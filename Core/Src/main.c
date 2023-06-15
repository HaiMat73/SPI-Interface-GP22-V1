/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "user_spi_interface.c"
#include "user_tools.c"

#include "GP22_Coding.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */

 GP22_InitTypeDef DUT; // DUT = Device Under Test

 volatile uint32_t  My_INTN_Counter = 0;
 volatile uint8_t   My_INTN_State = 1;

 volatile float     CLKLS_freq = 32768;             // LS Clock frequency in Hz
 volatile float     CLKHS_freq = 4000000;           // HS Clock frequency in Hz
 volatile float     CLKHS_freq_cal = 4000000;       // Calibrated HS Clock frequency in Hz
 volatile float     CLKHS_freq_corr_fact = 1.000;   // Correction factor for HS Clock frequency

 volatile float     RAW_Result = 0;                 // RAW Value in [LSB]
 volatile float     Time_Result = 0;                // Result in [s]
 volatile float     Time_Result_ns = 0;             // Result in [ns]

 volatile float     RAW_CAL_Result = 0;             // RAW Value in [LSB]
 volatile float     Time_CAL_Result = 0;            // Result in [s]
 volatile float     Time_CAL_Result_ns = 0;         // Result in [ns]

 uint8_t   spiRX[7];                       // used for readout of ID
 volatile uint64_t  Bit_ID = 0;                     // contains individual ID[55:0] of GP22

 volatile float     MAX_Cal_Time_Delay = 0;         // Max. measured calibrated time delay in [s]
 volatile float     MAX_Cal_Time_Delay_ns = 0;      // Max. measured calibrated time delay in [ns]

 volatile int       N_Measure_Cycles;               // counter for the while loop
 volatile int       MAX_N_Measure_Cycles = 100;     // limit for the counter

 //default configuration: MR1
 uint32_t  Reg[7] = {
		 0xF3066000,
		 0x01410000,
		 0x28000000,
		 0x00000000,
		 0x00000000,
		 0x00000000,
		 0x00000000
 };


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */


  // set configuration registers

/*
  DUT.CR[0] = 0xF3076010;
  DUT.CR[1] = 0x01410032;
  DUT.CR[2] = 0xA0000054;
  DUT.CR[3] = 0x00000076;
  DUT.CR[4] = 0x10000098;
  DUT.CR[5] = 0x000000BA;
  DUT.CR[6] = 0x400000DC;

  GP22_Update_Param(&DUT);
*/

  GP22_Init_CFG(&DUT, Reg);


  // set new value in CR0 @measurement mode 1
  DUT.Param.CR0.DIV_CLKHS = 0; // Calibrated Measurement Range =  500 ns
  //DUT.Param.CR0.DIV_CLKHS = 1; // Calibrated Measurement Range = 1000 ns
  //DUT.Param.CR0.DIV_CLKHS = 2; // Calibrated Measurement Range = 2000 ns

  // update CR0 register with new parameter
  //DUT.CR[0] |= GP22_0_DIV_CLKHS_SET(DUT.Param.CR0.DIV_CLKHS);

  GP22_Update_CFG(&DUT); // Function to update CFG!


  // Rough SPI Example for TDC-GP22 @10 MHz
  // According data sheet, SPI Frequency up to 20 MHz are possible.

  Write_Opcode(POWER_ON_RESET);
  DUT.State = GP22_STATE_RESET;
  HAL_Delay(1); // Delay = 1ms              // 500 us wait for GP22


  Write_Dword_Lite(WR_CFG, 0x00, DUT.CR[0]);
  Write_Dword_Lite(WR_CFG, 0x01, DUT.CR[1]);
  Write_Dword_Lite(WR_CFG, 0x02, DUT.CR[2]);
  Write_Dword_Lite(WR_CFG, 0x03, DUT.CR[3]);
  Write_Dword_Lite(WR_CFG, 0x04, DUT.CR[4]);
  Write_Dword_Lite(WR_CFG, 0x05, DUT.CR[5]);
  Write_Dword_Lite(WR_CFG, 0x06, DUT.CR[6]);


  // Readout of individual ID
  Read_Byte_Amount_Of(RD_ID_BIT, spiRX, 7);

  int ind=0;
  for (int lshift=48; lshift >= 0; lshift = lshift - 8) {
	  Bit_ID = Bit_ID + spiRX[ind]*MyPower(lshift);
	  ind += 1;
  }


  //--------------------------------------------------------------------------
  // Start Calibrate High Speed Clock Cycle
  Write_Opcode(INITIALIZE_TDC);
  DUT.State = GP22_STATE_READY;
  Write_Opcode(START_CAL_RESONATOR);

  // Wait for INTN
  while ( (My_INTN_State==1)) { }; // endless loop as long as INTN=1, timeout is missing!

  //Calculate Correction factor
  //The time interval to be measured is set by ANZ_PER_CALRES
  //which defines the number of periods of the 32.768 kHz clock:
  //2 periods = 61.03515625 µs

  RAW_CAL_Result = Read_Dword_Lite(RD_RESULT, 0x00);
  RAW_CAL_Result /= MyPower(16);
  Time_CAL_Result = RAW_CAL_Result / CLKHS_freq * MyPower(DUT.Param.CR0.DIV_CLKHS);

  CLKHS_freq_corr_fact = 2 * (float)(1./CLKLS_freq * MyPower(DUT.Param.CR0.ANZ_PER_CALRES)) / Time_CAL_Result;
  CLKHS_freq_cal = CLKHS_freq / CLKHS_freq_corr_fact; // Calibrated Clock frequency
  MAX_Cal_Time_Delay = 2 / CLKHS_freq_cal * MyPower(DUT.Param.CR0.DIV_CLKHS);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  N_Measure_Cycles++;

	  if (N_Measure_Cycles >= MAX_N_Measure_Cycles)
	  {
		  Write_Opcode(INITIALIZE_TDC);
		  Write_Opcode(START_CAL_RESONATOR);

		  // Wait for INTN
		  while ( (My_INTN_State==1)) { }; //timeout is missing

		  RAW_CAL_Result = Read_Dword_Lite(RD_RESULT, 0x00);
		  RAW_CAL_Result /= MyPower(16);
		  Time_CAL_Result = RAW_CAL_Result / CLKHS_freq * MyPower(DUT.Param.CR0.DIV_CLKHS);

		  CLKHS_freq_corr_fact = 2 * (float)(1./CLKLS_freq * MyPower(DUT.Param.CR0.ANZ_PER_CALRES)) / Time_CAL_Result;
		  CLKHS_freq_cal = CLKHS_freq / CLKHS_freq_corr_fact; // Calibrated Clock frequency
		  MAX_Cal_Time_Delay = 2 / CLKHS_freq_cal;
		  MAX_Cal_Time_Delay *= MyPower(DUT.Param.CR0.DIV_CLKHS);

		  MAX_Cal_Time_Delay_ns = TIME_ns(MAX_Cal_Time_Delay); // result in [ns]

		  N_Measure_Cycles = 0;

	  }

	  Write_Opcode(INITIALIZE_TDC);

	  //while (HAL_GPIO_ReadPin(INTN_GPIO_Port, INTN_Pin)==1) {} //old stuff

	  // Wait for INTN
	  // NVIC Functionality to increase the speed of MCU
	  while ( (My_INTN_State==1)) { }; //timeout is missing

	  RAW_Result = Read_Dword_Lite(RD_RESULT, 0x00);
	  RAW_Result /= MyPower(16);
	  Time_Result = RAW_Result / CLKHS_freq_cal;
	  Time_Result *= MyPower(DUT.Param.CR0.DIV_CLKHS);

	  Time_Result_ns = TIME_ns(Time_Result); // result in [ns]

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SSN_GPIO_Port, SSN_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : INTN_Pin */
  GPIO_InitStruct.Pin = INTN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(INTN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SSN_Pin */
  GPIO_InitStruct.Pin = SSN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(SSN_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

/* USER CODE BEGIN 4 */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	/* stm32l4xx_hal_gpio.c */

	/* Prevent unused argument(s) compilation warning */
	UNUSED(GPIO_Pin);

	// Note: It takes about 1us after INTN

	if (GPIO_Pin == INTN_Pin) {
		My_INTN_State = (HAL_GPIO_ReadPin(INTN_GPIO_Port, INTN_Pin) == GPIO_PIN_SET); /* low active */
		if (My_INTN_State == 0) {
			My_INTN_Counter += 1;
		}
	}

}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
