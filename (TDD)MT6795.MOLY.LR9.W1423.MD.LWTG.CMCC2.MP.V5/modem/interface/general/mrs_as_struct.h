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
 *   mrs_as_struct.h
 *
 * Project:
 * --------
 *   Multimode
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 * ----------------------------------------------------------------------------
 * $Log:$
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * [MT6290] CSFB_enhancements inject message extension.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * [MT6290] CSFB Enhancement Implementation for Autonomous Fast Return - add new MRS API.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 * 
 ******************************************************************************/
#ifndef _MRS_AS_STRUCT_H
#define _MRS_AS_STRUCT_H

#include "mrs_as_enums.h"
#include "kal_public_defs.h"

#define AFR_FREQ_MAX_NUM 8

/* MRS uses this primitive to inform AS about white list change */
typedef struct {
  LOCAL_PARA_HDR
  csg_white_list_update_cause update_cause;
  kal_bool acsgl_changed;
  kal_bool ocsgl_changed;
} mrs_as_csg_white_list_update_ind_struct;

/* MRS uses this primitive to synch LLA status with AS */
typedef struct {
  LOCAL_PARA_HDR
  //lower_layer_availability_enum l1_availibility_status;
} mrs_lower_layer_availability_update_ind_struct;

/* GAS synch LLA status with MRS */
typedef struct {
  LOCAL_PARA_HDR
  lower_layer_availability_enum l1_availibility_status;
} mrs_gas_lower_layer_availability_update_req_struct;

/* UAS synch LLA status with MRS */
typedef struct {
  LOCAL_PARA_HDR
  lower_layer_availability_enum l1_availibility_status;
} mrs_uas_lower_layer_availability_update_req_struct;

/* EAS synch LLA status with MRS */
typedef struct {
  LOCAL_PARA_HDR
  lower_layer_availability_enum l1_availibility_status;
} mrs_eas_lower_layer_availability_update_req_struct;

/* Inform GAS band setting is changed */
typedef struct {
  LOCAL_PARA_HDR
} mrs_gas_band_setting_update_ind_struct;

/* Inform UAS band setting is changed */
typedef struct {
  LOCAL_PARA_HDR
} mrs_uas_band_setting_update_ind_struct;

/* Inform EAS band setting is changed */
typedef struct {
  LOCAL_PARA_HDR
} mrs_eas_band_setting_update_ind_struct;

typedef struct mrs_plmn_id
{
   kal_uint8 mcc1;
   kal_uint8 mcc2;
   kal_uint8 mcc3;
   kal_uint8 mnc1;
   kal_uint8 mnc2;
   kal_uint8 mnc3;
} mrs_plmn_id;

/* MRS notifies UAS of the transmission of INTER RAT HANDOVER INFO in GSM */
typedef struct {
   LOCAL_PARA_HDR
} mrs_uas_umts_ho_info_rsp_struct;

typedef struct
{
   /* [b1: not used] [b2: reduce lau, enable] [b3: defer si13, enable] [b4: 2g afr, enable] [b5: 3g afr, enable] */
   /* [b6: CSFB_2G_FDD_eCSFB, disable] [b7: CSFB_3G_FDD_eCSFB, disable] [b8: CSFB_2G_TDD_eCSFB, enable] [b9: CSFB_3G_TDD_eCSFB, disable] */
   /* [b10 ~ b16: reserved] */
   kal_uint16       csfb_enhancement_item_status;
   /* [b1: not used] [b2: reduce lau, disable] [b3: defer si13, enable] [b4: 2g afr, disable] [b5: 3g afr, disable] */
   /* [b6: CSFB_2G_FDD_eCSFB, disable] [b7: CSFB_3G_FDD_eCSFB, disable] [b8: CSFB_2G_TDD_eCSFB, disable] [b9: CSFB_3G_TDD_eCSFB, disable] */
   /* [b10 ~ b16: reserved] */
   kal_uint16       csfb_enhancement_item_status_in_test_mode; 
   kal_bool        is_csfb_ongoing;
   kal_uint8       num;
   kal_uint32     afr_list[AFR_FREQ_MAX_NUM];
} mrs_afr_main_struct;

typedef struct {
    mrs_plmn_id plmn_id;
    kal_uint8 la_code[2];
} mrs_lai_struct;

typedef struct
{
    kal_uint16 arfcn;
    kal_uint8 bsic;
}mrs_gas_cell_struct;

typedef struct
{
    mrs_gas_cell_struct gas_cell;
    mrs_lai_struct lai;
}mrs_gas_cell_inf_struct;

typedef struct
{
    kal_uint16 uarfcn;
    kal_uint16 psc;
}mrs_uas_cell_struct;

typedef struct
{
   mrs_uas_cell_struct uas_cell;
   mrs_lai_struct lai;
}mrs_uas_cell_inf_struct;

#endif /* _MRS_AS_STRUCT_H */
