/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contain definition of custom component module configuration variables, and routines
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"
#include "kal_internal_def.h"
#include "task_config.h"
#include "kal_user_mem.h"

/*************************************************************************
* FUNCTION
*  custom_configmem()
*
* DESCRIPTION
*   This routine configure 
*        
*   a. system total memory usage 
*      Task's stack, external queue, control buffer entries etc.
*      Any one who attempts to create new task or enlarge control
*      buffer size should fine tune the value!
*
*   b. system total debug memory usage 
*      Valid for DEBUG_KAL + DEBUG_[some items, ITC, BUF etc] 
*
* PARAMETERS
*        system_mem_sz       -        system all memory usage
*        debug_mem_sz        -        system all debug memory usage
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
    #include "sys_mem_size.h"
#else
    #include "sys_mem_size_modis.h"
#endif /*__MTK_TARGET__*/

#if defined(__KTEST__)
    #include "ktest_common.h"
#endif
/*Debug mem pool before sys mem for easy debug in case sys mem overflow*/

#if defined(DEBUG_KAL)
static kal_uint32 Debug_Mem_Pool[(GLOBAL_DEBUG_MEM_SIZE 
#if defined(__KTEST__)
+KTEST_DBG_MEM_FOR_DBG 
#endif
)/sizeof(kal_uint32)];
#endif /* DEBUG_KAL */

static kal_uint32 System_Mem_Pool[(GLOBAL_MEM_SIZE + CUSTOM_CFG_GLOBAL_MEM_SIZE_IN_BYTES 
#if defined(__KTEST__)
+KTEST_SYS_MEM_FOR_TASK
#endif
#if defined(ATEST_ENABLE)
+(10*1024)
#endif
) / sizeof(kal_uint32)];


void
custom_configmem(kal_uint32 *system_mem_sz, kal_uint32** system_mem_addr, 
                 kal_uint32 *debug_mem_sz,  kal_uint32** debug_mem_addr)
{
   *system_mem_sz   = sizeof(System_Mem_Pool);
   *system_mem_addr = System_Mem_Pool;
   
#if defined(DEBUG_KAL)   
   *debug_mem_addr  = Debug_Mem_Pool;
   *debug_mem_sz    = sizeof(Debug_Mem_Pool);
#else
   *debug_mem_addr  = (kal_uint32 *)0;
   *debug_mem_sz    = 0;
#endif
}

/*************************************************************************
* FUNCTION
*  custom_config_libc_heap()
*
* DESCRIPTION
*   This routine configure libc heap size & location.
*
* PARAMETERS
*
* RETURNS
*  heap size & heap location. if heap_size return 0, then no heap is
*  initialized.
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef __GADGET_SUPPORT__
#define GLOBAL_LIBC_HEAP_SIZE 10240
#else 
#define GLOBAL_LIBC_HEAP_SIZE 0
#endif
#if GLOBAL_LIBC_HEAP_SIZE != 0
/* if we don't define heap, we won't define a symbol call System_Libc_Heap
 * using this method, we can detect whether system allow to use 
 * malloc/free/realloc/calloc
 */
kal_uint32 System_Libc_Heap[GLOBAL_LIBC_HEAP_SIZE/sizeof(kal_uint32)];
#endif
void custom_config_libc_heap(kal_uint32 *heap_size, void **heap_addr)
{
#if GLOBAL_LIBC_HEAP_SIZE == 0
    *heap_size = 0;
    *heap_addr = 0;
#else
    *heap_size = sizeof(System_Libc_Heap);
    *heap_addr = System_Libc_Heap;
#endif
}

#if defined(__EUTEST_ENABLE__)
kal_bool
_is_skip_remap(kal_uint32 module_id)
{
    kal_uint32 i;
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
#define task_module_map(task, mod) task,
#define compatible_code(p1)
#define MODULE_ID_MAP_TO_NULL_TASK_CAN_ALLOCATE_ILM(p1)
#define MODULE_ID_FOR_PRINT_TRACE(p1)
#define task_name(p1)        
#define task_queue_name(p1)  
#define task_priority(p1, p2)
#define task_stack_size(p1) 
#define null_task_create_entry(p1) 
#define task_create_function(p1)  
#define task_stack_internalRAM(p1)
#define task_external_queue_size(p1) 
#define task_internal_queue_size(p1) 
#define task_boot_mode(p1) 
    kal_uint32 skip_task_id[] =
    {
#include "middleWare_task_config.h"
#include "srv_task_config.h"
    };

    kal_uint32 non_skip_task_id[] =
    {
      INDX_NIL,
      INDX_IPCORE,
    };

    /* check non skip first, because skip will contain non skip task */
    for (i = 0; i < sizeof(non_skip_task_id)/sizeof(kal_uint32); i++) {
       if (mod_task_g[module_id] == non_skip_task_id[i]) {
           return KAL_FALSE;
       }
    }

    for (i = 0; i < sizeof(skip_task_id)/sizeof(kal_uint32); i++) {
       if (mod_task_g[module_id] == skip_task_id[i]) {
           return KAL_TRUE;
       }
    }

    return KAL_FALSE;
}
#endif/*__EUTEST_ENABLE__*/


/*************************************************************************
* FUNCTION
*  remap_mod_task_g
*
* DESCRIPTION
*  This function will remap module to new task at initialization stage.
*  Original configuration in config.lib will be overwritten.
*  XXX PLEASE DON'T EDIT THE FUNCTION.
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  mod_task_g
*
*************************************************************************/
void remap_mod_task_g(void)
{
#ifdef __EUTEST_ENABLE__
   kal_uint32 module_id;
#endif

#if defined(__EL1_IT__) && !defined(__EL1_EL2_ERRC_IT__)
#if defined(__EL1_EMAC_IT__)
    mod_task_g[remap_module_id(MOD_ERRC)] = mod_task_g[remap_module_id(MOD_EL1IT)];//INDX_EL1IT;
#else /* __EL1_EMAC_IT__ */
#ifndef __ESL_COSIM_LTE_L2__
    mod_task_g[remap_module_id(MOD_EMAC)] = mod_task_g[remap_module_id(MOD_EL1IT)];//INDX_EL1IT;
    mod_task_g[remap_module_id(MOD_EL1TX)] = mod_task_g[remap_module_id(MOD_EL1IT)];//INDX_EL1IT;
    mod_task_g[remap_module_id(MOD_ERRC)] = mod_task_g[remap_module_id(MOD_EL1IT)];//INDX_EL1IT;
#endif
#if defined(__UMTS_RAT__)
    mod_task_g[remap_module_id(MOD_UL1)] = mod_task_g[remap_module_id(MOD_EL1IT)];//INDX_EL1IT;
#endif
#if defined(__GSM_RAT__)
    mod_task_g[remap_module_id(MOD_L1)] = mod_task_g[remap_module_id(MOD_EL1IT)];//INDX_EL1IT;
#endif        
#endif /* __EL1_EMAC_IT__ */
#endif /* __EL1_IT__ && !__EL1_EL2_ERRC_IT__ */

#if defined(__EL1TX_IT__)
    mod_task_g[remap_module_id(MOD_LTE)] = mod_task_g[remap_module_id(MOD_EL1TX_IT)];//INDX_EL1TX_IT;
    mod_task_g[remap_module_id(MOD_EL1)] = mod_task_g[remap_module_id(MOD_EL1TX_IT)];//INDX_EL1TX_IT;
    mod_task_g[remap_module_id(MOD_ERRC)] = mod_task_g[remap_module_id(MOD_EL1TX_IT)];//INDX_EL1TX_IT;
#if defined(_LENB_SIM_ENBL_)
    mod_task_g[remap_module_id(MOD_ERLCUL)] = mod_task_g[remap_module_id(MOD_EL1TX_IT)];//INDX_EL1TX_IT;
    mod_task_g[remap_module_id(MOD_SIMENB)] = mod_task_g[remap_module_id(MOD_EL1TX_IT)];//INDX_EL1TX_IT;
#endif /* _LENB_SIM_ENBL_ */

#endif /* __EL1TX_IT__ */

#if defined(__L2TPS_TEST__)
    /* EL2IT task will simulate following modules for testing purpose */
    mod_task_g[remap_module_id(MOD_LTM)]    = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_ERRC)]   = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;

    /* for LTM configuration */
    mod_task_g[remap_module_id(MOD_ESM)]    = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
		/* Discard AT command */
    mod_task_g[remap_module_id(MOD_ATCI)]    = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_EMM)]    = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;

#endif

#if defined(__EL2_IT__) || defined(__EL2_FPGA_IT__)

#if defined(__L2TPS_TEST__)
    /* EL2IT task will simulate following modules for testing purpose */
//    mod_task_g[remap_module_id(MOD_LTM)]    = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
//    mod_task_g[remap_module_id(MOD_ERRC)]   = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;

    /* for LTM configuration */
//    mod_task_g[remap_module_id(MOD_ESM)]    = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
#else  /* __L2TPS_TEST__ */

#if   (TEST_MODE == TEST_MODE_EL2_IT)
    /* EL2IT task will simulate following modules for testing purpose */
#if !defined(__EDATA_PATH_IT__)
    mod_task_g[remap_module_id(MOD_LTM)]    = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
#endif /* !__EDATA_PATH_IT__ */
    mod_task_g[remap_module_id(MOD_EL1)]    = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_EL1TX)]  = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_ERRC)]   = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;

    /* for LTM configuration */
    mod_task_g[remap_module_id(MOD_ESM)]    = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;

#elif (TEST_MODE == TEST_MODE_EMAC_IT)
    mod_task_g[remap_module_id(MOD_ERRC)]   = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_ERLCUL)] = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_ERLCDL)] = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_EL1)]    = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_EL1TX)]  = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_LTM)]    = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
#elif (TEST_MODE == TEST_MODE_ERLC_IT)
    mod_task_g[remap_module_id(MOD_ERRC)]   = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_EMAC)]   = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_EPDCP)]  = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
#elif (TEST_MODE == TEST_MODE_EPDCP_IT)
    mod_task_g[remap_module_id(MOD_ERRC)]   = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_ERLCUL)] = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_LTM)]    = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_EMAC)]   = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
    mod_task_g[remap_module_id(MOD_EL1TX)]  = mod_task_g[remap_module_id(MOD_EL2IT)];//INDX_EL2_IT;
#endif

#endif /* __L2TPS_TEST__ */

#endif /* __EL2_IT__ || __EL2_FPGA_IT__ || __L2TPS_TEST__ */

#ifdef __EUTEST_ENABLE__
   for(module_id = 0; module_id < RPS_TOTAL_STACK_MODULES; module_id++)
   {
       if(_is_skip_remap(module_id)) {
           continue;
       }
       mod_task_g[module_id] = mod_task_g[remap_module_id(MOD_DUMMY_EUTEST)];//MAUI_12345678
   }
#endif

#ifdef __LTM_EPDCP_SIMULATION_SUPPORT__
    mod_task_g[remap_module_id(MOD_EPDCP)]  = mod_task_g[remap_module_id(MOD_DUMMY_IPCORE)];
#endif

#if defined(__EDYN_ENABLE__)
    if (kal_query_boot_mode() == FACTORY_BOOT) {
        mod_task_g[remap_module_id(MOD_EL1)]   = mod_task_g[remap_module_id(MOD_DUMMY_ETSTM)];
    }
#endif/*__EDYN_ENABLE__*/

#ifdef __ESL_COSIM_LTE_L2__
    mod_task_g[remap_module_id(MOD_ERRC)] = mod_task_g[remap_module_id(MOD_EL2IT)];
#endif

#if 0                    //[MAUI_12345678]
#if defined(OBIGO_Q05A)
/* under construction !*/
#endif
#ifndef OBIGO_Q03C_MMS_V02
/* under construction !*/
#endif
/* under construction !*/
#endif     //MAUI_12345678
}

