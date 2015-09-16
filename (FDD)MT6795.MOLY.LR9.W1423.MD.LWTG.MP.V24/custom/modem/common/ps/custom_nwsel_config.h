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
 * custom_nwsel_config.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *   This file is used to define the configurations of Selection customization feature
 *
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
 *
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CUSTOM_NWSEL_CONFIG_H
#define _CUSTOM_NWSEL_CONFIG_H


#include "kal_general_types.h"

/*************************************************************************
* Constant
*************************************************************************/
/* Do not modify the following default values */

#define NWSEL_INVALID_TIMER_VALUE 0xffffffff
extern const kal_uint32 NWSEL_RETRY_ABNORMAL_LAI_TIMER_PERIOD;
extern const kal_uint32 NWSEL_RETRY_ABNORMAL_RAI_TIMER_PERIOD;

/* International Higher Priorirty PLMN Search */
#define ALL_MCC_ALLOWED 0xfff
#define NO_MCC_ALLOWED 0xffffffff

//extern const kal_uint32 NWSEL_RECOVERY_TIMER_INTERVAL[];
extern const kal_uint32 NWSEL_EUTRAN_DISABLE_TIMER_VALUE;
extern const kal_uint32 NWSEL_EUTRAN_DISABLE_TD_TIMER_VALUE;
extern const kal_uint32 NWSEL_EUTRAN_DISABLE_ESM_TIMER_VALUE;
extern const kal_uint32 NWSEL_EUTRAN_DISABLE_FOR_REJ_IN_HPLMN_TIMER_VALUE;
extern kal_uint32 *NWSEL_RPLMN_MCC_LIST;
extern kal_uint32 NWSEL_RPLMN_MCC_NUM;
extern kal_uint32 *NWSEL_HPPLMN_MCC_LIST;
extern kal_uint32 NWSEL_HPPLMN_MCC_NUM;

/* CUSTOM_EQ_PLMN_SET_END indicates the end of each EQ PLMN set */
#define CUSTOM_EQ_PLMN_SET_END "FFFFFF"
extern const char **CUSTOM_EQ_PLMN;
extern kal_uint32 CUSTOM_EQ_PLMN_NUM;

extern const char *CUSTOM_CSFB_PREFER_2G_PLMN[];

#define INVALID_CUSTOM_WL_PLMN "FFFFFF"
extern const char *CUSTOM_WL_PLMN[];
extern const kal_uint32 CUSTOM_WL_PLMN_NUM;

#define INVALID_CUSTOM_BL_PLMN "FFFFFF"
extern const char *CUSTOM_BL_PLMN[];
extern const nwsel_rat_enum CUSTOM_BL_RAT[];
extern const kal_uint32 CUSTOM_BL_PLMN_NUM;

/* Ignore equivalent PLMN list assigned by operator */
#define IGNORE_EQPLMN_OPERATOR_SET_END "FFFFFF"
extern char *IGNORE_EQPLMN_OPERATOR[];
extern kal_uint32 IGNORE_EQPLMN_OPERATOR_NUM;

#ifdef __ME_STORED_EHPLMN__
#define ME_STORED_EHPLMN_NUM  4 /* Shall less than or equal to 4, according to MAX_NUM_HPLMN definition */
#define ME_STORED_HPLMNWACT_NUM  4 

extern kal_uint8 ME_STORED_EHPLMN_DATA[]; 
extern kal_uint8 ME_STORED_EHPLMNWACT_DATA[];

#endif

#define NWSEL_CUSTOM_HOME_MCC_NOT_DEFINED 0xffffffff
#define NWSEL_RAT_ORDER_NUM 2 /* DO NOT MODIFY */
#define NWSEL_RAT_ENTRY_NUM 4 /* DO NOT MODIFY */
extern const kal_uint32 NWSEL_CUSTOM_HOME_MCC_NUM;

extern const kal_uint32 NWSEL_CUSTOM_HOME_MCC[];
extern const nwsel_rat_enum custom_rat_order_op01[NWSEL_RAT_ORDER_NUM][NWSEL_RAT_ENTRY_NUM];
extern const nwsel_rat_enum custom_rat_ocustom_rat_order_op01_roamingrder_op01[NWSEL_RAT_ORDER_NUM][NWSEL_RAT_ENTRY_NUM];
extern const nwsel_rat_enum custom_rat_order_def[NWSEL_RAT_ORDER_NUM][NWSEL_RAT_ENTRY_NUM];
extern const nwsel_rat_enum* custom_rat_order[NWSEL_RAT_ORDER_NUM];

extern const char *CUSTOM_PS_ONLY_PLMN[];
extern const kal_uint32 CUSTOM_PS_ONLY_PLMN_NUM;


/*************************************************************************
* Enum
*************************************************************************/
typedef enum
{
    MM_ENTER_STATE_DEPEND_ON_CONDITION,
    MM_ENTER_STATE_PLMN_SEARCH,
    MM_ENTER_STATE_ATTEMPTING_TO_UPDATE
}mm_state_after_lu_abnormal_enum;

typedef enum
{
    NWSEL_REJECT_13,
    NWSEL_REJECT_15,
    NWSEL_REJECT_ABNORMAL
}nwsel_disable_eutran_cause_enum;


/*************************************************************************
* Function
*************************************************************************/

//extern kal_uint8 nwsel_get_max_recovery_timer_num(void);
extern kal_bool nwsel_custom_is_search_hplmn_before_rplmn(void);
extern kal_bool nwsel_custom_allow_rplmn_hplmn_combined_search(void); 
extern kal_bool nwsel_custom_skip_no_suitable_plmn_rat(void);
extern mm_state_after_lu_abnormal_enum nwsel_custom_state_after_lu_abnormal(void);
extern kal_bool nwsel_custom_is_try_abnormal_lai_once_more(void); 
extern kal_bool nwsel_custom_search_next_plmn_when_access_class_barred(void);
extern kal_bool nwsel_custom_ignore_eqplmn_in_manual_mode(void);
extern kal_bool nwsel_custom_ignore_eqplmn_in_auto_mode(void);
extern kal_bool nwsel_custom_disable_previous_rplmn_from_nvram(void);
extern kal_bool nwsel_custom_disable_rplmn_from_gloci(void);
extern kal_bool nwsel_custom_disable_rplmn_from_epsloci(void);
extern kal_bool nwsel_custom_is_hpplmn_1st_attempt_enhance(void);
extern kal_bool nwsel_custom_is_disable_eutran_after_reject(nwsel_disable_eutran_cause_enum cause);
extern kal_bool nwsel_custom_is_display_roaming_hplmn_in_eplmn(void);
extern kal_bool nwsel_custom_is_disable_skip_new_fplmn_manual_resel(void);
extern kal_bool nwsel_custom_enable_plmnsel_oplmn_coexist(void);
extern void nwsel_init_sbp_config(void);

#endif /* _CUSTOM_NWSEL_CONFIG_H */

