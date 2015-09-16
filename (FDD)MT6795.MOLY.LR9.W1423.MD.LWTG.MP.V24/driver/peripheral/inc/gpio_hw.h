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
 *    gpio_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for GPIO driver.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _GPIO_HW_H
#define _GPIO_HW_H
   
#include "drv_features_gpio.h"
#include "reg_base.h"

#if !defined(DRV_GPIO_OFF)
   //MMP address
#if defined(DRV_GPIO_REG_AS_6205) || defined(DRV_GPIO_REG_AS_6205B)
   #define 	GPIO_DIR         	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   	    (GPIO_base+0x0004)
   #define 	GPIO_PULLEN    	    (GPIO_base+0x0008)
   #define 	GPIO_PULLEN2   	    (GPIO_base+0x000c)
   #define 	GPIO_DOUT      	    (GPIO_base+0x0010)
   #define 	GPIO_DOUT2      	(GPIO_base+0x0014)
   #define 	GPIO_DIN       	    (GPIO_base+0x0018)
   #define 	GPIO_DIN2       	(GPIO_base+0x001c)
   #define 	GPO_DOUT       	    (GPIO_base+0x0020)
   #define 	GPIO_MODE1       	(GPIO_base+0x0024)
   #define 	GPIO_MODE2       	(GPIO_base+0x0028)
   #define 	GPIO_MODE3       	(GPIO_base+0x002c)
   #define 	GPIO_MODE4       	(GPIO_base+0x0030)
   
   
   #if defined(DRV_GPIO_REG_AS_6205B)
      #define 	GPIO_DIR_SET    (GPIO_base+0x0040+0x0000)
      #define 	GPIO_DIR2_SET   (GPIO_base+0x0040+0x0004)
      #define 	GPIO_PULLEN_SET (GPIO_base+0x0040+0x0008)
      #define 	GPIO_PULLEN2_SET (GPIO_base+0x0040+0x000c)
      #define 	GPIO_DOUT_SET   (GPIO_base+0x0040+0x0010)
      #define 	GPIO_DOUT2_SET      	   (GPIO_base+0x0040+0x0014)
      #define 	GPIO_DIN_SET       	   (GPIO_base+0x0040+0x0018)
      #define 	GPIO_DIN2_SET       	   (GPIO_base+0x0040+0x001c)
      #define 	GPO_DOUT_SET       	   (GPIO_base+0x0040+0x0020)
      #define 	GPIO_MODE1_SET       	(GPIO_base+0x0040+0x0024)
      #define 	GPIO_MODE2_SET       	(GPIO_base+0x0040+0x0028)
      #define 	GPIO_MODE3_SET       	(GPIO_base+0x0040+0x002c)
      #define 	GPIO_MODE4_SET       	(GPIO_base+0x0040+0x0030)
      #define  GPIO_MODE_SET(_no) (GPIO_MODE1_SET+(0x04*(_no)))
      
      #define 	GPIO_DIR_CLR         	(GPIO_base+0x0080+0x0000)
      #define 	GPIO_DIR2_CLR   	      (GPIO_base+0x0080+0x0004)
      #define 	GPIO_PULLEN_CLR    	   (GPIO_base+0x0080+0x0008)
      #define 	GPIO_PULLEN2_CLR   	   (GPIO_base+0x0080+0x000c)
      #define 	GPIO_DOUT_CLR      	   (GPIO_base+0x0080+0x0010)
      #define 	GPIO_DOUT2_CLR      	   (GPIO_base+0x0080+0x0014)
      #define 	GPIO_DIN_CLR       	   (GPIO_base+0x0080+0x0018)
      #define 	GPIO_DIN2_CLR       	   (GPIO_base+0x0080+0x001c)
      #define 	GPO_DOUT_CLR       	   (GPIO_base+0x0080+0x0020)
      #define 	GPIO_MODE1_CLR       	(GPIO_base+0x0080+0x0024)
      #define 	GPIO_MODE2_CLR       	(GPIO_base+0x0080+0x0028)
      #define 	GPIO_MODE3_CLR       	(GPIO_base+0x0080+0x002c)
      #define 	GPIO_MODE4_CLR       	(GPIO_base+0x0080+0x0030)
      #define  GPIO_MODE_CLR(_no) (GPIO_MODE1_CLR+(0x04*(_no)))
      

   #endif   /*DRV_GPIO_REG_AS_6205B*/
   
      #define  GPIO_MODE(_no)          (GPIO_MODE1+(0x4*(_no))) 
      
#endif /*DRV_GPIO_REG_AS_6205,DRV_GPIO_REG_AS_6205B*/

#if defined(DRV_GPIO_REG_AS_6208) || defined(FPGA)
   #define 	GPIO_DIR   	   (GPIO_base+0x0000)
   #define 	GPIO_DOUT  	   (GPIO_base+0x0004)
   #define 	GPIO_DIN   	   (GPIO_base+0x0008)
   #define 	GPIO_MODE1 	   (GPIO_base+0x000C)
   #define 	GPIO_MODE2 	   (GPIO_base+0x0010)
   #define 	GPI_O_DIO     	(GPIO_base+0x0018)
   #define 	GPI_O_MODE  	(GPIO_base+0x001c)
   
   #define  GPIO_MODE(_no)          (GPIO_MODE1+(0x4*(_no))) 

#endif   /*DRV_GPIO_REG_AS_6208,FPGA*/

#if defined(DRV_GPIO_REG_AS_6218)
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   	    (GPIO_base+0x0010)
   #define 	GPIO_DIR3           (GPIO_base+0x0020)
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0030)
   #define 	GPIO_PULLEN2    	(GPIO_base+0x0040)
   #define 	GPIO_PULLEN3   	    (GPIO_base+0x0050)
   #define 	GPIO_DOUT1      	(GPIO_base+0x0060)
   #define 	GPIO_DOUT2      	(GPIO_base+0x0070)
   #define 	GPIO_DOUT3      	(GPIO_base+0x0080)
   #define 	GPIO_DIN1       	(GPIO_base+0x0090)
   #define 	GPIO_DIN2       	(GPIO_base+0x0094)
   #define 	GPIO_DIN3       	(GPIO_base+0x0098)
   #define 	GPO_DOUT       	    (GPIO_base+0x00a0)
   #define 	GPIO_MODE1       	(GPIO_base+0x00b0)
   #define 	GPIO_MODE2       	(GPIO_base+0x00c0)
   #define 	GPIO_MODE3       	(GPIO_base+0x00d0)
   #define 	GPIO_MODE4       	(GPIO_base+0x00e0)
   #define 	GPIO_MODE5       	(GPIO_base+0x00f0)
   #define 	GPIO_MODE6       	(GPIO_base+0x0100)
   #define 	GPO_MODE       	    (GPIO_base+0x0110)
   
   #define 	GPIO_DIR1_SET       (GPIO_base+0x0000+0x04)
   #define 	GPIO_DIR2_SET    	(GPIO_base+0x0010+0x04)
   #define 	GPIO_DIR3_SET       (GPIO_base+0x0020+0x04)
   #define 	GPIO_PULLEN1_SET    (GPIO_base+0x0030+0x04)
   #define 	GPIO_PULLEN2_SET    (GPIO_base+0x0040+0x04)
   #define 	GPIO_PULLEN3_SET   	(GPIO_base+0x0050+0x04)
   #define 	GPIO_DOUT1_SET      (GPIO_base+0x0060+0x04)
   #define 	GPIO_DOUT2_SET      (GPIO_base+0x0070+0x04)
   #define 	GPIO_DOUT3_SET      (GPIO_base+0x0080+0x04)
   #define 	GPO_DOUT_SET       	(GPIO_base+0x00a0+0x04)
   #define 	GPIO_MODE1_SET      (GPIO_base+0x00b0+0x04)
   #define 	GPIO_MODE2_SET      (GPIO_base+0x00c0+0x04)
   #define 	GPIO_MODE3_SET      (GPIO_base+0x00d0+0x04)
   #define 	GPIO_MODE4_SET      (GPIO_base+0x00e0+0x04)
   #define 	GPIO_MODE5_SET      (GPIO_base+0x00f0+0x04)
   #define 	GPIO_MODE6_SET      (GPIO_base+0x0100+0x04)
   #define 	GPO_MODE_SET       	(GPIO_base+0x0110+0x04)
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x10*(_no)))
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x10*(_no)))
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x10*(_no)))
   
   #define 	GPIO_DIR1_CLR       (GPIO_base+0x0000+0x08)
   #define 	GPIO_DIR2_CLR   	(GPIO_base+0x0010+0x08)
   #define 	GPIO_DIR3_CLR       (GPIO_base+0x0020+0x08)
   #define 	GPIO_PULLEN1_CLR    (GPIO_base+0x0030+0x08)
   #define 	GPIO_PULLEN2_CLR    (GPIO_base+0x0040+0x08)
   #define 	GPIO_PULLEN3_CLR   	(GPIO_base+0x0050+0x08)
   #define 	GPIO_DOUT1_CLR      (GPIO_base+0x0060+0x08)
   #define 	GPIO_DOUT2_CLR      (GPIO_base+0x0070+0x08)
   #define 	GPIO_DOUT3_CLR      (GPIO_base+0x0080+0x08)
   #define 	GPO_DOUT_CLR       	(GPIO_base+0x00a0+0x08)
   #define 	GPIO_MODE1_CLR      (GPIO_base+0x00b0+0x08)
   #define 	GPIO_MODE2_CLR      (GPIO_base+0x00c0+0x08)
   #define 	GPIO_MODE3_CLR      (GPIO_base+0x00d0+0x08)
   #define 	GPIO_MODE4_CLR      (GPIO_base+0x00e0+0x08)
   #define 	GPIO_MODE5_CLR      (GPIO_base+0x00f0+0x08)
   #define 	GPIO_MODE6_CLR      (GPIO_base+0x0100+0x08)
   #define 	GPO_MODE_CLR       	(GPIO_base+0x0110+0x08)
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x10*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x10*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x10*(_no)))
   
   #define  GPIO_MODE(_no)      (GPIO_MODE1+(0x10*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x10*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x10*(_no))) 
#endif   /*DRV_GPIO_REG_AS_6218*/

#if defined(DRV_GPIO_REG_AS_6218B)
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   	    (GPIO_base+0x0010)
   #define 	GPIO_DIR3           (GPIO_base+0x0020)
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0030)
   #define 	GPIO_PULLEN2    	(GPIO_base+0x0040)
   #define 	GPIO_PULLEN3   	    (GPIO_base+0x0050)
   #define 	GPIO_DINV1      	(GPIO_base+0x0060)
   #define 	GPIO_DINV2      	(GPIO_base+0x0070)
   #define 	GPIO_DINV3      	(GPIO_base+0x0080)
   #define 	GPIO_DOUT1      	(GPIO_base+0x0090)
   #define 	GPIO_DOUT2      	(GPIO_base+0x00a0)
   #define 	GPIO_DOUT3      	(GPIO_base+0x00b0)
   #define 	GPIO_DIN1       	(GPIO_base+0x00c0)
   #define 	GPIO_DIN2       	(GPIO_base+0x00d0)
   #define 	GPIO_DIN3       	(GPIO_base+0x00e0)
   #define 	GPO_DOUT       	    (GPIO_base+0x00f0)
   #define 	GPIO_MODE1       	(GPIO_base+0x0100)
   #define 	GPIO_MODE2       	(GPIO_base+0x0110)
   #define 	GPIO_MODE3       	(GPIO_base+0x0120)
   #define 	GPIO_MODE4       	(GPIO_base+0x0130)
   #define 	GPIO_MODE5       	(GPIO_base+0x0140)
   #define 	GPIO_MODE6       	(GPIO_base+0x0150)
   #define 	GPO_MODE       	    (GPIO_base+0x0160)
   
   #define 	GPIO_DIR1_SET       (GPIO_base+0x0000+0x04)
   #define 	GPIO_DIR2_SET    	(GPIO_base+0x0010+0x04)        
   #define 	GPIO_DIR3_SET       (GPIO_base+0x0020+0x04)      
   #define 	GPIO_PULLEN1_SET    (GPIO_base+0x0030+0x04)      
   #define 	GPIO_PULLEN2_SET    (GPIO_base+0x0040+0x04)      
   #define 	GPIO_PULLEN3_SET   	(GPIO_base+0x0050+0x04)     
   #define 	GPIO_DOUT1_SET      (GPIO_base+0x0090+0x04)      
   #define 	GPIO_DOUT2_SET      (GPIO_base+0x00a0+0x04)      
   #define 	GPIO_DOUT3_SET      (GPIO_base+0x00b0+0x04)      
   #define 	GPO_DOUT_SET       	(GPIO_base+0x00f0+0x04)     
   #define 	GPIO_MODE1_SET      (GPIO_base+0x0100+0x04)      
   #define 	GPIO_MODE2_SET      (GPIO_base+0x0110+0x04)      
   #define 	GPIO_MODE3_SET      (GPIO_base+0x0120+0x04)      
   #define 	GPIO_MODE4_SET      (GPIO_base+0x0130+0x04)      
   #define 	GPIO_MODE5_SET      (GPIO_base+0x0140+0x04)      
   #define 	GPIO_MODE6_SET      (GPIO_base+0x0150+0x04)      
   #define 	GPO_MODE_SET       	(GPIO_base+0x0160+0x04)       
   #define  GPIO_DINV_ADRS(n)	(GPIO_DINV1+0x10*(n))
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x10*(_no)))  
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x10*(_no)))   
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x10*(_no)))  
   #define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x10*(_no)))  
                                                               
   #define 	GPIO_DIR1_CLR       (GPIO_base+0x0000+0x08)         
   #define 	GPIO_DIR2_CLR   	(GPIO_base+0x0010+0x08)        
   #define 	GPIO_DIR3_CLR       (GPIO_base+0x0020+0x08)       
   #define 	GPIO_PULLEN1_CLR    (GPIO_base+0x0030+0x08)       
   #define 	GPIO_PULLEN2_CLR    (GPIO_base+0x0040+0x08)       
   #define 	GPIO_PULLEN3_CLR   	(GPIO_base+0x0050+0x08)   
   #define 	GPIO_DOUT1_CLR      (GPIO_base+0x0090+0x08)       
   #define 	GPIO_DOUT2_CLR      (GPIO_base+0x00a0+0x08)       
   #define 	GPIO_DOUT3_CLR      (GPIO_base+0x00b0+0x08)       
   #define 	GPO_DOUT_CLR       	(GPIO_base+0x00f0+0x08)   
   #define 	GPIO_MODE1_CLR      (GPIO_base+0x0100+0x08)       
   #define 	GPIO_MODE2_CLR      (GPIO_base+0x0110+0x08)       
   #define 	GPIO_MODE3_CLR      (GPIO_base+0x0120+0x08)       
   #define 	GPIO_MODE4_CLR      (GPIO_base+0x0130+0x08)       
   #define 	GPIO_MODE5_CLR      (GPIO_base+0x0140+0x08)       
   #define 	GPIO_MODE6_CLR      (GPIO_base+0x0150+0x08)       
   #define 	GPO_MODE_CLR       	(GPIO_base+0x0160+0x08)   
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x10*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x10*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x10*(_no)))
   #define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN1_CLR+(0x10*(_no)))  
   
   #define  GPIO_MODE(_no)      (GPIO_MODE1+(0x10*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x10*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x10*(_no)))
#endif   /*DRV_GPIO_REG_AS_6218B*/

#if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223)
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   	   (GPIO_base+0x0010)
   #define 	GPIO_DIR3         (GPIO_base+0x0020)
   #define 	GPIO_DIR4         (GPIO_base+0x0030)
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0040)
   #define 	GPIO_PULLEN2    	(GPIO_base+0x0050)
   #define 	GPIO_PULLEN3   	(GPIO_base+0x0060)
   #define 	GPIO_PULLEN4      (GPIO_base+0x0070)
   #define 	GPIO_DINV1      	(GPIO_base+0x0080)
   #define 	GPIO_DINV2      	(GPIO_base+0x0090)
   #define 	GPIO_DINV3      	(GPIO_base+0x00a0)
   #define 	GPIO_DINV4      	(GPIO_base+0x00b0)
   #define 	GPIO_DOUT1      	(GPIO_base+0x00c0)
   #define 	GPIO_DOUT2      	(GPIO_base+0x00d0)
   #define 	GPIO_DOUT3      	(GPIO_base+0x00e0)
   #define 	GPIO_DOUT4      	(GPIO_base+0x00f0)
   #define 	GPIO_DIN1       	(GPIO_base+0x0100)
   #define 	GPIO_DIN2       	(GPIO_base+0x0110)
   #define 	GPIO_DIN3       	(GPIO_base+0x0120)
   #define 	GPIO_DIN4       	(GPIO_base+0x0130)
   #if !defined(DRV_GPIO_REG_AS_6223)
      #define 	GPO_DOUT       	(GPIO_base+0x0140)
   #endif /* DRV_GPIO_REG_AS_6223 */
   #define 	GPIO_MODE1       	(GPIO_base+0x0150)
   #define 	GPIO_MODE2       	(GPIO_base+0x0160)
   #define 	GPIO_MODE3       	(GPIO_base+0x0170)         
   #define 	GPIO_MODE4       	(GPIO_base+0x0180)         
   #define 	GPIO_MODE5       	(GPIO_base+0x0190)         
   #define 	GPIO_MODE6       	(GPIO_base+0x01a0)         
   #define 	GPIO_MODE7       	(GPIO_base+0x01b0)         
   #if defined(DRV_GPIO_REG_AS_6223)
      #define 	GPIO_BANK       	(GPIO_base+0x01c0)   
      #define  CLKO_MODE1      	(GPIO_base+0x0200)   
      #define  CLKO_MODE2      	(GPIO_base+0x0210)   
      #define  CLKO_MODE3      	(GPIO_base+0x0220)   
      #define  CLKO_MODE4      	(GPIO_base+0x0230)   
      #define  CLKO_MODE5      	(GPIO_base+0x0240)   
      #define  CLKO_MODE6      	(GPIO_base+0x0250)   
   #else /* DRV_GPIO_REG_AS_6223 */
      #define 	GPO_MODE       	(GPIO_base+0x01c0)         
   #endif /* DRV_GPIO_REG_AS_6223 */
	#define  GPIO_DINV_ADRS(n)	(GPIO_DINV1+0x10*(n))  
   
   #define 	GPIO_DIR1_SET       (GPIO_base+0x0000+0x04)  
   #define 	GPIO_DIR2_SET    	  (GPIO_base+0x0010+0x04)        
   #define 	GPIO_DIR3_SET       (GPIO_base+0x0020+0x04)      
   #define 	GPIO_DIR4_SET       (GPIO_base+0x0030+0x04)  
   #define 	GPIO_PULLEN1_SET    (GPIO_base+0x0040+0x04)      
   #define 	GPIO_PULLEN2_SET    (GPIO_base+0x0050+0x04)      
   #define 	GPIO_PULLEN3_SET    (GPIO_base+0x0060+0x04)     
   #define 	GPIO_PULLEN4_SET    (GPIO_base+0x0070+0x04)  
   #define 	GPIO_DOUT1_SET      (GPIO_base+0x00c0+0x04)      
   #define 	GPIO_DOUT2_SET      (GPIO_base+0x00d0+0x04)      
   #define 	GPIO_DOUT3_SET      (GPIO_base+0x00e0+0x04)      
   #define 	GPIO_DOUT4_SET      (GPIO_base+0x00f0+0x04)  
   #if !defined(DRV_GPIO_REG_AS_6223)
      #define 	GPO_DOUT_SET        (GPIO_base+0x0140+0x04)     
   #endif /* DRV_GPIO_REG_AS_6223 */
   #define 	GPIO_MODE1_SET      (GPIO_base+0x0150+0x04)      
   #define 	GPIO_MODE2_SET      (GPIO_base+0x0160+0x04)      
   #define 	GPIO_MODE3_SET      (GPIO_base+0x0170+0x04)      
   #define 	GPIO_MODE4_SET      (GPIO_base+0x0180+0x04)      
   #define 	GPIO_MODE5_SET      (GPIO_base+0x0190+0x04)      
   #define 	GPIO_MODE6_SET      (GPIO_base+0x01a0+0x04)      
   #define 	GPIO_MODE7_SET      (GPIO_base+0x01b0+0x04)  
   #if defined(DRV_GPIO_REG_AS_6223)
      #define 	GPIO_BANK_SET       	(GPIO_base+0x01c0+0x04)   
      #define  CLKO_MODE1_SET      	(GPIO_base+0x0200+0x04)   
      #define  CLKO_MODE2_SET      	(GPIO_base+0x0210+0x04)   
      #define  CLKO_MODE3_SET      	(GPIO_base+0x0220+0x04)   
      #define  CLKO_MODE4_SET      	(GPIO_base+0x0230+0x04)   
      #define  CLKO_MODE5_SET      	(GPIO_base+0x0240+0x04)   
      #define  CLKO_MODE6_SET      	(GPIO_base+0x0250+0x04) 
   #else /* DRV_GPIO_REG_AS_6223 */
      #define 	GPO_MODE_SET        (GPIO_base+0x01c0+0x04)       
   #endif /* DRV_GPIO_REG_AS_6223 */
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x10*(_no)))  
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x10*(_no)))   
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x10*(_no)))  
   #define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x10*(_no)))  
   #if defined(DRV_GPIO_REG_AS_6223)
      #define  CLKO_MODE_SET(_no)  (CLKO_MODE1_SET+(0x10*(_no)))  
   #endif /* DRV_GPIO_REG_AS_6223 */
   #define 	GPIO_DIR1_CLR       (GPIO_base+0x0000+0x08)         
   #define 	GPIO_DIR2_CLR   	  (GPIO_base+0x0010+0x08)        
   #define 	GPIO_DIR3_CLR       (GPIO_base+0x0020+0x08)       
   #define 	GPIO_DIR4_CLR       (GPIO_base+0x0030+0x08)  
   #define 	GPIO_PULLEN1_CLR    (GPIO_base+0x0040+0x08)       
   #define 	GPIO_PULLEN2_CLR    (GPIO_base+0x0050+0x08)       
   #define 	GPIO_PULLEN3_CLR    (GPIO_base+0x0060+0x08)   
   #define 	GPIO_PULLEN4_CLR    (GPIO_base+0x0070+0x08)
   #define 	GPIO_DOUT1_CLR      (GPIO_base+0x00c0+0x08)       
   #define 	GPIO_DOUT2_CLR      (GPIO_base+0x00d0+0x08)       
   #define 	GPIO_DOUT3_CLR      (GPIO_base+0x00e0+0x08)       
   #define 	GPIO_DOUT4_CLR      (GPIO_base+0x00f0+0x08)
   #if !defined(DRV_GPIO_REG_AS_6223)
      #define 	GPO_DOUT_CLR        (GPIO_base+0x0140+0x08)   
   #endif /* DRV_GPIO_REG_AS_6223 */
   #define 	GPIO_MODE1_CLR      (GPIO_base+0x0150+0x08)       
   #define 	GPIO_MODE2_CLR      (GPIO_base+0x0160+0x08)       
   #define 	GPIO_MODE3_CLR      (GPIO_base+0x0170+0x08)       
   #define 	GPIO_MODE4_CLR      (GPIO_base+0x0180+0x08)       
   #define 	GPIO_MODE5_CLR      (GPIO_base+0x0190+0x08)       
   #define 	GPIO_MODE6_CLR      (GPIO_base+0x01a0+0x08)       
   #define 	GPIO_MODE7_CLR      (GPIO_base+0x01b0+0x08)
   #if defined(DRV_GPIO_REG_AS_6223)
      #define 	GPIO_BANK_CLR       	(GPIO_base+0x01c0+0x08)   
      #define  CLKO_MODE1_CLR      	(GPIO_base+0x0200+0x08)   
      #define  CLKO_MODE2_CLR      	(GPIO_base+0x0210+0x08)   
      #define  CLKO_MODE3_CLR      	(GPIO_base+0x0220+0x08)   
      #define  CLKO_MODE4_CLR      	(GPIO_base+0x0230+0x08)   
      #define  CLKO_MODE5_CLR      	(GPIO_base+0x0240+0x08)   
      #define  CLKO_MODE6_CLR      	(GPIO_base+0x0250+0x08) 
   #else /* DRV_GPIO_REG_AS_6223 */
      #define 	GPO_MODE_CLR        (GPIO_base+0x01c0+0x08)   
   #endif /* DRV_GPIO_REG_AS_6223 */
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x10*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x10*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x10*(_no)))
   #define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN1_CLR+(0x10*(_no)))  
   #if defined(DRV_GPIO_REG_AS_6223)
      #define  CLKO_MODE_CLR(_no)  (CLKO_MODE1_CLR+(0x10*(_no)))  
   #endif /* DRV_GPIO_REG_AS_6223 */
   
   #define  GPIO_MODE(_no)      (GPIO_MODE1+(0x10*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x10*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x10*(_no)))
   #if defined(DRV_GPIO_REG_AS_6223)
      #define  CLKO_MODE(_no)      (CLKO_MODE1+(0x10*(_no)))  
      #define  CLKO_NUM            6
   #endif /* DRV_GPIO_REG_AS_6223 */
#endif   /*DRV_GPIO_REG_AS_6219, DRV_GPIO_REG_AS_6225*/

#if defined(DRV_GPIO_REG_AS_6227)
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   	   (GPIO_base+0x0010)
   #define 	GPIO_DIR3         (GPIO_base+0x0020)
   #define 	GPIO_DIR4         (GPIO_base+0x0030)
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0040)
   #define 	GPIO_PULLEN2    	(GPIO_base+0x0050)
   #define 	GPIO_PULLEN3   	(GPIO_base+0x0060)
   #define 	GPIO_PULLEN4      (GPIO_base+0x0070)
   #define 	GPIO_DINV1      	(GPIO_base+0x0080)
   #define 	GPIO_DINV2      	(GPIO_base+0x0090)
   #define 	GPIO_DINV3      	(GPIO_base+0x00a0)
   #define 	GPIO_DINV4      	(GPIO_base+0x00b0)
   #define 	GPIO_DOUT1      	(GPIO_base+0x00c0)
   #define 	GPIO_DOUT2      	(GPIO_base+0x00d0)
   #define 	GPIO_DOUT3      	(GPIO_base+0x00e0)
   #define 	GPIO_DOUT4      	(GPIO_base+0x00f0)
   #define 	GPIO_DIN1       	(GPIO_base+0x0100)
   #define 	GPIO_DIN2       	(GPIO_base+0x0110)
   #define 	GPIO_DIN3       	(GPIO_base+0x0120)
   #define 	GPIO_DIN4       	(GPIO_base+0x0130)
   #define 	GPO_DOUT       	(GPIO_base+0x0140)
   #define 	GPIO_MODE1       	(GPIO_base+0x0150)
   #define 	GPIO_MODE2       	(GPIO_base+0x0160)
   #define 	GPIO_MODE3       	(GPIO_base+0x0170)         
   #define 	GPIO_MODE4       	(GPIO_base+0x0180)         
   #define 	GPIO_MODE5       	(GPIO_base+0x0190)         
   #define 	GPIO_MODE6       	(GPIO_base+0x01a0)         
   #define 	GPIO_MODE7       	(GPIO_base+0x01b0)         
   #define 	GPIO_MODE8       	(GPIO_base+0x01d0)         
   #define 	GPO_MODE       	(GPIO_base+0x01c0)         
   #define  GPIO_DINV_ADRS(n)	(GPIO_DINV1+0x10*(n))  
   
   #define 	GPIO_DIR1_SET       (GPIO_base+0x0000+0x04)  
   #define 	GPIO_DIR2_SET    	  (GPIO_base+0x0010+0x04)        
   #define 	GPIO_DIR3_SET       (GPIO_base+0x0020+0x04)      
   #define 	GPIO_DIR4_SET       (GPIO_base+0x0030+0x04)  
   #define 	GPIO_PULLEN1_SET    (GPIO_base+0x0040+0x04)      
   #define 	GPIO_PULLEN2_SET    (GPIO_base+0x0050+0x04)      
   #define 	GPIO_PULLEN3_SET    (GPIO_base+0x0060+0x04)     
   #define 	GPIO_PULLEN4_SET    (GPIO_base+0x0070+0x04)  
   #define 	GPIO_DOUT1_SET      (GPIO_base+0x00c0+0x04)      
   #define 	GPIO_DOUT2_SET      (GPIO_base+0x00d0+0x04)      
   #define 	GPIO_DOUT3_SET      (GPIO_base+0x00e0+0x04)      
   #define 	GPIO_DOUT4_SET      (GPIO_base+0x00f0+0x04)  
   #define 	GPO_DOUT_SET        (GPIO_base+0x0140+0x04)     
   #define 	GPIO_MODE1_SET      (GPIO_base+0x0150+0x04)      
   #define 	GPIO_MODE2_SET      (GPIO_base+0x0160+0x04)      
   #define 	GPIO_MODE3_SET      (GPIO_base+0x0170+0x04)      
   #define 	GPIO_MODE4_SET      (GPIO_base+0x0180+0x04)      
   #define 	GPIO_MODE5_SET      (GPIO_base+0x0190+0x04)      
   #define 	GPIO_MODE6_SET      (GPIO_base+0x01a0+0x04)      
   #define 	GPIO_MODE7_SET      (GPIO_base+0x01b0+0x04)  
   #define 	GPIO_MODE8_SET      (GPIO_base+0x01d0+0x04)
   #define 	GPO_MODE_SET        (GPIO_base+0x01c0+0x04)       
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x10*(_no)))  
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x10*(_no)))   
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x10*(_no)))  
   #define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x10*(_no)))  
                                                               
   #define 	GPIO_DIR1_CLR       (GPIO_base+0x0000+0x08)         
   #define 	GPIO_DIR2_CLR   	  (GPIO_base+0x0010+0x08)        
   #define 	GPIO_DIR3_CLR       (GPIO_base+0x0020+0x08)       
   #define 	GPIO_DIR4_CLR       (GPIO_base+0x0030+0x08)  
   #define 	GPIO_PULLEN1_CLR    (GPIO_base+0x0040+0x08)       
   #define 	GPIO_PULLEN2_CLR    (GPIO_base+0x0050+0x08)       
   #define 	GPIO_PULLEN3_CLR    (GPIO_base+0x0060+0x08)   
   #define 	GPIO_PULLEN4_CLR    (GPIO_base+0x0070+0x08)
   #define 	GPIO_DOUT1_CLR      (GPIO_base+0x00c0+0x08)       
   #define 	GPIO_DOUT2_CLR      (GPIO_base+0x00d0+0x08)       
   #define 	GPIO_DOUT3_CLR      (GPIO_base+0x00e0+0x08)       
   #define 	GPIO_DOUT4_CLR      (GPIO_base+0x00f0+0x08)
   #define 	GPO_DOUT_CLR        (GPIO_base+0x0140+0x08)   
   #define 	GPIO_MODE1_CLR      (GPIO_base+0x0150+0x08)       
   #define 	GPIO_MODE2_CLR      (GPIO_base+0x0160+0x08)       
   #define 	GPIO_MODE3_CLR      (GPIO_base+0x0170+0x08)       
   #define 	GPIO_MODE4_CLR      (GPIO_base+0x0180+0x08)       
   #define 	GPIO_MODE5_CLR      (GPIO_base+0x0190+0x08)       
   #define 	GPIO_MODE6_CLR      (GPIO_base+0x01a0+0x08)       
   #define 	GPIO_MODE7_CLR      (GPIO_base+0x01b0+0x08)
   #define 	GPIO_MODE8_CLR      (GPIO_base+0x01d0+0x08)
   #define 	GPO_MODE_CLR        (GPIO_base+0x01c0+0x08)   
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x10*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x10*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x10*(_no)))
   #define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN1_CLR+(0x10*(_no)))  
   
   #define  GPIO_MODE(_no)      (GPIO_MODE1+(0x10*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x10*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x10*(_no)))
   #define  GPIO_DIN(_no)       (GPIO_DIN1+(0x10*(_no)))
   
#endif   /*DRV_GPIO_REG_AS_6227*/


#if defined(DRV_GPIO_REG_AS_6228)
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   	   (GPIO_base+0x0010)
   #define 	GPIO_DIR3         (GPIO_base+0x0020)
   #define 	GPIO_DIR4         (GPIO_base+0x0030)
   #define 	GPIO_DIR5         (GPIO_base+0x0040)      
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0050)
   #define 	GPIO_PULLEN2    	(GPIO_base+0x0060)
   #define 	GPIO_PULLEN3   	(GPIO_base+0x0070)
   #define 	GPIO_PULLEN4      (GPIO_base+0x0080)
   #define 	GPIO_PULLEN5      (GPIO_base+0x0090)   
   #define 	GPIO_DINV1      	(GPIO_base+0x00a0)
   #define 	GPIO_DINV2      	(GPIO_base+0x00b0)
   #define 	GPIO_DINV3      	(GPIO_base+0x00c0)
   #define 	GPIO_DINV4      	(GPIO_base+0x00d0)
   #define 	GPIO_DINV5      	(GPIO_base+0x00e0)   
   #define 	GPIO_DOUT1      	(GPIO_base+0x00f0)
   #define 	GPIO_DOUT2      	(GPIO_base+0x0100)
   #define 	GPIO_DOUT3      	(GPIO_base+0x0110)
   #define 	GPIO_DOUT4      	(GPIO_base+0x0120)
   #define 	GPIO_DOUT5      	(GPIO_base+0x0130)   
   #define 	GPIO_DIN1       	(GPIO_base+0x0140)
   #define 	GPIO_DIN2       	(GPIO_base+0x0150)
   #define 	GPIO_DIN3       	(GPIO_base+0x0160)
   #define 	GPIO_DIN4       	(GPIO_base+0x0170)
   #define 	GPIO_DIN5       	(GPIO_base+0x0180)   
   #define 	GPO_DOUT       	(GPIO_base+0x0190)   
   #define 	GPIO_MODE1       	(GPIO_base+0x01a0)
   #define 	GPIO_MODE2       	(GPIO_base+0x01b0)
   #define 	GPIO_MODE3       	(GPIO_base+0x01c0)         
   #define 	GPIO_MODE4       	(GPIO_base+0x01d0)         
   #define 	GPIO_MODE5       	(GPIO_base+0x01e0)         
   #define 	GPIO_MODE6       	(GPIO_base+0x01f0)         
   #define 	GPIO_MODE7       	(GPIO_base+0x0200)
   #define 	GPIO_MODE8       	(GPIO_base+0x0210)
   #define 	GPIO_MODE9       	(GPIO_base+0x0220)
   #define 	GPIO_MODE10       (GPIO_base+0x0230)   
   #define 	GPO_MODE       	(GPIO_base+0x0240)         
   #define  GPIO_DINV_ADRS(n)	(GPIO_DINV1+0x10*(n))  
   
   #define 	GPIO_DIR1_SET       (GPIO_base+0x0000+0x04)    
   #define 	GPIO_DIR2_SET    	  (GPIO_base+0x0010+0x04)        
   #define 	GPIO_DIR3_SET       (GPIO_base+0x0020+0x04)      
   #define 	GPIO_DIR4_SET       (GPIO_base+0x0030+0x04)    
   #define 	GPIO_DIR5_SET       (GPIO_base+0x0040+0x04)    
   #define 	GPIO_PULLEN1_SET    (GPIO_base+0x0050+0x04)      
   #define 	GPIO_PULLEN2_SET    (GPIO_base+0x0060+0x04)      
   #define 	GPIO_PULLEN3_SET    (GPIO_base+0x0070+0x04)     
   #define 	GPIO_PULLEN4_SET    (GPIO_base+0x0080+0x04)    
   #define 	GPIO_PULLEN5_SET    (GPIO_base+0x0090+0x04)    
   #define 	GPIO_DOUT1_SET      (GPIO_base+0x00f0+0x04)    
   #define 	GPIO_DOUT2_SET      (GPIO_base+0x0100+0x04)    
   #define 	GPIO_DOUT3_SET      (GPIO_base+0x0110+0x04)    
   #define 	GPIO_DOUT4_SET      (GPIO_base+0x0120+0x04)    
   #define 	GPIO_DOUT5_SET      (GPIO_base+0x0130+0x04)    
   #define 	GPO_DOUT_SET        (GPIO_base+0x0190+0x04)     
   #define 	GPIO_MODE1_SET      (GPIO_base+0x01a0+0x04)        
   #define 	GPIO_MODE2_SET      (GPIO_base+0x01b0+0x04)    
   #define 	GPIO_MODE3_SET      (GPIO_base+0x01c0+0x04)       
   #define 	GPIO_MODE4_SET      (GPIO_base+0x01d0+0x04)    
   #define 	GPIO_MODE5_SET      (GPIO_base+0x01e0+0x04)        
   #define 	GPIO_MODE6_SET      (GPIO_base+0x01f0+0x04)        
   #define 	GPIO_MODE7_SET      (GPIO_base+0x0200+0x04)      
   #define 	GPIO_MODE8_SET      (GPIO_base+0x0210+0x04)        
   #define 	GPIO_MODE9_SET      (GPIO_base+0x0220+0x04)      
   #define 	GPIO_MODE10_SET     (GPIO_base+0x0230+0x04)     
   #define 	GPO_MODE_SET        (GPIO_base+0x0240+0x04)       
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x10*(_no)))
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x10*(_no)))  
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x10*(_no)))  
   #define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x10*(_no)))  
                                                             
   #define 	GPIO_DIR1_CLR       (GPIO_base+0x0000+0x08)         
   #define 	GPIO_DIR2_CLR   	  (GPIO_base+0x0010+0x08)         
   #define 	GPIO_DIR3_CLR       (GPIO_base+0x0020+0x08)         
   #define 	GPIO_DIR4_CLR       (GPIO_base+0x0030+0x08)         
   #define 	GPIO_DIR5_CLR       (GPIO_base+0x0040+0x08)         
   #define 	GPIO_PULLEN1_CLR    (GPIO_base+0x0050+0x08)         
   #define 	GPIO_PULLEN2_CLR    (GPIO_base+0x0060+0x08)         
   #define 	GPIO_PULLEN3_CLR    (GPIO_base+0x0070+0x08)         
   #define 	GPIO_PULLEN4_CLR    (GPIO_base+0x0080+0x08)         
   #define 	GPIO_PULLEN5_CLR    (GPIO_base+0x0090+0x08)         
   #define 	GPIO_DOUT1_CLR      (GPIO_base+0x00f0+0x08)         
   #define 	GPIO_DOUT2_CLR      (GPIO_base+0x0100+0x08)         
   #define 	GPIO_DOUT3_CLR      (GPIO_base+0x0110+0x08)         
   #define 	GPIO_DOUT4_CLR      (GPIO_base+0x0120+0x08)         
   #define 	GPIO_DOUT5_CLR      (GPIO_base+0x0130+0x08)         
   #define 	GPO_DOUT_CLR        (GPIO_base+0x0190+0x08)         
   #define 	GPIO_MODE1_CLR      (GPIO_base+0x01a0+0x08)         
   #define 	GPIO_MODE2_CLR      (GPIO_base+0x01b0+0x08)         
   #define 	GPIO_MODE3_CLR      (GPIO_base+0x01c0+0x08)         
   #define 	GPIO_MODE4_CLR      (GPIO_base+0x01d0+0x08)         
   #define 	GPIO_MODE5_CLR      (GPIO_base+0x01e0+0x08)         
   #define 	GPIO_MODE6_CLR      (GPIO_base+0x01f0+0x08)         
   #define 	GPIO_MODE7_CLR      (GPIO_base+0x0200+0x08)         
   #define 	GPIO_MODE8_CLR      (GPIO_base+0x0210+0x08)         
   #define 	GPIO_MODE9_CLR      (GPIO_base+0x0220+0x08)         
   #define 	GPIO_MODE10_CLR     (GPIO_base+0x0230+0x08)          
   #define 	GPO_MODE_CLR        (GPIO_base+0x0240+0x08)         
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x10*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x10*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x10*(_no)))
   #define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN1_CLR+(0x10*(_no)))  
   
   #define  GPIO_MODE(_no)      (GPIO_MODE1+(0x10*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x10*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x10*(_no)))
   #define  GPIO_DIN(_no)       (GPIO_DIN1+(0x10*(_no)))
#endif   /*DRV_GPIO_REG_AS_6228*/

#if defined(DRV_GPIO_REG_AS_6268T) 
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   	   (GPIO_base+0x0010)
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0050)
   #define 	GPIO_PULLEN2    	(GPIO_base+0x0060)
   #define 	GPIO_DINV1      	(GPIO_base+0x00a0)
   #define 	GPIO_DINV2      	(GPIO_base+0x00b0)
   #define 	GPIO_DOUT1      	(GPIO_base+0x00f0)
   #define 	GPIO_DOUT2      	(GPIO_base+0x0100)
   #define 	GPIO_DIN1       	(GPIO_base+0x0140)
   #define 	GPIO_DIN2       	(GPIO_base+0x0150)
   #define 	GPIO_MODE1       	(GPIO_base+0x01a0)
   #define 	GPIO_MODE2       	(GPIO_base+0x01b0)
   #define 	GPIO_MODE3       	(GPIO_base+0x01c0)         
   #define 	GPIO_MODE4       	(GPIO_base+0x01d0)         
   #define  GPIO_DINV_ADRS(n)	(GPIO_DINV1+0x10*(n))  
   
   #define 	GPIO_DIR1_SET       (GPIO_base+0x0000+0x04)    
   #define 	GPIO_DIR2_SET    	  (GPIO_base+0x0010+0x04)        
   #define 	GPIO_PULLEN1_SET    (GPIO_base+0x0050+0x04)      
   #define 	GPIO_PULLEN2_SET    (GPIO_base+0x0060+0x04)      
   #define 	GPIO_DOUT1_SET      (GPIO_base+0x00f0+0x04)    
   #define 	GPIO_DOUT2_SET      (GPIO_base+0x0100+0x04)    
   #define 	GPIO_MODE1_SET      (GPIO_base+0x01a0+0x04)        
   #define 	GPIO_MODE2_SET      (GPIO_base+0x01b0+0x04)    
   #define 	GPIO_MODE3_SET      (GPIO_base+0x01c0+0x04)       
   #define 	GPIO_MODE4_SET      (GPIO_base+0x01d0+0x04)    
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x10*(_no)))
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x10*(_no)))  
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x10*(_no)))  
   #define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x10*(_no)))  
                                                             
   #define 	GPIO_DIR1_CLR       (GPIO_base+0x0000+0x08)         
   #define 	GPIO_DIR2_CLR   	  (GPIO_base+0x0010+0x08)         
   #define 	GPIO_PULLEN1_CLR    (GPIO_base+0x0050+0x08)         
   #define 	GPIO_PULLEN2_CLR    (GPIO_base+0x0060+0x08)         
   #define 	GPIO_DOUT1_CLR      (GPIO_base+0x00f0+0x08)         
   #define 	GPIO_DOUT2_CLR      (GPIO_base+0x0100+0x08)         
   #define 	GPIO_MODE1_CLR      (GPIO_base+0x01a0+0x08)         
   #define 	GPIO_MODE2_CLR      (GPIO_base+0x01b0+0x08)         
   #define 	GPIO_MODE3_CLR      (GPIO_base+0x01c0+0x08)         
   #define 	GPIO_MODE4_CLR      (GPIO_base+0x01d0+0x08)         
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x10*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x10*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x10*(_no)))
   #define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN1_CLR+(0x10*(_no)))  
   
   #define  GPIO_MODE(_no)      (GPIO_MODE1+(0x10*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x10*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x10*(_no)))
   #define  GPIO_DIN(_no)       (GPIO_DIN1+(0x10*(_no)))
#endif   /*DRV_GPIO_REG_AS_6268T*/

#if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6270A) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   	   (GPIO_base+0x0040)
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_DIR3         (GPIO_base+0x0080)
   #define 	GPIO_DIR4         (GPIO_base+0x00c0)
   #define 	GPIO_DIR5         (GPIO_base+0x0100)      
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DIR6         (GPIO_base+0x0140)      
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DIR7         (GPIO_base+0x0180)      
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0200)
   #define 	GPIO_PULLEN2    	(GPIO_base+0x0240)
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_PULLEN3   	(GPIO_base+0x0280)
   #define 	GPIO_PULLEN4      (GPIO_base+0x02c0)
   #define 	GPIO_PULLEN5      (GPIO_base+0x0300)   
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_PULLEN6      (GPIO_base+0x0340)   
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_PULLEN7      (GPIO_base+0x0380)
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_PULLSEL1    	(GPIO_base+0x0400)
   #define 	GPIO_PULLSEL2    	(GPIO_base+0x0440)
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_PULLSEL3   	(GPIO_base+0x0480)
   #define 	GPIO_PULLSEL4     (GPIO_base+0x04c0)
   #define 	GPIO_PULLSEL5     (GPIO_base+0x0500)   
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_PULLSEL6     (GPIO_base+0x0540)   
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_PULLSEL7     (GPIO_base+0x0580)
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_DINV1      	(GPIO_base+0x0600)
   #define 	GPIO_DINV2      	(GPIO_base+0x0640)
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_DINV3      	(GPIO_base+0x0680)
   #define 	GPIO_DINV4      	(GPIO_base+0x06c0)
   #define 	GPIO_DINV5      	(GPIO_base+0x0700)   
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DINV6      	(GPIO_base+0x0740)   
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DINV7      	(GPIO_base+0x0780)   
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_DOUT1      	(GPIO_base+0x0800)
   #define 	GPIO_DOUT2      	(GPIO_base+0x0840)
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_DOUT3      	(GPIO_base+0x0880)
   #define 	GPIO_DOUT4      	(GPIO_base+0x08c0)
   #define 	GPIO_DOUT5      	(GPIO_base+0x0900)   
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DOUT6      	(GPIO_base+0x0940)   
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DOUT7      	(GPIO_base+0x0980)   
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_DIN1       	(GPIO_base+0x0a00)
   #define 	GPIO_DIN2       	(GPIO_base+0x0a40)
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_DIN3       	(GPIO_base+0x0a80)
   #define 	GPIO_DIN4       	(GPIO_base+0x0ac0)
   #define 	GPIO_DIN5       	(GPIO_base+0x0b00)   
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DIN6       	(GPIO_base+0x0b40)   
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DIN7       	(GPIO_base+0x0b80)   
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #if defined(MT6276_S01)
   #define GPIO_MODE0			(GPIO_base+0x1000)
   #define GPIO_MODE1			(GPIO_base+0x1100)
   #define GPIO_MODE2			(GPIO_base+0x1200)
   #define GPIO_MODE3			(GPIO_base+0x1300)
   #define GPIO_MODE4			(GPIO_base+0x1400)
   #define GPIO_MODE5			(GPIO_base+0x1500)
   #define GPIO_MODE6			(GPIO_base+0x1600)
   #define GPIO_MODE7			(GPIO_base+0x1700)
   #define GPIO_MODE8			(GPIO_base+0x1800)
   #define GPIO_MODE9			(GPIO_base+0x1900)
   #define GPIO_MODEA			(GPIO_base+0x1A00)
   #define GPIO_MODEB			(GPIO_base+0x1B00)
   #define GPIO_MODEC			(GPIO_base+0x1C00)
   #define GPIO_MODED			(GPIO_base+0x1D00)
   #define GPIO_MODEE			(GPIO_base+0x1E00)
   #define GPIO_MODEF			(GPIO_base+0x1F00)
   #define GPIO_MODE10			(GPIO_base+0x2000)
   #define GPIO_MODE11			(GPIO_base+0x2100)
   #define GPIO_MODE12			(GPIO_base+0x2200)
   #define GPIO_MODE13			(GPIO_base+0x2300)
   #define GPIO_MODE14			(GPIO_base+0x2400)
   #define GPIO_MODE15			(GPIO_base+0x2500)
   #define GPIO_MODE16			(GPIO_base+0x2600)
   #else	//define(MT6276_S01)
   #define 	GPIO_MODE1       	(GPIO_base+0x1000)
   #define 	GPIO_MODE2       	(GPIO_base+0x1100)
   #define 	GPIO_MODE3       	(GPIO_base+0x1200)         
   #define 	GPIO_MODE4       	(GPIO_base+0x1300)         
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_MODE5       	(GPIO_base+0x1400)         
   #define 	GPIO_MODE6       	(GPIO_base+0x1500)         
   #define 	GPIO_MODE7       	(GPIO_base+0x1600)
   #define 	GPIO_MODE8       	(GPIO_base+0x1700)
   #define 	GPIO_MODE9       	(GPIO_base+0x1800)
   #define 	GPIO_MODEA        (GPIO_base+0x1900)   
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_MODEB        (GPIO_base+0x1a00)   
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_MODEC        (GPIO_base+0x1b00)   
   #define 	GPIO_MODED        (GPIO_base+0x1c00)   
   #if defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_MODEE        (GPIO_base+0x1d00)   
   #endif //defined(DRV_GPIO_REG_AS_6276)
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #endif //define(MT6276_S01)	   
   #define  CLKO_MODE1      	(GPIO_base+0x3000)
   #define  CLKO_MODE2      	(GPIO_base+0x3100)   
   #define  CLKO_MODE3      	(GPIO_base+0x3200)   
   #define  CLKO_MODE4      	(GPIO_base+0x3300)   
   #define  CLKO_MODE5      	(GPIO_base+0x3400)   
#if !defined(DRV_GPIO_REG_AS_6270A)
   #define  CLKO_MODE6      	(GPIO_base+0x3500)   
#if !defined(DRV_GPIO_REG_AS_6268A) && !defined(DRV_GPIO_REG_AS_6268) && !defined(DRV_GPIO_REG_AS_6276)
   #define  CLKO_MODE7      	(GPIO_base+0x3600)   
   #define  CLKO_MODE8      	(GPIO_base+0x3700)   
   #if defined(DRV_GPIO_REG_AS_6235)
   #define  CLKO_MODE9      	(GPIO_base+0x3800)
   #define  CLKO_MODEA      	(GPIO_base+0x3900)   
   #endif /* DRV_GPIO_REG_AS_6235 */
   #if defined(DRV_GPIO_REG_AS_6238)
   #define  GPIO_TM        	(GPIO_base+0x4000)   
   #endif /* DRV_GPIO_REG_AS_6238 */
#endif /* !defined(DRV_GPIO_REG_AS_6268A) */
#endif //!defined(DRV_GPIO_REG_AS_6270A)
   #define  GPIO_DINV_ADRS(n)	(GPIO_DINV1+0x40*(n))  
   
   #define 	GPIO_DIR1_SET       (GPIO_base+0x0000+0x04)    
   #define 	GPIO_DIR2_SET    	  (GPIO_base+0x0040+0x04)        
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_DIR3_SET       (GPIO_base+0x0080+0x04)      
   #define 	GPIO_DIR4_SET       (GPIO_base+0x00c0+0x04)    
   #define 	GPIO_DIR5_SET       (GPIO_base+0x0100+0x04)    
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DIR6_SET       (GPIO_base+0x0140+0x04)    
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DIR7_SET       (GPIO_base+0x0180+0x04)    
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_PULLEN1_SET    (GPIO_base+0x0200+0x04)      
   #define 	GPIO_PULLEN2_SET    (GPIO_base+0x0240+0x04)      
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_PULLEN3_SET    (GPIO_base+0x0280+0x04)     
   #define 	GPIO_PULLEN4_SET    (GPIO_base+0x02c0+0x04)    
   #define 	GPIO_PULLEN5_SET    (GPIO_base+0x0300+0x04)    
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_PULLEN6_SET    (GPIO_base+0x0340+0x04)    
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_PULLEN7_SET    (GPIO_base+0x0380+0x04)    
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_PULLSEL1_SET   (GPIO_base+0x0400+0x04)      
   #define 	GPIO_PULLSEL2_SET   (GPIO_base+0x0440+0x04)      
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_PULLSEL3_SET   (GPIO_base+0x0480+0x04)     
   #define 	GPIO_PULLSEL4_SET   (GPIO_base+0x04c0+0x04)    
   #define 	GPIO_PULLSEL5_SET   (GPIO_base+0x0500+0x04)    
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_PULLSEL6_SET   (GPIO_base+0x0540+0x04)    
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_PULLSEL7_SET   (GPIO_base+0x0580+0x04)    
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_DOUT1_SET      (GPIO_base+0x0800+0x04)    
   #define 	GPIO_DOUT2_SET      (GPIO_base+0x0840+0x04)    
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_DOUT3_SET      (GPIO_base+0x0880+0x04)    
   #define 	GPIO_DOUT4_SET      (GPIO_base+0x08c0+0x04)    
   #define 	GPIO_DOUT5_SET      (GPIO_base+0x0900+0x04)    
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DOUT6_SET      (GPIO_base+0x0940+0x04)    
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DOUT7_SET      (GPIO_base+0x0980+0x04)    
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #if defined(MT6276_S01)
     #define GPIO_MODE0_SET		(GPIO_base+0x1000+0x04)
     #define GPIO_MODE1_SET		(GPIO_base+0x1100+0x04)
     #define GPIO_MODE2_SET		(GPIO_base+0x1200+0x04)
     #define GPIO_MODE3_SET		(GPIO_base+0x1300+0x04)
     #define GPIO_MODE4_SET		(GPIO_base+0x1400+0x04)
     #define GPIO_MODE5_SET		(GPIO_base+0x1500+0x04)
     #define GPIO_MODE6_SET		(GPIO_base+0x1600+0x04)
     #define GPIO_MODE7_SET		(GPIO_base+0x1700+0x04)
     #define GPIO_MODE8_SET		(GPIO_base+0x1800+0x04)
     #define GPIO_MODE9_SET		(GPIO_base+0x1900+0x04)
     #define GPIO_MODEA_SET		(GPIO_base+0x1A00+0x04)
     #define GPIO_MODEB_SET		(GPIO_base+0x1B00+0x04)
     #define GPIO_MODEC_SET		(GPIO_base+0x1C00+0x04)
     #define GPIO_MODED_SET		(GPIO_base+0x1D00+0x04)
     #define GPIO_MODEE_SET		(GPIO_base+0x1E00+0x04)
     #define GPIO_MODEF_SET		(GPIO_base+0x1F00+0x04)
     #define GPIO_MODE10_SET 		(GPIO_base+0x2000+0x04)
     #define GPIO_MODE11_SET 		(GPIO_base+0x2100+0x04)
     #define GPIO_MODE12_SET 		(GPIO_base+0x2200+0x04)
     #define GPIO_MODE13_SET 		(GPIO_base+0x2300+0x04)
     #define GPIO_MODE14_SET 		(GPIO_base+0x2400+0x04)
     #define GPIO_MODE15_SET 		(GPIO_base+0x2500+0x04)
     #define GPIO_MODE16_SET 		(GPIO_base+0x2600+0x04)
   #else
   #define 	GPIO_MODE1_SET      (GPIO_base+0x1000+0x04)        
   #define 	GPIO_MODE2_SET      (GPIO_base+0x1100+0x04)    
   #define 	GPIO_MODE3_SET      (GPIO_base+0x1200+0x04)       
   #define 	GPIO_MODE4_SET      (GPIO_base+0x1300+0x04)    
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_MODE5_SET      (GPIO_base+0x1400+0x04)        
   #define 	GPIO_MODE6_SET      (GPIO_base+0x1500+0x04)        
   #define 	GPIO_MODE7_SET      (GPIO_base+0x1600+0x04)      
   #define 	GPIO_MODE8_SET      (GPIO_base+0x1700+0x04)        
   #define 	GPIO_MODE9_SET      (GPIO_base+0x1800+0x04)      
   #define 	GPIO_MODEA_SET      (GPIO_base+0x1900+0x04)     
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_MODEB_SET      (GPIO_base+0x1a00+0x04)     
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_MODEC_SET      (GPIO_base+0x1b00+0x04)     
   #define 	GPIO_MODED_SET      (GPIO_base+0x1c00+0x04)     
   #if  defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_MODEE_SET      (GPIO_base+0x1d00+0x04)     
   #endif
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #endif //define(MT6276_S01)
   
   #if defined(MT6276_S01) 
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE0_SET+(0x100*(_no)))
   #else
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x100*(_no)))
   #endif
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x40*(_no)))  
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x40*(_no)))  
   #define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x40*(_no)))  
   #define  GPIO_PULLSEL_SET(_no)  (GPIO_PULLSEL1_SET+(0x40*(_no)))  
                                                             
   #define 	GPIO_DIR1_CLR       (GPIO_base+0x0000+0x08)         
   #define 	GPIO_DIR2_CLR   	  (GPIO_base+0x0040+0x08)         
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_DIR3_CLR       (GPIO_base+0x0080+0x08)         
   #define 	GPIO_DIR4_CLR       (GPIO_base+0x00c0+0x08)         
   #define 	GPIO_DIR5_CLR       (GPIO_base+0x0100+0x08)         
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DIR6_CLR       (GPIO_base+0x0140+0x08)         
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DIR7_CLR       (GPIO_base+0x0180+0x08)         
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_PULLEN1_CLR    (GPIO_base+0x0200+0x08)         
   #define 	GPIO_PULLEN2_CLR    (GPIO_base+0x0240+0x08)         
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_PULLEN3_CLR    (GPIO_base+0x0280+0x08)         
   #define 	GPIO_PULLEN4_CLR    (GPIO_base+0x02c0+0x08)         
   #define 	GPIO_PULLEN5_CLR    (GPIO_base+0x0300+0x08)         
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_PULLEN6_CLR    (GPIO_base+0x0340+0x08)         
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_PULLEN7_CLR    (GPIO_base+0x0380+0x08)         
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_PULLSEL1_CLR   (GPIO_base+0x0400+0x08)         
   #define 	GPIO_PULLSEL2_CLR   (GPIO_base+0x0440+0x08)         
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_PULLSEL3_CLR   (GPIO_base+0x0480+0x08)         
   #define 	GPIO_PULLSEL4_CLR   (GPIO_base+0x04c0+0x08)         
   #define 	GPIO_PULLSEL5_CLR   (GPIO_base+0x0500+0x08)         
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_PULLSEL6_CLR   (GPIO_base+0x0540+0x08)         
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_PULLSEL7_CLR   (GPIO_base+0x0580+0x08)         
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_DOUT1_CLR      (GPIO_base+0x0800+0x08)         
   #define 	GPIO_DOUT2_CLR      (GPIO_base+0x0840+0x08)         
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_DOUT3_CLR      (GPIO_base+0x0880+0x08)         
   #define 	GPIO_DOUT4_CLR      (GPIO_base+0x08c0+0x08)         
   #define 	GPIO_DOUT5_CLR      (GPIO_base+0x0900+0x08)         
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DOUT6_CLR      (GPIO_base+0x0940+0x08)         
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_DOUT7_CLR      (GPIO_base+0x0980+0x08)         
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #if defined(MT6276_S01)  
     #define GPIO_MODE0_CLR		 (GPIO_base+0x1000+0x08)
     #define GPIO_MODE1_CLR		 (GPIO_base+0x1100+0x08)
     #define GPIO_MODE2_CLR		 (GPIO_base+0x1200+0x08)
     #define GPIO_MODE3_CLR		 (GPIO_base+0x1300+0x08)
     #define GPIO_MODE4_CLR		 (GPIO_base+0x1400+0x08)
     #define GPIO_MODE5_CLR		 (GPIO_base+0x1500+0x08)
     #define GPIO_MODE6_CLR		 (GPIO_base+0x1600+0x08)
     #define GPIO_MODE7_CLR		 (GPIO_base+0x1700+0x08)
     #define GPIO_MODE8_CLR		 (GPIO_base+0x1800+0x08)
     #define GPIO_MODE9_CLR		 (GPIO_base+0x1900+0x08)
     #define GPIO_MODEA_CLR		 (GPIO_base+0x1A00+0x08)
     #define GPIO_MODEB_CLR		 (GPIO_base+0x1B00+0x08)
     #define GPIO_MODEC_CLR		 (GPIO_base+0x1C00+0x08)
     #define GPIO_MODED_CLR		 (GPIO_base+0x1D00+0x08)
     #define GPIO_MODEE_CLR		 (GPIO_base+0x1E00+0x08)
     #define GPIO_MODEF_CLR		 (GPIO_base+0x1F00+0x08)
     #define GPIO_MODE10_CLR 		 (GPIO_base+0x2000+0x08)
     #define GPIO_MODE11_CLR 		 (GPIO_base+0x2100+0x08)
     #define GPIO_MODE12_CLR 		 (GPIO_base+0x2200+0x08)
     #define GPIO_MODE13_CLR 		 (GPIO_base+0x2300+0x08)
     #define GPIO_MODE14_CLR 		 (GPIO_base+0x2400+0x08)
     #define GPIO_MODE15_CLR 		 (GPIO_base+0x2500+0x08)
     #define GPIO_MODE16_CLR 		 (GPIO_base+0x2600+0x08)   
   #else	
   #define 	GPIO_MODE1_CLR      (GPIO_base+0x1000+0x08)         
   #define 	GPIO_MODE2_CLR      (GPIO_base+0x1100+0x08)         
   #define 	GPIO_MODE3_CLR      (GPIO_base+0x1200+0x08)         
   #define 	GPIO_MODE4_CLR      (GPIO_base+0x1300+0x08)         
   #if !defined(DRV_GPIO_REG_AS_6270A)
   #define 	GPIO_MODE5_CLR      (GPIO_base+0x1400+0x08)         
   #define 	GPIO_MODE6_CLR      (GPIO_base+0x1500+0x08)         
   #define 	GPIO_MODE7_CLR      (GPIO_base+0x1600+0x08)         
   #define 	GPIO_MODE8_CLR      (GPIO_base+0x1700+0x08)         
   #define 	GPIO_MODE9_CLR      (GPIO_base+0x1800+0x08)         
   #define 	GPIO_MODEA_CLR      (GPIO_base+0x1900+0x08)          
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_MODEB_CLR      (GPIO_base+0x1a00+0x08)          
   #endif /* DRV_GPIO_REG_AS_6238 */
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_MODEC_CLR      (GPIO_base+0x1b00+0x08)          
   #define 	GPIO_MODED_CLR      (GPIO_base+0x1c00+0x08)          
   #if  defined(DRV_GPIO_REG_AS_6276)
   #define 	GPIO_MODEE_CLR      (GPIO_base+0x1d00+0x08)          
   #endif
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
   #endif //define(MT6276_S01) 

   #if defined(MT6276_S01) 
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE0_CLR+(0x100*(_no)))
   #define  GPIO_MODE(_no) 	 (GPIO_MODE0+(0x100*(_no)))	
   #else
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x100*(_no)))
   #define  GPIO_MODE(_no)      (GPIO_MODE1+(0x100*(_no)))
   #endif
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x40*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x40*(_no)))
   #define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN1_CLR+(0x40*(_no)))  
   #define  GPIO_PULLSEL_CLR(_no)  (GPIO_PULLSEL1_CLR+(0x40*(_no)))  
   
   
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x40*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x40*(_no)))
   #define  GPIO_DIN(_no)       (GPIO_DIN1+(0x40*(_no)))
   #define  GPIO_PULLEN(_no)    (GPIO_PULLEN1+(0x40*(_no)))
   #define  GPIO_PULLSEL(_no)   (GPIO_PULLSEL1+(0x40*(_no)))
   #define  CLKO_MODE(_no)      (CLKO_MODE1+(0x100*(_no)))  
   #if defined(DRV_GPIO_REG_AS_6238)
   #define  CLKO_NUM            8
   #elif defined(DRV_GPIO_REG_AS_6235)
   #define  CLKO_NUM            10
   #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6270A) || defined(DRV_GPIO_REG_AS_6276)
   #define  CLKO_NUM            6
   #endif
#endif   /*defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6270A) || defined(DRV_GPIO_REG_AS_6276)*/

#if defined(DRV_GPIO_REG_AS_TK6516)
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0100)
   #define 	GPIO_PULLSEL1    	(GPIO_base+0x0200)
   #define 	GPIO_DINV1      	(GPIO_base+0x0300)
   #define 	GPIO_DOUT1      	(GPIO_base+0x0400)
   #define 	GPIO_DIN1       	(GPIO_base+0x0500)
   #define 	GPIO_MODE1       	(GPIO_base+0x0600)
   #define  GPIO_DINV_ADRS(n)	(GPIO_DINV1+0x10*(n))  
   
   #define 	GPIO_DIR1_SET       (GPIO_base+0x0000+0x04)    
   #define 	GPIO_PULLEN1_SET    (GPIO_base+0x0100+0x04)      
   #define 	GPIO_PULLSEL1_SET    (GPIO_base+0x0200+0x04)      
   #define 	GPIO_DOUT1_SET      (GPIO_base+0x0400+0x04)    
   #define 	GPIO_MODE1_SET      (GPIO_base+0x0600+0x04)        
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x10*(_no)))
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x10*(_no)))  
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x10*(_no)))  
   #define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x10*(_no)))  
   #define  GPIO_PULLSEL_SET(_no)  (GPIO_PULLSEL1_SET+(0x40*(_no)))  
                                                             
   #define 	GPIO_DIR1_CLR       (GPIO_base+0x0000+0x08)         
   #define 	GPIO_PULLEN1_CLR    (GPIO_base+0x0100+0x08)         
   #define 	GPIO_PULLSEL1_CLR   (GPIO_base+0x0200+0x08)         
   #define 	GPIO_DOUT1_CLR      (GPIO_base+0x0400+0x08)         
   #define 	GPIO_MODE1_CLR      (GPIO_base+0x0600+0x08)         
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x10*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x10*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x10*(_no)))
   #define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN1_CLR+(0x10*(_no)))  
   #define  GPIO_PULLSEL_CLR(_no)  (GPIO_PULLSEL1_CLR+(0x40*(_no)))  
   
   #define  GPIO_MODE(_no)      (GPIO_MODE1+(0x10*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x10*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x10*(_no)))
   #define  GPIO_DIN(_no)       (GPIO_DIN1+(0x10*(_no)))
   #define  GPIO_PULLEN(_no)    (GPIO_PULLEN1+(0x40*(_no)))
   #define  GPIO_PULLSEL(_no)   (GPIO_PULLSEL1+(0x40*(_no)))
#endif   /*DRV_GPIO_REG_AS_TK6516*/

#if defined(DRV_GPIO_REG_AS_6253T)
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   	   (GPIO_base+0x0010)
   #define 	GPIO_DIR3         (GPIO_base+0x0020)
   #define 	GPIO_DIR4         (GPIO_base+0x0030)
   #define 	GPIO_DIR5         (GPIO_base+0x0040)      
   #define 	GPIO_DIR6         (GPIO_base+0x0380)      
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0050)
   #define 	GPIO_PULLEN2    	(GPIO_base+0x0060)
   #define 	GPIO_PULLEN3   	(GPIO_base+0x0070)
   #define 	GPIO_PULLEN4      (GPIO_base+0x0080)
   #define 	GPIO_PULLEN5      (GPIO_base+0x0090)   
   #define 	GPIO_PULLEN6      (GPIO_base+0x0390)   
   #define 	GPIO_DINV1      	(GPIO_base+0x00a0)
   #define 	GPIO_DINV2      	(GPIO_base+0x00b0)
   #define 	GPIO_DINV3      	(GPIO_base+0x00c0)
   #define 	GPIO_DINV4      	(GPIO_base+0x00d0)
   #define 	GPIO_DINV5      	(GPIO_base+0x00e0)   
   #define 	GPIO_DINV6      	(GPIO_base+0x03a0)   
   #define 	GPIO_DOUT1      	(GPIO_base+0x00f0)
   #define 	GPIO_DOUT2      	(GPIO_base+0x0100)
   #define 	GPIO_DOUT3      	(GPIO_base+0x0110)
   #define 	GPIO_DOUT4      	(GPIO_base+0x0120)
   #define 	GPIO_DOUT5      	(GPIO_base+0x0130)   
   #define 	GPIO_DOUT6      	(GPIO_base+0x03b0)   
   #define 	GPIO_DIN1       	(GPIO_base+0x0140)
   #define 	GPIO_DIN2       	(GPIO_base+0x0150)
   #define 	GPIO_DIN3       	(GPIO_base+0x0160)
   #define 	GPIO_DIN4       	(GPIO_base+0x0170)
   #define 	GPIO_DIN5       	(GPIO_base+0x0180)   
   #define 	GPIO_DIN6       	(GPIO_base+0x03c0)   
   #define 	GPIO_MODE1       	(GPIO_base+0x0190)
   #define 	GPIO_MODE2       	(GPIO_base+0x01a0)
   #define 	GPIO_MODE3       	(GPIO_base+0x01b0)
   #define 	GPIO_MODE4       	(GPIO_base+0x01c0)         
   #define 	GPIO_MODE5       	(GPIO_base+0x01d0)         
   #define 	GPIO_MODE6       	(GPIO_base+0x01e0)         
   #define 	GPIO_MODE7       	(GPIO_base+0x01f0)         
   #define 	GPIO_MODE8       	(GPIO_base+0x0200)
   #define 	GPIO_MODE9       	(GPIO_base+0x0210)
   #define 	GPIO_MODEA      	(GPIO_base+0x0220)
   #define 	GPIO_MODEB       (GPIO_base+0x03d0)   
   #define 	GPIO_BANK       	(GPIO_base+0x0230)   
   #define  CLKO_MODE1      	(GPIO_base+0x0300)   
   #define  CLKO_MODE2      	(GPIO_base+0x0310)   
   #define  CLKO_MODE3      	(GPIO_base+0x0320)   
   #define  CLKO_MODE4      	(GPIO_base+0x0330)   
   #define  CLKO_MODE5      	(GPIO_base+0x0340)   
   #define  CLKO_MODE6      	(GPIO_base+0x0350)   
   #define  CLKO_MODE7      	(GPIO_base+0x0360)   
   #define  GPIO_DINV_ADRS(n)	(((n)<5)?(GPIO_DINV1+0x10*(n)):GPIO_DINV6)  
   
   #define 	GPIO_PULLSEL1    	(GPIO_base+0x0240)
   #define 	GPIO_PULLSEL2    	(GPIO_base+0x0250)
   #define 	GPIO_PULLSEL3   	(GPIO_base+0x0260)
   #define 	GPIO_PULLSEL4     (GPIO_base+0x0270)
   #define 	GPIO_PULLSEL5     (GPIO_base+0x0280)   
   #define 	GPIO_PULLSEL6     (GPIO_base+0x03e0)   
   #define  GPIO_TM        	(GPIO_base+0x0370)   

   #define 	GPIO_DIR1_SET       	(GPIO_base+0x0000+0x04)
   #define 	GPIO_DIR2_SET   	   (GPIO_base+0x0010+0x04)
   #define 	GPIO_DIR3_SET         (GPIO_base+0x0020+0x04)
   #define 	GPIO_DIR4_SET         (GPIO_base+0x0030+0x04)
   #define 	GPIO_DIR5_SET         (GPIO_base+0x0040+0x04)      
   #define 	GPIO_DIR6_SET         (GPIO_base+0x0380+0x04)      
   #define 	GPIO_PULLEN1_SET    	(GPIO_base+0x0050+0x04)
   #define 	GPIO_PULLEN2_SET    	(GPIO_base+0x0060+0x04)
   #define 	GPIO_PULLEN3_SET   	(GPIO_base+0x0070+0x04)
   #define 	GPIO_PULLEN4_SET      (GPIO_base+0x0080+0x04)
   #define 	GPIO_PULLEN5_SET      (GPIO_base+0x0090+0x04)   
   #define 	GPIO_PULLEN6_SET      (GPIO_base+0x0390+0x04)   
   #define 	GPIO_DINV1_SET      	(GPIO_base+0x00a0+0x04)
   #define 	GPIO_DINV2_SET      	(GPIO_base+0x00b0+0x04)
   #define 	GPIO_DINV3_SET      	(GPIO_base+0x00c0+0x04)
   #define 	GPIO_DINV4_SET      	(GPIO_base+0x00d0+0x04)
   #define 	GPIO_DINV5_SET      	(GPIO_base+0x00e0+0x04)   
   #define 	GPIO_DINV6_SET      	(GPIO_base+0x03a0+0x04)   
   #define 	GPIO_DOUT1_SET      	(GPIO_base+0x00f0+0x04)
   #define 	GPIO_DOUT2_SET      	(GPIO_base+0x0100+0x04)
   #define 	GPIO_DOUT3_SET      	(GPIO_base+0x0110+0x04)
   #define 	GPIO_DOUT4_SET      	(GPIO_base+0x0120+0x04)
   #define 	GPIO_DOUT5_SET      	(GPIO_base+0x0130+0x04)   
   #define 	GPIO_DOUT6_SET      	(GPIO_base+0x03b0+0x04)   
   #define 	GPIO_DIN1_SET       	(GPIO_base+0x0140+0x04)
   #define 	GPIO_DIN2_SET       	(GPIO_base+0x0150+0x04)
   #define 	GPIO_DIN3_SET       	(GPIO_base+0x0160+0x04)
   #define 	GPIO_DIN4_SET       	(GPIO_base+0x0170+0x04)
   #define 	GPIO_DIN5_SET       	(GPIO_base+0x0180+0x04)   
   #define 	GPIO_DIN6_SET       	(GPIO_base+0x03c0+0x04)   
   #define 	GPIO_MODE1_SET       	(GPIO_base+0x0190+0x04)
   #define 	GPIO_MODE2_SET       	(GPIO_base+0x01a0+0x04)
   #define 	GPIO_MODE3_SET       	(GPIO_base+0x01b0+0x04)
   #define 	GPIO_MODE4_SET       	(GPIO_base+0x01c0+0x04)         
   #define 	GPIO_MODE5_SET       	(GPIO_base+0x01d0+0x04)         
   #define 	GPIO_MODE6_SET       	(GPIO_base+0x01e0+0x04)         
   #define 	GPIO_MODE7_SET       	(GPIO_base+0x01f0+0x04)         
   #define 	GPIO_MODE8_SET       	(GPIO_base+0x0200+0x04)
   #define 	GPIO_MODE9_SET       	(GPIO_base+0x0210+0x04)
   #define 	GPIO_MODEA_SET      	(GPIO_base+0x0220+0x04)
   #define 	GPIO_MODEB_SET       (GPIO_base+0x03d0+0x04)   
   #define 	GPIO_BANK_SET       	(GPIO_base+0x0230+0x04)   
   #define  CLKO_MODE1_SET      	(GPIO_base+0x0300+0x04)   
   #define  CLKO_MODE2_SET      	(GPIO_base+0x0310+0x04)   
   #define  CLKO_MODE3_SET      	(GPIO_base+0x0320+0x04)   
   #define  CLKO_MODE4_SET      	(GPIO_base+0x0330+0x04)   
   #define  CLKO_MODE5_SET      	(GPIO_base+0x0340+0x04)   
   #define  CLKO_MODE6_SET      	(GPIO_base+0x0350+0x04)   
   #define  CLKO_MODE7_SET      	(GPIO_base+0x0360+0x04)   
   
   #define 	GPIO_PULLSEL1_SET    	(GPIO_base+0x0240+0x04)
   #define 	GPIO_PULLSEL2_SET    	(GPIO_base+0x0250+0x04)
   #define 	GPIO_PULLSEL3_SET   	(GPIO_base+0x0260+0x04)
   #define 	GPIO_PULLSEL4_SET     (GPIO_base+0x0270+0x04)
   #define 	GPIO_PULLSEL5_SET     (GPIO_base+0x0280+0x04)   
   #define 	GPIO_PULLSEL6_SET     (GPIO_base+0x03e0+0x04)   
   #define  GPIO_TM_SET        	(GPIO_base+0x0370+0x04)   

   #define  GPIO_MODE_SET(_no)  (((_no)<10)?(GPIO_MODE1_SET+(0x10*(_no))):(GPIO_MODEB_SET))
   #define  GPIO_DIR_SET(_no)   (((_no)<5)?(GPIO_DIR1_SET+(0x10*(_no))):(GPIO_DIR6_SET))  
   #define  GPIO_DOUT_SET(_no)  (((_no)<5)?(GPIO_DOUT1_SET+(0x10*(_no))):(GPIO_DOUT6_SET))  
   #define  GPIO_PULLEN_SET(_no)  (((_no)<5)?(GPIO_PULLEN1_SET+(0x10*(_no))):(GPIO_PULLEN6_SET))
   #define  GPIO_PULLSEL_SET(_no)  (((_no)<5)?(GPIO_PULLSEL1_SET+(0x10*(_no))):(GPIO_PULLSEL6_SET))

   #define 	GPIO_DIR1_CLR       	(GPIO_base+0x0000+0x08)
   #define 	GPIO_DIR2_CLR   	   (GPIO_base+0x0010+0x08)
   #define 	GPIO_DIR3_CLR         (GPIO_base+0x0020+0x08)
   #define 	GPIO_DIR4_CLR         (GPIO_base+0x0030+0x08)
   #define 	GPIO_DIR5_CLR         (GPIO_base+0x0040+0x08)      
   #define 	GPIO_DIR6_CLR         (GPIO_base+0x0380+0x08)      
   #define 	GPIO_PULLEN1_CLR    	(GPIO_base+0x0050+0x08)
   #define 	GPIO_PULLEN2_CLR    	(GPIO_base+0x0060+0x08)
   #define 	GPIO_PULLEN3_CLR   	(GPIO_base+0x0070+0x08)
   #define 	GPIO_PULLEN4_CLR      (GPIO_base+0x0080+0x08)
   #define 	GPIO_PULLEN5_CLR      (GPIO_base+0x0090+0x08)   
   #define 	GPIO_PULLEN6_CLR      (GPIO_base+0x0390+0x08)   
   #define 	GPIO_DINV1_CLR      	(GPIO_base+0x00a0+0x08)
   #define 	GPIO_DINV2_CLR      	(GPIO_base+0x00b0+0x08)
   #define 	GPIO_DINV3_CLR      	(GPIO_base+0x00c0+0x08)
   #define 	GPIO_DINV4_CLR      	(GPIO_base+0x00d0+0x08)
   #define 	GPIO_DINV5_CLR      	(GPIO_base+0x00e0+0x08)   
   #define 	GPIO_DINV6_CLR      	(GPIO_base+0x03a0+0x08)   
   #define 	GPIO_DOUT1_CLR      	(GPIO_base+0x00f0+0x08)
   #define 	GPIO_DOUT2_CLR      	(GPIO_base+0x0100+0x08)
   #define 	GPIO_DOUT3_CLR      	(GPIO_base+0x0110+0x08)
   #define 	GPIO_DOUT4_CLR      	(GPIO_base+0x0120+0x08)
   #define 	GPIO_DOUT5_CLR      	(GPIO_base+0x0130+0x08)   
   #define 	GPIO_DOUT6_CLR      	(GPIO_base+0x03b0+0x08)   
   #define 	GPIO_DIN1_CLR       	(GPIO_base+0x0140+0x08)
   #define 	GPIO_DIN2_CLR       	(GPIO_base+0x0150+0x08)
   #define 	GPIO_DIN3_CLR       	(GPIO_base+0x0160+0x08)
   #define 	GPIO_DIN4_CLR       	(GPIO_base+0x0170+0x08)
   #define 	GPIO_DIN5_CLR       	(GPIO_base+0x0180+0x08)   
   #define 	GPIO_DIN6_CLR       	(GPIO_base+0x03c0+0x08)   
   #define 	GPIO_MODE1_CLR       	(GPIO_base+0x0190+0x08)
   #define 	GPIO_MODE2_CLR       	(GPIO_base+0x01a0+0x08)
   #define 	GPIO_MODE3_CLR       	(GPIO_base+0x01b0+0x08)
   #define 	GPIO_MODE4_CLR       	(GPIO_base+0x01c0+0x08)         
   #define 	GPIO_MODE5_CLR       	(GPIO_base+0x01d0+0x08)         
   #define 	GPIO_MODE6_CLR       	(GPIO_base+0x01e0+0x08)         
   #define 	GPIO_MODE7_CLR       	(GPIO_base+0x01f0+0x08)         
   #define 	GPIO_MODE8_CLR       	(GPIO_base+0x0200+0x08)
   #define 	GPIO_MODE9_CLR       	(GPIO_base+0x0210+0x08)
   #define 	GPIO_MODEA_CLR      	(GPIO_base+0x0220+0x08)
   #define 	GPIO_MODEB_CLR       (GPIO_base+0x03d0+0x08)   
   #define 	GPIO_BANK_CLR       	(GPIO_base+0x0230+0x08)   
   #define  CLKO_MODE1_CLR      	(GPIO_base+0x0300+0x08)   
   #define  CLKO_MODE2_CLR      	(GPIO_base+0x0310+0x08)   
   #define  CLKO_MODE3_CLR      	(GPIO_base+0x0320+0x08)   
   #define  CLKO_MODE4_CLR      	(GPIO_base+0x0330+0x08)   
   #define  CLKO_MODE5_CLR      	(GPIO_base+0x0340+0x08)   
   #define  CLKO_MODE6_CLR      	(GPIO_base+0x0350+0x08)   
   #define  CLKO_MODE7_CLR      	(GPIO_base+0x0360+0x08)   
   
   #define 	GPIO_PULLSEL1_CLR    	(GPIO_base+0x0240+0x08)
   #define 	GPIO_PULLSEL2_CLR    	(GPIO_base+0x0250+0x08)
   #define 	GPIO_PULLSEL3_CLR   	(GPIO_base+0x0260+0x08)
   #define 	GPIO_PULLSEL4_CLR     (GPIO_base+0x0270+0x08)
   #define 	GPIO_PULLSEL5_CLR     (GPIO_base+0x0280+0x08)   
   #define 	GPIO_PULLSEL6_CLR     (GPIO_base+0x03e0+0x08)   
   #define  GPIO_TM_CLR        	(GPIO_base+0x0370+0x08)   

   #define  GPIO_MODE_CLR(_no)  (((_no)<10)?(GPIO_MODE1_CLR+(0x10*(_no))):(GPIO_MODEB_CLR))
   #define  GPIO_DIR_CLR(_no)   (((_no)<5)?(GPIO_DIR1_CLR+(0x10*(_no))):(GPIO_DIR6_CLR))  
   #define  GPIO_DOUT_CLR(_no)  (((_no)<5)?(GPIO_DOUT1_CLR+(0x10*(_no))):(GPIO_DOUT6_CLR))  
   #define  GPIO_PULLEN_CLR(_no)  (((_no)<5)?(GPIO_PULLEN1_CLR+(0x10*(_no))):(GPIO_PULLEN6_CLR))
   #define  GPIO_PULLSEL_CLR(_no)  (((_no)<5)?(GPIO_PULLSEL1_CLR+(0x10*(_no))):(GPIO_PULLSEL6_CLR))

   #define  GPIO_MODE(_no)      (((_no)<10)?(GPIO_MODE1+(0x10*(_no))):(GPIO_MODEB))
   #define  GPIO_DOUT(_no)      (((_no)<5)?(GPIO_DOUT1+(0x10*(_no))):(GPIO_DOUT6))
   #define  GPIO_DIR(_no)       (((_no)<5)?(GPIO_DIR1+(0x10*(_no))):(GPIO_DIR6))
   #define  GPIO_DIN(_no)       (((_no)<5)?(GPIO_DIN1+(0x10*(_no))):(GPIO_DIN6))
   #define  GPIO_PULLEN(_no)    (((_no)<5)?(GPIO_PULLEN1+(0x10*(_no))):(GPIO_PULLEN6))
   #define  GPIO_PULLSEL(_no)   (((_no)<5)?(GPIO_PULLSEL1+(0x10*(_no))):(GPIO_PULLSEL6))
   #define  CLKO_MODE(_no)      (CLKO_MODE1+(0x10*(_no)))  

   #define  CLKO_NUM            7
#endif   /*DRV_GPIO_REG_AS_6253T*/

#if defined(DRV_GPIO_REG_AS_6253E)
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   	   (GPIO_base+0x0010)
   #define 	GPIO_DIR3         (GPIO_base+0x0020)
   #define 	GPIO_DIR4         (GPIO_base+0x0030)
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0050)
   #define 	GPIO_PULLEN2    	(GPIO_base+0x0060)
   #define 	GPIO_PULLEN3   	(GPIO_base+0x0070)
   #define 	GPIO_PULLEN4      (GPIO_base+0x0080)
   #define 	GPIO_DINV1      	(GPIO_base+0x00a0)
   #define 	GPIO_DINV2      	(GPIO_base+0x00b0)
   #define 	GPIO_DINV3      	(GPIO_base+0x00c0)
   #define 	GPIO_DINV4      	(GPIO_base+0x00d0)
   #define 	GPIO_DOUT1      	(GPIO_base+0x00f0)
   #define 	GPIO_DOUT2      	(GPIO_base+0x0100)
   #define 	GPIO_DOUT3      	(GPIO_base+0x0110)
   #define 	GPIO_DOUT4      	(GPIO_base+0x0120)
   #define 	GPIO_DIN1       	(GPIO_base+0x0140)
   #define 	GPIO_DIN2       	(GPIO_base+0x0150)
   #define 	GPIO_DIN3       	(GPIO_base+0x0160)
   #define 	GPIO_DIN4       	(GPIO_base+0x0170)

   #define 	GPIO_SPMODE      	(GPIO_base+0x0220)

   #define 	GPIO_MODE1       	(GPIO_base+0x0190)
   #define 	GPIO_MODE2       	(GPIO_base+0x01a0)
   #define 	GPIO_MODE3       	(GPIO_base+0x01b0)
   #define 	GPIO_MODE4       	(GPIO_base+0x01c0)         
   #define 	GPIO_MODE5       	(GPIO_base+0x01d0)         
   #define 	GPIO_MODE6       	(GPIO_base+0x01e0)         
   #define 	GPIO_MODE7       	(GPIO_base+0x01f0)         
   #define 	GPIO_MODE8       	(GPIO_base+0x0200)

   #define 	GPIO_BANK       	(GPIO_base+0x0230)   

   #define  CLKO_MODE1      	(GPIO_base+0x0300)   
   #define  CLKO_MODE2      	(GPIO_base+0x0310)   
   #define  CLKO_MODE3      	(GPIO_base+0x0320)   
   #define  CLKO_MODE4      	(GPIO_base+0x0330)   
   #define  CLKO_MODE5      	(GPIO_base+0x0340)   
   #define  CLKO_MODE6      	(GPIO_base+0x0350)   
   #define  CLKO_MODE7      	(GPIO_base+0x0360)   
   #define  GPIO_DINV_ADRS(n)	(GPIO_DINV1+0x10*(n))
   
   #define 	GPIO_PULLSEL1    	(GPIO_base+0x0240)
   #define 	GPIO_PULLSEL2    	(GPIO_base+0x0250)
   #define 	GPIO_PULLSEL3   	(GPIO_base+0x0260)
   #define 	GPIO_PULLSEL4     (GPIO_base+0x0270)

   #define  GPIO_TM        	(GPIO_base+0x0370)   

   #define 	GPIO_DIR1_SET       	(GPIO_DIR1+0x04)
   #define 	GPIO_PULLEN1_SET    	(GPIO_PULLEN1+0x04)
   #define 	GPIO_DOUT1_SET      	(GPIO_DOUT1+0x04)
   #define 	GPIO_MODE1_SET       (GPIO_MODE1+0x04)
  
   #define 	GPIO_PULLSEL1_SET    	(GPIO_PULLSEL1+0x04)
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x10*(_no)))
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x10*(_no)))  
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x10*(_no)))  
   #define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x10*(_no)))  
   #define  GPIO_PULLSEL_SET(_no)  (GPIO_PULLSEL1_SET+(0x10*(_no)))  

   #define 	GPIO_DIR1_CLR       	(GPIO_DIR1+0x08)
   #define 	GPIO_PULLEN1_CLR    	(GPIO_PULLEN1+0x08)
   #define 	GPIO_DOUT1_CLR      	(GPIO_DOUT1+0x08)
   #define 	GPIO_MODE1_CLR       	(GPIO_MODE1+0x08)
   #define 	GPIO_PULLSEL1_CLR    	(GPIO_PULLSEL1+0x08)
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x10*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x10*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x10*(_no)))
   #define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN1_CLR+(0x10*(_no)))  
   #define  GPIO_PULLSEL_CLR(_no)  (GPIO_PULLSEL1_CLR+(0x10*(_no)))  

   #define  GPIO_MODE(_no)      (GPIO_MODE1+(0x10*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x10*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x10*(_no)))
   #define  GPIO_DIN(_no)       (GPIO_DIN1+(0x10*(_no)))
   #define  GPIO_PULLEN(_no)    (GPIO_PULLEN1+(0x10*(_no)))
   #define  GPIO_PULLSEL(_no)   (GPIO_PULLSEL1+(0x10*(_no)))
   #define  CLKO_MODE(_no)      (CLKO_MODE1+(0x10*(_no)))  
   #define  CLKO_NUM            7

#endif   /*DRV_GPIO_REG_AS_6253E*/

#if defined(DRV_GPIO_REG_AS_6253E_1)
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   		(GPIO_base+0x0010)
   #define 	GPIO_DIR3         	(GPIO_base+0x0020)
   #define 	GPIO_DIR4         	(GPIO_base+0x0030)
   #define	GPIO_DIR5		(GPIO_base+0x0040)

   #define 	GPIO_PULLEN1    	(GPIO_base+0x0050)
   #define 	GPIO_PULLEN2    	(GPIO_base+0x0060)
   #define 	GPIO_PULLEN3   		(GPIO_base+0x0070)
   #define 	GPIO_PULLEN4      	(GPIO_base+0x0080)
   #define	GPIO_PULLEN5		(GPIO_base+0x0090)

   #define 	GPIO_DINV1      	(GPIO_base+0x00a0)
   #define 	GPIO_DINV2      	(GPIO_base+0x00b0)
   #define 	GPIO_DINV3      	(GPIO_base+0x00c0)
   #define 	GPIO_DINV4      	(GPIO_base+0x00d0)
   #define      GPIO_DINV5		(GPIO_base+0x00e0)

   #define 	GPIO_DOUT1      	(GPIO_base+0x00f0)
   #define 	GPIO_DOUT2      	(GPIO_base+0x0100)
   #define 	GPIO_DOUT3      	(GPIO_base+0x0110)
   #define 	GPIO_DOUT4      	(GPIO_base+0x0120)
   #define      GPIO_DOUT5		(GPIO_base+0x0130)

   #define 	GPIO_DIN1       	(GPIO_base+0x0140)
   #define 	GPIO_DIN2       	(GPIO_base+0x0150)
   #define 	GPIO_DIN3       	(GPIO_base+0x0160)
   #define 	GPIO_DIN4       	(GPIO_base+0x0170)
   #define	GPIO_DIN5		(GPIO_base+0x0180)

   #define	GPIO_SPMODE0		(GPIO_base+0x0210)
   #define 	GPIO_SPMODE1     	(GPIO_base+0x0220)

   #define 	GPIO_MODE1       	(GPIO_base+0x0190)
   #define 	GPIO_MODE2       	(GPIO_base+0x01a0)
   #define 	GPIO_MODE3       	(GPIO_base+0x01b0)
   #define 	GPIO_MODE4       	(GPIO_base+0x01c0)         
   #define 	GPIO_MODE5       	(GPIO_base+0x01d0)         
   #define 	GPIO_MODE6       	(GPIO_base+0x01e0)         
   #define 	GPIO_MODE7       	(GPIO_base+0x01f0)         
   #define 	GPIO_MODE8       	(GPIO_base+0x0200)
   #define 	GPIO_MODE9		(GPIO_base+0x0230)

 //  #define 	GPIO_BANK       	(GPIO_base+0x0230)   

   #define  	CLKO_MODE1      	(GPIO_base+0x0300)   
   #define  	CLKO_MODE2      	(GPIO_base+0x0310)   
   #define  	CLKO_MODE3      	(GPIO_base+0x0320)   
   #define  	CLKO_MODE4      	(GPIO_base+0x0330)   
   #define  	CLKO_MODE5      	(GPIO_base+0x0340)   
   #define  	CLKO_MODE6      	(GPIO_base+0x0350)   
   #define  	CLKO_MODE7      	(GPIO_base+0x0360)   
   
   #define  	GPIO_DINV_ADRS(n)	(GPIO_DINV1+0x10*(n))
   
   #define 	GPIO_PULLSEL1    	(GPIO_base+0x0240)
   #define 	GPIO_PULLSEL2    	(GPIO_base+0x0250)
   #define 	GPIO_PULLSEL3   	(GPIO_base+0x0260)
   #define 	GPIO_PULLSEL4     	(GPIO_base+0x0270)
   #define 	GPIO_PULLSEL5     	(GPIO_base+0x0280)

   #define  	GPIO_TM        		(GPIO_base+0x0370)   

   #define 	GPIO_DIR1_SET       	(GPIO_DIR1+0x04)
   #define 	GPIO_PULLEN1_SET    	(GPIO_PULLEN1+0x04)
   #define 	GPIO_DOUT1_SET      	(GPIO_DOUT1+0x04)
   #define 	GPIO_MODE1_SET       	(GPIO_MODE1+0x04)
   #define 	GPIO_PULLSEL1_SET    	(GPIO_PULLSEL1+0x04)

   #define  	GPIO_MODE_SET(_no)  	(((_no)==8)?(GPIO_MODE9+0x04):(GPIO_MODE1_SET+(0x10*(_no))))
   #define  	GPIO_DIR_SET(_no)   	(GPIO_DIR1_SET+(0x10*(_no)))  
   #define  	GPIO_DOUT_SET(_no)  	(GPIO_DOUT1_SET+(0x10*(_no)))  
   #define  	GPIO_PULLEN_SET(_no)  	(GPIO_PULLEN1_SET+(0x10*(_no)))  
   #define  	GPIO_PULLSEL_SET(_no)  	(GPIO_PULLSEL1_SET+(0x10*(_no)))  

   #define 	GPIO_DIR1_CLR       	(GPIO_DIR1+0x08)
   #define 	GPIO_PULLEN1_CLR    	(GPIO_PULLEN1+0x08)
   #define 	GPIO_DOUT1_CLR      	(GPIO_DOUT1+0x08)
   #define 	GPIO_MODE1_CLR       	(GPIO_MODE1+0x08)
   #define 	GPIO_PULLSEL1_CLR    	(GPIO_PULLSEL1+0x08)

   #define 	GPIO_MODE_CLR(_no)  	(((_no)==8)?(GPIO_MODE9+0x08):(GPIO_MODE1_CLR+(0x10*(_no))))
   #define  	GPIO_DIR_CLR(_no)   	(GPIO_DIR1_CLR+(0x10*(_no)))
   #define  	GPIO_DOUT_CLR(_no)  	(GPIO_DOUT1_CLR+(0x10*(_no)))
   #define  	GPIO_PULLEN_CLR(_no)  	(GPIO_PULLEN1_CLR+(0x10*(_no)))  
   #define  	GPIO_PULLSEL_CLR(_no)  	(GPIO_PULLSEL1_CLR+(0x10*(_no)))  

   #define  	GPIO_MODE(_no)      	(((_no)==8)?(GPIO_MODE9):(GPIO_MODE1+(0x10*(_no)))) 
   #define  	GPIO_DOUT(_no)      	(GPIO_DOUT1+(0x10*(_no)))
   #define  	GPIO_DIR(_no)       	(GPIO_DIR1+(0x10*(_no)))
   #define  	GPIO_DIN(_no)       	(GPIO_DIN1+(0x10*(_no)))
   #define  	GPIO_PULLEN(_no)    	(GPIO_PULLEN1+(0x10*(_no)))
   #define  	GPIO_PULLSEL(_no)   	(GPIO_PULLSEL1+(0x10*(_no)))
   #define  	CLKO_MODE(_no)      	(CLKO_MODE1+(0x10*(_no)))  
   #define  	CLKO_NUM            	7

#endif   /*DRV_GPIO_REG_AS_6253E_1*/

#if defined(DRV_GPIO_REG_AS_6236)
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   	   (GPIO_base+0x0010)
   #define 	GPIO_DIR3         (GPIO_base+0x0020)
   #define 	GPIO_DIR4         (GPIO_base+0x0030)
   #define 	GPIO_DIR5         (GPIO_base+0x0040)      
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0100)
   #define 	GPIO_PULLEN2    	(GPIO_base+0x0110)
   #define 	GPIO_PULLEN3   	(GPIO_base+0x0120)
   #define 	GPIO_PULLEN4      (GPIO_base+0x0130)
   #define 	GPIO_PULLEN5      (GPIO_base+0x0140)   
   #define 	GPIO_PULLSEL1    	(GPIO_base+0x0200)
   #define 	GPIO_PULLSEL2    	(GPIO_base+0x0210)
   #define 	GPIO_PULLSEL3   	(GPIO_base+0x0220)
   #define 	GPIO_PULLSEL4     (GPIO_base+0x0230)
   #define 	GPIO_PULLSEL5     (GPIO_base+0x0240)   
   #define 	GPIO_DINV1      	(GPIO_base+0x0300)
   #define 	GPIO_DINV2      	(GPIO_base+0x0310)
   #define 	GPIO_DINV3      	(GPIO_base+0x0320)
   #define 	GPIO_DINV4      	(GPIO_base+0x0330)
   #define 	GPIO_DINV5      	(GPIO_base+0x0340)   
   #define 	GPIO_DOUT1      	(GPIO_base+0x0400)
   #define 	GPIO_DOUT2      	(GPIO_base+0x0410)
   #define 	GPIO_DOUT3      	(GPIO_base+0x0420)
   #define 	GPIO_DOUT4      	(GPIO_base+0x0430)
   #define 	GPIO_DOUT5      	(GPIO_base+0x0440)   
   #define 	GPIO_DIN1       	(GPIO_base+0x0500)
   #define 	GPIO_DIN2       	(GPIO_base+0x0510)
   #define 	GPIO_DIN3       	(GPIO_base+0x0520)
   #define 	GPIO_DIN4       	(GPIO_base+0x0530)
   #define 	GPIO_DIN5       	(GPIO_base+0x0540)   
   #define 	GPIO_MODE1       	(GPIO_base+0x0600)
   #define 	GPIO_MODE2       	(GPIO_base+0x0610)
   #define 	GPIO_MODE3       	(GPIO_base+0x0620)         
   #define 	GPIO_MODE4       	(GPIO_base+0x0630)         
   #define 	GPIO_MODE5       	(GPIO_base+0x0640)         
   #define 	GPIO_MODE6       	(GPIO_base+0x0650)         
   #define 	GPIO_MODE7       	(GPIO_base+0x0660)
   #define 	GPIO_MODE8       	(GPIO_base+0x0670)
   #define 	GPIO_MODE9       	(GPIO_base+0x0680)
   #define  CLKO_MODE0      	(GPIO_base+0x0900)
   #define  CLKO_MODE1      	(GPIO_base+0x0910)   
   #define  CLKO_MODE2      	(GPIO_base+0x0920)   
   #define  CLKO_MODE3      	(GPIO_base+0x0930)   
   #define  CLKO_MODE4      	(GPIO_base+0x0940)   
   #define  CLKO_MODE5      	(GPIO_base+0x0950)   
   #define  GPIO_DINV_ADRS(n)	(GPIO_DINV1+0x10*(n))  
   
   #define 	GPIO_DIR1_SET       (GPIO_base+0x0000+0x04)    
   #define 	GPIO_DIR2_SET    	  (GPIO_base+0x0010+0x04)        
   #define 	GPIO_DIR3_SET       (GPIO_base+0x0020+0x04)      
   #define 	GPIO_DIR4_SET       (GPIO_base+0x0030+0x04)    
   #define 	GPIO_DIR5_SET       (GPIO_base+0x0040+0x04)    
   #define 	GPIO_PULLEN1_SET    (GPIO_base+0x0100+0x04)      
   #define 	GPIO_PULLEN2_SET    (GPIO_base+0x0110+0x04)      
   #define 	GPIO_PULLEN3_SET    (GPIO_base+0x0120+0x04)     
   #define 	GPIO_PULLEN4_SET    (GPIO_base+0x0130+0x04)    
   #define 	GPIO_PULLEN5_SET    (GPIO_base+0x0140+0x04)    
   #define 	GPIO_PULLSEL1_SET   (GPIO_base+0x0200+0x04)      
   #define 	GPIO_PULLSEL2_SET   (GPIO_base+0x0210+0x04)      
   #define 	GPIO_PULLSEL3_SET   (GPIO_base+0x0220+0x04)     
   #define 	GPIO_PULLSEL4_SET   (GPIO_base+0x0230+0x04)    
   #define 	GPIO_PULLSEL5_SET   (GPIO_base+0x0240+0x04)    
   #define 	GPIO_DOUT1_SET      (GPIO_base+0x0400+0x04)    
   #define 	GPIO_DOUT2_SET      (GPIO_base+0x0410+0x04)    
   #define 	GPIO_DOUT3_SET      (GPIO_base+0x0420+0x04)    
   #define 	GPIO_DOUT4_SET      (GPIO_base+0x0430+0x04)    
   #define 	GPIO_DOUT5_SET      (GPIO_base+0x0440+0x04)    
   #define 	GPIO_MODE1_SET      (GPIO_base+0x0600+0x04)        
   #define 	GPIO_MODE2_SET      (GPIO_base+0x0610+0x04)    
   #define 	GPIO_MODE3_SET      (GPIO_base+0x0620+0x04)       
   #define 	GPIO_MODE4_SET      (GPIO_base+0x0630+0x04)    
   #define 	GPIO_MODE5_SET      (GPIO_base+0x0640+0x04)        
   #define 	GPIO_MODE6_SET      (GPIO_base+0x0650+0x04)        
   #define 	GPIO_MODE7_SET      (GPIO_base+0x0660+0x04)      
   #define 	GPIO_MODE8_SET      (GPIO_base+0x0670+0x04)        
   #define 	GPIO_MODE9_SET      (GPIO_base+0x0680+0x04)      
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x10*(_no)))
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x10*(_no)))  
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x10*(_no)))  
   #define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x10*(_no)))  
   #define  GPIO_PULLSEL_SET(_no)  (GPIO_PULLSEL1_SET+(0x10*(_no)))  
                                                             
   #define 	GPIO_DIR1_CLR       (GPIO_base+0x0000+0x08)         
   #define 	GPIO_DIR2_CLR   	  (GPIO_base+0x0010+0x08)         
   #define 	GPIO_DIR3_CLR       (GPIO_base+0x0020+0x08)         
   #define 	GPIO_DIR4_CLR       (GPIO_base+0x0030+0x08)         
   #define 	GPIO_DIR5_CLR       (GPIO_base+0x0040+0x08)         
   #define 	GPIO_PULLEN1_CLR    (GPIO_base+0x0100+0x08)         
   #define 	GPIO_PULLEN2_CLR    (GPIO_base+0x0110+0x08)         
   #define 	GPIO_PULLEN3_CLR    (GPIO_base+0x0120+0x08)         
   #define 	GPIO_PULLEN4_CLR    (GPIO_base+0x0130+0x08)         
   #define 	GPIO_PULLEN5_CLR    (GPIO_base+0x0140+0x08)         
   #define 	GPIO_PULLSEL1_CLR   (GPIO_base+0x0200+0x08)         
   #define 	GPIO_PULLSEL2_CLR   (GPIO_base+0x0210+0x08)         
   #define 	GPIO_PULLSEL3_CLR   (GPIO_base+0x0220+0x08)         
   #define 	GPIO_PULLSEL4_CLR   (GPIO_base+0x0230+0x08)         
   #define 	GPIO_PULLSEL5_CLR   (GPIO_base+0x0240+0x08)         
   #define 	GPIO_DOUT1_CLR      (GPIO_base+0x0400+0x08)         
   #define 	GPIO_DOUT2_CLR      (GPIO_base+0x0410+0x08)         
   #define 	GPIO_DOUT3_CLR      (GPIO_base+0x0420+0x08)         
   #define 	GPIO_DOUT4_CLR      (GPIO_base+0x0430+0x08)         
   #define 	GPIO_DOUT5_CLR      (GPIO_base+0x0440+0x08)         
   #define 	GPIO_MODE1_CLR      (GPIO_base+0x0600+0x08)         
   #define 	GPIO_MODE2_CLR      (GPIO_base+0x0610+0x08)         
   #define 	GPIO_MODE3_CLR      (GPIO_base+0x0620+0x08)         
   #define 	GPIO_MODE4_CLR      (GPIO_base+0x0630+0x08)         
   #define 	GPIO_MODE5_CLR      (GPIO_base+0x0640+0x08)         
   #define 	GPIO_MODE6_CLR      (GPIO_base+0x0650+0x08)         
   #define 	GPIO_MODE7_CLR      (GPIO_base+0x0660+0x08)         
   #define 	GPIO_MODE8_CLR      (GPIO_base+0x0670+0x08)         
   #define 	GPIO_MODE9_CLR      (GPIO_base+0x0680+0x08)         
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x10*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x10*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x10*(_no)))
   #define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN1_CLR+(0x10*(_no)))  
   #define  GPIO_PULLSEL_CLR(_no)  (GPIO_PULLSEL1_CLR+(0x10*(_no)))  
   
   #define  GPIO_MODE(_no)      (GPIO_MODE1+(0x10*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x10*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x10*(_no)))
   #define  GPIO_DIN(_no)       (GPIO_DIN1+(0x10*(_no)))
   #define  GPIO_PULLEN(_no)    (GPIO_PULLEN1+(0x10*(_no)))
   #define  GPIO_PULLSEL(_no)   (GPIO_PULLSEL1+(0x10*(_no)))
   #define  CLKO_MODE(_no)      (CLKO_MODE0+(0x10*(_no)))  
   #define  CLKO_NUM            6
#endif   /*defined(DRV_GPIO_REG_AS_6236)*/

#if defined(DRV_GPIO_REG_AS_6255)
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   	   (GPIO_base+0x0010)
   #define 	GPIO_DIR3         (GPIO_base+0x0020)
   #define 	GPIO_DIR4         (GPIO_base+0x0030)
   #define 	GPIO_DIR5         (GPIO_base+0x0040)      
   #define 	GPIO_DIR6         (GPIO_base+0x0050)      
   #define 	GPIO_DIR7        (GPIO_base+0x0060)    
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0100)
   #define 	GPIO_PULLEN2    	(GPIO_base+0x0110)
   #define 	GPIO_PULLEN3   	(GPIO_base+0x0120)
   #define 	GPIO_PULLEN4      (GPIO_base+0x0130)
   #define 	GPIO_PULLEN5      (GPIO_base+0x0140)   
   #define 	GPIO_PULLEN6      (GPIO_base+0x0150)   
   #define 	GPIO_PULLEN7      (GPIO_base+0x0160)
   #define 	GPIO_PULLSEL1    	(GPIO_base+0x0200)
   #define 	GPIO_PULLSEL2    	(GPIO_base+0x0210)
   #define 	GPIO_PULLSEL3   	(GPIO_base+0x0220)
   #define 	GPIO_PULLSEL4     (GPIO_base+0x0230)
   #define 	GPIO_PULLSEL5     (GPIO_base+0x0240)   
   #define 	GPIO_PULLSEL6     (GPIO_base+0x0250)   
   #define 	GPIO_PULLSEL7    (GPIO_base+0x0260) 
   #define 	GPIO_DINV1      	(GPIO_base+0x0300)
   #define 	GPIO_DINV2      	(GPIO_base+0x0310)
   #define 	GPIO_DINV3      	(GPIO_base+0x0320)
   #define 	GPIO_DINV4      	(GPIO_base+0x0330)
   #define 	GPIO_DINV5      	(GPIO_base+0x0340)   
   #define 	GPIO_DINV6      	(GPIO_base+0x0350)   
   #define 	GPIO_DINV7     	(GPIO_base+0x0360)
   #define 	GPIO_DOUT1      	(GPIO_base+0x0400)
   #define 	GPIO_DOUT2      	(GPIO_base+0x0410)
   #define 	GPIO_DOUT3      	(GPIO_base+0x0420)
   #define 	GPIO_DOUT4      	(GPIO_base+0x0430)
   #define 	GPIO_DOUT5      	(GPIO_base+0x0440)   
   #define 	GPIO_DOUT6      	(GPIO_base+0x0450)   
   #define 	GPIO_DOUT7      	(GPIO_base+0x0460)
   #define 	GPIO_DIN1       	(GPIO_base+0x0500)
   #define 	GPIO_DIN2       	(GPIO_base+0x0510)
   #define 	GPIO_DIN3       	(GPIO_base+0x0520)
   #define 	GPIO_DIN4       	(GPIO_base+0x0530)
   #define 	GPIO_DIN5       	(GPIO_base+0x0540)   
   #define 	GPIO_DIN6       	(GPIO_base+0x0550)   
   #define 	GPIO_DIN7      	    (GPIO_base+0x0560) 
   #define 	GPIO_MODE1       	(GPIO_base+0x0600)
   #define 	GPIO_MODE2       	(GPIO_base+0x0610)
   #define 	GPIO_MODE3       	(GPIO_base+0x0620)         
   #define 	GPIO_MODE4       	(GPIO_base+0x0630)         
   #define 	GPIO_MODE5       	(GPIO_base+0x0640)         
   #define 	GPIO_MODE6       	(GPIO_base+0x0650)         
   #define 	GPIO_MODE7       	(GPIO_base+0x0660)
   #define 	GPIO_MODE8       	(GPIO_base+0x0670)
   #define 	GPIO_MODE9       	(GPIO_base+0x0680)
   #define 	GPIO_MODE10      	(GPIO_base+0x0690)
   #define 	GPIO_MODE11      	(GPIO_base+0x06A0)
   #define 	GPIO_MODE12      	(GPIO_base+0x06B0)
   #define 	GPIO_MODE13      	(GPIO_base+0x06C0)
   #define 	GPIO_MODE14      	(GPIO_base+0x06D0)
   #define 	GPIO_MODE15      	(GPIO_base+0x06E0)
   #define 	GPIO_MODE16      	(GPIO_base+0x06F0)
   #define 	GPIO_MODE17      	(GPIO_base+0x0700)
   #define 	GPIO_MODE18      	(GPIO_base+0x0710)
   #define 	GPIO_MODE19      	(GPIO_base+0x0720)
   #define 	GPIO_MODE20      	(GPIO_base+0x0730)
   #define 	GPIO_MODE21      	(GPIO_base+0x0740)
   #define 	GPIO_MODE22      	(GPIO_base+0x0750)
   #define 	GPIO_MODE23      	(GPIO_base+0x0760)
   #define 	GPIO_MODE24      	(GPIO_base+0x0770)
   #define 	GPIO_MODE25      	(GPIO_base+0x0780)
#define 	GPIO_MODE26      	(GPIO_base+0x0790)
#define 	GPIO_MODE27     	(GPIO_base+0x07A0)
   #define  CLKO_MODE0      	(GPIO_base+0x0900)
   #define  CLKO_MODE1      	(GPIO_base+0x0910)   
   #define  CLKO_MODE2      	(GPIO_base+0x0920)   
   #define  CLKO_MODE3      	(GPIO_base+0x0930)   
   #define  CLKO_MODE4      	(GPIO_base+0x0940)   
   #define  CLKO_MODE5      	(GPIO_base+0x0950)   
   #define  CLKO_MODE6      	(GPIO_base+0x0960)   
   #define  CLKO_MODE7      	(GPIO_base+0x0970)   
   #define  CLKO_MODE8      	(GPIO_base+0x0980)   
   
   #define  GPIO_DINV_ADRS(n)	(GPIO_DINV1+0x10*(n))  
   
   #define 	GPIO_DIR1_SET       (GPIO_DIR1+0x04)    
   #define 	GPIO_PULLEN1_SET    (GPIO_PULLEN1+0x04)      
   #define 	GPIO_PULLSEL1_SET   (GPIO_PULLSEL1+0x04)      
   #define 	GPIO_DOUT1_SET      (GPIO_DOUT1+0x04)    
   #define 	GPIO_MODE1_SET      (GPIO_MODE1+0x04)        
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x10*(_no)))
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x10*(_no)))  
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x10*(_no)))  
   #define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x10*(_no)))  
   #define  GPIO_PULLSEL_SET(_no)  (GPIO_PULLSEL1_SET+(0x10*(_no)))  
                                                             
   #define 	GPIO_DIR1_CLR       (GPIO_DIR1+0x08)         
   #define 	GPIO_PULLEN1_CLR    (GPIO_PULLEN1+0x08)         
   #define 	GPIO_PULLSEL1_CLR   (GPIO_PULLSEL1+0x08)         
   #define 	GPIO_DOUT1_CLR      (GPIO_DOUT1+0x08)         
   #define 	GPIO_MODE1_CLR      (GPIO_MODE1+0x08)         
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x10*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x10*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x10*(_no)))
   #define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN1_CLR+(0x10*(_no)))  
   #define  GPIO_PULLSEL_CLR(_no)  (GPIO_PULLSEL1_CLR+(0x10*(_no)))  
   
   #define  GPIO_MODE(_no)      (GPIO_MODE1+(0x10*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x10*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x10*(_no)))
   #define  GPIO_DIN(_no)       (GPIO_DIN1+(0x10*(_no)))
   #define  GPIO_PULLEN(_no)    (GPIO_PULLEN1+(0x10*(_no)))
   #define  GPIO_PULLSEL(_no)   (GPIO_PULLSEL1+(0x10*(_no)))
   #define  CLKO_MODE(_no)      (CLKO_MODE0+(0x10*(_no)))  
   #define  CLKO_NUM            9
#endif   /*defined(DRV_GPIO_REG_AS_6255)*/

#if defined(DRV_GPIO_REG_AS_6251)
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   	   (GPIO_base+0x0010)
   #define 	GPIO_DIR3         (GPIO_base+0x0020)
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0050)
   #define 	GPIO_PULLEN2    	(GPIO_base+0x0060)
   #define 	GPIO_PULLEN3   	(GPIO_base+0x0070)
   #define 	GPIO_PULLSEL1    	(GPIO_base+0x0240)
   #define 	GPIO_PULLSEL2    	(GPIO_base+0x0250)
   #define 	GPIO_PULLSEL3   	(GPIO_base+0x0260)
   #define 	GPIO_DINV1      	(GPIO_base+0x00A0)
   #define 	GPIO_DINV2      	(GPIO_base+0x00B0)
   //#define 	GPIO_DINV3      	(GPIO_base+0x00C0)
   #define 	GPIO_DOUT1      	(GPIO_base+0x00F0)
   #define 	GPIO_DOUT2      	(GPIO_base+0x0100)
   #define 	GPIO_DOUT3      	(GPIO_base+0x0110)
   #define 	GPIO_DIN1       	(GPIO_base+0x0140)
   #define 	GPIO_DIN2       	(GPIO_base+0x0150)
   //#define 	GPIO_DIN3       	(GPIO_base+0x0160)
   #define 	GPIO_MODE1       	(GPIO_base+0x0190)
   #define 	GPIO_MODE2       	(GPIO_base+0x01A0)
   #define 	GPIO_MODE3       	(GPIO_base+0x01B0)         
   #define 	GPIO_MODE4       	(GPIO_base+0x01C0)         
   #define 	GPIO_MODE5       	(GPIO_base+0x01D0)         
   #define 	GPIO_MODE6       	(GPIO_base+0x01E0)         
   #define 	GPIO_MODE7       	(GPIO_base+0x01F0)
   #define 	GPIO_MODE8       	(GPIO_base+0x0200)
   #define  CLKO_MODE0      	(GPIO_base+0x0300)
   #define  CLKO_MODE1      	(GPIO_base+0x0310)   
   #define  CLKO_MODE2      	(GPIO_base+0x0320)   
   #define  CLKO_MODE3      	(GPIO_base+0x0330)   
   #define  GPIO_DINV_ADRS(n)	(GPIO_DINV1+0x10*(n))  
   
   #define 	GPIO_DIR1_SET       (GPIO_DIR1+0x04)    
   #define 	GPIO_PULLEN1_SET    (GPIO_PULLEN1+0x04)      
   #define 	GPIO_PULLSEL1_SET   (GPIO_PULLSEL1+0x04)      
   #define 	GPIO_DOUT1_SET      (GPIO_DOUT1+0x04)    
   #define 	GPIO_MODE1_SET      (GPIO_MODE1+0x04)        
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x10*(_no)))
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x10*(_no)))  
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x10*(_no)))  
   #define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x10*(_no)))  
   #define  GPIO_PULLSEL_SET(_no)  (GPIO_PULLSEL1_SET+(0x10*(_no)))  
                                                             
   #define 	GPIO_DIR1_CLR       (GPIO_DIR1+0x08)         
   #define 	GPIO_PULLEN1_CLR    (GPIO_PULLEN1+0x08)         
   #define 	GPIO_PULLSEL1_CLR   (GPIO_PULLSEL1+0x08)         
   #define 	GPIO_DOUT1_CLR      (GPIO_DOUT1+0x08)         
   #define 	GPIO_MODE1_CLR      (GPIO_MODE1+0x08)         
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x10*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x10*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x10*(_no)))
   #define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN1_CLR+(0x10*(_no)))  
   #define  GPIO_PULLSEL_CLR(_no)  (GPIO_PULLSEL1_CLR+(0x10*(_no)))  
   
   #define  GPIO_MODE(_no)      (GPIO_MODE1+(0x10*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x10*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x10*(_no)))
   #define  GPIO_DIN(_no)       (GPIO_DIN1+(0x10*(_no)))
   #define  GPIO_PULLEN(_no)    (GPIO_PULLEN1+(0x10*(_no)))
   #define  GPIO_PULLSEL(_no)   (GPIO_PULLSEL1+(0x10*(_no)))
   #define  CLKO_MODE(_no)      (CLKO_MODE0+(0x10*(_no)))  
   #define  CLKO_NUM           4
#endif   /*defined(DRV_GPIO_REG_AS_6251)*/

 #if defined(MT6276_S01)
 #define CLK_MUX_SEL0 (CONFIG_base+0x0538)
 #define CLK_MUX_SEL1 (CONFIG_base+0x053C)
 #endif

#if defined(DRV_GPIO_REG_AS_6256)
   #define 	GPIO_DIR1       	(GPIO_base+0x0000)
   #define 	GPIO_DIR2   	   (GPIO_base+0x0010)
   #define 	GPIO_DIR3         (GPIO_base+0x0020)
   #define 	GPIO_DIR4         (GPIO_base+0x0030)
   #define 	GPIO_DIR5         (GPIO_base+0x0040)
   #define 	GPIO_DIR6         (GPIO_base+0x0050)
   #define  GPIO_DIR7			(GPIO_base+0x0060)
   
   #define 	GPIO_PULLEN1    	(GPIO_base+0x0100)
   #define 	GPIO_PULLEN2    	(GPIO_base+0x0110)
   #define 	GPIO_PULLEN3   	(GPIO_base+0x0120)
   #define 	GPIO_PULLEN4      (GPIO_base+0x0130)
   #define 	GPIO_PULLEN5      (GPIO_base+0x0140)
   #define 	GPIO_PULLEN6      (GPIO_base+0x0150)
   #define 	GPIO_PULLEN7      (GPIO_base+0x0160)
   
   #define 	GPIO_PULLSEL1    	(GPIO_base+0x0200)
   #define 	GPIO_PULLSEL2    	(GPIO_base+0x0210)
   #define 	GPIO_PULLSEL3   	(GPIO_base+0x0220)
   #define 	GPIO_PULLSEL4     (GPIO_base+0x0230)
   #define 	GPIO_PULLSEL5     (GPIO_base+0x0240)
   #define 	GPIO_PULLSEL6     (GPIO_base+0x0250)
   #define 	GPIO_PULLSEL7     (GPIO_base+0x0260)
   
   #define 	GPIO_DINV1      	(GPIO_base+0x0300)
   #define 	GPIO_DINV2      	(GPIO_base+0x0310)
   #define 	GPIO_DINV3      	(GPIO_base+0x0320)
   #define 	GPIO_DINV4      	(GPIO_base+0x0330)
   #define 	GPIO_DINV5      	(GPIO_base+0x0340)
   #define 	GPIO_DINV6      	(GPIO_base+0x0350)
   #define 	GPIO_DINV7      	(GPIO_base+0x0360)   
   
   #define 	GPIO_DOUT1      	(GPIO_base+0x0400)
   #define 	GPIO_DOUT2      	(GPIO_base+0x0410)
   #define 	GPIO_DOUT3      	(GPIO_base+0x0420)
   #define 	GPIO_DOUT4      	(GPIO_base+0x0430)
   #define 	GPIO_DOUT5      	(GPIO_base+0x0440)
   #define 	GPIO_DOUT6      	(GPIO_base+0x0450)
   #define 	GPIO_DOUT7      	(GPIO_base+0x0460)
   
   #define 	GPIO_DIN1       	(GPIO_base+0x0500)
   #define 	GPIO_DIN2       	(GPIO_base+0x0510)
   #define 	GPIO_DIN3       	(GPIO_base+0x0520)
   #define 	GPIO_DIN4       	(GPIO_base+0x0530)
   #define 	GPIO_DIN5       	(GPIO_base+0x0540)
   #define 	GPIO_DIN6       	(GPIO_base+0x0550)
   #define 	GPIO_DIN7       	(GPIO_base+0x0560)   
   
   #define 	GPIO_MODE1       	(GPIO_base+0x0600)
   #define 	GPIO_MODE2       	(GPIO_base+0x0610)
   #define 	GPIO_MODE3       	(GPIO_base+0x0620)
   #define 	GPIO_MODE4       	(GPIO_base+0x0630)
   #define 	GPIO_MODE5       	(GPIO_base+0x0640)
   #define 	GPIO_MODE6       	(GPIO_base+0x0650)
   #define 	GPIO_MODE7       	(GPIO_base+0x0660)
   #define 	GPIO_MODE8       	(GPIO_base+0x0670)
   #define 	GPIO_MODE9       	(GPIO_base+0x0680)
   #define 	GPIO_MODE10      	(GPIO_base+0x0690)
   #define 	GPIO_MODE11      	(GPIO_base+0x06A0)
   #define 	GPIO_MODE12      	(GPIO_base+0x06B0)
   #define 	GPIO_MODE13      	(GPIO_base+0x06C0)
   #define 	GPIO_MODE14      	(GPIO_base+0x06D0)
   #define 	GPIO_MODE15      	(GPIO_base+0x06E0)
   #define 	GPIO_MODE16      	(GPIO_base+0x06F0)
   #define 	GPIO_MODE17      	(GPIO_base+0x0700)
   #define 	GPIO_MODE18      	(GPIO_base+0x0710)
   #define 	GPIO_MODE19      	(GPIO_base+0x0720)
   #define 	GPIO_MODE20      	(GPIO_base+0x0730)
   #define 	GPIO_MODE21      	(GPIO_base+0x0740)
   #define 	GPIO_MODE22      	(GPIO_base+0x0750)
   #define 	GPIO_MODE23      	(GPIO_base+0x0760)
   #define 	GPIO_MODE24      	(GPIO_base+0x0770)
   #define 	GPIO_MODE25      	(GPIO_base+0x0780)
   #define 	GPIO_MODE26      	(GPIO_base+0x0790)
   #define 	GPIO_MODE27      	(GPIO_base+0x07A0)
         
   #define  CLKO_MODE0      	(GPIO_base+0x0900)
   #define  CLKO_MODE1      	(GPIO_base+0x0910)
   #define  CLKO_MODE2      	(GPIO_base+0x0920)
   #define  CLKO_MODE3      	(GPIO_base+0x0930)
   #define  CLKO_MODE4      	(GPIO_base+0x0940)
   #define  CLKO_MODE5      	(GPIO_base+0x0950)
   #define  CLKO_MODE6      	(GPIO_base+0x0960)

   #define 	GPIO_DIR1_SET       	 (GPIO_DIR1+0x04)
   #define 	GPIO_PULLEN1_SET    	 (GPIO_PULLEN1+0x04)
   #define 	GPIO_PULLSEL1_SET   	 (GPIO_PULLSEL1+0x04)
   #define 	GPIO_DOUT1_SET      	 (GPIO_DOUT1+0x04)
   #define 	GPIO_MODE1_SET      	 (GPIO_MODE1+0x04)
   #define  GPIO_DINV_ADRS(n)	  	 (GPIO_DINV1+0x10*(n))
   #define  GPIO_MODE_SET(_no)  	 (GPIO_MODE1_SET+(0x10*(_no)))
   #define  GPIO_DIR_SET(_no)   	 (GPIO_DIR1_SET+(0x10*(_no)))
   #define  GPIO_DOUT_SET(_no)  	 (GPIO_DOUT1_SET+(0x10*(_no)))
   #define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x10*(_no)))
   #define  GPIO_PULLSEL_SET(_no) (GPIO_PULLSEL1_SET+(0x10*(_no)))
   
   #define 	GPIO_DIR1_CLR       	 (GPIO_DIR1+0x08)
   #define 	GPIO_PULLEN1_CLR    	 (GPIO_PULLEN1+0x08)
   #define 	GPIO_PULLSEL1_CLR   	 (GPIO_PULLSEL1+0x08)
   #define 	GPIO_DOUT1_CLR     	 (GPIO_DOUT1+0x08)
   #define 	GPIO_MODE1_CLR      	 (GPIO_MODE1+0x08)    
   #define  GPIO_MODE_CLR(_no)  	 (GPIO_MODE1_CLR+(0x10*(_no)))
   #define  GPIO_DIR_CLR(_no)   	 (GPIO_DIR1_CLR+(0x10*(_no)))
   #define  GPIO_DOUT_CLR(_no)  	 (GPIO_DOUT1_CLR+(0x10*(_no)))
   #define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN1_CLR+(0x10*(_no)))  
   #define  GPIO_PULLSEL_CLR(_no) (GPIO_PULLSEL1_CLR+(0x10*(_no)))  
   
   #define  GPIO_MODE(_no)      	(GPIO_MODE1+(0x10*(_no))) 
   #define  GPIO_DOUT(_no)      	(GPIO_DOUT1+(0x10*(_no)))
   #define  GPIO_DIR(_no)       	(GPIO_DIR1+(0x10*(_no)))
   #define  GPIO_DIN(_no)       	(GPIO_DIN1+(0x10*(_no)))
   #define  GPIO_PULLEN(_no)    	(GPIO_PULLEN1+(0x10*(_no)))
   #define  GPIO_PULLSEL(_no)   	(GPIO_PULLSEL1+(0x10*(_no)))
   #define  CLKO_MODE(_no)      	(CLKO_MODE0+(0x10*(_no)))  
   #define  CLKO_NUM              6
#endif   /*defined(DRV_GPIO_REG_AS_6256)*/

#if defined(DRV_GPIO_REG_AS_6280)

#define  GPIO_DIR1			(GPIO_base+0x0000)
#define  GPIO_DIR2			(GPIO_base+0x0040)
#define  GPIO_DIR3		   (GPIO_base+0x0080)
#define  GPIO_DIR4		   (GPIO_base+0x00c0)
#define  GPIO_DIR5		   (GPIO_base+0x0100) 
#define  GPIO_DIR6		   (GPIO_base+0x0140)  
#define  GPIO_DIR7		   (GPIO_base+0x0180) 

/*********************************************************/

#define    GPIO_PULLEN1		 (GPIO_base+0x0200)
#define    GPIO_PULLEN2		 (GPIO_base+0x0240)
#define    GPIO_PULLEN3	  (GPIO_base+0x0280)
#define    GPIO_PULLEN4		(GPIO_base+0x02c0)
#define    GPIO_PULLEN5		(GPIO_base+0x0300)	
#define 	GPIO_PULLEN6      (GPIO_base+0x0340) 
#define    GPIO_PULLEN7 	 (GPIO_base+0x0380)

/*********************************************************/

#define  GPIO_PULLSEL1		 (GPIO_base+0x0400)
#define  GPIO_PULLSEL2		 (GPIO_base+0x0440)
#define  GPIO_PULLSEL3		 (GPIO_base+0x0480)
#define  GPIO_PULLSEL4	   (GPIO_base+0x04c0)
#define  GPIO_PULLSEL5	   (GPIO_base+0x0500) 
#define  GPIO_PULLSEL6     (GPIO_base+0x0540) 
#define  GPIO_PULLSEL7	   (GPIO_base+0x0580)

/*********************************************************/
#define  GPIO_DINV1 		 (GPIO_base+0x0600)
#define  GPIO_DINV2 		 (GPIO_base+0x0640)
#define  GPIO_DINV3 		 (GPIO_base+0x0680)
#define  GPIO_DINV4 		 (GPIO_base+0x06c0)
#define  GPIO_DINV5 		 (GPIO_base+0x0700) 
#define  GPIO_DINV6		   (GPIO_base+0x0740)
#define  GPIO_DINV7		  (GPIO_base+0x0780) 
/*********************************************************/
#define  GPIO_DOUT1 		 (GPIO_base+0x0800)
#define  GPIO_DOUT2 		 (GPIO_base+0x0840)
#define  GPIO_DOUT3 		 (GPIO_base+0x0880)
#define  GPIO_DOUT4 		 (GPIO_base+0x08c0)
#define  GPIO_DOUT5 		 (GPIO_base+0x0900)
#define   GPIO_DOUT6		  (GPIO_base+0x0940)  
#define   GPIO_DOUT7      	(GPIO_base+0x0980) 
/*********************************************************/
#define  GPIO_DIN1			 (GPIO_base+0x0a00)
#define  GPIO_DIN2			 (GPIO_base+0x0a40)
#define  GPIO_DIN3			 (GPIO_base+0x0a80)
#define  GPIO_DIN4			 (GPIO_base+0x0ac0)
#define  GPIO_DIN5			 (GPIO_base+0x0b00)
#define  GPIO_DIN6		   (GPIO_base+0x0b40)  
#define  GPIO_DIN7 		  (GPIO_base+0x0b80)  
/*********************************************************/
 #define GPIO_MODE0			  (GPIO_base+0x1000)
 #define GPIO_MODE1 		  (GPIO_base+0x1100)
 #define GPIO_MODE2 		  (GPIO_base+0x1200)
 #define GPIO_MODE3 		  (GPIO_base+0x1300)
 #define GPIO_MODE4 		  (GPIO_base+0x1400)
 #define GPIO_MODE5 		  (GPIO_base+0x1500)
 #define GPIO_MODE6 		  (GPIO_base+0x1600)
 #define GPIO_MODE7 		  (GPIO_base+0x1700)
 #define GPIO_MODE8 		  (GPIO_base+0x1800)
 #define GPIO_MODE9 		  (GPIO_base+0x1900)
 #define GPIO_MODE10 		  (GPIO_base+0x1A00)
 #define GPIO_MODE11 		  (GPIO_base+0x1B00)
 #define GPIO_MODE12		  (GPIO_base+0x1C00)
 #define GPIO_MODE13		  (GPIO_base+0x1D00)
 #define GPIO_MODE14		  (GPIO_base+0x1E00)
 #define GPIO_MODE15 		  (GPIO_base+0x1F00)
 #define GPIO_MODE16		  (GPIO_base+0x2000)
 #define GPIO_MODE17		  (GPIO_base+0x2100)
 #define GPIO_MODE18		  (GPIO_base+0x2200)
 #define GPIO_MODE19		  (GPIO_base+0x2300)
 #define GPIO_MODE20		  (GPIO_base+0x2400)
 #define GPIO_MODE21		  (GPIO_base+0x2500)
 #define GPIO_MODE22		  (GPIO_base+0x2600)
 #define GPIO_MODE23		  (GPIO_base+0x2700)
 #define GPIO_MODE24		  (GPIO_base+0x2800)
 /*********************************************************/
#define  GPIO_OTHER          (GPIO_base+0x5c00)

/*********************************************************/
#define  CLKO_MODE1 	 (GPIO_base+0x7000)
#define  CLKO_MODE2 	 (GPIO_base+0x7100)   

/*********************************************************/



#define  GPIO_DINV_ADRS(n)	(GPIO_DINV1+0x40*(n))  
	
   #define 	GPIO_DIR1_SET       (GPIO_DIR1+0x04)    
   #define 	GPIO_PULLEN1_SET    (GPIO_PULLEN1+0x04)      
   #define 	GPIO_PULLSEL1_SET   (GPIO_PULLSEL1+0x04)      
   #define 	GPIO_DOUT1_SET      (GPIO_DOUT1+0x04)    
   #define 	GPIO_MODE1_SET      (GPIO_MODE0+0x04)        
   #define  GPIO_MODE_SET(_no)  (GPIO_MODE1_SET+(0x100*(_no)))
   #define  GPIO_DIR_SET(_no)   (GPIO_DIR1_SET+(0x40*(_no)))  
   #define  GPIO_DOUT_SET(_no)  (GPIO_DOUT1_SET+(0x40*(_no)))  
   #define  GPIO_PULLEN_SET(_no)  (GPIO_PULLEN1_SET+(0x40*(_no)))  
   #define  GPIO_PULLSEL_SET(_no)  (GPIO_PULLSEL1_SET+(0x40*(_no)))  
	#define  GPIO_OTHER_SET      (GPIO_OTHER+0x04)
	
   #define 	GPIO_DIR1_CLR       (GPIO_DIR1+0x08)         
   #define 	GPIO_PULLEN1_CLR    (GPIO_PULLEN1+0x08)         
   #define 	GPIO_PULLSEL1_CLR   (GPIO_PULLSEL1+0x08)         
   #define 	GPIO_DOUT1_CLR      (GPIO_DOUT1+0x08)         
   #define 	GPIO_MODE1_CLR      (GPIO_MODE0+0x08)         
   #define  GPIO_MODE_CLR(_no)  (GPIO_MODE1_CLR+(0x100*(_no)))
   #define  GPIO_DIR_CLR(_no)   (GPIO_DIR1_CLR+(0x40*(_no)))
   #define  GPIO_DOUT_CLR(_no)  (GPIO_DOUT1_CLR+(0x40*(_no)))
   #define  GPIO_PULLEN_CLR(_no)  (GPIO_PULLEN1_CLR+(0x40*(_no)))  
   #define  GPIO_PULLSEL_CLR(_no)  (GPIO_PULLSEL1_CLR+(0x40*(_no)))  
	#define  GPIO_OTHER_CLR      (GPIO_OTHER+0x08)

	
   #define  GPIO_MODE(_no)      (GPIO_MODE0+(0x100*(_no))) 
   #define  GPIO_DOUT(_no)      (GPIO_DOUT1+(0x40*(_no)))
   #define  GPIO_DIR(_no)       (GPIO_DIR1+(0x40*(_no)))
   #define  GPIO_DIN(_no)       (GPIO_DIN1+(0x40*(_no)))
   #define  GPIO_PULLEN(_no)    (GPIO_PULLEN1+(0x40*(_no)))
   #define  GPIO_PULLSEL(_no)   (GPIO_PULLSEL1+(0x40*(_no))) 
 

   #define  CLKO_MODE(_no)      (CLKO_MODE1+(0x100*(_no)))  
   #define  CLKO_NUM            2

#endif //defined(DRV_GPIO_REG_AS_6280)




#endif /*!defined(DRV_GPIO_OFF)*/
#endif   /*_GPIO_HW_H*/

