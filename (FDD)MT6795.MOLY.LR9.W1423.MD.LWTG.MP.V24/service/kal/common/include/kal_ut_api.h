#ifndef _KAL_UT_API_H
#define _KAL_UT_API_H

#include "kal_general_types.h"

#ifdef __MTK_TARGET__

#define kal_ut_store_sp()
#define kal_ut_restore_sp()

#else

#define kal_ut_store_sp() \
do{ \
	kal_int32 ut_sp; \
	{ \
		__asm mov ut_sp, esp  \
	} \
	kal_ut_set_sp_var(ut_sp); \
}while(0)

#define kal_ut_restore_sp() \
do{ \
	kal_int32 ut_sp; \
	ut_sp = kal_ut_get_sp_var(); \
	{ \
		__asm mov esp, ut_sp  \
	} \
}while(0)

#endif

/*************************************************************************
 * Type Definitions
 *************************************************************************/
typedef void (*kal_ut_assert_user_handler_fp)(kal_char *file, kal_uint32 line);

/*************************************************************************
 * Exported Function Prototypes
 *************************************************************************/

/*******************************************************************************
 * <GROUP Functions>
 * 
 * FUNCTION
 *  kal_ut_register_assert_user_handler
 * DESCRIPTION
 *  Register user assert handler
 * PARAMETERS
 *  user_fp: [IN] the function pointer of user handler.
 * RETURNS
 *  N/A
 * NOTE
 *  This API only used for unit test environment. The kal assert handler will 
 *  call the resitered user handler, and the user handler should not return.
 ******************************************************************************/
extern void kal_ut_register_assert_user_handler(kal_ut_assert_user_handler_fp user_fp);


/*************************************************************************
 * Internal Function Prototypes
 *************************************************************************/
extern void kal_ut_run_assert_user_handler(kal_char *file, kal_uint32 line);
extern void kal_ut_set_sp_var(kal_int32 sp);
extern kal_int32 kal_ut_get_sp_var();

#endif
