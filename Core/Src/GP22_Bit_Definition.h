/*
 * GP22_Bit_Definition.h
 *
 *  Created on: 18.08.2022
 *      Author: Matthias Hainz
 */

#ifndef INC_GP22_BIT_DEFINITION_H_
#define INC_GP22_BIT_DEFINITION_H_

/******************************************************************************/
/*                                                                            */
/*                        TDC GP22                   */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for GP22_0 register  ********************/
#define GP22_0_ID0_Pos                	(0U)
#define GP22_0_ID0_Msk                	(0xFFUL << GP22_0_ID0_Pos)		/*!< 0x000000FF */
#define GP22_0_ID0                		GP22_0_ID0_Msk					/*!< ID0[7:0]Free bits, e.g. to be used as identification or version number */
#define GP22_0_ID0_0                		(0x00000001 << GP22_0_ID0_Pos)	
#define GP22_0_ID0_1                		(0x00000002 << GP22_0_ID0_Pos)	
#define GP22_0_ID0_2                		(0x00000004 << GP22_0_ID0_Pos)	
#define GP22_0_ID0_3                		(0x00000008 << GP22_0_ID0_Pos)	
#define GP22_0_ID0_4                		(0x00000010 << GP22_0_ID0_Pos)	
#define GP22_0_ID0_5                		(0x00000020 << GP22_0_ID0_Pos)	
#define GP22_0_ID0_6                		(0x00000040 << GP22_0_ID0_Pos)	
#define GP22_0_ID0_7                		(0x00000080 << GP22_0_ID0_Pos)	
#define GP22_0_NEG_START_Pos          	(8U)
#define GP22_0_NEG_START_Msk          	(0x1UL << GP22_0_NEG_START_Pos)		/*!< 0x00000100 */
#define GP22_0_NEG_START          		GP22_0_NEG_START_Msk					/*!< Negation start input */
#define GP22_0_NEG_STOP1_Pos          	(9U)
#define GP22_0_NEG_STOP1_Msk          	(0x1UL << GP22_0_NEG_STOP1_Pos)		/*!< 0x00000200 */
#define GP22_0_NEG_STOP1          		GP22_0_NEG_STOP1_Msk					/*!< Negation stop 1 input */
#define GP22_0_NEG_STOP2_Pos          	(10U)
#define GP22_0_NEG_STOP2_Msk          	(0x1UL << GP22_0_NEG_STOP2_Pos)		/*!< 0x00000400 */
#define GP22_0_NEG_STOP2          		GP22_0_NEG_STOP2_Msk					/*!< Negation stop 2 input */
#define GP22_0_MESSB2_Pos             	(11U)
#define GP22_0_MESSB2_Msk             	(0x1UL << GP22_0_MESSB2_Pos)		/*!< 0x00000800 */
#define GP22_0_MESSB2             		GP22_0_MESSB2_Msk					/*!< Switch to measurement mode 2 */
#define GP22_0_NO_CAL_AUTO_Pos        	(12U)
#define GP22_0_NO_CAL_AUTO_Msk        	(0x1UL << GP22_0_NO_CAL_AUTO_Pos)		/*!< 0x00001000 */
#define GP22_0_NO_CAL_AUTO        		GP22_0_NO_CAL_AUTO_Msk					/*!< Enables/disables auto-calibration run in the TDC */
#define GP22_0_CALIBRATE_Pos          	(13U)
#define GP22_0_CALIBRATE_Msk          	(0x1UL << GP22_0_CALIBRATE_Pos)		/*!< 0x00002000 */
#define GP22_0_CALIBRATE          		GP22_0_CALIBRATE_Msk					/*!< Enables/disables calibration calculation in the ALU */
#define GP22_0_SEL_ECLK_TEMP_Pos      	(14U)
#define GP22_0_SEL_ECLK_TEMP_Msk      	(0x1UL << GP22_0_SEL_ECLK_TEMP_Pos)		/*!< 0x00004000 */
#define GP22_0_SEL_ECLK_TEMP      		GP22_0_SEL_ECLK_TEMP_Msk					/*!< Select reference signal for internal cycle clock for temperature measurement */
#define GP22_0_ANZ_FAKE_Pos           	(15U)
#define GP22_0_ANZ_FAKE_Msk           	(0x1UL << GP22_0_ANZ_FAKE_Pos)		/*!< 0x00008000 */
#define GP22_0_ANZ_FAKE           		GP22_0_ANZ_FAKE_Msk					/*!< Number of dummy cycles at the beginning of a temperature measurement */
#define GP22_0_TCYCLE_Pos             	(16U)
#define GP22_0_TCYCLE_Msk             	(0x1UL << GP22_0_TCYCLE_Pos)		/*!< 0x00010000 */
#define GP22_0_TCYCLE             		GP22_0_TCYCLE_Msk					/*!< Sets cycle time for temperature measurement */
#define GP22_0_ANZ_PORT_Pos           	(17U)
#define GP22_0_ANZ_PORT_Msk           	(0x1UL << GP22_0_ANZ_PORT_Pos)		/*!< 0x00020000 */
#define GP22_0_ANZ_PORT           		GP22_0_ANZ_PORT_Msk					/*!< Sets number of ports used for temperature measurement */
#define GP22_0_START_CLKHS_1_0_Pos    	(18U)
#define GP22_0_START_CLKHS_1_0_Msk    	(0x03UL << GP22_0_START_CLKHS_1_0_Pos)		/*!< 0x000C0000 */
#define GP22_0_START_CLKHS_1_0    		GP22_0_START_CLKHS_1_0_Msk					/*!< START_CLKHS_1_0[19:18]Defines the time interval the chip waits after switching on the oscillator before making a measurement */
#define GP22_0_START_CLKHS_1_0_0    		(0x00000001 << GP22_0_START_CLKHS_1_0_Pos)	
#define GP22_0_START_CLKHS_1_0_1    		(0x00000002 << GP22_0_START_CLKHS_1_0_Pos)	
#define GP22_0_DIV_CLKHS_Pos          	(20U)
#define GP22_0_DIV_CLKHS_Msk          	(0x03UL << GP22_0_DIV_CLKHS_Pos)		/*!< 0x00300000 */
#define GP22_0_DIV_CLKHS          		GP22_0_DIV_CLKHS_Msk					/*!< DIV_CLKHS[21:20]Sets predivider for CLKHS */
#define GP22_0_DIV_CLKHS_0          		(0x00000001 << GP22_0_DIV_CLKHS_Pos)	
#define GP22_0_DIV_CLKHS_1          		(0x00000002 << GP22_0_DIV_CLKHS_Pos)	
#define GP22_0_ANZ_PER_CALRES_Pos     	(22U)
#define GP22_0_ANZ_PER_CALRES_Msk     	(0x03UL << GP22_0_ANZ_PER_CALRES_Pos)		/*!< 0x00C00000 */
#define GP22_0_ANZ_PER_CALRES     		GP22_0_ANZ_PER_CALRES_Msk					/*!< ANZ_PER_CALRES[23:22]Sets number of periods used for calibrating the ceramic resonator */
#define GP22_0_ANZ_PER_CALRES_0     		(0x00000001 << GP22_0_ANZ_PER_CALRES_Pos)	
#define GP22_0_ANZ_PER_CALRES_1     		(0x00000002 << GP22_0_ANZ_PER_CALRES_Pos)	
#define GP22_0_DIV_FIRE_Pos           	(24U)
#define GP22_0_DIV_FIRE_Msk           	(0xFUL << GP22_0_DIV_FIRE_Pos)		/*!< 0x0F000000 */
#define GP22_0_DIV_FIRE           		GP22_0_DIV_FIRE_Msk					/*!< DIV_FIRE[27:24]Sets predivider for internal clock signal of fire pulse generator */
#define GP22_0_DIV_FIRE_0           		(0x00000001 << GP22_0_DIV_FIRE_Pos)	
#define GP22_0_DIV_FIRE_1           		(0x00000002 << GP22_0_DIV_FIRE_Pos)	
#define GP22_0_DIV_FIRE_2           		(0x00000004 << GP22_0_DIV_FIRE_Pos)	
#define GP22_0_DIV_FIRE_3           		(0x00000008 << GP22_0_DIV_FIRE_Pos)	
#define GP22_0_ANZ_FIRE_3_0_Pos       	(28U)
#define GP22_0_ANZ_FIRE_3_0_Msk       	(0xFUL << GP22_0_ANZ_FIRE_3_0_Pos)		/*!< 0xF0000000 */
#define GP22_0_ANZ_FIRE_3_0       		GP22_0_ANZ_FIRE_3_0_Msk					/*!< ANZ_FIRE_3_0[31:28]Sets number of pulses generated by fire pulse generator */
#define GP22_0_ANZ_FIRE_3_0_0       		(0x00000001 << GP22_0_ANZ_FIRE_3_0_Pos)	
#define GP22_0_ANZ_FIRE_3_0_1       		(0x00000002 << GP22_0_ANZ_FIRE_3_0_Pos)	
#define GP22_0_ANZ_FIRE_3_0_2       		(0x00000004 << GP22_0_ANZ_FIRE_3_0_Pos)	
#define GP22_0_ANZ_FIRE_3_0_3       		(0x00000008 << GP22_0_ANZ_FIRE_3_0_Pos)	

/*******************  Bit definition for GP22_1 register  ********************/
#define GP22_1_ID1_Pos                	(0U)
#define GP22_1_ID1_Msk                	(0xFFUL << GP22_1_ID1_Pos)		/*!< 0x000000FF */
#define GP22_1_ID1                		GP22_1_ID1_Msk					/*!< ID1[7:0]Free bits, e.g. to be used as identification or version number */
#define GP22_1_ID1_0                		(0x00000001 << GP22_1_ID1_Pos)	
#define GP22_1_ID1_1                		(0x00000002 << GP22_1_ID1_Pos)	
#define GP22_1_ID1_2                		(0x00000004 << GP22_1_ID1_Pos)	
#define GP22_1_ID1_3                		(0x00000008 << GP22_1_ID1_Pos)	
#define GP22_1_ID1_4                		(0x00000010 << GP22_1_ID1_Pos)	
#define GP22_1_ID1_5                		(0x00000020 << GP22_1_ID1_Pos)	
#define GP22_1_ID1_6                		(0x00000040 << GP22_1_ID1_Pos)	
#define GP22_1_ID1_7                		(0x00000080 << GP22_1_ID1_Pos)	
#define GP22_1_SEL_TST01_Pos          	(8U)
#define GP22_1_SEL_TST01_Msk          	(0x07UL << GP22_1_SEL_TST01_Pos)		/*!< 0x00000700 */
#define GP22_1_SEL_TST01          		GP22_1_SEL_TST01_Msk					/*!< SEL_TST01[10:8]Defines functionality of FIRE_IN pin */
#define GP22_1_SEL_TST01_0          		(0x00000001 << GP22_1_SEL_TST01_Pos)	
#define GP22_1_SEL_TST01_1          		(0x00000002 << GP22_1_SEL_TST01_Pos)	
#define GP22_1_SEL_TST01_2          		(0x00000004 << GP22_1_SEL_TST01_Pos)	
#define GP22_1_SEL_TST02_Pos          	(11U)
#define GP22_1_SEL_TST02_Msk          	(0x07UL << GP22_1_SEL_TST02_Pos)		/*!< 0x00003800 */
#define GP22_1_SEL_TST02          		GP22_1_SEL_TST02_Msk					/*!< SEL_TST02[13:11]Defines functionality of EN_START pin */
#define GP22_1_SEL_TST02_0          		(0x00000001 << GP22_1_SEL_TST02_Pos)	
#define GP22_1_SEL_TST02_1          		(0x00000002 << GP22_1_SEL_TST02_Pos)	
#define GP22_1_SEL_TST02_2          		(0x00000004 << GP22_1_SEL_TST02_Pos)	
#define GP22_1_SEL_START_FIRE_Pos     	(14U)
#define GP22_1_SEL_START_FIRE_Msk     	(0x1UL << GP22_1_SEL_START_FIRE_Pos)		/*!< 0x00004000 */
#define GP22_1_SEL_START_FIRE     		GP22_1_SEL_START_FIRE_Msk					/*!< Fire pulse is used as TDC start. The START input is disabled */
#define GP22_1_CURR32K_Pos            	(15U)
#define GP22_1_CURR32K_Msk            	(0x1UL << GP22_1_CURR32K_Pos)		/*!< 0x00008000 */
#define GP22_1_CURR32K            		GP22_1_CURR32K_Msk					/*!< Low current option for 32 kHz oscillator */
#define GP22_1_HITIN1_Pos             	(16U)
#define GP22_1_HITIN1_Msk             	(0x07UL << GP22_1_HITIN1_Pos)		/*!< 0x00070000 */
#define GP22_1_HITIN1             		GP22_1_HITIN1_Msk					/*!< HITIN1[18:16]Number of expected hits on channel 1 */
#define GP22_1_HITIN1_0             		(0x00000001 << GP22_1_HITIN1_Pos)	
#define GP22_1_HITIN1_1             		(0x00000002 << GP22_1_HITIN1_Pos)	
#define GP22_1_HITIN1_2             		(0x00000004 << GP22_1_HITIN1_Pos)	
#define GP22_1_HITIN2_Pos             	(19U)
#define GP22_1_HITIN2_Msk             	(0x07UL << GP22_1_HITIN2_Pos)		/*!< 0x00380000 */
#define GP22_1_HITIN2             		GP22_1_HITIN2_Msk					/*!< HITIN2[21:19]Number of expected hits on channel 2 */
#define GP22_1_HITIN2_0             		(0x00000001 << GP22_1_HITIN2_Pos)	
#define GP22_1_HITIN2_1             		(0x00000002 << GP22_1_HITIN2_Pos)	
#define GP22_1_HITIN2_2             		(0x00000004 << GP22_1_HITIN2_Pos)	
#define GP22_1_KEEP_DEF_22_Pos        	(22U)
#define GP22_1_KEEP_DEF_22_Msk        	(0x1UL << GP22_1_KEEP_DEF_22_Pos)		/*!< 0x00400000 */
#define GP22_1_KEEP_DEF_22        		GP22_1_KEEP_DEF_22_Msk					/*!< Keep default value */
#define GP22_1_EN_FAST_INIT_Pos       	(23U)
#define GP22_1_EN_FAST_INIT_Msk       	(0x1UL << GP22_1_EN_FAST_INIT_Pos)		/*!< 0x00800000 */
#define GP22_1_EN_FAST_INIT       		GP22_1_EN_FAST_INIT_Msk					/*!< Enables fast init operation */
#define GP22_1_HIT1_Pos               	(24U)
#define GP22_1_HIT1_Msk               	(0xFUL << GP22_1_HIT1_Pos)		/*!< 0x0F000000 */
#define GP22_1_HIT1               		GP22_1_HIT1_Msk					/*!< HIT1[27:24]Defines operator for ALU data postprocessing */
#define GP22_1_HIT1_0               		(0x00000001 << GP22_1_HIT1_Pos)	
#define GP22_1_HIT1_1               		(0x00000002 << GP22_1_HIT1_Pos)	
#define GP22_1_HIT1_2               		(0x00000004 << GP22_1_HIT1_Pos)	
#define GP22_1_HIT1_3               		(0x00000008 << GP22_1_HIT1_Pos)	
#define GP22_1_HIT2_Pos               	(28U)
#define GP22_1_HIT2_Msk               	(0xFUL << GP22_1_HIT2_Pos)		/*!< 0xF0000000 */
#define GP22_1_HIT2               		GP22_1_HIT2_Msk					/*!< HIT2[31:28]Defines operator for ALU data postprocessing */
#define GP22_1_HIT2_0               		(0x00000001 << GP22_1_HIT2_Pos)	
#define GP22_1_HIT2_1               		(0x00000002 << GP22_1_HIT2_Pos)	
#define GP22_1_HIT2_2               		(0x00000004 << GP22_1_HIT2_Pos)	
#define GP22_1_HIT2_3               		(0x00000008 << GP22_1_HIT2_Pos)	

/*******************  Bit definition for GP22_2 register  ********************/
#define GP22_2_ID2_Pos                	(0U)
#define GP22_2_ID2_Msk                	(0xFFUL << GP22_2_ID2_Pos)		/*!< 0x000000FF */
#define GP22_2_ID2                		GP22_2_ID2_Msk					/*!< ID2[7:0]Free bits, e.g. to be used as identification or version number */
#define GP22_2_ID2_0                		(0x00000001 << GP22_2_ID2_Pos)	
#define GP22_2_ID2_1                		(0x00000002 << GP22_2_ID2_Pos)	
#define GP22_2_ID2_2                		(0x00000004 << GP22_2_ID2_Pos)	
#define GP22_2_ID2_3                		(0x00000008 << GP22_2_ID2_Pos)	
#define GP22_2_ID2_4                		(0x00000010 << GP22_2_ID2_Pos)	
#define GP22_2_ID2_5                		(0x00000020 << GP22_2_ID2_Pos)	
#define GP22_2_ID2_6                		(0x00000040 << GP22_2_ID2_Pos)	
#define GP22_2_ID2_7                		(0x00000080 << GP22_2_ID2_Pos)	
#define GP22_2_DELVAL1_Pos            	(8U)
#define GP22_2_DELVAL1_Msk            	(0x07FFFFUL << GP22_2_DELVAL1_Pos)		/*!< 0x07FFFF00 */
#define GP22_2_DELVAL1            		GP22_2_DELVAL1_Msk					/*!< DELVAL1[26:8]Delay value for internal stop enable unit, hit 1 channel 1 */
#define GP22_2_DELVAL1_0            		(0x00000001 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_1            		(0x00000002 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_2            		(0x00000004 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_3            		(0x00000008 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_4            		(0x00000010 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_5            		(0x00000020 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_6            		(0x00000040 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_7            		(0x00000080 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_8            		(0x00000100 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_9            		(0x00000200 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_10            		(0x00000400 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_11            		(0x00000800 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_12            		(0x00001000 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_13            		(0x00002000 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_14            		(0x00004000 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_15            		(0x00008000 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_16            		(0x00010000 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_17            		(0x00020000 << GP22_2_DELVAL1_Pos)	
#define GP22_2_DELVAL1_18            		(0x00040000 << GP22_2_DELVAL1_Pos)	
#define GP22_2_RFEDGE1_Pos            	(27U)
#define GP22_2_RFEDGE1_Msk            	(0x1UL << GP22_2_RFEDGE1_Pos)		/*!< 0x08000000 */
#define GP22_2_RFEDGE1            		GP22_2_RFEDGE1_Msk					/*!< Edge sensitivity channel 1 */
#define GP22_2_RFEDGE2_Pos            	(28U)
#define GP22_2_RFEDGE2_Msk            	(0x1UL << GP22_2_RFEDGE2_Pos)		/*!< 0x10000000 */
#define GP22_2_RFEDGE2            		GP22_2_RFEDGE2_Msk					/*!< Edge sensitivity channel 2 */
#define GP22_2_EN_INT_2_0_Pos         	(29U)
#define GP22_2_EN_INT_2_0_Msk         	(0x07UL << GP22_2_EN_INT_2_0_Pos)		/*!< 0xE0000000 */
#define GP22_2_EN_INT_2_0         		GP22_2_EN_INT_2_0_Msk					/*!< EN_INT_2_0[31:29]Activates interrupt sources wired by OR */
#define GP22_2_EN_INT_2_0_0         		(0x00000001 << GP22_2_EN_INT_2_0_Pos)	
#define GP22_2_EN_INT_2_0_1         		(0x00000002 << GP22_2_EN_INT_2_0_Pos)	
#define GP22_2_EN_INT_2_0_2         		(0x00000004 << GP22_2_EN_INT_2_0_Pos)	

/*******************  Bit definition for GP22_3 register  ********************/
#define GP22_3_ID3_Pos                	(0U)
#define GP22_3_ID3_Msk                	(0xFFUL << GP22_3_ID3_Pos)		/*!< 0x000000FF */
#define GP22_3_ID3                		GP22_3_ID3_Msk					/*!< ID3[7:0]Free bits, e.g. to be used as identification or version number */
#define GP22_3_ID3_0                		(0x00000001 << GP22_3_ID3_Pos)	
#define GP22_3_ID3_1                		(0x00000002 << GP22_3_ID3_Pos)	
#define GP22_3_ID3_2                		(0x00000004 << GP22_3_ID3_Pos)	
#define GP22_3_ID3_3                		(0x00000008 << GP22_3_ID3_Pos)	
#define GP22_3_ID3_4                		(0x00000010 << GP22_3_ID3_Pos)	
#define GP22_3_ID3_5                		(0x00000020 << GP22_3_ID3_Pos)	
#define GP22_3_ID3_6                		(0x00000040 << GP22_3_ID3_Pos)	
#define GP22_3_ID3_7                		(0x00000080 << GP22_3_ID3_Pos)	
#define GP22_3_DELVAL2_Pos            	(8U)
#define GP22_3_DELVAL2_Msk            	(0x07FFFFUL << GP22_3_DELVAL2_Pos)		/*!< 0x07FFFF00 */
#define GP22_3_DELVAL2            		GP22_3_DELVAL2_Msk					/*!< DELVAL2[26:8]Delay value for internal stop enable unit, hit 2 channel 1 */
#define GP22_3_DELVAL2_0            		(0x00000001 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_1            		(0x00000002 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_2            		(0x00000004 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_3            		(0x00000008 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_4            		(0x00000010 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_5            		(0x00000020 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_6            		(0x00000040 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_7            		(0x00000080 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_8            		(0x00000100 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_9            		(0x00000200 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_10            		(0x00000400 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_11            		(0x00000800 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_12            		(0x00001000 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_13            		(0x00002000 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_14            		(0x00004000 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_15            		(0x00008000 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_16            		(0x00010000 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_17            		(0x00020000 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELVAL2_18            		(0x00040000 << GP22_3_DELVAL2_Pos)	
#define GP22_3_DELREL1_Pos            	(8U)
#define GP22_3_DELREL1_Msk            	(0x3FUL << GP22_3_DELREL1_Pos)		/*!< 0x00003F00 */
#define GP22_3_DELREL1            		GP22_3_DELREL1_Msk					/*!< DELREL1[13:8]Sets the number of the periods after the first hit for the 1st stop */
#define GP22_3_DELREL1_0            		(0x00000001 << GP22_3_DELREL1_Pos)	
#define GP22_3_DELREL1_1            		(0x00000002 << GP22_3_DELREL1_Pos)	
#define GP22_3_DELREL1_2            		(0x00000004 << GP22_3_DELREL1_Pos)	
#define GP22_3_DELREL1_3            		(0x00000008 << GP22_3_DELREL1_Pos)	
#define GP22_3_DELREL1_4            		(0x00000010 << GP22_3_DELREL1_Pos)	
#define GP22_3_DELREL1_5            		(0x00000020 << GP22_3_DELREL1_Pos)	
#define GP22_3_DELREL2_Pos            	(14U)
#define GP22_3_DELREL2_Msk            	(0x3FUL << GP22_3_DELREL2_Pos)		/*!< 0x000FC000 */
#define GP22_3_DELREL2            		GP22_3_DELREL2_Msk					/*!< DELREL2[19:14]Sets the number of the periods after the first hit for the 2nd stop */
#define GP22_3_DELREL2_0            		(0x00000001 << GP22_3_DELREL2_Pos)	
#define GP22_3_DELREL2_1            		(0x00000002 << GP22_3_DELREL2_Pos)	
#define GP22_3_DELREL2_2            		(0x00000004 << GP22_3_DELREL2_Pos)	
#define GP22_3_DELREL2_3            		(0x00000008 << GP22_3_DELREL2_Pos)	
#define GP22_3_DELREL2_4            		(0x00000010 << GP22_3_DELREL2_Pos)	
#define GP22_3_DELREL2_5            		(0x00000020 << GP22_3_DELREL2_Pos)	
#define GP22_3_DELREL3_Pos            	(20U)
#define GP22_3_DELREL3_Msk            	(0x3FUL << GP22_3_DELREL3_Pos)		/*!< 0x03F00000 */
#define GP22_3_DELREL3            		GP22_3_DELREL3_Msk					/*!< DELREL3[25:20]Sets the number of the periods after the first hit for the 3rd stop */
#define GP22_3_DELREL3_0            		(0x00000001 << GP22_3_DELREL3_Pos)	
#define GP22_3_DELREL3_1            		(0x00000002 << GP22_3_DELREL3_Pos)	
#define GP22_3_DELREL3_2            		(0x00000004 << GP22_3_DELREL3_Pos)	
#define GP22_3_DELREL3_3            		(0x00000008 << GP22_3_DELREL3_Pos)	
#define GP22_3_DELREL3_4            		(0x00000010 << GP22_3_DELREL3_Pos)	
#define GP22_3_DELREL3_5            		(0x00000020 << GP22_3_DELREL3_Pos)	
#define GP22_3_KEEP_DEF_26_Pos        	(26U)
#define GP22_3_KEEP_DEF_26_Msk        	(0x1UL << GP22_3_KEEP_DEF_26_Pos)		/*!< 0x04000000 */
#define GP22_3_KEEP_DEF_26        		GP22_3_KEEP_DEF_26_Msk					/*!< Keep default value */
#define GP22_3_SEL_TIMO_MB2_Pos       	(27U)
#define GP22_3_SEL_TIMO_MB2_Msk       	(0x03UL << GP22_3_SEL_TIMO_MB2_Pos)		/*!< 0x18000000 */
#define GP22_3_SEL_TIMO_MB2       		GP22_3_SEL_TIMO_MB2_Msk					/*!< SEL_TIMO_MB2[28:27]Select predivider for timeout in measurement mode 2 */
#define GP22_3_SEL_TIMO_MB2_0       		(0x00000001 << GP22_3_SEL_TIMO_MB2_Pos)	
#define GP22_3_SEL_TIMO_MB2_1       		(0x00000002 << GP22_3_SEL_TIMO_MB2_Pos)	
#define GP22_3_EN_ERR_VAL_Pos         	(29U)
#define GP22_3_EN_ERR_VAL_Msk         	(0x1UL << GP22_3_EN_ERR_VAL_Pos)		/*!< 0x20000000 */
#define GP22_3_EN_ERR_VAL         		GP22_3_EN_ERR_VAL_Msk					/*!< Timeout forces ALU to write ‘hFFFFFFFF into the output register */
#define GP22_3_EN_FIRST_WAVE_Pos      	(30U)
#define GP22_3_EN_FIRST_WAVE_Msk      	(0x1UL << GP22_3_EN_FIRST_WAVE_Pos)		/*!< 0x40000000 */
#define GP22_3_EN_FIRST_WAVE      		GP22_3_EN_FIRST_WAVE_Msk					/*!< Enables the automatic first hit detection */
#define GP22_3_EN_AUTOCALC_MB2_Pos    	(31U)
#define GP22_3_EN_AUTOCALC_MB2_Msk    	(0x1UL << GP22_3_EN_AUTOCALC_MB2_Pos)		/*!< 0x80000000 */
#define GP22_3_EN_AUTOCALC_MB2    		GP22_3_EN_AUTOCALC_MB2_Msk					/*!< Only in measurement mode 2: automatic calculation of all enabled hits */

/*******************  Bit definition for GP22_4 register  ********************/
#define GP22_4_ID4_Pos                	(0U)
#define GP22_4_ID4_Msk                	(0xFFUL << GP22_4_ID4_Pos)		/*!< 0x000000FF */
#define GP22_4_ID4                		GP22_4_ID4_Msk					/*!< ID4[7:0]Free bits, e.g. to be used as identification or version number */
#define GP22_4_ID4_0                		(0x00000001 << GP22_4_ID4_Pos)	
#define GP22_4_ID4_1                		(0x00000002 << GP22_4_ID4_Pos)	
#define GP22_4_ID4_2                		(0x00000004 << GP22_4_ID4_Pos)	
#define GP22_4_ID4_3                		(0x00000008 << GP22_4_ID4_Pos)	
#define GP22_4_ID4_4                		(0x00000010 << GP22_4_ID4_Pos)	
#define GP22_4_ID4_5                		(0x00000020 << GP22_4_ID4_Pos)	
#define GP22_4_ID4_6                		(0x00000040 << GP22_4_ID4_Pos)	
#define GP22_4_ID4_7                		(0x00000080 << GP22_4_ID4_Pos)	
#define GP22_4_DELVAL3_Pos            	(8U)
#define GP22_4_DELVAL3_Msk            	(0x07FFFFUL << GP22_4_DELVAL3_Pos)		/*!< 0x07FFFF00 */
#define GP22_4_DELVAL3            		GP22_4_DELVAL3_Msk					/*!< DELVAL3[26:8]Delay value for internal stop enable unit, hit 3 channel 1 */
#define GP22_4_DELVAL3_0            		(0x00000001 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_1            		(0x00000002 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_2            		(0x00000004 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_3            		(0x00000008 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_4            		(0x00000010 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_5            		(0x00000020 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_6            		(0x00000040 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_7            		(0x00000080 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_8            		(0x00000100 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_9            		(0x00000200 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_10            		(0x00000400 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_11            		(0x00000800 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_12            		(0x00001000 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_13            		(0x00002000 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_14            		(0x00004000 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_15            		(0x00008000 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_16            		(0x00010000 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_17            		(0x00020000 << GP22_4_DELVAL3_Pos)	
#define GP22_4_DELVAL3_18            		(0x00040000 << GP22_4_DELVAL3_Pos)	
#define GP22_4_KEEP_DEF_31_27_Pos     	(27U)
#define GP22_4_KEEP_DEF_31_27_Msk     	(0x1FUL << GP22_4_KEEP_DEF_31_27_Pos)		/*!< 0xF8000000 */
#define GP22_4_KEEP_DEF_31_27     		GP22_4_KEEP_DEF_31_27_Msk					/*!< KEEP_DEF_31_27[31:27]Keep default value */
#define GP22_4_KEEP_DEF_31_27_0     		(0x00000001 << GP22_4_KEEP_DEF_31_27_Pos)	
#define GP22_4_KEEP_DEF_31_27_1     		(0x00000002 << GP22_4_KEEP_DEF_31_27_Pos)	
#define GP22_4_KEEP_DEF_31_27_2     		(0x00000004 << GP22_4_KEEP_DEF_31_27_Pos)	
#define GP22_4_KEEP_DEF_31_27_3     		(0x00000008 << GP22_4_KEEP_DEF_31_27_Pos)	
#define GP22_4_KEEP_DEF_31_27_4     		(0x00000010 << GP22_4_KEEP_DEF_31_27_Pos)	
#define GP22_4_OFFS_Pos               	(8U)
#define GP22_4_OFFS_Msk               	(0x1FUL << GP22_4_OFFS_Pos)		/*!< 0x00001F00 */
#define GP22_4_OFFS               		GP22_4_OFFS_Msk					/*!< OFFS[12:8]2‘s complement number setting the offset shift in 1 mV steps */
#define GP22_4_OFFS_0               		(0x00000001 << GP22_4_OFFS_Pos)	
#define GP22_4_OFFS_1               		(0x00000002 << GP22_4_OFFS_Pos)	
#define GP22_4_OFFS_2               		(0x00000004 << GP22_4_OFFS_Pos)	
#define GP22_4_OFFS_3               		(0x00000008 << GP22_4_OFFS_Pos)	
#define GP22_4_OFFS_4               		(0x00000010 << GP22_4_OFFS_Pos)	
#define GP22_4_OFFSRNG1_Pos           	(13U)
#define GP22_4_OFFSRNG1_Msk           	(0x1UL << GP22_4_OFFSRNG1_Pos)		/*!< 0x00002000 */
#define GP22_4_OFFSRNG1           		GP22_4_OFFSRNG1_Msk					/*!< Additional offset shift by - 20 mV */
#define GP22_4_OFFSRNG2_Pos           	(14U)
#define GP22_4_OFFSRNG2_Msk           	(0x1UL << GP22_4_OFFSRNG2_Pos)		/*!< 0x00004000 */
#define GP22_4_OFFSRNG2           		GP22_4_OFFSRNG2_Msk					/*!< Additional offset shift by + 20 mV */
#define GP22_4_EDGE_FW_Pos            	(15U)
#define GP22_4_EDGE_FW_Msk            	(0x1UL << GP22_4_EDGE_FW_Pos)		/*!< 0x00008000 */
#define GP22_4_EDGE_FW            		GP22_4_EDGE_FW_Msk					/*!< Sets the edge sensitivity for the first wave */
#define GP22_4_DIS_PW_Pos             	(16U)
#define GP22_4_DIS_PW_Msk             	(0x1UL << GP22_4_DIS_PW_Pos)		/*!< 0x00010000 */
#define GP22_4_DIS_PW             		GP22_4_DIS_PW_Msk					/*!< Disable pulse width measurement */
#define GP22_4_KEEP_DEF_31_17_Pos     	(17U)
#define GP22_4_KEEP_DEF_31_17_Msk     	(0x07FFFUL << GP22_4_KEEP_DEF_31_17_Pos)		/*!< 0xFFFE0000 */
#define GP22_4_KEEP_DEF_31_17     		GP22_4_KEEP_DEF_31_17_Msk					/*!< KEEP_DEF_31_17[31:17]Keep default value */
#define GP22_4_KEEP_DEF_31_17_0     		(0x00000001 << GP22_4_KEEP_DEF_31_17_Pos)	
#define GP22_4_KEEP_DEF_31_17_1     		(0x00000002 << GP22_4_KEEP_DEF_31_17_Pos)	
#define GP22_4_KEEP_DEF_31_17_2     		(0x00000004 << GP22_4_KEEP_DEF_31_17_Pos)	
#define GP22_4_KEEP_DEF_31_17_3     		(0x00000008 << GP22_4_KEEP_DEF_31_17_Pos)	
#define GP22_4_KEEP_DEF_31_17_4     		(0x00000010 << GP22_4_KEEP_DEF_31_17_Pos)	
#define GP22_4_KEEP_DEF_31_17_5     		(0x00000020 << GP22_4_KEEP_DEF_31_17_Pos)	
#define GP22_4_KEEP_DEF_31_17_6     		(0x00000040 << GP22_4_KEEP_DEF_31_17_Pos)	
#define GP22_4_KEEP_DEF_31_17_7     		(0x00000080 << GP22_4_KEEP_DEF_31_17_Pos)	
#define GP22_4_KEEP_DEF_31_17_8     		(0x00000100 << GP22_4_KEEP_DEF_31_17_Pos)	
#define GP22_4_KEEP_DEF_31_17_9     		(0x00000200 << GP22_4_KEEP_DEF_31_17_Pos)	
#define GP22_4_KEEP_DEF_31_17_10     		(0x00000400 << GP22_4_KEEP_DEF_31_17_Pos)	
#define GP22_4_KEEP_DEF_31_17_11     		(0x00000800 << GP22_4_KEEP_DEF_31_17_Pos)	
#define GP22_4_KEEP_DEF_31_17_12     		(0x00001000 << GP22_4_KEEP_DEF_31_17_Pos)	
#define GP22_4_KEEP_DEF_31_17_13     		(0x00002000 << GP22_4_KEEP_DEF_31_17_Pos)	
#define GP22_4_KEEP_DEF_31_17_14     		(0x00004000 << GP22_4_KEEP_DEF_31_17_Pos)	

/*******************  Bit definition for GP22_5 register  ********************/
#define GP22_5_ID5_Pos                	(0U)
#define GP22_5_ID5_Msk                	(0xFFUL << GP22_5_ID5_Pos)		/*!< 0x000000FF */
#define GP22_5_ID5                		GP22_5_ID5_Msk					/*!< ID5[7:0]Free bits, e.g. to be used as identification or version number */
#define GP22_5_ID5_0                		(0x00000001 << GP22_5_ID5_Pos)	
#define GP22_5_ID5_1                		(0x00000002 << GP22_5_ID5_Pos)	
#define GP22_5_ID5_2                		(0x00000004 << GP22_5_ID5_Pos)	
#define GP22_5_ID5_3                		(0x00000008 << GP22_5_ID5_Pos)	
#define GP22_5_ID5_4                		(0x00000010 << GP22_5_ID5_Pos)	
#define GP22_5_ID5_5                		(0x00000020 << GP22_5_ID5_Pos)	
#define GP22_5_ID5_6                		(0x00000040 << GP22_5_ID5_Pos)	
#define GP22_5_ID5_7                		(0x00000080 << GP22_5_ID5_Pos)	
#define GP22_5_PHFIRE_Pos             	(8U)
#define GP22_5_PHFIRE_Msk             	(0xFFFFUL << GP22_5_PHFIRE_Pos)		/*!< 0x00FFFF00 */
#define GP22_5_PHFIRE             		GP22_5_PHFIRE_Msk					/*!< PHFIRE[23:8]Enables phase reversing for each pulse of a sequence of up to 15 possible pulses */
#define GP22_5_PHFIRE_0             		(0x00000001 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_1             		(0x00000002 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_2             		(0x00000004 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_3             		(0x00000008 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_4             		(0x00000010 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_5             		(0x00000020 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_6             		(0x00000040 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_7             		(0x00000080 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_8             		(0x00000100 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_9             		(0x00000200 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_10             		(0x00000400 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_11             		(0x00000800 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_12             		(0x00001000 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_13             		(0x00002000 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_14             		(0x00004000 << GP22_5_PHFIRE_Pos)	
#define GP22_5_PHFIRE_15             		(0x00008000 << GP22_5_PHFIRE_Pos)	
#define GP22_5_REPEAT_FIRE_Pos        	(24U)
#define GP22_5_REPEAT_FIRE_Msk        	(0x07UL << GP22_5_REPEAT_FIRE_Pos)		/*!< 0x07000000 */
#define GP22_5_REPEAT_FIRE        		GP22_5_REPEAT_FIRE_Msk					/*!< REPEAT_FIRE[26:24]Number of pulse sequence repetition for 'quasi-sing-around' */
#define GP22_5_REPEAT_FIRE_0        		(0x00000001 << GP22_5_REPEAT_FIRE_Pos)	
#define GP22_5_REPEAT_FIRE_1        		(0x00000002 << GP22_5_REPEAT_FIRE_Pos)	
#define GP22_5_REPEAT_FIRE_2        		(0x00000004 << GP22_5_REPEAT_FIRE_Pos)	
#define GP22_5_DIS_PHASESHIFT_Pos     	(27U)
#define GP22_5_DIS_PHASESHIFT_Msk     	(0x1UL << GP22_5_DIS_PHASESHIFT_Pos)		/*!< 0x08000000 */
#define GP22_5_DIS_PHASESHIFT     		GP22_5_DIS_PHASESHIFT_Msk					/*!< Phase noise unit */
#define GP22_5_EN_STARTNOISE_Pos      	(28U)
#define GP22_5_EN_STARTNOISE_Msk      	(0x1UL << GP22_5_EN_STARTNOISE_Pos)		/*!< 0x10000000 */
#define GP22_5_EN_STARTNOISE      		GP22_5_EN_STARTNOISE_Msk					/*!< Enables additional noise for start channel */
#define GP22_5_CONF_FIRE_Pos          	(29U)
#define GP22_5_CONF_FIRE_Msk          	(0x07UL << GP22_5_CONF_FIRE_Pos)		/*!< 0xE0000000 */
#define GP22_5_CONF_FIRE          		GP22_5_CONF_FIRE_Msk					/*!< CONF_FIRE[31:29]Output configuration for pulse generator */
#define GP22_5_CONF_FIRE_0          		(0x00000001 << GP22_5_CONF_FIRE_Pos)	
#define GP22_5_CONF_FIRE_1          		(0x00000002 << GP22_5_CONF_FIRE_Pos)	
#define GP22_5_CONF_FIRE_2          		(0x00000004 << GP22_5_CONF_FIRE_Pos)	

/*******************  Bit definition for GP22_6 register  ********************/
#define GP22_6_ID6_Pos                	(0U)
#define GP22_6_ID6_Msk                	(0xFFUL << GP22_6_ID6_Pos)		/*!< 0x000000FF */
#define GP22_6_ID6                		GP22_6_ID6_Msk					/*!< ID6[7:0]Free bits, e.g. to be used as identification or version number */
#define GP22_6_ID6_0                		(0x00000001 << GP22_6_ID6_Pos)	
#define GP22_6_ID6_1                		(0x00000002 << GP22_6_ID6_Pos)	
#define GP22_6_ID6_2                		(0x00000004 << GP22_6_ID6_Pos)	
#define GP22_6_ID6_3                		(0x00000008 << GP22_6_ID6_Pos)	
#define GP22_6_ID6_4                		(0x00000010 << GP22_6_ID6_Pos)	
#define GP22_6_ID6_5                		(0x00000020 << GP22_6_ID6_Pos)	
#define GP22_6_ID6_6                		(0x00000040 << GP22_6_ID6_Pos)	
#define GP22_6_ID6_7                		(0x00000080 << GP22_6_ID6_Pos)	
#define GP22_6_ANZ_FIRE_6_4_Pos       	(8U)
#define GP22_6_ANZ_FIRE_6_4_Msk       	(0x07UL << GP22_6_ANZ_FIRE_6_4_Pos)		/*!< 0x00000700 */
#define GP22_6_ANZ_FIRE_6_4       		GP22_6_ANZ_FIRE_6_4_Msk					/*!< ANZ_FIRE_6_4[10:8]Highest 3 bits of the number of fire pulses */
#define GP22_6_ANZ_FIRE_6_4_0       		(0x00000001 << GP22_6_ANZ_FIRE_6_4_Pos)	
#define GP22_6_ANZ_FIRE_6_4_1       		(0x00000002 << GP22_6_ANZ_FIRE_6_4_Pos)	
#define GP22_6_ANZ_FIRE_6_4_2       		(0x00000004 << GP22_6_ANZ_FIRE_6_4_Pos)	
#define GP22_6_TEMP_PORTDIR_Pos       	(11U)
#define GP22_6_TEMP_PORTDIR_Msk       	(0x1UL << GP22_6_TEMP_PORTDIR_Pos)		/*!< 0x00000800 */
#define GP22_6_TEMP_PORTDIR       		GP22_6_TEMP_PORTDIR_Msk					/*!< Ports for temperature measurement are measured in the opposite order */
#define GP22_6_DOUBLE_RES_Pos         	(12U)
#define GP22_6_DOUBLE_RES_Msk         	(0x1UL << GP22_6_DOUBLE_RES_Pos)		/*!< 0x00001000 */
#define GP22_6_DOUBLE_RES         		GP22_6_DOUBLE_RES_Msk					/*!< Doubles the resolution from 90 ps to 45 ps */
#define GP22_6_QUAD_RES_Pos           	(13U)
#define GP22_6_QUAD_RES_Msk           	(0x1UL << GP22_6_QUAD_RES_Pos)		/*!< 0x00002000 */
#define GP22_6_QUAD_RES           		GP22_6_QUAD_RES_Msk					/*!< Option to improve the resolution by factor 4 from 90 ps to 22 ps. Can be used only in measurement mode 2 */
#define GP22_6_FIRE0_DEF_Pos          	(14U)
#define GP22_6_FIRE0_DEF_Msk          	(0x1UL << GP22_6_FIRE0_DEF_Pos)		/*!< 0x00004000 */
#define GP22_6_FIRE0_DEF          		GP22_6_FIRE0_DEF_Msk					/*!< Specifies the default level of the inactive fire buffer */
#define GP22_6_HZ60_Pos               	(15U)
#define GP22_6_HZ60_Msk               	(0x1UL << GP22_6_HZ60_Pos)		/*!< 0x00008000 */
#define GP22_6_HZ60               		GP22_6_HZ60_Msk					/*!< TDC-GP21 can make complete up and down flow measurement and also two temperature measurements in series */
#define GP22_6_CYCLE_TOF_Pos          	(16U)
#define GP22_6_CYCLE_TOF_Msk          	(0x03UL << GP22_6_CYCLE_TOF_Pos)		/*!< 0x00030000 */
#define GP22_6_CYCLE_TOF          		GP22_6_CYCLE_TOF_Msk					/*!< CYCLE_TOF[17:16]Selects timer for triggering the second ToF measurement in multiples of 50/60Hz */
#define GP22_6_CYCLE_TOF_0          		(0x00000001 << GP22_6_CYCLE_TOF_Pos)	
#define GP22_6_CYCLE_TOF_1          		(0x00000002 << GP22_6_CYCLE_TOF_Pos)	
#define GP22_6_CYCLE_TEMP_Pos         	(18U)
#define GP22_6_CYCLE_TEMP_Msk         	(0x03UL << GP22_6_CYCLE_TEMP_Pos)		/*!< 0x000C0000 */
#define GP22_6_CYCLE_TEMP         		GP22_6_CYCLE_TEMP_Msk					/*!< CYCLE_TEMP[19:18]Selects timer for triggering the second temperature measurement in multiples of 50/60Hz */
#define GP22_6_CYCLE_TEMP_0         		(0x00000001 << GP22_6_CYCLE_TEMP_Pos)	
#define GP22_6_CYCLE_TEMP_1         		(0x00000002 << GP22_6_CYCLE_TEMP_Pos)	
#define GP22_6_START_CLKHS_2_Pos      	(20U)
#define GP22_6_START_CLKHS_2_Msk      	(0x1UL << GP22_6_START_CLKHS_2_Pos)		/*!< 0x00100000 */
#define GP22_6_START_CLKHS_2      		GP22_6_START_CLKHS_2_Msk					/*!< Highest bit to set the settling time for the high speed oscillator */
#define GP22_6_EN_INT_3_Pos           	(21U)
#define GP22_6_EN_INT_3_Msk           	(0x1UL << GP22_6_EN_INT_3_Pos)		/*!< 0x00200000 */
#define GP22_6_EN_INT_3           		GP22_6_EN_INT_3_Msk					/*!< Additional interrupt source */
#define GP22_6_TW2_Pos                	(22U)
#define GP22_6_TW2_Msk                	(0x03UL << GP22_6_TW2_Pos)		/*!< 0x00C00000 */
#define GP22_6_TW2                		GP22_6_TW2_Msk					/*!< TW2[23:22]Timer to charge up the capacitor of the recommend RC network when the internal analog part is used. */
#define GP22_6_TW2_0                		(0x00000001 << GP22_6_TW2_Pos)	
#define GP22_6_TW2_1                		(0x00000002 << GP22_6_TW2_Pos)	
#define GP22_6_KEEP_DEF_24_Pos        	(24U)
#define GP22_6_KEEP_DEF_24_Msk        	(0x1UL << GP22_6_KEEP_DEF_24_Pos)		/*!< 0x01000000 */
#define GP22_6_KEEP_DEF_24        		GP22_6_KEEP_DEF_24_Msk					/*!< Keep default value */
#define GP22_6_DA_KORR_Pos            	(25U)
#define GP22_6_DA_KORR_Msk            	(0xFUL << GP22_6_DA_KORR_Pos)		/*!< 0x1E000000 */
#define GP22_6_DA_KORR            		GP22_6_DA_KORR_Msk					/*!< DA_KORR[28:25]Sets comparator offset from -8 mV to +7 mV. 2‘s complement */
#define GP22_6_DA_KORR_0            		(0x00000001 << GP22_6_DA_KORR_Pos)	
#define GP22_6_DA_KORR_1            		(0x00000002 << GP22_6_DA_KORR_Pos)	
#define GP22_6_DA_KORR_2            		(0x00000004 << GP22_6_DA_KORR_Pos)	
#define GP22_6_DA_KORR_3            		(0x00000008 << GP22_6_DA_KORR_Pos)	
#define GP22_6_KEEP_DEF_29_Pos        	(29U)
#define GP22_6_KEEP_DEF_29_Msk        	(0x1UL << GP22_6_KEEP_DEF_29_Pos)		/*!< 0x20000000 */
#define GP22_6_KEEP_DEF_29        		GP22_6_KEEP_DEF_29_Msk					/*!< Keep default value */
#define GP22_6_NEG_STOP_TEMP_Pos      	(30U)
#define GP22_6_NEG_STOP_TEMP_Msk      	(0x1UL << GP22_6_NEG_STOP_TEMP_Pos)		/*!< 0x40000000 */
#define GP22_6_NEG_STOP_TEMP      		GP22_6_NEG_STOP_TEMP_Msk					/*!< Inverts the SenseT input signal */
#define GP22_6_EN_ANALOG_Pos          	(31U)
#define GP22_6_EN_ANALOG_Msk          	(0x1UL << GP22_6_EN_ANALOG_Pos)		/*!< 0x80000000 */
#define GP22_6_EN_ANALOG          		GP22_6_EN_ANALOG_Msk					/*!< Activates the analog part for the ultrasonic flow measurement */


#endif /* INC_GP22_BIT_DEFINITION_H_ */
