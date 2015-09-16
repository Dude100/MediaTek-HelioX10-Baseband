
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    BC_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Driver 0f Bit Copy.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_comm.h"
#include "intrCtrl.h"
#include "drv_hisr.h"
#include "BC_drv.h"

#if defined(__3G_F8F9BC_HW_DRV_V1__)

static kal_mutexid          BC_mutex;


/*****************************************************************************
 * FUNCTION
 *   F8Cipher
 *
 * DESCRIPTION
 *   Do the F8 Cipher funtion.
 *
 * PARAMETERS
 *   src             [IN] : source data pointer
 *   srcOffset       [IN] : source data bit offset
 *   dest            [IN] : destination data pointer
 *   destOffset      [IN] : destination data bit offset
 *   length          [IN] : total bit length
 *
 * RETURNS
 *   None
 *****************************************************************************/


void BitCopy(const kal_uint8 *src, kal_uint16 srcOffset, kal_uint8 *dest, kal_uint16 *destOffset, kal_uint16 length)
{
	
     kal_uint32	 Input32Temp, BC_it;
     kal_uint32  srcStartAddr, dstStartAddr;
     kal_uint16  destOffsetTemp = *destOffset; 
     
     srcStartAddr = (kal_uint32) (src + ( srcOffset / 8 ));
     srcOffset = srcOffset % 8;
     
     dstStartAddr = (kal_uint32) (dest + ( (*destOffset) / 8 ));
     (*destOffset) = (*destOffset) % 8;
     
     
     if (!BC_mutex){
         BC_mutex = kal_create_mutex("BC_mutex");}
      
     
     kal_take_mutex(BC_mutex);
        
     //reset all register   
	  DRV_WriteReg32(BC_REG_START,0);       
	   
	  //input source addr
	  DRV_WriteReg32(BC_REG_SRC, ((kal_uint32)(srcStartAddr)));    
	   
	  //output destination addr   
	  DRV_WriteReg32(BC_REG_DST, ((kal_uint32)(dstStartAddr)));      
	   
	   
	  //output destination last byte addr 
	  Input32Temp = ((length - (8 - (*destOffset))) > 0) ? (kal_uint32)(dstStartAddr + ((length - (8 - (*destOffset)) + 7) / 8)) : (kal_uint32)dstStartAddr;
	  DRV_WriteReg32(BC_REG_LDST, ((kal_uint32)Input32Temp));   
	   
	   
	  //input copy length 
	  Input32Temp = 0;
     Input32Temp = length & 0x0000FFFF;
	   DRV_WriteReg32(BC_REG_SIZE, ((kal_uint32)Input32Temp));                 
	   
	   
	  //set wo and ro(also reset all)
	  Input32Temp = 0;
     Input32Temp = (kal_uint32)(( ((kal_uint32)(*destOffset))<<4) | ((kal_uint32)srcOffset) | (0x00030000));
	  DRV_WriteReg32(BC_REG_CON, (kal_uint32)Input32Temp);               
	   
	   
	  //start the BC engine 
     DRV_WriteReg32(BC_REG_START, 0x00008000);       
	   	
	   	
	   //polling completed interrupt	
	   while(1){  
	     BC_it = DRV_Reg32(BC_REG_STA);
        if((BC_it&0x00000002)!=0)
	   		break;
	   }
	   
	   kal_give_mutex(BC_mutex);
	   
	   (*destOffset) = destOffsetTemp + length;
} 

#endif /* __3G_F8F9BC_HW_DRV_V1__ */
