/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * Filename:
 * ---------
 *   drv_dcm.c
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * Barry Hong
 *
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * do not gating GRP1_HCLK_OFF_EN in K2
 *
 * removed!
 * removed!
 * 	fix check AfnUfn location
 *
 * removed!
 * removed!
 * update shared memory API
 *
 * removed!
 * removed!
 * LR9.W1421 merge from MOLY CL#572419, CL#575172
 *
 * removed!
 * removed!
 * add UFN/AFN check patch
 *
 * removed!
 * removed!
 * update emi header name, request by emi owner Junhua kuo
 *
 * removed!
 * removed!
 * 
 * [MT6589][SYSTEM SERVICE] MT6589 DCM driver porting (dummy, since no need to support MT6589 DCM on MOLY)
 *
 * removed!
 * removed!
 * fix build error because the TOPSM API renaming
 *
 * removed!
 * removed!
 * check sleep lock in DCM handler
 *
 * removed!
 * removed!
 * add enter WFI flag
 *
 * removed!
 * removed!
 * remove static attribute for drvtest
 *
 * removed!
 * removed!
 * add dcm/dormant debug information in CCCI mechanism
 *
 * removed!
 * removed!
 * Add ROME dormant function
 *
 * removed!
 * removed!
 * Merging
 *      
 *     //MOLY_CBr/chin-chieh.hung/MT6595E1_BRING_UP_DEV_W1402p7/mcu/driver/devdrv/dcm/inc/drv_dcm.h
 *      
 *     to //MOLY/TRUNK/MOLY/mcu/driver/devdrv/dcm/inc/drv_dcm.h
 *
 * removed!
 * removed!
 * Fix MT6290E2 EMI HW issue
 *
 * removed!
 * removed!
 * Add DCM flow
 *
 * removed!
 * removed!
 * DCM code re-arch
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Patch for OSTD interrupt disabpear issue
 *
 * removed!
 * removed!
 * Integration change.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * remove unused variable
 *
 * removed!
 * removed!
 * user updated dummy_fdma API (need CL:219427)
 *
 * removed!
 * removed!
 * Low Power Feature patch back from CBr
 *
 * removed!
 * removed!
 * .update DCM driver
 *
 * removed!
 * removed!
 * .add fakeAPI enter_PLL_save_mode/leave_PLL_save_mode
 *
 * removed!
 * removed!
 * .remove unused code and modify TCM section declare
 *
 * removed!
 * removed!
 * .Sync DCM function to MOLY 6290 for sleep flow
 *
 * removed!
 * removed!
 * .remove fakeAPI
 ****************************************************************************/
#ifdef __MTK_TARGET__

#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "intrCtrl.h"

#include "drv_dcm.h"

#include "dcl.h"
#include "drv_hisr.h"
#include "devdrv_ls.h"


#include "reg_base.h"
#include "config_hw.h"
#include "init.h"
#include "cp15.h"
#include "us_timer.h"
#include "drv_comm.h"
#if !defined(MT6752)
# include "emi_hw_internal.h"
#endif
#include "drvpdn.h"
#include "pll.h"
#include "us_timer.h"

#include "l1_interface.h"
#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
#include "ostd_public.h"
#endif

#include "SST_sla.h"
#include "system_trc.h"
#include "sleepdrv_interface.h"

#if defined (__MODEM_CCCI_EXIST__)
#include "ccci.h"
#endif //__MODEM_CCCI_EXIST__

#include "ex_mem_manager_public.h"



/*
 * NoteXXX: SaveAndSetIRQMask()/RestoreIRQMask() are APIs for appilcations to disable/restore
 *          IRQ. They will restrict the disable duration. But idle task disables IRQ for a
 *          time due to DCM. Thus LockIRQ()/RestoreIRQ() are used here. Only the idle task
 *          can use them!! Other applications are not allowed to use LockIRQ()/RestoreIRQ().
 */
kal_uint32 LockIRQ(void);
void RestoreIRQ(kal_uint32);

extern void dormant_mode_activate(void);
extern void dormant_mode_init(void);
extern kal_bool OSTD_Allow_Dormant_Mode(void);
//#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"

extern kal_uint32 dcm_mcubus_dcm_off;

//DEVDRV_LS_INTSRAM_RW volatile static kal_uint32 WFI_Handle_Count =0 ;
DEVDRV_LS_INTSRAM_RW volatile static kal_bool OST_ReadyToSlept = KAL_FALSE;

#if defined(__FAST_FRC__)
/* enterWFI: the FastFRC is not updated when system enter WFI and DCM is enabled(clock will be gated)
 * We set this flag to indicated this situation; The maximal sync delay is 1us after leaving WFI.
 * Scenario/Solution:
 *   1. Leave WFI means the ISR in. Because the ISR handling time is much logner than 1us, 
 *      we just consider the FRC user in LISR.
 *   2. For the LISR user under UNIFIED_ISR_LEVEL, there is no get FRC requirement in this flow
 *   3. For SWLA is enabled environment, the LISR start logging needs to get the FRC value,
 *      we provide the original FRC API for this purpose, 
 *      and the enterWFI flag is clear as KAL_FALSE in the SWLA function.
 */
DEVDRV_LS_INTSRAM_ZI kal_bool enterWFI = KAL_FALSE;
#endif /* __FAST_FRC__ */

/* This value is ctrl by __MCU_DORMANT_MODE__ compile options */
//DEVDRV_LS_INTSRAM_RW volatile static kal_bool OST_AllowedToPowerDown = KAL_FALSE;

#if defined(MT6290_S00) && defined(MTK_SLEEP_ENABLE) && !defined(USB30_ENABLE)
    #define LP_HWBUG_PATCH_START() dummy_fdma(KAL_TRUE)
    #define LP_HWBUG_PATCH_END()   dummy_fdma(KAL_FALSE)
#elif defined(MT6290_S01) && defined(MTK_SLEEP_ENABLE) && !defined(USB30_ENABLE)
    #define LP_HWBUG_PATCH_START()  \
        do {    \
            UNLOCK_EMI_REG();   \
            EMI_PD_REG_ACCESS_EN(); \
            LOCK_EMI_REG(); \
        } while(0)
    #define LP_HWBUG_PATCH_END()    \
        do {    \
            UNLOCK_EMI_REG();   \
            EMI_PD_REG_ACCESS_DIS(); \
            LOCK_EMI_REG(); \
        } while(0)
#else  /* MT6290_S00 && MTK_SLEEP_ENABLE && !USB30_ENABLE */
    #define LP_HWBUG_PATCH_START()
    #define LP_HWBUG_PATCH_END()
#endif /* MT6290_S00 && MTK_SLEEP_ENABLE && !USB30_ENABLE */

#if defined(__MCU_DORMANT_MODE__)
    #define IFDEF_DORMANT(def_statement, undef_statement) def_statement
#else  /* __MCU_DORMANT_MODE__ */
    #define IFDEF_DORMANT(def_statement, undef_statement) undef_statement
#endif /* __MCU_DORMANT_MODE__ */

#if defined( DCM_ENABLE )
    #define IFDEF_DCM(def_statement, undef_statement) def_statement
#else  /* DCM_ENABLE */
    #define IFDEF_DCM(def_statement, undef_statement) undef_statement
#endif /* DCM_ENABLE */

#if defined(MT6290) && defined(__ARM7EJ_S__)
    #define IFDEF_MDCOPRO(def_statement, undef_statement) def_statement
#else  /* MT6290 && __ARM7EJ_S__ */
    #define IFDEF_MDCOPRO(def_statement, undef_statement) undef_statement
#endif /* MT6290 && __ARM7EJ_S__ */

#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
    #define LOWPWER_ENTER_PAUSE_MODE
#endif

#if defined(__MD2__) && defined(MT6752)
    #define dcm_ust_get_current_time_source() ust_get_current_time()
#else
    #define dcm_ust_get_current_time_source() ust_get_current_time_source()
#endif

#if defined( DCM_ENABLE )

extern void lpm_init(void);
/* For MD_GLOBAL_0 setting */
#define PDMG_CG     ( 1UL << 0)
#define BOOTSLV_CG  ( 1UL << 1)
#define LPM_SEL     ( 1UL <<19)

/* For MD_GLOBAL_1 setting */
#define DCMGRP0_MCLKSLW_EN   ( 1UL <<20)
#define DCMGRP1_MCLKSLW_EN   ( 1UL <<21)
#define DCMGRP0_XCLKOFF_EN   ( 1UL <<22)
#define DCMGRP1_HCLKOFF_EN   ( 1UL <<23)
#define DCMGRP1_MDMCU_MCU_EN ( 1UL <<24)
#define DCMGRP1_MDMCU_BUS_EN ( 1UL <<25)

static struct 
{
   kal_uint32   dcmDisable;                    /* Default not disable DCM */
   kal_uint8    dcmHandleCount;
   
   #if defined(LOWPWER_ENTER_PAUSE_MODE)
   kal_bool OST_ReadyToSlept;
   Sleep_Time allow_sleep_dur;
   #endif
} dcm DEVDRV_LS_INTSRAM_ZI; 
 
static int _dcm_hw_setting(kal_int32 on);
void _dcm_hw_top_mcu_dcm(int on);

//volatile static kal_bool dcm_executed DEVDRV_LS_INTSRAM_RW = KAL_FALSE;

/* Query the MDMCU DCM Status
 * When the MDMCU is running, the DCM is off.
 * If the MDMCU is enter DCM mode, the MDMCU clock is gated.
 */
kal_bool DCM_Query_Status(void)
{
//   kal_bool status = dcm_executed;
//   dcm_executed = KAL_FALSE;/* Restored to default state */
//   return status;
    IFDEF_DCM(return KAL_TRUE, return KAL_FALSE);
} 
kal_uint8 DCM_GetHandle( void )
{    
   ASSERT(dcm.dcmHandleCount<32);
   return dcm.dcmHandleCount++;   /* Using handle number from 0, not 1 */
}


void DCM_Enable( kal_uint8 handle )
{   
   kal_uint32 _savedMask;
   
   _savedMask = SaveAndSetIRQMask();
   dcm.dcmDisable &= ~(1 << handle);   

   if(0 == dcm.dcmDisable)
   {
       _dcm_hw_setting(1);
   }
   RestoreIRQMask(_savedMask);
}

void DCM_Disable( kal_uint8 handle )
{
   kal_uint32 _savedMask;
   
   _savedMask = SaveAndSetIRQMask();
   dcm.dcmDisable |= (1 << handle);

   _dcm_hw_setting(0);

   RestoreIRQMask(_savedMask);
}

static int _dcm_hw_setting(kal_int32 on)
{
    if (on != 0) { 
        /** 
         * DCM enable sequence:  level-2 DCM enable, then level-1 DCM enable
         **/

        // MD Level-2 DCM Enable
        /* MD Level-2 DCM Enable */
#if defined(MT6752)
        DRV_SetReg32(MD_GLOBAL_CON1, 0x03700000); // Bit 25: (L2) MDMCU BUS,
                                                  // Bit 24: (L2) MDMCU MCU,
                                                  // Bit 23: GRP1_HCLK_OFF_EN,
                                                  // Bit 22: GRP0_XCLK_OFF_EN,
                                                  // Bit 21: GRP1 MCLKSLW_EN
                                                  // Bit 20: GRP0 MCLKSLW_EN
#else /* MT6752 */
        DRV_SetReg32(MD_GLOBAL_CON1, 0x03F00000); // Bit 25: (L2) MDMCU BUS,
                                                  // Bit 24: (L2) MDMCU MCU,
                                                  // Bit 23: GRP1_HCLK_OFF_EN,
                                                  // Bit 22: GRP0_XCLK_OFF_EN,
                                                  // Bit 21: GRP1 MCLKSLW_EN
                                                  // Bit 20: GRP0 MCLKSLW_EN
#endif /* MT6752 */

        /* L1 MDMCU DCM Enable */
        DRV_WriteReg32(MD_TOP_MDMCU_DCM_CON0, 0x030F0F00); // Bit    25: DBC_EN, 
                                                           // Bit    24: DCM_EN,
                                                           // Bit 22-16: DBC_CNT, 
                                                           // Bit 12- 8: IDLE_FSEL,
                                                           // Bit  4- 0: FSEL

        DRV_WriteReg32(MD_TOP_MDMCU_DCM_CON1, 0x1F);       // Bit  4- 0: APB_SEL
        DRV_ClrReg32(MD_TOP_MDMCU_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
        DRV_SetReg32(MD_TOP_MDMCU_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
        DRV_ClrReg32(MD_TOP_MDMCU_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
#if !defined(MT6595_S00)
        /* L1 MDBUS DCM Enable */
        DRV_WriteReg32(MD_TOP_MDBUS_DCM_CON0, 0x030F0F00); // Bit    25: DBC_EN,
                                                           // Bit    24: DCM_EN,
                                                           // Bit 22-16: DBC_CNT,
                                                           // Bit 12- 8: IDLE_FSEL,
                                                           // Bit  4- 0: FSEL
        DRV_WriteReg32(MD_TOP_MDBUS_DCM_CON1, 0x1F);       // Bit  4- 0: APB_SEL
        DRV_ClrReg32(MD_TOP_MDBUS_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
        DRV_SetReg32(MD_TOP_MDBUS_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
        DRV_ClrReg32(MD_TOP_MDBUS_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE 
#endif /* !MT6595_S00 */
    }
    else {
        /** 
         * DCM disable sequence: level-1 Bus DCM disable, then level-2 Bus DCM disable
         **/

        // L1 MDMCU DCM Disable
        DRV_ClrReg32(MD_TOP_MDMCU_DCM_CON0, (1<<24));      // Bit 24: MDMCU_DCM_EN
        DRV_WriteReg32(MD_TOP_MDMCU_DCM_CON1, 0x22);       // Bit  4- 0: APB_SEL:
        DRV_ClrReg32(MD_TOP_MDMCU_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
        DRV_SetReg32(MD_TOP_MDMCU_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
        DRV_ClrReg32(MD_TOP_MDMCU_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE

        // L1 MDBUS DCM Disable
        DRV_ClrReg32(MD_TOP_MDBUS_DCM_CON0, (1<<24));      // Bit 24: MDMCU_DCM_EN
        DRV_WriteReg32(MD_TOP_MDBUS_DCM_CON1, 0x22);       // Bit  4- 0: APB_SEL:
        DRV_ClrReg32(MD_TOP_MDBUS_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
        DRV_SetReg32(MD_TOP_MDBUS_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
        DRV_ClrReg32(MD_TOP_MDBUS_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE


        // L2 MD DCM Disable
        DRV_ClrReg32(MD_GLOBAL_CON1, ((1<<25)|(1<<24)|(1<<23)|(1<<22)|(3<<20)));      // Bit 24: MDMCU_DCM_EN
    }

    return 0;
}

#if defined(__MD2__) && defined(MT6752)
void DCM_Recovery(void)
{
}
#endif /* __MD2__ && MT6752 */

#else /*!defined(DCM_ENABLE)*/

kal_bool DCM_Query_Status(void)
{
    return KAL_FALSE;
}
kal_uint8 DCM_GetHandle( void )
{
    return 0;
}

void DCM_Enable( kal_uint8 handle ) {}
void DCM_Disable( kal_uint8 handle ) {}

#endif /*!defined(DCM_ENABLE)*/

void enter_PLL_save_mode(pll_use_scenario_t pll_scenario) {}
void leave_PLL_save_mode(pll_use_scenario_t pll_scenario) {}


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
#endif

void DCM_Init( void )
{
    IFDEF_DORMANT(dormant_mode_init(), );

#if defined( DCM_ENABLE )
    _dcm_hw_setting(1);
    #if defined(__MTK_INTERNAL__) && defined (DCM_LPM_ENABLE)
    lpm_init();
    #endif //__MTK_INTERNAL__

    /* Set all mask bits */
//    DRV_SetReg32(MD_GLOBAL_CLR0, 0x3E600000);
#endif /* DCM_ENABLE */
}
#if defined(MT6290) && defined(MTK_SLEEP_ENABLE) && defined(MT6290_S00)
extern void dummy_fdma(kal_uint32 gdma_start);
#endif

#if defined( DCM_ENABLE )
void _dcm_hw_top_mcu_dcm(int on)
{    
    if (on != 0) {
        // L1 MDMCU DCM Enable
        DRV_WriteReg32(MD_TOP_MDMCU_DCM_CON0, 0x030F0F00); // Bit    25: DBC_EN, 
                                                           // Bit    24: DCM_EN,
                                                           // Bit 22-16: DBC_CNT, 
                                                           // Bit 12- 8: IDLE_FSEL,
                                                           // Bit  4- 0: FSEL

        DRV_WriteReg32(MD_TOP_MDMCU_DCM_CON1, 0x1F);       // Bit  4- 0: APB_SEL
        DRV_ClrReg32(MD_TOP_MDMCU_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
        DRV_SetReg32(MD_TOP_MDMCU_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
        DRV_ClrReg32(MD_TOP_MDMCU_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
    }
    else {
        // L1 MDMCU DCM Disable
        DRV_ClrReg32(MD_TOP_MDMCU_DCM_CON0, (1<<24));      // Bit 24: MDMCU_DCM_EN
        DRV_WriteReg32(MD_TOP_MDMCU_DCM_CON1, 0x22);       // Bit  4- 0: APB_SEL:
        DRV_ClrReg32(MD_TOP_MDMCU_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
        DRV_SetReg32(MD_TOP_MDMCU_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
        DRV_ClrReg32(MD_TOP_MDMCU_DCM_CON1, 0x20);         // Bit     5: APB_TOGGLE
    }
}
#endif /* DCM_ENABLE */


IFDEF_MDCOPRO(DEVDRV_LS_COPRO_INTSRAM_ROCODE, DEVDRV_LS_INTSRAM_ROCODE)
void DCM_Handler( void )
{
    kal_uint32 _savedMask;
    /* Partial sleep mode for MCU and AVB block.
       To force MCU and AVB bus CLK stopped when system is in idle task.
       System will run again and CLK resume automatically only when IRQ comes.
    */

#if defined( DCM_ENABLE )
    register kal_uint32 start, end, duration;
    #if defined(LOWPWER_ENTER_PAUSE_MODE)
    kal_get_sleep_time(&dcm.allow_sleep_dur);
    #endif /* LOWPWER_ENTER_PAUSE_MODE */

//    IFDEF_DORMANT(OST_AllowedToPowerDown = OSTD_Allow_Dormant_Mode(), );
    _savedMask = LockIRQ();
    start = ust_get_current_time();

    #if defined(LOWPWER_ENTER_PAUSE_MODE)
    /* Enable nIRQ wake-up event after I-Bit OFF. */
    IFDEF_MDCOPRO(, OSTD_EnableNIRQ());

    /* If the sleep is lock, try pure WFI directly to avoid the FRC/Frame Counter Mismatch Error */
    if( OSTD_CheckIsSleepLock() )
    {
        dcm.OST_ReadyToSlept = OST_ReadyToSlept = KAL_FALSE;
    }
    else
    {
        /* Get confirm */
        if( kal_is_valid_sleep_time( &dcm.allow_sleep_dur ) == 0 )
        {
            /* Disable nIRQ wake-up event before I-Bit ON. */
            IFDEF_MDCOPRO(, OSTD_DisableNIRQ());
            RestoreIRQ(_savedMask);
            return;
        }
        /* Check & Trigger OST Pause Mode:
             MUST be called inside of I-Bit protection:
             No need to check return value while DCM disabled. */
        dcm.OST_ReadyToSlept = OST_ReadyToSlept = OSTD_CheckSleep();
    }
    #endif /* LOWPWER_ENTER_PAUSE_MODE */
    if ( (OST_ReadyToSlept == KAL_FALSE) && (dcm.dcmDisable == 0) )
    {
        /* System will not enter pause mode, 
           CPU enter pure WFI mode, dormant is not necessary 
           Only DCM enabled, CPU clock is gated
         */

        //EMI_Dummy_Read(); //MOLY's chips does not need this workaround

        /* check if IRQ is disabled for more than 60 qbits */
        end = ust_get_current_time();
        duration = ust_get_duration(start, end);
        if (duration > 60) {
           if( !L1_CHECK_ASSERT_BYPASS() )
              EXT_ASSERT(0, duration, start, end);
        }
        #if defined (__MODEM_CCCI_EXIST__)
        volatile kal_uint32 usc;
        usc = ust_get_current_time();
        EMM_WriteDbgInfo(EMM_IDLE_TASK_DCM_ENTER, (void*)&usc);
        #endif //#if defined (__MODEM_CCCI_EXIST__)

        arm_enter_standby_mode(0);

        #if defined(__FAST_FRC__)
        enterWFI = KAL_TRUE;
        #endif /* __FAST_FRC__ */
        #if defined (__MODEM_CCCI_EXIST__)
        usc = dcm_ust_get_current_time_source();
        EMM_WriteDbgInfo(EMM_IDLE_TASK_DCM_LEAVE, (void*)&usc);
        #endif //#if defined (__MODEM_CCCI_EXIST__)
    }
    else
    {
        #if defined (__MODEM_CCCI_EXIST__)
        volatile kal_uint32 usc, type, OST_InfiniteSlept;
        #if defined(LOWPWER_ENTER_PAUSE_MODE)
        OST_InfiniteSlept = OSTD_Infinite_Sleep_Query();
        #else  /* LOWPWER_ENTER_PAUSE_MODE */
        OST_InfiniteSlept = KAL_FALSE;
        #endif /* LOWPWER_ENTER_PAUSE_MODE */
        type = (KAL_TRUE == OST_ReadyToSlept) ? EMM_IDLE_TASK_SLEEP_ENTER : EMM_IDLE_TASK_WFI_ENTER;
        usc = ust_get_current_time();
        if (KAL_TRUE == OST_InfiniteSlept)
            EMM_WriteDbgInfo(EMM_INFINITESLEEP_WFI, (void*)&usc);
        else
            EMM_WriteDbgInfo(type, (void*)&usc);
        #endif //#if defined (__MODEM_CCCI_EXIST__)
        if(KAL_TRUE == OST_ReadyToSlept)
        {
            /* workaround: to disable TOP MDMCU DCM to push "axi_sleep_protect ready".
             * TOP MDMCU DCM will gating mcu_clock that are referenced by AXI_Sleep_Protect, 
             * which will lost protect ready while WFI for entering sleep.
             */
            _dcm_hw_top_mcu_dcm(0);
            IFDEF_DORMANT(dormant_mode_activate(), arm_enter_standby_mode(0));
            _dcm_hw_top_mcu_dcm(1);
        }
        else
        {
            arm_enter_standby_mode(0);
        }
        #if defined(__FAST_FRC__)
        enterWFI = KAL_TRUE;
        #endif /* __FAST_FRC__ */
        #if defined (__MODEM_CCCI_EXIST__)
        usc = dcm_ust_get_current_time_source();
        type = (type == EMM_IDLE_TASK_SLEEP_ENTER) ? EMM_IDLE_TASK_SLEEP_LEAVE : EMM_IDLE_TASK_WFI_LEAVE;
        EMM_WriteDbgInfo(type, (void*)&usc);
        #endif //#if defined (__MODEM_CCCI_EXIST__)
    }


    #if defined(LOWPWER_ENTER_PAUSE_MODE)
    /* Disable nIRQ wake-up event before I-Bit ON. */
    IFDEF_MDCOPRO(, OSTD_DisableNIRQ());
    #endif /* LOWPWER_ENTER_PAUSE_MODE */
    RestoreIRQ(_savedMask);

#else //DCM_ENABLE
    #if defined(LOWPWER_ENTER_PAUSE_MODE)
    Sleep_Time allow_sleep_dur;

    kal_get_sleep_time(&allow_sleep_dur);
    #endif /* LOWPWER_ENTER_PAUSE_MODE */

//    IFDEF_DORMANT(OST_AllowedToPowerDown = OSTD_Allow_Dormant_Mode(), );

    _savedMask = LockIRQ();

    #if defined(LOWPWER_ENTER_PAUSE_MODE)
    /* Enable nIRQ wake-up event after I-Bit OFF. */
    IFDEF_MDCOPRO(, OSTD_EnableNIRQ());
    /* Get confirm */
    if( kal_is_valid_sleep_time( &allow_sleep_dur ) == 0 )
    {
        /* Disable nIRQ wake-up event before I-Bit ON. */
        IFDEF_MDCOPRO(, OSTD_DisableNIRQ());
        RestoreIRQ(_savedMask);
        return;
    }
    /* Check & Trigger OST Pause Mode:
         MUST be called inside of I-Bit protection:
         No need to check return value while DCM disabled. */
    OST_ReadyToSlept = OSTD_CheckSleep();
    #endif /* LOWPWER_ENTER_PAUSE_MODE */

    /*To temporarily avoid the problem on AHB.*/

//    if(WFI_Handle_Count == 0 )
    {

        if( (KAL_TRUE == OST_ReadyToSlept))
        {
            /* System will enter pause mode, 
               CPU enter dormant if dormant feature is turn on.
               Otherwise, just call WFI.
             */
            LP_HWBUG_PATCH_START();
            IFDEF_DORMANT(dormant_mode_activate(), arm_enter_standby_mode(0));
            LP_HWBUG_PATCH_END();
            #if defined(MT6290) && defined(LOWPWER_ENTER_PAUSE_MODE)
            OSTD_CheckAfnUfn2TriggerISR();
            #endif /* MT6290 && LOWPWER_ENTER_PAUSE_MODE */
        }
        else
        {
            /* System will not enter pause mode, 
               CPU enter pure WFI mode, dormant is not necessary */
            LP_HWBUG_PATCH_START();
            arm_enter_standby_mode(0);
            LP_HWBUG_PATCH_END();
        }

    }


    #if defined(LOWPWER_ENTER_PAUSE_MODE)
    /* Disable nIRQ wake-up event before I-Bit ON. */
    IFDEF_MDCOPRO(, OSTD_DisableNIRQ());
    #endif /* LOWPWER_ENTER_PAUSE_MODE */
    RestoreIRQ(_savedMask);

#endif /* defined(DCM_ENABLE)*/
}


#endif /* __MTK_TARGET__ */ 
