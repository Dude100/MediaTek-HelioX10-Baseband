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
 *   bl_main.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   This file defines the major procedure of bootloader
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
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
 * removed!
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"   
#include "kal_public_api.h" 
#include "sw_types.h"
#include "bl_BootInfo.h"
#include "bl_INIT.H"
#include "bl_loader.h"
#include "bl_common.h"
#include "bl_features.h"
#include "bl_custom.h"
#include "bl_setting.h"
#include "bl_sectiondef.h"
#include "bl_MTK_BB_REG.h"

#include "SST_secure.h"
#include "feature_def.h"
#include <string.h>

#include "br_time_stamp.h"
#ifdef __TIME_STAMP__
#include "br_time_stamp_cb.h"
#include "bl_time_stamp_id.h"
#endif

#include "br_GFH_file_info.h"
#include "br_header_block.h"
#include "bl_GFH_body.h"

#if defined __NAND_FDM_50__   
#include "NAND_DAL_Version.h"
#endif /*  __NAND_FDM_50__ */

#include "config_hw.h"

#include "bl_share_param.h"
#include "bl_UART_SW.H"
#include "bl_wdt.h"
#include "bl_cfgctl.h"
#include "bl_trc_api.h"
#include "bl_GPT.h"
#include "bl_drv_common.h"

#ifdef __USB_DOWNLOAD__
#include "bl_usb.h" 
#endif /*__USB_DOWNLOAD__*/

#ifdef __EXT_BOOTLOADER__
#include "drv_boot_init.h"
#endif /* __EXT_BOOTLOADER__ */

/*************************************************************************
 * Macro and const definition
 *************************************************************************/
//Note that these value cannot be adjusted without discussing with Tool team
#ifndef __N_PLUS_0_PROJECT__
#define BL_DA_SHARED_DATA_MAX_SIZE  (32*1024)
#else
#define BL_DA_SHARED_DATA_MAX_SIZE  (4*1024)
#endif
#define BL_DA_SHARED_DATA_ID        "_BL_DA_SHARED_DATA_"
#define MINI_EXT_SHARED_DATA_ID     "_MINI_EXT_SHR_DATA_"

//ID for share data items
#define MINI_EXT_SHARD_FEATURE_COMBINATION                  0x1000
#define MINI_EXT_SHARD_FEATURE_COMBINATION_EXT          0x1001
#define MINI_EXT_SHARD_RANDOM_SEED                                  0x1002
#define MINI_EXT_SHARD_BL_PARAM                                         0x1003
#define MINI_EXT_SHARE_BL_HEADER                                        0x1004
#define MINI_EXT_SHARE_BL_TOKEN                                          0x1005
#define MINI_EXT_SHARE_BL_TIME_STAMP_RECORD                 0x1006
#define MINI_EXT_SHARE_EMI_PARAM                                       0x1007
#define MINI_EXT_SHARE_EXT_BL_UPDATE_INFO                     0x1008
#define MINI_EXT_SHARE_USBDL_RETN                                     0x1009
#define MINI_EXT_SHARE_IMGPARAM                                         0x1010
#define MINI_EXT_SHARE_SCTRL_CERT                                      0x1011
#define MINI_EXT_SHARE_SCTRL_CERT_FLAG                            0x1012
#define MINI_EXT_SHARE_MEID                                                  0x1013
#define MINI_EXT_SHARE_CHANNEL_TYPE                                 0x1014
#define MINI_EXT_SHARE_USB_PID                                            0x1015
#define MINI_EXT_SHARE_USB_VID                                            0x1016

#define TLV_SIZE_RECORD 0

#define BROM_USBDL_V2_TIMEOUT  (30)

/*************************************************************************
 * Structure definition
 *************************************************************************/

typedef struct
{
   kal_char       m_blDaSharedDataId[32];
   kal_uint32     m_payloadLength;
   kal_uint32     m_payload[3];
} BL_DA_SHARED_DATA_HEADER;

typedef struct
{
   kal_uint32     m_type;
   kal_uint32     m_length;
} BL_DA_SHARED_DATA_STRUCT;

typedef enum
{
   USBDL_NOT_TRIGGERED     = 0x00,
   USBDL_RESCUE_KEY,
   USBDL_KEY,
   USBDL_GPIO,
   USBDL_FLAG,
   USBDL_AUTO              = 0x81,
} USBDL_TRIGGER_REASON;
 
/*************************************************************************
 * External reference definition
 *************************************************************************/

extern void bl_BringUpAP();
extern void Connect_FactoryTool(void);
extern kal_uint32 custom_ROM_baseaddr(void);
extern kal_uint32 SST_Get_Secinfo(kal_uint32 rom_base, kal_bool check_mac);

extern void NorFlashBooting(void);
extern void InitRegionsExt(void);
extern void CacheDeinit(void);
extern void CacheInit(void);
extern BL_STATUS InitExt(void);
extern void GetFeatureCombination(void);
extern kal_bool CheckPairedVersion(void);
extern kal_bool USBDLKey_Pressed(void);
extern kal_uint32 custom_get_bootloader_version(kal_uint8 *version, kal_uint32 len);

#if defined(__IC_SLT_LOADER__)
extern __interncode__ kal_uint32 LoadAndVerifySLTBinary(kal_bool *pDoRemap);
#endif

#ifdef __TIME_STAMP__
extern void TS_DumpTimeStamps(void);
#endif

extern kal_uint32 g_Bl_Secure_Test;
extern const LOG_LEVEL bootloader_debug_level;

/*************************************************************************
 * Forward declearaion
 *************************************************************************/
void SetRetnFlag(kal_uint32 flag);
void ClrRetnFlag(kal_uint32 flag);
void SetRetnTimeout(kal_uint32 time);
void ClearUSBDLFlag(void);
void RestoreUSBDLFlag(void);
USBDL_TRIGGER_REASON USBDL_Detect(void);
kal_bool bl_Init_BL_DA_SharedData();
void SetBootupFlag(kal_uint32 flag);
kal_uint32* bl_Allocate_BL_DA_SharedData(kal_uint32 type, kal_uint32 size);

/*************************************************************************
 * Global variables definition
 *************************************************************************/

kal_uint32 g_mauiFeatureCombination = 0;
kal_uint32 g_randomSeed = 0;
kal_bool   g_bromCmdModeDisabled = KAL_FALSE;
kal_uint8  g_emi_param[2] = {0};

//Flag to control the flow
kal_uint32 g_bootupStatus   = BL_BOOTUP_FAIL_REASON_NONE;
kal_bool   g_bootupDisabled = KAL_FALSE;
kal_bool   g_usbdlDisabled  = KAL_FALSE;

kal_uint32 g_usbdlRetnValue = 0xffffffff;   //Must use RW

__zero_init__ __mini_ext_da_share__ kal_uint32 g_mini_ext_da_share_buf[BL_DA_SHARED_DATA_MAX_SIZE/4];


/*************************************************************************
 * Main code
 *************************************************************************/

/**********************************************************
Description : Facility for BL-DA shared data, initialize structure
Input       : 
Output      : 
***********************************************************/
kal_bool bl_Init_TLV_Service(kal_uint32 buffAddr, kal_uint32 buffSize, const kal_char *pId)
{
   BL_DA_SHARED_DATA_HEADER *pSharedData = (BL_DA_SHARED_DATA_HEADER*)buffAddr;

   ASSERT(buffSize > sizeof(BL_DA_SHARED_DATA_HEADER));

   memset(pSharedData->m_blDaSharedDataId, 0, sizeof(pSharedData->m_blDaSharedDataId));
   strcpy(pSharedData->m_blDaSharedDataId, pId);
   pSharedData->m_payload[0] = TLV_SIZE_RECORD;
   pSharedData->m_payload[1] = 4;
   pSharedData->m_payload[2] = buffSize;
   pSharedData->m_payloadLength = sizeof(pSharedData->m_payload);
   
   return KAL_TRUE;
}

kal_uint32* bl_Traverse_TLV_Record(kal_uint32 buffAddr, kal_uint32 *it, kal_uint32 *pType, kal_uint32 *pSize)
{
   BL_DA_SHARED_DATA_HEADER *pSharedDataHeader = (BL_DA_SHARED_DATA_HEADER*)buffAddr;
   BL_DA_SHARED_DATA_STRUCT *pSharedData;

   if(*it == 0)
   {
      *it = (kal_uint32)pSharedDataHeader->m_payload;
   }

   pSharedData = (BL_DA_SHARED_DATA_STRUCT*)(*it + sizeof(BL_DA_SHARED_DATA_STRUCT) + ((BL_DA_SHARED_DATA_STRUCT*)*it)->m_length);

   if((kal_uint32)pSharedData - (kal_uint32)pSharedDataHeader->m_payload < pSharedDataHeader->m_payloadLength)
   {
      if(pType)
      {
         *pType = pSharedData->m_type;
      }
      if(pSize)
      {
         *pSize = pSharedData->m_length;
      }

      *it = (kal_uint32)pSharedData;

      return (kal_uint32*)(pSharedData+1);
   }

   return NULL;
}

kal_uint32* bl_Get_TLV_Record(kal_uint32 buffAddr, kal_uint32 type, kal_uint32 *pSize)
{
   BL_DA_SHARED_DATA_HEADER *pSharedDataHeader = (BL_DA_SHARED_DATA_HEADER*)buffAddr;
   BL_DA_SHARED_DATA_STRUCT *pSharedData;

   kal_uint32 n;

   ASSERT(pSharedDataHeader->m_payload[0] == TLV_SIZE_RECORD && pSharedDataHeader->m_payload[1] == 4);

   n = 3;
   while(n<pSharedDataHeader->m_payloadLength)
   {
      pSharedData = (BL_DA_SHARED_DATA_STRUCT*)((kal_uint32)(&pSharedDataHeader->m_payload) + n);

      if(pSharedData->m_type == type)
   {
         if(pSize)
   {
            *pSize = pSharedData->m_length;
   }   
         return (kal_uint32*)(pSharedData+1);
   }   

      n += pSharedData->m_length + sizeof(BL_DA_SHARED_DATA_STRUCT);
   }   

   return NULL;
}

/**********************************************************
Description : Facility for BL-DA shared data, allocate a new space
Input       : id of the requested record, and size of it
Output      : the pointer to the buffer for record
***********************************************************/
kal_uint32* bl_Allocate_TLV_Record(kal_uint32 buffAddr, kal_uint32 type, kal_uint32 size)
{
   BL_DA_SHARED_DATA_HEADER *pSharedDataHeader = (BL_DA_SHARED_DATA_HEADER*)buffAddr;
   BL_DA_SHARED_DATA_STRUCT *pSharedData;

   kal_uint32 tlvLen = pSharedDataHeader->m_payload[2];

   ASSERT(type != TLV_SIZE_RECORD);

   //Align to 4B
   size = ((size+3)>>2)<<2;

   if(pSharedDataHeader->m_payloadLength + (size + sizeof(BL_DA_SHARED_DATA_STRUCT)) > tlvLen)
   {
      return NULL;
         }
         
   pSharedData = (BL_DA_SHARED_DATA_STRUCT*)(&pSharedDataHeader->m_payload[pSharedDataHeader->m_payloadLength/4]);
   pSharedData->m_type   = type;
   pSharedData->m_length = size;
   
   pSharedDataHeader->m_payloadLength += (size + sizeof(BL_DA_SHARED_DATA_STRUCT));

   return (kal_uint32*)(pSharedData+1);
}


/**********************************************************
Description : Facility for BL-DA shared data, initialize structure
Input       : 
Output      : 
***********************************************************/
kal_bool bl_Init_MINI_EXT_SharedData(void)
{
   return bl_Init_TLV_Service((kal_uint32)g_mini_ext_da_share_buf, sizeof(g_mini_ext_da_share_buf), MINI_EXT_SHARED_DATA_ID);
}

/**********************************************************
Description : Facility for BL-DA shared data, allocate a new space
Input       : id of the requested record, and size of it
Output      : the pointer to the buffer for record
***********************************************************/
kal_uint32* bl_Allocate_MINI_EXT_SharedData(kal_uint32 type, kal_uint32 size)
{
   return bl_Allocate_TLV_Record((kal_uint32)g_mini_ext_da_share_buf, type, size);
}


#ifdef __MINI_BOOTLOADER__

kal_bool VerifyExtBootloader(kal_uint32 extBlAddr)
{

   INT_Trace_Enter(BL_VERIFY_EXT_BOOTLOADER);

#if !defined(__16_3_SEG__) && !defined(__32_32_SEG__) && !defined(__BRINGUP_SUPPORT__)

   BL_PRINT(LOG_INFO, "Verifying ExtBootloader...\n\r"); 

   if ( SST_VerifyBinaryByParent((kal_uint32*)&g_bootloader_gfh, (kal_uint32*)extBlAddr) != 0 )
   {
      BL_PRINT(LOG_CRIT, "Verifying ExtBootloader failed!!\n\r");
      return KAL_FALSE;
   }
#endif /* !__16_3_SEG__  && !__32_32_SEG__ && !__BRINGUP_SUPPORT__ */

   INT_Trace_Exit(BL_VERIFY_EXT_BOOTLOADER);

   return KAL_TRUE;
}

void JumpToExtBootloader(kal_uint32 extBlAddr)
{
    bl_Init_MINI_EXT_SharedData();

    //Prepare argument needs to be passed

    #define PASS_BUFFER_TO_EXT_BL(_ID, _P, _LEN) \
        memcpy(bl_Allocate_MINI_EXT_SharedData((_ID), (_LEN)), (void*)(_P), (_LEN))

    //This is the simplied version for convenience. User must make sure this variable is 4B aligned
    #define PASS_VARIABLE_TO_EXT_BL(_ID, _VAR) \
        if(sizeof(_VAR) <= 4) *(kal_uint32*)bl_Allocate_MINI_EXT_SharedData((_ID), sizeof(_VAR)) = *(kal_uint32*)(&(_VAR)); \
        else memcpy(bl_Allocate_MINI_EXT_SharedData((_ID), sizeof(_VAR)), &(_VAR), sizeof(_VAR))

    PASS_VARIABLE_TO_EXT_BL(MINI_EXT_SHARD_FEATURE_COMBINATION,     g_bootloader_gfh.gfh_arm_bl_info.m_feature_combination);
    PASS_VARIABLE_TO_EXT_BL(MINI_EXT_SHARD_FEATURE_COMBINATION_EXT, g_bootloader_gfh.gfh_arm_bl_info.m_feature_combination_ex);
    PASS_VARIABLE_TO_EXT_BL(MINI_EXT_SHARD_RANDOM_SEED,             g_randomSeed);

    PASS_BUFFER_TO_EXT_BL(MINI_EXT_SHARE_BL_TOKEN,                  (kal_uint32*)SST_GetToken(), sizeof(((BL_MAUI_ShareData*)(0))->m_bl_token));
    PASS_BUFFER_TO_EXT_BL(MINI_EXT_SHARE_EMI_PARAM,                 g_emi_param, sizeof(g_emi_param));

    PASS_VARIABLE_TO_EXT_BL(MINI_EXT_SHARE_USBDL_RETN,              g_usbdlRetnValue);

    //New shared data for MT6290
    PASS_BUFFER_TO_EXT_BL(MINI_EXT_SHARE_IMGPARAM, g_cs_bl_param->img_param, sizeof(img_param_t));
    PASS_BUFFER_TO_EXT_BL(MINI_EXT_SHARE_SCTRL_CERT, g_cs_bl_param->bl_param.sctrl_cert, sizeof(sctrl_cert_t));
    PASS_BUFFER_TO_EXT_BL(MINI_EXT_SHARE_SCTRL_CERT_FLAG, g_cs_bl_param->bl_param.sctrl_cert_flag, sizeof(kal_uint32));
    PASS_BUFFER_TO_EXT_BL(MINI_EXT_SHARE_MEID, g_cs_bl_param->bl_param.me_id, MEID_LENGTH);
    PASS_BUFFER_TO_EXT_BL(MINI_EXT_SHARE_CHANNEL_TYPE, g_cs_bl_param->bl_param.channel_type, sizeof(kal_uint32));
    PASS_BUFFER_TO_EXT_BL(MINI_EXT_SHARE_USB_PID, g_cs_bl_param->bl_param.ex_pid, sizeof(kal_uint16));
    PASS_BUFFER_TO_EXT_BL(MINI_EXT_SHARE_USB_VID, g_cs_bl_param->bl_param.ex_vid, sizeof(kal_uint16));
    
    if(extBlAddr != INVALID_START_ADDR)
    {
        extBlAddr += ((GFH_FILE_INFO_v1*)(extBlAddr))->m_jump_offset;
    }
    
    BL_PRINT(LOG_INFO, "Jump to ExtBL, %x\n\r",extBlAddr);

   INT_Trace_Exit(BL_BOOTLOADER);

#ifdef __TIME_STAMP__
{
    kal_uint32 tsAddr, tsSize;

    TS_GetContext(&tsAddr, &tsSize);
    PASS_BUFFER_TO_EXT_BL(MINI_EXT_SHARE_BL_TIME_STAMP_RECORD, tsAddr, tsSize);
}
#endif

    //Jump to EXT BL
    INT_Trace_Enter(BL_JUMP_EXT_BOOTLOADER);
    JumpCmd(extBlAddr);
    INT_Trace_Exit(BL_JUMP_EXT_BOOTLOADER);

}

void USBDLPreSet(void)
{
    g_usbdlRetnValue = DRV_Reg32(REG_SW_MISC);
}

void MiniBLErrorHandler(void)
{
   BL_PRINT(LOG_ERROR, "MiniBL is dead!!\r\n");

#if defined(__USB_DOWNLOAD__) 
   //Trigger BROM USBDL and try to recover this situation
   bl_wdt_force_reset(1);
#endif

}

#endif /*__MINI_BOOTLOADER__ */


/*************************************************************************
 * Main code of both of Bootloaders
 *************************************************************************/
void TriggerBromDL(void)
{
    bl_cfgctl_set_misc(0x04);
}

void TriggerBlDL(void)
{
    //Setup flag to trigger bootloader DL
    g_usbdlRetnValue &= (RETN_USBDL_BY_FLAG_EN|RETN_USBDL_TYPE_MASK);
}

void TriggerMetaMode(void)
{
   (*(volatile kal_uint16 *)BOOT_CONFIG_ADDR) |= 0x01;
}

kal_bool IsUsbATModeEnabled(void)
{
   return ((*(volatile kal_uint16 *)BOOT_CONFIG_ADDR) & 0x04) ? KAL_TRUE : KAL_FALSE;
}

kal_bool IsMetaModeEnabled(void)
{
   return ((*(volatile kal_uint16 *)BOOT_CONFIG_ADDR) & 0x01) ? KAL_TRUE : KAL_FALSE;
}

kal_bool IsFactoryModeToMAUI(void)
{
   return (IsMetaModeEnabled() || IsUsbATModeEnabled()) ? KAL_TRUE : KAL_FALSE;
}

kal_bool IsUSBEstablishedInBootROM(void) 
{
    //Todo: check usage
    return KAL_FALSE;
}

kal_bool IsBlUsbDLModeEnabled(void)
{
#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__)

    if(USBDL_Detect() == USBDL_FLAG)
    {
        return KAL_TRUE;
    }
#endif /*__USB_DOWNLOAD__ || __UART_DOWNLOAD__*/

    return KAL_FALSE;
}
/**********************************************************
Description : Utility for USB DL flag
Input       : 
Output      : 
***********************************************************/
void SetRetnFlag(kal_uint32 flag)
{
    DRV_WriteReg32(REG_SW_MISC, RETN_SPECIAL_KEY |flag);
}

void ClrRetnFlag(kal_uint32 flag)
{
    DRV_WriteReg32(REG_SW_MISC, RETN_SPECIAL_KEY);
}

void SetRetnTimeout(kal_uint32 time)
{

}

void ClearUSBDLFlag(void)
{
    ClrRetnFlag(0);   
}

void RestoreUSBDLFlag(void)
{
    ClearUSBDLFlag();
    SetRetnFlag(g_usbdlRetnValue & (RETN_USBDL_BY_FLAG_EN|RETN_USBDL_TYPE_MASK));
}

kal_bool USBBL_KeyPressed()
{
    if(!(DRV_Reg32(USB_DL_FLAG) & USB_DL_BIT)){
        return KAL_TRUE;
    }

    return KAL_FALSE;
}

USBDL_TRIGGER_REASON USBDL_Detect(void)
{
    USBDL_TRIGGER_REASON detected = USBDL_NOT_TRIGGERED;

    //Check all possible conditions to enter USBDL
    //Rescue key has the highest priority
    if(USBBL_KeyPressed())
    {
        detected = USBDL_RESCUE_KEY;
    }

    //Detect flags from MAUI
    if((g_usbdlRetnValue & RETN_USBDL_BY_FLAG_EN) &&
        (g_usbdlRetnValue & RETN_USBDL_TYPE_MASK))
    {
        detected = USBDL_FLAG;
    }

    return detected;   
}

/*************************************************************************
 * Main code of ExtBootloader
 *************************************************************************/

#ifdef __EXT_BOOTLOADER__

#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__)

#define Delay_Count      150      //150ms
static const volatile kal_uint8  startcmd_len = 4;
static const kal_uint8  startcmd[4] = {
	0xa0,
	0x0a,
	0x50, 
	0x05
};

kal_uint8 USBDL_CheckStartCmd(void)
{

    kal_uint8  data;
    kal_uint8  GetStartCmd = KAL_FALSE;
    kal_uint8  startcmd_index = 0;

    BL_PRINT(LOG_INFO, "Start sync...\n\r");

    //Start timer
    BL_GPT_START_TIMEOUT_MS(Delay_Count);

#ifdef __USB_DOWNLOAD__     
    //Setup timeout for USB download
    BL_GPT_START_TIMEOUT_S2(BL_USB_TIMEOUT_S);
#elif __UART_DOWNLOAD__   
    // Clear UART RX FIFO 
    // 1. If RX FIFO is already filled with 1st 0xa0 by tool, which would cause start command out-of-sync
    // 2. Should be right before polling loop without other operations between
    ClearUARTFifo();
#else
        #error "Impossible"
#endif

    do
    {
    #if defined(__USB_DOWNLOAD__)     
        data = USBDL_GetUARTByte_Ext(KAL_FALSE) ;
        if(data != 0)
        {
            USBDL_PutUARTByte_Ext(~data,KAL_FALSE);
            USBDL_PutUARTByte_Complete_Ext(KAL_FALSE);
        }
        else
        {
            continue;
        }
    #elif defined(__UART_DOWNLOAD__)     
        if(GetUARTByte_NB(&data))
        {

        }
        else
        {
            continue;
        }
    #else
        #error "Impossible"
    #endif

        if (data == startcmd[startcmd_index])
        {
            PutUARTByte(~data);
            PutUARTByte_Complete();
        
            BL_GPT_START_TIMEOUT_MS(Delay_Count);
            startcmd_index++;

            if (startcmd_index == startcmd_len)
            {
#if defined(__USB_DOWNLOAD__)
                BL_PRINT(LOG_INFO, "Sync success\n\r");
#endif            
                GetStartCmd = KAL_TRUE;
                break;
            }
        }
        else
        {
            PutUARTByte(data+1);
            PutUARTByte_Complete();
            startcmd_index = 0;
        }

#if defined(__USB_DOWNLOAD__)
    //No character is received in delay period and USB timer is timeout
    }while(BL_GPT_GET_TIMEOUT_STATUS() == KAL_FALSE || BL_GPT_GET_TIMEOUT_STATUS2() == KAL_FALSE);
#else
    //No character is received in delay period
    }while(BL_GPT_GET_TIMEOUT_STATUS() == KAL_FALSE);
#endif

    
    return GetStartCmd;
}

/**********************************************************
Description : Major Procedure for USB Download
Input       : None
Output      : None
***********************************************************/
void USBDL_Main(void)
{
    kal_bool skipDownload = KAL_FALSE;

#if defined(__USB_DOWNLOAD__)    
    BL_PRINT(LOG_INFO, "Open USB COM port...\n\r");
#elif defined(__UART_DOWNLOAD__)
    BL_PRINT(LOG_INFO, "Open UART COM port...\n\r");
#endif

    /* MAIN 1 : Setup USB Virtual COM */

#ifdef __USB_DOWNLOAD__
    {
        USBDL_UART_Init();      
    }

   /* MAIN 2 : Confirm COM port is ready */
    if (USBDL_Is_USB_Download_Mode() == KAL_FALSE )
    {
        /* User Abort the USB Download */
        skipDownload = KAL_TRUE;
    }
#endif

   /* MAIN 3 : Check Start Cmd */
    {
        if (skipDownload == KAL_FALSE && USBDL_CheckStartCmd() == KAL_FALSE)
        {
            /* User Run Unknown Program on PC side */
            skipDownload = KAL_TRUE;
        }
    }

   /* MAIN 4 : BOOTROM-like procedure start */
   if (skipDownload == KAL_FALSE)
   {

#if defined(__MTK_SECURE_PLATFORM__) 
      CBRUtl_InitService();
#endif

#if 0
/* under construction !*/
/* under construction !*/
#endif

        RestoreUSBDLFlag();

        bl_wdt_restart();

        Connect_FactoryTool();

        /* if it reach here, boot maui directly (Meta mode) */
        SetBootupFlag(BL_INFO_USBDL_IN_BL_CONNECTED);

#if defined(__SECURE_USB_DOWNLOAD__) || defined(__SECURE_UART_DOWNLOAD__)
        {
            extern kal_bool g_BlFirstDownload;
            if(g_BlFirstDownload != KAL_TRUE)
            {
                SetBootupFlag(BL_INFO_SUSBDL_IN_BL_ENABLED);
            } 
        }
#endif

    }

    // Go on with the bootup procedure since it's caused by a time-out of implicit USBDL or try to enter META mode     

#ifdef __USB_DOWNLOAD__
    BL_PRINT(LOG_INFO, "Disable COM port...\n\r");
    USBDL_Release();
#endif


    //Return and continue the boot-up
    BL_PRINT(LOG_INFO, "Continue to boot up...\n\r");

}

#ifdef __MTK_INTERNAL__

typedef enum
{
   USBDLV2_NONE      = 0x00,     //Normal detection flow
   USBDLV2_BOOT_META,            //No detection, bootup MAUI directly
   USBDLV2_DOWNLOAD,             //No detection, go to USBDL directly
   USBDLV2_INVALID   = 0xff,
} USBDLV2_MODE;

USBDLV2_MODE CheckUSBDLMode(void)
{
   USBDLV2_MODE currentMode = USBDLV2_INVALID;
   kal_bool factoryModeToMAUI = (IsMetaModeEnabled() || IsUsbATModeEnabled()) ? KAL_TRUE : KAL_FALSE;

   switch(g_usbdlRetnValue & (RETN_USBDL_BY_FLAG_EN|RETN_USBDL_TYPE_MASK))
   {
      case 0:                                               //Normal Bootup (0,0)
      {
         if(factoryModeToMAUI)
         {
            //META via UART or USB
            currentMode = USBDLV2_BOOT_META;
         }
         else
         {
            currentMode = USBDLV2_NONE;
         }
         break;
      }
      case RETN_USBDL_BY_FLAG_EN:                           //BROM USBDL (1,0)
      {
         if(factoryModeToMAUI)
         {
            //META via USB
            currentMode = USBDLV2_BOOT_META;
         }
         break;
      }
      case RETN_USBDL_TYPE_MASK:                            //Invalid case (0,1)
      {
         break;
      }

      case RETN_USBDL_BY_FLAG_EN|RETN_USBDL_TYPE_MASK:      //BL USBDL (1,1)
      {
         currentMode = USBDLV2_DOWNLOAD;
         break;
      }
   }

   if(currentMode == USBDLV2_INVALID)
   {
      BL_PRINT(LOG_ERROR, "Unrecognized USBDL mode, retn=%x\r\n", currentMode);
      ASSERT(0);
   }

   return currentMode;

}

void USBDL_PrintDebugInfo(void)
{   
    BL_PRINT(LOG_INFO, "Retn = (%d,%d), bl_trg=%d\r\n", (g_usbdlRetnValue&RETN_USBDL_BY_FLAG_EN)?1:0, (g_usbdlRetnValue&RETN_USBDL_TYPE_MASK)?1:0, (g_usbdlRetnValue&RETN_USBDL_TRIGGERED_BY_BL)?1:0);
    BL_PRINT(LOG_INFO, "BromCom=%d, META=%d\r\n", IsUSBEstablishedInBootROM(), IsFactoryModeToMAUI());
}

#endif /* __MTK_INTERNAL__ */


void InitiateBromUSBDL(USBDL_TRIGGER_REASON triggerReason)
{
   SetRetnFlag(RETN_USBDL_BY_FLAG_EN);

   BL_PRINT(LOG_INFO, "Launch BROM USBDL \r\n\r\n\r\n\r\n\r\n");

   bl_wdt_force_reset(1);

   while(1);
}

#endif /* defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__) */

/**********************************************************
Description : Major Procedure for Factory Purpose
Input       : None
Output      : None
***********************************************************/
void FactoryProcedure(void)
{
   INT_Trace_Enter(BL_FACTORY_PROCEDURE);

#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__)
    if (!g_usbdlDisabled)
    {
#if __MTK_INTERNAL__       
        /* MTK internal debug code */

        CheckUSBDLMode();
         
        USBDL_PrintDebugInfo();

#endif /* __MTK_INTERNAL__ */

        if(!IsFactoryModeToMAUI())
        {
            USBDL_TRIGGER_REASON usbdlTriggered = USBDL_Detect();         

#if __MTK_INTERNAL__
            BL_PRINT(LOG_INFO, "Current USBDL triggered = %x\r\n", usbdlTriggered);
#endif

            if(usbdlTriggered != USBDL_NOT_TRIGGERED)
            {
                //Trigger BROM USB BL for rescue
                if(usbdlTriggered == USBDL_RESCUE_KEY)
                {
                    InitiateBromUSBDL(usbdlTriggered);
                }

                USBDL_Main();

#if defined(__AP_BOOTUP_BY_MDBL__)
                //Bring up AP if USBDL is timeout
                {
                    bl_BringUpAP();

                    //Enable wdt interrupt mode to let AP handle the MD wdt reset
                    bl_wdt_intr_enable();
                }
#endif /*__AP_BOOTUP_BY_MDBL__*/
                
            }
            else
            {
                ClearUSBDLFlag();
            }
        }
        else
        {
            BL_PRINT(LOG_INFO, "META mode detected, go to MAUI directly\r\n");
        }

        //Wait for tools' ready
        ClearUSBDLFlag();

   }
   
#endif // __USB_DOWNLOAD__|| __UART_DOWNLOAD__

   INT_Trace_Exit(BL_FACTORY_PROCEDURE);

}

/**********************************************************
Description : Post process before jumping
Input       : None
Output      : None
***********************************************************/
__interncode__ void PostProcess(void)
{

#if defined(__USB_DOWNLOAD__) && defined(__BROM_USBDL_V2__)       
    BL_PRINT(LOG_INFO, "Out Retn = (%d,%d), %d\r\n", (*RETN_FLAG&RETN_USBDL_BY_FLAG_EN)?1:0, (*RETN_FLAG&RETN_USBDL_TYPE_MASK)?1:0, (*RETN_FLAG&RETN_USBDL_TRIGGERED_BY_BL)?1:0);
#endif

    CheckUARTSendEnd();

#if !defined(__IC_SLT_LOADER__)
    boot_init_clock();
#endif
}

/**********************************************************
Description : Procedures for boot and handover to next ROM
Input       : None
Output      : None
***********************************************************/

__interncode__ kal_uint32 LoadAndVerifyNextBinary(kal_bool *pDoRemap)
{
   kal_uint32 targetAddr = INVALID_START_ADDR;

    /* Non-FOTA part */
   targetAddr = LoadMauiBody();

   if(targetAddr != INVALID_START_ADDR)
   {
      targetAddr += ((GFH_FILE_INFO_v1*)(targetAddr))->m_jump_offset;
   }

    return targetAddr;
}

__interncode__ void BootAndHandOver(void)
{
    kal_uint32 targetAddr = INVALID_START_ADDR;
    kal_bool   doRemap = KAL_FALSE;

    INT_Trace_Enter(BL_BOOT_AND_HANDOVER);

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__XIP_SHADOWING__) || defined(__X_BOOTING__) || defined(__SERIAL_FLASH_EN__)
    BL_PRINT(LOG_DEBUG, "Start loading image...\n\r"); 
#endif

    bl_wdt_restart();

#if !defined(__IC_SLT_LOADER__)
    targetAddr = LoadAndVerifyNextBinary(&doRemap);
#else
    targetAddr = LoadAndVerifySLTBinary(&doRemap);
#endif

    bl_wdt_restart();

#if defined(__X_BOOTING__)
    if(XBOOT_BootEnd() != KAL_TRUE){
        return;
    }
#endif

#if !defined(__16_3_SEG__) && !defined(__32_32_SEG__) && !defined(__BRINGUP_SUPPORT__)
    CacheDeinit();
#endif /* !__16_3_SEG__  && !__32_32_SEG__ && !__BRINGUP_SUPPORT__ */

    if(targetAddr != INVALID_START_ADDR)
    {
        INT_Trace_Exit(BL_BOOT_AND_HANDOVER);
        INT_Trace_Exit(BL_EXT_BOOTLOADER);
        INT_Trace_Exit(BL_TOTAL);

#ifdef __TIME_STAMP__
        TS_SetTimeUnit(TS_TIME_MS);
        TS_ConvertTimeUnit();
        TS_DumpTimeStamps();
        BL_PRINT(LOG_INFO, "Dump timestamp done\r\n");
#endif

        BL_PRINT(LOG_INFO, "\nBye bye bootloader, jump to=%x\n\r", targetAddr);

        PostProcess();

        INT_Trace_Enter(BL_JUMP_MAUI);

        //Jump to MAUI in thumb mode
        JumpCmd(targetAddr);
        
        INT_Trace_Exit(BL_JUMP_MAUI);
    }

    g_Bl_Secure_Test = 1;
}

/**********************************************************
Description : Set up flags for init module
Input       : None
Output      : None
***********************************************************/

void SetBootupFlag(kal_uint32 flag)
{
    extern BL_Info_Wrapper_st BL_Shared_info;
    ASSERT(BL_Shared_info.m_bl_maui_share_data.m_bl_magic_head == BL_INFO_V1);
    BL_Shared_info.m_bl_maui_share_data.m_bl_bootup_flag |= flag;
}

kal_uint32 InitBlSysInfo(void)
{
    extern BL_Info_Wrapper_st BL_Shared_info;

    memset(&BL_Shared_info.m_bl_maui_share_data, 0x00, sizeof(BL_Shared_info.m_bl_maui_share_data));

    BL_Shared_info.m_bl_maui_share_data.m_bl_magic_head = BL_INFO_V1;
    BL_Shared_info.m_bl_maui_share_data.m_bl_random_seed = g_randomSeed;

    custom_get_bootloader_version(BL_Shared_info.m_bl_maui_share_data.m_bl_version_str, sizeof(BL_Shared_info.m_bl_maui_share_data.m_bl_version_str));

#ifndef __16_3_SEG__ 
    memcpy(BL_Shared_info.m_bl_maui_share_data.m_bl_token, SST_GetToken(), sizeof(BL_Shared_info.m_bl_maui_share_data.m_bl_token));      
#endif /* __16_3_SEG__ */

    memcpy(&BL_Shared_info.m_bl_maui_share_data.m_emi_param, g_emi_param, sizeof(g_emi_param));

    //Pass MEID to Moly
    memcpy(&BL_Shared_info.m_bl_maui_share_data.m_meid, g_mini_ext_bl_param.meid, sizeof(g_mini_ext_bl_param.meid));

    //Pass the sync channel type used in BROM or BL to Moly
    BL_Shared_info.m_chl_type = g_mini_ext_bl_param.channel_type;

    return 0;
}

void GetArgFromMini(void)
{
    kal_uint32 it = 0;
    kal_uint32 *p, type, size;

    while((p = bl_Traverse_TLV_Record((kal_uint32)g_mini_ext_da_share_buf, &it, &type, &size)))
    {
        switch(type)
        {
            case MINI_EXT_SHARD_RANDOM_SEED:
                g_randomSeed = *p;
                break;
 
            case MINI_EXT_SHARD_BL_PARAM:
                 //Not supported
                break;

            case MINI_EXT_SHARE_BL_HEADER:
                //Not supported
                break;

            case MINI_EXT_SHARE_BL_TOKEN:
                SST_SetToken(p, size);
                break;

            case MINI_EXT_SHARD_FEATURE_COMBINATION:
                //BL_TODO
                break;

#ifdef __TIME_STAMP__            
        case MINI_EXT_SHARE_BL_TIME_STAMP_RECORD:
        {
            kal_uint32 tsAddr, tsSize;
            TS_GetContext(&tsAddr, &tsSize);
            memcpy((void*)tsAddr, p, tsSize);
            break;
        }
#endif /* __TIME_STAMP__ */         

        case MINI_EXT_SHARE_EMI_PARAM:
            memcpy(g_emi_param, p, sizeof(g_emi_param));
            break;

        case MINI_EXT_SHARE_EXT_BL_UPDATE_INFO:
            //Not supported
            break;
            
        case MINI_EXT_SHARE_USBDL_RETN:
            g_usbdlRetnValue = *p;
            break;

        case MINI_EXT_SHARE_IMGPARAM:
            memcpy(&g_mini_ext_bl_param.img_param, p, sizeof(g_mini_ext_bl_param.img_param));
            
        case MINI_EXT_SHARE_SCTRL_CERT:
            memcpy(&g_mini_ext_bl_param.sctrl_cert, p, sizeof(g_mini_ext_bl_param.sctrl_cert));

        case MINI_EXT_SHARE_SCTRL_CERT_FLAG:
            g_mini_ext_bl_param.sctrl_cert_flag = *p;
            
        case MINI_EXT_SHARE_MEID:
            memcpy(&g_mini_ext_bl_param.meid, p, sizeof(g_mini_ext_bl_param.meid));
            break;

        case MINI_EXT_SHARE_CHANNEL_TYPE:
            memcpy(&g_mini_ext_bl_param.channel_type, p, sizeof(g_mini_ext_bl_param.channel_type));
            break;

        case MINI_EXT_SHARE_USB_PID:
            memcpy(&g_mini_ext_bl_param.usb_pid, p, sizeof(g_mini_ext_bl_param.usb_pid));
            break;

        case MINI_EXT_SHARE_USB_VID:
            memcpy(&g_mini_ext_bl_param.usb_vid, p, sizeof(g_mini_ext_bl_param.usb_vid));
            break;

        default:
            break;

      }
   }
}

/**********************************************************
Description : Main body of Ext Bootloader
Input       : None
Output      : None
***********************************************************/

void ExtBootloader(void)
{
    GetArgFromMini();

    TS_Init(KAL_FALSE);

    set_debug_level(bootloader_debug_level);

    INT_Trace_Enter(BL_EXT_BOOTLOADER);

    INT_Trace_Enter(BL_PRINT_WELCOME);

    BL_PRINT(LOG_DEBUG, "\n\n\n\r~~~ Welcome to MTK Bootloader %s (since 2005) ~~~\n\r", BootLDVerno);
    BL_PRINT(LOG_DEBUG, "**===================================================**\n\n\r");

#ifdef __MTK_INTERNAL__

#if defined(_NAND_FLASH_BOOTING_)
    BL_PRINT(LOG_DEBUG, "NAND Booting\n\r");
#elif defined(__EMMC_BOOTING__)
    BL_PRINT(LOG_DEBUG, "EMMC Booting\n\r");
#elif defined(__X_BOOTING__)
    BL_PRINT(LOG_DEBUG, "Xboot Booting\n\r");
#endif

#endif

    INT_Trace_Exit(BL_PRINT_WELCOME);

    if(InitExt() != BL_ERROR_NONE){
        BL_PRINT(LOG_ERROR, "ERROR: InitExt fail\n\r");
        return;
    }

    InitBlSysInfo();

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__SERIAL_FLASH_EN__)
    //Temp solution for non-final tool. This part should be replaced by CBR
    BL_DEBUG_PRINT("Find and load image list block...\n\r");
    if ( LoadImageListblock(GetMainRegionStartBlock()) == KAL_FALSE )
    {
        BL_PRINT(LOG_ERROR, "Invalid ILB config\n\r");
        return;
    }
#endif

    //Find (and load) MAUI's GFH
    if(!g_bootupDisabled)
    {
        kal_int32 status;
#if !defined(__IC_SLT_LOADER__)
        status = LoadMAUIFirstPart();
#else
        status = LoadSLTFirstPart();
#endif

        if(status != BL_ERROR_NONE){
            return;
        }
    }

    bl_wdt_restart();   

    GetFeatureCombination();

    if ( CheckPairedVersion() == KAL_FALSE )
    {
        g_bootupDisabled = KAL_TRUE;
        g_bootupStatus = BL_BOOTUP_FAIL_PAIRED_VER_MISMATCHED;
    }

    if ( CheckFeatureCombination() == KAL_FALSE )
    {
        g_bootupDisabled = KAL_TRUE;
        g_bootupStatus = BL_BOOTUP_FAIL_UNSUPPORTED_MAUI_FEAUTRE;
    }

#if !(defined(__X_BOOTING__))	
    FactoryProcedure();    
#endif

    if( !g_bootupDisabled )
    {

        INT_Trace_Enter(BL_PREPARE_BOOTUP);

        INT_Trace_Exit(BL_PREPARE_BOOTUP);

#ifndef __X_BOOTING__
        //Todo: remove the flag after new SDIO driver is ready
        //Disable cache for xboot since sdio driver does not support cache opertion now
        BL_PRINT(LOG_DEBUG, "Cache Init\n\r");
        CacheInit();      
#endif

        BootAndHandOver();
    }

    BL_PRINT(LOG_ERROR, "Bootloader dead end(%d,%d)\n\r", g_bootupDisabled, g_bootupStatus);

    while(1);
   
}

/**********************************************************
Description : Get the memory regions that are used by bootloader
Input       : A buffer and lenght of it
Output      : The information about bootloader region 
***********************************************************/

kal_uint32 GetBootloaderRegion(BL_MEM_REGION_INFO **pResultArr)
{
   #define GET_REGION_INFO(R, T) {                                                                                             \
                              extern kal_uint32 Image$$##R##$$Base;                                                            \
                              extern kal_uint32 Image$$##R##$$Length;                                                          \
                              extern kal_uint32 Image$$##R##$$ZI$$Length;                                                      \
                              if ( (kal_uint32)(&Image$$##R##$$Length) != 0 || (kal_uint32)(&Image$$##R##$$ZI$$Length) != 0 )  \
                              {                                                                                                \
                                pInfo[count].addr = (kal_uint32)(&Image$$##R##$$Base);                                             \
                                pInfo[count].len  = (kal_uint32)(&Image$$##R##$$Length) + (kal_uint32)(&Image$$##R##$$ZI$$Length); \
                                pInfo[count].type = T;                                                                             \
                                count++;                                                                                           \
                              }                                                                                                \
   }

   static kal_uint32 count = 0;
   static BL_MEM_REGION_INFO regionInfo[9];
   
   BL_MEM_REGION_INFO *pInfo = &regionInfo[0];

   if(count == 0)
   {
       //These code should be modified corresponding to scatter file
      GET_REGION_INFO(EXT_READ_ONLY,                BL_EXCLUSIVE_TO_DA)
      GET_REGION_INFO(EXT_READ_ONLY_HEAD,           BL_EXCLUSIVE_TO_DA)
      GET_REGION_INFO(EXT_READ_ONLY_TAIL,           BL_EXCLUSIVE_TO_DA)
      GET_REGION_INFO(EXT_READ_WRITE,               BL_EXCLUSIVE_TO_DA)

      GET_REGION_INFO(EXT_READ_ONLY_INT,            BL_FREE_DURING_EXECUTION)
      GET_REGION_INFO(EXT_READ_WRITE_INT,           BL_FREE_DURING_EXECUTION)
      GET_REGION_INFO(STACK_AREA_NOINIT,                   BL_FREE_DURING_EXECUTION)
      GET_REGION_INFO(EXT_UN_INIT_NOINIT,                  BL_FREE_DURING_EXECUTION)

      //SHARE_BUF is not protected due to DA's behavior
      //GET_REGION_INFO(SHARE_BUF_NOINIT,                    BL_FREE_DURING_EXECUTION)
      ASSERT(count < sizeof(regionInfo)/sizeof(regionInfo[0]));   
   }

   if(pResultArr)
   {
      *pResultArr = pInfo;
   }
      
   return count;

}

/**********************************************************
Description : Facility for wrapping USB and UART driver
Input       : 
Output      : 
***********************************************************/
#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__)

kal_uint8 BL_GetUARTByte(void)
{
#ifdef __UART_DOWNLOAD__
   return GetUARTByte();
#else
   return USBDL_GetUARTByte();
#endif
}

void BL_PutUARTByte(kal_uint8 data)
{
#ifdef __UART_DOWNLOAD__
   PutUARTByte(data);
#else
   USBDL_PutUARTByte(data);
#endif    
}

void BL_PutUARTByte_Complete(void)
{
#ifdef __UART_DOWNLOAD__
   PutUARTByte_Complete();
#else
   USBDL_PutUARTByte_Complete();
#endif        
}

void BL_CheckUARTSendEnd(void)
{
#ifdef __UART_DOWNLOAD__
   CheckUARTSendEnd();
#else
   USBDL_CheckUARTSendEnd();
#endif        
}
#endif /* defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__) */

/**********************************************************
Description : Facility for BL-DA shared data, initialize structure
Input       : 
Output      : 
***********************************************************/
kal_bool bl_Init_BL_DA_SharedData(void)
{
   return bl_Init_TLV_Service((kal_uint32)g_mini_ext_da_share_buf, sizeof(g_mini_ext_da_share_buf), BL_DA_SHARED_DATA_ID);   
}

/**********************************************************
Description : Facility for BL-DA shared data, allocate a new space
Input       : id of the requested record, and size of it
Output      : the pointer to the buffer for record
***********************************************************/
kal_uint32* bl_Allocate_BL_DA_SharedData(kal_uint32 type, kal_uint32 size)
{
   return bl_Allocate_TLV_Record((kal_uint32)g_mini_ext_da_share_buf, type, size);
}

   
#endif /* __EXT_BOOTLOADER__ */

