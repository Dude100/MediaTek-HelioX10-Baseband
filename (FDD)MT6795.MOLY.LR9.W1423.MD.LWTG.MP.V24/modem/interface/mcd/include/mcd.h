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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	mcd.
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MediaTek Coding/Decoding engine header file. (2002.11.11)
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *==============================================================================
 *******************************************************************************/

#ifndef _MCD_H
#define _MCD_H

//------------------------------ suggest Add ------------------------------
#include "kal_general_types.h"

#include "mcd_public_api.h"

#define MCD_ERROR ((kal_uint32)-1)
#define MCD_INVALID_STRUCT_ID ((kal_uint16)-1)

#ifdef MCD_DLL
	#define MCDDLL_API typedef __declspec(dllimport)
	#define _DECLARE_(f) (* f##_func)
#elif  defined(MCD_DLL_EXPORT)
	#define MCDDLL_API __declspec(dllexport)
	#define _DECLARE_(f) f
	#define MCD_ENABLE_QUERY
	//#define kal_trace
	//#define MCD_OUTSIDE_TABLE
#else
	#define MCDDLL_API extern
	#define _DECLARE_(f) f
#endif

#define MCD_L3_MESSAGE_ERROR_HANDLE
#define MCD_PD_CC (3)
#define MCD_PD_INVALID (255)
#define SET_MCD_PD(x) mcd_pd=x

extern kal_uint8 mcd_pd;

#ifdef __MCD_CODESET_SHIFT__ 
MCDDLL_API void _DECLARE_(mcd_update_plmn)(kal_uint8,kal_uint8,kal_uint8,kal_uint8,kal_uint8,kal_uint8);
#endif

MCDDLL_API kal_uint32 _DECLARE_(mcd_pseudo_alloc)(kal_uint16 msgid,kal_uint32 *dest,kal_uint32 dest_size);
MCDDLL_API kal_uint32 _DECLARE_(mcd_pack)(kal_uint16 msgid,kal_uint32 *dest,kal_uint32 dest_size,kal_uint8 *src);
MCDDLL_API kal_uint32 _DECLARE_(mcd_unpack)(kal_uint16 msgid,kal_uint32 *dest,kal_uint32 dest_size,kal_uint32 *src,kal_uint32 total_bits);

MCDDLL_API kal_uint16 _DECLARE_(mcd_get_structure_id)(const kal_uint8 * struct_name);
MCDDLL_API const kal_uint8 * _DECLARE_(mcd_get_structure_name)(kal_uint16 structid);
MCDDLL_API kal_uint16 _DECLARE_(mcd_find_structure_id)(kal_uint32 msg_id,kal_uint8 *src,kal_uint32 total_bits);

#undef DECLARE

typedef enum
{
	MCD_UNKNOWN_ERROR=1, 
	MCD_COMPREHENSION_ERROR,
	MCD_UNKNOWN_OPCODE_ERROR,
	MCD_UNPACK_NEED_MORE_BITSTREAM_ERROR,
	MCD_UNPACK_USE_THE_SAME_ADDRESS_ERROR,
	MCD_PACK_USE_THE_SAME_ADDRESS_ERROR,
	MCD_BUFFER_MUST_START_AT_4_ALIGNMENT_ERROR,
	MCD_REPEAT_IEI_UNKNOWN_ERROR,
	MCD_ALLOCATE_SEGMENT_OVERFLOW_ERROR,
	MCD_ALLOCATE_MEMORY_NOT_ENOUGH_ERROR,
	MCD_LOST_ENDIF_ERROR,
	MCD_LOST_ENDBERIF_ERROR,
	MCD_FREE_SEGMENT_ERROR,
	MCD_PACK_BUFFER_OVERFLOW_ERROR,
	MCD_RESIZE_MEMORY_NOT_ENOUGH_ERROR,
	MCD_ILLEGAL_SEGMENT_ADDRESS_ERROR,
	MCD_NULL_POINTER_ASSIGNMENT_ERROR, 
	MCD_POINTER_OUT_OF_RANGE_ERROR,
	MCD_CANT_FIND_THE_END_OF_INFINITE_MARK,
  MCD_MANDATORY_IE_LENGTH_INVALID,
  MCD_OPTIONAL_IE_LENGTH_INVALID	
} mcd_error_enum;

typedef struct
{
	kal_uint8 errorno; // mcd_error_enum
	kal_uint16 op_start;
	kal_uint16 op_pos;
} mcd_error_struct;

/* how many pointers are contained in each structure? 
   (include recursive structure reference)*/

#define SASKEN_STRUCT_START     MCD_TABLE_SIZE + 2000
#define UB_PEER_STRUCT_START    MCD_TABLE_SIZE + 4000
#define UB_DB_STRUCT_START      MCD_TABLE_SIZE + 6000
#define UB_EXTRA_STRUCT_START   MCD_TABLE_SIZE + 8000
#define NAS_STRUCT_START        MCD_TABLE_SIZE + 10000
#define MA_STRUCT_START         MCD_TABLE_SIZE + 12000
#define ERRC_STRUCT_START       MCD_TABLE_SIZE + 14000
#define EL1_STRUCT_START        MCD_TABLE_SIZE + 16000
#define LPP_STRUCT_START        MCD_TABLE_SIZE + 17000

// opcode enum
typedef enum
{
    // general & ASN command
    END,
    MCD_IGNORE,
    BITS,
    //BITS_ARRAY,
    BYTES,
	//BYTES16,
	//MAXBITS,
    MAXBYTES,
	//MAXBYTES16,
    CHOICE,
    CALL,
	REFCALL,
    IF,
    ARRAYSTRUCT,
    MAXSTRUCT,
    CASE,
    BACKWARD,
    EXT_TI,
    BREAK,
    ENDCHOICE,

    // ACT command
    BER_NUMSTRING,
    BER_BYTES,
    BER_MAXIA5STRING,
    BER_OID,
    BER_INTEGER,
    BER_BOOLEAN,
    BER_ENUM,
    BER_MAXBYTES,
    BER_SEQUENCE,
	BER_SET,
    BER_NULL,
    BER_TAG,
    BER_IF,
    BER_MAXSTRUCT,
    BER_OPTIONAL,
    BER_CASE,
    BER_CASE_TRY,
	BER_ANY,

    IEI_LIST,
	INFINITE_CALL,
	PADDING_BITS,
	CSN_TAG,
	SPARE_BITS,
#ifdef __MCD_CODESET_SHIFT__ 
  IEI_SHIFT_CHK,
#endif
    MCD_OP_SUM,

    ENDBER_SEQUENCE,
    ENDBER_IF,
    ENDIF
} mcd_op_enum;

#include "mcd_l3.h"
#include "mcd_l4.h"

#endif // _MCD_H
