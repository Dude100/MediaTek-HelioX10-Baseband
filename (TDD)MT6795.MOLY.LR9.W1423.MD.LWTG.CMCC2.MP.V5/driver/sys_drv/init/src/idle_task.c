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
 *   idle_task.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for the functions of idle task.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __MTK_TARGET__
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "syscomp_config.h"
#include "task_config.h"      /* Task creation */
#include "kal_general_types.h"
//#include "task_main_func.h"
#include "kal_internal_api.h"



#if defined(KAL_ON_NUCLEUS)
NU_TASK *IdleTaskTCB;
#elif defined(KAL_ON_THREADX)
TX_THREAD *IdleTaskTCB;
#endif

extern void DCM_Handler(void);

extern void DCM_Init(void);

//#pragma arm section code = "INTERNCODE"
//#pragma arm section code = "INTSRAM_ROCODE"
#define __SECTION__(S) __attribute__ ((__section__(#S)))
#define __ZI__          __attribute__ ((zero_init))

void IdleTask( task_entry_struct * task_entry_ptr ) __SECTION__(INTSRAM_ROCODE);
//#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
//#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"


void IdleTask( task_entry_struct * task_entry_ptr )
{

#if defined(KAL_ON_NUCLEUS)
	IdleTaskTCB = (NU_TASK*)kal_get_task_by_moduleID(MOD_IDLE);  //(NU_TASK*)task_info_g[task_entry_ptr->task_indx].task_id;
#elif defined(KAL_ON_THREADX)
	IdleTaskTCB = (TX_THREAD*)kal_get_task_by_moduleID(MOD_IDLE);  //(TX_THREAD *)task_info_g[task_entry_ptr->task_indx].task_id;
#endif
	
   DCM_Init();

   while(1)
   {
       DCM_Handler();
   }    /* Infinite loop */
}

  
//#pragma arm section rwdata , rodata , zidata



/*************************************************************************
* FUNCTION                                                            
*	idle_create
*
* DESCRIPTION                                                           
*	This function implements idle entity's create handler.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
idle_create(comptask_handler_struct **handle)
{
	static const comptask_handler_struct idle_handler_info = 
	{
		IdleTask,			/* task entry function */
		NULL,			/* task initialization function */
		NULL			/* task reset handler */
	};

	*handle = (comptask_handler_struct *)&idle_handler_info;


	return KAL_TRUE;
}


#else  /* __MTK_TARGET__ */
   
#endif


