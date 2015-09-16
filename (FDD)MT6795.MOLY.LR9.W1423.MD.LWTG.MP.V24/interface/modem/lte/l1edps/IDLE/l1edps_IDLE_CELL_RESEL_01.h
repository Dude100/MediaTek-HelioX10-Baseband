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
 *  l1edps_IDLE_CELL_RESEL_01.h
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
 * . modify cell resel header file.
 *
 * removed!
 * removed!
 * . modify cell_resel and sch_rlm header files.
 *
 * removed!
 * removed!
 * add LTE l1edps common header files
 ****************************************************************************/



#ifndef _L1SS_IDLE_CELL_RESEL_01_H
#define _L1SS_IDLE_CELL_RESEL_01_H

#include "l1edps_common_parameters.h"

//#undef PHYS_CELL_ID_BTS1
#undef MIB_DL_BANDWIDTH_BTS1
#undef CELL_OFFSET_BTS1 	
#undef DL_EARFCN_BTS1
#undef SIB1_SERVING_Q_RXLEV_MIN_BTS1			
#undef SIB1_SERVING_Q_QUAL_MIN_BTS1		
#undef SIB1_SERVING_P_MAX_BTS1 
#undef SIB2_PRACH_CONFIG_INDEX_BTS1
#undef SIB2_DEFAULT_PAGING_CYCLE_BTS1
#undef SIB3_Q_HYST_BTS1 
#undef SIB3_INTRA_Q_RXLEV_MIN_BTS1                      
#undef SIB3_INTRA_Q_QUAL_MIN_BTS1                        
#undef SIB3_INTRA_P_MAX_BTS1                          
#undef SIB4_INTRA_NEIGHBOR_Q_OFFSET_CELL_BTS1 

//#undef PHYS_CELL_ID_BTS2
#undef MIB_DL_BANDWIDTH_BTS2
#undef CELL_OFFSET_BTS2 	
#undef DL_EARFCN_BTS2
#undef SIB1_SERVING_Q_RXLEV_MIN_BTS2			
#undef SIB1_SERVING_Q_QUAL_MIN_BTS2		
#undef SIB1_SERVING_P_MAX_BTS2 				
#undef SIB2_PRACH_CONFIG_INDEX_BTS2
#undef SIB2_DEFAULT_PAGING_CYCLE_BTS2
#undef SIB3_Q_HYST_BTS2
#undef SIB3_INTRA_Q_RXLEV_MIN_BTS2                       
#undef SIB3_INTRA_Q_QUAL_MIN_BTS2                        
#undef SIB3_INTRA_P_MAX_BTS2                           
#undef SIB4_INTRA_NEIGHBOR_Q_OFFSET_CELL_BTS2

//#define PHYS_CELL_ID_BTS1 0
#define MIB_DL_BANDWIDTH_BTS1 BW_100_RB
#define CELL_OFFSET_BTS1 0	
#define DL_EARFCN_BTS1 900
#define SIB1_SERVING_Q_RXLEV_MIN_BTS1 -70			
#define SIB1_SERVING_Q_QUAL_MIN_BTS1 -34			
#define SIB1_SERVING_P_MAX_BTS1 23 
#define SIB2_PRACH_CONFIG_INDEX_BTS1 4
#define SIB2_DEFAULT_PAGING_CYCLE_BTS1 DEFAULT_PAGING_CYCLE_RF128
#define SIB3_Q_HYST_BTS1 0
#define SIB3_INTRA_Q_RXLEV_MIN_BTS1 -70                      
#define SIB3_INTRA_Q_QUAL_MIN_BTS1 -34                        
#define SIB3_INTRA_P_MAX_BTS1 23                           
#define SIB4_INTRA_NEIGHBOR_Q_OFFSET_CELL_BTS1 0

//#define PHYS_CELL_ID_BTS2 1
#define MIB_DL_BANDWIDTH_BTS2 BW_100_RB
#define CELL_OFFSET_BTS2 0	
#define DL_EARFCN_BTS2 900
#define SIB1_SERVING_Q_RXLEV_MIN_BTS2 -70			
#define SIB1_SERVING_Q_QUAL_MIN_BTS2 -34			
#define SIB1_SERVING_P_MAX_BTS2 -30 
#define SIB2_PRACH_CONFIG_INDEX_BTS2 4
#define SIB2_DEFAULT_PAGING_CYCLE_BTS2 DEFAULT_PAGING_CYCLE_RF128
#define SIB3_Q_HYST_BTS2 0
#define SIB3_INTRA_Q_RXLEV_MIN_BTS2 -70                      
#define SIB3_INTRA_Q_QUAL_MIN_BTS2 -34                        
#define SIB3_INTRA_P_MAX_BTS2 23                           
#define SIB4_INTRA_NEIGHBOR_Q_OFFSET_CELL_BTS2 0

#endif




