/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *
 * Filename:
 * ---------
 * custom_nwsel_config.c
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "string.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "l3_inc_enums.h"
#include "custom_nwsel_config.h"
#include "custom_mm_config.h"
#include "ps_public_enum.h"

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
#endif

/*************************************************************************
* EUTRAN disable timer
*
* TS 24.301, subclause 4.5:
*   As an implementation option, the UE may start a timer for enabling E-UTRA...
*
* AT&T spec, <CDR-DAM-320> Timer Value T_Disable-LTE:
*   T_Disable-LTE defines the duration that EUTRAN is to be 
*   disabled for. Its default value shall be 12mins ...
*************************************************************************/
/* This value should NOT be 0, minimum value is 1 min */
const kal_uint32 NWSEL_EUTRAN_DISABLE_TIMER_VALUE = KAL_TICKS_1_MIN * 12;

/*************************************************************************
* EUTRAN disable TD timer
*
* TS 23.122 subclause 3.1
*    If MS that has disabled its E-UTRA capability re-enables it when PLMN selection is performed, then the MS 
*    should, for duration of timer TD, memorize the PLMNs where E-UTRA capability was disabled as PLMNs where voice
*    service was not possible.
*************************************************************************/
/* This value should NOT be 0, minimum value is 1 min 
 * Default value is invalid, which means the value is as same as Higher Priority PLMN search timer (EF_HPPLMN in (U)SIM)
 */
const kal_uint32 NWSEL_EUTRAN_DISABLE_TD_TIMER_VALUE = NWSEL_INVALID_TIMER_VALUE;

/*************************************************************************
* EUTRAN disable ESM timer
*
* Clear Codes Data requirement - Telcel (Mexico)
*   The phone must not trigger Clear code 33 procedure unless 
*      5. LTE disable timer, 2 hours, (included on phone¡¦s side) is reached then the procedure starts all over again.
*************************************************************************/
 /* This value is 2 hrs */
const kal_uint32 NWSEL_EUTRAN_DISABLE_ESM_TIMER_VALUE = KAL_TICKS_1_MIN * 120;

/*************************************************************************
* EUTRAN disable timer for reject cause #15 in HPLMN
*
* For 23G only SIM, UE will be reject with cause #13, #15 in 4G NW.
* To opitimize power consumption, disable EUTRAN in HPLMN if reject cause #13, #15 is received in 4G PLMN.
*************************************************************************/
 /* This value is 12 hrs */
const kal_uint32 NWSEL_EUTRAN_DISABLE_FOR_REJ_IN_HPLMN_TIMER_VALUE = KAL_TICKS_1_MIN * 60 * 12;


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
#endif

#ifdef __ME_STORED_EHPLMN__
/*************************************************************************
* This information will be refered if EF_EHPLMN is not available
* NOTE: for 2 digit mnc PLMN, please leave the 3rd digit mnc as 0xf
*************************************************************************/
kal_uint8 ME_STORED_EHPLMN_DATA[ME_STORED_EHPLMN_NUM *3] = 
{
  /* mcc2|mcc1, mnc3|mcc3, mnc2|mnc1*/
  0x64, 0xf0, 0x00, /* 460 00 */
  0x64, 0xf0, 0x20, /* 460 02 */
  0x64, 0xf0, 0x70, /* 460 07 */
  0x64, 0xf0, 0x80  /* 460 08 */
};

/*************************************************************************
* This information will be refered if EF_HPLMNWact is not available
* NOTE: for 2 digit mnc PLMN, please leave the 3rd digit mnc as 0xf
*************************************************************************/
kal_uint8 ME_STORED_EHPLMNWACT_DATA[ME_STORED_HPLMNWACT_NUM *5] = 
{
  /* mcc2|mcc1, mnc3|mcc3, mnc2|mnc1, PLMN ACT, PLMN ACT*/
  0x64, 0xf0, 0x00, 0x80, 0x00,/* 460 00, RAT: UMTS*/
  0x64, 0xf0, 0x00, 0x00, 0x80,/* 460 00, RAT: GSM */
  0x64, 0xf0, 0x70, 0x80, 0x00,/* 460 07, RAT: UMTS */
  0x64, 0xf0, 0x70, 0x00, 0x80 /* 460 07, RAT: GSM */
};
#endif

/*****************************************************************************
* FUNCTION
*   nwsel_custom_is_search_hplmn_before_rplmn
*
* DESCRIPTION
*   This function is used to configure whether search HPLMN before RPLMN
*   when power on or recovery search in automatic mode.
*
*   This configuration will not take effect while verifying FTA cases.
*
* PARAMETERS
*   none
*
* RETURNS
*   KAL_TRUE:
*    - The UE will always search HPLMN before RPLMN when power on or recovery search in automatic mode
*      - The UE will take more time to get normal service if HPLMN does not exist
*      - The UE can camp on HPLMN quicker if both RPLMN and HPLMN exist
*
*   KAL_FALSE:
*   - The UE will follow the requirement of PLMN search procedure defined in 3GPP TS23.122 
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool nwsel_custom_is_search_hplmn_before_rplmn(void)
{
    return nwsel_query_sbp_feature(SBP_MM_SEARCH_HPLMN_BEFORE_RPLMN,KAL_FALSE);
}

/*****************************************************************************
* FUNCTION
*   nwsel_custom_is_display_roaming_hplmn_in_eplmn
*
* DESCRIPTION
*   This function is used to configure whether display roaming when HPLMN is add into EPLMN list
*
* PARAMETERS
*   none
*
* RETURNS
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool nwsel_custom_is_display_roaming_hplmn_in_eplmn(void)
{
    return (nwsel_query_sbp_feature(SBP_DISABLE_DISPLAY_ROAMING_HPLMN_IN_EPLMN,KAL_FALSE)==KAL_FALSE);
}

/*****************************************************************************
* FUNCTION
*   nwsel_custom_is_skip_new_fplmn_manual_resel
*
* DESCRIPTION
*   This function is used to configure whether to skip the remainning RAT for rejected by FORBIDDEN PLMN
*
* PARAMETERS
*   none
*
* RETURNS
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool nwsel_custom_is_disable_skip_new_fplmn_manual_resel(void)
{
    return nwsel_query_sbp_feature(SBP_DISABLE_SKIP_NEW_FPLMN_MANUAL_RESEL,KAL_FALSE);
}

/*****************************************************************************
* FUNCTION
*   nwsel_custom_enable_plmnsel_oplmn_coexist
*
* DESCRIPTION
*   This function is used to configure whether enable ef_plmnsel and ef_oplmn both take effect
*
* PARAMETERS
*   none
*
* RETURNS
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool nwsel_custom_enable_plmnsel_oplmn_coexist(void)
{
    return (nwsel_query_sbp_feature(SBP_DISABLE_PLMNSEL_OPLMN_COEXIST,KAL_FALSE)==KAL_FALSE);
}


/*****************************************************************************
* FUNCTION
*   nwsel_custom_ignore_eqplmn_in_manual_mode
*
* DESCRIPTION
*   This function is used to configure whether shall ignore equivalent PLMN only in manual mode or not
*
* PARAMETERS
*   none
*
* RETURNS
*   KAL_TRUE:
*   KAL_FALSE:
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool nwsel_custom_ignore_eqplmn_in_manual_mode(void)
{
    return nwsel_query_sbp_feature(SBP_MM_IGNORE_EQPLMN_IN_MANUAL_MODE,KAL_FALSE);
}

/*****************************************************************************
* FUNCTION
*   nwsel_custom_ignore_eqplmn_in_auto_mode
*
* DESCRIPTION
*   This function is used to configure whether shall ignore equivalent PLMN only in auto mode or not
*
* PARAMETERS
*   none
*
* RETURNS
*   KAL_TRUE:
*   KAL_FALSE:
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool nwsel_custom_ignore_eqplmn_in_auto_mode(void)
{
    return nwsel_query_sbp_feature(SBP_MM_IGNORE_EQPLMN_IN_AUTO_MODE,KAL_FALSE);
}

/*****************************************************************************
* FUNCTION
*  nwsel_custom_allow_rplmn_hplmn_combined_search
*
* DESCRIPTION
*  This function is used to configure whether search RPLMN and HPLMN together.
*
*  [Important!]
*  If return value of nwsel_custom_is_search_hplmn_before_rplmn is set to KAL_TRUE, 
*  configuration of nwsel_custom_allow_rplmn_hplmn_combined_search will not take effect.
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool nwsel_custom_allow_rplmn_hplmn_combined_search(void)
{
    /*if search RPLMN and HPLMN together, it is more quickly to camp on HPLMN,
    and no need to do high priority plmn search later.
    But it may disobey test case 6.2.1.1 in spec 34.123. 
    */

    if(nwsel_query_sbp_feature(SBP_RPLMN_HPLMN_COMBINED_SEARCH,KAL_FALSE) == KAL_TRUE)
    {
        return KAL_TRUE;
    }
    else
    {
    #ifdef __UMTS_TDD128_MODE__  /*for TDD project, this compile option is open*/
        return KAL_FALSE;
    #elif defined(__DUMMY_OFF_R7_AUTO_RHPLMN_SEL__)
        return KAL_TRUE;            
    #else
        return KAL_FALSE;
    #endif
    }
} 

/*****************************************************************************
* FUNCTION
*  nwsel_custom_is_disable_eutran_after_no_suitable_cell_exist
* DESCRIPTION
*  AT&T requirement <CDR-DAM-415>When a Combined Attach/TAU Request is rejected with
* cause #17, a maximum of 5 attempts shall be made. Disable EUTRAN for PLMN 310-410
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool nwsel_custom_is_disable_eutran_after_reject(nwsel_disable_eutran_cause_enum cause)
{
    if(cause == NWSEL_REJECT_15)
    {
        return nwsel_query_sbp_feature(SBP_DISABLE_EUTRAN_AFTER_NO_SUITABLE,KAL_FALSE);
    }
    else if(cause == NWSEL_REJECT_ABNORMAL)
    {
        return nwsel_query_sbp_feature(SBP_DISABLE_EUTRAN_AFTER_ABNORMAL,KAL_FALSE);
    }
    else if(cause == NWSEL_REJECT_13)
    {
        return nwsel_query_sbp_feature(SBP_DISABLE_EUTRAN_AFTER_ROAMING_NOT_ALLOWED, KAL_FALSE);
    }
    
    return KAL_FALSE;
}


/*************************************************************************
 * International Higher Priorirty PLMN Search
 * 
 * [Important!] Enable this option will violate TS23.122 and thus fail FTA cases
 *
 * - NWSEL_RPLMN_MCC_LIST / NWSEL_HPPLMN_MCC_LIST:
 *   - The UE is allowed to perform international HPPLMN search when the UE
 *     1. registers on a PLMN belonging to one of the MCCs defined in NWSEL_RPLMN_MCC_LIST, and
 *     2. the HPPLMN belongs to one of the MCCs defined in NWSEL_HPPLMN_MCC_LIST
 *
 * - If the MCC of RPLMN or HPPLMN is not restricted
 *   - NWSEL_RPLMN_MCC_LIST or NWSEL_HPPLMN_MCC_LIST shall contain only one entry {ALL_MCC_ALLOWED}
 *
 * - If the UE is not allowed to perform international HPPLMN search
 *   - NWSEL_RPLMN_MCC_LIST and NWSEL_HPPLMN_MCC_LIST shall contain only one entry {NO_MCC_ALLOWED}
 *************************************************************************/
/*  The UE is allowed to perform international HPPLMN search when the UE
 *  1. registers on a PLMN belonging to any MCC, and 
 *  2. the HPPLMN belongs to any MCC
 */
kal_uint32 NWSEL_RPLMN_MCC_LIST_ANY[] = {ALL_MCC_ALLOWED};
kal_uint32 NWSEL_HPPLMN_MCC_LIST_ANY[] = {ALL_MCC_ALLOWED};
/*  The UE is allowed to perform international HPPLMN search when the UE
 *  1. registers on a PLMN belonging to US/Canada/Mexico/British Virgin Islands, and 
 *  2. the HPPLMN belongs to any MCC
 */
kal_uint32 NWSEL_RPLMN_MCC_LIST_ATNT[] = {310, 311, 312, 313, 314, 315, 316, 302, 334, 348};
kal_uint32 NWSEL_HPPLMN_MCC_LIST_ATNT[] = {ALL_MCC_ALLOWED};
/*  The UE is allowed to perform international HPPLMN search when the UE
 *  1. registers on a PLMN belonging to US, and 
 *  2. the HPPLMN belongs to Canada
 */
kal_uint32 NWSEL_RPLMN_MCC_LIST_INT[] = {310, 311, 312, 313, 314, 315, 316};
kal_uint32 NWSEL_HPPLMN_MCC_LIST_INT[] = {302};
/* The UE is not allowed to perform international HPPLMN search */

kal_uint32 NWSEL_RPLMN_MCC_LIST_DEF[] = {NO_MCC_ALLOWED};
kal_uint32 NWSEL_HPPLMN_MCC_LIST_DEF[] = {NO_MCC_ALLOWED};

kal_uint32 *NWSEL_RPLMN_MCC_LIST = NULL;
kal_uint32 *NWSEL_HPPLMN_MCC_LIST = NULL;

kal_uint32 NWSEL_RPLMN_MCC_NUM=0;
kal_uint32 NWSEL_HPPLMN_MCC_NUM=0;


/*****************************************************************************
* FUNCTION
*   mm_custom_state_after_lu_abnormal
*
* DESCRIPTION
*   According to 3GPP TS24.008 4.4.4.9, the UE may enter the MM IDLE sub-state ATTEMPTING TO UPDATE or
*   optionally the MM IDLE sub-state PLMN SEARCH after LU abnormal 4 times.
*
* PARAMETERS
*   none
*
* RETURNS
*   MM_ENTER_STATE_DEPEND_ON_CONDITION  - Default behavior
*   MM_ENTER_STATE_PLMN_SEARCH          - Always enter MM IDLE sub-state PLMN SEARCH and perform PLMN selection
*   MM_ENTER_STATE_ATTEMPTING_TO_UPDATE - Always enter MM IDLE sub-state ATTEMPTING TO UPDATE and stay on current cell
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
mm_state_after_lu_abnormal_enum nwsel_custom_state_after_lu_abnormal(void)
{
    if(nwsel_query_sbp_feature(SBP_MM_PERFORM_PLMN_SEARCH_AFTER_LU_ABNORMAL,KAL_FALSE) == KAL_TRUE)
    {
        return MM_ENTER_STATE_PLMN_SEARCH;
    }
    else
    {
        return MM_ENTER_STATE_DEPEND_ON_CONDITION;
    }
}


/*****************************************************************************
* FUNCTION
*   nwsel_custom_is_try_abnormal_lai_once_more
* DESCRIPTION
*   If abnormal LU 4 times happen, MS will try to search other available and allowable PLMNs. If no other PLMN is found,
*   MS will go back to the abnormal-4-times PLMN and do registration with another 4 attempts.
*
* PARAMETERS
*   none
* RETURNS
*   kal_bool - indicate if "try abnormal lai once more" is enabled.
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool nwsel_custom_is_try_abnormal_lai_once_more(void)
{
    return mm_custom_is_try_abnormal_lai_once_more();
}


/*************************************************************************
 * HPLMN matching criteria enhance and customized equivalent PLMN definition
 * 
 * [Important!] Inappropriate setting may violate spec and thus fail FTA cases
 *
 * - CUSTOM_EQ_PLMN[]
 *   Ex: CUSTOM_EQ_PLMN[] = 
 *           {"001010", "00101F", "00202F", CUSTOM_EQ_PLMN_SET_END, //the first 3 PLMNs are regarded as eqivalent to each other
 *            "100011", "10002F", CUSTOM_EQ_PLMN_SET_END}           //100011 and 10002F are regarded as equivalent. 
 *************************************************************************/
/*  Regards 31026F and 310260 as eqivalent. To allow cell reselection between 310260 and 31026F (T-Mobile)  */
const char *CUSTOM_EQ_PLMN_TMO[] = {"31026F", "310260", CUSTOM_EQ_PLMN_SET_END};

/* Default. Follows TS23.122 Annex A. Eg. In 310260, MS can reselect to 31026F. 
 * But if in 31026F, MS can't reselect to 310260. 
 */
const char *CUSTOM_EQ_PLMN_DEF[] = {CUSTOM_EQ_PLMN_SET_END};

const char **CUSTOM_EQ_PLMN = NULL;

kal_uint32 CUSTOM_EQ_PLMN_NUM = 0;


/*****************************************************************************
* NWSEL use this lists to decide plmn search rat order when CSFB by PLMN Search
* If RPLMN is in this list, then search rat order will be 2G=>3G
* Otherwise, search rat order will be 3G=>2G
*****************************************************************************/
const char *CUSTOM_CSFB_PREFER_2G_PLMN[] = {"45412F", "46000F", "46002F", "46007F", "46008F", CUSTOM_EQ_PLMN_SET_END};

/*****************************************************************************
* FUNCTION
*  nwsel_custom_config_custom_eq_plmn_list
* DESCRIPTION
*  This function is used to configure CUSTOM_EQ_PLMN by SBP function 
*
* PARAMETERS
*
* RETURNS
*  NONE
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void nwsel_custom_config_custom_eq_plmn_list(void)
{
    if (nwsel_query_sbp_feature(SBP_TMO_PLMN_MATCHING,KAL_FALSE) == KAL_TRUE)
    {
        CUSTOM_EQ_PLMN_NUM = sizeof(CUSTOM_EQ_PLMN_TMO)/sizeof(char *);
        CUSTOM_EQ_PLMN = CUSTOM_EQ_PLMN_TMO;
    }
    
    else
    {
        CUSTOM_EQ_PLMN_NUM = sizeof(CUSTOM_EQ_PLMN_DEF)/sizeof(char *);
        CUSTOM_EQ_PLMN = CUSTOM_EQ_PLMN_DEF;
    } 
}


/*************************************************************************
 * After abnormal LU 4 times, UE should wait T3212 timeout and then start next LU attempt round.
 * Customization can be done here. Config the RETRY_ABNORMAL_LAI timer value as below. UE will 
 * start the next LU attempt when the RETRY_ABNORMAL_LAI timer expires.
 *************************************************************************/
/* default value: 10 minutes */
const kal_uint32 NWSEL_RETRY_ABNORMAL_LAI_TIMER_PERIOD = 10 * KAL_TICKS_1_MIN;
const kal_uint32 NWSEL_RETRY_ABNORMAL_RAI_TIMER_PERIOD = 15 * KAL_TICKS_1_MIN;

/*************************************************************************
 * Ignore equivalent PLMN list assigned by operator
 * 
 * - IGNORE_EQPLMN_OPERATOR
 *     - If HPLMN belongs to any PLMN defined in the list,
 *       all eqivalent PLMNs assigned by this HPLMN will be ignored.
 * 
 *************************************************************************/
char *IGNORE_EQPLMN_OPERATOR[] = {IGNORE_EQPLMN_OPERATOR_SET_END, IGNORE_EQPLMN_OPERATOR_SET_END, IGNORE_EQPLMN_OPERATOR_SET_END};
kal_uint32 IGNORE_EQPLMN_OPERATOR_NUM = sizeof(IGNORE_EQPLMN_OPERATOR)/sizeof(char *);

/*****************************************************************************
* FUNCTION
*  nwsel_custom_config_ignore_eqplmn_operator_list
* DESCRIPTION
*  This function is used to configure IGNORE_EQPLMN_OPERATOR by SBP function 
*  when IGNORE_EQPLMN_OPERATOR is empty.
*
* PARAMETERS
*
* RETURNS
*  NONE
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void nwsel_custom_config_ignore_eqplmn_operator_list(void)
{
    kal_uint32 index = 0;

    /* If IGNORE_EQPLMN_OPERATOR is not empty, do not change the list by SBP */
    if (strcmp(IGNORE_EQPLMN_OPERATOR[0], IGNORE_EQPLMN_OPERATOR_SET_END) != 0)
    {
        return;
    }
    
    if (nwsel_query_sbp_feature(SBP_MM_IGNORE_YOIGO_EQPLMN,KAL_FALSE) == KAL_TRUE)
    {
        IGNORE_EQPLMN_OPERATOR[index] = "21404F";
        index++;
    }

    if (nwsel_query_sbp_feature(SBP_MM_IGNORE_PLAY_EQPLMN,KAL_FALSE) == KAL_TRUE)
    {
        IGNORE_EQPLMN_OPERATOR[index] = "26006F";
        index++;
    }
}

/*****************************************************************************
* FUNCTION
*  nwsel_custom_config_hpplmn_search_mcc_list
* DESCRIPTION
*  This function is used to configure NWSEL_RPLMN_MCC_LIST/NWSEL_HPPLMN_MCC_LIST by SBP function 
*
* PARAMETERS
*
* RETURNS
*  NONE
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void nwsel_custom_config_hpplmn_search_mcc_list(void)
{
    if (nwsel_query_sbp_feature(SBP_HPPLMN_REGARDLESS_ANY_MCC,KAL_FALSE) == KAL_TRUE)
    {
        NWSEL_RPLMN_MCC_LIST = NWSEL_RPLMN_MCC_LIST_ANY;
        NWSEL_HPPLMN_MCC_LIST = NWSEL_HPPLMN_MCC_LIST_ANY;        
        NWSEL_RPLMN_MCC_NUM = sizeof(NWSEL_RPLMN_MCC_LIST_ANY)/sizeof(kal_uint32);
        NWSEL_HPPLMN_MCC_NUM = sizeof(NWSEL_HPPLMN_MCC_LIST_ANY)/sizeof(kal_uint32);
    }
    else if (nwsel_query_sbp_feature(SBP_ATNT_HPPLMN_SEARCH,KAL_FALSE) == KAL_TRUE)
    {
        NWSEL_RPLMN_MCC_LIST = NWSEL_RPLMN_MCC_LIST_ATNT;
        NWSEL_HPPLMN_MCC_LIST = NWSEL_HPPLMN_MCC_LIST_ATNT;
        NWSEL_RPLMN_MCC_NUM = sizeof(NWSEL_RPLMN_MCC_LIST_ATNT)/sizeof(kal_uint32);
        NWSEL_HPPLMN_MCC_NUM = sizeof(NWSEL_HPPLMN_MCC_LIST_ATNT)/sizeof(kal_uint32);
    }
    else if (nwsel_query_sbp_feature(SBP_MM_INTERNATIONAL_HPPLMN_SEARCH,KAL_FALSE) == KAL_TRUE)
    {
        NWSEL_RPLMN_MCC_LIST = NWSEL_RPLMN_MCC_LIST_INT;
        NWSEL_HPPLMN_MCC_LIST = NWSEL_HPPLMN_MCC_LIST_INT;
        NWSEL_RPLMN_MCC_NUM = sizeof(NWSEL_RPLMN_MCC_LIST_INT)/sizeof(kal_uint32);
        NWSEL_HPPLMN_MCC_NUM = sizeof(NWSEL_HPPLMN_MCC_LIST_INT)/sizeof(kal_uint32);
    }
    else
    {
        NWSEL_RPLMN_MCC_LIST = NWSEL_RPLMN_MCC_LIST_DEF;
        NWSEL_HPPLMN_MCC_LIST = NWSEL_HPPLMN_MCC_LIST_DEF;
        NWSEL_RPLMN_MCC_NUM = sizeof(NWSEL_RPLMN_MCC_LIST_DEF)/sizeof(kal_uint32);
        NWSEL_HPPLMN_MCC_NUM = sizeof(NWSEL_HPPLMN_MCC_LIST_DEF)/sizeof(kal_uint32);
    } 
}

/*************************************************************************
 * customized roaming allow whitelist PLMN definition
 * 
 * To prevent the specified PLMN is banned due to disable roaming
 *   Ex: HPLMN 46001, international roaming is disable but want to allow to roam on 46692, 46689.
 * - CUSTOM_WL_PLMN[]
 *   Ex: CUSTOM_WL_PLMN[] = 
 *           {"46692F","46689F"}         
 *************************************************************************/

/*  If roaming is disable, only specified PLMNs/HPLMN can be registered by UE  */

const char *CUSTOM_WL_PLMN[] = {INVALID_CUSTOM_WL_PLMN};

const kal_uint32 CUSTOM_WL_PLMN_NUM = sizeof(CUSTOM_WL_PLMN)/sizeof(char *);

/*************************************************************************
 * customized non-existing network not allow blacklist definition
 * 
 * To prevent waste time to search non-existing PLMN
 * note: no guarantee that the specified network won't be found, just reduce the possibility to search 
 *   Ex: TDD project search 46001
 * - CUSTOM_BL_PLMN[] = {"46001F"} 
 *    CUSTOM_BL_RAT[] = {NWSEL_UMTS} 
 *    CUSTOM_BL_RAT[] = {NWSEL_UMTS} 
 *   Ex2: do not search china 3G
 * - CUSTOM_BL_PLMN[] = {"460FFF"} 
 *    CUSTOM_BL_RAT[] = {NWSEL_UMTS} 
 *************************************************************************/

/*  If network(PLMN/RAT) is specified, do not waste time on power scan the PLMN/RAT */
#ifdef __DISABLE_CUSTOM_NONEXISTING_NETWORK_MECHANISM__
const char *CUSTOM_BL_PLMN[] = {INVALID_CUSTOM_BL_PLMN};

const nwsel_rat_enum CUSTOM_BL_RAT[] = {NWSEL_RAT_NONE};
#elif defined(__UMTS_TDD128_MODE__)
const char *CUSTOM_BL_PLMN[] = {"46001F",INVALID_CUSTOM_BL_PLMN};

const nwsel_rat_enum CUSTOM_BL_RAT[] = {NWSEL_UMTS};
#else
const char *CUSTOM_BL_PLMN[] = {"46000F",INVALID_CUSTOM_BL_PLMN};

const nwsel_rat_enum CUSTOM_BL_RAT[] = {NWSEL_UMTS};
#endif

const kal_uint32 CUSTOM_BL_PLMN_NUM = sizeof(CUSTOM_BL_PLMN)/sizeof(char *);

/*************************************************************************
 * RAT search order setting
 * 
 * Two orders can be set according to the current location of the UE, in Home country or in Other countries (UE is 
 * roaming). 
 *   NWSEL_CUSTOM_HOME_MCC[] - define the Home country MCC, can be one or more MCCs
 *   custom_rat_order[2][4] - define the rat_order in home country and in other countries
 *************************************************************************/

/* define the Home country MCC, can be one or more MCCs */
/* if HOME MCC is not specified, use Home MCC RAT order in any countries */
const kal_uint32 NWSEL_CUSTOM_HOME_MCC[] = {
#if defined(__OP01__) && defined(__LTE_RAT__)
    460
#else
    /* default */
    NWSEL_CUSTOM_HOME_MCC_NOT_DEFINED
#endif
};

const kal_uint32 NWSEL_CUSTOM_HOME_MCC_NUM = sizeof(NWSEL_CUSTOM_HOME_MCC)/sizeof(kal_uint32);

/* Define the RAT search order in Home country (defined by NWSEL_CUSTOM_HOME_MCC) and in Other countries. 
 * Here are some setting reminders:
 * 1. NWSEL_TD_SCDMA and NWSEL_WCDMA should not both exist in the same search order.
 * 2. If NWSEL_TD_LTE and NWSEL_FDD_LTE exist in the same order, they should be listed successively. i.e. the order 
 *    "NWSEL_TD_LTE, NWSEL_TD-SCDMA, NWSEL_FDD_LTE" is NOT allowed
 * 3. NWSEL_RAT_NONE - Indicate the End Point, means "Do not search other RATs" 
 * 4. NWSEL_RAT_ANY - Indicate the End Point, means "Other RATs search order are not restricted" 
 * 5. If NWSEL_TD_FDD_LTE is listed, NWSEL_TD_LTE and NWSEL_FDD_LTE should not be listed in the same search order. 
 *    Vice versa.

   The following are allowed nwsel_rat_enum values:
     {
        NWSEL_RAT_NONE    -->     Indicate the End Point, means "Do not search other RATs"
        NWSEL_GSM
        NWSEL_UMTS        -->     3G FDD, WCDMA 
        NWSEL_TD_SCDMA    -->     3G TD, TD-SCDMA
        NWSEL_FDD_LTE
        NWSEL_TD_LTE
        NWSEL_TD_FDD_LTE  -->     Indicate TD-LTE and FDD-LTE have same priority
        NWSEL_RAT_ANY     -->     Indicate the End Point, means "Other RATs search order are not specified" 
     }
 */
const nwsel_rat_enum* custom_rat_order[NWSEL_RAT_ORDER_NUM];
const nwsel_rat_enum custom_rat_order_op01_roaming[NWSEL_RAT_ORDER_NUM][NWSEL_RAT_ENTRY_NUM] = {
//#if defined(__LTE_RAT__) && defined(__UMTS_FDD_MODE__) && defined(__OP01_ROAMING_RAT_ORDER__)
    /* Home MCC RAT search order */
    /* If FDD-LTE cell is found, regard the environment as "Abroad" */
    {NWSEL_TD_FDD_LTE, NWSEL_UMTS, NWSEL_GSM, NWSEL_RAT_NONE},

    /* Abroad/Roaming MCC RAT search order */
    {NWSEL_TD_LTE, NWSEL_FDD_LTE, NWSEL_UMTS, NWSEL_GSM}
};

//#elif defined(__OP01__) && defined(__LTE_RAT__)
const nwsel_rat_enum custom_rat_order_op01[NWSEL_RAT_ORDER_NUM][NWSEL_RAT_ENTRY_NUM] = {
    /* Home MCC RAT search order */
    /* If FDD-LTE cell is found, regard the environment as "Abroad" */
    {NWSEL_TD_FDD_LTE, NWSEL_TD_SCDMA, NWSEL_GSM, NWSEL_RAT_NONE},

    /* Abroad/Roaming MCC RAT search order */
    {NWSEL_TD_FDD_LTE, NWSEL_UMTS, NWSEL_GSM, NWSEL_RAT_NONE}
};
//#else
const nwsel_rat_enum custom_rat_order_def[NWSEL_RAT_ORDER_NUM][NWSEL_RAT_ENTRY_NUM] = {
    /* default - Search order are not specified. NWSEL wil check the previous RPLMN RAT and other factors to decide 
                 proper RAT order */
    /* Home MCC RAT search order */
    {NWSEL_RAT_ANY, NWSEL_RAT_ANY, NWSEL_RAT_ANY, NWSEL_RAT_ANY},

    /* Abroad/Roaming MCC RAT search order */
    {NWSEL_RAT_ANY, NWSEL_RAT_ANY, NWSEL_RAT_ANY, NWSEL_RAT_ANY}
//#endif
};

/*****************************************************************************
* FUNCTION
*  nwsel_custom_config_custom_rat_order
* DESCRIPTION
*  This function is used to configure custom_rat_order by SBP function 
*
* PARAMETERS
*
* RETURNS
*  NONE
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void nwsel_custom_config_custom_rat_order(void)
{
    kal_uint32 i;

    if (nwsel_query_sbp_feature(SBP_OP01_ROAMING_RAT_ORDER,KAL_FALSE) == KAL_TRUE)
    {   
        for( i = 0 ; i < NWSEL_RAT_ORDER_NUM ; i ++ )
        {
            custom_rat_order[i] = &custom_rat_order_op01_roaming[i];
        }
        return;
    }

#if defined(__OP01__) && defined(__LTE_RAT__)
    for( i = 0 ; i < NWSEL_RAT_ORDER_NUM ; i ++ )
    {
        custom_rat_order[i] = &custom_rat_order_op01[i];
    }
#else
    for( i = 0 ; i < NWSEL_RAT_ORDER_NUM ; i ++ )
    {
        custom_rat_order[i] = &custom_rat_order_def[i];
    }
#endif

}

/*****************************************************************************
* FUNCTION
*  nwsel_custom_search_next_plmn_when_access_class_barred
* DESCRIPTION
*  This function is used to configure whether search next plmn
*  when not test sim and not test mode
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool nwsel_custom_search_next_plmn_when_access_class_barred(void)
{
    return (nwsel_query_sbp_feature(SBP_DISABLE_PLMN_SEL_WHEN_ACCESS_BARRED,KAL_FALSE)==KAL_FALSE);
}

/*****************************************************************************
* FUNCTION
*  nwsel_custom_disable_previous_rplmn_from_nvram
* DESCRIPTION
*  This function is used to configure whether backup previous rplmn from nvram
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool nwsel_custom_disable_previous_rplmn_from_nvram(void)
{
    return nwsel_query_sbp_feature(SBP_MM_DISABLE_PREVIOUS_RPLMN_FROM_NVRAM,KAL_FALSE);
}

/*****************************************************************************
* FUNCTION
*  nwsel_custom_is_hpplmn_1st_attempt_enhance
* DESCRIPTION
*  H3G Hutchison Requirement:
*   First BG scan when UE is registered on a VPLMN shall always be 
*   2 min (HPLMN timer =2 min at first BG scan). This implementation shall be applied for 
*   "Power on", "Out Of Service" and "Manual selection" scenarios.
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool nwsel_custom_is_hpplmn_1st_attempt_enhance(void)
{
    return nwsel_query_sbp_feature(SBP_MM_HPPLMN_1ST_ATTEMPT_ENHANCE,KAL_FALSE);
}

/*****************************************************************************
* FUNCTION
*  nwsel_custom_disable_rplmn_from_gloci
* DESCRIPTION
*   Some operator doesn't expect MS will read the RPLMN information from GPRS LOCI.
*   So need an option to switch on/off this feature.
*
* PARAMETERS
*
* RETURNS
*   KAL_TRUE:
*    - MS will not store the RPLMN information from GPRS LOCI.
*   KAL_FALSE:
*    - MS will store the RPLMN information from GPRS LOCI.
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool nwsel_custom_disable_rplmn_from_gloci(void)
{
    return nwsel_query_sbp_feature(SBP_DISABLE_RPLMN_FROM_GLOCI,KAL_FALSE);
}
/*****************************************************************************
* FUNCTION
*  nwsel_custom_disable_rplmn_from_gloci
* DESCRIPTION
*   Some operator doesn't expect MS will read the RPLMN information from GPRS LOCI.
*   So need an option to switch on/off this feature.
*
* PARAMETERS
*
* RETURNS
*   KAL_TRUE:
*    - MS will not store the RPLMN information from GPRS LOCI.
*   KAL_FALSE:
*    - MS will store the RPLMN information from GPRS LOCI.
* GLOBALS AFFECTED
*  None
*****************************************************************************/
kal_bool nwsel_custom_disable_rplmn_from_epsloci(void)
{
    return nwsel_query_sbp_feature(SBP_DISABLE_RPLMN_FROM_EPSLOCI,KAL_FALSE);
}

/*************************************************************************
 * customized PS only LTE network definition
 * 
 * LTE CDMA netork reject UE with #18 CS DOMAIN NOT AVAILABLE
 *   Ex: CUSTOM_PS_ONLY_PLMN[] = 
 *           {"46692F","46689F"}         
 *************************************************************************/

/*  If roaming is disable, only specified PLMNs/HPLMN can be registered by UE  */

const char *CUSTOM_PS_ONLY_PLMN[] = {"45006F","46011F",INVALID_CUSTOM_WL_PLMN};

const kal_uint32 CUSTOM_PS_ONLY_PLMN_NUM = sizeof(CUSTOM_PS_ONLY_PLMN)/sizeof(char *);


/*****************************************************************************
* FUNCTION
*  nwsel_init_sbp_config
* DESCRIPTION
*  This function is used to configure NWSEL custom setting dynamically by SBP function.
*  This function is executed at NWSEL init stage before NWSEL receive INIT_REQ from RAC.
*
* PARAMETERS
*  NONE
* RETURNS
*  NONE
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void nwsel_init_sbp_config(void)
{
    nwsel_custom_config_ignore_eqplmn_operator_list();
    nwsel_custom_config_hpplmn_search_mcc_list();   
    nwsel_custom_config_custom_eq_plmn_list();
    nwsel_custom_config_custom_rat_order();
}

