/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *  wmt_sap.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  WMT SAP
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/*****************************************************************************
 * Include
 *****************************************************************************/
#include "module_msg_range.h"

#ifndef _WMT_MSG_H
#define _WMT_MSG_H
 
/****************************************************************************
 *  Indication Messages: BT -> WMT
 ****************************************************************************/

MODULE_MSG_BEGIN( MSG_ID_WMT_MSG_CODE_BEGIN )
MSG_ID_BT_WMT_CONN_STATUS_UPDATE_IND = MSG_ID_WMT_MSG_CODE_BEGIN,
MSG_ID_BT_WMT_QUERY_RSSI_IND,
MSG_ID_WMT_BT_SET_RX_RANGE_CNF,
MSG_ID_WMT_WNDRV_SET_BWCS_IND,
MSG_ID_WMT_BT_SET_DEFAULT_TX_POWER_CNF,
MSG_ID_WMT_BT_UPDATE_CONN_TX_POWER_CNF,

/****************************************************************************
 *  Request Messages: WMT -> BT
 ****************************************************************************/
MSG_ID_WMT_BT_SET_BWCS_REQ,
MSG_ID_WMT_BT_QUERY_RSSI_REQ,
MSG_ID_WMT_BT_SET_RX_RANGE_REQ,
MSG_ID_WMT_BT_SET_DEFAULT_TX_POWER_REQ,
MSG_ID_WMT_BT_UPDATE_CONN_TX_POWER_REQ,
/****************************************************************************
 *  Indication Messages: WNDRV -> WMT
 ****************************************************************************/
MSG_ID_WNDRV_WMT_CONN_STATUS_UPDATE_IND,
MSG_ID_WNDRV_WMT_QUERY_RSSI_IND,

/****************************************************************************
 *  Request Messages: WMT -> WNDRV
 ****************************************************************************/
MSG_ID_WMT_WNDRV_SET_BWCS_REQ,
MSG_ID_WMT_WNDRV_QUERY_RSSI_REQ,
MSG_ID_WMT_WNDRV_SET_ANT_REQ,
MSG_ID_WMT_WNDRV_SET_FLOW_CTRL_REQ,
MSG_ID_WMT_WNDRV_SET_FIXED_RX_GAIN_REQ,
MSG_ID_WMT_WNDRV_SET_OMIT_LOW_RATE_REQ,

/****************************************************************************
 *  Request Messages: FM -> WMT
 ****************************************************************************/
MSG_ID_FM_WMT_SLEEP_REQ,

/****************************************************************************
 *  Request Messages: WMT -> FM
 ****************************************************************************/
MSG_ID_FM_WMT_SLEEP_CNF,

/****************************************************************************
 *  New Added Indication Messages: BT -> WMT
 ****************************************************************************/
MSG_ID_BT_WMT_HCI_EVENT_IND,
MSG_ID_WMT_BT_HCI_CMD_CNF,

/****************************************************************************
*  New Added Request Messages: WMT -> BT
****************************************************************************/
MSG_ID_WMT_BT_HCI_CMD_REQ,

/****************************************************************************
 *  Indication Messages: WNDRV -> WMT
 ****************************************************************************/
MSG_ID_WNDRV_WMT_CM_MODE_UPDATE_IND,
MODULE_MSG_END( MSG_ID_WMT_MSG_CODE_TAIL )

#endif  //_WMT_MSG_H
