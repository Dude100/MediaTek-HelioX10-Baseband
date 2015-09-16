#ifndef _PCMREC_H_
#define _PCMREC_H_

typedef enum {
	PCM_REC_SAMPLE_RATE_IDX_8K = 0,
	PCM_REC_SAMPLE_RATE_IDX_16K, 
	PCM_REC_SAMPLE_RATE_IDX_32K,
	PCM_REC_SAMPLE_RATE_IDX_48K,
	
	PCM_REC_SAMPLE_RATE_IDX_UNDEF = 0xf
}PCM_REC_SAMPLE_RATE_IDX;
	
void PCMREC_Start(void (*pcmRec_hdlr)(void), uint8 channelNum, PCM_REC_SAMPLE_RATE_IDX samplingRateIdx);
void PCMREC_Stop();

void PcmRec_GetMicDataBufs(kal_uint32 *add1, kal_uint16 *len1, kal_uint32 *add2, kal_uint16 *len2);

#endif
