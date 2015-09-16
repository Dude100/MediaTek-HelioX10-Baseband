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
 *   kal_internal_api.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This header file is used to define internal api, do not export!
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __KAL_INTERNAL_DEFINATIONS__
#define __KAL_INTERNAL_DEFINATIONS__

#include "srv_modid.h"
#include "drv_modid.h"
#include "modem_2g3g_modid.h"
#include "middleware_modid.h"
#include "hisr_modid.h"

#undef TASK_PRIORITY_MACRO

#undef SRV_TASK_CONFIG
#undef MODEM_2G3G_TASK_CONFIG
#undef MIDDLEWARE_TASK_CONFIG
#undef DRIVER_TASK_CONFIG

#define SRV_TASK_CONFIG
#define MODEM_2G3G_TASK_CONFIG
#define MIDDLEWARE_TASK_CONFIG
#define DRIVER_TASK_CONFIG

#undef task_index

/*define all macros as empty*/
#define task_name(p1)
#define task_queue_name(p1)
#define task_priority(p1,p2)
#define task_stack_size(p1)
#define null_task_create_entry(p1)
#define compatible_code(p1)
#define task_create_function(p1)
#define task_stack_internalRAM(p1)
#define task_external_queue_size(p1)
#define task_internal_queue_size(p1)
#define task_boot_mode(p1)
#define MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(p1)
#define MODULE_ID_FOR_PRINT_TRACE(p1)
#define task_module_map(task, mod)
#define task_index(p1)


typedef enum {
    LAST_MOD_ID = ( MODULE_TAG_SRV_TAIL + 1 +
    				MODULE_TAG_MODEM_DUMMY_TAIL - MOD_MODEM_DUMMY_BEGIN + 1 +
    				MODULE_TAG_MODEM_4G_DUMMY_TAIL - MOD_MODEM_4G_DUMMY_BEGIN + 1 +
    				MODULE_TAG_MW_DUMMY_TAIL - MOD_MW_DUMMY_BEGIN + 1 + 
    				MODULE_TAG_DRV_DUMMY_TAIL - MOD_DRV_DUMMY_BEGIN + 1) + (2 + KAL_MAX_NUM_HISRS),
	
	RPS_TOTAL_STACK_MODULES = LAST_MOD_ID,
	MOD_LIBRARY_BEGIN = 990,
	MOD_BOUNDARY,
	MAX_MODULE_ID = 1023

}module_type_t;


/*************************************************************************
 * module type boundary check
 * Don't use this array in your code
 *************************************************************************/
typedef unsigned int module_id_boundary_check[MAX_MODULE_ID - MOD_BOUNDARY];
typedef unsigned int total_stack_modules_boundary_check[MOD_LIBRARY_BEGIN + 1 - RPS_TOTAL_STACK_MODULES]; 
/************************************************************************/

/* unmark this defination would use static memory for default prioriry node*/
//#define KAL_PRIORITY_NODE_BY_CTRL_BUFF 1

#endif /* __KAL_INTERNAL_DEFINATIONS__  */
