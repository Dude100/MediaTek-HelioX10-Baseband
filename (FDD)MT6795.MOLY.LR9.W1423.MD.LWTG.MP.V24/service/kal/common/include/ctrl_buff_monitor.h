#ifndef __CTRL_BUFF_MONITOR_H__
#define __CTRL_BUFF_MONITOR_H__

#include "kal_public_api.h"

#if defined(DEBUG_KAL) && defined(DEBUG_BUF2) && defined(DEBUG_CBAM_GLOBAL)
#include "bsd_list.h"                   /* list type */

/* CBAM = Control Buffer Allocated Monitor */
#define CBAM_LIST_SIZE  (NUM_CTRL_BUFF_POOL_SIZE32 + \
                         NUM_CTRL_BUFF_POOL_SIZE64 + \
                         NUM_CTRL_BUFF_POOL_SIZE128 + \
                         NUM_CTRL_BUFF_POOL_SIZE256 + \
                         NUM_CTRL_BUFF_POOL_SIZE512 + \
                         NUM_CTRL_BUFF_POOL_SIZE1024 + \
                         NUM_CTRL_BUFF_POOL_SIZE2048 + \
                         NUM_CTRL_BUFF_POOL_SIZE4096 + \
                         NUM_CTRL_BUFF_POOL_SIZE8192 + \
                         NUM_CTRL_BUFF_POOL_SIZE16384 + \
                         NUM_CTRL_BUFF_POOL_SIZE32768 + \
                         NUM_CTRL_BUFF_POOL_SIZE65536 + \
                         NUM_CTRL_BUFF_POOL_SIZE100000    )
                         

/*******************************************************************************
 * Defines for Ctrl Buffer Allocated Monitor
 *******************************************************************************/
struct ctrl_buff_alloc_entry {
        void *ptr;
        STAILQ_ENTRY(ctrl_buff_alloc_entry) entries;    /* Tail queue. */
        kal_bool used;
};

typedef struct{
    kal_uint32  buf_size;
    kal_uint32  line;
    const kal_char    *filename;
    module_type mod_id;
}ctrl_buff_info_struct;

extern struct ctrl_buf_alloc_head cbam_head;
extern struct ctrl_buff_alloc_entry cbam_list[];
extern kal_bool   cbam_global_enable;

STAILQ_HEAD(ctrl_buf_alloc_head, ctrl_buff_alloc_entry);

#define CBAM_GLOBAL_INSERT_BUFFER(h, b, l, p)                              \
	do{                                                                    \
		if(KAL_TRUE == cbam_global_enable)                                 \
		{                                                                  \
			CBAM_INSERT_BUFFER(h, b, l, p);                                \
		}                                                                  \
	}while(0)
	
#define CBAM_GLOBAL_REMOVE_BUFFER(h, b)                                    \
	do{                                                                    \
		if(KAL_TRUE == cbam_global_enable)                                 \
		{                                                                  \
            CBAM_REMOVE_BUFFER(h, b);                                      \
		}																   \
	}while(0)

#define CBAM_GLOBAL_DEFINED(def_expr, undef_expr) def_expr


/*************************************************************************
* FUNCTION
*  ctrl_buff_force_reset_and_free
*
* DESCRIPTION
*  reset the CBAM list, free all buffer in the lhead
*
* PARAMETERS
*  lhead  -  control buffer allocated monitor list head
*
* RETURNS
*  KAL_SUCCESS      - all operations are success
*  KAL_NOT_PRESENT  - do nothing if DEBUG_CBAM_GLOBAL is not defined and 
*                     NULL == lhead
*
* GLOBALS AFFECTED
*
*************************************************************************/
extern kal_status ctrl_buff_force_reset_and_free(struct ctrl_buf_alloc_head *lhead, kal_uint32 *free_count);

/*************************************************************************
* FUNCTION
*  ctrl_buff_monlist_pop
*
* DESCRIPTION
*  get the current allocated control buffer information(potential memory leak)
*  the popped buffer will be freed in this function
*
* PARAMETERS
*  lhead  -  control buffer allocated monitor list head
*  cbis   -  control buffer allocated buffer's information
*
* RETURNS
*  KAL_NOT_PRESENT  - this function is not available (not correct debug level)
*  KAL_NULL_ADDRESS - allocated list is empty
*  KAL_SUCCESS      - all operations are success
*
* GLOBALS AFFECTED
*
*************************************************************************/
extern kal_status ctrl_buff_monlist_pop(struct ctrl_buf_alloc_head *lhead, ctrl_buff_info_struct *cbis);

/*************************************************************************
* FUNCTION
*  ctrl_buff_global_allocated_mon_enb
*
* DESCRIPTION
*  enable the global allocated buffer monitor
*
* PARAMETERS
*  enable  -  enable or disable the global monitor
*
* RETURNS
*  KAL_NOT_PRESENT  - this function is not available (not correct debug level)
*  KAL_SUCCESS      - all operations are success
*
* GLOBALS AFFECTED
*
*************************************************************************/
extern kal_status ctrl_buff_global_allocated_mon_enb(kal_bool enable);

/*************************************************************************
* FUNCTION
*  ctrl_buff_get_alloc_entry
*
* DESCRIPTION
*  find the available CBAM entry from entry_pool
*
* PARAMETERS
*  entry_pool -  CBAM entry pool
*  max_num    -  maximal items in the entry_pool
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
extern struct ctrl_buff_alloc_entry* ctrl_buff_get_alloc_entry(
	struct ctrl_buff_alloc_entry *entry_pool, 
	kal_uint32 max_num);

/*************************************************************************
* FUNCTION
*  ctrl_buff_monlist_element_count
*
* DESCRIPTION
*  get the element number in the lhead
*
* PARAMETERS
*  lhead  -  control buffer allocated monitor list head
*
* RETURNS
*  KAL_SUCCESS      - all operations are success
*  KAL_NOT_PRESENT  - do nothing if DEBUG_CBAM_GLOBAL is not defined and 
*                     NULL == lhead
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
extern kal_status ctrl_buff_monlist_element_count(
	struct ctrl_buf_alloc_head *lhead, \
    kal_uint32 *count);


#define CBAM_INSERT_BUFFER(list_head, buff_ptr, list_pool, pool_count)\
    do{                                                                        \
          struct ctrl_buff_alloc_entry *tmp;                                   \
          kal_uint32 old_mask;                                                 \
                                                                               \
          tmp = ctrl_buff_get_alloc_entry((list_pool), (pool_count));          \
          tmp->ptr = buff_ptr;                                                 \
                                                                               \
          old_mask = SaveAndSetIRQMask();                                      \
          STAILQ_INSERT_TAIL(&(list_head), tmp, entries);                      \
          RestoreIRQMask(old_mask);                                            \
       }while(0)

#define CBAM_REMOVE_BUFFER(list_head, buff_ptr)                                \
    do{                                                                        \
        struct ctrl_buff_alloc_entry *entry_iter;                              \
        kal_uint32 old_mask;                                                   \
    	                                                                       \
        old_mask = SaveAndSetIRQMask();                                      \
    	STAILQ_FOREACH(entry_iter, &(list_head), entries)                      \
    	{                                                                      \
    		if(entry_iter->ptr == buff_ptr)                                    \
    		{                                                                  \
    			STAILQ_REMOVE(&(list_head), entry_iter, ctrl_buff_alloc_entry, entries);\
    			entry_iter->used = KAL_FALSE;                                  \
    			break;                                                         \
    		}		                                                           \
    	}                                                                      \
    	RestoreIRQMask(old_mask);                                              \
       }while(0)

#define CBAM_LIST_PREPARE_SIZE(n) (sizeof(struct ctrl_buff_alloc_entry)*(n))
#define CBAM_LISTHEAD_DECLARE(head) struct ctrl_buf_alloc_head head = STAILQ_HEAD_INITIALIZER(head)
#define CBAM_ENTRIES_DECLARE(lentries, n) struct ctrl_buff_alloc_entry lentries[(n)]

#else  /* else of "DEBUG_KAL && DEBUG_BUF2 && DEBUG_CBAM_GLOBAL" */
#define CBAM_INSERT_BUFFER(list_head, buff_ptr, list_pool, pool_count)
#define CBAM_REMOVE_BUFFER(list_head, buff_ptr)

#define CBAM_LIST_PREPARE_SIZE(n) (0)
#define CBAM_LISTHEAD_DECLARE(head)
#define CBAM_ENTRIES_DECLARE(lentries, n)
#define CBAM_GLOBAL_INSERT_BUFFER(h, b, l, p)
#define CBAM_GLOBAL_REMOVE_BUFFER(h, b)
#define CBAM_GLOBAL_DEFINED(def_expr, undef_expr) undef_expr

#endif /* end of "DEBUG_KAL && DEBUG_BUF2 && DEBUG_CBAM_GLOBAL" */


#endif /* end of __CTRL_BUFF_ALLOC_MONITOR_H__ */

