/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *	ds_if.h
 *
 * Project:
 * --------
 *   ALL
 *
 * Description:
 * ------------
 *   This file is intends for direct sensor interface driver.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DS_IF_H__
#define __DS_IF_H__

//RHR #include "kal_release.h"
//MSBB remove #include "kal_non_specific_general_types.h"


//Action Id
#define DS_IF_DATA_BUS_CONTL  0x01 
#define DS_IF_SEN2LCM_SET  0x02
#define DS_IF_FRAME_DONE_CB_REGISTER  0x04
#define DS_IF_SENSOR_PAUSE_CB_REGISTER  0x08
#define DS_IF_SENSOR_RESUME_CB_REGISTER  0x10


//Error code
#define DS_IF_SUCCEED                                               0x0000
#define DS_IF_ERR_INVALID_HANDLE                          0x0001 
#define DS_IF_ERR_INVALID_ACTION                          0x0002
#define DS_IF_ERR_INVALID_PARA                              0x0004
#define DS_IF_ERR_NOT_ALLOWED_STATE                  0x0008
#define DS_IF_ERR_CALLER_CONTEXT_NOT_ALLOW    0x0010
#define DS_IF_ERR_CAL_NOT_DIRECT_SENSOR           0x0020
#define DS_IF_ERR_CAL_NOT_CONFIG_HW_TIMING    0x0040
#define DS_IF_ERR_NOT_REGISTERED_CB                    0x0080
#define DS_IF_ERR_TOO_MANY_USERS                        0x8000



#define USER_HANDLE_FOR_NON_DIRECT_SENSOR                  0x0
#define DUMMY_USER_HANDLE_FOR_TOO_MANY_USERS          0xF1


typedef void (*DS_CB_FUNC)(void * cb_para);

typedef enum
{
   DS_IF_STATE_INIT= 0, 
   DS_IF_STATE_READY = 1, 
   DS_IF_STATE_BUS = 2, 
   DS_IF_STATE_BUSY = 3 
} DS_IF_STATE_E;


typedef enum
{
   UNKNOWN_SENSOR = 0, 
   DIRECT_SENSOR = 1, 
   SERIAL_SENSOR = 2, 
   PARALLEL_SENSOR= 3 
} SENSOR_IF_TYPE;

typedef enum
{
   CAL_DS_IF_USER = 0, 
   LCD_DS_IF_USER, 
   MAX_DS_IF_USERS 
} DS_IF_USER;


typedef struct
{
   kal_uint16 para_1;
   kal_uint16 para_2;
   kal_uint16 para_3;
   kal_uint16 para_4;
   kal_uint16 para_5;
   kal_uint16 para_6;
   kal_bool para_7;
   kal_bool para_8;
   kal_bool para_9;
   kal_uint32 para_10;
} DS_SEN2LCM_T;


typedef struct
{
//only valid for action DS_DATA_BUS_CONTL been asserted.
kal_bool    data_bus_control_take; // KAL_TRUE for taken, KAL_FALSE for release, 
// only valid for DS_SEN2LCM_SET been asserted.
DS_SEN2LCM_T    sen2lcm_setting; 
// only valid for DS_FRAME_DONE_CB_REGISTER been asserted.
kal_bool    repeat_callback; // KAL_TRUE for repeat, KAL_FALSE for first frame only
DS_CB_FUNC    frame_done_cb_func;
// only valid for DS_SENSOR_PAUSE_CB_REGISTER been asserted.
DS_CB_FUNC    sensor_pause;
// only valid for DS_SENSOR_RESUME_CB_REGISTER been asserted.
DS_CB_FUNC    sensor_resume;
} DS_CONFG_T;


/**
 *  Get user handle for other function call usage afterwards.
 *  @param sensor      : sensor type
 *  @param user_id      : predefine user id
 *  @return kal_uint32 : user handle
 *  @remarks This function return user handle, which is valid on for DIRECT_SENSOR.
 *           Other sensor type returned handle is not effective in following call.
 */
kal_uint32 ds_if_open(SENSOR_IF_TYPE sensor, DS_IF_USER user_id);


/**
 *  release user handle and close usage privilege.
 *  @param handle      : user handle
 *  @return kal_uint32 : error code
 *  @remarks This function must call after ds_if_open() and can not call in HW interface busy state.
 *  
 */
kal_uint32 ds_if_close(kal_uint32 handle);


/**
 *  configure the HW parameters or others
 *  @param handle      : user handle
 *  @param action       : action id
 *  @param para         : parameters corresponding to action id
 *  @return kal_uint32 : error code
 *  @remarks This function must call after ds_if_open() and can not call in HW interface busy state.
 *  
 */
kal_uint32 ds_if_config(kal_uint32 handle, kal_uint32 action, DS_CONFG_T* para);


/**
 *  start HW for direct sensor mode display 
 *  @param handle      : user handle
 *  @return kal_uint32 : error code
 *  @remarks This function must call after ds_if_open() and can not call in HW interface busy state.
 *  
 */
kal_uint32 ds_if_start (kal_uint32 handle);


/**
 *  stop HW which is in direct sensor mode display 
 *  @param handle      : user handle
 *  @return kal_uint32 : error code
 *  @remarks This function must call after ds_if_open() and after ds_if_start( ). That is, only stop HW when HW is in busy state
 *  
 */
kal_uint32 ds_if_stop (kal_uint32 handle);



/**
 *  query current HW(direct sensor interface) state
 *  @param 
 *  @return DS_IF_STATE_E : HW state
 *  @remarks After first call ds_if_open() the state change from INIT to READY. Afterwards, BUS, or BUSY states transition depends on data bus and hw status.
 *  
 */
DS_IF_STATE_E ds_if_query_state (void);

//only for lcd driver
kal_uint32 ds_if_pause_sensor_cb (kal_uint32 handle);

//only for lcd driver
kal_uint32 ds_if_resume_sensor_cb (kal_uint32 handle);

//only call from lcd_Hisr
kal_uint32 ds_if_hisr(kal_uint32 intr_status);

//only for lcd driver
void lcd_set_ds_a0_polarity(unsigned long a0);

//only for lcd driver
kal_uint32 ds_if_enable_per_frame_lcm_roi_coms (kal_uint32 handle, kal_bool on_Noff);

#endif   /*__DS_IF_H__*/

