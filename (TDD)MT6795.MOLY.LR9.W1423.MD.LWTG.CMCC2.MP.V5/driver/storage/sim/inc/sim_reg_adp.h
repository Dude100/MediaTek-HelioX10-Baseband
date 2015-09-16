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
 *    sim_reg_adp.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is to be an adaptation layer for all SIM related register functions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*RHR*/
#include "drv_comm.h"
/*RHR*/
#ifndef __SIM_REG_ADP_H__
#define __SIM_REG_ADP_H__





#ifdef __DRV_SIM_RW_DBG__
#define SIM_WriteReg(addr,data) DRV_DBG_WriteReg(addr,data)
#define SIM_Reg(addr) DRV_DBG_Reg(addr)
#define SIM_WriteReg32(addr,data) DRV_DBG_WriteReg32(addr,data)
#define SIM_Reg32(addr) DRV_DBG_Reg32(addr)
#define SIM_WriteReg8(addr,data) DRV_DBG_WriteReg8(addr,data)
#define SIM_Reg8(addr) DRV_DBG_Reg8(addr)
#define SIM_ClearBits(addr,data) DRV_DBG_ClearBits(addr,data)
#define SIM_SetData(addr, bitmask, value) DRV_DBG_SetData(addr, bitmask, value)
#define SIM_SetBits(addr,data) DRV_DBG_SetBits(addr,data)
#define SIM_ClearBits32(addr,data) DRV_DBG_ClearBits32(addr,data)
#define SIM_SetBits32(addr,data) DRV_DBG_SetBits32(addr,data)
#define SIM_SetData32(addr, bitmask, value) DRV_DBG_SetData32(addr, bitmask, value)
#define SIM_ClearBits8(addr,data) DRV_DBG_ClearBits8(addr,data)
#define SIM_SetBits8(addr,data) DRV_DBG_SetBits8(addr,data)
#define SIM_SetData8(addr, bitmask, value) DRV_DBG_SetData8(addr, bitmask, value)
#else
#define SIM_WriteReg(addr,data) DRV_WriteReg(addr,data)
#define SIM_Reg(addr) DRV_Reg(addr)
#define SIM_WriteReg32(addr,data) DRV_WriteReg32(addr,data)
#define SIM_Reg32(addr) DRV_Reg32(addr)
#define SIM_WriteReg8(addr,data) DRV_WriteReg8(addr,data)
#define SIM_Reg8(addr) DRV_Reg8(addr)
#define SIM_ClearBits(addr,data) DRV_ClearBits(addr,data)
#define SIM_SetBits(addr,data) DRV_SetBits(addr,data)
#define SIM_SetData(addr, bitmask, value) DRV_SetData(addr, bitmask, value)
#define SIM_ClearBits32(addr,data) DRV_ClearBits32(addr,data)
#define SIM_SetBits32(addr,data) DRV_SetBits32(addr,data)
#define SIM_SetData32(addr, bitmask, value) DRV_SetData32(addr, bitmask, value)
#define SIM_ClearBits8(addr,data) DRV_ClearBits8(addr,data)
#define SIM_SetBits8(addr,data) DRV_SetBits8(addr,data)
#define SIM_SetData8(addr, bitmask, value) DRV_SetData8(addr, bitmask, value)
#endif





#endif //__SIM_REG_ADP_H__
