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
 * pcm4way.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   PCM4WAY/PCM2WAY interface 
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
#ifndef __PCM4WAY_H
#define __PCM4WAY_H
#include "common_def.h"


// #define PNW_ENBLE               (1<<8)
#define DATA_SELECT_AFTER_ENH   (1<<9)  
#define USE_D2M_PATH            (1<<10)
#define USE_M2D_PATH            (1<<11)

// #define PNW_DSP_IDLE            (0)
// #define PNW_DSP_ON              (1)
// #define PNW_DSP_READY           (2)

// #define PCM4WAY_STATE 0x1
// #define PCM2WAY_STATE 0x2

typedef enum{
	PNW_STATE_IDLE = 0,
	PNW_STATE_RUN,
	
}PCMEX_STATE;

typedef enum {
  PCMEX_BAND_UNSET = 0,
  PCMEX_BAND_NB,
  PCMEX_BAND_WB,
  PCMEX_BAND_DYNAMIC, // follow codec, only for delication mode 
}PCMEX_BAND;

typedef enum {
  PCMEX_IDLE_ENH_SETTING_NONE = 0,
  PCMEX_IDLE_ENH_SETTING_WITH,
  PCMEX_IDLE_ENH_SETTING_WITHOUT,
  PCMEX_IDLE_ENH_SETTING_DMNR_REC_ONLY_CAL,
  PCMEX_IDLE_ENH_SETTING_DMNR_CAL
}PCMEX_IDLE_ENH_SETTING;


typedef struct{
   uint16      aud_id; // to lock sleep mode
  	bool        isEnhOn;
   PCMEX_STATE state;   // on/off 
   kal_uint32  am_type;
   // kal_uint32  app_type;
   
   PCMEX_BAND  bandInfo;  //to record the band information, 
   
   kal_uint32  cfgUL1;
	kal_uint32  cfgUL2;
	kal_uint32  cfgUL3;
	kal_uint32  cfgUL4;
   kal_uint32  cfgDL;
   
   // kal_int16   dspPcmExMicLen; // unit is 16-bit (sampel), -1 means useless
   // kal_int16   dspPcmExSpkLen; // unit is 16-bit (sampel), 0xFFFFFFFF means useless

   void        (*pnw_dl_hdlr)(void);
   void        (*pnw_ul_hdlr)(void);      
}_PCMEX_T;


typedef enum{
	PNW_APP_TYPE_IDLE = 0,
	PNW_APP_TYPE_UNDER_CALL,
}PCMEX_APP_TYPE;


typedef enum{
   MCU_SET_P4W_OFF   = 0,  
   MCU_SET_P4W_ON    = 1,  
   DSP_SET_P4W_READY = 2
}P4W_CTRL_STATUS;

typedef enum{
   MCU_SET_P2W_OFF   = 0<<4,  
   MCU_SET_P2W_ON    = 1<<4,  
   DSP_SET_P2W_READY = 2<<4
}P2W_CTRL_STATUS;


typedef enum {
	P4W_APP_CTM = 0,
	P4W_APP_TYPE_UNDER_CALL, //p2w acts as I/O to get/put pcm data under idle
	P4W_APP_TYPE_WITHOUT_CALL,
   P4W_APP_TYPE_WITHOUT_CALL_WB,
   
	P4W_APP_TYPE_UNDEFINE = 0xFFFF
}P4W_APP_TYPE;

typedef enum {
  P2W_APP_TYPE_UNDER_CALL = 0, //p2w acts as I/O to get/put pcm data under phone call
  P2W_APP_TYPE_WITHOUT_CALL,   //p2w acts as I/O to get/put pcm data when idle
  P2W_APP_TYPE_VOIP,           //VOIP, speech quality like phone call but not under calling
  // P2W_APP_TYPE_REC_ONLY_CAL,   //dmnr calibration, record only
  // P2W_APP_TYPE_REC_PLAY_CAL    //dmnr calibration, record and playback at the same time
  P2W_APP_TYPE_UNDEFINE = 0xFFFF
}P2W_App_Type;


void PCM4WAY_Start(void (*pcm4way_hdlr)(void), uint32 type);   
void PCM4WAY_Stop(uint32 type);           
// void Extended_PCM4WAY_Start(void (*pcm4way_dl_hdlr)(void), void (*pcm4way_ul_hdlr)(void), uint32 type, uint32 cfgUL, uint32 cfgDL);
// void Extended_PCM4WAY_Stop(uint32 type);

uint16 PCM4WAY_GetFromMic(uint16 *ul_buf);
uint16 PCM4WAY_PutToSE(const uint16 *ul_data); 
uint16 PCM4WAY_FillSE(uint16 value); 

uint16 PCM4WAY_GetFromSD(uint16 *dl_buf);
uint16 PCM4WAY_PutToSpk(const uint16 *dl_data); 
uint16 PCM4WAY_FillSpk(uint16 value);

void PCM2WAY_Start(void (*pcm2way_hdlr)(void), uint32 type);
void PCM2WAY_Stop(uint32 type);
// void Extended_PCM2WAY_Start(void (*pcm2way_dl_hdlr)(void), void (*pcm2way_ul_hdlr)(void), uint32 type, uint32 cfgUL, uint32 cfgDL);
// void Extended_PCM2WAY_Stop(uint32 type);

uint16 PCM2WAY_GetFromMic(uint16 *ul_buf);
uint16 PCM2WAY_PutToSpk(const uint16 *dl_data);
uint16 PCM2WAY_FillSpk(uint16 value);

#endif 
