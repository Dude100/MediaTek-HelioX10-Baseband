#include "kal_public_api.h"
#include "kal_general_types.h"

#include "kal_trace.h"
#include "l1sp_trc.h"
#include "l1audio_trace.h"


#include "am.h"
//#include "speech_def.h"
#include "media.h" // for IDMA_ReadFromDSP
#include "rawpcmrec.h"
#include "audio_dsp_d2c_def.h"
#include "sal_exp.h"
#include "sal_def.h"


// ----------------------------------------------------------------------------
// Structure
// ----------------------------------------------------------------------------

static struct{
	kal_uint16 audId;

	kal_bool isRecording;  //state information. 
	
	//PCM_REC_SAMPLE_RATE_IDX outSampleRateIdx; // DRV to user sampling rate. 
	kal_uint8 ULChannelNum; // in & out are the same. 
	void (*RawPcmRec_hdlr)(void);
	
	PCM_REC_SAMPLE_RATE_IDX inSampleRateIdx; // DSP to MCU sampling rate. 
	kal_bool isDedicatedMode; //recording under speech is on, DSP to MCU sampling rate is sync with codec
	
	//kal_uint8 bufReadFrame; 
	//kal_uint8 bufWriteFrame;
	
	//kal_uint16 outputFrameSize;  // unit is sample (word)
	//kal_uint16 outputBufSize; // unit is sample (word)
}RawPcmRec; 


// ----------------------------------------------------------------------------
// Define
// ----------------------------------------------------------------------------

#define RAW_PCM_REC_FRAME_BUF_SIZE_8K       (160)
#define RAW_PCM_REC_FRAME_BUF_SIZE_16K      (320)
#define RAW_PCM_REC_FRAME_BUF_SIZE_32K      (640)
#define RAW_PCM_REC_FRAME_BUF_SIZE_48K      (960)

//header + sample*2ch(UL+DL)*2byte
#define RAW_PCM_TOTAL_BUFFER_BYTE_SIZE (sizeof(spcRAWPCMBufInfo) + RAW_PCM_REC_FRAME_BUF_SIZE_48K*2*2)

// ----------------------------------------------------------------------------
// buffers and varables
// ----------------------------------------------------------------------------

static kal_uint16        dualMicOrDlTempBuf[RAW_PCM_REC_FRAME_BUF_SIZE_48K];
static kal_uint32        RawPcmRecBuf[(RAW_PCM_TOTAL_BUFFER_BYTE_SIZE+3)>>2];
static spcRAWPCMBufInfo *pstspcRAWPCMBufInfo;
static kal_uint16       *pRawPcmRecBufData;


extern bool spc_RawPcmRec_getDataWaiting(void);


/**
	@buf1: pointer to pcm buf1, 
	@len1:length of buf1, unit is word(2byte)
	@buf2:pointer to pcm buf2
	@len2: length of buf2. unit is word(2byte)
*/
void RawPcmRec_GetMicDataBufs(kal_uint32 *add1, kal_uint16 *len1, kal_uint32 *add2, kal_uint16 *len2)
{
	*add1 = (kal_uint32)(RawPcmRecBuf);		
	*len1 = (sizeof(spcRAWPCMBufInfo) + pstspcRAWPCMBufInfo->u16ULLength + pstspcRAWPCMBufInfo->u16DLLength) >> 1;
	*add2 = 0;
	*len2 = 0;

	kal_trace(TRACE_INFO, RAWPCMREC_GET_MIC_DATA_BUFS, RawPcmRecBuf, sizeof(spcRAWPCMBufInfo), pstspcRAWPCMBufInfo->u16ULLength, pstspcRAWPCMBufInfo->u16DLLength);
}


void RawPcmRec_GetMicDataFromDSP(kal_uint16 * buf)
{
	volatile uint16* dspAddr;
	uint32 framesize = 0; //uplink
    uint16 dlFrameSize = 0;

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
	if( (RawPcmRec.isDedicatedMode==KAL_FALSE) && (RawPcmRec.ULChannelNum>1) ) { // stereo record with interleave
		uint16 i; 

		//framesize = (PCM_REC_SAMPLE_RATE_IDX_16K == RawPcmRec.inSampleRateIdx) ? 320 : 160;

		//The framesize should be indicated by DSP, especially in call record
		framesize = SAL_PcmEx_GetBufLen(SAL_PCMEX_BUF_SE);
        ASSERT(framesize <= ((sizeof(dualMicOrDlTempBuf))/(sizeof(kal_uint16))));

		/* handle uplink data from 1st mic */
		dspAddr = SAL_PcmEx_GetBuf(SAL_PCMEX_BUF_SE);

		kal_brief_trace(TRACE_INFO, RAWPCMREC_HISR_DATA_FROM_DSP, dspAddr, framesize);

		IDMA_ReadFromDSP((uint16*)dualMicOrDlTempBuf, dspAddr, (uint32)framesize/**sizeof(kal_int16)*/);
		for(i=0; i<framesize; i++){ //interleave
			buf[i*2] = dualMicOrDlTempBuf[i];
		}
		
		/* handle uplink data from 2st mic */
		dspAddr = SAL_PcmEx_GetBuf(SAL_PCMEX_BUF_SE2);
		kal_brief_trace(TRACE_INFO, RAWPCMREC_HISR_DATA_FROM_DSP, dspAddr, framesize);
		
		IDMA_ReadFromDSP((uint16*)dualMicOrDlTempBuf, dspAddr, (uint32)framesize/**sizeof(kal_int16)*/);
		for(i=0; i<framesize; i++){ //interleave
			buf[i*2+1] = dualMicOrDlTempBuf[i];
		}

		switch(framesize)
		{
			case RAW_PCM_REC_FRAME_BUF_SIZE_8K:
				pstspcRAWPCMBufInfo->u16ULFreq   = PCM_REC_SAMPLE_RATE_IDX_8K;
				pstspcRAWPCMBufInfo->u16ULLength = RAW_PCM_REC_FRAME_BUF_SIZE_8K<<2; //unit is byte
				break;
			case RAW_PCM_REC_FRAME_BUF_SIZE_16K:
				pstspcRAWPCMBufInfo->u16ULFreq   = PCM_REC_SAMPLE_RATE_IDX_16K;
				pstspcRAWPCMBufInfo->u16ULLength = RAW_PCM_REC_FRAME_BUF_SIZE_16K<<2; //unit is byte
				break;
			case RAW_PCM_REC_FRAME_BUF_SIZE_32K:
				pstspcRAWPCMBufInfo->u16ULFreq   = PCM_REC_SAMPLE_RATE_IDX_32K;
				pstspcRAWPCMBufInfo->u16ULLength = RAW_PCM_REC_FRAME_BUF_SIZE_32K<<2; //unit is byte
				break;
			case RAW_PCM_REC_FRAME_BUF_SIZE_48K:
				pstspcRAWPCMBufInfo->u16ULFreq   = PCM_REC_SAMPLE_RATE_IDX_48K;
				pstspcRAWPCMBufInfo->u16ULLength = RAW_PCM_REC_FRAME_BUF_SIZE_48K<<2; //unit is byte
				break;
			default:
				ASSERT(0);
				break;
		}
        pstspcRAWPCMBufInfo->u16DLFreq   = PCM_REC_SAMPLE_RATE_IDX_UNDEF;
        pstspcRAWPCMBufInfo->u16DLLength = 0;

        kal_brief_trace(TRACE_INFO, RAWPCMREC_GET_DATA_INFO, 0, pstspcRAWPCMBufInfo->u16ULFreq, pstspcRAWPCMBufInfo->u16ULLength, pstspcRAWPCMBufInfo->u16DLFreq, pstspcRAWPCMBufInfo->u16DLLength);
	} 
	else 
#endif // defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
	{
		if(RawPcmRec.isDedicatedMode) { // under call
			//kal_uint16 *ulBuf;
			//kal_int16 dlValue, ulValue; 
			//kal_int16 dlJumpSize, ulJumpSize;
			//kal_int16 i, dlI, ulI; 
			
			// framesize = (PCM_REC_SAMPLE_RATE_IDX_16K == RawPcmRec.inSampleRateIdx)? 320: 160 ; 

			// get uplink data	
			//ulBuf = buf; // to keep origianl starting point
			
			framesize = SAL_PcmEx_GetBufLen(SAL_PCMEX_BUF_SE);			
            ASSERT(framesize <= RAW_PCM_REC_FRAME_BUF_SIZE_48K);
			dspAddr = SAL_PcmEx_GetBuf(SAL_PCMEX_BUF_SE);
			kal_brief_trace(TRACE_INFO, RAWPCMREC_HISR_DATA_FROM_DSP, dspAddr, framesize);
			IDMA_ReadFromDSP(buf, dspAddr, (uint32)framesize);

            switch(framesize)
            {
                case RAW_PCM_REC_FRAME_BUF_SIZE_8K:
                    pstspcRAWPCMBufInfo->u16ULFreq   = PCM_REC_SAMPLE_RATE_IDX_8K;
                    pstspcRAWPCMBufInfo->u16ULLength = RAW_PCM_REC_FRAME_BUF_SIZE_8K<<1; //unit is byte
                    break;
                case RAW_PCM_REC_FRAME_BUF_SIZE_16K:
                    pstspcRAWPCMBufInfo->u16ULFreq   = PCM_REC_SAMPLE_RATE_IDX_16K;
                    pstspcRAWPCMBufInfo->u16ULLength = RAW_PCM_REC_FRAME_BUF_SIZE_16K<<1; //unit is byte
                    break;
                case RAW_PCM_REC_FRAME_BUF_SIZE_32K:
                    pstspcRAWPCMBufInfo->u16ULFreq   = PCM_REC_SAMPLE_RATE_IDX_32K;
                    pstspcRAWPCMBufInfo->u16ULLength = RAW_PCM_REC_FRAME_BUF_SIZE_32K<<1; //unit is byte
                    break;
                case RAW_PCM_REC_FRAME_BUF_SIZE_48K:
                    pstspcRAWPCMBufInfo->u16ULFreq   = PCM_REC_SAMPLE_RATE_IDX_48K;
                    pstspcRAWPCMBufInfo->u16ULLength = RAW_PCM_REC_FRAME_BUF_SIZE_48K<<1; //unit is byte
                    break;
                default:
                    ASSERT(0);
                    break;
            }
            pstspcRAWPCMBufInfo->u16DLFreq   = PCM_REC_SAMPLE_RATE_IDX_UNDEF;
            pstspcRAWPCMBufInfo->u16DLLength = 0;

			/*if(PCM_REC_FRAME_BUF_SIZE_16K == framesize){
				ulJumpSize = 2;
			} else {
				ulJumpSize = 1;
			}*/

		
			// get downlink data 
			dlFrameSize = SAL_PcmEx_GetBufLen(SAL_PCMEX_BUF_SD);
            ASSERT(dlFrameSize <= RAW_PCM_REC_FRAME_BUF_SIZE_48K);
			dspAddr = SAL_PcmEx_GetBuf(SAL_PCMEX_BUF_SD);
			kal_brief_trace(TRACE_INFO, RAWPCMREC_HISR_DATA_FROM_DSP, dspAddr, dlFrameSize);
			IDMA_ReadFromDSP(/*dualMicOrDlTempBuf*/buf+framesize, dspAddr, (uint32)dlFrameSize);

            switch(dlFrameSize)
            {
                case RAW_PCM_REC_FRAME_BUF_SIZE_8K:
                    pstspcRAWPCMBufInfo->u16DLFreq   = PCM_REC_SAMPLE_RATE_IDX_8K;
                    pstspcRAWPCMBufInfo->u16DLLength = RAW_PCM_REC_FRAME_BUF_SIZE_8K<<1; //unit is byte
                    break;
                case RAW_PCM_REC_FRAME_BUF_SIZE_16K:
                    pstspcRAWPCMBufInfo->u16DLFreq   = PCM_REC_SAMPLE_RATE_IDX_16K;
                    pstspcRAWPCMBufInfo->u16DLLength = RAW_PCM_REC_FRAME_BUF_SIZE_16K<<1; //unit is byte
                    break;
                case RAW_PCM_REC_FRAME_BUF_SIZE_32K:
                    pstspcRAWPCMBufInfo->u16DLFreq   = PCM_REC_SAMPLE_RATE_IDX_32K;
                    pstspcRAWPCMBufInfo->u16DLLength = RAW_PCM_REC_FRAME_BUF_SIZE_32K<<1; //unit is byte
                    break;
                case RAW_PCM_REC_FRAME_BUF_SIZE_48K:
                    pstspcRAWPCMBufInfo->u16DLFreq   = PCM_REC_SAMPLE_RATE_IDX_48K;
                    pstspcRAWPCMBufInfo->u16DLLength = RAW_PCM_REC_FRAME_BUF_SIZE_48K<<1; //unit is byte
                    break;
                default:
                    ASSERT(0);
                    break;
            }

            kal_brief_trace(TRACE_INFO, RAWPCMREC_GET_DATA_INFO, 1, pstspcRAWPCMBufInfo->u16ULFreq, pstspcRAWPCMBufInfo->u16ULLength, pstspcRAWPCMBufInfo->u16DLFreq, pstspcRAWPCMBufInfo->u16DLLength);

			/*if(PCM_REC_FRAME_BUF_SIZE_16K == dlFrameSize){
				dlJumpSize = 2;
			} else {
				dlJumpSize = 1;
			}*/

			// mix			
			/*ulI=0;
			dlI=0;
			for(i=0; i< PCM_REC_FRAME_BUF_SIZE_8K; i++) {				
				ulValue = ulBuf[ulI]; 
				dlValue = dualMicOrDlTempBuf[dlI]; 
				
				ulBuf[i] = ((dlValue+ulValue)>>1);

				//move 				
				ulI+=ulJumpSize;
				dlI+=dlJumpSize;
			}*/
		} else { // idle 
			//framesize = RawPcmRec.outputFrameSize; 
			
			framesize = SAL_PcmEx_GetBufLen(SAL_PCMEX_BUF_SE);
            ASSERT(framesize <= RAW_PCM_REC_FRAME_BUF_SIZE_48K);
		
			/* handle uplink data */
			dspAddr = SAL_PcmEx_GetBuf(SAL_PCMEX_BUF_SE);
			//kal_prompt_trace(MOD_L1SP, "*DPRAM2_base(SPH_DM_ADDR_SE_PTR) = %x", dspAddr);
			//dspAddr = *DSP_DM_ADDR(PCM_REC_PAGE_NUM, dspAddr);		
			kal_brief_trace(TRACE_INFO, RAWPCMREC_HISR_DATA_FROM_DSP, dspAddr, framesize);
			
			IDMA_ReadFromDSP(buf, dspAddr, (uint32)framesize);

            switch(framesize)
            {
                case RAW_PCM_REC_FRAME_BUF_SIZE_8K:
                    pstspcRAWPCMBufInfo->u16ULFreq   = PCM_REC_SAMPLE_RATE_IDX_8K;
                    pstspcRAWPCMBufInfo->u16ULLength = RAW_PCM_REC_FRAME_BUF_SIZE_8K<<1; //unit is byte
                    break;
                case RAW_PCM_REC_FRAME_BUF_SIZE_16K:
                    pstspcRAWPCMBufInfo->u16ULFreq   = PCM_REC_SAMPLE_RATE_IDX_16K;
                    pstspcRAWPCMBufInfo->u16ULLength = RAW_PCM_REC_FRAME_BUF_SIZE_16K<<1; //unit is byte
                    break;
                case RAW_PCM_REC_FRAME_BUF_SIZE_32K:
                    pstspcRAWPCMBufInfo->u16ULFreq   = PCM_REC_SAMPLE_RATE_IDX_32K;
                    pstspcRAWPCMBufInfo->u16ULLength = RAW_PCM_REC_FRAME_BUF_SIZE_32K<<1; //unit is byte
                    break;
                case RAW_PCM_REC_FRAME_BUF_SIZE_48K:
                    pstspcRAWPCMBufInfo->u16ULFreq   = PCM_REC_SAMPLE_RATE_IDX_48K;
                    pstspcRAWPCMBufInfo->u16ULLength = RAW_PCM_REC_FRAME_BUF_SIZE_48K<<1; //unit is byte
                    break;
                default:
                    ASSERT(0);
                    break;
            }
            pstspcRAWPCMBufInfo->u16DLFreq   = PCM_REC_SAMPLE_RATE_IDX_UNDEF;
            pstspcRAWPCMBufInfo->u16DLLength = 0;

            kal_brief_trace(TRACE_INFO, RAWPCMREC_GET_DATA_INFO, 2, pstspcRAWPCMBufInfo->u16ULFreq, pstspcRAWPCMBufInfo->u16ULLength, pstspcRAWPCMBufInfo->u16DLFreq, pstspcRAWPCMBufInfo->u16DLLength);
		}

	}	

}


void RawPcmRecHisr(void *param)
{
	// check the buffer 
	if(true == spc_RawPcmRec_getDataWaiting()) {
		//leave the log when buffer is full
		kal_brief_trace(TRACE_INFO, RAWPCMREC_HISR_DATA_DROP_DSP);
	} else { // There has some empty buffer
		//get from dsp
		RawPcmRec_GetMicDataFromDSP(pRawPcmRecBufData);
	}	
	//excute callback function 
	RawPcmRec.RawPcmRec_hdlr();
}


void RAWPCMREC_Start(void (*RawPcmRec_hdlr)(void), kal_uint8 ULChannelNumIdx)
{   
	//???
	uint8 channelNum;
	PCM_REC_SAMPLE_RATE_IDX samplingRateIdx;

	// lock sleep mode
	RawPcmRec.audId = L1Audio_GetAudioID();
	L1Audio_SetFlag( RawPcmRec.audId ); 

	//RawPcmRec.outSampleRateIdx = samplingRateIdx;
	RawPcmRec.ULChannelNum = ULChannelNumIdx; 
	RawPcmRec.isDedicatedMode = AM_IsAmInSpeechState();
	RawPcmRec.RawPcmRec_hdlr = RawPcmRec_hdlr;

	//calculate frame size & output buffer size
	/*switch(samplingRateIdx) {
		case PCM_REC_SAMPLE_RATE_IDX_8K:
			RawPcmRec.outputFrameSize = (PCM_REC_FRAME_BUF_SIZE_8K << (channelNum-1));			
			break;
		case PCM_REC_SAMPLE_RATE_IDX_16K:
			RawPcmRec.outputFrameSize = (PCM_REC_FRAME_BUF_SIZE_16K << (channelNum-1));
			break;
		default:
			ASSERT(0);
	}
	RawPcmRec.outputBufSize = RawPcmRec.outputFrameSize * PCM_REC_FRAME_NO;*/
	
	//buffer and pointer reseting
	//RawPcmRec.bufReadFrame = 0;
	//RawPcmRec.bufWriteFrame = 0; 	
	//memset(RawPcmRecInternalBuf, 0, PCM_REC_FRAME_NO*PCM_REC_FRAME_MAX_SIZE*sizeof(uint16));
	//memset(RawPcmRecOutputBuf, 0, PCM_REC_FRAME_NO*PCM_REC_FRAME_MAX_SIZE*sizeof(uint16));
	memset(RawPcmRecBuf, 0, sizeof(RawPcmRecBuf));
	pstspcRAWPCMBufInfo = (pspcRAWPCMBufInfo)(RawPcmRecBuf);
    pRawPcmRecBufData   = (kal_uint16 *)(RawPcmRecBuf);
    pRawPcmRecBufData   = pRawPcmRecBufData + ( sizeof(spcRAWPCMBufInfo) / sizeof(kal_uint16) );

	L1Audio_HookHisrHandler( DP_D2C_PCM_REC_INT, RawPcmRecHisr, 0); 
	
	// invoke am to start record
	if(RawPcmRec.isDedicatedMode) {
		RawPcmRec.inSampleRateIdx = PCM_REC_SAMPLE_RATE_IDX_UNDEF;  // dynamic
		// L1Audio_HookHisrHandler( D2C_UL_DL_PCM_REC_INT_ID, RawPcmRecHisr, 0 ); //vocTchRawPcmRecordHisr
		AM_PCM8K_RecordOn(AM_PCM8KREC_APP_TYPE_PCMREC);
	}else {
		RawPcmRec.inSampleRateIdx = PCM_REC_SAMPLE_RATE_IDX_16K;
		//L1Audio_HookHisrHandler( DP_D2C_PCM_REC_INT, RawPcmRecHisr, 0); 
		AM_PCM16K_RecordOn();
	}

	RawPcmRec.isRecording = KAL_TRUE;
}



void RAWPCMREC_Stop()
{
	if (RawPcmRec.isDedicatedMode) {

		AM_PCM8K_RecordOff(false, AM_PCM8KREC_APP_TYPE_PCMREC); // do not need toe wait
		// L1Audio_UnhookHisrHandler(D2C_UL_DL_PCM_REC_INT_ID); //vocTchPcmRecordHisr
				
	} else {	
		
		if(PCM_REC_SAMPLE_RATE_IDX_8K == RawPcmRec.inSampleRateIdx) {			
			
	      AM_PCM8K_RecordOff(true, AM_PCM8KREC_APP_TYPE_PCMREC); 
			
		} else if(PCM_REC_SAMPLE_RATE_IDX_16K == RawPcmRec.inSampleRateIdx) {
		
			AM_PCM16K_RecordOff(true);
			
		} else {
			ASSERT(0); // invalid input sampling rate. 
		}
		// L1Audio_UnhookHisrHandler(DP_D2C_PCM_REC_INT);		
	}
	L1Audio_UnhookHisrHandler(DP_D2C_PCM_REC_INT);
	RawPcmRec.isRecording = KAL_FALSE;
	
	RawPcmRec.isDedicatedMode = KAL_FALSE;
	RawPcmRec.ULChannelNum = 0;
	RawPcmRec.inSampleRateIdx = PCM_REC_SAMPLE_RATE_IDX_UNDEF;

	// unlock sleep
	L1Audio_ClearFlag( RawPcmRec.audId );
	L1Audio_FreeAudioID( RawPcmRec.audId );

}

