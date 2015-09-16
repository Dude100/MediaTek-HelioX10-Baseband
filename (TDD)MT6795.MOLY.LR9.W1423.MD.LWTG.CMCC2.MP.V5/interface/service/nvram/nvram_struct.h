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
 * nvram_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for customers to config/customize their parameters to NVRAM Layer and
 *   Driver Layer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef NVRAM_STRUCT_H
#define NVRAM_STRUCT_H

#include "kal_general_types.h"
#include "nvram_enums.h"
#include "nvram_defs.h"

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_STARTUP_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8 access_id;
    kal_uint8 poweron_mode;
} nvram_startup_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_STARTUP_CNF
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8 access_id;
    kal_uint8 result;
    kal_uint8 data[8];
} nvram_startup_cnf_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_RESET_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8 access_id;
    nvram_reset_category_enum reset_category;
    nvram_app_id_enum app_id;
    nvram_lid_enum LID;
    kal_uint16 rec_index;
    kal_uint16 rec_amount;
} nvram_reset_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_RESET_CNF
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8 access_id;
    kal_uint8 result;
} nvram_reset_cnf_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_READ_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8 access_id;
    nvram_lid_enum file_idx;
    kal_uint16 para;
    kal_uint16 rec_amount;
} nvram_read_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_READ_CNF
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8 access_id;
    nvram_lid_enum file_idx;
    kal_uint16 para;
    kal_uint16 length;
    kal_uint8 result;
} nvram_read_cnf_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_WRITE_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8 access_id;
    nvram_lid_enum file_idx;
    kal_uint16 para;
} nvram_write_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_WRITE_CNF
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8 access_id;
    nvram_lid_enum file_idx;
    kal_uint16 para;
    kal_uint8 result;
} nvram_write_cnf_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_WRITE_IMEI_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8 access_id;			/* assign by sender */
    kal_uint16 record_index;		/* first IMEI or second IMEI,  starts from 1 */
    kal_uint8 imei[8];			    /* IMEI 8 bytes */
    kal_uint8 svn;			        /* svn 1 bytes */
} nvram_write_imei_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_WRITE_IMEI_CNF
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8 access_id;			/* same as nvram_write_imei_req_struct */
    kal_uint16 record_index;		/* 1 ~ 2 */
    kal_uint8 result;			    /* nvram_errno_enum */
} nvram_write_imei_cnf_struct;


/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_SET_LOCK_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8 lock_en;
    kal_uint32 reserved;
} nvram_set_lock_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_SET_LOCK_CNF
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8 result;
} nvram_set_lock_cnf_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_READ_SM_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8       access_id;          /*  app use, no use to NVRAM, will return in confirm primitive*/
    nvram_lid_enum  file_idx;           /*  NVRAM lid index */
    kal_uint16      para;               /*  record index */
    kal_uint16      rec_amount;         /*  total record to read */
    kal_uint8       *buffer;            /*  buffer to fill in data */
    kal_uint32      buf_size;           /*  buffer size */
} nvram_read_sm_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_READ_SM_CNF
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8       access_id;          /*  app use, no use to NVRAM, same value in requeset primitive*/
    nvram_lid_enum  file_idx;           /*  NVRAM lid index */
    kal_uint16      para;               /*  record index */
    kal_uint32      length;             /*  length of data in buffer */
    kal_uint8       result;             /*  error code */
} nvram_read_sm_cnf_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_WRITE_SM_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8       access_id;          /*  app use, no use to NVRAM, will return in confirm primitive*/
    nvram_lid_enum  file_idx;           /*  NVRAM lid index */
    kal_uint16      para;               /*  record index */
    kal_uint8       *buffer;            /*  buffer to fill in data */
    kal_uint32      buf_size;           /*  buffer size */
} nvram_write_sm_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_WRITE_SM_CNF
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8       access_id;          /*  app use, no use to NVRAM, same value in requeset primitive*/
    nvram_lid_enum  file_idx;           /*  NVRAM lid index */
    kal_uint16      para;               /*  record index */
    kal_uint8       result;             /*  result */
} nvram_write_sm_cnf_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_IMAGE_CREATE_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8       access_id;          /* app use, no use to NVRAM, will return in confirm primitive*/
    nvram_image_type_enum image_type;   /* Which kind of data need to put into backup partition.
                                           The value is a bitwise exclusive value.
                                           ex: NVRAM_IMAGE_TYPE_CALIBRAT | NVRAM_IMAGE_TYPE_IMEI
                                           ex: NVRAM_IMAGE_TYPE_DEFAULT
                                           if the value is NVRAM_IMAGE_TYPE_EMPTY, the backup partition
                                           would be initialized. */
} nvram_create_image_req_struct;


/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_IMAGE_CREATE_CNF
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8       access_id;          /* app use, no use to NVRAM, will return in confirm primitive*/
    nvram_errno_enum result;            /* the result of the requirement */
} nvram_create_image_cnf_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_IMAGE_RECOVER_REQ
 *************************************************************/

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8       access_id;          /*  app use, no use to NVRAM, will return in confirm primitive*/
    nvram_image_type_enum image_type;   /* Which kind of data need to recover
                                           The value is a bitwise exclusive value.
                                           ex: NVRAM_IMAGE_TYPE_CALIBRAT | NVRAM_IMAGE_TYPE_IMEI
                                           ex: NVRAM_IMAGE_TYPE_DEFAULT
                                           The value -- NVRAM_IMAGE_TYPE_EMPTY is no use*/

} nvram_recover_image_req_struct;


/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_IMAGE_RECOVER_CNF
 *************************************************************/

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8       access_id;          /*  app use, no use to NVRAM, will return in confirm primitive*/
    nvram_errno_enum result;            /* the result of the requirement */
} nvram_recover_image_cnf_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_IMAGE_VERIFY_REQ
 *************************************************************/

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8       access_id;          /*  app use, no use to NVRAM, will return in confirm primitive*/
    nvram_image_type_enum image_type;   /* Which kind of data need to verify
                                           The value is a bitwise exclusive value.
                                           ex: NVRAM_IMAGE_TYPE_CALIBRAT | NVRAM_IMAGE_TYPE_IMEI
                                           ex: NVRAM_IMAGE_TYPE_DEFAULT
                                           The value -- NVRAM_IMAGE_TYPE_EMPTY is no use*/

    kal_bool        fast_verify;        /* if the parameter is true, only the status of backup
                                           partition would be checked. */
} nvram_verify_image_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_IMAGE_VERIFY_CNF
 *************************************************************/

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8       access_id;          /*  app use, no use to NVRAM, will return in confirm primitive*/
    nvram_errno_enum result;            /* the result of the requirement
                                           NVRAM_ERRNO_IMAGE_EMPTY : the image is empty
                                           NVRAM_ERRNO_IMAGE_BROKEN : the image is broken, may power lost during image backup
                                           NVRAM_ERRNO_IMAGE_DATA_NOT_SYNC : the data doesn't synchoronous with NVRAM's*/
} nvram_verify_image_cnf_struct;


/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_SUSPEND_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32       suspend_time;       /* 0: suspend forever*/
} nvram_suspend_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_SUSPEND_CNF
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    nvram_errno_enum       result;
} nvram_suspend_cnf_struct;

/*************************************************************
*  <GROUP Local_Parameter_Structure>
*  Related Message: MSG_ID_NVRAM_SDS_REQ
*************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8   access_id;   /*  app use, no use to NVRAM, will return in confirm primitive*/
    nvram_sds_access_enum access_mode; /*   SDS access mode */
} nvram_sds_req_struct;


/*************************************************************
*  <GROUP Local_Parameter_Structure>
*  Related Message: 
*  Related Message: MSG_ID_NVRAM_SDS_CNF 
*************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8   access_id;   /* app use, no use to NVRAM, will return in confirm primitive*/
    nvram_errno_enum result;    /* the result of the requirement
                                                                    NVRAM_ERRNO_SUCCESS : access success */
} nvram_sds_cnf_struct;


/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_BIN_REGION_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8       access_id;                 /* app use, no use to NVRAM, will return in confirm primitive*/
    nvram_bin_region_access_enum access_mode;  /*   SDS access mode */
} nvram_bin_region_req_struct;


/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_NVRAM_BIN_REGION_CNF
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8   access_id;     /* app use, no use to NVRAM, will return in confirm primitive*/
    nvram_errno_enum result;   /* the result of the requirement */
} nvram_bin_region_cnf_struct;


#endif /* NVRAM_STRUCT_H */

