/* Copyright (c) 2003-2008, Jouni Malinen <j@w1.fi> and contributors
 * All Rights Reserved.
 * 
 * This program is dual-licensed under both the GPL version 2 and BSD
 * license. Either license may be used at your option.
 * 
 * 
 * 
 * License
 * -------
 * 
 * GPL v2:
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 * 
 * (this copy of the license is in COPYING file)
 * 
 * 
 * Alternatively, this software may be distributed, used, and modified
 * under the terms of BSD license:
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * 3. Neither the name(s) of the above-listed copyright holder(s) nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    aes.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   aes software function.
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

#ifndef __AES_H__
#define __AES_H__

#include "kal_general_types.h"

#if defined(_MSC_VER)
   #define SWAP(x) (_lrotl(x, 8) & 0x00ff00ff | _lrotr(x, 8) & 0xff00ff00)
   #define GETU32(p) SWAP(*((u32 *)(p)))
   #define PUTU32(ct, st) { *((u32 *)(ct)) = SWAP((st)); }
#else
   #define GETU32(pt) (((u32)(pt)[0] << 24) ^ ((u32)(pt)[1] << 16) ^ ((u32)(pt)[2] <<  8) ^ ((u32)(pt)[3]))
   #define PUTU32(ct, st) { (ct)[0] = (u8)((st) >> 24); (ct)[1] = (u8)((st) >> 16); (ct)[2] = (u8)((st) >>  8); (ct)[3] = (u8)(st); }
#endif

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;

#define MAXKC   (256/32)
#define MAXKB   (256/8)
#define MAXNR   14


#undef FULL_UNROLL



#define AES_ENCRYPT	1
#define AES_DECRYPT	0



#define AES_MAXNR 14
#define AES_BLOCK_SIZE 16

struct aes_key_st {
    unsigned long rd_key[4 *(AES_MAXNR + 1)];
    int rounds;
};
typedef struct aes_key_st AES_KEY;

kal_int32 CHE_AES_block_encrypt(kal_uint8 *ivec, AES_KEY *cipher, kal_uint8 *input, kal_uint32 uInputLen, kal_uint8 *outBuffer, kal_bool first_flag, kal_uint8 *orgIV);

kal_int32 CHE_AES_block_decrypt(kal_uint8 *ivec, AES_KEY *cipher, kal_uint8 *input, kal_uint32 uInputLen, kal_uint8 *outBuffer, kal_bool first_flag, kal_uint8 *orgIV);


void CHE_AES_unit_encrypt(const kal_uint32 rk[], kal_int32 Nr, const kal_uint8 pt[16], kal_uint8 ct[16]);

void CHE_AES_unit_decrypt(const kal_uint32 rk[], int Nr, const kal_uint8 ct[16], kal_uint8 pt[16]);


void CHE_AES_unit_encrypt(const kal_uint32 rk[], kal_int32 Nr, const kal_uint8 pt[16], kal_uint8 ct[16]);

void CHE_AES_unit_decrypt(const kal_uint32 rk[], int Nr, const kal_uint8 ct[16], kal_uint8 pt[16]);


kal_int32 CHE_AES_ctr_encrypt( unsigned char *nonce, AES_KEY *key, unsigned char *data, unsigned long data_len, unsigned char *output, kal_bool first_flag, kal_uint8 *orgIV);

kal_int32 CHE_AES_ctr_encrypt( unsigned char *nonce, AES_KEY *key, unsigned char *data, unsigned long data_len, unsigned char *output, kal_bool first_flag, kal_uint8 *orgIV);

kal_int32 CHE_AES_f8_encrypt( unsigned char *IV, AES_KEY *key, unsigned char *data, unsigned long data_len, unsigned char *output, kal_bool first_flag);

kal_int32 CHE_AES_f8_decrypt( unsigned char *IV, AES_KEY *key, unsigned char *data, unsigned long data_len, unsigned char *output, kal_bool first_flag);

kal_int32 CHE_AES_setup_enc_key(kal_uint32 rk[], const kal_uint8 *cipherKey, kal_int32 keyBits);
kal_int32 CHE_AES_ctr_decrypt( unsigned char *nonce, AES_KEY *key, unsigned char *data, unsigned long data_len, unsigned char *output, kal_bool first_flag, kal_uint8 *orgIV);
kal_int32 CHE_AES_setup_dec_key(kal_uint32 rk[], const kal_uint8 cipherKey[], kal_int32 keyBits);
int CHE_AES_WRAP(AES_KEY *key, kal_int32 n, const kal_uint8 *plain, kal_uint8 *cipher);
int CHE_AES_UNWRAP(AES_KEY *key, kal_int32 n, const kal_uint8 *cipher, kal_uint8 *plain);
#endif /* __AES_H__ */
