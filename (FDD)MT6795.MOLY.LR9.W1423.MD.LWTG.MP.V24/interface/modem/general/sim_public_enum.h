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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   sim_public_enum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Enum and Constant  provided by SIM task and outside-PS task uses also
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
#ifndef SIM_PUBLIC_ENUM_H
#define SIM_PUBLIC_ENUM_H

#include "global_def.h"

/******************* MMDC START *******************/
typedef enum
{
    SIM_ACCESS_EXTERNAL_READ_BINARY,
    SIM_ACCESS_EXTERNAL_READ_RECORD,
    SIM_ACCESS_EXTERNAL_UPDATE_BINARY,
    SIM_ACCESS_EXTERNAL_UPDATE_RECORD,
    SIM_ACCESS_EXTERNAL_FILE_INFO,
    SIM_ACCESS_EXTERNAL_AUTHENTICATION
}sim_access_extmd_op_enum;

typedef enum
{
    SIM_NOTIFY_INITIALIZATION,
    SIM_RESPONSE_ACCESS,
    SIM_NOTIFY_CARD_STATUS,
    SIM_NOTIFY_CARD_TYPE,
    SIM_NOTIFY_FILE_CHANGE
}sim_extmd_notify_enum;

/******************* MMDC END *******************/

typedef enum
{
   SIM_TYPE_NULL,
   SIM_TYPE_TEST_SIM,
   SIM_TYPE_TEST_USIM,
   SIM_TYPE_SIM,
   SIM_TYPE_USIM
} sim_type_query_enum;


typedef enum
{
   SERVICE_CHV_DISABLE_FUNCTION=1,
   SERVICE_ADN,
   SERVICE_FDN,
   SERVICE_SMS,
   SERVICE_AOC,
   SERVICE_CCP,
   SERVICE_PLMNSEL,
   SERVICE_RFU1,
   SERVICE_MSISDN,
   SERVICE_EXT1,
   SERVICE_EXT2,
   SERVICE_SMSP,
   SERVICE_LND,
   SERVICE_CBMI,
   SERVICE_GID1,
   SERVICE_GID2,
   SERVICE_SPN,
   SERVICE_SDN,
   SERVICE_EXT3,
   SERVICE_RFU2,
   SERVICE_VGCS,
   SERVICE_VBS,
   SERVICE_EMLPP,
   SERVICE_AAEM,
   SERVICE_DATA_DOWNLOAD_SMS_CB,
   SERVICE_DATA_DOWNLOAD_SMS_PP,
   SERVICE_MENU_SELECTION,
   SERVICE_CALL_CONTROL,
   SERVICE_PROACTIVE_SIM,
   SERVICE_CBMIR,
   SERVICE_BDN,
   SERVICE_EXT4,
   SERVICE_DCK,
   SERVICE_CNL,
   SERVICE_SMSR,
   SERVICE_NW_IND_ALERT,
   SERVICE_MO_SMS,
   SERVICE_GPRS,
   SERVICE_IMAGE,
   SERVICE_SOLSA,
   SERVICE_USSD,
   SERVICE_RUN_AT_CMD,
   SERVICE_PLMNWACT,
   SERVICE_OPLMNWACT,
   SERVICE_HPLMNWACT,
   SERVICE_CPBCCH,
   SERVICE_INVSCAN,
   SERVICE_ECCP,
   SERVICE_MEXE,
   SERVICE_RFU,
   SERVICE_PLMN_NAME,
   SERVICE_OPLMN_LIST,
   SERVICE_MAILBOX_DIAL_NUM,
   SERVICE_MSG_WAIT_IND,
   SERVICE_CALL_FWD_IND,
   SERVICE_SP_DSPL_INFO,
   SERVICE_MMS,
   SERVICE_EXT8,
   SERVICE_MMS_UCP,
   SERVICE_EMPTY, /* 60 */
   SERVICE_CSP,
   SERVICE_SST,
   SERVICE_MAILBOX_NUM,
   SERVICE_OPNAME_SHORTFORM,
   SERVICE_INFO_NUM,
   SERVICE_END,
   SERVICE_U_LOCAL_PHB,  // 1
   SERVICE_U_FDN,
   SERVICE_U_EXT2,
   SERVICE_U_SDN,
   SERVICE_U_EXT3,
   SERVICE_U_BDN,
   SERVICE_U_EXT4,
   SERVICE_U_OCI_OCT,
   SERVICE_U_ICI_ICT,
   SERVICE_U_SMS,  // 10
   SERVICE_U_SMSR,
   SERVICE_U_SMSP,
   SERVICE_U_AOC,
   SERVICE_U_CCP,
   SERVICE_U_CBMI,
   SERVICE_U_CBMIR,
   SERVICE_U_GID1,
   SERVICE_U_GID2,
   SERVICE_U_SPN,
   SERVICE_U_PLMNWACT,  // 20
   SERVICE_U_MSISDN,
   SERVICE_U_IMG,
   SERVICE_U_SOLSA,
   SERVICE_U_EMLPP,
   SERVICE_U_AAEM,
   SERVICE_U_RFU,
   SERVICE_U_GSM_ACCESS,
   SERVICE_U_DATA_DOWNLOAD_SMS_PP,
   SERVICE_U_DATA_DOWNLOAD_SMS_CB,
   SERVICE_U_CALL_CONTROL,  // 30
   SERVICE_U_SMS_CONTROL,
   SERVICE_U_RUN_AT_CMD,
   SERVICE_U_RFU_1,
   SERVICE_U_EST,
   SERVICE_U_ACL,
   SERVICE_U_DCK,
   SERVICE_U_CO_NWLIST,
   SERVICE_U_GSM_SECURITY_CTX,
   SERVICE_U_CPBCCH,
   SERVICE_U_INVSCAN,  // 40
   SERVICE_U_MEXE,
   SERVICE_U_OPLMNWACT,
   SERVICE_U_HPLMNWACT,
   SERVICE_U_EXT5,
   SERVICE_U_PLMN_NAME,
   SERVICE_U_OPLMN_LIST,
   SERVICE_U_MAILBOX_DIAL_NUM,
   SERVICE_U_MSG_WAIT_IND,
   SERVICE_U_CALL_FWD_IND,
   SERVICE_U_RFU_2,  // 50
   SERVICE_U_SP_DSPL_INFO,
   SERVICE_U_MMS,
   SERVICE_U_EXT8,
   SERVICE_U_GPRS_CALL_CONTROL,
   SERVICE_U_MMS_UCP,
   SERVICE_U_NIA,
   SERVICE_U_VGCS, //__R7_EHPLMN__ start
   SERVICE_U_VBS,
   SERVICE_U_PSEUDO, 
   SERVICE_U_UPLMNWLAN,  // 60
   SERVICE_U_OPLMNWLAN,
   SERVICE_U_UWSIDL,
   SERVICE_U_OWSIDL,
   SERVICE_U_VGCS_SECURITY,
   SERVICE_U_VBS_SECURITY,
   SERVICE_U_WRI,
   SERVICE_U_MULTIMEDIA_MSG_STORAGE,
   SERVICE_U_GBA,
   SERVICE_U_MBMS_SECURITY,
   SERVICE_U_DATA_DOWNLOAD_USSD,  // 70
   SERVICE_U_EHPLMN,   //__R7_EHPLMN__ end
   SERVICE_U_ADDITIONAL_TERMINAL_PROFILE,
   SERVICE_U_EHPLMNPI,
   SERVICE_U_LRPLMNSI,
   SERVICE_U_OMA_BCAST, //R8 __CSG_SUPPORT__ start  
   SERVICE_U_GBA_LOCAL_KEY,
   SERVICE_U_TERMINAL_AP,
   SERVICE_U_SPNI,
   SERVICE_U_PNNI,
   SERVICE_U_CPIP,  // 80
   SERVICE_U_HWSIDL, 
   SERVICE_U_WEHPLMNPI, 
   SERVICE_U_WHPI, 
   SERVICE_U_WLRPLMN, 
   SERVICE_U_EPS_MM_INFO, 
   SERVICE_U_ACSGL,    //R8 __CSG_SUPPORT__ end
   SERVICE_U_CC_EPS_PDN, //Call control on EPS PDN connection by USIM
   SERVICE_U_HPLMNDA,
   SERVICE_U_ECALL_DATA, //__ECALL_SUPPORT__
   SERVICE_U_OCSGL,  // 90
   SERVICE_U_SM_OVER_IP,
   SERVICE_U_CSG_DISPLAY, 
   SERVICE_U_COMM_CTRL_IMS,
   SERVICE_U_EXT_TERMINAL_APP,
   SERVICE_U_UICC_ACCESS_IMS,
   SERVICE_U_NAS_CONFIG,  
   SERVICE_U_PWS_CONFIG,
   SERVICE_U_END
}sim_service_enum;

typedef enum
{
   SIM_CARD_REMOVED,
   SIM_ACCESS_ERROR,
   SIM_REFRESH,
   SIM_REFRESH_POWER_OFF,
   SIM_PUK1,
   SIM_ACCESS_PROFILE_ON,
   SIM_ACCESS_PROFILE_OFF,
   DUALSIM_DISCONNECTED,               /* mtk01488: gsmcdma_dualsim disconnected */
   DUALSIM_CONNECTED,                      /* mtk01488: gsmcdma_dualsim connected */
/*mtk01612: wise_vsim start*/   
   SIM_VSIM_ON, 
   SIM_VSIM_OFF,   
/*mtk01612: wise_vsim end*/   
   SIM_PLUG_OUT,                /* mtk80420: SIM hot swap start */
   SIM_PLUG_IN,                  /* mtk80420: SIM hot swap end */   
   SIM_RECOVERY_START,                 /* mtk80420: SIM recovery improvement */
   SIM_RECOVERY_END,
   SIM_IMEI_LOCK_FAIL       /* __IMEI_LOCK_SUPPORT__ */ 
}sim_error_cause_enum;

typedef enum
{
   SIM_CMD_SUCCESS        = 2560,
   SIM_CMD_FAIL           = 2561,
   SIM_FATAL_ERROR        = 2562,
   SIM_NO_INSERTED        = 2563,
   SIM_CHV_NOT_INIT       = 2564,
   SIM_CHV_RETRY_ALLOW    = 2565,
   SIM_CHV_BLOCK          = 2566,
   SIM_ACCESS_NOT_ALLOW   = 2567,
   SIM_SAT_CMD_BUSY       = 2568,
   SIM_DL_ERROR           = 2569,
   SIM_MEMORY_PROBLEM     = 2570,
   SIM_TECHNICAL_PROBLEM  = 2571,
   SIM_PUK_UNLOCK   = 2572, /* add new enum value to distinguish whether normal poweron or PUK-unlock-poweron */   
   SIM_EF_RECORD_FULL = 2573, /*add new enum value to represent no free record in the file*/
   /* USIM related results */
   SIM_SELECT_FILE_INVALID = 2574,
   SIM_SELECT_DF_TERMINATED = 2575,
   SIM_NO_EF_SELECTED = 2576,
   SIM_FILE_NOT_FOUND = 2577,
   SIM_RECORD_NOT_FOUND = 2578,
   SIM_REF_DATA_NOT_FOUND = 2579,
   SIM_INCREASE_FAIL = 2580,
   SIM_AUTH_ERROR_WRONG_MAC = 2581,
   SIM_AUTH_ERROR_GSM_NOT_SUPPORT = 2582,
   /* HW instruction class */
   SIM_WRONG_INSTRUCTION_CLASS = 2583
}sim_cmd_result_enum;

typedef enum
{
   SERVICE_NOT_SUPPORT,
   SERVICE_SUPPORT,
   SERVICE_ALLOCATE,
   SERVICE_UNDEFINED
}sim_service_state_enum;

typedef enum
{
   SIM_NOT_READY, /* initial state */
   SIM_CARD_NOT_INSERTED, /* No SIM found after initialization */
   NORMAL_SIM_PRESENCE, /* Normal SIM found after initialization */
   TEST_SIM_PRESENCE, /* Test SIM found after initialization */
   SIM_ERROR_SIM_PRESENCE  /* mtk80420: SIM hot swap */
}sim_card_status_enum;
    
typedef enum
{
    FILE_NONE,         
    FILE_MF_IDX,
    FILE_GSM_IDX,
    FILE_TELECOM_IDX,
    FILE_IRIDIUM_IDX,
    FILE_GLOBST_IDX,
    FILE_ICO_IDX,
    FILE_ACES_IDX,
    FILE_EIA_IDX,
    FILE_CTS_IDX,
    FILE_SOLSA_IDX, /*10*/
    FILE_MEXE_IDX, 
    FILE_GRAPHICS_IDX,
    GLOBAL_FILES_START,
    FILE_ICCID_IDX = GLOBAL_FILES_START,
    FILE_ELP_IDX,
    GLOBAL_FILES_END = FILE_ELP_IDX,
    FILE_SAI_IDX,
    FILE_SLL_IDX,
    FILE_MEXE_ST_IDX,
    FILE_ORPK_IDX,
    FILE_ARPK_IDX,
    FILE_TPRPK_IDX,/*20*/
    FILE_IMG_IDX,
    FILE_LP_IDX,
    FILE_IMSI_IDX,
    FILE_KC_IDX,
    FILE_PLMNSEL_IDX,
    FILE_HPLMN_IDX,
    FILE_ACMAX_IDX,
    FILE_SST_IDX,
    FILE_ACM_IDX,
    FILE_GID1_IDX,/*30*/
    FILE_GID2_IDX,
    FILE_SPN_IDX,
    FILE_PUCT_IDX,
    FILE_CBMI_IDX,
    FILE_BCCH_IDX,
    FILE_ACC_IDX,
    FILE_FPLMN_IDX,
    FILE_LOCI_IDX,
    FILE_AD_IDX,
    FILE_PHASE_IDX,/*40*/
    FILE_VGCS_IDX,
    FILE_VGCSS_IDX,
    FILE_VBS_IDX,
    FILE_VBSS_IDX,
    FILE_EMLPP_IDX,
    FILE_AAEM_IDX,
    FILE_CBMID_IDX,
    FILE_ECC_IDX,
    FILE_CBMIR_IDX,
    FILE_DCK_IDX,/*50*/
    FILE_CNL_IDX,
    FILE_NIA_IDX,
    FILE_KCGPRS_IDX,
    FILE_LOCIGPRS_IDX,
    FILE_SUME_IDX,
    FILE_PLMNWACT_IDX,
    FILE_OPLMNWACT_IDX,
    FILE_HPLMNACT_IDX,
    FILE_CPBCCH_IDX,
    FILE_INVSCAN_IDX,/*60*/
    FILE_VM_WAIT_IDX,
    FILE_CPHS_SST_IDX,
    FILE_CF_FLAG_IDX,
    FILE_OP_STRING_IDX,
    FILE_CSP_IDX,
    FILE_CPHS_INFO_IDX,
    FILE_MAILBOX_NUM_IDX,
    FILE_OP_SHORTFORM_IDX,
    FILE_INFO_NUM_IDX,
    FILE_ADN_IDX,/*70*/
    FILE_FDN_IDX,
    FILE_SMS_IDX,
    FILE_CCP_IDX,
    FILE_ECCP_IDX,
    FILE_MSISDN_IDX,
    FILE_SMSP_IDX,
    FILE_SMSS_IDX,
    FILE_LND_IDX,
    FILE_SDN_IDX,
    FILE_EXT1_IDX,/*80*/
    FILE_EXT2_IDX,
    FILE_EXT3_IDX,
    FILE_BDN_IDX,
    FILE_EXT4_IDX,
    FILE_SMSR_IDX,
    FILE_CMI_IDX,
    FILE_IMG_1_IDX,
    FILE_IMG_2_IDX,
    FILE_IMG_3_IDX,
    FILE_IMG_4_IDX,/*90*/
    FILE_IMG_5_IDX,
    FILE_IMG_6_IDX,
    FILE_IMG_7_IDX,
    FILE_IMG_8_IDX,
    FILE_IMG_9_IDX,
    FILE_IMG_A_IDX,
    FILE_IMG_B_IDX,
    FILE_IMG_C_IDX,
    FILE_IMG_D_IDX,
    FILE_IMG_E_IDX,/*100*/
    FILE_IMG_F_IDX,
 /*__HOMEZONE_SUPPORT__ start*/ 
    FILE_VID_IDX, 
    FILE_HZ_IDX,
    FILE_HZ_CACHE1_IDX,
    FILE_HZ_CACHE2_IDX,
    FILE_HZ_CACHE3_IDX,
    FILE_HZ_CACHE4_IDX,
 /*__HOMEZONE_SUPPORT__ end*/  
 /*__ENS__ start*/ /*ENS support mtk01488 */
    FILE_ENS_DF_7F66_IDX,
    FILE_ENS_DF_5F30_IDX,
    FILE_ENS_ACTING_HPLMN_IDX,/*110*/
    FILE_ENS_TERMINAL_SUPPORT_TABLE_IDX,
 /*__ENS__ end*/
    FILE_PNN_IDX,
    FILE_OPL_IDX,
    FILE_MBDN_IDX,
    FILE_EXT6_IDX,
    FILE_MBI_IDX,
    FILE_MWIS_IDX,
    FILE_CFIS_IDX,
    FILE_EXT7_IDX,
    FILE_SPDI_IDX,/*120*/
    FILE_MMSN_IDX,
    FILE_EXT8_IDX,
    FILE_MMSICP_IDX,
    FILE_MMSUP_IDX,
    FILE_MMSUCP_IDX,
    SIM_TOT_FILES,
    FILE_DIR_IDX  = SIM_TOT_FILES,
    FILE_ARR_IDX,       
    FILE_USIM_IDX,
    FILE_U_LI_IDX,
    FILE_U_IMSI_IDX,/*130*/
    FILE_U_KEYS_IDX,
    FILE_U_KEYSPS_IDX,
    FILE_U_PLMNWACT_IDX, 
    FILE_U_HPPLMN_IDX,
    FILE_U_ACMMAX_IDX,
    FILE_U_UST_IDX,
    FILE_U_ACM_IDX,
    FILE_U_GID1_IDX,
    FILE_U_GID2_IDX,
    FILE_U_SPN_IDX,/*140*/
    FILE_U_PUCT_IDX,
    FILE_U_CBMI_IDX,
    FILE_U_ACC_IDX,
    FILE_U_FPLMN_IDX,
    FILE_U_LOCI_IDX,
    FILE_U_AD_IDX,
    FILE_U_CBMID_IDX,
    FILE_U_ECC_IDX,
    FILE_U_CBMIR_IDX,
    FILE_U_PSLOCI_IDX,/*150*/
    FILE_U_FDN_IDX,
    FILE_U_SMS_IDX,
    FILE_U_MSISDN_IDX,
    FILE_U_SMSP_IDX,  
    FILE_U_SMSS_IDX,
    FILE_U_SDN_IDX,
    FILE_U_EXT2_IDX,
    FILE_U_EXT3_IDX,
    FILE_U_SMSR_IDX,
    FILE_U_ICI_IDX,/*160*/
    FILE_U_OCI_IDX,
    FILE_U_ICT_IDX,
    FILE_U_OCT_IDX,
    FILE_U_EXT5_IDX,  
    FILE_U_CCP2_IDX,
    FILE_U_EMLPP_IDX,
    FILE_U_AAEM_IDX,
    FILE_U_HIDDENKEY_IDX,
    FILE_U_BDN_IDX,
    FILE_U_EXT4_IDX,/*170*/
    FILE_U_CMI_IDX,
    FILE_U_EST_IDX,
    FILE_U_ACL_IDX,
    FILE_U_DCK_IDX,  
    FILE_U_CNL_IDX,
    FILE_U_STARTHFN_IDX,
    FILE_U_THRESHOLD_IDX,
    FILE_U_OPLMNWACT_IDX,
    FILE_U_HPLMNWACT_IDX,
    FILE_U_ARR_IDX,/*180*/
    FILE_U_NETPAR_IDX,
    FILE_U_PNN_IDX,
    FILE_U_OPL_IDX,
    FILE_U_MBDN_IDX,
    FILE_U_EXT6_IDX,
    FILE_U_MBI_IDX,
    FILE_U_MWIS_IDX,
    FILE_U_CFIS_IDX,
    FILE_U_EXT7_IDX,
    FILE_U_SPDI_IDX,/*190*/
    FILE_U_MMSN_IDX,
    FILE_U_EXT8_IDX,
    FILE_U_MMSICP_IDX,
    FILE_U_MMSUP_IDX,
    FILE_U_MMSUCP_IDX,
    FILE_U_NIA_IDX,
    FILE_U_VGCS_IDX,
    FILE_U_VGCSS_IDX,
    FILE_U_VBS_IDX,
    FILE_U_VBSS_IDX,/*200*/
    FILE_U_VGCSCA_IDX,
    FILE_U_VBSCA_IDX,
    FILE_U_GBAP_IDX,
    FILE_U_MSK_IDX,   
    FILE_U_MUK_IDX,
    FILE_U_GBANL_IDX,
    FILE_U_SOLSA_IDX,
    FILE_U_SAI_IDX,
    FILE_U_SLL_IDX,
    FILE_U_LSAD_IDX,/*210*/
    FILE_U_PHONEBOOK_IDX,
    FILE_U_PBR_IDX,
    FILE_U_IAP_IDX,
    FILE_U_ADN_IDX,   
    FILE_U_EXT1_IDX,
    FILE_U_PBC_IDX,
    FILE_U_GRP_IDX,
    FILE_U_AAS_IDX,
    FILE_U_GAS_IDX,
    FILE_U_ANR_IDX,/*220*/
    FILE_U_SNE_IDX,
    FILE_U_CCP1_IDX,
    FILE_U_UID_IDX,
    FILE_U_PSC_IDX,   
    FILE_U_CC_IDX,
    FILE_U_PUID_IDX,
    FILE_U_EMAIL_IDX,
    FILE_U_GSMACCESS_IDX,
    FILE_U_KC_IDX,
    FILE_U_KCGPRS_IDX,/*230*/
    FILE_U_CPBCCH_IDX,
    FILE_U_INVSCAN_IDX,
    FILE_U_MEXE_IDX,
    FILE_U_MEXEST_IDX, 
    FILE_U_ORPK_IDX,
    FILE_U_ARPK_IDX,
    FILE_U_TPRPK_IDX,
    FILE_U_TKCDF_IDX,
    FILE_U_WLAN_IDX,
    FILE_U_PSEUDO_IDX,/*240*/
    FILE_U_UPLMNWLAN_IDX,
    FILE_U_OPLMNWLAN_IDX,
    FILE_U_USSIDL_IDX, 
    FILE_U_OSSIDL_IDX,  
    FILE_U_WRI_IDX,
    FILE_G_PHONEBOOK_IDX,
    FILE_G_PBR_IDX,
    FILE_G_IAP_IDX,
    FILE_G_ADN_IDX,
    FILE_G_EXT1_IDX,/*250*/
    FILE_G_PBC_IDX,
    FILE_G_GRP_IDX,
    FILE_G_AAS_IDX,
    FILE_G_GAS_IDX,    
    FILE_G_ANR_IDX,
    FILE_G_SNE_IDX,
    FILE_G_CCP1_IDX,
    FILE_G_UID_IDX,
    FILE_G_PSC_IDX,
    FILE_G_CC_IDX,/*260*/
    FILE_G_PUID_IDX,
    FILE_G_EMAIL_IDX,
    FILE_MULTIMEDIA_IDX, 
    FILE_MML_IDX,     
    FILE_MMDF_IDX,
    FILE_U_EHPLMN_IDX, //__R7_EHPLMN__
    FILE_U_EHPLMNPI_IDX,
    FILE_U_LRPLMNSI_IDX,
/*__U_CSP_SUPPORT__ start*/     /*[MAUI_02387843] mtk01612: AT&T proprietary: support EF U_CSP under 7FFF*/ 
    FILE_U_CSP_IDX,
/*__U_CSP_SUPPORT__ end*/     
    FILE_U_ENS_RAT_IDX, //__ENS_RAT_BALANCING__	/*270*/ 
    FILE_U_ENS_TERMINAL_SUPPORT_TABLE_IDX,     /* [MAUI_02908638] mtk01616_110418 support EF_U_TS_table under 7FFF */
    FILE_U_ENS_DF_7F66_IDX,
    FILE_U_ENS_DF_5F30_IDX,
    FILE_U_ENS_ACTING_HPLMN_IDX,
/* R8 __CSG_SUPPORT__ start */    
    FILE_U_HNB_IDX, 
    FILE_U_ACSGL_IDX,
    FILE_U_CSGT_IDX,
    FILE_U_HNBN_IDX,    
    FILE_U_OCSGL_IDX,
/* R8 __CSG_SUPPORT__ end */
    FILE_U_EPSLOCI_IDX,
    FILE_U_EPSNSC_IDX,
/* __ISIM_SUPPORT__ start */
    FILE_PSISMSC_IDX,
    FILE_ISIM_IDX,
    FILE_I_IST_IDX,
    FILE_I_IMPI_IDX,
    FILE_I_DOMAIN_IDX,
    FILE_I_IMPU_IDX,
    FILE_I_AD_IDX,
    FILE_I_ARR_IDX,
    FILE_I_PCSCF_IDX,
    FILE_I_GBAP_IDX,
    FILE_I_GBANL_IDX,
    FILE_I_NAFKCA_IDX,
    FILE_I_UICCIARI_IDX,
    FILE_I_SMS_IDX,
    FILE_I_SMSS_IDX,
    FILE_I_SMSR_IDX,
    FILE_I_SMSP_IDX,
/* __ISIM_SUPPORT__ end */  

/* USIM R10/R11 new file start */   
    FILE_U_NAFKCA_IDX,
    FILE_U_SPNI_IDX,
    FILE_U_PNNI_IDX,
    FILE_U_NCPIP_IDX,
    //FILE_U_EPSLOCI_IDX,// Already exist
    //FILE_U_EPSNSC_IDX,// Already exist
    FILE_U_UFC_IDX,
    FILE_U_UICCIARI_IDX,
    FILE_U_NASCONFIG_IDX,
    FILE_U_PWS_IDX,
/* USIM R10/R11 new file end */

    UICC_TOTAL_FILES 
}sim_file_index_enum;

typedef enum
{
   TYPE_SIM_INIT_AND_FULL_FILE_CHANGE,
   TYPE_FILE_CHANGE,
   TYPE_SIM_INIT_AND_FILE_CHANGE,
   TYPE_SIM_INIT,
   TYPE_SIM_RESET,
   TYPE_USIM_APPLICATION_RESET,
   TYPE_USIM_SESSION_RESET,
   TYPE_STEERING_OF_ROAMING,
   TYPE_NON_SAT_REFRESH = 0xFE //[MAUI_01321308] mtk01612: for G+C
}sat_refresh_type_enum;

typedef enum
{
   PROTOCOL_1 = 0x00,
   PROTOCOL_2 = 0x01,
   PROTOCOL_3 = 0x02,
   PROTOCOL_4 = 0x03   
}protocol_id_enum;

typedef enum
{
   SIM1 = 0x00,
   SIM2 = 0x01,
   SIM3 = 0x02,
   SIM4 = 0x03   
}sim_interface_enum;

typedef enum
{
    USIM_DEFAULT_CH = 0x00,
    USIM_LOGIC_CH_1 = 0x01,
    USIM_LOGIC_CH_2 = 0x02,
    USIM_LOGIC_CH_3 = 0x03,
    USIM_LOGIC_CH_4 = 0x04,
    USIM_LOGIC_CH_5 = 0x05,
    USIM_LOGIC_CH_6 = 0x06,
    USIM_LOGIC_CH_7 = 0x07,
    USIM_LOGIC_CH_8 = 0x08,
    USIM_LOGIC_CH_9 = 0x09,
    USIM_LOGIC_CH_10 = 0x0a,
    USIM_LOGIC_CH_11 = 0x0b,
    USIM_LOGIC_CH_12 = 0x0c,
    USIM_LOGIC_CH_13 = 0x0d,
    USIM_LOGIC_CH_14 = 0x0e,
    USIM_LOGIC_CH_15 = 0x0f,
    USIM_LOGIC_CH_16 = 0x10,
    USIM_LOGIC_CH_17 = 0x11,
    USIM_LOGIC_CH_18 = 0x12,
    USIM_LOGIC_CH_19 = 0x13,
    USIM_LOGIC_CH_SIZE,
    USIM_LOGIC_CH_INVALID = 0xFF
} usim_logic_channel_enum;

typedef enum
{
    AKA_CONTEXT,
    GBA_CONTEXT,
    MAX_AUTH_CONTEXT
} uicc_auth_mode_enum;

typedef enum
{
    SIM_INFO_ATR,
    SIM_INFO_CDMA,
    SIM_INFO_MAX
}sim_query_info_enum;

typedef enum
{
   SIM_ECALL_NONE,
   SIM_ECALL_ONLY,
   SIM_ECALL_AND_NORMAL,
   SIM_ECALL_TEST_DISABLE //for ecall test simulation
}sim_ecall_mode_enum;

typedef enum
{
    GSMCDMA_DUALSIM_DISCONNECT,
    GSMCDMA_DUALSIM_CONNECT
}gsmcdma_dualsim_mode_enum;

typedef enum
{
    DUALSIM_CMD_SUCCESS,
    DUALSIM_CMD_FAIL_RESET_ABNORMAL,
    DUALSIM_CMD_FAIL_CHVINFO_ABNORMAL,
    DUALSIM_CMD_FAIL_DISCONNECT_NOT_ALLOWED,
    DUALSIM_CMD_FAIL_CONNECT_NOT_ALLOWED,
    DUAKSIM_CMD_FAIL_UNDEFINED_OPERATION,
    DUALSIM_CMD_FAIL_PUK_STATE
}gsmcdma_dualsim_result_enum;

typedef enum
{
   VERIFY,
   DISABLE,
   ENABLE,
   CHANGE,
   UNBLOCK,
   SUPER_VERIFY, //link_SML
}sim_security_operation_enum; /*[MAUI_03058435] mtk01612: move sim_security_operation_enum into this file due to HAL rule*/

typedef enum
{
   TYPE_ONLY_DIGIT,         // mtk01488: digit only and sms default alphabet
   TYPE_SMS_DEFAULT_SET,    // mtk01488: alphabet set and SMS default alphabet
   TYPE_UCS2,               // mtk01488: alphabet set and UCS2 alphabet
   TYPE_YES_NO,
   TYPE_ONLY_DIGIT_UCS2     // mtk01488: digit only and UCS2 alphabet
}sat_input_type_enum;

typedef enum
{
   SAT_CMD_PERFORMED_SUCCESSFULLY=	0,
   SAT_CMD_PERFORMED_WITH_PARTIAL_COMPREHENSION=	0X01,
   SAT_CMD_PERFORMED_WITH_MISSING_INFO=	0X02,
   SAT_REFRESH_PERFORMED_WITH_ADDITIONAL_EF_READ=	0X03,
   SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL=	0X04,
   SAT_CMD_PERFORMED_BUT_MODIFIED_CC_BY_SIM=	0X05,
   SAT_CMD_PERFORMED_LIMITED_SERVICE=	0X06,
   SAT_CMD_PERFORMED_WITH_MODIFIED=	0X07,
   SAT_PROACTIVE_CMD_TERMINATED_BY_USER=	0X10,
   SAT_BACKWARD_MOVE_IN_PROACTIVE_SESSION_BY_USER=	0X11,
   SAT_NO_RESPONSE_FROM_USER=	0X12,
   SAT_HELP_INFO_REQUEST_BY_USER=	0X13,
   SAT_USSD_SS_TRANSACTION_TERMINATION_BY_USER=	0X14,
   SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD=	0X20,
   SAT_NET_CURRENTLY_UNABLE_TO_PROCESS_CMD=	0X21,
   SAT_USER_DID_NOT_ACCEPT_THE_PROACTIVE_CMD=	0X22,
   SAT_USER_CLEAR_DOWN_CALL_BEFORE_CONNECTION_RELEASE=	0X23,
   SAT_ACTION_IN_CONTRACTION_WITH_CURRENT_TIMER_STATE=	0X24,
   SAT_INTERACTION_WITH_CALL_CTRL_BY_SIM_TEMPORARY_ERROR=	0X25,
   SAT_LAUNCH_BROWER_GENERIC_ERROR_CODE=	0X26,
   SAT_CMD_BEYOND_ME_CAP=	0X30,
   SAT_CMD_TYPE_NOT_UNDERSTAND_BY_ME=	0X31,
   SAT_CMD_DATA_NOT_UNDERSTAND_BY_ME=	0X32,
   SAT_CMD_NUMBER_NOT_KNOWN_BY_ME=	0X33,
   SAT_SS_RETURN_ERROR=	0X34,
   SAT_SMS_RP_ERROR=	0X35,
   SAT_ERROR_REQUIRED_VALUE_MISSING=	0X36,
   SAT_USSD_RETURN_ERROR=	0X37,
   SAT_MULTICARD_CMD_ERROR=	0X38,
   SAT_INTERACTION_WITH_CALL_CTRL_BY_SIM_PERMANENT_ERROR=	0X39,
   SAT_BEARER_INDEPENDENT_PROTOCOL_ERROR=	0X3A
}sat_terminal_res_enum;

typedef enum
{
   SAT_NO_SPECIFIC_CAUSE,
   SAT_SCREEN_BUSY,
   SAT_ME_CURRENTLY_BUSY_ON_CALL,
   SAT_ME_CURRENTLY_BUSY_ON_SS,
   SAT_NO_SERVICE,
   SAT_ACCESS_CTRL_CLASS_BAR,
   SAT_RR_NOT_BRANTED,
   SAT_NOT_IN_SPEECH_MODE,
   SAT_ME_CURRENTLY_BUSY_ON_USSD,
   SAT_ME_CURRENTLY_BUSY_ON_DTMF
}sat_additional_info_for_res_enum;

typedef enum
{
   SAT_LAUNCH_BROWSER_IF_NOT_ALREADY_LAUNCHED = 0x00,
   SAT_USE_EXISTING_BROWSER = 0x02,
   SAT_CLOSE_EXISTING_BROWSER_AND_LAUNCH_NEW = 0x03
}sat_launch_browser_mode_enum;

typedef enum
{
   SAT_LAUNCH_BROWSER_NO_SPECIFIC_CAUSE,
   SAT_LAUNCH_BROWSER_BEARER_UNAVALIABLE,
   SAT_LAUNCH_BROWSER_BROWSER_UNAVALIABLE,
   SAT_LAUNCH_BROWSER_ME_UNABLE_TO_READ_PROVISION_DATA
}sat_launch_browser_additional_info_for_res_enum;

typedef enum
{
   SAT_BROWSER_USER_TERMINATION,
   SAT_BROWSER_ERROR_TERMINATION
}sat_browser_termination_mode_enum;

/* proactive SIM command struct */
typedef enum
{
   SETUP_CALL_IF_NO_ANOTHER_CALL,
   SETUP_CALL_WITH_REDIAL_IF_NO_ANOTHER_CALL,
   SETUP_CALL_PUT_ANOTHER_HOLD,    
   SETUP_CALL_WITH_REDIAL_PUT_ANOTHER_HOLD,   
   SETUP_CALL_DISCON_ANOTHER,    
   SETUP_CALL_WITH_REDIAL_DISCON_ANOTHER   
}sat_setup_call_condition_enum;

typedef enum
{
   SAT_OPERATION_CHANGED_BY_SIM,
//   SAT_NUM_CHANGED_BY_SIM,
   SAT_NUM_CHANGED_CALL_TO_CALL,
   SAT_NUM_CHANGED_CALL_TO_SS,   
   SAT_NUM_CHANGED_CALL_TO_USSD,   
   SAT_NUM_CHANGED_SS_TO_CALL,   
   SAT_NUM_CHANGED_SS_TO_SS,
   SAT_NUM_CHANGED_SS_TO_USSD,   
   SAT_NUM_CHANGED_USSD_TO_CALL,   
   SAT_NUM_CHANGED_USSD_TO_SS,   
   SAT_NUM_CHANGED_USSD_TO_USSD,   
   SAT_NUM_CHANGED_SMS,   
//   SAT_ALPHA_ID_IND,
   SAT_CALL_NOT_ALLOWED,
   SAT_SS_NOT_ALLOWED,
   SAT_USSD_NOT_ALLOWED,
   SAT_SMS_NOT_ALLOWED,
   SIM_MEM_PROBLEM,
   SIM_SECRET_CODE_REJ,
   SIM_TECH_PROBLEM,
   SAT_ALLOWED_NO_CHANGE   
}sat_mmi_info_type_enum;

typedef enum
{
   SAT_TONE_DIAL=0x01,
   SAT_TONE_CALLED_SUBSCRIBER_BUSY=0x02,
   SAT_TONE_CONGESTION=0x03,
   SAT_TONE_RADIO_PATH_ACK=0x04,
   SAT_TONE_RADIO_NO_PATH=0x05,
   SAT_TONE_ERROR=0x06,
   SAT_TONE_CALL_WAITING=0x07,
   SAT_TONE_RING=0x08,
   SAT_TONE_GENERAL_BEEP=0x10,
   SAT_TONE_POS_ACK=0x11,
   SAT_TONE_NEG_ACK=0x12
}sat_tone_id_enum;

typedef enum
{

    SIM_RESET_SMART_DETECTION,
    SIM_RESET_USIM_PREFER,
    SIM_RESET_SIM_PREFER
} sim_reset_method_enum;

typedef enum
{
    SAT_NW_REJ_LOCATION_INFO,
    SAT_NW_REJ_ROUTE_AREA_ID,
    SAT_NW_REJ_TRACK_AREA_ID
} sat_nw_rej_info_enum;

/* Update/Attach Type, clause 8.92 in TS 31.111 */
typedef enum
{
    SAT_NW_REJ_TYPE_NORMAL_LU,                      /* 0x00: "Normal Location Update" for LOCATION UPDATING REQUEST */
    SAT_NW_REJ_TYPE_PERIODIC_LU,                    /* 0x01: "Periodic Updating" for LOCATION UPDATING REQUEST */
    SAT_NW_REJ_TYPE_IMSI_ATTACH,                    /* 0x02: "IMSI Attach" for LOCATION UPDATING REQUEST */
    SAT_NW_REJ_TYPE_GPRS_ATTACH,                    /* 0x03: "GPRS Attach" for GPRS ATTACH REQUEST */
    SAT_NW_REJ_TYPE_COMBINED_ATTACH,                /* 0x04: "Combined GPRS/IMSI Attach" for GPRS ATTACH REQUEST */

    SAT_NW_REJ_TYPE_RAU,                            /* 0x05: "RA Updating" for ROUTING AREA UPDATE REQUEST */
    SAT_NW_REJ_TYPE_COMBINED_RA_LAU,                /* 0x06: "Combined RA/LA Updating" for ROUTING AREA UPDATE REQUEST */
    SAT_NW_REJ_TYPE_COMBINED_RA_LAU_WITH_IMSI,      /* 0x07: "Combined RA/LA Updating with IMSI Attach" for ROUTING AREA UPDATE REQUEST */
    SAT_NW_REJ_TYPE_PERIODIC_RAU,                   /* 0x08: "Periodic Updating" for ROUTING AREA UPDATE REQUEST */

    SAT_NW_REJ_TYPE_EPS_ATTACH,                     /* 0x09: "EPS Attach" for EMM ATTACH REQUEST */
    SAT_NW_REJ_TYPE_COMBINED_EPS_IMSI_ATTACH,       /* 0x0A: "Combined EPS/IMSI Attach" for EMM ATTACH REQUEST */
    SAT_NW_REJ_TYPE_TAU,                            /* 0x0B: "TA updating" for EMM TRACKING AREA UPDATE REQUEST */
    SAT_NW_REJ_TYPE_COMBINED_TA_LAU,                /* 0x0C: "Combined TA/LA updating" for EMM TRACKING AREA UPDATE REQUEST */
    SAT_NW_REJ_TYPE_COMBINED_TA_LAU_WITH_IMSI,      /* 0x0D: "Combined TA/LA updating with IMSI attach" for EMM TRACKING AREA UPDATE REQUEST */
    SAT_NW_REJ_TYPE_PERIODIC_TAU                    /* 0x0E: "Periodic updating" for EMM TRACKING AREA UPDATE REQUEST */
} sat_nw_rej_type_enum;

/* UTRAN/E-UTRAN Measurement Qualifier, clause 8.73 in TS 31.111 */
typedef enum
{
    SAT_NMR_UTRAN_INTRA_FRQ         = 0x01,         /* 0x01: UTRAN Intra-frequency measurements */
    SAT_NMR_UTRAN_INTER_FRQ         = 0x02,         /* 0x02: UTRAN Inter-frequency measurements */
    SAT_NMR_UTRAN_INTRAT_GSM        = 0x03,         /* 0x03: UTRAN Inter-RAT (GERAN) measurements */
    SAT_NMR_UTRAN_INTRAT_EUTRAN     = 0x04,         /* 0x04: UTRAN Intra-RAT (E-UTRAN) measurements */
    SAT_NMR_EUTRAN_INTRA_FRQ        = 0x05,         /* 0x05: E-UTRAN Intra-frequency measurements */
    SAT_NMR_EUTRAN_INTER_FRQ        = 0x06,         /* 0x06: E-UTRAN Inter-frequency measurements */
    SAT_NMR_EUTRAN_INTRAT_GSM       = 0x07,         /* 0x07: E-UTRAN Inter-RAT (GERAN) measurements */
    SAT_NMR_EUTRAN_INTRAT_UTRAN     = 0x08          /* 0x08: E-UTRAN Inter-RAT (UTRAN) measurements */
} sat_nmr_qual_enum;

/*mtk01612:  [MAUI_02023545] BT_SIM_Profile for MAUI and DUMA*/
#define APDU_REQ_MAX_LEN    261 /* 256 bytes for data + 5 bytes header information: CLA,INS,P1,P2,P3 */
#define APDU_RSP_MAX_LEN    258 /* 256 bytes for data + 2 bytes status word SW1 and SW2 */
#define ATR_MAX_LEN                40
#define MAX_SAT_SIZE_OF_CCP (14+0) /* for L4A autogen to use macro directly */

#define MAX_SUPPORT_RECORD_SIZE 255 /*at present, each record cannot be greater than 254 or 255 bytes in linear fixed/cyclic file */
#define MAX_SUPPORT_RECORD_NUM  255 /*at present, no more than 254 or 255 records in linear fixed/cyclic file */
/* MAUI_02953154 */

#define usim_file_index_enum sim_file_index_enum

/* MAUI_03041489 : for moveing sim_profile to custom folder */
#ifdef __SAT_ADDITIONAL_LOCK__
#define SAT_ADDITIONAL_TER_PROFILE 9
#endif

#if defined(__REL7__) || defined(__SATCL__) || defined(__SATCM__) || defined(__SATCR__)
#define MAX_SIM_PROFILE_LEN      32
#else
#define MAX_SIM_PROFILE_LEN      18
#endif

/* +2 to support Rel.4 SIM card */
/*If you changed MAX_SST_LEN value, must patch [MAUI_03169422] to avoid TST exception for mini log feature*/
#ifdef __CPHS__
#define MAX_SST_LEN              17
#else
#define MAX_SST_LEN              15
#endif

/*If you changed USIM_SUPPORT_UST_LEN value, must patch [MAUI_03169422] to avoid TST exception for mini log feature*/
#define USIM_SUPPORT_UST_LEN   13 //__R7_EHPLMN__ // mtk80420: 23.122 R7 feature, extend service num to 74  //mtk01616_110502 for R8 __CSG_SUPPORT__ extend service to 86 // for __ECALL_SUPPORT__ extended to 89

#define SUPPORT_SIM_TOTAL      (MAX_SIM_NUM)

#endif
 
