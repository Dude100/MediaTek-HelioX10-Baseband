
/*------------------------------------------------------------------------------
     Copyright ASTwireless Corporation
--------------------------------------------------------------------------------
   FILE NAME        :                          
   TYPE             :   C header file                             
   DEPARTMENT       :        
   AUTHOR           :           
   AUTHOR'S EMAIL   :                            
--------------------------------------------------------------------------------
   Release history
   VERSION  Date         AUTHOR        DESCRIPTION
   0.1                                 First version
--------------------------------------------------------------------------------
   DESCRIPTION      :   UMAC-Stub function module for L1 test case
------------------------------------------------------------------------------*/
#ifndef FTA_UMAC_H
#define FTA_UMAC_H

#ifdef TL1_TESTCASE
//#define _L1TEST_UMAC_CASE

extern kal_uint8 gDlData[4096];

#define MAX(a, b) ((a) > (b) ? (a) : (b))



typedef struct _fta_ul_data_info_T
{
	kal_bool		valid;					 /*is valid*/
    kal_uint16      tfc_num;                 /*Number of TFC for UL DPCH*/
    ul_dpch_tfc_T   tfcs[MAX_UL_TFC];        /*ul TFCS*/
    kal_uint8       trch_num;                /*Number of UL TrCH*/
    ul_dch_trch_T   trch_list[MAX_UL_TRCH];  /*UL TrCH Info*/
    ul_dpch_info_T  dpch_info;               /*UL DPCH info*/
}fta_ul_data_info_T;


typedef struct _fta_ul_data_param_T
{
    kal_uint16   tfci;	
    kal_uint8     num_trch;	
    ulTrchData  TrchInfo[MAX_TRCH_NUM];	
    kal_uint16   size_data[MAX_TRCH_NUM];	
}fta_ul_data_param_T;


typedef struct _ftal_ul_data_T
{
	kal_bool data_valid;
	fta_ul_data_param_T ul_data_param;
	kal_uint8 *data_ptr;
}fta_ul_data_T;

typedef struct _fta_umac_stub_set_tfci_struct
{
    LOCAL_PARA_HDR 
    kal_uint16       tfci[16];              
}fta_umac_stub_set_tfci_struct;

#ifdef __HSUPA_SUPPORT__

typedef struct _fta_edch_config_info_T
{
    kal_bool             is_lowest_capability_category;
    kal_bool                edch_sched_info_valid;                  /*The following edch_sched_info valid or not.*/
    edch_sched_info_T       edch_sched_info;                        /*Scheduled Transmission Information.*/
    kal_bool                edch_non_sched_info_valid;              /*The following edch_sched_info valid or not.*/
    edch_non_sched_info_T   edch_non_sched_info;                    /*Non-Scheduled Transmission Information.*/
    epuch_info_T            epuch_info;                             /*E-PUCH Information, common to both scheduled and non-scheduled E-DCH transmission.*/
    edch_harq_info_T        edch_harq_info;                         /*Harq Configuration Information.*/
}fta_edch_config_info_T;

typedef struct _fta_edch_tick_1_output_para_T
{
	kal_bool is_user_data_available;
}fta_edch_tick_1_output_para_T;

typedef struct _fta_edch_tick_retx_set_T
{
	kal_uint8 sched_retx_harq_num;
	kal_uint8 sched_retx_harq_id[4];
	kal_uint8 non_sched_retx_harq_num;
	kal_uint8 non_sched_retx_harq_id[4];
}fta_edch_tick_retx_set_T;

typedef struct _fta_edch_tick_newtx_set_T
{
	kal_uint8 sched_newtx_harq_num;
	kal_uint8 sched_newtx_harq_id[4];
	kal_uint8 non_sched_newtx_harq_num;
	kal_uint8 non_sched_newtx_harq_id[4];
}fta_edch_tick_newtx_set_T;


typedef struct _fta_edch_case_ctrl_para_T
{
	kal_bool stub_use_case_set;
	kal_bool use_case_set;
	kal_uint8 twait_timeout;
	kal_uint8 etfci;
	kal_uint16 data_size; 
	tdd128_modulation_E modulation;
	fta_edch_tick_1_output_para_T tick_1_output;
	fta_edch_tick_retx_set_T tick_retx_set;
	fta_edch_tick_newtx_set_T tick_newtx_set;
}fta_edch_case_ctrl_para_T;


typedef struct _fta_edch_data_info_T
{
	kal_uint32 used;
	kal_uint8 edch_data[1400];
}fta_edch_data_info_T;

typedef struct _fta_umac_harq_para_T
{
	fta_edch_data_info_T*	edch_data_ptr;
	kal_uint8                          	harq_id;
	kal_uint8                          max_retrans_num;  /*最大重传次数，如果是SI，用config的参数*/
	kal_uint16                        max_retrans_timer;  /*最大重传时延，超过就丢包*/
	kal_bool                           trans_flag;  /*该harq当前需要发送数据*/
	kal_bool                           si_only_flag;
	kal_uint8                          etfci;
	kal_uint16                        tb_size;
	kal_uint8                          delta_harq;
	kal_uint8                          retrans_count;   /*0:表示可用的新harq,每传一次count++*/
	kal_uint8                          rsn;
	kal_uint16                        retrans_time;
	kal_uint8                          ts_num;
	kal_bool                           edch_use_flag;
	kal_uint8                          exist_time;/*0:harq不存在  >0:harq存在时间，注意区别uwRetransTime*/
	tdd128_modulation_E modulation;
}fta_umac_harq_para_T;

typedef struct _fta_edch_ctrl_para_T
{
	kal_uint16 harq_id;
	kal_uint16 ts_num;
	kal_uint16 tx_sfn;
	kal_uint16 delta_harq;
	kal_uint8   num_retx_harq; 
	kal_uint16 retx_harq_id_array[4];
	kal_bool new_data;
}fta_edch_ctrl_para_T;

typedef struct _fta_umac_stub_set_edch_ctrl_para_struct
{
    LOCAL_PARA_HDR 
    fta_edch_case_ctrl_para_T       edch_case_ctrl;              
}fta_umac_stub_set_edch_ctrl_para_struct;

typedef struct _fta_debug_var_T
{
	kal_uint32 hich_result_cnt;
	kal_uint32 tx_harq_cnt;
	kal_uint32 tx_harqid_idx;
	kal_uint8 tx_harqid[100];
	kal_uint32 result_harqid_idx;
	kal_uint8 result_harqid[100];
	ehich_result_E result_harq[100];
	kal_uint16 rsn_cnt;
}fta_debug_var_T;


#endif
/*******************************************************************************
                                ul data struct end                                
*******************************************************************************/

void FTA_Init_UMAC();
kal_bool FTA_UMAC_handle_l1_ind(ilm_struct* ilm);
kal_bool FTA_UMAC_store_ul_dch_param (msg_type msg_id,local_para_struct* local_para_ptr);
void FTA_UMAC_set_tfci(msg_type msg_id,local_para_struct* local_para_ptr);

#ifdef __HSUPA_SUPPORT__
kal_bool FTA_UMAC_store_edch_param (msg_type msg_id,local_para_struct* local_para_ptr);
#endif

#endif

#endif

