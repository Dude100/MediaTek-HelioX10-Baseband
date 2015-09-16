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
 *  l1edps_SCH_PCQI_01.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *  Parameters define value between SS and UE
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
 * CQI RI_CONFIG and CQI_RI_CONFIG modify
 *
 * removed!
 * removed!
 * 	modify CQI config for PCQI and ACQI
 *
 * removed!
 * removed!
 * merge back to moly trunck
 *
 * removed!
 * removed!
 * Add messages for new L1S TCs.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 ****************************************************************************/



#ifndef _L1EDPS_SCH_PCQI_01_H
#define _L1EDPS_SCH_PCQI_01_H

#include "l1edps_common_parameters.h"

#undef MIB_DL_BANDWIDTH_BTS1
#undef DL_EARFCN_BTS1
#undef SIB2_UL_BANDWIDTH_BTS1 
#undef RRC_SETUP_CQI_REPORT_PERIODIC_SETUP_BTS1
#undef RRC_SETUP_SIMULTANEOUS_ACK_NACK_AND_CQI_BTS1
#undef RRC_SETUP_CQI_SUBBAND_K_BTS1
#undef RRC_SETUP_RI_CONFIG_INDEX_BTS1
#undef RRC_SETUP_CQI_PMI_CONFIG_INDEX_BTS1

#define DL_EARFCN_BTS1         900
#define MIB_DL_BANDWIDTH_BTS1  BW_100_RB
#define SIB2_UL_BANDWIDTH_BTS1 BW_100_RB

#define RRC_SETUP_SIMULTANEOUS_ACK_NACK_AND_CQI_BTS1  L1S_SETUP
#define RRC_SETUP_CQI_REPORT_PERIODIC_SETUP_BTS1      L1S_SETUP
#define RRC_SETUP_CQI_SUBBAND_K_BTS1                  4         //k=4
#define RRC_SETUP_RI_CONFIG_INDEX_BTS1                2
#define RRC_SETUP_CQI_PMI_CONFIG_INDEX_BTS1           2


#endif

