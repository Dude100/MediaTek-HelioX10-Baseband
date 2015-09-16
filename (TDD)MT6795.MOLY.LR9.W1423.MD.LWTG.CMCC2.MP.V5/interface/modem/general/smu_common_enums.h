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
 * Filename:
 * ---------
 *	sim_trc.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is trace map definition.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

/*Kinki*/
#ifndef _SIM_COMMON_ENUMS_H

#define _SIM_COMMON_ENUMS_H
#include "sim_common_enums.h"
//#include "custom_mmi_default_value.h"
//#include "common_nvram_editor_data_item.h"
#include "nvram_editor_data_item.h"
//#include "kal_non_specific_general_types.h"
//#include "ps2sim_struct.h"
#include "kal_general_types.h"
#include "ps_public_struct.h" 
#include "ps_public_enum.h"
#endif

#ifndef _SMU_COMMON_ENUMS_H
#define _SMU_COMMON_ENUMS_H

#define NUM_OF_BYTE_LP     2
#define MAX_LP_NUM         5 
#define NUM_OF_BYTE_ECC    3
#define MAX_ECC_NUM        5
#define NUM_OF_BYTE_NP     NVRAM_EDITOR_NUM_OF_BYTE_NP
#define NUM_NP             NVRAM_EDITOR_NUM_NP
#define NUM_OF_BYTE_NSP    NVRAM_EDITOR_NUM_OF_BYTE_NSP
#define NUM_NSP            NVRAM_EDITOR_NUM_NSP
#define NUM_OF_BYTE_KEY    NVRAM_EDITOR_NUM_OF_BYTE_KEY
//#define NUM_GID            NVRAM_EDITOR_NUM_GID
#define NUM_OF_BYTE_IMSI   NVRAM_EDITOR_NUM_OF_BYTE_IMSI
#define NUM_OF_BYTE_PLMN   3
#define NUM_OF_PUCT_DIGIT 18
#define NUM_OF_BYTE_ICCID	NVRAM_EDITOR_NUM_OF_BYTE_ICCID

#ifdef __SMS_DEPERSONALIZATION__
#define LEN_OF_BYTE_SMS_DEPER 88 //Kinki: [MAUI_01255000]
#endif

/* msg ID */

typedef enum
{
   SMU_PHONELOCK_REQUIRED,
   SMU_CHV1_NOT_REQUIRED,
   SMU_CHV1_REQUIRED,
   SMU_UBCHV1_REQUIRED,
   SMU_SIM_BLOCKED
}smu_chv1_phonelock_status_enum;

typedef enum
{
   SMU_CHV1,
   SMU_CHV2
}smu_chv_type_enum;

typedef enum
{
   CHV_RETRY_ALLOW,
   CHV_VERIFIED,
   CHV_DISABLED,
   CHV_BLOCKED,
   CHV_DEAD,
   CHV_INVALID_TYPE,
   CHV_NOTINITED
}smu_chv_status_enum;


typedef enum
{
   READ_BINARY=176,
   READ_RECORD=178,
   GET_RESPONSE=192,
   UPDATE_BINARY=214,
   UPDATE_RECORD=220,
   STATUS_CMD=242
}smu_sim_access_cmd_enum;


typedef enum
{
   SMU_UPDATE_ACMMAX,
   SMU_UPDATE_ACM,
   SMU_UPDATE_PUCT,
   SMU_SWITCH_BDN
}smu_access_item_enum;

typedef enum
{
   SMU_ACCESS_NOT_ALLOW,
   SMU_VERIFY_CHV1,
   SMU_VERIFY_CHV2
}smu_access_condition_enum;

typedef enum
{
   ID_READY,
   ID_SIM_PIN1,
   ID_SIM_PUK1,
   ID_PH_SIM_PIN,
   ID_PH_FSIM_PIN,
   ID_PH_FSIM_PUK,
   ID_SIM_PIN2,
   ID_SIM_PUK2,
   ID_PH_NET_PIN,
   ID_PH_NET_PUK,
   ID_PH_NETSUB_PIN,
   ID_PH_NETSUB_PUK,
   ID_PH_SP_PIN,
   ID_PH_SP_PUK,
   ID_PH_CORP_PIN,
   ID_PH_CORP_PUK,
   ID_PH_LINK_NS_SP_PIN,
   ID_PH_LINK_NS_SP_PUK,
   ID_PH_LINK_SIM_C_PIN,
   ID_PH_LINK_SIM_C_PUK,
   ID_PHONELOCK,
   ID_SIM_BLOCKED,
   ID_SIM_BUSY,   /* This add for WM CPIN? with SML check */
   ID_UNKNOWN //link_SML
}smu_pending_password_id_enum;

typedef enum
{
   SMU_WRITE_PUCT_RMI,
   SMU_WRITE_PUCT_LMI,   
   SMU_SIM_ACCESS_CMD,
   SMU_WRITE_PLMN_SEL_ADD_RMI,
   SMU_WRITE_PLMN_SEL_REMOVE_RMI,
   SMU_WRITE_PLMN_SEL_REPLACE_RMI,
   SMU_WRITE_PLMN_SEL_ADD_LMI,
   SMU_WRITE_PLMN_SEL_REMOVE_LMI,
   SMU_WRITE_PLMN_SEL_REPLACE_LMI,         
   SMU_READ_PUCT_RMI,
   SMU_READ_PLMN_SEL_RMI,
   SMU_READ_PUCT_LMI,
   SMU_READ_PLMN_SEL_LMI,
   SMU_READ_CSP_RMI,
   SMU_READ_CSP_LMI,
   SMU_READ_CHANGED_PLMNSEL,
   SMU_READ_CHANGED_PUCT,
   SMU_WRITE_DCK
}smu_write_access_id_enum;

typedef enum {
    SMU_CI_DISABLE,
    SMU_CI_ENABLE,
    SMU_CI_NONE
} smu_cipher_ind_enum;

/*Kinki : revised ECC*/
typedef enum
{
   SMU_SIM_UNKNOWN,    //default value
   SMU_SIM_NOT_INSERTED,         
   SMU_SIM_INSERTED
}smu_sim_inserted_enum;

#ifdef __SMS_DEPERSONALIZATION__ //Kinki: [MAUI_01255000]

typedef enum
{
   SMU_SML_LENGTH_TOO_SHORT,
   RFU
}smu_sms_depersonalization_enum;

#endif

typedef struct {
    kal_uint8 mcc2;
    kal_uint8 mcc1;
    kal_uint8 mnc3;
    kal_uint8 mcc3;
    kal_uint8 mnc2;
    kal_uint8 mnc1;
    kal_uint8 access_tech[2];
} smu_plmn_id_struct;

extern kal_bool l4csmu_read_plmn_sel(sim_file_index_enum file_idx, kal_uint8 start_index, kal_uint16 * num, smu_plmn_id_struct * plmn_ptr);
//extern smu_chv_status_enum l4csmu_get_chv_status(smu_chv_type_enum type);
extern kal_bool l4csmu_get_puct_value(kal_uint8 *currency,kal_uint8 *ppu);

//SMU only
/*Kinki remove(useless function)*/
//extern void l4csmu_get_preferred_language(kal_uint8 *num,sim_lp_file_type_enum *file_type, kal_uint8 *lp_data);
//extern void l4csmu_get_ecc(kal_uint8 *num_ecc, sim_ecc_entry_struct *ecc_entry);
//extern void l4csmu_get_ecc(kal_uint8 *num, kal_uint8 *ecc_data);
extern void l4csmu_get_imsi(kal_uint8 *imsi_data);

//SMU only
/*Kinki remove(useless function)*/
//extern smu_access_condition_enum l4csmu_get_sim_access_info(smu_access_item_enum access_item);
extern smu_pending_password_id_enum l4csmu_get_pending_password_id(void);
//link_SML
extern smu_pending_password_id_enum l4csmu_get_pending_password_id_ext(sim_interface_enum sim_id);
extern smu_pending_password_id_enum l4csmu_app_get_pending_password_id(kal_uint8);
extern kal_bool l4csmu_get_pending_lock(smu_pending_password_id_enum password, smu_security_type_enum *type);

/*Kinki remove(useless function)*/	
//extern kal_uint16 l4csmu_test_preferred_plmn (void); //Benson 20040407 modified for mtk00714's request 
extern sim_dn_enum l4csmu_get_dial_mode(void);
//Kinki remove for MAUI_00632199
#if 0
#ifdef __GEMINI__
/* under construction !*/
#else
/* under construction !*/
#endif
#endif

extern kal_bool check_is_usim(void);

#if defined(__GEMINI__) || defined(__SGLTE__)
extern smu_sim_inserted_enum is_sim_inserted(kal_uint8 simInterface);
#else
extern smu_sim_inserted_enum is_sim_inserted(void);
#endif

extern kal_bool smu_update_is_simcard_replaced(kal_uint8 *iccid, kal_uint8 simInterface);

#ifdef __cplusplus
extern "C" {
#endif
extern smu_sim_status_enum smu_update_is_sim_replaced(kal_uint8 *imsi, kal_uint8 simInterface);
#ifdef __cplusplus
}
#endif

extern smu_cipher_ind_enum l4csmu_get_cipher_ind_status(void);

extern kal_bool l4csmu_sat_ready_req(kal_bool trigger_by_user);

#endif  

