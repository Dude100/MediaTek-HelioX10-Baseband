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
 *
 * Filename:
 * ---------
 * libParserDbModem.c
 *
 * Project:
 * --------
 * MOLY
 *
 * Description:
 * ------------
 * This file collects primitve IDs and struct definition from the Modem
 * application part for pre-processing.
 *
 * Author:
 * -------
 * -------
 *
 * =============================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [PFM] [IPCORE] Packet Filter Manager & Garbage Filter Implementation
 *
 * 10 22 2014 hong.yu
 * removed!
 * Merging to MP6
 *
 * 10 22 2014 hong.yu
 * removed!
 * Merging to MP6
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 06 25 2014 cw.wang
 * removed!
 * Merging
 *  	
 * 	//MOLY/TRUNK/MOLY/mcu/...
 *  	
 * 	to //MOLY/BRANCHES_LR9/LR9.W1423.MD.LWTG.MP/mcu/...
 *
 * 06 25 2014 cw.wang
 * removed!
 * [USBCLASS] cdcecm power saving enhancement
 *
 * 06 16 2014 ken.liu
 * removed!
 * re-enable l1 boxster.
 *
 * 06 09 2014 ken.liu
 * removed!
 * re-enable l1 boxster.
 * 05 28 2014 max.mo
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	open AGPSD/ATCI interface for TDD modem
 *
 * 05 16 2014 max.mo
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	[CCCI] Show CCCI IPC ILM's local parameter in ELT
 *
 * removed!
 * removed!
 * CCCI IPC msgid rename - L4
 *
 * 04 29 2014 ken.liu
 * removed!
 * rollback L1boxster to align ELT support.
 *
 * 04 16 2014 ken.liu
 * removed!
 * enable l1boxster by default.
 *
 * 04 15 2014 ken.liu
 * removed!
 * Disable l1boxster by default due to incorrect usage of L1 trace API in AST L1 module.
 *
 * 04 15 2014 ken.liu
 * removed!
 * enable L1Boxster support and optimization.
 *
 * removed!
 * removed!
 * Set breakpoint/watchpoint via ILM
 *
 * removed!
 * removed!
 * [LPP] L4, CISS
 *
 * removed!
 * removed!
 * [LPP] LPP module and interface.
 *
 * removed!
 * removed!
 * add l4c_lbs_struct.h
 *
 * removed!
 * removed!
 * el1 related code
 *
 * 03 13 2014 ryan.ou
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	.
 *
 * 03 06 2014 hk.yang
 * removed!
 * Add dhl sp loging trace
 *
 * removed!
 * removed!
 * .Gemini RSVAE check-in
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Add a new table msg_id_access_level_map and a new file em_mapping_for_tool.h
 *
 * removed!
 * removed!
 * Common and IMC config files
 *
 * removed!
 * removed!
 * [DBME] H/G+W/G.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 10 18 2013 bo.wu
 * removed!
 * .
 *
 * removed!
 * removed!
 * Integration change.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * MOLY
 *
 * removed!
 * removed!
 * Log UL/DL Ip header content
 *
 * 07 18 2013 aj.tsai
 * removed!
 * Integrate AOMgr Related code
 * add  aomgr trace log.
 * refine aomgr code.
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * Interface Check-in
 *
 * removed!
 * removed!
 * [IPCORE] Add ipcore related header files into DHL Database.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 *
 * 06 03 2013 ken.liu
 * removed!
 * add msg id to em_info_enum mapping table.
 *
 * removed!
 * removed!
 * add EM Related message ID, EM Info Type.
 *
 * removed!
 * removed!
 * Remove TFTLIB compile options
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Back out changelist 156018
 * patch for QMU_BM/UPCM/RATADP/TFT_PF trace
 *
 * removed!
 * removed!
 * add tft_pf/qmu_bm/upcm/ratadp trace
 *
 * removed!
 * removed!
 * EM parameter modification
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * SWTR merge
 *
 * removed!
 * removed!
 * add MOD_PSDM into required files
 *
 * 03 14 2013 ye.yuan
 * removed!
 * .
 *
 * 01 29 2013 ken.liu
 * removed!
 * add log header.
 *
 *******************************************************************************/

#ifdef _MODIS_ON_VC9_
#define __w64
#endif
typedef int cgen_use_spare_msg_id;
typedef int cgen_use_spare_sap_id;
typedef int cgen_use_spare_module_id;
typedef unsigned short msg_type;
typedef unsigned short sap_type;
typedef unsigned short module_type;

#if defined(__MTK_TARGET__) && !defined(__UE_SIMULATOR__)
  #if !(defined(__GSM_RAT__) && defined(__MD2__))
    typedef int cgen_use_L1Boxster;
  #endif
#endif

#ifdef __GNUC__
  typedef struct __va_list { void *__ap; } __builtin_va_list;
  #define INLINE __inline
  #define inline __inline
#endif

#define __declspec(s)
//"ps\\tools\\asn1lib\\include\\act-ttbuffmgr.h"
#undef STDC_HEADERS //it will include stdio.h

#ifdef __RVCT__
#ifndef __int64
   typedef  long long __int64;
#endif


#define _ARMABI

#endif

#ifdef __UE_SIMULATOR__
#ifndef __int64
	typedef  long long __int64;
#endif
//#include "TrcMod.h"
#include "L1Trc.h"
#endif

#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "sap_info.h"
#include "msg_id_to_em_info_map.h"
#include "em_mapping_for_tool.h"

#include "kal_trace.h"
/* #include "stack_ltlcom.h" Reduce 2 service global include path*/

#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "stack_timer.h"
#include "event_shed.h"

#include "intrCtrl.h"

#include "SST_sla.h"

/* l1 */
#include "mph_types.h"
#include "mph_cs_def.h"
#include "mph_cs_msg.h"
#ifdef __PS_SERVICE__
#include "mph_ps_def.h"
#include "mph_ps_msg.h"
#endif
#if ( defined(__GSM_RAT__) || defined(__UMTS_RAT__) )
/* For Dual Mode L1 */
#include "mph_dm_def.h"
#include "mph_dm_msg.h"
/* For Dual Mode L1 */
#endif /* __GSM_RAT__ && __UMTS_RAT__ */

#include "GV.h"
#include "dhl_def.h"
#include "dhl_sp_logging.h"
#include "dhl_internal_def.h"
#ifdef UNIT_TEST
#include "dhlsim_def.h"
#endif

#ifdef __MINI_LOG_SUPPORT__
#include "tst_mini_log.h"
#endif /* __MINI_LOG_SUPPORT__ */

#if defined(GEN_FOR_PC)
#include "tst_Catcher_version.h"
#include "tst_catcher_diagonsis_info.h"
#endif  //#if defined(GEN_FOR_PC)

#ifndef NWSEL_NOT_PRESENT
#include "nwsel_msgid.h"
#include "nwsel_mm_struct.h"
#include "nwsel_ratcm_struct.h"
#include "rac_nwsel_struct.h"
#include "nwsel_context.h" 
#include "nwsel_def.h"
#include "nwsel_eval_struct.h"
#endif

#ifdef DUMMY_PROTOCOL
#ifdef __GSM_RAT__
#include "dps_testTool.h"
#include "dps_rlc_sap.h"
#endif //__GSM_RAT__
#endif

/* other module */

#ifndef __L1_STANDALONE__
/*For Protol modules*/

#ifdef __PS_SERVICE__
//#include "asn-incl.h"
#endif

#include "l4c_common_enum.h"
#include "l4_defs.h"
#include "irat_common_struct.h"

/* FLC */
#if defined(__FLC2__) && defined(__FLC_SUPPORT__)
#include "flc2_config.h"
#endif
#include "flc2stack_struct.h"


#include "mcd_l4_common.h"

#ifdef __MOD_CC__
#include "mcd_ss_parameters.h"
#include "mcd_ss_tcapmessages.h"
#include "mcd_cc_peer.h"
#include "ps2sat_struct.h" /* Ripple SATCE */
#include "l4c_common_enum.h"
#include "csmcc_enums.h"
#include "csmcc_common_enums.h"
#include "ps2sat_struct.h"
#include "l4c2csm_cc_struct.h"
#include "mncc_struct.h"
#include "mm2cm_struct.h"
#include "cm2mm_struct.h"
#include "cm2csce_struct.h"


#include "stacklib.h"
#include "event_shed.h"
#include "stack_timer.h"
#include "cc_defs.h"
#include "cc_std_defs.h"
#include "cc_ss_defs.h"
#include "cc_types.h"
#endif


#ifdef __MOD_CSM__
#include "mcd_ss_parameters.h"
#include "mcd_ss_tcapmessages.h"
#include "ps2sat_struct.h" /*  Ripple SATCE */
#include "l4c_aux_struct.h"
#include "l4c_common_enum.h"
#include "csmcc_enums.h"
#include "csmcc_common_enums.h"
#include "ps2sat_struct.h"
#include "l4c2csm_cc_struct.h"
#include "mncc_struct.h"

#include "stack_timer.h"
#include "l4_defs.h"
#include "csmcc_defs.h"
#include "csmcc_bc_defs.h"
#include "csmcc_bc_types.h"
#include "csmcc_common_enums.h"
#include "csmcc_enums.h"
#include "csmcc_types.h"
#include "csmcc_atfunc.h"

#include "l4c2csm_ss_struct.h"

#ifdef __AGPS_CONTROL_PLANE__
/* SSAGPS */
#ifdef GEN_FOR_PC
    #ifndef __RVCT__
			#define __int64
    #endif	//#if !defined(__RVCT__)
#define __cdecl
#endif //#ifndef __L1_STANDALONE__

//#include "applib_asn_ber_common.h" /* SSAGPS */
#include "applib2_asn_common.h" /* SSAGPS */
#include "applib2_mtkasn_global.h" /* SSAGPS */
#include "ss_asn.h" /* SSAGPS */
#include "l4c2csm_ss_lcs_struct.h" /* SSAGPS */
#endif
#include "l4c_lbs_struct.h" /* SSAGPS */

#include "mnss_struct.h"
#include "csmss_common_enums.h"
#endif /*__MOD_CSM__*/

#ifdef __MOD_SIM__
#include "stack_timer.h"
#include "sim_common_enums.h"

#include "phb_utils.h"
#include "ps2sat_struct.h" /* Ripple SATCE */
#include "l4c2csm_cc_struct.h" /* ripple */
#include "l4c_common_enum.h"
#include "csmcc_enums.h"
#include "csmcc_common_enums.h"
#include "ps2sat_struct.h"
#include "l4c2csm_cc_struct.h"
 /* ripple */
#include "cc2sat_struct.h" /* ripple */
#include "sat_def.h"
#include "ps2sim_struct.h"


#endif /*__MOD_SIM__*/

#ifdef __MOD_SMU__

#if defined(__MMI_FMI__)
#endif
#include "l4c2smu_struct.h"
#include "ps2sim_struct.h"
#include "ps2sat_struct.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#include "smu_def.h"
#endif /*__MOD_SMU__*/

#ifdef __MOD_PHB__
#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"
#endif /*__MOD_PHB__*/

#ifdef __MOD_UEM__
#include "device.h"
#include "uart_sw.h"
#include "mcd_uem_peer.h"
#endif /*__MOD_UEM__*/

#ifdef __MOD_SMSAL__
#include "smsal_l4c_defs.h"
#include "smsal_l4c_enum.h"

/* for context */
#include "l3_inc_enums.h"
#include "smsal_timer.h"
#include "smsal_enums.h"
#include "smsal_defs.h"
#include "l4c2smsal_struct.h"
#include "mcd_l4c2smsal_peer.h"
#include "smsal_peer_struct.h"

#include "mnsms_struct.h"
#include "smsal_structs.h"
#include "smsal_context.h"
#endif /*__MOD_SMSAL__*/

#ifdef __MOD_SMS__

/* SMS <--> SMSAL */
//#include "stack_timer.h"
#include "mnsms_struct.h"
#include "sms_enum.h"
//#include "lcd_cqueue.h"
#include "event_shed.h"
#include "sms_timer.h"

/* SMS Context */
#include "sms_defs.h"
#include "sms_tl.h"
#include "sms_rl.h"
#include "sms_cm.h"
#include "sms_context.h"

/* SMS <--> MM */
#include "mcd_sms_gen_peer.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "cm2mm_struct.h"
#include "mm2cm_struct.h"
#include "sms2mm_struct.h"
#include "mm2sms_struct.h"
#endif

#ifndef PPP_NOT_PRESENT
#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "tcm2sm_struct.h"
#include "l4c2ppp_struct.h"
#include "ppp2l4c_struct.h"
#include "tcm2ppp_struct.h"
#include "ppp2tcm_struct.h"
#include "ppp_l4_enums.h"
/* PPP for CSD usage */
#include "tcpip2ppp_struct.h"
//#include "ppp2tcpip_struct.h"
#include "ppp2csd_struct.h"
 #ifdef __PPP_UT__
  #include "ppp_types.h"
  #include "ppp_buff_mgr.h"
  #include "ppp_fsm.h"
  #include "ppp_crc.h"
  #include "ppp_lcp.h"
  #include "ppp_ipcp.h"
  #include "ppp_main.h"
  #include "ext_modem_ppp_struct.h"
 #endif // ~ #ifdef __PPP_UT__
#endif /*  ~PPP_NOT_PRESENT */

#ifdef __MOD_CISS__
#include "mcd_ss_parameters.h"
#include "mcd_ss_tcapmessages.h"
#include "mnss_struct.h"
#include "mm2cm_struct.h"
#include "cm2mm_struct.h"
#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "mcd_ciss_peer.h"
#include "ciss_enum.h"
#include "ciss_eval_struct.h"
#endif /* __MOD_CISS__ */

//#ifdef __PS_SERVICE__
#ifdef __MOD_TCM__
#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "tcm2sm_struct.h"
#include "sm2tcm_struct.h"
#include "rat_tcm_context.h"
#if defined(__MMI_FMI__)
#endif
#include "l4c2abm_struct.h"
/* mtk00938 2008-02-20: for streaming and secondary PDP context */
#include "mmi_sm_enums.h"
/* End of Jeff Wu */
#include "abm2l4c_struct.h"
#include "l4c2tcm_struct.h"
//#include "tcm_common_enums.h"
//#include "tcm_common.h"
#include "l4c2tcm_func.h"
#include "tcm2l4c_struct.h"
#include "ppp2tcm_struct.h"
#include "tcm2ppp_struct.h"
#include "snd2tcm_struct.h"
#include "tcm2snd_struct.h"
//#include "tcm_timer.h"
#include "tcm_rattcm_struct.h"
#include "tcm_context.h"

#include "tcm_assert.h"
#include "tcm_at_handler.h"
#include "tcm_gprs_statistic.h"
#include "tcm_init.h"
#include "tcm_main.h"
#include "tcm_pco_api.h"
#include "tcm_qos_api.h"
#include "tcm_reset.h"
#include "tcm_send_msg.h"

#ifdef __TURN_ON_GENERAL_SECONDARY_PDP__
#include "tcm_tft_api.h"
#endif /* __TURN_ON_GENERAL_SECONDARY_PDP__ */

#ifdef __ACL_SUPPORT__
#include "tcm_acl_support.h"
#endif /* __ACL_SUPPORT__ */

#ifdef __UGTCM__
#include "tcm_ugtcm_check.h"
#include "tcm_ugtcm_fsm.h"
#include "tcm_ugtcm_send_msg.h"
#include "tcm_ugtcm_timer.h"
#endif /* __UGTCM__ */

#endif /* __MOD_TCM__ */
//#endif /* __PS_SERVICE__ */

#include "nwsel_def.h"
#include "nwsel_context.h"
#include "rac_nwsel_struct.h"
#include "nwsel_mm_struct.h"
#include "nwsel_ratcm_struct.h"

#ifndef RR_NOT_PRESENT
#ifdef __UMTS_RAT__
#include "as_common.h"
#endif

/* For Poring CSN.1*/

#include "rr_common_headers.h"
#include "rr_common_def.h"
#include "rr_context.h"


#include "rr_mpal_interface.h"
#include "rmc_lapdm_interface.h"

#include "security_keys_enums.h"
#include "security_keys_struct.h"
#include "as2nas_struct.h"
#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "l3_inc_enums.h"

#ifdef __UMTS_RAT__
/* John 2006/06/10*/
#include "mcd_l3_inc_struct.h"
#include "l3_inc_enums.h"
#include "l3_inc_local.h"
#include "csi_asn.h"
#ifdef __GSM_RAT__
#include "csi_gsm_asn.h"    // Defines e.g., `CsiGsmBaRangeList'
#endif
#ifdef __UMTS_RAT__
#include "csi_umts_asn.h"   // Defines e.g., `CsiFddUmtsCellList'
#endif

#include "uas_gas_enums.h"
#include "uas_gas_struct.h"
#include "mrs_utility.h"

#ifdef __LTE_RAT__
#include "uas_eas_struct.h"
#include "gas_eas_struct.h"
#endif
#include "mrs_as_struct.h"
#include "rac_mrs_struct.h"

#if defined(__SGLTE__)
#include "gas_el1_struct.h"
#endif
#if defined(__LTE_RAT__)
#include "l4c_el1_struct.h"
#endif

#ifdef __GEMINI__
#include "uas_gas_gemini_struct.h"
#endif /* __GEMINI__ */

/* For generating 3G LBM TRACE_PEER enum */
#include "ratcm_loop_mode.h"

#endif /* __UMTS_RAT__ */

#if defined(__GEMINI__)
#include "rsvas_enum.h"
#include "rsvas_struct.h"
#if defined(__UMTS_RAT__)
#include "rsvak_enum.h"
#include "rsvak_struct.h"
#include "urr_rsvau_struct.h"
#ifdef __GSM_RAT__
#include "gas_rsva_struct.h"
#endif /* __GSM_RAT__ */
#endif /* __UMTS_RAT__ */
#ifdef __LTE_RAT__
#include "eas_rsva_struct.h"
#include "rsvae_fsm.h"
#endif /* __LTE_RAT__ */
#endif /* __GEMINI__ */

#ifdef __GEMINI__
#include "as_access_sem_context.h"
#include "as_access_sem_funcs.h"
#endif /* __GEMINI__ */

#include "rr2lapdm_struct.h"
#include "rr2mpal_struct.h"
#include "mpal2rr_struct.h"
#include "rrm2rmpc_struct.h"
#include "lapdm2rr_struct.h"
#ifdef __GEMINI_GSM__
#include "rr2prr_struct.h"
#endif
#include "mph_cs_msg.h"
#include "sim_common_enums.h"

/* CSN codec*/
#include "mtk_csn.h"

#ifdef __PS_SERVICE__
#include "gprs_rlcmac_ul.h"
/* Evelyn 20090415: Merge R6 */
#if defined(__MTBF__) || defined(__PS_HO__)
#include "gprs_mtbf.h"
#endif
#ifdef __PS_HO__
#include "ps_ho.h"
#endif
#endif

#include "rrm_context.h"
#include "lapdm_common.h"
#include "psi_si_common.h"
#include "si.h"
#include "si_context.h"
#include "rr_sendmsgs_to_mpal.h"
#include "si_update_funcs.h"
#include "si_msg_decode.h"
#include "rmc_enums.h"
#include "rmc_peer_msg_enums.h"

#ifdef __PS_SERVICE__
#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "l3_inc_enums.h"

/* peer message */
#include "si_peer.h"
#include "rmc_peer_dl.h"
#include "nstd_alloc_bitmap.h"
#include "nstd_mobile_alloc_peer.h"
#include "nstd_pmo.h"
#include "gprs_rlcmac_dl.h"
#include "nstd_pkt_meas_report.h"
#include "gprs_rlcmac_ul.h"
#include "rmc_peer.h"
#include "gprs_rlcmac_peer.h"
#include "meascell.h"
#include "gprs_rlcmac_common.h"

#include "llcrlc_enums.h"
#include "rlc_mac_enums.h"
#include "rmpc_rlc_enums.h"
#include "llc2rlc_struct.h"
#include "rlc2mac_struct.h"
#include "rlcmac_struct.h"
#include "mac2rlc_struct.h"
#include "mac2rmpc_struct.h"
#ifdef __ADAPTIVE_PAGING_PERIOD_IN_UNACK_MODE__
#include "rlc2rmpc_struct.h"
#endif
#include "rmpc2rlc_struct.h"
#include "rmpc2mac_struct.h"
#include "rlc2reasm_struct.h"
#include "reasm2rlc_struct.h"
#include "rr_data_ind.h"
#include "psi_si_common.h"
#include "psi.h"
#include "mac_context.h"
#include "rlc_context.h"
#include "reasm_context.h"
#ifndef __MTK_TARGET__
#include "gprs_rlcmac_common_struct.h"
#endif

/* for RMP */
#include "rmp_pktacc.h"
#include "rmp_context.h"
#endif /* end of __PS_SERVICE__ */

#ifdef __UMTS_RAT__
#include "uas_gas_enums.h"

#ifdef __GEMINI__
#include "uas_gas_gemini_struct.h"
#endif /* __GEMINI__ */
#endif /* __UMTS_RAT__ */

#include "meas_context.h"
#include "rmc_context.h"

#include "rcs_context.h"

#include "lapdm_context.h"
#include "rmc_common_access.h"
#include "rmc_cell_resel.h"
#include "rmpc_common_func.h"
#include "rmc_meas.h"
#include "rr_utils.h"
#include "rr_peh.h"
#include "rmc_dedicated_proc.h"
#include "csrr_utils.h"
#include "csrr_recv_lapdm_mesgs.h"
#include "csrr_recv_mpal_mesgs.h"
#include "csrr_ded_access.h"
#include "csrr_ded_proc.h"
#include "rmc_dedicated_meas.h"
#include "rmpc_nbr_cell.h"

// Evelyn 20080902: For MAC UT
// Rachel 20101114: For MPAL UT
#include "mpal_context.h"



#include "mll1_msgid.h"
#include "mll1_eutran.h"
#include "mll1_gsm.h"
#include "mll1_umts_fdd.h"
#include "mll1_umts_tdd.h"


#ifdef __AGPS_CONTROL_PLANE__
#include "csrr_agps_context.h"
#endif

#endif /* RR_NOT_PRESENT */

#ifndef MM_NOT_PRESENT
#include "l3_inc_enums.h"
#include "mm_mmi_enums.h"
#include "mmcm_enums.h"
#include "mmas_enums.h"
#include "mm_ratcm_enums.h"
#include "mm_ratcm_struct.h"
#include "security_keys_enums.h"

#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "mcd_mm_common_gen_struct.h"
#include "mcd_mm_cs_peer_struct.h"

#include "security_keys_struct.h"
#include "mm2cm_struct.h"
#include "mm2mmi_struct.h"
#include "cm2mm_struct.h"
#include "mmi2mm_struct.h"
#include "mm_common.h"
#include "mm_cs_defs.h"

#include "mm_mmi_enums.h"
#include "l4crac_enums.h"
#include "l3_inc_enums.h"
#include "nvram_enums.h"
#include "mm2sms_enums.h"

#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "mmi2mm_struct.h"
#include "mm2mmi_struct.h"
#include "l4c2rac_struct.h"
#include "rac2l4c_struct.h"
#include "nvram_struct.h"
#include "as2mmi_struct.h"

#ifdef __PS_SERVICE__
#include "mcd_mm_ps_peer_struct.h"
#include "mm_ps_defs.h"
#include "mm_ps_context.h"
#endif

#include "mm_cs_context.h"
#include "mm_common_context.h"

#endif /* #ifndef MM_NOT_PRESENT */


#ifdef __MOD_L4A__
#include "l4a.h"
#endif

#ifdef WISDOM_MMI
#include "ws_msg_struct.h"
#endif

/**************************************************************************
 * GPRS NAS DATA PATH BEGINS
 **************************************************************************/
#ifdef __PS_SERVICE__

#include "sm2l4c_struct.h"
#include "l4c2sm_struct.h"
#include "sm_esm_struct.h"

#ifndef SNDCP_NOT_PRESENT
/* other needed struct and enums */
#include "snd_defines.h"
#include "sndllc_enums.h"
#include "data_plane_sm_enums.h"
#include "mcd_snd_peer.h"
/* sndcp peer struct */
/* sm local struct */
#include "snd2tcm_struct.h"
#include "tcm2snd_struct.h"
#include "snd2llc_struct.h"
#include "llc2snd_struct.h"
#include "llc2l3_struct.h"
#include "ratdm_sndcp_struct.h"
#include "snd_enums.h"
#include "snd_comp_interface.h"
#include "snd_flc.h"

#include "snd_xid.h"
#include "snd_rfc1144.h"
#include "snd_context.h"

#endif /* SNDCP_NOT_PRESENT */

#ifndef SM_NOT_PRESENT
/* other needed struct and enums */

#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "l3_inc_enums.h"
#include "mmi_sm_enums.h"
#include "data_plane_sm_enums.h"
#include "smmm_enums.h"
#include "sm_common_enums.h"

/* sm peer struct */
#include "mcd_sm_gen_peer.h"
/* sm local struct */
#include "sm2mm_struct.h"
#include "mm2sm_struct.h"
#include "data_plane2sm_struct.h"
#include "sm2data_plane_struct.h"
#include "tcm2sm_struct.h"
#include "sm2tcm_struct.h"
#include "sm_defines.h" /* Carlson SM UT GV */
#include "sm_context.h" /* Carlson SM UT GV */
#endif /* SM_NOT_PRESENT */



#ifndef LLC_NOT_PRESENT

/* other needed struct and enums */
#include "gmmllc_enums.h"
#include "mmllc_enums.h"
#include "l3llc_enums.h"
#include "sndllc_enums.h"
#include "llccipher_enums.h"
#include "llcrlc_enums.h"
#include "security_keys_enums.h"
/* In interface/include */
#include "llc_peer_interface.h"

/* llc local struct */
#include "security_keys_struct.h"
#include "cipher2llc_struct.h"
#include "l32llc_struct.h"
#include "llc2l3_struct.h"
#include "llc2rlc_struct.h"
#include "rlc2llc_struct.h"
#include "snd2llc_struct.h"
#include "llc2snd_struct.h"
#include "llc_flowctrl.h"

#include "ratcm_llc_struct.h"

/* llc asn peer struct (Order shall be kept) */
#include "mcd_llc_peer_struct.h"

/* other needed struct and enums */
#include "stacklib.h"
// #include "lcd_dll.h" // remove lcd_dll, replaced by ./mcd/kal/mlib/mlib_dll
#include "stack_timer.h"
#include "event_shed.h"
#include "llc_lcdiplqueue.h"

#include "llc_defs.h"
#include "llc_context.h"
#include "llc_specific_defines.h"

#endif /* LLC_NOT_PRESENT */

#endif /* __PS_SERVICE__ */

#endif /*__L1_STANDALONE__*/

/**************************************************************************
 * GPRS NAS DATA PATH ENDS
 **************************************************************************/

#ifndef DATA_NOT_PRESENT

#if defined(__CSD_T__) || defined(__CSD_NT__) || defined(__CSD_FAX__)
#include "ratcm_csd_interface.h"

#include "data_uart_simu.h"
#include "csm_data_enums.h"
#include "data_context.h"
#include "ppp2csd_struct.h"
#endif

#ifdef __CSD_NT__
#include "l2r2rlp_enums.h"
#include "l2r_defs.h"
#include "rlp_defs.h"
#include "l2r_enum.h"
#include "rlp_enums.h"
#include "rlp_common.h"
#include "l2r_context.h"
#include "data_xid_struct.h"
#include "csm2l2r_struct.h"
#include "l2r2rlp_struct.h"
#include "rlp_timer.h"
#include "rlp_context.h"
#endif /* __CSD_NT__ */


#ifdef __CSD_T__
#include "csm2tdt_struct.h"
#include "tdt_context.h"
#endif /* __CSD_T__ */

#ifdef __CSD_FAX__
#include "l4c2t30_enums.h"
#include "l4c2t30_struct.h"
#include "csm2t30_struct.h"
#include "t302fa_struct.h"
#include "fa_defs.h"
#include "fa_enums.h"
#include "fa_context.h"

#include "t30_defs.h"
#include "t30_enums.h"
#include "t30_params.h"
#include "t30_context.h"
#endif /* __CSD_FAX__ */
#endif /* DATA_NOT_PRESENT */

#include "m12190.h"
#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
#include "ul1cal.h"
#endif

#ifdef __AST_TL1_TDD__
#include "tl1cal_ast.h"
#endif

#include "l1cal.h"


//#ifdef __MCD__
//#include "mcd_channel_rel.h"
//#include "mcd_rmc_peer_dl.h"
//#include "mcd_rmc_peer.h"
//#include "mcd_si_peer.h"
//#include "mcd_measurement_report.h"

//#endif

#include    "uart_sw.h"

#ifdef __IRDA_SUPPORT__
#ifndef OBEX_NOT_PRESENT
#include "irda_enums.h"
#include "irda_struct.h"
#include "obex_app_enums.h"
#include "obex2app_struct.h"
#include "app2obex_struct.h"
#endif

#ifndef IRCOMM_NOT_PRESENT
#include "irda_enums.h"
#include "irda_struct.h"
#include "ircomm_app_enums.h"
#include "app2ircomm_struct.h"
#include "ircomm2app_struct.h"
#endif
#endif /* __IRDA_SUPPORT__ */

#if defined(__MOD_SMSAL__) && !defined(SOC_NOT_PRESENT) //kevin 05/23
#include "smsal2soc_struct.h"
#endif /*__MOD_SMSAL__*/

#ifndef __L1_STANDALONE__
#include "smsal_as_struct.h"
#endif

#ifdef __LTE_RAT__
#include "mll1_msgid.h"
#include "mll1_eutran.h"
#include "mll1_gsm.h"
#include "mll1_umts_fdd.h"
#include "mll1_umts_tdd.h"
#endif /*__LTE_RAT__*/

#if defined(__MOD_RAC__)
#include "l4c2rac_struct.h"
#include "rac2l4c_struct.h"
#include "rac_nwsel_struct.h"
#ifdef __LTE_RAT__
#include "rac_eval_struct.h"
#endif /* __LTE_RAT__ */
#include "mmi2mm_struct.h"
#include "mm2mmi_struct.h"
#include "rac_defs.h"
#include "rac_mrs_struct.h"
#include "rac_em_struct.h"
#include "rac_context.h"
#endif /* __MOD_RAC__ */

#ifndef L4_NOT_PRESENT
#include "rmmi_context.h"
#include "drvsignals.h"
#include "l4_ipc_msg_struct.h"
#endif

/* for BMT */
#include "drvsignals.h"
/* for BMT */

#include "audio_enum.h"

#ifdef __WIFI_SUPPORT__
#include "wndrv_cnst.h"
#include "wndrv_cal.h"
#include "wndrv_ft_types.h"
#include "wndrv_ft_msg.h"
#include "wndrv_supc_types.h"
#include "wndrv_supc_msg.h"
#include "wndrv_tool_types.h"
#include "wndrv_tool_msg.h"
#include "supc_abm_msgs.h"
#include "mmi2abm_struct.h"
#include "wndrv_abm_msg.h"
#ifdef WIFI_BB_MT5921
#include "wndrv_trace_enum.h"
#endif
#endif

#ifndef __L1_STANDALONE__
#ifdef GEN_FOR_PC
#include "sasken_msg.h"
#include "smsal_peer.h"
#include "mpal2rr_unpack_struct.h"
#include "rr2mpal_unpack_struct.h"
#if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
#include "nas_msg.h"
#endif

#ifdef __UMTS_RAT__
#include "ub_msg.h"
#endif /* #ifdef __UMTS_RAT__ */
#ifdef __PS_SERVICE__
#include "rlc2mac_unpack_struct.h"
#endif /*__PS_SERVICE__*/
#endif /*GEN_FOR_PC*/
#endif /*__L1_STANDALONE__*/

#ifdef __DT_SUPPORT__
#include "dt_common_enum.h"
#endif /*__DT_SUPPORT__*/
#include"l4c2dt_struct.h"

#ifdef __EXT_MODEM__
#include "ext_modem_ppp_struct.h"
#include "ext_modem_l4c_struct.h"
#endif

#ifdef __PS_SERVICE__
#include "ps_ratdm_struct.h"
#endif

#ifndef __MTK_TARGET__
#include "uart_sim_struct.h"
#endif


#ifdef __IPERF__
#include "soc_api.h"
#endif /* __IPERF__ */

#ifdef __DRM_SUPPORT__
#endif /* __DRM_SUPPORT__ */

#ifdef GIS_SUPPORT
#include "gis_struct.h"
#endif

#ifdef __CMUX_SUPPORT__
#include "cmux_struct.h"
#include "cmux_def.h"
#endif /* __CMUX_SUPPORT__ */

#ifdef __UPS_SUPPORT__
#include "ups_struct.h"
#ifdef __USB_TETHERING__
#include "ps_public_ups_enum.h"
#include "ps_public_ups_struct.h"
#include "rndis_def.h"
#endif /* __USB_TETHERING__ */
#endif /* __UPS_SUPPORT__ */

#ifdef __IPCORE_SUPPORT__
#include "ipc_struct.h"
#include "ipc_enums.h"
#endif /* __IPCORE_SUPPORT__ */

#ifdef __HIF_AOMGR_SUPPORT__
#include "aomgr_struct.h"
#include "aomgr_enums.h"
#endif /* __HIF_AOMGR_SUPPORT__ */

#ifdef __ETHERCORE_SUPPORT__
#include "ethercore_struct.h"
#endif /* __ETHERCORE_SUPPORT__ */

#ifdef __NMU_ENABLE__
#include "dhcp4c_struct.h"
#include "ndpc_struct.h"
#endif

#ifdef __USB_ECM_SUPPORT__
#include "cdcecm_struct.h"
#endif

#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
#include "gps_struct.h"
#endif

#ifndef __L1_STANDALONE__

/* for NAS/RATCM inerface */
#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "l3_inc_enums.h"

#include "ratcm_ratdm_struct.h"
#include "ratcm_context.h"
#include "smsal_ratcm_struct.h"

#ifdef __PS_SERVICE__
#include "mm_ratdm_struct.h"
#include "sm_ratdm_struct.h"

#ifndef UART_SW_H
#include "uart_sw.h"
#endif // ~ #ifndef UART_SW_H
#ifndef _PS_RATDM_STRUCT_H
#include "ps_ratdm_struct.h"
#endif // ~ #ifndef _PS_RATDM_STRUCT_H
#include "tcm_ratdm_struct.h"
#ifdef __UMTS_FDD_MODE__
#include "ndis_ratdm_struct.h"
#endif
/* L4C -> RATDM */
//#ifndef _L4C_RATDM_STRUCT_H
#ifdef __UMTS_FDD_MODE__
#include "l4c_ratdm_struct.h"
#endif
//#endif

/* For RATDM/RABM UT */
#include "dlist.h"
#include "ratdm_context.h"
#endif

#ifdef __GSM_RAT__
/* for RATCM/GAS interface */
#include "ratcm_gas_enums.h"
#include "ratcm_gas_struct.h"
#endif

#endif /* ! __L1_STANDALONE__ */

#if defined(__SGLTE__)
#include "psdm2l4c_enum.h"
#include "psdm2l4c_struct.h"
#include "psdm_enums.h"
#endif

/* mtk04121 */
#if defined(__MOD_TCM__)
#include "l3_inc_local.h"
#include "tcm2sm_struct.h"
#include "sm2tcm_struct.h"
#include "rat_tcm_context.h"
#include "flc2_config.h"
#include "mmi_sm_enums.h"
#include "l4c2tcm_struct.h"
#include "l4c2tcm_func.h"
#include "tcm_api.h"
#include "tcm2l4c_struct.h"
#include "tcm_rattcm_struct.h"
/* PPP Dial-up */
#include "ppp2tcm_struct.h"
#include "tcm2ppp_struct.h"
#include "snd2tcm_struct.h"
#include "tcm2snd_struct.h"
#include "tcm_rattcm_struct.h"
#include "tcm_context.h"
#include "tcm_assert.h"
#include "tcm_at_handler.h"
#include "tcm_gprs_statistic.h"
#include "tcm_init.h"
#include "tcm_main.h"
#include "tcm_pco_api.h"
#include "tcm_qos_api.h"
#include "tcm_reset.h"
#include "tcm_send_msg.h"

#ifdef __TURN_ON_GENERAL_SECONDARY_PDP__
#include "tcm_tft_api.h"
#endif /* __TURN_ON_GENERAL_SECONDARY_PDP__ */

#ifdef __ACL_SUPPORT__
#include "tcm_acl_support.h"
#endif /* __ACL_SUPPORT__ */

#ifdef __UGTCM__
#include "tcm_ugtcm_check.h"
#include "tcm_ugtcm_fsm.h"
#include "tcm_ugtcm_send_msg.h"
#include "tcm_ugtcm_timer.h"
#endif /* __UGTCM__ */

#if defined(__ETCM__)
#include "eval_msgid.h"
#include "upcm_msgid.h"
#include "tcm_eval_enums.h"
#include "tcm_eval_struct.h"
#include "tcm_upcm_struct.h"
#include "tcm_etcm_utility.h"
#endif
#endif

/**************************************************************************
 * WCDMA INTERFACE BEGINS
 **************************************************************************/
#ifdef __UMTS_RAT__
#ifdef __UMTS_FDD_MODE__
#include "ul1_cnst.h"
#include "ul1_def.h"
#include "ul1_struct.h"
#include "ul1hisr_struct.h"
#endif
#include "kal_public_api.h"

#ifdef __UMTS_FDD_MODE__
#include "mll1_umts_fdd.h"
#endif /*__UMTS_FDD_MODE__*/

#ifdef __UMTS_FDD_MODE__
#include "hal_ul1_def.h"
#include "hal_ul1_struct.h"
#endif /*__UMTS_FDD_MODE__*/

#ifdef __UL1_ON_MNT__
/* for UL1 MoDIS */
#include "ul1_types.h"
//#include "ul1c_struct.h"
#endif

#ifdef DUMMY_PROTOCOL
/* 3G DPS */
#include "udps_testTool.h"
#endif


/* for MAL1 interface */
#ifdef __MA_L1__
#include "mal1_def.h"
#include "cti_msg.h"
#include "dual_msg.h"
#include "mal1_struct.h"
#endif

#ifndef __L1_STANDALONE__

#include "as_common.h"

/* for UAS common structure and enums */
#include "uas_common_enums.h"
#include "uas_common_struct.h"

#ifdef GEN_FOR_PC
#include "mcd_rrc_asn.h"
//John 960724
#include "asn_aper_common.h"
#include "mcd_h245_asn.h"
#endif

#include "rrc_asn.h"
#include "urr_common.h"
//#ifdef __UMTS_FDD_MODE__
#include "urr_enums.h"
#include "urr_struct.h"
//#endif

/* for UAS internal interface */
/* for URR/UL2D interface */
#include "cbmc_enums.h"
#include "cbmc_struct.h"
#include "bmc_common.h"
#include "cpdcp_enums.h"
#include "cpdcp_struct.h"
#include "ccsr_struct.h"
#include "crabm_struct.h"
#include "meme_umac_enums.h"
#include "meme_umac_struct.h"
#include "meme_drlc_struct.h"
#include "rrce_urlc_enums.h"
#include "rrce_urlc_struct.h"
#ifdef __UMTS_FDD_MODE__
#include "rrce_pdcp_struct.h"
#endif
#include "rrce_umac_struct.h"
#include "rrce_bmc_struct.h"
#include "rrce_drlc_struct.h"


/* for URR/UL2 interface */
#include "ul2_common_def.h"
#include "crlc_enums.h"
#include "crlc_struct.h"
#include "cmac_enums.h"
#include "capability.h"      /* for cmac_struct.h */
#ifdef __UMTS_TDD128_MODE__
#include "tl1_cnst.h"
#include "tl1_def.h"
#include "tl1_struct.h"
#endif
#include "cmac_struct.h"
#include "umac_common_enums.h"  /* for UMAC trace */
#include "umac_context.h"  /* for UMAC UT */

/* for UL2/UL2D interface */
#ifdef __UMTS_FDD_MODE__
#include "rlc_cid.h" /* Roger 100310 : for compile option depend on ECO/IC version */
#endif
#include "csr_umac_enums.h"
#include "csr_umac_struct.h"
#include "csr_drlc_struct.h"
#include "pdcp_drlc_struct.h"
#include "rabm_pdcp_struct.h"
#include "drlc_urlc_struct.h"
#include "urlc_umac_enums.h"
#include "urlc_umac_struct.h"
#include "drlc_umac_struct.h"
#include "pdcp_urlc_struct.h"  /* Jeff Wu 2006-02-13: For RLC Reset and Reestablish */
#include "rlc_common.h"
#include "l2l_comm.h"
#include "ul2_common.h"
#include "ciphering_common.h"
#include "retransmission_buffer.h" /* frost: for MCD to parse urlc control pdu. */
#ifdef __UMTS_FDD_MODE__
#include "rlc_cid.h" /* Roger 100310 : for compile option depend on ECO/IC version */
#include "urlc_drv_enums.h"  /* Kathie: for rlc_hsupa_cmd_struct */
#include "urlc_drv_struct.h"   /* Kathie: for rlc_hsupa_cmd_struct */
#include "seq_common.h"
#include "rlc_drv_common.h" /* Peng-An: for rlc_cmd_struct using in urlc_seq_struct.h */
#include "rlc_drv_rx.h" /* Peng-An: for rlc_cmd_struct using in urlc_seq_struct.h */
#include "urlc_seq_struct.h"
#include "umac_seq_struct.h"
#include "cseq_struct.h"
#endif
/* for URR internal interface */
#include "urr_acknowledge.h"
#include "urr_slce_enums.h"
#include "urr_slce_struct.h"
#include "rrce_csce_enums.h"
#include "rrce_csce_struct.h"
#include "rrce_meme_enums.h"
#include "rrce_meme_struct.h"
#include "rrce_sibe_enums.h"
#include "rrce_sibe_struct.h"
#include "rrce_slce_enums.h"
#include "rrce_slce_struct.h"
#include "rrce_usime_struct.h"
#include "csce_usime_struct.h"
#include "seq_enums.h"
#include "seq_struct.h"
#include "csce_cse_enums.h"
#include "cse_racache.h"        // For showing cache content to Catcher...>#I
#include "csce_cse_struct.h"
#include "csce_meme_enums.h"
#include "csce_meme_struct.h"
#include "csce_sibe_enums.h"
#include "csce_sibe_struct.h"
#include "cse_slce_struct.h"
#include "csce_slce_struct.h"
#include "cse_meme_struct.h"
#include "cse_sibe_enums.h"
#include "cse_sibe_struct.h"
#include "sibe_slce_enums.h"
#include "sibe_slce_struct.h"
#include "adr_drlc_enums.h"
#include "adr_drlc_struct.h"
#include "bmc_drlc_struct.h"
#include "meme_sibe_enums.h"
#include "meme_sibe_struct.h"
#include "meme_slce_enums.h"
#include "meme_slce_struct.h"
#include "dbme_struct.h"
#include "urr_signal_in.h"
#include "nvram_data_items.h"
#include "ex_item.h"
#include "sim_public_enum.h"
//#ifdef __UMTS_FDD_MODE__
#include "sibe_enums.h"
#include "sibe_struct.h"
#include "usime_struct.h"
//#endif

/* discuss with SIM owner, UAS add sim header file when requirement.*/
#if ((defined(UNIT_TEST) && defined(__UMTS_TDD128_MODE__)) || defined(__SGLTE__))
#include "sim_private_struct.h"
#endif

/* for RATCM/UAS interface */
#include "ratcm_uas_enums.h"
#include "ratcm_slce_enums.h"
#include "ratcm_rrce_enums.h"
#include "usim_data.h"       /* for ratcm_rrce_struct.h */
#include "ratcm_uas_struct.h"
#include "ratcm_rrce_struct.h"
#include "ratcm_csce_enums.h"
#include "ratcm_csce_struct.h"
#include "ratcm_slce_struct.h"
#include "ratcm_cse_enums.h"
#include "ratcm_cse_struct.h"
#include "cs_types.h"
#include "ratcm_bmc_struct.h"
#include "ratcm_csr_struct.h"
#include "ratdm_rabm_struct.h"   /* should be after crabm_struct.h */
#include "ratcm_urlc_struct.h"
#include "ratdm_urlc_struct.h"
#include "ratcm_usime_struct.h"

/* for UAS/GAS interface */
#include "uas_gas_enums.h"
#include "uas_gas_struct.h"

#ifdef __GEMINI__
/* for GAS/UL2 interface */
#include "l3_inc_enums.h" /* for as_suspend_mode_reason_enum */
#include "gas_ul2_gemini_struct.h"
#include "gas_ul2d_gemini_struct.h"
#endif /* __GEMINI__ */

/*Vito: for CSR UT */
#include "rab.h"
#include "csr_fsm.h"

/* Jeff Wu 2006-02-13: For RABM/PDCP UT */
#include "as_common.h"
#include "flc2_config.h"
#include "cpdcp.h"
#include "pdcp.h"
#include "ps_data.h"
#include "bigend.h"
#include "pdcp_context.h"
#include "rabm_fsm.h"
#include "rabm_context.h"
#include "rabm_timer.h"

/* Evan Chen 2007-08-13: For MM UT */
#include "mm_common_context.h"
#include "mm_cs_context.h"
#include "mm_ps_context.h"
#include "mm_cs_defs.h"
#include "l3_inc_enums.h"
#include "mm_ratcm_enums.h"
#include "mm_common.h"
#include "mm_ps_defs.h"
#include "l3_inc_local.h"


/* Gibran Chang 2006/03/23: For CSCE */
#include "csce_fsm.h"
#include "csce_context.h"

/* Dennis Weng 2010/08/09: For SIBE */
#include "sibe_fsm.h"
/* YenChih Yang 2012/04/18: For USIME */
#include "usime_context.h"

/* For MEME */
/* For TDD please modify the code wrapped by __UMTS_TDD128_MODE__ */
/* For TDD please modify the code wrapped by __UMTS_FDD_MODE__ */
#ifdef __GEMINI__
#include "uas_gas_gemini_enums.h"
#endif

#if defined(__UMTS_TDD128_MODE__)
#include "meme_fsm.h"
#include "memetypes.h"
#include "em_struct.h"
#include "meme_def.h"
#include "rrc_meme_utilities.h"
#include "rrc_meme_timing.h"
#include "meme_context.h"
#include "rrc_protocol_timing.h"
#endif

#if defined(__UMTS_FDD_MODE__)
#include "meme_fsm.h"
#include "meme_def.h"
#include "rrc_meme_utilities.h"
#include "meme_context.h"
#include "rrc_meme_phys_layer.h"
#endif

/* MH Change 2006/04/18: For RRCE */
#include "rrci_fsm.h"
#include "rrcn_fsm.h"
#include "rrce_context.h"
#include "rrc_fsm_tmr_utils.h"
#include "rrce_fsm.h"

/* John Tang 2005/11/08: For DB Unit-test tool */
#ifdef GEN_FOR_PC

#define __int64
#define __cdecl
//#include "ub_msg.h"
#include "db_schema.h"
#include "db_io.h"
#include "db_dump_api.h"

#endif //#ifndef __L1_STANDALONE__


#include "rrc_db_all_struct.h"


/* Alfie: 2006-0422 For SLCE Trace Info Start */
#ifndef __size_t
#define __size_t 1
typedef unsigned int size_t;  /* used for dbme.h */
#endif

#include "uas_common_enums.h"
#include "dbme.h"
#include "db_access.h"
#ifdef __UMTS_FDD_MODE__
#include "dbme_context.h"
#endif
#include "crlc_enums.h"
#include "crlc_struct.h"
#include "rrce_slce_enums.h"
#include "seq_enums.h"
#include "seq_struct.h"
#include "slce_context.h"
#include "slce_fsm.h"
/* Alfie: 2006-0422 For SLCE Trace Info End */


/*Christine 2006/05/02*/
#include "transaction.h"
#include "rrcc_fsm.h"

#endif
//Matt 2007/11/30 for VT feature
/*
#ifdef __VIDEO_CALL_SUPPORT__
#include "vt_med_enum.h"
#include "vt_med_struct.h"
#include "vt_mmi_struct.h"
#include "..\..\..\3g324m\interface\inc\vt_tst_enum.h"
#include "..\..\..\3g324m\appl\inc\vt_ut_struct.h"
#include "csm2vt_struct.h"
#endif
*/

#endif /* __UMTS_RAT__ */
#ifdef __L1_STANDALONE__
#ifdef __MOD_NVRAM__
#include "nvram_data_items.h"
#include "ex_item.h"

#if defined(__MMI_FMI__)
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"
#endif

#include "nvram_editor_data_item.h"
#endif /*__MOD_NVRAM__*/
#endif
/**************************************************************************
 * WCDMA INTERFACE ENDS
 **************************************************************************/

#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
#include "gps_struct.h"
#ifdef __AGPS_SUPPORT__
#include "gps2lcsp_enum.h"
#include "gps2lcsp_struct.h"
#endif /* __AGPS_SUPPORT__ */
#endif

#ifdef __RRLP_SUPPORT__
#include "rr2rrlp_struct.h"
#include "rrlp_common_headers.h"
#include "rrlp_enum.h"
#endif /* __RRLP_SUPPORT__ */

#ifdef __AGPS_SUPPORT__

#if defined(__UAGPS_CP_SUPPORT__)
#include "uagps_cp_csce_struct.h"
#include "uagps_cp_sibe_struct.h"
#include "uagps_cp_meme_struct.h"
#include "l4c_uagps_cp_struct.h"
#include "uagps_cp_gps_struct.h"
#endif /* __UAGPS_CP_SUPPORT__ */

#endif /* __AGPS_SUPPORT__ */

#if defined(__AGNSS_SUPPORT__)
#include "gnss2lcsp_struct.h"
#include "gnss2lcsp_enum.h"
#endif /* #if defined(__AGNSS_SUPPORT__) */

/* for LPP*/
#if defined(__LTE_RAT__) && defined(__LPP_SUPPORT__)
#include "lpp_msg_struct.h"
#include "lpp_msg_enum.h"
#include "lpp_lbs_msg_struct.h"
#include "lpp_context.h"
#include "lpp_mcd_struct_id.h"
#endif

#include "as2l4c_struct.h"

#ifdef __ACMT_SUPPORT__
#include "nas2l4c_struct.h"
#endif

/*For UL1A*/
#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
#include "ul1a_enum.h"
#endif

#if defined (__WMT_SUPPORT__) || defined(__WIFI_BT_SINGLE_ANTENNA_SUPPORT__)
#include "wmt_struct.h"
#endif /* __WMT_SUPPORT__*/

#ifdef __GADGET_SUPPORT__
#include "widget_adp_struct.h"
#endif /* __GADGET_SUPPORT__ */

#if defined(__RMMI_UT__)
#include "l3_inc_struct.h"
//#include "mmi_sm_enums.h"
//#include "ppp_l4_enums.h"
#include "tcm_common_enums.h"
#include "tcm_common.h"
#include "tcm_timer.h"
//#include "l3_inc_local.h"
//#include "l4crac_enums.h"
//#include "rac2l4c_struct.h"
//#include "mmi2mm_struct.h"
//#include "rac_defs.h"
#include "tcm_context.h"
#endif

#ifndef __MTK_TARGET__
#include "l4c_context.h"
#endif

#ifndef __L1_STANDALONE__
#include "rmmi_common_enum.h"
#include "rmmi_struct.h"
#endif
#ifdef __VIDEO_ARCHI_V2__
#endif /* __VIDEO_ARCHI_V2__ */

/* mpl & source*/
//#include "mpl_common.h"
//#include "mpl_player.h"

#if defined(__L1_GPS_REF_TIME_SUPPORT__) || defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__)
#include "hal_l1_struct.h"
#endif /*(__L1_GPS_REF_TIME_SUPPORT__) || (__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__)*/

#if defined (__MOD_NVRAM__)
#include "nvram_editor_data_item.h"
#endif
/* mtk04121 */

/* SIM CODEGEN begin */
#ifndef SIM_NOT_PRESENT
#include "sim_ps_struct.h"
#include "sim_public_struct.h"
#endif
/* SIM CODEGEN end */

/* EVAL CODEGEN begin */
#ifdef __EVAL_ENABLE__
#include "eval_msgid.h"
#include "l4c_eval_struct.h"
#include "nwsel_eval_struct.h"
#include "rac_eval_struct.h"
#include "tcm_eval_struct.h"
#include "sms_eval_struct.h"
#include "smsal_eval_struct.h"
#endif
/* EVAL CODEGEN end */

//etc interface
#include "etc_upcm_struct.h"
#include "etc_msgid.h"

/* TFTLIB CODEGEN */
#include "tftlib_common_struct.h"
#include "tftlib_msgid.h"
#include "tftlib_msg_struct.h"

/* mtk00938: Multimode interfaces */
#ifdef __LTE_RAT__
#include "mm_emm_struct.h"
#include "sm_esm_struct.h"
#endif

/* mtk00938: This file is necessary even without LTE */
#include "irat_common_struct.h"

#include "mddbg.h"
/* global enum */
/***************************************************************
*  if add _msgid.h or _sap.h file, should include the _msgid.h or _sap.h in :                *
*    kal_debug_msg_sap_defs.h & libParseDbModem.c & srcParseDbModem.c          *
****************************************************************/
#include "module_msg_range.h"
#include "sysservice_msgid.h"	
#include "cc_msgid.h"	
#include "ciss_msgid.h"	
#include "mm_msgid.h"	
#include "sms_msgid.h"	
#include "sim_public_msgid.h"	    
#include "sim_ps_msgid.h"
#include "ps_public_l4_msgid.h"	
#include "l4_msgid.h" 
#include "psdm_msgid.h"
#include "rr_msgid.h"
#include "llc_msgid.h"    
#include "p2p_msgid.h"     
#include "sndcp_msgid.h"   
#include "sm_msgid.h"    
#include "data_msgid.h"
#include "ps_public_vt_msgid.h"    
#include "VT_msgid.h"    
#include "nvram_msgid.h"      
#include "l1_msgid.h"    
#include "hal_l1_msgid.h"    
#include "l1hisr_msgid.h"     
#include "ft_msgid.h"   
#include "tst_msgid.h"    
#include "audio_msgid.h"    
#include "cldmacore_msgid.h"
#include "ratcm_msgid.h"    
#include "ratdm_msgid.h"    
#include "urr_msgid.h"    
#include "ul2_msgid.h" 
#include "ul2d_msgid.h"  
#include "uas_gas_msgid.h"     
#include "mrs_msgid.h"
#include "uas_gas_gemini_msgid.h"	
#include "ul1_msgid.h"    
#include "ul1data_msgid.h"     
#include "ul1hisr_msgid.h"   
#include "ul1c_msgid.h"    
#include "ll1_msgid.h"     
#include "ul1tst_msgid.h"     
#include "ulcs_msgid.h"    
#include "lpp_msgid.h"
#include "tl1_msgid.h"    
#include "tl1data_ast_msgid.h"      
#include "tl1hisr_ast_msgid.h"     
#include "tl1fta_ast_msgid.h"   
#include "rsva_msgid.h"
#include "ndis_msgid.h"     
#include "ps_public_ups_msgid.h"    
#include "ups_msgid.h"     
#include "ps_public_supl_msgid.h"      
#include "supl_msgid.h"     
#include "cmux_msgid.h"     
#include "ppp_msgid.h"	
#include "ext_modem_msgid.h"	
#include "wmt_msgid.h"
#include "em_msgid.h"    
#include "fs_msgid.h"         
#include "med_msgid.h"    
#include "dps_msgid.h"   
#include "udps_msgid.h"
#include "drv_msgid.h"    
#include "meut_msgid.h"	
#include "l1_ext_msgid.h"	
#include "haplus_msgid.h"
#include "hif_mw_msgid.h"
#include "hif_svc_msgid.h"

#include "sap_range.h"
#include "svc_sap.h"	
#include "md_sap.h"	
#include "md_svc_sap.h"	
#include "md_drv_sap.h"	
#include "md_mmi_sap.h"	
#include "md_mw_sap.h"	
#include "mw_sap.h"	
#include "drv_sap.h"

#include "srv_modid.h"
#include "modem_2g3g_modid.h"
#include "modem_4g_modid.h"
#include "middleware_modid.h"
#include "drv_modid.h"
#include "hisr_modid.h"
#if defined(__GSM_RAT__) || defined(__UMTS_RAT__) // BJM
#include "l1_core_private.h"
#include "l1_rtb.h"
#ifdef __MTK_UL1_FDD__	
#include "ul1c_trc.h"
#include "ul1c_core_private.h"
#include "ul1_public.h"
#endif /* __MTK_UL1_FDD__ */
#endif /* defined(__GSM_RAT__) || defined(__UMTS_RAT__) */

//mtk04121
#if defined(__ETCM__)
#include "tcm_eval_struct.h"
#include "tcm_eval_enums.h"
#include "tcm_upcm_struct.h"

#include "eval_msgid.h"
#include "upcm_msgid.h"

#endif

#include "qmu_bm_enum.h"
#include "upcm_enum.h"
#include "tft_pf_enum.h"

#include "qbm_stats.h"
#include "upcm_em_struct.h"
#include "uas_data_common.h"

/* for RAC/GAS interface */
#include "rac_gas_enums.h"
#include "rac_gas_struct.h"

#if defined(__IMS_SUPPORT__)
/* VDM */
#include "vdm_imsp_struct.h"
#include "vdm_imc_struct.h"
#include "vdm_ctrl_trk_msg.h"
#include "vdm_ctrl_ads_msg.h"
#include "vdm_ctrl_vcc_msg.h"
#include "vdm_trk_ads_msg.h"
#include "vdm_trk_vcc_msg.h"
#include "vdm_ads_vcc_msg.h"
#include "vdm_ut.h"
#include "vdm_trk_ut.h"
#include "vdm_ads_ut.h"
#include "vdm_vcc_ut.h"

/* SDM */
#include "sdm_imsp_struct.h"
#include "sdm_imcsms_enums.h"
#include "sdm_imcsms_struct.h"
#include "sdm_trc.h"
#include "sdm_msgid.h"
#include "sdm_context.h"

/* IMSP */
#include "proxy_atci_struct.h"
#include "imsp_msgid.h"
#include "imsp_imcsms_struct.h"

/* IMC */
#include "dhl_ims_sap_collect.h"

/* IMCSMS */
#include "imcsms_msgid.h"
#include "imcsms_imc_struct.h"
#include "imcsms_enums.h"
#include "imcsms_defs.h"
#include "imcsms_rl.h"
#include "imcsms_context.h"
#include "imcsms_timer.h"

#endif /* defined(__IMS_SUPPORT__) */

/* CCCI IPC */
#if defined(__CCCIDEV_SUPPORT__)
#include "ccci_ipc_msgid.h"
#endif
#include "ps_public_struct.h"

#ifdef __IPCORE_SUPPORT__
#include "pfm_struct.h"
#include "pfm_enums.h"
#endif /* __IPCORE_SUPPORT__ */
