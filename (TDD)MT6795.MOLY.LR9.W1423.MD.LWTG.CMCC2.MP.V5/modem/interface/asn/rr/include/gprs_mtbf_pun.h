/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : gprs_mtbf_pun.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */

 /* Evelyn 20090415: Merge R6 */

#ifdef MTK_PEER 
#define IMP __declspec(dllimport) 
#else 
#define IMP 
#endif 
#ifndef _GPRS_MTBF_PUN_H
#define _GPRS_MTBF_PUN_H
#define tlli_g_rnti_struct_size(x) 5
IMP unsigned int tlli_g_rnti_struct_bits(void *);
IMP void tlli_g_rnti_struct_alloc(void *);
IMP void tlli_g_rnti_struct_dealloc(void *);
IMP unsigned int tlli_g_rnti_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int tlli_g_rnti_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define bts_mode_modify_struct_size(x) 1
IMP unsigned int bts_mode_modify_struct_bits(void *);
IMP void bts_mode_modify_struct_alloc(void *);
IMP void bts_mode_modify_struct_dealloc(void *);
IMP unsigned int bts_mode_modify_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int bts_mode_modify_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int egprs_window_size_struct_bits(void *);
IMP void egprs_window_size_struct_alloc(void *);
IMP void egprs_window_size_struct_dealloc(void *);
IMP unsigned int egprs_window_size_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int egprs_window_size_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int hfn_lsb_struct_bits(void *);
IMP void hfn_lsb_struct_alloc(void *);
IMP void hfn_lsb_struct_dealloc(void *);
IMP unsigned int hfn_lsb_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int hfn_lsb_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int mtbf_downlink_tbf_assign_struct_bits(void *);
IMP void mtbf_downlink_tbf_assign_struct_alloc(void *);
IMP void mtbf_downlink_tbf_assign_struct_dealloc(void *);
IMP unsigned int mtbf_downlink_tbf_assign_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int mtbf_downlink_tbf_assign_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define pfi_rlcmode_struct_size(x) 1
IMP unsigned int pfi_rlcmode_struct_bits(void *);
IMP void pfi_rlcmode_struct_alloc(void *);
IMP void pfi_rlcmode_struct_dealloc(void *);
IMP unsigned int pfi_rlcmode_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pfi_rlcmode_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int tbf_address_rel6_struct_bits(void *);
IMP void tbf_address_rel6_struct_alloc(void *);
IMP void tbf_address_rel6_struct_dealloc(void *);
IMP unsigned int tbf_address_rel6_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int tbf_address_rel6_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *, kal_bool);

IMP unsigned int downlink_tbf_assign_struct_bits(void *);
IMP void downlink_tbf_assign_struct_alloc(void *);
IMP void downlink_tbf_assign_struct_dealloc(void *);
IMP unsigned int downlink_tbf_assign_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int downlink_tbf_assign_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int egprsdl_assign_additions_mtbf_struct_bits(void *);
IMP void egprsdl_assign_additions_mtbf_struct_alloc(void *);
IMP void egprsdl_assign_additions_mtbf_struct_dealloc(void *);
IMP unsigned int egprsdl_assign_additions_mtbf_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int egprsdl_assign_additions_mtbf_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int mtbf_downlink_assign_bits(void *);
IMP void mtbf_downlink_assign_alloc(void *);
IMP void mtbf_downlink_assign_dealloc(void *);
IMP unsigned int mtbf_downlink_assign_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int mtbf_downlink_assign_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int gamma_choise_struct_bits(void *);
IMP void gamma_choise_struct_alloc(void *);
IMP void gamma_choise_struct_dealloc(void *);
IMP unsigned int gamma_choise_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gamma_choise_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int alpha_gamma_choise_struct_bits(void *);
IMP void alpha_gamma_choise_struct_alloc(void *);
IMP void alpha_gamma_choise_struct_dealloc(void *);
IMP unsigned int alpha_gamma_choise_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int alpha_gamma_choise_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int timeslot_desc_struct_bits(void *);
IMP void timeslot_desc_struct_alloc(void *);
IMP void timeslot_desc_struct_dealloc(void *);
IMP unsigned int timeslot_desc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int timeslot_desc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *, kal_bool);

IMP unsigned int usf_alloc_struct_bits(void *);
IMP void usf_alloc_struct_alloc(void *);
IMP void usf_alloc_struct_dealloc(void *);
IMP unsigned int usf_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int usf_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int different_usf_alloc_struct_bits(void *);
IMP void different_usf_alloc_struct_alloc(void *);
IMP void different_usf_alloc_struct_dealloc(void *);
IMP unsigned int different_usf_alloc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int different_usf_alloc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *, unsigned int);

IMP unsigned int uplink_tbf_assign_struct_bits(void *);
IMP void uplink_tbf_assign_struct_alloc(void *);
IMP void uplink_tbf_assign_struct_dealloc(void *);
IMP unsigned int uplink_tbf_assign_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int uplink_tbf_assign_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *, unsigned int, kal_bool);

IMP unsigned int uplink_assign_struct_bits(void *);
IMP void uplink_assign_struct_alloc(void *);
IMP void uplink_assign_struct_dealloc(void *);
IMP unsigned int uplink_assign_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int uplink_assign_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int gprs_uplink_assign_mtbf_struct_bits(void *);
IMP void gprs_uplink_assign_mtbf_struct_alloc(void *);
IMP void gprs_uplink_assign_mtbf_struct_dealloc(void *);
IMP unsigned int gprs_uplink_assign_mtbf_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprs_uplink_assign_mtbf_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int egprs_uplink_assign_mtbf_struct_bits(void *);
IMP void egprs_uplink_assign_mtbf_struct_alloc(void *);
IMP void egprs_uplink_assign_mtbf_struct_dealloc(void *);
IMP unsigned int egprs_uplink_assign_mtbf_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int egprs_uplink_assign_mtbf_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int mtbf_uplink_assign_bits(void *);
IMP void mtbf_uplink_assign_alloc(void *);
IMP void mtbf_uplink_assign_dealloc(void *);
IMP unsigned int mtbf_uplink_assign_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int mtbf_uplink_assign_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ts_reconfig_dl_tbf_assign_struct_bits(void *);
IMP void ts_reconfig_dl_tbf_assign_struct_alloc(void *);
IMP void ts_reconfig_dl_tbf_assign_struct_dealloc(void *);
IMP unsigned int ts_reconfig_dl_tbf_assign_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ts_reconfig_dl_tbf_assign_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ts_reconfig_dl_tbf_assign_mtbf_struct_bits(void *);
IMP void ts_reconfig_dl_tbf_assign_mtbf_struct_alloc(void *);
IMP void ts_reconfig_dl_tbf_assign_mtbf_struct_dealloc(void *);
IMP unsigned int ts_reconfig_dl_tbf_assign_mtbf_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ts_reconfig_dl_tbf_assign_mtbf_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ts_reconfig_ul_assign_struct_bits(void *);
IMP void ts_reconfig_ul_assign_struct_alloc(void *);
IMP void ts_reconfig_ul_assign_struct_dealloc(void *);
IMP unsigned int ts_reconfig_ul_assign_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ts_reconfig_ul_assign_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int gprs_ts_reconfig_mtbf_struct_bits(void *);
IMP void gprs_ts_reconfig_mtbf_struct_alloc(void *);
IMP void gprs_ts_reconfig_mtbf_struct_dealloc(void *);
IMP unsigned int gprs_ts_reconfig_mtbf_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprs_ts_reconfig_mtbf_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int egprs_ts_reconfig_mtbf_struct_bits(void *);
IMP void egprs_ts_reconfig_mtbf_struct_alloc(void *);
IMP void egprs_ts_reconfig_mtbf_struct_dealloc(void *);
IMP unsigned int egprs_ts_reconfig_mtbf_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int egprs_ts_reconfig_mtbf_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int mtbf_timeslot_reconfigure_assign_bits(void *);
IMP void mtbf_timeslot_reconfigure_assign_alloc(void *);
IMP void mtbf_timeslot_reconfigure_assign_dealloc(void *);
IMP unsigned int mtbf_timeslot_reconfigure_assign_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int mtbf_timeslot_reconfigure_assign_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

extern kal_uint8 rr_get_1s_count(kal_uint32 number);
#endif 
