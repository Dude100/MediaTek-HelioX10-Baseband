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
 *   drv_pfb.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file declares CR4 prefetch buffer related APIs.
 *   We seperate it from bus_drv.c
 *
 * Author:
 * -------
 *  
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * Before CG PFB, polling mi0 & si0 busy status bits until they are idle
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * [PFB] Add comment, re-checkin to same CR ID of same issue
 *
 * removed!
 * removed!
 * [PFB] Disable branch prediction & return stack before enable/disable PFB; re-enable branch prediction & return stack after enable/disable PFB
 *
 * removed!
 * removed!
 * [PFB] Add delay before disable PFB to avoid risk of bus hang
 *
 * removed!
 * removed!
 * [PFB] Fix MT6582_MD2 build error
 *
 * removed!
 * removed!
 * [PFB] Add DCM operation when disabling PFB
 *
 * removed!
 * removed!
 * [PFB] Use inline assembly instead
 *
 * removed!
 * removed!
 * Merge PFB driver from MT6595_E1_DEV to TRUNK
 *
 * removed!
 * removed!
 * [PFB] Add ISB right after PFB enable action. Avoid instruction fetch and PFB switching conflicting
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * 1. No need to disable PFB before dormant sleep 
 * 2. Add ISB before PFB enabled
 * 3. Backup and restore tcm region used by bootrom
 *
 * removed!
 * removed!
 * 1. Add CR4 dormant API and ATEST test item
 * 2. Update link section name oF PFB
 *
 * removed!
 * removed!
 * 1. Add CR4 dormant API and ATEST test item
 * 2. Update link section name oF PFB
 *
 * removed!
 * removed!
 * Enable Prefetch Buffer and remove it from fake api.
 ****************************************************************************/

#include "drv_comm.h"
#include "drvpdn.h"
#include "devdrv_ls.h"
#include "sync_data.h"
#include "pfb_reg.h"
#include "dcm_sw.h"
#include "cp15_int.h"

#define GET_CURRENT_TIME(v) do{\
                                CP15_PMU_GET_CYCLE_CNT(v); \
                            }while(0)

#define GET_DURATION(d,t1,t2) do{\
                                 d = ((t2) >= (t1)) ? ((t2) - (t1)) : (0xFFFFFFFF - (t1) + (t2));\
                              }while(0)


#define PFB_ACTLR_BP_MASK       0x00018000
#define PFB_ACTLR_BP_NORMAL     (0x0 << 15)
#define PFB_ACTLR_BP_NOT_TAKEN  (0x2 << 15)
#define PFB_ACTLR_RSDIS_MASK    0x00020000
#define PFB_ACTLR_RS_DISABLE    (0x1 << 17)
#define PFB_ACTLR_DEOLP_MASK    0x00200000
#define PFB_ACTLR_OLP_DISABLE   (0x1 << 21)
#define PFB_ACTLR_CLR_MASK      0xFFDC7FFF

#define PFB_ACTLR_DEBUG         0

#if PFB_ACTLR_DEBUG

// In enablePrefetchBuffer()
volatile kal_uint32 g_enpfb_be_actlr_old   = 0;    // Before : branch prediction backup
volatile kal_uint32 g_enpfb_be_bp_old      = 0;    // Before : branch prediction backup
volatile kal_uint32 g_enpfb_be_rsdis_old   = 0;    // Before : return stack backup
volatile kal_uint32 g_enpfb_be_deolp_old   = 0;    // Before : end of loop prediction
volatile kal_uint32 g_enpfb_be_actlr_set   = 0;    // Before : ACTLR set value
volatile kal_uint32 g_enpfb_be_actlr       = 0;    // Before : ACTLR value after set
volatile kal_uint32 g_enpfb_af_actlr_set   = 0;    // After : ACTLR set value
volatile kal_uint32 g_enpfb_af_actlr       = 0;    // After : ACTLR value after set
// In disablePrefetchBuffer()
volatile kal_uint32 g_dispfb_be_actlr_old   = 0;    // Before : branch prediction backup
volatile kal_uint32 g_dispfb_be_bp_old      = 0;    // Before : branch prediction backup
volatile kal_uint32 g_dispfb_be_rsdis_old   = 0;    // Before : return stack backup
volatile kal_uint32 g_dispfb_be_deolp_old   = 0;    // Before : end of loop prediction
volatile kal_uint32 g_dispfb_be_actlr_set   = 0;    // Before : ACTLR set value
volatile kal_uint32 g_dispfb_be_actlr       = 0;    // Before : ACTLR value after set
volatile kal_uint32 g_dispfb_af_actlr_set   = 0;    // After : ACTLR set value
volatile kal_uint32 g_dispfb_af_actlr       = 0;    // After : ACTLR value after set

#endif

volatile kal_uint32 g_enpfb_delay_count     = 0;
volatile kal_uint32 g_dispfb_delay_count    = 0;

/*************************************************************************
* FUNCTION
*  enablePrefetchBuffer
*
* DESCRIPTION
*  Enable instruction prefetch buffer.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
#if defined(__MTK_TARGET__)
DEVDRV_LS_INTSRAM_ROCODE void enablePrefetchBuffer(void)
#else
void enablePrefetchBuffer(void)
#endif
{
#ifdef MT6290 // MT6290
    volatile kal_uint32 start_cycle = 0, current_cycle = 0, duration = 0;
    volatile kal_uint32 actlr = 0, bp_old = 0, rsdis_old = 0, deolp_old = 0;

    if ((DRV_Reg32(REG_PFB_CTRL) & (0x5)) == 0x5) {
        return ;
    }

    /* Disable CR4 branch prediction (bit[16:15]) and return stack (bit[17]) */
    // Read from Auxiliary Control Register
    __asm__ __volatile__
    (
        "DSB\r\n"
        "MRC p15,0,%0,c1,c0,1\r\n"
        :"=r"(actlr)
    );
#if PFB_ACTLR_DEBUG
    g_enpfb_be_actlr_old = actlr;
#endif

    bp_old = actlr & PFB_ACTLR_BP_MASK;                                 // backup BP
    rsdis_old = actlr & PFB_ACTLR_RSDIS_MASK;                           // backup RSDIS
    deolp_old = actlr & PFB_ACTLR_DEOLP_MASK;                           // backup DEOLP
    // Set BP to not taken and return stack to disabled
    actlr = ((actlr & PFB_ACTLR_CLR_MASK) | PFB_ACTLR_BP_NOT_TAKEN | PFB_ACTLR_RS_DISABLE | PFB_ACTLR_OLP_DISABLE);
#if PFB_ACTLR_DEBUG
    g_enpfb_be_bp_old = bp_old;
    g_enpfb_be_rsdis_old = rsdis_old;
    g_enpfb_be_deolp_old = deolp_old;
    g_enpfb_be_actlr_set = actlr;
#endif

    // Write settings to Auxiliary Control Register
    __asm__ __volatile__
    (
        "MCR p15,0,%0,c1,c0,1\r\n"
        "ISB\r\n"
        :
        :"r"(actlr)
    );

#if PFB_ACTLR_DEBUG
    // Read settins again
    __asm__ __volatile__
    (
        "MRC p15,0,%0,c1,c0,1\r\n"
        :"=r"(g_enpfb_be_actlr)
        :
    );
#endif

    /*
     * Wait for 2us.
     *
     * [ WHY 2us ]
     *     In MT6290, EMI busy latency is 200 ~ 300 ns.
     *     We use a safer value of 2us.
     */
    g_enpfb_delay_count = 0;
    GET_CURRENT_TIME(start_cycle);
    do {
        GET_CURRENT_TIME(current_cycle);
        GET_DURATION(duration,start_cycle,current_cycle);
        g_enpfb_delay_count++;
    } while (((2 * CPU_CLOCK_MHZ) > duration) && (g_enpfb_delay_count < CPU_CLOCK_MHZ));

    DRV_WriteReg32_NPW(REG_PFB_CTRL, DRV_Reg32(REG_PFB_CTRL) | (0x00000001));	// Enable PFB first
    DRV_WriteReg32_NPW(REG_PFB_CTRL, DRV_Reg32(REG_PFB_CTRL) | (0x00000004));	// Switch Bus to PFB

    /* According to backup value to enable CR4 branch prediction (bit[16:15]) and return stack (bit[17]) */
    // Read from Auxiliary Control Register
    __asm__ __volatile__
    (
        "ISB\r\n"
        "MRC p15,0,%0,c1,c0,1\r\n"
        :"=r"(actlr)
    );
    // Restore BP & RS settings
    actlr = ((actlr & PFB_ACTLR_CLR_MASK) | bp_old | rsdis_old | deolp_old);
#if PFB_ACTLR_DEBUG
    g_enpfb_af_actlr_set = actlr;
#endif

    // Write settings to Auxiliary Control Register
    __asm__ __volatile__
    (
        "MCR p15,0,%0,c1,c0,1\r\n"
        :
        :"r"(actlr)
    );

#if PFB_ACTLR_DEBUG
    // Read settins again
    __asm__ __volatile__
    (
        "MRC p15,0,%0,c1,c0,1\r\n"
        :"=r"(g_enpfb_af_actlr)
        :
    );
#endif

#elif (defined(MT6595) || defined(MT6752)) // MT6595 || MT6752

    if (cp15_is_icache_enabled()) {
        __asm__ __volatile__
        (
            "ISB\r\n"
        );

        PDN_CLR(PDN_PFB);
        DRV_WriteReg32_NPW(MD_MCU2EMI_CON0, DRV_Reg32(MD_MCU2EMI_CON0) | 0x00000005);

        __asm__ __volatile__
        (
            "DSB\r\n"
            "ISB\r\n"
        );
    }

#endif // end of MT6290 & MT6595
}

/*************************************************************************
* FUNCTION
*  disablePrefetchBuffer
*
* DESCRIPTION
*  Disable instruction prefetch buffer.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
#if defined(__MTK_TARGET__)
DEVDRV_LS_INTSRAM_ROCODE void disablePrefetchBuffer(void)
#else
void disablePrefetchBuffer(void)
#endif
{
#if defined(DCM_ENABLE)
    DCM_MCUBUS_DCM_OFF(1);
#endif /* DCM_ENABLE */

#ifdef MT6290
    volatile kal_uint32 start_cycle = 0, current_cycle = 0, duration = 0;
    volatile kal_uint32 actlr = 0, bp_old = 0, rsdis_old = 0, deolp_old = 0;

    /* Disable CR4 branch prediction (bit[16:15]) and return stack (bit[17]) */
    // Read from Auxiliary Control Register
    __asm__ __volatile__
    (
        "DSB\r\n"
        "MRC p15,0,%0,c1,c0,1\r\n"
        :"=r"(actlr)
    );
#if PFB_ACTLR_DEBUG
    g_dispfb_be_actlr_old = actlr;
#endif
    bp_old = actlr & PFB_ACTLR_BP_MASK;                                 // backup BP
    rsdis_old = actlr & PFB_ACTLR_RSDIS_MASK;                           // backup RSDIS
    deolp_old = actlr & PFB_ACTLR_DEOLP_MASK;                           // backup DEOLP
    // Set BP to not taken and return stack to disabled
    actlr = ((actlr & PFB_ACTLR_CLR_MASK) | PFB_ACTLR_BP_NOT_TAKEN | PFB_ACTLR_RS_DISABLE | PFB_ACTLR_OLP_DISABLE);
#if PFB_ACTLR_DEBUG
    g_dispfb_be_bp_old = bp_old;
    g_dispfb_be_rsdis_old = rsdis_old;
    g_dispfb_be_deolp_old = deolp_old;
    g_dispfb_be_actlr_set = actlr;
#endif

    // Write settings to Auxiliary Control Register
    __asm__ __volatile__
    (
        "MCR p15,0,%0,c1,c0,1\r\n"
        "ISB\r\n"
        :
        :"r"(actlr)
    );

#if PFB_ACTLR_DEBUG
    // Read settins again
    __asm__ __volatile__
    (
        "MRC p15,0,%0,c1,c0,1\r\n"
        :"=r"(g_dispfb_be_actlr)
        :
    );
#endif

    /*
     * Wait for 2us.
     *
     * [ WHY 2us ]
     *     In MT6290, EMI busy latency is 200 ~ 300 ns.
     *     We use a safer value of 2us.
     */
    g_dispfb_delay_count = 0;
    GET_CURRENT_TIME(start_cycle);
    do {
        GET_CURRENT_TIME(current_cycle);
        GET_DURATION(duration,start_cycle,current_cycle);
        g_dispfb_delay_count++;
    } while (((3 * CPU_CLOCK_MHZ) > duration) && (g_dispfb_delay_count < CPU_CLOCK_MHZ));

    DRV_WriteReg32_NPW(REG_PFB_CTRL, DRV_Reg32(REG_PFB_CTRL) & (~0x00000004));	// Switch Bus to EMI first
    DRV_WriteReg32_NPW(REG_PFB_CTRL, DRV_Reg32(REG_PFB_CTRL) & (~0x00000001));	// Disable PFB

    /* According to backup value to enable CR4 branch prediction (bit[16:15]) and return stack (bit[17]) */
    // Read from Auxiliary Control Register
    __asm__ __volatile__
    (
        "ISB\r\n"
        "MRC p15,0,%0,c1,c0,1\r\n"
        :"=r"(actlr)
    );
    // Restore BP & RS settings
    actlr = ((actlr & PFB_ACTLR_CLR_MASK) | bp_old | rsdis_old | deolp_old);
#if PFB_ACTLR_DEBUG
    g_dispfb_af_actlr_set = actlr;
#endif

    // Write settings to Auxiliary Control Register
    __asm__ __volatile__
    (
        "MCR p15,0,%0,c1,c0,1\r\n"
        :
        :"r"(actlr)
    );

#if PFB_ACTLR_DEBUG
    // Read settins again
    __asm__ __volatile__
    (
        "MRC p15,0,%0,c1,c0,1\r\n"
        :"=r"(g_dispfb_af_actlr)
        :
    );
#endif

#elif (defined(MT6595) || defined(MT6752))

    DRV_WriteReg32_NPW(MD_MCU2EMI_CON0, DRV_Reg32(MD_MCU2EMI_CON0) & ~0x00000005);
    while( !(DRV_Reg32(MD_MCU2EMI_STATUS0) & 0x00000001) )  ;
    __asm__ __volatile__
    (
        "ISB\r\n"
    );
    while( (DRV_Reg32(MD_MCU2EMI_STATUS0) & 0x10000000) > 0 )  ;
    while( (DRV_Reg32(MD_MCU2EMI_STATUS0) & 0x04000000) > 0 )  ;
    __asm__ __volatile__
    (
        "ISB\r\n"
    );
    PDN_SET(PDN_PFB);

#endif

#if defined(DCM_ENABLE)
    DCM_MCUBUS_DCM_OFF(0);
#endif /* DCM_ENABLE */
}

/*************************************************************************
* FUNCTION
*  drv_pfb_cnt_enable
*
* DESCRIPTION
*  Enable the counting of instruction prefetch buffer.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void drv_pfb_cnt_enable(void)
{
#ifdef MT6290

    DRV_WriteReg32_NPW(REG_PFB_CTRL, DRV_Reg32(REG_PFB_CTRL) | (0x00000002));

#elif (defined(MT6595) || defined(MT6752))

    DRV_WriteReg32_NPW(MD_MCU2EMI_CON0, DRV_Reg32(MD_MCU2EMI_CON0) | (0x00000002));

#endif
}

/*************************************************************************
* FUNCTION
*  drv_pfb_cnt_disable
*
* DESCRIPTION
*  Disable the counting of instruction prefetch buffer.
*
* CALLS
*
* CALL BY
** PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void drv_pfb_cnt_disable(void)
{
#ifdef MT6290

    DRV_WriteReg32_NPW(REG_PFB_CTRL, DRV_Reg32(REG_PFB_CTRL) & (~0x00000002));

#elif (defined(MT6595) || defined(MT6752))

    DRV_WriteReg32_NPW(MD_MCU2EMI_CON0, DRV_Reg32(MD_MCU2EMI_CON0) & (~0x00000002));

#endif
}

/*************************************************************************
* FUNCTION
*  drv_pfb_get_cnt
*
* DESCRIPTION
*  Get the counter of instruction prefetch buffer.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  FPB counter
*
*************************************************************************/
kal_uint32 drv_pfb_get_cnt(void)
{
#ifdef MT6290
    return DRV_Reg32(REG_PFB_TOTAL_CNT);
#elif (defined(MT6595) || defined(MT6752))
    return DRV_Reg32(MD_PFBUFFER_STATUS2);
#else
    return 0;
#endif
}

