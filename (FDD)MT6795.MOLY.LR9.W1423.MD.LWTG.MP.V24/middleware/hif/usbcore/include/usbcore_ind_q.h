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
 *   usbcore_ind_q.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   USB Core indication queue operations.
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
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _USBCORE_IND_Q_H
#define _USBCORE_IND_Q_H

#define USBC_IND_CTRL_SETUP       0   /**< Control transfer setup packet indication. */
#define USBC_IND_CTRL_CMPLT       1   /**< Control transfer data phase complete. */
#define USBC_IND_DEV_EVENT        2   /**< USB device event indication. */
#define USBC_IND_SPEED_CHANGE     3   /**< USB speed changed notification. */
#define USBC_IND_ALT_SETTING      4   /**< USB interface alternate setting set by host. */
#define USBC_IND_PIPE_STALL       5   /**< USB pipe HALT state is set or cleared by host. */
#define USBC_IND_MODE_SWITCH      6   /**< USB mode switch indication */
#define USBC_IND_FUNC_EVENT       7   /**< USB function event indication. */
#define USBC_IND_SET_CONFIG       8   /**< USB Set configuration */

/*!
 *  @brief Information to indication up to USB Class.
 */
typedef struct _usbc_ind {
    kal_uint8       ext:4; /**< Extended data specific to each type of indication. */
    kal_uint8       type:4; /**< Type of indication, see USBC_IND_XXX for details. */
    kal_uint8       data; /**< Data specific to each type of indication. */
} usbc_ind_t;

/*!
 *  @brief Copy and enqueue an indication object.
 *  @param indication  [IN] Pointer to the indication object to enqueue.
 */
void usbc_enqueue_ind(usbc_ind_t *indication);

/*!
 *  @brief Dequeue an indication object if available.
 *  @param indication  [OUT] Caller allocated space for the indication object dequeued.
 *  @return KAL_TURE if there's an indicaiton object dequeue; KAL_FALSE otherwise.
 */
kal_bool usbc_dequeue_ind(usbc_ind_t *indication);

#endif
