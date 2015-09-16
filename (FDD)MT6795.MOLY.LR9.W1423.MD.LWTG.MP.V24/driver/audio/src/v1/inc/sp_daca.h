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
 *==============================================================================
 *******************************************************************************/
#ifndef __DACA_H__
#define __DACA_H__
#include "common_def.h"


typedef struct{
   kal_uint16   aud_daca_id;         
   kal_uint32   state;         //identify pcm2way or pcm4way
   
   kal_uint32   am_type;
   kal_uint32   app_type;   
   kal_uint32   frame_size;  //to record the band information, please refer to PCMNWAY_BAND_INFO
      
   kal_uint32   u4DspPcmExMicLen;
   kal_uint32   u4DspPcmExSpkLen;
   
   void        (*daca_dl_hdlr)(void);
   void        (*daca_ul_hdlr)(void);
}_DACA_EX_T;


//the following macro is bit-wise
#define DACA_IN_PHONE_CALL 0x0001     
#define DACA_USE_NB        0x0002
#define DACA_USE_UL        0x0004
#define DACA_USE_DL        0x0008
#define DACA_UNDEFINED     0x8000

typedef enum {
  DACA_APP_TYPE_IDLE_UL_DL_NB        = DACA_USE_NB + DACA_USE_UL + DACA_USE_DL, 
  DACA_APP_TYPE_IDLE_UL_NB           = DACA_USE_NB + DACA_USE_UL, 
  DACA_APP_TYPE_IDLE_DL_NB           = DACA_USE_NB + DACA_USE_DL, 
  DACA_APP_TYPE_ACTIVE_UL_DL_NB      = DACA_IN_PHONE_CALL + DACA_USE_NB + DACA_USE_UL + DACA_USE_DL, 
  DACA_APP_TYPE_ACTIVE_UL_NB         = DACA_IN_PHONE_CALL + DACA_USE_NB + DACA_USE_UL, 
  DACA_APP_TYPE_ACTIVE_DL_NB         = DACA_IN_PHONE_CALL + DACA_USE_NB + DACA_USE_DL, 

  DACA_APP_TYPE_IDLE_UL_DL_WB        = DACA_USE_UL + DACA_USE_DL,                            
  DACA_APP_TYPE_IDLE_UL_WB           = DACA_USE_UL,                                    
  DACA_APP_TYPE_IDLE_DL_WB           = DACA_USE_DL,                                     
  DACA_APP_TYPE_ACTIVE_UL_DL_WB      = DACA_IN_PHONE_CALL + DACA_USE_UL + DACA_USE_DL,  
  DACA_APP_TYPE_ACTIVE_UL_WB         = DACA_IN_PHONE_CALL + DACA_USE_UL ,               
  DACA_APP_TYPE_ACTIVE_DL_WB         = DACA_IN_PHONE_CALL + DACA_USE_DL,                
    
  DACA_APP_TYPE_UNDEFINE             = DACA_UNDEFINED
}DACA_APP_TYPE;

void    DACA_Start(void (*daca_dl_hdlr)(void), void (*daca_ul_hdlr)(void), DACA_APP_TYPE app_type);
void    DACA_Stop(DACA_APP_TYPE app_type);
uint32  DACA_GetFromSD(uint16 *dl_buf);
void    DACA_PutToSE(const uint16 *ul_data);
void    DACA_FillSE(uint16 value);  


#endif 
