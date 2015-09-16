#ifndef __HIF_SDIOQ_OP_H__
#define __HIF_SDIOQ_OP_H__

#include "brom_sdio_reg.h"

/**
 *  @brief  Setting start address in QMU
 *	@param	_qid : the queue type you want to set the start address
 *	@param	_addr : the address setting to start address
 */ 
#define SDIO_QMU_SET_START_ADDR(_tx,_qid, _addr)   do {      \
	if (_tx) {								\
		*SDIO_QMU_DLQ_SAR_n(_qid) = (kal_uint32)_addr;	\
	} else {								\
		*SDIO_QMU_ULQ_SAR_n(_qid) = (kal_uint32)_addr;	\
	}										\
}while(0)									\


/**
 *  @brief  Read Current Pointer 
 *	@param	_qid : the queue type you want to set the start address
 *	@param	_addr : the address setting to start address
 */ 

/* mtk03694 : Mark this function because SDIO has no register to read current pointer directly NOW */
/*
#define SDIO_QMU_GET_CURRENT_ADDR(_tx,_qid, _addr)	do {	\
	if (_tx) {							\
	} else {							\
	}								\
}while(0)								\
*/


/**
 *  @brief  start the queue defined in _qid immediately
 *	@param	_qid : the queue type you want to start
 */ 
#define SDIO_QMU_START(_tx, _qid)	do {					\
	if (_tx) {												\
		*SDIO_QMU_DLQ_CR_n(_qid) = SDIO_QMU_DLQ_START;	\
	} else {												\
		*SDIO_QMU_UL_DCR |= SDIO_QMU_ULQ_START(_qid);	\
	}														\
}while(0)													\


/**
 *  @brief  Resume the queue defined in _qid immediately
 *	@param	_qid : the queue type you want to resume
 *   NOTICE : Because the SDIO DL queue resume need to write the packet length 
 *                 simutanously, so we do nothing with simple resume function.
 */ 
#define SDIO_QMU_RESUME(_tx,_qid)	do {						\
/*	if (_tx) {													\
		*SDIO_QMU_DLQ_CR_n(_qid) = SDIO_QMU_DLQ_RESUME;	\
	} else {													\
		*SDIO_QMU_UL_DCR |= SDIO_QMU_ULQ_RESUME(_qid);		\
	}	*/														\
}while(0)										


/**
 *  @brief  Stop the queue defined in _qid immediately
 *	@param	_qid : the queue type you want to stop
 */ 
#define SDIO_QMU_STOP(_tx,_qid)	do {						\
	if (_tx) {												\
		*SDIO_QMU_DLQ_CR_n(_qid) = SDIO_QMU_DLQ_STOP;	\
	} else {												\
		*SDIO_QMU_UL_DCR |= SDIO_QMU_ULQ_STOP(_qid);	\
	}														\
}while(0)													\


/**
 *	@brief	Check and wait the queue stop operation is completed 
 *	@param	_qid : the queue type you want to stop
 */ 
#define SDIO_QMU_CHK_STOP_COMPLETE(_tx,_qid)	do {													\
		if (_tx) {																					\
			while(*SDIO_QMU_DLQ_CR_n(_qid) & (SDIO_QMU_DLQ_STOP | SDIO_QMU_DLQ_STATUS));		\
		} else {																					\
			while(*SDIO_QMU_UL_DCR & (SDIO_QMU_ULQ_STOP(_qid) | SDIO_QMU_ULQ_STATUS(_qid)));	\
		}																							\
	}while(0)																						\
	
/**
 *	@brief	get the active status of a queue
 *	@param	_qid : the queue 
 */ 
#define SDIO_QMU_GET_ACTIVE(_tx,_qid,_st)	do {									\
		if (_tx) {																	\
			_st = (*SDIO_QMU_DLQ_CR_n(_qid) & (SDIO_QMU_DLQ_STATUS)) ? 1 : 0; 	\
		} else {																	\
			_st = (*SDIO_QMU_UL_DCR & (SDIO_QMU_ULQ_STATUS(_qid))) ? 1 : 0; 	\
		}																			\
	}while(0)																		\


#endif
