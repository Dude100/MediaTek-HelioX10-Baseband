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
 *    usbdl_b2psi.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines baseband to PMIC interface
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include    "drv_features.h"
//#include 	"kal_release.h"
//#include 	"stack_common.h"  
//#include 	"stack_msgs.h"
//#include 	"app_ltlcom.h"       /* Task message communiction */
#include 	"drv_comm.h"
//#include    "drvsignals.h"
#include 	"reg_base.h"
#include 	"pmic6318_hw.h"
#include 	"b2psi_hw.h"
//#include 	"intrCtrl.h"
//#include	   "stack_ltlcom.h"       /*msg_send_ext_queue.....definitions*/
//#include	   "stack_config.h"        /*MOD_UART1_HISR,MOD_UART2_HISR*/
#include    "drvpdn.h"
#include 	"gpio_hw.h"
#include 	"gpio_sw.h"
//#include    "lpwr.h"

#if  defined(PMIC_B2SPI_INTERFACE)

#define B2PSI_INTERNAL_SRAM
#define B2PSI_DRVPDN_FAST

/*only for superman29 wrong layout*/
#if (defined(SUPERMAN29_DEMO_BB)&&defined(PCB01))
   #ifdef __CUST_NEW__
      #define B2PSI_CS_PIN    (GPIO_MAGIC_NUM|24)
   #else
      #define B2PSI_CS_PIN    24
   #endif
#endif
#if defined(MCU_104M)
#define B2SPI_WAIT_CNT     10
#else
#define B2SPI_WAIT_CNT     5
#endif

void B2PSI_write_fast(kal_uint8 data, kal_uint16 register_index)
{
#ifdef  __USB_DOWNLOAD__
   kal_uint16     write_data=0;   
   kal_uint16     i, status=0;
//   extern kal_uint8 pmic_reg_save[];
   
#if defined(__DRV_B2SPI_SHARE_PIN__)
	b2spi_serial_lock();
	B2PSI_init_sharePin();	
#endif   
   

   write_data=(register_index|B2PSI_WRITE_MASK|data);         
   DRV_WriteReg(DRVPDN_CON1+0x20,(kal_uint16)DRVPDN_CON1_B2SPI);
#if (defined(SUPERMAN29_DEMO_BB)&&defined(PCB01))
   GPIO_WriteIO(0, B2PSI_CS_PIN);
   for(debug_loop=0;debug_loop<debug_loop_cnt;debug_loop++){};
#endif
   //L1D_MeasureMaxDuration_Start( &b2psi_duration );
   DRV_WriteReg(B2PSI_DATA,B2PSI_DATA_KEY);   
#if (defined(SUPERMAN29_DEMO_BB)&&defined(PCB01))
   GPIO_WriteIO(1, B2PSI_CS_PIN);
#endif
   /*this short loop is becasue B2PSI needs this to change his state machine*/
   for(i=0;i<B2SPI_WAIT_CNT;i++){}   
#if (defined(SUPERMAN29_DEMO_BB)&&defined(PCB01))
   GPIO_WriteIO(0, B2PSI_CS_PIN);
   for(debug_loop=0;debug_loop<debug_loop_cnt;debug_loop++){};
#endif
   DRV_WriteReg(B2PSI_DATA,write_data); 
   //L1D_MeasureMaxDuration_Stop( &b2psi_duration );
   /*write data to reg_save*/     
   //pmic_reg_save[(register_index>>PMIC_SHIFT_BITS)]=data;
   //dbg_data=data;
   //dbg_index=register_index;  
   do 
   {
      status=DRV_Reg(B2PSI_STAT);       
   }
   while(!(status&=0x2));
#if (defined(SUPERMAN29_DEMO_BB)&&defined(PCB01))
   GPIO_WriteIO(1, B2PSI_CS_PIN);
#endif
    
#if defined(__DRV_B2SPI_SHARE_PIN__)
	serial_init_sharePin();
	b2spi_serial_unlock();
#endif

   DRV_WriteReg(DRVPDN_CON1+0x10,(kal_uint16)DRVPDN_CON1_B2SPI);
#endif  /* __USB_DOWNLOAD__ */
}

#endif/*PMIC_B2SPI_INTERFACE*/


