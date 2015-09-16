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
 *   combo_flash_init.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the ComboMCP Init function
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "custom_MemoryDevice.h"
#include "flash_opt.h"

#if defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__) || (defined(_NAND_FLASH_BOOTING_) && defined(__NAND_MDL_APPEND__))
#include "combo_flash_init.h"
#include "combo_flash_defs.h"
  #if (!defined(_NAND_FLASH_BOOTING_))
  #include "flash_cfi.h"
  #include "flash_cfi_internal.h"
  #include "flash_mtd.h"
  #endif
  #if defined(NAND_SUPPORT)
  #ifdef __UBL__
    extern void NFI_ReadID(kal_uint32 id_num, kal_uint8* id_data);
  #else
    extern kal_bool DAL_is_initialized;
  	extern kal_int32 DAL_init (void);
    extern void MTD_ReadID(kal_uint32 id_num,kal_uint8* id_data);
  #endif
  #endif
#if defined(__SERIAL_FLASH__)
#include "flash_sf.h"
#endif

#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
#include "br_GFH_cmem_id_info.h"
#endif /* __SV5_ENABLED__ */

//-----------------------------------------------------------------------------
// MCP ID Table
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [Section] RVCT and GCC
//-----------------------------------------------------------------------------
#if defined(__MTK_TARGET__)
#if defined(__SV5_ENABLED__)|| defined(__SV5X_ENABLED__)
  #if defined(__UBL__)
	#if defined (__MINI_BOOTLOADER__)
    #define __sf_section_RODATA_GFH             __attribute__ ((section ("BOOTLOADER_GFH_EXT")))
	#elif defined (	__EXT_BOOTLOADER__)
	#define __sf_section_RODATA_GFH             __attribute__ ((section ("EXT_BOOTLOADER_GFH_EXT")))
	#endif
  #else
    #define __sf_section_RODATA_GFH             __attribute__ ((section ("MAUI_GFH_EXT")))
  #endif
#else // SV3
    // Method1
    // #define __sf_section_RODATA_GFH             __attribute__ ((section ("SECOND_PART_RODATA")))
    // Method2
    #define __sf_section_RODATA_GFH
#endif
#else //defined(__MTK_TARGET__)
    /* Reserve for MoDIS */
    #define __sf_section_RODATA_GFH
#endif  // defined(__MTK_TARGET__)

#if defined(__MTK_TARGET__)
    #define __sf_section_RWDATA_EMI             __attribute__ ((section ("EMIINITRW")))
    #define __sf_section_SECOND_PART            /* Second part region is removed */
    #define __sf_section_EMI                    __attribute__ ((section ("EMIINITCODE")))
#else
/* Reserve for MoDIS */
    #define __sf_section_RWDATA_EMI
    #define __sf_section_SECOND_PART
    #define __sf_section_EMI
#endif  // __MTK_TARGET__



#define  COMBO_MEM_TYPE_MODIFIER  __sf_section_RODATA_GFH const
#define  COMBO_MEM_INST_NAME    combo_mem_id_list

#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
  #define  COMBO_MEM_TYPE_NAME  GFH_CMEM_ID_INFO_v1
#else
  #define  COMBO_MEM_TYPE_NAME  CMEMEntryIDList
#endif

#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
#define COMBO_MEM_STRUCT_HEAD  COMBO_MEM_ID_GFH_HEADER, { COMBO_MEM_ID_VER, COMBO_MEM_DEVICE_COUNT, {
#define COMBO_MEM_STRUCT_FOOT  } }
#else
#define COMBO_MEM_STRUCT_HEAD  COMBO_MEM_IDENTITY_ID, COMBO_MEM_ID_VER, COMBO_MEM_DEVICE_COUNT, {
#define COMBO_MEM_STRUCT_FOOT  }
#endif


#include "combo_flash_id.h"       // ==== Instantiate ID table



//-----------------------------------------------------------------------------
// External Functions
//-----------------------------------------------------------------------------
extern kal_uint32 custom_get_fat_addr(void);

//-----------------------------------------------------------------------------
// Internal Functions
//-----------------------------------------------------------------------------
// ===[EMI/SFI Initialization]===
kal_int32 CMEM_EMIINIT_Index(void);
void CMEM_EMIINIT_ReadID(void *BaseAddr, kal_uint16 *flashid);

//-----------------------------------------------------------------------------
// Internal Variables
//-----------------------------------------------------------------------------
#define CMEM_INVALID_INDEX -1

#if defined(__COMBO_MEMORY_SUPPORT__)

__sf_section_RWDATA_EMI static kal_int16 cmem_emiinit_index=CMEM_INVALID_INDEX;  // Init stage only

static kal_int16 cmem_index=CMEM_INVALID_INDEX;

#endif //__COMBO_MEMORY_SUPPORT__



//-----------------------------------------------------------------------------
/*!
  @brief
    Determine whether SF ID is valid.
    Apply for MT6250 because after command issue(ex: Read ID), Data pins are in floating, may read trasient value instead of 0x00 or 0xFF.
  @retval
    KAL_TRUE: the device ID0 is valid.
    KAL_FALSE: the device ID0 is not valid.  
*/
__sf_section_SECOND_PART kal_bool CMEM_CheckValidDeviceID(kal_uint8 *id)
{
		// Serial Flash
#if defined(__SERIAL_FLASH__)
    kal_int32 i, j;
    const CMEMEntryID *id_list=NULL;
	
#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
    id_list=combo_mem_id_list.m_data.List;
#else
    id_list=combo_mem_id_list.List;
#endif	
    // seach CMEM list for specific Flash ID
    for (i=0; i<COMBO_MEM_DEVICE_COUNT; i++)	{
        // Check 1: Compare ID
        for (j=0; j<id_list[i].IDLength; j++) {
            if (id_list[i].ID[j]!=id[j]) break;
        }
        // Check 2: Compare RegionInfo
        if (j==id_list[i].IDLength)   {
            // TBD: Compare RegionInfo
            return KAL_TRUE;
        }
    }  
#endif //defined(__SERIAL_FLASH__)
    return KAL_FALSE;
}

//-----------------------------------------------------------------------------
/*!
  @brief
  Seach device in the combo MCP list by Flash ID.
    1. Read NOR/NAND flash ID
    2. Lookup ID table and return the index to the found entry.

  @retval
    The index to the found entry.
    -1 : ID not found
  @remars
    If combo MCP was not turned on, the returned index is always 0.
*/
#if defined(__COMBO_MEMORY_SUPPORT__)
#if !defined(MT6290)
extern kal_int32 EMI_QueryIsRemapped(void);
#endif

__sf_section_SECOND_PART kal_int32 CMEM_Index(void)
{
    kal_int32 i, j;
    CMEMFlashID id;
    const CMEMEntryID *id_list=NULL;

    if (cmem_index>=0) return cmem_index;

// Read Flash ID
#if defined(_NAND_FLASH_BOOTING_)
    #if defined(__UBL__)
    return CMEM_INVALID_INDEX;
    #else
    if(DAL_is_initialized == 0)
    {
    	DAL_init(); // Call DAL init to ensure FlashID alreay there.
    }
    MTD_ReadID(8, id.NAND);
    #endif
#else
  #if defined(MT6290)
  //For MT6290, No EMI driver
      #if defined(__UBL__)//BL Driver Flow
      NOR_ReadID((void *)(0xA0000000 + NOR_FLASH_BASE_ADDRESS), id.NOR);
      #else//MOLY Driver Flow
      NOR_ReadID((void *)(INT_RetrieveFlashBaseAddr() + NOR_FLASH_BASE_ADDRESS), id.NOR);
      #endif
  #else
      #if defined(__UBL__)
        //begin from MT6255, remapping is done before NOR_ReadID
        if(EMI_QueryIsRemapped())
            NOR_ReadID((void*)0x10000000, id.NOR);
        else
            NOR_ReadID((void*)0, id.NOR);
        
      #else
        NOR_ReadID((void *)(INT_RetrieveFlashBaseAddr() + NOR_FLASH_BASE_ADDRESS), id.NOR);
      #endif
  #endif
#endif

#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
    id_list=combo_mem_id_list.m_data.List;
#else
    id_list=combo_mem_id_list.List;
#endif

    // seach CMEM list for specific Flash ID
    for (i=0; i<COMBO_MEM_DEVICE_COUNT; i++)    {
        // Check 1: Compare ID
        for (j=0; j<id_list[i].IDLength; j++) {
            #if defined(_NAND_FLASH_BOOTING_)
            if (id_list[i].ID[j]!=id.NAND[j]) break;
            #else // __SERIAL_FLASH__ || NOR FLASH
            if (id_list[i].ID[j]!=id.NOR[j]) break;
            #endif
        }
        // Check 2: Compare RegionInfo
        if (j==id_list[i].IDLength)   {
            // TBD: Compare RegionInfo
            cmem_index=i;
            break;  // entry found, break the loop
        }
    }

    return cmem_index;
}


#else  // __COMBO_MEMORY_SUPPORT__

__sf_section_SECOND_PART kal_int32 CMEM_Index(void)
{
    return 0;
}

#endif // __COMBO_MEMORY_SUPPORT__

__sf_section_SECOND_PART const CMEMEntryID *CMEM_GetIDEntry(kal_uint32 index)
{
#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
        return &combo_mem_id_list.m_data.List[index];
#else
        return &combo_mem_id_list.List[index];
#endif
}


//-----------------------------------------------------------------------------
/*!
  @brief
    Read Flash ID
  @param[in] BaseAddr Base address to the Flash
  @param[out] flashid Flash ID
  @remarks
    This function is only allowed in EMI/SFI init stage.
*/
__sf_section_EMI void CMEM_EMIINIT_ReadID(void *BaseAddr, kal_uint16 *flashid)
{
    // Serial Flash
#if defined(__COMBO_MEMORY_SUPPORT__)
#if defined(__SERIAL_FLASH__)
    {
        #ifdef MT6290
	 #include "drv_spi.h"
	 kal_uint8 ReadID[8], i;
	 spi_flash_readID(ReadID);
	 for (i=0;i<SF_FLASH_ID_LENGTH;i++) flashid[i]=ReadID[i];
	 
	 #else
        kal_uint8 cmd, id[SF_FLASH_ID_LENGTH], i;

        cmd=SF_CMD_READ_ID_QPI;
        SFI_Dev_Command_Ext(&cmd, id, 1, SF_FLASH_ID_LENGTH);

        if (id[0]==0x00 || id[0]==0xFF || (CMEM_EMIINIT_CheckValidDeviceID(id) == KAL_FALSE)) {
            cmd=SF_CMD_READ_ID;
            SFI_Dev_Command_Ext(&cmd, id, 1, SF_FLASH_ID_LENGTH);
        }

        for (i=0;i<SF_FLASH_ID_LENGTH;i++) flashid[i]=id[i];
	 #endif
    }
    // ADMUX NOR Flash
#elif !defined(_NAND_FLASH_BOOTING_) // ADMUX
    {
        volatile FLASH_CELL *fp = (volatile FLASH_CELL*)(BaseAddr);

        *(fp+CFI_RDID_UNLOCK_ADR1)=CFI_RDID_UNLOCK_DAT1;
        *(fp+CFI_RDID_UNLOCK_ADR2)=CFI_RDID_UNLOCK_DAT2;
        *(fp+CFI_RDID_ADR)=CFI_RDID_CMD;

        flashid[0]=fp[0];
        flashid[1]=fp[1];
        flashid[2]=fp[2];
        flashid[3]=fp[3];

        *(fp) = CFI_CMD_EXIT1;
        *(fp) = CFI_CMD_EXIT2;

    }
#endif
#endif
    return;
}


//-----------------------------------------------------------------------------
/*!
  @brief
    Determine whether SF ID is valid.
    Apply for MT6250 because after command issue(ex: Read ID), Data pins are in floating, may read trasient value instead of 0x00 or 0xFF.
  @retval
    KAL_TRUE: the device ID0 is valid.
    KAL_FALSE: the device ID0 is not valid.  
*/
__sf_section_EMI kal_bool CMEM_EMIINIT_CheckValidDeviceID(kal_uint8 *id)
{
		// Serial Flash
#if defined(__SERIAL_FLASH__)
    kal_int32 i, j;
    const CMEMEntryID *id_list=NULL;
	// seach CMEM list for specific Flash ID
#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
    id_list=combo_mem_id_list.m_data.List;
#else
    id_list=combo_mem_id_list.List;
#endif

    for (i=0; i<COMBO_MEM_DEVICE_COUNT; i++)    {
        // Check 1: Compare ID
        for (j=0; j<id_list[i].IDLength; j++) {
            if (id_list[i].ID[j]!=id[j]) break;            
        }
        // Check 2: Compare RegionInfo
        if (j==id_list[i].IDLength)   {
            // TBD: Compare RegionInfo
           return KAL_TRUE;
        }
    }
  
#endif //defined(__SERIAL_FLASH__)
    return KAL_FALSE;
}



//-----------------------------------------------------------------------------
/*!
  @brief
    Search device ID list
  @retval
    The index to the found device ID.
    -1: device not found
  @remarks
    This function is only allowed in EMI/SFI init stage.
*/
#if defined(__COMBO_MEMORY_SUPPORT__)

__sf_section_EMI kal_int32 CMEM_EMIINIT_Index(void)
{
    kal_int32 i, j;
    CMEMFlashID id;
    const CMEMEntryID *id_list=NULL;

    if (cmem_emiinit_index>=0) return cmem_emiinit_index;

    // Read Flash ID
#if defined(_NAND_FLASH_BOOTING_)
    #if defined(__UBL__)
    NFI_ReadID(8, id.NAND);
    #else
    return CMEM_INVALID_INDEX;
    #endif
#else
    CMEM_EMIINIT_ReadID((void*)NOR_FLASH_BASE_ADDRESS, id.NOR);
#endif

// seach CMEM list for specific Flash ID
#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
    id_list=combo_mem_id_list.m_data.List;
#else
    id_list=combo_mem_id_list.List;
#endif

    for (i=0; i<COMBO_MEM_DEVICE_COUNT; i++)    {
        // Check 1: Compare ID
        for (j=0; j<id_list[i].IDLength; j++) {
            #if defined(_NAND_FLASH_BOOTING_)
            if (id_list[i].ID[j]!=id.NAND[j]) break;
            #else // Serial Flash / NOR Flash
            if (id_list[i].ID[j]!=id.NOR[j]) break;
            #endif
        }
        // Check 2: Compare RegionInfo
        if (j==id_list[i].IDLength)   {
            // TBD: Compare RegionInfo
            cmem_emiinit_index=i;
            break;
        }
    }
    return cmem_emiinit_index;  // entry not found
}

#else  // __COMBO_MEMORY_SUPPORT__

__sf_section_EMI kal_int32 CMEM_EMIINIT_Index(void)
{
    return 0;
}


#endif // __COMBO_MEMORY_SUPPORT__

#if defined(_NAND_FLASH_BOOTING_) && defined(__NAND_MDL_APPEND__)
kal_bool CMEM_GetflashInfo(kal_uint8* id, CMEMFlashInfo* st)
{
	const CMEMEntryID *flash_id_list=NULL;
	kal_uint32 icount, l_index;

	if((id == NULL) || (st == NULL))
		return KAL_FALSE;
	
	#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
        flash_id_list = combo_mem_id_list.m_data.List;
	#else
        flash_id_list = combo_mem_id_list.List;
	#endif

	for(l_index = 0; l_index < COMBO_MEM_DEVICE_COUNT; l_index++)
	{
		for(icount = 0; icount < flash_id_list[l_index].IDLength; icount++)
		{
			if (flash_id_list[l_index].ID[icount] != id[icount])
				break;
		}

		if (icount == flash_id_list[l_index].IDLength)
		{
			break;
		}
	}

	if(l_index == COMBO_MEM_DEVICE_COUNT)
		return KAL_FALSE;

	st->block_size = flash_id_list[l_index].FlashDevice_Info.block_size;
	st->page_size = flash_id_list[l_index].FlashDevice_Info.page_size;
	st->spare_size = flash_id_list[l_index].FlashDevice_Info.spare_size;
    	
	return KAL_TRUE;
}
#endif


#endif //  defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__) || defined(__NAND_MDL_APPEND__)
