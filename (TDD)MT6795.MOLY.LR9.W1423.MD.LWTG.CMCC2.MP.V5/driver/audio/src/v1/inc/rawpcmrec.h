#ifndef _RAWPCMREC_H_
#define _RAWPCMREC_H_

#include "pcmrec.h"
/*typedef enum {
	PCM_REC_SAMPLE_RATE_IDX_8K = 0,
	PCM_REC_SAMPLE_RATE_IDX_16K, 
	PCM_REC_SAMPLE_RATE_IDX_32K,
	PCM_REC_SAMPLE_RATE_IDX_48K,
	
	PCM_REC_SAMPLE_RATE_IDX_UNDEF = 0xf
}PCM_REC_SAMPLE_RATE_IDX;*/

typedef struct spcRAWPCMBufInfoStruct{
	//UL sample rate, please refer PCM_REC_SAMPLE_RATE_IDX
	uint16 u16ULFreq;
	//UL length in byte
	uint16 u16ULLength;
	//DL sample rate, please refer PCM_REC_SAMPLE_RATE_IDX
	uint16 u16DLFreq;
	//DL length in byte
	uint16 u16DLLength;
}spcRAWPCMBufInfo, *pspcRAWPCMBufInfo;


void RAWPCMREC_Start(void (*pcmRec_hdlr)(void), kal_uint8 ULChannelNumIdx);
void RAWPCMREC_Stop();

void RawPcmRec_GetMicDataBufs(kal_uint32 *add1, kal_uint16 *len1, kal_uint32 *add2, kal_uint16 *len2);

#endif //#ifndef _RAWPCMREC_H_

