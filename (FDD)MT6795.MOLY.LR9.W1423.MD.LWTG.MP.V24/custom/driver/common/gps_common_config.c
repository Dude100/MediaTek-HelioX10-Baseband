/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *
 * Filename:
 * ---------
 *	 gps_common_config.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains common configuration for GPS customization
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __GPS_SUPPORT__

#include "reg_base.h"
#include "eint.h"
#include "dcl.h"
#include "intrCtrl.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
//#include "Drv_features_gpio.h"  //jiawang add

        
//extern void DisplayPopup(kal_uint8 *string, kal_uint16 imageId, kal_uint8 imageOnBottom, kal_uint32 popupDuration, kal_uint8 toneId);


typedef  struct {
    unsigned char num_poweronGPS;
    unsigned char pol_poweronGPS;
    unsigned char num_standbyGPS;
    unsigned char pol_standbyGPS;
    unsigned char num_syncGPS;
    unsigned char mode_syncGPS;
    unsigned char num_lpoclk;
    unsigned char mode_lpoclk;
    unsigned char num_urxd;
    unsigned char num_utxd;	
    unsigned char num_ucts;
    unsigned char num_urts;
} sGPIO4GPS;

#ifdef __CUST_NEW__
extern const char gpio_gps_power_pin;
extern const char gpio_gps_standby_pin;
extern const char gpio_gps_sync_pin;
extern const char gpio_gps_32k_pin;
extern const char gpio_gps_utxd_pin;
extern const char gpio_gps_urxd_pin;
extern const char gpio_gps_ucts_pin;
extern const char gpio_gps_urts_pin;

#define GPS_LPO_GPIO_NUM GPIO_MAGIC_NUM
#define GPS_LPO_GPO_NUM  GPO_MAGIC_NUM
#define GPS_UART_GPIO_NUM GPIO_MAGIC_NUM

#else

#define GPS_GPO_MAGIC_NUM	100
#define GPS_LPO_GPIO_NUM          0
#define GPS_LPO_GPO_NUM  GPS_GPO_MAGIC_NUM
#define GPS_UART_GPIO_NUM          0

extern const unsigned char gps_gpio_setting[9];

#endif

extern const unsigned char gps_uart_port_setting;
extern kal_uint8 gps_urxd_mode;
extern kal_uint8 gps_utxd_mode;

#ifdef  MT6256
static void GPS_GPIO_SetClkOut(char clk_num, gpio_clk_mode mode)
{
	DCL_HANDLE handle;
	GPIO_CTRL_SET_CLK_OUT_T data;
	handle=DclGPIO_Open(DCL_GPIO_CLK,clk_num);
	data.u2ClkNum=clk_num;
	data.u2Mode=mode;
	DclGPIO_Control(handle,GPIO_CMD_SET_CLK_OUT,(DCL_CTRL_DATA_T*)&data);
	DclGPIO_Close(handle);	
}


static void GPS_GPIO_SetClkDiv(char clk_num, gpio_clk_div div)
{
    DCL_HANDLE handle;
    GPIO_CTRL_SET_CLK_DIV_T data;
    handle = DclGPIO_Open(DCL_GPIO_CLK, clk_num);
    data.u2ClkNum = clk_num;
    data.u2Div = div;
    DclGPIO_Control(handle, GPIO_CMD_SET_CLK_DIV, (DCL_CTRL_DATA_T*)&data);
    DclGPIO_Close(handle);
}
#endif

#ifdef MT6225
static void GPS_GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
{
	DCL_HANDLE handle;
	handle=DclGPIO_Open(DCL_GPIO,pin);	
	switch(conf_dada)
		{
			case 0:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_0,0);
				break;
			case 1:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_1,0);
				break;
			case 2:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_2,0);
				break;
			case 3:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_3,0);	
				break;
			case 4:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_4,0);	
				break;
			case 5:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_5,0);	
				break;
			case 6:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_6,0);	
				break;
			case 7:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_7,0);	
				break;
			default:
				{
					DclGPIO_Close(handle);
					ASSERT(0);
				}
		}
	DclGPIO_Close(handle);
}
#endif

#ifndef __CUST_NEW__
static void GPS_GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
{
	DCL_HANDLE handle;
	handle=DclGPIO_Open(DCL_GPO,pin);
	switch(conf_dada)
		{
			case 0:
				DclGPIO_Control(handle,GPO_CMD_MODE_SET_0,0);
				break;
			case 1:
				DclGPIO_Control(handle,GPO_CMD_MODE_SET_1,0);
				break;
			case 2:
				DclGPIO_Control(handle,GPO_CMD_MODE_SET_2,0);
				break;
			case 3:
				DclGPIO_Control(handle,GPO_CMD_MODE_SET_3,0);
				break;
			default:
				{
					DclGPIO_Close(handle);
					ASSERT(0);	
				}
		}
		DclGPIO_Close(handle);
}
#endif

void GPS_SetupGPIO(char val, unsigned char pin)
{
#if defined(__SMART_PHONE_MODEM__)
#else
#ifdef __CUST_NEW__
    if (pin >= GPIO_MAGIC_NUM)
    {
    	GPS_GPIO_ModeSetup(pin, val);
    }
    else
    {
    	GPS_GPO_ModeSetup(pin, val);
    }
#else
    if (pin >= GPS_GPO_MAGIC_NUM)
    {
    	GPS_GPO_ModeSetup((pin - GPS_GPO_MAGIC_NUM), val);
    }
    else
    {
    	GPS_GPIO_ModeSetup(pin, val);
    }
#endif
#endif /* __SMART_PHONE_MODEM__ */
}

void GPS_InitGPIO(char direction, unsigned char pin)
{
#if defined(__SMART_PHONE_MODEM__)
#else
	DCL_HANDLE handle;
	handle=DclGPIO_Open(DCL_GPIO,pin);
	if(0==direction)
		DclGPIO_Control(handle,GPIO_CMD_SET_DIR_IN,0);
	else if(1==direction)
		DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);
	else
		ASSERT(0);
	DclGPIO_Close(handle);
#endif /* __SMART_PHONE_MODEM__ */
}

void GPS_WriteGPIO(char val, unsigned char pin)
{
#if defined(__SMART_PHONE_MODEM__)
#else
	DCL_HANDLE handle;
	    
#ifdef __CUST_NEW__
	if (pin >= GPIO_MAGIC_NUM)
	{
		//GPIO_WriteIO(val, pin);
		handle=DclGPIO_Open(DCL_GPIO,pin);	
	    if(0==val)
	    	DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
	    else if(1==val)
	    	DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
	    DclGPIO_Close(handle);			
	}
	else
	{
		//GPO_WriteIO(val, pin);
		handle=DclGPIO_Open(DCL_GPO,pin);	
	    if(0==val)
		    DclGPIO_Control(handle,GPO_CMD_WRITE_LOW,0);
	    else if(1==val)
		    DclGPIO_Control(handle,GPO_CMD_WRITE_HIGH,0);
		DclGPIO_Close(handle);
	}
#else
	if (pin >= GPS_GPO_MAGIC_NUM)
	{
		//GPO_WriteIO(val, (pin - GPS_GPO_MAGIC_NUM));
		handle=DclGPIO_Open(DCL_GPO,(pin - GPS_GPO_MAGIC_NUM));	
	    if(0==val)
		    DclGPIO_Control(handle,GPO_CMD_WRITE_LOW,0);
	    else if(1==val)
		    DclGPIO_Control(handle,GPO_CMD_WRITE_HIGH,0);
		DclGPIO_Close(handle);
	}
	else
	{
		//GPIO_WriteIO(val, pin);
		handle=DclGPIO_Open(DCL_GPIO,pin);	
	    if(0==val)
	    	DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
	    else if(1==val)
	    	DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
	    DclGPIO_Close(handle);
	}
#endif
#endif /* __SMART_PHONE_MODEM__ */
}

void GPS_SetToGPIOMode(kal_uint8 pin)
{
#if defined(__SMART_PHONE_MODEM__)
#else
	kal_uint8 gpio_mode = 0;
	kal_uint8 gpio_pin = pin;

#ifdef __CUST_NEW__
	if (pin >= GPIO_MAGIC_NUM)
	{
		gpio_pin -= GPIO_MAGIC_NUM;
	}
	else
	{
		GPS_GPO_ModeSetup(pin, gpio_mode);
		return;
	}
#else /* #ifdef __CUST_NEW__ */
	if (pin >= GPS_GPO_MAGIC_NUM)
	{
		GPS_GPO_ModeSetup((pin - GPS_GPO_MAGIC_NUM), gpio_mode);
		return;
	}
#endif /* #ifdef __CUST_NEW__ */

	switch (gpio_pin)
	{
#if defined(MT6223) || defined(MT6223P) || defined(MT6223C)
		case 44:
		case 50:
			gpio_mode = 1;
			break;
#elif defined(MT6228) || defined(MT6229) || defined(MT6230)
		case 26: case 27: case 28: case 29: case 30: case 31: 
		case 44: case 45: case 46: case 47:
		case 54: case 55: case 56: case 57: case 58: case 59: case 60: case 61: case 62:
		case 68: case 69: case 70: case 71: case 72: case 73: case 74:
			gpio_mode = 1;
			break;
#endif	
		default:
			gpio_mode = 0;
	}

	GPS_GPIO_ModeSetup(pin, gpio_mode);
#endif /* __SMART_PHONE_MODEM__ */
}

void GPS_PowerOn(kal_uint8 polGPS, kal_uint8 numGPS)
{
#if defined(__SMART_PHONE_MODEM__)
#else
    GPS_WriteGPIO(polGPS, numGPS);  // turn on GPS regulator
#endif /* __SMART_PHONE_MODEM__ */
}

void GPS_PowerOff(kal_uint8 polGPS, kal_uint8 numGPS)
{	
#if defined(__SMART_PHONE_MODEM__)
#else
    GPS_WriteGPIO((1 - polGPS), numGPS);  // turn off GPS regulator
#endif /* __SMART_PHONE_MODEM__ */
}

kal_uint8 GPS_GetLpoMode(kal_uint8 numLpo)
{
    kal_uint8 modeLpo = 0xFF;
#if defined(MT6223) || defined(MT6223P) || defined(MT6223C)
{
	switch (numLpo)
	{
		case (GPS_LPO_GPIO_NUM | 21):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(0, 4);
			#endif
			break;
		case (GPS_LPO_GPIO_NUM | 22):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(1, 4);
			#endif
			break;
		case (GPS_LPO_GPIO_NUM | 23):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(2, 4);
			#endif
			break;
		case (GPS_LPO_GPIO_NUM | 47):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(3, 4);
			#endif
			break;
		case (GPS_LPO_GPIO_NUM | 48):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(4, 4);
			#endif
			break;
		case (GPS_LPO_GPIO_NUM | 49):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(5, 4);
			#endif
			break;
	}
}
#elif defined(MT6225) || defined(MT6225B)
{
	if ((numLpo == (GPS_LPO_GPIO_NUM | 6)) || (numLpo == (GPS_LPO_GPO_NUM | 2)))
		modeLpo = 2;
	else
		modeLpo = 3;
}
#elif defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)                           
{
	modeLpo = 3;
}
#elif defined(MT6228) || defined(MT6229) || defined(MT6230)
{
	if (numLpo == (GPS_LPO_GPIO_NUM | 8))
		modeLpo = 1;
	else
		modeLpo = 3;
}
#elif defined(MT6235) || defined(MT6235B)
{
	switch (numLpo)
	{
		case (GPS_LPO_GPIO_NUM | 0):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(0, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 26):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(1, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 27):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(2, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 45):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(3, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 57):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(4, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 64):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(5, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 65):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(6, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 66):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(7, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 73):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(8, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 74):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(9, 6);
			#endif
			break;
	}
}
#elif defined(MT6236) || defined(MT6236B)
{
	switch (numLpo)
	{
		case (GPS_LPO_GPIO_NUM | 8):  //CLKM0
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(0, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 17):  //CLKM1
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(1, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 20):   //CLKM3
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(3, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 22):  //CLKM3
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(3, 6);
			#endif
			break;			
			
		case (GPS_LPO_GPIO_NUM | 31):   //CLKM3
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(3, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 32):   //CLKM4
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(4, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 33):   //CLKM5
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(5, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 36):   //CLKM2
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(2, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 41):   //CLKM4
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(4, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 42):   //CLKM5
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(5, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 54):   //CLKM3
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(3, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 58):   //CLKM4
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(4, 6);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 63):   //CLKM5
			modeLpo = 1;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(5, 6);
			#endif
			break;
	}
}
#elif defined(MT6238) || defined(MT6239)
{
	switch (numLpo)
	{
		case (GPS_LPO_GPIO_NUM | 57):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(0, 6);
			#endif
			break;
		case (GPS_LPO_GPIO_NUM | 58):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(1, 6);
			#endif
			break;
		case (GPS_LPO_GPIO_NUM | 65):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(2, 6);
			#endif
			break;
		case (GPS_LPO_GPIO_NUM | 8):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(3, 6);
			#endif
			break;
		case (GPS_LPO_GPIO_NUM | 77):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(4, 6);
			#endif
			break;
		case (GPS_LPO_GPIO_NUM | 78):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(5, 6);
			#endif
			break;
		case (GPS_LPO_GPIO_NUM | 50):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(6, 6);
			#endif
			break;
		case (GPS_LPO_GPIO_NUM | 55):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(7, 6);
			#endif
			break;
	}
}
#elif defined(MT6268)
{
	switch (numLpo)
	{
		case (GPS_LPO_GPIO_NUM | 37):
		case (GPS_LPO_GPIO_NUM | 85):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(0, 0x40);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 38):
		case (GPS_LPO_GPIO_NUM | 90):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(1, 0x40);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 43):
		case (GPS_LPO_GPIO_NUM | 44):
		case (GPS_LPO_GPIO_NUM | 60):
		case (GPS_LPO_GPIO_NUM | 80):
		case (GPS_LPO_GPIO_NUM | 98):
		case (GPS_LPO_GPIO_NUM | 99):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(2, 0x40);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 81):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(3, 0x40);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 64):
		case (GPS_LPO_GPIO_NUM | 82):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(4, 0x40);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 83):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(5, 0x40);
			#endif
			break;
	}
}
#elif defined(MT6268T) || defined(MT6268A) || defined(MT6268H)
{
	switch (numLpo)
	{
		case (GPS_LPO_GPIO_NUM | 33):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(0, 0x40);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 34):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(1, 0x40);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 39):
		case (GPS_LPO_GPIO_NUM | 97):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(2, 0x40);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 40):
		case (GPS_LPO_GPIO_NUM | 98):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(3, 0x40);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 81):
		case (GPS_LPO_GPIO_NUM | 99):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(4, 0x40);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 100):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(5, 0x40);
			#endif
			break;
	}
}
#elif defined(MT6253T) || defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
{
	switch (numLpo)
	{
		case (GPS_LPO_GPIO_NUM | 18):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(0, 4);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 3):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(1, 4);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 75):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(2, 4);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 62):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(3, 4);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 61):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(4, 4);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 15):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(5, 4);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 74):
			modeLpo = 1;
			#if defined(DRV_GPIO_CLK_OUT)
			GPS_GPIO_SetClkOut(6, 4);
			#endif
			break;
	}
}
#elif defined(MT6276)
{
#if defined(MT6276_S01)
	switch (numLpo)
	{
		case (GPS_LPO_GPIO_NUM | 9):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(1, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(1, 0);		
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 99):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(2, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(2, 0);		
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 32):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(3, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(3, 0);		
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 33):
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(4, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(4, 0);		
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 34):
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(5, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(5, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 45):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(6, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(6, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 11):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(7, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(7, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 12):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(8, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(8, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 5):
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(9, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(9, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 8):
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(10, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(10, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 71):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(11, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(11, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 72):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(12, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(12, 0);
			#endif
			break;
			
		case (GPS_LPO_GPIO_NUM | 105):
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(13, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(13, 0);
			#endif
			break;
	}
#elif defined(MT6276_S00)
switch (numLpo)
	{
		case (GPS_LPO_GPIO_NUM | 13):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(1, mode_f32k_ck); //001xb	f32k_ck
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 101):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(2, mode_f32k_ck); //001xb	f32k_ck
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 51):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(3, mode_f32k_ck); //001xb	f32k_ck
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 14):
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(4, mode_f32k_ck); //001xb	f32k_ck
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 15):
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(5, mode_f32k_ck); //001xb	f32k_ck
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 27):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(6, mode_f32k_ck); //001xb	f32k_ck
			#endif
			break;
	}
#else
	switch (numLpo)
	{
		case (GPS_LPO_GPIO_NUM | 9):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(1, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(1, 0);		
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 99):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(2, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(2, 0);		
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 32):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(3, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(3, 0);		
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 33):
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(4, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(4, 0);		
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 34):
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(5, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(5, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 45):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(6, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(6, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 11):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(7, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(7, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 12):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(8, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(8, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 5):
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(9, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(9, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 8):
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(10, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(10, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 71):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(11, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(11, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 72):
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(12, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(12, 0);
			#endif
			break;
			
		case (GPS_LPO_GPIO_NUM | 105):
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6276)
			GPS_GPIO_SetClkOut(13, mode_f32k_ck); //001xb	f32k_ck
			GPS_GPIO_SetClkDiv(13, 0);
			#endif
			break;
	}
#endif  /* defined(MT6276_S01) */
}
#elif defined(MT6256)
{
	switch (numLpo)
    {
		case (GPS_LPO_GPIO_NUM | 95): //CLKM0
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6256)
			GPS_GPIO_SetClkOut(0, mode_f32k_ck);
      GPS_GPIO_SetClkDiv(0, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 0): //CLKM1
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6256)
			GPS_GPIO_SetClkOut(1, mode_f32k_ck);
      GPS_GPIO_SetClkDiv(1, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 8): //CLKM2
			modeLpo = 5;
			#if defined(DRV_GPIO_REG_AS_6256)
			GPS_GPIO_SetClkOut(2, mode_f32k_ck);
      GPS_GPIO_SetClkDiv(2, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 5): //CLKM3
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6256)
			GPS_GPIO_SetClkOut(3, 64);
      GPS_GPIO_SetClkDiv(3, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 68):  //CLKM4
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6256)
			GPS_GPIO_SetClkOut(4, mode_f32k_ck);
      GPS_GPIO_SetClkDiv(4, 0);
			#endif
			break;

		case (GPS_LPO_GPIO_NUM | 79):  //CLKM5
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6256)
			GPS_GPIO_SetClkOut(5, mode_f32k_ck);
      GPS_GPIO_SetClkDiv(5, 0);
			#endif
			break;
    }
}
#endif
    return modeLpo;
}

extern kal_uint8 gps_uart_port;

void GPS_GetUartMode(kal_uint8 numUart)
{
#if defined(MT6228) || defined(MT6229) || defined(MT6230)
	switch (numUart)
	{
		case (GPS_UART_GPIO_NUM | 4):
            gps_urxd_mode = 2;
            gps_utxd_mode = 2;
            gps_uart_port = uart_port2;       
            break;
            
		case (GPS_UART_GPIO_NUM | 37):
            gps_urxd_mode = 1;
            gps_utxd_mode = 1;
            gps_uart_port = uart_port2;       
            break;
            
		case (GPS_UART_GPIO_NUM | 39):
            gps_urxd_mode = 1;
            gps_utxd_mode = 1;
            gps_uart_port = uart_port3;       
            break;

        default:
            ASSERT(0);   
            break;
	}
#elif defined(MT6236) || defined(MT6236B)
	switch (numUart)
	{
		case (GPS_UART_GPIO_NUM | 16):
            gps_urxd_mode = 3;
            gps_utxd_mode = 3;
            gps_uart_port = uart_port3;       
            break;
            
		case (GPS_UART_GPIO_NUM | 31):
            gps_urxd_mode = 2;
            gps_utxd_mode = 2;
            gps_uart_port = uart_port2;       
            break;
            
		case (GPS_UART_GPIO_NUM | 39):
            gps_urxd_mode = 1;
            gps_utxd_mode = 1;
            gps_uart_port = uart_port3;       
            break;

        case (GPS_UART_GPIO_NUM | 45):
            gps_urxd_mode = 1;
            gps_utxd_mode = 1;
            gps_uart_port = uart_port2;       
            break;

        case (GPS_UART_GPIO_NUM | 59):
            gps_urxd_mode = 2;
            gps_utxd_mode = 2;
            gps_uart_port = uart_port2;       
            break;

        case (GPS_UART_GPIO_NUM | 61):
            gps_urxd_mode = 2;
            gps_utxd_mode = 2;
            gps_uart_port = uart_port3;       
            break;

        default:
            ASSERT(0);   
            break;
	}
#elif defined(MT6276)

#if defined(MT6276_S01)
	switch (numUart)
	{	                
		case (GPS_UART_GPIO_NUM | 13):
            gps_urxd_mode = 1;
            gps_utxd_mode = 1;
            gps_uart_port = uart_port3;       
            break;
            
		case (GPS_UART_GPIO_NUM | 14):
            gps_urxd_mode = 2;
            gps_utxd_mode = 2;
            gps_uart_port = uart_port2;       
            break;
            
		case (GPS_UART_GPIO_NUM | 17):
            gps_urxd_mode = 3;
            gps_utxd_mode = 3;
            gps_uart_port = uart_port3;       
            break;
            
		case (GPS_UART_GPIO_NUM | 18):
            gps_urxd_mode = 4;
            gps_utxd_mode = 4;
            gps_uart_port = uart_port3;       
            break;
            
		case (GPS_UART_GPIO_NUM | 36):
            gps_urxd_mode = 2;
            gps_utxd_mode = 2;
            gps_uart_port = uart_port3;       
            break;

         default:
            ASSERT(0);   
            break;
	}
#elif defined(MT6276_S00)
	switch (numUart)
	{
		case (GPS_UART_GPIO_NUM | 18):
            gps_urxd_mode = 2;
            gps_utxd_mode = 2;
            gps_uart_port = uart_port3;       
            break;
            
		case (GPS_UART_GPIO_NUM | 46):
            gps_urxd_mode = 3;
            gps_utxd_mode = 3;
            gps_uart_port = uart_port3;       
            break;
            
		case (GPS_UART_GPIO_NUM | 52):
            gps_urxd_mode = 1;
            gps_utxd_mode = 1;
            gps_uart_port = uart_port2;       
            break;

         default:
            ASSERT(0);   
            break;
	}
#else
    switch (numUart)
	{	                
		case (GPS_UART_GPIO_NUM | 13):
            gps_urxd_mode = 1;
            gps_utxd_mode = 1;
            gps_uart_port = uart_port3;       
            break;
            
		case (GPS_UART_GPIO_NUM | 14):
            gps_urxd_mode = 2;
            gps_utxd_mode = 2;
            gps_uart_port = uart_port2;       
            break;
            
		case (GPS_UART_GPIO_NUM | 17):
            gps_urxd_mode = 3;
            gps_utxd_mode = 3;
            gps_uart_port = uart_port3;       
            break;
            
		case (GPS_UART_GPIO_NUM | 18):
            gps_urxd_mode = 4;
            gps_utxd_mode = 4;
            gps_uart_port = uart_port3;       
            break;
            
		case (GPS_UART_GPIO_NUM | 36):
            gps_urxd_mode = 2;
            gps_utxd_mode = 2;
            gps_uart_port = uart_port3;       
            break;

         default:
            ASSERT(0);   
            break;
	}
#endif  /* defined(MT6276_S01) */

#elif defined(MT6256)

	switch (numUart)
	{	                
		case (GPS_UART_GPIO_NUM | 6):
            gps_urxd_mode = 2;
            gps_utxd_mode = 2;
            gps_uart_port = uart_port3;       
            break;
            
		case (GPS_UART_GPIO_NUM | 8):
            gps_urxd_mode = 1;
            gps_utxd_mode = 1;
            gps_uart_port = uart_port2;       
            break;
            
		case (GPS_UART_GPIO_NUM | 9):
            gps_urxd_mode = 7;
            gps_utxd_mode = 7;
            gps_uart_port = uart_port2;       
            break;
            
		case (GPS_UART_GPIO_NUM | 10):
            gps_urxd_mode = 2;
            gps_utxd_mode = 2;
            gps_uart_port = uart_port3;       
            break;
            
		case (GPS_UART_GPIO_NUM | 11):
            gps_urxd_mode = 7;
            gps_utxd_mode = 7;
            gps_uart_port = uart_port3;       
            break;

    case (GPS_UART_GPIO_NUM | 21):
            gps_urxd_mode = 2;
            gps_utxd_mode = 2;
            gps_uart_port = uart_port3;       
            break;

    case (GPS_UART_GPIO_NUM | 92):
            gps_urxd_mode = 4;
            gps_utxd_mode = 4;
            gps_uart_port = uart_port2;       
            break;

    default:
            ASSERT(0);   
            break;
	}
#else
    gps_urxd_mode = 1;
    gps_utxd_mode = 1;   
    gps_uart_port = gps_uart_port_setting;      
#endif    
}

kal_uint8 GPS_GetSyncMode(kal_uint8 numSync)
{
    kal_uint8 modeSync = 0xFF;
    
#if defined(MT6276)

#if defined(MT6276_S01)
	switch (numSync)
	{	                
		case (GPS_UART_GPIO_NUM | 21):
            modeSync = 2;
            break;
            
		case (GPS_UART_GPIO_NUM | 34):
            modeSync = 3;
            break;
            
		default:
            ASSERT(0);   
            break;
	}
#elif defined(MT6276_S00)
	switch (numSync)
	{
		case (GPS_UART_GPIO_NUM | 15):
            modeSync = 3;
            break;
            
		case (GPS_UART_GPIO_NUM | 17):
            modeSync = 3;
            break;            

         default:
            ASSERT(0);   
            break;
	}
#else
    switch (numSync)
	{	                
		case (GPS_UART_GPIO_NUM | 21):
            modeSync = 2;
            break;
            
		case (GPS_UART_GPIO_NUM | 34):
            modeSync = 3;
            break;
            
         default:
            ASSERT(0);   
            break;
	}
#endif  /* defined(MT6276_S01) */
     
#endif    
    return modeSync;
}


void GPS_AssignGpioPins(sGPIO4GPS *gpio)
{
#ifdef __CUST_NEW__
	
    // power on pin
    gpio->num_poweronGPS = gpio_gps_power_pin;  
    gpio->pol_poweronGPS = 1;
    
    // standby pin
    gpio->num_standbyGPS = gpio_gps_standby_pin;
    gpio->pol_standbyGPS = 0;
    
    // sync pin
    gpio->num_syncGPS = gpio_gps_sync_pin;         
    if (0xFF != gpio->num_syncGPS)
    {
        gpio->mode_syncGPS = GPS_GetSyncMode(gpio->num_syncGPS);
        if (0xFF == gpio->mode_syncGPS)
        {
            ASSERT(0);
        }
    }
    
    // lpo clock pin
    gpio->num_lpoclk = gpio_gps_32k_pin;
    if (0xFF != gpio->num_lpoclk)
    {
        gpio->mode_lpoclk = GPS_GetLpoMode(gpio->num_lpoclk);
        if (0xFF == gpio->mode_lpoclk)
        {
            //DisplayPopup((kal_uint8*)L"The pin of GPIO for lpoclk is wrong!", IMG_GLOBAL_ERROR, 0, 5000, 0); 
            ASSERT(0);
        }
    }
 
    // UART pin
    gpio->num_urxd = gpio_gps_urxd_pin;
    gpio->num_utxd = gpio_gps_utxd_pin;
    
    gpio->num_ucts = gpio_gps_ucts_pin;		// Non flow control
    gpio->num_urts = gpio_gps_urts_pin;		// Non flow control
    
    GPS_GetUartMode(gpio->num_urxd);
    
#else
    // power on pin
    gpio->num_poweronGPS = gps_gpio_setting[0];
    gpio->pol_poweronGPS = gps_gpio_setting[1];
    
    // standby pin
    gpio->num_standbyGPS = gps_gpio_setting[2];
    gpio->pol_standbyGPS = gps_gpio_setting[3];

    // sync pin
    gpio->num_syncGPS = gps_gpio_setting[4];
    if (0xFF != gpio->num_syncGPS)
    {
        gpio->mode_syncGPS = GPS_GetSyncMode(gpio->num_syncGPS);
        if (0xFF == gpio->mode_syncGPS)
        {
            ASSERT(0);
        }
    }

    // lpo clock pin
    gpio->num_lpoclk = gps_gpio_setting[6];
    if (0xFF != gpio->num_lpoclk)
    {
        gpio->mode_lpoclk = GPS_GetLpoMode(gpio->num_lpoclk);
        if (0xFF == gpio->mode_lpoclk)
        {
            //DisplayPopup((kal_uint8*)L"The pin of GPIO for lpoclk is wrong!", IMG_GLOBAL_ERROR, 0, 5000, 0);    
            ASSERT(0);
        }
    }
    gpio->num_urxd = gps_gpio_setting[7];
    gpio->num_utxd = gps_gpio_setting[8];
    gpio->num_ucts = gps_gpio_setting[9];
    gpio->num_urts = gps_gpio_setting[10];
    
    GPS_GetUartMode(gpio->num_urxd);
    
#endif
               
    if (gpio->num_poweronGPS != 0xFF)
    {
    	GPS_InitGPIO(1, gpio->num_poweronGPS);		// set direction (output)
    	//GPS_SetupGPIO(0, gpio->num_poweronGPS);	// set to gpio mode
        GPS_SetToGPIOMode(gpio->num_poweronGPS);        
    	GPS_WriteGPIO(0, gpio->num_poweronGPS);		// set ouput low
    }
    if(gpio->num_standbyGPS != 0xFF)
    {
    	GPS_InitGPIO(1, gpio->num_standbyGPS);		// set direction (output)
    	//GPS_SetupGPIO(0, gpio->num_standbyGPS);	// set to gpio mode
        GPS_SetToGPIOMode(gpio->num_standbyGPS);
    	GPS_WriteGPIO(0, gpio->num_standbyGPS);		// set ouput low
    }
    if(gpio->num_syncGPS != 0xFF)
    {
    	GPS_InitGPIO(1, gpio->num_syncGPS);		// set direction (output)
    	//GPS_SetupGPIO(0, gpio->num_syncGPS);		// set to gpio mode
        GPS_SetToGPIOMode(gpio->num_syncGPS);
    	GPS_WriteGPIO(0, gpio->num_syncGPS);		// set ouput low
    }
    if(gpio->num_lpoclk != 0xFF)
    {
    	GPS_InitGPIO(1, gpio->num_lpoclk);		// set direction (output)
    	//GPS_SetupGPIO(0, gpio->num_lpoclk);	// set to gpio mode
    	GPS_SetToGPIOMode(gpio->num_lpoclk);
        GPS_WriteGPIO(0, gpio->num_lpoclk);		// set ouput low
    }
    
    GPS_InitGPIO(1, gpio->num_urxd);			// set direction (output)
    //GPS_SetupGPIO(0, gpio->num_urxd);			// set to gpio mode
    GPS_SetToGPIOMode(gpio->num_urxd);
    GPS_WriteGPIO(0, gpio->num_urxd);			// set ouput low
    
    GPS_InitGPIO(1, gpio->num_utxd);			// set direction (output)
    //GPS_SetupGPIO(0, gpio->num_utxd);			// set to gpio mode
    GPS_SetToGPIOMode(gpio->num_utxd);
    GPS_WriteGPIO(0, gpio->num_utxd);			// set ouput low
    
    if(gpio->num_ucts != 0xFF)
    {
    	GPS_InitGPIO(1, gpio->num_ucts);			// set direction (output)
    	//GPS_SetupGPIO(0, gpio->num_ucts);			// set to gpio mode
    	GPS_SetToGPIOMode(gpio->num_ucts);
        GPS_WriteGPIO(0, gpio->num_ucts);			// set ouput low
    
    	GPS_InitGPIO(1, gpio->num_urts);			// set direction (output)
    	//GPS_SetupGPIO(0, gpio->num_urts);			// set to gpio mode
        GPS_SetToGPIOMode(gpio->num_urts);
    	GPS_WriteGPIO(0, gpio->num_urts);			// set ouput low
    }  
}

kal_uint8 GPS_AssignEintPins()
{
    kal_uint8 eint_channel;
    eint_channel = custom_eint_get_channel( gps_eint_chann );
    // To prevent use wrong EINT
    if (eint_channel != EINT_CHANNEL_NOT_EXIST)
    {
#if defined (MT6223) || defined(MT6223P) || defined(MT6223C) 
    /* Check chip allowed EINT2~7(6223) for level trigger. */
        switch (eint_channel)
        {
            case 2:
                /* GPIO42 = Mode1(EINT2) */
                GPS_GPIO_ModeSetup(42, 1);
                break;
            case 3:
                /* GPIO43 = Mode1(EINT3) */
                GPS_GPIO_ModeSetup(43, 1);
        	    break;
            case 4:
                /* GPIO26 = Mode2(EINT4) */
                GPS_GPIO_ModeSetup(26, 2);
                break;
            case 5:
                /* GPIO27 = Mode2(EINT5) */
                GPS_GPIO_ModeSetup(27, 2);
                break;
            case 6:
                /* GPIO28 = Mode2(EINT6) */
                GPS_GPIO_ModeSetup(28, 2);
                break;
            case 7:
                /* GPIO14 = Mode3(EINT7) */
                GPS_GPIO_ModeSetup(14, 3);
                break;
            default:
                /* only handle EINT2~7*/
                break;
        }		  		
#elif defined(MT6225) || defined(MT6225B) 
        switch (eint_channel)
        {
            case 4:
                /* GPIO0 = MODE3(EINT4) */
                GPS_GPIO_ModeSetup(0, 3);
                break;
            case 5:
                /* GPIO1 = MODE3(EINT5) */
                GPS_GPIO_ModeSetup(1, 3);
                break;
            case 6:
                /* GPIO2 = MODE3(EINT6) */
                GPS_GPIO_ModeSetup(2, 3);
                break;
            case 7:
                /* GPIO3 = MODE3(EINT7) */
                GPS_GPIO_ModeSetup(3, 3);
                break;
            default:
                /* only handle EINT4~7*/
                break;
        }       
#elif defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
        switch (eint_channel)
        {
             case 4:
                 /* GPIO36 = Mode3(EINT4) */
                 GPS_GPIO_ModeSetup(36, 3);
                 break;
             case 5:
                 /* GPIO34 = Mode2(EINT5) */
                 GPS_GPIO_ModeSetup(34, 2);
                 break;
             case 6:
                 /* GPIO35 = Mode3(EINT6) */
                 GPS_GPIO_ModeSetup(35, 3);
                 break;
             case 7:
                 /* GPIO33 = Mode2(EINT7) */
                 GPS_GPIO_ModeSetup(33, 2);
                 break;
             default:
                 /* only handle EINT4~7*/
                 break;
        }
#elif defined(MT6228) || defined(MT6229) || defined(MT6230)
        switch (eint_channel)
        {
            case 4:
                /* no EINT4 */
                //DisplayPopup((kal_uint8*)L"Do not use EINT4 on this chip!", IMG_GLOBAL_ERROR, 0, 5000, 0);   
                ASSERT(0);
                break;
            case 5:
                /* GPIO35 = MODE0(GPIO input = EINT5) */
                GPS_GPIO_ModeSetup(35, 0);
                GPIO_InitIO(0, 35);/* 0=input, 1=output*/
                break;
            case 6:
                /* GPIO37 = MODE1(UART2 RXD = EINT6) */
                //DisplayPopup((kal_uint8*)L"Do not use EINT6 on this chip!", IMG_GLOBAL_ERROR, 0, 5000, 0);                   
                ASSERT(0);
                break;
            case 7:
                /* GPIO8 = MODE0(GPIO input = EINT7) */
                GPS_GPIO_ModeSetup(8, 0);
                GPIO_InitIO(0, 8);/* 0=input, 1=output*/
                break;
#if defined(MT6229) || defined(MT6230)
            case 8:
                /* GPIO63 = MODE2(GPIO input = EINT7) */
                GPS_GPIO_ModeSetup(63, 2);
                break;
#endif
            default:
                /* only handle EINT4~7(8)*/
                break;
        }
#elif defined(MT6235) || defined(MT6235B)
        switch (eint_channel)
        {
            case 3:
                /* GPIO44 = MODE1(GPIO input = EINT3) */
                GPS_GPIO_ModeSetup(44, 1);
                break;
            case 4:
                /* GPIO45 = MODE1(GPIO input = EINT4) */
                GPS_GPIO_ModeSetup(45, 1);
                break;
            case 5:
                /* GPIO46 = MODE1(GPIO input = EINT5) */
                GPS_GPIO_ModeSetup(46, 1);

                break;
            case 6:
                /* GPIO47 = MODE1(GPIO input = EINT6) */
                GPS_GPIO_ModeSetup(47, 1);
                break;
            case 7:
                /* GPIO48 = MODE1(GPIO input = EINT7) */
                GPS_GPIO_ModeSetup(48, 1);
                break;
            default:
                /* only handle EINT3~7*/
            	break;
        }
#elif defined(MT6236) || defined(MT6236B)
        switch (eint_channel)
        {
            case 0:
                /* GPIO41 = MODE1(GPIO input = EINT0) */
                GPS_GPIO_ModeSetup(41, 1);
                break;
            case 1:
                /* GPIO42 = MODE1(GPIO input = EINT1) */
                GPS_GPIO_ModeSetup(42, 1);
                break;
            case 2:
                /* GPIO43 = MODE1(GPIO input = EINT2) */
                GPS_GPIO_ModeSetup(43, 1);

                break;
            case 3:
                /* GPIO44 = MODE1(GPIO input = EINT3) */
                GPS_GPIO_ModeSetup(44, 1);
                break;
            case 4:
                /* GPIO52 = MODE1(GPIO input = EINT4) */
                GPS_GPIO_ModeSetup(52, 1);
                break;
            case 5:
                /* GPIO53 = MODE1(GPIO input = EINT5) */
                GPS_GPIO_ModeSetup(53, 1);
                break;
            case 6:
                /* GPIO54 = MODE1(GPIO input = EINT6) */
                GPS_GPIO_ModeSetup(54, 1);
                break;
            default:
                /* only handle EINT0~6*/
            	break;
        }
#elif defined(MT6238) || defined(MT6239)
        switch (eint_channel)
        {
            case 0:
                /* GPIO77 = Mode1(EINT0) */
                GPS_GPIO_ModeSetup(77, 1);           
                break;
            case 1:
                /* GPIO78 = Mode1(EINT1) */
                GPS_GPIO_ModeSetup(78, 1);             
                break;
            case 2:
                /* GPIO79 = Mode1(EINT2) */
                GPS_GPIO_ModeSetup(79, 1);              
                break;
            case 3:
                /* GPIO33 = Mode1(EINT3) */
                GPS_GPIO_ModeSetup(33, 1);               
                break;
            case 4:
                /* GPIO34 = Mode1(EINT4) */
                GPS_GPIO_ModeSetup(34, 1);             
                break;
            case 5:
                /* GPIO35 = Mode1(EINT5) */
                GPS_GPIO_ModeSetup(35, 1);               
                break;
            case 6:
                /* GPIO36 = Mode1(EINT6) */
                GPS_GPIO_ModeSetup(36, 1);              
                break;
            case 7:
                /* GPIO37 = Mode1(EINT7) */
                GPS_GPIO_ModeSetup(37, 1);             
                break;
        }
#elif defined(MT6268)
		switch (eint_channel)
		{
			case 0:
				GPS_GPIO_ModeSetup(94, 1);
			  break;
			case 1:
				GPS_GPIO_ModeSetup(95, 1);
			  break;
			case 2:
				GPS_GPIO_ModeSetup(49, 1);
			  break;
			case 3:
				GPS_GPIO_ModeSetup(50, 1);
			  break;
			case 4:
				GPS_GPIO_ModeSetup(96, 1);
				break;
			case 5:
				GPS_GPIO_ModeSetup(97, 1);
				break;
			case 6:
				GPS_GPIO_ModeSetup(82, 1);
				break;
			case 7:
				GPS_GPIO_ModeSetup(83, 1);
				break;
			default:
					//DisplayPopup((kal_uint8*)L"Please assign valid GPS_EINT_NO!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined(MT6268T) || defined(MT6268A)  || defined(MT6268H)
        switch (eint_channel)
        {
            case 2:
                /* GPIO45 = Mode1(EINT2) */
                GPS_GPIO_ModeSetup(45, 1);
                break;
            case 3:
                /* GPIO46 = Mode1(EINT3) */
                GPS_GPIO_ModeSetup(46, 1);
                break;
            case 6:
                /* GPIO99 = Mode1(EINT6) */
                GPS_GPIO_ModeSetup(99, 1);
                break;
            case 7:
                /* GPIO100 = Mode1(EINT7) */
                GPS_GPIO_ModeSetup(100, 1);
                break;
        }
#elif defined(MT6253T) || defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
		switch (eint_channel)
		{
			case 0:
				GPS_GPIO_ModeSetup(64, 1);
				break;
			case 1:
				GPS_GPIO_ModeSetup(63, 1);
				break;
			case 2:
				GPS_GPIO_ModeSetup(62, 1);
				break;
			case 3:
				GPS_GPIO_ModeSetup(61, 1);
				break;
			case 4:
				GPS_GPIO_ModeSetup(1, 2);
			  break;
			case 5:
				GPS_GPIO_ModeSetup(8, 2);
			  break;
			case 6:
				GPS_GPIO_ModeSetup(76, 2);
				break;
			default:
					//DisplayPopup((kal_uint8*)L"Please assign valid GPS_EINT_NO!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined(MT6276)

#if defined(MT6276_S01)
        switch (eint_channel)
		{
			case 0:
				GPS_GPIO_ModeSetup(33, 1);
				break;
			case 1:
				GPS_GPIO_ModeSetup(34, 1);
				break;
			case 2:
				GPS_GPIO_ModeSetup(35, 1);
				break;
			case 3:
				GPS_GPIO_ModeSetup(20, 1);
				break;
			case 4:
				GPS_GPIO_ModeSetup(21, 1);
			    break;
			case 5:
				GPS_GPIO_ModeSetup(89, 3);
			    break;
			case 6:
				GPS_GPIO_ModeSetup(14, 3);
				break;
			case 7:
				GPS_GPIO_ModeSetup(13, 3);
				break;
			case 8:
				GPS_GPIO_ModeSetup(31, 3);
				break;
			case 9:
				GPS_GPIO_ModeSetup(0, 3);
				break;
			case 10:
				GPS_GPIO_ModeSetup(99, 2);
				break;
			case 11:
				GPS_GPIO_ModeSetup(73, 3);
				break;
			case 12:
				GPS_GPIO_ModeSetup(77, 2);
				break;
			case 13:
				GPS_GPIO_ModeSetup(78, 2);
				break;
			case 14:
				GPS_GPIO_ModeSetup(38, 2);
				break;
			case 15:
				GPS_GPIO_ModeSetup(39, 2);
				break;
			case 16:
				GPS_GPIO_ModeSetup(46, 2);
				break;
			case 17:
				GPS_GPIO_ModeSetup(47, 2);
				break;
			default:
					//DisplayPopup((kal_uint8*)L"Please assign valid GPS_EINT_NO!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined(MT6276_S00)
        switch (eint_channel)
		{
			case 0:
				GPS_GPIO_ModeSetup(14, 1);
				break;
			case 1:
				GPS_GPIO_ModeSetup(15, 1);
				break;
			case 2:
				GPS_GPIO_ModeSetup(16, 1);
				break;
			case 3:
				GPS_GPIO_ModeSetup(54, 1);
				break;
			case 4:
				GPS_GPIO_ModeSetup(90, 3);
			    break;
			case 5:
				GPS_GPIO_ModeSetup(91, 3);
			    break;
			case 6:
				GPS_GPIO_ModeSetup(30, 2);
				break;
			case 7:
				GPS_GPIO_ModeSetup(31, 2);
				break;
			case 8:
				GPS_GPIO_ModeSetup(50, 3);
				break;
			case 9:
				GPS_GPIO_ModeSetup(4, 3);
				break;
			case 10:
				GPS_GPIO_ModeSetup(101, 2);
				break;
			case 11:
				GPS_GPIO_ModeSetup(81, 3);
				break;
			case 12:
				GPS_GPIO_ModeSetup(85, 2);
				break;
			case 13:
				GPS_GPIO_ModeSetup(86, 2);
				break;
			case 14:
				GPS_GPIO_ModeSetup(20, 2);
				break;
			case 15:
				GPS_GPIO_ModeSetup(21, 2);
				break;
			case 16:
				GPS_GPIO_ModeSetup(28, 2);
				break;
			case 17:
				GPS_GPIO_ModeSetup(29, 2);
				break;
			default:
					//DisplayPopup((kal_uint8*)L"Please assign valid GPS_EINT_NO!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#else
        switch (eint_channel)
		{
			case 0:
				GPS_GPIO_ModeSetup(33, 1);
				break;
			case 1:
				GPS_GPIO_ModeSetup(34, 1);
				break;
			case 2:
				GPS_GPIO_ModeSetup(35, 1);
				break;
			case 3:
				GPS_GPIO_ModeSetup(20, 1);
				break;
			case 4:
				GPS_GPIO_ModeSetup(21, 1);
			    break;
			case 5:
				GPS_GPIO_ModeSetup(89, 3);
			    break;
			case 6:
				GPS_GPIO_ModeSetup(14, 3);
				break;
			case 7:
				GPS_GPIO_ModeSetup(13, 3);
				break;
			case 8:
				GPS_GPIO_ModeSetup(31, 3);
				break;
			case 9:
				GPS_GPIO_ModeSetup(0, 3);
				break;
			case 10:
				GPS_GPIO_ModeSetup(99, 2);
				break;
			case 11:
				GPS_GPIO_ModeSetup(73, 3);
				break;
			case 12:
				GPS_GPIO_ModeSetup(77, 2);
				break;
			case 13:
				GPS_GPIO_ModeSetup(78, 2);
				break;
			case 14:
				GPS_GPIO_ModeSetup(38, 2);
				break;
			case 15:
				GPS_GPIO_ModeSetup(39, 2);
				break;
			case 16:
				GPS_GPIO_ModeSetup(46, 2);
				break;
			case 17:
				GPS_GPIO_ModeSetup(47, 2);
				break;
			default:
					//DisplayPopup((kal_uint8*)L"Please assign valid GPS_EINT_NO!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}        
#endif  /* defined(MT6276_S01) */

#elif defined(MT6256)
    switch (eint_channel)
    {
            case 0:
                /* GPIO72 = Mode1(EINT0) */
                GPS_GPIO_ModeSetup(61, 1);
                break;
            case 1:
                /* GPIO73 = Mode1(EINT1) */
                GPS_GPIO_ModeSetup(62, 1);
                break;
            case 2:
                /* GPIO74 = Mode1(EINT2) */
                GPS_GPIO_ModeSetup(63, 1);
                break;
            case 3:
                /* GPIO15 = Mode2(EINT3) */
                GPS_GPIO_ModeSetup(64, 1);
                break;
            case 4:
                /* GPIO16 = Mode2(EINT4) */
                GPS_GPIO_ModeSetup(65, 1);
                break;
            case 5:
                /* GPIO1 = Mode2(EINT5) */
                GPS_GPIO_ModeSetup(72, 2);
                break;
            case 6:
                /* GPIO2 = Mode2(EINT6) */
                GPS_GPIO_ModeSetup(79, 5);
                break;
            case 7:
                /* GPIO76 = Mode2(EINT7) */
                GPS_GPIO_ModeSetup(6, 3);
                break;
            case 8:
                /* GPIO77 = Mode2(EINT8) */
                GPS_GPIO_ModeSetup(7, 3);
                break;
            case 9:
                /* GPIO60 = Mode2(EINT9) */
                GPS_GPIO_ModeSetup(103, 2);
                break;
            case 10:
                /* GPIO59 = Mode2(EINT10) */
                GPS_GPIO_ModeSetup(12, 3);
                break;
            case 11:
                /* GPIO71 = Mode1(EINT7) */
                GPS_GPIO_ModeSetup(78, 2);
                break;
    }

#else

#if defined(__SMART_PHONE_MODEM__)

#else

#error "This is new baseband chip, please notify CS6 to modify GPIO/EINT configurations for GPS!"

#endif /* __SMART_PHONE_MODEM__ */

#endif
    }/*if (eint_channel != EINT_CHANNEL_NOT_EXIST)*/
    else
    {
        eint_channel = 0xFF;
    }
    return eint_channel;
}


#endif /* __GPS_SUPPORT__ */
