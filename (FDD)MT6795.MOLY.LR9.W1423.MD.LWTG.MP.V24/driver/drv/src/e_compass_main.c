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
 *    e_compass_main.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines a task to provide e_compass driver interface
 *
 * Author:
 * Peter Zhang
 *
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "syscomp_config.h"   
#if defined (__E_COMPASS_SENSOR_SUPPORT__)
#include "kal_public_api.h"
#include "stacklib.h"           /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"         /* Event scheduler */
#include "task_config.h"        /* Task creation */
#include "e_compass_sensor.h"

extern E_CompassSensorStruct e_compass_sensor_data;

/*************************************************************************
* Function declaration
 *************************************************************************/
kal_bool    ec_task_create(comptask_handler_struct **handle);

static void ec_task_main(task_entry_struct *task_entry_ptr);
static kal_bool   ec_task_reset(void);
static kal_bool   ec_task_end(void);

/*************************************************************************
* FUNCTION
*   ec_task_create
*
* DESCRIPTION
*   This function implements xyz entity's create handler.
*
* PARAMETERS
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
ec_task_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct ec_handler_info =
    {
        ec_task_main,       /* task entry function */
        NULL,               /* task initialization function */
        ec_task_reset       /* task reset handler */
       
    };

    *handle = (comptask_handler_struct *)&ec_handler_info;
    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*   ec_task_main
*
* DESCRIPTION
*   This function implements xyz task's entry function
*
* PARAMETERS
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void ec_task_main( task_entry_struct * task_entry_ptr )
{	
    kal_uint32 event_group;
    /*initialize function*/
    if (e_compass_sensor_data.event == NULL)
      e_compass_sensor_data.event = kal_create_event_group("ECEVT");
    e_compass_init();

    while (1) 
    {
        kal_retrieve_eg_events(e_compass_sensor_data.event,1,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);
        e_compass_main_hdr();
    }

    /* Do component task's processing here */
}

/*************************************************************************
* FUNCTION
*	ec_task_reset
*
* DESCRIPTION
*	This function implements xyz's reset handler
*
* PARAMETERS
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
ec_task_reset(void)
{
    /* Do task's reset here.
     * Notice that: shouldn't execute modules reset handler since
     * stack_task_reset() will do. */
    return KAL_TRUE;
}

#endif
