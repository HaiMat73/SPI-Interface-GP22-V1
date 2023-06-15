/*
 * GP22_Coding.h
 *
 *  Created on: 18.08.2022
 *      Author: Matthias Hainz
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_GP22_CODING_H_
#define INC_GP22_CODING_H_

/* Includes ------------------------------------------------------------------*/
#include "GP22_Bit_Definition.h"
#include "GP22_CFG_Macros.h"

/* Exported types ------------------------------------------------------------*/
/** @defgroup GP22_Exported_Types GP22 Exported Types
  * @{
  */

/* Private defines -----------------------------------------------------------*/
/** @defgroup GP22_Private_Constants GP22 Private Constants
  * @{
  */
#define __GP22_CFG_Declaration	uint32_t
#define __GP22_CFG_Array_Size		7		/* Addresses from CR[0] up to CR[6] */
/**
* @}
*/
/**
  * @brief  GP22 Opcode definition
  */
typedef enum _GP22_OpcodeTypeDef
{
	/* Opcode = Hex / Description */
	WR_CFG                   = 0x80U,    /*!< 0b10000XXX Write configuration register X=0..6                                                                        */
	RD_RESULT                = 0xB0U,    /*!< 0b10110XXX Read opcode for result and status register X=0..5                                                          */
	RD_PW1ST                 = 0xB8U,    /*!< followed by 8 bit                                                                                                     */
	RD_ID_BIT                = 0xB7U,    /*!< followed by 56 bit                                                                                                    */
	INITIALIZE_TDC           = 0x70U,    /*!< Initialize TDC                                                                                                        */
	POWER_ON_RESET           = 0x50U,    /*!< Power On Reset                                                                                                        */
	START_TOF                = 0x01U,    /*!< Triggers a sequence for a single time-of-flight measurement                                                           */
	START_TEMP               = 0x02U,    /*!< Triggers a single temperature measurement sequence                                                                    */
	START_CAL_RESONATOR      = 0x03U,    /*!< Triggers a calibration measurement of the high speed oscilator                                                        */
	START_CAL_TDC            = 0x04U,    /*!< This command starts a measurement of 2 periods of the reference clock. It is used to update the calibration raw data. */
	START_TOF_RESTART        = 0x05U,    /*!< This opcode runs the Start_TOF sequence twice, in up and down direction as it is typical in ultrasonic flow meters    */
	START_TEMP_RESTART       = 0x06U,    /*!< This opcode runs the Start_Temp sequence twice                                                                        */
	WRITE_CFG_INTO_EEPROM    = 0xC0U,    /*!< Write configuration registers into EEPROM                                                                             */
	TRANSFER_EEPROM_INTO_CFG = 0xF0U,    /*!< Transfer EEPROM content into configuration registers                                                                  */
	COMPARE_CFG_WITH_EEPROM  = 0xC6U     /*!< Compare configuration registers with EEPROM                                                                           */
} GP22_OpcodeTypeDef;

/**
  * @brief  GP22 State structure definition
  */
typedef enum _GP22_StateTypeDef
{
	GP22_STATE_RESET      = 0x00U,    /*!< Device not Initialized                           */
	GP22_STATE_READY      = 0x01U,    /*!< Device Configured, Initialized and ready for use */
	GP22_STATE_BUSY       = 0x02U,    /*!< an internal process is ongoing                   */
	GP22_STATE_INTN       = 0x03U,    /*!< Device interrupt state                           */
	GP22_STATE_ERROR      = 0x04U     /*!< Device error state                               */
} GP22_StateTypeDef;

/* Exported types ------------------------------------------------------------*/
/** @defgroup GP22_Exported_Types GP22 Exported Types
  * @{
  */
/**
  * @brief  Configuration CR[0] Structure definition
  */
typedef struct {
	uint8_t ID0;            	/*!< Free bits, e.g. to be used as identification or version number */
	uint8_t NEG_START;      	/*!< Negation start input */
	uint8_t NEG_STOP1;      	/*!< Negation stop 1 input */
	uint8_t NEG_STOP2;      	/*!< Negation stop 2 input */
	uint8_t MESSB2;         	/*!< Switch to measurement mode 2 */
	uint8_t NO_CAL_AUTO;    	/*!< Enables/disables auto-calibration run in the TDC */
	uint8_t CALIBRATE;      	/*!< Enables/disables calibration calculation in the ALU */
	uint8_t SEL_ECLK_TEMP;  	/*!< Select reference signal for internal cycle clock for temperature measurement */
	uint8_t ANZ_FAKE;       	/*!< Number of dummy cycles at the beginning of a temperature measurement */
	uint8_t TCYCLE;         	/*!< Sets cycle time for temperature measurement */
	uint8_t ANZ_PORT;       	/*!< Sets number of ports used for temperature measurement */
	uint8_t START_CLKHS_1_0;	/*!< Defines the time interval the chip waits after switching on the oscillator before making a measurement */
	uint8_t DIV_CLKHS;      	/*!< Sets predivider for CLKHS */
	uint8_t ANZ_PER_CALRES; 	/*!< Sets number of periods used for calibrating the ceramic resonator */
	uint8_t DIV_FIRE;       	/*!< Sets predivider for internal clock signal of fire pulse generator */
	uint8_t ANZ_FIRE_3_0;   	/*!< Sets number of pulses generated by fire pulse generator */
} GP22_CR0TypeDef;

/**
  * @brief  Configuration CR[1] Structure definition
  */
typedef struct {
	uint8_t ID1;            	/*!< Free bits, e.g. to be used as identification or version number */
	uint8_t SEL_TST01;      	/*!< Defines functionality of FIRE_IN pin */
	uint8_t SEL_TST02;      	/*!< Defines functionality of EN_START pin */
	uint8_t SEL_START_FIRE; 	/*!< Fire pulse is used as TDC start. The START input is disabled */
	uint8_t CURR32K;        	/*!< Low current option for 32 kHz oscillator */
	uint8_t HITIN1;         	/*!< Number of expected hits on channel 1 */
	uint8_t HITIN2;         	/*!< Number of expected hits on channel 2 */
	uint8_t KEEP_DEF_22;    	/*!< Keep default value */
	uint8_t EN_FAST_INIT;   	/*!< Enables fast init operation */
	uint8_t HIT1;           	/*!< Defines operator for ALU data postprocessing */
	uint8_t HIT2;           	/*!< Defines operator for ALU data postprocessing */
} GP22_CR1TypeDef;

/**
  * @brief  Configuration CR[2] Structure definition
  */
typedef struct {
	uint8_t ID2;            	/*!< Free bits, e.g. to be used as identification or version number */
	uint32_t DELVAL1;        	/*!< Delay value for internal stop enable unit, hit 1 channel 1 */
	uint8_t RFEDGE1;        	/*!< Edge sensitivity channel 1 */
	uint8_t RFEDGE2;        	/*!< Edge sensitivity channel 2 */
	uint8_t EN_INT_2_0;     	/*!< Activates interrupt sources wired by OR */
} GP22_CR2TypeDef;

/**
  * @brief  Configuration CR[3] Structure definition
  */
typedef struct {
	uint8_t ID3;            	/*!< Free bits, e.g. to be used as identification or version number */
	uint32_t DELVAL2;        	/*!< Delay value for internal stop enable unit, hit 2 channel 1 */
	uint8_t DELREL1;        	/*!< Sets the number of the periods after the first hit for the 1st stop */
	uint8_t DELREL2;        	/*!< Sets the number of the periods after the first hit for the 2nd stop */
	uint8_t DELREL3;        	/*!< Sets the number of the periods after the first hit for the 3rd stop */
	uint8_t KEEP_DEF_26;    	/*!< Keep default value */
	uint8_t SEL_TIMO_MB2;   	/*!< Select predivider for timeout in measurement mode 2 */
	uint8_t EN_ERR_VAL;     	/*!< Timeout forces ALU to write ‘hFFFFFFFF into the output register */
	uint8_t EN_FIRST_WAVE;  	/*!< Enables the automatic first hit detection */
	uint8_t EN_AUTOCALC_MB2;	/*!< Only in measurement mode 2: automatic calculation of all enabled hits */
} GP22_CR3TypeDef;

/**
  * @brief  Configuration CR[4] Structure definition
  */
typedef struct {
	uint8_t ID4;            	/*!< Free bits, e.g. to be used as identification or version number */
	uint32_t DELVAL3;        	/*!< Delay value for internal stop enable unit, hit 3 channel 1 */
	uint8_t KEEP_DEF_31_27; 	/*!< Keep default value */
	uint8_t OFFS;           	/*!< 2‘s complement number setting the offset shift in 1 mV steps */
	uint8_t OFFSRNG1;       	/*!< Additional offset shift by - 20 mV */
	uint8_t OFFSRNG2;       	/*!< Additional offset shift by + 20 mV */
	uint8_t EDGE_FW;        	/*!< Sets the edge sensitivity for the first wave */
	uint8_t DIS_PW;         	/*!< Disable pulse width measurement */
	uint32_t KEEP_DEF_31_17; 	/*!< Keep default value */
} GP22_CR4TypeDef;

/**
  * @brief  Configuration CR[5] Structure definition
  */
typedef struct {
	uint8_t ID5;            	/*!< Free bits, e.g. to be used as identification or version number */
	uint32_t PHFIRE;         	/*!< Enables phase reversing for each pulse of a sequence of up to 15 possible pulses */
	uint8_t REPEAT_FIRE;    	/*!< Number of pulse sequence repetition for 'quasi-sing-around' */
	uint8_t DIS_PHASESHIFT; 	/*!< Phase noise unit */
	uint8_t EN_STARTNOISE;  	/*!< Enables additional noise for start channel */
	uint8_t CONF_FIRE;      	/*!< Output configuration for pulse generator */
} GP22_CR5TypeDef;

/**
  * @brief  Configuration CR[6] Structure definition
  */
typedef struct {
	uint8_t ID6;            	/*!< Free bits, e.g. to be used as identification or version number */
	uint8_t ANZ_FIRE_6_4;   	/*!< Highest 3 bits of the number of fire pulses */
	uint8_t TEMP_PORTDIR;   	/*!< Ports for temperature measurement are measured in the opposite order */
	uint8_t DOUBLE_RES;     	/*!< Doubles the resolution from 90 ps to 45 ps */
	uint8_t QUAD_RES;       	/*!< Option to improve the resolution by factor 4 from 90 ps to 22 ps. Can be used only in measurement mode 2 */
	uint8_t FIRE0_DEF;      	/*!< Specifies the default level of the inactive fire buffer */
	uint8_t HZ60;           	/*!< TDC-GP21 can make complete up and down flow measurement and also two temperature measurements in series */
	uint8_t CYCLE_TOF;      	/*!< Selects timer for triggering the second ToF measurement in multiples of 50/60Hz */
	uint8_t CYCLE_TEMP;     	/*!< Selects timer for triggering the second temperature measurement in multiples of 50/60Hz */
	uint8_t START_CLKHS_2;  	/*!< Highest bit to set the settling time for the high speed oscillator */
	uint8_t EN_INT_3;       	/*!< Additional interrupt source */
	uint8_t TW2;            	/*!< Timer to charge up the capacitor of the recommend RC network when the internal analog part is used. */
	uint8_t KEEP_DEF_24;    	/*!< Keep default value */
	uint8_t DA_KORR;        	/*!< Sets comparator offset from -8 mV to +7 mV. 2‘s complement */
	uint8_t KEEP_DEF_29;    	/*!< Keep default value */
	uint8_t NEG_STOP_TEMP;  	/*!< Inverts the SenseT input signal */
	uint8_t EN_ANALOG;      	/*!< Activates the analog part for the ultrasonic flow measurement */
} GP22_CR6TypeDef;


/**
  * @brief  Configuration Structure definition
  */
typedef struct {
	GP22_CR0TypeDef CR0;	/*!< Configuration Register Address 0 */
	GP22_CR1TypeDef CR1;	/*!< Configuration Register Address 1 */
	GP22_CR2TypeDef CR2;	/*!< Configuration Register Address 2 */
	GP22_CR3TypeDef CR3;	/*!< Configuration Register Address 3 */
	GP22_CR4TypeDef CR4;	/*!< Configuration Register Address 4 */
	GP22_CR5TypeDef CR5;	/*!< Configuration Register Address 5 */
	GP22_CR6TypeDef CR6;	/*!< Configuration Register Address 6 */

	/* additional parameter, more than one register long
	 * custom content */

	//uint32_t refclk_division;
} GP22_ParamTypeDef;
/**
* @}
*/

/**
  * @brief  Initialization Structure definition
  */
typedef struct {
	__GP22_CFG_Declaration CR[__GP22_CFG_Array_Size];

	GP22_ParamTypeDef Param;	/*!< Configuration Parameter */

	/* place for custom content
	 * e.g. further registers */

	GP22_StateTypeDef State;	/*!< Status of GP22 */

} GP22_InitTypeDef;
/**
* @}
*/

/* Private function prototypes -----------------------------------------------*/
/** @defgroup GP22_Private_Functions GP22 Private Functions
  * @{
  */
/**
  * @brief  Handle parameter update.
  * @param  init pointer to a GP22_InitTypeDef structure that contains
  *               the configuration information for the specified device.
  * @retval None
  */
void GP22_Update_Param(GP22_InitTypeDef* init)  {
	/* Read all content from CR[] and write into every parameter
	 * Update for each parameter */
	/* Parameter of CR[0] */
	init->Param.CR0.ID0 = ( (init->CR[0]) & GP22_0_ID0_Msk ) >> GP22_0_ID0_Pos;
	init->Param.CR0.NEG_START = ( (init->CR[0]) & GP22_0_NEG_START_Msk ) >> GP22_0_NEG_START_Pos;
	init->Param.CR0.NEG_STOP1 = ( (init->CR[0]) & GP22_0_NEG_STOP1_Msk ) >> GP22_0_NEG_STOP1_Pos;
	init->Param.CR0.NEG_STOP2 = ( (init->CR[0]) & GP22_0_NEG_STOP2_Msk ) >> GP22_0_NEG_STOP2_Pos;
	init->Param.CR0.MESSB2 = ( (init->CR[0]) & GP22_0_MESSB2_Msk ) >> GP22_0_MESSB2_Pos;
	init->Param.CR0.NO_CAL_AUTO = ( (init->CR[0]) & GP22_0_NO_CAL_AUTO_Msk ) >> GP22_0_NO_CAL_AUTO_Pos;
	init->Param.CR0.CALIBRATE = ( (init->CR[0]) & GP22_0_CALIBRATE_Msk ) >> GP22_0_CALIBRATE_Pos;
	init->Param.CR0.SEL_ECLK_TEMP = ( (init->CR[0]) & GP22_0_SEL_ECLK_TEMP_Msk ) >> GP22_0_SEL_ECLK_TEMP_Pos;
	init->Param.CR0.ANZ_FAKE = ( (init->CR[0]) & GP22_0_ANZ_FAKE_Msk ) >> GP22_0_ANZ_FAKE_Pos;
	init->Param.CR0.TCYCLE = ( (init->CR[0]) & GP22_0_TCYCLE_Msk ) >> GP22_0_TCYCLE_Pos;
	init->Param.CR0.ANZ_PORT = ( (init->CR[0]) & GP22_0_ANZ_PORT_Msk ) >> GP22_0_ANZ_PORT_Pos;
	init->Param.CR0.START_CLKHS_1_0 = ( (init->CR[0]) & GP22_0_START_CLKHS_1_0_Msk ) >> GP22_0_START_CLKHS_1_0_Pos;
	init->Param.CR0.DIV_CLKHS = ( (init->CR[0]) & GP22_0_DIV_CLKHS_Msk ) >> GP22_0_DIV_CLKHS_Pos;
	init->Param.CR0.ANZ_PER_CALRES = ( (init->CR[0]) & GP22_0_ANZ_PER_CALRES_Msk ) >> GP22_0_ANZ_PER_CALRES_Pos;
	init->Param.CR0.DIV_FIRE = ( (init->CR[0]) & GP22_0_DIV_FIRE_Msk ) >> GP22_0_DIV_FIRE_Pos;
	init->Param.CR0.ANZ_FIRE_3_0 = ( (init->CR[0]) & GP22_0_ANZ_FIRE_3_0_Msk ) >> GP22_0_ANZ_FIRE_3_0_Pos;
	/* Parameter of CR[1] */
	init->Param.CR1.ID1 = ( (init->CR[1]) & GP22_1_ID1_Msk ) >> GP22_1_ID1_Pos;
	init->Param.CR1.SEL_TST01 = ( (init->CR[1]) & GP22_1_SEL_TST01_Msk ) >> GP22_1_SEL_TST01_Pos;
	init->Param.CR1.SEL_TST02 = ( (init->CR[1]) & GP22_1_SEL_TST02_Msk ) >> GP22_1_SEL_TST02_Pos;
	init->Param.CR1.SEL_START_FIRE = ( (init->CR[1]) & GP22_1_SEL_START_FIRE_Msk ) >> GP22_1_SEL_START_FIRE_Pos;
	init->Param.CR1.CURR32K = ( (init->CR[1]) & GP22_1_CURR32K_Msk ) >> GP22_1_CURR32K_Pos;
	init->Param.CR1.HITIN1 = ( (init->CR[1]) & GP22_1_HITIN1_Msk ) >> GP22_1_HITIN1_Pos;
	init->Param.CR1.HITIN2 = ( (init->CR[1]) & GP22_1_HITIN2_Msk ) >> GP22_1_HITIN2_Pos;
	init->Param.CR1.KEEP_DEF_22 = ( (init->CR[1]) & GP22_1_KEEP_DEF_22_Msk ) >> GP22_1_KEEP_DEF_22_Pos;
	init->Param.CR1.EN_FAST_INIT = ( (init->CR[1]) & GP22_1_EN_FAST_INIT_Msk ) >> GP22_1_EN_FAST_INIT_Pos;
	init->Param.CR1.HIT1 = ( (init->CR[1]) & GP22_1_HIT1_Msk ) >> GP22_1_HIT1_Pos;
	init->Param.CR1.HIT2 = ( (init->CR[1]) & GP22_1_HIT2_Msk ) >> GP22_1_HIT2_Pos;
	/* Parameter of CR[2] */
	init->Param.CR2.ID2 = ( (init->CR[2]) & GP22_2_ID2_Msk ) >> GP22_2_ID2_Pos;
	init->Param.CR2.DELVAL1 = ( (init->CR[2]) & GP22_2_DELVAL1_Msk ) >> GP22_2_DELVAL1_Pos;
	init->Param.CR2.RFEDGE1 = ( (init->CR[2]) & GP22_2_RFEDGE1_Msk ) >> GP22_2_RFEDGE1_Pos;
	init->Param.CR2.RFEDGE2 = ( (init->CR[2]) & GP22_2_RFEDGE2_Msk ) >> GP22_2_RFEDGE2_Pos;
	init->Param.CR2.EN_INT_2_0 = ( (init->CR[2]) & GP22_2_EN_INT_2_0_Msk ) >> GP22_2_EN_INT_2_0_Pos;
	/* Parameter of CR[3] */
	init->Param.CR3.ID3 = ( (init->CR[3]) & GP22_3_ID3_Msk ) >> GP22_3_ID3_Pos;
	init->Param.CR3.DELVAL2 = ( (init->CR[3]) & GP22_3_DELVAL2_Msk ) >> GP22_3_DELVAL2_Pos;
	init->Param.CR3.DELREL1 = ( (init->CR[3]) & GP22_3_DELREL1_Msk ) >> GP22_3_DELREL1_Pos;
	init->Param.CR3.DELREL2 = ( (init->CR[3]) & GP22_3_DELREL2_Msk ) >> GP22_3_DELREL2_Pos;
	init->Param.CR3.DELREL3 = ( (init->CR[3]) & GP22_3_DELREL3_Msk ) >> GP22_3_DELREL3_Pos;
	init->Param.CR3.KEEP_DEF_26 = ( (init->CR[3]) & GP22_3_KEEP_DEF_26_Msk ) >> GP22_3_KEEP_DEF_26_Pos;
	init->Param.CR3.SEL_TIMO_MB2 = ( (init->CR[3]) & GP22_3_SEL_TIMO_MB2_Msk ) >> GP22_3_SEL_TIMO_MB2_Pos;
	init->Param.CR3.EN_ERR_VAL = ( (init->CR[3]) & GP22_3_EN_ERR_VAL_Msk ) >> GP22_3_EN_ERR_VAL_Pos;
	init->Param.CR3.EN_FIRST_WAVE = ( (init->CR[3]) & GP22_3_EN_FIRST_WAVE_Msk ) >> GP22_3_EN_FIRST_WAVE_Pos;
	init->Param.CR3.EN_AUTOCALC_MB2 = ( (init->CR[3]) & GP22_3_EN_AUTOCALC_MB2_Msk ) >> GP22_3_EN_AUTOCALC_MB2_Pos;
	/* Parameter of CR[4] */
	init->Param.CR4.ID4 = ( (init->CR[4]) & GP22_4_ID4_Msk ) >> GP22_4_ID4_Pos;
	init->Param.CR4.DELVAL3 = ( (init->CR[4]) & GP22_4_DELVAL3_Msk ) >> GP22_4_DELVAL3_Pos;
	init->Param.CR4.KEEP_DEF_31_27 = ( (init->CR[4]) & GP22_4_KEEP_DEF_31_27_Msk ) >> GP22_4_KEEP_DEF_31_27_Pos;
	init->Param.CR4.OFFS = ( (init->CR[4]) & GP22_4_OFFS_Msk ) >> GP22_4_OFFS_Pos;
	init->Param.CR4.OFFSRNG1 = ( (init->CR[4]) & GP22_4_OFFSRNG1_Msk ) >> GP22_4_OFFSRNG1_Pos;
	init->Param.CR4.OFFSRNG2 = ( (init->CR[4]) & GP22_4_OFFSRNG2_Msk ) >> GP22_4_OFFSRNG2_Pos;
	init->Param.CR4.EDGE_FW = ( (init->CR[4]) & GP22_4_EDGE_FW_Msk ) >> GP22_4_EDGE_FW_Pos;
	init->Param.CR4.DIS_PW = ( (init->CR[4]) & GP22_4_DIS_PW_Msk ) >> GP22_4_DIS_PW_Pos;
	init->Param.CR4.KEEP_DEF_31_17 = ( (init->CR[4]) & GP22_4_KEEP_DEF_31_17_Msk ) >> GP22_4_KEEP_DEF_31_17_Pos;
	/* Parameter of CR[5] */
	init->Param.CR5.ID5 = ( (init->CR[5]) & GP22_5_ID5_Msk ) >> GP22_5_ID5_Pos;
	init->Param.CR5.PHFIRE = ( (init->CR[5]) & GP22_5_PHFIRE_Msk ) >> GP22_5_PHFIRE_Pos;
	init->Param.CR5.REPEAT_FIRE = ( (init->CR[5]) & GP22_5_REPEAT_FIRE_Msk ) >> GP22_5_REPEAT_FIRE_Pos;
	init->Param.CR5.DIS_PHASESHIFT = ( (init->CR[5]) & GP22_5_DIS_PHASESHIFT_Msk ) >> GP22_5_DIS_PHASESHIFT_Pos;
	init->Param.CR5.EN_STARTNOISE = ( (init->CR[5]) & GP22_5_EN_STARTNOISE_Msk ) >> GP22_5_EN_STARTNOISE_Pos;
	init->Param.CR5.CONF_FIRE = ( (init->CR[5]) & GP22_5_CONF_FIRE_Msk ) >> GP22_5_CONF_FIRE_Pos;
	/* Parameter of CR[6] */
	init->Param.CR6.ID6 = ( (init->CR[6]) & GP22_6_ID6_Msk ) >> GP22_6_ID6_Pos;
	init->Param.CR6.ANZ_FIRE_6_4 = ( (init->CR[6]) & GP22_6_ANZ_FIRE_6_4_Msk ) >> GP22_6_ANZ_FIRE_6_4_Pos;
	init->Param.CR6.TEMP_PORTDIR = ( (init->CR[6]) & GP22_6_TEMP_PORTDIR_Msk ) >> GP22_6_TEMP_PORTDIR_Pos;
	init->Param.CR6.DOUBLE_RES = ( (init->CR[6]) & GP22_6_DOUBLE_RES_Msk ) >> GP22_6_DOUBLE_RES_Pos;
	init->Param.CR6.QUAD_RES = ( (init->CR[6]) & GP22_6_QUAD_RES_Msk ) >> GP22_6_QUAD_RES_Pos;
	init->Param.CR6.FIRE0_DEF = ( (init->CR[6]) & GP22_6_FIRE0_DEF_Msk ) >> GP22_6_FIRE0_DEF_Pos;
	init->Param.CR6.HZ60 = ( (init->CR[6]) & GP22_6_HZ60_Msk ) >> GP22_6_HZ60_Pos;
	init->Param.CR6.CYCLE_TOF = ( (init->CR[6]) & GP22_6_CYCLE_TOF_Msk ) >> GP22_6_CYCLE_TOF_Pos;
	init->Param.CR6.CYCLE_TEMP = ( (init->CR[6]) & GP22_6_CYCLE_TEMP_Msk ) >> GP22_6_CYCLE_TEMP_Pos;
	init->Param.CR6.START_CLKHS_2 = ( (init->CR[6]) & GP22_6_START_CLKHS_2_Msk ) >> GP22_6_START_CLKHS_2_Pos;
	init->Param.CR6.EN_INT_3 = ( (init->CR[6]) & GP22_6_EN_INT_3_Msk ) >> GP22_6_EN_INT_3_Pos;
	init->Param.CR6.TW2 = ( (init->CR[6]) & GP22_6_TW2_Msk ) >> GP22_6_TW2_Pos;
	init->Param.CR6.KEEP_DEF_24 = ( (init->CR[6]) & GP22_6_KEEP_DEF_24_Msk ) >> GP22_6_KEEP_DEF_24_Pos;
	init->Param.CR6.DA_KORR = ( (init->CR[6]) & GP22_6_DA_KORR_Msk ) >> GP22_6_DA_KORR_Pos;
	init->Param.CR6.KEEP_DEF_29 = ( (init->CR[6]) & GP22_6_KEEP_DEF_29_Msk ) >> GP22_6_KEEP_DEF_29_Pos;
	init->Param.CR6.NEG_STOP_TEMP = ( (init->CR[6]) & GP22_6_NEG_STOP_TEMP_Msk ) >> GP22_6_NEG_STOP_TEMP_Pos;
	init->Param.CR6.EN_ANALOG = ( (init->CR[6]) & GP22_6_EN_ANALOG_Msk ) >> GP22_6_EN_ANALOG_Pos;
}
/**
* @}
*/

/**
  * @brief  Handle configuration registers update.
  * @param  init pointer to a GP22_InitTypeDef structure that contains
  *               the parameter information for the specified device.
  * @retval None
  */
void GP22_Update_CFG(GP22_InitTypeDef* init)  {
	/* Writes all parameters into every configuration register */
	/* Parameter for CR[0] */
	init->CR[0]	|= GP22_0_ID0_SET(init->Param.CR0.ID0);
	init->CR[0]	|= GP22_0_NEG_START_SET(init->Param.CR0.NEG_START);
	init->CR[0]	|= GP22_0_NEG_STOP1_SET(init->Param.CR0.NEG_STOP1);
	init->CR[0]	|= GP22_0_NEG_STOP2_SET(init->Param.CR0.NEG_STOP2);
	init->CR[0]	|= GP22_0_MESSB2_SET(init->Param.CR0.MESSB2);
	init->CR[0]	|= GP22_0_NO_CAL_AUTO_SET(init->Param.CR0.NO_CAL_AUTO);
	init->CR[0]	|= GP22_0_CALIBRATE_SET(init->Param.CR0.CALIBRATE);
	init->CR[0]	|= GP22_0_SEL_ECLK_TEMP_SET(init->Param.CR0.SEL_ECLK_TEMP);
	init->CR[0]	|= GP22_0_ANZ_FAKE_SET(init->Param.CR0.ANZ_FAKE);
	init->CR[0]	|= GP22_0_TCYCLE_SET(init->Param.CR0.TCYCLE);
	init->CR[0]	|= GP22_0_ANZ_PORT_SET(init->Param.CR0.ANZ_PORT);
	init->CR[0]	|= GP22_0_START_CLKHS_1_0_SET(init->Param.CR0.START_CLKHS_1_0);
	init->CR[0]	|= GP22_0_DIV_CLKHS_SET(init->Param.CR0.DIV_CLKHS);
	init->CR[0]	|= GP22_0_ANZ_PER_CALRES_SET(init->Param.CR0.ANZ_PER_CALRES);
	init->CR[0]	|= GP22_0_DIV_FIRE_SET(init->Param.CR0.DIV_FIRE);
	init->CR[0]	|= GP22_0_ANZ_FIRE_3_0_SET(init->Param.CR0.ANZ_FIRE_3_0);
	/* Parameter for CR[1] */
	init->CR[1]	|= GP22_1_ID1_SET(init->Param.CR1.ID1);
	init->CR[1]	|= GP22_1_SEL_TST01_SET(init->Param.CR1.SEL_TST01);
	init->CR[1]	|= GP22_1_SEL_TST02_SET(init->Param.CR1.SEL_TST02);
	init->CR[1]	|= GP22_1_SEL_START_FIRE_SET(init->Param.CR1.SEL_START_FIRE);
	init->CR[1]	|= GP22_1_CURR32K_SET(init->Param.CR1.CURR32K);
	init->CR[1]	|= GP22_1_HITIN1_SET(init->Param.CR1.HITIN1);
	init->CR[1]	|= GP22_1_HITIN2_SET(init->Param.CR1.HITIN2);
	init->CR[1]	|= GP22_1_KEEP_DEF_22_SET(init->Param.CR1.KEEP_DEF_22);
	init->CR[1]	|= GP22_1_EN_FAST_INIT_SET(init->Param.CR1.EN_FAST_INIT);
	init->CR[1]	|= GP22_1_HIT1_SET(init->Param.CR1.HIT1);
	init->CR[1]	|= GP22_1_HIT2_SET(init->Param.CR1.HIT2);
	/* Parameter for CR[2] */
	init->CR[2]	|= GP22_2_ID2_SET(init->Param.CR2.ID2);
	init->CR[2]	|= GP22_2_DELVAL1_SET(init->Param.CR2.DELVAL1);
	init->CR[2]	|= GP22_2_RFEDGE1_SET(init->Param.CR2.RFEDGE1);
	init->CR[2]	|= GP22_2_RFEDGE2_SET(init->Param.CR2.RFEDGE2);
	init->CR[2]	|= GP22_2_EN_INT_2_0_SET(init->Param.CR2.EN_INT_2_0);
	/* Parameter for CR[3] */
	init->CR[3]	|= GP22_3_ID3_SET(init->Param.CR3.ID3);
	init->CR[3]	|= GP22_3_DELVAL2_SET(init->Param.CR3.DELVAL2);
	init->CR[3]	|= GP22_3_DELREL1_SET(init->Param.CR3.DELREL1);
	init->CR[3]	|= GP22_3_DELREL2_SET(init->Param.CR3.DELREL2);
	init->CR[3]	|= GP22_3_DELREL3_SET(init->Param.CR3.DELREL3);
	init->CR[3]	|= GP22_3_KEEP_DEF_26_SET(init->Param.CR3.KEEP_DEF_26);
	init->CR[3]	|= GP22_3_SEL_TIMO_MB2_SET(init->Param.CR3.SEL_TIMO_MB2);
	init->CR[3]	|= GP22_3_EN_ERR_VAL_SET(init->Param.CR3.EN_ERR_VAL);
	init->CR[3]	|= GP22_3_EN_FIRST_WAVE_SET(init->Param.CR3.EN_FIRST_WAVE);
	init->CR[3]	|= GP22_3_EN_AUTOCALC_MB2_SET(init->Param.CR3.EN_AUTOCALC_MB2);
	/* Parameter for CR[4] */
	init->CR[4]	|= GP22_4_ID4_SET(init->Param.CR4.ID4);
	init->CR[4]	|= GP22_4_DELVAL3_SET(init->Param.CR4.DELVAL3);
	init->CR[4]	|= GP22_4_KEEP_DEF_31_27_SET(init->Param.CR4.KEEP_DEF_31_27);
	init->CR[4]	|= GP22_4_OFFS_SET(init->Param.CR4.OFFS);
	init->CR[4]	|= GP22_4_OFFSRNG1_SET(init->Param.CR4.OFFSRNG1);
	init->CR[4]	|= GP22_4_OFFSRNG2_SET(init->Param.CR4.OFFSRNG2);
	init->CR[4]	|= GP22_4_EDGE_FW_SET(init->Param.CR4.EDGE_FW);
	init->CR[4]	|= GP22_4_DIS_PW_SET(init->Param.CR4.DIS_PW);
	init->CR[4]	|= GP22_4_KEEP_DEF_31_17_SET(init->Param.CR4.KEEP_DEF_31_17);
	/* Parameter for CR[5] */
	init->CR[5]	|= GP22_5_ID5_SET(init->Param.CR5.ID5);
	init->CR[5]	|= GP22_5_PHFIRE_SET(init->Param.CR5.PHFIRE);
	init->CR[5]	|= GP22_5_REPEAT_FIRE_SET(init->Param.CR5.REPEAT_FIRE);
	init->CR[5]	|= GP22_5_DIS_PHASESHIFT_SET(init->Param.CR5.DIS_PHASESHIFT);
	init->CR[5]	|= GP22_5_EN_STARTNOISE_SET(init->Param.CR5.EN_STARTNOISE);
	init->CR[5]	|= GP22_5_CONF_FIRE_SET(init->Param.CR5.CONF_FIRE);
	/* Parameter for CR[6] */
	init->CR[6]	|= GP22_6_ID6_SET(init->Param.CR6.ID6);
	init->CR[6]	|= GP22_6_ANZ_FIRE_6_4_SET(init->Param.CR6.ANZ_FIRE_6_4);
	init->CR[6]	|= GP22_6_TEMP_PORTDIR_SET(init->Param.CR6.TEMP_PORTDIR);
	init->CR[6]	|= GP22_6_DOUBLE_RES_SET(init->Param.CR6.DOUBLE_RES);
	init->CR[6]	|= GP22_6_QUAD_RES_SET(init->Param.CR6.QUAD_RES);
	init->CR[6]	|= GP22_6_FIRE0_DEF_SET(init->Param.CR6.FIRE0_DEF);
	init->CR[6]	|= GP22_6_HZ60_SET(init->Param.CR6.HZ60);
	init->CR[6]	|= GP22_6_CYCLE_TOF_SET(init->Param.CR6.CYCLE_TOF);
	init->CR[6]	|= GP22_6_CYCLE_TEMP_SET(init->Param.CR6.CYCLE_TEMP);
	init->CR[6]	|= GP22_6_START_CLKHS_2_SET(init->Param.CR6.START_CLKHS_2);
	init->CR[6]	|= GP22_6_EN_INT_3_SET(init->Param.CR6.EN_INT_3);
	init->CR[6]	|= GP22_6_TW2_SET(init->Param.CR6.TW2);
	init->CR[6]	|= GP22_6_KEEP_DEF_24_SET(init->Param.CR6.KEEP_DEF_24);
	init->CR[6]	|= GP22_6_DA_KORR_SET(init->Param.CR6.DA_KORR);
	init->CR[6]	|= GP22_6_KEEP_DEF_29_SET(init->Param.CR6.KEEP_DEF_29);
	init->CR[6]	|= GP22_6_NEG_STOP_TEMP_SET(init->Param.CR6.NEG_STOP_TEMP);
	init->CR[6]	|= GP22_6_EN_ANALOG_SET(init->Param.CR6.EN_ANALOG);
}
/**
* @}
*/

/**
  * @brief  Handle initialization of configuration.
  * @param  init pointer to a GP22_InitTypeDef structure that contains
  *               the configuration information for the specified device.
  * @param  array pointer to declarated configuration register for the specified device.
  * @retval None
  */
void GP22_Init_CFG(GP22_InitTypeDef* init, __GP22_CFG_Declaration* array)  {
	uint8_t idx;
	/* Update content of CR for external usage */
	for (idx = 0; idx <= __GP22_CFG_Array_Size; idx++) {
		init->CR[idx] = array[idx];
	}

	/* Update Parameter */
	GP22_Update_Param(init);

}
/**
* @}
*/

/**
* @}
*/


#endif /* INC_GP22_CODING_H_ */
