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
 *	smsal_l4c_enum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the enumerations which related to interface of
 *   SMSAL and L4C.
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

#ifndef _SMSAL_L4C_ENUM_H
#define _SMSAL_L4C_ENUM_H

#include "ps_public_enum.h" //mtk02589 MPM
#include "kal_general_types.h"

/* SIM file enum and NVRAM file enum are used together with maximum enum size*/
typedef kal_uint16 smsal_file_enum;

typedef enum
{
   SMSAL_NORMAL_INIT,
   SMSAL_PARAM_INIT_ONLY,
   SMSAL_RESET_INIT
} smsal_init_type_enum;

typedef enum
{
   /* follows intended for AT commands and MMI */
   SMSAL_DEL_INDEXED_MSG = 0,    /* delete specified msg */
   SMSAL_DEL_READ_MSG,           /* delete all read msg */
   SMSAL_DEL_READ_SENT_MSG,      /* delete all read/sent msg */
   SMSAL_DEL_READ_MO_MSG,        /* delete all read/mobile-originated msg */
   SMSAL_DEL_ALL_MSG,            /* delete all msg */
   
   /* follows intended only for MMI */
   SMSAL_DEL_INBOX,
   SMSAL_DEL_OUTBOX,
   SMSAL_DEL_BITMAP             /* delete according bitmap */
} smsal_del_flag_enum;

/*
 * message type identifier 
 */
typedef enum
{
   SMSAL_MTI_DELIVER          = 0x00,
   SMSAL_MTI_DELIVER_REPORT   = 0x00,
   SMSAL_MTI_SUBMIT           = 0x01,
   SMSAL_MTI_SUBMIT_REPORT    = 0x01,
   SMSAL_MTI_STATUS_REPORT    = 0x02,
   SMSAL_MTI_COMMAND          = 0x02,
   
   SMSAL_MTI_UNSPECIFIED      = 0x03,  /* MMI shall handle this case,
                                        * eg, displaying "does not support", 
                                        * or "cannot display", etc */
   SMSAL_MTI_ILLEGAL          = 0x04
} smsal_mti_enum;

typedef enum
{
   SMSAL_VPF_NOT_PRESENT    = 0x00,
   SMSAL_VPF_ENHANCED       = 0x01,
   SMSAL_VPF_RELATIVE       = 0x02,
   SMSAL_VPF_ABSOLUTE       = 0x03

} smsal_vp_format_enum;


/*
 * CNMI destination code
 */
typedef enum
{
   SMSAL_INVALID_DEST = 0,
   SMSAL_TO_LMI,
   SMSAL_TO_RMI
} smsal_nmi_dest_enum;

typedef enum
{
   NOT_SHOW_HEADER = 0,
   SHOW_HEADER
} smsal_show_header_enum;

typedef enum
{
    SMSAL_SM_FIRST = 0x00,
    SMSAL_ME_FIRST = 0x01
} smsal_sms_prefer_order_enum;

typedef enum
{
   SMSAL_PDU_MODE = 0,
   SMSAL_TEXT_MODE,
   NUM_OF_SMSAL_MSG_FORMAT
} smsal_msg_format_enum;

typedef enum
{
   SMSAL_MMS_DISABLE =0,
   SMSAL_MMS_ENABLE_UNTIL_TIMEOUT,
   SMSAL_MMS_ENALBE
} smsal_more_msg_mode_enum;

typedef enum
{
   SMSAL_SERVICE0 = 0,
   SMSAL_SERVICE1
} smsal_service_mode_enum;

typedef enum
{
   EXACTLY_INDEXING,
   NEXT_INDEXING
} smsal_read_type_enum;

typedef enum
{
   SMSAL_SEND_MSG,               
   SMSAL_SEND_CMD           
} smsal_send_type_enum;

typedef enum
{
   CNMA_MODE_TEXT_MODE,
   CNMA_MODE_RP_ACK,
   CNMA_MODE_RP_ERROR
} smsal_cnma_mode_enum;

typedef enum
{
   SMSAL_MTSMS_PARA_MMS    =   0x0001,
   SMSAL_MTSMS_PARA_RP     =   0x0002,
   SMSAL_MTSMS_PARA_SRI    =   0x0004
} smsal_mt_sms_para_enum;

typedef enum
{
   /* In current phase, only "Relative" VP is supported */
   
   /* Reply Path NOT request, Status Report NOT request */
   SMSAL_DEFAULT_FO  = 0x11,                       
                     
   /* Reply Path request, Status Report NOT request */                     
   SMSAL_RP_FO       = 0x91,   
   
   /* Reply Path NOT request, Status Report request */                                                          
   SMSAL_SR_FO       = 0x31,   
   
   /* Reply Path request, Status Report request */                                       
   SMSAL_RP_SR_FO    = 0xb1    
} smsal_first_octet_enum;   

/*
 * This enum is used in SMSAL module internally
 */
typedef enum
{
   SMSAL_GSM7_BIT = 0,    
   SMSAL_EIGHT_BIT,
   SMSAL_UCS2,       
   SMSAL_ALPHABET_UNSPECIFIED       

} smsal_alphabet_enum;

typedef enum
{
   SMSAL_CLASS0 = 0,
   SMSAL_CLASS1,
   SMSAL_CLASS2,
   SMSAL_CLASS3,
   SMSAL_CLASS_UNSPECIFIED,
   
   SMSAL_MW_DISCARD, /* follows are for SMSAL internal use */
   SMSAL_MW_STORE,
   SMSAL_RCM,
   NUM_OF_NMI_MSG_ENUM
} smsal_msg_class_enum;


typedef enum
{
   SMSAL_MSG_TYPE_NORMAL ,
   SMSAL_MSG_TYPE_CLASS0 ,
   SMSAL_MSG_TYPE_UPDATE_ONLY
} smsal_display_type_enum;


/* Enums for Relative format */
typedef enum
{
   SMSAL_VP_1_HR   = 11,   /* 1 hour */
   SMSAL_VP_6_HR   = 71,   /* 6 hours */
   SMSAL_VP_12_HR  = 143,  /* 12 hours */
   SMSAL_VP_24_HR  = 167,  /* 24 hours = 1 day */
   SMSAL_VP_72_HR  = 169,  /* 72 hours = 3 days */
   SMSAL_VP_1_WEEK = 173,  /* 1 week */
   SMSAL_VP_MAX    = 255   /* 63 weeks */
} smsal_vp_enum;


// SMSAL_MW_OTHER == SMSAL_MW_VIDEO_MSG   in SIM EFmwis
// SMSAL_MW_OTHER != SMSAL_MW_VIDEO_MSG   in (U)SIM EFmwis
typedef enum
{
   SMSAL_MW_VM = 0,
   SMSAL_MW_FAX,
   SMSAL_MW_EMAIL, 
   SMSAL_MW_OTHER,
#ifdef __REL6__
   SMSAL_MW_VIDEO_MSG,       
#endif
   NUM_OF_MSG_WAITING_TYPE
} smsal_msg_waiting_type_enum;

typedef enum
{
    SMSAL_EVMI_NOTIFICATION        = 0x00,
    SMSAL_EVMI_DELETE_CONFIRMATION = 0x01
} smsal_sms_evmi_type_enum;

typedef enum
{
   SMSAL_ENQUIRY_CMD = 0,  /* enquiry relating to previously submitted SM */
   SMSAL_CANCEL_SRR_CMD,   /* cancel status report request */
   SMSAL_DEL_CMD,          /* delete previously submitted SM */
   SMSAL_ENABLE_SRR_CMD    /* enable status report request */   
} smsal_cmd_type_enum;
   
typedef enum
{
   SMSAL_MEM_FULL_NORMAL, /* both SIM and ME are full */
   SMSAL_SM_FULL_ONLY,
   SMSAL_ME_FULL_ONLY
} smsal_mem_full_enum;
 
typedef enum
{
   SMSAL_MEM_EXCEED_NORMAL,
   SMSAL_SM_EXCEED_WITH_CLASS2
} smsal_mem_exceed_enum;

typedef enum
{
   SMSAL_MEM_AVAIL_NORMAL, /* corresponding to SMSAL_MEM_FULL_NORMAL */
                           /* one of storage is avail. it will be sent */
   SMSAL_SM_AVAIL_ONLY,    /* corresponding to SMSAL_SM_FULL_ONLY */
   SMSAL_ME_AVAIL_ONLY     /* corresponding to SMSAL_SM_FULL_ONLY */
} smsal_mem_avail_enum;

typedef enum
{
   SMSAL_COPY_MSG,
   SMSAL_MOVE_MSG
} smsal_copy_action_enum;

typedef enum
{
    SMSAL_L4C_IMS_MO,
    SMSAL_L4C_IMS_MT,
    SMSAL_L4C_IMS_SMMA,
}smsal_l4c_ims_enum;
#endif /* _SMSAL_L4C_ENUM_H */


