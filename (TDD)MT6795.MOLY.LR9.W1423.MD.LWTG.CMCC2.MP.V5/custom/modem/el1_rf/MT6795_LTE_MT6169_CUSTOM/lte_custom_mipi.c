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
* el1_rf_custom.c
*
* Project:
* --------
* MT6290
*
* Description:
* ------------
*
*
* Author:
* -------
 * -------
*
*============================================================================*/

/*===============================================================================*/

#include "kal_general_types.h"
#include "lte_custom_rf.h"
#include "lte_custom_mipi.h"


/*===============================================================================*/
#if IS_MIPI_FRONT_END_ENABLE

LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_INITIAL_CW[] =
{
   // elm type   , port_sel      , data_seq ,    USID          , addr , data  , wait_time(us)
   {LTE_MIPI_ASM , LTE_MIPI_PORT0, LTE_REG_W, MIPI_USID_INIT0  , {0x1C, 0x38} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = normal mode
   {LTE_MIPI_ASM , LTE_MIPI_PORT1, LTE_REG_W, MIPI_USID_INIT0  , {0x1C, 0x38} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = normal mode
   {LTE_MIPI_END_PATTERN,0,0,0,{0,0},0},
};

LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_SLEEP_CW[] =
{
   // elm type   , port_sel      , data_seq ,    USID          , addr , data  , wait_time(us)
   {LTE_MIPI_ASM , LTE_MIPI_PORT0, LTE_REG_W, MIPI_USID_INIT0  , {0x1C, 0xB8} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = low power mode
   {LTE_MIPI_ASM , LTE_MIPI_PORT1, LTE_REG_W, MIPI_USID_INIT0  , {0x1C, 0xB8} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = low power mode
   {LTE_MIPI_END_PATTERN,0,0,0,{0,0},0},
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_RX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band1_MIPI_RX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band3_MIPI_RX_EVENT[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band5_MIPI_RX_EVENT[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band7_MIPI_RX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band8_MIPI_RX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band17_MIPI_RX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_RX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                     ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band39_MIPI_RX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_RX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_RX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};
kal_uint32 LTE_MIPI_RX_EVENT_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_MIPI_RX_EVENT(BAND_INDICATOR1 )),
      sizeof(LTE_MIPI_RX_EVENT(BAND_INDICATOR2 )),
      sizeof(LTE_MIPI_RX_EVENT(BAND_INDICATOR3 )),
      sizeof(LTE_MIPI_RX_EVENT(BAND_INDICATOR4 )),
      sizeof(LTE_MIPI_RX_EVENT(BAND_INDICATOR5 )),
      sizeof(LTE_MIPI_RX_EVENT(BAND_INDICATOR6 )),
      sizeof(LTE_MIPI_RX_EVENT(BAND_INDICATOR7 )),
      sizeof(LTE_MIPI_RX_EVENT(BAND_INDICATOR8 )),
      sizeof(LTE_MIPI_RX_EVENT(BAND_INDICATOR9 )),
      sizeof(LTE_MIPI_RX_EVENT(BAND_INDICATOR10)),
      sizeof(LTE_MIPI_RX_EVENT(BAND_INDICATOR11)),
      sizeof(LTE_MIPI_RX_EVENT(BAND_INDICATOR12)),
      sizeof(LTE_MIPI_RX_EVENT(BAND_INDICATOR13)),
      sizeof(LTE_MIPI_RX_EVENT(BAND_INDICATOR14)),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_RX_EVENT_TABLE[] =
{
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_MIPI_RX_EVENT(BAND_INDICATOR1 ),
      LTE_MIPI_RX_EVENT(BAND_INDICATOR2 ),
      LTE_MIPI_RX_EVENT(BAND_INDICATOR3 ),
      LTE_MIPI_RX_EVENT(BAND_INDICATOR4 ),
      LTE_MIPI_RX_EVENT(BAND_INDICATOR5 ),
      LTE_MIPI_RX_EVENT(BAND_INDICATOR6 ),
      LTE_MIPI_RX_EVENT(BAND_INDICATOR7 ),
      LTE_MIPI_RX_EVENT(BAND_INDICATOR8 ),
      LTE_MIPI_RX_EVENT(BAND_INDICATOR9 ),
      LTE_MIPI_RX_EVENT(BAND_INDICATOR10),
      LTE_MIPI_RX_EVENT(BAND_INDICATOR11),
      LTE_MIPI_RX_EVENT(BAND_INDICATOR12),
      LTE_MIPI_RX_EVENT(BAND_INDICATOR13),
      LTE_MIPI_RX_EVENT(BAND_INDICATOR14),
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_RX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    ,0    }, { 0     /*100 kHz*/    ,0    ,0    }, { 0     /*100 kHz*/    ,0    ,0    }, { 0     /*100 kHz*/    ,0    ,0    }, { 0     /*100 kHz*/    ,0    ,0    },} }, // ASM PM_Trig: Active
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band1_MIPI_RX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 21100 /*100 kHz*/    ,0x1C , 0x38}, { 21250 /*100 kHz*/    ,0x1C , 0x38}, { 21400 /*100 kHz*/    ,0x1C , 0x38}, { 21550 /*100 kHz*/    ,0x1C , 0x38}, { 21700 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 21100 /*100 kHz*/    ,0x00 , 0x0C}, { 21250 /*100 kHz*/    ,0x00 , 0x0C}, { 21400 /*100 kHz*/    ,0x00 , 0x0C}, { 21550 /*100 kHz*/    ,0x00 , 0x0C}, { 21700 /*100 kHz*/    ,0x00 , 0x0C},} }, 
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 21100 /*100 kHz*/    ,0x00 , 0x00}, { 21250 /*100 kHz*/    ,0x00 , 0x00}, { 21400 /*100 kHz*/    ,0x00 , 0x00}, { 21550 /*100 kHz*/    ,0x00 , 0x00}, { 21700 /*100 kHz*/    ,0x00 , 0x00},} }, 
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 21100 /*100 kHz*/    ,0x1C , 0xB8}, { 21250 /*100 kHz*/    ,0x1C , 0xB8}, { 21400 /*100 kHz*/    ,0x1C , 0xB8}, { 21550 /*100 kHz*/    ,0x1C , 0xB8}, { 21700 /*100 kHz*/    ,0x1C , 0xB8},} }, 
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, 
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band3_MIPI_RX_DATA[] = 
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18050 /*100 kHz*/    ,0x1C , 0x38}, { 18238 /*100 kHz*/    ,0x1C , 0x38}, { 18425 /*100 kHz*/    ,0x1C , 0x38}, { 18612 /*100 kHz*/    ,0x1C , 0x38}, { 18800 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18050 /*100 kHz*/    ,0x00 , 0x02}, { 18238 /*100 kHz*/    ,0x00 , 0x02}, { 18425 /*100 kHz*/    ,0x00 , 0x02}, { 18612 /*100 kHz*/    ,0x00 , 0x02}, { 18800 /*100 kHz*/    ,0x00 , 0x02},} }, 
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18050 /*100 kHz*/    ,0x00 , 0x00}, { 18238 /*100 kHz*/    ,0x00 , 0x00}, { 18425 /*100 kHz*/    ,0x00 , 0x00}, { 18612 /*100 kHz*/    ,0x00 , 0x00}, { 18800 /*100 kHz*/    ,0x00 , 0x00},} }, 
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18050 /*100 kHz*/    ,0x1C , 0xB8}, { 18238 /*100 kHz*/    ,0x1C , 0xB8}, { 18425 /*100 kHz*/    ,0x1C , 0xB8}, { 18612 /*100 kHz*/    ,0x1C , 0xB8}, { 18800 /*100 kHz*/    ,0x1C , 0xB8},} }, 
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, 
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band5_MIPI_RX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 8690 /*100 kHz*/    ,0x1C , 0x38}, { 8753 /*100 kHz*/    ,0x1C , 0x38}, { 8816 /*100 kHz*/    ,0x1C , 0x38}, { 8879 /*100 kHz*/    ,0x1C , 0x38}, { 8940 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 8690 /*100 kHz*/    ,0x00 , 0x0B}, { 8753 /*100 kHz*/    ,0x00 , 0x0B}, { 8816 /*100 kHz*/    ,0x00 , 0x0B}, { 8879 /*100 kHz*/    ,0x00 , 0x0B}, { 8940 /*100 kHz*/    ,0x00 , 0x0B},} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 8690 /*100 kHz*/    ,0x00 , 0x00}, { 8753 /*100 kHz*/    ,0x00 , 0x00}, { 8816 /*100 kHz*/    ,0x00 , 0x00}, { 8879 /*100 kHz*/    ,0x00 , 0x00}, { 8940 /*100 kHz*/    ,0x00 , 0x00},} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 8690 /*100 kHz*/    ,0x1C , 0xB8}, { 8753 /*100 kHz*/    ,0x1C , 0xB8}, { 8816 /*100 kHz*/    ,0x1C , 0xB8}, { 8879 /*100 kHz*/    ,0x1C , 0xB8}, { 8940 /*100 kHz*/    ,0x1C , 0xB8},} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band8_MIPI_RX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 9250 /*100 kHz*/    ,0x1C , 0x38}, { 9338 /*100 kHz*/    ,0x1C , 0x38}, { 9426 /*100 kHz*/    ,0x1C , 0x38}, { 9514 /*100 kHz*/    ,0x1C , 0x38}, { 9600 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 9250 /*100 kHz*/    ,0x00 , 0x03}, { 9338 /*100 kHz*/    ,0x00 , 0x03}, { 9426 /*100 kHz*/    ,0x00 , 0x03}, { 9514 /*100 kHz*/    ,0x00 , 0x03}, { 9600 /*100 kHz*/    ,0x00 , 0x03},} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 9250 /*100 kHz*/    ,0x00 , 0x00}, { 9338 /*100 kHz*/    ,0x00 , 0x00}, { 9426 /*100 kHz*/    ,0x00 , 0x00}, { 9514 /*100 kHz*/    ,0x00 , 0x00}, { 9600 /*100 kHz*/    ,0x00 , 0x00},} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 9250 /*100 kHz*/    ,0x1C , 0xB8}, { 9338 /*100 kHz*/    ,0x1C , 0xB8}, { 9426 /*100 kHz*/    ,0x1C , 0xB8}, { 9514 /*100 kHz*/    ,0x1C , 0xB8}, { 9600 /*100 kHz*/    ,0x1C , 0xB8},} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band7_MIPI_RX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band17_MIPI_RX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7340  /*100 kHz*/    ,0x1C , 0x38}, { 7370  /*100 kHz*/    ,0x1C , 0x38}, { 7400  /*100 kHz*/    ,0x1C , 0x38}, { 7430  /*100 kHz*/    ,0x1C , 0x38}, { 7460  /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7340  /*100 kHz*/    ,0x00 , 0x01}, { 7370  /*100 kHz*/    ,0x00 , 0x01}, { 7400  /*100 kHz*/    ,0x00 , 0x01}, { 7430  /*100 kHz*/    ,0x00 , 0x01}, { 7460  /*100 kHz*/    ,0x00 , 0x01},} }, 
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7340  /*100 kHz*/    ,0x00 , 0x00}, { 7370  /*100 kHz*/    ,0x00 , 0x00}, { 7400  /*100 kHz*/    ,0x00 , 0x00}, { 7430  /*100 kHz*/    ,0x00 , 0x00}, { 7460  /*100 kHz*/    ,0x00 , 0x00},} }, 
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7340  /*100 kHz*/    ,0x1C , 0xB8}, { 7370  /*100 kHz*/    ,0x1C , 0xB8}, { 7400  /*100 kHz*/    ,0x1C , 0xB8}, { 7430  /*100 kHz*/    ,0x1C , 0xB8}, { 7460  /*100 kHz*/    ,0x1C , 0xB8},} }, 
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, 
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band38_MIPI_RX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band39_MIPI_RX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x00 , 0x07}, { 18900 /*100 kHz*/    ,0x00 , 0x07}, { 19000 /*100 kHz*/    ,0x00 , 0x07}, { 19100 /*100 kHz*/    ,0x00 , 0x07}, { 19200 /*100 kHz*/    ,0x00 , 0x07},} }, 
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x00 , 0x00}, { 18900 /*100 kHz*/    ,0x00 , 0x00}, { 19000 /*100 kHz*/    ,0x00 , 0x00}, { 19100 /*100 kHz*/    ,0x00 , 0x00}, { 19200 /*100 kHz*/    ,0x00 , 0x00},} }, 
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x1C , 0xB8}, { 18900 /*100 kHz*/    ,0x1C , 0xB8}, { 19000 /*100 kHz*/    ,0x1C , 0xB8}, { 19100 /*100 kHz*/    ,0x1C , 0xB8}, { 19200 /*100 kHz*/    ,0x1C , 0xB8},} }, 
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, 
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band40_MIPI_RX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band41_MIPI_RX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};
kal_uint32 LTE_MIPI_RX_DATA_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_MIPI_RX_DATA(BAND_INDICATOR1 )),
      sizeof(LTE_MIPI_RX_DATA(BAND_INDICATOR2 )),
      sizeof(LTE_MIPI_RX_DATA(BAND_INDICATOR3 )),
      sizeof(LTE_MIPI_RX_DATA(BAND_INDICATOR4 )),
      sizeof(LTE_MIPI_RX_DATA(BAND_INDICATOR5 )),
      sizeof(LTE_MIPI_RX_DATA(BAND_INDICATOR6 )),
      sizeof(LTE_MIPI_RX_DATA(BAND_INDICATOR7 )),
      sizeof(LTE_MIPI_RX_DATA(BAND_INDICATOR8 )),
      sizeof(LTE_MIPI_RX_DATA(BAND_INDICATOR9 )),
      sizeof(LTE_MIPI_RX_DATA(BAND_INDICATOR10)),
      sizeof(LTE_MIPI_RX_DATA(BAND_INDICATOR11)),
      sizeof(LTE_MIPI_RX_DATA(BAND_INDICATOR12)),
      sizeof(LTE_MIPI_RX_DATA(BAND_INDICATOR13)),
      sizeof(LTE_MIPI_RX_DATA(BAND_INDICATOR14)),
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_RX_DATA_TABLE[] =
{
      LTE_BandNone_MIPI_RX_DATA,
      LTE_MIPI_RX_DATA(BAND_INDICATOR1 ),
      LTE_MIPI_RX_DATA(BAND_INDICATOR2 ),
      LTE_MIPI_RX_DATA(BAND_INDICATOR3 ),
      LTE_MIPI_RX_DATA(BAND_INDICATOR4 ),
      LTE_MIPI_RX_DATA(BAND_INDICATOR5 ),
      LTE_MIPI_RX_DATA(BAND_INDICATOR6 ),
      LTE_MIPI_RX_DATA(BAND_INDICATOR7 ),
      LTE_MIPI_RX_DATA(BAND_INDICATOR8 ),
      LTE_MIPI_RX_DATA(BAND_INDICATOR9 ),
      LTE_MIPI_RX_DATA(BAND_INDICATOR10),
      LTE_MIPI_RX_DATA(BAND_INDICATOR11),
      LTE_MIPI_RX_DATA(BAND_INDICATOR12),
      LTE_MIPI_RX_DATA(BAND_INDICATOR13),
      LTE_MIPI_RX_DATA(BAND_INDICATOR14),
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_TX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band1_MIPI_TX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band3_MIPI_TX_EVENT[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band5_MIPI_TX_EVENT[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band7_MIPI_TX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON1 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band8_MIPI_TX_EVENT[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band17_MIPI_TX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_TX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band39_MIPI_TX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_TX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_TX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};
kal_uint32  LTE_MIPI_TX_EVENT_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR1 )),
      sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR2 )),
      sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR3 )),
      sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR4 )),
      sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR5 )),
      sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR6 )),
      sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR7 )),
      sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR8 )),
      sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR9 )),
      sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR10)),
      sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR11)),
      sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR12)),
      sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR13)),
      sizeof(LTE_MIPI_TX_EVENT(BAND_INDICATOR14)),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_TX_EVENT_TABLE[] =
{
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_MIPI_TX_EVENT(BAND_INDICATOR1 ),
      LTE_MIPI_TX_EVENT(BAND_INDICATOR2 ),
      LTE_MIPI_TX_EVENT(BAND_INDICATOR3 ),
      LTE_MIPI_TX_EVENT(BAND_INDICATOR4 ),
      LTE_MIPI_TX_EVENT(BAND_INDICATOR5 ),
      LTE_MIPI_TX_EVENT(BAND_INDICATOR6 ),
      LTE_MIPI_TX_EVENT(BAND_INDICATOR7 ),
      LTE_MIPI_TX_EVENT(BAND_INDICATOR8 ),
      LTE_MIPI_TX_EVENT(BAND_INDICATOR9 ),
      LTE_MIPI_TX_EVENT(BAND_INDICATOR10),
      LTE_MIPI_TX_EVENT(BAND_INDICATOR11),
      LTE_MIPI_TX_EVENT(BAND_INDICATOR12),
      LTE_MIPI_TX_EVENT(BAND_INDICATOR13),
      LTE_MIPI_TX_EVENT(BAND_INDICATOR14),
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, // ASM PM_Trig: normal mode
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band1_MIPI_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x00 , 0x00}, { 19350 /*100 kHz*/    ,0x00 , 0x00}, { 19500 /*100 kHz*/    ,0x00 , 0x00}, { 19650 /*100 kHz*/    ,0x00 , 0x00}, { 19800 /*100 kHz*/    ,0x00 , 0x00},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x01 , 0x1F}, { 19350 /*100 kHz*/    ,0x01 , 0x1F}, { 19500 /*100 kHz*/    ,0x01 , 0x1F}, { 19650 /*100 kHz*/    ,0x01 , 0x1F}, { 19800 /*100 kHz*/    ,0x01 , 0x1F},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x02 , 0x00}, { 19350 /*100 kHz*/    ,0x02 , 0x00}, { 19500 /*100 kHz*/    ,0x02 , 0x00}, { 19650 /*100 kHz*/    ,0x02 , 0x00}, { 19800 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x03 , 0x00}, { 19350 /*100 kHz*/    ,0x03 , 0x00}, { 19500 /*100 kHz*/    ,0x03 , 0x00}, { 19650 /*100 kHz*/    ,0x03 , 0x00}, { 19800 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x01 , 0x00}, { 19350 /*100 kHz*/    ,0x01 , 0x00}, { 19500 /*100 kHz*/    ,0x01 , 0x00}, { 19650 /*100 kHz*/    ,0x01 , 0x00}, { 19800 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable                
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode  
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 19200 /*100 kHz*/    ,0x00 , 0x0C}, { 19350 /*100 kHz*/    ,0x00 , 0x0C}, { 19500 /*100 kHz*/    ,0x00 , 0x0C}, { 19650 /*100 kHz*/    ,0x00 , 0x0C}, { 19800 /*100 kHz*/    ,0x00 , 0x0C},} },                              
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band3_MIPI_TX_DATA[] = 
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x00 , 0x08}, { 17287 /*100 kHz*/    ,0x00 , 0x08}, { 17475 /*100 kHz*/    ,0x00 , 0x08}, { 17662 /*100 kHz*/    ,0x00 , 0x08}, { 17850 /*100 kHz*/    ,0x00 , 0x08},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x01 , 0x1F}, { 17287 /*100 kHz*/    ,0x01 , 0x1F}, { 17475 /*100 kHz*/    ,0x01 , 0x1F}, { 17662 /*100 kHz*/    ,0x01 , 0x1F}, { 17850 /*100 kHz*/    ,0x01 , 0x1F},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x02 , 0x00}, { 17287 /*100 kHz*/    ,0x02 , 0x00}, { 17475 /*100 kHz*/    ,0x02 , 0x00}, { 17662 /*100 kHz*/    ,0x02 , 0x00}, { 17850 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x03 , 0x00}, { 17287 /*100 kHz*/    ,0x03 , 0x00}, { 17475 /*100 kHz*/    ,0x03 , 0x00}, { 17662 /*100 kHz*/    ,0x03 , 0x00}, { 17850 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x01 , 0x00}, { 17287 /*100 kHz*/    ,0x01 , 0x00}, { 17475 /*100 kHz*/    ,0x01 , 0x00}, { 17662 /*100 kHz*/    ,0x01 , 0x00}, { 17850 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable                
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode  
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 17100 /*100 kHz*/    ,0x00 , 0x02}, { 17287 /*100 kHz*/    ,0x00 , 0x02}, { 17475 /*100 kHz*/    ,0x00 , 0x02}, { 17662 /*100 kHz*/    ,0x00 , 0x02}, { 17850 /*100 kHz*/    ,0x00 , 0x02},} },                              
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band5_MIPI_TX_DATA[] =
{
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8240 /*100 kHz*/    ,0x1C , 0x38}, { 8303 /*100 kHz*/    ,0x1C , 0x38}, { 8366 /*100 kHz*/    ,0x1C , 0x38}, { 8429 /*100 kHz*/    ,0x1C , 0x38}, { 8490 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8240 /*100 kHz*/    ,0x00 , 0x04}, { 8303 /*100 kHz*/    ,0x00 , 0x04}, { 8366 /*100 kHz*/    ,0x00 , 0x04}, { 8429 /*100 kHz*/    ,0x00 , 0x04}, { 8490 /*100 kHz*/    ,0x00 , 0x04},} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8240 /*100 kHz*/    ,0x01 , 0x0F}, { 8303 /*100 kHz*/    ,0x01 , 0x0F}, { 8366 /*100 kHz*/    ,0x01 , 0x0F}, { 8429 /*100 kHz*/    ,0x01 , 0x0F}, { 8490 /*100 kHz*/    ,0x01 , 0x0F},} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8240 /*100 kHz*/    ,0x02 , 0x00}, { 8303 /*100 kHz*/    ,0x02 , 0x00}, { 8366 /*100 kHz*/    ,0x02 , 0x00}, { 8429 /*100 kHz*/    ,0x02 , 0x00}, { 8490 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8240 /*100 kHz*/    ,0x03 , 0x00}, { 8303 /*100 kHz*/    ,0x03 , 0x00}, { 8366 /*100 kHz*/    ,0x03 , 0x00}, { 8429 /*100 kHz*/    ,0x03 , 0x00}, { 8490 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8240 /*100 kHz*/    ,0x01 , 0x00}, { 8303 /*100 kHz*/    ,0x01 , 0x00}, { 8366 /*100 kHz*/    ,0x01 , 0x00}, { 8429 /*100 kHz*/    ,0x01 , 0x00}, { 8490 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 8240 /*100 kHz*/    ,0x1C , 0x38}, { 8303 /*100 kHz*/    ,0x1C , 0x38}, { 8366 /*100 kHz*/    ,0x1C , 0x38}, { 8429 /*100 kHz*/    ,0x1C , 0x38}, { 8490 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 8240 /*100 kHz*/    ,0x00 , 0x0B}, { 8303 /*100 kHz*/    ,0x00 , 0x0B}, { 8366 /*100 kHz*/    ,0x00 , 0x0B}, { 8429 /*100 kHz*/    ,0x00 , 0x0B}, { 8490 /*100 kHz*/    ,0x00 , 0x0B},} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band7_MIPI_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25000 /*100 kHz*/    ,0x1C , 0x38}, { 25175 /*100 kHz*/    ,0x1C , 0x38}, { 25350 /*100 kHz*/    ,0x1C , 0x38}, { 25525 /*100 kHz*/    ,0x1C , 0x38}, { 25700 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25000 /*100 kHz*/    ,0x00 , 0x0D}, { 25175 /*100 kHz*/    ,0x00 , 0x0D}, { 25350 /*100 kHz*/    ,0x00 , 0x0D}, { 25525 /*100 kHz*/    ,0x00 , 0x0D}, { 25700 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25000 /*100 kHz*/    ,0x01 , 0x00}, { 25175 /*100 kHz*/    ,0x01 , 0x00}, { 25350 /*100 kHz*/    ,0x01 , 0x00}, { 25525 /*100 kHz*/    ,0x01 , 0x00}, { 25700 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25000 /*100 kHz*/    ,0x00 , 0x00}, { 25175 /*100 kHz*/    ,0x00 , 0x00}, { 25350 /*100 kHz*/    ,0x00 , 0x00}, { 25525 /*100 kHz*/    ,0x00 , 0x00}, { 25700 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band8_MIPI_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x1C , 0x38}, { 8888 /*100 kHz*/    ,0x1C , 0x38}, { 8976 /*100 kHz*/    ,0x1C , 0x38}, { 9064 /*100 kHz*/    ,0x1C , 0x38}, { 9150 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x00 , 0x00}, { 8888 /*100 kHz*/    ,0x00 , 0x00}, { 8976 /*100 kHz*/    ,0x00 , 0x00}, { 9064 /*100 kHz*/    ,0x00 , 0x00}, { 9150 /*100 kHz*/    ,0x00 , 0x00},} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x01 , 0x0F}, { 8888 /*100 kHz*/    ,0x01 , 0x0F}, { 8976 /*100 kHz*/    ,0x01 , 0x0F}, { 9064 /*100 kHz*/    ,0x01 , 0x0F}, { 9150 /*100 kHz*/    ,0x01 , 0x0F},} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x02 , 0x00}, { 8888 /*100 kHz*/    ,0x02 , 0x00}, { 8976 /*100 kHz*/    ,0x02 , 0x00}, { 9064 /*100 kHz*/    ,0x02 , 0x00}, { 9150 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x03 , 0x00}, { 8888 /*100 kHz*/    ,0x03 , 0x00}, { 8976 /*100 kHz*/    ,0x03 , 0x00}, { 9064 /*100 kHz*/    ,0x03 , 0x00}, { 9150 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x01 , 0x00}, { 8888 /*100 kHz*/    ,0x01 , 0x00}, { 8976 /*100 kHz*/    ,0x01 , 0x00}, { 9064 /*100 kHz*/    ,0x01 , 0x00}, { 9150 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 8800 /*100 kHz*/    ,0x1C , 0x38}, { 8888 /*100 kHz*/    ,0x1C , 0x38}, { 8976 /*100 kHz*/    ,0x1C , 0x38}, { 9064 /*100 kHz*/    ,0x1C , 0x38}, { 9150 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 8800 /*100 kHz*/    ,0x00 , 0x03}, { 8888 /*100 kHz*/    ,0x00 , 0x03}, { 8976 /*100 kHz*/    ,0x00 , 0x03}, { 9064 /*100 kHz*/    ,0x00 , 0x03}, { 9150 /*100 kHz*/    ,0x00 , 0x03},} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band17_MIPI_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7040 /*100 kHz*/    ,0x1C , 0x38}, { 7070 /*100 kHz*/    ,0x1C , 0x38}, { 7100 /*100 kHz*/    ,0x1C , 0x38}, { 7130 /*100 kHz*/    ,0x1C , 0x38}, { 7160 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7040 /*100 kHz*/    ,0x00 , 0x0C}, { 7070 /*100 kHz*/    ,0x00 , 0x0C}, { 7100 /*100 kHz*/    ,0x00 , 0x0C}, { 7130 /*100 kHz*/    ,0x00 , 0x0C}, { 7160 /*100 kHz*/    ,0x00 , 0x0C},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7040 /*100 kHz*/    ,0x01 , 0x0F}, { 7070 /*100 kHz*/    ,0x01 , 0x0F}, { 7100 /*100 kHz*/    ,0x01 , 0x0F}, { 7130 /*100 kHz*/    ,0x01 , 0x0F}, { 7160 /*100 kHz*/    ,0x01 , 0x0F},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7040 /*100 kHz*/    ,0x02 , 0x00}, { 7070 /*100 kHz*/    ,0x02 , 0x00}, { 7100 /*100 kHz*/    ,0x02 , 0x00}, { 7130 /*100 kHz*/    ,0x02 , 0x00}, { 7160 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7040 /*100 kHz*/    ,0x03 , 0x00}, { 7070 /*100 kHz*/    ,0x03 , 0x00}, { 7100 /*100 kHz*/    ,0x03 , 0x00}, { 7130 /*100 kHz*/    ,0x03 , 0x00}, { 7160 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7040 /*100 kHz*/    ,0x01 , 0x00}, { 7070 /*100 kHz*/    ,0x01 , 0x00}, { 7100 /*100 kHz*/    ,0x01 , 0x00}, { 7130 /*100 kHz*/    ,0x01 , 0x00}, { 7160 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable                
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7040 /*100 kHz*/    ,0x1C , 0x38}, { 7070 /*100 kHz*/    ,0x1C , 0x38}, { 7100 /*100 kHz*/    ,0x1C , 0x38}, { 7130 /*100 kHz*/    ,0x1C , 0x38}, { 7160 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode  
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7040 /*100 kHz*/    ,0x00 , 0x01}, { 7070 /*100 kHz*/    ,0x00 , 0x01}, { 7100 /*100 kHz*/    ,0x00 , 0x01}, { 7130 /*100 kHz*/    ,0x00 , 0x01}, { 7160 /*100 kHz*/    ,0x00 , 0x01},} },                              
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band38_MIPI_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x00 , 0x0D}, { 25825 /*100 kHz*/    ,0x00 , 0x0D}, { 25950 /*100 kHz*/    ,0x00 , 0x0D}, { 26075 /*100 kHz*/    ,0x00 , 0x0D}, { 26200 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x01 , 0x00}, { 25825 /*100 kHz*/    ,0x01 , 0x00}, { 25950 /*100 kHz*/    ,0x01 , 0x00}, { 26075 /*100 kHz*/    ,0x01 , 0x00}, { 26200 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x00 , 0x00}, { 25825 /*100 kHz*/    ,0x00 , 0x00}, { 25950 /*100 kHz*/    ,0x00 , 0x00}, { 26075 /*100 kHz*/    ,0x00 , 0x00}, { 26200 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band39_MIPI_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x00 , 0x0C}, { 18900 /*100 kHz*/    ,0x00 , 0x0C}, { 19000 /*100 kHz*/    ,0x00 , 0x0C}, { 19100 /*100 kHz*/    ,0x00 , 0x0C}, { 19200 /*100 kHz*/    ,0x00 , 0x0C},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x01 , 0x1F}, { 18900 /*100 kHz*/    ,0x01 , 0x1F}, { 19000 /*100 kHz*/    ,0x01 , 0x1F}, { 19100 /*100 kHz*/    ,0x01 , 0x1F}, { 19200 /*100 kHz*/    ,0x01 , 0x1F},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x02 , 0x00}, { 18900 /*100 kHz*/    ,0x02 , 0x00}, { 19000 /*100 kHz*/    ,0x02 , 0x00}, { 19100 /*100 kHz*/    ,0x02 , 0x00}, { 19200 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x03 , 0x00}, { 18900 /*100 kHz*/    ,0x03 , 0x00}, { 19000 /*100 kHz*/    ,0x03 , 0x00}, { 19100 /*100 kHz*/    ,0x03 , 0x00}, { 19200 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x01 , 0x00}, { 18900 /*100 kHz*/    ,0x01 , 0x00}, { 19000 /*100 kHz*/    ,0x01 , 0x00}, { 19100 /*100 kHz*/    ,0x01 , 0x00}, { 19200 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable                
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode  
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x00 , 0x05}, { 18900 /*100 kHz*/    ,0x00 , 0x05}, { 19000 /*100 kHz*/    ,0x00 , 0x05}, { 19100 /*100 kHz*/    ,0x00 , 0x05}, { 19200 /*100 kHz*/    ,0x00 , 0x05},} },                              
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band40_MIPI_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x00 , 0x0D}, { 23250 /*100 kHz*/    ,0x00 , 0x0D}, { 23500 /*100 kHz*/    ,0x00 , 0x0D}, { 23750 /*100 kHz*/    ,0x00 , 0x0D}, { 24000 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x01 , 0x00}, { 23250 /*100 kHz*/    ,0x01 , 0x00}, { 23500 /*100 kHz*/    ,0x01 , 0x00}, { 23750 /*100 kHz*/    ,0x01 , 0x00}, { 24000 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x00 , 0x00}, { 23250 /*100 kHz*/    ,0x00 , 0x00}, { 23500 /*100 kHz*/    ,0x00 , 0x00}, { 23750 /*100 kHz*/    ,0x00 , 0x00}, { 24000 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band41_MIPI_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x00 , 0x0D}, { 25445 /*100 kHz*/    ,0x00 , 0x0D}, { 25930 /*100 kHz*/    ,0x00 , 0x0D}, { 26415 /*100 kHz*/    ,0x00 , 0x0D}, { 26900 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x01 , 0x00}, { 25445 /*100 kHz*/    ,0x01 , 0x00}, { 25930 /*100 kHz*/    ,0x01 , 0x00}, { 26415 /*100 kHz*/    ,0x01 , 0x00}, { 26900 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x00 , 0x00}, { 25445 /*100 kHz*/    ,0x00 , 0x00}, { 25930 /*100 kHz*/    ,0x00 , 0x00}, { 26415 /*100 kHz*/    ,0x00 , 0x00}, { 26900 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};
kal_uint32  LTE_MIPI_TX_DATA_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR1 )),
      sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR2 )),
      sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR3 )),
      sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR4 )),
      sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR5 )),
      sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR6 )),
      sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR7 )),
      sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR8 )),
      sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR9 )),
      sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR10)),
      sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR11)),
      sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR12)),
      sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR13)),
      sizeof(LTE_MIPI_TX_DATA(BAND_INDICATOR14)),
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_TX_DATA_TABLE[] =
{
      LTE_BandNone_MIPI_TX_DATA,
      LTE_MIPI_TX_DATA(BAND_INDICATOR1 ),
      LTE_MIPI_TX_DATA(BAND_INDICATOR2 ),
      LTE_MIPI_TX_DATA(BAND_INDICATOR3 ),
      LTE_MIPI_TX_DATA(BAND_INDICATOR4 ),
      LTE_MIPI_TX_DATA(BAND_INDICATOR5 ),
      LTE_MIPI_TX_DATA(BAND_INDICATOR6 ),
      LTE_MIPI_TX_DATA(BAND_INDICATOR7 ),
      LTE_MIPI_TX_DATA(BAND_INDICATOR8 ),
      LTE_MIPI_TX_DATA(BAND_INDICATOR9 ),
      LTE_MIPI_TX_DATA(BAND_INDICATOR10),
      LTE_MIPI_TX_DATA(BAND_INDICATOR11),
      LTE_MIPI_TX_DATA(BAND_INDICATOR12),
      LTE_MIPI_TX_DATA(BAND_INDICATOR13),
      LTE_MIPI_TX_DATA(BAND_INDICATOR14),
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_TPC_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band1_MIPI_TPC_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band3_MIPI_TPC_EVENT[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band5_MIPI_TPC_EVENT[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band7_MIPI_TPC_EVENT[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band8_MIPI_TPC_EVENT[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};


LTE_MIPI_EVENT_TABLE_T LTE_Band17_MIPI_TPC_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_TPC_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band39_MIPI_TPC_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_TPC_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_TPC_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};
kal_uint32  LTE_MIPI_TPC_EVENT_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR1 )),
      sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR2 )),
      sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR3 )),
      sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR4 )),
      sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR5 )),
      sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR6 )),
      sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR7 )),
      sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR8 )),
      sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR9 )),
      sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR10)),
      sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR11)),
      sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR12)),
      sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR13)),
      sizeof(LTE_MIPI_TPC_EVENT(BAND_INDICATOR14)),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_TPC_EVENT_TABLE[] =
{
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_MIPI_TPC_EVENT(BAND_INDICATOR1 ),
      LTE_MIPI_TPC_EVENT(BAND_INDICATOR2 ),
      LTE_MIPI_TPC_EVENT(BAND_INDICATOR3 ),
      LTE_MIPI_TPC_EVENT(BAND_INDICATOR4 ),
      LTE_MIPI_TPC_EVENT(BAND_INDICATOR5 ),
      LTE_MIPI_TPC_EVENT(BAND_INDICATOR6 ),
      LTE_MIPI_TPC_EVENT(BAND_INDICATOR7 ),
      LTE_MIPI_TPC_EVENT(BAND_INDICATOR8 ),
      LTE_MIPI_TPC_EVENT(BAND_INDICATOR9 ),
      LTE_MIPI_TPC_EVENT(BAND_INDICATOR10),
      LTE_MIPI_TPC_EVENT(BAND_INDICATOR11),
      LTE_MIPI_TPC_EVENT(BAND_INDICATOR12),
      LTE_MIPI_TPC_EVENT(BAND_INDICATOR13),
      LTE_MIPI_TPC_EVENT(BAND_INDICATOR14),
};

LTE_MIPI_DATA_TABLE_T LTE_BandNone_MIPI_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band1_MIPI_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band3_MIPI_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band5_MIPI_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band7_MIPI_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band8_MIPI_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band17_MIPI_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band38_MIPI_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band39_MIPI_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band40_MIPI_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band41_MIPI_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};
kal_uint32  LTE_MIPI_TPC_DATA_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_MIPI_TPC_DATA(BAND_INDICATOR1 )),
      sizeof(LTE_MIPI_TPC_DATA(BAND_INDICATOR2 )),
      sizeof(LTE_MIPI_TPC_DATA(BAND_INDICATOR3 )),
      sizeof(LTE_MIPI_TPC_DATA(BAND_INDICATOR4 )),
      sizeof(LTE_MIPI_TPC_DATA(BAND_INDICATOR5 )),
      sizeof(LTE_MIPI_TPC_DATA(BAND_INDICATOR6 )),
      sizeof(LTE_MIPI_TPC_DATA(BAND_INDICATOR7 )),
      sizeof(LTE_MIPI_TPC_DATA(BAND_INDICATOR8 )),
      sizeof(LTE_MIPI_TPC_DATA(BAND_INDICATOR9 )),
      sizeof(LTE_MIPI_TPC_DATA(BAND_INDICATOR10)),
      sizeof(LTE_MIPI_TPC_DATA(BAND_INDICATOR11)),
      sizeof(LTE_MIPI_TPC_DATA(BAND_INDICATOR12)),
      sizeof(LTE_MIPI_TPC_DATA(BAND_INDICATOR13)),
      sizeof(LTE_MIPI_TPC_DATA(BAND_INDICATOR14)),
};

LTE_MIPI_DATA_TABLE_T*  LTE_MIPI_TPC_DATA_TABLE[] =
{
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_MIPI_TPC_DATA(BAND_INDICATOR1 ),
      LTE_MIPI_TPC_DATA(BAND_INDICATOR2 ),
      LTE_MIPI_TPC_DATA(BAND_INDICATOR3 ),
      LTE_MIPI_TPC_DATA(BAND_INDICATOR4 ),
      LTE_MIPI_TPC_DATA(BAND_INDICATOR5 ),
      LTE_MIPI_TPC_DATA(BAND_INDICATOR6 ),
      LTE_MIPI_TPC_DATA(BAND_INDICATOR7 ),
      LTE_MIPI_TPC_DATA(BAND_INDICATOR8 ),
      LTE_MIPI_TPC_DATA(BAND_INDICATOR9 ),
      LTE_MIPI_TPC_DATA(BAND_INDICATOR10),
      LTE_MIPI_TPC_DATA(BAND_INDICATOR11),
      LTE_MIPI_TPC_DATA(BAND_INDICATOR12),
      LTE_MIPI_TPC_DATA(BAND_INDICATOR13),
      LTE_MIPI_TPC_DATA(BAND_INDICATOR14),
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_BandNone_MIPI_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band1_MIPI_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      19200,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      19350,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      19500,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
     }
   },

      /*8804 KHz*/
   {
      19650,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      19800,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band3_MIPI_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      17100,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      17287,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      17475,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      17662,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      17850,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band5_MIPI_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      8240,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      8303,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      8366,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      8429,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      8490,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band7_MIPI_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      25000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25175,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25350,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      25525,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      25700,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band8_MIPI_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      8800,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      8888,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      8976,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      9064,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      9150,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band17_MIPI_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      7040,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      7070,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      7100,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      7130,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      7160,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band38_MIPI_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      25700,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25825,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25950,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      26075,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      26200,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};
LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band39_MIPI_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*18800 KHz*/
   {
      18800,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
      
      /*18900 KHz*/
   {
      18900,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   }, 
      
      /*19000 KHz*/
   {
      19000,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
      
      /*19100 KHz*/
   {
      19100,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
      
      /*19200 KHz*/
   {
      19200,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};
LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band40_MIPI_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      23000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      23250,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      23500,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      23750,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      24000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band41_MIPI_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      24960,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25445,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25930,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      26415,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      26900,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};
kal_uint32  LTE_MIPI_PA_TPC_SECTION_DATA_SIZE[] =
{
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR1 )),
      sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR2 )),
      sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR3 )),
      sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR4 )),
      sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR5 )),
      sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR6 )),
      sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR7 )),
      sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR8 )),
      sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR9 )),
      sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR10)),
      sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR11)),
      sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR12)),
      sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR13)),
      sizeof(LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR14)),
};

LTE_MIPI_TPC_SECTION_TABLE_T*  LTE_MIPI_PA_TPC_SECTION_DATA[] =
{
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR1 ),
      LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR2 ),
      LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR3 ),
      LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR4 ),
      LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR5 ),
      LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR6 ),
      LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR7 ),
      LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR8 ),
      LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR9 ),
      LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR10),
      LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR11),
      LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR12),
      LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR13),
      LTE_MIPI_PA_SECTION_DATA(BAND_INDICATOR14),
};


/*special handle for T/Rx calibration, we should force ASM to isolation mode */
/*Users just need to provide the ASM isolation CW, DSP may use immediate mode*/
/*to control the MIPI ASM                                                    */
LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_ASM_ISOLATION_DATA[] =
{
   //No.      elm type     , port_sel       , data_seq     ,       USID       , addr  , data , wait_time(us)
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1 , LTE_REG_W    , MIPI_USID_ASM0   , {0x0  , 0x7F} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = normal mode
   {LTE_MIPI_END_PATTERN,0,0,0,{0,0},0},
};

/*** MIPI BYPASS Feature ***/
LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_BYPASS_TX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_BYPASS_TX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_BYPASS_TX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_BYPASS_TX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

kal_uint32  LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),
      sizeof(LTE_MIPI_BYPASS_TX_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR1 )),
      sizeof(LTE_MIPI_BYPASS_TX_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR2 )),
      sizeof(LTE_MIPI_BYPASS_TX_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR3 )),
      sizeof(LTE_MIPI_BYPASS_TX_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR4 )),
      sizeof(LTE_MIPI_BYPASS_TX_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR5 )),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_BYPASS_TX_EVENT_TABLE[] =
{
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,
      LTE_MIPI_BYPASS_TX_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR1 ),
      LTE_MIPI_BYPASS_TX_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR2 ),
      LTE_MIPI_BYPASS_TX_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR3 ),      
      LTE_MIPI_BYPASS_TX_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR4 ),
      LTE_MIPI_BYPASS_TX_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR5 ),      
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_BYPASS_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, // ASM PM_Trig: normal mode
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band38_MIPI_BYPASS_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x00 , 0x2A}, { 25825 /*100 kHz*/    ,0x00 , 0x2A}, { 25950 /*100 kHz*/    ,0x00 , 0x2A}, { 26075 /*100 kHz*/    ,0x00 , 0x2A}, { 26200 /*100 kHz*/    ,0x00 , 0x2A},} }, // PA path sel _enable            
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x01 , 0x00}, { 25825 /*100 kHz*/    ,0x01 , 0x00}, { 25950 /*100 kHz*/    ,0x01 , 0x00}, { 26075 /*100 kHz*/    ,0x01 , 0x00}, { 26200 /*100 kHz*/    ,0x01, 0x00},} }, // Iref                
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x00 , 0x00}, { 25825 /*100 kHz*/    ,0x00 , 0x00}, { 25950 /*100 kHz*/    ,0x00 , 0x00}, { 26075 /*100 kHz*/    ,0x00 , 0x00}, { 26200 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band40_MIPI_BYPASS_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x00 , 0x2A}, { 23250 /*100 kHz*/    ,0x00 , 0x2A}, { 23500 /*100 kHz*/    ,0x00 , 0x2A}, { 23750 /*100 kHz*/    ,0x00 , 0x2A}, { 24000 /*100 kHz*/    ,0x00 , 0x2A},} }, // PA path sel _enable            
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x01 , 0x00}, { 23250 /*100 kHz*/    ,0x01 , 0x00}, { 23500 /*100 kHz*/    ,0x01 , 0x00}, { 23750 /*100 kHz*/    ,0x01 , 0x00}, { 24000 /*100 kHz*/    ,0x01, 0x00},} }, // Iref                
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x00 , 0x00}, { 23250 /*100 kHz*/    ,0x00 , 0x00}, { 23500 /*100 kHz*/    ,0x00 , 0x00}, { 23750 /*100 kHz*/    ,0x00 , 0x00}, { 24000 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band41_MIPI_BYPASS_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },  
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x00 , 0x2A}, { 25445 /*100 kHz*/    ,0x00 , 0x2A}, { 25930 /*100 kHz*/    ,0x00 , 0x2A}, { 26415 /*100 kHz*/    ,0x00 , 0x2A}, { 26900 /*100 kHz*/    ,0x00 , 0x2A},} }, // PA path sel _enable            
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x01 , 0x00}, { 25445 /*100 kHz*/    ,0x01 , 0x00}, { 25930 /*100 kHz*/    ,0x01 , 0x00}, { 26415 /*100 kHz*/    ,0x01 , 0x00}, { 26900 /*100 kHz*/    ,0x01, 0x00},} }, // Iref                
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x00 , 0x00}, { 25445 /*100 kHz*/    ,0x00 , 0x00}, { 25930 /*100 kHz*/    ,0x00 , 0x00}, { 26415 /*100 kHz*/    ,0x00 , 0x00}, { 26900 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

kal_uint32  LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),
      sizeof(LTE_MIPI_BYPASS_TX_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR1 )),
      sizeof(LTE_MIPI_BYPASS_TX_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR2 )),
      sizeof(LTE_MIPI_BYPASS_TX_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR3 )),
      sizeof(LTE_MIPI_BYPASS_TX_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR4 )),
      sizeof(LTE_MIPI_BYPASS_TX_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR5 )),
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_BYPASS_TX_DATA_TABLE[] =
{
      LTE_BandNone_MIPI_BYPASS_TX_DATA,
      LTE_MIPI_BYPASS_TX_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR1 ),
      LTE_MIPI_BYPASS_TX_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR2 ),
      LTE_MIPI_BYPASS_TX_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR3 ),
      LTE_MIPI_BYPASS_TX_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR4 ),
      LTE_MIPI_BYPASS_TX_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR5 ),
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_BYPASS_TPC_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_BYPASS_TPC_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_BYPASS_TPC_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_BYPASS_TPC_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

kal_uint32  LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),
      sizeof(LTE_MIPI_BYPASS_TPC_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR1 )),
      sizeof(LTE_MIPI_BYPASS_TPC_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR2 )),
      sizeof(LTE_MIPI_BYPASS_TPC_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR3 )),
      sizeof(LTE_MIPI_BYPASS_TPC_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR4 )),
      sizeof(LTE_MIPI_BYPASS_TPC_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR5 )),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_BYPASS_TPC_EVENT_TABLE[] =
{
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,
      LTE_MIPI_BYPASS_TPC_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR1 ),
      LTE_MIPI_BYPASS_TPC_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR2 ),
      LTE_MIPI_BYPASS_TPC_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR3 ),
      LTE_MIPI_BYPASS_TPC_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR4 ),
      LTE_MIPI_BYPASS_TPC_EVENT(LTE_MIPI_BYPASS_BAND_INDICATOR5 ),
};

LTE_MIPI_DATA_TABLE_T LTE_BandNone_MIPI_BYPASS_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band38_MIPI_BYPASS_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band40_MIPI_BYPASS_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band41_MIPI_BYPASS_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

kal_uint32  LTE_MIPI_BYPASS_TPC_DATA_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_DATA),
      sizeof(LTE_MIPI_BYPASS_TPC_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR1 )),
      sizeof(LTE_MIPI_BYPASS_TPC_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR2 )),
      sizeof(LTE_MIPI_BYPASS_TPC_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR3 )),
      sizeof(LTE_MIPI_BYPASS_TPC_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR4 )),
      sizeof(LTE_MIPI_BYPASS_TPC_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR5 )),
};



LTE_MIPI_DATA_TABLE_T*  LTE_MIPI_BYPASS_TPC_DATA_TABLE[] =
{
      LTE_BandNone_MIPI_BYPASS_TPC_DATA,
      LTE_MIPI_BYPASS_TPC_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR1 ),
      LTE_MIPI_BYPASS_TPC_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR2 ),
      LTE_MIPI_BYPASS_TPC_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR3 ),
      LTE_MIPI_BYPASS_TPC_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR4 ),
      LTE_MIPI_BYPASS_TPC_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR5 ),
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band38_MIPI_BYPASS_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      25700,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25825,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , {0x0 , 0x00} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25950,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , {0x0 , 0x00} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      26075,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , {0x0 , 0x00} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      26200,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , {0x0 , 0x00} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band40_MIPI_BYPASS_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      23000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , {0x0 , 0x00} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      23250,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , {0x0 , 0x00} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      23500,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , {0x0 , 0x00} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      23750,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , {0x0 , 0x00} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      24000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , {0x0 , 0x00} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band41_MIPI_BYPASS_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      24960,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , {0x0 , 0x00} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25445,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , {0x0 , 0x00} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25930,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , {0x0 , 0x00} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      26415,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , {0x0 , 0x00} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      26900,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , {0x0 , 0x00} , { 0x0 , 0x0}}},//SRS
      }
   },
};

kal_uint32  LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),
      sizeof(LTE_MIPI_BYPASS_PA_SECTION_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR1 )),
      sizeof(LTE_MIPI_BYPASS_PA_SECTION_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR2 )),
      sizeof(LTE_MIPI_BYPASS_PA_SECTION_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR3 )),
      sizeof(LTE_MIPI_BYPASS_PA_SECTION_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR4 )),
      sizeof(LTE_MIPI_BYPASS_PA_SECTION_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR5 )),
};

LTE_MIPI_TPC_SECTION_TABLE_T*  LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA[] =
{
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,
      LTE_MIPI_BYPASS_PA_SECTION_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR1 ),
      LTE_MIPI_BYPASS_PA_SECTION_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR2 ),
      LTE_MIPI_BYPASS_PA_SECTION_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR3 ),
      LTE_MIPI_BYPASS_PA_SECTION_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR4 ),
      LTE_MIPI_BYPASS_PA_SECTION_DATA(LTE_MIPI_BYPASS_BAND_INDICATOR5 ),
};

/////////////////////////////////////////////
#else //IS_MIPI_FRONT_END_ENABLE

LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_INITIAL_CW[] =
{
   // elm type   , port_sel      , data_seq ,    USID          ,addr , data          , wait_time(us)
   {LTE_MIPI_END_PATTERN,0,0,0,{0,0},0},
};

LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_SLEEP_CW[] =
{
   //   elm type , port_sel      , data_seq,    USID           ,addr , data         , wait_time(us)
   {LTE_MIPI_END_PATTERN,0,0,0,{0,0},0},
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_RX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

kal_uint32  LTE_MIPI_RX_EVENT_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
      sizeof(LTE_BandNone_MIPI_RX_EVENT),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_RX_EVENT_TABLE[] =
{
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_BandNone_MIPI_RX_EVENT,
      LTE_BandNone_MIPI_RX_EVENT,
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_RX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, // ASM PM_Trig: normal mode
};

kal_uint32  LTE_MIPI_RX_DATA_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_BandNone_MIPI_RX_DATA),
      sizeof(LTE_BandNone_MIPI_RX_DATA),
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_RX_DATA_TABLE[] =
{
      LTE_BandNone_MIPI_RX_DATA,
      LTE_BandNone_MIPI_RX_DATA,
      LTE_BandNone_MIPI_RX_DATA,
      LTE_BandNone_MIPI_RX_DATA,
      LTE_BandNone_MIPI_RX_DATA,
      LTE_BandNone_MIPI_RX_DATA,
      LTE_BandNone_MIPI_RX_DATA,
      LTE_BandNone_MIPI_RX_DATA,
      LTE_BandNone_MIPI_RX_DATA,
      LTE_BandNone_MIPI_RX_DATA,
      LTE_BandNone_MIPI_RX_DATA,
      LTE_BandNone_MIPI_RX_DATA,
      LTE_BandNone_MIPI_RX_DATA,
      LTE_BandNone_MIPI_RX_DATA,
      LTE_BandNone_MIPI_RX_DATA,
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_TX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

kal_uint32  LTE_MIPI_TX_EVENT_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_TX_EVENT),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_TX_EVENT_TABLE[] =
{
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_BandNone_MIPI_TX_EVENT,
      LTE_BandNone_MIPI_TX_EVENT,
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, // ASM PM_Trig: normal mode
};

kal_uint32  LTE_MIPI_TX_DATA_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_BandNone_MIPI_TX_DATA),
      sizeof(LTE_BandNone_MIPI_TX_DATA),
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_TX_DATA_TABLE[] =
{
      LTE_BandNone_MIPI_TX_DATA,
      LTE_BandNone_MIPI_TX_DATA,
      LTE_BandNone_MIPI_TX_DATA,
      LTE_BandNone_MIPI_TX_DATA,
      LTE_BandNone_MIPI_TX_DATA,
      LTE_BandNone_MIPI_TX_DATA,
      LTE_BandNone_MIPI_TX_DATA,
      LTE_BandNone_MIPI_TX_DATA,
      LTE_BandNone_MIPI_TX_DATA,
      LTE_BandNone_MIPI_TX_DATA,
      LTE_BandNone_MIPI_TX_DATA,
      LTE_BandNone_MIPI_TX_DATA,
      LTE_BandNone_MIPI_TX_DATA,
      LTE_BandNone_MIPI_TX_DATA,
      LTE_BandNone_MIPI_TX_DATA,
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_TPC_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

kal_uint32  LTE_MIPI_TPC_EVENT_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_TPC_EVENT_TABLE[] =
{
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_BandNone_MIPI_TPC_EVENT,
      LTE_BandNone_MIPI_TPC_EVENT,
};

LTE_MIPI_DATA_TABLE_T LTE_BandNone_MIPI_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_NULL  , 0                , 0           , 0                             , 0                            , 0               },
};

kal_uint32  LTE_MIPI_TPC_DATA_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_TPC_DATA),
};

LTE_MIPI_DATA_TABLE_T*  LTE_MIPI_TPC_DATA_TABLE[] =
{
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_BandNone_MIPI_TPC_DATA,
      LTE_BandNone_MIPI_TPC_DATA,
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_BandNone_MIPI_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      0,/*100kHz*/
      0,
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      0,/*100kHz*/
      0,
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      0,/*100kHz*/
      0,
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      0,/*100kHz*/
      0,
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      0,/*100kHz*/
      0,
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },
};

kal_uint32  LTE_MIPI_PA_TPC_SECTION_DATA_SIZE[] =
{
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),
};

LTE_MIPI_TPC_SECTION_TABLE_T*  LTE_MIPI_PA_TPC_SECTION_DATA[] =
{
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_BandNone_MIPI_PA_SECTION_DATA,
      LTE_BandNone_MIPI_PA_SECTION_DATA,
};

LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_ASM_ISOLATION_DATA[] =
{
   //No.      elm type , port_sel   , data_seq ,addr , data       , wait_time(us)
   {LTE_MIPI_END_PATTERN,0,0,0,{0,0},0},
};

/*** MIPI BYPASS Feature ***/
LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_BYPASS_TX_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

kal_uint32  LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_BYPASS_TX_EVENT_TABLE[] =
{
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,      
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_BYPASS_TX_DATA[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, // ASM PM_Trig: normal mode
};

kal_uint32  LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_BYPASS_TX_DATA_TABLE[] =
{
      LTE_BandNone_MIPI_BYPASS_TX_DATA,
      LTE_BandNone_MIPI_BYPASS_TX_DATA,
      LTE_BandNone_MIPI_BYPASS_TX_DATA,
      LTE_BandNone_MIPI_BYPASS_TX_DATA,
      LTE_BandNone_MIPI_BYPASS_TX_DATA,
      LTE_BandNone_MIPI_BYPASS_TX_DATA,
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_BYPASS_TPC_EVENT[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

kal_uint32  LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_BYPASS_TPC_EVENT_TABLE[] =
{
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,
};

LTE_MIPI_DATA_TABLE_T LTE_BandNone_MIPI_BYPASS_TPC_DATA[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

kal_uint32  LTE_MIPI_BYPASS_TPC_DATA_SIZE_TABLE[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_DATA),
};

LTE_MIPI_DATA_TABLE_T*  LTE_MIPI_BYPASS_TPC_DATA_TABLE[] =
{
      LTE_BandNone_MIPI_BYPASS_TPC_DATA,
      LTE_BandNone_MIPI_BYPASS_TPC_DATA,
      LTE_BandNone_MIPI_BYPASS_TPC_DATA,
      LTE_BandNone_MIPI_BYPASS_TPC_DATA,
      LTE_BandNone_MIPI_BYPASS_TPC_DATA,
      LTE_BandNone_MIPI_BYPASS_TPC_DATA,
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },
};

kal_uint32  LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),
};

LTE_MIPI_TPC_SECTION_TABLE_T*  LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA[] =
{
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // !!!DON'T MODIFY!!!      
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // Band_ind=0              
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // Band_ind=1              
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // Band_ind=2              
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // Band_ind=3              
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // Band_ind=4              
};
#endif//end of #if IS_MIPI_FRONT_END_ENABLE

kal_uint32 LTE_MIPI_RX_EVENT_SIZE_TABLE_Set0[] =
{
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // LTE_BandNone, !!!DON'T MODIFY!!!    
      sizeof(LTE_Band1_MIPI_RX_EVENT),    // Band_ind=0                     
      sizeof(LTE_Band3_MIPI_RX_EVENT),    // Band_ind=1                     
      sizeof(LTE_Band7_MIPI_RX_EVENT),    // Band_ind=2                     
      sizeof(LTE_Band17_MIPI_RX_EVENT),    // Band_ind=3                    
      sizeof(LTE_Band38_MIPI_RX_EVENT),    // Band_ind=4                    
      sizeof(LTE_Band39_MIPI_RX_EVENT),   // Band_ind=5                     
      sizeof(LTE_Band40_MIPI_RX_EVENT),   // Band_ind=6                     
      sizeof(LTE_Band41_MIPI_RX_EVENT),   // Band_ind=7                     
      sizeof(LTE_Band8_MIPI_RX_EVENT),   // Band_ind=8                      
      sizeof(LTE_Band5_MIPI_RX_EVENT),   // Band_ind=9                        
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // Band_ind=10                         
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // Band_ind=11                         
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // Band_ind=12                         
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // Band_ind=13                         
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_RX_EVENT_TABLE_Set0[] =
{
      LTE_BandNone_MIPI_RX_EVENT,    // LTE_BandNone, !!!DON'T MODIFY!!!        
      LTE_Band1_MIPI_RX_EVENT,       // Band_ind=0                         
      LTE_Band3_MIPI_RX_EVENT,       // Band_ind=1                         
      LTE_Band7_MIPI_RX_EVENT,       // Band_ind=2                         
      LTE_Band17_MIPI_RX_EVENT,       // Band_ind=3                        
      LTE_Band38_MIPI_RX_EVENT,       // Band_ind=4                        
      LTE_Band39_MIPI_RX_EVENT,      // Band_ind=5                         
      LTE_Band40_MIPI_RX_EVENT,      // Band_ind=6                         
      LTE_Band41_MIPI_RX_EVENT,      // Band_ind=7                         
      LTE_Band8_MIPI_RX_EVENT,      // Band_ind=8                          
      LTE_Band5_MIPI_RX_EVENT,      // Band_ind=9                            
      LTE_BandNone_MIPI_RX_EVENT,    // Band_ind=10                             
      LTE_BandNone_MIPI_RX_EVENT,    // Band_ind=11                             
      LTE_BandNone_MIPI_RX_EVENT,    // Band_ind=12                             
      LTE_BandNone_MIPI_RX_EVENT,    // Band_ind=13                             
};

kal_uint32 LTE_MIPI_RX_DATA_SIZE_TABLE_Set0[] =
{
      sizeof(LTE_BandNone_MIPI_RX_DATA), // LTE_BandNone, !!!DON'T MODIFY!!!  
      sizeof(LTE_Band1_MIPI_RX_DATA),    // Band_ind=0                   
      sizeof(LTE_Band3_MIPI_RX_DATA),    // Band_ind=1                   
      sizeof(LTE_Band7_MIPI_RX_DATA),    // Band_ind=2                   
      sizeof(LTE_Band17_MIPI_RX_DATA),    // Band_ind=3                  
      sizeof(LTE_Band38_MIPI_RX_DATA),    // Band_ind=4                  
      sizeof(LTE_Band39_MIPI_RX_DATA),   // Band_ind=5                   
      sizeof(LTE_Band40_MIPI_RX_DATA),   // Band_ind=6                   
      sizeof(LTE_Band41_MIPI_RX_DATA),   // Band_ind=7                   
      sizeof(LTE_Band8_MIPI_RX_DATA),   // Band_ind=8                    
      sizeof(LTE_Band5_MIPI_RX_DATA),   // Band_ind=9                      
      sizeof(LTE_BandNone_MIPI_RX_DATA), // Band_ind=10                       
      sizeof(LTE_BandNone_MIPI_RX_DATA), // Band_ind=11                       
      sizeof(LTE_BandNone_MIPI_RX_DATA), // Band_ind=12                       
      sizeof(LTE_BandNone_MIPI_RX_DATA), // Band_ind=13                       
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_RX_DATA_TABLE_Set0[] =
{
      LTE_BandNone_MIPI_RX_DATA,     // LTE_BandNone, !!!DON'T MODIFY!!!  
      LTE_Band1_MIPI_RX_DATA,        // Band_ind=0                   
      LTE_Band3_MIPI_RX_DATA,        // Band_ind=1                   
      LTE_Band7_MIPI_RX_DATA,        // Band_ind=2                   
      LTE_Band17_MIPI_RX_DATA,        // Band_ind=3                  
      LTE_Band38_MIPI_RX_DATA,        // Band_ind=4                  
      LTE_Band39_MIPI_RX_DATA,       // Band_ind=5                   
      LTE_Band40_MIPI_RX_DATA,       // Band_ind=6                   
      LTE_Band41_MIPI_RX_DATA,       // Band_ind=7                   
      LTE_Band8_MIPI_RX_DATA,       // Band_ind=8                    
      LTE_Band5_MIPI_RX_DATA,       // Band_ind=9                      
      LTE_BandNone_MIPI_RX_DATA,     // Band_ind=10                       
      LTE_BandNone_MIPI_RX_DATA,     // Band_ind=11                       
      LTE_BandNone_MIPI_RX_DATA,     // Band_ind=12                       
      LTE_BandNone_MIPI_RX_DATA,     // Band_ind=13                       
};

kal_uint32  LTE_MIPI_TX_EVENT_SIZE_TABLE_Set0[] =
{
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // LTE_BandNone, !!!DON'T MODIFY!!! 
      sizeof(LTE_Band1_MIPI_TX_EVENT),    // Band_ind=0                       
      sizeof(LTE_Band3_MIPI_TX_EVENT),    // Band_ind=1                       
      sizeof(LTE_Band7_MIPI_TX_EVENT),    // Band_ind=2                       
      sizeof(LTE_Band17_MIPI_TX_EVENT),    // Band_ind=3                       
      sizeof(LTE_Band38_MIPI_TX_EVENT),    // Band_ind=4                       
      sizeof(LTE_Band39_MIPI_TX_EVENT),   // Band_ind=5                       
      sizeof(LTE_Band40_MIPI_TX_EVENT),   // Band_ind=6                       
      sizeof(LTE_Band41_MIPI_TX_EVENT),   // Band_ind=7                       
      sizeof(LTE_Band8_MIPI_TX_EVENT),   // Band_ind=8                       
      sizeof(LTE_Band5_MIPI_TX_EVENT),   // Band_ind=9                       
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // Band_ind=10                      
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // Band_ind=11                      
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // Band_ind=12                      
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // Band_ind=13                      
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_TX_EVENT_TABLE_Set0[] =
{
      LTE_BandNone_MIPI_TX_EVENT,    // LTE_BandNone, !!!DON'T MODIFY!!!      
      LTE_Band1_MIPI_TX_EVENT,       // Band_ind=0                            
      LTE_Band3_MIPI_TX_EVENT,       // Band_ind=1                            
      LTE_Band7_MIPI_TX_EVENT,       // Band_ind=2                            
      LTE_Band17_MIPI_TX_EVENT,       // Band_ind=3                            
      LTE_Band38_MIPI_TX_EVENT,       // Band_ind=4                            
      LTE_Band39_MIPI_TX_EVENT,      // Band_ind=5                            
      LTE_Band40_MIPI_TX_EVENT,      // Band_ind=6                            
      LTE_Band41_MIPI_TX_EVENT,      // Band_ind=7                            
      LTE_Band8_MIPI_TX_EVENT,      // Band_ind=8                            
      LTE_Band5_MIPI_TX_EVENT,      // Band_ind=9                            
      LTE_BandNone_MIPI_TX_EVENT,    // Band_ind=10                           
      LTE_BandNone_MIPI_TX_EVENT,    // Band_ind=11                           
      LTE_BandNone_MIPI_TX_EVENT,    // Band_ind=12                           
      LTE_BandNone_MIPI_TX_EVENT,    // Band_ind=13                           
};

kal_uint32  LTE_MIPI_TX_DATA_SIZE_TABLE_Set0[] =
{
      sizeof(LTE_BandNone_MIPI_TX_DATA), // LTE_BandNone, !!!DON'T MODIFY!!! 
      sizeof(LTE_Band1_MIPI_TX_DATA),    // Band_ind=0                       
      sizeof(LTE_Band3_MIPI_TX_DATA),    // Band_ind=1                       
      sizeof(LTE_Band7_MIPI_TX_DATA),    // Band_ind=2                       
      sizeof(LTE_Band17_MIPI_TX_DATA),    // Band_ind=3                       
      sizeof(LTE_Band38_MIPI_TX_DATA),    // Band_ind=4                       
      sizeof(LTE_Band39_MIPI_TX_DATA),   // Band_ind=5                       
      sizeof(LTE_Band40_MIPI_TX_DATA),   // Band_ind=6                       
      sizeof(LTE_Band41_MIPI_TX_DATA),   // Band_ind=7                       
      sizeof(LTE_Band8_MIPI_TX_DATA),   // Band_ind=8                       
      sizeof(LTE_Band5_MIPI_TX_DATA),   // Band_ind=9                       
      sizeof(LTE_BandNone_MIPI_TX_DATA), // Band_ind=10                      
      sizeof(LTE_BandNone_MIPI_TX_DATA), // Band_ind=11                      
      sizeof(LTE_BandNone_MIPI_TX_DATA), // Band_ind=12                      
      sizeof(LTE_BandNone_MIPI_TX_DATA), // Band_ind=13                      
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_TX_DATA_TABLE_Set0[] =
{
      LTE_BandNone_MIPI_TX_DATA,     // LTE_BandNone, !!!DON'T MODIFY!!!   
      LTE_Band1_MIPI_TX_DATA,        // Band_ind=0                         
      LTE_Band3_MIPI_TX_DATA,        // Band_ind=1                         
      LTE_Band7_MIPI_TX_DATA,        // Band_ind=2                         
      LTE_Band17_MIPI_TX_DATA,        // Band_ind=3                         
      LTE_Band38_MIPI_TX_DATA,        // Band_ind=4                         
      LTE_Band39_MIPI_TX_DATA,       // Band_ind=5                         
      LTE_Band40_MIPI_TX_DATA,       // Band_ind=6                         
      LTE_Band41_MIPI_TX_DATA,       // Band_ind=7                         
      LTE_Band8_MIPI_TX_DATA,       // Band_ind=8                         
      LTE_Band5_MIPI_TX_DATA,       // Band_ind=9                         
      LTE_BandNone_MIPI_TX_DATA,     // Band_ind=10                        
      LTE_BandNone_MIPI_TX_DATA,     // Band_ind=11                        
      LTE_BandNone_MIPI_TX_DATA,     // Band_ind=12                        
      LTE_BandNone_MIPI_TX_DATA,     // Band_ind=13                        
};

kal_uint32  LTE_MIPI_TPC_EVENT_SIZE_TABLE_Set0[] =
{
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // LTE_BandNone, !!!DON'T MODIFY!!!  
      sizeof(LTE_Band1_MIPI_TPC_EVENT),    // Band_ind=0                        
      sizeof(LTE_Band3_MIPI_TPC_EVENT),    // Band_ind=1                        
      sizeof(LTE_Band7_MIPI_TPC_EVENT),    // Band_ind=2                        
      sizeof(LTE_Band17_MIPI_TPC_EVENT),    // Band_ind=3                        
      sizeof(LTE_Band38_MIPI_TPC_EVENT),    // Band_ind=4                        
      sizeof(LTE_Band39_MIPI_TPC_EVENT),   // Band_ind=5                        
      sizeof(LTE_Band40_MIPI_TPC_EVENT),   // Band_ind=6                        
      sizeof(LTE_Band41_MIPI_TPC_EVENT),   // Band_ind=7                        
      sizeof(LTE_Band8_MIPI_TPC_EVENT),   // Band_ind=8                        
      sizeof(LTE_Band5_MIPI_TPC_EVENT),   // Band_ind=9                        
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // Band_ind=10                       
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // Band_ind=11                       
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // Band_ind=12                       
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // Band_ind=13                       
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_TPC_EVENT_TABLE_Set0[] =
{
      LTE_BandNone_MIPI_TPC_EVENT,   // LTE_BandNone, !!!DON'T MODIFY!!! 
      LTE_Band1_MIPI_TPC_EVENT,      // Band_ind=0                       
      LTE_Band3_MIPI_TPC_EVENT,      // Band_ind=1                       
      LTE_Band7_MIPI_TPC_EVENT,      // Band_ind=2                       
      LTE_Band17_MIPI_TPC_EVENT,      // Band_ind=3                       
      LTE_Band38_MIPI_TPC_EVENT,      // Band_ind=4                       
      LTE_Band39_MIPI_TPC_EVENT,     // Band_ind=5                       
      LTE_Band40_MIPI_TPC_EVENT,     // Band_ind=6                       
      LTE_Band41_MIPI_TPC_EVENT,     // Band_ind=7                       
      LTE_Band8_MIPI_TPC_EVENT,     // Band_ind=8                       
      LTE_Band5_MIPI_TPC_EVENT,     // Band_ind=9                       
      LTE_BandNone_MIPI_TPC_EVENT,   // Band_ind=10                      
      LTE_BandNone_MIPI_TPC_EVENT,   // Band_ind=11                      
      LTE_BandNone_MIPI_TPC_EVENT,   // Band_ind=12                      
      LTE_BandNone_MIPI_TPC_EVENT,   // Band_ind=13                      
};

LTE_MIPI_DATA_TABLE_T*  LTE_MIPI_TPC_DATA_TABLE_Set0[] =
{
      LTE_BandNone_MIPI_TPC_DATA,    // LTE_BandNone, !!!DON'T MODIFY!!!  
      LTE_Band1_MIPI_TPC_DATA,       // Band_ind=0                        
      LTE_Band3_MIPI_TPC_DATA,       // Band_ind=1                        
      LTE_Band7_MIPI_TPC_DATA,       // Band_ind=2                        
      LTE_Band17_MIPI_TPC_DATA,       // Band_ind=3                        
      LTE_Band38_MIPI_TPC_DATA,       // Band_ind=4                        
      LTE_Band39_MIPI_TPC_DATA,      // Band_ind=5                        
      LTE_Band40_MIPI_TPC_DATA,      // Band_ind=6                        
      LTE_Band41_MIPI_TPC_DATA,      // Band_ind=7                        
      LTE_Band8_MIPI_TPC_DATA,      // Band_ind=8                        
      LTE_Band5_MIPI_TPC_DATA,      // Band_ind=9                        
      LTE_BandNone_MIPI_TPC_DATA,    // Band_ind=10                       
      LTE_BandNone_MIPI_TPC_DATA,    // Band_ind=11                       
      LTE_BandNone_MIPI_TPC_DATA,    // Band_ind=12                       
      LTE_BandNone_MIPI_TPC_DATA,    // Band_ind=13                       
};

kal_uint32  LTE_MIPI_PA_TPC_SECTION_DATA_SIZE_Set0[] =
{
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // LTE_BandNone, !!!DON'T MODIFY!!!    
      sizeof(LTE_Band1_MIPI_PA_SECTION_DATA),     // Band_ind=0                          
      sizeof(LTE_Band3_MIPI_PA_SECTION_DATA),     // Band_ind=1                          
      sizeof(LTE_Band7_MIPI_PA_SECTION_DATA),     // Band_ind=2                          
      sizeof(LTE_Band17_MIPI_PA_SECTION_DATA),     // Band_ind=3                          
      sizeof(LTE_Band38_MIPI_PA_SECTION_DATA),     // Band_ind=4                          
      sizeof(LTE_Band39_MIPI_PA_SECTION_DATA),    // Band_ind=5                          
      sizeof(LTE_Band40_MIPI_PA_SECTION_DATA),    // Band_ind=6                          
      sizeof(LTE_Band41_MIPI_PA_SECTION_DATA),    // Band_ind=7                          
      sizeof(LTE_Band8_MIPI_PA_SECTION_DATA),    // Band_ind=8                          
      sizeof(LTE_Band5_MIPI_PA_SECTION_DATA),    // Band_ind=9                          
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // Band_ind=10                         
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // Band_ind=11                         
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // Band_ind=12                         
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // Band_ind=13                         
};

LTE_MIPI_TPC_SECTION_TABLE_T*  LTE_MIPI_PA_TPC_SECTION_DATA_Set0[] =
{
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // LTE_BandNone, !!!DON'T MODIFY!!!   
      LTE_Band1_MIPI_PA_SECTION_DATA,      // Band_ind=0                         
      LTE_Band3_MIPI_PA_SECTION_DATA,      // Band_ind=1                         
      LTE_Band7_MIPI_PA_SECTION_DATA,      // Band_ind=2                         
      LTE_Band17_MIPI_PA_SECTION_DATA,      // Band_ind=3                         
      LTE_Band38_MIPI_PA_SECTION_DATA,      // Band_ind=4                         
      LTE_Band39_MIPI_PA_SECTION_DATA,     // Band_ind=5                         
      LTE_Band40_MIPI_PA_SECTION_DATA,     // Band_ind=6                         
      LTE_Band41_MIPI_PA_SECTION_DATA,     // Band_ind=7                         
      LTE_Band8_MIPI_PA_SECTION_DATA,     // Band_ind=8                         
      LTE_Band5_MIPI_PA_SECTION_DATA,     // Band_ind=9                         
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // Band_ind=10                        
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // Band_ind=11                        
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // Band_ind=12                        
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // Band_ind=13                        
};

kal_uint32  LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE_Set0[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),      // !!!DON'T MODIFY!!! 
      sizeof(LTE_Band38_MIPI_BYPASS_TX_EVENT),   // Band_ind=0         
      sizeof(LTE_Band40_MIPI_BYPASS_TX_EVENT),   // Band_ind=1         
      sizeof(LTE_Band41_MIPI_BYPASS_TX_EVENT),      // Band_ind=2         
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),      // Band_ind=3         
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),      // Band_ind=4         
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_BYPASS_TX_EVENT_TABLE_Set0[] =
{
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,       // !!!DON'T MODIFY!!! 
      LTE_Band38_MIPI_BYPASS_TX_EVENT,    // Band_ind=0         
      LTE_Band40_MIPI_BYPASS_TX_EVENT,    // Band_ind=1         
      LTE_Band41_MIPI_BYPASS_TX_EVENT,       // Band_ind=2           
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,       // Band_ind=3         
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,       // Band_ind=4           
};

kal_uint32  LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE_Set0[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),      // !!!DON'T MODIFY!!!      
      sizeof(LTE_Band38_MIPI_BYPASS_TX_DATA),   // Band_ind=0              
      sizeof(LTE_Band40_MIPI_BYPASS_TX_DATA),   // Band_ind=1              
      sizeof(LTE_Band41_MIPI_BYPASS_TX_DATA),      // Band_ind=2              
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),      // Band_ind=3              
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),      // Band_ind=4              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_BYPASS_TX_DATA_TABLE_Set0[] =
{
      LTE_BandNone_MIPI_BYPASS_TX_DATA,        // !!!DON'T MODIFY!!!  
      LTE_Band38_MIPI_BYPASS_TX_DATA,     // Band_ind=0          
      LTE_Band40_MIPI_BYPASS_TX_DATA,     // Band_ind=1          
      LTE_Band41_MIPI_BYPASS_TX_DATA,        // Band_ind=2          
      LTE_BandNone_MIPI_BYPASS_TX_DATA,        // Band_ind=3          
      LTE_BandNone_MIPI_BYPASS_TX_DATA,        // Band_ind=4          
};

kal_uint32  LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE_Set0[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),    // !!!DON'T MODIFY!!!
      sizeof(LTE_Band38_MIPI_BYPASS_TPC_EVENT),    // Band_ind=0        
      sizeof(LTE_Band40_MIPI_BYPASS_TPC_EVENT),    // Band_ind=1        
      sizeof(LTE_Band41_MIPI_BYPASS_TPC_EVENT),    // Band_ind=2        
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),    // Band_ind=3        
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),    // Band_ind=4        
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_BYPASS_TPC_EVENT_TABLE_Set0[] =
{
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,   // !!!DON'T MODIFY!!!  
      LTE_Band38_MIPI_BYPASS_TPC_EVENT,   // Band_ind=0          
      LTE_Band40_MIPI_BYPASS_TPC_EVENT,   // Band_ind=1          
      LTE_Band41_MIPI_BYPASS_TPC_EVENT,   // Band_ind=2          
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,   // Band_ind=3          
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,   // Band_ind=4          
};

kal_uint32  LTE_MIPI_BYPASS_TPC_DATA_SIZE_TABLE_Set0[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_DATA),
      sizeof(LTE_Band38_MIPI_BYPASS_TPC_DATA  ),
      sizeof(LTE_Band40_MIPI_BYPASS_TPC_DATA  ),
      sizeof(LTE_Band41_MIPI_BYPASS_TPC_DATA  ),
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_DATA),
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_DATA),
};

LTE_MIPI_DATA_TABLE_T*  LTE_MIPI_BYPASS_TPC_DATA_TABLE_Set0[] =
{
     LTE_BandNone_MIPI_BYPASS_TPC_DATA,    // !!!DON'T MODIFY!!! 
     LTE_Band38_MIPI_BYPASS_TPC_DATA,    // Band_ind=0         
     LTE_Band40_MIPI_BYPASS_TPC_DATA,    // Band_ind=1         
     LTE_Band41_MIPI_BYPASS_TPC_DATA,    // Band_ind=2         
     LTE_BandNone_MIPI_BYPASS_TPC_DATA,    // Band_ind=3         
     LTE_BandNone_MIPI_BYPASS_TPC_DATA,    // Band_ind=4         
};

kal_uint32  LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE_Set0[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),    // !!!DON'T MODIFY!!! 
      sizeof(LTE_Band38_MIPI_BYPASS_PA_SECTION_DATA),    // Band_ind=0         
      sizeof(LTE_Band40_MIPI_BYPASS_PA_SECTION_DATA),    // Band_ind=1         
      sizeof(LTE_Band41_MIPI_BYPASS_PA_SECTION_DATA),    // Band_ind=2         
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),    // Band_ind=3         
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),    // Band_ind=4         
};

LTE_MIPI_TPC_SECTION_TABLE_T*  LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_Set0[] =
{
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // !!!DON'T MODIFY!!! 
      LTE_Band38_MIPI_BYPASS_PA_SECTION_DATA,   // Band_ind=0         
      LTE_Band40_MIPI_BYPASS_PA_SECTION_DATA,   // Band_ind=1         
      LTE_Band41_MIPI_BYPASS_PA_SECTION_DATA,   // Band_ind=2         
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // Band_ind=3         
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // Band_ind=4         
};

LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_INITIAL_CW_Set1[] =
{
   // elm type   , port_sel      , data_seq ,    USID          , addr , data  , wait_time(us)
   {LTE_MIPI_ASM , LTE_MIPI_PORT0, LTE_REG_W, MIPI_USID_INIT0  , {0x1C, 0x38} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = normal mode
   {LTE_MIPI_ASM , LTE_MIPI_PORT1, LTE_REG_W, MIPI_USID_INIT0  , {0x1C, 0x38} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = normal mode
   {LTE_MIPI_END_PATTERN,0,0,0,{0,0},0},
};

LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_SLEEP_CW_Set1[] =
{
   // elm type   , port_sel      , data_seq ,    USID          , addr , data  , wait_time(us)
   {LTE_MIPI_ASM , LTE_MIPI_PORT0, LTE_REG_W, MIPI_USID_INIT0  , {0x1C, 0xB8} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = low power mode
   {LTE_MIPI_ASM , LTE_MIPI_PORT1, LTE_REG_W, MIPI_USID_INIT0  , {0x1C, 0xB8} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = low power mode
   {LTE_MIPI_END_PATTERN,0,0,0,{0,0},0},
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band1_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band3_MIPI_RX_EVENT_Set1[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band28_MIPI_RX_EVENT_Set1[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band7_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band8_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band17_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                     ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band39_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_RX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};
kal_uint32 LTE_MIPI_RX_EVENT_SIZE_TABLE_Set1[] =
{
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // LTE_BandNone, !!!DON'T MODIFY!!!
      sizeof(LTE_Band1_MIPI_RX_EVENT_Set1),    // Band_ind=0                      
      sizeof(LTE_Band3_MIPI_RX_EVENT_Set1),    // Band_ind=1                      
      sizeof(LTE_Band7_MIPI_RX_EVENT_Set1),    // Band_ind=2                      
      sizeof(LTE_Band17_MIPI_RX_EVENT_Set1),    // Band_ind=3                      
      sizeof(LTE_Band38_MIPI_RX_EVENT_Set1),    // Band_ind=4                      
      sizeof(LTE_Band39_MIPI_RX_EVENT_Set1),   // Band_ind=5                      
      sizeof(LTE_Band40_MIPI_RX_EVENT_Set1),   // Band_ind=6                      
      sizeof(LTE_Band41_MIPI_RX_EVENT_Set1),   // Band_ind=7                      
      sizeof(LTE_Band8_MIPI_RX_EVENT_Set1),   // Band_ind=8                      
      sizeof(LTE_Band28_MIPI_RX_EVENT_Set1),   // Band_ind=9                      
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // Band_ind=10                     
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // Band_ind=11                     
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // Band_ind=12                     
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // Band_ind=13                     
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_RX_EVENT_TABLE_Set1[] =
{
      LTE_BandNone_MIPI_RX_EVENT,    // LTE_BandNone, !!!DON'T MODIFY!!!
      LTE_Band1_MIPI_RX_EVENT_Set1,       // Band_ind=0                      
      LTE_Band3_MIPI_RX_EVENT_Set1,       // Band_ind=1                      
      LTE_Band7_MIPI_RX_EVENT_Set1,       // Band_ind=2                      
      LTE_Band17_MIPI_RX_EVENT_Set1,       // Band_ind=3                      
      LTE_Band38_MIPI_RX_EVENT_Set1,       // Band_ind=4                      
      LTE_Band39_MIPI_RX_EVENT_Set1,      // Band_ind=5                      
      LTE_Band40_MIPI_RX_EVENT_Set1,      // Band_ind=6                      
      LTE_Band41_MIPI_RX_EVENT_Set1,      // Band_ind=7                      
      LTE_Band8_MIPI_RX_EVENT_Set1,      // Band_ind=8                      
      LTE_Band28_MIPI_RX_EVENT_Set1,      // Band_ind=9                      
      LTE_BandNone_MIPI_RX_EVENT,    // Band_ind=10                     
      LTE_BandNone_MIPI_RX_EVENT,    // Band_ind=11                     
      LTE_BandNone_MIPI_RX_EVENT,    // Band_ind=12                     
      LTE_BandNone_MIPI_RX_EVENT,    // Band_ind=13                     
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band1_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 21100 /*100 kHz*/    ,0x1C , 0x38}, { 21250 /*100 kHz*/    ,0x1C , 0x38}, { 21400 /*100 kHz*/    ,0x1C , 0x38}, { 21550 /*100 kHz*/    ,0x1C , 0x38}, { 21700 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 21100 /*100 kHz*/    ,0x00 , 0x0C}, { 21250 /*100 kHz*/    ,0x00 , 0x0C}, { 21400 /*100 kHz*/    ,0x00 , 0x0C}, { 21550 /*100 kHz*/    ,0x00 , 0x0C}, { 21700 /*100 kHz*/    ,0x00 , 0x0C},} }, 
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 21100 /*100 kHz*/    ,0x00 , 0x00}, { 21250 /*100 kHz*/    ,0x00 , 0x00}, { 21400 /*100 kHz*/    ,0x00 , 0x00}, { 21550 /*100 kHz*/    ,0x00 , 0x00}, { 21700 /*100 kHz*/    ,0x00 , 0x00},} }, 
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 21100 /*100 kHz*/    ,0x1C , 0xB8}, { 21250 /*100 kHz*/    ,0x1C , 0xB8}, { 21400 /*100 kHz*/    ,0x1C , 0xB8}, { 21550 /*100 kHz*/    ,0x1C , 0xB8}, { 21700 /*100 kHz*/    ,0x1C , 0xB8},} }, 
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, 
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band3_MIPI_RX_DATA_Set1[] = 
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18050 /*100 kHz*/    ,0x1C , 0x38}, { 18238 /*100 kHz*/    ,0x1C , 0x38}, { 18425 /*100 kHz*/    ,0x1C , 0x38}, { 18612 /*100 kHz*/    ,0x1C , 0x38}, { 18800 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18050 /*100 kHz*/    ,0x00 , 0x02}, { 18238 /*100 kHz*/    ,0x00 , 0x02}, { 18425 /*100 kHz*/    ,0x00 , 0x02}, { 18612 /*100 kHz*/    ,0x00 , 0x02}, { 18800 /*100 kHz*/    ,0x00 , 0x02},} }, 
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18050 /*100 kHz*/    ,0x00 , 0x00}, { 18238 /*100 kHz*/    ,0x00 , 0x00}, { 18425 /*100 kHz*/    ,0x00 , 0x00}, { 18612 /*100 kHz*/    ,0x00 , 0x00}, { 18800 /*100 kHz*/    ,0x00 , 0x00},} }, 
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18050 /*100 kHz*/    ,0x1C , 0xB8}, { 18238 /*100 kHz*/    ,0x1C , 0xB8}, { 18425 /*100 kHz*/    ,0x1C , 0xB8}, { 18612 /*100 kHz*/    ,0x1C , 0xB8}, { 18800 /*100 kHz*/    ,0x1C , 0xB8},} }, 
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, 
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band28_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7580 /*100 kHz*/    ,0x1C , 0x38}, { 7700 /*100 kHz*/    ,0x1C , 0x38}, { 7805 /*100 kHz*/    ,0x1C , 0x38}, { 7920 /*100 kHz*/    ,0x1C , 0x38}, { 8030 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7580 /*100 kHz*/    ,0x00 , 0x0B}, { 7700 /*100 kHz*/    ,0x00 , 0x0B}, { 7805 /*100 kHz*/    ,0x00 , 0x0B}, { 7920 /*100 kHz*/    ,0x00 , 0x0B}, { 8030 /*100 kHz*/    ,0x00 , 0x0B},} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7580 /*100 kHz*/    ,0x00 , 0x00}, { 7700 /*100 kHz*/    ,0x00 , 0x00}, { 7805 /*100 kHz*/    ,0x00 , 0x00}, { 7920 /*100 kHz*/    ,0x00 , 0x00}, { 8030 /*100 kHz*/    ,0x00 , 0x00},} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7580 /*100 kHz*/    ,0x1C , 0xB8}, { 7700 /*100 kHz*/    ,0x1C , 0xB8}, { 7805 /*100 kHz*/    ,0x1C , 0xB8}, { 7920 /*100 kHz*/    ,0x1C , 0xB8}, { 8030 /*100 kHz*/    ,0x1C , 0xB8},} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band8_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 9250 /*100 kHz*/    ,0x1C , 0x38}, { 9338 /*100 kHz*/    ,0x1C , 0x38}, { 9426 /*100 kHz*/    ,0x1C , 0x38}, { 9514 /*100 kHz*/    ,0x1C , 0x38}, { 9600 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 9250 /*100 kHz*/    ,0x00 , 0x03}, { 9338 /*100 kHz*/    ,0x00 , 0x03}, { 9426 /*100 kHz*/    ,0x00 , 0x03}, { 9514 /*100 kHz*/    ,0x00 , 0x03}, { 9600 /*100 kHz*/    ,0x00 , 0x03},} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 9250 /*100 kHz*/    ,0x00 , 0x00}, { 9338 /*100 kHz*/    ,0x00 , 0x00}, { 9426 /*100 kHz*/    ,0x00 , 0x00}, { 9514 /*100 kHz*/    ,0x00 , 0x00}, { 9600 /*100 kHz*/    ,0x00 , 0x00},} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 9250 /*100 kHz*/    ,0x1C , 0xB8}, { 9338 /*100 kHz*/    ,0x1C , 0xB8}, { 9426 /*100 kHz*/    ,0x1C , 0xB8}, { 9514 /*100 kHz*/    ,0x1C , 0xB8}, { 9600 /*100 kHz*/    ,0x1C , 0xB8},} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band7_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band17_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7340  /*100 kHz*/    ,0x1C , 0x38}, { 7370  /*100 kHz*/    ,0x1C , 0x38}, { 7400  /*100 kHz*/    ,0x1C , 0x38}, { 7430  /*100 kHz*/    ,0x1C , 0x38}, { 7460  /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7340  /*100 kHz*/    ,0x00 , 0x01}, { 7370  /*100 kHz*/    ,0x00 , 0x01}, { 7400  /*100 kHz*/    ,0x00 , 0x01}, { 7430  /*100 kHz*/    ,0x00 , 0x01}, { 7460  /*100 kHz*/    ,0x00 , 0x01},} }, 
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7340  /*100 kHz*/    ,0x00 , 0x00}, { 7370  /*100 kHz*/    ,0x00 , 0x00}, { 7400  /*100 kHz*/    ,0x00 , 0x00}, { 7430  /*100 kHz*/    ,0x00 , 0x00}, { 7460  /*100 kHz*/    ,0x00 , 0x00},} }, 
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7340  /*100 kHz*/    ,0x1C , 0xB8}, { 7370  /*100 kHz*/    ,0x1C , 0xB8}, { 7400  /*100 kHz*/    ,0x1C , 0xB8}, { 7430  /*100 kHz*/    ,0x1C , 0xB8}, { 7460  /*100 kHz*/    ,0x1C , 0xB8},} }, 
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, 
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band38_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band39_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x00 , 0x07}, { 18900 /*100 kHz*/    ,0x00 , 0x07}, { 19000 /*100 kHz*/    ,0x00 , 0x07}, { 19100 /*100 kHz*/    ,0x00 , 0x07}, { 19200 /*100 kHz*/    ,0x00 , 0x07},} }, 
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x00 , 0x00}, { 18900 /*100 kHz*/    ,0x00 , 0x00}, { 19000 /*100 kHz*/    ,0x00 , 0x00}, { 19100 /*100 kHz*/    ,0x00 , 0x00}, { 19200 /*100 kHz*/    ,0x00 , 0x00},} }, 
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x1C , 0xB8}, { 18900 /*100 kHz*/    ,0x1C , 0xB8}, { 19000 /*100 kHz*/    ,0x1C , 0xB8}, { 19100 /*100 kHz*/    ,0x1C , 0xB8}, { 19200 /*100 kHz*/    ,0x1C , 0xB8},} }, 
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, 
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band40_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band41_MIPI_RX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};
kal_uint32 LTE_MIPI_RX_DATA_SIZE_TABLE_Set1[] =
{
      sizeof(LTE_BandNone_MIPI_RX_DATA), // LTE_BandNone, !!!DON'T MODIFY!!!
      sizeof(LTE_Band1_MIPI_RX_DATA_Set1),    // Band_ind=0                      
      sizeof(LTE_Band3_MIPI_RX_DATA_Set1),    // Band_ind=1                      
      sizeof(LTE_Band7_MIPI_RX_DATA_Set1),    // Band_ind=2                      
      sizeof(LTE_Band17_MIPI_RX_DATA_Set1),    // Band_ind=3                      
      sizeof(LTE_Band38_MIPI_RX_DATA_Set1),    // Band_ind=4                      
      sizeof(LTE_Band39_MIPI_RX_DATA_Set1),   // Band_ind=5                      
      sizeof(LTE_Band40_MIPI_RX_DATA_Set1),   // Band_ind=6                      
      sizeof(LTE_Band41_MIPI_RX_DATA_Set1),   // Band_ind=7                      
      sizeof(LTE_Band8_MIPI_RX_DATA_Set1),   // Band_ind=8                      
      sizeof(LTE_Band28_MIPI_RX_DATA_Set1),   // Band_ind=9                      
      sizeof(LTE_BandNone_MIPI_RX_DATA), // Band_ind=10                     
      sizeof(LTE_BandNone_MIPI_RX_DATA), // Band_ind=11                     
      sizeof(LTE_BandNone_MIPI_RX_DATA), // Band_ind=12                     
      sizeof(LTE_BandNone_MIPI_RX_DATA), // Band_ind=13                     
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_RX_DATA_TABLE_Set1[] =
{
      LTE_BandNone_MIPI_RX_DATA,     // LTE_BandNone, !!!DON'T MODIFY!!!     
      LTE_Band1_MIPI_RX_DATA_Set1,        // Band_ind=0                           
      LTE_Band3_MIPI_RX_DATA_Set1,        // Band_ind=1                           
      LTE_Band7_MIPI_RX_DATA_Set1,        // Band_ind=2                           
      LTE_Band17_MIPI_RX_DATA_Set1,        // Band_ind=3                           
      LTE_Band38_MIPI_RX_DATA_Set1,        // Band_ind=4                           
      LTE_Band39_MIPI_RX_DATA_Set1,       // Band_ind=5                           
      LTE_Band40_MIPI_RX_DATA_Set1,       // Band_ind=6                           
      LTE_Band41_MIPI_RX_DATA_Set1,       // Band_ind=7                           
      LTE_Band8_MIPI_RX_DATA_Set1,       // Band_ind=8                           
      LTE_Band28_MIPI_RX_DATA_Set1,       // Band_ind=9                           
      LTE_BandNone_MIPI_RX_DATA,     // Band_ind=10                          
      LTE_BandNone_MIPI_RX_DATA,     // Band_ind=11                          
      LTE_BandNone_MIPI_RX_DATA,     // Band_ind=12                          
      LTE_BandNone_MIPI_RX_DATA,     // Band_ind=13                          
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band1_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band3_MIPI_TX_EVENT_Set1[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band28_MIPI_TX_EVENT_Set1[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band7_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON1 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band8_MIPI_TX_EVENT_Set1[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band17_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band39_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};
kal_uint32  LTE_MIPI_TX_EVENT_SIZE_TABLE_Set1[] =
{
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // LTE_BandNone, !!!DON'T MODIFY!!!      
      sizeof(LTE_Band1_MIPI_TX_EVENT_Set1),    // Band_ind=0                            
      sizeof(LTE_Band3_MIPI_TX_EVENT_Set1),    // Band_ind=1                            
      sizeof(LTE_Band7_MIPI_TX_EVENT_Set1),    // Band_ind=2                            
      sizeof(LTE_Band17_MIPI_TX_EVENT_Set1),    // Band_ind=3                            
      sizeof(LTE_Band38_MIPI_TX_EVENT_Set1),    // Band_ind=4                            
      sizeof(LTE_Band39_MIPI_TX_EVENT_Set1),   // Band_ind=5                            
      sizeof(LTE_Band40_MIPI_TX_EVENT_Set1),   // Band_ind=6                            
      sizeof(LTE_Band41_MIPI_TX_EVENT_Set1),   // Band_ind=7                            
      sizeof(LTE_Band8_MIPI_TX_EVENT_Set1),   // Band_ind=8                            
      sizeof(LTE_Band28_MIPI_TX_EVENT_Set1),   // Band_ind=9                            
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // Band_ind=10                           
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // Band_ind=11                           
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // Band_ind=12                           
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // Band_ind=13                           
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_TX_EVENT_TABLE_Set1[] =
{
      LTE_BandNone_MIPI_TX_EVENT,    // LTE_BandNone, !!!DON'T MODIFY!!! 
      LTE_Band1_MIPI_TX_EVENT_Set1,       // Band_ind=0                       
      LTE_Band3_MIPI_TX_EVENT_Set1,       // Band_ind=1                       
      LTE_Band7_MIPI_TX_EVENT_Set1,       // Band_ind=2                       
      LTE_Band17_MIPI_TX_EVENT_Set1,       // Band_ind=3                       
      LTE_Band38_MIPI_TX_EVENT_Set1,       // Band_ind=4                       
      LTE_Band39_MIPI_TX_EVENT_Set1,      // Band_ind=5                       
      LTE_Band40_MIPI_TX_EVENT_Set1,      // Band_ind=6                       
      LTE_Band41_MIPI_TX_EVENT_Set1,      // Band_ind=7                       
      LTE_Band8_MIPI_TX_EVENT_Set1,      // Band_ind=8                       
      LTE_Band28_MIPI_TX_EVENT_Set1,      // Band_ind=9                       
      LTE_BandNone_MIPI_TX_EVENT,    // Band_ind=10                      
      LTE_BandNone_MIPI_TX_EVENT,    // Band_ind=11                      
      LTE_BandNone_MIPI_TX_EVENT,    // Band_ind=12                      
      LTE_BandNone_MIPI_TX_EVENT,    // Band_ind=13                      
};                                                                       

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, // ASM PM_Trig: normal mode
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band1_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x00 , 0x00}, { 19350 /*100 kHz*/    ,0x00 , 0x00}, { 19500 /*100 kHz*/    ,0x00 , 0x00}, { 19650 /*100 kHz*/    ,0x00 , 0x00}, { 19800 /*100 kHz*/    ,0x00 , 0x00},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x01 , 0x1F}, { 19350 /*100 kHz*/    ,0x01 , 0x1F}, { 19500 /*100 kHz*/    ,0x01 , 0x1F}, { 19650 /*100 kHz*/    ,0x01 , 0x1F}, { 19800 /*100 kHz*/    ,0x01 , 0x1F},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x02 , 0x00}, { 19350 /*100 kHz*/    ,0x02 , 0x00}, { 19500 /*100 kHz*/    ,0x02 , 0x00}, { 19650 /*100 kHz*/    ,0x02 , 0x00}, { 19800 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x03 , 0x00}, { 19350 /*100 kHz*/    ,0x03 , 0x00}, { 19500 /*100 kHz*/    ,0x03 , 0x00}, { 19650 /*100 kHz*/    ,0x03 , 0x00}, { 19800 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x01 , 0x00}, { 19350 /*100 kHz*/    ,0x01 , 0x00}, { 19500 /*100 kHz*/    ,0x01 , 0x00}, { 19650 /*100 kHz*/    ,0x01 , 0x00}, { 19800 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable                
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode  
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 19200 /*100 kHz*/    ,0x00 , 0x0C}, { 19350 /*100 kHz*/    ,0x00 , 0x0C}, { 19500 /*100 kHz*/    ,0x00 , 0x0C}, { 19650 /*100 kHz*/    ,0x00 , 0x0C}, { 19800 /*100 kHz*/    ,0x00 , 0x0C},} },                              
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band3_MIPI_TX_DATA_Set1[] = 
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x00 , 0x08}, { 17287 /*100 kHz*/    ,0x00 , 0x08}, { 17475 /*100 kHz*/    ,0x00 , 0x08}, { 17662 /*100 kHz*/    ,0x00 , 0x08}, { 17850 /*100 kHz*/    ,0x00 , 0x08},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x01 , 0x1F}, { 17287 /*100 kHz*/    ,0x01 , 0x1F}, { 17475 /*100 kHz*/    ,0x01 , 0x1F}, { 17662 /*100 kHz*/    ,0x01 , 0x1F}, { 17850 /*100 kHz*/    ,0x01 , 0x1F},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x02 , 0x00}, { 17287 /*100 kHz*/    ,0x02 , 0x00}, { 17475 /*100 kHz*/    ,0x02 , 0x00}, { 17662 /*100 kHz*/    ,0x02 , 0x00}, { 17850 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x03 , 0x00}, { 17287 /*100 kHz*/    ,0x03 , 0x00}, { 17475 /*100 kHz*/    ,0x03 , 0x00}, { 17662 /*100 kHz*/    ,0x03 , 0x00}, { 17850 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x01 , 0x00}, { 17287 /*100 kHz*/    ,0x01 , 0x00}, { 17475 /*100 kHz*/    ,0x01 , 0x00}, { 17662 /*100 kHz*/    ,0x01 , 0x00}, { 17850 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable                
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode  
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 17100 /*100 kHz*/    ,0x00 , 0x02}, { 17287 /*100 kHz*/    ,0x00 , 0x02}, { 17475 /*100 kHz*/    ,0x00 , 0x02}, { 17662 /*100 kHz*/    ,0x00 , 0x02}, { 17850 /*100 kHz*/    ,0x00 , 0x02},} },                              
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band28_MIPI_TX_DATA_Set1[] =
{
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7030 /*100 kHz*/    ,0x1C , 0x38}, { 7143 /*100 kHz*/    ,0x1C , 0x38}, { 7255 /*100 kHz*/    ,0x1C , 0x38}, { 7370 /*100 kHz*/    ,0x1C , 0x38}, { 7480 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7030 /*100 kHz*/    ,0x00 , 0x04}, { 7143 /*100 kHz*/    ,0x00 , 0x04}, { 7255 /*100 kHz*/    ,0x00 , 0x04}, { 7370 /*100 kHz*/    ,0x00 , 0x04}, { 7480 /*100 kHz*/    ,0x00 , 0x04},} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7030 /*100 kHz*/    ,0x01 , 0x0F}, { 7143 /*100 kHz*/    ,0x01 , 0x0F}, { 7255 /*100 kHz*/    ,0x01 , 0x0F}, { 7370 /*100 kHz*/    ,0x01 , 0x0F}, { 7480 /*100 kHz*/    ,0x01 , 0x0F},} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7030 /*100 kHz*/    ,0x02 , 0x00}, { 7143 /*100 kHz*/    ,0x02 , 0x00}, { 7255 /*100 kHz*/    ,0x02 , 0x00}, { 7370 /*100 kHz*/    ,0x02 , 0x00}, { 7480 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7030 /*100 kHz*/    ,0x03 , 0x00}, { 7143 /*100 kHz*/    ,0x03 , 0x00}, { 7255 /*100 kHz*/    ,0x03 , 0x00}, { 7370 /*100 kHz*/    ,0x03 , 0x00}, { 7480 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7030 /*100 kHz*/    ,0x01 , 0x00}, { 7143 /*100 kHz*/    ,0x01 , 0x00}, { 7255 /*100 kHz*/    ,0x01 , 0x00}, { 7370 /*100 kHz*/    ,0x01 , 0x00}, { 7480 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7030 /*100 kHz*/    ,0x1C , 0x38}, { 7143 /*100 kHz*/    ,0x1C , 0x38}, { 7255 /*100 kHz*/    ,0x1C , 0x38}, { 7370 /*100 kHz*/    ,0x1C , 0x38}, { 7480 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7030 /*100 kHz*/    ,0x00 , 0x0B}, { 7143 /*100 kHz*/    ,0x00 , 0x0B}, { 7255 /*100 kHz*/    ,0x00 , 0x0B}, { 7370 /*100 kHz*/    ,0x00 , 0x0B}, { 7480 /*100 kHz*/    ,0x00 , 0x0B},} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band7_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25000 /*100 kHz*/    ,0x1C , 0x38}, { 25175 /*100 kHz*/    ,0x1C , 0x38}, { 25350 /*100 kHz*/    ,0x1C , 0x38}, { 25525 /*100 kHz*/    ,0x1C , 0x38}, { 25700 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25000 /*100 kHz*/    ,0x00 , 0x0D}, { 25175 /*100 kHz*/    ,0x00 , 0x0D}, { 25350 /*100 kHz*/    ,0x00 , 0x0D}, { 25525 /*100 kHz*/    ,0x00 , 0x0D}, { 25700 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25000 /*100 kHz*/    ,0x01 , 0x00}, { 25175 /*100 kHz*/    ,0x01 , 0x00}, { 25350 /*100 kHz*/    ,0x01 , 0x00}, { 25525 /*100 kHz*/    ,0x01 , 0x00}, { 25700 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25000 /*100 kHz*/    ,0x00 , 0x00}, { 25175 /*100 kHz*/    ,0x00 , 0x00}, { 25350 /*100 kHz*/    ,0x00 , 0x00}, { 25525 /*100 kHz*/    ,0x00 , 0x00}, { 25700 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band8_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x1C , 0x38}, { 8888 /*100 kHz*/    ,0x1C , 0x38}, { 8976 /*100 kHz*/    ,0x1C , 0x38}, { 9064 /*100 kHz*/    ,0x1C , 0x38}, { 9150 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x00 , 0x00}, { 8888 /*100 kHz*/    ,0x00 , 0x00}, { 8976 /*100 kHz*/    ,0x00 , 0x00}, { 9064 /*100 kHz*/    ,0x00 , 0x00}, { 9150 /*100 kHz*/    ,0x00 , 0x00},} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x01 , 0x0F}, { 8888 /*100 kHz*/    ,0x01 , 0x0F}, { 8976 /*100 kHz*/    ,0x01 , 0x0F}, { 9064 /*100 kHz*/    ,0x01 , 0x0F}, { 9150 /*100 kHz*/    ,0x01 , 0x0F},} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x02 , 0x00}, { 8888 /*100 kHz*/    ,0x02 , 0x00}, { 8976 /*100 kHz*/    ,0x02 , 0x00}, { 9064 /*100 kHz*/    ,0x02 , 0x00}, { 9150 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x03 , 0x00}, { 8888 /*100 kHz*/    ,0x03 , 0x00}, { 8976 /*100 kHz*/    ,0x03 , 0x00}, { 9064 /*100 kHz*/    ,0x03 , 0x00}, { 9150 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x01 , 0x00}, { 8888 /*100 kHz*/    ,0x01 , 0x00}, { 8976 /*100 kHz*/    ,0x01 , 0x00}, { 9064 /*100 kHz*/    ,0x01 , 0x00}, { 9150 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 8800 /*100 kHz*/    ,0x1C , 0x38}, { 8888 /*100 kHz*/    ,0x1C , 0x38}, { 8976 /*100 kHz*/    ,0x1C , 0x38}, { 9064 /*100 kHz*/    ,0x1C , 0x38}, { 9150 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 8800 /*100 kHz*/    ,0x00 , 0x03}, { 8888 /*100 kHz*/    ,0x00 , 0x03}, { 8976 /*100 kHz*/    ,0x00 , 0x03}, { 9064 /*100 kHz*/    ,0x00 , 0x03}, { 9150 /*100 kHz*/    ,0x00 , 0x03},} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band17_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7040 /*100 kHz*/    ,0x1C , 0x38}, { 7070 /*100 kHz*/    ,0x1C , 0x38}, { 7100 /*100 kHz*/    ,0x1C , 0x38}, { 7130 /*100 kHz*/    ,0x1C , 0x38}, { 7160 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7040 /*100 kHz*/    ,0x00 , 0x0C}, { 7070 /*100 kHz*/    ,0x00 , 0x0C}, { 7100 /*100 kHz*/    ,0x00 , 0x0C}, { 7130 /*100 kHz*/    ,0x00 , 0x0C}, { 7160 /*100 kHz*/    ,0x00 , 0x0C},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7040 /*100 kHz*/    ,0x01 , 0x0F}, { 7070 /*100 kHz*/    ,0x01 , 0x0F}, { 7100 /*100 kHz*/    ,0x01 , 0x0F}, { 7130 /*100 kHz*/    ,0x01 , 0x0F}, { 7160 /*100 kHz*/    ,0x01 , 0x0F},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7040 /*100 kHz*/    ,0x02 , 0x00}, { 7070 /*100 kHz*/    ,0x02 , 0x00}, { 7100 /*100 kHz*/    ,0x02 , 0x00}, { 7130 /*100 kHz*/    ,0x02 , 0x00}, { 7160 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7040 /*100 kHz*/    ,0x03 , 0x00}, { 7070 /*100 kHz*/    ,0x03 , 0x00}, { 7100 /*100 kHz*/    ,0x03 , 0x00}, { 7130 /*100 kHz*/    ,0x03 , 0x00}, { 7160 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7040 /*100 kHz*/    ,0x01 , 0x00}, { 7070 /*100 kHz*/    ,0x01 , 0x00}, { 7100 /*100 kHz*/    ,0x01 , 0x00}, { 7130 /*100 kHz*/    ,0x01 , 0x00}, { 7160 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable                
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7040 /*100 kHz*/    ,0x1C , 0x38}, { 7070 /*100 kHz*/    ,0x1C , 0x38}, { 7100 /*100 kHz*/    ,0x1C , 0x38}, { 7130 /*100 kHz*/    ,0x1C , 0x38}, { 7160 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode  
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7040 /*100 kHz*/    ,0x00 , 0x01}, { 7070 /*100 kHz*/    ,0x00 , 0x01}, { 7100 /*100 kHz*/    ,0x00 , 0x01}, { 7130 /*100 kHz*/    ,0x00 , 0x01}, { 7160 /*100 kHz*/    ,0x00 , 0x01},} },                              
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band38_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x00 , 0x0D}, { 25825 /*100 kHz*/    ,0x00 , 0x0D}, { 25950 /*100 kHz*/    ,0x00 , 0x0D}, { 26075 /*100 kHz*/    ,0x00 , 0x0D}, { 26200 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x01 , 0x00}, { 25825 /*100 kHz*/    ,0x01 , 0x00}, { 25950 /*100 kHz*/    ,0x01 , 0x00}, { 26075 /*100 kHz*/    ,0x01 , 0x00}, { 26200 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x00 , 0x00}, { 25825 /*100 kHz*/    ,0x00 , 0x00}, { 25950 /*100 kHz*/    ,0x00 , 0x00}, { 26075 /*100 kHz*/    ,0x00 , 0x00}, { 26200 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band39_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x00 , 0x0C}, { 18900 /*100 kHz*/    ,0x00 , 0x0C}, { 19000 /*100 kHz*/    ,0x00 , 0x0C}, { 19100 /*100 kHz*/    ,0x00 , 0x0C}, { 19200 /*100 kHz*/    ,0x00 , 0x0C},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x01 , 0x1F}, { 18900 /*100 kHz*/    ,0x01 , 0x1F}, { 19000 /*100 kHz*/    ,0x01 , 0x1F}, { 19100 /*100 kHz*/    ,0x01 , 0x1F}, { 19200 /*100 kHz*/    ,0x01 , 0x1F},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x02 , 0x00}, { 18900 /*100 kHz*/    ,0x02 , 0x00}, { 19000 /*100 kHz*/    ,0x02 , 0x00}, { 19100 /*100 kHz*/    ,0x02 , 0x00}, { 19200 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x03 , 0x00}, { 18900 /*100 kHz*/    ,0x03 , 0x00}, { 19000 /*100 kHz*/    ,0x03 , 0x00}, { 19100 /*100 kHz*/    ,0x03 , 0x00}, { 19200 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x01 , 0x00}, { 18900 /*100 kHz*/    ,0x01 , 0x00}, { 19000 /*100 kHz*/    ,0x01 , 0x00}, { 19100 /*100 kHz*/    ,0x01 , 0x00}, { 19200 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable                
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode  
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x00 , 0x05}, { 18900 /*100 kHz*/    ,0x00 , 0x05}, { 19000 /*100 kHz*/    ,0x00 , 0x05}, { 19100 /*100 kHz*/    ,0x00 , 0x05}, { 19200 /*100 kHz*/    ,0x00 , 0x05},} },                              
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band40_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x00 , 0x0D}, { 23250 /*100 kHz*/    ,0x00 , 0x0D}, { 23500 /*100 kHz*/    ,0x00 , 0x0D}, { 23750 /*100 kHz*/    ,0x00 , 0x0D}, { 24000 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x01 , 0x00}, { 23250 /*100 kHz*/    ,0x01 , 0x00}, { 23500 /*100 kHz*/    ,0x01 , 0x00}, { 23750 /*100 kHz*/    ,0x01 , 0x00}, { 24000 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x00 , 0x00}, { 23250 /*100 kHz*/    ,0x00 , 0x00}, { 23500 /*100 kHz*/    ,0x00 , 0x00}, { 23750 /*100 kHz*/    ,0x00 , 0x00}, { 24000 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band41_MIPI_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x00 , 0x0D}, { 25445 /*100 kHz*/    ,0x00 , 0x0D}, { 25930 /*100 kHz*/    ,0x00 , 0x0D}, { 26415 /*100 kHz*/    ,0x00 , 0x0D}, { 26900 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x01 , 0x00}, { 25445 /*100 kHz*/    ,0x01 , 0x00}, { 25930 /*100 kHz*/    ,0x01 , 0x00}, { 26415 /*100 kHz*/    ,0x01 , 0x00}, { 26900 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x00 , 0x00}, { 25445 /*100 kHz*/    ,0x00 , 0x00}, { 25930 /*100 kHz*/    ,0x00 , 0x00}, { 26415 /*100 kHz*/    ,0x00 , 0x00}, { 26900 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};
kal_uint32  LTE_MIPI_TX_DATA_SIZE_TABLE_Set1[] =
{
      sizeof(LTE_BandNone_MIPI_TX_DATA), // LTE_BandNone, !!!DON'T MODIFY!!! 
      sizeof(LTE_Band1_MIPI_TX_DATA_Set1),    // Band_ind=0                       
      sizeof(LTE_Band3_MIPI_TX_DATA_Set1),    // Band_ind=1                       
      sizeof(LTE_Band7_MIPI_TX_DATA_Set1),    // Band_ind=2                       
      sizeof(LTE_Band17_MIPI_TX_DATA_Set1),    // Band_ind=3                       
      sizeof(LTE_Band38_MIPI_TX_DATA_Set1),    // Band_ind=4                       
      sizeof(LTE_Band39_MIPI_TX_DATA_Set1),   // Band_ind=5                       
      sizeof(LTE_Band40_MIPI_TX_DATA_Set1),   // Band_ind=6                       
      sizeof(LTE_Band41_MIPI_TX_DATA_Set1),   // Band_ind=7                       
      sizeof(LTE_Band8_MIPI_TX_DATA_Set1),   // Band_ind=8                       
      sizeof(LTE_Band28_MIPI_TX_DATA_Set1),   // Band_ind=9                       
      sizeof(LTE_BandNone_MIPI_TX_DATA), // Band_ind=10                      
      sizeof(LTE_BandNone_MIPI_TX_DATA), // Band_ind=11                      
      sizeof(LTE_BandNone_MIPI_TX_DATA), // Band_ind=12                      
      sizeof(LTE_BandNone_MIPI_TX_DATA), // Band_ind=13                      
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_TX_DATA_TABLE_Set1[] =
{
      LTE_BandNone_MIPI_TX_DATA,     // LTE_BandNone, !!!DON'T MODIFY!!!    
      LTE_Band1_MIPI_TX_DATA_Set1,        // Band_ind=0                          
      LTE_Band3_MIPI_TX_DATA_Set1,        // Band_ind=1                          
      LTE_Band7_MIPI_TX_DATA_Set1,        // Band_ind=2                          
      LTE_Band17_MIPI_TX_DATA_Set1,        // Band_ind=3                          
      LTE_Band38_MIPI_TX_DATA_Set1,        // Band_ind=4                          
      LTE_Band39_MIPI_TX_DATA_Set1,       // Band_ind=5                          
      LTE_Band40_MIPI_TX_DATA_Set1,       // Band_ind=6                          
      LTE_Band41_MIPI_TX_DATA_Set1,       // Band_ind=7                          
      LTE_Band8_MIPI_TX_DATA_Set1,       // Band_ind=8                          
      LTE_Band28_MIPI_TX_DATA_Set1,       // Band_ind=9                          
      LTE_BandNone_MIPI_TX_DATA,     // Band_ind=10                         
      LTE_BandNone_MIPI_TX_DATA,     // Band_ind=11                         
      LTE_BandNone_MIPI_TX_DATA,     // Band_ind=12                         
      LTE_BandNone_MIPI_TX_DATA,     // Band_ind=13                         
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band1_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band3_MIPI_TPC_EVENT_Set1[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band28_MIPI_TPC_EVENT_Set1[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band7_MIPI_TPC_EVENT_Set1[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band8_MIPI_TPC_EVENT_Set1[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};


LTE_MIPI_EVENT_TABLE_T LTE_Band17_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band39_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};
kal_uint32  LTE_MIPI_TPC_EVENT_SIZE_TABLE_Set1[] =
{
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // LTE_BandNone, !!!DON'T MODIFY!!!             
      sizeof(LTE_Band1_MIPI_TPC_EVENT_Set1),    // Band_ind=0                                   
      sizeof(LTE_Band3_MIPI_TPC_EVENT_Set1),    // Band_ind=1                                   
      sizeof(LTE_Band7_MIPI_TPC_EVENT_Set1),    // Band_ind=2                                   
      sizeof(LTE_Band17_MIPI_TPC_EVENT_Set1),    // Band_ind=3                                   
      sizeof(LTE_Band38_MIPI_TPC_EVENT_Set1),    // Band_ind=4                                   
      sizeof(LTE_Band39_MIPI_TPC_EVENT_Set1),   // Band_ind=5                                   
      sizeof(LTE_Band40_MIPI_TPC_EVENT_Set1),   // Band_ind=6                                   
      sizeof(LTE_Band41_MIPI_TPC_EVENT_Set1),   // Band_ind=7                                   
      sizeof(LTE_Band8_MIPI_TPC_EVENT_Set1),   // Band_ind=8                                   
      sizeof(LTE_Band28_MIPI_TPC_EVENT_Set1),   // Band_ind=9                                   
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // Band_ind=10                                  
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // Band_ind=11                                  
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // Band_ind=12                                  
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // Band_ind=13                                  
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_TPC_EVENT_TABLE_Set1[] =
{
      LTE_BandNone_MIPI_TPC_EVENT,   // LTE_BandNone, !!!DON'T MODIFY!!!       
      LTE_Band1_MIPI_TPC_EVENT_Set1,      // Band_ind=0                             
      LTE_Band3_MIPI_TPC_EVENT_Set1,      // Band_ind=1                             
      LTE_Band7_MIPI_TPC_EVENT_Set1,      // Band_ind=2                             
      LTE_Band17_MIPI_TPC_EVENT_Set1,      // Band_ind=3                             
      LTE_Band38_MIPI_TPC_EVENT_Set1,      // Band_ind=4                             
      LTE_Band39_MIPI_TPC_EVENT_Set1,     // Band_ind=5                             
      LTE_Band40_MIPI_TPC_EVENT_Set1,     // Band_ind=6                             
      LTE_Band41_MIPI_TPC_EVENT_Set1,     // Band_ind=7                             
      LTE_Band8_MIPI_TPC_EVENT_Set1,     // Band_ind=8                             
      LTE_Band28_MIPI_TPC_EVENT_Set1,     // Band_ind=9                             
      LTE_BandNone_MIPI_TPC_EVENT,   // Band_ind=10                            
      LTE_BandNone_MIPI_TPC_EVENT,   // Band_ind=11                            
      LTE_BandNone_MIPI_TPC_EVENT,   // Band_ind=12                            
      LTE_BandNone_MIPI_TPC_EVENT,   // Band_ind=13                            
};

LTE_MIPI_DATA_TABLE_T LTE_BandNone_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band1_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band3_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band28_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band7_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band8_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band17_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band38_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band39_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band40_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band41_MIPI_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T*  LTE_MIPI_TPC_DATA_TABLE_Set1[] =
{
      LTE_BandNone_MIPI_TPC_DATA,    // LTE_BandNone, !!!DON'T MODIFY!!!
      LTE_Band1_MIPI_TPC_DATA_Set1,       // Band_ind=0                      
      LTE_Band3_MIPI_TPC_DATA_Set1,       // Band_ind=1                      
      LTE_Band7_MIPI_TPC_DATA_Set1,       // Band_ind=2                      
      LTE_Band17_MIPI_TPC_DATA_Set1,       // Band_ind=3                     
      LTE_Band38_MIPI_TPC_DATA_Set1,       // Band_ind=4                     
      LTE_Band39_MIPI_TPC_DATA_Set1,      // Band_ind=5                      
      LTE_Band40_MIPI_TPC_DATA_Set1,      // Band_ind=6                      
      LTE_Band41_MIPI_TPC_DATA_Set1,      // Band_ind=7                      
      LTE_Band8_MIPI_TPC_DATA_Set1,      // Band_ind=8                       
      LTE_Band28_MIPI_TPC_DATA_Set1,      // Band_ind=9                      
      LTE_BandNone_MIPI_TPC_DATA,    // Band_ind=10                     
      LTE_BandNone_MIPI_TPC_DATA,    // Band_ind=11                     
      LTE_BandNone_MIPI_TPC_DATA,    // Band_ind=12                     
      LTE_BandNone_MIPI_TPC_DATA,    // Band_ind=13                     
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_BandNone_MIPI_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band1_MIPI_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      19200,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      19350,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      19500,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
     }
   },

      /*8804 KHz*/
   {
      19650,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      19800,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band3_MIPI_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      17100,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      17287,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      17475,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      17662,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      17850,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band28_MIPI_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      7030,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      7143,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      7255,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      7370,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      7480,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band7_MIPI_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      25000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25175,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25350,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      25525,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      25700,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band8_MIPI_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      8800,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      8888,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      8976,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      9064,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      9150,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band17_MIPI_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      7040,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      7070,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      7100,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      7130,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      7160,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band38_MIPI_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      25700,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25825,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25950,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      26075,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      26200,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};
LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band39_MIPI_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*18800 KHz*/
   {
      18800,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
      
      /*18900 KHz*/
   {
      18900,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   }, 
      
      /*19000 KHz*/
   {
      19000,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
      
      /*19100 KHz*/
   {
      19100,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
      
      /*19200 KHz*/
   {
      19200,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};
LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band40_MIPI_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      23000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      23250,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      23500,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      23750,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      24000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band41_MIPI_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      24960,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25445,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25930,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      26415,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      26900,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};
kal_uint32  LTE_MIPI_PA_TPC_SECTION_DATA_SIZE_Set1[] =
{
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // LTE_BandNone, !!!DON'T MODIFY!!!     
      sizeof(LTE_Band1_MIPI_PA_SECTION_DATA_Set1),     // Band_ind=0                           
      sizeof(LTE_Band3_MIPI_PA_SECTION_DATA_Set1),     // Band_ind=1                           
      sizeof(LTE_Band7_MIPI_PA_SECTION_DATA_Set1),     // Band_ind=2                           
      sizeof(LTE_Band17_MIPI_PA_SECTION_DATA_Set1),     // Band_ind=3                           
      sizeof(LTE_Band38_MIPI_PA_SECTION_DATA_Set1),     // Band_ind=4                           
      sizeof(LTE_Band39_MIPI_PA_SECTION_DATA_Set1),    // Band_ind=5                           
      sizeof(LTE_Band40_MIPI_PA_SECTION_DATA_Set1),    // Band_ind=6                           
      sizeof(LTE_Band41_MIPI_PA_SECTION_DATA_Set1),    // Band_ind=7                           
      sizeof(LTE_Band8_MIPI_PA_SECTION_DATA_Set1),    // Band_ind=8                           
      sizeof(LTE_Band28_MIPI_PA_SECTION_DATA_Set1),    // Band_ind=9                           
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // Band_ind=10                          
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // Band_ind=11                          
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // Band_ind=12                          
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // Band_ind=13                          
};

LTE_MIPI_TPC_SECTION_TABLE_T*  LTE_MIPI_PA_TPC_SECTION_DATA_Set1[] =
{
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // LTE_BandNone, !!!DON'T MODIFY!!!   
      LTE_Band1_MIPI_PA_SECTION_DATA_Set1,      // Band_ind=0                         
      LTE_Band3_MIPI_PA_SECTION_DATA_Set1,      // Band_ind=1                         
      LTE_Band7_MIPI_PA_SECTION_DATA_Set1,      // Band_ind=2                         
      LTE_Band17_MIPI_PA_SECTION_DATA_Set1,      // Band_ind=3                         
      LTE_Band38_MIPI_PA_SECTION_DATA_Set1,      // Band_ind=4                         
      LTE_Band39_MIPI_PA_SECTION_DATA_Set1,     // Band_ind=5                         
      LTE_Band40_MIPI_PA_SECTION_DATA_Set1,     // Band_ind=6                         
      LTE_Band41_MIPI_PA_SECTION_DATA_Set1,     // Band_ind=7                         
      LTE_Band8_MIPI_PA_SECTION_DATA_Set1,     // Band_ind=8                         
      LTE_Band28_MIPI_PA_SECTION_DATA_Set1,     // Band_ind=9                         
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // Band_ind=10                        
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // Band_ind=11                        
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // Band_ind=12                        
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // Band_ind=13                        
};

/*special handle for T/Rx calibration, we should force ASM to isolation mode */
/*Users just need to provide the ASM isolation CW, DSP may use immediate mode*/
/*to control the MIPI ASM                                                    */
LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_ASM_ISOLATION_DATA_Set1[] =
{
   //No.      elm type     , port_sel       , data_seq     ,       USID       , addr  , data , wait_time(us)
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1 , LTE_REG_W    , MIPI_USID_ASM0   , {0x0  , 0x7F} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = normal mode
   {LTE_MIPI_END_PATTERN,0,0,0,{0,0},0},
};

/*** MIPI BYPASS Feature ***/
LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_BYPASS_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_BYPASS_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_BYPASS_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_BYPASS_TX_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

kal_uint32  LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE_Set1[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),      // !!!DON'T MODIFY!!!  
      sizeof(LTE_Band38_MIPI_BYPASS_TX_EVENT_Set1),   // Band_ind=0          
      sizeof(LTE_Band40_MIPI_BYPASS_TX_EVENT_Set1),   // Band_ind=1          
      sizeof(LTE_Band41_MIPI_BYPASS_TX_EVENT_Set1),      // Band_ind=2          
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),      // Band_ind=3          
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),      // Band_ind=4          
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_BYPASS_TX_EVENT_TABLE_Set1[] =
{
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,       // !!!DON'T MODIFY!!!
      LTE_Band38_MIPI_BYPASS_TX_EVENT_Set1,    // Band_ind=0        
      LTE_Band40_MIPI_BYPASS_TX_EVENT_Set1,    // Band_ind=1        
      LTE_Band41_MIPI_BYPASS_TX_EVENT_Set1,       // Band_ind=2        
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,       // Band_ind=3        
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,       // Band_ind=4        
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_BYPASS_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, // ASM PM_Trig: normal mode
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band38_MIPI_BYPASS_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x00 , 0x0D}, { 25825 /*100 kHz*/    ,0x00 , 0x0D}, { 25950 /*100 kHz*/    ,0x00 , 0x0D}, { 26075 /*100 kHz*/    ,0x00 , 0x0D}, { 26200 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x01 , 0x00}, { 25825 /*100 kHz*/    ,0x01 , 0x00}, { 25950 /*100 kHz*/    ,0x01 , 0x00}, { 26075 /*100 kHz*/    ,0x01 , 0x00}, { 26200 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x00 , 0x00}, { 25825 /*100 kHz*/    ,0x00 , 0x00}, { 25950 /*100 kHz*/    ,0x00 , 0x00}, { 26075 /*100 kHz*/    ,0x00 , 0x00}, { 26200 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band40_MIPI_BYPASS_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x00 , 0x0D}, { 23250 /*100 kHz*/    ,0x00 , 0x0D}, { 23500 /*100 kHz*/    ,0x00 , 0x0D}, { 23750 /*100 kHz*/    ,0x00 , 0x0D}, { 24000 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x01 , 0x00}, { 23250 /*100 kHz*/    ,0x01 , 0x00}, { 23500 /*100 kHz*/    ,0x01 , 0x00}, { 23750 /*100 kHz*/    ,0x01 , 0x00}, { 24000 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x00 , 0x00}, { 23250 /*100 kHz*/    ,0x00 , 0x00}, { 23500 /*100 kHz*/    ,0x00 , 0x00}, { 23750 /*100 kHz*/    ,0x00 , 0x00}, { 24000 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band41_MIPI_BYPASS_TX_DATA_Set1[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x00 , 0x0D}, { 25445 /*100 kHz*/    ,0x00 , 0x0D}, { 25930 /*100 kHz*/    ,0x00 , 0x0D}, { 26415 /*100 kHz*/    ,0x00 , 0x0D}, { 26900 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x01 , 0x00}, { 25445 /*100 kHz*/    ,0x01 , 0x00}, { 25930 /*100 kHz*/    ,0x01 , 0x00}, { 26415 /*100 kHz*/    ,0x01 , 0x00}, { 26900 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x00 , 0x00}, { 25445 /*100 kHz*/    ,0x00 , 0x00}, { 25930 /*100 kHz*/    ,0x00 , 0x00}, { 26415 /*100 kHz*/    ,0x00 , 0x00}, { 26900 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

kal_uint32  LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE_Set1[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),      // !!!DON'T MODIFY!!!
      sizeof(LTE_Band38_MIPI_BYPASS_TX_DATA_Set1),   // Band_ind=0        
      sizeof(LTE_Band40_MIPI_BYPASS_TX_DATA_Set1),   // Band_ind=1        
      sizeof(LTE_Band41_MIPI_BYPASS_TX_DATA_Set1),      // Band_ind=2        
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),      // Band_ind=3        
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),      // Band_ind=4        
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_BYPASS_TX_DATA_TABLE_Set1[] =
{
      LTE_BandNone_MIPI_BYPASS_TX_DATA,        // !!!DON'T MODIFY!!! 
      LTE_Band38_MIPI_BYPASS_TX_DATA_Set1,     // Band_ind=0         
      LTE_Band40_MIPI_BYPASS_TX_DATA_Set1,     // Band_ind=1         
      LTE_Band41_MIPI_BYPASS_TX_DATA_Set1,        // Band_ind=2         
      LTE_BandNone_MIPI_BYPASS_TX_DATA,        // Band_ind=3         
      LTE_BandNone_MIPI_BYPASS_TX_DATA,        // Band_ind=4         
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_BYPASS_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_BYPASS_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_BYPASS_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_BYPASS_TPC_EVENT_Set1[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

kal_uint32  LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE_Set1[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),    // !!!DON'T MODIFY!!! 
      sizeof(LTE_Band38_MIPI_BYPASS_TPC_EVENT_Set1),    // Band_ind=0         
      sizeof(LTE_Band40_MIPI_BYPASS_TPC_EVENT_Set1),    // Band_ind=1         
      sizeof(LTE_Band41_MIPI_BYPASS_TPC_EVENT_Set1),    // Band_ind=2         
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),    // Band_ind=3         
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),    // Band_ind=4         
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_BYPASS_TPC_EVENT_TABLE_Set1[] =
{
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,   // !!!DON'T MODIFY!!! 
      LTE_Band38_MIPI_BYPASS_TPC_EVENT_Set1,   // Band_ind=0         
      LTE_Band40_MIPI_BYPASS_TPC_EVENT_Set1,   // Band_ind=1         
      LTE_Band41_MIPI_BYPASS_TPC_EVENT_Set1,   // Band_ind=2         
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,   // Band_ind=3         
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,   // Band_ind=4         
};

LTE_MIPI_DATA_TABLE_T LTE_BandNone_MIPI_BYPASS_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band38_MIPI_BYPASS_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band40_MIPI_BYPASS_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band41_MIPI_BYPASS_TPC_DATA_Set1[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T*  LTE_MIPI_BYPASS_TPC_DATA_TABLE_Set1[] =
{
      LTE_BandNone_MIPI_BYPASS_TPC_DATA,    // !!!DON'T MODIFY!!!  
      LTE_Band38_MIPI_BYPASS_TPC_DATA_Set1,    // Band_ind=0          
      LTE_Band40_MIPI_BYPASS_TPC_DATA_Set1,    // Band_ind=1          
      LTE_Band41_MIPI_BYPASS_TPC_DATA_Set1,    // Band_ind=2          
      LTE_BandNone_MIPI_BYPASS_TPC_DATA,    // Band_ind=3          
      LTE_BandNone_MIPI_BYPASS_TPC_DATA,    // Band_ind=4          
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band38_MIPI_BYPASS_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      25700,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25825,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25950,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      26075,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      26200,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band40_MIPI_BYPASS_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      23000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      23250,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      23500,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      23750,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      24000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band41_MIPI_BYPASS_PA_SECTION_DATA_Set1[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      24960,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25445,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25930,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      26415,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      26900,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

kal_uint32  LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE_Set1[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),    // !!!DON'T MODIFY!!!   
      sizeof(LTE_Band38_MIPI_BYPASS_PA_SECTION_DATA_Set1),    // Band_ind=0           
      sizeof(LTE_Band40_MIPI_BYPASS_PA_SECTION_DATA_Set1),    // Band_ind=1           
      sizeof(LTE_Band41_MIPI_BYPASS_PA_SECTION_DATA_Set1),    // Band_ind=2           
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),    // Band_ind=3           
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),    // Band_ind=4           
};

LTE_MIPI_TPC_SECTION_TABLE_T*  LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_Set1[] =
{
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // !!!DON'T MODIFY!!! 
      LTE_Band38_MIPI_BYPASS_PA_SECTION_DATA_Set1,   // Band_ind=0         
      LTE_Band40_MIPI_BYPASS_PA_SECTION_DATA_Set1,   // Band_ind=1         
      LTE_Band41_MIPI_BYPASS_PA_SECTION_DATA_Set1,   // Band_ind=2         
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // Band_ind=3         
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // Band_ind=4         
};


LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_INITIAL_CW_Set2[] =
{
   // elm type   , port_sel      , data_seq ,    USID          , addr , data  , wait_time(us)
   {LTE_MIPI_ASM , LTE_MIPI_PORT0, LTE_REG_W, MIPI_USID_INIT0  , {0x1C, 0x38} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = normal mode
   {LTE_MIPI_ASM , LTE_MIPI_PORT1, LTE_REG_W, MIPI_USID_INIT0  , {0x1C, 0x38} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = normal mode
   {LTE_MIPI_END_PATTERN,0,0,0,{0,0},0},
};

LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_SLEEP_CW_Set2[] =
{
   // elm type   , port_sel      , data_seq ,    USID          , addr , data  , wait_time(us)
   {LTE_MIPI_ASM , LTE_MIPI_PORT0, LTE_REG_W, MIPI_USID_INIT0  , {0x1C, 0xB8} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = low power mode
   {LTE_MIPI_ASM , LTE_MIPI_PORT1, LTE_REG_W, MIPI_USID_INIT0  , {0x1C, 0xB8} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = low power mode
   {LTE_MIPI_END_PATTERN,0,0,0,{0,0},0},
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_RX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band1_MIPI_RX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band3_MIPI_RX_EVENT_Set2[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band7_MIPI_RX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band8_MIPI_RX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band28_MIPI_RX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_RX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset    */
   /*                        { start, stop },                     ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band39_MIPI_RX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_ASM , { 0    , 1    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ASM_RX_ON0 },
   { /* 1  */ LTE_MIPI_ASM , { 2    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_ASM_RX_OFF0},
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_RX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_RX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};
kal_uint32 LTE_MIPI_RX_EVENT_SIZE_TABLE_Set2[] =
{
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // LTE_BandNone, !!!DON'T MODIFY!!!
      sizeof(LTE_Band1_MIPI_RX_EVENT_Set2),    // Band_ind=0                      
      sizeof(LTE_Band3_MIPI_RX_EVENT_Set2),    // Band_ind=1                      
      sizeof(LTE_Band7_MIPI_RX_EVENT_Set2),    // Band_ind=2                      
      sizeof(LTE_Band28_MIPI_RX_EVENT_Set2),    // Band_ind=3                      
      sizeof(LTE_Band38_MIPI_RX_EVENT_Set2),    // Band_ind=4                      
      sizeof(LTE_Band39_MIPI_RX_EVENT_Set2),   // Band_ind=5                      
      sizeof(LTE_Band40_MIPI_RX_EVENT_Set2),   // Band_ind=6                      
      sizeof(LTE_Band41_MIPI_RX_EVENT_Set2),   // Band_ind=7                      
      sizeof(LTE_Band8_MIPI_RX_EVENT_Set2),   // Band_ind=8                      
      sizeof(LTE_BandNone_MIPI_RX_EVENT),   // Band_ind=9                      
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // Band_ind=10                     
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // Band_ind=11                     
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // Band_ind=12                     
      sizeof(LTE_BandNone_MIPI_RX_EVENT), // Band_ind=13                     
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_RX_EVENT_TABLE_Set2[] =
{
      LTE_BandNone_MIPI_RX_EVENT,    // LTE_BandNone, !!!DON'T MODIFY!!!  
      LTE_Band1_MIPI_RX_EVENT_Set2,       // Band_ind=0                        
      LTE_Band3_MIPI_RX_EVENT_Set2,       // Band_ind=1                        
      LTE_Band7_MIPI_RX_EVENT_Set2,       // Band_ind=2                        
      LTE_Band28_MIPI_RX_EVENT_Set2,       // Band_ind=3                        
      LTE_Band38_MIPI_RX_EVENT_Set2,       // Band_ind=4                        
      LTE_Band39_MIPI_RX_EVENT_Set2,      // Band_ind=5                        
      LTE_Band40_MIPI_RX_EVENT_Set2,      // Band_ind=6                        
      LTE_Band41_MIPI_RX_EVENT_Set2,      // Band_ind=7                        
      LTE_Band8_MIPI_RX_EVENT_Set2,      // Band_ind=8                        
      LTE_BandNone_MIPI_RX_EVENT,      // Band_ind=9                        
      LTE_BandNone_MIPI_RX_EVENT,    // Band_ind=10                       
      LTE_BandNone_MIPI_RX_EVENT,    // Band_ind=11                       
      LTE_BandNone_MIPI_RX_EVENT,    // Band_ind=12                       
      LTE_BandNone_MIPI_RX_EVENT,    // Band_ind=13                       
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_RX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band1_MIPI_RX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 21100 /*100 kHz*/    ,0x1C , 0x38}, { 21250 /*100 kHz*/    ,0x1C , 0x38}, { 21400 /*100 kHz*/    ,0x1C , 0x38}, { 21550 /*100 kHz*/    ,0x1C , 0x38}, { 21700 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 21100 /*100 kHz*/    ,0x00 , 0x0C}, { 21250 /*100 kHz*/    ,0x00 , 0x0C}, { 21400 /*100 kHz*/    ,0x00 , 0x0C}, { 21550 /*100 kHz*/    ,0x00 , 0x0C}, { 21700 /*100 kHz*/    ,0x00 , 0x0C},} }, 
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 21100 /*100 kHz*/    ,0x00 , 0x00}, { 21250 /*100 kHz*/    ,0x00 , 0x00}, { 21400 /*100 kHz*/    ,0x00 , 0x00}, { 21550 /*100 kHz*/    ,0x00 , 0x00}, { 21700 /*100 kHz*/    ,0x00 , 0x00},} }, 
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 21100 /*100 kHz*/    ,0x1C , 0xB8}, { 21250 /*100 kHz*/    ,0x1C , 0xB8}, { 21400 /*100 kHz*/    ,0x1C , 0xB8}, { 21550 /*100 kHz*/    ,0x1C , 0xB8}, { 21700 /*100 kHz*/    ,0x1C , 0xB8},} }, 
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, 
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band3_MIPI_RX_DATA_Set2[] = 
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18050 /*100 kHz*/    ,0x1C , 0x38}, { 18238 /*100 kHz*/    ,0x1C , 0x38}, { 18425 /*100 kHz*/    ,0x1C , 0x38}, { 18612 /*100 kHz*/    ,0x1C , 0x38}, { 18800 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18050 /*100 kHz*/    ,0x00 , 0x02}, { 18238 /*100 kHz*/    ,0x00 , 0x02}, { 18425 /*100 kHz*/    ,0x00 , 0x02}, { 18612 /*100 kHz*/    ,0x00 , 0x02}, { 18800 /*100 kHz*/    ,0x00 , 0x02},} }, 
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18050 /*100 kHz*/    ,0x00 , 0x00}, { 18238 /*100 kHz*/    ,0x00 , 0x00}, { 18425 /*100 kHz*/    ,0x00 , 0x00}, { 18612 /*100 kHz*/    ,0x00 , 0x00}, { 18800 /*100 kHz*/    ,0x00 , 0x00},} }, 
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18050 /*100 kHz*/    ,0x1C , 0xB8}, { 18238 /*100 kHz*/    ,0x1C , 0xB8}, { 18425 /*100 kHz*/    ,0x1C , 0xB8}, { 18612 /*100 kHz*/    ,0x1C , 0xB8}, { 18800 /*100 kHz*/    ,0x1C , 0xB8},} }, 
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, 
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band8_MIPI_RX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 9250 /*100 kHz*/    ,0x1C , 0x38}, { 9338 /*100 kHz*/    ,0x1C , 0x38}, { 9426 /*100 kHz*/    ,0x1C , 0x38}, { 9514 /*100 kHz*/    ,0x1C , 0x38}, { 9600 /*100 kHz*/    ,0x1C , 0x38},} },
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 9250 /*100 kHz*/    ,0x00 , 0x03}, { 9338 /*100 kHz*/    ,0x00 , 0x03}, { 9426 /*100 kHz*/    ,0x00 , 0x03}, { 9514 /*100 kHz*/    ,0x00 , 0x03}, { 9600 /*100 kHz*/    ,0x00 , 0x03},} },
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 9250 /*100 kHz*/    ,0x00 , 0x00}, { 9338 /*100 kHz*/    ,0x00 , 0x00}, { 9426 /*100 kHz*/    ,0x00 , 0x00}, { 9514 /*100 kHz*/    ,0x00 , 0x00}, { 9600 /*100 kHz*/    ,0x00 , 0x00},} },
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 9250 /*100 kHz*/    ,0x1C , 0xB8}, { 9338 /*100 kHz*/    ,0x1C , 0xB8}, { 9426 /*100 kHz*/    ,0x1C , 0xB8}, { 9514 /*100 kHz*/    ,0x1C , 0xB8}, { 9600 /*100 kHz*/    ,0x1C , 0xB8},} },
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band7_MIPI_RX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band28_MIPI_RX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7580  /*100 kHz*/    ,0x1C , 0x38}, { 7700  /*100 kHz*/    ,0x1C , 0x38}, { 7805  /*100 kHz*/    ,0x1C , 0x38}, { 7920  /*100 kHz*/    ,0x1C , 0x38}, { 8030  /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7580  /*100 kHz*/    ,0x00 , 0x01}, { 7700  /*100 kHz*/    ,0x00 , 0x01}, { 7805  /*100 kHz*/    ,0x00 , 0x0B}, { 7920  /*100 kHz*/    ,0x00 , 0x0B}, { 8030  /*100 kHz*/    ,0x00 , 0x0B},} }, 
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7580  /*100 kHz*/    ,0x00 , 0x00}, { 7700  /*100 kHz*/    ,0x00 , 0x00}, { 7805  /*100 kHz*/    ,0x00 , 0x00}, { 7920  /*100 kHz*/    ,0x00 , 0x00}, { 8030  /*100 kHz*/    ,0x00 , 0x00},} }, 
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7580  /*100 kHz*/    ,0x1C , 0xB8}, { 7700  /*100 kHz*/    ,0x1C , 0xB8}, { 7805  /*100 kHz*/    ,0x1C , 0xB8}, { 7920  /*100 kHz*/    ,0x1C , 0xB8}, { 8030  /*100 kHz*/    ,0x1C , 0xB8},} }, 
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, 
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band38_MIPI_RX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band39_MIPI_RX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} }, 
   { /* 1  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x00 , 0x07}, { 18900 /*100 kHz*/    ,0x00 , 0x07}, { 19000 /*100 kHz*/    ,0x00 , 0x07}, { 19100 /*100 kHz*/    ,0x00 , 0x07}, { 19200 /*100 kHz*/    ,0x00 , 0x07},} }, 
   { /* 2  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x00 , 0x00}, { 18900 /*100 kHz*/    ,0x00 , 0x00}, { 19000 /*100 kHz*/    ,0x00 , 0x00}, { 19100 /*100 kHz*/    ,0x00 , 0x00}, { 19200 /*100 kHz*/    ,0x00 , 0x00},} }, 
   { /* 3  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x1C , 0xB8}, { 18900 /*100 kHz*/    ,0x1C , 0xB8}, { 19000 /*100 kHz*/    ,0x1C , 0xB8}, { 19100 /*100 kHz*/    ,0x1C , 0xB8}, { 19200 /*100 kHz*/    ,0x1C , 0xB8},} }, 
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, 
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band40_MIPI_RX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band41_MIPI_RX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};
kal_uint32 LTE_MIPI_RX_DATA_SIZE_TABLE_Set2[] =
{
      sizeof(LTE_BandNone_MIPI_RX_DATA), // LTE_BandNone, !!!DON'T MODIFY!!!         
      sizeof(LTE_Band1_MIPI_RX_DATA_Set2),    // Band_ind=0                               
      sizeof(LTE_Band3_MIPI_RX_DATA_Set2),    // Band_ind=1                               
      sizeof(LTE_Band7_MIPI_RX_DATA_Set2),    // Band_ind=2                               
      sizeof(LTE_Band28_MIPI_RX_DATA_Set2),    // Band_ind=3                               
      sizeof(LTE_Band38_MIPI_RX_DATA_Set2),    // Band_ind=4                               
      sizeof(LTE_Band39_MIPI_RX_DATA_Set2),   // Band_ind=5                               
      sizeof(LTE_Band40_MIPI_RX_DATA_Set2),   // Band_ind=6                               
      sizeof(LTE_Band41_MIPI_RX_DATA_Set2),   // Band_ind=7                               
      sizeof(LTE_Band8_MIPI_RX_DATA_Set2),   // Band_ind=8                               
      sizeof(LTE_BandNone_MIPI_RX_DATA),   // Band_ind=9                               
      sizeof(LTE_BandNone_MIPI_RX_DATA), // Band_ind=10                              
      sizeof(LTE_BandNone_MIPI_RX_DATA), // Band_ind=11                              
      sizeof(LTE_BandNone_MIPI_RX_DATA), // Band_ind=12                              
      sizeof(LTE_BandNone_MIPI_RX_DATA), // Band_ind=13                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_RX_DATA_TABLE_Set2[] =
{
      LTE_BandNone_MIPI_RX_DATA,     // LTE_BandNone, !!!DON'T MODIFY!!!            
      LTE_Band1_MIPI_RX_DATA_Set2,        // Band_ind=0                                  
      LTE_Band3_MIPI_RX_DATA_Set2,        // Band_ind=1                                  
      LTE_Band7_MIPI_RX_DATA_Set2,        // Band_ind=2                                  
      LTE_Band28_MIPI_RX_DATA_Set2,        // Band_ind=3                                  
      LTE_Band38_MIPI_RX_DATA_Set2,        // Band_ind=4                                  
      LTE_Band39_MIPI_RX_DATA_Set2,       // Band_ind=5                                  
      LTE_Band40_MIPI_RX_DATA_Set2,       // Band_ind=6                                  
      LTE_Band41_MIPI_RX_DATA_Set2,       // Band_ind=7                                  
      LTE_Band8_MIPI_RX_DATA_Set2,       // Band_ind=8                                  
      LTE_BandNone_MIPI_RX_DATA,       // Band_ind=9                                  
      LTE_BandNone_MIPI_RX_DATA,     // Band_ind=10                                 
      LTE_BandNone_MIPI_RX_DATA,     // Band_ind=11                                 
      LTE_BandNone_MIPI_RX_DATA,     // Band_ind=12                                 
      LTE_BandNone_MIPI_RX_DATA,     // Band_ind=13                                 
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_TX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band1_MIPI_TX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band3_MIPI_TX_EVENT_Set2[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band7_MIPI_TX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON1 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band8_MIPI_TX_EVENT_Set2[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band28_MIPI_TX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_FDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_FDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_TX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band39_MIPI_TX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 4    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON0 },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 5    , 5    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0},//PA Off
   { /* 2  */ LTE_MIPI_ASM , { 6    , 7    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_ASM_TX_ON0},
   { /* 3  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_TX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_TX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};
kal_uint32  LTE_MIPI_TX_EVENT_SIZE_TABLE_Set2[] =
{
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // LTE_BandNone, !!!DON'T MODIFY!!!           
      sizeof(LTE_Band1_MIPI_TX_EVENT_Set2),    // Band_ind=0                                 
      sizeof(LTE_Band3_MIPI_TX_EVENT_Set2),    // Band_ind=1                                 
      sizeof(LTE_Band7_MIPI_TX_EVENT_Set2),    // Band_ind=2                                 
      sizeof(LTE_Band28_MIPI_TX_EVENT_Set2),    // Band_ind=3                                 
      sizeof(LTE_Band38_MIPI_TX_EVENT_Set2),    // Band_ind=4                                 
      sizeof(LTE_Band39_MIPI_TX_EVENT_Set2),   // Band_ind=5                                 
      sizeof(LTE_Band40_MIPI_TX_EVENT_Set2),   // Band_ind=6                                 
      sizeof(LTE_Band41_MIPI_TX_EVENT_Set2),   // Band_ind=7                                 
      sizeof(LTE_Band8_MIPI_TX_EVENT_Set2),   // Band_ind=8                                 
      sizeof(LTE_BandNone_MIPI_TX_EVENT),   // Band_ind=9                                 
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // Band_ind=10                                
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // Band_ind=11                                
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // Band_ind=12                                
      sizeof(LTE_BandNone_MIPI_TX_EVENT), // Band_ind=13                                
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_TX_EVENT_TABLE_Set2[] =
{
      LTE_BandNone_MIPI_TX_EVENT,    // LTE_BandNone, !!!DON'T MODIFY!!!        
      LTE_Band1_MIPI_TX_EVENT_Set2,       // Band_ind=0                              
      LTE_Band3_MIPI_TX_EVENT_Set2,       // Band_ind=1                              
      LTE_Band7_MIPI_TX_EVENT_Set2,       // Band_ind=2                              
      LTE_Band28_MIPI_TX_EVENT_Set2,       // Band_ind=3                              
      LTE_Band38_MIPI_TX_EVENT_Set2,       // Band_ind=4                              
      LTE_Band39_MIPI_TX_EVENT_Set2,      // Band_ind=5                              
      LTE_Band40_MIPI_TX_EVENT_Set2,      // Band_ind=6                              
      LTE_Band41_MIPI_TX_EVENT_Set2,      // Band_ind=7                              
      LTE_Band8_MIPI_TX_EVENT_Set2,      // Band_ind=8                              
      LTE_BandNone_MIPI_TX_EVENT,      // Band_ind=9                              
      LTE_BandNone_MIPI_TX_EVENT,    // Band_ind=10                             
      LTE_BandNone_MIPI_TX_EVENT,    // Band_ind=11                             
      LTE_BandNone_MIPI_TX_EVENT,    // Band_ind=12                             
      LTE_BandNone_MIPI_TX_EVENT,    // Band_ind=13                             
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_TX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, // ASM PM_Trig: normal mode
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band1_MIPI_TX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x00 , 0x00}, { 19350 /*100 kHz*/    ,0x00 , 0x00}, { 19500 /*100 kHz*/    ,0x00 , 0x00}, { 19650 /*100 kHz*/    ,0x00 , 0x00}, { 19800 /*100 kHz*/    ,0x00 , 0x00},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x01 , 0x1F}, { 19350 /*100 kHz*/    ,0x01 , 0x1F}, { 19500 /*100 kHz*/    ,0x01 , 0x1F}, { 19650 /*100 kHz*/    ,0x01 , 0x1F}, { 19800 /*100 kHz*/    ,0x01 , 0x1F},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x02 , 0x00}, { 19350 /*100 kHz*/    ,0x02 , 0x00}, { 19500 /*100 kHz*/    ,0x02 , 0x00}, { 19650 /*100 kHz*/    ,0x02 , 0x00}, { 19800 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x03 , 0x00}, { 19350 /*100 kHz*/    ,0x03 , 0x00}, { 19500 /*100 kHz*/    ,0x03 , 0x00}, { 19650 /*100 kHz*/    ,0x03 , 0x00}, { 19800 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 19200 /*100 kHz*/    ,0x01 , 0x00}, { 19350 /*100 kHz*/    ,0x01 , 0x00}, { 19500 /*100 kHz*/    ,0x01 , 0x00}, { 19650 /*100 kHz*/    ,0x01 , 0x00}, { 19800 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable                
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 19200 /*100 kHz*/    ,0x1C , 0x38}, { 19350 /*100 kHz*/    ,0x1C , 0x38}, { 19500 /*100 kHz*/    ,0x1C , 0x38}, { 19650 /*100 kHz*/    ,0x1C , 0x38}, { 19800 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode  
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 19200 /*100 kHz*/    ,0x00 , 0x0C}, { 19350 /*100 kHz*/    ,0x00 , 0x0C}, { 19500 /*100 kHz*/    ,0x00 , 0x0C}, { 19650 /*100 kHz*/    ,0x00 , 0x0C}, { 19800 /*100 kHz*/    ,0x00 , 0x0C},} },                              
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band3_MIPI_TX_DATA_Set2[] = 
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x00 , 0x08}, { 17287 /*100 kHz*/    ,0x00 , 0x08}, { 17475 /*100 kHz*/    ,0x00 , 0x08}, { 17662 /*100 kHz*/    ,0x00 , 0x08}, { 17850 /*100 kHz*/    ,0x00 , 0x08},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x01 , 0x1F}, { 17287 /*100 kHz*/    ,0x01 , 0x1F}, { 17475 /*100 kHz*/    ,0x01 , 0x1F}, { 17662 /*100 kHz*/    ,0x01 , 0x1F}, { 17850 /*100 kHz*/    ,0x01 , 0x1F},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x02 , 0x00}, { 17287 /*100 kHz*/    ,0x02 , 0x00}, { 17475 /*100 kHz*/    ,0x02 , 0x00}, { 17662 /*100 kHz*/    ,0x02 , 0x00}, { 17850 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x03 , 0x00}, { 17287 /*100 kHz*/    ,0x03 , 0x00}, { 17475 /*100 kHz*/    ,0x03 , 0x00}, { 17662 /*100 kHz*/    ,0x03 , 0x00}, { 17850 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 17100 /*100 kHz*/    ,0x01 , 0x00}, { 17287 /*100 kHz*/    ,0x01 , 0x00}, { 17475 /*100 kHz*/    ,0x01 , 0x00}, { 17662 /*100 kHz*/    ,0x01 , 0x00}, { 17850 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable                
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 17100 /*100 kHz*/    ,0x1C , 0x38}, { 17287 /*100 kHz*/    ,0x1C , 0x38}, { 17475 /*100 kHz*/    ,0x1C , 0x38}, { 17662 /*100 kHz*/    ,0x1C , 0x38}, { 17850 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode  
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 17100 /*100 kHz*/    ,0x00 , 0x02}, { 17287 /*100 kHz*/    ,0x00 , 0x02}, { 17475 /*100 kHz*/    ,0x00 , 0x02}, { 17662 /*100 kHz*/    ,0x00 , 0x02}, { 17850 /*100 kHz*/    ,0x00 , 0x02},} },                              
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};



LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band7_MIPI_TX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25000 /*100 kHz*/    ,0x1C , 0x38}, { 25175 /*100 kHz*/    ,0x1C , 0x38}, { 25350 /*100 kHz*/    ,0x1C , 0x38}, { 25525 /*100 kHz*/    ,0x1C , 0x38}, { 25700 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25000 /*100 kHz*/    ,0x00 , 0x0D}, { 25175 /*100 kHz*/    ,0x00 , 0x0D}, { 25350 /*100 kHz*/    ,0x00 , 0x0D}, { 25525 /*100 kHz*/    ,0x00 , 0x0D}, { 25700 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25000 /*100 kHz*/    ,0x01 , 0x00}, { 25175 /*100 kHz*/    ,0x01 , 0x00}, { 25350 /*100 kHz*/    ,0x01 , 0x00}, { 25525 /*100 kHz*/    ,0x01 , 0x00}, { 25700 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25000 /*100 kHz*/    ,0x00 , 0x00}, { 25175 /*100 kHz*/    ,0x00 , 0x00}, { 25350 /*100 kHz*/    ,0x00 , 0x00}, { 25525 /*100 kHz*/    ,0x00 , 0x00}, { 25700 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band8_MIPI_TX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x1C , 0x38}, { 8888 /*100 kHz*/    ,0x1C , 0x38}, { 8976 /*100 kHz*/    ,0x1C , 0x38}, { 9064 /*100 kHz*/    ,0x1C , 0x38}, { 9150 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x00 , 0x00}, { 8888 /*100 kHz*/    ,0x00 , 0x00}, { 8976 /*100 kHz*/    ,0x00 , 0x00}, { 9064 /*100 kHz*/    ,0x00 , 0x00}, { 9150 /*100 kHz*/    ,0x00 , 0x00},} }, // PA path sel
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x01 , 0x0F}, { 8888 /*100 kHz*/    ,0x01 , 0x0F}, { 8976 /*100 kHz*/    ,0x01 , 0x0F}, { 9064 /*100 kHz*/    ,0x01 , 0x0F}, { 9150 /*100 kHz*/    ,0x01 , 0x0F},} }, // PA enable
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x02 , 0x00}, { 8888 /*100 kHz*/    ,0x02 , 0x00}, { 8976 /*100 kHz*/    ,0x02 , 0x00}, { 9064 /*100 kHz*/    ,0x02 , 0x00}, { 9150 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x03 , 0x00}, { 8888 /*100 kHz*/    ,0x03 , 0x00}, { 8976 /*100 kHz*/    ,0x03 , 0x00}, { 9064 /*100 kHz*/    ,0x03 , 0x00}, { 9150 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 8800 /*100 kHz*/    ,0x01 , 0x00}, { 8888 /*100 kHz*/    ,0x01 , 0x00}, { 8976 /*100 kHz*/    ,0x01 , 0x00}, { 9064 /*100 kHz*/    ,0x01 , 0x00}, { 9150 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 8800 /*100 kHz*/    ,0x1C , 0x38}, { 8888 /*100 kHz*/    ,0x1C , 0x38}, { 8976 /*100 kHz*/    ,0x1C , 0x38}, { 9064 /*100 kHz*/    ,0x1C , 0x38}, { 9150 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 8800 /*100 kHz*/    ,0x00 , 0x03}, { 8888 /*100 kHz*/    ,0x00 , 0x03}, { 8976 /*100 kHz*/    ,0x00 , 0x03}, { 9064 /*100 kHz*/    ,0x00 , 0x03}, { 9150 /*100 kHz*/    ,0x00 , 0x03},} },
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band28_MIPI_TX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7030 /*100 kHz*/    ,0x1C , 0x38}, { 7143 /*100 kHz*/    ,0x1C , 0x38}, { 7255 /*100 kHz*/    ,0x1C , 0x38}, { 7370 /*100 kHz*/    ,0x1C , 0x38}, { 7480 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7030 /*100 kHz*/    ,0x00 , 0x0C}, { 7143 /*100 kHz*/    ,0x00 , 0x0C}, { 7255 /*100 kHz*/    ,0x00 , 0x04}, { 7370 /*100 kHz*/    ,0x00 , 0x04}, { 7480 /*100 kHz*/    ,0x00 , 0x04},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7030 /*100 kHz*/    ,0x01 , 0x0F}, { 7143 /*100 kHz*/    ,0x01 , 0x0F}, { 7255 /*100 kHz*/    ,0x01 , 0x0F}, { 7370 /*100 kHz*/    ,0x01 , 0x0F}, { 7480 /*100 kHz*/    ,0x01 , 0x0F},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7030 /*100 kHz*/    ,0x02 , 0x00}, { 7143 /*100 kHz*/    ,0x02 , 0x00}, { 7255 /*100 kHz*/    ,0x02 , 0x00}, { 7370 /*100 kHz*/    ,0x02 , 0x00}, { 7480 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7030 /*100 kHz*/    ,0x03 , 0x00}, { 7143 /*100 kHz*/    ,0x03 , 0x00}, { 7255 /*100 kHz*/    ,0x03 , 0x00}, { 7370 /*100 kHz*/    ,0x03 , 0x00}, { 7480 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 7030 /*100 kHz*/    ,0x01 , 0x00}, { 7143 /*100 kHz*/    ,0x01 , 0x00}, { 7255 /*100 kHz*/    ,0x01 , 0x00}, { 7370 /*100 kHz*/    ,0x01 , 0x00}, { 7480 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable                
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7030 /*100 kHz*/    ,0x1C , 0x38}, { 7143 /*100 kHz*/    ,0x1C , 0x38}, { 7255 /*100 kHz*/    ,0x1C , 0x38}, { 7370 /*100 kHz*/    ,0x1C , 0x38}, { 7480 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode  
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 7030 /*100 kHz*/    ,0x00 , 0x01}, { 7143 /*100 kHz*/    ,0x00 , 0x01}, { 7255 /*100 kHz*/    ,0x00 , 0x0B}, { 7370 /*100 kHz*/    ,0x00 , 0x0B}, { 7480 /*100 kHz*/    ,0x00 , 0x0B},} },                              
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band38_MIPI_TX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x00 , 0x0D}, { 25825 /*100 kHz*/    ,0x00 , 0x0D}, { 25950 /*100 kHz*/    ,0x00 , 0x0D}, { 26075 /*100 kHz*/    ,0x00 , 0x0D}, { 26200 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x01 , 0x00}, { 25825 /*100 kHz*/    ,0x01 , 0x00}, { 25950 /*100 kHz*/    ,0x01 , 0x00}, { 26075 /*100 kHz*/    ,0x01 , 0x00}, { 26200 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x00 , 0x00}, { 25825 /*100 kHz*/    ,0x00 , 0x00}, { 25950 /*100 kHz*/    ,0x00 , 0x00}, { 26075 /*100 kHz*/    ,0x00 , 0x00}, { 26200 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band39_MIPI_TX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x00 , 0x0C}, { 18900 /*100 kHz*/    ,0x00 , 0x0C}, { 19000 /*100 kHz*/    ,0x00 , 0x0C}, { 19100 /*100 kHz*/    ,0x00 , 0x0C}, { 19200 /*100 kHz*/    ,0x00 , 0x0C},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x01 , 0x1F}, { 18900 /*100 kHz*/    ,0x01 , 0x1F}, { 19000 /*100 kHz*/    ,0x01 , 0x1F}, { 19100 /*100 kHz*/    ,0x01 , 0x1F}, { 19200 /*100 kHz*/    ,0x01 , 0x1F},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x02 , 0x00}, { 18900 /*100 kHz*/    ,0x02 , 0x00}, { 19000 /*100 kHz*/    ,0x02 , 0x00}, { 19100 /*100 kHz*/    ,0x02 , 0x00}, { 19200 /*100 kHz*/    ,0x02 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x03 , 0x00}, { 18900 /*100 kHz*/    ,0x03 , 0x00}, { 19000 /*100 kHz*/    ,0x03 , 0x00}, { 19100 /*100 kHz*/    ,0x03 , 0x00}, { 19200 /*100 kHz*/    ,0x03 , 0x00},} }, // Iref                      
   { /* 5  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA0    ,{ { 18800 /*100 kHz*/    ,0x01 , 0x00}, { 18900 /*100 kHz*/    ,0x01 , 0x00}, { 19000 /*100 kHz*/    ,0x01 , 0x00}, { 19100 /*100 kHz*/    ,0x01 , 0x00}, { 19200 /*100 kHz*/    ,0x01 , 0x00},} }, // PA disable                
   { /* 6  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x1C , 0x38}, { 18900 /*100 kHz*/    ,0x1C , 0x38}, { 19000 /*100 kHz*/    ,0x1C , 0x38}, { 19100 /*100 kHz*/    ,0x1C , 0x38}, { 19200 /*100 kHz*/    ,0x1C , 0x38},} }, // ASM PM_Trig: normal mode  
   { /* 7  */ LTE_MIPI_ASM , LTE_MIPI_PORT1    , LTE_REG_W     , MIPI_USID_ASM0   ,{ { 18800 /*100 kHz*/    ,0x00 , 0x05}, { 18900 /*100 kHz*/    ,0x00 , 0x05}, { 19000 /*100 kHz*/    ,0x00 , 0x05}, { 19100 /*100 kHz*/    ,0x00 , 0x05}, { 19200 /*100 kHz*/    ,0x00 , 0x05},} },                              
   { /* 8  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   }, { 0    /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band40_MIPI_TX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x00 , 0x0D}, { 23250 /*100 kHz*/    ,0x00 , 0x0D}, { 23500 /*100 kHz*/    ,0x00 , 0x0D}, { 23750 /*100 kHz*/    ,0x00 , 0x0D}, { 24000 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x01 , 0x00}, { 23250 /*100 kHz*/    ,0x01 , 0x00}, { 23500 /*100 kHz*/    ,0x01 , 0x00}, { 23750 /*100 kHz*/    ,0x01 , 0x00}, { 24000 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x00 , 0x00}, { 23250 /*100 kHz*/    ,0x00 , 0x00}, { 23500 /*100 kHz*/    ,0x00 , 0x00}, { 23750 /*100 kHz*/    ,0x00 , 0x00}, { 24000 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band41_MIPI_TX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x00 , 0x0D}, { 25445 /*100 kHz*/    ,0x00 , 0x0D}, { 25930 /*100 kHz*/    ,0x00 , 0x0D}, { 26415 /*100 kHz*/    ,0x00 , 0x0D}, { 26900 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x01 , 0x00}, { 25445 /*100 kHz*/    ,0x01 , 0x00}, { 25930 /*100 kHz*/    ,0x01 , 0x00}, { 26415 /*100 kHz*/    ,0x01 , 0x00}, { 26900 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x00 , 0x00}, { 25445 /*100 kHz*/    ,0x00 , 0x00}, { 25930 /*100 kHz*/    ,0x00 , 0x00}, { 26415 /*100 kHz*/    ,0x00 , 0x00}, { 26900 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};
kal_uint32  LTE_MIPI_TX_DATA_SIZE_TABLE_Set2[] =
{
      sizeof(LTE_BandNone_MIPI_TX_DATA), // LTE_BandNone, !!!DON'T MODIFY!!!     
      sizeof(LTE_Band1_MIPI_TX_DATA_Set2),    // Band_ind=0                           
      sizeof(LTE_Band3_MIPI_TX_DATA_Set2),    // Band_ind=1                           
      sizeof(LTE_Band7_MIPI_TX_DATA_Set2),    // Band_ind=2                           
      sizeof(LTE_Band28_MIPI_TX_DATA_Set2),    // Band_ind=3                           
      sizeof(LTE_Band39_MIPI_TX_DATA_Set2),    // Band_ind=4                           
      sizeof(LTE_Band39_MIPI_TX_DATA_Set2),   // Band_ind=5                           
      sizeof(LTE_Band40_MIPI_TX_DATA_Set2),   // Band_ind=6                           
      sizeof(LTE_Band41_MIPI_TX_DATA_Set2),   // Band_ind=7                           
      sizeof(LTE_Band8_MIPI_TX_DATA_Set2),   // Band_ind=8                           
      sizeof(LTE_BandNone_MIPI_TX_DATA),   // Band_ind=9                           
      sizeof(LTE_BandNone_MIPI_TX_DATA), // Band_ind=10                          
      sizeof(LTE_BandNone_MIPI_TX_DATA), // Band_ind=11                          
      sizeof(LTE_BandNone_MIPI_TX_DATA), // Band_ind=12                          
      sizeof(LTE_BandNone_MIPI_TX_DATA), // Band_ind=13                          
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_TX_DATA_TABLE_Set2[] =
{
      LTE_BandNone_MIPI_TX_DATA,     // LTE_BandNone, !!!DON'T MODIFY!!!    
      LTE_Band1_MIPI_TX_DATA_Set2,        // Band_ind=0                          
      LTE_Band3_MIPI_TX_DATA_Set2,        // Band_ind=1                          
      LTE_Band7_MIPI_TX_DATA_Set2,        // Band_ind=2                          
      LTE_Band28_MIPI_TX_DATA_Set2,        // Band_ind=3                          
      LTE_Band38_MIPI_TX_DATA_Set2,        // Band_ind=4                          
      LTE_Band39_MIPI_TX_DATA_Set2,       // Band_ind=5                          
      LTE_Band40_MIPI_TX_DATA_Set2,       // Band_ind=6                          
      LTE_Band41_MIPI_TX_DATA_Set2,       // Band_ind=7                          
      LTE_Band8_MIPI_TX_DATA_Set2,       // Band_ind=8                          
      LTE_BandNone_MIPI_TX_DATA,       // Band_ind=9                          
      LTE_BandNone_MIPI_TX_DATA,     // Band_ind=10                         
      LTE_BandNone_MIPI_TX_DATA,     // Band_ind=11                         
      LTE_BandNone_MIPI_TX_DATA,     // Band_ind=12                         
      LTE_BandNone_MIPI_TX_DATA,     // Band_ind=13                         
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_TPC_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band1_MIPI_TPC_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band3_MIPI_TPC_EVENT_Set2[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band7_MIPI_TPC_EVENT_Set2[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band8_MIPI_TPC_EVENT_Set2[] = 
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};


LTE_MIPI_EVENT_TABLE_T LTE_Band28_MIPI_TPC_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_TPC_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band39_MIPI_TPC_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TPC_SET   , US2OFFCNT(12)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_TPC_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_TPC_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};
kal_uint32  LTE_MIPI_TPC_EVENT_SIZE_TABLE_Set2[] =
{
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // LTE_BandNone, !!!DON'T MODIFY!!! 
      sizeof(LTE_Band1_MIPI_TPC_EVENT_Set2),    // Band_ind=0                       
      sizeof(LTE_Band3_MIPI_TPC_EVENT_Set2),    // Band_ind=1                       
      sizeof(LTE_Band7_MIPI_TPC_EVENT_Set2),    // Band_ind=2                       
      sizeof(LTE_Band28_MIPI_TPC_EVENT_Set2),    // Band_ind=3                       
      sizeof(LTE_Band38_MIPI_TPC_EVENT_Set2),    // Band_ind=4                       
      sizeof(LTE_Band39_MIPI_TPC_EVENT_Set2),   // Band_ind=5                       
      sizeof(LTE_Band40_MIPI_TPC_EVENT_Set2),   // Band_ind=6                       
      sizeof(LTE_Band41_MIPI_TPC_EVENT_Set2),   // Band_ind=7                       
      sizeof(LTE_Band8_MIPI_TPC_EVENT_Set2),   // Band_ind=8                       
      sizeof(LTE_BandNone_MIPI_TPC_EVENT),   // Band_ind=9                       
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // Band_ind=10                      
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // Band_ind=11                      
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // Band_ind=12                      
      sizeof(LTE_BandNone_MIPI_TPC_EVENT), // Band_ind=13                      
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_TPC_EVENT_TABLE_Set2[] =
{
      LTE_BandNone_MIPI_TPC_EVENT,   // LTE_BandNone, !!!DON'T MODIFY!!!
      LTE_Band1_MIPI_TPC_EVENT_Set2,      // Band_ind=0                      
      LTE_Band3_MIPI_TPC_EVENT_Set2,      // Band_ind=1                      
      LTE_Band7_MIPI_TPC_EVENT_Set2,      // Band_ind=2                      
      LTE_Band28_MIPI_TPC_EVENT_Set2,      // Band_ind=3                      
      LTE_Band38_MIPI_TPC_EVENT_Set2,      // Band_ind=4                      
      LTE_Band39_MIPI_TPC_EVENT_Set2,     // Band_ind=5                      
      LTE_Band40_MIPI_TPC_EVENT_Set2,     // Band_ind=6                      
      LTE_Band41_MIPI_TPC_EVENT_Set2,     // Band_ind=7                      
      LTE_Band8_MIPI_TPC_EVENT_Set2,     // Band_ind=8                      
      LTE_BandNone_MIPI_TPC_EVENT,     // Band_ind=9                      
      LTE_BandNone_MIPI_TPC_EVENT,   // Band_ind=10                     
      LTE_BandNone_MIPI_TPC_EVENT,   // Band_ind=11                     
      LTE_BandNone_MIPI_TPC_EVENT,   // Band_ind=12                     
      LTE_BandNone_MIPI_TPC_EVENT,   // Band_ind=13                     
};

LTE_MIPI_DATA_TABLE_T LTE_BandNone_MIPI_TPC_DATA_Set2[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band1_MIPI_TPC_DATA_Set2[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band3_MIPI_TPC_DATA_Set2[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band7_MIPI_TPC_DATA_Set2[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band8_MIPI_TPC_DATA_Set2[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band28_MIPI_TPC_DATA_Set2[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band38_MIPI_TPC_DATA_Set2[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band39_MIPI_TPC_DATA_Set2[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA2}, // Data ref. by PA Section table idx 0
   {/* 3  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band40_MIPI_TPC_DATA_Set2[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band41_MIPI_TPC_DATA_Set2[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T*  LTE_MIPI_TPC_DATA_TABLE_Set2[] =
{
      LTE_BandNone_MIPI_TPC_DATA,    // LTE_BandNone, !!!DON'T MODIFY!!!  
      LTE_Band1_MIPI_TPC_DATA_Set2,       // Band_ind=0                        
      LTE_Band3_MIPI_TPC_DATA_Set2,       // Band_ind=1                        
      LTE_Band7_MIPI_TPC_DATA_Set2,       // Band_ind=2                        
      LTE_Band28_MIPI_TPC_DATA_Set2,       // Band_ind=3                        
      LTE_Band38_MIPI_TPC_DATA_Set2,       // Band_ind=4                        
      LTE_Band39_MIPI_TPC_DATA_Set2,      // Band_ind=5                        
      LTE_Band40_MIPI_TPC_DATA_Set2,      // Band_ind=6                        
      LTE_Band41_MIPI_TPC_DATA_Set2,      // Band_ind=7                        
      LTE_Band8_MIPI_TPC_DATA_Set2,      // Band_ind=8                        
      LTE_BandNone_MIPI_TPC_DATA,      // Band_ind=9                        
      LTE_BandNone_MIPI_TPC_DATA,    // Band_ind=10                       
      LTE_BandNone_MIPI_TPC_DATA,    // Band_ind=11                       
      LTE_BandNone_MIPI_TPC_DATA,    // Band_ind=12                       
      LTE_BandNone_MIPI_TPC_DATA,    // Band_ind=13                       
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_BandNone_MIPI_PA_SECTION_DATA_Set2[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band1_MIPI_PA_SECTION_DATA_Set2[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      19200,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      19350,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      19500,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
     }
   },

      /*8804 KHz*/
   {
      19650,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      19800,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCE} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band3_MIPI_PA_SECTION_DATA_Set2[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      17100,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      17287,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      17475,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      17662,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      17850,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x87} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xA8} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xEA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDB} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xED} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};


LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band7_MIPI_PA_SECTION_DATA_Set2[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      25000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25175,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25350,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      25525,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      25700,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band8_MIPI_PA_SECTION_DATA_Set2[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      8800,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      8888,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      8976,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      9064,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      9150,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x54} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x96} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xB6} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xC7} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x98} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xF9} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xFC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCC} , { 0x3 , 0x11} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band28_MIPI_PA_SECTION_DATA_Set2[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      7030,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      7143,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      7255,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      7370,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      7480,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x86} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xA7} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xD9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xBA} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xCB} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0xEC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x0F}  , { 0x2 , 0x8D} , { 0x3 , 0x30} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band38_MIPI_PA_SECTION_DATA_Set2[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      25700,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25825,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25950,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      26075,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      26200,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};
LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band39_MIPI_PA_SECTION_DATA_Set2[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*18800 KHz*/
   {
      18800,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
      
      /*18900 KHz*/
   {
      18900,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   }, 
      
      /*19000 KHz*/
   {
      19000,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
      
      /*19100 KHz*/
   {
      19100,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
      
      /*19200 KHz*/
   {
      19200,/*100kHz*/
      MIPI_USID_PA0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x66} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0x97} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xC9} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xFA} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBC} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xBD} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xCF} , { 0x3 , 0x10} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x1F}  , { 0x2 , 0xDD} , { 0x3 , 0x14} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x1 , 0x00}  , { 0x2 , 0x00} , { 0x3 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};
LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band40_MIPI_PA_SECTION_DATA_Set2[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      23000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      23250,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      23500,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      23750,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      24000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band41_MIPI_PA_SECTION_DATA_Set2[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      24960,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25445,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25930,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      26415,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      26900,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};
kal_uint32  LTE_MIPI_PA_TPC_SECTION_DATA_SIZE_Set2[] =
{
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // LTE_BandNone, !!!DON'T MODIFY!!!  
      sizeof(LTE_Band1_MIPI_PA_SECTION_DATA_Set2),     // Band_ind=0                        
      sizeof(LTE_Band3_MIPI_PA_SECTION_DATA_Set2),     // Band_ind=1                        
      sizeof(LTE_Band7_MIPI_PA_SECTION_DATA_Set2),     // Band_ind=2                        
      sizeof(LTE_Band28_MIPI_PA_SECTION_DATA_Set2),     // Band_ind=3                        
      sizeof(LTE_Band38_MIPI_PA_SECTION_DATA_Set2),     // Band_ind=4                        
      sizeof(LTE_Band39_MIPI_PA_SECTION_DATA_Set2),    // Band_ind=5                        
      sizeof(LTE_Band40_MIPI_PA_SECTION_DATA_Set2),    // Band_ind=6                        
      sizeof(LTE_Band41_MIPI_PA_SECTION_DATA_Set2),    // Band_ind=7                        
      sizeof(LTE_Band8_MIPI_PA_SECTION_DATA_Set2),    // Band_ind=8                        
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),    // Band_ind=9                        
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // Band_ind=10                       
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // Band_ind=11                       
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // Band_ind=12                       
      sizeof(LTE_BandNone_MIPI_PA_SECTION_DATA),  // Band_ind=13                       
};

LTE_MIPI_TPC_SECTION_TABLE_T*  LTE_MIPI_PA_TPC_SECTION_DATA_Set2[] =
{
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // LTE_BandNone, !!!DON'T MODIFY!!!       
      LTE_Band1_MIPI_PA_SECTION_DATA_Set2,      // Band_ind=0                             
      LTE_Band3_MIPI_PA_SECTION_DATA_Set2,      // Band_ind=1                             
      LTE_Band7_MIPI_PA_SECTION_DATA_Set2,      // Band_ind=2                             
      LTE_Band28_MIPI_PA_SECTION_DATA_Set2,      // Band_ind=3                             
      LTE_Band38_MIPI_PA_SECTION_DATA_Set2,      // Band_ind=4                             
      LTE_Band39_MIPI_PA_SECTION_DATA_Set2,     // Band_ind=5                             
      LTE_Band40_MIPI_PA_SECTION_DATA_Set2,     // Band_ind=6                             
      LTE_Band41_MIPI_PA_SECTION_DATA_Set2,     // Band_ind=7                             
      LTE_Band8_MIPI_PA_SECTION_DATA_Set2,     // Band_ind=8                             
      LTE_BandNone_MIPI_PA_SECTION_DATA,     // Band_ind=9                             
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // Band_ind=10                            
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // Band_ind=11                            
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // Band_ind=12                            
      LTE_BandNone_MIPI_PA_SECTION_DATA,   // Band_ind=13                            
};

/*special handle for T/Rx calibration, we should force ASM to isolation mode */
/*Users just need to provide the ASM isolation CW, DSP may use immediate mode*/
/*to control the MIPI ASM                                                    */
LTE_MIPI_IMM_DATA_TABLE_T LTE_MIPI_ASM_ISOLATION_DATA_Set2[] =
{
   //No.      elm type     , port_sel       , data_seq     ,       USID       , addr  , data , wait_time(us)
   { /* 0  */ LTE_MIPI_ASM , LTE_MIPI_PORT1 , LTE_REG_W    , MIPI_USID_ASM0   , {0x0  , 0x7F} , WAITUSCNT(0) }, // Broadcast ID, Standard MIPI, PM_TRIG = normal mode
   {LTE_MIPI_END_PATTERN,0,0,0,{0,0},0},
};

/*** MIPI BYPASS Feature ***/
LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_BYPASS_TX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_BYPASS_TX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_BYPASS_TX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_BYPASS_TX_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 2    }, LTE_MIPI_TRX_ON    , LTE_TDD_MIPI_PA_TX_ON1  },//PA On
   { /* 1  */ LTE_MIPI_PA  , { 3    , 3    }, LTE_MIPI_TRX_OFF   , LTE_TDD_MIPI_PA_TX_OFF0 },//PA Off
   { /* 2  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};
kal_uint32  LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE_Set2[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),      // !!!DON'T MODIFY!!! 
      sizeof(LTE_Band38_MIPI_BYPASS_TX_EVENT_Set2),   // Band_ind=0         
      sizeof(LTE_Band40_MIPI_BYPASS_TX_EVENT_Set2),   // Band_ind=1         
      sizeof(LTE_Band41_MIPI_BYPASS_TX_EVENT_Set2),      // Band_ind=2         
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),      // Band_ind=3         
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_EVENT),      // Band_ind=4         
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_BYPASS_TX_EVENT_TABLE_Set2[] =
{
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,       // !!!DON'T MODIFY!!! 
      LTE_Band38_MIPI_BYPASS_TX_EVENT_Set2,    // Band_ind=0         
      LTE_Band40_MIPI_BYPASS_TX_EVENT_Set2,    // Band_ind=1         
      LTE_Band41_MIPI_BYPASS_TX_EVENT_Set2,       // Band_ind=2         
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,       // Band_ind=3         
      LTE_BandNone_MIPI_BYPASS_TX_EVENT,       // Band_ind=4         
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_BandNone_MIPI_BYPASS_TX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0 /*100 kHz*/        ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} }, // ASM PM_Trig: normal mode
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band38_MIPI_BYPASS_TX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x1C , 0x38}, { 25825 /*100 kHz*/    ,0x1C , 0x38}, { 25950 /*100 kHz*/    ,0x1C , 0x38}, { 26075 /*100 kHz*/    ,0x1C , 0x38}, { 26200 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x00 , 0x2A}, { 25825 /*100 kHz*/    ,0x00 , 0x2A}, { 25950 /*100 kHz*/    ,0x00 , 0x2A}, { 26075 /*100 kHz*/    ,0x00 , 0x2A}, { 26200 /*100 kHz*/    ,0x00 , 0x2A},} }, // PA path sel _enable            
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x01 , 0x00}, { 25825 /*100 kHz*/    ,0x01 , 0x00}, { 25950 /*100 kHz*/    ,0x01 , 0x00}, { 26075 /*100 kHz*/    ,0x01 , 0x00}, { 26200 /*100 kHz*/    ,0x01, 0x00},} }, // Iref                
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 25700 /*100 kHz*/    ,0x00 , 0x00}, { 25825 /*100 kHz*/    ,0x00 , 0x00}, { 25950 /*100 kHz*/    ,0x00 , 0x00}, { 26075 /*100 kHz*/    ,0x00 , 0x00}, { 26200 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band40_MIPI_BYPASS_TX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x1C , 0x38}, { 23250 /*100 kHz*/    ,0x1C , 0x38}, { 23500 /*100 kHz*/    ,0x1C , 0x38}, { 23750 /*100 kHz*/    ,0x1C , 0x38}, { 24000 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x00 , 0x0D}, { 23250 /*100 kHz*/    ,0x00 , 0x0D}, { 23500 /*100 kHz*/    ,0x00 , 0x0D}, { 23750 /*100 kHz*/    ,0x00 , 0x0D}, { 24000 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x01 , 0x00}, { 23250 /*100 kHz*/    ,0x01 , 0x00}, { 23500 /*100 kHz*/    ,0x01 , 0x00}, { 23750 /*100 kHz*/    ,0x01 , 0x00}, { 24000 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 23000 /*100 kHz*/    ,0x00 , 0x00}, { 23250 /*100 kHz*/    ,0x00 , 0x00}, { 23500 /*100 kHz*/    ,0x00 , 0x00}, { 23750 /*100 kHz*/    ,0x00 , 0x00}, { 24000 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

LTE_MIPI_DATA_SUBBAND_TABLE_T LTE_Band41_MIPI_BYPASS_TX_DATA_Set2[] =
{
   //No.      elm type     , port_sel          , data_seq      , USID             ,{ { subband earfcn /*0*/ ,addr ,data }, { subband earfcn /*1*/ ,addr ,data }, { subband earfcn /*2*/ ,addr ,data }, { subband earfcn /*3*/ ,addr ,data }, { subband earfcn /*4*/ ,addr ,data } },
   { /* 0  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x1C , 0x38}, { 25445 /*100 kHz*/    ,0x1C , 0x38}, { 25930 /*100 kHz*/    ,0x1C , 0x38}, { 26415 /*100 kHz*/    ,0x1C , 0x38}, { 26900 /*100 kHz*/    ,0x1C , 0x38},} }, // PA On PM_Trig: normal mode
   { /* 1  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x00 , 0x0D}, { 25445 /*100 kHz*/    ,0x00 , 0x0D}, { 25930 /*100 kHz*/    ,0x00 , 0x0D}, { 26415 /*100 kHz*/    ,0x00 , 0x0D}, { 26900 /*100 kHz*/    ,0x00 , 0x0D},} }, // PA path sel               
   { /* 2  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x01 , 0x00}, { 25445 /*100 kHz*/    ,0x01 , 0x00}, { 25930 /*100 kHz*/    ,0x01 , 0x00}, { 26415 /*100 kHz*/    ,0x01 , 0x00}, { 26900 /*100 kHz*/    ,0x01 , 0x00},} }, // PA enable                 
   { /* 3  */ LTE_MIPI_PA  , LTE_MIPI_PORT0    , LTE_REG_W     , MIPI_USID_PA1    ,{ { 24960 /*100 kHz*/    ,0x00 , 0x00}, { 25445 /*100 kHz*/    ,0x00 , 0x00}, { 25930 /*100 kHz*/    ,0x00 , 0x00}, { 26415 /*100 kHz*/    ,0x00 , 0x00}, { 26900 /*100 kHz*/    ,0x00 , 0x00},} }, // Iref                      
   { /* 4  */ LTE_MIPI_NULL, 0                 , 0             , 0                ,{ { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   }, { 0     /*100 kHz*/    ,0    , 0   },} },                              
};

kal_uint32  LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE_Set2[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),      // !!!DON'T MODIFY!!! 
      sizeof(LTE_Band38_MIPI_BYPASS_TX_DATA_Set2),   // Band_ind=0         
      sizeof(LTE_Band40_MIPI_BYPASS_TX_DATA_Set2),   // Band_ind=1         
      sizeof(LTE_Band41_MIPI_BYPASS_TX_DATA_Set2),      // Band_ind=2         
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),      // Band_ind=3         
      sizeof(LTE_BandNone_MIPI_BYPASS_TX_DATA),      // Band_ind=4         
};

LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_BYPASS_TX_DATA_TABLE_Set2[] =
{
      LTE_BandNone_MIPI_BYPASS_TX_DATA,        // !!!DON'T MODIFY!!!      
      LTE_Band38_MIPI_BYPASS_TX_DATA_Set2,     // Band_ind=0              
      LTE_Band40_MIPI_BYPASS_TX_DATA_Set2,     // Band_ind=1              
      LTE_Band41_MIPI_BYPASS_TX_DATA_Set2,        // Band_ind=2              
      LTE_BandNone_MIPI_BYPASS_TX_DATA,        // Band_ind=3              
      LTE_BandNone_MIPI_BYPASS_TX_DATA,        // Band_ind=4              
};

LTE_MIPI_EVENT_TABLE_T LTE_BandNone_MIPI_BYPASS_TPC_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band38_MIPI_BYPASS_TPC_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band40_MIPI_BYPASS_TPC_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

LTE_MIPI_EVENT_TABLE_T LTE_Band41_MIPI_BYPASS_TPC_EVENT_Set2[] =
{
   /* No.     elm type     , data idx       , evt_type           , evt_offset     */
   /*                        { start, stop },                      ( us )         */
   { /* 0  */ LTE_MIPI_PA  , { 0    , 1    }, LTE_MIPI_TPC_SET   , US2OFFCNT(7)  },
   { /* 1  */ LTE_MIPI_NULL, { 0    , 0    }, LTE_MIPI_EVENT_NULL, 0              },
};

kal_uint32  LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE_Set2[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),    // !!!DON'T MODIFY!!!  
      sizeof(LTE_Band38_MIPI_BYPASS_TPC_EVENT_Set2),    // Band_ind=0          
      sizeof(LTE_Band40_MIPI_BYPASS_TPC_EVENT_Set2),    // Band_ind=1          
      sizeof(LTE_Band41_MIPI_BYPASS_TPC_EVENT_Set2),    // Band_ind=2          
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),    // Band_ind=3          
      sizeof(LTE_BandNone_MIPI_BYPASS_TPC_EVENT),    // Band_ind=4          
};

LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_BYPASS_TPC_EVENT_TABLE_Set2[] =
{
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,   // !!!DON'T MODIFY!!! 
      LTE_Band38_MIPI_BYPASS_TPC_EVENT_Set2,   // Band_ind=0         
      LTE_Band40_MIPI_BYPASS_TPC_EVENT_Set2,   // Band_ind=1         
      LTE_Band41_MIPI_BYPASS_TPC_EVENT_Set2,   // Band_ind=2         
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,   // Band_ind=3         
      LTE_BandNone_MIPI_BYPASS_TPC_EVENT,   // Band_ind=4         
};

LTE_MIPI_DATA_TABLE_T LTE_BandNone_MIPI_BYPASS_TPC_DATA_Set2[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band38_MIPI_BYPASS_TPC_DATA_Set2[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band40_MIPI_BYPASS_TPC_DATA_Set2[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T LTE_Band41_MIPI_BYPASS_TPC_DATA_Set2[] =
{
   //No.     elm type       , port_sel         , data_seq    , USID                         , address                      , data
   {/* 0  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA0}, // PA On Band Select
   {/* 1  */ LTE_MIPI_PA_SEC, LTE_MIPI_PORT0   , LTE_REG_W   , LTE_MIPI_PA_SECTION_USID     , LTE_MIPI_PA_SECTION_ADDRESS  , LTE_MIPI_PA_SECTION_DATA1}, // Data ref. by PA Section table idx 0
   {/* 2  */ LTE_MIPI_NULL  , 0                , 0           , 0                            , 0                            , 0               },
};

LTE_MIPI_DATA_TABLE_T*  LTE_MIPI_BYPASS_TPC_DATA_TABLE_Set2[] =
{
      LTE_BandNone_MIPI_BYPASS_TPC_DATA,    // !!!DON'T MODIFY!!! 
      LTE_Band38_MIPI_BYPASS_TPC_DATA_Set2,    // Band_ind=0         
      LTE_Band40_MIPI_BYPASS_TPC_DATA_Set2,    // Band_ind=1         
      LTE_Band41_MIPI_BYPASS_TPC_DATA_Set2,    // Band_ind=2         
      LTE_BandNone_MIPI_BYPASS_TPC_DATA,    // Band_ind=3         
      LTE_BandNone_MIPI_BYPASS_TPC_DATA,    // Band_ind=4         
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA_Set2[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      0,/*100kHz*/
      0,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},
         {{ {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}, {0x0,0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band38_MIPI_BYPASS_PA_SECTION_DATA_Set2[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      25700,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25825,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25950,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      26075,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      26200,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band40_MIPI_BYPASS_PA_SECTION_DATA_Set2[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      23000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      23250,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      23500,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      23750,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      24000,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xBD}  , { 0x1 , 0xA8} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

LTE_MIPI_TPC_SECTION_TABLE_T LTE_Band41_MIPI_BYPASS_PA_SECTION_DATA_Set2[LTE_MIPI_SUBBAND_NUM_PER_DATA] =
{
   /*8714 KHz*/
   {
      24960,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8764 KHz*/
   {
      25445,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8784 KHz*/
   {
      25930,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8804 KHz*/
   {
      26415,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },

      /*8916 KHz*/
   {
      26900,/*100kHz*/
      MIPI_USID_PA1,/*USID*/
      {
         // PAEn=1
         //PA_SEC_DATA0, PA_SEC_DATA1, PA_SEC_DATA2,...
         {{ { 0x0 , 0x3D}  , { 0x1 , 0x60} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x4D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x70} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x5D}  , { 0x1 , 0x80} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x6D}  , { 0x1 , 0x90} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x7D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x9D}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0xAD}  , { 0x1 , 0xA7} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},
         {{ { 0x0 , 0x00}  , { 0x1 , 0x00} , { 0x0 , 0x00} , { 0x0 , 0x0} , { 0x0 , 0x0}}},//SRS
      }
   },
};

kal_uint32  LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE_Set2[] =
{
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),    // !!!DON'T MODIFY!!! 
      sizeof(LTE_Band38_MIPI_BYPASS_PA_SECTION_DATA_Set2),    // Band_ind=0         
      sizeof(LTE_Band40_MIPI_BYPASS_PA_SECTION_DATA_Set2),    // Band_ind=1         
      sizeof(LTE_Band41_MIPI_BYPASS_PA_SECTION_DATA_Set2),    // Band_ind=2         
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),    // Band_ind=3         
      sizeof(LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA),    // Band_ind=4         
};

LTE_MIPI_TPC_SECTION_TABLE_T*  LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_Set2[] =
{
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // !!!DON'T MODIFY!!!      
      LTE_Band38_MIPI_BYPASS_PA_SECTION_DATA_Set2,   // Band_ind=0              
      LTE_Band40_MIPI_BYPASS_PA_SECTION_DATA_Set2,   // Band_ind=1              
      LTE_Band41_MIPI_BYPASS_PA_SECTION_DATA_Set2,   // Band_ind=2              
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // Band_ind=3              
      LTE_BandNone_MIPI_BYPASS_PA_SECTION_DATA,   // Band_ind=4              
};
