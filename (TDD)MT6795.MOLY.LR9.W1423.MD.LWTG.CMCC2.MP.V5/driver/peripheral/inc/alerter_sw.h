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
 *    alerter_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for alerter driver and melody adaption.
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
#ifndef ALERTER_SW_H
#define ALERTER_SW_H
#include "dcl.h"
/*
* The output of Alerter has to sources:
* one is the enhanced pwm output signal,which is implemented embedded in Alerter module;
* the other is PDM signal from DSP domain directly.
*/
#define pwm 	0
#define pdm 	1

/*Select PWM Waveform clock*/
typedef enum 
{
   c13_1MHZ, /*13M Hz*/
   c13_2MHZ, /*13/2M Hz*/
   c13_4MHZ, /*13/4M Hz*/
   c13_8MHZ  /*13/8M Hz*/
}ALClock;
/*
* select Alerter mode
* In mode 1, the polarity of alerter output signal according to the relationship between internal counter1 and the programmed threshold will be inverted each time internal
* counter2 reaches zero. 
*
* In mode2, each time the internal counter2 count backwards to zero the alerter output signal is normal
* pwm signal (i.e. signal is low as long as the internal counter1 value is greater than or equals to ALERTER_THRES, and it
* is high when the internal counter1 is less than ALERTER_THRES) or low state by turns. 

* In mode3, the value of internal counter2 has no effect on output signal, i.e. the alerter output signal is low as long as the internal counter1 value is above
* the programmed threshold and is high the internal counter1 is less than ALERTER_THRES when no matter what value the
* internal counter2 is.
*/
typedef enum 
{
   m1, /*Mode 1 select*/
   m2, /*Mode 2 select*/
   m3  /*Mode 3 select*/
}ALMode;

typedef void (*DCL_ALERTER_CONFIGURE)(kal_uint32 freq, kal_uint8 duty);
typedef void (*DCL_ALERTER_START)(void);
typedef void (*DCL_ALERTER_STOP)(void);
typedef void (*DCL_ALERTER_PWROPEN)(kal_bool ENABLE);
typedef void (*DCL_ALERTER_OUTPUT)(kal_uint8 outtype);
typedef void (*DCL_ALERTER_PLAYALTERNOTES)(kal_bool (*GetNotecallbac)(BuzNoteStruct *Buz), void (*endofAlter)(void));
typedef void (*DCL_ALERTER_STOPALERTERNOTES)(void);
typedef void (*DCL_ALERTER_SETBUZVOLUME)(kal_uint8 volumn);
typedef void (*DCL_ALERTER_CONFIG)(ALMode mode, ALClock Clock);
typedef void (*DCL_ALERTER_GETCURRENT_LEVEL)(void);

typedef struct
{
   DCL_ALERTER_CONFIGURE         configure;
   DCL_ALERTER_START             start;
   DCL_ALERTER_STOP              stop;
   DCL_ALERTER_PWROPEN           pwropen;
   DCL_ALERTER_OUTPUT            output;
   DCL_ALERTER_PLAYALTERNOTES    playnotes;
   DCL_ALERTER_STOPALERTERNOTES  stopnotes;
   DCL_ALERTER_SETBUZVOLUME      setbuzvolume;
   DCL_ALERTER_GETCURRENT_LEVEL  getlevel;
}AlerterDriver_t;

extern void ALERTER_Output(kal_uint8 outtype);
extern void PlayAlterNotes(kal_bool (*GetNotecallbac)(BuzNoteStruct *Buz), void (*endofAlter)(void));
extern void StopAlterNotes(void);
extern void SetBuzVolume(kal_uint8 volumn);
extern void ALERTER_Config(ALMode mode, ALClock Clock);


// MoDIS parser skip start
// The following APIs are implemented in other dummy API files
extern void Alter_Configure(kal_uint32 freq, kal_uint8 duty);
extern void Alter_Start(void);
extern void Alter_Stop(void);
extern void ALERTER_PWROPEN(kal_bool ENABLE);
// MoDIS parser skip end

#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_ALERTER_REG_DBG__)
#define DRV_ALERTER_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_ALERTER_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_ALERTER_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_ALERTER_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_ALERTER_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_ALERTER_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_ALERTER_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_ALERTER_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_ALERTER_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_ALERTER_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_ALERTER_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_ALERTER_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_ALERTER_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_ALERTER_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_ALERTER_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_ALERTER_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_ALERTER_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_ALERTER_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_ALERTER_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_ALERTER_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_ALERTER_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_ALERTER_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_ALERTER_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_ALERTER_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_ALERTER_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_ALERTER_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_ALERTER_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_ALERTER_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_ALERTER_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_ALERTER_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_ALERTER_REG_DBG__)
#endif

