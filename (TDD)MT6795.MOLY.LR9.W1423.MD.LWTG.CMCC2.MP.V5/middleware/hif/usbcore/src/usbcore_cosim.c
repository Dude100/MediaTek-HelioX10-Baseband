#include "kal_public_api.h"
#include "syscomp_config.h"
#include "usbcore_common.h"
#include "hif_usb.h"
#include "usbcore_main.h"
#include "usbcore_ind_q.h"
#include "usbcore_hif.h"
#include "hifusb_qmu.h"
#include "usbcore_class_device.h"
#include "hif_ior.h"
#include "qmu_bm_util.h"
#include "qmu_bm.h"
#include "hmu.h"
#include "hmu_conf_data.h"
#include "sysservice_msgid.h"
#include "hif_mw_msgid.h"
#include "usbcore_cosim.h"

/************************************************
 * USBHIF driver APIs for ESL COSIM
 ************************************************/
static kal_bool usbc_cosim_hif_connect(void)
{
    /* emulate driver connection */
    usbc_core_notify_state_attaching();

    return KAL_TRUE;
}

static kal_bool usbc_cosim_hif_disconnect(void)
{
    usbc_core_notify_state_detaching();

    return KAL_TRUE;
}

/************************************************
 * USBCORE HIF APIs for ESL COSIM
 ************************************************/

static void usbc_cosim_hif_factory(void)
{
    USBC_NON_EXCEPTION_MODE_CHECK();

    usbc_esl_printf("Use DRVHIF ESL APIs...\n");
    usbc_core_set_property = hifusb_set_property_emulate;
    usbc_core_set_usbhif_address = hifusb_set_usb_address_emulate;
    usbc_core_set_usbhif_configuration = hifusb_set_usb_configuration_emulate;
    usbc_core_set_usbhif_connect = usbc_cosim_hif_connect;
    usbc_core_set_usbhif_disconnect = usbc_cosim_hif_disconnect;
}

static void usbc_cosim_hif_attach(void)
{
    usbc_core_t        *pUsbCore = usbc_core_get_instance();
    /* fake USB HW info for ESL COSIM */
    hifusb_boot_info_t usb_boot_info;
    hifusb_get_boot_info(&usb_boot_info);

    usbc_esl_printf("Emulare USB speed change and reset...\n");
    usbc_core_speed_change(pUsbCore, (usbc_usb_speed_e)usb_boot_info.usb_speed);    // emulate speed change notify
    usbc_core_notify_speed_change((usbc_usb_speed_e)usb_boot_info.usb_speed);
    usbc_core_set_hif_configuration();      // emulate reset notify
    usbc_core_notify_state_reset();

    usbc_esl_printf("Emulare HIF USB set address...\n");
    /* emulate SetAddress */
    usbc_core_set_usb_address(usb_boot_info.usb_addr & 0x7f);     // set USB address

    usbc_esl_printf("Emulare USB set configuration...\n");
    /* emulate SetConfig */
    usbc_core_set_usb_configuration(usb_boot_info.usb_config_val);   //set USB configuration, assume there is only one configuration in META mode
}


/************************************************
 * USBCORE task APIs for ESL COSIM
 ************************************************/

kal_bool usbc_cosim_core_task_init(void)
{
    usbc_core_t* pUsbCore;
    kal_char usbc_class_mutex_name[50];

#ifdef IPCORE_NOT_PRESENT
    hmu_boot_init();
#endif

    usbc_set_op_mode(USBC_OP_MODE_NORMAL);
    kal_mem_set(usbc_core_get_instance(), 0, sizeof(usbc_core_t));

    usbc_core_clear_register();
    usbc_core_clear_status();

    pUsbCore = usbc_core_get_instance();
    // create enhance mutex
    sprintf(usbc_class_mutex_name, "USBC_CLASS_REMOTE_WK_MUTEX");
    pUsbCore->usbc_class_remote_wk_mutex = kal_create_enh_mutex(usbc_class_mutex_name);
    sprintf(usbc_class_mutex_name, "USBC_CLASS_RENOTIFY_MUTEX");
    pUsbCore->usbc_class_renotify_mutex = kal_create_enh_mutex(usbc_class_mutex_name);
    sprintf(usbc_class_mutex_name, "USBC_CLASS_FUNC_ACCESS_MUTEX");
    pUsbCore->usbc_class_func_access_mutex = kal_create_enh_mutex(usbc_class_mutex_name);
    if ( NULL == pUsbCore->usbc_class_remote_wk_mutex ||
         NULL == pUsbCore->usbc_class_renotify_mutex ||
         NULL == pUsbCore->usbc_class_func_access_mutex )
    {
        ASSERT(0);
    }

    // initial an evnet scheduler
    pUsbCore->usbc_es_wk_notify_g = evshed_create(
                        "USBC_WK_NOTIFY", /* timer_name: event scheduler name */
                        MOD_USBCORE, /* dest_mod_id: system sends timeout message to this module when event scheduler timeout happens */
                        0, /* fuzz */
                        255); /* max_delay_ticks */
    if (pUsbCore->usbc_es_wk_notify_g) {
        evshed_set_index(pUsbCore->usbc_es_wk_notify_g, USBC_WK_NOTIFY_INDEX);
    } else {
        ASSERT(0);
    }

    usbc_normal_hif_factory();
    usbc_cosim_hif_factory();

    usbc_stack_checkin(USB_CLASS_NUM, NULL);
    return KAL_TRUE;
}

void usbc_cosim_core_task_main(task_entry_struct* task_entry_ptr)
{
    kal_uint8 wait_count = 0;
    ilm_struct current_ilm;
    kal_uint32 rt_event;
    kal_uint16 timer_index;
    module_type dest_mod;
    msg_type msg_id;
    usbc_class_device_esl_connect_parm  *rsp_msg_p;
    usbc_core_t* pUsbCore = usbc_core_get_instance();

    kal_set_active_module_id(MOD_USBCORE);
    kal_mem_set(&current_ilm, 0, sizeof(ilm_struct));

    usbc_esl_printf("Start USBCORE task loop...\n");
    while(1)
    {
        while ( msg_get_extq_messages() > 0 )
        {
            if ( msg_receive_extq(&current_ilm) != KAL_TRUE )
            {
                break;
            }

            switch (current_ilm.msg_id)
            {
                case MSG_ID_TIMER_EXPIRY:
                    timer_index = evshed_get_index(&current_ilm);
                    switch (timer_index)
                    {
                        case USBC_WK_NOTIFY_INDEX:
                            ASSERT(0);
                            evshed_timer_handler(pUsbCore->usbc_es_wk_notify_g);
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }

            destroy_ilm(&current_ilm);
        }

        /* Wait someone notify HMU to wake up HIF. */
        rt_event = hmu_hifeg_wait(HIF_DRV_EG_HIF_TICK_EVENT | HIF_DRV_EG_USBC_IND_EVENT);
        if ((HIF_DRV_EG_HIF_TICK_EVENT & rt_event) &&
            (pUsbCore->state != USBC_USB_STATE_SUSPENDED))
        {
            /* poll HIF queue data */
            usbc_esl_printf("Start HIF USB poll queue...\n");
            usbc_normal_hif_poll_queue();
            usbc_esl_printf("End HIF USB poll queue...\n");
        }
        if ((HIF_DRV_EG_USBC_IND_EVENT & rt_event))
        {
            /* Handle indications */
            usbc_normal_hif_process_indications();
        }

        // wait for IPCORE finishing handling ILMs in ipc_init
        if (wait_count < 1)
        {
            wait_count++;

            if(wait_count == 1)
            {
                usbc_esl_printf("Emulare USB enumeration...\n");
                // Emulate USB plug-in for ESL COSIM
                usbc_cosim_hif_attach();

                usbc_esl_printf("Set USB class to connected state...\n");
                // change USB classes state to transfer data
                rsp_msg_p = (usbc_class_device_esl_connect_parm*)construct_local_para(sizeof(usbc_class_device_esl_connect_parm), TD_RESET);
                ASSERT(rsp_msg_p);
                rsp_msg_p->class_device_id = 0;
                msg_id = MSG_ID_USBCLASS_USBCORE_ESL_ENTER_CONNECTED_STATE_REQ;

                switch ((pUsbCore->class_device[0]).class_type)
                {
#ifdef __USB_MBIM_SUPPORT__
                    case USB_CLASS_MBIM:
                        dest_mod = MOD_MBIM;
                        break;
#endif
#ifdef __USB_ECM_SUPPORT__
                    case USB_CLASS_ECM:
                        dest_mod = MOD_ECM;
                        break;
#endif
#ifdef __USB_RNDIS_SUPPORT__			
                    case USB_CLASS_RNDIS:
                        dest_mod = MOD_RNDIS;
                        break;
#endif			
                    default:
                        // We assume the first class device must be a NIC for ESL CO-SIM
                        ASSERT(0);
                        return;
                        break;
                }

                msg_send6(MOD_USBCORE,  // src module
                          dest_mod,  // dst module
                          0,       // sap id
                          msg_id,
                          (local_para_struct*)rsp_msg_p,
                          0); //msg id
            }
        }
    }
}
