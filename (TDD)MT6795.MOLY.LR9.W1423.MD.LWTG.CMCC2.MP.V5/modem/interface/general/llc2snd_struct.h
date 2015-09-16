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
 *  llc2snd_struct.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file describes the common struct of LLC and SNDCP. 
 *
 * Author:
 * -------
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

#ifndef _LLC2SND_STRUCT_H
#define _LLC2SND_STRUCT_H


// Poying: 20101105. RHR
//------------------------------ suggest Add ------------------------------    
#include "kal_general_types.h"
#include "kal_public_defs.h"


typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint32 tlli;
    kal_uint16 ui_info_field_length;
    kal_uint16 i_info_field_length;
} ll_establish_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint32 tlli;
    kal_uint16 ui_info_field_length;
    kal_uint16 i_info_field_length;
} ll_establish_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint32 tlli;
    kal_uint16 ui_info_field_length;
    kal_uint16 i_info_field_length;
} ll_xid_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint32 tlli;
    kal_uint16 ui_info_field_length;
    kal_uint16 i_info_field_length;
} ll_xid_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint8 l_parameter;
    kal_uint32 tlli;
} ll_release_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint32 tlli;
} ll_release_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint32 tlli;
    kal_uint16 ui_info_field_length;
    kal_uint16 i_info_field_length;
#ifdef __PS_HO__
    kal_bool old_xid_indicator;
    kal_bool is_psho;
#endif
} ll_reset_ind_struct;

#ifdef __PS_HO__
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
} ll_t100_reset_ind_struct;
#endif

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint32 tlli;
} ll_data_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint16 reference;
    kal_uint32 tlli;
} ll_data_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint32 tlli;
    kal_uint8 cause;
} ll_status_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
} ll_flush_cnf_struct;

typedef ll_establish_ind_struct llsnd_establish_ind_struct;
typedef ll_establish_cnf_struct llsnd_establish_cnf_struct;
typedef ll_xid_ind_struct llsnd_xid_ind_struct;
typedef ll_xid_cnf_struct llsnd_xid_cnf_struct;
typedef ll_release_ind_struct llsnd_release_ind_struct;
typedef ll_release_cnf_struct llsnd_release_cnf_struct;
typedef ll_data_cnf_struct llsnd_data_cnf_struct;
typedef ll_reset_ind_struct llsnd_reset_ind_struct;
typedef ll_data_ind_struct llsnd_data_ind_struct;
typedef ll_status_ind_struct llsnd_status_ind_struct;
typedef ll_flush_cnf_struct llsnd_flush_cnf_struct;
#ifdef __PS_HO__
typedef ll_t100_reset_ind_struct llsnd_t100_reset_ind_struct;
#endif
#endif 


