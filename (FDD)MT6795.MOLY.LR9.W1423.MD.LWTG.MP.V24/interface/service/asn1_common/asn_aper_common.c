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
 * .remove LTE compile warning
 * .turn off GENERATE_EXTERN_ALL_PDU
 *
 * removed!
 * removed!
 * Merge Moly_tataka asn common
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

#include "kal_public_api.h"
#include "asn_memory.h"
#include "asn_common.h"

#include "asn_aper_common.h"


extern	Bool IsReindexOneByteAlphabet(ASN_OneByteAlphabet *pAlphabet)
{

	return ((U32)(*(pAlphabet->value + pAlphabet->valueLen - 1)) 
			<= GetOneByteCharacterBitWidth(pAlphabet)) ? 0 : 1;
}


extern	U32 GetOneByteCharacterBitWidth(ASN_OneByteAlphabet *pAlphabet)
{
	U32	uB, uB2;

	uB = GetNumberBitLength(pAlphabet->valueLen);
	uB2 = GetNumberBitLength(uB);

	return	(U32)(1 << uB2); //pow(2, uB2);
}	


U32 GetNumberBitLength(U32  Data)
{
	if (Data > 0 && Data < 2) {
		return 1;
	}
	else if (Data >= 2 && Data < 4) {
		return 2;
	}
	else if (Data >= 4 && Data < 8) {
		return 3;
	}
	else if (Data >= 8 && Data < 16) {
		return 4;
	}
	else if (Data >= 16 && Data < 32) {
		return 5;
	}
	else if (Data >= 32 && Data < 64) {
		return 6;
	}
	else if (Data >= 64 && Data < 128) {
		return 7;
	}
	else if (Data >= 128 && Data < 256) {
		return 8;
	}
	else if (Data >= 256 && Data < 512) {
		return 9;
	}
	else if (Data >= 512 && Data < 1024) {
		return 10;
	}
	else if (Data >= 1024 && Data < 2048) {
		return 11;
	}
	else if (Data >= 2048 && Data < 4096) {
		return 12;
	}
	else{
		return 0;
	}
}


/************************************************************************/
/*         APER    Encode   Tools  Function                             */
/************************************************************************/
extern void AperPutSmallNumber(AsnContext *pContext, U32 uNum)
{
	if (uNum < 64)
	{
		putShortBits(pContext, 1, 0);
		putShortBits(pContext, 6, uNum);
	}
	else
	{
		putShortBits(pContext, 1, 1);
		AperPutSemiConstraintNumber(pContext, 0, uNum);
	}
}

extern U32 AperGetSmallNumber(AsnContext *pContext)
{
	U32 uNum;

	if (0 ==  getShortBits(pContext, 1))
	{
		uNum = getShortBits(pContext, 6);
	}
	else
	{
		uNum = 	AperGetSemiConstraintNumber(pContext, 0);
	}

	return uNum;
}


extern U32 AperPutLengthValue(AsnContext *pContext, U32 lBound, U32 uBound, U32 uLen)
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
		AperPutWholeConstraintNumber(pContext, lBound, uBound, uLen);
	}
	else if (uBound >= 65536)
	{
		if (uLen <= 127)
		{
			PER_ALIGN
			putShortBits(pContext, 1, 0);
			putShortBits(pContext, 7, uLen);
		}
		else if (uLen >127 && uLen<=16383)
		{
			PER_ALIGN
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

extern U32 AperGetLengthValue(AsnContext *pContext, U32 lBound, U32 uBound)
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
		ulen = AperGetWholeConstraintNumber(pContext, lBound, uBound);
	}
	else if (uBound >= 65536)
	{

		if (0 == testGetShortBits(pContext, 1))
		{
			PER_CLEAR_ALIGN_BITS
			// Len < 127
			ulen = getShortBits(pContext, 8);
		}
		else if (0x20 == testGetShortBits(pContext, 2))
		{
			PER_CLEAR_ALIGN_BITS
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

extern void AperPutWholeConstraintNumber(AsnContext *pContext, S32 lBound, S32 uBound, U32 uNum)
{	
	U32		range, nByte;

	ASSERT(uBound >= lBound);
	range = uBound - lBound;

	if (0 == range)
	{
		// put no bit 
	}
	else if((range >= 1) && (range <= 254))
	{
		putShortBits(pContext, GetNumberBitLength(range), uNum-lBound);
	}
	else if(255 == range)
	{
		PER_ALIGN
		putShortBits(pContext, 8, uNum-lBound);
	}
	else if(range <= 65535)
	{
		PER_ALIGN
		putShortBits(pContext, 16, uNum-lBound);
	}
	else if(range >= 65536)
	{
		PER_ALIGN
		range = GetNumberOctetLength(uBound - lBound);
		nByte = GetNumberOctetLength(uNum - lBound);

		AperPutLengthValue(pContext, 1, range, nByte);

		PER_ALIGN
		putShortBits(pContext, nByte * 8, uNum-lBound);
	}
}

extern U32	AperGetWholeConstraintNumber(AsnContext *pContext, S32 lBound, S32 uBound)
{
	U32		range, uNum=0, nByte;

	ASSERT(uBound >= lBound);
	range = uBound - lBound;

	if (0 == range)
	{
		// put no bit 
	}
	else if((range >= 1) && (range <= 254))
	{
		uNum = getShortBits(pContext, GetNumberBitLength(range)) + lBound;
	}
	else if(255 == range)
	{
		PER_CLEAR_ALIGN_BITS
		uNum = getShortBits(pContext, 8) + lBound;
	}
	else if(range <= 65535)
	{
		PER_CLEAR_ALIGN_BITS
		uNum = getShortBits(pContext, 16) + lBound;
	}
	else if(range >= 65536)
	{
		PER_CLEAR_ALIGN_BITS
		nByte = GetNumberOctetLength(uBound-lBound);
		nByte = AperGetLengthValue(pContext, 1, nByte);
		
		PER_CLEAR_ALIGN_BITS
		uNum = getShortBits(pContext, nByte * 8) + lBound;
	}

	return uNum;
}


extern  void AperPutSemiConstraintNumber(AsnContext *pContext, S32 lBound, S32 uNum)
{	
	U32		distance, nByte ;
	
	ASSERT(uNum >= lBound);
	distance = uNum - lBound;

	nByte = GetNumberOctetLength(distance);
	AperPutLengthValue(pContext, 0, ASN_MAX, nByte);

	PER_ALIGN

	putBits(pContext, nByte * 8, distance);

}

extern S32 AperGetSemiConstraintNumber(AsnContext *pContext, S32 lBound)
{	
	U32	sNum, nByte;

	nByte = AperGetLengthValue(pContext, 0, ASN_MAX);

	PER_CLEAR_ALIGN_BITS
	
	if (nByte <= 3)
	{
		sNum = getShortBits(pContext, nByte * 8) + lBound;
	}
	else
	{
		sNum = getShortBits(pContext, 16);
		sNum = sNum << 16;

		sNum &= 0xFFFF0000;
		sNum |= getShortBits(pContext, 16);

		sNum += lBound;
	}
		
	return sNum;
}

extern  void AperPutNonConstraintNumber(AsnContext *pContext,  S32 uNum)
{	
	int		ulen, nByte, temp=0;
	EncodeBeginPoint	begin;

	PER_ALIGN

	SkipEncodeByte(pContext);	// For Record 
	begin = BeginTestEncodeLen(pContext);

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

		putShortBits(pContext, nByte * 8, uNum);
	}

	PER_ALIGN

	ulen = EndTestEncodeLen(pContext, begin);
	PutShortSkipedEncodeByte(pContext, GetNumberOctetLength(ulen), ulen, ulen);
}

extern S32 AperGetNonConstraintNumber(AsnContext *pContext)
{
	int		nByte;
	S32		uNum = 0;

	PER_CLEAR_ALIGN_BITS

	nByte = testGetShortBits(pContext, 8);

	if (0 == getShortBits(pContext, 1))
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
	
	
	PER_CLEAR_ALIGN_BITS

	return uNum;
}

extern void AperEncodeOpenType(AsnContext *pContext,  U8 * pData, U32 uSize)
{
	if (uSize > 0)
	{
		AperPutLengthValue(pContext, 0, ASN_MAX, uSize);	
		putLongBits(pContext, uSize*8, pData);
	}	
}

extern U32 AperDecodeOpenTypeLength(AsnContext *pContext)
{
	return AperGetLengthValue(pContext, 0, ASN_MAX);
}

extern U32 AperDecodeOpenType(AsnContext *pContext,  U8 * pData, U32 uSize)
{
	U32		   uLen;
	AsnContext TempContext = *pContext;

	uLen = AperGetLengthValue(pContext, 0, ASN_MAX);

	if (NULL == pData)
	{	
		*pContext = TempContext;
		return uLen;
	}

	getLongBits(pContext, 8 * asn_min(uLen, uSize),  (U8 *)pData);

	// return decode length (by byte)
	return asn_min(uLen, uSize);
}

static void AperEncodeOIDItem(AsnContext *pContext,  U32  uData)
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

static U32 AperDecodeOIDItem(AsnContext *pContext,  U8 **ppData)
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
		UA1_ERROR(103);
	}
	
	return uNum;
}

extern void AperEncodeOID(AsnContext *pContext,  OID *pOid)
{
	U32		ulen, i;
	AsnContext TempContext;
	U8 * pBuf = NULL;
	EncodeBeginPoint	begin;

	PER_ALIGN

	begin = BeginTestEncodeLen(pContext);

	TempContext = *pContext;

	putShortBits(pContext,  8, ((*pOid->value)*40 + (* (pOid->value + 1))));

	for(i=2; i<pOid->valueLen; i++)
	{
		AperEncodeOIDItem(pContext, *(pOid->value + i));
	}

	ulen = EndTestEncodeLen(pContext, begin);

	asnMemAlloc(pContext, (void **)&pBuf, ulen);
	
	asnMemCopy(pBuf, pContext->pEncoded - ulen, ulen);	

	*pContext = TempContext;

	AperEncodeOpenType(pContext, pBuf, ulen);

   if (pContext->pMemFreeFunc != NULL)
   {
      pContext->pMemFreeFunc((void **)&pBuf);
   }
   else
   {
	asnMemFree((void **)&pBuf);
   }

}

extern void AperDecodeOID(AsnContext *pContext,  OID *pOid)
{	
	U32	 ulen, i, *pItemOrg;
	U8 * pBuf;// , * pBufOrg;
		
	PER_CLEAR_ALIGN_BITS

	ulen = AperDecodeOpenType(pContext, NULL, 0);

	AsnDecodeAlloc(pContext, (void **)&pBuf, ulen);

	//pBufOrg = pBuf;

	AperDecodeOpenType(pContext, pBuf, ulen);

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
		*pOid->value = AperDecodeOIDItem(pContext, &pBuf);
	}

	pOid->value = pItemOrg;
}


extern void AperEncodeBitString(AsnContext *pContext, U32 lBound, U32 uBound, U8 *pData, U32 uLen)
{
	U32	distance;
	
	distance = uBound - lBound;
	
	if (0 == distance)
	{
		if (lBound <= 16)
		{
			putLongBits(pContext, uLen, pData);
		}
		else if (lBound <= 65536)
		{
			PER_ALIGN
			putLongBits(pContext, uLen, pData);
			PER_ALIGN
		}
		else
		{
			AperPutLengthValue(pContext, distance, distance, distance);
			putLongBits(pContext, uLen, pData);
		}
	}
	else
	{
		AperPutLengthValue(pContext, 0, ASN_MAX, distance);
		putLongBits(pContext, uLen, pData);
	}
}

extern U32 AperDecodeBitString(AsnContext *pContext, U32 lBound, U32 uBound, U8 *pData)
{
	U32	distance, uLen;
	
	distance = uBound - lBound;
	
	if (0 == distance)
	{
		if (lBound <= 16)
		{
			uLen = lBound;
			getLongBits(pContext, lBound, (U8 *)pData);
		}
		else if (lBound <= 65536)
		{
			PER_CLEAR_ALIGN_BITS
				
			uLen = lBound;
			getLongBits(pContext, lBound, (U8 *)pData);
			
			PER_CLEAR_ALIGN_BITS
		}
		else
		{
			uLen = AperGetLengthValue(pContext, distance, distance);
			AsnDecodeAlloc(pContext,(void **) &pData, lBound);
			getLongBits(pContext, uLen, (U8 *)pData);
		}
	}
	else
	{
		uLen =  AperGetLengthValue(pContext, 0, ASN_MAX);
		
		AsnDecodeAlloc(pContext, (void **)&pData, lBound);
		getLongBits(pContext, uLen, (U8 *)pData);
	}
	
	return uLen;
}

//////////////////////////////////////////////////////////////////////////
// String Encode
//////////////////////////////////////////////////////////////////////////

extern void AperEncodeOneByteString(AsnContext *pContext,  OneByteString *pStr, U32 minSize, U32 maxSize, ASN_OneByteAlphabet *pAlphabet)
{
	U32		i=0, bitSize=0;
 S32     index=0;

	AperPutLengthValue(pContext, minSize, maxSize, pStr->valueLen);
	
	PER_ALIGN
	
	if (NULL == pAlphabet)
	{
		for(i = 0; i < pStr->valueLen; i++)
		{		
			putShortBits(pContext, 8,  *(pStr->value+i));
		}
	}
	else
	{
		if (IsReindexOneByteAlphabet(pAlphabet))
		{
			bitSize = GetOneByteCharacterBitWidth(pAlphabet);
			
			for(i = 0; i < pStr->valueLen; i++)
			{	
				index = GetAlphabetIndex(pAlphabet, (pStr->value+i));
				
				if (-1 == index)
				{
					UA1_ERROR(112);
				}
				
				putShortBits(pContext, bitSize,  index);
			}	
		}
		else
		{
			for(i = 0; i < pStr->valueLen; i++)
			{		
				putShortBits(pContext, 8,  *(pStr->value+i));
			}
		}	
	}
	
}

static void AperDecodeOneByteStringA(AsnContext *pContext,  OneByteString *pStr, U32 minSize, U32 maxSize, ASN_OneByteAlphabet *pAlphabet)
{
	// ... ?  Check Characters ?	
	U32		i, bitSize, index;

	pStr->valueLen = AperGetLengthValue(pContext, minSize, maxSize);

	PER_CLEAR_ALIGN_BITS

	if (NULL == pAlphabet)
	{
		AsnDecodeAlloc(pContext, (void **)&pStr->value, pStr->valueLen);
		getLongBits(pContext, pStr->valueLen * 8, (U8 *)pStr->value);
	}
	else
	{
		if (IsReindexOneByteAlphabet(pAlphabet))
		{		
			AsnDecodeAlloc(pContext, (void **)&pStr->value, pStr->valueLen);
			bitSize = GetOneByteCharacterBitWidth(pAlphabet);

			for(i = 0; i < pStr->valueLen; i++)
			{	
				index = getShortBits(pContext, bitSize);
				*(pStr->value + i) = *(pAlphabet->value + index);
			}	
		}
		else
		{
			AsnDecodeAlloc(pContext, (void **)&pStr->value, pStr->valueLen);
			getLongBits(pContext, pStr->valueLen * 8, (U8 *)pStr->value);
		}			
	}	
}

static  void AperEncodeTwoByteString(AsnContext *pContext,  TwoByteString *pStr, U32 minSize, U32 maxSize, ASN_TwoByteAlphabet *pAlphabet)
{
	// If No Constraint 
	U32		i;

	AperPutLengthValue(pContext, minSize, maxSize, pStr->valueLen);
	
	PER_ALIGN
	
	for(i = 0; i < pStr->valueLen; i++){		
		putShortBits(pContext, 8,  GET_U16_HIGH(*(pStr->value+i)) );
		putShortBits(pContext, 8,  GET_U16_LOW(*(pStr->value+i)) );
	}

  if ( pAlphabet) {
    /* do nothing */
  } else {
    /* do nothing */
  }
}

static  void AperDecodeTwoByteStringA(AsnContext *pContext,  TwoByteString *pStr, U32 minSize, U32 maxSize, ASN_TwoByteAlphabet *pAlphabet)
{
	// If No Constraint 
	U32		i;
	U16		uHigh, uLow;

	pStr->valueLen = AperGetLengthValue(pContext, minSize, maxSize);	
	AsnDecodeAlloc(pContext, (void **)&pStr->value, pStr->valueLen * 2);

	PER_CLEAR_ALIGN_BITS

	for(i = 0; i < pStr->valueLen; i++){		
		uHigh = (U16)getShortBits(pContext, 8);
		uLow  = (U16)getShortBits(pContext, 8);
		*(pStr->value + i) = MAKE_U16(uHigh, uLow);
	}
	
  if ( pAlphabet) {
    /* do nothing */
  } else {
    /* do nothing */
  }	
}


//////////////////////////////////////////////////////////////////////////
// Numeric String

extern  void AperEncodeNumericString(AsnContext *pContext,  asn_NumericString *pStr, U32 minSize, U32 maxSize, ASN_OneByteAlphabet *pAlphabet)
{
	// ... ?  Check Characters ?
	U32		i;

	AperPutLengthValue(pContext, minSize, maxSize, pStr->valueLen);
	
	PER_ALIGN

	for(i = 0; i < pStr->valueLen; i++){		
		putShortBits(pContext, 4,  *(pStr->value+i) - 47);
	}
	
	if ( pAlphabet) {
    /* do nothing */
  } else {
    /* do nothing */
  }
}

extern  void AperDecodeNumericStringA(AsnContext *pContext,  asn_NumericString *pStr, U32 minSize, U32 maxSize, ASN_OneByteAlphabet *pAlphabet)
{
	// ... ?  Check Characters ?
	U32		i;
	
	pStr->valueLen = AperGetLengthValue(pContext, minSize, maxSize);	

	PER_CLEAR_ALIGN_BITS

	AsnDecodeAlloc(pContext, (void **)&pStr->value, pStr->valueLen);

	for(i = 0; i < pStr->valueLen; i++){		
		*(pStr->value+i) = (U8)getShortBits(pContext, 4) + 47;
	}
  if ( pAlphabet) {
    /* do nothing */
  } else {
    /* do nothing */
  }	
}


//////////////////////////////////////////////////////////////////////////
// IA5 String
extern  void AperEncodeIA5String(AsnContext *pContext,  asn_IA5String *pStr, U32 minSize, U32 maxSize, ASN_OneByteAlphabet *pAlphabet)
{
	// ... ?  Check Characters ?
	AperEncodeOneByteString(pContext, pStr, minSize, maxSize, pAlphabet);
}

extern  void AperDecodeIA5StringA(AsnContext *pContext,  asn_IA5String *pStr, U32 minSize, U32 maxSize, ASN_OneByteAlphabet *pAlphabet)
{
	AperDecodeOneByteStringA (pContext, pStr, minSize, maxSize, pAlphabet);
}	

//////////////////////////////////////////////////////////////////////////
// BMP String
extern  void AperEncodeBMPString(AsnContext *pContext,  asn_BMPString *pStr, U32 minSize, U32 maxSize, ASN_TwoByteAlphabet *pAlphabet)
{
	// ... ?  Check Characters ?
	AperEncodeTwoByteString(pContext, pStr, minSize, maxSize, pAlphabet);
}

extern  void AperDecodeBMPStringA(AsnContext *pContext,  asn_BMPString *pStr, U32 minSize, U32 maxSize, ASN_TwoByteAlphabet *pAlphabet)
{
	// ... ?  Check Characters ?
	AperDecodeTwoByteStringA(pContext, pStr, minSize, maxSize, pAlphabet);
}


//////////////////////////////////////////////////////////////////////////
// General String
extern  void AperEncodeGeneralString(AsnContext *pContext,  asn_GeneralString *pStr)
{
	AperEncodeOpenType(pContext, (U8 *)pStr->value, pStr->valueLen);
}

extern  void AperDecodeGeneralStringA(AsnContext *pContext,  asn_GeneralString *pStr)
{
	pStr->valueLen = AperDecodeOpenType(pContext, NULL, 0);
	AsnDecodeAlloc(pContext, (void **)&pStr->value, pStr->valueLen);
		
	AperDecodeOpenType(pContext, (U8 *)pStr->value, pStr->valueLen);
}

extern	void AperDecodeChoiceUnKnowItem(AsnContext *pContext, ChoiceUnKnow *pUnKnowItem)
{
	ChoiceUnKnow	*pUnKnow;
	
	// In the extension
	AsnDecodeAlloc(pContext, (void **)&pUnKnow, sizeof(ChoiceUnKnow));
	pUnKnow->uIndex =  AperGetSmallNumber(pContext); // Index
	
	PER_CLEAR_ALIGN_BITS
	pUnKnow->valueLen = AperDecodeOpenType(pContext, NULL, 0);
	
	AsnDecodeAlloc(pContext, (void **)&(pUnKnow->value), pUnKnow->valueLen);
	AperDecodeOpenType(pContext, pUnKnow->value, pUnKnow->valueLen);
	
	pUnKnowItem = pUnKnow;
}

extern void AperDecodeSequcenceUnKnowItem(AsnContext *pContext,  UnKnowExtensionItemArray *pArray, U32 uSize, Bool  *pIsItemExist)
{
	U32	i, uUnKonwSize;
	U8 *pData;
	
	AsnDecodeAlloc(pContext, (void **)&(pArray->value), sizeof(UnKnowExtensionItem) * uSize);
	memset(pArray->value, 0, sizeof(UnKnowExtensionItem) * uSize);
	
	for (i=0; i<uSize; i++)
	{
		if (*(pIsItemExist+i))
		{
			uUnKonwSize = AperDecodeOpenType(pContext, NULL, 0);
			AsnDecodeAlloc(pContext, (void **)&pData, uUnKonwSize);
			AperDecodeOpenType(pContext, pData, uUnKonwSize);
		
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
