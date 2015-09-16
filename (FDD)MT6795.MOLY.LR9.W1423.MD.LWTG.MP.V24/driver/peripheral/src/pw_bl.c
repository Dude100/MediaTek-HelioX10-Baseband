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
 *    pw_bl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for power on reason detection at bootloader
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __FAST_LOGO__

#include "drv_features.h"
#include "drv_comm.h"
#include "dcl_rtc.h"
#include "dcl_pw.h"
#include "wdt_hw.h"
#include "bmt.h"

//extern kal_bool DclPW_Is_RTC_Expired(void);
extern kal_bool USBDL_Cable_IN(void);
extern kal_bool BL_PowerKey_Press(void);

kal_uint8 PW_PowerDetect(void)
{
#if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)

    kal_uint8  RTC_Firston;   
    RTC_CTRL_IS_FIRST_ON_T IsFirstOn; 
    kal_uint16 REG_COMM2;
    kal_uint8 return_value = 0;
    kal_bool factors[PWR_FACTOR_MAX] = {KAL_FALSE};
    DCL_HANDLE rtc_handler;
    PW_CTRL_POWER_ON_REASON PWRon;    

    RTC_CTRL_CONFIG_PDN_BIT_T rtc_cmd_data18;

    kal_bool PowerKeyStatus;
    kal_bool WdtRstFlag;

    rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);
    rtc_cmd_data18.PDNIndex = DCL_RTC_PDN2;	
    DclRTC_Control(rtc_handler, RTC_CMD_READ_PDN_BITS, (DCL_CTRL_DATA_T *)&rtc_cmd_data18); // New API with CMD & DATA
    REG_COMM2 = rtc_cmd_data18.PDNValue;    

    DclRTC_Control(rtc_handler, RTC_CMD_IS_FIRST_ON, (DCL_CTRL_DATA_T *)&IsFirstOn);	

    // If RTC first on, reset PDN bits to normal reset
    RTC_Firston = (kal_uint8)IsFirstOn.fgFirstOn;
    DclRTC_Close(rtc_handler);

	if (RTC_Firston)      
	{
          REG_COMM2 = DRV_COMM_REG2_NORMAL_RESET; // REG_COMM2 will be refered in later check
	}

	// collect all factors
	// check RTC expired
	//if (PW_Is_RTC_Expired())
	if (DclPW_Is_RTC_Expired())
	{
		factors[PWR_FACTOR_RTC_EXPIRE] = KAL_TRUE;
	}

     PowerKeyStatus = BL_PowerKey_Press();
	// check power key pressed
	if (PowerKeyStatus)
	{
		factors[PWR_FACTOR_POWER_KEY] = KAL_TRUE;
	}

    if (USBDL_Cable_IN())
    {
        factors[PWR_FACTOR_CHARGER_IN] = KAL_TRUE;
    }

     WdtRstFlag = (PW_DRV_ReadReg16(WDT_STATUS) & WDT_STATUS_BITMASK)?(KAL_TRUE):(KAL_FALSE);  
     if (WdtRstFlag)
     {
		factors[PWR_FACTOR_WDT_RESET] = KAL_TRUE;
     }
    
	// check flags
	if (REG_COMM2 & DRV_COMM_REG2_NORMAL_RESET)
	{
		factors[PWR_FACTOR_NORMAL_RESET_FLG] = KAL_TRUE;
	}
	if (REG_COMM2 & DRV_COMM_REG2_CHRPWRON)
	{
		factors[PWR_FACTOR_CHRPWRON_FLG] = KAL_TRUE;
	}
	if (REG_COMM2 & DRV_COMM_REG2_USBMS_PWRON)
	{
		factors[PWR_FACTOR_USBMS_PWRON_FLG] = KAL_TRUE;
	}
	if (REG_COMM2 & DRV_COMM_REG2_RTCPWRON)
	{
		factors[PWR_FACTOR_RTCPWRON_FLG] = KAL_TRUE;
	}
	if (REG_COMM2 & DRV_COMM_REG2_SWITCH2IDLE_PWRON)
	{
		factors[PWR_FACTOR_SWITCH2IDLE_FLG] = KAL_TRUE;
	}
	// check power on type
	// priority: PWRKEYPWRON > ABNRESET > CHRPWRON > USBPWRON_WDT > USBPWRON > RTCPWRON


	#if defined(DRV_MISC_PWIC_FORCE_RETURN_PWRKEY_POWERON)
	{
		kal_uint32 tmp_i;
		for (tmp_i=0; tmp_i<PWR_FACTOR_MAX;tmp_i++){
			factors[tmp_i] = KAL_FALSE;
		}
		factors[PWR_FACTOR_SWITCH2IDLE_FLG] = KAL_TRUE;
	}
	#endif // #if defined(DRV_MISC_PWIC_FORCE_RETURN_PWRKEY_POWERON)


	if(factors[PWR_FACTOR_PRECHRPWRON_FLG])
	{
		//BMT.PWRon = (kal_uint8)CHRPWRON;//PRECHRPWRON
		PWRon=CHRPWRON;
	}
	else if (factors[PWR_FACTOR_SWITCH2IDLE_FLG])
	{
		//BMT.PWRon = (kal_uint8)PWRKEYPWRON;
		PWRon=PWRKEYPWRON;
	}
	else if (factors[PWR_FACTOR_SWITCH2CHR_FLG])
	{
		//BMT.PWRon = (kal_uint8)CHRPWRON;
		PWRon=CHRPWRON;
	}
	else if (factors[PWR_FACTOR_SWITCH2USB_FLG])
	{
		//BMT.PWRon = (kal_uint8)USBPWRON;
		PWRon=USBPWRON;
	}
	else if ((factors[PWR_FACTOR_POWER_KEY]&& !factors[PWR_FACTOR_CHARGER_IN]&& !factors[PWR_FACTOR_USB_IN])||
	         (factors[PWR_FACTOR_POWER_KEY]&& factors[PWR_FACTOR_CHARGER_IN]&& factors[PWR_FACTOR_WDT_RESET]&& factors[PWR_FACTOR_CHRPWRON_FLG])||
	         (factors[PWR_FACTOR_POWER_KEY]&& factors[PWR_FACTOR_USB_IN]&& factors[PWR_FACTOR_WDT_RESET]&& factors[PWR_FACTOR_USBMS_PWRON_FLG])||
	         (factors[PWR_FACTOR_POWER_KEY]&& factors[PWR_FACTOR_CHARGER_IN]&& !factors[PWR_FACTOR_WDT_RESET])||
	         (factors[PWR_FACTOR_POWER_KEY]&& factors[PWR_FACTOR_USB_IN]&& !factors[PWR_FACTOR_WDT_RESET]))
	{
		//BMT.PWRon = (kal_uint8)PWRKEYPWRON;
		PWRon=PWRKEYPWRON;
	}
	else if (factors[PWR_FACTOR_WDT_RESET]&&!factors[PWR_FACTOR_CHRPWRON_FLG]&&!factors[PWR_FACTOR_USBMS_PWRON_FLG]
	         &&!factors[PWR_FACTOR_RTCPWRON_FLG]&& !factors[PWR_FACTOR_NORMAL_RESET_FLG])
	{
		//BMT.PWRon = (kal_uint8)ABNRESET;
		PWRon=ABNRESET;
	}
	#ifdef __MA_L1__
	else if (factors[PWR_FACTOR_WDT_RESET]&&!factors[PWR_FACTOR_NORMAL_RESET_FLG]&&(KAL_TRUE == query_mas_mode()))
	{
		//BMT.PWRon = (kal_uint8)PWRKEYPWRON;
		PWRon=PWRKEYPWRON;
	}
	#endif // #ifdef __MA_L1__
	else if ((factors[PWR_FACTOR_CHARGER_IN]&&!factors[PWR_FACTOR_POWER_KEY])||
	         (factors[PWR_FACTOR_CHARGER_IN]&&factors[PWR_FACTOR_POWER_KEY]&&!factors[PWR_FACTOR_RTCPWRON_FLG]))
	{
		//BMT.PWRon = (kal_uint8)CHRPWRON;
		PWRon=CHRPWRON;
	}
	#ifdef __USB_ENABLE__
	else if ((factors[PWR_FACTOR_USB_IN]&&!factors[PWR_FACTOR_POWER_KEY]&&factors[PWR_FACTOR_WDT_RESET]&&
	         !factors[PWR_FACTOR_NORMAL_RESET_FLG]&&factors[PWR_FACTOR_USBMS_PWRON_FLG]))
	{
		#if defined(DRV_BMT_NONE_USB_POWER_ON)
		//BMT.PWRon = (kal_uint8)CHRPWRON;
		PWRon=CHRPWRON;
		#else //#if defined(DRV_BMT_NONE_USB_POWER_ON)
		//BMT.PWRon = (kal_uint8)USBPWRON_WDT;
		PWRon=USBPWRON_WDT;
		#endif //#if defined(DRV_BMT_NONE_USB_POWER_ON)
	}
	else if ((factors[PWR_FACTOR_USB_IN]&&!factors[PWR_FACTOR_POWER_KEY])||
	         (factors[PWR_FACTOR_USB_IN]&&factors[PWR_FACTOR_POWER_KEY]&&!factors[PWR_FACTOR_USBMS_PWRON_FLG])
	        )
	{
		#if defined(DRV_BMT_NONE_USB_POWER_ON)
		//BMT.PWRon = (kal_uint8)CHRPWRON;
		PWRon=CHRPWRON;
		#else //#if defined(DRV_BMT_NONE_USB_POWER_ON)
		//BMT.PWRon = (kal_uint8)USBPWRON;
		PWRon=USBPWRON;
		#endif //#if defined(DRV_BMT_NONE_USB_POWER_ON)
	}
	#endif // #ifdef __USB_ENABLE__
	else if ((factors[PWR_FACTOR_RTC_EXPIRE]&&!factors[PWR_FACTOR_RTCPWRON_FLG]))
	{
		//BMT.PWRon = (kal_uint8)RTCPWRON;
		PWRon=RTCPWRON;
	}  
	else
	{
        PWRon = UNKNOWN_PWRON;
	}

    
    if ((PWRon == ABNRESET) || (PWRon == UNKNOWN_PWRON))
    {
        return_value = 0;
    }
    else 
    {   return_value = 0;
        if (factors[PWR_FACTOR_POWER_KEY])
            return_value |= PWR_FACTOR_BL_POWER_KEY;   
        
        if (factors[PWR_FACTOR_CHARGER_IN])
            return_value |= PWR_FACTOR_BL_CABLE_IN;
        
        if (factors[PWR_FACTOR_RTC_EXPIRE])
            return_value |= PWR_FACTOR_BL_RTC_EXPIRE;

        if (factors[PWR_FACTOR_NORMAL_RESET_FLG])
            return_value |= PWR_FACTOR_BL_NORMAL_RESET_FLG;

        if (factors[PWR_FACTOR_CHRPWRON_FLG])
            return_value |= PWR_FACTOR_BL_CHRPWRON_FLG;

        if (factors[PWR_FACTOR_USBMS_PWRON_FLG])
            return_value |= PWR_FACTOR_BL_USBMS_PWRON_FLG;

        if (factors[PWR_FACTOR_RTCPWRON_FLG])
            return_value |= PWR_FACTOR_BL_RTCPWRON_FLG;

        if (factors[PWR_FACTOR_SWITCH2IDLE_FLG] | factors[PWR_FACTOR_SWITCH2CHR_FLG] | factors[PWR_FACTOR_SWITCH2USB_FLG])
            return_value |= PWR_FACTOR_BL_FACTORY_FLG;  
    }
    
    return return_value;
     

#else // #if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)
	//BMT.PWRon = PWRKEYPWRON;
    PWRon=PWRKEYPWRON;
    return_value = 0x1;

    return return_value;
#endif // #if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)

}

#endif
