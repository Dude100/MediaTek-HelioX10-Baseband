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
 *    msdc_reg_adap.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for memory card common definitions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MSDC_REG_ADAP_H
#define MSDC_REG_ADAP_H

#include "drv_comm.h"

//#define __DRV_MSDC_REG_DBG__

#if !defined(DRV_MSDC_OFF)
#ifdef __DRV_MSDC_REG_DBG__

#define MSDC_WriteReg(addr,data) DRV_DBG_WriteReg(addr,data)
#define MSDC_Reg(addr) DRV_DBG_Reg(addr)
#define MSDC_WriteReg32(addr,data) DRV_DBG_WriteReg32(addr,data)
#define MSDC_Reg32(addr) DRV_DBG_Reg32(addr)
#define MSDC_WriteReg8(addr,data) DRV_DBG_WriteReg8(addr,data)
#define MSDC_Reg8(addr) DRV_DBG_Reg8(addr)

#define MSDC_ClearBits(addr,data) DRV_DBG_ClearBits(addr,data)
#define MSDC_SetBits(addr,data) DRV_DBG_SetBits(addr,data)
#define MSDC_ClearBits32(addr,data) DRV_DBG_ClearBits32(addr,data)
#define MSDC_SetBits32(addr,data) DRV_DBG_SetBits32(addr,data)
#define MSDC_ClearBits8(addr,data) DRV_DBG_ClearBits8(addr,data)
#define MSDC_SetBits8(addr,data) DRV_DBG_SetBits8(addr,data)

#define MSDC_SetData(addr,bitmask,value) DRV_DBG_SetData(addr,bitmask,value)
#define MSDC_SetData32(addr,bitmask,value) DRV_DBG_SetData32(addr,bitmask,value)
#define MSDC_SetData8(addr,bitmask,value) DRV_DBG_SetData8(addr,bitmask,value)

#else

#define MSDC_WriteReg(addr,data) DRV_WriteReg(addr,data)
#define MSDC_Reg(addr) DRV_Reg(addr)
#define MSDC_WriteReg32(addr,data) DRV_WriteReg32(addr,data)
#define MSDC_WriteReg32_NPW(addr,data) DRV_WriteReg32_NPW(addr,data)
#define MSDC_Reg32(addr) DRV_Reg32(addr)
#define MSDC_WriteReg8(addr,data) DRV_WriteReg8(addr,data)
#define MSDC_Reg8(addr) DRV_Reg8(addr)

#define MSDC_ClearBits(addr,data) DRV_ClearBits(addr,data)
#define MSDC_SetBits(addr,data) DRV_SetBits(addr,data)
#define MSDC_ClearBits32(addr,data) DRV_ClearBits32(addr,data)
#define MSDC_SetBits32(addr,data) DRV_SetBits32(addr,data)
#define MSDC_ClearBits8(addr,data) DRV_ClearBits8(addr,data)
#define MSDC_SetBits8(addr,data) DRV_SetBits8(addr,data)

#define MSDC_SetData(addr,bitmask,value) DRV_SetData(addr,bitmask,value)
#define MSDC_SetData32(addr,bitmask,value) DRV_SetData32(addr,bitmask,value)
#define MSDC_SetData8(addr,bitmask,value) DRV_SetData8(addr,bitmask,value)

#define MSDC_SET_FIELD_NPW(addr,bitmask,value)      \
    do {    \
        volatile kal_uint32 tv = MSDC_Reg32(addr); \
        tv &= ~(bitmask); \
        tv |= ((value) << (uffs(bitmask) - 1)); \
        DRV_WriteReg32_NPW(addr,tv); \
    } while(0)

#define MSDC_SET_FIELD(addr,bitmask,value)      \
    do {    \
        volatile kal_uint32 tv = MSDC_Reg32(addr); \
        tv &= ~(bitmask); \
        tv |= ((value) << (uffs(bitmask) - 1)); \
        MSDC_WriteReg32(addr,tv); \
    } while(0)

#define MSDC_GET_FIELD(addr,bitmask,value)      \
    do {    \
        volatile kal_uint32 tv = MSDC_Reg32(addr); \
        value = ((tv & (bitmask)) >> (uffs(bitmask) - 1)); \
    } while(0)


#endif//__DRV_MSDC_REG_DBG__

#else //!defined(DRV_MSDC_OFF)

#define MSDC_WriteReg(addr,data)
#define MSDC_Reg(addr)                        drv_dummy_return()
#define MSDC_WriteReg32(addr,data)
#define MSDC_Reg32(addr)                      drv_dummy_return()
#define MSDC_WriteReg8(addr,data)
#define MSDC_Reg8(addr)                       drv_dummy_return()

#define MSDC_ClearBits(addr,data)
#define MSDC_SetBits(addr,data)
#define MSDC_ClearBits32(addr,data)
#define MSDC_SetBits32(addr,data)
#define MSDC_ClearBits8(addr,data)
#define MSDC_SetBits8(addr,data)

#define MSDC_SetData(addr,bitmask,value)
#define MSDC_SetData32(addr,bitmask,value)
#define MSDC_SetData8(addr,bitmask,value)

#endif //!defined(DRV_MSDC_OFF)

#endif  /* MSDC_REG_ADAP_H */                   

