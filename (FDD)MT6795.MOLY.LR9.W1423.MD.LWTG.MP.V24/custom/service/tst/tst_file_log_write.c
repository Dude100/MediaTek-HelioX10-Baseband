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
 * tst_file_log_write.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements the logging functions for TST
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __TST_WRITE_TO_FILE__  //this function is only avaialable when __TST_WRITE_TO_FILE__ is enabled

#include "kal_public_api.h" //MSBB change #include "kal_release.h"      /* Basic data type */

#include "GV.h"
#include "tst_def.h"
#include "tst_ext.h"          /* Dump info*/
#include "intrCtrl.h"
#include "tst_file_def.h"
//#include "tst_internal_def.h"

//#pragma arm section code= "PRIMARY_ROCODE" rwdata = "PRIMARY_RW" , rodata = "PRIMARY_RODATA" , zidata = "PRIMARY_ZI" 

/*************************************************************************
* Defs
 *************************************************************************/
#define ROLL_BACK_ERROR_MSG_BYTES 8 // the bytes required for rollback actions
#define  ISR_FRAME_MAGIC  0xA5
#define BE_A_FRAME_HEADER_PACKET 1
#define NOT_A_FRAME_HEADER_PACKET 0

/*************************************************************************
* Global variable declaration
 *************************************************************************/
kal_uint32 frameHeaderStartPos; //the starting position of the frame header --> for rollback action

/*************************************************************************
* Extern variable declaration
 *************************************************************************/
#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST) 
  extern kal_uint8* lga_buf_ptr;
  extern kal_uint32 lga_buf_len;
  extern kal_bool b_lga_log_unsent;
#endif  //#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST) 

/*************************************************************************
* Function declaration
 *************************************************************************/
extern void tst_lga_activate_hisr(unsigned int id);

/*************************************************************************
* FUNCTION
*  trc_WriteToFile 
*
* DESCRIPTION
*  This function copys the l1 trace to write2file buffer.
*  If the buffer is full, write them to physic disks
*
* PARAMETERS
*  kal_uint8* buf : buf to be sent
*  kal_uint32 len : the length of the buf
*  kal_uint8 isFrameHeaderPacket: Is it the frist packet (frame header) of a frame ?
*
* RETURNS
*
* GLOBALS AFFECTED
*  frameHeaderStartPos: the starting position of the frame header
*
*************************************************************************/
__tstfileFunc void trc_WriteToFile(kal_uint8* buffer, kal_uint32 size, kal_uint8 isFrameHeaderPacket)
{
  #define TRC_FILE_DROP_IND_LEN (6)
  static kal_bool trc_file_last_log_drop = KAL_FALSE;
  kal_uint32 required_size = (size+ROLL_BACK_ERROR_MSG_BYTES);

  ASSERT(tst_dump_info.nL1BufferWritePtr < TST_L1_BUFFER_SIZE_FOR_WRITE_FILE);
  
  if (trc_file_last_log_drop)
    required_size += TRC_FILE_DROP_IND_LEN;

  if (tst_dump_info.nL1BufferVancancy < required_size ){
    //roll back  the previous stord information

    //we need to rollback if it is not the frame header packet
    if (!isFrameHeaderPacket){
        //ROLL-BACK 
        if (tst_dump_info.nL1BufferWritePtr >= frameHeaderStartPos)
          tst_dump_info.nL1BufferVancancy += (tst_dump_info.nL1BufferWritePtr-frameHeaderStartPos);
        else
          tst_dump_info.nL1BufferVancancy += (TST_L1_BUFFER_SIZE_FOR_WRITE_FILE+tst_dump_info.nL1BufferWritePtr-frameHeaderStartPos);
          
        tst_dump_info.nL1BufferWritePtr = frameHeaderStartPos;
    }
    
    trc_file_last_log_drop = KAL_TRUE;
    return;
  }

  //keep the starting position of the frame header for possible rollback actions
  if (isFrameHeaderPacket == BE_A_FRAME_HEADER_PACKET){  
    //frame header -->keep the position
    frameHeaderStartPos = tst_dump_info.nL1BufferWritePtr;
  }
  else
  {
    if (trc_file_last_log_drop)
    { //Wait for the next header starting
      return;  
    }
  }
  
  //Fill the lost info
  if (trc_file_last_log_drop)
  {
    // the previous msg doesn't match the error msg pattern
    // Need to fill the error msg
    kal_uint8 trc_lost_buf[TRC_FILE_DROP_IND_LEN] = {ISR_FRAME_MAGIC, 2, 0, 0xFC, 0, 0x5B};
    kal_uint32 sent_len=0;
    
    tst_dump_info.nL1BufferVancancy -= TRC_FILE_DROP_IND_LEN;
    
    if (tst_dump_info.nL1BufferWritePtr+TRC_FILE_DROP_IND_LEN >= TST_L1_BUFFER_SIZE_FOR_WRITE_FILE)
    {
      sent_len = TST_L1_BUFFER_SIZE_FOR_WRITE_FILE-tst_dump_info.nL1BufferWritePtr;
      kal_mem_cpy(tst_dump_info.L1Buffer + tst_dump_info.nL1BufferWritePtr,
        trc_lost_buf,
        sent_len);
      tst_dump_info.nL1BufferWritePtr = 0;
    }
    
    kal_mem_cpy(tst_dump_info.L1Buffer + tst_dump_info.nL1BufferWritePtr,
        &trc_lost_buf[sent_len],
        TRC_FILE_DROP_IND_LEN-sent_len);
    tst_dump_info.nL1BufferWritePtr += (TRC_FILE_DROP_IND_LEN-sent_len);
        
    
    trc_file_last_log_drop = KAL_FALSE;  
  }
    
  tst_dump_info.nL1BufferVancancy -= size;
  if (tst_dump_info.nL1BufferWritePtr + size >=  TST_L1_BUFFER_SIZE_FOR_WRITE_FILE)
  {
    kal_uint32 nHalfSize = TST_L1_BUFFER_SIZE_FOR_WRITE_FILE - tst_dump_info.nL1BufferWritePtr;
    //write the first part
    kal_mem_cpy(tst_dump_info.L1Buffer + tst_dump_info.nL1BufferWritePtr,
                buffer,
                nHalfSize);
    size -= nHalfSize; 
    buffer += nHalfSize;           
    tst_dump_info.nL1BufferWritePtr = 0;
  }
  if (size > 0)
  {
    kal_mem_cpy(tst_dump_info.L1Buffer + tst_dump_info.nL1BufferWritePtr,
                buffer,
                size);
    tst_dump_info.nL1BufferWritePtr += size;
  }
}

__tstfileFunc kal_bool tst_file_check_lga_data_saved(void)
{
  #if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST) 
    return (kal_bool)(!b_lga_log_unsent);
  #else //#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST) 
    return KAL_TRUE;
  #endif  //#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST) 
}

__tstfileFunc void tst_file_write_logacc_logs(void)
{
  #if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST) 
    kal_uint32 _savedMask = 0;  
        
    tst_file_dump_log_to_file(lga_buf_ptr, lga_buf_len, 1);
      
    _savedMask = SaveAndSetIRQMask();  
    b_lga_log_unsent = KAL_FALSE;
    RestoreIRQMask(_savedMask);
    
    //Activate lga hisr
    tst_lga_activate_hisr(0);
  #endif  //#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST) 
}

#else

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "tst_file_def.h"

//#pragma arm section code= "PRIMARY_ROCODE" rwdata = "PRIMARY_RW" , rodata = "PRIMARY_RODATA" , zidata = "PRIMARY_ZI" 
__tstfileFunc void trc_WriteToFile(kal_uint8* buffer, kal_uint32 size, kal_uint8 isFrameHeaderPacket){}
__tstfileFunc void tst_file_write_logacc_logs(void){}
__tstfileFunc kal_bool tst_file_check_lga_data_saved(void){return KAL_TRUE;}
#endif  //#ifdef __TST_WRITE_TO_FILE__
