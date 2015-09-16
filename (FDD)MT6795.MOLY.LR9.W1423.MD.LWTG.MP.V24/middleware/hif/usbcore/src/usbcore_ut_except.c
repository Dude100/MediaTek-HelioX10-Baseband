#include "kal_public_api.h"
#include "intrCtrl.h"
#include "qmu_bm.h"
#include "qmu_bm_util.h"

#include "usbcore_except.h"

static usbc_class_device_info_t         dev_info_s;
static usbc_class_device_instance_t    *dev_inst_s = NULL;
static kal_uint8                        ct_data_buf[2048];

#define MIN(_a, _b) (((_a) <= (_b)) ? (_a) : (_b))

void usbc_at_notify_usb_state(kal_uint8 class_device_id, usbc_usb_state_e state)
{
    ASSERT(0);
}

void usbc_at_notify_usb_speed(kal_uint8 class_device_id, usbc_usb_speed_e speed)
{
    ASSERT(dev_inst_s);
    ASSERT(class_device_id == dev_inst_s->id);
}

void usbc_at_notify_control_setup_packet(kal_uint8 class_device_id, usbc_setup_packet_t *packet)
{
    kal_bool    result;
    
    ASSERT(dev_inst_s);
    ASSERT(class_device_id == dev_inst_s->id);  

    if (packet->bmRequestType & 0x80) { // IN
        ASSERT(packet->wLength > 0);
        result = usbc_class_device_submit_control_request(
                class_device_id, /* kal_uint8 class_device_id */
                NULL, /* kal_uint8 *buffer */
                0, /* kal_uint32 length */
                USBC_CONTROL_REQUEST_TYPE_SEND); /* usbc_control_request_type_e */
    } else { // OUT
        result = usbc_class_device_submit_control_request(
                class_device_id, /* kal_uint8 class_device_id */
                ct_data_buf, /* kal_uint8 *buffer */
                MIN(packet->wLength, sizeof(ct_data_buf)), /* kal_uint32 length */
                USBC_CONTROL_REQUEST_TYPE_RECEIVE); /* usbc_control_request_type_e */
    }
    ASSERT(result);
}

void usbc_at_notify_control_complete(kal_uint8 class_device_id)
{
    ASSERT(dev_inst_s);
    ASSERT(class_device_id == dev_inst_s->id);  
    return; 
}

void usbc_at_exception(void)
{
    static kal_uint32   cnt = 0;
    kal_uint32     mask; 
    kal_uint32     num_gpd;
    void          *head_gpd;
    void          *tail_gpd;
    void          *rx_gpd;
    void          *next_gpd;
    usbc_except_link_st_e   link_state;

    if (cnt++ < 5000) {
        return;
    }

    ASSERT(2 == qbmt_alloc_q_no_tail(QBM_TYPE_HIF_DL, 2, &head_gpd, &tail_gpd));
    for (rx_gpd = head_gpd; rx_gpd; rx_gpd = next_gpd) {
        next_gpd = QBM_DES_GET_NEXT(rx_gpd);

        QBM_DES_SET_ALLOW_LEN(rx_gpd, 512);
        qbm_cal_set_checksum((kal_uint8*)rx_gpd);
        QBM_CACHE_FLUSH(rx_gpd, sizeof(qbm_gpd));
        rx_gpd = QBM_DES_GET_NEXT(rx_gpd);

        if (rx_gpd == tail_gpd) break;
    }

    mask = SaveAndSetIRQMask();

    dev_info_s.class_type = USBC_CLASS_TYPE_CDC_ACM;
    dev_info_s.total_pipes = 3;
    dev_info_s.pipe_type[0] = USBC_PIPE_TYPE_CDC_ACM_COMM_IN;
    dev_info_s.pipe_type[1] = USBC_PIPE_TYPE_CDC_ACM_DATA_IN;
    dev_info_s.pipe_type[2] = USBC_PIPE_TYPE_CDC_ACM_DATA_OUT;
    dev_info_s.notify_usb_state = usbc_at_notify_usb_state;
    dev_info_s.notify_usb_speed = usbc_at_notify_usb_speed;
    dev_info_s.notify_control_setup_packet = usbc_at_notify_control_setup_packet;
    dev_info_s.notify_control_complete = usbc_at_notify_control_complete;
    dev_info_s.notify_alternate_setting = NULL;
    dev_info_s.notify_pipe_complete[0] = NULL;
    dev_info_s.notify_pipe_complete[1] = NULL;
    dev_info_s.notify_pipe_complete[2] = NULL;
    dev_info_s.notify_pipe_stall[0] = NULL;
    dev_info_s.notify_pipe_stall[1] = NULL;
    dev_info_s.notify_pipe_stall[2] = NULL;

    dev_inst_s = usbc_except_reset_ch(&dev_info_s);
    ASSERT(dev_inst_s);
    ASSERT(usbc_except_enum_loop());

    ASSERT(usbc_except_init());
    ASSERT(usbc_except_submit_gpd(dev_inst_s->id, dev_inst_s->queue_no_for_pipe[1], head_gpd, tail_gpd));

    do {
        usbc_except_hif_poll(dev_inst_s->id);

        ASSERT(usbc_except_poll_queue(dev_inst_s->id, dev_inst_s->queue_no_for_pipe[1], &head_gpd, &tail_gpd, &num_gpd));
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        ASSERT(usbc_except_hif_state(dev_inst_s->id, dev_inst_s->queue_no_for_pipe[1], &link_state));
#if 0
/* under construction !*/
#endif

    } while(1);

    RestoreIRQMask(mask);
}
