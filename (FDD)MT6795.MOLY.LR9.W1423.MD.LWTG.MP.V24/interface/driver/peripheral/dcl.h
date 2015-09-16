/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer).
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
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DCL_H__
#define __DCL_H__


#if !defined(GEN_FOR_PC) && !defined(NVRAM_AUTO_GEN)
#ifdef __CATEGORY_MODEM__
//#error drv_features.h include by modem detection
#endif 
#endif //!defined(GEN_FOR_PC) && !defined(NVRAM_AUTO_GEN)



#ifdef __CATEGORY_MODEM__  // doesn't need to include these module
//#define NONE_MODEM_BMT 
//#define NONE_MODEM_RTC 
#define NONE_MODEM_I2C
#define NONE_MODEM_AUX
//#define NONE_MODEM_KBDH 
//#define NONE_MODEM_KBD 
#define NONE_MODEM_PWM
#define NONE_MODEM_ALERTER
#define NONE_MODEM_TS
#define NONE_MODEM_SD
#define NONE_MODEM_USBD
#define NONE_MODEM_OTG
#define NONE_MODEM_IRDA
//#define NONE_MODEM_PW 
#define NONE_MODEM_PXS
#endif

//ZTE73
//#ifdef __MODEM_COMPONENT__  // doesn't need to include these module in modem ip
//#define NONE_MODEM_BMT 				//	l4misc
//#define NONE_MODEM_RTC 				// 	l4misc
//#define NONE_MODEM_KBDH 			//	l4_classb
//#define NONE_MODEM_KBD 				//	l4_classb
//#define NONE_MODEM_PW  				//	l4_classb
//#endif

//NAMI76
//#ifdef __MODEM_PRODUCT__ // doesn't need to include these module in modem product
//#define NONE_MODEM_BMT  	// l4misc
//#define NONE_MODEM_RTC  	// l4misc
//#define NONE_MODEM_KBDH  	// l4misc l4_calssb
//#define NONE_MODEM_KBD 		// l4misc l4_classb
//#define NONE_MODEM_PW 		// l4misc peripheral l4_classb
//#endif



typedef char              DCL_CHAR;
typedef signed char       DCL_INT8;
typedef signed short      DCL_INT16;
typedef signed long       DCL_INT32;

typedef unsigned char      DCL_UCHAR;
typedef unsigned char      DCL_UINT8;
typedef unsigned short     DCL_UINT16;
typedef unsigned long      DCL_UINT32;

#if !defined(GEN_FOR_PC) && defined(_MSC_VER)
   typedef signed __int64    DCL_INT64;
typedef unsigned __int64   DCL_UINT64;
#else
   typedef unsigned long long   DCL_UINT64;
   typedef signed long long     DCL_INT64;
#endif

typedef double             DCL_DOUBLE;
typedef int		DCL_INT;

//typedef int DCL_BOOL;
typedef enum
{
   DCL_FALSE = 0,
   DCL_TRUE
}DCL_BOOLEAN;

#define DCL_BOOL  DCL_BOOLEAN

#define	DCL_DEFINITION_STRUCT

#ifndef NONE_MODEM_GPT
#include "dcl_gpt.h"
#endif
#ifndef NONE_MODEM_GPIO
#include "dcl_gpio.h"
#endif
#ifndef NONE_MODEM_UART
#include "dcl_uart.h"
#endif
#ifndef NONE_MODEM_WDT
#include "dcl_wdt.h"
#endif
#ifndef NONE_MODEM_ADC
#include "dcl_adc.h"
#endif
#ifndef NONE_MODEM_BMT
#include "dcl_bmt.h"
#endif
#ifndef NONE_MODEM_PFC
#include "dcl_pfc.h"
#endif
#ifndef NONE_MODEM_RTC
#include "dcl_rtc.h"
#endif
#ifndef NONE_MODEM_I2C
#include "dcl_i2c.h"
#endif
#ifndef NONE_MODEM_AUX
#include "dcl_aux.h"
#endif
#if !defined(NONE_MODEM_PWM) && !defined(NONE_MODEM_ALERTER)
#include "dcl_pwm.h"
#endif
#ifndef NONE_MODEM_KBDH
#include "DclH_kbd.h"
#endif
#ifndef NONE_MODEM_KBD
#include "DclS_kbd.h"
#endif
#ifndef NONE_MODEM_STS
#include "dcl_sts.h"
#endif
#ifndef NONE_MODEM_MSDC
#include "dcl_msdc.h"
#endif
#ifndef NONE_MODEM_USB
#include "dcl_usb_drv.h"
#endif
#ifndef NONE_MODEM_USBD
#include "dcl_usb_hcd.h"
#endif
#ifndef NONE_MODEM_OTG
#include "dcl_otg_drv.h"
#endif
#ifndef NONE_MODEM_IRDA
#include "dcl_irda.h"
#endif
#ifndef NONE_MODEM_SIM
#include "dcl_sim.h"
#endif
#ifndef NONE_MODEM_PMU
#include "dcl_pmu.h"
#endif
#ifndef NONE_MODEM_PW
#include "dcl_pw.h"
#endif
#ifndef NONE_MODEM_CHR_USB_DET
#include "dcl_chr_det.h"
#endif
#ifndef NONE_MODEM_PXS
#include "dcl_pxs.h"
#endif
#ifndef NONE_MODEM_SIM_GPIO
#include "dcl_sim_gpio.h"
#endif
#ifndef NONE_MODEM_F32K_CLK
#include "dcl_f32k_clk.h"
#endif
#ifndef NONE_MODEM_IDC
#include "dcl_idc.h"
#endif

/*******************************************************************************
 * DCL_STATUS 
 *******************************************************************************/
#if defined(STATUS_OK)
#undef STATUS_OK
#endif

#if defined(STATUS_FAIL)
#undef STATUS_FAIL  
#endif  

typedef DCL_INT32 DCL_STATUS;
typedef enum
{
   STATUS_OK = 0,
   STATUS_FAIL = -1,
   STATUS_INVALID_CMD = -2,
   STATUS_UNSUPPORTED = -3,
   STATUS_NOT_OPENED = -4,
   STATUS_INVALID_EVENT = -5,
   STATUS_INVALID_DCL_HANDLE = -6,
   STATUS_INVALID_CTRL_DATA = -7,
   STATUS_INVALID_CONFIGURATION = -8,
   STATUS_INVALID_ARGUMENT = -9,
   STATUS_ERROR_TIMEOUT = -10,
   STATUS_ERROR_CRCERROR = -11,
   STATUS_ERROR_READONLY = -12,
   STATUS_ERROR_WRONG_STATE = -13,
   STATUS_INVALID_DEVICE = -14,
   STATUS_ALREADY_OPENED = -15,
   STATUS_SET_VFIFO_FAIL = -16,
   STATUS_INVALID_OPERATION = -17,
   STATUS_DEVICE_NOT_EXIST = -18,

   //*/ I2C DCL added /*//
   STATUS_DEVICE_NOT_SUPPORT_DMA = -19,
   STATUS_DEVICE_IS_BUSY = -20,
   STATUS_ACKERR = -21, 
   STATUS_HS_NACKERR = -22,

   STATUS_BUFFER_EMPTY = 1
} DCL_STATUS_T;

/*******************************************************************************
 * DCL_DEV
 *******************************************************************************/
typedef DCL_UINT16 DCL_DEV;
typedef enum
{
#ifndef NONE_MODEM_UART	
   DCL_UART_GROUP_START = 0,
   DCL_UART_DEV // Marco defined in dcl_uart.h
#endif
#ifndef NONE_MODEM_GPIO   
   DCL_GPIO_GROUP_START = 0x100,
   DCL_GPIO,
   DCL_GPO,
   DCL_GPIO_CLK,
#endif   
#ifndef NONE_MODEM_GPT   
   DCL_GPT_GROUP_START = 0x200,
   DCL_GPT_CB,
   DCL_GPT_CB2,
   DCL_GPT_BusyWait,
   DCL_GPT_FreeRUN3,
   DCL_GPT_FreeRUN4,
   DCL_GPT_DEBUG,
   DCL_XGPT,
   DCL_GPT_CB_MS, 
   DCL_GPT_CRITICAL_CB_MS,
#endif   
#ifndef NONE_MODEM_PWM  
   DCL_PWM_GROUP_START = 0x300,
   DCL_PWM1,
   DCL_PWM2,
   DCL_PWM3,
   DCL_PWM4,
   DCL_PWM5,
   DCL_PWM6,
#endif   
   DCL_PWM_GROUP_END = 0x400,
   DCL_REST_GROUP_START = DCL_PWM_GROUP_END,
#ifndef NONE_MODEM_BMT   
   DCL_BMT_GROUP_START = 0x500,    
   DCL_BMT,
#endif
#ifndef NONE_MODEM_PFC  
   DCL_PFC_GROUP_START = 0x600,  
   DCL_PFC,
#endif     
#ifndef NONE_MODEM_RTC 
   DCL_RTC_GROUP_START = 0x700,    
   DCL_RTC,
#endif     
#ifndef NONE_MODEM_ADC 
   DCL_ADC_GROUP_START = 0x800,      
   DCL_ADC,
#endif    
#ifndef NONE_MODEM_PMU
   DCL_PMU_GROUP_START = 0x900,      
   DCL_PMU,
#endif    
#ifndef NONE_MODEM_PW 
   DCL_PW_GROUP_START = 0xA00,    
   DCL_PW,
#endif    
#ifndef NONE_MODEM_CHR_USB_DET
   DCL_CHR_USB_DET_GROUP_START = 0xB00,   
   DCL_CHR_USB_DET,
#endif    
#ifndef NONE_MODEM_ALERTER   
   DCL_ALERTER_GROUP_START = 0xC00,
   DCL_ALERTER,
#endif 
#ifndef NONE_MODEM_KBD 
   DCL_KBD_GROUP_START = 0xD00,  
   DCL_KBD,
#endif    
#ifndef NONE_MODEM_TS 
   DCL_TS_GROUP_START = 0xE00,     
   DCL_TS,
#endif    
#ifndef NONE_MODEM_I2C  
   DCL_I2C_GROUP_START = 0xF00,  
   DCL_I2C,
#endif
/* Moly have no ACCDET*/    
#if 0
#ifndef NONE_MODEM_AUX  
/* under construction !*/
/* under construction !*/
#endif 
#endif
#ifndef NONE_MODEM_WDT 
   DCL_WDT_GROUP_START = 0x1100,  
   DCL_WDT,
#endif   
#ifndef NONE_MODEM_IRDA
   DCL_IRDA_GROUP_START = 0x1200,  
   DCL_IRDA,
#endif 
#ifndef NONE_MODEM_USB
   DCL_USB_GROUP_START = 0x1300,   
   DCL_USB,
#endif    
#ifndef NONE_MODEM_SIM 
   DCL_SIM_GROUP_START = 0x1400,   
   DCL_SIM,
#endif     
#ifndef NONE_MODEM_SD
   DCL_SD_GROUP_START = 0x1500,   
   DCL_SD,
#endif
#ifndef NONE_MODEM_MS 
   DCL_MS_GROUP_START = 0x1600,   
   DCL_MS,
#endif    
#ifndef NONE_MODEM_SDIO 
   DCL_SDIO_GROUP_START = 0x1700,   
   DCL_SDIO,
#endif    
#ifndef NONE_MODEM_ONEW 
   DCL_ONEW_GROUP_START = 0x1800,   
   DCL_ONEW, //1-wire
#endif    
#ifndef NONE_MODEM_HDQ
   DCL_HDQ_GROUP_START = 0x1900,    
   DCL_HDQ,
#endif    
#ifndef NONE_MODEM_PXS
   DCL_PXS_GROUP_START = 0x1A00,   
   DCL_PXS,
#endif 
#ifndef NONE_MODEM_SIM_GPIO  
   DCL_SIM_GPIO_GROUP_START = 0x1B00, 
   DCL_SIM_GPIO,
#endif    
#ifndef NONE_MODEM_SIM_GPI
   DCL_SIM_GPI_GROUP_START = 0x1C00,    
   DCL_SIM_GPI,
#endif  
#ifndef NONE_MODEM_F32K_CLK
   DCL_F32K_CLK_GROUP_START = 0x1D00,
   DCL_F32K_CLK,
#endif  
#ifndef NONE_MODEM_IDC
   DCL_IDC_GROUP_START = 0x1E00,  
   DCL_IDC
#endif     
} DCL_DEV_T;

/*******************************************************************************
 * DCL_FLAGS
 *******************************************************************************/
typedef DCL_UINT32 DCL_FLAGS;
typedef enum
{
   FLAGS_NONE = 0,
   FLAGS_END
} DCL_FLAGS_T;


/*******************************************************************************
 * DCL_OPTIONS
 *******************************************************************************/
typedef DCL_UINT32 DCL_OPTIONS;
typedef enum
{
   OPTIONS_NONE = 0,
#ifndef NONE_MODEM_GPT   
   GPT_OPTIONS_START = OPTIONS_NONE,
   GPT_OPTIONS //Please see dcl_gpt.h
#endif  
#ifndef NONE_MODEM_GPIO   
   GPIO_OPTIONS_START = 0x100,
   GPIO_OPTIONS //Please see dcl_gpio.h
#endif  
#ifndef NONE_MODEM_ADC   
   ADC_OPTIONS_START = 0x200,
   ADC_OPTIONS //Please see dcl_adc.h
#endif  
#ifndef NONE_MODEM_WDT   
   WDT_OPTIONS_START = 0x300,
   WDT_OPTIONS //Please see dcl_wdt.h
#endif  
#ifndef NONE_MODEM_BMT       
   BMT_OPTIONS_START = 0x400,
   BMT_OPTIONS // Please see dcl_bmt.h   
#endif   
#ifndef NONE_MODEM_PFC
   PFC_OPTIONS_START = 0x500,
   PFC_OPTIONS // Please see dcl_pfc.h   
#endif  
#ifndef NONE_MODEM_RTC   
   RTC_OPTIONS_START = 0x600,
   RTC_OPTIONS // Please see dcl_rtc.h
#endif  
#ifndef NONE_MODEM_I2C  
   I2C_OPTIONS_START = 0x700,
   I2C_OPTIONS //Please see dcl_i2c.h
#endif  
#if 0
#ifndef NONE_MODEM_AUX
/* under construction !*/
/* under construction !*/
#endif  
#endif
#ifndef NONE_MODEM_TS
   TS_OPTIONS_START = 0x900,
   TS_OPTIONS//Please see dcl_ts.h
#endif
#ifndef NONE_MODEM_USB   
   USB_DRV_OPTIONS_START = 0xA00,
   USB_DRV_OPTIONS//Please see dcl_usb_drv.h
#endif  
#ifndef NONE_MODEM_USBD  
   USB_HCD_OPTIONS_START = 0xB00,
   USB_HCD_OPTIONS//Please see dcl_usb_hcd.h
#endif  
#ifndef NONE_MODEM_OTG
   OTG_DRV_OPTIONS_START = 0xC00,
   OTG_DRV_OPTIONS//Please see dcl_otg_drv.h
#endif  
#ifndef NONE_MODEM_IRDA
   IRDA_OPTIONS_START = 0xD00,
   IRDA_OPTIONS//Please see dcl_irda.h
#endif   
#ifndef NONE_MODEM_PMU
   PMU_OPTIONS_START = 0xE00,
   PMU_OPTIONS // Please see dcl_pmu.h
#endif  
#ifndef NONE_MODEM_PW
   PW_OPTIONS_START = 0xF00,
   PW_OPTIONS // Please see dcl_pw.h
#endif  
#ifndef NONE_MODEM_CHR_USB_DET
   CHR_DET_OPTIONS_START = 0x1000,
   CHR_DET_OPTIONS // Please see dcl_chr_usb_det.h
#endif     
#ifndef NONE_MODEM_PXS
   PXS_OPTIONS_START = 0x2000,
   PXS_OPTIONS // Please see dcl_pxs.h
#endif   
#ifndef NONE_MODEM_F32K_CLK
   F32K_CLK_OPTIONS_START = 0x4000,
   F32K_CLK_OPTIONS // Please see dcl_f32k_clk.h
#endif  
#ifndef NONE_MODEM_IDC
   IDC_OPTIONS_START = 0x5000,
   IDC_OPTIONS // Please see dcl_idc.h
#endif  
   OPTIONS_MAX
} DCL_OPTIONS_T;

/*******************************************************************************
 * DCL_HANDLE
 *******************************************************************************/
typedef DCL_INT32 DCL_HANDLE;
#define DCL_HANDLE_NONE    (0)
#define DCL_HANDLE_INVALID    (-1)
#define DCL_HANDLE_OCCUPIED    (-2)

/*******************************************************************************
 * DCL_BUFF
 *******************************************************************************/
typedef DCL_UINT8  DCL_BUFF;
typedef DCL_UINT32  DCL_BUFF_LEN;

/*******************************************************************************
 * DCL_CONFIGURE_T
 *******************************************************************************/
typedef union
{
#ifndef NONE_MODEM_PWM
   PWM_CONFIGS//Please see dcl_PWM.h
#endif  
#ifndef NONE_MODEM_ADC 
   // For ADC, please see dcl_adc.h
   ADC_CONFIGS
#endif
#ifndef NONE_MODEM_BMT    
   // For BMT, please see dcl_bmt.h
   BMT_CONFIGS   
#endif  
#ifndef NONE_MODEM_PFC 
   // For PFC, please see dcl_pfc.h
   PFC_CONFIGS   
#endif
#ifndef NONE_MODEM_RTC
   // For RTC, please see dcl_rtc.h
   RTC_CONFIGS
#endif
#ifndef NONE_MODEM_WDT    
   // For WDT, please see dcl_wdt.h
   WDT_CONFIGS
#endif
#ifndef NONE_MODEM_I2C   
   // For I2C, please see dcl_i2c.h
   I2C_CONFIGS
#endif
#if 0
#ifndef NONE_MODEM_AUX      
/* under construction !*/
/* under construction !*/
#endif   
#endif
#ifndef NONE_MODEM_USB
   // For USB_DRV, please see dcl_usb_drv.h
   USB_DRV_CONFIGS
#endif
#ifndef NONE_MODEM_USBD
   // For USB_HCD, please see dcl_usb_hcd.h
   USB_HCD_CONFIGS
#endif
#ifndef NONE_MODEM_OTG   
   // For OTG_DRV, please see dcl_otg_drv.h
   OTG_DRV_CONFIGS
#endif
#ifndef NONE_MODEM_IRDA
   // For IRDA, please see dcl_irda.h
   IRDA_CONFIGS
#endif   
#ifndef NONE_MODEM_PMU
   // For PMU, please see dcl_pmu.h
   PMU_CONFIGS
#endif
#ifndef NONE_MODEM_PW
   // For PW, please see dcl_pw.h
   PW_CONFIGS   
#endif
#ifndef NONE_MODEM_CHR_USB_DET
   // For CHR&USB detection , please see dcl_chr_usb_det.h
   CHR_DET_CONFIGS
#endif
#ifndef NONE_MODEM_SIM
   // For SIM, please see dcl_sim.h
   SIM_CONFIGS
#endif  
#ifndef NONE_MODEM_TS
   //for TS, please see dcl_ts.h
   TS_CONFIGS
#endif
#ifndef NONE_MODEM_PXS
   // For PXS, please see dcl_pxs.h
   PXS_CONFIGS
#endif
#ifndef NONE_MODEM_F32K_CLK
   // For F32K_CLK, please see dcl_f32k_clk.h
   F32K_CLK_CONFIGS
#endif  
#ifndef NONE_MODEM_IDC
   // For IDC, please see dcl_idc.h
   IDC_CONFIGS   
#endif
} DCL_CONFIGURE_T;


/*******************************************************************************
 * DCL_EVENT
 *******************************************************************************/
typedef DCL_UINT32  DCL_EVENT;
typedef enum
{
   EVENT_NULL = 0,
#ifndef NONE_MODEM_GPT
   // For HGPT, please see dcl_gpt.h
   GPT_EVENTS_START = EVENT_NULL,
   GPT_EVENTS
#endif  
#ifndef NONE_MODEM_GPIO
   //for GPIO, please see dcl_gpio.h
   GPIO_EVENTS_START = 0x100,
   GPIO_EVENTS
#endif  
#ifndef NONE_MODEM_BMT     
   // For BMT, please see dcl_bmt.h
   BMT_EVENTS_START = 0x200,
   BMT_EVENTS
#endif   
#ifndef NONE_MODEM_PFC
   // For PFC, please see dcl_pfc.h
   PFC_EVENTS_START = 0x300,
   PFC_EVENTS
#endif  
#ifndef NONE_MODEM_RTC
   // For RTC, please see dcl_rtc.h
   RTC_EVENTS_START = 0x400,
   RTC_EVENTS
#endif  
#ifndef NONE_MODEM_WDT
   // For WDT, please see dcl_wdt.h
   WDT_EVENTS_START = 0x500,
   WDT_EVENTS
#endif  
#ifndef NONE_MODEM_ADC
   // For ADC, please see dcl_adc.h
   ADC_EVENTS_START = 0x600,
   ADC_EVENTS
#endif  
#ifndef NONE_MODEM_I2C  
   // For I2C, please see dcl_i2c.h
   I2C_EVENTS_START = 0x700,
   I2C_EVENTS
#endif  
#if 0
#ifndef NONE_MODEM_AUX
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
#endif
#ifndef NONE_MODEM_KBDH
   //For Keypad, Please see dcl_kbd.h
   KBDH_EVENTS_START = 0x900,
   KBDH_EVENTS
#endif  
#ifndef NONE_MODEM_TS       
   //For TS, Please see dcl_ts.h
   TS_EVENTS_START = 0xA00,
   TS_EVENTS
#endif   
#ifndef NONE_MODEM_USB
   //For USB_DRV, please see dcl_usb_drv.h
   USB_DRV_EVENTS_START = 0xB00,
   USB_DRV_EVENTS
#endif  
#ifndef NONE_MODEM_USBD  
   //For USB_HCD, please see dcl_usb_hcd.h
   USB_HCD_EVENTS_START = 0xC00,
   USB_HCD_EVENTS
#endif  
#ifndef NONE_MODEM_OTG   
   //For OTG_DRV, please see dcl_otg_drv.h
   OTG_DRV_EVENTS_START = 0xD00,
   OTG_DRV_EVENTS
#endif  
#ifndef NONE_MODEM_IRDA
   // For IrDA, please see dcl_irda.h
   IRDA_EVENTS_START = 0xE00,
   IRDA_EVENTS
#endif   
#ifndef NONE_MODEM_PMU
   // For pmu, please see dcl_pmu.h
   PMU_EVENTS_START = 0xF00,
   PMU_EVENTS
#endif  
#ifndef NONE_MODEM_PW
   // For pw, please see dcl_pw.h
   PW_EVENTS_START = 0x1000,
   PW_EVENTS
#endif  
#ifndef NONE_MODEM_CHR_USB_DET
   // For Chr&USB detection , please see dcl_chr_usb_det.h
   CHR_DET_EVENTS_START = 0x1100,
   CHR_DET_EVENTS
#endif  
#ifndef NONE_MODEM_PXS  
   // For PXS, please see dcl_pxs.h
   PXS_EVENTS_START = 0x1200,
   PXS_EVENTS
#endif   
#ifndef NONE_MODEM_F32K_CLK
   // For F32K_CLK, please see dcl_f32k_clk.h
   F32K_CLK_EVENTS_START = 0x1300,
   F32K_CLK_EVENTS  
#endif  
#ifndef NONE_MODEM_IDC
   // For IDC, please see dcl_idc.h
   IDC_EVENTS_START = 0x1400,
   IDC_EVENTS
#endif  
   EVENT_END
} DCL_EVENT_T;

/*******************************************************************************
 * PFN_DCL_CALLBACK
 *******************************************************************************/
typedef void (*PFN_DCL_CALLBACK)(DCL_EVENT event);

/*******************************************************************************
 * DCL_CTRL_CMD
 *******************************************************************************/
#if defined(CMD_END)
#undef CMD_END  
#endif 
typedef DCL_UINT32  DCL_CTRL_CMD;
typedef enum
{
   CMDS_START = 0,
   /* Below is the command for GPIO */
#ifndef NONE_MODEM_GPIO
   //please make sure GPIO Command start from zero! [drv_tool genertate a char type variable]
   GPIO_CMDS_START = CMDS_START, 
   GPIO_CMDS //please see dcl_gpio.h
#endif
#ifndef NONE_MODEM_UART
   /* Below is the command for UART */
   UART_CMDS_START = 0x100,
   UART_CMDS //please see dcl_uart.h
#endif
#ifndef NONE_MODEM_GPT
   /* Below is the command for GPT */
   GPT_CMDS_START = 0x200,
   GPT_CMDS //please see dcl_gpt.h
#endif
#ifndef NONE_MODEM_ADC
   /* Below is the command for ADC */
     /* Exported adc schedule APIs */
   ADC_CMDS_START = 0x300,
   ADC_CMDS
     /* Interfac for Hardware ADC */
   HADC_CMDS_START = 0x400,
   HADC_CMDS
#endif   
#ifndef NONE_MODEM_WDT
   /* Below is the command for WDT */
   WDT_CMDS_START = 0x500,
   WDT_CMDS
#endif   
#ifndef NONE_MODEM_BMT  
   /* Below is the command for BMT */
   BMT_CMDS_START = 0x600,
   BMT_CMDS // Please see dcl_bmt.h
#endif  
#ifndef NONE_MODEM_PFC
   /* Below is the command for PFC */
   PFC_CMDS_START = 0x700,
   PFC_CMDS // Please see dcl_pfc.h
#endif
#ifndef NONE_MODEM_RTC
   /* Below is the command for RTC */
   RTC_CMDS_START = 0x800,
   RTC_CMDS // Please see dcl_rtc.h
#endif
#ifndef NONE_MODEM_I2C  
   /* Below is the command for I2C */
   I2C_CMDS_START = 0x900,
   I2C_CMDS
#endif
#if 0
#ifndef NONE_MODEM_AUX
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   
#endif
#ifndef NONE_MODEM_KBDH
   /* Below is the command for KBD */
   KBDH_CMDS_START = 0xB00,
   KBDH_CMDS
#endif
#ifndef NONE_MODEM_KBD
   KBD_CMDS_START = 0xC00,
   KBD_CMDS//Please see dcl_kbd.h
#endif
#ifndef NONE_MODEM_PWM   
   /* Below is the command for OWM */
   PWM_CMDS_START = 0xD00,
   PWM_CMDS//Please see dcl_PWM.h
#endif
#ifndef NONE_MODEM_ALERTER
   ALERTER_CMDS_START = 0xE00,
   ALERTER_CMDS //please see dcl_pwm.h
#endif
#ifndef NONE_MODEM_TS
   /* Below is the command for TS */
   TS_CMDS_START = 0xF00,
   TS_CMDS//Please see dcl_ts.h
#endif
#ifndef NONE_MODEM_SD
   /* Below is the command for SD*/
   SD_CMDS_START = 0x1000,
   SD_CMDS//Please see dcl_msdc.h
#endif   
#ifndef NONE_MODEM_SDIO
   /* Below is the command for SDIO*/
   SDIO_CMDS_START = 0x1100,
   SDIO_CMDS//Please see dcl_msdc.h
#endif
#ifndef NONE_MODEM_USB
   /* Below is the commands for USB_DRV, please see dcl_usb_drv.h */
   USB_DRV_CMDS_START = 0x1300,
   USB_DRV_CMDS
#endif
#ifndef NONE_MODEM_USBD 
   /* Below is the commands for USB_HCD, please see dcl_usb_hcd.h */
   USB_HCD_CMDS_START = 0x1400,
   USB_HCD_CMDS
#endif
#ifndef NONE_MODEM_OTG
   /* Below is the commands for OTG_DRV, please see dcl_otg_drv.h */
   OTG_DRV_CMDS_START = 0x1500,
   OTG_DRV_CMDS
#endif
#ifndef NONE_MODEM_IRDA
   /* Below is the command for IRDA*/
   IRDA_CMDS_START = 0x1600,
   IRDA_CMDS//Please see dcl_irda.h
#endif   
#ifndef NONE_MODEM_SIM
   /* Below is the command for SIM*/
   SIM_CMDS_START = 0x1700,
   SIM_CMDS//Please see dcl_msdc.h
#endif
#ifndef NONE_MODEM_PMU
   /* Below is the command for PMU */
   PMU_CMDS_START = 0x1800,
   PMU_CMDS //Please see dcl_pmu.h
#endif
#ifndef NONE_MODEM_PW
   /* Below is the command for PW */
   PW_CMDS_START = 0x1900,
   PW_CMDS //Please see dcl_pw.h
#endif
#ifndef NONE_MODEM_CHR_USB_DET
   /* Below is the command for CHR USB DETECT */
   CHR_DET_CMDS_START = 0x1A00,
   CHR_DET_CMDS //Please see dcl_chr_usb_det.h
#endif
#ifndef NONE_MODEM_PXS   
   /* Below is the command for PXS */
   PXS_CMDS_START = 0x1B00,
   PXS_CMDS //Please see dcl_pxs.h
#endif   
#ifndef NONE_MODEM_SIM_GPIO
	/* Below is the command for SIM GPIO */
    SIMGPIO_CMDS_START = 0x1C00,
	SIMGPIO_CMDS //Please see dcl_sim_gpio.h
#endif 
#ifndef NONE_MODEM_F32K_CLK
 /* Below is the command for F32K_CLK */
   F32K_CLK_CMDS_START = 0x1D00,
   F32K_CLK_CMDS //please see dcl_f32k_clk.h	
#endif 
#ifndef NONE_MODEM_IDC
   /* Below is the command for IDC */
   IDC_CMDS_START = 0x1E00,
   IDC_CMDS // Please see dcl_idc.h
#endif
   CMD_END
} DCL_CTRL_CMD_T;

/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
typedef union
{
#ifndef NONE_MODEM_GPT
   /* GPT control datas, please see dcl_gpt.h */
   GPT_CTRLS
#endif 
#ifndef NONE_MODEM_UART
   /* UART control datas, please see dcl_uart.h */
   UART_CTRLS
#endif 
#ifndef NONE_MODEM_GPIO
   /* GPIO control datas, please see dcl_gpio.h */
   GPIO_CTRLS
#endif 
#ifndef NONE_MODEM_ADC
   /* ADC control datas, please see dcl_adc.h */
   ADC_CTRLS
#endif 
#ifndef NONE_MODEM_WDT
   /* WDT control datas, please see dcl_wdt.h */
   WDT_CTRLS
#endif 
#ifndef NONE_MODEM_BMT
   /* Below is the ctrl structures for BMT */
   BMT_CTRLS //Please see dcl_bmt.h
#endif   
#ifndef NONE_MODEM_PFC
   /* Below is the ctrl structures for PFC */
   PFC_CTRLS // Please see dcl_pfc.h
#endif 
#ifndef NONE_MODEM_RTC
   /* RTC control datas, please see dcl_rtc.h */
   RTC_CTRLS // Please see dcl_rtc.h
#endif 
#ifndef NONE_MODEM_I2C    
   /* I2C control datas, please see dcl_i2c.h */
   I2C_CTRLS
#endif 
#if 0
#ifndef NONE_MODEM_AUX
/* under construction !*/
/* under construction !*/
#endif
#endif
#ifndef NONE_MODEM_KBD
   /* KBD control datas, please see dcl_kbd.h */
  KBDS_CTRLS//Please see dcl_kbd.h
#endif 
#ifndef NONE_MODEM_KBDH
   KBDH_CTRLS
#endif 
#ifndef NONE_MODEM_PWM     
   /* PWM control datas, please see dcl_PWM.h */
   PWM_CTRLS//Please see dcl_PWM.h   
#endif 
#ifndef NONE_MODEM_ALERTER
   ALERTER_CTRLS
#endif 
#ifndef NONE_MODEM_TS
   /* TS control datas, please see dcl_ts.h */
   TS_CTRLS//Please see dcl_ts.h
#endif 
#ifndef NONE_MODEM_SD
   /* Below is the ctrl structures for SD*/
   SD_CTRLS//Please see dcl_msdc.h
#endif   
#ifndef NONE_MODEM_SDIO
   /* Below is the ctrl structures for SDIO*/
   SDIO_CTRLS//Please see dcl_msdc.h
#endif 
#ifndef NONE_MODEM_USB
   /* Below is the control data structures for USB_DRV, please see dcl_usb_drv.h */
   USB_DRV_CTRLS
#endif 
#ifndef NONE_MODEM_USBD  
   /* Below is the control data structures for USB_HCD, please see dcl_usb_hcd.h */
   USB_HCD_CTRLS
#endif 
#ifndef NONE_MODEM_OTG
   /* Below is the control data structures for OTG_DRV, please see dcl_otg_drv.h */
   OTG_DRV_CTRLS
#endif 
#ifndef NONE_MODEM_IRDA
   /* Below is the ctrl structures for IRDA*/
   IRDA_CTRLS//Please see dcl_irda.h
#endif   
#ifndef NONE_MODEM_SIM
   /* Below is the ctrl structures for SIM*/
   SIM_CTRLS//Please see dcl_sim.h
#endif 
#ifndef NONE_MODEM_PMU
   /* Below is the ctrl structures for PMU */
   PMU_CTRLS//Please see dcl_pmu.h
#endif 
#ifndef NONE_MODEM_PW
   /* Below is the ctrl structures for Power up reason */
   PW_CTRLS//Please see dcl_pW.h
#endif 
#ifndef NONE_MODEM_CHR_USB_DET
   /* Below is the ctrl structures for Chr & USB detection */
   CHR_DET_CTRLS//Please see dcl_chr_usb_det.h   
#endif 
#ifndef NONE_MODEM_PXS
   /* Below is the ctrl structures for PXS */
   PXS_CTRLS//Please see dcl_pxs.h
#endif 
#ifndef NONE_MODEM_SIM_GPIO  
   /* Below is the ctrl structures for SIM_GPIO */
   SIMGPIO_CTRLS//Please see dcl_sim_gpio.h      
#endif       
#ifndef NONE_MODEM_F32K_CLK
   /* Below is the ctrl structures for SIM_GPIO */
   F32K_CLK_CTRLS//please see dcl_f32k_clk.h   	
#endif   
#ifndef NONE_MODEM_IDC
   /* Below is the ctrl structures for IDC */
   IDC_CTRLS//please see dcl_idc.h
#endif 
} DCL_CTRL_DATA_T;


/*definitions of structures are finished, undefine DCL_DEFINITION_STRUCT*/
#undef DCL_DEFINITION_STRUCT
#define DCL_DEFINITION_PROTOTYPE

#ifndef NONE_MODEM_GPT
#include "dcl_gpt.h"
#endif
#ifndef NONE_MODEM_GPIO
#include "dcl_gpio.h"
#endif
#ifndef NONE_MODEM_UART
#include "dcl_uart.h"
#endif
#ifndef NONE_MODEM_WDT
#include "dcl_wdt.h"
#endif
#ifndef NONE_MODEM_ADC
#include "dcl_adc.h"
#endif
#ifndef NONE_MODEM_BMT
#include "dcl_bmt.h"
#endif
#ifndef NONE_MODEM_PFC
#include "dcl_pfc.h"
#endif
#ifndef NONE_MODEM_RTC
#include "dcl_rtc.h"
#endif
#ifndef NONE_MODEM_I2C
#include "dcl_i2c.h"
#endif
#ifndef NONE_MODEM_AUX
#include "dcl_aux.h"
#endif
#if !defined(NONE_MODEM_PWM) && !defined(NONE_MODEM_ALERTER)
#include "dcl_pwm.h"
#endif
#ifndef NONE_MODEM_KBDH
#include "DclH_kbd.h"
#endif
#ifndef NONE_MODEM_KBD
#include "DclS_kbd.h"
#endif
#ifndef NONE_MODEM_STS
#include "dcl_sts.h"
#endif
#ifndef NONE_MODEM_MSDC
#include "dcl_msdc.h"
#endif
#ifndef NONE_MODEM_USB
#include "dcl_usb_drv.h"
#endif
#ifndef NONE_MODEM_USBD
#include "dcl_usb_hcd.h"
#endif
#ifndef NONE_MODEM_OTG
#include "dcl_otg_drv.h"
#endif
#ifndef NONE_MODEM_IRDA
#include "dcl_irda.h"
#endif
#ifndef NONE_MODEM_SIM
#include "dcl_sim.h"
#endif
#ifndef NONE_MODEM_PMU
#include "dcl_pmu.h"
#endif
#ifndef NONE_MODEM_PW
#include "dcl_pw.h"
#endif
#ifndef NONE_MODEM_CHR_USB_DET
#include "dcl_chr_det.h"
#endif
#ifndef NONE_MODEM_PXS
#include "dcl_pxs.h"
#endif
#ifndef NONE_MODEM_SIM_GPIO
#include "dcl_sim_gpio.h"
#endif
#ifndef NONE_MODEM_F32K_CLK
#include "dcl_f32k_clk.h"	
#endif   
#ifndef NONE_MODEM_IDC
#include "dcl_idc.h"
#endif
#undef DCL_DEFINITION_PROTOTYPE


#endif  /* __DCL_H__ */
