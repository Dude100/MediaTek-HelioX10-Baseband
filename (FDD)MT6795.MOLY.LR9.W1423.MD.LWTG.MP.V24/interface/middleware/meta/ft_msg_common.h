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
/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_msg_common.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Common definition for META commnuication
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *==============================================================================
 *******************************************************************************/

#ifndef _FT_MSG_COMMON_H_
#define _FT_MSG_COMMON_H_
#include "kal_public_api.h"
typedef enum
{
  /* RF */
  FT_RF_TEST_REQ_ID = 0                       ,/*0*/
  FT_RF_TEST_CNF_ID                           ,
  /* BaseBand */
  FT_REG_READ_ID                              ,
  FT_REG_READ_CNF_ID                          ,
  FT_REG_WRITE_ID                             ,
  FT_REG_WRITE_CNF_ID                         ,/*5*/
  FT_ADC_GETMEADATA_ID                        ,
  FT_ADC_GETMEADATA_CNF_ID                    ,
  /* test alive */
  FT_IS_ALIVE_REQ_ID                          ,
  FT_IS_ALIVE_CNF_ID                          ,
  /* power off */
  FT_POWER_OFF_REQ_ID                         ,/*10*/
  /* unused */
  FT_RESERVED04_ID                            ,
  /* required META_DLL version */
  FT_CHECK_META_VER_REQ_ID                    ,
  FT_CHECK_META_VER_CNF_ID                    ,
  /* utility command */
  FT_UTILITY_COMMAND_REQ_ID                   ,
  FT_UTILITY_COMMAND_CNF_ID                   ,/*15*/
  /* for NVRAM */
  FT_NVRAM_GET_DISK_INFO_REQ_ID               ,
  FT_NVRAM_GET_DISK_INFO_CNF_ID               ,
  FT_NVRAM_RESET_REQ_ID                       ,
  FT_NVRAM_RESET_CNF_ID                       ,
  FT_NVRAM_LOCK_CNF_ID                        ,/*20*/
  FT_NVRAM_LOCK_REQ_ID                        ,
  FT_NVRAM_READ_REQ_ID                        ,
  FT_NVRAM_READ_CNF_ID                        ,
  FT_NVRAM_WRITE_REQ_ID                       ,
  FT_NVRAM_WRITE_CNF_ID                       ,/*25*/
  /* FAT */
  FT_FAT_OPERATION_ID = 26                    ,/* 26 ~ 40 */
  /* L4 Audio */
  FT_L4AUD_REQ_ID = 41                        ,/* 41 ~ 50 */
  FT_L4AUD_CNF_ID                             ,
  /* Version Info */
  FT_VER_INFO_REQ_ID = 51                     ,/* 51 */
  FT_VER_INFO_CNF_ID                          ,
  /* CCT */
  FT_CCT_REQ_ID = 53                          ,/* 53 */
  FT_CCT_CNF_ID                               ,
  /* WiFi */
  FT_WIFI_WNDRV_SET_REQ_ID = 55               ,/* 55 */
  FT_WIFI_WNDRV_SET_CNF_ID                    ,
  FT_WIFI_WNDRV_QUERY_REQ_ID = 57             ,/* 57 */
  FT_WIFI_WNDRV_QUERY_CNF_ID                  ,
  FT_WIFI_REQ_ID = 59                         ,/* 59 */
  FT_WIFI_CNF_ID                              ,
  FT_BT_REQ_ID = 61                           ,
  FT_BT_CNF_ID                                ,
  FT_PMIC_REG_READ_ID = 63            ,
  FT_PMIC_REG_READ_CNF_ID             ,
  FT_PMIC_REG_WRITE_ID = 65           ,
  FT_PMIC_REG_WRITE_CNF_ID                ,
  FT_URF_TEST_REQ_ID = 67                   ,   /* 67 */
  FT_URF_TEST_CNF_ID                  ,
  FT_FM_REQ_ID = 69                          ,   /* 69 */
  FT_FM_CNF_ID = 70                          ,
  FT_TDMB_REQ_ID = 71                , /* 71 */
  FT_TDMB_CNF_ID = 72                , /* 72 */
  FT_MISC_CMD_REQ_ID = 73            ,
  FT_MISC_CMD_CNF_ID = 74            ,
  FT_CMMB_REQ_ID = 75                ,
  FT_CMMB_CNF_ID = 76                ,
  FT_CUSTOM_REQ_ID = 77              ,
  FT_CUSTOM_CNF_ID = 78              ,
  FT_MISC_EX_CMD_REQ_ID = 79            ,
  FT_MISC_EX_CMD_CNF_ID = 80            ,
  FT_AUX_REQ_ID = 81                 ,
  FT_AUX_CNF_ID = 82                 ,
  FT_MATV_CMD_REQ_ID = 83            ,
  FT_MATV_CMD_CNF_ID = 84            ,
   /* L4 Audio EX after all audio developed in w10.10 */
  FT_L4AUD_REQ_EX_ID = 85                  ,
  FT_L4AUD_CNF_EX_ID = 86                   ,
  /* NFC test command category */
  FT_NFC_CMD_REQ_ID = 87,
  FT_NFC_CMD_CNF_ID = 88,
  /* LTE command */
  FT_ERF_TEST_REQ_ID = 91,
  FT_ERF_TEST_CNF_ID = 92,
  FT_PHY_TOOL_REQ_ID = 93,
  FT_PHY_TOOL_CNF_ID = 94,
  
  /* This is a special message defined to handle L1 report. */
  FT_DISPATCH_REPORT_ID                       ,
  FT_MSG_LAST_ID   =  FT_DISPATCH_REPORT_ID
}FT_MESSAGE_ID;

/* Header of every structure */
typedef struct
{
   LOCAL_PARA_HDR
   kal_uint16        token;
   kal_uint16        ft_msg_id;
}FT_H;
#define FT_CNF_OK   0
#define FT_CNF_FAIL 1
#define FT_CNF_NOT_SUPPORTED 2
/*******************************************************************************
*
*  Utility Functions
*
*******************************************************************************/
void _FT_ALLOC_MSG(ilm_struct* ptr_ilm, kal_uint16 size, kal_bool  IsFtMsg);
void _FT_SendFtMsgByToken(module_type  src_mod, module_type  dest_mod, sap_type  sap, msg_type  msg, ilm_struct  *ilm_ptr, kal_uint16  token);
void _FT_SendFtMsgToPcByToken(ilm_struct  *ilm_ptr, kal_uint16  token);
kal_uint16   FT_GetGolbalToken(void);
#define FT_ALLOC_MSG(ptr_ilm,size)          _FT_ALLOC_MSG(ptr_ilm, size, KAL_TRUE)
#define FT_ALLOC_OTHER_MSG(ptr_ilm,size)    _FT_ALLOC_MSG(ptr_ilm, size, KAL_FALSE)
#define FT_SEND_MSG(src_mod, dest_mod, sap, msg, ilm_ptr)   _FT_SendFtMsgByToken(src_mod, dest_mod, sap, msg, ilm_ptr, FT_GetGolbalToken())
#define FT_SEND_MSG_TO_PC(ilm_ptr)                          _FT_SendFtMsgToPcByToken(ilm_ptr, FT_GetGolbalToken())
#define FT_SEND_MSG_TO_PC_BY_TOKEN(ilm_ptr, token)          _FT_SendFtMsgToPcByToken(ilm_ptr, token)
#endif // _FT_MSG_COMMON_H_
