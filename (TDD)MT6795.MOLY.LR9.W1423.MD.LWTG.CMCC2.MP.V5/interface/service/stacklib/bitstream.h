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
 *   bitstream.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   BitStream allows sequential reading and writing of bit fields.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/
 
#ifndef _BITSTREAM_H
#define _BITSTREAM_H
/*RHR*/
#include "kal_general_types.h"
/*RHR*/
/* BitStream
 *
 *      A bit stream allows bit fields to be read and written to,
 *      just like an byte stream allows byte to be read and written
 *      to. Reading and writing of bit fields is done to an underlying
 *      byte stream, in network byte order.
 *
 *      bit_stream_init sets the underlying byte stream and the
 *      current read/write position within the byte stream. Can also
 *      be called when a seek to a new position is desired.

 *      The values which are read by bit_stream_read are returned as
 *      native unsigned integers.
 *
 *      Similarly the values which are passed to bit_stream_write for
 *      writing should be passed as native unsigned integers.
 *
 *      Both bit_stream_read and bit_stream_write, increment the
 *      current position,to facilitate sequential operation.
 *      bit_stream_cur_pos returns the number of bytes, the underlying
 *      byte pointer has been moved since bit_stream_init.
 *
 */

typedef struct bit_stream {
    kal_uint8    *byte_stream; /* Pointer to underlying byte stream. */
    kal_uint8    *byte_stream_start;
    kal_uint8    offset;    /* Offset in bits from MSB of byte_stream */
} bit_stream;

/* Initialise Bit stream operations
 *
 *                                offset
 *                                |
 *                                V
 *               /-------------------------------\
 * byte_stream-->|   |   |   |   |   |   |   |   |
 *               |---|---|---|---|---|---|---|---|
 *               |   |   |   |   |   |   |   |   |
 *               |---|---|---|---|---|---|---|---|
 *               |   |   |   |   |   |   |   |   |
 *               |---|---|---|---|---|---|---|---|
 *               | . | . | . | . | . | . | . | . |
 *                 .   .   .   .   .   .   .   .
 *                 .   .   .   .   .   .   .   .
 *
 *  If offset is more than eight then, byte_stream is incremented by
 *  offset/8 and offset is taken to be offset modulo 8.
 */
extern void bit_stream_init(
                            bit_stream      *bs,
                            kal_uint8       *byte_stream,
                            unsigned int    offset);

/* Read specified number of bits from current position and return it as
 *  an unsigned integer.
 *
 *                                        offset (before)
 *                                        |
 *                                        V
 *                       /-------------------------------\
 * byte_stream (before)->|   |   |   |   | 1 | 0 | 0 | 0 |
 *                       |---|---|---|---|---|---|---|---|
 * byte_stream (after) ->| 1 | 0 |   |   |   |   |   |   |
 *                       |---|---|---|---|---|---|---|---|
 *                       | . | . | ^ | . | . | . | . | . |
 *                                 |
 *                                 offset (after)
 *
 *      On the above stream bit_stream_read(bs, 6) will return 34
 */
extern unsigned int bit_stream_read(
                                    bit_stream      *bs,
                                    unsigned int    width);


/* Write specified number of bits from current position into the
 * underlying byte stream.
 *
 *              bit_stream_write(bs, 6)
 *
 *                                        offset (before)
 *                                        |
 *                                        V
 *                       /-------------------------------\
 * byte_stream (before)->|   |   |   |   | 1 | 0 | 0 | 0 |
 *                       |---|---|---|---|---|---|---|---|
 * byte_stream (after) ->| 1 | 0 |   |   |   |   |   |   |
 *                       |---|---|---|---|---|---|---|---|
 *                       | . | . | ^ | . | . | . | . | . |
 *                                 |
 *                                 offset (after)
 *
 */
extern void bit_stream_write(
                             bit_stream      *bs,
                             unsigned int    width,
                             unsigned int    value );

/* Return the number of bits the internal pointer has moved since
 * bit_stream_init */
extern unsigned int bit_stream_cur_pos(bit_stream    *bs);

/* Move pointer back by given number of bits */
extern void bit_stream_move_back(
                                 bit_stream      *bs,
                                 unsigned int    bits);

/* Copy bits from one byte stream to another.
 * Byte stream is incremented as read operation
 * is done */

extern void byte_stream_bit_copy(
                                 kal_uint8      *s,
                                 unsigned int   s_offset,
                                 unsigned int   length,
                                 kal_uint8      *d,
                                 unsigned int   d_offset);


/* Read specified number of bits from the bitstream, starting
 * from a position, width bits before the current position.

 *
 *                                        offset (after)
 *                                        |
 *                                        V
 *                       /-------------------------------\
 * byte_stream (after)-> |   |   |   |   | 1 | 0 | 0 | 0 |
 *                       |---|---|---|---|---|---|---|---|
 * byte_stream (before)->| 1 | 0 |   |   |   |   |   |   |
 *                       |---|---|---|---|---|---|---|---|
 *                       | . | . | ^ | . | . | . | . | . |
 *                                 |
 *                                 offset (before)
 *
 *      On the above stream ,
 *         bit_stream_read_back(bs, 6) will return 34
 */

extern unsigned int bit_stream_read_back(
                                         bit_stream    *bs,
                                         unsigned int  width);



/* Write specified number of bits to the bitstream starting
 * from a position width bits before the current position.
 *
 *     bit_stream_write_back(bs, 6, 34) will return
 *
 *
 *                                        offset (after)
 *                                        |
 *                                        V
 *                       /-------------------------------\
 * byte_stream (after) ->|   |   |   |   | 1 | 0 | 0 | 0 |
 *                       |---|---|---|---|---|---|---|---|
 * byte_stream (before)->| 1 | 0 |   |   |   |   |   |   |
 *                       |---|---|---|---|---|---|---|---|
 *                       | . | . | ^ | . | . | . | . | . |
 *                                 |
 *                                 offset (before)
 *
 */
extern void bit_stream_write_back(
                                  bit_stream      *bs,
                                  unsigned int    width,
                                  unsigned int    value );
#endif /* _BITSTREAM_H */

