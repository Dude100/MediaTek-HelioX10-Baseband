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
 * srcParseDbModem.c
 *
 * Project:
 * --------
 * MOLY
 *
 * Description:
 * ------------
 * This file collects primitve IDs and struct definition from the Modem
 * part for pre-processing.
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
 * 06 16 2014 ken.liu
 * removed!
 * re-enable l1 boxster.
 *
 * 06 09 2014 ken.liu
 * removed!
 * re-enable l1 boxster.
 *
 * removed!
 * removed!
 * 	[CCCI] Show CCCI IPC ILM's local parameter in ELT
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
 * [LPP] LPP module and interface.
 *
 * removed!
 * removed!
 * Integration change.
 *
 * removed!
 * removed!
 * .
 *
 * 06 03 2013 ken.liu
 * removed!
 * add msg id to em_info_enum mapping table.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * add MOD_PSDM into required files
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

#include "kal_public_api.h"      
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "sap_info.h"
#include "msg_id_to_em_info_map.h"

#include "kal_trace.h"
#include "stack_ltlcom.h"
#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "stack_timer.h"
#include "event_shed.h"

#include "intrCtrl.h"

#include "GV.h"
#include "dhl_def.h"

#if defined(GEN_FOR_PC)
//#include "tst_Catcher_version.h"
#endif  //#if defined(GEN_FOR_PC)

#ifndef L4_NOT_PRESENT
#include "l4c2uem_struct.h"
#include "l4c2smu_struct.h"
#include "l4c2csm_cc_struct.h"
#include "l4c2smsal_struct.h"
#endif

#ifdef __MOD_NVRAM__
#include "nvram_data_items.h"
#include "ex_item.h"

#if defined(__MMI_FMI__)
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"
#endif

#include "nvram_editor_data_item.h"
#endif /*__MOD_NVRAM__*/


#ifdef __EM_MODE__
#include "em_struct.h"
#endif /* __EM_MODE__ */



#ifndef ABM_NOT_PRESENT
#include "abm_soc_enums.h"
#include "abm2soc_struct.h"
#include "app2cbm_struct.h"
#include "wndrv_cnst.h"
#include "wndrv_supc_types.h"
#include "wndrv_api.h"
#include "supc_abm_msgs.h"
#include "mmi2abm_struct.h"
#include "soc2abm_struct.h"

#if defined(__MMI_FMI__)
#endif

#include "l4c2abm_struct.h"
/* Jeff Wu 2008-02-20: for streaming and secondary PDP context */
#include "mmi_sm_enums.h" 
/* End of Jeff Wu */
#include "abm2l4c_struct.h"
#include "l4c2ppp_struct.h"
#include "ppp2l4c_struct.h"
#include "abm_def.h"
#endif /* ~ABM_NOT_PRESENT */



#ifndef MED_NOT_PRESENT
#include "aud_defs.h"
#include "med_struct.h"
#endif /* MED_NOT_PRESENT */

#ifndef MED_V_NOT_PRESENT
#include "med_global.h"
#endif /* MED_V_NOT_PRESENT */
#if defined(__VIDEO_ARCHI_V2__)
#endif
#ifndef TCPIP_NOT_PRESENT
#include "soc_api.h"
#include "soc2tcpip_struct.h"
#include "tcpip2ppp_struct.h"
#include "ppp2tcpip_struct.h"
#endif

#ifdef __HOTSPOT_SUPPORT__
#include "hostap_abm_msgs.h"
#endif

#ifndef SOC_NOT_PRESENT
#include "inet_ut_struct.h"
#include "..\..\..\inet_ps\soc\include\soc_feature.h"
#include "soc_api.h"
#include "app2soc_struct.h"
#include "soc2tcpip_struct.h"
#include "abm_soc_enums.h"
#include "abm2soc_struct.h"
#include "soc2abm_struct.h"
#include "soc_enum.h"
#endif

#ifdef __J2ME__
#include ".\..\..\applib\misc\include\app_datetime.h"
#endif

#ifdef __EMAIL__
#include "rtc_sw.h"
#ifdef __SSL_SUPPORT__
#endif /* __SSL_SUPPORT__ */
#include "che_api.h"


#endif /* __EMAIL__ */

#ifdef __IMPS__
#include "fs_type.h"
#include "fat_fs.h"
#endif /* __IMPS__ */

#ifdef WAP_SUPPORT
#include "custom_wap_config.h"
#endif
#ifdef MMS_SUPPORT
#endif
#include "resource_audio.h"

#if defined (__MTV_SUPPORT__) || defined(__ATV_SUPPORT__)
#endif
#if defined (__CMMB_SUPPORT__)
#include ".\..\..\plutommi\MtkApp\DTVPlayer\DTVPlayerInc\DTVPlayerEnum.h" 
#endif

#ifdef PLUTO_MMI
#ifndef __L1_STANDALONE__
#endif /* __L1_STANDALONE__ */
#endif

#ifdef NEPTUNE_MMI
#ifndef __L1_STANDALONE__
#endif /* __L1_STANDALONE__ */
#endif

#ifdef __XDM__
#include "fs_type.h"
#include "fat_fs.h"
#endif /* __XDM__ */

#ifdef __RTSP__
#include "app2rtsp_struct.h"
#endif /* __RTSP__ */

/* for BMT */
#include "drvsignals.h"
/* for BMT */

#ifdef __SIP__
#include "inet_msg_def.h"
#endif /* __SIP__ */

#ifdef __POC__
#include "mmi2poc_struct.h"
#include "poc_enum.h"
#endif /* __POC__ */

#ifdef __BTMTK__
#include "bluetooth_bm_struct.h"
#include "bluetooth_struct.h"
#include "bt_dm_struct.h"
#include "bt_hfg_struct.h"
#include "bt_hsg_struct.h"
#include "bt_hidd_struct.h"
#include "bt_a2dp_base_struct.h"
#endif

#if defined(PLUTO_MMI)
#endif

#ifdef __SYNCML_SUPPORT__
#endif

#include "mexe_struct.h"

#ifdef __VOIP__
#endif /* __VOIP__ */

#ifdef __TCPIP__
#include "..\..\..\inet_ps\tcpip\include\tcpip_config.h"
#include "..\..\..\inet_ps\tcpip\include\in.h"
#include "..\..\..\inet_ps\tcpip\include\ip.h"
#include "..\..\..\inet_ps\tcpip\include\tcp.h"
#include "..\..\..\inet_ps\tcpip\include\if.h"
#ifdef __WIFI_SUPPORT__
#include "wndrv_cnst.h"
#include "wndrv_tcpip_msg.h"
#endif /* __WIFI_SUPPORT__ */
#endif /* __TCPIP__ */


#ifdef __WIFI_SUPPORT__
#include "..\..\..\inet_ps\dhcp\include\dhcp_const.h"
#include "..\..\..\inet_ps\dhcp\include\dhcp_enum.h"
#include "..\..\..\inet_ps\dhcp\include\dhcp_context.h"
#include "dhcp_abm_enums.h"
#include "dhcp_sip_enums.h"
#include "dhcp2abm_struct.h"
#include "dhcp2sip_struct.h"
#include "tcpip2dhcp_struct.h"
#endif /* __WIFI_SUPPORT__ */
#ifdef __HOTSPOT_SUPPORT__
#include "dhcpd2abm_struct.h"
#endif /* __HOTSPOT_SUPPORT__ */

#ifdef __SAF__
#endif /* __SAF__ */

#ifdef NEPTUNE_MMI
#include ".\..\..\interface\modem\mmi_msg_struct.h"
#endif
#ifdef PLUTO_MMI
#include ".\..\..\interface\modem\mmi_msg_struct.h"
#include ".\..\..\applib\mem\include\app_mem.h"

#ifdef __MMI_VUI_3D_MAINMENU__
#endif
#ifdef __TCPIP__
#define CODEGEN_DTCNT_SRV
#endif 

#ifdef __SDP__
#include "sdp_msg_api.h"
#endif

#include "tcpip2abm_struct.h"

#ifdef SYNCML_DM_SUPPORT
#include "mmiapi_dm_struct.h"
#endif

/* MMI GSM/3G Call Service */
#include "..\..\..\modem\interface\l4misc\l3_inc_enums.h"

#endif /* PLUTO_MMI */

#ifdef __SSL_SUPPORT__
#endif /* __SSL_SUPPORT__ */

#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
#include "gps_struct.h"
#endif

#ifdef __CERTMAN_SUPPORT__
#endif

#if defined __SUPL_SUPPORT__
#include "supl2lcsp_enums.h"
#include "supl2lcsp_struct.h"
#endif

#ifndef FMT_NOT_PRESENT
#endif

#if defined(__UDX_SUPPORT__) || defined(__MULTI_VCARD_SUPPORT__)
#endif

#ifdef WAP_SUPPORT
#endif /* WAP_SUPPORT */

#ifdef __CCA_SUPPORT__
#endif /* __CCA_SUPPORT__ */

#ifdef __MTP_ENABLE__
#endif

#ifndef __MTK_TARGET__
#include "l4c2dt_struct.h"
#include "rmmi_context.h"
#endif

#if defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__)
#endif

#if defined (__MMI_IMAGE_VIEWER__) && !defined (NEPTUNE_MMI)
#endif /* __MMI_IMAGE_VIEWER__ */

#ifdef __CMMB_CAS_MBBMS_SUPPORT__
#endif

#if defined(__CMMB_SUPPORT__)
#endif
#if defined(__H264_HW_OPEN_API_SUPPORT__) || defined(__H264_DEC_HW_SUPPORT__) || defined (__H264_SW_OPEN_API_SUPPORT__)
#endif

#if defined(DRV_DISPLAY_DRIVER_V2)
#include ".\..\..\interface\hal\display\wfc\wfc.h"
#include ".\..\..\hal\display\debug\inc\lcd_catcher_log.h"
#include ".\..\..\interface\hal\display\common\display_io.h"
#include ".\..\..\hal\display\common\include\display_io_internal.h"
#endif

#include "fs_gprot.h"

#ifdef __PLST_SERVICE_DB_SUPPORT__
#include "..\..\..\plutommi\Service\PlstSrv\PlstSrvMsgStruct.h"
#endif

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
#include "nwsel_msgid.h"
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
#include "mll1_msgid.h"    
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
#include "gps_msgid.h"      
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

#include "mbci_struct.h"

#if defined (__ETCM__)
#include "eval_msgid.h"
#include "upcm_msgid.h"
#endif

#include "l4c_eval_struct.h"

/* CCCI IPC */
#if defined(__CCCIDEV_SUPPORT__)
#include "ccci_ipc_msgid.h"
#endif

#ifdef __IPCORE_SUPPORT__
#include "ipc_struct.h"
#include "ipc_enums.h"
#include "pfm_struct.h"
#include "pfm_enums.h"
#endif /* __IPCORE_SUPPORT__ */
