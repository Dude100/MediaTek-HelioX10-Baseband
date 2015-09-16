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
 *  mt6572_pmic_wrap_sw.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *	This is for mt6572 pmic wrapper driver s/w usage
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MT6572_PMIC_WRAP_SW_H__
#define __MT6572_PMIC_WRAP_SW_H__

#include "drv_comm.h"
#define PMIC_WRAP_READ              0
#define PMIC_WRAP_WRITE             1

#define PMIC_WRAP_REG_CLOCK_SAFE_MODE   0

#define PMIC_WRAP_REG_CLOCK_06MHZ       1
#define PMIC_WRAP_REG_CLOCK_12MHZ       2

#define PMIC_WRAP_REG_CLOCK_18MHZ       1
#define PMIC_WRAP_REG_CLOCK_36MHZ       2

#define DEW_WRITE_TEST_VALUE            0xA55A

#define PMIC_WRAP_INVALID_RW            0x10
#define PMIC_WRAP_INVALID_ADDR          0x11
#define PMIC_WRAP_INVALID_WDATA         0x12
#define PMIC_WRAP_INVALID_OP            0x13
#define PMIC_WRAP_INVALID_ARGUMENT      0x14

#define PMIC_WRAP_INIT_SIDLY_FAIL	0x20
#define PMIC_WRAP_INIT_REG_CLK_FAIL	0x21
#define PMIC_WRAP_INIT_DUAL_MODE_FAIL	0x22
#define PMIC_WRAP_INIT_CIPHER_FAIL	0x23

#define PMIC_WRAP_NOT_INIT_DONE         0x30
#define PMIC_WRAP_NOT_INIT_DONE_READ    0x31
#define PMIC_WRAP_READ_TEST_FAIL        0x32
#define PMIC_WRAP_WRITE_TEST_FAIL       0x33
#define PMIC_WRAP_SWITCH_DIO_FAIL       0x34
#define PMIC_WRAP_READ_FAIL             0x35
#define PMIC_WRAP_WRITE_FAIL            0x36
#define PMIC_WRAP_DEW_EVENT_TEST_FAIL   0x37
#define PMIC_WRAP_MANUAL_MODE_NOT_IDLE  0x38
#define PMIC_WRAP_STAUPD_FSM_NOT_IDLE   0x39


#define PMIC_WRAP_TIME_OUT_FAIL         0xFF

#define OP_RD       (0x0)
#define OP_WR       (0x1)

#define OP_CSH      (0x0)
#define OP_CSL      (0x1)
#define OP_CK       (0x2)
#define OP_OUTS     (0x8)
#define OP_OUTD     (0x9)
#define OP_INS      (0xC)
#define OP_IND      (0xD)

#define DRV_WriteReg(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#define DRV_Reg(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_WriteReg32(addr,data)   ((*(volatile kal_uint32 *)(addr)) = (kal_uint32)(data))
#define DRV_Reg32(addr)             (*(volatile kal_uint32 *)(addr))
#define DRV_WriteReg8(addr,data)    ((*(volatile kal_uint8 *)(addr)) = (kal_uint8)(data))
#define DRV_Reg8(addr)              (*(volatile kal_uint8 *)(addr))

#define DRV_ClearBits32(addr,data)     {\
   kal_uint32 temp;\
   temp = DRV_Reg32(addr);\
   temp &=~(data);\
   DRV_WriteReg32(addr,temp);\
}

#define DRV_SetBits32(addr,data)     {\
   kal_uint32 temp;\
   temp = DRV_Reg32(addr);\
   temp |= (data);\
   DRV_WriteReg32(addr,temp);\
}

#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_PMIC_WRAP_REG_DBG__)
#define PMIC_WRAP_DRV_ClearBits16(addr,data)        DRV_DBG_ClearBits(addr,data)
#define PMIC_WRAP_DRV_SetBits16(addr)               DRV_DBG_SetBits(addr)
#define PMIC_WRAP_DRV_WriteReg16(addr, data)        DRV_DBG_WriteReg(addr, data)
#define PMIC_WRAP_DRV_ReadReg16(addr)               DRV_DBG_Reg(addr)
#define PMIC_WRAP_DRV_ClearBits32(addr, data)       DRV_DBG_ClearBits32(addr, data)
#define PMIC_WRAP_DRV_SetBits32(addr, data)         DRV_DBG_SetBits32(addr, data)
#define PMIC_WRAP_DRV_SetData(addr, bitmask, value)     DRV_SetData(addr, bitmask, value)
#define PMIC_WRAP_DRV_WriteReg32(addr,data)         DRV_DBG_WriteReg32(addr,data)
#define PMIC_WRAP_DRV_Reg32(addr)                   DRV_DBG_Reg32(addr)
#else // #if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_RTC_REG_DBG__)
#define PMIC_WRAP_DRV_ClearBits16(addr, data)       DRV_ClearBits(addr,data)
#define PMIC_WRAP_DRV_SetBits16(addr, data)         DRV_SetBits(addr,data)
#define PMIC_WRAP_DRV_WriteReg16(addr, data)        DRV_WriteReg(addr, data)
#define PMIC_WRAP_DRV_ReadReg16(addr)               DRV_Reg(addr)
#define PMIC_WRAP_DRV_ClearBits32(addr, data)       DRV_ClearBits32(addr, data)
#define PMIC_WRAP_DRV_SetBits32(addr, data)         DRV_SetBits32(addr, data)
#define PMIC_WRAP_DRV_SetData(addr, bitmask, value)     DRV_SetData(addr, bitmask, value)
#define PMIC_WRAP_DRV_WriteReg32(addr,data)         DRV_WriteReg32(addr,data)
#define PMIC_WRAP_DRV_Reg32(addr)                   DRV_Reg32(addr)
#endif // #if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_RTC_REG_DBG__)

kal_uint32 DrvPWRAP_Init(void);
kal_uint32 DrvPWRAP_WACS2_NoChk(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata);
//kal_uint32 DrvPWRAP_WACS0(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata);
kal_uint32 DrvPWRAP_WACS0(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint16 *rdata);
//kal_uint32 DrvPWRAP_WACS1(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata);
kal_uint32 DrvPWRAP_WACS1(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint16 *rdata);
kal_uint32 DrvPWRAP_WACS2(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata);
kal_uint32 DrvPWRAP_Man(kal_uint32 write, kal_uint32 op, kal_uint32 wdata, kal_uint32 *rdata );
kal_uint32 DrvPWRAP_ManAccess(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata);
kal_uint32 DrvPWRAP_InitDio(kal_bool dio_en);
kal_uint32 DrvPWRAP_SwitchDio(kal_bool dio_en);
kal_uint32 DrvPWRAP_InitCIPHER(void);
kal_uint32 DrvPWRAP_EnableCIPHER(void);
kal_uint32 DrvPWRAP_DisableCIPHER(void);
void DrvPWRAP_ResetSPISLV(void);
void DrvPWRAP_SwitchMux(kal_uint8 mux_sel_new);
kal_uint32 DrvPWRAP_InitSiStrobe(void);
kal_uint32 DrvPWRAP_StaUpdTrig(kal_uint32 mode);
void DrvPWRAP_AlignCRC(void);
kal_uint32 DrvPWRAP_InitRegClk(kal_uint32 regck_sel);

typedef kal_uint32 (*loop_condition_fp)(kal_uint32); // Define a function pointer

#endif // __MT6572_PMIC_WRAP_SW_H__
