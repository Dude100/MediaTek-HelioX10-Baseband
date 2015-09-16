#ifndef _USBCORE_DEBUG_H
#define _USBCORE_DEBUG_H

#define HIF_DATA_TRACE_ENABLED          1
#define USBCORE_CONSOLE_TRACE_ENABLED   0

#include "hif_trace.h"
#include "TrcMod.h"

extern kal_bool INT_QueryExceptionStatus(void);
extern void dbg_print(char *fmt,...);


#if USBCORE_CONSOLE_TRACE_ENABLED
    /*
     * Print indexed trace to console.
     */
    #if defined(__MTK_TARGET__)
        #define usbc_console_print  dbg_print
    #else
        #define usbc_console_print
    #endif

    #define usbc_trace_error(...)   usbc_console_print(__VA_ARGS__)
    #define usbc_trace_warn(...)    usbc_console_print(__VA_ARGS__)
    #define usbc_trace_info(...)    usbc_console_print(__VA_ARGS__)
    #define usbc_data_trace    hif_data_trace
#else    

    /*
     * Use DHL logging.
     */
    #define usbc_trace_error(...)                                          \
        do{                                                               \
            if(INT_QueryExceptionStatus() == KAL_FALSE)                   \
            {                                                             \
                dhl_trace(TRACE_ERROR, DHL_USER_FLAG_NONE, __VA_ARGS__);  \
            }                                                             \
        }while(0)

    #define usbc_trace_warn(...)                                            \
        do{                                                                \
            if(INT_QueryExceptionStatus() == KAL_FALSE)                    \
            {                                                              \
                dhl_trace(TRACE_ERROR, DHL_USER_FLAG_NONE, __VA_ARGS__);   \
            }                                                              \
        }while(0)

    #define usbc_trace_info(...)                                           \
        do{                                                               \
            if(INT_QueryExceptionStatus() == KAL_FALSE)                   \
            {                                                             \
                dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, __VA_ARGS__);   \
            }                                                             \
        }while(0)

    #define usbc_trace_func(...)                                           \
        do{                                                               \
            if(INT_QueryExceptionStatus() == KAL_FALSE)                   \
            {                                                             \
                dhl_trace(TRACE_FUNC, DHL_USER_FLAG_NONE, __VA_ARGS__);   \
            }                                                             \
        }while(0)

    #define usbc_data_trace    hif_data_trace
#endif /* USBCORE_CONSOLE_TRACE_ENABLED */


#include "usbcore_trace.h"
#include "dhl_trace.h"

#endif  /* _USBCORE_DEBUG_H */

