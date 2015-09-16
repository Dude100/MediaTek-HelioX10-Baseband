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
 *    gpio_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for GPIO driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _GPIO_SW_H
#define _GPIO_SW_H

#include "drv_features_gpio.h"
#include "dcl.h"
#include "drv_comm.h"
#include "kal_general_types.h"


#if !defined(DRV_GPIO_OFF)
//#define __DRV_GPIO_REG_DBG__

#define  GPIO_6280_INVAILD_INDEX  200
#define  GPIO_6280_MIN_PIN_A      60
#define  GPIO_6280_MAX_PIN_A      67
#define  GPIO_6280_MIN_PIN_B      83
#define  GPIO_6280_MAX_PIN_B      90

#if defined(DRV_GPIO_6280_SPECIAL_SET_REG)
typedef struct MT6280_GPIO_PULL_EN_SELL_MAP_TABLE_TAG
{

	kal_uint16          pullen_sel_index;
	kal_uint16         pullen_reg_num;      // which  register
    kal_uint16        pullen_remainder;   // which bit in register
    kal_uint16        pullsel_remainder;   // which bit in register
}MT6280_GPIO_PULL_EN_SELL_MAP_Table_T;

#endif

#ifdef __DRV_GPIO_REG_DBG__

#define DRV_GPIO_WriteReg(addr,data)    DRV_DBG_WriteReg(addr,data)
#define DRV_GPIO_Reg(addr)              DRV_DBG_Reg(addr)
#define DRV_GPIO_WriteReg32(addr,data)  DRV_DBG_WriteReg32(addr,data)
#define DRV_GPIO_Reg32(addr)            DRV_DBG_Reg32(addr)
#define DRV_GPIO_WriteReg8(addr,data)   DRV_DBG_WriteReg8(addr,data)
#define DRV_GPIO_Reg8(addr)             DRV_DBG_Reg8(addr)


#define DRV_GPIO_ClearBits(addr,data)   DRV_DBG_ClearBits(addr,data)
#define DRV_GPIO_SetBits(addr,data)     DRV_DBG_SetBits(addr,data)
#define DRV_GPIO_ClearBits32(addr,data) DRV_DBG_ClearBits32(addr,data)
#define DRV_GPIO_SetBits32(addr,data)   DRV_DBG_SetBits32(addr,data)
#define DRV_GPIO_ClearBits8(addr,data)  DRV_DBG_ClearBits8(addr,data)
#define DRV_GPIO_SetBits8(addr,data)    DRV_DBG_SetBits8(addr,data)

#define DRV_GPIO_SetData(addr, bitmask, value)     DRV_DBG_SetData(addr, bitmask, value)
#define DRV_GPIO_SetData32(addr, bitmask, value)   DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_GPIO_SetData8(addr, bitmask, value)    DRV_DBG_SetData8(addr, bitmask, value)

#else //__DRV_GPIO_REG_DBG__

#define DRV_GPIO_WriteReg(addr,data)    DRV_WriteReg(addr,data)
#define DRV_GPIO_Reg(addr)              DRV_Reg(addr)
#define DRV_GPIO_WriteReg32(addr,data)  DRV_WriteReg32(addr,data)
#define DRV_GPIO_Reg32(addr)            DRV_Reg32(addr)
#define DRV_GPIO_WriteReg8(addr,data)   DRV_WriteReg8(addr,data)
#define DRV_GPIO_Reg8(addr)             DRV_Reg8(addr)


#define DRV_GPIO_ClearBits(addr,data)   DRV_ClearBits(addr,data)
#define DRV_GPIO_SetBits(addr,data)     DRV_SetBits(addr,data)
#define DRV_GPIO_ClearBits32(addr,data) DRV_ClearBits32(addr,data)
#define DRV_GPIO_SetBits32(addr,data)   DRV_DBGD_SetBits32(addr,data)
#define DRV_GPIO_ClearBits8(addr,data)  DRV_ClearBits8(addr,data)
#define DRV_GPIO_SetBits8(addr,data)    DRV_SetBits8(addr,data)

#define DRV_GPIO_SetData(addr, bitmask, value)     DRV_SetData(addr, bitmask, value)
#define DRV_GPIO_SetData32(addr, bitmask, value)   DRV_SetData32(addr, bitmask, value)
#define DRV_GPIO_SetData8(addr, bitmask, value)    DRV_SetData8(addr, bitmask, value)

#endif //__DRV_GPIO_REG_DBG__

#else //#if !defined(DRV_GPIO_OFF)

#define DRV_GPIO_WriteReg(addr,data)  
#define DRV_GPIO_Reg(addr)               drv_dummy_return()
#define DRV_GPIO_WriteReg32(addr,data)
#define DRV_GPIO_Reg32(addr)             drv_dummy_return()
#define DRV_GPIO_WriteReg8(addr,data) 
#define DRV_GPIO_Reg8(addr)              drv_dummy_return()


#define DRV_GPIO_ClearBits(addr,data) 
#define DRV_GPIO_SetBits(addr,data)   
#define DRV_GPIO_ClearBits32(addr,data)
#define DRV_GPIO_SetBits32(addr,data) 
#define DRV_GPIO_ClearBits8(addr,data)
#define DRV_GPIO_SetBits8(addr,data)  

#define DRV_GPIO_SetData(addr, bitmask, value)
#define DRV_GPIO_SetData32(addr, bitmask, value)
#define DRV_GPIO_SetData8(addr, bitmask, value)

#endif //#if !defined(DRV_GPIO_OFF)

extern 	 kal_bool  Is_6280_SPEC_GPIO( kal_uint16 pin);
extern  kal_uint16  get_6280_spec_index( kal_uint16	pin_num);
extern void GPIO_MD_InitIO(char direction, char port);
extern void GPIO_MD_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern DCL_UINT32 MD_get_gpio_pin_number(DCL_UINT32 flags);



extern void GPIO_InitIO(char direction, char port);
extern char GPIO_ReadIO(char port);
extern kal_uint16 GPIO_ReadAll(void);
extern void GPIO_WriteIO(char data, char port);
extern void GPIO_WriteAll(kal_uint16 write_data);
extern char GPIO_ReturnMode(char port);
extern char GPO_ReturnMode(char port);
extern char GPIO_ReturnDir(char port);
extern char GPIO_ReturnDout(char port);
extern char GPO_ReturnDout(char port);
extern void GPO_WriteIO(char data,char port);
extern void GPO_WriteAll(kal_uint16 write_data);
extern void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern void initGPIO(void);
//extern void GPIO_init_(void);
extern void GPIO_ALLIO(void);
extern void GPIO_PullenSetup(kal_uint16 pin, kal_bool enable);
extern void GPIO_DinvSetup(kal_uint16 pin, kal_bool enable);
extern void GPIO_SetDebugMode(kal_bool enable);
extern void GPIO_SetClkOut(char clk_num, gpio_clk_mode mode);
extern void GPIO_SetClkDiv(char clk_num, gpio_clk_div div);   
extern void GPIO_PullSelSetup(kal_uint16 pin, kal_bool pull_up);
extern void GPIO_TMDir(kal_bool pad_oe);
#ifdef __CUST_NEW__
extern void GPIO_ModeSetup_FAST(kal_uint16 pin, kal_uint16 conf_dada);
extern void GPIO_InitIO_FAST(char direction, char port);
extern char GPIO_ReadIO_FAST(char port);
extern void GPIO_WriteIO_FAST(char data, char port);
#endif/* __CUST_NEW__ */
extern void GPIO_Check_MultiPins(GPIOCheckStruct *check_ptr, kal_uint32 pin_cnt);
extern void GPIO_WriteIO_Force(char data, char port);
extern void GPIO_WriteIO_FAST2(char data, kal_uint16 no, kal_uint16 remainder_shift);
#endif

