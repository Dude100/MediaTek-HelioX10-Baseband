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
 *   bitop_macros.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Preprocessor macros for putting and getting bit fields into
*    byte arrays.
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
 
#ifndef _BITOP_MACROS_H
#define _BITOP_MACROS_H

/***************************************************************************
 * Macros With Parameters
 ***************************************************************************/

#define MASK(_w) ( ((_w)>31) ? 0xffffffff : (0x1u << (_w)) - 1 )


/* _uc is the pointer to the byte stream from which bits to be read */
/* _s is the offset in bits from MSB of the byte stream _uc  */
/* _w is the number of bits to be read  */

#define GET_BITS_1_8(_uc, _s, _w) (                                  \
   (((_s)+(_w)>8) ? *(_uc) << ((_s)+(_w)-8) |                        \
    *((_uc)+1) >> (16-(_s)-(_w)) :                                   \
     *(_uc) << (_s) >> (8-(_w)))                                     \
    & MASK(_w) )

#define GET_BITS_9_16(_uc, _s, _w) (                                 \
   ((_s+_w>16) ? *_uc << (_s+_w-8) | *(_uc+1) << (_s+_w-16) |        \
    *(_uc+2) >> (24-_s-_w) :                                         \
        *_uc << (_s+_w-8) | *(_uc+1) >> (16-_s-_w))                  \
    & MASK(_w))

#define GET_BITS_17_24(_uc, _s, _w) (                                \
    (((_s)+(_w)>24) ? *(_uc) << ((_s)+(_w)-8) |                      \
     *((_uc)+1) << ((_s)+(_w)-16) |                                  \
     *((_uc)+2) << ((_s)+(_w)-24) | *((_uc)+3) >> (32-(_s)-(_w)) :   \
        *(_uc) << ((_s)+(_w)-8) | *((_uc)+1) << ((_s)+(_w)-16) |     \
        *((_uc)+2) >> (24-(_s)-(_w)))                                \
    & MASK(_w))

#define GET_BITS_25_32(_uc, _s, _w) (                               \
    (((_s)+(_w)>32) ? *(_uc) << ((_s)+(_w)-8) |                      \
     *((_uc)+1) << ((_s)+(_w)-16) |                                  \
     *((_uc)+2) << ((_s)+(_w)-24) | *((_uc)+3) << ((_s)+(_w)-32) |   \
     *((_uc)+4) >> (40-(_s)-(_w)) : *(_uc) << ((_s)+(_w)-8) |        \
     *((_uc)+1) << ((_s)+(_w)-16) | *((_uc)+2) << ((_s)+(_w)-24) |   \
     *((_uc)+3) >> (32-(_s)-(_w))) & MASK(_w))

#define GET_BITS(_uc, _s, _w) (                                      \
    ((_w)>8) ? (((_w)>16) ? (((_w)>24) ?                             \
        GET_BITS_25_32((_uc), (_s), (_w)) :                          \
        GET_BITS_17_24((_uc), (_s), (_w))) :                         \
        GET_BITS_9_16((_uc), (_s), (_w))) :                          \
        GET_BITS_1_8((_uc), (_s), (_w))                              \
    )

/* _uc is the pointer to the byte stream to which bits to be written */
/* _s is the offset in bits from MSB of the byte stream _uc  */
/* _w is the number of bits to be written  */
/* _i is the value to be written  */

#define PUT_BITS_1_8(_uc, _s, _w, _i)                                \
    if ((_s)+(_w)>8) {                                               \
        *(_uc)     &= ~ MASK(8-(_s));                               \
        *(_uc)     |= ((_i) & MASK((_w))) >> ((_s)+(_w)- 8);        \
        *((_uc)+1)   = (*((_uc)+1) & MASK(16-(_s)-(_w))) |           \
        (_i) << (16-(_s)-(_w));                                      \
    } else {                                                         \
        *(_uc)     &= ~ (MASK((_w)) << ( 8-(_w)-(_s)));             \
        *(_uc)     |= ((_i) & MASK((_w))) << ( 8-(_w)-(_s));        \
    }

#define PUT_BITS_9_16(_uc, _s, _w, _i)                               \
    *(_uc) &= ~ MASK(8-(_s));                                       \
    if ((_s)+(_w)>16) {                                              \
        *(_uc)     |= ((_i) & MASK((_w))) >> ((_s)+(_w)- 8);        \
        *((_uc)+1)   = (_i) >> ((_s)+(_w)-16);                       \
        *((_uc)+2)   = (*((_uc)+2) & MASK(24-(_s)-(_w))) |           \
        (_i) << (24-(_s)-(_w));                                      \
    } else {                                                         \
        *(_uc)     |= ((_i) & MASK((_w))) >> ((_s)+(_w)- 8);        \
        *((_uc)+1)   = (*((_uc)+1) & MASK(16-(_s)-(_w))) |           \
        (_i) << (16-(_s)-(_w));                                      \
    }

#define PUT_BITS_17_24(_uc, _s, _w, _i)                              \
    *(_uc) &= ~ MASK(8-(_s));                                       \
    if ((_s)+(_w)>24) {                                              \
        *(_uc)     |= ((_i) & MASK((_w))) >> ((_s)+(_w)- 8);        \
        *((_uc)+1)   = (_i) >> ((_s)+(_w)-16);                       \
        *((_uc)+2)   = (_i) >> ((_s)+(_w)-24);                       \
        *((_uc)+3)   = (*((_uc)+3) & MASK(32-(_s)-(_w))) |           \
        (_i) << (32-(_s)-(_w));                                      \
    } else {                                                         \
        *(_uc)     |= ((_i) & MASK((_w))) >> ((_s)+(_w)- 8);        \
        *((_uc)+1)   = (_i) >> ((_s)+(_w)-16);                       \
        *((_uc)+2)   = (*((_uc)+2) & MASK(24-(_s)-(_w))) |           \
        (_i) << (24-(_s)-(_w));                                      \
    }

#define PUT_BITS_25_32(_uc, _s, _w, _i)                              \
    *(_uc) &= ~MASK(8-(_s));                                        \
    if ((_s)+(_w)>32) {                                              \
        *(_uc)     |= ((_i) & MASK((_w))) >> ((_s)+(_w)- 8);        \
        *((_uc)+1)   = (_i) >> ((_s)+(_w)-16);                       \
        *((_uc)+2)   = (_i) >> ((_s)+(_w)-24);                       \
        *((_uc)+3)   = (_i) >> ((_s)+(_w)-32);                       \
        *((_uc)+4)   = (*((_uc)+4) & MASK(40-(_s)-(_w))) |           \
        (_i) << (40-(_s)-(_w));                                      \
    } else {                                                         \
        *(_uc)     |= ((_i) & MASK((_w))) >> ((_s)+(_w)- 8);        \
        *((_uc)+1)   = (_i) >> ((_s)+(_w)-16);                       \
        *((_uc)+2)   = (_i) >> ((_s)+(_w)-24);                       \
        *((_uc)+3)   = (*((_uc)+3) & MASK(32-(_s)-(_w))) |           \
        (_i) << (32-(_s)-(_w));                                      \
    }

#define PUT_BITS(_uc, _s, _w, _i)                                    \
    if ((_w)<9) {                                                    \
        PUT_BITS_1_8(_uc, _s, _w, _i)                                \
    } else if ((_w)<17) {                                            \
        PUT_BITS_9_16(_uc, _s, _w, _i)                               \
    } else if ((_w)<25) {                                            \
        PUT_BITS_17_24(_uc, _s, _w, _i)                              \
    } else {                                                         \
        PUT_BITS_25_32(_uc, _s, _w, _i)                              \
    }


/********************************************************************/
/* This macro insert a given number of bits to a bit position
 * by shifting the existing bits down. */

/* ptr is the pointer to the byte stream
 * to which bits to be inserted.         */
/* _offset is the offset in bytes from MSB of byte stream ptr.  */
/* length is the number of bits to be inserted.                 */
/* _size is the number of bits in the bit stream, after the point
 * of insertion ,which is to be shifted. */
/* _value is the value to be inserted.   */


#define INSERT_BITS(ptr,_offset,length,_size,_value)                 \
{                                                                    \
    unsigned int temp,value =_value;                                 \
    unsigned short int offset=_offset,size=_size;                    \
    while(length <= size) {                                          \
        temp = GET_BITS(ptr,offset,length);                          \
        PUT_BITS(ptr,offset,length,value);                           \
        ptr = ptr +((offset+length)/8);                              \
        offset = (offset+length)%8;                                  \
        size -=length;                                               \
        value = temp;                                                \
    }                                                                \
    temp = GET_BITS(ptr,offset,size);                                \
    PUT_BITS(ptr,offset,length,value);                               \
    ptr = ptr +(offset+length)/8;                                    \
    offset = (offset+length)%8;                                      \
    PUT_BITS(ptr,offset,size,temp);                                  \
}

/* Conversions for length fields                                      */
/* BITS_TO_BYTES_INC converts a length in bits, to a length in bytes, */
/* inclusive of remainder (i.e. rounding up)                          */
/* BITS_TO_BYTES_EXC converts a length in bits, to a length in bytes, */
/* exclusive of remainder (i.e. rounding down)                        */
/* These macros work for all types of integer                         */
/* but beware sufficient headroom on BYTES_TO_BITS                    */
#define BITS_TO_BYTES_INC(bit_length) (((bit_length)+7)/8)
#define BITS_TO_BYTES_EXC(bit_length) ((bit_length)/8)
#define BYTES_TO_BITS(length) ((length)*8)

/* Similar to round up to fit U32s                                    */
/* for buffer size allocation etc.                                    */
#define BITS_TO_U32S_INC(bit_length) (((bit_length)+31)/32)
#define BYTES_TO_U32S_INC(length) (((length)+3)/4)

#endif /* _BITOP_MACROS_H */


