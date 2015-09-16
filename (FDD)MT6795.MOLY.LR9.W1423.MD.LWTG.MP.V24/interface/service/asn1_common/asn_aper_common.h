/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 * $Log:$
 * 
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * for msbb2
 *
 * removed!
 * removed!
 * for msbb2
 *
 ****************************************************************************/

#if !defined _ASN_APER_COMMON_H_
#define _ASN_APER_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "asn_common.h"
#include "asn_memory.h"
#include "mtkasn_global.h"


extern void AperEncodeOID(AsnContext *pContext,  OID *pOid);
extern void AperDecodeOID(AsnContext *pContext,  OID *pOid);

extern void AperEncodeBitString(AsnContext *pContext, U32 lBound, U32 uBound, U8 *pData, U32 uLen);
extern U32  AperDecodeBitString(AsnContext *pContext, U32 lBound, U32 uBound, U8 *pData);

extern void AperEncodeOpenType(AsnContext *pContext,  U8 * pData, U32 uSize);
extern U32 AperDecodeOpenTypeLength(AsnContext *pContext);
extern U32 AperDecodeOpenType(AsnContext *pContext,  U8 * pData, U32 uSize);

extern void AperPutNonConstraintNumber(AsnContext *pContext,  S32 uNum);
extern S32 AperGetNonConstraintNumber(AsnContext *pContext);

extern U32 AperPutLengthValue(AsnContext *pContext, U32 lBound, U32 uBound, U32 uLen);
extern U32 AperGetLengthValue(AsnContext *pContext, U32 lBound, U32 uBound);

extern void AperPutSmallNumber(AsnContext *pContext, U32 uNum);
extern U32 AperGetSmallNumber(AsnContext *pContext);

extern void AperPutSemiConstraintNumber(AsnContext *pContext, S32 lBound, S32 uNum);
extern S32 AperGetSemiConstraintNumber(AsnContext *pContext, S32 lBound);

extern void AperPutWholeConstraintNumber(AsnContext *pContext, S32 lBound, S32 uBound, U32 uNum);
extern U32 AperGetWholeConstraintNumber(AsnContext *pContext, S32 lBound, S32 uBound);


// APER STRING Encode function
extern void  AperEncodeGeneralString(AsnContext *pContext,  asn_GeneralString *pStr);
extern void  AperEncodeBMPString(AsnContext *pContext,  asn_BMPString *pStr, U32 minSize, U32 maxSize, ASN_TwoByteAlphabet  *pAlphabet);
extern void  AperEncodeIA5String(AsnContext *pContext,  asn_IA5String *pStr, U32 minSize, U32 maxSize, ASN_OneByteAlphabet  *pAlphabet);
extern void  AperEncodeNumericString(AsnContext *pContext,  asn_NumericString *pStr, U32 minSize, U32 maxSize, ASN_OneByteAlphabet  *pAlphabet);
extern void  AperDecodeNumericStringA(AsnContext *pContext,  asn_NumericString *pStr, U32 minSize, U32 maxSize, ASN_OneByteAlphabet  *pAlphabet);
extern void	AperDecodeIA5StringA(AsnContext *pContext,  asn_IA5String *pStr, U32 minSize, U32 maxSize, ASN_OneByteAlphabet  *pAlphabet);
extern void	AperDecodeBMPStringA(AsnContext *pContext,  asn_BMPString *pStr, U32 minSize, U32 maxSize, ASN_TwoByteAlphabet  *pAlphabet);
extern void	AperDecodeGeneralStringA(AsnContext *pContext,  asn_GeneralString *pStr);
extern void	AperDecodeChoiceUnKnowItem(AsnContext *pContext, ChoiceUnKnow *pUnKnowItem);
extern void	AperDecodeSequcenceUnKnowItem(AsnContext* pContext,  UnKnowExtensionItemArray *pArray, U32	uSize, Bool  *pIsItemExist);
extern S32	GetAlphabetIndex(ASN_OneByteAlphabet *pAlphabet, char *pChar);

extern  U32  GetNumberBitLength(U32  Data);
extern  Bool IsReindexOneByteAlphabet(ASN_OneByteAlphabet *pAlphabet);
extern  U32  GetOneByteCharacterBitWidth(ASN_OneByteAlphabet *pAlphabet);

	
#ifdef __cplusplus       
}
#endif
#endif //_ASN_APER_COMMON_H_
