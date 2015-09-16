/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * nvram_data_items.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains `vendor' defined logical data items stored in NVRAM.
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_config.c
 *
 * Author:
 * -------
 * 
 * 
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_NOT_PRESENT

#define NVRAM_FACTORY_CONFIG

#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "kal_general_types.h"

#include "nvram_defs.h"
#include "nvram_enums.h"
#include "nvram_data_items.h"
#include "nvram_editor_data_item.h"
#include "custom_nvram_config.h"
#include "custom_nvram_sec.h"
#include "custom_nvram_restore.h"
#include "custom_nvram_config.h"
#if defined(__NVRAM_COMPRESS_SUPPORT__) && !defined(NVRAM_AUTO_GEN)
#include "nvram_default_value.h"
#endif


#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
#include "ul1cal.h"
#endif /* __UMTS_RAT__ && __MTK_UL1_FDD__ */

#ifdef __AST_TL1_TDD__
#include "tl1cal_ast.h"
#include "tl1d_custom_rf.h"
#endif // __AST_TL1_TDD__

#include "l1cal.h"

#include "adc_channel.h"
#include "ul1_nvram_def.h"
extern void nvram_get_L1_default_value_to_write(nvram_lid_enum lid, kal_uint8 *buffer, kal_uint16 buffer_size);
extern void nvram_get_uL1_default_value_to_write(nvram_lid_enum lid, kal_uint8 * buffer, kal_uint16 buffer_size);

/**
 * Steps of defining logical data item:
 * 1> Define LID of new logical data item into `nvram_lid_core_enum' in
 *    nvram_data_items.h
 * 2> Define two constants: SIZE and TOTAL, in nvram_data_items.h
 * 3> Define default value of that new logical data item.
 * 4> Define attributes of that new logical data item into
 *    `logical_data_item_table_core'
 * 5> Change NVRAM_TOTAL_LID_VENDOR in nvram_user_defs.h
 * 6> Add structure defination in nvram_editor_data_item.h
 * 7> Add bit-level description in nvram_editor_data_item.h
 * 8> Change version number CODED_DATA_VERSION in nvram_user_config.c
 *
 * Note that multiple copied attribute DOES NOT support for
 * near fixed logical data items.
 */

/**
 * Step 3:
 * Define necessary default values for each logical data item.
 */



#ifdef __AST_TL1_TDD__
/*Nan Shen:Temp solution for fixing build error*/
extern kal_uint16 const NVRAM_EF_AST_TL1_AFC_DATA_DEFAULT[];
extern kal_int16 const NVRAM_EF_AST_TL1_PATHLOSS_33_35_37_39_DEFAULT[];
extern kal_int16 const NVRAM_EF_AST_TL1_PATHLOSS_34_DEFAULT[];
extern kal_int16 const NVRAM_EF_AST_TL1_TXDAC_33_35_37_39_DEFAULT[];
extern kal_int16 const NVRAM_EF_AST_TL1_TXDAC_34_DEFAULT[];
extern kal_int16 const NVRAM_EF_AST_TL1_TXDAC_40_DEFAULT[];
extern kal_int16 const NVRAM_EF_AST_TL1_ABB_CAL_DEFAULT[];
extern kal_int16 const NVRAM_EF_AST_TL1_TXCLPC_34_DEFAULT[];
extern kal_int16 const NVRAM_EF_AST_TL1_TXCLPC_39_DEFAULT[];
extern kal_int16 const NVRAM_EF_AST_TL1_TXCLPC_40_DEFAULT[];
#if !defined(__AST1001__) && !defined(__AST2001__)
extern kal_uint32 const NVRAM_EF_AST_TL1_CAP_DATA_DEFAULT[];
#endif

#ifdef __TDD_RF_CUSTOM_TOOL_SUPPORT__
extern T_TD_CUSTOMIZATION_STRUCT TD_CUST_CONST    NVRAM_EF_AST_TL1_RF_PARAMETER_DEFAULT[]; 
#endif
#endif



#ifdef  __BTMODULE_MT6601__
static kal_uint8 const NVRAM_EF_BTRADIO_MT6601_DEFAULT[] = {
/* BDAddr                       ,  6 */ 0x01,0x66,0x00,0x00,0x00,0x00,
/* ClassOfDevice                ,  3 */ 0x00,0x1F,0x00,
/* LinkKeyType                  ,  1 */ 0x01,
/* UnitKey                      , 16 */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* Encryption                   ,  3 */ 0x00,0x02,0x10,
/* PinCodeType                  ,  1 */ 0x00,
/* Voice                        ,  2 */ 0xAC,0x00,
/* Codec                        ,  1 */ 0x23,
/* Radio                        , 30 */ 0x02,0x01,0x7F,0x07,0x07,0x80,0x00,0x0B,0x03,
                                        0x07,
                                        0xFA,0x00,0x32,0x01,0x00,0x03,0xFF,0x16,0x07,0x17,0x01,0x35,0x7F,0x28,0x00,0x00,0x00,0x00,0x00,0x00,
#if defined(__MTK_TARGET__)
/* Sleep                        ,  6 */ 0x03,0x40,0x1F,0x40,0x1F,0x02,
#else
/* Sleep                        ,  6 */ 0x00,0x40,0x1F,0x00,0x00,0x02,
#endif
/* MainOscillatorInfo           ,  5 */ 0x01,0x01,0x14,0x0A,0x08,
/* LPOInfo                      ,  4 */ 0x01,0x04,0xFA,0x0A,
/* AFH                          ,  9 */ 0x40,0x06,0x40,0x06,0x40,0x1F,0x01,0x08,0x04,
/* PTA                          , 49 */ 0x01,0x14,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
                                        0x41,0x14,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
                                        0x21,0x14,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
                                        0x00,0x00,0x00,0x00,0x00,
                                        0xA4,0x04,0x80,0x01,0x3F,0x02,0x38,0x04,
                                        0xDC,0x0A,0x00,0x00,0xFF,0x00,0x00,0x01,0x01,
/* WDT                          ,  2 */ 0xFF,0x00,
/* Debug                        ,  1 */ 0x80,
/* UART                         ,  2 */ 0x0B,0x00
};
#endif /* __BTMODULE_MT6601__*/

#ifdef  __BTMODULE_MT6611__
static kal_uint8 const NVRAM_EF_BTRADIO_MT6611_DEFAULT[] = {
/* BDAddr                       ,  6 */ 0x11,0x66,0x00,0x00,0x00,0x00,
/* Radio Cap Id                 ,  1 */ 0x40,
/* LinkKeyType                  ,  1 */ 0x01,
/* UnitKey                      , 16 */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* Encryption                   ,  3 */ 0x00,0x02,0x10,
/* PinCodeType                  ,  1 */ 0x00,
/* Voice                        ,  2 */ 0x60,0x00,
/* Codec                        ,  1 */ 0x23,
/* Radio                        , 6 */ 0x07,0x80,0x00,0x06,0x03,0x07,
#if defined(__MTK_TARGET__)
/* Sleep                        ,  7 */ 0x03,0x40,0x1F,0x40,0x1F,0x00,0x04,
#else
/* Sleep                        ,  7 */ 0x00,0x40,0x1F,0x00,0x00,0x00,0x04,
#endif
/* Reserved                      ,  2 */0x80,0x00,
};
#endif /* __BTMODULE_MT6611__*/


#if  defined(__BTMODULE_MT6612__) || defined(__BTMODULE_MT6616__) || defined(__BTMODULE_MT6622__) || defined(__BTMODULE_MT6626__) || defined(__BTMODULE_MT6236__) || defined(__BTMODULE_MT6256__) || defined(__BTMODULE_MT6276__) || defined(__BTMODULE_MT6255__)
static kal_uint8 const NVRAM_EF_BTRADIO_MTK_BT_CHIP_DEFAULT[] = {
/* BDAddr                       ,  6 */ 0x00,0x66,0x00,0x00,0x00,0x00,
/* Radio Cap Id                 ,  1 */ 0xFF,
/* LinkKeyType                  ,  1 */ 0x01,
/* UnitKey                      , 16 */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* Encryption                   ,  3 */ 0x00,0x02,0x10,
/* PinCodeType                  ,  1 */ 0x00,
/* Voice                        ,  2 */ 0x60,0x00,
/* Codec                        ,  1 */ 0x23,
/* Radio                        ,  6 */ 0x07,0x80,0x00,0x06,0x03,0x07,
#if defined(__MTK_TARGET__)
/* Sleep                        ,  7 */ 0x03,0x40,0x1F,0x40,0x1F,0x00,0x04,
#else
/* Sleep                        ,  7 */ 0x00,0x40,0x1F,0x00,0x00,0x00,0x04,
#endif
/* Reserved                     ,  2 */0x80,0x00,
#if  defined(__BTMODULE_MT6626__) && defined(__PHONE__)
/* ECLK_SEL                     ,  1 */0x01,
#else
/* ECLK_SEL                     ,  1 */0x00,
#endif
};
#endif /* defined(__BTMODULE_MT6612__) || defined(__BTMODULE_MT6616__) || defined(__BTMODULE_MT6622__) || defined(__BTMODULE_MT6626__) || defined(__BTMODULE_MT6236__) || defined(__BTMODULE_MT6256__) || defined(__BTMODULE_MT6276__)*/




#if defined(__WIFI_SUPPORT__)&&(__CUSTOM_WIFI_FEATURES_SWITCH__)

#include "wndrv_cal.h"
#include "wifi_common_config.h"
extern wndrv_cal_mac_addr_struct wndrv_default_mac_addr;

#if defined(WIFI_BB_MT5911)
    #if defined( WIFI_RF_AL2236 )
extern const wndrv_cal_txpwr_2400M_struct wndrv_default_txpwr_2400M;
   #else
extern const wndrv_cal_txpwr_2400M_struct wndrv_default_txpwr_2400M;
    #endif
//20081110 add by saker for MT5921 support
#elif defined(WIFI_BB_MT5921) || defined(MT5931)
extern const wndrv_cal_txpwr_2400M_struct wndrv_default_txpwr_2400M;
#endif

extern const wndrv_cal_txpwr_5000M_struct wndrv_default_txpwr_5000M;

extern const wndrv_cal_dac_dc_offset_struct wndrv_default_dac_dc_offset;

extern const wndrv_cal_tx_ALC_2400M_struct wndrv_default_tx_ALC_pwr;

extern const wndrv_cal_ALC_Slope_2400M_struct wndrv_default_ALC_Slope;

extern const wndrv_cal_txpwr_cal_free_flow_struct wndrv_default_TPCFF;

extern const wndrv_cal_setting_trim_thermo_struct wndrv_cal_setting_trim_thermo;

#endif

#if defined(__IC_SLT__)
static kal_uint8 const NVRAM_EF_IMEI_DEFAULT[] = {0x53, 0x93,  0x91, 0x20, 0x65, 0x08, 0x31, 0x70, 0x00, 0x00};
#endif

/**
 * Step 4:
 * The logical data item table.
 * Note:
 * Each logical data item must be:
 * 1> Size must be EVEN
 * 2> Size of default value must be equal to the logical data item's size.
 *
 * The last LID in the MT reign now is MT1k
 */
ltable_entry_struct logical_data_item_table_factory[] =
{

    
#if defined(__CCCIFS_SUPPORT__)
    {
        NVRAM_EF_IMPT_COUNTER_LID,
        NVRAM_EF_IMPT_COUNTER_TOTAL,
        NVRAM_EF_IMPT_COUNTER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_IMPORTANT_L4,
        NVRAM_ATTR_AVERAGE,
        "MP0D",
        VER(NVRAM_EF_IMPT_COUNTER_LID)
    },
#endif
        
    {
        NVRAM_EF_L1_AGCPATHLOSS_LID,
        NVRAM_EF_L1_AGCPATHLOSS_TOTAL,
        NVRAM_EF_L1_AGCPATHLOSS_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
        "MT95",
   #else
        "MT05",
   #endif
        VER(NVRAM_EF_L1_AGCPATHLOSS_LID)
    },

#ifdef __GSM850__
    {
        NVRAM_EF_L1_RAMPTABLE_GSM850_LID,
        NVRAM_EF_L1_RAMPTABLE_GSM850_TOTAL,
        NVRAM_EF_L1_RAMPTABLE_GSM850_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
		"MT96",
   #else
        "MT06",
   #endif
        VER(NVRAM_EF_L1_RAMPTABLE_GSM850_LID)
    },
#endif

#ifdef __EGSM900__
    {
        NVRAM_EF_L1_RAMPTABLE_GSM900_LID,
        NVRAM_EF_L1_RAMPTABLE_GSM900_TOTAL,
        NVRAM_EF_L1_RAMPTABLE_GSM900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
		"MT97",
   #else
        "MT07",
   #endif
        VER(NVRAM_EF_L1_RAMPTABLE_GSM900_LID)
    },
#endif

#ifdef __DCS1800__
    {
        NVRAM_EF_L1_RAMPTABLE_DCS1800_LID,
        NVRAM_EF_L1_RAMPTABLE_DCS1800_TOTAL,
        NVRAM_EF_L1_RAMPTABLE_DCS1800_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
		"MT98",
   #else
        "MT08",
   #endif
        VER(NVRAM_EF_L1_RAMPTABLE_DCS1800_LID)
    },
#endif

#ifdef __PCS1900__
    {
        NVRAM_EF_L1_RAMPTABLE_PCS1900_LID,
        NVRAM_EF_L1_RAMPTABLE_PCS1900_TOTAL,
        NVRAM_EF_L1_RAMPTABLE_PCS1900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
		"MT99",
   #else
        "MT09",
   #endif
        VER(NVRAM_EF_L1_RAMPTABLE_PCS1900_LID)
    },
#endif

#if defined(__EPSK_TX__)
#ifdef __GSM850__
    {
        NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID,
        NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_TOTAL,
        NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
        "MT9A",
   #else
        "MT0A",
   #endif
        VER(NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID)
    },
#endif

#ifdef __EGSM900__
    {
        NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID,
        NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_TOTAL,
        NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
        "MT9B",
   #else
        "MT0B",
   #endif
        VER(NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID)
    },
#endif

#ifdef __DCS1800__
    {
        NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID,
        NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_TOTAL,
        NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)   
        "MT9C",
   #else
        "MT0C",
   #endif
        VER(NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID)
    },
#endif

#ifdef __PCS1900__
    {
        NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID,
        NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_TOTAL,
        NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)   
        "MT9D",
   #else
        "MT0D",
   #endif
        VER(NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID)
    },
#endif

#ifdef __GSM850__
    {
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_TOTAL,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
        "MT9E",
   #else
        "MT0E",
   #endif
        VER(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID)
    },
#endif

#ifdef __EGSM900__
    {
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_TOTAL,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
        "MT9F",
   #else        
        "MT0F",
   #endif
        VER(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID)
    },
#endif

#ifdef __DCS1800__
    {
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_TOTAL,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
		"MT9G",
   #else 
        "MT0G",
   #endif
        VER(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID)
    },
#endif

#ifdef __PCS1900__
    {
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_TOTAL,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
		"MT9H",
   #else 
        "MT0H",
   #endif
        VER(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID)
    },
#endif

#endif/*__EPSK_TX__*/
    {
        NVRAM_EF_L1_AFCDATA_LID,
        NVRAM_EF_L1_AFCDATA_TOTAL,
        NVRAM_EF_L1_AFCDATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
		"MT9I",
   #else 
        "MT0I",
   #endif
        VER(NVRAM_EF_L1_AFCDATA_LID)
    },
    
    {
        NVRAM_EF_L1_TXIQ_LID,
        NVRAM_EF_L1_TXIQ_TOTAL,
        NVRAM_EF_L1_TXIQ_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
		"MT9J",
   #else 
        "MT0J",
   #endif
        VER(NVRAM_EF_L1_TXIQ_LID)
    },
    
    {
        NVRAM_EF_L1_RFSPECIALCOEF_LID,
        NVRAM_EF_L1_RFSPECIALCOEF_TOTAL,
        NVRAM_EF_L1_RFSPECIALCOEF_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
		"MT9K",
   #else 
        "MT0K",
   #endif
        VER(NVRAM_EF_L1_RFSPECIALCOEF_LID)
    },

#ifdef __GSM850__
    {
        NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID,
        NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_TOTAL,
        NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
		"MT9L",
   #else 
        "MT0L",
   #endif
        VER(NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID)
    },
#endif

#ifdef __EGSM900__
    {
        NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID,
        NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_TOTAL,
        NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
		"MT9M",
   #else 
        "MT0M",
   #endif
        VER(NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID)
    },
#endif

#ifdef __DCS1800__
    {
        NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID,
        NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_TOTAL,
        NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
	    "MT9N",
   #else 
        "MT0N",
   #endif
        VER(NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID)
    },
#endif

#ifdef __PCS1900__
    {
        NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID,
        NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_TOTAL,
        NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
	    "MT9O",
   #else 
        "MT0O",
   #endif
        VER(NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID)
    },
#endif
    
    {
        NVRAM_EF_L1_CRYSTAL_AFCDATA_LID,
        NVRAM_EF_L1_CRYSTAL_AFCDATA_TOTAL,
        NVRAM_EF_L1_CRYSTAL_AFCDATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
	    "MT9P",
   #else 
        "MT0P",
   #endif
        VER(NVRAM_EF_L1_CRYSTAL_AFCDATA_LID)
    },
    
    {
        NVRAM_EF_L1_CRYSTAL_CAPDATA_LID,
        NVRAM_EF_L1_CRYSTAL_CAPDATA_TOTAL,
        NVRAM_EF_L1_CRYSTAL_CAPDATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
	    "MT9Q",
   #else 
        "MT0Q",
   #endif
        VER(NVRAM_EF_L1_CRYSTAL_CAPDATA_LID)
    },

#if defined(__PS_SERVICE__)
    {
        NVRAM_EF_L1_GMSK_TX_POWER_ROLLBACK_TABLE_LID,
        NVRAM_EF_L1_GMSK_TX_POWER_ROLLBACK_TABLE_TOTAL,
        NVRAM_EF_L1_GMSK_TX_POWER_ROLLBACK_TABLE_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
	    "MT9R",
   #else 
        "MT0R",
   #endif
        VER(NVRAM_EF_L1_GMSK_TX_POWER_ROLLBACK_TABLE_LID)
    },

#if defined(__EGPRS_MODE__)
    {
        NVRAM_EF_L1_EPSK_TX_POWER_ROLLBACK_TABLE_LID,
        NVRAM_EF_L1_EPSK_TX_POWER_ROLLBACK_TABLE_TOTAL,
        NVRAM_EF_L1_EPSK_TX_POWER_ROLLBACK_TABLE_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
	    "MT9S",
   #else 
        "MT0S",
   #endif
        VER(NVRAM_EF_L1_EPSK_TX_POWER_ROLLBACK_TABLE_LID)
    },
#endif /* defined(__EGPRS_MODE__) */
#endif /*defined(__PS_SERVICE__) */

#if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
    {
        NVRAM_EF_L1_GMSK_TXPC_LID,
        NVRAM_EF_L1_GMSK_TXPC_TOTAL,
        NVRAM_EF_L1_GMSK_TXPC_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
	    "MT9T",
   #else 
        "MT0T",
   #endif
        VER(NVRAM_EF_L1_GMSK_TXPC_LID)
    },
#if defined(__EPSK_TX__)
    {
        NVRAM_EF_L1_EPSK_TXPC_LID,
        NVRAM_EF_L1_EPSK_TXPC_TOTAL,
        NVRAM_EF_L1_EPSK_TXPC_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
	    "MT9U",
   #else 
        "MT0U",
   #endif
        VER(NVRAM_EF_L1_EPSK_TXPC_LID)
    },
#endif /* defined(__EPSK_TX__) */
#endif /* defined(__2G_TX_POWER_CONTROL_SUPPORT__) */

#if defined(__MULTI_LNA_MODE_CALIBRATION_SUPPORT__)
    {
        NVRAM_EF_L1_LNAPATHLOSS_LID,
        NVRAM_EF_L1_LNAPATHLOSS_TOTAL,
        NVRAM_EF_L1_LNAPATHLOSS_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
	    "MT9V",
   #else 
        "MT0V",
   #endif
        VER(NVRAM_EF_L1_LNAPATHLOSS_LID)
    },
#endif

#if defined(__F32_XOSC_REMOVAL_SUPPORT__)
    {
        NVRAM_EF_L1_CLOAD_FREQ_OFFSET_LID,
        NVRAM_EF_L1_CLOAD_FREQ_OFFSET_TOTAL,
        NVRAM_EF_L1_CLOAD_FREQ_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
	    "MT8V",
   #else 
        "MT1V",
   #endif
        VER(NVRAM_EF_L1_CLOAD_FREQ_OFFSET_LID),
    },
#endif

#if defined(__2G_TX_GAIN_RF_CALIBRATION__)
    {
        NVRAM_EF_L1_GAINRF_LID,
        NVRAM_EF_L1_GAINRF_LID_TOTAL,
        NVRAM_EF_L1_GAINRF_LID_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT1W",
        VER(NVRAM_EF_L1_GAINRF_LID),
    },
#endif

#if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
#if !defined(__UMTS_RAT__) || !defined(__MTK_UL1_FDD__)|| defined(__MULTI_RAT_AFC_TADC_SHARE_SUPPORT__)
    {
        NVRAM_EF_L1_TEMPERATURE_ADC_LID,
        NVRAM_EF_L1_TEMPERATURE_ADC_TOTAL,
        NVRAM_EF_L1_TEMPERATURE_ADC_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
	    "MT8U",
   #else 
        "MT1U",
   #endif
        VER(NVRAM_EF_L1_TEMPERATURE_ADC_LID)
    },
#endif /* !defined(__UMTS_RAT__) || !defined(__MTK_UL1_FDD__)|| defined(__MULTI_RAT_AFC_TADC_SHARE_SUPPORT__) */
#endif /* defined(__2G_TX_POWER_CONTROL_SUPPORT__) */

#if defined(__TX_POWER_OFFSET_SUPPORT__)
   {
       NVRAM_EF_L1_2G_RF_PARAMETER_EXT_LID,
       NVRAM_EF_L1_2G_RF_PARAMETER_EXT_TOTAL,
       NVRAM_EF_L1_2G_RF_PARAMETER_EXT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "MT1X",
       VER(NVRAM_EF_L1_2G_RF_PARAMETER_EXT_LID),
   },
   {
       NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_GSM850_LID,
       NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_GSM850_TOTAL,
       NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_GSM850_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "MT1Y",
       VER(NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_GSM850_LID),
   },
   {
       NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_GSM900_LID,
       NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_GSM900_TOTAL,
       NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_GSM900_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "MT1Z",
       VER(NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_GSM900_LID),
   },
   {
       NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_DCS_LID,
       NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_DCS_TOTAL,
       NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_DCS_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "MT20",
       VER(NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_DCS_LID),
   },
   {
       NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_PCS_LID,
       NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_PCS_TOTAL,
       NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_PCS_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "MT21",
       VER(NVRAM_EF_L1_GMSK_TX_POWER_OFFSET_PCS_LID),
   },
   {
       NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_GSM850_LID,
       NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_GSM850_TOTAL,
       NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_GSM850_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "MT22",
       VER(NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_GSM850_LID),
   },
   {
       NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_GSM900_LID,
       NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_GSM900_TOTAL,
       NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_GSM900_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "MT23",
       VER(NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_GSM900_LID),
   },
   {
       NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_DCS_LID,
       NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_DCS_TOTAL,
       NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_DCS_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "MT24",
       VER(NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_DCS_LID),
   },
   {
       NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_PCS_LID,
       NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_PCS_TOTAL,
       NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_PCS_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "MT25",
       VER(NVRAM_EF_L1_EPSK_TX_POWER_OFFSET_PCS_LID),
   },
#endif   /* __TX_POWER_OFFSET_SUPPORT__ */

#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
    {
        NVRAM_EF_UL1_TEMP_DAC_LID,
        NVRAM_EF_UL1_TEMP_DAC_TOTAL,
        NVRAM_EF_UL1_TEMP_DAC_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL10",
        VER(NVRAM_EF_UL1_TEMP_DAC_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS_BAND1_LID,
        NVRAM_EF_UL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL11",
        VER(NVRAM_EF_UL1_PATHLOSS_BAND1_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS_BAND2_LID,
        NVRAM_EF_UL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL12",
        VER(NVRAM_EF_UL1_PATHLOSS_BAND2_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS_BAND3_LID,
        NVRAM_EF_UL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL13",
        VER(NVRAM_EF_UL1_PATHLOSS_BAND3_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS_BAND4_LID,
        NVRAM_EF_UL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL14",
        VER(NVRAM_EF_UL1_PATHLOSS_BAND4_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS_BAND5_LID,
        NVRAM_EF_UL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL15",
        VER(NVRAM_EF_UL1_PATHLOSS_BAND5_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS_BAND6_LID,
        NVRAM_EF_UL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL16",
        VER(NVRAM_EF_UL1_PATHLOSS_BAND6_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS_BAND7_LID,
        NVRAM_EF_UL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL17",
        VER(NVRAM_EF_UL1_PATHLOSS_BAND7_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS_BAND8_LID,
        NVRAM_EF_UL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL18",
        VER(NVRAM_EF_UL1_PATHLOSS_BAND8_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS_BAND9_LID,
        NVRAM_EF_UL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL19",
        VER(NVRAM_EF_UL1_PATHLOSS_BAND9_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS_BAND10_LID,
        NVRAM_EF_UL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1A",
        VER(NVRAM_EF_UL1_PATHLOSS_BAND10_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS_BAND11_LID,
        NVRAM_EF_UL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULB0",
        VER(NVRAM_EF_UL1_PATHLOSS_BAND11_LID)
    },

    {
        NVRAM_EF_UL1_PATHLOSS_BAND19_LID,
        NVRAM_EF_UL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULB1",
        VER(NVRAM_EF_UL1_PATHLOSS_BAND19_LID)
    },
    
    {
        NVRAM_EF_UL1_TXDAC_BAND1_LID,
        NVRAM_EF_UL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_UL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1B",
        VER(NVRAM_EF_UL1_TXDAC_BAND1_LID)
    },
    
    {
        NVRAM_EF_UL1_TXDAC_BAND2_LID,
        NVRAM_EF_UL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_UL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1C",
        VER(NVRAM_EF_UL1_TXDAC_BAND2_LID)
    },
    
    {
        NVRAM_EF_UL1_TXDAC_BAND3_LID,
        NVRAM_EF_UL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_UL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1D",
        VER(NVRAM_EF_UL1_TXDAC_BAND3_LID)
    },
    
    {
        NVRAM_EF_UL1_TXDAC_BAND4_LID,
        NVRAM_EF_UL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_UL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1E",
        VER(NVRAM_EF_UL1_TXDAC_BAND4_LID)
    },
    
    {
        NVRAM_EF_UL1_TXDAC_BAND5_LID,
        NVRAM_EF_UL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_UL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1F",
        VER(NVRAM_EF_UL1_TXDAC_BAND5_LID)
    },
    
    {
        NVRAM_EF_UL1_TXDAC_BAND6_LID,
        NVRAM_EF_UL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_UL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1G",
        VER(NVRAM_EF_UL1_TXDAC_BAND6_LID)
    },
    
    {
        NVRAM_EF_UL1_TXDAC_BAND7_LID,
        NVRAM_EF_UL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_UL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1H",
        VER(NVRAM_EF_UL1_TXDAC_BAND7_LID)
    },
    
    {
        NVRAM_EF_UL1_TXDAC_BAND8_LID,
        NVRAM_EF_UL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_UL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1I",
        VER(NVRAM_EF_UL1_TXDAC_BAND8_LID)
    },
    
    {
        NVRAM_EF_UL1_TXDAC_BAND9_LID,
        NVRAM_EF_UL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_UL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1J",
        VER(NVRAM_EF_UL1_TXDAC_BAND9_LID)
    },
    {
        NVRAM_EF_UL1_TXDAC_BAND10_LID,
        NVRAM_EF_UL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_UL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1K",
        VER(NVRAM_EF_UL1_TXDAC_BAND10_LID)
    },
    {
        NVRAM_EF_UL1_TXDAC_BAND11_LID,
        NVRAM_EF_UL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_UL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULB2",
        VER(NVRAM_EF_UL1_TXDAC_BAND11_LID)
    },
    {
        NVRAM_EF_UL1_TXDAC_BAND19_LID,
        NVRAM_EF_UL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_UL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULB3",
        VER(NVRAM_EF_UL1_TXDAC_BAND19_LID)
    },
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
    /* PA 8-level control (for MT6276, MT6573) */
    {
        NVRAM_EF_UL1_TXPAOCTLEV_BAND1_LID,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1M",
        VER(NVRAM_EF_UL1_TXPAOCTLEV_BAND1_LID)
    },
    
    {
        NVRAM_EF_UL1_TXPAOCTLEV_BAND2_LID,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1N",
        VER(NVRAM_EF_UL1_TXPAOCTLEV_BAND2_LID)
    },
    
    {
        NVRAM_EF_UL1_TXPAOCTLEV_BAND3_LID,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1O",
        VER(NVRAM_EF_UL1_TXPAOCTLEV_BAND3_LID)
    },
    
    {
        NVRAM_EF_UL1_TXPAOCTLEV_BAND4_LID,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1P",
        VER(NVRAM_EF_UL1_TXPAOCTLEV_BAND4_LID)
    },
    
    {
        NVRAM_EF_UL1_TXPAOCTLEV_BAND5_LID,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1Q",
        VER(NVRAM_EF_UL1_TXPAOCTLEV_BAND5_LID)
    },
    
    {
        NVRAM_EF_UL1_TXPAOCTLEV_BAND6_LID,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1R",
        VER(NVRAM_EF_UL1_TXPAOCTLEV_BAND6_LID)
    },
    
    {
        NVRAM_EF_UL1_TXPAOCTLEV_BAND7_LID,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1S",
        VER(NVRAM_EF_UL1_TXPAOCTLEV_BAND7_LID)
    },
    
    {
        NVRAM_EF_UL1_TXPAOCTLEV_BAND8_LID,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1T",
        VER(NVRAM_EF_UL1_TXPAOCTLEV_BAND8_LID)
    },
    
    {
        NVRAM_EF_UL1_TXPAOCTLEV_BAND9_LID,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1U",
        VER(NVRAM_EF_UL1_TXPAOCTLEV_BAND9_LID)
    },
    
    {
        NVRAM_EF_UL1_TXPAOCTLEV_BAND10_LID,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1V",
        VER(NVRAM_EF_UL1_TXPAOCTLEV_BAND10_LID)
    },
    
    {
        NVRAM_EF_UL1_TXPAOCTLEV_BAND11_LID,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULB4",
        VER(NVRAM_EF_UL1_TXPAOCTLEV_BAND11_LID)
    },
    
    {
        NVRAM_EF_UL1_TXPAOCTLEV_BAND19_LID,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_UL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULB5",
        VER(NVRAM_EF_UL1_TXPAOCTLEV_BAND19_LID)
    },
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
#endif /* __UMTS_RAT__ && __MTK_UL1_FDD__*/

#if defined(__UMTS_R8__)&&defined(__MTK_UL1_FDD__) //add by Jay
    {
        NVRAM_EF_UL1_PATHLOSS2_BAND1_LID,
        NVRAM_EF_UL1_PATHLOSS2_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS2_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL10",
        VER(NVRAM_EF_UL1_PATHLOSS2_BAND1_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS2_BAND2_LID,
        NVRAM_EF_UL1_PATHLOSS2_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS2_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL11",
        VER(NVRAM_EF_UL1_PATHLOSS2_BAND2_LID)
    },
    {
        NVRAM_EF_UL1_PATHLOSS2_BAND3_LID,
        NVRAM_EF_UL1_PATHLOSS2_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS2_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL12",
        VER(NVRAM_EF_UL1_PATHLOSS2_BAND3_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS2_BAND4_LID,
        NVRAM_EF_UL1_PATHLOSS2_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS2_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL13",
        VER(NVRAM_EF_UL1_PATHLOSS2_BAND4_LID)
    },

    {
        NVRAM_EF_UL1_PATHLOSS2_BAND5_LID,
        NVRAM_EF_UL1_PATHLOSS2_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS2_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL14",
        VER(NVRAM_EF_UL1_PATHLOSS2_BAND5_LID)
    },

    {
        NVRAM_EF_UL1_PATHLOSS2_BAND6_LID,
        NVRAM_EF_UL1_PATHLOSS2_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS2_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL15",
        VER(NVRAM_EF_UL1_PATHLOSS2_BAND6_LID)
    },

    {
        NVRAM_EF_UL1_PATHLOSS2_BAND7_LID,
        NVRAM_EF_UL1_PATHLOSS2_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS2_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL16",
        VER(NVRAM_EF_UL1_PATHLOSS2_BAND7_LID)
    },

    {
        NVRAM_EF_UL1_PATHLOSS2_BAND8_LID,
        NVRAM_EF_UL1_PATHLOSS2_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS2_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL17",
        VER(NVRAM_EF_UL1_PATHLOSS2_BAND8_LID)
    },

    {
        NVRAM_EF_UL1_PATHLOSS2_BAND9_LID,
        NVRAM_EF_UL1_PATHLOSS2_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS2_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL18",
        VER(NVRAM_EF_UL1_PATHLOSS2_BAND9_LID)
    },

    {
        NVRAM_EF_UL1_PATHLOSS2_BAND10_LID,
        NVRAM_EF_UL1_PATHLOSS2_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS2_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL19",
        VER(NVRAM_EF_UL1_PATHLOSS2_BAND10_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS2_BAND11_LID,
        NVRAM_EF_UL1_PATHLOSS2_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS2_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULB6",
        VER(NVRAM_EF_UL1_PATHLOSS2_BAND11_LID)
    },
    
    {
        NVRAM_EF_UL1_PATHLOSS2_BAND19_LID,
        NVRAM_EF_UL1_PATHLOSS2_BAND_TOTAL,
        NVRAM_EF_UL1_PATHLOSS2_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULB7",
        VER(NVRAM_EF_UL1_PATHLOSS2_BAND19_LID)
    },
//add by wilson
    {
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND1_LID,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL1A",//note: only 4 char
        VER(NVRAM_EF_UL1_TXPADRIFTCOMP_BAND1_LID)
    }, 

    {
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND2_LID,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL1B",//note: only 4 char
        VER(NVRAM_EF_UL1_TXPADRIFTCOMP_BAND2_LID)
    },

    {
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND3_LID,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL1C",//note: only 4 char
        VER(NVRAM_EF_UL1_TXPADRIFTCOMP_BAND3_LID)
    },

    {
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND4_LID,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL1D",//note: only 4 char
        VER(NVRAM_EF_UL1_TXPADRIFTCOMP_BAND4_LID)
    }, 

    {
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND5_LID,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL1E",//note: only 4 char
        VER(NVRAM_EF_UL1_TXPADRIFTCOMP_BAND5_LID)
    },

    {
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND6_LID,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL1F",//note: only 4 char
        VER(NVRAM_EF_UL1_TXPADRIFTCOMP_BAND6_LID)
    },

    {
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND7_LID,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL1G",//note: only 4 char
        VER(NVRAM_EF_UL1_TXPADRIFTCOMP_BAND7_LID)
    },

    {
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND8_LID,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL1H",//note: only 4 char
        VER(NVRAM_EF_UL1_TXPADRIFTCOMP_BAND8_LID)
    }, 

    {
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND9_LID,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL1I",//note: only 4 char
        VER(NVRAM_EF_UL1_TXPADRIFTCOMP_BAND9_LID)
    },

    {
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND10_LID,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "HL1J",//note: only 4 char
        VER(NVRAM_EF_UL1_TXPADRIFTCOMP_BAND10_LID)
    },

    {
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND11_LID,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULB8",//note: only 4 char
        VER(NVRAM_EF_UL1_TXPADRIFTCOMP_BAND11_LID)
    },
    
    {
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND19_LID,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPADRIFTCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULB9",//note: only 4 char
        VER(NVRAM_EF_UL1_TXPADRIFTCOMP_BAND19_LID)
    },
    
#endif

#if defined (__MTK_UL1_FDD__)
    /** Tx PRACH TM Compensation */
    {
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND1_LID,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1W",
        VER(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND1_LID)
    },
    
    {
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND2_LID,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1X",
        VER(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND2_LID)
    },

    {
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND3_LID,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1Y",
        VER(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND3_LID)
    },

    {
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND4_LID,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL1Z",
        VER(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND4_LID)
    },

    {
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND5_LID,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL20",
        VER(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND5_LID)
    },

    {
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND6_LID,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL21",
        VER(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND6_LID)
    },

    {
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND7_LID,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL22",
        VER(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND7_LID)
    },

    {
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND8_LID,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL23",
        VER(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND8_LID)
    },

    {
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND9_LID,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL24",
        VER(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND9_LID)
    },

    {
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND10_LID,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "UL25",
        VER(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND10_LID)
    },

    {
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND11_LID,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBA",
        VER(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND11_LID)
    },

    {
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND19_LID,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL,
        NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBB",
        VER(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND19_LID)
    },

    {
        NVRAM_EF_UL1_AFCDAC_LID,
        NVRAM_EF_UL1_AFCDAC_TOTAL,
        NVRAM_EF_UL1_AFCDAC_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBC",//note: only 4 char
        VER(NVRAM_EF_UL1_AFCDAC_LID)
    },

    {
        NVRAM_EF_UL1_AFCCAP_LID,
        NVRAM_EF_UL1_AFCCAP_TOTAL,
        NVRAM_EF_UL1_AFCCAP_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBD",//note: only 4 char
        VER(NVRAM_EF_UL1_AFCCAP_LID)
    },

#if defined(__TX_POWER_OFFSET_SUPPORT__)
    {
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND1_LID,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBE",
        VER(NVRAM_EF_UL1_TXPOWEROFFSET_BAND1_LID)
    },

    {
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND2_LID,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBF",
        VER(NVRAM_EF_UL1_TXPOWEROFFSET_BAND2_LID)
    },

    {   
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND3_LID,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBG",
        VER(NVRAM_EF_UL1_TXPOWEROFFSET_BAND3_LID)
    },

    {
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND4_LID,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBH",
        VER(NVRAM_EF_UL1_TXPOWEROFFSET_BAND4_LID)
    },

    {
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND5_LID,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBI",
        VER(NVRAM_EF_UL1_TXPOWEROFFSET_BAND5_LID)
    },

    {
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND6_LID,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBJ",
        VER(NVRAM_EF_UL1_TXPOWEROFFSET_BAND6_LID)
    },

    {
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND7_LID,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBK",
        VER(NVRAM_EF_UL1_TXPOWEROFFSET_BAND7_LID)
    },

    {
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND8_LID,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBL",
        VER(NVRAM_EF_UL1_TXPOWEROFFSET_BAND8_LID)
    },

    {
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND9_LID,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBM",
        VER(NVRAM_EF_UL1_TXPOWEROFFSET_BAND9_LID)
    },

    {
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND10_LID,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBN",
        VER(NVRAM_EF_UL1_TXPOWEROFFSET_BAND10_LID)
    },

    {
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND11_LID,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBO",
        VER(NVRAM_EF_UL1_TXPOWEROFFSET_BAND11_LID)
    },

    {
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND19_LID,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL,
        NVRAM_EF_UL1_TXPOWEROFFSET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "ULBP",
        VER(NVRAM_EF_UL1_TXPOWEROFFSET_BAND19_LID)
    },
#endif /* __TX_POWER_OFFSET_SUPPORT__ */

#endif // (__MTK_UL1_FDD__)

#ifdef  __BTMODULE_MT6601__
    {
        NVRAM_EF_BTRADIO_MT6601_LID,
        NVRAM_EF_BTRADIO_MT6601_TOTAL,
        NVRAM_EF_BTRADIO_MT6601_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BTRADIO_MT6601_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_AVERAGE,
        "MT1H",
        VER(NVRAM_EF_BTRADIO_MT6601_LID)
    },
#endif

#ifdef  __BTMODULE_MT6611__
    {
        NVRAM_EF_BTRADIO_MT6611_LID,
        NVRAM_EF_BTRADIO_MT6611_TOTAL,
        NVRAM_EF_BTRADIO_MT6611_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BTRADIO_MT6611_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_AVERAGE,
        "MT1I",
        VER(NVRAM_EF_BTRADIO_MT6611_LID)
    },
#endif


#if defined(__WIFI_SUPPORT__)&&(__CUSTOM_WIFI_FEATURES_SWITCH__)
    {
        NVRAM_EF_WNDRV_MAC_ADDRESS_LID,
        NVRAM_EF_WNDRV_MAC_ADDRESS_TOTAL,
        NVRAM_EF_WNDRV_MAC_ADDRESS_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_default_mac_addr),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT1M",
        VER(NVRAM_EF_WNDRV_MAC_ADDRESS_LID)
    },
    
    {
        NVRAM_EF_WNDRV_TX_POWER_2400M_LID,
        NVRAM_EF_WNDRV_TX_POWER_2400M_TOTAL,
        NVRAM_EF_WNDRV_TX_POWER_2400M_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_default_txpwr_2400M),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT1N",
        VER(NVRAM_EF_WNDRV_TX_POWER_2400M_LID)
    },
    
    {
        NVRAM_EF_WNDRV_TX_POWER_5000M_LID,
        NVRAM_EF_WNDRV_TX_POWER_5000M_TOTAL,
        NVRAM_EF_WNDRV_TX_POWER_5000M_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_default_txpwr_5000M),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT1O",
        VER(NVRAM_EF_WNDRV_TX_POWER_5000M_LID)
    },
    
    {
        NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID,
        NVRAM_EF_WNDRV_DAC_DC_OFFSET_TOTAL,
        NVRAM_EF_WNDRV_DAC_DC_OFFSET_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_default_dac_dc_offset),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT1P",
        VER(NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID)
    },
    
    {
        NVRAM_EF_WNDRV_TX_ALC_POWER_LID,
        NVRAM_EF_WNDRV_TX_ALC_POWER_TOTAL,
        NVRAM_EF_WNDRV_TX_ALC_POWER_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_default_tx_ALC_pwr),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT1Q",
        VER(NVRAM_EF_WNDRV_TX_ALC_POWER_LID)
    },
    
    {
        NVRAM_EF_WNDRV_EXT_SETTING_TRIMVAL_THERMOVAL_LID,
        NVRAM_EF_WNDRV_EXT_SETTING_TRIMVAL_THERMOVAL_TOTAL,
        NVRAM_EF_WNDRV_EXT_SETTING_TRIMVAL_THERMOVAL_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_cal_setting_trim_thermo),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT1R",
        VER(NVRAM_EF_WNDRV_EXT_SETTING_TRIMVAL_THERMOVAL_LID)
    },
    
    {
        NVRAM_EF_WNDRV_ALC_SLOPE_LID,
        NVRAM_EF_WNDRV_ALC_SLOPE_TOTAL,
        NVRAM_EF_WNDRV_ALC_SLOPE_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_default_ALC_Slope),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT1S",
        VER(NVRAM_EF_WNDRV_ALC_SLOPE_LID)
    },
//CYLEN: ??    
    {
        NVRAM_EF_WNDRV_TPCFF_LID,
        NVRAM_EF_WNDRV_TPCFF_TOTAL,
        NVRAM_EF_WNDRV_TPCFF_SIZE,
        NVRAM_NORMAL_NOT_GEN(&wndrv_default_TPCFF),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE,
        "MT1T",
        VER(NVRAM_EF_WNDRV_TPCFF_LID)
    },
#endif /*__WIFI_SUPPORT__*/

#ifdef __AST_TL1_TDD__
    {
        NVRAM_EF_AST_TL1_TEMP_DAC_LID,
        NVRAM_EF_AST_TL1_TEMP_DAC_TOTAL,
        NVRAM_EF_AST_TL1_TEMP_DAC_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT2A",
        VER(NVRAM_EF_AST_TL1_TEMP_DAC_LID)
    },
    
    {
        NVRAM_EF_AST_TL1_AFC_DATA_LID,
        NVRAM_EF_AST_TL1_AFC_DATA_TOTAL,
        NVRAM_EF_AST_TL1_AFC_DATA_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_AFC_DATA_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT2B",
        VER(NVRAM_EF_AST_TL1_AFC_DATA_LID)
    },

    {
        NVRAM_EF_AST_TL1_PATHLOSS_BAND33_35_37_39_LID,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_PATHLOSS_33_35_37_39_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT2C",
        VER(NVRAM_EF_AST_TL1_PATHLOSS_BAND33_35_37_39_LID)
    },

    {
        NVRAM_EF_AST_TL1_PATHLOSS_BAND34_LID,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_PATHLOSS_34_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT2D",
        VER(NVRAM_EF_AST_TL1_PATHLOSS_BAND34_LID)
    },

    {
        NVRAM_EF_AST_TL1_PATHLOSS_BAND36_LID,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT2E",
        VER(NVRAM_EF_AST_TL1_PATHLOSS_BAND36_LID)
    },

    {
        NVRAM_EF_AST_TL1_PATHLOSS_BAND38_LID,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT2F",
        VER(NVRAM_EF_AST_TL1_PATHLOSS_BAND38_LID)
    },

    {
        NVRAM_EF_AST_TL1_PATHLOSS_BAND40_LID,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_TOTAL,
        NVRAM_EF_AST_TL1_PATHLOSS_BAND_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT2G",
        VER(NVRAM_EF_AST_TL1_PATHLOSS_BAND40_LID)
    },

    {
        NVRAM_EF_AST_TL1_TXDAC_BAND33_35_37_39_LID,
        NVRAM_EF_AST_TL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_AST_TL1_TXDAC_BAND_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_TXDAC_33_35_37_39_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT2H",
        VER(NVRAM_EF_AST_TL1_TXDAC_BAND33_35_37_39_LID)
    },

     {
        NVRAM_EF_AST_TL1_TXDAC_BAND34_LID,
        NVRAM_EF_AST_TL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_AST_TL1_TXDAC_BAND_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_TXDAC_34_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT2I",
        VER(NVRAM_EF_AST_TL1_TXDAC_BAND34_LID)
    },
    
    {
        NVRAM_EF_AST_TL1_TXDAC_BAND36_LID,
        NVRAM_EF_AST_TL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_AST_TL1_TXDAC_BAND_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT2J",
        VER(NVRAM_EF_AST_TL1_TXDAC_BAND36_LID)
    },
    
    {
        NVRAM_EF_AST_TL1_TXDAC_BAND38_LID,
        NVRAM_EF_AST_TL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_AST_TL1_TXDAC_BAND_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT2K",
        VER(NVRAM_EF_AST_TL1_TXDAC_BAND38_LID)
    },
    
    {
        NVRAM_EF_AST_TL1_TXDAC_BAND40_LID,
        NVRAM_EF_AST_TL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_AST_TL1_TXDAC_BAND_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_TXDAC_40_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MT2L",
        VER(NVRAM_EF_AST_TL1_TXDAC_BAND40_LID)
    },
//CYLEN??    
    {
        NVRAM_EF_AST_TL1_ABB_CAL_LID,
        NVRAM_EF_AST_TL1_ABB_CAL_TOTAL,
        NVRAM_EF_AST_TL1_ABB_CAL_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_ABB_CAL_DEFAULT),
        NVRAM_CATEGORY_USER, /// this is auto calibrated in first time mcu power on (or the data loss case), don't need backup & restore
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT2P", // be very careful, MT2M, MT2N, MT2O is used by RF calibration history in MAUI, 10A branch
        VER(NVRAM_EF_AST_TL1_ABB_CAL_LID)
    },
    {
        NVRAM_EF_AST_TL1_TXCLPC_BAND34_LID,
        NVRAM_EF_AST_TL1_TXCLPC_BAND_TOTAL,
        NVRAM_EF_AST_TL1_TXCLPC_BAND_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_TXCLPC_34_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT2W", // be very careful, MT2M, MT2N, MT2O is used by RF calibration history in MAUI, 10A branch
        VER(NVRAM_EF_AST_TL1_TXCLPC_BAND34_LID)
    },

	{
        NVRAM_EF_AST_TL1_TXCLPC_BAND33_35_37_39_LID,
        NVRAM_EF_AST_TL1_TXCLPC_BAND_TOTAL,
        NVRAM_EF_AST_TL1_TXCLPC_BAND_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_TXCLPC_33_35_37_39_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT2X", // be very careful, MT2M, MT2N, MT2O is used by RF calibration history in MAUI, 10A branch
        VER(NVRAM_EF_AST_TL1_TXCLPC_BAND33_35_37_39_LID)
    },

	{
		NVRAM_EF_AST_TL1_TXCLPC_BAND36_LID,
		NVRAM_EF_AST_TL1_TXCLPC_BAND_TOTAL,
		NVRAM_EF_AST_TL1_TXCLPC_BAND_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_CALIBRAT,
		NVRAM_ATTR_MULTIPLE,
		"MT2Y",
		VER(NVRAM_EF_AST_TL1_TXCLPC_BAND36_LID)
	},

	{
		NVRAM_EF_AST_TL1_TXCLPC_BAND38_LID,
		NVRAM_EF_AST_TL1_TXCLPC_BAND_TOTAL,
		NVRAM_EF_AST_TL1_TXCLPC_BAND_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_CALIBRAT,
		NVRAM_ATTR_MULTIPLE,
		"MT2Z",
		VER(NVRAM_EF_AST_TL1_TXCLPC_BAND38_LID)
    },
		
	{
        NVRAM_EF_AST_TL1_TXCLPC_BAND40_LID,
        NVRAM_EF_AST_TL1_TXCLPC_BAND_TOTAL,
        NVRAM_EF_AST_TL1_TXCLPC_BAND_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_TXCLPC_40_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MU0A", // be very careful, MT2M, MT2N, MT2O is used by RF calibration history in MAUI, 10A branch
        VER(NVRAM_EF_AST_TL1_TXCLPC_BAND40_LID)
    },
#endif // __AST_TL1_TDD__
// RF Calibration history NVRAM items
#ifdef __TC01__
    {
        NVRAM_EF_RF_CAL_ENV_LID,
        NVRAM_EF_RF_CAL_ENV_TOTAL,
        NVRAM_EF_RF_CAL_ENV_SIZE,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MT2M",
        VER(NVRAM_EF_RF_CAL_ENV_LID)
    },
    
    {
        NVRAM_EF_RF_CAL_LOSS_SETTING_LID,
        NVRAM_EF_RF_CAL_LOSS_SETTING_TOTAL,
        NVRAM_EF_RF_CAL_LOSS_SETTING_SIZE,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MT2N",
        VER(NVRAM_EF_RF_CAL_LOSS_SETTING_LID)
    },
    
    {
        NVRAM_EF_RF_TEST_POWER_RESULT_LID,
        NVRAM_EF_RF_TEST_POWER_RESULT_TOTAL,
        NVRAM_EF_RF_TEST_POWER_RESULT_SIZE,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MT2O",
        VER(NVRAM_EF_RF_TEST_POWER_RESULT_LID)
    },
#endif  /* __TC01__ */



    {
        NVRAM_EF_BARCODE_NUM_LID,
        NVRAM_EF_BARCODE_NUM_TOTAL,
        NVRAM_EF_BARCODE_NUM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_CONFIDENTIAL,
        "MP09", /* keep the file prefix as the same with legacy branches in BKRS/sw upgrade */
        VER(NVRAM_EF_BARCODE_NUM_LID)
    },
    
    {
        NVRAM_EF_CAL_FLAG_LID,
        NVRAM_EF_CAL_FLAG_TOTAL,
        NVRAM_EF_CAL_FLAG_SIZE,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MPA2", /* keep the file prefix as the same with legacy branches in BKRS/sw upgrade */
        VER(NVRAM_EF_CAL_FLAG_LID)
    },
    
    {
        NVRAM_EF_CAL_DATA_CHECK_LID,
        NVRAM_EF_CAL_DATA_CHECK_TOTAL,
        NVRAM_EF_CAL_DATA_CHECK_SIZE,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE,
        "MPA8", /* keep the file prefix as the same with legacy branches in BKRS/sw upgrade */
        VER(NVRAM_EF_CAL_DATA_CHECK_LID)
    },


    {
        NVRAM_EF_IMEI_IMEISV_LID,
        NVRAM_EF_IMEI_IMEISV_TOTAL,
        NVRAM_EF_IMEI_IMEISV_SIZE,
	#if defined(__IC_SLT__)
	NVRAM_NORMAL(NVRAM_EF_IMEI_DEFAULT),
	#else
	NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
	#endif

    #ifdef __NVRAM_OTP__
        NVRAM_CATEGORY_OTP | NVRAM_CATEGORY_IMPORTANT,
    #elif defined(__NVRAM_CUSTOM_DISK__)
        NVRAM_CATEGORY_CUSTOM_DISK,
    #else
        NVRAM_CATEGORY_IMPORTANT,
    #endif

    #if defined(__NVRAM_OTP__) || defined(__NVRAM_CUSTOM_DISK__)
        NVRAM_ATTR_AVERAGE,
    #else
        NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL,
    #endif
        "MP0B",
        VER(NVRAM_EF_IMEI_IMEISV_LID)
    },

    {
        NVRAM_EF_SML_LID,
        NVRAM_EF_SML_TOTAL,
        NVRAM_EF_SML_SIZE,
        NVRAM_SECUPACK(&NVRAM_EF_SML_DEFAULT),
    #ifdef __SMART_PHONE_MODEM__
        NVRAM_CATEGORY_SECUPACK | NVRAM_CATEGORY_IMPORTANT_L4,
    #elif defined(__CUSTOMER_TC01_DISK__) && !defined(WISDOM_MMI)
        NVRAM_CATEGORY_SECUPACK,
    #else
        NVRAM_CATEGORY_SECUPACK | NVRAM_CATEGORY_IMPORTANT,
    #endif
        NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
        "MP33",
        VER(NVRAM_EF_SML_LID)
    },

#ifdef __SMART_PHONE_MODEM__
    {
        NVRAM_EF_SIM_LOCK_LID,
        NVRAM_EF_SIM_LOCK_TOTAL,
        NVRAM_EF_SIM_LOCK_SIZE,
        NVRAM_SECUPACK(&NVRAM_EF_SML_TMO_DEFAULT),
        NVRAM_CATEGORY_SECUPACK | NVRAM_CATEGORY_IMPORTANT_L4,
        NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
        "MP6T",
        VER(NVRAM_EF_SIM_LOCK_LID)
    },
#endif


#if defined(__BTMODULE_MT6612__) || defined(__BTMODULE_MT6616__) || defined(__BTMODULE_MT6622__) || defined(__BTMODULE_MT6626__) || defined(__BTMODULE_MT6236__) || defined(__BTMODULE_MT6256__) || defined(__BTMODULE_MT6276__) || defined(__BTMODULE_MT6255__)
    {
        NVRAM_EF_BTRADIO_MTK_BT_CHIP_LID,
        NVRAM_EF_BTRADIO_MTK_BT_CHIP_TOTAL,
        NVRAM_EF_BTRADIO_MTK_BT_CHIP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BTRADIO_MTK_BT_CHIP_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_AVERAGE,
        "MT6Y",
        VER(NVRAM_EF_BTRADIO_MTK_BT_CHIP_LID)
    },
#endif
#if defined(__AST_TL1_TDD__)
#if !defined(__AST1001__) && !defined(__AST2001__)
    {
        NVRAM_EF_AST_TL1_CAP_DATA_LID,
        NVRAM_EF_AST_TL1_CAP_DATA_TOTAL,
        NVRAM_EF_AST_TL1_CAP_DATA_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AST_TL1_CAP_DATA_DEFAULT),
        NVRAM_CATEGORY_CALIBRAT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT6Z",
        VER(NVRAM_EF_AST_TL1_CAP_DATA_LID)
    },
#endif // #if !defined(__AST1001__) && !defined(__AST2001__)
#endif // #if defined(__AST_TL1_TDD__)
};

#endif /* NVRAM_NOT_PRESENT */
