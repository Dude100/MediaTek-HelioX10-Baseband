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
 * Filename:
 * ---------
 * custom_l4_utility.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is used for L4C customization
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "kal_non_specific_general_types.h"


//#include <stdio.h>
//#include <string.h>
//#include "kal_release.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h"       	/* Task message communiction */
//#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
//#include "app_buff_alloc.h"
//#include "stack_timer.h"
//#include "event_shed.h"
//#include "nvram_editor_data_item.h"
//#include "custom_nvram_editor_data_item.h"
#ifdef __MMI_FMI__
//#include "custom_mmi_default_value.h" 
#endif
//#include "l4_defs.h"
//#include "uart_sw.h"

//#include "kbd_table.h"
#if defined(__ATCMD_ONOFF_CHECK__)
#include "rmmi_parser.h"
#endif
#include "kal_general_types.h"
//#include "stack_config.h"
#include "kal_public_api.h"

#if defined (__MTK_UL1_FDD__)
#if !defined (UL1_NOT_PRESENT)
//#if !defined (__HSUPA_SUPPORT__) && !defined (__HSDPA_SUPPORT__)
//#include "hal_ul1_struct.h"
//#include "ul1_def.h"
extern void UL1D_UeBandCapabilityEx(kal_uint32 *ue_cap);
//#include "ul1d_rf_public.h"
//#endif
#endif
#endif
#ifdef __MTK_TARGET__
#ifdef __LTE_RAT__
#include "mrs_eas_capability.h"
#endif
#endif
#include "csmcc_enums.h"
#include "l4_ps_api.h"
#include "sim_ps_struct.h"
#include "sim_ps_enum.h"
#include "sim_ps_msgid.h"

#define CM_DTMF_P_W_SWITCH_FLAG  KAL_FALSE
//define codec num
#define SUPPORTED_2G_CODEC_NUM 6 
#define CUSTOM_ACM_BOUND      (1000)
#define	CSM_RLC_TIMER_CONFIG  (3)

#ifdef __FWP_NC_LAI_INFO__
#define CELL_LOCK_PREFIX_LEN 4
kal_uint8 CELL_LOCK_PREFIX[CELL_LOCK_PREFIX_LEN] = {0x0d, 0x00, 0x00, 0x01};
#endif /*__FWP_NC_LAI_INFO__*/

/* MAUI_01637672 support CCWE */
#define CUSTOM_ACM_CALL_METER_WARNING_EVENT_SECONDS      (30)

//mtk00924 20051026:  +EIMG and +EMDY download to MS default folder name customization
//at most 25 characters in UCS2 format for folder name, and 0x005C and 0x0000 should be given at the end
kal_wchar CUSTOM_AT_AUDIO_DOWNLOAD_FOLDER_NAME[] = {0x0041, 0x0075, 0x0064, 0x0069, 0x006F, 0x005C, 0x0000};  /* default folder = Audio */
kal_wchar CUSTOM_AT_IMAGE_DOWNLOAD_FOLDER_NAME[] = {0x0049, 0x006D, 0x0061, 0x0067, 0x0065, 0x0073, 0x005C, 0x0000};  /* default folder = Images */

#include "ps_public_enum.h"
#include "ps_em_enum.h"

#if (defined(__GEMINI__) || defined(__SGLTE__)) && defined(__SIM_ME_LOCK__)
#include "smu_common_enums.h" //link_SML
#endif

#include "custom_l4_utility.h"


/*****************************************************************************
	If customer want to use other character instead of '?' as wild character 
	Please re-define this CUSTOM_WILD_CHAR 
	[Note!!] Wild character definition should be unique and sync with MMI display
	[Note!!] This is used only apply to L4 protocol. 
	         Customer still need to revise the definition in MMI and Phonebook 
*****************************************************************************/
#define CUSTOM_WILD_CHAR '?'

/*****************************************************************************
	If customer want to use other character instead of 'w' as auto dtmf modifier 
	Please re-define this CUSTOM_AUTO_DTMF_MODIFIER 
	[Note 1] Please always use lowercase character e.g. use 't' instead of 'T'
	[Note 2] Auto DTMF modifier definition should be unique and sync with MMI display
	[Note 3] This is used only apply to L4 protocol. 
	         Customer still need to revise the definition in MMI and Phonebook 
*****************************************************************************/
#define CUSTOM_AUTO_DTMF_MODIFIER 'w' 

/*****************************************************************************
* FUNCTION
*  	custom_wild_char()
* DESCRIPTION
*   	This function is used to return wild character definition
*	
* PARAMETERS
*	none
* RETURNS
*	wild character definition
*****************************************************************************/
kal_uint8 custom_wild_char(void)
{
	return CUSTOM_WILD_CHAR;
}


/*****************************************************************************
* FUNCTION
*  	custom_auto_dtmf_modifer()
* DESCRIPTION
*   	This function is used to return auto DTMF modifier definition
*	
* PARAMETERS
*	none
* RETURNS
*	auto dtmf modifier definition
*****************************************************************************/
kal_uint8 custom_auto_dtmf_modifier(void)
{
	return CUSTOM_AUTO_DTMF_MODIFIER;
}

/*****************************************************************************
* FUNCTION
*  	custom_ext_modem_mod_id()
* DESCRIPTION
*   	This function is used to return external modem module id
*	
* PARAMETERS
*	none
* RETURNS
*	External modem module id
*****************************************************************************/
#ifdef __EXT_MODEM__
module_type custom_ext_modem_mod_id(void)
{
	return MOD_EXT_MODEM;
}
#endif

/*****************************************************************************
* FUNCTION
*  	custom_short_string_as_call()
* DESCRIPTION
*   	This function is used to define specific short string (1 or 2 digit dial string)
*		  that should be treat as call instead of USSD. 
*	    In spec 22.030 Figure 3.5.3.2 it define short string except 2 digit starting 
*     with a '1' shall treat as USSD. However,there might be some special operator requirement 
*	    ex: "86" is a operator service call number
* PARAMETERS
*	kal_uint8 c1
*	kal_uint8 c2  
*	kal_uint8 length
* RETURNS
*	KAL_TRUE or KAL_FALSE
* KAL_TRUE is to treat this short string as call
*****************************************************************************/
kal_bool custom_short_string_as_call(kal_uint8 c1, kal_uint8 c2, kal_uint8 length)
{
	kal_bool ret_val = KAL_FALSE;
	
	//Implement specific short string parsing rule here
	#if 0 // Example case :treat "86" as call
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	
	return ret_val;
}


#define custom_is_digit(c) ((c >= '0') && (c <= '9'))

/*****************************************************************************
* FUNCTION
*  	custom_idle_string_as_call()
* DESCRIPTION
*   This function is used to define specific string input in idle screen 
*   that should be treat as call instead of USSD.
*   This check is prior to the spec 22.030 Figure 3.5.3.2 
*
* PARAMETERS
*	kal_uint8 *str  
*	kal_uint8 length
* RETURNS
*	KAL_TRUE or KAL_FALSE
* KAL_TRUE is to treat this string as call
*****************************************************************************/
kal_bool custom_idle_string_as_call(kal_uint8 *str, kal_uint8 length)
{
    kal_bool ret_val = KAL_FALSE;

    //Implement specific string parsing rule here
    if (((length == 1) && (str[0] == '0'))                          // "0 SEND"
        || ((length == 2) && ((kal_mem_cmp(str,"00",length) == 0)   // "00 SEND"
                           || (kal_mem_cmp(str,"*8",length) == 0)   // "*8 SEND"
                           || (kal_mem_cmp(str,"*0",length) == 0)   // "*0 SEND"
                           || (kal_mem_cmp(str,"#0",length) == 0))) // "#0 SEND"
        || ((length == 3) && ((kal_mem_cmp(str,"411",length) == 0)  // "411 SEND"
                           || (kal_mem_cmp(str,"*08",length) == 0)  // "*08 SEND"
                           || ((str[0] == '#') 
                            && (str[1] == '#') 
                            && custom_is_digit(str[2]))))           // "##<1 digit> SEND"
        || ((length == 4) && ((str[0] == '*') || (str[0] == '#'))
                          && custom_is_digit(str[1]) 
                          && custom_is_digit(str[2]) 
                          && custom_is_digit(str[3]))               // "*<3 digits> SEND" or "#<3 digits> SEND"
        || ((length == 5) && (str[0] == '*') 
                          && custom_is_digit(str[1]) 
                          && custom_is_digit(str[2]) 
                          && custom_is_digit(str[3]) 
                          && custom_is_digit(str[4]))               // "*<4 digits> SEND"
        || ((length == 5) && (str[0] == '#') 
                          && custom_is_digit(str[1]) 
                          && custom_is_digit(str[2]) 
                          && custom_is_digit(str[3]) 
                          && custom_is_digit(str[4])
                          && custom_is_digit(str[5]))               // "#<5 digits> SEND"
        || ((length == 9) && (str[0] == '*') && (str[1] == '*')
                          && custom_is_digit(str[2])
                          && custom_is_digit(str[3])
                          && custom_is_digit(str[4])
                          && custom_is_digit(str[5])
                          && custom_is_digit(str[6])
                          && custom_is_digit(str[7])
                          && custom_is_digit(str[8]))               // "**<7 digits> SEND"
       )
    {
        ret_val = KAL_TRUE;
    }
    else
    {
        ret_val = KAL_FALSE;
    }
    
    return ret_val;
}


/*****************************************************************************
* FUNCTION
*  	custom_is_home_plmn()
* DESCRIPTION
*	For AT+CREG and AT+CGREG network registeration report (defined in spec 27.007)
*	+CREG : 1 (registered, home network)
*	+CREG : 5 (registered, roaming)
*	The basic rule for home plmn is to check if the PLMN id equal to mcc+mnc in IMSI
*     However, there might be operators having more than one PLMN id
*     For such case, you can define them in this function
*
* PARAMETERS
*	kal_uint8* plmn
*	kal_uint8* mcc_mnc
*     kal_bool is_on_hplmn, for R7 EHPLMN
* RETURNS
*	KAL_TRUE or KAL_FALSE
* KAL_TRUE is to treat this plmn as a home PLMN
*****************************************************************************/
kal_bool custom_is_home_plmn(kal_uint8* plmn, kal_uint8* mcc_mnc, kal_bool is_on_hplmn)
{
    kal_bool custom_is_on_hplmn = KAL_FALSE;

    //if SIM card MCC+MNC is 46000/46002/46007 , current PLMN is 46000/46002/46007.  Treate as home PLMN. not roaming PLMN
    if ((kal_mem_cmp(mcc_mnc,"46000",5) == 0) || (kal_mem_cmp(mcc_mnc,"46002",5) == 0) || (kal_mem_cmp(mcc_mnc,"46007",5) == 0))
    {
        if ((kal_mem_cmp(plmn,"46000",5) == 0) || (kal_mem_cmp(plmn,"46002",5) == 0) || (kal_mem_cmp(plmn,"46007",5) == 0))
        {
            custom_is_on_hplmn = KAL_TRUE;
        }
    }

    return (custom_is_on_hplmn || is_on_hplmn);
}


/***********************************************************************************************
* FUNCTION
*     custom_disable_query_cfu_status()
* DESCRIPTION
*     In CPHS spec , it define a file to record if Call Forwarding Uncoditional (CFU) is active.
*     If CFU is active , ME show indicate user with CFU icon in MMI.
*     However, not all the SIM card havs this CFU flag file. 
*     So one SIM card might be with CFU activaed in ME A,but fail to display CFU icon when it is inserted in the ME B.
*
*     To dispaly CFU icon correctly,MTK solution might try to query CFU status right after first camping on to NW.
*     However, this might cause user MO SS operation fail due to the collision of ss operation
*
* PARAMETERS
*     none
* RETURNS
*     KAL_FALSE (default) is to query CFU status for the first time camping on to NW
*     KAL_TRUE is to disable the trick 
*************************************************************************************************/
kal_uint8 custom_disable_query_cfu_status(void)
{
#if defined(__TC01__) || defined(__SS_CPHS_QUERY_CFU_DISABLE__)
    return KAL_TRUE;  
#else	
    return KAL_FALSE;  
#endif	
}

/***********************************************************************************************
* FUNCTION
*     custom_cphs_query_cfu_status_always()
* DESCRIPTION
*     In CPHS spec , it define a file to record if Call Forwarding Uncoditional (CFU) is active.
*     If CFU is active , ME show indicate user with CFU icon in MMI.
*     However, not all the SIM card havs this CFU flag file. 
*     So one SIM card might be with CFU activaed in ME A,but fail to display CFU icon when it is inserted in the ME B.
*
*     To dispaly CFU icon correctly,MTK solution might try to query CFU status right after first camping on to NW always.
*     However, this might cause user MO SS operation fail due to the collision of ss operation
*     Available when custom_disable_query_cfu_status is KAL_FALSE.
*
* PARAMETERS
*     none
* RETURNS
*     KAL_FALSE (default) is to query CFU status when camping on to NW at the first time
*     KAL_TRUE is to query CFU status when camping on to NW
*************************************************************************************************/
kal_uint8 custom_cphs_query_cfu_status_always(void)
{
#if defined(__SS_CPHS_QUERY_CFU_ALWAYS__)
    return KAL_TRUE;  
#else	
    return KAL_FALSE;  
#endif	
}

/***********************************************************************************************
* FUNCTION
*     custom_cfu_store_ftn_in_efcfis()
* DESCRIPTION
*     Store CFU Forwarded-To-Number(FTN) to SIM EFcfis
*     It may cause CFU machine test failure because of redundant saving FTN transaction
* PARAMETERS
*     none
* RETURNS
*     KAL_FALSE (default) do not store CFU FTN in SIM
*     KAL_TRUE            do     store CFU FTN in SIM
*************************************************************************************************/
kal_uint8 custom_cfu_store_ftn_in_efcfis(void)
{
#ifdef __CFU_FTN_IN_EFCFIS__
    return KAL_TRUE;  
#else
    return KAL_FALSE;  
#endif
}

/***********************************************************************************************
* FUNCTION
*     custom_allow_at_write_imei()
* DESCRIPTION
*     To en/dis-able IMEI writing via AT command AT+EGMR with <op>=1 and <type>=7 or 10
*
* PARAMETERS
*     none
* RETURNS
*     KAL_FALSE is to prevent AT+EGMR to write IMEI
*     KAL_TRUE (default) is to allow the functionality 
*************************************************************************************************/
kal_uint8 custom_allow_at_write_imei(void)
{
    return KAL_TRUE;
}

/***********************************************************************************************
* FUNCTION
*     custom_sms_fdn_check_da_only()
* DESCRIPTION
*     According to spec 22.101 A.25 , 
*     For SMS,both SCA(Service Center address) and DA(Destination Address) shall be checked when FDN is enabled
*     There might be special requirement for sms fdn check to check DA only.
*
* PARAMETERS
*     none
* RETURNS
*     KAL_TRUE is to ignore fdn check for sca, only check for da
*     KAL_FALSE (default) is to obey the spec. Do fdn check for both sca and da
************************************************************************************************/
kal_uint8 custom_sms_fdn_check_da_only(void)
{
#ifdef __SMS_FDN_CHECK_DA_ONLY__
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}


/*****************************************************************************
* FUNCTION
*  	custom_ath_for_dialup_timer()
* DESCRIPTION
*   	This function is used to define time duration of handling ath for dialup
*	The unit is 0.1 sec , Current default value is 40 sec  (i.e. 400 x 0.1 sec)
* PARAMETERS
*	none
* RETURNS
*	time duration of handling ath for dialup
*****************************************************************************/
kal_uint16 custom_ath_for_dialup_timer(void)
{
    return 0;
}


/*****************************************************************************
* FUNCTION
*   l4_custom_battery_cind_value()
*
* DESCRIPTION
*   This function is used to convert battery_voltage(battery_level_enum)
*   to cind value 0~5 (battery cind range 0~5 is defined in HFP and 27.007 spec)
*   battery cind_value is the response of AT+CIND or +CIEV:<battery_ind>,<cind_value> 
*
* PARAMETERS
*	battery_voltage      IN
*
* RETURNS
*	cind value (according to HFP and 27.007 spec, battery cind value is 0~5)
*****************************************************************************/
kal_uint8 l4_custom_battery_cind_value(kal_uint8 battery_voltage)
{
    kal_uint8 cind_value;

    /* convert battery_voltage(battery_level_enum) to spec defined cind value (0~5) */
    if (battery_voltage > 5)
    {
        cind_value = 5;
    }
    else if (battery_voltage > 0)
    {
        cind_value = battery_voltage - 1;
    }
    else
    {
        cind_value = 0;
    }
	
    return cind_value;	
}

/*****************************************************************************
 * FUNCTION
 *  l4_custom_is_phb_valid_char
 * DESCRIPTION
 *  This function is to check if the chars of the input str are valid or not
 * PARAMETERS
 *  number		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool l4_custom_is_phb_valid_char(kal_uint8 ch)
{
    if ( !((ch >= '0' && ch <= '9') || ch == 'p' || 
        ch == custom_wild_char() || ch == custom_auto_dtmf_modifier() ||
        ch == '+' || ch == '*' || ch == '#') )
    {
            return KAL_FALSE;    
    }

    return KAL_TRUE;
}

/*****************************************************************************
* FUNCTION
*  custom_disable_modem_auto_startup()
* DESCRIPTION
*
* PARAMETERS
*	none
* RETURNS
*   TRUE:  disable modem auto boot up. need AP side trigger
*   FALSE: modem auto boot up/attach network
*       cfun_state=1:  auto boot up in normal mode
*       cfun_state=4:  auto boot up in flight mode
*****************************************************************************/
kal_bool custom_disable_modem_auto_startup(kal_uint8 *cfun_state)
{
    *cfun_state = 1;

    #if defined(__MODEM_CARD__) && defined(IC_MODULE_TEST)
        return KAL_FALSE;
    #endif

    if ((query_ps_conf_test_mode()==PS_CONF_TEST_FACTORY) && (query_ps_conf_test_profile_setting() & FACTORY_MODEM_AUTO_BOOT_AND_AUTO_ANSWER_BIT_FOR_L4C))
    {
        return KAL_FALSE;
    }

    #if defined(__MODEM_AUTO_STARTUP_TO_FLIGHT_MODE__)
        *cfun_state = 4;
        return KAL_FALSE;
    #endif

    #if defined(__DISABLE_MODEM_AUTO_STARTUP__) || defined(__SMART_PHONE_MODEM__)
        return KAL_TRUE;
    #endif

    return KAL_FALSE;
}

/*****************************************************************************
* FUNCTION
*   l4_custom_get_cscs_support_string()
*
* DESCRIPTION
*   This function is used to get the supportted list of the AT+CSCS
*
* PARAMETERS
*	none
*
* RETURNS
*	supported list string of AT+CSCS
*****************************************************************************/
kal_char* l4_custom_get_cscs_support_string(void)
{
    #ifdef __PHB_0x81_SUPPORT__ 
    return "+CSCS: (\"IRA\", \"GSM\", \"HEX\", \"PCCP437\", \"8859-1\", \"UCS2\", \"UCS2_0X81\")";
    #else
    return "+CSCS: (\"IRA\", \"GSM\", \"HEX\", \"PCCP437\", \"8859-1\", \"UCS2\")";
    #endif
}

/*****************************************************************************
* FUNCTION
*   l4_custom_is_supportted_cscs()
*
* DESCRIPTION
*   This function is used to check if the input name of cscs is support or not
*   which let customer decide what cscs should be supportted
*
* PARAMETERS
*	none
*
* RETURNS
*	supported list string of AT+CSCS
*****************************************************************************/
kal_bool l4_custom_is_supportted_cscs(kal_char* string)
{
    return KAL_TRUE;
}


/*****************************************************************************
* FUNCTION
*   custom_disallow_gprs_dialup_when_ms_busy()
*
* DESCRIPTION
*   This function is to configure "if we allow gprs dialup when MS is busy(in call)"
*   in Bluetooth SPP port
*   If return KAL_TRUE, we will response 'BUSY' for ATD*99# when MS busy (in call) 
*   If return KAL_FALSE, we allow ATD*99# to be processed when MS is in call
*
*   For BQB DUN testcase APS/BV/02.
*   It request MS to response 'BUSY' for GPRS dialup(ATD*99#) when MS is in call. 
*
* PARAMETERS
*	none
*
* RETURNS
*	KAL_TRUE or KAL_FASLE
*****************************************************************************/
kal_bool custom_disallow_gprs_dialup_when_ms_busy(void)
{
    return KAL_TRUE;
}


/*****************************************************************************
* FUNCTION
 *  custom_check_keypad_code
 * DESCRIPTION
 *  This function is used to convert the input of AT command (ex. AT+CKPD) 
 *  to the Device Key
 *  Customer can use this function to override the meaning of a key from AT command
 *  If customer didn't handle the key, we will check our default key mapping
 *  
 * PARAMETERS
 *  key         [IN]        input keys from command
 *  keycode   [OUT]     a output device key which is converted from key
 * RETURNS
 *  A pointer to the "key" which is unhandled
 *****************************************************************************/
kal_uint8* custom_check_keypad_code(kal_uint8 *key, kal_uint8 *keycode)
{
    /* EXAMPLE
    if (*key == 'y' || *key=='Y')
    {
        *keycode = 57; // DEVICE_KEY_Y defined in the kbd_table.h
        key++;
    }
    else if(*key == ':')
    {
        if(*(key+1) == 'j' || *(key+1) == 'J' )
        {
            *keycode = 42; // DEVICE_KEY_J defined in the kbd_table.h
            key += 2;
        }
    }
    */

    return key;
}


/*****************************************************************************
* FUNCTION
*   custom_remove_cgsms_constraint()
*
* DESCRIPTION
*   Regarding to AT+CGSMS = <service> to set service parameter to send SMS.
*   We don't allow to set <service> = 0 (PS only).
*   This is to prevent MO SMS fail due to no GPRS service available
*   We only allow to set <service> if TEST SIM is inserted (for FTA test)
*
*   If you want to remove such constraint, please modifty the function to return TRUE
* PARAMETERS
*	none
*
* RETURNS
*	KAL_TRUE or KAL_FASLE
*****************************************************************************/
kal_bool custom_remove_cgsms_constraint(void)
{
#if 0
#if defined(__CGSMS_FULL_SUPPORT__)
/* under construction !*/
#else
/* under construction !*/
#endif
#else
        return KAL_TRUE;
#endif
}

/*****************************************************************************
* FUNCTION
*   custom_get_supported_bands()
*
* DESCRIPTION
*   get the supported bands of the protocol
*
* PARAMETERS
*   gsm_bands   returned gsm bands 
*   umts_bands  returned umts bands 
*
* RETURNS
*   none
*****************************************************************************/
void custom_get_supported_bands(kal_uint32 *gsm_bands, kal_uint32 *umts_bands, kal_uint32 *lte_band)
{
    *gsm_bands = 0
        #if defined(__EGSM900__) 
            | 0x02  //BAND_900  
        #endif
        #if defined(__DCS1800__)  
            | 0x08  //BAND_1800 
        #endif                       
        #if defined(__GSM850__)   
            | 0x80  //BAND_850   
        #endif 
        #if defined(__PCS1900__)  
            | 0x10  //BAND_1900  
        #endif 
        ;

    *umts_bands = 0 
        #if defined(__UMTS_TDD128_BAND_A__)
            | 0x00000001    
        #endif  
        #if defined(__UMTS_TDD128_BAND_B__)
            | 0x00000002    
        #endif  
        #if defined(__UMTS_TDD128_BAND_C__)
            | 0x00000004    
        #endif  
        #if defined(__UMTS_TDD128_BAND_D__)
            | 0x00000008    
        #endif  
        #if defined(__UMTS_TDD128_BAND_E__)
            | 0x00000010    
        #endif  
        #if defined(__UMTS_TDD128_BAND_F__)
            | 0x00000020    
        #endif  
        ;

#if defined (__MTK_UL1_FDD__)
#if !defined (UL1_NOT_PRESENT)
//#if !defined (__HSUPA_SUPPORT__) && !defined (__HSDPA_SUPPORT__) && defined(__MTK_TARGET__)
#if defined(__MTK_TARGET__)
{
    kal_uint32 tmp_umts_bands=0;
    
    UL1D_UeBandCapabilityEx(&tmp_umts_bands);
    //UL1D_UeBandCapability((kal_uint16*)&tmp_umts_bands);
    *umts_bands = tmp_umts_bands;
}
#endif
#endif
#endif

#ifdef __MTK_TARGET__
#ifdef __LTE_RAT__
{
    mrs_eas_max_band_cap_for_user(lte_band);
}
#endif
#endif
}

#ifdef __UMTS_RAT__
/*  Gordon 20090604 :For signal strength modification */
/*  when RSCP < -72 and original signal strength > 9, new formula defines three RSCP thresholds for re-calculating a new signal strength */
#define CUSTOM_3G_SIGNAL_LEVEL_MINUS_1_THRESHOLD (-72)
#define CUSTOM_3G_SIGNAL_LEVEL_MINUS_2_THRESHOLD  (-88)
#define CUSTOM_3G_SIGNAL_LEVEL_MINUS_3_THRESHOLD  (-104)
/*  when RSCP < -72 and original signal strength > 9, signal strength values (8,11,14) are mapped to signal level (1,2,3) */
#define CUSTOM_3G_SIGNAL_LEVEL_1_MAX_STRENGTH (8)
#define CUSTOM_3G_SIGNAL_LEVEL_2_MAX_STRENGTH (11)
#define CUSTOM_3G_SIGNAL_LEVEL_3_MAX_STRENGTH (14)

/*  20101028: Adjust TDD RSCP to CSQ mapping */ 
#ifdef __UMTS_TDD128_MODE__
#define CUSTOM_3G_TDD_RSCP_THRESHOLD_1 (-51)
#define CUSTOM_3G_TDD_RSCP_THRESHOLD_2 (-75)
#define CUSTOM_3G_TDD_RSCP_THRESHOLD_3 (-85)
#define CUSTOM_3G_TDD_RSCP_THRESHOLD_4 (-95)
#define CUSTOM_3G_TDD_RSCP_THRESHOLD_5 (-108)

#define CUSTOM_3G_TDD_CSQ_LEVEL_1 (31)
#define CUSTOM_3G_TDD_CSQ_LEVEL_2 (15)
#define CUSTOM_3G_TDD_CSQ_LEVEL_3 (7)
#define CUSTOM_3G_TDD_CSQ_LEVEL_4 (3)
#define CUSTOM_3G_TDD_CSQ_LEVEL_5 (0)
#endif /* __UMTS_TDD128_MODE__ */
#endif /* __UMTS_RAT__ */

/*****************************************************************************
* FUNCTION
*   custom_signal_strength_in_ts27007()
*
* DESCRIPTION
*   convert a dbm value to level value defined in 27.007 +CSQ
*
* PARAMETERS
*    kal_int32 strength_in_dbm, any strength value in dbm (Ex. RSCP, RSSI, EcN0...)
*
* RETURNS
*	level value: ranged from 0 to 31, 99 means invalid/un-available
*****************************************************************************/
kal_uint8 custom_signal_strength_in_ts27007(kal_int32 strength_in_dbm)
{
    kal_uint8 level = 99;
	if (strength_in_dbm <= -113)
	{
	    level = 0;
	}
	else if (strength_in_dbm >= -51)
	{
	    level = 31;
	}
	else
	{						
    	level = (strength_in_dbm + 113) / 2; 
	}	
	return level;
}

/*****************************************************************************
* FUNCTION
*   custom_signal_strength_cesq_level_to_raw()
*
* DESCRIPTION
*   This function is used to convert signal level to raw qdBm according to 3GPP 27.007 +CESQ definnition
*   
* PARAMETERS
*	none
*
* RETURNS
*   
*****************************************************************************/
kal_int32 custom_signal_strength_cesq_level_to_raw(l4_cesq_param_enum type, kal_uint8 signal_level)
{
    kal_int32 raw_in_qdbm=1;

    if (type == L4_GERAN_RXLEVEL)
    {
        if (signal_level >= 0 && signal_level <= 63)
        {
            raw_in_qdbm = (signal_level << 2) - 444;
        }
    }
    else if (type == L4_GERAN_BER)
    {
        // N/A
    }
    else if (type == L4_UTRA_RSCP)
    {
        if (signal_level >= 0 && signal_level <= 96)
        {
            raw_in_qdbm = (signal_level << 2) - 484;
        }
    }
    else if (type == L4_UTRA_ECNO)
    {
        if (signal_level >= 0 && signal_level <= 49)
        {
            raw_in_qdbm = (signal_level - 49) << 1;
        }
    }
    else if (type == L4_EUTRA_RSRQ)
    {
        if (signal_level >= 0 && signal_level <= 34)
        {
            raw_in_qdbm = (signal_level - 40) << 1;
        }
    }
    else if (type == L4_EUTRA_RSRP)
    {
        if (signal_level >= 0 && signal_level <= 97)
        {
            raw_in_qdbm = (signal_level << 2) - 564;
        }
    }

    return raw_in_qdbm;
}

/*****************************************************************************
* FUNCTION
*   custom_signal_strength_raw_to_cesq_level()
*
* DESCRIPTION
*   This function is used to convert qdBm to signal level according to 3GPP 27.007 +CESQ definnition
*   
* PARAMETERS
*	none
*
* RETURNS
*   
*****************************************************************************/
kal_uint8 custom_signal_strength_raw_to_cesq_level(l4_cesq_param_enum type, kal_int32 raw_in_qdbm)
{
    kal_uint8 signal_level;
    //kal_int32 raw_in_dbm = (raw_in_qdbm / 4);

    if (type == L4_GERAN_RXLEVEL)
    {
        if (raw_in_qdbm == 1)
        {
            signal_level = 99;
        }
        else if (raw_in_qdbm < -440)
        {
            signal_level = 0;
        }
        else if (raw_in_qdbm >= -192)
        {
            signal_level = 63;
        }
        else
        {
            signal_level = (raw_in_qdbm + 444) >> 2;
        }
    }
    else if (type == L4_GERAN_BER)
    {
        if (raw_in_qdbm >= 0 && raw_in_qdbm <= 7)
        {
            signal_level = raw_in_qdbm;
        }
        else
        {
            signal_level = 99;
        }
    }
    else if (type == L4_UTRA_RSCP)
    {
        if (raw_in_qdbm == 1)
        {
            signal_level = 255;
        }
        else if (raw_in_qdbm < -480)
        {
            signal_level = 0;
        }
        else if (raw_in_qdbm >= -100)
        {
            signal_level = 96;
        }
        else
        {
            signal_level = (raw_in_qdbm + 484) >> 2;
        }
    }
    else if (type == L4_UTRA_ECNO)
    {
        if (raw_in_qdbm == 1)
        {
            signal_level = 255;
        }
        else if (raw_in_qdbm < -96)
        {
            signal_level = 0;
        }
        else if (raw_in_qdbm >= 0)
        {
            signal_level = 49;
        }
        else
        {
            signal_level = (raw_in_qdbm >> 1) + 49;
        }
    }
    else if (type == L4_EUTRA_RSRQ)
    {
        if (raw_in_qdbm == 1)
        {
            signal_level = 255;
        }
        else if (raw_in_qdbm < -78)
        {
            signal_level = 0;
        }
        else if (raw_in_qdbm >= -12)
        {
            signal_level = 34;
        }
        else
        {
            signal_level = (raw_in_qdbm >> 1) + 40;
        }
    }
    else if (type == L4_EUTRA_RSRP)
    {
        if (raw_in_qdbm == 1)
        {
            signal_level = 255;
        }
        else if (raw_in_qdbm < -560)
        {
            signal_level = 0;
        }
        else if (raw_in_qdbm >= -176)
        {
            signal_level = 97;
        }
        else
        {
            signal_level = (raw_in_qdbm + 564) >> 2;
        }
    }

    return signal_level;
}


/*****************************************************************************
* FUNCTION
*   custom_signal_strength_raw_to_csq_level()
*
* DESCRIPTION
*   convert 2G/3G signal strength raw data to level value defined in 27.007 +CSQ
*
* PARAMETERS
*    kal_uint8 rat            radio access technology (2G/3G)
*	 kal_int32 rssi_in_qdbm   2G/3G raw data   
*    kal_int32 RSCP_in_qdbm   3G raw data
*    kal_int32 EcN0_in_qdbm   3G raw data
*    kal_uint8 ber            2G/3G raw data
*	 kal_uint8 current_band   2G raw data
*
* RETURNS
*	level value: ranged from 0 to 31, 99 means invalid/un-available
*****************************************************************************/
kal_uint8 custom_signal_strength_raw_to_csq_level(
                kal_uint8 rat, 
                kal_int32 rssi_in_qdbm, 
                kal_int32 RSCP_in_qdbm,
                kal_int32 EcN0_in_qdbm,
                kal_uint8 ber,
                kal_uint8 current_band,
                kal_int32 RSRQ_in_qdbm,
                kal_int32 RSRP_in_qdbm)
{
    kal_int32 level = 99;
	if (rat == L4C_RAT_GSM)
	{
	    /* 2G conversion */
		if (rssi_in_qdbm != 1)
		{
		    /* refer to 27.007 AT+CSQ */
			level = custom_signal_strength_in_ts27007(rssi_in_qdbm / 4);
		}
	}
#ifdef __UMTS_RAT__	
    else if (rat == L4C_RAT_UMTS)
    {
    #ifdef __UMTS_TDD128_MODE__ /* 3G TDD conversion */	    
        #if defined(__OP01__) && defined(__MMI_FMI__) //MAUI_02973870, ALPS00056754, mtk02285
	    {
	        kal_int32 RSCP = RSCP_in_qdbm / 4;
			level = 199; //199 means unknown
			if (RSCP <= -116)
			{
			    level = 100;
			}
			else if (RSCP >= -25)
			{
			    level = 191;
			}
			else
			{
				level = RSCP + 216;
			}
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif		
	    }
	    #else /* Not-- defined(__OP01__) && defined(__MMI_FMI__) */ 
		{
		#if 0
/* under construction !*/
/* under construction !*/
        #else
		    kal_int32 RSCP = RSCP_in_qdbm / 4;

			if (RSCP >= CUSTOM_3G_TDD_RSCP_THRESHOLD_1)
			{
			    level = 31;
			}
			else if (RSCP >= CUSTOM_3G_TDD_RSCP_THRESHOLD_2)
			{
			    level = (CUSTOM_3G_TDD_CSQ_LEVEL_2+1) + 
					(CUSTOM_3G_TDD_CSQ_LEVEL_1-CUSTOM_3G_TDD_CSQ_LEVEL_2-1) * (RSCP-CUSTOM_3G_TDD_RSCP_THRESHOLD_2) / 
                    (CUSTOM_3G_TDD_RSCP_THRESHOLD_1-CUSTOM_3G_TDD_RSCP_THRESHOLD_2);
			}
			else if (RSCP >= CUSTOM_3G_TDD_RSCP_THRESHOLD_3)
			{
			    level = (CUSTOM_3G_TDD_CSQ_LEVEL_3+1) + 
					(CUSTOM_3G_TDD_CSQ_LEVEL_2-CUSTOM_3G_TDD_CSQ_LEVEL_3-1) * (RSCP-CUSTOM_3G_TDD_RSCP_THRESHOLD_3) / 
                    (CUSTOM_3G_TDD_RSCP_THRESHOLD_2-CUSTOM_3G_TDD_RSCP_THRESHOLD_3-1);
			}
			else if (RSCP >= CUSTOM_3G_TDD_RSCP_THRESHOLD_4)
			{
			    level = (CUSTOM_3G_TDD_CSQ_LEVEL_4+1) + 
					(CUSTOM_3G_TDD_CSQ_LEVEL_3-CUSTOM_3G_TDD_CSQ_LEVEL_4-1) * (RSCP-CUSTOM_3G_TDD_RSCP_THRESHOLD_4) / 
                    (CUSTOM_3G_TDD_RSCP_THRESHOLD_3-CUSTOM_3G_TDD_RSCP_THRESHOLD_4-1);
			}
			else if (RSCP >= CUSTOM_3G_TDD_RSCP_THRESHOLD_5)
			{
			    level = (CUSTOM_3G_TDD_CSQ_LEVEL_5+1) + 
					(CUSTOM_3G_TDD_CSQ_LEVEL_4-CUSTOM_3G_TDD_CSQ_LEVEL_5-1) * (RSCP-CUSTOM_3G_TDD_RSCP_THRESHOLD_5) / 
                    (CUSTOM_3G_TDD_RSCP_THRESHOLD_4-CUSTOM_3G_TDD_RSCP_THRESHOLD_5-1);
			}
			else
			{
			    level = 0;
			}			
		#endif		
		}
        #endif /* defined(__OP01__) && defined(__MMI_FMI__) */
		
    #else /* 3G FDD conversion */
	    
		/* Alva 20081210: signal strength = (Ec/N0 + 25) + (RSCP + 120) / 8, range: 0 ~ 31 */
		level =
		    ((EcN0_in_qdbm / 4) + 25) + 
		    (((RSCP_in_qdbm / 4) + 120) / 8);

		if (level > 31)
		{
		    level = 31;
		}

		/* Gordon 20090604: To reflect the real network environment more accurately, 
		 *  based on the experiment results, we modify the calculated signal level for MMI display 
		 *  When RSCP < -72 and the original signal strength > 9, 
		 *  a new formula is defined to modify the original signal strength.
		 *  More detailed information are shown in the excel file for the new formula */

		if (level >= (CUSTOM_3G_SIGNAL_LEVEL_1_MAX_STRENGTH+1))
		{
			kal_int32 RSCP_in_dbm = RSCP_in_qdbm / 4;
			if (RSCP_in_dbm < CUSTOM_3G_SIGNAL_LEVEL_MINUS_3_THRESHOLD) 
			{
				level = CUSTOM_3G_SIGNAL_LEVEL_1_MAX_STRENGTH;
			}
			else if (RSCP_in_dbm < CUSTOM_3G_SIGNAL_LEVEL_MINUS_2_THRESHOLD) 
			{
				if ((CUSTOM_3G_SIGNAL_LEVEL_3_MAX_STRENGTH) >= level)
				{
					level=CUSTOM_3G_SIGNAL_LEVEL_1_MAX_STRENGTH;
				}
				else
				{
					level=CUSTOM_3G_SIGNAL_LEVEL_2_MAX_STRENGTH; 
				}
			}
			else if (RSCP_in_dbm < CUSTOM_3G_SIGNAL_LEVEL_MINUS_1_THRESHOLD) 
			{
				if (CUSTOM_3G_SIGNAL_LEVEL_2_MAX_STRENGTH >= level)
				{
					level=CUSTOM_3G_SIGNAL_LEVEL_1_MAX_STRENGTH;
				}
				else if (CUSTOM_3G_SIGNAL_LEVEL_3_MAX_STRENGTH >= level)
				{
					level=CUSTOM_3G_SIGNAL_LEVEL_2_MAX_STRENGTH;
				}
				else
				{
					level=CUSTOM_3G_SIGNAL_LEVEL_3_MAX_STRENGTH;   
				}
			}
		}
    #endif /* __UMTS_TDD128_MODE__ */
    }
#endif /* __UMTS_RAT__ */
#ifdef __LTE_RAT__
    else if (rat == L4C_RAT_LTE)
    {
        if (RSRP_in_qdbm != 1)
        {
            level = custom_signal_strength_raw_to_cesq_level(L4_EUTRA_RSRP, RSRP_in_qdbm) >> 2;
        }
    }
#endif

	return (kal_uint8) level;
}


/*****************************************************************************
* FUNCTION
*   custom_signal_strength_raw_to_ciev_signal_level()
*
* DESCRIPTION
*   convert signal strength raw data to level <val> in +CIEV:<signal>,<val>
*
* PARAMETERS
*    kal_uint8 rat            radio access technology (2G/3G)
*	 kal_int32 rssi_in_qdbm   RSSI raw data
*    kal_int32 RSCP_in_qdbm   3G raw data
*    kal_int32 EcN0_in_qdbm   3G raw data
*    kal_uint8 ber            2G/3G raw data
*	 kal_uint8 current_band   2G raw data
*
* RETURNS
*	level value: ranges from 0 to 5
*****************************************************************************/
kal_uint8 custom_signal_strength_raw_to_ciev_signal_level(
            kal_uint8 rat, 
            kal_int32 rssi_in_qdbm, 
            kal_int32 RSCP_in_qdbm,
            kal_int32 EcN0_in_qdbm,
            kal_uint8 ber,
            kal_uint8 current_band,
            kal_int32 RSRQ_in_qdbm,
            kal_int32 RSRP_in_qdbm)
{
    kal_uint8 rx_level = 0;
    kal_uint8 signal_ind;

#if defined(__OP01__) && defined(__UMTS_TDD128_MODE__) && defined(__MMI_FMI__) //MAUI_02973870, ALPS00056754, mtk02285
    /* CMCC TD requirement */
    if (rat == L4C_RAT_GSM)
    {
        if (rssi_in_qdbm == 1)
        {
		    rx_level = 99;
        }
		else
		{
    		rx_level = custom_signal_strength_in_ts27007(rssi_in_qdbm / 4);
		}        
    }
	else if (rat == L4C_RAT_UMTS)
	{
	    rx_level = custom_signal_strength_in_ts27007(RSCP_in_qdbm / 4);
	}
    else if (rat == L4C_RAT_LTE)
    {
        if (RSRP_in_qdbm != 1)
        {
            rx_level = custom_signal_strength_raw_to_cesq_level(L4_EUTRA_RSRP, RSRP_in_qdbm) >> 2;
        }
    }
#else
    rx_level = custom_signal_strength_raw_to_csq_level(rat, rssi_in_qdbm, RSCP_in_qdbm, EcN0_in_qdbm, ber, current_band, RSRQ_in_qdbm, RSRP_in_qdbm);
#endif /* defined(__OP01__) && defined(__UMTS_TDD128_MODE__) && defined(__MMI_FMI__) */

    if (rx_level == 0 || rx_level == 99)
    {
        signal_ind = 0;
    }
    else if (rx_level < 6)
    {
        signal_ind = 1;
    }
    else if ((rx_level >= 6) && (rx_level < 12))
    {
        signal_ind = 2;
    }
    else if ((rx_level >= 12) && (rx_level < 18))
    {
        signal_ind = 3;
    }
    else if ((rx_level >= 18) && (rx_level < 24))
    {
        signal_ind = 4;
    }
    else if (rx_level >= 24)
    {
        signal_ind = 5;
    }
    else
    {
        signal_ind = 0;
    }

    return signal_ind;
}


/*****************************************************************************
* FUNCTION
*   custom_ciev_signal_variance()
*
* DESCRIPTION
*   This function is used to set the ignorable difference between two consequent
*   +CIEV Signal Strength URC for Bluetoth Hands-Free.
*
* PARAMETERS
*	none
*
* RETURNS
*   A kal_uint8 value 0 ~ 5 indicating the ignorable difference bwtween two <val>
*   in +CIEV:<signal>,<val>. If the return is larger than 0, the <val> different 
*   to the last reported +CIEV Signal Strength <val> which is smaller then the 
*   return would be ignored.
*   If the return value is 0, the +CIEV Signal Strength URC is reported as usual
*****************************************************************************/
kal_uint8 custom_ciev_signal_variance(void)
{
    /* The default return value is 0 which means no filter.
       If return value is 5, the +CIEV:<signal>,<val> is turn off
    */
    return 0;
}


/*****************************************************************************
* FUNCTION
*   custom_disable_gprs_csd_dialup()
*
* DESCRIPTION
*   This function is used to disable GPRS and CSD dial up functionality
*
* PARAMETERS
*	none
*
* RETURNS
*   KAL_TRUE is to disable gprs and csd dialup
*   KAL_FALSE has no effect on these functionality (default)
*****************************************************************************/
kal_bool custom_disable_gprs_csd_dialup(void) //MAUI_02600165
{
    return KAL_FALSE;
}

#if defined(__ATCMD_ONOFF_CHECK__)
/*****************************************************************************
* FUNCTION
*   custom_check_is_atcmd_allowed()
*
* DESCRIPTION
*   check if the command is allowed by custom or not
*
* PARAMETERS
*   cmd_id   [IN]   AT command enum defined in the ps\l4\atci\include\at_cmd.def
*
* RETURNS
*   KAL_TRUE: could be executed, 
*   KAL_FLASE: could not be executed
*****************************************************************************/
kal_bool custom_check_is_atcmd_allowed(rmmi_cmd_id_enum cmd_id)
{    
    /* the following example disallowed executing 
    * the command AT+EADP
    */
    /*if (cmd_id == RMMI_CMD_ATEADP) 
    {
        return KAL_FALSE;
    }*/
    return KAL_TRUE;
}
#endif

#ifdef __MOD_TCM__
/*****************************************************************************
* FUNCTION
*   custom_l4c_gprs_when_needed_timer()
*
* DESCRIPTION
*   This function is used to define GPRS when needed timer value
*   The unit is 100ms. Ex. 20 => 20 * 100ms => 2 seconds
*   Default value = 20 (2 seconds)
*   Maximum value = 255 (Due to kal_uint8 limit, the max is about 25.5 sec)
* PARAMETERS
*	none
*****************************************************************************/
kal_uint8 custom_l4c_gprs_when_needed_timer(void) 
{
    const kal_uint8 GPRS_DETACH_TIMER = 20;
    return GPRS_DETACH_TIMER;
} // MAUI_02598495, custom gprs detach timer

/*****************************************************************************
* FUNCTION
*   custom_l4c_ndis_fdn_enable()
*
* DESCRIPTION
*   This function is used to enable/disable FDN check before NDIS setup
*   0. the FDN check number is "*99#"
*   1. if it returns KAL_TRUE, then L4C checks PHB approve result to decide doing PDP activation or not,
*       - if PHB approve fails, then it does NOT send out PDP activation request
*       - if PHB approve succeeds, then it sends out PDP activation request
*
*   2. if it returns KAL_FALSE, the L4C always SKIPS PHB approve result and always send out PDP activation request
* PARAMETERS
*	none
*****************************************************************************/
kal_bool custom_l4c_ndis_fdn_enable(void)
{
#if 1
    return KAL_TRUE; //check FDN
#else
/* under construction !*/
#endif
}

/*****************************************************************************
* FUNCTION
*   custom_l4c_psbearer_indicate()
*
* DESCRIPTION
*   This function is used to enable/disable +PSBEARER: <x>, <y> indication
*   KAL_TRUE: Yes
*   KAL_FALSE: No
*
* PARAMETERS
*	none
*****************************************************************************/
kal_uint8 custom_l4c_psbearer_indicate(void)
{
    return KAL_FALSE;
}

#endif /* __MOD_TCM__ */

/*****************************************************************************
* FUNCTION
*   custom_l4c_max_poweroff_retry()
*
* DESCRIPTION
*   This function is used to define maximal waitting time for SIM power off while MS is going to shutdown
*   The unit is second. Ex. 2 => 2 seconds
*   Default value = 8 (seconds)
*   Maximum value = 255 (Due to kal_uint8 limit, the max is about 255 sec)
* PARAMETERS
*	none
*****************************************************************************/
kal_uint8 custom_l4c_max_poweroff_retry(void)
{
    return 8;
}


#ifdef __SAT__
/*****************************************************************************
* FUNCTION
*   custom_l4c_sat_ton_npi_transform()
*
* DESCRIPTION
*   This function is used to transform the TON/NPI of SAT send SS/CALL from SIM
*   
* PARAMETERS
*	raw_data    [IN] raw data from SIM
*
* RETURNS
*   the new data transformed from raw_data
*****************************************************************************/
kal_uint8 custom_l4c_sat_ton_npi_transform(kal_uint8 raw_data)
{
    kal_uint8 ret_val = 0x81;

    /* MAUI_02660770: return 0x91 if raw_data is between 0x90 to 0x9f;
     * Otherwise return 0x81
     */
    if ((raw_data >= 0x90) && (raw_data <= 0x9f))
    {
        ret_val = 0x91;
    }
    
    return ret_val;
}
#endif /* __SAT__ */

#ifdef __AMR_WB_WHITE_LIST__
/*****************************************************************************
* FUNCTION
*  custom_check_white_list
* DESCRIPTION
*  This function is for customize PLMN in the wihte list, on which CC support AMR_WB
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void custom_check_white_list(kal_bool * is_gsm_white_list,kal_bool * is_umts_white_list,kal_uint32 plmn_id)
{
#ifdef __AMR_WB_FOR_T_MOBILE__   
    /* *is_gsm_white_list =KAL_TRUE; means that MS support AMR_WB in 2G rat of the selected PLMN*/
    /*check 2G white_list plmn [byte2:mcc1,mcc2; byte1:mcc3,mnc1; byte0:mnc2,mnc3]*/
    switch(plmn_id)
    {
    /*Please add white plmn list as specified below:
        case 0x0046000f:
        case 0x0046002f:
            *is_gsm_white_list =KAL_TRUE;
            break;
    */            
        default:
   	      *is_gsm_white_list =KAL_FALSE;
            break;
    }  	
#else
#ifdef __AMR_GSM_IOT_SUPPORT__
    *is_gsm_white_list =KAL_TRUE;
#else
    *is_gsm_white_list =sbp_query_md_feature(SBP_AMR_WB_GSM);
#endif 
#endif    
#ifdef __OP11__
    /* *is_umts_white_list =KAL_TRUE; means that MS support AMR_WB in 3G rat of the selected PLMN*/   	
    /*check UMTS white_list plmn [byte2:mcc1,mcc2; byte1:mcc3,mnc1; byte0:mnc2,mnc3]*/
    switch(plmn_id)	
    {
    /*Please add white plmn list as specified below:       
        case 0x0046000f:
        case 0x0046002f:
            *is_umts_white_list =KAL_TRUE;
            break;
    */            
        default:
   	      *is_umts_white_list =KAL_FALSE;
   	      break;
    }
#else
    *is_umts_white_list =sbp_query_md_feature(SBP_AMR_WB_UMTS);    
#endif    
    return ;
}
#endif

/*****************************************************************************
* FUNCTION
*  cm_p_w_switch
* DESCRIPTION
*   This function is used to define if "P"(pause) and "W"(wait for user command)
*   of DTMF separator is switched or not
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_bool cm_dtmf_p_w_switch (void)
{
   return (CM_DTMF_P_W_SWITCH_FLAG);
}

#ifdef __FWP_NC_LAI_INFO__
/*****************************************************************************
* FUNCTION
*  cm_get_cell_lock_string
* DESCRIPTION
*   This function is used to let customer configure cell lock prefix and also
*   change prefix length, CELL_LOCK_PREFIX_LEN
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 cm_get_cell_lock_string (kal_uint8** prefix)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	*prefix = &CELL_LOCK_PREFIX[0];
	return CELL_LOCK_PREFIX_LEN;
}
#endif /*__FWP_NC_LAI_INFO__*/

/*****************************************************************************
* FUNCTION
*  customer_define_codec_priority
* DESCRIPTION
*   This function is used to define the priority customer prefered
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/
const kal_uint8 customer_define_codec_priority[SUPPORTED_2G_CODEC_NUM]=
{
#ifdef __CUSTOM_CODEC_PRIORITY__
    CSMCC_FR_AMRWB_V5,CSMCC_FR_V3,CSMCC_HR_V3,CSMCC_FR_V2,CSMCC_FR_V1,CSMCC_HR_V1
#else
    CSMCC_FR_AMRWB_V5,CSMCC_FR_V3,CSMCC_FR_V2,CSMCC_FR_V1,CSMCC_HR_V3,CSMCC_HR_V1
#endif
};

/*****************************************************************************
* FUNCTION
*  cc_get_SUPPORTED_2G_CODEC_NUM
* DESCRIPTION
*   This function is used to get the MAX Codec size customer defined 
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 cc_get_SUPPORTED_2G_CODEC_NUM(void)
{
    return(SUPPORTED_2G_CODEC_NUM);
}


#ifdef __CUSTOM_CONFIG_ACM_BOUND__
/*****************************************************************************
* FUNCTION
*  custom_is_acm_exceed_boundary
* DESCRIPTION
*   This function is used to check if acm exceed the boundary.
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_bool custom_is_acm_exceed_boundary (kal_uint32 acm_value)
{
       return ((kal_bool)(acm_value > CUSTOM_ACM_BOUND));
}
#endif /*__CUSTOM_CONFIG_ACM_BOUND__*/

/* MAUI_01637672 support CCWE */
/*****************************************************************************
* FUNCTION
*  custom_cc_get_acm_bound
* DESCRIPTION
*   This function is used to get the acm custom bound.
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint32 custom_cc_get_acm_bound()
{
   return ((kal_uint32)CUSTOM_ACM_BOUND);
}

/*****************************************************************************
* FUNCTION
*  custom_cc_get_acm_ccwe_time
* DESCRIPTION
*   This function is used to get the acm ccwe time.
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint32 custom_cc_get_acm_ccwe_time()
{
   return ((kal_uint32)CUSTOM_ACM_CALL_METER_WARNING_EVENT_SECONDS);
}

/*****************************************************************************
* FUNCTION
*  custom_config_rlc_timer
* DESCRIPTION
*   This function is used to get customer config rlc timer in seconds.
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint32 custom_config_rlc_timer()
{
       return CSM_RLC_TIMER_CONFIG;
}


/*****************************************************************************
 * FUNCTION
 *  custom_get_at_audio_download_folder
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_wchar *custom_get_at_audio_download_folder()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUSTOM_AT_AUDIO_DOWNLOAD_FOLDER_NAME;
}


/*****************************************************************************
 * FUNCTION
 *  custom_get_at_image_download_folder
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_wchar *custom_get_at_image_download_folder()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUSTOM_AT_IMAGE_DOWNLOAD_FOLDER_NAME;
}


#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
/* the maximum supported number of timer used in Fast Dormancy , 1 ~ 255 */
#define MAX_SUPPORTED_FD_TIMER_ID 4

/* the time slot of each tick to monitor PS data. uint is 0.1 sec */
#define FD_MONITOR_SLOT 10

/* the inactivity timer table. unit is 0.1 sec */
kal_uint16 fd_timer[MAX_SUPPORTED_FD_TIMER_ID] = 
{
/* timer id(b8~b1) meaning
   b1: screen on/off
   b2: NW R8 FD supported
   b3: cpc supported
*/
   50,   //t0: screen off, NW R8 FD off
   150,  //t1: screen on, NW R8 FD off
   50,   //t2: screen off, NW R8 FD on
   150   //t3: screen on, NW R8 FD on
};

/*****************************************************************************
* FUNCTION
*  	custom_get_fd_monitor_slot()
* DESCRIPTION
* 
* PARAMETERS
*	none
* RETURNS
*	kal_uint8
*****************************************************************************/
kal_uint8 custom_get_fd_monitor_slot(void)
{
   return FD_MONITOR_SLOT;
}


/*****************************************************************************
* FUNCTION
*  	custom_get_fd_timer_id()
* DESCRIPTION
*   	This function is used to return the timer ID according to input 
*   parameters
* PARAMETERS
*	conditions
* RETURNS
*	Timer ID
*****************************************************************************/
kal_uint8 custom_get_fd_timer_id(kal_bool is_screen_on, kal_bool is_r8_fd_support, kal_bool is_cpc_suppot)
{
    kal_uint8 timer_id;
    
    timer_id = (is_r8_fd_support == KAL_TRUE)? 1 : 0;
    timer_id <<= 1;
    timer_id |= (is_screen_on == KAL_TRUE)? 1 : 0;

    return timer_id;
}


/*****************************************************************************
* FUNCTION
*  	custom_set_fd_timer()
* DESCRIPTION
*   	This function is used to define time duration of Fast Dormancy to monitor
*   PS data transfer. The unit is 0.1 sec. 
*   Current default value is 40 sec (i.e. 400 x 0.1 sec)
* PARAMETERS
*	none
* RETURNS
*	time duration of handling ath for dialup
*****************************************************************************/
kal_bool custom_set_fd_timer(kal_uint8 timer_id, kal_uint16 timer_value)
{
    if (timer_id < MAX_SUPPORTED_FD_TIMER_ID)
    {
        fd_timer[timer_id] = timer_value;
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  	custom_get_fd_timer()
* DESCRIPTION
*   	This function is used to return the time duration of Fast Dormancy to monitor
*   PS data transfer. The unit is 0.1 sec.
* PARAMETERS
*	none
* RETURNS
*	time duration of handling ath for dialup
*****************************************************************************/
kal_uint16 custom_get_fd_timer(kal_uint8 timer_id)
{
    if (timer_id < MAX_SUPPORTED_FD_TIMER_ID)
    {
        return fd_timer[timer_id];
    }
    else
    {
        return 0xffff;
    }
}
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */


#if (defined(__GEMINI__) || defined(__SGLTE__))&& defined(__SIM_ME_LOCK__)
/*****************************************************************************
* FUNCTION
*   custom_l4c_root_lock_verify()
*
* DESCRIPTION
*   This function is used to customiz link_SML. Each SIM ME Lock can depend
*   on the status of other SIM. Please modify pending_password_tbl and 
*   need_unlock_table according to the updated_sim and updated_type.
*
* PARAMETERS
*	updated_sim             [IN]        the updated SIM
*   updated_type            [IN]        the pending password of the updated SIM
*   pending_password_tbl    [IN/OUT]    the fake pending password table
*   need_unlock_table       [OUT]       the flag of each modified SIM
*
* RETURNS
*   whether the pending password of any SIM is change
*****************************************************************************/
kal_bool custom_l4c_root_lock_verify(kal_uint8 updated_sim, 
                                     smu_pending_password_id_enum updated_type, 
                                     smu_pending_password_id_enum *pending_password_tbl,
                                     kal_uint8 *need_unlock_table)
{
    kal_bool need_unlock = KAL_FALSE;
    
#if defined(__SGLTE__)
    sim_interface_enum SGLTE_ps_nvram_idx;
    sim_interface_enum SGLTE_cs_nvram_idx;
    kal_bool mmdc_mode = KAL_TRUE;
#endif

#if defined(__SGLTE__)
    #if defined(__SGLTE_DSDS__)
    
        if (KAL_TRUE == is_SGLTE_4G_switched())  // 4G switched
        {
            SGLTE_ps_nvram_idx = SIM2;
        }
        else
        {
            SGLTE_ps_nvram_idx = SIM1;
        }

        SGLTE_cs_nvram_idx = SIM3;

    #else

        SGLTE_ps_nvram_idx = SIM1;
    
        SGLTE_cs_nvram_idx = SIM2;

    #endif

    mmdc_mode = is_mmdc_mode(SIM1);  // is_mmdc_mode(protocol 1)

    if (KAL_TRUE == mmdc_mode)
    {
        switch (updated_type)
        {
            case ID_READY:
            {
                if (updated_sim == SGLTE_ps_nvram_idx)
                {
                    /* unlock SIM2 if SIM1 is valid */
                    if ((pending_password_tbl[SGLTE_cs_nvram_idx] == ID_PH_FSIM_PIN) || 
                        (pending_password_tbl[SGLTE_cs_nvram_idx] == ID_PH_NET_PIN) ||
                        (pending_password_tbl[SGLTE_cs_nvram_idx] == ID_PH_NETSUB_PIN) ||
                        (pending_password_tbl[SGLTE_cs_nvram_idx] == ID_PH_SP_PIN) ||
                        (pending_password_tbl[SGLTE_cs_nvram_idx] == ID_PH_CORP_PIN) ||
                        (pending_password_tbl[SGLTE_cs_nvram_idx] == ID_PH_LINK_NS_SP_PIN) ||
                        (pending_password_tbl[SGLTE_cs_nvram_idx] == ID_PH_LINK_SIM_C_PIN))
                    {
                        pending_password_tbl[SGLTE_cs_nvram_idx] = ID_READY;
                        need_unlock_table[SGLTE_cs_nvram_idx] = 1;
                        need_unlock = KAL_TRUE;

                        tst_sys_trace("Set SGLTE_CS READY because of SGLTE_PS READY!");
                    }
                }

                pending_password_tbl[updated_sim] = ID_READY;  //SIM1, SIM2, or SIM3 ready

                tst_sys_trace("SGLTE SML READY!");

                break;
            }
            case ID_PH_FSIM_PIN:
            case ID_PH_NET_PIN:
            case ID_PH_NETSUB_PIN:
            case ID_PH_SP_PIN:
            case ID_PH_CORP_PIN:
            case ID_PH_LINK_NS_SP_PIN:
            case ID_PH_LINK_SIM_C_PIN:
            {
                /* SIM2 SML locked but SIM1 is valid */
                if (updated_sim == SGLTE_cs_nvram_idx)
                {
                    if (pending_password_tbl[SGLTE_ps_nvram_idx] == ID_READY)
                    {
                        pending_password_tbl[SGLTE_cs_nvram_idx] = ID_READY;
                        need_unlock = KAL_TRUE;
                        need_unlock_table[SGLTE_cs_nvram_idx] = 1;
                        tst_sys_trace("Set SGLTE_CS READY because of SGLTE_PS READY!!");
                    }
                    else if (pending_password_tbl[SGLTE_ps_nvram_idx] == ID_SIM_BUSY)
                    {
                        //don't lock first, wait for sim1 result
                        pending_password_tbl[SGLTE_cs_nvram_idx] = ID_SIM_BUSY;
                        tst_sys_trace("Set SGLTE_CS BUSY because of SGLTE_PS BUSY!");
                    }
                    else
                    {
                        pending_password_tbl[SGLTE_cs_nvram_idx] = updated_type;
                        tst_sys_trace("Set SGLTE_CS LOCKED!");
                    }
                }
                else //SIM1 or SIM3 locked 
                {
                    pending_password_tbl[updated_sim] = updated_type;
                    tst_sys_trace("Set SGLTE LOCKED!");
                }
                break;
            }
            default:
                /* not change */
                pending_password_tbl[updated_sim] = updated_type;
                break;
        }
    }
    else
    {
        pending_password_tbl[updated_sim] = updated_type;
    }

#else  /* __SGLTE__ */

    #if defined(__TC01__) || defined(__LINK_SML__)
    switch (updated_type)
    {
        case ID_READY:
        {
            if (updated_sim == SIM1)
            {
                kal_uint8 i;
                
                /* unlock all SIM if SIM1 is valid */
                for (i=1; i<MAX_SIM_NUM; i++)
                {
                    if ((pending_password_tbl[i] == ID_PH_FSIM_PIN) || 
                        (pending_password_tbl[i] == ID_PH_NET_PIN) ||
                        (pending_password_tbl[i] == ID_PH_NETSUB_PIN) ||
                        (pending_password_tbl[i] == ID_PH_SP_PIN) ||
                        (pending_password_tbl[i] == ID_PH_CORP_PIN) ||
                        (pending_password_tbl[i] == ID_PH_LINK_NS_SP_PIN) ||
                        (pending_password_tbl[i] == ID_PH_LINK_SIM_C_PIN))
                    {
                        pending_password_tbl[i] = ID_READY;
                        need_unlock_table[i] = 1;
                        need_unlock = KAL_TRUE;
                    }
                }
            }
            pending_password_tbl[updated_sim] = updated_type;
            break;
        }
        case ID_PH_FSIM_PIN:
        case ID_PH_NET_PIN:
        case ID_PH_NETSUB_PIN:
        case ID_PH_SP_PIN:
        case ID_PH_CORP_PIN:
        case ID_PH_LINK_NS_SP_PIN:
        case ID_PH_LINK_SIM_C_PIN:
        {
            /* SIM2~SIM3 SML locked but SIM1 is valid */
            if (updated_sim != SIM1)
            {
                if (pending_password_tbl[SIM1] == ID_READY)
                {
                    pending_password_tbl[updated_sim] = ID_READY;
                    need_unlock = KAL_TRUE;
                    need_unlock_table[updated_sim] = 1;
                }
                else if (pending_password_tbl[SIM1] == ID_SIM_BUSY)
                {
                    //don't lock first, wait for sim1 result
                    pending_password_tbl[updated_sim] = ID_SIM_BUSY;
                }
                else
                {
                    pending_password_tbl[updated_sim] = updated_type;
                }
            }
            else //SIM1 locked
            {
                pending_password_tbl[updated_sim] = updated_type;
            }
            break;
        }
        default:
            /* not change */
            pending_password_tbl[updated_sim] = updated_type;
            break;
    }
    #else  /* __TC01__ || __LINK_SML__ */
    /* default each SML is independent */
    pending_password_tbl[updated_sim] = updated_type;
    #endif  /* __TC01__ || __LINK_SML__ */

#endif  /* __SGLTE__ */

    return need_unlock;
}
#endif /* defined(__GEMINI__) && defined(__SIM_ME_LOCK__) */

/*****************************************************************************
* FUNCTION
*   custom_l4c_fill_ecc_category()
*
* DESCRIPTION
*   This function is used to turn on/off the ecc service category support
*
* PARAMETERS
*   none
*
* RETURNS
*   TRUE    : L4C will let MOD_PHB to approve the number and fill in the ecc category for ATDE
*   FALSE   : L4C will not let MOD_PHB to approve the number and fill in the ecc category for ATDE
*****************************************************************************/
kal_bool custom_fill_ecc_category(void)
{
    /*default value : KAL_FALSE.
    *   KAL_TRUE    : L4C will let MOD_PHB to approve the number and fill in the ecc category for ATDE
    *   KAL_FALSE   : L4C will not let MOD_PHB to approve the number and fill in the ecc category for ATDE
    */

    return KAL_FALSE;

}

/*****************************************************************************
* FUNCTION
*   custom_l4c_report_pdp_status()
*
* DESCRIPTION
*   This function is used to report PDP status to SIM
*
* PARAMETERS
*   none
*
* RETURNS
*
*****************************************************************************/
void custom_l4c_report_pdp_status(l4c_gprs_status_enum *last_status, l4c_gprs_status_enum current_status)
{
    sat_pdp_status_ind_struct *param_ptr = NULL;

    if (*last_status != current_status) {  

        param_ptr = (sat_pdp_status_ind_struct*)
            construct_local_para((kal_uint16) sizeof(sat_pdp_status_ind_struct), TD_RESET);

        if (current_status == L4C_PDP_ACTIVED) {    
            param_ptr->pdp_status = SAT_PDP_ACTIVATE;                      
        }    
        else {
            param_ptr->pdp_status = SAT_PDP_DEACTIVATE;        
        }
    
        l4c_send_msg_to_sim(MSG_ID_SAT_PDP_STATUS_IND, param_ptr, NULL);
    }
    l4c_resend_afr_req();
}

/*****************************************************************************
* FUNCTION
*   custom_l4c_report_gprs_status()
*
* DESCRIPTION
*   This function is used to report PDP status to SIM
*
* PARAMETERS
*   none
*
* RETURNS
*
*****************************************************************************/
void custom_l4c_report_gprs_status(l4c_gprs_status_enum *last_status, l4c_gprs_status_enum current_status, kal_uint8 cell_support_egprs, kal_uint8 data_speed_support, kal_uint8 data_bearer_capability)
{
    l4c_ps_gprs_status_update_lind(current_status, cell_support_egprs, data_speed_support, data_bearer_capability); // 1.1 update G-icon                                   
    custom_l4c_report_pdp_status(last_status, current_status);
    *last_status = current_status;    
}



/*****************************************************************************************
* FUNCTION
*   custom_cm_ctrl_by_sim()
*
* DESCRIPTION
*   this function is used to switch on/off call/sms/ss control by sim
*
* PARAMETERS
*   module [IN] could be CC, SS or SMS
* RETURNS
*   KAL_TRUE : support conrtorl by SIM
*   KAL_FALSE: not support control by SIM
******************************************************************************************/
kal_bool custom_cm_ctrl_by_sim(cm_ctrl_by_sim_enum module)
{
    switch (module)
    {
        case SMS_CTRL_BY_SIM:
            return KAL_TRUE;
            
        case CC_CTRL_BY_SIM:
            return KAL_TRUE;
            
        case SS_CTRL_BY_SIM:
            return KAL_TRUE;
            
        default:
            return KAL_FALSE;
    }
}

/*****************************************************************************
* FUNCTION
*  	custom_config_ims_reg_timeout_timer()
* DESCRIPTION
*
* PARAMETERS
*	none
* RETURNS
*	kal_uint8
*****************************************************************************/
kal_uint8 custom_config_ims_reg_timeout_timer(void)
{
    //length in Seconds
    return 64;
}




