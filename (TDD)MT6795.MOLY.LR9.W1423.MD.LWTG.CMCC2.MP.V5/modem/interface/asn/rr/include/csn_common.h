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
*	csn_common.h  : header file
*
* Project:
* --------
*  csn.1 common ------ CSN.1 common file
*
* Description:
* ------------
*  This file defines the data structures for csn common functions
*  If user want to modify the file, please discuss with the owner
*
* Author:
* -------
 * -------
*
*******************************************************************************/

#ifndef _CSN_COMMON_H_
#define _CSN_COMMON_H_

#ifdef __cplusplus
 extern "C" {
#endif
 
//#include <string.h> 
//#include <stdlib.h> 
//#include <setjmp.h>

#include "mtkcsn_global.h"
#include "error_struct_enum.h"

/*Evelyn: Remove redundant header and file */
#include "asn1lib.h"
#include "as_common.h"

#ifdef _CSN_TEST_
  #include <time.h>
  #include <stdarg.h>
  #include <stdio.h>
  #include <assert.h>
  #define DSVALUEINFO ".\\dsvalueinfo.txt"
  #define DLLEXPORT __declspec( dllexport ) 

  //#define _CSN_RANDOM_TEST_  //for random encode test //this was removed to "csn_macro_define.h"
 
#else
  #define DLLEXPORT

#ifdef _CSN_DEBUG_ON_TARGET_
  TRC_MSG(CSN_WARNING_INFO, "[CSN] trace: %s %d.")
#endif

#endif 

#ifdef _CSN_TEST_
typedef enum
{
	ABSENT=0,
	PRESENT
}ispresent;  
#endif
 
typedef enum
{
	SINGLE_L=0,
	SINGLE_H
}isLHpresent;
  
#ifdef _CSN_TEST_
//follow is for error struct
typedef struct AsnListNode
{
    struct AsnListNode	*prev;
    struct AsnListNode	*next;
    void		*data;		 
}AsnListNode; 

typedef struct AsnList
{
    AsnListNode		*first;
    AsnListNode		*last;
    AsnListNode		*curr;
    int			count;	 
    int			dataSize;	 
}AsnList; 

typedef enum ErrorDetail {
    SPARE_ERROR,
    OUT_OF_RANGE_ERROR,
    IGNORE_FUNCTION
} ErrorDetail; 
#endif

typedef struct CSN_ErrorStruct {
    CSN_ErrorType    error_type; //here is different from ErrorStruct
    asn_error_detail  error_flag;
    int          structNameEnum;
    asn_list      cond_errors;  
    int          comp_req;
//    int   errorlineno;
//    S8  errorfile[1024];
}CSN_ErrorStruct;
 

#ifndef NOT_USED
#define NOT_USED(x) (void)(x)
#endif
 
#ifndef UA1_ERROR_1   
#define UA1_ERROR_1() CsnError1(pContext, (S8 *)__FILE__, __LINE__) 
#endif 
 
#define	INFINIT_EXPONENT_INIT_SIZE 2  //initial allocate memory size
#define INFINIT_EXPONENT_INC_SIZE  2  //increase size for every time
 
#define MAX_TOLERABLE_MEM_BLOCK_NUM       20         //should greater than 4
#define MAX_TOLERABLE_MEM_BLOCK_INC_SIZE  (5*4)  //multiple of 4 bytes

#define MAX_U32 0xffffffff

typedef struct
{ 
	S8 * name; //label
	U8 * value;
	U32 length;    
}FunctionInfoNode;
 
typedef struct
{
	FunctionInfoNode fin;
    struct FunctionInfoList *ppNext;
}FunctionInfoList;
 
typedef struct
{
   void *pMemBlock[MAX_TOLERABLE_MEM_BLOCK_NUM];
   void **ppNext;
   void **ppEnd;  
}CsnAllocRecord;

/*
typedef struct
{
	jmp_buf env;
    struct JmpBufList *ppNext;  
}JmpBufList;
*/
 
#ifdef _CSN_TEST_ 
  #include <setjmp.h>
  #define csn_jmpbuf jmp_buf  
#else 
  #if defined(__MTK_TARGET__) && defined(__RVCT__)
    typedef long long csn_jmpbuf[17];
  #elif defined(__MTK_TARGET__)
    typedef int csn_jmpbuf[17];
  #else
	
	///add for vc9.0 
	//vc 9.0 have un-standard code , cgen could not pass the parse
	// GEN_FOR_PC: just defined when codegen_modis
    #ifndef GEN_FOR_PC 
      #include <setjmp.h>
    #else
      #define _JBLEN 16
      #define _JBTYPE int
	  typedef _JBTYPE jmp_buf[_JBLEN];
    #endif  
	///
    #define csn_jmpbuf jmp_buf  	

  #endif 
#endif 
  

typedef struct
{ 
   U8 *pEncoded;
   U8 *pEncodedEnd;
   U32 limitBitLength; //for user defined buffer bit length 
   csn_jmpbuf env;
   void *encodeAlloc; 
   CsnAllocRecord *decodeAlloc; 
   FunctionInfoList *fil;  // for csn function 
}CsnContext;
   
 
typedef U32 (*FP_EN)(U8 *frame, void *pmtk_d, U32 bit_offset, U32 frame_size, CsnContext *pParentContext);
typedef U32 (*FP_DE)(void *pmtk_d, U8 *frame, U32 bit_offset, U32 frame_size, void *err_hndl, CsnContext *pParentContext);
#define TEST_CASE_NUM 10000

#ifdef _CSN_TEST_

U32 csn_act_mask(U32 width);
U32 get_bits(U8 *frame, U32 offset, U32 width);
U32 get_bits_1_8(U8 *addr, U32 offset, U32 width);
U32 get_bits_9_16(U8 *addr, U32 offset, U32 width);
U32 get_bits_17_24(U8 *addr, U32 offset, U32 width);
U32 get_bits_25_32(U8 *addr, U32 offset, U32 width);

void put_bits_25_32(U8 *addr, U32 bitoffset, U32 bitlength, U32 data);
void put_bits_17_24(U8 *addr, U32 bitoffset, U32 bitlength, U32 data);
void put_bits_9_16(U8 *addr, U32 bitoffset, U32 bitlength, U32 data);
void put_bits_1_8(U8 *addr, U32 bitoffset, U32 bitlength, U32 data);
void put_bits(U8 *addr, U32 bitoffset, U32 bitlength, U32 data);

#endif
U16 get_16bits_L_endian_2_B_endian(U8 *addr, U32 offset);

extern void update_addr_n_offset(kal_uint8 **addr, kal_uint32 *offset_ptr, kal_uint32 width);

extern void put_bits_slim(kal_uint8 **addr, kal_uint32 *offset_ptr, kal_uint32 width, kal_uint32 put_val);
extern void put_bits_1_8_slim(kal_uint8 **addr, kal_uint32 *offset_ptr, kal_uint32 width, kal_uint32 put_val);
extern void put_bits_9_16_slim(kal_uint8 **addr, kal_uint32 *offset_ptr, kal_uint32 width, kal_uint32 put_val);
extern void put_bits_17_24_slim(kal_uint8 **addr, kal_uint32 *offset_ptr, kal_uint32 width, kal_uint32 put_val);
extern void put_bits_25_32_slim(kal_uint8 **addr, kal_uint32 *offset_ptr, kal_uint32 width, kal_uint32 put_val);

extern kal_uint32 get_bits_slim(kal_uint8 **addr, kal_uint32 *offset_ptr, kal_uint32 width);
extern kal_uint32 get_bits_1_8_slim(kal_uint8 **addr, kal_uint32 *offset_ptr, kal_uint32 width);
extern kal_uint32 get_bits_9_16_slim(kal_uint8 **addr, kal_uint32 *offset_ptr, kal_uint32 width);
extern kal_uint32 get_bits_17_24_slim(kal_uint8 **addr, kal_uint32 *offset_ptr, kal_uint32 width);
extern kal_uint32 get_bits_25_32_slim(kal_uint8 **addr, kal_uint32 *offset_ptr, kal_uint32 width);

U32 get_spare_bits(U8 *frame, U32 bit_offset, U32 numBits, U32 frame_size, void *err_hndl, CsnContext *pContext);
U32 get_spare_padding(U8 *frame, U32 bit_offset, U32 numBits, U32 frame_size, void *err_hndl, CsnContext *pContext);
U32 get_padding_bits(U8 *frame, U32 bit_offset, U32 numBits, U32 frame_size, void *err_hndl, CsnContext *pContext);


DLLEXPORT void CsnRootDecodeFree( void *pType); 
DLLEXPORT void CsnRootDecodeAlloc( void **ppType, U32 size ); 
DLLEXPORT void CsnDecodeAlloc( CsnContext *pContext, void **ppMem, U32 size ); 
DLLEXPORT void CsnDecodeFree( CsnAllocRecord *decodeAlloc);

void ** CsnFindInMemList(CsnContext *pContext, void **ppMem);
void CsnDeleteMemMarkFromList(CsnContext *pContext, void ** ppMem );
void CsnDecodeReAlloc( CsnContext *pContext, void **ppMem, U32 newsize, U32 oldsize);
void CsnRootEncodeAutoAlloc(CsnContext *pContext); //
void CsnRootEncodeAutoFree (CsnContext *pContext); //
void CsnBitFieldCopy(U8 * new_frame, U32 new_bit_offset, U8 * old_frame, U32 bit_offset,U32 copylength);

 
void csn_init_ErrorStruct(void * err_hndl);
void csn_set_ErrorStruct(void * err_hndl, enum_error_struct_type errorstructname,CSN_ErrorType errortype);
void csn_set_ErrorStruct1(CsnContext * pContext, void * err_hndl, enum_error_struct_type errorstructname,CSN_ErrorType errortype);

void clear_csn_function_from_list(S8 * name, CsnContext * pContext);   
void add_to_csn_function_list(S8 * name, U8 * value, U32 length, CsnContext * pContext);   
//Bool special_function_handle(S8 * name, U8 * value, U32 length, CsnContext * pContext);
//void special_deal_with_reserve_max_value(S8 * name, U8 * value, U32 length, CsnContext * pContext);

void CsnError1( CsnContext *pContext, S8 * file, U32 line );

void csn_initFifo( CsnContext *pContext, U8 *buffer, U32 bufferByteLength );  
void csn_getLongBits(U8 * frame, U32 bits, U32 bitoffset, U8 *outputBuffer, U32 numBits);
void csn_putLongBits(U8 * frame, U32 bits, U32 bitoffset, U8 *data, U32 numBits );
  
//for match L\H string or encode L\H string 
U8  match_LH(CsnContext *pContext, U32 bitoffset, U8 value, S8 * pLHString);
void put_LH(CsnContext *pContext, U8 *frame, U32 bit_offset, S8 * pLHString);


U32 put_spare_bits(U8 *frame, U32 bit_offset, U32 numBits, U32 frame_size, CsnContext *pContext);
U32 put_spare_padding(U8 *frame, U32 bit_offset, U32 numBits, U32 frame_size, CsnContext *pContext);
U32 put_padding_bits(U8 *frame, U32 bit_offset, U32 numBits, U32 frame_size, CsnContext *pContext);
 
///user defined functions // mapping to csn.1 functions
U32 val(S8 * label, CsnContext * pContext);
U32 len(S8 * label, CsnContext * pContext);
//U32 fdd_cell_info_p(S8 * label, CsnContext * pContext);
//U32 tdd_cell_info_q(S8 * label, CsnContext * pContext);
//U32 max_val(S8 * label, CsnContext * pContext);

//U32 n(S8 * label, CsnContext * pContext);
//U32 m(S8 * label, CsnContext * pContext);

///for test  
#ifdef _CSN_TEST_
int OutputDSValueInfo(const S8 *ptext, ...);
int OutputTestInfo(const S8 *ptext, ...); 
int csn_rand_u32(void); 
void csn_rand_buffer(U8 * pBuffer, U32 numBits);
#endif
///

 

#ifdef __cplusplus
}
#endif
#endif /* _CSN_COMMON_H */
