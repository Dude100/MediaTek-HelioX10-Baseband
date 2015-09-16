
#include "kal_public_api.h"
#include "kal_general_types.h"

#include "kal_trace.h"
#include "l1sp_trc.h"
#include "l1audio_trace.h"


#include "am.h"
//#include "speech_def.h"
#include "media.h" // for IDMA_ReadFromDSP
#include "pcmrec.h"
#include "audio_dsp_d2c_def.h"
#include "sal_exp.h"
#include "sal_def.h"

// ----------------------------------------------------------------------------
// Structure
// ----------------------------------------------------------------------------


static struct{
	kal_uint16 audId;

	kal_bool isRecording;  //state information. 
	
	PCM_REC_SAMPLE_RATE_IDX outSampleRateIdx; // DRV to user sampling rate. 
	kal_uint8 channelNum; // in & out are the same. 
	void (*pcmRec_hdlr)(void);
	
	PCM_REC_SAMPLE_RATE_IDX inSampleRateIdx; // DSP to MCU sampling rate. 
	kal_bool isDedicatedMode; //recording under speech is on, DSP to MCU sampling rate is sync with codec
	
	kal_uint8 bufReadFrame; 
	kal_uint8 bufWriteFrame;
	
	kal_uint16 outputFrameSize;  // unit is sample (word)
	kal_uint16 outputBufSize; // unit is sample (word)
}pcmRec; 

// ----------------------------------------------------------------------------
// Define
// ----------------------------------------------------------------------------


#define PCM_REC_FRAME_BUF_SIZE_8K       160
#define PCM_REC_FRAME_BUF_SIZE_16K      320

#define PCM_REC_FRAME_NO 4 // please take care of the size of pcmRec.bufReadFrame, pcmRec.bufWriteFrame
#define PCM_REC_FRAME_MASK (PCM_REC_FRAME_NO-1)
#define PCM_REC_FRAME_MAX_SIZE 640 // unit is word. 16k stereo 20ms. 16*2*20 = 640 words

// ----------------------------------------------------------------------------
// buffers and varables
// ----------------------------------------------------------------------------

static kal_uint16 pcmRecOutputBuf[PCM_REC_FRAME_NO*PCM_REC_FRAME_MAX_SIZE];
static kal_uint16 pcmRecInternalBuf[PCM_REC_FRAME_NO][PCM_REC_FRAME_MAX_SIZE];


static kal_uint16 dualMicOrDlTempBuf[PCM_REC_FRAME_BUF_SIZE_16K];


/**
	@buf1: pointer to pcm buf1, 
	@len1:length of buf1, unit is word(2byte)
	@buf2:pointer to pcm buf2
	@len2: length of buf2. unit is word(2byte)
*/
void PcmRec_GetMicDataBufs(kal_uint32 *add1, kal_uint16 *len1, kal_uint32 *add2, kal_uint16 *len2)
{
	kal_uint8 curWriteFrame = pcmRec.bufWriteFrame; // for keep write frame
	kal_uint8 procFrame;
	kal_uint8 idx;

	procFrame =  curWriteFrame-pcmRec.bufReadFrame; //circular buffer

	if(procFrame > PCM_REC_FRAME_NO) {
		procFrame = PCM_REC_FRAME_NO; 			
	}

	idx = curWriteFrame - procFrame;
	if(idx >= pcmRec.bufReadFrame){ // write > read, 1 buf segment
	
		*add1 = (kal_uint32)(pcmRecOutputBuf + ((idx&PCM_REC_FRAME_MASK)*pcmRec.outputFrameSize));		
		*len1 = (procFrame * pcmRec.outputFrameSize);		
		*add2 = 0;
		*len2 = 0;
	
	} else { //write < read, 2 buf segment
		*add1 = (kal_uint32)(pcmRecOutputBuf+ ((idx&PCM_REC_FRAME_MASK)*pcmRec.outputFrameSize));
		*len1 = ((PCM_REC_FRAME_NO - (idx&PCM_REC_FRAME_MASK))*pcmRec.outputFrameSize);
		*add2 = (kal_uint32)(pcmRecOutputBuf);
		*len2 = ((curWriteFrame&PCM_REC_FRAME_MASK)*pcmRec.outputFrameSize);		
	}
		
	kal_trace(TRACE_INFO, PCMREC_GET_MIC_DATA_BUFS, procFrame, idx, curWriteFrame, pcmRec.bufReadFrame);
	pcmRec.bufReadFrame = curWriteFrame;
}

void pcmRec_GetMicDataFromDSP(kal_uint16 * buf)
{
	volatile uint16* dspAddr;
	uint32 framesize; //uplink

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
	if(pcmRec.isDedicatedMode == KAL_FALSE && pcmRec.channelNum > 1) { // stereo record with interleave

		uint16 i; 

		framesize = (PCM_REC_SAMPLE_RATE_IDX_16K == pcmRec.inSampleRateIdx)? 320: 160 ; 
		
		//The framesize should be indicated by DSP, especially in call record
		framesize = SAL_PcmEx_GetBufLen(SAL_PCMEX_BUF_SE);
		/* handle uplink data from 1st mic */
		dspAddr = SAL_PcmEx_GetBuf(SAL_PCMEX_BUF_SE);

		kal_brief_trace(TRACE_INFO, PCMREC_HISR_DATA_FROM_DSP, dspAddr, framesize);
		
		IDMA_ReadFromDSP((uint16*)dualMicOrDlTempBuf, dspAddr, (uint32)framesize*sizeof(kal_int16));
		for(i=0; i<framesize; i++){ //interleave
			buf[i*2] = dualMicOrDlTempBuf[i];
		}
		
		/* handle uplink data from 2st mic */
		dspAddr = SAL_PcmEx_GetBuf(SAL_PCMEX_BUF_SE2);
		kal_brief_trace(TRACE_INFO, PCMREC_HISR_DATA_FROM_DSP, dspAddr, framesize);
		
		IDMA_ReadFromDSP((uint16*)dualMicOrDlTempBuf, dspAddr, (uint32)framesize*sizeof(kal_int16));

		for(i=0; i<framesize; i++){ //interleave
			buf[i*2+1] = dualMicOrDlTempBuf[i];
		}
		
	} 
	else 
#endif // defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
	{
		if(pcmRec.isDedicatedMode) { // under call
			uint16 dlFrameSize; 
			kal_uint16 *ulBuf;
			kal_int16 dlValue, ulValue; 
			kal_int16 dlJumpSize, ulJumpSize;
			kal_int16 i, dlI, ulI; 
			
			// framesize = (PCM_REC_SAMPLE_RATE_IDX_16K == pcmRec.inSampleRateIdx)? 320: 160 ; 

			// get uplink data	
			ulBuf = buf; // to keep origianl starting point
			
			framesize = SAL_PcmEx_GetBufLen(SAL_PCMEX_BUF_SE);			
			dspAddr = SAL_PcmEx_GetBuf(SAL_PCMEX_BUF_SE);
			kal_brief_trace(TRACE_INFO, PCMREC_HISR_DATA_FROM_DSP, dspAddr, framesize);
			IDMA_ReadFromDSP(buf, dspAddr, (uint32)framesize);

			if(PCM_REC_FRAME_BUF_SIZE_16K == framesize){
				ulJumpSize = 2;
			} else {
				ulJumpSize = 1;
			}

		
			// get downlink data 
			dlFrameSize = SAL_PcmEx_GetBufLen(SAL_PCMEX_BUF_SD);
			dspAddr = SAL_PcmEx_GetBuf(SAL_PCMEX_BUF_SD);
			kal_brief_trace(TRACE_INFO, PCMREC_HISR_DATA_FROM_DSP, dspAddr, dlFrameSize);
			IDMA_ReadFromDSP(dualMicOrDlTempBuf, dspAddr, (uint32)dlFrameSize);

			if(PCM_REC_FRAME_BUF_SIZE_16K == dlFrameSize){
				dlJumpSize = 2;
			} else {
				dlJumpSize = 1;
			}

			// mix			
			ulI=0;
			dlI=0;
			for(i=0; i< PCM_REC_FRAME_BUF_SIZE_8K; i++) {				
				ulValue = ulBuf[ulI]; 
				dlValue = dualMicOrDlTempBuf[dlI]; 
				
				ulBuf[i] = ((dlValue+ulValue)>>1);

				//move 				
				ulI+=ulJumpSize;
				dlI+=dlJumpSize;
			}
			/*
			framesize = SAL_PcmEx_GetBufLen(SAL_PCMEX_BUF_SE);
			dlFrameSize = SAL_PcmEx_GetBufLen(SAL_PCMEX_BUF_SD);

			if(framesize == dlFrameSize){
				int i; 

				// get uplink data				
				ulBuf = buf; // to keep origianl starting point
				dspAddr = SAL_PcmEx_GetBuf(SAL_PCMEX_BUF_SE);
				kal_brief_trace(TRACE_INFO, PCMREC_HISR_DATA_FROM_DSP, dspAddr, framesize);
				IDMA_ReadFromDSP(buf, dspAddr, (uint32)framesize);
				
				
				// get downlink data 
				dspAddr = SAL_PcmEx_GetBuf(SAL_PCMEX_BUF_SD);
				kal_brief_trace(TRACE_INFO, PCMREC_HISR_DATA_FROM_DSP, dspAddr, dlFrameSize);
				IDMA_ReadFromDSP(dualMicOrDlTempBuf, dspAddr, (uint32)dlFrameSize);

				// mix								
				for(i=0; i< framesize; i++) {
					dlValue = dualMicOrDlTempBuf[i]; 
					ulValue = ulBuf[i]; 
					
					ulBuf[i] = ((dlValue+ulValue)>>1);
				}		
			
				
				
			} else {
				ASSERT(0); // TODO: inplement the size conversion
			}	*/
		} else { // idle 
			framesize = pcmRec.outputFrameSize; 
			
			framesize = SAL_PcmEx_GetBufLen(SAL_PCMEX_BUF_SE);
		
			/* handle uplink data */
			dspAddr = SAL_PcmEx_GetBuf(SAL_PCMEX_BUF_SE);
			//kal_prompt_trace(MOD_L1SP, "*DPRAM2_base(SPH_DM_ADDR_SE_PTR) = %x", dspAddr);
			//dspAddr = *DSP_DM_ADDR(PCM_REC_PAGE_NUM, dspAddr);		
			kal_brief_trace(TRACE_INFO, PCMREC_HISR_DATA_FROM_DSP, dspAddr, framesize);
			
			IDMA_ReadFromDSP(buf, dspAddr, (uint32)framesize);
		}

		
		
	}	

}

void pcmRecHisr(void *param)
{

	kal_uint16 frameIdx = (pcmRec.bufWriteFrame & PCM_REC_FRAME_MASK);

	// check the buffer 
	if( (
				(pcmRec.bufWriteFrame >= pcmRec.bufReadFrame) 
			&& (pcmRec.bufWriteFrame - pcmRec.bufReadFrame)>= PCM_REC_FRAME_NO
		  )
		 ||
		  (
				(pcmRec.bufWriteFrame < pcmRec.bufReadFrame) 
			&& (pcmRec.bufWriteFrame + 256 - pcmRec.bufReadFrame)>= PCM_REC_FRAME_NO
		  )
		) {
		//leave the log when buffer is full
		kal_brief_trace(TRACE_INFO, PCMREC_HISR_DATA_DROP_DSP, pcmRec.bufWriteFrame, pcmRec.bufReadFrame);
		
	} else { // There has some empty buffer

		//get from dsp
		pcmRec_GetMicDataFromDSP(pcmRecInternalBuf[frameIdx]);
		
		// sampling rate converting if necessary (call record converting is do under get from dsp)
		
		// put to output frame
		memcpy( (pcmRecOutputBuf+(pcmRec.outputFrameSize*frameIdx)), pcmRecInternalBuf[frameIdx], pcmRec.outputFrameSize * sizeof(kal_uint16));
		pcmRec.bufWriteFrame++;

	}	
	//excute callback function 
	pcmRec.pcmRec_hdlr();
	
}


void PCMREC_Start(void (*pcmRec_hdlr)(void), uint8 channelNum, PCM_REC_SAMPLE_RATE_IDX samplingRateIdx)
{   
	// lock sleep mode
	pcmRec.audId = L1Audio_GetAudioID();
   L1Audio_SetFlag( pcmRec.audId ); 
	
	pcmRec.outSampleRateIdx = samplingRateIdx;
	pcmRec.channelNum = channelNum; 
	pcmRec.isDedicatedMode = AM_IsAmInSpeechState();
	pcmRec.pcmRec_hdlr = pcmRec_hdlr;

	//calculate frame size & output buffer size
	switch(samplingRateIdx) {
		case PCM_REC_SAMPLE_RATE_IDX_8K:
			pcmRec.outputFrameSize = (PCM_REC_FRAME_BUF_SIZE_8K << (channelNum-1));			
			break;
		case PCM_REC_SAMPLE_RATE_IDX_16K:
			pcmRec.outputFrameSize = (PCM_REC_FRAME_BUF_SIZE_16K << (channelNum-1));
			break;
		default:
			ASSERT(0);
	}
	pcmRec.outputBufSize = pcmRec.outputFrameSize * PCM_REC_FRAME_NO;
	
	//buffer and pointer reseting
	pcmRec.bufReadFrame = 0;
	pcmRec.bufWriteFrame = 0; 	
	memset(pcmRecInternalBuf, 0, PCM_REC_FRAME_NO*PCM_REC_FRAME_MAX_SIZE*sizeof(uint16));
	memset(pcmRecOutputBuf, 0, PCM_REC_FRAME_NO*PCM_REC_FRAME_MAX_SIZE*sizeof(uint16));

	L1Audio_HookHisrHandler( DP_D2C_PCM_REC_INT, pcmRecHisr, 0); 
	
	// invoke am to start record
	if (pcmRec.isDedicatedMode) {

		pcmRec.inSampleRateIdx = PCM_REC_SAMPLE_RATE_IDX_UNDEF;  // dynamic
		// L1Audio_HookHisrHandler( D2C_UL_DL_PCM_REC_INT_ID, pcmRecHisr, 0 ); //vocTchPcmRecordHisr
		AM_PCM8K_RecordOn(AM_PCM8KREC_APP_TYPE_PCMREC);
		
	} else {

		pcmRec.inSampleRateIdx = samplingRateIdx;
		// L1Audio_HookHisrHandler( DP_D2C_PCM_REC_INT, pcmRecHisr, 0); 
		
		if(PCM_REC_SAMPLE_RATE_IDX_8K == samplingRateIdx) {			
			
	      AM_PCM8K_RecordOn(AM_PCM8KREC_APP_TYPE_PCMREC);			
			
		} else if(PCM_REC_SAMPLE_RATE_IDX_16K == samplingRateIdx) {
		
			AM_PCM16K_RecordOn();
			
		} else {
			ASSERT(0); // invalid input sampling rate. 
		}
	}

	pcmRec.isRecording = KAL_TRUE;
}



void PCMREC_Stop()
{
	if (pcmRec.isDedicatedMode) {

		AM_PCM8K_RecordOff(false, AM_PCM8KREC_APP_TYPE_PCMREC); // do not need toe wait
		// L1Audio_UnhookHisrHandler(D2C_UL_DL_PCM_REC_INT_ID); //vocTchPcmRecordHisr
				
	} else {	
		
		if(PCM_REC_SAMPLE_RATE_IDX_8K == pcmRec.inSampleRateIdx) {			
			
	      AM_PCM8K_RecordOff(true, AM_PCM8KREC_APP_TYPE_PCMREC); 
			
		} else if(PCM_REC_SAMPLE_RATE_IDX_16K == pcmRec.inSampleRateIdx) {
		
			AM_PCM16K_RecordOff(true);
			
		} else {
			ASSERT(0); // invalid input sampling rate. 
		}
		// L1Audio_UnhookHisrHandler(DP_D2C_PCM_REC_INT);		
	}
	L1Audio_UnhookHisrHandler(DP_D2C_PCM_REC_INT);
	pcmRec.isRecording = KAL_FALSE;
	
	pcmRec.isDedicatedMode = KAL_FALSE;
	pcmRec.channelNum = 0;
	pcmRec.outSampleRateIdx = PCM_REC_SAMPLE_RATE_IDX_UNDEF;

	// unlock sleep
	L1Audio_ClearFlag( pcmRec.audId );
   L1Audio_FreeAudioID( pcmRec.audId );
	
}

