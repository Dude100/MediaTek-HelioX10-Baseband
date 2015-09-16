/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * Filename:
 * ---------
 *   drv_gpio.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   Low level GPIO driver
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * MT6752 MD1 GPIO driver check in
 *
 * removed!
 * removed!
 * Fix gpio build error
 *
 * removed!
 * removed!
 * fix gpio eint build error.
 *
 * removed!
 * removed!
 * gpio eint fix build error.
 *
 * removed!
 * removed!
 * fix eint/gpio build error.
 *
 * removed!
 * removed!
 * check in MD side GPIO driver for MT6595
 *
 * 05 10 2013 da.wang
 * removed!
 * Upload GPIO driver API for meta mode.
 *
 * 02 04 2013 da.wang
 * removed!
 * .rename GPIO/EINT related keywords MT7208 to MT6290 in MOLY
 ****************************************************************************/
#include "drv_comm.h"
#include "drv_gpio.h"
#include "kal_general_types.h"
#include "devdrv_ls.h"

#if !defined(GPIO_DUMMY_FUN)

//========================================================================
//  Global variable
//========================================================================   

#ifdef __CUST_NEW__
   #if defined(DRV_GPIO_8_MODES) || defined(DRV_GPIO_MODE_4BITS)
   extern const kal_uint32  gpio_mode_allowed[][8];
   #else //defined(DRV_GPIO_8_MODES) || defined(DRV_GPIO_MODE_4BITS)
extern const kal_uint32  gpio_mode_allowed[][4];
   #endif //defined(DRV_GPIO_8_MODES) || defined(DRV_GPIO_MODE_4BITS)
extern const kal_uint32  gpio_dir_out_allowed[];
extern const kal_uint32  gpio_dir_in_allowed[];
extern const kal_uint16  gpo_mode_allowed[];
extern kal_uint32  gpio_check_for_write[];
extern kal_uint32  gpio_check_for_read[];
extern kal_uint16  gpo_check_for_write[];
extern kal_bool   gpio_debug_enable;
#endif /* __CUST_NEW__ */

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

//========================================================================
/**
 *  @brief     get direction register value of pin
 *  @param  gpio_pin :  The GPIO pin to be read.
 *  @return   return the direction register value of gpio_pin
 *		      0:                 the direction of gpio is input
 *            1:                 the direction of gpio is output
 *            GPIO_FAIL:   gpio_pin is out of range
 */
kal_int32 gpio_get_dir_value (gpio_pin_e gpio_pin)
{
#if defined(MT6290)
	kal_uint32 dir_val;

	if (gpio_pin>GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}	
	if(gpio_pin > 31)
	{
		dir_val= BU_G_BIT(*GPIO_DIR2, (gpio_pin-32));
	}
	else
	{
		dir_val = BU_G_BIT(*GPIO_DIR1, gpio_pin);
	}
	return dir_val;		
#elif defined(MT6595)
	unsigned long pos;
	unsigned long bit;
	unsigned long data;

	if (gpio_pin>GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}	

	pos = gpio_pin/16;
	bit = gpio_pin%16;

	data = DRV_Reg32((GPIO_DIR1 + pos*0x10));

	return ((data&(1<<bit))?1:0);	
#elif defined(MT6752)
	unsigned long pos;
	unsigned long bit;
	unsigned long data;

	if (gpio_pin>GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}	

	pos = gpio_pin/32;
	bit = gpio_pin%32;

	data = DRV_Reg32((GPIO_DIR1 + pos*0x10));

	return ((data&(1<<bit))?1:0);	

#endif
}

// ----------------------------------------------------------
/**
 *  @brief	Set GPIO_DIR input or output
 *  @param  gpio_pin :  The GPIO pin to be set.
 *  @param  direction : The direction to be set in gpio_pin.
 *  					1: set as output pin
 *					0: set as input pin
 *  @return  GPIO_OK : set successful,  GPIO_FAIL : set failed
 */
static kal_int32 _GPIO_Set_Direction(gpio_pin_e gpio_pin, kal_uint32 direction)
{
#if defined(MT6290)
	if (gpio_pin>GPIO_PIN_MAX){
		GPIO_ERR("\tThe gpio pin is out of range of MAX num (32) !!!! ");
		return GPIO_FAIL;
	}
	
	if (direction == GPIO_AS_OUTPUT){
		if(gpio_pin < 32){
			DRV_WriteReg32(GPIO_DIR1_SET,(1<<gpio_pin));
		}
		else{
			DRV_WriteReg32(GPIO_DIR2_SET,(1<<(gpio_pin-32)));
		}
	} 
	else if (direction == GPIO_AS_INPUT){
		if(gpio_pin < 32){
			DRV_WriteReg32(GPIO_DIR1_CLR,(1<<gpio_pin));
		}
		else{
			DRV_WriteReg32(GPIO_DIR2_CLR,(1<<(gpio_pin-32)));
		}
	} 
	else{
		GPIO_ERR("\tThe direction should be 0 or 1 !!!!");
		return GPIO_FAIL;
	}
	return GPIO_OK;	
#elif defined(MT6595)
	unsigned long pos;
	unsigned long bit;
	//unsigned long data;

	if (gpio_pin>GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}	

	pos = gpio_pin/16;
	bit = gpio_pin%16;
	if (direction == GPIO_AS_OUTPUT)
		DRV_WriteReg32(GPIO_DIR_SET(pos),1<<bit);
	else
		DRV_WriteReg32(GPIO_DIR_CLR(pos),1<<bit);

	return GPIO_OK;	
#elif defined(MT6752)
	unsigned long pos;
	unsigned long bit;
	//unsigned long data;

	if (gpio_pin>GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}	

	pos = gpio_pin/32;
	bit = gpio_pin%32;
	if (direction == GPIO_AS_OUTPUT)
		DRV_WriteReg32(GPIO_DIR_SET(pos),1<<bit);
	else
		DRV_WriteReg32(GPIO_DIR_CLR(pos),1<<bit);

	return GPIO_OK; 

#endif
}



//========================================================================
/*-----------------------------------------------------------------------*
*  @brief  Read the input value of the gpio pin.
*  @param  gpio_pin :   The pin which to read value.
*  @param  *value	   :	The variable to save value read from the pin, will be 0 or 1.
*  @return GPIO_OK :   get successful,  GPIO_FAIL : get failed
*-----------------------------------------------------------------------*/
kal_int32 GPIO_READ_INPUT_VALUE (gpio_pin_e gpio_pin, kal_uint32 *value)
{
#if defined(MT6290)
	if(gpio_pin >= GPIO_PIN_MAX)
	{
		GPIO_ERR("\tThe gpio_pin[%d] is out of range ",gpio_pin);
		return GPIO_FAIL;
	}
	if(gpio_pin > 31){
			*value = BU_G_BIT(*GPIO_DIN2, (gpio_pin-32));
	}
	else{
			*value = BU_G_BIT(*GPIO_DIN1, gpio_pin);
	}
	return GPIO_OK;		
#elif defined(MT6595)
	unsigned long pos;
	unsigned long bit;
	unsigned long data;

	if (gpio_pin>GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}	

	pos = gpio_pin/16;
	bit = gpio_pin%16;
	data = DRV_Reg32((GPIO_DIN1 + pos*0x10));
	*value=((data&(1<<bit))?1:0);

	return GPIO_OK;	
#elif defined(MT6752)
	unsigned long pos;
	unsigned long bit;
	unsigned long data;

	if (gpio_pin>GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}	

	pos = gpio_pin/32;
	bit = gpio_pin%32;
	data = DRV_Reg32((GPIO_DIN1 + pos*0x10));
	*value=((data&(1<<bit))?1:0);

	return GPIO_OK; 

#endif
}




// ----------------------------------------------------------
/**
 *  @brief	Enable or Disable GPIO_PULLEN specific pin
 *  @param  gpio_pin :  The GPIO pin to be set.
 *  @param  pullen : set 1 to enable pull up/down in gpio_pin.
 *  @return  GPIO_OK : set successful,  GPIO_FAIL : set failed
 */
kal_int32 _GPIO_Set_Pullen(gpio_pin_e gpio_pin, kal_uint32 pullen)  
{
#if defined(MT6290)
	if (gpio_pin>GPIO_PIN_MAX){
		GPIO_ERR("\tThe gpio pin is out of range of MAX num (32) !!!! ");
		return GPIO_FAIL;
	}
		
	if (pullen == GPIO_ENABLE){
		if(gpio_pin < 32){
			DRV_WriteReg32(GPIO_PULLEN1_SET,(1<<gpio_pin));  
		}
		else{
			DRV_WriteReg32(GPIO_PULLEN2_SET,(1<<(gpio_pin-32)));  
		}
	}
	else if (pullen == GPIO_DISABLE){
		if(gpio_pin < 32){
			DRV_WriteReg32(GPIO_PULLEN1_CLR,(1<<gpio_pin));  
		}
		else{
			DRV_WriteReg32(GPIO_PULLEN2_CLR,(1<<(gpio_pin-32)));  
		}
	}
	else {
		GPIO_ERR("\tThe pullen value should be 0 or 1 !!!!");
		return GPIO_FAIL;
	}
	
	return GPIO_OK;	
#elif defined(MT6595)
	return GPIO_OK;	
#else
	return GPIO_OK;
#endif
}

// ----------------------------------------------------------
/**
 *  @brief	Set GPIO_PULLSEL to pull-up or pull-down
 *  @param  gpio_pin :  The GPIO pin to be set.
 *  @param  updown : set GPIO_PULL_UP to set gpio_pin in pull-up. set GPIO_PULL_DOWN to set gpio_pin pull_down.
 *  @return  GPIO_OK : set successful,  GPIO_FAIL : set failed
 */
kal_int32 _GPIO_Set_Pullsel(gpio_pin_e gpio_pin, kal_uint32 updown)
{
#if defined(MT6290)
	if (gpio_pin>GPIO_PIN_MAX){
		GPIO_ERR("\tThe gpio pin is out of range of MAX num (32) !!!! ");
		return GPIO_FAIL;
	}

	if (updown == GPIO_PULL_UP){
		if(gpio_pin < 32){
			DRV_WriteReg32(GPIO_PULLSEL1_SET,(1<<gpio_pin));  
		}
		else{
			DRV_WriteReg32(GPIO_PULLSEL2_SET,(1<<(gpio_pin-32)));  
		}
	}
	else if (updown == GPIO_PULL_DOWN){
		if(gpio_pin < 32){
			DRV_WriteReg32(GPIO_PULLSEL1_CLR,(1<<gpio_pin));  
		}
		else{
			DRV_WriteReg32(GPIO_PULLSEL2_CLR,(1<<(gpio_pin-32)));  
		}
	}
	else{
		GPIO_ERR("\tThe pull updown value should be 0 or 1 !!!!");
		return GPIO_FAIL;
	}
	return GPIO_OK;	
#elif defined(MT6595)
	return GPIO_OK;
#else
	return GPIO_OK;
#endif
}


/**
*  @brief  Set pin direction as an output pin.
*  @param  gpio_pin : The pin which to be set direction to output pin.
*  @return GPIO_OK : set successful,  GPIO_FAIL : set failed
*/
kal_int32 GPIO_SET_DIRECT_OUTPUT (gpio_pin_e gpio_pin)
{
	if (gpio_pin>GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}
	
	if (GPIO_FAIL == _GPIO_Set_Pullen(gpio_pin, GPIO_DISABLE) )
	{	return GPIO_FAIL; }
		
	if (GPIO_FAIL == _GPIO_Set_Direction(gpio_pin, GPIO_AS_OUTPUT) )
	{	return GPIO_FAIL; }

	return GPIO_OK;
}

//========================================================================
/**
*  @brief  Set pin direction as an input pin.
*  @param  gpio_pin	   :	The pin which want to be set.
*  @param  pull_en	   :   GPIO_ENABLE or GPIO_DISABLE, Set if pull-up/down function is enable. 
*  @param  pull_updown  :   GPIO_PULL_UP / GPIO_PULL_DOWN, it works only when pull_en is enable.
*  @return GPIO_OK : set successful,  GPIO_FAIL : set failed
*/
kal_int32 GPIO_SET_DIRECT_INPUT (gpio_pin_e gpio_pin, kal_uint32 pull_en, kal_uint32 pull_updown)
{
	if (gpio_pin>GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}	
				/* Step-1 Check GPIO_Mode to make sure the pin can be uesed as GPIO*/
				//_GPIO_ShareMode_Chk(gpio_pin);

				/* Step-2 set the pull-up/down */
				// When input, the pullen could be set as required
				// If the pullen is set, the pullsel should be set.
	if (GPIO_FAIL == _GPIO_Set_Pullen(gpio_pin, pull_en) )
	{	return GPIO_FAIL; }

				/* Step-3 set the pull-up/down when gpio is input*/
	if (GPIO_FAIL == _GPIO_Set_Pullsel(gpio_pin, pull_updown) )
	{	return GPIO_FAIL; }

				/* Step-4 set the direction to input*/
	if (GPIO_FAIL == _GPIO_Set_Direction(gpio_pin, GPIO_AS_INPUT) )
	{	return GPIO_FAIL; }		
	
	
		return GPIO_OK;
}
	

//========================================================================
/**
*  @brief  set the data inversion parameter of the gpio pin.
*  @param  gpio_pin :	The pin which is to be set data inversion.
*  @param  inversion:	The value to be set, will be 0 or 1.
*					0: disable data inversion
					1: enable data inversion
*  @return GPIO_OK :   set successful,  GPIO_FAIL : set failed
*/
kal_int32 gpio_set_data_inversion(gpio_pin_e gpio_pin, kal_uint32 inversion)
{
#if defined(MT6290)
	if (gpio_pin>GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}	
	if (inversion == GPIO_ENABLE)
	{
		if(gpio_pin < 32)
		{
			DRV_WriteReg32(GPIO_DINV1_SET,(1<<gpio_pin));
		}
		else
		{
			DRV_WriteReg32(GPIO_DINV2_SET,(1<<(gpio_pin-32)));
		}
	}
	else if (inversion == GPIO_DISABLE)
	{
		if(gpio_pin < 32)
		{
			DRV_WriteReg32(GPIO_DINV1_CLR,(1<<gpio_pin));
		}
		else
		{
			DRV_WriteReg32(GPIO_DINV2_CLR,(1<<(gpio_pin-32)));
		}
	}
	return GPIO_OK;
#elif defined(MT6595)
	return GPIO_FAIL;
#else
	return GPIO_FAIL;
#endif
}



//========================================================================
/**
*  @brief  Write the output value of the gpio pin. It only work when the pin is an output pin.
*  @param  gpio_pin :	The pin which to be set output value.
*  @param  value	   :	The value which want to be set, can be 0 or 1.
*  @return GPIO_OK :   set successful,  GPIO_FAIL : set failed
*/
kal_int32 GPIO_WRITE_OUTPUT_VALUE (gpio_pin_e gpio_pin, kal_uint32 value)
{
#if defined(MT6290)
	if (value==GPIO_OUTPUT_HIGH){
		if(gpio_pin < 32){
					DRV_WriteReg32(GPIO_DOUT1_SET,(1<<gpio_pin));
		}
		else{
					DRV_WriteReg32(GPIO_DOUT2_SET,(1<<(gpio_pin-32)));
		}
	}
	else if (value==GPIO_OUTPUT_LOW){
		if(gpio_pin < 32){
					DRV_WriteReg32(GPIO_DOUT1_CLR,(1<<gpio_pin));
		}
		else{
					DRV_WriteReg32(GPIO_DOUT2_CLR,(1<<(gpio_pin-32)));
		}
	}
	else{
		GPIO_ERR("\tThe output value should be 0 or 1 !!!!");
		return GPIO_FAIL;
	}
	
	return GPIO_OK;
#elif defined(MT6595)
	unsigned long pos;
	unsigned long bit;
	//unsigned long data;

	if (gpio_pin>GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}	

	pos = gpio_pin/16;
	bit = gpio_pin%16;
	if (value == GPIO_OUTPUT_HIGH)
		DRV_WriteReg32(GPIO_DOUT_SET(pos),1<<bit);
	else
		DRV_WriteReg32(GPIO_DOUT_CLR(pos),1<<bit);

	return GPIO_OK;	
#elif defined(MT6752)
	unsigned long pos;
	unsigned long bit;
	//unsigned long data;

	if (gpio_pin>GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}	

	pos = gpio_pin/32;
	bit = gpio_pin%32;
	if (value == GPIO_OUTPUT_HIGH)
		DRV_WriteReg32(GPIO_DOUT_SET(pos),1<<bit);
	else
		DRV_WriteReg32(GPIO_DOUT_CLR(pos),1<<bit);

	return GPIO_OK;	
#endif
}


/*-----------------------------------------------------------------------*
* FUNCTION                                                            
*	GPIO_ReadIO
*
* DESCRIPTION                                                           
*   	This function is to read data from one GPIO pin
*
* CALLS  
*	Read data from one GPIO pin
*
* PARAMETERS
*	port: pin number
*	
* RETURNS
*	1 or 0
*
* GLOBALS AFFECTED
*   external_global
*-----------------------------------------------------------------------*/
char GPIO_ReadIO(char port)
{
#if defined(MT6290)
	kal_uint32 input_val,gpio_pin,dir;

	#ifdef __CUST_NEW__  
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_read[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         char dir;
         mode = GPIO_ReturnMode(port);
         dir = GPIO_ReturnDir(port);
         if ((mode != 0) || (dir != 0))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: mode or direction is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d, direction=%d", port, mode, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_read[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __CUST_NEW__ */


	#ifdef __CUST_NEW__  
	port &= (~GPIO_MAGIC_NUM);
	#endif
	gpio_pin = port;
    dir = gpio_get_dir_value((gpio_pin_e)gpio_pin);
	if(dir != GPIO_INPUT)
	{
		GPIO_ERR("\tGPIO_ReadIO: the direction of port[%d] is not input!! ",gpio_pin);
	}
	if(GPIO_READ_INPUT_VALUE((gpio_pin_e)gpio_pin, &input_val) != GPIO_OK)
	{
		GPIO_ERR("\tGPIO_ReadIO: read the value of port[%d] failed!! ",gpio_pin);
	}
	return (char)input_val;
#elif defined(MT6595)
	kal_uint32 input_val;
	if(GPIO_READ_INPUT_VALUE((gpio_pin_e)port, &input_val) != GPIO_OK)
	{
		GPIO_ERR("\tGPIO_ReadIO: read the value of port[%d] failed!! ",port);
	}
	return (char)input_val;
#elif defined(MT6752)
	kal_uint32 input_val;
	if(GPIO_READ_INPUT_VALUE((gpio_pin_e)port, &input_val) != GPIO_OK)
	{
		GPIO_ERR("\tGPIO_ReadIO: read the value of port[%d] failed!! ",port);
	}
	return (char)input_val;
#endif
}


/*
* FUNCTION                                                            
*	GPIO_WriteIO
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPIO port
*
* CALLS  
*	Write data to one GPIO port
*
* PARAMETERS
*	data: KAL_TRUE(1) or KAL_FALSE(0)
*	port: gpio pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global        
*/
void GPIO_WriteIO(char data, char port)
{
#if defined(MT6290)
	#ifdef __CUST_NEW__  
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_write[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         char dir;
         mode = GPIO_ReturnMode(port);
         dir = GPIO_ReturnDir(port);
         if ((mode != 0) || (dir != 1))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO: mode or direction is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d, direction=%d", port, mode, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_write[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __CUST_NEW__ */


	#ifdef __CUST_NEW__  
	port &= (~GPIO_MAGIC_NUM);
	#endif
	GPIO_WRITE_OUTPUT_VALUE((gpio_pin_e)port,data);
#elif defined(MT6595)
	GPIO_WRITE_OUTPUT_VALUE((gpio_pin_e)port,data);
#elif defined(MT6752)
	GPIO_WRITE_OUTPUT_VALUE((gpio_pin_e)port,data);
#endif
}
#if defined(MT6595)
#define MAX_GPIO_MODE_PER_REG 5
#define GPIO_MODE_BITS  3
#elif defined(MT6752)
#define MAX_GPIO_MODE_PER_REG 8
#define GPIO_MODE_BITS  4
#endif
void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_data)
{
#if defined(MT6595)
	//unsigned long i=0;
	unsigned long pos;
	unsigned long bit;
	unsigned long data;
	unsigned long mask = (1L << GPIO_MODE_BITS)-1;

	pos = pin/MAX_GPIO_MODE_PER_REG;
	bit = pin%MAX_GPIO_MODE_PER_REG;
	data = DRV_Reg32(GPIO_MODE(pos));
	data &= ~(mask << (GPIO_MODE_BITS*bit));
	data |= (conf_data << (GPIO_MODE_BITS*bit));
	//to avoid possible race condition with AP,use SET/CLR reg to setup MODE register
	DRV_WriteReg32(GPIO_MODE_CLR(pos),(mask << (GPIO_MODE_BITS*bit)));
	DRV_WriteReg32(GPIO_MODE_SET(pos),data);
#elif defined(MT6752)
	//unsigned long i=0;
	unsigned long pos;
	unsigned long bit;
	unsigned long data;
	unsigned long mask = (1L << GPIO_MODE_BITS)-1;

	pos = pin/MAX_GPIO_MODE_PER_REG;
	bit = pin%MAX_GPIO_MODE_PER_REG;
	data = DRV_Reg32(GPIO_MODE(pos));
	data &= ~(mask << (GPIO_MODE_BITS*bit));
	data |= (conf_data << (GPIO_MODE_BITS*bit));
	//to avoid possible race condition with AP,use SET/CLR reg to setup MODE register
	DRV_WriteReg32(GPIO_MODE_CLR(pos),(mask << (GPIO_MODE_BITS*bit)));
	DRV_WriteReg32(GPIO_MODE_SET(pos),data);
#endif	
}

/*
* FUNCTION                                                            
*	GPIO_InitIO
*
* DESCRIPTION                                                           
*   	This function is to initialize one GPIO pin as INPUT or OUTPUT
*
* CALLS  
*	Initialize one GPIO pin as INPUT or OUTPUT
*
* PARAMETERS
*	direction: INPUT or OUTPUT
*	port: pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_InitIO(char direction, char port)
{
#if defined(MT6290)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_InitIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   if (gpio_debug_enable == KAL_TRUE)
   {
      if (direction == 0)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_dir_in_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_InitIO: Direction Input is not allowed!");
             ret = sprintf(buff, "pin=%d", port);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpio_dir_in_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_dir_out_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_InitIO: Direction Output is not allowed!");
             ret = sprintf(buff, "pin=%d", port);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpio_dir_out_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
	  gpio_check_for_write[(kal_uint8)port>>5] |= (1 << (port & 0x1f));
	  gpio_check_for_read[(kal_uint8)port>>5] |= (1 << (port & 0x1f));
   }
   #endif /* __CUST_NEW__ */

	
	#ifdef __CUST_NEW__  
	port &= (~GPIO_MAGIC_NUM);
	#endif

	if(GPIO_OUTPUT == direction)
	{
		GPIO_SET_DIRECT_OUTPUT((gpio_pin_e)port);
	}
	else
	{
		_GPIO_Set_Direction((gpio_pin_e)port,GPIO_INPUT);
	}
#elif defined(MT6595)
	if(GPIO_OUTPUT == direction)
	{
		_GPIO_Set_Direction((gpio_pin_e)port,GPIO_OUTPUT);
	}
	else
	{
		_GPIO_Set_Direction((gpio_pin_e)port,GPIO_INPUT);
	}
#elif defined(MT6752)
if(GPIO_OUTPUT == direction)
{
	_GPIO_Set_Direction((gpio_pin_e)port,GPIO_OUTPUT);
}
else
{
	_GPIO_Set_Direction((gpio_pin_e)port,GPIO_INPUT);
}

#endif
}

char GPIO_ReturnMode(char port)
{
	return 0;
}

/*
* FUNCTION                                                            
*	GPIO_ReturnDir
*
* DESCRIPTION                                                           
*   	This function is to report GPIO direction value
*
* CALLS  
*	Report GPIO direction value accoding to input pin
*
* PARAMETERS
*	GPIO pin 
*	
* RETURNS
*	GPIO direction value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReturnDir(char port)
{
#if defined(MT6290)
	char dir_value;
	
	#ifdef __CUST_NEW__  
	port &= (~GPIO_MAGIC_NUM);
	#endif
	if (port > GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}

	if(port > 31)
	{
		dir_value = BU_G_BIT(REG32(GPIO_DIR2),(port - 32));
	}
	else
	{
		dir_value = BU_G_BIT(REG32(GPIO_DIR1),port);
	}

	return dir_value;
#elif defined(MT6595)
	return gpio_get_dir_value(port);
#elif defined(MT6752)
	return gpio_get_dir_value(port);
#endif
}

/*
* FUNCTION                                                            
*	GPIO_ReturnDout
*
* DESCRIPTION                                                           
*   	This function is to report GPIO output value
*
* CALLS  
*	Report GPIO output value accoding to input pin
*
* PARAMETERS
*	GPIO pin 
*	
* RETURNS
*	GPIO output value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReturnDout(char port)
{
#if defined(MT6290)
	char dout_value;
	
	#ifdef __CUST_NEW__  
	port &= (~GPIO_MAGIC_NUM);
	#endif
	if (port > GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}

	if(port > 31)
	{
		dout_value = BU_G_BIT(REG32(GPIO_DOUT2),(port - 32));
	}
	else
	{
		dout_value = BU_G_BIT(REG32(GPIO_DOUT1),port);
	}

	return dout_value;
#elif defined(MT6595)
	return GPIO_FAIL;
#elif defined(MT6752)
	return GPIO_FAIL;
#endif
}


/*
* FUNCTION                                                            
*	GPIO_PullenSetup
*
* DESCRIPTION                                                           
*   	This function is to enable or disable the pull up/down of the related GPIO pin.
*		You can not decide to pull up or down, it is set inside the chip.
*		And, the setting is different from pin by pin.
*
* PARAMETERS
*	pin : gpio pin number range from 0~63
*	enable: enable the pull up/down
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*/
void GPIO_PullenSetup(kal_uint16 pin, kal_bool enable)
{
	#ifdef __CUST_NEW__  
	pin &= (~GPIO_MAGIC_NUM);
	#endif
	_GPIO_Set_Pullen(pin,enable);
}

/*
* FUNCTION                                                            
*	GPIO_PullSelSetup
*
* DESCRIPTION                                                           
*   	This function is to select pull up/down of the related GPIO pin.
*
* PARAMETERS
*	pin : gpio pin number range from 0~63
*	enable: enable the pull up/down
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*/
void GPIO_PullSelSetup(kal_uint16 pin, kal_bool pull_up)
{
	#ifdef __CUST_NEW__  
	pin &= (~GPIO_MAGIC_NUM);
	#endif
	_GPIO_Set_Pullsel(pin,pull_up);
}

/*
* FUNCTION                                                            
*	GPIO_DinvSetup
*
* DESCRIPTION                                                           
*   	This function is to enable data invert of the related GPIO pin
*
* PARAMETERS
*	pin : gpio pin number range from 0~63
*	enable: enable the data inversion
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*/
void GPIO_DinvSetup(kal_uint16 pin, kal_bool enable)
{
	#ifdef __CUST_NEW__  
	pin &= (~GPIO_MAGIC_NUM);
	#endif
	gpio_set_data_inversion(pin,enable);
}

/*
* FUNCTION                                                            
*	GPIO_SetDebugMode
*
* DESCRIPTION                                                           
*  This function is to set GPIO HW debug mode
*  currently MT6290 not support this function
*
* CALLS  
*	set GPIO HW debug mode
*
* PARAMETERS
*	enable   - KAL_TRUE: turn on the debug mode
*             KAL_FALSE: turn off the debug mode
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_SetDebugMode(kal_bool enable)
{
	//not support in MT6290
}

#ifdef __CUST_NEW__

/*
* FUNCTION                                                            
*	GPIO_InitIO_FAST
*
* DESCRIPTION                                                           
*   	This function is to initialize one GPIO pin as INPUT or OUTPUT. 
*  Note that it's for fast access without debug checking and only exists
*  when __CUST_NEW__ is defined.
*
* CALLS  
*	Initialize one GPIO pin as INPUT or OUTPUT
*
* PARAMETERS
*	direction: INPUT or OUTPUT
*	port: pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_InitIO_FAST(char direction, char port)
{
	 #ifdef __GPIO_FAST_DEBUB__
   if (gpio_debug_enable == KAL_TRUE)
   {
      if (direction == 0)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_dir_in_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_InitIO_FAST: Direction Input is not allowed!");
             ret = sprintf(buff, "pin=%d", port);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpio_dir_in_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_dir_out_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_InitIO_FAST: Direction Output is not allowed!");
             ret = sprintf(buff, "pin=%d", port);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpio_dir_out_allowed[(kal_uint8)port>>5]) & (1 << (port & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
	  gpio_check_for_write[(kal_uint8)port>>5] |= (1 << (port & 0x1f));
	  gpio_check_for_read[(kal_uint8)port>>5] |= (1 << (port & 0x1f));
   }
   #endif /* __GPIO_FAST_DEBUB__ */

   #ifdef __CUST_NEW__   	
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
	if(GPIO_OUTPUT == direction)
	{
		GPIO_SET_DIRECT_OUTPUT((gpio_pin_e)port);
	}
	else
	{
		_GPIO_Set_Direction((gpio_pin_e)port,GPIO_INPUT);
	}
}

/*
* FUNCTION                                                            
*	GPIO_WriteIO_FAST
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPIO port
*  Note that it's for fast access without debug checking and only exists
*  when __CUST_NEW__ is defined.
*
* CALLS  
*	Write data to one GPIO port
*
* PARAMETERS
*	data: KAL_TRUE(1) or KAL_FALSE(0)
*	port: gpio pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global        
*/
void GPIO_WriteIO_FAST(char data, char port)
{
   #ifdef __GPIO_FAST_DEBUB__
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_write[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {

      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         char dir;
         dir = GPIO_ReturnDir(port);
         if (dir != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: direction is not correct.");
          ret = sprintf(buff, "pin=%d, direction=%d", port, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnDir(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_write[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __GPIO_FAST_DEBUB__ */

   	#ifdef __CUST_NEW__  
	port &= (~GPIO_MAGIC_NUM);
	#endif
	GPIO_WRITE_OUTPUT_VALUE((gpio_pin_e)port,data);

}

/*
* FUNCTION                                                            
*	GPIO_ReadIO_FAST
*
* DESCRIPTION                                                           
*   	This function is to read data from one GPIO pin.
*  Note that it's for fast access without debug checking and only exists
*  when __CUST_NEW__ is defined.
*
* CALLS  
*	Read data from one GPIO pin
*
* PARAMETERS
*	port: pin number
*	
* RETURNS
*	1 or 0
*
* GLOBALS AFFECTED
*   external_global
*/
char GPIO_ReadIO_FAST(char port)
{
	kal_uint32 input_val;

   #ifdef __GPIO_FAST_DEBUB__
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_read[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         char dir;
         mode = GPIO_ReturnMode(port);
         dir = GPIO_ReturnDir(port);
         if ((mode != 0) || (dir != 0))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO_FAST: mode or direction is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d, direction=%d", port, mode, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnMode(port) == 0);
      ASSERT(GPIO_ReturnDir(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_read[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __GPIO_FAST_DEBUB__ */

   #ifdef __CUST_NEW__   	
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   
	if(GPIO_READ_INPUT_VALUE((gpio_pin_e)port, &input_val) != GPIO_OK)
	{
		GPIO_ERR("\tGPIO_ReadIO: read the value of port[%d] failed!! ",port);
	}
	return (char)input_val;
}


#endif

//#pragma arm section code = "INTERNCODE"
/*
* FUNCTION                                                            
*	GPIO_WriteIO_FAST2
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPIO port
*  Note that it's for faster access without debug checking.
*
* CALLS  
*	Write data to one GPIO port
*
* PARAMETERS
*	data: KAL_TRUE(1) or KAL_FALSE(0)
*	no: no = port/16; port: GPIO port number
*	remainder_shift: remainder_shift = 1<<(port%16);
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global        
*/
void DEVDRV_LS_INTERNCODE GPIO_WriteIO_FAST2(char data, kal_uint16 no, kal_uint16 remainder_shift)
{
	kal_uint32 gpio_pin,shift_bit;

   #if defined(__CUST_NEW__)&&defined(__GPIO_FAST_DEBUB__)
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_write[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
      char port;
      kal_uint16 index;

      for (index = 0; index < 16; index++)
      {
         if (remainder_shift & (1 << index))
            break;
      }
      port = (char)((no<<4)+(index&0x000f));

      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }

      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         char dir;
         dir = GPIO_ReturnDir(port);
         if (dir != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: direction is not correct.");
          ret = sprintf(buff, "pin=%d, direction=%d", port, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnDir(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_write[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __GPIO_FAST_DEBUB__ */
   
  for (shift_bit = 0; shift_bit < 16; shift_bit++)
  {
     if (remainder_shift & (1 << shift_bit))
        break;
  }
  gpio_pin = (char)((no<<4)+(shift_bit&0x000f));
  
  GPIO_WRITE_OUTPUT_VALUE((gpio_pin_e)gpio_pin,data);

}

//#pragma arm section code


/*conf_data = 0~3*/
void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
{
	//not support in MT6290
}


/*
* FUNCTION                                                            
*	GPI_O_WriteIO
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPO pin
*
* CALLS  
*	Write data to one GPO pin
*
* PARAMETERS
*	data: KAL_TRUE(1) or KAL_FALSE(0)
*	port: gpo pin number
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/

void GPO_WriteIO(char data,char port)
{
	//not support in MT6290
}

/*
* FUNCTION                                                            
*	GPO_ReturnDout
*
* DESCRIPTION                                                           
*   	This function is to report GPO output value
*
* CALLS  
*	Report GPO output value accoding to input pin
*
* PARAMETERS
*	GPO pin 
*	
* RETURNS
*	GPO output value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPO_ReturnDout(char port)
{
	return 0;
}


/*
* FUNCTION                                                            
*	GPO_ReturnMode
*
* DESCRIPTION                                                           
*   	This function is to report GPO mode value
*
* CALLS  
*	Report GPO mode value accoding to input pin
*
* PARAMETERS
*	GPO pin 
*	
* RETURNS
*	GPO mode value
*
* GLOBALS AFFECTED
*   external_global
*/
char GPO_ReturnMode(char port)
{
	return 0;
}


/**
*  @brief  set gpio ownership register
*  @param  pin_num  : the gpio pin to set ownerhsip
*  @param  ownership : the ownership register bit value to set ,it should be 0~1
*                                    0: set ownership to MD
*                                    1: set ownership to AP
*  @return GPIO_OK :	set successful,  GPIO_FAIL : set failed
*/
kal_int32 gpio_set_ownership(kal_uint32 pin_num,kal_uint32 ownership)
{
#if defined(MT6290)
	kal_uint32 reg_val;

	if((pin_num >= 64)||(ownership > GPIO_OWNERSHIP_AP))
	{
		GPIO_PRINT("\tgpio_set_ownership failed! pin_num[%d] or ownership[%d] is over range",pin_num,ownership);
		return GPIO_FAIL;
	}
	
	if(ownership == GPIO_OWNERSHIP_AP)
	{
		if(pin_num < 32)
		{
			reg_val = REG32(GPIOMUX_GPIO_OWN1);
			reg_val = reg_val|(1<<pin_num);
			REG32_WRITE(GPIOMUX_GPIO_OWN1,reg_val);
		}
		else
		{
			reg_val = REG32(GPIOMUX_GPIO_OWN2);
			reg_val = reg_val|(1<<(pin_num-32));
			REG32_WRITE(GPIOMUX_GPIO_OWN2,reg_val);
		}
	}
	else
	{
		if(pin_num < 32)
		{
			reg_val = REG32(GPIOMUX_GPIO_OWN1);
			reg_val = reg_val&(~(1<<pin_num));
			REG32_WRITE(GPIOMUX_GPIO_OWN1,reg_val);
		}
		else
		{
			reg_val = REG32(GPIOMUX_GPIO_OWN2);
			reg_val = reg_val&(~(1<<(pin_num-32)));
			REG32_WRITE(GPIOMUX_GPIO_OWN2,reg_val);
		}
	}

	return GPIO_OK;
#elif defined(MT6595)
	return GPIO_FAIL;
#elif defined(MT6752)
	return GPIO_FAIL;
#endif
}


/**
*  @brief  set the drive parameter of the gpio pin.
*  @param  gpio_pin :	The pin which is to set drive.
*  @param  drive:         the value of drive parameter to set, it should be 0~3
*  @return GPIO_OK :   set successful,  GPIO_FAIL : set failed
*/
kal_int32 gpio_set_drive(gpio_pin_e gpio_pin,kal_uint32 drive)
{
#if defined(MT6290)
	volatile unsigned int* gpio_drive_reg;
	kal_uint32 drive_val;
	if (gpio_pin>GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}
	
	gpio_drive_reg = (volatile unsigned int*)((unsigned int)GPIO_DRIVE1 + 16*(gpio_pin/GPIO_DRIVE_NUM_PER_REG));
	drive_val = REG32(gpio_drive_reg);
	REG32_WRITE(gpio_drive_reg,(drive_val&(~(0x3<<((gpio_pin%GPIO_DRIVE_NUM_PER_REG)*GPIO_DRIVE_BIT_NUM)))));
	drive_val = REG32(gpio_drive_reg);
	REG32_WRITE(gpio_drive_reg,(drive_val|((drive<<((gpio_pin%GPIO_DRIVE_NUM_PER_REG)*GPIO_DRIVE_BIT_NUM)))));
	
	return GPIO_OK;
#elif defined(MT6595)
	return GPIO_FAIL;
#elif defined(MT6752)
	return GPIO_FAIL;
#endif
}


//========================================================================
/**
 *  @brief     get drive register value of pin
 *  @param  gpio_pin :  The GPIO pin to be read.
 *  @return   return the drive register value of pin, it should be 0x0~0x3.
 *		      if gpio_pin is out of range, the return value will be GPIO_FAIL
 */
kal_int32 gpio_get_drive_value(gpio_pin_e gpio_pin)
{
#if defined(MT6290)
	kal_uint32 drive_val;

	if (gpio_pin>GPIO_PIN_MAX)
	{
		GPIO_ERR("The gpio pin is out of range of MAX num (%d) !!!!", GPIO_PIN_MAX);
		return GPIO_FAIL;
	}
	if(gpio_pin > 47)
	{
		drive_val= BU_G_FLD((*GPIO_DRIVE4), ((gpio_pin-48)*2+1),(gpio_pin-48)*2);
	}
	else if((gpio_pin < 48)&&(gpio_pin > 31))
	{
		drive_val = BU_G_FLD((*GPIO_DRIVE3), ((gpio_pin-32)*2+1),(gpio_pin-32)*2);
	}
	else if((gpio_pin < 32)&&(gpio_pin > 15))
	{
		drive_val = BU_G_FLD((*GPIO_SEL_DRIVE2), ((gpio_pin-16)*2+1),(gpio_pin-16)*2);
	}
	else
	{
		drive_val = BU_G_FLD((*GPIO_DRIVE1),(gpio_pin*2+1),gpio_pin*2);
	}
	return drive_val;	
#elif defined(MT6595)
	return GPIO_FAIL;
#elif defined(MT6752)
	return GPIO_FAIL;
#endif
}



/**
*  @brief  set gpio ownership register
*  @param  pin_num  : the gpio pin to set ownerhsip
*  @param  ownership : the ownership register bit value to set ,it should be 0~1
*                                    0: set ownership to MD
*                                    1: set ownership to AP
*  @return GPIO_OK :	set successful,  GPIO_FAIL : set failed
*/
kal_int32 gpio_get_ownership(kal_uint32 pin_num)
{
#if defined(MT6290)
	kal_uint32 reg_val;

	if(pin_num >= 64)
	{
		GPIO_PRINT("\tgpio_set_ownership failed! pin_num[%d] is over range",pin_num);
		return GPIO_FAIL;
	}
	

	if(pin_num < 32)
	{
		reg_val = REG32(GPIOMUX_GPIO_OWN1);
		reg_val = BU_G_BIT(reg_val,pin_num);
	}
	else
	{
		reg_val = REG32(GPIOMUX_GPIO_OWN2);
		reg_val = BU_G_BIT(reg_val, (pin_num - 32));
	}



	return reg_val;
#elif defined(MT6595)
	return GPIO_FAIL;
#elif defined(MT6752)
	return GPIO_FAIL;
#endif
}

void GPIO_MetaModeInit(void)
{
#if defined(MT6290)
	gpio_set_ownership(METAMODE_GPIO, GPIO_OWNERSHIP_MD);
	_GPIO_Set_Direction(METAMODE_GPIO,GPIO_AS_INPUT);
	_GPIO_Set_Pullen(METAMODE_GPIO,GPIO_ENABLE);
	_GPIO_Set_Pullsel(METAMODE_GPIO,GPIO_PULL_HIGH);
#endif
}

kal_uint32 GPIO_GetMetaMode(void)
{
#if defined(MT6290)
	kal_uint32 val;
	GPIO_READ_INPUT_VALUE(METAMODE_GPIO, &val);
	return val;
#elif defined(MT6595)
	return GPIO_FAIL;
#elif defined(MT6752)
	return GPIO_FAIL;
#endif
}


#else
//========================================================================
//  dummy function for unsuport project
//========================================================================   

#ifdef __CUST_NEW__
   #if defined(DRV_GPIO_8_MODES) || defined(DRV_GPIO_MODE_4BITS)
   extern const kal_uint32  gpio_mode_allowed[][8];
   #else //defined(DRV_GPIO_8_MODES) || defined(DRV_GPIO_MODE_4BITS)
extern const kal_uint32  gpio_mode_allowed[][4];
   #endif //defined(DRV_GPIO_8_MODES) || defined(DRV_GPIO_MODE_4BITS)
extern const kal_uint32  gpio_dir_out_allowed[];
extern const kal_uint32  gpio_dir_in_allowed[];
extern const kal_uint16  gpo_mode_allowed[];
extern kal_uint32  gpio_check_for_write[];
extern kal_uint32  gpio_check_for_read[];
extern kal_uint16  gpo_check_for_write[];
extern kal_bool   gpio_debug_enable;
#endif /* __CUST_NEW__ */


kal_int32 gpio_get_dir_value (gpio_pin_e gpio_pin) {return GPIO_FAIL;}
//kal_int32 _GPIO_Set_Direction(gpio_pin_e gpio_pin, kal_uint32 direction) {	return GPIO_FAIL;}
kal_int32 GPIO_READ_INPUT_VALUE (gpio_pin_e gpio_pin, kal_uint32 *value) {	return GPIO_FAIL;}
kal_int32 _GPIO_Set_Pullen(gpio_pin_e gpio_pin, kal_uint32 pullen)  {	return GPIO_FAIL;}
kal_int32 _GPIO_Set_Pullsel(gpio_pin_e gpio_pin, kal_uint32 updown) {	return GPIO_FAIL;}
kal_int32 GPIO_SET_DIRECT_OUTPUT (gpio_pin_e gpio_pin) {	return GPIO_FAIL;}
kal_int32 GPIO_SET_DIRECT_INPUT (gpio_pin_e gpio_pin, kal_uint32 pull_en, kal_uint32 pull_updown) {		return GPIO_FAIL;}
kal_int32 gpio_set_data_inversion(gpio_pin_e gpio_pin, kal_uint32 inversion) {return GPIO_FAIL;}
kal_int32 GPIO_WRITE_OUTPUT_VALUE (gpio_pin_e gpio_pin, kal_uint32 value) {return GPIO_FAIL;}
char GPIO_ReadIO(char port) {	return (char)0;}
void GPIO_WriteIO(char data, char port) {}
void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_data) {}
void GPIO_InitIO(char direction, char port) {}
char GPIO_ReturnMode(char port) {	return 0;}
char GPIO_ReturnDir(char port) {	return 0;}
char GPIO_ReturnDout(char port) {	return 0;}
void GPIO_PullenSetup(kal_uint16 pin, kal_bool enable) {	}
void GPIO_PullSelSetup(kal_uint16 pin, kal_bool pull_up) {}
void GPIO_DinvSetup(kal_uint16 pin, kal_bool enable) {}
void GPIO_SetDebugMode(kal_bool enable) {	 }
#ifdef __CUST_NEW__
void GPIO_InitIO_FAST(char direction, char port) { }
void GPIO_WriteIO_FAST(char data, char port) {}
char GPIO_ReadIO_FAST(char port) {	return (char)0;}
#endif
void DEVDRV_LS_INTERNCODE GPIO_WriteIO_FAST2(char data, kal_uint16 no, kal_uint16 remainder_shift) {}
//#pragma arm section code
/*conf_data = 0~3*/
void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada) {	}
void GPO_WriteIO(char data,char port) {	}
char GPO_ReturnDout(char port) {	return 0;}
char GPO_ReturnMode(char port) {	return 0;}
kal_int32 gpio_set_ownership(kal_uint32 pin_num,kal_uint32 ownership) { 	return GPIO_FAIL;}
kal_int32 gpio_set_drive(gpio_pin_e gpio_pin,kal_uint32 drive) {	return GPIO_FAIL;}
kal_int32 gpio_get_drive_value(gpio_pin_e gpio_pin) {	return GPIO_FAIL;}
kal_int32 gpio_get_ownership(kal_uint32 pin_num) {	return GPIO_FAIL;}
void GPIO_MetaModeInit(void) {}

#endif
