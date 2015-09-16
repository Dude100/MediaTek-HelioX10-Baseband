#ifndef _USBCORE_COSIM_H
#define _USBCORE_COSIM_H

#include "hif_usb.h"
#include "usbcore_main.h"
#include "usbcore_hif.h"
#include "dhl_trace.h"

#define USBC_ESL_DEBUG  0

#if USBC_ESL_DEBUG
    #define usbc_esl_printf(...) hsl_printf(__VA_ARGS__)
#else
    #define usbc_esl_printf(...) 
#endif

/*!
 *  @brief usbcore initial for ESL COSIM
 */
kal_bool usbc_cosim_core_task_init(void);

/*!
 * @brief usbcore main function for ESL COSIM
 */
void usbc_cosim_core_task_main(task_entry_struct*);

#endif  // _USBCORE_HIF_H
