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
 *	llc_specific_defines.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains definitions of define constants and MACROs used in LLC
 *	 implementation.
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


#ifndef _LLC_SPECIFIC_DEFINES_H
#define _LLC_SPECIFIC_DEFINES_H

/*****************
Include Statements
******************/

/************************
Macros Without Parameters 
*************************/

/* ---- llc_defs.h ---- */

#ifdef __SMS_OVER_PS_SUPPORT__
#define NO_OF_ADM_SAPI                2
#else
#define NO_OF_ADM_SAPI                1
#endif

#define NO_OF_ABM_SAPI                4

#ifndef __MTK_TARGET__
#define MAX_LLC_QUEUE_SIZE           48 
#else /* __MTK_TARGET__ */

/* Jeff Wu 2005-12-21: MAX_LLC_QUEUE_SIZE may be obselete. Need discuss with Joseph */
#define MAX_LLC_QUEUE_SIZE           48*2 //(PDU_CONTXT_UNACK_UL_MAX_NUM_OF_BUFF * 2) //same as PDU_CONTXT_UNACK_UL_MAX_NUM_OF_BUFF * 2 PDP context

#endif /* __MTK_TARGET__ */

#define DEFAULT_LLC_TX_QUEUE_SIZE       MAX_LLC_QUEUE_SIZE 

#define UNASSIGNED_TLLI               0xFFFFFFFF

#define ACK_FORMAT          1
#define NON_ACK_FORMAT      0
#define ACK_REQD            1
#define ACK_NOT_REQD        2

#define SACK_BITMAP_MASK    0x1f
#define UI_FRAME_FORMAT     6


/* ---- llc_llerx.h ---- */
#define MIN_U_FRAME_LENGTH                 5
#define MIN_FRMR_FRAME_LENGTH              12
#define MIN_UI_FRAME_LENGTH_FOR_GMM        6 + 2
#define MIN_UI_FRAME_LENGTH_FOR_SNDCP      6 + N202
#define MIN_UI_FRAME_LENGTH_FOR_SMS        8 
#define MIN_S_NONSACK_FRAME_LENGTH         6
#define MIN_S_SACK_FRAME_LENGTH            7
#define MIN_SN_DATA_REQ_HEADER_LENGTH    1
#define MIN_I_NONSACK_FRAME_LENGTH         ( 7 + MIN_SN_DATA_REQ_HEADER_LENGTH )
/* ---- end of llc_llerx.h ---- */


/* ---- llc_llme.h ---- */
#define PM_BIT_ON      0x01
/* ---- end of llc_llme.h ---- */



/* ---- llc_mux.h ---- */
#define GENERATE_CRC              0
#define CHECK_CRC                 1
#define PROTECTED_MODE            1
#define UNPROTECTED_MODE          0

#define N202                      4

/* ---- end of llc_mux.h ---- */


/* ---- llc_peer.h ---- */

#define FCS_LENGTH                  3
#define U_HEADER_LENGTH             2
#define UI_HEADER_LENGTH            3
#define I_HEADER_LENGTH             4
#define I_SACK_FIXED_HEADER_LENGTH  5
#define S_SACK_FIXED_HEADER_LENGTH  3
#define CONTROL_FIELD_OFFSET        1

#define SET_W1_FIELD                0x01
#define SET_W2_FIELD                0x02
#define SET_W3_FIELD                0x04
#define SET_W1W3_FIELD              0x05
#define SET_W3W4_FIELD              0x0C
#define SET_W2W4_FIELD              0x0A
#define SET_W1W3W4_FIELD            0x0D


/* PD value */
#define DEFAULT_PD                  0x00


/*** CR bit values in LLC frame ***/
#define MS_COMMAND                 0
#define MS_RESPONSE                1
#define SGSN_COMMAND               1
#define SGSN_RESPONSE              0

#define FRMR_INFO_LENGTH           0x0A
#define ADD_FIELD_LENGTH           0x01
#define REJ_FRM_CNTRL_LENGTH       0x06

/* I frame and S frame formats */
#define RR_FORMAT                   0
#define SACK_FORMAT                 3
#define ACK_FORMAT                  1
#define RNR_FORMAT                  2

#define XID_COMMAND                 2
#define XID_RESPONSE                4
#define S_FORMAT_BITS              0x02

#define I_FORMAT_BIT               0x00


#define UA_RESPONSE                0x06
#define SABM_COMMAND               0x07

/* ---- end of llc_peer.h ---- */


/*****************
Enums Without Tags 
******************/
typedef enum {
    LLC_INVALID_PDU,
    LLC_L3_PDU,
    LLC_RES_PDU,
    LLC_DATA_I_PDU,
    LLC_SABM_CMD,
    LLC_XID_CMD,
    LLC_INQUIRY_CMD,
    LLC_DISC_CMD,
    LLC_CELL_UPDATE,
    LLC_DATA_UI_PDU
} llc_peer_msg_type_enum;

/* LLC peer message name for tool logging */
typedef enum {
    LLC__SABM_CMD,
    LLC__DISC_CMD,
    LLC__XID_CMD,
    LLC__UA_RSP,
    LLC__DM_RSP,
    LLC__XID_RSP,
    LLC__FRMR_RSP
} llc_peer_msg_name_enum;

/***************
Type Definitions 
****************/

/********
Constants 
*********/

#define LLC_PREF_N201_UI            1504

/*********************
Macros With Parameters 
**********************/

/* ---- llc_arqtx.h ---- */

#define GET_CEIL(a,b)    (((a) + (b) - 1) / (b))

/* ---- end of llc_arqtx.h ---- */

/* ----  llc_defs.h ---- */
#define GET_ADMSAPI_FROM_INDEX(struct_no) \
                LLC_GET_ADM_SAPI_FROM_STRUCT_CNST[struct_no]

#define GET_ABMSAPI_FROM_INDEX(struct_no) \
  ((struct_no) <= 1 ) ? ((2 * (struct_no))+3): ((2*(struct_no))+ 5)

#define GET_INDEX_FROM_ABMSAPI(sapi) \
                (((sapi) - 1) / 3)

//#define BITMASK(X) (1L << (X))
#define BITMASK(X) (1UL << (X))

/* ---- end of llc_defs.h ---- */

/***************************
Exported Function Prototypes 
****************************/

/******************************
Declarations Of Exported Globals 
*******************************/

#endif /* _LLC_SPECIFIC_DEFINES_H */


