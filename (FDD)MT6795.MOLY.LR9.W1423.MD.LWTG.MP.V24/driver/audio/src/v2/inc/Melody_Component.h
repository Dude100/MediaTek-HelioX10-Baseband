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
 * Melody_Component.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Melody Component Definitions
 *
 * Author:
 * -------
 * -------
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef MELODY_COMPONENT_H
#define MELODY_COMPONENT_H

#include "l1audio_def.h"
#include "AudComUtil.h"
#include "melody_par_exp.h"
#include "melody_syn_exp.h"

#define MULTIPLE_PASER_SINGLE_WTSYNTH
#define MELODY_SAMPLERATE   SR_32K
#define MELODY_PERIOD          18
#define DEFAULT_TONE_INST      74
#define MELODY_PCM_SIZE      2304
#define MELDOY_RTEVT_COUNT    256
#define MELODY_PARSE_BUFSIZE      1032
#define MELODY_PARSE_BUFNUM          2
#define PIANO_PARSE_BUFNUM           1
#define MELODY_SYNTH_BUFSIZE      2304
#define MELODY_SYNTH_BUFNUM          1
#define PIANO_SYNTH_BUFNUM           1
#define MELODY_PLAYER_BUFSIZE     1032

/***********************************************************************************
** MIDI Message
************************************************************************************/
#define MELDOY_RTMSG_NONE              0x00
#define MELODY_RTMSG_NOTEON            0x01
#define MELODY_RTMSG_NOTEOFF           0x02
#define MELODY_RTMSG_KEY_PRESSURE      0x03
#define MELODY_RTMSG_VOLUME            0x04
#define MELODY_RTMSG_PAN               0x05
#define MELODY_RTMSG_SUSTAIN           0x06
#define MELODY_RTMSG_EXPRESSION        0x07
#define MELODY_RTMSG_PITCH_WHEEL       0x08
#define MELODY_RTMSG_PITCH_SENS        0x09
#define MELODY_RTMSG_PROGRAM           0x0A
#define MELODY_RTMSG_CHANNEL_PRESSURE  0x0B
#define MELODY_RTMSG_TONE_BANK_HI      0x0C
#define MELODY_RTMSG_ALL_NOTES_OFF     0x0D
#define MELODY_RTMSG_ALL_SOUNDS_OFF    0x0E
#define MELODY_RTMSG_RESET_CONTROLLERS 0x0F
#define MELODY_RTMSG_MODULATION_WHEEL  0x10
#define MELODY_RTMSG_TONE_BANK_LO      0x11
#define MELODY_RTMSG_FREQ_ON           0x12
#define MELODY_RTMSG_FREQ_OFF          0x13
#define MELODY_RTMSG_TEMPO             0x14
#define MELODY_RTMSG_END               0x15
/***********************************************************************************
** PCM Message Definition
************************************************************************************/
#define MELODY_RTMSG_SET_PER           0x16
#define MELODY_RTMSG_RELEASE_PER       0x17
#define MELODY_RTMSG_CALLBACK_EVT      0x18
/***********************************************************************************
** Callback Message Definition
************************************************************************************/
#define MELODY_RTMSG_VIBRATOR_ON       0x80
#define MELODY_RTMSG_VIBRATOR_OFF      0x81
#define MELODY_RTMSG_LED_ON            0x82
#define MELODY_RTMSG_LED_OFF           0x83
#define MELODY_RTMSG_BACKLIGHT_ON      0x84
#define MELODY_RTMSG_BACKLIGHT_OFF     0x85

#define WT_NO_IMYEFFECTS
#define MELODY_NOSOUND_WRKRND
#define MELODY_SILENCE_END             20
#define MAX_DEVMSG_NUM                 30
/*#if !defined(MELODY_POP_WRKRND)
#define MELODY_POP_WRKRND
#endif*/
/*#if defined(MELODY_POP_WRKRND)
#define   MELODY_SILENCECNT            4
#endif*/
typedef enum{
   MELODY_REPEAT = 0x00,
   MELODY_END,
   MELODY_SYNTHDONE,
   MELODY_RELEASE,
   MELODY_RELEASEDONE,
   MELODY_MSG_DONE = 0x10,
   MELODY_VIBRATOR_ON = 0x80,
   MELODY_VIBRATOR_OFF,
   MELODY_LED_ON,
   MELODY_LED_OFF,
   MELODY_BACKLIGHT_ON,
   MELODY_BACKLIGHT_OFF,
}MELODY_EVENT_CALLBACK;

typedef struct{
   kal_uint32   samplerate;
   kal_uint32   maxtone;
   kal_uint32   finetone;
   kal_uint32   period;
   kal_uint32   tonegain;
   kal_uint32   isEOF;
   kal_uint32   reset;
   void         *mel_hdl;
   void         *working;
   kal_uint8    *wavtab;
   void         *evthdl;
   void         (*evtcall)(void *hdl,int evt);
} MEL_SynData;

typedef struct{
   MEL_SynData  meldata;   
   kal_uint32   channel;
   kal_uint32   data;
}MelodySynthParam;
#if defined(SINGLE_PASER_SINGLE_WTSYNTH)

   typedef struct{
      kal_uint32       filelen;
      kal_uint32       maxtone;
      kal_uint32       repeats;
      kal_uint32       period;
      kal_uint32       start_time;
      kal_uint32       stop_time;
      kal_uint32       releasedone;
      kal_uint32       duration;
      kal_uint32       delta_ms;
      kal_uint32       current_time;
      kal_uint32       current_time_int;
      kal_uint32       playrate;
      kal_uint32       tsrate;
      MELPAR_INPUTMODE mode;
      void             *mel_hdl;
      kal_int8         *evtbuf;
      const kal_uint8  *midifile;
      void             *working;
      void             *datahdl;
      void             (*getdata)(void *hdl, int evt, unsigned char* ptr, unsigned int len);
      void             *evthdl;
      void              (*evtcall)(void *hdl,int evt);
   #if defined(MELODY_POP_WRKRND)
      kal_uint32       silencecnt;
   #endif
   #if defined(MELODY_NOSOUND_WRKRND)
      kal_uint32       silenceend;
   #endif
   } MEL_ParData;
   
   typedef struct{
      const kal_uint8  *rtmidi_ptr;
      kal_uint16       rtmidi_count;
      kal_uint8        rtmidi_running;
      kal_uint8        rtmidi_status;
      kal_bool         rtmidi_wait;
      kal_bool         nrpn;
      kal_int8         rpn_msb[16];
      kal_int8         rpn_lsb[16];
      void             *evthdl;
      void             (*evtcall)(void *hdl,int evt);
   } MEL_DevData;

   typedef struct{
      MEL_ParData  meldata;
      kal_uint32   channel;
      kal_uint32   data;   
   }MelodyParseParam;
   
   typedef struct{
      MEL_DevData  meldata;
      kal_uint32   channel;
      kal_uint32   data;   
   }MelodyDevParam;

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Multiple Parser Framework
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#elif defined(MULTIPLE_PASER_SINGLE_WTSYNTH)

   #define MELODY_MAXPLAYERS          9
   #define MELODY_MAX_SYNTHCHANNEL   16
   #define MELODY_MAX_RTEVT          32
   
   typedef enum{
      MELPAR_DATA_FREE,
      MELPAR_DATA_IDLE,
      MELPAR_DATA_START,
      MELPAR_DATA_RUN,
      MELPAR_DATA_STOP,
      MELPAR_DATA_EOF,
      MELPAR_DATA_RELEASE
   }MEL_ParData_State;
   
   typedef struct{
      kal_uint32         filelen;
      kal_uint32         maxtone;
      kal_uint32         repeats;
      kal_uint32         start_time;
      kal_uint32         stop_time;
      kal_uint32         duration;
      kal_uint32         delta_ms;
      kal_uint32         current_time;
      kal_uint32         current_time_int;
      kal_uint32         playrate;
      kal_uint32         tsrate;
      kal_bool           stopflag;
      MIDI_Format        format;
      MELPAR_INPUTMODE   mode;
      void               *mel_hdl;
      void               *wrkbuf;
      void               *parent;
      MEL_ParData_State  status;
      const kal_uint8    *midifile;
      void               *evthdl;
      void               (*evtcall)(void *hdl,int evt);
      void               *channel_hdl;
      void               (*getchannel)(void *hdl, unsigned char* chid, unsigned char per);
      void               *datahdl;
      void               (*getdata)(void *hdl, int evt, unsigned char* ptr, unsigned int len);
   #if defined(MELODY_POP_WRKRND)
      kal_uint32        silencecnt;
   #endif
   }MEL_ParDataInt;
   
   typedef struct{
      void        *hdl;
      kal_bool    used;
      kal_bool    per;
   } MEL_SynthChannel;
   
   typedef struct {
      kal_uint32 read;
      kal_uint32 write;
      kal_int8   evtbuf[MELODY_MAX_RTEVT];
   }MEL_ParRtEvent;
   
   typedef struct{
      const kal_uint8    *rtmidi_buf;
      const kal_uint8    *rtmidi_ptr;
      kal_uint16         rtmidi_count;
      kal_uint8          rtmidi_running;
      kal_uint8          rtmidi_status;
      kal_bool           rtmidi_wait;
   }MEL_ParDevMsgQueue;
   typedef struct{
      kal_uint32         period;
      kal_uint32         releasedone;
      kal_uint32         totallen;
      kal_uint16         runstate;
      kal_int8           *parseroutput;
      kal_int8           *playeroutput;
   // MIDI Device Releated Data
      MEL_ParDevMsgQueue devqueue[MAX_DEVMSG_NUM];
      kal_bool           nrpn;
      kal_uint8          devchannel[16];
      kal_int8           rpn_msb[16];
      kal_int8           rpn_lsb[16];
      kal_uint8          rtmidi_vol;
   // End of MIDI Device Related Data
   #if defined(MELODY_NOSOUND_WRKRND)
      kal_uint32        silenceend;
   #endif
      MEL_ParDataInt    ParDataList[MELODY_MAXPLAYERS];
      MEL_SynthChannel  synthchannel[MELODY_MAX_SYNTHCHANNEL];
      MEL_ParRtEvent    rtEvent;
   } MEL_ParData;
   
   typedef struct{
      kal_uint32         filelen;
      kal_uint32         maxtone;
      kal_uint32         repeats;
      kal_uint32         start_time;
      kal_uint32         stop_time;
      kal_uint32         duration;
      kal_uint32         delta_ms;
      kal_uint32         current_time;
      kal_uint32         current_time_int;
      kal_uint32         playrate;
      kal_uint32         tsrate;
      MELPAR_INPUTMODE   mode;
      void               *mel_hdl;
      void               *wrkbuf;
      void               *parent;
      MEL_ParData_State  status;
      const kal_uint8    *midifile;
   #if defined(MELODY_POP_WRKRND)
      kal_uint32         silencecnt;
   #endif
      kal_uint32        period;
   // MIDI Device Releated Data
      kal_uint32        releasedone;
      kal_uint32        totallen;
      const kal_uint8   *rtmidi_ptr;
      kal_uint16        rtmidi_count;
      kal_uint8         rtmidi_running;
      kal_uint8         rtmidi_status;
      kal_bool          rtmidi_wait;
      kal_bool          nrpn;
      kal_int8          rpn_msb[16];
      kal_int8          rpn_lsb[16];
   // End of MIDI Device Related Data
      void              *datahdl;
      void              (*getdata)(void *hdl, int evt, unsigned char* ptr, unsigned int len);
      void              *evthdl;
      void              (*evtcall)(void *hdl,int evt);
      void              *channel_hdl;
      void              (*getchannel)(void *hdl, unsigned char* chid, unsigned char per);
   #if defined(MELODY_NOSOUND_WRKRND)
      kal_uint32        silenceend;
   #endif
   }MEL_ParDataParam;
   
   typedef struct{
      MEL_ParDataParam  meldata;
      kal_uint32        channel;
      kal_uint32        data;
      kal_uint32        state_bit;
      void              *wrkbuf;
   }MelodyParseParam;

#else
#error the framework should either be SINGLE_PASER_SINGLE_WTSYNTH or MULTIPLE_PASER_SINGLE_WTSYNTH
#endif /* SINGLE_PASER_SINGLE_WTSYNTH, MULTIPLE_PASER_SINGLE_WTSYNTH */


#endif  /* MELODY_COMPONENT_H */
