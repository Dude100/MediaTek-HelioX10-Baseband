/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	nvram_el1_default.c
 *
 * Project:
 * --------
 *   MT7206RF
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 *	
 *
 *******************************************************************************/
/*===============================================================================================*/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "nvram_data_items.h"

#if defined(__LTE_RAT__)
#include "el1_rf_public.h"
#include "el1_drdi.h"

/*static*/ kal_uint8 lte_band_to_bandInd_mapping(nvram_lid_core_enum lid)
{
   kal_uint8 i;
   LTE_Band eband;

   if((lid >= NVRAM_EF_EL1_TXDAC_START) && (lid <= NVRAM_EF_EL1_TXDAC_END))
   {
      eband = lteBandIndArray[lid - NVRAM_EF_EL1_TXDAC_START + 1];
      for(i = 0; i < LTE_AUGMENTED_BAND_ARRAY_NUM; i++)
      {
         if (LTE_RampData[i] != NULL)
         {
            if(LTE_RampData[i]->band_ind == eband)
            {
               break;
            }
         }
      }
   }
   else if((lid >= NVRAM_EF_EL1_TXPAOCTLEV_START) && (lid <= NVRAM_EF_EL1_TXPAOCTLEV_END))
   {
      eband = lteBandIndArray[lid - NVRAM_EF_EL1_TXPAOCTLEV_START + 1];
      for(i = 0; i < LTE_AUGMENTED_BAND_ARRAY_NUM; i++)
      {
         if (LTE_PaOctLevTable[i] != NULL)
         {
            if(LTE_PaOctLevTable[i]->band_ind == eband)
            {
               break;
            }
         }
      }
   }
   else if((lid >= NVRAM_EF_EL1_RSSIGAINTBL_START) && (lid <= NVRAM_EF_EL1_RSSIGAINTBL_END))
   {
      eband = lteBandIndArray[lid - NVRAM_EF_EL1_RSSIGAINTBL_START + 1];
      for(i = 0; i < LTE_AUGMENTED_BAND_ARRAY_NUM; i++)
      {
         if (LTE_RSSIGainTbl[i] != NULL)
         {
            if(LTE_RSSIGainTbl[i]->bandIndex == eband)
            {
               break;
            }
         }
      }
   }   
#if IS_4G_TX_POWER_OFFSET_SUPPORT
   else if((lid >= NVRAM_EF_EL1_TX_POWER_OFFSET_START) && (lid <= NVRAM_EF_EL1_TX_POWER_OFFSET_END))
   {
      eband = lteBandIndArray[lid - NVRAM_EF_EL1_TX_POWER_OFFSET_START + 1];
      for(i = 0; i < LTE_AUGMENTED_BAND_ARRAY_NUM; i++)
      {
         if(LTE_TX_POWER_OFFSET_TABLE[i] != NULL)
         {
            if(LTE_TX_POWER_OFFSET_TABLE[i]->band_ind == eband)
            {
               break;
            }
         }
      }
   }
#endif
   else
   {
      /* Input LID out of range */
      ASSERT(0);
      return 0; // make compiler happy
   }

   /* To trap that no calibration data default value defined for the band in question */
   ASSERT(i < LTE_AUGMENTED_BAND_ARRAY_NUM);
   return i;

}

void nvram_get_eL1_default_value_to_write(nvram_lid_core_enum lid, kal_uint8 *buffer, kal_uint16 buffer_size)
{
	kal_uint8 index_select;

	switch (lid)
	{
	case NVRAM_EF_EL1_TXDAC_1STBAND_LID:
	case NVRAM_EF_EL1_TXDAC_2NDBAND_LID:
	case NVRAM_EF_EL1_TXDAC_3RDBAND_LID:
	case NVRAM_EF_EL1_TXDAC_4THBAND_LID:
	case NVRAM_EF_EL1_TXDAC_5THBAND_LID:
	case NVRAM_EF_EL1_TXDAC_6THBAND_LID:
	case NVRAM_EF_EL1_TXDAC_7THBAND_LID:
	case NVRAM_EF_EL1_TXDAC_8THBAND_LID:
	case NVRAM_EF_EL1_TXDAC_9THBAND_LID:
	case NVRAM_EF_EL1_TXDAC_10THBAND_LID:
	case NVRAM_EF_EL1_TXDAC_11THBAND_LID:
	case NVRAM_EF_EL1_TXDAC_12THBAND_LID:
	case NVRAM_EF_EL1_TXDAC_13THBAND_LID:
	case NVRAM_EF_EL1_TXDAC_14THBAND_LID:
	{
		index_select = lte_band_to_bandInd_mapping(lid);
		if (LTE_RampData[index_select] != 0)
		{
			kal_mem_cpy(buffer, LTE_RampData[index_select], sizeof(LTE_sRAMPDATA));
		}
	}
	break;

	case NVRAM_EF_EL1_TXPAOCTLEV_1STBAND_LID:
	case NVRAM_EF_EL1_TXPAOCTLEV_2NDBAND_LID:
	case NVRAM_EF_EL1_TXPAOCTLEV_3RDBAND_LID:
	case NVRAM_EF_EL1_TXPAOCTLEV_4THBAND_LID:
	case NVRAM_EF_EL1_TXPAOCTLEV_5THBAND_LID:
	case NVRAM_EF_EL1_TXPAOCTLEV_6THBAND_LID:
	case NVRAM_EF_EL1_TXPAOCTLEV_7THBAND_LID:
	case NVRAM_EF_EL1_TXPAOCTLEV_8THBAND_LID:
	case NVRAM_EF_EL1_TXPAOCTLEV_9THBAND_LID:
	case NVRAM_EF_EL1_TXPAOCTLEV_10THBAND_LID:
	case NVRAM_EF_EL1_TXPAOCTLEV_11THBAND_LID:
	case NVRAM_EF_EL1_TXPAOCTLEV_12THBAND_LID:
	case NVRAM_EF_EL1_TXPAOCTLEV_13THBAND_LID:
	case NVRAM_EF_EL1_TXPAOCTLEV_14THBAND_LID:
	{
		index_select = lte_band_to_bandInd_mapping(lid);
		if (LTE_PaOctLevTable[index_select] != 0)
		{
			kal_mem_cpy(buffer, LTE_PaOctLevTable[index_select], sizeof(LTE_sPAOCTLVLSETTING));
		}
	}
	break;
	
	case NVRAM_EF_EL1_RSSIGAINTBL_1STBAND_LID:
	case NVRAM_EF_EL1_RSSIGAINTBL_2NDBAND_LID:
	case NVRAM_EF_EL1_RSSIGAINTBL_3RDBAND_LID:
	case NVRAM_EF_EL1_RSSIGAINTBL_4THBAND_LID:
	case NVRAM_EF_EL1_RSSIGAINTBL_5THBAND_LID:
	case NVRAM_EF_EL1_RSSIGAINTBL_6THBAND_LID:
	case NVRAM_EF_EL1_RSSIGAINTBL_7THBAND_LID:
	case NVRAM_EF_EL1_RSSIGAINTBL_8THBAND_LID:
	case NVRAM_EF_EL1_RSSIGAINTBL_9THBAND_LID:
	case NVRAM_EF_EL1_RSSIGAINTBL_10THBAND_LID:
	case NVRAM_EF_EL1_RSSIGAINTBL_11THBAND_LID:
	case NVRAM_EF_EL1_RSSIGAINTBL_12THBAND_LID:
	case NVRAM_EF_EL1_RSSIGAINTBL_13THBAND_LID:
	case NVRAM_EF_EL1_RSSIGAINTBL_14THBAND_LID:
	{
		index_select = lte_band_to_bandInd_mapping(lid);
		if (LTE_RSSIGainTbl[index_select] != 0)
		{
			kal_mem_cpy(buffer, LTE_RSSIGainTbl[index_select], sizeof(LTE_RSSIBandGainTable));
		}
	}
	break;
	
	case NVRAM_EF_EL1_FREQADJTBL_LID:
	{
		kal_mem_cpy(buffer, LTE_FreqAdjustTbl[0], sizeof(LTE_FreqAdjustTable));
	}
	break;
	 
	case NVRAM_EF_EL1_ETVINLUTDATA_1STBAND_LID:
	case NVRAM_EF_EL1_ETVINLUTDATA_2NDBAND_LID:
	case NVRAM_EF_EL1_ETVINLUTDATA_3RDBAND_LID:
	case NVRAM_EF_EL1_ETVINLUTDATA_4THBAND_LID:
	case NVRAM_EF_EL1_ETVINLUTDATA_5THBAND_LID:
	case NVRAM_EF_EL1_ETVINLUTDATA_6THBAND_LID:
	case NVRAM_EF_EL1_ETVINLUTDATA_7THBAND_LID:
	case NVRAM_EF_EL1_ETVINLUTDATA_8THBAND_LID:
	case NVRAM_EF_EL1_ETVINLUTDATA_9THBAND_LID:
	case NVRAM_EF_EL1_ETVINLUTDATA_10THBAND_LID:
	case NVRAM_EF_EL1_ETVINLUTDATA_11THBAND_LID:
	case NVRAM_EF_EL1_ETVINLUTDATA_12THBAND_LID:
	case NVRAM_EF_EL1_ETVINLUTDATA_13THBAND_LID:
	case NVRAM_EF_EL1_ETVINLUTDATA_14THBAND_LID:
	{
		kal_mem_cpy(buffer, 
			LTE_EtVinLutTbl[lid-NVRAM_EF_EL1_ETVINLUTDATA_1STBAND_LID], 
			sizeof(LTE_RfcEtVinLutPerBand_T));
	}
	break;
	
	case NVRAM_EF_EL1_ETCOMPPARAM_LID:
	{
		kal_mem_cpy(buffer, LTE_EtCompParamTbl, sizeof(LTE_RfcEtCompParam_T));
	}
	break;
	
	case NVRAM_EF_EL1_TEMPERATUREDAC_LID:
	{
	  kal_mem_cpy(buffer, LTE_TEMP_DAC, sizeof(LTE_TemperatureDac_T));
    }
	break;

	case NVRAM_EF_EL1_MPRADJTBL_LID:
	{
	  kal_mem_cpy(buffer, LTE_MPRAdjustTbl, NVRAM_EF_EL1_MPRADJTBL_SIZE);
    }
	break;

	case NVRAM_EF_EL1_AMPRADJTBL_LID:
	{
	  kal_mem_cpy(buffer, LTE_AMPRAdjustTbl, NVRAM_EF_EL1_AMPRADJTBL_SIZE);
    }
	break;

  case NVRAM_EF_EL1_BAND_INDICATOR_LID:
  {
     kal_mem_cpy(buffer, lteBandIndArray, NVRAM_EF_EL1_BAND_INDICATOR_SIZE);
  }
  break;

  case NVRAM_EF_EL1_RX_PDATABASE_LID:
  {
  	kal_mem_cpy(buffer, ERF_RX_PDATABASE, NVRAM_EF_EL1_RX_PDATABASE_SIZE);
  }
  break;

  case NVRAM_EF_EL1_TX_PDATABASE_LID:
  {
  	kal_mem_cpy(buffer, ERF_TX_PDATABASE, NVRAM_EF_EL1_TX_PDATABASE_SIZE);
  }
  break;

  case NVRAM_EF_EL1_RXON_BPIOFFSET_LID:
  {
  	kal_mem_cpy(buffer, &ERF_RXON_BPIOFFSET, NVRAM_EF_EL1_RXON_BPIOFFSET_SIZE);
  }
  break;

  case NVRAM_EF_EL1_TXON_BPIOFFSET_LID:
  {
  	kal_mem_cpy(buffer, &ERF_TXON_BPIOFFSET, NVRAM_EF_EL1_TXON_BPIOFFSET_SIZE);
  }
  break;

  case NVRAM_EF_EL1_RXOFF_BPIOFFSET_LID:
  {
  	kal_mem_cpy(buffer, &ERF_RXOFF_BPIOFFSET, NVRAM_EF_EL1_RXOFF_BPIOFFSET_SIZE);
  }
  break;

  case NVRAM_EF_EL1_TXOFF_BPIOFFSET_LID:
  {
  	kal_mem_cpy(buffer, &ERF_TXOFF_BPIOFFSET, NVRAM_EF_EL1_TXOFF_BPIOFFSET_SIZE);
  }
  break;

  case NVRAM_EF_EL1_RF_IO_LID:
  {
     kal_mem_cpy(buffer, ERF_RF_IOBASE, NVRAM_EF_EL1_RF_IO_SIZE);
  }
  break;

  case NVRAM_EF_EL1_CUSTOM_DYNAMIC_INIT_LID:
  {
     /* Dynamic-Radio-setting Dedicated Image (DRDI): Enable read from custom folder setting */
     kal_mem_cpy(buffer, &LTE_DRDI_STATUS, NVRAM_EF_EL1_CUSTOM_DYNAMIC_INIT_SIZE);
  }
  break;

  /* Single ANT Feature */
  case NVRAM_EF_EL1_RF_RX_PATH_CONFIG_LID:
  {
     kal_mem_cpy(buffer, &LTE_RF_RX_PATH_CONFIG_DEFAULT, NVRAM_EF_EL1_RF_RX_PATH_CONFIG_SIZE);
  }
  break;
  
  case NVRAM_EF_EL1_MIPI_FEATURE_LID:
  {
  	kal_mem_cpy(buffer, &LTE_MIPI_ENABLE, NVRAM_EF_EL1_MIPI_FEATURE_SIZE);
  }
  break;
  
  case NVRAM_EF_EL1_MIPI_RX_EVENT_1STBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_EVENT_2NDBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_EVENT_3RDBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_EVENT_4THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_EVENT_5THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_EVENT_6THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_EVENT_7THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_EVENT_8THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_EVENT_9THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_EVENT_10THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_EVENT_11THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_EVENT_12THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_EVENT_13THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_EVENT_14THBAND_LID:
  {
     if(LTE_MIPI_ENABLE == 1)
     {
        kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE);
        kal_mem_cpy(buffer,
        LTE_MIPI_RX_EVENT_TABLE[(lid-NVRAM_EF_EL1_MIPI_RX_EVENT_1STBAND_LID+1)], 
        LTE_MIPI_RX_EVENT_SIZE_TABLE[(lid-NVRAM_EF_EL1_MIPI_RX_EVENT_1STBAND_LID+1)]);
     }
  }
	break;

  case NVRAM_EF_EL1_MIPI_TX_EVENT_1STBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_EVENT_2NDBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_EVENT_3RDBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_EVENT_4THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_EVENT_5THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_EVENT_6THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_EVENT_7THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_EVENT_8THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_EVENT_9THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_EVENT_10THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_EVENT_11THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_EVENT_12THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_EVENT_13THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_EVENT_14THBAND_LID:
  {
     if(LTE_MIPI_ENABLE == 1)
     {
        kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE);

        kal_mem_cpy(buffer,
        LTE_MIPI_TX_EVENT_TABLE[(lid-NVRAM_EF_EL1_MIPI_TX_EVENT_1STBAND_LID+1)],
        LTE_MIPI_TX_EVENT_SIZE_TABLE[(lid-NVRAM_EF_EL1_MIPI_TX_EVENT_1STBAND_LID+1)]);
     }
  }
	break;

  case NVRAM_EF_EL1_MIPI_TPC_EVENT_1STBAND_LID:
  case NVRAM_EF_EL1_MIPI_TPC_EVENT_2NDBAND_LID:
  case NVRAM_EF_EL1_MIPI_TPC_EVENT_3RDBAND_LID:
  case NVRAM_EF_EL1_MIPI_TPC_EVENT_4THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TPC_EVENT_5THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TPC_EVENT_6THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TPC_EVENT_7THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TPC_EVENT_8THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TPC_EVENT_9THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TPC_EVENT_10THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TPC_EVENT_11THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TPC_EVENT_12THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TPC_EVENT_13THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TPC_EVENT_14THBAND_LID:
  {
     if(LTE_MIPI_ENABLE == 1)
     {
        kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE);

        kal_mem_cpy(buffer,
        LTE_MIPI_TPC_EVENT_TABLE[(lid-NVRAM_EF_EL1_MIPI_TPC_EVENT_1STBAND_LID+1)],
        LTE_MIPI_TPC_EVENT_SIZE_TABLE[(lid-NVRAM_EF_EL1_MIPI_TPC_EVENT_1STBAND_LID+1)]);
     }
  }
	break;

  case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_1STBAND_LID:
  case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_2NDBAND_LID:
  case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_3RDBAND_LID:
  case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_4THBAND_LID:
  case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_5THBAND_LID:
  case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_6THBAND_LID:
  case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_7THBAND_LID:
  case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_8THBAND_LID:
  case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_9THBAND_LID:
  case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_10THBAND_LID:
  case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_11THBAND_LID:
  case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_12THBAND_LID:
  case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_13THBAND_LID:
  case NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_14THBAND_LID:
  {
     if(LTE_MIPI_ENABLE == 1)
     {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE);

         kal_mem_cpy(buffer,
         LTE_MIPI_PA_TPC_SECTION_DATA[(lid-NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_1STBAND_LID+1)],
         LTE_MIPI_PA_TPC_SECTION_DATA_SIZE[(lid-NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_1STBAND_LID+1)]);
     }
	}
  break;

  case NVRAM_EF_EL1_MIPI_RX_DATA_1STBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_DATA_2NDBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_DATA_3RDBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_DATA_4THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_DATA_5THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_DATA_6THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_DATA_7THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_DATA_8THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_DATA_9THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_DATA_10THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_DATA_11THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_DATA_12THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_DATA_13THBAND_LID:
  case NVRAM_EF_EL1_MIPI_RX_DATA_14THBAND_LID:
  {
     if(LTE_MIPI_ENABLE == 1)
     {
        kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_RX_DATA_SIZE);

        kal_mem_cpy(buffer,
        LTE_MIPI_RX_DATA_TABLE[(lid-NVRAM_EF_EL1_MIPI_RX_DATA_1STBAND_LID+1)],
        LTE_MIPI_RX_DATA_SIZE_TABLE[(lid-NVRAM_EF_EL1_MIPI_RX_DATA_1STBAND_LID+1)]);
     }
  }
	break;

  case NVRAM_EF_EL1_MIPI_TX_DATA_1STBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_DATA_2NDBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_DATA_3RDBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_DATA_4THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_DATA_5THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_DATA_6THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_DATA_7THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_DATA_8THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_DATA_9THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_DATA_10THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_DATA_11THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_DATA_12THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_DATA_13THBAND_LID:
  case NVRAM_EF_EL1_MIPI_TX_DATA_14THBAND_LID:
  {
     if(LTE_MIPI_ENABLE == 1)
     {
        kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_TX_DATA_SIZE);

        kal_mem_cpy(buffer,
        LTE_MIPI_TX_DATA_TABLE[(lid-NVRAM_EF_EL1_MIPI_TX_DATA_1STBAND_LID+1)],
        LTE_MIPI_TX_DATA_SIZE_TABLE[(lid-NVRAM_EF_EL1_MIPI_TX_DATA_1STBAND_LID+1)]);
     }
  }
	break;

  case NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_1STBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_2NDBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_3RDBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_4THBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_5THBAND_LID:
  {
     if(LTE_MIPI_BYPASS_FEATURE_ENABLE == 1)
     {
        kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_SIZE);

        kal_mem_cpy(buffer,
        LTE_MIPI_BYPASS_TX_DATA_TABLE[(lid-NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_1STBAND_LID+1)],
        LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE[(lid-NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_1STBAND_LID+1)]);
     }
  }
	break;

  case NVRAM_EF_EL1_MIPI_BYPASS_FEATURE_LID:
  {
  	kal_mem_cpy(buffer, &LTE_MIPI_BYPASS_FEATURE_ENABLE, NVRAM_EF_EL1_MIPI_BYPASS_FEATURE_SIZE);
  }
  break;
  
  case NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_1STBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_2NDBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_3RDBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_4THBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_5THBAND_LID:
  {
     if(LTE_MIPI_BYPASS_FEATURE_ENABLE == 1)
     {
        kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_SIZE);

        kal_mem_cpy(buffer,
        LTE_MIPI_BYPASS_TX_EVENT_TABLE[(lid-NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_1STBAND_LID+1)],
        LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE[(lid-NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_1STBAND_LID+1)]);
     }
  }
  break;

  case NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_1STBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_2NDBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_3RDBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_4THBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_5THBAND_LID:
  {
     if(LTE_MIPI_BYPASS_FEATURE_ENABLE == 1)
     {
        kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_SIZE);

        kal_mem_cpy(buffer,
        LTE_MIPI_BYPASS_TPC_EVENT_TABLE[(lid-NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_1STBAND_LID+1)],
        LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE[(lid-NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_1STBAND_LID+1)]);
     }
  }
  break;

  case NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_1STBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_2NDBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_3RDBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_4THBAND_LID:
  case NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_5THBAND_LID:
  {
     if(LTE_MIPI_BYPASS_FEATURE_ENABLE == 1)
     {
         kal_mem_set(buffer, 0, NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE);

         kal_mem_cpy(buffer,
         LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA[(lid-NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_1STBAND_LID+1)],
         LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE[(lid-NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_1STBAND_LID+1)]);
     }
  }
  break;

#if IS_4G_TX_POWER_OFFSET_SUPPORT
  case NVRAM_EF_EL1_4G_TPO_PARAMETER_LID:
  {
     kal_mem_cpy(buffer, &LTE_TPO_CUSTOM_INPUT_DATA, NVRAM_EF_EL1_4G_TPO_PARAMETER_SIZE);
  }
  break;

  case NVRAM_EF_EL1_TX_POWER_OFFSET_1STBAND_LID:
  case NVRAM_EF_EL1_TX_POWER_OFFSET_2NDBAND_LID:
  case NVRAM_EF_EL1_TX_POWER_OFFSET_3RDBAND_LID:
  case NVRAM_EF_EL1_TX_POWER_OFFSET_4THBAND_LID:
  case NVRAM_EF_EL1_TX_POWER_OFFSET_5THBAND_LID:
  case NVRAM_EF_EL1_TX_POWER_OFFSET_6THBAND_LID:
  case NVRAM_EF_EL1_TX_POWER_OFFSET_7THBAND_LID:
  case NVRAM_EF_EL1_TX_POWER_OFFSET_8THBAND_LID:
  case NVRAM_EF_EL1_TX_POWER_OFFSET_9THBAND_LID:
  case NVRAM_EF_EL1_TX_POWER_OFFSET_10THBAND_LID:
  case NVRAM_EF_EL1_TX_POWER_OFFSET_11THBAND_LID:
  case NVRAM_EF_EL1_TX_POWER_OFFSET_12THBAND_LID:
  case NVRAM_EF_EL1_TX_POWER_OFFSET_13THBAND_LID:
  case NVRAM_EF_EL1_TX_POWER_OFFSET_14THBAND_LID:
  {
     index_select = lte_band_to_bandInd_mapping(lid);
     if (LTE_TX_POWER_OFFSET_TABLE[index_select] != 0)
     {
        kal_mem_cpy(buffer, LTE_TX_POWER_OFFSET_TABLE[index_select], sizeof(ERf_TXPOWEROFFSETDATA));
     }
  }
  break;
#endif

#if defined(__TAS_SUPPORT__)
  case NVRAM_EF_EL1_TAS_PARAMETER_LID:
  {
     kal_mem_cpy(buffer, &EL1_TAS_PARAMETER_TABLE, NVRAM_EF_EL1_TAS_PARAMETER_SIZE);
  }
  break;

  #if defined(__TAS_INTERNAL_NVRAM_VISIBLE__)
  case NVRAM_EF_EL1_TAS_OTHER_LID:
  {
     kal_mem_cpy(buffer, &EL1_TAS_OTHER_TABLE, NVRAM_EF_EL1_TAS_OTHER_SIZE);
  }
  break;
  #endif
#endif

  default:
     ASSERT(KAL_FALSE);
  break;
  }
}

#endif
