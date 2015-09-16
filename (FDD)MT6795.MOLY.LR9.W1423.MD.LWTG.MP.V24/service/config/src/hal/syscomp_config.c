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
 *   syscomp_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains definition of system component module configuration
 *   variables, and routines.
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
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "syscomp_config.h"
#include "task_config.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"
#include "hisr_config.h"

#include "ctrl_buff_pool.h"
#include "event_shed.h"
#include "page.h"
#include "module_hisrid_range.h"
#include "kal_internal_def.h"
#include "module_id_range.h"

#undef TASK_PRIORITY_MACRO

#undef task_name
#undef task_queue_name
#undef task_priority
#undef task_stack_size
#undef null_task_create_entry
#undef compatible_code
#undef task_create_function
#undef task_stack_internalRAM
#undef task_external_queue_size
#undef task_internal_queue_size
#undef task_boot_mode
#undef MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM
#undef MODULE_ID_FOR_PRINT_TRACE
#undef task_index
#undef task_module_map

/*Reset the macro in case of side effect*/
#define task_name(p1)
#define task_queue_name(p1)
#define task_priority(p1,p2)
#define task_stack_size(p1)
#define null_task_create_entry(p1)
#define compatible_code(p1)
#define task_stack_internalRAM(p1)
#define task_external_queue_size(p1)
#define task_internal_queue_size(p1)
#define task_boot_mode(p1)
#define MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(p1)
#define MODULE_ID_FOR_PRINT_TRACE(p1)
#define task_index(p1)
#define task_module_map(task, mod)

#define task_create_function(task_create_entry) \
    extern kal_bool task_create_entry(comptask_handler_struct **);

	#include "srv_task_config.h"
	#include "modem_2g3g_task_config.h"
    #include "modem_4g_task_config.h"
	#include "middleWare_task_config.h"
	#include "drv_task_config.h"	

#undef task_create_function
                                      
/*************************************************************************
 * define global variables to replace config internal macro
 * **********************************************************************/
const kal_uint32 total_stack_tasks = RPS_TOTAL_STACK_TASKS;
const kal_uint32 total_stack_modules = RPS_TOTAL_STACK_MODULES;
const kal_uint32 last_of_module_id = LAST_MOD_ID;
const kal_uint32 end_of_module_id = END_OF_MOD_ID;
/***********************************************************************/
#undef task_name
#undef task_queue_name
#undef task_priority
#undef task_stack_size
#undef null_task_create_entry
#undef compatible_code
#undef task_create_function
#undef task_stack_internalRAM
#undef task_external_queue_size
#undef task_internal_queue_size
#undef task_boot_mode
#undef MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM
#undef MODULE_ID_FOR_PRINT_TRACE
#undef task_index
#undef task_module_map

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
#define MODULE_ID_FOR_PRINT_TRACE(p1)
#define task_index(p1)

#define task_module_map(task, mod) task,
#define MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(p1) INDX_NIL,
#define MODULE_ID_FOR_PRINT_TRACE(p1) INDX_NIL,
/**RPS_TOTAL_STACK_MODULES: boundary check when access mod_task_g*/
kal_uint32 mod_task_g[RPS_TOTAL_STACK_MODULES] =
{
	#include "srv_task_config.h"
	#include "modem_2g3g_task_config.h"
    #include "modem_4g_task_config.h"
	#include "middleWare_task_config.h"
	#include "drv_task_config.h"	
    INDX_NIL,/* MOD_HISR_BEGIN */    
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL, INDX_NIL,
    INDX_NIL,/*MOD_APP_BEGIN */ 
};
/*************************************************************************
 * Total HISR number boundary check
 * Don't use this array in your code
 *************************************************************************/
/* if you change KAL_MAX_NUM_HISRS, please also modify INDX_NIL number in mod_task_g[]*/
/* if you change KAL_MAX_NUM_HISRS, please also modify MOD_ID_HISR_CODE_TAIL in MODULE_ID_TYPE*/
#define HISR_MOD_NUMBER (MOD_ID_HISR_CODE_TAIL-MOD_ID_HISR_CODE_BEGIN-1)	
typedef unsigned int hisr_mod_max_num_check1[HISR_MOD_NUMBER - KAL_MAX_NUM_HISRS
#if !defined(__MTK_TARGET__)
+1
#endif
]; 
typedef unsigned int hisr_mod_max_num_check2[KAL_MAX_NUM_HISRS - HISR_MOD_NUMBER
#if !defined(__MTK_TARGET__)
+1
#endif
]; 

#undef task_name
#undef task_queue_name
#undef task_priority
#undef task_stack_size
#undef task_create_function
#undef compatible_code 
#undef null_task_create_entry
#undef task_stack_internalRAM
#undef task_external_queue_size
#undef task_internal_queue_size
#undef task_boot_mode
#undef MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM
#undef MODULE_ID_FOR_PRINT_TRACE
#undef task_index
#undef task_module_map

#define task_index(p1)
#define task_module_map(task, mod)
#define compatible_code(p1)
#define MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(p1)
#define MODULE_ID_FOR_PRINT_TRACE(p1)

#define task_name(p1)                       {p1, 
#define task_queue_name(p1)                  p1,   
#define task_priority(p1, p2)               ((p1<<16) | (p2 & 0x0000ffff)),
#define task_stack_size(p1)                 KAL_STACK_ALIGN(p1 + TASK_STACK_COMMON_PLUS),
#define null_task_create_entry(p1)          (kal_create_func_ptr)TASK_NO_CREATE_PATTERN,
#define task_create_function(p1)             p1,
#define task_stack_internalRAM(p1)           p1,
#define task_external_queue_size(p1)         p1, 
#define task_internal_queue_size(p1)         p1,
#define task_boot_mode(p1)                   p1},

const comptask_info_struct sys_comp_config_tbl[RPS_TOTAL_STACK_TASKS] =
{
	#include "srv_task_config.h"
	#include "modem_2g3g_task_config.h"
    #include "modem_4g_task_config.h"
	#include "middleWare_task_config.h"
	#include "drv_task_config.h"
};

#define X_HISR_MOD(a,h)

#if defined(__UNIFIED_ISR_LEVEL__)
#define X_HISR_CONST(a,b,c,d,e,f,g)
#define X_HISR_CONST_WITH_INTID(a,b,c,d,e,f,g,i) {a,i}, 
#define X_HISR_INTID(a,j) {a,j},
const hisr_intid_map hisr_intid_g[]=
{
	{HISR_NIL, /*INTID_ERROR*/0xFFFF},
  #include "hisr_config_internal.h"
};	
const kal_uint32 total_hisr_intid_g = sizeof(hisr_intid_g)/sizeof(hisr_intid_map);
#undef X_HISR_CONST_WITH_INTID   
#undef X_HISR_INTID
#undef X_HISR_CONST   

#define X_HISR_INTID(a,j)
#define X_HISR_CONST_WITH_INTID(index, hisr_index, name, priority, stack, entry, option, interrupt_index) \
{index, priority, option, KAL_STACK_ALIGN(stack + HISR_STACK_COMMON_PLUS), entry, name},
#else
const hisr_intid_map hisr_intid_g[]=
{
    {HISR_NIL, /*INTID_ERROR*/0xFFFF},
};	
#endif
const kal_uint32 hisr_intid_map_size = sizeof(hisr_intid_map);

#define X_HISR_CONST(index, hisr_index, name, priority, stack, entry, option) \
{index, priority, option, KAL_STACK_ALIGN(stack + HISR_STACK_COMMON_PLUS), entry, name},

const hisr_parameter_s hisr_info[] =
{
#include "hisr_config_internal.h"
};
#undef X_HISR_CONST   
#undef X_HISR_MOD    
#if defined(__UNIFIED_ISR_LEVEL__)
#undef X_HISR_CONST_WITH_INTID   
#undef X_HISR_INTID
kal_hisrid hisr_initialized[sizeof(hisr_info)/sizeof(hisr_parameter_s)];
#endif
/*to move kal_init_hisr from config folder ,we difine totol_hisr to avoid */
const kal_uint32 total_hisr_g = sizeof(hisr_info)/sizeof(hisr_parameter_s);
const kal_uint32 cfg_hisr_priority_max = 
#ifdef __MTK_TARGET__
TC_HISR_PRIORITIES;
#else
0;
#endif
/*
 *The following code is for sys_mem_gen.pl and should never be linked 
 *into the final bin. The following code is actually usefull for 
 *sys_mem_gen.pl 
 */
typedef struct
{
    kal_uint32 buf_size;
    kal_uint16 buf_num;
}buffer_size_s;
#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const buffer_size_s cfg_ctrl_buff[] =
{
    {CTRL_BUFF_POOL_SIZE32, (NUM_CTRL_BUFF_POOL_SIZE32 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE32)},
    {CTRL_BUFF_POOL_SIZE64, (NUM_CTRL_BUFF_POOL_SIZE64 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE64)},
    {CTRL_BUFF_POOL_SIZE128, (NUM_CTRL_BUFF_POOL_SIZE128 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE128)},
    {CTRL_BUFF_POOL_SIZE256, (NUM_CTRL_BUFF_POOL_SIZE256 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE256)},
    {CTRL_BUFF_POOL_SIZE512, (NUM_CTRL_BUFF_POOL_SIZE512 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE512)},
    {CTRL_BUFF_POOL_SIZE1024, (NUM_CTRL_BUFF_POOL_SIZE1024 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE1024)},
    {CTRL_BUFF_POOL_SIZE2048, (NUM_CTRL_BUFF_POOL_SIZE2048 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE2048)},
    {CTRL_BUFF_POOL_SIZE4096, (NUM_CTRL_BUFF_POOL_SIZE4096 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE4096)},
#if defined(__UMTS_RAT__) || defined(__LTE_RAT__)
    {CTRL_BUFF_POOL_SIZE8192, (NUM_CTRL_BUFF_POOL_SIZE8192 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE8192)},
    {CTRL_BUFF_POOL_SIZE16384, (NUM_CTRL_BUFF_POOL_SIZE16384 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE16384)},
    {CTRL_BUFF_POOL_SIZE32768, (NUM_CTRL_BUFF_POOL_SIZE32768 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE32768)},
    {CTRL_BUFF_POOL_SIZE65536, (NUM_CTRL_BUFF_POOL_SIZE65536 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE65536)},
    {CTRL_BUFF_POOL_SIZE100000, (NUM_CTRL_BUFF_POOL_SIZE100000 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE100000)},
#endif
};

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
#if defined(__CS_SERVICE__) && defined(__PS_SERVICE__)
const buffer_size_s cfg_data_buff[] =
{
    {0, 0},
};
#else
const buffer_size_s cfg_data_buff[] =
{
    {0, 0},
};
#endif
#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const buffer_size_s cfg_event_buff[] =
{
    {sizeof(struct event), KAL_MIN_EVSHED_BUFF_NUM},
};

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const buffer_size_s cfg_module_number[] =
{
    {sizeof (struct ilm_struct), RPS_TOTAL_STACK_MODULES},
};

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
#ifdef __SYS_INTERN_RAM__
const kal_uint32 sys_internal_ram_defined = 1;
#else
const kal_uint32 sys_internal_ram_defined = 0;
#endif

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
#ifdef DEBUG_BUF2
const kal_uint32 debug_buf2 = 1; 
#else
const kal_uint32 debug_buf2 = 0; 
#endif

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
#if defined(__LOW_COST_SUPPORT_ULC__)
const kal_uint32 cfg_low_cost_support = 2;
#elif defined(__LOW_COST_SUPPORT_COMMON__)
const kal_uint32 cfg_low_cost_support = 1;
#else
const kal_uint32 cfg_low_cost_support = 0;
#endif

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
#if (GEMINI_PLUS >= 4)
const kal_uint32 cfg_gemini = 4;
#elif (GEMINI_PLUS >= 3)
const kal_uint32 cfg_gemini = 3;
#elif (GEMINI_PLUS >= 2)
const kal_uint32 cfg_gemini = 2;
#else
const kal_uint32 cfg_gemini = 1;
#endif

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
//XXX stack isolation
#if defined( __KAL_STACK_ISOLATION__)
const kal_uint32 stack_isolation = 1;
#else
const kal_uint32 stack_isolation = 0;
#endif

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
#if defined(__ARM9_MMU__)
const kal_uint32 page_size = 1024;
#elif defined(__ARM11_MMU__)
const kal_uint32 page_size = 4096;
#else
const kal_uint32 page_size = 4096;
#endif

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const kal_uint32 task_stack_common_plus = TASK_STACK_COMMON_PLUS;

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
#ifdef __UMTS_RAT__
const kal_uint32 cfg_3G_FSM = 1;
#else
const kal_uint32 cfg_3G_FSM = 0;
#endif

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const kal_uint32 cfg_task_info_g_size = sizeof(task_info_struct);

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const kal_uint32 cfg_task_cb_size = sizeof ( kal_task_type );

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const kal_uint32 cfg_hisr_cb_size = sizeof ( kal_hisr_type );

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const kal_uint32 cfg_ext_queue_head = sizeof(kal_queue_type);

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const kal_uint32 cfg_ilm_struct = sizeof(ilm_struct);

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const kal_uint32 cfg_max_custom_tasks = MAX_CUSTOM_TASKS;

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
#if defined(DEBUG_KAL) && defined(DEBUG_ITC)
const kal_uint32 cfg_kal_queue_stat_type = sizeof(struct kal_int_queue_statistics_struct);
#else
const kal_uint32 cfg_kal_queue_stat_type = 0;
#endif

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const kal_uint32 cfg_no_create_task = TASK_NO_CREATE_PATTERN;

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const kal_uint32 cfg_ctrl_buff_overhead = KAL_TOTAL_BUFF_OVERHEAD;

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const kal_uint32 cfg_pool_cb_size = sizeof (struct kal_int_pool_struct);

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
#if defined(DEBUG_KAL) && (defined(DEBUG_BUF2) || defined(DEBUG_BUF1))
const kal_uint32 cfg_pool_stat_size = sizeof (struct kal_int_pool_statistics_struct);
#else
const kal_uint32 cfg_pool_stat_size = 0;
#endif

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
#if defined(DEBUG_BUF3) && defined(__MTK_TARGET__)
const kal_uint32 cfg_int_buff_callstack = sizeof (struct kal_int_buff_callstack);
#else
const kal_uint32 cfg_int_buff_callstack = 0;
#endif 


#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
#ifdef KAL_ON_NUCLEUS 
const kal_uint32 cfg_nu_buff_overhead = KAL_NU_BUFF_OVERHEAD;
#else
const kal_uint32 cfg_nu_buff_overhead = KAL_OSC_BUFF_OVERHEAD;
#endif

#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const kal_uint32 cfg_normal_mode = NORMAL_M;
const kal_uint32 cfg_factory_mode = FACTORY_M;
const kal_uint32 cfg_usb_mode = USB_M;

#if defined(DEBUG_KAL) && defined(DEBUG_BUF2)
#ifdef KAL_ON_OSCAR
/*Visual C++ have different alignment assumption from RVCT*/
const kal_uint32 cfg_buff_stat = sizeof(struct kal_int_buff_stats) + 20;
#else
#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const kal_uint32 cfg_buff_stat = sizeof(struct kal_int_buff_stats);
#endif
#else
#ifdef __MTK_TARGET__
__attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) 
#endif /* __MTK_TARGET__ */
const kal_uint32 cfg_buff_stat = 4;
#endif
