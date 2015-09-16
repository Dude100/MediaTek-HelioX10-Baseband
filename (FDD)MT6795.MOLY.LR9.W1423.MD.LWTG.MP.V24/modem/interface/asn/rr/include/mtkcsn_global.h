/*******************************************************************************
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
*  BUYER'S SOLE AND EXCLUSIVE REME DY AND MEDIATEK'S ENTIRE AND CUMULATIVE
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
*	mtkcsn_global.h  : header file
*
* Project:
* --------
*  csn.1 common ------ CSN.1 common file
*
* Description:
* ------------
*  This file defines the basic data type
*  If user want to modify the file, please discuss with the owner
*
* Author:
* -------
 * -------
*
*******************************************************************************/
#if !defined _CSN_GLOBAL_H_
#define _CSN_GLOBAL_H_

/*Evelyn: Remove redundant header and file */
#include "kal_general_types.h"
#include "as_common.h"

#ifdef __cplusplus
extern "C" {
#endif
  

//#define _CSN_TEST_    //if no need any more, comment this marco
//#define  MCD_DLL_EXPORT 


#ifdef _CSN_TEST_

#include "csn_macro_define.h"

#define  ASSERT(x)   assert(x) 

typedef  unsigned char   U8;
typedef  unsigned short  U16;
typedef  unsigned int    U32;
typedef  U8			     Bool;

 
typedef	 char	S8;
typedef	 short	S16;
typedef	 int	S32;

 
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
 
#ifndef NULL
#define NULL (void *)0
#endif


#else

#include "rr_common_headers.h"

typedef  kal_uint8   U8;
typedef  kal_uint16  U16;
typedef  kal_uint32  U32;
#ifndef Bool    
typedef  kal_uint8   Bool;
#endif

 
typedef	 kal_int8     S8;
typedef	 kal_int16 	S16;
typedef	 kal_int32 	S32;


#ifndef TRUE
#define TRUE KAL_TRUE
#endif
#ifndef FALSE
#define FALSE KAL_FALSE
#endif
 
#ifndef NULL
#define NULL (void *)0
#endif

#endif

#ifdef __cplusplus   
}
#endif
#endif //_CSN_GLOBAL_H_
