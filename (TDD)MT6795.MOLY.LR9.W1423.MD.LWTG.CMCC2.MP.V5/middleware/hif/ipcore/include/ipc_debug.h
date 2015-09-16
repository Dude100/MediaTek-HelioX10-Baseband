#ifndef __INC_IPC_DEBUG_H
#define __INC_IPC_DEBUG_H

#define HIF_DATA_TRACE_ENABLED          1

#if defined(__MTK_TARGET__)
    #define HIF_CONSOLE_TRACE_ENABLED   0
#else
    #define HIF_CONSOLE_TRACE_ENABLED   0
#endif

#include "hif_trace.h"
#include "ipc_trace.h"
#include "TrcMod.h"

#endif /* __INC_IPC_DEBUG_H */
