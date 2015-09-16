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
 *
 * Filename:
 * ---------
 * spc_drv.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * MD speech control interfaces 
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _SPC_DRV_H
#define _SPC_DRV_H

#include "sp_drv.h"

typedef struct spcBufInfoStruct 
{
   uint16 syncWord;
   uint16 type;
   uint16 length;
} spcBufInfo;

typedef struct spcExtendedBufInfoStruct 
{
   uint16 syncWord;
   uint16 type;
   uint16 length;
   uint16 curIdx;
   uint16 totalIdx;      
} spcExtendedBufInfo;

// ----------------------------------------------------------------------------
// Datacard
// ----------------------------------------------------------------------------
void spc_daca_sendDlData(void);
void spc_daca_requestUlData(void);

// ----------------------------------------------------------------------------
// PCMNWAY
// ----------------------------------------------------------------------------
#if defined(__ENABLE_SPEECH_DVT__)
void spc_pcmNWay_sendUlData(uint16 bufLen);
void spc_pcmNWay_requestDlData(uint16 bufLen);
#else // defined(__ENABLE_SPEECH_DVT__)
void spc_pcmNWay_sendUlData(void);
void spc_pcmNWay_requestDlData(void);
#endif // defined(__ENABLE_SPEECH_DVT__)

// ----------------------------------------------------------------------------
// Background Sound
// ----------------------------------------------------------------------------
void spc_bgSnd_requestData(void);
void spc_BgSndClose(void);

// ----------------------------------------------------------------------------
// Recording
// ----------------------------------------------------------------------------
void spc_record_sendPcmData(void);
void spc_record_sendVmData(void);
void spc_record_sendRAWPcmData(void);


// ----------------------------------------------------------------------------
// CTM
// ----------------------------------------------------------------------------
void spc_ctm_sendDumpDebugData(void);


// ----------------------------------------------------------------------------
// AUDL running functions Related
// ----------------------------------------------------------------------------
void Spc_Init(void); 
void spc_A2M_MsgHandler(kal_uint32 ccciMsg, kal_uint32 ccciResv);
void spc_AP_Command_Handler(kal_uint32 ccciMsg, kal_uint32 ccciMsgRev); //#ifdef SPC_MSG_ORG_VER	


#endif // _SPC_DRV_H
