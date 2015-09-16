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
 *   PCMRB.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   PCMRB interface and driver, providing pcm ring buffer utility
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
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
*                     C O M P I L E R   F L A G S
******************************************************************************
*/

/*****************************************************************************
*                E X T E R N A L   R E F E R E N C E S
******************************************************************************
*/
#include "kal_public_api.h"
//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "string.h"

#include "common_def.h"
#include "pcmrb.h"
/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/

/*****************************************************************************
*                         D A T A   T Y P E S
******************************************************************************
*/

/*****************************************************************************
*                        P U B L I C   D A T A
******************************************************************************
*/

/*****************************************************************************
*                       P R I V A T E   D A T A
******************************************************************************
*/

/*****************************************************************************
*                             M A C R O S
******************************************************************************
*/

/*****************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/

/*****************************************************************************
*                          F U N C T I O N S
******************************************************************************
*/

__inline int16 pcm_add( int32 x, int32 y )
{
#if defined(__TARGET_FEATURE_DSPMUL)
   int32 xs, ys, rs;
   __asm {
      mov xs, x, lsl #16;
      mov ys, y, lsl #16;
      qadd rs, xs, ys;
   }
   return (int16)(rs >> 16);	
#else	
   x = x + y;
   if( x>32767 )
      x = 32767;
   else if( x< -32768 )
      x = -32768;

   return (int16)x;	
#endif
}

void pcm_mix_n( int16 *dest, int16 *src, int32 n )
{
   do {
      int32 x = *dest;
      int32 y = *src++;
      *dest++ = pcm_add( x, y );
   } while( --n>0 );
}

/*
 * Description
 * ---------
 *   The function initializes the ring buffer instance.
 *
 * Syntax
 * ---------
 *   bool PCMRB_Init( PCMRB *rb, int16 *buffer, int32 buffer_size )
 *
 * where
 *   rb   The ring buffer instance
 *   buffer        Address of the memory allocated for the ring buffer
 *   buffer_size   Size of the memory allocated for the ring buffer
 *
 * Return Value
 * ---------
 *   true
 *   false
 */
bool PCMRB_Init( PCMRB *rb, int16 *buffer, int32 buffer_size )
{
   ASSERT( rb!=NULL );
   
   memset( buffer, 0, buffer_size*sizeof(int16) );
   rb->buffer = buffer;
   rb->size = buffer_size;
   rb->read = 0;
   rb->write = 0;

   return true;
}

/*
 * Description
 * ---------
 *   The function returns the available free space of the ring buffer instance.
 *
 * Syntax
 * ---------
 *   int32 PCMRB_GetFreeSpace( PCMRB *rb )
 *
 * where
 *   rb   The ring buffer instance
 *
 * Return Value
 * ---------
 *   the free space in words
 */
int32 PCMRB_GetFreeSpace( PCMRB *rb )
{
   int32 count;
   
   ASSERT( rb!=NULL );
   
   count = rb->read - rb->write - 1;
   if( 0>count )
      count += rb->size;
   return count;
}

/*
 * Description
 * ---------
 *   The function returns available data count of the ring buffer instance
 *
 * Syntax
 * ---------
 *   int32 PCMRB_GetDataCount( PCMRB *rb )
 *
 * where
 *   rb   The ring buffer instance
 *
 * Return Value
 * ---------
 *   the data count in words
 */
int32 PCMRB_GetDataCount( PCMRB *rb )
{
   int32 count;
   
   ASSERT( rb!=NULL );
   
   count = rb->write - rb->read;
   if( 0>count )
      count += rb->size;
   return count;
}

/*
 * Description
 * ---------
 *   The function copies data from a linear array to a ring buffer instance.
 *   The free space of the ring buffer instance shall be enough, or assertion will happen
 *
 * Syntax
 * ---------
 *   void PCMRB_Write( PCMRB *dest_rb, int16 *src_buffer, int32 size )
 *
 * where
 *   dest_rb   The ring buffer instance
 *   src_buffer        Address of the linear array
 *   size   Size of copy
 *
 * Return Value
 * ---------
 *   none
 */
void PCMRB_Write( PCMRB *dest_rb, int16 *src_buffer, int32 size )
{
   int16 *write_ptr;
   int32 write_cnt;
///   kal_prompt_trace(MOD_L1SP, "PCMRB_Write size=%d",size);
   ASSERT( dest_rb!=NULL );
   ASSERT( PCMRB_GetFreeSpace( dest_rb )>=size );

   PCMRB_GetWriteBlock( dest_rb, &write_ptr, &write_cnt );
   if( write_cnt>size ) write_cnt = size;

   if( src_buffer == (int16 *)NULL ){ 
   	  memset( write_ptr, 0, write_cnt*sizeof(int16) );   	
///   	  kal_prompt_trace(MOD_L1SP, "PCMRB_Write Null");
   }else{
   	  memcpy( write_ptr, src_buffer, write_cnt*sizeof(int16) );
///   	  kal_prompt_trace(MOD_L1SP, "PCMRB_Write %x %x %x %x", write_ptr, *(src_buffer+0),*(src_buffer+1),*(src_buffer+2));
   }
   
   PCMRB_ShiftWritePointer( dest_rb, write_cnt );
   size -= write_cnt;

   if( size>0 )
   {
      if( src_buffer != (int16 *)NULL ) src_buffer += write_cnt;

      PCMRB_GetWriteBlock( dest_rb, &write_ptr, &write_cnt );
      if( write_cnt>size ) write_cnt = size;

      if( src_buffer == (int16 *)NULL ) memset( write_ptr, 0, write_cnt*sizeof(int16) );
      else memcpy( write_ptr, src_buffer, write_cnt*sizeof(int16) );

      PCMRB_ShiftWritePointer( dest_rb, write_cnt );
   }   
}

//fsju
void PCMRB_Write_from_DSP( PCMRB *dest_rb, volatile uint16 *src_buffer, int32 size )
{
   int16 *write_ptr;
   int32 write_cnt;
   int32 i;
///   kal_prompt_trace(MOD_L1SP, "PCMRB_Write size=%d",size);
   ASSERT( dest_rb!=NULL );
   ASSERT( PCMRB_GetFreeSpace( dest_rb )>=size );

   PCMRB_GetWriteBlock( dest_rb, &write_ptr, &write_cnt );
   if( write_cnt>size ) write_cnt = size;

   if( src_buffer == (volatile uint16 *)NULL ){ 
   	  memset( write_ptr, 0, write_cnt*sizeof(int16) );   	
///   	  kal_prompt_trace(MOD_L1SP, "PCMRB_Write Null");
   }else{
   	  //memcpy( write_ptr, src_buffer, write_cnt*sizeof(int16) );
      for(i=0; i<write_cnt; i++)
      {
         write_ptr[i] = src_buffer[i];
      }
///   	  kal_prompt_trace(MOD_L1SP, "PCMRB_Write %x %x %x %x", write_ptr, *(src_buffer+0),*(src_buffer+1),*(src_buffer+2));
   }
   
   PCMRB_ShiftWritePointer( dest_rb, write_cnt );
   size -= write_cnt;

   if( size>0 )
   {
      if( src_buffer != (volatile uint16 *)NULL ) src_buffer += write_cnt;

      PCMRB_GetWriteBlock( dest_rb, &write_ptr, &write_cnt );
      if( write_cnt>size ) write_cnt = size;

      if( src_buffer == (volatile uint16 *)NULL )
      {
         memset( write_ptr, 0, write_cnt*sizeof(int16) );
      }
      else
      {
         //memcpy( write_ptr, src_buffer, write_cnt*sizeof(int16) );
         for(i=0; i<write_cnt; i++)
         {
            write_ptr[i] = src_buffer[i];
         }
      }

      PCMRB_ShiftWritePointer( dest_rb, write_cnt );
   }   
}

//fsju, for test, should remove
void PCMRB_Write2( PCMRB *dest_rb, int16 *src_buffer, int32 size )
{
   int16 *write_ptr;
   int32 write_cnt;
   int32 i;
   static short test_val = 0;
///   kal_prompt_trace(MOD_L1SP, "PCMRB_Write size=%d",size);
   ASSERT( dest_rb!=NULL );
   ASSERT( PCMRB_GetFreeSpace( dest_rb )>=size );

   PCMRB_GetWriteBlock( dest_rb, &write_ptr, &write_cnt );
   if( write_cnt>size ) write_cnt = size;

   if( src_buffer == (int16 *)NULL ){ 
   	  memset( write_ptr, 0, write_cnt*sizeof(int16) );   	
///   	  kal_prompt_trace(MOD_L1SP, "PCMRB_Write Null");
   }else{
   	  //memcpy( write_ptr, src_buffer, write_cnt*sizeof(int16) );
   	  for(i=0; i<write_cnt; i++)
   	  {
   	  	write_ptr[i] = test_val;
		test_val++;
   	  }
///   	  kal_prompt_trace(MOD_L1SP, "PCMRB_Write %x %x %x %x", write_ptr, *(src_buffer+0),*(src_buffer+1),*(src_buffer+2));
   }
   
   PCMRB_ShiftWritePointer( dest_rb, write_cnt );
   size -= write_cnt;

   if( size>0 )
   {
      if( src_buffer != (int16 *)NULL ) src_buffer += write_cnt;

      PCMRB_GetWriteBlock( dest_rb, &write_ptr, &write_cnt );
      if( write_cnt>size ) write_cnt = size;

      if( src_buffer == (int16 *)NULL )
      {
         memset( write_ptr, 0, write_cnt*sizeof(int16) );
      }
      else
      {
         //memcpy( write_ptr, src_buffer, write_cnt*sizeof(int16) );
		 for(i=0; i<write_cnt; i++)
		 {
		   write_ptr[i] = test_val;
		   test_val++;
		 }
      }

      PCMRB_ShiftWritePointer( dest_rb, write_cnt );
   }   
}
//fsju add end

/*
 * Description
 * ---------
 *   The function copies data from a ring buffer instance to a linear array
 *   The data count of the ring buffer instance shall be enough, or assertion will happen
 *
 * Syntax
 * ---------
 *   void PCMRB_Read( PCMRB *src_rb, int16 *dest_buffer, int32 size )
 *
 * where
 *   src_rb   The ring buffer instance
 *   dest_buffer        Address of the linear array
 *   size   Size of copy
 *
 * Return Value
 * ---------
 *   none
 */
void PCMRB_Read( PCMRB *src_rb, int16 *dest_buffer, int32 size )
{
   int16 *read_ptr;
   int32 read_cnt;
///   kal_prompt_trace(MOD_L1SP, "PCMRB_Read size=%d",size);
   ASSERT( src_rb!=NULL );
   ASSERT( PCMRB_GetDataCount( src_rb )>=size );

   PCMRB_GetReadBlock( src_rb, &read_ptr, &read_cnt );
   if( read_cnt>size ) read_cnt = size;
   memcpy( dest_buffer, read_ptr, read_cnt*sizeof(int16) );
   PCMRB_ShiftReadPointer( src_rb, read_cnt );
   size -= read_cnt;

   if( size>0 )
   {
      dest_buffer += read_cnt;
      PCMRB_GetReadBlock( src_rb, &read_ptr, &read_cnt );
      if( read_cnt>size ) read_cnt = size;
      memcpy( dest_buffer, read_ptr, read_cnt*sizeof(int16) );
      PCMRB_ShiftReadPointer( src_rb, read_cnt );
   }
}

//fsju
void PCMRB_Read_to_DSP( PCMRB *src_rb, volatile uint16 *dest_buffer, int32 size )
{
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
#else //#if 0
   int16 *read_ptr;
   int32 read_cnt;
   int32 i;
   //volatile uint16* ptr_dest_buffer = dest_buffer;
///   kal_prompt_trace(MOD_L1SP, "PCMRB_Read size=%d",size);
   ASSERT( src_rb!=NULL );
   ASSERT( PCMRB_GetDataCount( src_rb )>=size );

   PCMRB_GetReadBlock( src_rb, &read_ptr, &read_cnt );
   if( read_cnt>size ) read_cnt = size;
   //memcpy( dest_buffer, read_ptr, read_cnt*sizeof(int16) );
   for(i=0; i<read_cnt; i++)
   {
      dest_buffer[i] = read_ptr[i];
   }
   PCMRB_ShiftReadPointer( src_rb, read_cnt );
   size -= read_cnt;

   if( size>0 )
   {
	  dest_buffer += read_cnt;
	  PCMRB_GetReadBlock( src_rb, &read_ptr, &read_cnt );
	  if( read_cnt>size ) read_cnt = size;
	  //memcpy( dest_buffer, read_ptr, read_cnt*sizeof(int16) );
	  for(i=0; i<read_cnt; i++)
	  {
		 dest_buffer[i] = read_ptr[i];
	  }
	  PCMRB_ShiftReadPointer( src_rb, read_cnt );
   }
#endif //#if 0
}


void PCMRB_Read_to_DSP_Padding( PCMRB *src_rb, volatile uint16 *dest_buffer, int32 size )
{
   int16 *read_ptr;
   int32 read_cnt;
   int32 i;
   //32k 20ms
   uint32 buffered_data[640/sizeof(uint32)];
   int32 read_cnt_total;

   ASSERT( src_rb!=NULL );
   //ASSERT( PCMRB_GetDataCount( src_rb )>=size );

   PCMRB_GetReadBlock( src_rb, &read_ptr, &read_cnt );
   //kal_prompt_trace(MOD_L1SP, "PCMRB_Read_to_DSP_Padding1: read_cnt=%d, size=%d", read_cnt, size);
   if( read_cnt>size ) read_cnt = size;
   //kal_prompt_trace(MOD_L1SP, "PCMRB_Read_to_DSP_Padding1: read_cnt=%d, size=%d", read_cnt, size);
   for(i=0; i<read_cnt; i++)
   {
      dest_buffer[i] = read_ptr[i];
      buffered_data[i] = read_ptr[i];
   }
   //kal_prompt_trace(MOD_L1SP, "PCMRB_Read_to_DSP_Padding1: src_rb->read=%d, src_rb->write=%d", src_rb->read, src_rb->write);
   PCMRB_ShiftReadPointer( src_rb, read_cnt );
   //kal_prompt_trace(MOD_L1SP, "PCMRB_Read_to_DSP_Padding1: src_rb->read=%d, src_rb->write=%d", src_rb->read, src_rb->write);
   size -= read_cnt;
   dest_buffer += read_cnt;
   read_cnt_total = read_cnt;

   if( size>0 )
   {
	  PCMRB_GetReadBlock( src_rb, &read_ptr, &read_cnt );
      //kal_prompt_trace(MOD_L1SP, "PCMRB_Read_to_DSP_Padding2: read_cnt=%d, size=%d", read_cnt, size);
	  if( read_cnt>size ) read_cnt = size;
      //kal_prompt_trace(MOD_L1SP, "PCMRB_Read_to_DSP_Padding2: read_cnt=%d, size=%d", read_cnt, size);
	  for(i=0; i<read_cnt; i++)
	  {
         dest_buffer[i] = read_ptr[i];
		 buffered_data[i+read_cnt_total] = read_ptr[i];
	  }
      //kal_prompt_trace(MOD_L1SP, "PCMRB_Read_to_DSP_Padding2: src_rb->read=%d, src_rb->write=%d", src_rb->read, src_rb->write);
	  PCMRB_ShiftReadPointer( src_rb, read_cnt );
      //kal_prompt_trace(MOD_L1SP, "PCMRB_Read_to_DSP_Padding2: src_rb->read=%d, src_rb->write=%d", src_rb->read, src_rb->write);
      size -= read_cnt;
      dest_buffer += read_cnt;
      read_cnt_total += read_cnt;
   }

   //padding
   while(size > 0)
   {
      read_cnt = read_cnt_total;
      //kal_prompt_trace(MOD_L1SP, "PCMRB_Read_to_DSP_Padding3: read_cnt=%d, size=%d", read_cnt, size);
      if(read_cnt > size)
      {
         read_cnt = size;
      }
      for(i=0; i<read_cnt; i++)
      {
         dest_buffer[i] = buffered_data[i];
      }
      size -= read_cnt;
      dest_buffer += read_cnt;
   }
}


void PCMRB_ShiftReadPointer2( PCMRB *src_rb, int32 size )
{
   int16 *read_ptr;
   int32 read_cnt;
   
   ASSERT( src_rb!=NULL );
   ASSERT( PCMRB_GetDataCount( src_rb )>=size );

   PCMRB_GetReadBlock( src_rb, &read_ptr, &read_cnt );
   if( read_cnt>size ) read_cnt = size;
   //memcpy( dest_buffer, read_ptr, read_cnt*sizeof(int16) );
   PCMRB_ShiftReadPointer( src_rb, read_cnt );
   size -= read_cnt;

   if( size>0 )
   {
      //dest_buffer += read_cnt;
      PCMRB_GetReadBlock( src_rb, &read_ptr, &read_cnt );
      if( read_cnt>size ) read_cnt = size;
     // memcpy( dest_buffer, read_ptr, read_cnt*sizeof(int16) );
      PCMRB_ShiftReadPointer( src_rb, read_cnt );
   }
}
/*
 * Description
 * ---------
 *   The function returns the linear write block and its size of a ring buffer instance
 *
 * Syntax
 * ---------
 *   void PCMRB_GetWriteBlock( PCMRB *dest_rb, int16 **write_ptr, int32 *write_cnt )
 *
 * where
 *   dest_rb   The ring buffer instance
 *   write_ptr        Address of the memory to put the address of the linear write block
 *   write_cnt   Address of the memory to put the size of the linear write block
 *
 * Return Value
 * ---------
 *   none
 */
void PCMRB_GetWriteBlock( PCMRB *dest_rb, int16 **write_ptr, int32 *write_cnt )
{
   int32 cnt;

   ASSERT( (dest_rb!=NULL) && (write_ptr!=NULL) && (write_cnt!=NULL) );

   if( dest_rb->read>dest_rb->write )
      cnt = dest_rb->read - dest_rb->write - 1;
   else if( dest_rb->read==0 )
      cnt = dest_rb->size - dest_rb->write - 1;
   else
      cnt = dest_rb->size - dest_rb->write;

   *write_cnt = cnt;
   *write_ptr = &dest_rb->buffer[dest_rb->write];
}

/*
 * Description
 * ---------
 *   The function returns the linear read block and its size of a ring buffer instance
 *
 * Syntax
 * ---------
 *   void PCMRB_GetReadBlock( PCMRB *src_rb, int16 **read_ptr, int32 *read_cnt )
 *
 * where
 *   src_rb   The ring buffer instance
 *   read_ptr        Address of the memory to put the address of the linear read block
 *   read_cnt   Address of the memory to put the size of the linear read block
 *
 * Return Value
 * ---------
 *   none
 */
void PCMRB_GetReadBlock( PCMRB *src_rb, int16 **read_ptr, int32 *read_cnt )
{
   int32 cnt;

   ASSERT( (src_rb!=NULL) && (read_ptr!=NULL) && (read_cnt!=NULL) );

   if( src_rb->write == src_rb->read )
      cnt = 0;
   else if( src_rb->write>src_rb->read )
      cnt = src_rb->write - src_rb->read;
   else
      cnt = src_rb->size - src_rb->read;

   *read_cnt = cnt;
   *read_ptr = &src_rb->buffer[src_rb->read]; 
}


/*
 * Description
 * ---------
 *   The function shifts the write pointer of a ring buffer instance in circular way
 *   Use this with PCMRB_GetWriteBlock
 *
 * Syntax
 * ---------
 *   void PCMRB_ShiftWritePointer( PCMRB *rb, int32 shamt )
 *
 * where
 *   rb   The ring buffer instance
 *   shamt        shift amount
 *
 * Return Value
 * ---------
 *   none
 */
void PCMRB_ShiftWritePointer( PCMRB *rb, int32 shamt )
{
   ASSERT( rb!=NULL );

   rb->write += shamt;
   if( rb->write>=rb->size )
      rb->write -= rb->size;
}

/*
 * Description
 * ---------
 *   The function shifts the read pointer of a ring buffer instance in circular way
 *   Use this with PCMRB_GetReadBlock
 *
 * Syntax
 * ---------
 *   void PCMRB_ShiftReadPointer( PCMRB *rb, int32 shamt )
 *
 * where
 *   rb   The ring buffer instance
 *   shamt        shift amount
 *
 * Return Value
 * ---------
 *   none
 */
void PCMRB_ShiftReadPointer( PCMRB *rb, int32 shamt )
{
   ASSERT( rb!=NULL );

   rb->read += shamt;
   if( rb->read>=rb->size )
      rb->read -= rb->size;
}

/*
 * Description
 * ---------
 *   The function mixes two ring buffer instance without shift their pointers
 *
 * Syntax
 * ---------
 *   void PCMRB_Mix( PCMRB *dest_rb, PCMRB *src_rb )
 *
 * where
 *   dest_rb   One of the input ring buffer, also the output ring buffer
 *   src_rb     One of the input ring buffer
 *
 * Return Value
 * ---------
 *   none
 */
 void PCMRB_Mix( PCMRB *dest_rb, PCMRB *src_rb, int32 size )
{
   int32 dest_rb_write, src_rb_read;

   ASSERT( dest_rb!=NULL );
   ASSERT( src_rb!=NULL );
   ASSERT( PCMRB_GetFreeSpace( dest_rb )>=size );
   ASSERT( PCMRB_GetDataCount( src_rb )>=size );

   dest_rb_write = dest_rb->write;
   src_rb_read = src_rb->read;
   while( 1 )
   {
      int32 cnt_write, cnt_read;
      int16 *dest_rb_buf, *src_rb_buf;
      int32 cnt;
      if( src_rb->write>src_rb_read )
         cnt_read = src_rb->write - src_rb_read;
      else
         cnt_read = src_rb->size - src_rb_read;
      if( dest_rb->read>dest_rb_write )
         cnt_write = dest_rb->read - dest_rb_write;
      else
         cnt_write = dest_rb->size - dest_rb_write;
      cnt = (cnt_read<cnt_write)? cnt_read: cnt_write;
      if( cnt>size ) cnt = size;
      
      dest_rb_buf = dest_rb->buffer + dest_rb_write;
      src_rb_buf = src_rb->buffer + src_rb_read;

      pcm_mix_n( dest_rb_buf, src_rb_buf, cnt );

      size -= cnt;
      if( size==0 )
         break;

      dest_rb_write += cnt;
      if( dest_rb_write==dest_rb->size )
         dest_rb_write = 0;
      src_rb_read += cnt;
      if( src_rb_read==src_rb->size )
         src_rb_read = 0;
   }
   
}


