/*
 * GP22_CFG_Macros.h
 *
 *  Created on: 18.08.2022
 *      Author: Matthias Hainz
 */

#ifndef INC_GP22_CFG_MACROS_H_
#define INC_GP22_CFG_MACROS_H_

/* Exported macros -----------------------------------------------------------*/
/** @defgroup _Exported_Macros  Exported Macros"
  * @{
  */

/** @defgroup GP22_0 register
* @{
*/
#define GP22_0_ID0_SET(__Val__)                	(((__Val__) << GP22_0_ID0_Pos) & GP22_0_ID0_Msk)		/*!< Default = 0x0 */
#define GP22_0_NEG_START_SET(__Val__)          	(((__Val__) << GP22_0_NEG_START_Pos) & GP22_0_NEG_START_Msk)		/*!< Default = 0x0 */
#define GP22_0_NEG_STOP1_SET(__Val__)          	(((__Val__) << GP22_0_NEG_STOP1_Pos) & GP22_0_NEG_STOP1_Msk)		/*!< Default = 0x0 */
#define GP22_0_NEG_STOP2_SET(__Val__)          	(((__Val__) << GP22_0_NEG_STOP2_Pos) & GP22_0_NEG_STOP2_Msk)		/*!< Default = 0x0 */
#define GP22_0_MESSB2_SET(__Val__)             	(((__Val__) << GP22_0_MESSB2_Pos) & GP22_0_MESSB2_Msk)		/*!< Default = 0x0 */
#define GP22_0_NO_CAL_AUTO_SET(__Val__)        	(((__Val__) << GP22_0_NO_CAL_AUTO_Pos) & GP22_0_NO_CAL_AUTO_Msk)		/*!< Default = 0x0 */
#define GP22_0_CALIBRATE_SET(__Val__)          	(((__Val__) << GP22_0_CALIBRATE_Pos) & GP22_0_CALIBRATE_Msk)		/*!< Default = 0x1 */
#define GP22_0_SEL_ECLK_TEMP_SET(__Val__)      	(((__Val__) << GP22_0_SEL_ECLK_TEMP_Pos) & GP22_0_SEL_ECLK_TEMP_Msk)		/*!< Default = 0x1 */
#define GP22_0_ANZ_FAKE_SET(__Val__)           	(((__Val__) << GP22_0_ANZ_FAKE_Pos) & GP22_0_ANZ_FAKE_Msk)		/*!< Default = 0x0 */
#define GP22_0_TCYCLE_SET(__Val__)             	(((__Val__) << GP22_0_TCYCLE_Pos) & GP22_0_TCYCLE_Msk)		/*!< Default = 0x0 */
#define GP22_0_ANZ_PORT_SET(__Val__)           	(((__Val__) << GP22_0_ANZ_PORT_Pos) & GP22_0_ANZ_PORT_Msk)		/*!< Default = 0x1 */
#define GP22_0_START_CLKHS_1_0_SET(__Val__)    	(((__Val__) << GP22_0_START_CLKHS_1_0_Pos) & GP22_0_START_CLKHS_1_0_Msk)		/*!< Default = 0x1 */
#define GP22_0_DIV_CLKHS_SET(__Val__)          	(((__Val__) << GP22_0_DIV_CLKHS_Pos) & GP22_0_DIV_CLKHS_Msk)		/*!< Default = 0x0 */
#define GP22_0_ANZ_PER_CALRES_SET(__Val__)     	(((__Val__) << GP22_0_ANZ_PER_CALRES_Pos) & GP22_0_ANZ_PER_CALRES_Msk)		/*!< Default = 0x0 */
#define GP22_0_DIV_FIRE_SET(__Val__)           	(((__Val__) << GP22_0_DIV_FIRE_Pos) & GP22_0_DIV_FIRE_Msk)		/*!< Default = 0x3 */
#define GP22_0_ANZ_FIRE_3_0_SET(__Val__)       	(((__Val__) << GP22_0_ANZ_FIRE_3_0_Pos) & GP22_0_ANZ_FIRE_3_0_Msk)		/*!< Default = 0xF */
/**
* @}
*/

/** @defgroup GP22_1 register
* @{
*/
#define GP22_1_ID1_SET(__Val__)                	(((__Val__) << GP22_1_ID1_Pos) & GP22_1_ID1_Msk)		/*!< Default = 0x0 */
#define GP22_1_SEL_TST01_SET(__Val__)          	(((__Val__) << GP22_1_SEL_TST01_Pos) & GP22_1_SEL_TST01_Msk)		/*!< Default = 0x0 */
#define GP22_1_SEL_TST02_SET(__Val__)          	(((__Val__) << GP22_1_SEL_TST02_Pos) & GP22_1_SEL_TST02_Msk)		/*!< Default = 0x0 */
#define GP22_1_SEL_START_FIRE_SET(__Val__)     	(((__Val__) << GP22_1_SEL_START_FIRE_Pos) & GP22_1_SEL_START_FIRE_Msk)		/*!< Default = 0x0 */
#define GP22_1_CURR32K_SET(__Val__)            	(((__Val__) << GP22_1_CURR32K_Pos) & GP22_1_CURR32K_Msk)		/*!< Default = 0x0 */
#define GP22_1_HITIN1_SET(__Val__)             	(((__Val__) << GP22_1_HITIN1_Pos) & GP22_1_HITIN1_Msk)		/*!< Default = 0x1 */
#define GP22_1_HITIN2_SET(__Val__)             	(((__Val__) << GP22_1_HITIN2_Pos) & GP22_1_HITIN2_Msk)		/*!< Default = 0x0 */
#define GP22_1_KEEP_DEF_22_SET(__Val__)        	(((__Val__) << GP22_1_KEEP_DEF_22_Pos) & GP22_1_KEEP_DEF_22_Msk)		/*!< Default = 0x1 */
#define GP22_1_EN_FAST_INIT_SET(__Val__)       	(((__Val__) << GP22_1_EN_FAST_INIT_Pos) & GP22_1_EN_FAST_INIT_Msk)		/*!< Default = 0x0 */
#define GP22_1_HIT1_SET(__Val__)               	(((__Val__) << GP22_1_HIT1_Pos) & GP22_1_HIT1_Msk)		/*!< Default = 0x1 */
#define GP22_1_HIT2_SET(__Val__)               	(((__Val__) << GP22_1_HIT2_Pos) & GP22_1_HIT2_Msk)		/*!< Default = 0x0 */
/**
* @}
*/

/** @defgroup GP22_2 register
* @{
*/
#define GP22_2_ID2_SET(__Val__)                	(((__Val__) << GP22_2_ID2_Pos) & GP22_2_ID2_Msk)		/*!< Default = 0x0 */
#define GP22_2_DELVAL1_SET(__Val__)            	(((__Val__) << GP22_2_DELVAL1_Pos) & GP22_2_DELVAL1_Msk)		/*!< Default = 0x0 */
#define GP22_2_RFEDGE1_SET(__Val__)            	(((__Val__) << GP22_2_RFEDGE1_Pos) & GP22_2_RFEDGE1_Msk)		/*!< Default = 0x1 */
#define GP22_2_RFEDGE2_SET(__Val__)            	(((__Val__) << GP22_2_RFEDGE2_Pos) & GP22_2_RFEDGE2_Msk)		/*!< Default = 0x0 */
#define GP22_2_EN_INT_2_0_SET(__Val__)         	(((__Val__) << GP22_2_EN_INT_2_0_Pos) & GP22_2_EN_INT_2_0_Msk)		/*!< Default = 0x1 */
/**
* @}
*/

/** @defgroup GP22_3 register
* @{
*/
#define GP22_3_ID3_SET(__Val__)                	(((__Val__) << GP22_3_ID3_Pos) & GP22_3_ID3_Msk)		/*!< Default = 0x0 */
#define GP22_3_DELVAL2_SET(__Val__)            	(((__Val__) << GP22_3_DELVAL2_Pos) & GP22_3_DELVAL2_Msk)		/*!< Default = 0x0 */
#define GP22_3_DELREL1_SET(__Val__)            	(((__Val__) << GP22_3_DELREL1_Pos) & GP22_3_DELREL1_Msk)		/*!< Default = 0x0 */
#define GP22_3_DELREL2_SET(__Val__)            	(((__Val__) << GP22_3_DELREL2_Pos) & GP22_3_DELREL2_Msk)		/*!< Default = 0x0 */
#define GP22_3_DELREL3_SET(__Val__)            	(((__Val__) << GP22_3_DELREL3_Pos) & GP22_3_DELREL3_Msk)		/*!< Default = 0x0 */
#define GP22_3_KEEP_DEF_26_SET(__Val__)        	(((__Val__) << GP22_3_KEEP_DEF_26_Pos) & GP22_3_KEEP_DEF_26_Msk)		/*!< Default = 0x0 */
#define GP22_3_SEL_TIMO_MB2_SET(__Val__)       	(((__Val__) << GP22_3_SEL_TIMO_MB2_Pos) & GP22_3_SEL_TIMO_MB2_Msk)		/*!< Default = 0x0 */
#define GP22_3_EN_ERR_VAL_SET(__Val__)         	(((__Val__) << GP22_3_EN_ERR_VAL_Pos) & GP22_3_EN_ERR_VAL_Msk)		/*!< Default = 0x0 */
#define GP22_3_EN_FIRST_WAVE_SET(__Val__)      	(((__Val__) << GP22_3_EN_FIRST_WAVE_Pos) & GP22_3_EN_FIRST_WAVE_Msk)		/*!< Default = 0x0 */
#define GP22_3_EN_AUTOCALC_MB2_SET(__Val__)    	(((__Val__) << GP22_3_EN_AUTOCALC_MB2_Pos) & GP22_3_EN_AUTOCALC_MB2_Msk)		/*!< Default = 0x0 */
/**
* @}
*/

/** @defgroup GP22_4 register
* @{
*/
#define GP22_4_ID4_SET(__Val__)                	(((__Val__) << GP22_4_ID4_Pos) & GP22_4_ID4_Msk)		/*!< Default = 0x0 */
#define GP22_4_DELVAL3_SET(__Val__)            	(((__Val__) << GP22_4_DELVAL3_Pos) & GP22_4_DELVAL3_Msk)		/*!< Default = 0x0 */
#define GP22_4_KEEP_DEF_31_27_SET(__Val__)     	(((__Val__) << GP22_4_KEEP_DEF_31_27_Pos) & GP22_4_KEEP_DEF_31_27_Msk)		/*!< Default = 0x0 */
#define GP22_4_OFFS_SET(__Val__)               	(((__Val__) << GP22_4_OFFS_Pos) & GP22_4_OFFS_Msk)		/*!< Default = 0x0 */
#define GP22_4_OFFSRNG1_SET(__Val__)           	(((__Val__) << GP22_4_OFFSRNG1_Pos) & GP22_4_OFFSRNG1_Msk)		/*!< Default = 0x0 */
#define GP22_4_OFFSRNG2_SET(__Val__)           	(((__Val__) << GP22_4_OFFSRNG2_Pos) & GP22_4_OFFSRNG2_Msk)		/*!< Default = 0x0 */
#define GP22_4_EDGE_FW_SET(__Val__)            	(((__Val__) << GP22_4_EDGE_FW_Pos) & GP22_4_EDGE_FW_Msk)		/*!< Default = 0x0 */
#define GP22_4_DIS_PW_SET(__Val__)             	(((__Val__) << GP22_4_DIS_PW_Pos) & GP22_4_DIS_PW_Msk)		/*!< Default = 0x0 */
#define GP22_4_KEEP_DEF_31_17_SET(__Val__)     	(((__Val__) << GP22_4_KEEP_DEF_31_17_Pos) & GP22_4_KEEP_DEF_31_17_Msk)		/*!< Default = 0x4 */
/**
* @}
*/

/** @defgroup GP22_5 register
* @{
*/
#define GP22_5_ID5_SET(__Val__)                	(((__Val__) << GP22_5_ID5_Pos) & GP22_5_ID5_Msk)		/*!< Default = 0x0 */
#define GP22_5_PHFIRE_SET(__Val__)             	(((__Val__) << GP22_5_PHFIRE_Pos) & GP22_5_PHFIRE_Msk)		/*!< Default = 0x0 */
#define GP22_5_REPEAT_FIRE_SET(__Val__)        	(((__Val__) << GP22_5_REPEAT_FIRE_Pos) & GP22_5_REPEAT_FIRE_Msk)		/*!< Default = 0x0 */
#define GP22_5_DIS_PHASESHIFT_SET(__Val__)     	(((__Val__) << GP22_5_DIS_PHASESHIFT_Pos) & GP22_5_DIS_PHASESHIFT_Msk)		/*!< Default = 0x0 */
#define GP22_5_EN_STARTNOISE_SET(__Val__)      	(((__Val__) << GP22_5_EN_STARTNOISE_Pos) & GP22_5_EN_STARTNOISE_Msk)		/*!< Default = 0x0 */
#define GP22_5_CONF_FIRE_SET(__Val__)          	(((__Val__) << GP22_5_CONF_FIRE_Pos) & GP22_5_CONF_FIRE_Msk)		/*!< Default = 0x0 */
/**
* @}
*/

/** @defgroup GP22_6 register
* @{
*/
#define GP22_6_ID6_SET(__Val__)                	(((__Val__) << GP22_6_ID6_Pos) & GP22_6_ID6_Msk)		/*!< Default = 0x0 */
#define GP22_6_ANZ_FIRE_6_4_SET(__Val__)       	(((__Val__) << GP22_6_ANZ_FIRE_6_4_Pos) & GP22_6_ANZ_FIRE_6_4_Msk)		/*!< Default = 0x0 */
#define GP22_6_TEMP_PORTDIR_SET(__Val__)       	(((__Val__) << GP22_6_TEMP_PORTDIR_Pos) & GP22_6_TEMP_PORTDIR_Msk)		/*!< Default = 0x0 */
#define GP22_6_DOUBLE_RES_SET(__Val__)         	(((__Val__) << GP22_6_DOUBLE_RES_Pos) & GP22_6_DOUBLE_RES_Msk)		/*!< Default = 0x0 */
#define GP22_6_QUAD_RES_SET(__Val__)           	(((__Val__) << GP22_6_QUAD_RES_Pos) & GP22_6_QUAD_RES_Msk)		/*!< Default = 0x0 */
#define GP22_6_FIRE0_DEF_SET(__Val__)          	(((__Val__) << GP22_6_FIRE0_DEF_Pos) & GP22_6_FIRE0_DEF_Msk)		/*!< Default = 0x0 */
#define GP22_6_HZ60_SET(__Val__)               	(((__Val__) << GP22_6_HZ60_Pos) & GP22_6_HZ60_Msk)		/*!< Default = 0x0 */
#define GP22_6_CYCLE_TOF_SET(__Val__)          	(((__Val__) << GP22_6_CYCLE_TOF_Pos) & GP22_6_CYCLE_TOF_Msk)		/*!< Default = 0x0 */
#define GP22_6_CYCLE_TEMP_SET(__Val__)         	(((__Val__) << GP22_6_CYCLE_TEMP_Pos) & GP22_6_CYCLE_TEMP_Msk)		/*!< Default = 0x0 */
#define GP22_6_START_CLKHS_2_SET(__Val__)      	(((__Val__) << GP22_6_START_CLKHS_2_Pos) & GP22_6_START_CLKHS_2_Msk)		/*!< Default = 0x0 */
#define GP22_6_EN_INT_3_SET(__Val__)           	(((__Val__) << GP22_6_EN_INT_3_Pos) & GP22_6_EN_INT_3_Msk)		/*!< Default = 0x0 */
#define GP22_6_TW2_SET(__Val__)                	(((__Val__) << GP22_6_TW2_Pos) & GP22_6_TW2_Msk)		/*!< Default = 0x0 */
#define GP22_6_KEEP_DEF_24_SET(__Val__)        	(((__Val__) << GP22_6_KEEP_DEF_24_Pos) & GP22_6_KEEP_DEF_24_Msk)		/*!< Default = 0x0 */
#define GP22_6_DA_KORR_SET(__Val__)            	(((__Val__) << GP22_6_DA_KORR_Pos) & GP22_6_DA_KORR_Msk)		/*!< Default = 0x0 */
#define GP22_6_KEEP_DEF_29_SET(__Val__)        	(((__Val__) << GP22_6_KEEP_DEF_29_Pos) & GP22_6_KEEP_DEF_29_Msk)		/*!< Default = 0x0 */
#define GP22_6_NEG_STOP_TEMP_SET(__Val__)      	(((__Val__) << GP22_6_NEG_STOP_TEMP_Pos) & GP22_6_NEG_STOP_TEMP_Msk)		/*!< Default = 0x0 */
#define GP22_6_EN_ANALOG_SET(__Val__)          	(((__Val__) << GP22_6_EN_ANALOG_Pos) & GP22_6_EN_ANALOG_Msk)		/*!< Default = 0x0 */
/**
* @}
*/

/**
* @}
*/


#endif /* INC_GP22_CFG_MACROS_H_ */
