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
 * MT6302_interface.C
 *
 * Project:
 * --------
 *   Gemini
 *
 * Description:
 * ------------
 *   this file is custom implementation of MT6302 SPI interface
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include	"drv_comm.h"
#include	"gpio_sw.h"
#include	"MT6302_spi.h"
#include	"MT6302_custom.h"
#include "kal_public_api.h"

#ifndef __CUST_NEW__
kal_uint8 gpio_MT6302_cs_pin=32;
kal_uint8 gpio_MT6302_clk_pin=29;
kal_uint8 gpio_MT6302_dat_pin=31;

//for gemini plus 2rd 6302 spi pins
kal_uint8 gpio_MT6302_cs2_pin=32;
kal_uint8 gpio_MT6302_clk2_pin=29;
kal_uint8 gpio_MT6302_dat2_pin=31;
#else
extern const char gpio_MT6302_cs_pin;
extern const char gpio_MT6302_clk_pin;
extern const char gpio_MT6302_dat_pin;

//for gemini plus 2rd 6302 spi pins
extern const char gpio_MT6302_cs2_pin;
extern const char gpio_MT6302_clk2_pin;
extern const char gpio_MT6302_dat2_pin;
#endif

/*
* FUNCTION
*	MT6302_getLCDSerialInterface
*
* DESCRIPTION
*   	This function is to return which LCD serial interface we use to implement SPI
*	If customer doesn't use LCD interface, this function should return 0xff
*
* CALLS
*
* PARAMETERS
*	none
*
* RETURNS
*	0~maximum number of serial interface BB has: the interface we use
*	0xff: customer doesn't use LCD interface to implement SPI
*
*/
kal_uint32 MT6302_getLCDSerialInterface(kal_uint32 MT6302Interface)
{
/* dual SIMIF dual SIM solution doesn't need this
	if(0 == MT6302Interface){
		return 1;
	}
	else
*/
	{
		ASSERT(0);
		return 0;
	}
}


/*
* FUNCTION
*	MT6302_getSPIInterface
*
* DESCRIPTION
*   	This function is to return which method do we use to implement SPI interface
*
* CALLS
*
* PARAMETERS
*	none
*
* RETURNS
*	0: use LCD serial interface
*	1: use GPIO
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint32 MT6302_getSPIInterface(kal_uint32 MT6302Interface)
{
/* dual SIMIF dual SIM solution doesn't need this
	if(0 == MT6302Interface)
		return MT6302_SPI_USE_LCD;	//MT6302_SPI_USE_LCD
	else if(1 == MT6302Interface)
		return MT6302_SPI_USE_DEDICATED_GPIO;
	else
*/
		ASSERT(0);
	//return MT6302_SPI_USE_LCD;
	//return MT6302_SPI_USE_GPIO;
	//return MT6302_SPI_USE_DEDICATED_GPIO;
		return 0;
}


/*
* FUNCTION
*	MT6302_checkSPIMode
*
* DESCRIPTION
*   	This function is check the SPI 3 pins are in correct mode, no matter use LCD or GPIO to implement
*	customer should add its check code here, or just return kal_true in case they don't want to protect
*
* CALLS
*
* PARAMETERS
*	none
*
* RETURNS
*	kal_true: control pins are all in correct mode
*	kal_false: control pins are not in correct mode
*
*/
kal_bool MT6302_checkSPIMode(kal_uint32 MT6302Interface)
{
/* dual SIMIF dual SIM solution doesn't need this
	if(MT6302Interface == 0)
	{
		if(MT6302_SPI_USE_LCD == MT6302_getSPIInterface(MT6302Interface))
		{
			//16 is SPI clk, 18 is SPI dat, 20 is SPI cs
			//14 is SPI clk, 16 is SPI dat, 18 is SPI cs in MT6238
			if(1 != GPIO_ReturnMode(46) || 1 != GPIO_ReturnMode(39) || 1 != GPIO_ReturnMode(40))
				return KAL_FALSE;
			else
				return KAL_TRUE;
		}
		else if(MT6302_SPI_USE_GPIO == MT6302_getSPIInterface(MT6302Interface) || MT6302_SPI_USE_DEDICATED_GPIO == MT6302_getSPIInterface(MT6302Interface))
		{
				if(0 != GPIO_ReturnMode(MT6302_CS_GPIO_NO) || \
				0 != GPIO_ReturnMode(MT6302_CLK_GPIO_NO) || \
				0 != GPIO_ReturnMode(MT6302_DAT_GPIO_NO) || \
				1 != GPIO_ReturnDir(MT6302_CS_GPIO_NO) || \
				1 != GPIO_ReturnDir(MT6302_CLK_GPIO_NO) || \
				1 != GPIO_ReturnDir(MT6302_DAT_GPIO_NO) || \
				1 != GPIO_ReturnDout(MT6302_CS_GPIO_NO) || \
				0 != GPIO_ReturnDout(MT6302_CLK_GPIO_NO) || \
				0 != GPIO_ReturnDout(MT6302_DAT_GPIO_NO))
					return KAL_FALSE;
				else
					return KAL_TRUE;
		}
	}
	else if(MT6302Interface == 1)
	{
		if(MT6302_SPI_USE_LCD == MT6302_getSPIInterface(MT6302Interface))
		{
			//16 is SPI clk, 18 is SPI dat, 20 is SPI cs
			//14 is SPI clk, 16 is SPI dat, 18 is SPI cs in MT6238
			if(1 != GPIO_ReturnMode(46) || 1 != GPIO_ReturnMode(39) || 1 != GPIO_ReturnMode(40))
				return KAL_FALSE;
			else
				return KAL_TRUE;
		}
		else if(MT6302_SPI_USE_GPIO == MT6302_getSPIInterface(MT6302Interface) || MT6302_SPI_USE_DEDICATED_GPIO == MT6302_getSPIInterface(MT6302Interface))
		{
				//if(0 != GPIO_ReturnMode(MT6302_CS2_GPIO_NO) || \
				//0 != GPIO_ReturnMode(MT6302_CLK2_GPIO_NO) || \
				//0 != GPIO_ReturnMode(MT6302_DAT2_GPIO_NO) || \
				//1 != GPIO_ReturnDir(MT6302_CS2_GPIO_NO) || \
				//1 != GPIO_ReturnDir(MT6302_CLK2_GPIO_NO) || \
				//1 != GPIO_ReturnDir(MT6302_DAT2_GPIO_NO) || \
				//1 != GPIO_ReturnDout(MT6302_CS2_GPIO_NO) || \
				//0 != GPIO_ReturnDout(MT6302_CLK2_GPIO_NO) || \
				//0 != GPIO_ReturnDout(MT6302_DAT2_GPIO_NO))
				//	return KAL_FALSE;
				//else
				//	return KAL_TRUE;
				ASSERT(0);
		}
	}
	else
*/
		ASSERT(0);
		return KAL_FALSE;
}



/*
* FUNCTION
*	MT6302_getGPIOCLK
*
* DESCRIPTION
*   	This function is to return which GPIO we use to implement SPI CLK
*	If customer doesn't GPIO to implement SPI, this function should return 0xff
*	This function is only work when customer used GPIO to implement SPI and CUSTOM_NEW is not defined.
*
* CALLS
*
* PARAMETERS
*	none
*
* RETURNS
*	0~maximum number of GPIO BB has: the GPIO we use
*	0xff: customer doesn't use GPIO to implement SPI CLK
*
*/
kal_uint32 MT6302_getGPIOCLK(kal_uint32 MT6302Interface)
{
/* dual SIMIF dual SIM solution doesn't need this
	//return 0xff;
	if(0 == MT6302Interface)
		return MT6302_CLK_GPIO_NO;
	else if(1 == MT6302Interface){
		//return MT6302_CLK2_GPIO_NO;
		ASSERT(0);
	}
	else
*/
		ASSERT(0);
		return 0;
}

/*
* FUNCTION
*	MT6302_getGPIOCLK
*
* DESCRIPTION
*   	This function is to return which GPIO we use to implement SPI CLK
*	If customer doesn't GPIO to implement SPI, this function should return 0xff
*	This function is only work when customer used GPIO to implement SPI and CUSTOM_NEW is not defined.
*
* CALLS
*
* PARAMETERS
*	none
*
* RETURNS
*	0~maximum number of GPIO BB has: the GPIO we use
*	0xff: customer doesn't use GPIO to implement SPI CLK
*
*/
kal_uint32 MT6302_getGPIOCS(kal_uint32 MT6302Interface)
{
/* dual SIMIF dual SIM solution doesn't need this
	//return 0xff;
	if(0 == MT6302Interface)
		return MT6302_CS_GPIO_NO;
	else if(1 == MT6302Interface){
		//return MT6302_CS2_GPIO_NO;
		ASSERT(0);
	}
	else
*/
		ASSERT(0);
		return 0;
}

/*
* FUNCTION
*	MT6302_getGPIOCLK
*
* DESCRIPTION
*   	This function is to return which GPIO we use to implement SPI CLK
*	If customer doesn't GPIO to implement SPI, this function should return 0xff
*	This function is only work when customer used GPIO to implement SPI and CUSTOM_NEW is not defined.
*
* CALLS
*
* PARAMETERS
*	none
*
* RETURNS
*	0~maximum number of GPIO BB has: the GPIO we use
*	0xff: customer doesn't use GPIO to implement SPI CLK
*
*/
kal_uint32 MT6302_getGPIODAT(kal_uint32 MT6302Interface)
{
/* dual SIMIF dual SIM solution doesn't need this
	//return 0xff;
	if(0 == MT6302Interface)
		return MT6302_DAT_GPIO_NO;
	else if(1 == MT6302Interface){
		//return MT6302_DAT2_GPIO_NO;
		ASSERT(0);
	}
	else
*/
		ASSERT(0);
		return 0;
}
