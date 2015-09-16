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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   snd_effect.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Streaming Background Sound Playback.
 *   Play 8kHz mono linear PCM in TCH or idle mode.
 *
 * Author:
 * -------
 * -------
 *============================================================================
 *             HISTORY
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_public_api.h"
#include "kal_general_types.h"

#include "kal_trace.h"
#include "l1sp_trc.h"


#include "am.h"
//#include "speech_def.h"
#include "afe_def.h" // for output device setting
#include "sp_drv.h"

#include "sal_exp.h"

#if !(defined(MT6280) || defined(MT6589))
#define DSP_BGS_UP_DOWN_INT_SEPERATE
#endif

/************************** Constants ***************************************/
// #define DP_BUFFER_DEFAULT_LEN       4096   /* The frame size of DSP. */ 
#define DSP_BUFFER_LEN_NB              160 //unit is sample (16bit)
#define DSP_BUFFER_LEN_WB              320 //unit is sample (16bit)
#define DSP_BUFFER_LEN_MAX					320 //unit is sample (16bit)

/* DSP Sound Effect State */
#define DP_BGSND_STATE_IDLE           0     /* MCU: 0 -> 1 */
#define DP_BGSND_STATE_READY          1     /* DSP: 1 -> 2 */
#define DP_BGSND_STATE_PLAYING        2     /* MCU: 2 -> 3 */
#define DP_BGSND_STATE_STOP           3     /* DSP: 3 -> 0 */

//#define SND_CHECK_DATA

#define SND_GAIN_CONFIG   1 /* 0: right shamt, 1: multiplier */

#define BGSND_BUF_SIZE 2560 // using in 16 bit 
#define BGSND_BUF_PTR_DIFF 2

typedef enum {
	BGSND_STATE_IDLE = 0,
	BGSND_STATE_RUN, 
	BGSND_STATE_STOP,
	BGSND_STATE_CLOSE,
}BGSND_STATE_TYPE;

/*********** Structure *******************************************************/

typedef struct{

	BGSND_STATE_TYPE state;
	
	kal_bool fULSPH;
	kal_bool fDLSPH;
	
	kal_bool isDlHisrCome;
	kal_bool isUlHisrCome;
	
	void (*bgSnd_hisrHandler)(void);
	void (*bgSnd_offHandler)(void);	
	
	kal_uint16 aud_id;
	kal_timerid timer;
	kal_uint16 endCount;
	
	kal_uint16 ULGain;
	kal_uint16 DLGain;
	kal_uint16 dspLastSample;
	
	kal_uint16 *pBuf;

	
	kal_int32 bufSize; // unit is 16 bit (sample)
	kal_int32 bufWrite; // unit is 16 bit
	kal_int32 bufRead; // unit is 16 bit
}BGSND_T; 

/*********** variable ********************************************************/

static BGSND_T bgSnd;

static kal_uint16 bgSndBuf[BGSND_BUF_SIZE];

/*********** internal fucntion  **********************************************/

static void bgsndUpdateMixer()
{
   if ( AM_IsSpeechOn() ) {
   	SAL_Bgsnd_Config(bgSnd.ULGain, bgSnd.DLGain, bgSnd.fULSPH, bgSnd.fDLSPH);
   } else {
	   SAL_Bgsnd_Config(bgSnd.ULGain, bgSnd.DLGain, 0, 0);
   }

}

/**
	@return: size is 16-bit, available PCM size
*/
static int32 bgsndGetDataCount(void)
{
	int32 count; 
   // int32 count = (int32)ihdl->mh.rbInfo.write - (int32)ihdl->mh.rbInfo.read;
	if(bgSnd.bufWrite<bgSnd.bufRead){
		count = (bgSnd.bufSize - BGSND_BUF_PTR_DIFF)+bgSnd.bufWrite - bgSnd.bufRead;
	} else {
		count = bgSnd.bufWrite - bgSnd.bufRead;
	}

	if( count > BGSND_BUF_PTR_DIFF) {
		count -= BGSND_BUF_PTR_DIFF;
	} else {
		count = 0;
	}

	if(count&1){
		count = count -1;
	}
	return count;
	/*
   int32 count = bgSnd.bufWrite - bgSnd.bufRead;
   if( count < 0 )
      count += (bgSnd.bufSize - BGSND_BUF_PTR_DIFF );
	else if( count > 2)
		count -= BGSND_BUF_PTR_DIFF;
	else 
		count = 0;
   return count;
   	*/
}
/*
static kal_int16 tone1k_16kSR[320] = {
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05,
0x0000, 0x30FC, 0x5A82, 0x7641, 0x7FFF, 0x7641, 0x5A82, 0x30FB, 
0x0001, 0xCF05, 0xA57E, 0x89C0, 0x8001, 0x89BF, 0xA57E, 0xCF05
};

*/
static void bgsnd_WriteToDSP(void)
{
   uint16 dsp_buf_len, dsp_buf_len_Ul;
   uint16 *dataPtr;
	volatile uint16 *toPtr;
	volatile uint16 *toPtr_Ul;
   int32 count, segment, i;
	bool isWb, isWb_Ul;

/*
	¡VSph_Band_Flag 
	¡EBit 0: Sch band (0/1 : Nb/Wb) 
	¡EBit 1: Cod band (0/1 : Nb/Wb) 
	¡EBit 2: VBI band (0/1 : Nb/Wb) 
	¡EBit 3: BT band (0/1 : Nb/Wb) 
	MT6280 0x2FBF
	MT6589 0x32F1
	dm5
*/

	// get current buffer data length in two sample alight. (16k sampling rate)
	count = bgsndGetDataCount();
	
	//set up the DSP address and pointers
   dsp_buf_len = SAL_Bgsnd_GetDataLen_DL();
#ifdef DSP_BGS_UP_DOWN_INT_SEPERATE
	dsp_buf_len_Ul = SAL_Bgsnd_GetDataLen_UL();
#else
	dsp_buf_len_Ul = dsp_buf_len;
#endif
	
	if(dsp_buf_len == DSP_BUFFER_LEN_WB)
		isWb = true;
	else if(dsp_buf_len == DSP_BUFFER_LEN_NB){
		isWb = false;
//		count >>= 1;
	}
	else {
		ASSERT_REBOOT(0);
		isWb = false; 
	}

	if(dsp_buf_len_Ul == DSP_BUFFER_LEN_WB)
		isWb_Ul= true;
	else if(dsp_buf_len_Ul == DSP_BUFFER_LEN_NB){
		isWb_Ul= false;
	}
	else {
		ASSERT_REBOOT(0);	
		isWb_Ul = false;
	}
		
	toPtr = SAL_Bgsnd_GetBuf_DL();
#ifdef DSP_BGS_UP_DOWN_INT_SEPERATE
	toPtr_Ul = SAL_Bgsnd_GetBuf_UL();
#else
	toPtr_Ul = toPtr; 
#endif

	kal_dev_trace(TRACE_INFO, L1SND_DSP_BUFFER_INFO, count, toPtr, dsp_buf_len);
#ifdef DSP_BGS_UP_DOWN_INT_SEPERATE
	kal_dev_trace(TRACE_INFO, L1SND_DSP_BUFFER_INFO, -1, toPtr_Ul, dsp_buf_len_Ul);
#else
	kal_dev_trace(TRACE_INFO, L1SND_DSP_BUFFER_INFO, count, toPtr_Ul, dsp_buf_len_Ul);
#endif


   if (count > DSP_BUFFER_LEN_MAX)
      count = DSP_BUFFER_LEN_MAX;

	if(count > 0) {

	   /* First Segemnt */
		if(bgSnd.bufWrite < bgSnd.bufRead) {
		   segment = (bgSnd.bufSize - bgSnd.bufRead);
		} else {
			segment = (bgSnd.bufWrite - bgSnd.bufRead);
		}

		if(segment&1){ // keep two sample alight
			segment =segment - 1;
		}

		/*
		if(isNb){ // 8k			
			if (segment > (count<<1))
				segment = (count<<1);
			
		}else { // 16 k
			if (segment > count)
				segment = count;
		}
		*/
		if (segment > count)
			segment = count;
			   
	   if (segment > 0) {
			
			// kal_dev_trace(TRACE_STATE, L1SND_FILLBUFFER, segment);
	      dataPtr = &(bgSnd.pBuf[bgSnd.bufRead]);
	   
	      for (i=segment; i>0; (i-=2)) {
				// first sample
	         *toPtr++ = *dataPtr;
				*toPtr_Ul++ = *dataPtr++;

				// second sample
				if(isWb) {
					*toPtr++ = *dataPtr;
				}
				if(isWb_Ul) {
					*toPtr_Ul++ = *dataPtr;
				}
				dataPtr++;
	      }
			
	      bgSnd.dspLastSample = *(toPtr-1);

	      bgSnd.bufRead += segment;
	      if (bgSnd.bufRead >= bgSnd.bufSize)
	         bgSnd.bufRead = (bgSnd.bufRead-bgSnd.bufSize);

			kal_dev_trace(TRACE_STATE, L1SND_FILLBUFFER, 1, segment, bgSnd.bufRead, bgSnd.bufWrite);
	   }

	   /* Second Segment */
		/*
		if(isNb){ // 8k	
			segment = (count<<1) - segment;
		} else {
		   segment = count - segment;
		}
		*/
		segment = count - segment;

	   if (segment > 0) {
	      // kal_dev_trace(TRACE_STATE, L1SND_FILLBUFFER, segment);
	      // dataPtr = bgSnd.pBuf;
	      dataPtr = &(bgSnd.pBuf[bgSnd.bufRead]);
	      for (i=segment; i>0; (i-=2)) {
	         // first sample
	         *toPtr++ = *dataPtr;
				*toPtr_Ul++ = *dataPtr++;
				
				// second sample
				if(isWb) {
					*toPtr++ = *dataPtr;
				}
				if(isWb_Ul) {
					*toPtr_Ul++ = *dataPtr;
				}
				dataPtr++;
	      }
	      bgSnd.dspLastSample = *(toPtr-1);
	      bgSnd.bufRead += segment;
	      if (bgSnd.bufRead >= bgSnd.bufSize)
	         bgSnd.bufRead = (bgSnd.bufRead-bgSnd.bufSize);

			kal_dev_trace(TRACE_STATE, L1SND_FILLBUFFER, 2, segment, bgSnd.bufRead, bgSnd.bufWrite);	
	   }
		
	}


   /* Put silence (last sample) if MCU buffer is empty */
   if (count < DSP_BUFFER_LEN_MAX) {
		
      kal_uint16 last_sample;
      
      last_sample = bgSnd.dspLastSample;      
      // segment = dsp_buf_len - count;
      segment = DSP_BUFFER_LEN_MAX - count;
		kal_dev_trace(TRACE_STATE, L1SND_PUT_SILENCE, segment, last_sample);

		/*
      for (i=segment; i>0; i--) {
         *toPtr++ = last_sample;
      } 
		*/
      for (i=segment; i>0; (i-=2)) {
         // first sample
         *toPtr++ = last_sample;
			*toPtr_Ul++ = last_sample;
			
			// second sample
			if(isWb) {
				*toPtr++ = last_sample;
			}
			if(isWb_Ul) {
				*toPtr_Ul++ = last_sample;
			}

      }
   }
}


void bgsndHisr( void *pram )
{

	// gain and setting update
   bgsndUpdateMixer();

	// handle extra notify and closing state
	if ((BGSND_STATE_RUN != bgSnd.state) && (BGSND_STATE_STOP !=bgSnd.state))
		return;
   // if ( ihdl->end_status != MEDIA_NONE )
   //   return;

   if(!SAL_Bgsnd_IsRunning())
      return;

   bgsnd_WriteToDSP();

	if( bgSnd.bgSnd_hisrHandler != NULL) {
		bgSnd.bgSnd_hisrHandler();
	}
}

#ifdef DSP_BGS_UP_DOWN_INT_SEPERATE
void bgsndDlHisr( void * param)
{
	if(true == bgSnd.isDlHisrCome) { 
		kal_dev_trace( TRACE_GROUP_SND, L1SND_REENTER_HISR, bgSnd.isDlHisrCome, bgSnd.isUlHisrCome);		
	} else {
		bgSnd.isDlHisrCome = true;
		
		if(bgSnd.isUlHisrCome == bgSnd.isDlHisrCome) {
			bgsndHisr(param);
			bgSnd.isUlHisrCome = false;
			bgSnd.isDlHisrCome = false;
		} 
	}
}

void bgsndUlHisr( void * param)
{
	if(true == bgSnd.isUlHisrCome) { 
		kal_dev_trace( TRACE_GROUP_SND, L1SND_REENTER_HISR, bgSnd.isDlHisrCome, bgSnd.isUlHisrCome);
	} else {
		bgSnd.isUlHisrCome = true;
		
		if(bgSnd.isUlHisrCome == bgSnd.isDlHisrCome) {
			bgsndHisr(param);
			bgSnd.isUlHisrCome = false;
			bgSnd.isDlHisrCome = false;
		} 
	}

}

#endif // DSP_BGS_UP_DOWN_INT_SEPERATE

void bgsndOnHandler(void)
{
		
	AM_SND_PlaybackOn();
	SAL_Bgsnd_SetInit();
	//*DSP_SOUND_EFFECT_CTRL = DP_BGSND_STATE_READY;
	{
		uint32 I;
		for( I = 0; ; I++ ) {
			//if( *DSP_SOUND_EFFECT_CTRL == DP_BGSND_STATE_PLAYING)
			if(SAL_Bgsnd_IsRunning())
				break;
			ASSERT_REBOOT( I < 20 );
			kal_sleep_task( 2 );
		}
	}
}

void bgsndOffHandler(void)
{

	if(BGSND_STATE_STOP != bgSnd.state) {
		return;
	}
	
	uint32 I;
	if(SAL_Bgsnd_IsRunning())
		SAL_Bgsnd_SetFinal();
	for ( I = 0; ; I++ ) {
		if ( SAL_Bgsnd_IsIdle())	 /* DSP returns to idle state */
			break;
		ASSERT_REBOOT( I < 20 );
		kal_sleep_task( 2 );
	}

	
	AM_SND_PlaybackOff( true );
}

void bgsndTimerCallback(void)
{
	L1Audio_SetEvent(bgSnd.aud_id, NULL);
}

/**
	Run on AUDIO task
*/
void bgsndEventHandler(void)
{
	kal_trace(TRACE_STATE, L1SND_ENTER_EVENT_HANDLER, bgSnd.state);
	
	switch (bgSnd.state)
	{
		case BGSND_STATE_STOP: 
		{
			// int32 I = 0;
			// Flush and  Disable DSP. 
			//while( I++ >= 0 ){
			while(bgSnd.endCount++ >=0){
				int32 count = bgsndGetDataCount();

				// if( I >=40 ){
				if(bgSnd.endCount >=20) {
					kal_trace(TRACE_STATE, L1SND_STOP_FLUSH_LEAVE, count);
					break;
				}
				
				if( count > BGSND_BUF_PTR_DIFF ){
					kal_trace(TRACE_STATE, L1SND_STOP_FLUSH_COUNT, count);
					// kal_sleep_task(1);
					kal_set_timer(bgSnd.timer, (kal_timer_func_ptr)(bgsndTimerCallback), NULL, 2, 0);
					return;
				}
				
			}
			//if ( *DSP_SOUND_EFFECT_CTRL == DP_BGSND_STATE_PLAYING ) {
			//	*DSP_SOUND_EFFECT_CTRL = DP_BGSND_STATE_STOP;		 /* give ABORT command to the DSP */
			//}
			kal_cancel_timer(bgSnd.timer);
			bgsndOffHandler();

			if(NULL != bgSnd.bgSnd_offHandler){
				bgSnd.bgSnd_offHandler();
			}
		}
			break;
		default: 
			break;
	}

	
}
/*===========================================================================*/


/**
	@srcBuf:
	@bufLen: unit is byte
*/
void BGSND_WriteData(kal_uint8 *srcBuf, kal_int32 bufLen)
{
	int32 freeLen; 
	int32 srcBufLen = bufLen >> 1; // unit i s word
	int32 currentRead = bgSnd.bufRead; 
	
	if(currentRead > bgSnd.bufWrite || currentRead < BGSND_BUF_PTR_DIFF) {	// one segment
		if(currentRead > bgSnd.bufWrite){
			freeLen=currentRead - bgSnd.bufWrite-BGSND_BUF_PTR_DIFF;
		}else {
			freeLen=bgSnd.bufSize - bgSnd.bufWrite-BGSND_BUF_PTR_DIFF;
		}

		kal_trace( TRACE_FUNC, L1SND_WRITE_DATA, 1, srcBufLen, freeLen, bgSnd.bufRead, bgSnd.bufWrite+srcBufLen ); // using write information which is after memory copy
		
		ASSERT(srcBufLen <= freeLen); // unit is 2 byte
		memcpy(bgSnd.pBuf+bgSnd.bufWrite, srcBuf, srcBufLen*sizeof(uint16));		
	
		bgSnd.bufWrite += srcBufLen;

		//kal_prompt_trace(MOD_L1SP, "[pDebug]BGSND_WriteData1, bgSnd.bufRead=%d, bgSnd.bufWrite=%d", bgSnd.bufRead, bgSnd.bufWrite);
	

	} else { // two segment
		
		int32 segment; 
		kal_uint8 *p2SrcBuf;

		freeLen= currentRead + bgSnd.bufSize - bgSnd.bufWrite-BGSND_BUF_PTR_DIFF;

		kal_trace( TRACE_FUNC, L1SND_WRITE_DATA, 2, srcBufLen, freeLen, 0, 0 ); 
		ASSERT(srcBufLen <= freeLen);

		p2SrcBuf = srcBuf;
		segment = bgSnd.bufSize - bgSnd.bufWrite; // bug
		if(segment > srcBufLen){
			segment = srcBufLen;
		}

		if(segment>0) { //first segment

			// kal_prompt_trace(MOD_L1SP, "xbgs temp3: bgSnd.pBuf+bgSnd.bufWrite=%x, p2SrcBuf=%x, segment*sizeof(kal_uint16)=%x", 
			// 	bgSnd.pBuf+bgSnd.bufWrite, p2SrcBuf, segment*sizeof(kal_uint16));
		
			memcpy(bgSnd.pBuf+bgSnd.bufWrite, p2SrcBuf, segment*sizeof(kal_uint16));		
			
			//update pointer
			p2SrcBuf = srcBuf + segment*sizeof(kal_uint16); 
			bgSnd.bufWrite += segment;
			if(bgSnd.bufWrite>=bgSnd.bufSize){				
				bgSnd.bufWrite = 0; 
			}

			// kal_prompt_trace(MOD_L1SP, "[pDebug]BGSND_WriteData2-1, bgSnd.bufRead=%d, bgSnd.bufWrite=%d", bgSnd.bufRead, bgSnd.bufWrite);
			kal_trace( TRACE_FUNC, L1SND_WRITE_DATA, 3, 0, 0, bgSnd.bufRead, bgSnd.bufWrite);
	
			segment = srcBufLen - segment; 
		}

		if(segment>0) { //second segement
			// kal_prompt_trace(MOD_L1SP, "xbgs temp5: bgSnd.pBuf=%x, p2SrcBuf=%x, segment*sizeof(kal_uint16=%x)", 
			// 	bgSnd.pBuf, p2SrcBuf, segment*sizeof(kal_uint16));
		
			memcpy(bgSnd.pBuf, p2SrcBuf, segment*sizeof(kal_uint16));	
			bgSnd.bufWrite = segment;

			// kal_prompt_trace(MOD_L1SP, "[pDebug]BGSND_WriteData2-2, bgSnd.bufRead=%d, bgSnd.bufWrite=%d", bgSnd.bufRead, bgSnd.bufWrite);
			kal_trace( TRACE_FUNC, L1SND_WRITE_DATA, 4, 0, 0, bgSnd.bufRead, bgSnd.bufWrite);
	
		}
	}

	/*
	freeLen=bgSnd.bufRead - bgSnd.bufWrite-1;
	if(freeLen<0){ // two segment
		int32 segment; 
		kal_uint8 *p2SrcBuf;
		
		freeLen += bgSnd.bufSize;
		
		
				p2SrcBuf = srcBuf;
				segment = bgSnd.bufSize - bgSnd.bufWrite; 
				memcpy(bgSnd.pBuf+bgSnd.bufWrite, p2SrcBuf, segment*sizeof(kal_uint16));		
				//update pointer
				p2SrcBuf = srcBuf + (segment<<1); 
				bgSnd.bufWrite = 0; 
		
				
				segment = srcBufLen - segment; 
				memcpy(bgSnd.pBuf+bgSnd.bufWrite, p2SrcBuf, segment*sizeof(kal_uint16));	
				bgSnd.bufWrite = segment;
				
			} else { // one segment
				ASSERT(bufLen <= freeLen); 
				memcpy(bgSnd.pBuf+bgSnd.bufWrite, srcBuf, bufLen); 	
		
				// for debug
				kal_prompt_trace(MOD_L1SP, "bgs temp: bgSnd.pBuf=%x, bgSnd.bufWrite=%x,  bgSnd.pBuf+bgSnd.bufWrite = %x", 
					bgSnd.pBuf, bgSnd.bufWrite, bgSnd.pBuf+bgSnd.bufWrite);
				
				bgSnd.bufWrite += (bufLen>>1);
		
				// for debg
				kal_prompt_trace(MOD_L1SP, "bgs temp2: new bgSnd.bufWrite = %x", bgSnd.bufWrite);
		
			}
			*/
		
}

/**
	@return: size is 16-bit (2byte)
*/
int32 BGSND_GetFreeSpace(void)
{
	int32 count;

	count = bgSnd.bufSize + bgSnd.bufRead - bgSnd.bufWrite-BGSND_BUF_PTR_DIFF; // (int32)ihdl->mh.rbInfo.read - (int32)ihdl->mh.rbInfo.write - 1;
	if( count > bgSnd.bufSize )
	  count = count - bgSnd.bufSize;
	return count;
}

/**
	The function sets the playback mode.
	
	@bULSPHFlag: Mixer switch for uplink speech, 1 for SPH+background Sound, 0 for background sound only
	@ULSNDGain: Sound effect gain for uplink mixer
*/
void BGSND_ConfigULMixer(kal_bool bULSPHFlag, kal_int8 ULSNDGain )
{
#if defined(__ENABLE_SPEECH_DVT__)
    ULSNDGain = 7;
#endif // defined(__ENABLE_SPEECH_DVT__)
	kal_trace( TRACE_FUNC, L1SND_CONFIG_ULMIXER, bULSPHFlag, ULSNDGain ); 

	ASSERT(ULSNDGain>=0 && ULSNDGain<=7);
	if( ULSNDGain == 0 )
		bgSnd.ULGain = 0;
	else {
		bgSnd.ULGain = (kal_int16)(32767 >> (7 - ULSNDGain));
	}
	bgSnd.fULSPH = bULSPHFlag;
}


/**
	The function sets the playback mode.
	
	@bDLSPHFlag: Mixer switch for downlink speech, 1 for SPH+background Sound, 0 for background sound only
	@DLSNDGain: Sound effect gain for downlink mixer
*/
void BGSND_ConfigDLMixer(kal_bool bDLSPHFlag, kal_int8 DLSNDGain )
{
#if defined(__ENABLE_SPEECH_DVT__)
    DLSNDGain = 7;
#endif // defined(__ENABLE_SPEECH_DVT__)
	kal_trace( TRACE_FUNC, L1SND_CONFIG_DLMIXER, bDLSPHFlag, DLSNDGain ); 

	ASSERT(DLSNDGain>=0 && DLSNDGain<=7);
	if( DLSNDGain == 0)
		bgSnd.DLGain = 0;
	else {
		bgSnd.DLGain = (kal_int16)(32767 >> (7 - DLSNDGain));
	}
	bgSnd.fDLSPH = bDLSPHFlag;
}

/**

 The function starts the background sound playback of the media handle.

 @bgSnd_hdlr: handler
 @ULGainLevel: uplink gain level, from 0~7
 @DLGainLevel: downlink gain level, from 0~7

*/
void BGSND_Start(void (*bgSnd_hisrHandler)(void), void (*bgSnd_offHandler)(void),
	kal_uint8 ULGainLevel , kal_uint8 DLGainLevel)
{
	kal_trace( TRACE_FUNC, L1SND_ENTER_BGSND_START ); 
	
	// clean up 
	bgSnd.dspLastSample = 0;
	bgSnd.endCount = 0;
	
	// buffer reset
	memset(bgSndBuf, 0, sizeof(kal_uint16)*BGSND_BUF_SIZE);
	bgSnd.pBuf = bgSndBuf;
	bgSnd.bufSize = BGSND_BUF_SIZE;
	bgSnd.bufRead = 0;
	bgSnd.bufWrite = BGSND_BUF_PTR_DIFF;

	// clear hisr flag
	bgSnd.isDlHisrCome = false;
	bgSnd.isUlHisrCome = false;
	
	// lock DSP for sherif writing.	
	L1Audio_SetFlag( bgSnd.aud_id ); // REIMIND: Before Locking SleepMode, to access DSP sherrif tasks much time. So access DSP must be after SetFlag1
	
	// L1Audio_SetEventHandler(bgSnd.aud_id, BGSND_eventHandler );
	bgSnd.bgSnd_hisrHandler = bgSnd_hisrHandler;
#ifdef DSP_BGS_UP_DOWN_INT_SEPERATE
	L1Audio_HookHisrHandler(D2C_SOUND_EFFECT_INT_ID_DL, bgsndDlHisr, 0);  
	L1Audio_HookHisrHandler(D2C_SOUND_EFFECT_INT_ID_UL, bgsndUlHisr, 0);  
#else
	L1Audio_HookHisrHandler(D2C_SOUND_EFFECT_INT_ID_DL, bgsndHisr, 0);  	
#endif

	bgSnd.bgSnd_offHandler = bgSnd_offHandler;

	// gain setting and update
	if(AM_IsSpeechOn()){
		BGSND_ConfigULMixer(KAL_TRUE, ULGainLevel);
		BGSND_ConfigDLMixer(KAL_TRUE, DLGainLevel);
	} else {
		BGSND_ConfigULMixer(KAL_FALSE, ULGainLevel);
		BGSND_ConfigDLMixer(KAL_FALSE, DLGainLevel);
	}
	bgsndUpdateMixer();
	 

	// Before dynamic download, all application should be off. 
	// But background sound do not need to dynamic download, so the following is unnecessary.
	// KT_StopAndWait();

	// turn on.
	bgsndOnHandler();

	// L1SP_Register_BgsService(bgsndOnHandler, bgsndOffHandler);
	bgSnd.state = BGSND_STATE_RUN;
}

/*
 * Description
 * ---------
 *   The function stops the background sound playback of the media handle.
 *
 * Syntax
 * ---------
 *   void BGSND_Stop();
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   None
 */
void BGSND_Stop(void)
{



	kal_trace( TRACE_FUNC, L1SND_ENTER_BGSND_STOP ); 

	/*	
	if ( !L1Audio_CheckFlag( bgSnd.aud_id ) )
		return;
	*/

	// unregister service
	// L1SP_UnRegister_BgsService();

	bgSnd.state = BGSND_STATE_STOP;

	// set event to trigger close process
	L1Audio_SetEvent(bgSnd.aud_id, NULL);
}

void BGSND_Close(void)
{
	
	L1Audio_ClearFlag( bgSnd.aud_id );

#ifdef DSP_BGS_UP_DOWN_INT_SEPERATE
	L1Audio_UnhookHisrHandler(D2C_SOUND_EFFECT_INT_ID_DL);  
	L1Audio_UnhookHisrHandler(D2C_SOUND_EFFECT_INT_ID_UL);  
#else
	L1Audio_UnhookHisrHandler(D2C_SOUND_EFFECT_INT_ID_DL);
#endif 

	// reset the pointer
	bgSnd.pBuf = NULL;
	bgSnd.bufSize = 0;
	bgSnd.bgSnd_hisrHandler = NULL;	


	bgSnd.state = BGSND_STATE_IDLE;
}


/* 
 * Description
 * ---------
 *   The function sets the output device.
 *
 * Syntax
 * ---------
 *   void BGSND_SetOutputDevice( kal_uint8 device );
 *
 * where
 *   device   The output device (L1SP_SPEAKER1, L1SP_SPEAKER2, L1SP_LOUD_SPEAKER)
 *
 * Return Value
 * ---------
 *   None
 
void BGSND_SetOutputDevice( kal_uint8 device )
{
	//if( !AM_IsSpeechOn() )
#ifdef ANALOG_AFE_PATH_EXIST   	
		AFE_SetOutputDevice( L1SP_SND_EFFECT, device );
#endif
}
*/


void BGSND_INIT()
{	
	memset(&bgSnd, 0, sizeof(BGSND_T));
	
	// get audio ID
	bgSnd.aud_id = L1Audio_GetAudioID(); 
	L1Audio_SetEventHandler( bgSnd.aud_id, (L1Audio_EventHandler)bgsndEventHandler );
	bgSnd.timer = kal_create_timer("bgSnd"); 
}
		
