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
 *    keypad_def.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defined for keypad table
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING)
#include "drv_features.h"
#include "drv_comm.h"
#include "eint.h"
#include "touch_panel_custom.h"
#include "touch_panel.h"
#include "touch_panel_spi.h"


TouchPanel_custom_data_struct  tp_custom_data_def = 
{
#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
    TS_DEBOUNCE_TIME,
    TOUCH_PANEL_CALI_CHECK_OFFSET,
    MIN_PEN_MOVE_OFFSET,
    HAND_WRITING_MAX_OFFSET,
    NONHAND_WRITING_MAX_OFFSET, 
    MAX_STROKE_MOVE_OFFSET, 
    TOUCH_PRESSURE_THRESHOLD_HIGH, 
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK) 
   MULTIPLE_POINT_SELECTION, 
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK) 
#if defined(__DRV_TP_DISCARD_SHIFTING__) 
    PRESSURE_CHECK_BOUNDARY, 
    PRESSURE_SHIFTING_BOUNDARY, 
#endif //#if defined(__DRV_TP_DISCARD_SHIFTING__) 
#endif //#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
	TOUCH_PANEL_FILTER_THRESOLD,
   /*ADC*/
   TOUCH_PANEL_ADC_X_START,   
	TOUCH_PANEL_ADC_X_END,     
	TOUCH_PANEL_ADC_Y_START,
	TOUCH_PANEL_ADC_Y_END,     
	/*Coord.*/
	TOUCH_PANEL_COORD_X_START,
	TOUCH_PANEL_COORD_X_END,   
	TOUCH_PANEL_COORD_Y_START, 
	TOUCH_PANEL_COORD_Y_END,
	/*Size.*/
	TOUCH_PANEL_X_MILLIMETER,
	TOUCH_PANEL_Y_MILLIMETER,
	/*eint level*/
	TOUCH_PANEL_EINT_DOWN_LEVEL   
};

#if defined(DRV_TP_NO_EXT_EINT)

extern void tp_read_adc(kal_int16 *x, kal_int16 *y);
extern void tp_irq_enable(kal_bool on);
#ifdef TOUCH_PANEL_PRESSURE
   extern kal_bool tp_pressure_check(void);
#endif /*TOUCH_PANEL_PRESSURE*/

const kal_int16 touch_panel_filter_thresold = TOUCH_PANEL_FILTER_THRESOLD;
#ifdef TOUCH_PANEL_PRESSURE
   const kal_uint16 touch_pressure_threshold_high = TOUCH_PRESSURE_THRESHOLD_HIGH;
   const kal_uint16 touch_pressure_threshold_low = TOUCH_PRESSURE_THRESHOLD_LOW;
#endif /*TOUCH_PANEL_PRESSURE*/

#else // #if defined(DRV_TP_NO_EXT_EINT)

void tp_read_adc(kal_int16 *x, kal_int16 *y)
{
#if !defined(__TOUCH_PANEL_CAPACITY__)
   kal_uint8 command=0, retry;        
   kal_int16 temp_x=0, temp_y=0, diff_x=0, diff_y=0;
   
   for(retry=0;retry<TOUCH_PANEL_RETRY;retry++)
   {
   /*Y ADC*/
   command=TOUCH_PANEL_START_BIT|TOUCH_PANEL_X_PLUS|TOUCH_PANEL_12BIT_SAMPLE|
           TOUCH_PANEL_DIFF_MODE;
   serial_write_data(command);
   *y=serial_read_data();   
   
   /*X ADC*/
   command=TOUCH_PANEL_START_BIT|TOUCH_PANEL_Y_PLUS|TOUCH_PANEL_12BIT_SAMPLE|
           TOUCH_PANEL_DIFF_MODE;
   serial_write_data(command);
   *x=serial_read_data();      
      
      if(temp_x==0&&temp_y==0)
      {
         temp_x=*x;
         temp_y=*y;
      }
      else
      {
         diff_x=temp_x-*x;
         diff_y=temp_y-*y;
         if(diff_x>TOUCH_PANEL_FILTER_THRESOLD||diff_x<-TOUCH_PANEL_FILTER_THRESOLD
            ||diff_y>TOUCH_PANEL_FILTER_THRESOLD||diff_y<-TOUCH_PANEL_FILTER_THRESOLD)
         {
            temp_x=*x;
            temp_y=*y;
            *x=4095;                  
            *y=4095;            
         }
         else
         {
         	if(*x!=4095&&*y!=4095)
            	return;
         }                        
      }                  
   }   
#endif //#if !defined(__TOUCH_PANEL_CAPACITY__)
}

#ifdef TOUCH_PANEL_PRESSURE
kal_bool tp_pressure_check(void)
{
#if !defined(__TOUCH_PANEL_CAPACITY__)
   kal_uint8 command=0, retry;        
   kal_int16 x, z1, z2;
   kal_uint32 pressure;
   
   for(retry=0;retry<TOUCH_PANEL_RETRY;retry++)
   {
      /*X ADC*/
      command=TOUCH_PANEL_START_BIT|TOUCH_PANEL_Y_PLUS|TOUCH_PANEL_12BIT_SAMPLE|
           TOUCH_PANEL_SINGLE_MODE;
      serial_write_data(command);
      x=serial_read_data();   
      //kal_prompt_trace(MOD_TP_TASK, "pressure x value: %d", x);

      /*Z1 ADC*/
      command=TOUCH_PANEL_START_BIT|TOUCH_PANEL_Z1_POS|TOUCH_PANEL_12BIT_SAMPLE|
           TOUCH_PANEL_DIFF_MODE;
      serial_write_data(command);
      z1=serial_read_data();   
      //kal_prompt_trace(MOD_TP_TASK, "pressure z1 value: %d", z1);

      /*Z2 ADC*/
      command=TOUCH_PANEL_START_BIT|TOUCH_PANEL_Z2_POS|TOUCH_PANEL_12BIT_SAMPLE|
           TOUCH_PANEL_DIFF_MODE;
      serial_write_data(command);
      z2=serial_read_data();
      //kal_prompt_trace(MOD_TP_TASK, "pressure z2 value: %d", z2);
      if((z1 > 0) && (z2 > z1))
      {
         pressure = (x*(z2-z1)/z1) >> 2; /* Rx*x/4096*(z2/z1 - 1), assume Rx=1024 */
         //kal_prompt_trace(MOD_TP_TASK, "pressure: %d", pressure);
         //if (pressure > TOUCH_PRESSURE_THRESHOLD2)
           // kal_prompt_trace(MOD_TP_TASK, "pressure is above %d. value: %d", TOUCH_PRESSURE_THRESHOLD2, pressure);
         if ((pressure > TOUCH_PRESSURE_THRESHOLD_HIGH) || (pressure <= TOUCH_PRESSURE_THRESHOLD_LOW))
            return KAL_FALSE; 
         else
            return KAL_TRUE; 
      }
   }
   //kal_prompt_trace(MOD_TP_TASK, "pressure: 0 (no value)");
#endif //#if !defined(__TOUCH_PANEL_CAPACITY__)
   return KAL_FALSE;
}
#endif /*TOUCH_PANEL_PRESSURE*/

void tp_irq_enable(kal_bool on)
{
#if !defined(__TOUCH_PANEL_CAPACITY__)
   kal_uint8 command=0;   
   kal_uint32 savedMask;

#ifdef TOUCH_PANEL_PRESSURE
   volatile kal_uint32  i;
   //savedMask = SaveAndSetIRQMask();
   GPIO_WriteIO(0,SPI_CS_PIN);
   for (i=0;i<50;i++)
   {;}
#endif
   
   if(on==KAL_TRUE)
   {
      command=TOUCH_PANEL_START_BIT|TOUCH_PANEL_PWD_ENBLE;               
   }   
   else
   {
      command=TOUCH_PANEL_START_BIT|TOUCH_PANEL_IRQ_DISABLE;
   }  
   serial_write_data(command);
   serial_read_data(); 

#ifdef TOUCH_PANEL_PRESSURE
    if(on==KAL_TRUE)            
        GPIO_WriteIO(0,SPI_CS_PIN);
    else
        GPIO_WriteIO(1,SPI_CS_PIN);
#endif
   
   //RestoreIRQMask(savedMask);
#endif //#if !defined(__TOUCH_PANEL_CAPACITY__)
}        

#endif // #if defined(DRV_TP_NO_EXT_EINT)

TouchPanel_custom_data_struct *tp_Get_Data(void) 
{
   return (&tp_custom_data_def);
}      
TouchPanel_customize_function_struct tp_custom_func=
{
     tp_Get_Data,
     tp_read_adc,
#ifdef TOUCH_PANEL_PRESSURE
     tp_pressure_check,
#endif
     tp_irq_enable
};            
TouchPanel_customize_function_struct *tp_GetFunc(void)
{
   return (&tp_custom_func);  
}   







/*************************************************************************
 * [Set the config for MMI handwriting pad is enabled]
 *************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_HANDWRITING_PAD__
#include "mmi_frm_gprot.h" /* get tp_area_struct declaraction */
#include "kbd_table.h"



/*************************************************************************
 * [Get the calibration point]
 *************************************************************************/
#define NUM_TP_CALIBRATION_POINTS 3
const mmi_pen_point_struct tp_calibration_point[NUM_TP_CALIBRATION_POINTS]={
      {TOUCH_PANEL_CALIBRATION_X_1, TOUCH_PANEL_CALIBRATION_Y_1}, /* top-left point */
      {TOUCH_PANEL_CALIBRATION_X_2, TOUCH_PANEL_CALIBRATION_Y_2}, /* bottom-right point */
      {TOUCH_PANEL_CALIBRATION_X_3, TOUCH_PANEL_CALIBRATION_Y_3}  /* the thrid point */
   };


/*************************************************************************
 * [handwriting pad information setting]
 * Define the coordinate for control areas
 * Below is the reference setting ...
 *************************************************************************/
#if defined(__MMI_MAINLCD_176X220__)
#define TP_SCREEN_ROW_H		(9)
#define TP_SCREEN_ROW_0		(TOUCH_PANEL_COORD_Y_START)
#define TP_SCREEN_ROW_1		(TOUCH_PANEL_COORD_Y_START+10)
#define TP_SCREEN_ROW_2		(TOUCH_PANEL_COORD_Y_START+20)
#define TP_SCREEN_ROW_3		(TOUCH_PANEL_COORD_Y_START+30)
#define TP_SCREEN_ROW_4		(TOUCH_PANEL_COORD_Y_START+40)
#define TP_SCREEN_ROW_5		(TOUCH_PANEL_COORD_Y_START+50)
#define TP_SCREEN_ROW_6		(TOUCH_PANEL_COORD_Y_START+60)
#define TP_SCREEN_ROW_7		(TOUCH_PANEL_COORD_Y_START+70)
#define TP_SCREEN_ROW_8		(TOUCH_PANEL_COORD_Y_START+80)
#define TP_SCREEN_ROW_9		(TOUCH_PANEL_COORD_Y_START+90)

#define TP_SCREEN_COL_W		(57)
#define TP_SCREEN_COL_0		(TOUCH_PANEL_COORD_X_START)
#define TP_SCREEN_COL_1		(TOUCH_PANEL_COORD_X_START+58)
#define TP_SCREEN_COL_2		(TOUCH_PANEL_COORD_X_START+116)
#define TP_SCREEN_COL_3		(TOUCH_PANEL_COORD_X_START+174)

#elif defined(__MMI_MAINLCD_240X320__)

#define TP_SCREEN_ROW_H		(19)
#define TP_SCREEN_ROW_0		(TOUCH_PANEL_COORD_Y_START)
#define TP_SCREEN_ROW_1		(TOUCH_PANEL_COORD_Y_START+20)
#define TP_SCREEN_ROW_2		(TOUCH_PANEL_COORD_Y_START+40)
#define TP_SCREEN_ROW_3		(TOUCH_PANEL_COORD_Y_START+60)
#define TP_SCREEN_ROW_4		(TOUCH_PANEL_COORD_Y_START+80)
#define TP_SCREEN_ROW_5		(TOUCH_PANEL_COORD_Y_START+100)
#define TP_SCREEN_ROW_6		(TOUCH_PANEL_COORD_Y_START+120)
#define TP_SCREEN_ROW_7		(TOUCH_PANEL_COORD_Y_START+140)
#define TP_SCREEN_ROW_8		(TOUCH_PANEL_COORD_Y_START+160)
#define TP_SCREEN_ROW_9		(TOUCH_PANEL_COORD_Y_START+180)

#define TP_SCREEN_COL_W		(79)
#define TP_SCREEN_COL_0		(TOUCH_PANEL_COORD_X_START)
#define TP_SCREEN_COL_1		(TOUCH_PANEL_COORD_X_START+80)
#define TP_SCREEN_COL_2		(TOUCH_PANEL_COORD_X_START+160)
#define TP_SCREEN_COL_3		(TOUCH_PANEL_COORD_X_START+240)

#endif


/* If the customer want to handle the pen events, register the function handler here. */

void custom_dummy_pen_hdlr(mmi_pen_point_struct pos)
{
}


mmi_pen_hdlr custom_extra_func_hdlr[MMI_PEN_EVENT_TYPE_MAX]={
                        	NULL, /* MMI_PEN_EVENT_DOWN, */
                        	NULL, /* MMI_PEN_EVENT_UP, */
                        	NULL, /* MMI_PEN_EVENT_LONG_TAP, */
                        	NULL, /* MMI_PEN_EVENT_REPEAT, */
                        	NULL, /* MMI_PEN_EVENT_MOVE, */
                        	NULL,  /* MMI_PEN_EVENT_ABORT, */ 
                        };

/* 
 * control area:
 * The points of the region need to be successive and end at {-1,-1}
 *
 * TP_SCREEN_COL_0
 * |     TP_SCREEN_COL_1
 * |     |     TP_SCREEN_COL_2
 * |     |     |     TP_SCREEN_COL_3
 * v     v     v     v
 * +-----+-----+-----+ <-- TP_SCREEN_ROW_0
 * | LSK |  ^  | RSK |
 * +-----+-----+-----+ <-- TP_SCREEN_ROW_1
 * | <-- |  v  | --> |
 * +-----+-----+-----+ <-- TP_SCREEN_ROW_2
 * |Send |  C  | End |
 * +-----+-----+-----+ <-- TP_SCREEN_ROW_3
 * |  1  |  2  |  3  |
 * +-----+-----+-----+ <-- TP_SCREEN_ROW_4
 * |  4  |  5  |  6  |
 * +-----+-----+-----+ <-- TP_SCREEN_ROW_5
 * |  7  |  8  |  9  |
 * +-----+-----+-----+ <-- TP_SCREEN_ROW_6
 * |  *  |  0  |  #  |
 * +-----+-----+-----+ <-- TP_SCREEN_ROW_7
 *
 * handwriting area:
 * The region must be the rectangle and the points should be successive and end at {-1,-1}
 */
const mmi_pen_point_struct tp_lsk_region[]= {
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_0}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_0}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_1-1}, 
                           {TP_SCREEN_COL_0,	   TP_SCREEN_ROW_1-1}, 
                           {-1,-1}
                        };

const mmi_pen_point_struct tp_up_arrow_region[]={
                           {TP_SCREEN_COL_1,    TP_SCREEN_ROW_0}, 
                           {TP_SCREEN_COL_2-1,  TP_SCREEN_ROW_0}, 
                           {TP_SCREEN_COL_2-1,  TP_SCREEN_ROW_1-1}, 
                           {TP_SCREEN_COL_1,    TP_SCREEN_ROW_1-1}, 
                           {-1,-1}
                        };
                        
const mmi_pen_point_struct tp_rsk_region[]={
                           {TP_SCREEN_COL_2,    TP_SCREEN_ROW_0}, 
                           {TP_SCREEN_COL_3-1,  TP_SCREEN_ROW_0}, 
                           {TP_SCREEN_COL_3-1,  TP_SCREEN_ROW_1-1}, 
                           {TP_SCREEN_COL_2,    TP_SCREEN_ROW_1-1}, 
                           {-1,-1}
                        };

const mmi_pen_point_struct tp_left_arrow_region[]= {
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_1}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_1}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_2-1}, 
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_2-1}, 
                           {-1,-1}
                        };

const mmi_pen_point_struct tp_down_arrow_region[]={
                           {TP_SCREEN_COL_1,    TP_SCREEN_ROW_1}, 
                           {TP_SCREEN_COL_2-1,  TP_SCREEN_ROW_1}, 
                           {TP_SCREEN_COL_2-1,  TP_SCREEN_ROW_2-1}, 
                           {TP_SCREEN_COL_1,    TP_SCREEN_ROW_2-1}, 
                           {-1,-1}
                        };
                        
const mmi_pen_point_struct tp_right_arrow_region[]={
                           {TP_SCREEN_COL_2,    TP_SCREEN_ROW_1}, 
                           {TP_SCREEN_COL_3-1,  TP_SCREEN_ROW_1}, 
                           {TP_SCREEN_COL_3-1,  TP_SCREEN_ROW_2-1}, 
                           {TP_SCREEN_COL_2,    TP_SCREEN_ROW_2-1}, 
                           {-1,-1}
                        };

const mmi_pen_point_struct tp_send_region[]= {
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_2}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_2}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_3-1}, 
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_3-1}, 
                           {-1,-1}
                        };

const mmi_pen_point_struct tp_clean_region[]={
                           {TP_SCREEN_COL_1,    TP_SCREEN_ROW_2}, 
                           {TP_SCREEN_COL_2-1,  TP_SCREEN_ROW_2}, 
                           {TP_SCREEN_COL_2-1,  TP_SCREEN_ROW_3-1}, 
                           {TP_SCREEN_COL_1,    TP_SCREEN_ROW_3-1}, 
                           {-1,-1}
                        };
                        
const mmi_pen_point_struct tp_end_region[]={
                           {TP_SCREEN_COL_2,    TP_SCREEN_ROW_2}, 
                           {TP_SCREEN_COL_3-1,  TP_SCREEN_ROW_2}, 
                           {TP_SCREEN_COL_3-1,  TP_SCREEN_ROW_3-1}, 
                           {TP_SCREEN_COL_2,    TP_SCREEN_ROW_3-1}, 
                           {-1,-1}
                        };

const mmi_pen_point_struct tp_1_region[]= {
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_3}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_3}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_4-1}, 
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_4-1}, 
                           {-1,-1}
                        };

const mmi_pen_point_struct tp_2_region[]={
                           {TP_SCREEN_COL_1,    TP_SCREEN_ROW_3}, 
                           {TP_SCREEN_COL_2-1,  TP_SCREEN_ROW_3}, 
                           {TP_SCREEN_COL_2-1,  TP_SCREEN_ROW_4-1}, 
                           {TP_SCREEN_COL_1,    TP_SCREEN_ROW_4-1}, 
                           {-1,-1}
                        };
                        
const mmi_pen_point_struct tp_3_region[]={
                           {TP_SCREEN_COL_2,    TP_SCREEN_ROW_3}, 
                           {TP_SCREEN_COL_3-1,  TP_SCREEN_ROW_3}, 
                           {TP_SCREEN_COL_3-1,  TP_SCREEN_ROW_4-1}, 
                           {TP_SCREEN_COL_2,    TP_SCREEN_ROW_4-1}, 
                           {-1,-1}
                        };

const mmi_pen_point_struct tp_4_region[]= {
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_4}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_4}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_5-1}, 
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_5-1}, 
                           {-1,-1}
                        };

const mmi_pen_point_struct tp_5_region[]={
                           {TP_SCREEN_COL_1,    TP_SCREEN_ROW_4}, 
                           {TP_SCREEN_COL_2-1,  TP_SCREEN_ROW_4}, 
                           {TP_SCREEN_COL_2-1,  TP_SCREEN_ROW_5-1}, 
                           {TP_SCREEN_COL_1,    TP_SCREEN_ROW_5-1}, 
                           {-1,-1}
                        };
                        
const mmi_pen_point_struct tp_6_region[]={
                           {TP_SCREEN_COL_2,    TP_SCREEN_ROW_4}, 
                           {TP_SCREEN_COL_3-1,  TP_SCREEN_ROW_4}, 
                           {TP_SCREEN_COL_3-1,  TP_SCREEN_ROW_5-1}, 
                           {TP_SCREEN_COL_2,    TP_SCREEN_ROW_5-1}, 
                           {-1,-1}
                        };

const mmi_pen_point_struct tp_7_region[]= {
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_5}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_5}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_6-1}, 
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_6-1}, 
                           {-1,-1}
                        };

const mmi_pen_point_struct tp_8_region[]={
                           {TP_SCREEN_COL_1,    TP_SCREEN_ROW_5}, 
                           {TP_SCREEN_COL_2-1,  TP_SCREEN_ROW_5}, 
                           {TP_SCREEN_COL_2-1,  TP_SCREEN_ROW_6-1}, 
                           {TP_SCREEN_COL_1,    TP_SCREEN_ROW_6-1}, 
                           {-1,-1}
                        };
                        
const mmi_pen_point_struct tp_9_region[]={
                           {TP_SCREEN_COL_2,    TP_SCREEN_ROW_5}, 
                           {TP_SCREEN_COL_3-1,  TP_SCREEN_ROW_5}, 
                           {TP_SCREEN_COL_3-1,  TP_SCREEN_ROW_6-1}, 
                           {TP_SCREEN_COL_2,    TP_SCREEN_ROW_6-1}, 
                           {-1,-1}
                        };

const mmi_pen_point_struct tp_star_region[]= {
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_6}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_6}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_7-1}, 
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_7-1}, 
                           {-1,-1}
                        };

const mmi_pen_point_struct tp_0_region[]={
                           {TP_SCREEN_COL_1,    TP_SCREEN_ROW_6}, 
                           {TP_SCREEN_COL_2-1,  TP_SCREEN_ROW_6}, 
                           {TP_SCREEN_COL_2-1,  TP_SCREEN_ROW_7-1}, 
                           {TP_SCREEN_COL_1,    TP_SCREEN_ROW_7-1}, 
                           {-1,-1}
                        };
                        
const mmi_pen_point_struct tp_hash_region[]={
                           {TP_SCREEN_COL_2,    TP_SCREEN_ROW_6}, 
                           {TP_SCREEN_COL_3-1,  TP_SCREEN_ROW_6}, 
                           {TP_SCREEN_COL_3-1,  TP_SCREEN_ROW_7-1}, 
                           {TP_SCREEN_COL_2,    TP_SCREEN_ROW_7-1}, 
                           {-1,-1}
                        };








const mmi_pen_point_struct tp_extra_func_region[]={
                           {TP_SCREEN_COL_0,	TP_SCREEN_ROW_7},
                           {TP_SCREEN_COL_0+TP_SCREEN_COL_3/4,    TP_SCREEN_ROW_7+TP_SCREEN_ROW_H/2},
                           {TP_SCREEN_COL_0+TP_SCREEN_COL_3/2,    TP_SCREEN_ROW_7+TP_SCREEN_ROW_H},
                           {TP_SCREEN_COL_0+TP_SCREEN_COL_3*3/4,  TP_SCREEN_ROW_7+TP_SCREEN_ROW_H/2},
                           {TP_SCREEN_COL_3-1,                    TP_SCREEN_ROW_7},
                           {-1,-1}
                        };

const mmi_pen_point_struct tp_handwriting_region[]={
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_2}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_2}, 
                           {TP_SCREEN_COL_1-1,  TP_SCREEN_ROW_8-1}, 
                           {TP_SCREEN_COL_0,    TP_SCREEN_ROW_8-1}, 
                           {-1,-1}
                        };

/* 
 * The area table information... 
 * 1. tp_area_id_enum
 *
 * 2. flag
 *       TP_HANDWRITING_AREA  - it is the handwriting area
 *       TP_CONTROL_AREA      - it is the control area
 *       TP_MAPPING_KEY       - for control area only; Translate the pen event to 
 *                              the key event
 *       TP_CUSTOM_HANDLE     - the custom want to handler pen event by themselves. 
 *       TP_HANDWRITING_SUPPORTS_FULL_AREA - extend handwriting area to full touch 
 *                                           pad area when the first stroke down.
 *
 * 3. region
 *    control area:
 *       The points of the region need to be successive and end at {-1,-1}
 *
 *    handwriting area:
 *       The region must be the rectangle and the points should be in clock wise order
 *
 * 4. pen_handler_table
 *    NULL - use the default handler
 *    Others - the customers provide the special handlers
 */
const tp_area_struct tp_area_table[TP_AREA_MAX_NUM] = {
   /* Handwriting Area */
   {
      TP_AREA_HANDWRITING,
      TP_HANDWRITING_AREA|TP_HANDWRITING_SUPPORTS_FULL_AREA,
      tp_handwriting_region,
      NULL
   },

   /* Control Area */
   {
      TP_CONTROL_AREA_LSK,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_SK_LEFT,
      tp_lsk_region,
      NULL
   },
   {
      TP_CONTROL_AREA_UP_ARROW,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_UP,
      tp_up_arrow_region,
      NULL
   },
   {
      TP_CONTROL_AREA_RSK,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_SK_RIGHT,
      tp_rsk_region,
      NULL
   },

   {
      TP_CONTROL_AREA_LEFT_ARROW,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_LEFT,
      tp_left_arrow_region,
      NULL
   },
   {
      TP_CONTROL_AREA_DOWN_ARROW,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_DOWN,
      tp_down_arrow_region,
      NULL
   },
   {
      TP_CONTROL_AREA_RIGHT_ARROW,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_RIGHT,
      tp_right_arrow_region,
      NULL
   },

   {
      TP_CONTROL_AREA_SEND,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_SEND,
      tp_send_region,
      NULL
   },
   {
      TP_CONTROL_AREA_CLEAN,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_CLEAR,
      tp_clean_region,
      NULL
   },
   {
      TP_CONTROL_AREA_END,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_END,
      tp_end_region,
      NULL
   },

   {
      TP_CONTROL_AREA_1,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_1,
      tp_1_region,
      NULL
   },
   {
      TP_CONTROL_AREA_2,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_2,
      tp_2_region,
      NULL
   },
   {
      TP_CONTROL_AREA_3,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_3,
      tp_3_region,
      NULL
   },

   {
      TP_CONTROL_AREA_4,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_4,
      tp_4_region,
      NULL
   },
   {
      TP_CONTROL_AREA_5,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_5,
      tp_5_region,
      NULL
   },
   {
      TP_CONTROL_AREA_6,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_6,
      tp_6_region,
      NULL
   },

   {
      TP_CONTROL_AREA_7,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_7,
      tp_7_region,
      NULL
   },
   {
      TP_CONTROL_AREA_8,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_8,
      tp_8_region,
      NULL
   },
   {
      TP_CONTROL_AREA_9,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_9,
      tp_9_region,
      NULL
   },

   {
      TP_CONTROL_AREA_STAR,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_STAR,
      tp_star_region,
      NULL
   },
   {
      TP_CONTROL_AREA_0,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_0,
      tp_0_region,
      NULL
   },
   {
      TP_CONTROL_AREA_HASH,
      TP_CONTROL_AREA|TP_MAPPING_KEY|DEVICE_KEY_HASH,
      tp_hash_region,
      NULL
   },


   {
      TP_CONTROL_AREA_EXTRA_FUNC,
      TP_CONTROL_AREA|TP_CUSTOM_HANDLE,
      tp_extra_func_region,
      custom_extra_func_hdlr
   },
};

#endif /* __MMI_HANDWRITING_PAD__ */



#endif

