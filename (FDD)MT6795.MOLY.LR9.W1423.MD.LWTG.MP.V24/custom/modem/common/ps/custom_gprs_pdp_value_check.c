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
 * custom_gprs_pdp_config.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the FLC2 configuration.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifdef __MOD_TCM__

#include "custom_gprs_pdp_value_check.h"

//#include "kal_release.h"
//#include "kal_non_specific_general_types.h"
//#include "l3_inc_enums.h"
//#include "mmi_l3_enums.h"
//#include "custom_mmi_default_value.h"
#include "mcd_l3_inc_gprs_struct.h"
//mtk04121 
#include "ps_public_struct.h" //path: mcu/interface/modem/ps_public_struct.h

//#include "common_nvram_editor_data_item.h"
//#include "custom_data_account.h"

//#include "l4c2abm_struct.h"

//#include "mmi_sm_enums.h"

//#include "ppp_l4_enums.h"

//#include "tcm_common_enums.h"
//#include "tcm_common.h"

#include "custom_gprs_pdp_default_qos_config.h"

//#include "custom_gprs_pdp_config.h"
#include "kal_public_defs.h"
#include "l4_ps_api.h"


//------------------------------ suggest Add ------------------------------    
#include "kal_general_types.h"    
#include "kal_public_api.h"

#include "ps_public_utility.h"

kal_uint8 custom_gprs_get_ps_qos_profile_default_req_sdu_error_ratio(void)
{
    kal_uint8   ps_qos_profile_default_req_sdu_error_ratio;
#ifndef __UMTS_TDD128_MODE__
    if(KAL_TRUE == sbp_query_md_feature(SBP_USE_SM_QOS_SUBSCRIBED))
    {
        ps_qos_profile_default_req_sdu_error_ratio = 0;     // please do not modify this before consulting with MTK (This is to avoid LLC ACK mode)
    } 
    else
    {
        ps_qos_profile_default_req_sdu_error_ratio = 4;     // please do not modify this before consulting with MTK (This is to avoid LLC ACK mode)
    }
#else
        ps_qos_profile_default_req_sdu_error_ratio = 0;     // please do not modify this before consulting with MTK (This is to avoid LLC ACK mode)
#endif
    return ps_qos_profile_default_req_sdu_error_ratio;
}

kal_uint8 custom_gprs_get_ps_qos_profile_default_req_reliability_class(void)
{
    kal_uint8   ps_qos_profile_default_req_reliability_class;
    
    if(KAL_TRUE == sbp_query_md_feature(SBP_USE_SM_QOS_SUBSCRIBED))
    {
        ps_qos_profile_default_req_reliability_class = 0;   // please do not modify this before consulting with MTK (This is to avoid LLC ACK mode)
    } 
    else
    {
        ps_qos_profile_default_req_reliability_class = 3;   // please do not modify this before consulting with MTK (This is to avoid LLC ACK mode)
    }
    return ps_qos_profile_default_req_reliability_class;
}

/*****************************************************************************
* FUNCTION
*   custom_gprs_pdp_check_if_req_eqos_is_default_value
* DESCRIPTION
*   This function check if the EQOS fields are default values
* 
* GLOBALS AFFECTED
*   N/A
*****************************************************************************/
kal_bool custom_gprs_pdp_check_if_eqos_is_default_value(qos_struct * s,tcm_qos_type_enum type)
{
    kal_bool    is_default_value = KAL_FALSE ;

    if ( (TCM_MIN_QOS == type) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_CLASS == s->traffic_class) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_ORDER == s->delivery_order) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_OF_ERR_SDU == s->delivery_of_err_sdu) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_MAX_SDU_SIZE == s->max_sdu_size) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_UPLINK == s->max_bitrate_up_lnk) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_DOWNLINK == s->max_bitrate_down_lnk) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_RESIDUAL_BIT_ERROR_RATE == s->residual_bit_err_rate) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_SDU_ERROR_RATIO == s->sdu_err_ratio) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_TRANSFER_DELAY == s->transfer_delay) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_HNDL_PRIORITY == s->traffic_hndl_priority) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_UPLINK == s->guarntd_bit_rate_up_lnk) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_DOWNLINK == s->guarntd_bit_rate_down_lnk) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_SIGNALING_INDICATION == s->signalling_indication) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_SOURCE_STAT_DESCPTOR == s->source_statistics_descriptor) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_DONW_LINK == s->ext_max_bitrate_down_lnk) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_DONW_LINK == s->ext_guarntd_bit_rate_down_lnk) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_UP_LINK == s->ext_max_bitrate_up_lnk) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_UP_LINK == s->ext_guarntd_bit_rate_up_lnk) )
    {
        is_default_value = KAL_TRUE ;
    }
    else if ( (TCM_REQ_QOS == type) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_CLASS == s->traffic_class) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_ORDER == s->delivery_order) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_OF_ERR_SDU == s->delivery_of_err_sdu) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_MAX_SDU_SIZE == s->max_sdu_size) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_UPLINK == s->max_bitrate_up_lnk) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_DOWNLINK == s->max_bitrate_down_lnk) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_RESIDUAL_BIT_ERROR_RATE == s->residual_bit_err_rate) 
               && (custom_gprs_get_ps_qos_profile_default_req_sdu_error_ratio() == s->sdu_err_ratio) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_TRANSFER_DELAY == s->transfer_delay) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_HNDL_PRIORITY == s->traffic_hndl_priority) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_UPLINK == s->guarntd_bit_rate_up_lnk) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_DOWNLINK == s->guarntd_bit_rate_down_lnk) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_SIGNALING_INDICATION == s->signalling_indication) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_SOURCE_STAT_DESCPTOR == s->source_statistics_descriptor) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_DONW_LINK == s->ext_max_bitrate_down_lnk) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_DONW_LINK == s->ext_guarntd_bit_rate_down_lnk) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_UP_LINK == s->ext_max_bitrate_up_lnk) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_UP_LINK == s->ext_guarntd_bit_rate_up_lnk) )
    {
        is_default_value = KAL_TRUE ;
    }

    return is_default_value ; 
}

/*****************************************************************************
* FUNCTION
*   custom_gprs_pdp_check_if_req_qos_is_default_value
* DESCRIPTION
*   This function check if the QOS fields are default values
* 
* GLOBALS AFFECTED
*   N/A
*****************************************************************************/
kal_bool custom_gprs_pdp_check_if_qos_is_default_value(qos_struct * s, tcm_qos_type_enum type)
{
    kal_bool    is_default_value = KAL_FALSE ;
    
    if ( (TCM_MIN_QOS == type) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_DELAY_CLASS == s->delay_class)
          && (PS_QOS_PROFILE_DEFAULT_MIN_RELIABILITY_CLASS == s->reliability_class) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_PEAK_THROUGHPUT == s->peak_throughput) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_PRECEDENCE_CLASS == s->precedence_class) 
          && (PS_QOS_PROFILE_DEFAULT_MIN_MEAN_THROUGHPUT == s->mean_throughput) )
    {
        is_default_value = KAL_TRUE ;
    }
    else if ( (TCM_REQ_QOS == type) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_DELAY_CLASS == s->delay_class)
               && (custom_gprs_get_ps_qos_profile_default_req_reliability_class() == s->reliability_class) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_PEAK_THROUGHPUT == s->peak_throughput) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_PRECEDENCE_CLASS == s->precedence_class) 
               && (PS_QOS_PROFILE_DEFAULT_REQ_MEAN_THROUGHPUT == s->mean_throughput) )
    {
        is_default_value = KAL_TRUE ;
    }
    
	return is_default_value ;
}

void custom_gprs_pdp_reset_qos_values_to_default_values(qos_struct * qos_p, tcm_qos_type_enum type)
{
	if(TCM_MIN_QOS == type)
	{
        qos_p->qos_length =                               PS_QOS_PROFILE_DEFAULT_MIN_LENGTH;
        qos_p->unused1 =                                   PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_1;
        qos_p->delay_class =                              PS_QOS_PROFILE_DEFAULT_MIN_DELAY_CLASS;
        qos_p->reliability_class =                         PS_QOS_PROFILE_DEFAULT_MIN_RELIABILITY_CLASS;
        qos_p->peak_throughput =                      PS_QOS_PROFILE_DEFAULT_MIN_PEAK_THROUGHPUT;
        qos_p->unused2 =                                    PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_2;
        qos_p->precedence_class =                      PS_QOS_PROFILE_DEFAULT_MIN_PRECEDENCE_CLASS;
        qos_p->unused3 =                                    PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_3;
        qos_p->mean_throughput =                     PS_QOS_PROFILE_DEFAULT_MIN_MEAN_THROUGHPUT;
        qos_p->traffic_class =                               PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_CLASS;
        qos_p->delivery_order =                           PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_ORDER;
        qos_p->delivery_of_err_sdu =                  PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_OF_ERR_SDU;
        qos_p->max_sdu_size =                            PS_QOS_PROFILE_DEFAULT_MIN_MAX_SDU_SIZE;
        qos_p->max_bitrate_up_lnk =                   PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_UPLINK;
        qos_p->max_bitrate_down_lnk =              PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_DOWNLINK;
        qos_p->residual_bit_err_rate =                 PS_QOS_PROFILE_DEFAULT_MIN_RESIDUAL_BIT_ERROR_RATE;
        qos_p->sdu_err_ratio =                             PS_QOS_PROFILE_DEFAULT_MIN_SDU_ERROR_RATIO;
        qos_p->transfer_delay =                            PS_QOS_PROFILE_DEFAULT_MIN_TRANSFER_DELAY;
        qos_p->traffic_hndl_priority =                     PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_HNDL_PRIORITY;
        qos_p->guarntd_bit_rate_up_lnk =            PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_UPLINK;
        qos_p->guarntd_bit_rate_down_lnk =       PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_DOWNLINK;
        qos_p->unused4 =                                      PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_4;
        qos_p->signalling_indication =                    PS_QOS_PROFILE_DEFAULT_MIN_SIGNALING_INDICATION;
        qos_p->source_statistics_descriptor =        PS_QOS_PROFILE_DEFAULT_MIN_SOURCE_STAT_DESCPTOR;
        qos_p->ext_max_bitrate_down_lnk =         PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_DONW_LINK;
        qos_p->ext_guarntd_bit_rate_down_lnk = PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_DONW_LINK;
        qos_p->ext_max_bitrate_up_lnk =              PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_UP_LINK;
        qos_p->ext_guarntd_bit_rate_up_lnk =      PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_UP_LINK;
	}
	else if(TCM_REQ_QOS == type)
	{
        qos_p->qos_length =                               PS_QOS_PROFILE_DEFAULT_REQ_LENGTH;
        qos_p->unused1 =                                   PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_1;
        qos_p->delay_class =                              PS_QOS_PROFILE_DEFAULT_REQ_DELAY_CLASS;
        qos_p->reliability_class =                         custom_gprs_get_ps_qos_profile_default_req_reliability_class();
        qos_p->peak_throughput =                      PS_QOS_PROFILE_DEFAULT_REQ_PEAK_THROUGHPUT;
        qos_p->unused2 =                                    PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_2;
        qos_p->precedence_class =                      PS_QOS_PROFILE_DEFAULT_REQ_PRECEDENCE_CLASS;
        qos_p->unused3 =                                    PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_3;
        qos_p->mean_throughput =                     PS_QOS_PROFILE_DEFAULT_REQ_MEAN_THROUGHPUT;
        qos_p->traffic_class =                               PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_CLASS;
        qos_p->delivery_order =                           PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_ORDER;
        qos_p->delivery_of_err_sdu =                  PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_OF_ERR_SDU;
        qos_p->max_sdu_size =                            PS_QOS_PROFILE_DEFAULT_REQ_MAX_SDU_SIZE;
        qos_p->max_bitrate_up_lnk =                   PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_UPLINK;
        qos_p->max_bitrate_down_lnk =              PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_DOWNLINK;
        qos_p->residual_bit_err_rate =                 PS_QOS_PROFILE_DEFAULT_REQ_RESIDUAL_BIT_ERROR_RATE;
        qos_p->sdu_err_ratio =                             custom_gprs_get_ps_qos_profile_default_req_sdu_error_ratio();
        qos_p->transfer_delay =                            PS_QOS_PROFILE_DEFAULT_REQ_TRANSFER_DELAY;
        qos_p->traffic_hndl_priority =                     PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_HNDL_PRIORITY;
        qos_p->guarntd_bit_rate_up_lnk =            PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_UPLINK;
        qos_p->guarntd_bit_rate_down_lnk =       PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_DOWNLINK;
        qos_p->unused4 =                                      PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_4;
        qos_p->signalling_indication =                    PS_QOS_PROFILE_DEFAULT_REQ_SIGNALING_INDICATION;
        qos_p->source_statistics_descriptor =        PS_QOS_PROFILE_DEFAULT_REQ_SOURCE_STAT_DESCPTOR;
        qos_p->ext_max_bitrate_down_lnk =         PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_DONW_LINK;
        qos_p->ext_guarntd_bit_rate_down_lnk = PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_DONW_LINK;
        qos_p->ext_max_bitrate_up_lnk =              PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_UP_LINK;
        qos_p->ext_guarntd_bit_rate_up_lnk =      PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_UP_LINK;
	}
	else
	{
		ASSERT(0);
	}

    
}

//mtk04121
/*****************************************************************************
* FUNCTION
*   custom_gprs_pdp_reset_eps_qos_values_to_default_values
* DESCRIPTION
*   This function reset EPS QOS fields
* 
* GLOBALS AFFECTED
*   N/A
*****************************************************************************/
void custom_gprs_pdp_reset_eps_qos_values_to_default_values(tcm_eps_qos_struct *eps_req_qos)
{
        eps_req_qos->qci =                                PS_QOS_PROFILE_DEFAULT_REQ_QCI;
        eps_req_qos->unused1 =                            PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_1;
        eps_req_qos->unused2 =                                    PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_2;
        eps_req_qos->unused3 =                                    PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_3;
        eps_req_qos->max_bitrate_up_lnk =                   PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_UPLINK;
        eps_req_qos->max_bitrate_down_lnk =              PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_DOWNLINK;
        eps_req_qos->guarntd_bit_rate_up_lnk =            PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_UPLINK;
        eps_req_qos->guarntd_bit_rate_down_lnk =       PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_DOWNLINK;
        eps_req_qos->ext_max_bitrate_up_lnk =              PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_UP_LINK;
        eps_req_qos->ext_max_bitrate_down_lnk =         PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_DONW_LINK;
        eps_req_qos->ext_guarntd_bit_rate_up_lnk =      PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_UP_LINK;
        eps_req_qos->ext_guarntd_bit_rate_down_lnk = PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_DONW_LINK;
        eps_req_qos->ext2_max_bitrate_up_lnk =              PS_QOS_PROFILE_DEFAULT_REQ_EXT2_MAX_BIT_RATE_UP_LINK;
        eps_req_qos->ext2_max_bitrate_down_lnk =         PS_QOS_PROFILE_DEFAULT_REQ_EXT2_MAX_BIT_RATE_DONW_LINK;
        eps_req_qos->ext2_guarntd_bit_rate_up_lnk =      PS_QOS_PROFILE_DEFAULT_REQ_EXT2_GUARANTEED_BIT_RATE_UP_LINK;
        eps_req_qos->ext2_guarntd_bit_rate_down_lnk = PS_QOS_PROFILE_DEFAULT_REQ_EXT2_GUARANTEED_BIT_RATE_DONW_LINK;
}
#endif // ~ #ifdef __MOD_TCM__
