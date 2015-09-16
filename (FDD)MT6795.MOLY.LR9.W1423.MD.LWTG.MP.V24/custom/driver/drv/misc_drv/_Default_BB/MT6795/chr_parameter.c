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
 *    chr_parameter.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defined for charging parameters.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "drv_comm.h"
#include "adc.h"
#include "bmt.h"
#include "dcl.h"
//MSBB remove #include "kal_non_specific_general_types.h"

#define _ADC_DETECT_USB_CHARGER_
//#define _GPIO_DETECT_USB_CHARGER_


#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
bmt_customized_high_vchg_struct bmt_custom_high_vchg_def =
{
    PMU_VOLT_10_500000_V, // VCHG_HV_VTH
    {
        {5250000, PMU_CHARGE_CURRENT_800_00_MA, 480},
        {5500000, PMU_CHARGE_CURRENT_650_00_MA, 600},
        {6000000, PMU_CHARGE_CURRENT_550_00_MA, 700},
        {6500000, PMU_CHARGE_CURRENT_450_00_MA, 860},
        {7500000, PMU_CHARGE_CURRENT_400_00_MA, 1920},        
        {9000000, PMU_CHARGE_CURRENT_200_00_MA, 1920},
        {9000000, PMU_CHARGE_CURRENT_200_00_MA, 1920},                  
    }, 
};

bmt_customized_high_vchg_struct *bmt_get_customized_high_vchg_para(void)         
{
   return (&bmt_custom_high_vchg_def);
}   

#endif //#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)

/*************************************************************************
* FUNCTION
*	bmt_charger_action
*
* DESCRIPTION
*	This function is to do something whenever AC is plug-in
*
* PARAMETERS
*	AC plug in or plug out
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef __CUST_NEW__
   //#define BMT_CHARGER_ACTION_WITH_GPIO
   #undef BMT_CHARGER_ACTION_WITH_GPIO
   #ifdef BMT_CHARGER_ACTION_WITH_GPIO
   extern const char gpio_bmt_charger_action_pin;
   #endif
#endif /* __CUST_NEW__ */
void bmt_charger_action(kal_bool in)
{
#ifdef __CUST_NEW__
	#ifdef BMT_CHARGER_ACTION_WITH_GPIO
    DCL_HANDLE gpio_handle;
    gpio_handle = DclGPIO_Open(DCL_GPIO, gpio_bmt_charger_action_pin);	
    if(in==KAL_FALSE)
        DclGPIO_Control(gpio_handle, GPIO_CMD_WRITE_LOW, 0);
    else if(in==KAL_TRUE)
        DclGPIO_Control(gpio_handle, GPIO_CMD_WRITE_HIGH, 0);
    else
    {
    	DclGPIO_Close(gpio_handle);
    	ASSERT(0);
    }
    DclGPIO_Close(gpio_handle);
  	#endif /* BMT_CHARGER_ACTION_WITH_GPIO */
#else /*  __CUST_NEW__ */
   	kal_uint16 gpio_pin=0xff;
    DCL_HANDLE gpio_handle;
    gpio_handle = DclGPIO_Open(DCL_GPIO, gpio_pin);	      
    if(gpio_pin!=0xff)
    {    
        DclGPIO_Control(gpio_handle,GPIO_CMD_SET_MODE_0,0);
      
        if(in==KAL_FALSE)
            DclGPIO_Control(gpio_handle, GPIO_CMD_WRITE_LOW, 0);
        else if(in==KAL_TRUE)
            DclGPIO_Control(gpio_handle, GPIO_CMD_WRITE_HIGH, 0);
        else
        {
            DclGPIO_Close(gpio_handle);
            ASSERT(0);
        }    
        
        DclGPIO_Close(gpio_handle);
    }      
#endif /* __CUST_NEW__ */
}   
/*usb charging*/

#ifdef __CUST_NEW__
#if defined(_GPIO_DETECT_USB_CHARGER_) 
extern const char gpio_bmt_check_ac_usb_pin;
#endif /* defined(_GPIO_DETECT_USB_CHARGER_) */
#endif /* __CUST_NEW__ */

#if defined(__USB_ENABLE__)

// KAL_TRUE: charging directly without host's grant, KAL_FALSE: charging with host's grant
static const kal_bool enable_usb_charge = KAL_TRUE;	
kal_bool bmt_support_usb_charge(void)
{
   return (enable_usb_charge);
}   


#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
// usb is plugged in if  < 1.4V, otherwise it is charger.
static const kal_int32	chr_usb_detect_volt = 1400000;  
kal_int32 bmt_get_chr_usb_detect_volt(void)
{
   return (kal_int32)(chr_usb_detect_volt);
}   
/*************************************************************************
* FUNCTION
*	bmt_check_ac_usb
*
* DESCRIPTION
*	This function is to tell USB and AC
*
* PARAMETERS
*	measurement voltage
*
* RETURNS
*  AC or USB
*
* GLOBALS AFFECTED
*
*************************************************************************/
charger_usb_present_enum bmt_check_ac_usb(kal_int32 vol)
{
   #ifdef _GPIO_DETECT_USB_CHARGER_	
    kal_uint16 gpio_pin;
    kal_uint8  gpio_state;
    DCL_HANDLE gpio_handle;
    GPIO_CTRL_READ_T gpio_data;
   #endif	

    #ifdef _ADC_DETECT_USB_CHARGER_
    // Use ADC to get voltage value (Analog method)
    /* Use voltage to tell AC/USB */
   	if(vol<chr_usb_detect_volt)      
		return USB_PRESENT;
   	else 
      	return CHARGER_PRESENT;  
   #elif defined(_GPIO_DETECT_USB_CHARGER_) // #ifdef _ADC_DETECT_USB_CHARGER_
   	/* 
        Kerwin:
        use GPIO state(high/low) to differentiate voltage value,
        because for digital(GPIO is digital due to 0/1),
        GPIO=1, if voltage > V
        GPIO=0, if voltage < V
        use V to differentiate USB or CHARGER,
        the following gpio_pin should be customized according to physical layout
    */
    #ifdef __CUST_NEW__
    gpio_handle = DclGPIO_Open(DCL_GPIO, gpio_bmt_check_ac_usb_pin);   
    DclGPIO_Control(gpio_handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T*)&gpio_data);
    DclGPIO_Close(gpio_handle);   
    gpio_state = gpio_data.u1IOData;
    #else /* __CUST_NEW__ */
    /*use GPIO to tell AC/USB*/
    gpio_pin=1;/*GPIO port number*/
    gpio_handle = DclGPIO_Open(DCL_GPIO, gpio_pin);	   
    DclGPIO_Control(gpio_handle, GPIO_CMD_SET_MODE_0, 0);
    DclGPIO_Control(gpio_handle, GPIO_CMD_SET_DIR_IN, 0);
    DclGPIO_Control(gpio_handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T*)&gpio_data);
    DclGPIO_Close(gpio_handle); 
    gpio_state = gpio_data.u1IOData;
    #endif /* __CUST_NEW__ */
    if(gpio_state)      
		return USB_PRESENT;
    else 
		return CHARGER_PRESENT;        
    #endif // #ifdef _ADC_DETECT_USB_CHARGER_             
}   
#endif // __CHARGER_USB_DETECT_WIHT_ONE_EINT__#endif //__USB_ENABLE__#endif //__USB_ENABLE__

#ifdef __USB_MULTI_CHARGE_CURRENT__

#if defined(PMIC_6305_USB_FUNCTION)
/* The max number is 8, and must be in strict-decreasing order.
   The maximun value must not be larger than 500 and the last
   value in the array must be zero.
*/
const kal_uint16  USB_CHARGE_CURRENT [] =
{
	 (450),
	 (0) /* zero must be in the last item. means no charging for USB. */
};

#define USB_CHARGE_CURRENT_TABLE_SIZE	(sizeof(USB_CHARGE_CURRENT) / sizeof(kal_uint16))
/*************************************************************************
* FUNCTION
*	usb_set_chr_current
*
* DESCRIPTION
*	This function is to set usb charging current. This can be customized
* by the board layout.
*
* PARAMETERS
*	index for USB_CHARGE_CURRENT []
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void usb_set_chr_current(kal_uint8 index)
{
	ASSERT(index < (USB_CHARGE_CURRENT_TABLE_SIZE -1));
    switch(index)
	{	
	case 0: /* 450 mA*/
		/* Set USB charging current for 450mA here. */
		break;
	default:
		break;
	}
	return;
}


const kal_uint8 USB_GetChargeCurrentTableSize(void)
{
	return USB_CHARGE_CURRENT_TABLE_SIZE;
}
#endif /* defined(PMIC_6305_USB_FUNCTION) */

/* Below is just reference codes for MT6318 */
#if defined(PMIC_6318_USB_FUNCTION)
extern void pmic_charging_currnet_ctrl(pmic_charging_current current);

/* The max number is 8, and must be in strict-decreasing order.
   The maximun value must not be larger than 500 and the last
   value in the array must be zero.
*/
const kal_uint16  USB_CHARGE_CURRENT [] =
{
	 (450),
	 (300),
	 (225),
	 (150),
	 (90),
	 (50),
	 (0) /* zero must be in the last item. means no charging for USB. */
};

#define USB_CHARGE_CURRENT_TABLE_SIZE	(sizeof(USB_CHARGE_CURRENT) / sizeof(kal_uint16))
static const pmic_charging_current  PMIC6318_USB_CHARGE_CURRENT[USB_CHARGE_CURRENT_TABLE_SIZE - 1] =
{
   CHR_CURRENT_450,
   CHR_CURRENT_300,
   CHR_CURRENT_225,
   CHR_CURRENT_150,
   CHR_CURRENT_90,
   CHR_CURRENT_50
};
void usb_set_chr_current(kal_uint8 index)
{
	ASSERT(index < (USB_CHARGE_CURRENT_TABLE_SIZE - 1));
	pmic_charging_currnet_ctrl(PMIC6318_USB_CHARGE_CURRENT[index]);
	return;
}


const kal_uint8 USB_GetChargeCurrentTableSize(void)
{
	return USB_CHARGE_CURRENT_TABLE_SIZE;
}
#endif /* defined(PMIC_6318_USB_FUNCTION) */

#endif /* __USB_MULTI_CHARGE_CURRENT__ */
#endif //__USB_ENABLE__


