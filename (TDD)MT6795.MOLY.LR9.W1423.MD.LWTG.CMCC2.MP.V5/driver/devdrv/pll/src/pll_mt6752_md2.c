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
 *   pll_mt6752_md2.c
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
 * Merging from //MOLY/Development_BRANCHES/MT6752E1_BRING_UP_DEV/mcu/driver/devdrv/pll/...
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

#define MCUPLL_ON
#define MD2_MCUPLL_COMPILE
#define FH_OFF
#undef  PLL_DIV

#define MT6752_MD2_PLL_ASM_MARKER(sym) do { __asm__ __volatile__ (".global " #sym ";\n" #sym ":\n"); } while(0)

#if defined(FH_OFF) && (defined(MCU_481M) || defined(MCU_480M))
    #define  DISABLE_FRACTIONAL
#else
    #undef   DISABLE_FRACTIONAL
#endif

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
#define TMP_LOOP_WAIT_VAL 4000

void INT_SetPLL(pll_init_mode mode)
{
    volatile kal_uint32 loop_var;

    *PLL_DFS_CON7               = 0x0033;   // [Force On]
                                            // Bit  5: SYSCLK
                                            // Bit  4: MDPLL
                                            // Bit  3: WHPLL
                                            // Bit  2: WPLL
                                            // Bit  1: MCUPLL
                                            // Bit  0: Not used
    *PLL_PLL_CON3               = 0x8000;   // [Power On]
                                            // Bit 15: MCUPLL
                                            // Bit  9: WHPLL
                                            // Bit  8: WPLL
    for (loop_var = 0; loop_var < TMP_LOOP_WAIT_VAL; loop_var++);
    *PLL_PLL_CON3               = 0x0000;   // [Power Off]
    *PLL_PLL_CON2               = 0x0000;   // [TOPSM & SW Ctrl]
                                            // Bit 12: MDPLL
                                            // Bit  8: MCUPLL
                                            // Bit  4: WPLL
                                            // Bit  0: WHPLL
    *PLL_PLLTD_CON0             = 0x0010;   // [FHCTL & SW Ctrl]
                                            // Bit  4: CHG_CTRL

    /* 13*(INT+FRC/2^14) */
    #if defined(MCU_478M)
    // 478.4 actually (align to MD1 Bus/BSI clk)
    *PLL_MCUPLL_CON2           &= 0xFF80;
    *PLL_MCUPLL_CON2           |= 0x0049; //INT
    *PLL_MCUPLL_CON3            = 0x2666; //FRC
    MT6752_MD2_PLL_ASM_MARKER(ARM9PLL_478);
    #elif defined(MCU_479M)
    *PLL_MCUPLL_CON2           &= 0xFF80;
    *PLL_MCUPLL_CON2           |= 0x0049;
    *PLL_MCUPLL_CON3            = 0x2C4E;
    MT6752_MD2_PLL_ASM_MARKER(ARM9PLL_479);
    #elif defined(MCU_480M)
    MT6752_MD2_PLL_ASM_MARKER(ARM9PLL_480);
    /* HW default setting, do nothing */
    #elif defined(MCU_481M)
    MT6752_MD2_PLL_ASM_MARKER(ARM9PLL_481);
    /* HW default setting, do nothing */
    #else
        #error "Unknown CR4 Clock/CR4PLL2 setting"
    #endif

    /* Enable PLLs */
    //*PLL_MDPLL_CON0            |= 0x8000;   // Bit 15: MDPLL_EN
    #ifdef DISABLE_FRACTIONAL
    MT6752_MD2_PLL_ASM_MARKER(ARM9PLL_FRAC_OFF);
    *PLL_MCUPLL_CON0           &= 0xFFEF;   // Bit  4: Disable FRA Mode
    #else
    MT6752_MD2_PLL_ASM_MARKER(ARM9PLL_FRAC_ON);
    /* When SSC enabled, must also enable FRC.
     * Otherwise, SSC would be stepped in integer */
    *PLL_MCUPLL_CON0            |= 0x0010;   // Bit  4: Enable FRA Mode
    #endif
    for (loop_var = 0; loop_var < TMP_LOOP_WAIT_VAL; loop_var++);
    *PLL_MCUPLL_CON0           |= 0x8000;   // Bit 15: MCUPLL_EN

    /* Frequency Hopping */
    for (loop_var = 0; loop_var < 20; loop_var++);
    *PLL_PLLTD_CON0             = 0x0000;   // Bit  4: CHG_CTRL by FHCTL
    for (loop_var = 0; loop_var <  5; loop_var++);

    #if defined(MCUPLL_ON) || defined(MD2_MCUPLL_COMPILE)
    #ifndef FH_OFF
    *PLL_FH_CON5                = 0x0076;   // Bit 15- 8: MCUPLL DDS Upper Limit
                                            // Bit 7 -10: MCUPLL DDS Lower Limit
    for (loop_var = 0; loop_var < 300; loop_var++); // For hopping selection change time, delay for enable free_run hopping, 300 is  a rough number
    *PLL_FH_CON4                = 0xA455;   // Bit 0: FH_EN
                                            // Bit 1: SOFT_START_EN
                                            // Bit 2: FREE_RUN_EN
                                            // Bit 10- 9: FREE_RUN_TIME_STEP
                                            // Bit 14-12: FREE_RUN_DDS_STEP

    #endif /* FH_OFF */
    #endif

    for (loop_var = 0; loop_var < 60; loop_var++);
    //*PLL_MDPLL_CON0            &= 0x7FFF;   // Bit 15: MDPLL_EN
    //*PLL_MDPLL_CON4            &= 0xFFFE;   // Bit  0: Disable MDPLL AutoK
    //for (loop_var = 0; loop_var < 1; loop_var++);
    for (loop_var = 0; loop_var < 100; loop_var++);
                                            // Turn MDPLL(MDPLL2) & disable AutoK then turn off and trun on
    *PLL_MDPLL_CON0            |= 0x8000;   // Bit 15: MDPLL_EN
    for (loop_var = 0; loop_var < 60; loop_var++);
    *PLL_MDPLL_CON0            &= 0x7FFF;   // Bit 15: MDPLL_EN
    *PLL_MDPLL_CON4            &= 0xFFFE;   // Bit  0: Disable AutoK
    *PLL_MDPLL_CON0            |= 0x8000;   // Bit 15: MDPLL_EN
    for (loop_var = 0; loop_var < 15; loop_var++);

    #ifdef PLL_DIV
    *PLL_CLKSW_FDIV0            = 0x0420;   // Bit 15-12: MCUPLL DIV1
                                            // Bit 11- 8: MCUPLL DIV2 (/4)
                                            // Bit  7- 4: MCUPLL DIV3 (/2)
                                            // Bit  3- 0: MCUPLL DIV4
    *PLL_CLKSW_FDIV2            = 0x0020;   // Bit 15-12: MDPLL DIV1
                                            // Bit 11- 8: MDPLL DIV2
                                            // Bit  7- 4: MDPLL DIV3 (/2)
                                            // Bit  3- 0: MDPLL DIV4
    *PLL_CLKSW_FDIV6           |= 0x0017;   // [DIV EN]
                                            // Bit  4: MCUPLL
                                            // Bit  2: MDPLL
                                            // Bit  1: WHPLL
                                            // Bit  0: WPLL
    *PLL_CLKSW_FDIV6           |= 0x05C0;   // [DIV 0->1]
                                            // Bit 10: MCUPLL
                                            // Bit  8: MDPLL
                                            // Bit  7: WHPLL
                                            // Bit  6: WPLL
    *PLL_CLKSW_FDIV6           &= 0xFA3F;   // [DIV 0->1]
    #endif


    *PLL_CLKSW_FDIV7            = 0xC100;   // Bit 15: PLL_DIV_CG_EN
                                            // Bit 14/ 8: Disable CONN Denesnse

    *PLL_MD_GLOBAL_CON1        |= 0x20000000; // Bit 29: BUS_CLK = PLL Freq (not 26M)

    #ifndef SIM_26M
    #ifdef MD2_MCUPLL_COMPILE
    *PLL_CLKSW_CKSEL3           = 0x0113;
    #endif
    *PLL_CLKSW_CKSEL0           = 0x2020;

    *PLL_CLKSW_CKSEL1           = 0x2000;
    *PLL_CLKSW_CKSEL2           = 0x2220;


    #ifdef MCUPLL_ON
    *PLL_CLKSW_CKSEL3           = 0x0113;
    #endif

    #endif /* SIM_26M */
    *PLL_DFS_CON7               = 0x0000;   // disable the force on to allow PLL on/off freely
}

void INT_SetPLL_Phase2()
{
    /* Do nothing, AP would init VTCXO for DSDA, no need for phase2 */
}

#endif /* __MTK_TARGET__ --- should NOT be compiled on MODIS */
