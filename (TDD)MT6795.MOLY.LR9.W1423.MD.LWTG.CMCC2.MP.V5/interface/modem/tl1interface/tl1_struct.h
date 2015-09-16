/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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

/******************************************************************************
 * Filename:
 * --------------------------------------------------------
 *   tl1_struct.h
 *
 * Project:
 * --------------------------------------------------------
 *   
 *
 * Description:
 * --------------------------------------------------------
 *   
 *
 * Author:
 * --------------------------------------------------------
 * -------
 *
 * --------------------------------------------------------
 * $Log$
 *
 * 01 17 2015 jt.tan
 * removed!
 * 	TxPower unstable in radiation testing if not lock in ant0 with testsim
 *
 * 01 10 2015 jt.tan
 * removed!
 * add tasTestSimEna flag
 *
 * 12 08 2014 jt.tan
 * removed!
 *
 * removed!
 * removed!
 * 	.add TL1 part code for rx data path pre modify for U3G
 *
 * removed!
 * removed!
 * report thermal.
 *
 * 05 13 2014 jt.tan
 * removed!
 * 	patch for CMCC 5.4.6
 *
 * removed!
 * removed!
 * 	.add mac ut struct with meas_occasion_ind
 *
 * removed!
 * removed!
 * 	.DMO optimization: ul tick tell mac DMO info
 *
 * removed!
 * removed!
 * 	.TL1 check in
 *
 * removed!
 * removed!
 * 4G OOS Measurement change.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * MMDC EM Dev: Report SINR Info to Uplayer.
 *
 * removed!
 * removed!
 * for cr:MOLY00032095,Record this situation: Calculate active_sfn with current_cfn and last rx_cfn, if the result is different, trace it.
 *
 * removed!
 * removed!
 * Report bch ind with standby no gap when no gap to rx bch.
 *
 * removed!
 * removed!
 * .add dsp changelist trace
 *
 * removed!
 * removed!
 * for cr:MOLY00032095,Record this situation: Calculate active_sfn with current_cfn and last rx_cfn, if the result is different, trace the it.
 *
 * removed!
 * removed!
 * for cr:MOLY00032095,Record this situation: Calculate active_sfn with current_cfn and last rx_cfn, if the result is different, trace the it.
 *
 *
 * removed!
 * removed!
 * Record this situation: Calculate active_sfn with current_cfn and last rx_cfn, if the result is different, trace the it.
 *
 * removed!
 * removed!
 * MEME control trigger short period measurement immediatly or not.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .remove __PREPARE_TX_AHEAD__
 *
 * removed!
 * removed!
 * add auto gap interface.
 *
 * removed!
 * removed!
 * [TL1] Merge lastes WR8 + R9 + MM code to MOLY..
 *
 * removed!
 * removed!
 * EM tx test tl1 part.
 *
 * removed!
 * removed!
 * add parameter of ul_inform_MAC
 *
 * removed!
 * removed!
 * .
 * 
 * removed!
 * removed!
 * remove option for islongperiodin3gstandby.
 * 
 * removed!
 * 
 * removed!
 * <saved by Perforce>
 * 
 * removed!
 * removed!
 * .
 * 
 * removed!
 * removed!
 * TDD_R9_DEV patch back to MOLY
 * 
 * removed!
 * removed!
 * 
 * removed!
 * removed!
 * .
 * remove __UMAC_DCH_LISR__
 * 
 * removed!
 * removed!
 * Rollback //MOLY/TRUNK/MOLY/mcu/interface/modem/tl1interface/tl1_struct.h to revision 2
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
 * (TL1 SAP)
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
 * TL1 code interface fta merge in MAUI.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * 
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * Update SAP according to UMAC requirement
 *
 * removed!
 * removed!
 * Help vendor_ast to merge PS_RESTRUCT_DEV
 *
 * removed!
 * removed!
 * Modify some description.
 *
 * removed!
 * removed!
 * merge code from daily LOAD to MAUI 10A.
 *
 * removed!
 * removed!
 * Remove LOCAL_PARA_HDR define.
 *
 * removed!
 * removed!
 * Add RHR feature to tl1 interface files.
 *
 * 12 28 2010 bo.lu
 * removed!
 * .
 *
 * removed!
 * removed!
 * Modify the struct of phy_post_tx_ind.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Modify the description of umts_power_class.
 *
 * removed!
 * removed!
 * 1. Add ul_mac_event to cphy_dch_setup/modify/release_req
 * 2. Add two ticks and structs for mac-tl1 interface.
 * 3. Add two simulation structs according to MAC's requeset.
 *
 * removed!
 * removed!
 * 1.SLCE-TL1 SAP Modify for R7
 * 2. MAC-TL1 SAP Modify for UPA
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Add tx_enable in phy_simulate_dch_ul_cctrch_hisr_rsp_struct according to the discussion result with UMAC
 *
 * removed!
 * removed!
 * 1.Add tx_enable in ul_dpch_cctrch_task(), ul_dpch_cctrch_HISR(), phy_simulate_dch_ul_cctrch_task_struct and phy_simulate_dch_ul_cctrch_hisr_struct
 * 2.Add access_type in phy_access_ind_struct with HSUPA compile option
 *
 * removed!
 * removed!
 * Modify dpch_SIR_lta to dpdch_SIR_lta in L1_info_struct
 *
 * removed!
 * removed!
 * 1.In tl1_info, modify the struct name of tl1_speech_info_T to L1_info_struct to use the same interface to FDD according to l1audio team¡¯s requirement.
 * 2.In L1_info_struct, modify the parameter name and type to use the same interface to FDD according to l1audio team¡¯s requirement.
 *
 * removed!
 * removed!
 *         1.Add rssi and rscp in PHY_BCH_DATA_IND, and add comments of the parameters in PHY_BCH_DATA_IND
 *         2.Add PHY_END_EDCH_TX_IND 
 *         3.Modify comments of sfn in phy_dch_setup_ind_struct, phy_dch_release_ind_struct
 *         4.Modify the comments of TL1_GetCurrentTime. 
 *
 * removed!
 * removed!
 * 1.Add cphy_hsdsch_setup/modify/release_req and cphy_edch_setup/modify/release_req into local_para_unpack_T
 * 2.Add midamble_shift_detection_result, max_value_of_midamble_correlation_result and noise_of_midamble_correlation_result in tl1_speech_info_struct_T
 * 3.seperate rscp to dpch_rscp and pccpch_rscp in tl1_speech_info_struct_T
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 1.Add type definition of cphy_edch_setup/modify/release_req_struct.
 * 2.Delete meas_control and idx_intra_freq in cphy_msg_container_req_struct and cphy_msg_container_req_unpack_struct
 * 3.Add access_type in phy_rach_data_req_struct and phy_access_req_struct
 * 4.Add HSDPA and HSUPA related callback function declaration
 *
 * removed!
 * removed!
 * 1.Delete pre-declare check of __UMTS_TDD128_MODE__
 *
 * removed!
 * removed!
 * 1.add check of __UMTS_TDD128_MODE__
 * 2.delete the parameter of act_time in cphy_bch_setup/modify_req
 * 3.delete strcut of cphy_measurement_config_fmo_req_struct
 * 4.Use TL1 to replace UL1 and L1 in comments
 * 5.Modify comments of mac_event in cphy_hsdsch_setup/modify/release_req to sync with TL1 SAP doc
 * 6.add comments of cfn in phy_end_dch_tx_ind_struct
 * 7.Modify type of sub_cfn in phy_hsdsch_data_ind_struct from kal_uint8 to kal_uint16, and modify type of mac_hs_reset in phy_hsdsch_data_ind_struct from kal_uint8 to kal_bool
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add meas_id in cphy_measurement_internal_result_ind according to discussion conclusion with MEME module owner
 *
 * removed!
 * removed!
 * Modify type of event_id in CPHY_MEASUREMENT_INTERNAL_EVENT_IND from kal_uint8 to internal_meas_event_E
 *
 * removed!
 * removed!
 * 1 rename "dpdch_SIR_lta" in phy_data_ind_struct to "dpch_SIR_lta"
 *
 * removed!
 * removed!
 * 1. change the type of sib7_factor from "kal_int8" to "kal_uint8" to compiance with SLCE 
 * 2. add h_msg and e_msg for DPA and UPA
 * 3. change the type of off in cphy_sfn_ind_struct from kal_uint16 to kal_int16
 *
 * removed!
 * removed!
 * remove typo error "ul1_def"
 *
 * removed!
 * removed!
 * modify phy_data_ind_struct for UT test 
 *
 * removed!
 * removed!
 * Rename __UMTS_TDD128_RAT__ to __UMTS_TDD128_MODE__
 *
 * removed!
 * removed!
 * add log section for tl1interface header files
 *
*******************************************************************************/


#ifndef _TL1_STRUCT_H
#define _TL1_STRUCT_H

//#include "tool.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "tl1_def.h"
#include "gas_b3_general_struct.h"

//TDD_TAS JT.Tan
#include "em_msgid.h"
#include "em_public_struct.h"

/*****************************************************************************
Request from SLCE/MEME  to TL1 
*****************************************************************************/

/*bch*/
typedef struct _cphy_bch_setup_req_struct
{
    LOCAL_PARA_HDR
    kal_int16    rx_sfn;                                /*[Range]: (-1~4095). (0-4095) for frame number type, and "-1" for immediate type.
                                                          [Meaning]: This is the SFN to start to setup BCH channel, and receive SIB */  
    kal_int32    tm;                                    /*[Range]: -1 ~ (6400*8-1). -1 for unknown timing.
                                                          [Meaning]:Sub Frame boundary offset between target cell and LST
                                                           For a cell with unknown tm value, it can not be issued to TL1. */                                                                                               
    kal_int16    off;                                   /*[Range]: -1~8191, (0-8191) for a cell whose Sub SFN offset to LST has been measured by TL1. -1 means off unknown.
                                                          [Meaning]: Sub frame number offset between target cell and LST.
                                                           For a cell with unknown off value, it can not be issued to TL1. */
    kal_bool     sfn_only;                              /*True/False. True: The BCH setup request is only for the SFN reading, 
                                                          and TL1 will only send CPHY_SFN_IND to RRC,                                                                                     
                                                           False: The BCH setup request is for the BCH data reading.*/
    kal_uint16   uarfcn;                                /*uarfcn*/                                              
    kal_uint16   cell_param_id;                          /*[Range]: 0-127, CPID_INVALID
                                                           [Meaning]:Cell parameter ID*/ 
    kal_bool     sctd;                                   /*True: sctd is applied on this cell's P-CCPCH. 
                                                          False: sctd is not applied on this cell's P-CCPCH.*/
    kal_bool     tstd;                                   /*True: tstd is applied on this cell's P-CCPCH. 
                                                           False: tstd is not applied on this cell's P-CCPCH.*/                                                            
    kal_int8     sib7_index;                              /*[Range]: -1 ~ (sibnum-1) 
                                                            [Meaning]: Indicate which SIB Info in sib_list[] is SIB7,-1 means there is no SIB7 in the list*/
    kal_uint16    sib7_rep_cycle;                          /* 2~256 .The meaning of sib7_rp_cycle becomes "SIB7 expiration timer/ SIB_REP" */
                                                                                                                                      
    bch_priority_T    bch_priority;                       /*Enum:BCH_PRIOHIGH,BCH_PRIOMEDIUM(not used in TDD18), BCH_PRIOLOW  */
    kal_uint8    sib_num;                                 /*[Range]: 0~ MAX_SIB_PATTERN.
                                                            [Meaning]: the number of sib in sib list.
                                                            0 means all SIBs reception.0 is not used in current implementation.*/ 
    sib_info_T   sib_list[MAX_SIB_PATTERN];    /*SIB information*/
#if defined( __GEMINI_GSM__ ) && defined ( __UMTS_RAT__ )
    kal_uint16                   priority_index;                     /*Priority_index for same priority channel in 3G Gemini project*/   
#endif
    kal_bool	 is_auto_gap_support;		   /*This BCH req is for report CGI*/

} cphy_bch_setup_req_struct;

typedef struct _cphy_bch_modify_req_struct
{
    LOCAL_PARA_HDR
    kal_int16    rx_sfn;                                  /*[Range]: (-1~4095). (0-4095) for frame number type, and "-1" for immediate type.
                                                            [Meaning]: This is the SFN to start to setup BCH channel, and receive SIB */ 
    kal_uint8    modify_flag;                           /*A flag to indicate the field to be modified.
                                                          0x01 "bch_priority" is changed
                                                           0x02: "sib_num", "sib_list", sib7_index, sib7_factor are changed.
                                                            0x03: both above item are changed*/
    kal_int8     sib7_index;                      /*[Range]: -1 ~ (sibnum-1) 
                                                     [Meaning]: Indicate which SIB Info in sib_list[] is SIB7,-1 means there is no SIB7 in the list*/
    kal_uint16    sib7_rep_cycle;                 /* 2~256 .The meaning of sib7_rp_cycle becomes "SIB7 expiration timer/ SIB_REP" */
                                                                                             
    bch_priority_T    bch_priority;               /*Enum:BCH_PRIOHIGH,BCH_PRIOMEDIUM(not used in TDD18), BCH_PRIOLOW  */ 
    kal_uint8    sib_num;                         /*[Range]: 0~ MAX_SIB_PATTERN.
                                                    [Meaning]: the number of sib in sib list.
                                                     0 means all SIBs reception.0 is not used in current implementation.*/     
    sib_info_T   sib_list[MAX_SIB_PATTERN]; /*SIB information*/
#if defined( __GEMINI_GSM__ ) && defined ( __UMTS_RAT__ )
    uas_gemini_conflict_cause_enum conflict_cause;   /*Channel conflict casue with peer channel*/
   kal_uint16                   priority_index;                     /*Priority_index for same priority channel in 3G Gemini project*/   
#endif
} cphy_bch_modify_req_struct;


typedef struct _cphy_bch_release_req_struct
{
    LOCAL_PARA_HDR
} cphy_bch_release_req_struct;
    

/*pch*/
typedef struct _cphy_pch_setup_req_struct
{
    LOCAL_PARA_HDR
    kal_int16    act_time;              /* activation time. -1 ~ 255. -1 means immediate */
    kal_uint16   uarfcn;                                /*uarfcn*/      
    kal_int32    tm;                                    /*[Range]: -1 ~ (6400*8-1). -1 for unknown timing.
                                                          [Meaning]:Sub Frame boundary offset between target cell and LST
                                                          For a cell with unknown tm value, it can not be issued to TL1. */
    kal_int16        off;                               /*[Range]: -1~8191, (0-8191) for a cell whose Sub SFN offset to LST has been measured by TL1. -1 means off unknown.
                                                          [Meaning]: Sub frame number offset between target cell and LST.
                                                          For a cell with unknown off value, it can not be issued to TL1. */
    fach_pch_info_T    fach_pch_info;   /*FACH/PCH channel information*/
} cphy_pch_setup_req_struct;

typedef struct _cphy_pch_modify_req_struct
{
    LOCAL_PARA_HDR
    kal_int16    act_time;              /* activation time. -1 ~ 255. -1 means immediate */
    pich_drx_T   pich_drx;              /*new drx info of PCH/PICH*/

	pich_reconfig_type_E          reconfig_type;
	pich_smartpaging_T            smartpaging_info;
} cphy_pch_modify_req_struct;

typedef struct _cphy_pch_release_req_struct
{
    LOCAL_PARA_HDR
    kal_int16    act_time;              /* activation time. -1 ~ 255. -1 means immediate */
} cphy_pch_release_req_struct;


/*fach*/
typedef struct _cphy_fach_setup_req_struct
{
    LOCAL_PARA_HDR            
    kal_int16    act_time;              /* activation time. -1 ~ 255. -1 means immediate */
    kal_uint16   uarfcn;                               /*uarfcn*/      
    kal_int32    tm;                                    /*[Range]: -1 ~ (6400*8-1). -1 for unknown timing.
                                                         [Meaning]:Sub Frame boundary offset between target cell and LST
                                                           For a cell with unknown tm value, it can not be issued to TL1. */
    kal_int16    off;                                   /*[Range]: -1~8191, (0-8191) for a cell whose Sub SFN offset to LST has been measured by TL1. -1 means off unknown.
                                                          [Meaning]: Sub frame number offset between target cell and LST.
                                                           For a cell with unknown off value, it can not be issued to TL1. */
    fach_pch_info_T    fach_pch_info;  /*FACH/PCH channel information*/
} cphy_fach_setup_req_struct;

typedef struct _cphy_fach_release_req_struct
{
    LOCAL_PARA_HDR
    kal_int16    act_time;              /* activation time. -1 ~ 255. -1 means immediate */
} cphy_fach_release_req_struct;


/*rach*/
typedef struct _cphy_rach_setup_req_struct
{
    LOCAL_PARA_HDR
    kal_int16    act_time;              /* activation time. -1 ~ 255. -1 means immediate */
    random_access_info_T  prach_info;            /*prach related info for this UE*/
    ul_rach_trch_T      trch_list[1];   /*SLCE will select one rach trch for TL1*/
} cphy_rach_setup_req_struct;

typedef struct _cphy_rach_release_req_struct
{
    LOCAL_PARA_HDR
    kal_int16    act_time;              /* activation time. -1 ~ 255. -1 means immediate */
} cphy_rach_release_req_struct;


/*dch*/
typedef  struct _cphy_dch_setup_req_struct
{
    LOCAL_PARA_HDR
    kal_int16    act_time;                      /*(-1~255). (0~255) for CFN type, "-1" for immediate type.*/
    dch_setup_msg_type_E    setup_type;         /*DCH setup type,setup,HHO,baton HO,revert,etc.*/

    kal_bool    is_ul_dch_setup;     /*Indicate whether UL dch will be set up. */
    kal_bool is_dl_dch_setup;        /*Indicate whether DL dch will be set up. 
                                                Before R8£¬ this field should always be set to KAL_TRUE*/
    kal_int16    rscp;                          /* -500 ~ -100 means (-125 ~ -25 )dBm in 0.25 dB step,serving cell rscp*/
    kal_uint8    tid;                           /*Transaction id*/
    kal_uint8    dl_crc_ind;                    /* For those TrCHs whose CRC data should be sent to MAC, 
                                                                                    their corresponding bit will be set to 1.
                                                                                    The MSB represents the lowest numbered TrCH ID.*/
    kal_uint16      prim_uarfcn;                /*Primary uarfcn of the cell*/
    kal_uint16      work_uarfcn;                /*Working uarfcn of the  UE  */
    kal_uint16      ul_tfc_num;                 /*Number of TFC for UL DPCH*/
    ul_dpch_tfc_T   ul_tfcs[MAX_UL_TFC];        /*ul TFCS*/
    kal_uint8       ul_trch_num;                /*Number of UL TrCH*/
    ul_dch_trch_T   ul_trch_list[MAX_UL_TRCH];  /*UL TrCH Info*/
    ul_dpch_info_T  ul_dpch_info;               /*UL DPCH info*/
    kal_uint16      dl_tfc_num;                 /*Number of DL TFCS*/
    dl_tfc_T        dl_tfcs[MAX_DL_TFC];        /*DL TFCS*/
    kal_uint8       dl_trch_num;                /*Number of DL TrCH*/
    dl_dch_trch_T   dl_trch_list[MAX_DL_TRCH];  /*DL Trch Info*/
    kal_int8        max_tx_power;               /*50 ~ 33 dBm,Max. allowed TX power. */
    kal_int8        umts_power_class;           /*UE capability(in dBm)*/   
    dl_dpch_rla_T   dl_dpch_rla;                /*DL Info & DL DPCH Info common for all RLs*/
    dl_dpch_rl_T    dl_dpch_rl[MAX_RL];         /*DL Info & DL DPCH Info. for each RL*/    
    dl_establish_T  dl_establish_info;          /*DL DPCH establishment criterion*/  
    kal_uint8       sbgp;                       /*Value represents number of radio frames
                                                                                       0 = 2 frames, 1 = 4 frames,
                                                                                       2 = 8 frames, 3 = 16 frames,
                                                                                       4 = 32 frames, 5 = 64 frames,
                                                                                       6 = 128 frames, 7 =256 frames.*/
     random_access_info_T   ul_sync;                    /*UL  sync parameter for enter DCH to another cell, handover or handover revert.*/      
    kal_uint8       ul_mac_event;                       /* Indicate if UMAC need setup/modify/release event 
                                                           Bit 0 : Setup; Bit 1 : Release ; Bit 2 : Modify
                                                           And in this primitive, only Bit 0 can be set to 1*/
}cphy_dch_setup_req_struct;

typedef struct _cphy_dch_modify_req_struct
{
    LOCAL_PARA_HDR            
    kal_int16    act_time;                     /*(-1~255). (0~255) for CFN type, "-1" for immediate type.*/
    kal_uint16   work_uarfcn;                  /*Working uarfcn of the cell  */             
    dch_modify_msg_type_E    modify_type;      /*Enums:DCH_RECONFIG,DCH_LOOP_MODE_2*/
    kal_uint8    tid;                          /*Transaction id*/                  
   ul_dpch_reconfig_type_E ul_dpch_reconfig_type   ;/*   0: Do nothing with ul dpch.
                                                1: Setup ul dpch.
                                                2: modify ul dpch
                                                3.Release ul dpch*/   
//#ifdef __TDD128_HSPA_PLUS__
	dl_dpch_reconfig_type_E dl_dpch_reconfig_type	;/*   0: Do nothing with dl dpch.
											 1: Setup dl dpch.
											 2: modify dl dpch
											 3.Release dl dpch*/ 
//#endif
    kal_bool     ul_mod_ind;                   /*Indicate whether UL modify indication should be sent to MAC*/
    kal_bool     dl_mod_ind;                   /*Indicate whether DL modify indication should be sent to MAC*/
    kal_uint8    dl_crc_ind;                    /*For those TrCHs whose CRC data should be sent to MAC.
                                                                      their corresponding bit will be set to 1. 
                                                                                       The MSB represents the lowest numbered TrCH ID.*/
    kal_uint16    modify_field;                /*Bit field to represent for the parameters that should be modified 
                                                                Bit0: DL TrCH parameter
                                                                Bit1: DL TFCS parameter 
                                                                Bit2: UL TrCH parameter
                                                                Bit3: UL TFCS parameter
                                                                Bit4: downlink common RL parameters
                                                                Bit5: downlink each RL parameters. 
                                                                Bit 6 : UL RL parameter 
                                                                Bit 7 : Physical parameters such as working_uarfcn 
                                                                Bit8: dl_establish_info
                                                                Bit9: SBGP
                                                                Bit10: uplink power control related parameters, such as max _tx_power,  umts_power_class. */
    kal_uint16   ul_tfc_num;                   /*Number of TFC for UL DPCH*/    
    ul_dpch_tfc_T    ul_tfcs[MAX_UL_TFC];      /*ul TFCS*/
    kal_uint8    ul_trch_num;                  /*Number of UL TrCH*/
    ul_dch_trch_T    ul_trch_list[MAX_UL_TRCH];/*UL TrCH Info*/
    kal_uint16    dl_tfc_num;                   /*Number of DL TFCS*/
    dl_tfc_T     dl_tfcs[MAX_DL_TFC];          /*DL TFCS*/
    kal_uint8    dl_trch_num;                  /*Number of DL TrCH*/
    dl_dch_trch_T    dl_trch_list[MAX_DL_TRCH];/*DL Trch Info*/
    dl_dpch_rla_T    dl_dpch_rla;              /*DL Info & DL DPCH Info common for all RLs*/              
    ul_dpch_info_T    ul_dpch_info;            /*UL DPCH info*/        
    kal_int8     max_tx_power;                 /*50 ~ 33 dBm,Max. allowed TX power. */                
    kal_int8     umts_power_class;             /*UE capability(in dBm)*/ 
    dl_dpch_rl_T    dl_dpch_rl[MAX_RL];        /*DL Info & DL DPCH Info. for each RL*/
    dl_establish_T  dl_establish_info;         /*DL DPCH establishment criterion*/
    kal_uint8         sbgp;                    /*Value represents number of radio frames
                                                                                       0 = 2 frames, 1 = 4 frames,
                                                                                       2 = 8 frames, 3 = 16 frames,
                                                                                       4 = 32 frames, 5 = 64 frames,
                                                                                       6 = 128 frames, 7 =256 frames.*/
    kal_uint8       ul_mac_event;                       /* Indicate if UMAC need setup/modify/release event
                                                            Bit 0 : Setup; Bit 1 : Release ; Bit 2 : Modify
                                                            And in this primitive, only Bit 2 can be set to 1*/
}cphy_dch_modify_req_struct;

typedef struct _cphy_dch_release_req_struct
{
    LOCAL_PARA_HDR            
    kal_int16    act_time;                    /*(-1~255). (0~255) for CFN type, "-1" for immediate type.*/
    kal_bool    isStopLoopTestM2First;        /*TRUE: Stop Loop Mode 2 before releasing DCH.*/
    kal_uint8   ul_mac_event;                       /* Indicate if UMAC need setup/modify/release event    
                                                       Bit 0 : Setup; Bit 1 : Release ; Bit 2 : Modify
                                                       And in this primitive, only Bit 1 can be set to 1*/
} cphy_dch_release_req_struct;


/*fs*/
typedef struct _cphy_frequency_scan_req_struct
{
    LOCAL_PARA_HDR
    kal_uint8     max_num_cell;                    /*Maximum number of cells reported in 1 frequency during scan. 
                                             MIN(max_num_cell, num_found_cell) cells to MEME
                                             it shall halt the frequency scan procedure.*/   
    kal_uint16    timeout;                         /*Maximum time spent to do cell search on 1 frequency. 
                                             If TL1 has spent so much time to do cell search on 1 frequency,
                                             it will send an indication to MEME and halt the frequency scan procedure.
                                             [Unit]: ms.*/  
    kal_uint8     num_freq_range;                  /*Number of range list*/ 
    kal_uint16    uarfcn_begin[MAX_FREQ_RANGE];       /*Begin of UARFCN for range cell search*/    
    kal_uint16    uarfcn_end[MAX_FREQ_RANGE];         /*End of UARFCN for range cell search */ 
    kal_uint8     num_freq_list;                   /*Number of freq for preferred freq list */
    kal_uint16    uarfcn_list[MAX_FREQ_LIST];         /*List of UARFCN */ 
    kal_uint8     num_preferred_cell;              /*Number of preferred cells. */
    preferred_cell_list_T    preferred_cell_list[MAX_PREFERRED_CELL];    /*Preferred cell list. */
    kal_bool    full_band_search;                  /*True/False. True: Perform full band scan. */
    kal_bool    freq_correct;                      /*True/False. True: TL1 need to do frequency correction. */
    kal_bool    resume;                            /*True/False. True:TL1 should resume previous freq scan,
                                               TL1 didn't care the other fields in this msg,
                                               False: TL1 should start a new freq scan according to this msg */
   full_band_option_E    full_band_option;         /*- FULL_BAND_ONLY: Normal full band FS
                                                - FULL_BAND_AND_EXCLUDE: Full band FS but the indicated frequency list/range will be excluded */
   #if defined( __GEMINI_GSM__ ) && defined ( __UMTS_RAT__ )    
   kal_uint16                    priority_index;   
   #endif
   #ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
   kal_uint8                     priority_level;    /*[Range: 0-2] Indicate which gap pattern shoud be used for this freq scan in Virtual mode*/
                                                    /*0=highest priority; 1=2nd priority; 2=lowest priority*/
   #endif
   kal_bool     is_auto_gap_support;          /*This FS req is for report CGI*/
#if defined(__LTE_RAT__) && defined (__UMTS_TDD128_MODE__) && !defined (__SGLTE__)
   kal_bool                            trigger_by_4g_plmn_loss;
#endif
/*Yajiang 20150114 :add for TL1 to differ manual plmn search or autonmous*/
   kal_bool    is_plmn_list;
} cphy_frequency_scan_req_struct;

typedef struct _cphy_frequency_scan_suspend_req_struct
{
    LOCAL_PARA_HDR 
} cphy_frequency_scan_suspend_req_struct;


typedef struct _cphy_frequency_scan_continue_req_struct
{
   LOCAL_PARA_HDR
   kal_bool              continue_cell;                             /*True if MEME want TL1 to do continue cell search on current frequency
                                                                        instead of jumping to next specified frequency. */
} cphy_frequency_scan_continue_req_struct;


/*meas*/
typedef struct _cphy_measurement_config_cell_req_struct
{
    LOCAL_PARA_HDR 
    kal_uint8    tid;                                               /*Transaction ID to sync between request and indication*/
    meas_act_E   action;                                            /*[Range]: STOP_MEAS,
                                                                                                                          START_MEAS_NEW_CIL,
                                                                                                                          START_MEAS_NEW_CIL_NEW_FMO*/    
    kal_bool     ds_meas;                                           /*True: Indicate that TL1 shall make detected cell measure.*/
    kal_uint16   intra_uarfcn;                                      /*Intra-frequency uarfcn, TL1 has knowledge about intra_uarfcn,
                                                                                                                          just double check the value. MEME shall send the primitive after 
                                                                                                                          channel enters stable state to guarantee the value is the same 
                                                                                                                          with TL1. But it is possible different with TL1 when channel transition.*/
    kal_uint8    num_cell;                                          /*[Range]:0-64,[Meaning]: Number of cells in the following 
                                                                                                                          cell_info_list[]. Must be greater than 0 if bit1 of 'action' is set.*/
    cell_info_list_T    cell_info_list[MAX_NUM_MEASURED_CELL];      /*List of all monitor cells to be measured indicated by network. It 
                                                                                                                          is ascending sort by cell's uarfcn and cell_param_id. Cells on the 
                                                                                                                          same frequency will be collected together. The cells on different 
                                                                                                                          frequencies will not be interleaved.*/
    fach_mo_info_T      fach_mo_info;                               /*The structure is used to express the FACH measurement occasion 
                                                                                                                          parameters. It is valid when bit2 of 'action' is set*/
    kal_bool     intra_rscp_meas_period_valid;                      /*Configure Intra-freq. RSCP meas. period in DCH/FACH.*/
    kal_uint8    intra_rscp_period_N;                               /*Num. of 50/40 ms.*/
    kal_bool     inter_rscp_meas_period_valid;                      /*Configure Inter-freq. RSCP meas. period in DCH/FACH*/                 
    kal_uint8    inter_rscp_period_N;                               /*Num. of 50/40 ms.*/
    kal_bool     intra_iscp_meas_period_valid;                      /*Configure Intra-freq. ISCP meas. period in DCH/FACH.*/
    kal_uint8    intra_iscp_period_N;                               /*Num. of 50/40 ms.*/
//#ifdef __UMTS_R9__
    kal_int16	 T_higher_prio_search;                                /*Higher priority search period (s) when use priority based cell reselection, -1 means use regular period.*/
	kal_bool	 is_meas_period_reset_standby;
	kal_bool	 prohibit_apply_n_layer_standby; 						     /* [R8][MM] Due to 4G OOS, MEME notifies TL1 not to apply n_layer factor to accelerate meas frequency */

//#endif
} cphy_measurement_config_cell_req_struct;

//JT.Tan 05792
//#ifdef __TDSCDMA_TAS_ENABLE__
typedef struct _cphy_tas_custom_config_param_T
{
	kal_uint16 tas_enable_flag; //1/0: enable/disable TAS
	kal_uint16 tas_default_main_antenna; //0: ant#0 as default /1: ant#1 as default;
	kal_uint16 tas_default_type;
	kal_uint16 tas_type_by_band;//bit0:band34; bit1:band39; bit2:band40;
	kal_uint16 tas_force_tx_ant_enable;
	kal_uint16 tas_force_tx_ant_idx;
	kal_uint16 tas_with_test_sim_enable;
}cphy_tas_custom_config_param_T;

typedef struct _cphy_tas_algorithm_param_T
{
	//TAS period
	kal_int16 period_N;//TAS period in connected mode,DCH n*200ms,default=1;
	kal_int16 drx_period_N;//TAS period in DRX: drx_period_n * drx; 

	//TAS antenna offset
	kal_int16 diff_ant_oft0;
	kal_int16 diff_ant_oft1;
	
	kal_int16 diff_htp;
	kal_int16 htp_oft;
	kal_int16 max_htp_tx_pwr;
	kal_int16 threshold_htp;

	kal_int16 diff_drx_ant_oft0;
	kal_int16 diff_drx_ant_oft1;

	//TAS threshold
	kal_int16 threshold_diff_rscp;
	kal_int16 threshold_diff_snr;
	kal_int16 snr_good;
	
	kal_int16 threshold_drx_diff_rscp;
	kal_int16 threshold_drx_diff_snr;
	kal_int16 drx_snr_good;
	
	kal_int16 threshold_drx_rscp_low;
	kal_int16 threshold_drx_snr_low;		
	
	//TAS fall back algorithm
	kal_int16 diff_fall_back;
	kal_int16 diff_drx_fall_back;
}cphy_tas_algorithm_param_T;
/*specific cell search*/
typedef struct _cphy_specific_cell_search_req_struct                  /*RRCE->TL1*/
{
    LOCAL_PARA_HDR
    kal_uint16  uarfcn;                                             /*uarfcn*/
    kal_uint16  cell_param_id;                                      /*[Range]: 0-127 [Meaning]:Cell parameter ID*/
    kal_bool    sctd;                                               /*True/False. True: sctd is applied on this cell's P-CCPCH.  
                                                                                                                          False: sctd is not applied on this cell's P-CCPCH.*/
    kal_bool    tstd;                                               /*True/False. True: tstd is applied on this cell's P-CCPCH.  
                                                                                                                          False: tstd is not applied on this cell's P-CCPCH.*/
} cphy_specific_cell_search_req_struct;

typedef struct _cphy_specific_cell_search_stop_req_struct
{
    LOCAL_PARA_HDR 
} cphy_specific_cell_search_stop_req_struct;

/*reset and set rat*/
typedef struct _cphy_reset_req_struct
{
    LOCAL_PARA_HDR 
} cphy_reset_req_struct;

typedef struct _cphy_rf_on_req_struct
{
    LOCAL_PARA_HDR 
    kal_uint8    working_UMTS_band[2]; 
} cphy_rf_on_req_struct;

typedef struct _cphy_rf_off_req_struct
{
    LOCAL_PARA_HDR  
} cphy_rf_off_req_struct;

typedef struct _cphy_set_active_rat_req_struct
{
    LOCAL_PARA_HDR
    mode_type_E mode;                               /* Curernt mode setting (Single, Dual) */
    rat_type_E  rat;                                /* Current active RAT setting (Flight, UMTS, GSM) */
} cphy_set_active_rat_req_struct;

/*internal meas*/
typedef struct _cphy_measurement_internal_config_req_struct  /*MEME->TL1*/
{
    LOCAL_PARA_HDR      
    kal_uint8    meas_id;                                           /*[Range] 0-16,  0 is INVALID_MEAS_ID and is forbidden use here.
                                                                                                                          [Meaning] <TS25.331:10.3.7.48>, it is 'Measurement Identity' 
                                                                                                                          in the 'MEASUREMENT CONTROL', follow fields are all derived from the message.*/
    internal_meas_E meas_quantity;                                  /*[Range] MEAS_TX_PWR, MEAS_RSSI, MEAS_TA 
                                                                                                                          [Meaning] Indicates internal measurement type in the primitive.*/
    kal_bool     periodic_ind;                                      /*[Range]True/False.  
                                                                                                                          [Meaning] Indicates whether TL1 report result of 'meas_type' periodically. 
                                                                                                                          When 'meas_type' is MEAS_RSSI, always set with 'False'.*/
    kal_uint8    report_num;                                        /*[Range]: 0 ~ 64. Number of periodic reports to be reported. TL1 will ignore 
                                                                                                                          this value if periodic_ind=False. If the value is 0, it means infinity.*/
    kal_uint16   period;                                            /*[Range]: 250 ~ 6400 frames. The reporting interval of periodic measurement.
                                                                                                                          TL1 will ignore this value if periodic_ind=False.*/
    kal_uint8    event_num;                                         /*Number of events in the below event[] list.*/
    meas_event_T event[MAX_MEAS_EVENT];                             /*The list of event.*/
    kal_uint8    filter;                                            /*[Range] 0-14.(fc0,fc1,fc2,fc3,fc4,fc5,fc6,fc7,fc8,fc9,fc11,fc13,fc15,fc17,fc19),
                                                                                                                          L3 filtering, apply for UTRA carrier RSSI and UE transmitted power.*/
}cphy_measurement_internal_config_req_struct;


typedef struct _cphy_measurement_internal_result_req_struct
{
    LOCAL_PARA_HDR
    kal_uint8 meas_id;                                              /*[Range] 0-16,  0 is INVALID_MEAS_ID 
                                                                                                                          [Meaning] Measurement Identity<TS25.331:10.3.7.48>; Indicate  
                                                                                                                          TL1 return Tx-Pwr results with filter coefficient in 'MEASUREMENT  
                                                                                                                          CONTROL' indicated by meas_id. If meas_id is 0, it means TL1  
                                                                                                                          return Tx-Pwr value without filter.*/   
}cphy_measurement_internal_result_req_struct;


typedef struct _cphy_measurement_internal_stop_req_struct
{
    LOCAL_PARA_HDR
    kal_uint8 num_meas_id;                                          /*[Range] 1-MAX_NUM_MEAS_ID 
                                                                                                                          [Meaning] The number of valid 'meas_id' in 'meas_id[]'.*/
    kal_uint8 meas_id[MAX_NUM_MEAS_ID];                             /*[Range] 1-16 [Meaning] <TS25.331:10.3.7.48>, it is 'Measurement 
                                                                                                                          Identity' in the 'MEASUREMENT CONTROL', TL1 shall stop internal 
                                                                                                                          measurement configured by these message.*/   
}cphy_measurement_internal_stop_req_struct;



/*sniffer  */
typedef struct _cphy_rssi_sniffer_start_req_struct
{
    LOCAL_PARA_HDR
    kal_uint8   num_freq_list;                                   /* Num of of freq for scan list of RSSI sniffer */
    kal_uint16  uarfcn_list[MAX_RSSI_SNIFFER_SCAN_LIST];         /* Array of UARFCNs for RSSI sniffer*/
} cphy_rssi_sniffer_start_req_struct;

typedef struct _cphy_rssi_sniffer_stop_req_struct
{
    LOCAL_PARA_HDR
} cphy_rssi_sniffer_stop_req_struct;


/*HSPDA*/
typedef struct _cphy_hsdsch_setup_req_struct
{
    
    LOCAL_PARA_HDR
    kal_int16               act_time;                               /*[meaning]: The activation time for this message. 
                                                                     TL1 will schedule the activation time to the TTI boundary. 
                                                                                         [Range]: (-1~255). (0-255) for CFN type, "-1" for immediate type.*/
//#ifdef __TDD128_HSPA_PLUS__
    kal_bool                h_rnti_valid;                           /*if H_RNTI valid*/
//#endif    
    kal_uint16              h_rnti;                                 /*H-RNTI assigned to UE*/
//#ifdef __TDD128_HSPA_PLUS__
    kal_uint16              prim_uarfcn;                           /*if H_RNTI valid*/
//#endif
    kal_uint16              work_uarfcn;                    /*Working uarfcn of the  UE  */                                                                                                                
    kal_uint16              cell_param_id;                 /*0-127,Cell parameter ID*/     
    hsscch_info_T           hsscch_info;                            /*HS-SCCH Information*/     
    midamble_info_T         hspdsch_midamble_info;                  /*HS-PDSCH Midamble Configuration*/     
    hs_harq_info_T          harq_info;                              /*Harq process & IR buffer information*/        
    kal_bool                mac_hs_reset;                           /*TRUE indicates the MAC-hs entity needs to be reset*/
    kal_uint8               mac_event;                              /*Indicate whether HS-DSCH events indication should be sent to MAC:
                                                                                                               Bit 0 : Setup; Bit 1 : Release ; Bit 2 : Modify
                                                                                                               And in this primitive, only Bit 0 can be set to 1*/
    hs_queue_info_T         queue_info;                             /*MAC-hs Queue Information*/    
   kal_uint8            pccpch_tx_power;                 /*[Range]: 6 ~ 43 by step 1 in dBm
                                                            [Meaning]:P-CCPCH transmit power*/  
   kal_int8          max_tx_power;                       /*[Range]: -50 ~ 33 dBm
                                                           [Meaning]: Max. allowed TX power.*/
   kal_int8          umts_power_class;                  /*UE capability(in dBm)
                                                           The value's unit  configured by SLCE is dBm. 
                                                           define MAX_OUTPUT_POWER_CLASS_1 33  :+33dBm 
                                                           define MAX_OUTPUT_POWER_CLASS_2 24 :  +24dBm 
                                                           define MAX_OUTPUT_POWER_CLASS_3 21 : +21dBm 
                                                           define MAX_OUTPUT_POWER_CLASS_4 27 : +27dBm */
//#ifdef __TDD128_HSPA_PLUS__
    kal_int16                           rscp;                           /* -500 ~ -100 means (-125 ~ -25 )dBm in 0.25 dB step,serving cell rscp*/
    kal_uint8                           capability_category;            /*[Meaning]: indicate TL1 to usewhich category (1,9,24)*/
	kal_uint8							tid;	/*Transation ID, used for reporting DL INIT SYNC*/
	rrc_state_E 	                     rrc_status;			/* Indicate the RRC current status */
    hspdsch_state_info_T               hspdsch_state_info;      
    kal_int32                           Tm;
	kal_int16                           Off;
	kal_uint8                           doff;
    dl_establish_T                     dl_sync_info;                   /*Downlink establishment criterion*/
    kal_bool                            c_h_rnti_valid;                 /*Indicate if common H-RNTI is valid for UL1. This field shall be set to FALSE when rrc_status is equal to CELL_DCH.*/
    kal_uint16                          c_h_rnti;                       /*Common H-RNTI assigned to UE, Never use in CELL_PCH/URA_PCH*/
    kal_bool                            b_h_rnti_valid;                     /* [R7] Indicate if bcch-specific H-RNTI is valid for UL1 */
    kal_uint16                          b_h_rnti;                           /* [R7] bcch-specific H-RNTI assigned to UE. UL1 should not refer to this field if b_h_rnti_valid = KAL_FALSE. */
//#endif
} cphy_hsdsch_setup_req_struct;

typedef struct _cphy_hsdsch_modify_req_struct
{
    LOCAL_PARA_HDR      
    kal_int16               act_time;                               /*[meaning]: The activation time for this message. TL1 will schedule 
                                                                                                                the activation time to the TTI boundary. [Range]: (-1~255). 
                                                                                                                (0-255) for CFN type, "-1" for immediate type.*/
//#ifndef __TDD128_HSPA_PLUS__
    /*kal_uint8               modify_field;*/                          
//#else  /*R8*/
    kal_uint16              modify_field;                       /*Bit field to represent for the parameters that should be modified
                                                                                          Bit 0 : H-RNTI, including D/B-HRNTI type; 
                                                                                          Bit 1 : HS-SCCH Info;
                                                                                          Bit 2 : HSPDSCH_midamble_info                                           
                                                                                          Bit 3 : HARQ Info; 
                                                                                          Bit 4 : Queue Info. 
                                                                                          Bit 5 : Uplink power control related parameters,such as
                                                                                                     "pccpch_tx_power", "max_tx_power" and "umts_power_class"  
                                                                                          Bit 6 : work_uarfcn
                                                                                          Bit 7 : capability_category
                                                                                          Bit 8 : hspdsch_state_info
                                                                                          Bit 9 : hs_cell_fach_drx_info
                                                                                          Bit 10: Tm,   NO USE now
                                                                                          Bit 11: Off,   NO USE now
                                                                                          Bit 12: doff,  NO USE now
                                                                                          Bit 13: dl_sync_info
                                                                                          Bit 14: cHrnti
                                                                                          Note: modify_field can be "0" only when mac_hs_reset = true. */  
                                                                                                                                                      
//#endif                                                        
    kal_uint16              h_rnti;                                 /*H-RNTI assigned to UE*/
    kal_uint16              work_uarfcn;                /*Working uarfcn of the  UE  */   
    hsscch_info_T           hsscch_info;                            /*HS-SCCH Information*/      
    midamble_info_T         hspdsch_midamble_info;                  /*HS-PDSCH Midamble Configuration*/     
    hs_harq_info_T          harq_info;                              /*Harq process & IR buffer information*/     
    kal_bool                mac_hs_reset;                           /*TRUE indicates the MAC-hs entity needs to be reset*/
    kal_uint8               mac_event;                              /*Indicate whether HS-DSCH events indication should be sent to MAC:
                                                                     Bit 0 : Setup; Bit 1 : Release ; Bit 2 : Modify
                                                                     And in this primitive, only Bit 2 can be set to 1*/
    hs_queue_info_T         queue_info;                             /*MAC-hs Queue Information*/
   kal_uint8            pccpch_tx_power;                  /*[Range]: 6 ~ 43 by step 1 in dBm
                                                            [Meaning]:P-CCPCH transmit power*/  
   kal_int8          max_tx_power;                        /*Range]: -50 ~ 33 dBm
                                                           [Meaning]: Max. allowed TX power.*/
   kal_int8          umts_power_class;                  /*UE capability(in dBm)
                                                           The value's unit  configured by SLCE is dBm. 
                                                           define MAX_OUTPUT_POWER_CLASS_1 33  :+33dBm 
                                                           define MAX_OUTPUT_POWER_CLASS_2 24 :  +24dBm 
                                                           define MAX_OUTPUT_POWER_CLASS_3 21 : +21dBm 
                                                           define MAX_OUTPUT_POWER_CLASS_4 27 :  +27dBm */ 
//#ifdef __TDD128_HSPA_PLUS__
    kal_uint8                           capability_category;            /*[Meaning]: indicate TL1 to usewhich category (1,9,24)*/
	kal_uint8							tid;	/*Transation ID, used for reporting DL INIT SYNC*/
    rrc_state_E 	                    rrc_status;              /*[R8] Specify that HS-DCH transmission type*/ 
    hspdsch_state_info_T                hspdsch_state_info;      
	kal_int32					Tm;
	kal_int16					Off;
	kal_uint8					doff;
	kal_int16					rscp;
    dl_establish_T                      dl_sync_info;                   /*Downlink establishment criterion*/
    kal_bool                            h_rnti_valid;                       /* Indicate if h_rnti field is valid for UL1. H-RNTI shall be always valid for CELL_DCH, CELL_FACH, IDLE_FACH, and shall be always invalid for URA_PCH. */
    kal_bool                            b_h_rnti_valid;                     /* [R7] Indicate if bcch-specific H-RNTI is valid for UL1 */
    kal_uint16                          b_h_rnti;                           /* [R7] bcch-specific H-RNTI assigned to UE. UL1 should not refer to this field if b_h_rnti_valid = KAL_FALSE. */
    kal_bool                            c_h_rnti_valid;                 /*Indicate if common H-RNTI is valid for UL1. This field shall be set to FALSE when rrc_status is equal to CELL_DCH.*/
    kal_uint16                          c_h_rnti;                       /*Common H-RNTI assigned to UE, Never use in CELL_PCH/URA_PCH*/
//#endif
} cphy_hsdsch_modify_req_struct;

typedef struct _cphy_hsdsch_release_req_struct
{
    LOCAL_PARA_HDR      
    kal_int16               act_time;                               /*[meaning]: The activation time for this message. TL1 will schedule the activation time to the
                                                                                                                TTI boundary. [Range]: (-1~255). (0-255) for CFN type, "-1" for immediate type.*/
    kal_bool                mac_hs_reset;                           /*TRUE indicates the MAC-hs entity needs to be reset*/
    kal_uint8               mac_event;                               /*Indicate whether HS-DSCH events indication should be sent to MAC:
                                                                      Bit 0 : Setup; Bit 1 : Release ; Bit 2 : Modify
                                                                      And in this primitive, only Bit 1 can be set to 1*/
} cphy_hsdsch_release_req_struct;

#ifdef __HSUPA_SUPPORT__ 
typedef struct _cphy_edch_setup_req_struct
{
    
    LOCAL_PARA_HDR
    kal_int16               act_time;                               /*[meaning]: The activation time for this message. L1 will schedule the activation time 
                                                                                                                to the TTI boundary. [Range]: (-1~255). (0-255) for CFN type, "-1" for immediate type.*/
//#ifdef __TDD128_HSPA_PLUS__ 
	kal_bool                e_rnti_valid;
//#endif
    kal_uint16              e_rnti;                                 /*E-RNTI assigned to UE.*/
//#ifdef __TDD128_HSPA_PLUS__
    kal_uint8            capability_category;                /*indicating which category [1,15] TL1 to use*/
//#else
   kal_bool             is_lowest_capability_category;      /*[Meaning]: indicate TL1 to use whether the lowest category or not.*/
//#endif
   kal_uint16              work_uarfcn;                /*Working uarfcn of the  UE  */                                                                                                              
       kal_uint16              cell_param_id;                 /*0-127,Cell parameter ID*/    
    kal_bool                edch_sched_info_valid;                  /*The following edch_sched_info valid or not.*/
    edch_sched_info_T       edch_sched_info;                        /*Scheduled Transmission Information.*/
    kal_bool                edch_non_sched_info_valid;              /*The following edch_sched_info valid or not.*/
    edch_non_sched_info_T   edch_non_sched_info;                    /*Non-Scheduled Transmission Information.*/
    epuch_info_T            epuch_info;                             /*E-PUCH Information, common to both scheduled and non-scheduled E-DCH transmission.*/
    edch_harq_info_T        edch_harq_info;                         /*Harq Configuration Information.*/
    kal_bool                mac_es_e_reset;                         /*TRUE indicates the MAC-es/e entity needs to be reset.*/
    kal_uint8               mac_event;                              /*Indicate whether E-DCH events indication should be sent to MAC:
                                                                                                               Bit 0 : Setup; Bit 1 : Release ; Bit 2 : Modify
                                                                                                               And in this primitive, only Bit 0 can be set to 1*/
//#ifdef __TDD128_HSPA_PLUS__
    edch_transmission_type_E    transmission_type;          /*[R8] specify that EDCH is allocated in dedicated state or common state*/
    common_edch_info_T           common_edch_info;           /*[R8]This field is only valid when transmission_type == EDCH_IN_COMMON_STATE*/
    kal_uint8                     pa_plus_valid_flag;         /*bitmask   bit0: eagch_drx_info_valid
                                                                                                                      bit1: edch_sps_info_valid*/
    eagch_drx_info_T             eagch_drx_param;            /*EAGCH DRX related param*/ 
    edch_sps_info_T              edch_sps_info;              /*EDCH SPS related param*/     
	kal_bool					ul_sync_flag;
	kal_uint16					t321;                  /*100, 200, 400, 800 ms*/
//#endif
} cphy_edch_setup_req_struct;

typedef struct _cphy_edch_modify_req_struct
{
    LOCAL_PARA_HDR      
    kal_int16               act_time;                               /*[meaning]: The activation time for this message. L1 will schedule 
                                                                                                                the activation time to the TTI boundary. [Range]: (-1~255). 
                                                                                                                (0-255) for CFN type, "-1" for immediate type.*/
//#ifdef __TDD128_HSPA_PLUS__
    kal_uint16              modify_field;             /*Bit0 ~ Bit6: refer to the below comments
                                                                                            Bit7 ~ Bit9: new added for PA+
                                                                                            Bit7: common edch info
                                                                                            Bit8: EAGCH DRX info
                                                                                            Bit9: EDCH SPS info*/
//#else
    //kal_uint8               modify_field;                           
                                                     /*Bit field to represent for the parameters that should be modified
                                                                                        Bit0: E-RNTI;
                                                                                        Bit1: scheduled mode information;
                                                                                        Bit2: non-scheduled mode information;
                                                                                        Bit3: e-puch information;
                                                                                        Bit4: HARQ information; 
                                                                                        Bit 5:  is_lowest_capablility_category .
                                                                                        Bit6: work_uarfcn
                                                                                        Note: modify_field can be "0" only when mac_e_es_reset = true. */
//#endif
    kal_uint16              e_rnti;                                 /*E-RNTI assigned to UE.*/
//#ifdef __TDD128_HSPA_PLUS__
	kal_uint8                capability_category;                /*indicating which category [1,15] TL1 to use*/
//#else
    kal_bool                 is_lowest_capability_category;     /*[Meaning]: indicate TL1 to use whether the lowest category or not.*/
//#endif
   kal_uint16              work_uarfcn;                /*Working uarfcn of the  UE  */    
        kal_bool                edch_sched_info_valid;                  /*Schedule EPUCH is valid or not after this msg.*/
    edch_sched_info_T       edch_sched_info;                        /*Scheduled Transmission Information.*/
        kal_bool                edch_non_sched_info_valid;              /*Non-schedule EPUCH isalid or notafter this msg.*/
    edch_non_sched_info_T   edch_non_sched_info;                    /*Non-Scheduled Transmission Information.*/
    epuch_info_T            epuch_info;                             /*E-PUCH Information, common to both scheduled and non-scheduled E-DCH transmission.*/
    edch_harq_info_T        edch_harq_info;                         /*Harq Configuration Information.*/
    kal_bool                mac_es_e_reset;                         /*TRUE indicates the MAC-es/e entity needs to be reset.*/
    kal_uint8               mac_event;                              /*Indicate whether E-DCH events indication should be sent to MAC:
                                                                                                               Bit 0 : Setup; Bit 1 : Release ; Bit 2 : Modify
                                                                                                               And in this primitive, only Bit 2 can be set to 1*/
//#ifdef __TDD128_HSPA_PLUS__
	edch_transmission_type_E    transmission_type;		 /*[R8] specify that EDCH is allocated in dedicated state or common state*/
	common_edch_info_T		   common_edch_info;		 /*[R8]This field is only valid when transmission_type == EDCH_IN_COMMON_STATE*/
	kal_uint8					pa_plus_valid_flag;			/*Bit0: DRX en/disable; Bit1: SPS en/disable*/
    eagch_drx_info_T             eagch_drx_param; 		 /*EAGCH DRX related param*/ 
	edch_sps_info_T	           edch_sps_info;			 /*EDCH SPS related param*/ 																				   
	kal_bool						e_rnti_valid;
//#endif

} cphy_edch_modify_req_struct;

typedef struct _cphy_edch_release_req_struct
{
    LOCAL_PARA_HDR      
    kal_int16               act_time;                               /*[meaning]: The activation time for this message. L1 will schedule the activation time to the
                                                                                                                TTI boundary. [Range]: (-1~255). (0-255) for CFN type, "-1" for immediate type.*/
    kal_bool      mac_es_e_reset;           /*TRUE indicates the MAC-es/e entity needs to be reset.*/
    kal_uint8               mac_event;                              /*Indicate whether EDCH events indication should be sent to MAC:
                                                                                                                  Bit 0 : Setup; Bit 1 : Release ; Bit 2 : Modify
                                                                                                               And in this primitive, only Bit 1 can be set to 1*/
} cphy_edch_release_req_struct;
#endif

//#if defined( __UMTS_R9__ ) && defined ( __AST3002__ )
typedef struct _cphy_measurement_config_dmo_req_struct
{
    LOCAL_PARA_HDR
    kal_int16              act_time;
	
    kal_uint8              dmo_bitmap;    
    dch_mo_info_T          dmo_pattern[MAX_DMO_PATTERN_NUM];    
}cphy_measurement_config_dmo_req_struct;
//#endif

typedef struct _cphy_measurement_config_idle_interval_req_struct
{
    LOCAL_PARA_HDR
    kal_uint8              k;
    kal_uint8              Offset;       
}cphy_measurement_config_idle_interval_req_struct;

/*****************************************************************************
 container request 
*****************************************************************************/

/*-------- Message(Primitive) related definition  ----------------------*/

typedef struct _msg_buf_T                          /* Buffer of message container */
{
   kal_uint8            channel_id;                   /* Channel ID */
   msg_type             msg_id;                       /* Message ID */
   kal_uint16           buff_size;                    /* Buffer size */
   local_para_struct*   buffer;                       /* Channel configuration message buffer */
} msg_buf_T;


typedef struct _cphy_msg_container_req_struct
{
    LOCAL_PARA_HDR 
    kal_uint8       at_ref;              /* Reference channge of activation time.
                                                                        0 : Ref channel is the released channel.
                                                                            There should be ch to be released
                                                                        1 : Ref channel is the setup channel.
                                                                            There should be ch to be setup. */
   /*
     meas_control_E   meas_control;                 // Indicate whether TL1 need to not to resume meas. after apply corresponding buffer's config. 
     kal_int8         idx_intra_freq;                     // [Range]: 0 ~ 2. Indicate which frequency in the array uarfcn[MAX_UMTS_FREQ] is intra-frequency, -1 means invalid  
   */                                                                
   kal_uint8        rab_domain_field;  /* BIT0: CS present, 
                                          BIT1: PS present */

   kal_int16        rx_cfn;            /* Indicate peer message receive cfn. Ex: tti = 4, receive frame number : 0,1,2,3.  rx_cfn = 3 (set by tl1)
                                                                        [Range]: -1 ~ 255.    
                                                                        -1 : Means upper layer internal control
                                                                      */
                                          
   kal_uint8        msg_num;            /* # of included msg. 1 ~ 4 */
   msg_buf_T        msg_buffer[4];      /* List of msg buffer for included channel msg */
   /* [R5R6] For HS-DSCH and E-DCH */
   kal_uint8        h_msg_num;          /* # of included H-msg. 0~2 */
   msg_buf_T        h_msg_buffer[2];    /* List of msg buffer for included channel msg */
   kal_uint8        e_msg_num;          /* # of included E-msg. 0~2 */
   msg_buf_T        e_msg_buffer[2];    /* List of msg buffer for included channel msg */

// #if defined (__UMTS_R9__) && defined (__AST3002__)
   kal_uint8        dmo_msg_num;        /* # of included dmo-msg. 0~1 */
   msg_buf_T        dmo_msg_buffer[1];  /* List of msg buffer for included channel msg */
//#endif   

} cphy_msg_container_req_struct;

typedef struct _cphy_abort_req_struct
{
    LOCAL_PARA_HDR
} cphy_abort_req_struct;

typedef struct _cphy_abort_bch_setup_req_struct
{
    LOCAL_PARA_HDR
} cphy_abort_bch_setup_req_struct;

#if defined (__GEMINI_GSM__) && defined (__UMTS_RAT__)
typedef struct _rsvas_tl1_suspend_req_struct
{
    LOCAL_PARA_HDR
} rsvas_tl1_suspend_req_struct;
typedef struct _rsvas_tl1_resume_req_struct
{
    LOCAL_PARA_HDR
} rsvas_tl1_resume_req_struct;
#endif

#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
typedef struct _cphy_channel_priority_adjustment_req_struct
{
    LOCAL_PARA_HDR
    kal_bool channel_priority_high;     /*TRUE: TL1 channel priority is set to high;*/
                                        /*FALSE: TL1 channel priority is set to normal */
	kal_int16 act_time;                  /*-1:active immediately,usually is -1 */
	                                      /*only dch modify and handover(R+S),the value is the real AT*/
} cphy_channel_priority_adjustment_req_struct;
typedef struct _urr_tl1_switch_gemini_mode_req_struct
{
    LOCAL_PARA_HDR
    kal_bool is_virtual_mode;       /*TRUE: TL1 will switch from normal mode to virtual mode;*/
                                    /*FALSE: TL1 will switch from virtual mode to normal mode */
} urr_tl1_switch_gemini_mode_req_struct;
typedef struct _rsvas_tl1_virtual_resume_req_struct
{
    LOCAL_PARA_HDR
} rsvas_tl1_virtual_resume_req_struct;
typedef struct _phy_channel_priority_adjustment_req_struct
{
    LOCAL_PARA_HDR
    kal_bool channel_priority_high;     /*TRUE: TL1 channel priority is set to high;*/
                                        /*FALSE: TL1 channel priority is set to normal */
} phy_channel_priority_adjustment_req_struct;

#endif

typedef struct _l4ctl1_get_rf_temperature_req_struct
{
   LOCAL_PARA_HDR
} l4ctl1_get_rf_temperature_req_struct;

typedef struct _l4ctl1_get_rf_temperature_cnf_struct
{
   LOCAL_PARA_HDR
   kal_int16 modem_temperature;
} l4ctl1_get_rf_temperature_cnf_struct;

typedef struct _l4ctl1_em_tst_control_req_struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;     
    tl1_em_tstcmdtype type;
    tl1_em_tstcmdpara param;
} l4ctl1_em_tst_control_req_struct;
/*****************************************************************************
 confirm & indication from TL1 to L4C 
*****************************************************************************/
typedef struct _l4ctl1_em_tst_control_cnf_struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_bool success;
}l4ctl1_em_tst_control_cnf_struct;
/*****************************************************************************
 confirm & indication from TL1 to SLCE 
*****************************************************************************/
typedef struct _cphy_bch_setup_cnf_struct
{
    LOCAL_PARA_HDR 
} cphy_bch_setup_cnf_struct;

typedef struct _cphy_bch_setup_ind_struct
{
    LOCAL_PARA_HDR 
    kal_bool    success;                            /* Indicate if BCH setup success.  For current TL1, it always return true.   */
} cphy_bch_setup_ind_struct;

typedef struct _cphy_bch_modify_cnf_struct
{
    LOCAL_PARA_HDR 
} cphy_bch_modify_cnf_struct;

typedef struct _cphy_bch_modify_ind_struct
{
    LOCAL_PARA_HDR 
} cphy_bch_modify_ind_struct;

typedef struct _cphy_bch_release_cnf_struct
{
    LOCAL_PARA_HDR 
} cphy_bch_release_cnf_struct;

typedef struct _cphy_bch_release_ind_struct
{
    LOCAL_PARA_HDR 
} cphy_bch_release_ind_struct;


typedef struct _cphy_sfn_ind_struct
{
    LOCAL_PARA_HDR
    kal_bool    success;            /*True/False. True: The SFN result is success. The SFN is in the following (tm, off).
                              False: The SFN reading is failed. The SFN in the following (tm, off) will be ignored.*/
    kal_int32   tm;                 /*[Range]: -1 ~ (6400*8-1). -1 for unknown timing.
                                 [Meaning]:Sub Frame boundary offset between target cell and LST
                                 For a cell with unknown tm value, it can not be issued to TL1. */
    kal_int16   off;             /*[Range]: -1~8191, (0-8191) for a cell whose Sub SFN offset to LST has been measured by TL1. -1 means off unknown.
                                 [Meaning]: Sub frame number offset between target cell and LST.
                                 For a cell with unknown off value, it can not be issued to TL1. */    
    kal_uint16  uarfcn;             /*uarfcn*/                                
    kal_uint16  cell_param_id;         /*[Range]: 0-127, CPID_INVALID
                              [Meaning]:Cell parameter ID*/
#if defined (__GEMINI_GSM__) && defined (__UMTS_RAT__)
    uas_gemini_conflict_cause_enum conflict_cause;   /*Channel conflict casue with peer channel*/
    kal_uint16 peer_priority_index;                  /* Channel conflict priority index with peer channel*/
#endif
} cphy_sfn_ind_struct;


typedef struct _cphy_t312_expiry_ind_struct
{
    LOCAL_PARA_HDR    
    kal_uint8   tid;                         /* Transaction id */       
 
} cphy_t312_expiry_ind_struct;

typedef struct _cphy_dl_init_sync_ind_struct
{
    LOCAL_PARA_HDR
    kal_uint8   tid;                        /* Transaction id */   
    kal_int32   dpch_tm;                    /* For CFN-SFN TD */
    kal_int16   dpch_off;                   /* For CFN-SFN TD */
} cphy_dl_init_sync_ind_struct;
 
typedef struct _cphy_rl_failure_ind_struct
{
    LOCAL_PARA_HDR 
    kal_bool   intrafreq_interference_flag;     /* TRUE: Indicate Radio Link Failure is caused by Intra-freq interference */
} cphy_rl_failure_ind_struct;

typedef struct _cphy_frequency_scan_cnf_struct
{
    LOCAL_PARA_HDR 
} cphy_frequency_scan_cnf_struct;

typedef struct _cphy_frequency_scan_ind_struct
{
    LOCAL_PARA_HDR 
} cphy_frequency_scan_ind_struct;

typedef struct _cphy_frequency_scan_suspend_cnf_struct
{
    LOCAL_PARA_HDR 
} cphy_frequency_scan_suspend_cnf_struct;

typedef struct _cphy_frequency_scan_suspend_ind_struct
{
    LOCAL_PARA_HDR 
 } cphy_frequency_scan_suspend_ind_struct;

typedef struct _cphy_frequency_scan_continue_cnf_struct
{
    LOCAL_PARA_HDR 
} cphy_frequency_scan_continue_cnf_struct;


typedef struct _cphy_measurement_config_cell_cnf_struct
{
    LOCAL_PARA_HDR 
} cphy_measurement_config_cell_cnf_struct;



typedef struct _cphy_measurement_cell_ind_struct
{
    LOCAL_PARA_HDR        
    kal_uint8    tid;                                               /*Transaction ID to synchronize between request and indication. 
                                                                                                                          Its value will be the same as the 'tid' field used in 
                                                                                                                          CPHY_MEASUREMENT_CONFIG_CELL_REQ. This field is unused for 
                                                                                                                          the frequency scan report.*/
    measured_type_T    measured_type;                               /*Measurement report type: INTRA_FREQUENCY_MEASURED, 
                                                                                                                          INTER_FREQUENCY_MEASURED,FREQ _SCAN_DETECTED,SERVING_ONLY
                                                                                                                          If UE works in the primary freq, the serving cell measurement is included 
                                                                                                                          in intra-freq measurement report. If it works in the second freq, the serving 
                                                                                                                          cell measurement is included in the inter-freq measurement report.*/ 
    kal_bool    iscp_included;                                      /*True: Indicate this message contains the iscp measurement result. 
                                                                                                                          This field is only used for INTRA-FREQUENCY report.*/
    kal_bool    fs_halt;                                            /*True: Frequency scan procedure is temporary halt. TL1 will wait for 
                                                                                                                          CPHY_FREQSCAN_CONTINUE_REQ. False: Frequency scan procedure 
                                                                                                                          is in progress. It can be set with 'TRUE' when report cell scan result. 
                                                                                                                          This field is only used for frequency scan report. This field is un-used 
                                                                                                                          for the cell measurement report.*/ 
    kal_int16   rssi[MAX_UMTS_FREQ];                                /*indicate the TS0's RSSI of each frequency  included in 'measured_cell[]'. 
                                                                                                                          Range: -400 ~ -100 means (-100 ~ -25) dBm 0.25 dB step. The sequence 
                                                                                                                          of frequency RSSI is same with 'measured_cell[]'*/
    kal_uint8   num_cell;                                           /*[range]: 0- MAX_NUM_REPORT_CELL Number of cells reported in this message*/                              
    measured_cell_T    measured_cell[MAX_NUM_REPORT_CELL];          /*List of measured cells' measurement result. TL1 may report multi-frequency's
                                                                                                                          measurement result in the same list, It is ascending sort by cell's uarfcn and
                                                                                                                          cell_param_id. Cells on the same frequency will be collected together. 
                                                                                                                          The cells on different frequencies will not be interleaved.*/
    kal_uint8   sinr;
    kal_bool    evaluate_req;
    kal_int8   tx_power;
    kal_bool                      isLongPeriodIn3GStandby;            /* [Rel8][ABPCR] For RR, Indicate if it is prio search peiorid*/                                                                                                                    
} cphy_measurement_cell_ind_struct;



typedef struct _cphy_specific_cell_search_ind_struct 
{ 
    LOCAL_PARA_HDR 
    kal_bool        success;                                        /* Indicate if search success */
    measured_cell_T measured_cell;                                  /* The found(1) cell */
} cphy_specific_cell_search_ind_struct;

typedef struct _cphy_specific_cell_search_stop_ind_struct
{
    LOCAL_PARA_HDR 
} cphy_specific_cell_search_stop_ind_struct;


/*reset&set rat*/
typedef struct _cphy_reset_cnf_struct
{
    LOCAL_PARA_HDR 
    kal_bool    success;                            /* Indicate whether the TL1 initialization sucess or fail 
                                       'True' - L1 successfully initialize itself.
                                       'False' - L1 fail to initialize itself.
                                       */
} cphy_reset_cnf_struct;


typedef struct _cphy_rf_on_cnf_struct
{
    LOCAL_PARA_HDR 
 } cphy_rf_on_cnf_struct;

typedef struct _cphy_rf_off_cnf_struct
{
    LOCAL_PARA_HDR  
} cphy_rf_off_cnf_struct;

typedef struct _cphy_set_active_rat_cnf_struct
{
    LOCAL_PARA_HDR 
} cphy_set_active_rat_cnf_struct;

/*tx status*/
typedef struct _cphy_tx_status_ind_struct
{
    LOCAL_PARA_HDR 
    kal_bool    is_tx_allow;              /* the current TX status
                                                                        TRUE : Currentlly, TX is available in TL1.
                                                                        FALSE : Currentlly, TX is not available in TL1. */
} cphy_tx_status_ind_struct;

/*gap status*/
typedef struct _cphy_gsm_gap_status_ind_struct
{
    LOCAL_PARA_HDR
    kal_bool is_bsic_gap_valid;
    
} cphy_gsm_gap_status_ind_struct;

/*internal measu*/
typedef struct _cphy_measurement_internal_config_cnf_struct
{
    LOCAL_PARA_HDR      
}cphy_measurement_internal_config_cnf_struct;

typedef struct _cphy_measurement_internal_event_ind_struct
{
    LOCAL_PARA_HDR
    kal_uint8   meas_id;                                            /*[Range] 1-16 Measurement Identity<TS25.331:10.3.7.48>*/
    internal_meas_event_E event_id;                                 /*indicate internal measurement event id*/
    tx_power_info_T tx_power_info;                                  /*The averaged TX power measurement result. It is a filter value with filter  
                                                                                                                      coefficient in 'MEASUREMENT CONTROL' indicated by meas_id.*/
    tadv_info_T tadv_info;                                          /*time advance */
} cphy_measurement_internal_event_ind_struct;

typedef struct _cphy_measurement_internal_periodic_ind_struct
{
    LOCAL_PARA_HDR
    kal_uint8 meas_id;                                              /*[Range] 1-16, Measurement Identity<TS25.331:10.3.7.48>*/
    kal_bool last_report;                                           /*True/False. True: Indicate that the 'report_num' is reached, 
                                                                                                                          and no more periodic report will be returned to RRC.*/
    tadv_info_T tadv_info;                                          /*time advance*/
    tx_power_info_T tx_power_info;                                  /*The averaged TX power measurement result.It is a filter value with filter 
                                                                                                                          coefficient in 'MEASUREMENT CONTROL' indicated by meas_id.*/
    
} cphy_measurement_internal_periodic_ind_struct;


typedef struct _cphy_measurement_internal_result_ind_struct
{
    LOCAL_PARA_HDR
    
    kal_uint8 meas_id;                                              /*[Range] 0-16, 0 is MEAS_ID_INVALID.
                                                                      [Meaning] it is the ¡®Measurement Identity¡¯ same as the request 
                                                                      meas_id in related cphy_measurement_internal_result_req_struct primitive.
                                                                      If Tl1 doesn¡¯t contain the meas_id as in cphy_measurement_internal_result_req_struct, 
                                                                      it will treat the meas_id as 0, and return Tx-Pwr value without filter.*/
    kal_int16 sir[MAX_TIMESLOT_PER_SUBFRAME];                       /*[Range]: -28 ...40 means(-14dB - 20dB ) in 0.5 dB step*/  
    tx_power_info_T tx_power_info;                                  /*The averaged TX power measurement result.*/
    tadv_info_T tadv_info;                                          /*time advance*/
    
} cphy_measurement_internal_result_ind_struct;


typedef struct _cphy_measurement_internal_stop_cnf_struct
{
    LOCAL_PARA_HDR    
} cphy_measurement_internal_stop_cnf_struct;
    



/*sniffer*/
typedef struct _cphy_rssi_sniffer_start_cnf_struct
{
    LOCAL_PARA_HDR    
} cphy_rssi_sniffer_start_cnf_struct;


typedef struct _cphy_rssi_sniffer_stop_cnf_struct
{
    LOCAL_PARA_HDR    

} cphy_rssi_sniffer_stop_cnf_struct;



typedef struct _cphy_rssi_sniffer_signal_appear_ind_struct
{
    LOCAL_PARA_HDR    
    kal_uint8   num_freq_list;                                   /*Number of freq for scan list of RSSI sniffer */
    kal_uint16  uarfcn_list[MAX_RSSI_SNIFFER_SCAN_LIST];         /* Array of UARFCNs on which cells are found */

} cphy_rssi_sniffer_signal_appear_ind_struct;


typedef struct _cphy_msg_container_cnf_struct
{
    LOCAL_PARA_HDR    

} cphy_msg_container_cnf_struct;

typedef struct _cphy_msg_container_ind_struct
{
    LOCAL_PARA_HDR
    kal_bool    success_flag;         
} cphy_msg_container_ind_struct;


typedef struct _cphy_abort_cnf_struct
{
    LOCAL_PARA_HDR 
    kal_bool    success;                 /* Indicate if abort request success
                                                                           TRUE : TL1 will back to the old channel configure.
                                                                           FALSE : TL1 will go forward to the new channel configure.*/                                                                     
} cphy_abort_cnf_struct;

#if defined (__GEMINI_GSM__) && defined (__UMTS_RAT__)
typedef struct _rsvas_tl1_suspend_cnf_struct
{
    LOCAL_PARA_HDR
} rsvas_tl1_suspend_cnf_struct;
#endif


/*****************************************************************************
 request from MAC to TL1 
*****************************************************************************/
typedef struct _phy_rach_data_req_struct
{
   LOCAL_PARA_HDR 
   kal_uint16   tfci;                               /* TFCI. 0 ~ 1023 */
   ulTrchData   TrchInfo;                           /* UL TrCH information */
   kal_uint16   size_data;                          /*  This parameter represents the number of bytes of the buffer. This number will be equal to the size of allocated buffer plus 4 bytes. */
   kal_uint8    *data[MAX_UL_TB];                   /* data for each TB. PS shoul allocate the buffer */
#ifdef __HSUPA_SUPPORT__
   access_type_E    access_type;                    /*Type of random access, RACH or E-RUCCH.
                                                                                       [Notes]:
                                                                                       #1. Fixed parameters for E-RUCCH:
                                                                                             TrchInfo.trchId = 0, TrchInfo.tb_size = 39(23 + 16), TrchInfo.num_tb = 1,
                                                                                             tfci = 0, size_data = 9(5 + 4).
                                                                                       #2. Data layout:
                                                                                             Padding(1bit) + SNPL(5bits) + UPH(5bits) + TEBS(5bits) + HLBS(4bits) + HLID(4bits) + E-RNTI(16bits)
                                                                                       #3. TL1 shall fill the following parameters:
                                                                                             SNPL, bit6/byte0 ~ bit2/byte0;
                                                                                             UPH, bit1/byte0 ~ bit5/byte1.*/
#endif
} phy_rach_data_req_struct;

typedef struct _phy_access_req_struct
{
    LOCAL_PARA_HDR
    kal_bool    retry;                              /*True: RACH transmission failed in the last access procedure,
                                                                                              and TL1 will use the same RACH data and ASC as in the last access procedure.
                                                                                              False: It¡¯s a new RACH procedure. TL1 will apply new RACH data and ASC from MAC.*/    
    kal_uint8   asc;                                /*The index value of configured asc array.*/
#ifdef __HSUPA_SUPPORT__
    access_type_E   access_type;                    /*Type of random access, RACH or E-RUCCH.*/
#endif

//#ifdef __TDD128_HSPA_PLUS__
	erucch_access_type_E	erucch_type;    /*ERUCCH type: CELL RESELECTION IND, UL SYNC ORDER, or SI REQUEST*/
//#endif
} phy_access_req_struct;

/*****************************************************************************
 indication from TL1 to MAC  
*****************************************************************************/

typedef struct _phy_pch_setup_ind_struct
{
    LOCAL_PARA_HDR 
} phy_pch_setup_ind_struct;

typedef struct _phy_pch_release_ind_struct
{
    LOCAL_PARA_HDR  
} phy_pch_release_ind_struct;

typedef struct _phy_fach_setup_ind_struct
{
    LOCAL_PARA_HDR  
} phy_fach_setup_ind_struct;


typedef struct _phy_fach_release_ind_struct
{
    LOCAL_PARA_HDR  
} phy_fach_release_ind_struct;

typedef struct _phy_rach_setup_ind_struct
{
    LOCAL_PARA_HDR  
} phy_rach_setup_ind_struct;

typedef struct _phy_rach_release_ind_struct
{
    LOCAL_PARA_HDR  
} phy_rach_release_ind_struct;

typedef struct _phy_dch_setup_ind_struct
{
    LOCAL_PARA_HDR 
    direction_E     direction;                      /* Indicate UL or DL is being setup, 0 : DL , 1 : UL*/
    kal_uint16      sfn;                            /* [Range]: 0 ~4095
                                                                                        [Meaning]: when DL DCH is setup. (Only used for downlink).*/
} phy_dch_setup_ind_struct;

typedef struct _phy_dch_modify_ind_struct
{
    LOCAL_PARA_HDR
    direction_E       direction;                    /* Indicate UL or DL is being setup, 0 : DL , 1 : UL*/                        
} phy_dch_modify_ind_struct;

typedef struct _phy_dch_release_ind_struct
{
    LOCAL_PARA_HDR
    direction_E     direction;                      /* Indicate UL or DL is being setup, 0 : DL , 1 : UL*/
    kal_uint16      sfn;                            /* [Range]: 0 ~4095
                                                                                        [Meaning]: when DL DCH is released. (Only used for downlink).*/
} phy_dch_release_ind_struct;

typedef struct _phy_config_abort_ind_struct
{
    LOCAL_PARA_HDR 
    kal_bool    success;                            /* Indicate if abort request success
                                                                                        TRUE : TL1 will back to old channel configure
                                                                                        FALSE : TL1 will go forward to new channel configure*/
} phy_config_abort_ind_struct;

typedef struct _phy_dl_init_sync_ind_struct
{
    LOCAL_PARA_HDR

} phy_dl_init_sync_ind_struct;


typedef struct _phy_bch_data_ind_struct
{
    LOCAL_PARA_HDR
    kal_uint8   *data;                              /*  Used by PS only. TL1 would assign it as ¡°NULL¡±*/
    kal_bool    no_path;                            /* True/False. True:  it means TL1 could not find the cell 
                                                                                        other parameter should be ignored and protocol should release this BCH channel.
                                                                                        False: This cell has been found */
    kal_int32   tm;                                 /* [Range ]:  -1 ~ 6400*8-1 , -1 means unknown timing
                                                                                        [Meaning]: Sub Frame boundary offset between target cell and LST*/
    kal_int16   off;                                /* [Range]: -1~8191, -1 for off unknown cell.
                                                                                        [Meaning]: Sub frame number offset between target cell and LST.*/
    kal_int16   rx_sfn;                             /* [Range]: 0 ~4095  
                                                                                        [Meaning]: The sfn where the SIB/MIB is received.*/
    kal_uint16  uarfcn;                             /* uarfcn*/
    kal_uint16  cell_param_id;                      /* [Range]: 0-127, CPID_INVALID
                                                                                        [Meaning]:Cell parameter ID*/   
    kal_uint8   crc_status;                         /* 0: crc_error, 1: crc_ok, 2: no_crc*/
    kal_int16   rssi;                               /* [Range]: -400 ~ -100 means (-100 ~ -25) dBm 0.25 dB step.
                                                                                        [Meaning]: TS0¡¯s RSSI.*/
    kal_int16   rscp;                               /* [Range]: -500 ~ -100 means (-125 ~ -25 )dBm in 0.25 dB step
                                                                                        [Meaning]: Serving cell RSCP.*/
    kal_bool    standby_no_gap;        /* True: L1 has no enough gap time for SIB reception */

                                                                                 
#if defined (__GEMINI_GSM__) && defined (__UMTS_RAT__)
    uas_gemini_conflict_cause_enum conflict_cause;   /*Channel conflict casue with peer channel*/
    kal_uint16 peer_priority_index;                  /* Channel conflict priority index with peer channel*/
#endif
} phy_bch_data_ind_struct;

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct _phy_data_ind_struct
{
    LOCAL_PARA_HDR
    cctrch_type_E    dl_cctrch;                       /*For PCH, FACH or DCH CCTRCH.*/   
    kal_uint8    rx_fn;                               /*0-255.This is the FN of the last frame in the TTI that was received. 
                                                                                               When DCH channel is activated, the reported FN is the true DCH CFN. 
                                                                                               When DCH channel is not activated, FN is the value of (SFN%256).*/   
    kal_uint16   rx_sfn;                                                                                              
    kal_uint16   uarfcn;                              /*uarfcn*/    
    kal_uint16   cell_param_id;                       /*0-127,Cell parameter ID*/
    kal_uint8    num_trch;                            /*Number of Trch*/   
    dlTrchData   TrchInfo[MAX_TRCH_NUM];              /*Downlink TRCH information. When TL1 is configured in Loopback mode 2, 
                                                                                                  the tb_size specifies the total of data bits and crc bits.*/
    kal_uint32   crc;                                 /*The crc result (Pass/Fail) for each TB. A bit 1 represents for "Pass', and 0 for"Fail"*/
    kal_uint16   num_data;                            /*The size in byte of the buffer containing the data. It is the exact size of data, 
                                                                                                including the byte for TB number.*/
    #ifndef __TL1_UT_TEST__
    kal_uint8    *data;                               /*The buffer contains data for each TB received in this min TTI. This buffer is allocated
                                                                                                by TL1,and freed by PS. The buffer is from ADM. The first byte in the data indicates the number 
                                                                                                of TB in this data indication*/   
    #else
    kal_uint8    data[1000];
    #endif
    kal_uint32   raw_crc;                             /*Unmodified CRC for speech decoder */   
    kal_uint32   s_value[MAX_TRCH_NUM];               /*Viterbi decoder output S value for speech decoder */  
    kal_int16    tpc_SIR_lta;                         /*The measured SIR value of DPCH TPC field. It is TL1D debugging information for speech quality.*/
    kal_int16    dpch_SIR_lta;                        /*The measured SIR value of DPCH pilot field. It is TL1D debugging information for speech quality.*/
    kal_int16    TFCI_max_corr;                       /*The measured correlation value of DPCH TFCI field from TFCI decoder.
                                                                                          It is TL1D debugging information for speech quality.*/
#if defined (__GEMINI_GSM__) && defined (__UMTS_RAT__)
    uas_gemini_conflict_cause_enum conflict_cause;   /*Channel conflict casue with peer channel*/
#endif
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
    kal_uint8   rx_suspend;                          /*It is a bitmap to indicate if some TrCH is conflicted with SIM2 gap.*/
                                                    /* The bit is set to "1" only when the TrCH TTI ends in this frame and SIM2 gap exists in this TTI.*/
                                                    /* LSB bit is mapped to trchInfo[0].*/
#endif
//#if defined( __UMTS_R9__ ) && defined ( __AST3002__ )
    kal_uint8		meas_occasion_ind;
//#endif
    kal_int8    pi_repeat_cycle;/* -1:invalid, -2:retransmission with CRC pass, 1~20:valid pi_repeat_cyle */

   /* serving cell information for speech debug. */
   /* These values are valid only when DCH state and RL exists, otherwise, the value will be "0". */
   kal_uint8                     RSSI;
   kal_uint8                     RSCP;
   kal_uint8                     ECIO;
   kal_uint8                     HHO_SHO;

} phy_data_ind_struct;

typedef struct _phy_access_ind_struct
{
    LOCAL_PARA_HDR
    access_status_E access_status;                      /* The result of RACH access */
#ifdef __HSUPA_SUPPORT__
    access_type_E   access_type;                        /*Type of random access, RACH or E-RUCCH.*/
#endif

//#ifdef __TDD128_HSPA_PLUS__
	erucch_access_type_E	erucch_type;        /*ERUCCH type: CELL RESELECTION IND, UL SYNC ORDER, or SI REQUEST*/
//#endif
} phy_access_ind_struct;


typedef struct _phy_post_tx_ind_struct
{
    LOCAL_PARA_HDR

    post_tx_type_E  post_tx_type;
    kal_uint8   cfn;     
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
    kal_bool    is_tx_suspend;                      /*It indicates if there is SIM2 gap in the minTTI period of the released ul data. For RACH, this flag is always false*/
#endif
} phy_post_tx_ind_struct;


typedef struct _phy_end_dch_tx_ind_struct
{
    LOCAL_PARA_HDR
    
    kal_uint8  cfn;                                     /*When MAC receives PHY_END_DCH_TX_IND, it's possible that time has
                                                                                             passed more than one TTI. So give this cfn value for MAC to handle 
                                                                                             remaining things at the right CFN*/
    
} phy_end_dch_tx_ind_struct;


typedef struct _cphy_measurement_config_idle_interval_cnf_struct
{
    LOCAL_PARA_HDR  
} cphy_measurement_config_idle_interval_cnf_struct;


//#ifdef __TDD128_HSPA_PLUS__
typedef struct _phy_erucch_access_ind_struct
{
	LOCAL_PARA_HDR
	erucch_access_type_E    access_type;		/*the type of TL1 triggerring ERUCCH Procedure,
                                                                                UL_SYNC_ORDER or CELL_RESELECTION_IND*/
}phy_erucch_access_ind_struct;
//#endif

typedef struct _phy_hsdsch_data_ind_struct
{
    LOCAL_PARA_HDR      
    kal_uint16          sub_cfn;                        /*[Range]: 0-511.*/
    kal_uint8           config_operation;               /*Bit 0: HS-DSCH setup; Bit1: HS-DSCH release; Bit 2: HS-DSCH modify*/
    kal_bool            mac_hs_reset;                   /*When TL1 does MAC-hs reset , the flag is set to tell MAC (it is also needed in 
                                                                                             setup and release cases, not only for modify indication)*/  
    kal_uint8           size_info_modified;             /*Bitmask of maximum 8 MAC-hs queues, with size info list modified
                                                                                             Bit 0: queue_id = 0; Bit 1: queue_id = 1; ¡­;Bit 7: quque_id = 7*/
    hsdsch_data_T       hsdsch_data;                    /*The received MAC-hs data descriptor*/
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
    kal_bool            is_rx_suspend;                  /*It indicates if there is SIM2 gap in the TTI receiving dsch data*/
#endif
//#if defined( __UMTS_R9__ ) && defined ( __AST3002__ )
    kal_uint8           meas_occasion_ind;              /*bit0 indicates whether it is in DCH measurement occasion;
                                                          bit1 indicates whether it is in idle interval for E-UTRA Measurement.*/
//#endif
} phy_hsdsch_data_ind_struct;

#ifdef __HSUPA_SUPPORT__

typedef struct _phy_end_edch_tx_ind_struct
{
    LOCAL_PARA_HDR      
    kal_uint16          sub_cfn;                        /*[Range]: 0-511.*/
    
    
    kal_uint8           harq_id;                        /*[Range]: 0~7 [Meaning]: Harq process id.*/
} phy_end_edch_tx_ind_struct;
#endif

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 functions to SLCE/MEME   
*****************************************************************************/


//void tl1_info (L1_info_struct* L1_info_struct_ptr);
kal_bool tl1_active_time_difference();

/*------------------- Function prototype -----------------------------*/
/* TL1 provides this function to other entities to get current CFN & SFN 
   CFN : -1 ~ 255. 0 ~ 255 if UE in DCH/FACH mode otherwise -1
   SFN : -1 ~ 4095. 0 ~ 4095 for the base station frame number. -1 for an invalid value.*/
void TL1_GetCurrentTime(kal_int16 *cfn, kal_int16 *sfn);     

extern kal_bool Tl1_FreeDataBuf(kal_uint8 type, kal_uint8* rel_buffer_ptr);

typedef struct _tl1_data_buf_info_T
{
    kal_uint8  min_left_data_buffers;
    kal_uint8  min_left_hsdsch_buffers;
}tl1_data_buf_info_T;

extern void     TL1_GetDataBufInfo(tl1_data_buf_info_T *tl1_data_buf_info_ptr);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

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
#endif

//#if defined (__UMAC_DCH_LISR__) || defined (__HSUPA_SUPPORT__)
typedef void (*pul_inform_MAC)(void *data);
//#endif


//#ifndef __UMAC_DCH_LISR__
//extern void UMAC_UL_DCH_Tick(uldch_data_req_T * uldch_data_req);
//extern void UMAC_UL_DCH_Tick_End(kal_bool tx_suspend,tx_enable_type_E tx_enable,uldch_data_ind_T * uldch_data_ind);
//#else
extern void TL1D_L2PutHISRDCHQueue(pul_inform_MAC func, void *data);
//#endif

extern void ul_inform_MAC(kal_uint8 cfn);

extern void ul_dpch_power(kal_uint8 cfn, kal_uint8 tfc_status[MAX_UL_TFC]);

extern uldch_data_ind_T* UMAC_UL_DCH_Tick_Low_Lisr(uldch_data_req_T * uldch_data_req);
extern void TL1_OTD_Calculation(kal_int16 off_s, kal_int16 off_n, 
                                       kal_int32 tm_ec_s, kal_int32 tm_ec_n, 
                                       kal_int16 *off_opt, kal_int32 *tm_ec_opt);

extern kal_int8 TL1_SelectSyncUlFpach(kal_uint8 *sync_ul_bitmap, kal_int8 num_fpach);   /*Return index of FPACH in FPACH set.*/

extern void mac_hs_get_pdu_buffer(kal_uint8 **buffer_ptr, kal_uint16 size);

extern void try_to_trigger_CSR_STATUS_IND_LISR(kal_uint8 cfn);
extern void TL1D_L2PutHISRCsrQueue(pul_inform_MAC func, void *data);


extern void mac_hs_get_variable_pdu_buffer(kal_uint8   **buffer_ptr, kal_uint32 num);
/*hs pdu buffer free shall only be invoked by UMAC, so no extern here	*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern void mac_r4_get_variable_pdu_buffer(kal_uint8   **buffer_ptr, kal_uint32 num);


#ifdef __HSUPA_SUPPORT__
/* Data path interface from TL1D, LISR / HISR / Task not decided yet */
extern etfc_eval_info_ind_T* umac_e_dch_tick_1(etfc_eval_info_req_T *etfc_eval_input);

extern edch_data_ind_T* umac_e_dch_tick_2(edch_data_req_T *edch_data_input);

extern void umac_e_dch_tick_3(kal_uint8 harq_id, tdd128_modulation_E modulation);

extern void umac_e_dch_tick_4(void);  /*for MTK in-hourse project only*/

extern void ul_inform_Edch_MAC(void  *data);

extern void TL1D_L2PutHISRQueue(pul_inform_MAC func, void *data);

/*TL1 return the Non-Scheduled Tx TTIs in the specified extended estimation window.*/
extern kal_uint8 tl1_eval_ext_est_wnd(kal_uint8 ext_est_wnd);
#endif

/*****************************************************************************
 UMAC UT SIMULATE MESSAGE
*****************************************************************************/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct 
{
    kal_uint8		  ref_count;
    kal_uint16		  msg_len;

    kal_uint8         cfn;
    kal_uint8         ul_mac_event;     /* bit 0: UL DCH setup,   */ 
                                                   /* bit 1: UL DCH release, */
                                                  /* bit 2: UL DCH modify   */
    tx_enable_type_E  tx_enable;         /* set true if TX data could be sent (min TTI) */
    kal_bool          tx_suspend;
    kal_uint8         tfc_status[MAX_UL_TFC];
  	kal_uint8		meas_occasion_ind;
}phy_simulate_dch_ul_cctrch_lisr_struct;

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
#endif

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
#endif

typedef struct 
/*UMAC*/{
/*UMAC*/    kal_uint8							ref_count;
/*UMAC*/    kal_uint16							msg_len;
/*UMAC*/
/*UMAC*/    kal_uint8 cfn;
/*UMAC*/   kal_uint8         num_trch;   
/*UMAC*/   ulTrchData        trchInfo[MAX_TRCH_NUM]; 
/*UMAC*/   kal_uint16        tfci;
/*UMAC*/   kal_uint16        num_data[MAX_TRCH_NUM]; 
/*UMAC*/   kal_uint8         *data[MAX_TRCH_NUM];
}phy_simulate_dch_ul_cctrch_lisr_rsp_struct;

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
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

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
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

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
#endif

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
#endif

#ifdef __HSUPA_SUPPORT__
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;

    etfc_eval_info_req_T etfc_eval_input;
}phy_simulate_umac_e_dch_tick_1_struct;


typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;

    etfc_eval_info_ind_T  etfc_eval_info_ind;
}phy_simulate_umac_e_dch_tick_1_rsp_struct;


typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;

    edch_data_req_T  edch_data_input;
}phy_simulate_umac_e_dch_tick_2_struct;


typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;

    edch_data_ind_T  edch_data_ind;
}phy_simulate_umac_e_dch_tick_2_rsp_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;

    kal_uint8   harq_id;
    tdd128_modulation_E modulation;
}phy_simulate_umac_e_dch_tick_3_struct;
#endif

/*****************************************************************************
 MSC Composer
*****************************************************************************/
/* The following definition is used only for MSC composer.      */
typedef union _local_para_unpack_T
{
   cphy_pch_setup_req_struct     cphy_pch_setup_req;
   cphy_pch_modify_req_struct    cphy_pch_modify_req;
   cphy_pch_release_req_struct   cphy_pch_release_req;
   cphy_fach_setup_req_struct    cphy_fach_setup_req;
   cphy_fach_release_req_struct  cphy_fach_release_req;
   cphy_dch_setup_req_struct     cphy_dch_setup_req;
   cphy_dch_modify_req_struct    cphy_dch_modify_req;
   cphy_dch_release_req_struct   cphy_dch_release_req;
   cphy_rach_setup_req_struct    cphy_rach_setup_req;
   cphy_rach_release_req_struct  cphy_rach_release_req;
   cphy_hsdsch_setup_req_struct     cphy_hsdsch_setup_req;
   cphy_hsdsch_modify_req_struct    cphy_hsdsch_modify_req;
   cphy_hsdsch_release_req_struct   cphy_hsdsch_release_req;
#ifdef __HSUPA_SUPPORT__
   cphy_edch_setup_req_struct       cphy_edch_setup_req;
   cphy_edch_modify_req_struct      cphy_edch_modify_req;
   cphy_edch_release_req_struct     cphy_edch_release_req;  
#endif
   cphy_measurement_config_dmo_req_struct cphy_measurement_config_dmo_req;
} local_para_unpack_T;

typedef struct _msg_buf_unpack_T                /* Buffer of message container */
{
   kal_uint8         channel_id;                   /* Channel ID */
   msg_type          msg_id;                       /* Message ID */
   kal_uint16        buff_size;                    /* Buffer size */
   local_para_unpack_T         buffer;             /* Channel configuration message buffer */
} msg_buf_unpack_T;

typedef struct _cphy_msg_container_req_unpack_struct
{
    LOCAL_PARA_HDR  
    kal_uint8           at_ref;                     /* Reference channge of activation time.
                                                                                                0 : Ref channel is the released channel.
                                                                                                    There should be ch to be released
                                                                                                1 : Ref channel is the setup channel.
                                                                                        There should be ch to be setup.*/

    /*
    meas_control_E      meas_control;               // Indicate whether TL1 need to not to resume meas. after apply corresponding buffer's config. 
    kal_int8            idx_intra_freq;             // [Range]: 0 ~ 2. Indicate which frequency in the array uarfcn[MAX_UMTS_FREQ] is intra-frequency, -1 means invalid    
    */                                                                      
    kal_uint8           rab_domain_field;           /* BIT0: CS present, 
                                                       BIT1: PS present */
                                                       
    kal_int16        rx_cfn;            /* Indicate peer message receive cfn. Ex: tti = 4, receive frame number : 0,1,2,3.  rx_cfn = 3 (set by tl1)
                                                                        [Range]: -1 ~ 255.    
                                                                        -1 : Means upper layer internal control
                                                                      */
                                                                      
    kal_uint8           msg_num;                    /* # of included msg. 1 ~ 4 */
    msg_buf_unpack_T    msg_buffer[4];              /* List of msg buffer for included channel msg */

    /* [R5R6] For HS-DSCH and E-DCH */
    kal_uint8                     h_msg_num;                            /* # of included H-msg. 0~2 */
    msg_buf_unpack_T              h_msg_buffer[2];                      /* List of msg buffer for included channel msg */
    kal_uint8                     e_msg_num;                            /* # of included E-msg. 0~2 */
    msg_buf_unpack_T              e_msg_buffer[2];                      /* List of msg buffer for included channel msg */
    
//#if defined( __UMTS_R9__ ) && defined ( __AST3002__ )
    kal_uint8                     dmo_msg_num;          /* # of included dmo-msg. 0~1 */
    msg_buf_unpack_T              dmo_msg_buffer[1];    /* List of msg buffer for included channel msg */
    //#endif

} cphy_msg_container_req_unpack_struct;

typedef struct _cphy_channel_quality_status_ind_struct
{
	LOCAL_PARA_HDR
	kal_bool is_triggered;
} cphy_channel_quality_status_ind_struct;

//add for TDD SAR
#if 1 //__TDD_TX_PWR_REDUCE__
typedef struct _tl1_umts_max_tx_pwr_red_req_struct
{
    LOCAL_PARA_HDR
    kal_bool   valid;
    kal_uint8  umts_power_reduction_in_edb[20][2];
         /*SAR_BAND_UMTS_TDSCDMA_A_BAND_2010 = 21; [0][0],[0][1] (first for no upa or dpa, second for upa or dpa)
                  SAR_BAND_UMTS_TDSCDMA_F_BAND_1880 = 22;   [1][0],[1][1]
                  SAR_BAND_UMTS_TDSCDMA_E_BAND_2300 = 23;   [2][0],[2][1]
                  SAR_BAND_UMTS_TDSCDMA_A_BAND_1900 = 24;   [3][0],[3][1]
                  SAR_BAND_UMTS_TDSCDMA_B_BAND_1850 = 25;   [4][0],[4][1]
                  SAR_BAND_UMTS_TDSCDMA_C_BAND_1910 = 27;   [5][0],[5][1]
                  SAR_BAND_UMTS_TDSCDMA_D_BAND_2570 = 28;   [6][0],[6][1]*/
}tl1_umts_max_tx_pwr_red_req_struct;
#endif

#ifdef __SGLTE__
/*add for b3 and b39 feature*/
typedef struct _gas_tl1_disable_b39_tx_req_struct
{
    LOCAL_PARA_HDR
    kal_bool is_disable_valid;   /* TRUE: use tx suspend, FALSE:use reduce tx power */
	kal_uint8 list_len;          /* b3_info_list valid num*/
    gl1_b3_info_struct b3_info_list[MULTIPLE_B3_INFO_NUM]; /*2g b3 high band info,contain:is_working_freq,index,arfcn,rssi
                                                             but now is only use index and rssi*/
}gas_tl1_disable_b39_tx_req_struct;
#endif

extern kal_uint32 tl1_is_tdd_hw_exist(void);

#endif
