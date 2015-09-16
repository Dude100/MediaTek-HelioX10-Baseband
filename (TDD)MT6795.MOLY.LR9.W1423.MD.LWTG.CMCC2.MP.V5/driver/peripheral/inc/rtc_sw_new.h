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
 *    rtc_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for RTC driver and adaption.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#ifndef _RTC_SW_H
#define _RTC_SW_H

#include "drv_comm.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"

#define ONE_SHOT_DIS		0
#define ONE_SHOT_EN		1

#define RTC_BBPU_KEY		               0x4300
                                       
#define RTC_BBPU_ALARM_SW	            0x0001
#if defined(DRV_RTC_BBPU_AS_6205) || defined(DRV_RTC_BBPU_AS_6208) || defined(FPGA)
   #define RTC_BBPU_PWR_POLARITY	      0x0002
#endif   /*DRV_RTC_BBPU_AS_6205,DRV_RTC_BBPU_AS_6208,FPGA*/

#if defined(DRV_RTC_BBPU_AS_6205B) || defined(DRV_RTC_BBPU_AS_6238)
   #define RTC_BBPU_WRITE_EN           0x0002
   #define RTC_BBPU_PWR_SW	            0x0004
   #define RTC_BBPU_AUTOPDN            0x0008
   #if  defined(DRV_RTC_BBPU_AS_6238)
      #define RTC_BBPU_CLRPKY            0x0010
      #define RTC_BBPU_RELOAD            0x0020
      #define RTC_BBPU_CBUSY             0x0040
      #define RTC_BBPU_DBING             0x0080
   #endif
#endif   /*DRV_RTC_BBPU_AS_6205B*/

#if defined(DRV_RTC_BBPU_AS_6218)
   #define RTC_BBPU_PWR_POLARITY       0x0002
   #define RTC_BBPU_PWR_SW	            0x0004
   #define RTC_BBPU_AUTOPDN            0x0008
#endif   /*DRV_RTC_BBPU_AS_6218*/
                                       
#if defined(DRV_RTC_BBPU_AS_6205)
   #define RTC_BBPU_PWR_SW	            0x0004
   #define RTC_BBPU_PDN_XOSC32K		   0x0010
#endif /*(DRV_RTC_BBPU_AS_6205)*/
#if defined(DRV_RTC_BBPU_AS_6208) || defined(FPGA)
   #define RTC_BBPU_PDN_XOSC32K		   0x0004
   #define RTC_BBPU_PWR_SW	            0x0010
#endif /*(DRV_RTC_BBPU_AS_6208,FPGA)*/

#if defined(DRV_RTC_BBPU_AS_6276)
  #define RTC_BBPU_PWR_SW	            0x0004 
  #define RTC_BBPU_AUTOPDN            0x0008
  #define RTC_BBPU_CLRPKY            0x0010
  #define RTC_BBPU_RELOAD            0x0020
  #define RTC_BBPU_CBUSY             0x0040
#endif   /*DRV_RTC_BBPU_AS_6205B*/


#if defined(DRV_RTC_BBPU_AS_6205) || defined(DRV_RTC_BBPU_AS_6208) || defined(FPGA)
   #define RTC_BBPU_POWERON        (RTC_BBPU_PDN_XOSC32K|RTC_BBPU_PWR_SW|RTC_BBPU_PWR_POLARITY|RTC_BBPU_ALARM_SW|RTC_BBPU_KEY)
   #define RTC_BBPU_POWEROFF       (RTC_BBPU_PDN_XOSC32K|RTC_BBPU_PWR_POLARITY|RTC_BBPU_ALARM_SW|RTC_BBPU_KEY)
#endif   /*DRV_RTC_BBPU_AS_6205,DRV_RTC_BBPU_AS_6208,FPGA*/

#if defined(DRV_RTC_BBPU_AS_6205B) || defined(DRV_RTC_BBPU_AS_6238)
   #define RTC_BBPU_POWERON        (RTC_BBPU_PWR_SW|RTC_BBPU_WRITE_EN|RTC_BBPU_ALARM_SW|RTC_BBPU_AUTOPDN|RTC_BBPU_KEY)
   #define RTC_BBPU_POWEROFF       (RTC_BBPU_WRITE_EN|RTC_BBPU_ALARM_SW|RTC_BBPU_AUTOPDN|RTC_BBPU_KEY)
#endif   /*DRV_RTC_BBPU_AS_6205B*/
/*0227 TY removes RTC_BBPU_ALARM_SW*/
#if defined(DRV_RTC_BBPU_AS_6218)
   #define RTC_BBPU_POWERON        (RTC_BBPU_PWR_SW|RTC_BBPU_PWR_POLARITY|RTC_BBPU_ALARM_SW|RTC_BBPU_AUTOPDN|RTC_BBPU_KEY)
   #define RTC_BBPU_POWEROFF       (RTC_BBPU_PWR_POLARITY|RTC_BBPU_ALARM_SW|RTC_BBPU_AUTOPDN|RTC_BBPU_KEY)
#endif   /*DRV_RTC_BBPU_AS_6218*/

#if defined(DRV_RTC_BBPU_AS_6276)
   #define RTC_BBPU_POWERON        (RTC_BBPU_PWR_SW|RTC_BBPU_ALARM_SW|RTC_BBPU_AUTOPDN|RTC_BBPU_KEY)
   #define RTC_BBPU_POWEROFF       (RTC_BBPU_ALARM_SW|RTC_BBPU_AUTOPDN|RTC_BBPU_KEY)
#endif   /*DRV_RTC_BBPU_AS_6205B*/

typedef struct __rtc 
{
	kal_uint8		rtc_sec;    /* seconds after the minute   - [0,59]  */
	kal_uint8		rtc_min;    /* minutes after the hour     - [0,59]  */
	kal_uint8		rtc_hour;   /* hours after the midnight   - [0,23]  */
	kal_uint8		rtc_day;    /* day of the month           - [1,31]  */
	kal_uint8		rtc_mon;    /* months 		               - [1,12] */
	kal_uint8		rtc_wday;   /* days in a week 		      - [1,7] */
	kal_uint8		rtc_year;   /* years                      - [0,127] */
} t_rtc;

typedef struct 
{
	void (*rtc_tcfunc)(void);
	void (*rtc_alfunc)(void); 
}rtc_callbac;

typedef struct
{
   kal_hisrid hisr;
}rtc_module;

typedef struct
{
kal_bool     time_valid;
t_rtc        rtc_time;
kal_bool     ticks_diff_valid;
kal_int32    ticks_diff_per_hour;
} rtc_nvram_data;

typedef struct{
   module_type       dest_mod_id;
   sap_type          sap_id;
   msg_type          msg_id;
}RTC_REG_MODULE_ILM_INFO_T;

typedef enum
{
    rtc_pdn1 = 0,
    rtc_pdn2,
    rtc_max_index
} RTC_PDN_INDEX;

#if defined(DRV_RTC_REG_SPAR)
typedef enum
{
    rtc_spar0 = 0,
    rtc_spar1,
    rtc_spar_max_index
}RTC_SPAR_INDEX;
#endif

#if defined(DRV_RTC_GPIO)
typedef enum {
   RTC_GPIO_DISABLE = 0,
   RTC_GPIO_EXPORT_32K,
   RTC_GPIO_EXPORT_COREDETB,
}RTC_GPIO_MODE_enum;

typedef enum {
   RTC_GPIO_NO_PULL = 0,
   RTC_GPIO_PULL_DOWN,
   RTC_GPIO_PULL_UP
}RTC_GPIO_PULL_TYPE_enum;

typedef enum {
   RTC_GPIO_DS_4mA = 0,
   RTC_GPIO_DS_8mA,
   RTC_GPIO_DS_12mA,
   RTC_GPIO_DS_16mA
}RTC_GPIO_DRIVING_STRENGTH_enum;
#endif //defined(DRV_RTC_GPIO)

#if defined(DRV_RTC_REG_COMM)

kal_uint16 RTC_Read_PDN(RTC_PDN_INDEX PDNIndex);
void RTC_Set_PDN_bits(RTC_PDN_INDEX PDNIndex,kal_uint16 flag);
void RTC_Clear_PDN_bits(RTC_PDN_INDEX PDNIndex,kal_uint16 flag);
void RTC_Write_PDN_bits(RTC_PDN_INDEX PDNIndex,kal_uint16 flag);

#endif //#if defined(DRV_RTC_REG_COMM)

#if defined(DRV_RTC_REG_SPAR)
kal_uint16 RTC_Read_SPAR(RTC_SPAR_INDEX SPARIndex);
void RTC_Write_SPAR(RTC_SPAR_INDEX SPARIndex, kal_uint16 flag);
#endif // End of #if defined(DRV_RTC_REG_SPAR)
// ============================================================
// Exported APIs, used by modules other than driver level functions
extern void RTC_Config_(kal_uint8 AL_EN,kal_uint8 TC_EN);
extern void RTC_InitTC_Time(t_rtc *rtctime);
extern void RTC_GetTime_(t_rtc *rtctime);
extern void RTC_SetAlarm(t_rtc *rtctime);
extern kal_bool RTC_GetALTime(t_rtc *rtctime);
extern kal_bool RTC_isFisrtOn(void);
extern void RTC_setPWRKey(void);
extern void RTC_setXOSC_(void);
extern void RTC_unlockPROT(void);
#if defined(DRV_RTC_LOW_POWER_DETECT)
extern void RTC_Clear_LPSTA_RAW(void);
extern void  RTC_Set_GPIO_Output_Mode(kal_bool value,kal_bool is_SlewRateOn);
extern kal_bool RTC_Get_GPIO_Input(void);
extern void RTC_Set_GPIO_Input_Mode(RTC_GPIO_PULL_TYPE_enum PullType,RTC_GPIO_DRIVING_STRENGTH_enum PullDs,kal_bool is_SmithTrigger);
extern void RTC_Set_GPIO_Mode(RTC_GPIO_MODE_enum Mode);
#endif //#if defined(DRV_RTC_LOW_POWER_DETECT)

// ============================================================
// MoDIS parser skip start
// Exported functions, used by driver level functions
extern kal_bool isPWROnByRTC(void);
extern void RTC_IRQOneShotEnable(kal_uint8 oneShotEN);
extern void RTC_LISR(void);
extern void RTC_init_(void (*RTC_TCCallback)(void),void (*RTC_ALCallback)(void));
extern kal_bool RTC_is_MS_FirstPowerOn_(void);
extern kal_bool RTC_is_config_valid(void);
extern kal_bool RTC_is_Time_Valid(t_rtc *time);
extern void RTC_GetTimeOnly(t_rtc *rtctime );
extern kal_uint8 RTC_read_xosc_reg(void);
extern void RTC_write_xosc_reg(kal_uint16 reg_value);
extern void RTC_SaveTC_Time(t_rtc *rtctime);
extern void RTC_set_First_PowerOn(kal_bool isFirstPowerOn);
extern kal_bool RTC_Bootloader_PowerOn_(void);

#if defined(DRV_RTC_HW_CALI)
extern void RTC_wait_busy(void);
extern void RTC_write_trigger(void);
extern void RTC_write_trigger_wait(void);
#endif /* defined(DRV_RTC_HW_CALI) */
// MoDIS parser skip end

// ============================================================
// MoDIS parser skip start
// Unknown functions, maybe previous owner forgot to delete
extern void RTC_BBPUOpen(kal_bool open);
extern void RTC_BBPWRUP_init(void);
// MoDIS parser skip end

#if defined(DRV_RTC_REG_COMM)
//pwic may change pdn value during booting, save the original value of pdn1.
extern kal_uint16  originalPDN1;
extern kal_uint16 RTC_original_pnd1(void);
#endif

#if !defined(__FUE__) && !defined(__UBL__)
extern kal_bool RTC_Set_Module_ILM_Info(RTC_REG_MODULE_ILM_INFO_T *Module_ilm_info);
#endif

#if !defined(DRV_RTC_OFF)
#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_RTC_REG_DBG__)
#define DRV_RTC_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_RTC_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_RTC_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_RTC_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_RTC_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_RTC_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_RTC_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_RTC_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_RTC_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_RTC_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_RTC_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_RTC_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_RTC_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_RTC_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_RTC_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_RTC_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_RTC_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_RTC_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_RTC_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_RTC_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_RTC_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_RTC_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_RTC_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_RTC_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_RTC_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_RTC_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_RTC_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_RTC_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_RTC_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_RTC_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_RTC_REG_DBG__)

#else //!defined(DRV_RTC_OFF)

#define DRV_RTC_WriteReg(addr,data)            
#define DRV_RTC_Reg(addr)                      drv_dummy_return()
#define DRV_RTC_WriteReg32(addr,data)          
#define DRV_RTC_Reg32(addr)                    drv_dummy_return()
#define DRV_RTC_WriteReg8(addr,data)           
#define DRV_RTC_Reg8(addr)                     drv_dummy_return()
#define DRV_RTC_ClearBits(addr,data)           
#define DRV_RTC_SetBits(addr,data)             
#define DRV_RTC_SetData(addr, bitmask, value)  
#define DRV_RTC_ClearBits32(addr,data)         
#define DRV_RTC_SetBits32(addr,data)           
#define DRV_RTC_SetData32(addr, bitmask, value)
#define DRV_RTC_ClearBits8(addr,data)          
#define DRV_RTC_SetBits8(addr,data)            
#define DRV_RTC_SetData8(addr, bitmask, value) 

#endif //!defined(DRV_RTC_OFF)

#endif

