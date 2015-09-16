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
 *  mt6589_pmic_wrap_hw.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *	This is mt6589 pmic wrapper h/w register
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
 
#ifndef __MT6752_PMIC_WRAP_HW_H__
#define __MT6589_PMIC_WRAP_HW_H__

#include "reg_base.h"

#define PMIC_WRAP_BASE                  (AP_PMIC_WRAP_base)

#define WDT_SWSYSRST                    (AP_TOPRGU_base + 0x18)
#define CLK_CFG_8                       (AP_TOPRGU_base + 0x164)

#define INFRA_GLOBALCON_RST0            (AP_INFRACFG_AO_base + 0x030)

#define PERI_GLOBALCON_RST1             (AP_PERICFG_base + 0x004)

#define PMIC_WRAP_MUX_SEL               (PMIC_WRAP_BASE+0x0)
#define PMIC_WRAP_WRAP_EN               (PMIC_WRAP_BASE+0x4)
#define PMIC_WRAP_DIO_EN                (PMIC_WRAP_BASE+0x8)
#define PMIC_WRAP_SIDLY                 (PMIC_WRAP_BASE+0xC)
#define PMIC_WRAP_CSHEXT                (PMIC_WRAP_BASE+0x10)
#define PMIC_WRAP_CSHEXT_WRITE          (PMIC_WRAP_BASE+0x14)
#define PMIC_WRAP_CSHEXT_READ           (PMIC_WRAP_BASE+0x18)
#define PMIC_WRAP_CSLEXT_START          (PMIC_WRAP_BASE+0x1C)
#define PMIC_WRAP_CSLEXT_END            (PMIC_WRAP_BASE+0x20)
#define PMIC_WRAP_STAUPD_PRD            (PMIC_WRAP_BASE+0x24)
#define PMIC_WRAP_STAUPD_GRPEN          (PMIC_WRAP_BASE+0x28)
#define PMIC_WRAP_STAUPD_MAN_TRIG       (PMIC_WRAP_BASE+0x2C)
#define PMIC_WRAP_STAUPD_STA            (PMIC_WRAP_BASE+0x30)
#define PMIC_WRAP_EVENT_IN_EN           (PMIC_WRAP_BASE+0x34)
#define PMIC_WRAP_EVENT_DST_EN          (PMIC_WRAP_BASE+0x38)
#define PMIC_WRAP_WRAP_STA              (PMIC_WRAP_BASE+0x3C)
#define PMIC_WRAP_RRARB_INIT            (PMIC_WRAP_BASE+0x40)
#define PMIC_WRAP_RRARB_EN              (PMIC_WRAP_BASE+0x44)
#define PMIC_WRAP_RRARB_STA0            (PMIC_WRAP_BASE+0x48)
#define PMIC_WRAP_RRARB_STA1            (PMIC_WRAP_BASE+0x4C)
#define PMIC_WRAP_HARB_INIT             (PMIC_WRAP_BASE+0x50)
#define PMIC_WRAP_HARB_HPRIO            (PMIC_WRAP_BASE+0x54)
#define PMIC_WRAP_HIPRIO_ARB_EN         (PMIC_WRAP_BASE+0x58)
#define PMIC_WRAP_HARB_STA0             (PMIC_WRAP_BASE+0x5C)
#define PMIC_WRAP_HARB_STA1             (PMIC_WRAP_BASE+0x60)
#define PMIC_WRAP_MAN_EN                (PMIC_WRAP_BASE+0x64)
#define PMIC_WRAP_MAN_CMD               (PMIC_WRAP_BASE+0x68)
#define PMIC_WRAP_MAN_RDATA             (PMIC_WRAP_BASE+0x6C)
#define PMIC_WRAP_MAN_VLDCLR            (PMIC_WRAP_BASE+0x70)
#define PMIC_WRAP_WACS0_EN              (PMIC_WRAP_BASE+0x74)
#define PMIC_WRAP_INIT_DONE0            (PMIC_WRAP_BASE+0x78)
#define PMIC_WRAP_WACS0_CMD             (PMIC_WRAP_BASE+0x7C)
#define PMIC_WRAP_WACS0_RDATA           (PMIC_WRAP_BASE+0x80)
#define PMIC_WRAP_WACS0_VLDCLR          (PMIC_WRAP_BASE+0x84)
#define PMIC_WRAP_WACS1_EN              (PMIC_WRAP_BASE+0x88)
#define PMIC_WRAP_INIT_DONE1            (PMIC_WRAP_BASE+0x8C)
#define PMIC_WRAP_WACS1_CMD             (PMIC_WRAP_BASE+0x90)
#define PMIC_WRAP_WACS1_RDATA           (PMIC_WRAP_BASE+0x94)
#define PMIC_WRAP_WACS1_VLDCLR          (PMIC_WRAP_BASE+0x98)
#define PMIC_WRAP_WACS2_EN              (PMIC_WRAP_BASE+0x9C)
#define PMIC_WRAP_INIT_DONE2            (PMIC_WRAP_BASE+0xA0)
#define PMIC_WRAP_WACS2_CMD             (PMIC_WRAP_BASE+0xA4)
#define PMIC_WRAP_WACS2_RDATA           (PMIC_WRAP_BASE+0xA8)
#define PMIC_WRAP_WACS2_VLDCLR          (PMIC_WRAP_BASE+0xAC)
#define PMIC_WRAP_INT_EN                (PMIC_WRAP_BASE+0xB0)
#define PMIC_WRAP_INT_FLG_RAW           (PMIC_WRAP_BASE+0xB4)
#define PMIC_WRAP_INT_FLG               (PMIC_WRAP_BASE+0xB8)
#define PMIC_WRAP_INT_CLR               (PMIC_WRAP_BASE+0xBC)
#define PMIC_WRAP_SIG_ADR               (PMIC_WRAP_BASE+0xC0)
#define PMIC_WRAP_SIG_MODE              (PMIC_WRAP_BASE+0xC4)
#define PMIC_WRAP_SIG_VALUE             (PMIC_WRAP_BASE+0xC8)
#define PMIC_WRAP_SIG_ERRVAL            (PMIC_WRAP_BASE+0xCC)
#define PMIC_WRAP_CRC_EN                (PMIC_WRAP_BASE+0xD0)
#define PMIC_WRAP_EVENT_STA             (PMIC_WRAP_BASE+0xD4)
#define PMIC_WRAP_EVENT_STACLR          (PMIC_WRAP_BASE+0xD8)
#define PMIC_WRAP_TIMER_EN              (PMIC_WRAP_BASE+0xDC)
#define PMIC_WRAP_TIMER_STA             (PMIC_WRAP_BASE+0xE0)
#define PMIC_WRAP_WDT_UNIT              (PMIC_WRAP_BASE+0xE4)
#define PMIC_WRAP_WDT_SRC_EN            (PMIC_WRAP_BASE+0xE8)
#define PMIC_WRAP_WDT_FLG               (PMIC_WRAP_BASE+0xEC)
#define PMIC_WRAP_DEBUG_INT_SEL         (PMIC_WRAP_BASE+0xF0)
#define PMIC_WRAP_DVFS_ADR0             (PMIC_WRAP_BASE+0xF4)
#define PMIC_WRAP_DVFS_WDATA0           (PMIC_WRAP_BASE+0xF8)
#define PMIC_WRAP_DVFS_ADR1             (PMIC_WRAP_BASE+0xFC)
#define PMIC_WRAP_DVFS_WDATA1           (PMIC_WRAP_BASE+0x100)
#define PMIC_WRAP_DVFS_ADR2             (PMIC_WRAP_BASE+0x104)
#define PMIC_WRAP_DVFS_WDATA2           (PMIC_WRAP_BASE+0x108)
#define PMIC_WRAP_DVFS_ADR3             (PMIC_WRAP_BASE+0x10C)
#define PMIC_WRAP_DVFS_WDATA3           (PMIC_WRAP_BASE+0x110)
#define PMIC_WRAP_DVFS_ADR4             (PMIC_WRAP_BASE+0x114)
#define PMIC_WRAP_DVFS_WDATA4           (PMIC_WRAP_BASE+0x118)
#define PMIC_WRAP_DVFS_ADR5             (PMIC_WRAP_BASE+0x11C)
#define PMIC_WRAP_DVFS_WDATA5           (PMIC_WRAP_BASE+0x120)
#define PMIC_WRAP_DVFS_ADR6             (PMIC_WRAP_BASE+0x124)
#define PMIC_WRAP_DVFS_WDATA6           (PMIC_WRAP_BASE+0x128)
#define PMIC_WRAP_DVFS_ADR7             (PMIC_WRAP_BASE+0x12C)
#define PMIC_WRAP_DVFS_WDATA7           (PMIC_WRAP_BASE+0x130)
#define PMIC_WRAP_CIPHER_KEY_SEL        (PMIC_WRAP_BASE+0x134)
#define PMIC_WRAP_CIPHER_IV_SEL         (PMIC_WRAP_BASE+0x138)
#define PMIC_WRAP_CIPHER_LOAD           (PMIC_WRAP_BASE+0x13C)
#define PMIC_WRAP_CIPHER_START          (PMIC_WRAP_BASE+0x140)
#define PMIC_WRAP_CIPHER_RDY            (PMIC_WRAP_BASE+0x144)
#define PMIC_WRAP_CIPHER_MODE           (PMIC_WRAP_BASE+0x148)
#define PMIC_WRAP_CIPHER_SWRST          (PMIC_WRAP_BASE+0x14C)
#define PMIC_WRAP_CIPHER_IV0            (PMIC_WRAP_BASE+0x150)
#define PMIC_WRAP_CIPHER_IV1            (PMIC_WRAP_BASE+0x154)
#define PMIC_WRAP_CIPHER_IV2            (PMIC_WRAP_BASE+0x158)
#define PMIC_WRAP_DCM_EN                (PMIC_WRAP_BASE+0x15C)
#define PMIC_WRAP_DCM_DBC_PRD           (PMIC_WRAP_BASE+0x160)

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
#define GET_HARB_DLE_OWN(x)          ((x>>3)  & 0x0000000f)      
#define GET_HARB_OWN(x)              ((x>>7)  & 0x0000000f)      
#define GET_HARB_DLE_RESTCNT(x)      ((x>>11) & 0x0000000f)      
#define GET_AG_HARB_REQ(x)           ((x>>15) & 0x000001ff)      
#define GET_HARB_WRAP_W(x)           ((x>>24) & 0x00000001)      
#define GET_HARB_WRAP_REQ0(x)        ((x>>25) & 0x00000001)      
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
#define GET_WACS1_WDATA(x)           ((x>>0)  & 0x0000ffff)      
#define GET_WACS1_ADR(x)             ((x>>16) & 0x00007fff)      
#define GET_WACS1_WRITE(x)           ((x>>31) & 0x00000001)      
#define GET_WACS1_RDATA(x)           ((x>>0)  & 0x0000ffff)      
#define GET_WACS1_FSM(x)             ((x>>16) & 0x00000007)      
#define GET_WACS1_REQ(x)             ((x>>19) & 0x00000001)      
#define GET_SYNC_IDLE1(x)            ((x>>20) & 0x00000001)      
#define GET_INIT_DONE1(x)            ((x>>21) & 0x00000001)      
#define GET_WACS2_WDATA(x)           ((x>>0)  & 0x0000ffff)      
#define GET_WACS2_ADR(x)             ((x>>16) & 0x00007fff)      
#define GET_WACS2_WRITE(x)           ((x>>31) & 0x00000001)      
#define GET_WACS2_RDATA(x)           ((x>>0)  & 0x0000ffff)      
#define GET_WACS2_FSM(x)             ((x>>16) & 0x00000007)      
#define GET_WACS2_REQ(x)             ((x>>19) & 0x00000001)      
#define GET_SYNC_IDLE2(x)            ((x>>20) & 0x00000001)      
#define GET_INIT_DONE2(x)            ((x>>21) & 0x00000001)      

#define GET_WACS_RDATA(x)            ((x>>0)  & 0x0000ffff)      
#define GET_WACS_FSM(x)              ((x>>16) & 0x00000007)      
#define GET_WACS_REQ(x)              ((x>>19) & 0x00000001)      
#define GET_SYNC_IDLE(x)             ((x>>20) & 0x00000001)      
#define GET_INIT_DONE(x)             ((x>>21) & 0x00000001)     

#define SPI_AUTO_MODE           0
#define SPI_MANUAL_MODE         1
#define HARB_HPRIO_ALL          0x1FF
#define HARB_HPRIO_RRAPB        (1 << 8)
#define HARB_HPRIO_PERI_PWRAP   (1 << 7)
#define HARB_HPRIO_STAUPD       (1 << 6)
#define HARB_HPRIO_ERC          (1 << 5)
#define HARB_HPRIO_DVFSINF      (1 << 4)
#define HARB_HPRIO_WACS2        (1 << 3)
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

#define DEW_READ_TEST_VALUE                 0x5AA5

//-----macro for manual commnd --------------------------------------------------------
#define OP_WR    (0x1)

#define OP_CSH   (0x0)
#define OP_CSL   (0x1)
#define OP_OUTS  (0x8)
#define OP_OUTD  (0x9)
#define OP_INS   (0xC)
#define OP_IND   (0xD)

 #endif // __MT6752_PMIC_WRAP_HW_H__                   
                                                 
