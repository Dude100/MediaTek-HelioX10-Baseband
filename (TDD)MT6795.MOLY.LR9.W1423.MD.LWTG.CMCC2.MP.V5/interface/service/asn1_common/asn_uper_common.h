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

#if !defined ASN_UPER_COMMON_H_
#define ASN_UPER_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "asn_common.h"
#include "asn_memory.h"
#include "mtkasn_global.h"


/* here move from old aper header */
/* nick add */

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else

#define		APER_ALIGN		do{		\
									if (0 != (pContext->shiftRegisterLength)%8) {			\
									putShortBits( pContext, 8 - (pContext->shiftRegisterLength)%8 , 0);	\
									}	\
							}while(0);
	
#define		APER_CLEAR_ALIGN_BITS	getShortBits( pContext, pContext->shiftRegisterLength);


#define		UPER_BEGIN_PRE_ENCODE       BEGIN_PRE_ENCODE
#define	  UPER_END_PRE_ENCODE         END_PRE_ENCODE
#define   UPER_BEGIN_PRE_DECODE_EXT   BEGIN_PRE_DECODE_EXT
#define   UPER_END_PRE_DECODE_EXT     END_PRE_DECODE_EXT


#endif



extern   void   UperEncodeOID(AsnContext *pContext,  OID *pOid);
extern   void   UperDecodeOID(AsnContext *pContext,  OID *pOid);
extern   void	UperEncodeOpenType(AsnContext *pContext,  U8 * pData, U32 uSize);
extern   U32	UperDecodeOpenTypeLength(AsnContext *pContext);
extern   U32	UperDecodeOpenType(AsnContext *pContext,  U8 * pData, U32 uSize);

extern   void   UperPutNonConstraintNumber(AsnContext *pContext,  S32 uNum);
extern   S32    UperGetNonConstraintNumber(AsnContext *pContext);

extern   U32    UperPutLengthValue(AsnContext *pContext, U32 lBound, U32 uBound, U32 uLen);
extern   U32	UperGetLengthValue(AsnContext *pContext, U32 lBound, U32 uBound);

extern   void   UperPutSmallNumber(AsnContext *pContext, U32 uNum);
extern   U32	UperGetSmallNumber(AsnContext *pContext);

extern   void   UperPutSemiConstraintNumber(AsnContext *pContext, S32 lBound, S32 uNum);
extern   S32	UperGetSemiConstraintNumber(AsnContext *pContext, S32 lBound);

extern   void   UperPutWholeConstraintNumber(AsnContext *pContext, S32 lBound, S32 uBound, U32 uNum);
extern   U32    UperGetWholeConstraintNumber(AsnContext *pContext, S32 lBound, S32 uBound);

extern   void UperEncodeGeneralString(AsnContext *pContext,  asn_GeneralString *pStr);
extern   void UperEncodeBMPString(AsnContext *pContext,  asn_BMPString *pStr, U32 minSize, U32 maxSize, ASN_TwoByteAlphabet  *pAlphabet);
extern   void UperEncodeNumericString(AsnContext *pContext,  asn_NumericString *pStr, U32 minSize, U32 maxSize, ASN_OneByteAlphabet  *pAlphabet);
extern   void UperDecodeNumericStringA(AsnContext *pContext,  asn_NumericString *pStr, U32 minSize, U32 maxSize, ASN_OneByteAlphabet  *pAlphabet);
extern   void UperDecodeBMPStringA(AsnContext *pContext,  asn_BMPString *pStr, U32 minSize, U32 maxSize, ASN_TwoByteAlphabet  *pAlphabet);
extern   void UperDecodeGeneralStringA(AsnContext *pContext,  asn_GeneralString *pStr);
extern   void UperDecodeChoiceUnKnowItem(AsnContext *pContext, ChoiceUnKnow *pUnKnowItem);
extern   void UperDecodeSequcenceUnKnowItem(AsnContext* pContext,  UnKnowExtensionItemArray *pArray, U32	uSize, Bool  *pIsItemExist);

#ifdef __cplusplus  
}
#endif

#endif //_UPER_COMMON_H_

