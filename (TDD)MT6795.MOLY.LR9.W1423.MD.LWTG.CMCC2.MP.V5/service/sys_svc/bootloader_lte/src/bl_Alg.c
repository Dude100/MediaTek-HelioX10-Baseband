/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   BL_Alg.c
 *
 * Project:
 * --------
 *   BootLoader
 *
 * Description:
 * ------------
 *   This Module defines cryptographic algorithm
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

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "bl_loader.h"
#include "bl_common.h"
#include "bl_sectiondef.h"

#include <string.h>

#if defined(__SECURE_USB_DOWNLOAD__) || defined(__SECURE_UART_DOWNLOAD__) || defined(__CARD_DOWNLOAD__)

#include "che_api.h"
#include "sha1.h"
#include "rc4.h"
#include "custom_nvram_sec.h"

//#define _BL_ALG_DEBUG_
//#define _BL_ALG_SKIP_

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
#endif

extern kal_uint32  Image$$EXT_READ_WRITE$$ZI$$Limit;

extern kal_uint32 custom_get_symmetric_key(kal_uint8 *key, kal_uint32 len);
extern kal_uint32 custom_get_asymmetric_key(kal_uint8 *key, kal_uint32 len);
extern kal_bool RSA_Encode(kal_uint32 dest_addr, kal_uint32 src_addr, kal_uint32 len, kal_uint32 key, kal_uint32 key_len);


kal_bool bl_Alg_Hash_Init(void);
kal_bool bl_Alg_Hash_Append(kal_uint32 addr, kal_uint32 len);
kal_bool bl_Alg_Hash_Finish(kal_uint32 digest, kal_uint32 len);
kal_bool bl_Alg_Sym_Decrypt(kal_uint32 dest_addr, kal_uint32 src_addr, kal_uint32 len, kal_uint32 key, kal_uint32 key_len);
kal_bool bl_Alg_Asym_Decrypt(kal_uint32 dest_addr, kal_uint32 src_addr, kal_uint32 len, kal_uint32 key, kal_uint32 key_len);


#endif /* __SECURE_USB_DOWNLOAD__ || __SECURE_UART_DOWNLOAD__ || __CARD_DOWNLOAD__ */


#if defined(__SECURE_USB_DOWNLOAD__) || defined(__SECURE_UART_DOWNLOAD__)
__bl_alg_table__ const T_BL_FUNC_TABLE g_BlFunc_Table =
{
   bl_Alg_Hash_Init,
   bl_Alg_Hash_Append,
   bl_Alg_Hash_Finish,
   bl_Alg_Sym_Decrypt,
   bl_Alg_Asym_Decrypt,
   sizeof(T_BL_FUNC_TABLE),
   FUNC_TABLE_ID
};
#else /* __SECURE_USB_DOWNLOAD__ || __SECURE_UART_DOWNLOAD__ */
__bl_alg_table__ const T_BL_FUNC_TABLE g_BlFunc_Table;
#endif /* __SECURE_USB_DOWNLOAD__ || __SECURE_UART_DOWNLOAD__ */

#if defined(__SECURE_USB_DOWNLOAD__) || defined(__SECURE_UART_DOWNLOAD__) || defined(__CARD_DOWNLOAD__)

static sha1_context hash_context;

kal_bool bl_Alg_Hash_Init(void)
{
#ifdef _BL_ALG_DEBUG_
   dbg_print("bl_Alg_Hash_Init\n\r");
#endif /*_BL_ALG_DEBUG_ */

#ifndef _BL_ALG_SKIP_
   CHE_sha1_Init(&hash_context);
#endif /* _BL_ALG_SKIP_ */
   
   return KAL_TRUE;
}


kal_bool bl_Alg_Hash_Append(kal_uint32 addr, kal_uint32 len)
{
#ifdef _BL_ALG_DEBUG_
   dbg_print("bl_Alg_Hash_Append(%x, %d)\n\r", addr, len);
#endif /*_BL_ALG_DEBUG_ */
   
#ifndef _BL_ALG_SKIP_
   CHE_sha1_append(&hash_context, (kal_uint8 *)addr, (int)len);
#endif /* _BL_ALG_SKIP_ */

   return KAL_TRUE;
}

kal_bool bl_Alg_Hash_Finish(kal_uint32 digest, kal_uint32 len)
{
#ifdef _BL_ALG_DEBUG_
   dbg_print("bl_Alg_Hash_Finish(%x, %d)\n\r", digest, len);
#endif /*_BL_ALG_DEBUG_ */
   
#ifndef _BL_ALG_SKIP_
   if (len < sizeof(sha1_digest))
   {
      return KAL_FALSE;
   }

   CHE_sha1_finish(&hash_context, (kal_uint8 *)digest);
#endif /* _BL_ALG_SKIP_ */
   
   return KAL_TRUE;
}


kal_bool bl_Alg_Sym_Decrypt(kal_uint32 dest_addr, kal_uint32 src_addr, kal_uint32 len, kal_uint32 key, kal_uint32 key_len)
{
    
    RC4_CNXT cnxt;
#ifdef _BL_ALG_DEBUG_
   dbg_print("bl_Alg_Sym_Decrypt(%x, %x, %d, %x, %d)\n\r", dest_addr, src_addr, len, key, key_len);
#endif /*_BL_ALG_DEBUG_ */
   
#ifndef _BL_ALG_SKIP_

   che_rc4_set_key((RC4_CNXT *)&cnxt, (kal_uint32)key_len, (kal_uint8 *)key);
   //che_rc4((RC4_CNXT *)&cnxt, (kal_uint32)len, (kal_uint8 *)src_addr, (kal_uint8 *)dest_addr);
   //che_rc4((kal_uint8 *)src_addr, (int)len, (kal_uint8 *)key, (int)key_len, CHE_MODE_NULL, (kal_uint8 *)dest_addr);
   che_rc4(&cnxt, (kal_uint8 *)src_addr, len, (kal_uint8 *)key, key_len, CHE_MODE_NULL, (kal_uint8 *)dest_addr);
#endif /* _BL_ALG_SKIP_ */

   return KAL_TRUE;
}

kal_bool bl_Alg_Asym_Decrypt(kal_uint32 dest_addr, kal_uint32 src_addr, kal_uint32 len, kal_uint32 key, kal_uint32 key_len)
{
   kal_uint32 Asym_Decrypt_Failed = 0;

#ifdef _BL_ALG_DEBUG_
   dbg_print("bl_Alg_Asym_Decrypt(%x, %x, %d, %x, %d)\n\r", dest_addr, src_addr, len, key, key_len);
#endif /*_BL_ALG_DEBUG_ */

#ifndef _BL_ALG_SKIP_
   if (RSA_Encode(dest_addr, src_addr, len, key, key_len) != KAL_TRUE)
   {
      dbg_print("RSA decryption: failed\n\r");
      ASSERT(Asym_Decrypt_Failed);
   }
#endif /* _BL_ALG_SKIP_ */

   return KAL_TRUE;
}

#endif /* __SECURE_USB_DOWNLOAD__ || __SECURE_UART_DOWNLOAD__ || __CARD_DOWNLOAD__ */

kal_uint32 bl_Alg_Copy_Func_Tbl(kal_uint32 dest_addr)
{
#if defined(__SECURE_USB_DOWNLOAD__) || defined(__SECURE_UART_DOWNLOAD__)

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

   kal_uint32 i;
   kal_uint32 *pSrc = (kal_uint32*)(&g_BlFunc_Table);
   kal_uint32 *pDst = (kal_uint32*)dest_addr;
   for ( i=0; i<(sizeof(g_BlFunc_Table)+3)/4; i++ )
   {
      *pDst = *pSrc;
      pSrc++;
      pDst++;
   }

#else

   dest_addr = (kal_uint32)&g_BlFunc_Table;

#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

#if defined(__SV5_ENABLED__)
   //Prepare data for DA usage
   {
      kal_uint32 *pFuncTblAddr = (kal_uint32*) bl_Allocate_BL_DA_SharedData(BL_DA_SHARED_DATA_ID_FUNC_TBL_ADDR, 4);

      //Pass the address of func tbl string to DA
      *pFuncTblAddr = dest_addr + sizeof(g_BlFunc_Table) - sizeof(g_BlFunc_Table.m_func_table_id);
   }
#endif

#endif /* __SECURE_USB_DOWNLOAD__ */

   return 0;
}

kal_bool bl_Alg_SignatureVerify(kal_uint32 addr, kal_uint32 len, kal_uint32 sig_addr, kal_uint32 sig_len)
{
#if defined(__SECURE_USB_DOWNLOAD__) || defined(__SECURE_UART_DOWNLOAD__)
   kal_uint8 *dest_addr = (kal_uint8 *)addr;
   kal_uint8 *sig = (kal_uint8 *)sig_addr;
   kal_uint8 *key = (kal_uint8 *)&Image$$EXT_READ_WRITE$$ZI$$Limit;
   kal_uint32 key_len;
   kal_uint8 hash[20];
   char sig_buf[32];
   kal_uint32 Sig_Verify_Failed = 0;
   
#ifdef _BL_ALG_DEBUG_
   dbg_print("bl_Alg_SignatureVerify(%x, %d, %x, %d)\n\r", addr, len, sig_addr, sig_len);
#endif /*_BL_ALG_DEBUG_ */

   /* Use the customer symmetric key to decrypt the binary image content */
   key_len = custom_get_symmetric_key(key, 128);
#ifndef _BL_ALG_SKIP_
   ASSERT(key_len > 0);
#endif /* _BL_ALG_SKIP_ */
   bl_Alg_Sym_Decrypt((kal_uint32)dest_addr, addr, len, (kal_uint32)key, key_len);
   /* Use the customer asymmetric key to decrypt the signature */
   key_len = custom_get_asymmetric_key(key, NVRAM_ASYMMETRIC_KEY_MAX_SIZE);
#ifndef _BL_ALG_SKIP_
   ASSERT(key_len > 0);
#endif /* _BL_ALG_SKIP_ */
   bl_Alg_Asym_Decrypt((kal_uint32)sig_buf, sig_addr, sig_len, (kal_uint32)key, key_len);
   /* Calculate the hash value */
   bl_Alg_Hash_Init();
   bl_Alg_Hash_Append((kal_uint32)dest_addr, len);
   bl_Alg_Hash_Finish((kal_uint32)hash, sizeof(hash));
   /* Compare the hash value */
   if (memcmp(hash, sig_buf, sizeof(hash)) != 0)
   {
#ifndef _BL_ALG_SKIP_
      ASSERT(Sig_Verify_Failed);
#endif /* _BL_ALG_SKIP_ */
   }
#endif /* __SECURE_USB_DOWNLOAD__ || __SECURE_UART_DOWNLOAD__ */
   
   return KAL_TRUE;
}

