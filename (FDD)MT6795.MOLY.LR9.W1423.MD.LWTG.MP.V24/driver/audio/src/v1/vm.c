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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * vm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   VM recording/playback
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
// #if defined(__VM_CODEC_SUPPORT__)

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "string.h"
#include "reg_base.h"
#include "kal_trace.h"

#include "speech_def.h"
#include "common_def.h"
#include "l1audio.h"
#include "l1audio_trace.h"
#include "am.h"
#include "media.h"
#include "afe.h"
#include "l1sp_trc.h"
#include "l1audio_sph_trc.h"
#include "sal_exp.h"
#include "sal_def.h"
#include "vm.h"

#define VM_LOG_DEBUG
//#define VM_VR_RERECORD

#define VM_CTRL_UL         1
#define VM_CTRL_DL         1

#define VM_CTRL_SC_START   3
#define VM_CTRL_SD_START   6

#define VM_STATE_RECORD       0x1
#define VM_STATE_RECORD_PAUSE 0x2
#define VM_STATE_PLAY         0x4
#define VM_STATE_PLAY_PAUSE   0x8
#define VM_STATE_STOP         0x10 
#define VM_STATE_RECORD_STOP  0x20 // entering vmStop

#define VM_BASIC_VM_DATA_SIZE    37 //SyncWord(1), header(1), vm.control(1), counter(1), counter(1), 16*2
#define VM_2G_CTRL_DL_DEBUG_SIZE 44

#define VM_4WAYPCM_DEBUG_SIZE    642 //320 + 320 + 2
#define VM_REFMICPCM_DEBUG_SIZE  324 //160 + 160 + 2 + 2

#define VM_3G_DSP_DEBUG_SIZE     22 //DSP 15 + L1_info 2 + crc_result|DCH_On/Off 1 + s_value 1 + tpc_SIR_lta 1 + dpdch_SIR_lta 1 + TFCI_max_corr 1
#define VM_3G_MCU_DEBUG_SIZE     37 //buffer status 1 + UL 17 + DL 19
#define VM_3G_DEBUG_SIZE         ( VM_3G_DSP_DEBUG_SIZE + VM_3G_MCU_DEBUG_SIZE )
#define VM_3G324M_DSP_DEBUG_SIZE 22 //DSP 15 + L1_info 2 + crc_result|DCH_On/Off 1 + s_value 1 + tpc_SIR_lta 1 + dpdch_SIR_lta 1 + TFCI_max_corr 1
#define VM_3G324M_MCU_DEBUG_SIZE 37 //buffer status 1 + UL 17 + DL 19
#define VM_3G324M_DEBUG_SIZE     ( VM_3G324M_DSP_DEBUG_SIZE + VM_3G324M_MCU_DEBUG_SIZE )
#define VM_MAXIMUM_SAVE_SIZE     91 //VM_3G_MCU_DEBUG_SIZE + VM_BASIC_VM_DATA_SIZE

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
#define FIVE_PCM_SAVE_SIZE            ((VM_4WAYPCM_DEBUG_SIZE*2) + VM_REFMICPCM_DEBUG_SIZE)
#endif

#define FOUR_PCM_SAVE_SIZE            (VM_4WAYPCM_DEBUG_SIZE*2)


// VM_MAGIC_HEADER(1), header(2), vm_lost & pcm_Lost(1),vm_counter(1), PCM (2*2*160)
#define VM_BUFFER_SIZE           (513 + 2000)//#### the expected number of frame within 40ms UL,and that within 40ms DL


//#if defined(__UMTS_TDD128_MODE__)
//#define VM_MAGIC_HEADER 0xAA77

//#else
#define VM_MAGIC_HEADER 0xAA88
//#endif


/* ------------------------------------------------------------------------------ */
static struct{
   // mediaControl   *ctrl;   // Use for media, phase out. 
   uint16          type;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   uint16         control_1;//new vm format from MT6280
   uint16         control_2;//new vm format from MT6280
   // uint32         rb_data_len;  /* actual data size (in word) in ring buffer */ //playback used, phase out
   int16          *vmBuf;    /* point to buffer for VM                              */   
   int16          *pcmBuf;   /* point to buffer for 1st set UL-DL PCM data         */   
   uint16         debug_info; /* 0  : vm (speech codec data) only                   */
                              /* b1 : record 1st set of UL-DL PCM buffer for SPE    */
                              /* b2 : record 2nd set of UL-DL PCM buffer for SPE    */ 
   uint8          state; // record DSP  runnning status (including 2 hisr)
   uint8          vm_lost; 
   uint8          vm_lost_count;
   uint8          pcm_lost_count;                                                                  
   uint8          sc_mode;
   uint8          sd_mode;
   uint32         pcm_save_size;

	
	void (*vm_hdlr)(void); // callback function for vm logging
	bool isVocOn; // only use under call AM_IsSpeechOn()
	bool isVmLOn; // only use under call AM_IsSpeechOn()
	bool isIdleVmOn; // idle VM record, exclusive with "isVocOn and isVmLOn"

	// related to 'vmRecOutputBuf', which is cycular buffer use to buffer formatted vm data from dsp
	uint16 pOutputBufWrite; 
	uint16 pOutputBufRead;
	uint16 outputBufSize;

	uint16 audId;
} vm;

#if defined( VM_LOG_DEBUG )
uint8   vm_counter;
#endif

#define VM_PCM_1ST_SET_RECORD_FLAG  0x1 
#define VM_PCM_2ND_SET_RECORD_FLAG  0x2
#define VM_VM_RECORD_FLAG           0x4
#define VM_PCM_REFMIC_RECORD_FLAG   0x8
#define VM_PCM_BAND_FLAG_UL_PRE		0x0010
#define VM_PCM_BAND_FLAG_UL_POS		0x0020
#define VM_PCM_BAND_FLAG_DL_PRE		0x0040
#define VM_PCM_BAND_FLAG_DL_POS		0x0080
#define VM_PCM_BAND_FLAG_UL2_POS	0x0100

#define TCH_VM_INT_FLAG             0x1 
#define TCH_PCM_INT_FLAG            0x2 

#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
#define G_CODEC_UL_INFO_HEADER_MAGIC_NUMBER (0x6666)
#define G_CODEC_DL_INFO_HEADER_MAGIC_NUMBER (0x6667)
//G.722 bitstream 20ms 160byte
//G.711 bitstream 10ms  80byte
//store max 4frame
#define G_CODEC_MAX_FRAME_NUMBER (4)
//stream_size+stream
#define G_CODEC_BITSTREAM_BUFFER_BYTE_SIZE (1*2+80)
//lost_info + system_time + codec + codec_parameters
#define G_CODEC_UL_INFO_BYTE_SIZE (4*2)
//lost_info + system_time + codec + codec_parameters + DL_PCM_buffer_size
#define G_CODEC_DL_INFO_BYTE_SIZE (5*2)
//header_magic_number+info_size+info_struct
#define G_CODEC_UL_INFO_TOTAL_BYTE_SIZE (2*2+G_CODEC_UL_INFO_BYTE_SIZE)
//header_magic_number+info_size+info_struct
#define G_CODEC_DL_INFO_TOTAL_BYTE_SIZE (2*2+G_CODEC_DL_INFO_BYTE_SIZE)
//total byte size
#define G_CODEC_UL_BITSTREAM_TOTAL_BYTE_SIZE ((G_CODEC_UL_INFO_TOTAL_BYTE_SIZE+G_CODEC_BITSTREAM_BUFFER_BYTE_SIZE)*G_CODEC_MAX_FRAME_NUMBER)
#define G_CODEC_DL_BITSTREAM_TOTAL_BYTE_SIZE ((G_CODEC_DL_INFO_TOTAL_BYTE_SIZE+G_CODEC_BITSTREAM_BUFFER_BYTE_SIZE)*G_CODEC_MAX_FRAME_NUMBER)
#endif //#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)

#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
#define VMREC_OUTPUT_BUF_SIZE (5120+2000+((G_CODEC_UL_BITSTREAM_TOTAL_BYTE_SIZE+1)>>1)+((G_CODEC_DL_BITSTREAM_TOTAL_BYTE_SIZE+1)>>1))	//####
#else //#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
#define VMREC_OUTPUT_BUF_SIZE (5120+2000)	//####
#endif //#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
static kal_uint16 vmRecOutputBuf[VMREC_OUTPUT_BUF_SIZE];
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
static kal_int16 eplInputBuf[FIVE_PCM_SAVE_SIZE];
#else
static kal_int16 eplInputBuf[FOUR_PCM_SAVE_SIZE];
#endif

#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
static kal_uint32 vmGCodecULBitstreamBuf[(G_CODEC_UL_BITSTREAM_TOTAL_BYTE_SIZE+3)/sizeof(kal_uint32)];
static kal_uint32 vmGCodecDLBitstreamBuf[(G_CODEC_DL_BITSTREAM_TOTAL_BYTE_SIZE+3)/sizeof(kal_uint32)];
static kal_uint32 vmGCodecULBufWritePos;
static kal_uint32 vmGCodecDLBufWritePos;
static kal_uint32 vmGCodecULBufLastHeaderPos;
static kal_uint32 vmGCodecDLBufLastHeaderPos;
static kal_uint16 *p16vmGCodecULBitstreamBuf;
static kal_uint16 *p16vmGCodecDLBitstreamBuf;
#endif //#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
#define VM_4G_G_SERIAL_DEBUG

#define VM_3G_NETWORK_INFO_LEN 7
uint16 vm3GNetworkInfo[VM_3G_NETWORK_INFO_LEN];

extern uint32 L1I_GetTimeStamp( void );

/* ------------------------------------------------------------------------------ 
#define  PUT_RECORD_DATA(val)                                  \
   {                                                           \
      if( vm.ctrl->read > vm.ctrl->write ) {                   \
         if( vm.ctrl->read - vm.ctrl->write > 1 )              \
            vm.ctrl->rb_base[vm.ctrl->write++] = (val);        \
      }                                                        \
      else if( vm.ctrl->read == 0 ) {                          \
         if( vm.ctrl->rb_size - vm.ctrl->write > 1 )           \
            vm.ctrl->rb_base[vm.ctrl->write++] = (val);        \
      }                                                        \
      else {                                                   \
         vm.ctrl->rb_base[vm.ctrl->write++] = (val);           \
         if( vm.ctrl->write == vm.ctrl->rb_size )              \
            vm.ctrl->write = 0;                                \
      }                                                        \
   }
*/

#define GET_VM_LENGTH(vmctrl_1, vmctrl_2) AM_GetSpeechPatternLength((vmctrl_1>> 1) & 0x3F) \
+ ((vmctrl_2 & 1)?(AM_GetSpeechPatternLength((vmctrl_2 >> 1) & 0x3F)):0) + 7

                                

#if defined( __UMTS_RAT__ )  || defined( __UMTS_TDD128_MODE__ )
#define _EXTRA_LOG_FOR_BIT_TRUE_
#endif

#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
extern kal_bool g_bNeedExtraLog;
#endif

// #pragma arm section code="SECONDARY_ROCODE"


#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
void vmInitGCodecULBuf(void)
{
   //memset(vmGCodecULBitstreamBuf, 0, sizeof(vmGCodecULBitstreamBuf));
   p16vmGCodecULBitstreamBuf = (kal_uint16 *)vmGCodecULBitstreamBuf;
   vmGCodecULBufWritePos = 0;
   vmGCodecULBufLastHeaderPos = 0;
}

void vmInitGCodecDLBuf(void)
{
   //memset(vmGCodecDLBitstreamBuf, 0, sizeof(vmGCodecDLBitstreamBuf));
   p16vmGCodecDLBitstreamBuf = (kal_uint16 *)vmGCodecDLBitstreamBuf;
   vmGCodecDLBufWritePos = 0;
   vmGCodecDLBufLastHeaderPos = 0;
}
/*
uint16 vmGCodecBufferedSize(kal_uint16 *pu16StreamData)
{
   uint16 u16BufferedSize = 0;
   uint16 u16SeekPos = 0;
   uint32 u32ULfinish = 0;

   while(1)
   {
      if(pu16StreamData[u16SeekPos] == G_CODEC_UL_INFO_HEADER_MAGIC_NUMBER)
      {
         if(u32ULfinish != 0)
         {
            break;
         }
      }
      else if(pu16StreamData[u16SeekPos] == G_CODEC_DL_INFO_HEADER_MAGIC_NUMBER)
      {
         u32ULfinish = 1;
      }
      else
      {
         break;
      }

      u16SeekPos++;
      u16SeekPos = u16SeekPos + pu16StreamData[u16SeekPos];
      u16SeekPos++;
      u16SeekPos = u16SeekPos + ((pu16StreamData[u16SeekPos]+1)>>1);
      u16SeekPos++;
      if(u16SeekPos < ((G_CODEC_UL_BITSTREAM_TOTAL_BYTE_SIZE+G_CODEC_DL_BITSTREAM_TOTAL_BYTE_SIZE)>>1))
      {
         u16BufferedSize = u16SeekPos;
      }
      else
      {
         break;
      }
   }

   return(u16BufferedSize);
}
*/
void vmFormatter_gseries(uint16 *vmBuf)
{
   volatile uint16 *addr;
   uint16 I;//, sc_mode, sd_mode, sc_len, sd_len;
   uint32 J;
   Sal_VM_Frame vmfrm_t;
   uint16 *vmBuf_temp;
   //uint32 savedMask;
   /*I = DP_3G_DL_RX_MODE_REPORT >> 8;
   sd_mode = I & 0x1F;
   I = DP_3G_UL_TX_MODE_REPORT >> 8;
   sc_mode = I & 0x1F;*/
   SAL_VM_GetFrame3G(&vmfrm_t);
   //sd_mode = vmfrm_t.dec_mode;
   //sc_mode = vmfrm_t.enc_mode;

   //ASSERT_REBOOT( (sc_len = AM_GetSpeechPatternLength(sc_mode)) > 0 );
   //ASSERT_REBOOT( (sd_len = AM_GetSpeechPatternLength(sd_mode)) > 0 );

   //I = vmfrm_t.enc_hdr;
   //I = I & 0x03;
   //vm.control_1 = I << 7 | (sc_mode << 1) | (vm.control_1 & 1);
   //if(SAL_3G_Mode())
   //   vm.control_1 = vm.control_1 | 0x1000;


   //I = vmfrm_t.dec_hdr;
   //I = I & 0x0e;
   //vm.control_2 = I << 6 | (sd_mode << 1) | (vm.control_2 & 1);

//kal_dev_trace( TRACE_INFO, VM_CONTROL, vm.control );
// record syn_word for VM_LOG_DEBUG 

   *vmBuf++ = VM_MAGIC_HEADER;
   J = L1SP_GetState();
   I = (uint16)( ( (SAL_VM_DBGINFO_LEN + SAL_VM_ENH_DBGINFO_LEN + SAL_VM_DRV_DBGINFO_LEN)<< 3 ) | J);
   *vmBuf++ = I;
   *vmBuf++ = VM_VM_RECORD_FLAG ;           //VM
   J = L1I_GetTimeStamp();
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   if( g_bNeedExtraLog )
        kal_dev_trace( TRACE_INFO, VM_SP3G_VM_L1T, J );
#endif
   I = (uint16)(J & 0xFFFF);
   *vmBuf++ = I;
   I = (uint16)((J >> 16) + ((uint32)vm_counter << 8));
   *vmBuf++ = I;
   vm_counter++;

   // record vm control value  
   #ifdef VM_4G_G_SERIAL_DEBUG
   kal_prompt_trace(MOD_L1SP, "[vmFormatter_gseries] vm.control_1=%x", (vmGCodecULBufWritePos & 0x0FFF) | 0x2000);
   #endif //#ifdef VM_4G_G_SERIAL_DEBUG
   *vmBuf++ = (vmGCodecULBufWritePos & 0x0FFF) | 0x2000;//vm.control_1;
   vmBuf_temp = vmBuf;
   *vmBuf++ = 0;//fake vm.control_2;
   // record UL data   
   //addr = vmfrm_t.enc_hb_addr;
   for( I = 0; I < (vmGCodecULBufWritePos&0x0FFF); I++ )
   {
      *vmBuf++ = p16vmGCodecULBitstreamBuf[I];
   }
   vmInitGCodecULBuf();

   // record vm control value  
   //addr = vmfrm_t.dec_hb_addr;
   *vmBuf_temp = vmGCodecDLBufWritePos & 0x0FFF;//vm.control_2;
   #ifdef VM_4G_G_SERIAL_DEBUG
   kal_prompt_trace(MOD_L1SP, "[vmFormatter_gseries] vm.control_2=%x", *vmBuf_temp);
   #endif //#ifdef VM_4G_G_SERIAL_DEBUG
   // record DL data   
   for( I = 0; I < (vmGCodecDLBufWritePos&0x0FFF); I++ )
      *vmBuf++ = p16vmGCodecDLBitstreamBuf[I];
   vmInitGCodecDLBuf();

   addr = vmfrm_t.dbgInfo_addr;  
   for( I = 0; I < SAL_VM_DBGINFO_LEN; I++ )
      *vmBuf++ = *addr++;

   addr = vmfrm_t.enh_dbgInfo_addr;  
   for( I = 0; I < SAL_VM_ENH_DBGINFO_LEN; I++ )
      *vmBuf++ = *addr++;

   for(I = 0; I < SAL_VM_DRV_DBGINFO_LEN; I++)
   {
      if(I < VM_3G_NETWORK_INFO_LEN)
         *vmBuf++ = vm3GNetworkInfo[I];
      else
         *vmBuf++ = 0;
   }

}


#endif //#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)


void vmStoreGCodecULStream(vmGCodecULInfo *pstvmGCodecULInfo, kal_uint16 u16StreamSize, kal_uint8 *pu8StreamData)
{
#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
   kal_uint32 u32TotalBufferSize = sizeof(vmGCodecULBitstreamBuf) >> 1;
   //bytesize: G_CODEC_UL_INFO_TOTAL_BYTE_SIZE + stream_size + stream_data[]
   //>>1 => 2byte size
   kal_uint32 u32NeedSize = (G_CODEC_UL_INFO_TOTAL_BYTE_SIZE + 2 + u16StreamSize + 1) >> 1;
   kal_uint32 i, j;
   kal_uint16 u16tempData;

   #ifdef VM_4G_G_SERIAL_DEBUG
   kal_prompt_trace(MOD_L1SP, "[vmStoreGCodecULStream] Enter");
   #endif //#ifdef VM_4G_G_SERIAL_DEBUG

   // dsp status check
   if(vm.state != VM_STATE_RECORD)
   {
      return;
   }

   // application status check
   if( (false == vm.isIdleVmOn) && (false == vm.isVocOn) && (false == vm.isVmLOn))
   {
      return;
   }

   #ifdef VM_4G_G_SERIAL_DEBUG
   kal_prompt_trace(MOD_L1SP, "[vmStoreGCodecULStream] u32TotalBufferSize=%d, vmGCodecULBufWritePos=%d, u16Stream2byteSize=%d, u16StreamSize=%d", u32TotalBufferSize, vmGCodecULBufWritePos, ((u16StreamSize+1)>>1), u16StreamSize);
   #endif //#ifdef VM_4G_G_SERIAL_DEBUG

   if( (u32TotalBufferSize-vmGCodecULBufWritePos) >= u32NeedSize )
   {
      vmGCodecULBufLastHeaderPos = vmGCodecULBufWritePos;

      p16vmGCodecULBitstreamBuf[vmGCodecULBufWritePos] = G_CODEC_UL_INFO_HEADER_MAGIC_NUMBER;
      vmGCodecULBufWritePos++;
      p16vmGCodecULBitstreamBuf[vmGCodecULBufWritePos] = G_CODEC_UL_INFO_BYTE_SIZE >> 1;
      vmGCodecULBufWritePos++;
      p16vmGCodecULBitstreamBuf[vmGCodecULBufWritePos] = pstvmGCodecULInfo->drop_info;
      vmGCodecULBufWritePos++;
      p16vmGCodecULBitstreamBuf[vmGCodecULBufWritePos] = (kal_uint16)(ust_get_current_time()/1000);//ust_get_current_time(): unit is micro second (us) => ust_get_current_time()/1000: unit is ms
                                                         //(kal_uint16)L1I_GetTimeStamp();//pstvmGCodecULInfo->system_time;
      vmGCodecULBufWritePos++;
      p16vmGCodecULBitstreamBuf[vmGCodecULBufWritePos] = pstvmGCodecULInfo->codec;
      vmGCodecULBufWritePos++;
      p16vmGCodecULBitstreamBuf[vmGCodecULBufWritePos] = pstvmGCodecULInfo->codec_parameters;
      vmGCodecULBufWritePos++;
      p16vmGCodecULBitstreamBuf[vmGCodecULBufWritePos] = u16StreamSize;
      vmGCodecULBufWritePos++;
      j = 0;
      for(i=0; i<(u16StreamSize>>1); i++)
      {
         u16tempData = pu8StreamData[j];
         j++;
         u16tempData = (u16tempData<<8) | pu8StreamData[j];
         j++;
         p16vmGCodecULBitstreamBuf[vmGCodecULBufWritePos] = u16tempData;
         vmGCodecULBufWritePos++;
      }
      if(u16StreamSize&0x01)
      {
         u16tempData = pu8StreamData[j];
         u16tempData = (u16tempData<<8) | u16tempData;
         p16vmGCodecULBitstreamBuf[vmGCodecULBufWritePos] = u16tempData;
         vmGCodecULBufWritePos++;
      }
   }
   else
   {
      kal_prompt_trace(MOD_L1SP, "[vmStoreGCodecULStream] data 2byte size is large than available buffer 2byte size, data 2byte size=%d, available buffer 2byte size=%d", u32NeedSize, u32TotalBufferSize-vmGCodecULBufWritePos);
      if(vmGCodecULBufWritePos != 0)
      {
         p16vmGCodecULBitstreamBuf[vmGCodecULBufLastHeaderPos+2] += 0x0100;
      }
      else
      {
         kal_prompt_trace(MOD_L1SP, "[vmStoreGCodecULStream] data 2byte size is large than total buffer 2byte size, data 2byte size=%d, total buffer 2byte size=%d", u32NeedSize, u32TotalBufferSize);
      }
   }

   #ifdef VM_4G_G_SERIAL_DEBUG
   kal_prompt_trace(MOD_L1SP, "[vmStoreGCodecULStream] Exit");
   #endif //#ifdef VM_4G_G_SERIAL_DEBUG
#endif //#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
}


void vmStoreGCodecDLStream(vmGCodecDLInfo *pstvmGCodecDLInfo, kal_uint16 u16StreamSize, kal_uint8 *pu8StreamData)
{
#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
   kal_uint32 u32TotalBufferSize = sizeof(vmGCodecDLBitstreamBuf) >> 1;
   //bytesize: G_CODEC_DL_INFO_TOTAL_BYTE_SIZE + stream_size + stream_data[]
   //>>1 => 2byte size
   kal_uint32 u32NeedSize = (G_CODEC_DL_INFO_TOTAL_BYTE_SIZE + 2 + u16StreamSize + 1) >> 1;
   kal_uint32 i, j;
   kal_uint16 u16tempData;

   #ifdef VM_4G_G_SERIAL_DEBUG
   kal_prompt_trace(MOD_L1SP, "[vmStoreGCodecDLStream] Enter");
   #endif //#ifdef VM_4G_G_SERIAL_DEBUG

   // dsp status check
   if(vm.state != VM_STATE_RECORD)
   {
      return;
   }

   // application status check
   if( (false == vm.isIdleVmOn) && (false == vm.isVocOn) && (false == vm.isVmLOn))
   {
      return;
   }

   #ifdef VM_4G_G_SERIAL_DEBUG
   kal_prompt_trace(MOD_L1SP, "[vmStoreGCodecDLStream] u32TotalBufferSize=%d, vmGCodecDLBufWritePos=%d, u16Stream2byteSize=%d, u16StreamSize=%d", u32TotalBufferSize, vmGCodecDLBufWritePos, ((u16StreamSize+1)>>1), u16StreamSize);
   #endif //#ifdef VM_4G_G_SERIAL_DEBUG

   if( (u32TotalBufferSize-vmGCodecDLBufWritePos) >= u32NeedSize )
   {
      vmGCodecDLBufLastHeaderPos = vmGCodecDLBufWritePos;

      p16vmGCodecDLBitstreamBuf[vmGCodecDLBufWritePos] = G_CODEC_DL_INFO_HEADER_MAGIC_NUMBER;
      vmGCodecDLBufWritePos++;
      p16vmGCodecDLBitstreamBuf[vmGCodecDLBufWritePos] = G_CODEC_DL_INFO_BYTE_SIZE >> 1;
      vmGCodecDLBufWritePos++;
      p16vmGCodecDLBitstreamBuf[vmGCodecDLBufWritePos] = pstvmGCodecDLInfo->drop_info;
      vmGCodecDLBufWritePos++;
      p16vmGCodecDLBitstreamBuf[vmGCodecDLBufWritePos] = (kal_uint16)(ust_get_current_time()/1000);//ust_get_current_time(): unit is micro second (us) => ust_get_current_time()/1000: unit is ms
                                                         //(kal_uint16)L1I_GetTimeStamp();//pstvmGCodecDLInfo->system_time;
      vmGCodecDLBufWritePos++;
      p16vmGCodecDLBitstreamBuf[vmGCodecDLBufWritePos] = pstvmGCodecDLInfo->codec;
      vmGCodecDLBufWritePos++;
      p16vmGCodecDLBitstreamBuf[vmGCodecDLBufWritePos] = pstvmGCodecDLInfo->codec_parameters;
      vmGCodecDLBufWritePos++;
      p16vmGCodecDLBitstreamBuf[vmGCodecDLBufWritePos] = pstvmGCodecDLInfo->DL_PCM_size;
      vmGCodecDLBufWritePos++;
      p16vmGCodecDLBitstreamBuf[vmGCodecDLBufWritePos] = u16StreamSize;
      vmGCodecDLBufWritePos++;
      j = 0;
      for(i=0; i<(u16StreamSize>>1); i++)
      {
         u16tempData = pu8StreamData[j];
         j++;
         u16tempData = (u16tempData<<8) | pu8StreamData[j];
         j++;
         p16vmGCodecDLBitstreamBuf[vmGCodecDLBufWritePos] = u16tempData;
         vmGCodecDLBufWritePos++;
      }
      if(u16StreamSize&0x01)
      {
         u16tempData = pu8StreamData[j];
         u16tempData = (u16tempData<<8) | u16tempData;
         p16vmGCodecDLBitstreamBuf[vmGCodecDLBufWritePos] = u16tempData;
         vmGCodecDLBufWritePos++;
      }
   }
   else
   {
      kal_prompt_trace(MOD_L1SP, "[vmStoreGCodecDLStream] data 2byte size is large than available buffer 2byte size, data 2byte size=%d, available buffer 2byte size=%d", u32NeedSize, u32TotalBufferSize-vmGCodecDLBufWritePos);
      if(vmGCodecDLBufWritePos != 0)
      {
         p16vmGCodecDLBitstreamBuf[vmGCodecDLBufLastHeaderPos+2] += 0x0100;
      }
      else
      {
         kal_prompt_trace(MOD_L1SP, "[vmStoreGCodecDLStream] data 2byte size is large than total buffer 2byte size, data 2byte size=%d, total buffer 2byte size=%d", u32NeedSize, u32TotalBufferSize);
      }
   }

   #ifdef VM_4G_G_SERIAL_DEBUG
   kal_prompt_trace(MOD_L1SP, "[vmStoreGCodecDLStream] Exit");
   #endif //#ifdef VM_4G_G_SERIAL_DEBUG
#endif //#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
}


//use this function instead of Media_WriteDataDone to avoid media.waiting false usage
int32 vmRec_queryOutputBufFreeSpace( void )
{
   int32 count;

   count = vm.pOutputBufRead + vm.outputBufSize - vm.pOutputBufWrite -1; 

   if( count >= vm.outputBufSize )
      count -= vm.outputBufSize;
   return count;
}

void vmRec_getWriteBuffer( uint16 **buffer, uint32 *bufLen )
{
   int32 count;

	if( vm.pOutputBufRead > vm.pOutputBufWrite )
      count = vm.pOutputBufRead  - vm.pOutputBufWrite - 1;
   else if( vm.pOutputBufRead == 0 )
      count = vm.outputBufSize - vm.pOutputBufWrite - 1;
   else
      count = vm.outputBufSize - vm.pOutputBufWrite;

   *buffer = &vmRecOutputBuf[vm.pOutputBufWrite];
   *bufLen = (uint32)count;
}

// static void vmWriteDataDone( uint32 len )
static void vmRec_writeDataDone( uint32 len )
{
	vm.pOutputBufWrite += len;
   if( vm.pOutputBufWrite >= vm.outputBufSize)
      vm.pOutputBufWrite = vm.pOutputBufWrite-vm.outputBufSize;

	// kal_prompt_trace(MOD_L1SP, "vmRec_writeDataDone len=%d word", len);
}

static void vmRec_writeVmToOutputBuf( uint16 vmLen, uint16 *vmBuf ) // a frame of VM must be written to MB
{
	uint16 *toPtr;
	uint32 segment, I;


	// kal_prompt_trace(MOD_L1SP, "vmRec_writeVmToOutputBuf");
	
   vmRec_getWriteBuffer( &toPtr, &segment );

   if(segment > vmLen)      
      segment = vmLen;

   for( I = segment ; I > 0 ; I-- ){
		*toPtr++ = *vmBuf++;		
   }
   
   vmRec_writeDataDone( segment );

	// second segment
   vmLen -= segment;	// unprocess length
   if(vmLen > 0 )
   {
      vmRec_getWriteBuffer( &toPtr, &segment );

		if(segment > vmLen)      
      	segment = vmLen;
		
		for( I = segment ; I > 0 ; I-- ){
			*toPtr++ = *vmBuf++;
		}
      vmRec_writeDataDone( segment );
   }
   return;
}

/**
	@buf1: pointer to pcm buf1, 
	@len1:length of buf1, unit is word(2byte)
	@buf2:pointer to pcm buf2
	@len2: length of buf2. unit is word(2byte)
*/
void VmRec_GetReadBufs(kal_uint32 *add1, kal_uint16 *len1, kal_uint32 *add2, kal_uint16 *len2)
{

	if(vm.pOutputBufWrite >= vm.pOutputBufRead){ // write > read, 1 buf segment
	
		*add1 = (kal_uint32)(&vmRecOutputBuf[vm.pOutputBufRead]);		
		*len1 = (vm.pOutputBufWrite - vm.pOutputBufRead);		
		*add2 = 0;
		*len2 = 0;
	
	} else { //write < read, 2 buf segment
		*add1 = (kal_uint32)(&vmRecOutputBuf[vm.pOutputBufRead]);
		*len1 = (vm.outputBufSize - vm.pOutputBufRead);
		*add2 = (kal_uint32)(vmRecOutputBuf);
		*len2 = (vm.pOutputBufWrite);		
	}		
	//pcmRec.bufReadFrame = curWriteFrame;
}

/**
	@len: unit is word
*/
void VmRec_ReadDataDone(uint16 len)
{
	vm.pOutputBufRead += len;
   if( vm.pOutputBufRead >= vm.outputBufSize)
      vm.pOutputBufRead = vm.pOutputBufRead-vm.outputBufSize;
}

static void vocWriteVocToCatcher( uint32 vmLen, uint16 *vmBuf )
{
   uint32 len = vmLen*2;
   uint16 *buf = vmBuf;
   
   kal_dev_trace(TRACE_GROUP_VM, RECORD_LENGTH, len);
   while(len > 1000)
   {
      tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)buf, 1000);
	  buf += 500;
	  len -= 1000;
   }
   tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)buf, len);
}

void vmFormatter_vm(int16 *vmBuf)
{	
   volatile uint16   *addr;
   uint16   I, sc_mode, sd_mode, sc_len, sd_len;	
   uint32   vmLen = 0;
	Sal_VM_Frame vmfrm_t;
	
	SAL_VM_GetFrame2G(&vmfrm_t);
	
	sc_mode = vmfrm_t.enc_mode;
	sd_mode = vmfrm_t.dec_mode;

	/*wayne ??
	if( sc_mode>2 && sc_mode<11 ){
		I = *DSP_RX_TCH_S(0,17) >> 8;
	sd_mode = I & 0x1F;
		I = *DSP_TX_TCH_S(0,17) >> 8;
	sc_mode = I & 0x1F;
	}*/
#if defined( VM_LOG_DEBUG )
	/*for catcher log codec information*/
	if( vm.sc_mode != sc_mode || vm.sd_mode != sd_mode ){
		L1Audio_Msg_SPEECH_CODEC( L1SP_Speech_Codec_Mode(sc_mode), L1SP_Speech_Codec_Mode(sd_mode) );
		vm.sc_mode = sc_mode;
		vm.sd_mode = sd_mode;
	}
#endif
	
	ASSERT_REBOOT( (sc_len = AM_GetSpeechPatternLength(sc_mode)) > 0 );
	ASSERT_REBOOT( (sd_len = AM_GetSpeechPatternLength(sd_mode)) > 0 );
	/*if( sc_mode <= 2 ) {
		vm.control =((*DSP_RX_TCH_S(0,0) & 0x3E) << 10) |
						((*DSP_TX_TCH_S(0,0) & 2)<< 9 ) |
						(sd_mode << VM_CTRL_SD_START) |
						(sc_mode << VM_CTRL_SC_START) |
						(vm.control & 3);
	}
	else {
		I = *DSP_RX_TCH_S(0,0) >> 1;
		I = ((I & 0x10)>>1) | (I & 0x07);
		vm.control =(I << 12) |
						((*DSP_TX_TCH_S(0,0) & 3)<< 10 ) |
						(sd_mode << VM_CTRL_SD_START) |
						(sc_mode << VM_CTRL_SC_START) |
						(vm.control & 3);
	}*/
	vm.control_1 = (sc_mode << 1) | (vm.control_1 & 1);
	vm.control_2 = (sd_mode << 1) | (vm.control_2 & 1);

	if(sc_mode > 2){
	I = vmfrm_t.enc_hdr & 3;//bit0, bit1
	vm.control_1 = vm.control_1 | (I << 7); //Tx
	}
	else{
	I = (vmfrm_t.enc_hdr & 2);//sp_flag
	vm.control_1 = vm.control_1 | (I << 10); 
	//add 3G_Mode here, where is dsp's 3g mode indicator
	}

	if(sd_mode > 2){
	I = (vmfrm_t.dec_hdr & 14) >> 1;//bit1, bit2, bit3
	vm.control_2 = vm.control_2 | (I << 7);	// Rx
	}
	else{
	I = (vmfrm_t.dec_hdr & 0x3E);
	vm.control_2 = vm.control_2 | (I << 10);
	}

		{	
		extern uint32 L1I_GetTimeStamp( void );
		uint32 J;

		*vmBuf++ = VM_MAGIC_HEADER;
		J = L1SP_GetState();
		I = (uint16)( ( (SAL_VM_DBGINFO_LEN + SAL_VM_ENH_DBGINFO_LEN + SAL_VM_DRV_DBGINFO_LEN) << 3 ) | J);				  
		*vmBuf++ = I;
		*vmBuf++ = VM_VM_RECORD_FLAG;
		J = L1I_GetTimeStamp();
		I = (uint16)(J & 0xFFFF);
		*vmBuf++ = I;
		I = (uint16)((J >> 16) + ((uint32)vm_counter << 8));
		*vmBuf++ = I;
		vm_counter++;
		}


	*vmBuf++ = vm.control_1;
	*vmBuf++ = vm.control_2;
	vmLen+=2;


	if( vm.control_1 & 1 ) {
		addr = vmfrm_t.enc_hb_addr;
		vmLen += sc_len;
		for( I = 0; I < sc_len; I++ )
			*vmBuf++ = *addr++;
	}

	if( vm.control_2 & 1 ) {
		addr = vmfrm_t.dec_hb_addr;
		vmLen += sc_len;
		for( I = 0; I < sd_len; I++ )
			*vmBuf++ = *addr++;

	 addr = vmfrm_t.dbgInfo_addr;  
	 for( I = 0; I < SAL_VM_DBGINFO_LEN; I++ )
				*vmBuf++ = *addr++;

	 addr = vmfrm_t.enh_dbgInfo_addr;  
	 for( I = 0; I < SAL_VM_ENH_DBGINFO_LEN; I++ )
				*vmBuf++ = *addr++;

	 for(I = 0; I < SAL_VM_DRV_DBGINFO_LEN; I++){
			    *vmBuf++ = 0;
		}

	}

	// kal_prompt_trace(MOD_L1SP, "vmLen: %d words", vmLen);
}


/*
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
   	void sp3g_vmRecordService( uint32 *l1_info, uint16 crc_result, uint16 buf_status, uint16 *ul_frame_data, uint16* dl_frame_data, uint8 dl_count );
#endif
*/
void vmRecordHisr( void )
{
   // kal_uint32 module_id = MOD_L1AUDIO_SPH_SRV;
   //volatile uint16   *addr;
   uint16   I; //, sc_mode, sd_mode, sc_len, sd_len;
   uint16   *vmBuf;
   // uint32   vmLen = 0;

	/*
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
   if( L1SP_GetState() == L1SP_STATE_3G_SPEECH_ON || L1SP_GetState() == L1SP_STATE_3G324M_SPEECH_ON )
	{
		sp3g_vmRecordService(0, 0, 0, 0, 0, 0);
		return;
	}
#endif
	*/
	// dsp status check
   if( vm.state != VM_STATE_RECORD )
      return;

	// application status check
	if( (false == vm.isIdleVmOn) && (false == vm.isVocOn) && (false == vm.isVmLOn))
		return;


#if defined(__MA_L1__)
   {
      uint8 rx_type, tx_type, BFI;
      uint16 rx_debug;
      rx_debug = *DSP_RX_TCH_S(0,0);
      tx_type = *DSP_RX_TCH_S(0,0) & 0x3;
      rx_type = (rx_debug >> 1) & 0x7;
      BFI = (rx_debug >> 5) & 0x1;   //speechBFI
      if( rx_type < 3 )//non-amr
         rx_type = 8 + (rx_type << 1) + BFI;
      BFI = (rx_debug >> 8) & 0xFF;  //BER
      L1Audio_Msg_SPEECH_FRAME( L1SP_Speech_TX_Type(tx_type), L1SP_Speech_RX_Type(rx_type), BFI);
      L1Audio_Msg_VM_DEBUG( DP2_3G_debug_info0, DP2_3G_debug_info1, DP2_3G_debug_info7 );
   }
#endif

   vmBuf = (uint16 *)vm.vmBuf;
   if( vmBuf[0] == VM_MAGIC_HEADER ){//already buffer VM
#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)      
      if(L1SP_STATE_4G_SPEECH_ON == L1SP_GetState() && SP4G_IsGCodecMode()){
         kal_prompt_trace(MOD_L1SP, "[vmrec]vmRecordHisr record 4G G-serial codec");
         ASSERT(0);
      }else
#endif
      {
               I = (uint16)( vmBuf[1] >> 3 ) + AM_GetSpeechPatternLength((vmBuf[5]>> 1) & 0x3F) 
                                + ((vm.control_2 & 1)?(AM_GetSpeechPatternLength((vmBuf[6] >> 1) & 0x3F)):0) 
                                + 7; //####
		}
		      
      if( vmRec_queryOutputBufFreeSpace() < I ) {
			kal_dev_trace(TRACE_INFO, VM_REC_HISR_VM_DATA_LOST, vm.vm_lost_count, 0);
			vm.vm_hdlr();
         return;
      }
      else{
         vmRec_writeVmToOutputBuf(I, vmBuf );
			vm.vm_hdlr();
			
         vm.vm_lost_count = 0;
         *(uint32 *)vm.vmBuf = 0;

      }
   }
	vmFormatter_vm(vm.vmBuf);
}

/*
#pragma arm section

#define  GET_PLAYBACK_DATA(val)                            \
      if( vm.ctrl->read != vm.ctrl->write ) {              \
         (val) = vm.ctrl->rb_base[vm.ctrl->read++];        \
         vm.rb_data_len -= 1;                              \
         if( vm.ctrl->read >= vm.ctrl->rb_size )           \
            vm.ctrl->read = 0;                             \
      }                                                    \
      else {                                               \
         return;                                           \
      }

static void vm_playback( void )
{
   volatile uint16 *addr;
   uint16   I, control, sc_mode, sd_mode, data_len, data;
#if defined( VM_LOG_DEBUG )
   uint16   dummy_tmp;
#endif

   while( 1 ) {
      if( vm.ctrl->format != MEDIA_FORMAT_VRD && vm.ctrl->format != MEDIA_FORMAT_VRSI) {
#if defined( VM_LOG_DEBUG )
         do {
            GET_PLAYBACK_DATA( control );
         } while( control != VM_MAGIC_HEADER );
         GET_PLAYBACK_DATA( control );       // ignore frame number(0~15)                 
         GET_PLAYBACK_DATA( control );       // ignore frame number(16~24) and time stamp 
#endif
         GET_PLAYBACK_DATA( control );
         if( (control&3) == 0 )
            continue;
      }
      else
         control = 0x401;

      sc_mode = (control >> VM_CTRL_SC_START) & 0x0F;
      sd_mode = (control >> VM_CTRL_SD_START) & 0x0F;
      if( sc_mode != sd_mode && (sc_mode <= 2 || sd_mode <= 2) )
         continue;
      break;
   }

   if( control & VM_CTRL_UL ) {
      addr = DSP_SD2_VM_0;
      if( sc_mode <= 2 )
         *addr++ = (control >> 9) & 2;       // Write real AMR UL data 
      else
         *addr++ = (control >> 10) & 3;      // Write real AMR UL data 
      data_len = AM_GetSpeechPatternLength(sc_mode);
      for( I = 0; I < data_len; I++ )
         GET_PLAYBACK_DATA( *addr++ );
   }
   else {                                             // No UL data 
      sc_mode = sd_mode;
      AM_FillSilencePattern( DSP_SD2_VM_0, 2, sc_mode );
   }
   if( sc_mode > 2 )
      *DSP_SD2_VM_17 = sc_mode;

   if( (control & VM_CTRL_DL) == 0 ) {                // No DL data 
      sd_mode = sc_mode;
      AM_FillSilencePattern( DSP_SD1_VM_0, 0, sd_mode );
   }
   else if( control & 0x8000 ) {                      // bad speech 
      AM_FillSilencePattern( DSP_SD1_VM_0, 0, sd_mode );
      data_len = AM_GetSpeechPatternLength(sd_mode);
      for( I = 0; I < data_len; I++ )
         GET_PLAYBACK_DATA( data );
   }
   else {
      addr = DSP_SD1_VM_0;
      if( sd_mode <= 2 )
         *addr++ = (control >> 10) & 0x3E;
      else {
         I = (control >> 12);
         *addr++ = ((I & 8) << 2) + ((I & 7) << 1);
      }
      data_len = AM_GetSpeechPatternLength(sd_mode);
      for( I = 0; I < data_len; I++ )
         GET_PLAYBACK_DATA( *addr++ );
   }
#if defined( VM_LOG_DEBUG )
   if( sd_mode>2 && sd_mode<11 && (control & VM_CTRL_DL) ){
    	GET_PLAYBACK_DATA( dummy_tmp );
    	GET_PLAYBACK_DATA( dummy_tmp );
      for( I = 0; I <42; I++ )
         GET_PLAYBACK_DATA( dummy_tmp );
   }
#endif
   if( sd_mode > 2 )
      *DSP_SD1_VM_17 = sd_mode;

   if( (vm.control==0) || ((vm.control & 0x3FC) != (control & 0x3FC)) ) {
      vm.control = control;
      // Set Digital Gain for Voice Memo 
      AFE_SetDigitalGain( L1SP_VOICE, 100 );
      AM_VMPlaybackOn( control, vm.ctrl->param.vm );
   }
}
*/

/* ------------------------------------------------------------------------------ */
/*
void vmPlaybackHisr( void )
{
   int32 count;

   if (vm.state != VM_STATE_PLAY)
      return;

   vm_playback();
   count = (int32)vm.ctrl->write - (int32)vm.ctrl->read;
   if( count < 0 )
      count += vm.ctrl->rb_size;
   if( vm.ctrl->eof && (count < 17 || (vm.rb_data_len == 0
      && vm.ctrl->format == MEDIA_FORMAT_VRD))) {
      AM_VMPlaybackOff( vm.ctrl->param.vm );
      mediaSetEvent( MEDIA_END );
   }
}
*/
/* ------------------------------------------------------------------------------ */
#if 0
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
/* under construction !*/
#if defined(MT6256_S01) // FIXME:
/* under construction !*/
#elif defined(MT6589) || defined(MT6280)
#else
/* under construction !*/
#endif
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(MT6280) || defined(MT6589)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else 
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
#endif


#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
static void vmRefMic_AGC_PcmRecord( bool isToVoc, volatile uint16 *addr, uint16 len )
{
   uint32 I, tmp = 0;
   uint16 *buf, *mBuf;
   uint16 logsize;

	// kal_prompt_trace(MOD_L1SP, "vmRefMic_AGC_PcmRecord");
	
   logsize = len + 2 + 2;
   
   buf = (uint16 *)vm.pcmBuf; 
   *buf++ = (vm.vm_lost_count << 8) + vm.pcm_lost_count;
   *buf++ = vm_counter ;   
   
   {//RefMic
      IDMA_ReadFromDSP((uint16*)buf, addr, len);
      buf += len;
	  *buf++ = SAL_AGC_GetSWGain(0);
	  *buf = SAL_AGC_GetSWGain(1);

   }

   buf = (uint16 *)vm.pcmBuf;

	if(isToVoc){
		vocWriteVocToCatcher(logsize, buf);   
		
	} else { // normal vm process
	
	   // Media_GetWriteBuffer( &mBuf, &tmp );
	   vmRec_getWriteBuffer( &mBuf, &tmp );
	   if( tmp > logsize )
	      tmp = logsize;
	   for( I = tmp ; I > 0 ; I-- )
	      *mBuf++ = *buf++;
		
	   vmRec_writeDataDone(tmp);
	   tmp = logsize - tmp;
	   if( (int32)tmp > 0 ){
	      // Media_GetWriteBuffer( &mBuf, &I );
	      vmRec_getWriteBuffer( &mBuf, &I );
	      for( I = tmp ; I > 0 ; I--) {
	         *mBuf++ = *buf++;				
	      }
	      vmRec_writeDataDone(tmp);
	   }
	}
}
/*
static void vocRefMic_AGC_PcmRecord( void )
{
   uint32 I = 0;
   uint16 *buf;
   
   buf = (uint16 *)vm.pcmBuf; 
   *buf++ = (vm.vm_lost_count << 8) + vm.pcm_lost_count;
   *buf++ = vm_counter ;   
   
   {//RefMic
      volatile uint16* ptr;
      ptr = DSP_DM_ADDR(REFMIC_PAGE_NUM, DUALMIC_MIC2_BUF_PTR);
      IDMA_ReadFromDSP((uint16*)buf, DSP_DM_ADDR(REFMIC_PAGE_NUM, *ptr), (uint32)FRAME_BUF_SIZE);
      buf += FRAME_BUF_SIZE;
      IDMA_ReadFromDSP((uint16*)buf, DSP_DM_ADDR(REFMIC_PAGE_NUM, 0x37B9), (uint32)1);
      buf ++;
      IDMA_ReadFromDSP((uint16*)buf, DSP_DM_ADDR(REFMIC_PAGE_NUM, 0x37BE), (uint32)1);
   }

   buf = (uint16 *)vm.pcmBuf;

   vocWriteVocToCatcher(VM_REFMICPCM_DEBUG_SIZE, buf);   
}
*/
#endif

static void vm4WayPcmRecord(volatile uint16 *ul_addr, uint16 ul_len, volatile uint16 *dl_addr, uint16 dl_len)
{
   uint32 I;
	uint32 tmp = 0;
   uint16 *buf, *mBuf;
   uint16 logsize;
	
   logsize = ul_len + dl_len + 2;
	
	// kal_prompt_trace(MOD_L1SP, "vm4WayPcmRecord, logsize = %d", logsize);

   buf = (uint16 *)vm.pcmBuf; 
   // header for record 1st set of UL-DL PCM data 
   *buf++ = (vm.vm_lost_count << 8) + vm.pcm_lost_count;
   *buf++ = vm_counter ;
   
   // Uplink
   IDMA_ReadFromDSP((uint16*)buf, ul_addr, ul_len);
   buf+= ul_len;
   
   // Downlink 
   IDMA_ReadFromDSP((uint16*)buf, dl_addr, dl_len);
   
   buf = (uint16 *)vm.pcmBuf;
   // Media_GetWriteBuffer( &mBuf, &tmp );
   vmRec_getWriteBuffer( &mBuf, &tmp );
   if( tmp > logsize )
      tmp = logsize;
   for( I = tmp ; I > 0 ; I-- ) {
      *mBuf++ = *buf++;		
   }
   // vmWriteDataDone( tmp );
   vmRec_writeDataDone(tmp);
	
   tmp = logsize - tmp; // tmp is size did not write to Buffer
   if( (int32)tmp > 0 ){
      // Media_GetWriteBuffer( &mBuf, &I );
      vmRec_getWriteBuffer( &mBuf, &I );

		if(I>=tmp){
   	   for( I = tmp ; I > 0 ; I--) {
      	   *mBuf++ = *buf++;      	   
   	   }
		
	      //vmWriteDataDone( tmp );
      	vmRec_writeDataDone( tmp );
		} else {
			kal_dev_trace(TRACE_INFO, VM_REC_HISR_PCM_DATA_LOST, 0);
		}
   }
}

static void voc4WayPcmRecord( volatile uint16* ul_addr, uint16 ul_len, volatile uint16* dl_addr, uint16 dl_len)
{
   uint16 *buf;

   buf = (uint16 *)vm.pcmBuf; 
   // header for record 1st set of UL-DL PCM data 
   *buf++ = (vm.vm_lost_count << 8) + vm.pcm_lost_count;
   *buf++ = vm_counter ;

	// make it interleave	
   // Uplink
   IDMA_ReadFromDSP((uint16*)buf, ul_addr, ul_len);
   buf+= ul_len;
   
   // Downlink 
   IDMA_ReadFromDSP((uint16*)buf, dl_addr, dl_len);
   
   buf = (uint16 *)vm.pcmBuf;

   vocWriteVocToCatcher(ul_len + dl_len + 2, buf);
}

void vmTchPcmRecordHisr(void *param)
{
   uint32 I, tmp = 0;
   // uint16 dummy;
   uint16 *buf; //, *mBuf;
   Sal_EPL_Frame eplfrm_t;
   uint16 pcmsize;
   
   // dsp status check
   if( vm.state != VM_STATE_RECORD )
      return;

	// application status check
	if( (false == vm.isIdleVmOn) && (false == vm.isVocOn) && (false == vm.isVmLOn))
		return;

   SAL_EPL_GetFrame(&eplfrm_t);

   pcmsize = 0;
   if(vm.debug_info & VM_PCM_1ST_SET_RECORD_FLAG)
   		pcmsize += eplfrm_t.ul_pre_len + eplfrm_t.dl_pre_len;
   if(vm.debug_info & VM_PCM_2ND_SET_RECORD_FLAG)
   		pcmsize += eplfrm_t.ul_pos_len + eplfrm_t.dl_pos_len;
   if(vm.debug_info & VM_PCM_REFMIC_RECORD_FLAG)
   		pcmsize += eplfrm_t.ul2_pos_len;
   	
	
   // handing the total size I (vm + pcm buffer) in word(2byte)
   buf = (uint16 *)vm.vmBuf;
   if( buf[0] == VM_MAGIC_HEADER ){//already buffer VM, (normal case)
      tmp = ( buf[1] >> 3 ) + pcmsize; // debug size (vm buf + pcm buf)
#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
      //if(L1SP_STATE_4G_SPEECH_ON == L1SP_GetState() && SP4G_IsGCodecMode()){
      if( (buf[5]&0x3000) == 0x2000 ){
         kal_prompt_trace(MOD_L1SP, "[vmrec]vmTchPcmRecordHisr record 4G G-serial codec");
         I =   tmp
             + ( buf[5] & 0x0FFF )
             + ( buf[6] & 0x0FFF )
             + 7;
      }else
#endif         
      {
         I = tmp + GET_VM_LENGTH(vm.control_1, vm.control_2);
      }      
   } else { // case when previous vmbufer is missing! Save the pcm data with empty vm 
      tmp = pcmsize;  //debug size(only PCM)
      I = pcmsize + 3 + 2;// plus sync word and format, and 2 timestamp

	  
   }

   buf[2] &= 0xfe0f;//clean the epl band flag
   if(eplfrm_t.ul_pre_len == 320)
   		buf[2] |= VM_PCM_BAND_FLAG_UL_PRE;
   if(eplfrm_t.ul_pos_len == 320)
   		buf[2] |= VM_PCM_BAND_FLAG_UL_POS;
   if(eplfrm_t.dl_pre_len == 320)
   		buf[2] |= VM_PCM_BAND_FLAG_DL_PRE;
   if(eplfrm_t.dl_pos_len == 320)
   		buf[2] |= VM_PCM_BAND_FLAG_DL_POS;
   if(eplfrm_t.ul2_pos_len == 320)
   		buf[2] |= VM_PCM_BAND_FLAG_UL2_POS;
	

	//when vm logging and VOC are both on, only send the data to vm logging to reduce log size
	// if(vm.isVmLOn || ((!vm.isVmLOn) && (!vm.isVocOn) && (VM_STATE_RECORD == vm.state))){	 // Vm Logging  or idle VM record
	if(vm.isVmLOn || vm.isIdleVmOn) { // Vm Logging  or idle VM record
		
		if( vmRec_queryOutputBufFreeSpace() < I )
	   { // drop this log and add counter
	      vm.pcm_lost_count++; 
			kal_dev_trace(TRACE_INFO, VM_REC_HISR_VM_DATA_LOST, vm.vm_lost_count, 1);

			vm.vm_hdlr();
	      return;       
	   } else {
	      buf[0] = VM_MAGIC_HEADER;
	      buf[1] = (uint16)(tmp << 3) | ( L1SP_GetState()) ;	               
	      buf[2] |= ( vm.debug_info & (VM_PCM_REFMIC_RECORD_FLAG + VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG) );              
	   }
		
		// vm buf 
		I -= pcmsize; // I is vm buffer size, 
		vmRec_writeVmToOutputBuf(I, buf );
		/*	
	   Media_GetWriteBuffer( &mBuf, &tmp );
	   I -= vm.pcm_save_size;
	   if( tmp > I )
	      tmp = I;
	   for( dummy = (uint16)tmp ; dummy > 0 ; dummy-- )
	      *mBuf++ = *buf++;
	   vmWriteDataDone( tmp );
	   I -= tmp;
	   if( (int32)I > 0 ){
	      Media_GetWriteBuffer( &mBuf, &tmp );
	      for( dummy = (uint16)I ; dummy > 0 ; dummy-- )
	         *mBuf++ = *buf++;
	      vmWriteDataDone( I );
	   } */

		//pcm bufs
	   if(vm.debug_info & VM_PCM_1ST_SET_RECORD_FLAG)
	   {
	      vm4WayPcmRecord(eplfrm_t.ul_pre_buf, eplfrm_t.ul_pre_len, eplfrm_t.dl_pre_buf, eplfrm_t.dl_pre_len);			
	   }  

	   if(vm.debug_info & VM_PCM_2ND_SET_RECORD_FLAG)
	   {      
	      vm4WayPcmRecord(eplfrm_t.ul_pos_buf, eplfrm_t.ul_pos_len, eplfrm_t.dl_pos_buf, eplfrm_t.dl_pos_len);			
	   }     
	       
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	   if(vm.debug_info & VM_PCM_REFMIC_RECORD_FLAG)
	   {
	      vmRefMic_AGC_PcmRecord(false, eplfrm_t.ul2_pos_buf, eplfrm_t.ul2_pos_len);
	   }
#endif
		
		vm.vm_hdlr();
	} else { // VOC,
		// fill vm buffer header 
		buf[0] = VM_MAGIC_HEADER;
		buf[1] = (uint16)(tmp << 3) | ( L1SP_GetState()) ;								
		buf[2] |= ( vm.debug_info & (VM_PCM_REFMIC_RECORD_FLAG + VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG) ); 				 

		I -= pcmsize;
		vocWriteVocToCatcher(I, buf);
		if(vm.debug_info & VM_PCM_1ST_SET_RECORD_FLAG) {
			voc4WayPcmRecord(eplfrm_t.ul_pre_buf, eplfrm_t.ul_pre_len, eplfrm_t.dl_pre_buf, eplfrm_t.dl_pre_len);
		}

		if(vm.debug_info & VM_PCM_2ND_SET_RECORD_FLAG) {
			voc4WayPcmRecord(eplfrm_t.ul_pos_buf, eplfrm_t.ul_pos_len, eplfrm_t.dl_pos_buf, eplfrm_t.dl_pos_len);			
		}

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
		if(vm.debug_info & VM_PCM_REFMIC_RECORD_FLAG)
		{
      	vmRefMic_AGC_PcmRecord(true, eplfrm_t.ul2_pos_buf, eplfrm_t.ul2_pos_len);
		}
#endif
		
	}

	*(int32 *)vm.vmBuf = 0;//reset
   vm.pcm_lost_count = 0;
	buf[2] = 0;
}

void vmFormatter_amr(int16 *vmBuf)
{	
   volatile uint16 *addr;
   uint16 I, sc_mode, sd_mode, sc_len, sd_len ; 	
   uint32 J;
   Sal_VM_Frame vmfrm_t;
	/*I = DP_3G_DL_RX_MODE_REPORT >> 8;
	sd_mode = I & 0x1F;
	I = DP_3G_UL_TX_MODE_REPORT >> 8;
	sc_mode = I & 0x1F;*/
	SAL_VM_GetFrame3G(&vmfrm_t);
	sd_mode = vmfrm_t.dec_mode;
	sc_mode = vmfrm_t.enc_mode;

	ASSERT_REBOOT( (sc_len = AM_GetSpeechPatternLength(sc_mode)) > 0 );
	ASSERT_REBOOT( (sd_len = AM_GetSpeechPatternLength(sd_mode)) > 0 );

	I = vmfrm_t.enc_hdr;
	I = I & 0x03;
	vm.control_1 = I << 7 | (sc_mode << 1) | (vm.control_1 & 1);
	if(SAL_3G_Mode())
		vm.control_1 = vm.control_1 | 0x1000;


	I = vmfrm_t.dec_hdr;
	I = I & 0x0e;
	vm.control_2 = I << 6 | (sd_mode << 1) | (vm.control_2 & 1);

	//kal_dev_trace( TRACE_INFO, VM_CONTROL, vm.control );
	// record syn_word for VM_LOG_DEBUG 
		
	*vmBuf++ = VM_MAGIC_HEADER;
	J = L1SP_GetState();
	I = (uint16)( ( (SAL_VM_DBGINFO_LEN + SAL_VM_ENH_DBGINFO_LEN + SAL_VM_DRV_DBGINFO_LEN)<< 3 ) | J);
	*vmBuf++ = I;
	*vmBuf++ = VM_VM_RECORD_FLAG ;			 //VM
	J = L1I_GetTimeStamp();
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
	if( g_bNeedExtraLog )
		  kal_dev_trace( TRACE_INFO, VM_SP3G_VM_L1T, J );
#endif
	I = (uint16)(J & 0xFFFF);
	*vmBuf++ = I;
	I = (uint16)((J >> 16) + ((uint32)vm_counter << 8));
	*vmBuf++ = I;
	vm_counter++;

	// record vm control value 	
	*vmBuf++ = vm.control_1;
	*vmBuf++ = vm.control_2;

	// record UL data 	
	addr = vmfrm_t.enc_hb_addr;
	for( I = 0; I < sc_len; I++ )
		*vmBuf++ = *addr++;
		
	// record DL data 	
	addr = vmfrm_t.dec_hb_addr;
	for( I = 0; I < sd_len; I++ )
		*vmBuf++ = *addr++;

	addr = vmfrm_t.dbgInfo_addr;  
	 for( I = 0; I < SAL_VM_DBGINFO_LEN; I++ )
		*vmBuf++ = *addr++;

	addr = vmfrm_t.enh_dbgInfo_addr;  
	 for( I = 0; I < SAL_VM_ENH_DBGINFO_LEN; I++ )
		*vmBuf++ = *addr++;

	for(I = 0; I < SAL_VM_DRV_DBGINFO_LEN; I++){
		if(I < VM_3G_NETWORK_INFO_LEN)
		*vmBuf++ = vm3GNetworkInfo[I];
		else
		*vmBuf++ = 0;
		}
	 
}

kal_uint32 SP4G_GetCodecMode(void);
void vmFormatter_4g(int16 *vmBuf)
{
#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)   
   if(!SP4G_IsGCodecMode()){//amr
#endif      
      vmFormatter_amr((int16 *)vmBuf);
#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)      
   }else{
      vmFormatter_gseries((uint16 *)vmBuf);//ASSERT(0);
   }
#endif   
}

void vmTchRecordHisr(void *param)
{
	kal_bool is3G;	
   uint8    sp_state = L1SP_GetState();	
   uint16   *vmBuf;

	// check dsp status	
   if( vm.state != VM_STATE_RECORD )
      return;

	// check application status
	if( (false == vm.isIdleVmOn) && (false == vm.isVocOn) && (false == vm.isVmLOn))
		return;

	// REMIND!! 
	// For MT6280: when vm under 3g call, vm interrupt is not this one. Need DSP's patch 
	// For MT6589: when vm under 3g call, vm interrupt is this one.
	/*
    if( L1SP_GetState() != L1SP_STATE_2G_SPEECH_ON )
      return;
	*/

	/* REMOVE
   if(vm.isVmLOn){  // vm logging
		// TODO: 
		if(vmRec_queryOutputBufFreeSpace() < VM_MAXIMUM_SAVE_SIZE)		
	   {
	      vm.vm_lost = 1; 
	      vm.vm_lost_count ++;
	      // mediaDataNotification();
	      return;       
	   }
	   
	    vm.vm_lost = 0;
		
	    vmRecordHisr();
	    mediaIncRecordTime();  //for update record time
	    mediaDataNotification();        
   }
   */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
/* under construction !*/
#else //#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
/* under construction !*/
#endif //#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	
	//check is under 3g or not
	is3G = false;
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ ) // when 3G
	is3G = ( L1SP_GetState() == L1SP_STATE_3G_SPEECH_ON || L1SP_GetState() == L1SP_STATE_3G324M_SPEECH_ON );	
#endif

	// just logging
#if defined(__MA_L1__)
	if(!is3G) {
		uint8 rx_type, tx_type, BFI;
		uint16 rx_debug;
		rx_debug = *DSP_RX_TCH_S(0,0);
		tx_type = *DSP_RX_TCH_S(0,0) & 0x3;
		rx_type = (rx_debug >> 1) & 0x7;
		BFI = (rx_debug >> 5) & 0x1;	 //speechBFI
		if( rx_type < 3 )//non-amr
			rx_type = 8 + (rx_type << 1) + BFI;
		BFI = (rx_debug >> 8) & 0xFF;  //BER
		L1Audio_Msg_SPEECH_FRAME( L1SP_Speech_TX_Type(tx_type), L1SP_Speech_RX_Type(rx_type), BFI);
		L1Audio_Msg_VM_DEBUG( DP2_3G_debug_info0, DP2_3G_debug_info1, DP2_3G_debug_info7 );
	}
#endif

	// process previous buffer
	vmBuf = (uint16 *)vm.vmBuf;
   if( vmBuf[0] == VM_MAGIC_HEADER ){//already buffer VM
      uint16 I;
#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)      
      //if(L1SP_STATE_4G_SPEECH_ON == sp_state && SP4G_IsGCodecMode()){
      if( (vmBuf[5]&0x3000) == 0x2000 ){
         kal_prompt_trace(MOD_L1SP, "[vmrec]vmTchRecordHisr record 4G G-serial codec");
         I =   (uint16)( vmBuf[1] >> 3 )
             + (uint16)( vmBuf[5] & 0x0FFF )
             + (uint16)( vmBuf[6] & 0x0FFF )
             + 7; //####
      }else
#endif
      {
         I = (uint16)( vmBuf[1] >> 3 ) + AM_GetSpeechPatternLength((vmBuf[5]>> 1) & 0x3F) 
               + ((vm.control_2 & 1)?(AM_GetSpeechPatternLength((vmBuf[6] >> 1) & 0x3F)):0) 
               + 7; //####
      }
      //write data
      if( vmRec_queryOutputBufFreeSpace() < I ){
         vm.vm_lost = 1;
         vm.vm_lost_count++;
         kal_dev_trace(TRACE_INFO, VM_REC_HISR_VM_DATA_LOST, vm.vm_lost_count, 2);

         vm.vm_hdlr();
         return;
      }
      else{
         //when vm logging and VOC are both on, only send the data to vm logging to reduce log size   
         if(vm.isVmLOn){				
            vmRec_writeVmToOutputBuf(I, vmBuf );
            vm.vm_hdlr();	   
         } else {
            vocWriteVocToCatcher( (uint32)I, vmBuf );
         }
      }

      vm.vm_lost_count = 0;
      *(uint32 *)vm.vmBuf = 0;
      vmBuf[2] = 0;
   }

	// formatting!!!
	switch(sp_state){
	case L1SP_STATE_4G_SPEECH_ON:
	   vmFormatter_4g(vm.vmBuf);
	   break;
	case L1SP_STATE_3G_SPEECH_ON:   
	case L1SP_STATE_3G324M_SPEECH_ON:   
	   vmFormatter_amr(vm.vmBuf);
	   break;
	default:
	   vmFormatter_vm(vm.vmBuf);
	   break;      
	}
}


extern void UL1D_RXBRP_GET_INFO_FOR_SPEECH_VM(kal_int16* tpc_SIR_lta, kal_int16* dpdch_SIR_lta, kal_int16* TFCI_max_corr);
void vmSet3GNetworkInfo( uint32 *l1_info, uint16 crc_result, uint16 buf_status, uint8 dl_count )
{
	  kal_int16 tpc_SIR_lta, dpdch_SIR_lta, TFCI_max_corr, I;
      uint32 l1Info, s_value;
      if( l1_info == NULL ){
         l1Info = 0;
         tpc_SIR_lta = 0;
         dpdch_SIR_lta = 0;
         TFCI_max_corr = 0;
         s_value = 0;
      }else{
         l1Info = l1_info[1];
         tpc_SIR_lta = l1_info[4];
         dpdch_SIR_lta = l1_info[5];
         TFCI_max_corr = l1_info[6];
         s_value = l1_info[3];
      }
      I = (uint16)(l1Info & 0xFFFF);
      vm3GNetworkInfo[4] = I;
	  
      I = (uint16)(l1Info >> 16);
	  vm3GNetworkInfo[5] = I;

	  vm3GNetworkInfo[3] = crc_result;

      
      vm3GNetworkInfo[6] = (uint16)((s_value >= 32767)? 32767 : s_value);//s_value
#if defined( __MTK_UL1_FDD__ )// only MTK 3G has this function
      if(dl_count == 0){
         UL1D_RXBRP_GET_INFO_FOR_SPEECH_VM( &tpc_SIR_lta,  &dpdch_SIR_lta, &TFCI_max_corr);
      }
#endif
      vm3GNetworkInfo[0] = (uint16)tpc_SIR_lta;
      vm3GNetworkInfo[1] = (uint16)dpdch_SIR_lta;
      vm3GNetworkInfo[2] = (uint16)TFCI_max_corr;
}

/*
void vocTchRecordHisr(void *param)
{
   if( vm.state != VM_STATE_RECORD )
      return;
   
   if( L1SP_GetState() != L1SP_STATE_2G_SPEECH_ON )
      return;
         
   vm.vm_lost = 0;
   vmRecordHisr();    
}
*/

// #pragma arm section

extern void SP3G_Start_VM( void ); 
extern void SP3G_Stop_VM( void ); 
extern bool SP3G_VM_Status( void ); 

void vmSpeechOnHandler( void *state ) 
{
   if(vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG))
   {     
      AM_PCM8K_RecordOn(AM_PCM8KREC_APP_TYPE_VMEPL);
   }
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
   //SP3G_Start_VM();marked by wayne 20120808
#endif
   L1Audio_HookHisrHandler( DP_D2C_VM_REC_INT, vmTchRecordHisr, 0 );
   AM_VMRecordOn( (uint16)vm.type );
}

void vmSpeechOffHandler( void *state ) 
{      
   if(vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG))
   {      
      AM_PCM8K_RecordOff(false, AM_PCM8KREC_APP_TYPE_VMEPL);      
   }
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
   if(SP3G_VM_Status())
		SP3G_Stop_VM();
#endif
   // *DP_SC_MUTE = 0x0000; // do inside SAL
   L1Audio_UnhookHisrHandler( DP_D2C_VM_REC_INT );
   AM_VMRecordOff();
}

void VMREC_ConfigEpl(void)
{
	// only support phone call VM record dynamic change from AP side
	if( vm.isVocOn || vm.isVmLOn ){
		kal_uint16 debugInfo = L1Audio_GetDebugInfo(VM_DEBUG_INFO);
		kal_uint32 module_id = MOD_L1AUDIO_SPH_SRV;
#if defined(__ENABLE_SPEECH_DVT__)
		debugInfo = 3; 
#endif // defined(__ENABLE_SPEECH_DVT__)
		kal_trace(TRACE_INFO, VM_REC_DEBUG_INFO, debugInfo);
			
		// SP1's request, use inject string to enable EPL.
	  if(!tst_trace_check_ps_filter_off(TRACE_GROUP_EPL, &module_id, 0x2)) 			
	  {
			debugInfo |= (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG);
		}

     if(!tst_trace_check_ps_filter_off(TRACE_GROUP_REFMIC, &module_id, 0x2))	
	  {
			debugInfo |= VM_PCM_REFMIC_RECORD_FLAG;
		}
		
		if( ((debugInfo & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG))!=0) // config to open
			&& (vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG))==0) // did not open yet
		{//EPL open
		
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
			debugInfo |= VM_PCM_REFMIC_RECORD_FLAG;
	      if(debugInfo & VM_PCM_REFMIC_RECORD_FLAG){
	         vm.pcm_save_size = FIVE_PCM_SAVE_SIZE;
	      }else
#endif
	      {
	         vm.pcm_save_size = FOUR_PCM_SAVE_SIZE;
	      }

			// enable EPL
			memset(eplInputBuf, 0 , sizeof(int16)*vm.pcm_save_size);
			vm.pcmBuf = eplInputBuf; //(int16*)get_ctrl_buffer( vm.pcm_save_size*sizeof(uint16) );
			vm.pcm_lost_count = 0; 
			vm.vm_lost  = 1; // to force save VM first 
			vm.vm_lost_count = 0;
			L1Audio_HookHisrHandler( DP_D2C_VMEPL_REC_INT, (L1Audio_EventHandler)vmTchPcmRecordHisr, 0 ); //
	      AM_PCM8K_RecordOn(AM_PCM8KREC_APP_TYPE_VMEPL);
			vm.debug_info = debugInfo;
		}
	}
		
}

/**
	@vm_hdlr: handler
	@type: using in Idle VM record
	@isVoc: is call from vm over catcher.
*/
// void vmRecord( mediaControl *ctrl, uint16 type )
void VMREC_Start(void (*vm_hdlr)(void), uint16 type, bool isVoc)
{

   // if( AM_IsSpeechOn() ) {
   if( AM_IsAmInSpeechState() ) {
		
		//decide the open
	   bool isAlreadyOn = (vm.isVocOn || vm.isVmLOn);

		ASSERT((!vm.isIdleVmOn));
		
		if(isVoc){
			ASSERT(!vm.isVocOn); // prevent re-entry
			vm.isVocOn = true;
			// vm.vm_hdlr = NULL; 
		} else { // normal vm 
			ASSERT(!vm.isVmLOn); // prevent re-entry
			// L1SP_Register_Service(vmSpeechOnHandler, vmSpeechOffHandler);
			vm.vm_hdlr = vm_hdlr; 
			vm.isVmLOn = true;			
		}

		//already on		
	   if(isAlreadyOn){		
			VMREC_ConfigEpl();
			return;
	   } else {

			// Initials
			// lock sleep mode
			vm.audId = L1Audio_GetAudioID();
			L1Audio_SetFlag( vm.audId );/*Be careful.Before Locking SleepMode, to access DSP sherrif tasks much time. So access DSP must be after SetFlag*/

		   // vm.ctrl = ctrl;
		   
		   vm.type = type;
		   
			//vm buffer initital
		   vm.vmBuf = (int16 *)get_ctrl_buffer( VM_BUFFER_SIZE );//####
		   memset( vm.vmBuf, 0, VM_BUFFER_SIZE );

			// output buffer initial 
			vm.pOutputBufWrite = 0;
			vm.pOutputBufRead = 0;
			vm.outputBufSize = VMREC_OUTPUT_BUF_SIZE; 
			memset( vmRecOutputBuf, 0, VMREC_OUTPUT_BUF_SIZE*sizeof(uint16) );		

#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
            //G-serial codec buffer initial
            {
               vmInitGCodecULBuf();
               vmInitGCodecDLBuf();
            }
#endif //#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
				
			// control setup
	      //vm.control = 0x0003;
			vm.control_1 = 0x0001;
			vm.control_2 = 0x0001;

			VMREC_ConfigEpl();
			
		  
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
	      //SP3G_Start_VM();marked by wayne 20120808
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_) && !defined(__UMTS_TDD128_MODE__)
	//TDD load need to reduce trace
	      g_bNeedExtraLog = KAL_TRUE;
#endif
#endif
			L1Audio_HookHisrHandler( DP_D2C_VM_REC_INT, (L1Audio_EventHandler)vmTchRecordHisr, 0 ); 
			
			// enalbe normal VM record
	      AM_VMRecordOn( (uint16)type );
			
			vm.state = VM_STATE_RECORD;

	   }
   }
   else {
		ASSERT((!vm.isVocOn) && (!vm.isVmLOn));
		ASSERT(vm.state != VM_STATE_RECORD);
		
		// Initials
		// lock sleep mode
		vm.audId = L1Audio_GetAudioID();
		L1Audio_SetFlag( vm.audId );/*Be careful.Before Locking SleepMode, to access DSP sherrif tasks much time. So access DSP must be after SetFlag*/

		// setup handler
	   vm.vm_hdlr = vm_hdlr; 
	   vm.type = type;
		vm.isIdleVmOn = true;

		//vm buffer initital
	   vm.vmBuf = (int16 *)get_ctrl_buffer( VM_BUFFER_SIZE );
	   memset( vm.vmBuf, 0, VM_BUFFER_SIZE );

		// output buffer initial 
		vm.pOutputBufWrite = 0;
		vm.pOutputBufRead = 0;
		vm.outputBufSize = VMREC_OUTPUT_BUF_SIZE; 
		memset( vmRecOutputBuf, 0, VMREC_OUTPUT_BUF_SIZE*sizeof(uint16) );	

#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
        //G-serial codec buffer initial
        {
           vmInitGCodecULBuf();
           vmInitGCodecDLBuf();
        }
#endif //#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
		
      // for idle-mode recording , will use DP_D2C_SE_DONE , through mediaHisr -> vmRecordHisr
      // vm.control = 0x0001;
		vm.control_1 = 0x0001;
		vm.control_2 = 0x0000;
      // *DP_SC_MUTE = 0x0002; // do inside SAL

		// Read the debug info
		vm.debug_info = L1Audio_GetDebugInfo(VM_DEBUG_INFO); 
		kal_trace(TRACE_INFO, VM_REC_DEBUG_INFO, vm.debug_info);
		
		L1Audio_HookHisrHandler( DP_D2C_VM_REC_INT, (L1Audio_EventHandler)vmRecordHisr, 0 );
      AM_VMRecordOn( (uint16)type );

		if(vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG))
		{//EPL open
		
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	      if(vm.debug_info & VM_PCM_REFMIC_RECORD_FLAG){
	         vm.pcm_save_size = FIVE_PCM_SAVE_SIZE;
	      }else
#endif
	      {
	         vm.pcm_save_size = FOUR_PCM_SAVE_SIZE;
	      }

			// enable EPL
			memset(eplInputBuf, 0 , sizeof(int16)*vm.pcm_save_size);
			vm.pcmBuf = eplInputBuf; // (int16*)get_ctrl_buffer( vm.pcm_save_size*sizeof(uint16) );
			vm.pcm_lost_count = 0; 
			vm.vm_lost  = 1; // to force save VM first 
			vm.vm_lost_count = 0;
			L1Audio_HookHisrHandler( DP_D2C_VMEPL_REC_INT, (L1Audio_EventHandler)vmTchPcmRecordHisr, 0 );
         AM_PCM8K_RecordOn(AM_PCM8KREC_APP_TYPE_VMEPL);
		}

	   vm.state = VM_STATE_RECORD;
   }
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

/**
	@isVoc: is call from voice over cater. true is yes; false is no.
*/
void VMREC_Stop( bool isVoc)
{
	// check voc & vm are both closed. 
	// if(AM_IsSpeechOn()){
	if(AM_IsAmInSpeechState()){	
		if(isVoc){
			ASSERT(vm.isVocOn == true);
			vm.isVocOn = false; 
			if(vm.isVmLOn){ //still another need vm 				
				return;
			}
		} else { //record vm from media
			ASSERT(vm.isVmLOn == true);
			vm.isVmLOn = false;
			if(vm.isVocOn){ //still another need vm			
				return;
			}
		}
   }else {
   	ASSERT(vm.isIdleVmOn == true);
   	vm.isIdleVmOn = false;
   }

	if(VM_STATE_RECORD == vm.state)
   {
      vm.state = VM_STATE_RECORD_STOP;
      if(vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG))  
      {    
         AM_PCM8K_RecordOff(false, AM_PCM8KREC_APP_TYPE_VMEPL);
         L1Audio_UnhookHisrHandler( DP_D2C_VMEPL_REC_INT );
         vm.pcmBuf = NULL; // free_ctrl_buffer(vm.pcmBuf);
         
      }
      L1Audio_UnhookHisrHandler(DP_D2C_VM_REC_INT); // vm record unhook
      // L1SP_UnRegister_Service();
   }else {
   	return;
	}

	AM_VMRecordOff();
	if( vm.vmBuf != NULL ){
      free_ctrl_buffer( vm.vmBuf );
      vm.vmBuf = NULL;
   }

   vm.state = VM_STATE_STOP;

	vm.debug_info = 0;
	// output buffer clean 
	vm.pOutputBufWrite = 0;
	vm.pOutputBufRead = 0;
	vm.outputBufSize = 0; 
	memset( vmRecOutputBuf, 0, VMREC_OUTPUT_BUF_SIZE*sizeof(uint16) );	

#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
   //G-serial codec buffer initial
   {
      vmInitGCodecULBuf();
      vmInitGCodecDLBuf();
   }
#endif //#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)

	// release sleep mode
   L1Audio_ClearFlag( vm.audId );
   L1Audio_FreeAudioID( vm.audId );
   
}

/*
void vmStop(void)
{
	
   if(vm.control & 0x02)
   {
      vm.state = VM_STATE_RECORD_STOP;
      if(vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG))  
      {    
         AM_PCM8K_RecordOff(false, AM_PCM8KREC_APP_TYPE_VMEPL);
         L1Audio_UnhookHisrHandler( DP_D2C_VMEPL_REC_INT );
         vm.pcmBuf = NULL; free_ctrl_buffer(vm.pcmBuf);
         
      }
      L1Audio_UnhookHisrHandler(DP_D2C_VM_REC_INT);
      L1SP_UnRegister_Service();
   }   

   switch(vm.state) {
      case VM_STATE_RECORD_PAUSE:
         break;
      case VM_STATE_RECORD:
      case VM_STATE_RECORD_STOP:
         AM_VMRecordOff();
         *DP_SC_MUTE = 0x0000;
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
         if(SP3G_VM_Status())
            SP3G_Stop_VM();
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
         g_bNeedExtraLog = KAL_FALSE;
#endif
#endif
         break;
      case VM_STATE_PLAY:
      case VM_STATE_PLAY_PAUSE:
         AM_VMPlaybackOff(vm.ctrl->param.vm);
         break;
      default:
         ASSERT(KAL_FALSE);
   }

   if( vm.vmBuf != NULL ){
      free_ctrl_buffer( vm.vmBuf );
      vm.vmBuf = NULL;
   }

   vm.state = VM_STATE_STOP;
}
*/
/*
void vmPause(mediaControl *ctrl)
{
   switch(vm.state) {
      case VM_STATE_RECORD:
         if((vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG)) && AM_IsSpeechOn())               
            AM_PCM8K_RecordOff(false, AM_PCM8KREC_APP_TYPE_VMEPL);
         *DP_SC_MUTE = 0x0000;
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
         if(SP3G_VM_Status())
            SP3G_Stop_VM();
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
         g_bNeedExtraLog = KAL_FALSE;
#endif
#endif
         AM_VMRecordOff();
         vm.state = VM_STATE_RECORD_PAUSE;
         break;
      case VM_STATE_PLAY:
         AM_VMPlaybackOff(vm.ctrl->param.vm);
         vm.state = VM_STATE_PLAY_PAUSE;
         break;
      default:
         ASSERT(KAL_FALSE);
   }

}

void vmResume(mediaControl *ctrl)
{
   switch(vm.state) {
      case VM_STATE_RECORD_PAUSE:
         if( AM_IsSpeechOn() ) {
            vm.control = 0x0003;
            if(vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG))  
            {
               AM_PCM8K_RecordOn(AM_PCM8KREC_APP_TYPE_VMEPL);
            }
         }
         else {
            vm.control = 0x0001;
            *DP_SC_MUTE = 0x0002;
         }
#if defined(__UMTS_RAT__) || defined( __UMTS_TDD128_MODE__ )
         SP3G_Start_VM();
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
         g_bNeedExtraLog = KAL_TRUE;
#endif
#endif
         AM_VMRecordOn( (uint16)vm.type );
         vm.state = VM_STATE_RECORD;
         break;
      case VM_STATE_PLAY_PAUSE:
         vm.state = VM_STATE_PLAY;
         vm.control = 0;
         vm_playback();
         break;
      default:
         ASSERT(KAL_FALSE);
   }
}
*/
/* ------------------------------------------------------------------------------ */
// #endif
