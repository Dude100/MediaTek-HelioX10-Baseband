/*****************************************************************************
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   msdc_adap_bl.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   MSDC/SD driver adaption layer for bootloader porting
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
 *============================================================================
 ****************************************************************************/

#ifdef __CARD_DOWNLOAD__

#include "msdc_adap_bl.h"
#include "drv_comm.h"
#include "msdc_def.h"

/*** external data & function ***/

extern FS_Driver FS_SdDrv;

/*** function body ***/

int BL_MSDC_Init(void)
{
    // enable GPIO for MSDC
#if defined(MT6235) || defined(MT6235B)
    DRV_SetBits(0x80021800, 0x5540);
    DRV_SetBits(0x80021900, 0x55);
#elif defined(MT6236)
    DRV_SetBits(0x801D0610, 0x3);       // MCOINS: b'11
    DRV_SetBits(0x801D0200, 0xFD00);    // GPIO8 PU SEL (b'8)    
#elif defined(MT6253)
    DRV_SetBits(0x80020210, 0x5554);
#elif defined(MT6252)
	  //
	  // Patch the offset and arguments. The macro only can read/write 16bit data.
	  //
	  //DRV_ClearBits(0x800201D0, 0xFFFF0000);
    //DRV_SetBits(0x800201D0, 0x11110000);
    DRV_ClearBits(0x800201D2, 0xFFFF);
    DRV_SetBits(0x800201D2, 0x1111);
#elif defined(MT6268)
	DRV_ClearBits(0x84021A00, 0xFF00);
    DRV_SetBits(0x84021A00, 0x5500);
#elif defined(MT6276_S01)
	DRV_ClearBits(0x810A2200, 0x7FC0);
    DRV_SetBits(0x810A2200, 0x1240);
	DRV_ClearBits(0x810A2300, 0x0FFF);
    DRV_SetBits(0x810A2300, 0x0249);
#elif defined(MT6276_S00)
	#error Not support MT6276 E1!
#elif defined(MT6251_S01)
	DRV_ClearBits(0x80020200, 0x0FFF);
    DRV_SetBits(0x80020200, 0x0111);
#elif defined(MT6251_S00)
	#error Not support MT6251 E1!
#elif defined(MT6255)
    DRV_ClearBits(0x801D0750, 0x00F0);
#elif defined(MT6250)
    DRV_ClearBits(0xA0020c32, 0xFF00); 
    DRV_SetBits(0xA0020c32, 0x1100); // CLK and DAT0
    DRV_ClearBits(0xA0020c40, 0x000F);
    DRV_SetBits(0xA0020c40, 0x0001); // CMD    
#endif

    DclSD_Initialize();
    //MSDC_Initialize();
    
    return 0;
}

int BL_MSDC_DeInit(void)
{
    //MSDC_DeInit();
    DclSD_DeInitialize();

    // reset GPIO to disable MSDC
#if defined(MT6235) || defined(MT6235B)
    DRV_ClearBits(0x80021800, 0x5540);
    DRV_ClearBits(0x80021900, 0x55);
#elif defined(MT6236)
    DRV_ClearBits(0x801D0610, 0x3); // MCOINS: b'11
#elif defined(MT6253)
    DRV_ClearBits(0x80020210, 0x5554);
#elif defined(MT6252)
	DRV_ClearBits(0x800201D0, 0xFFFF0000);
#elif defined(MT6268)
	DRV_ClearBits(0x84021A00, 0xFF00);
#elif defined(MT6251_S01)
	DRV_ClearBits(0x80020200, 0x0FFF);
#endif

    return 0;
}

int BL_MSDC_MountDevice(int DeviceNumber, int DeviceType, unsigned int Flags)
{
    return FS_SdDrv.MountDevice((void*)&MSDC_Blk[0], DeviceNumber, DeviceType, Flags);
}

int BL_MSDC_ReadSectors(unsigned int Sector, unsigned int Sectors, void * Buffer)
{
    return FS_SdDrv.ReadSectors((void*)&MSDC_Blk[0], Sector, Sectors, Buffer);
}

int BL_MSDC_GetDiskGeometry(FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor)
{
    return FS_SdDrv.GetDiskGeometry((void*)&MSDC_Blk[0], DiskGeometry, MediaDescriptor);
}

int BL_MSDC_GetCardPSN(unsigned int *psn)
{
    FS_DeviceInfo info;
    FS_SdDrv.IOCtrl((void*)&MSDC_Blk[0], FS_IOCTRL_QUERY_CARD_INFO, &info);

	if (psn == NULL)
		return -1;

    *psn = info.DeviceInfo.Card.PSN;
    
    return 0;
}

#endif//__CARD_DOWNLOAD__
