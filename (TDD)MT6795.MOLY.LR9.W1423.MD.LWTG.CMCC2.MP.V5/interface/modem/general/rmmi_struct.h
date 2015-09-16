/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   rmmi_strcut.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *============================================================================
 ****************************************************************************/

#ifndef __RMMI_STRUCT_H__
#define __RMMI_STRUCT_H__
//#include "kal_non_specific_general_types.h"
#include "kal_general_types.h"
//#include "l4c_common_enum.h"
#include "ps_public_enum.h"

#ifndef __MTK_TARGET__
#include "dcl.h" //for DCL_DEV_T
#endif

typedef struct{
	kal_uint8 ref_count;
	kal_uint16 data_length;  
	kal_uint8 data[256];
} rmmi_inject_msg_req_struct;

typedef struct{
	kal_uint8 ref_count;
	kal_uint16 data_length;
	kal_uint8 data[256];
} rmmi_inject_msg_cnf_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} rmmi_atcidt_force_transfer_req_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 port;   
    kal_bool is_dt; 
} rmmi_atcidt_force_transfer_cnf_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    rmmi_sim_uart_setting_enum sim_setting;
} rmmi_master_sim_change_req_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;   
} rmmi_master_sim_change_cnf_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 ch_num;   
} rmmi_register_channel_req_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint8 begin_port_id;   
} rmmi_register_channel_cnf_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 port_id;
    kal_uint16 length;   
} rmmi_exe_at_req_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint8 port_id;
} rmmi_exe_at_cnf_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 port_id;
    kal_uint16 length;   
} rmmi_response_at_ind_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 length;   
} rmmi_urc_at_ind_struct;

typedef struct rmmi_rsp_mode_struct
{
    kal_uint32 echo_flag;        /* rmmi_cmd_echo_enum */
    kal_uint8 suppress_flag;    /* rmmi_result_code_suppress_enum */
    kal_uint8 format;           /* rmmi_result_code_format */
    kal_uint8 ext_result_code;
} rmmi_rsp_mode_struct;

typedef struct rmmi_report_mode_struct
{
    kal_uint32 einfo;         /* proprietary +ECPI: call progress information */	
    kal_uint32 ecpi;         /* proprietary +ECPI: call progress information */
    kal_uint32 eind;         /* proprietary +EIND: general indication */ /* Bit 0(SMS ready), Bit 1(PHB ready), Bit 7(AT ready), others reserved */
    kal_uint8 ccm;          /* rmmi_report_mode_enum */
    kal_uint8 acm_warning;  /* rmmi_report_mode_enum */
    kal_uint8 call_wait;    /* rmmi_report_mode_enum */
    kal_uint8 cdip;         /* rmmi_report_mode_enum */
    kal_uint8 clip;         /* rmmi_report_mode_enum */
    kal_uint8 clir;         /* rmmi_report_mode_enum */
    kal_uint8 cnap;         /* rmmi_report_mode_enum */
    kal_uint8 colp;         /* rmmi_report_mode_enum */
    kal_uint8 ss_mo;        /* rmmi_report_mode_enum */
    kal_uint8 ss_mt;        /* rmmi_report_mode_enum */
    kal_uint8 ussd;         /* rmmi_report_mode_enum */
    kal_uint8 compression;  /* rmmi_report_mode_enum */
    kal_uint8 ps_reg;       /* rmmi_nw_reg_report_mode_enum */
    kal_uint8 cs_reg;       /* rmmi_nw_reg_report_mode_enum */
    kal_uint8 timezone;     /* rmmi_report_mode_enum */
    kal_uint8 crc;          /* rmmi_report_mode_enum, for +CRC */
    kal_uint8 cr;           /* rmmi_report_mode_enum, for +CR */
    kal_uint8 ecsq;
    kal_uint8 ecsq_count;
    kal_uint8 cgerep;
    kal_uint8 cmer_mode;
    kal_uint8 cmer_keyp;
    kal_uint8 cmer_ind;
    kal_uint8 cmer_bfr;
#if defined(__MMI_FMI__)
    kal_uint8 cmer_tscrn;
#else
    kal_uint8 esims;
#endif
    kal_uint8 eusim;
    kal_uint8 etestsim;
#if defined(__MOD_TCM__) //&& !defined(__MMI_FMI__)
    kal_uint8 psbearer_indicate;  // for +PSBEARER
#endif
    kal_uint8 pacsp;
#ifdef __CSG_SUPPORT__
    kal_uint8 ecsg;
#endif
#ifdef __IMS_SUPPORT__
    kal_uint8 cireg;
    kal_uint8 cirep;
    kal_uint8 cnem;
#endif
    kal_uint8 ecell;
    kal_uint8 evocd;
    kal_uint8 ecode33_mode;
} rmmi_report_mode_struct;

#ifdef __OP01__
typedef struct rmmi_op01_report_mode_struct
{
    kal_uint8 dsci;
    kal_uint8 rfsw;
    kal_uint8 cardmode;
} rmmi_op01_report_mode_struct;
#endif


/* this structure is used to let custom config the rmmi default setting*/
typedef struct{
    rmmi_rsp_mode_struct rsp_mode;
    kal_uint8 error_report_mode;        //  /* +CMEE <mode>: rmmi_error_report_mode_enum */
    kal_uint8 char_set; //+CSCS
    kal_uint8 plmn_format;
    kal_uint8 cops_mode;
    kal_uint8 CPOL_plmn_format;
    kal_uint8 cmec_keyp; 
    kal_uint8 cmec_disp;
    kal_uint8 cmec_ind;
    kal_bool clae_mode; // we save clae mode in rmmi context
    kal_bool csdh_show; //mtk00714: for +CSDH , hide/show detail Text mode parameters.
    kal_uint8 cvhu_mode; //MAUI_02862643, mtk02285, support CVHU=1 to ignore ATH
    rmmi_report_mode_struct report_mode;
#ifdef __OP01__
    rmmi_op01_report_mode_struct op01_report_mode;
#endif
#ifdef __PLMN_LIST_WITH_LAC__
    kal_bool list_plmn_with_lac; //print LAC for +COPS=? response
#endif
} rmmi_custom_context_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool lock; //KAL_TRUE: lock, KAL_FALSE: unlock
} rmmi_lock_at_cmd_req_struct;

 typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result; //KAL_TRUE: success, KAL_FALSE: fail
} rmmi_lock_at_cmd_cnf_struct;

#ifdef __GAS_SUPPORT__
 /* Message Structure */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 data[1500];  /* data  */
    kal_uint16 size;                                        /* size of the input data */
    kal_uint16 buf_size;                                  /* avariable size of the output buffer */
} gas_data_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 data[1500];  /* data  */
    kal_uint16 size;                                        /* size of the input data */
    kal_uint8 data_type;                                /* gati_output_data_type_enum */
} gas_data_req_struct;

typedef enum
{
    GAS_OUTPUT_NORMAL,     /* The type of output data is normal type which might be partially put to the output buffer of the ATCI */
    GAS_OUTPUT_URC,            /* The type of output data is a URC. Note that this type of data is an integrity type implicitly. */
} gas_output_data_type_enum;
#endif /*__GAS_SUPPORT__*/

/* for thermal_protection */
typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 value;
    kal_uint8 type;
} atci_thermal_event_report_ind_struct;

#ifndef __MTK_TARGET__
#define MAX_UT_UART_LENGTH 2048

typedef enum
{
    ATCI_UT_UART_PORT1 = uart_port1,
    ATCI_UT_UART_PORT2 = uart_port2,
    ATCI_UT_UART_PORT_USB = uart_port_usb,
    ATCI_UT_UART_PORT_USB2 = uart_port_usb2,
    ATCI_UT_UART_PORT_CCCI = uart_port_at_ccci,
    ATCI_UT_UART_PORT_GPS = uart_port_gps_ccci,
    
    /* CMUX virtual port for SIM1 */
    ATCI_UT_UART_VIRTUAL_PORT_START = start_of_virtual_port,
    ATCI_UT_UART_VIRTUAL_PORT2,
    ATCI_UT_UART_VIRTUAL_PORT3,
    ATCI_UT_UART_VIRTUAL_PORT4,
    ATCI_UT_UART_VIRTUAL_PORT5,
    ATCI_UT_UART_VIRTUAL_PORT6, //CMUX extention port for TTL

    /* CMUX virtual port for SIM2 */
    ATCI_UT_UART_VIRTUAL_PORT7,
    ATCI_UT_UART_VIRTUAL_PORT8,
    ATCI_UT_UART_VIRTUAL_PORT9,
    ATCI_UT_UART_VIRTUAL_PORT10,
    ATCI_UT_UART_VIRTUAL_PORT11,
    ATCI_UT_UART_VIRTUAL_PORT12,

    /* no list all of CMUX_VP_NUM virtual ports */
    
    ATCI_UT_UART_VIRTUAL_PORT_END = end_of_virtual_port,
} atci_ut_uart_port_enum;

typedef struct
{
    LOCAL_PARA_HDR
    atci_ut_uart_port_enum port;
    kal_uint8 string[MAX_UT_UART_LENGTH];
    kal_uint16 str_len;
} atci_ut_uart_input_ind_struct; // MSG_ID_ATCI_UT_UART_INPUT_IND
#endif
#endif
