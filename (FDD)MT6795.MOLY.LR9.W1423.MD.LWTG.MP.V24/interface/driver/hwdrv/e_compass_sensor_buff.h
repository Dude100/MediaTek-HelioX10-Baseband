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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    e_compass_sensor_buff.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is for e_compass sensor driver.
 *
 * Author:
 * Peter Zhang
 *
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef E_COMPASS_SENSOR_BUFF_H
#define E_COMPASS_SENSOR_BUFF_H

#define ec_get_buf_roomleft(_left)   \
{\
    if ( e_compass_sensor_buff.e_compass_sensor_rindex <= e_compass_sensor_buff.e_compass_sensor_windex ) \
    {\
        _left = E_COMPASS_SENSOR_BUFFER_SIZE - e_compass_sensor_buff.e_compass_sensor_windex + e_compass_sensor_buff.e_compass_sensor_rindex - 1;\
    }\
    else\
    {\
        _left = e_compass_sensor_buff.e_compass_sensor_rindex - e_compass_sensor_buff.e_compass_sensor_windex - 1;\
    }\
}

#define ec_get_buf_avail(_left)   \
{\
    if ( e_compass_sensor_buff.e_compass_sensor_windex >= e_compass_sensor_buff.e_compass_sensor_rindex ) \
    {\
        _left = e_compass_sensor_buff.e_compass_sensor_windex - e_compass_sensor_buff.e_compass_sensor_rindex;\
    }\
    else\
    {\
        _left = E_COMPASS_SENSOR_BUFFER_SIZE - e_compass_sensor_buff.e_compass_sensor_rindex + e_compass_sensor_buff.e_compass_sensor_windex;\
    }\
}

#define e_compass_push_data_to_buffer(_data,_room)   \
{\
    e_compass_sensor_buff.e_compass_sensor_data[e_compass_sensor_buff.e_compass_sensor_windex]= _data;\
    e_compass_sensor_buff.e_compass_sensor_windex++;\
    e_compass_sensor_buff.e_compass_sensor_windex &= (E_COMPASS_SENSOR_BUFFER_SIZE - 1);\
    if (_room == 1)\
        e_compass_sensor_data.data_cb_func(e_compass_sensor_data.data_para, E_COMPASS_SENSOR_BUFF_FULL);\
    else\
        e_compass_sensor_data.data_cb_func(e_compass_sensor_data.data_para, E_COMPASS_SENSOR_BUFF_DATA_EXIST);\
}

#define e_compass_pop_data_from_buffer(_data)   \
{\
    (_data) = e_compass_sensor_buff.e_compass_sensor_data[e_compass_sensor_buff.e_compass_sensor_rindex];\
    e_compass_sensor_buff.e_compass_sensor_rindex ++;\
    e_compass_sensor_buff.e_compass_sensor_rindex &= (E_COMPASS_SENSOR_BUFFER_SIZE - 1);\
}

#define e_compass_flush_data_buffer()   \
{\
    e_compass_sensor_buff.e_compass_sensor_rindex = 0;\
    e_compass_sensor_buff.e_compass_sensor_windex = 0;\
}

#endif
