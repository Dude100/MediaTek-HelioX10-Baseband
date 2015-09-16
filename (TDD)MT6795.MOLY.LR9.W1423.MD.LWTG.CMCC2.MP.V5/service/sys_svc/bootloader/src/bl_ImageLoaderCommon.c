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
 *   bl_ImageLoaderCommon.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Reponsible for loading image.
 *
 * Author:
 * -------
 *   
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
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "kal_general_types.h"
#include "bl_common.h"
#include "bl_FOTA.h"
#include "bl_loader.h"
#include "bl_custom.h"
#include "bl_nfi_wrapper.h"
#include "bl_sectiondef.h"
#include "bl_INIT.H"

/*************************************************************************
 * External reference
*************************************************************************/

extern BL_Info_Wrapper_st BL_Shared_info;

#if defined(__FOTA_DM__)
extern kal_uint32 Image$$READ_WRITE_SYS_RAM$$Base;
extern void SSF_Set_Shared_Backup(kal_uint32 ua_shared_ram);
extern kal_uint32 bl_loadFOTAImage(void);
#endif /* __FOTA_DM__ */

/*************************************************************************
 * Global variables definition
*************************************************************************/
__bl_info_shared_zi__ BL_Info_Wrapper_st BL_Shared_info;

#if defined(_NAND_FLASH_BOOTING_)
const kal_char blID1[]  = "BOOTLOADER!";
const kal_char blID2[]  = "NFIINFO";
#endif /* _NAND_FLASH_BOOTING_ */

kal_bool bl_secure_nfb_usbdl = KAL_FALSE;

BOOTL_HEADER     BLHeader;

#if !defined(__USE_NFI_SHARED_DRV__)
/**********************************************************
Description : C entry of the project.
Input       : None
Output      : None
***********************************************************/
void _errorExit(_RET_CODE errorCode, kal_uint32 pageNo, kal_uint32 *ptr)
{
   switch ( errorCode )
   {
      case NFI_ZERO_POINTER: 
         BL_PRINT(LOG_ERROR, "\n\n\rNFI Read Error: Zero pointer is encountered!\n\r");
         break;
      case NFI_READ_DATA_TIMEOUT:          
         BL_PRINT(LOG_ERROR, "\n\n\rNFI Read Error: Timeout while reading data!\n\r");
         break;
      case NFI_READ_SPARE_TIMEOUT:          
         BL_PRINT(LOG_ERROR, "\n\n\rNFI Read Error: Timeout while reading spare data!\n\r");
         break;
      case DMA_TRANSFER_DATA_TIMEOUT:          
         BL_PRINT(LOG_ERROR, "\n\n\rNFI Read Error: DMA timeout while transferring data!\n\r");
         break;
      case DMA_TRANSFER_SPARE_TIMEOUT:          
         BL_PRINT(LOG_ERROR, "\n\n\rNFI Read Error: DMA timeout while transferring spare data!\n\r");
         break;
      case NFI_ECC_2BITS_ERR: 
         BL_PRINT(LOG_ERROR, "\n\n\rNFI Read Error: NFI ECC 2-bits error!\n\r");
         break;
#if defined(__FOTA_DM__)
      case FUE_BACKUP_ERROR:
         BL_PRINT(LOG_ERROR, "\n\n\rNFB FOTA Error: FUE Back up is not found!\n\r");
         break;
      case FUE_FOTA_IMAGE_TOO_BIG:
         BL_PRINT(LOG_ERROR, "\n\n\rNFB FOTA Error: FUE Image is too big!\n\r");
         break;
      case FUE_UNSUPPORTED_TYPE:
         BL_PRINT(LOG_ERROR, "\n\n\rNFB FOTA Error: Unknown flash device type! %d\n\r", errorCode);
        break;
#endif
      default:
         break;
   }
   
   BL_PRINT(LOG_ERROR, ".....@ Page numberd %d, desitination address %x\n\r", pageNo, (kal_uint32)ptr);
   BL_PRINT(LOG_ERROR, ".....Good-bye with error!\n\n\n\r");
   
   while (1)
      WacthDogRestart();
}

#endif /* !__USE_NFI_SHARED_DRV__ */

#if defined(__FOTA_DM__) && defined(__EXT_BOOTLOADER__) && ( defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) )

kal_uint32 LoadFotaOnNand()
{
   kal_uint32 start_addr = INVALID_START_ADDR;

   /* copy boot loader header to shared variable */
   memcpy(&BL_Shared_info.m_bl_header, &BLHeader, sizeof(BOOTL_HEADER));

   /* load image list */
   SSF_Set_Shared_Backup((kal_uint32)&Image$$READ_WRITE_SYS_RAM$$Base);
   WacthDogRestart();                                                  
   start_addr = bl_loadFOTAImage();                                    
   WacthDogRestart();                                                  

   return start_addr;
}
#endif /* __FOTA_DM__ && __EXT_BOOTLOADER__ && (_NAND_FLASH_BOOTING_ || __EMMC_BOOTING__)*/

#if defined(_NAND_FLASH_BOOTING_) || defined(__EXT_BL_UPDATE__)

/**********************************************************
Description : Utility for identifying block endmark with bit errors
Input       : tags of tail1 and tail2
Output      : return if they are the same
***********************************************************/
kal_bool CompareEndMarkWithError(const kal_uint32 *pTag1, const kal_uint32 *pTag2, kal_uint32 errorThreshold)
{
   kal_uint32 i;
   kal_uint32 idxes[] = {0, 1, 5, 6};
   kal_uint32 bit_error = 0;

   for ( i=0; i<sizeof(idxes)/sizeof(*idxes); i++)
   {
      kal_uint32 r = pTag1[idxes[i]] ^ pTag2[idxes[i]];
      while (r)
      {
         bit_error++;
         if(bit_error >= errorThreshold)
         {
            return KAL_FALSE;
         }
         r &= r-1;
      }
   }

   return KAL_TRUE;
}


#endif /* _NAND_FLASH_BOOTING_ || __EXT_BL_UPDATE__ */


