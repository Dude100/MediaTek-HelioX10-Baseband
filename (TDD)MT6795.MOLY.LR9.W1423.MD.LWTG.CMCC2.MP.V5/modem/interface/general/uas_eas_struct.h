#ifndef _UAS_EAS_STRUCT_H
#define _UAS_EAS_STRUCT_H

#include "irat_common_enums.h"
#include "irat_common_struct.h"
#include "uas_eas_enums.h"
#include "mcd_l3_inc_struct.h"
#include "csi_umts_asn.h"

/* Measurement results related: UAS to/from EAS */


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __UMTS_FDD_MODE__
typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  ir_umts_measured_result ir_umts_meas_info;
  kal_bool isLongPeriod;
#ifdef UNIT_TEST
  kal_uint32 meas_ind_ms_diff;
#endif /* UNIT_TEST */
}eas_uas_ucell_meas_ind_struct;
#endif/*__UMTS_FDD_MODE__*/

#ifdef __UMTS_TDD128_MODE__
typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  ts_ir_umts_meas_info ir_umts_meas_info;
  kal_bool isLongPeriod;
#ifdef UNIT_TEST
  kal_uint32 meas_ind_ms_diff;
#endif /* UNIT_TEST */
}eas_uas_ucell_meas_ind_struct;
#endif/*__UMTS_TDD128_MODE__*/

typedef struct
{
  LOCAL_PARA_HDR
  kal_uint8 tid;
  kal_uint8 freq_num;
  eas_meas_freq_rslt_struct freq[MAX_MEAS_IRAT_FREQ];
} uas_eas_lte_measurement_ind_struct;

/* Measurement request/confirm related: UAS to/from EAS */
typedef struct
{
  LOCAL_PARA_HDR
  kal_uint8 tid;
  kal_bool hps_flag;
  kal_uint8 prio_meas_period;
  kal_uint8 freq_num;
  eas_meas_freq_info_struct freq[MAX_MEAS_IRAT_FREQ];
} uas_eas_lte_measurement_req_struct;

typedef struct
{
  LOCAL_PARA_HDR
  kal_uint8 freq_num;
  eas_hps_qualify_struct freq[MAX_MEAS_IRAT_FREQ];
  /* This flag is used to indicate whether measurement period should be reset
   * immediately. (TRUE:  meas is performed in the first DRX. 
   *               FALSE: meas is performed in the first T-meas occasion)  
   * In current design, the following rules should be followed.
   * (1)If freq_num != 0, this flag will be set as FALSE only if tmeasure measurement 
   *                      is triggered when priority measurement is on-going (i.e., at 
   *                      least one of LTE cells hits priority reselection criteria for 
   *                      priority based measurement reselection). If any improvement is 
   *                      needed, the usage limitation for this flag should be confirmed 
   *                      with EL1's colleague.
   * (2) If freq_num == 0, this flag will alwyas be set as FALSE;
   */
  kal_bool is_meas_period_reset;
} uas_eas_lte_hps_qualify_cell_ind_struct;

typedef struct {
  LOCAL_PARA_HDR
} uas_eas_lte_measurement_cnf_struct;

/* Measurement request/confirm related: EAS to UAS */
#ifdef __UMTS_FDD_MODE__
typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  kal_int16 prio_meas_period;
  CsiUmtsCellList umts_cell_list;
  kal_int8 fdd_rscp_min_in_dbm; //TBC with LTE
  kal_uint16 first_meas_uarfcn; // invalid value = -1
  kal_bool is_detected_cell_meas[3];
} eas_uas_config_ucell_prio_meas_req_struct;
#endif/*__UMTS_FDD_MODE__*/
#ifdef __UMTS_TDD128_MODE__
typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  kal_int16 prio_meas_period;
  CsiUmtsCellList umts_cell_list;//numElements in CsiUmtsCellListOnTheCarrier must be 0
//  kal_int8 fdd_rscp_min_in_dbm; //TBC with LTE, FDD only
  kal_uint16 first_meas_uarfcn; // invalid value = -1//TBD, for CSFB, whether report meas result per freq?
  kal_bool is_detected_cell_meas[9];
} eas_uas_config_ucell_prio_meas_req_struct;
#endif/*__UMTS_TDD128_MODE__*/

#ifdef __UMTS_FDD_MODE__
typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  CsiUmtsCellList umts_cell_list;
  kal_int8 fdd_rscp_min_in_dbm; //TBC with LTE
  kal_uint16 first_meas_uarfcn; // invalid value = -1
  kal_bool is_detected_cell_meas[3];
  /* This flag is used to indicate whether measurement period should be reset
   * immediately. (TRUE:  meas is performed in the first DRX. 
   *               FALSE: meas is performed in the first T-meas occasion)  
   * In current design, the following rules should be followed.
   * (1)If number of ARFCN != 0, this flag will be set as FALSE only if tmeasure measurement 
   *                             is triggered when priority measurement is on-going (i.e., at least 
   *                             one of UMTS cells hits priority reselection criteria for priority 
   *                             based measurement reselection). For other case, this flag should 
   *                             be set as TRUE. If any improvement is needed, the usage limitation 
   *                             for this flag should be confirmed with UL1's colleague.
   * (2) If number of ARFCN == 0, this flag will alwyas be set as FALSE;
   */
  kal_bool is_meas_period_reset;
  
  /* When this flag is set to TRUE, the standby measurement will be performed every T-meas without */
  /* multiplying by N layers. So that there will be 2 measurement results within 10s OOS period, which */
  /* increases the successful rate of finding a candidate during OOS */
  kal_bool prohibit_apply_n_layer;
} eas_uas_config_ucell_meas_req_struct;
#endif/*__UMTS_FDD_MODE__*/
#ifdef __UMTS_TDD128_MODE__
typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  CsiUmtsCellList umts_cell_list;
  //kal_int8 fdd_rscp_min_in_dbm; //TBC with LTE, FDD only
  kal_uint16 first_meas_uarfcn; // invalid value = -1//TBD, for CSFB, whether report meas result per freq?
  kal_bool is_detected_cell_meas[9];
  kal_bool  is_meas_period_reset;
  
  /* When this flag is set to TRUE, the standby measurement will be performed every T-meas without */
  /* multiplying by N layers. So that there will be 2 measurement results within 10s OOS period, which */
  /* increases the successful rate of finding a candidate during OOS */
  kal_bool prohibit_apply_n_layer;
} eas_uas_config_ucell_meas_req_struct;
#endif/*__UMTS_TDD128_MODE__*/

typedef struct {
  LOCAL_PARA_HDR
} eas_uas_config_ucell_prio_meas_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
} eas_uas_config_ucell_meas_cnf_struct;


typedef struct{
  kal_bool   is_lac_valid;
  kal_uint16 lac;
  kal_bool   is_rac_valid;
  kal_uint8  rac;
} ucell_cgi_info_optional_struct;

typedef struct{
    cgi_info_status_enum cgi_info_status;
    kal_uint32 cell_id;
    kal_uint8  num_plmn_id_list;
    plmn_id_struct plmn_id_list[6]; //MAX_NUM_PLMN_ID
    csg_access_mode_enum ucell_type;
    kal_uint32     csg_id;
    ucell_cgi_info_optional_struct optional_field;
} ucell_cgi_info_struct;

typedef struct {
    LOCAL_PARA_HDR
    plmn_search_type_enum	plmn_search_type;
    auto_search_cmd_enum auto_search_cmd;
    kal_uint8  num_carriers;
    kal_uint16 csg_uarfcn[MAX_NUM_CSG_CARRIERS];
} eas_uas_search_csg_ucell_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    search_status_enum search_status;
    kal_uint8 num_carriers;
    ts_3G_csg_ucell_evluation_result csg_ucell_evluation_result_list[MAX_NUM_CSG_CARRIERS];
} eas_uas_search_csg_ucell_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    plmn_search_type_enum	plmn_search_type;
    auto_search_cmd_enum auto_search_cmd;
    kal_uint8  num_carriers;
    kal_uint16 csg_uarfcn[MAX_NUM_CSG_CARRIERS];
} eas_uas_evaluate_csg_ucell_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    search_status_enum search_status;
    kal_uint8 num_carriers;
    ts_3G_csg_ucell_evluation_result csg_ucell_evluation_result_list[MAX_NUM_CSG_CARRIERS];
} eas_uas_evaluate_csg_ucell_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    plmn_search_type_enum plmn_search_type;
    auto_search_cmd_enum auto_search_cmd;
    kal_uint8  num_freq;
    kal_uint16 freq_list[MAX_NUM_CSG_FREQ];
} uas_eas_search_csg_ecell_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    search_status_enum search_status;
    kal_uint8 num_csg_freq_search_result;
    csg_freq_search_result_struct csg_freq_search_result_list[MAX_NUM_CSG_FREQ];
} uas_eas_search_csg_ecell_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    plmn_search_type_enum plmn_search_type;
    auto_search_cmd_enum auto_search_cmd;
    kal_uint8  num_freq;
    kal_uint16 freq_list[MAX_NUM_CSG_FREQ];
} uas_eas_evaluate_csg_ecell_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    search_status_enum search_status;
    kal_uint8 num_csg_freq_search_result;
    csg_freq_search_result_struct csg_freq_search_result_list[MAX_NUM_CSG_FREQ];
} uas_eas_evaluate_csg_ecell_cnf_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 tid;
    report_cgi_req_type_enum report_cgi_req_type;
    kal_uint16 uarfcn;
    kal_uint16 physical_cell_id;
} eas_uas_report_cgi_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8  tid;
    kal_uint16 uarfcn;
    kal_uint16 physical_cell_id;
    ucell_cgi_info_struct ucell_cgi_info;
} eas_uas_report_cgi_cnf_struct;

typedef struct{
    LOCAL_PARA_HDR
    te_ir_cell_change_trigger ir_cell_change_trigger;
    plmn_search_type_enum plmn_search_type;
    ts_umts_target_cell target_cell;
} eas_uas_evaluate_ucell_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    te_ir_cell_reselection_status ir_cell_eval_status;
    ts_eval_activate_fail_handle  Eval_activate_fail_handle;
} eas_uas_evaluate_ucell_cnf_struct;

typedef struct {
   kal_uint16 phys_cell_id;
   kal_uint16 BCCH_Container_size; // 0 ~ max_size 
   kal_uint8  *BCCH_container; /* note: remember to Free the memory here*/
} ts_ir_utra_cell_info;

typedef struct {
   kal_uint16 uarfcn;
   kal_uint8 cell_info_num;
   ts_ir_utra_cell_info cell_info[MAX_NUM_CELL_INFO_UTRA];
} ts_ir_utra_cell_info_list;

typedef struct {
   kal_uint8 numElements;
   ts_ir_utra_cell_info_list element[MAX_NUM_REDIRECTION_FREQ_UTRA];
} eas_uas_redirectInfo;

typedef struct{
    LOCAL_PARA_HDR
    te_ir_cell_change_trigger ir_cell_change_trigger;
    plmn_search_type_enum plmn_search;
    ts_umts_target_cell target_cell;
    kal_uint16 ircco_time;
    eas_uas_redirectInfo redirection;
} eas_uas_activate_ucell_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    te_ir_cell_reselection_status      ir_cell_activation_status;
    ts_eval_activate_fail_handle       eval_activate_fail_handle;
    te_ir_cell_change_fail_reason_enum ir_cell_change_failed_reason;
} eas_uas_activate_ucell_cnf_struct;

/* For 3G4 IRHO */
typedef struct {
   LOCAL_PARA_HDR
   kal_bool    is_limited_service;
   plmn_search_type_enum	plmn_search_type;
} uas_eas_handover_ecell_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   /* No parameters here */
} uas_eas_ho_activate_ecell_req_struct;

/* For 3G4 IRCR or IR Redirection */
typedef struct {
   LOCAL_PARA_HDR
   eas_target_cell_info   target_cell;
   plmn_search_type_enum  plmn_search_type;
   /*3G4 background search parameter*/
   kal_bool               is_background_search_trigger;
   uas_cell_info          serving_cell_info;
} uas_eas_evaluate_ecell_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   /* No parameters here */
} uas_eas_evaluate_ecell_stop_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   te_ir_cell_change_trigger  trigger;
   kal_uint32                 wait_time;
   eas_target_cell_info       target_cell;
   plmn_search_type_enum      plmn_search_type;
   kal_uint8                  redirect_freq_num;
   lte_redirect_info          redirect_freq_info[MAX_UAS_EAS_REDIRECT_FREQ_NUM];
} uas_eas_activate_ecell_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   te_ir_handover_status  ho_to_eas_status;
   kal_uint8  nas_sec_param_to_eutra[NAS_SECURITY_PARAM_LEN];
} uas_eas_handover_ecell_cnf_struct;

typedef struct {
   LOCAL_PARA_HDR
   te_ir_handover_status  ho_to_eas_status;
} uas_eas_ho_activate_ecell_cnf_struct;

typedef struct {
   LOCAL_PARA_HDR
   te_ir_cell_reselection_status  eval_status;
   ts_eval_activate_fail_handle   eval_activate_fail_handle;
} uas_eas_evaluate_ecell_cnf_struct;

typedef struct {
   LOCAL_PARA_HDR
   /* No parameters here */
} uas_eas_evaluate_ecell_stop_cnf_struct;

typedef struct {
   LOCAL_PARA_HDR
   te_ir_cell_reselection_status  active_status;
   ts_eval_activate_fail_handle   eval_activate_fail_handle;
} uas_eas_activate_ecell_cnf_struct;

typedef struct {
   LOCAL_PARA_HDR
   /* No parameters here */
} uas_eas_abort_ho_ecell_req_struct;

/* For 4G3 IRHO */
typedef struct {
   LOCAL_PARA_HDR
   plmn_search_type_enum  plmn_search_type;
} eas_uas_handover_ucell_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   /* No parameters here */
} eas_uas_ho_activate_ucell_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   /* No parameters here */
} eas_uas_abort_ho_ucell_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   ho_from_lte_type_enum  lte_ho_type;
   te_ir_handover_status  ir_ho_eval_status;
   kal_uint16             uarfcn_DL;
} eas_uas_handover_ucell_cnf_struct;

typedef struct {
   LOCAL_PARA_HDR
   te_ir_handover_status  ir_ho_activate_status;
} eas_uas_ho_activate_ucell_cnf_struct;

/*3G4 background search*/
typedef struct {
   LOCAL_PARA_HDR
   /* No parameters here */
} uas_eas_background_search_start_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   /* No parameters here */
} uas_eas_background_search_stop_req_struct;

/* __4G_BACKGROUND_SEARCH__ */
typedef struct {
   LOCAL_PARA_HDR
   /* LTE detected cell info */
   kal_uint16         earfcn;
   kal_uint16         pci;   
} eas_uas_background_search_found_ind_struct;

#endif  /* UAS_EAS_STRUCT_H */
