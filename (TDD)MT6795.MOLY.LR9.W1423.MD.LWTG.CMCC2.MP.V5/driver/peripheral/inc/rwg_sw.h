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
 *    rwg_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for Random Waveform Generator (Enhaced PWM) driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef RWG_SW_H
#define RWG_SW_H
#include "kal_general_types.h"
#include "drv_comm.h"
#include "drv_features_pwm.h"
#include "dcl.h"
#if defined(DRV_PWM_RWG)
/*PWM user mode ID*/
typedef enum 
{
	PWM_OWNER_UEM=0,
   PWM_OWNER_AF,
	PWM_OWNER_NONE=0xff
}pwm_owner_e;

/*Select PWM1 clock scale*/
typedef enum 
{
	PWM_CLK_DIV_NONE=0,
	PWM_CLK_DIV_2=1,
	PWM_CLK_DIV_4=2,
	PWM_CLK_DIV_8=3,
	PWM_CLK_DIV_16=4,
	PWM_CLK_DIV_32=5,
	PWM_CLK_DIV_64=6,
	PWM_CLK_DIV_128=7
}pwm_clk_div_e;

/*Select PWMn clock*/
typedef enum 
{
	PWM_CLK_SEL_52M=0,
	PWM_CLK_SEL_32K=1
}pwm_clk_sel_e;

/*PWM channel enumerate*/
typedef enum 
{
	PWM1=0,
	PWM2,
	PWM3,
	PWM4,
	PWM5,
	PWM6,
  PWM_COUNT
}pwm_num_e;

typedef enum
{
   PWM_SEQ_EN_PWM3=0x1,
   PWM_SEQ_EN_PWM34=0x03,
   PWM_SEQ_EN_PWM35=0x05,
   PWM_SEQ_EN_PWM345=0x07,
   PWM_SEQ_EN_PWM36=0x09,
   PWM_SEQ_EN_PWM346=0x0b,
   PWM_SEQ_EN_PWM356=0x0d,
   PWM_SEQ_EN_PWM3456=0x0f
} pwm_seq_en_cnt_e;

typedef enum
{
   PWM_BUF_INVALID_NONE=0,
   PWM_BUF_0_INVALID,
   PWM_BUF_1_INVALID,
   PWM_BUF_0_1_INVALID
} pwm_buf_invalid_e;
typedef void (*DCL_PWM_INIT)(void);
typedef void (*DCL_PWM_CLK_INIT)(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint32 clk_div);
typedef void (*DCL_PWM_START)(DCL_UINT8 owner, DCL_UINT32 pwm_num);
typedef void (*DCL_PWM_STOP)(DCL_UINT8 owner, DCL_UINT32 pwm_num);
typedef DCL_BOOL (*DCL_PWM_CONFIGURE)(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 mode, void *para);
typedef void (*DCL_PWM_SET_BUF_VALID)(kal_uint8 owner, kal_uint32 pwm_num,kal_uint32 *buf_addr, kal_uint16 buf_size, kal_bool is_buf0);
typedef void (*DCL_PWM_SET_DELAY)(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint16 delay_cnt);
typedef  DCL_BOOL (*DCL_PWM_SEQ_OPEN)(kal_uint8 owner);
typedef void (*DCL_PWM_SEQ_START)(kal_uint8 owner, kal_uint8 en_cnt);
typedef void (*DCL_PWM_SEQ_STOP)(kal_uint8 owner);
typedef DCL_BOOL (*DCL_PWM_SEQ_CLOSE)(kal_uint8 owner);
typedef void (*DCL_PWM_CONFIG_OLD)(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint8 duty);
typedef DCL_UINT8 (*DCL_PWM_GETCURRENT_LEVEL)(DCL_UINT8 pwm_num);
typedef DCL_UINT32(*DCL_PWM_GETCURRENT_FREQ)(DCL_UINT8 pwm_num);
typedef DCL_UINT8 (*DCL_PWM_GETCURRENT_DUTY)(DCL_UINT8 pwm_num);
typedef void (*DCL_PWM_TEST_SELECT)(DCL_BOOL sel);
typedef kal_bool (*DCL_PWM_OPEN)(kal_uint8 owner, kal_uint32 pwm_num);
typedef kal_bool (*DCL_PWM_CLOSE)(kal_uint8 owner, kal_uint32 pwm_num);
typedef void (*DCL_PWM_CONFIG_FREQ_STEPS)(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint16 steps);
typedef void (*DCL_PWM_SET_DUTY)(kal_uint8 owner, kal_uint32 pwm_num, kal_uint16 duty);
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
   DCL_PWM_TEST_SELECT           pwmTestSelect;
   DCL_PWM_CONFIGURE             pwmConfigure;
   DCL_PWM_OPEN                  pwmOpen;
   DCL_PWM_CLOSE                 pwmClose;
   DCL_PWM_SET_BUF_VALID         pwmSetBufValid; 
   DCL_PWM_SET_DELAY             pwmSetDelay;
   DCL_PWM_SEQ_OPEN              pwmSeqOpen;
   DCL_PWM_SEQ_START             pwmSeqStart;
   DCL_PWM_SEQ_STOP              pwmSeqStop;
   DCL_PWM_SEQ_CLOSE             pwmSeqClose;
   DCL_PWM_CONFIG_FREQ_STEPS     pwm_config_freq_steps;
   DCL_PWM_SET_DUTY              pwmSetDuty;
}PWMDriver_t;

extern void DCL_PWM_Start(kal_uint8 owner, kal_uint32 pwm_num);
extern void DCL_PWM_Stop(kal_uint8 owner, kal_uint32 pwm_num);
extern kal_uint8 DCL_PWM_GetCurrent_Level(kal_uint8 pwm_num);
extern kal_uint8 DCL_PWM_GetCurrentDuty(kal_uint8 pwm_num);
extern kal_uint32 DCL_PWM_GetCurrentFreq(kal_uint8 pwm_num);
extern void DCL_PWM_ConfigOld(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint8 duty);

extern void PWM_Init(void);
extern kal_bool PWM_Open(kal_uint8 owner, kal_uint32 pwm_num);
extern kal_bool PWM_Seq_Open(kal_uint8 owner);
extern kal_bool PWM_Close(kal_uint8 owner, kal_uint32 pwm_num);
extern kal_bool PWM_Seq_Close(kal_uint8 owner);
extern void PWM_CLK_Init(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint32 clk_div);
extern kal_bool PWM_Configure(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 mode, void *para);
extern void PWM_Start(kal_uint8 owner, kal_uint32 pwm_num);
extern void PWM_Stop(kal_uint8 owner, kal_uint32 pwm_num);

/* Below are for Sequence mode */
extern void PMW_Set_Delay(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint16 delay_cnt);
extern void PWM_Seq_Start(kal_uint8 owner, kal_uint8 en_cnt);
extern void PWM_Seq_Stop(kal_uint8 owner);
//extern kal_uint32 PWM_Check_Buf_Valid(kal_uint32 pwm_num);
extern void PWM_Set_Buf_Valid(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 *buf_addr, kal_uint16 buf_size, kal_bool is_buf0);

/* Below are for OLD PWM backward compatibility. */
// MoDIS parser skip start
// The following APIs are implemented in other dummy API files
extern void PWM1_Configure(kal_uint32 freq, kal_uint8 duty);
extern void PWM2_Configure(kal_uint32 freq, kal_uint8 duty);
// MoDIS parser skip end
extern void PWM3_Configure(kal_uint32 freq, kal_uint8 duty);
// MoDIS parser skip start
// The following APIs are implemented in other dummy API files
extern void PWM1_Start(void);
extern void PWM2_Start(void);
// MoDIS parser skip end
extern void PWM3_Start(void);
// MoDIS parser skip start
// The following APIs are implemented in other dummy API files
extern void PWM1_Stop(void);
extern void PWM2_Stop(void);
// MoDIS parser skip end
extern void PWM3_Stop(void);

// OLD PWM support for PWM port 4, 5, 6 begin
extern void PWM4_Configure(kal_uint32 freq, kal_uint8 duty);
extern void PWM5_Configure(kal_uint32 freq, kal_uint8 duty);
extern void PWM6_Configure(kal_uint32 freq, kal_uint8 duty);
extern void PWM4_Start(void);
extern void PWM5_Start(void);
extern void PWM6_Start(void);
extern void PWM4_Stop(void);
extern void PWM5_Stop(void);
extern void PWM6_Stop(void);
extern kal_uint8  PWM4_GetCurrentLevel(void);
extern kal_uint8  PMW4_GetCurrentDuty(void);
extern kal_uint32 PMW4_GetCurrentFreq(void);
extern kal_uint8  PWM5_GetCurrentLevel(void);
extern kal_uint8  PMW5_GetCurrentDuty(void);
extern kal_uint32 PMW5_GetCurrentFreq(void);
extern kal_uint8  PWM6_GetCurrentLevel(void);
extern kal_uint8  PMW6_GetCurrentDuty(void);
extern kal_uint32 PMW6_GetCurrentFreq(void);
// OLD PWM support for PWM port 4, 5, 6 begin

extern kal_uint8  PWM1_GetCurrentLevel(void);
extern kal_uint8  PMW1_GetCurrentDuty(void);
extern kal_uint32 PMW1_GetCurrentFreq(void);
extern kal_uint8  PWM2_GetCurrentLevel(void);
extern kal_uint8  PMW2_GetCurrentDuty(void);
extern kal_uint32 PMW2_GetCurrentFreq(void);
extern kal_uint8 PWM3_GetCurrentLevel(void);
extern kal_uint32 PMW3_GetCurrentFreq(void);
extern kal_uint8 PMW3_GetCurrentDuty(void);
extern void PWM_Test_Select(kal_bool sel);
#endif  /* defined(DRV_PWM_RWG) */


#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_RWG_REG_DBG__)
#define DRV_RWG_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_RWG_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_RWG_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_RWG_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_RWG_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_RWG_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_RWG_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_RWG_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_RWG_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_RWG_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_RWG_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_RWG_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_RWG_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_RWG_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_RWG_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_RWG_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_RWG_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_RWG_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_RWG_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_RWG_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_RWG_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_RWG_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_RWG_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_RWG_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_RWG_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_RWG_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_RWG_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_RWG_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_RWG_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_RWG_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_RWG_REG_DBG__)
#endif

