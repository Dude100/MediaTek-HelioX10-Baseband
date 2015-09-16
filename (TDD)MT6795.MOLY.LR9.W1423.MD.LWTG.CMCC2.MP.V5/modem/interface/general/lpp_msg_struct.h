/******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
*******************************************************************************/

/******************************************************************************
 * Filename:
 * --------------------------------------------------------
 *   lpp_msg_struct.h
 *
 * Project:
 * --------------------------------------------------------
 *   LTE project
 *
 * Description:
 * --------------------------------------------------------
 *   LTE Positioning Protocol - Message Structure Definition
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
 * 	.
 *
 * removed!
 * removed!
 * .
 *
 *
 *****************************************************************************/

#ifndef _LPP_MSG_STRUCT_H
#define _LPP_MSG_STRUCT_H

#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"

/*Always trun on LPP CP options for L1 stand alone build*/
//#if defined(__LPP_CP_SUPPORT__) || defined(__LPP_UP_SUPPORT__) || defined(__L1EDPS_ENABLE__)

#include "lpp_msg_enum.h"
#include "ps_public_struct.h"  /* for L4C SS struct */
#include "as2l4c_struct.h"     /* for L4CPS NBR cell info */
#include "mcd_l3_inc_struct.h" /* for PLMN id */
#include "l3_inc_enums.h"      /* for LCS/EMM enum */

/*****************************************************************************
 * Macros Without Parameters
 *****************************************************************************/


/*****************************************************************************
 * Macros With Parameters
 *****************************************************************************/


/*****************************************************************************
 * Enums without tags
 *****************************************************************************/


/*****************************************************************************
 * Type Definitions
 *****************************************************************************/

/* LPP -> ERRC */
/* This structure for MSG_ID_LPP_EL1_OTDOA_MEAS_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16  transactionID;
    kal_uint8   responseTime;     /* [1..128], unit in seconds, for EL1 knowing about how long it will take for OTDOA measurement, but LPP still controls the response timer */
} lpp_el1_otdoa_meas_req_struct;


typedef struct
{
   lpp_otdoa_prs_info_bandwidth_enum     prsBandwidth;
   kal_uint16                            prsConfigIndex;     /* [0..4095] */
   lpp_otdoa_prs_info_num_dl_frame_enum  numDLFrames;
   kal_bool                              prsMutingInfoValid;
   lpp_otdoa_prs_info_muting_po_enum     prsMutingInfoType;
   kal_uint16                            prsMutingInfoBits;  /* Position Occasion: PO-2: 2 bits, PO-4: 4 bits, PO-8: 8 bits, PO-16: 16 bits */
} lpp_otdoa_prs_info;


typedef struct
{
    kal_uint16          phyCellId;                 /* [0..503] */
    kal_bool            earfcnValid;               /* FALSE: indicate this is a intra-freq cell, EL1 should use current serving cell's earfcn; TRUE: indicate this is a inter-freq cell */
    kal_uint32          earfcn;                    /* [0..262143], 65535 is invalid to indicate ARFCN-ValueEUTRA-v9a0 present; LPP assign reference cell if received message IE does not present */
    kal_bool            isFourAntPortConfigValid;
    kal_bool            isFourAntPortConfig;       /* TRUE: 4 antenna ports for CRS are used in the assistance data reference cell, FALSE: 1 (or 2) antenna port(s) */
    kal_bool            isCPLengthExtended;        /* TRUE: cyclic prefix length of PRS or CRS is extended, FALSE: cyclic prefix length is normal */
    kal_bool            prsInfoValid;
    lpp_otdoa_prs_info  prsInfo;
} lpp_otdoa_ref_cell_info_struct;


typedef struct
{
    kal_uint16          phyCellId;                 /* [0..503] */
    kal_bool            earfcnValid;               /* FALSE: indicate this is a intra-freq cell, EL1 should use current serving cell's earfcn; TRUE: indicate this is a inter-freq cell */
    kal_uint32          earfcn;                    /* [0..262143], 65535 is invalid to indicate ARFCN-ValueEUTRA-v9a0 present; LPP assign reference cell if received message IE does not present */
    kal_bool            isCPLengthExtendedValid;   /* only present when cyclic prefix length is not the same as reference cell */
    kal_bool            isCPLengthExtended;        /* TRUE: cyclic prefix length of PRS or CRS is extended, FALSE: cyclic prefix length is normal */
    kal_bool            isFourAntPortConfigValid;  /* only present when antenna port config is not the same as reference cell */
    kal_bool            isFourAntPortConfig;       /* TRUE: 4 antenna ports for CRS are used in the assistance data reference cell, FALSE: 1 (or 2) antenna port(s) */

    kal_bool            prsInfoValid;              /* only present when prs info is not the same as reference cell */
    lpp_otdoa_prs_info  prsInfo;

    kal_bool            slotNumberOffsetValid;     /* only present when slot timing is not the same as reference cell */
    kal_uint8           slotNumberOffset;          /* [0..19] */
    kal_bool            prsSubFrameOffsetValid;    /* only present when earfcn is not the same as reference cell */
    kal_uint16          prsSubFrameOffset;         /* [0..1279] */
    kal_uint16          expectedRSTD;              /* [0..16383] */
    kal_uint16          expectedRSTDUnc;           /* [0..1023] */
} lpp_otdoa_nbr_cell_info_struct;


typedef struct
{
    kal_uint8                       numCellInfo;
    lpp_otdoa_nbr_cell_info_struct  cellInfo[LPP_OTDOA_MAX_NBR_CELL_LIST_NUM];
} lpp_otdoa_nbr_cell_info_list_struct;


typedef struct
{
    kal_uint8                            numFreqInfo;
    lpp_otdoa_nbr_cell_info_list_struct  freqInfo[LPP_OTDOA_MAX_NBR_CELL_FREQ_LAYER_NUM];
}  lpp_otdoa_nbr_freq_info_list_struct;


/* This structure for MSG_ID_LPP_EL1_OTDOA_ASSIST_DATA_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                           transactionID;
    kal_bool                             refCellInfoValid;
    lpp_otdoa_ref_cell_info_struct       refCellInfo;
    kal_bool                             nbrCellInfoValid;
    lpp_otdoa_nbr_freq_info_list_struct  nbrCellInfo;
} lpp_el1_otdoa_assist_data_req_struct;


/* This structure for MSG_ID_LPP_EL1_OTDOA_MEAS_ABORT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16  transactionID;
} lpp_el1_otdoa_meas_abort_req_struct;


/* This structure for MSG_ID_LPP_EL1_OTDOA_RESET_UE_STORED_POS_INFO */
typedef struct
{
    LOCAL_PARA_HDR
    /* empty */
} lpp_el1_otdoa_reset_ue_stored_pos_info_struct;


/* This structure for MSG_ID_LPP_ERRC_ECID_MEAS_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16  transactionID;
    kal_bool    rsrpReq;
    kal_bool    rsrqReq;
    kal_bool    ueRxTxTimeDiffReq;
} lpp_errc_ecid_meas_req_struct;


/* This structure for MSG_ID_LPP_ERRC_ECID_MEAS_ABORT_REQ */
/* the conditions LPP will send abort request to ERRC:
 * (1) network abort ECID session or LPP protocol error
 * (2) ECID response timer expiry
 */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16  transactionID;
} lpp_errc_ecid_meas_abort_req_struct;


/* ERRC -> LPP */
/**
 *   error-Resolution 
 *   This field specifies the resolution R used in error-Value field. The encoding on two bits is as follows: 
 *        '00'            5 meters 
 *        '01'           10 meters 
 *        '10'           20 meters 
 *        '11'           30 meters. 
 *   
 *   error-Value 
 *   This field specifies the target device"s best estimate of the uncertainty of the OTDOA (or TOA) measurement. 
 *   The encoding on five bits is as follows: 
 *        '00000'     0    to   (R*1-1) meters 
 *        '00001'     R*1  to   (R*2-1) meters 
 *        '00010'     R*2  to   (R*3-1) meters 
 *        ¡K 
 *        '11111'     R*31  meters or more; 
 *   where R is the resolution defined by error-Resolution field.  
 *   e.g. , R=20 m corresponds to 0-19 m, 20-39 m,¡K,620+ m.  
 *
 *   error-NumSamples 
 *   If the error-Value field provides the sample uncertainty of the OTDOA (or TOA) measurement, this field specifies how 
 *   many measurements have been used by the target device to determine this (i.e., sample size). Following 3 bit 
 *   encoding is used: 
 *        "000"         Not the baseline metric 
 *        '001'         5-9 
 *        '010'         10-14 
 *        '011'         15-24 
 *        '100'         25-34 
 *        '101'         35-44 
 *        '110'         45-54 
 *        '111'         55 or more. 
 *   In case of the value "000", the error-Value field contains the target device"s best estimate of the uncertainty of the 
 *   OTDOA (or TOA) measurement not based on the baseline metric. E.g., other measurements such as signal-to-noise-
 *   ratio or signal strength can be utilized to estimate the error-Value. 
 *   If this field is absent, the value of this field is "000". 
 */
typedef struct
{
    kal_uint8  errResolution;     /* 2 bits, refer description as above */
    kal_uint8  errValue;          /* 5 bits, refer description as above */
    kal_bool   errSamplesValid;
    kal_uint8  errSamples;        /* 3 bits, refer description as above */
} lpp_otdoa_measured_quality_struct;


typedef struct
{
    kal_uint16                         phyCellId;
    kal_uint32                         earfcn;        /* [0..262143], 65535 is invalid to indicate ARFCN-ValueEUTRA-v9a0 present */
    kal_uint16                         rstd;          /* [0..12711], mapping refer to TS 36.133 table 9.1.10.3-1 */
    lpp_otdoa_measured_quality_struct  rstdQuality;
} lpp_otdoa_measured_nbr_cell_struct;


typedef struct
{
    kal_uint16                          sysFrameNumber;      /* 10 bits */
    kal_uint16                          refPhyCellId;        /* [0..503] */
    kal_uint32                          refEarfcn;           /* [0..262143], 65535 is invalid to indicate ARFCN-ValueEUTRA-v9a0 present */ 
    kal_bool                            refQualityValid;
    lpp_otdoa_measured_quality_struct   refQuality;
    kal_uint8                           numMeasuredNbrCell;
    lpp_otdoa_measured_nbr_cell_struct  measuredNbrCell[LPP_OTDOA_MAX_NBR_CELL_LIST_NUM];
}  lpp_otdoa_measured_info_struct;


/* This structure for MSG_ID_LPP_EL1_OTDOA_MEAS_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                      transactionID;
    lpp_otdoa_measured_info_struct  measurementResult;
} lpp_el1_otdoa_meas_cnf_struct;


/* This structure for MSG_ID_LPP_EL1_OTDOA_ASSIST_DATA_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16  transactionID;
} lpp_el1_otdoa_assist_data_cnf_struct;


/* This structure for MSG_ID_LPP_EL1_OTDOA_ADDITIONAL_ASSIST_DATA_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16  transactionID;   /* assoicated measurement transaction ID */
    kal_uint16  physCellId;      /* [0..503] */
} lpp_el1_otdoa_additional_assist_data_req_struct;


typedef struct
{
    kal_uint16      phyCellId;            /* [0..503] */
    kal_bool        plmnIdValid;
    plmn_id_struct  plmnId;
    kal_bool        cellIdValid;
    kal_uint32      cellId;               /* eutra 28 bits */
    kal_uint32      earfcn;               /* [0..262143], 65535 is invalid to indicate ARFCN-ValueEUTRA-v9a0 present */
    kal_bool        sysFrameNumberValid;
    kal_uint16      sysFrameNumber;       /* 10 bits */
    /* measured result */
    kal_bool        rsrpResultValid;
    kal_uint8       rsrpResult;           /* [0..97]  */
    kal_bool        rsrqResultValid;
    kal_uint8       rsrqResult;           /* [0..34] */
    kal_bool        ueRxTxTimeDiffValid;
    kal_uint16      ueRxTxTimeDiff;       /* [0..4095] */
} lpp_ecid_cell_measured_info_struct;


typedef struct
{
    /**
     * Please note that the interface here is more straight-forward than ECID-SignalMeasurementInformation IE of LPP Message:
     * when ERRC has measured primary cell, the result will place in primaryCellMeasuredResult;
     * (if serving (primary) cell is not present, the whole measured info should be ignored since result will be error)
     *
     * in addition to primary cell, if ERRC also measured neighbor cells, they will be put into the array of measuredCellResult[],
     * and the number of neighbor will specify in numMeasuredCellResult
     */
    lpp_ecid_cell_measured_info_struct  primaryCellMeasuredResult;
    kal_uint8                           numMeasuredCellResult;
    lpp_ecid_cell_measured_info_struct  measuredCellResult[LPP_ECID_MAX_MEASURED_CELL_INFO_NUM];
} lpp_ecid_measured_info_struct;


/* This structure for MSG_ID_LPP_ERRC_ECID_MEAS_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                     transactionID;
    lpp_loc_ecid_result_enum       result;
    lpp_ecid_measured_info_struct  measurementResult;
} lpp_errc_ecid_meas_cnf_struct;


/* LPP -> EMM (EVAL) */
/* This structure for MSG_ID_LPP_EVAL_DATA_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16  mui;
    /* for Additional Information IE of UL generic NAS transport */
    kal_uint8   addInfoLen;
    kal_uint8   *addInfo;
    /* raw data is in peer buffer */
} lpp_eval_data_req_struct;


/* This structure for MSG_ID_LPP_EVAL_DATA_IND */
typedef struct
{
    LOCAL_PARA_HDR
    /* for Additional Information IE of DL generic NAS transport */
    kal_uint8   addInfoLen;
    kal_uint8   *addInfo;
    /* raw data is in peer buffer */
} lpp_eval_data_ind_struct;


/* This structure for MSG_ID_LPP_EVAL_DATA_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    lcs_emm_status_enum  result;
    kal_uint16           mui;
} lpp_eval_data_cnf_struct;


/* This structure for MSG_ID_EVAL_LPP_NW_RESET_UE_STORED_POS_INFO_IND */
typedef struct
{
    LOCAL_PARA_HDR
    ue_pos_tech_enum  pos_tech;
} eval_lpp_nw_reset_ue_stored_pos_info_ind_struct;


//#endif  /* #if defined(__LPP_CP_SUPPORT__) || defined(__LPP_UP_SUPPORT__) || defined(__L1EDPS_ENABLE__) */

#endif /* _LPP_MSG_STRUCT_H */
