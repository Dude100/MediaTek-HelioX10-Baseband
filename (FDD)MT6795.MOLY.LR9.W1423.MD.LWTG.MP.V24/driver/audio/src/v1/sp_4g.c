



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
 * sp_4g.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   4G speech interface
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime: $
 * $Log: $
 *
 * removed!
 * removed!
 * AAM first UL interrupt data is not ready issue.
 *
 * removed!
 * removed!
 * Do not notify LTECSR when there is no active RAB link.
 *
 * removed!
 * removed!
 * Notify EL1 it is VOLTE on.
 *
 * removed!
 * removed!
 * EMAC do not support two emac_volte_callon() without emac_volte_calloff().
 *
 * removed!
 * removed!
 * Do not use SP4G after speech off.
 *
 * removed!
 * removed!
 * Fix WB<->NB issue which cause by DSP SE interrupt raise at the beginning of next SE.
 *
 * removed!
 * removed!
 * AAM check invalid information from MAC.
 *
 * removed!
 * removed!
 * 	Support MUTE_NOTIFY for LTECSR.
 *
 * removed!
 * removed!
 * VoLte data alignment
 *
 * removed!
 * removed!
 * Merge VoLTE Audio Align MAC low power algorithm. Phase1.
 *
 * removed!
 * removed!
 * Modify side effect of PSR_Link_Eest/PSR_Link_Deest out of sequency.
 *
 * removed!
 * removed!
 * Work around establish/de-establish RAB invalid sequence of control plane.
 *
 * removed!
 * removed!
 * Modify VoLTE AMR-WB codec type issue.
 *
 * removed!
 * removed!
 * Merge VoLTE to LR9.W1423.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	Back out changelist 541440
 *
 * removed!
 * removed!
 * Support Frame Aggregation
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	data plane first sync, these file also need to update
 *  	
 * 	1_ [MODEM.mak] /proj/mtk01662/moly/volte_dev/mcu/make/MODEM.mak - no permission for operation on file(s).
 * 	2_ [REL_COMP_COMMON.mak ] /proj/mtk01662/moly/volte_dev/mcu/make/rel/REL_COMP_COMMON.mak - no permission for operation on file(s).
 * 	3_ [folderlist.bld]/proj/mtk01662/moly/volte_dev/mcu/make/folderlist.bld - no permission for operation on file(s).
 * 	4_ [folderlist_ps.bld]/proj/mtk01662/moly/volte_dev/mcu/make/folderlist_ps.bld - no permission for operation on file(s).
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * .
 *
 * removed!
 * .
 *
 * removed!
 * .
 *
 
 *******************************************************************************/
#define __SP4G_UL_RESYNC__
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "string.h"
#include "kal_trace.h"
#include "reg_base.h"

//#include "speech_def.h"
#include "audio_dsp_d2c_def.h"
#include "common_def.h"
#include "l1audio.h"
#include "am.h"
#include "l1audio_trace.h"
#include "media.h" 
#include "l1sp_trc.h"
#include "amr_table.h"

#include "sal_exp.h"
#include "sal_def.h"


#include "dcl.h"

#include "drv_sap.h"
#include "ltecsr_msgid.h"

#include "audio_msgid.h"
#include "l1sp_el2_struct.h"
#include "sp_drv.h"

#undef __CSHSPA_SUPPORT__
#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
#include "vm.h"
#endif //#if defined(__G_CODEC_SUPPORT__) && defined(__VOLTE_SUPPORT__)
/////
#if defined(__G_CODEC_SUPPORT__)
#include "pcmrb.h"
#include "streamrb.h"
#include "g_series_union.h"

//10frame * sample_number(20ms at 8k) * 2byte_per_sample
#define G_SERIAL_CODEC_PCM_RB_BYTE_SIZE (10*160*2)
//2048byte
#define G_SERIAL_CODEC_STREAM_RB_BYTE_SIZE (2048)


__attribute__((aligned (4))) G_Series_Handle           enc_handle;
__attribute__((aligned (4))) unsigned char             enc_tmp_buf[4000+100];
__attribute__((aligned (4))) unsigned char             enc_init_buf[4000+100];

__attribute__((aligned (4))) G_Series_Handle           dec_handle;
__attribute__((aligned (4))) unsigned char             dec_tmp_buf[4000+100];
__attribute__((aligned (4))) unsigned char             dec_init_buf[4000+100];

__attribute__((aligned (4))) G726_Enc_Init_Param       enc_init_param_g726;
__attribute__((aligned (4))) G726_Enc_Runtime_Param    enc_rtime_param_g726;
__attribute__((aligned (4))) G726_Dec_Init_Param       dec_init_param_g726;



__attribute__((aligned (4))) G722_Dec_Runtime_Param    dec_rtime_param_g722;
__attribute__((aligned (4))) G722_Dec_Init_Param       dec_init_param_g722;


__attribute__((aligned (4))) G729_Enc_Init_Param       enc_init_param_g729;

__attribute__((aligned (4))) G7231_Enc_Init_Param      enc_init_param_g723_1;
__attribute__((aligned (4))) G7231_Enc_Runtime_Param   enc_rtime_param_g723_1;

__attribute__((aligned (4))) G711_Enc_Init_Param       enc_init_param_g711;
__attribute__((aligned (4))) G711_Dec_Init_Param       dec_init_param_g711;
__attribute__((aligned (4))) G711_Dec_Runtime_Param    dec_rtime_param_g711;


uint16 dl_pcm_tmp[400];
uint16 ul_pcm_tmp[400];
uint32 dl_encoded_tmp[600/sizeof(uint32)];
uint32 ul_encoded_tmp[600/sizeof(uint32)];


struct GSERIES_MANAGER{
   SP4G_Codec enc_codec;
   //encode
   void  *enc_hdl;
   void  *enc_tmp_buf;
   void  *enc_init_buf;
   
   int    enc_pcm_size;
   int    enc_bs_size; 
   
   void  *enc_init_param;
   void  *enc_rtime_param;
   
   SP4G_Codec dec_codec;
   //decode
   void  *dec_hdl;
   void  *dec_tmp_buf;
   void  *dec_init_buf;
   
   int    dec_pcm_size;
   int    dec_bs_size;    
   
   void  *dec_init_param;
   void  *dec_rtime_param;
   
     
}g_series_mgr;
#endif

#if defined(__G_CODEC_SUPPORT__)
uint16   aud_dl_id;
uint16   aud_ul_id;
kal_uint16 *pcm_ul_buf_ptr, *pcm_dl_buf_ptr;
kal_uint8  *ul_buf_ptr,     *dl_buf_ptr;

PCMRB pcm_ul_buf, pcm_dl_buf;
StreamRB ul_buf, dl_buf;
#endif
/////

///<--- FIX ME
//int WWWW = 0;
extern int case_;
void PSR_SP4G_Callback( SP4G_Event event, void *data ){
	if(SP4G_UL_DATA_NOTIFY == event){
		//WWWW = 1;
		if(1) {
		   kal_prompt_trace(MOD_L1SP, "[DEBUG]PSR_SP4G_Callback 1");
			/* send message L1SP to LTECSR */
			msg_send4(	MOD_L1SP, 				/* source module id */
					MOD_LTECSR, 				/* destination module id */
					L1SP_LTECSR_SAP,			/* sap id */
					MSG_ID_LTECSR_VOICE_UL_DATA_NOTIFY	/* message id */
				 );						
		} else {
		   kal_prompt_trace(MOD_L1SP, "[DEBUG]PSR_SP4G_Callback 0");
			msg_send4(MOD_L1SP, MOD_MED, AUDIO_SAP, 123456);  	
		}
	}else if(SP4G_UL_MUTE_NOTIFY == event){
		msg_send4(	MOD_L1SP, 				/* source module id */
				MOD_LTECSR, 				/* destination module id */
				L1SP_LTECSR_SAP,			/* sap id */
				MSG_ID_LTECSR_VOICE_UL_MUTE_NOTIFY	/* message id */
			 );
	}
}
extern void CSR_SP3G_Callback( SP3G_Event event, void *data );
extern kal_enhmutexid sp_handover_mutex; //just for 4G and 4G
/// FIX ME --->

extern const kal_uint16* tblAMR_WBOrder[9];

//#define __DLDCH_DELAY_IMPROVE__

 

  
 
#if defined( __UMTS_RAT__ )  || defined( __UMTS_TDD128_MODE__ )

//4G
extern kal_enhmutexid sp_handover_mutex;//sp_4g.c

#define _EXTRA_LOG_FOR_BIT_TRUE_
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
kal_bool _CS_NeedSpeechExtraLog( void );
kal_bool _3g_bNeedExtraLog; //FIX ME
#endif

extern void L1SP_4G_Request(void);
bool is_g_codec(uint8 codec);


//#define AMR_LOST_FRAME  30
#define AMR_SID_FRAME   8
#define AMR_NO_DATA     15 

#define AWB_SID_FRAME   9
#define WB_AMR_SID_FRAME   25
#define UL_HARD_REAL_TIME_DEMAND 
     
#if defined(__AMRWB_LINK_SUPPORT__)

#define UL_MAX_DATA_SIZE  62 // frame_type, UL : len / DL : FQI_flag , DATA(23.85=>60)
#define DL_MAX_DATA_SIZE  66 // frame_type, UL : len / DL : FQI_flag , CFN(4 bytes),  DATA(23.85=>60)
#define MAX_DSP_FRAME_LEN 30
#else     
#define UL_MAX_DATA_SIZE  34 // frame_type, UL : len / DL : FQI_flag , DATA(12.2=>32)
#define DL_MAX_DATA_SIZE  38 // frame_type, UL : len / DL : FQI_flag , CFN(4 bytes),  DATA(12.2=>32)
#define MAX_DSP_FRAME_LEN 16
#endif

#define MAXIMUM_UL_DELAY 15  // CSR define for debug  
#define START_SHRINK_UL_DELAY 10 // L1Audio shrink UL delay from 40ms to 20ms 

#define MAX_4G_DL_BUFF_SIZE (2)
#define MAX_4G_UL_BUFF_SIZE (2)

#define DL_4G_THRESHOLD (2)
#define UL_4G_THRESHOLD (2)

#define HARD_REAL_TIME_UL_BUFFER_NUM 1 // could not revise 
#define RAT_4G_UL_BUFFER_NUM MAX_4G_UL_BUFF_SIZE  // could not revise 

#define RAT_4G_DL_BUFFER_NUM                  MAX_4G_DL_BUFF_SIZE  // do not suggest to revise 
#define RAT_4G_DL_BUFFER_NUM_BEFORE_RESYNC    MAX_4G_DL_BUFF_SIZE  // do not suggest to revise


#ifdef __VIDEO_CALL_SUPPORT__
   #define MAX_UL_BUFFER_NUM  5
   #define MAX_DL_BUFFER_NUM  20
#elif defined(__CSHSPA_SUPPORT__)
	#define MAX_UL_BUFFER_NUM  2
	//In theory, Max CS delay is 200ms at most, which is 10 frames
	#define MAX_DL_BUFFER_NUM  10
#else 
   #define MAX_UL_BUFFER_NUM  RAT_4G_UL_BUFFER_NUM
   #define MAX_DL_BUFFER_NUM  RAT_4G_DL_BUFFER_NUM_BEFORE_RESYNC
#endif 

#define __SP4G_DL_BUFFER_BEFORE_PLAY__
/* Enable more buffering before put frame to DSP to keep start of speech smooth.
   If not defined this compile option, it can reduce delay but maybe can't cover the initial discontinous.
*/   

// here should be careful for this will limit MAX_DL_BUFFER_NUM to 1 << DL_BUF_INDEX_BIT_NUM 
//                                        and MAX_UL_BUFFER_NUM to 1 << UL_BUF_INDEX_BIT_NUM      
#define DL_BUF_INDEX_BIT_NUM 5 
#define UL_BUF_INDEX_BIT_NUM (8 - DL_BUF_INDEX_BIT_NUM)

#define SP4G324M_DL_EXTRA_LEN 5//frameType(1), len(1), l1_frame : recieve(3)
#define SP4G_DL_EXTRA_LEN     6//frameType(1), FQI_flag(1), CFN(4)(unit:byte)

#if defined(__AMRWB_LINK_SUPPORT__)
//AMRWB 23.85 classB 405 bits=>51 bytes
#define MAX_BYTES_IN_SINGLE_SUBFLOW ((405 + 7)>>3)
#else
//AMR 12.2 classB 103 bits=>13 bytes
#define MAX_BYTES_IN_SINGLE_SUBFLOW ((103 + 7)>>3)
#endif
#define _IGNORE_TYPE_ERROR_   // for 4G324M since the CRC is weaker, it's possible wrong pattern.
                              // so ignore it instead of assert.

typedef struct 
{   
   uint16 dsp_buffer[MAX_DSP_FRAME_LEN];
   uint8 dl_buffer[MAX_DL_BUFFER_NUM][DL_MAX_DATA_SIZE];
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   uint8 dl_buffer2[MAX_DL_BUFFER_NUM][DL_MAX_DATA_SIZE];
#endif
   /*0: CFN, 1:RSSI|RSCP|ECIO|HHO_SHO ,2:crc_result ,3:s_value[0], 4:tpc_SIR_lta, 5:dpdch_SIR_lta, 6:TFCI_max_corr */
   uint32 L1_Info[4][7];

#if defined(__SP4G_UL_RESYNC__)   
   uint32 time[3];  //unit:ms  0: eMAC , 1: under dl_hisr, ready for VBIReset, 2: ul_hisr timing   
   bool   ul_request_resync;
   int32  time2nextULHISR;   //unit: ms
   //bool   is_trigger_mac_notify;   
   //bool   ul_resync_info_available;
   //uint32 EMACSyncInfoInUse;
#endif
   
   uint8 ul_buffer[MAX_UL_BUFFER_NUM][UL_MAX_DATA_SIZE]; // prevent sp4g_hisr , CSR race condition
   uint8 ul_write_idx;
   uint8 ul_read_idx;
   uint8 ul_count;
   bool is_getting_ul_data;
   uint8 ul_delay;
   uint8 dl_count;
   uint8 dl_write_idx;
   uint8 dl_read_idx;
   uint8 ul_codec_mode;
   uint8 ul_report;
   uint8 dl_report;
   uint8 pre_ul_report;
   uint8 pre_dl_report;
   bool waiting;  // 1-message-1-get policy
   bool ul_refresh; // detect change codec_mode
   bool ul_intrarat; //if DSP SE interrupt raise at next beginning of next SE, ignore first SE.
   uint8 l1_info_idx;

   uint8 sp4g_mode;
   uint8 ul_buffer_size;
   uint8 dl_buffer_size;
   uint8 dtx_state;  //enter dtx mode
   uint8 dtx_force;  //occured that force AMR frame
//#if defined(__CSHSPA_SUPPORT__)
   uint8 dl_subflow[MAX_BYTES_IN_SINGLE_SUBFLOW];
//#endif   
#define DL_MAX_DATA_SIZE  (1024) //#FIX ME
#define MAX_DSP_FRAME_LEN (1024)

}SP4G_Struct;

SP4G_Struct *sp4g;

#if defined(__SP4G_UL_RESYNC__)
#include "us_timer.h"
#define ust_get_duration_true(prev, cur)  (((cur) >= (prev))? (((cur) - (prev))): ((USCNT_WRAP - (prev) + (cur))))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define DSP_SD_MIPS    (5)         //ms
//#define DSP_SE_MIPS    (14-9)        //ms
#define DSP_SE_MIPS    (20)        //ms
#define DSP_PERIOD     (20)        //ms

#define DRIFT_DSP2MCU_RESET         (2) //unit ms :allow the timing of DSP interrupt deviated from time2nextULHISR is with DRIFT_DSP2MCU_US ms.
#define DRIFT_DSP2MCU_DSP_FINE_TUNE (1) //unit ms :allow the timing of DSP interrupt deviated from time2nextULHISR is with DRIFT_DSP2MCU_US ms.
#define DIFF_TX_RX_ALIGN            (2)

#define MARGIN_CORESONIC_INIT_TIME  (3) //unit ms :The length of time of transferring data from PSR to EMAC ,TO-DO, by reception of EMAC, we can adapt this value instead of a fixed value
#define MARGIN_PSR2MAC              (2) //unit ms :The length of time of transferring data from PSR to EMAC ,TO-DO, by reception of EMAC, we can adapt this value instead of a fixed value

resync_info_t resync_info;
bool   SP4G_is_trigger_mac_notify;
bool   SP4G_ul_resync_info_available;
uint32 SP4G_EMACSyncInfoInUse;
#endif



void SP4G_emac_timing_update(l1sp_emac_volte_timing_info_struct* p_timing_info){
#if defined(__SP4G_UL_RESYNC__)
   ilm_resync_info_t *local_para;
   uint32 ctime;
   kal_prompt_trace(MOD_L1SP, "[UL_Sync]SP4G_emac_timing_update");

   local_para = (ilm_resync_info_t *) construct_local_para( sizeof(ilm_resync_info_t), TD_CTRL/*TD_RESET*/ );

   ctime = ust_get_current_time();
         
   local_para->RX_period      = p_timing_info->drx_period ;
   local_para->TX_period      = p_timing_info->sr_period ;
   local_para->time2nextRX    = p_timing_info->time_to_next_on;
   local_para->time2nextTX    = p_timing_info->time_to_trig_sr;
   local_para->issueTime      = ctime;
   
   kal_prompt_trace(MOD_L1SP, "[UL_Sync]SP4G_emac_timing_update: OK");
   
   kal_prompt_trace(MOD_L1SP, "[UL_Sync]SP4G_emac_timing_update drx_period=%x sr_period=%x", 
                                p_timing_info->drx_period,
                                p_timing_info->sr_period
                    );
   kal_prompt_trace(MOD_L1SP, "[UL_Sync]time_to_next_on=%x time_to_trig_sr=%x ctime=%d",                                 
                                p_timing_info->time_to_next_on,
                                p_timing_info->time_to_trig_sr, ctime
                    );
   msg_send6(MOD_EMAC, MOD_MED, AUDIO_SAP, MSG_ID_AUDIO_M2M_VOLTE_MAC_TIMING_INFO, (local_para_struct *)local_para, NULL);
   //sub_SP4G_emac_timing_update(p_timing_info);
#else
   kal_prompt_trace(MOD_L1SP, "[UL_Sync]SP4G_emac_timing_update: skip");
#endif   
} 

#define DIFF_LOCAL(a, b) (((a)>=(b)) ? ((a)-(b)) : ((b)-(a)))
void check_TX_RX_align(void)
{
   if( (resync_info.RX_period>=resync_info.TX_period) && ((resync_info.RX_period%resync_info.TX_period)==0) )
   {
      uint32 u32time2nextTXTemp = resync_info.time2nextTX;
      uint32 u32time2nextRXTemp = resync_info.time2nextRX;

      while(u32time2nextRXTemp < u32time2nextTXTemp)
      {
         u32time2nextRXTemp += resync_info.RX_period;
      }
      kal_prompt_trace(MOD_L1SP, "[UL_Sync]check_TX_RX_align time2nextRX=%d, u32time2nextRXTemp=%d", resync_info.time2nextRX, u32time2nextRXTemp);

      while(1)
      {
         if( DIFF_LOCAL(u32time2nextRXTemp, u32time2nextTXTemp) <= DIFF_TX_RX_ALIGN )
         {
            u32time2nextTXTemp = u32time2nextTXTemp % (MIN(20, resync_info.RX_period));
            resync_info.TX_period   = MIN(20, resync_info.RX_period);
            resync_info.time2nextTX = u32time2nextTXTemp;
            kal_prompt_trace(MOD_L1SP, "[UL_Sync]check_TX_RX_align: OK");
            break;
         }
         if(u32time2nextRXTemp < u32time2nextTXTemp)
         {
            kal_prompt_trace(MOD_L1SP, "[UL_Sync]check_TX_RX_align: fail");
            break;
         }
         u32time2nextTXTemp += resync_info.TX_period;
      }
   }
}

void sub_SP4G_emac_timing_update(ilm_resync_info_t* p_timing_info){
#if defined(__SP4G_UL_RESYNC__)
   uint32 savedMask;
   uint32 u32SoftwareCodecDelay = 0;

   if( L1SP_GetState() != L1SP_STATE_4G_SPEECH_ON)
   {
      savedMask = SaveAndSetIRQMask();
      if( KAL_TRUE == SP4G_is_trigger_mac_notify )
      {
         emac_volte_calloff();
         el1_phs_volte_on(false);
         SP4G_is_trigger_mac_notify = KAL_FALSE;
         SP4G_ul_resync_info_available = KAL_FALSE;
         SP4G_EMACSyncInfoInUse = 0;
		 kal_prompt_trace(MOD_L1SP, "[UL_Sync]emac_volte_calloff at sub_SP4G_emac_timing_update");
      }
      RestoreIRQMask(savedMask);
      return;
   }

   ASSERT(sp4g != (SP4G_Struct*)0);

   if(SP4G_is_trigger_mac_notify == false)
   {
      savedMask = SaveAndSetIRQMask();
      SP4G_ul_resync_info_available = false;
      RestoreIRQMask(savedMask);
      kal_prompt_trace(MOD_L1SP, "[UL_Sync]sub_SP4G_emac_timing_update: return with SP4G_is_trigger_mac_notify=%d", SP4G_is_trigger_mac_notify );
      return;
   }

   savedMask = SaveAndSetIRQMask();
   if(SP4G_EMACSyncInfoInUse == 1)
   {
      RestoreIRQMask(savedMask);
      kal_prompt_trace(MOD_L1SP, "[UL_Sync]sub_SP4G_emac_timing_update: return");
      return;
   }
   else
   {
      if( (p_timing_info->TX_period == 0) || (p_timing_info->time2nextTX > p_timing_info->TX_period) )
      {
         SP4G_ul_resync_info_available = false;
         RestoreIRQMask(savedMask);
         kal_prompt_trace(MOD_L1SP, "[UL_Sync]sub_SP4G_emac_timing_update: return with useless info TX_period=%d, time2nextTX=%d", p_timing_info->TX_period, p_timing_info->time2nextTX);
         return;
      }
      SP4G_EMACSyncInfoInUse = 1;
      sp4g->time[0] = p_timing_info->issueTime;
   }
   RestoreIRQMask(savedMask);
   kal_prompt_trace(MOD_L1SP, "[UL_Sync]sub_SP4G_emac_timing_update: OK");

   resync_info.RX_period      = p_timing_info->RX_period;
   resync_info.TX_period      = p_timing_info->TX_period;
   resync_info.time2nextRX    = p_timing_info->time2nextRX;
   resync_info.time2nextTX    = p_timing_info->time2nextTX;      
   resync_info.issueTime      = p_timing_info->issueTime;

   kal_prompt_trace(MOD_L1SP,   "[UL_Sync]sub_SP4G_emac_timing_update rx=%d tx=%d t2rx=%d t2tx=%d",
                                resync_info.RX_period, resync_info.TX_period, 
                                resync_info.time2nextRX, resync_info.time2nextTX
                    );  

   if(is_g_codec(sp4g->ul_codec_mode))
   {
      switch(sp4g->ul_codec_mode)
      {
          case SP4G_CODEC_G711:
             u32SoftwareCodecDelay = 0;
             break;
          case SP4G_CODEC_G722:
             u32SoftwareCodecDelay = 0;
             break;
          case SP4G_CODEC_G723_1:
             u32SoftwareCodecDelay = 0;
             break;
          case SP4G_CODEC_G726:
             u32SoftwareCodecDelay = 0;
             break;
          case SP4G_CODEC_G729:
             u32SoftwareCodecDelay = 0;
             break;
          default:
             u32SoftwareCodecDelay = 0;
             break;
      }
   }
   else
   {
      u32SoftwareCodecDelay = 0;
   }
   kal_prompt_trace(MOD_L1SP, "[UL_Sync]sub_SP4G_emac_timing_update: codec=%d, u32SoftwareCodecDelay=%d", sp4g->ul_codec_mode, u32SoftwareCodecDelay);

   //TX sync RX. If can sync, modify TX_period and time2nextTX by RX value!!!
   if( (resync_info.RX_period != 0) && (resync_info.time2nextRX <= resync_info.RX_period) )
   {
       check_TX_RX_align();
   }
   kal_prompt_trace(MOD_L1SP,   "[UL_Sync]sub_SP4G_emac_timing_update rx=%d tx=%d t2rx=%d t2tx=%d",
                                resync_info.RX_period, resync_info.TX_period, 
                                resync_info.time2nextRX, resync_info.time2nextTX
                    );  

   //TO-DO
   //TX mx , choose the TX timing for tracking   
   //sp4g->time2nextULHISR = resync_info.time2nextTX - MARGIN_PSR2MAC /*- DRIFT_DSP2MCU_RESET*/;
   sp4g->time2nextULHISR = resync_info.time2nextTX - MARGIN_CORESONIC_INIT_TIME - MARGIN_PSR2MAC - u32SoftwareCodecDelay;

   while(sp4g->time2nextULHISR < 0){      
      sp4g->time2nextULHISR += MIN(resync_info.TX_period, 20);
   }
   kal_prompt_trace(MOD_L1SP,   "[UL_Sync]sub_SP4G_emac_timing_update time2nextULHISR=%d", sp4g->time2nextULHISR);

   //TODO, when SR period is not 1 2 5 10 20 40 80=>we can not do sync!!!
   savedMask = SaveAndSetIRQMask();
   SP4G_ul_resync_info_available = true;
   RestoreIRQMask(savedMask);
   // reading this only in ul_hisr is safety for race condition
#endif     
}


bool is_g_codec(uint8 codec)
{
   if(codec ==  SP4G_CODEC_G711)
      return true;
   if(codec ==  SP4G_CODEC_G722)
      return true;
   if(codec ==  SP4G_CODEC_G723_1)
      return true;
   if(codec ==  SP4G_CODEC_G726)
      return true;
   if(codec ==  SP4G_CODEC_G729)
      return true;    
   return false;         
}


static uint8 sp4g_est_codec_mode;   
static kal_uint32 sp4g_rab_id;
#define SP4G_RAB_ID_MAX (6)
static kal_uint32 sp4g_rab_id_record[SP4G_RAB_ID_MAX]; //valid element: 1~(SP4G_RAB_ID_MAX-1)
static kal_bool   sp4g_rab_state;
static kal_uint32 l1AInfo;
static bool       sp4g_vm_flag;
static kal_uint8  sp4g_reset_flag; // speech on and InterRAT : set TRUE
static kal_bool  sp4g_dtx_mode;
#if defined(__CSHSPA_SUPPORT__)
static kal_uint8  sp4g_max_cs_delay;
#endif

uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );

#define INIT_CODEC (0x3)

static const uint16 RAB_subflow[][4] = {
   {42, 53,  0, 13}, // 4.75
   {49, 54,  0, 14}, // 5.15 
   {55, 63,  0, 15}, // 5.9 
   {58, 76,  0, 18}, // 6.7 
   {61, 87,  0, 19}, // 7.4 
   {75, 84,  0, 21}, // 7.95
   {65, 99, 40, 27}, // 10.2 
   {81, 103,60, 32}, // 12.2
   {39,  0,  0,  5}, // SID  
   {39,  0,  0,  5}, // dummy
   {39,  0,  0,  5}, // dummy
   {39,  0,  0,  5}, // dummy
   {39,  0,  0,  5}, // dummy
   {39,  0,  0,  5}, // dummy
   {39,  0,  0,  5}, // For Future use   
   {8,   0,  0,  0}, // AMR NoData 
#ifdef __AMRWB_LINK_SUPPORT__
/* TS26.201, Table 7 */
   {54,  78, 0, 17},/* WB type 0, AMR-WB 6.60 */
   {64, 113, 0, 23},/* WB type 1, AMR-WB 8.85 */
   {72, 181, 0, 32},/* WB type 2, AMR-WB 12.65 */
   {72, 213, 0, 36},/* WB type 3, AMR-WB 14.25 */
   {72, 245, 0, 40},/* WB type 4, AMR-WB 15.85 */
   {72, 293, 0, 46},/* WB type 5, AMR-WB 18.25 */
   {72, 325, 0, 50},/* WB type 6, AMR-WB 19.85 */
   {72, 389, 0, 58},/* WB type 7, AMR-WB 23.05 */
   {72, 405, 0, 60},/* WB type 8, AMR-WB 23.85 */
   {40,   0, 0,  5}/* WB type 9, AMR-WB SID */
/* WB type 10-13, Not Used */
#endif /*__AMRWB_LINK_SUPPORT__*/       
};


      
static const uint8 RAB_Order[8] = {
   0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01   /* bits order of AMR frame */
};

static const uint16 DSP_Order[16] = {
   0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0080,   /* bits order of SHERIF */
   0x0100,0x0200,0x0400,0x0800,0x1000,0x2000,0x4000,0x8000
};
#ifdef __VIDEO_CALL_SUPPORT__
static const uint8 AMR_IF2_Order[8] = {
   0x10,0x20,0x40,0x80,0x01,0x02,0x04,0x08   /* bits order of AMR IF2 frame */
};

static const uint8 AMR_IF2_FRAME_LENGTH[16] = {/* byte length of AMR IF2 frame */
   13, 14, 16, 18, 19, 21, 26, 31, 6,
   0 ,  0,  0,  0,  0,  0,  1
};
#endif

#ifdef __AMRWB_LINK_SUPPORT__
static const uint8 AmrFrameType2DspMode[25] = {0x0A, 0x09, 0x08, 0x07, 0x06, 
                                        0x05, 0x04, 0x03, 0x00, 0x00,
                                        0x00, 0x00, 0x00, 0x00, 0x00,
                                        0x00, 0x20, 0x21, 0x22, 0x23,
                                        0x24, 0x25, 0x26, 0x27, 0x28};
                                        
                         //**  From          {0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00};                  
                         //**  mapping to
static const uint8 NB_DspMode2AmrFrameType[17]    = {0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00}; 
                         
                         //**  From       {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28};                  
                         //**  mapping to                         
static const uint8 WB_DspMode2AmrFrameType[17] = {0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18}; 

          //**  From               {0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00};                  
          //**  mapping to
static const uint8 NB_DspModeLen[17]    = {0x10, 0x0D, 0x0A, 0x0A, 0x09, 0x08, 0x07, 0x06};
          
          //**  From            {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28};                  
          //**  mapping to                         
static const uint8 WB_DspModeLen[17] = {0x09, 0x0C, 0x10, 0x12, 0x14, 0x17, 0x19, 0x1D, 0x1E};          
#else
static const uint8 AmrFrameType2DspMode[8] = {0xA, 0x9, 0x8, 0x7, 0x6, 0x5, 0x4, 0x3};
static const uint8 NB_DspMode2AmrFrameType[8] = {0x7, 0x6, 0x5, 0x4, 0x3, 0x2, 0x1, 0x0}; 
static const uint8 NB_DspModeLen[8] = {16, 13, 10, 10, 9, 8, 7, 6};
#endif


#ifdef __AMRWB_LINK_SUPPORT__
#define GetFrameType2DspMode(ftype)   (AmrFrameType2DspMode[(ftype)])
#define GetDspMode2FrameType(mode)    (((0x20 <= (mode)) && ((mode) <= 0x28)) ? (WB_DspMode2AmrFrameType[(mode)-0x20]) :         \
                                   (((0x03 <= (mode)) && ((mode) <= 0x0A)) ? (NB_DspMode2AmrFrameType[(mode)-0x03]) : (-1)))   
   
#define GetDspModeLen(mode)        (((0x20 <= (mode)) && ((mode) <= 0x28)) ? (WB_DspModeLen[(mode)-0x20]) :                   \
                                   (((0x03 <= (mode)) && ((mode) <= 0x0A)) ? (NB_DspModeLen[(mode)-0x03]) : (0x00))) 
                                    
#define GetRab2DspMapping(ftype)   (((0x10 <= (ftype)) && ((ftype) <= 0x18)) ? (tblAMR_WBOrder[(ftype) - 0x10]) :               \
                                   (((0x00 <= (ftype)) && ((ftype) <= 0x07)) ? (tblAMROrder[(ftype)-0x00]) : (0)))  
   
   
#else// !defined(__AMRWB_LINK_SUPPORT__)
#define GetFrameType2DspMode(ftype)   (AmrFrameType2DspMode[(ftype)])
#define GetDspMode2FrameType(mode)    (((0x03 <= (mode))  && ((mode)  <= 0x0A)) ? (NB_DspMode2AmrFrameType[(mode)-0x03]) : (-1))   
#define GetDspModeLen(mode)        (((0x03 <= (mode))  && ((mode)  <= 0x0A)) ? (NB_DspModeLen[(mode)-0x03]) : (0x00)) 
#define GetRab2DspMapping(ftype)   (((0x00 <= (ftype)) && ((ftype) <= 0x07)) ? (tblAMROrder[ftype-0x00]) : (0))  
    
#endif

extern const uint8* tblAMROrder[8];

#define AMR_DATA_LOG

#if defined(__L1_STANDALONE__)
void PSR_SP4G_Callback( SP4G_Event event, void *data){}

void PSR_SP4G_Callback( SP4G_Event event, void *data ){}

#else 
extern void PSR_SP4G_Callback( SP4G_Event event, void *data );

extern void PSR_SP4G_Callback( SP4G_Event event, void *data );
#endif

extern uint32 L1I_GetTimeStamp( void );

#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
kal_bool _CS_NeedSpeechExtraLog( void )
{
   return _3g_bNeedExtraLog;
}
#endif

extern void sp4g_vmRecordService( uint32 *l1_info, uint16 crc_result, uint16 buf_status, uint16 *ul_frame_data, uint16* dl_frame_data, kal_bool bBufferOK);

/* SP4G_UpdateL1InFo                                                          */ 
/* called by L1A to update DCH on/off and TX in/off(DCH UL on/off)            */
/* bit 0: DCH on/off (1: on, 0: off)                                          */
/* bit 1: DCH UL on/off (1: on, 0: off)                                       */
/* bit 2: indicate RLF status (1: indicate RLF, 0: reset RLF)                 */
/* bit 3: 3 bits to indicate DCH setup type                                   */
void SP4G_UpdateL1AInFo( kal_uint8 bitmap, kal_uint8 value )
{
   uint32 savedMask;
   
   ASSERT( bitmap <= 3 );
   kal_trace( TRACE_GROUP_SP4G, SP4G_L1A_UPDATE_INFO, bitmap, value);
   savedMask = SaveAndSetIRQMask();
   if( bitmap == 3 ){
      l1AInfo |= (value << 3);
   } else {
      if( value > 0 )
         l1AInfo |= (1 << bitmap);
      else
         l1AInfo &= ~(1 << bitmap);
   }
   RestoreIRQMask(savedMask);
}
extern kal_uint32 SP3G_Rab_Id( void );

kal_uint32 SP4G_GetGCodecMode(void)
{
   return sp4g->ul_codec_mode;

}
kal_bool   SP4G_IsGCodecMode()
{
   return is_g_codec(sp4g->ul_codec_mode);
}

kal_uint32 SP4G_GetCodecMode(void)
{
   if(sp4g != NULL)
       return sp4g->ul_codec_mode;
   else
       return INIT_CODEC;
}

kal_uint32 SP4G_PSR_Link_Est( SP4G_Codec default_speech_codec ) // function call 
{
   kal_int32 i;
   kal_uint8 speech_codec_local = (kal_uint8)default_speech_codec;
   //sp4g_rab_id++;
   //if(sp4g_rab_id > 5)//just want to get unique id without any extra purpose
   //   sp4g_rab_id = 0;

   sp4g_rab_id = 0;
   for(i=1; i<SP4G_RAB_ID_MAX; i++)
   {
      if(sp4g_rab_id_record[i] == 0)
      {
         sp4g_rab_id = i;
         sp4g_rab_id_record[i] = 1;
         break;
      }
   }
   ASSERT(sp4g_rab_id > 0);
      
   SP4G_Rab_Est( sp4g_rab_id, speech_codec_local );   

   kal_prompt_trace(MOD_L1SP, "SP4G_PSR_Link_Est: sp4g_rab_id=%d", sp4g_rab_id);
   return sp4g_rab_id;
}
//CSR inform RAB is established, the rab_id should be set as parameter when callback to CSR
void SP4G_Rab_Est( uint32 rab_id, kal_uint8 default_speech_codec )
{
   sp4g_rab_id    = rab_id;
   sp4g_rab_state = KAL_TRUE;

   sp4g_est_codec_mode = default_speech_codec;
   if( is_g_codec(sp4g_est_codec_mode) == false )
   {
      sp4g_est_codec_mode = GetFrameType2DspMode(sp4g_est_codec_mode);
   }
   if(sp4g != (SP4G_Struct *)NULL)
   {
      sp4g->ul_codec_mode = sp4g_est_codec_mode;//default_speech_codec;
   }
   kal_prompt_trace(MOD_L1SP, "SP4G_Rab_Est: in_codec_mode=%d, real_codec_mode=%d", default_speech_codec, sp4g_est_codec_mode);
   kal_trace( TRACE_GROUP_SP4G, SP4G_RAB_EST,  rab_id, default_speech_codec/*sp4g_est_codec_mode*/); // Notice!! Due to the procedure of PSR, SP4G_Rab_Est must follow SetULFrameType so that sp4g_est_codec_mode has been set properly
   
   kal_take_enh_mutex( sp_handover_mutex );   
   if( L1SP_GetState() == L1SP_STATE_3G_SPEECH_ON ){//
      CSR_SP3G_Callback(SP3G_CODEC_CLOSED, (void*)SP3G_Rab_Id() ); 
      PSR_SP4G_Callback(SP4G_CODEC_READY, (void*)0 );
      SP4G_Reset();
      
      AM_InterRAT_3G_to_4G(SP4G_GetCodecMode());
      
      //fix me , depend on codec
      
      
      L1SP_SetState( L1SP_STATE_4G_SPEECH_ON );
   }else
   if( L1SP_GetState() == L1SP_STATE_2G_SPEECH_ON ){//prepare InterRAT HO      
      PSR_SP4G_Callback(SP4G_CODEC_READY, (void*)0 );
      SP4G_Reset();
      AM_InterRAT_2G_to_4G(SP4G_GetCodecMode());
      
      //fix me , depend on codec
      
      L1SP_SetState( L1SP_STATE_4G_SPEECH_ON );
   }else
   if( L1SP_GetState() == L1SP_STATE_4G_SPEECH_ON ){//prepare InterRAT HO      
      PSR_SP4G_Callback(SP4G_CODEC_READY, (void*)0 );
      SP4G_Reset();
      AM_4G_INTRARAT(SP4G_GetCodecMode());
      
      //fix me , depend on codec
      
      L1SP_SetState( L1SP_STATE_4G_SPEECH_ON );
   }
   kal_give_enh_mutex( sp_handover_mutex );
}

void SP4G_PSR_Link_Deest(kal_uint32 id) // function call 
{
   kal_int32 i;
   kal_uint32 sp4g_rab_id_total;
   kal_trace( TRACE_GROUP_SP4G, SP4G_RAB_DEEST, id );
   //ASSERT(id == sp4g_rab_id);
   ASSERT(sp4g_rab_id_record[id] == 1);

   sp4g_rab_id_record[id] = 0;
   sp4g_rab_id_total = 0;
   for(i=1; i<SP4G_RAB_ID_MAX; i++)
   {
      sp4g_rab_id_total |= sp4g_rab_id_record[i];
   }
   if(sp4g_rab_id_total == 0)
   {
      sp4g_rab_state      = KAL_FALSE;
      sp4g_est_codec_mode = INIT_CODEC;
   }

   kal_prompt_trace(MOD_L1SP, "SP4G_PSR_Link_Deest: sp4g_rab_state=%d", sp4g_rab_state);

   kal_take_enh_mutex( sp_handover_mutex );
   if( SP3G_Rab_State() && L1SP_GetState() != L1SP_STATE_3G_SPEECH_ON && L1SP_GetState() != L1SP_STATE_IDLE ){//4G->3G 
      PSR_SP4G_Callback(SP4G_CODEC_CLOSED, (void*)0 );  
      CSR_SP3G_Callback(SP3G_CODEC_READY, (void*)SP3G_Rab_Id() ); 
      AM_InterRAT_4G_to_3G(SP4G_GetCodecMode());
      L1SP_SetState( L1SP_STATE_3G_SPEECH_ON );
   }else
   if( L1SP_TCH_State() && L1SP_GetState() != L1SP_STATE_2G_SPEECH_ON && L1SP_GetState() != L1SP_STATE_IDLE ){//4G->2G
      PSR_SP4G_Callback(SP4G_CODEC_CLOSED, (void*)0 );
      AM_InterRAT_4G_to_2G();
      L1SP_SetState( L1SP_STATE_2G_SPEECH_ON );
   }
   kal_give_enh_mutex( sp_handover_mutex );
}

kal_bool SP4G_Rab_State( void )
{
   return sp4g_rab_state;
}

kal_uint32 SP4G_Rab_Id( void )
{
   return sp4g_rab_id;
}

void SP4GHSPA_UL_GetSpeechFrame_Loop(kal_uint8 *frame_type, kal_uint8 *rab_byte_array, kal_uint8 *len)
{
   kal_uint16 frame_index, I, J, K, rabBitsCount;
   kal_uint8  *ptr8, *ptr8_swap, byte_swap, bit8Data;

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
#else
//#if 1
   SP4G_UL_GetSpeechFrame(&frame_index, frame_type, rab_byte_array, len);
   //reorder to AMR IF1
   if( *frame_type != AMR_NO_DATA && *frame_type != 25 && *frame_type != AMR_SID_FRAME )
   {
      ptr8 = rab_byte_array;
      ptr8_swap = rab_byte_array;
      byte_swap = *ptr8_swap;
      *ptr8 = 0;
      K = 0;
      for( I = 0 ; I < 3 ; I++ ){
         rabBitsCount = RAB_subflow[*frame_type][I];
         for( J = 0; J < rabBitsCount ; J++, K++ ){
            bit8Data = (byte_swap & RAB_Order[J & 7])? RAB_Order[K & 7] : 0; 
            *ptr8 |= bit8Data;
            if( (J&7) == 7 ){
               ptr8_swap++;
               byte_swap = *ptr8_swap;
            }
            if( (K&7) == 7 ){
               ptr8++;
               *ptr8 = 0;
            }
         }
         if( (J&7) != 0 ){ // avoid false advance a byte
            ptr8_swap++;
            byte_swap = *ptr8_swap;
         }
      }
      //recalculate rab length
      rabBitsCount = 0;
      for( I = 0 ; I < 3 ; I++ )
         rabBitsCount += RAB_subflow[*frame_type][I];
      *len = ((rabBitsCount+7)>>3);
   }
#endif   
   kal_trace( TRACE_GROUP_SP4G, SP4G_HSPA_UL_GET_SPEECH_FRAME, *frame_type, *len, rab_byte_array[0], rab_byte_array[1] );
}

void SP4GHSPA_DL_PutSpeechFrame_Loop(kal_uint32 CFN, kal_uint8 frame_type, kal_bool crc_status, kal_uint8 *subflow)
{
   kal_trace( TRACE_GROUP_SP4G, SP4G_HSPA_DL_PUT_SPEECH_FRAME, frame_type, CFN, crc_status, subflow[0],subflow[1]);
   if( frame_type != AMR_NO_DATA && frame_type != 25 && frame_type != AMR_SID_FRAME ){
      kal_uint16 I, J, K, rabBitsCount;
      kal_uint8  *ptr8, *ptr8_swap, byte_swap, bit8Data;
      
      K = 0;
      ptr8_swap = subflow;
      byte_swap = *ptr8_swap;
      for( I = 0 ; I < 3 ; I++ ){
         rabBitsCount = RAB_subflow[frame_type][I];
         if( rabBitsCount == 0 )
            break;
         ptr8 = &sp4g->dl_subflow[0];
         *ptr8 = 0;//reset
         for( J = 0; J < rabBitsCount ; J++, K++ ){
            bit8Data = (byte_swap & RAB_Order[K & 7])? RAB_Order[J & 7] : 0; 
            *ptr8 |= bit8Data;
            if( (J&7) == 7 ){
               ptr8++;
               *ptr8 = 0;
            }
            if( (K&7) == 7 ){
               ptr8_swap++;
               byte_swap = *ptr8_swap;
            }
         }
         SP4G_DL_PutSpeechFrame(CFN, I, frame_type, crc_status, sp4g->dl_subflow);
      }
   } else {
      SP4G_DL_PutSpeechFrame(CFN, 0, frame_type, crc_status, subflow);
   }
}

void SP4G_GetSyncDelayRW( kal_uint16 *u16DelayR, kal_uint16 *u16DelayW)
{
#if defined(__SP4G_UL_RESYNC__)  
   if( sp4g_reset_flag != 1  && SP4G_ul_resync_info_available){
      uint32 ctime = sp4g->time[1] = ust_get_current_time();
      int32  time2nextULHISR = sp4g->time2nextULHISR;
      int32  time_emac_to_here ;//= ust_get_duration_true(sp4g->time[0], ctime) / 1000;
      if(ctime > sp4g->time[0]){
         time_emac_to_here = (ctime - sp4g->time[0])/1000;  
      }else{
         time_emac_to_here = (USCNT_WRAP - sp4g->time[0] + ctime)/1000;
      }
      //may assert in LISR
      kal_prompt_trace(MOD_L1SP, "[UL_Sync] SP4G_GetSyncDelayRW.1 ctime = %d time2nextULHISR = %d time_emac_to_here= %d", 
                                 ctime,time2nextULHISR, time_emac_to_here                                 
                                 );
      
      while(time_emac_to_here > time2nextULHISR){
         time2nextULHISR += MIN(resync_info.TX_period, 20);
      }        
      kal_prompt_trace(MOD_L1SP, "[UL_Sync] SP4G_GetSyncDelayRW.2 time2nextULHISR = %d TX_period= %d", 
                                 time2nextULHISR, resync_info.TX_period                                 
                                 );      
      {
         int32 tmp = (time2nextULHISR - time_emac_to_here)/DSP_PERIOD;
         int32 time2nextDSPSD =  ( time2nextULHISR - time_emac_to_here ) - tmp * DSP_PERIOD;
         
         kal_prompt_trace(MOD_L1SP, "[UL_Sync] SP4G_GetSyncDelayRW.3 tmp = %d time2nextDSPSE= %d", 
                                 tmp, time2nextDSPSD
                                 );

         while(time2nextDSPSD< DSP_SE_MIPS)
         {
            time2nextDSPSD += MIN(resync_info.TX_period, 20);
         }
         *u16DelayW = (time2nextDSPSD - DSP_SD_MIPS) * 8;  //SD
         *u16DelayR = (time2nextDSPSD - DSP_SE_MIPS) * 8;  //SE
         kal_prompt_trace(MOD_L1SP, "[UL_Sync] SP4G_GetSyncDelayRW.4 R = %d W= %d",
                                    *u16DelayR, *u16DelayW
                           );
      }
      SP4G_EMACSyncInfoInUse = 0;
   }else
#endif      
   {
      kal_uint8  defaultR, defaultW;
      /*if((sp4g->ul_codec_mode >= 0x20) && (sp4g->ul_codec_mode <= 0x28)){      
      	  defaultW = 26;
      	  defaultR = 31;      
      }else{
      	  defaultW = 30;
      	  defaultR = 0;
      }*/
      defaultW = 26;
      defaultR = 31;
      *u16DelayW = defaultW * 8;
      *u16DelayR = defaultR * 8; //refer to am.c DSP_PCM_IDLE_DELAY_TABLE[6]      
   }
}

void sp4g_hisr_ul_amr(void *data)
{
   int32 I, J = 0, K;
   uint16 *ptr16;
   uint16 tx_type, sc_mode;
   uint8 *ptr8;
   uint8 len;
   const uint8* RAB_To_DSP_Mapping;
   uint16 total_bits, idx, rabBitsCount;
   uint8 frame_type = 0,bit8Data;  
   bool bWrite;
   
 
 
    
   if(L1SP_GetState() == L1SP_STATE_4G_SPEECH_CLOSING) 
      return; 
   if(is_g_codec(sp4g->ul_codec_mode))   
      return;
            
   ASSERT(sp4g != (SP4G_Struct*) 0);                          

#if defined(__SP4G_UL_RESYNC__)   
   kal_prompt_trace(MOD_L1SP, "[UL_Sync]sp4g_hisr_ul_amr.0 mac_notify %d codec_mute=%d SP4G_ul_resync_info_available=%d", 
                              SP4G_is_trigger_mac_notify,
                              SP_is_codec_mute(), SP4G_ul_resync_info_available
                             );
    
   if(!SP4G_is_trigger_mac_notify && !SP_is_codec_mute()){
      kal_prompt_trace(MOD_L1SP, "debug sp4g_hisr_ul_amr emac_volte_callon");   
      emac_volte_callon(20);  
      el1_phs_volte_on(true);
      SP4G_is_trigger_mac_notify = KAL_TRUE;
      SP4G_ul_resync_info_available = KAL_FALSE;
      SP4G_EMACSyncInfoInUse = 0;
   }else if(SP4G_is_trigger_mac_notify && SP_is_codec_mute()){
      kal_prompt_trace(MOD_L1SP, "debug sp4g_hisr_ul_amr emac_volte_calloff");   
      emac_volte_calloff();  
      el1_phs_volte_on(false);
      SP4G_is_trigger_mac_notify = KAL_FALSE;
      SP4G_ul_resync_info_available = KAL_FALSE;
      SP4G_EMACSyncInfoInUse = 0;
   }
   
   if( (SP4G_ul_resync_info_available) && (SP4G_is_trigger_mac_notify) ){
      static kal_uint32 time_request_resync = 0;   
      uint32 ctime = sp4g->time[2] = ust_get_current_time();
      uint32 time_emac_2_ulhisr;// = ust_get_duration_true( ctime, sp4g->time[0] ) / 1000;
      uint32 time_diff_request_resync;
      uint32 diff, diff_mod, diff_mod2;
      uint32 tx_period_min = MIN(resync_info.TX_period, 20);

      if(ctime > sp4g->time[0]){
         time_emac_2_ulhisr = (ctime - sp4g->time[0])/1000;
      }else{
         time_emac_2_ulhisr = ((USCNT_WRAP - (sp4g->time[0]) - (ctime)))/1000;   
      }
      
      
      kal_prompt_trace(MOD_L1SP, "[UL_Sync]sp4g_hisr_ul_amr.1 ctime = %d time[0] = %d time_emac_2_ulhisr = %d",
                                 ctime, sp4g->time[0], time_emac_2_ulhisr
                       );
      
       
      diff = (time_emac_2_ulhisr > sp4g->time2nextULHISR ) ? (time_emac_2_ulhisr - sp4g->time2nextULHISR) : (sp4g->time2nextULHISR - time_emac_2_ulhisr);
      diff_mod = diff % tx_period_min;
      kal_prompt_trace(MOD_L1SP, "[UL_Sync]sp4g_hisr_ul_amr.2 time_emac_2_ulhisr = %d sp4g->time2nextULHISR = %d",
                                 time_emac_2_ulhisr, sp4g->time2nextULHISR
                      );
      kal_prompt_trace(MOD_L1SP, "[UL_Sync]sp4g_hisr_ul_amr.2-1 diff = %d  diff_mod = %d tx_period_min = %d",
                                 diff, diff_mod, tx_period_min
                      );
      /*if(resync_info.TX_period < 20)
      {
         while(1)
         {
            if( (diff_mod+resync_info.TX_period) <= 20 )
            {
               diff_mod += resync_info.TX_period;
            }
            else
            {
               break;
            }
         }
      }
      kal_prompt_trace(MOD_L1SP, "[UL_Sync]sp4g_hisr_ul_amr.2-1 adjust diff_mod = %d with resync_info.TX_period = %d",
                                 diff_mod, resync_info.TX_period
                      );*/
      diff_mod2 = diff_mod;
      if( (diff_mod+DRIFT_DSP2MCU_RESET) >= tx_period_min )
      {
         diff_mod = tx_period_min - diff_mod;
      }
      kal_prompt_trace(MOD_L1SP, "[UL_Sync]sp4g_hisr_ul_amr.2-2 adjust diff_mod = %d with DRIFT_DSP2MCU_RESET = %d",
                                 diff_mod, DRIFT_DSP2MCU_RESET
                      );
      if( (diff_mod2+DRIFT_DSP2MCU_DSP_FINE_TUNE) >= tx_period_min )
      {
         diff_mod2 = tx_period_min - diff_mod2;
      }
      kal_prompt_trace(MOD_L1SP, "[UL_Sync]sp4g_hisr_ul_amr.2-2 adjust diff_mod2 = %d with DRIFT_DSP2MCU_DSP_FINE_TUNE = %d",
                                 diff_mod2, DRIFT_DSP2MCU_DSP_FINE_TUNE
                      );

      //time_diff_request_resync = ust_get_duration_true( time_request_resync, ctime ) / 1000;
      if(ctime > time_request_resync){
         time_diff_request_resync = ( ctime - time_request_resync ) / 1000;
      }else{
         time_diff_request_resync = ( USCNT_WRAP - ctime + time_request_resync) / 1000;
      }
      
      kal_prompt_trace(MOD_L1SP, "[UL_Sync]sp4g_hisr_ul_amr.3 t_req_resync = %d ctime = %d tdiff_req_resync = %d, ul_req_resync = %d",
                                 time_request_resync, ctime, time_diff_request_resync, sp4g->ul_request_resync
                      );
      
      kal_prompt_trace(MOD_L1SP, "[UL_Sync]sp4g_hisr_ul_amr.4 %d %d %d", 
                                  diff_mod >= DRIFT_DSP2MCU_RESET,(sp4g->ul_request_resync == KAL_FALSE),
                                  (time_diff_request_resync > 200)
      );

      if( (diff_mod2 >= DRIFT_DSP2MCU_DSP_FINE_TUNE) && (diff_mod < DRIFT_DSP2MCU_RESET) )
      {
         //TODO, let Speech DSP to do fine tune.
         ;
      }

      if( 
           (diff_mod >= DRIFT_DSP2MCU_RESET) &&
           (sp4g->ul_request_resync == KAL_FALSE) &&
           (time_diff_request_resync > 200)
         ){
            sp4g_reset_flag = 1;
            time_request_resync = ctime;
            sp4g->ul_request_resync = KAL_TRUE;      
            kal_prompt_trace(MOD_L1SP, "[UL_Sync]sp4g_hisr_ul_amr.5 UL sync start");   
         }
      else
      {
         SP4G_EMACSyncInfoInUse = 0;
      }
   }
#endif

   sp4g->ul_report = SAL_3G_GetValue(SAL_3G_VALUE_TX_CODEC_MODE);

   /*for catcher log codec information*/
   if( sp4g->ul_report != sp4g->pre_ul_report ){
      L1Audio_Msg_SPEECH_CODEC( L1SP_Speech_Codec_Mode(sp4g->ul_report), L1SP_Speech_Codec_Mode(sp4g->dl_report) );
      sp4g->pre_ul_report = sp4g->ul_report;
   }




      
   // UL side    
   ptr16 = (uint16*)sp4g->dsp_buffer;
   {
      // get data from DSP UL buffer
      volatile uint16 *addr;
      tx_type = SAL_3G_GetValue(SAL_3G_VALUE_TX_TYPE);
      sc_mode =  sp4g->ul_report;
#ifdef __AMRWB_LINK_SUPPORT__
      if( sc_mode < 0x03 || sc_mode > 0x28 )
#else      
      if( sc_mode < 0x03 || sc_mode > 0x0A )
#endif         
      {
         kal_dev_trace(TRACE_GROUP_SP4G, SP4G_INVALID_UL_CODEC_MODE, sc_mode);
         tx_type = SAL_3G_TX_NO_DATA;
         sc_mode = 3;
      }
      addr = SAL_3G_GetAddr(SAL_3G_ADDR_TXHB);
 	  for(I = GetDspModeLen(sc_mode); --I >= 0 ; )
         *ptr16++ = *addr++;
   }  
   
   // do bit re-ordering  
   ptr16 = (uint16*)sp4g->dsp_buffer;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   if (_3g_bNeedExtraLog == true){
      ptr16 = (uint16*)sp4g->dsp_buffer;
      //kal_prompt_trace(MOD_L1SPHISR,"SP4GHISR UL DSP len %d, %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x",
      //      DspModeLen[sc_mode - 3], ptr16[0], ptr16[1], ptr16[2], ptr16[3], ptr16[4], ptr16[5], ptr16[6], ptr16[7], 
      //      ptr16[8], ptr16[9], ptr16[10], ptr16[11], ptr16[12], ptr16[13], ptr16[14], ptr16[15]);
      kal_dev_trace(TRACE_GROUP_SP4G, SP4G_UL_BIT_TRUE_DSP_F8, 
       	      GetDspModeLen(sc_mode), ptr16[0], ptr16[1], ptr16[2], ptr16[3], ptr16[4], ptr16[5], ptr16[6], ptr16[7]);
      kal_dev_trace(TRACE_GROUP_SP4G, SP4G_UL_BIT_TRUE_DSP_N8,
            ptr16[8], ptr16[9], ptr16[10], ptr16[11], ptr16[12], ptr16[13], ptr16[14], ptr16[15]);
            
   }
#endif
   ptr8 = (uint8*)sp4g->ul_buffer[sp4g->ul_write_idx];
   
   bWrite = KAL_FALSE;
   
   if(SAL_3G_IsULReady()){//DSP tell MCU the data of DSP is ready
      if( sp4g->ul_count < sp4g->ul_buffer_size ){
         bWrite = KAL_TRUE;
      }
      if( sp4g->ul_count == sp4g->ul_buffer_size ){
         if( sp4g->is_getting_ul_data ){
            bWrite = KAL_FALSE;
         }else{
            sp4g->ul_read_idx++;          //drop oldest frame
            sp4g->ul_count--;
            bWrite = KAL_TRUE;
            if( sp4g->ul_read_idx == sp4g->ul_buffer_size )
               sp4g->ul_read_idx = 0;
         }
      }
      SAL_3G_SetULEmpty();
   }else{//DSP tell MCU the data of DSP is not ready
      //We should not modify sp4g->ul_report, but this case is error handling.
      sp4g->ul_report = sp4g->ul_codec_mode;
      sc_mode = sp4g->ul_report;
      AM_FillSilencePatternInBuffer( ptr16, sp4g->ul_report );
      tx_type = SAL_3G_TX_SPEECH_GOOD;
      bWrite = KAL_TRUE;
      kal_brief_trace(TRACE_GROUP_SP4G, SP4G_UL_DSP_NOT_READY_WARNING_AND_FILL_SILENCE);
      kal_dev_trace(TRACE_GROUP_SP4G, SP4G_UL_BIT_TRUE_DSP_F8, 
              GetDspModeLen(sc_mode), ptr16[0], ptr16[1], ptr16[2], ptr16[3], ptr16[4], ptr16[5], ptr16[6], ptr16[7]); 
   }

   if( bWrite ){
      frame_type = GetDspMode2FrameType(sc_mode);
      switch(tx_type)
      {
         case SAL_3G_TX_SPEECH_GOOD:
            if( sp4g->sp4g_mode == RAT_4G_MODE ){
               *ptr8++ = frame_type;
               len = RAB_subflow[frame_type][3];
               *ptr8++ = len;  
#ifdef __AMRWB_LINK_SUPPORT__
               if(frame_type >= 0x10) //AMR-WB
                  RAB_To_DSP_Mapping = (const uint8 *)tblAMR_WBOrder[frame_type-0x10];
               else
#endif
                  RAB_To_DSP_Mapping = tblAMROrder[frame_type];

               // do bit reorder , move speech information bits to rab_byte_array
               total_bits = RAB_subflow[frame_type][0] + RAB_subflow[frame_type][1] + RAB_subflow[frame_type][2];
               
               for(I = len; --I >= 0; *ptr8++ = 0);
                           
               for(idx = 0, ptr8 -= len, I = 0; I < 3; I ++){
                  rabBitsCount = RAB_subflow[frame_type][I];
                  
                  if( frame_type >= 16 ){
                     const uint16* WB_RAB_To_DSP_Mapping;
                     WB_RAB_To_DSP_Mapping = (const uint16*)RAB_To_DSP_Mapping;
                     for(J = 0; J < rabBitsCount; J++)
                     {
                        K = WB_RAB_To_DSP_Mapping[idx++];
                        bit8Data = (ptr16[K >> 4] & DSP_Order[K & 15])? RAB_Order[J & 0x7] : 0; 
                        ptr8[J >> 3] |= bit8Data;
                     }
                  } else {
                     for(J = 0; J < rabBitsCount; J++)
                     {
                        K = RAB_To_DSP_Mapping[idx++];
                        bit8Data = (ptr16[K >> 4] & DSP_Order[K & 15])? RAB_Order[J & 0x7] : 0; 
                        ptr8[J >> 3] |= bit8Data;
                     }
                  }
                  ptr8 += (rabBitsCount + 7) >> 3; 
               }    
            
               ASSERT(idx == total_bits);
            }
#ifdef __VIDEO_CALL_SUPPORT__
            else{
               len = AMR_IF2_FRAME_LENGTH[frame_type]; //frame length
               *ptr8++ = len;
               RAB_To_DSP_Mapping = tblAMROrder[frame_type]; 
               total_bits = RAB_subflow[frame_type][0] + RAB_subflow[frame_type][1] + RAB_subflow[frame_type][2];
               
               for(I = len; --I >= 0  ; )
                  *ptr8++ = 0;
               idx = 0;
               ptr8 -= len;
               // do bit reorder , first byte contains frame_type
               *ptr8 = frame_type;
               I = 4;
               for(J = 0; J < total_bits; J++,I++)
               {
                  K = RAB_To_DSP_Mapping[idx++];
                  bit8Data = (ptr16[K >> 4] & DSP_Order[K & 15])? AMR_IF2_Order[J & 0x7] : 0; 
                  ptr8[I >> 3] |= bit8Data;
               }
            }
#endif
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
            //kal_prompt_trace(MOD_L1SPHISR,"SP4G_HISR UL is TX_SPEECH_GOOD");
            kal_dev_trace(TRACE_GROUP_SP4G, SP4G_TX_SPEECH_GOOD);
#endif
            break;
         case SAL_3G_TX_SID_FIRST: 
            if( sp4g->sp4g_mode == RAT_4G_MODE ){
#ifdef __AMRWB_LINK_SUPPORT__
               if( sp4g->ul_report >= 0x20 ) 
                  *ptr8++ = WB_AMR_SID_FRAME;//WB SID
               else
#endif                           	
               *ptr8++ = AMR_SID_FRAME;
               *ptr8++ = 5;
               for(I = 4; --I >= 0; )
                  *ptr8++ = 0;
#ifdef __AMRWB_LINK_SUPPORT__
               if( sp4g->ul_report >= 0x20 )
                  *ptr8 = (uint8)(sp4g->ul_report - 0x20);
               else
#endif               
               *ptr8 = (uint8)(frame_type << 1);
         #ifdef AMR_DATA_LOG
               ptr8 -= 6;
               kal_dev_trace( TRACE_GROUP_SP4G, SP4G_TX_SID_FIRST );
         #endif 
            }
#ifdef __VIDEO_CALL_SUPPORT__
            else{//4G 324M
               *ptr8++ = 6;//frame length
               for(I = 5; --I >= 0; )
                  *ptr8++ = 0;
               *ptr8 = (uint8)(frame_type);
               ptr8 -= 5;
               *ptr8 |= AMR_SID_FRAME;
            }
#endif
            break;
         case SAL_3G_TX_SID_UPDATE:
            if( sp4g->sp4g_mode == RAT_4G_MODE ){
#ifdef __AMRWB_LINK_SUPPORT__
               if( sp4g->ul_report >= 0x20 )
                  *ptr8++ = WB_AMR_SID_FRAME;//WB SID
               else
#endif      	
               *ptr8++ = AMR_SID_FRAME;
               *ptr8++ = 5;
               // do bit reorder , move sid information bits to rab_byte_array
               for(I = 5; --I >= 0; )
                  *ptr8++ = 0;  
      
               ptr8 -= 5;
               for(I = 0; I < 35; I ++)
               {
                  bit8Data = (ptr16[I >> 4] & DSP_Order[I & 15])? RAB_Order[I & 0x7] : 0; 
                  ptr8[I >> 3] |= bit8Data;
               }
               frame_type = (frame_type >> 2) | ((frame_type & 0x1) << 2) | (frame_type & 0x2);
#ifdef __AMRWB_LINK_SUPPORT__
               if( sp4g->ul_report >= 0x20 )
                  ptr8[4] |= (uint8)(sp4g->ul_report - 0x20)|0x10;
               else
                  ptr8[4] |= (uint8)(frame_type << 1)|0x10; 
#else          
               ptr8[4] |= (uint8)(frame_type << 1)|0x10;        
#endif                     
               
         #ifdef AMR_DATA_LOG
               ptr8 -= 2;
               kal_dev_trace( TRACE_GROUP_SP4G, SP4G_TX_SID_UPDATE );
         #endif
            }
#ifdef __VIDEO_CALL_SUPPORT__
            else{//4G 324M
               *ptr8++ = 6;//frame length
               for(I = 5; --I >= 0; )
                  *ptr8++ = 0;
               *ptr8 = (uint8)(frame_type);
               ptr8 -= 5;
               *ptr8 |= AMR_SID_FRAME;
               J = 4;
               for(I = 0; I < 35; J++, I++)
               {
                  bit8Data = (ptr16[I >> 4] & DSP_Order[I & 15])? AMR_IF2_Order[I & 0x7] : 0; 
                  ptr8[J >> 3] |= bit8Data;
               }
               ptr8[4] |= 0x80;
            }
#endif
            break;
         case SAL_3G_TX_NO_DATA:
            if( sp4g->sp4g_mode == RAT_4G_MODE ){
               *ptr8++ = AMR_NO_DATA;
               *ptr8++ = 0;
            }
#ifdef __VIDEO_CALL_SUPPORT__
            else{//4G324M
               *ptr8++ = 1;
               *ptr8++ = AMR_NO_DATA;
            }
#endif
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
            //kal_prompt_trace(MOD_L1SPHISR,"SP4G_HISR UL is NO DATA");
            kal_dev_trace(TRACE_GROUP_SP4G, SP4G_UL_NO_DATA);
#endif
            break;
         default:
            ASSERT(false);
            break;
      }
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      if (_3g_bNeedExtraLog == true){
	      //kal_prompt_trace(MOD_L1SPHISR,"SP4G_HISR UL Type %d, Frm %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x",
	      //   tx_type, ptr8[0], ptr8[1],ptr8[2],ptr8[3],ptr8[4],
	      //   ptr8[5],ptr8[6],ptr8[7],ptr8[8],ptr8[9],ptr8[10],ptr8[11],ptr8[12],ptr8[13],ptr8[14],ptr8[15], ptr8[16],ptr8[17],ptr8[18],ptr8[19],ptr8[20]);
	      uint8 *tmp_ = (uint8*)sp4g->ul_buffer[sp4g->ul_write_idx];
	      kal_prompt_trace(MOD_L1SP, "#debug_ul_buff(6) %d ", sp4g->ul_write_idx);
	      kal_dev_trace(TRACE_GROUP_SP4G, SP4G_UL_BIT_TRUE_F8,
	         1, tx_type, tmp_[0], tmp_[1],tmp_[2],tmp_[3],tmp_[4],tmp_[5],tmp_[6],tmp_[7]);
	      kal_dev_trace(TRACE_GROUP_SP4G, SP4G_UL_BIT_TRUE_N13,
	         tmp_[8],tmp_[9],tmp_[10],tmp_[11],tmp_[12],tmp_[13],tmp_[14],tmp_[15], 
	         tmp_[16],tmp_[17],tmp_[18],tmp_[19],tmp_[20]);
      }
#endif
   }
   
   if( sp4g->ul_refresh && (sp4g->ul_intrarat == KAL_FALSE) )
   {
      if((sp4g->ul_report <= 0x0A && sp4g->ul_codec_mode >= 0x20) || //WB, NB handover
         (sp4g->ul_report >= 0x20 && sp4g->ul_codec_mode <= 0xA)){
         ASSERT(0);
      }else if(sp4g->ul_report != sp4g->ul_codec_mode ){
		  SAL_3G_Upd_Enc_Cod(sp4g->ul_codec_mode);
      }
      sp4g->ul_refresh = KAL_FALSE;
   }
   sp4g->ul_intrarat == KAL_FALSE;

   if( bWrite ){
      sp4g->ul_write_idx++;
      if( sp4g->ul_write_idx == sp4g->ul_buffer_size )
         sp4g->ul_write_idx = 0;
      sp4g->ul_count++;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      if (_3g_bNeedExtraLog == true) {
         //kal_prompt_trace(MOD_L1SPHISR,"SP4GVT UL cnt=%d,r=%d,w=%d",sp4g->ul_count,sp4g->ul_read_idx,sp4g->ul_write_idx);
         kal_dev_trace(TRACE_GROUP_SP4G, SP4G_UL_BUFFER, sp4g->ul_count,sp4g->ul_read_idx,sp4g->ul_write_idx);
      }
#endif
      if( sp4g->sp4g_mode == RAT_4G_MODE && sp4g->ul_delay > START_SHRINK_UL_DELAY && !sp4g->is_getting_ul_data){
         sp4g->ul_read_idx++;
         if( sp4g->ul_read_idx == sp4g->ul_buffer_size )
            sp4g->ul_read_idx = 0;
         if(sp4g->ul_count > 1)
            sp4g->ul_count--;
      }//when ul write updated, check ul_delay. keep newest one
   }

   if(SP_is_codec_mute())
   {
      if(KAL_TRUE == SP4G_Rab_State())
      {
   	     PSR_SP4G_Callback( SP4G_UL_MUTE_NOTIFY, (void*)0 );
   	     kal_trace( TRACE_GROUP_SP4G, SP4G_UL_SKIP_NOTIFY);
   	  }
   }
   else
   {   
      if( sp4g->waiting == KAL_FALSE ){
         sp4g->waiting = KAL_TRUE;
         if( sp4g->sp4g_mode == RAT_4G_MODE ){		      	 
         PSR_SP4G_Callback( SP4G_UL_DATA_NOTIFY, (void*)0 );		         
      }   		         
      }else{
         sp4g->ul_delay ++; 
         if( sp4g->sp4g_mode == RAT_4G_MODE )
            PSR_SP4G_Callback(SP4G_UL_DATA_DEALY_TICK, (void *)(kal_uint32)sp4g->ul_delay);
            kal_dev_trace( TRACE_GROUP_SP4G, SP4G_UL_DELAY, sp4g->ul_delay );
            #if 0
/* under construction !*/
            #endif
      }
   }
}



void SP4G_SetCodec(int c)
{
   if( L1SP_GetState() != L1SP_STATE_4G_SPEECH_ON){
         return;
   } 
      
   if(is_g_codec(c)){   
   	  if(c == sp4g->ul_codec_mode){
   	  	 kal_prompt_trace(MOD_L1SP, "[SP4G]SetCodec is equal %x", c);
   	     return;	
   	  }
      sp4g->ul_codec_mode = c;
      AM_4G_INTRARAT(c);
      SP4G_Reset();         
   }else{
      SP4G_UL_SetFrameType(c);
   }
}

//void SP4G_SetWaiting(bool b)
//{
//    sp4g->waiting = b;
//}  

   

typedef struct {
   int magicid;
   int codec;
   int len;
}frame_header_t;

extern kal_enhmutexid sp4g_dl_mutex;
extern kal_enhmutexid sp4g_ul_mutex;

#if defined(__G_CODEC_SUPPORT__)
int PSR_GetFrame(int16* c, int16* len, uint8* tmp_buf);
void PSR_PutFrame(int c, int encoded_len, uint8* encoded_bits);
#endif


/*
law:
    1: G711_ALAW
    2: G711_ULAW
dec_init_CNG_enable:
    0: disable (default)
    1: enable
*/
void SP4G_Set_G711Parameters(kal_int32 law, kal_int32 dec_init_CNG_enable)
{
#if defined(__G_CODEC_SUPPORT__)
   if( (law != G711_ALAW) && (law != G711_ULAW) )
   {  
      kal_prompt_trace(MOD_L1SP, "SP4G_Set_G711Parameters input law is out of range(1~2): %d", law);
      ASSERT(0);
   }
   enc_init_param_g711.law = law;
   dec_init_param_g711.law = law;

   if( (dec_init_CNG_enable != 0) && (dec_init_CNG_enable != 1) )
   {   
      kal_prompt_trace(MOD_L1SP, "SP4G_Set_G711Parameters input dec_init_CNG_enable is out of range(0~1): %d", dec_init_CNG_enable);
      ASSERT(0);
   }
   dec_init_param_g711.CNG_enable = dec_init_CNG_enable;
/*
G711_Enc_Init_Param       enc_init_param_g711;   
G711_LAW law;
int VAD_enable;
G711_Dec_Init_Param       dec_init_param_g711;   
G711_LAW law;
int CNG_enable;
G711_Dec_Runtime_Param dec_rtime_param_g711;
int ENH_enable;
int BFI;
*/
#endif //#if defined(__G_CODEC_SUPPORT__)
}

void SP4G_PSR_UL_GSeries_GetSpeechFrame(SP4G_Codec *codec, kal_uint8 *encodebits, kal_uint8 *bitlen)
{
#if defined(__G_CODEC_SUPPORT__)
   kal_prompt_trace(MOD_L1SP, "SP4G_PSR_UL_GSeries_GetSpeechFrame");
   PSR_GetFrame((int16 *)codec, (int16 *)bitlen, (uint8 *)encodebits);
   kal_prompt_trace(MOD_L1SP, "SP4G_PSR_UL_GSeries_GetSpeechFrame: codec=%x, encodebits=%02x%02x%02x%02x, bitlen=%x", *codec, encodebits[0], encodebits[1], encodebits[2], encodebits[3], *bitlen);
#endif
}

void SP4G_PSR_DL_GSeries_PutSpeechFrame(SP4G_Codec codec, kal_uint8 *encodebits, kal_uint8 *bitlen)
{
#if defined(__G_CODEC_SUPPORT__)
   kal_prompt_trace(MOD_L1SP, "SP4G_PSR_DL_GSeries_PutSpeechFrame");
   PSR_PutFrame((int)codec, (int)(*bitlen), (uint8 *)encodebits);
   kal_prompt_trace(MOD_L1SP, "SP4G_PSR_DL_GSeries_PutSpeechFrame: codec=%x, encodebits=%02x%02x%02x%02x, bitlen=%x", codec, encodebits[0], encodebits[1], encodebits[2], encodebits[3], *bitlen);
#endif
}

/*
return value:
0: No more data in ul_buf.
1: Have more data in ul_buf
*/
int SP4G_PSR_UL_GSeries_IsMoreData(void)
{
#if defined(__G_CODEC_SUPPORT__)
   if(StreamRB_GetDataCount(&ul_buf) > 0)
   {
      return(1);
   }
#endif
   return(0);
}

//void SP4G_PSR_UL_SetFrameType(SP4G_Codec codec)
#if defined(__G_CODEC_SUPPORT__)
void setVmGCodecULInfo(frame_header_t *ptmp_hdr, vmGCodecULInfo *pstvmGCodecULInfo)
{
    pstvmGCodecULInfo->drop_info = 0x0000;
    pstvmGCodecULInfo->codec = ptmp_hdr->codec;
    switch(ptmp_hdr->codec)
    {
       case SP4G_CODEC_G711:
          pstvmGCodecULInfo->codec_parameters = ((enc_init_param_g711.law&0x000F)<<12) |
                                                ((enc_init_param_g711.VAD_enable&0x000F)<<8);
          break;
       case SP4G_CODEC_G722:   
          pstvmGCodecULInfo->codec_parameters = 0;
          break;
       case SP4G_CODEC_G723_1:
          pstvmGCodecULInfo->codec_parameters = ((enc_init_param_g723_1.BitRate&0x000F)<<12) |
                                                ((enc_init_param_g723_1.VAD_enable&0x000F)<<8) |
                                                ((enc_init_param_g723_1.CNG_enable&0x000F)<<4) |
                                                ((enc_rtime_param_g723_1.BitRate&0x000F)<<0);
          break;
       case SP4G_CODEC_G726:
          pstvmGCodecULInfo->codec_parameters = ((enc_init_param_g726.BitRate&0x000F)<<12) |
                                                ((enc_rtime_param_g726.BitRate&0x000F)<<8);
          break;
       case SP4G_CODEC_G729:  
          pstvmGCodecULInfo->codec_parameters = ((enc_init_param_g729.VAD_enable&0x000F)<<12) |
                                                ((enc_init_param_g729.CNG_enable&0x000F)<<8);
          break;
       default:
          pstvmGCodecULInfo->codec_parameters = 0;
          break;
    }
}

int PSR_GetFrame(int16* c, int16* len, uint8* tmp_buf)
{
   int i= 0;
   int left = 0;
   frame_header_t tmp_hdr;
   uint32 savedMask;   
 
   if( L1SP_GetState() != L1SP_STATE_4G_SPEECH_ON){
         return;
   } 
   if(!is_g_codec(sp4g->ul_codec_mode))   
      return;  
           
   kal_prompt_trace(MOD_L1SP, "PSR_GetFrame"); 
   kal_take_enh_mutex( sp4g_ul_mutex ); 
   while(StreamRB_GetDataCount(&ul_buf)>0){      
      //for VM
      uint32 streamDataBuffer[640/sizeof(uint32)];
      vmGCodecULInfo stvmGCodecULInfo;

      StreamRB_Read(&ul_buf, (uint8 *)&tmp_hdr, sizeof(tmp_hdr)/sizeof(uint8));
      ASSERT(tmp_hdr.magicid == 0xFFAA);
      kal_prompt_trace(MOD_L1SP, "PSR_GetFrame# %d", i++); 

      setVmGCodecULInfo(&tmp_hdr, &stvmGCodecULInfo);
     
      if(tmp_hdr.codec == sp4g->ul_codec_mode){
         *c = sp4g->ul_codec_mode;
         *len = tmp_hdr.len;
        
         StreamRB_Read(&ul_buf, tmp_buf, tmp_hdr.len);
         savedMask = SaveAndSetIRQMask();
         vmStoreGCodecULStream(&stvmGCodecULInfo, (kal_uint16)tmp_hdr.len, tmp_buf);
         RestoreIRQMask( savedMask );
         kal_give_enh_mutex( sp4g_ul_mutex );
         kal_prompt_trace(MOD_L1SP, "PSR_GetFrame codec=%d len=%d", *c, *len);
         kal_prompt_trace(MOD_L1SP, "PSR_GetFrame Ok"); 
        
         return;
      }else{
         kal_prompt_trace(MOD_L1SP, "PSR_GetFrame Mismatch codec %d %d", tmp_hdr.codec, sp4g->ul_codec_mode);

         stvmGCodecULInfo.drop_info = 0x0001;
         //StreamRB_ShiftReadPointer(&ul_buf, tmp_hdr.len);          
         if(tmp_hdr.len <= sizeof(streamDataBuffer))
         {
            StreamRB_Read(&ul_buf, (uint8*)streamDataBuffer, tmp_hdr.len);
            savedMask = SaveAndSetIRQMask();
            vmStoreGCodecULStream(&stvmGCodecULInfo, (kal_uint16)tmp_hdr.len, (kal_uint8 *)streamDataBuffer);
            RestoreIRQMask( savedMask );
         }
         else
         {
            StreamRB_Read(&ul_buf, (uint8*)streamDataBuffer, sizeof(streamDataBuffer));
            StreamRB_ShiftReadPointer(&ul_buf, tmp_hdr.len-sizeof(streamDataBuffer));
            savedMask = SaveAndSetIRQMask();
            vmStoreGCodecULStream(&stvmGCodecULInfo, (kal_uint16)(sizeof(streamDataBuffer)), (kal_uint8 *)streamDataBuffer);
            RestoreIRQMask( savedMask );
            kal_prompt_trace(MOD_L1SP, "UL_Event drop2 stream size is larger than %dbyte", sizeof(streamDataBuffer));
         }
      }
   }             
   left = StreamRB_GetDataCount(&ul_buf)>0;
   kal_give_enh_mutex( sp4g_ul_mutex ); 
   //give a NODATA frame
   kal_prompt_trace(MOD_L1SP, "PSR_GetFrame NoData");
   return left;
}

uint16 TimerUL_id;
void UL_Timer( void *data )
{  kal_prompt_trace(MOD_L1SP, "@UL_Timer ");
   L1Audio_SetEvent( TimerUL_id, (void *)0 );
}

void Timer_Event()
{
   uint8 tmp_buf[2048*2];
   int16 codec, len;
   PSR_GetFrame(&codec, &len, tmp_buf);
   kal_prompt_trace(MOD_L1SP, "@Timer_Event codec=%d len=%d", codec, len);
   PSR_PutFrame(codec, len, tmp_buf);	
}


void UL_Event()
{
  
   
   int frame_size = 0;
   int max_iteration = 5;
   int c_codec;
   frame_header_t ul_header; 
   uint8 *pu8_ul_encoded_tmp = (uint8 *)ul_encoded_tmp;
   int i;
   int f;
   int valid_stream_data;
   uint32 savedMask;   

   if( L1SP_GetState() != L1SP_STATE_4G_SPEECH_ON){
         return;
   } 
          
 
   if(!is_g_codec(sp4g->ul_codec_mode))   
      return;   

   valid_stream_data = 0;
   for(i=0; i<max_iteration; i++){
      c_codec = g_series_mgr.enc_codec;
      kal_prompt_trace(MOD_L1SP, "UL_Event %d-th codec=%d", i, c_codec);
      switch(c_codec){         //unit is word     
            case SP4G_CODEC_G711:
            case SP4G_CODEC_G722:   
            case SP4G_CODEC_G723_1:
            case SP4G_CODEC_G726:
            case SP4G_CODEC_G729:  
               frame_size = g_series_mgr.enc_pcm_size/2;
            break;              
         default:
            ASSERT(0);
            break;         
      }
      
      f = 0;
      {
         uint32 savedMask;
         savedMask = SaveAndSetIRQMask();
         if(PCMRB_GetDataCount(&pcm_ul_buf) >= frame_size) {
		 	#if 1
            PCMRB_Read(&pcm_ul_buf, ul_pcm_tmp, frame_size);   
		 	//fsju, for test, should remove!
			#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#if 1
/* under construction !*/
/* under construction !*/
				#else
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
			#endif
		 	//fsju add end
            f = 1;
         }
         RestoreIRQMask( savedMask );
      }
      
      if(f == 1){   
         kal_prompt_trace(MOD_L1SP, "UL_Event ReadPCM size=%d", frame_size);
         
         ul_header.magicid = 0xFFAA;
         switch(c_codec){
            case SP4G_CODEC_G711:
            case SP4G_CODEC_G722:   
            case SP4G_CODEC_G723_1:
            case SP4G_CODEC_G726:
            case SP4G_CODEC_G729:  
            {
               int result;
               int pcm_size = g_series_mgr.enc_pcm_size;
               int bs_size  = g_series_mgr.enc_bs_size;
               
               int GSeries_Encode_Process(uint16 *ul_pcm_tmp, int *pcm_size, uint8 *ul_encoded_tmp, int *bs_size);
               result = GSeries_Encode_Process(ul_pcm_tmp, &pcm_size, pu8_ul_encoded_tmp, &bs_size);               
               kal_prompt_trace(MOD_L1SP, "UL_Event Encoded GSeries_Encode_Process return=%d", result);
               ul_header.codec = c_codec; 
               ul_header.len   = bs_size;//bs_size/2;
            }
            break;
         default:
            ASSERT(0);
            break;         
         }   
         kal_prompt_trace(MOD_L1SP, "UL_Event Encoded codec=%d size=%d", c_codec, ul_header.len);
		 //fsju
         #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #endif
         if(ul_header.codec==sp4g->ul_codec_mode)
         {
            if(SP_is_codec_mute() == false)
            {
               valid_stream_data = 1;
               kal_take_enh_mutex( sp4g_ul_mutex );
               kal_prompt_trace(MOD_L1SP, "UL_Event Encoded free_size=%d %d", StreamRB_GetFreeSpace(&ul_buf), ul_header.len);
               while(StreamRB_GetFreeSpace(&ul_buf)< ul_header.len + (sizeof(frame_header_t)/sizeof(uint8))){
                  frame_header_t hdr; 
                  //for VM
                  uint32 streamDataBuffer[640/sizeof(uint32)];
                  vmGCodecULInfo stvmGCodecULInfo;

                  kal_prompt_trace(MOD_L1SP, "UL_Event drop1 %d", StreamRB_GetFreeSpace(&ul_buf));
                  //drop a frame
                  StreamRB_Read(&ul_buf, (uint8*)&hdr, sizeof(hdr)/sizeof(uint8));
                  kal_prompt_trace(MOD_L1SP, "UL_Event drop2 %d %d", StreamRB_GetFreeSpace(&ul_buf), hdr.len);
                  ASSERT(hdr.magicid == 0xFFAA);

                  setVmGCodecULInfo(&hdr, &stvmGCodecULInfo);
                  stvmGCodecULInfo.drop_info = 0x0001;
                  //StreamRB_ShiftReadPointer(&ul_buf, hdr.len);
                  if(hdr.len <= sizeof(streamDataBuffer))
                  {
                     StreamRB_Read(&ul_buf, (uint8*)streamDataBuffer, hdr.len);
                     savedMask = SaveAndSetIRQMask();
                     vmStoreGCodecULStream(&stvmGCodecULInfo, (kal_uint16)hdr.len, (kal_uint8 *)streamDataBuffer);
                     RestoreIRQMask( savedMask );
                  }
                  else
                  {
                     StreamRB_Read(&ul_buf, (uint8*)streamDataBuffer, sizeof(streamDataBuffer));
                     StreamRB_ShiftReadPointer(&ul_buf, hdr.len-sizeof(streamDataBuffer));
                     savedMask = SaveAndSetIRQMask();
                     vmStoreGCodecULStream(&stvmGCodecULInfo, (kal_uint16)(sizeof(streamDataBuffer)), (kal_uint8 *)streamDataBuffer);
                     RestoreIRQMask( savedMask );
                     kal_prompt_trace(MOD_L1SP, "UL_Event drop2 stream size is larger than %dbyte", sizeof(streamDataBuffer));
                  }
                  kal_prompt_trace(MOD_L1SP, "UL_Event drop3 %d ", StreamRB_GetFreeSpace(&ul_buf));
               }
               kal_give_enh_mutex( sp4g_ul_mutex );
               kal_prompt_trace(MOD_L1SP, "UL_Event Write1 %d", StreamRB_GetFreeSpace(&ul_buf));
               StreamRB_Write(&ul_buf, (uint8*)&ul_header, sizeof(ul_header)/sizeof(uint8)); 

               kal_prompt_trace(MOD_L1SP, "UL_Event Write2 %d", StreamRB_GetFreeSpace(&ul_buf));
               StreamRB_Write(&ul_buf, pu8_ul_encoded_tmp, ul_header.len); 

               kal_prompt_trace(MOD_L1SP, "UL_Event Write3 %d", StreamRB_GetFreeSpace(&ul_buf));
            }
            else
            {
               if(KAL_TRUE == SP4G_Rab_State())
               {
                  PSR_SP4G_Callback( SP4G_UL_MUTE_NOTIFY, (void*)0 );
                  kal_prompt_trace(MOD_L1SP, "UL_Event drop data, SP_is_codec_mute()=%d", SP_is_codec_mute());
               }
            }
            /*if(SP_is_codec_mute()){
               kal_trace( TRACE_GROUP_SP4G, SP4G_UL_SKIP_NOTIFY);
            }else{            
               PSR_SP4G_Callback(SP4G_UL_DATA_NOTIFY, 0);
            }*/
         }
         else
         {
            kal_prompt_trace(MOD_L1SP, "UL_Event codec %d %d mismatch", ul_header.codec, sp4g->ul_codec_mode); 
         }         
      }
      else
      {
         kal_prompt_trace(MOD_L1SP, "UL_Event ReadPCM no size");    
         break;     
      }     
   }

   if(valid_stream_data != 0)
   {
      PSR_SP4G_Callback(SP4G_UL_DATA_NOTIFY, 0);
   }

}

volatile uint16* SAL_PcmEx_Get4GULBuf(int *len);


int ii=0;
void sp4g_hisr_ul_g(void *data)
{   
   int len;
   int fsize;
   if(L1SP_GetState() == L1SP_STATE_4G_SPEECH_CLOSING) 
      return; 
      
   if(!is_g_codec(sp4g->ul_codec_mode))   
      return;   
   fsize = SAL_PcmEx_GetBufLen(SAL_PCMEX_VOLTE_BUF_UL);
   
   kal_prompt_trace(MOD_L1SP, "sp4g_hisr_ul_g size=%d", fsize);
   if(PCMRB_GetFreeSpace(&pcm_ul_buf) < fsize){
      PCMRB_ShiftReadPointer(&pcm_ul_buf, fsize);
      kal_prompt_trace(MOD_L1SP, "sp4g_hisr_ul_g drop");
   }  
   
   {                    
      volatile uint16* ptr = SAL_PcmEx_GetBuf(SAL_PCMEX_VOLTE_BUF_UL);
      kal_prompt_trace(MOD_L1SP, "sp4g_hisr_ul_g %x", ptr);
	  //fsju
	  #if 1
      //PCMRB_Write(&pcm_ul_buf, ptr, fsize);
      PCMRB_Write_from_DSP(&pcm_ul_buf, ptr, fsize);
	  #else
/* under construction !*/
	  #endif
   }
   L1Audio_SetEvent( aud_ul_id, (void *)0 );
   kal_prompt_trace(MOD_L1SP, "sp4g_hisr_ul_g aud_ul_id %x", aud_ul_id);
}

#endif



//extern void vmSet4GNetworkInfo( uint32 *l1_info, uint16 crc_result, uint16 buf_status, uint8 dl_count );
void vmSet4GNetworkInfo( uint32 *l1_info, uint16 crc_result, uint16 buf_status, uint8 dl_count ){}


void sp4g_hisr_dl_amr(void *data)
{
   int32 I, J = 0, K;
   uint16 *ptr16;
   uint16 rx_type = 0, sd_mode = 0, rx_len = 0;
   uint8 *ptr8;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   uint8 *ptr8_bak;
#endif
   const uint8* RAB_To_DSP_Mapping, *Order = NULL;
   uint16 total_bits, idx, rabBitsCount;
   uint8 frame_type = 0;  
   uint16 bit16Data;
   uint8 sidData;
   bool FQI_flag = false;
#if defined(__SP4G_UL_RESYNC__)
   bool ul_request_resync = sp4g->ul_request_resync;
   uint32 ctime = ust_get_current_time();
   kal_prompt_trace(MOD_L1SP, "[UL_Sync]sp4g_hisr_dl_amr.1 ul_request_resync = %d sp4g_reset_flag=%d ctime = %d", ul_request_resync, sp4g_reset_flag, ctime);
#endif


                        
   if(L1SP_GetState() == L1SP_STATE_4G_SPEECH_CLOSING) 
      return; 
   if(is_g_codec(sp4g->ul_codec_mode))   
      return;
            
   ASSERT(sp4g != (SP4G_Struct*) 0);                          
   

   sp4g->dl_report = SAL_3G_GetValue(SAL_3G_VALUE_RX_CODEC_MODE);


   /*for catcher log codec information*/
   if( sp4g->dl_report != sp4g->pre_dl_report ){
      L1Audio_Msg_SPEECH_CODEC( L1SP_Speech_Codec_Mode(sp4g->ul_report), L1SP_Speech_Codec_Mode(sp4g->dl_report) );
      sp4g->pre_dl_report = sp4g->dl_report;
   }
   
// #if defined(__VM_CODEC_SUPPORT__) // always on
   // VM 
   //if( sp4g_vm_flag ) 
   {
      uint32 *l1_info = NULL;
      //uint16 crc_result = 0;
	  uint16 buf_status, crc_result = 0;
	  uint32 CFN;
      
      if( sp4g->dl_count == 0 ){
         crc_result = (l1AInfo << 8);
         CFN = 0xFFFFFFFF;
      }
      else 
      {
         CFN = 0;
         if( sp4g->sp4g_mode == RAT_3G324M_MODE ){
            l1_info = NULL;
         }
         else{
            ptr8 = (uint8*) sp4g->dl_buffer[sp4g->dl_read_idx];
            ptr8 += 2;
            CFN = ptr8[0] + (ptr8[1] << 8) + (ptr8[2] << 16) + (ptr8[3] << 24);
            
            for(I = 0 ; I < 4 ; I ++)
               if( CFN == sp4g->L1_Info[I][0] ) 
                  break;
            if( I == 4 ){
               crc_result = (l1AInfo << 8);
               l1_info = NULL;
            }else{
               l1_info = sp4g->L1_Info[I];
               crc_result = (uint16)(l1AInfo << 8) | (uint16)(sp4g->L1_Info[I][2] & 0xF); //[0:7]:CRC, [8:15]:l1AInfo
            }
            /*SID BAD False alarm work around, log in VM first*/
            {
               uint8 * ptrDL;
               ptrDL = (uint8*) sp4g->dl_buffer[sp4g->dl_read_idx];
               if( sp4g->dtx_state == 0 && ptrDL[0] == 8 /*AMR_SID*/ && ptrDL[1] == KAL_FALSE/*CRC fail*/)
                  crc_result |= 0x8000;// The flag indicate working around
               if( ptrDL[0] == AMR_NO_DATA && sp4g->dtx_force == KAL_TRUE )
                  //crc_result |= 0x4000;
                  crc_result |= 0x0080;//move from bit14 to bit7. 20100821
            }
         }
      }
      SAL_VOLTE_SetInfo(SAL_VOLTE_INFO_JBM_OUT_SN,  CFN);
      buf_status = ( ( (sp4g->ul_read_idx << DL_BUF_INDEX_BIT_NUM) + sp4g->dl_read_idx ) << 8 ) +
                   (sp4g->ul_write_idx << DL_BUF_INDEX_BIT_NUM) + sp4g->dl_write_idx;
	  vmSet4GNetworkInfo(l1_info, crc_result, buf_status, sp4g->dl_count);
      
   }
// #endif
   l1AInfo &= ~0xFFFC;
   kal_prompt_trace(MOD_L1SP, "[P_HISR] sp4g_reset_flag=%d dl_count=%d %d %d size=%d", sp4g_reset_flag, sp4g->dl_count, sp4g->dl_read_idx, sp4g->dl_write_idx, sp4g->dl_buffer_size);
   // DL side
   if( sp4g->dl_count == 0 || sp4g_reset_flag != 2 ){ // buffer under flow
      SAL_3G_Set_RxType(SAL_3G_RX_NO_DATA);
      rx_type = SAL_3G_RX_NO_DATA;
      sp4g->dtx_state = 1;
      kal_dev_trace( TRACE_GROUP_SP4G, SP4G_DTX_NO_DATA );
   }
   else
   {
      kal_dev_trace( TRACE_GROUP_SP4G, SP4G_BUFFER_STATUS, sp4g->dl_read_idx, sp4g->dl_write_idx,sp4g->dl_count, sp4g->dl_buffer[sp4g->dl_read_idx][0] );
      
      ptr8 = (uint8*) sp4g->dl_buffer[sp4g->dl_read_idx];
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      ptr8_bak = (uint8*) sp4g->dl_buffer2[sp4g->dl_read_idx];
#endif
      ptr16 = (uint16*) sp4g->dsp_buffer;
      if( sp4g->sp4g_mode == RAT_4G_MODE ){
         frame_type = *ptr8++;        // here 0 ~ 7 and includes SID and NO_DATA
         FQI_flag = (bool)*ptr8++;
         ptr8 += 4; // skip CFN 
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
         ptr8_bak += 6;
#endif
      }
#ifdef __VIDEO_CALL_SUPPORT__
      else{//4G 324M
         FQI_flag = KAL_TRUE;
         frame_type = *ptr8++; // here 0 ~ 7 and includes SID and NO_DATA
         ptr8++;               // skip frame length 
      }
#endif
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      if (_3g_bNeedExtraLog == true){
         //kal_prompt_trace(MOD_L1SPHISR,"SP4G_HISR DL Type %d, Frm %x %x %x %x %x", frame_type, ptr8[0], ptr8[1],ptr8[2],ptr8[3],ptr8[4]);
         kal_dev_trace(TRACE_GROUP_SP4G, SP4G_DL_BIT_TRUE, frame_type, ptr8[0], ptr8[1],ptr8[2],ptr8[3],ptr8[4]);
      }
#endif
      if( frame_type == AMR_NO_DATA && sp4g->dtx_force == KAL_TRUE ){
         frame_type = AMR_SID_FRAME;
         FQI_flag = KAL_FALSE; // force enter SID_BAD;
         sp4g->dtx_state = 1;
      }
      sp4g->dtx_force = KAL_FALSE;
      if( sp4g->dtx_state == 0 && frame_type == AMR_SID_FRAME && FQI_flag == KAL_FALSE ){//previous dtx_state is false, but suddenly SID_BAD, regard it as false alarm.
         frame_type = AMR_NO_DATA;
         sp4g->dtx_force = KAL_TRUE;
      }
#if defined(__SP4G_UL_RESYNC__)      
      if( ul_request_resync ){
         kal_prompt_trace(MOD_L1SP, "[UL_Sync] sp4g_hisr_dl_amr.2 forced no_data");
         
         frame_type = AMR_NO_DATA;
      }
#endif    
      switch(frame_type)
      {
         case 0: // 4.75 kbps  
         case 1: // 5.15 kbps
         case 2: // 5.9  kbps 
         case 3: // 6.7  kbps 
         case 4: // 7.4  kbps 
         case 5: // 7.95 kbps 
         case 6: // 10.2 kbps 
         case 7: // 12.2 kbps
#ifdef __AMRWB_LINK_SUPPORT__
         case 16:/* WB type 0, AMR-WB 6.60 */ 
         case 17:/* WB type 1, AMR-WB 8.85 */ 
         case 18:/* WB type 2, AMR-WB 12.65 */
         case 19:/* WB type 3, AMR-WB 14.25 */
         case 20:/* WB type 4, AMR-WB 15.85 */
         case 21:/* WB type 5, AMR-WB 18.25 */
         case 22:/* WB type 6, AMR-WB 19.85 */
         case 23:/* WB type 7, AMR-WB 23.05 */
         case 24:/* WB type 8, AMR-WB 23.85 */
            if( frame_type >= 16 )
               RAB_To_DSP_Mapping = (const uint8 *) tblAMR_WBOrder[frame_type-16];
            else
#endif         	
            RAB_To_DSP_Mapping = tblAMROrder[frame_type];    
            if( FQI_flag == KAL_TRUE )
               rx_type = SAL_3G_RX_SPEECH_GOOD;
            else 
               rx_type = SAL_3G_RX_SPEECH_BAD;
            
            sd_mode = GetFrameType2DspMode(frame_type);
            rx_len  = GetDspModeLen(sd_mode);
             // move amr data to dl_buffer 
             
            total_bits = RAB_subflow[frame_type][0] + RAB_subflow[frame_type][1] + RAB_subflow[frame_type][2];
            
            for(I = rx_len; --I >= 0; )
               *ptr16++ = 0;
            
            ptr16 -= rx_len;
            idx = 0;
            if( sp4g->sp4g_mode == RAT_4G_MODE ){
               for(I = 0; I < 3; I ++)
               {
                  if(RAB_subflow[frame_type][I] == 0)
                     break;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
                  if (_3g_bNeedExtraLog == true){
                     ASSERT( *ptr8 == *ptr8_bak );
                  }
#endif
                  rabBitsCount = RAB_subflow[frame_type][I];
                  if(frame_type >= 16){
                     const uint16* WB_RAB_To_DSP_Mapping;
                     WB_RAB_To_DSP_Mapping = (const uint16*)RAB_To_DSP_Mapping;
                     for(J = 0; J < rabBitsCount; J++)
                     {
                        K = WB_RAB_To_DSP_Mapping[idx++];
                        bit16Data = (ptr8[J >> 3] & RAB_Order[J & 7])? DSP_Order[K & 15] : 0; 
                        ptr16[K >> 4] |= bit16Data;
                     }
                  } else {
                     for(J = 0; J < rabBitsCount; J++)
                     {
                        uint32 t1;
                        uint16 *t2;
                        K = RAB_To_DSP_Mapping[idx++];
                        bit16Data = (ptr8[J >> 3] & RAB_Order[J & 7])? DSP_Order[K & 15] : 0;
                        t1 = K >> 4;
                        t2 = ptr16 + t1;
                         
                        //ptr16[K >> 4] |= bit16Data;
                        *t2 |= bit16Data;
                     }
                  }  
                  ptr8 += (rabBitsCount + 7) >> 3;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
                  ptr8_bak += (rabBitsCount + 7) >> 3;
#endif
               }
               ASSERT(idx == total_bits);
            }
#ifdef __VIDEO_CALL_SUPPORT__
            else{//4G 324M
               I = 4;
               for(J = 0; J < total_bits; J++, I++)
               {
                  K = RAB_To_DSP_Mapping[idx++];
                  bit16Data = (ptr8[I >> 3] & AMR_IF2_Order[J & 7])? DSP_Order[K & 15] : 0; 
                  ptr16[K >> 4] |= bit16Data;
               }  
            }  
#endif
            sp4g->dtx_state = 0;
            break;
      
         case 8: // AMR SID
#ifdef __AMRWB_LINK_SUPPORT__
         case 25:
#endif            
            sidData = ptr8[4];
            if( sp4g->sp4g_mode == RAT_4G_MODE ){
               if( FQI_flag == KAL_TRUE )
               {
                  if( sidData & 0x10 )
                     rx_type = SAL_3G_RX_SID_UPDATE;
                  else 
                     rx_type = SAL_3G_RX_SID_FIRST;
                  sp4g->dtx_state = 1;
               }
               else
                  rx_type = SAL_3G_RX_SID_BAD;
#ifdef __AMRWB_LINK_SUPPORT__
               if( frame_type == 25 ){
                  sd_mode = (sidData & 0xF);
               
                  if(sd_mode >= 10)
                  {
                     rx_type = SAL_3G_RX_SID_BAD;
                     sd_mode = sp4g->pre_dl_report;
                  } else {
                     sd_mode = GetFrameType2DspMode(sd_mode+16);
                     //sd_mode = AmrFrameType2DspMode[sd_mode+16];  // RX SD Mode 
                  }
               } else
#endif             
               {     
                  sd_mode = (sidData & 0xE) >> 1;// should reverse
                  sd_mode = (sd_mode >> 2) | ((sd_mode & 0x1) << 2) | (sd_mode & 0x2);
                  sd_mode = GetFrameType2DspMode(sd_mode);
                  //sd_mode = AmrFrameType2DspMode[sd_mode];  // RX SD Mode 
               }
            }
#ifdef __VIDEO_CALL_SUPPORT__
            else{//4G 324M
               if( sidData & 0x80 )
                  rx_type = SAL_3G_RX_SID_UPDATE;
               else 
                  rx_type = SAL_3G_RX_SID_FIRST;
               sd_mode = GetFrameType2DspMode((ptr8[5] & 0x7)); 
            }
#endif

            rx_len = 3; // 35 information bits
            // move sid data to dl_buffer
            for(I = 3; --I >= 0; )
               *ptr16++ = 0;
            ptr16 -= 3;
            if( sp4g->sp4g_mode == RAT_4G_MODE ){
               J = 0;
               Order = RAB_Order;
            }
#ifdef __VIDEO_CALL_SUPPORT__
            else{//4G324M
               J = 4;
               Order = AMR_IF2_Order;
            }
#endif
         
            for(I = 0; I < 35; I++,J++)
            {
               bit16Data = (ptr8[J >> 3] & Order[I & 7])? DSP_Order[I & 15] : 0; 
               ptr16[I >> 4] |= bit16Data;
            } 
         #ifdef AMR_DATA_LOG   
            if( rx_type == SAL_3G_RX_SID_FIRST )  
               kal_dev_trace( TRACE_GROUP_SP4G, SP4G_RX_SID_FIRST );
            else if( rx_type == SAL_3G_RX_SID_UPDATE )  
               kal_dev_trace( TRACE_GROUP_SP4G, SP4G_RX_SID_UPDATE );
         #endif
            break;
            
         case 15: // NO DATA 
            kal_dev_trace( TRACE_GROUP_SP4G, SP4G_RX_NO_DATA );
            rx_type = SAL_3G_RX_NO_DATA; 
            rx_len = 0;
            // no need to record codec mode , inherit from previous 
            break; 
         case SP4G_CODEC_LOST_FRAME:
         	  kal_dev_trace( TRACE_GROUP_SP4G, SP4G_RX_LOST_DATA );
            rx_type = SAL_3G_RX_NO_DATA; 
            rx_len = 0;         	
         	   //##fix
         	  break;   
         default: 
            ASSERT(false);
            break;
      }
      // get codec_mode , set RX codec_mode 
      // get data from dl_read  
      ptr16 = (uint16*) sp4g->dsp_buffer;
      
      SAL_3G_Set_RxType(rx_type); 
      
      //For NB/WB handover, it's decided by network set UL codec.
      // If downlink happens, set it as NO data.
      if( rx_type != SAL_3G_RX_NO_DATA )
      {
         if( (sd_mode <= 0x0A && sp4g->dl_report >= 0x20) ||
             (sd_mode >= 0x20 && sp4g->dl_report <= 0x0A) )
         {
         	SAL_3G_Set_RxType(SAL_3G_RX_NO_DATA);
			SAL_3G_Upd_Dec_Cod(sp4g->dl_report);
            rx_type = SAL_3G_RX_NO_DATA;
            kal_brief_trace( TRACE_GROUP_SP4G, SP4G_RX_FORCE_NO_DATA_WHEN_CHANGE_BAND );
         }
      }
#if defined(__SP4G_UL_RESYNC__)      
      else if (ul_request_resync) {
         kal_prompt_trace(MOD_L1SP, "[UL_Sync] AM_4G_INTRARAT");
         AM_4G_INTRARAT(sp4g->ul_codec_mode);
         sp4g->ul_request_resync = KAL_FALSE; 
      }
#endif      
      if( rx_type != SAL_3G_RX_NO_DATA && rx_type != SAL_3G_RX_SID_BAD ) //if RX_NO_DATA or RX_SID_BAD, codec mode will use the previous one
      {
         volatile uint16 *addr;
		 SAL_3G_Upd_Dec_Cod(sd_mode);
         addr = SAL_3G_GetAddr(SAL_3G_ADDR_RXHB);
         for(I = rx_len ; --I >= 0; )
            *addr++ = *ptr16++;            
      }
      {
         // update 4G dl_count
         sp4g->dl_count --;
         sp4g->dl_read_idx++;
      }
      if( sp4g->dl_read_idx >= sp4g->dl_buffer_size ){//near end of buffer
         sp4g->dl_read_idx = 0;
      }
   }
   kal_prompt_trace(MOD_L1SP, "sp4g_hist 4g_sync=%x", ((uint8)SAL_3G_IsDLEmpty()<<1) + (uint8)SAL_3G_IsULReady());
   SAL_3G_SetDLReady(); // MCU tell DSP the data is ready

   { /*for catcher log codec information*/
      uint8 txType, rxType, ber;
      txType   = SAL_3G_GetValue(SAL_3G_VALUE_TX_TYPE);
      rxType   = rx_type >> 1;
	  ber = 255;//useless both for dsp and driver;
      //ber      = (*DP_4G_DL_RX_TYPE & 0xFF00);
      L1Audio_Msg_SPEECH_FRAME( L1SP_Speech_TX_Type(txType), L1SP_Speech_RX_Type(rxType), ber );
      L1Audio_Msg_VM_DEBUG( DP2_3G_debug_info0, DP2_3G_debug_info1, DP2_3G_debug_info7 );
   }

}


#if defined(__G_CODEC_SUPPORT__)
void setVmGCodecDLInfo(frame_header_t *ptmp_hdr, vmGCodecDLInfo *pstvmGCodecDLInfo)
{
   uint16 u16temp;
   pstvmGCodecDLInfo->drop_info = 0x0000;
   pstvmGCodecDLInfo->codec = ptmp_hdr->codec;
   pstvmGCodecDLInfo->DL_PCM_size = (G_SERIAL_CODEC_PCM_RB_BYTE_SIZE>>1);
   switch(ptmp_hdr->codec)
   {
      case SP4G_CODEC_G711:
         pstvmGCodecDLInfo->codec_parameters = ((dec_init_param_g711.law&0x000F)<<12) |
                                               ((dec_init_param_g711.CNG_enable&0x000F)<<8) |
                                               ((dec_rtime_param_g711.BFI&0x000F)<<4) |
                                               ((dec_rtime_param_g711.ENH_enable&0x000F)<<0);
         break;
      case SP4G_CODEC_G722:
         if(dec_init_param_g722.frame_size_in_samples == G722_10MS_PCM_FRAME_SIZE_IN_BYTES)
         {
            u16temp = 0;
         }
         else if(dec_init_param_g722.frame_size_in_samples == G722_20MS_PCM_FRAME_SIZE_IN_BYTES)
         {
            u16temp = 1;
         }
         else
         {
            u16temp = 2;
         }
         pstvmGCodecDLInfo->codec_parameters = ((u16temp&0x000F)<<12) |
                                               ((dec_rtime_param_g722.bad_frame_indicator&0x000F)<<8) |
                                               ((dec_rtime_param_g722.mode&0x000F)<<4);
         break;
      case SP4G_CODEC_G723_1:
         pstvmGCodecDLInfo->codec_parameters = 0;
         break;
      case SP4G_CODEC_G726:
         pstvmGCodecDLInfo->codec_parameters = ((dec_init_param_g726.BitRate&0x000F)<<12);
         break;
      case SP4G_CODEC_G729:
         pstvmGCodecDLInfo->codec_parameters = 0;
         break;
      default:
         pstvmGCodecDLInfo->codec_parameters = 0;
         break;
   }
}

void PSR_PutFrame(int c, int encoded_len, uint8* encoded_bits)
{
   uint32 savedMask;
   frame_header_t hdr;  
   if( L1SP_GetState() != L1SP_STATE_4G_SPEECH_ON){
         return;
   } 
      
   if(!is_g_codec(sp4g->ul_codec_mode))   
      return;

   if(c==sp4g->ul_codec_mode){
      kal_take_enh_mutex( sp4g_dl_mutex );  
      while(StreamRB_GetFreeSpace(&dl_buf)< encoded_len + (sizeof(frame_header_t)/sizeof(uint8))){
         //uint16 tmp_buf[2048];
         uint32 streamDataBuffer[640/sizeof(uint32)];
         vmGCodecDLInfo stvmGCodecDLInfo;

         kal_prompt_trace(MOD_L1SP, "PSR_PutFrame drop");
         //drop a frame
         StreamRB_Read(&dl_buf, (uint8 *)&hdr, sizeof(hdr)/sizeof(uint8));
         ASSERT(hdr.magicid == 0xFFAA);

         setVmGCodecDLInfo(&hdr, &stvmGCodecDLInfo);
         stvmGCodecDLInfo.drop_info = 0x0001;
         //StreamRB_ShiftReadPointer(&dl_buf, hdr.len);   
         if(hdr.len <= sizeof(streamDataBuffer))
         {
            StreamRB_Read(&dl_buf, (uint8*)streamDataBuffer, hdr.len);
            savedMask = SaveAndSetIRQMask();
            vmStoreGCodecDLStream(&stvmGCodecDLInfo, (kal_uint16)hdr.len, (kal_uint8 *)streamDataBuffer);
            RestoreIRQMask( savedMask );
         }
         else
         {
            StreamRB_Read(&dl_buf, (uint8*)streamDataBuffer, sizeof(streamDataBuffer));
            StreamRB_ShiftReadPointer(&dl_buf, hdr.len-sizeof(streamDataBuffer));
            savedMask = SaveAndSetIRQMask();
            vmStoreGCodecDLStream(&stvmGCodecDLInfo, (kal_uint16)(sizeof(streamDataBuffer)), (kal_uint8 *)streamDataBuffer);
            RestoreIRQMask( savedMask );
            kal_prompt_trace(MOD_L1SP, "PSR_PutFrame drop stream size is larger than %dbyte", sizeof(streamDataBuffer));
         }
      }
      kal_give_enh_mutex( sp4g_dl_mutex );
      
      hdr.magicid = 0xFFAA;
      hdr.codec   = c;
      hdr.len     = encoded_len;
      kal_prompt_trace(MOD_L1SP, "PSR_PutFrame codec=%d len=%d", c, encoded_len);
      StreamRB_Write(&dl_buf, (uint8 *)&hdr, sizeof(hdr)/sizeof(uint8)); 
      StreamRB_Write(&dl_buf, encoded_bits, encoded_len); 

  }
  else
  {
      vmGCodecDLInfo stvmGCodecDLInfo;

      kal_prompt_trace(MOD_L1SP, "PSR_PutFrame mismatch codec=%d %d", c, sp4g->ul_codec_mode);

      hdr.magicid = 0xFFAA;
      hdr.codec = c;
      hdr.len = encoded_len;

      setVmGCodecDLInfo(&hdr, &stvmGCodecDLInfo);
      stvmGCodecDLInfo.drop_info = 0x0001;
      savedMask = SaveAndSetIRQMask();
      vmStoreGCodecDLStream(&stvmGCodecDLInfo, (kal_uint16)(encoded_len), (kal_uint8 *)encoded_bits);
      RestoreIRQMask( savedMask );
  }
  L1Audio_SetEvent( aud_dl_id, (void *)0 );
  kal_prompt_trace(MOD_L1SP, "PSR_PutFrame aud_dl_id %x", aud_dl_id);
}

void DL_Event()
{
   frame_header_t hdr;  
   uint8 *pu8_dl_encoded_tmp = (uint8 *)dl_encoded_tmp;
   uint32 savedMask;
   vmGCodecDLInfo stvmGCodecDLInfo;

   int i;
   int max_iteration = 5;
   int f;
    if( L1SP_GetState() != L1SP_STATE_4G_SPEECH_ON){
         return;
   } 
       
 
   if(!is_g_codec(sp4g->ul_codec_mode))   
      return;
      
   for(i=0; i<max_iteration; i++){
      kal_prompt_trace(MOD_L1SP, "DL_Event %d-th ", i);
      
      if( sp4g_reset_flag == 1 ){
         sp4g_reset_internal();
      }
      
      f = 0;
      kal_take_enh_mutex( sp4g_dl_mutex );
      if(StreamRB_GetDataCount(&dl_buf) >0) {
         StreamRB_Read(&dl_buf, (uint8 *)&hdr, sizeof(hdr)/sizeof(uint8));
         ASSERT(hdr.magicid == 0xFFAA);
         StreamRB_Read(&dl_buf, pu8_dl_encoded_tmp, hdr.len);
         f = 1;
      }
      kal_give_enh_mutex( sp4g_dl_mutex );
      
      if(f==1){   
         int pcm_len = 0;
         switch(hdr.codec){
            case SP4G_CODEC_G711:
            case SP4G_CODEC_G722:   
            case SP4G_CODEC_G723_1:
            case SP4G_CODEC_G726:
            case SP4G_CODEC_G729:  
            {
               int result;
               int pcm_size = g_series_mgr.dec_pcm_size;
               int bs_size  = hdr.len;//hdr.len*2;
               int GSeries_Decode_Process(uint16 *dl_pcm_tmp, int *pcm_size, uint8 *dl_encoded_tmp, int *bs_size);
               result = GSeries_Decode_Process(dl_pcm_tmp, &pcm_size, pu8_dl_encoded_tmp, &bs_size);
               kal_prompt_trace(MOD_L1SP, "DL_Event Decoded GSeries_Decode_Process result=%d", result);
               
               pcm_len = pcm_size/2;
            }            
            break;            
            default:
               ASSERT(0);
            break;         
         }      
		 //fsju
		 #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		 #endif
         ASSERT(pcm_len != 0);
         kal_prompt_trace(MOD_L1SP, "DL_Event codec=%d len=%d hdr.len=%d", hdr.codec, pcm_len, hdr.len);
         
         setVmGCodecDLInfo(&hdr, &stvmGCodecDLInfo);

         {
            uint32 savedMask;
            savedMask = SaveAndSetIRQMask();
            if(PCMRB_GetFreeSpace(&pcm_dl_buf)<pcm_len ){               
               kal_prompt_trace(MOD_L1SP, "DL_Event drop PCM");
               PCMRB_ShiftReadPointer(&pcm_dl_buf, pcm_len);                 
               stvmGCodecDLInfo.drop_info = 0x0002;
            }
            RestoreIRQMask( savedMask );
         }
         PCMRB_Write(&pcm_dl_buf, dl_pcm_tmp, pcm_len);

         savedMask = SaveAndSetIRQMask();
         vmStoreGCodecDLStream(&stvmGCodecDLInfo, (kal_uint16)(hdr.len), pu8_dl_encoded_tmp);
         RestoreIRQMask( savedMask );
      }else{
         kal_prompt_trace(MOD_L1SP, "DL_Event ReadHardbit no size"); 
      }        
   }
}

void sp4g_hisr_dl_g(void *data)
{
   int len;
   int fsize;

   //uint16 tmp_buf[160];
   //uint16 *ptr = tmp_buf;
   
   volatile uint16* ptr;
   
   if(L1SP_GetState() == L1SP_STATE_4G_SPEECH_CLOSING) 
      return; 
      
   if(!is_g_codec(sp4g->ul_codec_mode))   
      return;   
   fsize = SAL_PcmEx_GetBufLen(SAL_PCMEX_VOLTE_BUF_DL);

   
   ptr = SAL_PcmEx_GetBuf(SAL_PCMEX_VOLTE_BUF_DL);
            
   kal_prompt_trace(MOD_L1SP, "sp4g_hisr_dl_g %x fsize=%d", ptr, fsize); 
   //fsju
   if((sp4g_reset_flag == 2) &&
      (PCMRB_GetDataCount(&pcm_dl_buf) >= fsize)){     
      //fsju
      #if 1
      //PCMRB_Read(&pcm_dl_buf, ptr, fsize);
      PCMRB_Read_to_DSP(&pcm_dl_buf, ptr, fsize);
	  #else
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
   }else{
      /*if((sp4g_reset_flag == 2) &&
          (PCMRB_GetDataCount(&pcm_dl_buf) > 0))
      {
         kal_prompt_trace(MOD_L1SP, "sp4g_hisr_dl_g data is less than DSP request: data=%d, DSP request=%d", PCMRB_GetDataCount(&pcm_dl_buf), fsize);
         PCMRB_Read_to_DSP_Padding(&pcm_dl_buf, ptr, fsize);
         //kal_prompt_trace(MOD_L1SP, "sp4g_hisr_dl_g 2 data is less than DSP request: data=%d, DSP request=%d", PCMRB_GetDataCount(&pcm_dl_buf), fsize);
      }
      else*/
      {
          int i;
          for(i=0; i<fsize; i++)
          {
             *ptr++ = 0;
          }
          kal_prompt_trace(MOD_L1SP, "sp4g_hisr_dl_g no data"); 

          // Record PCM buffer empty info to VM buffer. Start
          // VM HISR function and this HISR function run in the same HISR. So, we do not need to disable interrupt.
          {
              frame_header_t hdr;  
              vmGCodecDLInfo stvmGCodecDLInfo;
              hdr.magicid = 0xFFAA;
              hdr.codec = sp4g->ul_codec_mode;
              hdr.len = 0;
              setVmGCodecDLInfo(&hdr, &stvmGCodecDLInfo);
              stvmGCodecDLInfo.drop_info = 0x0004;
              switch(hdr.codec)
              {
                 case SP4G_CODEC_G711:
                    vmStoreGCodecDLStream(&stvmGCodecDLInfo, (kal_uint16)hdr.len, (kal_uint8 *)&stvmGCodecDLInfo);
                    vmStoreGCodecDLStream(&stvmGCodecDLInfo, (kal_uint16)hdr.len, (kal_uint8 *)&stvmGCodecDLInfo);
                    break;
                 case SP4G_CODEC_G722:
                    break;
                 case SP4G_CODEC_G723_1:
                    break;
                 case SP4G_CODEC_G726:
                    break;
                 case SP4G_CODEC_G729:
                    break;
                 default:
                    break;
              }
          }
          // Record PCM buffer empty info to VM buffer. End.
      }
   }   
//   L1Audio_SetEvent( aud_dl_id, (void *)0 );
}
#endif

void SP4G_Reset( void )
{
   sp4g_reset_flag = 1;
}

kal_bool SP4G_IsDTXOn()
{
   return sp4g_dtx_mode;
}

void SP4G_PSR_SetDTX(kal_bool on)
{
   SP4G_SetDTX(on);
}

void SP4G_SetDTX(kal_bool on)
{
   sp4g_dtx_mode = on;
   kal_trace( TRACE_GROUP_SP4G, SP4G_SET_DTX, on );
   if( L1SP_GetState() == L1SP_STATE_4G_SPEECH_ON )
   {
      uint32 savedMask;
      savedMask = SaveAndSetIRQMask();
	   SAL_3G_SetDtx(on);
      RestoreIRQMask(savedMask);
   }
}

// Force Rx Type to No data frame, used in speech off
void SP4G_SetRxTypeToNoData( void )
{
   SAL_3G_Set_RxType(SAL_3G_RX_NO_DATA);
}

void sp4g_reset_internal( void )
{
   // DL side(G-series)
#if defined(__G_CODEC_SUPPORT__)   
   if(is_g_codec(sp4g->ul_codec_mode)){
      uint32 savedMask;
      int32 len;
      savedMask = SaveAndSetIRQMask();
      //original method
      //len = PCMRB_GetFreeSpace(&pcm_dl_buf);
      //PCMRB_ShiftReadPointer(&pcm_dl_buf, len);  
      //new method 1
      //ASSERT(PCMRB_Init( &pcm_dl_buf, (int16 *)pcm_dl_buf_ptr, (G_SERIAL_CODEC_PCM_RB_BYTE_SIZE>>1)/*1600*/ ) );
      //new method 2
      pcm_dl_buf.read = pcm_dl_buf.write;
      RestoreIRQMask( savedMask );     
      sp4g_reset_flag    = 2;
   }else
#endif
   {
      // DL side 
      sp4g->dl_count     = 0;
      sp4g->dl_write_idx = 0;
      sp4g->dl_read_idx  = 0;
      //kal_prompt_trace(MOD_L1SP, "[PP3] sp4g_reset_flag=%d dl_count=%d %d %d size=%d", sp4g_reset_flag, sp4g->dl_count, sp4g->dl_read_idx, sp4g->dl_write_idx, sp4g->dl_buffer_size);      
   #if defined(__CSHSPA_SUPPORT__)
      //kal_prompt_trace(MOD_L1SP, "[PP3.1] %d", sp4g_max_cs_delay);
      sp4g->dl_buffer_size = sp4g_max_cs_delay;
   #else
      //kal_prompt_trace(MOD_L1SP, "[PP3.2] %d", RAT_4G_DL_BUFFER_NUM_BEFORE_RESYNC);
      sp4g->dl_buffer_size = RAT_4G_DL_BUFFER_NUM_BEFORE_RESYNC;
   #endif
    sp4g->dl_buffer_size = 2;
      //kal_prompt_trace(MOD_L1SP, "[PP4] sp4g_reset_flag=%d dl_count=%d %d %d size=%d", sp4g_reset_flag, sp4g->dl_count, sp4g->dl_read_idx, sp4g->dl_write_idx, sp4g->dl_buffer_size);   
      sp4g_reset_flag    = 0; // clear reset flag, wait it to be 2
   }
   
}

void sp4g_init( void )
{
   int i;

   sp4g_rab_id        = 0;
   for(i=0; i<SP4G_RAB_ID_MAX; i++)
   {
      sp4g_rab_id_record[i] = 0;
   }
   sp4g_rab_state     = KAL_FALSE;
   l1AInfo       = 0;
   sp4g_vm_flag  = KAL_FALSE;
#if defined(__CSHSPA_SUPPORT__)
   sp4g_max_cs_delay = 2;
#endif
   sp4g_dtx_mode = 1;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   _3g_bNeedExtraLog = KAL_TRUE;
#endif

#if defined(__G_CODEC_SUPPORT__)
   pcm_ul_buf_ptr = pcm_dl_buf_ptr = NULL ;
   ul_buf_ptr     = dl_buf_ptr     = NULL ;
#endif

#if defined(__SP4G_UL_RESYNC__)
   SP4G_EMACSyncInfoInUse        = 0;
   SP4G_is_trigger_mac_notify    = KAL_FALSE;
   SP4G_ul_resync_info_available = KAL_FALSE;
#endif
}


void sp4g_speech_init(uint8 RAT_Mode)
{
   ASSERT( RAT_Mode == RAT_4G_MODE  );
   ASSERT( L1SP_GetState() == L1SP_STATE_IDLE );
   //sp_handover_mutex = kal_create_enh_mutex( "SP_HANDOVER_ENH_MUTEX" );
   
   sp4g = (SP4G_Struct*) get_ctrl_buffer(sizeof(SP4G_Struct));

   memset(sp4g, 0, sizeof(SP4G_Struct));
   sp4g->sp4g_mode = RAT_Mode; 
   // UL side
   sp4g->waiting = KAL_FALSE;
  
   sp4g->ul_write_idx = 0;
   sp4g->ul_read_idx = 0;
   sp4g->ul_count = 0;
   sp4g->is_getting_ul_data = KAL_FALSE;
   sp4g->ul_delay = 0;
   sp4g->pre_ul_report = sp4g->pre_dl_report = sp4g->ul_report = sp4g->dl_report = sp4g_est_codec_mode;//INIT_CODEC;
   kal_prompt_trace(MOD_L1SP, "[DEBUG]sp4g_speech_init = %x", sp4g_est_codec_mode) ;
   if( sp4g->sp4g_mode == RAT_4G_MODE )
      sp4g->ul_buffer_size = RAT_4G_UL_BUFFER_NUM;
#ifdef __VIDEO_CALL_SUPPORT__
   else //4G324M
      sp4g->ul_buffer_size = MAX_UL_BUFFER_NUM;
#endif
#if defined(UL_HARD_REAL_TIME_DEMAND)
   sp4g->ul_buffer_size = HARD_REAL_TIME_UL_BUFFER_NUM;
#endif    

//#if defined(__G_CODEC_SUPPORT__)   
   //if(is_g==0)
//#endif      
      sp4g->ul_codec_mode = sp4g_est_codec_mode;//INIT_CODEC;//  use 12.20kbps rate initially
//#if defined(__G_CODEC_SUPPORT__)   
   //else   
      //sp4g->ul_codec_mode = is_g;//  use 12.20kbps rate initially
//#endif      
      
   sp4g->ul_refresh  = KAL_FALSE; // detect change codec_mode  
   sp4g->ul_intrarat = KAL_FALSE;

   // DL side 
   sp4g->dl_count     = 0;
   sp4g->dl_write_idx = 0;
   sp4g->dl_read_idx  = 0;
   
   if( sp4g->sp4g_mode == RAT_4G_MODE ){
         kal_prompt_trace(MOD_L1SP, "[PP5] sp4g_reset_flag=%d dl_count=%d %d %d size=%d", sp4g_reset_flag, sp4g->dl_count, sp4g->dl_read_idx, sp4g->dl_write_idx, sp4g->dl_buffer_size);      
#if defined(__CSHSPA_SUPPORT__)
      kal_prompt_trace(MOD_L1SP, "[PP5.1] %d", sp4g_max_cs_delay);
      sp4g->dl_buffer_size = sp4g_max_cs_delay;
#else
      kal_prompt_trace(MOD_L1SP, "[PP5.2] %d", RAT_4G_DL_BUFFER_NUM_BEFORE_RESYNC);
      sp4g->dl_buffer_size = RAT_4G_DL_BUFFER_NUM_BEFORE_RESYNC;
#endif
      sp4g->dl_buffer_size = 2;
         kal_prompt_trace(MOD_L1SP, "[PP6] sp4g_reset_flag=%d dl_count=%d %d %d size=%d", sp4g_reset_flag, sp4g->dl_count, sp4g->dl_read_idx, sp4g->dl_write_idx, sp4g->dl_buffer_size);
      sp4g_reset_flag    = 1;
   }
   else{  // 4G324M 
      sp4g->dl_buffer_size = MAX_DL_BUFFER_NUM;
      sp4g_reset_flag    = 2;
   }

#if defined(__SP4G_UL_RESYNC__)
   sp4g->time[0]              = 0;  
   sp4g->time[1]              = 0;  
   sp4g->time[2]              = 0;  
   sp4g->ul_request_resync    = KAL_FALSE;
   sp4g->time2nextULHISR      = 0;  //unit: ms
   //SP4G_EMACSyncInfoInUse        = 0;
   //SP4G_is_trigger_mac_notify    = KAL_FALSE;
   //SP4G_ul_resync_info_available = KAL_FALSE;
#endif

#if defined(SP4G_UNIT_TEST)
   L1Audio_HookHisrHandler(DP_D2C_4G,(L1Audio_EventHandler)sp4g_hisr_2, 0);
#else 
#if defined(__G_CODEC_SUPPORT__)
   L1Audio_HookHisrHandler(DP_D2C_4G_PCM_DONE_DL,(L1Audio_EventHandler)sp4g_hisr_dl_g, 0);//fix
   L1Audio_HookHisrHandler(DP_D2C_4G_PCM_DONE_UL,(L1Audio_EventHandler)sp4g_hisr_ul_g, 0);//fix
#endif   
   L1Audio_HookHisrHandler(DP_D2C_4G_AMR_DONE_DL,(L1Audio_EventHandler)sp4g_hisr_dl_amr, 0);//fix
   L1Audio_HookHisrHandler(DP_D2C_4G_AMR_DONE_UL,(L1Audio_EventHandler)sp4g_hisr_ul_amr, 0);//fix   
#endif

#if defined(__G_CODEC_SUPPORT__)
   {  
      kal_uint16 *buffer;
      
      pcm_ul_buf_ptr = (kal_uint16 *)get_ctrl_buffer(G_SERIAL_CODEC_PCM_RB_BYTE_SIZE/*10*160*sizeof(int16)*/);   // 8k, 10 frames
      ASSERT( pcm_ul_buf_ptr!=NULL );      
      ASSERT(PCMRB_Init( &pcm_ul_buf, (int16 *)pcm_ul_buf_ptr, (G_SERIAL_CODEC_PCM_RB_BYTE_SIZE>>1)/*1600*/ ) );
   
      pcm_dl_buf_ptr = (kal_uint16 *)get_ctrl_buffer(G_SERIAL_CODEC_PCM_RB_BYTE_SIZE/*10*160*sizeof(int16)*/);   // 8k, 10 frames
      ASSERT( pcm_dl_buf_ptr!=NULL );      
      ASSERT(PCMRB_Init( &pcm_dl_buf, (int16 *)pcm_dl_buf_ptr, (G_SERIAL_CODEC_PCM_RB_BYTE_SIZE>>1)/*1600*/ ) );
      
      ul_buf_ptr = (kal_uint8 *)get_ctrl_buffer(G_SERIAL_CODEC_STREAM_RB_BYTE_SIZE/*2048*sizeof(uint8)*/);   // 2048 bytes
      ASSERT( ul_buf_ptr!=NULL );      
      ASSERT(StreamRB_Init( &ul_buf, (uint8 *)ul_buf_ptr, G_SERIAL_CODEC_STREAM_RB_BYTE_SIZE/*2048*/ ) );
   
      dl_buf_ptr = (kal_uint8 *)get_ctrl_buffer(G_SERIAL_CODEC_STREAM_RB_BYTE_SIZE/*2048*sizeof(uint8)*/);   // 2048 bytes
      ASSERT( dl_buf_ptr!=NULL );      
      ASSERT(StreamRB_Init( &dl_buf, (uint8 *)dl_buf_ptr, G_SERIAL_CODEC_STREAM_RB_BYTE_SIZE/*2048*/ ) );
      
      aud_dl_id = L1Audio_GetAudioID();
      L1Audio_SetFlag( aud_dl_id );     /* To lock sleep mode */
      aud_ul_id = L1Audio_GetAudioID();
      L1Audio_SetFlag( aud_ul_id );     /* To lock sleep mode */   
      
      L1Audio_SetEventHandler( aud_dl_id, DL_Event );
      L1Audio_SetEventHandler( aud_ul_id, UL_Event );
   }
#endif

   sp4g->l1_info_idx = 0;
   sp4g->dtx_state   = 0;
 }




#if defined(__G_CODEC_SUPPORT__)

void GSeries_Encode_Init(SP4G_Codec codec_)
{
   g_series_mgr.enc_codec = codec_;
   //Encode
   g_series_mgr.enc_hdl         = (G_Series_Handle *)&enc_handle;  //FIX ME 4-byte alignment
   
   switch(g_series_mgr.enc_codec){
      case SP4G_CODEC_G726:
         g_series_mgr.enc_init_param  = (void *)&enc_init_param_g726;
         g_series_mgr.enc_rtime_param = (void *)&enc_rtime_param_g726; 
         break;
      case SP4G_CODEC_G722:  
         g_series_mgr.enc_init_param  = NULL; 
         g_series_mgr.enc_rtime_param = NULL;
         break;
      case SP4G_CODEC_G729:
         g_series_mgr.enc_init_param  = (void *)&enc_init_param_g729;
         g_series_mgr.enc_rtime_param = NULL;  
         break;
      case SP4G_CODEC_G723_1:
         g_series_mgr.enc_init_param  = (void *)&enc_init_param_g723_1;
         g_series_mgr.enc_rtime_param = (void *)&enc_rtime_param_g723_1;  
         break;
      case SP4G_CODEC_G711:
         g_series_mgr.enc_init_param  = (void *)&enc_init_param_g711;
         g_series_mgr.enc_rtime_param = NULL;                      
         break;
   }
   {//Encode     
        G_Series_Handle *p_handle = g_series_mgr.enc_hdl;
        
        // Step 0 : Set handle   
        switch(g_series_mgr.enc_codec){
           case SP4G_CODEC_G726:             
              G726_Enc_Set_Handle(p_handle);                
              break;
           case SP4G_CODEC_G722:                
              G722_Enc_Set_Handle(p_handle);
              break;
           case SP4G_CODEC_G729:    
              G729_Enc_Set_Handle(p_handle); 
              break;   
           case SP4G_CODEC_G723_1:             
              G7231_Enc_Set_Handle(p_handle);              
              break;
           case SP4G_CODEC_G711:                           
              G711_Enc_Set_Handle(p_handle);
              break;
        }
        
        {// Step 1 : Get buffer size
           int int_buf_size, tmp_buf_size, pcm_buf_size, bs_buf_size;
           p_handle->GetBufferSize(&int_buf_size, &tmp_buf_size, &pcm_buf_size, &bs_buf_size);
           kal_prompt_trace(MOD_L1SP, "Encode GetBufferSize %d %d %d %d",int_buf_size, tmp_buf_size, pcm_buf_size, bs_buf_size);
           
           g_series_mgr.enc_tmp_buf     = (void *)enc_tmp_buf;             //FIX ME 4-byte alignment
           g_series_mgr.enc_init_buf    = (void *)enc_init_buf;            //FIX ME 4-byte alignment   
           g_series_mgr.enc_pcm_size    = pcm_buf_size;
           g_series_mgr.enc_bs_size     = bs_buf_size;  
        }
        
        {// Step 2 : Initialize
            switch(g_series_mgr.enc_codec){
               case SP4G_CODEC_G726:
                  ((G726_Enc_Init_Param *)g_series_mgr.enc_init_param)->BitRate = G726_BITRATE_40;            
                  break;
               case SP4G_CODEC_G729:   
                  ((G729_Enc_Init_Param *)g_series_mgr.enc_init_param)->VAD_enable = 1;  
                  ((G729_Enc_Init_Param *)g_series_mgr.enc_init_param)->CNG_enable = 1;  
                  break;       
               case SP4G_CODEC_G723_1: 
                  ((G7231_Enc_Init_Param *)g_series_mgr.enc_init_param)->VAD_enable = 1;  
                  ((G7231_Enc_Init_Param *)g_series_mgr.enc_init_param)->CNG_enable = 1;
                  ((G7231_Enc_Init_Param *)g_series_mgr.enc_init_param)->BitRate = G7231_BITRATE_63;
                  break;   
               case SP4G_CODEC_G711:
                  //((G711_Enc_Init_Param *)g_series_mgr.enc_init_param)->law = G711_ALAW;
				  //fsju
                  ((G711_Enc_Init_Param *)g_series_mgr.enc_init_param)->VAD_enable = (int)SP4G_IsDTXOn();//0;//1; 
                  break;                              
            }
            p_handle->Init(p_handle, 
                           g_series_mgr.enc_init_buf, 
                           g_series_mgr.enc_tmp_buf, 
                           g_series_mgr.enc_init_param);
        }   
   }         
}

int GSeries_Encode_Process(uint16 *pcm_tmp, int *pcm_size, uint8 *encoded_tmp, int *bs_size)
{
   int result;   
   G_Series_Handle *p_handle = g_series_mgr.enc_hdl;
   
   ASSERT( *pcm_size == g_series_mgr.enc_pcm_size);
   *bs_size  = g_series_mgr.enc_bs_size;
   
   switch(g_series_mgr.enc_codec){
      case SP4G_CODEC_G726:
         ((G726_Enc_Runtime_Param *)g_series_mgr.enc_rtime_param)->BitRate = G726_BITRATE_40;   
         break;
      case SP4G_CODEC_G723_1:
         ((G7231_Enc_Runtime_Param *)g_series_mgr.enc_rtime_param)->BitRate = G7231_BITRATE_63;   
         break;         
   }
   
   result = p_handle->Process(p_handle, g_series_mgr.enc_tmp_buf, pcm_tmp, pcm_size, encoded_tmp, bs_size, g_series_mgr.enc_rtime_param); 
   return result;   
}

void GSeries_Encode_DeInit()
{
   
}

void GSeries_Decode_Init(SP4G_Codec codec_)
{
   g_series_mgr.dec_codec = codec_;
   //Decode
   g_series_mgr.dec_hdl         = (G_Series_Handle *)&dec_handle;  //FIX ME 4-byte alignment  
   switch(g_series_mgr.dec_codec){
      case SP4G_CODEC_G726:
         g_series_mgr.dec_init_param  = (void *)&dec_init_param_g726;
         g_series_mgr.dec_rtime_param =  NULL;
         break;
      case SP4G_CODEC_G722:   
         g_series_mgr.dec_init_param  = (void *)&dec_init_param_g722;
         g_series_mgr.dec_rtime_param = (G722_Dec_Runtime_Param*)&dec_rtime_param_g722;
         break;
      case SP4G_CODEC_G729:
         g_series_mgr.dec_init_param  =  NULL;
         g_series_mgr.dec_rtime_param =  NULL;  
            break;  
      case SP4G_CODEC_G723_1:
         g_series_mgr.dec_init_param  =  NULL;
         g_series_mgr.dec_rtime_param =  NULL;   
         break;
      case SP4G_CODEC_G711:   
         g_series_mgr.dec_init_param  = (void *)&dec_init_param_g711;
         g_series_mgr.dec_rtime_param = (G711_Dec_Runtime_Param*)&dec_rtime_param_g711;                      
         break;
   }      
  
   {//Decode     
        G_Series_Handle *p_handle = g_series_mgr.dec_hdl;
        // Step 0 : Set handle
        switch(g_series_mgr.dec_codec){
           case SP4G_CODEC_G726:
              G726_Dec_Set_Handle(p_handle);
              break;
           case SP4G_CODEC_G722:   
              G722_Dec_Set_Handle(p_handle);
              break;
           case SP4G_CODEC_G729:   
              G729_Dec_Set_Handle(p_handle);              
              break;
           case SP4G_CODEC_G723_1:
              G7231_Dec_Set_Handle(p_handle);  
              break;
           case SP4G_CODEC_G711:  
              G711_Dec_Set_Handle(p_handle);
              break; 
        }
        
        {// Step 1 : Get buffer size                                                    
           int int_buf_size, tmp_buf_size, pcm_buf_size, bs_buf_size;
           p_handle->GetBufferSize(&int_buf_size, &tmp_buf_size, &pcm_buf_size, &bs_buf_size);
           kal_prompt_trace(MOD_L1SP, "Decode GetBufferSize %d %d %d %d",int_buf_size, tmp_buf_size, pcm_buf_size, bs_buf_size);
        
           g_series_mgr.dec_tmp_buf     = (void *)dec_tmp_buf;             //FIX ME 4-byte alignment
           g_series_mgr.dec_init_buf    = (void *)dec_init_buf;            //FIX ME 4-byte alignment     
           g_series_mgr.dec_pcm_size    = pcm_buf_size;
           g_series_mgr.dec_bs_size     = bs_buf_size;                  
        }
         
        {// Step 2 : Initialize
           switch(g_series_mgr.dec_codec){
              case SP4G_CODEC_G726:
                 ((G726_Dec_Init_Param *)g_series_mgr.dec_init_param)->BitRate = G726_BITRATE_40;      
                  break;
              case SP4G_CODEC_G722:
                 ((G722_Dec_Init_Param *)g_series_mgr.dec_init_param)->frame_size_in_samples = G722_20MS_PCM_FRAME_SIZE_IN_BYTES/2;      
                  break;   
              case SP4G_CODEC_G711:   
                 //((G711_Dec_Init_Param *)g_series_mgr.dec_init_param)->law = G711_ALAW;  
				 //fsju
                 //((G711_Dec_Init_Param *)g_series_mgr.dec_init_param)->CNG_enable = 0;//1;  
                 break;                
           }      
           p_handle->Init(p_handle, 
                           g_series_mgr.dec_init_buf, 
                           g_series_mgr.dec_tmp_buf, 
                           g_series_mgr.dec_init_param);
        }      
   }        
}

int GSeries_Decode_Process(uint16 *pcm_tmp, int *pcm_size, uint8 *encoded_tmp, int *bs_size)
{
   int result;
   G_Series_Handle *p_handle = g_series_mgr.dec_hdl;
   //int bs_size  = hdr.len*2;//g_series_mgr.dec_bs_size;
   
   ASSERT( *pcm_size == g_series_mgr.dec_pcm_size);
 
   switch(g_series_mgr.dec_codec){
      case SP4G_CODEC_G722:
         ((G722_Dec_Runtime_Param *)g_series_mgr.dec_rtime_param)->bad_frame_indicator = G722PLC_GOOD_FRAME;//G722PLC_BAD_FRAME;   
         ((G722_Dec_Runtime_Param *)g_series_mgr.dec_rtime_param)->mode =  1;
         break;
      case SP4G_CODEC_G711:
         ((G711_Dec_Runtime_Param *)g_series_mgr.dec_rtime_param)->BFI = 0;
		 //fsju
         ((G711_Dec_Runtime_Param *)g_series_mgr.dec_rtime_param)->ENH_enable = 0;//1; 
         break;          
   }
      
   result = p_handle->Process(p_handle, g_series_mgr.dec_tmp_buf, pcm_tmp, pcm_size, encoded_tmp, bs_size, g_series_mgr.dec_rtime_param);    
   return result;
}

void GSeries_Decode_DeInit()
{
   
}
#endif
        
void sp4g_speech_close( void )
{         
#if defined(__G_CODEC_SUPPORT__)   
   L1Audio_UnhookHisrHandler(DP_D2C_4G_PCM_DONE_DL);
   L1Audio_UnhookHisrHandler(DP_D2C_4G_PCM_DONE_UL);
#endif   
   L1Audio_UnhookHisrHandler(DP_D2C_4G_AMR_DONE_DL);
   L1Audio_UnhookHisrHandler(DP_D2C_4G_AMR_DONE_UL); 
   

   free_ctrl_buffer(sp4g);
#if defined(__G_CODEC_SUPPORT__)     
{
   free_ctrl_buffer(pcm_ul_buf_ptr);
   free_ctrl_buffer(pcm_dl_buf_ptr);
   free_ctrl_buffer(ul_buf_ptr);
   free_ctrl_buffer(dl_buf_ptr);
   
   pcm_ul_buf_ptr = pcm_dl_buf_ptr = NULL ;
   ul_buf_ptr     = dl_buf_ptr     = NULL ;


   
   L1Audio_ClearFlag( aud_ul_id );
   L1Audio_FreeAudioID( aud_ul_id );  
   
   L1Audio_ClearFlag( aud_dl_id );
   L1Audio_FreeAudioID( aud_dl_id );   
}
#endif   
   sp4g = (SP4G_Struct*) 0; 
#if defined(__CSHSPA_SUPPORT__)
   sp4g_max_cs_delay = 2;
   //reset to 2 frame
#if defined(CSHSPA_UNIT_TEST) 
	 L1Audio_FreeAudioID(sp4g_hspa_aud_id);
#endif   
#endif
}

void SP4G_Request(void)
{
   kal_trace( TRACE_GROUP_SP4G, SP4G_REQUEST );
   L1SP_4G_Request();
}

kal_uint16 SP4G_PSR_GetCodecBitLength(SP4G_Codec codec) // function call 
{
   int len, I;
   
   if(is_g_codec(codec)){
      ASSERT(false);//FIX ME
   }else{//AMR, WB-AMR      
      if(codec == 25 || codec == AMR_SID_FRAME){
         len= RAB_subflow[codec][0] ;
      }else if(codec == AMR_NO_DATA){
         len = 0;
	   }else{
         for( len = 0, I = 0 ; I < 3 ; I++ )
            len += RAB_subflow[codec][I];            
      }  
   }   
   return len;
}


void SP4G_PSR_UL_SetFrameType(SP4G_Codec codec)
{
   if( L1SP_GetState() != L1SP_STATE_4G_SPEECH_ON){
         return;
   } 
      
   if(is_g_codec(codec)){         
   	if(codec == sp4g->ul_codec_mode){
   		 kal_prompt_trace(MOD_L1SP, "[SP4G]SetCodec is equal %x", codec);
   	     return;	
   	}
      sp4g->ul_codec_mode = codec;
      AM_4G_INTRARAT(codec);
      SP4G_Reset();         
   }else{
      SP4G_UL_SetFrameType(codec);
   }
}

void SP4G_UL_SetFrameType(uint8 amr_frame_type) // function call 
{
   uint8  state;
   uint32 codec;
   sp4g_est_codec_mode = AmrFrameType2DspMode[amr_frame_type]; 
   if( (state = L1SP_GetState()) != L1SP_STATE_4G_SPEECH_ON){
            //if(state == L1SP_STATE_4G_SPEECH_CLOSING)
        
      return;
      //else 
         //ASSERT(false);       
   }      
   
   ASSERT(sp4g != (SP4G_Struct*) 0); 
   
   kal_trace( TRACE_GROUP_SP4G, SP4G_REQUEST_UL_FRAME_TYPE, amr_frame_type);
   codec = AmrFrameType2DspMode[amr_frame_type];      
   if((sp4g->ul_codec_mode >= 0x20 && codec <= 0x0A) ||
      (sp4g->ul_codec_mode <= 0x0A && codec >= 0x20)){//Intrarat
      sp4g->ul_codec_mode = codec;
      AM_4G_INTRARAT(codec);
      //may add at 3G
      sp4g->ul_intrarat = KAL_TRUE;
      SP4G_Reset();
      kal_prompt_trace(MOD_L1SP, "[DEBUG]SP4G_UL_SetFrameType1 %d %d ftype=%d, ul_intrarat=%d", sp4g->ul_codec_mode, codec, amr_frame_type, sp4g->ul_intrarat );
      //L1SP_SetState( L1SP_STATE_4G_SPEECH_ON );
   }else{
      if(sp4g->ul_codec_mode != codec){
         kal_prompt_trace(MOD_L1SP, "[DEBUG]SP4G_UL_SetFrameType2 %d %d ftype=%d, ul_intrarat=%d", sp4g->ul_codec_mode, codec,amr_frame_type, sp4g->ul_intrarat );
         sp4g->ul_codec_mode = codec;
         sp4g->ul_refresh = KAL_TRUE; 
      }
   }
}

// do bit reorder here 
void SP4G_UL_GetSpeechFrame(kal_uint16*frame_index, kal_uint8 *frame_type, kal_uint8 *rab_byte_array, kal_uint8 *len)
{   
   uint8 *ptr8;
   uint32 savedMask;
   int32 I; 
   uint16 sc_mode=0;
   uint8 state;
               
   if( (state = L1SP_GetState()) != L1SP_STATE_4G_SPEECH_ON)
   {
      //if(state == L1SP_STATE_4G_SPEECH_CLOSING)
      {
         *frame_index = 0xABCD;      
         *frame_type = AMR_NO_DATA;
         *len = 0; 
         return;         
      }   
      //else 
         //ASSERT(false);       
         //return;
   }
   
   ASSERT(sp4g != (SP4G_Struct*) 0);
   
   kal_trace( TRACE_GROUP_SP4G, SP4G_UL_GET_SPEECH_FRAME );
       
   ASSERT(sp4g->waiting == KAL_TRUE); // 1 message 1 get , 
                                // should take care if CSR doesn't get by DATA_NOTIFY message 
   savedMask = SaveAndSetIRQMask();
   kal_prompt_trace(MOD_L1SP, "[UL_Sync]SP4G_UL_GetSpeechFrame.1 sp4g_reset_flag=%d", sp4g_reset_flag);
   if( sp4g_reset_flag == 1 ){
      sp4g_reset_internal();
   }
   kal_prompt_trace(MOD_L1SP, "[UL_Sync]SP4G_UL_GetSpeechFrame.2 sp4g_reset_flag=%d", sp4g_reset_flag);
   RestoreIRQMask(savedMask);
   
   if( sp4g->ul_count == 0)// or should repeat last frame
   {
      *frame_type = AMR_NO_DATA;      
      *len = 0;
      return;
   }   

   *frame_index = 0xABCD; // tmp setting , should be apply true value in near future , Adam 
        
   sp4g->is_getting_ul_data = KAL_TRUE;
           
   ptr8 = (uint8*)sp4g->ul_buffer[sp4g->ul_read_idx];
    
   *frame_type = *ptr8;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   if (_3g_bNeedExtraLog == true){
   	uint8 *tmp_ = (uint8*)sp4g->ul_buffer[sp4g->ul_read_idx];
      //kal_prompt_trace(MOD_L1SP,"SP4G UL Type %d, Frm %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x",
      //   *frame_type, ptr8[0], ptr8[1],ptr8[2],ptr8[3],ptr8[4],
      //   ptr8[5],ptr8[6],ptr8[7],ptr8[8],ptr8[9],ptr8[10],ptr8[11],ptr8[12],ptr8[13],ptr8[14],ptr8[15], ptr8[16],ptr8[17],ptr8[18],ptr8[19],ptr8[20]);
      kal_prompt_trace(MOD_L1SP, "Debug_UL_GetSpeechFrame %d", sp4g->ul_read_idx);
      kal_trace(TRACE_GROUP_SP4G, SP4G_UL_BIT_TRUE_F8,
         0, *frame_type, tmp_[0], tmp_[1],tmp_[2],tmp_[3],tmp_[4],tmp_[5],tmp_[6],tmp_[7]);
      kal_trace(TRACE_GROUP_SP4G, SP4G_UL_BIT_TRUE_N13,
         tmp_[8],tmp_[9],tmp_[10],tmp_[11],tmp_[12],tmp_[13],tmp_[14],tmp_[15],
         tmp_[16],tmp_[17],tmp_[18],tmp_[19],tmp_[20]);
   }
#endif //#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)

   if(*frame_type < AMR_SID_FRAME)
      sc_mode = AmrFrameType2DspMode[*frame_type];
#ifdef __AMRWB_LINK_SUPPORT__
   else if(*frame_type >= 16 && *frame_type <= 24){
      sc_mode = AmrFrameType2DspMode[*frame_type];
      *ptr8 -= 16;//in subflow data, remap to 0~8?????
   }else if( *frame_type == 25 ){ //WB AMR SID
      *ptr8 = AWB_SID_FRAME; //in subflow data, remap to 9
   }
#endif //#ifdef __AMRWB_LINK_SUPPORT__

   ptr8++;
   //if((*frame_type < 8) && sc_mode < sp4g->ul_codec_mode) // maximum bit_rate limitation 
  /* if( sc_mode != sp4g->ul_codec_mode) // 4G Uplink, when the codec inconsistency between DSP and CSR, driver provides NO_DATA frame to PSR
   {      
      *frame_type = AMR_NO_DATA;
      *len = 0; 
   }    
   else */
   {      
      *len = *ptr8++;
#ifdef __AMRWB_LINK_SUPPORT__
      ASSERT( *len <= 60 );
#else
      ASSERT( *len <= 32 );
#endif
      for( I = *len; --I >= 0 ; ) 
         *rab_byte_array++ = *ptr8++;
   } 
   savedMask = SaveAndSetIRQMask();
   sp4g->waiting = KAL_FALSE;
   sp4g->ul_delay = 0;
   sp4g->ul_count--;
   RestoreIRQMask(savedMask);
   sp4g->ul_read_idx++;
   if( sp4g->ul_read_idx == sp4g->ul_buffer_size )
      sp4g->ul_read_idx = 0;
   sp4g->is_getting_ul_data = KAL_FALSE;
}

#ifdef __AMRWB_LINK_SUPPORT__
static const uint8 last_sub_flow_id[26] = { 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 
	                                         1, 1, 1, 1, 1, 1, 1, 1, 1};
#else
static const uint8 last_sub_flow_id[16] = { 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0};
#endif

// do bit reorder here 
void SP4G_DL_PutSpeechFrame(uint32 CFN, uint8 sub_flow_id, uint8 frame_type, bool crc_status, uint8 *subflow)
{
   uint32 savedMask;
   int32 I;
   uint8 *ptr8; 
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   uint8 *ptr8_bak;
#endif
   uint16 rabBitsCount, state;
   uint8 last_id;         
   if( (state = L1SP_GetState()) != L1SP_STATE_4G_SPEECH_ON)
   {
      if(state == L1SP_STATE_4G_SPEECH_CLOSING)
         return;
      else 
         //ASSERT(false);       
         return;
   }
   
   ASSERT(sp4g != (SP4G_Struct*) 0);
   
   kal_trace( TRACE_GROUP_SP4G, SP4G_DL_PUT_SPEECH_FRAME, sub_flow_id, frame_type, crc_status );
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   if(frame_type == SP4G_CODEC_LOST_FRAME){
      kal_prompt_trace(MOD_L1SP, "SP4G DL Frm -- -- -- -- --");
   }else{
      if( sub_flow_id == 0 ) {
         kal_trace(TRACE_GROUP_SP4G, SP4G_DL_BIT_TRUE_TASK, subflow[0], subflow[1],subflow[2],subflow[3],subflow[4]);
      }
   }
#endif
   //if( frame_type == AMR_NO_DATA )
   //   return;
            
#ifdef __AMRWB_LINK_SUPPORT__
   ASSERT( frame_type <= 25 || frame_type == SP4G_CODEC_LOST_FRAME);
#else
   ASSERT( (frame_type <= 8 || frame_type ==15 || frame_type == SP4G_CODEC_LOST_FRAME) );
#endif
   

   kal_prompt_trace(MOD_L1SP, "[P1] sp4g_reset_flag=%d dl_count=%d %d %d size=%d", sp4g_reset_flag, sp4g->dl_count, sp4g->dl_read_idx, sp4g->dl_write_idx, sp4g->dl_buffer_size);
      
   if(frame_type == SP4G_CODEC_LOST_FRAME)
   	  last_id = 0;
   else
   	  last_id = last_sub_flow_id[frame_type];
   	  
   if( sub_flow_id > last_id ) 
      return; 
   savedMask = SaveAndSetIRQMask();   
   if( sp4g->dl_count >= sp4g->dl_buffer_size ) 
   {      
      sp4g->dl_read_idx++;
      if( sp4g->dl_read_idx >= sp4g->dl_buffer_size )
         sp4g->dl_read_idx = 0;
      sp4g->dl_count --;
   }//keep only 2 frame
   RestoreIRQMask(savedMask);
   kal_prompt_trace(MOD_L1SP, "[P2] sp4g_reset_flag=%d dl_count=%d %d %d size=%d", sp4g_reset_flag, sp4g->dl_count, sp4g->dl_read_idx, sp4g->dl_write_idx, sp4g->dl_buffer_size);
   ptr8 = sp4g->dl_buffer[sp4g->dl_write_idx];
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   ptr8_bak = sp4g->dl_buffer2[sp4g->dl_write_idx];
#endif
   if( sub_flow_id == 0 )
   {
      //frame_len = RAB_subflow[frame_type][3];
      
      // before first RB-subflow write
      *ptr8++ = frame_type;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      *ptr8_bak++ = frame_type;
#endif
      *ptr8++ = (uint8)crc_status;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      *ptr8_bak++ = (uint8)crc_status;
#endif
      *ptr8++ = CFN & 0xFF; 
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      *ptr8_bak++ = CFN & 0xFF; 
#endif
      *ptr8++ = (CFN >> 8) & 0xFF; 
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      *ptr8_bak++ = (CFN >> 8) & 0xFF; 
#endif
      *ptr8++ = (CFN >> 16) & 0xFF; 
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      *ptr8_bak++ = (CFN >> 16) & 0xFF; 
#endif
      *ptr8++ = (CFN >> 24) & 0xFF;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      *ptr8_bak++ = (CFN >> 24) & 0xFF;
#endif
   }
   else 
   {
#ifdef __AMRWB_LINK_SUPPORT__
      if( frame_type > AMR_NO_DATA && sub_flow_id == 1 ){
         //For WB-AMR, the frame type can not be differed in subflow 0,
         // so that update it at subflow 1
         *ptr8 = frame_type;//Range 16~25
      }
#endif      
      //kal_prompt_trace(MOD_L1SP,"SP4G DL r=%d,w=%d,n=%d",sp4g->dl_read,sp4g->dl_write,sp4g->dl_count);      
      ptr8 += 6;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      ptr8_bak += 6;
#endif
      for(I = 0 ; I < sub_flow_id ; I ++)
      {
         rabBitsCount = RAB_subflow[frame_type][I]; 
         ptr8 += (rabBitsCount + 7) >> 3;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
         ptr8_bak += (rabBitsCount + 7) >> 3;
#endif
      }   
   }
   
   if(frame_type == SP4G_CODEC_LOST_FRAME)
   	  rabBitsCount = 0;
   else	  
        rabBitsCount = RAB_subflow[frame_type][sub_flow_id]; 
   
   for( I = 0; I < (rabBitsCount + 7) >> 3; I++ ){
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      *ptr8++ = *subflow;
      *ptr8_bak++ = *subflow++;
#else
      *ptr8++ = *subflow++;
#endif
   }
      
   // after last RB-subflow write
   if( sub_flow_id == last_id ) 
   {
      //kal_uint8 u8CheckBufFinish = 0;
      kal_prompt_trace(MOD_L1SP, "[P3] sp4g_reset_flag=%d dl_count=%d %d %d size=%d", sp4g_reset_flag, sp4g->dl_count, sp4g->dl_read_idx, sp4g->dl_write_idx, sp4g->dl_buffer_size);
      sp4g->dl_write_idx++;
      if( sp4g->dl_write_idx >= sp4g->dl_buffer_size )
         sp4g->dl_write_idx = 0;
      kal_prompt_trace(MOD_L1SP, "[P4] sp4g_reset_flag=%d dl_count=%d %d %d size=%d", sp4g_reset_flag, sp4g->dl_count, sp4g->dl_read_idx, sp4g->dl_write_idx, sp4g->dl_buffer_size);

      savedMask = SaveAndSetIRQMask();
      sp4g->dl_count ++;
         
      //if( sp4g->dl_count == sp4g->dl_buffer_size && sp4g_reset_flag == 0 ){      
      if( sp4g->dl_count == DL_4G_THRESHOLD && sp4g_reset_flag == 0 ){
         sp4g_reset_flag = 2;// reset done
         //u8CheckBufFinish = 2;
      }      
      RestoreIRQMask(savedMask);

   }
}

// #if defined(__VM_CODEC_SUPPORT__) // always on
void SP4G_Start_VM( void ) 
{
   sp4g_vm_flag = KAL_TRUE;
}

void SP4G_Stop_VM( void ) 
{
   sp4g_vm_flag = KAL_FALSE;
}

bool SP4G_VM_Status( void )
{
   return sp4g_vm_flag;
}
// #endif

typedef struct
{
   kal_uint8 RSSI;
   kal_uint8 RSCP;
   kal_uint8 ECIO;
   kal_uint8 HHO_SHO;
/* Used by UMAC */ 
    /* Modified CRC = CRC |(S value decision) 
        S value decision=1 => S value < S Threshold. this frame is not reliable
        S value decision =0 => S value > S Threshold. This frame is reliable

        Modified CRC =0, speech good, CRC=0, S value decision =0 
        Modified CRC=1, CRC =1 or S value decision=1

        crc_result value meaning : 
        0 : Modified CRC =  0
        1 : Modified CRC = 1, CRC = 0
        2 : Modified CRC = 1, CRC = 1
        */
   kal_uint8 crc_result[3]; /* For Class A/B/C */
   kal_uint32 s_value[3];  /* For Class A/B/C */

   kal_int16      tpc_SIR_lta;            // For recording into speech VM
   kal_int16      dpdch_SIR_lta;          // For recording into speech VM
   kal_int16      TFCI_max_corr;          // For recording into speech VM                                              
}L1_info_struct;

void SP4G_Log_L1_Info(uint32 CFN, L1_info_struct *p_L1_Info)
{
   uint32 *l1_info; 
   uint32 l1_data, crc_result;
   
   if(sp4g == (SP4G_Struct*) 0)
      return;
   
   l1_info = sp4g->L1_Info[sp4g->l1_info_idx++];
   sp4g->l1_info_idx &= 0x3; 
   
   l1_info[0] = CFN;
   l1_data = (uint32)(p_L1_Info->RSSI) + ((uint32)(p_L1_Info->RSCP) << 8) + 
              ((uint32)(p_L1_Info->ECIO) << 16) + ((uint32)(p_L1_Info->HHO_SHO) << 24);
   crc_result = (uint32)(p_L1_Info->crc_result[0]) + ((uint32)(p_L1_Info->crc_result[1]) << 8) + 
              ((uint32)(p_L1_Info->crc_result[2]) << 16);
   l1_info[1] = l1_data;
   l1_info[2] = crc_result;
   l1_info[3] = p_L1_Info->s_value[0];
   l1_info[4] = (uint32)p_L1_Info->tpc_SIR_lta;
   l1_info[5] = (uint32)p_L1_Info->dpdch_SIR_lta;
   l1_info[6] = (uint32)p_L1_Info->TFCI_max_corr;
   kal_trace( TRACE_GROUP_SP4G, SP4G_LOG_L1_INFO,
      l1_info[0], l1_info[1], crc_result, p_L1_Info->s_value[0], p_L1_Info->s_value[1],p_L1_Info->s_value[2]);
}

void SP4G_Closed_Confirm( void )
{
   //ASSERT( L1SP_GetState() == L1SP_STATE_4G_SPEECH_CLOSING );
   //L1SP_SetState(L1SP_STATE_4G_SPEECH_CLOSED);
}
/*====================== CS over HSPA interface ============================*/
                                        
SP4G_PSR_Codec SP4G_PSR_UL_GetSpeechFrameType()
{
   SP4G_PSR_Codec codec;

   if(is_g_codec(sp4g->ul_codec_mode)){
      ASSERT(false);//FIX ME
   }else{  

   	if( (sp4g->ul_codec_mode >= 0x20) && (sp4g->ul_codec_mode <= 0x28)){
   		codec = SP4G_PSR_WBAMR;
   	}else if ((sp4g->ul_codec_mode >= 0x03) && (sp4g->ul_codec_mode <= 0x0A)){
   		codec = SP4G_PSR_AMR;
   	}else{
   	   ASSERT(false);//FIX ME
   	}
   }   

   return codec;
}

void SP4G_PSR_UL_AMR_GetSpeechFrame(SP4G_Codec *frame_type, kal_uint8 *encodebits, kal_uint8 *bitlen)
{
     SP4GHSPA_UL_GetSpeechFrame(frame_type, encodebits, bitlen);
}



#if 1//defined(__CSHSPA_SUPPORT__)
void SP4GHSPA_UL_GetSpeechFrame(kal_uint8 *frame_type, kal_uint8 *rab_byte_array, kal_uint8 *len)
{
   kal_uint16 frame_index, I, J, K, rabBitsCount;
   kal_uint8  *ptr8, *ptr8_swap, byte_swap, bit8Data;

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
#else
//#if 1
   SP4G_UL_GetSpeechFrame(&frame_index, frame_type, rab_byte_array, len);
   //reorder to AMR IF1
   if( *frame_type != AMR_NO_DATA && *frame_type != 25 && *frame_type != AMR_SID_FRAME )
   {
      ptr8 = rab_byte_array;
      ptr8_swap = rab_byte_array;
      byte_swap = *ptr8_swap;
      *ptr8 = 0;
      K = 0;
      for( I = 0 ; I < 3 ; I++ ){
         rabBitsCount = RAB_subflow[*frame_type][I];
         for( J = 0; J < rabBitsCount ; J++, K++ ){
            bit8Data = (byte_swap & RAB_Order[J & 7])? RAB_Order[K & 7] : 0; 
            *ptr8 |= bit8Data;
            if( (J&7) == 7 ){
               ptr8_swap++;
               byte_swap = *ptr8_swap;
            }
            if( (K&7) == 7 ){
               ptr8++;
               *ptr8 = 0;
            }
         }
         if( (J&7) != 0 ){ // avoid false advance a byte
            ptr8_swap++;
            byte_swap = *ptr8_swap;
         }
      }
      //recalculate rab length
      rabBitsCount = 0;
      for( I = 0 ; I < 3 ; I++ )
         rabBitsCount += RAB_subflow[*frame_type][I];
      *len = ((rabBitsCount+7)>>3);
   }
#endif   
   kal_trace( TRACE_GROUP_SP4G, SP4G_HSPA_UL_GET_SPEECH_FRAME, *frame_type, *len, rab_byte_array[0], rab_byte_array[1] );
}

/*
By RFC3267, use the IF1 format
*/
void SP4G_PSR_DL_AMR_PutSpeechFrame(kal_uint32 CFN, SP4G_PSR_Codec codec, SP4G_Codec frame_type, kal_uint8 *encodebits)
{   	
   	//band mismatch . assert

#if defined(__G_CODEC_SUPPORT__)
    if(is_g_codec(sp4g->ul_codec_mode)){
		kal_prompt_trace(MOD_L1SP,"SP4G_PSR_DL_AMR_PutSpeechFrame: now is G codec, skip this data flow.");
		return;
    }
#endif /*#if defined(__G_CODEC_SUPPORT__)*/
	
   	if(NULL != encodebits){
   	   kal_prompt_trace(MOD_L1SP,"SP4G_PSR_DL_AMR_PutSpeechFrame codec=%d frame_type=%d ul_codec_mode=%d", codec, frame_type, sp4g->ul_codec_mode);
   	   ASSERT( (codec ==SP4G_PSR_AMR   && sp4g->ul_codec_mode >= 0x03 && sp4g->ul_codec_mode <= 0x0A) ||
   	           (codec ==SP4G_PSR_WBAMR && sp4g->ul_codec_mode >= 0x20 && sp4g->ul_codec_mode <= 0x28)
   	       );
   	       
      	ASSERT( (frame_type >= SP4G_CODEC_AMR_4_75  && frame_type <= SP4G_CODEC_AMR_SID   && sp4g->ul_codec_mode >= 0x03 && sp4g->ul_codec_mode <= 0x0A) ||
      	        (frame_type >= SP4G_CODEC_WBAMR_6_6 && frame_type <= SP4G_CODEC_WBAMR_SID && sp4g->ul_codec_mode >= 0x20 && sp4g->ul_codec_mode <= 0x28)
      	       );  	   
      	       
   	   SP4GHSPA_DL_PutSpeechFrame(CFN, frame_type, 1, encodebits);
   	}else{
   	   kal_prompt_trace(MOD_L1SP,"SP4G_PSR_DL_AMR_PutSpeechFrame LOST_FRAME");

   	   SP4GHSPA_DL_PutSpeechFrame(CFN, SP4G_CODEC_LOST_FRAME, 1, NULL);
   	}
}

void SP4GHSPA_DL_PutSpeechFrame(kal_uint32 CFN, kal_uint8 frame_type, kal_bool crc_status, kal_uint8 *subflow)
{
   kal_trace( TRACE_GROUP_SP4G, SP4G_HSPA_DL_PUT_SPEECH_FRAME, frame_type, CFN, crc_status, subflow[0],subflow[1]);
   if( frame_type != AMR_NO_DATA && frame_type != 25 && frame_type != AMR_SID_FRAME && frame_type != SP4G_CODEC_LOST_FRAME ){
      kal_uint16 I, J, K, rabBitsCount;
      kal_uint8  *ptr8, *ptr8_swap, byte_swap, bit8Data;
      
      K = 0;
      ptr8_swap = subflow;
      byte_swap = *ptr8_swap;
      for( I = 0 ; I < 3 ; I++ ){
         rabBitsCount = RAB_subflow[frame_type][I];
         if( rabBitsCount == 0 )
            break;
         ptr8 = &sp4g->dl_subflow[0];
         *ptr8 = 0;//reset
         for( J = 0; J < rabBitsCount ; J++, K++ ){
            bit8Data = (byte_swap & RAB_Order[K & 7])? RAB_Order[J & 7] : 0; 
            *ptr8 |= bit8Data;
            if( (J&7) == 7 ){
               ptr8++;
               *ptr8 = 0;
            }
            if( (K&7) == 7 ){
               ptr8_swap++;
               byte_swap = *ptr8_swap;
            }
         }
         SP4G_DL_PutSpeechFrame(CFN, I, frame_type, crc_status, sp4g->dl_subflow);
      }
   } else {
      SP4G_DL_PutSpeechFrame(CFN, 0, frame_type, crc_status, subflow);
   }
}

void SP4GHSPA_DL_SetMaxCsDelay(kal_uint8 max_cs_delay)
{
   uint32 savedMask;   
   kal_trace( TRACE_GROUP_SP4G, SP4G_HSPA_DL_MAX_CS_DELAY, max_cs_delay);

}

#endif // if defined(__CSHSPA_SUPPORT__)
/*====================== 4G 324M interface==================================*/


//fake loopback
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
#endif //#if 0


#endif // __UMTS_RAT__  || defined( __UMTS_TDD128_MODE__ )
