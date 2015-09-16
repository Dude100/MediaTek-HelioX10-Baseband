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
 *   wav_codec.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Wave codec functions, adapted from g711.c 1.10
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "l1audio_def.h"
#include "wav.h"

#define  SIGN_BIT    (0x80)      /* Sign bit for a A-law byte.       */
#define  QUANT_MASK  (0x0F)      /* Quantization field mask.         */
#define  NSEGS       (8)         /* Number of A-law segments.        */
#define  SEG_SHIFT   (4)         /* Left shift for segment number.   */
#define  SEG_MASK    (0x70)      /* Segment field mask.              */
#define  BIAS        (0x84)      /* Bias for linear code.            */
#define FIXED(v)      ((Word16)(16384.0 * (v) + 0.5))
#define FRAME_SAMPLE  80

const int16 sintab[] = {
       0,   201,   402,   603,   804,  1005,  1206,  1406,
    1607,  1808,  2009,  2209,  2410,  2610,  2811,  3011,
    3211,  3411,  3611,  3811,  4011,  4210,  4409,  4608,
    4807,  5006,  5205,  5403,  5601,  5799,  5997,  6195,
    6392,  6589,  6786,  6983,  7179,  7375,  7571,  7766,
    7961,  8156,  8351,  8545,  8739,  8933,  9126,  9319,
    9511,  9703,  9895, 10087, 10278, 10469, 10659, 10849,
   11038, 11227, 11416, 11604, 11792, 11980, 12166, 12353,
   12539, 12724, 12909, 13094, 13278, 13462, 13645, 13827,
   14009, 14191, 14372, 14552, 14732, 14911, 15090, 15268,
   15446, 15623, 15799, 15975, 16150, 16325, 16499, 16672,
   16845, 17017, 17189, 17360, 17530, 17699, 17868, 18036,
   18204, 18371, 18537, 18702, 18867, 19031, 19194, 19357,
   19519, 19680, 19840, 20000, 20159, 20317, 20474, 20631,
   20787, 20942, 21096, 21249, 21402, 21554, 21705, 21855,
   22005, 22153, 22301, 22448, 22594, 22739, 22883, 23027,
   23169, 23311, 23452, 23592, 23731, 23869, 24006, 24143,
   24278, 24413, 24546, 24679, 24811, 24942, 25072, 25201,
   25329, 25456, 25582, 25707, 25831, 25954, 26077, 26198,
   26318, 26438, 26556, 26673, 26789, 26905, 27019, 27132,
   27244, 27355, 27466, 27575, 27683, 27790, 27896, 28001,
   28105, 28208, 28309, 28410, 28510, 28608, 28706, 28802,
   28897, 28992, 29085, 29177, 29268, 29358, 29446, 29534,
   29621, 29706, 29790, 29873, 29955, 30036, 30116, 30195,
   30272, 30349, 30424, 30498, 30571, 30643, 30713, 30783,
   30851, 30918, 30984, 31049, 31113, 31175, 31237, 31297,
   31356, 31413, 31470, 31525, 31580, 31633, 31684, 31735,
   31785, 31833, 31880, 31926, 31970, 32014, 32056, 32097,
   32137, 32176, 32213, 32249, 32284, 32318, 32350, 32382,
   32412, 32441, 32468, 32495, 32520, 32544, 32567, 32588,
   32609, 32628, 32646, 32662, 32678, 32692, 32705, 32717,
   32727, 32736, 32744, 32751, 32757, 32761, 32764, 32766,
   32767
};

static const short seg_end[] = {
   0xFF, 0x1FF, 0x3FF, 0x7FF, 0xFFF, 0x1FFF, 0x3FFF, 0x7FFF
};

static int search( int val, const short *table, int size )
{
   int i;

   for(i = 0; i < size; i++) {
      if (val <= *table++)
         return (i);
   }
   return (size);
}

/*
 * linear2alaw() - Convert a 16-bit linear PCM value to 8-bit A-law
 *
 * linear2alaw() accepts an 16-bit integer and encodes it as A-law data.
 *
 *    Linear Input Code Compressed Code
 * ------------------------   ---------------
 * 0000000wxyza         000wxyz
 * 0000001wxyza         001wxyz
 * 000001wxyzab         010wxyz
 * 00001wxyzabc         011wxyz
 * 0001wxyzabcd         100wxyz
 * 001wxyzabcde         101wxyz
 * 01wxyzabcdef         110wxyz
 * 1wxyzabcdefg         111wxyz
 *
 * For further information see John C. Bellamy's Digital Telephony, 1982,
 * John Wiley & Sons, pps 98-111 and 472-476.
 */
int linear2alaw( int p_val )  /* 2's complement (16-bit range) */
{
   int      mask;
   int      seg;
   unsigned char  aval;
   int      pcm_val = (p_val >> 3) << 3;

   if (pcm_val >= 0) {
      mask = 0xD5;      /* sign (7th) bit = 1 */
   }
   else {
      mask = 0x55;      /* sign bit = 0 */
      pcm_val = -pcm_val - 8;
   }

   /* Convert the scaled magnitude to segment number. */
   seg = search(pcm_val, seg_end, 8);

   /* Combine the sign, segment, and quantization bits. */

   if (seg >= 8)     /* out of range, return maximum value. */
      return (0x7F ^ mask);
   else {
      aval = seg << SEG_SHIFT;
      if (seg < 2)
         aval |= (pcm_val >> 4) & QUANT_MASK;
      else
         aval |= (pcm_val >> (seg + 3)) & QUANT_MASK;
      return (aval ^ mask);
   }
}

/*
 * alaw2linear() - Convert an A-law value to 16-bit linear PCM
 *
 */
unsigned short alaw2linear ( unsigned char a_val )
{
   int      t;
   int      seg;

   a_val ^= 0x55;

   t = (a_val & QUANT_MASK) << 4;
   seg = ((unsigned)a_val & SEG_MASK) >> SEG_SHIFT;
   switch (seg) {
   case 0:
      t += 8;
      break;
   case 1:
      t += 0x108;
      break;
   default:
      t += 0x108;
      t <<= seg - 1;
   }
   return (unsigned short)(short)((a_val & SIGN_BIT) ? t : -t);
}

/*
 * linear2ulaw() - Convert a linear PCM value to u-law
 *
 * In order to simplify the encoding process, the original linear magnitude
 * is biased by adding 33 which shifts the encoding range from (0 - 8158) to
 * (33 - 8191). The result can be seen in the following encoding table:
 *
 * Biased Linear Input Code   Compressed Code
 * ------------------------   ---------------
 * 00000001wxyza        000wxyz
 * 0000001wxyzab        001wxyz
 * 000001wxyzabc        010wxyz
 * 00001wxyzabcd        011wxyz
 * 0001wxyzabcde        100wxyz
 * 001wxyzabcdef        101wxyz
 * 01wxyzabcdefg        110wxyz
 * 1wxyzabcdefgh        111wxyz
 *
 * Each biased linear code has a leading 1 which identifies the segment
 * number. The value of the segment number is equal to 7 minus the number
 * of leading 0's. The quantization interval is directly available as the
 * four bits wxyz.  * The trailing bits (a - h) are ignored.
 *
 * Ordinarily the complement of the resulting code word is used for
 * transmission, and so the code word is complemented before it is returned.
 *
 * For further information see John C. Bellamy's Digital Telephony, 1982,
 * John Wiley & Sons, pps 98-111 and 472-476.
 */
int linear2ulaw( int p_val )  /* 2's complement (16-bit range) */
{
   int      mask;
   int      seg;
   unsigned char  uval;
   int      pcm_val = (int)(short)p_val;

   /* Get the sign and the magnitude of the value. */
   if (pcm_val < 0) {
      pcm_val = BIAS - pcm_val;
      mask = 0x7F;
   }
   else {
      pcm_val += BIAS;
      mask = 0xFF;
   }

   /* Convert the scaled magnitude to segment number. */
   seg = search(pcm_val, seg_end, 8);

   /*
    * Combine the sign, segment, quantization bits;
    * and complement the code word.
    */
   if (seg >= 8)     /* out of range, return maximum value. */
      return (0x7F ^ mask);
   else {
      uval = (seg << 4) | ((pcm_val >> (seg + 3)) & 0xF);
      return (uval ^ mask);
   }

}

/*
 * ulaw2linear() - Convert a u-law value to 16-bit linear PCM
 *
 * First, a biased linear code is derived from the code word. An unbiased
 * output can then be obtained by subtracting 33 from the biased code.
 *
 * Note that this function expects to be passed the complement of the
 * original code word. This is in keeping with ISDN conventions.
 */
unsigned short ulaw2linear( unsigned char u_val )
{
   int      t;

   /* Complement to obtain normal u-law value. */
   u_val = ~u_val;

   /*
    * Extract and bias the quantization bits. Then
    * shift up by the segment number and subtract out the bias.
    */
   t = ((u_val & QUANT_MASK) << 3) + BIAS;
   t <<= ((unsigned)u_val & SEG_MASK) >> SEG_SHIFT;

   return (unsigned short)(short)((u_val & SIGN_BIT) ? (BIAS - t) : (t - BIAS));
}

/* ------------------------------------------------------------------------------ */

/* Intel ADPCM step variation table */
static const short indexTable[16] = {
    -1, -1, -1, -1, 2, 4, 6, 8,
    -1, -1, -1, -1, 2, 4, 6, 8,
};

/* Intel ADPCM step sizes table */
static const short stepsizeTable[90] =
{
       7,     8,     9,    10,    11,    12,    13,    14,    16,    17,
      19,    21,    23,    25,    28,    31,    34,    37,    41,    45,
      50,    55,    60,    66,    73,    80,    88,    97,   107,   118,
     130,   143,   157,   173,   190,   209,   230,   253,   279,   307,
     337,   371,   408,   449,   494,   544,   598,   658,   724,   796,
     876,   963,  1060,  1166,  1282,  1411,  1552,  1707,  1878,  2066,
    2272,  2499,  2749,  3024,  3327,  3660,  4026,  4428,  4871,  5358,
    5894,  6484,  7132,  7845,  8630,  9493, 10442, 11487, 12635, 13899,
   15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767
};

/* Microsoft ADPCM step variation table */
static const short stepAdjustTable[] = {
        230, 230, 230, 230, 307, 409, 512, 614,
        768, 614, 512, 409, 307, 230, 230, 230
};

/* Microsoft ADPCM coefficient table */
const short iCoeff[7][2] = {
                        { 256,   0},
                        { 512,-256},
                        {   0,   0},
                        { 192,  64},
                        { 240,   0},
                        { 460,-208},
                        { 392,-232}
};

/*
**************************************************************************
* Initialze the data used by the coder.
**************************************************************************
*/
void dviAdpcm_Init( dviAdpcm_State *state )
{
   state->index = 0;
   state->valpred = 0;
   return;
}


/*
**************************************************************************
* Encode linear to ADPCM
**************************************************************************
*/
unsigned char dviAdpcm_Encode( unsigned short pcm, dviAdpcm_State *state )
{
   int sign;         /* Current adpcm sign bit */
   int diff;         /* Difference between val and valprev */
   int step;         /* Stepsize */
   int delta;        /* Current adpcm output value */
   int vpdiff;       /* Current change to valpred */
   int index_cache = state->index;
   int valpred_cache = state->valpred;
   int val = (int)(short)pcm;

   step = stepsizeTable[index_cache];

   /* Step 1 - compute difference with previous value */
   diff = val - valpred_cache;
   sign = (diff < 0) ? 8 : 0;
   if (sign) diff = (-diff);

   /* Step 2 - Divide and clamp */
   /* Note:
   ** This code *approximately* computes:
   **    delta = diff*4/step;
   **    vpdiff = (delta+0.5)*step/4;
   ** but in shift step bits are dropped. The net result of this is
   ** that even if you have fast mul/div hardware you cannot put it to
   ** good use since the fixup would be too expensive.
   */
   delta = 0;

   vpdiff = (step >> 3);

   if (diff >= step) {
      delta = 4;
      diff -= step;
      vpdiff += step;
   }

   step >>= 1;

   if (diff >= step) {
      delta |= 2;
      diff -= step;
      vpdiff += step;
   }

   step >>= 1;

   if(diff >= step) {
      delta |= 1;
      vpdiff += step;
   }

   if ( sign ) valpred_cache -= vpdiff; /* Step 3 - Update previous value */
   else valpred_cache += vpdiff;

   if( valpred_cache > 32767 )     /* Step 4 - Clamp previous value to 16 bits */
      valpred_cache = 32767;
   else if( valpred_cache < -32768 )
      valpred_cache = -32768;
   state->valpred = valpred_cache;

   /* Step 5 - Assemble value, update index and step values */
   delta |= sign;

   index_cache += indexTable[delta];

   if(index_cache < 0)
      index_cache = 0;
   else if ( index_cache > 88 )
      index_cache = 88;
   state->index = index_cache;
   return delta;
}

/*
**************************************************************************
* Decode Linear from ADPCM
**************************************************************************
*/

int dviAdpcm_Decode( int delta, dviAdpcm_State *state )
{
   int step;        /* Stepsize */
   int vpdiff;      /* Current change to valpred */
   int index_cache = state->index;

   if ( index_cache < 0 )
      index_cache = 0;
   else if ( index_cache > 88 )
      index_cache = 88;

   step = stepsizeTable[index_cache];

   /* Step 2 - Find new index value (for later) */
   index_cache += indexTable[delta];
   state->index = index_cache;

   vpdiff = step >> 3;
   if (delta & 4) vpdiff += step;
   if (delta & 2) vpdiff += step>>1;
   if (delta & 1) vpdiff += step>>2;

   {
      int valpred_cache = state->valpred;

      if (delta & 8) {
      	valpred_cache -= vpdiff;
      } else {
      	valpred_cache += vpdiff;
      }

      if (valpred_cache < -32768)
         valpred_cache = -32768;
      else if (valpred_cache> 32767)
         valpred_cache = 32767;

      state->valpred = valpred_cache;
      return valpred_cache;
   }
}

short ms_adpcm_decode_sample( uint8 error_delta, MS_ADPCM_STATE *state )
{
   int linearSample, delta;

	linearSample = ((state->iSamp1 * state->iCoeff1) +
      (state->iSamp2 * state->iCoeff2)) >> 8;

	if ( error_delta & 0x08)
		linearSample += state->iDelta * (error_delta-0x10);
	else
		linearSample += state->iDelta * error_delta;

	/* Clamp linearSample to a signed 16-bit value. */
	if (linearSample < -32768)
		linearSample = -32768;
	else if (linearSample > 32767)
		linearSample = 32767;

	delta = ((int) state->iDelta * stepAdjustTable[error_delta]) >> 8;
   state->iDelta = (delta < 16) ? 16:delta;
	state->iSamp2 = state->iSamp1;
	state->iSamp1 = linearSample;

	/*
		Because of earlier range checking, new_sample will be
		in the range of an int16.
	*/
	return (short) linearSample;
}

int16 my_cos( int32 idx )
{
   int32 frac;

   if( idx < 0 )
      idx = -idx;
   idx &= 0xFFFF;
   if( idx >= 0x8000 ) {
      idx = 0x10000 - idx;
   }
   frac = idx & 0x3F;
   idx = (idx >> 6) & 0x3FF;
   if( idx < 256 )
      return (sintab[256-idx] * (0x40-frac) + sintab[256-idx-1] * frac) >> 6;
   return (-sintab[idx-256] * (0x40-frac) - sintab[idx-256+1] * frac) >> 6;
}

/*
 * Bit reverse the number
 *
 * Change 11100000b to 00000111b or vice-versa
 */
static int permute( int index, int fft_size_bits )
{
   int   n1, result, loop;

   n1 = 1 << fft_size_bits;
   result = 0;

   for (loop = 0; loop < fft_size_bits; loop++)  {
      n1 >>= 1;         /* n1 / 2.0 */
      if (index < n1)
         continue;

      result += (1 << loop);
      index -= n1;
   }

   return result;
}

void my_fft( int16 *real, int16 *imag, int fft_size_bits )
{
   unsigned i1, i2, i3, i4, y, loop1, loop2;
   int    loop, z1, z2;
   int    a1, a2, b1, b2;
   int fft_size = 1 << fft_size_bits;

   /* Scale the data */
   for (loop = 0; loop < fft_size; loop++)  {
      real[loop] >>= fft_size_bits;
      imag[loop] >>= fft_size_bits;
   }

   i1 = fft_size >> 1;
   i2 = 1;

   for (loop = 0; loop < fft_size_bits; loop++)  {
      i3 = 0;
      i4 = i1;

      for (loop1 = 0; loop1 < i2; loop1++)  {
         y = permute( i3 / i1, fft_size_bits );
         z1 =  my_cos( y * 0x10000 >> fft_size_bits );
         z2 = -my_cos( 0x4000 - (y * 0x10000 >> fft_size_bits) );

         for (loop2 = i3; loop2 < i4; loop2++)  {
            a1 = real[loop2];
            a2 = imag[loop2];

            b1 = (z1*real[loop2+i1] - z2*imag[loop2+i1])>>15;
            b2 = (z2*real[loop2+i1] + z1*imag[loop2+i1])>>15;

            real[loop2]      = (int16)(a1 + b1);
            imag[loop2]      = (int16)(a2 + b2);

            real[loop2 + i1] = (int16)(a1 - b1);
            imag[loop2 + i1] = (int16)(a2 - b2);
         }

         i3 += (i1 << 1);
         i4 += (i1 << 1);
      }

      i1 >>= 1;
      i2 <<= 1;
   }
}

