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
 *   custom_equipment.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains definition of custom component module configuration
 *   variables, and routines handle for equipment device.
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
 * removed!
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __L1_STANDALONE__

/*
**   Includes
*/
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"
#include "nvram_editor_data_item.h"
#include "stack_types.h"
#include "syscomp_config.h"
//MSBB remove #include "custom_config.h"
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"

#include "device.h"
#include "l1audio.h"
#include "resource_audio.h"
#include "custom_equipment.h"
#include "custom_hw_default.h"
#include "custom_em.h"

/*
**   Typedefs
*/

/*
**   Defines
*/

/* 
**   Extern Functions
*/
#ifndef __CUST_NEW__
extern void GPIO_WriteIO(char data, char port);
extern void PWM_level(kal_uint8 level);
extern void PWM2_level(kal_uint8 level);
#endif /* __CUST_NEW__ */
//extern void Alter_level(kal_uint8 level);

/* 
**   Extern Varibales 
*/


/* 
**   Globol Varibales 
*/

/* 
**   Local Functions 
*/

/* 
**   Local Variables 
*/
//static kal_uint8  l_ext_device_id = EXT_DEV_NONE;

#ifndef __CUST_NEW__
/***********************************************************
  **
  **  GPIO MAPPING TABLE
  **
  ***********************************************************/

const unsigned char netname[][MAX_NETNAME_TEXT] = {
   "GPIO#0",
   "GPIO#1",
   "GPIO#2",
   "GPIO#3",
   "GPIO#4",
   "GPIO#5",
   "GPIO#6",
   "GPIO#7",
   "GPIO#8",
   "GPIO#9",
   "GPIO#10",
   "GPIO#11",
   "GPIO#12",
   "GPIO#13",
   "GPIO#14",
   "GPIO#15",
   "GPIO#16",
   "GPIO#17",
   "GPIO#18",
   "GPIO#19",
   "GPIO#20",
   "GPO#1",
   "GPO#2",
   "GPO#3"
};



GPIO_MAP_ENTRY gpio_map_tbl[] = {
/*GPIO_LABEL_LED_LCD */      {GPIO_VAILD, GPIO_PORT_12, netname[GPIO_PORT_12], NULL },
/*GPIO_LABEL_DEV_LED_KEY */      {GPIO_VAILD, GPIO_PORT_13, netname[GPIO_PORT_13], NULL },
/*GPIO_LABEL_DEV_LED_STATUS */      {GPIO_VAILD, GPIO_PORT_14, netname[GPIO_PORT_14], NULL },
/*GPIO_LABEL_DEV_VIBRATOR */      {GPIO_VAILD, GPIO_PORT_15, netname[GPIO_PORT_15], NULL },
/*GPIO_LABELID_4 */      {GPIO_INVAILD, GPIO_PORT_4, netname[GPIO_PORT_4], NULL },
/*GPIO_LABELID_5 */      {GPIO_INVAILD, GPIO_PORT_5, netname[GPIO_PORT_5], NULL },
/*GPIO_LABELID_6 */      {GPIO_INVAILD, GPIO_PORT_6, netname[GPIO_PORT_6], NULL },
/*GPIO_LABELID_7 */      {GPIO_INVAILD, GPIO_PORT_7, netname[GPIO_PORT_7], NULL },
/*GPIO_LABELID_8 */      {GPIO_INVAILD, GPIO_PORT_8, netname[GPIO_PORT_8], NULL },
/*GPIO_LABELID_9 */      {GPIO_INVAILD, GPIO_PORT_9, netname[GPIO_PORT_9], NULL },
/*GPIO_LABELID_10 */      {GPIO_INVAILD, GPIO_PORT_10, netname[GPIO_PORT_10], NULL },
/*GPIO_LABELID_11 */      {GPIO_INVAILD, GPIO_PORT_11, netname[GPIO_PORT_11], NULL },
/*GPIO_LABELID_12 */      {GPIO_INVAILD, GPIO_PORT_12, netname[GPIO_PORT_12], NULL },
/*GPIO_LABELID_13 */      {GPIO_INVAILD, GPIO_PORT_13, netname[GPIO_PORT_13], NULL },
/*GPIO_LABELID_14 */      {GPIO_INVAILD, GPIO_PORT_14, netname[GPIO_PORT_14], NULL },
/*GPIO_LABELID_15 */      {GPIO_INVAILD, GPIO_PORT_15, netname[GPIO_PORT_15], NULL },
/*GPIO_LABELID_16 */      {GPIO_INVAILD, GPIO_PORT_16, netname[GPIO_PORT_16], NULL },
/*GPIO_LABELID_17 */      {GPIO_INVAILD, GPIO_PORT_17, netname[GPIO_PORT_17], NULL },
/*GPIO_LABELID_18 */      {GPIO_INVAILD, GPIO_PORT_18, netname[GPIO_PORT_18], NULL },
/*GPIO_LABELID_19 */      {GPIO_INVAILD, GPIO_PORT_19, netname[GPIO_PORT_19], NULL },
/*GPIO_LABELID_20 */      {GPIO_INVAILD, GPIO_PORT_20, netname[GPIO_PORT_20], NULL },
/*GPO_LABELID_1 */      {GPIO_INVAILD, 0, netname[21], NULL },
/*GPO_LABELID_2 */      {GPIO_INVAILD, 0, netname[22], NULL },
/*GPO_LABELID_3 */      {GPIO_INVAILD, 0, netname[23], NULL }
};




/***********************************************************
  **
  **  EINT MAPPING TABLE  ( Execution Table )
  **
  ***********************************************************/

const unsigned char eintname[][MAX_NETNAME_TEXT] = {
   "Charger",
   "Cable",
   "SendKey",
   "Earphone",
   "ClamShell"
};

GPIO_MAP_ENTRY eint_map_tbl[] = {
/*EINT_LABELID_0 */      {GPIO_VAILD, 0, eintname[0], NULL },
/*EINT_LABELID_1 */      {GPIO_VAILD, 1, eintname[1], NULL },
/*EINT_LABELID_2 */      {GPIO_VAILD, 1, eintname[2], NULL },
/*EINT_LABELID_3 */      {GPIO_VAILD, 1, eintname[3], NULL },
/*EINT_LABELID_4 */      {GPIO_INVAILD, 2, eintname[4], NULL },
};



/***********************************************************
  **
  **  ADC MAPPING TABLE  ( Execution Table )
  **
  ***********************************************************/
const unsigned char adcname[][MAX_NETNAME_TEXT] = {
   "VBAT",
   "BTemp",
   "VAUX",
   "Current",
   "VChgr"
};

GPIO_MAP_ENTRY adc_map_tbl[] = {
/*ADC_LABELID_0 */      {GPIO_VAILD, 0, adcname[0], NULL },
/*ADC_LABELID_1 */      {GPIO_VAILD, 1, adcname[1], NULL },
/*ADC_LABELID_2 */      {GPIO_VAILD, 2, adcname[2], NULL },
/*ADC_LABELID_3 */      {GPIO_VAILD, 3, adcname[3], NULL },
/*ADC_LABELID_4 */      {GPIO_VAILD, 4, adcname[4], NULL },
};
#endif /* __CUST_NEW__*/

/* 
*   Function 
*      custom_cfg_vbat_level_regulator
*   DESCRIPTION
*      The function is used to convert the vbat value to the end-user level .
*     And it will be call by audio manager.
*   PARAMETERS
*     vbat      IN
*   RETURNS
*      kal_uint8
*   GLOBALS AFFECTED
*/
kal_uint8 custom_cfg_vbat_level_regulator( kal_uint32 measure_voltage, kal_uint8 *last_level, kal_uint8 *disp_level, kal_uint8 *hit_count )
{
   kal_uint8 level=0; 
   //kal_uint8 regulated_level=0; 

   for( level=0; level<BATTERY_MAX_LEVEL; level++)
      if( measure_voltage <= Battery_Level_Info[level] )
         break;
         
   if( level > *disp_level )
      {
            for( level=0; level<BATTERY_MAX_LEVEL; level++)
               if( measure_voltage <= (Battery_Level_Info[level] + VBAT_GROWUP_PENALTY) )
                  break;
      }

   if( level == *last_level )
      {
           if( *hit_count >= VBAT_HIT_COUNT_BOUND )
            {
                 //regulated_level = *disp_level = level;
            }
           else 
           {
                (*hit_count)++;
                //regulated_level = *disp_level;
            }
      }
   else
      {
           *hit_count=1;
           //regulated_level = *disp_level;

      }
   
  *last_level = level;

   if( level <= BATTERY_LOW_WARNING )
      return ( level );
   else
   return ( *disp_level );
   
}

/*
*      custom_cfg_vbat_level_convert
*   DESCRIPTION
*      The function is used to convert the vbat value to the end-user level .
*     And it will be call by audio manager.
*   PARAMETERS
*     vbat      IN
*   RETURNS
*      kal_uint8
*   GLOBALS AFFECTED
*/
kal_uint8 custom_cfg_vbat_level_convert
(
 kal_int32  vbat
 )
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_uint8 level=0; /* the level could be customized by user */
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   for( level=0; level<BATTERY_MAX_LEVEL; level++)
      if( vbat <= Battery_Level_Info[level] )
         return level;
      
   return (BATTERY_MAX_LEVEL-1);

}

/*
*      custom_cfg_vbat_percentage_convert
*   DESCRIPTION
*      The function is used to convert the vbat value to the end-user level .
*     And it will be call by audio manager.
*   PARAMETERS
*     vbat      IN
*   RETURNS
*      kal_uint8
*   GLOBALS AFFECTED
*/
kal_uint32 custom_cfg_vbat_percentage_convert
(
 kal_uint32  vbat
 )
{
   kal_uint32 int_result;
   double result;

   if( BATLEV_MAX_IDX == 0 )
   {
      ASSERT(BATLEV_MAX_VOLTAGE > 0);
      result = (double)vbat/(double)BATLEV_MAX_VOLTAGE;
      
   }
   else if( BATLEV_MAX_IDX > 0 && BATLEV_MAX_IDX < BATTERY_MAX_LEVEL ) 
   {
      ASSERT(Battery_Level_Info[BATLEV_MAX_IDX] > 0);
      result = (double)vbat/(double)Battery_Level_Info[BATLEV_MAX_IDX] ;
   }
   else
   {
       result = 0.0;
   }
   
   int_result = (kal_uint32) (result * 10000);
   
   return (int_result);
}

#ifndef __CUST_NEW__
/***********************************************************
  **
  **  GPIO SETTTING
  **
  ***********************************************************/



/* 
*   Function 
*      custom_cfg_outward_gpio_port
*   DESCRIPTION
*      The function is used to handle the port number of the outward gpio device.
*     And it will be call by audio manager.
*   PARAMETERS
*     gpio_device_id      IN
*     port_num            IN/OUT
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*/
kal_uint8 custom_cfg_outward_gpio_port(  kal_uint8  gpio_device_id /* gpio_device_enum */)
{
   if( (gpio_device_id < GPIO_LABELID_MAX) && (gpio_map_tbl[gpio_device_id].vaild != GPIO_INVAILD) )
      return gpio_map_tbl[gpio_device_id].port;
   else
      return 0;
}




kal_bool custom_cfg_gpio_set_level(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level )
{
   kal_bool res=KAL_TRUE;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   return res;
}

void custom_start_flashlight(kal_uint8 red_level, kal_uint8 green_level, kal_uint8 blue_level, kal_uint8 duty)
{
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_1, ((red_level>0) ? LED_LIGHT_LEVEL5 : LED_LIGHT_LEVEL0));
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_2, ((green_level>0) ? LED_LIGHT_LEVEL5 : LED_LIGHT_LEVEL0));
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_3, ((blue_level>0) ? LED_LIGHT_LEVEL5 : LED_LIGHT_LEVEL0));

       PWM2_Configure(PWM2_Level_Info[0][0], duty);   
       PWM2_Start();
}

void custom_stop_flashlight(void)
{ 
       custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
       custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0);
       custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0);
       
       PWM2_Stop();
}
#endif /* __CUST_NEW__ */

#endif /* !__L1_STANDALONE__ */


