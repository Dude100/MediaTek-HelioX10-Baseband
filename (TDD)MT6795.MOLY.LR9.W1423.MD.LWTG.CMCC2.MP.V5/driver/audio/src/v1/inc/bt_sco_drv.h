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
 *  BT_SCO_drv.h
 *
 * Project:
 * --------
 *  MOLY
 *
 * Description:
 * ------------
 *  BT SCO driver header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BT_SCO_DRV_H
#define __BT_SCO_DRV_H

#include "common_def.h"
#include "reg_base.h"

// PLC Interface
/*
extern kal_int32 g711plc_GetMemorySize(void);
extern void g711plc_construct(void *lc);
extern void g711plc_addtohistory(void *lc, kal_int16 *s);
extern void g711plc_dofe(void *lc,kal_int16 *out);
*/

extern void g711plc_addtohistory_v2(void *lc, short *s, unsigned int dwBtEv3HalfBad);
extern void g711plc_dofe_v2(void *lc, short *s, unsigned int dwBtEv3HalfBad);
extern int g711plc_GetMemorySize_v2();
extern int g711plc_construct_v2(void *lc, unsigned int dwFs);

extern void CVSD_DownSample_Process(void *pHandle, short *pInSample, short *pOutSample, short *pTempBuffer, int iSourceSamples);
extern int CVSD_DownSample_GetMemory(void);
extern void *CVSD_DownSample_Init(char *pBuffer);
extern void CVSD_UpSample_Process(void *pHandle, short *pInSample, short *pOutSample, short *pTempBuffer, int iSourceSamples);
extern int CVSD_UpSample_GetMemory(void);
extern void *CVSD_UpSample_Init(char *pBuffer);

void BT_SCO_Loopback_OFF(void);
void BT_SCO_Loopback_ON(kal_bool fDisableCodec, kal_bool fWideBand);
kal_bool BT_SCO_IS_SPEECH_ON(void);
void BT_SCO_SPEECH_OFF(void);
void BT_SCO_SPEECH_ON(kal_bool fWideBand);
void BT_SCO_Init(void);

#if defined(__CVSD_CODEC_SUPPORT__) 
#define __MSBC_CODEC_SUPPORT__ 1

// BT HW Register address
//#define BTSRAM_base              (0xA8080000) //defined in mcu/driver/sys_drv/regbase/inc/reg_base_mtxxxx.h
//#define BTPKT_base               (0xA8000000) //defined in mcu/driver/sys_drv/regbase/inc/reg_base_mtxxxx.h
#define BT_SCO_HW_REG_PACKET_R     ((volatile kal_uint32*)(BTPKT_base+0x0FD0))
#define BT_SCO_HW_REG_PACKET_W     ((volatile kal_uint32*)(BTPKT_base+0x0FD4))
#define BT_SCO_HW_REG_CONTROL      ((volatile kal_uint32*)(BTPKT_base+0x0FD8))

#if defined(MT6752) && defined(__MD2__)
// K2 MD2 BT phone call workaround
#define BT_SCO_BUS_STATE_REG    ((volatile kal_uint32 *)(INFRACFG_AO_BASE+0x0210))
#define BT_SCO_BUS_STATE_MASK   (0x1)
typedef enum {
  BT_SCO_BUS_STATE_OFF = 0x0,
  BT_SCO_BUS_STATE_ON  = 0x1
} BT_SCO_BUS_STATE_ENUM;
#endif  // defined(MT6752) && defined(__MD2__)
#endif
#if defined(MT6752) // temp irq id,for MT6752 MD2 
	#if !defined (__MD1__) 
	#define IRQ_BT_CVSD_CODE     0 
	#endif
#endif

#define MSBC_BTSTREAM_FRAME_BYTE 57
#define MSBC_PCM_FRAME_BYTE 240 //120 sample

#define BT_SCO_PACKET_120 120
#define BT_SCO_PACKET_180 180

#define BT_CVSD_TX_NREADY    (1<<21)
#define BT_CVSD_RX_READY     (1<<22)
#define BT_CVSD_TX_UNDERFLOW (1<<23)
#define BT_CVSD_RX_OVERFLOW  (1<<24)
#define BT_CVSD_INTERRUPT    (1<<31)

#define BT_CVSD_CLEAR        (BT_CVSD_TX_NREADY | BT_CVSD_RX_READY | BT_CVSD_TX_UNDERFLOW | BT_CVSD_RX_OVERFLOW | BT_CVSD_INTERRUPT)

//TX 
#define SCO_TX_ENCODE_SIZE           (60                             ) // 60 byte (60*8 samples)
#define SCO_TX_PACKER_BUF_NUM        (8                              ) 
#define SCO_TX_PACKET_MASK           (0x7                            )
#define SCO_TX_PCM64K_BUF_SIZE       (SCO_TX_ENCODE_SIZE*2*8         ) // 60 * 2 * 8 byte
#define SCO_TX_RINGBUFFER_SIZE       (320*9                          ) // = 2880, should by multple of 320 and 360 and 240

//RX
#define SCO_RX_PLC_SIZE              (30                    ) 
#define SCO_RX_PACKER_BUF_NUM        (16                    ) 
#define SCO_RX_PACKET_MASK           (0xF                   )
#define SCO_RX_PCM64K_BUF_SIZE       (SCO_RX_PLC_SIZE*2*8   ) 
#define SCO_RX_PCM8K_BUF_SIZE        (SCO_RX_PLC_SIZE*2     ) 
#define SCO_RX_RINGBUFFER_SIZE       (320*9                 ) // = 2880, should by multple of 320 and 360 and 240

#define SCORX_BT_CVSD_RX_PACKET_BUFFER_LEN (BT_CVSD_BLOCKSIZE * 6) // 360 byte

#define NB_SPEECH_FRAME_SIZE 320 //BYTE
#define WB_SPEECH_FRAME_SIZE 640 //BYTE

typedef enum {
  BT_SCO_STATE_IDLE=0,
  BT_SCO_STATE_RUNNING,
  BT_SCO_STATE_ENDING
} BT_SCO_STATE;

typedef enum {
  BT_SCO_MODE_SPEECH,
  BT_SCO_MODE_LOOPBACK_WITH_CODEC,
  BT_SCO_MODE_LOOPBACK_WITHOUT_CODEC
} BT_SCO_MODE;

typedef enum {
  BT_SCO_MOD_CVSD_ENCODE,
  BT_SCO_MOD_CVSD_DECODE,
  BT_SCO_MOD_PLC_NB,
  BT_SCO_MOD_CVSD_TX_SRC,
  BT_SCO_MOD_CVSD_RX_SRC,
  BT_SCO_MOD_PCM_RINGBUF_TX,
  BT_SCO_MOD_PCM_RINGBUF_RX,
  BT_SCO_MOD_MSBC_DECODE,
  BT_SCO_MOD_MSBC_ENCODE,
  BT_SCO_MOD_PLC_WB
} BT_SCO_MODULE;

typedef enum {
  BT_SCO_DIRECT_BT2ARM,
  BT_SCO_DIRECT_ARM2BT
} BT_SCO_DIRECT;

typedef enum {
  BT_SCO_CVSD_30 =0,
  BT_SCO_CVSD_60 =1,
  BT_SCO_CVSD_90 =2,
  BT_SCO_CVSD_120=3,
  BT_SCO_CVSD_10 =4,
  BT_SCO_CVSD_20 =5,
  BT_SCO_CVSD_MAX=6
} BT_SCO_PACKET_LEN;

typedef struct {
   //handle
   void          *pSRCHandle;
   void          *pEncHandle;
   AUD_RB_INFO   RingBuffer;

   //bitstream buffer
   kal_uint8     PacketBuf[SCO_TX_PACKER_BUF_NUM][SCO_TX_ENCODE_SIZE];
   kal_uint32    iPacket_w;        
   kal_uint32    iPacket_r; 
   kal_uint8     PcmBuf_64k[SCO_TX_PCM64K_BUF_SIZE];
   kal_uint8     PcmBuf_Temp[SCO_TX_PCM64K_BUF_SIZE]; 
   kal_uint32    uPcmBuf_w;
   kal_bool      fUnderflow;
} BT_SCO_TX;

typedef struct {
   //handle
   void          *pDecHandle;
   void          *pPLCHandle;
   void          *pSRCHandle;

   //bitstream buffer
   kal_uint8     PacketBuf[SCO_RX_PACKER_BUF_NUM][SCO_RX_PLC_SIZE];
   kal_bool      PacketValid[SCO_RX_PACKER_BUF_NUM];
   kal_uint32    iPacket_w;        
   kal_uint32    iPacket_r;       

   //temp buffer
   kal_uint8     PcmBuf_64k[SCO_RX_PCM64K_BUF_SIZE];
   kal_uint8     PcmBuf_Temp[SCO_RX_PCM64K_BUF_SIZE];
   kal_uint8     PcmBuf_8k[SCO_RX_PCM8K_BUF_SIZE];
   kal_uint32    uPcmBuf_r; //for PcmBuf_8k
   AUD_RB_INFO   RingBuffer;
   kal_bool      fOverflow;

} BT_SCO_RX;

#endif //__BT_SCO_DRV_H

