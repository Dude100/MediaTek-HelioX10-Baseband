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
 *    usb_phy_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements usb phy hardware related functions
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
 * removed!
 * removed!
 * removed!
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "kal_non_specific_general_types.h"
#include "drv_features.h"
#include "drv_comm.h"
#include "reg_base.h"
//#include "config_hw.h"
#include "init.h"
//#include "drvpdn.h"
//#include "drv_hisr.h"
//#include "gpio_sw.h"
//#include "upll_ctrl.h"

#include "usb_hw.h"
#include "usb_drv.h"
//#include "usb_drv_pri.h"
#include "usb_phy_drv.h"
#include "usb_custom.h"

#ifdef __OTG_ENABLE__
//#include "stack_common.h"        /* sap_type */
//#include "stack_msgs.h"                /* msg_type */
//#include "app_ltlcom.h"       /* Task message communiction */
//#include "otg_drv.h"
//#include "otg_if.h"
//#include "usb_hcd.h"
//#include "usb_hcd_pri.h"
#endif

//#include "usb_debug_tool.h"
//#include "usb_trc.h"

#include "dcl.h"
#include "dcl_pmic_features.h"
#include "kal_general_types.h"

#if defined(__USB_BOOTUP_TRACE__)
extern kal_bool is_init_log_enable;
extern kal_bool is_init_stage;
#endif

#if defined(__USB_ENABLE__) && !defined(DRV_USB_OFF)
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

#if defined(DRV_USB_PHY_CURRENT_CONSUMPTION)
void USB_Save_Current_Consumption(void);
void USB_Recover_Current_Consumption(void);
#endif  //DRV_USB_PHY_CURRENT_CONSUMPTION

#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
void USB_PHY_Charger_Detect_Init(void);
void USB_PHY_Check_Standard_Charger(void);
void USB_PHY_Charger_Detect_Release(void);
#endif //__CHARGER_USB_DETECT_WIHT_ONE_EINT__

#endif //(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
#endif //__USB_ENABLE__


#if defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V2)||defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

#if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
void USB_UART_Share(kal_bool usb_mode)
{	
#ifdef DRV_USB_PHY_USB_UART_SHARE_PAD  //USB IP3

#if defined(__USB_ENABLE__) && !defined(DRV_USB_OFF)

#if (defined(DRV_USB_PHY_COST_DOWN)) 

	if(usb_mode)
	{
#ifdef DRV_USB_SHARE_PAD_UART_DL //MT6236 UART Mode Download, change initial setting for USB use.
		USB_DRV_WriteReg8(USB_PHYCR3_2, USB_PHY_CLEAR_MASK); 
#if defined(DRV_MT6236_VERSION_CONTROL)
		USB_DRV_WriteReg8(USB_PHYCR5_3, USB_PHYCR5_3_SUSPENDM); 
#else
		USB_DRV_WriteReg8(USB_PHYCR5_3, USB_PHY_CLEAR_MASK); 	
#endif
#endif  //DRV_USB_SHARE_PAD_UART_DL

//switch USB / UART
		USB_DRV_WriteReg8(USB_PHYCR4_0, USB_PHYCR4_0_FORCE_USB_CLKOFF|USB_PHYCR4_0_FORCE_IDDIG); 
		USB_DRV_WriteReg8(USB_PHYCR3_3, USB_PHY_CLEAR_MASK);
  	}
/*Disable USB_UART share pad function  	
  Save current flow (USB mode) -> cannot change register setting  */   	
//  	else
//  	{
//		USB_DRV_WriteReg8(USB_PHYCR3_2, USB_PHYCR3_2_FORCE_DP_DM_PULLDOWN); 
//#if defined(DRV_MT6236_VERSION_CONTROL)
//		USB_DRV_WriteReg8(USB_PHYCR5_3, USB_PHYCR5_3_TERM_SELECT|USB_PHYCR5_3_SUSPENDM);
//#else
//		USB_DRV_WriteReg8(USB_PHYCR5_3, USB_PHYCR5_3_TERM_SELECT);
//#endif
//		USB_DRV_WriteReg8(USB_PHYCR3_3, USB_PHYCR3_3_FORCE_TERM_SELECT|USB_PHYCR3_3_FORCE_SUSPENDM); 
//		USB_DRV_WriteReg8(USB_PHYCR4_0, USB_PHYCR4_0_FORCE_AUX_EN|USB_PHYCR4_0_FORCE_OTG_PROBE);
//  	}
#elif (defined(DRV_USB_PHY_U65_IP))  

#elif (defined(DRV_USB_PHY_M60_IP))  

#elif (defined(DRV_USB_PHY_U40_IP)) 

#elif (defined(DRV_USB_PHY_T28_IP)) 

#else   //Old PHY version

  	if (usb_mode)
  	{
  		USB_DRV_WriteReg8(USB_PHYIR2_3, USB_PHYIR2_3_FORCE_USB_CLKOFF);
  		USB_DRV_WriteReg8(USB_PHYCR5_2, USB_PHY_CLEAR_MASK);
  	}
  	else
  	{
  		USB_DRV_WriteReg8(USB_PHYIR2_3, USB_PHYIR2_3_FORCE_AUX_EN);
  		USB_DRV_WriteReg8(USB_PHYCR5_2, USB_PHYCR5_2_FORCE_SUSPENDM);
  	}

#endif  	// PHY Version

#endif  //USB Enable
  	
#else    //USB IP1 IP2 
     PMIC_Power_Control(KAL_FALSE);

     if (usb_mode)
     {
	   	UART_and_USB_Switch(KAL_TRUE);
     }
     else
     {
	   	UART_and_USB_Switch(KAL_FALSE);
     }
#endif
}
#endif  // defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
#endif //(defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V2)||defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))



#if defined(__USB_ENABLE__) && !defined(DRV_USB_OFF)
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

void USB_HS_Slew_Rate_Cal(void)
{
#ifdef	__USB_HS_SLEW_RATE_CAL__
    double freq, x;
    kal_uint32 data = 0, b;
    kal_uint32 timeout = 0;

#if (defined(DRV_USB_PHY_U65_IP))  
    //enable USB ring oscillator, RG_USBRESERVED[6] = 1
    USB_DRV_SetBits8(USB_U2PHYACR3_1, USB_U2PHYACR3_2_RG_USBRESERVED_6);
    //RG_USB_CLKEN = 1
    USB_DRV_SetBits8(USB_U2PHYDCR1_2, USB_U2PHYDCR1_2_RG_USB_CLKEN);
    //RG_SUSPENDM = 1
    //USB_DRV_SetBits8(USB_U2PHYDTM0_0, USB_U2PHYDTM0_0_RG_SUSPENDM);
#elif defined(DRV_USB_PHY_M60_IP)||defined(DRV_USB_PHY_U40_IP)
	//enable USB ring oscillator
    USB_DRV_SetBits32(USB_U2PHYACR0, USB_U2PHYACR0_RG_USB20_HSTX_SRCAL_EN);  
    //Enable free run clock 
    USB_DRV_SetBits32(USB_FMMONR1, USB_FMMONR1_RG_FRCK_EN);  
#endif

	//RG_MONCLK_SEL = 00, 60MHz clock
    USB_DRV_WriteReg32(USB_FMCR0, (1 << 28) | (1 << 24) | (USB_HS_SLEW_RATE_CAL_TIME_WINDOW));

    //check USB_FM_VLD
    while ((USB_DRV_Reg32(USB_FMMONR1) & 0x1) != 0x1) {
        timeout++;
        if (timeout == 500)
        	break;
    }
    
    data = USB_DRV_Reg32(USB_FMMONR0);
    freq = (double) ((48 * USB_HS_SLEW_RATE_CAL_TIME_WINDOW) / (double)data);
    x = USB_HS_SLEW_RATE_CAL_A * freq / USB_HS_SLEW_RATE_CAL_FRA;
    b = (int)(x + 0.5);

#if (defined(DRV_USB_PHY_U65_IP))  
    //RG_HSTX_SRCTRL[2:0]
    USB_DRV_ClearBits8(USB_U2PHYACR1_1, USB_U2PHYACR1_1_RG_HSTX_SRCTRL_MASK);
    USB_DRV_SetBits8(USB_U2PHYACR1_1, b & 0x7);
    //disable FREQDET_EN
    USB_DRV_WriteReg32(USB_FMCR0, USB_DRV_Reg32(USB_FMCR0) & 0xFEFFFFFF);
    //disable USB ring oscillator, RG_USBRESERVED[6] = 0
    USB_DRV_ClearBits8(USB_U2PHYACR3_1, USB_U2PHYACR3_2_RG_USBRESERVED_6);
#elif defined(DRV_USB_PHY_M60_IP)||defined(DRV_USB_PHY_U40_IP)
    //Disable free run clock 
    USB_DRV_WriteReg32(USB_FMCR0, USB_DRV_Reg32(USB_FMCR0) & 0xFEFFFFFF);
    USB_DRV_ClearBits32(USB_FMMONR1, USB_FMMONR1_RG_FRCK_EN);    
	USB_DRV_WriteReg32(USB_U2PHYACR0, (USB_DRV_Reg32(USB_U2PHYACR0)&~USB_U2PHYACR0_RG_USB20_HSTX_SRCTRL_CLR)|((b & 0x7) << 16)); 
	//Disable USB ring oscillator	
    USB_DRV_ClearBits32(USB_U2PHYACR0, USB_U2PHYACR0_RG_USB20_HSTX_SRCAL_EN);  
#endif

#endif //__USB_HS_SLEW_RATE_CAL__
}


void USB_Eye_Setting_Customize(void)  //performance tuning
{
#ifdef DRV_USB_PHY_COST_DOWN  //focus on PHY setting
	kal_uint8 Custom_IADJ = 0xFF; 
	kal_uint8 Custom_HS_TERMC = 0xFF; 	
	
	if(Custom_IADJ != 0xFF)
	{	
		USB_DRV_ClearBits8(USB_PHYCR1_0,USB_PHYCR1_0_IADJ_MASK);
		USB_DRV_SetBits8(USB_PHYCR1_0, Custom_IADJ<<4); //Bit[6:4]
	}
	if(Custom_HS_TERMC != 0xFF)
	{				
		USB_DRV_ClearBits8(USB_PHYIR4_0,USB_PHYIR4_0_HS_TERMC_MASK);
		USB_DRV_SetBits8(USB_PHYIR4_0, Custom_HS_TERMC<<4);	//Bit[6:4]
	}
#elif (defined(DRV_USB_PHY_U65_IP))  

#elif defined(DRV_USB_PHY_M60_IP)

#elif defined(DRV_USB_PHY_U40_IP)  

#elif defined(DRV_USB_PHY_T28_IP)  

#else	 //Old PHY version
	kal_uint8 Custom_IADJ = 0xFF;
	kal_uint8 Custom_HS_TERMC = 0xFF; 	
	
	if(Custom_IADJ != 0xFF)
	{	
		USB_DRV_ClearBits8(USB_PHYCR3_0,USB_PHYCR3_0_IADJ_MASK);
		USB_DRV_SetBits8(USB_PHYCR3_0, Custom_IADJ); //Bit[2:0]
	}
	if(Custom_HS_TERMC != 0xFF)
	{				
		USB_DRV_ClearBits8(USB_PHYCR2_3,USB_PHYCR2_3_HS_TERMC_MASK);
		USB_DRV_SetBits8(USB_PHYCR2_3, Custom_HS_TERMC);	//Bit[4:0]
	}
	
#endif
}

void USB_PHY_Initialize(void)
{
		volatile kal_uint32 delay;
#if defined(DRV_USB_PHY_U65_IP)
		DCL_HANDLE handle;
		PMU_CTRL_CHR_SET_BC11_PULLUP_EN val;
#endif		
		#if defined(DRV_USB_IP_V3)
		USB_DRV_Reg8(USB_DUMMY);
		#endif
		
#if (defined(DRV_USB_PHY_COST_DOWN)) 

		for(delay = 0; delay < 1000; delay++);
			
		USB_DRV_WriteReg8(USB_PHYCR2_3, USB_PHYCR2_3_PLL_EN);//PLL enable
		
		//========initial value=======//
#if defined(DRV_MT6253_VERSION_CONTROL) //6253 MP
	if (INT_ecoVersion() == ECO_E8) 
	{
		/*only E8 needs this setting, E9 and others version use default value*/
		USB_DRV_WriteReg8(USB_PHYCR3_0, USB_PHYCR3_0_CDR_FILT); 
	}
	else
	{	
		USB_DRV_WriteReg8(USB_PHYCR3_0, (USB_PHYCR3_0_HS_TX_ANA_SER_EN|USB_PHYCR3_0_CDR_FILT));	
	}	
#elif defined(DRV_MT6253D_VERSION_CONTROL) //6253D MP
	if (INT_ecoVersion() == ECO_E1) 
	{
		USB_DRV_WriteReg8(USB_PHYCR3_0, USB_PHYCR3_0_CDR_FILT); 
	}
	else
	{	
		USB_DRV_WriteReg8(USB_PHYCR3_0, (USB_PHYCR3_0_HS_TX_ANA_SER_EN|USB_PHYCR3_0_CDR_FILT));	
	}	
#else
		USB_DRV_WriteReg8(USB_PHYCR3_0, (USB_PHYCR3_0_HS_TX_ANA_SER_EN|USB_PHYCR3_0_CDR_FILT));			
#endif   //MT6253
		
		USB_DRV_WriteReg8(USB_PHYIR4_2, (USB_PHYIR4_2_RG_HSTX_DBIST0|USB_PHYIR4_2_RG_HSTX_SRCTRL0));
		USB_DRV_WriteReg8(USB_PHYIR1_1, USB_PHYIR1_1_RG_DM1_ABIST_SELE);
		USB_DRV_WriteReg8(USB_PHYIR5_1, USB_PHYIR5_1_RG_SQTH0);
				
#if defined(DRV_USB_PHY_65_INITIAL_VALUE) //6268 MP		
		USB_DRV_ClearBits8(USB_PHYIR4_3, 0x01); // bit[1:0] = 2'b 10 
		USB_DRV_SetBits8(USB_PHYIR4_3, USB_PHYIR4_3_RG_DISCD);//Host mode
		
//MT6268  remove Vbus  resistor only for Device mode
#ifndef __OTG_ENABLE__
		USB_DRV_WriteReg8(USB_PHYCR4_0, 0x3F);//Device mode [60C] = 0x3F
		USB_DRV_ClearBits8(USB_PHYIR3_2, 0x1F); //bit[4:0] = 0x1D;
		USB_DRV_SetBits8(USB_PHYIR3_2, 0x1D); //Device mode [61E] = 0xFD
#endif		
		
#elif defined(DRV_USB_PHY_M110_INITIAL_VALUE) //6253 MP
		// VRT voltage threshold 
		USB_DRV_ClearBits8(USB_PHYCR1_0, USB_PHYCR1_0_IADJ_MASK);
		USB_DRV_SetBits8(USB_PHYCR1_0, USB_PHYCR1_0_IADJ_MASK3);
		USB_DRV_ClearBits8(USB_PHYIR4_0, USB_PHYIR4_0_HS_TERMC_MASK);
		USB_DRV_SetBits8(USB_PHYIR4_0, USB_PHYIR4_0_RG_CALIB_SELE0);
#endif
		
		USB_Eye_Setting_Customize();
		
		USB_DRV_WriteReg8(USB_PHYIR6_0, USB_PHY_CLEAR_MASK);//remove DM 100K (UART function)			
		USB_DRV_WriteReg8(USB_PHYIR6_1, (USB_PHYIR6_1_BGR_DIV_L|USB_PHYIR6_1_RG_OTG_VBUSTH|USB_PHYIR6_1_VBUSCMP_EN)); //Vbus_Cmp_Enable

#elif (defined(DRV_USB_PHY_U65_IP))  
	//USB_DRV_WriteReg8(USB_U2PHYDCR1_2,USB_U2PHYDCR1_2_RG_USB_CLKEN);
	USB_DRV_ClearBits8(USB_U2PHYDTM0_3,USB_U2PHYDTM0_3_FORCE_UART_EN);
	USB_DRV_ClearBits8(USB_U2PHYDCR1_2,USB_U2PHYDCR1_2_RG_UART_EN);
	USB_DRV_SetBits8(USB_U2PHYDCR1_2,USB_U2PHYDCR1_2_RG_USB_CLKEN);
	//========initial value ======
	USB_DRV_ClearBits8(USB_U2PHYDCR0_0,USB_U2PHYDCR0_0_RG_EARLY_HSTX_I);
	USB_DRV_SetBits8(USB_U2PHYDCR0_0,USB_U2PHYDCR0_0_RG_HSTX_ANA_SER_EN);
	USB_DRV_ClearBits8(USB_U2PHYACR3_2,USB_U2PHYACR3_2_RG_USBRESERVED_10);
	
#if defined(__USB_BOOTUP_TRACE__)
	if (!(is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE))
#endif
	{
		val.enable=KAL_TRUE;
		handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
		DclPMU_Control(handle, CHR_SET_BC11_PULLUP_EN, (DCL_CTRL_DATA_T *)&val);
		DclPMU_Close(handle);
	}
	
	USB_DRV_WriteReg8(USB_U2PHYACR1_1,((USB_DRV_Reg8(USB_U2PHYACR1_1)& 0xF8)|USB_U2PHYACR1_1_RG_HSTX_SRCTRL));
	USB_DRV_WriteReg8(USB_U2PHYACR0_0,((USB_DRV_Reg8(USB_U2PHYACR0_0)& 0xF0)|USB_U2PHYACR0_0_RG_LS_CROSS|USB_U2PHYACR0_0_RG_FS_CROSS));
	USB_DRV_WriteReg8(USB_U2PHYACR2_0,((USB_DRV_Reg8(USB_U2PHYACR2_0)& 0xF8)|USB_U2PHYACR2_0_RG_SQTH));
	USB_DRV_WriteReg8(USB_U2PHYACR2_0,((USB_DRV_Reg8(USB_U2PHYACR2_0)& 0x0F)|USB_U2PHYACR2_0_RG_SQB|USB_U2PHYACR2_0_RG_RCVB));	
	USB_DRV_WriteReg8(USB_U2PHYACR1_2,((USB_DRV_Reg8(USB_U2PHYACR1_2)& 0xFC)|USB_U2PHYACR1_2_RG_DISCD));
	USB_DRV_WriteReg8(USB_U2PHYAC0_2,((USB_DRV_Reg8(USB_U2PHYAC0_2)& 0xC0)|USB_U2PHYAC0_2_RG_PLL_DIV));
	//remove 100K
	//USB_DRV_WriteReg8(USB_U2PHYDTM0_2,0x00);
	USB_DRV_ClearBits8(USB_U2PHYACR2_3,USB_U2PHYACR2_3_RG_DM_100K_EN);
	USB_DRV_ClearBits8(USB_U2PHYACR2_3,USB_U2PHYACR2_3_RG_DP_100K_EN);
	//====================
	USB_DRV_ClearBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_SUSPENDM);
	USB_DRV_SetBits8(USB_U2PHYACR2_3,USB_U2PHYACR2_3_RG_OTG_VBUSCMP_EN);
	
	for(delay = 0; delay < 1000; delay++);
		
	USB_HS_Slew_Rate_Cal();
	
#elif defined(DRV_USB_PHY_M60_IP)||defined(DRV_USB_PHY_U40_IP)
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_uart_en);
	USB_DRV_ClearBits32(USB_U2PHYDTM1, USB_U2PHYDTM1_RG_UART_EN);
	USB_DRV_ClearBits32(USB_U2PHYACR3, USB_U2PHYACR3_RG_USB20_PHY_REV_7);
	USB_DRV_WriteReg32(USB_U2PHYAC0, (USB_DRV_Reg32(USB_U2PHYAC0)&~USB_U2PHYAC0_RG_USB20_USBPLL_FBDIV_6_0_CLR)|USB_U2PHYAC0_RG_USB20_USBPLL_FBDIV_6_0);
	USB_DRV_ClearBits32(USB_U2PHYACR4, USB_U2PHYACR4_RG_USB20_DP_100K_EN);
	USB_DRV_ClearBits32(USB_U2PHYACR4, USB_U2PHYACR4_RG_USB20_DM_100K_EN);
        USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_suspendm);	
	USB_DRV_SetBits32(USB_U2PHYACR2, USB_U2PHYACR2_RG_USB20_OTG_VBUSCMP_EN);
	for(delay = 0; delay < 120000; delay++);
	#ifdef MT6255
 	USB_DRV_WriteReg(USB_U2PHYDTM1, 0x3c2c);		//only for MT6255
 	for(delay = 0; delay < 10000; delay++);
 	#endif
	USB_HS_Slew_Rate_Cal();
#elif defined(DRV_USB_PHY_T28_IP)
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_uart_en);
	USB_DRV_ClearBits32(USB_U2PHYDTM1, USB_U2PHYDTM1_RG_UART_EN);
	USB_DRV_ClearBits32(USB_USBPHYACR6, USB_USBPHYACR6_RG_USB20_BC11_SW_EN);
  USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_suspendm);	
	USB_DRV_SetBits32(USB_USBPHYACR6, USB_USBPHYACR6_RG_USB20_OTG_VBUSCMP_EN);
	for(delay = 0; delay < 120000; delay++);	
#else   //Old PHY version

		USB_DRV_SetBits8(USB_PHYCR1_2, USB_PHYCR1_2_PLL_VCOG_H);

	#if defined(DRV_USB_PHY_SUPPORT_OTG)
		USB_DRV_SetBits8(USB_PHYCR4_1, USB_PHYCR4_1_FORCE_BGR_ON);
	#else	
		// For MT6235 only
		USB_DRV_SetBits8(USB_PHYIR1_0, USB_PHYIR1_0_DRVVBUS);
		USB_DRV_SetBits8(USB_PHYCR2_3, USB_PHYCR2_3_FORCE_DRV_VBUS);
		USB_DRV_SetBits8(USB_PHYCR5_0, USB_PHYCR5_0_VBUSCMP_EN);
	#endif

		for(delay = 0; delay < 1000; delay++)  ;

		/* Add external 48M clk for USB PLL here, 1: internal, 0: external */
//		USB_DRV_SetBits8(USB_PHYCR3_2, USB_PHYCR3_2_CLK_MODE);
//		USB_DRV_ClearBits8(USB_PHYCR3_2, USB_PHYCR3_2_CLK_MODE);

		USB_DRV_ClearBits8(USB_PHYCR5_2, USB_PHYCR5_2_FORCE_SUSPENDM);

		for(delay = 0; delay < 1500; delay++)  ;

		USB_DRV_SetBits8(USB_PHYCR1_0, USB_PHYCR1_0_PLL_EN);
		
		USB_Eye_Setting_Customize();

#endif
}


void USB_Save_Current_Consumption()
{
#if !defined(IC_MODULE_TEST) || defined(__SLT_MD_CATCHER_LOG_VIA_USB__)
#if defined(DRV_USB_PHY_U65_IP)
	DCL_HANDLE handle;
	PMU_CTRL_CHR_SET_BC11_PULLUP_EN val;
#endif
	volatile kal_uint32 delay;
	
	#if defined(DRV_USB_IP_V3)
	USB_DRV_Reg8(USB_DUMMY);
	#endif

#if (defined(DRV_USB_PHY_COST_DOWN)) 

#if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
	USB_UART_Share(KAL_TRUE);
#endif 
	
	USB_DRV_WriteReg8(USB_PHYCR3_2, (USB_PHYCR3_2_FORCE_DM_PULLDOWN|USB_PHYCR3_2_FORCE_DP_PULLDOWN|USB_PHYCR3_2_FORCE_TX_VALID|USB_PHYCR3_2_FORCE_DATA_IN));
	USB_DRV_WriteReg8(USB_PHYIR6_1, (USB_PHYIR6_1_RG_OTG_VBUSTH|USB_PHYIR6_1_BGR_DIV_L));
#if defined(DRV_MT6236_VERSION_CONTROL)
	USB_DRV_WriteReg8(USB_PHYCR5_3, (USB_PHYCR5_3_DP_DM_PULL_DOWN|USB_PHYCR5_3_TERM_SELECT|USB_PHYCR5_3_SUSPENDM));
#else
	USB_DRV_WriteReg8(USB_PHYCR5_3, (USB_PHYCR5_3_DP_DM_PULL_DOWN|USB_PHYCR5_3_TERM_SELECT));
#endif
	USB_DRV_WriteReg8(USB_PHYIR1_0, USB_PHY_CLEAR_MASK);
	USB_DRV_WriteReg8(USB_PHYCR1_0, USB_PHYCR1_0_IADJ_MASK2);  //Bandgape
	
	for(delay = 0; delay < 50000; delay++) ;
	
	USB_DRV_WriteReg8(USB_PHYCR3_3, (USB_PHYCR3_3_FORCE_XCVR_SELECT|USB_PHYCR3_3_FORCE_SUSPENDM|USB_PHYCR3_3_FORCE_TERM_SELECT));  
	
	for(delay = 0; delay < 50000; delay++) ;
	
	USB_DRV_WriteReg8(USB_PHYCR2_3, USB_PHY_CLEAR_MASK); //PLL

#ifndef __USB_PHY_BC11_SUPPORT__
	USB_DRV_WriteReg8(USB_PHYIR6_0, USB_PHY_CLEAR_MASK); // Remove 100K resistor
#endif

#if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
	USB_UART_Share(KAL_FALSE);
#endif 

#elif (defined(DRV_USB_PHY_U65_IP))  
	USB_DRV_ClearBits8(USB_U2PHYDTM0_3,USB_U2PHYDTM0_3_FORCE_UART_EN);
	USB_DRV_ClearBits8(USB_U2PHYDCR1_2,USB_U2PHYDCR1_2_RG_UART_EN);
	USB_DRV_SetBits8(USB_U2PHYDCR1_2,USB_U2PHYDCR1_2_RG_USB_CLKEN);
	
	USB_DRV_ClearBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_SUSPENDM); 
	
	USB_DRV_SetBits8(USB_U2PHYDTM0_0,USB_U2PHYDTM0_0_RG_DPPULLDOWN); 
	USB_DRV_SetBits8(USB_U2PHYDTM0_0,USB_U2PHYDTM0_0_RG_DMPULLDOWN);
	USB_DRV_WriteReg8(USB_U2PHYDTM0_0,((USB_DRV_Reg8(USB_U2PHYDTM0_0)& 0xCF)|USB_U2PHYDTM0_0_RG_RG_XCVRSEL));
	USB_DRV_SetBits8(USB_U2PHYDTM0_0,USB_U2PHYDTM0_0_RG_TERMSEL);
	
	USB_DRV_WriteReg8(USB_U2PHYDTM0_1,((USB_DRV_Reg8(USB_U2PHYDTM0_1)& ~0xC3)|USB_U2PHYDTM0_1_RG_DATAIN));
	
	USB_DRV_SetBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_DP_PULLDOWN); 
	USB_DRV_SetBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_DM_PULLDOWN); 
	USB_DRV_SetBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_XCVRSEL); 
	USB_DRV_SetBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_TERMSEL); 
	USB_DRV_SetBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_DATAIN);
	
	USB_DRV_ClearBits8(USB_U2PHYACR3_3,USB_U2PHYACR3_3_RG_USBRESERVED);
	USB_DRV_ClearBits8(USB_U2PHYACR2_3,USB_U2PHYACR2_3_RG_OTG_VBUSCMP_EN);
	
	for(delay = 0; delay < 1000; delay++);
	
	USB_DRV_SetBits8(USB_U2PHYDCR0_3,USB_U2PHYDCR0_3_RG_PLL_STABLE);
	
	for(delay = 0; delay < 10; delay++);
	
	USB_DRV_SetBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_SUSPENDM); 
	
	for(delay = 0; delay < 10; delay++);
	
#if defined(__USB_BOOTUP_TRACE__)
	if (!(is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE))
#endif
	{
		val.enable=KAL_FALSE;
		handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
		DclPMU_Control(handle, CHR_SET_BC11_PULLUP_EN, (DCL_CTRL_DATA_T *)&val);
		DclPMU_Close(handle);
	}
	USB_DRV_SetBits8(USB_U2PHYACR3_2,USB_U2PHYACR3_2_RG_USBRESERVED_10);
#elif defined(DRV_USB_PHY_M60_IP)||defined(DRV_USB_PHY_U40_IP)
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_uart_en);
	USB_DRV_ClearBits32(USB_U2PHYDTM1, USB_U2PHYDTM1_RG_UART_EN);
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_suspendm);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_DPPULLDOWN);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_DMPULLDOWN);
	USB_DRV_WriteReg32(USB_U2PHYDTM0, (USB_DRV_Reg32(USB_U2PHYDTM0)&~USB_U2PHYDTM0_RG_XCVRSEL_1_0_CLR)|USB_U2PHYDTM0_RG_XCVRSEL_1_0);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_TERMSEL);
	USB_DRV_WriteReg32(USB_U2PHYDTM0, (USB_DRV_Reg32(USB_U2PHYDTM0)&~USB_U2PHYDTM0_RG_DATAIN_3_0_CLR));
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_dp_pulldown);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_dm_pulldown);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_xcvrsel);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_termsel);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_datain);
	USB_DRV_ClearBits32(USB_U2PHYACR3, USB_U2PHYACR3_RG_USB20_PHY_REV_7);
	USB_DRV_ClearBits32(USB_U2PHYACR2, USB_U2PHYACR2_RG_USB20_OTG_VBUSCMP_EN);
	for(delay = 0; delay < 120000; delay++);	

//	USB_DRV_SetBits32(USB_U2PHYDCR0, USB_U2PHYDCR0_RG_USB20_PLL_STABLE);
//	USB_DRV_SetBits32(USB_U2PHYDCR1, USB_U2PHYDCR1_RG_PLL_STABL);	
	for(delay = 0; delay < 10; delay++);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_suspendm);
	for(delay = 0; delay < 10; delay++);

#elif defined(DRV_USB_PHY_T28_IP)
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_uart_en);
	USB_DRV_ClearBits32(USB_U2PHYDTM1, USB_U2PHYDTM1_RG_UART_EN);
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_suspendm);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_DPPULLDOWN);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_DMPULLDOWN);
	USB_DRV_WriteReg32(USB_U2PHYDTM0, (USB_DRV_Reg32(USB_U2PHYDTM0)&~USB_U2PHYDTM0_RG_XCVRSEL_1_0_CLR)|USB_U2PHYDTM0_RG_XCVRSEL_1_0);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_TERMSEL);
	USB_DRV_WriteReg32(USB_U2PHYDTM0, (USB_DRV_Reg32(USB_U2PHYDTM0)&~USB_U2PHYDTM0_RG_DATAIN_3_0_CLR));
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_dp_pulldown);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_dm_pulldown);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_xcvrsel);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_termsel);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_datain);
	USB_DRV_ClearBits32(USB_USBPHYACR6, USB_USBPHYACR6_RG_USB20_BC11_SW_EN);
	USB_DRV_ClearBits32(USB_USBPHYACR6, USB_USBPHYACR6_RG_USB20_OTG_VBUSCMP_EN);
	for(delay = 0; delay < 120000; delay++);	

//	USB_DRV_SetBits32(USB_U2PHYDCR0, USB_U2PHYDCR0_RG_USB20_PLL_STABLE);
//	USB_DRV_SetBits32(USB_U2PHYDCR1, USB_U2PHYDCR1_RG_PLL_STABL);	
	for(delay = 0; delay < 10; delay++);
	USB_DRV_SetBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_suspendm);
	for(delay = 0; delay < 10; delay++);

#elif defined(DRV_USB_PHY_T55_IP)
//  DRV_ClearBits32(USB_U1PHYCR1, U1PHYCR1_RG_USB11_PHY_REV_7);
//	USB_DRV_ClearBits32(USB_U1PHYCR0, U1PHYCR0_RG_USB11_FSLS_ENBGRI);  
#else  //Old PHY version

	USB_DRV_WriteReg8(USB_PHYCR1_2, (USB_PHYCR1_2_PLL_VCOG_H|USB_PHYCR1_2_HS_RCVB));

#if defined(DRV_USB_PHY_SUPPORT_OTG)
	//for MT6238
	USB_DRV_WriteReg8(USB_PHYCR2_3, (USB_PHYCR2_3_FORCE_DP_DM_PULLDOWN|USB_PHYCR2_3_HS_TERMC));
#else
	//for MT6235 only
	USB_DRV_WriteReg8(USB_PHYCR2_3, (USB_PHYCR2_3_FORCE_DRV_VBUS|USB_PHYCR2_3_FORCE_DP_DM_PULLDOWN|USB_PHYCR2_3_HS_TERMC));
	USB_DRV_WriteReg8(USB_PHYIR1_0, USB_PHYIR1_0_DRVVBUS);
#endif

	USB_DRV_WriteReg8(USB_PHYCR1_0, USB_PHYCR1_0_PLL_EN);
	USB_DRV_WriteReg8(USB_PHYCR2_2, (USB_PHYCR2_2_FORCE_DATA_IN|USB_PHYCR2_2_FORCE_TX_VALID|USB_PHYCR2_2_HS_DISCP));
	USB_DRV_WriteReg8(USB_PHYCR5_0, USB_PHYCR5_0_CDR_FILT);
	USB_DRV_WriteReg8(USB_PHYCR5_3, (USB_PHYCR5_3_DP_DM_PULL_DOWN|USB_PHYCR5_3_TERM_SELECT));
	USB_DRV_WriteReg8(USB_PHYCR5_2, (USB_PHYCR5_2_FORCE_XCVR_SELECT|USB_PHYCR5_2_FORCE_SUSPENDM|USB_PHYCR5_2_FORCE_TERM_SELECT));

	for(delay = 0; delay < 1500; delay++) ;

	USB_DRV_WriteReg8(USB_PHYIR1_0, USB_PHY_CLEAR_MASK); //for MT6235 -- turn off 48MHz clock gated cell
	USB_DRV_WriteReg8(USB_PHYCR1_2, USB_PHYCR1_2_HS_RCVB); //turn off 48MHz clock gated cell  
	
#if defined(DRV_USB_PHY_SUPPORT_OTG)
	USB_DRV_WriteReg8(USB_PHYCR4_1,USB_PHYCR4_1_BGR_DIV_L);
#else
	USB_DRV_WriteReg8(USB_PHYCR4_1, (USB_PHYCR4_1_BGR_DIV_L|USB_PHYCR4_1_BGR_CHIP_EN)); //turn off all bandgap(turn on for OTG) 
#endif

#endif //PHY setting

#endif //IC_MODULE_TEST	
}


void USB_Recover_Current_Consumption()
{
#if !defined(IC_MODULE_TEST) || defined(__SLT_MD_CATCHER_LOG_VIA_USB__)
#if (defined(DRV_USB_PHY_U65_IP) || defined(DRV_USB_PHY_M60_IP)|| defined(DRV_USB_PHY_U40_IP) || defined(DRV_USB_PHY_T28_IP))
	volatile kal_uint32 delay;
#endif

	#if defined(DRV_USB_IP_V3)
	USB_DRV_Reg8(USB_DUMMY);
	#endif

#if (defined(DRV_USB_PHY_COST_DOWN)) 

#if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
	USB_UART_Share(KAL_TRUE);
#endif 

	USB_DRV_WriteReg8(USB_PHYCR3_2, USB_PHY_CLEAR_MASK);
	USB_DRV_WriteReg8(USB_PHYCR2_3, USB_PHYCR2_3_PLL_EN);
	USB_DRV_WriteReg8(USB_PHYIR6_1, (USB_PHYIR6_1_BGR_DIV_L|USB_PHYIR6_1_RG_OTG_VBUSTH|USB_PHYIR6_1_VBUSCMP_EN));
	USB_DRV_WriteReg8(USB_PHYCR3_3, USB_PHY_CLEAR_MASK);
	
#if defined(DRV_MT6236_VERSION_CONTROL)
	USB_DRV_WriteReg8(USB_PHYCR5_3, USB_PHYCR5_3_SUSPENDM);	
#else
	USB_DRV_WriteReg8(USB_PHYCR5_3, USB_PHY_CLEAR_MASK);
#endif

	USB_DRV_WriteReg8(USB_PHYIR1_0, USB_PHY_CLEAR_MASK);
	USB_DRV_WriteReg8(USB_PHYCR1_0, (USB_PHYCR1_0_IADJ_MASK2|USB_PHYCR1_0_BGR_CHIP_EN));
		
	//=========================================
	#if defined(DRV_USB_PHY_65_INITIAL_VALUE) //6268 MP
	USB_DRV_WriteReg8(USB_PHYCR1_2, USB_PHYCR1_2_RG_PLL_DIV);
	#elif defined(DRV_USB_PHY_M110_INITIAL_VALUE) //6253 & MT6253D
	USB_DRV_WriteReg8(USB_PHYCR1_2, USB_PHYCR1_2_RG_PLL_DIV3);
	#endif
	#ifndef	__USB_PHY_BC11_SUPPORT__
	USB_DRV_WriteReg8(USB_PHYCR4_3, (USB_PHYCR4_3_UART_MODE|USB_PHYCR4_3_OTG_RESET_EN));
	#endif
	//=========================================
	

#elif (defined(DRV_USB_PHY_U65_IP))  
	USB_DRV_ClearBits8(USB_U2PHYDTM0_3,USB_U2PHYDTM0_3_FORCE_UART_EN);
	USB_DRV_ClearBits8(USB_U2PHYDCR1_2,USB_U2PHYDCR1_2_RG_UART_EN);
	USB_DRV_SetBits8(USB_U2PHYDCR1_2,USB_U2PHYDCR1_2_RG_USB_CLKEN);
	
	USB_DRV_ClearBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_SUSPENDM); 
	
	USB_DRV_ClearBits8(USB_U2PHYDTM0_0,USB_U2PHYDTM0_0_RG_DPPULLDOWN); 
	USB_DRV_ClearBits8(USB_U2PHYDTM0_0,USB_U2PHYDTM0_0_RG_DMPULLDOWN);
	USB_DRV_WriteReg8(USB_U2PHYDTM0_0,((USB_DRV_Reg8(USB_U2PHYDTM0_0)& 0xCF)));
	USB_DRV_ClearBits8(USB_U2PHYDTM0_0,USB_U2PHYDTM0_0_RG_TERMSEL);
	
	USB_DRV_WriteReg8(USB_U2PHYDTM0_1,((USB_DRV_Reg8(USB_U2PHYDTM0_1)& ~0xC3)));
	
	USB_DRV_ClearBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_DP_PULLDOWN); 
	USB_DRV_ClearBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_DM_PULLDOWN); 
	USB_DRV_ClearBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_XCVRSEL); 
	USB_DRV_ClearBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_TERMSEL); 
	USB_DRV_ClearBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_DATAIN);
	
	USB_DRV_ClearBits8(USB_U2PHYACR3_3,USB_U2PHYACR3_3_RG_USBRESERVED);
	USB_DRV_SetBits8(USB_U2PHYACR2_3,USB_U2PHYACR2_3_RG_OTG_VBUSCMP_EN);
	
	USB_DRV_SetBits8(USB_U2PHYAC0_0,USB_U2PHYAC0_0_RG_REF_INTR_EN); // switch to use internal R
		
	for(delay = 0; delay < 1000; delay++);
	
#elif (defined(DRV_USB_PHY_M60_IP)||defined(DRV_USB_PHY_U40_IP))
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_uart_en);
	USB_DRV_ClearBits32(USB_U2PHYDTM1, USB_U2PHYDTM1_RG_UART_EN);
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_suspendm);
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_DPPULLDOWN);
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_DMPULLDOWN);
	USB_DRV_WriteReg32(USB_U2PHYDTM0, (USB_DRV_Reg32(USB_U2PHYDTM0)&~USB_U2PHYDTM0_RG_XCVRSEL_1_0_CLR));
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_TERMSEL);
	USB_DRV_WriteReg32(USB_U2PHYDTM0, (USB_DRV_Reg32(USB_U2PHYDTM0)&~USB_U2PHYDTM0_RG_DATAIN_3_0_CLR));
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_dp_pulldown);
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_dm_pulldown);
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_xcvrsel);
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_termsel);
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_datain);
	USB_DRV_ClearBits32(USB_U2PHYACR3, USB_U2PHYACR3_RG_USB20_PHY_REV_7);
	USB_DRV_SetBits32(USB_U2PHYACR2, USB_U2PHYACR2_RG_USB20_OTG_VBUSCMP_EN);
	for(delay = 0; delay < 120000; delay++);	
#elif (defined(DRV_USB_PHY_T28_IP))
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_uart_en);  
	USB_DRV_ClearBits32(USB_U2PHYDTM1, USB_U2PHYDTM1_RG_UART_EN);     
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_suspendm); 
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_DPPULLDOWN);  
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_DMPULLDOWN); 
	USB_DRV_WriteReg32(USB_U2PHYDTM0, (USB_DRV_Reg32(USB_U2PHYDTM0)&~USB_U2PHYDTM0_RG_XCVRSEL_1_0_CLR));
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_TERMSEL);  
	USB_DRV_WriteReg32(USB_U2PHYDTM0, (USB_DRV_Reg32(USB_U2PHYDTM0)&~USB_U2PHYDTM0_RG_DATAIN_3_0_CLR));
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_dp_pulldown); 
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_dm_pulldown); 
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_xcvrsel); 
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_termsel); 
	USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_datain); 
	USB_DRV_ClearBits32(USB_USBPHYACR6, USB_USBPHYACR6_RG_USB20_BC11_SW_EN);
	USB_DRV_SetBits32(USB_USBPHYACR6, USB_USBPHYACR6_RG_USB20_OTG_VBUSCMP_EN);
	for(delay = 0; delay < 120000; delay++);

    USB_DRV_SetBits32(USB_U2PHYDTM1, 0x3e2e);    // force enter device mode

	
#elif defined(DRV_USB_PHY_T55_IP)
//  DRV_ClearBits32(USB_U1PHYCR1, U1PHYCR1_RG_USB11_PHY_REV_7);
//	DRV_SetBits32(USB_U1PHYCR0, U1PHYCR0_RG_USB11_FSLS_ENBGRI);  
//  for(delay = 0; delay < 1000; delay++);	

#else   	//Old PHY version

	USB_DRV_WriteReg8(USB_PHYCR1_2, (USB_PHYCR1_2_PLL_VCOG_H|USB_PHYCR1_2_HS_RCVB));
#if defined(DRV_USB_PHY_SUPPORT_OTG)
	USB_DRV_WriteReg8(USB_PHYIR1_0, USB_PHY_CLEAR_MASK);
	USB_DRV_WriteReg8(USB_PHYCR2_3, USB_PHYCR2_3_HS_TERMC);  //for MT6238
	USB_DRV_WriteReg8(USB_PHYCR5_0, (USB_PHYCR5_0_VBUSCMP_EN|USB_PHYCR5_0_CDR_FILT));  ///if 6235 0x02  else 6238 0x82
#else
	USB_DRV_WriteReg8(USB_PHYIR1_0, USB_PHYIR1_0_DRVVBUS);  //force drvvubs = 1, only for MT6235 to turn on 48MHz clock
	USB_DRV_WriteReg8(USB_PHYCR2_3, (USB_PHYCR2_3_FORCE_DRV_VBUS|USB_PHYCR2_3_HS_TERMC)); //charger detect need not to force dp_pull_down, for MT6235
	USB_DRV_WriteReg8(USB_PHYCR5_0, USB_PHYCR5_0_CDR_FILT);  ///if 6235 0x02  else 6238 0x82
#endif
	USB_DRV_WriteReg8(USB_PHYCR5_2, USB_PHY_CLEAR_MASK); //release force UTMI interface
	USB_DRV_WriteReg8(USB_PHYCR2_2, USB_PHYCR2_2_HS_DISCP); //release force UTMI interface
	USB_DRV_WriteReg8(USB_PHYCR5_3, USB_PHY_CLEAR_MASK); //reset force value.
			
#endif	
	
#endif //IC_MODULE_TEST		
}

#endif //(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__

/* After Charger EINT, BMT call this function to pull high D- 100k, remove DP/DM 15K to ground */
void USB_PHY_Charger_Detect_Init(void)
{
		
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
#if defined(DRV_USB_PHY_U65_IP)
	DCL_HANDLE handle;
	PMU_CTRL_CHR_SET_BC11_PULLUP_EN val;
#endif
	#if (defined(DRV_USB_PHY_U65_IP)||((defined(DRV_USB_PHY_M60_IP)||defined(DRV_USB_PHY_U40_IP))&&defined(PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11)))
		volatile kal_uint32 delay;
	#endif
	
		#if defined(DRV_USB_IP_V3)
		USB_DRV_Reg8(USB_DUMMY);
		#endif
		
	#if (defined(DRV_USB_PHY_COST_DOWN)) 
	
	#if defined(__USB_PHY_BC11_SUPPORT__)
		kal_uint8  index;
			
		//Change to register control and disable termination, RG_HS_TERM_EN_MODE = 10, RG21X[5:4] = 10
		USB_DRV_WriteReg8(USB_PHYIR4_1, (USB_DRV_Reg8(USB_PHYIR4_1) & 0xCF) | 0x10);
		
		//Bandgap enable, RG_BGR_BGR_EN = 1, RG0X[0] = 1
		//Bias current enable, RG_BGR_ISRC_EN = 1, RG0X[1] = 1
		//Chopper enable, RG_BGR_CHP_EN = 1, RG0X[2] = 1
		USB_DRV_WriteReg8(USB_PHYCR1_0, 0x47);
		//Enable pull up/down control from register, RG_PUPD_BIST_EN = 1, RG17X[5] = 1
		USB_DRV_WriteReg8(USB_PHYIR1_3,USB_DRV_Reg8(USB_PHYIR1_3) | 0x20);
		
		//Disconnect OP output from DP/DM, RG_CHGDT_OPOUT_SEL[1:0] = 00, USB_PHYCR5_1[4:3] = 00
		USB_DRV_WriteReg8(USB_PHYCR5_1,USB_DRV_Reg8(USB_PHYCR5_1) & 0xE7);
		//Disable OP & COMP block current, RG_CHGDT_IOUT_SEL[1:0] = 00, USB_PHYCR5_0[7:6] = 00
		USB_DRV_WriteReg8(USB_PHYCR5_0,USB_DRV_Reg8(USB_PHYCR5_0) & 0x3F);
		//Select 20uA current as I_DP_SRC, RG_CHGDT_IREF_SEL[2:0] = 011, USB_PHYCR5_1[2:0] = 011
		USB_DRV_WriteReg8(USB_PHYCR5_1, (USB_DRV_Reg8(USB_PHYCR5_1) & 0xF8) | 0x3);
		//20uA current source enable, RG_CHGDT_IREF_EN = 1, USB_PHYCR4_1[6] = 1
		USB_DRV_WriteReg8(USB_PHYCR4_1,USB_DRV_Reg8(USB_PHYCR4_1) | 0x40);
		//100uA current source disable, RG_CHGDT_ISINK_EN = 0, USB_PHYCR4_1[5] = 0
		USB_DRV_WriteReg8(USB_PHYCR4_1,USB_DRV_Reg8(USB_PHYCR4_1) & 0xDF);
		//Connect I_DP_SRC to DM, RG_CHGDT_IUP_SEL[1:0] = 01, USB_PHYCR5_0[5:4] = 01
		USB_DRV_WriteReg8(USB_PHYCR5_0, (USB_DRV_Reg8(USB_PHYCR5_0) & 0xCF) | 0x10);
		//Disconnect I_DAT_SINK current source from DP/DM, RG_CHGDT_IDN_SEL[1:0] = 00, USB_PHYCR5_0[3:2] = 00
		USB_DRV_WriteReg8(USB_PHYCR5_0,USB_DRV_Reg8(USB_PHYCR5_0) & 0xF3);
		//Disconnect DP/DM to comparator, RG_CHGDT_COMP_SEL[1:0] = 00, USB_PHYCR5_0[1:0] = 00
		USB_DRV_WriteReg8(USB_PHYCR5_0, USB_DRV_Reg8(USB_PHYCR5_0) & 0xFC);
		//Enable ISOURCE block, RG_CHGDT_EN_SEL[3:0] = 1000, USB_PHYCR5_2[3:0] = 1000
		USB_DRV_WriteReg8(USB_PHYCR5_2, (USB_DRV_Reg8(USB_PHYCR5_2) & 0xF0) | 0x08);
		//Enable charger detection, RG_EN_CHGDT = 1, USB_PHYCR5_2[4] = 1
		USB_DRV_WriteReg8(USB_PHYCR5_2,USB_DRV_Reg8(USB_PHYCR5_2) | 0x10);
	#else
		/* add 100K*/
		USB_DRV_WriteReg8(USB_PHYCR2_3, USB_PHY_CLEAR_MASK); 
		USB_DRV_WriteReg8(USB_PHYIR6_0, (USB_PHYIR6_0_RG_DP_100K_EN|USB_PHYIR6_0_RG_DM_100K_EN)); 
	#if defined(DRV_MT6236_VERSION_CONTROL)
		USB_DRV_WriteReg8(USB_PHYCR5_3, (USB_PHYCR5_3_OP_MODE|USB_PHYCR5_3_TERM_SELECT));
	#else
		USB_DRV_WriteReg8(USB_PHYCR5_3, (USB_PHYCR5_3_SUSPENDM|USB_PHYCR5_3_OP_MODE|USB_PHYCR5_3_TERM_SELECT)); 
	#endif
		USB_DRV_WriteReg8(USB_PHYCR3_3, (USB_PHYCR3_3_FORCE_OP_MODE|USB_PHYCR3_3_FORCE_TERM_SELECT|USB_PHYCR3_3_FORCE_SUSPENDM));
		USB_DRV_WriteReg8(USB_PHYCR3_2, USB_PHYCR3_2_FORCE_DP_DM_PULLDOWN);  //QQ
		
	#endif //DRV_USB_PHY_BC11_SUPPORT
		
	#elif (defined(DRV_USB_PHY_U65_IP))  
	
		// Initial Settings
		USB_DRV_ClearBits8(USB_U2PHYACR3_2,USB_U2PHYACR3_2_RG_USBRESERVED_10); //BC11 use USB
#if defined(__USB_BOOTUP_TRACE__)
		if (!(is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE))
#endif
		{
			val.enable=KAL_TRUE;
			handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
			DclPMU_Control(handle, CHR_SET_BC11_PULLUP_EN, (DCL_CTRL_DATA_T *)&val);
			DclPMU_Close(handle);
		}
		
		
		USB_DRV_WriteReg8(USB_U2PHYACR1_0,((USB_DRV_Reg8(USB_U2PHYACR1_0)& 0xCF)|USB_U2PHYACR1_0_RG_HS_TERM_EN_MODE));
		USB_DRV_SetBits8(USB_U2PHYAC0_0, USB_U2PHYAC0_0_RG_BGR_BGR_EN);
		USB_DRV_SetBits8(USB_U2PHYAC0_0, USB_U2PHYAC0_0_RG_BGR_ISRC_EN);
		USB_DRV_SetBits8(USB_U2PHYAC0_0, USB_U2PHYAC0_0_RG_BGR_CHP_EN);
		
		for(delay = 0; delay < 1000; delay++);
		
		//=================================
		// Turn on 20uA current to D-
		//=================================
		//RG_CHGDT_OPOUT_SEL[1:0] = 00
		USB_DRV_WriteReg8(USB_U2PHYACHG_1,((USB_DRV_Reg8(USB_U2PHYACHG_1)& 0xF3)));
		//RG_CHGDT_IOUT_SEL[1:0] = 00
		USB_DRV_WriteReg8(USB_U2PHYACHG_0,((USB_DRV_Reg8(USB_U2PHYACHG_0)& 0xFC)));
		//RG_CHGDT_IREF_SEL[2:0] = 011
		USB_DRV_WriteReg8(USB_U2PHYACHG_1,((USB_DRV_Reg8(USB_U2PHYACHG_1)& 0x8F)|USB_U2PHYACHG_1_RG_CHGDT_IREF_SEL));
		//RG_CHGDT_IREF_EN = 1
		USB_DRV_SetBits8(USB_U2PHYACHG_3, USB_U2PHYACHG_3_RG_CHGDT_IREF_EN);
		//RG_CHGDT_ISINK_EN = 0
		USB_DRV_ClearBits8(USB_U2PHYACHG_3, USB_U2PHYACHG_3_RG_CHGDT_ISINK_EN);
		//RG_CHGDT_IUP_SEL[1:0] = 01
		USB_DRV_WriteReg8(USB_U2PHYACHG_0,((USB_DRV_Reg8(USB_U2PHYACHG_0)& 0xF3)|USB_U2PHYACHG_0_RG_CHGDT_IUP_SEL));
		//RG_CHGDT_IDN_SEL[1:0] = 00
		USB_DRV_WriteReg8(USB_U2PHYACHG_0,((USB_DRV_Reg8(USB_U2PHYACHG_0)& 0xCF)));
		//RG_CHGDT_COMP_SEL[1:0] = 00
		USB_DRV_WriteReg8(USB_U2PHYACHG_0,((USB_DRV_Reg8(USB_U2PHYACHG_0)& 0x3F)));
		//RG_CHGDT_EN_SEL[3:0] = 1000
		USB_DRV_WriteReg8(USB_U2PHYACHG_2,((USB_DRV_Reg8(USB_U2PHYACHG_2)& 0xF0)|USB_U2PHYACHG_2_RG_CHGDT_EN_SEL));
		//RG_EN_CHGDT = 1
		USB_DRV_SetBits8(USB_U2PHYACHG_2,USB_U2PHYACHG_2_RG_EN_CHGDT);
		//RG_PUPD_BIST_EN = 1
		USB_DRV_SetBits8(USB_U2PHYACR0_0, USB_U2PHYACR0_0_RG_PUPD_BIST_EN);
		
		for(delay = 0; delay < 2000; delay++);
		
	#elif defined(DRV_USB_PHY_M60_IP)||defined(DRV_USB_PHY_U40_IP)
	
		#ifdef PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11
		USB_DRV_SetBits32(USB_U2PHYACR3, USB_U2PHYACR3_RG_USB20_PHY_REV_7);
		for(delay = 0; delay < 1000; delay++);
		#else //PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11
		
		#endif //PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11
	#elif defined(DRV_USB_PHY_T28_IP)
	
	#else 	//Old PHY version
	
	#if  defined(DRV_USB_PHY_CHARGER_DETECT)
		/* Only for 38 E2 series add 100K resistor to D- */
		USB_DRV_WriteReg8(USB_PHYCR1_0, USB_PHY_CLEAR_MASK);
		USB_DRV_SetBits8(USB_PHYCR3_2, (USB_PHYCR3_2_TEST_CTRL2_SET|USB_PHYCR3_2_TEST_CTRL1_SET));
	
		USB_DRV_WriteReg8(USB_PHYCR4_1, USB_PHYCR4_1_FORCE_BGR_ON);
		USB_DRV_WriteReg8(USB_PHYCR5_3, (USB_PHYCR5_3_TERM_SELECT|USB_PHYCR5_3_OP_MODE));
		USB_DRV_WriteReg8(USB_PHYIR1_0, USB_PHYIR1_0_TX_VALID);
	
	#ifdef DRV_USB_PHY_USB_UART_SHARE_PAD 
		USB_DRV_WriteReg8(USB_PHYCR5_2, (USB_PHYCR5_2_FORCE_OP_MODE|USB_PHYCR5_2_FORCE_TERM_SELECT|USB_PHYCR5_2_FORCE_SUSPENDM)); // force  these initial value (not include UART part)
	#else
		USB_DRV_WriteReg8(USB_PHYCR5_2, USB_PHYCR5_2_UTMI_MUXSEL); // force all initial value
	#endif
	#else
		USB_Connect_R_To_DM_Control(KAL_TRUE);
	#endif
	
		/* Remove 15K ohm pull down resistor */
		USB_DRV_ClearBits8(USB_PHYCR5_3, USB_PHYCR5_3_DP_DM_PULL_DOWN);
		USB_DRV_SetBits8(USB_PHYCR2_3, USB_PHYCR2_3_FORCE_DP_DM_PULLDOWN);
	
	#endif
#elif defined(DRV_USB_IP_V1_PLUS) //end of DRV_USB_IP_V3||defined(DRV_USB_IP_V4)
  #if defined(DRV_USB_PHY_T55_IP)
		volatile kal_uint32 delay;		  
    USB_DRV_SetBits32(USB_U1PHYCR1, U1PHYCR1_RG_USB11_PHY_REV_7);	
    for(delay = 0; delay < 1000; delay++);
  #else  
	USB_DRV_SetBits8(USB_U1PHYCR1_1, USB_U1PHYCR1_1_RG_USB11_USBRESERVED_PMU);
	USB_DRV_SetBits8(USB_U1PHYCR0_1, USB_U1PHYCR0_1_RG_USB11_PUPD_BIST_EN);
	//USB_DRV_ClearBits8(USB_U1PHYCR0_2, USB_U1PHYCR0_2_RG_USB11_EN_PD_DM);
	#endif	
	
#endif //(DRV_USB_IP_V3)
}


/* BMT already know charger in, need to differentiate standard or not-standard charger */
void USB_PHY_Check_Standard_Charger(void)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	#if (defined(DRV_USB_PHY_COST_DOWN))
		#if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
		USB_UART_Share(KAL_TRUE);
		#endif 
		
		#if defined(DRV_USB_IP_V3)
		USB_DRV_Reg8(USB_DUMMY);
		#endif
	
		#if defined(__USB_PHY_BC11_SUPPORT__)
			//Disable all charger block, RG_CHGDT_EN_SEL[3:0] = 0000, USB_PHYCR5_2[3:0] = 0000
			USB_DRV_WriteReg8(USB_PHYCR5_2, (USB_DRV_Reg8(USB_PHYCR5_2) & 0xF0));
			//Disable 20uA current source, RG_CHGDT_IREF_EN = 0, USB_PHYCR4_1[6] = 0
			USB_DRV_WriteReg8(USB_PHYCR4_1, USB_DRV_Reg8(USB_PHYCR4_1) & 0xBF);
			//Disconnect 20uA to DP/DM, RG_CHGDT_IUP_SEL[1:0] = 00, USB_PHYCR5_0[5:4] = 00
			USB_DRV_WriteReg8(USB_PHYCR5_0, (USB_DRV_Reg8(USB_PHYCR5_0) & 0xCF));
			//Select VREF source from BGR, RG_CHGDT_VDATSRC_SEL = 0, USB_PHYCR4_1[7] = 0
			USB_DRV_WriteReg8(USB_PHYCR4_1,USB_DRV_Reg8(USB_PHYCR4_1) & 0x7F);
			//Connect OP output from DP, RG_CHGDT_OPOUT_SEL[1:0] = 10, USB_PHYCR5_1[4:3] = 10
			USB_DRV_WriteReg8(USB_PHYCR5_1, (USB_DRV_Reg8(USB_PHYCR5_1) & 0xE7) | 0x10);
			//Enable OP & COMP block current, RG_CHGDT_IOUT_SEL[1:0] = 11, USB_PHYCR5_0[7:6] = 11 
			USB_DRV_WriteReg8(USB_PHYCR5_0,USB_DRV_Reg8(USB_PHYCR5_0) | 0xC0);
			//Connect I_DAT_SINK current source from DM, RG_CHGDT_IDN_SEL[1:0] = 01, USB_PHYCR5_0[3:2] = 01
			USB_DRV_WriteReg8(USB_PHYCR5_0, (USB_DRV_Reg8(USB_PHYCR5_0) & 0xF3) | 0x04);
			//100uA current source enable, RG_CHGDT_ISINK_EN = 1, USB_PHYCR4_1[5] = 1
			USB_DRV_WriteReg8(USB_PHYCR4_1,USB_DRV_Reg8(USB_PHYCR4_1) | 0x20);
			//Connect DM to comparator, RG_CHGDT_COMP_SEL[1:0] = 01, USB_PHYCR5_0[1:0] = 01
			USB_DRV_WriteReg8(USB_PHYCR5_0, (USB_DRV_Reg8(USB_PHYCR5_0) & 0xFC) | 0x01);
			//Enable OP & ISOURCE & COMP blocks, RG_CHGDT_EN_SEL[3:0] = 1110, USB_PHYCR5_2[3:0] = 1110
			USB_DRV_WriteReg8(USB_PHYCR5_2, (USB_DRV_Reg8(USB_PHYCR5_2) & 0xF0) | 0x0E);
		
		#else
			/* remove 100K*/ 
			USB_DRV_WriteReg8(USB_PHYCR2_3, USB_PHYCR2_3_PLL_EN); 
			USB_DRV_WriteReg8(USB_PHYIR6_0, USB_PHY_CLEAR_MASK); 
			/* add pull up & down resistor*/
			USB_DRV_WriteReg8(USB_PHYCR3_2, USB_PHYCR3_2_FORCE_DP_DM_PULLDOWN); 
			
			#if defined(DRV_MT6236_VERSION_CONTROL)
			USB_DRV_WriteReg8(USB_PHYCR5_3, (USB_PHYCR5_3_DM_PULL_DOWN|USB_PHYCR5_3_XCVR_SELECT_L|USB_PHYCR5_3_TERM_SELECT)); 
			#else
			USB_DRV_WriteReg8(USB_PHYCR5_3, (USB_PHYCR5_3_DM_PULL_DOWN|USB_PHYCR5_3_XCVR_SELECT_L|USB_PHYCR5_3_SUSPENDM|USB_PHYCR5_3_TERM_SELECT)); 
			#endif
			
			USB_DRV_WriteReg8(USB_PHYCR3_3, (USB_PHYCR3_3_FORCE_OP_MODE|USB_PHYCR3_3_FORCE_TERM_SELECT|USB_PHYCR3_3_FORCE_SUSPENDM|USB_PHYCR3_3_FORCE_XCVR_SELECT)); 
	
		#endif  //DRV_USB_PHY_BC11_SUPPORT
	
	#elif (defined(DRV_USB_PHY_U65_IP))  
			//RG_PUPD_BIST_EN = 1	Enable pull up/down control from register
			USB_DRV_SetBits8(USB_U2PHYACR0_0, USB_U2PHYACR0_0_RG_PUPD_BIST_EN);
			//RG_EN_PU_DP = 1	DP pull up enable
			USB_DRV_SetBits8(USB_U2PHYACR0_1, USB_U2PHYACR0_1_RG_EN_PU_DP);
			//RG_EN_PD_DP = 0	DP pull down disable
			USB_DRV_ClearBits8(USB_U2PHYACR0_1, USB_U2PHYACR0_1_RG_EN_PD_DP);
			//RG_EN_PU_DM = 0	DM pull up disable
			USB_DRV_ClearBits8(USB_U2PHYACR1_0, USB_U2PHYACR1_0_RG_EN_PU_DM);
			//RG_EN_PD_DM = 1	DM pull down eable
			USB_DRV_SetBits8(USB_U2PHYACR1_0, USB_U2PHYACR1_0_RG_EN_PD_DM);
	
	#elif (defined(DRV_USB_PHY_M60_IP))  

	#elif (defined(DRV_USB_PHY_U40_IP)) 
	
	#elif (defined(DRV_USB_PHY_T28_IP)) 
		
	#else //Old PHY version
	
		#if  defined(DRV_USB_PHY_CHARGER_DETECT)
			/* Only for 38 E2, Remove 100K resistor to D- */
			USB_DRV_WriteReg8(USB_PHYCR1_0, USB_PHYCR1_0_PLL_EN);
			USB_DRV_ClearBits8(USB_PHYCR3_2, USB_PHYCR3_2_TEST_CTRL_MASK);
			USB_DRV_SetBits8(USB_PHYCR3_2, USB_PHYCR3_2_TEST_CTRL2_SET);
			USB_DRV_WriteReg8(USB_PHYCR4_1, USB_PHYCR4_1_FORCE_BGR_ON);
			USB_DRV_WriteReg8(USB_PHYCR5_3, USB_PHY_CLEAR_MASK);
			USB_DRV_WriteReg8(USB_PHYIR1_0, USB_PHY_CLEAR_MASK);
			USB_DRV_WriteReg8(USB_PHYCR5_2, USB_PHY_CLEAR_MASK);
		#else
			USB_Connect_R_To_DM_Control(KAL_FALSE);
		#endif
	
		/* Add D- 15K ohm pull down resistor */
		USB_DRV_SetBits8(USB_PHYCR5_3, USB_PHYCR5_3_DM_PULL_DOWN);
	
		/* Add D+ 1.5K ohm pull up resistor */
		USB_DRV_ClearBits8(USB_PHYCR5_3, USB_PHYCR5_3_XCVR_SELECT_MASK);
	
		USB_DRV_SetBits8(USB_PHYCR5_3, (USB_PHYCR5_3_XCVR_SELECT_L|USB_PHYCR5_3_TERM_SELECT));
	
		USB_DRV_SetBits8(USB_PHYCR5_2, USB_PHYCR5_2_FORCE_DP_HIGH);
		
	#endif 
#elif defined(DRV_USB_IP_V1_PLUS) //end of DRV_USB_IP_V3
  #if defined(DRV_USB_PHY_T55_IP)
  #else
	//1. Isolation on (turn off PMU)
	USB_DRV_ClearBits8(USB_U1PHYCR1_1, USB_U1PHYCR1_1_RG_USB11_USBRESERVED_PMU);
	
	//2. pull up 1.5k resistor
	//USB_DRV_SetBits8(USB_U1PHYCR0_1, USB_U1PHYCR0_1_RG_USB11_PUPD_BIST_EN);
	//USB_DRV_SetBits8(USB_U1PHYCR0_2, USB_U1PHYCR0_2_RG_USB11_EN_PU_DP);
	//USB_DRV_ClearBits8(USB_U1PHYCR0_2, USB_U1PHYCR0_2_RG_USB11_EN_PD_DP);
	//USB_DRV_ClearBits8(USB_U1PHYCR0_2, USB_U1PHYCR0_2_RG_USB11_EN_PU_DM);
	//USB_DRV_ClearBits8(USB_U1PHYCR0_2, USB_U1PHYCR0_2_RG_USB11_EN_PD_DM);

	//2. pull up 100k
	//USB_DRV_SetBits8(USB_U1PHYCR0_1, USB_U1PHYCR0_1_RG_USB11_PUPD_BIST_EN);
	//USB_DRV_SetBits8(USB_U1PHYCR0_2, USB_U1PHYCR0_2_RG_USB11_EN_PU_DP);
	//USB_DRV_SetBits8(USB_U1PHYCR0_2, USB_U1PHYCR0_2_RG_USB11_DP_100K_EN); 
	#endif
#endif //(DRV_USB_IP_V3)
}

void USB_PHY_Charger_Detect_Release(void)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

	#if defined(DRV_USB_PHY_U65_IP)
	DCL_HANDLE handle;
	PMU_CTRL_CHR_SET_BC11_PULLUP_EN val;
	#endif	
	
	#if (defined(DRV_USB_PHY_M60_IP)||defined(DRV_USB_PHY_U40_IP)&&defined(PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11))
	volatile kal_uint32 delay;
	#endif

	#if defined(DRV_USB_IP_V3)
	USB_DRV_Reg8(USB_DUMMY);
	#endif
			
	#if (defined(DRV_USB_PHY_COST_DOWN)) 
		#if defined(__USB_PHY_BC11_SUPPORT__)
			//Recover to RG default setting
			//RG_CHGDT_VREF_SEL[1:0] = 00, USB_PHYCR5_1[6:5] = 00
			USB_DRV_WriteReg8(USB_PHYCR5_1,USB_DRV_Reg8(USB_PHYCR5_1) & 0x9F);
			//RG_CHGDT_IREF_SEL[2:0] = 011, USB_PHYCR5_1[2:0] = 011
			USB_DRV_WriteReg8(USB_PHYCR5_1, (USB_DRV_Reg8(USB_PHYCR5_1) & 0xF8) | 0x3);
			//RG_CHGDT_IOUT_SEL[1:0] = 00, USB_PHYCR5_0[7:6] = 00
			USB_DRV_WriteReg8(USB_PHYCR5_0,USB_DRV_Reg8(USB_PHYCR5_0) & 0x3F);
			//RG_CHGDT_IUP_SEL[1:0] = 00, USB_PHYCR5_0[5:4] = 00
			USB_DRV_WriteReg8(USB_PHYCR5_0, (USB_DRV_Reg8(USB_PHYCR5_0) & 0xCF));
			//RG_CHGDT_IDN_SEL[1:0] = 00, USB_PHYCR5_0[3:2] = 00
			USB_DRV_WriteReg8(USB_PHYCR5_0,USB_DRV_Reg8(USB_PHYCR5_0) & 0xF3);
			//RG_CHGDT_OPOUT_SEL[1:0] = 00, USB_PHYCR5_1[4:3] = 00
			USB_DRV_WriteReg8(USB_PHYCR5_1,USB_DRV_Reg8(USB_PHYCR5_1) & 0xE7);
			//RG_CHGDT_COMP_SEL[1:0] = 00, USB_PHYCR5_0[1:0] = 00
			USB_DRV_WriteReg8(USB_PHYCR5_0,USB_DRV_Reg8(USB_PHYCR5_0) & 0xFC);
			//RG_CHGDT_EN_SEL[3:0] = 0000, USB_PHYCR5_2[3:0] = 0000
			USB_DRV_WriteReg8(USB_PHYCR5_2, (USB_DRV_Reg8(USB_PHYCR5_2) & 0xF0));
			//RG_EN_CHGDT = 0, USB_PHYCR5_2[4] = 0
			USB_DRV_WriteReg8(USB_PHYCR5_2,USB_DRV_Reg8(USB_PHYCR5_2) & 0xEF);
			//RG_CHGDT_RESERVED[4:0] = 00000, RG_CHGDT_ISINK_EN = 0, RG_CHGDT_IREF_EN = 0, RG_CHGDT_VDATSRC_SEL = 0, USB_PHYCR4_1[7:0] = 00000000
			USB_DRV_WriteReg8(USB_PHYCR4_1, 0);
			//RG_BGR_BGR_EN = 0, RG0X[0] = 0, RG_BGR_ISRC_EN = 0, RG0X[1] = 0, RG_RGR_CHP_EN = 1, RG0X[2] = 1
			USB_DRV_WriteReg8(USB_PHYCR1_0, (USB_DRV_Reg8(USB_PHYCR1_0) & 0xF8) | USB_PHYCR1_0_BGR_CHIP_EN);
			//RG_PUPD_BIST_EN = 0, RG17X[5] = 0
			USB_DRV_WriteReg8(USB_PHYIR1_3,USB_DRV_Reg8(USB_PHYIR1_3) & 0xDF);
			//RG_EN_PU_DP = 0, RG15X[6] = 0
			//RG_EN_PD_DP = 0, RG15X[4] = 0
			//RG_EN_PU_DM = 0, RG15X[7] = 0
			//RG_EN_PD_DM = 0, RG15X[5] = 0
			USB_DRV_WriteReg8(USB_PHYIR1_1,USB_DRV_Reg8(USB_PHYIR1_1) & 0x0F);
			
			//RG_DP_ABIST_SOURCE_EN = 0, RG26X[4] = 0
			USB_DRV_WriteReg8(USB_PHYIR5_2,USB_DRV_Reg8(USB_PHYIR5_2) & 0xEF);
			//RG_DM_ABIST_SOURCE_EN = 0, RG27X[4] = 0
			USB_DRV_WriteReg8(USB_PHYIR5_3,USB_DRV_Reg8(USB_PHYIR5_3) & 0xEF);
			//RG_DP_100K_EN = 0, RG28X[0] = 0
			//RG_DM_100K_EN = 0, RG28X[1] = 0
			USB_DRV_WriteReg8(USB_PHYIR6_0,USB_DRV_Reg8(USB_PHYIR6_0) & 0xFC);
			//RG_HS_TERM_EN_MODE = 00, RG21X[5:4] = 00
			USB_DRV_WriteReg8(USB_PHYIR4_1,USB_DRV_Reg8(USB_PHYIR4_1) & 0xCF);
		
		#else  //(__USB_PHY_BC11_SUPPORT__)
			/* remove 100K  & pull up & down resistor */ 
			USB_DRV_WriteReg8(USB_PHYCR2_3, USB_PHYCR2_3_PLL_EN); 
			USB_DRV_WriteReg8(USB_PHYIR6_0, USB_PHY_CLEAR_MASK); 
			#if defined(DRV_MT6236_VERSION_CONTROL)
			USB_DRV_WriteReg8(USB_PHYCR5_3, USB_PHYCR5_3_SUSPENDM);
			#else
			USB_DRV_WriteReg8(USB_PHYCR5_3, USB_PHY_CLEAR_MASK); 
			#endif
			USB_DRV_WriteReg8(USB_PHYCR3_2, USB_PHY_CLEAR_MASK); 
			USB_DRV_WriteReg8(USB_PHYCR3_3, USB_PHYCR3_3_FORCE_SUSPENDM); 
		
		#endif  //DRV_USB_PHY_BC11_SUPPORT
		
	#elif (defined(DRV_USB_PHY_U65_IP))  
		//RG_CHGDT_VREF_SEL[1:0] = 00
		USB_DRV_WriteReg8(USB_U2PHYACHG_1,((USB_DRV_Reg8(USB_U2PHYACHG_1)& 0xFC)));
		//RG_CHGDT_IREF_SEL[2:0] = 011
		USB_DRV_WriteReg8(USB_U2PHYACHG_1,((USB_DRV_Reg8(USB_U2PHYACHG_1)& 0x8F)|USB_U2PHYACHG_1_RG_CHGDT_IREF_SEL));
		//RG_CHGDT_IOUT_SEL[1:0] = 00
		USB_DRV_WriteReg8(USB_U2PHYACHG_0,((USB_DRV_Reg8(USB_U2PHYACHG_0)& 0xF3)));
		//RG_CHGDT_IUP_SEL[1:0] = 00
		USB_DRV_WriteReg8(USB_U2PHYACHG_0,((USB_DRV_Reg8(USB_U2PHYACHG_0)& 0xF3)));
		//RG_CHGDT_IDN_SEL[1:0] = 00
		USB_DRV_WriteReg8(USB_U2PHYACHG_0,((USB_DRV_Reg8(USB_U2PHYACHG_0)& 0xCF)));
		//RG_CHGDT_OPOUT_SEL[1:0] = 00
		USB_DRV_WriteReg8(USB_U2PHYACHG_1,((USB_DRV_Reg8(USB_U2PHYACHG_1)& 0xF3)));
		//RG_CHGDT_COMP_SEL[1:0] = 00
		USB_DRV_WriteReg8(USB_U2PHYACHG_0,((USB_DRV_Reg8(USB_U2PHYACHG_0)& 0x3F)));
		//RG_CHGDT_EN_SEL[3:0] = 0000
		USB_DRV_WriteReg8(USB_U2PHYACHG_2,((USB_DRV_Reg8(USB_U2PHYACHG_2)& 0xF0)));
		//RG_EN_CHGDT = 0
		USB_DRV_ClearBits8(USB_U2PHYACHG_2,USB_U2PHYACHG_2_RG_EN_CHGDT);
		//RG_CHGDT_RESERVED[7:0] = 00000000
		USB_DRV_WriteReg8(USB_U2PHYACHG_3,0x00);
		//RG_BGR_BGR_EN = 0
		USB_DRV_ClearBits8(USB_U2PHYAC0_0, USB_U2PHYAC0_0_RG_BGR_BGR_EN);
		//RG_BGR_ISRC_EN = 0
		USB_DRV_ClearBits8(USB_U2PHYAC0_0, USB_U2PHYAC0_0_RG_BGR_ISRC_EN);
		//RG_BGR_CHP_EN = 1
		USB_DRV_SetBits8(USB_U2PHYAC0_0, USB_U2PHYAC0_0_RG_BGR_CHP_EN);
		//RG_PUPD_BIST_EN = 0
		USB_DRV_ClearBits8(USB_U2PHYACR0_0, USB_U2PHYACR0_0_RG_PUPD_BIST_EN);
		//RG_EN_PU_DP = 0
		USB_DRV_ClearBits8(USB_U2PHYACR0_1, USB_U2PHYACR0_1_RG_EN_PU_DP);
		//RG_EN_PD_DP = 0
		USB_DRV_ClearBits8(USB_U2PHYACR0_1, USB_U2PHYACR0_1_RG_EN_PD_DP);
		//RG_EN_PU_DM = 0
		USB_DRV_ClearBits8(USB_U2PHYACR1_0, USB_U2PHYACR1_0_RG_EN_PU_DM);
		//RG_EN_PD_DM = 0
		USB_DRV_ClearBits8(USB_U2PHYACR1_0, USB_U2PHYACR1_0_RG_EN_PD_DM);
		//RG_DP_ABIST_SOURCE_EN = 0
		USB_DRV_ClearBits8(USB_U2PHYACR2_1, USB_U2PHYACR2_1_RG_DP_ABIST_SOURCE_EN);
		//RG_DM_ABIST_SOURCE_EN = 0
		USB_DRV_ClearBits8(USB_U2PHYACR2_2, USB_U2PHYACR2_2_RG_DM_ABIST_SOURCE_EN);
		//RG_DP_100K_EN = 0
		USB_DRV_ClearBits8(USB_U2PHYACR2_3, USB_U2PHYACR2_3_RG_DP_100K_EN);
		//RG_DM_100K_EN = 0
		USB_DRV_ClearBits8(USB_U2PHYACR2_3, USB_U2PHYACR2_3_RG_DM_100K_EN);
		//RG_HS_TERM_EN_MODE = 00
		USB_DRV_ClearBits8(USB_U2PHYACR1_0, USB_U2PHYACR1_0_RG_HS_TERM_EN_MODE);
		
#if defined(__USB_BOOTUP_TRACE__)
		if (!(is_init_log_enable == KAL_TRUE && is_init_stage == KAL_TRUE))
#endif
		{
			val.enable=KAL_FALSE;
			handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
			DclPMU_Control(handle, CHR_SET_BC11_PULLUP_EN, (DCL_CTRL_DATA_T *)&val);
			DclPMU_Close(handle);
		}
		USB_DRV_SetBits8(USB_U2PHYACR3_2,USB_U2PHYACR3_2_RG_USBRESERVED_10);
	
	#elif defined(DRV_USB_PHY_M60_IP)||defined(DRV_USB_PHY_U40_IP)
		#ifdef PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11
		USB_DRV_ClearBits32(USB_U2PHYACR3, USB_U2PHYACR3_RG_USB20_PHY_REV_7);
		for(delay = 0; delay < 1000; delay++);
		#else //PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11
		
		#endif //PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11

	#elif defined(DRV_USB_PHY_T28_IP)
	
	#else	//Old PHY version
	
		#if  defined(DRV_USB_PHY_CHARGER_DETECT)
			/* For 38 E2, Remove 100K resistor to D- */
			USB_DRV_WriteReg8(USB_PHYCR1_0, USB_PHYCR1_0_PLL_EN);
		
			USB_DRV_ClearBits8(USB_PHYCR3_2, USB_PHYCR3_2_TEST_CTRL_MASK);
			USB_DRV_SetBits8(USB_PHYCR3_2, USB_PHYCR3_2_TEST_CTRL2_SET);
			USB_DRV_WriteReg8(USB_PHYCR4_1, USB_PHYCR4_1_FORCE_BGR_ON);
			USB_DRV_WriteReg8(USB_PHYCR5_3, USB_PHY_CLEAR_MASK);
			USB_DRV_WriteReg8(USB_PHYIR1_0, USB_PHY_CLEAR_MASK);
			USB_DRV_WriteReg8(USB_PHYCR5_2, USB_PHY_CLEAR_MASK);
		#else
			USB_Connect_R_To_DM_Control(KAL_FALSE);
		#endif
	
		/* Remove 15K ohm pull down resistor */
		USB_DRV_ClearBits8(USB_PHYCR2_3, USB_PHYCR2_3_FORCE_DP_DM_PULLDOWN);
	
		/* Remove D+ 1.5K ohm pull up resistor */
		USB_DRV_ClearBits8(USB_PHYCR5_2, USB_PHYCR5_2_FORCE_DP_HIGH);
	
	#endif
#elif defined(DRV_USB_IP_V1_PLUS) //end of DRV_USB_IP_V3
  #if defined(DRV_USB_PHY_T55_IP)
		volatile kal_uint32 delay;		    
    USB_DRV_ClearBits32(USB_U1PHYCR1, U1PHYCR1_RG_USB11_PHY_REV_7);		
    for(delay = 0; delay < 1000; delay++);
  #else  
	USB_DRV_ClearBits8(USB_U1PHYCR0_1, USB_U1PHYCR0_1_RG_USB11_PUPD_BIST_EN);
	USB_DRV_ClearBits8(USB_U1PHYCR0_2, USB_U1PHYCR0_2_RG_USB11_EN_PU_DP);
	USB_DRV_ClearBits8(USB_U1PHYCR0_2, USB_U1PHYCR0_2_RG_USB11_EN_PD_DP);
	USB_DRV_ClearBits8(USB_U1PHYCR0_2, USB_U1PHYCR0_2_RG_USB11_EN_PU_DM);
	USB_DRV_ClearBits8(USB_U1PHYCR0_2, USB_U1PHYCR0_2_RG_USB11_EN_PD_DM);
	USB_DRV_ClearBits8(USB_U1PHYCR0_3, USB_U1PHYCR0_3_RG_USB11_DP_ABIST_SOURCE_EN);
	USB_DRV_ClearBits8(USB_U1PHYCR1_0, USB_U1PHYCR1_0_RG_USB11_DM_ABIST_SOURCE_EN);
	USB_DRV_ClearBits8(USB_U1PHYCR0_2, USB_U1PHYCR0_2_RG_USB11_DP_100K_EN);
	USB_DRV_ClearBits8(USB_U1PHYCR0_2, USB_U1PHYCR0_2_RG_USB11_DM_100K_EN);
	USB_DRV_ClearBits8(USB_U1PHYCR1_1, USB_U1PHYCR1_1_RG_USB11_USBRESERVED_PMU);
	//USB_DRV_ClearBits8(USB_U1PHYCR0_2, USB_U1PHYCR0_2_RG_USB11_DP_100K_EN); 
	#endif
#endif //(DRV_USB_IP_V3)
}

#endif  //__CHARGER_USB_DETECT_WIHT_ONE_EINT__



#if defined(DRV_USB_PHY_CALIBRATION)

void USB_SR_Calibration(void)
{
#if (defined(DRV_USB_PHY_COST_DOWN)) 
	unsigned long data = 0, b;
	double freq, x;
        kal_uint32 timeout = 0;
	//Enable USB ring oscillator, RG4X[2] = 1
	USB_DRV_WriteReg8(USB_PHYCR2_0, USB_DRV_Reg8(USB_PHYCR2_0) | 0x4);
	//Select AD_USB_MONCLK00 to frequency meter, RG4X[1:0] = 00
	USB_DRV_WriteReg8(USB_PHYCR2_0, USB_DRV_Reg8(USB_PHYCR2_0) & 0xFC);
	
	//Reset frequency meter
	USB_DRV_WriteReg(ABIST_FMTR_CON0, 0x4000);
	//De-assert reset and program measurement time window
	USB_DRV_WriteReg(ABIST_FMTR_CON0, TIME_WINDOW);
	//Select fixed clock (13MHz) as reference frequency and select tested clock source (USB PHY 30MHz)
	USB_DRV_WriteReg(ABIST_FMTR_CON1, 7);
	//Enable frequency meter
	USB_DRV_WriteReg(ABIST_FMTR_CON0, TIME_WINDOW | 0x8000);
	//Polling FQMTR_BUSY until it return to 0
	while ((((data = USB_DRV_Reg(ABIST_FMTR_DATA)) & 0x8000) == 0x8000) || (data == 0)) {
          timeout++;
          if (timeout == 500)
        	break;
	};
	freq = (double) (13 * (double)data / TIME_WINDOW);
	
	x = 4 * freq / FRA;
	b = (int)(x + 0.5);
	//b = RGX[2:0] = RG29X[7], RG22X[1:0]
	USB_DRV_WriteReg8(USB_PHYIR4_2, (USB_DRV_Reg8(USB_PHYIR4_2) & 0xFC) | (b & 0x3));
	USB_DRV_WriteReg8(USB_PHYIR6_1, (USB_DRV_Reg8(USB_PHYIR6_1) & 0x7F) | (((b & 0x4) >> 2) << 7));
	
	//Disable USB ring oscillator, RG4X[2] = 0
	USB_DRV_WriteReg8(USB_PHYCR2_0, USB_DRV_Reg8(USB_PHYCR2_0) & 0xFB);
	//Disable frequency meter
	USB_DRV_WriteReg(ABIST_FMTR_CON0, 0);
#elif (defined(DRV_USB_PHY_U65_IP))  

#elif (defined(DRV_USB_PHY_U40_IP))     
    
#elif (defined(DRV_USB_PHY_T28_IP))     

#endif    
    	
}
#endif  //SR_Calibration

#endif  //USB Enable


