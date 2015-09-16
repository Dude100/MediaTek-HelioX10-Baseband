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
 *   bl_Init.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   This file defines the initialization functions of bootloader
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
//Special workaround for RHR: include init.h first to get correct PDN address
#include "init.h"
#include "bl_INIT.H"
#include "bl_common.h"
#include "bl_features.h"
#include "bl_custom.h"
#include "bl_loader.h"
#include "bl_sectiondef.h"

#include "br_time_stamp.h"
#ifdef __TIME_STAMP__ 
#include "br_time_stamp_cb.h"
#include "bl_time_stamp_id.h"
#include "bl_frc.h"
#endif
#ifdef __MINI_BOOTLOADER__
#include "mt_emi.h"
#include "drv_bsi.h"
#include "bus_init.h" 
#endif

#include "SST_secure.h"

#include "bl_GFH_body.h"
#include "br_GFH_file_info.h"
#include "br_GFH_arm_bl_info.h"
#include "br_GFH_maui_info.h"
#include "br_GFH.h"
#include "maui_GFH_body.h"

#include "bl_share_param.h"
#include "bl_wdt.h"
#include "bl_cfgctl.h"
#include "bl_topsm.h"
#include "bl_UART_SW.H"
#include "bl_drv_common.h"
#include "pll.h"

#include "brom_sdio_drv.h"
#include "bl_topsm.h"
#include "bl_efuse.h"
#include "bl_pfb.h"
#include "bl_trc_api.h"

/*************************************************************************
 * Structure definition
 *************************************************************************/
typedef struct 
{
    kal_uint32 size;
    kal_uint32 payload[8];
} BL_SWB_STRUCT;

/*************************************************************************
 * External reference definition
 *************************************************************************/
extern void CacheInit(void);
extern void IOMUX_init(void);
extern void GPIO_init(void);
extern void EINT_Setting_Init(void);
extern void dcl_pmic_internal_init(void);
extern void PMIC_VCORE_INIT(kal_uint32 value, kal_uint32 var);
extern kal_bool SST_SWB_Init(kal_uint32 *pBootloader);
extern kal_uint32 SST_Get_MAUI_Paired_Version(kal_uint32 rom_base);
extern kal_uint32 SST_Get_MAUI_Feature_Combination(kal_uint32 rom_base, kal_uint32 *pFeatureCombination);

extern const LOG_LEVEL bootloader_debug_level;
extern kal_uint32 g_randomSeed;

extern GFH_MAUI_INFO_v1 *bl_GetMAUIInfo(void);

/*************************************************************************
 * Forward declearaion
 *************************************************************************/

/*************************************************************************
 * Global variables definition
 *************************************************************************/

__bl_resv_region__ BL_SWB_STRUCT g_bl_swb_struct = {sizeof(BL_SWB_STRUCT)-4};

ECO_VERSION eco_version = (ECO_VERSION)(0xff); /* only used in PLL setup, force it to be in RW */

/*************************************************************************
 * Main code
 *************************************************************************/

#ifdef __MINI_BOOTLOADER__

/**********************************************************
Description : initialization of internal RAM/mpu/HW
Input       : None
Output      : None
***********************************************************/
void PreInit(void)
{
#if defined(__CR4__)
   CachePreInitMini();
#endif /* __CR4__ */

}

/**********************************************************
Description : Initialize shared parameter with command script and 
                   bootrom
Input       : None
Output      : None
***********************************************************/
void bl_init_param()
{
    g_cs_bl_param = (cs_bl_param_v1 *)BASE_ADDR_MDTCM;

#if defined(__X_BOOTING__)
    //Set the channel type to CCCI if it is XBOOT
    g_cs_bl_param->sync_chl_type = CHL_CCCI;
#endif
}

void TimeStampInit(void)
{
#ifdef __TIME_STAMP__

   //Start FRC timer
   bl_frc_start();

   TS_Init(KAL_TRUE);

   INT_Trace_Enter(BL_TOTAL);
   INT_Trace_Enter(BL_BOOTLOADER);

#endif
}

void Init()
{
    dramc_cal_err_code emi_result = DRAMC_CAL_PASS;
    //Todo:
    // move vector table to 0x0
    // mode exception handling code to dram?
    // AP reset MD flow
    // check wdt reset status

    INT_Trace_Enter(BL_INIT);

    //Init wdt
    bl_wdt_init();

    //Init shared paramter
    bl_init_param();

#if defined(__X_BOOTING__)
    INT_Trace_Enter(BL_SDIO_SYNC_BEFORE_PLL);
    //Sync with AP side to stop sdio access while PLL is setting.
    brom_sdio_sync_before_PLL_init();
    INT_Trace_Exit(BL_SDIO_SYNC_BEFORE_PLL);
#endif    


    INT_Trace_Enter(BL_SET_PLL);
    //Init CLKPLL
    INT_SetPLL(PLL_MODE_MAUI);
    INT_Trace_Exit(BL_SET_PLL);

#if defined(__X_BOOTING__)
    INT_Trace_Enter(BL_SDIO_SYNC_AFTER_PLL);
    //Sync with AP side to continue sdio access
    //Note : AHB bus needs to be stable after PLL init
    brom_sdio_sync_after_PLL_init();
    INT_Trace_Exit(BL_SDIO_SYNC_AFTER_PLL);
#endif 

    //Init UART
    uart_init();

    //Todo:remove this
    BL_PRINT(LOG_INFO, "WDT status %x\n\r", DRV_Reg32(0xBF820134));

    set_debug_level(bootloader_debug_level);
    BL_PRINT(LOG_INFO, "Init Start\n\r");

    //Init topsm
    bl_topsm_init();

    //Init bus setting
    boot_init_bus();

    //IOMUX/GPIO/EINT init
#if !defined(__IC_SLT_LOADER__)    
    INT_Trace_Enter(BL_SET_IO);
    IOMUX_init();
    GPIO_init();
    EINT_Setting_Init();
    INT_Trace_Exit(BL_SET_IO);
#endif    

    INT_Trace_Enter(BL_SET_PMIC);
    //Init BSI PMIC (should be called before bring up AP)
    drv_bsi_pmic_init();
#ifndef __FPGA__
    dcl_pmic_internal_init();
#endif
#ifdef MT6290_S01
    //Pass efuse leakage setting to PMIC driver to fix thermal issue
    PMIC_VCORE_INIT(bl_efuse_get_leakage(), bl_efuse_get_ext_pwr_flow());
#endif
    INT_Trace_Exit(BL_SET_PMIC);

    //Init PFB
    //Init PFB in BL to prevent the bus hang issue
    INT_Trace_Enter(BL_SET_PFB);
    bl_pfb_enable();
    INT_Trace_Exit(BL_SET_PFB);

    //Init ownership
    //This cannot be called before PMIC function since it use I2C
    //In router project, I2C is owned by AP, set ownership before PMIC use I2C causes BL hangs 
    INT_Trace_Enter(BL_SET_HW_OWN);
    bl_cfgctl_ownership_init();
    INT_Trace_Exit(BL_SET_HW_OWN);

    //Init DRAM
#ifdef __IC_SLT_LOADER__    

    bl_slt_Init();

#else

    BL_PRINT(LOG_DEBUG, "DRAM Init\n\r");
    INT_Trace_Enter(BL_SET_EMI);
    emi_result = mt_set_emi();
    if (DRAMC_CAL_FAIL <= emi_result) {
        BL_PRINT(LOG_ERROR, "EMI: DRAMC Initialization is failed with emi_result equal to %d\n\r", emi_result);
        ASSERT(0);
    }
    INT_Trace_Exit(BL_SET_EMI);

#endif

    bl_print(LOG_NONE, "", g_bl_swb_struct.size);

    //Init Crypto lib
    BL_PRINT(LOG_DEBUG, "Crypto lib Init\n\r");
    SSS_Init_Crypto_Drv(TS_RECORD_FUNC, TS_INFO_FUNC);

    //Check if token passing is required
    {
        extern kal_uint32 Image$$BL_GFH_SECTION$$Base;
        SST_SWB_Init((kal_uint32*)&Image$$BL_GFH_SECTION$$Base);
    }

    BL_PRINT(LOG_INFO, "Init done, %x\n\r", g_randomSeed);
    INT_Trace_Exit(BL_INIT);
   
    DummyReference();

}

#endif /* __MINI_BOOTLOADER__ */

kal_uint32 BlFeatureCombination(void)
{

#ifdef __MINI_BOOTLOADER__
   return g_bootloader_gfh.gfh_arm_bl_info.m_feature_combination;
#else
   return g_ext_bootloader_gfh.gfh_arm_bl_info.m_feature_combination;
#endif

}


#ifdef __EXT_BOOTLOADER__

BL_STATUS InitExt(void)
{
    BL_STATUS status = BL_ERROR_NONE;

    INT_Trace_Enter(BL_EXT_INIT);

    INT_Trace_Enter(BL_INIT_EXT_FLASH_DRV);
    status = InitFlashDriver();
    if( status != BL_ERROR_NONE){
        goto _end;
    }
    INT_Trace_Exit(BL_INIT_EXT_FLASH_DRV);

    DummyReference();

    //Init Crypto lib
    BL_PRINT(LOG_DEBUG, "Crypto lib Init\n\r");
    SSS_Init_Crypto_Drv(NULL, NULL);

    INT_Trace_Exit(BL_EXT_INIT);

_end:
    
    return status;
}

void GetFeatureCombination(void)
{
    INT_Trace_Enter(BL_GET_FATURE_COMINATION);

    BL_DEBUG_PRINT("GetFeatureCombination()\n\r");

    g_mauiFeatureCombination = 0;

    GFH_MAUI_INFO_v1 *pMauiInfo = bl_GetMAUIInfo();

    if(pMauiInfo)
    {
        g_mauiFeatureCombination = pMauiInfo->m_feature_combination;
    }

    INT_Trace_Exit(BL_GET_FATURE_COMINATION);
}

kal_bool CheckPairedVersion(void)
{
    GFH_MAUI_INFO_v1 *pMauiInfo = bl_GetMAUIInfo();

    if(pMauiInfo)
    {
        if( pMauiInfo->m_bl_maui_paired_ver != g_ext_bootloader_gfh.gfh_arm_bl_info.m_bl_maui_paired_ver)
        {
            BL_PRINT(LOG_ERROR, "Paired version mismatched, %d, %d\n\r", pMauiInfo->m_bl_maui_paired_ver, g_ext_bootloader_gfh.gfh_arm_bl_info.m_bl_maui_paired_ver);
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;   
}

kal_bool CheckFeatureCompatibility(kal_uint32 mauiFeatureSet)
{
    kal_uint32 blFeatureSet = BlFeatureCombination();

    kal_bool featureIncomp = KAL_FALSE;

    if( (blFeatureSet & MAUI_FC_SECURE) != (mauiFeatureSet & MAUI_FC_SECURE) )
    {
        featureIncomp = KAL_TRUE;
    }

    if( !(blFeatureSet & MAUI_FC_FOTA) && (mauiFeatureSet & MAUI_FC_FOTA) )
    {
        featureIncomp = KAL_TRUE;
    }

    if( !(blFeatureSet & MAUI_FC_NOR_FLASH_BOOTING) && (mauiFeatureSet & MAUI_FC_NOR_FLASH_BOOTING) )
    {
        featureIncomp = KAL_TRUE;
    }

    if( (blFeatureSet & MAUI_FC_FAST_LOGO) != (mauiFeatureSet & MAUI_FC_FAST_LOGO) )
    {
        featureIncomp = KAL_TRUE;
    }

    return (!featureIncomp);

}

kal_bool CheckFeatureCombination(void)
{
    if(g_maui_load_addr != INVALID_START_ADDR)
    {
        if( CheckFeatureCompatibility(g_mauiFeatureCombination) == KAL_FALSE )
        {
            BL_PRINT(LOG_ERROR, "Incompatible features, mauiFeature=%d\n\r", g_mauiFeatureCombination);
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;   
}

#endif /* __EXT_BOOTLOADER__ */

#ifdef __RVCT__
/*************************************************************************
* FUNCTION
*  __user_initial_stackheap
*
* DESCRIPTION
*  This dummy function is implemented to make the linker happy for RVCT.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
__value_in_regs struct __initial_stackheap __user_initial_stackheap(unsigned i0, unsigned i1, unsigned i2, unsigned i3)
{
   struct __initial_stackheap config;

   config.heap_base = i1;
   config.heap_limit = i1;
   config.stack_base = i1; 
   config.stack_limit = 0;

   return config;
}

/*************************************************************************
* FUNCTION
*  __ARM_get_argv
*
* DESCRIPTION
*  This dummy function is implemented to suppress argc,argv processing
*  in standard C library
*
* CALLS
* PARAMETERS
* RETURNS
* GLOBALS AFFECTED
*************************************************************************/
__value_in_regs struct __argc_argv $Sub$$__ARM_get_argv(void *ptr)
{
    struct __argc_argv a = {0};
    return a;
}

/*************************************************************************
* FUNCTION SYMBOL
*  __use_no_heap
*
* DESCRIPTION
*  You can reference the __use_no_heap or __use_no_heap_region symbols in
*  your code in order to guarantee that no heap using functions are linked
*  in from the ARM library.
*
*************************************************************************/
//#pragma import(__use_no_heap)

#pragma import(__user_initial_stackheap)
#endif   /* __RVCT__ */

#ifdef __MINI_BOOTLOADER__

/**********************************************************
Description : Generation of the random seed
Input       : None
Output      : Generated seed
***********************************************************/

#define REG_RNDR                (BASE_ADDR_L2MISC + 0x01F0)

void GenerateRandomSeed()
{
    g_randomSeed = DRV_Reg32(REG_RNDR);
}
#endif /* __MINI_BOOTLOADER__ */

