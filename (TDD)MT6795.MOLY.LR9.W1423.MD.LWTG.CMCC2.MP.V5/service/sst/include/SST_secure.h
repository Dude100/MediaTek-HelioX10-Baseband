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
 *   SST_secure.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This is header file for SST_secure.c
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
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Included header files
 *******************************************************************************/

/*************************************************************************
 * External global data declaration
 *************************************************************************/

/*************************************************************************
 * External Function Declaration
 *************************************************************************/

/*************************************************************************
 * Type definitions
 *************************************************************************/
#ifndef __SST_SECURE_H__
#define __SST_SECURE_H__

#include "kal_general_types.h"
#include "sst_interface.h"

#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
#if defined(__SMART_PHONE_MODEM__) && defined(__X_BOOTING__)
#define SECURE_RO_SIZE_OVERHEAD 0	//SEC_RO has no GFH for external phone
#else
#define SECURE_RO_SIZE_OVERHEAD 404 
#endif /*defined(__SMART_PHONE_MODEM__) && defined(__X_BOOTING__)*/
#else
#define SECURE_RO_SIZE_OVERHEAD  0
#endif

extern kal_bool   SST_Is_Secure_BB(void);

extern kal_bool SST_Get_ChipUID(kal_char *pUid, kal_int32 buf_len);

#if !defined(__MTK_TARGET__)
extern void SST_Secure_Algo (kal_uint8 Direction, kal_uint32 ContentAddr,
                             kal_uint32 ContentLen, kal_uint8 *CustomSeed,
                             kal_uint8 *ResText);

#elif (defined(__SMART_PHONE_MODEM__) && defined(__X_BOOTING__)) ||(defined(__MODEM_CARD__) && defined(__TRADITIONAL_MODEM_CARD__))
/* Tranditional dongle, external smart phone*/
extern void SST_Secure_Algo (kal_uint8 Direction, kal_uint32 ContentAddr,
                             kal_uint32 ContentLen, kal_uint8 *CustomSeed,
                             kal_uint8 *ResText);
#else /* __SMART_PHONE_MODEM__ */
/* hosted dongle, router, internal smart phone*/
extern kal_int32 IPC_RPC_Secure_Algo (kal_uint8 Direction, kal_uint32 ContentAddr,
                             kal_uint32 ContentLen, kal_uint8 *CustomSeed,
                             kal_uint8 *ResText);

extern kal_int32 IPC_RPC_Get_Secure_RO(kal_uint8 *ResText, kal_uint32 ResLen);

#define IPC_RPC_API(n, ...) IPC_RPC##_##n(__VA_ARGS__)
#define SST_Secure_Algo(...) IPC_RPC_API(Secure_Algo,__VA_ARGS__)

#endif /* __SMART_PHONE_MODEM__ */

extern void SST_Secure_Algo_With_Level (kal_uint8 Direction, kal_uint32 ContentAddr,
                        kal_uint32 ContentLen, kal_uint8 *CustomSeed, kal_uint32 Level,
                        kal_uint8 *ResText);

extern kal_bool SST_Get_NVRAM_Key(kal_uint32 *p_key, kal_uint32 *p_addr, kal_uint32 *p_len);
   
extern void SST_Get_Secure_RO (kal_uint8 *CustomSeed, kal_uint8 *ResText, kal_uint32 ResLen);

extern void SST_DTLB_Init (void);

extern void SST_SetBootupMode(kal_bool bIsFactoryBin);

extern kal_int32 SST_VerifyNFBImageContent(void* func_ptr, void* cache_ctrl_ptr, kal_uint32 binRes);

extern void SST_VerifyNFBSecondaryImage(void);

extern kal_int32 SST_VerifyImageContent(kal_uint32 secinfo_addr, kal_uint32 mac_addr, kal_bool bFactoryBin);

extern kal_int32 SST_VerifyExtBootloader(kal_uint32 ebl_addr, kal_uint32 ebl_len, kal_uint32 ebl_header_addr, kal_uint32 ebl_header_len);

extern void SST_Load_Data_For_SUSBDL(void* func_ptr);

extern kal_bool SST_CheckImageInfo(void);

extern kal_uint32 SST_GetBootloaderSize(void);

extern kal_uint32 SST_GetUAImageHeadSize(void);

extern kal_uint32 SST_GetUAImageTailSize(void);

extern kal_bool SST_SearchUAImageHead(kal_uint8 *buff, kal_uint32 buff_size, kal_uint8* info_buff, kal_uint32 *info_size);

extern kal_bool SST_SearchUAImageTail(kal_uint8 *buff, kal_uint32 buff_size, kal_uint8* info_buff, kal_uint32 *info_size);

extern kal_uint32 SST_VerifyBinaryByParent(kal_uint32 *pParentBinary, kal_uint32 *pTargetBinary);

extern kal_bool SST_VerifyMAUI(kal_uint32 *pParentBin, kal_uint32 *pMAUI);

extern kal_bool SST_VerifyDspROM(kal_uint32 *pParentBin, kal_uint32 *pDSP);

extern kal_uint32 SST_CheckBootloaderHash(kal_uint32* pBinary);

extern void SSS_Init_Share_Crypto_Drv(void * cb_ts_record, void * cb_ts_info, kal_uint32 init_tbl);

extern void SSS_Init_Crypto_Drv(void * cb_ts_record, void * cb_ts_info);

extern kal_uint32* SST_GetToken(void);

extern void SST_SetToken(kal_uint32 *pToken, kal_uint32 tokenLen);

extern kal_bool bl_Is_Brom_Cmd_Mode_Disabled(void);

#endif //__SST_SECURE_H__
