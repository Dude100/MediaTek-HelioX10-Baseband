/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *
 * Filename:
 * ---------
 * custom_gprs_pdp_default_qos_config.h
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the GPRS default PDP context qos setting
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
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
 *
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _CUSTOM_GPRS_PDP_DEFAULT_QOS_CONFIG_H
#define _CUSTOM_GPRS_PDP_DEFAULT_QOS_CONFIG_H

#define PS_QOS_PROFILE_DEFAULT_REQ_LENGTH (16) // please do not modify this before consulting with MTK
#define PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_1 (0) // please do not modify this
#define PS_QOS_PROFILE_DEFAULT_REQ_DELAY_CLASS (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_PEAK_THROUGHPUT (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_2 (0) // please do not modify this
#define PS_QOS_PROFILE_DEFAULT_REQ_PRECEDENCE_CLASS (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_3 (0) // please do not modify this
#ifdef  __UMTS_TDD128_MODE__
#define PS_QOS_PROFILE_DEFAULT_REQ_MEAN_THROUGHPUT (31)
#else
#define PS_QOS_PROFILE_DEFAULT_REQ_MEAN_THROUGHPUT (0)
#endif
#define PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_CLASS (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_ORDER (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_OF_ERR_SDU (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_MAX_SDU_SIZE (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_UPLINK (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_DOWNLINK (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_RESIDUAL_BIT_ERROR_RATE (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_TRANSFER_DELAY (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_HNDL_PRIORITY (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_UPLINK (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_DOWNLINK (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_4 (0) // please do not modify this
#define PS_QOS_PROFILE_DEFAULT_REQ_SIGNALING_INDICATION (0) // please do not modify this before consulting with MTK
#define PS_QOS_PROFILE_DEFAULT_REQ_SOURCE_STAT_DESCPTOR (0) // please do not modify this before consulting with MTK
#define PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_DONW_LINK (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_DONW_LINK (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_UP_LINK (0)
#define PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_UP_LINK (0)

//mtk04121
#define PS_QOS_PROFILE_DEFAULT_REQ_QCI (9) //please do not modify this
#define PS_QOS_PROFILE_DEFAULT_REQ_EXT2_MAX_BIT_RATE_UP_LINK (0) //please do not modify this
#define PS_QOS_PROFILE_DEFAULT_REQ_EXT2_MAX_BIT_RATE_DONW_LINK (0) //please do not modify this
#define PS_QOS_PROFILE_DEFAULT_REQ_EXT2_GUARANTEED_BIT_RATE_UP_LINK (0) //please do not modify this
#define PS_QOS_PROFILE_DEFAULT_REQ_EXT2_GUARANTEED_BIT_RATE_DONW_LINK (0) //please do not modify this

#define PS_QOS_PROFILE_DEFAULT_MIN_LENGTH (16) // please do not modify this before consulting with MTK
#define PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_1 (0) // please do not modify this
#define PS_QOS_PROFILE_DEFAULT_MIN_DELAY_CLASS (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_RELIABILITY_CLASS (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_PEAK_THROUGHPUT (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_2 (0) // please do not modify this
#define PS_QOS_PROFILE_DEFAULT_MIN_PRECEDENCE_CLASS (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_3 (0) // please do not modify this
#define PS_QOS_PROFILE_DEFAULT_MIN_MEAN_THROUGHPUT (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_CLASS (4)
#define PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_ORDER (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_OF_ERR_SDU (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_MAX_SDU_SIZE (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_UPLINK (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_DOWNLINK (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_RESIDUAL_BIT_ERROR_RATE (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_SDU_ERROR_RATIO (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_TRANSFER_DELAY (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_HNDL_PRIORITY (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_UPLINK (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_DOWNLINK (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_4 (0) // please do not modify this
#define PS_QOS_PROFILE_DEFAULT_MIN_SIGNALING_INDICATION (0) // please do not modify this before consulting with MTK
#define PS_QOS_PROFILE_DEFAULT_MIN_SOURCE_STAT_DESCPTOR (0) // please do not modify this before consulting with MTK
#define PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_DONW_LINK (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_DONW_LINK (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_UP_LINK (0)
#define PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_UP_LINK (0)

#endif /* _CUSTOM_GPRS_PDP_DEFAULT_QOS_CONFIG_H */ 

