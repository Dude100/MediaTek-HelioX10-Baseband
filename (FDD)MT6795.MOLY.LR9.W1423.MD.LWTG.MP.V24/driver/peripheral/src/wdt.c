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
 *    wdt.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the WDT driver.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "drv_features_wdt.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "wdt_hw.h"
#include "wdt_sw.h"
//#include "adc.h"
//#include "bmt.h"
//#include "keypad_hw.h"
#include  "keypad_sw.h"
//#include "pwic.h"
#include "intrCtrl.h"
//#include "isrentry.h"
#include "rtc_sw.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "dcl.h"
#include "wdt_hw_public.h"

/*nucleus schedule for WDT restart******************************************/
/*******************************************************************************
 * Define global data
 *******************************************************************************/
/* define the WDT restart register and abnormal reset check resgister */
/* [BB porting] please make sure the register address is correct and scatter file palced in the correct region */
//#pragma arm section rodata = "INIT_RODATA"
const kal_uint32 g_WATCHDOG_RESTART_REG   = WDT_RESTART;
const kal_uint32 g_WATCHDOG_RESTART_VALUE = WDT_RESTART_KEY;

#if !defined(DRV_WDT_6575_REG)
const kal_uint32 g_ABNORMAL_RST_REG       = WDT_RSTINTERVAL;
const kal_uint32 g_ABNORMAL_RST_VAL		  = WDT_RSTINTERVAL_VAL;
#else /* MT6575 */
const kal_uint32 g_ABNORMAL_RST_REG       = WDT_LENGTH;
const kal_uint32 g_ABNORMAL_RST_VAL		  = WDT_LENGTH_TOUT; 
#endif /* MT6575 */
//#pragma arm section rodata
/*******************************************/

 #if defined(DRV_WDT_WAKE_UP_AP_SIDE_BEFORE_SEND_INT) && defined(__MODEM_CCCI_EXIST__)
#include "ccci.h"
#endif


#if !defined(DRV_WDT_OFF)

/*lint -e552*/  
//althought not access in wdt.c, but it is accessed in pwic.c
kal_bool  WDT_RST;
/*lint +e552*/
#if defined(DRV_WDT_RESET_PKEY_RELEASE)
kal_uint8  TargetReset = 0;
extern BMTStruct BMT;
#endif


/*
* FUNCTION                                                            
*	WDT_SetValue
*
* DESCRIPTION                                                           
*   	This function is to set WDT count value
*
* CALLS  
*
* PARAMETERS
*	value: WDT count value
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void WDT_SetValue(kal_uint16 value)
{
	kal_uint16 tmp = (kal_uint16)value;
#if defined(DRV_WDT_LENGTH_11BITS)
   ASSERT(tmp <= 0x7ff);
   tmp = tmp << 5;
#else
   ASSERT(tmp <= 0xff);
	tmp = tmp << 8;
#endif
	DRV_WDT_WriteReg(WDT_LENGTH,(tmp | WDT_LENGTH_KEY));
}

/*
* FUNCTION                                                            
*	WDT_Enable
*
* DESCRIPTION                                                           
*   	This function is to enable WDT timer
*
* CALLS  
*
* PARAMETERS
*	en: KAL_TRUE, enable WDT
*	    FASLE, disable WDT
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void WDT_Enable(kal_bool en)
{
	kal_uint16 tmp = DRV_WDT_Reg(WDT_MODE);
	tmp |= WDT_MODE_KEY;
	if (en == KAL_TRUE)
	{
		tmp |= WDT_MODE_ENABLE;
	}
	else
	{
		tmp &= ~WDT_MODE_ENABLE;
	}
	DRV_WDT_WriteReg(WDT_MODE,tmp);
}
/*
* FUNCTION                                                            
*	WDT_EnableInterrupt
*
* DESCRIPTION                                                           
*   	This function is to enable/disable  IRQ bit in WDT_MODE register
*
* CALLS  
*
* PARAMETERS
*	en: KAL_TRUE, enable IRQ
*	    FASLE, disable IRQ
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/

void WDT_EnableInterrupt(kal_bool enable)
{
	kal_uint16 tmp = DRV_WDT_Reg(WDT_MODE);
	tmp |= WDT_MODE_KEY;
	if (enable == KAL_TRUE)
	{
		tmp |= WDT_MODE_IRQEN;
	}
	else
	{
		tmp &= ~WDT_MODE_IRQEN;
	}
	DRV_WDT_WriteReg(WDT_MODE,tmp);
}



/*
* FUNCTION                                                            
*	WDT_Enable
*
* DESCRIPTION                                                           
*   	This function is to set ploarity of external pin
*
* CALLS  
*
* PARAMETERS
*	extpol: KAL_TRUE, polarity = 1
*	        FASLE, polarity = 0
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void WDT_SetExtpol(IO_level extpol)
{
#if !defined (DRV_WDT_6575_REG)
	kal_uint16 tmp = DRV_WDT_Reg(WDT_MODE);
	tmp |= WDT_MODE_KEY;
	if (extpol == io_high)
	{
		tmp |= WDT_MODE_EXTPOL;
	}
	else
	{
		tmp &= ~WDT_MODE_EXTPOL;
	}
	DRV_WDT_WriteReg(WDT_MODE,tmp);
#endif
}

/*
* FUNCTION                                                            
*	WDT_SetExten
*
* DESCRIPTION                                                           
*   	This function is to generate an external watchdog reset signal
*
* CALLS  
*
* PARAMETERS
*	en: KAL_TRUE, generate an external watchdog reset signal when couter=0
*	    KAL_FALSE, not generate an external watchdog reset signal when couter=0
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void WDT_SetExten(kal_bool en)
{
#if !defined (DRV_WDT_6575_REG)
	kal_uint16 tmp = DRV_WDT_Reg(WDT_MODE);
	tmp |= WDT_MODE_KEY;
	if (en == KAL_TRUE)
	{
		tmp |= WDT_MODE_EXTEN;
	}
	else
	{
		tmp &= ~WDT_MODE_EXTEN;
	}
	DRV_WDT_WriteReg(WDT_MODE,tmp);
#endif
}

/*
* FUNCTION                                                            
*	WDT_Config
*
* DESCRIPTION                                                           
*   	This function is to configure WDT only called in WDT_init
*
* CALLS  
*
* PARAMETERS
*	extpol: KAL_TRUE, polarity = 1
*	        FASLE, polarity = 0
*	exten: KAL_TRUE, generate an external watchdog reset signal when couter=0
*	    KAL_FALSE, not generate an external watchdog reset signal when couter=0
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void WDT_Config(IO_level extpol, kal_bool exten)
{
	kal_uint16 tmp = DRV_WDT_Reg(WDT_MODE);
	tmp |= WDT_MODE_KEY;
	tmp &= ~WDT_MODE_ENABLE;
	
#ifndef DRV_WDT_6575_REG
	if (extpol == io_high)
	{
		tmp |= WDT_MODE_EXTPOL;
	}
	else
	{
		tmp &= ~WDT_MODE_EXTPOL;
	}
	
	if (exten == KAL_TRUE)
	{
		tmp |= WDT_MODE_EXTEN;
	}
	else
	{
		tmp &= ~WDT_MODE_EXTEN;
	}
#endif

#if defined(DRV_WDT_SMARTPHONE_AP_RESET_MODEM)
	tmp |= WDT_MODE_IRQEN;
	IRQMask(IRQ_WDT_CODE);
#endif //defined(DRV_WDT_SMARTPHONE_AP_RESET_MODEM)

	tmp |= WDT_MODE_KEY;
	DRV_WDT_WriteReg(WDT_MODE,tmp);
}

void WDT_Enable_Debug_Mode(kal_bool en)
{
	kal_uint16 tmp = DRV_WDT_Reg(WDT_MODE);
	tmp |= WDT_MODE_KEY;
	if (en==KAL_TRUE)
	{
		//IRQ_Register_LISR(IRQ_WDT_CODE,reg_lisr,"WDT LISR");
		IRQUnmask(IRQ_WDT_CODE);
		tmp |= WDT_MODE_IRQEN;
		tmp |= WDT_MODE_ENABLE;

	}
	else
	{
		//IRQ_Register_LISR(IRQ_WDT_CODE,IRQ_Default_LISR,"NULL handler");
		IRQMask(IRQ_WDT_CODE);
		tmp &= ~WDT_MODE_IRQEN;
		tmp &= ~WDT_MODE_ENABLE;
	}
	DRV_WDT_WriteReg(WDT_MODE,tmp);	
}

/*
void WDT_Enable_Debug_Mode(kal_bool en,void (*reg_lisr)(void))
{
	kal_uint16 tmp = DRV_WDT_Reg(WDT_MODE);
	tmp |= WDT_MODE_KEY;
	if (en==KAL_TRUE)
	{
		IRQ_Register_LISR(IRQ_WDT_CODE,reg_lisr,"WDT LISR");
		IRQUnmask(IRQ_WDT_CODE);
		tmp |= WDT_MODE_IRQEN;
		tmp |= WDT_MODE_ENABLE;

	}
	else
	{
		IRQ_Register_LISR(IRQ_WDT_CODE,IRQ_Default_LISR,"NULL handler");
		IRQMask(IRQ_WDT_CODE);
		tmp &= ~WDT_MODE_IRQEN;
		tmp &= ~WDT_MODE_ENABLE;
	}
	DRV_WDT_WriteReg(WDT_MODE,tmp);
}

*/


/*
* FUNCTION
*	WDT_init
*
* DESCRIPTION                                                           
*   	This function is to initialize the WDT module
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   None
*/
void WDT_init(void)
{
   WDT_RST = (DRV_WDT_Reg(WDT_STATUS) & WDT_STATUS_BITMASK)?(KAL_TRUE):(KAL_FALSE);  
   WDT_SetValue(255);
   WDT_Config(io_low,KAL_TRUE);
#ifndef DRV_WDT_6575_REG
   DRV_WDT_WriteReg(WDT_RSTINTERVAL,WDT_RSTINTERVAL_VALUE);
#endif
#if defined(DRV_WDT_IRQ_MODE)
   WDT_EnableInterrupt(KAL_TRUE);
   IRQSensitivity(IRQ_WDT_CODE,EDGE_SENSITIVE);
	 IRQUnmask(IRQ_WDT_CODE);
#endif
}
#if defined(DRV_WDT_RESET_PKEY_RELEASE)
static kal_bool WdtPowerKey_Pressed(void)
{
	HKBD_CTRL_POWKEY_T sta;	
	DCL_HANDLE handle;
	handle = DclHKBD_Open(DCL_KBD, 0);
	DclHKBD_Control(handle,HKBD_CMD_GET_POWER_KEY_STATUS , (DCL_CTRL_DATA_T*)&sta);
	return sta.fgPKP;
}
#endif
/*
* FUNCTION
*	   DRV_RESET
*
* DESCRIPTION                                                           
*   	This function is to reset our system
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void DRV_RESET(void)
{
	//kal_uint32 itmp;
	
#if defined(DRV_RTC_REG_COMM)//add by dongming for warning
	DCL_HANDLE rtc_handler;
	RTC_CTRL_CONFIG_PDN_BIT_T rtc_cmd_data8;
#endif
#if defined(DRV_WDT_RESET_PKEY_RELEASE)
kal_uint16 powerkey_status;
#if defined(__USB_ENABLE__)
	DCL_BOOL dcl_data = DCL_TRUE;
	DCL_HANDLE  usb_dcl_handle;

	usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);

	DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_PDN_ENABLE, (DCL_CTRL_DATA_T  *)&dcl_data);
	DclUSB_DRV_Close(usb_dcl_handle);

//   USB_PDNmode(KAl_TRUE);
#endif //#if defined(__USB_ENABLE__)
   #ifdef PMIC_PRESENT
   //#if ( (defined(MT6318))|| (defined(MT6305)) )
      if (BMT.PWRon != CHRPWRON)
      {
            switch(Pwrkey_Position)
   {
       case low_key:
         powerkey_status= DRV_WDT_Reg(KP_LOW_KEY);
         break;
/*#if 0
      case medium_key:
         powerkey_status= DRV_WDT_Reg(KP_MID_KEY);               
         break;
#endif  */        
      case high_key:
         powerkey_status= DRV_WDT_Reg(KP_HI_KEY);
         break;
      default:
         ASSERT(0);
         break;     
   }      
         if(WdtPowerKey_Pressed())     
         {
            TargetReset = 1;
         }
         else
         {
            /*lint -e(534)*/SaveAndSetIRQMask();

            WDT_SetValue(1);
            WDT_Restart();
            WDT_Enable(KAL_TRUE);
            while(1);
         }
      }
      else
      {
         /*lint -e(534)*/SaveAndSetIRQMask();
       
         WDT_SetValue(1);
         WDT_Restart();
         WDT_Enable(KAL_TRUE);
         while(1);
      }
   #else /*PMIC_PRESENT*/
      /*lint -e(534)*/SaveAndSetIRQMask();

      WDT_SetValue(1);
      WDT_Restart();
      WDT_Enable(KAL_TRUE);
      while(1);
   #endif   /*PMIC_PRESENT*/
#else /*!DRV_WDT_RESET_PKEY_RELEASE*/
   
   	kal_uint16 index;   
      /*lint -e(534)*/SaveAndSetIRQMask();	 
#if defined(DRV_WDT_WAKE_UP_AP_SIDE_BEFORE_SEND_INT) && defined(__MODEM_CCCI_EXIST__)
   	ccci_send_message(CCMSG_ID_MD_WDT_FLAG,0);
#endif	 
      for(index=0;index<1000;index++);  
   	#if defined(__USB_ENABLE__)
	{
	DCL_BOOL dcl_data = DCL_TRUE;
	DCL_HANDLE  usb_dcl_handle;

	usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);

	DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_PDN_ENABLE, (DCL_CTRL_DATA_T  *)&dcl_data);
	DclUSB_DRV_Close(usb_dcl_handle);
	}				  
//   USB_PDNmode(KAl_TRUE);
#endif //#if defined(__USB_ENABLE__)
   	
      #if defined(DRV_RTC_REG_COMM)
			//RTC_Set_PDN_bits(rtc_pdn2 ,DRV_COMM_REG2_NORMAL_RESET);
			rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
	    rtc_cmd_data8.PDNIndex = DCL_RTC_PDN2;
	    rtc_cmd_data8.fgConfigBit = DRV_COMM_REG2_NORMAL_RESET;
	    DclRTC_Control(rtc_handler, RTC_CMD_SET_PDN_BITS, (DCL_CTRL_DATA_T *)&rtc_cmd_data8); // New API with CMD & DATA	
      #endif   /*DRV_RTC_REG_COMM*/
   #if !defined(DRV_WDT_SWRST)
      WDT_SetValue(1);
      WDT_Restart();
      WDT_Enable(KAL_TRUE);
      while(1);
   #else
/*#if 0
#if defined(DRV_MISC_WDT_TURN_OFF_PLL)
      DRV_WDT_WriteReg(0x80000108, 0);
#endif // #if defined(DRV_MISC_WDT_TURN_OFF_PLL)
#endif*/
   #if defined(DRV_WDT_RETN_REG)// because add 32bit retention register,SW reset and restart register also from 16bit to 32bit
      DRV_WDT_WriteReg32(WDT_SWRST,WDT_SWRST_KEY);
   #else
      DRV_WDT_WriteReg(WDT_SWRST,WDT_SWRST_KEY);
   #endif
   
      while(1);
   #endif
#endif   /*!DRV_WDT_RESET_PKEY_RELEASE*/
}

void DRV_ABN_RESET(void)
{
	 //kal_uint32 itmp;
#if defined(DRV_RTC_REG_COMM)//add by dongming for warning
	DCL_HANDLE rtc_handler;
	RTC_CTRL_CONFIG_PDN_BIT_T rtc_cmd_data1;
#endif
   /*lint -e(534)*/SaveAndSetIRQMask();

#if defined(DRV_WDT_WAKE_UP_AP_SIDE_BEFORE_SEND_INT) && defined(__MODEM_CCCI_EXIST__)
	   ccci_send_message(CCMSG_ID_MD_WDT_FLAG,0);
#endif	


   #if defined(DRV_RTC_REG_COMM)
   //RTC_Clear_PDN_bits(rtc_pdn2 ,DRV_COMM_REG2_NORMAL_RESET);
  rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
	
	rtc_cmd_data1.PDNIndex = DCL_RTC_PDN2;
	rtc_cmd_data1.fgConfigBit = DRV_COMM_REG2_NORMAL_RESET;
	
	DclRTC_Control(rtc_handler, RTC_CMD_CLEAR_PDN_BITS, (DCL_CTRL_DATA_T *)&rtc_cmd_data1); // New API with CMD & DATA
   #endif   /*DRV_RTC_REG_COMM*/
   #if defined(DRV_WDT_SWRST)
   
/*#if 0
#if defined(DRV_MISC_WDT_TURN_OFF_PLL)
      DRV_WDT_WriteReg(0x80000108, 0);
#endif // #if defined(DRV_MISC_WDT_TURN_OFF_PLL)
#endif*/
   #endif
   WDT_SetValue(1);
   WDT_Restart();
   WDT_Enable(KAL_TRUE);
   while(1);
}

void WDT_Restart2(void)
{
#if defined(DRV_WDT_RETN_REG)// because add 32bit retention register,SW reset and restart register also from 16bit to 32bit
	DRV_WDT_WriteReg32(WDT_RESTART,WDT_RESTART_KEY);
#else
   DRV_WDT_WriteReg(WDT_RESTART,WDT_RESTART_KEY);
#endif
}

/*
* FUNCTION                                                            
*	WDT_CheckStat
*
* DESCRIPTION                                                           
*   	This function is to check whether reset is due to WDT
*
* CALLS  
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE, Reset due to that WDT Timer time-out period is reached.
*	KAL_FALSE, Reset not due to WDT
*
* GLOBALS AFFECTED
*   external_global
*/
#ifdef DRV_WDT_6205_CHECK_STAT
kal_uint8 WDT_CheckStat(void)
{
   kal_uint8 status;
   status = DRV_WDT_Reg(WDT_STATUS);
   return status;
}
#endif   /*DRV_WDT_6205_CHECK_STAT*/

kal_bool Is_WDT_Init()// for ex_item.c  
{
//WDT_RESINTERVAL will be 0xfff(default) when the first bootup, then WDT_RESINTERVAL will be 0xffa when wdt_init()
//if the value is 0xfff when bootup,we will kown this is the first bootup or normal reset
//if the value is 0ffa when bootup,we will kown this is abnormal reset
	#if defined(DRV_WDT_6575_REG)
	if( DRV_WDT_Reg(WDT_LENGTH) == WDT_LENGTH_VALUE_INIT )
		return KAL_TRUE;
	else
		return KAL_FALSE;
	#else
	if( DRV_WDT_Reg(WDT_RSTINTERVAL) == WDT_RSTINTERVAL_VALUE)
		return KAL_TRUE;
	else
		return KAL_FALSE;
	#endif
}


kal_uint32 Get_WATCHDOG_BASE()
{
	return WDT_RESTART;
}
kal_uint32 Get_WATCHDOG_RESTART_CMD()
{
	return WDT_RESTART_KEY;
}




#if defined(DRV_WDT_RETN_REG)
//for USBDLv2,when WDT reset,let BROM or bootloader know the two things:
// 1:  whether do USBDL  or not is  depends on The register:RETN_FLAG
// 2: RETN_DAT0:  How long the USBDL timeout 
void WDT_Write_RETN_FLAG(kal_uint8 flag)
{
	kal_uint32 uFlag;
	uFlag = WDT_RETN_FLAG_KEY | 0xff;
	DRV_WDT_WriteReg(WDT_RETN_FLAG_CLR,uFlag);
	uFlag = WDT_RETN_FLAG_KEY | flag;	
	DRV_WDT_WriteReg(WDT_RETN_FLAG_SET,uFlag);
	//bit 0: whether do USBDL  or not
	//bit 1: use BOOTROM or BOOTLOADER do USBDL
}
void WDT_SET_RETN_FLAG(kal_uint8 flag)
{
	kal_uint32 uFlag;
	uFlag = WDT_RETN_FLAG_KEY | flag;	
	DRV_WDT_WriteReg32(WDT_RETN_FLAG_SET,uFlag);// write 1 to set
	//bit 0: whether do USBDL  or not
	//bit 1: use BOOTROM or BOOTLOADER do USBDL
}
void WDT_CLR_RETN_FLAG(kal_uint8 flag)
{
	kal_uint32 uFlag;
	uFlag = WDT_RETN_FLAG_KEY | flag;
	DRV_WDT_WriteReg32(WDT_RETN_FLAG_CLR,uFlag);// write 1 to clear
	//bit 0: whether do USBDL  or not
	//bit 1: use BOOTROM or BOOTLOADER do USBDL
}

kal_uint8 WDT_Read_RETN_FLAG(void)
{
	return (kal_uint8)DRV_WDT_Reg32(WDT_RETN_FLAG);
}


void WDT_Write_RETN_DAT0(kal_uint32 value)
{
	DRV_WDT_WriteReg32(WDT_RETN_DAT0,value);
}
kal_uint32 WDT_Read_RETN_DAT0(void)
{
	return DRV_WDT_Reg32(WDT_RETN_DAT0);
}
#endif





#else
void DRV_ABN_RESET(void){}
void DRV_RESET(void){}
kal_uint8 WDT_CheckStat(void){}
void WDT_Config(IO_level extpol, kal_bool exten){}
void WDT_Enable(kal_bool en){}
void WDT_EnableInterrupt(kal_bool enable){}
void WDT_init(void){}
void WDT_Restart2(void){}
void WDT_SetExten(kal_bool en){}
void WDT_SetExtpol(IO_level extpol){}
void WDT_SetValue(kal_uint16 value){}
void WDT_Reset_DMA(void){}
void WDT_Enable_Debug_Mode(kal_bool en,void (*reg_lisr)(void)){}
kal_uint16 WDT_Read_RSTINTERVAL(void){}
kal_bool Is_WDT_Init(void){}
kal_uint32 Get_WATCHDOG_RESTART_CMD(void){}
kal_uint32 Get_WATCHDOG_BASE(void){}
#if defined(DRV_WDT_RETN_REG)
void WDT_Write_RETN_FLAG(kal_uint8 flag){}
void WDT_SET_RETN_FLAG(kal_uint8 flag){}
void WDT_CLR_RETN_FLAG(kal_uint8 flag){}
kal_uint8 WDT_Read_RETN_FLAG(void){}
void WDT_Write_RETN_DAT0(kal_uint32 value){}
kal_uint32 WDT_Read_RETN_DAT0(void){}
#endif


#endif //#if !defined(DRV_WDT_OFF)
