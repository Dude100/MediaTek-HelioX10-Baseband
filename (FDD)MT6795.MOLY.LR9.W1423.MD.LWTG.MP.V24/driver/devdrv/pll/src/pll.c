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
 *   pll.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   PLL Related Functions
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * Merging from //MOLY/Development_BRANCHES/MT6752E1_BRING_UP_DEV/mcu/driver/devdrv/pll/...
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * Merging from CL#585195
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * Merging from CL#578502
 *
 * removed!
 * removed!
 * force PLL E1 setting
 *
 * removed!
 * removed!
 * Update clock switch setting
 *
 * removed!
 * removed!
 * Add phase2 dummy function for build error
 *
 * removed!
 * removed!
 * Temporary fix build error (empty function)
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
 * [MT6595][SYSTEM SERVICE][PLL] Config srclken1 to control RF1 power
 *
 * Merging
 *
 * //MOLY_CBr/yuyang.hsiao/MOLY_W14.20.LTE.p1.VRF18HwCtrlbySrclkenO1/mcu/driver/devdrv/pll/src/pll.c
 *
 * to //MOLY/TRUNK/MOLY/mcu/driver/devdrv/pll/src/pll.c
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * [MT6595][SYSTEM SERVICE] Disable PWB, besides, PWB should not init at PLL
 *
 * removed!
 * removed!
 *
 * Merging
 *
 * //MOLY_CBr/yuyang.hsiao/MOLY_W14.12.LTE.p2.HwporSwCtrl/mcu/driver/devdrv/pll/...
 *
 * to //MOLY/TRUNK/MOLY/mcu/driver/devdrv/pll/...
 *
 * removed!
 * removed!
 *
 * Fix build error
 *
 * removed!
 * removed!
 *
 * [MT6589][SYSTEM SERVICE] MT6589 PLL driver porting from W1301
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
 * Update SRCLKEN Settings By SA's Request
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
 *
 ****************************************************************************/


/*******************************************************************************
 * Locally Used Options
 *******************************************************************************/
#define PLL_FOR_FPGA    __FPGA__    /* 0: For ASIC,  1: For FPGA */

#ifdef __DOWNLOAD_AGENT__
#define PLL_FOR_MOLY    0           /* 0: For DA,    1: For MOLY */
#else
#define PLL_FOR_MOLY    1           /* 0: For DA,    1: For MOLY */
#endif


/*******************************************************************************
 * Include header files
 *******************************************************************************/

#if defined(MT6290)
    #if PLL_FOR_MOLY

    #include "kal_general_types.h"
    #include "reg_base.h"
    #include "pll.h"

    #define MODEM_TYPE              0xBF800058

    #else

    #define MDCLKCTL_CR4PLL_CTL     0xBF81030C
    #define APCLKCTL_CA7PLL_CTL     0xBF898304
    #define MDCLKCTL_ARM7PLL_CTL    0xBF810308
    #define MDCLKCTL_LTEWHPLL_CTL   0xBF810324
    #define MDCLKCTL_CLKSRCSEL0     0xBF810008
    #define MDCLKCTL_CLKSRCSEL1     0xBF81000C
    #define APCLKCTL_CLKSRCSEL2     0xBF898010
    #define APCLKCTL_CLKSPDCTL      0xBF898014
    #define MDCLKCTL_CLKSPDCTL      0xBF810014
    #define MDCLKCTL_CLKSWCCTL      0xBF810020
    #define MDCLKCTL_SRCLKEN_CTL    0xBF810024
    #define APCLKCTL_MSDCPLL_CTL    0xBF898318
    #define MDCLKCTL_APCLKONCTL     0xBF81001C
    #define APCLKCTL_MDCLKONCTL     0xBF898018
    #define MDCLKCTL_DUMMY          0xBF811000
    #define MDCLKCTL_LTEPLL_CTL0    0xBF810330
    #define MDCLKCTL_LTEPLL_CTL1    0xBF810334

    #define MODEM_TYPE              0xBF800058
    #define MDCLKCTL_RING_OSC_CTL   0xBF810100

    typedef unsigned int kal_uint32;

    #endif

#elif defined(MT6595)
    #include "kal_general_types.h"
    #include "reg_base.h"
    #include "pll.h"
    #include "sync_data.h"
    #include "devdrv_ls.h"
#endif

#ifdef __MTK_TARGET__ /* should NOT be compiled on MODIS */

/*******************************************************************************
 * Locally Used Macro Function
 *******************************************************************************/
#define PLL_REG32(addr)   *(volatile kal_uint32 *)(addr)


/*************************************************************************
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
*************************************************************************/
#if defined(MT6290)
#if PLL_FOR_MOLY
void INT_SetPLL(pll_init_mode mode)
#else
void INT_SetPLL()
#endif
{
#if PLL_FOR_FPGA
    // Do Not Conduct Special Settings for FPGA

#else
    // Tune CR4PLL to 570MHz. This Also Cause Bus2X to 114MHz and Bus1X to 57MHz.
    PLL_REG32(MDCLKCTL_CR4PLL_CTL) = 0x920AF627;

    // Tune CA7PLL to 600MHz
    PLL_REG32(APCLKCTL_CA7PLL_CTL) = 0x920B89D8;

    #if defined(MT6290_S00)
    // Tune ARM7PLL to 260MHz
    PLL_REG32(MDCLKCTL_ARM7PLL_CTL) = 0x940A0000;
    #endif

    // Tune MSDCPLL to 200MHz
    PLL_REG32(APCLKCTL_MSDCPLL_CTL) = 0x960F6276;

    #if defined(MT6290_S00)
    // Tune LTEWHPLL POSDIV by Designer Request
    PLL_REG32(MDCLKCTL_LTEWHPLL_CTL) = 0x9609A000;
    #endif

    // Tune LTEPHY to ARM7PLL/1 (E1:260MHz, E2:300MHz), BUS2X to DSPPLL/2 (120MHz), and ARM7 to ARM7PLL/1 (E1:260MHz, E2:300MHz)
    PLL_REG32(MDCLKCTL_CLKSRCSEL0) = 0x02130200;

    // Tune BSISPI to DSPPLL/2 (120MHz), TRACE to UNIVPLL/5 (130MHz), TDDSYS to ISPPLL/1 (288MHz), and GDSP to DSPPLL/1 (240MHz)
    PLL_REG32(MDCLKCTL_CLKSRCSEL1) = 0x13460503;

    // Tune MSDC0 and MSDC1 to MSDCPLL/1 (200MHz)
    PLL_REG32(APCLKCTL_CLKSRCSEL2) = 0x00040400;

    // Tune SPI PLL Divisor to CR4PLL/20
    PLL_REG32(MDCLKCTL_CLKSPDCTL) = 0x0000008B;

    // Tune CR4 from CR4PLL/2 (570/2 MHz) to CR4PLL (570MHz), 32K Source to ABB
    // Tune MODEM Clocks from XTAL to PLL and SPI Clock from XTAL/2 to CR4PLL/20
    PLL_REG32(MDCLKCTL_CLKSWCCTL) = 0x000000FF;

    //
    // Tune LTEPLL to Normal Mode to Save Power by ACD Designer's Request
    //
    PLL_REG32(MDCLKCTL_DUMMY) = 0x0001FFFF;
    while (PLL_REG32(MDCLKCTL_STATUS_5) & 0x100);
    PLL_REG32(MDCLKCTL_LTEPLL_CTL0) = 0xD808011E;
    PLL_REG32(MDCLKCTL_LTEPLL_CTL1) = 0x1C184007;
    PLL_REG32(MDCLKCTL_DUMMY) = 0x0000FFFF;
#endif

#if PLL_FOR_FPGA
    // Do Not Conduct Special Settings for FPGA

#else
    #if defined(__SMART_PHONE_MODEM__) && defined(__X_BOOTING__) // Phone Product
        #if defined(__SGLTE__)  || defined(__DUAL_TALK_SUPPORT__) // Dual-Talk
            //#if defined(__UMTS_FDD_MODE__)
            //PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x00052727;
            //#elif defined(__UMTS_TDD128_MODE__)
            //PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x00092B2B;
            //#else
            //    #error "Undefined Product Type. Error Code: PLL0001"
            //#endif

            #if 1 // For TDDPLL Init Sequence Correction (Stage 1)
                // Apply Dual-Talk Settings, But Turn Off 2nd RF Clock Buffer
                #if defined(__UMTS_FDD_MODE__)
                PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x00050027;
                #elif defined(__UMTS_TDD128_MODE__)
                PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x0009002B;
                #else
                    #error "Undefined Product Type. Error Code: PLL0001"
                #endif
            #endif
        #else // CSFB
            #if defined(MT6290_DEMO_BB) || defined(MT6290M_DEMO_BB) || defined(MT6290E2_EVB) || defined(MT6290ME2_EVB) // EVB
                #if defined(__UMTS_FDD_MODE__)
                PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x00070727;
                #elif defined(__UMTS_TDD128_MODE__)
                PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x000B0B2B;
                #else
                    #error "Undefined Product Type. Error Code: PLL0002-1"
                #endif
            #else // PDB
                #if defined(__UMTS_FDD_MODE__)
                PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x00070027;
                #elif defined(__UMTS_TDD128_MODE__)
                PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x000B002B;
                #else
                    #error "Undefined Product Type. Error Code: PLL0002-2"
                #endif
            #endif
        #endif
    #elif defined(__SMART_PHONE_MODEM__) && !(defined(__X_BOOTING__)) // Router Product (with AP)
        #if defined(__UMTS_FDD_MODE__)
        PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x10077767;
        #elif defined(__UMTS_TDD128_MODE__)
        PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x100B7B6B;
        #else
            #error "Undefined Product Type. Error Code: PLL0003"
        #endif
    #elif defined(__MODEM_CARD__) && !(defined(__TRADITIONAL_MODEM_CARD__)) // Hosted Dongle (with AP)
        #if defined(__UMTS_FDD_MODE__)
        PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x10077767;
        #elif defined(__UMTS_TDD128_MODE__)
        PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x100B7B6B;
        #else
            #error "Undefined Product Type. Error Code: PLL0004"
        #endif
    #elif defined(__MODEM_CARD__) && defined(__TRADITIONAL_MODEM_CARD__) // Traditional Dongle (w/o AP, but APTOPSM is on)
        #if defined(__UMTS_FDD_MODE__)
        PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x10077767;
        #elif defined(__UMTS_TDD128_MODE__)
        PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x100B7B6B;
        #else
            //#error "Undefined Product Type. Error Code: PLL0005"
            PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x00070727; // For MT6290_LTE(SINGLE_MODE) project
        #endif
    #else
        #error "Undefined Product Type. Error Code: PLL0006"
    #endif

    //#if defined(__SGLTE__)
    //PLL_REG32(MODEM_TYPE) = 0x00000001;
    //#endif

    #if defined(__SMART_PHONE_MODEM__) && !(defined(__X_BOOTING__))  // For Router Product, Requested by Box Wu
    // Tune SPI Clock from CR4PLL/20 to XTAL/2
    PLL_REG32(MDCLKCTL_CLKSWCCTL) = (PLL_REG32(MDCLKCTL_CLKSWCCTL) & (~0x00000002));
    #endif

    // Set Ring OSC's Force Enable Bit to 0, for Non-E1 ICs, by DE - Will Lee's Request
    #if !defined(MT6290_S00)
    PLL_REG32(MDCLKCTL_RING_OSC_CTL) = 0x00000000;
    #endif

    // Note:
    // 1. EMI PLL related settings are taken care by EMI owner
    // 2. TOPSM related settings have been taken care by TOPSM owner. Known settings
    //    - OGT/LTE DCXO Settle Time: PLL_REG32(MDCLKCTL_PLL_DLY_CTL5) = (RM_SYS_CLK_SETTLE << 24) | (RM_SYS_CLK_SETTLE << 16) | 0x023A;
#endif
}

void INT_SetPLL_Phase2()
{
    #if defined(__SGLTE__) || defined(__DUAL_TALK_SUPPORT__) // For TDDPLL Init Sequence Correction (Stage 2)
    // Mask TOPSM Request for 2G and TDD Clock
    PLL_REG32(MDCLKCTL_MDTOPSM_SW_CTL) = 0x180;

    // Mask TOPSM Request for TDD, 2G X16G, 2G 26M
    PLL_REG32(MDCLKCTL_MODEM_TOPSM_SW_CTL) = 0x320;

    // Set Dual Talk Modem Type
    PLL_REG32(MODEM_TYPE) = 0x00000001;

        // Set SRCLKEN Request
        #if defined(__UMTS_FDD_MODE__)
        PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x00052727;
        #elif defined(__UMTS_TDD128_MODE__)
        PLL_REG32(MDCLKCTL_SRCLKEN_CTL) = 0x00092B2B;
        #else
            #error "Undefined Product Type. Error Code: PLL0001"
        #endif

    // Resume TOPSM Request for TDD, 2G X16G, 2G 26M
    PLL_REG32(MDCLKCTL_MODEM_TOPSM_SW_CTL) = 0x0;

    // Resume TOPSM Request for 2G and TDD Clock
    PLL_REG32(MDCLKCTL_MDTOPSM_SW_CTL) = 0x0;
    #endif
}

#elif defined(MT6595)

#include "init.h"

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

//DEVDRV_LS_NONCACHEDZI unsigned setting;

void INT_SetPLL(pll_init_mode mode)
{
    register kal_uint32 mt6595_eco_ver_at_pll = 0;
    if(INT_MT6595_ECO_MAGIC == 0x00) { // E1
        mt6595_eco_ver_at_pll = 0xE1;
    } else {
        mt6595_eco_ver_at_pll = 0xE2;  // E2
    }
    PLL_REG32(PLL_ABIST_FQMTR_CON0)             = mt6595_eco_ver_at_pll; /* use FQMTR_WINSET to save ECO version */

    // First Porting from 6595 HVT
    PLL_REG32(PLL_PLL_RESERVE_REG)              = 0x0001;     // Bit 2: Autoswitch bus clk to 26M as PLL off
                                                              // Bit 0: FHC_HW_MODE

    wait_usec(1);

    if (mt6595_eco_ver_at_pll == 0xE2) {
        PLL_REG32(PLL_DPM_SEL_SW_CTL0)             &= 0xFFF0;
        PLL_REG32(PLL_DPM_SEL_SW_CTL0)             |= 0x0005; // CLK source from CR4PLL2
        PLL_REG32(PLL_DPM_SEL_SW_CTL0)             |= 0x0008;
    }

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

    #if defined(__SGLTE__) || defined(__DUAL_TALK_SUPPORT__)
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
    #else
        #if defined(__UMTS_FDD_MODE__)
        PLL_REG32(PLL_MD_SRCLKEN_CTL0)          = 0x0727;
        PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x0007;
        #elif defined(__UMTS_TDD128_MODE__)
        PLL_REG32(PLL_MD_SRCLKEN_CTL0)          = 0x0B2B;
        PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x000B;
        #else
            #error "Undefined Product Type. Error Code: PLL0002"
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
    PLL_REG32(PLL_CLKSW_CKSEL3)                  = 0x0143;  // Bit 6~4: MDMCU_CK => WPLL

    // 2. Enable GDMA CG
    PLL_REG32(PLL_MD_GLOBAL_CLR0)                |= 0x0001;

    #if defined(MCU_646M)
    PLL_REG32(PLL_CR4PLL2_CON2)                  &= 0xff80;
    PLL_REG32(PLL_CR4PLL2_CON2)                  |= 0x0031;
    PLL_REG32(PLL_CR4PLL2_CON3)                   = 0x2c4e;
    #elif defined(MCU_800M)
    /* HW default setting, do nothing */
    #else
        #error "Unknown CR4 Clock/CR4PLL2 setting"
    #endif

    // 3. Enable CR4PLL2
    PLL_REG32(PLL_CR4PLL2_CON0)                  |= 0x8000;

    // 3.1 Delay for CR4PLL2 to be Stable // 0205 updated
    wait_usec(20);

    // 4. Switch BUS_CLK to CR4PLL/5/2 = 120MHz
    //PLL_REG32(PLL_CLKSW_CKSEL1)                  = 0x8000;

    PLL_REG32(PLL_PLL_CON2)                    |= 0x0010;     // [TOPSM & SW CTRL] Bit 0: WPLL to SW CTRL Mode


    if (mt6595_eco_ver_at_pll == 0xE1) {
        // 5. Set GDMA
        PLL_REG32(PLL_CLKSW_FDIV3) = PLL_REG32(PLL_CLKSW_CKSEL4);
        PLL_REG32(PLL_CLKSW_FDIV4) = PLL_REG32(PLL_CLKSW_CKSEL5) | 0x0020;
        PLL_REG32(PLL_GDMA_FDCSR0) = 0x00000200; // Basic Mode
        PLL_REG32(PLL_GDMA_FDSAR0) = PLL_CLKSW_FDIV3;
        PLL_REG32(PLL_GDMA_FDDAR0) = PLL_CLKSW_CKSEL4;

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
/* under construction !*/
/* under construction !*/
        #endif

        //Data_Mem_Barrier();

        // 5.1 WPLL Turn Off
        //PLL_REG32(PLL_PLL_CON2)   = 0x0010;  // Remove TOPSM Ctrl Effect
        //PLL_REG32(PLL_WPLL_CON0)  = 0x0800;  // Bit 15: WPLL_EN

        PLL_REG32(PLL_GDMA_FDCR0) = (0x8) << 16 | 0x40A1; // Burst 64B, Width 32b (SRC, DST), Start

        PLL_REG32(PLL_WPLL_CON0)                   = 0x0800;     // Bit 15: Turn Off WPLL

        // Wait for GDMA done
        while ((PLL_REG32(PLL_GDMA_FDCSR0) & 0x1) != 0x00000000) {};
    } else { // mt6595_eco_ver_at_pll == 0xE2
        PLL_REG32(PLL_CLKSW_CKSEL0)  = (PLL_REG32(PLL_CLKSW_CKSEL0) & 0x0fff) | 0x4000; // Bit 15-12: MDMCU_CLK_SEL set to 4
    }

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

    // Release PLL Force
    PLL_REG32(PLL_DFS_CON7)                     = 0x0000;
    PLL_REG32(PLL_PLL_CON4)                     = 0x0000;

    #if MISC_SETTING
    /* Pre-fetch Buffer Enable */
    //PLL_REG32(MD_MCU2EMI_CON0) |= 0x1; // Bit 0: PFH_EN

    /* Post Write Buffer Enable */
    //PLL_REG32(PLL_MD_MCU_CON2) |= 0x10000; // Bit 16: PWB_EN

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

    // Wait 5 (avg. xstal to IC at EVB) + 125 (CLKSQ stable) us
    wait_usec_cpu_clock_at_phase2(130);

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
#else
#include "pll.h"

void INT_SetPLL(pll_init_mode mode)
{}

void INT_SetPLL_Phase2()
{}
#endif


#if PLL_FOR_MOLY && defined(MT6290)
void enable_ap_clk()
{
    // Enable APCA7_CGEN
    PLL_REG32(MDCLKCTL_CLKONCTL) = PLL_REG32(MDCLKCTL_CLKONCTL) | 0x80000000;
}

void set_spi_clk_div(spi_clk_div div)
{
    // Tune SPI PLL Divisor to div
    PLL_REG32(MDCLKCTL_CLKSPDCTL) = (PLL_REG32(MDCLKCTL_CLKSPDCTL) & 0xFFFFFFF0) | div;
}

void set_msdc0_clk_div(msdc_clk_pre_div prediv, msdc_clk_post_div postdiv)
{
    // Tune MSDC0 PLL Divisor to (prediv * postdiv)
    PLL_REG32(APCLKCTL_CLKSRCSEL2) = (PLL_REG32(APCLKCTL_CLKSRCSEL2) & 0xFFFF0FFF) | (prediv << 12);
    PLL_REG32(APCLKCTL_CLKSPDCTL) = (PLL_REG32(APCLKCTL_CLKSPDCTL) & 0xFFFFF8FF) | (postdiv << 8);
}

void set_msdc1_clk_div(msdc_clk_pre_div prediv, msdc_clk_post_div postdiv)
{
    // Tune MSDC1 PLL Divisor to (prediv * postdiv)
    PLL_REG32(APCLKCTL_CLKSRCSEL2) = (PLL_REG32(APCLKCTL_CLKSRCSEL2) & 0xFF0FFFFF) | (prediv << 20);
    PLL_REG32(APCLKCTL_CLKSPDCTL) = (PLL_REG32(APCLKCTL_CLKSPDCTL) & 0xFFFFC7FF) | (postdiv << 11);
}

void set_msdc_pll_clock(msdc_pll_clk clk)
{
    // Tune MSDC PLL's PCW Frequency Setting
    switch (clk)
    {
        case MSDC_PLL_208MHZ:
            PLL_REG32(APCLKCTL_MSDCPLL_CTL) = 0x96100000;
        break;
        case MSDC_PLL_200MHZ:
            PLL_REG32(APCLKCTL_MSDCPLL_CTL) = 0x960F6276;
        break;
        default:
            PLL_REG32(APCLKCTL_MSDCPLL_CTL) = 0x960F6276;
        break;
    }
}

void set_trace_bus1x_clock(trace_bus1x_clk clk)
{
    // This API is only for Trace Owner's Experiment Usage. It Causes Side-effects

    switch (clk)
    {
        case TRACE_BUS1X_60MHZ:
            // Tune CA7PLL to 600MHz
            PLL_REG32(APCLKCTL_CA7PLL_CTL) = 0x920B89D8;
        break;
        case TRACE_BUS1X_61MHZ:
            // Tune CA7PLL to 610MHz
            PLL_REG32(APCLKCTL_CA7PLL_CTL) = 0x920BBB13;
        break;
        case TRACE_BUS1X_62MHZ:
            // Tune CA7PLL to 620MHz
            PLL_REG32(APCLKCTL_CA7PLL_CTL) = 0x920BEC4E;
        break;
        case TRACE_BUS1X_63MHZ:
            // Tune CA7PLL to 630MHz
            PLL_REG32(APCLKCTL_CA7PLL_CTL) = 0x920C1D89;
        break;
        case TRACE_BUS1X_64MHZ:
            // Tune CA7PLL to 640MHz
            PLL_REG32(APCLKCTL_CA7PLL_CTL) = 0x920C4EC4;
        break;
        case TRACE_BUS1X_65MHZ:
            // Tune CA7PLL to 650MHz
            PLL_REG32(APCLKCTL_CA7PLL_CTL) = 0x920C8000;
        break;
    }

    // Tune BUS2X to CA7PLL/5
    PLL_REG32(MDCLKCTL_CLKSRCSEL0) = (PLL_REG32(MDCLKCTL_CLKSRCSEL0) & 0xFF00FFFF) | 0x00400000;
}

#endif

#if defined(MT6595)
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
                    #error "Undefined Product Type. Error Code: PLL0001"
                #endif
            #else
                #if defined(__UMTS_FDD_MODE__)
                PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x0007;
                #elif defined(__UMTS_TDD128_MODE__)
                PLL_REG32(PLL_MD_SRCLKEN_CTL1)          = 0x000B;
                #else
                    #error "Undefined Product Type. Error Code: PLL0002"
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
#endif

#endif /* should NOT be compiled on MODIS */
