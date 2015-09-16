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
 *	l4c2t30_enums.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for enum definition between T30 and L4C.
 *
 * Author:
 * -------
 *	
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _L4C2T30_ENUMS_H
#define _L4C2T30_ENUMS_H

typedef enum {
   ACTION_SET,
   ACTION_QUERY,
   ACTION_TEST
} l4c_t30_action_enum;

typedef enum {
	CODE_CONNECT,
	CODE_ERROR,
	CODE_NOCARRIER,
	CODE_OK,
	CODE_FCERROR,
	NO_CODE
}l4c_t30_act_rsp_enum;


typedef enum {
   FIP_INIT_PARA=0x1,     /* initialize all parameters */
   FCC_DCE_CAP=0x2,			/* DCE capability */
   FIS_NEG_CAP=0x4,			/* current session negotiating position*/
   FCS_CURRENT_CAP=0x8,	/* current sessioni parameters(read only) */
   FLP_DOC_AVAIL=0x10,	   /*indicate documet available for polling */
   FSP_POLL_ENABLE=0x20,
   FNR_REPORT_PARAM= 0x40,
   FIE_PI_ENABLE= 0x80,
   FPS_PAGE_STATUS= 0x100,
   FCQ_COPY_QUALITY= 0x200,
   FIT_INACT_TO = 0x400,
   FPP_PKT_PROCO= 0x800,
   FBO_BIT_ORDER = 0x1000,
   FEA_EOL_ALIGN = 0x2000,
   FCR_RECV_CAP = 0x4000,
   FBU_HDLC_REPORT = 0x8000,
   FAP_ADD_POLL_CAP = 0x10000,
   FRQ_RECV_Q_THRESD = 0x20000,
   FCT_PHC_TO = 0x40000,
   FHS_HANG_CODE = 0x80000,
   FMS_MIN_SPEED = 0x100000,
   FCL_CARRIER_LOSS = 0x200000,
   FDD_ESC_REPLACE = 0x400000,
   FFC_FORMAT_CONV = 0x800000,
   FBS_BUFF_SIZE = 0x1000000,
   FRY_CTC_RETRY = 0x2000000,
   FET_POST_CMD = 0x4000000
} rw_param_enum;

typedef enum {
   FLI_LOCAL_ID = 0x1,
   FPI_LOCAL_ID = 0x2,
   FNS_NON_STAND = 0x4,
   FSA_SUB_ADD = 0x8,
   FPW_PWD = 0x10,
   FPA_SEL_ADD = 0x20
} rw_str_param_enum;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

