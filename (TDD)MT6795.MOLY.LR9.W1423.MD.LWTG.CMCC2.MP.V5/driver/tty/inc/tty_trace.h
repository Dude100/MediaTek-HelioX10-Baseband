#ifndef _TTY_TRACE_H_
#define _TTY_TRACE_H_


#if TTY_CONSOLE_TRACE_ENABLED != 1

#ifndef GEN_FOR_PC
 #include "stack_config.h"
#endif /* GEN_FOR_PC */

#include "dhl_trace.h"
#include "dhl_def.h"

#if !defined(GEN_FOR_PC)
#if defined(__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "tty_trace_gen.h"
#endif /* TST Trace Defintion */
#endif

#endif /* TTY_CONSOLE_TRACE_ENABLED != 1 */

BEGIN_TRACE_MAP(MOD_TTY)
   TRC_MSG(TTY_TR_CTRL, "[TTY] DclSerialPort_Control, cmd: %d ")
   TRC_MSG(TTY_TR_DEV_NOT_EXIST, "[TTY] Device doesn't exist ")
   TRC_MSG(TTY_TR_INVALID_HANDLE, "[TTY] Invalid handle!")
   TRC_MSG(TTY_TR_CONV_INIT, "[TTY] Conventional module init ")
   TRC_MSG(TTY_TR_NEW_INIT, "[TTY] New module init, module id: %d,  port: %d ")
   TRC_MSG(TTY_TR_REINIT, "[TTY] re-init, new module id: %d ")
   TRC_MSG(TTY_TR_DEINIT, "[TTY] de-init, port: %d ")
   TRC_MSG(TTY_TR_DRV_ATTACH, "[TTY] Driver attach, port: %d")
   TRC_MSG(TTY_TR_DRV_DETACH, "[TTY] Driver detach, port: %d")
   TRC_MSG(TTY_TR_DRV_REGISTER_CB, "[TTY] Driver register callback function (uart handler), port: %d")
   TRC_MSG(TTY_TR_DRV_CB_IS_NULL, "[TTY] Driver serial port %d callback handler is NULL!!")
   TRC_MSG(TTY_TR_NEW_RX_CB_IS_NULL, "[TTY] Rx use new path but doesn't register callback!!")
   TRC_MSG(TTY_TR_GPD_EXHAUST, "[TTY]   GPD is exhausted!!")
   TRC_MSG(TTY_TR_RX_GPD_IS_NULL, "[TTY] Rx GPD is NULL!!")
   TRC_MSG(TTY_TR_TX_IOR_IS_NULL, "[TTY] Tx IOR is NULL!!")
   TRC_MSG(TTY_TR_CMD_ERR_ASSIGN_RX_IOR, "[TTY] Command error!! command: assign rx ior")
   TRC_MSG(TTY_TR_CMD_ERR_PUT_BYTES_IOR, "[TTY] Command error!! command: put bytes ior")
   TRC_MSG(TTY_TR_CMD_ERR_NEED_TX_DONE_CB, "[TTY] Command error!! command: need tx done cb")
   TRC_MSG(TTY_TR_CMD_ERR_GET_CHUNK_SIZE, "[TTY] Command error!! command: get chunk size")
   TRC_MSG(TTY_TR_CMD_ERR_CLR_TX_BUF, "[TTY] Command error!! command: clear tx buffer")
   TRC_MSG(TTY_TR_CMD_ERR_CLR_RX_BUF, "[TTY] Command error!! command: clear rx buffer")
   TRC_MSG(TTY_TR_CMD_REG_CB_FAIL, "[TTY] Register callback failed")
   TRC_MSG(TTY_TR_DRV_DEREGISTER_CB, "[TTY] Driver de-register callback function (uart handler)")
   TRC_MSG(TTY_TR_CMD_CONV_TX, "[TTY] Command conventional putbytes, length: %d, port: %d")
   TRC_MSG(TTY_TR_CMD_CONV_RX, "[TTY] Command conventional getbytes, length: %d, port: %d")
   TRC_MSG(TTY_TR_CMD_CONV_TX_NOT_RDY, "[TTY] Command conventional putbytes not ready, tx gpd current used: %d, port: %d")
   TRC_MSG(TTY_TR_CMD_DCL_CONTROL, "[TTY] DclSerialPort_Control in, command: %d, port: %d")
   TRC_MSG(TTY_TR_WRONG_STATE, "[TTY] Wrong state, driver not attached or flush operation not finished")
   TRC_MSG(TTY_TR_CMD_CONV_RX_NOT_RDY, "[TTY] Command conventional getbytes not ready, no available data, port: %d")
   TRC_MSG(TTY_TR_CMD_REG_CB, "[TTY] Register user callback, port: %d")
   TRC_MSG(TTY_TR_CMD_ASSIGN_RX_IOR, "[TTY] Command assign RX ior, port: %d")
   TRC_MSG(TTY_TR_DRV_RX_ALLOW_LEN, "[TTY] RX_ALLOW_LEN: %d, port: %d")
END_TRACE_MAP(MOD_TTY)

#endif /* _TTY_TRACE_H_ */

