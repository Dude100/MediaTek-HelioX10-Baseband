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
 ****************************************************************************/

/*****************************************************************************
 * Filename:
 * ---------
 *   pll_mt6752_md1.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   PLL Related Functions
 *
 * Author:
 * -------
 * -------
 *
 * ===========================================================================
 * $Log$
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
 * Merging from //MOLY/Development_BRANCHES/MT6752E1_BRING_UP_DEV/mcu/driver/devdrv/pll/...
 *
 * removed!
 * removed!
 * Fix SIM CLK from typo
 *
 * removed!
 * removed!
 * Switch LTEDSP from 26M to LTEDSPPLL
 *
 * removed!
 * removed!
 *
 ****************************************************************************/

/*****************************************************************************
 * Locally Used Options
 ****************************************************************************/

/*****************************************************************************
 * Include header files
 ****************************************************************************/

#include "pll.h"
#include "kal_general_types.h"
#include "reg_base.h"

#ifdef __MTK_TARGET__ /* should NOT be compiled on MODIS */

/*****************************************************************************
 * Locally Used Macro Function
 ****************************************************************************/
#define PLL_REG32(addr)   *(volatile kal_uint32 *)(addr)

/*****************************************************************************
 * FUNCTION
 *  INT_SetPLL
 *
 * DESCRIPTION
 *  This function dedicates for PLL setting.
 *
 * PARAMETERS
 *  Init mode of PLL
 *
 * RETURNS
 *
 ****************************************************************************/
#define BUS2X_SSC_FROM_CR4PLL       0  // Whether to Enable CR4PLL for BUS SSC
#define MISC_SETTING                1  // Additional MDCONFIG Settings

void mon_counter_set(unsigned int event0, unsigned int event1, unsigned int event2, unsigned int divide)
{
    int value;

	if (1==divide)
	{
		__asm__ __volatile__
	    (
	       "mrc p15, 0, %0, c9, c12, 0\r\n"
	       "orr %0, %0, #0x0F\r\n"
	       "mcr p15, 0, %0, c9, c12, 0\r\n"
	       :"=r"(value)
	       :
	    );
	}
	else
	{
		__asm__ __volatile__
	    (
	       "mrc p15, 0, %0, c9, c12, 0\r\n"
	       "bic %0, %0, #0x0F\r\n"
	       "orr %0, %0, #0x07\r\n"
	       "mcr p15, 0, %0, c9, c12, 0\r\n"
	       :"=r"(value)
	       :
	    );
	}

    // Select Counter 0, and Select Event
    __asm__ __volatile__
    (
       "mrc p15, 0, %0, c9, c12, 5\r\n"
       "bic %0, %0, #0x1F\r\n"
       "orr %0, %0, #0x00\r\n"
       "mcr p15, 0, %0, c9, c12, 5\r\n"
       "mrc p15, 0, %0, c9, c13, 1\r\n"
       "bic %0, %0, #0xFF\r\n"
       "orr %0, %0, %1\r\n"
       "mcr p15, 0, %0, c9, c13, 1\r\n"
       :
       :"r"(value), "r"(event0)
    );

    // Select Counter 1, and Select Event
    __asm__ __volatile__
    (
       "mrc p15, 0, %0, c9, c12, 5\r\n"
       "bic %0, %0, #0x1F\r\n"
       "orr %0, %0, #0x01\r\n"
       "mcr p15, 0, %0, c9, c12, 5\r\n"
       "mrc p15, 0, %0, c9, c13, 1\r\n"
       "bic %0, %0, #0xFF\r\n"
       "orr %0, %0, %1\r\n"
       "mcr p15, 0, %0, c9, c13, 1\r\n"
       :
       :"r"(value), "r"(event1)
    );

    // Select Counter 2, and Select Event
    __asm__ __volatile__
    (
       "mrc p15, 0, %0, c9, c12, 5\r\n"
       "bic %0, %0, #0x1F\r\n"
       "orr %0, %0, #0x02\r\n"
       "mcr p15, 0, %0, c9, c12, 5\r\n"
       "mrc p15, 0, %0, c9, c13, 1\r\n"
       "bic %0, %0, #0xFF\r\n"
       "orr %0, %0, %1\r\n"
       "mcr p15, 0, %0, c9, c13, 1\r\n"
       :
       :"r"(value), "r"(event2)
    );
}

void mon_counter_start(void)
{
    // Enable all counters (local bits)
    int value = 0, tmp;

	tmp = 0x80000007;

    __asm__ __volatile__
    (
       "mrc p15, 0, %0, c9, c12, 1\r\n"
       "orr %0, %0, %1\r\n"
       "mcr p15, 0, %0, c9, c12, 1\r\n"
       :
       :"r"(value), "r"(tmp)
    );
}

void mon_counter_stop(void)
{
    unsigned int tmp;
    int value = 0;

	tmp = 0x80000007;

    // Disable all counters (local bits)
    __asm__ __volatile__
    (
       "mrc p15, 0, %0, c9, c12, 2\r\n"
       "orr %0, %0, %1\r\n"
       "mcr p15, 0, %0, c9, c12, 2\r\n"
       :
       :"r"(value), "r"(tmp)
    );
}

kal_uint32 mon_counter_cycle_value(void)
{
	unsigned int counter;

	// Read Cycle Counter Register
    __asm__ __volatile__
    (
       "mrc p15, 0, %0, c9, c13, 0\r\n"
       :"=r"(counter)
       :
    );

	return counter;
}


#define PLL_CPU_CLOCK_MHZ               26  // Default run on 26MHz XTAL
static void wait_usec(unsigned int usec)
{
	unsigned int count_wait_for = usec * (PLL_CPU_CLOCK_MHZ);

    mon_counter_set(0, 0, 0, 0);
    mon_counter_start();

    while (mon_counter_cycle_value() <= count_wait_for);

    mon_counter_stop();
}

#if defined(__SGLTE__) || defined(__DUAL_TALK_SUPPORT__)
static void wait_usec_cpu_clock_at_phase2(const unsigned int usec)
{
    // DO NOT START & STOP PMU CYCLE COUNTER at this stage, since OTHER MODULES USE
    // CYCLE COUNTER!
    kal_uint32 beg, end, dur;
    beg = mon_counter_cycle_value();
    dur = 0;

    while (dur <= usec * (CPU_CLOCK_MHZ)) {
        end = mon_counter_cycle_value();
        dur = ((end) >= (beg)) ? ((end) - (beg)) : (0xffffffff - (beg) + (end));
    }
}
#endif

void INT_SetPLL(pll_init_mode mode)
{
    // First Porting from 6595 HVT
    PLL_REG32(PLL_PLL_RESERVE_REG)              = 0x0001;     // Bit 2: Autoswitch bus clk to 26M as PLL off
                                                              // Bit 0: FHC_HW_MODE

    wait_usec(1);

    // Config DPM
    PLL_REG32(PLL_DPM_SEL_SW_CTL0)             &= 0xFFF0;
    PLL_REG32(PLL_DPM_SEL_SW_CTL0)             |= 0x0005; // CLK source from CR4PLL2
    PLL_REG32(PLL_DPM_SEL_SW_CTL0)             |= 0x0008;
    PLL_REG32(PLL_DPM_SEL_SW_CTL0)             |= 0x0080;     // Set fd216_clk_sel_sw_own for dpm & clksw mismatch

    PLL_REG32(PLL_PLLTD_CON8)                  &= 0x000f;
    PLL_REG32(PLL_PLLTD_CON8)                  |= 0x0040;     // Set Bit 4~10 (S7_STB_TIME) to 4(125us)

    PLL_REG32(PLL_DFS_CON7)                     = 0x01FF;     // [FORCE ON] bit 0~8 set to 1 to force all PLLs on
    PLL_REG32(PLL_PLL_CON3)                     = 0x0000;     // [POWER OFF]
    PLL_REG32(PLL_PLL_MTCMOS_CON0)              = 0x0000;     // [POWER OFF]
    PLL_REG32(PLL_PLL_CON2)                     = 0x0000;     // [TOPSM & SW CTRL] bit 0/4/8/12 (WHPLL/WPLL/MCUPLL/MDPLL) set to 0 to enable TOPSM control
    PLL_REG32(PLL_PLL_CON2_1)                   = 0x0000;     // [TOPSM & SW CTRL] bit 0/4/8/12 (OGTWPLL/TDPLL/ARM7PLL/CR4PLL2) set to 0 to enable TOPSM control
    PLL_REG32(PLL_PLLTD_CON0)                   = 0x0000;     // [FHCTL & SW CTRL] bit 0 set to 0 to enable automation delay control, bit 4 set to 0 to set MCUPLL control by FHCTL

    PLL_REG32(PLL_PLL_CON4)                     = 0x0013;     // Bit 4: LTE_DCXO_FORCE_ON  => set 1
                                                              // Bit 3: OGT_BP_PLL_DLY  => set 0
                                                              // Bit 2: OGT_CLKSQ_EN_SEL  => set 0
                                                              // Bit 1: RG_OGT_CLKSQ_EN   =>  keep 1
                                                              // Bit 0: OGT_DCXO_FORCE_ON   => set 1

    #if defined(__SGLTE__) || defined(__DUAL_TALK_SUPPORT__) // SGLTE
        PLL_REG32(PLL_MD_DUAL_TALK)             |= 0x0001;     // Bit 0: REG_DUAL_TALK  // 2G + 4G

        // Enble 1st RF only (2nd RF enable on phase 2 for PMIC/TDPLL issue)
        #if defined(__UMTS_FDD_MODE__)
        PLL_REG32(PLL_MD_SRCLKEN_CTL0)          = 0x0027;
        PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x0005;
        #elif defined(__UMTS_TDD128_MODE__)
        PLL_REG32(PLL_MD_SRCLKEN_CTL0)          = 0x002B;
        PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x0009;
        #else
            #error "Undefined Product Type. Error Code: PLL0001"
        #endif

        // Set TOPSM Request of 2G and TDD Clock to sw own and set to 0 (masked)
        PLL_REG32(PLL_MD_MDTOPSM_SW_CTL)          = 0x0060; // Set bit 6 rg_mdtopsm_tdd_mixedclk_req_sw_own (MDTOPSM TDD)
                                                            //     bit 5 rg_mdtopsm_tdma_mixedclk_req_sw_own (MDTOPSM 2G)

        PLL_REG32(PLL_MD_MODEMTOPSM_SW_CTL)       = 0x0040; // Set bit 5 rg_tdd_topsm_clken_req_sw_own (TDD TOPSM)
        PLL_REG32(PLL_MD_M2GTOPSM_SW_CTL)         = 0x0009; // Set bit 3 rg_modem2_x16gclk_req_sw_own (2G TOPSM x16g)
                                                          ; //     bit 0 rg_modem2_sysclk_req_sw_oen (2G TOPSM system clock, i.e., 26M)
    #elif defined(__DUAL_MODEM_SUPPORT__) // DSDA
        #if defined(__UMTS_FDD_MODE__) || defined(__FLAVOR_BASIC__)
        PLL_REG32(PLL_MD_SRCLKEN_CTL0)          = 0x0027;
        PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x0007;
        #elif defined(__UMTS_TDD128_MODE__)
        PLL_REG32(PLL_MD_SRCLKEN_CTL0)          = 0x002B;
        PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x000B;
        #else
            #error "Undefined Product Type. Error Code: PLL0002"
        #endif
    #else   // CSFB
        #if defined(__UMTS_FDD_MODE__) || defined(__FLAVOR_BASIC__)
        PLL_REG32(PLL_MD_SRCLKEN_CTL0)          = 0x0727;
        PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x0007;
        #elif defined(__UMTS_TDD128_MODE__)
        PLL_REG32(PLL_MD_SRCLKEN_CTL0)          = 0x0B2B;
        PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x000B;
        #else
            #error "Undefined Product Type. Error Code: PLL0003"
        #endif
    #endif // DUAL_TALK_OFF

    #if BUS2X_SSC_FROM_CR4PLL
    // Set DPM to Match BUS2X CLKSW Settings
    PLL_REG32(PLL_DPM_SEL_SW_CTL1)             &= 0xF0FF;
    PLL_REG32(PLL_DPM_SEL_SW_CTL1)             |= 0x0100;     // CLK source from CR4PLL
    PLL_REG32(PLL_DPM_SEL_SW_CTL1)             |= 0x0800;
    #endif

    /* Enable PLLs */
    PLL_REG32(PLL_MDPLL_CON0)                  |= 0x8000;     // Bit 15: MDPLL_EN
    PLL_REG32(PLL_MCUPLL_CON0)                 |= 0x8000;     // Bit 15: MCUPLL_EN
    PLL_REG32(PLL_WPLL_CON0)                   |= 0x8000;     // Bit 15: WPLL_EN
    PLL_REG32(PLL_WHPLL_CON0)                  |= 0x8000;     // Bit 15: WHPLL_EN
    //Disable TDPLL for PMIC/TDPLL issue (enable at phase 2)
    //PLL_REG32(PLL_TDPLL_CON0)                  |= 0x8000;     // Bit 15: TDPLL_EN
    PLL_REG32(PLL_OGTWPLL_CON0)                |= 0x8000;     // Bit 15: OGTWPLL_EN
    PLL_REG32(PLL_ARM7PLL_CON0)                |= 0x8000;     // Bit 15: LTEDSPPLL_EN

    /* CR4 DIV MACRO CONTROL */
    wait_usec(5);
    PLL_REG32(PLL_MD_CR4PLL_DIV_CON)           |= 0x0002;     // Bit 1: MCUPLL DIV MACRO, pll_clk_en 1

    wait_usec(23);
    PLL_REG32(PLL_MD_CR4PLL_DIV_CON)           |= 0x0020;     // Bit 5: MCUPLL DIV MACRO, RESET release

    wait_usec(6);
    PLL_REG32(PLL_MD_CR4PLL_DIV_CON)           |= 0x5000;     // Bit 12,14: MCUPLL DIV MACRO, cg enable

    /* Frequency Hopping */
    wait_usec(6);
    PLL_REG32(PLL_PLLTD_CON0)                   = 0x0000;     // [FHCTL & SW CTRL]   ==> <GH> Set PLL POR Sequence controlled by HW

    // LTEDSPPLL (300 MHz) Hopping Setting
    //PLL_REG32(PLL_FH_CON8_1)                     =  0x0070; // DOWN Hopping 8%
    //PLL_REG32(PLL_FH_CON8)                       =  0xA454; // FREE RUN MODE

    // CR4PLL2 (800MHz => Actually 800MHz) Hopping Setting (Need Check)
    //PLL_REG32(PLL_FH_CON_CR4PLL2_1)             = 0x009C; // Down Hopping 8%
    //PLL_REG32(PLL_FH_CON_CR4PLL2)               = 0xA454; // FREE RUN MODE

    #if BUS2X_SSC_FROM_CR4PLL
    // CR4PLL (600 MHz) Hopping Setting // By Adder @ 2014/3/12
    PLL_REG32(PLL_FH_CON5)                      =  0x008A; // DOWN Hopping 5%
    PLL_REG32(PLL_FH_CON4)                      =  0xA454; // FREE RUN MODE
    #endif

    /* CR4 DIV MACRO CONTROL - release to topsm */
    PLL_REG32(PLL_MD_CR4PLL_DIV_CON)           &= 0xFEEE; // Bit 8/4/0: Bypass Dly = 0, RSTB SEL = 0, Out Enable Sel = 0
                                                           // ==> <GH> Check

    wait_usec(60);
    PLL_REG32(PLL_MDPLL_CON0)                  &= 0x7FFF; // Bit 15: Disable MDPLL
    PLL_REG32(PLL_MDPLL_CON4)                  &= 0xFFFE; // Bit 0: Disable MDPLL AUTOK
    //PLL_REG32(PLL_TDPLL_CON0)                  &= 0x7FFF; // Bit 15: Disable TDPLL
    //PLL_REG32(PLL_TDPLL_CON4)                  &= 0xFFFE; // Bit 0: Disable TDPLL AUTOK

    wait_usec(1);
    PLL_REG32(PLL_MDPLL_CON0)                  |= 0x8000; // Bit 15: Enable MDPLL
    //PLL_REG32(PLL_TDPLL_CON0)                  |= 0x8000; // Bit 15: Enable TDPLL

    wait_usec(15);

    PLL_REG32(PLL_CLKSW_FDIV7)                  = 0xC100; // // Bit  14/8: Disable Consys Access, Bit 15: Unused

    PLL_REG32(PLL_MD_GLOBAL_CON1)              |= 0x20000000; // Bit 29: Set ghmdbus div2
                                                              // Maggie in represent of Ethan ==> Clock / 2


    // Switch MDMCU_CLK from 26MHz to WPLL = 491.52 MHz, and DSP_CLK (GDSP) from 26MHz to WPLL/2 = 491.52/2 = 245.76 MHz
    PLL_REG32(PLL_CLKSW_CKSEL0)                 = 0x2040;

    // Switch FX64W_CLK(TDD/FDD) to WPLL = 245.76 MHz, and FX16G_CLK(FDD/TDD/2G) from 26MHz to MDPLL/2 = 208 MHz, and HX64W_CLK to WPLL/2 = 245.76 MHz
    PLL_REG32(PLL_CLKSW_CKSEL2)                 = 0x6F20;

    // CR4 800M Patch
    // 1. Switch MDMCU_CLK to WPLL
    PLL_REG32(PLL_CLKSW_CKSEL3)                 = 0x0141;  // Bit 6~4: MDMCU_CK => WPLL
                                                           // Bit 1: WHPLL_D1_CLKEN div1 & div2: not used, clear
                                                           // Bit 0: WPLL_D1_CLKEN div1 & div2: must ebabled


    // 2. Enable GDMA CG
    PLL_REG32(PLL_MD_GLOBAL_CLR0)                |= 0x0001;

    #define MT6752_MD1_PLL_ASM_MARKER(sym) do { __asm__ __volatile__ (".global " #sym ";\n" #sym ":\n"); } while(0)
    /* 13*(INT+FRC/2^14) */
    #if defined(MCU_646M)
    PLL_REG32(PLL_CR4PLL2_CON2)                  &= 0xff80;
    PLL_REG32(PLL_CR4PLL2_CON2)                  |= 0x0031; /* INT */
    PLL_REG32(PLL_CR4PLL2_CON3)                   = 0x2c4e; /* FRC */
    MT6752_MD1_PLL_ASM_MARKER(CR4PLL2_646);
    #elif defined(MCU_600M)
    PLL_REG32(PLL_CR4PLL2_CON2)                  &= 0xff80;
    PLL_REG32(PLL_CR4PLL2_CON2)                  |= 0x002e;
    PLL_REG32(PLL_CR4PLL2_CON3)                   = 0x09D8;
    MT6752_MD1_PLL_ASM_MARKER(CR4PLL2_600);
    #elif defined(MCU_570M)
    PLL_REG32(PLL_CR4PLL2_CON2)                  &= 0xff80;
    PLL_REG32(PLL_CR4PLL2_CON2)                  |= 0x002b;
    PLL_REG32(PLL_CR4PLL2_CON3)                   = 0x3627;
    MT6752_MD1_PLL_ASM_MARKER(CR4PLL2_570);
    #elif defined(MCU_400M)
    PLL_REG32(PLL_CR4PLL2_CON2)                  &= 0xff80;
    PLL_REG32(PLL_CR4PLL2_CON2)                  |= 0x001e;
    PLL_REG32(PLL_CR4PLL2_CON3)                   = 0x3200;
    MT6752_MD1_PLL_ASM_MARKER(CR4PLL2_400);
    #elif defined(MCU_800M)
    MT6752_MD1_PLL_ASM_MARKER(CR4PLL2_800);
    /* HW default setting, do nothing */
    #else
        #error "Unknown CR4 Clock/CR4PLL2 setting"
    #endif
    #undef MT6752_MD1_PLL_ASM_MARKER

    // 3. Enable CR4PLL2
    PLL_REG32(PLL_CR4PLL2_CON0)                  |= 0x8000;

    // 3.1 Delay for CR4PLL2 to be Stable // 0205 updated
    wait_usec(20);

    // 4. Switch BUS_CLK to CR4PLL/5/2 = 120MHz
    //PLL_REG32(PLL_CLKSW_CKSEL1)                  = 0x8000;

    PLL_REG32(PLL_PLL_CON2)                    |= 0x0010;     // [TOPSM & SW CTRL] Bit 0: WPLL to SW CTRL Mode


    // Switch to CR4PLL2
    PLL_REG32(PLL_CLKSW_CKSEL0)  = (PLL_REG32(PLL_CLKSW_CKSEL0) & 0x0fff) | 0x4000; // Bit 15-12: MDMCU_CLK_SEL set to 4

    // 6. Turn on WPLL
    PLL_REG32(PLL_PLLTD_CON4) = 0x0001; // PLL enable dly // 0118 added
    PLL_REG32(PLL_PLL_CON2)   = 0x0000;   // Restore TOPSM Ctrl Effect
    PLL_REG32(PLL_WPLL_CON0)  |= 0x8000;  // Bit 15: WPLL_EN

    wait_usec(20);

    #if BUS2X_SSC_FROM_CR4PLL
    // 7. Switch BUS_CLK to CR4PLL = 600/5 = 120 MHz  // By Adder @ 2014/3/12
    PLL_REG32(PLL_CLKSW_CKSEL1)  = 0x8000;
    #else
    // 7. Switch BUS_CLK to WPLL/4 = 491.52/4 = 122.88 MHz
    PLL_REG32(PLL_CLKSW_CKSEL1)  = 0x2000;  // Also for BUS2X = WHPLL
    #endif

    // Switch ARM7_CLK to LTEDSPPLL = 300 MHz, LTEL2_PHY_CLK to WPLL/4 = 122.88 MHz, LTEL1_AXI_CLK to WPLL = 245.76 MHz
    PLL_REG32(PLL_CLKSW_CKSEL4)                 = 0x4500;

    // Enable LTEL2_PHY_CK and MML1_BUS1X_CLK
    PLL_REG32(PLL_CLKSW_CKSEL6)                 = 0x0003;


    /*
     * Disable Unused PLLs Based on Configs
     */
    PLL_REG32(PLL_PLL_CON2)                    |= 0x0001;     // [TOPSM & SW CTRL] Bit 0: WHPLL to SW CTRL Mode
    PLL_REG32(PLL_WHPLL_CON0)                  &= ~(0x8000);  // Bit 15: WHPLL_EN Set to 0 to Disable WHPLL

    PLL_REG32(PLL_PLL_CON2_1)                  |= 0x0001;     // [TOPSM & SW CTRL], Bit 0: OGTWPLL to SW CTRL Mode
    PLL_REG32(PLL_OGTWPLL_CON0)                &= ~(0x8000);  // Bit 15: OGTWPLL_EN Set to 0 to Disable OGTWPLL

    #if !BUS2X_SSC_FROM_CR4PLL
    PLL_REG32(PLL_PLL_CON2)                    |= 0x0100;     // [TOPSM & SW CTRL], Bit 8: MCUPLL to SW CTRL Mode
    PLL_REG32(PLL_MCUPLL_CON0)                 &= ~(0x8000);  // Bit 15: MCUPLL_EN to Disable MCUPLL (CR4PLL)
    #endif

    // Switch LTEDSP from 26M to LTEDSPPLL (300M)
    PLL_REG32(PLL_CLKSW_CKSEL8)                |= 0x00FF;
    
//    PLL_REG32(PLL_CLKSW_CKSEL5)                |= 0x0010; // csw_phy_fix300m_ck = LTEDSPPLL = 300M

    // Release PLL Force
    PLL_REG32(PLL_DFS_CON7)                     = 0x0000;
    PLL_REG32(PLL_PLL_CON4)                     = 0x0000;

    #if MISC_SETTING
    // Enable Ultra High Request
    PLL_REG32(PLL_MD2EMI_ULTRA_HIGH_SET0) = 0x0007;
    PLL_REG32(PLL_MD2EMI_ULTRA_HIGH_SET1) = 0x0007;
    #endif
}

void INT_SetPLL_Phase2()
{
    // For TDDPLL Init Sequence Correction (Stage 2)
    #if defined(__SGLTE__) || defined(__DUAL_TALK_SUPPORT__)

    // [2] Enable SRCLKEN 2nd RF setting
    #if defined(__UMTS_FDD_MODE__)
    PLL_REG32(PLL_MD_SRCLKEN_CTL0)            = 0x2727;
    #elif defined(__UMTS_TDD128_MODE__)
    PLL_REG32(PLL_MD_SRCLKEN_CTL0)            = 0x2B2B;
    #endif

    // Wait 3000 (avg. xstal to IC at EVB) + 125 (CLKSQ stable) us
    wait_usec_cpu_clock_at_phase2(3125);

    // [3] Enable TDPLL
    PLL_REG32(PLL_TDPLL_CON0)                |= 0x8000;

    // Wait 20 us for TDPLL stable when TDPLL_AUTOK enabled (hw default)
    wait_usec_cpu_clock_at_phase2(20);

    // [4] Resume frow sw control to topsm control
    PLL_REG32(PLL_MD_MDTOPSM_SW_CTL)          = 0x0000;
    PLL_REG32(PLL_MD_MODEMTOPSM_SW_CTL)       = 0x0000;
    PLL_REG32(PLL_MD_M2GTOPSM_SW_CTL)         = 0x0000;
    #endif
}

/*
 * Provide HW POR Control by Request of RF Control Members
 */
void set_hw_por_ctrlmode(hw_por_ctrl_mode mode)
{
    switch (mode)
    {
        case CTRL_MODE_HW:
            #if defined(__SGLTE__) || defined(__DUAL_TALK_SUPPORT__)
                #if defined(__UMTS_FDD_MODE__)
                PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x0005;
                #elif defined(__UMTS_TDD128_MODE__)
                PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x0009;
                #else
                    #error "Undefined Product Type. Error Code: PLL0004"
                #endif
            #else
                #if defined(__UMTS_FDD_MODE__) || defined(__FLAVOR_BASIC__)
                PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x0007;
                #elif defined(__UMTS_TDD128_MODE__)
                PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x000B;
                #else
                    #error "Undefined Product Type. Error Code: PLL0005"
                #endif
            #endif
        break;
        case CTRL_MODE_SW: // Default to be Off
            PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x0000;
        break;
    }
}

void set_hw_por_swctrl(hw_por_swctrl swctrl)
{
    switch (swctrl)
    {
        case SWCTRL_FORCE_OFF:
            PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x0000;
        break;
        case SWCTRL_FORCE_ON:
            PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x0080;
        break;
    }
}

void set_csw_lt1l1_axi_ck(kal_uint32 onoff)
{
    if(onoff == 0 /* off */) {
        /* turn csw_ltel1_axi_ck to 26M when non-lte-mode */
        PLL_REG32(PLL_CLKSW_CKSEL8)          &= (~(1<<7)); /* Clr bit 7 csw_ltel1_axi_ck mux sel to 0(26M) */
        PLL_REG32(PLL_CLKSW_CKSEL7)          |=   (1<<1);  /* Set bit 1 LTEL1_BUS_CK_DIS to disable(1) bus ltel1 clock */
    } else if(onoff == 1 /* on */) {
        /* turn csw_ltel1_axi_ck back to PLL when lte-mode */
        PLL_REG32(PLL_CLKSW_CKSEL7)          &= (~(1<<1)); /* Clr bit 1 LTEL1_BUS_CK_DIS to enable(0) bus ltel1 clock */
        PLL_REG32(PLL_CLKSW_CKSEL8)          |=   (1<<7);  /* Set bit 7 csw_ltel1_axi_ck mux sel to 1(PLL) */
    }
}

#endif /* __MTK_TARGET__ --- should NOT be compiled on MODIS */
