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
 *	ps_public_ups_def.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  The public definitions of module UPS.
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef PS_PUBLIC_UPS_DEF_H
#define PS_PUBLIC_UPS_DEF_H

#if defined(__USB_TETHERING__)

#define RNDIS_PACKET_MSG_HEADER_LENGTH          44
#define RNDIS_ETHERNET_FRAME_HEADER_LENGTH      14

// Reserve more space for local parameters embedded in ratdm_ps_data_ind_struct
#define RNDIS_FREE_HEADER_SPACE     (((RNDIS_PACKET_MSG_HEADER_LENGTH + \
                                    RNDIS_ETHERNET_FRAME_HEADER_LENGTH + 11) >> 2) << 2)

#elif defined(__MBIM_SUPPORT__)

// MBIM Functional Descriptor
#define MBIM_MAX_CONTROL_MESSAGE        512
#define MBIM_NUMBER_FILTERS             16
#define MBIM_MAX_FILTER_SIZE            64
#define MBIM_MAX_SEGMENT_SIZE           1500 // By implementation guideline

// NTB Parameter Structure
#define MBIM_NTB_IN_MAX_SIZE            2048
#define MBIM_NDP_IN_DIVISOR             4
#define MBIM_NDP_IN_PAYLOAD_REMAINDER   0
#define MBIM_NDP_IN_ALIGNMENT           4

#define MBIM_NTB_OUT_MAX_SIZE           2048
#define MBIM_NDP_OUT_DIVISOR            4
#define MBIM_NDP_OUT_PAYLOAD_REMAINDER  0
#define MBIM_NDP_OUT_ALIGNMENT          4
#define MBIM_NTB_OUT_MAX_DATAGRAMS      1

#endif

#endif /* PS_PUBLIC_UPS_DEF_H */
