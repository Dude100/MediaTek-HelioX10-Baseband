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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  mt6582_pmic_wrap_hw.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *	This is mt6595 pmic wrapper h/w register
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __MT6595_PMIC_WRAP_HW_H__
#define __MT6595_PMIC_WRAP_HW_H__

#if !defined(FPGA_CTP)
#include "reg_base.h"

/* 
#define TOP_CLOCK_CTRL_BASE     		(AP_TOP_CLOCK_CTRL_BASE)
#define TOPRGU_BASE             		(AP_TOPRGU_BASE)
*/
#define PMIC_WRAP_BASE					(PWRAP_BASE)

#else
#define PMIC_WRAP_BASE					(0x1000D000)
#define CKSYS_BASE                      (0x10000000)
#define INFRACFG_AO_BASE                (0x10001000)

#endif

#define CLK_CFG_5_CLR               	(CKSYS_BASE + 0x098)

#define INFRA_GLOBALCON_RST0            (INFRACFG_AO_BASE + 0x030)

#define PMIC_WRAP_MUX_SEL               (PMIC_WRAP_BASE+0x0)
#define PMIC_WRAP_WRAP_EN               (PMIC_WRAP_BASE+0x4)
#define PMIC_WRAP_DIO_EN                (PMIC_WRAP_BASE+0x8)
#define PMIC_WRAP_SIDLY                 (PMIC_WRAP_BASE+0xC)
#define PMIC_WRAP_RDDMY                 (PMIC_WRAP_BASE+0x10)
#define PMIC_WRAP_SI_CK_CON             (PMIC_WRAP_BASE+0x14)
#define PMIC_WRAP_CSHEXT_WRITE          (PMIC_WRAP_BASE+0x18)
#define PMIC_WRAP_CSHEXT_READ           (PMIC_WRAP_BASE+0x1C)
#define PMIC_WRAP_CSLEXT_START          (PMIC_WRAP_BASE+0x20)
#define PMIC_WRAP_CSLEXT_END            (PMIC_WRAP_BASE+0x24)
#define PMIC_WRAP_STAUPD_PRD            (PMIC_WRAP_BASE+0x28)
#define PMIC_WRAP_STAUPD_GRPEN          (PMIC_WRAP_BASE+0x2C)
#define PMIC_WRAP_EINT_STA0_ADR         (PMIC_WRAP_BASE+0x30)
#define PMIC_WRAP_EINT_STA1_ADR         (PMIC_WRAP_BASE+0x34)
#define PMIC_WRAP_EINT_STA              (PMIC_WRAP_BASE+0x38)
#define PMIC_WRAP_EINT_CLR              (PMIC_WRAP_BASE+0x3C)
#define PMIC_WRAP_STAUPD_MAN_TRIG       (PMIC_WRAP_BASE+0x40)
#define PMIC_WRAP_STAUPD_STA            (PMIC_WRAP_BASE+0x44)
#define PMIC_WRAP_WRAP_STA              (PMIC_WRAP_BASE+0x48)
#define PMIC_WRAP_HARB_INIT             (PMIC_WRAP_BASE+0x4C)
#define PMIC_WRAP_HARB_HPRIO            (PMIC_WRAP_BASE+0x50)
#define PMIC_WRAP_HIPRIO_ARB_EN         (PMIC_WRAP_BASE+0x54)
#define PMIC_WRAP_HARB_STA0             (PMIC_WRAP_BASE+0x58)
#define PMIC_WRAP_HARB_STA1             (PMIC_WRAP_BASE+0x5C)
#define PMIC_WRAP_MAN_EN                (PMIC_WRAP_BASE+0x60)
#define PMIC_WRAP_MAN_CMD               (PMIC_WRAP_BASE+0x64)
#define PMIC_WRAP_MAN_RDATA             (PMIC_WRAP_BASE+0x68)
#define PMIC_WRAP_MAN_VLDCLR            (PMIC_WRAP_BASE+0x6C)
#define PMIC_WRAP_WACS0_EN              (PMIC_WRAP_BASE+0x70)
#define PMIC_WRAP_INIT_DONE0            (PMIC_WRAP_BASE+0x74)
#define PMIC_WRAP_WACS0_CMD             (PMIC_WRAP_BASE+0x78)
#define PMIC_WRAP_WACS0_RDATA           (PMIC_WRAP_BASE+0x7C)
#define PMIC_WRAP_WACS0_VLDCLR          (PMIC_WRAP_BASE+0x80)
#define PMIC_WRAP_WACS1_EN              (PMIC_WRAP_BASE+0x84)
#define PMIC_WRAP_INIT_DONE1            (PMIC_WRAP_BASE+0x88)
#define PMIC_WRAP_WACS1_CMD             (PMIC_WRAP_BASE+0x8C)
#define PMIC_WRAP_WACS1_RDATA           (PMIC_WRAP_BASE+0x90)
#define PMIC_WRAP_WACS1_VLDCLR          (PMIC_WRAP_BASE+0x94)
#define PMIC_WRAP_WACS2_EN              (PMIC_WRAP_BASE+0x98)
#define PMIC_WRAP_INIT_DONE2            (PMIC_WRAP_BASE+0x9C)
#define PMIC_WRAP_WACS2_CMD             (PMIC_WRAP_BASE+0xA0)
#define PMIC_WRAP_WACS2_RDATA           (PMIC_WRAP_BASE+0xA4)
#define PMIC_WRAP_WACS2_VLDCLR          (PMIC_WRAP_BASE+0xA8)
#define PMIC_WRAP_INT_EN                (PMIC_WRAP_BASE+0xAC)
#define PMIC_WRAP_INT_FLG_RAW           (PMIC_WRAP_BASE+0xB0)
#define PMIC_WRAP_INT_FLG               (PMIC_WRAP_BASE+0xB4)
#define PMIC_WRAP_INT_CLR               (PMIC_WRAP_BASE+0xB8)
#define PMIC_WRAP_SIG_ADR               (PMIC_WRAP_BASE+0xBC)
#define PMIC_WRAP_SIG_MODE              (PMIC_WRAP_BASE+0xC0)
#define PMIC_WRAP_SIG_VALUE             (PMIC_WRAP_BASE+0xC4)
#define PMIC_WRAP_SIG_ERRVAL            (PMIC_WRAP_BASE+0xC8)
#define PMIC_WRAP_CRC_EN                (PMIC_WRAP_BASE+0xCC)
#define PMIC_WRAP_TIMER_EN              (PMIC_WRAP_BASE+0xD0)
#define PMIC_WRAP_TIMER_STA             (PMIC_WRAP_BASE+0xD4)
#define PMIC_WRAP_WDT_UNIT              (PMIC_WRAP_BASE+0xD8)
#define PMIC_WRAP_WDT_SRC_EN            (PMIC_WRAP_BASE+0xDC)
#define PMIC_WRAP_WDT_FLG               (PMIC_WRAP_BASE+0xE0)
#define PMIC_WRAP_DEBUG_INT_SEL         (PMIC_WRAP_BASE+0xE4)
#define PMIC_WRAP_DVFS_ADR0             (PMIC_WRAP_BASE+0xE8)
#define PMIC_WRAP_DVFS_WDATA0           (PMIC_WRAP_BASE+0xEC)
#define PMIC_WRAP_DVFS_ADR1             (PMIC_WRAP_BASE+0xF0)
#define PMIC_WRAP_DVFS_WDATA1           (PMIC_WRAP_BASE+0xF4)
#define PMIC_WRAP_DVFS_ADR2             (PMIC_WRAP_BASE+0xF8)
#define PMIC_WRAP_DVFS_WDATA2           (PMIC_WRAP_BASE+0xFC)
#define PMIC_WRAP_DVFS_ADR3             (PMIC_WRAP_BASE+0x100)
#define PMIC_WRAP_DVFS_WDATA3           (PMIC_WRAP_BASE+0x104)
#define PMIC_WRAP_DVFS_ADR4             (PMIC_WRAP_BASE+0x108)
#define PMIC_WRAP_DVFS_WDATA4           (PMIC_WRAP_BASE+0x10C)
#define PMIC_WRAP_DVFS_ADR5             (PMIC_WRAP_BASE+0x110)
#define PMIC_WRAP_DVFS_WDATA5           (PMIC_WRAP_BASE+0x114)
#define PMIC_WRAP_DVFS_ADR6             (PMIC_WRAP_BASE+0x118)
#define PMIC_WRAP_DVFS_WDATA6           (PMIC_WRAP_BASE+0x11C)
#define PMIC_WRAP_DVFS_ADR7             (PMIC_WRAP_BASE+0x120)
#define PMIC_WRAP_DVFS_WDATA7           (PMIC_WRAP_BASE+0x124)
#define PMIC_WRAP_SPMINF_STA            (PMIC_WRAP_BASE+0x128)
#define PMIC_WRAP_CIPHER_KEY_SEL        (PMIC_WRAP_BASE+0x12C)
#define PMIC_WRAP_CIPHER_IV_SEL         (PMIC_WRAP_BASE+0x130)
#define PMIC_WRAP_CIPHER_EN             (PMIC_WRAP_BASE+0x134)
#define PMIC_WRAP_CIPHER_RDY            (PMIC_WRAP_BASE+0x138)
#define PMIC_WRAP_CIPHER_MODE           (PMIC_WRAP_BASE+0x13C)
#define PMIC_WRAP_CIPHER_SWRST          (PMIC_WRAP_BASE+0x140)
#define PMIC_WRAP_DCM_EN                (PMIC_WRAP_BASE+0x144)
#define PMIC_WRAP_DCM_DBC_PRD           (PMIC_WRAP_BASE+0x148)
#define PMIC_WRAP_EXT_CK                (PMIC_WRAP_BASE+0x14C)

// Bit Control
#define GET_STAUPD_DLE_CNT(x)        ((x>>0)  & 0x00000007)
#define GET_STAUPD_ALE_CNT(x)        ((x>>3)  & 0x00000007)
#define GET_STAUPD_FSM(x)            ((x>>6)  & 0x00000007)
#define GET_WRAP_CH_DLE_RESTCNT(x)   ((x>>0)  & 0x00000007)
#define GET_WRAP_CH_ALE_RESTCNT(x)   ((x>>3)  & 0x00000003)
#define GET_WRAP_AG_DLE_RESTCNT(x)   ((x>>5)  & 0x00000003)
#define GET_WRAP_CH_W(x)             ((x>>7)  & 0x00000001)
#define GET_WRAP_CH_REQ(x)           ((x>>8)  & 0x00000001)
#define GET_AG_WRAP_W(x)             ((x>>9)  & 0x00000001)
#define GET_AG_WRAP_REQ(x)           ((x>>10) & 0x00000001)
#define GET_WRAP_FSM(x)              ((x>>11) & 0x0000000f)
#define GET_HARB_WRAP_WDATA(x)       ((x>>0)  & 0x0000ffff)
#define GET_HARB_WRAP_ADR(x)         ((x>>16) & 0x00007fff)
#define GET_HARB_WRAP_REQ(x)         ((x>>31) & 0x00000001)
#define GET_HARB_DLE_EMPTY(x)        ((x>>0)  & 0x00000001)
#define GET_HARB_DLE_FULL(x)         ((x>>1)  & 0x00000001)
#define GET_HARB_VLD(x)              ((x>>2)  & 0x00000001)
#define GET_HARB_DLE_OWN(x)          ((x>>3)  & 0x00000007)
#define GET_HARB_OWN(x)              ((x>>6)  & 0x00000007)
#define GET_HARB_DLE_RESTCNT(x)      ((x>>9)  & 0x00000007)
#define GET_AG_HARB_REQ(x)           ((x>>12) & 0x0000003f)
#define GET_HARB_WRAP_W(x)           ((x>>18) & 0x00000001)
#define GET_HARB_WRAP_REQ0(x)        ((x>>19) & 0x00000001)
#define GET_SPI_WDATA(x)             ((x>>0)  & 0x000000ff)
#define GET_SPI_OP(x)                ((x>>8)  & 0x0000001f)
#define GET_SPI_W(x)                 ((x>>13) & 0x00000001)
#define GET_MAN_RDATA(x)             ((x>>0)  & 0x000000ff)
#define GET_MAN_FSM(x)               ((x>>8)  & 0x00000007)
#define GET_MAN_REQ(x)               ((x>>11) & 0x00000001)
#define GET_WACS0_WDATA(x)           ((x>>0)  & 0x0000ffff)
#define GET_WACS0_ADR(x)             ((x>>16) & 0x00007fff)
#define GET_WACS0_WRITE(x)           ((x>>31) & 0x00000001)
#define GET_WACS0_RDATA(x)           ((x>>0)  & 0x0000ffff)
#define GET_WACS0_FSM(x)             ((x>>16) & 0x00000007)
#define GET_WACS0_REQ(x)             ((x>>19) & 0x00000001)
#define GET_SYNC_IDLE0(x)            ((x>>20) & 0x00000001)
#define GET_INIT_DONE0(x)            ((x>>21) & 0x00000001)
#define GET_SYS_IDLE0(x)             ((x>>22) & 0x00000001)
#define GET_WACS0_FIFO_FILLCNT(x)    ((x>>24) & 0x0000000f)
#define GET_WACS0_FIFO_FREECNT(x)    ((x>>28) & 0x0000000f)
#define GET_WACS1_WDATA(x)           ((x>>0)  & 0x0000ffff)
#define GET_WACS1_ADR(x)             ((x>>16) & 0x00007fff)
#define GET_WACS1_WRITE(x)           ((x>>31) & 0x00000001)
#define GET_WACS1_RDATA(x)           ((x>>0)  & 0x0000ffff)
#define GET_WACS1_FSM(x)             ((x>>16) & 0x00000007)
#define GET_WACS1_REQ(x)             ((x>>19) & 0x00000001)
#define GET_SYNC_IDLE1(x)            ((x>>20) & 0x00000001)
#define GET_INIT_DONE1(x)            ((x>>21) & 0x00000001)
#define GET_SYS_IDLE1(x)             ((x>>22) & 0x00000001)
#define GET_WACS1_FIFO_FILLCNT(x)    ((x>>24) & 0x0000000f)
#define GET_WACS1_FIFO_FREECNT(x)    ((x>>28) & 0x0000000f)
#define GET_WACS2_WDATA(x)           ((x>>0)  & 0x0000ffff)
#define GET_WACS2_ADR(x)             ((x>>16) & 0x00007fff)
#define GET_WACS2_WRITE(x)           ((x>>31) & 0x00000001)
#define GET_WACS2_RDATA(x)           ((x>>0)  & 0x0000ffff)
#define GET_WACS2_FSM(x)             ((x>>16) & 0x00000007)
#define GET_WACS2_REQ(x)             ((x>>19) & 0x00000001)
#define GET_SYNC_IDLE2(x)            ((x>>20) & 0x00000001)
#define GET_INIT_DONE2(x)            ((x>>21) & 0x00000001)
#define GET_SYS_IDLE2(x)             ((x>>22) & 0x00000001)
#define GET_WACS2_FIFO_FILLCNT(x)    ((x>>24) & 0x0000000f)
#define GET_WACS2_FIFO_FREECNT(x)    ((x>>28) & 0x0000000f)

#define GET_WACS_RDATA(x)            ((x>>0)  & 0x0000ffff)      
#define GET_WACS_FSM(x)              ((x>>16) & 0x00000007)      
#define GET_WACS_REQ(x)              ((x>>19) & 0x00000001)      
#define GET_SYNC_IDLE(x)             ((x>>20) & 0x00000001)      
#define GET_INIT_DONE(x)             ((x>>21) & 0x00000001)     

#define SPI_AUTO_MODE           0
#define SPI_MANUAL_MODE         1

#define HARB_HPRIO_ALL          0x3F
#define HARB_HPRIO_STAUPD       (1 << 5)
#define HARB_HPRIO_WACS2        (1 << 4)
#define HARB_HPRIO_DVFSINF      (1 << 3)
#define HARB_HPRIO_WACS1        (1 << 2)
#define HARB_HPRIO_WACS0        (1 << 1)
#define HARB_HPRIO_MDINF        (1 << 0)

// Current WRAP FSM states.
#define WRAP_FSM_IDLE_STATE                 0x0
#define WRAP_FSM_CSL_ADR_START_STATE        0x2
#define WRAP_FSM_ADR_STATE                  0x4
#define WRAP_FSM_CSL_ADR_END_STATE          0x6
#define WRAP_FSM_CSH_ADR_STATE              0x8
#define WRAP_FSM_CSL_DATA_START_STATE       0xA
#define WRAP_FSM_DATA_STATE                 0xC
#define WRAP_FSM_CSL_DATA_END_STATE         0xE
#define WRAP_FSM_CSH_DATA_STATE             0xF

#define WACS_INIT_DONE_NOT_FINISHED         0
#define WACS_INIT_DONE_FINISHED             1


#define WACS_SYNC_MODULE_BUSY               0
#define WACS_SYNC_MODULE_IDLE               1

// Current WACS FSM states.
#define WACS_FSM_IDLE_STATE                 0x0
#define WACS_FSM_REQ_STATE                  0x2
#define WACS_FSM_WFDLE_STATE                0x4
#define WACS_FSM_WFVLDCLR_STATE             0x6

// Current MAN FSM states.
#define MAN_FSM_IDLE_STATE                  0x0
#define MAN_FSM_REQ_STATE                   0x2
#define MAN_FSM_WFDLE_STATE                 0x4
#define MAN_FSM_WFVLDCLR_STATE              0x6

// Current STAUPD FSM states.
#define STAUPD_FSM_IDLE_STATE               0x0
#define STAUPD_FSM_REQ_STATE                0x2
#define STAUPD_FSM_WFDLE_STATE              0x4

#define MT6331_DEW_READ_TEST_VALUE                 0x5AA5
#define MT6332_DEW_READ_TEST_VALUE                 0xA55A

//-----macro for manual commnd --------------------------------------------------------
// From par_spi_man.h
#define OP_WR    (0x1)
#define OP_RD    (0x0)

#define OP_CSH   (0x0)
#define OP_CSL   (0x1)
#define OP_CK    (0x2)

#define OP_OUTS  (0x8)
#define OP_OUTD  (0x9)
#define OP_OUTQ  (0xA)

#define OP_INS   (0xC)
#define OP_IND   (0xD)
#define OP_INQ   (0xE)

#define OP_OS2IS (0x10)
#define OP_OS2ID (0x11)
#define OP_OS2IQ (0x12)
#define OP_OD2IS (0x13)
#define OP_OD2ID (0x14)
#define OP_OD2IQ (0x15)
#define OP_OQ2IS (0x16)
#define OP_OQ2ID (0x17)
#define OP_OQ2IQ (0x18)

#define OP_OSNIS (0x19)
#define OP_ODNID (0x1A)

 #endif // __MT6595_PMIC_WRAP_HW_H__                   
                                                 
