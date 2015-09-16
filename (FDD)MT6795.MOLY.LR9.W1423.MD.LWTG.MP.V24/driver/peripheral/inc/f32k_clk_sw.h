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
 *    f32k_clk_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for F32K_CLK driver.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef F32K_CLK_SW_H
#define F32K_CLK_SW_H

#include "kal_general_types.h"
#include "drv_comm.h"

#if defined(DRV_F32K_FQMTR_AS_6255)
#define IDLE_VAL_WITH_WINSET_LV1        (0x319)       //13M meter 32K with winset=1
#define IDLE_VAL_WITH_WINSET_LV2        (0x1a59)      //13M meter 32K with winset=16
#elif defined(DRV_F32K_FQMTR_AS_6250)
#define IDLE_VAL_WITH_WINSET_LV1        (0x52)        //26M meter 32K with winset=0xffff
#endif

#if defined(DRV_F32K_FQMTR_AS_6280)
// 26MHZ = PAD_32K clock*(1+-2.5%) *  FQMTR_data/(0x1)
#define FQMTR_PAD32K_LOWER_BOUND        (774)           
#define FQMTR_PAD32K_UPPER_BOUND        (814)
#endif

#define F32K_EOSCCALI_MAX    (0x1f)
#define F32K_EOSCCALI_MIN    (0x0)
// =================================================================
// Exported APIs, used by modules other than driver level functions
#if defined(DRV_F32K_INTERNAL_32K) 
extern void F32K_XOSC32_EMB_setting(void);
#endif //#if defined(DRV_F32K_INTERNAL_32K) 


#if !defined(__MINI_BOOTLOADER__)
#if defined(DRV_F32K_INTERNAL_32K) || defined(DRV_F32K_SWITCH_32K)   
extern kal_bool F32K_Query_Is_XOSC32(void);
#endif //#if defined(DRV_F32K_INTERNAL_32K) || defined(DRV_F32K_SWITCH_32K)  


#if defined(DRV_F32K_INTERNAL_32K) 
extern kal_uint16 F32K_EOSC32_trimming(void);
#endif //#if defined(DRV_F32K_INTERNAL_32K) 

#if defined(DRV_F32K_SWITCH_32K)   
extern void F32K_Switch_32K_setting(void);
#endif //#if defined(DRV_F32K_SWITCH_32K)

#endif //#if !defined(__MINI_BOOTLOADER__)

#if !defined(DRV_F32K_CLK_OFF)
#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_F32K_CLK_REG_DBG__)
#define DRV_F32K_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_F32K_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_F32K_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_F32K_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_F32K_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_F32K_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_F32K_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_F32K_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_F32K_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_F32K_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_F32K_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_F32K_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_F32K_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_F32K_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_F32K_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_F32K_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_F32K_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_F32K_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_F32K_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_F32K_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_F32K_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_F32K_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_F32K_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_F32K_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_F32K_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_F32K_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_F32K_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_F32K_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_F32K_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_F32K_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_F32K_CLK_REG_DBG__)

#else //!defined(DRV_F32K_CLK_OFF)

#define DRV_F32K_WriteReg(addr,data)            
#define DRV_F32K_Reg(addr)                      drv_dummy_return()
#define DRV_F32K_WriteReg32(addr,data)          
#define DRV_F32K_Reg32(addr)                    drv_dummy_return()
#define DRV_F32K_WriteReg8(addr,data)           
#define DRV_F32K_Reg8(addr)                     drv_dummy_return()
#define DRV_F32K_ClearBits(addr,data)           
#define DRV_F32K_SetBits(addr,data)             
#define DRV_F32K_SetData(addr, bitmask, value)  
#define DRV_F32K_ClearBits32(addr,data)         
#define DRV_F32K_SetBits32(addr,data)           
#define DRV_F32K_SetData32(addr, bitmask, value)
#define DRV_F32K_ClearBits8(addr,data)          
#define DRV_F32K_SetBits8(addr,data)            
#define DRV_F32K_SetData8(addr, bitmask, value) 

#endif //!defined(DRV_F32K_CLK_OFF)


#endif //#ifndef F32K_CLK_SW_H
 
