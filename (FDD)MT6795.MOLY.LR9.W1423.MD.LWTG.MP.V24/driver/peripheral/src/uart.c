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
*    uart.c      
*
* Project:
* --------
*   Maui_Software
*
* Description:
* ------------
*   This Module defines the uart1 driver and the adaption layer
*   between driver and maui protocol.
*
* Author:
* -------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#include    "drv_features.h"
#include "sync_data.h"
//#include    "kal_release.h"
#include "kal_public_defs.h" //MSBB change #include    "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include    "stack_msgs.h"
//#include "stack_ltlcom.h" //MSBB change #include    "app_ltlcom.h"       /* Task message communiction */
//#include    "stack_buff_pool.h"
//#include    "app_buff_alloc.h"
#include    "drv_comm.h"
#include    "reg_base.h"
#include    "uart_hw.h"
#include    "bmd.h"
#include    "intrCtrl.h"
#include    "drvpdn.h"
//#include    "stack_ltlcom.h"       /*msg_send_ext_queue.....definitions*/
#include "kal_public_defs.h" //MSBB change #include    "stack_config.h"        /*MOD_UART1_HISR,MOD_UART2_HISR*/
#include    "uart_sw.h"
#include "uart_internal.h"
#include "drv_msgid.h"

#include    "dma_hw.h"
#include    "dma_sw.h"
#include    "gpt_sw.h"
//#include    "init.h"
#include    "drv_trc.h"
#include    "drv_hisr.h"
#ifdef __ROMSA_SUPPORT__
#ifndef __ROMSA_EXPORT_UART_H__
#include "romsa_export_uart.h"
#endif
#include    "gpt_hw.h"
#endif
#ifdef __USB_COM_PORT_ENABLE__
#include    "usb_comm.h"
#endif   /*__USB_COM_PORT_ENABLE__*/


// MT6238/MT6235 D-cache plan phase #1 begin
#include "cache_sw.h"
//#include "init.h"
// MT6238/MT6235 D-cache plan phase #1 end
   // #include "kal_non_specific_general_types.h"
    #include "l1_interface.h"
    #include "us_timer.h"
        #include "kal_general_types.h"
    #include "kal_public_api.h"
    #include "hisr_config.h"
    #include "dcl.h"
    #include "kal_public_defs.h"
    
extern kal_uint8 INT_Exception_Enter;

// For TK6516, the UART driver is is at uart_tk6516.c
#if !defined(TK6516)

#if !defined(DRV_UART_OFF)
#ifdef VFIFO_DBG
#include "string.h"
static kal_uint32 gUART_TrxHandler_VFIFO;
static kal_uint32 gUART_RecHandler_VFIFO;
static kal_uint32 gUART_RecTimeOutHandler;
#endif

 
#if defined(DRV_UART_CLOCK_52M)	 //phase out MT6255 option!!!   use driver feature option 
#define UART_CLOCK 52000000
#define   UART_DCM_CLOCK  13000000

#elif defined(DRV_UART_CLOCK_6144M)	
#define UART_CLOCK 61440000
#define   UART_DCM_CLOCK  15360000

#else


#ifdef MCU_13M
#define   UART_CLOCK   13000000    /* 13M */
#endif   /*MCU_13M*/

#ifdef MCU_26M
#define   UART_CLOCK   26000000    /* 26M */
#endif   /*MCU_26M*/

#ifdef MCU_39M
#define   UART_CLOCK   39000000    /* 39M */
#endif   /*MCU_39M*/

#ifdef MCU_52M
#define   UART_CLOCK   52000000    /* 52M */
#endif   /*MCU_52M*/

#if defined(MCU_104M)||defined(MCU_78M)
#if defined(MT6251)
#define   UART_CLOCK   78000000    /* 78M */
#else
#define   UART_CLOCK  52000000    /* 104M */
#endif 	//defined(MT6251)
#endif   /*MCU_104M*/

#ifdef MCU_122_88M
#ifdef DRV_UART_FPGA_CLOCK
#define   UART_CLOCK  30720000    /* 30.72M*/
#else
#define   UART_CLOCK  61440000    /* 61.44M*/
#endif
#endif   /*MCU_104M*/

#if defined(MCU_208M)
#define   UART_CLOCK  52000000    /* 104M */
#endif   /*MCU_104M*/

#ifdef MCU_312M
#define   UART_CLOCK  52000000    /* 312M */
#endif   /*MCU_312M*/

#ifdef MCU_512M
#define UART_CLOCK 52000000
#endif 

#if defined(MCU_650M) || defined(MCU_611M)||defined(MCU_416M)
#if defined(MT6276_S01) || defined(MT6276)
#define UART_CLOCK 52000000
#else
#define UART_CLOCK 61440000
#endif 
#endif 

#ifdef MCU_520M
#if defined(MT6575)||defined(MT6256)
	#define UART_CLOCK 52000000
#else
#define UART_CLOCK 61440000
#endif
#endif 


#if defined(MCU_245_76M) || defined(MCU_368_64M)
#ifdef DRV_UART_FPGA_CLOCK
#define   UART_CLOCK  30720000    /* 30.72M*/
#else
#define   UART_CLOCK  61440000    /* 61.44M*/
#endif
#endif   /*MCU_104M*/

#if defined(MCU_122_88M) || defined(MCU_245_76M) || defined(MCU_650M) || defined(MCU_520M) || defined(MCU_611M) || defined(MCU_520M) || defined(MCU_416M)
#if defined(MT6276_S01) || defined(MT6575) || defined(MT6276)||defined(MT6256)
#define   UART_DCM_CLOCK  13000000
#else
#define   UART_DCM_CLOCK  15360000
#endif
#else
#define   UART_DCM_CLOCK  13000000
#endif


#endif//#if defined(DRV_UART_CLOCK_52M)	



kal_uint8 UART_handle;
#ifdef __MTK_INTERNAL__
/*lint -e552*/
kal_uint8 uart_lcr_save[MAX_UART_PORT_NUM];
/*lint +e552*/
#endif   

#if defined(DRV_UART1_NORMAL_DMA)
kal_uint8                      uart1_dmaport;
static DMA_INPUT               uart1_input;
static DMA_HWRINGBUFF_MENU     uart1_txmenu;
static UART_RingBuffer_SaveIndex       uart1_index_save;
static kal_bool   UART1_Intr_is_Running;
static kal_bool   UART1_race_check;
#endif   /*DRV_UART1_NORMAL_DMA*/

#if defined(DRV_UART2_NORMAL_DMA)
kal_uint8                      uart2_dmaport;
static DMA_INPUT               uart2_input;
static DMA_HWRINGBUFF_MENU     uart2_txmenu;
static UART_RingBuffer_SaveIndex       uart2_index_save;
#endif   /*DRV_UART2_NORMAL_DMA*/

#ifdef __UART3_SUPPORT__
#if defined(DRV_UART3_NORMAL_DMA)
kal_uint8                      uart3_dmaport;
static DMA_INPUT               uart3_input;
static DMA_HWRINGBUFF_MENU     uart3_txmenu;
static UART_RingBuffer_SaveIndex       uart3_index_save;
static kal_bool   UART3_Intr_is_Running;
static kal_bool   UART3_race_check;
#endif   /*DRV_UART3_NORMAL_DMA*/
#endif

UARTStruct UARTPort[MAX_UART_PORT_NUM];
#if !defined(DRV_UART2_NO_DMA)
static kal_bool   UART2_Intr_is_Running;
static kal_bool   UART2_race_check;
#endif

//static UART_flowCtrlMode  old_uart_portswitch_fctrl = fc_hw;//for build warning

#ifdef DRV_DEBUG
kal_uint8 uart_initialize[MAX_UART_PORT_NUM];
#endif /*DRV_DEBUG*/

#if defined(DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS)

/*
meaning of DRV_UART2_USE_UART4
smart phone modem side only can use uart1 , 
hardware uart2 & uart3 does not layout pin to output .
this patch map modem side uart2 data structure to hardware uart4.
MT6516 uart4 does not support VFIFO on modem side.
smart phone AP side will handle clock gating , so modem side does not care about clock.
the feature is for smart phone only
*/
#ifdef DRV_UART2_USE_UART4
kal_uint8 UartPortOwnedByMD[3]={1, 1, 0};
#elif defined( DRV_MD_2_UART)
kal_uint8 UartPortOwnedByMD[3]={1, 1, 0};
#elif defined( DRV_MD_1_UART)
    kal_uint8 UartPortOwnedByMD[3]={1, 0, 0};
#elif defined(DRV_MD_UART2_USE_AP_UART1) //for MT6280 MD uart2(use AP uart1)
    kal_uint8 UartPortOwnedByMD[3]={1, 1, 0};
	#else
kal_uint8 UartPortOwnedByMD[3]={1, 0, 0};
#endif //#ifdef DRV_UART2_USE_UART4
#endif // #if defined(DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS)

/*************************************************************************
 * BOOT UP  TRACE declaration  Start
 *************************************************************************/
#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
    #if defined(__USB_BOOTUP_TRACE__)
       const UART_PORT debug_port = uart_port_usb;
    #else /* __USB_BOOTUP_TRACE__ */
          #if defined(DEBUG_PORT)
            const UART_PORT debug_port = DEBUG_PORT;
         #else  /* DEBUG_PORT */
            const UART_PORT debug_port = uart_port1;
         #endif  /* DEBUG_PORT */
    #endif /* __USB_BOOTUP_TRACE__ */

   #if defined(DEBUG_BAUDRATE)
  const UART_baudrate debug_baudrate = DEBUG_BAUDRATE;
  #else  /* DEBUG_BAUDRATE */
  const UART_baudrate debug_baudrate = 921600;
  #endif  /* DEBUG_BAUDRATE */
#else /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */
  const UART_PORT debug_port = uart_port1;
    const UART_baudrate debug_baudrate = 921600;  /*set BR 921600 in all time memory dump or boot-up trace enable*/
#endif  /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */

/*************************************************************************
 * BOOT UP  TRACE   declaration  End
 *************************************************************************/

kal_int32 init_log_fail_count=0;
//MCU booting speed 26M/baudrate(bits/second) = 260M/baudrate(bytes/second) = MCU tick/bytes
#define MCU_BOOT_SPEED 260000000 //Currently all chips use 26M, 260M because of count [MCU ticks/byte]

kal_bool send_Txilm[MAX_UART_PORT_NUM] = {// change from kal_uint8 to kal_bool, avoid Warning 641: Converting enum 'kal_bool' to int"
   KAL_FALSE,
 #if !defined(DRV_MD_1_UART)
      KAL_FALSE,
#endif
#ifdef __UART3_SUPPORT__
      KAL_FALSE
#endif   /*__UART3_SUPPORT__*/
};

kal_bool send_Rxilm[MAX_UART_PORT_NUM] = {// change from kal_uint8 to kal_bool, avoid Warning 641: Converting enum 'kal_bool' to int"
   KAL_TRUE,
 #if !defined(DRV_MD_1_UART)
      KAL_TRUE,
 #endif
#ifdef __UART3_SUPPORT__
      KAL_TRUE
#endif   /*__UART3_SUPPORT__*/
      
};

const VOID_FUNC UART_HISR[MAX_UART_PORT_NUM] =
{
   UART1_HISR,
 #if !defined(DRV_MD_1_UART)
      UART2_HISR,
#endif
#ifdef __UART3_SUPPORT__
      UART3_HISR
#endif   /*__UART3_SUPPORT__*/
};



#if defined(DRV_UART2_USE_UART4)
#define DRV_UART_PORT2_IRQ_CODE IRQ_UART4_CODE
#define DRV_UART_PORT2_BASE  UART4_base
#elif defined(DRV_MD_UART2_USE_AP_UART1) //for MT6280 MD uart2(use AP uart1)
#define DRV_UART_PORT2_IRQ_CODE IRQ_AP_UART1_CODE
#define DRV_UART_PORT2_BASE  AP_UART1_SD_base
#else
#define DRV_UART_PORT2_IRQ_CODE IRQ_UART2_CODE
#define DRV_UART_PORT2_BASE  UART2_base
#endif

#ifdef DRV_UART_FPGA_VFIFO
kal_uint32 UART_BaseAddr[MAX_UART_PORT_NUM] =
#else // #ifdef DRV_UART_FPGA_VFIFO
const kal_uint32 UART_BaseAddr[MAX_UART_PORT_NUM] =
#endif // #ifdef DRV_UART_FPGA_VFIFO
{
   UART1_base,
   	#if !defined(DRV_MD_1_UART)// for MD only have one uart port,like MT6280
      DRV_UART_PORT2_BASE,
      #endif   
#ifdef __UART3_SUPPORT__
      UART3_base
#endif   /*__UART3_SUPPORT__*/
};
#ifdef __DMA_UART_VIRTUAL_FIFO__
#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
kal_bool UART_SINGLE_VFIFO_support[MAX_UART_TUNNEL_NUM] = //toy add for single tunnel vfifo
{
   KAL_TRUE, 
      KAL_TRUE, 
      KAL_TRUE, 
      KAL_TRUE,
#ifdef __UART3_SUPPORT__
      KAL_TRUE,
      KAL_TRUE,
#endif   /*__UART3_SUPPORT__*/
};
#elif !defined(__MEUT__) && !defined(__MEIT__)  //#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
kal_bool UART_VFIFO_support[MAX_UART_PORT_NUM] =
{ 
   KAL_TRUE, 
 #if !defined(DRV_MD_1_UART) 
      KAL_FALSE,
 #endif
#ifdef __UART3_SUPPORT__
      KAL_FALSE,
#endif   /*__UART3_SUPPORT__*/
};
#else
kal_bool UART_VFIFO_support[MAX_UART_PORT_NUM] =
{
   KAL_FALSE,
 #if !defined(DRV_MD_1_UART)
      KAL_FALSE,
 #endif
#ifdef __UART3_SUPPORT__
      KAL_FALSE
#endif   /*__UART3_SUPPORT__*/
};
#endif  //#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)

#else
#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
kal_bool UART_SINGLE_VFIFO_support[MAX_UART_TUNNEL_NUM] =  //toy add for single tunnel vfifo
{
   KAL_FALSE, 
      KAL_FALSE, 
      KAL_FALSE, 
      KAL_FALSE,
#ifdef __UART3_SUPPORT__
      KAL_FALSE,
      KAL_FALSE,
#endif   /*__UART3_SUPPORT__*/
};
#else  //#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
kal_bool UART_VFIFO_support[MAX_UART_PORT_NUM] =
{
   KAL_FALSE,
      KAL_FALSE,
#ifdef __UART3_SUPPORT__
      KAL_FALSE
#endif   /*__UART3_SUPPORT__*/
};
#endif  //#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
#endif/*__DMA_UART_VIRTUAL_FIFO__*/

//Bei add for new internal func
void UART2_TrxHandler(void);
kal_uint8 UART_GetIRQCode(UART_PORT port);

kal_uint8 uart_escape_state=0;
/*DCM setting*/
#ifdef DCM_ENABLE
extern kal_uint8 DCM_GetHandle(void);
extern void DCM_Disable(kal_uint8 handle);	
extern void DCM_Enable(kal_uint8 handle);
#if defined(__BT_USE_UART2__) || defined(__GPS_USE_UART2__)
#define __USE_UART2_921600__
/*
#if !defined(DRV_UART_SPEED_SAMPLE_COUNT)
#define __USE_921600_WITHOUT_SAMPLE_COUNT__
#endif //#if !defined(DRV_UART_SPEED_SAMPLE_COUNT)
*/
#endif
#endif


extern UartDriver_strcut* pUart_CMD_FUNC[];

#ifdef __MTK_TARGET__
extern int INT_QueryExceptionStatus(void);
#endif
#ifdef DRV_UART_FPGA_VFIFO
//extern kal_int32 detect_fpga(void);
kal_bool uart_for_fpga = KAL_TRUE;
#endif  // #ifdef DRV_UART_FPGA_VFIFO

void UART_Calback(void *parameter);
void U_ConfigEscape (UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid);
void UART_FCR_Setting(  kal_uint32 UART_BASE,kal_uint32 u4UART_FCR);

/*UART Customization */
extern const UART_customize_function_struct *UART_GetFunc(void);
const UART_customize_function_struct *UartCustomFunc;
const UART_rings_struct *UART_rings;
kal_bool WaitForUARTTx[MAX_UART_PORT_NUM] = {KAL_FALSE};

#define ASSERT_WAIT_LOOP 0xffffffff
#define VFIFO_SWITCH_WAIT_LOOP 100000
kal_uint16 DELAY_FOR_PUTBYTE = 300;

//for 6575 bringup uart HW delay
#if defined(DRV_UART_PUTBYTE_DELAY)
kal_uint16 uart_LSR;
#endif
//end for 6575 bringup uart HW delay

//liming add for early response
void UART_Delay_For_Bus_Early_Response()
{
	#if defined(DRV_UART_BUS_EARLY_RESPONSE)
	volatile kal_uint16 uart_MSR;
	uart_MSR |=0x0;   //fix build  warning , uart_MSR set but not used 
	 uart_MSR = DRV_UART_Reg(UART_MSR(UART_BaseAddr[uart_port1]));
#endif
}

void UART1_PDN_ENABLE(void)
{
#if 0       //mark for k2 md2 6589, sync to newer uart driver
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
#elif defined(__APPLICATION_PROCESSOR__)
/* under construction !*/
#elif (defined(__CLKG_DEFINE__) && !defined(DRV_MISC_TDMA_PDN0)) // For MT6516 MD side do not have pdn
/* under construction !*/
#endif
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
#endif
}

void UART1_PDN_DISABLE(void)
{
#if 0       //mark for k2 md2 6589, sync to newer uart driver
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
#elif defined(__APPLICATION_PROCESSOR__)
/* under construction !*/
#elif (defined(__CLKG_DEFINE__) && !defined(DRV_MISC_TDMA_PDN0)) // For MT6516 MD side do not have pdn
/* under construction !*/
#endif
#else //#if defined(__OLD_PDN_ARCH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if defined(__OLD_PDN_ARCH__)
#endif
}

void UART2_PDN_ENABLE(void)
{
#if !defined(DRV_MD_1_UART)// for MD only have one uart port,like MT6280
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
   DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
#elif defined(__APPLICATION_PROCESSOR__)
   DRVPDN_Enable(CG_CON0, CG_CON0_UART2, PDN_UART2);
#elif (defined(__CLKG_DEFINE__) && !defined(DRV_MISC_TDMA_PDN0)) // For MT6516 MD side do not have pdn
   DRVPDN_Enable(CG_CON1, CG_CON1_UART2, PDN_UART2);
#endif
#else //#if defined(__OLD_PDN_ARCH__)
   DRVPDN_Enable(PDN_UART2);
#endif //#if defined(__OLD_PDN_ARCH__)
#endif
}

void UART2_PDN_DISABLE(void)
{
#if !defined(DRV_MD_1_UART)// for MD only have one uart port,like MT6280
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
   DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART2,PDN_UART2);
#elif defined(__APPLICATION_PROCESSOR__)
   DRVPDN_Disable(CG_CON0, CG_CON0_UART2, PDN_UART2);
#elif (defined(__CLKG_DEFINE__) && !defined(DRV_MISC_TDMA_PDN0)) // For MT6516 MD side do not have pdn
   DRVPDN_Disable(CG_CON1, CG_CON1_UART2, PDN_UART2);
#endif
#else //#if defined(__OLD_PDN_ARCH__)
   DRVPDN_Disable(PDN_UART2);
#endif //#if defined(__OLD_PDN_ARCH__)
#endif
}

#ifdef __UART3_SUPPORT__
void UART3_PDN_ENABLE(void)
{
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
   DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);
#elif defined(__APPLICATION_PROCESSOR__)
   DRVPDN_Enable(CG_CON0, CG_CON0_UART3, PDN_UART3);
#elif (defined(__CLKG_DEFINE__) && !defined(DRV_MISC_TDMA_PDN0)) // For MT6516 MD side do not have pdn
   DRVPDN_Enable(CG_CON1, CG_CON1_UART3, PDN_UART3);
#endif
#else //#if defined(__OLD_PDN_ARCH__)
   DRVPDN_Enable(PDN_UART3);
#endif //#if defined(__OLD_PDN_ARCH__)
}

void UART3_PDN_DISABLE(void)
{
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
   DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_UART3,PDN_UART3);
#elif defined(__APPLICATION_PROCESSOR__)
   DRVPDN_Disable(CG_CON0, CG_CON0_UART3, PDN_UART3);
#elif (defined(__CLKG_DEFINE__) && !defined(DRV_MISC_TDMA_PDN0)) // For MT6516 MD side do not have pdn
   DRVPDN_Disable(CG_CON1, CG_CON1_UART3, PDN_UART3);
#endif
#else //#if defined(__OLD_PDN_ARCH__)
   DRVPDN_Disable(PDN_UART3);
#endif //#if defined(__OLD_PDN_ARCH__)
}
#endif //#ifdef __UART3_SUPPORT__

#if defined(DRV_UART_MEMORY_TRACE)
UART_DRV_DBG_STRUCT UART_DRV_DBG_INFO_DATA;
/*uart_drv_dbg_trace(NAND_READ_START,drv_get_current_time(),0,0);*/
void uart_drv_dbg_trace(kal_uint16 index, kal_uint32 time, kal_uint32 data1, kal_uint32 data2)
{
   kal_uint32        savedMask;
   savedMask = SaveAndSetIRQMask();
   {
      UART_DRV_DBG_INFO_DATA.dbg_data[UART_DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_UART_DRV_DBG_INFO_SIZE-1)].tag = index;
      UART_DRV_DBG_INFO_DATA.dbg_data[UART_DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_UART_DRV_DBG_INFO_SIZE-1)].time = time;
      UART_DRV_DBG_INFO_DATA.dbg_data[UART_DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_UART_DRV_DBG_INFO_SIZE-1)].data1 = data1;
      UART_DRV_DBG_INFO_DATA.dbg_data[UART_DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_UART_DRV_DBG_INFO_SIZE-1)].data2 = data2;
      UART_DRV_DBG_INFO_DATA.dbg_data_idx++;
   }
   RestoreIRQMask(savedMask);
}
#endif //#if defined(DRV_UART_MEMORY_TRACE)

//add for refactoring(bei)
void UART_PDN_Disable(UART_PORT port)
{
	switch(port)
    {
    	case uart_port1:
			UART1_PDN_DISABLE();
            break;
        case uart_port2:
            UART2_PDN_DISABLE();
            break;
#ifdef __UART3_SUPPORT__
         case uart_port3:               
            UART3_PDN_DISABLE();
            break;
#endif   /*__UART3_SUPPORT__*/
         default:
            ASSERT(0);
            break;
     }
}

void UART_PDN_Enable(UART_PORT port)
{
	switch(port)
    {
    	case uart_port1:
            UART1_PDN_ENABLE();
            break;
        case uart_port2:
            UART2_PDN_ENABLE();
            break;
#ifdef __UART3_SUPPORT__
        case uart_port3:               
            UART3_PDN_ENABLE();
            break;
#endif   /*__UART3_SUPPORT__*/
        default:
            ASSERT(0);
            break;
     }
}

// bei add for get irqcode
kal_uint8 UART_GetIRQCode(UART_PORT port)
{
	kal_uint8 IRQ_code_ = 0;
	switch(port)
	{
		case uart_port1:
			#ifdef DRV_UART_FPGA_VFIFO
				if (KAL_TRUE==uart_for_fpga)
					IRQ_code_ = IRQ_FPGA_UART1_CODE;
				else
					IRQ_code_ = IRQ_UART1_CODE;
		   	#else 
    			IRQ_code_ = IRQ_UART1_CODE;
		   	#endif 
		break;
	    #if !defined(DRV_MD_1_UART)// for MD only have one uart port,like MT6280	
		case uart_port2:
			#ifdef DRV_UART_FPGA_VFIFO
				if (KAL_TRUE==uart_for_fpga)
					IRQ_code_ = IRQ_FPGA_UART2_CODE;
				else
					IRQ_code_ = DRV_UART_PORT2_IRQ_CODE;
		   	#else 
    			IRQ_code_ = DRV_UART_PORT2_IRQ_CODE;
		   	#endif 
		break;
		#endif
		#ifdef __UART3_SUPPORT__
		case uart_port3:
			IRQ_code_ = IRQ_UART3_CODE;
		break;
		#endif //__UART3_SUPPORT__
		default:
		break;
	}
	return IRQ_code_;
}
void uart_customize_init(void)
{
#ifdef DRV_UART_FPGA_VFIFO
   //uart_for_fpga = (detect_fpga() == 1)? KAL_TRUE: KAL_FALSE;
   if (KAL_TRUE==uart_for_fpga)
   {
      UART_BaseAddr[uart_port1] = FPGA_UART1_base;
      UART_BaseAddr[uart_port2] = FPGA_UART2_base;
   }
#endif  // #ifdef DRV_UART_FPGA_VFIFO
   /* retreive the function table */
   UartCustomFunc=UART_GetFunc();
   /* use the entry in function table to retreive desired information */
   UART_rings = UartCustomFunc->UART_Get_Data();
#ifdef __DMA_UART_VIRTUAL_FIFO__   
#if !defined(__MEUT__) && !defined(__MEIT__)
   U_configure_DMA_VFIFO();
#endif
#endif
   
}  

kal_bool UART_IsVfifoSetting(UART_PORT port, UART_TxRx_VFIFO_support vs)
{
#ifdef __DMA_UART_VIRTUAL_FIFO__
   if(port >= MAX_UART_PORT_NUM)
      return KAL_FALSE;
#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
   if(vs == TXRX_VFIFO)
      return ( UART_SINGLE_VFIFO_support[port*2] && UART_SINGLE_VFIFO_support[port*2 + 1] );
   else if(vs == RX_VFIFO)
      return UART_SINGLE_VFIFO_support[port*2];
   else if(vs == TX_VFIFO)
      return UART_SINGLE_VFIFO_support[port*2 + 1];
   else //NONE_VFIFO
      return ( !UART_SINGLE_VFIFO_support[port*2] && !UART_SINGLE_VFIFO_support[port*2 + 1] );
#else  //#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
   if(vs != NONE_VFIFO)
      return UART_VFIFO_support[port];
   else //NONE_VFIFO
      return (kal_bool)!UART_VFIFO_support[port];
#endif  //#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
#else
   if(vs == NONE_VFIFO)
      return KAL_TRUE;
   else //NONE_VFIFO
      return KAL_FALSE;   
#endif      
}

/*check if chip can support auto escape*/
kal_bool uart_support_autoescape(void)
{      
#if defined(FPGA)
   return KAL_FALSE;	
#else  /*not support auto escape*/	
   return KAL_TRUE;	
#endif
}

#if defined(DRV_UART1_NORMAL_DMA)
kal_uint8 uart1_update_race_check;
void UART1_update_index_save(kal_uint32 type, kal_uint32 index)
{
   ASSERT(uart1_update_race_check == 0);
   uart1_update_race_check = 1;
   uart1_index_save.type = (UART_RingBuffer_Type)type;//toy avoid lint Error 64: Type mismatch (assignment) (int/enum)"
   uart1_index_save.index = index;
   uart1_update_race_check = 0;
}
#endif /* defined(DRV_UART1_NORMAL_DMA) */

#if defined(DRV_UART2_NORMAL_DMA)
kal_uint8 uart_update_race_check;
void UART2_update_index_save(kal_uint32 type, kal_uint32 index)
{
   ASSERT(uart_update_race_check == 0);
   uart_update_race_check = 1;
   uart2_index_save.type = (UART_RingBuffer_Type)type;//toy avoid lint Error 64: Type mismatch (assignment) (int/enum)"
   uart2_index_save.index = index;
   uart_update_race_check = 0;
}
#endif

#ifdef __UART3_SUPPORT__
#if defined(DRV_UART3_NORMAL_DMA)
kal_uint8 uart3_update_race_check;
void UART3_update_index_save(kal_uint32 type, kal_uint32 index)
{
   ASSERT(uart3_update_race_check == 0);
   uart3_update_race_check = 1;
   uart3_index_save.type = (UART_RingBuffer_Type)type;//toy avoid lint Error 64: Type mismatch (assignment) (int/enum)"
   uart3_index_save.index = index;
   uart3_update_race_check = 0;
}
#endif /* defined(DRV_UART3_NORMAL_DMA) */
#endif

void UART_sendilm(UART_PORT port, msg_type msgid)
{
  
  ilm_struct PrintMsg_ILM_local;
   ilm_struct *UART_ilm=&PrintMsg_ILM_local;
   void *port_ptr=0;      
   //kal_bool msg_b; //for avoid Lint Warning 534: Ignoring return value of function 'msg_send_ext_queue"

   if(port >= MAX_UART_PORT_NUM)
      return;
   
                   /*TY adds the following decription 20041013
   The first if check is to avoid the case that owenr is UARTX_HISR*/   
   
   if (UARTPort[port].ownerid != UARTPort[port].UART_id)
   {
      switch(msgid)
      {
      case MSG_ID_UART_READY_TO_READ_IND:
         {	   		 	
            uart_ready_to_read_ind_struct *tmp;      
            tmp = (uart_ready_to_read_ind_struct *) 
               construct_local_para(sizeof(uart_ready_to_read_ind_struct),TD_UL);
            tmp->port = port;   		
            port_ptr = tmp;   	
         }	
         break;	
      case MSG_ID_UART_READY_TO_WRITE_IND:      		
         {
            uart_ready_to_write_ind_struct *tmp;      
            tmp = (uart_ready_to_write_ind_struct *) 
               construct_local_para(sizeof(uart_ready_to_write_ind_struct),TD_UL);
            tmp->port = port;   		
            port_ptr = tmp;
         }	   	
         break;
      case MSG_ID_UART_DSR_CHANGE_IND:   	   		
         {
            uart_dsr_change_ind_struct *tmp;      
            tmp = (uart_dsr_change_ind_struct *) 
               construct_local_para(sizeof(uart_dsr_change_ind_struct),TD_UL);
            tmp->port = port;   		
            port_ptr = tmp;   		
         }	
         break;
      case MSG_ID_UART_ESCAPE_DETECTED_IND:   	
         {
            uart_escape_detected_ind_struct *tmp;      
            tmp = (uart_escape_detected_ind_struct *) 
               construct_local_para(sizeof(uart_escape_detected_ind_struct),TD_UL);
            tmp->port = port;   		
            port_ptr = tmp;   		
         }	
         break;
      default:
         break;   	
      }         
      DRV_BuildPrimitive(UART_ilm,
         MOD_DRV_HISR,//UARTPort[port].UART_id,
         UARTPort[port].ownerid,
         msgid,
         port_ptr);
      
      /*lint -e(534)*/msg_send(UART_ilm);
   }
}

//Bei add for U_ClrRxBuffer and U_ClrTxBuffer, reduce code size
void UART_Set_NormalFlowControl(UART_PORT port) 
{
	if (UARTPort[port].DCB.flowControl == fc_none)
		  DRV_UART_WriteReg(UART_IER(UART_BaseAddr[port]),IER_HW_NORMALINTS);
	else
	   {
		  if (UARTPort[port].DCB.flowControl == fc_hw)
			 DRV_UART_WriteReg(UART_IER(UART_BaseAddr[port]),IER_HW_NORMALINTS);
		  else
		  {
			 if (UARTPort[port].DCB.flowControl == fc_sw)
				DRV_UART_WriteReg(UART_IER(UART_BaseAddr[port]),IER_SW_NORMALINTS);
		  }
	   }
}


void U_ClrRxBuffer(UART_PORT port, module_type ownerid)  /*clear sw buffer*/
{
   kal_uint32 savedMask;
#ifdef __DMA_UART_VIRTUAL_FIFO__
   kal_uint8 rxBuf[100];
#endif //#ifdef __DMA_UART_VIRTUAL_FIFO__
      
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   savedMask = SaveAndSetIRQMask();
   BWrite_addr(UARTPort[port].Rx_Buffer) = 0;
   BRead_addr(UARTPort[port].Rx_Buffer) = 0;
   
   UART_Set_NormalFlowControl(port);   
   send_Rxilm[port] = KAL_TRUE;
   RestoreIRQMask(savedMask);

#ifdef __DMA_UART_VIRTUAL_FIFO__
/*
	we must clean data in VFIFO too , 
	if we pop data between SaveAndSetIRQMask() and RestoreIRQMask(),it might over 60 qbit ,so we pop data 
	after RestoreIRQMask().
	we use UART_GetBytes() to avoid looping deadlock , and we can assume MCU pop is faster than uart rx.
*/
   if( UART_IsVfifoSetting(port, RX_VFIFO) )
   {
	while (U_GetBytes_VFIFO(port,rxBuf,100,NULL,ownerid)==100);
   }
#endif //#ifdef __DMA_UART_VIRTUAL_FIFO__
   
}

void U_ClrTxBuffer(UART_PORT port, module_type ownerid)  /*clear sw buffer*/
{
   kal_uint32 savedMask;
   
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   savedMask = SaveAndSetIRQMask();
   
   BWrite_addr(UARTPort[port].Tx_Buffer) = 0;
   BRead_addr(UARTPort[port].Tx_Buffer) = 0;  

   UART_Set_NormalFlowControl(port);
   send_Txilm[port] = KAL_TRUE;
   RestoreIRQMask(savedMask);
}
void UART_EnableTX(UART_PORT port, kal_bool enable)
{  
#ifdef __UART3_SUPPORT__
   if (port <= uart_port3)
#else
      if (port <= uart_port2)
#endif
      {
         UARTPort[port].EnableTX= enable;
         if(enable == KAL_TRUE)
            EnableTxIntr(UART_BaseAddr[port]);
      }
}

void UART_SleepOnTx_Enable(UART_PORT port, UART_SLEEP_ON_TX enable_flag)
{
#ifdef __UART3_SUPPORT__
   if (port <= uart_port3)
#else
      if (port <= uart_port2)
#endif
      {
         UARTPort[port].sleep_on_tx = uart_sleep_on_tx_allow;
      }
}

kal_uint16 U_GetBytesAvail(UART_PORT port)
{	
   kal_uint16 real_count;   

   Buf_GetBytesAvail(&(UARTPort[port].Rx_Buffer),real_count);
   return real_count;
}

kal_uint16 U_GetTxRoomLeft(UART_PORT port)
{
   kal_uint16 real_count;   

   Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer),real_count);   
   return real_count;
}

#ifndef __ROMSA_SUPPORT__ /* Note: for ROM code */

kal_uint16 U_GetTxISRRoomLeft(UART_PORT port)
{
   kal_uint16 real_count;
   
   Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer_ISR),real_count);
   
   /*temp solution: to cover L1 trace bug*/
   if(real_count<=16)
      real_count=0;
   else
      real_count-=16;
   
   return real_count;
}
#endif /* Note: for ROM code */

/* Note: for ROM code start */
#ifdef __ROMSA_SUPPORT__
/*for MCUROM*/
kal_uint16 U_ROM_GetTxISRRoomLeft(UART_PORT port)
{
   kal_uint16 real_count;
   
   if( UART_IsVfifoSetting(port, TX_VFIFO) )
      real_count=DMA_GetVFIFO_Roomleft(UARTPort[port].Tx_DMA_Ch);
   else
      Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer_ISR),real_count);
   return real_count;
}
UARTStruct *U_ROM_GetUARTPort(UART_PORT port)
{
   return &UARTPort[port];
}

kal_uint8 *U_ROM_GetUART_TXilm(UART_PORT port)
{
   return &(kal_uint8)send_Txilm[port];
}

void U_ROM_InformUARTOwner(UART_PORT port)
{
   send_Txilm[port] = KAL_TRUE;
   
   if( UART_IsVfifoSetting(port, TX_VFIFO) )
      DMA_EnableINT(UARTPort[port].Tx_DMA_Ch);
}


void U_ROM_PushDataToBuf(UART_PORT port, kal_uint8 *data, kal_uint32 real_count)
{
   kal_uint32  index;
   
   for (index = 0; index < real_count; index++)
   {
      if( UART_IsVfifoSetting(port, TX_VFIFO) )
      {
         DMA_TASK_PUSH(UARTPort[port].Tx_DMA_Ch,*(data+index));
      }	
      else   
      {   
         Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),*(data+index));
      }	
   }
   if( UART_IsVfifoSetting(port, TX_VFIFO) == KAL_FALSE )
      U_ROM_EnableTxIntr(port);
}
void U_ROM_EnableTxIntr(UART_PORT port)
{
   switch(port)
   {
   case uart_port1:
      EnableTxIntr(UART_BaseAddr[port]);
      break;
   case uart_port2:
      if (UART2_Intr_is_Running == KAL_FALSE)
      {
         EnableTxIntr(UART_BaseAddr[port]);
      }
      break;
   case uart_port3:
      EnableTxIntr(UART_BaseAddr[port]);
      break;
   default:
      ASSERT(0);
      break;
   }
}
#endif

/*
* FUNCTION
*  GetUARTByte
*
* DESCRIPTION
*     This function is to read data from UART
*
* CALLS
*  This function is to receive data through UART
*
* PARAMETERS
*  None
*
* RETURNS
*  the data from UART
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint8 U_GetUARTByte(UART_PORT port)
{
   
   kal_uint8 data;
   kal_uint8 U_GetUARTByteWithTimeOut(UART_PORT port, kal_uint8* ch, kal_uint32 timeout_value);//liming add statement
   while(!U_GetUARTByteWithTimeOut(port,&data,0xffffffff));// for descrease code size  (U_GetUARTByte &U_GetUARTByteTimeout)
   return data;
}


/*
* FUNCTION
*  GetUARTByte
*
* DESCRIPTION
*     This function is to read data from UART
*
* CALLS
*  This function is to receive data through UART
*
* PARAMETERS
*  None
*
* RETURNS
*  the data from UART
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint8 U_GetUARTByteWithTimeOut(UART_PORT port, kal_uint8* ch, kal_uint32 timeout_value)
{
   kal_uint8 res_byte = 0;
   kal_uint8 data;
   
   while(timeout_value != 0)
   {
      kal_uint16 LSR;
      LSR = DRV_UART_Reg(UART_LSR(UART_BaseAddr[port]));      
      if (LSR & UART_LSR_DR)
      {
         data = (kal_uint8)DRV_UART_Reg(UART_RBR(UART_BaseAddr[port]));
         res_byte = 1;
         //only META port use old flow control escape character,
         if( (kal_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw && UARTPort[port].ownerid==MOD_DHL_READER)||
            (uart_support_autoescape()==KAL_FALSE&&UARTPort[port].DCB.flowControl==fc_sw))     
         {
            if(uart_escape_state==0)
            {
               if(data==0x77)            
                  uart_escape_state=0x77;
               else
               {
                 *ch = data;
                 break; 
               }            
            }
            else if (uart_escape_state==0x77)
            {
               uart_escape_state=0x0; 
               
               if (data == 0x01)
               {
                 *ch = UARTPort[port].DCB.xonChar;
                 break;
               }
               else if (data == 0x02)
               {
                 *ch = UARTPort[port].DCB.xoffChar;
                 break;
               }
               else if (data == 0x03)
               {
                 *ch = 0x77;
                 break;
               }                                           
            }                           
         }
         else
         {
            *ch = data;
            break;
         }
      }
      
      --timeout_value;
   }
   
   return res_byte;
}
/*
* FUNCTION
*  PutUARTByte
*
* DESCRIPTION
*     This function is to write data to UART
*
* CALLS
*  This function is to transmit data through UART
*
* PARAMETERS
*  None
*
* RETURNS
*  the data from UART
*
* GLOBALS AFFECTED
*   external_global
*/
void PutUARTRingBufferData(UART_PORT port)
{
#ifndef __DMA_UART_VIRTUAL_FIFO__
   
   kal_uint16  index;
   kal_uint16  real_count;
   kal_uint8   TX_DATA;
   kal_uint32 UART_BASE = UART_BaseAddr[port];
   if(port >= MAX_UART_PORT_NUM)
      return;
   
   /*ISR*/
   Buf_GetBytesAvail(&(UARTPort[port].Tx_Buffer_ISR),real_count);
   for (index = 0;index < real_count;index++)
   {
      Buf_Pop(&(UARTPort[port].Tx_Buffer_ISR),TX_DATA);
      DRV_UART_WriteReg(UART_THR(UART_BASE),(kal_uint16)TX_DATA);
   #if defined(DRV_UART_PUTBYTE_DELAY)// this option For 6575 uart putbyte hw delay
        uart_LSR = DRV_UART_Reg(UART_LSR(UART_BASE));
   #endif
   }
   /*Task*/
   Buf_GetBytesAvail(&(UARTPort[port].Tx_Buffer),real_count);
   for (index = 0;index < real_count;index++)
   {
      Buf_Pop(&(UARTPort[port].Tx_Buffer),TX_DATA);
      DRV_UART_WriteReg(UART_THR(UART_BASE),(kal_uint16)TX_DATA);
   #if defined(DRV_UART_PUTBYTE_DELAY)// this option For 6575 uart putbyte hw delay
        uart_LSR = DRV_UART_Reg(UART_LSR(UART_BASE));
   #endif
   }
#endif   
}

void UART_PutUARTByte_limited(UART_PORT port, kal_uint8 data)
{
   volatile kal_uint16 LSR;
   kal_uint32 count = 0;
   
   if(init_log_fail_count > 3)
   {
      DRV_UART_WriteReg(UART_THR(UART_BaseAddr[port]),(kal_uint16)data);
		 UART_Delay_For_Bus_Early_Response();//for MT6255\MT6256 BUS limitation:early respones
      return;
   }
   
   while(1)
   {
      LSR = DRV_UART_Reg(UART_LSR(UART_BaseAddr[port]));
      count++;
      if ( LSR & UART_LSR_THRE )
      {
         DRV_UART_WriteReg(UART_THR(UART_BaseAddr[port]),(kal_uint16)data);
		 UART_Delay_For_Bus_Early_Response();//for MT6255\MT6256 BUS limitation:early respones
         break;
      }
      else if(count > (MCU_BOOT_SPEED/debug_baudrate) ) 
      {
         DRV_UART_WriteReg(UART_THR(UART_BaseAddr[port]),(kal_uint16)data); //don't care the pending
		 UART_Delay_For_Bus_Early_Response();//for MT6255\MT6256 BUS limitation:early respones
         init_log_fail_count++;
         break;
   }
}
}

void U_PutUARTByte(UART_PORT port, kal_uint8 data)
{
   kal_uint16 LSR;
   
   while(1)
   {
      LSR = DRV_UART_Reg(UART_LSR(UART_BaseAddr[port]));
      if ( LSR & UART_LSR_THRE )
      {
         DRV_UART_WriteReg(UART_THR(UART_BaseAddr[port]),(kal_uint16)data);
		 UART_Delay_For_Bus_Early_Response();//for MT6255\MT6256 BUS limitation:early respones

         break;
      }
   }
}
void PutUARTData(UART_PORT port, kal_uint8 escape_char, kal_uint8 data)
{
   if(port >= MAX_UART_PORT_NUM)
      return;

   //only META port use old flow control escape character,
   if( (kal_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw && UARTPort[port].ownerid==MOD_DHL_READER)||
      (uart_support_autoescape()==KAL_FALSE))        
   {
      if (data == UARTPort[port].DCB.xonChar)
      {
           pUart_CMD_FUNC[port]->PutUARTByte(port, escape_char);
         pUart_CMD_FUNC[port]->PutUARTByte(port, 0x01);             
      }
      else if (data == UARTPort[port].DCB.xoffChar)
      {
         pUart_CMD_FUNC[port]->PutUARTByte(port, escape_char);
         pUart_CMD_FUNC[port]->PutUARTByte(port, 0x02);            
      }
      else if (data == escape_char)
      {
         pUart_CMD_FUNC[port]->PutUARTByte(port, escape_char);
         pUart_CMD_FUNC[port]->PutUARTByte(port, 0x03);            
      }
      else
      {
         pUart_CMD_FUNC[port]->PutUARTByte(port, data);
      }         
   }
   else
   {
      pUart_CMD_FUNC[port]->PutUARTByte(port, data);
   }   
}

void PutUARTByteDelay(UART_PORT port, kal_uint8 data)
{
   kal_uint16 LSR;
   kal_uint16 i;
   if(port >= MAX_UART_PORT_NUM)
      return;
   
   while(1)
   {
      LSR = DRV_UART_Reg(UART_LSR(UART_BaseAddr[port]));
      
      if( LSR & UART_LSR_THRE )
      {
         for(i=0; i < DELAY_FOR_PUTBYTE; i++); //add delay...
         DRV_UART_WriteReg(UART_THR(UART_BaseAddr[port]),(kal_uint16)data);
		 UART_Delay_For_Bus_Early_Response();//for MT6255\MT6256 BUS limitation:early respones

         break;
      }
   }
}

void PutUARTDataDelay(UART_PORT port, kal_uint8 escape_char, kal_uint8 data)
{
   if(port >= MAX_UART_PORT_NUM)
      return;

   if( (kal_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw && UARTPort[port].ownerid==MOD_DHL_READER)||
      (uart_support_autoescape()==KAL_FALSE))        
   {
      if (data == UARTPort[port].DCB.xonChar)
      {
         PutUARTByteDelay(port, escape_char);
         PutUARTByteDelay(port, 0x01);            
      }
      else if (data == UARTPort[port].DCB.xoffChar)
      {
         PutUARTByteDelay(port, escape_char);
         PutUARTByteDelay(port, 0x02);            
      }
      else if (data == escape_char)
      {
         PutUARTByteDelay(port, escape_char);
         PutUARTByteDelay(port, 0x03);            
      }
      else
      {
         PutUARTByteDelay(port, data);
      }         
   }
   else
   {
      PutUARTByteDelay(port, data);
   }   
}


void UART_Boot_PutUARTBytes(UART_PORT port, kal_uint8 *data,kal_uint16 len)
{
   volatile kal_uint16 LSR;
   kal_uint16 index;
   static kal_uint32 UART_Boot_Send_Count = 0;
   
  UART_Boot_Send_Count+=len;
  
   for(index=0;index<len;index++)
      //UART_PutUARTByte_limited(port,*(data+index));  //this function could be phase out
      U_PutUARTByte(port, *(data+index));             //added by zhanguo 
   index = 0;
   while(1) //make sure tx already send out all data.
   {
      LSR = DRV_UART_Reg(UART_LSR(UART_BaseAddr[port]));
      if( LSR & UART_LSR_THRE )
      {
         break;
      }else if( (MCU_BOOT_SPEED/debug_baudrate) < index++)
      {
         init_log_fail_count++;
         break;
      }
   }
}

void U_PutUARTBytes(UART_PORT port, kal_uint8 *data,kal_uint16 len)
{
   kal_uint16 index;

   for(index=0;index<len;index++)
      pUart_CMD_FUNC[port]->PutUARTByte(port,*(data+index));
}
void PutUARTDatas(UART_PORT port, kal_uint8 escape_char, kal_uint8 *data,kal_uint16 len)
{
   kal_uint16 index;
   if(port >= MAX_UART_PORT_NUM)
      return;
   
   if( (INT_Exception_Enter > 0) && (0 == UARTPort[port].Tx_DMA_Ch) && (1500000 == UARTPort[port].DCB.baud))
      for(index=0;index<len;index++)
         PutUARTDataDelay(port,escape_char,*(data+index));
      else   
         for(index=0;index<len;index++)
            PutUARTData(port,escape_char,*(data+index));
}

void UART_AUTO_BAUDRATE_Clear_DLL_DLM(UART_PORT port)
{
#ifdef  DRV_UART_AUTO_BAUDRATE_BUG
// there is a bug on auto baudrate,Rx maybe hang when the DLL and DLM are not 0 before  auto baudrate.
//workaround:  clear DLL and DLM before auto baudrate.
	kal_uint16	 byte;
	byte = DRV_UART_Reg(UART_LCR(UART_BaseAddr[port]));	  /* DLAB start */
	DRV_UART_WriteReg(UART_LCR(UART_BaseAddr[port]),0xbf);			  
	DRV_UART_WriteReg(UART_DLL(UART_BaseAddr[port]),0x01);   // modified to 1 invoid of appearing dirty bytes  when PC sends AT commands
	DRV_UART_WriteReg(UART_DLH(UART_BaseAddr[port]),0);
	DRV_UART_WriteReg(UART_LCR(UART_BaseAddr[port]),byte);		/* DLAB End */		
#endif
}


void U_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type ownerid)
{
   kal_uint32   tmp_div;
   kal_uint16   divisor;
   kal_uint16   byte;
   kal_uint32   remainder;
   kal_uint32   UART_BASE;
   kal_uint32	  uart_clock=0;
#if defined(DRV_UART_HIGH_SPEED)
#if !defined(DRV_UART_SPEED_SAMPLE_COUNT)
   kal_uint8    counterBase=4; // toy add for High Speed sample counter base, this value can be 8 or 4
#endif
#endif
#if defined(DRV_UART_COMPENSATE_AT)
  //only for 6251 & 6252 & 6253L & 6253EL,because there is hw bug.
  //when auto setbaudRate,hw could set autobaudrate correct ,but can't receive "AT"\"at",but application maybe use "AT"\"at",so we add  "AT"\"at" to Rec Buffer!

  // kal_uint8 itmp; //avoid Warning 534: Ignoring return value of function 'GPTI_GetHandle"
 //  kal_bool     btmp;
 SGPT_CTRL_START_T start;
#endif //#if defined(DRV_UART_COMPENSATE_AT)

   UART_BASE = UART_BaseAddr[port];
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
#ifdef DCM_ENABLE   
/*
#if defined(__USE_921600_WITHOUT_SAMPLE_COUNT__)
   if(port!=uart_port3 && port!=uart_port2 && baudrate != UART_BAUD_AUTO)	// UART_BAUD_AUTO work around
#elif !defined(DRV_UART_SPEED_SAMPLE_COUNT)// BT and GPS not use UART2 and UART can not support DCM
   if(port!=uart_port3 && baudrate != UART_BAUD_AUTO)	// UART_BAUD_AUTO can not working under rate fix of 25, 23, 35, 38, 68, 53, 16   
#else  
   if(baudrate != UART_BAUD_AUTO)	// UART_BAUD_AUTO work around
#endif*//*defined(__USE_921600_WITHOUT_SAMPLE_COUNT__)*/ 
#if defined(__USE_UART2_921600__)
   if(port!=uart_port3 && port!=uart_port2 && baudrate != UART_BAUD_AUTO)	// UART_BAUD_AUTO work around
#else  
   if(port!=uart_port3 && baudrate != UART_BAUD_AUTO)	// UART_BAUD_AUTO work around
#endif/*defined(__USE_UART2_921600__)*/ 
      {
         DRV_UART_WriteReg(UART_RATE_FIX_REG(UART_BASE),UART_RATE_FIX);/*13 or 15.36*/   
         uart_clock=UART_DCM_CLOCK;/*fixed uart clock for DCM*/
      } 	
      else
      {
          #if defined(DRV_UART_DCM_BUG_FIXED) || defined(DRV_UART_DCM_NO_BUG)
        if(baudrate != UART_BAUD_AUTO)
        {
            DRV_UART_WriteReg(UART_RATE_FIX_REG(UART_BASE),UART_RATE_FIX);/*13 or 15.36*/   
            uart_clock=UART_DCM_CLOCK;/*fixed uart clock for DCM*/
        }
        else
        {
            DRV_UART_WriteReg(UART_RATE_FIX_REG(UART_BASE),0x0);   
             uart_clock=UART_CLOCK;  
        }

         #else
         DRV_UART_WriteReg(UART_RATE_FIX_REG(UART_BASE),0x0);   
         uart_clock=UART_CLOCK;   
         #endif  
      }
#else
      uart_clock=UART_CLOCK;
   #if defined(MT6573)&&defined(__SMART_PHONE_MODEM__)
     DRV_WriteReg(UART_RATE_FIX_REG(UART_BASE),UART_RATE_FIX);
     uart_clock=UART_DCM_CLOCK;
   #endif
      
#endif/* DCM_ENABLE*/
      
      
#if defined(DRV_UART_FRACTIONAL)
      DRV_UART_WriteReg(UART_FRACDIV_L(UART_BASE),0); //clear fraction
      DRV_UART_WriteReg(UART_FRACDIV_M(UART_BASE),0);
#endif
      
      if ( baudrate != UART_BAUD_AUTO ) /* no autobaud */
      {
         if (baudrate <= UART_BAUD_115200)
         {
            /* Set BaudRate   */             
            tmp_div = (uart_clock)/(16*baudrate);
            divisor =  (kal_uint16)tmp_div;
            
            remainder = (uart_clock)%(16*baudrate);
            
            if (remainder >= (8*baudrate))
               divisor =  (kal_uint16)(tmp_div+1);
            else
               divisor =  (kal_uint16)tmp_div;
            
            
            
#if defined(DRV_UART_HIGH_SPEED)
            DRV_UART_WriteReg(UART_RATE_STEP(UART_BASE),0x0);
#endif
            
		#ifdef DCM_ENABLE
		#if defined(DRV_UART_DCM_BUG_FIXED)
			DRV_UART_ClearBits(UART_MCR(UART_BASE),  UART_MCR_DCM_EN); // Fix DCM hw bug
		#endif
		#endif
		     
            /* GPIO_WriteAll(divisor); */
            byte = DRV_UART_Reg(UART_LCR(UART_BASE));     /* DLAB start */
            DRV_UART_WriteReg(UART_LCR(UART_BASE),(byte | UART_LCR_DLAB));
            
            DRV_UART_WriteReg(UART_DLL(UART_BASE),(divisor & 0x00ff));
            DRV_UART_WriteReg(UART_DLH(UART_BASE),((divisor >> 8)&0x00ff));
            DRV_UART_WriteReg(UART_LCR(UART_BASE),byte);      /* DLAB End */
#ifdef __MTK_INTERNAL__
            uart_lcr_save[port] = byte;
#endif   /*__PRODUCTION_RELEASE__*/
         }
#if defined(DRV_UART_HIGH_SPEED)
         else    //support high speed uart baudrate > 115200
         {
#if !defined(DRV_UART_SPEED_SAMPLE_COUNT)
            if(baudrate < UART_BAUD_921600)
            {
               counterBase = 4; //only define under DRV_UART_HIGH_SPEED && !DRV_UART_SPEED_SAMPLE_COUNT
               DRV_UART_WriteReg(UART_RATE_STEP(UART_BASE),0x02);
            }
            else
            {
               counterBase = 8; //only define under DRV_UART_HIGH_SPEED && !DRV_UART_SPEED_SAMPLE_COUNT
               DRV_UART_WriteReg(UART_RATE_STEP(UART_BASE),0x01);
            }
            tmp_div = (uart_clock)/(counterBase*baudrate);
            divisor =  (kal_uint16)tmp_div;
            remainder = (uart_clock)%(counterBase*baudrate);
            if (remainder >= (2*baudrate))
               divisor =  (kal_uint16)(tmp_div+1);
            else
               divisor =  (kal_uint16)tmp_div;
            
            byte = DRV_UART_Reg(UART_LCR(UART_BASE));     /* DLAB start */
            DRV_UART_WriteReg(UART_LCR(UART_BASE),(byte | UART_LCR_DLAB));
            DRV_UART_WriteReg(UART_DLL(UART_BASE),(divisor & 0x00ff));
            DRV_UART_WriteReg(UART_DLH(UART_BASE),((divisor >> 8)&0x00ff));
            DRV_UART_WriteReg(UART_LCR(UART_BASE),byte);      /* DLAB End */
#else /* !defined(DRV_UART_SPEED_SAMPLE_COUNT) */
            kal_uint16   high_speed_div, data;
            kal_uint16	 sample_count, sample_point;
#if defined(DRV_UART_FRACTIONAL)
            kal_uint32  fraction;
            kal_uint16  fraction_L_mapping[] = {0, 1, 0x5, 0x15, 0x55, 0x57, 0x57, 0x77, 0x7F, 0xFF, 0xFF};
            kal_uint16  fraction_M_mapping[] = {0, 0,   0,    0,    0,    0,    1,    1,    1,    1,  0x3};
#endif //#if defined(DRV_UART_FRACTIONAL)
            data=(kal_uint16)(uart_clock/baudrate);
            high_speed_div = (data>>8) + 1; // divided by 256
            
            tmp_div=uart_clock/(baudrate*high_speed_div);
            divisor =  (kal_uint16)tmp_div;
            
#if defined(DRV_UART_FRACTIONAL)
            fraction = ((uart_clock*10)/baudrate)%10; //count fraction to set fractoin register
            DRV_UART_WriteReg(UART_FRACDIV_L(UART_BASE),fraction_L_mapping[fraction]);
            DRV_UART_WriteReg(UART_FRACDIV_M(UART_BASE),fraction_M_mapping[fraction]);
#else
            remainder = (uart_clock)%(high_speed_div*baudrate);
            /*get (sample_count+1)*/
            if (remainder >= ((baudrate)*(high_speed_div))>>1)
               divisor =  (kal_uint16)(tmp_div+1);
            else
               divisor =  (kal_uint16)tmp_div;		      
#endif //#if defined(UART_FRACTIONAL)
            
            sample_count=divisor-1;
            
            /*get the sample point*/
            sample_point=(kal_uint16)(sample_count-1)>>1;
            
            /*configure register*/

			#ifdef DCM_ENABLE
			#if defined(DRV_UART_DCM_BUG_FIXED)
			DRV_UART_SetBits(UART_MCR(UART_BASE),  UART_MCR_DCM_EN); // Fix DCM hw bug
			#endif
			#endif
			
            DRV_UART_WriteReg(UART_RATE_STEP(UART_BASE),0x3);
            
            byte = DRV_UART_Reg(UART_LCR(UART_BASE));     /* DLAB start */
            DRV_UART_WriteReg(UART_LCR(UART_BASE),(byte | UART_LCR_DLAB));
            
            DRV_UART_WriteReg(UART_DLL(UART_BASE),(high_speed_div & 0x00ff));
            DRV_UART_WriteReg(UART_DLH(UART_BASE),((high_speed_div >> 8)&0x00ff));
            
            DRV_UART_WriteReg(UART_STEP_COUNT(UART_BASE),sample_count);
            DRV_UART_WriteReg(UART_SAMPLE_COUNT(UART_BASE),sample_point);
            DRV_UART_WriteReg(UART_LCR(UART_BASE),byte);      /* DLAB End */      
#if defined(DRV_UART_GUARD_DALAY_IN_3M)
            if(baudrate >= 3000000)
            {
               DRV_UART_WriteReg(UART_GUARD(UART_BASE),0x12); //delay 2 bits per byte.
            }
#endif
#endif /* !defined(DRV_UART_SPEED_SAMPLE_COUNT) */
         }
#endif
         
        }
#if defined(DRV_UART_AUTO_BAUD)
        else
        {
#if defined(DRV_UART_COMPENSATE_AT)
            //prepare to polling data ready, because there won't trigger interrupt.
   	    if (UARTPort[port].handle == 0xFF)
			    UARTPort[port].handle = DclSGPT_Open(DCL_GPT_CB, 0);			    
		DclSGPT_Control(UARTPort[port].handle,SGPT_CMD_STOP,0);
              // itmp = GPTI_GetHandle(&UARTPort[port].handle);
   //            GPTI_GetHandle(&UARTPort[port].handle);
    //        GPTI_StopItem(UARTPort[port].handle);

            UARTPort[port].CompensateAT = Compensate_Wait;
            if(UARTPort[port].Rx_DMA_Ch != 0)
            {
               DRV_UART_WriteReg(UART_RXDMA(UART_BASE), UART_TXRXDMA_OFF);
               DMA_Stop(UARTPort[port].Rx_DMA_Ch);              
            }
#endif //#ifdef DRV_UART_COMPENSATE_AT
#ifdef DCM_ENABLE
           UARTPort[port].AutobaudDetection = KAL_TRUE; //autobaud conflict rate fix
           DCM_Disable(UARTPort[port].DCMHandle);
           DRV_UART_WriteReg(UART_RATE_STEP(UART_BaseAddr[port]),0x0);// autobaud must use speed 0		#ifdef DCM_ENABLE

		#if defined(DRV_UART_DCM_BUG_FIXED)
			DRV_UART_ClearBits(UART_MCR(UART_BASE),  UART_MCR_DCM_EN); // Fix DCM hw bug
		#endif
	
           
#endif
           switch (uart_clock)
           {
           case   13000000:
              DRV_UART_WriteReg(UART_AUTO_BAUDSAMPLE(UART_BASE),AUTOBAUDSAMPLE_13M);
              break;
           case   26000000:
              DRV_UART_WriteReg(UART_AUTO_BAUDSAMPLE(UART_BASE),AUTOBAUDSAMPLE_26M);
              break;
           case   52000000:
              DRV_UART_WriteReg(UART_AUTO_BAUDSAMPLE(UART_BASE),AUTOBAUDSAMPLE_52M);
              break;
           case   15360000:
              DRV_UART_WriteReg(UART_AUTO_BAUDSAMPLE(UART_BASE),AUTOBAUDSAMPLE_15_36M);
              break;
           case   30720000:
              DRV_UART_WriteReg(UART_AUTO_BAUDSAMPLE(UART_BASE),AUTOBAUDSAMPLE_30_72M);
              break;
           case   61440000:
              DRV_UART_WriteReg(UART_AUTO_BAUDSAMPLE(UART_BASE),AUTOBAUDSAMPLE_61_44M);
              break;
           default:
              break;
           }
		   UART_AUTO_BAUDRATE_Clear_DLL_DLM(port);
           DRV_UART_WriteReg(UART_AUTOBAUD_EN(UART_BASE),AUTOBAUD_EN);
#ifdef DRV_UART_COMPENSATE_AT
           // polling data ready after set autobaud
          // btmp = GPTI_StartItem(UARTPort[port].handle,
/*
          GPTI_StartItem(UARTPort[port].handle,
                     10,
                     UART_CheckAT_Callback,
                     &UARTPort[port]);
 */
 start.u2Tick=10;
start.pfCallback=UART_CheckAT_Callback;
start.vPara=&UARTPort[port];
DclSGPT_Control(UARTPort[port].handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);  
	
#endif //#ifdef DRV_UART_COMPENSATE_AT
        }
#endif
}

void UART_Bootup_Init()
{
	UARTPort[debug_port].ownerid = (module_type)( (kal_uint16)MOD_UART1_HISR + (kal_uint8)debug_port );

   //Set SW flow control as equal to catcher default flow control
   DRV_UART_WriteReg(UART_LCR(UART1_base),0xbf);            /* Enchance setting */
   DRV_UART_WriteReg(UART_EFR(UART1_base),UART_EFR_SWFlowCtrlX1);
   //if( (uart_support_autoescape()==KAL_TRUE) && (kal_query_boot_mode() != FACTORY_BOOT))
   //always open as new SW flow control, TST under META will reset to disable
   {  
      DRV_UART_WriteReg(UART_ESCAPE_DAT(UART1_base),0x77);
      DRV_UART_WriteReg(UART_ESCAPE_EN(UART1_base),0x1);
   }              
   DRV_UART_WriteReg(UART_XON1(UART1_base),0x11);
   DRV_UART_WriteReg(UART_XOFF1(UART1_base),0x13);
   DRV_UART_WriteReg(UART_XON2(UART1_base),0x11);
   DRV_UART_WriteReg(UART_XOFF2(UART1_base),0x13);
   DRV_UART_WriteReg(UART_LCR(UART1_base),0x3);
   
#ifdef DRV_UART_SET_REG_DELAY_FOR_HW_BUG  //only for TK6280  
//add liming:for uart hw bug,when set uart register,there may be error,for example:when set  LCR fron 0xbf to 0x03,MCR and XON1 will be mix up. Delay several codes in UART_Bootup_Init()  will be ok.
//only for TK6280, 
DRV_UART_WriteReg(UART_LCR(UART1_base),0x3);
DRV_UART_WriteReg(UART_MCR(UART1_base),0x03);
DRV_UART_WriteReg(UART_LCR(UART1_base),0x3);
   DRV_UART_WriteReg(UART_LCR(UART1_base),0x3);
#endif  //#ifdef DRV_UART_SET_REG_DELAY_FOR_HW_BUG  //only for TK6280  

	U_SetBaudRate(debug_port, debug_baudrate, (module_type)( (kal_uint16)MOD_UART1_HISR + (kal_uint8)debug_port ));
}

/*This function is to cover 6218B/6219 hw bug.
UART should not send receiving data to its FIFO when doing auto baud*/
void U_SetAutoBaud_Div(UART_PORT port, module_type ownerid)
{
   kal_uint32   UART_BASE;
   kal_uint8 byte;

   UART_BASE = UART_BaseAddr[port];
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   /*TY adds this compile option 20041006*/   
   if(uart_support_autoescape()==KAL_FALSE)
   {
      byte = DRV_UART_Reg(UART_LCR(UART_BASE));     /* DLAB start */
      DRV_UART_WriteReg(UART_LCR(UART_BASE),(byte | UART_LCR_DLAB));
      
      DRV_UART_WriteReg(UART_DLL(UART_BASE),0xff);
      DRV_UART_WriteReg(UART_DLH(UART_BASE),0xff);
      DRV_UART_WriteReg(UART_LCR(UART_BASE),byte);      /* DLAB End */   
   }      
}   

void U_SetDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid)
{
   kal_uint16   byte;
   kal_uint16   IER;
   kal_uint32   savedMask;
   kal_uint32   UART_BASE;

   UART_BASE = UART_BaseAddr[port];
#ifdef DRV_DEBUG
   if (uart_initialize[port] && (UARTPort[port].ownerid != ownerid))
      return;
#endif /*DRV_DEBUG*/
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   savedMask = SaveAndSetIRQMask();
   IER = DRV_UART_Reg(UART_IER(UART_BASE));
   DRV_UART_WriteReg(UART_IER(UART_BASE),UART_IER_ALLOFF);
   UART_Delay_For_Bus_Early_Response();//for MT6255\MT6256 BUS limitation:early respones

   RestoreIRQMask(savedMask);

   U_SetBaudRate(port, UART_Config->baud, ownerid);
   
   /* Setup N81 */
   byte = DRV_UART_Reg(UART_LCR(UART_BASE));     /* DLAB start */
   byte &= ~UART_DATA_MASK;
   switch(UART_Config->dataBits)
   {
   case len_5:
      byte |= UART_WLS_5;
      break;
      
   case len_6:
      byte |= UART_WLS_6;
      break;
      
   case len_7:
      byte |= UART_WLS_7;
      break;
      
   case len_8:
      byte |= UART_WLS_8;
      break;
      
   default:
      break;
   }
   byte &= ~UART_STOP_MASK;
   switch(UART_Config->stopBits)
   {
   case sb_1:
      byte |= UART_1_STOP;
      break;
      
   case sb_2:
      byte |= UART_2_STOP;
      break;
      
   case sb_1_5:
      byte |= UART_1_5_STOP;
      break;
      
   default:
      break;
   }
   
   byte &= ~UART_PARITY_MASK;
   switch(UART_Config->parity)
   {
   case pa_none:
      byte |= UART_NONE_PARITY;
      break;
      
   case pa_odd:
      byte |= UART_ODD_PARITY;
      break;
      
   case pa_even:
      byte |= UART_EVEN_PARITY;
      break;
   case pa_mark:
   	   byte |= UART_MARK_PARITY;
     break; 
   case pa_space:
      byte |= UART_SPACE_PARITY;
      break;
      
   default:
      break;
   }
   DRV_UART_WriteReg(UART_LCR(UART_BASE),byte);            /* DLAB End */
   /* flowControl */
   byte = DRV_UART_Reg(UART_LCR(UART_BASE));
   /* DRV_UART_WriteReg(UART_LCR,(byte | UART_LCR_DLAB));   // DLAB start */
   DRV_UART_WriteReg(UART_LCR(UART_BASE),0xbf);            /* Enchance setting */
   switch(UART_Config->flowControl)
   {
   case fc_none:
      DRV_UART_WriteReg(UART_EFR(UART_BASE),UART_EFR_ALLOFF);
      
      // Disable AutoEscape, we expect to use this functionality for S/W flow control
      /*For AutoEscape*/
      DRV_UART_WriteReg(UART_ESCAPE_EN(UART_BaseAddr[port]),0x0);
      
      break;
      
   case fc_hw:
      IER |= UART_IER_VFF_FC_EN;
      DRV_UART_WriteReg(UART_EFR(UART_BASE),UART_EFR_AutoRTSCTS);
      
      // Disable AutoEscape, we expect to use this functionality for S/W flow control
      /*For AutoEscape*/
      DRV_UART_WriteReg(UART_ESCAPE_EN(UART_BaseAddr[port]),0x0);
      break;
      
   case fc_sw:
      DRV_UART_WriteReg(UART_EFR(UART_BASE),UART_EFR_SWFlowCtrlX1);                               
      IER |= UART_IER_VFF_FC_EN;
      //reset first
      DRV_UART_WriteReg(UART_ESCAPE_EN(UART_BaseAddr[port]),0x0);
      if(uart_support_autoescape()==KAL_TRUE)
      {  
         /*For META, Dont use auto escape*/ 
         if(kal_query_boot_mode() != FACTORY_BOOT || UARTPort[port].ownerid != MOD_DHL_READER)
         {
            /*For AutoEscape*/
            DRV_UART_WriteReg(UART_ESCAPE_DAT(UART_BaseAddr[port]),0x77);
            DRV_UART_WriteReg(UART_ESCAPE_EN(UART_BaseAddr[port]),0x1);
         }
      }              
      break;
      
   default:    
      break;
   }
#ifdef __DMA_UART_VIRTUAL_FIFO__
#if defined(DRV_UART_COMPENSATE_AT)
   if(UARTPort[port].CompensateAT == Compensate_Wait) //Disable VFIFO
      DRV_UART_WriteReg(UART_RXDMA(UART_BASE),UART_TXRXDMA_OFF);
   else
#else
      if( UART_IsVfifoSetting(port, RX_VFIFO) )
     	   DRV_UART_WriteReg(UART_RXDMA(UART_BASE),UART_TXRXDMA_ON);
#endif //#if defined(DRV_UART_COMPENSATE_AT)
#endif
   /* XON and XOFF characters */
   DRV_UART_WriteReg(UART_XON1(UART_BASE),UART_Config->xonChar);
   DRV_UART_WriteReg(UART_XOFF1(UART_BASE),UART_Config->xoffChar);
   DRV_UART_WriteReg(UART_XON2(UART_BASE),UART_Config->xonChar);
   DRV_UART_WriteReg(UART_XOFF2(UART_BASE),UART_Config->xoffChar);
   DRV_UART_WriteReg(UART_LCR(UART_BASE),byte);         /* DLAB End */
#ifdef __MTK_INTERNAL__
   uart_lcr_save[port] = byte;
#endif   /*__PRODUCTION_RELEASE__*/
   
#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
   if (UART_Config->DSRCheck)
   {
      if (DRV_UART_Reg(UART_MSR(UART_BASE)) & UART_MSR_DSR)
      {    
         UART_PDN_Disable(port);         
      }
      else
      {
		  UART_PDN_Enable(port);
      }
   }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
   
   /*lint -e(534)*/kal_mem_cpy( &UARTPort[port].DCB, UART_Config, sizeof(UARTDCBStruct) );
   
   savedMask = SaveAndSetIRQMask();
   DRV_UART_WriteReg(UART_IER(UART_BASE),IER);
   RestoreIRQMask(savedMask);
}

void U_ReadDCBConfig (UART_PORT port, UARTDCBStruct *DCB)
{
   /*lint -e(534)*/kal_mem_cpy( DCB, &UARTPort[port].DCB, sizeof(UARTDCBStruct) );
}

void UART_loopback(UART_PORT port)
{
   kal_uint16 tmp;
   kal_uint32 UART_BASE;
   /* Enable Loop Back test!! */
   if(port >= MAX_UART_PORT_NUM)
      return;
   UART_BASE = UART_BaseAddr[port];
   tmp = DRV_UART_Reg(UART_MCR(UART_BASE));
   tmp |= UART_MCR_LOOPB;
   DRV_UART_WriteReg(UART_MCR(UART_BASE),tmp);
}

void UART_loopback_btmt(UART_PORT port,kal_bool enable)
{
   kal_uint16 tmp;
   kal_uint32 UART_BASE;
   /* Enable Loop Back test!! */
   if(port >= MAX_UART_PORT_NUM)
      return;
   UART_BASE = UART_BaseAddr[port];
   tmp = DRV_UART_Reg(UART_MCR(UART_BASE));
   if(KAL_TRUE==enable)
      tmp |= UART_MCR_LOOPB;
   else
      tmp &=~UART_MCR_LOOPB;
   DRV_UART_WriteReg(UART_MCR(UART_BASE),tmp);
}


void UART_HWInit(UART_PORT port)
{
   //kal_uint8 tmp;
   UARTDCBStruct *DCBdefault;
   UARTDCBStruct  UART_DefaultConfig =
   {
      UART_BAUD_115200,    /* baud; */
         len_8,               /* dataBits; */
         sb_1,                /*stopBits; */
         pa_none,             /* parity; */
         fc_none,             /*no flow control*/
         0x11,                /* xonChar; */
         0x13,                /* xoffChar; */
         KAL_FALSE
   };
   kal_uint32 UART_BASE;
   if(port >= MAX_UART_PORT_NUM)
      return;
   UART_BASE = UART_BaseAddr[port];
#ifdef __ROMSA_SUPPORT__
   /*for MCUROM*/
#ifdef DRV_DEBUG
   UART_debug=KAL_TRUE;
#else
   UART_debug=KAL_FALSE;
#endif
#ifdef __DMA_UART_VIRTUAL_FIFO__
   UART_Virtual_FIFO=KAL_TRUE;
#else
   UART_Virtual_FIFO=KAL_FALSE;
#endif
#endif
   
#if !defined(__WRITE_THROUGH_CACHEABLE__)   
   // MT6238/MT6235 D-cache plan phase #1 begin
   // Check if ring buffer is cacheable or NOT
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
   if (INT_QueryIsCachedRAM((kal_uint32)UART_rings->ring[uart_port1].rx_adrs, (kal_uint32)UART_rings->ring[uart_port1].rx_len) 
      || INT_QueryIsCachedRAM((kal_uint32)UART_rings->ring[uart_port1].tx_adrs, (kal_uint32)UART_rings->ring[uart_port1].tx_len)) {
      EXT_ASSERT(0, (kal_uint32)UART_rings->ring[uart_port1].rx_adrs, (kal_uint32)UART_rings->ring[uart_port1].tx_adrs, UART_rings->ring[uart_port1].rx_len);
   }
 #if !defined(DRV_MD_1_UART)
   if (INT_QueryIsCachedRAM((kal_uint32)UART_rings->ring[uart_port2].rx_adrs, (kal_uint32)UART_rings->ring[uart_port2].rx_len) 
      || INT_QueryIsCachedRAM((kal_uint32)UART_rings->ring[uart_port2].tx_adrs, (kal_uint32)UART_rings->ring[uart_port2].tx_len)) {
      EXT_ASSERT(0, (kal_uint32)UART_rings->ring[uart_port2].rx_adrs, (kal_uint32)UART_rings->ring[uart_port2].tx_adrs, UART_rings->ring[uart_port2].rx_len);
   }
   #endif
#ifdef __UART3_SUPPORT__
   if (INT_QueryIsCachedRAM((kal_uint32)UART_rings->ring[uart_port3].rx_adrs, (kal_uint32)UART_rings->ring[uart_port3].rx_len) 
      || INT_QueryIsCachedRAM((kal_uint32)UART_rings->ring[uart_port3].tx_adrs, (kal_uint32)UART_rings->ring[uart_port3].tx_len)) {
      EXT_ASSERT(0, (kal_uint32)UART_rings->ring[uart_port3].rx_adrs, (kal_uint32)UART_rings->ring[uart_port3].tx_adrs, UART_rings->ring[uart_port3].rx_len);
   }
#endif // #ifdef __UART3_SUPPORT__
#endif //#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
   
   // MT6238/MT6235 D-cache plan phase #1 end
#endif // #if defined(__WRITE_THROUGH_CACHEABLE__)
   
#ifdef DCM_ENABLE
   UARTPort[port].DCMHandle = DCM_GetHandle();// UART_BAUD_AUTO conflict with rate fix, need to disable DCM
   UARTPort[port].AutobaudDetection = KAL_FALSE; //autobaud conflict rate fix
#endif
#if defined(DRV_UART_COMPENSATE_AT)
   UARTPort[port].CompensateAT = Compensate_None;     //MT6253 need compensate AT
#endif
   switch(port)
   {
   case uart_port1:
#if defined(__OLD_PDN_ARCH__)
#if defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
#elif defined(DRV_MISC_PDN_NO_SET_CLR)
      DRV_UART_ClearBits(DRVPDN_CON1, DRVPDN_CON1_UART1);
      //DRV_UART_Reg(DRVPDN_CON1) &= ~(DRVPDN_CON1_UART1);
#else  //#if defined(DRV_MISC_TDMA_PDN0)
#if defined(__OLD_PDN_DEFINE__)
      DRV_UART_WriteReg(DRVPDN_CON1_CLR, DRVPDN_CON1_UART1);
#elif defined(__APPLICATION_PROCESSOR__) //MT6516 AP side
      DRV_UART_WriteReg(CG_CLR0, CG_CON0_UART1);
#elif defined(__CLKG_DEFINE__)
      DRV_UART_WriteReg(CG_CLR1, CG_CON1_UART1);
#endif //#if defined(DRV_MISC_TDMA_PDN0)
#endif // #if defined(__OLD_PDN_DEFINE__)
#else //#if defined(__OLD_PDN_ARCH__)
      PDN_CLR(PDN_UART1);
#endif// #if defined(__OLD_PDN_ARCH__)
#ifdef __DMA_UART_VIRTUAL_FIFO__
      if( UART_IsVfifoSetting(port, RX_VFIFO) )
         DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].rx_adrs, UART_rings->ring[port].rx_len, (DMA_VFIFO_UART)UARTPort[uart_port1].Rx_DMA_Ch, KAL_FALSE);
      if( UART_IsVfifoSetting(port, TX_VFIFO) )
         DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].tx_adrs, UART_rings->ring[port].tx_len, (DMA_VFIFO_UART)UARTPort[uart_port1].Tx_DMA_Ch, KAL_TRUE);
#endif
      break;
#if !defined(DRV_MD_1_UART)// for MD only have one uart port,like MT6280
   case uart_port2:
#if defined(__OLD_PDN_ARCH__)
#if defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
#elif defined(DRV_MISC_PDN_NO_SET_CLR)
      DRV_UART_ClearBits(DRVPDN_CON1, DRVPDN_CON1_UART2);
      //DRV_UART_Reg(DRVPDN_CON1) &= ~(DRVPDN_CON1_UART2);
#else
#if defined(__OLD_PDN_DEFINE__)
      DRV_UART_WriteReg(DRVPDN_CON1_CLR, DRVPDN_CON1_UART2);
#elif defined(__APPLICATION_PROCESSOR__) //MT6516 AP side
      DRV_UART_WriteReg(CG_CLR0, CG_CON0_UART2);
#elif defined(__CLKG_DEFINE__)
      DRV_UART_WriteReg(CG_CLR1, CG_CON1_UART2);
#endif // #if defined(__OLD_PDN_DEFINE__)
#endif
#else //#if defined(__OLD_PDN_ARCH__)
      PDN_CLR(PDN_UART2);
#endif// #if defined(__OLD_PDN_ARCH__)
#ifdef __DMA_UART_VIRTUAL_FIFO__
      if( UART_IsVfifoSetting(port, RX_VFIFO) )
         DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].rx_adrs, UART_rings->ring[port].rx_len, (DMA_VFIFO_UART)UARTPort[uart_port2].Rx_DMA_Ch, KAL_FALSE);
      if( UART_IsVfifoSetting(port, TX_VFIFO) )
         DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].tx_adrs, UART_rings->ring[port].tx_len, (DMA_VFIFO_UART)UARTPort[uart_port2].Tx_DMA_Ch, KAL_TRUE);
#endif
      break;
#endif

#ifdef __UART3_SUPPORT__
   case uart_port3:         
#if defined(__OLD_PDN_ARCH__)
#if defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
#elif defined(DRV_MISC_PDN_NO_SET_CLR)
      DRV_UART_ClearBits(DRVPDN_CON1, DRVPDN_CON1_UART3);
      //DRV_UART_Reg(DRVPDN_CON1) &= ~(DRVPDN_CON1_UART3);
#else
#if defined(__OLD_PDN_DEFINE__)
      DRV_UART_WriteReg(DRVPDN_CON1_CLR, DRVPDN_CON1_UART3);
#elif defined(__APPLICATION_PROCESSOR__) //MT6516 AP side
      DRV_UART_WriteReg(CG_CLR0, CG_CON0_UART3);
#elif defined(__CLKG_DEFINE__)
      DRV_UART_WriteReg(CG_CLR1, CG_CON1_UART3);
#endif // #if defined(__OLD_PDN_DEFINE__)
#endif
#else //#if defined(__OLD_PDN_ARCH__)
      PDN_CLR(PDN_UART3);
#endif// #if defined(__OLD_PDN_ARCH__)
#ifdef __DMA_UART_VIRTUAL_FIFO__
      if( UART_IsVfifoSetting(port, RX_VFIFO) )
         DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].rx_adrs, UART_rings->ring[port].rx_len, (DMA_VFIFO_UART)UARTPort[uart_port3].Rx_DMA_Ch, KAL_FALSE);
      if( UART_IsVfifoSetting(port, TX_VFIFO) )
         DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].tx_adrs, UART_rings->ring[port].tx_len, (DMA_VFIFO_UART)UARTPort[uart_port3].Tx_DMA_Ch, KAL_TRUE);
#endif/*__DMA_UART_VIRTUAL_FIFO__*/         
      break;
#endif   /*__UART3_SUPPORT__*/
   default:
      ASSERT(0);
      break;
   }
   
   DCBdefault = (UARTDCBStruct *)&UART_DefaultConfig;
   /* Setup N81,(UART_WLS_8 | UART_NONE_PARITY | UART_1_STOP) = 0x03 */


   /* BaudRate and autoflowcontrol */
   if(port == debug_port)
   {
      DCBdefault->baud = debug_baudrate;
     #if !defined(__MEUT__) && !defined(__MEIT__)  //liming add  for MEUT test(when uart1 as comunication port,can't sw flowcontrol,for testcase19(0x13))
      DCBdefault->flowControl = fc_sw;
     #endif
   }

   U_SetDCBConfig(port, DCBdefault, UARTPort[port].ownerid);
   
#ifdef UART_HIGHSPEED_TEST
   DRV_UART_WriteReg(UART_RATE_STEP(UART_BASE),0x01);
   DRV_UART_WriteReg(UART_LCR(UART_BASE),0xbf);
   DRV_UART_WriteReg(UART_DLL(UART_BASE),0x07);
   DRV_UART_WriteReg(UART_LCR(UART_BASE),0x03);
#endif   /*UART_HIGHSPEED_TEST*/
   /* SER_SetConfig((char *)DCBdefault); */
   
   DRV_UART_Reg(UART_LSR(UART_BASE));
   DRV_UART_Reg(UART_MSR(UART_BASE));
   /* DTR , RTS is on, data will be coming,Output2 is high */
   DRV_UART_SetBits(UART_MCR(UART_BASE),UART_MCR_Normal);
#if defined(DRV_UART_FIFO_FLOW_CONTROL)
   {
   kal_uint32 efr;
   efr = DRV_UART_Reg(UART_EFR(UART_BASE));
   DRV_UART_WriteReg(UART_EFR(UART_BASE), efr | UART_EFR_Enchance);
   DRV_UART_WriteReg(UART_RXTRI(UART_BASE),UART_RXTRI_VALUE); //Ataru suggest 3/4 rx FIFO size.
   }
#endif //#if defined(DRV_UART_FIFO_FLOW_CONTROL)
   //need to set Enchance bit first, then rx fifo flow control bit can be set in IER
   DRV_UART_WriteReg(UART_IER(UART_BASE),UART_IER_ALLOFF);
   /* Enable UART int. controller */
   /* UART1_IER, enable RDA, RLS, MS , disable THR interrupt */
   /* DRV_UART_WriteReg(UART1_IER,UART_IER_RDA); */
   
   // Set handle value to 0xFF to indicate this handle is invalid
   //GPTI_GetHandle(&UARTPort[port].handle);
   UARTPort[port].handle = 0xFF;
   
   
/*
	meaning of DRV_UART_VFIFO_V2_USE_GPT
	because UDVT load does not have KAL timer
	we use gpt timer to replace KAL timer on UDVT load
*/
#if defined(DRV_UART_VFIFO_V2_USE_GPT)
	 UARTPort[port].uart_flush_timer_handle= 0xFF;    /*GPT handle*/
	 UARTPort[port].uart_isr_flush_timer_handle= 0xFF;   /*GPT handle*/
#endif //defined(DRV_UART_VFIFO_V2_USE_GPT)

   UARTPort[port].Rec_state = UART_RecNormal;
   UARTPort[port].port_no = port;
   
   UARTPort[port].sleep_on_tx = uart_sleep_on_tx_allow;
   UARTPort[port].EnableTX= KAL_TRUE;
   UARTPort[port].power_on= KAL_TRUE;
#if defined(DRV_UART_BASIC_REG) //UART_SLEEP_EN only exist in DRV_UART_BASIC_REG
#if defined(DRV_UART_SLEEP_MODE)
#if (defined(DRV_UART_SLEEP_MODE_WORK_AROUND) && defined(MTK_SLEEP_ENABLE))   //Toy disable sleep for keep awake to output 3G log only for MT6268A
   DRV_UART_WriteReg(UART_SLEEP_EN(UART_BASE),KAL_FALSE);
#else
   DRV_UART_WriteReg(UART_SLEEP_EN(UART_BASE),KAL_TRUE);
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

kal_bool U_Open(UART_PORT port, module_type ownerid)
{
   kal_uint32 UART_BASE;
   kal_uint16  MSR;
   kal_uint8 byte;
   kal_uint8  irq_code=0;

   UART_BASE = UART_BaseAddr[port];
   if(port == uart_port_null)
      return KAL_FALSE;
   
#ifdef DRV_DEBUG
   UARTPort[port].ownerid = ownerid;
   if (uart_initialize[port])
      return KAL_TRUE;
   else
      uart_initialize[port] = KAL_TRUE;
#endif /*DRV_DEBUG*/
   
   //toy add case avoid lint error 56, 58
   if (UARTPort[port].initialized &&
      (UARTPort[port].ownerid != (module_type)((kal_uint16)MOD_UART1_HISR + (kal_uint8)port)))
      return KAL_FALSE;
   UARTPort[port].initialized = KAL_TRUE;
   UARTPort[port].ownerid = ownerid;
   

      
      UARTPort[port].RingBuffers.rx_buffer = UART_rings->ring[port].rx_adrs;
      UARTPort[port].RingBuffers.tx_buffer = UART_rings->ring[port].tx_adrs;
      Buf_init(&(UARTPort[port].Rx_Buffer),(kal_uint8 *)(UARTPort[port].RingBuffers.rx_buffer),(kal_uint16)UART_rings->ring[port].rx_len);
      Buf_init(&(UARTPort[port].Tx_Buffer),(kal_uint8 *)(UARTPort[port].RingBuffers.tx_buffer),(kal_uint16)UART_rings->ring[port].tx_len);   
      if( UART_IsVfifoSetting(port, TX_VFIFO) == KAL_FALSE )
      {
         UARTPort[port].RingBuffers.txISR_buffer = UART_rings->ring[port].txisr_adrs;
         Buf_init(&(UARTPort[port].Tx_Buffer_ISR),(kal_uint8 *)(UARTPort[port].RingBuffers.txISR_buffer),(kal_uint16)UART_rings->ring[port].txisr_len);				
      }

#ifdef __DMA_UART_VIRTUAL_FIFO__
#if defined(DRV_UART_VFIFO_V2)	
      if( UART_IsVfifoSetting(port, RX_VFIFO) )
      	{
      		DRV_UART_WriteReg32(DMA_VFF_RPT(UARTPort[port].Rx_DMA_Ch), 0);
     	}
#elif defined(DRV_UART_VFIFO_V3)
	 if( UART_IsVfifoSetting(port, TXRX_VFIFO) )
      	{
      		DRV_UART_WriteReg32(DMA_VFF_RPT(UARTPort[port].Rx_DMA_Ch), 0);
			DRV_UART_WriteReg32(DMA_VFF_WPT(UARTPort[port].Tx_DMA_Ch), 0);
     	}
#endif //#if defined(DRV_UART_VFIFO_V2)	  
#endif


#if defined(DRV_UART_POWER_ON_BEFORE_ACCESS)
   UART_TurnOnPower(port, KAL_TRUE);
#endif //   #if defined(DRV_UART_POWER_ON_BEFORE_ACCESS)
   MSR = DRV_UART_Reg(UART_MSR(UART_BASE));

   if (MSR & UART_MSR_DSR)
      UARTPort[port].DSR = io_high;
   else
      UARTPort[port].DSR = io_low;
   
#ifdef __DMA_UART_VIRTUAL_FIFO__
   if( UART_IsVfifoSetting(port, TXRX_VFIFO))
   {
      /* Rx FIFO trigger = 1, Tx FIFO trigger is 1, FIFO enable and initialized,and using DMA mode 0.*/
      // while using virtual fifo, dma mode must be set 0!!!
      //DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_VFIFO_DEPTH);
	  UART_FCR_Setting(UART_BASE,UART_VFIFO_DEPTH);	  
   }
   else if( UART_IsVfifoSetting(port, NONE_VFIFO))
   {
      /* Rx FIFO trigger = 62, Tx FIFO trigger is 16, and FIFO enable. */
      //DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_FCR_Normal);
	  UART_FCR_Setting(UART_BASE,UART_FCR_Normal);	
   }   
   else if( UART_IsVfifoSetting(port, RX_VFIFO))
   {
      //DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_FCR_TX_Normal);
       UART_FCR_Setting(UART_BASE,UART_FCR_TX_Normal);
   }
   else // tx vfifo
   {
      //DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_FCR_RX_Normal);
	  UART_FCR_Setting(UART_BASE,UART_FCR_RX_Normal);
   }
#else //#ifdef __DMA_UART_VIRTUAL_FIFO__

   /* Rx FIFO trigger = 62, Tx FIFO trigger is 16, and FIFO enable. */
   //DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_FCR_Normal);
	UART_FCR_Setting(UART_BASE,UART_FCR_Normal);

#endif //__DMA_UART_VIRTUAL_FIFO__
   
   if( UART_IsVfifoSetting(port, TXRX_VFIFO))
   {
#ifdef __DMA_UART_VIRTUAL_FIFO__
      DMA_Stop(UARTPort[port].Rx_DMA_Ch);
      DMA_Stop(UARTPort[port].Tx_DMA_Ch);
#ifdef DRV_UART_FPGA_VFIFO
      if (KAL_TRUE==uart_for_fpga)
      {
         FPGA_DMA_Start(UARTPort[port].Rx_DMA_Ch);
         FPGA_DMA_Start(UARTPort[port].Tx_DMA_Ch);
      }
      else
      {
#endif // #ifdef DRV_UART_FPGA_VFIFO
         DMA_Start(UARTPort[port].Rx_DMA_Ch);
         DMA_Start(UARTPort[port].Tx_DMA_Ch);		
#ifdef DRV_UART_FPGA_VFIFO
      }
#endif // #ifdef DRV_UART_FPGA_VFIFO
	  

      DRV_UART_WriteReg(UART_RXDMA(UART_BASE),UART_TXRXDMA_ON);
      // only turn on receive interrupt
      // toy add UART_IER_ELSI to monitor BT may overrun UART HW FIFO. 
      DRV_UART_WriteReg(UART_IER(UART_BaseAddr[port]),UART_IER_VFIFO | UART_IER_ELSI);
#else //__DMA_UART_VIRTUAL_FIFO__
      ASSERT(0);/*wrong configuration*/
#endif //__DMA_UART_VIRTUAL_FIFO__
   }
   else
   {	
#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
      if(UART_SINGLE_VFIFO_support[port*2])  //only Rx VFIFO
      {
#ifdef __DMA_UART_VIRTUAL_FIFO__
         DMA_Stop(UARTPort[port].Rx_DMA_Ch);
#ifdef DRV_UART_FPGA_VFIFO
         if (KAL_TRUE==uart_for_fpga)
         {
            FPGA_DMA_Start(UARTPort[port].Rx_DMA_Ch);
         }
         else
         {
#endif // #ifdef DRV_UART_FPGA_VFIFO
            DMA_Start(UARTPort[port].Rx_DMA_Ch);
#ifdef DRV_UART_FPGA_VFIFO
         }
#endif // #ifdef DRV_UART_FPGA_VFIFO
         DRV_UART_WriteReg(UART_RXDMA(UART_BASE),UART_TXRXDMA_ON);
         // only turn on receive interrupt
#else //__DMA_UART_VIRTUAL_FIFO__
         ASSERT(0);/*wrong configuration*/
#endif //__DMA_UART_VIRTUAL_FIFO__
      }
      else if(UART_SINGLE_VFIFO_support[port*2 + 1]) // only Tx VFIFO
      {
#ifdef __DMA_UART_VIRTUAL_FIFO__
         DMA_Stop(UARTPort[port].Tx_DMA_Ch);
#ifdef DRV_UART_FPGA_VFIFO
         if (KAL_TRUE==uart_for_fpga)
         {
            FPGA_DMA_Start(UARTPort[port].Tx_DMA_Ch);
         }
         else
         {	
#endif // #ifdef DRV_UART_FPGA_VFIFO
            DMA_Start(UARTPort[port].Tx_DMA_Ch);		
#ifdef DRV_UART_FPGA_VFIFO
         }
#endif // #ifdef DRV_UART_FPGA_VFIFO
#else //__DMA_UART_VIRTUAL_FIFO__
         ASSERT(0);//*wrong configuration
#endif //__DMA_UART_VIRTUAL_FIFO__
      }
#endif  //#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
      if (UARTPort[port].DCB.flowControl == fc_none)
         DRV_UART_WriteReg(UART_IER(UART_BaseAddr[port]),IER_HW_NORMALINTS);
      else
      {
         if (UARTPort[port].DCB.flowControl == fc_hw)
            DRV_UART_WriteReg(UART_IER(UART_BaseAddr[port]),IER_HW_NORMALINTS);
         else
         {
            if (UARTPort[port].DCB.flowControl == fc_sw)
            {
#if defined(DRV_UART_FIFO_FLOW_CONTROL)// need to set EFR enhance before IRE
               DRV_UART_WriteReg(UART_EFR(UART_BASE),  DRV_UART_Reg(UART_EFR(UART_BASE)) | UART_EFR_Enchance);
#endif //#if defined(DRV_UART_FIFO_FLOW_CONTROL)
               DRV_UART_WriteReg(UART_IER(UART_BaseAddr[port]),IER_SW_NORMALINTS);                        
               DRV_UART_WriteReg(UART_ESCAPE_EN(UART_BaseAddr[port]),0x0); //reset to disable first
               if(uart_support_autoescape()==KAL_TRUE)
               {
                  /*For META, Dont use auto escape*/
                  if(kal_query_boot_mode() != FACTORY_BOOT || UARTPort[port].ownerid != MOD_DHL_READER)
                  {
                     /*For AutoEscape*/
                     byte = DRV_UART_Reg(UART_LCR(UART_BASE));
                     // DLAB start */
                     DRV_UART_WriteReg(UART_LCR(UART_BASE),0xbf);            /* Enchance setting */
                     DRV_UART_WriteReg(UART_XON1(UART_BaseAddr[port]),0x11);
                     DRV_UART_WriteReg(UART_XON2(UART_BaseAddr[port]),0x11);
                     DRV_UART_WriteReg(UART_XOFF1(UART_BaseAddr[port]),0x13);
                     DRV_UART_WriteReg(UART_XOFF2(UART_BaseAddr[port]),0x13);
//autoescape
                     DRV_UART_WriteReg(UART_ESCAPE_DAT(UART_BaseAddr[port]),0x77);
                     DRV_UART_WriteReg(UART_ESCAPE_EN(UART_BaseAddr[port]),0x1);
                     DRV_UART_WriteReg(UART_LCR(UART_BASE),byte);            /* Enchance setting */            
                  }
               }              
            }   
         }
      }
   }      
   //#endif //__DMA_UART_VIRTUAL_FIFO__
   /*For excetpion, we dont need to do the following */
#ifdef __MTK_TARGET__
   if(INT_QueryExceptionStatus())
      return KAL_TRUE; 
#endif   
   
#if defined(DRV_UART_FIFO_FLOW_CONTROL)
  // if(UARTPort[port].ownerid == MOD_BT)//BT can not receive flow control, because when BT sleep, it will switch RX as EINT.
   //DRV_UART_WriteReg(UART_SLEEP_EN(UART_BASE),KAL_FALSE);
   ;
#endif   
   /* UARTPort[port].callback = FunCallBack; */
   /* UARTPort[port].initialized = KAL_TRUE; */
   /* initializ our ringbuffer,  */
   send_Rxilm[port] = KAL_TRUE;
//   if (UARTPort[port].hisr == NULL)
   {
      //UARTPort[port].hisr = kal_create_hisr("UARTx_HISR",1,512,UART_HISR[port],NULL);
      UARTPort[port].hisr=(void*)0x1234;
      if(port==uart_port1)
         DRV_Register_HISR(DRV_UART1_HISR_ID,UART_HISR[port]);//add (kal_uint8), avoid Warning 641: Converting enum 'DRV_HISR_ID' to int"
      if(port==uart_port2)
         DRV_Register_HISR(DRV_UART2_HISR_ID,UART_HISR[port]);
      if(port==uart_port3)
         DRV_Register_HISR(DRV_UART3_HISR_ID,UART_HISR[port]);      
   }   
   
   switch(port)
   {
   case uart_port1:
#if defined(DRV_UART1_NORMAL_DMA)
      if( UART_IsVfifoSetting(uart_port1, TX_VFIFO) == KAL_FALSE)
      {
         /*DMA initialize*/
         if (uart1_dmaport == 0)
            uart1_dmaport = DMA_GetChannel(DMA_UART1TX);
         uart1_txmenu.TMOD.burst_mode = KAL_FALSE; // toy modify from 0 to KAL_FALSE, avoid Error 64: Type mismatch (assignment) (int/enum)"
         uart1_txmenu.TMOD.cycle = 0;
         uart1_txmenu.master = DMA_UART1TX;
         uart1_txmenu.addr = NULL;  /*1*/
         uart1_txmenu.WPPT = NULL; /*2*/
         uart1_txmenu.WPTO = NULL;     /*3*/
         
         uart1_input.type = DMA_HWTX_RINGBUFF;
         uart1_input.size = DMA_BYTE;
         uart1_input.menu = &uart1_txmenu;
         uart1_input.count = 0;       /*4*/
         uart1_input.callback = NULL;   /*5*/
      }   
      //#endif //__DMA_UART_VIRTUAL_FIFO__
#endif   /*DRV_UART1_NORMAL_DMA*/
	
      UARTPort[port].UART_id = MOD_UART1_HISR;
	  irq_code = UART_GetIRQCode(uart_port1);
	  IRQ_Register_LISR(irq_code, UART1_LISR,"UART1");
      IRQSensitivity(irq_code,LEVEL_SENSITIVE);
      if (UARTPort[port].power_on == KAL_TRUE)
         IRQUnmask(irq_code);
      break;
   case uart_port2:
#if defined(DRV_UART2_NORMAL_DMA)
      if( UART_IsVfifoSetting(uart_port2, TX_VFIFO) == KAL_FALSE)
      {
         /*DMA initialize*/
         if (uart2_dmaport == 0)
            uart2_dmaport = DMA_GetChannel(DMA_UART2TX);
         uart2_txmenu.TMOD.burst_mode = KAL_FALSE; // toy modify from 0 to KAL_FALSE, avoid Error 64: Type mismatch (assignment) (int/enum)"
         uart2_txmenu.TMOD.cycle = 0;
         uart2_txmenu.master = DMA_UART2TX;
         uart2_txmenu.addr = NULL;  /*1*/
         uart2_txmenu.WPPT = NULL; /*2*/
         uart2_txmenu.WPTO = NULL;     /*3*/
         
         uart2_input.type = DMA_HWTX_RINGBUFF;
         uart2_input.size = DMA_BYTE;
         uart2_input.menu = &uart2_txmenu;
         uart2_input.count = 0;       /*4*/
         uart2_input.callback = NULL;   /*5*/
      }   
      //#endif //__DMA_UART_VIRTUAL_FIFO__
#endif   /*DRV_UART2_NORMAL_DMA*/
      UARTPort[port].UART_id = MOD_UART2_HISR;
	  irq_code = UART_GetIRQCode(uart_port2);
	  IRQ_Register_LISR(irq_code, UART2_LISR,"UART2");
      IRQSensitivity(irq_code,LEVEL_SENSITIVE);
      if (UARTPort[port].power_on == KAL_TRUE)
         IRQUnmask(irq_code);
	  break;
      
#ifdef __UART3_SUPPORT__
   case uart_port3:
    
#if defined(DRV_UART3_NORMAL_DMA)
          if( UART_IsVfifoSetting(uart_port3, TX_VFIFO) == KAL_FALSE)
          {
             /*DMA initialize*/
             if (uart3_dmaport == 0)
                uart3_dmaport = DMA_GetChannel(DMA_UART3TX);
             uart3_txmenu.TMOD.burst_mode = KAL_FALSE; // toy modify from 0 to KAL_FALSE, avoid Error 64: Type mismatch (assignment) (int/enum)"
             uart3_txmenu.TMOD.cycle = 0;
             uart3_txmenu.master = DMA_UART3TX;
             uart3_txmenu.addr = NULL;  /*1*/
             uart3_txmenu.WPPT = NULL; /*2*/
             uart3_txmenu.WPTO = NULL;     /*3*/
             
             uart3_input.type = DMA_HWTX_RINGBUFF;
             uart3_input.size = DMA_BYTE;
             uart3_input.menu = &uart3_txmenu;
             uart3_input.count = 0;       /*4*/
             uart3_input.callback = NULL;   /*5*/
          }   
          //#endif //__DMA_UART_VIRTUAL_FIFO__
#endif   /*DRV_UART3_NORMAL_DMA*/
      UARTPort[port].UART_id = MOD_UART3_HISR;
	  irq_code = UART_GetIRQCode(uart_port3);
      IRQ_Register_LISR(irq_code, UART3_LISR,"UART3");
      IRQSensitivity(irq_code,LEVEL_SENSITIVE);
      if (UARTPort[port].power_on == KAL_TRUE)
         IRQUnmask(irq_code);
      break;
#endif   /*__UART3_SUPPORT__*/
   default:
      ASSERT(0);
      break;
   }
   // enable virtual fifo
   /*for  RX data come when user 's task not ready to get data*/
 #ifdef __DMA_UART_VIRTUAL_FIFO__
      U_ClrRxBuffer(port,ownerid);
      DMA_EnableINT(UARTPort[port].Rx_DMA_Ch); 
 #else
    EnableRxIntr(UART_BaseAddr[port]);
  #endif

   return KAL_TRUE;
}

void UART_FCR_Setting(  kal_uint32 UART_BASE,kal_uint32 u4UART_FCR)
{
	#if defined(DRV_UART_TX_RX_CLEAR_BUG)//for clear Tx  bug
	// because of uart tx clear bug:  maybe send dirty byte when clear tx FIFO,   if close FIFO before clear,that's OK
	   kal_uint32 UART_FCR_close_FIFO;
	kal_uint8 uUART_IER_close_Rx_INT;
	
	// Rx DMA will be hang and issue a uart Rx interrupt when DMA mode to close FIFO
	// So must to close UART Rx interrupt when close FIFO
	 uUART_IER_close_Rx_INT = DRV_UART_Reg8(UART_IER(UART_BASE));
	 DRV_UART_WriteReg8(UART_IER(UART_BASE),uUART_IER_close_Rx_INT & (~UART_IER_ERBFI));
	
	UART_FCR_close_FIFO = u4UART_FCR & (~UART_FCR_FIFOINI);//close FIFO

	 switch(u4UART_FCR & UART_FCR_FIFOINI)
   {
   case UART_FCR_FIFOINI:  	
	DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_FCR_close_FIFO);//close FIFO
	DRV_UART_WriteReg(UART_FCR(UART_BASE),(UART_FCR_close_FIFO|UART_FCR_CLRR|UART_FCR_CLRT));//clear Rx clear Tx
	DRV_UART_WriteReg(UART_FCR(UART_BASE),(UART_FCR_close_FIFO | UART_FCR_FIFOEN) );// open fifo
      break;
   case UART_FCR_CLRT | UART_FCR_FIFOEN: 		
   	DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_FCR_close_FIFO);//close FIFO
	DRV_UART_WriteReg(UART_FCR(UART_BASE),(UART_FCR_close_FIFO|UART_FCR_CLRT));// clear Tx
	DRV_UART_WriteReg(UART_FCR(UART_BASE),(UART_FCR_close_FIFO | UART_FCR_FIFOEN) );// open fifo
      break;
   case UART_FCR_CLRR | UART_FCR_FIFOEN:   
   	DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_FCR_close_FIFO);//close FIFO
	DRV_UART_WriteReg(UART_FCR(UART_BASE),(UART_FCR_close_FIFO|UART_FCR_CLRR));//clear Rx
	DRV_UART_WriteReg(UART_FCR(UART_BASE),(UART_FCR_close_FIFO | UART_FCR_FIFOEN) );// open fifo
      break; 
   case  UART_FCR_FIFOEN:  
	DRV_UART_WriteReg(UART_FCR(UART_BASE),u4UART_FCR);
	break; 
   default:
   	DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_FCR_close_FIFO);//close FIFO
     DRV_UART_WriteReg(UART_FCR(UART_BASE),u4UART_FCR);
      break;
   }
   
   	// Rx DMA will be hang and issue a uart Rx interrupt when DMA mode to close FIFO
	// So must to close UART Rx interrupt when close FIFO
   DRV_UART_WriteReg8(UART_IER(UART_BASE),uUART_IER_close_Rx_INT );
   
	 #else//DRV_UART_TX_RX_CLEAR_BUG
	 DRV_UART_WriteReg(UART_FCR(UART_BASE),u4UART_FCR);
	 #endif//DRV_UART_TX_RX_CLEAR_BUG
		
}

void U_Purge(UART_PORT port, UART_buffer dir, module_type ownerid)
{
   kal_uint32 UART_BASE;


   UART_BASE = UART_BaseAddr[port];
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
    
   if (dir == RX_BUF)
	 UART_FCR_Setting(UART_BASE,(UART_FCR_Normal & ~UART_FCR_CLRT));
   else
	 UART_FCR_Setting(UART_BASE,(UART_FCR_Normal & ~UART_FCR_CLRR));    
}
void U_Close(UART_PORT port, module_type ownerid)
{
   kal_uint32 UART_BASE;
   	kal_uint8 irq_code;
   //kal_uint8 itmp; //avoid Warning 534: Ignoring return value of function 'GPTI_ReleaseHandle"

   UART_BASE = UART_BaseAddr[port];
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   UARTPort[port].initialized = KAL_FALSE;
   UARTPort[port].ownerid = (module_type)((kal_uint16)MOD_UART1_HISR+(kal_uint8)port); //toy add cast to avoid Lint error 58, 64
   
   switch(port)
   {
   case uart_port1:   		
   		irq_code = UART_GetIRQCode(uart_port1);		
		IRQMask(irq_code);
      break;
   case uart_port2: 		
   		irq_code = UART_GetIRQCode(uart_port2);
		IRQMask(irq_code);
      break;
#ifdef __UART3_SUPPORT__
   case uart_port3:     
	  irq_code = UART_GetIRQCode(uart_port3);
	  IRQMask(irq_code);      
      break;
#endif   /*__UART3_SUPPORT__*/
   default:
      ASSERT(0);
      break;
   }

	DRV_UART_WriteReg(UART_IER(UART_BASE),UART_IER_ALLOFF);
#ifdef __DMA_UART_VIRTUAL_FIFO__	
#if defined(DRV_UART_VFIFO_V2)	
	DRV_UART_WriteReg(UART_RXDMA(UART_BASE),UART_TXRXDMA_OFF);
	if( UART_IsVfifoSetting(port, RX_VFIFO) )
	{	
		DMA_Flush(UARTPort[port].Rx_DMA_Ch);
		while (DRV_UART_Reg32(DMA_FLUSH(UARTPort[port].Rx_DMA_Ch))!=0);
	}
#elif defined(DRV_UART_VFIFO_V3)
DRV_UART_WriteReg(UART_RXDMA(UART_BASE),UART_TXRXDMA_OFF);
	if( UART_IsVfifoSetting(port, TXRX_VFIFO) )
	{	
		DMA_Flush(UARTPort[port].Rx_DMA_Ch);
	//	Data_Sync_Barrier();
	//	while (DRV_UART_Reg32(DMA_FLUSH(UARTPort[port].Rx_DMA_Ch))!=0);
		
		DMA_Flush(UARTPort[port].Tx_DMA_Ch);
	//	Data_Sync_Barrier();
	//	while (DRV_UART_Reg32(DMA_FLUSH(UARTPort[port].Tx_DMA_Ch))!=0);
		
	}
#endif //#if defined(DRV_UART_VFIFO_V2)
#endif

	U_ConfigEscape(port, 0xff, 0, UARTPort[port].ownerid);
	U_ClrRxBuffer(port, UARTPort[port].ownerid);  /*clear sw RX buffer*/
	U_ClrTxBuffer(port, UARTPort[port].ownerid);  /*clear sw TX buffer*/
	U_Purge(port, RX_BUF, UARTPort[port].ownerid);/*clear sw RX FIFO*/
	U_Purge(port, TX_BUF, UARTPort[port].ownerid);/*clear sw TX FIFO*/
 
#ifdef __DMA_UART_VIRTUAL_FIFO__
   if( UART_IsVfifoSetting(port, RX_VFIFO) )
   {
      DMA_Stop(UARTPort[port].Rx_DMA_Ch);
      DRV_UART_WriteReg(UART_RXDMA(UART_BASE),UART_TXRXDMA_OFF);
   }	
   if( UART_IsVfifoSetting(port, TX_VFIFO) )
   {
      DMA_Stop(UARTPort[port].Tx_DMA_Ch);
   }
#endif

   DRV_UART_WriteReg(UART_IER(UART_BASE),UART_IER_ALLOFF);
   
   
   if (UARTPort[port].handle != 0xFF)
   	{
      //GPTI_ReleaseHandle(&(UARTPort[port].handle));
      DclSGPT_Close(&(UARTPort[port].handle));
      UARTPort[port].handle = 0xFF;
   }
   
}

//void U_SetOwner (UART_PORT port, kal_uint8 ownerid)
void U_SetOwner (UART_PORT port, module_type ownerid)
{
   //abnormal usage for kal_prompt_trace cause un-necessary RO-CODE & RO-DATA size.
   //#ifndef __PRODUCTION_RELEASE__
   //kal_prompt_trace(MOD_UART1_HISR,"port: %d, ownerid: %d", port, ownerid);
   //#endif   
   UARTPort[port].ownerid = ownerid;
}

module_type U_GetOwnerID(UART_PORT port)
{
   return UARTPort[port].ownerid;
}

void U_ConfigEscape (UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid)
{
   //kal_uint8 itmp; //avoid Warning 534: Ignoring return value of function 'GPTI_GetHandle"
   //kal_bool btmp; //avoid Warning 534: Ignoring return value of function 'GPTI_StartItem"
   SGPT_CTRL_START_T start;

   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   UARTPort[port].ESCDet.EscChar = EscChar;
   UARTPort[port].ESCDet.GuardTime = ESCGuardtime;
   if (UARTPort[port].ESCDet.GuardTime)
   {
      
      if (UARTPort[port].handle == 0xFF)
	  {
         // /*lint -e(534)*/GPTI_GetHandle(&UARTPort[port].handle);
         UARTPort[port].handle = DclSGPT_Open(DCL_GPT_CB, 0);
      }
      
      UARTPort[port].Rec_state = UART_RecNormal;

	 /*
      GPTI_StartItem(UARTPort[port].handle,
         (UARTPort[port].ESCDet.GuardTime/10),
         UART_Calback,
         &UARTPort[port]);*/
   
	start.u2Tick=UARTPort[port].ESCDet.GuardTime/10;
	start.pfCallback=UART_Calback;
	start.vPara=&UARTPort[port];
	DclSGPT_Control(UARTPort[port].handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);  
	
   }
}

void U_SetFlowCtrl(UART_PORT port, kal_bool XON, module_type ownerid)    {}   /*NULL for all*/
void U_CtrlDCD(UART_PORT port, IO_level SDCD, module_type ownerid)   {}   /*NULL for DCE*/
void U_CtrlRI (UART_PORT port, IO_level SRI, module_type ownerid)    {}   /*NULL for DCE*/
void U_CtrlDTR (UART_PORT port, IO_level SDTR, module_type ownerid)
{
   kal_uint32 UART_BASE;

   UART_BASE = UART_BaseAddr[port];
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   if (SDTR)
   {
      DRV_UART_SetBits(UART_MCR(UART_BASE), UART_MCR_DTR);
   }
   else
   {
      DRV_UART_ClearBits(UART_MCR(UART_BASE), UART_MCR_DTR);
   }
      //DRV_UART_Reg(UART_MCR(UART_BASE)) |= UART_MCR_DTR;
      //DRV_UART_Reg(UART_MCR(UART_BASE)) &= ~UART_MCR_DTR;
}
void U_ReadHWStatus(UART_PORT port, IO_level *SDSR, IO_level *SCTS)
{
   kal_uint16 MSR;
   kal_uint32 UART_BASE;

   UART_BASE = UART_BaseAddr[port];
   MSR = DRV_UART_Reg(UART_MSR(UART_BASE));
   *SDSR = (IO_level)(( MSR & UART_MSR_DSR) >> 5);
   *SCTS = (IO_level)(( MSR & UART_MSR_CTS) >> 4);
}

void U_CtrlBreak(UART_PORT port, IO_level SBREAK, module_type ownerid)
{
   kal_uint32 UART_BASE;

   UART_BASE = UART_BaseAddr[port];
   if (SBREAK == io_high)
   {
      DRV_UART_SetBits(UART_LCR(UART_BASE), UART_LCR_BREAK);
   }
   else
   {
      DRV_UART_ClearBits(UART_LCR(UART_BASE), UART_LCR_BREAK);
   }
      //DRV_UART_Reg(UART_LCR(UART_BASE)) |= UART_LCR_BREAK;
      //DRV_UART_Reg(UART_LCR(UART_BASE)) &= ~UART_LCR_BREAK;
}

kal_uint16 U_GetBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{
   kal_uint16  real_count,index;
   kal_uint16   data_count=0;

   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32)port, (kal_uint32)ownerid,  (kal_uint32)UARTPort[port].ownerid);
   
   if (status != NULL)
      *status = 0;
   
   DisableRxIntr(UART_BaseAddr[port]);
   if (status != NULL)
   {
      if (UARTPort[port].EscFound)
      {
         *status |= UART_STAT_EscDet;
         UARTPort[port].EscFound = KAL_FALSE;
      }
      if (UARTPort[port].breakDet)
      {
         *status |= UART_STAT_Break;
         UARTPort[port].breakDet = KAL_FALSE;
      }
   }
   
   EnableRxIntr(UART_BaseAddr[port]);
   do
   {
      Buf_GetBytesAvail(&(UARTPort[port].Rx_Buffer),real_count);
      
      if( (kal_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw && UARTPort[port].ownerid==MOD_DHL_READER)||
         (uart_support_autoescape()==KAL_FALSE&& UARTPort[port].DCB.flowControl==fc_sw ))
      {  
         for (index = 0; (index < real_count)&& (data_count<Length) ; index++)
         {
            Buf_Pop(&(UARTPort[port].Rx_Buffer),*(Buffaddr+data_count));           
            /*The following are for software flow control*/
            if(uart_escape_state==0)
            {
               if(*(Buffaddr+data_count)==0x77)
               {
                  uart_escape_state=0x77;               
               }   
               else   
               {
                  data_count++;
               }   
            }  
            else if (uart_escape_state==0x77)
            {
               switch(*(Buffaddr+data_count))
               {
               case 0x01:
                  *(Buffaddr+data_count)=UARTPort[port].DCB.xonChar;
                  data_count++;
                  break;
               case 0x02:                  
                  *(Buffaddr+data_count)=UARTPort[port].DCB.xoffChar; 
                  data_count++;                 
                  break;               
               case 0x03:                  
                  *(Buffaddr+data_count)=0x77;
                  data_count++;
                  break;      
               default:                  
                  break;      
               }                         
               uart_escape_state=0x0;        
            }                          
         }   
      }
      else/*HW flow control*/
      {
         for (index = 0; (index < real_count)&& (data_count<Length) ; index++)
         {
            Buf_Pop(&(UARTPort[port].Rx_Buffer),*(Buffaddr+data_count));                             
            data_count++;
         }   
      }   
      //}      
      /*satisfy uart owner request, so break*/
      if (data_count == Length) break;            
      /* disable interrupt*/
      DisableRxIntr(UART_BaseAddr[port]);
      Buf_GetBytesAvail(&(UARTPort[port].Rx_Buffer),real_count);
      
      /*there is no data in ringbuffer, so break*/       
      if (real_count==0)
      {
         send_Rxilm[port] = KAL_TRUE;  
         EnableRxIntr(UART_BaseAddr[port]); 
         /* enable interrupt*/
         break;
      }
      EnableRxIntr(UART_BaseAddr[port]);
      /* enable interrupt*/
   }while(KAL_TRUE);        
   
   return data_count;
}

#ifdef DRV_DEBUG
kal_uint16 BMT_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length)
{
   kal_uint16  real_count,index;
   if(port >= MAX_UART_PORT_NUM)
      return 0;
#if !defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
   if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
   {     
      UART_PDN_Disable(port);
   }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
   Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer),real_count);
   if (real_count > Length)
   {
      real_count = Length;
   }
   else
   {
      send_Txilm[port] = KAL_TRUE;
   }
   
   for (index = 0; index < real_count; index++)
   {
      Buf_Push(&(UARTPort[port].Tx_Buffer),*(Buffaddr+index));
   }
   
   switch(port)
   {
   case uart_port1:

#if defined(DRV_UART1_NO_DMA)	
      EnableTxIntr(UART_BaseAddr[port]);
#endif   /*(DRV_UART1_NO_DMA)*/

#if defined(DRV_UART1_NORMAL_DMA)
      if ((DMA_CheckITStat(uart1_dmaport))||(DMA_CheckRunStat(uart1_dmaport)))
      {
         ;
      }
      else
      {
      EnableTxIntr(UART_BaseAddr[port]);
      }

#endif   /*DRV_UART1_NORMAL_DMA*/
	  
      break;
   case uart_port2:
#if defined(DRV_UART2_NO_DMA) || defined(FPGA)
      EnableTxIntr(UART_BaseAddr[port]);
#endif   /*(DRV_UART2_NO_DMA,FPGA)*/
      
#if defined(DRV_UART2_NORMAL_DMA)
      if ((DMA_CheckITStat(uart2_dmaport))||(DMA_CheckRunStat(uart2_dmaport)))
      {
         ;
      }
      else
      {
         EnableTxIntr(UART_BaseAddr[port]);
      }
#endif   /*DRV_UART2_NORMAL_DMA*/
      break;
#ifdef __UART3_SUPPORT__
   case uart_port3:
      #if defined(DRV_UART3_NO_DMA)	
      EnableTxIntr(UART_BaseAddr[port]);
#endif   /*(DRV_UART3_NO_DMA)*/

#if defined(DRV_UART3_NORMAL_DMA)
      if ((DMA_CheckITStat(uart3_dmaport))||(DMA_CheckRunStat(uart3_dmaport)))
      {
         ;
      }
      else
      {
      EnableTxIntr(UART_BaseAddr[port]);
      }

#endif   /*DRV_UART3_NORMAL_DMA*/
	  
      break;
#endif   /*__UART3_SUPPORT__*/
   default:
      ASSERT(0);
      break;
   }
   
   return real_count;
}
#endif   /*DRV_DEBUG*/

/*************************************************************************
   * FUNCTION                                                            
   *	UART_GetTxWorkingMode
   *
   * DESCRIPTION                                                           
   *	
   *	This function is to get the uart TX working mode.
   *
   * PARAMETERS
   *  port        - the uart port
   *
   *  RETURNS
   *  UART_ON_VFIFO: the uart port Tx working on VFIFO mode
   *  UART_ON_DMA: the uart port Tx working on normal DMA mode
   *  UART_ON_MCU: the uart port Tx working on sw mode 
   *
   * Global AFFECTED
   *
   *************************************************************************/
UART_WORKING_MODE UART_GetTxWorkingMode(UART_PORT port)
{
 if(UART_IsVfifoSetting(port, TX_VFIFO))
   return UART_ON_VFIFO;
 
#ifdef __UART3_SUPPORT__
 if(port == uart_port3)
 {
#if defined(DRV_UART3_NO_DMA)
   return UART_ON_MCU;
#elif defined(DRV_UART3_NORMAL_DMA)
   return UART_ON_DMA;
#endif//#if defined(DRV_UART3_NO_DMA)
 }
#endif
 
#if defined(DRV_UART1_NO_DMA) || defined(DRV_UART2_NO_DMA)
	 return UART_ON_MCU;
#elif defined(DRV_UART1_NORMAL_DMA) || defined(DRV_UART2_NORMAL_DMA)
	 return UART_ON_DMA;
#else
    return UART_ON_UNKNOWN;
#endif
 
 
}


kal_uint16 U_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid )
{
#ifndef DRV_DEBUG
   kal_uint16  real_count;
   kal_uint32  savedMask;
#if !defined(DRV_UART_MCU_MULTI_POP_PUSH)
   kal_uint16  index;
#endif


 if((kal_query_boot_mode()== FACTORY_BOOT))
 	{
	kal_uint8 escape_char=0x77;
    kal_uint8 mode=0x1;

 real_count=U_SendData(port, Buffaddr,  Length, mode,escape_char,  ownerid);

	return real_count;
 	}
  
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid,  (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
   if((UARTPort[port].EnableTX == KAL_FALSE) || (UARTPort[port].power_on == KAL_FALSE))
   {
      return Length;
   }
#if !defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
   if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
   {
      UART_PDN_Disable(port);
   }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
   savedMask = SaveAndSetIRQMask();
   Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer),real_count);
   if (real_count >= Length)
   {
      real_count = Length;
   }
else if(( (real_count < (UARTPort[port].Tx_Buffer.Length >> 5)) || (real_count < 100)) && (UART_IsVfifoSetting(port, TX_VFIFO) == KAL_FALSE) )  //when buffer < 1/8, let owner wait for a while
   {
     UART_WORKING_MODE mode;
     mode = UART_GetTxWorkingMode( port);
     if(UART_ON_DMA == mode)
        {
             send_Txilm[port] = KAL_TRUE;
        }
     else if (UART_ON_MCU == mode)
        {
            WaitForUARTTx[port] = KAL_TRUE;
        }
   }
   else
   {
      send_Txilm[port] = KAL_TRUE;
   }
   RestoreIRQMask(savedMask);
   
#if defined(DRV_UART_MCU_MULTI_POP_PUSH)
   Buf_Push_Multi(&(UARTPort[port].Tx_Buffer), Buffaddr, real_count, 0);
#else
   for (index = 0; index < real_count; index++)
   {
      Buf_Push(&(UARTPort[port].Tx_Buffer),*(Buffaddr+index));
   }
#endif//DRV_UART_MCU_MULTI_POP_PUSH
   switch(port)
   {
   case uart_port1:
#if defined(DRV_UART1_NORMAL_DMA)
      savedMask = SaveAndSetIRQMask();
      if (UART1_Intr_is_Running == KAL_TRUE)
      {
         ;
      }
      else
      {
         EnableTxIntr(UART_BaseAddr[port]);
      }
      RestoreIRQMask(savedMask);
#endif   /*DRV_UART1_NORMAL_DMA*/

#if defined(DRV_UART1_NO_DMA) 
      EnableTxIntr(UART_BaseAddr[port]);
#endif   /*DRV_UART2_NO_DMA*/
	
      break;
   case uart_port2:
#if defined(DRV_UART2_NORMAL_DMA)
      savedMask = SaveAndSetIRQMask();
      if (UART2_Intr_is_Running == KAL_TRUE)
      {
         ;
      }
      else
      {
         EnableTxIntr(UART_BaseAddr[port]);
      }
      RestoreIRQMask(savedMask);
#endif   /*DRV_UART2_NORMAL_DMA*/
#if defined(DRV_UART2_NO_DMA) || defined(FPGA)
      EnableTxIntr(UART_BaseAddr[port]);
#endif   /*(DRV_UART2_NO_DMA,FPGA)*/
      break;
#ifdef __UART3_SUPPORT__
   case uart_port3:
      #if defined(DRV_UART3_NORMAL_DMA)
      savedMask = SaveAndSetIRQMask();
      if (UART3_Intr_is_Running == KAL_TRUE)
      {
         ;
      }
      else
      {
      EnableTxIntr(UART_BaseAddr[port]);
      }
      RestoreIRQMask(savedMask);
#endif   /*DRV_UART3_NORMAL_DMA*/

#if defined(DRV_UART3_NO_DMA) 
      EnableTxIntr(UART_BaseAddr[port]);
#endif   /*DRV_UART3_NO_DMA*/
	
      break;
#endif   /*__UART3_SUPPORT__*/
   default:
      ASSERT(0);
      break;
   }
   return real_count;
#else /*DRV_DEBUG*/
   return Length;
#endif /*DRV_DEBUG*/
}

#ifndef __ROMSA_SUPPORT__ /* Note: for ROM code */

kal_uint16 U_PutISRBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
#ifndef DRV_DEBUG
   kal_uint16  real_count;
#if !defined(DRV_UART_MCU_MULTI_POP_PUSH)
   kal_uint16  index;
#endif
   
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
   if (UARTPort[port].power_on == KAL_FALSE)
      return Length;
#if !defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
   if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
   {   
      UART_PDN_Disable(port);
   }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
   if(UARTPort[port].EnableTX == KAL_FALSE)
   {
      return Length;
   }
   
   Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer_ISR),real_count);
   if (real_count > Length)
   {
      real_count = Length;
   }
#if defined(DRV_UART_MCU_MULTI_POP_PUSH)
   Buf_Push_Multi(&(UARTPort[port].Tx_Buffer_ISR), Buffaddr, real_count, 0);
#else
   for (index = 0; index < real_count; index++)
   {
      Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),*(Buffaddr+index));
   }
#endif//DRV_UART_MCU_MULTI_POP_PUSH
   switch(port)
   {
   case uart_port1:
#if defined(DRV_UART1_NORMAL_DMA)
      if (UART1_Intr_is_Running == KAL_TRUE)
      {
         ;
      }
      else
      {
      EnableTxIntr(UART_BaseAddr[port]);
      }
#endif   /*DRV_UART1_NORMAL_DMA*/   

#if defined(DRV_UART1_NO_DMA)
	     EnableTxIntr(UART_BaseAddr[port]);
#endif   /*DRV_UART1_NO_DMA*/   	

      break;
   case uart_port2:      
#if defined(DRV_UART2_NO_DMA) || defined(FPGA)
      EnableTxIntr(UART_BaseAddr[port]);
#endif   /*(DRV_UART2_NO_DMA,FPGA)*/
      
#if defined(DRV_UART2_NORMAL_DMA)
      if (UART2_Intr_is_Running == KAL_TRUE)
      {
         ;
      }
      else
      {
         EnableTxIntr(UART_BaseAddr[port]);
      }
#endif   /*DRV_UART2_NORMAL_DMA*/
      break;
#ifdef __UART3_SUPPORT__
   case uart_port3:
      
#if defined(DRV_UART3_NORMAL_DMA)
            if (UART3_Intr_is_Running == KAL_TRUE)
            {
               ;
            }
            else
            {
      EnableTxIntr(UART_BaseAddr[port]);
            }
#endif   /*DRV_UART3_NORMAL_DMA*/   
      
#if defined(DRV_UART3_NO_DMA)
               EnableTxIntr(UART_BaseAddr[port]);
#endif   /*DRV_UART3_NO_DMA*/   	
      break;
#endif   /*__UART3_SUPPORT__*/
   default:
      ASSERT(0);
      break;
   }
   return real_count;
#else /*DRV_DEBUG*/
   return Length;
#endif /*DRV_DEBUG*/
}
#endif /* Note: for ROM code */

kal_uint16 U_SendISRData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode, kal_uint8 escape_char, module_type ownerid)
{
#ifndef DRV_DEBUG
   kal_uint32  real_count,index, data_count=0;
   kal_uint8 data;
   
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);            
   if (UARTPort[port].power_on == KAL_FALSE)
      return Length;
   if( (kal_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw && UARTPort[port].ownerid==MOD_DHL_READER)||
      (uart_support_autoescape()==KAL_FALSE) )
   {
      if (mode == 0)
      {
         real_count = U_PutISRBytes(port,Buffaddr,Length,ownerid);
      }
      else
      {
#if !defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
         if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
         {     
            UART_PDN_Disable(port);
         }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
         /*TY modify this to solve overrun issue 20041006*/    
         Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer_ISR),real_count);           
         for (index = 0; (index < (real_count-1))&&(data_count<Length); index++)
         {
            data_count++;
            data = *(Buffaddr+index);
            if (data == UARTPort[port].DCB.xonChar)
            {
               Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),escape_char);
               Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),0x01);
               real_count--;
               
            }
            else if (data == UARTPort[port].DCB.xoffChar)
            {
               Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),escape_char);
               Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),0x02);
               real_count--;
            }
            else if (data == escape_char)
            {
               Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),escape_char);
               Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),0x03);
               real_count--;
            }
            else
            {
               Buf_Push(&(UARTPort[port].Tx_Buffer_ISR),*(Buffaddr+index));
               
            }
         }
         
         real_count = index;
         
         switch(port)
         {
         case uart_port1:
#if defined(DRV_UART1_NORMAL_DMA)
            if (UART1_Intr_is_Running == KAL_TRUE)
            {
               ;
            }
            else
            {
            EnableTxIntr(UART_BaseAddr[port]);
            }
#endif   /*DRV_UART1_NORMAL_DMA*/	

#if defined(DRV_UART1_NO_DMA)
		 EnableTxIntr(UART_BaseAddr[port]);
#endif   /*DRV_UART1_NO_DMA*/		 	

            break;
         case uart_port2:
#if defined(DRV_UART2_NO_DMA) || defined(FPGA)
            EnableTxIntr(UART_BaseAddr[port]);
#endif   /*(DRV_UART2_NO_DMA,FPGA)*/
            
#if defined(DRV_UART2_NORMAL_DMA)
            if (UART2_Intr_is_Running == KAL_TRUE)
            {
               ;
            }
            else
            {
               EnableTxIntr(UART_BaseAddr[port]);
            }
#endif   /*DRV_UART2_NORMAL_DMA*/
            break;
#ifdef __UART3_SUPPORT__
         case uart_port3:
#if defined(DRV_UART3_NORMAL_DMA)
            if (UART3_Intr_is_Running == KAL_TRUE)
            {
               ;
            }
            else
            {
            EnableTxIntr(UART_BaseAddr[port]);
            }
#endif   /*DRV_UART3_NORMAL_DMA*/	

#if defined(DRV_UART3_NO_DMA)
		 EnableTxIntr(UART_BaseAddr[port]);
#endif   /*DRV_UART3_NO_DMA*/
            break;
#endif   /*__UART3_SUPPORT__*/
         default:
            ASSERT(0);
            break;
         }
      }
  	   }
  	   else
  	   {
         real_count = U_PutISRBytes(port,Buffaddr,Length,ownerid);
      }
      
      return real_count;
#else
      return Length;
#endif
}



kal_uint16 U_SendData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid)
{
#ifndef DRV_DEBUG
   kal_uint32   real_count,index, data_count=0;
   kal_uint8   data;
#if defined(DRV_UART1_NORMAL_DMA)||defined(DRV_UART2_NORMAL_DMA)||defined(DRV_UART3_NORMAL_DMA)||defined(DRV_UART2_OLD_DMA)
   kal_uint32  savedMask;
#endif
   
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);        
   if (UARTPort[port].power_on == KAL_FALSE)
      return Length;
   
   if( (kal_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw && UARTPort[port].ownerid==MOD_DHL_READER)||
      (uart_support_autoescape()==KAL_FALSE) )     
   {
      if(mode == 0)
         ASSERT(0);//real_count = U_PutBytes(port, Buffaddr,Length,ownerid);       
      else
      {
#if !defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
         if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
         {     
            UART_PDN_Disable(port);            
         }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
         Buf_GetRoomLeft(&(UARTPort[port].Tx_Buffer),real_count);
         /*TY modify this to solve overrun issue 20041006*/      
         for (index = 0;( index < (real_count-1) )&& (data_count <Length); index++)
         {
            data_count++;
            data = *(Buffaddr+index);
            
            if (data == UARTPort[port].DCB.xonChar)
            {
               Buf_Push(&(UARTPort[port].Tx_Buffer),escape_char);
               Buf_Push(&(UARTPort[port].Tx_Buffer),0x01);
               real_count--;         
            }
            else if (data == UARTPort[port].DCB.xoffChar)
            {
               Buf_Push(&(UARTPort[port].Tx_Buffer),escape_char);
               Buf_Push(&(UARTPort[port].Tx_Buffer),0x02);
               real_count--;
            }
            else if (data == escape_char)
            {
               Buf_Push(&(UARTPort[port].Tx_Buffer),escape_char);
               Buf_Push(&(UARTPort[port].Tx_Buffer),0x03);            
               real_count--;
            }
            else
            {
               Buf_Push(&(UARTPort[port].Tx_Buffer),data);
            }        
         }
         
         real_count = index;
         if (real_count != Length)
         {
            send_Txilm[port] = KAL_TRUE;
         }      
         switch(port)
         {
         case uart_port1:
#if defined(DRV_UART1_NORMAL_DMA)
            savedMask = SaveAndSetIRQMask();
            if ((DMA_CheckITStat(uart1_dmaport))||(DMA_CheckRunStat(uart1_dmaport)))
            {
               ;
            }
            else
            {
               EnableTxIntr(UART_BaseAddr[port]);
            }
            RestoreIRQMask(savedMask);
#endif   /*DRV_UART1_NORMAL_DMA*/

#if defined(DRV_UART1_NO_DMA) 
            EnableTxIntr(UART_BaseAddr[port]);
#endif   /*DRV_UART1_NO_DMA*/
            break;
         case uart_port2:
#if defined(DRV_UART2_NORMAL_DMA)
            savedMask = SaveAndSetIRQMask();
            if ((DMA_CheckITStat(uart2_dmaport))||(DMA_CheckRunStat(uart2_dmaport)))
            {
               ;
            }
            else
            {
               EnableTxIntr(UART_BaseAddr[port]);
            }
            RestoreIRQMask(savedMask);
#endif   /*DRV_UART2_NORMAL_DMA*/
#if defined(DRV_UART2_NO_DMA) || defined(FPGA)
            EnableTxIntr(UART_BaseAddr[port]);
#endif   /*(DRV_UART2_NO_DMA,FPGA)*/
            break;
#ifdef __UART3_SUPPORT__
         case uart_port3:
            #if defined(DRV_UART3_NORMAL_DMA)
            savedMask = SaveAndSetIRQMask();
            if ((DMA_CheckITStat(uart3_dmaport))||(DMA_CheckRunStat(uart3_dmaport)))
            {
               ;
            }
            else
            {
            EnableTxIntr(UART_BaseAddr[port]);
            }
            RestoreIRQMask(savedMask);
#endif   /*DRV_UART3_NORMAL_DMA*/

#if defined(DRV_UART3_NO_DMA) 
            EnableTxIntr(UART_BaseAddr[port]);
#endif   /*DRV_UART1_NO_DMA*/
            break;
#endif   /*__UART3_SUPPORT__*/
         default:
            ASSERT(0);
            break;
         }
      }
  	}
  	else
  	{
      ASSERT(0);//real_count = U_PutBytes(port, Buffaddr,Length,ownerid); 
   }    
   return real_count;
#else
   return Length;
#endif
}
//============================== ISR level ====================
/*============================ UART1 ========================*/
void UART_RLSHandler(void *parameter)
{
   kal_uint16 LSR;
   UARTStruct *UARTData=(UARTStruct *)parameter;
   kal_uint32 UART_BASE;
   if(UARTData->port_no >= MAX_UART_PORT_NUM)
      return;
   
   UART_BASE = UART_BaseAddr[UARTData->port_no];
   LSR = DRV_UART_Reg(UART_LSR(UART_BASE));
   if (LSR & UART_LSR_BI)
   {
      UARTData->breakDet = KAL_TRUE;
      U_Purge(UARTData->port_no,RX_BUF,UARTPort[UARTData->port_no].ownerid);
   }
   
   if ((LSR & UART_LSR_OE) ||
      (LSR & UART_LSR_FIFOERR))
   {
   	  //toy add, for check BT overwrite UART FIFO, because BT do not use flow control, lost data will cause BT fail
   	  //if((UARTPort[UARTData->port_no].ownerid == MOD_BT))
       // {
       //    UART_DBG(__LINE__, UART_GetTimeStamp(), ust_get_current_time(), LSR);
        //   ASSERT(!(LSR & UART_LSR_OE)); // BT send too fast, VFIFO can not get bus, overwrite UART FIFO
       // }   	   
        DisableRLSIntr(UART_BASE);
   }
}

void UART_Calback(void *parameter)
{
   UARTStruct *UARTData=(UARTStruct *)parameter;
 //  GPTI_StopItem(UARTData->handle);
 DclSGPT_Control(UARTData->handle,SGPT_CMD_STOP,0);
 
   switch(UARTData->Rec_state)
   {
   case UART_Get3EscChar:
      UARTData->EscFound = KAL_TRUE;
      UARTData->Rec_state = UART_RecNormal;
      UARTData->EscCount = 0;
      UART_sendilm(UARTData->port_no, MSG_ID_UART_ESCAPE_DETECTED_IND);
      break;
   case UART_RecNormal:
      UARTData->Rec_state = UART_StartCheckESC;
      UARTData->EscCount = 0;
      break;
      
   case UART_StartCheckESC:
      UARTData->Rec_state = UART_RecNormal;
      UARTData->EscCount = 0;
      break;
   default: //toy add for avoid lint info.
      break;
   }
}

#ifdef DRV_UART_COMPENSATE_AT

//Use GPT timer to polling data ready after set autobaud
void UART_CheckAT_Callback(void *parameter)
{
   UARTStruct *UARTData=(UARTStruct *)parameter;
   kal_uint32 UART_BASE;
   kal_uint16 LSR;
   SGPT_CTRL_START_T start;
 //  kal_bool   btmp; //avoid Warning 534: Ignoring return value of function 'GPTI_StartItem"
   if(UARTData->port_no >= MAX_UART_PORT_NUM)
      return;
      
   UART_BASE = UART_BaseAddr[UARTData->port_no];
  // GPTI_StopItem(UARTData->handle);
  DclSGPT_Control(UARTData->handle,SGPT_CMD_STOP,0);

   LSR = DRV_UART_Reg(UART_LSR(UART_BASE));
   if (LSR & UART_LSR_DR)
   {
#ifdef DCM_ENABLE
      UART_SetRateFix(UARTData->port_no); //work around for autobaud need fix rate.
#endif      
      //work around for autobaud can not put complete 'AT' in rx FIFO
      //this is come from MT6253 hopping impact,
      UART_CompensateAT(UARTData->port_no);
   }
   else
   {
      // polling data ready after set autobaud
    //  btmp = GPTI_StartItem(UARTData->handle,
/*
    GPTI_StartItem(UARTData->handle,
                         10,
                         UART_CheckAT_Callback,
                         &UARTData->port_no);
*/
		   start.u2Tick=10;
		  start.pfCallback=UART_CheckAT_Callback;
		  start.vPara=&UARTData->port_no;
		  DclSGPT_Control(UARTData->handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);  

   }
}

//Work around for autobaud which can not put complete 'AT' in rx FIFO
//This is due to MT6253 hopping impact,
void UART_CompensateAT(UART_PORT  port)
{
   kal_uint32 UART_BASE;
   kal_uint8  ch;
   kal_uint8  cRXChar;
   if(port >= MAX_UART_PORT_NUM)
      return;

   UART_BASE = UART_BaseAddr[port];
   ch = UARTPort[port].Rx_DMA_Ch;
   cRXChar = (kal_uint8)DRV_UART_Reg(UART_RBR(UART_BASE));
   if( (cRXChar == 'A') || (cRXChar == 'T'))
   { UARTPort[port].CompensateAT = Compensate_AT; }
   else if( (cRXChar == 'a') || (cRXChar == 't'))
   { UARTPort[port].CompensateAT = Compensate_at; }
   else //error handling, it should never happen.
   { // restart autobaud again.
      U_SetBaudRate(port, UART_BAUD_AUTO, UARTPort[port].ownerid);
      return;      
   }

#ifdef __DMA_UART_VIRTUAL_FIFO__
   if( UART_IsVfifoSetting(port, TXRX_VFIFO))
   {
      /* Rx FIFO trigger = 1, Tx FIFO trigger is 1, FIFO enable and initialized,and using DMA mode 0.*/
      // while using virtual fifo, dma mode must be set 0!!!
      //DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_VFIFO_DEPTH);
	   UART_FCR_Setting(UART_BASE,UART_VFIFO_DEPTH);	 
   }
   else if( UART_IsVfifoSetting(port, NONE_VFIFO))
   {
      /* Rx FIFO trigger = 62, Tx FIFO trigger is 16, and FIFO enable. */
      //DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_FCR_Normal);
	     UART_FCR_Setting(UART_BASE,UART_FCR_Normal);
   }   
   else if( UART_IsVfifoSetting(port, RX_VFIFO))
   {
   #if defined(DRV_UART_FIFO_FLOW_CONTROL) //Use larger size of RX FIFO, because it can trigger flow control
     // DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_FCR_TX_Normal | UART_FCR_RX16Byte_Level);
   UART_FCR_Setting(UART_BASE,UART_FCR_TX_Normal | UART_FCR_RX16Byte_Level);
      //DRV_WriteReg(UART_FCR(UART_BASE),UART_FCR_TX_Normal | UART_FCR_RX16Byte_Level);   
   #else
      //DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_FCR_TX_Normal);
    UART_FCR_Setting(UART_BASE,UART_FCR_TX_Normal);
      //DRV_WriteReg(UART_FCR(UART_BASE),UART_FCR_TX_Normal);
   #endif
      
   }
   else // tx vfifo
   {
      //DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_FCR_RX_Normal);
	  UART_FCR_Setting(UART_BASE,UART_FCR_RX_Normal);
   }
#else //#ifdef __DMA_UART_VIRTUAL_FIFO__
   /* Rx FIFO trigger = 62, Tx FIFO trigger is 16, and FIFO enable. */
  // DRV_UART_WriteReg(UART_FCR(UART_BASE),UART_FCR_Normal);
	UART_FCR_Setting(UART_BASE,UART_FCR_Normal);

#endif //__DMA_UART_VIRTUAL_FIFO__

   if(0 == ch)
   {
      if(UARTPort[port].CompensateAT == Compensate_AT)
      {
         Buf_Push(&(UARTPort[port].Rx_Buffer),0x41); // A
         Buf_Push(&(UARTPort[port].Rx_Buffer),0x54); // T
      }
      else if(UARTPort[port].CompensateAT == Compensate_at)
      {
         Buf_Push(&(UARTPort[port].Rx_Buffer),0x61); // a
         Buf_Push(&(UARTPort[port].Rx_Buffer),0x74); // t
      }
      UARTPort[port].CompensateAT = Compensate_None;
   }
   else
   {
      DRV_UART_WriteReg(UART_RXDMA(UART_BASE),UART_TXRXDMA_ON);
      DMA_Start(ch);
   }
   UARTPort[port].rx_cb(port);
}
#endif //#ifdef DRV_UART_COMPENSATE_AT


void UART_SetRateFix(UART_PORT  port)
{
#ifdef DCM_ENABLE
   kal_uint16 DLM_DLL = 0;
   kal_uint16 LCR;
   kal_uint16 AutobaudEn;
   kal_uint16 UART_CLOCK_Div_13M;
   if(port >= MAX_UART_PORT_NUM)
      return;
   
   if(UARTPort[port].AutobaudDetection)// Autobaud conflict with baudrate fix(DCM)
   {
      // Maybe UART FIFO stiil exist some data when we set autobaud?
      AutobaudEn = DRV_UART_Reg(UART_AUTOBAUD_EN(UART_BaseAddr[port]));
      if(AutobaudEn)
      {
         return;
      }
      // We use UART_CLOCK to do autobaud detection,
      // therefore we need to divide DLM+DLL by UART_CLOCK/UART_DCM_CLOCK
      // and set baudrate fix back.
      LCR = DRV_UART_Reg(UART_LCR(UART_BaseAddr[port]));
      LCR |= UART_LCR_DLAB;
      DRV_UART_WriteReg(UART_LCR(UART_BaseAddr[port]), LCR);
      DLM_DLL =  DRV_UART_Reg(UART_DLH(UART_BaseAddr[port])) << 8;
      DLM_DLL |= DRV_UART_Reg(UART_DLL(UART_BaseAddr[port]));
      UART_CLOCK_Div_13M = UART_CLOCK / UART_DCM_CLOCK;
      DLM_DLL /= UART_CLOCK_Div_13M;
      DRV_UART_WriteReg(UART_DLH(UART_BaseAddr[port]), DLM_DLL >> 8);
      DRV_UART_WriteReg(UART_DLL(UART_BaseAddr[port]), DLM_DLL & 0xFF);
      LCR &= ~UART_LCR_DLAB;
      DRV_UART_WriteReg(UART_LCR(UART_BaseAddr[port]), LCR);
      
      DRV_UART_WriteReg(UART_RATE_FIX_REG(UART_BaseAddr[port]),UART_RATE_FIX);/*13*/   
      UARTPort[port].AutobaudDetection = KAL_FALSE;
      DCM_Enable(UARTPort[port].DCMHandle);
   }	
#endif
}

void UART_RecHandler(void *parameter)
{
   UARTStruct *UARTData=(UARTStruct *)parameter;
   kal_uint32 UART_BASE;
   kal_uint16 RoomLeft;
   kal_uint16 LSR;
   kal_uint8  cRXChar;
    SGPT_CTRL_START_T start;
   //kal_bool   btmp; //avoid Warning 534: Ignoring return value of function 'GPTI_StartItem"
   if(UARTData->port_no >= MAX_UART_PORT_NUM)
      return;
   UART_BASE = UART_BaseAddr[UARTData->port_no];
   if (UARTData->ESCDet.GuardTime != 0)
   	DclSGPT_Control(UARTData->handle,SGPT_CMD_STOP,0);
  //    GPTI_StopItem(UARTData->handle);
   
   Buf_GetRoomLeft(&(UARTData->Rx_Buffer),RoomLeft);
   
    drv_trace2(TRACE_GROUP_3,UART_RX_MCU_MODE_INT,UARTData->port_no,RoomLeft);
	
   while (RoomLeft)
   {
      LSR = DRV_UART_Reg(UART_LSR(UART_BASE));
      if (LSR & UART_LSR_BI)
      {
         UARTData->breakDet = KAL_TRUE;
         U_Purge(UARTData->port_no,RX_BUF,UARTPort[UARTData->port_no].ownerid);
         LSR = DRV_UART_Reg(UART_LSR(UART_BASE));
      }
      
      if (LSR & UART_LSR_DR)
      {
#ifdef DCM_ENABLE
         if(UARTData->AutobaudDetection)
         {
            UART_SetRateFix(UARTData->port_no);
         }
#endif      	    
         cRXChar = (kal_uint8)DRV_UART_Reg(UART_RBR(UART_BASE));

         Buf_Push(&(UARTData->Rx_Buffer),cRXChar);
         RoomLeft--;
         if (UARTData->ESCDet.GuardTime != 0)
         {
            /* detect escape sequence  */
            if (UARTData->Rec_state != UART_RecNormal)
            {
               if (cRXChar == UARTData->ESCDet.EscChar)
               {
                  UARTData->EscCount++;
                  if(UARTData->EscCount == 3)
                  {
                     UARTData->Rec_state = UART_Get3EscChar;
                  }
                  else if(UARTData->EscCount > 3)
                  {
                     UARTData->Rec_state = UART_RecNormal;
                     UARTData->EscCount = 0;
                  }
               }
               else
               {
                  UARTData->Rec_state = UART_RecNormal;
                  UARTData->EscCount = 0;
               }
            }
         }
      }
      else
      {
         break;
      }
   }
   /*TY adds these to expand flexibility 2004/10/15*/
   UARTPort[UARTData->port_no].rx_cb(UARTData->port_no);
   
   if (UARTData->ESCDet.GuardTime != 0)
   	{
   		start.u2Tick=UARTData->ESCDet.GuardTime/10;
	start.pfCallback=UART_Calback;
	start.vPara=&UARTPort[UARTData->port_no];
	DclSGPT_Control(UARTData->handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);  
   	}
   
   if (!RoomLeft)   /*buffer is full*/
      DisableRxIntr(UART_BASE);
}
void UART_TrxHandler(void *parameter)
{
   UARTStruct *UARTData=(UARTStruct *)parameter;
   kal_uint32 UART_BASE;
   kal_uint16  byteCount,index;
   kal_uint16  real_count_TASK,real_count_ISR, real_count, left_count;
   kal_uint16  offset;
   kal_uint8   TX_DATA;
   if(UARTData->port_no >= MAX_UART_PORT_NUM)
      return;
   UART_BASE = UART_BaseAddr[UARTData->port_no];   
#if defined(DRV_UART_2_FIFO_DEPTHS) || defined(FPGA)
   if (UARTData->port_no == uart_port1)
      byteCount = UART1_TxFIFO_DEPTH;
   else
      byteCount = UART2_TxFIFO_DEPTH;
#endif   /*(DRV_UART_2_FIFO_DEPTHS,FPGA)*/
      
   Buf_GetBytesAvail(&(UARTData->Tx_Buffer_ISR),real_count_ISR);
   if (UARTPort[UARTData->port_no].sleep_on_tx == uart_sleep_on_tx_forbid)
   {
      Buf_GetBytesAvail(&(UARTData->Tx_Buffer),real_count_TASK);
#if !defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
      if ((!real_count_ISR) && (!real_count_TASK))
      {        
         UART_PDN_Enable(UARTData->port_no);
         DisableTxIntr(UART_BASE);
         return;
      }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
   }
   real_count = real_count_ISR;
   if (real_count_ISR > byteCount)
   {
      real_count = byteCount;
   }
   
   for (index = 0;index < real_count;index++)
   {
      Buf_Pop(&(UARTData->Tx_Buffer_ISR),TX_DATA);
      DRV_UART_WriteReg(UART_THR(UART_BASE),(kal_uint16)TX_DATA);
    #if defined(DRV_UART_PUTBYTE_DELAY)// this option For 6575 uart putbyte hw delay
        uart_LSR = DRV_UART_Reg(UART_LSR(UART_BASE));
		#endif
   }
   
   if (real_count != byteCount)
   {
      Buf_GetBytesAvail(&(UARTData->Tx_Buffer),real_count_TASK);
      offset = byteCount - real_count;
      real_count = real_count_TASK;
      if (real_count_TASK > offset)
      {
         real_count = offset;
      }
      
      for (index = 0;index < real_count;index++)
      {
         Buf_Pop(&(UARTData->Tx_Buffer),TX_DATA);
         DRV_UART_WriteReg(UART_THR(UART_BASE),(kal_uint16)TX_DATA);
    #if defined(DRV_UART_PUTBYTE_DELAY)// this option For 6575 uart putbyte hw delay
        uart_LSR = DRV_UART_Reg(UART_LSR(UART_BASE));
		#endif
      }
      
      //toy, when buffer full, UART will keep sending ready_to_write, wait until buffer not full
      if(WaitForUARTTx[UARTData->port_no])
      {
         Buf_GetRoomLeft(&(UARTData->Tx_Buffer),left_count);
         if( (left_count > (UARTData->Tx_Buffer.Length >> 2)) || (left_count > 300))
         {
            WaitForUARTTx[UARTData->port_no] = KAL_FALSE;
            send_Txilm[UARTData->port_no] = KAL_TRUE;
         }
      }
      
      /*TY adds these to expand flexibility 2004/10/15*/
      UARTPort[UARTData->port_no].tx_cb(UARTData->port_no);      
   }
   
   if (UARTPort[UARTData->port_no].sleep_on_tx == uart_sleep_on_tx_allow)
   {
      if ( ( BRead_addr(UARTData->Tx_Buffer) != BWrite_addr(UARTData->Tx_Buffer) ) ||
         ( BRead_addr(UARTData->Tx_Buffer_ISR) != BWrite_addr(UARTData->Tx_Buffer_ISR) )
         )
      {
         ;
      }
      else
      {
         DisableTxIntr(UART_BASE);
      }
   }
}

void UART_MsHandler(void *parameter)
{
   UARTStruct *UARTData=(UARTStruct *)parameter;
   kal_uint32 UART_BASE;
   kal_uint16  MSR;
   IO_level    DSR;

   if(UARTData->port_no >= MAX_UART_PORT_NUM)
      return;

   UART_BASE = UART_BaseAddr[UARTData->port_no];
   MSR = DRV_UART_Reg(UART_MSR(UART_BASE));
   if (MSR & UART_MSR_DSR)
      DSR = io_high;
   else
      DSR = io_low;
   
   if (DSR != UARTData->DSR)
   {
      UART_sendilm(UARTData->port_no, MSG_ID_UART_DSR_CHANGE_IND);
      UARTData->DSR = DSR;
   }
#if !defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
   if (UARTData->DCB.DSRCheck)
   {
      if (MSR & UART_MSR_DSR)
      { 
         UART_PDN_Disable(UARTData->port_no);         
      }
      else
      {     
         UART_PDN_Enable(UARTData->port_no);
      }
   }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
}

#if defined(DRV_UART1_NORMAL_DMA)
void UART1_TrxHandler(void)
{
   kal_uint16  real_count_TASK,real_count_ISR;
   kal_uint16  old_index;
   kal_uint32  savedMask;
   ASSERT(UART1_race_check == KAL_FALSE);
   
   
   savedMask = SaveAndSetIRQMask();
   UART1_race_check = KAL_TRUE;
   
   switch(uart1_index_save.type)
   {
   case uart_isr_buffer:
      BRead_addr(UARTPort[uart_port1].Tx_Buffer_ISR) = uart1_index_save.index;
      break;
   case uart_normal_buffer:
      BRead_addr(UARTPort[uart_port1].Tx_Buffer) = uart1_index_save.index;
      break;
   default:
      break;
   }
   UART1_update_index_save((kal_uint32)uart_null_buffer,0);
   
   if ( (BRead_addr(UARTPort[uart_port1].Tx_Buffer) == BWrite_addr(UARTPort[uart_port1].Tx_Buffer)) &&
      (BRead_addr(UARTPort[uart_port1].Tx_Buffer_ISR) == BWrite_addr(UARTPort[uart_port1].Tx_Buffer_ISR))
      )
   {
#if !defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
      if (UARTPort[uart_port1].sleep_on_tx == uart_sleep_on_tx_forbid){
         UART1_PDN_ENABLE();
      }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
      UART1_race_check = KAL_FALSE;
      UART1_Intr_is_Running = KAL_FALSE;
      RestoreIRQMask(savedMask);
      /*TY adds these to expand flexibility 2004/10/15*/      
      UARTPort[uart_port1].tx_cb(uart_port1);
      /*TY adds the above description 2004/10/14
      Whenever UART finishes all transmission, he also needs to 
      check send_Txilm[uart_port2] flag and send the message according
      to this flag*/	         
      return;
   }
   
   
   UART1_Intr_is_Running = KAL_TRUE;
   RestoreIRQMask(savedMask);
   
   DMA_Stop(uart1_dmaport);
   Data_Sync_Barrier();
   UART_SetDMAIntr(UART_BaseAddr[uart_port1]);
   
   Buf_GetBytesAvail(&(UARTPort[uart_port1].Tx_Buffer_ISR),real_count_ISR);
   
   if (real_count_ISR)
   {
      uart1_txmenu.addr = (kal_uint32)BuffRead_addr(UARTPort[uart_port1].Tx_Buffer_ISR);  /*1*/
      uart1_txmenu.WPPT = (void *)((kal_uint32)(Buff_EndAddr(UARTPort[uart_port1].Tx_Buffer_ISR))-(kal_uint32)uart1_txmenu.addr+1); /*2*/
      
      uart1_txmenu.WPTO = Buff_StartAddr(UARTPort[uart_port1].Tx_Buffer_ISR);     /*3*/
      uart1_input.count = real_count_ISR;       /*4*/
      uart1_input.callback = UART1_TrxHandler;   /*5*/
      
      old_index = BRead_addr(UARTPort[uart_port1].Tx_Buffer_ISR)+real_count_ISR;
      if (old_index>=BLength_addr(UARTPort[uart_port1].Tx_Buffer_ISR))
         old_index -= BLength_addr(UARTPort[uart_port1].Tx_Buffer_ISR);
      
      UART1_update_index_save((kal_uint32)uart_isr_buffer,old_index);
      DMA_Config(uart1_dmaport, &uart1_input, KAL_TRUE);
      UART1_race_check = KAL_FALSE;
   }
   else
   {
      Buf_GetBytesAvail(&(UARTPort[uart_port1].Tx_Buffer),real_count_TASK);
//#ifdef __PRODUCTION_RELEASE__
      if(real_count_TASK > 128)
         real_count_TASK = 128;
//#endif   /*__PRODUCTION_RELEASE__*/ 
      
      if (real_count_TASK)
      {
         uart1_txmenu.addr = (kal_uint32)BuffRead_addr(UARTPort[uart_port1].Tx_Buffer);  /*1*/
         uart1_txmenu.WPPT = (void *)((kal_uint32)(Buff_EndAddr(UARTPort[uart_port1].Tx_Buffer))-(kal_uint32)uart1_txmenu.addr+1); /*2*/
         
         uart1_txmenu.WPTO = Buff_StartAddr(UARTPort[uart_port1].Tx_Buffer);     /*3*/
         uart1_input.count = real_count_TASK;       /*4*/
         uart1_input.callback = UART1_TrxHandler;   /*5*/
         
         old_index = BRead_addr(UARTPort[uart_port1].Tx_Buffer)+real_count_TASK;
         if (old_index>=BLength_addr(UARTPort[uart_port1].Tx_Buffer))
            old_index -= BLength_addr(UARTPort[uart_port1].Tx_Buffer);
         
         UART1_update_index_save((kal_uint32)uart_normal_buffer,old_index);
         DMA_Config(uart1_dmaport, &uart1_input, KAL_TRUE);
         UART1_race_check = KAL_FALSE;
      }
      else
      {
         UART1_race_check = KAL_FALSE;
         UART1_Intr_is_Running = KAL_FALSE;
      }
   }
   /*TY adds these to expand flexibility 2004/10/15*/
   UARTPort[uart_port1].tx_cb(uart_port1);         
   
}
#endif /* defined(DRV_UART1_NORMAL_DMA) */



//add for uart1/2/3 THRE interrput
void UART_THREHandler(UART_PORT port)
{
#ifdef __DMA_UART_VIRTUAL_FIFO__
	if( UART_IsVfifoSetting(port, TX_VFIFO) )
		UART_THRE_hdr_VFIFO(port);
	else
//#endif
	{
		if(UARTPort[port].EnableTX == KAL_FALSE)
			return;
		switch(port)
		{
			case uart_port1:
				#if defined(DRV_UART1_NORMAL_DMA)
					UART1_TrxHandler();
				#endif
				#if defined(DRV_UART1_NO_DMA)
	 				UART_TrxHandler(&UARTPort[port]);
				#endif 
	 		break;
			case uart_port2:
				#if defined(DRV_UART2_NORMAL_DMA)
					UART2_TrxHandler();
				#endif
				#if defined(DRV_UART2_NO_DMA) || defined(FPGA)
           			UART_TrxHandler(&UARTPort[port]);
				#endif  
			break;
			#ifdef __UART3_SUPPORT__
			case uart_port3:
				#if defined(DRV_UART3_NORMAL_DMA)
          			UART3_TrxHandler();	
				#endif
				#if defined(DRV_UART3_NO_DMA) 		   
         			UART_TrxHandler(&UARTPort[port]);
				#endif 
			break;
			#endif //endif __UART3_SUPPORT__
			default:
			break;
		}
	}
#else
	if(UARTPort[port].EnableTX == KAL_FALSE)
	{
		return ;
	}
    switch(port)
    {
    	case uart_port1:
			#if defined(DRV_UART1_NORMAL_DMA)
				UART1_TrxHandler();	
			#endif
			#if defined(DRV_UART1_NO_DMA) 		   
        		UART_TrxHandler(&UARTPort[port]);         
			#endif
		break;
		case uart_port2:
			#if defined(DRV_UART2_NORMAL_DMA)
        		UART2_TrxHandler();
			#endif
			#if defined(DRV_UART2_NO_DMA) || defined(FPGA)
        		UART_TrxHandler(&UARTPort[port]);
			#endif
		break;
		#ifdef __UART3_SUPPORT__
		case uart_port3:
			#if defined(DRV_UART3_NORMAL_DMA)
           		UART3_TrxHandler();	
			#endif
			#if defined(DRV_UART3_NO_DMA) 		   
      			UART_TrxHandler(&UARTPort[port]);
			#endif
		break;
		#endif //endif __UART3_SUPPORT__
		default:
		break;
		
    }
#endif
}

void UART_HISR_Internal(UART_PORT port)
{
	kal_uint16 IIR;
	kal_uint8 irq_code;
	
	#if defined(DRV_UART_DMA_INTERNAL_BUFFER_WORKAROUND) 
	volatile kal_uint8 tmp;
	#endif
   IIR = DRV_UART_Reg(UART_IIR(UART_BaseAddr[port]));
   if (IIR & UART_IIR_INT_INVALID)
   {
		irq_code = UART_GetIRQCode(port);
		IRQClearInt(irq_code);
    	IRQUnmask(irq_code);
		return;
   }
   
   switch ( IIR & UART_IIR_INT_MASK )
   {
   	case UART_IIR_CTI:
		#ifdef __DMA_UART_VIRTUAL_FIFO__	
		#if defined(DRV_UART_DMA_INTERNAL_BUFFER_WORKAROUND) 		  
				if( UART_IsVfifoSetting(port, RX_VFIFO) == KAL_FALSE )
					UART_RecHandler(&UARTPort[port]);
				else
					tmp = DRV_UART_Reg(UART_RXDMA(UART_BaseAddr[port]));
		#elif defined(DRV_UART_NEW_UART_AND_OLG_DMA)//for MT6250 new uart design+old DMA design
			if( UART_IsVfifoSetting(port, RX_VFIFO) )
           		UART_RecTimeOutHandler(port);
        	else	
           		UART_RecHandler(&UARTPort[port]);
		#else
        	if( UART_IsVfifoSetting(port, RX_VFIFO) )
           		UART_RecTimeOutHandler(port);
        	else	
           		UART_RecHandler(&UARTPort[port]);
    #endif
		#else
        		UART_RecHandler(&UARTPort[port]);
		#endif	
        break;
	case UART_IIR_RDA:
        if( UART_IsVfifoSetting(port, RX_VFIFO) == KAL_FALSE)
			UART_RecHandler(&UARTPort[port]);
        break;
    case UART_IIR_THRE :
		UART_THREHandler(port);
        break;
     case UART_IIR_RLS:
        UART_RLSHandler(&UARTPort[port]);
        break;
        
     case UART_IIR_MS :
        UART_MsHandler(&UARTPort[port]);
        break;
        
     case UART_IIR_SWFlowCtrl:
        break;
        
     case UART_IIR_HWFlowCtrl:
        break;
        
     default:
        break;
   }
   
   irq_code = UART_GetIRQCode(port);
   IRQClearInt(irq_code);
   IRQUnmask(irq_code);
}


void UART1_HISR(void)
{ 
  UART_HISR_Internal(uart_port1);  
}

void UART_LISR(UART_PORT port)
{
//	kal_uint8 uart_hisrid[3] = {DRV_UART1_HISR_ID,DRV_UART2_HISR_ID,DRV_UART3_HISR_ID}
	kal_uint8 irq_code;
	irq_code = UART_GetIRQCode(port);
	IRQMask(irq_code);
    if (UARTPort[port].power_on == KAL_FALSE)
		IRQClearInt(irq_code);
	else
   		drv_active_hisr((DRV_HISR_ID)(DRV_UART1_HISR_ID + port));
}

void UART1_LISR(void)
{
	UART_LISR(uart_port1);
}

/*============================ UART2 ========================*/
#if defined(DRV_UART2_NORMAL_DMA)
void UART2_TrxHandler(void)
{
   kal_uint16  real_count_TASK,real_count_ISR;
   kal_uint16  old_index;
   kal_uint32  savedMask;
   ASSERT(UART2_race_check == KAL_FALSE);
   
   
   savedMask = SaveAndSetIRQMask();
   UART2_race_check = KAL_TRUE;
   
   switch(uart2_index_save.type)
   {
   case uart_isr_buffer:
      BRead_addr(UARTPort[uart_port2].Tx_Buffer_ISR) = uart2_index_save.index;
      break;
   case uart_normal_buffer:
      BRead_addr(UARTPort[uart_port2].Tx_Buffer) = uart2_index_save.index;
      break;
   default:
      break;
   }
   UART2_update_index_save((kal_uint32)uart_null_buffer,0);
   
   if ( (BRead_addr(UARTPort[uart_port2].Tx_Buffer) == BWrite_addr(UARTPort[uart_port2].Tx_Buffer)) &&
      (BRead_addr(UARTPort[uart_port2].Tx_Buffer_ISR) == BWrite_addr(UARTPort[uart_port2].Tx_Buffer_ISR))
      )
   {
#if !defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
      if (UARTPort[uart_port2].sleep_on_tx == uart_sleep_on_tx_forbid){
         UART2_PDN_ENABLE();
      }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
      UART2_race_check = KAL_FALSE;
      UART2_Intr_is_Running = KAL_FALSE;
      RestoreIRQMask(savedMask);
      /*TY adds these to expand flexibility 2004/10/15*/      
      UARTPort[uart_port2].tx_cb(uart_port2);
      /*TY adds the above description 2004/10/14
      Whenever UART finishes all transmission, he also needs to 
      check send_Txilm[uart_port2] flag and send the message according
      to this flag*/	         
      return;
   }
   
   
   UART2_Intr_is_Running = KAL_TRUE;
   RestoreIRQMask(savedMask);
   
   DMA_Stop(uart2_dmaport);
   UART_SetDMAIntr(UART_BaseAddr[uart_port2]);
   
   Buf_GetBytesAvail(&(UARTPort[uart_port2].Tx_Buffer_ISR),real_count_ISR);
   
   if (real_count_ISR)
   {
      uart2_txmenu.addr = (kal_uint32)BuffRead_addr(UARTPort[uart_port2].Tx_Buffer_ISR);  /*1*/
      uart2_txmenu.WPPT = (void *)((kal_uint32)(Buff_EndAddr(UARTPort[uart_port2].Tx_Buffer_ISR))-(kal_uint32)uart2_txmenu.addr+1); /*2*/
      
      uart2_txmenu.WPTO = Buff_StartAddr(UARTPort[uart_port2].Tx_Buffer_ISR);     /*3*/
      uart2_input.count = real_count_ISR;       /*4*/
      uart2_input.callback = UART2_TrxHandler;   /*5*/
      
      old_index = BRead_addr(UARTPort[uart_port2].Tx_Buffer_ISR)+real_count_ISR;
      if (old_index>=BLength_addr(UARTPort[uart_port2].Tx_Buffer_ISR))
         old_index -= BLength_addr(UARTPort[uart_port2].Tx_Buffer_ISR);
      
      UART2_update_index_save((kal_uint32)uart_isr_buffer,old_index);
      DMA_Config(uart2_dmaport, &uart2_input, KAL_TRUE);
      UART2_race_check = KAL_FALSE;
   }
   else
   {
      Buf_GetBytesAvail(&(UARTPort[uart_port2].Tx_Buffer),real_count_TASK);
//#ifdef __PRODUCTION_RELEASE__
      if(real_count_TASK > 128)
         real_count_TASK = 128;
//#endif   /*__PRODUCTION_RELEASE__*/ 
      
      if (real_count_TASK)
      {
         uart2_txmenu.addr = (kal_uint32)BuffRead_addr(UARTPort[uart_port2].Tx_Buffer);  /*1*/
         uart2_txmenu.WPPT = (void *)((kal_uint32)(Buff_EndAddr(UARTPort[uart_port2].Tx_Buffer))-(kal_uint32)uart2_txmenu.addr+1); /*2*/
         
         uart2_txmenu.WPTO = Buff_StartAddr(UARTPort[uart_port2].Tx_Buffer);     /*3*/
         uart2_input.count = real_count_TASK;       /*4*/
         uart2_input.callback = UART2_TrxHandler;   /*5*/
         
         old_index = BRead_addr(UARTPort[uart_port2].Tx_Buffer)+real_count_TASK;
         if (old_index>=BLength_addr(UARTPort[uart_port2].Tx_Buffer))
            old_index -= BLength_addr(UARTPort[uart_port2].Tx_Buffer);
         
         UART2_update_index_save((kal_uint32)uart_normal_buffer,old_index);
         DMA_Config(uart2_dmaport, &uart2_input, KAL_TRUE);
         UART2_race_check = KAL_FALSE;
      }
      else
      {
         UART2_race_check = KAL_FALSE;
         UART2_Intr_is_Running = KAL_FALSE;
      }
   }
   /*TY adds these to expand flexibility 2004/10/15*/
   UARTPort[uart_port2].tx_cb(uart_port2);         
   
}
#endif   /*DRV_UART2_NORMAL_DMA*/

#ifdef __UART3_SUPPORT__
#if defined(DRV_UART3_NORMAL_DMA)
void UART3_TrxHandler(void)
{
   kal_uint16  real_count_TASK,real_count_ISR;
   kal_uint16  old_index;
   kal_uint32  savedMask;
   ASSERT(UART3_race_check == KAL_FALSE);
   
   savedMask = SaveAndSetIRQMask();
   UART3_race_check = KAL_TRUE;
   
   switch(uart3_index_save.type)
   {
   case uart_isr_buffer:
      BRead_addr(UARTPort[uart_port3].Tx_Buffer_ISR) = uart3_index_save.index;
      break;
   case uart_normal_buffer:
      BRead_addr(UARTPort[uart_port3].Tx_Buffer) = uart3_index_save.index;
      break;
   default:
      break;
   }
   UART3_update_index_save((kal_uint32)uart_null_buffer,0);
   
   if ( (BRead_addr(UARTPort[uart_port3].Tx_Buffer) == BWrite_addr(UARTPort[uart_port3].Tx_Buffer)) &&
      (BRead_addr(UARTPort[uart_port3].Tx_Buffer_ISR) == BWrite_addr(UARTPort[uart_port3].Tx_Buffer_ISR))
      )
   {
#if !defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
      if (UARTPort[uart_port3].sleep_on_tx == uart_sleep_on_tx_forbid){
         UART3_PDN_ENABLE();
      }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
      UART3_race_check = KAL_FALSE;
      UART3_Intr_is_Running = KAL_FALSE;
      RestoreIRQMask(savedMask);
      /*TY adds these to expand flexibility 2004/10/15*/      
      UARTPort[uart_port3].tx_cb(uart_port3);
      /*TY adds the above description 2004/10/14
      Whenever UART finishes all transmission, he also needs to 
      check send_Txilm[uart_port2] flag and send the message according
      to this flag*/	         
      return;
   }
   
   
   UART3_Intr_is_Running = KAL_TRUE;
   RestoreIRQMask(savedMask);
   
   DMA_Stop(uart3_dmaport);
   UART_SetDMAIntr(UART_BaseAddr[uart_port3]);
   
   Buf_GetBytesAvail(&(UARTPort[uart_port3].Tx_Buffer_ISR),real_count_ISR);
   
   if (real_count_ISR)
   {
      uart3_txmenu.addr = (kal_uint32)BuffRead_addr(UARTPort[uart_port3].Tx_Buffer_ISR);  /*1*/
      uart3_txmenu.WPPT = (void *)((kal_uint32)(Buff_EndAddr(UARTPort[uart_port3].Tx_Buffer_ISR))-(kal_uint32)uart3_txmenu.addr+1); /*2*/
    
      uart3_txmenu.WPTO = Buff_StartAddr(UARTPort[uart_port3].Tx_Buffer_ISR);     /*3*/
      uart3_input.count = real_count_ISR;       /*4*/
      uart3_input.callback = UART3_TrxHandler;   /*5*/
      
      old_index = BRead_addr(UARTPort[uart_port3].Tx_Buffer_ISR)+real_count_ISR;
      if (old_index>=BLength_addr(UARTPort[uart_port3].Tx_Buffer_ISR))
         old_index -= BLength_addr(UARTPort[uart_port3].Tx_Buffer_ISR);
      
      UART3_update_index_save((kal_uint32)uart_isr_buffer,old_index);
      DMA_Config(uart3_dmaport, &uart3_input, KAL_TRUE);
      UART3_race_check = KAL_FALSE;
   }
   else
   {
      Buf_GetBytesAvail(&(UARTPort[uart_port3].Tx_Buffer),real_count_TASK);
//#ifdef __PRODUCTION_RELEASE__
      if(real_count_TASK > 128)
         real_count_TASK = 128;
//#endif   /*__PRODUCTION_RELEASE__*/ 
      
      if (real_count_TASK)
      {
         uart3_txmenu.addr = (kal_uint32)BuffRead_addr(UARTPort[uart_port3].Tx_Buffer);  /*1*/
         uart3_txmenu.WPPT = (void *)((kal_uint32)(Buff_EndAddr(UARTPort[uart_port3].Tx_Buffer))-(kal_uint32)uart3_txmenu.addr+1); /*2*/
       
         uart3_txmenu.WPTO = Buff_StartAddr(UARTPort[uart_port3].Tx_Buffer);     /*3*/
         uart3_input.count = real_count_TASK;       /*4*/
         uart3_input.callback = UART3_TrxHandler;   /*5*/
         
         old_index = BRead_addr(UARTPort[uart_port3].Tx_Buffer)+real_count_TASK;
         if (old_index>=BLength_addr(UARTPort[uart_port3].Tx_Buffer))
            old_index -= BLength_addr(UARTPort[uart_port3].Tx_Buffer);
         
         UART3_update_index_save((kal_uint32)uart_normal_buffer,old_index);
         DMA_Config(uart3_dmaport, &uart3_input, KAL_TRUE);
         UART3_race_check = KAL_FALSE;
      }
      else
      {
         UART3_race_check = KAL_FALSE;
         UART3_Intr_is_Running = KAL_FALSE;
      }
   }
   /*TY adds these to expand flexibility 2004/10/15*/
   UARTPort[uart_port3].tx_cb(uart_port3);         
   
}
#endif /* defined(DRV_UART3_NORMAL_DMA) */
#endif

void UART2_HISR(void)
{   
   UART_HISR_Internal(uart_port2);   
}

void UART2_LISR(void)
{
	UART_LISR(uart_port2);
}

#ifdef __UART3_SUPPORT__
void UART3_HISR(void)
{
 UART_HISR_Internal(uart_port3);
}

void UART3_LISR(void)
{  
   UART_LISR(uart_port3);   
}
#endif   /*__UART3_SUPPORT__*/

#ifdef __USB_COM_PORT_ENABLE__
extern UARTStruct USB2UARTPort[MAX_USB_PORT_NUM];
#endif   /*__USB_COM_PORT_ENABLE__*/

void UART_SetSleepEnable(kal_bool enable)
{
#if defined(DRV_UART_BASIC_REG) //UART_SLEEP_EN only exist in DRV_UART_BASIC_REG
   DRV_UART_WriteReg(UART_SLEEP_EN(UART_BaseAddr[uart_port1]),enable);
 //  if(UARTPort[uart_port2].ownerid == MOD_BT)//BT can not receive flow control, because when BT sleep, it will switch RX as EINT.
  //    DRV_UART_WriteReg(UART_SLEEP_EN(UART_BaseAddr[uart_port2]),KAL_FALSE);
  // else
      DRV_UART_WriteReg(UART_SLEEP_EN(UART_BaseAddr[uart_port2]),enable);
#ifdef __UART3_SUPPORT__
 //  if(UARTPort[uart_port3].ownerid == MOD_BT)//BT can not receive flow control, because when BT sleep, it will switch RX as EINT.
 //     DRV_UART_WriteReg(UART_SLEEP_EN(UART_BaseAddr[uart_port3]),KAL_FALSE);
  // else
      DRV_UART_WriteReg(UART_SLEEP_EN(UART_BaseAddr[uart_port3]),enable);
#endif /*__UART3_SUPPORT__*/
#endif
}

/*TY adds these to expand flexibility 2004/10/15*/
void UART_dafault_tx_cb(UART_PORT port)
{
   if(port >= MAX_UART_PORT_NUM)
      return;
   if (send_Txilm[port])
   {
      UART_sendilm(port, MSG_ID_UART_READY_TO_WRITE_IND);
      send_Txilm[port] = KAL_FALSE;
   }      
}
void UART_dafault_rx_cb(UART_PORT port)
{
   if(port >= MAX_UART_PORT_NUM)
      return;
   if (send_Rxilm[port])
   {
      if(port == uart_port3)
         UART_DBG(__LINE__, UART_GetTimeStamp(), ust_get_current_time(), 0);
      UART_sendilm(port, MSG_ID_UART_READY_TO_READ_IND);
      send_Rxilm[port] = KAL_FALSE;
   }      
}
void UART_dsp_dafault_tx_cb(UART_PORT port)
{
   if(port >= MAX_UART_PORT_NUM)
      return;

     UART_sendilm(port, MSG_ID_UART_READY_TO_WRITE_IND);
}
void UART_dsp_dafault_rx_cb(UART_PORT port)
{
   if(port >= MAX_UART_PORT_NUM)
      return;

    UART_sendilm(port, MSG_ID_UART_READY_TO_READ_IND);

}
//This API only for test purpose, can only be called by MEUT DVT test.
//***********  do not call this API directly   ************
//***********  do not call this API directly   ************
//***********  do not call this API directly   ************
void UART_set_FIFO_trigger(UART_PORT port, kal_uint16 tx_level, kal_uint16 rx_level)
{
   if(port >= MAX_UART_PORT_NUM)
      return;
   //DRV_UART_WriteReg(UART_FCR(UART_BaseAddr[port]), ((tx_level<<4) | (rx_level<<6) | 0x7));
   	UART_FCR_Setting(UART_BaseAddr[port],((tx_level<<4) | (rx_level<<6) | 0x7));
}

/*TY adds these to expand flexibility 2004/10/15*/
void U_Register_TX_cb(UART_PORT port, module_type ownerid, UART_TX_FUNC func)
{
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
   if(func == NULL) // if null, means register the default call back function
   	{
   		UARTPort[port].tx_cb = UART_dafault_tx_cb;
   	}
   	else
   		{
   			 UARTPort[port].tx_cb=func;   
   		}
  
}   
/*TY adds these to expand flexibility 2004/10/15*/
void U_Register_RX_cb(UART_PORT port, module_type ownerid, UART_RX_FUNC func)
{
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
   if(func == NULL) // if null, means register the default call back function
   	{
   		UARTPort[port].rx_cb = UART_dafault_rx_cb;
   	}
   	else
   		{
   			 UARTPort[port].rx_cb=func;    
   		}
   
}   

void UART_TurnOnPower(UART_PORT port, kal_bool enable)
{      
#if defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
   
   return;

#else //#if !defined(DRV_MISC_TDMA_PDN0)// For MT6516 MD side do not have pdn
#if defined(__OLD_PDN_ARCH__) 
   kal_uint16 pdn_code=0;
#endif //#if defined(__OLD_PDN_ARCH__) 
   kal_uint8  irq_code=0;
   if(port >= MAX_UART_PORT_NUM)
      return;
   switch(port)
   {
   case uart_port1:
#if defined(__OLD_PDN_ARCH__)   
#if defined(__OLD_PDN_DEFINE__)
      pdn_code=DRVPDN_CON1_UART1;
#elif defined(__APPLICATION_PROCESSOR__)
      pdn_code=CG_CON0_UART1;
#elif defined(__CLKG_DEFINE__)
      pdn_code=CG_CON1_UART1;
#endif // #if defined(__OLD_PDN_DEFINE__)
#endif //#if defined(__OLD_PDN_ARCH__)
	irq_code = UART_GetIRQCode(uart_port1);
      break;
   case uart_port2:
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
      pdn_code=DRVPDN_CON1_UART2;
#elif defined(__APPLICATION_PROCESSOR__)
      pdn_code=CG_CON0_UART2;
#elif defined(__CLKG_DEFINE__)
      pdn_code=CG_CON1_UART2;
#endif // #if defined(__OLD_PDN_DEFINE__)
#endif //#if defined(__OLD_PDN_ARCH__)
	irq_code = UART_GetIRQCode(uart_port2);
      
#ifdef DCM_ENABLE
//#if defined(__USE_921600_WITHOUT_SAMPLE_COUNT__)
#if defined(__USE_UART2_921600__)
      if(enable==KAL_TRUE)/*turn on power*/
         	{
      	#if (!defined(DRV_UART_DCM_BUG_FIXED)) && (!defined(DRV_UART_DCM_NO_BUG))
         DCM_Disable(UARTPort[port].DCMHandle);
		#else
		DCM_Enable(UARTPort[port].DCMHandle);
		#endif
      	}
      else
         DCM_Enable(UARTPort[port].DCMHandle);
#endif/*defined(__USE_UART2_921600__)*/
//#endif/*defined(__USE_921600_WITHOUT_SAMPLE_COUNT__)*/
#endif/*DCM_ENABLE*/  
      break;
   case uart_port3:       	 	
#ifdef __UART3_SUPPORT__
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
      pdn_code=DRVPDN_CON1_UART3;
#elif defined(__APPLICATION_PROCESSOR__)
      pdn_code=CG_CON0_UART3;
#elif defined(__CLKG_DEFINE__)
      pdn_code=CG_CON1_UART3;
#endif // #if defined(__OLD_PDN_DEFINE__)      
	irq_code = UART_GetIRQCode(uart_port3);     
#else
      irq_code = UART_GetIRQCode(uart_port3);     
#endif //#if defined(__OLD_PDN_ARCH__)
//#if ( defined(DCM_ENABLE) && !defined(DRV_UART_SPEED_SAMPLE_COUNT))
#ifdef DCM_ENABLE
      if(enable==KAL_TRUE)/*turn on power*/
        	{
      	#if (!defined(DRV_UART_DCM_BUG_FIXED)) && (!defined(DRV_UART_DCM_NO_BUG))
         DCM_Disable(UARTPort[port].DCMHandle);
		#else
		DCM_Enable(UARTPort[port].DCMHandle);
		#endif
      	}
         
      else
         DCM_Enable(UARTPort[port].DCMHandle);            
#endif/*DCM_ENABLE*/   
#endif/*__UART3_SUPPORT__*/
      break;
   }
   if(enable==KAL_TRUE)/*turn on power*/
   {
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
      DRV_UART_WriteReg(DRVPDN_CON1+0x20, pdn_code);
      //DRV_UART_Reg(DRVPDN_CON1+0x20)=pdn_code;
#elif defined(__APPLICATION_PROCESSOR__)
      DRV_UART_WriteReg(CG_CLR0, pdn_code);
      //DRV_UART_Reg(CG_CLR0)=pdn_code;
#elif defined(__CLKG_DEFINE__)
      DRV_UART_WriteReg(CG_CLR1, pdn_code);
      //DRV_UART_Reg(CG_CLR1)=pdn_code;
#endif // #if defined(__OLD_PDN_DEFINE__)
#else
      if (port == uart_port1) {
         PDN_CLR(PDN_UART1);
      }
	  #if !defined(DRV_MD_1_UART)// for MD only have one uart port,like MT6280
      if (port == uart_port2) {
         PDN_CLR(PDN_UART2);
      }
	  #endif
#ifdef __UART3_SUPPORT__      
      if (port == uart_port3) {
         PDN_CLR(PDN_UART3);
      }
#endif //#ifdef __UART3_SUPPORT__      
#endif //#if defined(__OLD_PDN_ARCH__)
      //DRV_UART_WriteReg(UART_IER(UART_BaseAddr[port]),UART_IER_ALLOFF);
      UARTPort[port].power_on = KAL_TRUE;
      IRQClearInt(irq_code);
      IRQUnmask(irq_code);
   }
   else/*turn off power*/
   {
      IRQMask(irq_code);
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
      DRV_UART_WriteReg(DRVPDN_CON1+0x10, pdn_code);
      //DRV_UART_Reg(DRVPDN_CON1+0x10)=pdn_code;
#elif defined(__APPLICATION_PROCESSOR__)
      DRV_UART_WriteReg(CG_SET0, pdn_code);
      //DRV_UART_Reg(CG_SET0)=pdn_code;
#elif defined(__CLKG_DEFINE__)
      DRV_UART_WriteReg(CG_SET1, pdn_code);
      //DRV_UART_Reg(CG_SET1)=pdn_code;
#endif // #if defined(__OLD_PDN_DEFINE__)
#else
      if (port == uart_port1) {
         PDN_SET(PDN_UART1);
      }
	  #if !defined(DRV_MD_1_UART)// for MD only have one uart port,like MT6280
      if (port == uart_port2) {
         PDN_SET(PDN_UART2);
      }
	  #endif
#ifdef __UART3_SUPPORT__      
      if (port == uart_port3) {
         PDN_SET(PDN_UART3);
      }
#endif //#ifdef __UART3_SUPPORT__
#endif //#if defined(__OLD_PDN_ARCH__)
      UARTPort[port].power_on = KAL_FALSE;
   }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
}   

/* This is to check that all the data in UART TX ring buffer is empty. */
kal_bool UART_CheckTxBufferEmpty(UART_PORT port)
{
	 kal_uint8 result;
   if(port >= MAX_UART_PORT_NUM)
      return KAL_FALSE;
#ifdef __DMA_UART_VIRTUAL_FIFO__
   if( UART_IsVfifoSetting(port, TX_VFIFO) )
   {
      return ((0==DMA_GetVFIFO_Avail(UARTPort[port].Tx_DMA_Ch)) ? KAL_TRUE : KAL_FALSE);
   }
   else
   {
#endif
     
      
      Buf_IsEmpty(&(UARTPort[port].Tx_Buffer),result);
      return ((Buff_isEmpty == result) ? KAL_TRUE : KAL_FALSE);
#ifdef __DMA_UART_VIRTUAL_FIFO__
   }
#endif
}

/* This is to check that all TX data have been sent out 
including UART TX ring buffer and UART FIFO. */
kal_bool UART_CheckTxAllSentOut(UART_PORT port)
{
   if(port >= MAX_UART_PORT_NUM)
      return KAL_FALSE;
   if (UART_CheckTxBufferEmpty(port) == KAL_FALSE)
      return KAL_FALSE;
   if (UART_LSR_TEMT & DRV_UART_Reg(UART_LSR(UART_BaseAddr[port])))
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

void UART_GetTxBufferSize(UART_PORT port, kal_uint32 *total_size, kal_uint32 *rest_size)
{
   if(port >= MAX_UART_PORT_NUM)
      return;
   *total_size = UARTPort[port].Tx_Buffer.Length;
#ifdef __DMA_UART_VIRTUAL_FIFO__
   if( UART_IsVfifoSetting(port, TX_VFIFO) )
      *rest_size = DMA_GetVFIFO_Avail(UARTPort[port].Tx_DMA_Ch);
   else
#endif
      Buf_GetBytesAvail(&(UARTPort[port].Tx_Buffer), *rest_size);
}


/*
* FUNCTION                                                            
*	UART_VFIFO_TX_DMA_Enable
*
* DESCRIPTION                                                           
*   	for
*
* CALLS  
*	This function is called to enable or disable VFIFO DMA TX
*     it is for logacc only , logacc will take UART TX , it might cause UART & VFIFO DMA sync problem
*     so we must disable VFIFO DMA when logacc on
*     enable and reset VFIFO DMA when logacc off
*
* PARAMETERS
*	port: uart port
*	enable: disable or enable VFIFO DMA TX
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void UART_VFIFO_TX_DMA_Enable(UART_PORT port,kal_bool enable)
{
#if defined(__LOGACC_ENABLE__) 
#ifdef __DMA_UART_VIRTUAL_FIFO__
#if defined(DRV_UART_VFIFO_V2)||defined(DRV_UART_VFIFO_V3)
	kal_uint32 UART_BASE;
	kal_uint32 start_ticks=0;
	kal_uint16 RxDMA;
	kal_uint16 LSR;
	module_type ownerid=UARTPort[port].ownerid;

	if(port < MAX_UART_PORT_NUM && (ownerid==MOD_TST || ownerid==MOD_TST_READER))
	{
		if (UART_IsVfifoSetting(port, TX_VFIFO)==KAL_TRUE)
		{
			UART_BASE = UART_BaseAddr[port];
			RxDMA=DRV_UART_Reg(UART_RXDMA(UART_BASE));   
			if (enable==KAL_TRUE)
			{

				while(1)
				{
					LSR = DRV_UART_Reg(UART_LSR(UART_BaseAddr[port]));
					if ( LSR & UART_LSR_THRE )
						break;
					start_ticks++;
					if(start_ticks > VFIFO_SWITCH_WAIT_LOOP)
						break;
				}
			
	 			RxDMA|= UART_TX_DMA_EN;
				U_Purge(port,TX_BUF,ownerid); 
				DRV_UART_WriteReg(UART_RXDMA(UART_BASE), RxDMA);
				DMA_Start(UARTPort[port].Tx_DMA_Ch);
			}
			else
			{
	 			RxDMA &=~(UART_TX_DMA_EN);
				DRV_UART_WriteReg(UART_RXDMA(UART_BASE), RxDMA);
				DMA_Stop(UARTPort[port].Tx_DMA_Ch);
			}
		}

	}
	else
	{
		
ASSERT(0);
	}
#endif //#if defined(DRV_UART_VFIFO_V2)
#endif //#ifdef __DMA_UART_VIRTUAL_FIFO__
#endif //#if defined(__LOGACC_ENABLE__) 
}




// Used under ASSERT condition
// This has effect only when the port does NOT support VFIFO and used as Catcher port
// After ASSERT, TST will wait UART to send out all the data before ASSERT.
// But now, all the interrupts are disabled, TST may wait forever when the UART port is configured with DMA
// To solve this problem, we provide this function for TST to call 
// in order to send out all the data in ring buffer before ASSERT
// TST will open UART port again after previous data is sent out
void UART_AssertWaitPrevDataSentOut(UART_PORT port){
   kal_uint16 LSR;
   kal_uint16 TX_DATA;
#if defined(DRV_UART2_NORMAL_DMA)
   kal_uint32 start_ticks; // for break out of infinite loop
#endif
   if(port >= MAX_UART_PORT_NUM)
      return;
   
#ifdef __DMA_UART_VIRTUAL_FIFO__
   if( UART_IsVfifoSetting(port, TX_VFIFO) )
   {
      // Support VFIFO, what we need to do is to wait VFIFO DMA to 
      // sent out the remaining data in ring buffer before ASSERT
      while (!UART_CheckTxBufferEmpty(port)){
         ;
      }
   }else{
#if defined(DRV_UART2_NORMAL_DMA)
      if (port == uart_port2){
            start_ticks = 0;
            //Polling DMA channel stat till stopped
            //ASSERT_WAIT_LOOP to avoid DMA broken
			while(DMA_CheckRunStat(uart2_dmaport))
			{
				start_ticks++;
				if(start_ticks >= ASSERT_WAIT_LOOP)
				break;		    
			}
		
         return;
      }
#endif // #if defined(DRV_UART2_NORMAL_DMA)
      
      // Manually send out data by MCU polling
      while (!UART_CheckTxBufferEmpty(port)){
         LSR = DRV_UART_Reg(UART_LSR(UART_BaseAddr[port]));
         if ( LSR & UART_LSR_THRE )
         {
            Buf_Pop(&(UARTPort[port].Tx_Buffer),TX_DATA);
         			DRV_UART_WriteReg(UART_THR(UART_BaseAddr[port]),(kal_uint16)TX_DATA);
					UART_Delay_For_Bus_Early_Response();//for MT6255\MT6256 BUS limitation:early respones

         }
      }
      // Wait UART controller to sent out the data in FIFO
      while (!UART_CheckTxAllSentOut(port)){
         ;
      }
   }
#else
#if defined(DRV_UART2_NORMAL_DMA)
   if (port == uart_port2){
            start_ticks = 0;
            //Polling DMA channel stat till stopped
            //ASSERT_WAIT_LOOP to avoid DMA broken
			while(DMA_CheckRunStat(uart2_dmaport))
			{
				start_ticks++;
				if(start_ticks >= ASSERT_WAIT_LOOP)
				break;		    
			}
		
         return;
   }
#endif // #if defined(DRV_UART2_NORMAL_DMA)
   
   // Manually send out data by MCU polling
   while (!UART_CheckTxBufferEmpty(port)){
      LSR = DRV_UART_Reg(UART_LSR(UART_BaseAddr[port]));
      if ( LSR & UART_LSR_THRE )
      {
         Buf_Pop(&(UARTPort[port].Tx_Buffer),TX_DATA);
         DRV_UART_WriteReg(UART_THR(UART_BaseAddr[port]),(kal_uint16)TX_DATA);
		 UART_Delay_For_Bus_Early_Response();//for MT6255\MT6256 BUS limitation:early respones

      }
   }
   // Wait UART controller to sent out the data in FIFO
   while (!UART_CheckTxAllSentOut(port)){
      ;
   }
   
#endif
   
}
//Bei add for udvt
void UART_Register(UART_PORT port, UartDriver_strcut *UartDriver)
{
	pUart_CMD_FUNC[port]= UartDriver;
}
//add for get maxbaudrate
kal_uint32 UART_Get_Maxbaudrate(UART_PORT port)
{
	kal_uint32 baudrate;
	#ifdef DCM_ENABLE 
		#ifdef DRV_UART_FRACTIONAL
			baudrate = UART_BAUD_1500000;
		#else
			baudrate = UART_BAUD_921600;
		#endif
	#else
		baudrate = UART_BAUD_1500000;
	#endif	
	return baudrate;
}



#define UART_NO_BOOTUP_TRACE              0
#define UART_BOOTUP_TRACE_CLOSE_VFIFO     1
#define UART_BOOTUP_TRACE_OPEN_VFIFO      2


void UART_Driver_open_close_vfifo(UART_PORT port,kal_uint32 flag)
{
      #ifdef __DMA_UART_VIRTUAL_FIFO__
			static kal_uint8 uflag_bootup = 0;
			#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
				static kal_bool UART_SINGLE_VFIFO_support_bootupTrace_pre1 = KAL_FALSE;
				static kal_bool UART_SINGLE_VFIFO_support_bootupTrace_pre2 = KAL_FALSE;
			#else
				 static kal_bool UART_VFIFO_support_bootupTrace_pre = KAL_FALSE;
			#endif//__DMA_UART_VFIFO_SINGLE_TUNNEL__


		if( flag == UART_BOOTUP_TRACE_CLOSE_VFIFO )
		{
			if(uflag_bootup != 0)
				  EXT_ASSERT(0, (kal_uint32)flag, (kal_uint32)uflag_bootup,0);
			uflag_bootup = 1;
			#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
			UART_SINGLE_VFIFO_support_bootupTrace_pre1 = UART_SINGLE_VFIFO_support[port*2];
			UART_SINGLE_VFIFO_support_bootupTrace_pre2 = UART_SINGLE_VFIFO_support[port*2+1];
			 UART_SINGLE_VFIFO_support[port*2]= KAL_FALSE;
			 UART_SINGLE_VFIFO_support[port*2+1]= KAL_FALSE;
			#else
			UART_VFIFO_support_bootupTrace_pre = UART_VFIFO_support[port];
			 UART_VFIFO_support[port]=KAL_FALSE;
			 DRV_UART_WriteReg(UART_RXDMA(UART_BaseAddr[port]),UART_TXRXDMA_OFF);// close VFIFO 0x4c register
		    #endif//__DMA_UART_VFIFO_SINGLE_TUNNEL__	
		}
		else if( flag == UART_BOOTUP_TRACE_OPEN_VFIFO )
		{
			if(uflag_bootup != 1)
			 EXT_ASSERT(0, (kal_uint32)flag, (kal_uint32)uflag_bootup,0);
			uflag_bootup = 2;
			#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
			          if(UART_SINGLE_VFIFO_support_bootupTrace_pre1 && UART_SINGLE_VFIFO_support_bootupTrace_pre2)
			          	{
						 UART_SINGLE_VFIFO_support[port*2]= UART_SINGLE_VFIFO_support_bootupTrace_pre1;
						 UART_SINGLE_VFIFO_support[port*2+1]= UART_SINGLE_VFIFO_support_bootupTrace_pre2;
			          	}
			#else
			           if(UART_VFIFO_support_bootupTrace_pre)
			           	{
						 UART_VFIFO_support[port]=UART_VFIFO_support_bootupTrace_pre;
			           	}
			#endif
		}
	#endif//__DMA_UART_VIRTUAL_FIFO__		


#ifdef __DMA_UART_VIRTUAL_FIFO__	 
#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
		if(UART_SINGLE_VFIFO_support[port*2] && UART_SINGLE_VFIFO_support[port*2 + 1])
			pUart_CMD_FUNC[port]= &UartDriver_VFIFO;
		else if(UART_SINGLE_VFIFO_support[port*2])
			pUart_CMD_FUNC[port]= &UartDriver_VFIFO_RX;
		else if(UART_SINGLE_VFIFO_support[port*2 + 1])
			pUart_CMD_FUNC[port]= &UartDriver_VFIFO_TX;
		else // both tx and rx are not VFIFO
		   pUart_CMD_FUNC[port]= &UartDriver;
#else //#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)

	if(UART_VFIFO_support[port])
		pUart_CMD_FUNC[port]= &UartDriver_VFIFO;
	else 
	  pUart_CMD_FUNC[port]= &UartDriver;
	#endif//__DMA_UART_VFIFO_SINGLE_TUNNEL__
#else // #ifdef __DMA_UART_VIRTUAL_FIFO__
	 pUart_CMD_FUNC[port]= &UartDriver;
#endif // #ifdef __DMA_UART_VIRTUAL_FIFO__
	
}

void PreInit_Seriport()//Bootup init call this function
{

	DCL_HANDLE uart_handle;
	UART_CTRL_INIT_T data_init;
	#ifdef __USB_BOOTUP_TRACE__
	UART_CTRL_OPEN_T data;
	#endif	//__USB_BOOTUP_TRACE__

	#ifdef __USB_BOOTUP_TRACE__
	  extern Seriport_HANDLER_T USB2Uart_Drv_Handler;
	#endif
	 extern Seriport_HANDLER_T  Uart_Drv_Handler;
  if (debug_port <= uart_port3)
			  {
					data_init.u4Flag = UART_BOOTUP_TRACE_CLOSE_VFIFO;
					uart_handle = DclSerialPort_Open(debug_port,0);
					DclSerialPort_RegisterCallback(uart_handle, &Uart_Drv_Handler);
					DclSerialPort_Control(uart_handle,SIO_CMD_INIT,(DCL_CTRL_DATA_T *)&data_init);
}
#ifdef __USB_BOOTUP_TRACE__
	if (debug_port>=uart_port_usb && debug_port<=uart_port_usb3)
			  {
				data.u4OwenrId = MOD_DRV_HISR;	
				data_init.u4Flag = KAL_TRUE;
	
				uart_handle =  DclSerialPort_Open(debug_port, 0);
				DclSerialPort_RegisterCallback(uart_handle, &USB2Uart_Drv_Handler);
				DclSerialPort_Control(uart_handle,SIO_CMD_INIT,(DCL_CTRL_DATA_T *)&data_init);
				DclSerialPort_Control(uart_handle,SIO_CMD_OPEN,(DCL_CTRL_DATA_T *)&data);
}
#endif	//__USB_BOOTUP_TRACE__


}




void UART_Boot_Trace_Release(kal_bool flag)//flag = 1 :  open VFIFO when TST init   TST inti call this function  . only when uart bootup trace
{
    if (flag == KAL_TRUE)//TST init     open vfifo
    {
      if(debug_port > uart_port3)//debug_port maybe USB port
	     return;
	   UART_DriverInit(debug_port,UART_BOOTUP_TRACE_OPEN_VFIFO);
    }

}



extern int DMA_Vfifo_SetChan(UART_PORT port);
void UART_DriverInit(UART_PORT port,kal_uint32 flag)
{
//		kal_bool ret;
		module_type ownerid;
		static kal_bool b_uart_custom_init = KAL_FALSE;
		kal_bool Is_OpenUart = KAL_TRUE;
		
		ownerid = (module_type)(MOD_UART1_HISR + port);
			
#if defined( DRV_UART_DMA_ENABLE_HANG_BUG)
U_Purge(port, TX_BUF, UARTPort[port].ownerid);/*clear sw TX FIFO*/
#endif
			
#if !defined(__UART3_SUPPORT__)
		   if(port == uart_port3)
			  return;
#endif	
		// Customization 
		if(b_uart_custom_init == KAL_FALSE)
			{
		  uart_customize_init();
				b_uart_custom_init = KAL_TRUE;
			}
		 

#if defined(DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS)
Is_OpenUart = KAL_FALSE;

if(port == uart_port1)
{
	if(UartPortOwnedByMD[port]
			#if defined(__SMART_PHONE_MODEM__)
		&& (kal_query_boot_mode()!= FACTORY_BOOT)
	#endif
	)
		Is_OpenUart = KAL_TRUE;

}
else if (UartPortOwnedByMD[port] )
	Is_OpenUart = KAL_TRUE;
else
	Is_OpenUart = KAL_FALSE;

#endif

if(Is_OpenUart == KAL_TRUE)
	{
UART_Driver_open_close_vfifo(port,flag);

#ifdef __DMA_UART_VIRTUAL_FIFO__
	     DMA_Vfifo_SetChan(port);//enable DMA interrupt
#endif

	
UART_HWInit(port);

 U_Open(port,(module_type)(MOD_UART1_HISR + port));

// Register the default callback function
U_Register_TX_cb(port, ownerid, UART_dafault_tx_cb);
U_Register_RX_cb(port, ownerid, UART_dafault_rx_cb);
}

}


#else //#if !defined(DRV_UART_OFF)

UARTStruct UARTPort[MAX_UART_PORT_NUM];

kal_bool UART_VFIFO_support[MAX_UART_PORT_NUM] =
{
   KAL_FALSE,
      KAL_FALSE,
#ifdef __UART3_SUPPORT__
      KAL_FALSE
#endif   /*__UART3_SUPPORT__*/
};
void UART_Boot_PutUARTBytes(UART_PORT port, kal_uint8 *data,kal_uint16 len){}
void U_Register(UART_PORT port, UartType_enum type, UartDriver_strcut* drv){}
kal_bool U_Open(UART_PORT port, module_type ownerid){}
void U_Close(UART_PORT port, module_type ownerid){}
kal_uint16 U_GetBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid){}
kal_uint16 U_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid){}
kal_uint16 U_GetBytesAvail(UART_PORT port){}
kal_uint16 U_GetTxRoomLeft(UART_PORT port){}
kal_uint16 U_PutISRBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid){}
kal_uint16 U_GetTxISRRoomLeft(UART_PORT port){}
kal_uint16 U_SendISRData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode, kal_uint8 escape_char, module_type ownerid){}
kal_uint16 U_SendData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid ){}
void U_Purge(UART_PORT port, UART_buffer dir, module_type ownerid){}
void U_SetOwner (UART_PORT port, module_type ownerid){}
void U_SetFlowCtrl(UART_PORT port, kal_bool XON, module_type ownerid){}
void U_ConfigEscape (UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid){}
void U_SetDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid){}
void U_CtrlDCD(UART_PORT port, IO_level SDCD, module_type ownerid){}
void U_CtrlBreak(UART_PORT port, IO_level SBREAK, module_type ownerid){}
void U_ClrRxBuffer(UART_PORT port, module_type ownerid){}
void U_ClrTxBuffer(UART_PORT port, module_type ownerid){}
void U_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type ownerid){}
module_type U_GetOwnerID(UART_PORT port){}
void U_SetAutoBaud_Div(UART_PORT port, module_type ownerid){}
void U_Register_TX_cb(UART_PORT port, module_type ownerid, UART_TX_FUNC func){}
void U_Register_RX_cb(UART_PORT port, module_type ownerid, UART_RX_FUNC func){}
kal_uint8 U_GetUARTByte(UART_PORT port){}
kal_uint8 U_GetUARTByteWithTimeOut(UART_PORT port, kal_uint8* ch, kal_uint32 timeout_value){return 0;}
void U_PutUARTByte(UART_PORT port, kal_uint8 data){}
void U_PutUARTBytes(UART_PORT port, kal_uint8 *data, kal_uint16 len){}
void U_ReadDCBConfig(UART_PORT port, UARTDCBStruct *DCB){}
void U_CtrlRI (UART_PORT port, IO_level SRI, module_type ownerid){}
void U_CtrlDTR (UART_PORT port, IO_level SDTR, module_type ownerid){}
void U_ReadHWStatus(UART_PORT port, IO_level *SDSR, IO_level *SCTS){}
void UART_AssertWaitPrevDataSentOut(UART_PORT port){}
void UART_Calback(void *parameter){}
void UART_CheckAT_Callback(void *parameter){}
kal_bool UART_CheckTxAllSentOut(UART_PORT port){}
kal_bool UART_CheckTxBufferEmpty(UART_PORT port){}
void UART_CompensateAT(UART_PORT  port){}
void uart_customize_init(void){}
void UART_dafault_rx_cb(UART_PORT port){}
void UART_dafault_tx_cb(UART_PORT port){}
void UART_DriverInit(UART_PORT port,kal_uint32 flag){}
void UART_EnableTX(UART_PORT port, kal_bool enable){}
void UART_GetTxBufferSize(UART_PORT port, kal_uint32 *total_size, kal_uint32 *rest_size){}
void UART_HWInit(UART_PORT port){}
kal_bool UART_IsVfifoSetting(UART_PORT port, UART_TxRx_VFIFO_support vs){}
void UART_RecHandler(void *parameter){}
void UART_MsHandler(void *parameter){}
void UART_RLSHandler(void *parameter){}
void UART_sendilm(UART_PORT port, msg_type msgid){}
void UART_set_FIFO_trigger(UART_PORT port, kal_uint16 tx_level, kal_uint16 rx_level){}
void UART_SetRateFix(UART_PORT  port){}
void UART_SetSleepEnable(kal_bool enable){}
void UART_SleepOnTx_Enable(UART_PORT port, UART_SLEEP_ON_TX enable_flag){}
kal_bool uart_support_autoescape(void){}
void UART_SwitchPort(UART_PORT *APP_port, UART_PORT new_uart_port){}
void UART_TrxHandler(void *parameter){}
void UART_TurnOnPower(UART_PORT port, kal_bool enable){}
void UART1_HISR(void){}
void UART2_HISR(void){}
void UART3_HISR(void){}
void PutUARTDatas(UART_PORT port, kal_uint8 escape_char, kal_uint8 *data,kal_uint16 len){}
kal_uint16 BMT_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length){}
void PutUARTRingBufferData(UART_PORT port){}
void UART_loopback(UART_PORT port){}
void UART_dsp_dafault_tx_cb(UART_PORT port){}
void UART_dsp_dafault_rx_cb(UART_PORT port){}
void UART_Boot_Trace_Release(kal_bool flag){}//for uart bootup trace

#endif //if !defined(DRV_UART_OFF)


// uart dispatch funtion table
UartDriver_strcut UartDriver=
{
   U_Open,
      U_Close,
      U_GetBytes,
      U_PutBytes,
      U_GetBytesAvail,
      U_GetTxRoomLeft,
      U_PutISRBytes,
      U_GetTxISRRoomLeft, 
      U_Purge,
      U_SetOwner,
      U_SetFlowCtrl,
      U_ConfigEscape,
      U_SetDCBConfig,
      U_CtrlDCD,
      U_CtrlBreak,
      U_ClrRxBuffer,
      U_ClrTxBuffer,
      U_SetBaudRate,
      U_SendISRData,
      U_SendData,
      U_GetOwnerID,
      U_SetAutoBaud_Div,
      /*TY adds these to expand flexibility 2004/10/15*/
      U_Register_TX_cb,        
      U_Register_RX_cb,
      /*TY adds these to let virtual COM port can retrive exception log 2005/3/8*/
      U_GetUARTByte,
      U_PutUARTByte,
      U_PutUARTBytes,
      /*for virtual com port to return DCB configuration*/
      U_ReadDCBConfig,
      U_CtrlRI,
      U_CtrlDTR,
      U_ReadHWStatus,
      U_GetUARTByteWithTimeOut
};

#endif // #if !defined(TK6516)

