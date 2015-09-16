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
 * smslib_enum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains enum
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _SMSLIB_ENUM_H
#define _SMSLIB_ENUM_H

#if defined(__SMS_STORAGE_BY_MMI__)

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef enum
{
    SMSLIB_MTI_DELIVER          = 0x00,
    SMSLIB_MTI_DELIVER_REPORT   = 0x00,
    SMSLIB_MTI_SUBMIT           = 0x01,
    SMSLIB_MTI_SUBMIT_REPORT    = 0x01,
    SMSLIB_MTI_STATUS_REPORT    = 0x02,
    SMSLIB_MTI_COMMAND          = 0x02,

    SMSLIB_MTI_UNSPECIFIED      = 0x03   /* MMI shall handle this case,
                                        * eg, displaying "does not support",
                                        * or "cannot display", etc */
} smslib_mti_enum;

typedef enum
{
    SMSLIB_CLASS0 = 0,
    SMSLIB_CLASS1,
    SMSLIB_CLASS2,
    SMSLIB_CLASS3,
    SMSLIB_CLASS_UNSPECIFIED,

    SMSLIB_MW_DISCARD, /* follows are for SMSLIB internal use */
    SMSLIB_MW_STORE,
    SMSLIB_RCM,
    SMSLIB_NUM_OF_NMI_MSG_ENUM
} smslib_msg_class_enum;

typedef enum
{
    /* follows intended for AT commands and MMI */
    SMSLIB_REC_UNREAD = 0,         /* received unread */
    SMSLIB_REC_READ,               /* received read */
    SMSLIB_STO_UNSENT,             /* stored unsent */
    SMSLIB_STO_SENT,               /* stored sent */

    SMSLIB_ALL,                    /* all (only applicable to +CMGL command)
                                  * not for MMI
                                  */

    /* follows intended for MMI only */
    SMSLIB_INBOX_PARTIAL,          /* parts of inbox messages */
    SMSLIB_OUTBOX_PARTIAL,         /* parts of outbox messages */
    SMSLIB_STO_DRAFT,              /* stored draft */
    SMSLIB_INVALID_STATUS
} smslib_sim_status_enum;

typedef enum
{
    SMSLIB_STATUS_OK = 0x00,
    SMSLIB_STATUS_NULL_POINTER,          /* application pass a NULL pointer */
    SMSLIB_STATUS_NO_MEMORY,             /* library run out of memory */
    SMSLIB_STATUS_ALREADY_INITIALIZED,   /* library already be initialized */
    SMSLIB_STATUS_NOT_INITIALIZED,       /* library is not be initialized */
    SMSLIB_STATUS_INVALID_PARAMETER,
    SMSLIB_STATUS_INVALID_MTI,
    SMSLIB_STATUS_UNSPECIFIED_ERROR,
    SMSLIB_STATUS_INPUT_SPDU_LENGTH_ERROR,
    SMSLIB_STATUS_INPUT_PDU_LENGTH_ERROR,
    SMSLIB_STATUS_INPUT_TPDU_LENGTH_ERROR,
    SMSLIB_STATUS_ADDR_LENGTH_ERROR,
    SMSLIB_STATUS_USER_DATA_LENGTH_ERROR,
    SMSLIB_STATUS_INPUT_LENGTH_ERROR,
    SMSLIB_STATUS_LENGTH_ERROR,
    SMSLIB_STATUS_END
} smslib_status_enum;

typedef enum
{
    SMSLIB_GSM7_BIT = 0,
    SMSLIB_EIGHT_BIT,
    SMSLIB_UCS2,
    SMSLIB_ALPHABET_UNSPECIFIED

} smslib_alphabet_enum;

typedef enum
{
    SMSLIB_MW_VM = 0,
    SMSLIB_MW_FAX,
    SMSLIB_MW_EMAIL,
    SMSLIB_MW_OTHER,
#ifdef __REL6__
    SMSLIB_MW_VIDEO_MSG,       
#endif
    SMSLIB_NUM_OF_MSG_WAITING_TYPE
} smslib_msg_waiting_type_enum;

typedef enum
{
    SMSLIB_MSG_WAIT_CPHS     = 0x01,
    SMSLIB_MSG_WAIT_DCS      = 0x02,
    SMSLIB_MSG_WAIT_UDH      = 0x04,
    SMSLIB_MSG_WAIT_UDH_EVM  = 0x08
} smslib_type_of_msg_waiting_enum;

typedef enum
{
    SMSLIB_VPF_NOT_PRESENT    = 0x00,
    SMSLIB_VPF_ENHANCED       = 0x01,
    SMSLIB_VPF_RELATIVE       = 0x02,
    SMSLIB_VPF_ABSOLUTE       = 0x03

} smslib_vp_format_enum;

typedef enum
{
    SMSLIB_DEFAULT_DCS        = 0x00,  /* GSM 7-bit */
    SMSLIB_8BIT_DCS           = 0x04,  /* 8-bit */
    SMSLIB_UCS2_DCS           = 0x08,  /* UCS2 */
    SMSLIB_RESERVED_DCS       = 0x0c,  /* reserved alphabet,
                                        currently, MMI shall display "not support alphabet"
                                        or "cannot display" when receive dcs indicated this value */
    SMSLIB_EXT_DCS            = 0x10  /* Special dcs for non-standard character,
                                       used by MMI and EMS */
} smslib_dcs_enum;

typedef enum
{
   /* Mailbox */
   SMSLIB_LINE_1 = 0,
   SMSLIB_LINE_2 = 1,
   SMSLIB_MAX_LINES = 2,          

   /* SMS profile parameter */
   SMSLIB_PROFILE_1 = 0,
   SMSLIB_PROFILE_2 = 1,
   SMSLIB_PROFILE_3 = 2,
   SMSLIB_PROFILE_4 = 3, /* SMSAL_MAX_PROFILE_NUM (4) */
   SMSLIB_PROFILE_NONE = 0xff /* invalid profile ID */
} smslib_dest_no_enum;

typedef enum
{
   SMSLIB_DEFAULT_PID = 0x00,   /* Text SMS */
   SMSLIB_TELEX_PID   = 0x21,   /* Telex */
   SMSLIB_G3_FAX_PID  = 0x22,   /* Group 3 telefax */
   SMSLIB_G4_FAX_PID  = 0x23,   /* Group 4 telefax */
   SMSLIB_VOICE_PID   = 0x24,   /* Voice Telephone */
   SMSLIB_ERMES_PID   = 0x25,   /* ERMES (European Radio Messaging System) */
   SMSLIB_PAGING_PID  = 0x26,   /* National Paging system */
   SMSLIB_X400_PID    = 0x31,   /* Any public X.400-based message system */
   SMSLIB_EMAIL_PID   = 0x32    /* E-mail SMS */
} smslib_pid_enum;

#endif // __SMS_STORAGE_BY_MMI__

#endif
