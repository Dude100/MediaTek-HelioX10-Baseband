//#include "kal_release.h"
#include "kal_public_api.h"
#include "syscomp_config.h"
#include "task_config.h"
//#include "kal_debug.h"
#include "sys_test.h"
#include "usbcore_main.h"
#include "usbcore_hif.h"
#include "usbcore_common.h"
#include "usbcore_ind_q.h"
#include "hifusb_qmu.h"
#include "hmu.h"
#include "usbcore_ut.h"

/****************************************************************************
                Macro Declaration
 ***************************************************************************/
#define ST_MOD_NAME     "USBCORE"

/****************************************************************************
               Global Variables
***************************************************************************/
static usbc_ut_fake_class_func_info_t fake_class_func;

hifusb_setup_packet_t getDevStatusPkt =
{
    0x80,   // bmRequestType
    0x00,   // bRequest
    0x00,   // wValue
    0x00,   // wIndex
    0x02,   // wLength
};

hifusb_setup_packet_t getNon1stInfxStatusPkt =
{
    0x81,   // bmRequestType
    0x00,   // bRequest
    0x00,   // wValue
    0x01,   // wIndex
    0x02,   // wLength
};

hifusb_setup_packet_t get1stInfxStatusPkt =
{
    0x81,   // bmRequestType
    0x00,   // bRequest
    0x00,   // wValue
    0x00,   // wIndex
    0x02,   // wLength
};

hifusb_setup_packet_t setDevFeatureRemoteWkPkt =
{
    0x00,   // bmRequestType
    0x03,   // bRequest
    0x01,   // wValue
    0x00,   // wIndex
    0x00,   // wLength
};

hifusb_setup_packet_t setDevFeatureU1Pkt =
{
    0x00,   // bmRequestType
    0x03,   // bRequest
    0x30,   // wValue
    0x00,   // wIndex
    0x00,   // wLength
};

hifusb_setup_packet_t setDevFeatureU2Pkt =
{
    0x00,   // bmRequestType
    0x03,   // bRequest
    0x31,   // wValue
    0x00,   // wIndex
    0x00,   // wLength
};

hifusb_setup_packet_t setDevFeatureLtmPkt =
{
    0x00,   // bmRequestType
    0x03,   // bReques: set featuret
    0x32,   // wValue: feature selector LTM_ENABLE
    0x00,   // wIndex
    0x00,   // wLength
};

hifusb_setup_packet_t setInfxFeatureWkPkt =
{
    0x01,   // bmRequestType
    0x03,   // bRequest: set feature
    0x00,   // wValue: function suspend feature selector
    0x0200,   // wIndex: suspend option + nInterface 
    0x00,
};

hifusb_setup_packet_t setInfxFeatureSuspendPkt =
{
    0x01,   // bmRequestType
    0x03,   // bRequest: set feature
    0x00,   // wValue: function suspend feature selector
    0x0300,   // wIndex: suspend option + nInterface
    0x00,
};

hifusb_setup_packet_t setInfxFeatureResumePkt =
{
    0x01,   // bmRequestType
    0x03,   // bRequest: set feature
    0x00,   // wValue: function suspend feature selector
    0x00,   // wIndex: suspend option + nInterface
    0x00,
};

hifusb_setup_packet_t clsDevFeatureRemoteWkPkt =
{
    0x00,   // bmRequestType
    0x01,   // bRequest
    0x01,   // wValue
    0x00,   // wIndex
    0x00,   // wLength
};

hifusb_setup_packet_t clsDevFeatureU1Pkt =
{
    0x00,   // bmRequestType
    0x01,   // bRequest
    0x30,   // wValue
    0x00,   // wIndex
    0x00,   // wLength
};

hifusb_setup_packet_t clsDevFeatureU2Pkt =
{
    0x00,   // bmRequestType
    0x01,   // bRequest
    0x31,   // wValue
    0x00,   // wIndex
    0x00,   // wLength
};

hifusb_setup_packet_t clsDevFeatureLtmPkt =
{
    0x00,   // bmRequestType
    0x01,   // bRequest
    0x32,   // wValue
    0x00,   // wIndex
    0x00,   // wLength
};

hifusb_setup_packet_t clsInfxFeatureWkPkt =
{
    0x01,   // bmRequestType
    0x01,   // bRequest: clear feature
    0x00,   // wValue: function suspend feature selector
    0x00,   // wIndex: nInterface
    0x00,   // wLength
};

/****************************************************************************
               Private Function
***************************************************************************/
static void usbc_ut_std_req(void *p_param)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    
    // set control setup packet
    usbc_core_dispatch_control_setup_packet(pUsbCore, p_param);
}

static kal_uint16 usbc_ut_get_status(void *p_param)
{
    usbc_core_t* pUsbCore;
    kal_uint16* pStatus;

    usbc_ut_std_req(p_param);

    pUsbCore = usbc_core_get_instance();
    pStatus = (kal_uint16*)pUsbCore->control_request_buffer;

    return *pStatus;
}


/****************************************************************************
               Public Fake Function
***************************************************************************/
kal_uint16 usbc_ut_fake_query_func_wk_status(kal_uint8 class_device_id)
{
    return fake_class_func.infx_status;
}

void usbc_ut_fake_notify_func_wk_ability(kal_uint8 class_device_id, kal_bool ability)
{
    if (ability)
    {
        fake_class_func.infx_status |= 0x0002;
    }
    else
    {
        fake_class_func.infx_status &= 0xFFFD;
    }
}

kal_bool usbc_ut_fake_notify_retry(kal_uint8 nInterface)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 class_device_id = 0;

    fake_class_func.nRetry++;
    if( fake_class_func.nRetry >= 5)
    {
        pUsbCore->is_func_be_accessed[class_device_id] = KAL_TRUE;
    }

    return KAL_TRUE;
}

kal_bool usbc_ut_fake_hif_remote_wakeup()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 class_device_id = pUsbCore->class_interface[0].class_device_id;
    kal_uint16 status;
    usbc_usb_state_e    dev_state;
    usbc_ind_t          ind_to_enqueue;

    // device resume
    dev_state = USBC_USB_STATE_RESUME;
    ind_to_enqueue.type = USBC_IND_DEV_EVENT;
    ind_to_enqueue.ext = 0;
    ind_to_enqueue.data = (kal_uint8)dev_state;
    usbc_enqueue_ind(&ind_to_enqueue);
    hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);

    return KAL_TRUE;
}

void usbc_ut_fake_set_control_request(kal_uint8 *buffer, kal_uint32 length, usbc_control_request_type_e type)
{
    return;
}
/****************************************************************************
                Test Function
 ***************************************************************************/
kal_bool
usbc_ut_is_dev_attached(void *p_parm,
           kal_char *p_ret_err_str,
           kal_uint32 *p_ret_err_str_sz)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
	usbc_fake_hif_factory();

    return KAL_TRUE;
}

kal_bool
usbc_ut_check_1st_infx(void *p_param,
           kal_char *p_ret_err_str,
           kal_uint32 *p_ret_err_str_sz)
{
    kal_uint8 total_interface_number;
    kal_bool ans[6] = {KAL_TRUE, KAL_FALSE, KAL_TRUE, KAL_FALSE, KAL_TRUE, KAL_FALSE};
    usbc_core_t* pUsbCore = usbc_core_get_instance();

    kal_uint8 i;
    kal_bool isFirstInfx;

    if ( pUsbCore->speed == USBC_USB_SPEED_USB30 )
    {
        total_interface_number = 6;
    }
    else
    {
        total_interface_number = 3;
    }

    for( i=0; i<total_interface_number; i++)
    {
        isFirstInfx = usbc_core_is_1st_interface(i);
        if (isFirstInfx != ans[i])
        {
            return KAL_FALSE;
        }
    }
    
    return KAL_TRUE;
}

kal_bool
usbc_ut_get_1st_infx(void *p_param,
           kal_char *p_ret_err_str,
           kal_uint32 *p_ret_err_str_sz)
{
    // set test parameters
    kal_uint8 total_dev_num = 3;
    kal_uint8 ans[3] = {0, 2, 4};
    usbc_core_t* pUsbCore = usbc_core_get_instance();

    kal_uint8 i;
    kal_uint8 nFirstInfx;

    for( i=0; i<total_dev_num; i++)
    {
        nFirstInfx = usbc_class_device_get_1st_interface(i);
        if (nFirstInfx != ans[i])
        {
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;
}

kal_bool
usbc_ut_set_dev_feature(void *p_parm,
        kal_char *p_ret_err_str,
        kal_uint32 *p_ret_err_st_ss)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint16 status = usbc_ut_get_status(&getDevStatusPkt);

    if( 0x0000 != (status & 0xFFFE))
    {
        return KAL_FALSE;
    }

    if ( pUsbCore->speed == USBC_USB_SPEED_USB30 )
    {
        // set LTM enable
        usbc_ut_std_req(&setDevFeatureLtmPkt);
        status = usbc_ut_get_status(&getDevStatusPkt);
        if( 0x0010 != (status & 0xFFFE))
        {
            return KAL_FALSE;
        }    

        // set U2 enable
        usbc_ut_std_req(&setDevFeatureU2Pkt);
        status = usbc_ut_get_status(&getDevStatusPkt);
        if( 0x0018 != (status & 0xFFFE))
        {
            return KAL_FALSE;
        }

        // set U1 enable
        usbc_ut_std_req(&setDevFeatureU1Pkt);
        status = usbc_ut_get_status(&getDevStatusPkt);
        if( 0x001C != (status & 0xFFFE))
        {
            return KAL_FALSE;
        }

        // clear U1 enable
        usbc_ut_std_req(&clsDevFeatureU1Pkt);
        status = usbc_ut_get_status(&getDevStatusPkt);
        if( 0x0018 != (status & 0xFFFE))
        {
            return KAL_FALSE;
        }

        // clear U2 enable
        usbc_ut_std_req(&clsDevFeatureU2Pkt);
        status = usbc_ut_get_status(&getDevStatusPkt);
        if( 0x0010 != (status & 0xFFFE))
        {
            return KAL_FALSE;
        }

        // clear LTM enable
        usbc_ut_std_req(&clsDevFeatureLtmPkt);
        status = usbc_ut_get_status(&getDevStatusPkt);
        if( 0x0000 != (status & 0xFFFE))
        {
            return KAL_FALSE;
        }
    }
    else
    {
        // set remote wakeup
        usbc_ut_std_req(&setDevFeatureRemoteWkPkt);
        status = usbc_ut_get_status(&getDevStatusPkt);
        if( 0x0002 != (status & 0xFFFE))
        {
            return KAL_FALSE;
        }

        // clear remote wakeup
        usbc_ut_std_req(&clsDevFeatureRemoteWkPkt);
        status = usbc_ut_get_status(&getDevStatusPkt);
        if( 0x0000 != (status & 0xFFFE))
        {
            return KAL_FALSE;
        } 
    }

    return KAL_TRUE;
}


kal_bool
usbc_ut_set_infx_feature(void *p_parm,
        kal_char *p_ret_err_str,
        kal_uint32 *p_ret_err_st_ss)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint16 status;

    // non 1st interface of any function, the reported status is 0
    status = usbc_ut_get_status(&getNon1stInfxStatusPkt);
    if( 0x0000 != (status & 0xFFFF))
    {
        return KAL_FALSE;
    }

    status = usbc_ut_get_status(&get1stInfxStatusPkt);
    // 1st interface of a super-speed function
    if ( pUsbCore->speed == USBC_USB_SPEED_USB30 )
    {
        if ( 0x0001 != (status & 0xFFFF))
        {
            return KAL_FALSE;
        }
    }
    //  1st interface of a non super-speed function
    else
    {
        if( 0x0000 != (status & 0xFFFF))
        {
            return KAL_FALSE;
        }
    }

    if ( pUsbCore->speed == USBC_USB_SPEED_USB30 )
    {
        // set feature to enable function remote wakeup
        usbc_ut_std_req(&setInfxFeatureWkPkt);
        status = usbc_ut_get_status(&get1stInfxStatusPkt);
        if ( 0x0003 != (status & 0xFFFF))
        {
            return KAL_FALSE;
        }

        // clear feature to disable function remote wakeup
        usbc_ut_std_req(&clsInfxFeatureWkPkt); 
        status = usbc_ut_get_status(&get1stInfxStatusPkt);
        if ( 0x0001 != (status & 0xFFFF))
        {
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;
}

kal_bool
usbc_ut_func_suspend_resume(void *p_parm,
        kal_char *p_ret_err_str,
        kal_uint32 *p_ret_err_st_ss)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 class_device_id = pUsbCore->class_interface[0].class_device_id;
    kal_uint16 status;

    // function suspend is supported in super-speed device only
    if ( pUsbCore->speed == USBC_USB_SPEED_USB30 )
    {
        // set feature to enable function remote wakeup and set function to suspend
        usbc_ut_std_req(&setInfxFeatureSuspendPkt);
        while( !pUsbCore->class_device[class_device_id].is_func_suspend )
        {
            kal_sleep_task(USBC_UT_BLOCK_TICK_T);
        }
        status = usbc_ut_get_status(&get1stInfxStatusPkt);
        if ( !pUsbCore->class_device[class_device_id].is_func_suspend ||
             0x0003 != (status & 0xFFFF) )
        {
            return KAL_FALSE;
        }
        // set feature to disable function remote wakeu and resume function
        usbc_ut_std_req(&setInfxFeatureResumePkt);
        while( pUsbCore->class_device[class_device_id].is_func_suspend)
        {
            kal_sleep_task(USBC_UT_BLOCK_TICK_T);
        }
        status = usbc_ut_get_status(&get1stInfxStatusPkt);
        if ( pUsbCore->class_device[class_device_id].is_func_suspend ||
             0x0001 != (status & 0xFFFF) )
        {
            return KAL_FALSE;
        }

        // set feature to enable function remote wakeup and set function to suspend
        usbc_ut_std_req(&setInfxFeatureSuspendPkt);
        while( !pUsbCore->class_device[class_device_id].is_func_suspend)
        {
            kal_sleep_task(USBC_UT_BLOCK_TICK_T);
        }
        status = usbc_ut_get_status(&get1stInfxStatusPkt);
        if ( !pUsbCore->class_device[class_device_id].is_func_suspend ||
             0x0003 != (status & 0xFFFF) )
        {
            return KAL_FALSE;
        }
        // clear feature to disable function remote wakeu and resume function
        usbc_ut_std_req(&clsInfxFeatureWkPkt);
        while( pUsbCore->class_device[class_device_id].is_func_suspend)
        {
            kal_sleep_task(USBC_UT_BLOCK_TICK_T);
        }
        status = usbc_ut_get_status(&get1stInfxStatusPkt);
        if ( pUsbCore->class_device[class_device_id].is_func_suspend ||
             0x0001 != (status & 0xFFFF) )
        {
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;   
}

kal_bool
usbc_ut_func_suspend_remote_wk(void *p_parm,
        kal_char *p_ret_err_str,
        kal_uint32 *p_ret_err_st_ss)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 class_device_id = pUsbCore->class_interface[0].class_device_id;
    kal_uint16 status;
    fake_class_func.nRetry = 0;

    // function suspend is supported in super-speed device only
    if ( pUsbCore->speed == USBC_USB_SPEED_USB30 )
    {
        // set feature to enable function remote wakeup and set function to suspend
        usbc_ut_std_req(&setInfxFeatureSuspendPkt);
        while( !pUsbCore->class_device[class_device_id].is_func_suspend)
        {
            kal_sleep_task(USBC_UT_BLOCK_TICK_T);
        }
        status = usbc_ut_get_status(&get1stInfxStatusPkt);
        if ( !pUsbCore->class_device[class_device_id].is_func_suspend ||
             0x0003 != (status & 0xFFFF) )
        {
            return KAL_FALSE;
        }
        // remote wakeup to resume the function
        usbc_class_device_func_remote_wk(class_device_id);
        while( pUsbCore->class_device[class_device_id].is_func_suspend )
        {
            kal_sleep_task(USBC_UT_BLOCK_TICK_T);
        }
        status = usbc_ut_get_status(&get1stInfxStatusPkt);
        if ( pUsbCore->class_device[class_device_id].is_func_suspend ||
             0x0003 != (status & 0xFFFF) )
        {
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;
}

kal_bool
usbc_ut_dev_suspend_resume(void *p_parm,
        kal_char *p_ret_err_str,
        kal_uint32 *p_ret_err_st_ss)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 class_device_id = pUsbCore->class_interface[0].class_device_id;
    kal_uint16 status;
    usbc_usb_state_e    dev_state;
    usbc_ind_t          ind_to_enqueue;


    /* test for USB non super-speed devices and supoer-speed devices without function suspend */
    // device suspend
    dev_state = USBC_USB_STATE_SUSPENDING;
    ind_to_enqueue.type = USBC_IND_DEV_EVENT;
    ind_to_enqueue.ext = 0;
    ind_to_enqueue.data = (kal_uint8)dev_state;
    usbc_enqueue_ind(&ind_to_enqueue);
    hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
    while ( USBC_USB_STATE_SUSPENDED!= pUsbCore->state )
    {
        kal_sleep_task(USBC_UT_BLOCK_TICK_T);
    }
    if ( pUsbCore->class_device[class_device_id].is_func_suspend )
    {
       return KAL_FALSE;
    }

    // device resume
    dev_state = USBC_USB_STATE_RESUME;
    ind_to_enqueue.type = USBC_IND_DEV_EVENT;
    ind_to_enqueue.ext = 0;
    ind_to_enqueue.data = (kal_uint8)dev_state;
    usbc_enqueue_ind(&ind_to_enqueue);
    hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
    while ( USBC_USB_STATE_RESUME != pUsbCore->state )
    {
        kal_sleep_task(USBC_UT_BLOCK_TICK_T);
    }
    if ( pUsbCore->class_device[class_device_id].is_func_suspend )
    {
        return KAL_FALSE;
    }

    // test for USB super-speed device with function suspend
    if ( pUsbCore->speed == USBC_USB_SPEED_USB30 )
    {
        // set function to be suspended
        usbc_ut_std_req(&setInfxFeatureSuspendPkt);
        if ( !pUsbCore->class_device[class_device_id].is_func_suspend )
        {
            return KAL_FALSE;
        }

        // device suspend
        dev_state = USBC_USB_STATE_SUSPENDING;
        ind_to_enqueue.type = USBC_IND_DEV_EVENT;
        ind_to_enqueue.ext = 0;
        ind_to_enqueue.data = (kal_uint8)dev_state;
        usbc_enqueue_ind(&ind_to_enqueue);
        hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
        while ( USBC_USB_STATE_SUSPENDED != pUsbCore->state )
        {
            kal_sleep_task(USBC_UT_BLOCK_TICK_T);
        }
        if ( !pUsbCore->class_device[class_device_id].is_func_suspend )
        {
            return KAL_FALSE;
        }

        // device resume
        dev_state = USBC_USB_STATE_RESUME;
        ind_to_enqueue.type = USBC_IND_DEV_EVENT;
        ind_to_enqueue.ext = 0;
        ind_to_enqueue.data = (kal_uint8)dev_state;
        usbc_enqueue_ind(&ind_to_enqueue);
        hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
        while ( USBC_USB_STATE_RESUME != pUsbCore->state )
        {
            kal_sleep_task(USBC_UT_BLOCK_TICK_T);
        }
        if ( !pUsbCore->class_device[class_device_id].is_func_suspend )
        {
            return KAL_FALSE;
        }

        // set the function to be resumed
        usbc_ut_std_req(&setInfxFeatureResumePkt);
        if ( pUsbCore->class_device[class_device_id].is_func_suspend )
        {
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;
}

kal_bool
usbc_ut_dev_suspend_remote_wk(void *p_parm,
        kal_char *p_ret_err_str,
        kal_uint32 *p_ret_err_st_ss)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 class_device_id = pUsbCore->class_interface[0].class_device_id;
    kal_uint16 status;
    usbc_usb_state_e    dev_state;
    usbc_ind_t          ind_to_enqueue;

    // for non super-speed device, use device remote wakeup
    if ( pUsbCore->speed != USBC_USB_SPEED_USB30 )
    {
        // set feature to enable device remote wakeup
        usbc_ut_std_req(&setDevFeatureRemoteWkPkt);
        status = usbc_ut_get_status(&getDevStatusPkt);
        if( 0x0002 != (status & 0xFFFE))
        {
            return KAL_FALSE;
        }

        // device suspend
        dev_state = USBC_USB_STATE_SUSPENDING;
        ind_to_enqueue.type = USBC_IND_DEV_EVENT;
        ind_to_enqueue.ext = 0;
        ind_to_enqueue.data = (kal_uint8)dev_state;
        usbc_enqueue_ind(&ind_to_enqueue);
        hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
        while ( USBC_USB_STATE_SUSPENDED!= pUsbCore->state )
        {
            kal_sleep_task(USBC_UT_BLOCK_TICK_T);
        }
        if ( pUsbCore->class_device[class_device_id].is_func_suspend )
        {
           return KAL_FALSE;
        }

        // device remote wakeup
        usbc_class_device_func_remote_wk(class_device_id);
        while ( USBC_USB_STATE_RESUME != pUsbCore->state )
        {
            kal_sleep_task(USBC_UT_BLOCK_TICK_T);
        }
        if ( pUsbCore->class_device[class_device_id].is_func_suspend )
        {
            return KAL_FALSE;
        }

        // clear remote wakeup
        usbc_ut_std_req(&clsDevFeatureRemoteWkPkt);
        status = usbc_ut_get_status(&getDevStatusPkt);
        if( 0x0000 != (status & 0xFFFE))
        {
            return KAL_FALSE;
        }
    }
    else
    {
        // set feature to enable function remote wakeup and set function to suspend
        usbc_ut_std_req(&setInfxFeatureSuspendPkt);
        status = usbc_ut_get_status(&get1stInfxStatusPkt);
        if ( !pUsbCore->class_device[class_device_id].is_func_suspend ||
             0x0003 != (status & 0xFFFF) )
        {
            return KAL_FALSE;
        }

        // device suspend
        dev_state = USBC_USB_STATE_SUSPENDING;
        ind_to_enqueue.type = USBC_IND_DEV_EVENT;
        ind_to_enqueue.ext = 0;
        ind_to_enqueue.data = (kal_uint8)dev_state;
        usbc_enqueue_ind(&ind_to_enqueue);
        hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
        while ( USBC_USB_STATE_SUSPENDED!= pUsbCore->state )
        {
            kal_sleep_task(USBC_UT_BLOCK_TICK_T);
        }
        if ( !pUsbCore->class_device[class_device_id].is_func_suspend )
        {
           return KAL_FALSE;
        }

        // device resume and function remote wakeup
        usbc_class_device_func_remote_wk(class_device_id);
        while ( USBC_USB_STATE_RESUME != pUsbCore->state  ||
                pUsbCore->class_device[class_device_id].is_func_suspend )
        {
            kal_sleep_task(USBC_UT_BLOCK_TICK_T);
        }
        if ( pUsbCore->class_device[class_device_id].is_func_suspend )
        {
            return KAL_FALSE;
        }

        // clear feature to disable function remote wakeup
        usbc_ut_std_req(&clsInfxFeatureWkPkt);
        status = usbc_ut_get_status(&get1stInfxStatusPkt);
        if ( 0x0001 != (status & 0xFFFF))
        {
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;
}

kal_bool
usbc_ut_notification_timeout(void *p_parm,
        kal_char *p_ret_err_str,
        kal_uint32 *p_ret_err_st_ss)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 class_device_id = 0;
    fake_class_func.nRetry = 0;

    usbc_set_wk_notify_timer((class_device_id));
    while ( !pUsbCore->is_func_be_accessed[class_device_id] )
    {
        kal_sleep_task(USBC_UT_BLOCK_TICK_T);
    }

    if( fake_class_func.nRetry >=5 )
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

//#define  ERR_STR   "This is a sample error case"
//kal_bool
//usbc_ut_get_1st_infx(void *p_param,
//           kal_char *p_ret_err_str,
//           kal_uint32 *p_ret_err_str_sz)
//{
    /* Test case is FAILED */
//    strncpy(p_ret_err_str, ERR_STR, MIN(strlen(ERR_STR), *p_ret_err_str_sz));
//    *p_ret_err_str_sz = MIN(strlen(ERR_STR), *p_ret_err_str_sz);

//    return KAL_FALSE;
//}


/****************************************************************************
                USBCORE Task Init Function
 ***************************************************************************/

ST_TCASE_T st_tcase_g[] = {
    { "Check the attachment of the device",
      usbc_ut_is_dev_attached,
      NULL
    },
   { "Check 1st interface", 
       usbc_ut_check_1st_infx, 
       NULL
    },
    { "Get 1st interface", 
       usbc_ut_get_1st_infx, 
       NULL 
    },
    { "Set/clear features of device", 
      usbc_ut_set_dev_feature,
      NULL
    },
    { "Set/clear feature of interface",
      usbc_ut_set_infx_feature,
      NULL
    },
    { "Function wakeup notification timeout and retry",
      usbc_ut_notification_timeout,
      NULL
    },
    { "Function suspend and resume by host",
      usbc_ut_func_suspend_resume,
      NULL
    },
    { "Function suspend and remote wakeup by class devices",
      usbc_ut_func_suspend_remote_wk,
      NULL
    },
    { "Device suspend and resume by host",
      usbc_ut_dev_suspend_resume,
      NULL
    },
    { "Device suspend and remote wakeup by class devices",
      usbc_ut_dev_suspend_remote_wk,
      NULL
    }
};

kal_uint32 st_tcase_count_g = sizeof(st_tcase_g) / sizeof(ST_TCASE_T);

kal_bool usbcore_ut_st_create (void)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();

    // set fefault fake class device value
    fake_class_func.infx_status = 0x0001;
    fake_class_func.nRetry = 0;

    pUsbCore->speed = USBC_USB_SPEED_USB30;

      return st_reg_test(ST_MOD_NAME,  /* p_mod_name */
                     st_tcase_g, /* p_tcase */
                     st_tcase_count_g /* tcase_num */
           );
}
