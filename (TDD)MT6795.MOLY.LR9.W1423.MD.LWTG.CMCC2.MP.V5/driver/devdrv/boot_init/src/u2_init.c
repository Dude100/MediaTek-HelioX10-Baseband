/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#if defined(MT6290)
#include "kal_general_types.h"
#include "drvpdn.h"

//#define BASE_ADDR_U2PHY        0xBEB00000
#define P1_PHY_OFFSET          0x800

//register offset
#define U2PHYDTM0   0x68
#define U2PHYDTM1   0x6C
#define U2PHYDCR0   0x60
#define USBPHYACR6  0x18


//bit define
#define USB20_FORCE_UART_ENABLE  0x04
#define USB20_RG_UART_ENABLE     0x01
#define USB20_RG_USB_SUSPENDM    0x08
#define USB20_FORCE_USB_SUSPENDM 0x04
#define USB20_RG_DP_PULLDOWN     0x40
#define USB20_RG_DM_PULLDOWN     0x80
#define USB20_RG_XCVRSEL         0x10
#define USB20_RG_USB_TERMSEL     0x04
#define USB20_RG_USB_DATAIN      0x3C
#define USB20_FORCE_DM_PULLDOWN  0x20
#define USB20_FORCE_DP_PULLDOWN  0x10
#define USB20_FORCE_USB_XCERSEL  0x08
#define USB20_FORCE_USB_TERMSEL  0x02
#define USB20_FORCE_USB_DATAIN   0x80
#define USB20_RG_BC11_SW_EN      0x80
#define USB20_RG_OTG_VBUSCMP_EN  0x10
#define USB20_RG_DP_RPU_MODE     0x20
#define USB20_RG_PLL_STABLE      0x02





#define MGC_WritePhy8(_offset,_data) (*((volatile unsigned char *)(BASE_ADDR_U2PHY + P1_PHY_OFFSET + (_offset))) = (unsigned char)(_data))
#define MGC_ReadPhy8(_offset)  (*((volatile unsigned char *)(BASE_ADDR_U2PHY + P1_PHY_OFFSET + (_offset))))
#endif


/*******************************************************************************
 * Function definitions
 *******************************************************************************/
void boot_init_u2_clock()
{
#if defined(MT6290)
#if defined(__SMART_PHONE_MODEM__) && !defined(__X_BOOTING__)
	    //U2 in router product will be controlled by AP
#elif defined(USB20_PURE_DMA) || (USB20_DMA_SIM_QMU)
#else
		//U2 port will not be used in phone/dongle product, so power down it in bootloader.

         //switch to usb function
         MGC_WritePhy8(U2PHYDTM0 +3, MGC_ReadPhy8(U2PHYDTM0 + 3)&(~USB20_FORCE_UART_ENABLE));
         MGC_WritePhy8(U2PHYDTM1 +2, MGC_ReadPhy8(U2PHYDTM1 + 2)&(~USB20_RG_UART_ENABLE));

         //release force suspend
         MGC_WritePhy8(U2PHYDTM0, MGC_ReadPhy8(U2PHYDTM0)|(USB20_RG_USB_SUSPENDM));
         MGC_WritePhy8(U2PHYDTM0 +2 , MGC_ReadPhy8(U2PHYDTM0 +2)|(USB20_FORCE_USB_SUSPENDM));

         //kal_sleep_task(1);

         //RG_DPPULLDOWN RG_DMPULLDOWN
         MGC_WritePhy8(U2PHYDTM0, MGC_ReadPhy8(U2PHYDTM0)|(USB20_RG_DP_PULLDOWN | USB20_RG_DM_PULLDOWN));

         //RG_XCVRSEL[1:0] = 01
         MGC_WritePhy8(U2PHYDTM0, MGC_ReadPhy8(U2PHYDTM0)&(~0x30));
         MGC_WritePhy8(U2PHYDTM0, MGC_ReadPhy8(U2PHYDTM0)|(USB20_RG_XCVRSEL));

         //RG_TERMSEL = 1
         MGC_WritePhy8(U2PHYDTM0, MGC_ReadPhy8(U2PHYDTM0)|(USB20_RG_USB_TERMSEL));

         //RG_DATAIN = 0
         MGC_WritePhy8(U2PHYDTM0 +1, MGC_ReadPhy8(U2PHYDTM0 +1)&(~USB20_RG_USB_DATAIN));

         //force_dp_pulldown,force_dm_pulldown,force_xcersel,force_termsel
         MGC_WritePhy8(U2PHYDTM0 + 2, MGC_ReadPhy8(U2PHYDTM0 +2)|(USB20_FORCE_USB_DATAIN | USB20_FORCE_DM_PULLDOWN
								 | USB20_FORCE_DP_PULLDOWN | USB20_FORCE_USB_XCERSEL |  USB20_FORCE_USB_TERMSEL));

         //RG_USB20_BC11_SW_EN=0
         MGC_WritePhy8(USBPHYACR6 +2, MGC_ReadPhy8(USBPHYACR6 +2)&(~USB20_RG_BC11_SW_EN));
         //RG_USB20_OTG_VBUSCMP_EN=0
         MGC_WritePhy8(USBPHYACR6 +2, MGC_ReadPhy8(USBPHYACR6 +2)&(~USB20_RG_OTG_VBUSCMP_EN));
	     //RG_DP_RPU_MODE = 1
	     MGC_WritePhy8(USBPHYACR6 +2, MGC_ReadPhy8(USBPHYACR6 +2)|(USB20_RG_DP_RPU_MODE));
         //kal_sleep_task(1);
         //RG_USB20_PLL_STABLE=1
         MGC_WritePhy8(U2PHYDCR0 +3, MGC_ReadPhy8(U2PHYDCR0 +3)|(USB20_RG_PLL_STABLE));

         //kal_sleep_task(1);

         //force suspend=1
         MGC_WritePhy8(U2PHYDTM0,MGC_ReadPhy8(U2PHYDTM0)&(~USB20_RG_USB_SUSPENDM));
         //kal_sleep_task(1);

		 IPCG_SET(IPCG_U2);
		 PDN_SET(PDN_U2);

#endif
#endif
}
