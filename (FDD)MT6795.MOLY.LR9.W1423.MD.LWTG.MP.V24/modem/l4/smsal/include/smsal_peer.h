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
 * Filename:
 * ---------
 *	smsal_peer.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is a wrapper include file for smsal_peer_xxx.x
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _SMSAL_PEER_H
#define _SMSAL_PEER_H


/* Non-Standard compile options */
#define NSTD_SMSAL_DELIVER_REPORT_NACK_PEER_STRUCT_BITS
#define NSTD_SMSAL_DELIVER_REPORT_NACK_PEER_STRUCT_PACK
#define NSTD_SMSAL_DELIVER_REPORT_NACK_PEER_STRUCT_UNPACK
#define NSTD_SMSAL_DELIVER_REPORT_ACK_PEER_STRUCT_BITS
#define NSTD_SMSAL_DELIVER_REPORT_ACK_PEER_STRUCT_PACK
#define NSTD_SMSAL_DELIVER_REPORT_ACK_PEER_STRUCT_UNPACK
#define NSTD_SMSAL_SUBMIT_PEER_STRUCT_BITS
#define NSTD_SMSAL_SUBMIT_PEER_STRUCT_PACK
#define NSTD_SMSAL_SUBMIT_PEER_STRUCT_UNPACK
#define NSTD_SMSAL_DELIVER_PEER_STRUCT_PACK
#define NSTD_SMSAL_DELIVER_PEER_STRUCT_UNPACK
#define NSTD_SMSAL_SUBMIT_REPORT_NACK_PEER_STRUCT_UNPACK
#define NSTD_SMSAL_SUBMIT_REPORT_ACK_PEER_STRUCT_UNPACK
#define NSTD_SMSAL_STATUS_REPORT_PEER_STRUCT_BITS
#define NSTD_SMSAL_STATUS_REPORT_PEER_STRUCT_PACK
#define NSTD_SMSAL_STATUS_REPORT_PEER_STRUCT_UNPACK
#define NSTD_SMSAL_COMMAND_PEER_STRUCT_BITS
#define NSTD_SMSAL_COMMAND_PEER_STRUCT_PACK
#define NSTD_SMSAL_COMMAND_PEER_STRUCT_UNPACK

#define NSTD_SMSAL_DELIVER_REPORT_NACK_PEER_STRUCT_ALLOC
#define NSTD_SMSAL_DELIVER_REPORT_NACK_PEER_STRUCT_DEALLOC
#define NSTD_SMSAL_DELIVER_REPORT_ACK_PEER_STRUCT_ALLOC
#define NSTD_SMSAL_DELIVER_REPORT_ACK_PEER_STRUCT_DEALLOC
#define NSTD_SMSAL_SUBMIT_PEER_STRUCT_ALLOC
#define NSTD_SMSAL_SUBMIT_PEER_STRUCT_DEALLOC
#define NSTD_SMSAL_DELIVER_PEER_STRUCT_BITS
#define NSTD_SMSAL_DELIVER_PEER_STRUCT_ALLOC
#define NSTD_SMSAL_DELIVER_PEER_STRUCT_DEALLOC
#define NSTD_SMSAL_SUBMIT_REPORT_NACK_PEER_STRUCT_ALLOC
#define NSTD_SMSAL_SUBMIT_REPORT_NACK_PEER_STRUCT_DEALLOC
#define NSTD_SMSAL_SUBMIT_REPORT_ACK_PEER_STRUCT_ALLOC
#define NSTD_SMSAL_SUBMIT_REPORT_ACK_PEER_STRUCT_DEALLOC
#define NSTD_SMSAL_STATUS_REPORT_PEER_STRUCT_ALLOC
#define NSTD_SMSAL_STATUS_REPORT_PEER_STRUCT_DEALLOC
#define NSTD_SMSAL_COMMAND_PEER_STRUCT_ALLOC
#define NSTD_SMSAL_COMMAND_PEER_STRUCT_DEALLOC


#ifdef __cplusplus
extern "C"
{
#endif

#ifdef TEST_TOOL
#include "tt_defs.h"
#else
#endif

#include "smsal_peer_struct.h"

#ifdef TOOL
#include "set_smsal_peer.h"
#include "get_smsal_peer.h"
#endif
#ifdef __cplusplus
}
#endif

#endif


