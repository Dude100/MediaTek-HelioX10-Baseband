/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014
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
 *   ipc_filter_priority.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   IP Core filter priority definition.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                 HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __INC_IPC_FILTER_PRIORITY_H
#define __INC_IPC_FILTER_PRIORITY_H

#define IPC_UL_FILTER_PRIORITY(_name, _num) IPC_UL_FILTER_PRIORITY_ ## _name ## _BEGIN, \
                                            IPC_UL_FILTER_PRIORITY_ ## _name ## _END = IPC_UL_FILTER_PRIORITY_ ## _name ## _BEGIN + _num,

#define IPC_DL_FILTER_PRIORITY(_name, _num) IPC_DL_FILTER_PRIORITY_ ## _name ## _BEGIN, \
                                            IPC_DL_FILTER_PRIORITY_ ## _name ## _END = IPC_DL_FILTER_PRIORITY_ ## _name ## _BEGIN + _num,

/* Priority for UL filters */
typedef enum {
    IPC_UL_FILTER_PRIORITY_BEGIN = 0,

    IPC_UL_FILTER_PRIORITY(AOMGR, 20)
    IPC_UL_FILTER_PRIORITY(NDPC, 4)

    NUM_OF_IPC_UL_FILTER,
} IPC_UL_FILTER_PRIORITY;

/* Priority for DL filters */
typedef enum {
    IPC_DL_FILTER_PRIORITY_BEGIN = 0,

    IPC_DL_FILTER_PRIORITY(IPC_DHCP, 16)
    IPC_DL_FILTER_PRIORITY(AOMGR, 4)
    IPC_DL_FILTER_PRIORITY(LTECSR, 4)

    IPC_DL_FILTER_PRIORITY(PFM_GARBAGE_FILTER, 127)
    IPC_DL_FILTER_PRIORITY_PFM_GARBAGE_FILTER_WC,

    NUM_OF_IPC_DL_FILTER,
} IPC_DL_FILTER_PRIORITY;

#endif /* __INC_IPC_FILTER_PRIORITY_H */
