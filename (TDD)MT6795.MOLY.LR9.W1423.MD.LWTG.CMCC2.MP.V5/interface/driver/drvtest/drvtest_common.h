#ifndef __DRVTEST_COMMON_H__
#define __DRVTEST_COMMON_H__
#include "drv_comm.h"

/*****************************************************************************
 *						 SYMBOL Definition                                   *
 *****************************************************************************/
#define DRVTEST_FAILCODE  0xDEADBABE
#define DRVTEST_PASSCODE  0xBABEFACE

/*****************************************************************************
 *					(Macro) function declaration                             *
 *****************************************************************************/
extern void dbg_print(char *fmt,...);
#define DRVTEST_PRINT   dbg_print
extern void drvtest_fail(char *name);
extern void drvtest_pass(char *name);
extern volatile kal_uint32 drvtest_result;
extern kal_uint32 drvtest_SaveAndSetIRQMask(void);
extern void drvtest_RestoreIRQMask(kal_uint32 irq);
extern void drvtest_srand(kal_uint32 seed);
extern kal_uint32 drvtest_rand(void);


#endif /* end of __DRVTEST_COMMON_H__ */

