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
/******************************************************************************
 * Filename:
 * --------------------------------------------------------
 *   scsi.h
 *
 * Project:
 * --------------------------------------------------------
 *   MONZA
 *
 * Description:
 * --------------------------------------------------------
 *   Implementation of Scsi class.
 *
 * Author:
 * --------------------------------------------------------
 * -------
 *
 * --------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 * 
 * 09 26 2012 ye.yuan
 * removed!
 * CSCE CODE Interface part .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * UARFCN validation function refactor (from URR to SCSI)
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * removed!
 * removed!
 * Add copyright header.
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *****************************************************************************/
/**
 * scsi.h
 * 
 * # @COPYLEFT 2005 Jethro E. Lee
 * ALL WRONGS RESERVED
 * 
 * [Useage]
 * 
 * [SYNOPSIS]
 * 
 * [Example]
 */

#ifndef __SCSI_H__	/* _(!@$ `scsi.h' $@!)_ */
#define __SCSI_H__

/* Nicky 20101008: include header files for redundant header file removal */
#include "kal_general_types.h"
#include "scsi_asn.h"    
#include "csi_asn.h"     
#include "mcd_l3_inc_struct.h"
#ifdef __GSM_RAT__
#include "csi_gsm_asn.h" 
#endif
#ifdef __UMTS_RAT__
#include "csi_umts_asn.h"
#endif
#ifdef __LTE_RAT__
#include "csi_lte_asn.h"
#endif


#define SCSI_SIM_EF_LOCI_LEN                    (11)
#define SCSI_USIM_EF_LOCI_LEN                   (11)
#define SCSI_USIM_EF_PSLOCI_LEN                 (14)

/** 
 * UTRAN Absolute Radio Frequency Channel Number 
 *  
 * UTRAFDD is designed to operatein either of the  
 * following paired bands: 
 *            1920-1980 MHz Uplink 
 *            2110-2170 MHz Downlink 
 *  
 * UARFCN Uplink:           9612- 9888 
 * UARFCN Downlink:         10562-10838 
 */
#ifdef __LTE_RAT__
#define SCSI_MAX_EARFCN                         (65535)
#endif /* __LTE_RAT__ */
#define SCSI_MAX_UARFCN                         (16383)
#define SCSI_PRIMARY_SCRAMBLING_CODE_MAX           (511)
#define SCSI_CELL_PARAMETERS_ID_MAX       (127)

/* Clause 2 of SPEC 05.05 */
#define SCSI_MAX_GSM_ARFCN                      (1024)

#define SCSI_GSM_CELL_INFORMATION_TAG           (0xA0)
#define SCSI_FDD_CELL_INFORMATION_TAG           (0xA1)
#define SCSI_TDD_CELL_INFORMATION_TAG           (0xA2)
#define SCSI_GSM_CAMPED_BCCH_FREQUENCY_TAG              (0x80)
#define SCSI_GSM_NEIGHBOUR_BCCH_FREQUENCY_TAG           (0x81)
#define SCSI_INTRA_FREQUENCY_INFORMATION_TAG        (0x80)
#define SCSI_INTER_FREQUENCY_INFORMATION_TAG        (0x81)
#define SCSI_UNITIALIZED_USIM_DATA                      (0xFF)

typedef enum {
    SCSI_SIM1 = 0,
    SCSI_SIM2,
    SCSI_SIM3,
    SCSI_SIM4,
    SCSI_SIM_INVALID
}SCSI_SIM_INDEX;

#ifdef __UMTS_RAT__

/**
 *  Lucien Huang 20081218:
 *    Please be sure that the following definition shall be matched with
 *    those in rrc_utils.h (same definition could be seen there)
 **/

#ifdef __UMTS_FDD_MODE__
#define SCSI_TOTAL_NUMBER_OF_UMTS_BAND_DEFINED      (22)
#define SCSI_MAX_NUM_OF_UMTS_BAND_SUPPORTED         (22)
#define SCSI_MAX_NUM_OF_UMTS_BAND_ADDITION_INFO     (6) /* For UMTS FDD BAND V only */

enum SCSI_UMTS_BAND_UARFCN_IDENTIFIER_TAG
{
    SCSI_UMTS_FDD_UARFCN_BAND_I_Identifier = 0,
    SCSI_UMTS_FDD_UARFCN_BAND_II_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_III_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_IV_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_V_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_VI_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_VII_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_VIII_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_IX_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_X_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_XI_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_XII_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_XIII_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_XIV_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_XV_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_XVI_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_XVII_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_XVIII_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_XIX_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_XX_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_XXI_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_XXII_Identifier,
    SCSI_UMTS_FDD_UARFCN_BAND_INVALID
};
#endif /* __UMTS_FDD_MODE__ */


#ifdef __UMTS_TDD128_MODE__
#define SCSI_TOTAL_NUMBER_OF_UMTS_BAND_DEFINED      (6)
#define SCSI_MAX_NUM_OF_UMTS_BAND_SUPPORTED         (6)
#define SCSI_MAX_NUM_OF_UMTS_BAND_ADDITION_INFO     (1) /* TDD doesn't use this part */

enum SCSI_UMTS_BAND_UARFCN_IDENTIFIER_TAG
{
    SCSI_UMTS_TDD_UARFCN_BAND_A_Identifier,
    SCSI_UMTS_TDD_UARFCN_BAND_B_Identifier,
    SCSI_UMTS_TDD_UARFCN_BAND_C_Identifier,
    SCSI_UMTS_TDD_UARFCN_BAND_D_Identifier,
    SCSI_UMTS_TDD_UARFCN_BAND_E_Identifier,
    SCSI_UMTS_TDD_UARFCN_BAND_F_Identifier,
    SCSI_UMTS_TDD_UARFCN_BAND_INVALID
};
#endif  /* __UMTS_TDD128_MODE__ */

typedef enum SCSI_UMTS_BAND_UARFCN_IDENTIFIER_TAG SCSI_UMTS_Band_UARFCN_Identifier;

#ifdef __UMTS_FDD_MODE__
#define SCSI_MAX_OVERLAPPING_BANDS                  (3)

typedef struct {
    kal_uint8 numUarfcn;
    CsiUarfcn overlappingUarfcn[SCSI_MAX_OVERLAPPING_BANDS];
    SCSI_UMTS_Band_UARFCN_Identifier overlappingBand[SCSI_MAX_OVERLAPPING_BANDS];
} SCSI_UMTS_overlapping_band_info_struct;
#endif /* __UMTS_FDD_MODE__ */

typedef enum
{
   SCSI_RRC_UE_PowerClassExt_class1,
   SCSI_RRC_UE_PowerClassExt_class2,
   SCSI_RRC_UE_PowerClassExt_class3,
   SCSI_RRC_UE_PowerClassExt_class4,
   SCSI_RRC_UE_PowerClassExt_spare4,
   SCSI_RRC_UE_PowerClassExt_spare3,
   SCSI_RRC_UE_PowerClassExt_spare2,
   SCSI_RRC_UE_PowerClassExt_spare1
}
SCSI_RRC_UE_PowerClassExt;

typedef enum
{
    SCSI_UMTS_UARFCN_DL,
    SCSI_UMTS_UARFCN_UL
}SCSI_UMTS_UarfcnDirectionType;

typedef struct SCSI_UMTS_BAND_UARFCN_ADDITION_SPECIAL_INFO_TAG SCSI_UMTS_Band_UARFCN_Addition_Special;

struct SCSI_UMTS_BAND_UARFCN_ADDITION_SPECIAL_INFO_TAG
{
    kal_uint8     addition_number;
    kal_uint16    uarfcn[SCSI_MAX_NUM_OF_UMTS_BAND_ADDITION_INFO];
};

typedef struct SCSI_UMTS_BAND_UARFCN_ADDITION_GENERAL_INFO_TAG SCSI_UMTS_Band_UARFCN_Addition_General;

struct SCSI_UMTS_BAND_UARFCN_ADDITION_GENERAL_INFO_TAG
{
    kal_uint16    addition_start;
    kal_uint8     addition_number;
};

enum SCSI_UMTS_BAND_UARFCN_ADDITION_TYPE_TAG
{
    SCSI_UMTS_BAND_UARFCN_ADDITION_None_Selector,
    SCSI_UMTS_BAND_UARFCN_ADDITION_GENERAL_Selector,
    SCSI_UMTS_BAND_UARFCN_ADDITION_SPECIAL_Selector
};

typedef enum SCSI_UMTS_BAND_UARFCN_ADDITION_TYPE_TAG SCSI_UMTS_Band_UARFCN_AdditionType;

typedef struct SCSI_UMTS_BAND_UARFCN_CHECK_INFO_TAG SCSI_UMTS_BandCheckInfo;

#if 0 /*__3GPP_25102_DEFINITION__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

struct SCSI_UMTS_BAND_UARFCN_CHECK_INFO_TAG
{
#if 0 /*__3GPP_25102_DEFINITION__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    kal_uint16                               low_bound;
    kal_uint16                               upper_bound;
    SCSI_UMTS_Band_UARFCN_AdditionType    selection;
    union
    {
        kal_uint8                                  none;
        SCSI_UMTS_Band_UARFCN_Addition_General  general;
        SCSI_UMTS_Band_UARFCN_Addition_Special  special;
    }choice;
};

struct SCSI_UMTS_BAND_INFO_TAG
{
    SCSI_UMTS_Band_UARFCN_Identifier  radioFrequencyBand;
    SCSI_RRC_UE_PowerClassExt            ue_PowerClass;
    kal_uint16                           txRxFrequencySeparation; /* in UARFCN */
    SCSI_UMTS_BandCheckInfo           uarfcn_check_info;
};

typedef struct SCSI_UMTS_BAND_INFO_TAG SCSI_UMTS_BandInfo;

typedef struct SCSI_UMTS_BAND_INFO_LIST_TAG SCSI_UMTS_BandInfoList;

struct SCSI_UMTS_BAND_INFO_LIST_TAG
{
    kal_uint8                            band_number; /* number of UMTS FDD working band */
    SCSI_UMTS_Band_UARFCN_Identifier  band_index[SCSI_MAX_NUM_OF_UMTS_BAND_SUPPORTED]; /* list of enum of UMTS FDD working band */
};

typedef struct SCSI_UMTS_BAND_INFO_DEFINED_TAG SCSI_UMTS_BandInfoDefinedList;

struct SCSI_UMTS_BAND_INFO_DEFINED_TAG
{
    SCSI_UMTS_BandInfo         band_info[SCSI_TOTAL_NUMBER_OF_UMTS_BAND_DEFINED];
};


/*
 * Chi-Chung 20090715:
 *    Code revised for frequencyRepository.  This is the structure for user to get the uarfcn in a MCC
 */
#define MAX_UARFCN_PER_MCC 32
    
/* the uarfcn in a Mcc*/
typedef struct SCSI_UMTS_UarfcnPerMcc
{
    ScsiMccValue mcc;
    kal_uint8 count;
    CsiUarfcn uarfcn[MAX_UARFCN_PER_MCC];
}
SCSI_UMTS_UarfcnPerMcc;

extern void Scsi_ComposeUmtsBandDefinitionInfo(void);

extern void Scsi_SE_retrieveUmtsBandListInfo(SCSI_SIM_INDEX sim_index, SCSI_UMTS_BandInfoList **ppScsi_StoredUmtsFddBandListInfo);

extern void Scsi_retrieveUmtsBandDefinedInfo(SCSI_UMTS_BandInfoDefinedList **ppScsi_StoreUmtsFddBandDefinedInfo);

extern kal_bool Scsi_SE_ensureUarfcnValid(SCSI_SIM_INDEX sim_index, kal_uint16 uarfcn);

/****************************************************************************
 *    Function:    Scsi_UarfcnValidateInAllUmtsBand
 *
 *    parameter: 
 *      a. uarfcn - uarfcn which we want to check the validation
 *      b. type - indicate to perform DL or UL UARFCN validation
 *      c. band_id - store which band the input uarfcn locates if return KAL_TRUE
 *                   meaningless if return KAL_FALSE or input band_id is NULL pointer
 *    Returns:
 *      a. return KAL_TRUE means input uarfcn is in valid range
 *      b. *band_id will store the band number which this uarfcn locates if band_id is not NULL pointer
 *
 *    Description:
 *      Envoked for check whether the input uarfcn is in the valid value range which 3GPP defines for
 *      whole UMTS FDD bands. Currently it will check Band I - X.
 *
 *****************************************************************************/

extern kal_bool Scsi_UarfcnValidateInAllUmtsBand(kal_uint16 uarfcn, SCSI_UMTS_UarfcnDirectionType type, SCSI_UMTS_Band_UARFCN_Identifier *band_id);

extern kal_bool Scsi_SE_UarfcnValidateInAllSupportUmtsBand(SCSI_SIM_INDEX sim_index, kal_uint16 uarfcn, SCSI_UMTS_UarfcnDirectionType type, SCSI_UMTS_Band_UARFCN_Identifier *band_id);

extern kal_bool Scsi_UarfcnValidateInOneSupportUmtsBand(kal_uint16 uarfcn, SCSI_UMTS_UarfcnDirectionType type, SCSI_UMTS_Band_UARFCN_Identifier band_id);

#ifdef __UMTS_FDD_MODE__
extern kal_bool Scsi_SE_UarfcnValidateInAllSupportUmtsBandExt(SCSI_SIM_INDEX sim_index, kal_uint16 uarfcn, SCSI_UMTS_UarfcnDirectionType type, SCSI_UMTS_Band_UARFCN_Identifier *band_id, kal_uint8 *indexInBandFDDList);
#endif

extern kal_uint8 Scsi_SE_GetNumOfUmtsSupportBand(SCSI_SIM_INDEX sim_index);

extern void Scsi_SE_GetUmtsSupportBandInfo(SCSI_SIM_INDEX sim_index, SCSI_UMTS_BandInfoList const **workBandInfo);

extern void Scsi_SE_RequiredUmtsBandListQuery(SCSI_SIM_INDEX sim_index, kal_uint8 *query_array);

extern kal_bool Scsi_SE_IsUmtsSupportBand(SCSI_SIM_INDEX sim_index, SCSI_UMTS_Band_UARFCN_Identifier band_id);

#endif /* __UMTS_RAT__ */

#ifdef __LTE_RAT__
#define MAX_BYTE_LTE_BAND_BITMASK 8

typedef struct SCSI_LTE_Band_Bitmask
{
    kal_uint8 oneByteBandBitmask[MAX_BYTE_LTE_BAND_BITMASK];
}
SCSI_LTE_Band_Bitmask;
#endif /* __LTE_RAT__ */

#if (defined(__23G_PRI_RESEL_SUPPORT__) || defined(__3G_CSG_SUPPORT__) || defined(__LTE_RAT__))
#define SCSI_MAX_TICKS 0xFFFFFFFF

typedef enum {
    SCSI_GSM_RAT,
    SCSI_UMTSFDD_RAT,
    SCSI_UMTSTDD_RAT,
    SCSI_LTE_RAT
}SCSI_RAT_MODE_TYPE;
#endif /* defined(__23G_PRI_RESEL_SUPPORT__) || defined(__3G_CSG_SUPPORT__) || defined(__LTE_RAT__) */

#if (defined(__23G_PRI_RESEL_SUPPORT__) || defined(__LTE_RAT__))
//Dedicated Priority Info
#define SCSI_MAX_NUM_OF_PRIO_INFO 17
#define SCSI_MAX_BYTE_OF_GSM_PRIO_ARFCN  128    // bitmask, total 128 bytes.
#define SCSI_MAX_NUM_OF_UMTSFDD_PRIO_UARFCN  32 // 32 frequency.
#define SCSI_MAX_NUM_OF_UMTSTDD_PRIO_UARFCN  32 // 32 frequency.
#define SCSI_MAX_NUM_OF_LTE_PRIO_EARFCN  32 // 32 frequency

typedef struct{
  kal_int8       priority;
  SCSI_RAT_MODE_TYPE  rat_choice;
  kal_uint8      freq_count;         // only used in 3G or LTE type, it keeps the frequency count
  kal_uint8      gsm_band_indicator; //refer to te_gsm_band_indicator in uas_gas_enums.h
  /**
   * for GSM RAT, every bit represenet a ARFCN (from 0~1023); LSB of octet 1 represent arfcn = 0, MSB of octet 1 represent arfcn = 7
   * for UMTSFDD, every U16 element represent an UARFCN.
   * for LTE,     every U16 element represent an EARFCN.
   **/
  union{
    kal_uint8  *ARFCN_bitmap; // SCSI_MAX_BYTE_OF_GSM_PRIO_ARFCN
    kal_uint16 *UARFCN_list;  // SCSI_MAX_NUM_OF_UMTSFDD_PRIO_UARFCN <== each of them is two bytes.
    kal_uint16 *EARFCN_list; // SCSI_MAX_NUM_OF_LTE_PRIO_EARFCN <== each of them is two bytes.
  }choice;
} SCSI_layer_prio_struct;

typedef struct{
  plmn_id_struct            rplmn;
  SCSI_RAT_MODE_TYPE        dedi_prio_info_src;
  kal_uint8                 layer_prio_count;
  SCSI_layer_prio_struct    layer_prio_list[SCSI_MAX_NUM_OF_PRIO_INFO];

  kal_uint32                tick_previous; // SCSI internal use
  kal_uint32                tick_left;     // SCSI internal use
} SCSI_dedi_prio_info;
#endif /* __23G_PRI_RESEL_SUPPORT__ || __LTE_RAT__ */


#if (defined(__3G_CSG_SUPPORT__) || defined(__LTE_RAT__))
//CSG Split Info
#define SCSI_MAX_NUM_OF_CSG_SPLIT_INFO  3   //the value cannot be equal to zero which 'wrap around' will happen in SCSI_newCSGSplitInfo().
#define SCSI_MAX_BYTE_OF_PHY_CELL_ID       64    // bitmask, total 64 bytes.
#define SCSI_MAX_NUM_OF_MULTI_PLMN   6

typedef struct{
  kal_uint8      plmn_count;
  plmn_id_struct plmn[SCSI_MAX_NUM_OF_MULTI_PLMN];
  kal_uint16     arfcn;
  kal_uint8      phyCellId_bitmap[SCSI_MAX_BYTE_OF_PHY_CELL_ID]; //every bit represenet a PSC (from 0~512); LSB of octet 1 represent psc = 0, MSB of octet 1 represent psc = 7

  kal_uint32     tick_previous; // SCSI internal use
  kal_uint32     tick_left;     // SCSI internal use
} SCSI_csg_split_info;


typedef struct{
  kal_uint8           list_count;
  SCSI_csg_split_info split_info_list[SCSI_MAX_NUM_OF_CSG_SPLIT_INFO];
}SCSI_csg_split_info_list;

#endif /* __3G_CSG_SUPPORT__ || __LTE_RAT__ */


// Constructor
extern void Scsi_Scsi(void);
extern void Scsi_reset(void);


// Initializer
extern void Scsi_initFromNVRAM(kal_uint8* nvramEfNetparBufPtr, kal_uint16 const nvramEfNetparBufLen);

extern kal_bool Scsi_isNvramInitialized(void);

#ifdef __GSM_RAT__
/* Jethro: Suppose SIM is able to be handled in all cases, regardless the load is dual mode or single mode. */
extern void Scsi_initFromSIM(plmn_id_struct const* const rPlmnId, 
                                CsiGsmCellList const* const gsmCellList);
#endif /* __GSM_RAT__ */

#ifdef __UMTS_RAT__      /* 3G is to be built-in */
extern void Scsi_initFromUSIM(plmn_id_struct const* const rPlmnId, 
                                CsiUmtsCellList* const umtsCellList
#ifdef __GSM_RAT__
                                , 
                                CsiGsmCellList const* const gsmCellList
#endif
                                );

extern void Scsi_FreqRepositoryInitFromNVRAM(kal_uint8* nvramEfNetparBufPtr, kal_uint16 const nvramEfNetparBufLen);
extern kal_uint16 Scsi_getNvramEFUmtsFreq(kal_uint8* const nvramEfNetparBufPtr, kal_uint16 const nvramEfNetparBufLen);
extern void Scsi_freqPurge(void);
#endif      /* #ifdef __UMTS_RAT__ */

extern void Scsi_purge(void);

// Destructor
extern void Scsi_destruct(void);


#ifdef __GSM_RAT__      /* 2G is to be built-in */
// GSM
// Setter
extern void Scsi_newGsmFreqRange(plmn_id_struct const* const plmnID, CsiGsmBaRangeAndBand* const BARangeList);
extern void Scsi_newGsmNeighborCells(plmn_id_struct const* const plmnID, CsiGsmCellList* const cellList);
#ifdef __LTE_RAT__
extern void Scsi_newGsmLatestServingCell(plmn_id_struct const* const plmnID, CsiGsmCell const* const cell);

//Just for UT currently, not release publicly
#ifdef UNIT_TEST
extern void Scsi_delGsmLatestServingCell(plmn_id_struct const* const plmnID);
#endif /* UNIT_TEST */
#endif /* __LTE_RAT__ */

// Getter
extern void Scsi_getGsmFreqRange(plmn_id_struct const* const plmnID, CsiGsmBaRangeAndBand* const BARangeList);
extern void Scsi_getGsmNeighborCells(plmn_id_struct const* const plmnID, CsiGsmCellList* const cellList);
#ifdef __LTE_RAT__
extern kal_bool Scsi_getGsmLatestServingCell(plmn_id_struct const* const plmnID, CsiGsmCell* const cell);
#endif /* __LTE_RAT__ */
#endif      /* #ifdef __GSM_RAT__ */


#ifdef __UMTS_RAT__      /* 3G is to be built-in */
// UMTS
/* David 20081107:
 * Added for auto band mechanism.
 */
#ifdef __3G_AUTO_BAND_MECHANISM__
extern void Scsi_newUmtsWorkingBand(plmn_id_struct const* const plmnID, SCSI_UMTS_Band_UARFCN_Identifier bandID);
extern void Scsi_delUmtsWorkingBand(plmn_id_struct const* const plmnID, SCSI_UMTS_Band_UARFCN_Identifier bandID);
#endif
// Setter
extern void Scsi_newUmtsFreqRange(plmn_id_struct const* const plmnID, CsiUmtsFrequnecyList* const freqRange);

#ifdef __UMTS_FDD_MODE__
extern void Scsi_newUmtsFreqList(plmn_id_struct const* const plmnID, CsiUmtsFrequnecyList* const freqList, kal_bool correctOverlappingUarfcn);
#endif /* __UMTS_FDD_MODE__ */
#ifdef __UMTS_TDD128_MODE__
extern void Scsi_newUmtsFreqList(plmn_id_struct const* const plmnID, CsiUmtsFrequnecyList* const freqList);
#endif /* __UMTS_TDD128_MODE__ */

extern void Scsi_newUmtsNeighborCells(plmn_id_struct const* const plmnID, CsiUmtsCellList* const cellList);
#ifdef __LTE_RAT__
extern void Scsi_newUmtsLatestServingCell(plmn_id_struct const* const plmnID, CsiUmtsCellWithUarfcn const* const cell);

//Just for UT currently, not release publicly
#ifdef UNIT_TEST
extern void Scsi_delUmtsLatestServingCell(plmn_id_struct const* const plmnID);
#endif /* UNIT_TEST */
#endif /* __LTE_RAT__ */

extern void Scsi_newUmtsUarfcnList(plmn_id_struct const* const plmnID , CsiUmtsUarfcnList *uarfcnList);

// Getter
extern void Scsi_getUmtsFreqRange(plmn_id_struct const* const plmnID, CsiUmtsFrequnecyList* const freqRange);
extern void Scsi_getUmtsFreqList(plmn_id_struct const* const plmnID, CsiUmtsFrequnecyList* const freqList);
extern void Scsi_getUmtsNeighborCells(plmn_id_struct const* const plmnID, CsiUmtsCellList* const cellList);
#ifdef __LTE_RAT__
extern kal_bool Scsi_getUmtsLatestServingCell(plmn_id_struct const* const plmnID, CsiUmtsCellWithUarfcn* const cell);
#endif /* __LTE_RAT__ */
extern void Scsi_getUmtsUarcnList(plmn_id_struct const* const plmnID, CsiUmtsUarfcnList *uarfcnList);
extern void Scsi_getUmtsUarfcnByMcc(kal_uint32 const countOfMccs , SCSI_UMTS_UarfcnPerMcc* uarfcnByMccs);
/* Nicky 20110103: Added for Gemini 2.0 */
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
extern kal_uint16 Scsi_getUmtsUarfcnUpperBound(SCSI_UMTS_Band_UARFCN_Identifier bandID);
extern kal_uint16 Scsi_getUmtsUarfcnLowerBound(SCSI_UMTS_Band_UARFCN_Identifier bandID);
extern kal_uint8 Scsi_getUmtsAdditionalFreqList(SCSI_UMTS_Band_UARFCN_Identifier bandID, kal_uint8 const sizeOfList, kal_uint16 * const additionalFreqList);
#endif      /* #ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */

/* Nicky 20111028: Added for UMTS Band Extension, which will be used by RRCE module. */
extern kal_uint16 Scsi_getBandTxRxFreqSeparation(SCSI_UMTS_Band_UARFCN_Identifier bandID);

#ifdef __UMTS_FDD_MODE__
extern kal_bool Scsi_convertUarfcnForOverlappedFreqBands(kal_uint16 uarfcn, SCSI_UMTS_Band_UARFCN_Identifier bandId, SCSI_UMTS_Band_UARFCN_Identifier otherBandId, kal_uint16 *convertedUarfcn);
#endif /* __UMTS_FDD_MODE__ */
#endif      /* #ifdef __UMTS_RAT__ */

extern kal_uint8 Scsi_getPlmns(plmn_id_struct* plmns);

// Retrieve encoded data for saving to non-volatile storages, i.e., NVRAM and USIM/SIM.
extern kal_uint16 Scsi_getNvramEFNetpar(kal_uint8* const nvramEfNetparBufPtr, kal_uint16 const nvramEfNetparBufLen);

#if (defined(__23G_PRI_RESEL_SUPPORT__) || defined(__LTE_RAT__))
// SCSI need to provide the following functions:

// Before use any API of DediPrioInfo, please call this function to acquire mutext.
extern void SCSI_acquirePrioMutex(SCSI_SIM_INDEX sim_index);

// return the pointer of pDediPrioInfo.
// user can operate on SCSI_dedi_prio_info, but user shall not operate on tick_previous. tick_previous would be updated by SCSI.
extern SCSI_dedi_prio_info *SCSI_getDediPrioInfo(SCSI_SIM_INDEX sim_index);

// free the memory of pDediPrioInfo, after user call this function, please never use the previous-got memory...So please be careful.
extern void SCSI_freeDediPrioInfo(SCSI_SIM_INDEX sim_index);

// call SCSI_FreeDediPrioInfo to free previous-put memory in pDediPrioInfo, and then put the point address in pDediPrioInfo.
// please never use the previous-got memory...So please careful.
// Besides, update the tick_previous by SCSI. User would not update it.
extern void SCSI_setDediPrioInfo(SCSI_SIM_INDEX sim_index, kal_uint32 tick_left, SCSI_dedi_prio_info *pDediPrio);

// In this function, please check the left_tick and do correct computing. If expired, please free the pDediPrioInfo and set it NULL.
extern void SCSI_releasePrioMutex(SCSI_SIM_INDEX sim_index);
#endif /* __23G_PRI_RESEL_SUPPORT__ || __LTE_RAT__ */

#if (defined(__3G_CSG_SUPPORT__) || defined(__LTE_RAT__))
// put the pSlitInfo which contain this arfcn in pSplitInfo according to rat_type, if not found, set content of pSplitInfo all zero.
// besides, according to tick_left tick_previous to delete the expired split info.
extern void SCSI_getCSGSplitInfo(SCSI_SIM_INDEX sim_index, kal_uint16 arfcn, plmn_id_struct const* const plmnID, SCSI_RAT_MODE_TYPE rat_type, SCSI_csg_split_info * const pSplitInfo);

// put the content of pCSGSplitInfoList in SCSI to pSplitInfoList according to rat_type, if pCSGSplitInfoList is null, set content of pSplitInfoList all zero.
// besides, according to tick_left tick_previous to delete the expired split info.
extern void SCSI_getCSGSplitInfoList(SCSI_SIM_INDEX sim_index, SCSI_RAT_MODE_TYPE rat_type, SCSI_csg_split_info_list * const pSplitInfoList);


// If found the same frequecny replace it, else allocate one memory and put the SCSI_csg_split_info in the CSGSplitInfo according to rat_type.
// besides, according to tick_left tick_previous to delete the expired split info.
extern void SCSI_newCSGSplitInfo(SCSI_SIM_INDEX sim_index, kal_uint32 tick_left, SCSI_RAT_MODE_TYPE rat_type, SCSI_csg_split_info const * const pSplitInfo);

#endif /* __3G_CSG_SUPPORT__ || __LTE_RAT__ */

/*Multi-Mode******************************************************************/
#ifdef __GSM_RAT__
extern void Scsi_SE_ComposeGsmBandBitmask(SCSI_SIM_INDEX sim_index, kal_uint8 GBandBitmask);

extern void Scsi_SE_retrieveGsmBandBitmask(SCSI_SIM_INDEX sim_index, kal_uint8 *pGBandBitmask);
#endif /* __GSM_RAT__ */
#ifdef __UMTS_RAT__
extern void Scsi_SE_ComposeUmtsBandBitmask(SCSI_SIM_INDEX sim_index, kal_uint32 UBandBitmask);

extern void Scsi_SE_retrieveUmtsBandBitmask(SCSI_SIM_INDEX sim_index, kal_uint32 *pUBandBitmask);
#endif /* __UTMS_RAT__ */
#ifdef __LTE_RAT__
extern void Scsi_SE_ComposeLteBandBitmask(SCSI_SIM_INDEX sim_index, SCSI_LTE_Band_Bitmask LBandBitmask);

extern void Scsi_SE_retrieveLteBandBitmask(SCSI_SIM_INDEX sim_index, SCSI_LTE_Band_Bitmask *pLBandBitmask);
#endif /* __LTE_RAT__ */

#ifdef __LTE_RAT__
extern void Scsi_newLteFreqList(plmn_id_struct const* const plmnID, CsiLteFrequencyList* const freqList);

extern void Scsi_getLteFreqList(plmn_id_struct const* const plmnID, CsiLteFrequencyList* const freqList);
#endif /* __LTE_RAT__ */

#if (defined(__3G_CSG_SUPPORT__) || defined(__LTE_RAT__))
extern void Scsi_prevVisitedCellInitFromNVRAM(kal_uint8* nvramEfPrevVisitedCellBufPtr, kal_uint16 const nvramEfPrevVisitedCellBufLen);

extern kal_uint16 Scsi_getNvramEFPrevVisitedCell(kal_uint8* const nvramEfPrevVisitedCellBufPtr, kal_uint16 const nvramEfPrevVisitedCellBufLen);

extern void Scsi_prevVisitedCellPurge(void);

extern void Scsi_newPrevVisitedCell(plmn_id_struct const* const plmnID, ScsiPrevVisitedCell * prevVisitedCell);

extern void Scsi_delPrevVisitedCellGivenPlmnAndCsg(plmn_id_struct const* const plmnID, CsiCsgId const csgID);

extern void Scsi_getPrevVisitedCellListByPlmn(plmn_id_struct const* const plmnID, ScsiPrevVisitedCellList * const prevVisitedCellList);

extern kal_bool Scsi_isPrevVisitedCellExistedGivenPlmnAndCsg(plmn_id_struct const* const plmnID, CsiCsgId const csgID);

#endif /* __3G_CSG_SUPPORT__ || __LTE_RAT__ */
/*Multi-Mode******************************************************************/

#ifdef UNIT_TEST
extern void Scsi_initFromNvramUnitTesting(void);
extern void Scsi_initFromNvramUnitTesting1(void);
extern void Scsi_initFromNvramUnitTesting2(void);
extern void Scsi_initFromNvramUnitTesting3(void);
#ifdef __UMTS_FDD_MODE__
extern void Scsi_initFromNvramUnitTestingForRplmnInfo(void);
//#ifdef __BAND_PRIORITY_SEARCH__
extern void Scsi_initFromNvramUnitTestingForBandPrioSearch(void);
//#endif /* __BAND_PRIORITY_SEARCH__ */
#endif
extern void Scsi_te(void);
#endif


#endif 				/* _(!@$ `scsi.h' $@!)_ */
