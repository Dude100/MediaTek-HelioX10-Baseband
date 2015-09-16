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
 * vm.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * VM record related interface using internal
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _VM_H
#define _VM_H

//#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
typedef struct _vmGCodecULInfo
{
    uint16 drop_info;
    //uint16 system_time;
    uint16 codec;
    uint16 codec_parameters;
}vmGCodecULInfo, *pvmGCodecULInfo;
typedef struct _vmGCodecDLInfo
{
    uint16 drop_info;
    //uint16 system_time;
    uint16 codec;
    uint16 codec_parameters;
    uint16 DL_PCM_size;
}vmGCodecDLInfo, *pvmGCodecDLInfo;
void vmStoreGCodecULStream(vmGCodecULInfo *pstvmGCodecULInfo, kal_uint16 u16StreamSize, kal_uint8 *pu8StreamData);
void vmStoreGCodecDLStream(vmGCodecDLInfo *pstvmGCodecDLInfo, kal_uint16 u16StreamSize, kal_uint8 *pu8StreamData);
//#endif //#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)

void VMREC_ConfigEpl(void);
void VMREC_Start(void (*vm_hdlr)(void), uint16 type, bool isVoc);
void VMREC_Stop( bool isVoc);


/**
	@buf1: [Output]pointer to pcm buf1, 
	@len1: [Output]length of buf1, unit is word(2byte)
	@buf2: [Output]pointer to pcm buf2
	@len2: [Output]length of buf2. unit is word(2byte)
*/
void VmRec_GetReadBufs(kal_uint32 *add1, kal_uint16 *len1, kal_uint32 *add2, kal_uint16 *len2);
void VmRec_ReadDataDone(uint16 len);

#endif //_VM_H

