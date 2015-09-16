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
 *    gpio.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the GPIO driver.
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
#include "drv_comm.h"
#include "reg_base.h"
#include "gpio_hw.h"
#include "gpio_sw.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#ifdef __AST_TL1_TDD__
#include "gpio_md.h"
#endif
#ifndef BL_ENABLE
//#define __GPIO_CHECK_WARNING__
#define __GPIO_CHECK_ASSERT__
#endif /* BL_ENABLE */
#ifdef __GPIO_CHECK_WARNING__
#include <stdio.h>
static kal_char buff[40];
#endif

#if !defined(__FUE__)
   #define SAVEANDSETIRQMASK()      SaveAndSetIRQMask()
   #define RESTOREIRQMASK(mask)     RestoreIRQMask(mask)
#else /*defined(__FUE__)*/
   #define SAVEANDSETIRQMASK()      0
   #define RESTOREIRQMASK(mask)     {}
#endif /*defined(__FUE__)*/

#define DCL_GPIO_MD_MAGIC_NUMBER  0X00001000

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
#if defined(DRV_GPIO_6280_SPECIAL_SET_REG)
const kal_uint16  gpio_6280_special_index[]={61,62,63,64,65,66,84,85,86,87,88,89};
const  MT6280_GPIO_PULL_EN_SELL_MAP_Table_T  gpio_6280_Spec_map[]={
		
			{0,3,14,4},  //GPIO_61 ,first element :0--puller,1--pullsel
			{0,4,0,5},  //GPIO_62
			{0,4,2,6},  //GPIO_63
			{1,3,14,7},  //GPIO_64
			{1,4,0,8},  //GPIO_65
			{1,4,2,9},  //GPIO_66
			{0,5,5,10},  //GPIO_84
			{0,5,7,11},  //GPIO_85
			{0,5,9,12},  //GPIO_86
			{1,5,5,13},  //GPIO_87
			{1,5,7,14},  //GPIO_88
			{1,5,9,15},  //GPIO_89
};

#endif

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   /*conf_data = 0~3*/
   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;
      kal_uint32 savedMask;

      pin &= 0x00ff;
      modeno = pin/8;
      remainder = pin % 8;
      savedMask = SAVEANDSETIRQMASK();
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
      DRV_GPIO_WriteReg(GPIO_MODE(modeno),data);
      RESTOREIRQMASK(savedMask);
#endif /*!defined(DRV_GPIO_OFF)*/
   }
   
   void GPIO_ModeSetup_FAST(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;

      pin &= 0x00ff;
      modeno = pin/8;
      remainder = pin % 8;
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
      DRV_GPIO_WriteReg(GPIO_MODE(modeno),data);
#endif /*!defined(DRV_GPIO_OFF)*/
   }
 
   
   /*conf_data = 0~3*/
   void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 mode; 
      kal_uint32 savedMask;
      
      pin &= 0x00ff;
      savedMask = SAVEANDSETIRQMASK();
      mode = DRV_GPIO_Reg(GPI_O_MODE);
      mode &= ~(0x0003 << (pin*2));
      mode |= (conf_dada << (pin*2));
      DRV_GPIO_WriteReg(GPI_O_MODE,mode);
      RESTOREIRQMASK(savedMask);
#endif /*!defined(DRV_GPIO_OFF)*/
   }
#endif   /*DRV_GPIO_6208_FUNC, FPGA*/

#if defined(DRV_GPIO_6205_FUNC)
   /*conf_data = 0~3*/
   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint32 savedMask;
      
      pin &= 0x00ff;
      modeno = pin/8;
      remainder = pin % 8;
      
      savedMask = SAVEANDSETIRQMASK();
      *(GPIO_MODE(modeno)) &= ~(0x0003 << (remainder*2));
      *(GPIO_MODE(modeno)) |= (conf_dada << (remainder*2));
      RESTOREIRQMASK(savedMask);
#endif /*!defined(DRV_GPIO_OFF)*/
   }
   
   
   void GPIO_ModeSetup_FAST(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      
      pin &= 0x00ff;
      modeno = pin/8;
      remainder = pin % 8;
      
      *(GPIO_MODE(modeno)) &= ~(0x0003 << (remainder*2));
      *(GPIO_MODE(modeno)) |= (conf_dada << (remainder*2));
#endif /*!defined(DRV_GPIO_OFF)*/
   }
   
   
   /*conf_data = 0~3*/
   void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 mode; 
      kal_uint32 savedMask;
      
      pin &= 0x00ff;
      savedMask = SAVEANDSETIRQMASK();
      mode = DRV_GPIO_Reg(GPIO_MODE4);
      mode &= ~(0x0003 << (pin*2));
      mode |= (conf_dada << (pin*2));
      DRV_GPIO_WriteReg(GPIO_MODE4,mode);
      RESTOREIRQMASK(savedMask);
#endif /*!defined(DRV_GPIO_OFF)*/
   }
#endif   /*DRV_GPIO_6205_FUNC*/

#if defined(DRV_GPIO_6205B_FUNC)
   /*conf_data = 0~3*/
   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;
      kal_uint32 savedMask;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_ModeSetup: GPIO Mode Not allowed");
             ret = sprintf(buff, "pin=%d, mode=%d", pin, conf_dada);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
      modeno = pin/8;
      remainder = pin % 8;
      
      savedMask = SAVEANDSETIRQMASK();
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
      DRV_GPIO_WriteReg(GPIO_MODE(modeno),data);
      RESTOREIRQMASK(savedMask);

      //DRV_GPIO_WriteReg(GPIO_MODE_CLR(modeno),(0x0003 << (remainder*2)));
      //DRV_GPIO_WriteReg(GPIO_MODE_SET(modeno),(conf_dada << (remainder*2)));
#endif /*!defined(DRV_GPIO_OFF)*/
   }
   
   void GPIO_ModeSetup_FAST(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_ModeSetup_FAST: GPIO Mode Not allowed");
             ret = sprintf(buff, "pin=%d, mode=%d", pin, conf_dada);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
      modeno = pin/8;
      remainder = pin % 8;
      
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
      DRV_GPIO_WriteReg(GPIO_MODE(modeno),data);

      //DRV_GPIO_WriteReg(GPIO_MODE_CLR(modeno),(0x0003 << (remainder*2)));
      //DRV_GPIO_WriteReg(GPIO_MODE_SET(modeno),(conf_dada << (remainder*2)));
#endif /*!defined(DRV_GPIO_OFF)*/
   }
 
   
   
   /*conf_data = 0~3*/
   void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 mode; 
      kal_uint32 savedMask;

      pin &= 0x00ff;
      #ifdef __CUST_NEW__   	
      pin &= (~GPO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpo_mode_allowed[conf_dada & 3]) & (1<<(pin & 0x0f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPO_ModeSetup: GPO Mode Not allowed");
             ret = sprintf(buff, "pin=%d, mode=%d", pin, conf_dada);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpo_mode_allowed[conf_dada & 3]) & (1<<(pin & 0x0f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
	     gpo_check_for_write[pin>>4] |= (1 << (pin & 0x0f));
      }
      #endif /* __CUST_NEW__ */
      savedMask = SAVEANDSETIRQMASK();
      mode = DRV_GPIO_Reg(GPIO_MODE4);
      mode &= ~(0x0003 << (pin*2));
      mode |= (conf_dada << (pin*2));
      DRV_GPIO_WriteReg(GPIO_MODE4,mode);
      RESTOREIRQMASK(savedMask);

      //DRV_GPIO_WriteReg(GPIO_MODE4_CLR,(0x0003 << (pin*2)));
      //DRV_GPIO_WriteReg(GPIO_MODE4_SET,(conf_dada << (pin*2)));
#endif /*!defined(DRV_GPIO_OFF)*/
   }
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_FULL_FUNC)
   #if defined(DRV_GPIO_MODE_4BITS)
   /*conf_data = 0~7*/
   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint32 savedMask;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #if defined(__GPIO_CHECK_ASSERT__)
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 7]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
   #if defined(GPIO_MODE_32BIT_LENGTH)
      modeno = pin/8;
      remainder = pin % 8;      
      savedMask = SAVEANDSETIRQMASK();
      DRV_GPIO_SetData32(GPIO_MODE(modeno), (0x7 << (4*remainder)), (conf_dada << (4*remainder)));
      RESTOREIRQMASK(savedMask);
   #else //defined(GPIO_MODE_32BIT_LENGTH)
      modeno = pin/4;
      remainder = pin % 4;      
      savedMask = SAVEANDSETIRQMASK();
      DRV_GPIO_SetData(GPIO_MODE(modeno), (0x7 << (4*remainder)), (conf_dada << (4*remainder)));
      RESTOREIRQMASK(savedMask);
   #endif //defined(GPIO_MODE_32BIT_LENGTH)

#endif /*!defined(DRV_GPIO_OFF)*/
   }
char GPIO_ReturnMode(char port)
{
   #if !defined(DRV_GPIO_OFF)
   kal_uint16 modeno;
   kal_uint16 remainder;
   kal_uint32 data;   
   #ifdef __CUST_NEW__
      port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
    #if defined(GPIO_MODE_32BIT_LENGTH)
      modeno = port/8;
      remainder = port % 8;      
      data=DRV_GPIO_Reg32(GPIO_MODE(modeno)); 
      data=data&(0x7 << (4*remainder));
      data=(data >> (4*remainder));
      return (char)data;
   #else //defined(GPIO_MODE_32BIT_LENGTH)
      modeno = port/4;
      remainder = port % 4;      
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data=data&(0x7 << (4*remainder));
      data=(data >> (4*remainder));
      return (char)data;
   #endif //defined(GPIO_MODE_32BIT_LENGTH)   
   #else  /*!defined(DRV_GPIO_OFF)*/   
   return 0;
   #endif /*!defined(DRV_GPIO_OFF)*/
} 
   void GPIO_ModeSetup_FAST(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #if defined(__GPIO_CHECK_ASSERT__)
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 7]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
   #if defined(GPIO_MODE_32BIT_LENGTH)
      modeno = pin/8;
      remainder = pin % 8;      
      DRV_GPIO_SetData32(GPIO_MODE(modeno), (0x7 << (4*remainder)), (conf_dada << (4*remainder)));
   #else //defined(GPIO_MODE_32BIT_LENGTH)
      modeno = pin/4;
      remainder = pin % 4;      
      DRV_GPIO_SetData(GPIO_MODE(modeno), (0x7 << (4*remainder)), (conf_dada << (4*remainder)));
   #endif //defined(GPIO_MODE_32BIT_LENGTH)

#endif /*!defined(DRV_GPIO_OFF)*/
   }
 #elif defined(DRV_GPIO_MODE_3BITS)   
void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
{
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint32 savedMask;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #if defined(__GPIO_CHECK_ASSERT__)
	  //there is a bug.
	  //is conf_data is big the 5, than access a address large than gpio_mode_allowed . -->may cause fatal error 
	  	  if(conf_dada>=5)
		  	{ASSERT(0);}
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 7]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
      modeno = pin/5;
      remainder = pin % 5;      
      savedMask = SAVEANDSETIRQMASK();
      DRV_GPIO_SetData(GPIO_MODE(modeno), (0x7 << (3*remainder)), (conf_dada << (3*remainder)));
      RESTOREIRQMASK(savedMask);
#endif /*!defined(DRV_GPIO_OFF)*/
}

void GPIO_ModeSetup_FAST(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #if defined(__GPIO_CHECK_ASSERT__)
	  	  if(conf_dada>=5)
		  	{ASSERT(0);}
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 7]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
      modeno = pin/5;
      remainder = pin % 5;      
      DRV_GPIO_SetData(GPIO_MODE(modeno), (0x7 << (3*remainder)), (conf_dada << (3*remainder)));
#endif /*!defined(DRV_GPIO_OFF)*/
   }
 char GPIO_ReturnMode(char port)
{
   #if !defined(DRV_GPIO_OFF)
   kal_uint16 modeno;
   kal_uint16 remainder;
   kal_uint32 data;   
   #ifdef __CUST_NEW__
      port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   modeno = port/5;
   remainder = port % 5;      
   data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
   data=data&(0x7 << (3*remainder));
   data=(data >> (3*remainder));
   return (char)data;
   #else  /*!defined(DRV_GPIO_OFF)*/   
   return 0;
   #endif /*!defined(DRV_GPIO_OFF)*/  
}     
#else //defined(DRV_GPIO_MODE_4BITS)
   /*conf_data = 0~3*/
   void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;
      kal_uint32 savedMask;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f))))
            {
			    kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_ModeSetup: GPIO Mode Not allowed");
             ret = sprintf(buff, "pin=%d, mode=%d", pin, conf_dada);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
      modeno = pin/8;
      remainder = pin % 8;
      #if defined(DRV_GPIO_MODE8_SPECIAL_POS)
      if(pin>=56)/*special case  */
      {
         kal_uint16 mode; 

         savedMask = SAVEANDSETIRQMASK();
         mode = DRV_GPIO_Reg(GPIO_MODE8);
         mode &= ~(0x0003 << (remainder*2));
         mode |= (conf_dada << (remainder*2));
         DRV_GPIO_WriteReg(GPIO_MODE8,mode);
         RESTOREIRQMASK(savedMask);
         //DRV_GPIO_WriteReg(GPIO_MODE8_CLR,(0x0003 << (remainder*2)));
         //DRV_GPIO_WriteReg(GPIO_MODE8_SET,(conf_dada << (remainder*2)));
         return;
      }
      #endif                  
      
      savedMask = SAVEANDSETIRQMASK();
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
#ifdef DRV_GPIO_REG_AS_6223
      if ((modeno == 5) && (pin != 44))
         data ^= 0x0100; //mode44 LSB: set and clear are inversed in MT6223.
      else if ((modeno == 6) && (pin != 50))
         data ^= 0x0010; //mode50 LSB: set and clear are inversed in MT6223.
#endif
      DRV_GPIO_WriteReg(GPIO_MODE(modeno),data);
      RESTOREIRQMASK(savedMask);

      //DRV_GPIO_WriteReg(GPIO_MODE_CLR(modeno),(0x0003 << (remainder*2)));
      //DRV_GPIO_WriteReg(GPIO_MODE_SET(modeno),(conf_dada << (remainder*2)));
#endif /*!defined(DRV_GPIO_OFF)*/
   }
   
   void GPIO_ModeSetup_FAST(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 data;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__
      pin &= (~GPIO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPIO_ModeSetup_FAST: GPIO Mode Not allowed");
             ret = sprintf(buff, "pin=%d, mode=%d", pin, conf_dada);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
          ASSERT((gpio_mode_allowed[pin>>5][conf_dada & 3]) & (1<<(pin & 0x1f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
		  gpio_check_for_write[pin>>5] |= (1 << (pin & 0x1f));
		  gpio_check_for_read[pin>>5] |= (1 << (pin & 0x1f));
      }
      #endif /* __CUST_NEW__ */
      modeno = pin/8;
      remainder = pin % 8;
      #if defined(DRV_GPIO_MODE8_SPECIAL_POS)
      if(pin>=56)/*special case  */
      {
         kal_uint16 mode; 

         mode = DRV_GPIO_Reg(GPIO_MODE8);
         mode &= ~(0x0003 << (remainder*2));
         mode |= (conf_dada << (remainder*2));
         DRV_GPIO_WriteReg(GPIO_MODE8,mode);

         //DRV_GPIO_WriteReg(GPIO_MODE8_CLR,(0x0003 << (remainder*2)));
         //DRV_GPIO_WriteReg(GPIO_MODE8_SET,(conf_dada << (remainder*2)));
         return;
      }
      #endif                  
      
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data&=~(0x3 << (2*remainder));
      data|= (conf_dada << (remainder*2));
#ifdef DRV_GPIO_REG_AS_6223
      if ((modeno == 5) && (pin != 44))
         data ^= 0x0100; //mode44 LSB: set and clear are inversed in MT6223.
      else if ((modeno == 6) && (pin != 50))
         data ^= 0x0010; //mode50 LSB: set and clear are inversed in MT6223.
#endif
      DRV_GPIO_WriteReg(GPIO_MODE(modeno),data);

      //DRV_GPIO_WriteReg(GPIO_MODE_CLR(modeno),(0x0003 << (remainder*2)));
      //DRV_GPIO_WriteReg(GPIO_MODE_SET(modeno),(conf_dada << (remainder*2)));
#endif /*!defined(DRV_GPIO_OFF)*/
   }
char GPIO_ReturnMode(char port)
{
   #if !defined(DRV_GPIO_OFF)
   kal_uint16 modeno;
   kal_uint16 remainder;
   kal_uint32 data;   
   #ifdef __CUST_NEW__
      port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   
   #if defined(GPIO_MODE_32BIT_LENGTH)
      modeno = port/16;
      remainder = port % 16;      
      data=DRV_GPIO_Reg32(GPIO_MODE(modeno)); 
      data=data&(0x3 << (2*remainder));
      data=(data >> (2*remainder));
      return (char)data;
   #else //defined(GPIO_MODE_32BIT_LENGTH)
      modeno = port/8;
      remainder = port % 8;      
      data=DRV_GPIO_Reg(GPIO_MODE(modeno)); 
      data=data&(0x3 << (2*remainder));
      data=(data >> (2*remainder));
      return (char)data;
   #endif //defined(GPIO_MODE_32BIT_LENGTH)  
   #else  /*!defined(DRV_GPIO_OFF)*/   
   return 0;
   #endif /*!defined(DRV_GPIO_OFF)*/  
}    
   #endif //defined(DRV_GPIO_MODE_4BITS)
   
   /*conf_data = 0~3*/
   void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {
#if !defined(DRV_GPIO_OFF)
   #if !defined(DRV_GPIO_WO_GPO)
      kal_uint16 mode; 
      kal_uint32 savedMask;

      pin &= 0x00ff;
      #ifdef __CUST_NEW__   	
      pin &= (~GPO_MAGIC_NUM);
      if (gpio_debug_enable == KAL_TRUE)
      {
      #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
            if (!((gpo_mode_allowed[conf_dada & 3]) & (1<<(pin & 0x0f))))
            {
               kal_int32 ret;
             system_print("GPIO WARNING!! GPO_ModeSetup: GPO Mode Not allowed");
             ret = sprintf(buff, "pin=%d, mode=%d", pin, conf_dada);
             system_print(buff);
            }
         }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT((gpo_mode_allowed[conf_dada & 3]) & (1<<(pin & 0x0f)));
		#endif  /* __GPIO_CHECK_WARNING__ */
	     gpo_check_for_write[pin>>4] |= (1 << (pin & 0x0f));
      }
      #endif /* __CUST_NEW__ */
      savedMask = SAVEANDSETIRQMASK();
      mode = DRV_GPIO_Reg(GPO_MODE);
      mode &= ~(0x0003 << (pin*2));
      mode |= (conf_dada << (pin*2));
      DRV_GPIO_WriteReg(GPO_MODE,mode);
      RESTOREIRQMASK(savedMask);

      //DRV_GPIO_WriteReg(GPO_MODE_CLR,(0x0003 << (pin*2)));
      //DRV_GPIO_WriteReg(GPO_MODE_SET,(conf_dada << (pin*2)));
   #endif /* !defined(DRV_GPIO_WO_GPO) */
#endif /*!defined(DRV_GPIO_OFF)*/
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
*	pin : gpio pin number range from 0~54 (MT6219)
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
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      kal_uint16 gpio_index;
       kal_uint16 pull_index;
      pin &= 0x00ff;
      #ifdef __CUST_NEW__   	
      pin &= (~GPIO_MAGIC_NUM);
      #endif /* __CUST_NEW__ */
      modeno = pin/16;
      remainder = pin % 16;

#if defined(DRV_GPIO_6280_SPECIAL_SET_REG)
			if(KAL_TRUE==Is_6280_SPEC_GPIO(pin))
				{
				gpio_index=get_6280_spec_index(pin);
				modeno=gpio_6280_Spec_map[gpio_index].pullen_reg_num;
				remainder=gpio_6280_Spec_map[gpio_index].pullen_remainder;
				pull_index=gpio_6280_Spec_map[gpio_index].pullen_sel_index;


				if(pull_index==0)   // which gpio pullen bit is in pullen register
					{
                     
		      if(enable)
      	          DRV_GPIO_WriteReg(GPIO_PULLEN_SET(modeno), 1 << remainder);
               else
      	           DRV_GPIO_WriteReg(GPIO_PULLEN_CLR(modeno), 1 << remainder);    

				}
				else                 // which gpio pullen bit is in  pullsel  register
					{
					   if(enable)
						DRV_GPIO_WriteReg(GPIO_PULLSEL_SET(modeno), 1 << remainder);
					 else
						DRV_GPIO_WriteReg(GPIO_PULLSEL_CLR(modeno), 1 << remainder);

					  }
				}
			if(KAL_FALSE==Is_6280_SPEC_GPIO(pin))

				{
          if(enable)
      	DRV_GPIO_WriteReg(GPIO_PULLEN_SET(modeno), 1 << remainder);
        else
      	DRV_GPIO_WriteReg(GPIO_PULLEN_CLR(modeno), 1 << remainder);      

			}
   #else   //  not 6280 GPIO
   
		if(enable)
      	DRV_GPIO_WriteReg(GPIO_PULLEN_SET(modeno), 1 << remainder);
      else
      	DRV_GPIO_WriteReg(GPIO_PULLEN_CLR(modeno), 1 << remainder);
		
#endif  //defined(DRV_GPIO_6280_SPECIAL_SET_REG)


#endif /*!defined(DRV_GPIO_OFF)*/
   }
/*
* FUNCTION                                                            
*	GPIO_DinvSetup
*
* DESCRIPTION                                                           
*   	This function is to enable data invert of the related GPIO pin
*
* PARAMETERS
*	pin : gpio pin number range from 0~54 (MT6219)
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
#if !defined(DRV_GPIO_OFF)
      kal_uint16 modeno;
      kal_uint16 remainder;
      
      pin &= 0x00ff;
      #ifdef __CUST_NEW__   	
      //ASSERT(pin&GPIO_MAGIC_NUM);
      pin &= (~GPIO_MAGIC_NUM);
      #endif /* __CUST_NEW__ */
      modeno = pin/16;
      remainder = pin % 16;

		if(enable)
      {
         DRV_GPIO_SetBits(GPIO_DINV_ADRS(modeno), (1 << remainder));
      }
      else
      {
         DRV_GPIO_ClearBits(GPIO_DINV_ADRS(modeno), (1 << remainder));
      }
#endif /*!defined(DRV_GPIO_OFF)*/
   }
   
#endif   /*DRV_GPIO_FULL_FUNC*/

/*
* FUNCTION                                                            
*	GPIO_PullSelSetup
*
* DESCRIPTION                                                           
*   	This function is to select pull up/down of the related GPIO pin.
*
* PARAMETERS
*	pin : gpio pin number range from 0~54 (MT6219)
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
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_PULL_SEL)
   kal_uint16 modeno;
   kal_uint16 remainder;
    kal_uint16 gpio_index;
   pin &= 0x00ff;
   #ifdef __CUST_NEW__   	
   pin &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   modeno = pin/16;
   remainder = pin % 16;

	#if defined(DRV_GPIO_6280_SPECIAL_SET_REG)
	    if(KAL_TRUE==Is_6280_SPEC_GPIO(pin))
	    	{
              gpio_index=get_6280_spec_index(pin);
               remainder=gpio_6280_Spec_map[gpio_index].pullsel_remainder;
        if(pull_up)

		    DRV_GPIO_WriteReg(GPIO_OTHER_SET, 1 << remainder);
       else
            DRV_GPIO_WriteReg(GPIO_OTHER_SET, 1 << remainder);

	    	}
        if(KAL_FALSE==Is_6280_SPEC_GPIO(pin))
        	{
	if(pull_up)
      DRV_GPIO_WriteReg(GPIO_PULLSEL_SET(modeno), 1 << remainder);
   else
      DRV_GPIO_WriteReg(GPIO_PULLSEL_CLR(modeno), 1 << remainder);
        	}

	#else
	
     if(pull_up)
      DRV_GPIO_WriteReg(GPIO_PULLSEL_SET(modeno), 1 << remainder);
   else
      DRV_GPIO_WriteReg(GPIO_PULLSEL_CLR(modeno), 1 << remainder);
  #endif //#  defiend(DRV_GPIO_6280_SPECIAL_SET_REG)
	
#endif /*defined(DRV_GPIO_PULL_SEL)*/
#endif /*!defined(DRV_GPIO_OFF)*/
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
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_6205_FUNC)
   if (direction == OUTPUT)
	{
	   if (port < 16)
      {
         DRV_GPIO_SetBits(GPIO_DIR, (1 << port));
      }
      else
      {
         DRV_GPIO_SetBits(GPIO_DIR2, (1 << (port-16)));
      }
	}
	else
	{
	   if (port < 16)
      {
         DRV_GPIO_ClearBits(GPIO_DIR, (1 << port));
      }
		else
      {
         DRV_GPIO_ClearBits(GPIO_DIR2, (1 << (port-16));
      }
	}
#endif /*DRV_GPIO_6205_FUNC*/

#if defined(DRV_GPIO_6205B_FUNC)
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
   if (direction == OUTPUT)
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DIR_SET,(1 << port));
      else
         DRV_GPIO_WriteReg(GPIO_DIR2_SET,(1 << (port-16)));
	}
	else
	{
	   if (port < 16)
		   DRV_GPIO_WriteReg(GPIO_DIR_CLR,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DIR2_CLR,(1 << (port-16)));
	}
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
      
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
   no = port/16;
   remainder = port % 16;
   if (direction == OUTPUT)
      DRV_GPIO_WriteReg(GPIO_DIR_SET(no),(1 << remainder));
	else
      DRV_GPIO_WriteReg(GPIO_DIR_CLR(no),(1 << remainder));
#endif   /*DRV_GPIO_FULL_FUNC*/

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
	if (direction == OUTPUT)
	{
      DRV_GPIO_SetBits(GPIO_DIR, (1 << port));
	}
	else
	{
      DRV_GPIO_ClearBits(GPIO_DIR, (1 << port));
	}
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
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
*/
char GPIO_ReadIO(char port)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
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
   if (port < 16)
	   return((DRV_GPIO_Reg(GPIO_DIN) >> port) & 1);
	else
	   return((DRV_GPIO_Reg(GPIO_DIN2) >> (port-16)) & 1);
#endif /*DRV_GPIO_6205_FUNC, DRV_GPIO_6205B_FUNC*/
#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   return((DRV_GPIO_Reg(GPIO_DIN) >> port) & 1);
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/
#if defined(DRV_GPIO_FULL_FUNC)
#if defined(DRV_GPIO_DIN_DISCONT)
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
   if (port < 16)
	   return((DRV_GPIO_Reg(GPIO_DIN1) >> port) & 1);
	else if (port < 32)
	   return((DRV_GPIO_Reg(GPIO_DIN2) >> (port-16)) & 1);
	else if (port < 48)
	   return((DRV_GPIO_Reg(GPIO_DIN3) >> (port-32)) & 1);
	#if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6225)
	else if (port < 64)
	   return((DRV_GPIO_Reg(GPIO_DIN4) >> (port-48)) & 1);
	#endif
   else
   {
      ASSERT(0);
      return 0;
   }
#endif /* DRV_GPIO_DIN_DISCONT*/
#if defined(DRV_GPIO_DIN_CONTI)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data;   
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
   #if defined(DRV_GPIO_REG_AS_6228)
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
   #endif /* DRV_GPIO_REG_AS_6228 */
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         char dir;
         dir = GPIO_ReturnDir(port);
         if (dir != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO: direction is not correct.");
          ret = sprintf(buff, "pin=%d, direction=%d", port, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnDir(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_read[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
         		
   data=DRV_GPIO_Reg(GPIO_DIN(no));   
   data=data&(1 << remainder);
   data=(data >> remainder);
   return (char)data;
   
#endif   /*DRV_GPIO_DIN_CONTI*/
#else /* DRV_GPIO_FULL_FUNC */
   return 0;
#endif /* DRV_GPIO_FULL_FUNC */
#endif /*!defined(DRV_GPIO_OFF)*/
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
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_6205_FUNC)
	if (data == 1)
	{
	   if (port < 16)
      {
         DRV_GPIO_SetBits(GPIO_DOUT, (1 << port));
      }
		else
      {
         DRV_GPIO_SetBits(GPIO_DOUT2, (1 << (port-16)));
      }
	}
	else
	{
	   if (port < 16)
      {
         DRV_GPIO_ClearBits(GPIO_DOUT, (1 << port));
      }
		else
      {
         DRV_GPIO_ClearBits(GPIO_DOUT2, (1 << (port-16))));
      }
	}
#endif /*(DRV_GPIO_6205_FUNC)*/

#if defined(DRV_GPIO_6205B_FUNC)
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
	if (data == 1)
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DOUT_SET,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DOUT2_SET,(1 << (port-16)));
	}
	else
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DOUT_CLR,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DOUT2_CLR,(1 << (port-16)));
	}
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
	if (data == 1)
	{
      DRV_GPIO_SetBits(GPIO_DOUT, (1 << port));
	}
	else
	{
      DRV_GPIO_ClearBits(GPIO_DOUT, (1 << port));
	}
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/

#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
      
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
   #if defined(DRV_GPIO_REG_AS_6228)
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
   #endif /*DRV_GPIO_REG_AS_6228*/
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
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
          system_print("GPIO WARNING!! GPIO_WriteIO: direction is not correct.");
          ret = sprintf(buff, "pin=%d, direction=%d", port, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnDir(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_write[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
   if (data == 1)
      DRV_GPIO_WriteReg(GPIO_DOUT_SET(no),(1 << remainder));
	else
      DRV_GPIO_WriteReg(GPIO_DOUT_CLR(no),(1 << remainder));
#endif   /*DRV_GPIO_FULL_FUNC*/
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPI_O_ReadIO
*
* DESCRIPTION                                                           
*   	This function is to read data from one GPI pin
*
* CALLS  
*	Read data from one GPI pin
*
* PARAMETERS
*	None
*	
* RETURNS
*	1 or 0
*
* GLOBALS AFFECTED
*   external_global
*/
#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
char GPI_ReadIO_(void)
{
#if !defined(DRV_GPIO_OFF)
	return((DRV_GPIO_Reg(GPI_O_DIO) >> 15) & 1);
#endif /*!defined(DRV_GPIO_OFF)*/
}
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/
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
#if !defined(DRV_GPIO_OFF)
#if !defined(DRV_GPIO_WO_GPO)
#if defined(DRV_GPIO_6205_FUNC)
	if (data == 1)
	{
      DRV_GPIO_SetBits(GPO_DOUT, (1 << port));
	}
	else
	{
      DRV_GPIO_ClearBits(GPO_DOUT, (1 << port));
	}
#endif   /*(DRV_GPIO_6205_FUNC*/

#if defined(DRV_GPIO_6205B_FUNC)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPO_WriteIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(port & GPO_MAGIC_NUM);
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPO_MAGIC_NUM);
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpo_check_for_write[(kal_uint8)port>>4] & (1 << (port & 0x0f))))
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPO_WriteIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPO_ReturnMode(port)== 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpo_check_for_write[(kal_uint8)port>>4] &= (~(1 << (port & 0x0f)));
   }
   #endif /* __CUST_NEW__ */
	if (data == 1)
	{
	   DRV_GPIO_WriteReg(GPO_DOUT_SET,(1 << port));
	}
	else
	{
	   DRV_GPIO_WriteReg(GPO_DOUT_CLR,(1 << port));
	}
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_FULL_FUNC)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPO_WriteIO: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(port & GPO_MAGIC_NUM);
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPO_MAGIC_NUM);
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpo_check_for_write[(kal_uint8)port>>4] & (1 << (port & 0x0f))))
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPO_WriteIO: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPO_ReturnMode(port)== 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpo_check_for_write[(kal_uint8)port>>4] &= (~(1 << (port & 0x0f)));
   }
   #endif /* __CUST_NEW__ */
	if (data == 1)
	{
	   DRV_GPIO_WriteReg(GPO_DOUT_SET,(1 << port));
	}
	else
	{
	   DRV_GPIO_WriteReg(GPO_DOUT_CLR,(1 << port));
	}
#endif   /*DRV_GPIO_FULL_FUNC*/

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
	if (data == 1)
	{
      DRV_GPIO_SetBits(GPI_O_DIO, (1 << port));
	}
	else
	{
      DRV_GPIO_ClearBits(GPI_O_DIO, (1 << port));
	}
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/
#endif /*!defined(DRV_GPIO_WO_GPO)*/
#endif /*!defined(DRV_GPIO_OFF)*/

}

/*
* FUNCTION                                                            
*	GPO_WriteAll
*
* DESCRIPTION                                                           
*   	This function is to write data to all GPO pins
*
* CALLS  
*	Write data to all GPO pins
*
* PARAMETERS
*	write_data: expected GPO data to all pins
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPO_WriteAll(kal_uint16 write_data)
{
#if !defined(DRV_GPIO_OFF)
#if !defined(DRV_GPIO_WO_GPO)
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
   DRV_GPIO_WriteReg(GPO_DOUT,write_data);
#endif   /*(DRV_GPIO_6205_FUNC,DRV_GPIO_6205B_FUNC)*/
#if defined(DRV_GPIO_FULL_FUNC)
   DRV_GPIO_WriteReg(GPO_DOUT,write_data);
#endif   /*DRV_GPIO_FULL_FUNC*/
#if ( (defined(DRV_GPIO_6208_FUNC)) || (defined(FPGA)) )
   DRV_GPIO_WriteReg(GPI_O_DIO,write_data);
#endif   /*(MT6208,FPGA)*/
#endif /*!defined(DRV_GPIO_WO_GPO)*/
#endif /*!defined(DRV_GPIO_OFF)*/
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
#if !defined(DRV_GPIO_OFF)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data=0;
   #ifdef __CUST_NEW__
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;

#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
   if(0==no)
      data=DRV_GPIO_Reg(GPIO_DOUT); 
   else if(1==no)
      data=DRV_GPIO_Reg(GPIO_DOUT2); 
#endif

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   data=DRV_GPIO_Reg(GPIO_DOUT); 	
#endif

#if defined(DRV_GPIO_FULL_FUNC)
   data=DRV_GPIO_Reg(GPIO_DOUT(no)); 
#endif   
   
   data=data&(1 << remainder);
   data=(data >> remainder);
   return (char)data;
#else  /*!defined(DRV_GPIO_OFF)*/
   return 0;
#endif /*!defined(DRV_GPIO_OFF)*/
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
#if !defined(DRV_GPIO_OFF)
#if !defined(DRV_GPIO_WO_GPO)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data;   
   #ifdef __CUST_NEW__
   port &= (~GPO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;


#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   data=DRV_GPIO_Reg(GPI_O_DIO); 	
#endif

#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)||defined(DRV_GPIO_FULL_FUNC)
   data=DRV_GPIO_Reg(GPO_DOUT); 
#endif   

   data=data&(1 << remainder);
   data=(data >> remainder);
   return (char)data;
#else /* !defined(DRV_GPIO_WO_GPO) */   
   return 0;
#endif /* !defined(DRV_GPIO_WO_GPO) */   
#else /*!defined(DRV_GPIO_OFF)*/
   return 0;
#endif /*!defined(DRV_GPIO_OFF)*/
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
#if !defined(DRV_GPIO_OFF)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data=0;   
   #ifdef __CUST_NEW__
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
   if(0==no)
      data=DRV_GPIO_Reg(GPIO_DIR); 
   else if(1==no)
      data=DRV_GPIO_Reg(GPIO_DIR2); 
#endif
#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
   data=DRV_GPIO_Reg(GPIO_DIR); 	
#endif
#if defined(DRV_GPIO_FULL_FUNC)
   data=DRV_GPIO_Reg(GPIO_DIR(no)); 
#endif   
   
   data=data&(1 << remainder);
   data=(data >> remainder);
   return (char)data;

#else  /*!defined(DRV_GPIO_OFF)*/
   return 0;
#endif /*!defined(DRV_GPIO_OFF)*/
}
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
#if !defined(DRV_GPIO_OFF)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #ifdef __CUST_NEW__
/* under construction !*/
   #endif /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else  /*!defined(DRV_GPIO_OFF)*/   
/* under construction !*/
#endif /*!defined(DRV_GPIO_OFF)*/
/* under construction !*/
#endif
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
#if !defined(DRV_GPIO_OFF)
#if !defined(DRV_GPIO_WO_GPO)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint32 data;   
   #ifdef __CUST_NEW__
      port &= (~GPO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/8;
   remainder = port % 8;

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
    data=DRV_GPIO_Reg(GPIO_MODE2); 
#endif      
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
    data=DRV_GPIO_Reg(GPIO_MODE4); 
#endif   
#if defined(DRV_GPIO_FULL_FUNC)
   data=DRV_GPIO_Reg(GPO_MODE); 
#endif   
   data=data&(0x3 << (2*remainder));
   data=(data >> (2*remainder));
   return (char)data;
#else /* !defined(DRV_GPIO_WO_GPO) */   
   return 0;
#endif /* !defined(DRV_GPIO_WO_GPO) */   
#else /*!defined(DRV_GPIO_OFF)*/
   return 0;
#endif /*!defined(DRV_GPIO_OFF)*/
}   

/*
* FUNCTION                                                            
*	GPIO_SetDebugMode
*
* DESCRIPTION                                                           
*  This function is to set GPIO HW debug mode
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
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_DEBUG_MODE)
   if (enable == KAL_TRUE)
   {
      DRV_GPIO_WriteReg(GPIO_BANK,0);
   }
   else
   {
      DRV_GPIO_WriteReg(GPIO_BANK,1);
   }
#endif /* DRV_GPIO_DEBUG_MODE */
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_SetClkOut
*
* DESCRIPTION                                                           
*  This function is to set GPIO Clock output mode
*
* CALLS  
*	set GPIO Clock output mode
*
* PARAMETERS
*	clk_num   - 0~5; When clk_num is 0, it represents CLK ouput 1
*  mode      - enum value for clock output source mode
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_SetClkOut(char clk_num, gpio_clk_mode mode)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_CLK_OUT)
   #if defined(DRV_GPIO_CLK_FROM_1)
   if ((clk_num > CLKO_NUM) || (clk_num < 1) || (mode >= mode_max_num))
      return;
   clk_num--;
   #else //DRV_GPIO_CLK_FROM_1
   if ((clk_num >= CLKO_NUM) || (mode >= mode_max_num))
 //  if ((clk_num >= CLKO_NUM) || (clk_num < 0) || (mode >= mode_max_num))
      return;
   #endif //DRV_GPIO_CLK_FROM_1
   DRV_GPIO_WriteReg(CLKO_MODE(clk_num), mode);
#elif defined(DRV_GPIO_CLK_OUT2)
   kal_uint32 savedMask;

   #if defined(DRV_GPIO_CLK_FROM_1)
   if ((clk_num > CLKO_NUM) || (clk_num < 1) || (mode >= mode_max_num))
      return;
   clk_num--;
   #else //DRV_GPIO_CLK_FROM_1
   if ((clk_num >= CLKO_NUM)  || (mode >= mode_max_num))
      return;
   #endif //DRV_GPIO_CLK_FROM_1
   savedMask = SAVEANDSETIRQMASK();
   #if defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6256)
   DRV_GPIO_SetData(CLKO_MODE(clk_num), 0x000f, mode);
   #elif defined(DRV_GPIO_REG_AS_6276)  || defined(DRV_GPIO_REG_AS_6280) 
   DRV_GPIO_SetData(CLKO_MODE(clk_num), (0x000f<<4), (mode<<4));
   #endif //defined(DRV_GPIO_REG_AS_6255)
   RESTOREIRQMASK(savedMask);
#endif /* DRV_GPIO_CLK_OUT */
#endif /*!defined(DRV_GPIO_OFF)*/
}

void GPIO_SetClkDiv(char clk_num, gpio_clk_div div)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_CLK_OUT2)
   kal_uint32 savedMask;

   #if defined(DRV_GPIO_CLK_FROM_1)
   if ((clk_num > CLKO_NUM) || (clk_num < 1) || (div >= div_max_num))
      return;
   clk_num--;
   #else //DRV_GPIO_CLK_FROM_1
   if ((clk_num >= CLKO_NUM) || (div >= div_max_num))
      return;
   #endif //DRV_GPIO_CLK_FROM_1
   savedMask = SAVEANDSETIRQMASK();
   #if defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6256)
   DRV_GPIO_SetData(CLKO_MODE(clk_num), (7<<4), (div<<4));
   #elif defined(DRV_GPIO_REG_AS_6276)  || defined(DRV_GPIO_REG_AS_6280) 
   DRV_GPIO_SetData(CLKO_MODE(clk_num), 0x000f, div);
   #endif //defined(DRV_GPIO_REG_AS_6255)
   RESTOREIRQMASK(savedMask);
#endif /* DRV_GPIO_CLK_OUT */
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_TMDir
*
* DESCRIPTION                                                           
*  This function is to set GPIO Test Mode direction
*
* CALLS  
*	set GPIO Test Mode direction
*
* PARAMETERS
*	pad_oe   - KAL_TRUE: Real pad OE
*             KAL_FALSE: MCU-configured
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void GPIO_TMDir(kal_bool pad_oe)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_TM_DIR)
   if (pad_oe == KAL_TRUE)
      DRV_GPIO_WriteReg(GPIO_TM,1);
   else
      DRV_GPIO_WriteReg(GPIO_TM,0);
#endif /* DRV_GPIO_CLK_OUT */
#endif /*!defined(DRV_GPIO_OFF)*/
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
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_6205B_FUNC)
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
   if (direction == OUTPUT)
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DIR_SET,(1 << port));
      else
         DRV_GPIO_WriteReg(GPIO_DIR2_SET,(1 << (port-16)));
	}
	else
	{
	   if (port < 16)
		   DRV_GPIO_WriteReg(GPIO_DIR_CLR,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DIR2_CLR,(1 << (port-16)));
	}
#endif   /*(DRV_GPIO_6205B_FUNC)*/

#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
      
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
   no = port/16;
   remainder = port % 16;
   if (direction == OUTPUT)
      DRV_GPIO_WriteReg(GPIO_DIR_SET(no),(1 << remainder));
	else
      DRV_GPIO_WriteReg(GPIO_DIR_CLR(no),(1 << remainder));
#endif   /*MT6218, MT6218B, MT6219, MT6217, MT6228, MT6229*/

#endif /*!defined(DRV_GPIO_OFF)*/
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
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_6205_FUNC) || defined(DRV_GPIO_6205B_FUNC)
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
   if (port < 16)
	   return((DRV_GPIO_Reg(GPIO_DIN) >> port) & 1);
	else
	   return((DRV_GPIO_Reg(GPIO_DIN2) >> (port-16)) & 1);
#endif /*(DRV_GPIO_6205_FUNC,DRV_GPIO_6205B_FUNC)*/
#if defined(DRV_GPIO_FULL_FUNC)
#if defined(DRV_GPIO_DIN_DISCONT)
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
   if (port < 16)
	   return((DRV_GPIO_Reg(GPIO_DIN1) >> port) & 1);
	else if (port < 32)
	   return((DRV_GPIO_Reg(GPIO_DIN2) >> (port-16)) & 1);
	else if (port < 48)
	   return((DRV_GPIO_Reg(GPIO_DIN3) >> (port-32)) & 1);
	#if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6225)
	else if (port < 64)
	   return((DRV_GPIO_Reg(GPIO_DIN4) >> (port-48)) & 1);
	#endif
   else
   {
      ASSERT(0);
      return 0;
   }
#endif
#if defined(DRV_GPIO_DIN_CONTI)
   kal_uint16 no;
   kal_uint16 remainder;
   kal_uint16 data;   
   #ifdef __GPIO_FAST_DEBUB__
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_read[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
   #if defined(DRV_GPIO_REG_AS_6228)
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO_FAST: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
   #endif /* (defined(MT6228))*/
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO_FAST: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         char dir;
         dir = GPIO_ReturnDir(port);
         if (dir != 0)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_ReadIO_FAST: direction is not correct.");
          ret = sprintf(buff, "pin=%d, direction=%d", port, dir);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
      ASSERT(GPIO_ReturnDir(port) == 0);
		#endif  /* __GPIO_CHECK_WARNING__ */
	  gpio_check_for_read[(kal_uint8)port>>5] &= (~(1 << (port & 0x1f)));
   }
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __GPIO_FAST_DEBUB__ */
   #ifdef __CUST_NEW__   	
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
         		
   data=DRV_GPIO_Reg(GPIO_DIN(no));   
   data=data&(1 << remainder);
   data=(data >> remainder);
   return (char)data;
   
#endif   /*DRV_GPIO_DIN_CONTI*/
#else /* DRV_GPIO_FULL_FUNC */
   return 0;
#endif /* DRV_GPIO_FULL_FUNC */
#endif /*!defined(DRV_GPIO_OFF)*/
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
#if !defined(DRV_GPIO_OFF)
#ifdef DRV_GPIO_6205B_FUNC
   #ifdef __GPIO_FAST_DEBUB__
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
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: mode or direction is not correct.");
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
   #endif /* __GPIO_FAST_DEBUB__ */
	if (data == 1)
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DOUT_SET,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DOUT2_SET,(1 << (port-16)));
	}
	else
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DOUT_CLR,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DOUT2_CLR,(1 << (port-16)));
	}
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
      
   #ifdef __GPIO_FAST_DEBUB__
   if ((gpio_debug_enable == KAL_TRUE) && 
	   (gpio_check_for_write[(kal_uint8)port>>5] & (1 << (port & 0x1f))))
   {
   #if defined(DRV_GPIO_REG_AS_6228)
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
   #endif /*DRV_GPIO_REG_AS_6228*/
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
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
   if (data == 1)
      DRV_GPIO_WriteReg(GPIO_DOUT_SET(no),(1 << remainder));
	else
      DRV_GPIO_WriteReg(GPIO_DOUT_CLR(no),(1 << remainder));
#endif   /*MT6218, MT6218B, MT6219, MT6217, MT6228, MT6229*/
#endif /*!defined(DRV_GPIO_OFF)*/
}

#endif /* __CUST_NEW__ */

/*
* FUNCTION                                                            
*	GPIO_WriteIO_Force
*
* DESCRIPTION                                                           
*   	This function is to write data to one GPIO port.
*  Note that when __CUST_NEW__ is defined and debug mode is enable,
*  this write action is still valid even if this port is not GPIO mode or not
*  set as output mode.
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
void GPIO_WriteIO_Force(char data, char port)
{
#if !defined(DRV_GPIO_OFF)
#if defined(DRV_GPIO_6205_FUNC)
	if (data == 1)
	{
	   if (port < 16)
      {
         DRV_GPIO_SetBits(GPIO_DOUT, (1 << port));
      }
		else
      {
         DRV_GPIO_SetBits(GPIO_DOUT2, (1 << (port-16)));
      }
	}
	else
	{
	   if (port < 16)
      {
         DRV_GPIO_ClearBits(GPIO_DOUT, (1 << port));
      }
		else
      {
         DRV_GPIO_ClearBits(GPIO_DOUT2, (1 << (port-16)));
      }
	}
#endif /*(DRV_GPIO_6205_FUNC)*/

#if defined(DRV_GPIO_6205B_FUNC)
   #ifdef __CUST_NEW__
   if (gpio_debug_enable == KAL_TRUE)
   {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if (!(port & GPIO_MAGIC_NUM))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_Force: Port has no magic number");
          ret = sprintf(buff, "pin=%d", port);
          system_print(buff);
         }
      }
      #else /* __GPIO_CHECK_WARNING__ */
      ASSERT((port & GPIO_MAGIC_NUM));
	  #endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
	if (data == 1)
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DOUT_SET,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DOUT2_SET,(1 << (port-16)));
	}
	else
	{
	   if (port < 16)
	      DRV_GPIO_WriteReg(GPIO_DOUT_CLR,(1 << port));
		else
		   DRV_GPIO_WriteReg(GPIO_DOUT2_CLR,(1 << (port-16)));
	}
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_6208_FUNC) || defined(FPGA)
	if (data == 1)
	{
      DRV_GPIO_SetBits(GPIO_DOUT, (1 << port));
	}
	else
	{
      DRV_GPIO_ClearBits(GPIO_DOUT, (1 << port));
	}
#endif   /*(DRV_GPIO_6208_FUNC,FPGA)*/

#if defined(DRV_GPIO_FULL_FUNC)
   kal_uint16 no;
   kal_uint16 remainder;
      
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
      #else /* __GPIO_CHECK_WARNING__ */
      ASSERT((port & GPIO_MAGIC_NUM));
		#endif  /* __GPIO_CHECK_WARNING__ */
   }
   port &= (~GPIO_MAGIC_NUM);
   #endif /* __CUST_NEW__ */
   no = port/16;
   remainder = port % 16;
   if (data == 1)
      DRV_GPIO_WriteReg(GPIO_DOUT_SET(no),(1 << remainder));
	else
      DRV_GPIO_WriteReg(GPIO_DOUT_CLR(no),(1 << remainder));
#endif   /*DRV_GPIO_FULL_FUNC*/
#endif /*!defined(DRV_GPIO_OFF)*/
}

/*
* FUNCTION                                                            
*	GPIO_Check_MultiPins
*
* DESCRIPTION                                                           
*   	This function is to check the validity of GPIO mode and direction
*  for multiple GPIO ports.
*
* CALLS  
*	check the validity of GPIO mode and direction for multiple GPIO ports.
*
* PARAMETERS
*	check_ptr: pointer to an array of GPIOCheckStruct with element number 
*             by pin_cnt.
*	pin_cnt: gpio pin count that will be checked for validity
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global        
*/
void GPIO_Check_MultiPins(GPIOCheckStruct *check_ptr, kal_uint32 pin_cnt)
{
#if !defined(DRV_GPIO_OFF)
#ifdef __CUST_NEW__
   kal_uint32 index;
   kal_uint16 mode;
   char dir;

   for (index = 0; index < pin_cnt; index++, check_ptr++)
   {
	   kal_uint8	pin;

	   #if defined(DRV_GPIO_6205B_FUNC)
	      pin = check_ptr->pin_num & (~GPIO_MAGIC_NUM);
	      mode = GPIO_ReturnMode(pin);
         dir = GPIO_ReturnDir(pin);
         #ifdef __GPIO_CHECK_WARNING__
         if (!kal_if_lisr()) {
          if ((mode != 0) || 
             ((check_ptr->dir!=GPIO_DIR_BOTH)&&(dir != check_ptr->dir)))
          {
            kal_int32 ret;
           system_print("GPIO WARNING!! GPIO_Check_MultiPins: NOT GPIO mode or Dir. Wrong.");
           ret = sprintf(buff, "pin=%d, mode=%d", pin, mode, dir);
           system_print(buff);
          }
         }
         #else /* __GPIO_CHECK_WARNING__ */
         ASSERT(mode==0);
         ASSERT((check_ptr->dir==GPIO_DIR_BOTH) || (dir == check_ptr->dir));
         #endif  /* __GPIO_CHECK_WARNING__ */
	   #endif   /*DRV_GPIO_6205B_FUNC*/
	   #if defined(DRV_GPIO_FULL_FUNC)
      #ifdef __GPIO_CHECK_WARNING__
      kal_bool gpio_mode = KAL_TRUE;
      #endif  /* __GPIO_CHECK_WARNING__ */
	   pin = check_ptr->pin_num & (~GPIO_MAGIC_NUM);
	   mode = GPIO_ReturnMode((char)pin);
      dir = GPIO_ReturnDir((char)pin);
	   #if defined(DRV_GPIO_REG_AS_6228)
      if(((pin > 25)&&(pin < 32)) || 
       ((pin > 43)&&(pin < 48)) || 
       ((pin > 53)&&(pin < 63)) || 
       ((pin > 67)&&(pin < 75)))
      {
        #ifdef __GPIO_CHECK_WARNING__
        if (mode != 1)
	        gpio_mode = KAL_FALSE;
        #else /* __GPIO_CHECK_WARNING__ */
        ASSERT(mode==1);
        ASSERT((check_ptr->dir==GPIO_DIR_BOTH) || (dir == check_ptr->dir));
        #endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
	   #endif /*DRV_GPIO_REG_AS_6228*/
      {
         #ifdef __GPIO_CHECK_WARNING__
         if (mode != 0)
           gpio_mode = KAL_FALSE;
         #else /* __GPIO_CHECK_WARNING__ */
         ASSERT(mode==0);
         ASSERT((check_ptr->dir==GPIO_DIR_BOTH) || (dir == check_ptr->dir));
         #endif  /* __GPIO_CHECK_WARNING__ */
      }
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         if ((gpio_mode == KAL_FALSE) ||
             ((check_ptr->dir!=GPIO_DIR_BOTH)&&(dir != check_ptr->dir)))
         {
            kal_int32 ret;
            system_print("GPIO WARNING!! GPIO_Check_MultiPins: NOT GPIO mode or Dir. Wrong.");
            ret = sprintf(buff, "pin=%d, mode=%d, dir=%d", pin, mode, dir);
            system_print(buff);
         }
      }
      #endif  /* __GPIO_CHECK_WARNING__ */
	   #endif   /*DRV_GPIO_FULL_FUNC*/
   }
#endif /* __CUST_NEW__ */
#endif /*!defined(DRV_GPIO_OFF)*/
}
#if 0
/* under construction !*/
#endif
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
__attribute__ ((section ("INTSRAM_ROCODE"))) void GPIO_WriteIO_FAST2(char data, kal_uint16 no, kal_uint16 remainder_shift)
{
#if !defined(DRV_GPIO_OFF)
#ifdef DRV_GPIO_6205B_FUNC
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
         char dir;
         mode = GPIO_ReturnMode(port);
         dir = GPIO_ReturnDir(port);
         if ((mode != 0) || (dir != 1))
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: mode or direction is not correct.");
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
   #endif /* __GPIO_FAST_DEBUB__ */
   DRV_GPIO_WriteReg(GPIO_DOUT_CLR+(no<<2)-(data<<6),remainder_shift);
#endif   /*DRV_GPIO_6205B_FUNC*/

#if defined(DRV_GPIO_FULL_FUNC)
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
   #if defined(DRV_GPIO_REG_AS_6228)
      if(((port > 25)&&(port < 32)) || 
         ((port > 43)&&(port < 48)) || 
         ((port > 53)&&(port < 63)) || 
         ((port > 67)&&(port < 75)))
      {
      #ifdef __GPIO_CHECK_WARNING__
      if (!kal_if_lisr()) {
         kal_uint16 mode;
         mode = GPIO_ReturnMode(port);
         if (mode != 1)
         {
            kal_int32 ret;
          system_print("GPIO WARNING!! GPIO_WriteIO_FAST: mode is not correct.");
          ret = sprintf(buff, "pin=%d, mode=%d", port, mode);
          system_print(buff);
         }
      }
      #elif defined(__GPIO_CHECK_ASSERT__)
         ASSERT(GPIO_ReturnMode(port) == 1);
		#endif  /* __GPIO_CHECK_WARNING__ */
      }
      else
   #endif /*DRV_GPIO_REG_AS_6228*/
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
	DRV_GPIO_WriteReg(GPIO_DOUT_CLR(no) - (data*4), remainder_shift);
#endif   /*MT6218, MT6218B, MT6219, MT6217, MT6228, MT6229*/
#endif /*!defined(DRV_GPIO_OFF)*/
}
 __attribute__ ((section ("INTSRAM_ROCODE")))  kal_uint16  get_6280_spec_index( kal_uint16	pin_num)
 	{   
#if !defined(DRV_GPIO_OFF)
#if defined (DRV_GPIO_6280_SPECIAL_SET_REG)
	static kal_uint16  u2cnt1;

	for (u2cnt1= 0;
	u2cnt1<sizeof(gpio_6280_special_index)/sizeof(*gpio_6280_special_index);
	u2cnt1++)
	{
		if(gpio_6280_special_index[u2cnt1]==pin_num)
		return  u2cnt1;
		
	}
	return  GPIO_6280_INVAILD_INDEX;
	#endif  //defined (DRV_GPIO_6280_SPECIAL_SET_REG)
	#endif  //defined(DRV_GPIO_OFF)
 	}


 __attribute__ ((section ("INTSRAM_ROCODE"))) kal_bool  Is_6280_SPEC_GPIO( kal_uint16 pin)
 	{
#if !defined(DRV_GPIO_OFF)
#if defined (DRV_GPIO_6280_SPECIAL_SET_REG)

if( (GPIO_6280_MIN_PIN_A<pin && pin< GPIO_6280_MAX_PIN_A)  || ( GPIO_6280_MIN_PIN_B<pin && pin< GPIO_6280_MAX_PIN_B))
      return  KAL_TRUE;
else
	  return  KAL_FALSE;

#endif  //defined (DRV_GPIO_6280_SPECIAL_SET_REG)
	  
#endif /*!defined(DRV_GPIO_OFF)*/  	
	  	
	  	  }


 //#if defined(MT6575)

#if defined(DRV_GPIO_SP_ON)
   #ifdef __AST_TL1_TDD__
  #if defined(DRV_GPIO_SP_REG)
  #if  defined(DRV_GPIO_SPEC_NAME)
  #define GPIO_base AP_GPIO_base
  #endif
#define  GPIO_DIR     (GPIO_base+0X0000)
#define  GPIO_MOD    (GPIO_base+0X0C00)
#define  GPIO_DOUT    (GPIO_base+0X0800)
#define  GPIO_INV     (GPIO_base+0X0600)
#define  GPIO_PULLEN  (GPIO_base+0X0200)
#define  GPIO_PULSEL  (GPIO_base+0X0400)
#else
#error //chip not support
  #endif


#ifdef __ANDROID_MODEM__
 __attribute__ ((section ("INTSRAM_ROCODE")))  kal_int32 IPC_RPC_GPIO_GetPin(kal_uint8 *GPIOName, kal_uint32 GPIONameLength, kal_uint32 *GPIOPin);
#endif
 /*
 * FUNCTION 														   
 *	 GPIO_MD_InitIO
 *
 * DESCRIPTION															 
 *		 This function is to initialize one GPIO pin as INPUT or OUTPUT
 *
 * CALLS  
 *	 Initialize one GPIO pin as INPUT or OUTPUT
 *
 * PARAMETERS
 *	 direction: INPUT or OUTPUT
 *	 port: pin number
 *	 
 * RETURNS
 *	 None
 *
 * GLOBALS AFFECTED
 *	 external_global
 */
__attribute__ ((section ("INTSRAM_ROCODE")))  void GPIO_MD_InitIO(char direction, char port)
 	{   
	 int base = GPIO_DIR+(port/16)*0x10;
	 if (direction == 1)
		 *(volatile unsigned short*)(base+4) = (1 << (port%16));
	 else
		 *(volatile unsigned short*)(base+8) = (1 << (port%16));  

}
 
 /*
 * FUNCTION 														   
 *	 GPIO_MD_WriteIO
 *
 * DESCRIPTION															 
 *		 This function is to write data to one GPIO port
 *
 * CALLS  
 *	 Write data to one GPIO port
 *
 * PARAMETERS
 *	 data: KAL_TRUE(1) or KAL_FALSE(0)
 *	 port: gpio pin number
 *	 
 * RETURNS
 *	 None
 *
 * GLOBALS AFFECTED
 *	 external_global		
 */
__attribute__ ((section ("INTSRAM_ROCODE"))) void GPIO_MD_WriteIO(char data, char port)
	{
	
	 int base = GPIO_DOUT + (port/16)*0x10;
	 if (data == 1)
		 *(volatile unsigned short*)(base+4) = (1 << (port%16));
	 else
		 *(volatile unsigned short*)(base+8) = (1 << (port%16));  
		
	}

__attribute__ ((section ("INTSRAM_ROCODE")))   void GPIO_MD_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
   {

	 int base = GPIO_MOD + (pin/5)*0x10;
    int mask = (0x7 << ((pin%5)*3));
    *(volatile unsigned short*)(base+8) = mask;
    *(volatile unsigned short*)(base+4) = (conf_dada <<((pin%5)*3));
     
 	}


   
   /*
   * FUNCTION															 
   *   GPIO_MD_PullenSetup
   *
   * DESCRIPTION														   
   *	   This function is to enable or disable the pull up/down of the related GPIO pin.
   *	   You can not decide to pull up or down, it is set inside the chip.
   *	   And, the setting is different from pin by pin.
   *
   * PARAMETERS
   *   pin : gpio pin number range from 0~54 (MT6219)
   *   enable: enable the pull up/down
   *   
   * RETURNS
   *   None
   *
   * GLOBALS AFFECTED
   *
   */
__attribute__ ((section ("INTSRAM_ROCODE"))) void GPIO_MD_PullenSetup(kal_uint16 pin, kal_bool enable)
 	{
      	 int base = GPIO_PULLEN + (pin/16)*0x10;
	 if (enable == 1)
		 *(volatile unsigned short*)(base+4) = (1 << (pin%16));
	 else
		 *(volatile unsigned short*)(base+8) = (1 << (pin%16)); 


   }



   
   
   /*
   * FUNCTION															 
   *   GPIO_MD_PullSelSetup
   *
   * DESCRIPTION														   
   *	   This function is to select pull up/down of the related GPIO pin.
   *
   * PARAMETERS
   *   pin : gpio pin number range from 0~54 (MT6219)
   *   enable: enable the pull up/down
   *   
   * RETURNS
   *   None
   *
   * GLOBALS AFFECTED
   *
   */
__attribute__ ((section ("INTSRAM_ROCODE")))   void GPIO_MD_PullSelSetup(kal_uint16 pin, kal_bool pull_up)
   	{
		   int base = GPIO_PULSEL  + (pin/16)*0x10;
	   if (pull_up == 1)
		   *(volatile unsigned short*)(base+4) = (1 << (pin%16));
	   else
		   *(volatile unsigned short*)(base+8) = (1 << (pin%16)); 


   }

   /*
   * FUNCTION															 
   *   GPIO_DinvSetup
   *
   * DESCRIPTION														   
   *	   This function is to enable data invert of the related GPIO pin
   *
   * PARAMETERS
   *   pin : gpio pin number range from 0~54 (MT6219)
   *   enable: enable the data inversion
   *   
   * RETURNS
   *   None
   *
   * GLOBALS AFFECTED
   *
   */
__attribute__ ((section ("INTSRAM_ROCODE"))) void GPIO_MD_DinvSetup(kal_uint16 pin, kal_bool enable)
	  {
		   int base = GPIO_INV  + (pin/16)*0x10;
	   if (enable == 1)
		   *(volatile unsigned short*)(base+4) = (1 << (pin%16));
      else
		   *(volatile unsigned short*)(base+8) = (1 << (pin%16)); 
	  	
	  }
	  
   DCL_UINT32 MD_get_gpio_pin_number(DCL_UINT32 flags)
			{
#ifdef __ANDROID_MODEM__
			   kal_uint32 pin;
			   kal_uint32 index=0;
			   kal_uint32 gpio_pin_num;
			   kal_uint32 pin_sum_number;
		 kal_int32	rpc_result;
			   pin=flags;
			   pin_sum_number=GPIO_MD_NUMBER&(~DCL_GPIO_MD_MAGIC_NUMBER);			   
			   if(pin>=GPIO_MD_NUMBER)
				ASSERT(0);
				 index = pin;
			   if(index>=pin_sum_number)
				ASSERT(0);
			  //  call IPC_RPC	service 
			   rpc_result=IPC_RPC_GPIO_GetPin((kal_uint8*)GPIO_PIN_DEFINE_STRING[index],GPIO_PIN_DEFINE_LENGTH[index]+1 ,&gpio_pin_num);
	  	
			   ASSERT(rpc_result>=0);
			  return  gpio_pin_num;
#endif //#ifdef __ANDROID_MODEM__
	  	  }

#endif  // #ifdef __AST_TL1_TDD__
#endif //#if defined(DRV_GPIO_SP_ON)
#if 0	 
/* under construction !*/
#endif
