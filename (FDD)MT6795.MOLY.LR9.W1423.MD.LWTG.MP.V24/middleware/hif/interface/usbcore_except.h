/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   usbcore_except.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   USB Core exception mode interface.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                 HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __INC_USBCORE_EXCEPT_H
#define __INC_USBCORE_EXCEPT_H

#include "usbcore_common.h"
#include "usbcore_class_device.h"


/*------------------------------------------------------------------------------
 * Data structure defintion.
 *----------------------------------------------------------------------------*/
typedef enum _usbc_except_link_st {
    USBC_LINK_NO_ERROR     = 0,
    USBC_LINK_TX_TIMEOUT   = 1,
} usbc_except_link_st_e;

/*------------------------------------------------------------------------------
 * Public fucntions.
 *----------------------------------------------------------------------------*/

/*!
 *  @brief  Start exception mode HIF data path.
 *          See also hif_except_initial() for more information.
 *  @return KAL_TRUE if succeeded, KAL_FALSE otherwise.
 */
kal_bool usbc_except_init(void);

/*!
 *  @brief  Stop the queue and flush USB pipe FIFO. 
 *          See also hif_except_clear_q() for more information.
 *  @param  class_device_id USB class device id.
 *  @param  queue_no QMU queue no.
 *  @return KAL_TRUE if succeeded, KAL_FALSE otherwise.
 */
kal_bool usbc_except_clear_ch(kal_uint8 class_device_id, kal_uint8 queue_no);

/*!
 *  @brief  Register the device to be used in exception mode and then trigger USB enumeration.
 *  @param  device_info class device information of the device.
 *  @return new instance of usb class device if succeeded, NULL otherwise.
 */
usbc_class_device_instance_t *usbc_except_reset_ch(usbc_class_device_info_t *device_info);

/*!
 *  @brief  Perform USB enumeration. 
 *          Note that, this function exist either the enumeration process is completed or timeout.
 *  @return KAL_TRUE if the USB enumeration is completed, KAL_FALSE if timeout.
 */
kal_bool usbc_except_enum_loop(void);

/*!
 *  @brief Check and handle USB control transfers and other device state changes.
 *         See also hifusb_except_poll_isr() for more information.
 *  @param  class_device_id USB class device id.
 *  @return KAL_TRUE if succeeded, KAL_FALSE otherwise.
 */
kal_bool usbc_except_hif_poll(kal_uint8 class_device_id);

/*!
 *  @brief  Submit a list of GPD to the specified queue of a USB class device instance.
 *          See also hif_except_set_gpd() for more information.
 *  @param  class_device_id USB class device id.
 *  @param  queue_no QMU queue no.
 *  @param  p_first_gpd head of the GPD list.
 *  @param  p_last_gpd tail of the GPD list.
 *  @return KAL_TRUE if succeeded, KAL_FALSE otherwise.
 */
kal_bool usbc_except_submit_gpd(kal_uint8 class_device_id, kal_uint8 queue_no, void *p_first_gpd, void *p_last_gpd);

/*!
 *  @brief  Check if any GPD submitted to specified queue of a USB class device instance has been completed.
 *          See also hif_except_poll_queue() for more information.
 *  @param  class_device_id USB class device id.
 *  @param  queue_no QMU queue no.
 *  @param  pp_first_gpd Caller allocated space for a pointer to head of the GPD list completed. Its value is invalid if this function returns KAL_FALSE.
 *  @param  pp_last_gpd Caller allocated space for a pointer to tail of the GPD list copmleted. Its value is invalid if this function returns KAL_FALSE.
 *  @param  gpd_num Number of GPD completed. Its value is invalid if this function returns KAL_FALSE.
 *  @return KAL_TRUE if succeeded, KAL_FALSE otherwise.
 */
kal_bool usbc_except_poll_queue(kal_uint8 class_device_id, kal_uint8 queue_no, void **pp_first_gpd, void **pp_last_gpd, kal_uint32 *gpd_num);

/*!
 *  @brief  Check specified queue status.
 *          See also hif_except_get_txq_timeout(() for more information.
 *  @param  class_device_id USB class device id.
 *  @param  queue_no QMU queue no.
 *  @param  link_state Return status of the queue if succeeded.
 *  @return KAL_TRUE if succeeded, KAL_FALSE otherwise.
 */
kal_bool usbc_except_hif_state(kal_uint8 class_device_id, kal_uint8 queue_no, usbc_except_link_st_e *link_state);

/*!
 *  @brief  flush Tx/Rx queue in exception reset.
 *  @param  class_device_id USB class device id.
 *  @param  queue_no QMU queue no.
 *  @param  number of returned flushed GPDs.
 *  @param  address of the returned GPD's head.
 *  @param  address of the returned GPD's tail.
 *  @return KAL_TRUE if succeeded, KAL_FALSE otherwise.
 */
kal_bool usbc_except_reset_flush(kal_uint8 class_device_id, kal_uint8 queue_no, void** first_gpd, void** last_gpd, kal_uint32* gpd_num);
#endif /* __INC_USBCORE_EXCEPT_H */

