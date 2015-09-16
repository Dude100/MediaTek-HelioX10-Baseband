/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  l1edps_common_parameters.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *  Total parameters define message id between SS and UE
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * Update L1S from DEV branch.
 *
 * removed!
 * removed!
 * . update L1S header files.
 *
 * removed!
 * removed!
 * add trx report msg.
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * add LTE l1edps common header files
 ****************************************************************************/

#ifndef _L1EDPS_MSG_ID_DEF_H
#define _L1EDPS_MSG_ID_DEF_H

#define MESSAGE_SIZE 13

/*********************** Message ID definition *****************/
/* Message via BCCH */
#define MIB_MSG 0x00
#define SIB1_MSG 0x01
#define SI1_MSG 0x02 // SIB2
#define SI2_MSG 0x03 // SIB10 + SIB11 + SIB12
#define SI3_MSG 0x11 // TBD...
#define SI4_MSG 0x12 // TBD...
#define SI5_MSG 0x13 // TBD...

/* Message via PCCH */
#define PAGING_MSG 0x04

/* Message via RAR */
#define RAR_MSG 0x7F

/* Message via CCCH */
#define CONNECT_REQ_MSG 0x05
#define CONNECT_SETUP_MSG 0x06
#define CONNECT_REESTABLISH_MSG 0x07
#define CONTENTION_RESOLUTION_SUCCESS_MSG 0x08
#define CONTENTION_RESOLUTION_FAILED_MSG 0x09

/* Message via DCCH */
#define CONNECT_SETUP_COMPLETE_MSG 0x0A 
#define CONNECT_REESTABLISH_COMPLETE_MSG 0x0B
#define CONNECT_RELEASE_MSG 0x0C	
#define CONNECT_RECONFIG_MSG 0x0D 
#define MEASUREMENT_RPT_MSG 0x0E
#define TRIGGER_SS_MSG 0x0F
#define TRX_REPORT_MSG 0x10

/***************** Message content definition  ****************** */
/* Byte 0 denotes message ID for all messages */
#define BYTE_IDX_FOR_MSG_ID 0
/* 
[SIB1]
Byte 1: system info value tag
Byte 2: scheduling info list (0: SIB10 & SIB11 are scheduled, 1: SIB12 is scheduled) 
*/
#define BYTE_IDX_FOR_SIB1_SI_VALUE_TAG 1
#define BYTE_IDX_FOR_SCHDL_LIST 2
#define SCHDL_LIST_FOR_SIB10_SIB11 0x00
#define SCHDL_LIST_FOR_SIB12 0x01
/* 
[SIB2 in SI1]
Byte 1: default paging cycle
Byte 2: nB
*/
#define BYTE_IDX_FOR_SIB2_DEFAULT_PAGING_CYCLE 1
#define BYTE_IDX_FOR_SIB2_nB 2
/* 
[Paging]
Byte 1: system info modification indication 
Byte 2: ETWS indication
Byte 3: CMAS indication
Byte 4: RSRP change
Byte 5: MT call
*/
#define BYTE_IDX_FOR_PAGING_TM_MODE 1   // Single or Periodic
#define BYTE_IDX_FOR_PAGING_SI_MOD_IND 2
#define BYTE_IDX_FOR_PAGING_ETWS_IND 3
#define BYTE_IDX_FOR_PAGING_CMAS_IND 4
#define BYTE_IDX_FOR_PAGING_RSRP_CHANGE_IND 5
#define BYTE_IDX_FOR_PAGING_MT_CALL 6
/* 
[Connection Reconfiguration]
Byte 1: DRX setup 
Byte 2: DRX cycle
Byte 3: measurement gap setup
Byte 4: measurement gap pattern
Byte 5: intra frequency measurement request 
*/
#define BYTE_IDX_FOR_CONNECT_RECONFIG_DRX_SETUP 1
#define BYTE_IDX_FOR_CONNECT_RECONFIG_DRX_CYCLE 2
#define BYTE_IDX_FOR_CONNECT_RECONFIG_MEAS_GAP_SETUP 3
#define BYTE_IDX_FOR_CONNECT_RECONFIG_MEAS_GAP_PATTERN 4
#define BYTE_IDX_FOR_CONNECT_RECONFIG_MEAS_GAP_OFFSET 5
#define BYTE_IDX_FOR_CONNECT_RECONFIG_PRACH_CONFIG_INDEX 6
#define BYTE_IDX_FOR_CONNECT_RECONFIG_TRANSMISSION_MODE 7

/* 
[Measurement Report]
Byte 1: intra frequency measurement report 
Byte 2: inter frequency measurement report 
*/
#define BYTE_IDX_FOR_MEAS_INTRA_RPT 1
#define BYTE_IDX_FOR_MEAS_INTER_RPT 2


/* 
[TRX  Report]
Byte 1: Pass =1(BLER =0%), Failed =0 (BLER!=0%)
*/
#define BYTE_IDX_FOR_TRX_RPT 1



#endif
