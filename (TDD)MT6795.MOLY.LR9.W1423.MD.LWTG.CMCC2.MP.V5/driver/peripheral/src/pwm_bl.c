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
#if defined(__UBL__)
#include "drv_features_pwm.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "pwm_hw.h"
#include "pwm_sw.h"
#include "kal_general_types.h"
#include "custom_hw_default.h"
#include "drvpdn.h"


#if !defined(DRV_PWM_NOT_EXIST)

#if !defined(DRV_PWM_RWG)

#if defined(__CARD_DOWNLOAD__)

static kal_uint32 PWM1_FRE_SAVE;   /*for MMI usage*/
static kal_uint32 PWM2_FRE_SAVE;   /*for MMI usage*/
static kal_uint8  PWM1_DUTY_SAVE;   /*for MMI usage*/
static kal_uint8  PWM2_DUTY_SAVE;   /*for MMI usage*/

#if defined(DRV_PWM_PWM3)
static kal_uint32 PWM3_FRE_SAVE;   /*for MMI usage*/
static kal_uint8  PWM3_DUTY_SAVE;   /*for MMI usage*/
#endif //#if defined(DRV_PWM_PWM3)


static kal_uint8  PWM1_CTRL_CLK = 0;
static kal_uint8  PWM2_CTRL_CLK = 0;

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

void PWM_level(kal_uint8 level)
{
	 kal_uint32 range = 0;
	 
   if (level > 5)
      ASSERT(0);
   
   //PWM1_LEVEL_SAVE = level;
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



#if defined(DRV_PWM_PWM2)
void PWM2_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div)
{
   /*clk_sel only actived in MT6205B or later*/
	kal_uint16 tmp;

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

void PWM2_level(kal_uint8 level)
{
	 kal_uint32 range = 0;
   if (level > 5)
      ASSERT(0);

   //PWM2_LEVEL_SAVE = level;
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
   PWM1_FRE_SAVE=freq;
   PWM1_DUTY_SAVE=duty;
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
   kal_uint32 clock;
   reg = DRV_PWM_Reg(PWM1_CTRL);
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
#endif

   DRV_PWM_WriteReg(DRVPDN_CON1_CLR,DRVPDN_CON1_PWM);

}

void PWM1_Stop(void)
{
#if defined(DRV_PWM_CLK_SEL)
   kal_uint16 reg; 
   kal_uint32 clock;
   reg = DRV_PWM_Reg(PWM1_CTRL);
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
#endif

   DRV_PWM_WriteReg(DRVPDN_CON1_SET,DRVPDN_CON1_PWM);



}

#if defined(DRV_PWM_PWM2)
void PWM2_Configure(kal_uint32 freq, kal_uint8 duty)
{
   kal_uint32 clock;
   kal_uint32 tmp;
   kal_uint32 tmpMultiCLK;
   kal_uint16 clkdiv;
   kal_uint16 reg;
   

   if(duty > 100)
      duty = 100;
   PWM2_FRE_SAVE=freq;
   PWM2_DUTY_SAVE=duty;
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
   kal_uint32 clock;
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__)
   kal_uint32 itmp;
   #endif
   #endif
   
   reg = DRV_PWM_Reg(PWM2_CTRL);
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;


   DRV_PWM_WriteReg(DRVPDN_CON1_CLR,DRVPDN_CON1_PWM2);


   /*to cover HW issue*/
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__)
   //itmp = swdbg_pwr_up();
   #endif
   #endif
}

void PWM2_Stop(void)
{
   kal_uint16 reg; 
   kal_uint32 clock;
   reg = DRV_PWM_Reg(PWM2_CTRL);
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;

   DRV_PWM_WriteReg(DRVPDN_CON1_SET,DRVPDN_CON1_PWM2);

   #if defined(DRV_PWM_PWM2_SWDBG)
   #if !defined(__FUE__)
   //swdbg_pwr_down();
   #endif
   #endif
}

#endif   /*DRV_PWM_PWM2*/


#if defined(DRV_PWM_PWM3)

#if defined(__DRV_PMU53_SPEC_V2__)
void PWM3_Output_High(void)
{
   DRV_PWM_WriteReg32(PWM3_CTRL, PWM_CTRL_CLK_1 | PWM_CTRL_CLKSEL);
   DRV_PWM_WriteReg(PWM3_COUNT,0);
   DRV_PWM_WriteReg(PWM3_THRESHOLD,1);

   #if defined(__OLD_PDN_DEFINE__)
   DRV_PWM_WriteReg(DRVPDN_CON3_CLR,DRVPDN_CON3_PWM3);
   #elif defined(__CLKG_DEFINE__)
   ASSERT(0);
   #endif // #if defined(__OLD_PDN_DEFINE__)

}
#endif //#if defined(__DRV_PMU53_SPEC_V2__)

void PWM3_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div)
{
   /*clk_sel only actived in MT6205B or later*/
	kal_uint16 tmp;

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

void PWM3_level(kal_uint8 level)
{
   kal_uint32 range = 0;
#if defined(__DRV_PMU53_SPEC_V2__)
   return;
#endif //#if defined(__DRV_PMU53_SPEC_V2__)
   if (level > 5)
      ASSERT(0);
   
   //PWM3_LEVEL_SAVE = level;
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
   PWM3_FRE_SAVE=freq;
   PWM3_DUTY_SAVE=duty;
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
   kal_uint32 clock;
   #if defined(MT6228)|| defined(MT6229) || defined(MT6230)
   #if !defined(__FUE__)
   kal_uint32 itmp;
   #endif
   #endif
#if defined(__DRV_PMU53_SPEC_V2__)
   return;
#endif //#if defined(__DRV_PMU53_SPEC_V2__)   
   reg = DRV_PWM_Reg(PWM3_CTRL);
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;

   DRV_PWM_WriteReg(DRVPDN_CON3_CLR,DRVPDN_CON3_PWM3);
}

void PWM3_Stop(void)
{
   kal_uint16 reg; 
   kal_uint32 clock;
#if defined(__DRV_PMU53_SPEC_V2__)
   return;
#endif //#if defined(__DRV_PMU53_SPEC_V2__)
   reg = DRV_PWM_Reg(PWM3_CTRL);
      
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;

  DRV_PWM_WriteReg(DRVPDN_CON3_SET,DRVPDN_CON3_PWM3);
}

#endif   /*DRV_PWM_PWM3*/

#else

void PWM_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div){;}
void PWM1_Configure(kal_uint32 freq, kal_uint8 duty){;}
void PWM1_Start(void) {;}
void PWM1_Stop(void) {;}

#if defined(DRV_PWM_PWM2)
void PWM2_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div){;}
void PWM2_Configure(kal_uint32 freq, kal_uint8 duty){;}
void PWM2_Start(void) {;}
void PWM2_Stop(void) {;}

#endif

#if defined(DRV_PWM_PWM3)

#if defined(__DRV_PMU53_SPEC_V2__)
void PWM3_Output_High(void) {;}
#endif

void PWM3_Init(PWMClock_SEL clk_sel,PWMClock_DIV Clock_div) {;}
void PWM3_Configure(kal_uint32 freq, kal_uint8 duty){;}
void PWM3_Start(void) {;}
void PWM3_Stop(void) {;}
#endif


#endif /*__CARD_DOWNLOAD__*/

#endif  /* !defined(DRV_PWM_RWG) */


#endif // #if !defined(DRV_PWM_NOT_EXIST)
#endif //#if defined(__UBL__)
