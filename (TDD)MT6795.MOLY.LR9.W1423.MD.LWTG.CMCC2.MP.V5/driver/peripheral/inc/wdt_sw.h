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
 *    wdt_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for WDT driver.
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
#ifndef WDT_SW_H
#define WDT_SW_H

#include "drv_features_wdt.h"
#include "drv_comm.h"
#include "wdt_hw.h"
//#include "wdt_hw.h"
//#include "kal_non_specific_general_types.h"

/*Must include "drv_comm.h*/
#define WDT_RSTINTERVAL_VALUE    0xffa

#if defined(DRV_WDT_RETN_REG)// because add 32bit retention register,SW reset and restart register also from 16bit to 32bit
	#define WDT_Restart()  DRV_WriteReg32(WDT_RESTART,WDT_RESTART_KEY)
#else
#define WDT_Restart()  DRV_WriteReg(WDT_RESTART,WDT_RESTART_KEY)
#endif

void WDT_SetValue(kal_uint16 value);
void WDT_Enable(kal_bool en);
void WDT_EnableInterrupt(kal_bool enable);
void WDT_SetExtpol(IO_level extpol);
void WDT_SetExten(kal_bool en);
void WDT_Config(IO_level extpol, kal_bool exten);
void WDT_Enable_Debug_Mode(kal_bool en);
void WDT_init(void);
void DRV_RESET(void);
void DRV_ABN_RESET(void);
void WDT_Restart2(void);

#if defined(DRV_WDT_RETN_REG)
void WDT_Write_RETN_FLAG(kal_uint8 flag);
void WDT_SET_RETN_FLAG(kal_uint8 flag);
void WDT_CLR_RETN_FLAG(kal_uint8 flag);
kal_uint8 WDT_Read_RETN_FLAG(void);
void WDT_Write_RETN_DAT0(kal_uint32 value);
kal_uint32 WDT_Read_RETN_DAT0(void);
#endif



#if !defined(DRV_WDT_OFF)
#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_WDT_REG_DBG__)
#define DRV_WDT_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_WDT_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_WDT_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_WDT_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_WDT_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_WDT_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_WDT_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_WDT_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_WDT_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_WDT_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_WDT_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_WDT_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_WDT_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_WDT_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_WDT_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_WDT_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_WDT_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_WDT_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_WDT_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_WDT_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_WDT_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_WDT_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_WDT_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_WDT_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_WDT_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_WDT_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_WDT_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_WDT_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_WDT_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_WDT_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_WDT_REG_DBG__)

#else // !defined(DRV_WDT_OFF)

#define DRV_WDT_WriteReg(addr,data)
#define DRV_WDT_Reg(addr)                        drv_dummy_return()
#define DRV_WDT_WriteReg32(addr,data)
#define DRV_WDT_Reg32(addr)                      drv_dummy_return()
#define DRV_WDT_WriteReg8(addr,data)
#define DRV_WDT_Reg8(addr)                       drv_dummy_return()
#define DRV_WDT_ClearBits(addr,data)
#define DRV_WDT_SetBits(addr,data)
#define DRV_WDT_SetData(addr, bitmask, value)
#define DRV_WDT_ClearBits32(addr,data)
#define DRV_WDT_SetBits32(addr,data)
#define DRV_WDT_SetData32(addr, bitmask, value)
#define DRV_WDT_ClearBits8(addr,data)
#define DRV_WDT_SetBits8(addr,data)
#define DRV_WDT_SetData8(addr, bitmask, value)

#endif //!defined(DRV_WDT_OFF)
#endif

