/******************************************************************************
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
*******************************************************************************/

/******************************************************************************
 * Filename:
 * --------------------------------------------------------
 *   mrs_uas_capability.h
 *
 * Project:
 * --------------------------------------------------------
 *   Multimode
 *
 * Description:
 * --------------------------------------------------------
 *   The UAS capability stored in MRS context.
 *
 * Author:
 * --------------------------------------------------------
 * -------
 *
 * --------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * B3/B39.
 *
 * removed!
 * removed!
 * SIM index argument added in MRS INTER RAT HANDOVER INFO set/get function
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * MRS UAS Capability header
 *
 * removed!
 * removed!
 * .
 *
 *****************************************************************************/

#ifndef _MRS_UAS_CAPABILITY_H
#define _MRS_UAS_CAPABILITY_H

/* COMMON INCLUDES ***********************************************************/
#include "irat_common_enums.h"
#include "mrs_as_enums.h"


/*****************************************************************************
 * Macros Without Parameters
 *****************************************************************************/


/*****************************************************************************
 * Macros With Parameters
 *****************************************************************************/


/*****************************************************************************
 * Enums without tags
 *****************************************************************************/



/*****************************************************************************
 * Type Definitions
 *****************************************************************************/
typedef struct {
    kal_uint32  length;
    kal_uint8   value[MAX_LEN_UTRAN_HANDOVER_INFO_MSG];
} ho_info_buf;

typedef struct {
    ho_info_buf  iRATHOInfo_GSM;
    ho_info_buf  iRATHOInfoCompact_GSM;
    ho_info_buf  iRATHOInfo_EUTRA;
    kal_uint16 uea;
    kal_uint16 uia;
#ifdef __SGLTE__
	kal_bool is_band_39_ori_support;
#endif /* __SGLTE__ */

} uas_capability_context_struct;

typedef enum{
    UTRA_POWER_CLASS_1,
    UTRA_POWER_CLASS_2,
    UTRA_POWER_CLASS_3,
    UTRA_POWER_CLASS_3bis,
    UTRA_POWER_CLASS_4,
    UTRA_POWER_CLASS_INVALID = -1
} mrs_utra_power_class_enum;

/*****************************************************************************
 * Declarations Of Exported Globals
 *****************************************************************************/


/*****************************************************************************
 * Function prototypes
 *****************************************************************************/
extern void mrs_uas_set_irat_ho_info(MRS_SIM_INDEX sim_index, module_type src_mod, kal_bool needToNotify);

extern void mrs_uas_get_irat_ho_info(MRS_SIM_INDEX sim_index, kal_bool isGSM, kal_bool isCompact,
                                     kal_uint32 *pSize, void *pCtrlBuf);

extern void mrs_uas_read_nvram_cnf_handler(kal_uint16 nvram_file_id, kal_uint8* data, kal_uint16 len);

extern void mrs_uas_get_uea_uia(MRS_SIM_INDEX sim_index, kal_uint16 *uea, kal_uint16 *uia);
#ifdef __UMTS_FDD_MODE__
extern mrs_utra_power_class_enum mrs_uas_get_FDD_powerclass();
#endif
#ifdef __UMTS_TDD128_MODE__
extern mrs_utra_power_class_enum mrs_uas_get_TDD_powerclass();
#endif

extern void mrs_uas_band_setting_update(MRS_SIM_INDEX sim_index, kal_uint32* data);
#ifdef __SGLTE__
extern kal_bool mrs_uas_is_band_39_ori_support(MRS_SIM_INDEX sim_index);
#endif

#endif /* _MRS_UAS_CAPABILITY_H */

