#ifndef __INC_HIF_TRACE_H
#define __INC_HIF_TRACE_H

/*
 *  Purpose:
 *      Allow DHL index trace like message can be shown in console.
 *
 *  Limitation:
 *      1. Not support string and floating point format specifiers.
 *
 *  Usage:
 *      step 1. Define HIF_CONSOLE_TRACE_ENABLED to 1 if you want to print
 *              dhl_trace() message to console, otherwise, define it to 0
 *
 *      step 2. Write your own trace message header file and use the 
 *              compiler flag HIF_CONSOLE_TRACE_ENABLED to prevent including 
 *              DHL realted header files.
 *              
 *      step 3. Include hif_trace.h and your trace message header file.
 *              Please note that, except for the trace message header file, 
 *              you are also required to follow follow DHL logging API user 
 *              guide to use DHL logging facilities.
 *
 *      step 4. Use hif_trace_error() and hif_trace_info() to print 
 *              DHL indexed trace like message to console or ELT as you 
 *              specified in step 1.
 *
 *  Example:
 *      Assume your module ID is MOD_XXX and the file and function prefix is xxx.
 *
 *      In xxx_trace.h
 *
 *          #if HIF_CONSOLE_TRACE_ENABLED != 1
 *              #ifndef GEN_FOR_PC
 *                  #include "kal_public_defs.h"
 *              #endif
 *    
 *              #include "dhl_trace.h"
 *              #include "dhl_def.h"
 *    
 *              #if !defined(GEN_FOR_PC)
 *                  #if defined(__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
 *                       #include "rndis_trace_gen.h"
 *                  #endif
 *              #endif
 *          #endif
 *          BEGIN_TRACE_MAP(MOD_RNDIS)
 *              TRC_MSG(XXX_SHOW_CODE_MSG_INDEX, "[XXX] xxx_func() got code(%d)")
 *              TRC_MSG(XXX_ERROR_MSG_INDEX, "[XXX] xxx_func() failed!")
 *          END_TRACE_MAP(MOD_RNDIS)
 *
 *      In Option.mak:
 *
 *          COMP_TRACE_DEFS += YOUR_MODULE_PATH\include\xxx_trace.h
 * 
 *      In xxx_debug.h:
 *
 *          #define HIF_CONSOLE_TRACE_ENABLED 1
 *          #include "hif_trace.h"
 *          #include "xxx_trace.h"
 *
 *      In xxx_yyy.c:
 *
 *          #include "hif_debug.h"
 *
 *          void xxx_func(int code) {
 *             hif_trace_info(XXX_SHOW_CODE_MSG_INDEX, code);
 *             if (OK != code) {
 *                 hif_trace_error(XXX_ERROR_MSG_INDEX);
 *             }
 *          }
 */
#if HIF_CONSOLE_TRACE_ENABLED==1
    /*
     * Print indexed trace to console.
     */
    #if defined(__MTK_TARGET__)
        #define hif_console_trace dbg_print
        #define HIF_NEW_LINE "\r\n"
    #else
        #define hif_console_trace kal_printf
        #define HIF_NEW_LINE "\n"
    #endif

    #if defined(__GNUC__)
        #define __UNUSED_ATTR__ __attribute__  ((unused))  
    #else
        #define __UNUSED_ATTR__ 
    #endif

    #define hif_trace_error(...) hif_console_trace(__VA_ARGS__)
    #define hif_trace_info(...) hif_console_trace(__VA_ARGS__)

    #if defined(BEGIN_TRACE_MAP) 
        #undef BEGIN_TRACE_MAP
    #endif
    #if defined(TRC_MSG) 
        #undef TRC_MSG
    #endif
    #if defined(END_TRACE_MAP) 
        #undef END_TRACE_MAP
    #endif
    #define BEGIN_TRACE_MAP(_mod)
    #define TRC_MSG(_msg_index, _fmt) static char _msg_index [] __UNUSED_ATTR__ = _fmt HIF_NEW_LINE;
    #define END_TRACE_MAP(_mod)
#else
    /*
     * Use DHL logging.
     */
    #define hif_trace_error(...) dhl_trace(TRACE_ERROR, DHL_USER_FLAG_NONE, __VA_ARGS__)
    #define hif_trace_info(...) dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, __VA_ARGS__)
#endif /* HIF_CONSOLE_TRACE_ENABLED */

#if HIF_DATA_TRACE_ENABLED==1

    #ifdef __MTK_TARGET__
    #define hif_data_trace(FUNC_NAME, ...)      do { FUNC_NAME ( __VA_ARGS__ ) ; } while (0)
#else
    /*
        *   (2013/08/20) Do to VC compiler bug in variadic macro replacement, it needs to divide Variadic macro into 2 parts to workaround.
        *                        http://connect.microsoft.com/VisualStudio/feedback/details/380090/variadic-macro-replacement
        */
    #define hif_data_trace_arg(FUNC_NAME, args_list)    do{ FUNC_NAME args_list ; } while (0)
    #define hif_data_trace(FUNC_NAME, ...)              do{ hif_data_trace_arg(FUNC_NAME, (__VA_ARGS__)); } while (0)
    #endif

#else
    #define hif_data_trace(FUNC_NAME, ...)
#endif

#endif /* __INC_HIF_TRACE_H */
