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
 *   mncc_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the Values for THE IES  in the CC entity.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/



#ifndef _MNCC_ENUMS_H_
#define _MNCC_ENUMS_H_

/*****************
Include Statements
******************/

/************************
Macros Without Parameters 
*************************/


/*Location*/
typedef enum {
	CC_USER                =0x00,
	CC_PRIVATE_NW_LOCAL_USER,    /* Private Network, local user  */
	CC_PUBLIC_NW_LOCAL_USER,     /* Public network, local user   */
	CC_TRANSIT_NW,
	CC_PUBLIC_NW_REMOTE_USER ,   /* Public network, remote user  */
	CC_PRIVATE_NW_REMOTE_USER,   /* Private Network, remote user */
	CC_INTERNATIONAL_NW = 0x07,
	CC_NW_BEYOND_IWP = 0x0A /* Network beyond Interworking point */
}cc_user_location_enum;

typedef enum {
    
	CC_MIN_AUX_CALL_STATE_IE_LEN    = 3
}cc_aux_state_len_enum;
/*----------AUX_STATE --------------------------------*/



/*---------BEARER CAPABILITY----------------------------*/
typedef enum {
	CC_MIN_BC_IE_LEN       = 3
}cc_bc_len_enum;

/*App Types*/
typedef enum {
	CC_SPEECH_APP     = 0x00,
	CC_UDI_APP,
	CC_EX_PLMN_APP,
	CC_FAX3_APP,
	CC_OTHER_ITC      =0x05,
   CC_AUX_SPEECH_APP =0x06,
	CC_RESERVED_APP   =0x07
}cc_app_types_enum;

/*Radio Channel Requirement*/
typedef enum {
	CC_FULL_RATE_ONLY_MS             = 0X01	,
	CC_DUAL_RATE_MS_HALF_RATE_PREF ,
	CC_DUAL_RATE_MS_FULL_RATE_PREF 
}cc_chanel_requirement_enum;

/*Transfer Mode*/
typedef enum {
	CC_CIRCUIT_TM                   = 0x00,
	CC_PACKET_TM                    = 0x00
}cc_transfer_mode_enum;

/*---------CALL CONTROL CAPABILITIES--------------------*/
typedef enum {

	CC_MIN_CC_CAPABILITIES_IE_LEN    =3
} cc_cc_capabilities_len_enum;

/*Prolonged Claering Support*/
typedef enum {
	CC_PROLONGED_CLEARING_NOT_SUPPORTED = 0,
	CC_PROLONGED_CLEARING_SUPPORTED      
}cc_prolonged_clr_support_enum;

/*Dtmf Support*/
typedef enum {
	CC_DTMF_SUPPORT_EARLIER_VERSION = 0,
	CC_DTMF_SUPPORT_CURRENT_VERSION
}cc_dtmf_support_enum;



/*------------- CALLED PARTY NUMBER ----------*/

/*Type of Number*/
typedef enum {
	CC_TON_UNKNOWN       = 0x00,  /* unknown number */
	CC_TON_INT_NUM ,              /* International number */
	CC_TON_NAT_NUM ,              /* National Number */
	CC_TON_NW_NUM ,               /* Network specific number */
	CC_TON_SHORT_CODE ,           /* dedicated access, short code */
	CC_TON_RESRV_EXT     = 0x07,  /* Reserved for Extension */
	CC_TON_RESERVE       = 0x05   /* x50 to x70 is reserved */
}cc_called_party_type_of_num_enum;

/*Numbering Plan*/
typedef enum {
	CC_UNKNOWN_NP         = 0x00 ,/* unknown numbering plan */
	CC_ISDN_NP ,		      /* ISDN numbering plan */
	CC_DATA_NP            = 0x03 ,/* data numbering plan */
	CC_TELEX_NP ,		      /* Telex numbering plan */
	CC_NATIONAL_NP        = 0x08, /* National */
	CC_PRIVATE_NP ,		      /* private numbering plan */
	CC_RESERVE_NP         = 0x0F  /* reserved numbering plan */
}cc_called_party_num_plan_enum;

/* Digits or Charachters */
/* Digit 1-9 has same value as their binary coded value */
typedef enum {
	CC_STAR              = 0x0A,
	CC_HASH ,               
	CC_DIGIT_A ,          
	CC_DIGIT_B ,           
	CC_DIGIT_C ,          
	CC_LAST_DIGIT       
}cc_xtra_digits_enum;

/*Screening Indicator*/
typedef enum {
	CC_SCR_NOT_SCREENED   = 0x00 ,/* user provided, not screened */
	CC_SCR_PASSED ,		      /* user provided, verf, passed */
	CC_SCR_FAILED ,		      /* user prov., failed */
	CC_SCR_NW   		      /* network provided */
}cc_scr_ind_enum;


/*--------- SUBADDRESS -----------*/
#define CC_MAX_CALLED_SUB_ADDR_IE_LEN 21

typedef enum {
	CC_NSAP_SUB_ADDR_TYPE,
    CC_USER_SPEC_SUB_ADDR_TYPE = 0x2
}cc_sub_addr_type_enum;

typedef enum {
    CC_EVEN_SUB_INDICATOR,
    CC_ODD_SUB_INDICATOR
}cc_sub_add_indicator_enum;

/*------------CONGESTION LEVEL------------*/
typedef enum {
	CC_RECEIVER_READY          = 0x00,
	CC_RECEIVER_NOT_READY

}cc_congestion_level_enum;

/*------------NOTIFICATION INDICATOR------*/

#define CC_MIN_NOTIFY_IND_IE_LEN   3

/*Notification Indication*/
typedef enum {
	S_USER_SUSPENDED         = 0x00,
	S_USER_RESUMED ,
        S_BEARER_CHG 
}cc_notification_ind_enum;

/*------------PROGRESS INDICATOR---------*/

/* Progress Description */
typedef enum {
	CC_NOT_END_TO_END_PLMN = 0X01,/* Call is not end-to-end plmn */
	CC_DST_ADD_NON_PLMN ,         /* Destination address is in non plmn*/
	CC_ORG_ADD_NON_PLMN ,         /* Originating address is in non-plmn */
	CC_CALL_RET_PLMN  ,           /* Call return to plmn */
	CC_INBAND_INFO_AVAIL   = 0X08,/* Inband Information avail now */
	CC_END_TO_END_PLMN     = 0X20,/* Call is end to end plmn */
	CC_QUEUEING            = 0X40, /* Call queueing */
	CC_PROG_DESC_INVALID_DEFAULT = 255   /*mtk00924: remove warning C2874W may be used before being set*/

}cc_progress_description_enum;

/*------------RECALL TYPE---------------*/
/*Recall Type*/
#define CC_CCBS_RECALL              0x00


/*------------REPEAT INDICATOR---------*/
/*Repeat Indication*/
typedef enum {
	MODE1_ALTERNATE_MODE2      = 0x01,
	MODE1_PREFERED_ELSE_MODE2 
}cc_repeat_ind_enum;

/*------------SIGNAL--------------------*/
typedef enum {
	CC_DIAL_TONE_ON                      = 0x00,
	CC_RING_BACK_TONE_ON ,                
	CC_INTERCEPT_TONE_ON ,
	CC_NTW_CONGESTION_TONE_ON ,
	CC_BUSY_TONE_ON , 
	CC_CONFIRM_TONE_ON  ,
	CC_ANSWER_TONE_ON  ,
	CC_CALL_WAITING_TONE_ON  ,
	CC_OFF_HOOK_WARNING_TONE_ON ,
	CC_TONES_OFF                         = 0x3F ,
	CC_ALERTING_OFF                      = 0x4F

}cc_signal_tone_enum;

/*------------ALLOWED ACTIONS-------------*/
typedef enum {
	CC_CCBS_ACTIVATION_NOT_POSSIBLE = 0 ,
	CC_CCBS_ACTIVATION_POSSIBLE 
	    
} cc_allowed_actions_enum;


/*------------SS VERSION INDICATOR-------*/
typedef enum {
	CC_SS_VERSION_2       = 0x00,
	CC_SS_VERSION_3

}cc_ss_version_ind_enum;

/*------------NETWORK CC CAPABILITY------*/
typedef enum {
	CC_NETWOTK_NOT_SUPPORTS_MULTICALL =0x00,
	CC_NETWOTK_SUPPORTS_MULTICALL      
}cc_nw_cc_capability_enum;

/*------------USER USER------------------*/
typedef enum {
    
	CC_MAX_USER2USER_IE_LEN = 131
}cc_nw_user2user_enum;

typedef enum {
	CC_UUI_PD_USER_SPECIFIC            = 0x00 ,
	CC_UUI_PD_OSI_HIGH_LAYER ,
	CC_UUI_PD_X_244 ,
	CC_UUI_PD_SYSTEM_MGMT_CONVERGENCE ,
	CC_UUI_PD_IA5_CHARS ,
	CC_UUI_PD_REC_V_120_RATE_ADAPTION  = 0x07,
	CC_UUI_PD_Q_931_CC_USER_MSGS       

}cc_uui_pd_enum;

/*------------CAUSE OF NO CLI------------*/
typedef enum {
	CC_CAUSE_OF_NO_CLI_UNAVAILABLE                    = 0x00 ,
	CC_CAUSE_OF_NO_CLI_REJECTED_BY_USER ,
	CC_CAUSE_OF_NO_CLI_INTERACTION_WITH_OTHER_SERVICE ,
	CC_CAUSE_OF_NO_CLI_COIN_LINE_OR_PAY_PHONE 
	    
}cc_cause_of_no_cli_enum;

/*------------CC CAPABILITY------------*/
typedef enum {
	CC_EARLIER_DTMF_VERSION             = 0,
	CC_CURRENT_DTMF_VERSION
}cc_dtmf_version_enum;

typedef enum {
	CC_PCP_NOT_SUPPORTED                = 0,
	CC_PCP_SUPPORTED

}cc_pcp_supported_enum;


/*****************
Enums Without Tags 
******************/

/***************
Type Definitions 
****************/

/********
Constants 
*********/

/*********************
Macros With Parameters 
**********************/

/***************************
Exported Function Prototypes 
****************************/

/******************************
Declarations Of Exported Globals 
*******************************/

#endif /* _MNCC_ENUMS_H_ */



















