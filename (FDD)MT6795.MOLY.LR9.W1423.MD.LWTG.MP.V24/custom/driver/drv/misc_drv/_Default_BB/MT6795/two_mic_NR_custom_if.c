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
 *   two_mic_NR_custom_if.h
 *
 * DateTime:
 * ---------
 *   9/27/2009 3:10PM
 *
 * Project:
 * --------
 *   2-mic NR
 *
 * Description:
 * ------------
 *   This file contains the function for the state transition of the FM chip.
 *
 * Author:
 *   
 *
 **************************************************************************
 **************************************************************************/
#if defined(__TWOMICNR_SUPPORT__)

 /*****************************************************************************
 * System Include Files
 ****************************************************************************/
#include "two_mic_NR_custom_if.h"
#include "kal_public_api.h" //MSBB change #include "kal_release.h"      /* Basic data type */
#include "parameter_data_file.h"
#include "gpio_sw.h"

/*****************************************************************************
 * Local Definitions
 ****************************************************************************/ 
#define START_TOKEN	0
#define STOP_TOKEN	1
#define DW_TOKEN	2
#define DR_N_TOKEN	3

/* #define TWOMICNR_I2C_DELAY    (0x08) */
#define TWOMICNR_I2C_DELAY    (0x28)
static kal_uint32 TWOMICNR_I2C_MAX_RETRY_COUNT = 0x100;

#define SET_TWOMICNR_I2C_CLK_OUTPUT     GPIO_InitIO(OUTPUT,TWOMICNR_I2C_SCL_GPIO_PIN)
#define SET_TWOMICNR_I2C_CLK_INPUT      GPIO_InitIO(INPUT,TWOMICNR_I2C_SCL_GPIO_PIN)
#define SET_TWOMICNR_I2C_DATA_OUTPUT    GPIO_InitIO(OUTPUT,TWOMICNR_I2C_SDA_GPIO_PIN)
#define SET_TWOMICNR_I2C_DATA_INPUT     GPIO_InitIO(INPUT,TWOMICNR_I2C_SDA_GPIO_PIN)
#define SET_TWOMICNR_I2C_CLK_HIGH       GPIO_WriteIO(1,TWOMICNR_I2C_SCL_GPIO_PIN)
#define SET_TWOMICNR_I2C_CLK_LOW        GPIO_WriteIO(0,TWOMICNR_I2C_SCL_GPIO_PIN)
#define SET_TWOMICNR_I2C_DATA_HIGH      GPIO_WriteIO(1,TWOMICNR_I2C_SDA_GPIO_PIN)
#define SET_TWOMICNR_I2C_DATA_LOW       GPIO_WriteIO(0,TWOMICNR_I2C_SDA_GPIO_PIN)
#define GET_TWOMICNR_I2C_DATA_BIT       GPIO_ReadIO(TWOMICNR_I2C_SDA_GPIO_PIN)

#define TWOMICNR_I2C_RESET_TRANSMISSION             \
  {                                             \
    SET_TWOMICNR_I2C_DATA_OUTPUT;                   \
    SET_TWOMICNR_I2C_DATA_HIGH;                     \
    SET_TWOMICNR_I2C_CLK_OUTPUT;                    \
    SET_TWOMICNR_I2C_CLK_HIGH;                      \
  }
  
#define TWOMICNR_I2C_START_TRANSMISSION \
{ \
    kal_uint8 j_start; \
    SET_TWOMICNR_I2C_CLK_OUTPUT; \
    SET_TWOMICNR_I2C_DATA_OUTPUT; \
    SET_TWOMICNR_I2C_CLK_HIGH; \
    SET_TWOMICNR_I2C_DATA_HIGH; \
    for (j_start = 0; j_start < TWOMICNR_I2C_DELAY; j_start++);\
    SET_TWOMICNR_I2C_DATA_LOW; \
    for (j_start = 0; j_start < TWOMICNR_I2C_DELAY; j_start++);\
    SET_TWOMICNR_I2C_CLK_LOW; \
}



#define TWOMICNR_I2C_STOP_TRANSMISSION \
{ \
    kal_uint8 j_stop; \
    SET_TWOMICNR_I2C_CLK_OUTPUT; \
    SET_TWOMICNR_I2C_DATA_OUTPUT; \
    SET_TWOMICNR_I2C_CLK_LOW; \
    SET_TWOMICNR_I2C_DATA_LOW; \
    for (j_stop = 0; j_stop < TWOMICNR_I2C_DELAY; j_stop++);\
    SET_TWOMICNR_I2C_CLK_HIGH; \
    for (j_stop = 0; j_stop < TWOMICNR_I2C_DELAY; j_stop++);\
    SET_TWOMICNR_I2C_DATA_HIGH; \
}


#define NACK_BIT                                \
  {                                             \
    kal_uint8  i_nack;                      \
    for (i_nack=0; i_nack<TWOMICNR_I2C_DELAY; i_nack++);           \
    SET_TWOMICNR_I2C_DATA_OUTPUT;                   \
    SET_TWOMICNR_I2C_DATA_HIGH;                     \
    for (i_nack=0; i_nack<TWOMICNR_I2C_DELAY; i_nack++);           \
    SET_TWOMICNR_I2C_CLK_HIGH;                      \
    for (i_nack=0; i_nack<TWOMICNR_I2C_DELAY; i_nack++);           \
    SET_TWOMICNR_I2C_CLK_LOW;                       \
    for (i_nack=0;i_nack<TWOMICNR_I2C_DELAY;i_nack++);             \
  }  

unsigned short length_twomicBR_para;

/*****************************************************************************
 * Local Definitions
 ****************************************************************************/

static kal_bool TWOMICNR_I2C_wait_readComplete(void)
{
  kal_uint32 i=0; 
  SET_TWOMICNR_I2C_DATA_INPUT;
  while(1)
  {
    i++;
    if(GET_TWOMICNR_I2C_DATA_BIT == 0)
       break;
    if(i > TWOMICNR_I2C_MAX_RETRY_COUNT)   
       return KAL_FALSE;  
  }
    
  return KAL_TRUE;      
}


/*****************************************************************************
    Function:  Two_Mic_NR_send_byte
    Parameters:  
  	       send_byte: the 8-bits data which will be sent out by I2C mode
    Returns:  
    Side Effects:  -
              
 Description:  To send one-byte parameter into FM chip
*****************************************************************************/
static void Two_Mic_NR_send_byte(kal_uint8 send_byte)
{
    kal_uint8 i_send_byte;
    kal_uint8 j_send_byte;

    for (i_send_byte = 8; i_send_byte > 0; i_send_byte--) { /* data bit 7~0 */
        if (send_byte & (1 << (i_send_byte-1))) {
            SET_TWOMICNR_I2C_DATA_HIGH;
        }else {
            SET_TWOMICNR_I2C_DATA_LOW;
        }

        for (j_send_byte = 0; j_send_byte < TWOMICNR_I2C_DELAY; j_send_byte++);
        SET_TWOMICNR_I2C_CLK_HIGH;        
        for (j_send_byte = 0; j_send_byte < TWOMICNR_I2C_DELAY; j_send_byte++);
        SET_TWOMICNR_I2C_CLK_LOW;
        for (j_send_byte = 0; j_send_byte < TWOMICNR_I2C_DELAY; j_send_byte++);
    }
    /* don't care bit, 9th bit */
    SET_TWOMICNR_I2C_DATA_LOW;
    SET_TWOMICNR_I2C_DATA_INPUT;
    SET_TWOMICNR_I2C_CLK_HIGH;
    for (j_send_byte = 0; j_send_byte < TWOMICNR_I2C_DELAY; j_send_byte++);
/*    ret = TWOMICNR_I2C_wait_readComplete(); */
    SET_TWOMICNR_I2C_CLK_LOW;
    SET_TWOMICNR_I2C_DATA_OUTPUT;
    
    return;
}

/*****************************************************************************
    Function:  Two_Mic_NR_get_byte
    Parameters:  
  	        
    Returns:  the 8-bits data which comes from FM chip by I2C mode
    Side Effects:  -
              
 Description:  To fetch the one-byte parameter from FM chip
*****************************************************************************/
static kal_uint8 Two_Mic_NR_get_byte(void)
{
    signed char i;
    kal_uint8 j;
    kal_uint8 get_byte = 0;

    SET_TWOMICNR_I2C_DATA_INPUT;

    for (i = 7; i >= 0; i--) { /* data bit 7~0 */
        SET_TWOMICNR_I2C_CLK_HIGH;
	for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
        if (GET_TWOMICNR_I2C_DATA_BIT)
            get_byte |= (1 << i);
        for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
        SET_TWOMICNR_I2C_CLK_LOW;
        for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
    }
    /* don't care bit, 9th bit */
    SET_TWOMICNR_I2C_DATA_HIGH;
    SET_TWOMICNR_I2C_DATA_OUTPUT;
    for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
    SET_TWOMICNR_I2C_CLK_HIGH;
    for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
    SET_TWOMICNR_I2C_CLK_LOW;

    return get_byte;
} 



/*****************************************************************************
    Function:  Two_Mic_NR_Readback_para
    Parameters:  
  	       length_send: the total number of bytes which will be sent out by I2C mode
  	       parameter_array: pointer to the parameter array which will be sent out by I2C mode
   	       length_receive: the total number of bytes which will be received by I2C mode
 	       receive_parameter_array: pointer to the parameter array which will keep the parameters received by I2C mode
    Returns:
    Side Effects:  -
              
 Description:  To fetch the parameters from FM chip
*****************************************************************************/
void Two_Mic_NR_Readback_para(kal_uint32  length_send, unsigned char* send_parameter_array, kal_uint32  length_receive, unsigned char* receive_parameter_array)
{
    kal_uint8 i,j;

        TWOMICNR_I2C_START_TRANSMISSION;
        for (i = 0; i < length_send; i++);
        {
        	for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
        	Two_Mic_NR_send_byte(send_parameter_array[i]);
        }
/*        for (j = 0; j < TWOMICNR_I2C_DELAY; j++); */

        for (i = 0; i < length_receive; i++);
        {
        	for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
        	receive_parameter_array[i] = Two_Mic_NR_get_byte();
        }
        for (j = 0; j < TWOMICNR_I2C_DELAY; j++);

        TWOMICNR_I2C_STOP_TRANSMISSION;


    return;
} 


/*****************************************************************************
    Function:  Two_Mic_NR_Download
    Parameters:  
  	       mode: 0 -> handset mode; 1 -> handfree mode; 2 -> bypass mode;  3 -> Init mode
    Returns:  
    Side Effects:  -
              
 Description:  To download corresponding parameters into FM chip
*****************************************************************************/
void Two_Mic_NR_Download(unsigned short mode)
{
    kal_uint8 j;
    unsigned short i_NR_Download_para;
   
   switch (mode){

   	case 0:
        TWOMICNR_I2C_START_TRANSMISSION;
        for (i_NR_Download_para = 0; i_NR_Download_para < TWOMICNR_HANDSET_PARA_LENGTH; i_NR_Download_para++)
        {
        	for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
        	Two_Mic_NR_send_byte((kal_uint8)(parameter_data_handset_mode[i_NR_Download_para]));
        }
        for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
        TWOMICNR_I2C_STOP_TRANSMISSION;
   		break;
   	case 1:
        TWOMICNR_I2C_START_TRANSMISSION;
        for (i_NR_Download_para = 0; i_NR_Download_para < TWOMICNR_HANDFREE_PARA_LENGTH; i_NR_Download_para++)
        {
        	for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
        	Two_Mic_NR_send_byte((kal_uint8)(parameter_data_handfree_mode[i_NR_Download_para]));
        }
        for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
        TWOMICNR_I2C_STOP_TRANSMISSION;
   		break;
   	case 2:
        TWOMICNR_I2C_START_TRANSMISSION;
        for (i_NR_Download_para = 0; i_NR_Download_para < TWOMICNR_BYPASS_PARA_LENGTH; i_NR_Download_para++)
        {
        	for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
        	Two_Mic_NR_send_byte((kal_uint8)(parameter_data_bypass_mode[i_NR_Download_para]));
        }
        for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
        TWOMICNR_I2C_STOP_TRANSMISSION;
   		break;
   	case 3:
        TWOMICNR_I2C_START_TRANSMISSION;
        for (i_NR_Download_para = 0; i_NR_Download_para < TWOMICNR_INIT_PARA_LENGTH; i_NR_Download_para++)
        {
        	for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
        	Two_Mic_NR_send_byte((kal_uint8)(parameter_data_Init[i_NR_Download_para]));
        }
        for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
        TWOMICNR_I2C_STOP_TRANSMISSION;
   		break;
   	default:
   		break;
   }
      		
   return;
}


/*****************************************************************************
    Function:  Two_Mic_NR_chip_Sleep
    Parameters:  
  	       
    Returns:  
    Side Effects:  -
              
 Description:  To sleep the FM chip.
	1. Set PWD low
	2. Wait 15ms
	3. Turn off the main clock
****************************************************************************/
void Two_Mic_NR_chip_Sleep(void)
{
  /*Set PWD low */
  GPIO_WriteIO(0,TWOMICNR_FM_PWDN_GPIO_PIN);

  /*Wait 15ms */
  kal_sleep_task(4);

  /*Turn off the main clock */
  GPIO_ModeSetup(TWOMICNR_FM_13MHZ_GPIO_PIN, 0); /* GPIO mode */
  GPIO_InitIO(OUTPUT,TWOMICNR_FM_13MHZ_GPIO_PIN);
  GPIO_WriteIO(0,TWOMICNR_FM_13MHZ_GPIO_PIN);  /* low voltage */

  return;
}


/*****************************************************************************
    Function:  Two_Mic_NR_chip_Init
    Parameters:  
  	       
    Returns:  
    Side Effects:  -
              
 Description:  To initialize the FM chip after power on of the handset
	1.  RST/PWD/BYPASS power on default at low 
	2.  Open main clock
	3.  Set PWD high
	4.  Wait 5ms
	5.  Set RST high
	6.  Wait 15ms
*****************************************************************************/
void Two_Mic_NR_chip_Init(void)
{
  /*RST/PWD/BYPASS power on default at low */
  GPIO_ModeSetup(TWOMICNR_FM_RST_GPIO_PIN, 0); /* GPIO mode */
  GPIO_InitIO(OUTPUT,TWOMICNR_FM_RST_GPIO_PIN);
  GPIO_WriteIO(0,TWOMICNR_FM_RST_GPIO_PIN);
  GPIO_ModeSetup(TWOMICNR_FM_PWDN_GPIO_PIN, 0); /* GPIO mode */
  GPIO_InitIO(OUTPUT,TWOMICNR_FM_PWDN_GPIO_PIN);
  GPIO_WriteIO(0,TWOMICNR_FM_PWDN_GPIO_PIN);
  GPIO_ModeSetup(TWOMICNR_FM_BYPASS_GPIO_PIN, 0); /* GPIO mode */
  GPIO_InitIO(OUTPUT,TWOMICNR_FM_BYPASS_GPIO_PIN);
  GPIO_WriteIO(0,TWOMICNR_FM_BYPASS_GPIO_PIN);

  /*Open main clock */
  (*(volatile kal_uint16 *)(0x84023200)) = 0x3;	/* 13MHz */
  GPIO_ModeSetup(TWOMICNR_FM_13MHZ_GPIO_PIN, 2); /* CLKM2 mode */
  
  /*Set PWD high */
  GPIO_WriteIO(1,TWOMICNR_FM_PWDN_GPIO_PIN);

  /*Wait 5ms */
  /*1 ticks = 4.615ms */
  kal_sleep_task(2);

  /*Set RST high */
  GPIO_WriteIO(1,TWOMICNR_FM_RST_GPIO_PIN);

  /*Wait 15ms */
  kal_sleep_task(4);
  
  /*Download Init_para */
  Two_Mic_NR_Download(3);
  
  /*Enter power-down state */
  Two_Mic_NR_chip_Sleep();
  
  return;
}

/*****************************************************************************
    Function:  FM_chip_Reset
    Parameters:  
  	       
    Returns:  
    Side Effects:  -
              
 Description:  To reset the FM chip
	1.  Mute UL path
	2.  If clock is not running, turn on the main clock first
	3.  Set BYPASS low
	4.  Set PWD high
	5.  Set RST low
	6.  Wait 1ms.
	7.  Set RST high
	8.  Wait 15 ms.
	9.  Un-mute UL path
*****************************************************************************/
void FM_chip_Reset(void)
{
  /*Mute UL path */

  /*If clock is not running, turn on the main clock first */
  (*(volatile unsigned short *)(0x84023200)) = 0x3;	/* 13MHz */
  GPIO_ModeSetup(TWOMICNR_FM_13MHZ_GPIO_PIN, 2); /* CLKM2 mode */
  
  /*Set BYPASS low */
  GPIO_WriteIO(0,TWOMICNR_FM_BYPASS_GPIO_PIN);

  /*Set PWD high */
  GPIO_WriteIO(1,TWOMICNR_FM_PWDN_GPIO_PIN);

  /* Set RST low */
  GPIO_WriteIO(0,TWOMICNR_FM_RST_GPIO_PIN);

  /* Wait 1ms */
  kal_sleep_task(2);

  /* Set RST high */
  GPIO_WriteIO(1,TWOMICNR_FM_RST_GPIO_PIN);

  /* Wait 15ms */
  kal_sleep_task(4);
  
  /* Un-mute UL path */
  
  return;
}



/*****************************************************************************
    Function:  Two_Mic_NR_chip_Bypass_mode
    Parameters:  
  	       
    Returns:  
    Side Effects:  -
              
 Description:  Make the FM chip to enter bypass mode
*****************************************************************************/
void Two_Mic_NR_chip_Bypass_mode(void)
{
  FM_chip_Reset();
  
  /* Download bypass parameter */
  Two_Mic_NR_Download(2);

  /* Wait 100 ms */
  kal_sleep_task(25);

  /*Set BYPASS high */
  GPIO_WriteIO(1,TWOMICNR_FM_BYPASS_GPIO_PIN);
  
  return;
}

/*****************************************************************************
    Function:  Two_Mic_NR_chip_exit_Bypass_mode
    Parameters:  
  	       
    Returns:  
    Side Effects:  -
              
 Description:  Make the FM chip to exit bypass mode, into power down mode
*****************************************************************************/
void Two_Mic_NR_chip_exit_Bypass_mode(void)
{
  /*Set BYPASS low */
  GPIO_WriteIO(0,TWOMICNR_FM_BYPASS_GPIO_PIN);
  Two_Mic_NR_chip_Sleep();
  
  return;
}


/*****************************************************************************
    Function:  Two_Mic_NR_chip_Handset_mode
    Parameters:  
  	       
    Returns:  
    Side Effects:  -
              
 Description:  Make the FM chip to enter handset mode
*****************************************************************************/
void Two_Mic_NR_chip_Handset_mode(void)
{
  FM_chip_Reset();
  
  /* Download handset parameter */
  Two_Mic_NR_Download(0);
  
  return;
}


/*****************************************************************************
    Function:  Two_Mic_NR_chip_Handfree_mode
    Parameters:  
  	       
    Returns:  
    Side Effects:  -
              
 Description:  Make the FM chip to enter handfree mode
*****************************************************************************/
void Two_Mic_NR_chip_Handfree_mode(void)
{
  FM_chip_Reset();
  
  /*Download handfree parameter */
  Two_Mic_NR_Download(1);
  
  return;
}




/****************************************************************************************************************************
    Function:  Two_Mic_NR_GPIO_con
    Parameters:  
  	       GPIO_pin_name: the GPIO pin to be manipulated. 				0 -> reset  1 -> PWDN  2 -> bypass
  	       GPIO_pin_voltage : the voltage level which needs to be reached. 		0 -> low  1 -> high
    Returns:  
    Side Effects:  -
              
 Description:  To manipulate the GPIO pin according to the command, which comes from PC tools through UART port
****************************************************************************************************************************/
void Two_Mic_NR_GPIO_con(unsigned short GPIO_pin_name,unsigned short GPIO_pin_voltage)
{
   switch (GPIO_pin_name){
   	case 0:
		GPIO_ModeSetup(TWOMICNR_FM_RST_GPIO_PIN, 0); /* GPIO mode */
		GPIO_InitIO(OUTPUT,TWOMICNR_FM_RST_GPIO_PIN);
		if (GPIO_pin_voltage == 0)
		{
			GPIO_WriteIO(0,TWOMICNR_FM_RST_GPIO_PIN);
		}
		else
		{
			GPIO_WriteIO(1,TWOMICNR_FM_RST_GPIO_PIN);
		}
   		break;
   	case 1:
		GPIO_ModeSetup(TWOMICNR_FM_PWDN_GPIO_PIN, 0); /* GPIO mode */
		GPIO_InitIO(OUTPUT,TWOMICNR_FM_PWDN_GPIO_PIN);
		if (GPIO_pin_voltage == 0)
		{
			GPIO_WriteIO(0,TWOMICNR_FM_PWDN_GPIO_PIN);
		}
		else
		{
			GPIO_WriteIO(1,TWOMICNR_FM_PWDN_GPIO_PIN);
		}
   		break;
   	case 2:
		GPIO_ModeSetup(TWOMICNR_FM_BYPASS_GPIO_PIN, 0); /* GPIO mode */
		GPIO_InitIO(OUTPUT,TWOMICNR_FM_BYPASS_GPIO_PIN);
		if (GPIO_pin_voltage == 0)
		{
			GPIO_WriteIO(0,TWOMICNR_FM_BYPASS_GPIO_PIN);
		}
		else
		{
			GPIO_WriteIO(1,TWOMICNR_FM_BYPASS_GPIO_PIN);
		}
   		break;
   	default:
   		break;
   }


  return;
}


/****************************************************************************************************************************
    Function:  Two_mic_NR_I2C_download_data
    Parameters:  
  	       Command_data_to_be_sent: this array contains the command data to be downloaded into the FM2018x chip
  	       One_command_data_length : the length of this array
    Returns:  
    Side Effects:  -
              
 Description:  To download the corresponding parameters into FM chip, which comes from PC tools through UART port
****************************************************************************************************************************/
void Two_mic_NR_I2C_download_data(unsigned char* Command_data_to_be_sent,kal_uint16 One_command_data_length)
{
  kal_uint8 j;
  kal_uint16 counter;
   
   TWOMICNR_I2C_START_TRANSMISSION;
   for (counter = 0; counter < One_command_data_length; counter++)
   {
   	for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
   	Two_Mic_NR_send_byte((kal_uint8)(Command_data_to_be_sent[counter]));
   }
   for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
   TWOMICNR_I2C_STOP_TRANSMISSION;

      		
   return;
}


/****************************************************************************************************************************
    Function:  Two_mic_NR_I2C_readback_data
    Parameters:  
  	       readback_command_to_be_sent: the chip ID of the FM2018x for reading back operation, '0xC1' now
  	       readback_data_length : the length of this array
    Returns:  
    Side Effects:  -
              
 Description:  To download the corresponding parameters into FM chip, which comes from PC tools through UART port
****************************************************************************************************************************/
unsigned char Two_mic_NR_I2C_readback_data(unsigned char readback_command_to_be_sent)
{
  kal_uint8 j;
  kal_uint8 return_value;

   
   TWOMICNR_I2C_START_TRANSMISSION;
   
   for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
   Two_Mic_NR_send_byte((kal_uint8)readback_command_to_be_sent);

   for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
   return_value = Two_Mic_NR_get_byte();
   	
   for (j = 0; j < TWOMICNR_I2C_DELAY; j++);
   TWOMICNR_I2C_STOP_TRANSMISSION;
      		
  
   return (unsigned char)return_value;
}


#endif
