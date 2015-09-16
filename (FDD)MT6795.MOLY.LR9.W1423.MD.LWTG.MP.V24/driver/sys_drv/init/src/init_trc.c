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
 *   init_trc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines bootup trace functions.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include <string.h>
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_trace.h"
#include "ccci_if.h"
#include "ex_mem_manager_public.h"

/*******************************************************************************
 * Define global data
 *******************************************************************************/
#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
  kal_bool is_init_log_enable; // setup in INT_setInitLogFlag
  kal_bool is_init_stage;
#else /* __USB_BOOTUP_TRACE__ || __KEYPAD_DEBUG_TRACE__ */
  const kal_bool is_init_log_enable = KAL_FALSE;
  kal_bool is_init_stage = KAL_TRUE;
#endif  /* __USB_BOOTUP_TRACE__ || __KEYPAD_DEBUG_TRACE__ */

#if defined(__SP_BOOTTRC_ENABLE__)
  #define BOOT_TRACE_LOG_SIZE    1024
  kal_uint32 boot_trace_log[BOOT_TRACE_LOG_SIZE/4];   // ccci reserves 1k currently
  kal_uint32 *boot_trace_log_ptr = boot_trace_log;
#endif




/*******************************************************************************
 * Declare import data
 *******************************************************************************/
extern boot_mode_type system_boot_mode;


/*******************************************************************************
 * Declare function prototype 

 *******************************************************************************/

/*******************************************************************************
 * Declare import function prototype 
 *******************************************************************************/
#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
#if defined(__USB_BOOTUP_TRACE__)
extern void USB_Boot_Trace_Init(void);
extern kal_int32 custom_usb_comport_setup_delay(void);
#else /* __USB_BOOTUP_TRACE__ */
extern void UART_Bootup_Init(void);
extern void Seriport_Driver_Boot_Trace_Init(void);//want bootup trace,but VFIFO maybe not ready,so close vfifo and init uart1 driver
#endif /* __USB_BOOTUP_TRACE__ */
#endif /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */


#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
/*************************************************************************
* FUNCTION
*  INT_setInitLogFlag
*
* DESCRIPTION
*  This function is used to set init flag for tst, which will use the flag to determine whether
*  the system is at init. stage or not.
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
void INT_setInitLogFlag(void)
{
    is_init_stage = KAL_TRUE;
#if defined(__KAL_RECORD_BOOTUP_LOG__)
    is_init_log_enable = KAL_TRUE;
#else
       
    custom_InitKeypadGPIO();
    
    if(custom_IsBootupTraceKeyPressed())
    {
        is_init_log_enable = KAL_TRUE;
    }
    else
    {
        is_init_log_enable = KAL_FALSE;
    }
#endif    
}

/*************************************************************************
* FUNCTION
*  INT_InitBootupTrace
*
* DESCRIPTION
*  This function is used to init bootup trace driver.
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
void INT_InitBootupTrace(void)
{
#if defined(__USB_BOOTUP_TRACE__)
    INT_setInitLogFlag();
    if (is_init_log_enable == KAL_TRUE)
    {
        USB_Boot_Trace_Init();
        custom_usb_comport_setup_delay();
    }
#else /* __USB_BOOTUP_TRACE__ */
    /* init uart baudrate (HW related) */
    UART_Bootup_Init();
    INT_setInitLogFlag();
#endif /* __USB_BOOTUP_TRACE__ */
}

/*************************************************************************
* FUNCTION
*  INT_printBootMode
*
* DESCRIPTION
*  This function is used to print out current boot-up mode.
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
void INT_printBootMode(void)
{
    kal_char buff[40];

#if defined(__FACTORY_BIN__)
    sprintf(buff, "Supported Boot mode: META only");
#else

#if defined(__SPLIT_BINARY__)
    sprintf(buff, "Supported Boot mode: MAUI only");
#else
    sprintf(buff, "Supported Boot mode: ALL");
#endif /* __SPLIT_BINARY__ */
    
#endif /* __FACTORY_BIN__ */

    kal_bootup_print(buff); 

    memset(buff, 0x0, sizeof(buff));
    sprintf(buff, "Boot mode: ");
    switch(system_boot_mode) {
        case FACTORY_BOOT:
	     strcat(buff, "FACTORY");
	 break;
	   
        case NORMAL_BOOT:
	     strcat(buff, "NORMAL");		  	
	 break;
	   
	 case USBMS_BOOT:
	     strcat(buff, "USB");	
	 break;
	   
	 case FUE_BOOT:
	     strcat(buff, "FUE");
	 break;
	   
	 default:
	     strcat(buff, "UNKNOWN");	 	
        break;
    }
    kal_bootup_print(buff);
}
#endif /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */

#if 0
/* under construction !*/
/* under construction !*/
#if defined(__SP_BOOTTRC_ENABLE__) && defined(__X_BOOTING__)    
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif

void INT_backupBootLogs(void)
{
#if defined(__SP_BOOTTRC_ENABLE__) && !defined(__X_BOOTING__)
    //for external smart phone, there is no share memory for back up
    kal_uint32 log_addr;
    kal_uint32 log_size;
    EMM_GetBufInfo(&log_addr, &log_size, EMM_DBG_INFO);
    memcpy(&boot_trace_log, (void*)log_addr, log_size);
    EMM_ClearDbgInfo();
#endif
}
