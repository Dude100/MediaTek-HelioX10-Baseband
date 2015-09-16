/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
* Filename:
* ---------
*    DigitalSignature.cpp
*
* Project:
* --------
*    X-download  
*
* Description:
* ------------
*   Digital signature functions 
*
* Author:
* -------
*    
*
*******************************************************************************/
#include "DigitalSignature.h"
#include <stdio.h>

/*
 *  This function should return the exact digital signature digest length (hash algorithm output hash data length)
 *  e.g SHA1 is 20 bytes
 */
unsigned int __stdcall DigestLen(void)
{
    return 0;
}

/*
 *  This function should be implemented as the initial function of hash algorithm 
 *  Please refer to the document
 *  return value: true (success)/false(failure)
 *  default: return false, need customer to modify 
 */
bool __stdcall HashInit(void) 
{    

    return false;
}

/*
 *  This function should be implemented as the append function of hash algorithm for batch data input
 *  Please refer to the document
 *  input: 
 *      addr: pointer to the data to be hashed
 *      len:  length of the data
 *  return value: 
         true (success)/false(failure)
 *       default: false, need customer to modify 
 */
bool __stdcall HashAppend(unsigned int addr, unsigned int len)
{

    return false;
}

/*
 *  This function should be implemented as the generated function of hash algorithm for digest data
 *  Please refer to the document 
 *  return value: true (success)/false(failure)
 *  default: return false, need customer to modify 
 */
bool __stdcall HashFinish(unsigned int digest, unsigned int len)
{

    return false;
}

/*
 *  This function should be implemented as asyc encryption function
 *  Please refer to the document
 *  return value: true (success)/false(failure)
 *  default: return false, need customer to modify 
 */
bool __stdcall AsymEncrypt(unsigned int dest_addr, unsigned int src_addr, unsigned int len, unsigned int key, unsigned int key_len)
{
 
    return false;
}

/*
 *  This function should be implemented as asyc decryption function
 *  Please refer to the document
 *  return value: true (success)/false(failure)
 *  default: return false, need customer to modify 
 */
bool __stdcall AsymDecrypt(unsigned int dest_addr, unsigned int src_addr, 
                           unsigned int len, unsigned int key, unsigned int key_len)
{

    return false;
}

/*
 *  This function should return the key address
 *  Please refer to the document
 *  
 */
unsigned int* __stdcall GetKeyAddr()
{

    return 0;
}

/*
 *  This function should return the key length in bytes
 *  
 */
unsigned int __stdcall GetKeyLen()
{

    return 0;
}

/*
 *  This function should return the digital signature length in bytes
 *  
 */
unsigned int __stdcall GetSigLen()
{

    return 0;
}

/*
 *  This function should do the hash + encryption function to provide digital signature function.
 *  return value: true (success)/false(failure)
 *  default: return false, need customer to modify 
 *
 */
bool __stdcall Sign(unsigned char *content, unsigned int contentLen, unsigned char* signature)
{	
    return false;
}


