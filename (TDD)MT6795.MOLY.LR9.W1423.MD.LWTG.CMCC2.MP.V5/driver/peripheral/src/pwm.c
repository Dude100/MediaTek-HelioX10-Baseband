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
 *    pwm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the PWM driver.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if 1
#include "drv_features_pwm.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "pwm_hw.h"
#include "pwm_sw.h"
#include "drvpdn.h"
//#include "custom_hw_default.h"
//#include "uart_sw.h"
#include "kal_general_types.h"
#include "dcl.h"
#define __DCL_PWM_INTERFACE__
//#include "drvtest.h"
#if !defined(DRV_PWM_NOT_EXIST)
/*****************************************************************************/
/*****************************************************************************/

 #if defined(MT6256) || defined(MT6255) 
       #define  HW_MISC  (CONFIG_base + 0x100)  //CONFIG_base=0x80000000
#endif
/******************************************************************************/
/*****************************************************************************/
#if !defined(DRV_PWM_RWG)
#ifndef DRV_PWM_OFF
#if defined(__DCL_PWM_INTERFACE__)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_PWM_PWM3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if defined(DRV_PWM_PWM3)
#if defined(DRV_PWM_PWM4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if defined(DRV_PWM_PWM4)
#endif

kal_uint8  PWM1_CTRL_CLK = 0;
kal_uint8  PWM2_CTRL_CLK = 0;

kal_uint8	PWM_LEVEL_SAVE[4];
kal_uint32      PWM_FRE_SAVE[4];
kal_uint8	PWM_DUTY_SAVE[4];


#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
extern void L1SM_SleepDisable(kal_uint8 handle);
extern void L1SM_SleepEnable(kal_uint8 handle);
extern kal_uint8 L1SM_GetHandle(void);

kal_uint8 PWM1_PDNhandle, PWM2_PDNhandle;
#if defined(DRV_PWM_PWM3)
kal_uint8 PWM3_PDNhandle;
#endif //#if defined(DRV_PWM_PWM3)
#endif
#if defined(DRV_PWM_PWM4)
kal_uint8 PWM4_PDNhandle;
#endif //#if defined(DRV_PWM_PWM4)
#else

static kal_uint8  PWM1_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint8  PWM2_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint32 PWM1_FRE_SAVE;   /*for MMI usage*/
static kal_uint32 PWM2_FRE_SAVE;   /*for MMI usage*/
static kal_uint8  PWM1_DUTY_SAVE;   /*for MMI usage*/
static kal_uint8  PWM2_DUTY_SAVE;   /*for MMI usage*/
	
static kal_uint8  PWM1_CTRL_CLK = 0;
static kal_uint8  PWM2_CTRL_CLK = 0;	
#if defined(DRV_PWM_PWM3)
static kal_uint8  PWM3_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint32 PWM3_FRE_SAVE;   /*for MMI usage*/
static kal_uint8  PWM3_DUTY_SAVE;   /*for MMI usage*/
#endif //#if defined(DRV_PWM_PWM3)
#if defined(DRV_PWM_PWM4)
static kal_uint8  PWM4_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint32 PWM4_FRE_SAVE;   /*for MMI usage*/
static kal_uint8  PWM4_DUTY_SAVE;   /*for MMI usage*/
#endif //#if defined(DRV_PWM_PWM4)

#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
static kal_uint8 PWM1_PDNhandle, PWM2_PDNhandle;
#if defined(DRV_PWM_PWM3)
static kal_uint8 PWM3_PDNhandle;
#endif //#if defined(DRV_PWM_PWM3)
#if defined(DRV_PWM_PWM4)
static kal_uint8 PWM4_PDNhandle;
#endif //#if defined(DRV_PWM_PWM4)

	#endif
#endif

PWMDriver_t pwm_driver = {
	(DCL_PWM_INIT)DCL_PWM_Init,
	(DCL_PWM_CLK_INIT)DCL_PWM_SetClock,
	(DCL_PWM_START)DCL_PWM_Start,
	(DCL_PWM_STOP)DCL_PWM_Stop,
	(DCL_PWM_GETCURRENT_LEVEL)DCL_PWM_GetCurrent_Level,
	(DCL_PWM_GETCURRENT_FREQ)DCL_PWM_GetCurrentFreq,
	(DCL_PWM_GETCURRENT_DUTY)DCL_PWM_GetCurrentDuty,
	(DCL_PWM_CONFIG_OLD)DCL_PWM_ConfigOld,
	//(DCL_PWM_CONFIGURE)DCL_PWM_Configure,
};

#if defined(DRV_PWM_PWM4)
void (*pwm_start[4])(void)={PWM1_Start,PWM2_Start,PWM3_Start,PWM4_Start};
void (*pwm_stop[4])(void)={PWM1_Stop,PWM2_Stop,PWM3_Stop,PWM4_Stop};
void (*pwm_init[4])(PWMClock_SEL,PWMClock_DIV)={PWM_Init,PWM2_Init,PWM3_Init,PWM4_Init};
void (*pwm_configure[4])(kal_uint32,kal_uint8)={PWM1_Configure,PWM2_Configure,PWM3_Configure,PWM4_Configure};
//kal_uint8 (*pwm_get_current_level[4])(void)={PWM1_GetCurrentLevel,PWM2_GetCurrentLevel,PWM3_GetCurrentLevel,PWM4_GetCurrentLevel};
//kal_uint8 (*pwm_get_current_duty[4])(void)={PMW1_GetCurrentDuty,PMW2_GetCurrentDuty,PMW3_GetCurrentDuty,PMW4_GetCurrentDuty};
//kal_uint32 (*pwm_get_current_freq[4])(void)={PMW1_GetCurrentFreq,PMW2_GetCurrentFreq,PMW3_GetCurrentFreq,PMW4_GetCurrentFreq};
#elif defined(DRV_PWM_PWM3) && !defined(DRV_PWM_PWM4)
void (*pwm_start[3])(void)={PWM1_Start,PWM2_Start,PWM3_Start};
void (*pwm_stop[3])(void)={PWM1_Stop,PWM2_Stop,PWM3_Stop};
void (*pwm_init[3])(PWMClock_SEL,PWMClock_DIV)={PWM_Init,PWM2_Init,PWM3_Init};
void (*pwm_configure[3])(kal_uint32,kal_uint8)={PWM1_Configure,PWM2_Configure,PWM3_Configure};
//kal_uint8 (*pwm_get_current_level[3])(void)={PWM1_GetCurrentLevel,PWM2_GetCurrentLevel,PWM3_GetCurrentLevel};
//kal_uint8 (*pwm_get_current_duty[3])(void)={PMW1_GetCurrentDuty,PMW2_GetCurrentDuty,PMW3_GetCurrentDuty};
//kal_uint32 (*pwm_get_current_freq[3])(void)={PMW1_GetCurrentFreq,PMW2_GetCurrentFreq,PMW3_GetCurrentFreq};
#elif defined(DRV_PWM_PWM2) && !defined(DRV_PWM_PWM3)
void (*pwm_start[2])(void)={PWM1_Start,PWM2_Start};
void (*pwm_stop[2])(void)={PWM1_Stop,PWM2_Stop};
void (*pwm_init[2])(PWMClock_SEL,PWMClock_DIV)={PWM_Init,PWM2_Init};
void (*pwm_configure[2])(kal_uint32,kal_uint8)={PWM1_Configure,PWM2_Configure};
//kal_uint8 (*pwm_get_current_level[2])(void)={PWM1_GetCurrentLevel,PWM2_GetCurrentLevel};
//kal_uint8 (*pwm_get_current_duty[2])(void)={PMW1_GetCurrentDuty,PMW2_GetCurrentDuty};
//kal_uint32 (*pwm_get_current_freq[2])(void)={PMW1_GetCurrentFreq,PMW2_GetCurrentFreq};
#elif defined(DRV_PWM_PWM1) && !defined(DRV_PWM_PWM2) && !defined(DRV_PWM_PWM3)
void (*pwm_start[1])(void)={PWM1_Start};
void (*pwm_stop[1])(void)={PWM1_Stop};
void (*pwm_init[1])(PWMClock_SEL,PWMClock_DIV)={PWM_Init};
void (*pwm_configure[1])(kal_uint32,kal_uint8)={PWM1_Configure};
#endif

void DCL_PWM_Init()
{
	 #if defined(MT6256) || defined(MT6255)       //modified by zhanguo  on 8.31,2011
	kal_uint32 pwm_source_setting;
	kal_uint32 savedMask;
	savedMask = SaveAndSetIRQMask();
      pwm_source_setting = DRV_PWM_Reg32(HW_MISC);
	pwm_source_setting = pwm_source_setting |(1<<15)|(1<<17)|(1<<18);
	pwm_source_setting = pwm_source_setting & (0<<14)&(0<<16)&(0<<19);
	  DRV_PWM_WriteReg32(HW_MISC ,pwm_source_setting);
	  RestoreIRQMask(savedMask);
#endif   //kal_prompt_trace(MOD_DRV_HISR,"PWM Init");
}
/*
void DCL_PWM_Configure(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 mode, void *para)
{
	kal_prompt_trace(MOD_DRV_HISR,"PWM configure");
}
*/
void DCL_PWM_SetClock(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint32 clk_div)
{
	//kal_prompt_trace(MOD_DRV_HISR,"PWM set clock sources %d and Div %d",clk_sel,clk_div);
	//PWM_Init(clk_sel,clk_div);
	pwm_init[pwm_num](clk_sel,clk_div);
}

void DCL_PWM_Start(kal_uint8 owner, kal_uint32 pwm_num)
{
	//kal_prompt_trace(MOD_DRV_HISR,"PWM %d is start by %d",pwm_num,owner);
	pwm_start[pwm_num]();
}

void DCL_PWM_Stop(kal_uint8 owner, kal_uint32 pwm_num)
{
	//kal_prompt_trace(MOD_DRV_HISR,"PWM %d is stop by %d",pwm_num,owner);
	pwm_stop[pwm_num]();
}
void DCL_PWM_ConfigOld(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint8 duty)
{
	//kal_prompt_trace(MOD_DRV_HISR,"PWM %d is set to freq=%d duty=%d by %d",pwm_num,freq,duty,owner);
	//module_test_print(" pwm is Configure %d ,%d \r\n",freq,duty);
	pwm_configure[pwm_num](freq,duty);
}
kal_uint8 DCL_PWM_GetCurrent_Level(kal_uint8 pwm_num)
{
	return PWM_LEVEL_SAVE[pwm_num];
}
kal_uint8 DCL_PWM_GetCurrentDuty(kal_uint8 pwm_num)
{
	return PWM_DUTY_SAVE[pwm_num];
}
kal_uint32 DCL_PWM_GetCurrentFreq(kal_uint8 pwm_num)
{
	return PWM_FRE_SAVE[pwm_num];
}

/*
* FUNCTION                                                            
*	PWM_Init
*
* DESCRIPTION                                                           
*   	PWM initial function
*
* CALLS  
*	It is called before access the PWM.
*
* PARAMETERS
*	Clock:	pwmclk_1MHZ,
*		pwmclk_2MHZ,
*		pwmclk_4MHZ,
*		pwmclk_8MHZ 
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void PWM_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div)
{
   /*clk_sel only actived in MT6205B or later*/
	kal_uint16 tmp;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
	PWM1_PDNhandle = L1SM_GetHandle();
	#endif
	tmp = DRV_PWM_Reg(PWM1_CTRL);
	switch(Clock_div)
	{
	   case pwmclk_1MHZ:
	      #if defined(DRV_PWM_NONE_CLK)
	      PWM1_CTRL_CLK = 0;
	      #endif
	      tmp |= PWM_CTRL_CLK_1;
	      break;
	      
	   case pwmclk_2MHZ:
	      #if defined(DRV_PWM_NONE_CLK)
	      tmp |= PWM_CTRL_CLK_1;
	      PWM1_CTRL_CLK = 1;
	      #else
	      tmp |= PWM_CTRL_CLK_2;
	      #endif
	      break;
      
      case pwmclk_4MHZ:
	      #if defined(DRV_PWM_NONE_CLK)
	      tmp |= PWM_CTRL_CLK_1;
	      PWM1_CTRL_CLK = 2;
	      #else
	      tmp |= PWM_CTRL_CLK_4;
	      #endif
	      break;
	      
	   case pwmclk_8MHZ:
	      #if defined(DRV_PWM_NONE_CLK)
	      tmp |= PWM_CTRL_CLK_1;
	      PWM1_CTRL_CLK = 3;
	      #else
	      tmp |= PWM_CTRL_CLK_8;
	      #endif
	      break;
	}

#if defined(DRV_PWM_CLK_SEL)
	switch(clk_sel)
	{
	   case pwmclk_13M:
	      tmp &= ~PWM_CTRL_CLKSEL;
	      break;
	      
	   case pwmclk_32k:
	      tmp |= PWM_CTRL_CLKSEL;
	      break;
	      
	   default:
	      break;
	}
#endif /*DRV_PWM_CLK_SEL*/
	DRV_PWM_WriteReg(PWM1_CTRL,tmp);
}

/*level = 1~5, level = 0, close PWM*/
/*
static void PWM_level(kal_uint8 level)
{
	 kal_uint32 range = 0;
	 
   if (level > 5)
      ASSERT(0);
   
   PWM1_LEVEL_SAVE = level;
	 range = sizeof(PWM1_Level_Info) / (sizeof(kal_uint32)*2);
	 if (level && level <= range)
   {
      PWM1_Configure(PWM1_Level_Info[level-1][0],PWM1_Level_Info[level-1][1]);
      PWM1_Start();
   }
   else
   {
      PWM1_Stop();
   }
}
*/
#if defined(DRV_PWM_PWM2)
void PWM2_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div)
{
   /*clk_sel only actived in MT6205B or later*/
	kal_uint16 tmp;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
	PWM2_PDNhandle = L1SM_GetHandle();
	#endif
	tmp = DRV_PWM_Reg(PWM2_CTRL);
	switch(Clock_div)
	{
	   case pwmclk_1MHZ:
	      #if defined(DRV_PWM_NONE_CLK)
	      PWM2_CTRL_CLK = 0;
	      #endif
	      tmp |= PWM_CTRL_CLK_1;
	      break;
	      
	   case pwmclk_2MHZ:
	      #if defined(DRV_PWM_NONE_CLK)
	      tmp |= PWM_CTRL_CLK_1;
	      PWM2_CTRL_CLK = 1;
	      #else
	      tmp |= PWM_CTRL_CLK_2;
	      #endif
	      break;
      
      case pwmclk_4MHZ:
	      #if defined(DRV_PWM_NONE_CLK)
	      tmp |= PWM_CTRL_CLK_1;
	      PWM2_CTRL_CLK = 2;
	      #else
	      tmp |= PWM_CTRL_CLK_4;
	      #endif
	      break;
	      
	   case pwmclk_8MHZ:
	      #if defined(DRV_PWM_NONE_CLK)
	      tmp |= PWM_CTRL_CLK_1;
	      PWM2_CTRL_CLK = 3;
	      #else
	      tmp |= PWM_CTRL_CLK_8;
	      #endif
	      break;
	}

	switch(clk_sel)
	{
	   case pwmclk_13M:
	      tmp &= ~PWM_CTRL_CLKSEL;
	      break;
	      
	   case pwmclk_32k:
	      tmp |= PWM_CTRL_CLKSEL;
	      break;
	      
	   default:
	      break;
	}
	DRV_PWM_WriteReg(PWM2_CTRL,tmp);
}

/*static void PWM2_level(kal_uint8 level)
{
	 kal_uint32 range = 0;
   if (level > 5)
      ASSERT(0);
   
   PWM2_LEVEL_SAVE = level;
	 range = sizeof(PWM2_Level_Info) / (sizeof(kal_uint32)*2);
	 if (level && level <= range)
   {
      PWM2_Configure(PWM2_Level_Info[level-1][0],PWM2_Level_Info[level-1][1]);
      PWM2_Start();
   }
   else
   {
      PWM2_Stop();
   }
}
*/
#endif   /*DRV_PWM_PWM2*/

void PWM1_Configure(kal_uint32 freq, kal_uint8 duty)
{
   kal_uint32 clock;
   kal_uint32 tmpMultiCLK;
   kal_uint32 tmp;
   kal_uint16 clkdiv;
   kal_uint16 reg;
   
     
   if(duty > 100)
      duty = 100;

   PWM_FRE_SAVE[0]=freq;
   PWM_DUTY_SAVE[0]=duty;

   reg = DRV_PWM_Reg(PWM1_CTRL);
#if defined(DRV_PWM_NONE_CLK)
   clkdiv = (1 << PWM1_CTRL_CLK);
#else
   clkdiv = (1 << (reg & 0x0003));
#endif
   
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   
   clock = clock/clkdiv;
   
   if(0==freq)
      tmp = clock/(freq+1);
   else 
      tmp = clock/(freq); 
   
   tmpMultiCLK = tmp<<PWM1_CTRL_CLK;
   tmpMultiCLK--;
   if(tmpMultiCLK >= 0x2000)
      tmpMultiCLK = 0x1fff;
   DRV_PWM_WriteReg(PWM1_COUNT,(kal_uint16)tmpMultiCLK);
   tmp = tmp<<PWM1_CTRL_CLK;
   tmpMultiCLK = (tmp*duty)/100;
   if(tmpMultiCLK >= 0x2000)
      tmpMultiCLK = 0x1fff;
   DRV_PWM_WriteReg(PWM1_THRESHOLD,(kal_uint16)tmpMultiCLK);
}

/*duty=50 ==> 50%*/
void PWM1_Start(void)
{
#if defined(DRV_PWM_CLK_SEL)
   kal_uint16 reg; 
   volatile kal_uint32 clock = 0;
   reg = DRV_PWM_Reg(PWM1_CTRL);
   clock = clock + 32000;//dummy assignment for build warning   
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
   if(clock == 13000000)
      L1SM_SleepDisable(PWM1_PDNhandle);
   #endif   
#if defined(__OLD_PDN_ARCH__)
   //DRV_PWM_WriteReg(DRVPDN_CON1_CLR,DRVPDN_CON1_PWM);
   #if defined(__OLD_PDN_DEFINE__)
   DRV_PWM_WriteReg(DRVPDN_CON1_CLR,DRVPDN_CON1_PWM);
   #elif defined(__CLKG_DEFINE__)
   DRV_PWM_WriteReg(CG_CLR0,CG_CON0_PWM);
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
   PDN_CLR(PDN_PWM);
#endif //#if defined(__OLD_PDN_ARCH__)
#else /*!(MT6205B,MT6218, MT6218B, MT6219, MT6217, MT6228,MT6229)*/
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   //DRV_PWM_Reg(DRVPDN_CON1) &= ~DRVPDN_CON1_PWM;
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
   DRV_PWM_ClearBits(DRVPDN_CON1, DRVPDN_CON1_PWM)
   //DRV_PWM_Reg(DRVPDN_CON1) &= ~DRVPDN_CON1_PWM;
   #elif defined(__CLKG_DEFINE__)
   DRV_PWM_WriteReg(CG_CLR0,CG_CON0_PWM);
   #endif // #if defined(__OLD_PDN_DEFINE__)
   RestoreIRQMask(savedMask);
#else //#if defined(__OLD_PDN_ARCH__)
   PDN_CLR(PDN_PWM);
#endif //#if defined(__OLD_PDN_ARCH__)
#endif   /*DRV_PWM_CLK_SEL*/
}

void PWM1_Stop(void)
{
#if defined(DRV_PWM_CLK_SEL)
   kal_uint16 reg; 
   volatile kal_uint32 clock = 0;
   reg = DRV_PWM_Reg(PWM1_CTRL);
   clock++;//dummy assignment for build warning   
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
#if defined(__OLD_PDN_ARCH__)
   //DRV_PWM_WriteReg(DRVPDN_CON1_SET,DRVPDN_CON1_PWM);
   #if defined(__OLD_PDN_DEFINE__)
   DRV_PWM_WriteReg(DRVPDN_CON1_SET,DRVPDN_CON1_PWM);
   #elif defined(__CLKG_DEFINE__)
   DRV_PWM_WriteReg(CG_SET0,CG_CON0_PWM);
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
   PDN_SET(PDN_PWM);   
#endif //#if defined(__OLD_PDN_ARCH__)

#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
   if(clock == 13000000)   
      L1SM_SleepEnable(PWM1_PDNhandle);
   #endif    
#else /*!(DRV_PWM_CLK_SEL)*/
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
#if defined(__OLD_PDN_ARCH__)
   //DRV_PWM_Reg(DRVPDN_CON1) |= DRVPDN_CON1_PWM;
   #if defined(__OLD_PDN_DEFINE__)
   DRV_PWM_SetBits(DRVPDN_CON1, DRVPDN_CON1_PWM)
   //DRV_PWM_Reg(DRVPDN_CON1) |= DRVPDN_CON1_PWM;
   #elif defined(__CLKG_DEFINE__)
   DRV_PWM_WriteReg(CG_SET0,CG_CON0_PWM);
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
   PDN_SET(PDN_PWM);
#endif //#if defined(__OLD_PDN_ARCH__)
   RestoreIRQMask(savedMask);
#endif   /*DRV_PWM_CLK_SEL*/
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if defined(DRV_PWM_PWM2)
void PWM2_Configure(kal_uint32 freq, kal_uint8 duty)
{
   volatile kal_uint32 clock;
   kal_uint32 tmp;
   kal_uint32 tmpMultiCLK;
   kal_uint16 clkdiv;
   kal_uint16 reg;
   

   if(duty > 100)
      duty = 100;
  // PWM2_FRE_SAVE=freq;
  // PWM2_DUTY_SAVE=duty;
  PWM_FRE_SAVE[1]=freq;
  PWM_DUTY_SAVE[1]=duty;
   reg = DRV_PWM_Reg(PWM2_CTRL);
   
#if defined(DRV_PWM_NONE_CLK)
   clkdiv = (1 << PWM2_CTRL_CLK);
#else
   clkdiv = (1 << (reg & 0x0003));
#endif   
   
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   
   clock = clock/clkdiv;
   
   if(0==freq)
      tmp = clock/(freq+1);
   else 
      tmp = clock/(freq); 
   
   tmpMultiCLK = tmp<<PWM2_CTRL_CLK;
   tmpMultiCLK--;
   if(tmpMultiCLK >= 0x2000)
      tmpMultiCLK = 0x1fff;
   DRV_PWM_WriteReg(PWM2_COUNT,(kal_uint16)tmpMultiCLK);
   tmp = tmp<<PWM2_CTRL_CLK;
   tmpMultiCLK = (tmp*duty)/100;
   if(tmpMultiCLK >= 0x2000)
      tmpMultiCLK = 0x1fff;
   DRV_PWM_WriteReg(PWM2_THRESHOLD,(kal_uint16)tmpMultiCLK);
}

/*duty=50 ==> 50%*/
void PWM2_Start(void)
{
   kal_uint16 reg; 
   volatile kal_uint32 clock = 0;
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__) && !defined(__UBL__)
   kal_uint32 itmp;
   #endif
   #endif
   
   reg = DRV_PWM_Reg(PWM2_CTRL);
   clock = 32000;//dummy assignment for build warning   
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
   if(clock == 13000000)   
      L1SM_SleepDisable(PWM2_PDNhandle);
   #endif   
   //DRV_PWM_WriteReg(DRVPDN_CON1_CLR,DRVPDN_CON1_PWM2);
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
   DRV_PWM_WriteReg(DRVPDN_CON1_CLR,DRVPDN_CON1_PWM2);
   #elif defined(__CLKG_DEFINE__)
   ASSERT(0);
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
   PDN_CLR(PDN_PWM2);
#endif //#if defined(__OLD_PDN_ARCH__)
   /*to cover HW issue*/
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__) && !defined(__UBL__)
   itmp = swdbg_pwr_up();
   #endif
   #endif
}

void PWM2_Stop(void)
{
   kal_uint16 reg; 
   volatile kal_uint32 clock = 0;
   reg = DRV_PWM_Reg(PWM2_CTRL);
   clock = 32000;//dummy assignment for build warning   
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
   if(clock == 13000000)         
      L1SM_SleepEnable(PWM2_PDNhandle);
   #endif   
#if defined(__OLD_PDN_ARCH__)
   //DRV_PWM_WriteReg(DRVPDN_CON1_SET,DRVPDN_CON1_PWM2);
   #if defined(__OLD_PDN_DEFINE__)
   DRV_PWM_WriteReg(DRVPDN_CON1_SET,DRVPDN_CON1_PWM2);
   #elif defined(__CLKG_DEFINE__)
   ASSERT(0);
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
   PDN_SET(PDN_PWM2);
#endif //#if defined(__OLD_PDN_ARCH__)
   #if defined(DRV_PWM_PWM2_SWDBG)
   #if !defined(__FUE__) && !defined(__UBL__)
   swdbg_pwr_down();
   #endif
   #endif
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif   /*DRV_PWM_PWM2*/


#if defined(DRV_PWM_PWM3)

#if defined(__DRV_PMU53_SPEC_V2__)
void PWM3_Output_High(void)
{
   DRV_PWM_WriteReg32(PWM3_CTRL, PWM_CTRL_CLK_1 | PWM_CTRL_CLKSEL);
   DRV_PWM_WriteReg(PWM3_COUNT,0);
   DRV_PWM_WriteReg(PWM3_THRESHOLD,1);
   
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
   DRV_PWM_WriteReg(DRVPDN_CON3_CLR,DRVPDN_CON3_PWM3);
   #elif defined(__CLKG_DEFINE__)
   ASSERT(0);
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
   PDN_CLR(PDN_PWM3);
#endif //#if defined(__OLD_PDN_ARCH__)
}
#endif //#if defined(__DRV_PMU53_SPEC_V2__)

void PWM3_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div)
{
   /*clk_sel only actived in MT6205B or later*/
	kal_uint16 tmp;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
	PWM3_PDNhandle = L1SM_GetHandle();
	#endif
#if defined(__DRV_PMU53_SPEC_V2__)
   return;
#endif //#if defined(__DRV_PMU53_SPEC_V2__)

	tmp = DRV_PWM_Reg(PWM3_CTRL);
	switch(Clock_div)
	{
	   case pwmclk_1MHZ:
	      tmp |= PWM_CTRL_CLK_1;
	      break;
	      
	   case pwmclk_2MHZ:
	      tmp |= PWM_CTRL_CLK_2;
	      break;
      
      case pwmclk_4MHZ:
	      tmp |= PWM_CTRL_CLK_4;
	      break;
	      
	   case pwmclk_8MHZ:
	      tmp |= PWM_CTRL_CLK_8;
	      break;
	}

	switch(clk_sel)
	{
	   case pwmclk_13M:
	      tmp &= ~PWM_CTRL_CLKSEL;
	      break;
	      
	   case pwmclk_32k:
	      tmp |= PWM_CTRL_CLKSEL;
	      break;
	      
	   default:
	      break;
	}
	DRV_PWM_WriteReg(PWM3_CTRL,tmp);
}

/*
static void PWM3_level(kal_uint8 level)
{
	 kal_uint32 range = 0;
#if defined(__DRV_PMU53_SPEC_V2__)
   return;
#endif //#if defined(__DRV_PMU53_SPEC_V2__)
   if (level > 5)
      ASSERT(0);
   
   PWM3_LEVEL_SAVE = level;
	 range = sizeof(PWM3_Level_Info) / (sizeof(kal_uint32)*2);
	 if (level && level <= range)
   {
      PWM3_Configure(PWM3_Level_Info[level-1][0],PWM3_Level_Info[level-1][1]);
      PWM3_Start();
   }
   else
   {
      PWM3_Stop();
   }
}
*/

void PWM3_Configure(kal_uint32 freq, kal_uint8 duty)
{
   kal_uint32 clock;
   kal_uint32 tmp;
   kal_uint16 clkdiv;
   kal_uint16 reg;
#if defined(__DRV_PMU53_SPEC_V2__)
   return;
#endif //#if defined(__DRV_PMU53_SPEC_V2__)   

   if(duty > 100)
      duty = 100;
  // PWM3_FRE_SAVE=freq;
  // PWM3_DUTY_SAVE=duty;
  PWM_FRE_SAVE[2]=freq;
  PWM_DUTY_SAVE[2]=duty;
   reg = DRV_PWM_Reg(PWM3_CTRL);
   
   clkdiv = (1 << (reg & 0x0003));
   
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   
   clock = clock/clkdiv;
   
   if(0==freq)
      tmp = clock/(freq+1);
   else 
      tmp = clock/(freq); 
   
   tmp--;
   if(tmp >= 0x2000)
      tmp = 0x1fff;
   DRV_PWM_WriteReg(PWM3_COUNT,(kal_uint16)tmp);
   tmp = ((tmp+1)*duty)/100;
   if(tmp >= 0x2000)
      tmp = 0x1fff;
   DRV_PWM_WriteReg(PWM3_THRESHOLD,(kal_uint16)tmp);
}

/*duty=50 ==> 50%*/
void PWM3_Start(void)
{
   kal_uint16 reg; 
   volatile kal_uint32 clock = 0;
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__) && !defined(__UBL__)
   kal_uint32 itmp;
   #endif
   #endif
#if defined(__DRV_PMU53_SPEC_V2__)
   return;
#endif //#if defined(__DRV_PMU53_SPEC_V2__)   
   reg = DRV_PWM_Reg(PWM3_CTRL);
   clock = 32000;//dummy assignment for build warning   
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
   if(clock == 13000000)   
      L1SM_SleepDisable(PWM3_PDNhandle);
   #endif   
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
   DRV_PWM_WriteReg(DRVPDN_CON3_CLR,DRVPDN_CON3_PWM3);
   #elif defined(__CLKG_DEFINE__)
   ASSERT(0);
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
   PDN_CLR(PDN_PWM3);
#endif //#if defined(__OLD_PDN_ARCH__)
   /*to cover HW issue*/
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__) && !defined(__UBL__)
   itmp = swdbg_pwr_up();
   #endif
   #endif
}

void PWM3_Stop(void)
{
   kal_uint16 reg; 
   volatile kal_uint32 clock = 0;
#if defined(__DRV_PMU53_SPEC_V2__)
   return;
#endif //#if defined(__DRV_PMU53_SPEC_V2__)
   reg = DRV_PWM_Reg(PWM3_CTRL);
   clock = 32000;//dummy assignment for build warning   
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
   if(clock == 13000000)         
      L1SM_SleepEnable(PWM3_PDNhandle);
   #endif   
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
   DRV_PWM_WriteReg(DRVPDN_CON3_SET,DRVPDN_CON3_PWM3);
   #elif defined(__CLKG_DEFINE__)
   ASSERT(0);
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
   PDN_SET(PDN_PWM3);
#endif //#if defined(__OLD_PDN_ARCH__)
   #if defined(DRV_PWM_PWM3_SWDBG)
   #if !defined(__FUE__) && !defined(__UBL__)
   swdbg_pwr_down();
   #endif
   #endif
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif   /*DRV_PWM_PWM3*/
#if defined(DRV_PWM_PWM4)

void PWM4_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div)
{
   /*clk_sel only actived in MT6205B or later*/
	kal_uint16 tmp;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
	PWM4_PDNhandle = L1SM_GetHandle();
	#endif
	tmp = DRV_PWM_Reg(PWM4_CTRL);
	switch(Clock_div)
	{
	   case pwmclk_1MHZ:
	      tmp |= PWM_CTRL_CLK_1;
	      break;
	      
	   case pwmclk_2MHZ:
	      tmp |= PWM_CTRL_CLK_2;
	      break;
      
      case pwmclk_4MHZ:
	      tmp |= PWM_CTRL_CLK_4;
	      break;
	      
	   case pwmclk_8MHZ:
	      tmp |= PWM_CTRL_CLK_8;
	      break;
	}

	switch(clk_sel)
	{
	   case pwmclk_13M:
	      tmp &= ~PWM_CTRL_CLKSEL;
	      break;
	      
	   case pwmclk_32k:
	      tmp |= PWM_CTRL_CLKSEL;
	      break;
	      
	   default:
	      break;
	}
	DRV_PWM_WriteReg(PWM4_CTRL,tmp);
}
/*
void PWM4_level(kal_uint8 level)
{
	 kal_uint32 range = 0;
   if (level > 5)
      ASSERT(0);
   
   PWM4_LEVEL_SAVE = level;
	 range = sizeof(PWM4_Level_Info) / (sizeof(kal_uint32)*2);
	 if (level && level <= range)
   {
      PWM4_Configure(PWM4_Level_Info[level-1][0],PWM4_Level_Info[level-1][1]);
      PWM4_Start();
   }
   else
   {
      PWM4_Stop();
   }
}
*/

void PWM4_Configure(kal_uint32 freq, kal_uint8 duty)
{
   volatile kal_uint32 clock = 0;
   kal_uint32 tmp;
   kal_uint16 clkdiv;
   kal_uint16 reg;

   if(duty > 100)
      duty = 100;
   //PWM4_FRE_SAVE=freq;
   //PWM4_DUTY_SAVE=duty;
   PWM_FRE_SAVE[3]=freq;
   PWM_DUTY_SAVE[3]=duty;
   reg = DRV_PWM_Reg(PWM4_CTRL);
   
   clkdiv = (1 << (reg & 0x0003));
   
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   
   clock = clock/clkdiv;
   
   if(0==freq)
      tmp = clock/(freq+1);
   else 
      tmp = clock/(freq); 
   
   tmp--;
   if(tmp >= 0x2000)
      tmp = 0x1fff;
   DRV_PWM_WriteReg(PWM4_COUNT,(kal_uint16)tmp);
   tmp = ((tmp+1)*duty)/100;
   if(tmp >= 0x2000)
      tmp = 0x1fff;
   DRV_PWM_WriteReg(PWM4_THRESHOLD,(kal_uint16)tmp);
}

/*duty=50 ==> 50%*/
void PWM4_Start(void)
{
   kal_uint16 reg; 
   volatile kal_uint32 clock = 0;
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__) && !defined(__UBL__)
   kal_uint32 itmp;
   #endif
   #endif
   reg = DRV_PWM_Reg(PWM4_CTRL);
   clock = 32000;//dummy assignment for build warning   
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
   if(clock == 13000000)   
      L1SM_SleepDisable(PWM4_PDNhandle);
   #endif   
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
   DRV_PWM_WriteReg(DRVPDN_CON3_CLR,DRVPDN_CON3_PWM3);
   #elif defined(__CLKG_DEFINE__)
   ASSERT(0);
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
   PDN_CLR(PDN_PWM4);
#endif //#if defined(__OLD_PDN_ARCH__)
   /*to cover HW issue*/
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__) && !defined(__UBL__)
   itmp = swdbg_pwr_up();
   #endif
   #endif
}

void PWM4_Stop(void)
{
   kal_uint16 reg; 
   volatile kal_uint32 clock = 0;

   reg = DRV_PWM_Reg(PWM4_CTRL);
   clock = 32000;//dummy assignment for build warning   
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
   if(clock == 13000000)         
      L1SM_SleepEnable(PWM4_PDNhandle);
   #endif   
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
   DRV_PWM_WriteReg(DRVPDN_CON3_SET,DRVPDN_CON3_PWM3);
   #elif defined(__CLKG_DEFINE__)
   ASSERT(0);
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
   PDN_SET(PDN_PWM4);
#endif //#if defined(__OLD_PDN_ARCH__)
   #if defined(DRV_PWM_PWM4_SWDBG)
   #if !defined(__FUE__) && !defined(__UBL__)
   swdbg_pwr_down();
   #endif
   #endif
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif   /*DRV_PWM_PWM4*/

#else  // DRV_PWM_OFF

void PWM_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div){}
void PWM1_Configure(kal_uint32 freq, kal_uint8 duty){}
void PWM1_Start(void){}
void PWM1_Stop(void){}
kal_uint8  PWM1_GetCurrentLevel(void){return 0;}
kal_uint8  PMW1_GetCurrentDuty(void){return 0;}
kal_uint32 PMW1_GetCurrentFreq(void){return 0;}
#if defined(DRV_PWM_PWM2)
void PWM2_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div){}
void PWM2_Configure(kal_uint32 freq, kal_uint8 duty){}
void PWM2_Start(void){}
void PWM2_Stop(void){}
kal_uint8  PWM2_GetCurrentLevel(void){return 0;}
kal_uint8  PMW2_GetCurrentDuty(void){return 0;}
kal_uint32 PMW2_GetCurrentFreq(void){return 0;}
#if defined(DRV_PWM_PWM3)
void PWM3_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div){}
void PWM3_Configure(kal_uint32 freq, kal_uint8 duty){}
void PWM3_Start(void){}
void PWM3_Stop(void){}
kal_uint8  PWM3_GetCurrentLevel(void){return 0;}
kal_uint8  PMW3_GetCurrentDuty(void){return 0;}
kal_uint32 PMW3_GetCurrentFreq(void){return 0;}
#if defined(__DRV_PMU53_SPEC_V2__)
void PWM3_Output_High(void){}
#endif //#if defined(__DRV_PMU53_SPEC_V2__)
#if defined(DRV_PWM_PWM4)
void PWM4_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div){}
void PWM4_Configure(kal_uint32 freq, kal_uint8 duty){}
void PWM4_Start(void){}
void PWM4_Stop(void){}
kal_uint8  PWM4_GetCurrentLevel(void){return 0;}
kal_uint8  PMW4_GetCurrentDuty(void){return 0;}
kal_uint32 PMW4_GetCurrentFreq(void){return 0;}
#endif
#endif   /* DRV_PWM_PWM3 */
#endif   /* DRV_PWM_PWM2 */

#endif  // DRV_PWM_OFF

#endif  /* !defined(DRV_PWM_RWG) */


#endif // #if !defined(DRV_PWM_NOT_EXIST)
#endif 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(DRV_PWM_NOT_EXIST)
/* under construction !*/
#if !defined(DRV_PWM_RWG)
#ifndef DRV_PWM_OFF
#if defined(__DCL_PWM_INTERFACE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
#if defined(DRV_PWM_PWM3)
/* under construction !*/
#endif //#if defined(DRV_PWM_PWM3)
#endif
#if defined(DRV_PWM_PWM4)
/* under construction !*/
#endif //#if defined(DRV_PWM_PWM4)
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_PWM_PWM3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if defined(DRV_PWM_PWM3)
#if defined(DRV_PWM_PWM4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if defined(DRV_PWM_PWM4)
/* under construction !*/
#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
#if defined(DRV_PWM_PWM3)
/* under construction !*/
#endif //#if defined(DRV_PWM_PWM3)
#if defined(DRV_PWM_PWM4)
/* under construction !*/
#endif //#if defined(DRV_PWM_PWM4)
/* under construction !*/
	#endif
#endif
/* under construction !*/
/* under construction !*/
#if defined(DRV_PWM_PWM4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(DRV_PWM_PWM3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(DRV_PWM_PWM2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
#if defined(DRV_PWM_PWM4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(DRV_PWM_PWM3) && !defined(DRV_PWM_PWM4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(DRV_PWM_PWM2) && !defined(DRV_PWM_PWM3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
/* under construction !*/
/* under construction !*/
#if defined(MT6256)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   //kal_prompt_trace(MOD_DRV_HISR,"PWM Init");
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   	#if defined(__DRV_PMU53_SPEC_V2__)
/* under construction !*/
	#endif //#if defined(__DRV_PMU53_SPEC_V2__)  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
   	#if defined(__DRV_PMU53_SPEC_V2__)
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
	      #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
/* under construction !*/
	      #else
/* under construction !*/
	      #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
/* under construction !*/
	      #else
/* under construction !*/
	      #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
/* under construction !*/
	      #else
/* under construction !*/
	      #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_PWM_CLK_SEL)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*DRV_PWM_CLK_SEL*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
   #endif
   #endif
/* under construction !*/
   #if 0
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
   #if defined(DRV_PWM_PWM4)&& defined(DRV_PWM_PWM3) && defined(DRV_PWM_PWM2)
/* under construction !*/
   #elif defined(DRV_PWM_PWM3)&& defined(DRV_PWM_PWM2)
/* under construction !*/
   #elif defined(DRV_PWM_PWM2)
/* under construction !*/
   #endif 
#endif //#if defined(__OLD_PDN_ARCH__)
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   	#if defined(__DRV_PMU53_SPEC_V2__)
/* under construction !*/
   	#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
/* under construction !*/
   #endif   
/* under construction !*/
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #elif defined(__CLKG_DEFINE__)
/* under construction !*/
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#if defined(DRV_PWM_PWM3)
/* under construction !*/
			#endif
/* under construction !*/
/* under construction !*/
			#if defined(DRV_PWM_PWM2)
/* under construction !*/
			#endif
/* under construction !*/
/* under construction !*/
			#if defined(DRV_PWM_PWM4)
/* under construction !*/
			#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
   #endif
   #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   	#if defined(__DRV_PMU53_SPEC_V2__)
/* under construction !*/
	#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
/* under construction !*/
   #endif   
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #elif defined(__CLKG_DEFINE__)
/* under construction !*/
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			 #if defined(DRV_PWM_PWM3)
/* under construction !*/
			 #endif
/* under construction !*/
/* under construction !*/
			 #if defined(DRV_PWM_PWM2)
/* under construction !*/
			 #endif
/* under construction !*/
/* under construction !*/
			 #if defined(DRV_PWM_PWM4)
/* under construction !*/
			 #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
   #if defined(DRV_PWM_PWM3_SWDBG)
   #if !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
   #endif
   #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
/* under construction !*/
	      #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #else
/* under construction !*/
	      #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #else
/* under construction !*/
	      #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #else
/* under construction !*/
	      #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_PWM_CLK_SEL)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*DRV_PWM_CLK_SEL*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_PWM_PWM2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
/* under construction !*/
	      #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #else
/* under construction !*/
	      #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #else
/* under construction !*/
	      #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
/* under construction !*/
/* under construction !*/
	      #else
/* under construction !*/
	      #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   /*DRV_PWM_PWM2*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_PWM_CLK_SEL)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
/* under construction !*/
   #endif   
#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
   #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
   #elif defined(__CLKG_DEFINE__)
/* under construction !*/
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
#else /*!(MT6205B,MT6218, MT6218B, MT6219, MT6217, MT6228,MT6229)*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
/* under construction !*/
   #elif defined(__CLKG_DEFINE__)
/* under construction !*/
   #endif // #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
#endif   /*DRV_PWM_CLK_SEL*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_PWM_CLK_SEL)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
   #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
   #elif defined(__CLKG_DEFINE__)
/* under construction !*/
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
/* under construction !*/
   #endif    
#else /*!(DRV_PWM_CLK_SEL)*/
/* under construction !*/
/* under construction !*/
#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
   #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
/* under construction !*/
   #elif defined(__CLKG_DEFINE__)
/* under construction !*/
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#endif   /*DRV_PWM_CLK_SEL*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if 0
#if defined(DRV_PWM_PWM2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_PWM_NONE_CLK)
/* under construction !*/
#else
/* under construction !*/
#endif   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
   #endif
   #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
/* under construction !*/
   #endif   
/* under construction !*/
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
   #elif defined(__CLKG_DEFINE__)
/* under construction !*/
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
   #endif
   #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
/* under construction !*/
   #endif   
#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
   #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
   #elif defined(__CLKG_DEFINE__)
/* under construction !*/
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
   #if defined(DRV_PWM_PWM2_SWDBG)
   #if !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
   #endif
   #endif
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif   /*DRV_PWM_PWM2*/
#endif
/* under construction !*/
#if defined(DRV_PWM_PWM3)
/* under construction !*/
#if defined(__DRV_PMU53_SPEC_V2__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
   #elif defined(__CLKG_DEFINE__)
/* under construction !*/
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#endif //#if defined(__DRV_PMU53_SPEC_V2__)
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
	#endif
#if defined(__DRV_PMU53_SPEC_V2__)
/* under construction !*/
#endif //#if defined(__DRV_PMU53_SPEC_V2__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__DRV_PMU53_SPEC_V2__)
/* under construction !*/
#endif //#if defined(__DRV_PMU53_SPEC_V2__)   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
   #endif
   #endif
#if defined(__DRV_PMU53_SPEC_V2__)
/* under construction !*/
#endif //#if defined(__DRV_PMU53_SPEC_V2__)   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
/* under construction !*/
   #endif   
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
   #elif defined(__CLKG_DEFINE__)
/* under construction !*/
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
   #endif
   #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__DRV_PMU53_SPEC_V2__)
/* under construction !*/
#endif //#if defined(__DRV_PMU53_SPEC_V2__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
/* under construction !*/
   #endif   
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
   #elif defined(__CLKG_DEFINE__)
/* under construction !*/
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
   #if defined(DRV_PWM_PWM3_SWDBG)
   #if !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
   #endif
   #endif
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif 
#endif   /*DRV_PWM_PWM3*/
#if defined(DRV_PWM_PWM4)
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
   #endif
   #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
/* under construction !*/
   #endif   
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
   #elif defined(__CLKG_DEFINE__)
/* under construction !*/
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
   #endif
   #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
/* under construction !*/
   #endif   
#if defined(__OLD_PDN_ARCH__)
   #if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
   #elif defined(__CLKG_DEFINE__)
/* under construction !*/
   #endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
   #if defined(DRV_PWM_PWM4_SWDBG)
   #if !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
   #endif
   #endif
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif 
#endif   /*DRV_PWM_PWM4*/
/* under construction !*/
#else  // DRV_PWM_OFF
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_PWM_PWM2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_PWM_PWM3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__DRV_PMU53_SPEC_V2__)
/* under construction !*/
#endif //#if defined(__DRV_PMU53_SPEC_V2__)
#if defined(DRV_PWM_PWM4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif   /* DRV_PWM_PWM3 */
#endif   /* DRV_PWM_PWM2 */
/* under construction !*/
#endif  // DRV_PWM_OFF
/* under construction !*/
#endif  /* !defined(DRV_PWM_RWG) */
/* under construction !*/
/* under construction !*/
#endif // #if !defined(DRV_PWM_NOT_EXIST)
#endif

