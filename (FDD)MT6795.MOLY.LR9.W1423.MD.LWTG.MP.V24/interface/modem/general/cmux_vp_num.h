/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   cmux_vp_num.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for CMUX Virtual Port Number Inclusion
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 ******************************************************************************/

#ifndef CMUX_VP_NUM_H
#define CMUX_VP_NUM_H
/******************************************************************************/

#include "global_def.h"

/******************************************************************************/

// CMUX_VP_NUM_FOR_ATCI
#define CMUX_VP_NUM_FOR_ATCI 	    5
#define CMUX_VP_NUM_FOR_ATCI_EX 	1

#if defined(__CSD_NT__) || defined(__CSD_T__) 
#define CMUX_VP_NUM_FOR_ATCI_CSD 	1
#else
#define CMUX_VP_NUM_FOR_ATCI_CSD 	0
#endif

// CMUX_VP_NUM_FOR_VT
#if defined(__VT_TRANSPORT_SUPPORT__)
#define CMUX_VP_NUM_FOR_VT		1
#else
#define CMUX_VP_NUM_FOR_VT		0
#endif

// CMUX_VP_NUM_FOR_CS
#if defined(__DATA_CARD_SPEECH__)
#define CMUX_VP_NUM_FOR_CS		1
#else
#define CMUX_VP_NUM_FOR_CS		0
#endif

/******************************************************************************/

// CMUX_VP_NUM_FOR_SINGLE_SIM is used for users of CMUX
// referenced by ATCI
#ifdef __CMUX_SUPPORT__
	#define CMUX_VP_NUM_FOR_SINGLE_SIM	    (CMUX_VP_NUM_FOR_ATCI)
	#define CMUX_VPEX_NUM_FOR_SINGLE_SIM    (CMUX_VP_NUM_FOR_ATCI_EX)
	#define CMUX_VPEX_TOTAL_NUM				(((CMUX_VP_NUM_FOR_ATCI_EX) \
		* (MAX_SIM_NUM)) + CMUX_VP_NUM_FOR_ATCI_CSD)
#else
	#define CMUX_VP_NUM_FOR_SINGLE_SIM 	    0
	#define CMUX_VPEX_NUM_FOR_SINGLE_SIM    0
	#define CMUX_VPEX_TOTAL_NUM				0
#endif

/******************************************************************************/

// CMUX_DLC_NUM is used by CMUX
// referenced in cmux_def.h
#ifdef __CMUX_SUPPORT__
	#define CMUX_DLC_NUM (((CMUX_VP_NUM_FOR_ATCI + CMUX_VP_NUM_FOR_ATCI_EX) \
        * (MAX_SIM_NUM)) + CMUX_VP_NUM_FOR_ATCI_CSD + CMUX_VP_NUM_FOR_VT \
		+ CMUX_VP_NUM_FOR_CS )
#else
	#define CMUX_DLC_NUM 	0
#endif

/******************************************************************************/

// CMUX_VP_NUM is used for uart provider
// referenced in enum UART_PORT
#ifdef __CMUX_SUPPORT__
    #define CMUX_VP_NUM     (CMUX_DLC_NUM)
#else
	#define CMUX_VP_NUM 	0
#endif

/******************************************************************************/
#endif /* CMUX_VP_NUM_H */

