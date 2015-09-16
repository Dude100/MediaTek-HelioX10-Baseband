/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   ccci_ims_common.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   CCCI_IMS header
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * 	Disable IMS loopback mode
 *
 * removed!
 * removed!
 * [CCCI] CCCI_IMS 1st verison loopback support
 ****************************************************************************/
#ifndef _CCCI_IMS_COMMON_H
#define _CCCI_IMS_COMMON_H
#include "ccci_ims_if.h"
#include "cccidev_qbm.h"      

//#define _CCCI_IMS_LB_IT_

typedef enum _ccci_ims_dev_state {
    IMS_DEV_UNINITIALIZED,       /* Device hasn't initialized yet */
    IMS_DEV_INITIALIZED,         /* Device initialized by ccci_ims_svc_init*/
    IMS_DEV_CONNECTED,           /* CCMNI dev has attached to a IPcore session, MSG_ID_IPCORE_LINK_UP_REQ */
    IMS_DEV_STATE_CNT
} ccci_ims_dev_state;

/*!
 *  @brief ccci_ch_set_t ccci channel descriptor
 */
typedef struct{
    kal_uint8 rx;
    kal_uint8 tx;
    CCCI_IMSCALLBACK rx_cb;
}ccci_ch_set_t;
 
/*!
 *  @brief ccci_ims_device_t CCCI_IMS device descriptor
 */
typedef struct
{
    kal_uint8 state;
    ccci_ch_set_t ch_set;
} ccci_ims_device_t;

typedef struct _ccci_ims_inst_t {
    
    /* <CCCI_IMS device handles> */
    ccci_ims_device_t   dev[CCCI_IMS_CH_MAX];
    /* <CCCI released APIs> */
    kal_int32           (*ccci_write_gpd)(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pextinfo);
    kal_int32           (*ccci_init_gpdior)(CCCI_CHANNEL_T channel, CCCI_IORCALLBACK ior_funp);
} ccci_ims_inst_t;

typedef struct CCCI_IMS_DEBUG_STATUS
{
    /* <CCCI_IMS device handles> */
    ccci_ims_device_t   dev[CCCI_IMS_CH_MAX];
} CCCI_IMS_DEBUG_STATUS_T;

#define CCCI_IMS_GET_QBM_DATALEN          CCCIDEV_GET_QBM_DATALEN
#define CCCI_IMS_GET_QBM_DATAPTR          CCCIDEV_GET_QBM_DATAPTR
#define CCCI_IMS_PUSH_QBM_DATAHEAD        CCCIDEV_PUSH_QBM_DATAHEAD
#define CCCI_IMS_PULL_QBM_DATAHEAD        CCCIDEV_PULL_QBM_DATAHEAD
#define CCCI_IMS_GET_GPD_LIST_SIZE        CCCIDEV_GET_GPD_LIST_SIZE
#define CCCI_IMS_GET_NONBPS_GPD_LIST_SIZE CCCIDEV_GET_NONBPS_GPD_LIST_SIZE
#define CCCI_IMS_FIX_IOR_NULL_LAST        CCCIDEV_FIX_IOR_NULL_LAST
#define CCCI_IMS_RM_CCCI_HEADERS          CCCIDEV_RM_CCCI_HEADERS
#define CCCI_IMS_QBM_ENQ                  CCCIDEV_QBM_ENQ


#ifdef _CCCI_IMS_LB_IT_
void ims_lb_it_init(void);
#endif

#endif //_CCCI_IMS_COMMON_H
