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

#include "kal_public_api.h"
#include "asn_memory.h"
#include "asn_common.h"
#include "asn_uper_common.h"

/************************************************************************/
/*         UPER    Encode   Tools  Function                             */
/************************************************************************/

extern void UperPutSmallNumber(AsnContext *pContext, U32 uNum)
{
	if (uNum < 64)
	{
		putShortBits(pContext, 1, 0);
		putShortBits(pContext, 6, uNum);
	}
	else
	{
		putShortBits(pContext, 1, 1);
		UperPutSemiConstraintNumber(pContext, 0, uNum);
	}
}

extern U32 UperGetSmallNumber(AsnContext *pContext)
{
	U32 uNum;

	if (0 ==  getShortBits(pContext, 1))
	{
		uNum = getShortBits(pContext, 6);
	}
	else
	{
		uNum = 	UperGetSemiConstraintNumber(pContext, 0);
	}

	return uNum;
}

extern U32 UperPutLengthValue(AsnContext *pContext, U32 lBound, U32 uBound, U32 uLen)
{
	U32 uDistance;
	ASSERT(uBound >= lBound);

	uDistance = uBound - lBound;
	if ((0 == uDistance) & (uDistance <= 65535))
	{
		// Need Not to encode;
		return 0;
	}
	if (uBound < 65536)
	{
		UperPutWholeConstraintNumber(pContext, lBound, uBound, uLen);
	}
	else if (uBound >= 65536)
	{
		if (uLen <= 127)
		{
			putShortBits(pContext, 1, 0);
			putShortBits(pContext, 7, uLen);
		}
		else if (uLen >127 && uLen<=16383)
		{
			putShortBits(pContext, 2, 0x02);
			putShortBits(pContext, 14, uLen);
		}
		else if (uLen>16383)
		{
			//....
		}
	}
	return 0;
}

extern U32 UperGetLengthValue(AsnContext *pContext, U32 lBound, U32 uBound)
{
	U32 ulen = 0, uDistance = uBound - lBound;
	ASSERT(uBound >= lBound);

	if ((0 == uDistance) & (uDistance <= 65535))
	{
		// Need Not to encode;
		return lBound;	
	}

	if (uBound < 65536)
	{
		ulen = UperGetWholeConstraintNumber(pContext, lBound, uBound);
	}
	else if (uBound >= 65536)
	{
		if (0 == testGetShortBits(pContext, 1))
		{
			// Len < 127
			ulen = getShortBits(pContext, 8);
		}
		else if (0x02 == testGetShortBits(pContext, 2))
		{
			// uLen >127 && uLen<=16383
			getShortBits(pContext, 2);
			ulen = getShortBits(pContext, 14);
		}
		else
		{
			// uLen>16383  ...
		}
	}
	return ulen;
}

extern  void UperPutWholeConstraintNumber(AsnContext *pContext, S32 lBound, S32 uBound, U32 uNum)
{	
	U32		range, bits, temp, i;
	range = uBound - lBound;

	if (0 == range)
	{
		// put no bit 
	}
	else
	{
		temp = 0;
		i = 32;

		while (0 == temp)
		{
			temp = range & 1<<(i-1);
			i--;
		}
		bits = i+1;
		putBits(pContext, bits, (uNum-lBound));
	}
}

extern U32	UperGetWholeConstraintNumber(AsnContext *pContext, S32 lBound, S32 uBound)
{
	U32		range, bits, temp, i, uNum = 0;
	ASSERT(uBound >= lBound);
	range = uBound - lBound;

	if (0 == range)
	{
		// put no bit 
	}
	else
	{
		temp = 0;
		i = 32;
		while (0 == temp)
		{
			temp = range & 1<<(i-1);
			i--;
		}

		bits = i+1;

		uNum = getShortBits(pContext, bits) + lBound;
	}
	return uNum;
}

extern void  UperPutSemiConstraintNumber(AsnContext *pContext, S32 lBound, S32 uNum)
{	
	U32		distance, nByte ;

	if ((lBound > 0 && uNum > 0) || (lBound < 0 && uNum < 0))
	{
		distance = uNum - lBound;
	}
	else
	{
		distance = uNum - lBound;
	}

	nByte = GetNumberOctetLength(distance);
	UperPutLengthValue(pContext, 0, ASN_MAX, nByte);
	putBits(pContext, nByte * 8, distance);
}

extern S32 UperGetSemiConstraintNumber(AsnContext *pContext, S32 lBound)
{	
	U32	sNum, nByte;
	nByte = UperGetLengthValue(pContext, 0, ASN_MAX);

	if (nByte != 0 )
	{
		sNum = getBits(pContext, nByte * 8);
	}
	else
	{
		sNum = 0;
	}

  if (lBound) {/* do nothing*/}
  
	return sNum;
}

extern void UperPutNonConstraintNumber(AsnContext *pContext,  S32 uNum)
{
	int		ulen, nByte, temp;
	ulen = 0;
	temp = 0;

	if (uNum > 0)
	{
		nByte = GetNumberOctetLength(uNum);

		switch(nByte)
		{
		case 1:
			temp = uNum & 0x00000080;
			break;
		case 2:
			temp = uNum & 0x00008000;
			break;
		case 3:
			temp = uNum & 0x00800000;
		    break;
		case 4:
			temp = uNum & 0x80000000;
		    break;
		default:
		    break;
		}

		if (0 != temp)
		{
			ulen = 1;
			putShortBits(pContext, 8, 0);
		}

		ulen += nByte;
		putShortBits(pContext, GetNumberOctetLength(ulen) * 8, ulen);	//Put length


		if (0 != temp)
		{
			putShortBits(pContext, 8, 0);
		}

		putShortBits(pContext, nByte * 8, uNum);
	}
	else
	{
		nByte = GetNumberOctetLength(-uNum);

		uNum = -uNum;
		uNum = ~uNum;
		uNum += 1;

		if (nByte == 1){
			uNum &= 0x000000FF;
		}
		else if (nByte == 2){
			uNum &= 0x0000FFFF;
		}
		else if (nByte == 3){
			uNum &= 0x00FFFFFF;
		}

		putShortBits(pContext, GetNumberOctetLength(nByte) * 8, nByte);	//Put length
		putShortBits(pContext, nByte * 8, uNum);
	}
}

extern S32 UperGetNonConstraintNumber(AsnContext *pContext)
{
	int		nByte;
	S32		uNum = 0;

	nByte = getShortBits(pContext, 8);	//Get length

	if (0 == testGetShortBits(pContext, 1))
	{
		// positive
		if (0 == testGetShortBits(pContext, 8))
		{
			getShortBits(pContext, 8);	
			uNum =  getShortBits(pContext, 8 * (nByte-1));
		}
		else
		{
			uNum =  getShortBits(pContext, 8 * nByte);
		}	
	}
	else
	{
		// negetive
		uNum =  getShortBits(pContext, (8 * nByte));
		uNum--;
		uNum = ~uNum;
		uNum = -uNum;

		if (nByte == 1){
			uNum |= 0xFFFFFF00;
		}
		else if (nByte == 2){
			uNum |= 0xFFFF0000;
		}
		else if (nByte == 3){
			uNum |= 0xFF000000;
		}
	}
	return uNum;
}

extern void UperEncodeOpenType(AsnContext *pContext,  U8 * pData, U32 uSize)
{
	if (uSize > 0)
	{
		UperPutLengthValue(pContext, 0, ASN_MAX, uSize);

		putLongBits(pContext, uSize*8, pData);
	}
}

extern U32 UperDecodeOpenTypeLength(AsnContext *pContext)
{
	return UperGetLengthValue(pContext, 0, ASN_MAX);
}

extern U32 UperDecodeOpenType(AsnContext *pContext,  U8 * pData, U32 uSize)
{
	U32		   uLen;
	AsnContext TempContext = *pContext;

	uLen = UperGetLengthValue(pContext, 0, ASN_MAX);
	if (NULL == pData)
	{
		*pContext = TempContext;
		return uLen;
	}

	getLongBits(pContext, 8 * asn_min(uLen, uSize),  pData);

	// return decode length (by byte)
	return asn_min(uLen, uSize);
}

static void UperEncodeOIDItem(AsnContext *pContext,  U32  uData)
{
	ASSERT(uData < 2097152);
	if (uData < 128)
	{
		putShortBits(pContext,  8, uData);
	}
	else if (uData < 16384)
	{
		// First Octet
		putShortBits(pContext,  1, 1);
		putShortBits(pContext,  7, (uData - uData%128)/128);

		// Second Octet
		putShortBits(pContext,  1, 0);
		putShortBits(pContext,  7, uData%128);
	}
	else if (uData < 2097152)
	{
		// First Octet
		putShortBits(pContext,  1, 1);
		putShortBits(pContext,  7, (uData - uData%16384)/16384);

		// Second Octet
		putShortBits(pContext,  1, 1);
		putShortBits(pContext,  7, ((uData - uData%128)%16384)/128);

		// Third Octet
		putShortBits(pContext,  1, 0);
		putShortBits(pContext,  7, uData%128);
	}
}

static U32 UperDecodeOIDItem(AsnContext *pContext,  U8 **ppData)
{
	U32		uNum = 0;
	U8		uData = **ppData;

	if (uData <= 0x7F)
	{
		uNum = uData;
		(*ppData)++;
	}
	else if (*(*ppData+1)  <= 0x7F)
	{
		// First Octet
		uData &= 0x7F;
		uNum = uData;
		uNum *= 128;

		(*ppData)++;
		uData = **ppData;

		// Second Octet
		uData &= 0x7F;
		uNum += uData;
		(*ppData)++;
	}
	else if (*(*ppData+2) <= 0x7F)
	{
		// First Octet
		uData &= 0x7F;
		uNum = uData;
		uNum *= 128;

		(*ppData)++;
		uData = **ppData;

		// Second Octet
		uData &= 0x7F;
		uNum += uData;
		uNum *= 128; 

		(*ppData)++;
		uData = **ppData;

		// Third Octet
		uData &= 0x7F;
		uNum += uData;

		(*ppData)++;
	}
	else
	{
		UA1_ERROR(10);
	}
	return uNum;
}

extern void UperEncodeOID(AsnContext *pContext, OID *pOid)
{
	U32		ulen, i;
	U8 * pTemp = NULL;

	BEGIN_PRE_ENCODE
	putShortBits(pContext,  8, ((*pOid->value)*40 + (* (pOid->value + 1))));

	for(i=2; i<pOid->valueLen; i++)
	{
		UperEncodeOIDItem(pContext, *(pOid->value + i));
	}

	END_PRE_ENCODE
	UperEncodeOpenType(pContext, (U8 *)pTemp, ulen);

   if (pContext->pMemFreeFunc != NULL)
   {
      pContext->pMemFreeFunc((void **)&pTemp);
   }
   else
   {
	  asnMemFree((void **)&pTemp);
   }
}

extern void UperDecodeOID(AsnContext *pContext, OID *pOid)
{	
	U32	 ulen, i, *pItemOrg;
	U8 * pBuf;// , * pBufOrg;

	ulen = UperDecodeOpenType(pContext, (U8 *)NULL, 0);
	AsnDecodeAlloc(pContext, (void **)&pBuf, ulen);

	//pBufOrg = pBuf;
	UperDecodeOpenType(pContext, (U8 *)pBuf, ulen);

	//Got object Identify Item count
	for (i=1, pOid->valueLen=2; i<ulen; i++)
	{
		if (*(pBuf+i) <= 0x7F )
		{
			(pOid->valueLen)++;
		}
	}

	AsnDecodeAlloc(pContext, (void **)&(pOid->value), (pOid->valueLen)*4);

	pItemOrg = pOid->value;

	if ((*pBuf) <= 39)
	{
		*pOid->value = 0;
	}
	else if ((*pBuf) <= 79)
	{
		*pOid->value = 1;
	}
	else
	{
		*pOid->value = 2;
	}

	*(pOid->value+1) = (*pBuf)%40;
	pBuf++;
	pOid->value += 2;

	for (i=2; i<pOid->valueLen; i++, pOid->value++)
	{
		*pOid->value = UperDecodeOIDItem(pContext, &pBuf);
	}
	pOid->value = pItemOrg;
}

//////////////////////////////////////////////////////////////////////////
// String Encode
//////////////////////////////////////////////////////////////////////////
static void UperEncodeTwoByteString(AsnContext *pContext,  TwoByteString *pStr, U32 minSize, U32 maxSize, ASN_TwoByteAlphabet *pAlphabet)
{
	// If No Constraint 
	U32		i;

	UperPutLengthValue(pContext, minSize, maxSize, pStr->valueLen);
	for(i = 0; i < pStr->valueLen; i++){
		putShortBits(pContext, 8,  GET_U16_HIGH(*(pStr->value+i)) );
		putShortBits(pContext, 8,  GET_U16_LOW(*(pStr->value+i)) );
	}
	if (pAlphabet){/*donothing*/}
}

static void UperDecodeTwoByteStringA(AsnContext *pContext,  TwoByteString *pStr, U32 minSize, U32 maxSize, ASN_TwoByteAlphabet *pAlphabet)
{
	// If No Constraint 
	U32		i;
	U16		uHigh, uLow;

	pStr->valueLen = UperGetLengthValue(pContext, minSize, maxSize);
	AsnDecodeAlloc(pContext, (void **)&pStr->value, pStr->valueLen * 2);

	for(i = 0; i < pStr->valueLen; i++){
		uHigh = (U16)getShortBits(pContext, 8);
		uLow  = (U16)getShortBits(pContext, 8);
		*(pStr->value + i) = MAKE_U16(uHigh, uLow);
	}
	if (pAlphabet){/*donothing*/}
}

//////////////////////////////////////////////////////////////////////////
// Numeric String
extern  void UperEncodeNumericString(AsnContext *pContext,  asn_NumericString *pStr, U32 minSize, U32 maxSize, ASN_OneByteAlphabet *pAlphabet)
{
	// ... ?  Check Characters ?
	U32		i;
	UperPutLengthValue(pContext, minSize, maxSize, pStr->valueLen);
	for(i = 0; i < pStr->valueLen; i++){
		putShortBits(pContext, 4,  *(pStr->value+i) - 47);
	}
	if (pAlphabet){/*donothing*/}
}

extern  void UperDecodeNumericStringA(AsnContext *pContext,  asn_NumericString *pStr, U32 minSize, U32 maxSize, ASN_OneByteAlphabet *pAlphabet)
{
	// ... ?  Check Characters ?
	U32		i;

	pStr->valueLen = UperGetLengthValue(pContext, minSize, maxSize);
	AsnDecodeAlloc(pContext, (void **)&pStr->value, pStr->valueLen);

	for(i = 0; i < pStr->valueLen; i++){
		*(pStr->value+i) = (U8)getShortBits(pContext, 4) + 47;
	}
	if (pAlphabet){/*donothing*/}	
}

//////////////////////////////////////////////////////////////////////////
// BMP String
extern  void UperEncodeBMPString(AsnContext *pContext,  asn_BMPString *pStr, U32 minSize, U32 maxSize, ASN_TwoByteAlphabet *pAlphabet)
{
	// ... ?  Check Characters ?
	UperEncodeTwoByteString(pContext, pStr, minSize, maxSize, pAlphabet);
}

extern  void UperDecodeBMPStringA(AsnContext *pContext,  asn_BMPString *pStr, U32 minSize, U32 maxSize, ASN_TwoByteAlphabet *pAlphabet)
{
	// ... ?  Check Characters ?
	UperDecodeTwoByteStringA(pContext, pStr, minSize, maxSize, pAlphabet);
}

//////////////////////////////////////////////////////////////////////////
// General String
extern  void UperEncodeGeneralString(AsnContext *pContext,  asn_GeneralString *pStr)
{
	UperEncodeOpenType(pContext, (U8 *)pStr->value, pStr->valueLen);
}

extern  void UperDecodeGeneralStringA(AsnContext *pContext,  asn_GeneralString *pStr)
{
	pStr->valueLen = UperDecodeOpenType(pContext, (U8 *)NULL, 0);
	AsnDecodeAlloc(pContext, (void **)&pStr->value, pStr->valueLen);

	UperDecodeOpenType(pContext, (U8 *)pStr->value, pStr->valueLen);
}

extern	void UperDecodeChoiceUnKnowItem(AsnContext *pContext, ChoiceUnKnow *pUnKnowItem)
{
	ChoiceUnKnow	*pUnKnow;
	// In the extension

	AsnDecodeAlloc(pContext, (void **)&pUnKnow, sizeof(ChoiceUnKnow));
	pUnKnow->uIndex =  UperGetSmallNumber(pContext); // Index

	pUnKnow->valueLen = UperDecodeOpenType(pContext, (U8 *)NULL, 0);
	AsnDecodeAlloc(pContext, (void **)&(pUnKnow->value), pUnKnow->valueLen);
	UperDecodeOpenType(pContext, (U8 *)pUnKnow->value, pUnKnow->valueLen);

	pUnKnowItem = pUnKnow;
    
    NOT_USED(pUnKnowItem); //add for clear warning
}

extern void	UperDecodeSequcenceUnKnowItem(AsnContext *pContext,  UnKnowExtensionItemArray *pArray, U32 uSize, Bool  *pIsItemExist)
{
	U32	i, uUnKonwSize;
	U8 *pData;

	AsnDecodeAlloc(pContext, (void **)&(pArray->value), sizeof(UnKnowExtensionItem) * uSize);
	memset(pArray->value, 0, sizeof(UnKnowExtensionItem) * uSize);

	for (i=0; i<uSize; i++)
	{
		if (*(pIsItemExist+i))
		{
			uUnKonwSize = UperDecodeOpenType(pContext, (U8 *)NULL, 0);
			AsnDecodeAlloc(pContext, (void **)&pData, uUnKonwSize);
			UperDecodeOpenType(pContext, (U8 *)pData, uUnKonwSize);
			(pArray->value + i)->valueLen = uUnKonwSize;
			(pArray->value + i)->value = pData;
			pArray->valueLen++;
		}
		else
		{
			(pArray->value + i)->valueLen = 0;
			(pArray->value + i)->value = NULL;
			pArray->valueLen++;
		}
	}
}

extern int	GetPresentBitsNum(unsigned long data)
{
	int		iNum,i;

	for (i=0 , iNum=0; i<32; i++)
	{
		if ((data & 0x00000001) == 1)
		{
			iNum++;
		}
		data >>= 1;
		data &= 0x7FFFFFFF;
	}
	return  iNum;
}
