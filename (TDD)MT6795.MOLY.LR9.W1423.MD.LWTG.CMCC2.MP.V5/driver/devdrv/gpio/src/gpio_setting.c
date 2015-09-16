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
 *    gpio_setting.c
 *
 * Project:
 * --------
 *   Dragonfly
 *
 * Description:
 * ------------
 *   This Module defines the GPIO and GPO settings.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __CUST_NEW__
#include "gpio_def.h"
#include "drv_comm.h"
#include "reg_base.h"
//#include "gpio_hw.h"
//#include "gpio_sw.h"
#include "gpio_drv.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

#include "kal_general_types.h"
#include "drv_gpio.h"
#include "drvpdn.h"


#define GPIO_PORTNULL_MODE  0
#define GPO_PORTNULL_MODE  0
#define GPIO_PORTNULL_DIR   0
#define GPIO_PORTNULL_PULL  0
#define GPIO_PORTNULL_INV   0
#define GPIO_PORTNULL_OUTPUT_LEVEL  0
#define GPO_PORTNULL_OUTPUT_LEVEL  0
#define GPIO_PORTNULL_PULL_SEL  0

#define MODE0_GPIONULL     0
#define MODE1_GPIONULL     0
#define MODE2_GPIONULL     0
#define MODE3_GPIONULL     0
#define MODE4_GPIONULL     0
#define MODE5_GPIONULL     0
#define MODE6_GPIONULL     0
#define MODE7_GPIONULL     0

#define DIR_OUT_GPIONULL   0
#define DIR_IN_GPIONULL   0

/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/******** If DRV_GPIO is not off, we will open to use  GPIO_DRV_TOOL ****************/
#if !defined(GPIO_DUMMY_FUN)

#if !defined(DRV_GPIO_OFF)    
    #if defined(DRV_GPIO_REG_AS_6205B) || defined(DRV_GPIO_REG_AS_6218B) || defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_TK6516) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6270A) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6251) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6253E_1)|| defined(DRV_GPIO_REG_AS_6256)||defined(DRV_GPIO_REG_AS_6290)
       #define __CHIP_SUPP_GPIO_DRV_TOOL__
    #else
       #error "No support driver customization tool for this chip."
    #endif
#endif //#if !defined(DRV_GPIO_OFF)

#endif


/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/***************General macro to calculate GPIO MODE register************************/


#if defined(DRV_GPIO_MODE_4BITS)
   #if defined(GPIO_MODE_32BIT_LENGTH)
      #define GPIO_MODE_4BITS_REG_VAL(port0, port1, port2, port3, port4, port5, port6, port7) \
          ((GPIO_PORT##port0##_MODE) | (GPIO_PORT##port1##_MODE<<4) | (GPIO_PORT##port2##_MODE<<8) |    \
          (GPIO_PORT##port3##_MODE<<12) | (GPIO_PORT##port4##_MODE<<16) | (GPIO_PORT##port5##_MODE<<20) | \
          (GPIO_PORT##port6##_MODE<<24) | (GPIO_PORT##port7##_MODE<<28))
   #else //defined(GPIO_MODE_32BIT_LENGTH)
     /* General macro to calculate GPIO MODE (with 4 bits per mode) register. */
       #define GPIO_MODE_4BITS_REG_VAL(port0, port1, port2, port3)                 \
          ((GPIO_PORT##port0##_MODE) | (GPIO_PORT##port1##_MODE<<4) | (GPIO_PORT##port2##_MODE<<8) |    \
          (GPIO_PORT##port3##_MODE<<12))
   #endif // define(GPIO_MODE_32BIT_LENGTH)
#elif defined(DRV_GPIO_MODE_3BITS)
	#define GPIO_MODE_3BITS_REG_VAL(port0,port1,port2,port3,port4)	\
		((GPIO_PORT##port0##_MODE) | (GPIO_PORT##port1##_MODE<<3) | (GPIO_PORT##port2##_MODE<<6) |	  \
		(GPIO_PORT##port3##_MODE<<9) | (GPIO_PORT##port4##_MODE<<12))
#else //defined(DRV_GPIO_MODE_4BITS)

    #define GPIO_MODE_REG_VAL(port0, port1, port2, port3, port4, port5, port6, port7)                 \
      ((GPIO_PORT##port0##_MODE) | (GPIO_PORT##port1##_MODE<<2) | (GPIO_PORT##port2##_MODE<<4) |    \
      (GPIO_PORT##port3##_MODE<<6) | (GPIO_PORT##port4##_MODE<<8) | (GPIO_PORT##port5##_MODE<<10) | \
      (GPIO_PORT##port6##_MODE<<12) | (GPIO_PORT##port7##_MODE<<14))
#endif //defined(DRV_GPIO_MODE_4BITS)


/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/****************** General macro to calculate GPO MODE register********************/


#define GPO_MODE_REG_VAL(port0, port1, port2, port3, port4, port5, port6, port7)                 \
    ((GPO_PORT##port0##_MODE) | (GPO_PORT##port1##_MODE<<2) | (GPO_PORT##port2##_MODE<<4) |    \
    (GPO_PORT##port3##_MODE<<6) | (GPO_PORT##port4##_MODE<<8) | (GPO_PORT##port5##_MODE<<10) | \
    (GPO_PORT##port6##_MODE<<12) | (GPO_PORT##port7##_MODE<<14))



/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/************* General macro to calculate GPIO register with 1 bit unit**************/

#if !defined(DRV_GPIO_REG_AS_6290)
#define GPIO_HWORD_REG_FOR_1BIT(name, port0, port1, port2, port3, port4, port5, port6, port7, port8, port9, \
                                port10, port11, port12, port13, port14, port15)	\
    ((GPIO_PORT##port0##_##name) | (GPIO_PORT##port1##_##name<<1) | (GPIO_PORT##port2##_##name<<2) |         \
    (GPIO_PORT##port3##_##name<<3) | (GPIO_PORT##port4##_##name<<4) | (GPIO_PORT##port5##_##name<<5) |       \
    (GPIO_PORT##port6##_##name<<6) | (GPIO_PORT##port7##_##name<<7) | (GPIO_PORT##port8##_##name<<8) |       \
    (GPIO_PORT##port9##_##name<<9) | (GPIO_PORT##port10##_##name<<10) | (GPIO_PORT##port11##_##name<<11) |   \
    (GPIO_PORT##port12##_##name<<12) | (GPIO_PORT##port13##_##name<<13) | (GPIO_PORT##port14##_##name<<14) | \
    (GPIO_PORT##port15##_##name<<15))
#else
#define GPIO_HWORD_REG_FOR_1BIT(name, port0, port1, port2, port3, port4, port5, port6, port7, port8, port9, \
                                port10, port11, port12, port13, port14, port15, port16, port17, port18, port19,\
                                port20,port21, port22, port23, port24, port25, port26, port27, port28, port29, \
                                port30, port31)	\
    ((GPIO_PORT##port0##_##name) | (GPIO_PORT##port1##_##name<<1) | (GPIO_PORT##port2##_##name<<2) |         \
    (GPIO_PORT##port3##_##name<<3) | (GPIO_PORT##port4##_##name<<4) | (GPIO_PORT##port5##_##name<<5) |       \
    (GPIO_PORT##port6##_##name<<6) | (GPIO_PORT##port7##_##name<<7) | (GPIO_PORT##port8##_##name<<8) |       \
    (GPIO_PORT##port9##_##name<<9) | (GPIO_PORT##port10##_##name<<10) | (GPIO_PORT##port11##_##name<<11) |   \
    (GPIO_PORT##port12##_##name<<12) | (GPIO_PORT##port13##_##name<<13) | (GPIO_PORT##port14##_##name<<14) | \
    (GPIO_PORT##port15##_##name<<15) | (GPIO_PORT##port16##_##name<<16) | (GPIO_PORT##port17##_##name<<17) | \
    (GPIO_PORT##port18##_##name<<18) | (GPIO_PORT##port19##_##name<<19) | (GPIO_PORT##port20##_##name<<20) | \
    (GPIO_PORT##port21##_##name<<21) | (GPIO_PORT##port22##_##name<<22) | (GPIO_PORT##port23##_##name<<23) | \
    (GPIO_PORT##port24##_##name<<24) | (GPIO_PORT##port25##_##name<<25) | (GPIO_PORT##port26##_##name<<26) | \
    (GPIO_PORT##port27##_##name<<27) | (GPIO_PORT##port28##_##name<<28) | (GPIO_PORT##port29##_##name<<29) | \
    (GPIO_PORT##port30##_##name<<30) | (GPIO_PORT##port31##_##name<<31)) 
#endif

/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/***************** General macro to calculate GPO register with 1 bit unit.**********/

#define GPO_HWORD_REG_FOR_1BIT(name, port0, port1, port2, port3, port4, port5, port6, port7, port8, port9, \
                                port10, port11, port12, port13, port14, port15)	\
    ((GPO_PORT##port0##_##name) | (GPO_PORT##port1##_##name<<1) | (GPO_PORT##port2##_##name<<2) |         \
    (GPO_PORT##port3##_##name<<3) | (GPO_PORT##port4##_##name<<4) | (GPO_PORT##port5##_##name<<5) |       \
    (GPO_PORT##port6##_##name<<6) | (GPO_PORT##port7##_##name<<7) | (GPO_PORT##port8##_##name<<8) |       \
    (GPO_PORT##port9##_##name<<9) | (GPO_PORT##port10##_##name<<10) | (GPO_PORT##port11##_##name<<11) |   \
    (GPO_PORT##port12##_##name<<12) | (GPO_PORT##port13##_##name<<13) | (GPO_PORT##port14##_##name<<14) | \
    (GPO_PORT##port15##_##name<<15))


/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
/*****General macro to calculate GPIO word-length variable value with 1 bit unit.****/


#define GPIO_WORD_VAR_FOR_1BIT(name, port0, port1, port2, port3, port4, port5, port6, port7, port8, port9, port10, \
	                            port11, port12, port13, port14, port15, port16, port17, port18, port19, port20, port21, \
                               port22, port23, port24, port25, port26, port27, port28, port29, port30, port31) \
    ((name##_GPIO##port0) | (name##_GPIO##port1<<1) | (name##_GPIO##port2<<2) | (name##_GPIO##port3<<3) | (name##_GPIO##port4<<4) | \
    (name##_GPIO##port5<<5) | (name##_GPIO##port6<<6) | (name##_GPIO##port7<<7) | (name##_GPIO##port8<<8) | (name##_GPIO##port9<<9) | \
    (name##_GPIO##port10<<10) | (name##_GPIO##port11<<11) | (name##_GPIO##port12<<12) | (name##_GPIO##port13<<13) | (name##_GPIO##port14<<14) | \
    (name##_GPIO##port15<<15) | (name##_GPIO##port16<<16) | (name##_GPIO##port17<<17) | (name##_GPIO##port18<<18) | (name##_GPIO##port19<<19) | \
    (name##_GPIO##port20<<20) | (name##_GPIO##port21<<21) | (name##_GPIO##port22<<22) | (name##_GPIO##port23<<23) | (name##_GPIO##port24<<24) | \
    (name##_GPIO##port25<<25) | (name##_GPIO##port26<<26) | (name##_GPIO##port27<<27) | (name##_GPIO##port28<<28) | (name##_GPIO##port29<<29) | \
    (name##_GPIO##port30<<30) | (name##_GPIO##port31<<31))



/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/*********************************__CHIP_SUPP_GPIO_DRV_TOOL__****************************/

#if defined(__CHIP_SUPP_GPIO_DRV_TOOL__)

/***************************GPIO MODE IS NEITHER 4 BIT NOR 3 BIT**********START*********/

#if !defined(DRV_GPIO_MODE_4BITS) && !defined(DRV_GPIO_MODE_3BITS)
   /* GPIO mode register values for different platforms. */

  #if defined(DRV_GPIO_REG_AS_TK6516)
      #define GPIO_MODE_REG1  GPIO_MODE_REG_VAL(0, 1, 2, 3, NULL, NULL, NULL, NULL)
  #else /* DRV_GPIO_REG_AS_TK6516 */
     #define GPIO_MODE_REG1  GPIO_MODE_REG_VAL(0, 1, 2, 3, 4, 5, 6, 7)
     #define GPIO_MODE_REG2  GPIO_MODE_REG_VAL(8, 9, 10, 11, 12, 13, 14, 15)
     #if defined(DRV_GPIO_REG_AS_6205B)
         #define GPIO_MODE_REG3  GPIO_MODE_REG_VAL(16, 17, 18, 19, 20, 21, NULL, NULL)
         #define GPO_MODE_REG    GPO_MODE_REG_VAL(0, 1, 2, 3, NULL, NULL, NULL, NULL)
     #elif defined(DRV_GPIO_REG_AS_6270A)
          #define GPIO_MODE_REG3  GPIO_MODE_REG_VAL(16, 17, 18, 19, 20, 21, 22, 23)
          #define GPIO_MODE_REG4  GPIO_MODE_REG_VAL(24, 25, 26, 27, NULL, NULL, NULL, NULL)
     #else /* DRV_GPIO_REG_AS_6270A */
          #define GPIO_MODE_REG3  GPIO_MODE_REG_VAL(16, 17, 18, 19, 20, 21, 22, 23)
          #define GPIO_MODE_REG4  GPIO_MODE_REG_VAL(24, 25, 26, 27, 28, 29, 30, 31)
          #define GPIO_MODE_REG5  GPIO_MODE_REG_VAL(32, 33, 34, 35, 36, 37, 38, 39)
          #define GPIO_MODE_REG6  GPIO_MODE_REG_VAL(40, 41, 42, 43, 44, 45, 46, 47)
         #if defined(DRV_GPIO_REG_AS_6218B)
              #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, NULL, NULL, NULL, NULL, NULL)
         #elif defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6225)
             #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, 53, 54, NULL)
             #if defined(DRV_GPIO_REG_AS_6219)
                 #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, 3, 4, NULL, NULL, NULL)
             #elif defined(DRV_GPIO_REG_AS_6225)
                 #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, 3, NULL, NULL, NULL, NULL)
             #endif
         #elif defined(DRV_GPIO_REG_AS_6227)
             #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, 53, 54, 55)
             #define GPIO_MODE_REG8  GPIO_MODE_REG_VAL(56, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
             #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, 3, 4, NULL, NULL, NULL)
        #elif defined(DRV_GPIO_REG_AS_6228)
            #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, 53, 54, 55)
            #define GPIO_MODE_REG8  GPIO_MODE_REG_VAL(56, 57, 58, 59, 60, 61, 62, 63)
            #define GPIO_MODE_REG9  GPIO_MODE_REG_VAL(64, 65, 66, 67, 68, 69, 70, 71)
            #define GPIO_MODE_REG10  GPIO_MODE_REG_VAL(72, 73, 74, NULL, NULL, NULL, NULL, NULL)
            #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, NULL, NULL, NULL, NULL, NULL)
        #elif defined(DRV_GPIO_REG_AS_6223)
            #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, NULL, NULL, NULL)
        #elif defined(DRV_GPIO_REG_AS_6238)  || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E)
            #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, 53, 54, 55)
            #define GPIO_MODE_REG8  GPIO_MODE_REG_VAL(56, 57, 58, 59, 60, 61, 62, 63)
         #if defined(DRV_GPIO_REG_AS_6236) 
            #define GPIO_MODE_REG9  GPIO_MODE_REG_VAL(64, 65, 66, 67, NULL, NULL, NULL, NULL)
         #else // defined(DRV_GPIO_REG_AS_6236) 
            #define GPIO_MODE_REG9  GPIO_MODE_REG_VAL(64, 65, 66, 67, 68, 69, 70, 71)
            #if defined(DRV_GPIO_REG_AS_6238)
               #define GPIO_MODE_REGA  GPIO_MODE_REG_VAL(72, 73, 74, 75, 76, 77, 78, 79)
               #define GPIO_MODE_REGB  GPIO_MODE_REG_VAL(80, 81, 82, 83, 84, NULL, NULL, NULL)
            #elif defined(DRV_GPIO_REG_AS_6235)
               #define GPIO_MODE_REGA  GPIO_MODE_REG_VAL(72, 73, 74, 75, 76, 77, 78, NULL)
            #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
               #define GPIO_MODE_REGA  GPIO_MODE_REG_VAL(72, 73, 74, 75, 76, 77, 78, 79)
               #define GPIO_MODE_REGB  GPIO_MODE_REG_VAL(80, 81, 82, 83, 84, 85, 86, 87)
               #define GPIO_MODE_REGC  GPIO_MODE_REG_VAL(88, 89, 90, 91, 92, 93, 94, 95)
               #if defined(DRV_GPIO_REG_AS_6268A)
               #define GPIO_MODE_REGD  GPIO_MODE_REG_VAL(96, 97, 98, 99, 100, NULL, NULL, NULL)
               #elif defined(DRV_GPIO_REG_AS_6268)
               #define GPIO_MODE_REGD  GPIO_MODE_REG_VAL(96, 97, 98, 99, NULL, NULL, NULL, NULL)
               #elif defined(DRV_GPIO_REG_AS_6276)
               #define GPIO_MODE_REGD  GPIO_MODE_REG_VAL(96, 97, 98, 99, 100, 101, 102, 103)
               #define GPIO_MODE_REGE  GPIO_MODE_REG_VAL(104, 105, 106, 107, 108, NULL, NULL, NULL)
               #endif
            #elif defined(DRV_GPIO_REG_AS_6253T)
               #define GPIO_MODE_REGA  GPIO_MODE_REG_VAL(72, 73, 74, 75, 76, 77, 78, 79)
               #if defined(DRV_GPIO_6253_MODE11_DEFAULT)
                  #define GPIO_PORT82FOR6253_MODE MODE_1 //GPIO82 for MT6253 should be fixed to mode1
                  #define GPIO_MODE_REGB  GPIO_MODE_REG_VAL(80, 81, 82FOR6253, NULL, NULL, NULL, NULL, NULL)
               #else //defined(DRV_GPIO_6253_MODE11_DEFAULT)
               #define GPIO_MODE_REGB  GPIO_MODE_REG_VAL(80, 81, NULL, NULL, NULL, NULL, NULL, NULL)
               #endif //defined(DRV_GPIO_6253_MODE11_DEFAULT)
            #endif
         #endif // defined(DRV_GPIO_REG_AS_6236) 
      #endif
   #endif /* DRV_GPIO_REG_AS_6205B */
#endif /* DRV_GPIO_REG_AS_TK6516 */


/***************************GPIO MODE IS NEITHER 4 BIT NOR 3 BIT**********END*********/


/***************************GPIO MODE IS 4 BIT ***********************START***********/

#elif defined(DRV_GPIO_MODE_4BITS) // DRV_GPIO_MODE_4BITS is defined
#if defined(DRV_GPIO_REG_AS_6253E_1)
   #define GPIO_MODE_REG1  GPIO_MODE_4BITS_REG_VAL(0, 1, 2, 3, 4, 5, 6, 7)
   #define GPIO_MODE_REG2  GPIO_MODE_4BITS_REG_VAL(8, 9, 10, 11, 12, 13, 14, 15)
   #define GPIO_MODE_REG3  GPIO_MODE_4BITS_REG_VAL(16, 17, 18, 19, 20, 21, 22, 23)
   #define GPIO_MODE_REG4  GPIO_MODE_4BITS_REG_VAL(24, 25, 26, 27, 28, 29, 30, 31)
   #define GPIO_MODE_REG5  GPIO_MODE_4BITS_REG_VAL(32, 33, 34, 35, 36, 37, 38, 39)
   #define GPIO_MODE_REG6  GPIO_MODE_4BITS_REG_VAL(40, 41, 42, 43, 44, 45, 46, 47)
   #define GPIO_MODE_REG7  GPIO_MODE_4BITS_REG_VAL(48, 49, 50, 51, 52, 53, 54, 55)
   #define GPIO_MODE_REG8  GPIO_MODE_4BITS_REG_VAL(56, 57, 58, 59, 60, 61, 62, 63)
   #define GPIO_MODE_REG9  GPIO_MODE_4BITS_REG_VAL(64, 65, 66, 67, 68, 69, 70, NULL)
#endif //defined(DRV_GPIO_REG_AS_6253E_1)
#if defined(DRV_GPIO_REG_AS_6255) 
   #define GPIO_MODE_REG1  GPIO_MODE_4BITS_REG_VAL(0, 1, 2, 3)
   #define GPIO_MODE_REG2  GPIO_MODE_4BITS_REG_VAL(4, 5, 6, 7)
   #define GPIO_MODE_REG3  GPIO_MODE_4BITS_REG_VAL(8, 9, 10, 11)
   #define GPIO_MODE_REG4  GPIO_MODE_4BITS_REG_VAL(12, 13, 14, 15)
   #define GPIO_MODE_REG5  GPIO_MODE_4BITS_REG_VAL(16, 17, 18, 19)
   #define GPIO_MODE_REG6  GPIO_MODE_4BITS_REG_VAL(20, 21, 22, 23)
   #define GPIO_MODE_REG7  GPIO_MODE_4BITS_REG_VAL(24, 25, 26, 27)
   #define GPIO_MODE_REG8  GPIO_MODE_4BITS_REG_VAL(28, 29, 30, 31)
   #define GPIO_MODE_REG9  GPIO_MODE_4BITS_REG_VAL(32, 33, 34, 35)
   #define GPIO_MODE_REG10  GPIO_MODE_4BITS_REG_VAL(36, 37, 38, 39)
   #define GPIO_MODE_REG11  GPIO_MODE_4BITS_REG_VAL(40, 41, 42, 43)
   #define GPIO_MODE_REG12  GPIO_MODE_4BITS_REG_VAL(44, 45, 46, 47)
   #define GPIO_MODE_REG13  GPIO_MODE_4BITS_REG_VAL(48, 49, 50, 51)
   #define GPIO_MODE_REG14  GPIO_MODE_4BITS_REG_VAL(52, 53, 54, 55)
   #define GPIO_MODE_REG15  GPIO_MODE_4BITS_REG_VAL(56, 57, 58, 59)
   #define GPIO_MODE_REG16  GPIO_MODE_4BITS_REG_VAL(60, 61, 62, 63)
   #define GPIO_MODE_REG17  GPIO_MODE_4BITS_REG_VAL(64, 65, 66, 67)
   #define GPIO_MODE_REG18  GPIO_MODE_4BITS_REG_VAL(68, 69, 70, 71)
   #define GPIO_MODE_REG19  GPIO_MODE_4BITS_REG_VAL(72, 73, 74, 75)
   #define GPIO_MODE_REG20  GPIO_MODE_4BITS_REG_VAL(76, 77, 78, 79)
   #define GPIO_MODE_REG21  GPIO_MODE_4BITS_REG_VAL(80, 81, 82, 83)
   #define GPIO_MODE_REG22  GPIO_MODE_4BITS_REG_VAL(84, 85, 86, 87)
#define GPIO_MODE_REG23  GPIO_MODE_4BITS_REG_VAL(88, 89, 90, 91)
#define GPIO_MODE_REG24  GPIO_MODE_4BITS_REG_VAL(92, 93, 94, 95)
#define GPIO_MODE_REG25  GPIO_MODE_4BITS_REG_VAL(96, 97, 98, 99)
#define GPIO_MODE_REG26  GPIO_MODE_4BITS_REG_VAL(100, 101, 102,103)
#define GPIO_MODE_REG27  GPIO_MODE_4BITS_REG_VAL(104, NULL, NULL,NULL)

 #endif 
#if defined(DRV_GPIO_REG_AS_6256)
   #define GPIO_MODE_REG1  GPIO_MODE_4BITS_REG_VAL(0, 1, 2, 3)
   #define GPIO_MODE_REG2  GPIO_MODE_4BITS_REG_VAL(4, 5, 6, 7)
   #define GPIO_MODE_REG3  GPIO_MODE_4BITS_REG_VAL(8, 9, 10, 11)
   #define GPIO_MODE_REG4  GPIO_MODE_4BITS_REG_VAL(12, 13, 14, 15)
   #define GPIO_MODE_REG5  GPIO_MODE_4BITS_REG_VAL(16, 17, 18, 19)
   #define GPIO_MODE_REG6  GPIO_MODE_4BITS_REG_VAL(20, 21, 22, 23)
   #define GPIO_MODE_REG7  GPIO_MODE_4BITS_REG_VAL(24, 25, 26, 27)
   #define GPIO_MODE_REG8  GPIO_MODE_4BITS_REG_VAL(28, 29, 30, 31)
   #define GPIO_MODE_REG9  GPIO_MODE_4BITS_REG_VAL(32, 33, 34, 35)
   #define GPIO_MODE_REG10  GPIO_MODE_4BITS_REG_VAL(36, 37, 38, 39)
   #define GPIO_MODE_REG11  GPIO_MODE_4BITS_REG_VAL(40, 41, 42, 43)
   #define GPIO_MODE_REG12  GPIO_MODE_4BITS_REG_VAL(44, 45, 46, 47)
   #define GPIO_MODE_REG13  GPIO_MODE_4BITS_REG_VAL(48, 49, 50, 51)
   #define GPIO_MODE_REG14  GPIO_MODE_4BITS_REG_VAL(52, 53, 54, 55)
   #define GPIO_MODE_REG15  GPIO_MODE_4BITS_REG_VAL(56, 57, 58, 59)
   #define GPIO_MODE_REG16  GPIO_MODE_4BITS_REG_VAL(60, 61, 62, 63)
   #define GPIO_MODE_REG17  GPIO_MODE_4BITS_REG_VAL(64, 65, 66, 67)
   #define GPIO_MODE_REG18  GPIO_MODE_4BITS_REG_VAL(68, 69, 70, 71)
   #define GPIO_MODE_REG19  GPIO_MODE_4BITS_REG_VAL(72, 73, 74, 75)
   #define GPIO_MODE_REG20  GPIO_MODE_4BITS_REG_VAL(76, 77, 78, 79)
   #define GPIO_MODE_REG21  GPIO_MODE_4BITS_REG_VAL(80, 81, 82, 83)
   #define GPIO_MODE_REG22  GPIO_MODE_4BITS_REG_VAL(84, 85, 86, 87)
   #define GPIO_MODE_REG23  GPIO_MODE_4BITS_REG_VAL(88, 89, 90, 91)
   #define GPIO_MODE_REG24  GPIO_MODE_4BITS_REG_VAL(92, 93, 94, 95)
   #define GPIO_MODE_REG25  GPIO_MODE_4BITS_REG_VAL(96, 97, 98, 99)
   #define GPIO_MODE_REG26  GPIO_MODE_4BITS_REG_VAL(100, 101, 102, 103)
   #define GPIO_MODE_REG27  GPIO_MODE_4BITS_REG_VAL(104, NULL, NULL, NULL)
#endif      
#if defined(DRV_GPIO_REG_AS_6251)
   #define GPIO_MODE_REG1  GPIO_MODE_4BITS_REG_VAL(0, 1, 2, 3)
   #define GPIO_MODE_REG2  GPIO_MODE_4BITS_REG_VAL(4, 5, 6, 7)
   #define GPIO_MODE_REG3  GPIO_MODE_4BITS_REG_VAL(8, 9, 10, 11)
   #define GPIO_MODE_REG4  GPIO_MODE_4BITS_REG_VAL(12, 13, 14, 15)
   #define GPIO_MODE_REG5  GPIO_MODE_4BITS_REG_VAL(16, 17, 18, 19)
   #define GPIO_MODE_REG6  GPIO_MODE_4BITS_REG_VAL(20, 21, 22, 23)
   #define GPIO_MODE_REG7  GPIO_MODE_4BITS_REG_VAL(24, 25, 26, 27)
   #define GPIO_MODE_REG8  GPIO_MODE_4BITS_REG_VAL(28, 29, 30, 31)
#endif // defined(DRV_GPIO_REG_AS_6255)

/***************************GPIO MODE IS NEITHER 4 BIT *********END**********/

/***************************GPIO MODE IS 3 BIT******************START********/
#elif defined(DRV_GPIO_MODE_3BITS)
#if defined(DRV_GPIO_REG_AS_6276)
    #define GPIO_MODE_REG0	GPIO_MODE_3BITS_REG_VAL(0, 1, 2, 3, 4)
    #define GPIO_MODE_REG1	GPIO_MODE_3BITS_REG_VAL(5, 6, 7, 8, 9)
    #define GPIO_MODE_REG2	GPIO_MODE_3BITS_REG_VAL(10, 11, 12, 13, 14)
    #define GPIO_MODE_REG3	GPIO_MODE_3BITS_REG_VAL(15, 16, 17, 18, 19)
    #define GPIO_MODE_REG4	GPIO_MODE_3BITS_REG_VAL(20, 21, 22, 23, 24)
    #define GPIO_MODE_REG5	GPIO_MODE_3BITS_REG_VAL(25, 26, 27, 28, 29)	
    #define GPIO_MODE_REG6	GPIO_MODE_3BITS_REG_VAL(30, 31, 32, 33, 34)
    #define GPIO_MODE_REG7	GPIO_MODE_3BITS_REG_VAL(35, 36, 37, 38, 39)
    #define GPIO_MODE_REG8	GPIO_MODE_3BITS_REG_VAL(40, 41, 42, 43, 44)	
    #define GPIO_MODE_REG9	GPIO_MODE_3BITS_REG_VAL(45, 46, 47, 48, 49)
    #define GPIO_MODE_REGA	GPIO_MODE_3BITS_REG_VAL(50, 51, 52, 53, 54)
    #define GPIO_MODE_REGB	GPIO_MODE_3BITS_REG_VAL(55, 56, 57, 58, 59)
    #define GPIO_MODE_REGC	GPIO_MODE_3BITS_REG_VAL(60, 61, 62, 63, 64)
    #define GPIO_MODE_REGD	GPIO_MODE_3BITS_REG_VAL(65, 66, 67, 68, 69)
    #define GPIO_MODE_REGE	GPIO_MODE_3BITS_REG_VAL(70, 71, 72, 73, 74)
    #define GPIO_MODE_REGF	GPIO_MODE_3BITS_REG_VAL(75, 76, 77, 78, 79)
    #define GPIO_MODE_REG10	GPIO_MODE_3BITS_REG_VAL(80, 81, 82, 83, 84)
    #define GPIO_MODE_REG11	GPIO_MODE_3BITS_REG_VAL(85, 86, 87, 88, 89)
    #define GPIO_MODE_REG12	GPIO_MODE_3BITS_REG_VAL(90, 91, 92, 93, 94)	
    #define GPIO_MODE_REG13	GPIO_MODE_3BITS_REG_VAL(95, 96, 97, 98, 99)
    #define GPIO_MODE_REG14	GPIO_MODE_3BITS_REG_VAL(100, 101, 102, 103, 104)
    #define GPIO_MODE_REG15	GPIO_MODE_3BITS_REG_VAL(105, 106, 107, 108, 109)
#endif //defined(DRV_GPIO_REG_AS_6276)

#endif //!defined(DRV_GPIO_MODE_4BITS) && !defined(DRV_GPIO_MODE_3BITS)

/****************************************************************************************/
/*********************************__CHIP_SUPP_GPIO_DRV_TOOL__****************************/
/*********************************************END****************************************/
/****************************************************************************************/




/*********************************************************************************************/
/*********************************************************************************************/
 /* Macros to calulate GPIO related register value of different platforms with 1 bit unit 
   for different settings, like dirction control pull-up/pull-down enable, inversion control. */
/*****************************************START***********************************************/
/*********************************************************************************************/


#if defined(DRV_GPIO_REG_AS_TK6516)
   #define GPIO_HWORD_REG1(name)  GPIO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, 3, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#else /* DRV_GPIO_REG_AS_TK6516 */
   #if !defined(DRV_GPIO_REG_AS_6290)
   #define GPIO_HWORD_REG1(name)  GPIO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
   #else
   #define GPIO_HWORD_REG1(name)  GPIO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 ,25 ,26 ,27,28, 29 ,30, 31)
   #endif
   #if defined(DRV_GPIO_REG_AS_6205B)
      #define GPO_HWORD_REG1(name)  GPO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, 3, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #define GPIO_HWORD_REG2(name)  GPIO_HWORD_REG_FOR_1BIT(name, 16, 17, 18, 19, 20, 21, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6270A)
      #define GPIO_HWORD_REG2(name)  GPIO_HWORD_REG_FOR_1BIT(name, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6251)
      #define GPIO_HWORD_REG2(name)  GPIO_HWORD_REG_FOR_1BIT(name, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)
      #define GPIO_HWORD_REG3(name)  GPIO_HWORD_REG_FOR_1BIT(name, 32, 33, 34, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #define GPIO_HWORD_REG3_TO_38(name)  GPIO_HWORD_REG_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
   #else /* DRV_GPIO_REG_AS_6270A) */
   	  #if !defined(DRV_GPIO_REG_AS_6290)
      #define GPIO_HWORD_REG2(name)  GPIO_HWORD_REG_FOR_1BIT(name, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)
      #else
	  #define GPIO_HWORD_REG2(name)  GPIO_HWORD_REG_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56 ,57 ,58 ,59,60, 61 ,62, 63)
	  #endif
      #define GPIO_HWORD_REG3(name)  GPIO_HWORD_REG_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47)
      #if defined(DRV_GPIO_REG_AS_6218B)
         #define GPO_HWORD_REG1(name)  GPO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6225)  
         #if defined(DRV_GPIO_REG_AS_6219)
            #define GPO_HWORD_REG1(name)  GPO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, 3, 4, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
         #elif defined(DRV_GPIO_REG_AS_6225)
            #define GPO_HWORD_REG1(name)  GPO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, 3, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
         #endif
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6227)
         #define GPO_HWORD_REG1(name)  GPO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, 3, 4, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6228)
         #define GPO_HWORD_REG1(name)  GPO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6223)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6238)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79)
         #define GPIO_HWORD_REG6(name)  GPIO_HWORD_REG_FOR_1BIT(name, 80, 81, 82, 83, 84, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6235)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6236)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79)
         #define GPIO_HWORD_REG6(name)  GPIO_HWORD_REG_FOR_1BIT(name, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95)
         #if defined(DRV_GPIO_REG_AS_6268A)
         #define GPIO_HWORD_REG7(name)  GPIO_HWORD_REG_FOR_1BIT(name, 96, 97, 98, 99, 100, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
         #elif defined(DRV_GPIO_REG_AS_6268)
         #define GPIO_HWORD_REG7(name)  GPIO_HWORD_REG_FOR_1BIT(name, 96, 97, 98, 99, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
         #elif defined(DRV_GPIO_REG_AS_6276)
         #define GPIO_HWORD_REG7(name)  GPIO_HWORD_REG_FOR_1BIT(name, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, NULL, NULL, NULL)
         #endif
      #elif defined(DRV_GPIO_REG_AS_6253T)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79)
         #define GPIO_HWORD_REG6(name)  GPIO_HWORD_REG_FOR_1BIT(name, 80, 81, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6255)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79)
         #define GPIO_HWORD_REG6(name)  GPIO_HWORD_REG_FOR_1BIT(name, 80, 81, 82, 83, 84, 85, 86, 87, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
         #define GPIO_HWORD_REG7(name)  GPIO_HWORD_REG_FOR_1BIT(name, 96, 97, 98, 99, 100, 101, 102, 103, 104, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#elif defined(DRV_GPIO_REG_AS_6253E)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
     #elif defined(DRV_GPIO_REG_AS_6253E_1) 
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)     
     #elif defined(DRV_GPIO_REG_AS_6256)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79)
         #define GPIO_HWORD_REG6(name)  GPIO_HWORD_REG_FOR_1BIT(name, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95)
         #define GPIO_HWORD_REG7(name)  GPIO_HWORD_REG_FOR_1BIT(name, 96, 97, 98, 99, 100, 101, 102, 103, 104, NULL, NULL, NULL, NULL, NULL, NULL, NULL)    
 #endif      
   #endif /* DRV_GPIO_REG_AS_6205B */
#endif /* DRV_GPIO_REG_AS_TK6516 */

/*********************************************************************************************/
/*********************************************************************************************/
 /* Macros to calulate GPIO related register value of different platforms with 1 bit unit 
   for different settings, like dirction control pull-up/pull-down enable, inversion control. */
/*****************************************END***********************************************/
/*********************************************************************************************/

#if defined(DRV_GPIO_REG_AS_6290)

   #define GPIO_OWNERSHIP_REG1 GPIO_HWORD_REG1(OWNERSHIP)
   #define GPIO_OWNERSHIP_REG2 GPIO_HWORD_REG2(OWNERSHIP)   

#endif
/*********************************************************************************************/
/*********************************************************************************************/ 
/****************** GPIO direction control register value*************************************/
/*************************************START************************************************/ 
/*********************************************************************************************/ 

   #define GPIO_DIR_REG1   GPIO_HWORD_REG1(DIR)
#if !defined(DRV_GPIO_REG_AS_TK6516)
   #define GPIO_DIR_REG2   GPIO_HWORD_REG2(DIR)
#if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_6270A)
   #define GPIO_DIR_REG3   GPIO_HWORD_REG3(DIR)
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6253E)
      #define GPIO_DIR_REG4   GPIO_HWORD_REG4(DIR)
   #endif
   #if defined(DRV_GPIO_REG_AS_6228)
      #define GPIO_DIR_REG5   GPIO_HWORD_REG5(DIR)
   #endif
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1)
      #define GPIO_DIR_REG4   GPIO_HWORD_REG4(DIR)
      #define GPIO_DIR_REG5   GPIO_HWORD_REG5(DIR)
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) 
         #define GPIO_DIR_REG6   GPIO_HWORD_REG6(DIR)
      #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
         #define GPIO_DIR_REG6   GPIO_HWORD_REG6(DIR)
         #define GPIO_DIR_REG7   GPIO_HWORD_REG7(DIR)
      #endif
  #elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255) 
      #define GPIO_DIR_REG4   GPIO_HWORD_REG4(DIR)
      #define GPIO_DIR_REG5   GPIO_HWORD_REG5(DIR)
      #define GPIO_DIR_REG6   GPIO_HWORD_REG6(DIR)
      #define GPIO_DIR_REG7   GPIO_HWORD_REG7(DIR)
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_6270A) */
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */

/*********************************************************************************************/
/*********************************************************************************************/ 
/****************** GPIO direction control register value*************************************/
/*************************************END*****************************************************/ 
/*********************************************************************************************/ 


/*********************************************************************************************/
/*********************************************************************************************/ 
/****************** GPIO Pull-up/Pull-down enable register value******************************/
/*************************************START***************************************************/ 
/*********************************************************************************************/ 

   #define GPIO_PULL_REG1   GPIO_HWORD_REG1(PULL)
#if !defined(DRV_GPIO_REG_AS_TK6516)
   #define GPIO_PULL_REG2   GPIO_HWORD_REG2(PULL)
#if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_6270A)
   #if defined(DRV_GPIO_REG_AS_6251)
      #define GPIO_PULL_REG3   GPIO_HWORD_REG3_TO_38(PULL)
   #else
      #define GPIO_PULL_REG3   GPIO_HWORD_REG3(PULL)
   #endif
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223)|| defined(DRV_GPIO_REG_AS_6253E)
      #define GPIO_PULL_REG4   GPIO_HWORD_REG4(PULL)
   #endif
   #if defined(DRV_GPIO_REG_AS_6228)
      #define GPIO_PULL_REG5   GPIO_HWORD_REG5(PULL)
   #endif
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1)
      #define GPIO_PULL_REG4   GPIO_HWORD_REG4(PULL)
      #define GPIO_PULL_REG5   GPIO_HWORD_REG5(PULL)
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) 
         #define GPIO_PULL_REG6   GPIO_HWORD_REG6(PULL)
      #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
         #define GPIO_PULL_REG6   GPIO_HWORD_REG6(PULL)
         #define GPIO_PULL_REG7   GPIO_HWORD_REG7(PULL)
      #endif
  #elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255) 
      #define GPIO_PULL_REG4   GPIO_HWORD_REG4(PULL)
      #define GPIO_PULL_REG5   GPIO_HWORD_REG5(PULL)   
      #define GPIO_PULL_REG6   GPIO_HWORD_REG6(PULL)
      #define GPIO_PULL_REG7   GPIO_HWORD_REG7(PULL)
   #endif
#endif /* #if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_6270A) */
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */

/*********************************************************************************************/
/*********************************************************************************************/ 
/****************** GPIO Pull-up/Pull-down enable register value******************************/
/*************************************END*****************************************************/ 
/*********************************************************************************************/ 

/*********************************************************************************************/
/*********************************************************************************************/ 
/******************GPIO inversion control register value**************************************/
/************************************START*****************************************************/ 
/*********************************************************************************************/ 

#if !defined(DRV_GPIO_REG_AS_6205B)
   #define GPIO_INV_REG1   GPIO_HWORD_REG1(INV)
#if !defined(DRV_GPIO_REG_AS_TK6516)
   #define GPIO_INV_REG2   GPIO_HWORD_REG2(INV)
#if !defined(DRV_GPIO_REG_AS_6270A) && !defined(DRV_GPIO_REG_AS_6251)
   #define GPIO_INV_REG3   GPIO_HWORD_REG3(INV)
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6253E)
      #define GPIO_INV_REG4   GPIO_HWORD_REG4(INV)
   #endif
   #if defined(DRV_GPIO_REG_AS_6228)
      #define GPIO_INV_REG5   GPIO_HWORD_REG5(INV)
   #endif
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T)  || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1)
      #define GPIO_INV_REG4   GPIO_HWORD_REG4(INV)
      #define GPIO_INV_REG5   GPIO_HWORD_REG5(INV)
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T)
         #define GPIO_INV_REG6   GPIO_HWORD_REG6(INV)
      #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
         #define GPIO_INV_REG6   GPIO_HWORD_REG6(INV)
         #define GPIO_INV_REG7   GPIO_HWORD_REG7(INV)
      #endif
   #elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255)  
      #define GPIO_INV_REG4   GPIO_HWORD_REG4(INV)
      #define GPIO_INV_REG5   GPIO_HWORD_REG5(INV)
      #define GPIO_INV_REG6   GPIO_HWORD_REG6(INV)
      #define GPIO_INV_REG7   GPIO_HWORD_REG7(INV)
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6270A) */
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */


/*********************************************************************************************/
/*********************************************************************************************/ 
/******************GPIO inversion control register value**************************************/
/************************************END******************************************************/ 
/*********************************************************************************************/ 

/*********************************************************************************************/
/*********************************************************************************************/ 
/*****************************GPIO Output register value**************************************/
/************************************START*****************************************************/ 
/*********************************************************************************************/ 

   #define GPIO_OUTPUT_REG1   GPIO_HWORD_REG1(OUTPUT_LEVEL)
#if !defined(DRV_GPIO_REG_AS_TK6516)
   #define GPIO_OUTPUT_REG2   GPIO_HWORD_REG2(OUTPUT_LEVEL)
#if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_6270A)
   #define GPIO_OUTPUT_REG3   GPIO_HWORD_REG3(OUTPUT_LEVEL)
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6253E)
      #define GPIO_OUTPUT_REG4   GPIO_HWORD_REG4(OUTPUT_LEVEL)
   #endif
   #if defined(DRV_GPIO_REG_AS_6228)
      #define GPIO_OUTPUT_REG5   GPIO_HWORD_REG5(OUTPUT_LEVEL)
   #endif
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T)  || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1)
      #define GPIO_OUTPUT_REG4   GPIO_HWORD_REG4(OUTPUT_LEVEL)
      #define GPIO_OUTPUT_REG5   GPIO_HWORD_REG5(OUTPUT_LEVEL)
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255)
         #define GPIO_OUTPUT_REG6   GPIO_HWORD_REG6(OUTPUT_LEVEL)
      #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
         #define GPIO_OUTPUT_REG6   GPIO_HWORD_REG6(OUTPUT_LEVEL)
         #define GPIO_OUTPUT_REG7   GPIO_HWORD_REG7(OUTPUT_LEVEL)
      #endif
   #elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255)
      #define GPIO_OUTPUT_REG4   GPIO_HWORD_REG4(OUTPUT_LEVEL)
      #define GPIO_OUTPUT_REG5   GPIO_HWORD_REG5(OUTPUT_LEVEL)
      #define GPIO_OUTPUT_REG6   GPIO_HWORD_REG6(OUTPUT_LEVEL)
      #define GPIO_OUTPUT_REG7   GPIO_HWORD_REG7(OUTPUT_LEVEL)
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_6270A) */
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */


/*********************************************************************************************/
/*********************************************************************************************/ 
/*****************************GPIO Output register value**************************************/
/************************************END*****************************************************/ 
/*********************************************************************************************/ 

/*********************************************************************************************/
/*********************************************************************************************/ 
/*****************************GPO Output register value**************************************/
/************************************START*****************************************************/ 
/*********************************************************************************************/ 

#if (!defined(DRV_GPIO_WO_GPO))
   #define GPO_OUTPUT_REG1   GPO_HWORD_REG1(OUTPUT_LEVEL)
#endif

/*********************************************************************************************/
/*********************************************************************************************/ 
/*****************************GPO Output register value**************************************/
/************************************END*****************************************************/ 
/*********************************************************************************************/ 
  

/*********************************************************************************************/
/*********************************************************************************************/ 
/****************************GPIO PULL up/down selection register value***********************/
/************************************START*****************************************************/ 
/*********************************************************************************************/ 

#if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_TK6516) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6270A) || defined(DRV_GPIO_REG_AS_6253E)  || defined(DRV_GPIO_REG_AS_6276)|| defined(DRV_GPIO_REG_AS_6251) || defined(DRV_GPIO_REG_AS_6253E_1) || defined(DRV_GPIO_REG_AS_6290)
   #define GPIO_PULLSEL_REG1   GPIO_HWORD_REG1(PULL_SEL)
#if !defined(DRV_GPIO_REG_AS_TK6516)
   #define GPIO_PULLSEL_REG2   GPIO_HWORD_REG2(PULL_SEL)
#if defined(DRV_GPIO_REG_AS_6251)
   #define GPIO_PULLSEL_REG3   GPIO_HWORD_REG3_TO_38(PULL_SEL)
#elif !defined(DRV_GPIO_REG_AS_6270A) && !defined(DRV_GPIO_REG_AS_6290)
   #define GPIO_PULLSEL_REG3   GPIO_HWORD_REG3(PULL_SEL)
   #define GPIO_PULLSEL_REG4   GPIO_HWORD_REG4(PULL_SEL)
#if !defined(DRV_GPIO_REG_AS_6253E)
   #define GPIO_PULLSEL_REG5   GPIO_HWORD_REG5(PULL_SEL)
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255)
      #define GPIO_PULLSEL_REG6   GPIO_HWORD_REG6(PULL_SEL)
   #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
      #define GPIO_PULLSEL_REG6   GPIO_HWORD_REG6(PULL_SEL)
      #define GPIO_PULLSEL_REG7   GPIO_HWORD_REG7(PULL_SEL)
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6253E) */
#endif /* !defined(DRV_GPIO_REG_AS_6270A) */
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */
#elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255) 
	#define GPIO_PULLSEL_REG1   GPIO_HWORD_REG1(PULL_SEL)
	#define GPIO_PULLSEL_REG2   GPIO_HWORD_REG2(PULL_SEL)
	#define GPIO_PULLSEL_REG3   GPIO_HWORD_REG3(PULL_SEL)
	#define GPIO_PULLSEL_REG4   GPIO_HWORD_REG4(PULL_SEL)
	#define GPIO_PULLSEL_REG5   GPIO_HWORD_REG5(PULL_SEL)
	#define GPIO_PULLSEL_REG6   GPIO_HWORD_REG6(PULL_SEL)
	#define GPIO_PULLSEL_REG7   GPIO_HWORD_REG7(PULL_SEL)
#endif /* defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) */

/*********************************************************************************************/
/*********************************************************************************************/ 
/****************************GPIO PULL up/down selection register value***********************/
/************************************END*****************************************************/ 
/*********************************************************************************************/ 

#if defined(DRV_GPIO_REG_AS_6253E)
   #define GPIO_SPMODE_REG ((SP_MODE_BIT0) | (SP_MODE_BIT2<<2) | (SP_MODE_BIT4<<4) | (SP_MODE_BIT6<<6) | (SP_MODE_BIT8<<8))
   #define GPIO_BANK_REG ((BANK0) | (BANK1<<1) | (BANK2<<2) | (BANK3<<3) | (BANK4<<4) | (BANK5<<5) | (BANK6<<6) | (BANK7<<7))
#endif //defined(DRV_GPIO_REG_AS_6253E)

//this need to confirm after WS.chen work done!!!!
#if defined(DRV_GPIO_REG_AS_6253E_1)
   #define GPIO_SPMODE0_REG ((SP_MODE0_BIT0) | (SP_MODE0_BIT2<<2) | (SP_MODE0_BIT4<<4) | (SP_MODE0_BIT6<<6) | (SP_MODE0_BIT8<<8) |\
   	   (SP_MODE0_BIT10<<10) | (SP_MODE0_BIT12<<12) | (SP_MODE0_BIT14<<14) | (SP_MODE0_BIT16<<16) | (SP_MODE0_BIT18<<18) |\
   	   (SP_MODE0_BIT20<<20) | (SP_MODE0_BIT22<<22) | (SP_MODE0_BIT24<<24) | (SP_MODE0_BIT26<<26) | (SP_MODE0_BIT28<<28) |\
   	   (SP_MODE0_BIT30<<30))

   #define GPIO_SPMODE1_REG ((SP_MODE1_BIT0) | (SP_MODE1_BIT2<<2) | (SP_MODE1_BIT4<<4) | (SP_MODE1_BIT8<<8) | (SP_MODE1_BIT12<<12) |\
   	   (SP_MODE1_BIT14<<14))
  // #define GPIO_BANK_REG ((BANK0) | (BANK1<<1) | (BANK2<<2) | (BANK3<<3) | (BANK4<<4) | (BANK5<<5) | (BANK6<<6) | (BANK7<<7))
#endif //defined(DRV_GPIO_REG_AS_6253E_1)





/*********************************************************************************************/
/*********************************************************************************************/ 
/**************************** General macros to calulate GPIO word-length variable************/
/**************************value with 1 bit unit for different platform***********************/
/************************************START*****************************************************/ 
/*********************************************************************************************/ 

#if defined(DRV_GPIO_REG_AS_TK6516)
   #define GPIO_WORD_VAR0(name)  GPIO_WORD_VAR_FOR_1BIT(name, 0, 1, 2, 3, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                    NULL, NULL, NULL, NULL)		
#elif defined(DRV_GPIO_REG_AS_6205B)
   #define GPIO_WORD_VAR0(name)  GPIO_WORD_VAR_FOR_1BIT(name, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
                                                    20, 21, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)		
#elif defined(DRV_GPIO_REG_AS_6270A)
   #define GPIO_WORD_VAR0(name)  GPIO_WORD_VAR_FOR_1BIT(name, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
                                                    20, 21, 22, 23, 24, 25, 26, 27, NULL, NULL, NULL, NULL)		
#elif defined(DRV_GPIO_REG_AS_6251)
   #define GPIO_WORD_VAR0(name)  GPIO_WORD_VAR_FOR_1BIT(name, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
                                                    20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)		
   #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                       NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#else /* defined(DRV_GPIO_REG_AS_6270A) */
   #define GPIO_WORD_VAR0(name)  GPIO_WORD_VAR_FOR_1BIT(name, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
                                                    20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)		
   #if defined(DRV_GPIO_REG_AS_6218B)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, NULL, \
                                                       NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6225)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                       49, 50, 51, 52, 53, 54, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6227)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                       49, 50, 51, 52, 53, 54, 55, 56, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6228)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6223)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                       49, 50, 51, 52, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6238)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, \
                                                  79, 80, 81, 82, 83, 84, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6235)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6236)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, \
                                                  79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95)
      #if defined(DRV_GPIO_REG_AS_6268A)
      #define GPIO_WORD_VAR3(name)  GPIO_WORD_VAR_FOR_1BIT(name, 96, 97, 98, 99, 100, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6268)
      #define GPIO_WORD_VAR3(name)  GPIO_WORD_VAR_FOR_1BIT(name, 96, 97, 98, 99, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6276)
      #define GPIO_WORD_VAR3(name)  GPIO_WORD_VAR_FOR_1BIT(name, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL)
      #endif
   #elif defined(DRV_GPIO_REG_AS_6253T)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, \
                                                  79, 80, 81, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6255)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, \
                                                  79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95)
      #define GPIO_WORD_VAR3(name)  GPIO_WORD_VAR_FOR_1BIT(name, 96, 97, 98, 99, 100, 101, 102, 103, 104, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6253E)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63) 
   #elif defined(DRV_GPIO_REG_AS_6253E_1)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)                                            
#elif defined(DRV_GPIO_REG_AS_6256) 
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, \
                                                  79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95)
      #define GPIO_WORD_VAR3(name)  GPIO_WORD_VAR_FOR_1BIT(name, 96, 97, 98, 99, 100, 101, 102, 103, 104, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6290)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)

#endif

#endif /* !defined(DRV_GPIO_REG_AS_6205B) */


/*********************************************************************************************/
/*********************************************************************************************/ 
/**************************** General macros to calulate GPIO word-length variable************/
/**************************value with 1 bit unit for different platform***********************/
/************************************END*****************************************************/ 
/*********************************************************************************************/ 


  


/*********************************************************************************************/
/*********************************************************************************************/ 
/**************************** For each GPIO mode, specify if each GPIO pin is allowed to ******/
/****************set to this mode with '1' allowed, '0' on the corresponding bit position******/
/**********  Bit 0 means GPIO0, Bit 1 means GPIO1... etc ****************************************/ 
/**************************************START****************************************************/ 
/************************************************************************************************/ 

   #define GPIO_MODE0_VAR0  GPIO_WORD_VAR0(MODE0)
   #define GPIO_MODE1_VAR0  GPIO_WORD_VAR0(MODE1)
   #define GPIO_MODE2_VAR0  GPIO_WORD_VAR0(MODE2)
   #define GPIO_MODE3_VAR0  GPIO_WORD_VAR0(MODE3)
   #if defined(DRV_GPIO_MODE_3BITS)
   #define GPIO_MODE4_VAR0  GPIO_WORD_VAR0(MODE4)
   #elif defined(DRV_GPIO_MODE_4BITS)
   #define GPIO_MODE4_VAR0  GPIO_WORD_VAR0(MODE4)
   #define GPIO_MODE5_VAR0  GPIO_WORD_VAR0(MODE5)
   #define GPIO_MODE6_VAR0  GPIO_WORD_VAR0(MODE6)
   #define GPIO_MODE7_VAR0  GPIO_WORD_VAR0(MODE7)
   #endif //defined(DRV_GPIO_MODE_4BITS)
   #define GPIO_DIROUT_VAR0  GPIO_WORD_VAR0(DIR_OUT)
   #define GPIO_DIRIN_VAR0  GPIO_WORD_VAR0(DIR_IN)
   
   #if defined(DRV_GPIO_REG_AS_6251)
   #define GPIO_DIROUT_VAR1  GPIO_WORD_VAR1(DIR_OUT)
   #define GPIO_DIRIN_VAR1  GPIO_WORD_VAR1(DIR_IN)
   #elif !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_TK6516) && !defined(DRV_GPIO_REG_AS_6270A)
   #define GPIO_MODE0_VAR1  GPIO_WORD_VAR1(MODE0)
   #define GPIO_MODE1_VAR1  GPIO_WORD_VAR1(MODE1)
   #define GPIO_MODE2_VAR1  GPIO_WORD_VAR1(MODE2)
   #define GPIO_MODE3_VAR1  GPIO_WORD_VAR1(MODE3)
   #if defined(DRV_GPIO_MODE_3BITS)
   #define GPIO_MODE4_VAR1  GPIO_WORD_VAR1(MODE4)
   #elif defined(DRV_GPIO_MODE_4BITS)
   #define GPIO_MODE4_VAR1  GPIO_WORD_VAR1(MODE4)
   #define GPIO_MODE5_VAR1  GPIO_WORD_VAR1(MODE5)
   #define GPIO_MODE6_VAR1  GPIO_WORD_VAR1(MODE6)
   #define GPIO_MODE7_VAR1  GPIO_WORD_VAR1(MODE7)
   #endif //defined(DRV_GPIO_MODE_4BITS)
   #define GPIO_DIROUT_VAR1  GPIO_WORD_VAR1(DIR_OUT)
   #define GPIO_DIRIN_VAR1  GPIO_WORD_VAR1(DIR_IN)
   
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1) || defined(DRV_GPIO_REG_AS_6256)
   #define GPIO_MODE0_VAR2     GPIO_WORD_VAR2(MODE0)
   #define GPIO_MODE1_VAR2     GPIO_WORD_VAR2(MODE1)
   #define GPIO_MODE2_VAR2     GPIO_WORD_VAR2(MODE2)
   #define GPIO_MODE3_VAR2     GPIO_WORD_VAR2(MODE3)
   #if defined(DRV_GPIO_MODE_3BITS)
   #define GPIO_MODE4_VAR2  GPIO_WORD_VAR2(MODE4)
   #elif defined(DRV_GPIO_MODE_4BITS) 
   #define GPIO_MODE4_VAR2  GPIO_WORD_VAR2(MODE4)
   #define GPIO_MODE5_VAR2  GPIO_WORD_VAR2(MODE5)
   #define GPIO_MODE6_VAR2  GPIO_WORD_VAR2(MODE6)
   #define GPIO_MODE7_VAR2  GPIO_WORD_VAR2(MODE7)
   #endif //defined(DRV_GPIO_MODE_4BITS)
   #define GPIO_DIROUT_VAR2    GPIO_WORD_VAR2(DIR_OUT)
   #define GPIO_DIRIN_VAR2     GPIO_WORD_VAR2(DIR_IN)
   #endif /* DRV_GPIO_REG_AS_6228 */
   
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6256)|| defined(DRV_GPIO_REG_AS_6255)
   #define GPIO_MODE0_VAR3     GPIO_WORD_VAR3(MODE0)
   #define GPIO_MODE1_VAR3     GPIO_WORD_VAR3(MODE1)
   #define GPIO_MODE2_VAR3     GPIO_WORD_VAR3(MODE2)
   #define GPIO_MODE3_VAR3     GPIO_WORD_VAR3(MODE3)
   #if defined(DRV_GPIO_MODE_3BITS)
   #define GPIO_MODE4_VAR3  GPIO_WORD_VAR3(MODE4)   
   #elif defined(DRV_GPIO_MODE_4BITS)
   #define GPIO_MODE4_VAR3  GPIO_WORD_VAR3(MODE4)
   #define GPIO_MODE5_VAR3  GPIO_WORD_VAR3(MODE5)
   #define GPIO_MODE6_VAR3  GPIO_WORD_VAR3(MODE6)
   #define GPIO_MODE7_VAR3  GPIO_WORD_VAR3(MODE7)
   #endif //defined(DRV_GPIO_MODE_4BITS)
   #define GPIO_DIROUT_VAR3    GPIO_WORD_VAR3(DIR_OUT)
   #define GPIO_DIRIN_VAR3     GPIO_WORD_VAR3(DIR_IN)
   #endif /* DRV_GPIO_REG_AS_6228 */
#endif /* !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_TK6516) && !defined(DRV_GPIO_REG_AS_6270A) */

/*********************************************************************************************/
/*********************************************************************************************/ 
/**************************** For each GPIO mode, specify if each GPIO pin is allowed to ******/
/****************set to this mode with '1' allowed, '0' on the corresponding bit position******/
/**********  Bit 0 means GPIO0, Bit 1 means GPIO1... etc ****************************************/ 
/**************************************END****************************************************/ 
/************************************************************************************************/ 



/*********************************************************************************************/
/*********************************************************************************************/ 
/**************************** For each GPO mode, specify if each GPO pin is allowed to ******/
/****************set to this mode with '1' allowed, '0' on the corresponding bit position******/
/**********  Bit 0 means GPO0, Bit 1 means GPO1... etc ****************************************/ 
/**************************************START****************************************************/ 
/************************************************************************************************/ 

#if defined(DRV_GPIO_REG_AS_6205B) || defined(DRV_GPIO_REG_AS_6225)
   #define GPO_MODE0_VAR0  (MODE0_GPO0 | (MODE0_GPO1 << 1) | (MODE0_GPO2 << 2) | (MODE0_GPO3 << 3))
   #define GPO_MODE1_VAR0  (MODE1_GPO0 | (MODE1_GPO1 << 1) | (MODE1_GPO2 << 2) | (MODE1_GPO3 << 3))
   #define GPO_MODE2_VAR0  (MODE2_GPO0 | (MODE2_GPO1 << 1) | (MODE2_GPO2 << 2) | (MODE2_GPO3 << 3))
   #define GPO_MODE3_VAR0  (MODE3_GPO0 | (MODE3_GPO1 << 1) | (MODE3_GPO2 << 2) | (MODE3_GPO3 << 3))
#elif defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227)
   #define GPO_MODE0_VAR0  (MODE0_GPO0 | (MODE0_GPO1 << 1) | (MODE0_GPO2 << 2) | (MODE0_GPO3 << 3) | (MODE0_GPO4 << 4))
   #define GPO_MODE1_VAR0  (MODE1_GPO0 | (MODE1_GPO1 << 1) | (MODE1_GPO2 << 2) | (MODE1_GPO3 << 3) | (MODE1_GPO4 << 4))
   #define GPO_MODE2_VAR0  (MODE2_GPO0 | (MODE2_GPO1 << 1) | (MODE2_GPO2 << 2) | (MODE2_GPO3 << 3) | (MODE2_GPO4 << 4))
   #define GPO_MODE3_VAR0  (MODE3_GPO0 | (MODE3_GPO1 << 1) | (MODE3_GPO2 << 2) | (MODE3_GPO3 << 3) | (MODE3_GPO4 << 4))
#elif defined(DRV_GPIO_REG_AS_6218B) || defined(DRV_GPIO_REG_AS_6228)
   #define GPO_MODE0_VAR0  (MODE0_GPO0 | (MODE0_GPO1 << 1) | (MODE0_GPO2 << 2))
   #define GPO_MODE1_VAR0  (MODE1_GPO0 | (MODE1_GPO1 << 1) | (MODE1_GPO2 << 2))
   #define GPO_MODE2_VAR0  (MODE2_GPO0 | (MODE2_GPO1 << 1) | (MODE2_GPO2 << 2))
   #define GPO_MODE3_VAR0  (MODE3_GPO0 | (MODE3_GPO1 << 1) | (MODE3_GPO2 << 2))
#endif

/*********************************************************************************************/
/*********************************************************************************************/ 
/**************************** For each GPO mode, specify if each GPO pin is allowed to ******/
/****************set to this mode with '1' allowed, '0' on the corresponding bit position******/
/**********  Bit 0 means GPO0, Bit 1 means GPO1... etc ****************************************/ 
/**************************************END****************************************************/ 
/************************************************************************************************/ 



/*********************************************************************************************/
/*********************************************************************************************/ 
/*** The '1' of the bit in the variables denotes that the mode is allowed to be set for the **/
/*** corresponding pin.******************gpio_mode_allowed[][4]*******************************/
/**************************************START***************************************************/
/**********************************************************************************************/ 
#if !defined(DRV_GPIO_MODE_4BITS) && !defined(DRV_GPIO_MODE_3BITS) && !defined(DRV_GPIO_REG_AS_6290)
const kal_uint32  gpio_mode_allowed[][4] = {
   {GPIO_MODE0_VAR0, GPIO_MODE1_VAR0, GPIO_MODE2_VAR0, GPIO_MODE3_VAR0}
   #if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_TK6516) && !defined(DRV_GPIO_REG_AS_6270A)
   ,{GPIO_MODE0_VAR1, GPIO_MODE1_VAR1, GPIO_MODE2_VAR1, GPIO_MODE3_VAR1}
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276)
   ,{GPIO_MODE0_VAR2, GPIO_MODE1_VAR2, GPIO_MODE2_VAR2, GPIO_MODE3_VAR2}
   #endif
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
   ,{GPIO_MODE0_VAR3, GPIO_MODE1_VAR3, GPIO_MODE2_VAR3, GPIO_MODE3_VAR3}
   #endif
   #endif /* !defined(DRV_GPIO_REG_AS_6205B) */
};
#elif defined(DRV_GPIO_MODE_4BITS)//#if defined(DRV_GPIO_MODE_4BITS)
const kal_uint32  gpio_mode_allowed[][8] = {
#if defined(DRV_GPIO_REG_AS_6255)
   {GPIO_MODE0_VAR0, GPIO_MODE1_VAR0, GPIO_MODE2_VAR0, GPIO_MODE3_VAR0, GPIO_MODE4_VAR0, GPIO_MODE5_VAR0, GPIO_MODE6_VAR0, GPIO_MODE7_VAR0}
   ,{GPIO_MODE0_VAR1, GPIO_MODE1_VAR1, GPIO_MODE2_VAR1, GPIO_MODE3_VAR1, GPIO_MODE4_VAR1, GPIO_MODE5_VAR1, GPIO_MODE6_VAR1, GPIO_MODE7_VAR1}
   ,{GPIO_MODE0_VAR2, GPIO_MODE1_VAR2, GPIO_MODE2_VAR2, GPIO_MODE3_VAR2, GPIO_MODE4_VAR2, GPIO_MODE5_VAR2, GPIO_MODE6_VAR2, GPIO_MODE7_VAR2}
   ,{GPIO_MODE0_VAR3, GPIO_MODE1_VAR3, GPIO_MODE2_VAR3, GPIO_MODE3_VAR3, GPIO_MODE4_VAR3, GPIO_MODE5_VAR3, GPIO_MODE6_VAR3, GPIO_MODE7_VAR3}
#elif defined(DRV_GPIO_REG_AS_6256)
    {GPIO_MODE0_VAR0, GPIO_MODE1_VAR0, GPIO_MODE2_VAR0, GPIO_MODE3_VAR0, GPIO_MODE4_VAR0, GPIO_MODE5_VAR0, GPIO_MODE6_VAR0, GPIO_MODE7_VAR0}
   ,{GPIO_MODE0_VAR1, GPIO_MODE1_VAR1, GPIO_MODE2_VAR1, GPIO_MODE3_VAR1, GPIO_MODE4_VAR1, GPIO_MODE5_VAR1, GPIO_MODE6_VAR1, GPIO_MODE7_VAR1}
   ,{GPIO_MODE0_VAR2, GPIO_MODE1_VAR2, GPIO_MODE2_VAR2, GPIO_MODE3_VAR2, GPIO_MODE4_VAR2, GPIO_MODE5_VAR2, GPIO_MODE6_VAR2, GPIO_MODE7_VAR2}
   ,{GPIO_MODE0_VAR3, GPIO_MODE1_VAR3, GPIO_MODE2_VAR3, GPIO_MODE3_VAR3, GPIO_MODE4_VAR3, GPIO_MODE5_VAR3, GPIO_MODE6_VAR3, GPIO_MODE7_VAR3}
#elif defined(DRV_GPIO_REG_AS_6253E_1)
   {GPIO_MODE0_VAR0, GPIO_MODE1_VAR0, GPIO_MODE2_VAR0, GPIO_MODE3_VAR0, GPIO_MODE4_VAR0, GPIO_MODE5_VAR0, GPIO_MODE6_VAR0, GPIO_MODE7_VAR0}
   ,{GPIO_MODE0_VAR1, GPIO_MODE1_VAR1, GPIO_MODE2_VAR1, GPIO_MODE3_VAR1, GPIO_MODE4_VAR1, GPIO_MODE5_VAR1, GPIO_MODE6_VAR1, GPIO_MODE7_VAR1}
#elif defined(DRV_GPIO_REG_AS_6251)
   {GPIO_MODE0_VAR0, GPIO_MODE1_VAR0, GPIO_MODE2_VAR0, GPIO_MODE3_VAR0, GPIO_MODE4_VAR0, GPIO_MODE5_VAR0, GPIO_MODE6_VAR0, GPIO_MODE7_VAR0}
#endif //defined(DRV_GPIO_REG_AS_6255)
};
#elif defined(DRV_GPIO_MODE_3BITS)
const kal_uint32  gpio_mode_allowed[][5] = {
#if defined(DRV_GPIO_REG_AS_6276)
    {GPIO_MODE0_VAR0, GPIO_MODE1_VAR0, GPIO_MODE2_VAR0, GPIO_MODE3_VAR0,GPIO_MODE4_VAR0}
   ,{GPIO_MODE0_VAR1, GPIO_MODE1_VAR1, GPIO_MODE2_VAR1, GPIO_MODE3_VAR1,GPIO_MODE4_VAR1}
   ,{GPIO_MODE0_VAR2, GPIO_MODE1_VAR2, GPIO_MODE2_VAR2, GPIO_MODE3_VAR2,GPIO_MODE4_VAR2}
   ,{GPIO_MODE0_VAR3, GPIO_MODE1_VAR3, GPIO_MODE2_VAR3, GPIO_MODE3_VAR3,GPIO_MODE4_VAR3}
#endif  
};

#endif //#if !defined(DRV_GPIO_MODE_4BITS) && !defined(DRV_GPIO_MODE_3BITS)


/*********************************************************************************************/
/*********************************************************************************************/ 
/*** The '1' of the bit in the variables denotes that the mode is allowed to be set for the **/
/*** corresponding pin.***********************************************************************/
/*************************************START***************************************************/
/**********************************************************************************************/ 

kal_uint32  gpio_check_for_write[] = {
   0xffffffff
   #if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_TK6516) && !defined(DRV_GPIO_REG_AS_6270A)
   #if defined(DRV_GPIO_REG_AS_6251)
   ,0x0
   #else //defined(DRV_GPIO_REG_AS_6251)
   ,0xffffffff
   #endif //defined(DRV_GPIO_REG_AS_6251)
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1) || defined(DRV_GPIO_REG_AS_6256)
   ,0xffffffff
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6256)
   ,0xffffffff
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif
   #endif /* !defined(DRV_GPIO_REG_AS_6205B) */
};

kal_uint32  gpio_check_for_read[] = {
   0xffffffff
   #if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_TK6516) && !defined(DRV_GPIO_REG_AS_6270A)
   #if defined(DRV_GPIO_REG_AS_6251)
   ,0x0
   #else //defined(DRV_GPIO_REG_AS_6251)
   ,0xffffffff
   #endif //defined(DRV_GPIO_REG_AS_6251)
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1) || defined(DRV_GPIO_REG_AS_6256)
   ,0xffffffff
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6256)
   ,0xffffffff
   #endif /* DRV_GPIO_REG_AS_6268A */
   #endif
   #endif /* !defined(DRV_GPIO_REG_AS_6205B) */
};

/* The '1' of the bit in the variables denotes that the direction output is allowed to be 
   set for the corresponding pin. */
const kal_uint32  gpio_dir_out_allowed[] = {
   GPIO_DIROUT_VAR0
   #if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_TK6516) && !defined(DRV_GPIO_REG_AS_6270A)
   ,GPIO_DIROUT_VAR1
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1) || defined(DRV_GPIO_REG_AS_6256)
   ,GPIO_DIROUT_VAR2
   #endif
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6256)
   ,GPIO_DIROUT_VAR3
   #endif
   #endif /* !defined(DRV_GPIO_REG_AS_6205B) */
};

/* The '1' of the bit in the variables denotes that the direction input is allowed to be 
   set for the corresponding pin. */
const kal_uint32  gpio_dir_in_allowed[] = {
	GPIO_DIRIN_VAR0
   #if !defined(DRV_GPIO_REG_AS_6205B) && !defined(DRV_GPIO_REG_AS_TK6516) && !defined(DRV_GPIO_REG_AS_6270A)
   ,GPIO_DIRIN_VAR1
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E_1) || defined(DRV_GPIO_REG_AS_6256)
   ,GPIO_DIRIN_VAR2
   #endif
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6256)
   ,GPIO_DIRIN_VAR3
   #endif
   #endif /* !defined(DRV_GPIO_REG_AS_6205B) */
};

#if (!defined(DRV_GPIO_WO_GPO))
const kal_uint16  gpo_mode_allowed[] = {
	GPO_MODE0_VAR0, GPO_MODE1_VAR0, GPO_MODE2_VAR0, GPO_MODE3_VAR0
};
kal_uint16  gpo_check_for_write[] = {
	0xffff
};
#endif /*!defined(DRV_GPIO_REG_AS_6223)*/



/*********************************************************************************************/
/*********************************************************************************************/ 
/*** The '1' of the bit in the variables denotes that the mode is allowed to be set for the **/
/*** corresponding pin.***********************************************************************/
/*************************************END*****************************************************/
/**********************************************************************************************/ 

#if defined(MT6276_S01)
#define CLK_MUX_SEL0_VALUE (CLKSEL1 | (CLKSEL2<<4) | (CLKSEL3<<8)| (CLKSEL4<<12) \
														|(CLKSEL5<<16)|(CLKSEL6<<20)|(CLKSEL7<<24)|(CLKSEL8<<28))
														
#define CLK_MUX_SEL1_VALUE (CLKSEL9 | (CLKSEL10<<4) | (CLKSEL11<<8)| (CLKSEL12<<12) \
														|(CLKSEL13<<16))
const kal_uint32 GPIO_CLK_SEL[13]={CLKSEL1,CLKSEL2,CLKSEL3,CLKSEL4,CLKSEL5,CLKSEL6,CLKSEL7, \
                                    CLKSEL8,CLKSEL9,CLKSEL10,CLKSEL11,CLKSEL12,CLKSEL13};
#endif

#endif /* __CHIP_SUPP_GPIO_DRV_TOOL__ */


/*********************************************************************************************/
/*********************************************************************************************/ 
/************************************** GPIO_Setting_init*************************************/
/************************************START***************************************************/
/**********************************************************************************************/ 

void GPIO_setting_init(void)
{
#if !defined(DRV_GPIO_OFF)
#if defined(__CHIP_SUPP_GPIO_DRV_TOOL__)
#if defined(DRV_GPIO_6290_SERIES)
//	PDN_CLR(PDN_GPIO);

	DRV_GPIO_WriteReg(GPIOMUX_GPIO_OWN1, GPIO_OWNERSHIP_REG1);
	DRV_GPIO_WriteReg(GPIOMUX_GPIO_OWN2, GPIO_OWNERSHIP_REG2);

#endif

#if !defined(DRV_GPIO_MODE_4BITS) && !defined(DRV_GPIO_MODE_3BITS) && !defined(DRV_GPIO_6290_SERIES)
   DRV_GPIO_WriteReg(GPIO_MODE1, GPIO_MODE_REG1);
#if !defined(DRV_GPIO_REG_AS_TK6516)
   DRV_GPIO_WriteReg(GPIO_MODE2, GPIO_MODE_REG2);
   DRV_GPIO_WriteReg(GPIO_MODE3, GPIO_MODE_REG3);
#if defined(DRV_GPIO_REG_AS_6205B)
   /* Note that for MT6205B, GPO mode register is on GPIO_MODE3, not GPO_MODE. */
   DRV_GPIO_WriteReg(GPIO_MODE4, GPO_MODE_REG);
#elif defined(DRV_GPIO_REG_AS_6270A)
   DRV_GPIO_WriteReg(GPIO_MODE4, GPIO_MODE_REG4);
#else /* defined(DRV_GPIO_REG_AS_6270A) */
   DRV_GPIO_WriteReg(GPIO_MODE4, GPIO_MODE_REG4);
   DRV_GPIO_WriteReg(GPIO_MODE5, GPIO_MODE_REG5);
   DRV_GPIO_WriteReg(GPIO_MODE6, GPIO_MODE_REG6);
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E)
   DRV_GPIO_WriteReg(GPIO_MODE7, GPIO_MODE_REG7);
      #if defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6276)
      DRV_GPIO_WriteReg(GPIO_MODE8, GPIO_MODE_REG8);
         #if defined(DRV_GPIO_REG_AS_6228)
         DRV_GPIO_WriteReg(GPIO_MODE9, GPIO_MODE_REG9);
         DRV_GPIO_WriteReg(GPIO_MODE10, GPIO_MODE_REG10);
         #endif
         #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276)
         DRV_GPIO_WriteReg(GPIO_MODE9, GPIO_MODE_REG9);
            #if !defined(DRV_GPIO_REG_AS_6236) 
            DRV_GPIO_WriteReg(GPIO_MODEA, GPIO_MODE_REGA);
               #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T)
               DRV_GPIO_WriteReg(GPIO_MODEB, GPIO_MODE_REGB);
               #endif
               #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
               DRV_GPIO_WriteReg(GPIO_MODEB, GPIO_MODE_REGB);
               DRV_GPIO_WriteReg(GPIO_MODEC, GPIO_MODE_REGC);
               DRV_GPIO_WriteReg(GPIO_MODED, GPIO_MODE_REGD);
                  #if  defined(DRV_GPIO_REG_AS_6276)
                  DRV_GPIO_WriteReg(GPIO_MODEE, GPIO_MODE_REGE);
                  #endif // defined(DRV_GPIO_REG_AS_6276)
               #endif
            #endif //!defined(DRV_GPIO_REG_AS_6236) 
         #endif
      #endif
   #endif
   #if (!defined(DRV_GPIO_WO_GPO))
   DRV_GPIO_WriteReg(GPO_MODE, GPO_MODE_REG);
   #endif
#endif /* defined(DRV_GPIO_REG_AS_6205B) */
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */
#elif defined(DRV_GPIO_MODE_3BITS)
#if defined(DRV_GPIO_REG_AS_6276)
   DRV_GPIO_WriteReg(GPIO_MODE0, GPIO_MODE_REG0);
   DRV_GPIO_WriteReg(GPIO_MODE1, GPIO_MODE_REG1);
   DRV_GPIO_WriteReg(GPIO_MODE2, GPIO_MODE_REG2);
   DRV_GPIO_WriteReg(GPIO_MODE3, GPIO_MODE_REG3);
   DRV_GPIO_WriteReg(GPIO_MODE4, GPIO_MODE_REG4);
   DRV_GPIO_WriteReg(GPIO_MODE5, GPIO_MODE_REG5);
   DRV_GPIO_WriteReg(GPIO_MODE6, GPIO_MODE_REG6);
   DRV_GPIO_WriteReg(GPIO_MODE7, GPIO_MODE_REG7);
   DRV_GPIO_WriteReg(GPIO_MODE8, GPIO_MODE_REG8);
   DRV_GPIO_WriteReg(GPIO_MODE9, GPIO_MODE_REG9);
   DRV_GPIO_WriteReg(GPIO_MODEA, GPIO_MODE_REGA);
   DRV_GPIO_WriteReg(GPIO_MODEB, GPIO_MODE_REGB);
   DRV_GPIO_WriteReg(GPIO_MODEC, GPIO_MODE_REGC);
   DRV_GPIO_WriteReg(GPIO_MODED, GPIO_MODE_REGD);
   DRV_GPIO_WriteReg(GPIO_MODEE, GPIO_MODE_REGE);
   DRV_GPIO_WriteReg(GPIO_MODEF, GPIO_MODE_REGF);
   DRV_GPIO_WriteReg(GPIO_MODE10, GPIO_MODE_REG10);
   DRV_GPIO_WriteReg(GPIO_MODE11, GPIO_MODE_REG11);
   DRV_GPIO_WriteReg(GPIO_MODE12, GPIO_MODE_REG12);
   DRV_GPIO_WriteReg(GPIO_MODE13, GPIO_MODE_REG13);
   DRV_GPIO_WriteReg(GPIO_MODE14, GPIO_MODE_REG14);
   DRV_GPIO_WriteReg(GPIO_MODE15, GPIO_MODE_REG15);	
	//wait after drv_tool check in, there should modify.
  // DRV_GPIO_WriteReg(GPIO_MODE16, GPIO_MODE_REG16);	
#endif   
#else // DRV_GPIO_MODE_4BITS is not defined
#if defined(DRV_GPIO_REG_AS_6253E_1)
   DRV_GPIO_WriteReg32(GPIO_MODE1, GPIO_MODE_REG1);
   DRV_GPIO_WriteReg32(GPIO_MODE2, GPIO_MODE_REG2);
   DRV_GPIO_WriteReg32(GPIO_MODE3, GPIO_MODE_REG3);
   DRV_GPIO_WriteReg32(GPIO_MODE4, GPIO_MODE_REG4);
   DRV_GPIO_WriteReg32(GPIO_MODE5, GPIO_MODE_REG5);
   DRV_GPIO_WriteReg32(GPIO_MODE6, GPIO_MODE_REG6);
   DRV_GPIO_WriteReg32(GPIO_MODE7, GPIO_MODE_REG7);
   DRV_GPIO_WriteReg32(GPIO_MODE8, GPIO_MODE_REG8);
   DRV_GPIO_WriteReg32(GPIO_MODE9, GPIO_MODE_REG9);
#endif

#if defined(DRV_GPIO_REG_AS_6255)
   DRV_GPIO_WriteReg(GPIO_MODE1, GPIO_MODE_REG1);
   DRV_GPIO_WriteReg(GPIO_MODE2, GPIO_MODE_REG2);
   DRV_GPIO_WriteReg(GPIO_MODE3, GPIO_MODE_REG3);
   DRV_GPIO_WriteReg(GPIO_MODE4, GPIO_MODE_REG4);
   DRV_GPIO_WriteReg(GPIO_MODE5, GPIO_MODE_REG5);
   DRV_GPIO_WriteReg(GPIO_MODE6, GPIO_MODE_REG6);
   DRV_GPIO_WriteReg(GPIO_MODE7, GPIO_MODE_REG7);
   DRV_GPIO_WriteReg(GPIO_MODE8, GPIO_MODE_REG8);
   DRV_GPIO_WriteReg(GPIO_MODE9, GPIO_MODE_REG9);
   DRV_GPIO_WriteReg(GPIO_MODE10, GPIO_MODE_REG10);
   DRV_GPIO_WriteReg(GPIO_MODE11, GPIO_MODE_REG11);
   DRV_GPIO_WriteReg(GPIO_MODE12, GPIO_MODE_REG12);
   DRV_GPIO_WriteReg(GPIO_MODE13, GPIO_MODE_REG13);
   DRV_GPIO_WriteReg(GPIO_MODE14, GPIO_MODE_REG14);
   DRV_GPIO_WriteReg(GPIO_MODE15, GPIO_MODE_REG15);
   DRV_GPIO_WriteReg(GPIO_MODE16, GPIO_MODE_REG16);
   DRV_GPIO_WriteReg(GPIO_MODE17, GPIO_MODE_REG17);
   DRV_GPIO_WriteReg(GPIO_MODE18, GPIO_MODE_REG18);
   DRV_GPIO_WriteReg(GPIO_MODE19, GPIO_MODE_REG19);
   DRV_GPIO_WriteReg(GPIO_MODE20, GPIO_MODE_REG20);
   DRV_GPIO_WriteReg(GPIO_MODE21, GPIO_MODE_REG21);
   DRV_GPIO_WriteReg(GPIO_MODE22, GPIO_MODE_REG22);
   DRV_GPIO_WriteReg(GPIO_MODE23, GPIO_MODE_REG23);
   DRV_GPIO_WriteReg(GPIO_MODE24, GPIO_MODE_REG24);
   DRV_GPIO_WriteReg(GPIO_MODE25, GPIO_MODE_REG25);
   DRV_GPIO_WriteReg(GPIO_MODE26, GPIO_MODE_REG26);
   DRV_GPIO_WriteReg(GPIO_MODE27, GPIO_MODE_REG27);
#elif defined(DRV_GPIO_REG_AS_6251)
   DRV_GPIO_WriteReg(GPIO_MODE1, GPIO_MODE_REG1);
   DRV_GPIO_WriteReg(GPIO_MODE2, GPIO_MODE_REG2);
   DRV_GPIO_WriteReg(GPIO_MODE3, GPIO_MODE_REG3);
   DRV_GPIO_WriteReg(GPIO_MODE4, GPIO_MODE_REG4);
   DRV_GPIO_WriteReg(GPIO_MODE5, GPIO_MODE_REG5);
   DRV_GPIO_WriteReg(GPIO_MODE6, GPIO_MODE_REG6);
   DRV_GPIO_WriteReg(GPIO_MODE7, GPIO_MODE_REG7);
   DRV_GPIO_WriteReg(GPIO_MODE8, GPIO_MODE_REG8);
#endif //defined(DRV_GPIO_REG_AS_6255)
#if defined(DRV_GPIO_REG_AS_6256)
   DRV_GPIO_WriteReg(GPIO_MODE1, GPIO_MODE_REG1);
   DRV_GPIO_WriteReg(GPIO_MODE2, GPIO_MODE_REG2);
   DRV_GPIO_WriteReg(GPIO_MODE3, GPIO_MODE_REG3);
   DRV_GPIO_WriteReg(GPIO_MODE4, GPIO_MODE_REG4);
   DRV_GPIO_WriteReg(GPIO_MODE5, GPIO_MODE_REG5);
   DRV_GPIO_WriteReg(GPIO_MODE6, GPIO_MODE_REG6);
   DRV_GPIO_WriteReg(GPIO_MODE7, GPIO_MODE_REG7);
   DRV_GPIO_WriteReg(GPIO_MODE8, GPIO_MODE_REG8);
   DRV_GPIO_WriteReg(GPIO_MODE9, GPIO_MODE_REG9);
   DRV_GPIO_WriteReg(GPIO_MODE10, GPIO_MODE_REG10);
   DRV_GPIO_WriteReg(GPIO_MODE11, GPIO_MODE_REG11);
   DRV_GPIO_WriteReg(GPIO_MODE12, GPIO_MODE_REG12);
   DRV_GPIO_WriteReg(GPIO_MODE13, GPIO_MODE_REG13);
   DRV_GPIO_WriteReg(GPIO_MODE14, GPIO_MODE_REG14);
   DRV_GPIO_WriteReg(GPIO_MODE15, GPIO_MODE_REG15);
   DRV_GPIO_WriteReg(GPIO_MODE16, GPIO_MODE_REG16);
   DRV_GPIO_WriteReg(GPIO_MODE17, GPIO_MODE_REG17);
   DRV_GPIO_WriteReg(GPIO_MODE18, GPIO_MODE_REG18);
   DRV_GPIO_WriteReg(GPIO_MODE19, GPIO_MODE_REG19);
   DRV_GPIO_WriteReg(GPIO_MODE20, GPIO_MODE_REG20);
   DRV_GPIO_WriteReg(GPIO_MODE21, GPIO_MODE_REG21);
   DRV_GPIO_WriteReg(GPIO_MODE22, GPIO_MODE_REG22);
   DRV_GPIO_WriteReg(GPIO_MODE23, GPIO_MODE_REG23);
   DRV_GPIO_WriteReg(GPIO_MODE24, GPIO_MODE_REG24);
   DRV_GPIO_WriteReg(GPIO_MODE25, GPIO_MODE_REG25);
   DRV_GPIO_WriteReg(GPIO_MODE26, GPIO_MODE_REG26);
   DRV_GPIO_WriteReg(GPIO_MODE27, GPIO_MODE_REG27);
#endif //defined(DRV_GPIO_REG_AS_6256)
#endif //defined(DRV_GPIO_MODE_4BITS)

#if defined(DRV_GPIO_REG_AS_6205B)
   DRV_GPIO_WriteReg(GPIO_DIR, GPIO_DIR_REG1);
   DRV_GPIO_WriteReg(GPIO_DIR2, GPIO_DIR_REG2);
#elif defined(DRV_GPIO_REG_AS_TK6516)
   DRV_GPIO_WriteReg(GPIO_DIR1, GPIO_DIR_REG1);
#elif defined(DRV_GPIO_REG_AS_6270A)
   DRV_GPIO_WriteReg(GPIO_DIR1, GPIO_DIR_REG1);
   DRV_GPIO_WriteReg(GPIO_DIR2, GPIO_DIR_REG2);
#else  /* defined(DRV_GPIO_REG_AS_6270A) */
   
   DRV_GPIO_WriteReg(GPIO_DIR1, GPIO_DIR_REG1);
   DRV_GPIO_WriteReg(GPIO_DIR2, GPIO_DIR_REG2);
   #if !defined(DRV_GPIO_REG_AS_6290)
   DRV_GPIO_WriteReg(GPIO_DIR3, GPIO_DIR_REG3);
   #endif
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E)|| defined(DRV_GPIO_REG_AS_6253E_1)
   DRV_GPIO_WriteReg(GPIO_DIR4, GPIO_DIR_REG4);
      #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6253E_1)
      DRV_GPIO_WriteReg(GPIO_DIR5, GPIO_DIR_REG5);
      #endif
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T)
      DRV_GPIO_WriteReg(GPIO_DIR5, GPIO_DIR_REG5);
      DRV_GPIO_WriteReg(GPIO_DIR6, GPIO_DIR_REG6);
      #endif
      #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
      DRV_GPIO_WriteReg(GPIO_DIR5, GPIO_DIR_REG5);
      DRV_GPIO_WriteReg(GPIO_DIR6, GPIO_DIR_REG6);
      DRV_GPIO_WriteReg(GPIO_DIR7, GPIO_DIR_REG7);
      #endif
   #elif defined(DRV_GPIO_REG_AS_6256)  || defined(DRV_GPIO_REG_AS_6255)
    DRV_GPIO_WriteReg(GPIO_DIR4, GPIO_DIR_REG4);
    DRV_GPIO_WriteReg(GPIO_DIR5, GPIO_DIR_REG5);
    DRV_GPIO_WriteReg(GPIO_DIR6, GPIO_DIR_REG6);
    DRV_GPIO_WriteReg(GPIO_DIR7, GPIO_DIR_REG7); 
   #endif
#endif

#if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_TK6516) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6270A) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6251) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6253E_1) || defined(DRV_GPIO_REG_AS_6256)  || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6290)
   DRV_GPIO_WriteReg(GPIO_PULLSEL1, GPIO_PULLSEL_REG1);
#if !defined(DRV_GPIO_REG_AS_TK6516)
   DRV_GPIO_WriteReg(GPIO_PULLSEL2, GPIO_PULLSEL_REG2);
   #if !defined(DRV_GPIO_REG_AS_6270A) && !defined(DRV_GPIO_REG_AS_6290)
   DRV_GPIO_WriteReg(GPIO_PULLSEL3, GPIO_PULLSEL_REG3);
   #if !defined(DRV_GPIO_REG_AS_6251)
   DRV_GPIO_WriteReg(GPIO_PULLSEL4, GPIO_PULLSEL_REG4);
   #if !defined(DRV_GPIO_REG_AS_6253E)
   DRV_GPIO_WriteReg(GPIO_PULLSEL5, GPIO_PULLSEL_REG5);
   #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) 
   DRV_GPIO_WriteReg(GPIO_PULLSEL6, GPIO_PULLSEL_REG6);
   #endif
   #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255)
   DRV_GPIO_WriteReg(GPIO_PULLSEL6, GPIO_PULLSEL_REG6);
   DRV_GPIO_WriteReg(GPIO_PULLSEL7, GPIO_PULLSEL_REG7);
   #endif
   #endif //!defined(DRV_GPIO_REG_AS_6253E)
   #endif //!defined(DRV_GPIO_REG_AS_6251)
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */
#endif

#if defined(DRV_GPIO_REG_AS_6205B)
   DRV_GPIO_WriteReg(GPIO_PULLEN, GPIO_PULL_REG1);
   DRV_GPIO_WriteReg(GPIO_PULLEN2, GPIO_PULL_REG2);
#elif defined(DRV_GPIO_REG_AS_TK6516)
   DRV_GPIO_WriteReg(GPIO_PULLEN1, GPIO_PULL_REG1);
#elif defined(DRV_GPIO_REG_AS_6270A)
   DRV_GPIO_WriteReg(GPIO_PULLEN1, GPIO_PULL_REG1);
   DRV_GPIO_WriteReg(GPIO_PULLEN2, GPIO_PULL_REG2);
#else  /* defined(DRV_GPIO_REG_AS_6270A) */
   DRV_GPIO_WriteReg(GPIO_PULLEN1, GPIO_PULL_REG1);
   DRV_GPIO_WriteReg(GPIO_PULLEN2, GPIO_PULL_REG2);
   #if !defined(DRV_GPIO_REG_AS_6290)
   DRV_GPIO_WriteReg(GPIO_PULLEN3, GPIO_PULL_REG3);
   #endif
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6253E_1)
   DRV_GPIO_WriteReg(GPIO_PULLEN4, GPIO_PULL_REG4);
      #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6253E_1)
      DRV_GPIO_WriteReg(GPIO_PULLEN5, GPIO_PULL_REG5);
      #endif
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) 
      DRV_GPIO_WriteReg(GPIO_PULLEN5, GPIO_PULL_REG5);
      DRV_GPIO_WriteReg(GPIO_PULLEN6, GPIO_PULL_REG6);
      #endif
      #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
      DRV_GPIO_WriteReg(GPIO_PULLEN5, GPIO_PULL_REG5);
      DRV_GPIO_WriteReg(GPIO_PULLEN6, GPIO_PULL_REG6);
      DRV_GPIO_WriteReg(GPIO_PULLEN7, GPIO_PULL_REG7);
      #endif
   #elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255)
      DRV_GPIO_WriteReg(GPIO_PULLEN4, GPIO_PULL_REG4);
      DRV_GPIO_WriteReg(GPIO_PULLEN5, GPIO_PULL_REG5);
      DRV_GPIO_WriteReg(GPIO_PULLEN6, GPIO_PULL_REG6);
      DRV_GPIO_WriteReg(GPIO_PULLEN7, GPIO_PULL_REG7);
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */

#if !defined(DRV_GPIO_REG_AS_6205B)
   DRV_GPIO_WriteReg(GPIO_DINV1, GPIO_INV_REG1);
#if !defined(DRV_GPIO_REG_AS_TK6516)
   DRV_GPIO_WriteReg(GPIO_DINV2, GPIO_INV_REG2);
   #if !defined(DRV_GPIO_REG_AS_6270A) && !defined(DRV_GPIO_REG_AS_6251) && !defined(DRV_GPIO_REG_AS_6290)
   DRV_GPIO_WriteReg(GPIO_DINV3, GPIO_INV_REG3);
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228)  || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6253E_1)
   DRV_GPIO_WriteReg(GPIO_DINV4, GPIO_INV_REG4);
      #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6253E_1)
      DRV_GPIO_WriteReg(GPIO_DINV5, GPIO_INV_REG5);
      #endif
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) 
      DRV_GPIO_WriteReg(GPIO_DINV5, GPIO_INV_REG5);
      DRV_GPIO_WriteReg(GPIO_DINV6, GPIO_INV_REG6);
      #endif
      #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
      DRV_GPIO_WriteReg(GPIO_DINV5, GPIO_INV_REG5);
      DRV_GPIO_WriteReg(GPIO_DINV6, GPIO_INV_REG6);
      DRV_GPIO_WriteReg(GPIO_DINV7, GPIO_INV_REG7);
      #endif
   #elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255)
      DRV_GPIO_WriteReg(GPIO_DINV4, GPIO_INV_REG4); 
      DRV_GPIO_WriteReg(GPIO_DINV5, GPIO_INV_REG5);
      DRV_GPIO_WriteReg(GPIO_DINV6, GPIO_INV_REG6);
      DRV_GPIO_WriteReg(GPIO_DINV7, GPIO_INV_REG7);  
   #endif
   #endif //!defined(DRV_GPIO_REG_AS_6270A)
#endif /* !defined(DRV_GPIO_REG_AS_TK6516) */
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */

#if defined(DRV_GPIO_REG_AS_6205B)
   DRV_GPIO_WriteReg(GPIO_DOUT, GPIO_OUTPUT_REG1);
   DRV_GPIO_WriteReg(GPIO_DOUT2, GPIO_OUTPUT_REG2);
#elif defined(DRV_GPIO_REG_AS_TK6516)
   DRV_GPIO_WriteReg(GPIO_DOUT1, GPIO_OUTPUT_REG1);
#elif defined(DRV_GPIO_REG_AS_6270A)
   DRV_GPIO_WriteReg(GPIO_DOUT1, GPIO_OUTPUT_REG1);
   DRV_GPIO_WriteReg(GPIO_DOUT2, GPIO_OUTPUT_REG2);
#else  /* defined(DRV_GPIO_REG_AS_6270A) */
   DRV_GPIO_WriteReg(GPIO_DOUT1, GPIO_OUTPUT_REG1);
   DRV_GPIO_WriteReg(GPIO_DOUT2, GPIO_OUTPUT_REG2);
   #if !defined(DRV_GPIO_REG_AS_6290)
   DRV_GPIO_WriteReg(GPIO_DOUT3, GPIO_OUTPUT_REG3);
   #endif
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6276) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6253E_1)
   DRV_GPIO_WriteReg(GPIO_DOUT4, GPIO_OUTPUT_REG4);
      #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6235) || defined(DRV_GPIO_REG_AS_6236) || defined(DRV_GPIO_REG_AS_6253E_1)
      DRV_GPIO_WriteReg(GPIO_DOUT5, GPIO_OUTPUT_REG5);
      #endif
      #if defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6255)
      DRV_GPIO_WriteReg(GPIO_DOUT5, GPIO_OUTPUT_REG5);
      DRV_GPIO_WriteReg(GPIO_DOUT6, GPIO_OUTPUT_REG6);
      #endif
      #if defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6276)
      DRV_GPIO_WriteReg(GPIO_DOUT5, GPIO_OUTPUT_REG5);
      DRV_GPIO_WriteReg(GPIO_DOUT6, GPIO_OUTPUT_REG6);
      DRV_GPIO_WriteReg(GPIO_DOUT7, GPIO_OUTPUT_REG7);
      #endif
   #elif defined(DRV_GPIO_REG_AS_6256) || defined(DRV_GPIO_REG_AS_6255)
      DRV_GPIO_WriteReg(GPIO_DOUT4, GPIO_OUTPUT_REG4);
      DRV_GPIO_WriteReg(GPIO_DOUT5, GPIO_OUTPUT_REG5);
      DRV_GPIO_WriteReg(GPIO_DOUT6, GPIO_OUTPUT_REG6);
      DRV_GPIO_WriteReg(GPIO_DOUT7, GPIO_OUTPUT_REG7); 
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */
#if (!defined(DRV_GPIO_WO_GPO))
   DRV_GPIO_WriteReg(GPO_DOUT, GPO_OUTPUT_REG1);
#endif

#if defined(DRV_GPIO_REG_AS_6253E)
   DRV_GPIO_WriteReg(GPIO_SPMODE, GPIO_SPMODE_REG);
   DRV_GPIO_WriteReg(GPIO_BANK, GPIO_BANK_REG);
#elif defined(DRV_GPIO_REG_AS_6253E_1)
   DRV_GPIO_WriteReg32(GPIO_SPMODE0, GPIO_SPMODE0_REG);
   DRV_GPIO_WriteReg32(GPIO_SPMODE1, GPIO_SPMODE1_REG);
#endif //defined(DRV_GPIO_REG_AS_6253E)

#if defined(MT6276_S01)
   DRV_GPIO_WriteReg32(CLK_MUX_SEL0, CLK_MUX_SEL0_VALUE);
   DRV_GPIO_WriteReg32(CLK_MUX_SEL1, CLK_MUX_SEL1_VALUE);
#endif

#endif /* __CHIP_SUPP_GPIO_DRV_TOOL__*/
#endif /*!defined(DRV_GPIO_OFF)*/
}

#endif /* __CUST_NEW__ */

/*********************************************************************************************/
/*********************************************************************************************/ 
/************************************** GPIO_Setting_init*************************************/
/************************************END******************************************************/
