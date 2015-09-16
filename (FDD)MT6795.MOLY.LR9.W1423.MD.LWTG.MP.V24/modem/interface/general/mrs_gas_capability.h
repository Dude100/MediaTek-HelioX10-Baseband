/******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*******************************************************************************/

/******************************************************************************
 * Filename:
 * --------------------------------------------------------
 *   mrs_gas_capability.h
 *
 * Project:
 * --------------------------------------------------------
 *   Multimode
 *
 * Description:
 * --------------------------------------------------------
 *   The GAS capability stored in MRS context.
 *
 * Author:
 * --------------------------------------------------------
 * -------
 *
 * --------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Back out changelist 321857
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .GAS part
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * [Henry][Multi-Mode Development] GAS Development and R8 CR Sync
 *
 * removed!
 * NULL
 * gas capability.
 *
 *****************************************************************************/

#ifndef _MRS_GAS_CAPABILITY_H
#define _MRS_GAS_CAPABILITY_H

#if defined(__UMTS_TDD128_MODE__) || defined(__TDD_MODEM__)

/************************************************* Begin of TDD's part *************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "bitstream.h"
#include "l3_inc_enums.h"
#include "mrs_as_enums.h"



/*****************************************************************************
 * Macros Without Parameters
 *****************************************************************************/


/*****************************************************************************
 * Macros With Parameters
 *****************************************************************************/


/*****************************************************************************
 * Enums without tags
 *****************************************************************************/
    /* Define the needed file size kept in NVRAM */
#define RR_NVRAM_CLK2_LEN           3
    /* Peter, 20080804: change the len of classmark3 */
#define RR_NVRAM_CLK3_LEN           34
#define RR_NVRAM_READ_CLK_LEN       12
#define RR_FULL_CLK2_LEN           5

#define  P_GSM_MASK_IN_NVRAM    0x01
#define  E_GSM_MASK_IN_NVRAM    0x02
#define  DCS_1800_MASK_IN_NVRAM 0x04
#define  GSM_480_MASK_IN_NVRAM  0x01
#define  GSM_450_MASK_IN_NVRAM  0x02

#define ADD_CLASSMARK_INFO_IEI         0x20
#define CLASSMARK_2_IEI                0x33


/*****************************************************************************
 * Type Definitions
 *****************************************************************************/
/* Stucture of supported channel modes */
typedef struct channel_mode_supported_struct
{
    kal_uint8 is_signalling_supp;
    kal_uint8 is_speech_full_or_half_ver_1_supp;
    kal_uint8 is_speech_full_or_half_ver_2_supp;
    kal_uint8 is_speech_full_or_half_ver_3_supp;
    /* ZY: add for AMR-WB */
#ifdef __AMRWB_LINK_SUPPORT__
    kal_uint8 is_speech_full_or_half_ver_4_supp;
    kal_uint8 is_speech_full_or_half_ver_5_supp;
#endif /* __AMRWB_LINK_SUPPORT__ */ 
    kal_uint8 is_data_43_5_dl_or_14_5_ul_supp;
    kal_uint8 is_data_29_0_dl_or_14_5_ul_supp;
    kal_uint8 is_data_43_5_dl_or_29_0_ul_supp;
    kal_uint8 is_data_14_5_dl_or_43_5_ul_supp;
    kal_uint8 is_data_14_5_dl_or_29_0_ul_supp;
    kal_uint8 is_data_29_0_dl_or_43_5_ul_supp;
    kal_uint8 is_data_43_5_radio_intf_rate_supp;
    kal_uint8 is_data_32_0_radio_intf_rate_supp;
    kal_uint8 is_data_29_0_radio_intf_rate_supp;
    kal_uint8 is_data_14_5_radio_intf_rate_supp;
    kal_uint8 is_data_12_0_radio_intf_rate_supp;
    kal_uint8 is_data_06_0_radio_intf_rate_supp;
    kal_uint8 is_data_03_6_radio_intf_rate_supp;
    kal_uint8 is_half_rate_supp;

}
channel_mode_supported_struct;

typedef struct ms_capability_from_mrs_struct
{
    kal_uint8 access_tech[16];
    kal_uint8 power_cap[16];
    kal_uint8 hscsd_multi_slot_class;
    kal_uint8 gprs_multi_slot_class;
    kal_uint8 pseudo_sync_cap;
    kal_uint8 vbs;
    kal_uint8 vgcs;
    kal_uint8 algo_supported;
    kal_uint8 hscsd_multi_slot_class_present;
    kal_uint8 gprs_multi_slot_class_present;
    kal_uint8 revision_level_indicator;
    kal_uint8 gprs_ext_dynamic_cap;
    kal_uint8 gea_supported;
    kal_uint8 sm_cap_gprs;
    kal_uint8 pfc_mode;

    kal_bool early_class_mark_support;
    kal_bool is_l2_random_fill_bits;
    kal_uint8 mm_non_drx_timer_value;
    channel_mode_supported_struct chl_mode_supported;   /* struct of supported channel modes */

    /* Evelyn 20080909 */
    /* Lanslo 20050215: for selecting GPRS or EGPRS capability */
#ifdef __EGPRS_MODE__
    kal_uint8 egprs_multi_slot_class_present;
    kal_uint8 egprs_multi_slot_class;
    kal_uint8 egprs_ext_dynamic_cap;
    //Jelly 20090602 Use __EPSK_TX__
    /* Evelyn 20090422: set difference power class of 8PSK */
#ifdef __EPSK_TX__
    kal_uint8 power_cap_8psk[16];
#endif /* __EPSK_TX__ */
#endif /* __EGPRS_MODE__ */ 

    /* Evelyn 20090905: Modify for High multislot class */
#if defined (__MULTISLOT_CLASS_34__) || defined (__MULTISLOT_CLASS_45__)
    kal_uint8 high_multi_slot_class_present;
    kal_uint8 high_multi_slot_class;
#endif
    /* eo Lanslo */
} ms_capability_from_mrs_struct;

/* The structure is defined here, but the variables are stored in rr_cntx_info.
   Because they are obtained from RATCM initialization procedure, not MRS .*/
typedef struct {
    kal_uint8 non_drx_timer;
    kal_uint8 split_on_ccch;
    kal_uint16 split_pg_cycle;
} ms_capability_from_nas_struct;

typedef struct {
    access_technology_type_enum serving_band;
    kal_uint8 band_indicator;
    kal_uint8 msc_r;
} gas_serving_cell_info_struct;

typedef enum{
    GSM_POWER_CLASS_1,
    GSM_POWER_CLASS_2,
    GSM_POWER_CLASS_3,
    GSM_POWER_CLASS_4,
    GSM_POWER_CLASS_5,
    GSM_POWER_CLASS_INVALID = -1      /* for non-supported band */
}mrs_gsm_power_class_enum;

typedef struct{
    mrs_gsm_power_class_enum  pow_class_band450;
    mrs_gsm_power_class_enum  pow_class_band480;
    mrs_gsm_power_class_enum  pow_class_band710;
    mrs_gsm_power_class_enum  pow_class_band750;
    mrs_gsm_power_class_enum  pow_class_band810;
    mrs_gsm_power_class_enum  pow_class_band850;
    mrs_gsm_power_class_enum  pow_class_band900P;
    mrs_gsm_power_class_enum  pow_class_band900E;
    mrs_gsm_power_class_enum  pow_class_band900R;
    mrs_gsm_power_class_enum  pow_class_band1800;
    mrs_gsm_power_class_enum  pow_class_band1900;
}mrs_gsm_power_class_struct;


typedef struct {

    ms_capability_from_mrs_struct ms_capability;
    kal_uint8 ms_classmark3_len;    /* The bit length of Classmark3 */
    kal_uint8 ms_classmark3_R98_len;    /* The bit length of Classmark3 when MS supports Release 98 */
    kal_uint8 ms_default_classmark2[RR_NVRAM_CLK2_LEN]; /* read from nvram and has been decoded as power on */    
    kal_uint8 ms_classmark2[RR_NVRAM_CLK2_LEN];
    kal_uint8 ms_full_classmark2[RR_FULL_CLK2_LEN];
    kal_uint8 ms_classmark3[RR_NVRAM_CLK3_LEN];    
    rat_enum   rat_mode;
    /* GSM supported band */
    kal_uint8    gsm_supported_band;
    kal_bool     is_test_sim;
    gas_serving_cell_info_struct  serving_cell_info;

#ifdef __LTE_RAT__
    eutran_cap_enum    eutran_cap;
#endif /* __LTE_RAT__ */

#ifdef __UMTS_FDD_MODE__   
    /* record the bit location for UMTS FDD RAT Capibility; this bit 
     * is set to 1 only when the MS is in GSM+UMTS dual mode 
     */    
    kal_uint8 cm3_umts_fdd_bit_location;
#endif /* __UMTS_FDD_MODE__ */

#ifdef __UMTS_TDD128_MODE__
    /* record the bit location for UMTS TDD RAT Capibility; 
     * this bit is set to 1 only when the MS is in GSM+UMTS dual mode 
     */    
    kal_uint8 cm3_umts_tdd_bit_location;    
#endif /* __UMTS_TDD128_MODE__ */

#ifdef __VAMOS_1__
    /* record the bit location for VAMOS level setting. */
    kal_uint8 cm3_vamos_bit_location;
    kal_uint8 inject_vamos;
    kal_uint8 vamos_level_from_nvram;
#endif /* __VAMOS_1__ */

#ifdef __GERAN_R8__
    /* record the bit location for R8 Capibility; 
     * this bit is set to 1 only when the MS is in GSM+LTE 
     * dual mode or GSM+UMTS+LTE triple mode
     */    
    kal_uint8 cm3_r8_bit_location;    
#endif /* __GERAN_R8__ */

#if defined(__EGPRS_MODE__)
    kal_bool is_epsk_tx_enabled;
#endif

#ifdef __AGPS_CONTROL_PLANE__
    kal_bool agps_supported_in_clk;
#endif /* __AGPS_CONTROL_PLANE__ */ 

#ifdef __PS_SERVICE__
    kal_bool inject_ra_cap_normal_coding;
    /* Katie 20130304: add inject to turn off R8R9 capability for CRTUG 44.2.10 */
    kal_bool inject_ra_cap_turn_R8R9_off;
#endif /* __PS_SERVICE__ */

    /* store the nvram CLK in context to allow set gas band without reboot */
    kal_uint8 *ms_classmark_in_nvram_ptr;
    kal_uint8 ms_classmark_in_nvram_len;

} gas_capability_context_struct;

/*****************************************************************************
 * Declarations Of Exported Globals
 *****************************************************************************/
#ifdef __GSM_RAT__ 
void mrs_gas_init_contx_default_value(void);

extern void mrs_gas_reset(void);

extern void mrs_gas_get_ms_capability(MRS_SIM_INDEX sim_index, gas_capability_context_struct *gas_ms_cap_ptr);

extern kal_uint8 *mrs_gas_get_classmark1 (MRS_SIM_INDEX sim_index, MRS_RAT_MODE_TYPE required_rat);

extern void mrs_gas_get_classmark3 (MRS_SIM_INDEX sim_index, bit_stream *bs_ptr);

extern kal_uint8 mrs_gas_get_classmark3msg_len(MRS_SIM_INDEX sim_index);

extern kal_bool mrs_gas_get_ucs2_support(MRS_SIM_INDEX sim_index);

extern void mrs_gas_set_sim_type(MRS_SIM_INDEX sim_index, kal_bool is_test_sim);

extern kal_uint8 mrs_gas_get_gsm_algo_support(MRS_SIM_INDEX sim_index);

#ifdef __PS_SERVICE__
extern kal_uint8 mrs_gas_get_radio_access_cap (MRS_SIM_INDEX sim_index, kal_uint8 support_band, kal_uint8 **ra_cap);
extern kal_uint8 mrs_mac_get_radio_access_cap(MRS_SIM_INDEX sim_index, kal_uint8 support_band, kal_uint8 **ra_cap, kal_bool *is_truncated, const kal_bool is_exclude_A5, const kal_uint8 bit_len_limit);
#endif /* __PS_SERVICE__ */

extern kal_bool mrs_gas_get_2g3_ps_ho_cap (MRS_SIM_INDEX sim_index, rat_enum rat_mode);

extern kal_bool mrs_gas_get_2g4_ps_ho_cap (MRS_SIM_INDEX sim_index, rat_enum rat_mode);

extern kal_bool mrs_gas_get_ir_srvcc_cap (MRS_SIM_INDEX sim_index, rat_enum rat_mode);

extern void mrs_gas_update_serving_cell_info(MRS_SIM_INDEX sim_index, gas_serving_cell_info_struct serving_cell_info);

extern void mrs_gas_update_current_rat_mode(MRS_SIM_INDEX sim_index, rat_enum rat_mode);

extern kal_bool mrs_gas_validate_arfcn(MRS_SIM_INDEX sim_index, kal_uint16 arfcn, te_gsm_band_indicator band_indicator);

extern kal_bool mrs_gas_band_setting_update(MRS_SIM_INDEX sim_index, kal_uint8 * gsm_band_ptr);

#endif /* __GSM_RAT__ */

#ifdef __LTE_RAT__

extern void mrs_gas_update_disable_eutran_cap(MRS_SIM_INDEX sim_index, eutran_cap_enum eutran_cap);

#endif /* __LTE_RAT__ */ 

void mrs_gas_read_nvram_cnf_handler(kal_uint16 nvram_file_id, kal_uint8* data, kal_uint16 len);

extern void mrs_gas_decode_mscap_from_nvram(MRS_SIM_INDEX sim_index, kal_uint8 *bit_ptr);

extern void mrs_gas_decode_ms_capability(MRS_SIM_INDEX sim_index, bit_stream *bit_stream_ptr, kal_bool is_dynmc_cfg);

extern kal_bool mrs_gas_is_R99_supported_in_CS(MRS_SIM_INDEX sim_index);

extern kal_uint8 *mrs_gas_get_classmark2 (MRS_SIM_INDEX sim_index, MRS_RAT_MODE_TYPE required_rat, kal_bool get_full_ie);

extern void mrs_gas_get_powerclass(MRS_SIM_INDEX sim_index, mrs_gsm_power_class_struct *gsm_pow_class);

/************************************************** End of TDD's part **************************************************/

#else

/************************************************* Begin of FDD's part *************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "bitstream.h"
#include "l3_inc_enums.h"
#include "mrs_as_enums.h"



/*****************************************************************************
 * Macros Without Parameters
 *****************************************************************************/


/*****************************************************************************
 * Macros With Parameters
 *****************************************************************************/


/*****************************************************************************
 * Enums without tags
 *****************************************************************************/
    /* Define the needed file size kept in NVRAM */
#define RR_NVRAM_CLK2_LEN           3
    /* Peter, 20080804: change the len of classmark3 */
#define RR_NVRAM_CLK3_LEN           34
#define RR_NVRAM_READ_CLK_LEN       12
#define RR_FULL_CLK2_LEN           5

#define  P_GSM_MASK_IN_NVRAM    0x01
#define  E_GSM_MASK_IN_NVRAM    0x02
#define  DCS_1800_MASK_IN_NVRAM 0x04
#define  GSM_480_MASK_IN_NVRAM  0x01
#define  GSM_450_MASK_IN_NVRAM  0x02

#define ADD_CLASSMARK_INFO_IEI         0x20
#define CLASSMARK_2_IEI                0x33


/*****************************************************************************
 * Type Definitions
 *****************************************************************************/
/* Stucture of supported channel modes */
typedef struct channel_mode_supported_struct
{
    kal_uint8 is_signalling_supp;
    kal_uint8 is_speech_full_or_half_ver_1_supp;
    kal_uint8 is_speech_full_or_half_ver_2_supp;
    kal_uint8 is_speech_full_or_half_ver_3_supp;
    /* ZY: add for AMR-WB */
#ifdef __AMRWB_LINK_SUPPORT__
    kal_uint8 is_speech_full_or_half_ver_4_supp;
    kal_uint8 is_speech_full_or_half_ver_5_supp;
#endif /* __AMRWB_LINK_SUPPORT__ */ 
    kal_uint8 is_data_43_5_dl_or_14_5_ul_supp;
    kal_uint8 is_data_29_0_dl_or_14_5_ul_supp;
    kal_uint8 is_data_43_5_dl_or_29_0_ul_supp;
    kal_uint8 is_data_14_5_dl_or_43_5_ul_supp;
    kal_uint8 is_data_14_5_dl_or_29_0_ul_supp;
    kal_uint8 is_data_29_0_dl_or_43_5_ul_supp;
    kal_uint8 is_data_43_5_radio_intf_rate_supp;
    kal_uint8 is_data_32_0_radio_intf_rate_supp;
    kal_uint8 is_data_29_0_radio_intf_rate_supp;
    kal_uint8 is_data_14_5_radio_intf_rate_supp;
    kal_uint8 is_data_12_0_radio_intf_rate_supp;
    kal_uint8 is_data_06_0_radio_intf_rate_supp;
    kal_uint8 is_data_03_6_radio_intf_rate_supp;
    kal_uint8 is_half_rate_supp;

}
channel_mode_supported_struct;

typedef struct ms_capability_from_mrs_struct
{
    kal_uint8 access_tech[16];
    kal_uint8 power_cap[16];
    kal_uint8 hscsd_multi_slot_class;
    kal_uint8 gprs_multi_slot_class;
    kal_uint8 pseudo_sync_cap;
    kal_uint8 vbs;
    kal_uint8 vgcs;
    kal_uint8 algo_supported;
    kal_uint8 hscsd_multi_slot_class_present;
    kal_uint8 gprs_multi_slot_class_present;
    kal_uint8 revision_level_indicator;
    kal_uint8 gprs_ext_dynamic_cap;
    kal_uint8 gea_supported;
    kal_uint8 sm_cap_gprs;
    kal_uint8 pfc_mode;

    kal_bool early_class_mark_support;
    kal_bool is_l2_random_fill_bits;
    kal_uint8 mm_non_drx_timer_value;
    channel_mode_supported_struct chl_mode_supported;   /* struct of supported channel modes */

    /* Evelyn 20080909 */
    /* Lanslo 20050215: for selecting GPRS or EGPRS capability */
#ifdef __EGPRS_MODE__
    kal_uint8 egprs_multi_slot_class_present;
    kal_uint8 egprs_multi_slot_class;
    kal_uint8 egprs_ext_dynamic_cap;
    //Jelly 20090602 Use __EPSK_TX__
    /* Evelyn 20090422: set difference power class of 8PSK */
#ifdef __EPSK_TX__
    kal_uint8 power_cap_8psk[16];
#endif /* __EPSK_TX__ */
#endif /* __EGPRS_MODE__ */ 

    /* Evelyn 20090905: Modify for High multislot class */
#if defined (__MULTISLOT_CLASS_34__) || defined (__MULTISLOT_CLASS_45__)
    kal_uint8 high_multi_slot_class_present;
    kal_uint8 high_multi_slot_class;
#endif
    /* eo Lanslo */
} ms_capability_from_mrs_struct;

/* The structure is defined here, but the variables are stored in rr_cntx_info.
   Because they are obtained from RATCM initialization procedure, not MRS .*/
typedef struct {
    kal_uint8 non_drx_timer;
    kal_uint8 split_on_ccch;
    kal_uint16 split_pg_cycle;
} ms_capability_from_nas_struct;

typedef struct {
    access_technology_type_enum serving_band;
    kal_uint8 band_indicator;
    kal_uint8 msc_r;
} gas_serving_cell_info_struct;

typedef enum{
    GSM_POWER_CLASS_1,
    GSM_POWER_CLASS_2,
    GSM_POWER_CLASS_3,
    GSM_POWER_CLASS_4,
    GSM_POWER_CLASS_5,
    GSM_POWER_CLASS_INVALID = -1      /* for non-supported band */
}mrs_gsm_power_class_enum;

typedef struct{
    mrs_gsm_power_class_enum  pow_class_band450;
    mrs_gsm_power_class_enum  pow_class_band480;
    mrs_gsm_power_class_enum  pow_class_band710;
    mrs_gsm_power_class_enum  pow_class_band750;
    mrs_gsm_power_class_enum  pow_class_band810;
    mrs_gsm_power_class_enum  pow_class_band850;
    mrs_gsm_power_class_enum  pow_class_band900P;
    mrs_gsm_power_class_enum  pow_class_band900E;
    mrs_gsm_power_class_enum  pow_class_band900R;
    mrs_gsm_power_class_enum  pow_class_band1800;
    mrs_gsm_power_class_enum  pow_class_band1900;
}mrs_gsm_power_class_struct;


typedef struct {

    ms_capability_from_mrs_struct ms_capability;
    kal_uint8 ms_classmark3_len;    /* The bit length of Classmark3 */
    kal_uint8 ms_classmark3_R98_len;    /* The bit length of Classmark3 when MS supports Release 98 */
    kal_uint8 ms_default_classmark2[RR_NVRAM_CLK2_LEN]; /* read from nvram and has been decoded as power on */    
    kal_uint8 ms_classmark2[RR_NVRAM_CLK2_LEN];
    kal_uint8 ms_full_classmark2[RR_FULL_CLK2_LEN];
    kal_uint8 ms_classmark3[RR_NVRAM_CLK3_LEN];    
    rat_enum   rat_mode;
    /* GSM supported band */
    kal_uint8    gsm_supported_band;
    kal_bool     is_test_sim;
    gas_serving_cell_info_struct  serving_cell_info;

#ifdef __LTE_RAT__
    eutran_cap_enum    eutran_cap;
#endif /* __LTE_RAT__ */

#ifdef __UMTS_FDD_MODE__   
    /* record the bit location for UMTS FDD RAT Capibility; this bit 
     * is set to 1 only when the MS is in GSM+UMTS dual mode 
     */    
    kal_uint8 cm3_umts_fdd_bit_location;
#endif /* __UMTS_FDD_MODE__ */

#ifdef __UMTS_TDD128_MODE__
    /* record the bit location for UMTS TDD RAT Capibility; 
     * this bit is set to 1 only when the MS is in GSM+UMTS dual mode 
     */    
    kal_uint8 cm3_umts_tdd_bit_location;    
#endif /* __UMTS_TDD128_MODE__ */

#ifdef __VAMOS_1__
    /* record the bit location for VAMOS level setting. */
    kal_uint8 cm3_vamos_bit_location;
    kal_uint8 inject_vamos;
    kal_uint8 vamos_level_from_nvram;
#endif /* __VAMOS_1__ */

#ifdef __GERAN_R8__
    /* record the bit location for R8 Capibility; 
     * this bit is set to 1 only when the MS is in GSM+LTE 
     * dual mode or GSM+UMTS+LTE triple mode
     */    
    kal_uint8 cm3_r8_bit_location;    
#endif /* __GERAN_R8__ */

#if defined(__EGPRS_MODE__)
    kal_bool is_epsk_tx_enabled;
#endif

#ifdef __AGPS_CONTROL_PLANE__
    kal_bool agps_supported_in_clk;
#endif /* __AGPS_CONTROL_PLANE__ */ 

#ifdef __PS_SERVICE__
    kal_bool inject_ra_cap_normal_coding;
    /* Katie 20130304: add inject to turn off R8R9 capability for CRTUG 44.2.10 */
    kal_bool inject_ra_cap_turn_R8R9_off;
#endif /* __PS_SERVICE__ */

    /* store the nvram CLK in context to allow set gas band without reboot */
    kal_uint8 *ms_classmark_in_nvram_ptr;
    kal_uint8 ms_classmark_in_nvram_len;

} gas_capability_context_struct;

/*****************************************************************************
 * Declarations Of Exported Globals
 *****************************************************************************/
#ifdef __GSM_RAT__ 
void mrs_gas_init_contx_default_value(void);

extern void mrs_gas_reset(void);

extern void mrs_gas_get_ms_capability(MRS_SIM_INDEX sim_index, gas_capability_context_struct *gas_ms_cap_ptr);

extern kal_uint8 *mrs_gas_get_classmark1 (MRS_SIM_INDEX sim_index, MRS_RAT_MODE_TYPE required_rat);

extern void mrs_gas_get_classmark3 (MRS_SIM_INDEX sim_index, bit_stream *bs_ptr);

extern kal_uint8 mrs_gas_get_classmark3msg_len(MRS_SIM_INDEX sim_index);

extern kal_bool mrs_gas_get_ucs2_support(MRS_SIM_INDEX sim_index);

extern void mrs_gas_set_sim_type(MRS_SIM_INDEX sim_index, kal_bool is_test_sim);

extern kal_uint8 mrs_gas_get_gsm_algo_support(MRS_SIM_INDEX sim_index);

#ifdef __PS_SERVICE__
extern kal_uint8 mrs_gas_get_radio_access_cap (MRS_SIM_INDEX sim_index, kal_uint8 support_band, kal_uint8 **ra_cap);
extern kal_uint8 mrs_mac_get_radio_access_cap(MRS_SIM_INDEX sim_index, kal_uint8 support_band, kal_uint8 **ra_cap, kal_bool *is_truncated, const kal_bool is_exclude_A5, const kal_uint8 bit_len_limit);
#endif /* __PS_SERVICE__ */

extern kal_bool mrs_gas_get_2g3_ps_ho_cap (MRS_SIM_INDEX sim_index, rat_enum rat_mode);

extern kal_bool mrs_gas_get_2g4_ps_ho_cap (MRS_SIM_INDEX sim_index, rat_enum rat_mode);

extern kal_bool mrs_gas_get_ir_srvcc_cap (MRS_SIM_INDEX sim_index, rat_enum rat_mode);

extern void mrs_gas_update_serving_cell_info(MRS_SIM_INDEX sim_index, gas_serving_cell_info_struct serving_cell_info);

extern void mrs_gas_update_current_rat_mode(MRS_SIM_INDEX sim_index, rat_enum rat_mode);

extern kal_bool mrs_gas_validate_arfcn(MRS_SIM_INDEX sim_index, kal_uint16 arfcn, te_gsm_band_indicator band_indicator);

extern kal_bool mrs_gas_band_setting_update(MRS_SIM_INDEX sim_index, kal_uint8 * gsm_band_ptr);

#endif /* __GSM_RAT__ */

#ifdef __LTE_RAT__

extern void mrs_gas_update_disable_eutran_cap(MRS_SIM_INDEX sim_index, eutran_cap_enum eutran_cap);

#endif /* __LTE_RAT__ */ 

void mrs_gas_read_nvram_cnf_handler(kal_uint16 nvram_file_id, kal_uint8* data, kal_uint16 len);

extern void mrs_gas_decode_mscap_from_nvram(MRS_SIM_INDEX sim_index, kal_uint8 *bit_ptr);

extern void mrs_gas_decode_ms_capability(MRS_SIM_INDEX sim_index, bit_stream *bit_stream_ptr, kal_bool is_dynmc_cfg);

extern kal_bool mrs_gas_is_R99_supported_in_CS(MRS_SIM_INDEX sim_index);

extern kal_uint8 *mrs_gas_get_classmark2 (MRS_SIM_INDEX sim_index, MRS_RAT_MODE_TYPE required_rat, kal_bool get_full_ie);

extern void mrs_gas_get_powerclass(MRS_SIM_INDEX sim_index, mrs_gsm_power_class_struct *gsm_pow_class);

/************************************************** End of FDD's part **************************************************/

#endif


#endif /* _MRS_GAS_CAPABILITY_H */

