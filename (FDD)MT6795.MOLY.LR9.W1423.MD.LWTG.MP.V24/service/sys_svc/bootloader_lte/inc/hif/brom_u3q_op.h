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
 *   brom_u3q_op.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *	This is the USB3.0 QMU operation API head file.
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 ****************************************************************************/
#ifndef __BROM_U3Q_OP_H__
#define __BROM_U3Q_OP_H__

#include "brom_u3q_reg.h"

/**
 *  @brief  Setting start address in QMU
 *	@param	_qid : the queue type you want to set the start address
 *	@param	_addr : the address setting to start address
 */ 
#define HIF_QMU_SET_START_ADDR(_tx,_qid, _addr)   do {      \
	if (_tx) {							\
		*USB3_QMU_TQSAR_n(_qid) = (kal_uint32)_addr;	\
	} else {							\
		*USB3_QMU_RQSAR_n(_qid) = (kal_uint32)_addr;	\
	}									\
}while(0)								\


/**
 *  @brief  Read Current Pointer 
 *	@param	_qid : the queue type you want to set the start address
 *	@param	_addr : the address setting to start address
 */ 
#define HIF_QMU_GET_CURRENT_ADDR(_tx,_qid, _addr)	do {	\
	if (_tx) {							\
		_addr = (void *)*USB3_QMU_TQCPR_n(_qid);	\
	} else {							\
		_addr = (void *)*USB3_QMU_RQCPR_n(_qid);	\
	}									\
}while(0)								\


/**
 *  @brief  start the queue defined in _qid immediately
 *	@param	_qid : the queue type you want to start
 */ 
#define HIF_QMU_START(_tx, _qid)	do {	\
	if (_tx) {										\
		*USB3_QMU_TQCSR_n(_qid) |= U3_DQMU_QUE_START;	\
	} else {										\
		*USB3_QMU_RQCSR_n(_qid) |= U3_DQMU_QUE_START;	\
	}												\
}while(0)											\


/**
 *  @brief  Resume the queue defined in _qid immediately
 *	@param	_qid : the queue type you want to resume
 */ 
#define HIF_QMU_RESUME(_tx,_qid)	do {				\
	if (_tx) {										\
		*USB3_QMU_TQCSR_n(_qid) |= U3_DQMU_QUE_RESUME;	\
	} else {										\
		*USB3_QMU_RQCSR_n(_qid) |= U3_DQMU_QUE_RESUME;	\
	}												\
}while(0)											\

/**
 *  @brief  Stop the queue defined in _qid immediately
 *	@param	_qid : the queue type you want to stop
 */ 
#define HIF_QMU_STOP(_tx,_qid)	do {					\
	if (_tx) {										\
		*USB3_QMU_TQCSR_n(_qid) |= U3_DQMU_QUE_STOP;	\
	} else {										\
		*USB3_QMU_RQCSR_n(_qid) |= U3_DQMU_QUE_STOP;	\
	}												\
}while(0)											\

/**
 *  @brief  Stop the queue defined in _qid immediately
 *	@param	_qid : the queue type you want to stop
 */ 
#define HIF_QMU_CHK_STOP_COMPLETE(_tx,_qid)	do {								\
	if (_tx) {																	\
		while(*USB3_QMU_TQCSR_n(_qid) & (U3_DQMU_QUE_STOP | U3_DQMU_QUE_ACTIVE));		\
	} else {																	\
		while(*USB3_QMU_RQCSR_n(_qid) & (U3_DQMU_QUE_STOP | U3_DQMU_QUE_ACTIVE));		\
	}																			\
}while(0)																		\

/**
 *  @brief  get the active status of a queue
 *	@param	_qid : the queue 
 */ 
#define HIF_QMU_GET_ACTIVE(_tx,_qid,_st)	do {								\
	if (_tx) {																	\
		_st = (*USB3_QMU_TQCSR_n(_qid) & (U3_DQMU_QUE_ACTIVE)) ? 1 : 0;				\
	} else {																	\
		_st = (*USB3_QMU_RQCSR_n(_qid) & (U3_DQMU_QUE_ACTIVE)) ? 1 : 0;				\
	}																			\
}while(0)																		\


#endif
