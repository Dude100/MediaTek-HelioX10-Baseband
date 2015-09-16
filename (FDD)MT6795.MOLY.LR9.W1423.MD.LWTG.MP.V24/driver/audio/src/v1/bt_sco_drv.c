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
 *  BT_SCO_drv.c
 *
 * Project:
 * --------
 *  Maui_sw
 *
 * Description:
 * ------------
 *  BT SCO driver
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
 *============================================================================
 ****************************************************************************/

#if defined(__CVSD_CODEC_SUPPORT__) 

#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "l1audio.h"
#include "speech_def.h"
#include "media.h"
#include "audio_enum.h"
#include "l1sp_trc.h"
#include "bt_sco_drv.h"
#include "cvsd_codec_exp.h"
#include "sp_daca.h"
#include "intrCtrl.h"
#include "audio_dsp_d2c_def.h"
#include "dcl.h"

//#define DISABLE_BTCVSD_FOR_CHIPBACK_BOOTUP 1
//#define DELAY_UNMASK_INTERRUPT 1

extern void L1Audio_TrigD2CHisr(uint16 magicNo);
#define SCO_CVSD_BUFFER_SIZE 30000//24004//(13296)
static kal_uint8 SCO_CVSD_BUFFER[SCO_CVSD_BUFFER_SIZE];

#if defined(DELAY_UNMASK_INTERRUPT)
static kal_uint32 uCVSDGPT;
#endif

static const kal_uint32 btsco_PacketValidMask[6][6] = {{0x1   , 0x1<<1, 0x1<<2, 0x1<<3, 0x1<<4 , 0x1<<5 },  //30
                                                       {0x1   , 0x1   , 0x2   , 0x2   , 0x4    , 0x4    },  //60
                                                       {0x1   , 0x1   , 0x1   , 0x2   , 0x2    , 0x2    },  //90
                                                       {0x1   , 0x1   , 0x1   , 0x1   , 0      , 0      },  //120
                                                       {0x7   , 0x7<<3, 0x7<<6, 0x7<<9, 0x7<<12, 0x7<<15},  //10
                                                       {0x3   , 0x3<<1, 0x3<<3, 0x3<<4, 0x3<<6 , 0x3<<7 }}; //20

static const kal_uint8 btsco_PacketInfo[6][6] = {{ 30, 6, BT_SCO_PACKET_180/SCO_TX_ENCODE_SIZE, BT_SCO_PACKET_180/SCO_RX_PLC_SIZE},  // 30, 6, 3, 6
                                                 { 60, 3, BT_SCO_PACKET_180/SCO_TX_ENCODE_SIZE, BT_SCO_PACKET_180/SCO_RX_PLC_SIZE},  // 60, 3, 3, 6
                                                 { 90, 2, BT_SCO_PACKET_180/SCO_TX_ENCODE_SIZE, BT_SCO_PACKET_180/SCO_RX_PLC_SIZE},  // 90, 2, 3, 6
                                                 {120, 1, BT_SCO_PACKET_120/SCO_TX_ENCODE_SIZE, BT_SCO_PACKET_120/SCO_RX_PLC_SIZE},  //120, 1, 2, 4
                                                 { 10,18, BT_SCO_PACKET_180/SCO_TX_ENCODE_SIZE, BT_SCO_PACKET_180/SCO_RX_PLC_SIZE},  // 10,18, 3, 6
                                                 { 20, 9, BT_SCO_PACKET_180/SCO_TX_ENCODE_SIZE, BT_SCO_PACKET_180/SCO_RX_PLC_SIZE}}; // 20, 9, 3, 6

static const kal_uint8 btsco_MsbcHeader[4] = {0x08, 0x38, 0xc8, 0xf8};

static struct{
   BT_SCO_TX *pTX;
   BT_SCO_RX *pRX;
   kal_uint8 *pTempPacketBuf;
   kal_uint8 *pSpeechData;
   kal_uint16 uAudId;
   BT_SCO_STATE uState;
   BT_SCO_MODE uMode;
   bool fBtError;
   bool fWideBand;
#if defined(MT6752) && defined(__MD2__)
    // K2 MD2 BT phone call workaround
    BT_SCO_BUS_STATE_ENUM bus_state;
#endif  // defined(MT6752) && defined(__MD2__)
}btsco;

#if defined(MT6752) && defined(__MD2__)
// K2 MD2 BT phone call workaround
kal_timerid btsco_timer;
#endif  // defined(MT6752) && defined(__MD2__)

void BT_SCO_LISR(void);

//=============================================================================================
//    BT SCO Buffer control interface
//=============================================================================================

static void BT_SCO_GetReadBuffer_RX(kal_uint8 **pBuf, kal_uint32 *pLen)
{
   ASSERT(btsco.pRX->RingBuffer.rb_base);
   rbGetReadBuffer(&btsco.pRX->RingBuffer, pBuf, pLen);
}

static void BT_SCO_ReadDataDone_RX(kal_uint32 uLen)
{
   ASSERT(btsco.pRX->RingBuffer.rb_base);
   rbReadDataDone(&btsco.pRX->RingBuffer, uLen);
}

static kal_int32 BT_SCO_GetDataCount_RX()
{
   ASSERT(btsco.pRX->RingBuffer.rb_base);
   return rbGetDataCount(&btsco.pRX->RingBuffer);
}

static void BT_SCO_GetWriteBuffer_TX(kal_uint8 **pBuf, kal_uint32 *pLen)
{
   ASSERT(btsco.pTX->RingBuffer.rb_base);
   rbGetWriteBuffer(&btsco.pTX->RingBuffer, pBuf, pLen);
}

static void BT_SCO_WriteDataDone_TX(kal_uint32 uLen)
{
   ASSERT(btsco.pTX->RingBuffer.rb_base);
   rbWriteDataDone(&btsco.pTX->RingBuffer, uLen);
}

static kal_int32 BT_SCO_GetFreeSpace_TX()
{
   ASSERT(btsco.pTX->RingBuffer.rb_base);
   return rbGetFreeSpace(&btsco.pTX->RingBuffer);
}

static void btsco_GetReadBuffer_TX(kal_uint8 **pBuf, kal_uint32 *pLen)
{
   ASSERT(btsco.pTX->RingBuffer.rb_base);
   rbGetReadBuffer(&btsco.pTX->RingBuffer, pBuf, pLen);
}

static void btsco_ReadDataDone_TX(kal_uint32 uLen)
{
   ASSERT(btsco.pTX->RingBuffer.rb_base);
   rbReadDataDone(&btsco.pTX->RingBuffer, uLen);
}

static kal_uint32 btsco_GetDataCount_TX()
{
   ASSERT(btsco.pTX->RingBuffer.rb_base);
   return rbGetDataCount(&btsco.pTX->RingBuffer);
}

static kal_int32 btsco_GetFreeSpace_RX()
{
   ASSERT(btsco.pRX->RingBuffer.rb_base);
   return rbGetFreeSpace(&btsco.pRX->RingBuffer);
}

static void btsco_GetWriteBuffer_RX(kal_uint8 **pBuf, kal_uint32 *pLen)
{
   ASSERT(btsco.pRX->RingBuffer.rb_base);
   rbGetWriteBuffer(&btsco.pRX->RingBuffer, pBuf, pLen);
}

static void btsco_WriteDataDone_RX(kal_uint32 uLen)
{
   ASSERT(btsco.pRX->RingBuffer.rb_base);
   rbWriteDataDone(&btsco.pRX->RingBuffer, uLen);
}

//=============================================================================================
//    BT SCO Internal Function
//=============================================================================================

static void btsco_DataTransfer(BT_SCO_DIRECT uDir, kal_uint8 *pSrc, kal_uint8 *pDst, kal_uint32 uBlockSize, kal_uint32 uBlockNum  )
{
   kal_int32 i, j;
   if(uBlockSize == 60 || uBlockSize == 120 || uBlockSize == 20)
   {
      kal_uint32 *pSrc32 = (kal_uint32*)pSrc;
      kal_uint32 *pDst32 = (kal_uint32*)pDst;
      for(i=0 ; i<(uBlockSize*uBlockNum/4) ; i++)
      {
         *pDst32++ = *pSrc32++;
      }
   }
   else
   {
      kal_uint16 *pSrc16 = (kal_uint16*)pSrc;
      kal_uint16 *pDst16 = (kal_uint16*)pDst;
      for(j=0 ; j< uBlockNum ; j++)
      {
         for(i=0 ; i<(uBlockSize/2) ; i++)
         {
            *pDst16++ = *pSrc16++;
         }
         if(uDir == BT_SCO_DIRECT_BT2ARM)
         {
            pSrc16++;
         }
         else
         {
            pDst16++;
         }
      }
   }
}

static void btsco_ReadFromBT(BT_SCO_PACKET_LEN uLen, kal_uint32 uPacketLength, kal_uint32 uPacketNumber, kal_uint32 uBlockSize, kal_uint32 uControl)
{
   kal_int32 i;
   kal_uint8 *pSrc = (kal_uint8 *)(BTSRAM_base + ((((*BT_SCO_HW_REG_PACKET_R & 0x00F00000)>>4)-0x00010000) | (*BT_SCO_HW_REG_PACKET_R & 0xFFFF)));
   btsco_DataTransfer(BT_SCO_DIRECT_BT2ARM, pSrc, btsco.pTempPacketBuf, uPacketLength, uPacketNumber );
   if(btsco.uState ==  BT_SCO_STATE_ENDING)
   {
#if defined(__MSBC_CODEC_SUPPORT__)
      if(btsco.fWideBand)
      {
         memset(btsco.pTempPacketBuf,	0, uPacketLength*uPacketNumber*sizeof(kal_uint8));
      }
      else
#endif
      {
         memset(btsco.pTempPacketBuf, 0x55, uPacketLength*uPacketNumber*sizeof(kal_uint8));
      }
   }
   for(i=0;i<uBlockSize;i++)
   {
      memcpy(btsco.pRX->PacketBuf[btsco.pRX->iPacket_w & SCO_RX_PACKET_MASK], btsco.pTempPacketBuf+(SCO_RX_PLC_SIZE*i), SCO_RX_PLC_SIZE);
      if( (uControl & btsco_PacketValidMask[uLen][i]) == btsco_PacketValidMask[uLen][i])
      {
         btsco.pRX->PacketValid[btsco.pRX->iPacket_w & SCO_RX_PACKET_MASK] = 1 ; //packet valid
      }
      else
      {
         btsco.pRX->PacketValid[btsco.pRX->iPacket_w & SCO_RX_PACKET_MASK] = 0 ; //packet invalid
	  }
      btsco.pRX->iPacket_w++;
   }
}

static void btsco_WriteToBT(BT_SCO_PACKET_LEN uLen, kal_uint32 uPacketLength, kal_uint32 uPacketNumber, kal_uint32 uBlockSize, kal_bool fFillSilence)
{
   kal_int32 i;
   kal_uint8 *pDst = (kal_uint8 *)(BTSRAM_base + ((((*BT_SCO_HW_REG_PACKET_W & 0x00F00000)>>4)-0x00010000) | (*BT_SCO_HW_REG_PACKET_W & 0xFFFF)));
   if(fFillSilence == KAL_TRUE)
   {
#if defined(__MSBC_CODEC_SUPPORT__)
	  if(btsco.fWideBand)
	  {
         memset(btsco.pTempPacketBuf,    0, uPacketLength*uPacketNumber*sizeof(kal_uint8));
      }
      else
#endif
      {
         memset(btsco.pTempPacketBuf, 0x55, uPacketLength*uPacketNumber*sizeof(kal_uint8));
      }
   }
   else
   {
      for(i=0;i<uBlockSize;i++)
      { 
         memcpy(btsco.pTempPacketBuf+(SCO_TX_ENCODE_SIZE*i), btsco.pTX->PacketBuf[btsco.pTX->iPacket_r & SCO_TX_PACKET_MASK], SCO_TX_ENCODE_SIZE);
         btsco.pTX->iPacket_r++;
      }
   }
   btsco_DataTransfer(BT_SCO_DIRECT_ARM2BT, btsco.pTempPacketBuf, pDst, uPacketLength, uPacketNumber );
}

static void btsco_hisr_internal()
{
   kal_uint32 uPacketType, uPacketNumber, uPacketLength, uBufferCount_TX, uBufferCount_RX, uControl;
   if((btsco.uState != BT_SCO_STATE_RUNNING) && (btsco.uState !=  BT_SCO_STATE_ENDING))
   {
      return;
   }
   uControl = *BT_SCO_HW_REG_CONTROL;
   uPacketType = (uControl >> 18) & 0x7;
   kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_CONTROL, uControl, uPacketType, *BT_SCO_HW_REG_PACKET_W, *BT_SCO_HW_REG_PACKET_R);

   btsco.fBtError = KAL_FALSE;
   if(*BT_SCO_HW_REG_PACKET_W == 0 || *BT_SCO_HW_REG_PACKET_R == 0 || uControl == 0) 
   {   
      kal_prompt_trace(MOD_L1SP, "[CVSD]btsco_hisr address: W:%x, R:%x, status:%x", BT_SCO_HW_REG_PACKET_W, BT_SCO_HW_REG_PACKET_R, BT_SCO_HW_REG_CONTROL);
      btsco.fBtError = KAL_TRUE;
      return;
   }
   if( ((uControl>>31) & 1) == 0)
   {
      return;
   }
   ASSERT(uPacketType < BT_SCO_CVSD_MAX);
   uPacketLength   = (kal_uint32)btsco_PacketInfo[uPacketType][0];
   uPacketNumber   = (kal_uint32)btsco_PacketInfo[uPacketType][1];
   uBufferCount_TX = (kal_uint32)btsco_PacketInfo[uPacketType][2];
   uBufferCount_RX = (kal_uint32)btsco_PacketInfo[uPacketType][3];

   if(btsco.uMode == BT_SCO_MODE_LOOPBACK_WITHOUT_CODEC) // read data from BT and write back directly
   {
      kal_uint8 *pDst, *pSrc;
      pDst = (kal_uint8 *)(BTSRAM_base + ((((*BT_SCO_HW_REG_PACKET_W & 0x00F00000)>>4)-0x00010000) | (*BT_SCO_HW_REG_PACKET_W & 0xFFFF)));
      pSrc = (kal_uint8 *)(BTSRAM_base + ((((*BT_SCO_HW_REG_PACKET_R & 0x00F00000)>>4)-0x00010000) | (*BT_SCO_HW_REG_PACKET_R & 0xFFFF)));
      btsco_DataTransfer(BT_SCO_DIRECT_BT2ARM, pSrc, btsco.pTempPacketBuf, uPacketLength, uPacketNumber );
      btsco_DataTransfer(BT_SCO_DIRECT_ARM2BT, btsco.pTempPacketBuf, pDst, uPacketLength, uPacketNumber );
      return;
   }

   if(btsco.pRX)
   {
      kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_COPY_RX, btsco.pRX->fOverflow, btsco.pRX->iPacket_w, btsco.pRX->iPacket_r, uBufferCount_RX);
      if(btsco.pRX->fOverflow)
      {
         if(btsco.pRX->iPacket_w - btsco.pRX->iPacket_r <= SCO_RX_PACKER_BUF_NUM - 2*uBufferCount_RX) 
         {
            //free space is larger then twice interrupt rx data size
            btsco.pRX->fOverflow = KAL_FALSE;
         }  
      }
      if(!btsco.pRX->fOverflow && (btsco.pRX->iPacket_w - btsco.pRX->iPacket_r <= SCO_RX_PACKER_BUF_NUM - uBufferCount_RX))
      {
         btsco_ReadFromBT(uPacketType, uPacketLength, uPacketNumber, uBufferCount_RX, uControl);
      }
      else
      {
         btsco.pRX->fOverflow = KAL_TRUE;
      }
   }

   if(btsco.pTX)
   {
      kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_COPY_TX, btsco.pTX->fUnderflow, btsco.pTX->iPacket_w, btsco.pTX->iPacket_r, uBufferCount_TX);
      if(btsco.pTX->fUnderflow)
      {
         //prepared data is larger then twice interrupt tx data size
         if(btsco.pTX->iPacket_w - btsco.pTX->iPacket_r >= 2*uBufferCount_TX)
         {
            btsco.pTX->fUnderflow = KAL_FALSE;
         }         
      }
	  
      if(btsco.pTX->iPacket_w - btsco.pTX->iPacket_r < uBufferCount_TX)
      {
            btsco.pTX->fUnderflow = KAL_TRUE;
      }

	  if(btsco.pTX->fUnderflow || btsco.uState == BT_SCO_STATE_ENDING)
	  {  //silence
	     btsco_WriteToBT(uPacketType, uPacketLength, uPacketNumber, uBufferCount_TX, KAL_TRUE);
	  }
	  else
	  {  //cvsd packet
	     btsco_WriteToBT(uPacketType, uPacketLength, uPacketNumber, uBufferCount_TX, KAL_FALSE);
	  }
   }
   L1Audio_SetEvent( btsco.uAudId, NULL );
}

#if defined(DELAY_UNMASK_INTERRUPT)
static void btsco_DelayInterruptUnMask( void *data )
{
   if( btsco.uState != BT_SCO_STATE_IDLE )
   {
#if defined(MT6752) && defined(__MD2__)
    // K2 MD2 BT phone call workaround
#else   // defined(MT6752) && defined(__MD2__)
        IRQUnmask(IRQ_BT_CVSD_CODE);
#endif  // defined(MT6752) && defined(__MD2__)
   }
}
#endif

static void btsco_hisr(void *pData)
{
   kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_HISR, btsco.uState);
   btsco_hisr_internal();
   *BT_SCO_HW_REG_CONTROL &= ~BT_CVSD_CLEAR;
#if !defined(DISABLE_BTCVSD_FOR_CHIPBACK_BOOTUP)   
   if( btsco.uState != BT_SCO_STATE_IDLE )
   {
#if defined(DELAY_UNMASK_INTERRUPT)     
      kal_trace( TRACE_GROUP_SCO,L1AUDIO_BTSCO_HISR_GPT, btsco.fBtError, uCVSDGPT);  

      if(btsco.fBtError == KAL_TRUE && uCVSDGPT)
      {
  	     #define CVSD_DELAY_INTERRUPT 1000 //msec
  	     SGPT_CTRL_START_T start;
         start.u2Tick = (CVSD_DELAY_INTERRUPT / 10);
         start.pfCallback = btsco_DelayInterruptUnMask;
         start.vPara = NULL;
         DclSGPT_Control( uCVSDGPT, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
      }
      else
#endif
      {
#if defined(MT6752) && defined(__MD2__)
    // K2 MD2 BT phone call workaround
#else   // defined(MT6752) && defined(__MD2__)
            IRQUnmask(IRQ_BT_CVSD_CODE);
#endif  // defined(MT6752) && defined(__MD2__)
      }
   }
#endif
}  

static kal_uint32 btsco_GetMemorySize_4ByteAlign(BT_SCO_MODULE uModule)
{
   kal_uint32 uSize=0;
   switch(uModule)
   {
      case BT_SCO_MOD_CVSD_ENCODE: 
         uSize = (kal_uint32)CVSD_ENC_GetBufferSize();
         break;
      case BT_SCO_MOD_CVSD_DECODE: 
         uSize = (kal_uint32)CVSD_DEC_GetBufferSize();
         break;
	  case BT_SCO_MOD_PLC_NB:
	  case BT_SCO_MOD_PLC_WB:
		 uSize = (kal_uint32)g711plc_GetMemorySize_v2();
         break;
      case BT_SCO_MOD_CVSD_TX_SRC:
         uSize = CVSD_UpSample_GetMemory();
         break;
      case BT_SCO_MOD_CVSD_RX_SRC:
         uSize = CVSD_DownSample_GetMemory();
         break;
      case BT_SCO_MOD_PCM_RINGBUF_TX:
         uSize = SCO_TX_RINGBUFFER_SIZE;
         break;
      case BT_SCO_MOD_PCM_RINGBUF_RX:
         uSize = SCO_RX_RINGBUFFER_SIZE;
         break;
#if defined(__CVSD_CODEC_SUPPORT__)
	  case BT_SCO_MOD_MSBC_ENCODE: 
		 uSize = (kal_uint32)MSBC_ENC_GetBufferSize();
		 break;
	  case BT_SCO_MOD_MSBC_DECODE: 
		 uSize = (kal_uint32)MSBC_DEC_GetBufferSize();
		 break;
#endif
      default:
         ASSERT(0);
   }
   uSize = (uSize+3) & ~3 ;
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_GET_MEM, uModule, uSize);
   return uSize;
}

static void btsco_InitialModule(BT_SCO_MODULE uModule, kal_uint8 *pBuf)
{
   ASSERT(pBuf);
   switch(uModule)
   {
      case BT_SCO_MOD_CVSD_ENCODE: 
         btsco.pTX->pEncHandle = CVSD_ENC_Init((kal_int8*)pBuf);
         break;
      case BT_SCO_MOD_CVSD_DECODE: 
         btsco.pRX->pDecHandle = CVSD_DEC_Init((kal_int8*)pBuf);
         break;
      case BT_SCO_MOD_PLC_NB:
         g711plc_construct_v2((void *)pBuf, 8000);
         btsco.pRX->pPLCHandle = (void*)pBuf;
         break;
      case BT_SCO_MOD_CVSD_TX_SRC:
         btsco.pTX->pSRCHandle = CVSD_UpSample_Init((kal_int8*)pBuf);
         break;
      case BT_SCO_MOD_CVSD_RX_SRC:
         btsco.pRX->pSRCHandle = CVSD_DownSample_Init((kal_int8*)pBuf);
         break;
      case BT_SCO_MOD_PCM_RINGBUF_TX:
         btsco.pTX->RingBuffer.rb_base = pBuf;
         btsco.pTX->RingBuffer.rb_size = SCO_TX_RINGBUFFER_SIZE;
         break;
      case BT_SCO_MOD_PCM_RINGBUF_RX:
         btsco.pRX->RingBuffer.rb_base = pBuf;
         btsco.pRX->RingBuffer.rb_size = SCO_RX_RINGBUFFER_SIZE;
         break;
#if defined(__MSBC_CODEC_SUPPORT__)
      case BT_SCO_MOD_MSBC_ENCODE: 
         btsco.pTX->pEncHandle = MSBC_ENC_Init((kal_int8*)pBuf);
         break;
      case BT_SCO_MOD_MSBC_DECODE: 
         btsco.pRX->pDecHandle = MSBC_DEC_Init((kal_int8*)pBuf);
         break;
      case BT_SCO_MOD_PLC_WB:
         g711plc_construct_v2((void *)pBuf, 16000);
         btsco.pRX->pPLCHandle = (void*)pBuf;
         break;
#endif
      default:
         ASSERT(0);
   }
}

static void btsco_AllocMemory_CVSD()
{
   kal_uint32 uTotalMemory = 0, uTxMemSize = 0, uRxMemSize = 0, uSpeechBufferSize=0;
   kal_uint8 *pBuf = SCO_CVSD_BUFFER;
   uTxMemSize = (sizeof(BT_SCO_TX)+3)& ~0x3;
   uRxMemSize = (sizeof(BT_SCO_RX)+3)& ~0x3;
   uSpeechBufferSize = (NB_SPEECH_FRAME_SIZE+3)& ~0x3;  
   uTotalMemory = uTxMemSize+uRxMemSize+uSpeechBufferSize+BT_SCO_PACKET_180;
   uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PCM_RINGBUF_TX);
   uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_ENCODE);
   uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_TX_SRC);
   uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PCM_RINGBUF_RX);
   uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_DECODE);
   uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_RX_SRC);
   uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PLC_NB);

   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_ALLOC_MEM, uTotalMemory, pBuf);
   ASSERT(SCO_CVSD_BUFFER_SIZE >= uTotalMemory);	   //double check 
   memset(SCO_CVSD_BUFFER, 0, SCO_CVSD_BUFFER_SIZE);  

   btsco.pTX = (BT_SCO_TX*)pBuf;
   pBuf += uTxMemSize;
   btsco.pRX = (BT_SCO_RX*)pBuf;
   pBuf += uRxMemSize;
   btsco.pSpeechData = (kal_uint8 *)pBuf;
   pBuf += uSpeechBufferSize;
   btsco.pTempPacketBuf = (kal_uint8 *)pBuf;
   pBuf += BT_SCO_PACKET_180;
   btsco_InitialModule(BT_SCO_MOD_CVSD_ENCODE, pBuf);
   pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_ENCODE);
   btsco_InitialModule(BT_SCO_MOD_CVSD_TX_SRC, pBuf);
   pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_TX_SRC);
   btsco_InitialModule(BT_SCO_MOD_PCM_RINGBUF_TX, pBuf);
   pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PCM_RINGBUF_TX);
   btsco_InitialModule(BT_SCO_MOD_CVSD_DECODE, pBuf);
   pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_DECODE);
   btsco_InitialModule(BT_SCO_MOD_CVSD_RX_SRC, pBuf);
   pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_CVSD_RX_SRC);
   btsco_InitialModule(BT_SCO_MOD_PCM_RINGBUF_RX, pBuf);
   pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PCM_RINGBUF_RX);
   btsco_InitialModule(BT_SCO_MOD_PLC_NB, pBuf);
   pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PLC_NB);

   kal_prompt_trace(MOD_L1SP, "[CVSD]BT_SCO_Alloc_CVSD_Memory: uTotalMemory %d", uTotalMemory);
}

static void btsco_process_TX_CVSD()
{
   kal_int32 iCount=0;
   while(1)
   {
      for(iCount = 0 ; iCount < 2 ; iCount++)
      {  //downsample
         kal_uint8 *pInBuf;
         kal_uint32 uInByte=0, uOutByte=0, uConsumeByte=0;
         if(SCO_TX_PCM64K_BUF_SIZE != btsco.pTX->uPcmBuf_w)
         {
            btsco_GetReadBuffer_TX(&pInBuf, &uInByte);
            kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROC_TX_RAW, uInByte, btsco.pTX->uPcmBuf_w);
            uInByte = uInByte & 0xFFFFFFFE;
            if(uInByte<2)
            {
               return;
            }
            uOutByte = SCO_TX_PCM64K_BUF_SIZE - btsco.pTX->uPcmBuf_w;
            {
               kal_uint32 uSrcInSample, uSrcOutSample;
               uSrcInSample = uInByte >> 1;
               uSrcOutSample = uOutByte >> 1;
               if((uSrcInSample) > (uSrcOutSample>>3))
               {
                  uSrcInSample = uSrcOutSample>>3;
               }
               CVSD_UpSample_Process(btsco.pTX->pSRCHandle, (kal_int16 *)pInBuf, (kal_int16 *)(&btsco.pTX->PcmBuf_64k[btsco.pTX->uPcmBuf_w]), (kal_int16 *)btsco.pTX->PcmBuf_Temp, uSrcInSample);
               uConsumeByte = uSrcInSample<<1;
               uOutByte = uSrcInSample<<4;
            }
            kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROC_TX_SRC, uConsumeByte, uOutByte);
            btsco.pTX->uPcmBuf_w += uOutByte;
            btsco_ReadDataDone_TX(uConsumeByte);
         }
      }
      if(SCO_TX_PCM64K_BUF_SIZE == btsco.pTX->uPcmBuf_w) 
      {
         if(btsco.pTX->iPacket_w - btsco.pTX->iPacket_r < SCO_TX_PACKER_BUF_NUM)
         {
            kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROC_TX_CVSD, btsco.pTX->iPacket_w, btsco.pTX->iPacket_r, 0);
            {  //encode
               kal_int32 iInSample = SCO_TX_PCM64K_BUF_SIZE>>1;
               kal_int32 iOutByte = SCO_TX_ENCODE_SIZE;
               CVSD_ENC_Process(btsco.pTX->pEncHandle, (kal_int16*)btsco.pTX->PcmBuf_64k, &iInSample, (char*)&btsco.pTX->PacketBuf[btsco.pTX->iPacket_w & SCO_TX_PACKET_MASK][0], &iOutByte);
               btsco.pTX->uPcmBuf_w = 0;
               btsco.pTX->iPacket_w++;
            }
         }
         else
         {
            return;
         }
      }
   }
}

static void btsco_process_RX_CVSD()
{
   kal_int32 iCount=0;
   while(1)
   {
      if(SCO_RX_PCM8K_BUF_SIZE == btsco.pRX->uPcmBuf_r)
      {
         //decode 30 byte cvsd
         if(btsco.pRX->iPacket_w != btsco.pRX->iPacket_r)
         {
            kal_int32 iOutSample=0, iInByte=0;
            iInByte=SCO_RX_PLC_SIZE;
            iOutSample=SCO_RX_PCM64K_BUF_SIZE>>1;
            kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROC_RX_CVSD, btsco.pRX->iPacket_w, btsco.pRX->iPacket_r, 0, 1);
            CVSD_DEC_Process(btsco.pRX->pDecHandle, (char*)&btsco.pRX->PacketBuf[btsco.pRX->iPacket_r & SCO_RX_PACKET_MASK][0], &iInByte, (kal_int16*)btsco.pRX->PcmBuf_64k, &iOutSample);
            {
               kal_uint32 uConsumeByte=0;
               CVSD_DownSample_Process(btsco.pRX->pSRCHandle, (kal_int16 *)btsco.pRX->PcmBuf_64k, (kal_int16 *)btsco.pRX->PcmBuf_8k, (kal_int16 *)btsco.pRX->PcmBuf_Temp, SCO_RX_PCM64K_BUF_SIZE>>1);
               uConsumeByte = SCO_RX_PCM64K_BUF_SIZE;
               ASSERT(uConsumeByte == SCO_RX_PCM64K_BUF_SIZE);
            }
            if(btsco.uMode == BT_SCO_MODE_SPEECH)//do PLC
            {  
               kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROC_RX_PLC);
               if(btsco.pRX->PacketValid[btsco.pRX->iPacket_r & SCO_RX_PACKET_MASK])
               {  //packet not lost
                  g711plc_addtohistory_v2(btsco.pRX->pPLCHandle, (short *)btsco.pRX->PcmBuf_8k, 0);
                  kal_prompt_trace(MOD_L1SP, "[CVSD]g711plc_addtohistory copy: btsco.pRX->iPacket_r %d", btsco.pRX->iPacket_r);
               }
               else
               {  //packet lost
                  g711plc_dofe_v2(btsco.pRX->pPLCHandle, (short *)btsco.pRX->PcmBuf_8k, 0);
                  kal_prompt_trace(MOD_L1SP, "[CVSD]g711plc_dofe copy: btsco.pRX->iPacket_r %d", btsco.pRX->iPacket_r);
               }
            }
            btsco.pRX->iPacket_r++;
            btsco.pRX->uPcmBuf_r=0;
         }
         else
         {  //cvsd buffer empty
            return;
         }

      }
      for(iCount = 0 ; iCount < 2 ; iCount++)
      {
         kal_uint32 uOutByte=0, uConsumeByte=0, uTotalSpace=0;
         kal_uint8 *pOutBuf;
         btsco_GetWriteBuffer_RX(&pOutBuf, &uOutByte);
         uTotalSpace = btsco_GetFreeSpace_RX();
         kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROC_RX_RAW, uOutByte, uTotalSpace, btsco.pRX->uPcmBuf_r);
         uOutByte = uOutByte & 0xFFFFFFFE;;
         if(uOutByte<2)
         {  //output buffer is empty
            return;
         }
         {  //output is 8k mono
            uConsumeByte = SCO_RX_PCM8K_BUF_SIZE - btsco.pRX->uPcmBuf_r;    
            if(uConsumeByte>uOutByte)
            {
               uConsumeByte = uOutByte;
            }
            memcpy(pOutBuf, (btsco.pRX->PcmBuf_8k + btsco.pRX->uPcmBuf_r), uConsumeByte);
            uOutByte = uConsumeByte;
         }
         btsco.pRX->uPcmBuf_r += uConsumeByte;
         btsco_WriteDataDone_RX(uOutByte);
         if(SCO_RX_PCM8K_BUF_SIZE == btsco.pRX->uPcmBuf_r)
         {
            break;
         }
      }
   }
}

#if defined(__MSBC_CODEC_SUPPORT__) 

static void btsco_AllocMemory_MSBC()
{
   kal_uint32 uTotalMemory = 0, uTxMemSize = 0, uRxMemSize = 0, uSpeechBufferSize=0;
   kal_uint8 *pBuf = SCO_CVSD_BUFFER;
   uTxMemSize = (sizeof(BT_SCO_TX)+3)& ~0x3;
   uRxMemSize = (sizeof(BT_SCO_RX)+3)& ~0x3;
   uSpeechBufferSize = (WB_SPEECH_FRAME_SIZE+3)& ~0x3;  
   uTotalMemory = uTxMemSize+uRxMemSize+uSpeechBufferSize+BT_SCO_PACKET_180;
   uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PCM_RINGBUF_TX);
   uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_MSBC_ENCODE);
   uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PCM_RINGBUF_RX);
   uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_MSBC_DECODE);
   uTotalMemory += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PLC_WB);

   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_ALLOC_MEM, uTotalMemory, pBuf);
   ASSERT(SCO_CVSD_BUFFER_SIZE >= uTotalMemory);	   //double check 
   memset(SCO_CVSD_BUFFER, 0, SCO_CVSD_BUFFER_SIZE);  

   btsco.pTX = (BT_SCO_TX*)pBuf;
   pBuf += uTxMemSize;
   btsco.pRX = (BT_SCO_RX*)pBuf;
   pBuf += uRxMemSize;
   btsco.pSpeechData = (kal_uint8 *)pBuf;
   pBuf += uSpeechBufferSize;
   btsco.pTempPacketBuf = (kal_uint8 *)pBuf;
   pBuf += BT_SCO_PACKET_180;
   btsco_InitialModule(BT_SCO_MOD_PCM_RINGBUF_TX, pBuf);
   pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PCM_RINGBUF_TX);
   btsco_InitialModule(BT_SCO_MOD_MSBC_ENCODE, pBuf);
   pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_MSBC_ENCODE);
   btsco_InitialModule(BT_SCO_MOD_PCM_RINGBUF_RX, pBuf);
   pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PCM_RINGBUF_RX);
   btsco_InitialModule(BT_SCO_MOD_MSBC_DECODE, pBuf);
   pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_MSBC_DECODE);
   btsco_InitialModule(BT_SCO_MOD_PLC_WB, pBuf);
   pBuf += btsco_GetMemorySize_4ByteAlign(BT_SCO_MOD_PLC_WB);

   kal_prompt_trace(MOD_L1SP, "[CVSD]BT_SCO_Alloc_MSBC_Memory: uTotalMemory %d", uTotalMemory);
}

static void btsco_process_TX_MSBC()
{
   kal_int32 iInByte1=0, iInByte2, iOutByte=0, status=0, iInSample=0, index=0;
   kal_uint8 *pSrcBuf;
   while(1)
   {
      if(btsco_GetDataCount_TX() < MSBC_PCM_FRAME_BYTE)
      {
         break; // source pcm not enough one frame
      }
	  if(btsco.pTX->iPacket_w - btsco.pTX->iPacket_r >= SCO_TX_PACKER_BUF_NUM)
	  {
         break; // bitstream buffer full
	  }
      btsco_GetReadBuffer_TX(&pSrcBuf, &iInByte1);
      if(iInByte1 > MSBC_PCM_FRAME_BYTE)
      {
         memcpy(btsco.pTX->PcmBuf_64k, pSrcBuf, MSBC_PCM_FRAME_BYTE);
         btsco_ReadDataDone_TX(MSBC_PCM_FRAME_BYTE);
      }
      else
      {
         memcpy(btsco.pTX->PcmBuf_64k, pSrcBuf, iInByte1);
         btsco_ReadDataDone_TX(iInByte1);
         btsco_GetReadBuffer_TX(&pSrcBuf, &iInByte2);
		 memcpy(btsco.pTX->PcmBuf_64k + iInByte1, pSrcBuf, MSBC_PCM_FRAME_BYTE-iInByte1);
         btsco_ReadDataDone_TX(MSBC_PCM_FRAME_BYTE-iInByte1);
      }
	  iInSample = MSBC_PCM_FRAME_BYTE >> 1;
	  iOutByte = MSBC_BTSTREAM_FRAME_BYTE;
      index = btsco.pTX->iPacket_w & SCO_TX_PACKET_MASK;
      status = MSBC_ENC_Process(btsco.pTX->pEncHandle, btsco.pTX->PcmBuf_64k, &iInSample, &btsco.pTX->PacketBuf[index][2], &iOutByte); //out 57 bytes
	  btsco.pTX->PacketBuf[index][0 ] = 0x01; //header
	  btsco.pTX->PacketBuf[index][1 ] = btsco_MsbcHeader[index&0x3]; //header
	  btsco.pTX->PacketBuf[index][59] = 0; //header
      btsco.pTX->iPacket_w++;
   }
}

static void btsco_process_RX_MSBC()
{
   kal_int32 iCount=0, index1=0, index2=0, match=0, iInByte=0, iOutSample=0, status=0, iOutByte1=0, iOutByte2=0, dwBtEv3HalfBad=0;
   kal_uint8 *pDstBuf;
   while(1)
   {
      if(btsco_GetFreeSpace_RX() < MSBC_PCM_FRAME_BYTE)
      {
         break; // pcm buffer full
      }
      if(btsco.pRX->iPacket_w - btsco.pRX->iPacket_r < 2 ) //use two block (2*30) each time
      { 
         break; // bitstream not enough
      }
      index1 =  btsco.pRX->iPacket_r    & SCO_RX_PACKET_MASK;
      index2 = (btsco.pRX->iPacket_r+1) & SCO_RX_PACKET_MASK;
	  btsco.pRX->iPacket_r++;
	  kal_prompt_trace(MOD_L1SP, "[MSBC][%d][%d], index1: %d, valid: %d",btsco.pRX->PacketBuf[index1][0],btsco.pRX->PacketBuf[index1][1], index1, btsco.pRX->PacketValid[index1]);
      if( (btsco.pRX->PacketBuf[index1][0] == 0x01) && ((btsco.pRX->PacketBuf[index1][1]&0x0F) == 0x08) )//correct header
      {
         memcpy(btsco.pRX->PcmBuf_8k   , &btsco.pRX->PacketBuf[index1][2], 28);
         memcpy(btsco.pRX->PcmBuf_8k+28, &btsco.pRX->PacketBuf[index2][0], 29); // total 57
         iInByte = MSBC_BTSTREAM_FRAME_BYTE; 
         iOutSample = MSBC_PCM_FRAME_BYTE >> 1;
         status = MSBC_DEC_Process(btsco.pRX->pDecHandle, &btsco.pRX->PcmBuf_8k, &iInByte, (kal_int16*)btsco.pRX->PcmBuf_64k, &iOutSample);
		 kal_prompt_trace(MOD_L1SP, "[MSBC]status: %d,",status);
         btsco.pRX->iPacket_r++;
      }
      else if(btsco.pRX->PacketValid[index1]==1)
      {//wrong header, but packet not lost, sync to next 30 byte block (should only happenes on packetsize 30)
		 status = -1;
      }
	  else
	  {//packet lost at first frame, fail to decode
		 status = -1;
		 btsco.pRX->iPacket_r++;
      }
      if(status==MSBC_BTSTREAM_FRAME_BYTE)
      {
         if(btsco.pRX->PacketValid[index1]==1 && btsco.pRX->PacketValid[index2]==0)
         {
            dwBtEv3HalfBad = 1;
         }
         else
         {
            dwBtEv3HalfBad = 0;
         }
      }
      if(status==MSBC_BTSTREAM_FRAME_BYTE && btsco.pRX->PacketValid[index1]==1 && btsco.pRX->PacketValid[index2]==1)
      {
         g711plc_addtohistory_v2(btsco.pRX->pPLCHandle, (short *)btsco.pRX->PcmBuf_64k, 0);
      }
      else
      {
         g711plc_dofe_v2(btsco.pRX->pPLCHandle, (short *)btsco.pRX->PcmBuf_64k, dwBtEv3HalfBad);
      }
      btsco_GetWriteBuffer_RX(&pDstBuf, &iOutByte1);
      if(iOutByte1 > MSBC_PCM_FRAME_BYTE)
      {
         memcpy(pDstBuf, btsco.pRX->PcmBuf_64k, MSBC_PCM_FRAME_BYTE);
         btsco_WriteDataDone_RX(MSBC_PCM_FRAME_BYTE);
      }
      else
      {
         memcpy(pDstBuf, btsco.pRX->PcmBuf_64k, iOutByte1);
         btsco_WriteDataDone_RX(iOutByte1);
         btsco_GetWriteBuffer_RX(&pDstBuf, &iOutByte2);
         memcpy(pDstBuf, btsco.pRX->PcmBuf_64k + iOutByte1, MSBC_PCM_FRAME_BYTE-iOutByte1);
         btsco_WriteDataDone_RX(MSBC_PCM_FRAME_BYTE-iOutByte1);
      }
   }
}

#endif 

static void btsco_process_loopback()
{
   kal_uint8 *pInBuf, *pOutBuf; 
   kal_uint32 uInLen, uOutLen, i;
   for(i=0;i<4;i++)
   {
      BT_SCO_GetReadBuffer_RX(&pInBuf, &uInLen);  
      BT_SCO_GetWriteBuffer_TX(&pOutBuf, &uOutLen);  
	  kal_prompt_trace(MOD_L1SP, "[CVSD]btsco_process_loopback, uInLen: %d, uOutLen: %d", uInLen, uOutLen);
      uInLen  &= 0xFFFFFFFE;
      uOutLen &= 0xFFFFFFFE;
      if(uInLen < uOutLen)
      {
         uOutLen = uInLen;
      }
      memcpy( pOutBuf, pInBuf, uOutLen );
      BT_SCO_WriteDataDone_TX(uOutLen);  
      BT_SCO_ReadDataDone_RX(uOutLen);  
   }
}

static void btsco_process(void *pData)
{
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_PROCESS, btsco.uState, btsco.pRX, btsco.pTX);
   if(btsco.uState != BT_SCO_STATE_RUNNING)
   {
      return;
   }
#if defined(__MSBC_CODEC_SUPPORT__) 
   if(btsco.fWideBand)
   {
      btsco_process_RX_MSBC();
   }
   else
#endif
   {
      btsco_process_RX_CVSD();
   }
   if(btsco.uMode == BT_SCO_MODE_LOOPBACK_WITH_CODEC)
   {
      btsco_process_loopback();
   }
#if defined(__MSBC_CODEC_SUPPORT__) 
   if(btsco.fWideBand)
   {
      btsco_process_TX_MSBC();
   }
   else
#endif
   {
      btsco_process_TX_CVSD();
   }
}

static void BT_SCO_Start(BT_SCO_MODE uMode, kal_bool fIsWideBand)
{
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_START, btsco.uState, fIsWideBand);
   if(fIsWideBand)
   {
#if defined(__MSBC_CODEC_SUPPORT__) 
      btsco_AllocMemory_MSBC();
#else
      ASSERT(0);
#endif
   }
   else
   {
      btsco_AllocMemory_CVSD();
   }
   btsco.fWideBand = fIsWideBand;
   btsco.uAudId = L1Audio_GetAudioID();
   btsco.uMode = uMode;
   L1Audio_SetEventHandler( btsco.uAudId, btsco_process );
   btsco.uState = BT_SCO_STATE_RUNNING;
#if defined(DELAY_UNMASK_INTERRUPT)
   if(uCVSDGPT == 0)
   {
      uCVSDGPT = DclSGPT_Open( DCL_GPT_CB ,0 );
   }  
#endif
#if !defined(DISABLE_BTCVSD_FOR_CHIPBACK_BOOTUP)   
#if defined(MT6752) && defined(__MD2__)
    // K2 MD2 BT phone call workaround
    {
        kal_uint32 timer_delay = 1;             // Unit: 4.615 ms tick
        kal_uint32 timer_reschedule_time = 1;   // Unit: 4.615 ms tick
		kal_trace( TRACE_GROUP_SCO,L1AUDIO_BTSCO_TIMER, (kal_uint32)btsco_timer, timer_delay, timer_reschedule_time);
        kal_set_timer(btsco_timer, (kal_timer_func_ptr)(BT_SCO_LISR), NULL, timer_delay, timer_reschedule_time);
    }
#else   // defined(MT6752) && defined(__MD2__)
    IRQUnmask(IRQ_BT_CVSD_CODE);
#endif  // defined(MT6752) && defined(__MD2__)
#endif
}

static void BT_SCO_Stop()
{
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_STOP, btsco.uState);
   ASSERT(btsco.uState != BT_SCO_STATE_IDLE);
   btsco.uState = BT_SCO_STATE_ENDING;
   kal_sleep_task(10); //flush zero (22.5*2 msec) 
   btsco.uState = BT_SCO_STATE_IDLE;
#if !defined(DISABLE_BTCVSD_FOR_CHIPBACK_BOOTUP)   
#if defined(MT6752) && defined(__MD2__)
    // K2 MD2 BT phone call workaround
    kal_trace( TRACE_GROUP_SCO,L1AUDIO_BTSCO_CANCEL_TIMER_ID, (kal_uint32)btsco_timer);
    kal_cancel_timer(btsco_timer);
    {   // Clear flag
//        kal_uint32 bus_state = *BT_SCO_BUS_STATE_REG;
//        bus_state = (bus_state & ~BT_SCO_BUS_STATE_MASK) | BT_SCO_BUS_STATE_OFF;
//        *BT_SCO_BUS_STATE_REG = bus_state;
//        btsco.bus_state = bus_state;
//        kal_prompt_trace(MOD_L1SP, "[K2_MD2] Clear flag, bus state = %x", bus_state);
    }
#else   // defined(MT6752) && defined(__MD2__)
   IRQMask(IRQ_BT_CVSD_CODE);
#endif  // defined(MT6752) && defined(__MD2__)
#endif
   L1Audio_FreeAudioID( btsco.uAudId );
   memset(&btsco, 0, sizeof(btsco));
}

void BT_SCO_LISR(void)
{
#if !defined(DISABLE_BTCVSD_FOR_CHIPBACK_BOOTUP)   

#if defined(MT6752) && defined(__MD2__)
    // K2 MD2 BT phone call workaround
    {
//        kal_uint32 bus_state = *BT_SCO_BUS_STATE_REG;
        
//        btsco.bus_state = bus_state;
        
//        if ((bus_state & BT_SCO_BUS_STATE_MASK) == BT_SCO_BUS_STATE_ON)
//        {
//            kal_prompt_trace(MOD_L1SP, "[K2_MD2] Bus on, bus state reg = %x", bus_state);
//        }
//        else
//        {
//            kal_prompt_trace(MOD_L1SP, "[K2_MD2] Bus off, bus state reg = %x", bus_state);
//            //return;
//        }
    }
#else   // defined(MT6752) && defined(__MD2__)
   IRQMask(IRQ_BT_CVSD_CODE);
#endif  // defined(MT6752) && defined(__MD2__)

   //[k2] btsco_hisr context run in HISR 
   btsco_hisr(NULL);   
   //L1Audio_TrigD2CHisr(BT_CVSD_HISR_MAGIC_NO);
   
#endif
}

void BT_SCO_Init()
{
#if !defined(DISABLE_BTCVSD_FOR_CHIPBACK_BOOTUP)   
#if defined(MT6752) && defined(__MD2__)
    // K2 MD2 BT phone call workaround
    btsco_timer = kal_create_timer("BTCODEC");
    kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_CREATE_TIMER_ID, (kal_uint32)btsco_timer);	
#else   // defined(MT6752) && defined(__MD2__)
   IRQMask(IRQ_BT_CVSD_CODE);
   // [k2] btsco_hisr context run in HISR 
   //L1Audio_HookHisrHandler( BT_CVSD_HISR_MAGIC_NO, btsco_hisr, NULL );
   IRQ_Register_LISR(IRQ_BT_CVSD_CODE, BT_SCO_LISR, "CVSD ISR");
   IRQSensitivity(IRQ_BT_CVSD_CODE, LEVEL_SENSITIVE);
   IRQMask(IRQ_BT_CVSD_CODE);
#endif  // defined(MT6752) && defined(__MD2__)
#endif
}

static void BT_SCO_Speech_TX_HISR()
{
   kal_uint8 *pDst, *pSrc;
   kal_uint32 uOutByte, uFreeSpace, uRemainByte, uSpeechFrameSize;
   if(btsco.uState != BT_SCO_STATE_RUNNING)
   {
      return;
   }
#if defined(__MSBC_CODEC_SUPPORT__) 
   if(btsco.fWideBand)
   {
      uSpeechFrameSize = WB_SPEECH_FRAME_SIZE;
   }
   else
#endif
   {
      uSpeechFrameSize = NB_SPEECH_FRAME_SIZE;
   }
   BT_SCO_GetWriteBuffer_TX(&pDst, &uOutByte);
   uFreeSpace = BT_SCO_GetFreeSpace_TX();
   kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_TX_DATA, uOutByte, uFreeSpace);
   uOutByte = uOutByte & 0xFFFFFFFE;
   uFreeSpace = uFreeSpace & 0xFFFFFFFE;
   if(uOutByte >= uSpeechFrameSize)
   {
      pSrc = pDst;
   }
   else if(uFreeSpace >= uSpeechFrameSize)
   {
      pSrc = btsco.pSpeechData;
   }
   else
   { 
      kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_TX_OF, uFreeSpace);
      //overflow
      return;
   }
   DACA_GetFromSD((kal_uint16*)pSrc);
   if(uOutByte >= uSpeechFrameSize)
   {
      BT_SCO_WriteDataDone_TX(uSpeechFrameSize);
   }
   else
   {//put to temp buffer first
      memcpy(pDst, pSrc, uOutByte);
      BT_SCO_WriteDataDone_TX(uOutByte);
      pSrc += uOutByte;
      uRemainByte = uSpeechFrameSize - uOutByte;
      BT_SCO_GetWriteBuffer_TX(&pDst, &uOutByte);
      uOutByte = uOutByte & 0xFFFFFFFE;
      ASSERT(uOutByte>=uRemainByte);
      memcpy(pDst, pSrc, uRemainByte);
      BT_SCO_WriteDataDone_TX(uRemainByte); 
   }

}

static void BT_SCO_Speech_RX_HISR()
{
   kal_uint8 *pSrc, *pDst;
   kal_uint32 uInByte, uDataCount, uRemainByte, uDirectCopy=0, uSpeechFrameSize=0;
   if(btsco.uState != BT_SCO_STATE_RUNNING)
   {
      return;
   }
#if defined(__MSBC_CODEC_SUPPORT__) 
  if(btsco.fWideBand)
   {
      uSpeechFrameSize = WB_SPEECH_FRAME_SIZE;
   }
   else
#endif
   {
      uSpeechFrameSize = NB_SPEECH_FRAME_SIZE;
   }
   BT_SCO_GetReadBuffer_RX(&pSrc, &uInByte);
   uDataCount = BT_SCO_GetDataCount_RX();
   kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_RX_DATA, uInByte, uDataCount);
   uInByte = uInByte & 0xFFFFFFFE;
   uDataCount = uDataCount & 0xFFFFFFFE;
   if(uInByte >= uSpeechFrameSize)
   {
      uDirectCopy = 1;
   }
   else if(uDataCount >= uSpeechFrameSize)
   {
      pDst = btsco.pSpeechData;
      memcpy(pDst, pSrc, uInByte);
      pDst += uInByte;
      uRemainByte = uSpeechFrameSize - uInByte;
      BT_SCO_ReadDataDone_RX(uInByte);
      BT_SCO_GetReadBuffer_RX(&pSrc, &uInByte);
      ASSERT(uInByte>=uRemainByte);
      memcpy(pDst, pSrc, uRemainByte);
      BT_SCO_ReadDataDone_RX(uRemainByte);
      pSrc = btsco.pSpeechData;
   }
   else
   { 
      kal_dev_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_AP_SPEECH_RX_UF, uDataCount);
      return;
   }
   DACA_PutToSE((const kal_uint16*)pSrc);
   if(uDirectCopy)
   {
      BT_SCO_ReadDataDone_RX(uSpeechFrameSize);
   }
}

void BT_SCO_SPEECH_ON(kal_bool fWideBand)
{
   DACA_APP_TYPE uType = DACA_APP_TYPE_ACTIVE_UL_DL_NB;
#if !defined(DISABLE_BTCVSD_FOR_CHIPBACK_BOOTUP)   
   kal_prompt_trace(MOD_L1SP, "[CVSD]BT_SCO_SPEECH_ON, uState: %d, fWideBand = %d", btsco.uState, fWideBand);
   //kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_SP_ON, btsco.uState);
   ASSERT(btsco.uState == BT_SCO_STATE_IDLE);
#if defined(__MSBC_CODEC_SUPPORT__) 
   if(fWideBand)
   {
      uType = DACA_APP_TYPE_ACTIVE_UL_DL_WB;
   }
#endif
   DACA_Start(BT_SCO_Speech_TX_HISR, BT_SCO_Speech_RX_HISR, uType);
   BT_SCO_Start( BT_SCO_MODE_SPEECH, fWideBand);
#endif
}

void BT_SCO_SPEECH_OFF()
{
   DACA_APP_TYPE uType = DACA_APP_TYPE_ACTIVE_UL_DL_NB;
#if !defined(DISABLE_BTCVSD_FOR_CHIPBACK_BOOTUP)   
#if defined(__MSBC_CODEC_SUPPORT__) 
   if(btsco.fWideBand)
   {
      uType = DACA_APP_TYPE_ACTIVE_UL_DL_WB;
   }
#endif
   kal_prompt_trace(MOD_L1SP, "[CVSD]BT_SCO_SPEECH_OFF, uState: %d", btsco.uState);
   //kal_trace( TRACE_GROUP_SCO, L1AUDIO_BTSCO_SP_OFF, btsco.uState);
   ASSERT(btsco.uState != BT_SCO_STATE_IDLE);
   BT_SCO_Stop();
   DACA_Stop(uType);
#endif
}

kal_bool BT_SCO_IS_SPEECH_ON()
{
   if(btsco.uState == BT_SCO_STATE_IDLE)
   {
      return KAL_FALSE;
   }
   return KAL_TRUE;
}

void BT_SCO_Loopback_ON(kal_bool fDisableCodec, kal_bool fWideBand)
{
   kal_prompt_trace(MOD_L1SP, "[CVSD]BT_SCO_Loopback_ON, fDisableCodec: %d, uState: %d", fDisableCodec, btsco.uState);
   ASSERT(btsco.uState == BT_SCO_STATE_IDLE);
   if(fDisableCodec)
   {
      BT_SCO_Start( BT_SCO_MODE_LOOPBACK_WITHOUT_CODEC, fWideBand );
   }
   else
   {
      BT_SCO_Start( BT_SCO_MODE_LOOPBACK_WITH_CODEC, fWideBand );
   }
}

void BT_SCO_Loopback_OFF()
{
   kal_prompt_trace(MOD_L1SP, "[CVSD]BT_SCO_Loopback_OFF, uState: %d", btsco.uState);
   ASSERT(btsco.uState != BT_SCO_STATE_IDLE);
   BT_SCO_Stop();
}

#endif //__CVSD_CODEC_SUPPORT__

