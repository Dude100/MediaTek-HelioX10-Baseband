/*****************************************************************************
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
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   uas_gas_enums.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 * ----------------------------------------------------------------------------
 * $Log:$
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
 * 09 09 2012 yong.su
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
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Check in TK6280_DVT_DEV to MT6280_DVT_DEV
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
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Supported 3rd criteria for InterRAT cell reselection to UTRAN.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add copyright header.
 ******************************************************************************/

#ifndef _UAS_GAS_ENUMS_H
#define _UAS_GAS_ENUMS_H

#include "irat_common_enums.h"

/* MACROS ******************************************************************/
/* MAX Values */
#define MAX_LEN_HO_TO_GSM_MSG (251)  /* Octets */
#define MAX_LEN_TLV_CLASSMARK_2 (5)  /* Octets */
#define MAX_LEN_V_CLASSMARK_3  (32)     /* Octets */
#define MAX_LEN_HO_TO_UTRAN_MSG  (251) /* Octets */
#define MAX_LEN_UTRAN_HANDOVER_INFO_MSG (251) /* Octets*/
#define MAX_NUM_MEASURED_UMTS_FDD_CELL 64


#define MAX_NUM_MEASURED_GSM_CELLS 32

#define UAS_GAS_INVALID_UARFCN (0xffff)

#if defined(__UMTS_TDD128_MODE__)
#define MAX_NUM_MEASURED_UMTS_TDD_CELL (64)
#endif //defined(__UMTS_TDD128_MODE__)

/*Other constants*/
#define INTER_RRC_GSM_CIPHERING_KEY_LENGTH   8  
#define INTER_RRC_UMTS_CIPHERING_KEY_LENGTH 16
#define INTER_RRC_UMTS_INTEGRITY_KEY_LENGTH 16
#define TEMP_FAILURE_PENALTY_TIME 30 /*Haizhou 20100819 Time penalty for convert temp failure to initial_value after resel to ucell fai*/

#define INTER_RRC_LEN_PLMN_IDENTITY 3

/* MAX/MIN values */
#define MAX_UARFCN_RSSI_VAL (-100)
#define MIN_UARFCN_RSSI_VAL (-480)
#define MAX_UCELL_RSCP_VAL (-100)
#define MIN_UCELL_RSCP_VAL (-480)
#define MAX_UCELL_EC_NO_VAL 0
#define MIN_UCELL_EC_NO_VAL (-100)

#define MAX_UMTS_UARFCN 16383
#define MIN_UMTS_UARFCN 0
#if 0
/* under construction !*/
/* under construction !*/
#endif
#define INVALID_NC_MODE (0xFF)

#if defined(__PS_HO__) && defined(__UMTS_R6__)
#define MAX_LEN_V_MS_RADIO_ACCESS_CAPABILITY (64)
#endif

#ifdef __WCDMA_PREFERRED__
#define INTER_DEFAULT_RSCP_THRESHOLD (11) /* -105 dBm */
#define INTER_DEFAULT_EC_N0_THRESHOLD (19) /* -15 dB */
#endif /* __WCDMA_PREFERRED__ */

/* TYPES DEFINITIONS ********************************************************/

typedef enum 
{
   UMTS_SIGNALLING_KEYS_FOR_CS_DOMAIN,
   UMTS_SIGNALLING_KEYS_FOR_PS_DOMAIN
}te_umts_signalling_connection_keys;

typedef enum {
    L1_AVAILIBILITY_STATUS_VACANT, /* During Cell selection*/
    L1_AVAILIBILITY_STATUS_SHARED, /* IDLE camped,URA_PCH,CELL_PCH */
    L1_AVAILIBILITY_STATUS_OCCUPIED /* PTM,DEDICATED,CELL_FACH,CELL_DCH*/
}te_l1_availibility_status;    

typedef enum {
  IR_CELL_CHANGE_COMPLETE_SUCCESS,
  IR_CELL_CHANGE_COMPLETE_FAIL,
  IR_CELL_CHANGE_COMPLETE_FAIL_BY_NAS_COMMAND
}te_ir_cell_change_complete_status;

typedef enum {
   IR_CELL_RESELECTION_TYPE_NORMAL,
   IR_CELL_RESELECTION_TYPE_LIMITED_SERVICE
}te_ir_cell_reselection_type;

#if 0 //__UMTS_TDD128_MODE__
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
#endif //__UMTS_TDD128_MODE__

/* not use enum
typedef enum {
   IR_ORIGINATING_RAT_TYPE_UMTS_FDD
}te_ir_originating_rat_type;
*/
/* Enum modification:
 * IR_URRC_STATE_MIN and IR_URRC_STATE_MAX are removed */
typedef enum {
        IR_URRC_INVALID = 0,
        IR_URRC_IDLE            = 1,
	IR_URRC_PCH,
	IR_URRC_FACH,
	IR_URRC_DCH
}te_ir_urrc_state;

#endif /* UAS_GAS_ENUMS_H */
