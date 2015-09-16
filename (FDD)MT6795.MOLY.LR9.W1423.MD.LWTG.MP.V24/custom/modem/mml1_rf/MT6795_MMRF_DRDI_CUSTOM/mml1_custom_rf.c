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
 *   mml1_custom_rf.c
 *
 * Project:
 * --------
 *   MT6595 EVB
 *
 * Description:
 * ------------
 *   MT6595 EVB Multi-Mode Multi-RAT L1 constance definition
 *
 * Author:
 * -------
 *
 *
 *==============================================================================
 *******************************************************************************/

#include "kal_general_types.h"
#include "mml1_custom_rf.h"

kal_uint32  MML1_CLK_EN_TABLE[4] = {  MML1_CLK1_EN, MML1_CLK2_EN, MML1_CLK3_EN, MML1_CLK4_EN  };

/* MT6595 DSDA Dual Talk feature usage */
kal_uint16 lte_dsda_rxon_config_gpio_num = LTE_DSDA_RXON_CONFIG_GPIO_NUM;
kal_uint16 lte_dsda_tx_filter_path_read_gpio_num = LTE_DSDA_TX_FILTER_PATH_READ_GPIO_NUM;

