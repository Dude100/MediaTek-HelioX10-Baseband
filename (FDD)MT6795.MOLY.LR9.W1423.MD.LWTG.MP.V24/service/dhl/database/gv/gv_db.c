/********************************************************************************************
 *     LEGAL DISCLAIMER 
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES 
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED 
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS 
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED, 
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR 
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY 
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, 
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK 
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION 
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *     
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH 
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, 
 *     
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE 
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
 *     
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS 
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.  
 ************************************************************************************************/


/*******************************************************************************
 *
 * Filename:
 * ---------
 * gv_db.c
 *
 * Project:
 * --------
 * MOLY
 *
 * Description:
 * ------------
 * This file used for pre-processing to build GV DB
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
 *  How to add a new gv script
 * 1. Put the gv script into the proper folder e.g: \dhl\database\gv
 *                                                  \dhl\database_classb\gv
 *                                                  \dhl\database_classb_umts\gv
 *                                                  \dhl\database_modis\gv
 * 2. #include <xxx.gv>. 
 *    Notably, you should use #include <xxx.gv> rather than "xxx.gv"
 *    If you have two different scripts with the same name in database\gv
 *    and database_modis\gv, please make sure you use #include <xxx.gv>.
 *    If you use #include "xxx.gv", Codegen will process \dhl\database\gv\xxx.gv
 *    instead of \dhl\database_modis\gv\xxx.gv. So you are suggested to use
 *    #include <xxx.gv> all the way.
 *******************************************************************************/

#ifdef _MODIS_ON_VC9_
#define __w64
#endif

#ifdef STDC_HEADERS
#undef STDC_HEADERS //it will include stdio.h
#endif

#include <tst_vars.gv>

#ifdef TST_STATISTICS
#include <tst_lost_count_vars.gv>
#endif  //#ifdef TST_STATISTICS


//For GSM/GPRS Project, please include your header here, e.g: #include <modis.gv>
//Please put your gv files to \dhl\database\gv\ or \dhl\database_classb\gv\

#ifdef __MOD_TCM__
    #if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
        #ifdef UNIT_TEST
        
           #ifdef __TCM_UT__
             #if (GPRS_MAX_PDP_SUPPORT >= 7) // Only support TCM GV when GPRS_MAX_PDP_SUPPORT == 7
               #ifdef __GEMINI__
               #else /* __GEMINI__ */
                 #include <tcm_fsm_vars.gv>
               #endif /* __GEMINI__ */
             #endif // ~ #if (GPRS_MAX_PDP_SUPPORT >= 7) // Only support TCM GV when GPRS_MAX_PDP_SUPPORT == 7
             #if (GPRS_MAX_PDP_SUPPORT == 4) //when PDP less than 4, for easy UT regression
                 #include <tcm_fsm_vars2.gv>
             #endif
           #endif // ~ #ifdef __TCM_UT__
           
           #ifdef __TCM_RAT_TCM_UT__
             #if (GPRS_MAX_PDP_SUPPORT >= 3) // Only support RAT_TCM GV when GPRS_MAX_PDP_SUPPORT >= 3
               #ifdef __GEMINI__
                 #ifdef __TCM_CID_0_SUPPORT__
                 #include <rat_tcm_vars_sim1_cid_0_turn_on.gv>
                 #include <rat_tcm_vars_sim2_cid_0_turn_on.gv>
                 #else // __TCM_CID_0_SUPPORT__
                 #include <rat_tcm_vars_sim1.gv>
                 #include <rat_tcm_vars_sim2.gv>
                 #endif // ~ __TCM_CID_0_SUPPORT__
               #else /* __GEMINI__ */
                 #ifdef __TCM_CID_0_SUPPORT__
                 #include <rat_tcm_vars_sim1_cid_0_turn_on.gv>
                 #else // __TCM_CID_0_SUPPORT__
                 #include <rat_tcm_vars_sim1.gv>
                 #endif // ~ __TCM_CID_0_SUPPORT__
               #endif /* __GEMINI__ */
             #endif // ~ #if (GPRS_MAX_PDP_SUPPORT >= 7) // Only support TCM GV when GPRS_MAX_PDP_SUPPORT == 7
           #endif // ~ #ifdef __TCM_RAT_TCM_UT__
           
        #endif // ~ #ifdef UNIT_TEST
    #endif // ~ #if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
#endif // ~ #ifdef __MOD_TCM__

//#ifdef __SM_UT__

    #if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
        #ifdef UNIT_TEST

            #if (GPRS_MAX_PDP_SUPPORT > 1) // MoDIS GV require at least 2 PDP Context support

                #ifdef __PS_SERVICE__ // GV is needed only when task SM is present
                
                    #include <sndcp_vars.gv>
                    

                    #ifdef __SGLTE__
                    #include <sm_mmds_dc_vars.gv>
                    #endif /* __SGLTE__ */
					
                    #if defined(__GEMINI__) || defined(__SGLTE__)
                    #include <sm_r98_gemini_sim1_vars.gv>
                        #if defined(__SGLTE__)
                        #include <sm_r98_gemini_sim2_vars.gv>
                        #endif
                    #else /* __GEMINI__ */
                    #include <sm_r98_vars.gv>
                    #endif /* __GEMINI__ */
                    
                    #ifdef __R99__
                        #if defined(__GEMINI__) || defined(__SGLTE__)
                        #include <sm_r99_gemini_sim1_vars.gv>
                        #include <sm_r99_gemini_sim2_vars.gv>
                        #else /* __GEMINI__ */
                        #include <sm_r99_vars.gv>
                        #endif /* __GEMINI__ */
                    #endif /* __R99__ */
                
                    #if defined(__GEMINI__) || defined(__SGLTE__)
                    #include <sm_mtk_3g_mrat_arch_gemini_sim1_vars.gv>
                        #if defined(__SGLTE__)
                        #include <sm_mtk_3g_mrat_arch_gemini_sim2_vars.gv>
                        #endif
                    #else /* __GEMINI__ */
                    #include <sm_mtk_3g_mrat_arch_vars.gv>
                    #endif /* __GEMINI__ */
                    
                    #if (defined(__UMTS_RAT__))
                        #if defined(__GEMINI__) || defined(__SGLTE__)
                        #include <sm_mtk_3g_mrat_arch_wcdma_rat_gemini_sim1_vars.gv>
                            #if defined(__SGLTE__)
                            #include <sm_mtk_3g_mrat_arch_wcdma_rat_gemini_sim2_vars.gv>
                            #endif
                        #else /* __GEMINI__ */
                        #include <sm_mtk_3g_mrat_arch_wcdma_rat_vars.gv>
                        #endif /* __GEMINI__ */
                    #endif /* (defined(__UMTS_RAT__)) */

                    #if 1 // (defined(__PS_SIG_DATA_IMMEDIATE_RETRY_GSM__) || defined(__PS_SIG_DATA_IMMEDIATE_RETRY_UMTS__) || defined(__SM_UT__))
                        #ifdef __GEMINI__
                        #include <sm_immediate_retry_sim1_vars.gv>
                        //#include <sm_immediate_retry_sim2_vars.gv>
                        #else /* __GEMINI__ */
                        #include <sm_immediate_retry_sim1_vars.gv>
                        #endif /* __GEMINI__ */
                    #endif /* #if (defined(__PS_SIG_DATA_IMMEDIATE_RETRY_GSM__) || defined(__PS_SIG_DATA_IMMEDIATE_RETRY_UMTS__)) */

            

                    #ifdef __REL6__
                        #if defined(__GEMINI__) || defined(__SGLTE__)
                        #include <sm_r6_gemini_sim1_vars.gv>
                            #if defined(__SGLTE__)
                            #include <sm_r6_gemini_sim2_vars.gv>
                            #endif
                        #else /* __GEMINI__ */
                        #include <sm_r6_vars.gv>
                        #endif /* __GEMINI__ */
                    #endif // ~ __REL6__

                    #ifdef __REL7__
                        #if defined(__GEMINI__) || defined(__SGLTE__)
                        #include <sm_r7_gemini_vars.gv>  // For both sim1 and sim2
                        #else  // __GEMINI__ 
                        #include <sm_r7_vars.gv>
                        #endif // ~ __GEMINI__
                    #endif // ~ __REL7__

                    #ifdef __LTE_RAT__
                        #if defined(__GEMINI__) || defined(__SGLTE__)
                        #include <sm_lte_multimode_gemini_sim1_vars.gv>
                            #if defined(__SGLTE__)
                            #include <sm_lte_multimode_gemini_sim2_vars.gv>
                            #endif
                        #else  // __GEMINI__ 
                        #include <sm_lte_multimode_vars.gv>
                        #endif // ~ __GEMINI__
                    #endif // ~ __LTE_RAT__

                #endif //#ifdef __PS_SERVICE__

            #endif //#if (GPRS_MAX_PDP_SUPPORT > 1) // MoDIS GV require at least 2 PDP Context support

        #endif // ~ #ifdef UNIT_TEST
    #endif // ~ #if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
//#endif // ~ __SM_UT__


#ifdef UNIT_TEST
//For MODIS Project, please include your header here, e.g: #include <modis.gv>
/*Please put your gv files to \dhl\database_modis\gv\ */
#if defined(__UMTS_TDD128_MODE__)
#if defined(__GEMINI__) && defined (__UMTS_RAT__)
#include <meme_r99_gemini_vars.gv>
#endif
#endif

#if defined (__UMTS_RAT__) && defined(__UMTS_FDD_MODE__)
#include <meme_r99_gemini_vars.gv>
#endif

#include <timer_vars.gv>

/* NWSEL UT GV */
#ifdef UNIT_TEST
#ifndef NWSEL_NOT_PRESENT
#include <nwsel_vars.gv>
#endif
#endif /* UNIT_TEST */

// Eric Hsieh 20090610: For LLC UT
#ifdef __LLC_UT__
#ifdef __PS__HO__
#include <llc_psho_vars.gv>
#else
#include <llc_vars.gv>
#endif
#endif // __LLC_UT__

/* FLC GV */
#ifdef __FLC2__ 
#include <flc_vars.gv>
#endif //#ifdef __FLC2__
/* ~ FLC GV */

/* Carlson PPP UT GV, strictly restrict the UT GV to limited projects */
#ifdef __PPP_UT__ // only work for __PPP_UT__ defined
    #if (GPRS_MAX_PDP_SUPPORT > 1) // MoDIS GV require at least 2 PDP Context support
        #ifdef __PS_SERVICE__ // do not include PPP GV in GSM only load
            #ifndef PPP_NOT_PRESENT                
                #include <ppp_vars_gprs.gv>
                
                #ifdef __PPP_TYPE_PDP_DIALUP_SUPPORT__
                    #include <ppp_vars_ppp_type_pdp_ctx.gv>
                #endif                
            #endif        
        #endif
        
        #if defined (__TCPIP_OVER_CSD__) || defined (__EXT_MODEM__)
            #include <ppp_vars_csd.gv>
        #endif                        
    #endif //#if (GPRS_MAX_PDP_SUPPORT > 1) // MoDIS GV require at least 2 PDP Context support
#endif // ~ #ifdef __PPP_UT__
/* ~ Carlson PPP UT GV, strictly restrict the UT GV to limited projects */

#if defined(__GSM_RAT__) || defined(__UMTS_RAT__) // BJM
/* SC Monza MM UT GV */
    //mm_cs_context
    #ifdef __CS_SERVICE__
        #include <monza_mm_cs_basic.gv>
        
        #ifdef __AGPS_CONTROL_PLANE__
        #include <monza_mm_cs_agps.gv>
        #endif
        
        #ifdef __REL5__
        #include <monza_mm_cs_rel5.gv>
        #endif
        
        #ifdef __UMTS_RAT__
        #include <monza_mm_cs_wcdma.gv>
        #endif
        
        #ifdef __GEMINI__
        #include <monza_mm_cs_gemini_basic.gv>
        
            #ifdef __AGPS_CONTROL_PLANE__
            #include <monza_mm_cs_gemini_agps.gv>
            #endif
            
            #ifdef __REL5__
            #include <monza_mm_cs_gemini_rel5.gv>
            #endif
            
            #ifdef __UMTS_RAT__
            #include <monza_mm_cs_gemini_wcdma.gv>
            #endif
        #endif
    #endif
    
    //mm_ps_context
    #ifdef __PS_SERVICE__
        #include <monza_mm_ps_basic.gv>
    
        #if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
        #include <monza_mm_ps_gsm_wcdma.gv>
        #endif
    
        #ifdef __REL4__
        #include <monza_mm_ps_rel4.gv>
        #endif
    
        #ifdef __REL5__
        #include <monza_mm_ps_rel5.gv>
        #endif
    
        #ifdef __UMTS_RAT__
        #include <monza_mm_ps_wcdma.gv>
        #endif
    
        #ifdef __GEMINI__
        #include <monza_mm_ps_gemini_basic.gv>
        
            #if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
            #include <monza_mm_ps_gemini_gsm_wcdma.gv>
            #endif
        
            #ifdef __REL4__
            #include <monza_mm_ps_gemini_rel4.gv>
            #endif
        
            #ifdef __REL5__
            #include <monza_mm_ps_gemini_rel5.gv>
            #endif
            
            #ifdef __UMTS_RAT__
            #include <monza_mm_ps_gemini_wcdma.gv>
            #endif
        #endif
    #endif
    
    
    //mm_common_context
    #include <monza_mm_common_basic.gv>
    
    #ifdef __MODEM_EM_MODE__
    #include <monza_mm_common_em_mode.gv>
    #endif
    
    #ifdef __ENS__
    #include <monza_mm_common_ens.gv>
    #endif
    
    #if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
    #include <monza_mm_common_gsm_wcdma.gv>
    #endif
    
    #ifdef __HOMEZONE_SUPPORT__
    #include <monza_mm_common_homezone.gv>
    #endif
    
    #ifdef __PS_SERVICE__
    #include <monza_mm_common_ps_service.gv>
    #endif
    
    #ifdef __REL5__
    #include <monza_mm_common_rel5.gv>
    #endif
    
    #ifdef ___MM_RSSI_SNIFFER_MECHANISM__
    #include <monza_mm_common_rssi_sniffer.gv>
    #endif
    
    #ifdef __SAT__
    #include <monza_mm_common_sat.gv>
    #endif
    
        #ifdef __GEMINI__
        #include <monza_mm_common_gemini_basic.gv>
            #ifdef __MODEM_EM_MODE__
            #include <monza_mm_common_gemini_em_mode.gv>
            #endif
            
            #ifdef __ENS__
            #include <monza_mm_common_gemini_ens.gv>
            #endif
            
            #if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
            #include <monza_mm_common_gemini_gsm_wcdma.gv>
            #endif
            
            #ifdef __HOMEZONE_SUPPORT__
            #include <monza_mm_common_gemini_homezone.gv>
            #endif
            
            #ifdef __PS_SERVICE__
            #include <monza_mm_common_gemini_ps_service.gv>
            #endif
            
            #ifdef __REL5__
            #include <monza_mm_common_gemini_rel5.gv>
            #endif
            
            #ifdef __MM_RSSI_SNIFFER_MECHANISM__
            #include <monza_mm_common_gemini_rssi_sniffer.gv>
            #endif
            
            #ifdef __SAT__
            #include <monza_mm_common_gemini_sat.gv>
            #endif
        #endif
    
/* ~ SC Monza MM UT GV */
#endif /* defined(__GSM_RAT__) || defined(__UMTS_RAT__) */

/* Max Yin RATDM, RABM, PDCP UT GV */
	/* RATDM */
	#ifndef RATDM_NOT_PRESENT
	  #ifdef __UMTS_RAT__
			#if defined(__GEMINI__) || defined(__SGLTE__)
				#include <ratdm_3g_gemini_vars.gv>
				#ifdef __RATDM_UT__
				  #include <ratdm_3g_gemini_ut_only_vars.gv>
				#endif /* __RATDM_UT__ */
			#else
				#include <ratdm_3g_vars.gv>
				#ifdef __RATDM_UT__
				  #include <ratdm_3g_ut_only_vars.gv>
				#endif /* __RATDM_UT__ */
			#endif /* __GEMINI__ */
			#ifdef __REL6__
				#include <ratdm_vars_R6.gv>
				#ifdef __REL7__
					#include <ratdm_vars_R7.gv>
				#endif /* __REL7__ */
			#endif
	  #else
			#ifdef __GEMINI__
				#include <ratdm_gemini_vars.gv>
			#else
				#include <ratdm_vars.gv>
			#endif /* __GEMINI__ */
		#endif
	#endif /* RATDM_NOT_PRESENT */

	/* RABM and PDCP */
	#ifdef __UMTS_RAT__
		#include <rabm_vars.gv>
		#include <pdcp_vars.gv>
	#endif /* __UMTS_RAT__ */


#if defined(__GSM_RAT__) || defined(__UMTS_RAT__) // BJM
#include <MONZA_GAS.gv>

// Evelyn 20080902: For MAC UT
// Rachel 20101114: For MPAL UT as well
#include <MONZA2G_GAS.gv>
#endif /* defined(__GSM_RAT__) || defined(__UMTS_RAT__) */

#ifdef __EGPRS_MODE__
#include <MONZA_EDGE_GAS.gv>
#endif //#ifdef __EGPRS_MODE__

#if defined(__GSM_RAT__) || defined(__UMTS_RAT__) // BJM
#ifdef __GERAN_R6__
#include <MONZA_PS_R6_GAS.gv>
#endif //#ifdef __GERAN_R6__

#ifdef __PS_SERVICE__
#include <MONZA_PS_GAS.gv>
#endif //#ifdef __PS_SERVICE__
#endif /* defined(__GSM_RAT__) || defined(__UMTS_RAT__) */

// Rachel,20101102: for Gemini UT
#ifdef __GEMINI__
#include <MONZA_GEMINI_GAS.gv>
#endif //#ifdef __GEMINI__

// Peter,20090115: for Gemini UT
#if defined(__PS_SERVICE__) && defined(__GEMINI__)
#include <MONZA_GEMINI_GAS_PS.gv>
#endif //#if defined(__PS_SERVICE__) && defined(__GEMINI__)

#if defined(__GSM_RAT__) || defined(__UMTS_RAT__) // BJM
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
#include <MONZA_GAS_MONITOR_PCH_DURING_PTM.gv>
#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */
#endif /* defined(__GSM_RAT__) || defined(__UMTS_RAT__) */

#if defined(__GEMINI_PREEMPT_PEER_SERVICE__) && defined(__UMTS_RAT__)
#include <MONZA_GEMINI_GAS_PREEMPT.gv>
#endif
#ifdef __UMTS_RAT__
#include <MAUI_PS_UAS.gv>

/*[MAUI_01712431] CSR UT Regression*/
#include <csr_vars.gv>

// Peng-An, 20090425: for 3G Gemini UT
#include <urlc_vars.gv>

#ifdef __MTK_UL1_FDD__
/* Nancy 20110712: for UMAC UT */
#include <umac_vars.gv>
    /* JY: for Mac-ehs UT with C-Model */
    #ifdef __UMTS_R7__
    #include <umac_vars_R7.gv>
    #endif
#endif /* __MTK_UL1_FDD__ */

#ifdef __RLC_HSDPA_COPRO__
// Peng-An, 20100525: for SEQ UT
#include <seq_vars.gv>
#endif /* __RLC_HSDPA_COPRO__ */

#endif //#ifdef __UMTS_RAT__


/*[MAUI_01709274] CSD UT Regression*/
#ifdef CSD_UART_SIMU
    #ifdef __CSD_NT__
      #ifdef __CSD_T__
          #include <data_vars_T_NT.gv>
      #else
          #include <data_vars_NT_only.gv>
      #endif /*(__CSD_T__)*/
    #endif /*(__CSD_NT__)*/
#endif /*CSD_UART_SIMU*/

//#if defined(__RMMI_UT__) || defined(__L4C_GPRS_UT__)
#include <l4c.gv>
//#endif

#if defined(__L4C_GPRS_UT__)
#include <l4c_gprs.gv>
#endif

#endif //#ifdef UNIT_TEST


#ifdef __UMTS_RAT__
//For 3G Project, please include your header here, e.g: #include <wcdma.gv>
//Please put your gv files to \dhl\database_classb_umts\gv\

#endif  //__UMTS_RAT__

#ifdef UL1D_TEST
#include <ul1v.gv>
#endif	//#ifdef UL1D_TEST

#ifdef UNIT_TEST
#include <rac.gv>
#endif /* UNIT_TEST */

#if defined (__URLC_DVT_ON_FULL_LOAD__)
#include <ul2v.gv>
#endif /* __URLC_DVT_ON_FULL_LOAD__ */

#ifdef UNIT_TEST
    #ifdef __IMS_SUPPORT__
        #include <vdm_vars.gv>
    #endif
#endif

