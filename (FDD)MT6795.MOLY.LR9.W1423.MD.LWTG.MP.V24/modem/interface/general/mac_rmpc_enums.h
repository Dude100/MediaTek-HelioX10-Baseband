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

/******************************************************************************
 * Filename:
 * ---------
 *	mac_rmpc_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to define related messages and paramters between MAC
 *   and RMPC.
 *
 * Author:
 * -------
 * -------
 *
 *=============================================================================
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
 *=============================================================================
 ******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _MAC_RMPC_ENUMS_H
#define _MAC_RMPC_ENUMS_H



/******************************************************************************
 * Constant
 ******************************************************************************/
#define MAX_RADIO_PRIORITY  4
#define MAX_OCTETS_IN_CONTROL_BLOCK       22
#define MAX_OCTETS_WITH_HEADER_IN_CONTROL_BLOCK 23

/******************************************************************************
 * Enum Value
 ******************************************************************************/
typedef enum {
    UL_FAILURE,
    UL_SUCCESS,
	UPDATE_PROTECT_PACCH
} pa_result_type_enum;

typedef enum {
    DL_FAILURE,
    DL_SUCCESS
} dl_result_type_enum;

typedef enum {
    ONE_PHASE_CONTENTION_IN_PROG,         /* 0 */
    TWO_PHASE_CONTENTION_IN_PROG,         /* 1 */
    CONTENTION_PASS,                      /* 2 */
    DL_TBF_PENDING,                       /* 3 */
    INVALID_FREQ_PARAMS,                  /* 4 */
    NO_FREQ_PARAMS,                       /* 5 */
    NOT_SUPPORTING_MODE,                  /* 6 */
    INVALID_CODING_SCHEME,                /* 7 */
    ONE_PHASE_CONTENTION_FAIL,            /* 8 */
    TWO_PHASE_CONTENTION_FAIL,            /* 9 */
    MULTI_SLOT_RESTRICTION_NOT_MET,       /* 10 */
    GOT_ACCESS_REJ,                       /* 11 */
    UL_TFI_ABSENT,                        /* 12 */
    DL_TFI_ABSENT,                        /* 13 */
    MSG_DECODE_ERR,                       /* 14 */
    MSG_WITH_INVALID_STARTING_TIME,       /* 15 */
    ACCESS_FAIL_WITH_MAX_RETRY,           /* 16 */

#ifdef __TBF_EST__
   MSG_WITH_INVALID_STARTING_TIME_TBF_EST,          /*17 */
#endif

   /* Lanslo 20070424: MONZA receives bad single block 
     (should be PCCO) during packet access in 8960 inter-RAT test */
   DL_SINGLE_BLK_ERR,			  /* 18 */

   /* Byron: Add for GEMINI, for DL single block that MAC accept it, 
                  Another RR actually can be resume. Therefore, add this cause
                  to let MAC inform RMC when accept this DL single block assignment.
                  This inform procedure is also the new one*/
   /*Byron: 2007/11/19: This is needed for MONZA due to there is a DL TBF in progress substate*/
   DL_SINGLE_BLK_SUCC,			  /* 19 */
   /*Evelyn 20080826: Add to notify RMPC that second DL_ASSIGN_IND is dropped by MAC
                      Because DL TBF is in progress*/
   DROP_DUE_TO_DL_IN_PROG,               /* 20 */
   
   /* Nancy 20090727: Send uplink single block through MAC. */
   UL_SINGLE_BLK_IN_PROG,                 /* 21 */
   UL_SINGLE_BLK_SUCC,                    /* 22 */
   /* Nancy 20090727: If uplink single block and failure is due to invalid  
    * starting time, access procedure is aborted. 
    * [TS 04.18] 3.5.2.1.3.3 If the mobile station receives the IMMEDIATE 
    * ASSIGNMENT message after the TBF starting time has expired, a failure has
    * occurred. If a failure occurs and the packet access attempt was due to the 
    * sending of an RLC/MAC control message, the packet access is aborted, the 
    * mobile station returns to packet idle mode. */
   MSG_WITH_INVALID_STARTING_TIME_FOR_CTRL_MSG,         /* 23 */
   START_PACCH_PROTECT_REQ,  /* 24 */
   STOP_PACCH_PROTECT_REQ,  /* 25 */
   
   TOTAL_ACCESS_RESULT_ENUM               /* 26 */
} access_result_enum;

/* Vincent 040207 add */
typedef enum
{
   ALL_TBF_END,
   DL_TBF_START,
   UL_TBF_START
} tbf_status_change_enum;

#ifdef __EGPRS_MODE__
typedef enum EGPRS_MEAS_PARAM
{
   LINK_QUALITY_MEASUREMENT_MODE,
   BEP_PERIOD,
   BEP_PERIOD2
} egprs_meas_param_enum;
#endif /* end of __EGPRS_MODE__ */

#endif /* end of _MAC_RMPC_ENUMS_H */


