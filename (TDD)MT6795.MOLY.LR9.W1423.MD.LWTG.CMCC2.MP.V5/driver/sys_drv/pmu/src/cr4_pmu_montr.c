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
 *   cr4_pmu_montr.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   CR4 Performance Monitor Driver
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__MTK_TARGET__)
#if defined(__CR4__)
#include "mcu_pmu_montr.h"
#include "cp15.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

static kal_bool ARM_PMU_Initialized=KAL_FALSE;
const kal_uint32 PMU_EVENT_COUNTER_NUM_MAP[] = {0,0,1,1,2};

/*************************************************************************
* FUNCTION
*  CR4PMU_Initialize
*
* DESCRIPTION
*  This function initialize cycle counter and event counter 1~3
*  Not that this function does not affect cycle count divide option
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void CR4PMU_Initialize(void)
{
    kal_uint32 ctrl;
    ASSERT(ARM_PMU_Initialized==KAL_FALSE); // ARM PMU can only be initialized once
    // Stop all counters
    CR4PMU_StopCounter(PMU_EVENT_COUNTER_1|PMU_EVENT_COUNTER_2|PMU_EVENT_COUNTER_3|PMU_CYCLE_COUNTER);
    // Reset all counters and enable PMU 
    ctrl = cp15_PMU_read_control_register();
    ctrl |= PMU_CTRL_CYCLE_COUNT_RST|PMU_CTRL_EVENT_COUNT_RST|PMU_CTRL_ENABLE;
    cp15_PMU_write_control_register(ctrl);
    // Set PMU init flag to prevent double Initialize
    ARM_PMU_Initialized=KAL_TRUE;
    return;
}

/*************************************************************************
* FUNCTION
*  CR4PMU_CycleCountDivide
*
* DESCRIPTION
*  This function set if cycle counter is divided by 64th or not
*  By default, cycle counter log every cycle
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_bool:  KAL_TRUE -> cycle counter 64th divide
*             KAL_FALSE -> cycle counter count every cycle
*
* RETURNS
*  None
*
*************************************************************************/
void CR4PMU_CycleCountDivide(kal_bool en)
{
    kal_uint32 ctrl;
    ctrl = cp15_PMU_read_control_register();
    if(en==KAL_TRUE)
    {
        ctrl |= PMU_CTRL_CYCLE_COUNT_DIV;
    } 
    else
    {
        ctrl &= ~(PMU_CTRL_CYCLE_COUNT_DIV);
    }
    cp15_PMU_write_control_register(ctrl);
    return;
}

/*************************************************************************
* FUNCTION
*  CR4PMU_SetEvent
*
* DESCRIPTION
*  This function set event for target counter
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  PMU_MONITOR_COUNTER_TYPE:  Counter number to be configure
*  PMU_MONITOR_EVENT_TYPE:    The event to be logged
*
* RETURNS
*  None
*
*************************************************************************/
void CR4PMU_SetEvent(kal_uint32 counter, PMU_MONITOR_EVENT_TYPE event)
{
    ASSERT(counter==PMU_EVENT_COUNTER_1||counter==PMU_EVENT_COUNTER_2||counter==PMU_EVENT_COUNTER_3);
    event&=PMU_EVENT_MASK;
    cp15_PMU_write_event_selection(PMU_EVENT_COUNTER_NUM_MAP[counter], event);
    
    return;
}

/*************************************************************************
* FUNCTION
*  CR4PMU_StartCounter
*
* DESCRIPTION
*  This function starts PMU counter
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_uint32:    Counter number that is to be started
*
* RETURNS
*  None
*
*************************************************************************/
void CR4PMU_StartCounter(kal_uint32 start_counters)
{
    ASSERT((start_counters&(~(PMU_EVENT_COUNTER_1|PMU_EVENT_COUNTER_2|PMU_EVENT_COUNTER_3|PMU_CYCLE_COUNTER)))==0);
    ASSERT(ARM_PMU_Initialized==KAL_TRUE);
    cp15_PMU_write_counter_enable_set(start_counters);
    
    return;
}

/*************************************************************************
* FUNCTION
*  CR4PMU_StopCounter
*
* DESCRIPTION
*  This function starts PMU counter
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  PMU_MONITOR_COUNTER_TYPE:    Counter number that is to be read
*
* RETURNS
*  None
*
*************************************************************************/
void CR4PMU_StopCounter(kal_uint32 stop_counters)
{
    ASSERT((stop_counters&(~(PMU_EVENT_COUNTER_1|PMU_EVENT_COUNTER_2|PMU_EVENT_COUNTER_3|PMU_CYCLE_COUNTER)))==0);
    cp15_PMU_write_counter_enable_clear(stop_counters);
    
    return;
}

/*************************************************************************
* FUNCTION
*  CR4PMU_ReadCounter
*
* DESCRIPTION
*  This function reads PMU counter value
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_uint32:    Counter number that is to be started
*
* RETURNS
*  None
*
*************************************************************************/
kal_uint32 CR4PMU_ReadCounter(kal_uint32 counter)
{   
    ASSERT(counter==PMU_EVENT_COUNTER_1||counter==PMU_EVENT_COUNTER_2||counter==PMU_EVENT_COUNTER_3||counter==PMU_CYCLE_COUNTER);
    
    if(counter==PMU_CYCLE_COUNTER)
    {
        return cp15_PMU_read_cycle_counter();
    }
    else
    {
        return cp15_PMU_read_event_counter(PMU_EVENT_COUNTER_NUM_MAP[counter]);
    }
}

/*************************************************************************
* FUNCTION
*  CR4PMU_ResetCounter
*
* DESCRIPTION
*  This function reset one PMU counter
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_uint32:    Counter number that is to be reset
*
* RETURNS
*  None
*
*************************************************************************/
kal_uint32 CR4PMU_ResetCounter(kal_uint32 counter)
{   
    ASSERT(counter==PMU_EVENT_COUNTER_1||counter==PMU_EVENT_COUNTER_2||counter==PMU_EVENT_COUNTER_3||counter==PMU_CYCLE_COUNTER);
    
    if(counter==PMU_CYCLE_COUNTER)
    {
        cp15_PMU_write_cycle_counter(0);
        return 0;
    }
    else
    {
        cp15_PMU_write_event_counter(PMU_EVENT_COUNTER_NUM_MAP[counter],0);
        return 0;
    }
}


#endif /* __CR4__ */
#endif /* __MTK_TARGET__ */
 
