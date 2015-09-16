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
 *   SST_concurrent_utility.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the necessary API needed by concurrent ulitity.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _SST_CONCURRENT_UTILITY_
#define _SST_CONCURRENT_UTILITY_
#ifdef __cplusplus
extern "C" {
#endif

#include "kal_general_types.h"

/*************************************************************************
 * Platform Capabilities Definition   
 *************************************************************************/

/*************************************************************************
 * Constant Definition : Option from NVRAM setting
 *************************************************************************/
#define SWLA_ADDON_EBM_R_LAT 0x10
#define SWLA_ADDON_EBM_W_LAT 0x20

/*************************************************************************
 * Constant Definition : Sync with ELT Addon DLL
 *************************************************************************/
#define USAGE_TYPE_ELM       (1UL <<  0)
#define USAGE_TYPE_EBM       (1UL <<  1)
#define USAGE_TYPE_UR        (1UL <<  2)
#define USAGE_TYPE_EBM_RLAT  (1UL <<  3)
#define USAGE_TYPE_EBM_WLAT  (1UL <<  4)
#define USAGE_TYPE_BMON      (1UL <<  5)


/*************************************************************************
 * ENUM Definition : Sync with Catcher 
 *************************************************************************/
typedef enum
{
   HEADER_ID_MAIN_TQCNT           = 0x00000001,
   HEADER_ID_MAIN_USEC            = 0x00000002,
   HEADER_ID_NUCLEUS_V1           = 0x00000000,
   HEADER_ID_NUCLEUS_V2           = 0x00000010,
   HEADER_ID_TIME_STAMP_BASE      = 0x00000100,
   HEADER_ID_EXTRA_INFO           = 0x00000103,
   HEADER_ID_TWO_RATIOS           = 0x00000104,
   HEADER_ID_OVERHEAD             = 0x00000105,
   HEADER_ID_CUST_OVERHEAD        = 0x00000106,
   HEADER_ID_EXTERNAL_BN          = 0x00010005,
   HEADER_ID_EXTERNAL_EMI_GERNAL  = 0x00010006,
   HEADER_ID_EXTERNAL_EMI_PRO     = 0x00010007,
   HEADER_ID_EXTERNAL_TST         = 0x00010008,
   HEADER_ID_EXTERNAL_INST_COUNT  = 0x0001000A,
   HEADER_ID_EXTERNAL_CONCURRENCY = 0x0001000B,
   HEADER_ID_EXTERNAL_MAX         = 0x00010010,
   
   /* The following is for MALMO ASM SWLA*/
   HEADER_ID_MALMO_ASM_BASE = 0x10000000,
   HEADER_ID_MALMO_ASM_FRAMENO,
   HEADER_ID_MALMO_ASM_MCU_PC, 
   HEADER_ID_MALMO_ASM_CONTEXT_ID, 
   HEADER_ID_MALMO_ASM_PMC0,
   HEADER_ID_MALMO_ASM_PMC1, 
   HEADER_ID_MALMO_ASM_PMC2,
   HEADER_ID_MALMO_ASM_CYCLE_CNT, 
   HEADER_ID_MALMO_ASM_EMI_BCNT, 
   HEADER_ID_MALMO_ASM_EMI_BACT, 
   HEADER_ID_MALMO_ASM_EMI_BSCT, 
   HEADER_ID_MALMO_ASM_EMI_BSCT2, 
   HEADER_ID_MALMO_ASM_EMI_BSCT3, 
   HEADER_ID_MALMO_ASM_TIMESTAMP,
   /* There might be more MALMO ASM entries in the future */
 
   HEADER_ID_MALMO_ASM_EXTRA_BASE = 0x10001000,
   HEADER_ID_MALMO_ASM_EXTRA0,
   HEADER_ID_MALMO_ASM_EXTRA1, 
   HEADER_ID_MALMO_ASM_EXTRA2, 
   HEADER_ID_MALMO_ASM_EXTRA3

} SA_HEADER_ID_T;

/*************************************************************************
 * Structure Definition : Basic and Professional EMI Monitor Logging Node
 *************************************************************************/

#if defined(MT6280)

typedef struct BM_LOG_T
{
    kal_uint32 bus_ccnt;        /* total bus cycle count */
    kal_uint32 busy_all_cnt;    /* all master busy count */
    kal_uint32 busy_cnt;        /* monitor master busy count */
    kal_uint32 busy_cnt2;
    kal_uint32 busy_cnt3;
}BM_Log;

#elif defined(MT6572) || defined(MT6582)

/* Defined Option off Add-on*/
// At least ONE of the following option should be Turned-On !!
#define __SWLA_ADDON_ELM__
//#define __SWLA_ADDON_EBM__
//#define __PROFILE_UR__

typedef struct BM_LOG_T
{
    // MD ELM
    #if defined(__SWLA_ADDON_ELM__)
    kal_uint32 elm_r_lat;
    kal_uint32 elm_r_tcnt;
    kal_uint32 elm_w_lat;
    kal_uint32 elm_w_tcnt;
    #endif

    #if defined(__SWLA_ADDON_EBM__)
    kal_uint32 emi_md_mcu_tcnt;
    kal_uint32 emi_md_hw_tcnt;
    #endif /* __SWLA_ADDON_EBM__ */

    #if defined(__SWLA_ADDON_EBM__) || defined(__PROFILE_UR__)
    kal_uint32 emi_md_mcu_wcnt;
    kal_uint32 emi_md_hw_wcnt;
    #endif /* __SWLA_ADDON_EBM__ || __PROFILE_UR__ */

    #if defined(__PROFILE_UR__)
    kal_uint32 emi_md_mcu_bcnt;
    kal_uint32 emi_md_hw_bcnt;
    #endif /* __PROFILE_UR__ */

    #if !defined(__SWLA_ADDON_ELM__) && !defined(__SWLA_ADDON_EBM__) && !defined(__PROFILE_UR__)
    kal_uint32 dummy;
    #endif

}BM_Log;

#elif defined(MT6290)

/* Defined Option off Add-on*/
// At least ONE of the following option should be Turned-On !!
#define __SWLA_ADDON_ELM__
//#define __SWLA_ADDON_EBM__
//#define __PROFILE_UR__
#define __PROFILE_EBM_LAT__

#if defined(__SWLA_ADDON_EBM__) && defined(PROFILE_EBM_LAT__)
#error "Only one EBM function at one time !"
#endif

typedef struct BM_LOG_T
{
    // MD ELM
    #if defined(__SWLA_ADDON_ELM__)
    kal_uint32 elm_r_lat;
    kal_uint32 elm_r_tcnt;
    kal_uint32 elm_w_lat;
    kal_uint32 elm_w_tcnt;
    #endif

    #if defined(__SWLA_ADDON_EBM__)
    kal_uint32 emi_md_mcu_tcnt;
    kal_uint32 emi_md_hw_tcnt;
    #endif /* __SWLA_ADDON_EBM__ */

    #if defined(__SWLA_ADDON_EBM__) || defined(__PROFILE_UR__)
    kal_uint32 emi_md_mcu_wcnt;
    kal_uint32 emi_md_hw_wcnt;
    #endif /* __SWLA_ADDON_EBM__ || __PROFILE_UR__ */

    #if defined(__PROFILE_UR__)
    kal_uint32 emi_md_mcu_bcnt;
    kal_uint32 emi_md_hw_bcnt;
    #endif /* __PROFILE_UR__ */

    #if defined(__PROFILE_EBM_LAT__)
    kal_uint32 ebm_md_mcu_lat;
    kal_uint32 ebm_md_mcu_tcnt;
    #endif /* __PROFILE_EBM_LAT__ */

    #if !defined(__SWLA_ADDON_ELM__) && !defined(__SWLA_ADDON_EBM__) && !defined(__PROFILE_UR__) && !defined(__PROFILE_EBM_LAT__)
    kal_uint32 dummy;
    #endif

}BM_Log;

#else /* defined(MT6595) and the following CHIP in MOLY */

/* Defined Option off Add-on
 * At least ONE of the following option should be Turned-On !!
 *  __SWLA_ADDON_ELM__
 *  __SWLA_ADDON_EBM__
 *  __PROFILE_UR__
 *  __PROFILE_EBM_LAT__
 *  __SWLA_ADDON_BMON__
 */

#if defined(__SWLA_ADDON_EBM__) && defined(PROFILE_EBM_LAT__)
#error "Only one EBM function at one time !"
#endif


//#define __SWLA_ADDON_SMIM__


typedef struct BM_LOG_T
{
    // MD ELM
    #if defined(__SWLA_ADDON_ELM__)
    kal_uint32 elm_r_lat;
    kal_uint32 elm_r_tcnt;
    kal_uint32 elm_w_lat;
    kal_uint32 elm_w_tcnt;
    #endif

    #if defined(__SWLA_ADDON_EBM__)
    kal_uint32 emi_md_mcu_tcnt;
    kal_uint32 emi_md_hw_tcnt;
    kal_uint32 emi_md_mcu_wcnt;
    kal_uint32 emi_md_hw_wcnt;
    //kal_uint32 emi_bcnt;
    //kal_uint32 emi_bact;
    //kal_uint32 emi_bsct;
    #endif /* __SWLA_ADDON_EBM__ */

    #if defined(__SWLA_ADDON_PMU__)
    #if defined(__PROFILE_PMU_START_END_CYC__)
    kal_uint32 cr4_pmu_cycle_start;
    kal_uint32 cr4_pmu_cycle_end;
    #else
    kal_uint32 cr4_pmu_dur;
    #endif /* __PROFILE_PMU_START_END_CYC__ */
    kal_uint32 cr4_pmu_event[3];
    #endif /* __SWLA_ADDON_PMU__ */

    #if defined(__SWLA_ADDON_EBM_LAT__)
    kal_uint32 ttype[7];
    #endif /* __SWLA_ADDON_EBM_LAT__ */

    #if defined(__SWLA_ADDON_BMON__)
    kal_uint32 busmon_mcu_tot_cyc;
    /* index 0 for IP0, index 1 for IP1 */
//  kal_uint32 busmon_mcu_tot_nw_cycle[2]; // non weighted transaction cycles
    kal_uint32 busmon_mcu_max_lat[2];      // maximal latency
    kal_uint32 busmon_infra_max_lat[2];    // maximal latency
    #endif /* __SWLA_ADDON_BMON__ */

	#if defined(__SWLA_ADDON_SMIM__)
    kal_uint32 smi_actCnt;
    kal_uint32 smi_tCnt;
    kal_uint32 smi_byteCnt;
	#endif

    #if !defined(__SWLA_ADDON_ELM__) && !defined(__SWLA_ADDON_EBM__) && !defined(__SWLA_ADDON_EBM_LAT__) && !defined(__SWLA_ADDON_PMU__)
    kal_uint32 dummy;
    #endif

} BM_Log;

#endif /* __MAUI_SWLA_PROFESSIONAL_EMI_MONITOR__ */

/*************************************************************************
 * Structure Definition : Auxiliary Structures
 *************************************************************************/

#if defined(MT6280)

typedef struct EMI_Setting_T
{
    kal_uint32 usage_type;
   
    kal_uint32 EMI_CONI_Val;
    kal_uint32 EMI_CONJ_Val;
    kal_uint32 EMI_CONK_Val;
    kal_uint32 EMI_CONL_Val;
    kal_uint32 EMI_CONM_Val;
    kal_uint32 EMI_CONN_Val;    
    kal_uint32 EMI_GEND_Val;
    kal_uint32 EMI_BMEN_Val;
    kal_uint32 EMI_MSEL_Val; 
    
    kal_uint32 EMI_FREQ;
}EMI_Setting;

#elif defined(MT6572) || defined(MT6582)

typedef struct EMI_Setting_T
{
    kal_uint32 usage_type;
}EMI_Setting;

#elif defined(MT6290)

typedef struct EMI_Setting_T
{
    kal_uint32 usage_type;
}EMI_Setting;

#else /* defined(MT6595) and the following CHIP in MOLY  */

typedef struct EMI_Setting_T
{
    kal_uint32 usage_type;
    kal_uint32 word_cnt;
}EMI_Setting;

#endif

/*************************************************************************
 * Structure Definition : Basic and Professional EMI Monitor Init Reference
 *************************************************************************/

#if defined(MT6280) || defined(MT6572) || defined(MT6582) || defined(MT6290) || defined(MT6595) || defined(MT6752)

typedef struct BM_REF_T
{
    SA_HEADER_ID_T   id;
    kal_uint32       szRef;
    EMI_Setting      emi_settings;
}BM_Ref;

#endif /* MT6280 || MT6572 || MT6582 */


/*************************************************************************
 * Exported APIs for Software LA
 *************************************************************************/
#if defined(__HW_EMI_MONITOR_SUPPORT__)

extern void Setup_AddOn_RefData(SA_HEADER_ID_T id,  kal_uint8 **ARef, kal_uint32 *szARef);
extern void Get_BM_Log( BM_Log* pLog );
extern void Enable_Normal_EMI_Monitor(void);

extern void SWLA_EBM_Setup_DLLInfo(kal_uint8 **ARef, kal_uint32 *szARef);
extern kal_uint8* SWLA_EBM_Clear_Counter(void);

#endif /* __HW_EMI_MONITOR_SUPPORT__ */


#ifdef __cplusplus       
}
#endif

#endif /* _SST_CONCURRENT_UTILITY_ */
