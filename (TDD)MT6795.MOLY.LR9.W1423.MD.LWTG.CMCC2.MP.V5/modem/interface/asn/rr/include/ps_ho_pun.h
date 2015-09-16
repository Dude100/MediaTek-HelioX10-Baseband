/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : ps_ho_pun.h
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
#ifndef _PS_HO_PUN_H
#define _PS_HO_PUN_H
#define rrc_container_ie_size(x) 1
IMP unsigned int rrc_container_ie_bits(void *);
IMP void rrc_container_ie_alloc(void *);
IMP void rrc_container_ie_dealloc(void *);
IMP unsigned int rrc_container_ie_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int rrc_container_ie_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define nas_container_ie_size(x) 1
IMP unsigned int nas_container_ie_bits(void *);
IMP void nas_container_ie_alloc(void *);
IMP void nas_container_ie_dealloc(void *);
IMP unsigned int nas_container_ie_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int nas_container_ie_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int global_and_extended_timing_adv_struct_bits(void *);
IMP void global_and_extended_timing_adv_struct_alloc(void *);
IMP void global_and_extended_timing_adv_struct_dealloc(void *);
IMP unsigned int global_and_extended_timing_adv_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int global_and_extended_timing_adv_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ps_ho_downlink_tbf_assign_struct_bits(void *);
IMP void ps_ho_downlink_tbf_assign_struct_alloc(void *);
IMP void ps_ho_downlink_tbf_assign_struct_dealloc(void *);
IMP unsigned int ps_ho_downlink_tbf_assign_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ps_ho_downlink_tbf_assign_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ps_ho_edge_dl_struct_bits(void *);
IMP void ps_ho_edge_dl_struct_alloc(void *);
IMP void ps_ho_edge_dl_struct_dealloc(void *);
IMP unsigned int ps_ho_edge_dl_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ps_ho_edge_dl_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ps_ho_edge_dl_exist_bits(void *);
IMP void ps_ho_edge_dl_exist_alloc(void *);
IMP void ps_ho_edge_dl_exist_dealloc(void *);
IMP unsigned int ps_ho_edge_dl_exist_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ps_ho_edge_dl_exist_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int gprs_mode_struct_bits(void *);
IMP void gprs_mode_struct_alloc(void *);
IMP void gprs_mode_struct_dealloc(void *);
IMP unsigned int gprs_mode_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprs_mode_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int egprs_mode_struct_bits(void *);
IMP void egprs_mode_struct_alloc(void *);
IMP void egprs_mode_struct_dealloc(void *);
IMP unsigned int egprs_mode_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int egprs_mode_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ps_ho_radio_resource_struct_bits(void *);
IMP void ps_ho_radio_resource_struct_alloc(void *);
IMP void ps_ho_radio_resource_struct_dealloc(void *);
IMP unsigned int ps_ho_radio_resource_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ps_ho_radio_resource_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ps_ho_to_geran_struct_bits(void *);
IMP void ps_ho_to_geran_struct_alloc(void *);
IMP void ps_ho_to_geran_struct_dealloc(void *);
IMP unsigned int ps_ho_to_geran_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ps_ho_to_geran_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ps_ho_command_struct_bits(void *);
IMP void ps_ho_command_struct_alloc(void *);
IMP void ps_ho_command_struct_dealloc(void *);
IMP unsigned int ps_ho_command_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ps_ho_command_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#endif 
