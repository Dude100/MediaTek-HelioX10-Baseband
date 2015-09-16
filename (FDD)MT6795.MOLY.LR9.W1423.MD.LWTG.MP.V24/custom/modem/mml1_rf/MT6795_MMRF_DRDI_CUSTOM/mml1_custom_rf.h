/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   mml1_custom_rf.h
 *
 * Project:
 * --------
 *   MT6290 EVB
 *
 * Description:
 * ------------
 *   MT6290 EVB Multi-Mode Multi-RAT L1 constance definition
 *
 * Author:
 * -------
 *
 *
 *==============================================================================
 *******************************************************************************/

#ifndef  _MML1_CUSTOM_RF_H_
#define  _MML1_CUSTOM_RF_H_
/* --------------------------------------------------------------------------- */
/*MT6595*/
/*MT6595*/ /*----------------------------------------------------*/
/*MT6595*/ /*   Enable or disable the clock1, 2, 3, and 4 output */
/*MT6595*/ /*   1 : Enable                                       */
/*MT6595*/ /*   0 : Disable                                      */
/*MT6595*/ /*----------------------------------------------------*/
/*MT6595*/ #define MML1_CLK1_EN                         1 /* CLK1 is enabled for BB */
/*MT6595*/ #define MML1_CLK2_EN                         1
/*MT6595*/ #define MML1_CLK3_EN                         1
/*MT6595*/ #define MML1_CLK4_EN                         1
/*MT6595*/
/* --------------------------------------------------------------------------- */

/* MT6595 DSDA Dual Talk feature usage */
#define LTE_DSDA_RXON_CONFIG_GPIO_NUM          53
#define LTE_DSDA_TX_FILTER_PATH_READ_GPIO_NUM  52


#endif

