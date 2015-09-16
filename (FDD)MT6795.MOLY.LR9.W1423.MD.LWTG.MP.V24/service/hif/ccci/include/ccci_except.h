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
 *   ccci_except.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI exception mode header
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
 * [CCCI] For SS debug info
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * [CCCI] Fix CCCI direct SM size
 *
 * removed!
 * removed!
 * [CCCI] Provide CCCI direct write SM API
 *
 * removed!
 * removed!
 * 	Add Step info in exception mode
 *
 * removed!
 * removed!
 * [CCCI] Add exception debug info & boot trace.
 *
 * removed!
 * removed!
 * 	.
 *
 * 07 12 2013 ap.wang
 * removed!
 * [CCCI EXCEPTION] exception integration
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCCI_EXCEPT_H
#define _CCCI_EXCEPT_H
#include "ccci_common.h"
#include "ccci_if.h"

#define MD_EX_MAGIC  0x5745444D  //"MDEX"

/*******************************************************************************
 * define global variable
 *******************************************************************************/
#define BOOT_CHECK_ID       0x5555FFFF /* magic id : Placed on reserved field */
#define EXCEPTION_CHECK_ID  0x45584350 /* EXCP     : Placed on reserved field */
#define EXCEPTION_REC_READY 0x45524543 /* EREC     : Placed on reserved field */
#define CCCI_WAIT_MAX_TIME  4615

/* CCCI EXCEP DBG Log magic number */
#define CCCI_EXCEP_DBG_INDICATOR_L 0x49434343    /* "CCCI" */
#define CCCI_EXCEP_DBG_INDICATOR_H 0x47424445    /* "EDBG" */

/* Exception DBG Info*/
#define EX_STEP_CCCI_HEAD 0xCC0000CC
enum{
    CCCI_DBG_EXPT_INIT     = 0xCC0000CC,
    CCCI_DBG_EXPT_CLR_CH   = 0xCC0100CC,
    CCCI_DBG_EXPT_SET_GPD  = 0xCC0200CC,
    CCCI_DBG_EXPT_POLL_GPD = 0xCC0300CC,
    CCCI_DBG_EXPT_HIF_ST   = 0xCC0400CC,
    CCCI_DBG_EXPT_HIF_ISR  = 0xCC0500CC,
};


enum { 
	MD_INIT_START_BOOT = 0x00000000, 
	MD_INIT_CHK_ID = 0x5555FFFF,
	MD_EX = 0x00000004, 
	MD_EX_CHK_ID = 0x45584350,
	MD_EX_REC_OK = 0x00000006, 
	MD_EX_REC_OK_CHK_ID = 0x45524543, 
	MD_EX_RESUME_CHK_ID = 0x7,
	CCCI_DRV_VER_ERROR = 0x5,
	// System channel, MD --> AP message start from 0x1000
	MD_WDT_MONITOR = 0x1000,
	MD_WAKEN_UP = 0x10000,
};

/*!
 *  @brief _ccci_expt_usr defines the ccci exception mode user
 */
typedef enum _CCCI_EXPT_USR
{
    CCCI_EXPT_DHL_UL,       /* for DHL */
    CCCI_EXPT_DHL_DL,       /* for DHL */
    CCCI_EXPT_DHL_CTRL_UL,  /* for DHL */
    CCCI_EXPT_DHL_CTRL_DL,  /* for DHL */    
    CCCI_EXPT_FS_UL,        /* for nvram */
    CCCI_EXPT_FS_DL,        /* for nvram */
    CCCI_EXPT_CTRL_UL,      /* for CCCI_HS */
    CCCI_EXPT_CTRL_DL,      /* for CCCI_HS */
    CCCI_EXPT_USR_MAX
} CCCI_EXPT_USR_E;

/*!
 *  @brief ccci_except_ch_inst
 */
typedef struct _ccci_expt_ch_inst {
    kal_uint32          ccci_ch;
	kal_uint8	        qno;        /*CCCI_EXPT_DHL_TXRX_HIF_QNO, CCCI_EXPT_FS_TXRX_HIF_QNO*/
    kal_uint8           hwq_type;   /*CCCI_TYPE_TX, CCCI_TYPE_RX*/
	CCCI_HIF_HW_TYPE_T  hw_type;
    ccci_hif_expt_apis  *hif_expt_apis;
} ccci_except_ch_inst_t ;

typedef struct _ccci_hif_expt_q_t{
    kal_uint8     hwq_id;
    kal_uint8     hwq_type;
}ccci_hif_expt_q_t;

//- Structure for Excep DBG Logging
typedef struct {
    kal_uint32 magic_number_l;
    kal_uint32 magic_number_h;
    kal_uint32 last_write_index;
    kal_uint32 reserved;
} ccci_excep_dbg_hdr_t;

#define CCCI_EXPT_DHL_CTRL_TXRX_HIF_QNO  3
#define CCCI_EXPT_DHL_TXRX_HIF_QNO       2
#define CCCI_EXPT_FS_TXRX_HIF_QNO        1
#define CCCI_EXPT_CTRL_TXRX_HIF_QNO      0

#endif // _CCCI_EXCEPT_H
