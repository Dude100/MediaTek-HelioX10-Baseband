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
 *   pll.h
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
 * Merging
 * 
 * //MOLY_CBr/yuyang.hsiao/MOLY_W14.12.LTE.p2.HwporSwCtrl/mcu/driver/devdrv/pll/...
 * 
 * to //MOLY/TRUNK/MOLY/mcu/driver/devdrv/pll/...
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

#ifndef __PLL_H__
#define __PLL_H__

/*******************************************************************************
 * Locally Used Options
 *******************************************************************************/
#define PLL_FOR_FPGA    __FPGA__    /* 0: For ASIC,  1: For FPGA */


/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "kal_general_types.h"
#include "reg_base.h"


/*************************************************************************
 * Define exported macro
 *************************************************************************/
#if defined(MT6290)
    #if PLL_FOR_FPGA
    #define BUS_CLOCK_MHZ       20      // Mostly Used BUS1X Clock Frquency
    #else
    #define BUS_CLOCK_MHZ       60      // BUS1X Clock Frequency
    #endif
#elif defined(MT6595)
    #define BUS_CLOCK_MHZ       61.44   // BUS1X Clock Frequency
#elif defined(MT6752)
    #define BUS_CLOCK_MHZ       61.44   // BUS1X Clock Frequency
#endif

/*************************************************************************
 * Define data structure
 *************************************************************************/

 /* Dummy type definition to avoid other legacy module code build issue */
typedef enum mcu_clock_enum_t {
    DUMMY
} mcu_clock_enum;

/* PLL initialization mode */
typedef enum {
    PLL_MODE_MAUI,
    PLL_MODE_USB_META
} pll_init_mode;

#if defined(MT6290)
/* SPI clock divisor */
typedef enum {
    CLKCTL_SPI_DIV_4 = 0,
    CLKCTL_SPI_DIV_5,
    CLKCTL_SPI_DIV_6,
    CLKCTL_SPI_DIV_7,
    CLKCTL_SPI_DIV_8,
    CLKCTL_SPI_DIV_9,
    CLKCTL_SPI_DIV_10,
    CLKCTL_SPI_DIV_11,
    CLKCTL_SPI_DIV_12,
    CLKCTL_SPI_DIV_14,
    CLKCTL_SPI_DIV_18,
    CLKCTL_SPI_DIV_20,
    CLKCTL_SPI_DIV_26,
    CLKCTL_SPI_DIV_64,
    CLKCTL_SPI_DIV_128,
    CLKCTL_SPI_DIV_256
} spi_clk_div;

/* MSDC clock divisor */
typedef enum {
    CLKCTL_MSDC_PREDIV_1 = 0,
    CLKCTL_MSDC_PREDIV_2,
    CLKCTL_MSDC_PREDIV_3,
    CLKCTL_MSDC_PREDIV_4,
    CLKCTL_MSDC_PREDIV_5,
    CLKCTL_MSDC_PREDIV_6,
    CLKCTL_MSDC_PREDIV_7,
    CLKCTL_MSDC_PREDIV_8
} msdc_clk_pre_div;

typedef enum {
    CLKCTL_MSDC_POSTDIV_1 = 0,
    CLKCTL_MSDC_POSTDIV_2,
    CLKCTL_MSDC_POSTDIV_3,
    CLKCTL_MSDC_POSTDIV_4,
    CLKCTL_MSDC_POSTDIV_5,
    CLKCTL_MSDC_POSTDIV_6,
    CLKCTL_MSDC_POSTDIV_7,
    CLKCTL_MSDC_POSTDIV_8
} msdc_clk_post_div;

/* MSDC PLL selection */
typedef enum {
    MSDC_PLL_208MHZ = 0,
    MSDC_PLL_200MHZ
} msdc_pll_clk;

/* Trace Bus1X selection */
typedef enum {
    TRACE_BUS1X_60MHZ = 0,
    TRACE_BUS1X_61MHZ,
    TRACE_BUS1X_62MHZ,
    TRACE_BUS1X_63MHZ,
    TRACE_BUS1X_64MHZ,
    TRACE_BUS1X_65MHZ
} trace_bus1x_clk;
#endif

#if defined(MT6595) || (defined(MT6752) && defined(__MD1__))
typedef enum {
    CTRL_MODE_HW = 0,
    CTRL_MODE_SW
} hw_por_ctrl_mode;

typedef enum {
    SWCTRL_FORCE_OFF = 0,
    SWCTRL_FORCE_ON
} hw_por_swctrl;
#endif

/*************************************************************************
 * Define exported function prototype
 *************************************************************************/
extern void INT_SetPLL(pll_init_mode mode);
extern void INT_SetPLL_Phase2();

#if defined(MT6290)
extern void enable_ap_clk();

extern void set_spi_clk_div(spi_clk_div div);
extern void set_msdc0_clk_div(msdc_clk_pre_div prediv, msdc_clk_post_div postdiv);
extern void set_msdc1_clk_div(msdc_clk_pre_div prediv, msdc_clk_post_div postdiv);
extern void set_msdc_pll_clock(msdc_pll_clk clk);
extern void set_trace_bus1x_clock(trace_bus1x_clk clk);
#endif

#if defined(MT6595) || (defined(MT6752) && defined(__MD1__))
extern void set_hw_por_ctrlmode(hw_por_ctrl_mode mode);
extern void set_hw_por_swctrl(hw_por_swctrl swctrl);
#endif

#if defined(MT6752) && defined(__MD1__)
extern void set_csw_lt1l1_axi_ck(kal_uint32 onoff);
#endif

/*************************************************************************
 * Define HW register
 *************************************************************************/
#if defined(MT6290)
#define MDCLKCTL_R_MDCLKCTL_CODA_VERSION    (BASE_ADDR_MDCLKCTL+0x0)
#define MDCLKCTL_CLKONCTL                   (BASE_ADDR_MDCLKCTL+0x4)
#define MDCLKCTL_CLKSRCSEL0                 (BASE_ADDR_MDCLKCTL+0x8)
#define MDCLKCTL_CLKSRCSEL1                 (BASE_ADDR_MDCLKCTL+0xC)
#define MDCLKCTL_CLKSPDCTL	                (BASE_ADDR_MDCLKCTL+0x14)
#define MDCLKCTL_MDCLKONCTL	                (BASE_ADDR_MDCLKCTL+0x18)
#define MDCLKCTL_APCLKONCTL	                (BASE_ADDR_MDCLKCTL+0x1C)
#define MDCLKCTL_CLKSWCCTL	                (BASE_ADDR_MDCLKCTL+0x20)
#define MDCLKCTL_SRCLKEN_CTL	            (BASE_ADDR_MDCLKCTL+0x24)
#define MDCLKCTL_SRCLKEN_CTL2	            (BASE_ADDR_MDCLKCTL+0x28)
#define MDCLKCTL_SLEEP_CNT	                (BASE_ADDR_MDCLKCTL+0x2C)
#define MDCLKCTL_RING_OSC_CTL	            (BASE_ADDR_MDCLKCTL+0x100)
#define MDCLKCTL_RAND_NUM	                (BASE_ADDR_MDCLKCTL+0x104)
#define MDCLKCTL_FREQ_METER_CTL	            (BASE_ADDR_MDCLKCTL+0x108)
#define MDCLKCTL_FREQ_XTAL_CNT	            (BASE_ADDR_MDCLKCTL+0x10C)
#define MDCLKCTL_CKMON_CNT	                (BASE_ADDR_MDCLKCTL+0x110)
#define MDCLKCTL_FREQ_METER_H	            (BASE_ADDR_MDCLKCTL+0x114)
#define MDCLKCTL_FREQ_METER_L	            (BASE_ADDR_MDCLKCTL+0x118)
#define MDCLKCTL_CKMON_CTL	                (BASE_ADDR_MDCLKCTL+0x11C)
#define MDCLKCTL_PLLGP_MONCTL	            (BASE_ADDR_MDCLKCTL+0x300)
#define MDCLKCTL_ARM7PLL_CTL	            (BASE_ADDR_MDCLKCTL+0x308)
#define MDCLKCTL_CR4PLL_CTL	                (BASE_ADDR_MDCLKCTL+0x30C)
#define MDCLKCTL_UNIVPLL_CTL	            (BASE_ADDR_MDCLKCTL+0x310)
#define MDCLKCTL_ISPPLL_CTL	                (BASE_ADDR_MDCLKCTL+0x314)
#define MDCLKCTL_EMIDDS_CTL	                (BASE_ADDR_MDCLKCTL+0x31C)
#define MDCLKCTL_DSPPLL_CTL	                (BASE_ADDR_MDCLKCTL+0x320)
#define MDCLKCTL_LTEWHPLL_CTL	            (BASE_ADDR_MDCLKCTL+0x324)
#define MDCLKCTL_LTEWPLL_CTL	            (BASE_ADDR_MDCLKCTL+0x328)
#define MDCLKCTL_OGTWPLL_CTL	            (BASE_ADDR_MDCLKCTL+0x32C)
#define MDCLKCTL_LTEPLL_CTL0	            (BASE_ADDR_MDCLKCTL+0x330)
#define MDCLKCTL_LTEPLL_CTL1	            (BASE_ADDR_MDCLKCTL+0x334)
#define MDCLKCTL_LTEPLL_CTL2	            (BASE_ADDR_MDCLKCTL+0x338)
#define MDCLKCTL_LTEPLL_CTL3	            (BASE_ADDR_MDCLKCTL+0x33C)
#define MDCLKCTL_TDPLL_CTL0	                (BASE_ADDR_MDCLKCTL+0x340)
#define MDCLKCTL_TDPLL_CTL1	                (BASE_ADDR_MDCLKCTL+0x344)
#define MDCLKCTL_MEMPLL_CTL0	            (BASE_ADDR_MDCLKCTL+0x350)
#define MDCLKCTL_MEMPLL_CTL1	            (BASE_ADDR_MDCLKCTL+0x354)
#define MDCLKCTL_MEMPLL_CTL2	            (BASE_ADDR_MDCLKCTL+0x358)
#define MDCLKCTL_MEMPLL2_CTL0	            (BASE_ADDR_MDCLKCTL+0x35C)
#define MDCLKCTL_MEMPLL2_CTL1	            (BASE_ADDR_MDCLKCTL+0x360)
#define MDCLKCTL_MEMPLL2_CTL2	            (BASE_ADDR_MDCLKCTL+0x364)
#define MDCLKCTL_MEMPLL3_CTL0	            (BASE_ADDR_MDCLKCTL+0x368)
#define MDCLKCTL_MEMPLL3_CTL1	            (BASE_ADDR_MDCLKCTL+0x36C)
#define MDCLKCTL_MEMPLL3_CTL2	            (BASE_ADDR_MDCLKCTL+0x370)
#define MDCLKCTL_MEMPLL4_CTL0	            (BASE_ADDR_MDCLKCTL+0x374)
#define MDCLKCTL_MEMPLL4_CTL1	            (BASE_ADDR_MDCLKCTL+0x378)
#define MDCLKCTL_MEMPLL4_CTL2	            (BASE_ADDR_MDCLKCTL+0x37C)
#define MDCLKCTL_POP_MEMPLL_CTL0	        (BASE_ADDR_MDCLKCTL+0x380)
#define MDCLKCTL_POP_MEMPLL_CTL1	        (BASE_ADDR_MDCLKCTL+0x384)
#define MDCLKCTL_POP_MEMPLL_CTL2	        (BASE_ADDR_MDCLKCTL+0x388)
#define MDCLKCTL_POP_MEMPLL3_CTL0	        (BASE_ADDR_MDCLKCTL+0x38C)
#define MDCLKCTL_POP_MEMPLL3_CTL1	        (BASE_ADDR_MDCLKCTL+0x390)
#define MDCLKCTL_POP_MEMPLL3_CTL2	        (BASE_ADDR_MDCLKCTL+0x394)
#define MDCLKCTL_MEMPLL_JMETER_CTL	        (BASE_ADDR_MDCLKCTL+0x398)
#define MDCLKCTL_MEMPLL0_JMETER_STS	        (BASE_ADDR_MDCLKCTL+0x3A0)
#define MDCLKCTL_MEMPLL1_JMETER_STS	        (BASE_ADDR_MDCLKCTL+0x3A4)
#define MDCLKCTL_MEMPLL2_JMETER_STS	        (BASE_ADDR_MDCLKCTL+0x3A8)
#define MDCLKCTL_MEMPLL3_JMETER_STS	        (BASE_ADDR_MDCLKCTL+0x3AC)
#define MDCLKCTL_MEMPLL_PCW	                (BASE_ADDR_MDCLKCTL+0x3B0)
#define MDCLKCTL_POP_MEMPLL_PCW	            (BASE_ADDR_MDCLKCTL+0x3B4)
#define MDCLKCTL_PLL_FORCE_ON	            (BASE_ADDR_MDCLKCTL+0x400)
#define MDCLKCTL_MDTOPSM_SW_CTL	            (BASE_ADDR_MDCLKCTL+0x404)
#define MDCLKCTL_APTOPSM_SW_CTL	            (BASE_ADDR_MDCLKCTL+0x408)
#define MDCLKCTL_LTEL1_TOPSM_SW_CTL	        (BASE_ADDR_MDCLKCTL+0x40C)
#define MDCLKCTL_MODEM_TOPSM_SW_CTL	        (BASE_ADDR_MDCLKCTL+0x410)
#define MDCLKCTL_PLL_DLY_CTL0	            (BASE_ADDR_MDCLKCTL+0x420)
#define MDCLKCTL_PLL_DLY_CTL1	            (BASE_ADDR_MDCLKCTL+0x424)
#define MDCLKCTL_PLL_DLY_CTL2           	(BASE_ADDR_MDCLKCTL+0x428)
#define MDCLKCTL_PLL_DLY_CTL3	            (BASE_ADDR_MDCLKCTL+0x42C)
#define MDCLKCTL_PLL_DLY_CTL4	            (BASE_ADDR_MDCLKCTL+0x430)
#define MDCLKCTL_PLL_DLY_CTL5	            (BASE_ADDR_MDCLKCTL+0x434)
#define MDCLKCTL_PLL_ON_CTL0	            (BASE_ADDR_MDCLKCTL+0x438)
#define MDCLKCTL_PLL_ON_CTL1	            (BASE_ADDR_MDCLKCTL+0x43C)
#define MDCLKCTL_PLL_ON_CTL2	            (BASE_ADDR_MDCLKCTL+0x440)
#define MDCLKCTL_PLL_ON_CTL3	            (BASE_ADDR_MDCLKCTL+0x444)
#define MDCLKCTL_DCXO_ON_CTL	            (BASE_ADDR_MDCLKCTL+0x448)
#define MDCLKCTL_PLLFH_CTL	                (BASE_ADDR_MDCLKCTL+0x500)
#define MDCLKCTL_CR4PLL_FH_CTL1	            (BASE_ADDR_MDCLKCTL+0x524)
#define MDCLKCTL_CR4PLL_FH_CTL2	            (BASE_ADDR_MDCLKCTL+0x528)
#define MDCLKCTL_CR4PLL_FH_CTL3	            (BASE_ADDR_MDCLKCTL+0x52C)
#define MDCLKCTL_CR4PLL_FH_CTL4	            (BASE_ADDR_MDCLKCTL+0x530)
#define MDCLKCTL_CR4PLL_FH_CTL5	            (BASE_ADDR_MDCLKCTL+0x534)
#define MDCLKCTL_ARM7PLL_FH_CTL1	        (BASE_ADDR_MDCLKCTL+0x544)
#define MDCLKCTL_ARM7PLL_FH_CTL2	        (BASE_ADDR_MDCLKCTL+0x548)
#define MDCLKCTL_ARM7PLL_FH_CTL3	        (BASE_ADDR_MDCLKCTL+0x54C)
#define MDCLKCTL_ARM7PLL_FH_CTL4	        (BASE_ADDR_MDCLKCTL+0x550)
#define MDCLKCTL_ARM7PLL_FH_CTL5	        (BASE_ADDR_MDCLKCTL+0x554)
#define MDCLKCTL_DSPPLL_FH_CTL1	            (BASE_ADDR_MDCLKCTL+0x564)
#define MDCLKCTL_DSPPLL_FH_CTL2	            (BASE_ADDR_MDCLKCTL+0x568)
#define MDCLKCTL_DSPPLL_FH_CTL3	            (BASE_ADDR_MDCLKCTL+0x56C)
#define MDCLKCTL_DSPPLL_FH_CTL4	            (BASE_ADDR_MDCLKCTL+0x570)
#define MDCLKCTL_DSPPLL_FH_CTL5	            (BASE_ADDR_MDCLKCTL+0x574)
#define MDCLKCTL_ISPPLL_FH_CTL1	            (BASE_ADDR_MDCLKCTL+0x5A4)
#define MDCLKCTL_ISPPLL_FH_CTL2	            (BASE_ADDR_MDCLKCTL+0x5A8)
#define MDCLKCTL_ISPPLL_FH_CTL3	            (BASE_ADDR_MDCLKCTL+0x5AC)
#define MDCLKCTL_ISPPLL_FH_CTL4	            (BASE_ADDR_MDCLKCTL+0x5B0)
#define MDCLKCTL_ISPPLL_FH_CTL5	            (BASE_ADDR_MDCLKCTL+0x5B4)
#define MDCLKCTL_EMIDDS_FH_CTL1	            (BASE_ADDR_MDCLKCTL+0x5C0)
#define MDCLKCTL_EMIDDS_FH_CTL2	            (BASE_ADDR_MDCLKCTL+0x5C4)
#define MDCLKCTL_EMIDDS_FH_CTL3	            (BASE_ADDR_MDCLKCTL+0x5C8)
#define MDCLKCTL_EMIDDS_FH_CTL4	            (BASE_ADDR_MDCLKCTL+0x5CC)
#define MDCLKCTL_EMIDDS_FH_CTL5	            (BASE_ADDR_MDCLKCTL+0x5D0)
#define MDCLKCTL_STATUS_0	                (BASE_ADDR_MDCLKCTL+0x800)
#define MDCLKCTL_STATUS_1	                (BASE_ADDR_MDCLKCTL+0x804)
#define MDCLKCTL_STATUS_2	                (BASE_ADDR_MDCLKCTL+0x808)
#define MDCLKCTL_STATUS_3	                (BASE_ADDR_MDCLKCTL+0x80C)
#define MDCLKCTL_STATUS_4	                (BASE_ADDR_MDCLKCTL+0x810)
#define MDCLKCTL_STATUS_5	                (BASE_ADDR_MDCLKCTL+0x814)
#define MDCLKCTL_STATUS_6	                (BASE_ADDR_MDCLKCTL+0x818)
#define MDCLKCTL_STATUS_7	                (BASE_ADDR_MDCLKCTL+0x81C)
#define MDCLKCTL_DUMMY	                    (BASE_ADDR_MDCLKCTL+0x1000)
#define MDCLKCTL_DUMMY2	                    (BASE_ADDR_MDCLKCTL+0x1004)
#define MDCLKCTL_TOP_DUMMY	                (BASE_ADDR_MDCLKCTL+0x1008)
#define MDCLKCTL_TOP_STATUS	                (BASE_ADDR_MDCLKCTL+0x100C)
#define MDCLKCTL_FPGA_EMICTL	            (BASE_ADDR_MDCLKCTL+0x4000)
#define MDCLKCTL_FPGA_CLKSPDCTL	            (BASE_ADDR_MDCLKCTL+0x4004)

#define APCLKCTL_R_APCLKCTL_CODA_VERSION	(BASE_ADDR_APCLKCTL+0x8000)
#define APCLKCTL_CLKONCTL	                (BASE_ADDR_APCLKCTL+0x8004)
#define APCLKCTL_CLKSRCSEL2	                (BASE_ADDR_APCLKCTL+0x8010)
#define APCLKCTL_CLKSPDCTL	                (BASE_ADDR_APCLKCTL+0x8014)
#define APCLKCTL_MDCLKONCTL	                (BASE_ADDR_APCLKCTL+0x8018)
#define APCLKCTL_APCLKONCTL	                (BASE_ADDR_APCLKCTL+0x801C)
#define APCLKCTL_CA7PLL_CTL	                (BASE_ADDR_APCLKCTL+0x8304)
#define APCLKCTL_MSDCPLL_CTL	            (BASE_ADDR_APCLKCTL+0x8318)
#define APCLKCTL_PLL_ON_CTL0	            (BASE_ADDR_APCLKCTL+0x8438)
#define APCLKCTL_PLL_ON_CTL1	            (BASE_ADDR_APCLKCTL+0x843C)
#define APCLKCTL_CA7PLL_FH_CTL1	            (BASE_ADDR_APCLKCTL+0x8504)
#define APCLKCTL_CA7PLL_FH_CTL2	            (BASE_ADDR_APCLKCTL+0x8508)
#define APCLKCTL_CA7PLL_FH_CTL3	            (BASE_ADDR_APCLKCTL+0x850C)
#define APCLKCTL_CA7PLL_FH_CTL4	            (BASE_ADDR_APCLKCTL+0x8510)
#define APCLKCTL_CA7PLL_FH_CTL5	            (BASE_ADDR_APCLKCTL+0x8514)
#define APCLKCTL_MSDCPLL_FH_CTL1	        (BASE_ADDR_APCLKCTL+0x8584)
#define APCLKCTL_MSDCPLL_FH_CTL2	        (BASE_ADDR_APCLKCTL+0x8588)
#define APCLKCTL_MSDCPLL_FH_CTL3        	(BASE_ADDR_APCLKCTL+0x858C)
#define APCLKCTL_MSDCPLL_FH_CTL4	        (BASE_ADDR_APCLKCTL+0x8590)
#define APCLKCTL_MSDCPLL_FH_CTL5	        (BASE_ADDR_APCLKCTL+0x8594)
#define APCLKCTL_DUMMY	                    (BASE_ADDR_APCLKCTL+0x9000)

#elif defined(MT6595)

#define PLL_PLL_CON0	                    (BASE_ADDR_PLL_MIXEDSYS+0x0020)
#define PLL_PLL_CON2_1	                    (BASE_ADDR_PLL_MIXEDSYS+0x0024)
#define PLL_PLL_MTCMOS_CON0	                (BASE_ADDR_PLL_MIXEDSYS+0x0028)
#define PLL_MD_MDTOPSM_SW_CTL	            (BASE_ADDR_PLL_MIXEDSYS+0x002C)
#define PLL_MD_LTEL1TOPSM_SW_CTL	        (BASE_ADDR_PLL_MIXEDSYS+0x0030)
#define PLL_MD_MODEMTOPSM_SW_CTL	        (BASE_ADDR_PLL_MIXEDSYS+0x0034)
#define PLL_MD_M2GTOPSM_SW_CTL	            (BASE_ADDR_PLL_MIXEDSYS+0x0038)
#define PLL_MD_CR4PLL_DIV_CON	            (BASE_ADDR_PLL_MIXEDSYS+0x003C)
#define PLL_MD_CR4PLL_DIV_CON1	            (BASE_ADDR_PLL_MIXEDSYS+0x0040)
#define PLL_PLL_CON1	                    (BASE_ADDR_PLL_MIXEDSYS+0x0044)
#define PLL_PLL_CON2	                    (BASE_ADDR_PLL_MIXEDSYS+0x0048)
#define PLL_PLL_CON3	                    (BASE_ADDR_PLL_MIXEDSYS+0x004C)
#define PLL_PLL_CON4	                    (BASE_ADDR_PLL_MIXEDSYS+0x0050)
#define PLL_MD_SRCLKEN_CTL0	                (BASE_ADDR_PLL_MIXEDSYS+0x0054)
#define PLL_MD_SRCLKEN_CTL1	                (BASE_ADDR_PLL_MIXEDSYS+0x0058)
#define PLL_LTEMDPLL_TEST	                (BASE_ADDR_PLL_MIXEDSYS+0x005C)
#define PLL_CLKSW_CKSEL0	                (BASE_ADDR_PLL_MIXEDSYS+0x0060)
#define PLL_CLKSW_CKSEL1	                (BASE_ADDR_PLL_MIXEDSYS+0x0064)
#define PLL_CLKSW_CKSEL2	                (BASE_ADDR_PLL_MIXEDSYS+0x0068)
#define PLL_CLKSW_CKSEL3	                (BASE_ADDR_PLL_MIXEDSYS+0x006C)
#define PLL_CLKSW_FDIV0	                    (BASE_ADDR_PLL_MIXEDSYS+0x0070)
#define PLL_CLKSW_FDIV1	                    (BASE_ADDR_PLL_MIXEDSYS+0x0074)
#define PLL_CLKSW_FDIV2	                    (BASE_ADDR_PLL_MIXEDSYS+0x0078)
#define PLL_CLKSW_FDIV3	                    (BASE_ADDR_PLL_MIXEDSYS+0x007C)
#define PLL_CLKSW_FDIV4	                    (BASE_ADDR_PLL_MIXEDSYS+0x0080)
#define PLL_CLKSW_FDIV5	                    (BASE_ADDR_PLL_MIXEDSYS+0x0084)
#define PLL_CLKSW_FDIV6	                    (BASE_ADDR_PLL_MIXEDSYS+0x0088)
#define PLL_CLKSW_FDIV7	                    (BASE_ADDR_PLL_MIXEDSYS+0x008C)
#define PLL_CLKSW_CONN_CON0	                (BASE_ADDR_PLL_MIXEDSYS+0x0090)
#define PLL_CLKSW_CKSEL4	                (BASE_ADDR_PLL_MIXEDSYS+0x0094)
#define PLL_CLKSW_CKSEL5	                (BASE_ADDR_PLL_MIXEDSYS+0x0098)
#define PLL_CLKSW_CKSEL6	                (BASE_ADDR_PLL_MIXEDSYS+0x009C)
#define PLL_CLKSW_CKSEL7	                (BASE_ADDR_PLL_MIXEDSYS+0x00A0)
#define PLL_CLKSW_CKSEL8	                (BASE_ADDR_PLL_MIXEDSYS+0x00A4)
#define PLL_DFS_CON8_1	                    (BASE_ADDR_PLL_MIXEDSYS+0x00A8)
#define PLL_DFS_CON7	                    (BASE_ADDR_PLL_MIXEDSYS+0x00AC)
#define PLL_DFS_CON8	                    (BASE_ADDR_PLL_MIXEDSYS+0x00B0)
#define PLL_DFS_CON9	                    (BASE_ADDR_PLL_MIXEDSYS+0x00B4)
#define PLL_DPM_SEL_SW_CTL0	                (BASE_ADDR_PLL_MIXEDSYS+0x00B8)
#define PLL_DPM_SEL_SW_CTL1	                (BASE_ADDR_PLL_MIXEDSYS+0x00BC)
#define PLL_DPM_STB_TIME_CTRL0	            (BASE_ADDR_PLL_MIXEDSYS+0x00C0)
#define PLL_MDPLL_CON0	                    (BASE_ADDR_PLL_MIXEDSYS+0x0100)
#define PLL_MDPLL_CON1	                    (BASE_ADDR_PLL_MIXEDSYS+0x0104)
#define PLL_MDPLL_CON2	                    (BASE_ADDR_PLL_MIXEDSYS+0x0108)
#define PLL_MDPLL_CON3	                    (BASE_ADDR_PLL_MIXEDSYS+0x010C)
#define PLL_MDPLL_CON4	                    (BASE_ADDR_PLL_MIXEDSYS+0x0110)
#define PLL_TDPLL_CON0	                    (BASE_ADDR_PLL_MIXEDSYS+0x0120)
#define PLL_TDPLL_CON1	                    (BASE_ADDR_PLL_MIXEDSYS+0x0124)
#define PLL_TDPLL_CON2	                    (BASE_ADDR_PLL_MIXEDSYS+0x0128)
#define PLL_TDPLL_CON3	                    (BASE_ADDR_PLL_MIXEDSYS+0x012C)
#define PLL_TDPLL_CON4	                    (BASE_ADDR_PLL_MIXEDSYS+0x0130)
#define PLL_MCUPLL_CON0	                    (BASE_ADDR_PLL_MIXEDSYS+0x0140)
#define PLL_MCUPLL_CON1	                    (BASE_ADDR_PLL_MIXEDSYS+0x0144)
#define PLL_MCUPLL_CON2	                    (BASE_ADDR_PLL_MIXEDSYS+0x0148)
#define PLL_MCUPLL_CON3	                    (BASE_ADDR_PLL_MIXEDSYS+0x014C)
#define PLL_ARM7PLL_CON0	                (BASE_ADDR_PLL_MIXEDSYS+0x0150)
#define PLL_ARM7PLL_CON1	                (BASE_ADDR_PLL_MIXEDSYS+0x0154)
#define PLL_ARM7PLL_CON2	                (BASE_ADDR_PLL_MIXEDSYS+0x0158)
#define PLL_ARM7PLL_CON3	                (BASE_ADDR_PLL_MIXEDSYS+0x015C)
#define PLL_WPLL_CON0	                    (BASE_ADDR_PLL_MIXEDSYS+0x01C0)
#define PLL_WPLL_CON1	                    (BASE_ADDR_PLL_MIXEDSYS+0x01C4)
#define PLL_WPLL_CON2	                    (BASE_ADDR_PLL_MIXEDSYS+0x01C8)
#define PLL_WPLL_CON3	                    (BASE_ADDR_PLL_MIXEDSYS+0x01CC)
#define PLL_OGTWPLL_CON0	                (BASE_ADDR_PLL_MIXEDSYS+0x01D0)
#define PLL_OGTWPLL_CON1	                (BASE_ADDR_PLL_MIXEDSYS+0x01D4)
#define PLL_OGTWPLL_CON2	                (BASE_ADDR_PLL_MIXEDSYS+0x01D8)
#define PLL_OGTWPLL_CON3	                (BASE_ADDR_PLL_MIXEDSYS+0x01DC)
#define PLL_CR4PLL2_CON0	                (BASE_ADDR_PLL_MIXEDSYS+0x01E0)
#define PLL_CR4PLL2_CON1	                (BASE_ADDR_PLL_MIXEDSYS+0x01E4)
#define PLL_CR4PLL2_CON2	                (BASE_ADDR_PLL_MIXEDSYS+0x01E8)
#define PLL_CR4PLL2_CON3	                (BASE_ADDR_PLL_MIXEDSYS+0x01EC)
#define PLL_CR4PLL2_CON4	                (BASE_ADDR_PLL_MIXEDSYS+0x01F0)
#define PLL_WHPLL_CON0	                    (BASE_ADDR_PLL_MIXEDSYS+0x0200)
#define PLL_WHPLL_CON2	                    (BASE_ADDR_PLL_MIXEDSYS+0x0208)
#define PLL_WHPLL_CON3	                    (BASE_ADDR_PLL_MIXEDSYS+0x020C)
#define PLL_WHPLL_CON4	                    (BASE_ADDR_PLL_MIXEDSYS+0x0210)
#define PLL_RSV_CON0	                    (BASE_ADDR_PLL_MIXEDSYS+0x0360)
#define PLL_ABIST_FQMTR_CON0	            (BASE_ADDR_PLL_MIXEDSYS+0x0400)
#define PLL_ABIST_FQMTR_CON1	            (BASE_ADDR_PLL_MIXEDSYS+0x0404)
#define PLL_ABIST_FQMTR_CON2	            (BASE_ADDR_PLL_MIXEDSYS+0x0408)
#define PLL_ABIST_FQMTR_DATA	            (BASE_ADDR_PLL_MIXEDSYS+0x040C)
#define PLL_SYS_ABIST_MON_CON0	            (BASE_ADDR_PLL_MIXEDSYS+0x0420)
#define PLL_SYS_ABIST_MON_CON1	            (BASE_ADDR_PLL_MIXEDSYS+0x0424)
#define PLL_SYS_ABIST_MON_CON2	            (BASE_ADDR_PLL_MIXEDSYS+0x0428)
#define PLL_ABIST_MON_DATA0	                (BASE_ADDR_PLL_MIXEDSYS+0x0440)
#define PLL_FH_CON0	                        (BASE_ADDR_PLL_MIXEDSYS+0x0500)
#define PLL_FH_CON1	                        (BASE_ADDR_PLL_MIXEDSYS+0x0504)
#define PLL_FH_CON2	                        (BASE_ADDR_PLL_MIXEDSYS+0x0508)
#define PLL_FH_CON3	                        (BASE_ADDR_PLL_MIXEDSYS+0x050C)
#define PLL_FH_CON4	                        (BASE_ADDR_PLL_MIXEDSYS+0x0510)
#define PLL_FH_CON5	                        (BASE_ADDR_PLL_MIXEDSYS+0x0514)
#define PLL_FH_CON6	                        (BASE_ADDR_PLL_MIXEDSYS+0x0518)
#define PLL_FH_CON7	                        (BASE_ADDR_PLL_MIXEDSYS+0x051C)
#define PLL_FH_CON9	                        (BASE_ADDR_PLL_MIXEDSYS+0x0524)
#define PLL_FH_CON10	                    (BASE_ADDR_PLL_MIXEDSYS+0x0528)
#define PLL_FH_CON11	                    (BASE_ADDR_PLL_MIXEDSYS+0x052C)
#define PLL_FH_CON12	                    (BASE_ADDR_PLL_MIXEDSYS+0x0530)
#define PLL_FH_CON13	                    (BASE_ADDR_PLL_MIXEDSYS+0x0534)
#define PLL_FH_CON14	                    (BASE_ADDR_PLL_MIXEDSYS+0x0538)
#define PLL_FH_CON15	                    (BASE_ADDR_PLL_MIXEDSYS+0x053C)
#define PLL_FH_CON16	                    (BASE_ADDR_PLL_MIXEDSYS+0x0540)
#define PLL_FH_CON17	                    (BASE_ADDR_PLL_MIXEDSYS+0x0544)
#define PLL_FH_CON18	                    (BASE_ADDR_PLL_MIXEDSYS+0x0548)
#define PLL_FH_CON19	                    (BASE_ADDR_PLL_MIXEDSYS+0x054C)
#define PLL_FH_CON20	                    (BASE_ADDR_PLL_MIXEDSYS+0x0550)
#define PLL_FH_CON21	                    (BASE_ADDR_PLL_MIXEDSYS+0x0554)
#define PLL_FH_CON22	                    (BASE_ADDR_PLL_MIXEDSYS+0x0558)
#define PLL_FH_CON23	                    (BASE_ADDR_PLL_MIXEDSYS+0x055C)
#define PLL_FH_CON24	                    (BASE_ADDR_PLL_MIXEDSYS+0x0560)
#define PLL_FH_CON25	                    (BASE_ADDR_PLL_MIXEDSYS+0x0564)
#define PLL_FH_CON26	                    (BASE_ADDR_PLL_MIXEDSYS+0x0568)
#define PLL_FH_CON27	                    (BASE_ADDR_PLL_MIXEDSYS+0x056C)
#define PLL_FH_CON28	                    (BASE_ADDR_PLL_MIXEDSYS+0x0570)
#define PLL_FH_CON29	                    (BASE_ADDR_PLL_MIXEDSYS+0x0574)
#define PLL_FH_CON30	                    (BASE_ADDR_PLL_MIXEDSYS+0x0578)
#define PLL_FH_CON31	                    (BASE_ADDR_PLL_MIXEDSYS+0x057C)
#define PLL_FH_CON32	                    (BASE_ADDR_PLL_MIXEDSYS+0x0580)
#define PLL_FH_CON8	                        (BASE_ADDR_PLL_MIXEDSYS+0x0584)
#define PLL_FH_CON8_1	                    (BASE_ADDR_PLL_MIXEDSYS+0x0588)
#define PLL_FH_CON_CR4PLL2	                (BASE_ADDR_PLL_MIXEDSYS+0x058C)
#define PLL_FH_CON_CR4PLL2_1	            (BASE_ADDR_PLL_MIXEDSYS+0x0590)
#define PLL_FH_CON1_1	                    (BASE_ADDR_PLL_MIXEDSYS+0x0594)
#define PLL_FH_CON_CR4PLL_SW_SEL	        (BASE_ADDR_PLL_MIXEDSYS+0x0598)
#define PLL_PLL_DEBUG_CTL	                (BASE_ADDR_PLL_MIXEDSYS+0x059C)
#define PLL_PLLTD_CON0	                    (BASE_ADDR_PLL_MIXEDSYS+0x0700)
#define PLL_PLLTD_CON1	                    (BASE_ADDR_PLL_MIXEDSYS+0x0704)
#define PLL_PLLTD_CON2	                    (BASE_ADDR_PLL_MIXEDSYS+0x0708)
#define PLL_PLLTD_CON3	                    (BASE_ADDR_PLL_MIXEDSYS+0x070C)
#define PLL_PLLTD_CON4	                    (BASE_ADDR_PLL_MIXEDSYS+0x0710)
#define PLL_PLLTD_CON5	                    (BASE_ADDR_PLL_MIXEDSYS+0x0714)
#define PLL_PLLTD_CON6	                    (BASE_ADDR_PLL_MIXEDSYS+0x0718)
#define PLL_PLLTD_CON7	                    (BASE_ADDR_PLL_MIXEDSYS+0x071C)
#define PLL_PLLTD_CON8	                    (BASE_ADDR_PLL_MIXEDSYS+0x0720)
#define PLL_PLL_RESERVE_REG	                (BASE_ADDR_PLL_MIXEDSYS+0x0800)

// Shall Be Internally Used, Or There Will be Multiple Definitions
#define PLL_MD_MCU_CON2	                    (BASE_ADDR_MDCONFIG+0x108)
#define PLL_MD2EMI_ULTRA_HIGH_SET0          (BASE_ADDR_MDCONFIG+0x404)
#define PLL_MD2EMI_ULTRA_HIGH_SET1          (BASE_ADDR_MDCONFIG+0x414)
#define PLL_MD_GLOBAL_CLR0	                (BASE_ADDR_MDCONFIG+0x458)
#define PLL_MD_GLOBAL_CON1	                (BASE_ADDR_MDCONFIG+0x45C)
#define PLL_MD_DUAL_TALK	                (BASE_ADDR_MDCONFIG+0x604)

#define PLL_GDMA_FDCSR0                     (BASE_ADDR_MDGDMA+0x0010)
#define PLL_GDMA_FDCR0                      (BASE_ADDR_MDGDMA+0x0020)
#define PLL_GDMA_FDSAR0                     (BASE_ADDR_MDGDMA+0x0024)
#define PLL_GDMA_FDDAR0                     (BASE_ADDR_MDGDMA+0x0028)

#elif defined(MT6752)
# if defined(__MD2__)
#  include "pll_mt6752_md2.h"
# else /* __MD1__ */
#  include "pll_mt6752_md1.h"
# endif
#endif

#endif  /* !__PLL_H__ */
