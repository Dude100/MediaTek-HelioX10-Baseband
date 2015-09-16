#ifndef L2TPS_MSG_H
#define L2TPS_MSG_H

#define L2TPS_GEN_TC_ID (0xFFFF)

/* For Gemini CFG */
#define L2TPS_MAX_GEMINI_GAP_PATTERN_NUM 5
#define L2TPS_MAX_GEMINI_VAR_DURN_NUM 5
#define L2TPS_MAX_GEMINI_DURN_SEQ_NUM 10

typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32;

typedef struct
{
		uint16 tc_id;
		uint16 cmd_id;
} l2tps_cmd_hdr_t;

enum
{
	L2TPS_MSG_ID_DL_POLLING,
	L2TPS_MSG_ID_UL_POLLING_RES,
	L2TPS_MSG_ID_DL_TEST_START,
	L2TPS_MSG_ID_DL_TEST_END,
	L2TPS_MSG_ID_DL_UL_DATA_REQ,
	L2TPS_MSG_ID_DL_EST_DRB,
	L2TPS_MSG_ID_DL_ULDL_LB_START,
	L2TPS_MSG_ID_DL_DLUL_LB_START,
	L2TPS_MSG_ID_DL_INITIAL_ACCESS_REQ,
	L2TPS_MSG_ID_DL_ACTIVATE_SRB,
	L2TPS_MSG_ID_DL_HO_RA_REQ,
	L2TPS_MSG_ID_DL_HO_RA_CNF,
	L2TPS_MSG_ID_DL_TA_TIMER_CFG,
	L2TPS_MSG_ID_UL_TA_TIMER_CFG_CNF,
	L2TPS_MSG_ID_DL_DRX_CFG,
	L2TPS_MSG_ID_UL_DRX_CNF,
	L2TPS_MSG_ID_DL_SPS_CFG,
	L2TPS_MSG_ID_UL_SPS_CNF,
	L2TPS_MSG_ID_DL_TTI_BUNDLE_CFG,
	L2TPS_MSG_ID_UL_TTI_BUNDLE_CNF,
	L2TPS_MSG_ID_DL_TTI_BUNDLE_DISABLE_CFG,
	L2TPS_MSG_ID_UL_TTI_BUNDLE_DISABLE_CNF,
	L2TPS_MSG_ID_DL_RA_CFG,
	L2TPS_MSG_ID_UL_RA_CFG_CNF,
	L2TPS_MSG_ID_DL_SR_CFG,
	L2TPS_MSG_ID_UL_SR_CFG_CNF,
	L2TPS_MSG_ID_DL_BSR_CFG,
	L2TPS_MSG_ID_UL_BSR_CFG_CNF,
	L2TPS_MSG_ID_DL_SRB2_DLUL_LB_START,
	L2TPS_MSG_ID_DL_RLF_REPORT_ENABLE,
	L2TPS_MSG_ID_UL_RLF_REPORT,
	L2TPS_MSG_ID_DL_SRB_DATA_REQ,
	L2TPS_MSG_ID_UL_SRB_DATA_CNF,
	L2TPS_MSG_ID_DL_MEAS_GAP_CFG,
	L2TPS_MSG_ID_UL_MEAS_GAP_CFG_CNF,
	L2TPS_MSG_ID_DL_GEMINI_GAP_CFG,
	L2TPS_MSG_ID_UL_GEMINI_GAP_CFG_CNF
};

typedef struct
{
    uint16 tdd_cfg;
    uint16 special_sf_idx;
} l2tps_cmd_dl_polling_t;

typedef struct
{
	uint16 tc_id;
    uint8   rsv0;
    uint8   rsv1;
} l2tps_cmd_dl_test_start_t;

typedef struct
{
    uint32 pkt_num;
    uint32 pkt_size;
    uint32 rb_idx;
} l2tps_cmd_dl_ul_data_req_t;

typedef struct
{
    uint32  rb_cfg;
    uint8   lcid;
    uint8   rb_id;
    uint8   rb_idx;
    uint8   rsv0;
} l2tps_add_rb_info_t;

typedef struct
{
    uint8   est_num;
    uint8   rsv0;
    uint8   rsv1;
    uint8   rsv2;
    l2tps_add_rb_info_t est_rb[8];
} l2tps_cmd_dl_est_drb_t;

typedef struct
{
    uint16  tdd_cfg;
    uint16  special_sf_idx;
	uint8   ueid[6];
    uint8   rsv0;
    uint8   rsv1;
} l2tps_cmd_dl_initial_access_req;


typedef struct
{
    uint8   rapid;
    uint8   ra_mask;
    uint8   rsv0;
    uint8   rsv1;
} l2tps_cmd_dl_ho_ra_req;

typedef struct
{
    uint16    send_delay;
} l2tps_cmd_dl_srb_data_req;

typedef struct
{
    uint32   ta_timer_idx;
} l2tps_cmd_dl_ta_timer_cfg;

typedef struct
{
    uint32  offset;

    uint8   drx_release;
    uint8   long_cycle;
    uint8   on_timer;
    uint8   inact_timer;

    uint8   retx_timer;
    uint8   short_cycle_valid;
    uint8   short_cycle;
    uint8   short_timer;
} l2tps_cmd_dl_drx_cfg;

typedef struct
{
    uint16 sps_crnti;
    uint8 ul_sps_valid;
    uint8 dl_sps_valid;

    uint16 dl_sps_interval;
    uint16 ul_sps_interval;
    uint8 dl_sps_proc_num;
    uint8 ul_sps_imp_rel;
    uint8 two_interval;
    uint8   rsv0;
} l2tps_cmd_dl_sps_cfg;

typedef struct
{
    uint8 ra_preamble_nb_index; //enum 0-15
    uint8 ra_pow_ramping_index; //enum 0-3
    uint8 ra_preamble_init_pow_index; //enum 0-15
    uint8 ra_preamble_tx_max_index; //enum 0-10
    uint8 ra_rar_wnd_sz_index; //enum 0-7
    uint8 ra_cr_timer_index; //enum 0-7

    uint8 ra_msg3_tx_max; //uint8

    uint8 group_a_valid; //bool
    uint8 ra_group_a_sz_index; //enum 0-14
    uint8 ra_msg_sz_group_a_index; //enum 0-3
    uint8 ra_msg_pow_offset_group_b_index; //enum 0-7

    uint8 ra_dedicated_valid; //bool
    uint8 rapid; //uint8
    uint8 prach_mask; //uint8

    uint8 rsv0;
    uint8 rsv1;
}l2tps_cmd_dl_ra_cfg;

typedef struct
{
    //EmacCfgReq
    uint16 sr_prohibit_timer;//uint8
    uint16 rsv;
    //CphyCfgReq
    uint16 sr_enable; //bool
    uint16 pucch_resource; //uint16
    uint16 config_index; //uint8
    uint16 dsr_max; //uint8

}l2tps_cmd_dl_sr_cfg;

typedef struct
{
    //EmacCfgReq
    uint16 periodic_bsr_timer_index; //enum0-14
    uint16 retx_bsr_timer_index; //enum0-5

}l2tps_cmd_dl_bsr_cfg;

typedef struct
{
    uint8  rb_idx;    //RB index
    uint8  rbid;      //RB ID
    uint16 is_old_rb; //old RB RLF or not

}l2tps_cmd_ul_rlf_report;

typedef struct
{
    uint8  meas_gap_setup;    //bool
    uint8  gap_pattern;      //0 or 1
    uint8  gap_offset; //0-39 for gp0, 0-79 for gp1

}l2tps_cmd_dl_meas_gap_cfg;

typedef struct
{
    uint8 gap_var_durn;
    uint8 gap_var_durn_prob;

}l2tps_cmd_dl_gemini_var_durn_t;

typedef struct
{
    uint16 gap_offset;
    uint16 gap_cycle;
    uint8 gap_duration;        //Original gap duration
    uint8 gap_durn_mode;       //0: always apply gap_duration, 1: var_durn, 2: durn_seq
    uint8 rsrv0;               //To make 4-byte align
    uint8 gap_var_durn_num;    //Config if gap shrinking is wanted.(MAX 3 var_durn) If sum of var_durn_prob < 1, the rest probability remains as gap_duration.
    l2tps_cmd_dl_gemini_var_durn_t gap_var_durn[L2TPS_MAX_GEMINI_VAR_DURN_NUM];
    uint8 gap_durn_seq_num;
    uint8 gap_durn_seq[L2TPS_MAX_GEMINI_DURN_SEQ_NUM];
    uint8 rsrv1;               //To make 4-byte align
    uint8 rsrv2;               //To make 4-byte align
    uint8 rsrv3;               //To make 4-byte align

}l2tps_cmd_dl_gemini_gap_pattern_t;

typedef struct
{
    uint8 need_cnf_flag;       //bool, true->need UE reply GEMINI_GAP_CNF
    uint8 gemini_gap_setup;    //bool, true->enable gemini gap, false->disable gemini gap
    uint8 gap_pattern_num;     //At most config 3 gap pattern
    uint8 rsrv0;               //To make 4-byte align
    l2tps_cmd_dl_gemini_gap_pattern_t gap_pattern[L2TPS_MAX_GEMINI_GAP_PATTERN_NUM];

}l2tps_cmd_dl_gemini_gap_cfg;

#endif
