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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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


// need to define CTM_Param 
typedef struct
{
    kal_int16   cprm_tone_demod_down_samp;                  // 1 (0, 1)   
} CTM_Param;


typedef void (*L1Ctm_Callback)(L1Ctm_Event , void*); 

uint32 L1Ctm_GetMemReq(void);
void L1Ctm_Open(L1Ctm_Interface a, L1Ctm_Callback handler, uint8 *buf, uint32 buf_len, CTM_Param *ctm_param);
void L1Ctm_Close(void);
void L1Ctm_StartNegotiation(void);
uint32 L1Ctm_TxPutText(const uint8 *text, uint32 len, uint32 *left_space);
uint32 L1Ctm_RxGetText(uint8 *text, uint32 len, uint32 *left_count);

#endif 
