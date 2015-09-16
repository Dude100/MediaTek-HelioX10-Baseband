#ifndef _USBCORE_TRACE_H_
#define _USBCORE_TRACE_H_

#if HIF_CONSOLE_TRACE_ENABLED != 1

#ifndef GEN_FOR_PC
 #include "stack_config.h"
#endif /* GEN_FOR_PC */

#include "dhl_trace.h"
#include "dhl_def.h"

#if !defined(GEN_FOR_PC)
#if defined(__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "usbcore_trace_gen.h"
#endif /* TST Trace Defintion */
#endif

#endif /* HIF_CONSOLE_TRACE_ENABLED != 1 */


BEGIN_TRACE_MAP(MOD_USBCORE)
   /* USB task initialization */
   TRC_MSG(USBCORE_TASK_INIT, "[USBCORE] usbcore task initialization")
   TRC_MSG(USBCORE_TASK_RESET, "[USBCORE] usbcore task reset")
   TRC_MSG(USBCORE_TASK_CREATE, "[USBCORE] usbcore task create")
   TRC_MSG(USBCORE_TASK_MAIN, "[USBCORE] usbcore task main")
   TRC_MSG(USBCORE_ALL_NODE_CHECKIN, "[USBCORE] all nodes have been checked in")
   TRC_MSG(USBCORE_ALL_NODE_CHECKIN_INIT_CLASS_START, "[USBCORE] start initialing classes after all nodes checked in: class type = %d")
   TRC_MSG(USBCORE_ALL_NODE_CHECKIN_INIT_CLASS_END, "[USBCORE] finish initialing classes after all nodes checked in: class type = %d")
   TRC_MSG(USBCORE_ALL_NODE_CHECKIN_REINIT_CLASS_START, "[USBCORE] start re-initialing classes after all nodes checked in: class index = %d")
   TRC_MSG(USBCORE_ALL_NODE_CHECKIN_REINIT_CLASS_END, "[USBCORE] finish re-initialing classes after all nodes checked in: class index = %d")

   /* USB standard requests */
   TRC_MSG(USBCORE_DISPATCH_REQUEST, "[USBCORE] usbcore dispatches requests: bmRequestType = 0x%x")
   TRC_MSG(USBCORE_SET_ADDRESS, "[USBCORE] usbcore handles set_address: addr = 0x%x")
   TRC_MSG(USBCORE_GET_STATUS, "[USBCORE] usbcore handles get_status: bRecip = 0x%x")
   TRC_MSG(USBCORE_SET_FEATURE, "[USBCORE] usbcore handles set_feature: bRecip = 0x%x, wIndex = 0x%x, wValue = 0x%x")
   TRC_MSG(USBCORE_CLEAR_FEATURE, "[USBCORE] usbcore handles clear_feature: bRecip = 0x%x, wIndex = 0x%x, wValue = 0x%x")
   TRC_MSG(USBCORE_GET_DESCRIPTOR, "[USBCORE] usbcore handles get_descriptor: bRecip = 0x%x, type = 0x%x")
   TRC_MSG(USBCORE_SET_CONFIG, "[USBCORE] usbcore handles set_configuration: wValue = 0x%x")
   TRC_MSG(USBCORE_GET_CONFIG, "[USBCORE] usbcore handles get_configuration: wValue = 0x%x")
   TRC_MSG(USBCORE_SET_INFX, "[USBCORE] usbcore handles set_interface: bInterface = 0x%x, wValue = 0x%x")
   TRC_MSG(USBCORE_GET_INFX, "[USBCORE] usbcore handles get_interface: bInterface = 0x%x")

   /* USB HIF state indications */
   TRC_MSG(USBCORE_HIF_EVENT_ATTACH, "[USBCORE] usbcore receives ATTACH events from HIF driver")
   TRC_MSG(USBCORE_HIF_EVENT_DETACH, "[USBCORE] usbcore receives DETACH events from HIF driver")
   TRC_MSG(USBCORE_HIF_EVENT_SUSPEND, "[USBCORE] usbcore receives SUSPEND events from HIF driver")
   TRC_MSG(USBCORE_HIF_EVENT_RESUME, "[USBCORE] usbcore receives RESUME events from HIF driver")
   TRC_MSG(USBCORE_HIF_EVENT_RESET, "[USBCORE] usbcore receives RESET events from HIF driver")
   TRC_MSG(USBCORE_HIF_EVENT_SPEED_CHANGE, "[USBCORE] usbcore changes speed in HIF driver reset: original speed 0x%x to new speed 0x%x")
   TRC_MSG(USBCORE_HIF_EVENT_UNKNOWN, "[USBCORE] usbcore receives unknown events from HIF driver")

   /* USB HIF set configuration*/
   TRC_MSG(USBCORE_HIF_SET_CONFIG, "[USBCORE] usbcore is setting config: %d")
   TRC_MSG(USBCORE_HIF_SET_CONFIG_UNCHANGED, "[USBCORE] usbcore doesn't set config (config unchaged)")
   TRC_MSG(USBCORE_HIF_SET_CONFIG_REINIT_START, "[USBCORE] usbcore starts usbclass reinit in HIF SET CONF")
   TRC_MSG(USBCORE_HIF_SET_CONFIG_REINIT_END, "[USBCORE] usbcore finishes usbclass reinit in HIF SET CONF")
   TRC_MSG(USBCORE_HIF_SET_CONFIG_USBCLASS, "[USBCORE] usbcore calls set config callback usbclass type %d")
   TRC_MSG(USBCORE_HIF_SET_CONFIG_HIF, "[USBCORE] usbcore calls HIF driver to set config: %d")
   TRC_MSG(USBCORE_HIF_SET_CONFIG_ADDR_STATE, "[USBCORE] usbcore goes to address state after setting config")
   TRC_MSG(USBCORE_HIF_SET_CONFIG_CONF_STATE, "[USBCORE] usbcore goes to configuration state after setting config")
   TRC_MSG(USBCORE_CONF_INVALID, "[USBCORE] usbcore receives an invalid configuration: %d")

   /* USB remote wakeup related info*/
   TRC_MSG(USBCORE_REMOTE_WK_START, "[USBCORE] usb class id %d starts calling function remote wk")
   TRC_MSG(USBCORE_REMOTE_WK_INVALID, "[USBCORE] the class id %d doesn't enable function remote wk: status 0x%x")
   TRC_MSG(USBCORE_REMOTE_WK_DEVICE, "[USBCORE] the class id %d asks the USB device to remote wakeup")
   TRC_MSG(USBCORE_REMOTE_WK_DEVICE_WAIT, "[USBCORE] the class id %d waits for device resuming")
   TRC_MSG(USBCORE_REMOTE_WK_FUNC, "[USBCORE] the class id %d asks  USBCORE to wakeup its function")
   TRC_MSG(USBCORE_REMOTE_WK_SET_NOTIFY_TIMER, "[USBCORE] usbcore sets remote wk notify timer for the class id %d")
   TRC_MSG(USBCORE_REMOTE_WK_HIF_NOTIFY, "[USBCORE] usbcore asks HIF driver to send wk notification for interface %d")

   /* USB notification to class devices*/
   TRC_MSG(USBCORE_NOTIFY_CLASS_START, "[USBCORE] usbcore calls usbclass's notify state: class type = %d, state = %d")
   TRC_MSG(USBCORE_NOTIFY_CLASS_END, "[USBCORE] usbcore finishs usbclass's notify state: class type = %d, state = %d")
   TRC_MSG(USBCORE_NOTIFY_WK_ABILITY_START, "[USBCORE] usbcore starts notifing wk ability to usbclass: class type = %d")
   TRC_MSG(USBCORE_NOTIFY_WK_ABILITY_END, "[USBCORE] usbcore finishs notifing wk ability to usbclass: class type = %d")
   TRC_MSG(USBCORE_NOTIFY_WK_ABILITY_INVALID, "[USBCORE] invalid notifing wk ability to usbclass: class type = %d")

   /* USB power saving */
   TRC_MSG(USBCORE_DEV_SUSPEND_CLOCK, "[USBCORE] usbcore sets clock gating = %d, notifies usbidle = %d")
   TRC_MSG(USBCORE_DEV_SUSPEND_L4, "[USBCORE] usbcore sets l4 power saving = %d, notifies ILM = %d, suspend = %d, remote wk =%d")
   TRC_MSG(USBCORE_SUSPEND_STOP_POLL, "[USBCORE] usbcore stop polling GPDs")
   TRC_MSG(USBCORE_SUSPEND_START_POLL, "[USBCORE] usbcore start polling GPDs")
   TRC_MSG(USBCORE_RESTORE_BFF_GPD, "[USBCORE] usbcore restore buffered GPDs in queue %d")
   TRC_MSG(USBCORE_FLUSH_BFF_GPD, "[USBCORE] usbcore flushes buffered GPDs in queue %d")
   TRC_MSG(USBCORE_UPDATE_API_BUFF_GPD, "[USBCORE] usbcore updates API for buffering GPDs: %d")

END_TRACE_MAP(MOD_USBCORE)

#endif /* _USBCORE_TRACE_H_ */

