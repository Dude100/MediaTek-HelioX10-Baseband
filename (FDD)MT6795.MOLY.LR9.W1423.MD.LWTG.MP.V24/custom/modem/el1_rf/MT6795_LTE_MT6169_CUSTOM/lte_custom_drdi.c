/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	lte_custom_drdi.c
 *
 * Project:
 * --------
 *  MOLY
 *
 * Description:
 * ------------
 *  Dynamic Radio-setting Dedicated Image.
 *  RF parameters data input file
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/

#ifdef __MTK_TARGET__

/*******************************************************************************
** Includes
*******************************************************************************/
#include "lte_custom_drdi.h"
#include "lte_custom_mipi.h"   // for DRDI of MIPI usage
#include "lte_custom_rf.h"

/***************************************************************************
 * Global Data
 ***************************************************************************/
/* Look up table from action id to action function
 * See the enum #El1CustomFunction for members of
 * the table */
const El1CustomFunction el1CustomActionTable[EL1_CUSTOM_MAX_PROC_ACTIONS] =
{
   NULL,

#if EL1_CUSTOM_GPIO_ENABLE
   EPHY_CUSTOM_DynamicInitByGPIO,
#else
   NULL, /* Null action */
#endif

#if EL1_CUSTOM_ADC_ENABLE
   EPHY_CUSTOM_DynamicInitByADC,
#else
   NULL, /* Null action */
#endif

#if EL1_CUSTOM_BARCODE_ENABLE
   EPHY_CUSTOM_DynamicInitByBarcode
#else
   NULL  /* Null action */
#endif
};
#if defined(__LTE_BPI_TIMING_DRDI_SUPPORT__)
#define MICROSECOND_TO_26M(x)                      ((kal_int32)((x)*26))
#endif

/***************************************************************************
 * Data array of pointers pointed to data array for custom data
 ***************************************************************************/
//********************************************
// LTE Band Indicator Custom data definition
//********************************************
/* Pointer array for customer to input 4G band support parameters
 * with pointers for each of the configuration set to be detected */
LTE_Band                                 *el1_rf_bandind_array_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];

//**************************************
// LTE BPI data Custom data definition
//**************************************
/* Pointer array for customer to input 4G BPI data parameters
 * with pointers for each of the configuration set to be detected */
El1CustomDynamicInitLteBpiData           *el1_rf_bpidata_array_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];

#if defined(__LTE_BPI_TIMING_DRDI_SUPPORT__)
//**************************************
// LTE BPI Timing Custom data definition
//**************************************
/* Pointer array for customer to input 4G BPI data parameters
 * with pointers for each of the configuration set to be detected */
El1CustomDynamicInitLteBpiTiming         *el1_rf_bpitiming_array_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];
#endif

//***************************************************
// LTE LNA port/Tx path data Custom data definition
//***************************************************
/* Pointer array for customer to input 4G LNA port and TX path parameters by band
 * with pointers for each of the configuration set to be detected */
El1CustomDynamicInitLteRxLnaPortTxPath   *el1_rf_lna_txpath_array_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];

//***************************************************
// LTE splitting band Custom data definition
//***************************************************
/* Pointer array for customer to input 4G splitting band parameters
 * with pointers for each of the configuration set to be detected */
El1CustomDynamicInitLteSplitBandInd      *el1_rf_splitbandind_array_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];

//***************************************************
// LTE BPI/LNA port/Tx path data Custom data definition
//***************************************************
/* Pointer array for customer to input 4G BPI, LNA port, and TX path parameters by band
 * with pointers for each of the configuration set to be detected */
El1CustomDynamicInitLteSplitRfData       *el1_rf_splitrfdata_array_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];

//***************************************************
// LTE Transmit Antenna Selection data Custom data definition
//***************************************************
/* Pointer array for customer to input Transmit Antenna Seletction parameters
 * with pointers for each of the configuration set to be detected */
#if defined(__TAS_SUPPORT__)
El1CustomDynamicInitLteTASParameter       *el1_rf_tas_parameter_array_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];
#endif

//*************************************************
// LTE Tx calibration data Custom data definition
//*************************************************
// Tx Ramp data
/* Pointer array for customer to input 4G TX Ramp calibration data
 * with pointers for each of the configuration set to be detected */
El1CustomDynamicInitLteTxRampData        *el1_rf_txramp_array_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];

// Tx PA oct-level data
/* Pointer array for customer to input 4G TX oct-level calibration data
 * with pointers for each of the configuration set to be detected */
El1CustomDynamicInitLteTxPaOctLvlData    *el1_rf_txoctlvl_array_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];

//*************************************************
// LTE Rx calibration data Custom data definition
//*************************************************
/* Pointer array for customer to input 4G RX path loss calibration data
 * with pointers for each of the configuration set to be detected */
El1CustomDynamicInitLteRxPathLossData    *el1_rf_rxpathloss_array_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];

//*********************************************
// LTE Temperature DAC Custom data definition
//*********************************************
/* Pointer array for customer to input 4G Temp. DAC calibration data
 * with pointers for each of the configuration set to be detected */
El1CustomDynamicInitLteTempDac           *el1_rf_tempdac_array_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];

//******************************************************
// LTE Tx PRACH TM Compensation Custom data definition
//******************************************************
/* Pointer array for customer to input 4G Tx PRACH TM Compensation calibration data
 * with pointers for each of the configuration set to be detected */
//El1CustomDynamicInitLteTxPrachTmCompData *el1_rf_txprachtmcomp_array_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];



/***************************************************************************
 * Data definition for custom to input data
 ***************************************************************************/
//********************************************
// LTE Band Indicator Custom data definition
//********************************************
LTE_Band el1CustomLteBand[EL1_CUSTOM_TOTAL_SET_NUMS][EL1_CUSTOM_MAX_RF_SUPPORT_BAND_NUM] =
{
 //{/*Set XX*/ band_idx 0  , band_idx 1  , band_idx 2  , band_idx 3  , band_idx 4  , band_idx 5  , band_idx 6  , band_idx 7  , band_idx 8  , band_idx 9  , band_idx 10 , band_idx 11 , band_idx 12 , band_idx 13 },
   {/*Set  0*/ LTE_Band1   , LTE_Band3   , LTE_Band7   , LTE_Band17  , LTE_Band38  , LTE_Band39  , LTE_Band40  , LTE_Band41  , LTE_Band8   , LTE_Band5   , LTE_BandNone, LTE_BandNone, LTE_BandNone, LTE_BandNone}, 
#if EL1_CUSTOM_DYNAMIC_INIT_ENABLE
   {/*Set  1*/ LTE_Band1   , LTE_Band3   , LTE_Band7   , LTE_Band17  , LTE_Band38  , LTE_Band39  , LTE_Band40  , LTE_Band41  , LTE_Band8   , LTE_Band28  , LTE_BandNone, LTE_BandNone, LTE_BandNone, LTE_BandNone},
   {/*Set  2*/ LTE_Band1   , LTE_Band3   , LTE_Band7   , LTE_Band28  , LTE_Band38  , LTE_Band39  , LTE_Band40  , LTE_Band41  , LTE_Band8   , LTE_BandNone  , LTE_BandNone, LTE_BandNone, LTE_BandNone, LTE_BandNone},
#endif
   /*** APPEND new set of custom data HERE ***/      
};

//**************************************
// LTE BPI data Custom data definition
//**************************************
El1CustomDynamicInitLteBpiData el1CustomLteBpiData[EL1_CUSTOM_TOTAL_SET_NUMS][EL1_CUSTOM_MAX_RF_SUPPORT_BAND_NUM] =
{
 //{/*Set XX*//*band_idx XX*/{Band        , {PR1       , PR2       , PR3            , PT1       , PT2       , PT3            }},
   {/*Set  0*//*band_idx  0*/{LTE_Band1   , {0x00120810, 0x00120810, LTE_PDATA_OFF  , 0x00120810, 0x00120810, LTE_PDATA_OFF  }},
              /*band_idx  1*/{LTE_Band3   , {0x000118000,0x000118000, LTE_PDATA_OFF , 0x000118000,0x000118000, LTE_PDATA_OFF  }},
              /*band_idx  2*/{LTE_Band7   , {0x02824001, 0x02824001, LTE_PDATA_OFF  , 0x02824001, 0x02824001, LTE_PDATA_OFF  }},
              /*band_idx  3*/{LTE_Band17  , {0x00114004, 0x00114004, LTE_PDATA_OFF  , 0x00114004, 0x00114004, LTE_PDATA_OFF  }},
              /*band_idx  4*/{LTE_Band38  , {0x02DCE001, 0x02DCE001, LTE_PDATA_OFF  , 0x039C0000, 0x039C0000, LTE_PDATA_OFF  }},
              /*band_idx  5*/{LTE_Band39  , {0x00108000, 0x00108000, LTE_PDATA_OFF  , 0x00140000, 0x00140000, LTE_PDATA_OFF  }},
              /*band_idx  6*/{LTE_Band40  , {0x02084001, 0x02084001, LTE_PDATA_OFF  , 0x010C0000, 0x010C0000, LTE_PDATA_OFF  }},
              /*band_idx  7*/{LTE_Band41  , {0x02DCE001, 0x02DCE001, LTE_PDATA_OFF  , 0x039C0000, 0x039C0000, LTE_PDATA_OFF  }},
              /*band_idx  8*/{LTE_Band8   , {0x00111000, 0x00111000, LTE_PDATA_OFF  , 0x00100000, 0x00100000, LTE_PDATA_OFF  }},
              /*band_idx  9*/{LTE_Band5   , {0x00134000, 0x00134000, LTE_PDATA_OFF  , 0x00100000, 0x00100000, LTE_PDATA_OFF  }},
              /*band_idx 10*/{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF  , 0x0       , 0x0       , LTE_PDATA_OFF  }},
              /*band_idx 11*/{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF  , 0x0       , 0x0       , LTE_PDATA_OFF  }},
              /*band_idx 12*/{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF  , 0x0       , 0x0       , LTE_PDATA_OFF  }},
              /*band_idx 13*/{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF  , 0x0       , 0x0       , LTE_PDATA_OFF  }}
   },
#if EL1_CUSTOM_DYNAMIC_INIT_ENABLE
   {/*Set  1*//*band_idx  0*/{LTE_Band1   , {0x00120810, 0x00120810, LTE_PDATA_OFF  , 0x00120810, 0x00120810, LTE_PDATA_OFF  }},
              /*band_idx  1*/{LTE_Band3   , {0x000118000, 0x000118000, LTE_PDATA_OFF  , 0x000118000, 0x000118000, LTE_PDATA_OFF  }},
              /*band_idx  2*/{LTE_Band7   , {0x02824001, 0x02824001, LTE_PDATA_OFF  , 0x02824001, 0x02824001, LTE_PDATA_OFF  }},
              /*band_idx  3*/{LTE_Band17  , {0x00114004, 0x00114004, LTE_PDATA_OFF  , 0x00114004, 0x00114004, LTE_PDATA_OFF  }},
              /*band_idx  4*/{LTE_Band38  , {0x02DCE001, 0x02DCE001, LTE_PDATA_OFF  , 0x039C0000, 0x039C0000, LTE_PDATA_OFF  }},
              /*band_idx  5*/{LTE_Band39  , {0x00108000, 0x00108000, LTE_PDATA_OFF  , 0x00140000, 0x00140000, LTE_PDATA_OFF  }},
              /*band_idx  6*/{LTE_Band40  , {0x02084001, 0x02084001, LTE_PDATA_OFF  , 0x010C0000, 0x010C0000, LTE_PDATA_OFF  }},
              /*band_idx  7*/{LTE_Band41  , {0x02DCE001, 0x02DCE001, LTE_PDATA_OFF  , 0x039C0000, 0x039C0000, LTE_PDATA_OFF  }},
              /*band_idx  8*/{LTE_Band8   , {0x00111000, 0x00111000, LTE_PDATA_OFF  , 0x00100000, 0x00100000, LTE_PDATA_OFF  }},
              /*band_idx  9*/{LTE_Band28  , {0x00134000, 0x00134000, LTE_PDATA_OFF  , 0x00100000, 0x00100000, LTE_PDATA_OFF  }},
              /*band_idx 10*/{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF  , 0x0       , 0x0       , LTE_PDATA_OFF  }},
              /*band_idx 11*/{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF  , 0x0       , 0x0       , LTE_PDATA_OFF  }},
              /*band_idx 12*/{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF  , 0x0       , 0x0       , LTE_PDATA_OFF  }},
              /*band_idx 13*/{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF  , 0x0       , 0x0       , LTE_PDATA_OFF  }}
   },
   {/*Set  2*//*band_idx  0*/{LTE_Band1   , {0x00120810, 0x00120810, LTE_PDATA_OFF  , 0x00120810, 0x00120810, LTE_PDATA_OFF  }},    
              /*band_idx  1*/{LTE_Band3   , {0x000118000, 0x000118000, LTE_PDATA_OFF  , 0x000118000, 0x000118000, LTE_PDATA_OFF  }},
              /*band_idx  2*/{LTE_Band7   , {0x02824001, 0x02824001, LTE_PDATA_OFF  , 0x02824001, 0x02824001, LTE_PDATA_OFF  }},    
              /*band_idx  3*/{LTE_Band28  , {0x00114004, 0x00114004, LTE_PDATA_OFF  , 0x00114004, 0x00114004, LTE_PDATA_OFF  }},
              /*band_idx  4*/{LTE_Band38  , {0x02DCE001, 0x02DCE001, LTE_PDATA_OFF  , 0x039C0000, 0x039C0000, LTE_PDATA_OFF  }},
              /*band_idx  5*/{LTE_Band39  , {0x00108000, 0x00108000, LTE_PDATA_OFF  , 0x00140000, 0x00140000, LTE_PDATA_OFF  }},
              /*band_idx  6*/{LTE_Band40  , {0x02084001, 0x02084001, LTE_PDATA_OFF  , 0x010C0000, 0x010C0000, LTE_PDATA_OFF  }},
              /*band_idx  7*/{LTE_Band41  , {0x02DCE001, 0x02DCE001, LTE_PDATA_OFF  , 0x039C0000, 0x039C0000, LTE_PDATA_OFF  }},
              /*band_idx  8*/{LTE_Band8   , {0x00111000, 0x00111000, LTE_PDATA_OFF  , 0x00100000, 0x00100000, LTE_PDATA_OFF  }},
              /*band_idx  9*/{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF  , 0x0       , 0x0       , LTE_PDATA_OFF  }},
              /*band_idx 10*/{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF  , 0x0       , 0x0       , LTE_PDATA_OFF  }},
              /*band_idx 11*/{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF  , 0x0       , 0x0       , LTE_PDATA_OFF  }},
              /*band_idx 12*/{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF  , 0x0       , 0x0       , LTE_PDATA_OFF  }},
              /*band_idx 13*/{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF  , 0x0       , 0x0       , LTE_PDATA_OFF  }}
   },
#endif
   /*** APPEND new set of custom data HERE ***/
};


#if defined(__LTE_BPI_TIMING_DRDI_SUPPORT__)
//**************************************
// LTE BPI Timin Custom data definition
//**************************************
El1CustomDynamicInitLteBpiTiming el1CustomLteBpiTiming[EL1_CUSTOM_TOTAL_SET_NUMS] =
{

 //{/*Set  0*/{ {TC_FPR1               , TC_FPR2               , TC_FPR3               , TC_FPT1               , TC_FPT2             , TC_FPT3            }},
    /*Set  0*/{ MICROSECOND_TO_26M(105), MICROSECOND_TO_26M(26), MICROSECOND_TO_26M(15), MICROSECOND_TO_26M(9), MICROSECOND_TO_26M(8), MICROSECOND_TO_26M(5),
 //{/*Set  0*/{ {TC_TPR1               , TC_TPR2               , TC_TPR3               , TC_TPT1              , TC_TPT2              , TC_TPT3            }},
                MICROSECOND_TO_26M(21) , MICROSECOND_TO_26M(20), MICROSECOND_TO_26M(1) , MICROSECOND_TO_26M(5), MICROSECOND_TO_26M(4), MICROSECOND_TO_26M(1)
              },
   #if EL1_CUSTOM_DYNAMIC_INIT_ENABLE
 //{/*Set  1*/{ {TC_FPR1               , TC_FPR2               , TC_FPR3               , TC_FPT1               , TC_FPT2             , TC_FPT3            }},
    /*Set  1*/{ MICROSECOND_TO_26M(106), MICROSECOND_TO_26M(27), MICROSECOND_TO_26M(16), MICROSECOND_TO_26M(10), MICROSECOND_TO_26M(9), MICROSECOND_TO_26M(6),
 //{/*Set  1*/{ {TC_TPR1               , TC_TPR2               , TC_TPR3               , TC_TPT1              , TC_TPT2              , TC_TPT3            }},
                MICROSECOND_TO_26M(22) , MICROSECOND_TO_26M(21), MICROSECOND_TO_26M(2) , MICROSECOND_TO_26M(6), MICROSECOND_TO_26M(5), MICROSECOND_TO_26M(2)
              },
   #endif
   /*** APPEND new set of custom data HERE ***/
};
#endif

//***************************************************
// LTE RX LNA port/Tx path data Custom data definition
//***************************************************
El1CustomDynamicInitLteRxLnaPortTxPath el1CustomLteRxLnaPortTxPath[EL1_CUSTOM_TOTAL_SET_NUMS][EL1_CUSTOM_MAX_RF_SUPPORT_BAND_NUM] =
{
 //{/*Set XX*//*band_idx XX*/{Band          , RX_IO         , RXD_IO         , TX_IO         },
   {/*Set  0*//*band_idx  0*/{LTE_Band1     , RX_IO_HB1     , RXD_IO_HB2     , TX_IO_MB2     },
              /*band_idx  1*/{LTE_Band3     , RX_IO_HB1     , RXD_IO_MB1     , TX_IO_MB2     },
              /*band_idx  2*/{LTE_Band7     , RX_IO_HB3     , RXD_IO_HB2     , TX_IO_HB2     },
              /*band_idx  3*/{LTE_Band17    , RX_IO_LB1     , RXD_IO_LB1     , TX_IO_LB2     },
              /*band_idx  4*/{LTE_Band38    , RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     },
              /*band_idx  5*/{LTE_Band39    , RX_IO_MB2     , RXD_IO_MB2     , TX_IO_MB2     },
              /*band_idx  6*/{LTE_Band40    , RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     },
              /*band_idx  7*/{LTE_Band41    , RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     },
              /*band_idx  8*/{LTE_Band8     , RX_IO_LB2     , RXD_IO_LB1     , TX_IO_LB2     },
              /*band_idx  9*/{LTE_Band5     , RX_IO_LB3     , RXD_IO_LB2     , TX_IO_LB2     },
              /*band_idx 10*/{LTE_BandNone  , RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED},
              /*band_idx 11*/{LTE_BandNone  , RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED},
              /*band_idx 12*/{LTE_BandNone  , RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED},
              /*band_idx 13*/{LTE_BandNone  , RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}
   }, 
#if EL1_CUSTOM_DYNAMIC_INIT_ENABLE
   {/*Set  1*//*band_idx  0*/{LTE_Band1     , RX_IO_HB1     , RXD_IO_HB2     , TX_IO_MB2     },
              /*band_idx  1*/{LTE_Band3     , RX_IO_HB1     , RXD_IO_MB1     , TX_IO_MB2     },
              /*band_idx  2*/{LTE_Band7     , RX_IO_HB3     , RXD_IO_HB2     , TX_IO_HB2     },
              /*band_idx  3*/{LTE_Band17    , RX_IO_LB1     , RXD_IO_LB1     , TX_IO_LB2     },
              /*band_idx  4*/{LTE_Band38    , RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     },
              /*band_idx  5*/{LTE_Band39    , RX_IO_MB2     , RXD_IO_MB2     , TX_IO_MB2     },
              /*band_idx  6*/{LTE_Band40    , RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     },
              /*band_idx  7*/{LTE_Band41    , RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     },
              /*band_idx  8*/{LTE_Band8     , RX_IO_LB2     , RXD_IO_LB1     , TX_IO_LB2     },
              /*band_idx  9*/{LTE_Band28    , RX_IO_LB3     , RXD_IO_LB2     , TX_IO_LB2     },
              /*band_idx 10*/{LTE_BandNone  , RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED},
              /*band_idx 11*/{LTE_BandNone  , RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED},
              /*band_idx 12*/{LTE_BandNone  , RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED},
              /*band_idx 13*/{LTE_BandNone  , RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}
   },
   {/*Set  2*//*band_idx  0*/{LTE_Band1     , RX_IO_HB1     , RXD_IO_HB2     , TX_IO_MB2     },
              /*band_idx  1*/{LTE_Band3     , RX_IO_HB1     , RXD_IO_MB1     , TX_IO_MB2     },
              /*band_idx  2*/{LTE_Band7     , RX_IO_HB3     , RXD_IO_HB2     , TX_IO_HB2     },
              /*band_idx  3*/{LTE_Band28    , RX_IO_LB1     , RXD_IO_LB1     , TX_IO_LB2     },
              /*band_idx  4*/{LTE_Band38    , RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     },
              /*band_idx  5*/{LTE_Band39    , RX_IO_MB2     , RXD_IO_MB2     , TX_IO_MB2     },
              /*band_idx  6*/{LTE_Band40    , RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     },
              /*band_idx  7*/{LTE_Band41    , RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     },
              /*band_idx  8*/{LTE_Band8     , RX_IO_LB2     , RXD_IO_LB1     , TX_IO_LB2     },
              /*band_idx  9*/{LTE_BandNone  , RX_IO_NON_USED, RX_IO_NON_USED , RX_IO_NON_USED},
              /*band_idx 10*/{LTE_BandNone  , RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED},
              /*band_idx 11*/{LTE_BandNone  , RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED},
              /*band_idx 12*/{LTE_BandNone  , RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED},
              /*band_idx 13*/{LTE_BandNone  , RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}
   },   
#endif 
   /*** APPEND new set of custom data HERE ***/
};

//***************************************************
// LTE Splitting Band Custom data definition
//***************************************************
El1CustomDynamicInitLteSplitBandInd el1CustomLteSplitBandInd[EL1_CUSTOM_TOTAL_SET_NUMS][EL1_CUSTOM_MAX_RF_SPLIT_BAND] =
{
 //{/*Set XX*//*BAND_SPLIT_INDICATORXX*/{Band        , SplitNum, SplitBandEndDL     , SplitBandEndUL     , PowerCompensation, CouplerCompensation
 //                                                              (Unit: 100KHz)       (Unit: 100KHz)       (Unit: S(6,8) dB)  (Unit: S(6,8) dB)
   {/*Set  0*//*BAND_SPLIT_INDICATOR1 */{LTE_Band38  , 0       , {    0,    0,    0}, {    0,    0,    0}, 768              , 256},
              /*BAND_SPLIT_INDICATOR2 */{LTE_BandNone, 0       , {    0,    0,    0}, {    0,    0,    0}, 0                , 0},
              /*BAND_SPLIT_INDICATOR3 */{LTE_Band41  , 0       , {    0,    0,    0}, {    0,    0,    0}, 768              , 256},
              /*BAND_SPLIT_INDICATOR4 */{LTE_Band40  , 0       , {    0,    0,    0}, {    0,    0,    0}, 768              , 256},
              /*BAND_SPLIT_INDICATOR5 */{LTE_BandNone, 0       , {    0,    0,    0}, {    0,    0,    0}, 0                , 0},
   },
#if EL1_CUSTOM_DYNAMIC_INIT_ENABLE
   {/*Set  1*//*BAND_SPLIT_INDICATOR1 */{LTE_Band38  , 0       , {    0,    0,    0}, {    0,    0,    0}, 768              , 256},  
              /*BAND_SPLIT_INDICATOR2 */{LTE_BandNone, 0       , {    0,    0,    0}, {    0,    0,    0}, 0                , 0},    
              /*BAND_SPLIT_INDICATOR3 */{LTE_Band41  , 0       , {    0,    0,    0}, {    0,    0,    0}, 768              , 256},  
              /*BAND_SPLIT_INDICATOR4 */{LTE_Band40  , 0       , {    0,    0,    0}, {    0,    0,    0}, 768              , 256},  
              /*BAND_SPLIT_INDICATOR5 */{LTE_BandNone, 0       , {    0,    0,    0}, {    0,    0,    0}, 0                , 0},
   },
   {/*Set  2*//*BAND_SPLIT_INDICATOR1 */{LTE_Band38  , 0       , {    0,    0,    0}, {    0,    0,    0}, 768              , 256},  
              /*BAND_SPLIT_INDICATOR2 */{LTE_Band28  , 2       , { 7805, 8030,    0}, { 7255, 7480,    0}, 0                , 0},    
              /*BAND_SPLIT_INDICATOR3 */{LTE_Band41  , 0       , {    0,    0,    0}, {    0,    0,    0}, 768              , 256},  
              /*BAND_SPLIT_INDICATOR4 */{LTE_Band40  , 0       , {    0,    0,    0}, {    0,    0,    0}, 768              , 256},  
              /*BAND_SPLIT_INDICATOR5 */{LTE_BandNone, 0       , {    0,    0,    0}, {    0,    0,    0}, 0                , 0},
   },
#endif
};

//***************************************************
// LTE BPI/RX LNA port/Tx path data Custom data definition
//***************************************************
El1CustomDynamicInitLteSplitRfData el1CustomLteSplitRfData[EL1_CUSTOM_TOTAL_SET_NUMS][EL1_CUSTOM_MAX_RF_SPLIT_NUM] =
{
 //{/*Set XX*//*BAND_SPLIT_INDICATORXX*/{Band        , {PR1       , PR2       , PR3           , PT1       , PT2       , PT3           }, RX_IO         , RXD_IO         , TX_IO         },
   {/*Set  0*//*BAND_SPLIT_INDICATOR1 */{LTE_Band38  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 2nd part of splitting band
              /*BAND_SPLIT_INDICATOR1 */{LTE_Band38  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band
              /*BAND_SPLIT_INDICATOR1 */{LTE_Band38  , {0x02DCE001, 0x02DCE001, LTE_PDATA_OFF , 0x03240000, 0x03240000, LTE_PDATA_OFF }, RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     }, // PDATA,IO of TX bypass path
              /*BAND_SPLIT_INDICATOR2 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 2nd part of splitting band
              /*BAND_SPLIT_INDICATOR2 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band
              /*BAND_SPLIT_INDICATOR2 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of TX bypass path
              /*BAND_SPLIT_INDICATOR3 */{LTE_Band41  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 2nd part of splitting band
              /*BAND_SPLIT_INDICATOR3 */{LTE_Band41  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band
              /*BAND_SPLIT_INDICATOR3 */{LTE_Band41  , {0x02084001, 0x02084001, LTE_PDATA_OFF , 0x03240000, 0x03240000, LTE_PDATA_OFF }, RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2}, // PDATA,IO of TX bypass path
              /*BAND_SPLIT_INDICATOR4 */{LTE_Band40  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 2nd part of splitting band
              /*BAND_SPLIT_INDICATOR4 */{LTE_Band40  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band
              /*BAND_SPLIT_INDICATOR4 */{LTE_Band40  , {0x02084001, 0x02084001, LTE_PDATA_OFF , 0x03240000, 0x03240000, LTE_PDATA_OFF }, RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     }, // PDATA,IO of TX bypass path
              /*BAND_SPLIT_INDICATOR5 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 2nd part of splitting band
              /*BAND_SPLIT_INDICATOR5 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band
              /*BAND_SPLIT_INDICATOR5 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of TX bypass path
   },
#if EL1_CUSTOM_DYNAMIC_INIT_ENABLE
   {/*Set  1*//*BAND_SPLIT_INDICATOR1 */{LTE_Band38  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 2nd part of splitting band    
              /*BAND_SPLIT_INDICATOR1 */{LTE_Band38  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band    
              /*BAND_SPLIT_INDICATOR1 */{LTE_Band38  , {0x02DCE001, 0x02DCE001, LTE_PDATA_OFF , 0x03240000, 0x03240000, LTE_PDATA_OFF }, RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     }, // PDATA,IO of TX bypass path                
              /*BAND_SPLIT_INDICATOR2 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 2nd part of splitting band    
              /*BAND_SPLIT_INDICATOR2 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band    
              /*BAND_SPLIT_INDICATOR2 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of TX bypass path                
              /*BAND_SPLIT_INDICATOR3 */{LTE_Band41  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 2nd part of splitting band    
              /*BAND_SPLIT_INDICATOR3 */{LTE_Band41  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band    
              /*BAND_SPLIT_INDICATOR3 */{LTE_Band41  , {0x02084001, 0x02084001, LTE_PDATA_OFF , 0x03240000, 0x03240000, LTE_PDATA_OFF }, RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2}, // PDATA,IO of TX bypass path                     
              /*BAND_SPLIT_INDICATOR4 */{LTE_Band40  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 2nd part of splitting band    
              /*BAND_SPLIT_INDICATOR4 */{LTE_Band40  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band    
              /*BAND_SPLIT_INDICATOR4 */{LTE_Band40  , {0x02084001, 0x02084001, LTE_PDATA_OFF , 0x03240000, 0x03240000, LTE_PDATA_OFF }, RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     }, // PDATA,IO of TX bypass path                
              /*BAND_SPLIT_INDICATOR5 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 2nd part of splitting band    
              /*BAND_SPLIT_INDICATOR5 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band    
              /*BAND_SPLIT_INDICATOR5 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of TX bypass path                
   },                                                                                                                                                                                                                                   
   {/*Set  2*//*BAND_SPLIT_INDICATOR1 */{LTE_Band38  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 2nd part of splitting band     
              /*BAND_SPLIT_INDICATOR1 */{LTE_Band38  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band     
              /*BAND_SPLIT_INDICATOR1 */{LTE_Band38  , {0x02DCE001, 0x02DCE001, LTE_PDATA_OFF , 0x03240000, 0x03240000, LTE_PDATA_OFF }, RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     }, // PDATA,IO of TX bypass path                 
              /*BAND_SPLIT_INDICATOR2 */{LTE_Band28  , {0x00134000, 0x00134000, LTE_PDATA_OFF , 0x00100000, 0x00100000, LTE_PDATA_OFF }, RX_IO_LB3     , RXD_IO_LB2     , TX_IO_LB2     }, // PDATA,IO of 2nd part of splitting band     
              /*BAND_SPLIT_INDICATOR2 */{LTE_Band28  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band     
              /*BAND_SPLIT_INDICATOR2 */{LTE_Band28  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of TX bypass path                 
              /*BAND_SPLIT_INDICATOR3 */{LTE_Band41  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 2nd part of splitting band     
              /*BAND_SPLIT_INDICATOR3 */{LTE_Band41  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band     
              /*BAND_SPLIT_INDICATOR3 */{LTE_Band41  , {0x02084001, 0x02084001, LTE_PDATA_OFF , 0x03240000, 0x03240000, LTE_PDATA_OFF }, RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2}, // PDATA,IO of TX bypass path                      
              /*BAND_SPLIT_INDICATOR4 */{LTE_Band40  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 2nd part of splitting band     
              /*BAND_SPLIT_INDICATOR4 */{LTE_Band40  , {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band     
              /*BAND_SPLIT_INDICATOR4 */{LTE_Band40  , {0x02084001, 0x02084001, LTE_PDATA_OFF , 0x03240000, 0x03240000, LTE_PDATA_OFF }, RX_IO_HB2     , RXD_IO_HB3     , TX_IO_HB2     }, // PDATA,IO of TX bypass path                 
              /*BAND_SPLIT_INDICATOR5 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 2nd part of splitting band     
              /*BAND_SPLIT_INDICATOR5 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of 3rd part of splitting band     
              /*BAND_SPLIT_INDICATOR5 */{LTE_BandNone, {0x0       , 0x0       , LTE_PDATA_OFF , 0x0       , 0x0       , LTE_PDATA_OFF }, RX_IO_NON_USED, RXD_IO_NON_USED, TX_IO_NON_USED}, // PDATA,IO of TX bypass path                 
   },                                                                                                                                                                                                                                    
#endif
   /*** APPEND new set of custom data HERE ***/
};

//***************************************************
// LTE Transmit Antenna Selection data Custom data definition
//***************************************************
#if defined(__TAS_SUPPORT__)
El1CustomDynamicInitLteTASParameter el1CustomLteTASParameter[EL1_CUSTOM_TOTAL_SET_NUMS] =
{
   {  /*Set  0*/
      {
         0,               // LTE_TAS_ENA,
         0,               // LTE_TAS_WITH_TEST_SIM_ENA,
         0x0000,          // MSB 16 bits of LTE_TAS_MASK,
         0x0000,          // LSB 16 bits of LTE_TAS_MASK,
         0,               // LTE_TAS_INIT_ANT,
         0,               // LTE_FORCE_TX_ANTENNA_ENABLE,
         0,               // LTE_FORCE_TX_ANTENNA_IDX,
         {
            LTE_BandNone, // BAND_TAS_INDICATOR1,
            LTE_BandNone, // BAND_TAS_INDICATOR2,
            LTE_BandNone, // BAND_TAS_INDICATOR3,
            LTE_BandNone, // BAND_TAS_INDICATOR4,
            LTE_BandNone, // BAND_TAS_INDICATOR5,
            LTE_BandNone, // BAND_TAS_INDICATOR6,
            LTE_BandNone, // BAND_TAS_INDICATOR7,
            LTE_BandNone, // BAND_TAS_INDICATOR8,
            LTE_BandNone, // BAND_TAS_INDICATOR9,
            LTE_BandNone, // BAND_TAS_INDICATOR10,
            LTE_BandNone, // BAND_TAS_INDICATOR11,
            LTE_BandNone, // BAND_TAS_INDICATOR12,
            LTE_BandNone, // BAND_TAS_INDICATOR13,
            LTE_BandNone, // BAND_TAS_INDICATOR14,
         },
      },
      {
         //                       TAS1        TAS2        TAS3        TAS4        TAS5        TAS6        TAS7
         /*BAND_TAS_INDICATOR1 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR2 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR3 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR4 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR5 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR6 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR7 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR8 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR9 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR10*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR11*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR12*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR13*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR14*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
      },
   },
   #if EL1_CUSTOM_DYNAMIC_INIT_ENABLE
   {  /*Set  1*/
      {
         0,               // LTE_TAS_ENA,
         0,               // LTE_TAS_WITH_TEST_SIM_ENA,
         0x0000,          // MSB 16 bits of LTE_TAS_MASK,
         0x0000,          // LSB 16 bits of LTE_TAS_MASK,
         0,               // LTE_TAS_INIT_ANT,
         0,               // LTE_FORCE_TX_ANTENNA_ENABLE,
         0,               // LTE_FORCE_TX_ANTENNA_IDX,
         {
            LTE_BandNone, // BAND_TAS_INDICATOR1,
            LTE_BandNone, // BAND_TAS_INDICATOR2,
            LTE_BandNone, // BAND_TAS_INDICATOR3,
            LTE_BandNone, // BAND_TAS_INDICATOR4,
            LTE_BandNone, // BAND_TAS_INDICATOR5,
            LTE_BandNone, // BAND_TAS_INDICATOR6,
            LTE_BandNone, // BAND_TAS_INDICATOR7,
            LTE_BandNone, // BAND_TAS_INDICATOR8,
            LTE_BandNone, // BAND_TAS_INDICATOR9,
            LTE_BandNone, // BAND_TAS_INDICATOR10,
            LTE_BandNone, // BAND_TAS_INDICATOR11,
            LTE_BandNone, // BAND_TAS_INDICATOR12,
            LTE_BandNone, // BAND_TAS_INDICATOR13,
            LTE_BandNone, // BAND_TAS_INDICATOR14,
         },
      },
      {
         //                       TAS1        TAS2        TAS3        TAS4        TAS5        TAS6        TAS7
         /*BAND_TAS_INDICATOR1 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR2 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR3 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR4 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR5 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR6 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR7 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR8 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR9 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR10*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR11*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR12*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR13*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR14*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
      },
   },
   {  /*Set  2*/
      {
         0,               // LTE_TAS_ENA,
         0,               // LTE_TAS_WITH_TEST_SIM_ENA,
         0x0000,          // MSB 16 bits of LTE_TAS_MASK,
         0x0000,          // LSB 16 bits of LTE_TAS_MASK,
         0,               // LTE_TAS_INIT_ANT,
         0,               // LTE_FORCE_TX_ANTENNA_ENABLE,
         0,               // LTE_FORCE_TX_ANTENNA_IDX,
         {
            LTE_BandNone, // BAND_TAS_INDICATOR1,
            LTE_BandNone, // BAND_TAS_INDICATOR2,
            LTE_BandNone, // BAND_TAS_INDICATOR3,
            LTE_BandNone, // BAND_TAS_INDICATOR4,
            LTE_BandNone, // BAND_TAS_INDICATOR5,
            LTE_BandNone, // BAND_TAS_INDICATOR6,
            LTE_BandNone, // BAND_TAS_INDICATOR7,
            LTE_BandNone, // BAND_TAS_INDICATOR8,
            LTE_BandNone, // BAND_TAS_INDICATOR9,
            LTE_BandNone, // BAND_TAS_INDICATOR10,
            LTE_BandNone, // BAND_TAS_INDICATOR11,
            LTE_BandNone, // BAND_TAS_INDICATOR12,
            LTE_BandNone, // BAND_TAS_INDICATOR13,
            LTE_BandNone, // BAND_TAS_INDICATOR14,
         },
      },
      {
         //                       TAS1        TAS2        TAS3        TAS4        TAS5        TAS6        TAS7
         /*BAND_TAS_INDICATOR1 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR2 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR3 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR4 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR5 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR6 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR7 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR8 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR9 */ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR10*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR11*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR12*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR13*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
         /*BAND_TAS_INDICATOR14*/ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
      },
   },
   #endif
};
#endif

//*************************************************
// LTE Tx calibration data Custom data definition
//*************************************************
// Tx Ramp data
El1CustomDynamicInitLteTxRampData el1CustomLteTxRampData[EL1_CUSTOM_TOTAL_SET_NUMS] =
{
   {/*Set  0*/{&LTE_Band1_RampData      ,   //  Tx Ramp Data, Band_ind=0
               &LTE_Band3_RampData      ,   //  Tx Ramp Data, Band_ind=1
               &LTE_Band7_RampData      ,   //  Tx Ramp Data, Band_ind=2
               &LTE_Band17_RampData     ,   //  Tx Ramp Data, Band_ind=3
               &LTE_Band38_RampData     ,   //  Tx Ramp Data, Band_ind=4
               &LTE_Band39_RampData     ,   //  Tx Ramp Data, Band_ind=5
               &LTE_Band40_RampData     ,   //  Tx Ramp Data, Band_ind=6
               &LTE_Band41_RampData     ,   //  Tx Ramp Data, Band_ind=7
               &LTE_Band8_RampData      ,   //  Tx Ramp Data, Band_ind=8
               &LTE_Band5_RampData      ,   //  Tx Ramp Data, Band_ind=9
               NULL                     ,   //  Tx Ramp Data, Band_ind=10
               NULL                     ,   //  Tx Ramp Data, Band_ind=11
               NULL                     ,   //  Tx Ramp Data, Band_ind=12
               NULL                     }   //  Tx Ramp Data, Band_ind=13
   }, 
#if EL1_CUSTOM_DYNAMIC_INIT_ENABLE
   {/*Set  1*/{&LTE_Band1_RampData      ,   //  Tx Ramp Data, Band_ind=0
               &LTE_Band3_RampData      ,   //  Tx Ramp Data, Band_ind=1
               &LTE_Band7_RampData      ,   //  Tx Ramp Data, Band_ind=2
               &LTE_Band17_RampData     ,   //  Tx Ramp Data, Band_ind=3
               &LTE_Band38_RampData     ,   //  Tx Ramp Data, Band_ind=4
               &LTE_Band39_RampData     ,   //  Tx Ramp Data, Band_ind=5
               &LTE_Band40_RampData     ,   //  Tx Ramp Data, Band_ind=6
               &LTE_Band41_RampData     ,   //  Tx Ramp Data, Band_ind=7
               &LTE_Band8_RampData      ,   //  Tx Ramp Data, Band_ind=8
               &LTE_Band28_RampData     ,   //  Tx Ramp Data, Band_ind=9
               NULL                     ,   //  Tx Ramp Data, Band_ind=10
               NULL                     ,   //  Tx Ramp Data, Band_ind=11
               NULL                     ,   //  Tx Ramp Data, Band_ind=12
               NULL                     }   //  Tx Ramp Data, Band_ind=13
   },
   {/*Set  2*/{&LTE_Band1_RampData      ,   //  Tx Ramp Data, Band_ind=0
               &LTE_Band3_RampData      ,   //  Tx Ramp Data, Band_ind=1
               &LTE_Band7_RampData      ,   //  Tx Ramp Data, Band_ind=2
               &LTE_Band28_RampData     ,   //  Tx Ramp Data, Band_ind=3
               &LTE_Band38_RampData     ,   //  Tx Ramp Data, Band_ind=4
               &LTE_Band39_RampData     ,   //  Tx Ramp Data, Band_ind=5
               &LTE_Band40_RampData     ,   //  Tx Ramp Data, Band_ind=6
               &LTE_Band41_RampData     ,   //  Tx Ramp Data, Band_ind=7
               &LTE_Band8_RampData      ,   //  Tx Ramp Data, Band_ind=8
               NULL                     ,   //  Tx Ramp Data, Band_ind=9
               NULL                     ,   //  Tx Ramp Data, Band_ind=10
               NULL                     ,   //  Tx Ramp Data, Band_ind=11
               NULL                     ,   //  Tx Ramp Data, Band_ind=12
               NULL                     }   //  Tx Ramp Data, Band_ind=13
   },
#endif
   /*** APPEND new set of custom data HERE ***/
};

// Tx PA oct-level data
El1CustomDynamicInitLteTxPaOctLvlData el1CustomLteTxPaOctLvlData[EL1_CUSTOM_TOTAL_SET_NUMS] =
{
   {/*Set  0*/{&LTE_Band1_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=0
               &LTE_Band3_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=1
               &LTE_Band7_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=2
               &LTE_Band17_PaOctLevData     ,   //  Tx Pa Oct Data, Band_ind=3
               &LTE_Band38_PaOctLevData     ,   //  Tx Pa Oct Data, Band_ind=4
               &LTE_Band39_PaOctLevData     ,   //  Tx Pa Oct Data, Band_ind=5
               &LTE_Band40_PaOctLevData     ,   //  Tx Pa Oct Data, Band_ind=6
               &LTE_Band41_PaOctLevData     ,   //  Tx Pa Oct Data, Band_ind=7
               &LTE_Band8_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=8
               &LTE_Band5_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=9
               NULL                         ,   //  Tx Pa Oct Data, Band_ind=10
               NULL                         ,   //  Tx Pa Oct Data, Band_ind=11
               NULL                         ,   //  Tx Pa Oct Data, Band_ind=12
               NULL                         }   //  Tx Pa Oct Data, Band_ind=13
   }, 
#if EL1_CUSTOM_DYNAMIC_INIT_ENABLE
   {/*Set  1*/{&LTE_Band1_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=0
               &LTE_Band3_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=1
               &LTE_Band7_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=2
               &LTE_Band17_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=3
               &LTE_Band38_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=4
               &LTE_Band39_PaOctLevData     ,   //  Tx Pa Oct Data, Band_ind=5
               &LTE_Band40_PaOctLevData     ,   //  Tx Pa Oct Data, Band_ind=6
               &LTE_Band41_PaOctLevData     ,   //  Tx Pa Oct Data, Band_ind=7
               &LTE_Band8_PaOctLevData     ,   //  Tx Pa Oct Data, Band_ind=8
               &LTE_Band28_PaOctLevData     ,   //  Tx Pa Oct Data, Band_ind=9
               NULL                         ,   //  Tx Pa Oct Data, Band_ind=10
               NULL                         ,   //  Tx Pa Oct Data, Band_ind=11
               NULL                         ,   //  Tx Pa Oct Data, Band_ind=12
               NULL                         }   //  Tx Pa Oct Data, Band_ind=13
   },
   {/*Set  2*/{&LTE_Band1_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=0
               &LTE_Band3_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=1
               &LTE_Band7_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=2
               &LTE_Band28_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=3
               &LTE_Band38_PaOctLevData      ,   //  Tx Pa Oct Data, Band_ind=4
               &LTE_Band39_PaOctLevData     ,   //  Tx Pa Oct Data, Band_ind=5
               &LTE_Band40_PaOctLevData     ,   //  Tx Pa Oct Data, Band_ind=6
               &LTE_Band41_PaOctLevData     ,   //  Tx Pa Oct Data, Band_ind=7
               &LTE_Band8_PaOctLevData     ,   //  Tx Pa Oct Data, Band_ind=8
               NULL                         ,   //  Tx Pa Oct Data, Band_ind=9
               NULL                         ,   //  Tx Pa Oct Data, Band_ind=10
               NULL                         ,   //  Tx Pa Oct Data, Band_ind=11
               NULL                         ,   //  Tx Pa Oct Data, Band_ind=12
               NULL                         }   //  Tx Pa Oct Data, Band_ind=13
   },  
#endif
   /*** APPEND new set of custom data HERE ***/
};


//*************************************************
// LTE Rx calibration data Custom data definition
//*************************************************
El1CustomDynamicInitLteRxPathLossData el1CustomLteRxPathLossData[EL1_CUSTOM_TOTAL_SET_NUMS] =
{
   {/*Set  0*/{&LTE_Band1_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=0
               &LTE_Band3_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=1
               &LTE_Band7_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=2
               &LTE_Band17_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=3
               &LTE_Band38_RSSIGainTbl    ,   //  Rx Path Loss Data, Band_ind=4
               &LTE_Band39_RSSIGainTbl    ,   //  Rx Path Loss Data, Band_ind=5
               &LTE_Band40_RSSIGainTbl    ,   //  Rx Path Loss Data, Band_ind=6
               &LTE_Band41_RSSIGainTbl    ,   //  Rx Path Loss Data, Band_ind=7
               &LTE_Band8_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=8
               &LTE_Band5_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=9
               NULL                       ,   //  Rx Path Loss Data, Band_ind=10
               NULL                       ,   //  Rx Path Loss Data, Band_ind=11
               NULL                       ,   //  Rx Path Loss Data, Band_ind=12
               NULL                       }   //  Rx Path Loss Data, Band_ind=13
   },     
#if EL1_CUSTOM_DYNAMIC_INIT_ENABLE
   {/*Set  1*/{&LTE_Band1_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=0
               &LTE_Band3_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=1
               &LTE_Band7_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=2
               &LTE_Band17_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=3
               &LTE_Band38_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=4
               &LTE_Band39_RSSIGainTbl    ,   //  Rx Path Loss Data, Band_ind=5
               &LTE_Band40_RSSIGainTbl    ,   //  Rx Path Loss Data, Band_ind=6
               &LTE_Band41_RSSIGainTbl    ,   //  Rx Path Loss Data, Band_ind=7
               &LTE_Band8_RSSIGainTbl    ,   //  Rx Path Loss Data, Band_ind=8
               &LTE_Band28_RSSIGainTbl    ,   //  Rx Path Loss Data, Band_ind=9
               NULL                       ,   //  Rx Path Loss Data, Band_ind=10
               NULL                       ,   //  Rx Path Loss Data, Band_ind=11
               NULL                       ,   //  Rx Path Loss Data, Band_ind=12
               NULL                       }   //  Rx Path Loss Data, Band_ind=13
   },
   {/*Set  2*/{&LTE_Band1_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=0
               &LTE_Band3_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=1
               &LTE_Band7_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=2
               &LTE_Band28_RSSIGainTbl    ,   //  Rx Path Loss Data, Band_ind=3
               &LTE_Band38_RSSIGainTbl    ,   //  Rx Path Loss Data, Band_ind=4
               &LTE_Band39_RSSIGainTbl    ,   //  Rx Path Loss Data, Band_ind=5
               &LTE_Band40_RSSIGainTbl    ,   //  Rx Path Loss Data, Band_ind=6
               &LTE_Band41_RSSIGainTbl    ,   //  Rx Path Loss Data, Band_ind=7
               &LTE_Band8_RSSIGainTbl     ,   //  Rx Path Loss Data, Band_ind=8
               NULL                       ,   //  Rx Path Loss Data, Band_ind=9
               NULL                       ,   //  Rx Path Loss Data, Band_ind=10
               NULL                       ,   //  Rx Path Loss Data, Band_ind=11
               NULL                       ,   //  Rx Path Loss Data, Band_ind=12
               NULL                       }   //  Rx Path Loss Data, Band_ind=13
   },
#endif    
   /*** APPEND new set of custom data HERE ***/
};


//*********************************************
// LTE Temperature DAC Custom data definition
//*********************************************
El1CustomDynamicInitLteTempDac el1CustomLteTempDacData[EL1_CUSTOM_TOTAL_SET_NUMS] =
{
   {&TempDacTable}     ,   //  Temperature DAC Data, Set 0
#if EL1_CUSTOM_DYNAMIC_INIT_ENABLE
   {&TempDacTable}     ,   //  Temperature DAC Data, Set 1
   {&TempDacTable}     ,   //  Temperature DAC Data, Set 2
#endif
   /*** APPEND new set of custom data HERE ***/
   //{&TempDacTable_SetX},   //  Temperature DAC Data, Set X
};


//***************************************
// AuxADC voltage to level look-up table
//***************************************
kal_uint32 el1_custom_adc_volt_to_lvl[/*number of supported ADC levels*/][2] =
{
   /* Upper Bound */                  /* Lower Bound */
   {EL1_CUSTOM_ADC_LVL0,               0},

   /* Don't remove the above line: insert your new added level setting definition
    * bellow or delete the unused level bellow */

   {EL1_CUSTOM_ADC_LVL1,               EL1_CUSTOM_ADC_LVL0},
   {EL1_CUSTOM_ADC_LVL2,               EL1_CUSTOM_ADC_LVL1},

   /* Insert your new added level setting definition above or
    * delete the unused level above, and then change lower bound
    * EL1_CUSTOM_ADC_LVL6 below to the last upper bound in the above lines */

   {EL1_CUSTOM_ADC_MAX_INPUT_VOLTAGE,  EL1_CUSTOM_ADC_LVL2}
};


//***************************************
// Barcode digits array 
//***************************************
kal_char el1_custom_barcode_digits[EL1_CUSTOM_BARCODE_NUMS_IN_CALC] =
{
   '8', //Set 0, ex; for MURATA_SP7T
#if 0
/* under construction !*/
/* under construction !*/
#endif
};

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
#endif

/*******************************************************************************
** Global Functions
*******************************************************************************/
void EL1_CUSTOM_ReplaceAuxAdcCalibrate(kal_uint32 adcDigitalValue, kal_int32 *volt)
{
   /* Empty function */
}

/*******************************************************************************
** Global Functions
** for Feature phone/data-card GPIO Pin number access
** Not Recommend to modify
*******************************************************************************/
void EL1_CUSTOM_GPIO_NON_SMART_PHONE_PIN_ACCESS(kal_int16 *gpio_pin)
{
   /*PS: If link error happens, PLEASE check if codegen(DWS) generates the following variables */
#if (!EL1_CUSTOM_SMART_PHONE_ENABLE)
#if   (EL1_CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE == 0x1)
   // extern const char is from gpio_var.c (codegen)
	 extern const char GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN;
   gpio_pin[0] = GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN;
   gpio_pin[1] = -1;
   gpio_pin[2] = -1;
#elif (EL1_CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE == 0x2)
   extern const char GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN;
   extern const char GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN;
   gpio_pin[0] = GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN;
   gpio_pin[1] = GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN;
   gpio_pin[2] = -1;	
#elif (EL1_CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE == 0x3)
   extern const char GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN;
   extern const char GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN;
   extern const char GPIO_FDD_BAND_SUPPORT_DETECT_3RD_PIN;
   gpio_pin[0] = GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN;
   gpio_pin[1] = GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN;
   gpio_pin[2] = GPIO_FDD_BAND_SUPPORT_DETECT_3RD_PIN;	
#endif
#endif // (!EL1_CUSTOM_SMART_PHONE_ENABLE)		
}


/*******************************************************************************
** Global Functions
** for Feature phone/data-card ADC Pin number access
** Not Recommend to modify
*******************************************************************************/
void EL1_CUSTOM_ADC_PIN_ACCESS(kal_uint16 *adc_channel_num)
{
   /*PS: If link error happens, PLEASE check if codegen(DWS) generates the following variables */
#if (!EL1_CUSTOM_SMART_PHONE_ENABLE)
#if (EL1_CUSTOM_ADC_ENABLE)
   // extern const char is from adc_var.c (codegen)
   extern const char ADC_FDD_RF_PARAMS_DYNAMIC_CUSTOM_CH;
   adc_channel_num[0] = ADC_FDD_RF_PARAMS_DYNAMIC_CUSTOM_CH;
#else
   adc_channel_num[0] = 0xFFFF;
#endif
#endif
}

/*******************************************************************************
** DRDI for MIPI Custom Setting
*******************************************************************************/
//Collect all custom MIPI data/event table for DRDI usage
El1CustomDynamicInitLteMipiEventData el1CustomLteMipiEventDataTable[EL1_CUSTOM_TOTAL_SET_NUMS] =
{
   {  /*Set 0*/  
      LTE_DRDI_MIPI_ENABLE              ,     // LTE_DRDI_MIPI_DISABLE or LTE_DRDI_MIPI_ENABLE
      LTE_MIPI_RX_EVENT_TABLE_Set0      ,     // LTE_MIPI_RX_EVENT_TABLE,     
      LTE_MIPI_RX_DATA_TABLE_Set0       ,     // LTE_MIPI_RX_DATA_TABLE,      
      LTE_MIPI_TX_EVENT_TABLE_Set0      ,     // LTE_MIPI_TX_EVENT_TABLE,     
      LTE_MIPI_TX_DATA_TABLE_Set0       ,     // LTE_MIPI_TX_DATA_TABLE,      
      LTE_MIPI_TPC_EVENT_TABLE_Set0     ,     // LTE_MIPI_TPC_EVENT_TABLE,    
      LTE_MIPI_TPC_DATA_TABLE_Set0      ,     // LTE_MIPI_TPC_DATA_TABLE,     
      LTE_MIPI_PA_TPC_SECTION_DATA_Set0 ,     // LTE_MIPI_PA_TPC_SECTION_DATA,
      LTE_MIPI_INITIAL_CW               ,     // LTE_MIPI_INITIAL_CW, Set0 reuse original table         
      LTE_MIPI_SLEEP_CW                 ,     // LTE_MIPI_SLEEP_CW, Set0 reuse original table          
      LTE_MIPI_ASM_ISOLATION_DATA       ,     // LTE_MIPI_ASM_ISOLATION_DATA, Set0 reuse original table 
      LTE_MIPI_RX_EVENT_SIZE_TABLE_Set0 ,     // LTE_MIPI_RX_EVENT_SIZE_TABLE,
      LTE_MIPI_RX_DATA_SIZE_TABLE_Set0  ,     // LTE_MIPI_RX_DATA_SIZE_TABLE,
      LTE_MIPI_TX_EVENT_SIZE_TABLE_Set0 ,     // LTE_MIPI_TX_EVENT_SIZE_TABLE,
      LTE_MIPI_TX_DATA_SIZE_TABLE_Set0  ,     // LTE_MIPI_TX_DATA_SIZE_TABLE,
      LTE_MIPI_TPC_EVENT_SIZE_TABLE_Set0,     // LTE_MIPI_TPC_EVENT_SIZE_TABLE,
      LTE_MIPI_PA_TPC_SECTION_DATA_SIZE_Set0 , // LTE_MIPI_PA_TPC_SECTION_DATA_SIZE,
   },
#if EL1_CUSTOM_DYNAMIC_INIT_ENABLE
   {  /*Set 1*/
      LTE_DRDI_MIPI_ENABLE              ,     // LTE_DRDI_MIPI_DISABLE or LTE_DRDI_MIPI_ENABLE
      LTE_MIPI_RX_EVENT_TABLE_Set1      ,     // LTE_MIPI_RX_EVENT_TABLE,     
      LTE_MIPI_RX_DATA_TABLE_Set1       ,     // LTE_MIPI_RX_DATA_TABLE,      
      LTE_MIPI_TX_EVENT_TABLE_Set1      ,     // LTE_MIPI_TX_EVENT_TABLE,     
      LTE_MIPI_TX_DATA_TABLE_Set1       ,     // LTE_MIPI_TX_DATA_TABLE,      
      LTE_MIPI_TPC_EVENT_TABLE_Set1     ,     // LTE_MIPI_TPC_EVENT_TABLE,    
      LTE_MIPI_TPC_DATA_TABLE_Set1      ,     // LTE_MIPI_TPC_DATA_TABLE,     
      LTE_MIPI_PA_TPC_SECTION_DATA_Set1 ,     // LTE_MIPI_PA_TPC_SECTION_DATA,
      LTE_MIPI_INITIAL_CW_Set1          ,     // LTE_MIPI_INITIAL_CW,         
      LTE_MIPI_SLEEP_CW_Set1            ,     // LTE_MIPI_SLEEP_CW,           
      LTE_MIPI_ASM_ISOLATION_DATA_Set1  ,     // LTE_MIPI_ASM_ISOLATION_DATA, 
      LTE_MIPI_RX_EVENT_SIZE_TABLE_Set1 ,     // LTE_MIPI_RX_EVENT_SIZE_TABLE,
      LTE_MIPI_RX_DATA_SIZE_TABLE_Set1  ,     // LTE_MIPI_RX_DATA_SIZE_TABLE,
      LTE_MIPI_TX_EVENT_SIZE_TABLE_Set1 ,     // LTE_MIPI_TX_EVENT_SIZE_TABLE,
      LTE_MIPI_TX_DATA_SIZE_TABLE_Set1  ,     // LTE_MIPI_TX_DATA_SIZE_TABLE,
      LTE_MIPI_TPC_EVENT_SIZE_TABLE_Set1,     // LTE_MIPI_TPC_EVENT_SIZE_TABLE,
      LTE_MIPI_PA_TPC_SECTION_DATA_SIZE_Set1, // LTE_MIPI_PA_TPC_SECTION_DATA_SIZE,
   },
   {  /*Set 2*/
      LTE_DRDI_MIPI_ENABLE              ,     // LTE_DRDI_MIPI_DISABLE or LTE_DRDI_MIPI_ENABLE
      LTE_MIPI_RX_EVENT_TABLE_Set2      ,     // LTE_MIPI_RX_EVENT_TABLE,     
      LTE_MIPI_RX_DATA_TABLE_Set2       ,     // LTE_MIPI_RX_DATA_TABLE,      
      LTE_MIPI_TX_EVENT_TABLE_Set2      ,     // LTE_MIPI_TX_EVENT_TABLE,     
      LTE_MIPI_TX_DATA_TABLE_Set2       ,     // LTE_MIPI_TX_DATA_TABLE,      
      LTE_MIPI_TPC_EVENT_TABLE_Set2     ,     // LTE_MIPI_TPC_EVENT_TABLE,    
      LTE_MIPI_TPC_DATA_TABLE_Set2      ,     // LTE_MIPI_TPC_DATA_TABLE,     
      LTE_MIPI_PA_TPC_SECTION_DATA_Set2 ,     // LTE_MIPI_PA_TPC_SECTION_DATA,
      LTE_MIPI_INITIAL_CW_Set2          ,     // LTE_MIPI_INITIAL_CW,         
      LTE_MIPI_SLEEP_CW_Set2            ,     // LTE_MIPI_SLEEP_CW,           
      LTE_MIPI_ASM_ISOLATION_DATA_Set2  ,     // LTE_MIPI_ASM_ISOLATION_DATA, 
      LTE_MIPI_RX_EVENT_SIZE_TABLE_Set2 ,     // LTE_MIPI_RX_EVENT_SIZE_TABLE,
      LTE_MIPI_RX_DATA_SIZE_TABLE_Set2  ,     // LTE_MIPI_RX_DATA_SIZE_TABLE,
      LTE_MIPI_TX_EVENT_SIZE_TABLE_Set2 ,     // LTE_MIPI_TX_EVENT_SIZE_TABLE,
      LTE_MIPI_TX_DATA_SIZE_TABLE_Set2  ,     // LTE_MIPI_TX_DATA_SIZE_TABLE,
      LTE_MIPI_TPC_EVENT_SIZE_TABLE_Set2,     // LTE_MIPI_TPC_EVENT_SIZE_TABLE,
      LTE_MIPI_PA_TPC_SECTION_DATA_SIZE_Set2, // LTE_MIPI_PA_TPC_SECTION_DATA_SIZE,
   },
#endif
   /*** APPEND new set of custom data HERE ***/   
};

//*********************************************
// LTE MIPI Custom Setting
//*********************************************
/* Pointer array for customer to input 4G MIPI data */
El1CustomDynamicInitLteMipiEventData   *el1_rf_mipi_evtdata_array_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];


/*******************************************************************************
** DRDI for MIPI BYPASS Custom Setting
*******************************************************************************/
//Collect all custom MIPI BYPASS data/event table for DRDI usage
El1CustomDynamicInitLteMipiBypassEventData el1CustomLteMipiBypassEventDataTable[EL1_CUSTOM_TOTAL_SET_NUMS] =
{
   {  /*Set 0*/  
      LTE_DRDI_MIPI_BYPASS_ENABLE                   ,  // LTE_DRDI_MIPI_BYPASS_DISABLE or LTE_DRDI_MIPI_BYPASS_ENABLE    
      LTE_MIPI_BYPASS_TX_EVENT_TABLE_Set0           ,  // LTE_MIPI_BYPASS_TX_EVENT_TABLE,     
      LTE_MIPI_BYPASS_TX_DATA_TABLE_Set0            ,  // LTE_MIPI_BYPASS_TX_DATA_TABLE,      
      LTE_MIPI_BYPASS_TPC_EVENT_TABLE_Set0          ,  // LTE_MIPI_BYPASS_TPC_EVENT_TABLE,    
      LTE_MIPI_BYPASS_TPC_DATA_TABLE_Set0           ,  // LTE_MIPI_BYPASS_TPC_DATA_TABLE,     
      LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_Set0      ,  // LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA,
      LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE_Set0      ,  // LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE,
      LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE_Set0       ,  // LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE,
      LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE_Set0     ,  // LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE,
      LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE_Set0 ,  // LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE,
   },
#if EL1_CUSTOM_DYNAMIC_INIT_ENABLE
   {  /*Set 1*/
      LTE_DRDI_MIPI_BYPASS_ENABLE                  ,  // LTE_DRDI_MIPI_BYPASS_DISABLE or LTE_DRDI_MIPI_BYPASS_ENABLE     
      LTE_MIPI_BYPASS_TX_EVENT_TABLE_Set1           ,  // LTE_MIPI_BYPASS_TX_EVENT_TABLE,     
      LTE_MIPI_BYPASS_TX_DATA_TABLE_Set1            ,  // LTE_MIPI_BYPASS_TX_DATA_TABLE,      
      LTE_MIPI_BYPASS_TPC_EVENT_TABLE_Set1          ,  // LTE_MIPI_BYPASS_TPC_EVENT_TABLE,    
      LTE_MIPI_BYPASS_TPC_DATA_TABLE_Set1           ,  // LTE_MIPI_BYPASS_TPC_DATA_TABLE,     
      LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_Set1      ,  // LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA,
      LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE_Set1      ,  // LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE,
      LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE_Set1       ,  // LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE,
      LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE_Set1     ,  // LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE,
      LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE_Set1 ,  // LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE,
   },
   {  /*Set 2*/
      LTE_DRDI_MIPI_BYPASS_ENABLE                   ,  // LTE_DRDI_MIPI_BYPASS_DISABLE or LTE_DRDI_MIPI_BYPASS_ENABLE     
      LTE_MIPI_BYPASS_TX_EVENT_TABLE_Set2           ,  // LTE_MIPI_BYPASS_TX_EVENT_TABLE,     
      LTE_MIPI_BYPASS_TX_DATA_TABLE_Set2            ,  // LTE_MIPI_BYPASS_TX_DATA_TABLE,      
      LTE_MIPI_BYPASS_TPC_EVENT_TABLE_Set2          ,  // LTE_MIPI_BYPASS_TPC_EVENT_TABLE,    
      LTE_MIPI_BYPASS_TPC_DATA_TABLE_Set2           ,  // LTE_MIPI_BYPASS_TPC_DATA_TABLE,     
      LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_Set2      ,  // LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA,
      LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE_Set2      ,  // LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE,
      LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE_Set2       ,  // LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE,
      LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE_Set2     ,  // LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE,
      LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE_Set2 ,  // LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE,
   },
#endif
   /*** APPEND new set of custom data HERE ***/   
};

//Collect all custom MIPI BYPASS Band setting and corresponding Power/Coupler compensation
El1CustomDynamicInitLteMipiBypassInfo el1CustomLteMipiBypassInfo[EL1_CUSTOM_TOTAL_SET_NUMS][EL1_CUSTOM_MIPI_BYPASS_MAX_SUPPORT_BAND_NUM] =
{
 //{/*Set XX*//*band_idx XX*/{Band        ,  PowerCompensation, CouplerCompensation
 //                                          (Unit: S(6,8) dB)  (Unit: S(6,8) dB)
   {/*Set  0*//*band_idx  0*/{LTE_Band38  ,               768,               256},
              /*band_idx  1*/{LTE_Band40  ,               768,               256},
              /*band_idx  2*/{LTE_Band41  ,               768,               256},
              /*band_idx  3*/{LTE_BandNone,                 0,                 0},
              /*band_idx  4*/{LTE_BandNone,                 0,                 0},
   },
#if EL1_CUSTOM_DYNAMIC_INIT_ENABLE
   {/*Set  1*//*band_idx  0*/{LTE_Band38  ,               768,               256},
              /*band_idx  1*/{LTE_Band40  ,               768,               256},
              /*band_idx  2*/{LTE_Band41  ,               768,               256},
              /*band_idx  3*/{LTE_BandNone,                 0,                 0},
              /*band_idx  4*/{LTE_BandNone,                 0,                 0},
   },
   {/*Set  2*//*band_idx  0*/{LTE_Band38  ,               768,               256},
              /*band_idx  1*/{LTE_Band40  ,               768,               256},
              /*band_idx  2*/{LTE_Band41  ,               768,               256},
              /*band_idx  3*/{LTE_BandNone,                 0,                 0},
              /*band_idx  4*/{LTE_BandNone,                 0,                 0},
   },
#endif
   /*** APPEND new set of custom data HERE ***/ 
};


//*********************************************
// LTE MIPI BYPASS Custom Setting
//*********************************************
/* Pointer array for customer to input 4G MIPI BYPASS data */
El1CustomDynamicInitLteMipiBypassEventData   *el1_rf_mipi_bypass_evtdata_array_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];
El1CustomDynamicInitLteMipiBypassInfo        *el1_rf_mipi_bypass_info_ptr[EL1_CUSTOM_TOTAL_SET_NUMS];


#endif /* #ifdef __MTK_TARGET__ */

/* END OF FILE */
