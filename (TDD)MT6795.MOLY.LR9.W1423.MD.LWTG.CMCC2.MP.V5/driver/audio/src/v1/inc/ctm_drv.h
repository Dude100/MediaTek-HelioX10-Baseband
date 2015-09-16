/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	   l1ctm.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 
// l1ctm.h
#ifndef __L1CTM_H
#define __L1CTM_H
#include "common_def.h"

typedef enum{
   DIRECT_MODE,
   BAUDOT_MODE       
} L1Ctm_Interface; 

typedef enum{
   CTM_MO_SUCCESS,
   CTM_MO_FAIL, 
   CTM_MT_DETECTED, 
   CTM_CHAR_SENT, 
   CTM_CHAR_RECEIVED,
   CTM_TX_BURST_START,
   CTM_TX_BURST_END   
} L1Ctm_Event; 

// Msg_Info Debug Message 
#define OPEN_CTM_REQUEST 1
#define CLOSE_CTM_REQUEST 2
#define UL_READ_PCM_FILE_REQUEST 3
#define DL_READ_PCM_FILE_REQUEST 4
#define DL_READ_BFI_FILE_REQUEST 5   
#define UL_IN_WRITE_FILE_REQUEST 6
#define DL_IN_WRITE_FILE_REQUEST 7
#define UL_OUT_WRITE_FILE_REQUEST 8
#define DL_OUT_WRITE_FILE_REQUEST 9   
#define GENERAL_WRITE_FILE_REQUEST 10
#define PUT_TEXT_TO_UL_CTM_BUF_REQUEST 11
#define UL_CTM_BUF_DUMMY_READ_REQUEST 12

#define DSP_REC_RX_BUF0_REQUEST 13
#define DSP_REC_NB_RESULT0_REQUEST 14
#define DSP_REC_FN_REQUEST 15
#define DSP_REC_EQ_SO0_REQUEST 16

#define START_NEGOTIATION_REQUEST 17

#define DONE_WRITE_FILE_REQUEST 18


// need to define CTM_Param 
typedef struct
{
    kal_int16   cprm_tone_demod_down_samp;                  // 1 (0, 1)   
} CTM_Param;


typedef void (*L1Ctm_Callback)(L1Ctm_Event , void*); 
typedef void (*L1Ctm_DebugCallback)(uint16 pos, uint16 *buffer, uint16 len, bool isDone);

uint32 L1Ctm_GetMemReq(void);
void L1Ctm_Open(L1Ctm_Interface a, L1Ctm_Callback handler, uint8 *buf, uint32 buf_len, L1Ctm_DebugCallback debugCallback);
void L1Ctm_Close(void);
void L1Ctm_StartNegotiation(void);
uint32 L1Ctm_TxPutText(const uint8 *text, uint32 len, uint32 *left_space);
uint32 L1Ctm_RxGetText(uint8 *text, uint32 len, uint32 *left_count);

#endif 
