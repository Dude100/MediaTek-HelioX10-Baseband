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
 * g_series_union.h
 *
 * Project:
 * --------
 * SWIP
 *
 * Description:
 * ------------
 * G series codec structure union header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __G_SERIES_UNION_H__
#define __G_SERIES_UNION_H__

#include "awb_exp.h"
#include "g711plc_exp.h"
#include "g711_exp.h"
#include "g722_exp.h"
#include "g726_exp.h"
#include "g729_exp.h"
#include "g7231_exp.h"

typedef union {
    AWB_Enc_Init_Param      awb_enc_init_param;
    G722_Dec_Init_Param     g722_dec_init_param;
    G726_Enc_Init_Param     g726_enc_init_param;
    G726_Dec_Init_Param     g726_dec_init_param;
    G729_Enc_Init_Param     g729_enc_init_param;
    G7231_Enc_Init_Param    g7231_enc_init_param;
} G_Series_Init_Param;

typedef union {
    AWB_Enc_Runtime_Param       awb_enc_runtime_param;
    G711PLC_Dec_Runtime_Param   g711plc_dec_runtime_param;
    G722_Dec_Runtime_Param      g722_dec_runtime_param;
    G726_Enc_Runtime_Param      g726_enc_runtime_param;
    G7231_Enc_Runtime_Param     g7231_enc_runtime_param;
} G_Series_Runtime_Param;

// #define G711_10MS_PCM_FRAME_SIZE_IN_BYTES     160
// #define G711_PLC_10MS_PCM_FRAME_SIZE_IN_BYTES 160
// #define G7231_30MS_PCM_FRAME_SIZE_IN_BYTES    480
// #define G729_10MS_PCM_FRAME_SIZE_IN_BYTES     160
// #define G726_10MS_PCM_FRAME_SIZE_IN_BYTES     160
// #define G722_10MS_PCM_FRAME_SIZE_IN_BYTES     320
// #define G722_20MS_PCM_FRAME_SIZE_IN_BYTES     640
// #define AMRWB_20MS_PCM_FRAME_SIZE_IN_BYTES    640

#endif // __G_SERIES_UNION_H__

