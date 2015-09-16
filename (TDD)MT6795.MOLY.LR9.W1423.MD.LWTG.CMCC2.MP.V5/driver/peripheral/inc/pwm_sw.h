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
 *    pwm_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for PWM driver.
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
#ifndef PWM_SW_H
#define PWM_SW_H

#include "drv_features_pwm.h"
#include "rwg_sw.h"
#include "kal_general_types.h"
#include "dcl.h"
#include "drv_comm.h"

#if !defined(DRV_PWM_RWG)

//this should move to pwm_sw.h
#if defined(DRV_PWM_PWM2)
#if defined(DRV_PWM_PWM3)
#if defined(DRV_PWM_PWM4)
#define PWM_COUNT 4
#else //defined(DRV_PWM_PWM4)
#define PWM_COUNT 3
#endif//defined(DRV_PWM_PWM4)
#else //defined(DRV_PWM_PWM3)
#define PWM_COUNT 2
#endif //defined(DRV_PWM_PWM3)
#else //defined(DRV_PWM_PWM2)
#define PWM_COUNT 1
#endif//defined(DRV_PWM_PWM2)

typedef enum 
{
	pwmclk_1MHZ=0,
	pwmclk_2MHZ,
	pwmclk_4MHZ,
	pwmclk_8MHZ 
}PWMClock_DIV;

typedef enum 
{
	pwmclk_13M=0,
	pwmclk_32k
}PWMClock_SEL;

typedef enum 
{
	PWM1=0,
	PWM2,
	PWM3,
	PWM4
}PWM_TYPE;

typedef void (*DCL_PWM_INIT)(void);
typedef void (*DCL_PWM_CLK_INIT)(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint32 clk_div);
typedef void (*DCL_PWM_START)(DCL_UINT8 owner, DCL_UINT32 pwm_num);
typedef void (*DCL_PWM_STOP)(DCL_UINT8 owner, DCL_UINT32 pwm_num);
typedef void (*DCL_PWM_CONFIG_OLD)(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint8 duty);
typedef DCL_UINT8 (*DCL_PWM_GETCURRENT_LEVEL)(DCL_UINT8 pwm_num);
typedef DCL_UINT32(*DCL_PWM_GETCURRENT_FREQ)(DCL_UINT8 pwm_num);
typedef DCL_UINT8 (*DCL_PWM_GETCURRENT_DUTY)(DCL_UINT8 pwm_num);

typedef struct
{
   DCL_PWM_INIT                  pwmInit;
   DCL_PWM_CLK_INIT              pwmClkInit;
   DCL_PWM_START                 pwmStart;
   DCL_PWM_STOP                  pwmStop;
   DCL_PWM_GETCURRENT_LEVEL      pwmGetCurrent_level;
   DCL_PWM_GETCURRENT_FREQ       pwmGetCurrent_Freq;
   DCL_PWM_GETCURRENT_DUTY       pwmGetCurrent_Duty;
   DCL_PWM_CONFIG_OLD            pwmConfigOld;
}PWMDriver_t;

extern void DCL_PWM_Init(void);
extern void DCL_PWM_SetClock(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint32 clk_div);
extern void DCL_PWM_Start(kal_uint8 owner, kal_uint32 pwm_num);
extern void DCL_PWM_Stop(kal_uint8 owner, kal_uint32 pwm_num);
extern void DCL_PWM_ConfigOld(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint8 duty);
extern kal_uint8 DCL_PWM_GetCurrent_Level(kal_uint8 pwm_num);
extern kal_uint8 DCL_PWM_GetCurrentDuty(kal_uint8 pwm_num);
extern kal_uint32 DCL_PWM_GetCurrentFreq(kal_uint8 pwm_num);


extern void PWM_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div);
extern void PWM1_Configure(kal_uint32 freq, kal_uint8 duty);
extern void PWM1_Start(void);
extern void PWM1_Stop(void);
extern kal_uint8  PWM1_GetCurrentLevel(void);
extern kal_uint8  PMW1_GetCurrentDuty(void);
extern kal_uint32 PMW1_GetCurrentFreq(void);
#if defined(DRV_PWM_PWM2)
   extern void PWM2_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div);
   extern void PWM2_Configure(kal_uint32 freq, kal_uint8 duty);
   extern void PWM2_Start(void);
   extern void PWM2_Stop(void);
   extern kal_uint8  PWM2_GetCurrentLevel(void);
   extern kal_uint8  PMW2_GetCurrentDuty(void);
   extern kal_uint32 PMW2_GetCurrentFreq(void);
#if defined(DRV_PWM_PWM3)
   extern void PWM3_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div);
   extern void PWM3_Configure(kal_uint32 freq, kal_uint8 duty);
   extern void PWM3_Start(void);
   extern void PWM3_Stop(void);
   extern kal_uint8  PWM3_GetCurrentLevel(void);
   extern kal_uint8  PMW3_GetCurrentDuty(void);
   extern kal_uint32 PMW3_GetCurrentFreq(void);
#if defined(__DRV_PMU53_SPEC_V2__)
extern void PWM3_Output_High(void);
#endif //#if defined(__DRV_PMU53_SPEC_V2__)
#if defined(DRV_PWM_PWM4)
   extern void PWM4_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div);
   extern void PWM4_Configure(kal_uint32 freq, kal_uint8 duty);
   extern void PWM4_Start(void);
   extern void PWM4_Stop(void);
   extern kal_uint8  PWM4_GetCurrentLevel(void);
   extern kal_uint8  PMW4_GetCurrentDuty(void);
   extern kal_uint32 PMW4_GetCurrentFreq(void);
#endif   /* DRV_PWM_PWM4 */

#endif   /* DRV_PWM_PWM3 */
#endif   /* DRV_PWM_PWM2 */

#endif  /* !defined(DRV_PWM_RWG) */


#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_PWM_REG_DBG__)
#define DRV_PWM_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_PWM_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_PWM_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_PWM_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_PWM_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_PWM_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_PWM_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_PWM_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_PWM_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_PWM_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_PWM_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_PWM_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_PWM_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_PWM_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_PWM_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_PWM_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_PWM_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_PWM_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_PWM_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_PWM_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_PWM_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_PWM_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_PWM_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_PWM_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_PWM_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_PWM_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_PWM_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_PWM_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_PWM_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_PWM_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_PWM_REG_DBG__)
#endif

