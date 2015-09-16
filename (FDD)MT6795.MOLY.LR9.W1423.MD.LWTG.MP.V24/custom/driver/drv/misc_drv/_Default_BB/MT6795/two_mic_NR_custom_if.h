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

#ifndef TWO_MIC_NR_CUSTOM_IF_H
#define TWO_MIC_NR_CUSTOM_IF_H

#include "kal_public_api.h" //MSBB change #include "kal_release.h"      /* Basic data type */

#ifdef __CUST_NEW__

extern const char gpio_2micNR_scl_pin;
extern const char gpio_2micNR_sda_pin;
extern const char gpio_2micNR_bypass_pin;
extern const char gpio_2micNR_13mhz_pin;
extern const char gpio_2micNR_rst_pin;
extern const char gpio_2micNR_pwdn_pin;

#define TWOMICNR_I2C_SCL_GPIO_PIN	gpio_2micNR_scl_pin
#define TWOMICNR_I2C_SDA_GPIO_PIN	gpio_2micNR_sda_pin
#define TWOMICNR_FM_13MHZ_GPIO_PIN	gpio_2micNR_13mhz_pin
#define TWOMICNR_FM_RST_GPIO_PIN	gpio_2micNR_rst_pin
#define TWOMICNR_FM_PWDN_GPIO_PIN	gpio_2micNR_pwdn_pin
#define TWOMICNR_FM_BYPASS_GPIO_PIN	gpio_2micNR_bypass_pin

 
#else //__CUST_NEW__

enum
{ 
  TWOMICNR_I2C_SCL_GPIO_PIN 	= 36,
  TWOMICNR_I2C_SDA_GPIO_PIN	= 37,
  TWOMICNR_FM_13MHZ_GPIO_PIN	= 43,
  TWOMICNR_FM_RST_GPIO_PIN	= 52,
  TWOMICNR_FM_PWDN_GPIO_PIN	= 53,
  TWOMICNR_FM_BYPASS_GPIO_PIN	= 54
};

#endif //__CUST_NEW__


/***************************************************************************
 *  Function Prototypes
 **************************************************************************/
extern void Two_Mic_NR_chip_Handfree_mode(void);
extern void Two_Mic_NR_chip_Init(void);
extern void Two_Mic_NR_chip_Handset_mode(void);
extern void Two_Mic_NR_chip_Bypass_mode(void);
extern void Two_Mic_NR_chip_exit_Bypass_mode(void);
extern void Two_Mic_NR_chip_Sleep(void);

extern unsigned char Two_mic_NR_I2C_readback_data(unsigned char readback_command_to_be_sent);
extern void Two_mic_NR_I2C_download_data(unsigned char* Command_data_to_be_sent,kal_uint16 One_command_data_length);
extern void Two_Mic_NR_GPIO_con(unsigned short GPIO_pin_name,unsigned short GPIO_pin_voltage);
#endif
