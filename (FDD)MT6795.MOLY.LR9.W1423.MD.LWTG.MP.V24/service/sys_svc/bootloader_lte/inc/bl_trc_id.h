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
 *   bl_trc_id.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Time stamp measurement id (MOLY Only)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _BL_TRC_ID_H
#define _BL_TRC_ID_H

//==============================================================================
// Trace ID
//==============================================================================

typedef enum {

    BOOT_BL_TOTAL = 1
    
//Mini Bootloader
    ,BOOT_BL_BOOTLOADER
    ,BOOT_BL_INIT
    ,BOOT_BL_SDIO_SYNC_BEFORE_PLL
    ,BOOT_BL_SET_PLL
    ,BOOT_BL_SDIO_SYNC_AFTER_PLL
    ,BOOT_BL_SET_IO 
    ,BOOT_BL_SET_PMIC
    ,BOOT_BL_SET_PFB
    ,BOOT_BL_SET_HW_OWN
    ,BOOT_BL_SET_EMI
    ,BOOT_BL_LOAD_AP_BOOTLOADER
    ,BOOT_BL_LOAD_AP_BOOTLOADER_BODY
    ,BOOT_BL_INIT_MINI_FLASH_DRV_FOR_AP
    ,BOOT_BL_LOAD_EXT_BOOTLOADER
    ,BOOT_BL_INIT_MINI_FLASH_DRV
    ,BOOT_BL_LOAD_EXT_BOOTLOADER_BODY
    ,BOOT_BL_VERIFY_EXT_BOOTLOADER
    ,BOOT_BL_JUMP_EXT_BOOTLOADER

//Ext Bootloader
    ,BOOT_BL_EXT_BOOTLOADER
    ,BOOT_BL_PRINT_WELCOME    
    ,BOOT_BL_EXT_INIT
    ,BOOT_BL_INIT_EXT_FLASH_DRV
    ,BOOT_BL_LOAD_ILB_CBR
    ,BOOT_BL_INIT_CBR
    ,BOOT_BL_READ_FLASH_LAYOUT_INFO    
    ,BOOT_BL_LOAD_MAUI_FIRST_PART
    ,BOOT_BL_GET_FATURE_COMINATION
    ,BOOT_BL_FACTORY_PROCEDURE
    ,BOOT_BL_PREPARE_BOOTUP
    ,BOOT_BL_CACHE_INIT    
    ,BOOT_BL_BOOT_AND_HANDOVER
    ,BOOT_BL_LOAD_MAUI_BODY
    ,BOOT_BL_VERIFY_MAUI
    ,BOOT_BL_JUMP_MAUI
        
//Security related
    ,BOOT_CALC_EXT_BOOTLOADER_CRC
    ,BOOT_SINGLE_SIG_HASH_IN_BL
    ,BOOT_SINGLE_SIG_CIPHER_IN_BL
    ,BOOT_SINGLE_SIG_HASH_IN_EBL
    ,BOOT_SINGLE_SIG_CIPHER_IN_EBL
    ,BOOT_LAST_SINGLE_SIG_HASH
    ,BOOT_LAST_SINGLE_SIG_CIPHER

    ,BOOT_NUM

    ,BOOT_END = (U8)255    // max 255 records     
    ,BOOT_NONE = BOOT_END

} BOOT;

 #endif /*_BL_TRC_ID_H*/
