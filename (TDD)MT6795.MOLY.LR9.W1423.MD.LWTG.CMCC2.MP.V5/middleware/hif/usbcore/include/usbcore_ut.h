#include "kal_public_api.h"
#include "syscomp_config.h"
#include "usbcore_common.h"
#include "usbcore_usbstd.h"
#include "hif_common.h"
#include "hif_usb.h"
#include "usbcore_main.h"
#include "usbcore_class_device.h"

#define USBC_UT_FAKE_CLASS_CALLBACK 0

#define usbc_core_set_ss_dev_init_u1_en(...)
#define usbc_core_set_ss_dev_init_u2_en(...)
#define hifusb_ss_func_wk_notify usbc_ut_fake_notify_retry
#define hifusb_remote_wakeup  usbc_ut_fake_hif_remote_wakeup

#define USBC_UT_BLOCK_TICK_T    2

typedef kal_uint16 usbc_ut_fake_infx_status;

typedef struct usbc_ut_fake_class_func_info {
    usbc_ut_fake_infx_status    infx_status;
    kal_uint8                    nRetry;
} usbc_ut_fake_class_func_info_t;

kal_uint16 usbc_ut_fake_query_func_wk_status(kal_uint8 class_device_id);

void usbc_ut_fake_notify_func_wk_ability(kal_uint8 class_device_id, kal_bool ability);

kal_bool usbc_ut_fake_notify_retry(kal_uint8 nInterface);

kal_bool usbc_ut_fake_hif_remote_wakeup();

void usbc_ut_fake_set_control_request(kal_uint8 *buffer, kal_uint32 length, usbc_control_request_type_e type);
