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
 * sp_3g.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   3G speech interface
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
 * 06 14 2012 kh.hung
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
 * 07 13 2011 kh.hung
 * removed!
 * .
 *
 * 07 12 2011 kh.hung
 * removed!
 * .
 *
 * 07 06 2011 kh.hung
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 *
 *******************************************************************************/

#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "l1audio_trace.h"
#include "string.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "reg_base.h"
                 
#include "l1audio.h"  
#include "l1audio_def.h"                                       
#include "fc_def.h"                                                                  
#include "media.h" 
#include "l1sp_trc.h"
#include "exp_SphFasTypDef.h"
#include "audio_enum.h"
#if defined( __UMTS_RAT__ )
//Temp setting, JY
//#define __CSHSPA_SUPPORT__

#define _EXTRA_LOG_FOR_BIT_TRUE_
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
kal_bool CS_NeedSpeechExtraLog( void );
kal_bool g_bNeedExtraLog;
#endif

extern void L1SP_3G_Request(void);

#if 1
enum TXFrameType {
   TX_SPEECH_GOOD = 0,
   TX_SID_FIRST,
   TX_SID_UPDATE,
   TX_NO_DATA,
   TX_SPEECH_DEGRADED,
   TX_SPEECH_BAD,
   TX_SID_BAD,
   TX_ONSET,
   TX_N_FRAMETYPES     /* number of frame types */
};
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 1
enum RXFrameType {
   RX_SPEECH_GOOD = 0,
   RX_SPEECH_DEGRADED,
   RX_ONSET,
   RX_SPEECH_BAD,
   RX_SID_FIRST,
   RX_SID_UPDATE,
   RX_SID_BAD,
   RX_NO_DATA,
   RX_N_FRAMETYPES     /* number of frame types */
};
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#define AMR_SID_FRAME   8
#define AMR_NO_DATA     15 
#define AWB_SID_FRAME   9

//#define UL_HARD_REAL_TIME_DEMAND 

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


#define HARD_REAL_TIME_UL_BUFFER_NUM 1 // could not revise 
#define RAT_3G_UL_BUFFER_NUM 2  // could not revise 
#define RAT_3G_DL_BUFFER_NUM 2  // do not suggest to revise 

#ifdef __VIDEO_CALL_SUPPORT__
#define MAX_UL_BUFFER_NUM  5
#define MAX_DL_BUFFER_NUM  20
#elif defined(__CSHSPA_SUPPORT__)
#define MAX_UL_BUFFER_NUM  2
//In theory, Max CS delay is 200ms at most, which is 10 frames
#define MAX_DL_BUFFER_NUM  10
#else 
#define MAX_UL_BUFFER_NUM  RAT_3G_UL_BUFFER_NUM
#define MAX_DL_BUFFER_NUM  RAT_3G_DL_BUFFER_NUM
#endif 

// here should be careful for this will limit MAX_DL_BUFFER_NUM to 1 << DL_BUF_INDEX_BIT_NUM 
//                                        and MAX_UL_BUFFER_NUM to 1 << UL_BUF_INDEX_BIT_NUM      
#define DL_BUF_INDEX_BIT_NUM 5 
#define UL_BUF_INDEX_BIT_NUM (8 - DL_BUF_INDEX_BIT_NUM)

#define SP3G324M_DL_EXTRA_LEN 5//frameType(1), len(1), l1_frame : recieve(3)
#define SP3G_DL_EXTRA_LEN     6//frameType(1), FQI_flag(1), CFN(4)(unit:byte)
#if defined(__AMRWB_LINK_SUPPORT__)
//AMRWB 23.85 classB 405 bits=>51 bytes
#define MAX_BYTES_IN_SINGLE_SUBFLOW ((405 + 7)>>3)
#else
//AMR 12.2 classB 103 bits=>13 bytes
#define MAX_BYTES_IN_SINGLE_SUBFLOW ((103 + 7)>>3)
#endif

#define _IGNORE_TYPE_ERROR_   // for 3G324M since the CRC is weaker, it's possible wrong pattern.
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
   uint8 ul_buffer[MAX_UL_BUFFER_NUM][UL_MAX_DATA_SIZE]; // prevent sp3g_hisr , CSR race condition
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
   uint8 l1_info_idx;
   uint8 sp3g_mode;
   uint8 ul_buffer_size;
   uint8 dl_buffer_size;
   uint8 dtx_state;  //enter dtx mode
   uint8 dtx_force;  //occured that force AMR frame
#if defined(__CSHSPA_SUPPORT__)
   uint8 dl_subflow[MAX_BYTES_IN_SINGLE_SUBFLOW];
#endif
}SP3G_Struct;

#define SP3G_RESET_BY_SPEECH_ON 0
#define SP3G_RESET_BY_INTERRAT  1
SP3G_Struct *sp3g;
uint8  sp3g_codec_mode = 0xA;
extern SAC_Sph3GCallPar_t SAC_Sph3GCallPar;
extern SAC_SphHandoverPar_t SAC_SphHandoverPar;
static kal_uint32 sp3g_rab_id;
static kal_bool   sp3g_rab_state;
static kal_uint32 l1AInfo;
static bool       sp3g_vm_flag;
static kal_uint8  sp3g_reset_flag; // speech on and InterRAT : set TRUE
static kal_uint8  sp3g_reset_source;
static kal_bool  sp3g_dtx_mode;
kal_enhmutexid sp3g_mutex;

#if defined(__CSHSPA_SUPPORT__)
static kal_uint8  sp3g_max_cs_delay;
#endif

__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
SAC_Sph3GL1Info_t sp3g_dlDebugInfo, sp3g_ulDebugInfo;

__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI"))) 
uint16            sp3g_dlDebugBuf[12+DL_MAX_DATA_SIZE/2], sp3g_ulDebugBuf[UL_MAX_DATA_SIZE/2];


uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );

#ifdef __AMRWB_LINK_SUPPORT__
#define RAB_SUBFLOW_ARRAY 26
#else
#define RAB_SUBFLOW_ARRAY 16
#endif

const uint16 RAB_subflow[RAB_SUBFLOW_ARRAY][4] = {
   {42, 53,  0, 13}, // 4.75
   {49, 54,  0, 14}, // 5.15 
   {55, 63,  0, 15}, // 5.9 
   {58, 76,  0, 18}, // 6.7 
   {61, 87,  0, 19}, // 7.4 
   {75, 84,  0, 21}, // 7.95
   {65, 99, 40, 27}, // 10.2 
   {81, 103,60, 32}, // 12.2
   {39,  0,  0,  5}, // SID  
   {39,  0,  0,  5}, // GSM-EFR SID
   {39,  0,  0,  5}, // TDMA_EFR SID
   {39,  0,  0,  5}, // PDC-EFR SID
   {39,  0,  0,  5}, // For Future use
   {39,  0,  0,  5}, // For Future use
   {39,  0,  0,  5}, // For Future use
   {39,  0,  0,  0}, // No data,  Not Used
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
      
const uint8 RAB_Order[8] = {
   0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01   /* bits order of AMR frame */
};

const uint16 DSP_Order[16] = {
   0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0080,   /* bits order of SHERIF */
   0x0100,0x0200,0x0400,0x0800,0x1000,0x2000,0x4000,0x8000
};
#ifdef __VIDEO_CALL_SUPPORT__
const uint8 AMR_IF2_Order[8] = {
   0x10,0x20,0x40,0x80,0x01,0x02,0x04,0x08   /* bits order of AMR IF2 frame */
};

const uint8 AMR_IF2_FRAME_LENGTH[16] = {/* byte length of AMR IF2 frame */
   13, 14, 16, 18, 19, 21, 26, 31, 6,
   0 ,  0,  0,  0,  0,  0,  1
};
#endif

#ifdef __AMRWB_LINK_SUPPORT__
const uint8 AmrFrameType2DspMode[25] = {0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0, 0, 0, 0, 0, 0, 0, 0,\
                                        0xB, 0xC, 0xD, 0xE, 0xF,0x10,0x11,0x12,0x13};
const uint8 DspMode2AmrFrameType[17] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x10, 0x11, 0x12, \
                                        0x13, 0x14,0x15,0x16,0x17,0x18};
const uint8 DspModeLen[17] = {6, 7, 8, 9, 10, 10, 13, 16, 9, 12, 16, 18, 20, 23, 25, 29, 30};
const uint8 DspMode_AMRLen[17] = {13, 14, 15, 18, 19, 21, 27, 32, 17, 23, 32, 36, 40, 46, 50, 58, 60};
#else
const uint8 AmrFrameType2DspMode[8] = {0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA};
const uint8 DspMode2AmrFrameType[8] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7}; 
const uint8 DspModeLen[8] = {6, 7, 8, 9, 10, 10, 13, 16};
const uint8 DspMode_AMRLen[8] = {13, 14, 15, 18, 19, 21, 27, 32};
#endif

extern const uint8* tblAMROrder[8];
extern const uint8* tblAMR_WBOrder[9];

#define AMR_DATA_LOG

#if defined(__L1_STANDALONE__)
void CSR_SP3G_Callback( SP3G_Event event, void *data){}
#else 
extern void CSR_SP3G_Callback( SP3G_Event event, void *data );
#endif

extern uint32 L1I_GetTimeStamp( void );

#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
kal_bool CS_NeedSpeechExtraLog( void )
{
   return g_bNeedExtraLog;
}
#endif

extern void sp3g_vmRecordService( uint32 *l1_info, uint16 crc_result, uint16 buf_status, uint16 *ul_frame_data, uint16* dl_frame_data, kal_bool bBufferOK);

/* SP3G_UpdateL1InFo                                                          */ 
/* called by L1A to update DCH on/off and TX in/off(DCH UL on/off)            */
/* bit 0: DCH on/off (1: on, 0: off)                                          */
/* bit 1: DCH UL on/off (1: on, 0: off)                                       */
/* bit 2: indicate RLF status (1: indicate RLF, 0: reset RLF)                 */
/* bit 3: 3 bits to indicate DCH setup type                                   */
void SP3G_UpdateL1AInFo( kal_uint8 bitmap, kal_uint8 value )
{
   uint32 savedMask;
   
   ASSERT( bitmap <= 3 );
   kal_trace( TRACE_GROUP_SP3G, SP3G_L1A_UPDATE_INFO, bitmap, value);
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

//CSR inform RAB is established, the rab_id should be set as parameter when callback to CSR
void SP3G_Rab_Est( uint32 rab_id, kal_uint8 default_speech_codec )
{
   sp3g_rab_id    = rab_id;
   sp3g_rab_state = KAL_TRUE;
   kal_trace( TRACE_GROUP_SP3G, SP3G_RAB_EST, AmrFrameType2DspMode[default_speech_codec] );
   if( L1SP_GetState() == L1SP_STATE_2G_SPEECH_ON ){//prepare InterRAT HO
      CSR_SP3G_Callback(SP3G_CODEC_READY, (void*)sp3g_rab_id );
      SP3G_Reset();
      L1SP_InterRATHO( 0 );//0:G2W, 1:W2G
   }
}

void SP3G_Rab_Deest( void )
{
   sp3g_rab_state = KAL_FALSE;
   kal_trace( TRACE_GROUP_SP3G, SP3G_RAB_DEEST );
   if( L1SP_TCH_State() && L1SP_GetState() != L1SP_STATE_2G_SPEECH_ON && L1SP_GetState() != L1SP_STATE_IDLE ){//2G->3G fail case
      CSR_SP3G_Callback(SP3G_CODEC_CLOSED, (void*)sp3g_rab_id );
      L1SP_InterRATHO( 1 );//0:G2W, 1:W2G
   }
}

kal_bool SP3G_Rab_State( void )
{
   return sp3g_rab_state;
}

kal_uint32 SP3G_Rab_Id( void )
{
   return sp3g_rab_id;
}

void SP3G_ProcessUL(kal_uint32 msgData16, kal_uint32 msgData32)
{
   int32 I, J = 0, K;
   uint16 *ptr16;
   uint16 tx_type, sc_mode;
   uint8 *ptr8;
   uint8 len;
   const uint8* RAB_To_DSP_Mapping; //, *Order = NULL;
   uint16 total_bits, idx, rabBitsCount;
   uint8 frame_type = 0,bit8Data;  
   bool bWrite;
   
   SAS_3GCallRequestReadUlData_t *payload;
   
   if(L1SP_GetState() == L1SP_STATE_3G_SPEECH_CLOSING)
      return;
   ASSERT(sp3g != (SP3G_Struct*) 0);
   
   payload = (SAS_3GCallRequestReadUlData_t *)msgData32;
   ASSERT(payload->u4CodModUl >=3 && payload->u4CodModUl <= 0x13 );
   sp3g->ul_report = (kal_uint8)payload->u4CodModUl;
   //ASSERT(sp3g->ul_report >=3 && sp3g->ul_report <= 0x13 )
   if( sp3g->ul_report != sp3g->pre_ul_report ){
      L1Audio_Msg_SPEECH_CODEC( L1SP_Speech_Codec_Mode(sp3g->ul_report), L1SP_Speech_Codec_Mode(sp3g->dl_report) );
      sp3g->pre_ul_report = sp3g->ul_report;
   }
   // UL side    
   kal_take_enh_mutex( sp3g_mutex );
   ptr16 = (uint16*)sp3g->dsp_buffer;
   {
      // get data from DSP UL buffer
      uint16 *addr;

      tx_type = payload->u4TxTyp;
      ASSERT(tx_type >=TX_SPEECH_GOOD && tx_type < TX_N_FRAMETYPES );
      sc_mode =  sp3g->ul_report;
      addr = (uint16*) payload->pucUlBufPtr;
      //ASSERT(DspModeLen[sc_mode - 3] != (payload->u4UlLen + 1)>>1 );
      for(I = DspModeLen[sc_mode - 3]; --I >= 0 ; )
         *ptr16++ = *addr++;
   }
   
   // do bit re-ordering  
   ptr16 = (uint16*)sp3g->dsp_buffer;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   if (g_bNeedExtraLog == true){
      ptr16 = (uint16*)sp3g->dsp_buffer;
      kal_trace(TRACE_GROUP_SP3G, SP3G_UL_BIT_TRUE_DSP_F8, 
            DspModeLen[sc_mode - 3], ptr16[0], ptr16[1], ptr16[2], ptr16[3], ptr16[4], ptr16[5], ptr16[6], ptr16[7]);
      kal_brief_trace(TRACE_GROUP_SP3G, SP3G_UL_BIT_TRUE_DSP_N8,
            ptr16[8], ptr16[9], ptr16[10], ptr16[11], ptr16[12], ptr16[13], ptr16[14], ptr16[15]);
   }
#endif
   ptr8 = (uint8*)sp3g->ul_buffer[sp3g->ul_write_idx];
   
   bWrite = KAL_FALSE;
   if( sp3g->ul_count < sp3g->ul_buffer_size ){
      bWrite = KAL_TRUE;
   }
   if( sp3g->ul_count == sp3g->ul_buffer_size ){
      if( sp3g->is_getting_ul_data ){
         bWrite = KAL_FALSE;
      }else{
         sp3g->ul_read_idx++;          //drop oldest frame
         sp3g->ul_count--;
         bWrite = KAL_TRUE;
         if( sp3g->ul_read_idx == sp3g->ul_buffer_size )
            sp3g->ul_read_idx = 0;
      }
   }
   if( bWrite ){
      frame_type= DspMode2AmrFrameType[sc_mode-3]; // here 0~7 only , not includes SID and NO_DATA
      switch(tx_type)
      {
         case TX_SPEECH_GOOD:
            if( sp3g->sp3g_mode == RAT_3G_MODE ){
               *ptr8++ = frame_type;
               len = RAB_subflow[frame_type][3];
               *ptr8++ = len;
#ifdef __AMRWB_LINK_SUPPORT__
               if(frame_type >= 0x10) //AMR-WB
                  RAB_To_DSP_Mapping = tblAMR_WBOrder[frame_type-0x10];
               else
#endif
                  RAB_To_DSP_Mapping = tblAMROrder[frame_type];
               
               // do bit reorder , move speech information bits to rab_byte_array
               total_bits = RAB_subflow[frame_type][0] + RAB_subflow[frame_type][1] + RAB_subflow[frame_type][2];
               
               for(I = len; --I >= 0  ; )
                  *ptr8++ = 0;
                           
               idx = 0;
               ptr8 -= len;  
               for(I = 0; I < 3; I ++)
               {
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
            kal_brief_trace(TRACE_GROUP_SP3G, SP3G_TX_SPEECH_GOOD);
#endif
            break;
         case TX_SID_FIRST: 
            if( sp3g->sp3g_mode == RAT_3G_MODE ){
#ifdef __AMRWB_LINK_SUPPORT__
               if( sp3g->ul_report >= 0xB )
                  *ptr8++ = 25;//WB SID
               else
#endif
               *ptr8++ = AMR_SID_FRAME;
               *ptr8++ = 5;
               for(I = 4; --I >= 0; )
                  *ptr8++ = 0;
#ifdef __AMRWB_LINK_SUPPORT__
               if( sp3g->ul_report >= 0xB )
                  *ptr8 = (uint8)(sp3g->ul_report - 0xB);
               else
                  *ptr8 = (uint8)(frame_type << 1);
#else
               *ptr8 = (uint8)(frame_type << 1);
#endif
         #ifdef AMR_DATA_LOG
               ptr8 -= 6;
               kal_brief_trace( TRACE_GROUP_SP3G, SP3G_TX_SID_FIRST );
         #endif 
            }
#ifdef __VIDEO_CALL_SUPPORT__
            else{//3G 324M
               *ptr8++ = 6;//frame length
               for(I = 5; --I >= 0; )
                  *ptr8++ = 0;
               *ptr8 = (uint8)(frame_type);
               ptr8 -= 5;
               *ptr8 |= AMR_SID_FRAME;
            }
#endif
            break;
         case TX_SID_UPDATE:
            if( sp3g->sp3g_mode == RAT_3G_MODE ){
#ifdef __AMRWB_LINK_SUPPORT__
               if( sp3g->ul_report >= 0xB )
                  *ptr8++ = 25;//WB SID
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
               if( sp3g->ul_report >= 0xB )
                  ptr8[4] |= (uint8)(sp3g->ul_report - 0xB)|0x10;
               else
                  ptr8[4] |= (uint8)(frame_type << 1)|0x10;
#else
               ptr8[4] |= (uint8)(frame_type << 1)|0x10;
#endif
         #ifdef AMR_DATA_LOG
               ptr8 -= 2;
               kal_brief_trace( TRACE_GROUP_SP3G, SP3G_TX_SID_UPDATE );
         #endif
            }
#ifdef __VIDEO_CALL_SUPPORT__
            else{//3G 324M
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
         case TX_NO_DATA:
            if( sp3g->sp3g_mode == RAT_3G_MODE ){
               *ptr8++ = AMR_NO_DATA;
               *ptr8++ = 0;
            }
#ifdef __VIDEO_CALL_SUPPORT__
            else{//3G324M
               *ptr8++ = 1;
               *ptr8++ = AMR_NO_DATA;
            }
#endif
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
            kal_brief_trace(TRACE_GROUP_SP3G, SP3G_UL_NO_DATA);
#endif
            break;
         default:
            ASSERT(false);
            break;
      }
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      if (g_bNeedExtraLog == true){
	      kal_brief_trace(TRACE_GROUP_SP3G, SP3G_UL_BIT_TRUE_F8,
	         1, tx_type, ptr8[0], ptr8[1],ptr8[2],ptr8[3],ptr8[4],ptr8[5],ptr8[6],ptr8[7]);
	      kal_brief_trace(TRACE_GROUP_SP3G, SP3G_UL_BIT_TRUE_N13,
	         ptr8[8],ptr8[9],ptr8[10],ptr8[11],ptr8[12],ptr8[13],ptr8[14],ptr8[15], 
	         ptr8[16],ptr8[17],ptr8[18],ptr8[19],ptr8[20]);
      }
#endif
   }
   
   if( sp3g->ul_refresh )
   {
      if ((sp3g->ul_report <= 0xA && sp3g->ul_codec_mode >= 0xB) ||
         (sp3g->ul_report >= 0xB && sp3g->ul_codec_mode <= 0xA)){
         SAC_SphHandoverPar.u4CodModUl = sp3g->ul_codec_mode;
         SAC_SphHandoverPar.u4CodModDl = sp3g->ul_codec_mode;
         SAC_SphHandoverPar.u4RAT      = 0;
         sp3g->dl_report               = SAC_SphHandoverPar.u4CodModDl;
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_HANDOVER, sizeof(SAC_SphHandoverPar_t), (kal_uint32)&SAC_SphHandoverPar );
      } else if(sp3g->ul_report != sp3g->ul_codec_mode ){
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_UPDATE_UL_CODEC_RATE, sp3g->ul_codec_mode, 0 );
      }
      sp3g->ul_refresh = KAL_FALSE;
   }
   //if(sp3g_vm_flag)
   {
      sp3g_ulDebugInfo.u4Len = ( DspMode_AMRLen[sc_mode-3] + 2 );
      memcpy(sp3g_ulDebugBuf, sp3g->ul_buffer[sp3g->ul_write_idx], DspMode_AMRLen[sc_mode-3]);
      sp3g_ulDebugInfo.puc3GL1Ptr = (uint8 *)sp3g_ulDebugBuf;
   }
   if( bWrite ){
      sp3g->ul_write_idx++;
      if( sp3g->ul_write_idx == sp3g->ul_buffer_size )
         sp3g->ul_write_idx = 0;
      sp3g->ul_count++;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      if (g_bNeedExtraLog == true)
         kal_brief_trace(TRACE_GROUP_SP3G, SP3G_UL_BUFFER, sp3g->ul_count,sp3g->ul_read_idx,sp3g->ul_write_idx);
#endif
      if( sp3g->sp3g_mode == RAT_3G_MODE && sp3g->ul_delay > START_SHRINK_UL_DELAY && !sp3g->is_getting_ul_data){
         sp3g->ul_read_idx++;
         if( sp3g->ul_read_idx == sp3g->ul_buffer_size )
            sp3g->ul_read_idx = 0;
         sp3g->ul_count--;
      }//when ul write updated, check ul_delay. keep newest one
   }
   if( sp3g->waiting == KAL_FALSE )
   {
      sp3g->waiting = KAL_TRUE;
      if( sp3g->sp3g_mode == RAT_3G_MODE )
         CSR_SP3G_Callback( SP3G_UL_DATA_NOTIFY, (void*)0 );
   }
   else 
   {
      sp3g->ul_delay ++; 
      if( sp3g->sp3g_mode == RAT_3G_MODE )
         CSR_SP3G_Callback(SP3G_UL_DATA_DEALY_TICK, (void*)(sp3g->ul_delay));
      kal_brief_trace( TRACE_GROUP_SP3G, SP3G_UL_DELAY, sp3g->ul_delay );
#if 0
/* under construction !*/
#endif
   }
   kal_give_enh_mutex( sp3g_mutex );
   L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_3G_REQUEST_READ_UL_DATA_ACK, 0, (uint32)&sp3g_ulDebugInfo);//ACK UL data
}

extern void UL1D_RXBRP_GET_INFO_FOR_SPEECH_VM(kal_int16* tpc_SIR_lta, kal_int16* dpdch_SIR_lta, kal_int16* TFCI_max_corr);

void SP3G_ProcessDL(kal_uint32 msgData16, kal_uint32 msgData32)
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
   uint8 sidData, backup_index;
   bool FQI_flag = false;
   SAS_3GCallRequestWriteDlData_t *payload;
   
   if(L1SP_GetState() == L1SP_STATE_3G_SPEECH_CLOSING) 
      return; 
   ASSERT(sp3g != (SP3G_Struct*) 0);
   //To Do: Sync mechanism: Semiphore?
   payload = (SAS_3GCallRequestWriteDlData_t *)msgData32;
   
   kal_take_enh_mutex( sp3g_mutex );
   
   backup_index = sp3g->dl_read_idx;
   //if( sp3g_vm_flag )
   {
      uint32 *l1_info = NULL;
      uint16 crc_result = 0;
      uint32 l1Info;
      
      if( sp3g->dl_count == 0 ){
         crc_result = (l1AInfo << 8);
      }
      else 
      {
         uint32 CFN = 0;
         if( sp3g->sp3g_mode == RAT_3G324M_MODE ){
            l1_info = NULL;
         }
         else{
            ptr8 = (uint8*) sp3g->dl_buffer[sp3g->dl_read_idx];
            ptr8 += 2;
            CFN = ptr8[0] + (ptr8[1] << 8) + (ptr8[2] << 16) + (ptr8[3] << 24);
            
            for(I = 0 ; I < 4 ; I ++)
               if( CFN == sp3g->L1_Info[I][0] ) 
                  break;
            if( I == 4 ){
               crc_result = (l1AInfo << 8);
               l1_info = NULL;
            }else{
               l1_info = sp3g->L1_Info[I];
               crc_result = (uint16)(l1AInfo << 8) | (uint16)(sp3g->L1_Info[I][2] & 0xF); //[0:7]:CRC, [8:15]:l1AInfo
            }
            /*SID BAD False alarm work around, log in VM first*/
            {
               uint8 * ptrDL;
               ptrDL = (uint8*) sp3g->dl_buffer[sp3g->dl_read_idx];
               if( sp3g->dtx_state == 0 && ptrDL[0] == 8 /*AMR_SID*/ && ptrDL[1] == KAL_FALSE/*CRC fail*/)
                  crc_result |= 0x8000;// The flag indicate working around
               if( ptrDL[0] == AMR_NO_DATA && sp3g->dtx_force == KAL_TRUE )
                  crc_result |= 0x4000;
            }
         }
      }
      
      for( I = 0 ; I < 12 ; I++ ){
         sp3g_dlDebugBuf[I] = 0;
      }
      if( l1_info == NULL ){
         l1Info = 0;
         sp3g_dlDebugBuf[3] = 0;
         sp3g_dlDebugBuf[4] = 0;
         sp3g_dlDebugBuf[5] = 0;
         sp3g_dlDebugBuf[6] = 0;
      }
      else{
         l1Info = l1_info[1];
         sp3g_dlDebugBuf[3] = (uint16)((l1_info[3] >= 32767)? 32767 : l1_info[3]);
         sp3g_dlDebugBuf[4] = l1_info[4];
         sp3g_dlDebugBuf[5] = l1_info[5];
         sp3g_dlDebugBuf[6] = l1_info[6];
      }
      sp3g_dlDebugBuf[0] = (uint16)(l1Info & 0xFFFF);
      sp3g_dlDebugBuf[1] = (uint16)(l1Info >> 16);
      sp3g_dlDebugBuf[2] = crc_result;
#if defined( __MTK_UL1_FDD__ )// only MTK 3G has this function
      if(sp3g->dl_count == 0){
         kal_int16 tpc_SIR_lta, dpdch_SIR_lta, TFCI_max_corr;
         UL1D_RXBRP_GET_INFO_FOR_SPEECH_VM( &tpc_SIR_lta,  &dpdch_SIR_lta, &TFCI_max_corr);
//JY, ask ul1d
         sp3g_dlDebugBuf[4] = tpc_SIR_lta;
         sp3g_dlDebugBuf[5] = dpdch_SIR_lta;
         sp3g_dlDebugBuf[6] = TFCI_max_corr;
      }
#endif
   }
   
   // DL side
   if( sp3g->dl_count == 0 || sp3g_reset_flag != 2 ){ // buffer under flow
      //*DP_3G_DL_RX_TYPE = RX_NO_DATA;
      rx_type = RX_NO_DATA;
      payload->u4RxTyp = rx_type;
      sp3g->dtx_state = 1;
      kal_trace( TRACE_GROUP_SP3G, SP3G_DTX_NO_DATA );
   }
   else
   {
      kal_trace( TRACE_GROUP_SP3G, SP3G_BUFFER_STATUS, sp3g->dl_read_idx, sp3g->dl_write_idx,sp3g->dl_count, sp3g->dl_buffer[sp3g->dl_read_idx][0] );
      
      ptr8 = (uint8*) sp3g->dl_buffer[sp3g->dl_read_idx];
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      ptr8_bak = (uint8*) sp3g->dl_buffer2[sp3g->dl_read_idx];
#endif
      ptr16 = (uint16*) sp3g->dsp_buffer;
      if( sp3g->sp3g_mode == RAT_3G_MODE ){
         frame_type = *ptr8++;        // here 0 ~ 7 and includes SID and NO_DATA
         FQI_flag = (bool)*ptr8++;
         ptr8 += 4; // skip CFN 
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
         ptr8_bak += 6;
#endif
      }
#ifdef __VIDEO_CALL_SUPPORT__
      else{//3G 324M
         FQI_flag = KAL_TRUE;
         frame_type = *ptr8++; // here 0 ~ 7 and includes SID and NO_DATA
         ptr8++;               // skip frame length 
      }
#endif
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      if (g_bNeedExtraLog == true)
         kal_brief_trace(TRACE_GROUP_SP3G, SP3G_DL_BIT_TRUE, frame_type, ptr8[0], ptr8[1],ptr8[2],ptr8[3],ptr8[4]);
#endif
      if( frame_type == AMR_NO_DATA && sp3g->dtx_force == KAL_TRUE ){
         frame_type = 8;
         FQI_flag = KAL_FALSE; // force enter SID_BAD;
         sp3g->dtx_state = 1;
      }
      sp3g->dtx_force = KAL_FALSE;
      if( sp3g->dtx_state == 0 && frame_type == 8 && FQI_flag == KAL_FALSE ){//previous dtx_state is false, but suddenly SID_BAD, regard it as false alarm.
         frame_type = AMR_NO_DATA;
         sp3g->dtx_force = KAL_TRUE;
      }
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
               RAB_To_DSP_Mapping = tblAMR_WBOrder[frame_type-16];
            else
#endif
            RAB_To_DSP_Mapping = tblAMROrder[frame_type];
            if( FQI_flag == KAL_TRUE ){
               rx_type = RX_SPEECH_GOOD;
               kal_brief_trace( TRACE_GROUP_SP3G, SP3G_RX_SPEECH_GOOD );
            }
            else {
               rx_type = RX_SPEECH_BAD;
               kal_brief_trace( TRACE_GROUP_SP3G, SP3G_RX_SPEECH_BAD );
            }
            
            sd_mode = AmrFrameType2DspMode[frame_type];  // RX SD Mode
            
            rx_len = DspModeLen[sd_mode-3];
             // move amr data to dl_buffer 
             
            total_bits = RAB_subflow[frame_type][0] + RAB_subflow[frame_type][1] + RAB_subflow[frame_type][2];
            
            for(I = rx_len; --I >= 0; )
               *ptr16++ = 0;
            
            ptr16 -= rx_len;
            idx = 0;
            if( sp3g->sp3g_mode == RAT_3G_MODE ){
               for(I = 0; I < 3; I ++)
               {
                  if(RAB_subflow[frame_type][I] == 0)
                     break;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
                  if (g_bNeedExtraLog == true){
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
            else{//3G 324M
               I = 4;
               for(J = 0; J < total_bits; J++, I++)
               {
                  K = RAB_To_DSP_Mapping[idx++];
                  bit16Data = (ptr8[I >> 3] & AMR_IF2_Order[J & 7])? DSP_Order[K & 15] : 0; 
                  ptr16[K >> 4] |= bit16Data;
               }  
            }  
#endif
            sp3g->dtx_state = 0;
            break;
      
         case 8: // AMR SID
#ifdef __AMRWB_LINK_SUPPORT__
         case 25:
#endif
            sidData = ptr8[4];
            if( sp3g->sp3g_mode == RAT_3G_MODE ){
               if( FQI_flag == KAL_TRUE )
               {
                  if( sidData & 0x10 )
                     rx_type = RX_SID_UPDATE;
                  else 
                     rx_type = RX_SID_FIRST;
                  sp3g->dtx_state = 1;
               }
               else
                  rx_type = RX_SID_BAD;
#ifdef __AMRWB_LINK_SUPPORT__
               if( frame_type == 25 ){
                  sd_mode = (sidData & 0xF);
               
                  if(sd_mode >= 10)
                  {
                     rx_type = RX_SID_BAD;
                     sd_mode = sp3g->pre_dl_report;
                  } else {
                     sd_mode = AmrFrameType2DspMode[sd_mode+16];  // RX SD Mode 
                  }
               } else
#endif
               {
                  sd_mode = (sidData & 0xE) >> 1;// should reverse
                  sd_mode = (sd_mode >> 2) | ((sd_mode & 0x1) << 2) | (sd_mode & 0x2);
                  sd_mode = AmrFrameType2DspMode[sd_mode];  // RX SD Mode 
               }
            }
#ifdef __VIDEO_CALL_SUPPORT__
            else{//3G 324M
               if( sidData & 0x80 )
                  rx_type = RX_SID_UPDATE;
               else 
                  rx_type = RX_SID_FIRST;
               sd_mode = AmrFrameType2DspMode[(ptr8[5] & 0x7)];       // RX SD Mode 
            }
#endif

            rx_len = 3; // 35 information bits
            // move sid data to dl_buffer
            for(I = 3; --I >= 0; )
               *ptr16++ = 0;
            ptr16 -= 3;
            if( sp3g->sp3g_mode == RAT_3G_MODE ){
               J = 0;
               Order = RAB_Order;
            }
#ifdef __VIDEO_CALL_SUPPORT__
            else{//3G324M
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
            if( rx_type == RX_SID_FIRST )  
               kal_brief_trace( TRACE_GROUP_SP3G, SP3G_RX_SID_FIRST );
            else if( rx_type == RX_SID_UPDATE )  
               kal_brief_trace( TRACE_GROUP_SP3G, SP3G_RX_SID_UPDATE );
         #endif
            break;
            
         case 15: // NO DATA 
            kal_brief_trace( TRACE_GROUP_SP3G, SP3G_RX_NO_DATA );
            rx_type = RX_NO_DATA; 
            rx_len = 0;
            // no need to record codec mode , inherit from previous 
            break; 
         default: 
            ASSERT(false);
            break;
      }
      // get codec_mode , set RX codec_mode 
      // get data from dl_read  
      ptr16 = (uint16*) sp3g->dsp_buffer;
      
      payload->u4RxTyp = rx_type;
      
      ASSERT( payload->u4DlMaxLen >= (rx_len << 1) );
      
      //For NB/WB handover, it's decided by network set UL codec.
      // If downlink happens, set it as NO data.
      if( rx_type != RX_NO_DATA )
      {
         if( (sd_mode <= 0xA && SAC_SphHandoverPar.u4CodModDl >= 0xB) ||
            (sd_mode >= 0xB && SAC_SphHandoverPar.u4CodModDl <= 0xA) )
         {
            payload->u4RxTyp = RX_NO_DATA;
            payload->u4CodModDl = sp3g->dl_report;
            rx_type = RX_NO_DATA;
            kal_brief_trace( TRACE_GROUP_SP3G, SP3G_RX_FORCE_NO_DATA_WHEN_CHANGE_BAND );
         }
      }
      
      if( rx_type != RX_NO_DATA && rx_type != RX_SID_BAD ) //if RX_NO_DATA or RX_SID_BAD, codec mode will use the previous one
      {
         if (sp3g->dl_report != sd_mode )
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_UPDATE_DL_CODEC_RATE, sd_mode, 0);
         payload->u4CodModDl = sd_mode;
         sp3g->dl_report = sd_mode;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
         if (g_bNeedExtraLog == true){
            kal_brief_trace(TRACE_GROUP_SP3G, SP3G_DL_BIT_TRUE_DSP_F8, 
               rx_len, ptr16[0], ptr16[1], ptr16[2], ptr16[3], ptr16[4], ptr16[5], ptr16[6], ptr16[7]);
            kal_brief_trace(TRACE_GROUP_SP3G, SP3G_DL_BIT_TRUE_DSP_N8, 
               ptr16[8], ptr16[9], ptr16[10], ptr16[11], ptr16[12], ptr16[13], ptr16[14], ptr16[15]);
         }
#endif
         
         if( sp3g->dl_report != sp3g->pre_dl_report ){
            L1Audio_Msg_SPEECH_CODEC( L1SP_Speech_Codec_Mode(sp3g->ul_report), L1SP_Speech_Codec_Mode(sp3g->dl_report) );
            sp3g->pre_dl_report = sp3g->dl_report;
         }
      } else {
         payload->u4CodModDl = sp3g->dl_report;
      }
      
      if( rx_type != RX_NO_DATA )
      { //Copy frame to DSP
         uint16 *addr;
         addr = (uint16*) payload->pucDlBufPtr;
         for(I = rx_len ; --I >= 0; )
            *addr++ = *ptr16++;
      }
      
      // update 3G dl_count
      sp3g->dl_count --;
      sp3g->dl_read_idx++;
      
      if( sp3g->dl_read_idx == sp3g->dl_buffer_size ){//near end of buffer
         sp3g->dl_read_idx = 0;
      }
   }
   
   sp3g_dlDebugInfo.u4Len = 12*2 + ( DspMode_AMRLen[sp3g->dl_report-3] + 6 ); //in sizeof bytes, 6 is the extra info
   memcpy((sp3g_dlDebugBuf + 12), sp3g->dl_buffer[backup_index], DspMode_AMRLen[sp3g->dl_report-3]);
   sp3g_dlDebugInfo.puc3GL1Ptr = (uint8 *)sp3g_dlDebugBuf;
   l1AInfo &= ~0xFFFC;
   
   kal_give_enh_mutex( sp3g_mutex );
   L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_3G_REQUEST_WRITE_DL_DATA_ACK, 0, (uint32)&sp3g_dlDebugInfo);//ACK DL data
}

void SP3G_Reset( void )
{
   sp3g_reset_flag = 1;
   sp3g_reset_source = SP3G_RESET_BY_INTERRAT;
}

kal_bool SP3G_IsDTXOn()
{
   return sp3g_dtx_mode;
}

void SP3G_SetDTX(kal_bool on)
{
   sp3g_dtx_mode = on;
   kal_trace( TRACE_GROUP_SP3G, SP3G_SET_DTX, on );
   if( L1SP_GetState() == L1SP_STATE_3G_SPEECH_ON )
   {
      if(on == KAL_TRUE){
         L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_ENABLE_DTX, 0, (kal_uint32)NULL);
      }else{
         L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_DISABLE_DTX, 0, (kal_uint32)NULL);
      }
   }
}

// Force Rx Type to No data frame, used in speech off
void SP3G_SetRxTypeToNoData( void )
{
   //*DP_3G_DL_RX_TYPE = 0x2E; // set RX_NO_DATA(0xE) for AMR and BFI(0x20) for non-AMR
}

void sp3g_reset_internal( void )
{
   // DL side 
   sp3g->dl_count     = 0;
   sp3g->dl_write_idx = 0;
   sp3g->dl_read_idx  = 0;
#if defined(__CSHSPA_SUPPORT__)
   sp3g->dl_buffer_size = sp3g_max_cs_delay;
#endif
   if(sp3g_reset_source == SP3G_RESET_BY_INTERRAT)
      sp3g->dl_report = SAC_SphHandoverPar.u4CodModDl;
   else
      sp3g->dl_report = SAC_Sph3GCallPar.u4CodModDl;
   sp3g_reset_flag    = 0; // clear reset flag, wait it to be 2
}

void sp3g_init( void )
{
   sp3g_rab_id        = 0;
   sp3g_rab_state     = KAL_FALSE;
   l1AInfo       = 0;
   sp3g_vm_flag  = KAL_FALSE;
#if defined(__CSHSPA_SUPPORT__)
   sp3g_max_cs_delay = 2;
#endif
   sp3g_mutex      = kal_create_enh_mutex( "SP3G_ENH_MUTEX" );
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   g_bNeedExtraLog = KAL_FALSE;
#endif
   SAC_SphHandoverPar.u4DelW = 0xA;
   SAC_SphHandoverPar.u4DelR = 0;
   SAC_SphHandoverPar.u4Dtx = 1;
   SAC_SphHandoverPar.u4CodModUl = 0xA;
   SAC_SphHandoverPar.u4CodModDl = 0xA;
}

void SP3G_SendSpeechOn(void)
{
}

void SP3G_SendSpeechOff(void)
{
}

void sp3gMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData)
{
   switch (msgOp) { // L1Audio2SAC is in am.c
      case MSG_SAC2L1AUDIO_SPEECH_3G_CALL_ON_ACK:
	   case MSG_SAC2L1AUDIO_SPEECH_3G_CALL_OFF_ACK:
         L1Audio_FC_SetWait(false);
         break;
      case MSG_SAC2L1AUDIO_SPEECH_3G_REQUEST_WRITE_DL_DATA:
      {//downlink;
         SP3G_ProcessDL( 0, msgData );
         break;
      }
      case MSG_SAC2L1AUDIO_SPEECH_3G_REQUEST_READ_UL_DATA:
      {//uplink
         SP3G_ProcessUL( 0, msgData );
         break;
      }
      default:
         ASSERT(0);
         break;
   }
}
void sp3g_speech_init(uint8 RAT_Mode)
{
   ASSERT( RAT_Mode == RAT_3G_MODE || RAT_3G324M_MODE );
   ASSERT( L1SP_GetState() == L1SP_STATE_IDLE );

   sp3g = (SP3G_Struct*) get_ctrl_buffer(sizeof(SP3G_Struct));

   kal_take_enh_mutex( sp3g_mutex );
   memset( (void *)sp3g, 0, sizeof(SP3G_Struct) );
   sp3g->sp3g_mode = RAT_Mode; 
   // UL side
   sp3g->waiting = KAL_FALSE;
  
   sp3g->ul_write_idx = 0;
   sp3g->ul_read_idx = 0;
   sp3g->ul_count = 0;
   sp3g->is_getting_ul_data = KAL_FALSE;
   sp3g->ul_delay = 0;
   sp3g->pre_ul_report = sp3g->pre_dl_report = sp3g->ul_report = sp3g->dl_report = sp3g_codec_mode;
    
   if( sp3g->sp3g_mode == RAT_3G_MODE )
      sp3g->ul_buffer_size = RAT_3G_UL_BUFFER_NUM;
#ifdef __VIDEO_CALL_SUPPORT__
   else //3G324M
      sp3g->ul_buffer_size = MAX_UL_BUFFER_NUM;
#endif
#if defined(UL_HARD_REAL_TIME_DEMAND)
   sp3g->ul_buffer_size = HARD_REAL_TIME_UL_BUFFER_NUM;
#endif    
   
   if( (RAT_Mode == RAT_3G324M_MODE) && (sp3g_codec_mode > 0xA)){
      //Due to VT call don't support WB, avoid set WBAMR codec mode
      //Then force to be NB AMR 12.2
      sp3g_codec_mode = 0xA;
   }
   
   SAC_Sph3GCallPar.u4CodModUl = sp3g_codec_mode;
   SAC_Sph3GCallPar.u4CodModDl = sp3g_codec_mode;
   SAC_Sph3GCallPar.u4DelR     = 0;
   SAC_Sph3GCallPar.u4DelW     = 0xA;
   SAC_Sph3GCallPar.u4Dtx      = SP3G_IsDTXOn();
    
   SAC_SphHandoverPar.u4CodModUl = sp3g_codec_mode;
   SAC_SphHandoverPar.u4CodModDl = sp3g_codec_mode;
   sp3g->ul_refresh = KAL_FALSE; // detect change codec_mode  
   
   // DL side 
   sp3g->dl_count     = 0;
   sp3g->dl_write_idx = 0;
   sp3g->dl_read_idx  = 0;
   
   if( sp3g->sp3g_mode == RAT_3G_MODE ){
#if defined(__CSHSPA_SUPPORT__)
      sp3g->dl_buffer_size = sp3g_max_cs_delay;
#else
      sp3g->dl_buffer_size = RAT_3G_DL_BUFFER_NUM;
#endif
      sp3g_reset_flag    = 1;
   }
   else{  // 3G324M 
      sp3g->dl_buffer_size = MAX_DL_BUFFER_NUM;
      sp3g_reset_flag    = 2;
   }
   sp3g_reset_source = SP3G_RESET_BY_SPEECH_ON;
 
   sp3g->l1_info_idx = 0;
   sp3g->dtx_state   = 0;
   kal_give_enh_mutex( sp3g_mutex );
}

void sp3g_speech_close( void )
{
   free_ctrl_buffer(sp3g);

   sp3g = (SP3G_Struct*) 0; 
#if defined(__CSHSPA_SUPPORT__)
   sp3g_max_cs_delay = 2;
   //reset to 2 frame
#endif
}

void SP3G_Request(void)
{
   kal_trace( TRACE_GROUP_SP3G, SP3G_REQUEST );
   L1SP_3G_Request();
}

void SP3G_UL_SetFrameType(uint8 amr_frame_type) // function call 
{
   if( L1SP_GetState() != L1SP_STATE_3G_SPEECH_ON && L1SP_GetState() != L1SP_STATE_3G324M_SPEECH_ON )
   {
      return;
   }      
   
   ASSERT(sp3g != (SP3G_Struct*) 0); 
   kal_take_enh_mutex( sp3g_mutex );
   sp3g_codec_mode = AmrFrameType2DspMode[amr_frame_type];
   kal_trace( TRACE_GROUP_SP3G, SP3G_REQUEST_UL_FRAME_TYPE, amr_frame_type);
   sp3g->ul_codec_mode = sp3g_codec_mode;
   sp3g->ul_refresh = KAL_TRUE; 
   kal_give_enh_mutex( sp3g_mutex );
}

// do bit reorder here 
void SP3G_UL_GetSpeechFrame(kal_uint16*frame_index, kal_uint8 *frame_type, kal_uint8 *rab_byte_array, kal_uint8 *len)
{   
   uint8 *ptr8;
   int32 I; 
   uint16 sc_mode = 0;
               
   if( L1SP_GetState() != L1SP_STATE_3G_SPEECH_ON)
   {
      *frame_index = 0xABCD;      
      *frame_type = AMR_NO_DATA;
      *len = 0; 
      return;         
   }
   
   ASSERT(sp3g != (SP3G_Struct*) 0);
   
   kal_trace( TRACE_GROUP_SP3G, SP3G_UL_START_GET_SPEECH_FRAME );
   
   if(!sp3g->waiting || sp3g->ul_count == 0)// or should repeat last frame
   {
      *len = 0;
      return;
   }   
   kal_take_enh_mutex( sp3g_mutex );
   *frame_index = 0xABCD; // tmp setting , should be apply true value in near future , Adam 
        
   sp3g->is_getting_ul_data = KAL_TRUE;
           
   ptr8 = (uint8*)sp3g->ul_buffer[sp3g->ul_read_idx];
    
   *frame_type = *ptr8;
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   if (g_bNeedExtraLog == true){
      kal_trace(TRACE_GROUP_SP3G, SP3G_UL_BIT_TRUE_F8,
         0, *frame_type, ptr8[0], ptr8[1],ptr8[2],ptr8[3],ptr8[4],ptr8[5],ptr8[6],ptr8[7]);
      kal_trace(TRACE_GROUP_SP3G, SP3G_UL_BIT_TRUE_N13,
         ptr8[8],ptr8[9],ptr8[10],ptr8[11],ptr8[12],ptr8[13],ptr8[14],ptr8[15],
         ptr8[16],ptr8[17],ptr8[18],ptr8[19],ptr8[20]);
   }
#endif

   if(*frame_type < AMR_SID_FRAME)
      sc_mode = AmrFrameType2DspMode[*frame_type];
#ifdef __AMRWB_LINK_SUPPORT__
   else if(*frame_type >= 16 && *frame_type <= 24){
      sc_mode = AmrFrameType2DspMode[*frame_type];
      *ptr8 -= 16;//in subflow data, remap to 0~8
   }else if( *frame_type == 25 ){ //WB AMR SID
      *ptr8 = AWB_SID_FRAME; //in subflow data, remap to 9
   }
#endif
   ptr8++;
   if( (*frame_type != AMR_SID_FRAME && *frame_type != 25) &&
      ((sc_mode > sp3g->ul_codec_mode)||
      (sc_mode <= 0xA && sp3g->ul_codec_mode >= 0xB) ||
      (sc_mode >= 0xB && sp3g->ul_codec_mode <= 0xA)) ) // maximum bit_rate limitation or change ban
   {      
      *frame_type = AMR_NO_DATA;
      *len = 0; 
   }    
   else 
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
   sp3g->waiting = KAL_FALSE;
   sp3g->ul_delay = 0;
   sp3g->ul_count--;
   sp3g->ul_read_idx++;
   if( sp3g->ul_read_idx == sp3g->ul_buffer_size )
      sp3g->ul_read_idx = 0;
   sp3g->is_getting_ul_data = KAL_FALSE;
   kal_give_enh_mutex( sp3g_mutex );
   kal_trace( TRACE_GROUP_SP3G, SP3G_UL_GET_SPEECH_FRAME, *frame_type, *len, rab_byte_array[0], rab_byte_array[1]);
}
#ifdef __AMRWB_LINK_SUPPORT__
const uint8 last_sub_flow_id[26] = { 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
#else
const uint8 last_sub_flow_id[16] = { 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0};
#endif

// do bit reorder here 
void SP3G_DL_PutSpeechFrame(uint32 CFN, uint8 sub_flow_id, uint8 frame_type, bool crc_status, uint8 *subflow)
{
   kal_uint32 savedMask;
   int32 I;
   uint8 *ptr8; 
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   uint8 *ptr8_bak;
#endif
   uint16 rabBitsCount;
   uint8  state;
            
   if( (state = L1SP_GetState()) != L1SP_STATE_3G_SPEECH_ON)
   {
      if(state == L1SP_STATE_3G_SPEECH_CLOSING)
         return;
      else 
         //ASSERT(false);       
         return;
   }
   
   ASSERT(sp3g != (SP3G_Struct*) 0);
   
   kal_trace( TRACE_GROUP_SP3G, SP3G_DL_PUT_SPEECH_FRAME, sub_flow_id, frame_type, crc_status );
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   if( sub_flow_id == 0 )
      kal_brief_trace(TRACE_GROUP_SP3G, SP3G_DL_BIT_TRUE_TASK, CFN, subflow[0], subflow[1],subflow[2],subflow[3],subflow[4]);
#endif

#ifdef __AMRWB_LINK_SUPPORT__
   ASSERT( frame_type <= 25 );
#else
   ASSERT( (frame_type <= 8 || frame_type ==15) );
#endif
   savedMask = SaveAndSetIRQMask();
   if( sp3g_reset_flag == 1 ){
      sp3g_reset_internal();
   }
   RestoreIRQMask(savedMask);
   
   if( sub_flow_id > last_sub_flow_id[frame_type] ) 
      return;
   kal_take_enh_mutex( sp3g_mutex );
   if( sp3g->dl_count == sp3g->dl_buffer_size ) 
   {      
      sp3g->dl_read_idx++;
      if( sp3g->dl_read_idx == sp3g->dl_buffer_size )
         sp3g->dl_read_idx = 0;
      sp3g->dl_count --;
   }//keep only 2 frame
   
   ptr8 = sp3g->dl_buffer[sp3g->dl_write_idx];
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
   ptr8_bak = sp3g->dl_buffer2[sp3g->dl_write_idx];
#endif
   if( sub_flow_id == 0 )
   {
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
      //kal_prompt_trace(MOD_L1SP,"SP3G DL r=%d,w=%d,n=%d",sp3g->dl_read,sp3g->dl_write,sp3g->dl_count);      
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
   if( sub_flow_id == last_sub_flow_id[frame_type] ) 
   {
      sp3g->dl_write_idx++;
      if( sp3g->dl_write_idx == sp3g->dl_buffer_size )
         sp3g->dl_write_idx = 0;
      sp3g->dl_count ++;
      if( sp3g->dl_count == sp3g->dl_buffer_size && sp3g_reset_flag == 0 ){
         sp3g_reset_flag = 2;// reset done
         kal_trace( TRACE_GROUP_SP3G, SP3G_DL_BUFFER_FINISH );
      }
   }
   kal_give_enh_mutex( sp3g_mutex );
}

void SP3G_Start_VM( void ) 
{
   sp3g_vm_flag = KAL_TRUE;
}

void SP3G_Stop_VM( void ) 
{
   sp3g_vm_flag = KAL_FALSE;
}

bool SP3G_VM_Status( void )
{
   return sp3g_vm_flag;
}

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

void SP3G_Log_L1_Info(uint32 CFN, L1_info_struct *p_L1_Info)
{
   uint32 *l1_info; 
   uint32 l1_data, crc_result;
   
   if(sp3g == (SP3G_Struct*) 0)
      return;
   
   l1_info = sp3g->L1_Info[sp3g->l1_info_idx++];
   sp3g->l1_info_idx &= 0x3; 
   
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
   kal_trace( TRACE_GROUP_SP3G, SP3G_LOG_L1_INFO,
      l1_info[0], l1_info[1], crc_result, p_L1_Info->s_value[0], p_L1_Info->s_value[1],p_L1_Info->s_value[2]);
}

void SP3G_Closed_Confirm( void )
{
}

/*====================== CS over HSPA interface ============================*/
#if defined(__CSHSPA_SUPPORT__)
void SP3GHSPA_UL_GetSpeechFrame(kal_uint8 *frame_type, kal_uint8 *rab_byte_array, kal_uint8 *len)
{
   kal_uint16 frame_index, I, J, K, rabBitsCount;
   kal_uint8  *ptr8, *ptr8_swap, byte_swap, bit8Data;
   
   SP3G_UL_GetSpeechFrame(&frame_index, frame_type, rab_byte_array, len);
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
   kal_trace( TRACE_GROUP_SP3G, SP3G_HSPA_UL_GET_SPEECH_FRAME, *frame_type, *len, rab_byte_array[0], rab_byte_array[1] );
}

void SP3GHSPA_DL_PutSpeechFrame(kal_uint32 CFN, kal_uint8 frame_type, kal_bool crc_status, kal_uint8 *subflow)
{
   kal_trace( TRACE_GROUP_SP3G, SP3G_HSPA_DL_PUT_SPEECH_FRAME, frame_type, CFN, crc_status, subflow[0],subflow[1]);
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
         ptr8 = &sp3g->dl_subflow[0];
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
         SP3G_DL_PutSpeechFrame(CFN, I, frame_type, crc_status, sp3g->dl_subflow);
      }
   } else {
      SP3G_DL_PutSpeechFrame(CFN, 0, frame_type, crc_status, subflow);
   }
}

void SP3GHSPA_DL_SetMaxCsDelay(kal_uint8 max_cs_delay)
{
   kal_trace( TRACE_GROUP_SP3G, SP3G_HSPA_DL_MAX_CS_DELAY, max_cs_delay);
   
   sp3g_max_cs_delay = (max_cs_delay + 19) / 20;
   ASSERT(sp3g_max_cs_delay <= 10);
   if( sp3g_max_cs_delay < 2 )
      sp3g_max_cs_delay = 2;
#if 1
   if(L1SP_GetState() == L1SP_STATE_3G_SPEECH_CLOSING || sp3g == NULL ) 
      return;

   kal_take_enh_mutex( sp3g_mutex );
   //Already in speech, allow extend buffer size
   if(sp3g->dl_buffer_size < sp3g_max_cs_delay){
      sp3g->dl_buffer_size = sp3g_max_cs_delay;
   }   
   kal_give_enh_mutex( sp3g_mutex );
#endif
}

#endif // if defined(__CSHSPA_SUPPORT__)
/*====================== 3G 324M interface==================================*/
#ifdef __VIDEO_CALL_SUPPORT__
void SP3GVT_UL_GetSpeechFrame(kal_uint8 *ul_data, kal_uint32 ul_space, kal_uint32 *size)
{   
   uint8 *ptr8, read_idx, count;
   uint32 totalLen = 0;
   int32 I, len;
   
   kal_trace( TRACE_GROUP_SP3G, SP3GVT_UL_GET_SPEECH_FRAME, sp3g->ul_count );
   kal_take_enh_mutex( sp3g_mutex );
   
   if( L1SP_GetState() != L1SP_STATE_3G324M_SPEECH_ON)
   {
      *size = 0;
      if( sp3g != (SP3G_Struct*) 0 )
         sp3g->waiting = KAL_FALSE;
      goto END_UL_PROCESS;
   }
   
   ASSERT(sp3g != (SP3G_Struct*) 0);
        
   sp3g->is_getting_ul_data = KAL_TRUE;

   if( !sp3g->waiting || sp3g->ul_count == 0 )
   {
      *size = 0;
      goto END_UL_PROCESS;
   }
   read_idx = sp3g->ul_read_idx;
   count = sp3g->ul_count;
   while( count > 0 ){
      ptr8 = (uint8*)sp3g->ul_buffer[read_idx];
      //frame_type = *ptr8++;
      len = (int32)*ptr8++;//frame len
      ASSERT( len <= 31 );
      totalLen += ( len + 1 ) ;
      ASSERT( totalLen <= ul_space );
      *ul_data++ = (uint8)len;
      kal_brief_trace( TRACE_GROUP_SP3G, SP3GVT_UL_FRAME_INFO, len, ptr8[0], ptr8[1], ptr8[2] );
      for( I = 0 ; I < len ; I++ )
      {
         *ul_data++ = *ptr8++;
      }
      count--;
      read_idx++;
      if( read_idx >= sp3g->ul_buffer_size )
         read_idx = 0;
   }
   *size = totalLen;

   sp3g->waiting = KAL_FALSE;
   sp3g->ul_count = 0;
   sp3g->ul_read_idx = read_idx;
   sp3g->ul_delay = 0;   
   sp3g->is_getting_ul_data = KAL_FALSE;
END_UL_PROCESS:
   
   kal_give_enh_mutex( sp3g_mutex );
}

uint8 SP3GVT_DL_PutSpeechFrame(uint8 *dl_data, uint32 size, kal_bool error_flag, uint8 *dl_frame_number)
{
   int32 dl_size;
   uint8 *ptr8, frame_type, *inputPtr, frame_len, dl_count;
   uint32 I, noDataCount = 0;

   if(L1SP_GetState() != L1SP_STATE_3G324M_SPEECH_ON)
   {
      return 0;
   }
   
   ASSERT(sp3g != (SP3G_Struct*) 0);
   *dl_frame_number = sp3g->dl_buffer_size;
   
   kal_trace( TRACE_GROUP_SP3G, SP3GVT_DL_FRAME_INFO, size,dl_data[0],dl_data[1],dl_data[2] );

   kal_take_enh_mutex( sp3g_mutex );
   if( error_flag ) 
   {            
      ASSERT( sp3g->dl_count < sp3g->dl_buffer_size );
      ptr8 = sp3g->dl_buffer[sp3g->dl_write_idx];
      *ptr8++ = AMR_NO_DATA;                        //frame type
      *ptr8++ = SP3G324M_DL_EXTRA_LEN; //the length with AMR frame and other info
      I = L1I_GetTimeStamp();
      *ptr8++ = (uint8)(I & 0xFF);                 //log frame time
      *ptr8++ = (uint8)(( I >> 8 ) & 0xFF);
      *ptr8++ = (uint8)(( I >> 16 ) & 0xFF);
      sp3g->dl_write_idx++;
      if( sp3g->dl_write_idx == sp3g->dl_buffer_size )
         sp3g->dl_write_idx = 0;
      sp3g->dl_count++;
      goto END_DL_PROCESS;
   }
   
   dl_size = (int32)size;
   inputPtr = dl_data;
   while( dl_size > 0 ){      
      frame_type = (*inputPtr & 0xF);
#if defined( _IGNORE_TYPE_ERROR_ )
      if (!( frame_type <= 8 || frame_type == 15 )){
         kal_brief_trace( TRACE_GROUP_SP3G, SP3GVT_DL_FRAME_ERROR );
         goto END_DL_PROCESS;
      }
#else
      ASSERT( frame_type <= 8 || frame_type == 15 );
#endif
      frame_len = AMR_IF2_FRAME_LENGTH[frame_type];//only type 0~7 and SID
            
      ASSERT( sp3g->dl_count < sp3g->dl_buffer_size );
      
      ptr8 = sp3g->dl_buffer[sp3g->dl_write_idx];
      *ptr8++ = frame_type;                        //frame type
      *ptr8++ = frame_len + SP3G324M_DL_EXTRA_LEN; //the length with AMR frame and other info
      for( I = 0 ; I < frame_len ; I++ )
         *ptr8++ = *inputPtr++;
      dl_size -= frame_len;
      
      // avoid consecutive AMR_NO_DATA(0xFF) which pass CRC check to make 3G buffer overflow
      if( frame_type == 15 ){
         noDataCount++;
         if( noDataCount > 1 ){
            kal_brief_trace(TRACE_GROUP_SP3G, SP3GVT_FAKE_NODATA);
            continue;
         }
      }else
         noDataCount = 0;

      I = L1I_GetTimeStamp();
      *ptr8++ = (uint8)( I & 0xFF );                 //log frame time
      *ptr8++ = (uint8)(( I >> 8 ) & 0xFF );
      *ptr8++ = (uint8)(( I >> 16 ) & 0xFF );
      
      sp3g->dl_write_idx++;
      if( sp3g->dl_write_idx == sp3g->dl_buffer_size )
         sp3g->dl_write_idx = 0;
      sp3g->dl_count++;  
   }  
   
   ASSERT( dl_size == 0 );
   
END_DL_PROCESS:
   dl_count = sp3g->dl_count;
   
   kal_give_enh_mutex( sp3g_mutex );
   
   return dl_count;
}

//Drop oldest sppech frame
uint8 SP3GVT_DL_DropSpeechFrame(uint32 number, uint8 *dl_frame_number)
{
   if( L1SP_GetState() != L1SP_STATE_3G324M_SPEECH_ON)
      return 0;
   
   ASSERT(sp3g != (SP3G_Struct*) 0);
   kal_take_enh_mutex( sp3g_mutex );
   while( number > 0 && sp3g->dl_count > 0 ){
      sp3g->dl_count--;
      number--;
      sp3g->dl_read_idx++;
      if( sp3g->dl_read_idx == sp3g->dl_buffer_size )
         sp3g->dl_read_idx = 0;
   }
   *dl_frame_number = sp3g->dl_buffer_size;
   kal_give_enh_mutex( sp3g_mutex );
   return sp3g->dl_count;
}

/* delay : unit is ms */
void SP3GVT_SetDelayValue(uint32 delay)
{
   uint32 delay_frame;
   uint8 state;
   uint8 tmp;
      
   if( (state = L1SP_GetState()) != L1SP_STATE_3G324M_SPEECH_ON)
   {
      if(state == L1SP_STATE_3G_SPEECH_CLOSING)      
         return;                  
      else 
         ASSERT(false);       
   }
   
   ASSERT(sp3g != (SP3G_Struct*) 0);   
            
   /*count delay to the most adjacent (delay) frame number */
   delay_frame = ( delay + 10 ) / 20; //remainder 0~9 ¤£¶i¦ì
   kal_trace( TRACE_GROUP_SP3G, SP3GVT_SET_DELAY , delay, delay_frame);
   
   while( delay_frame > 0 )
   {
      SP3GVT_DL_PutSpeechFrame(NULL, 0, KAL_TRUE, &tmp);
      delay_frame--;
   }
   
}
#endif // __VIDEO_CALL_SUPPORT__
#endif // __UMTS_RAT__ 

