/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   L1audio_idma.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   transfer data by IDMA
 *   address-mode and short-mode could be predefined switched.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *===========================================================
*****************************************************************************/

#include "reg_base.h"

#include "audio_def.h"
#include "common_def.h"

void IDMA_WriteToDSP_Duplicate(volatile kal_uint16 *dst, kal_uint16 *src, kal_uint32 length)
{
   kal_int32 i;
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE

   for(i=length; i>0;i-=2)
   {
      *dst++ = *src;
      *dst++ = *src++;
   }
#else

   *dst = *src;
   *IDMA_SHORT_ADDR = *src++;
   for(i=length-2; i>0;i-=2)
   {
      *IDMA_SHORT_ADDR=*src;
      *IDMA_SHORT_ADDR=*src++;
   }
#endif
}

void IDMA_WriteToDSP(volatile kal_uint16 *dst, kal_uint16 *src, kal_uint32 length)
{
   kal_int32 i;
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE

   for(i=length; i>0;i--)
      *dst++ = *src++;

#else

   *dst = *src++;
   for(i=length-1; i>0;i--)
      *IDMA_SHORT_ADDR=*src++;

#endif
}


void IDMA_FillToDSP(volatile kal_uint16 *dst, kal_uint16 value, kal_uint32 length)
{
   kal_int32 i;
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE

   for(i=length; i>0;i--)
      *dst++ = value;

#else

   *dst = value;
   for(i=length-1; i>0;i--)
      *IDMA_SHORT_ADDR=value;

#endif
}

void IDMA_ReadFromDSP(kal_uint16 *dst, volatile kal_uint16 *src, kal_uint32 length)
{
   kal_int32 i;

#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE

   for( i = length; i > 0; i-- )    
       *dst++ = *src++;

#else

   *dst = *src;   // dummy read
   for(i=length; i>0;i--)
      *dst++ = *IDMA_SHORT_ADDR;

#endif
}

void IDMA_ReadFromDSP_Skip_1(kal_uint16 *dst, volatile kal_uint16 *src, kal_uint32 length)
{
   kal_int32 i;

#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE

   for( i = length; i > 0; i-- )
   {
       *dst++ = *src++;
       dst++;
   }
   
#else

   *dst = *src;   // dummy read
   for(i=length; i>0;i--)
   {
      *dst++ = *IDMA_SHORT_ADDR;
      dst++;	  
   }
   
#endif
}

