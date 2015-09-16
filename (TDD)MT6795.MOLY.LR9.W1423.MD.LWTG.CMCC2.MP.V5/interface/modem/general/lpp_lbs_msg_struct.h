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
 *   lpp_lbs_msg_struct.h
 *
 * Project:
 * --------------------------------------------------------
 *   LTE project
 *
 * Description:
 * --------------------------------------------------------
 *   LTE Positioning Protocol - LBS Message Structure Definition
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
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 *
 *****************************************************************************/

#ifndef _LPP_LBS_MSG_STRUCT_H
#define _LPP_LBS_MSG_STRUCT_H

#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"

#if defined(__LPP_CP_SUPPORT__) || defined(__LPP_UP_SUPPORT__)

/*****************************************************************************
 * Macros Without Parameters
 *****************************************************************************/
#define LPP_PEER_OTDOA_MAX_NBR_CELL_FREQ_LAYER_NUM   3   /* inherit LPP_OTDOA_MAX_NBR_CELL_FREQ_LAYER_NUM */
#define LPP_PEER_OTDOA_MAX_NBR_CELL_LIST_NUM        24   /* inherit LPP_OTDOA_MAX_NBR_CELL_LIST_NUM */

#define LPP_PEER_ECID_MAX_MEASURED_CELL_INFO_NUM    32   /* inherit LPP_ECID_MAX_MEASURED_CELL_INFO_NUM */

#define LPP_PEER_MAX_BANDS                          64   /* inherit LPP_MAX_BANDS */
/* Define of peerNbrCellBitmap*/
#define LPP_PEER_OTDOA_NBR_CELL_BIT_EARFCNVALID              0x80
#define LPP_PEER_OTDOA_NBR_CELL_BIT_ISCPLENGTHEXTENDEDVALID  0x40
#define LPP_PEER_OTDOA_NBR_CELL_BIT_ISCPLENGTHEXTENDED       0x20
#define LPP_PEER_OTDOA_NBR_CELL_BIT_ISFOURANTPORTCONFIGVALID 0x10
#define LPP_PEER_OTDOA_NBR_CELL_BIT_ISFOURANTPORTCONFIG      0x08
#define LPP_PEER_OTDOA_NBR_CELL_BIT_PRSINFOVALID             0x04
#define LPP_PEER_OTDOA_NBR_CELL_BIT_SLOTNUMBEROFFSETVALID    0x02
#define LPP_PEER_OTDOA_NBR_CELL_BIT_PRSSUBFRAMEOFFSETVALID   0x01
/*****************************************************************************
 * Macros With Parameters
 *****************************************************************************/
/*Macros for peerNbrCellBitmap*/
#define LPP_PEER_OTDOA_NBR_CELL_GET_EARFCNVALID(pPeerNbr)              (((pPeerNbr)->peerNbrCellBitmap & LPP_PEER_OTDOA_NBR_CELL_BIT_EARFCNVALID             )? KAL_TRUE : KAL_FALSE)
#define LPP_PEER_OTDOA_NBR_CELL_GET_ISCPLENGTHEXTENDEDVALID(pPeerNbr)  (((pPeerNbr)->peerNbrCellBitmap & LPP_PEER_OTDOA_NBR_CELL_BIT_ISCPLENGTHEXTENDEDVALID )? KAL_TRUE : KAL_FALSE)
#define LPP_PEER_OTDOA_NBR_CELL_GET_ISCPLENGTHEXTENDED(pPeerNbr)       (((pPeerNbr)->peerNbrCellBitmap & LPP_PEER_OTDOA_NBR_CELL_BIT_ISCPLENGTHEXTENDED      )? KAL_TRUE : KAL_FALSE)
#define LPP_PEER_OTDOA_NBR_CELL_GET_ISFOURANTPORTCONFIGVALID(pPeerNbr) (((pPeerNbr)->peerNbrCellBitmap & LPP_PEER_OTDOA_NBR_CELL_BIT_ISFOURANTPORTCONFIGVALID)? KAL_TRUE : KAL_FALSE)
#define LPP_PEER_OTDOA_NBR_CELL_GET_ISFOURANTPORTCONFIG(pPeerNbr)      (((pPeerNbr)->peerNbrCellBitmap & LPP_PEER_OTDOA_NBR_CELL_BIT_ISFOURANTPORTCONFIG     )? KAL_TRUE : KAL_FALSE)
#define LPP_PEER_OTDOA_NBR_CELL_GET_PRSINFOVALID(pPeerNbr)             (((pPeerNbr)->peerNbrCellBitmap & LPP_PEER_OTDOA_NBR_CELL_BIT_PRSINFOVALID            )? KAL_TRUE : KAL_FALSE)
#define LPP_PEER_OTDOA_NBR_CELL_GET_SLOTNUMBEROFFSETVALID(pPeerNbr)    (((pPeerNbr)->peerNbrCellBitmap & LPP_PEER_OTDOA_NBR_CELL_BIT_SLOTNUMBEROFFSETVALID   )? KAL_TRUE : KAL_FALSE)
#define LPP_PEER_OTDOA_NBR_CELL_GET_PRSSUBFRAMEOFFSETVALID(pPeerNbr)   (((pPeerNbr)->peerNbrCellBitmap & LPP_PEER_OTDOA_NBR_CELL_BIT_PRSSUBFRAMEOFFSETVALID  )? KAL_TRUE : KAL_FALSE)

#define LPP_PEER_OTDOA_NBR_CELL_SET_EARFCNVALID(pPeerNbr)              ((pPeerNbr)->peerNbrCellBitmap |= LPP_PEER_OTDOA_NBR_CELL_BIT_EARFCNVALID             )
#define LPP_PEER_OTDOA_NBR_CELL_SET_ISCPLENGTHEXTENDEDVALID(pPeerNbr)  ((pPeerNbr)->peerNbrCellBitmap |= LPP_PEER_OTDOA_NBR_CELL_BIT_ISCPLENGTHEXTENDEDVALID )
#define LPP_PEER_OTDOA_NBR_CELL_SET_ISCPLENGTHEXTENDED(pPeerNbr)       ((pPeerNbr)->peerNbrCellBitmap |= LPP_PEER_OTDOA_NBR_CELL_BIT_ISCPLENGTHEXTENDED      )
#define LPP_PEER_OTDOA_NBR_CELL_SET_ISFOURANTPORTCONFIGVALID(pPeerNbr) ((pPeerNbr)->peerNbrCellBitmap |= LPP_PEER_OTDOA_NBR_CELL_BIT_ISFOURANTPORTCONFIGVALID)
#define LPP_PEER_OTDOA_NBR_CELL_SET_ISFOURANTPORTCONFIG(pPeerNbr)      ((pPeerNbr)->peerNbrCellBitmap |= LPP_PEER_OTDOA_NBR_CELL_BIT_ISFOURANTPORTCONFIG     )
#define LPP_PEER_OTDOA_NBR_CELL_SET_PRSINFOVALID(pPeerNbr)             ((pPeerNbr)->peerNbrCellBitmap |= LPP_PEER_OTDOA_NBR_CELL_BIT_PRSINFOVALID            )
#define LPP_PEER_OTDOA_NBR_CELL_SET_SLOTNUMBEROFFSETVALID(pPeerNbr)    ((pPeerNbr)->peerNbrCellBitmap |= LPP_PEER_OTDOA_NBR_CELL_BIT_SLOTNUMBEROFFSETVALID   )
#define LPP_PEER_OTDOA_NBR_CELL_SET_PRSSUBFRAMEOFFSETVALID(pPeerNbr)   ((pPeerNbr)->peerNbrCellBitmap |= LPP_PEER_OTDOA_NBR_CELL_BIT_PRSSUBFRAMEOFFSETVALID  )

#define LPP_PEER_OTDOA_NBR_CELL_CLEAR_EARFCNVALID(pPeerNbr)              ((pPeerNbr)->peerNbrCellBitmap &= ~LPP_PEER_OTDOA_NBR_CELL_BIT_EARFCNVALID             )
#define LPP_PEER_OTDOA_NBR_CELL_CLEAR_ISCPLENGTHEXTENDEDVALID(pPeerNbr)  ((pPeerNbr)->peerNbrCellBitmap &= ~LPP_PEER_OTDOA_NBR_CELL_BIT_ISCPLENGTHEXTENDEDVALID )
#define LPP_PEER_OTDOA_NBR_CELL_CLEAR_ISCPLENGTHEXTENDED(pPeerNbr)       ((pPeerNbr)->peerNbrCellBitmap &= ~LPP_PEER_OTDOA_NBR_CELL_BIT_ISCPLENGTHEXTENDED      )
#define LPP_PEER_OTDOA_NBR_CELL_CLEAR_ISFOURANTPORTCONFIGVALID(pPeerNbr) ((pPeerNbr)->peerNbrCellBitmap &= ~LPP_PEER_OTDOA_NBR_CELL_BIT_ISFOURANTPORTCONFIGVALID)
#define LPP_PEER_OTDOA_NBR_CELL_CLEAR_ISFOURANTPORTCONFIG(pPeerNbr)      ((pPeerNbr)->peerNbrCellBitmap &= ~LPP_PEER_OTDOA_NBR_CELL_BIT_ISFOURANTPORTCONFIG     )
#define LPP_PEER_OTDOA_NBR_CELL_CLEAR_PRSINFOVALID(pPeerNbr)             ((pPeerNbr)->peerNbrCellBitmap &= ~LPP_PEER_OTDOA_NBR_CELL_BIT_PRSINFOVALID            )
#define LPP_PEER_OTDOA_NBR_CELL_CLEAR_SLOTNUMBEROFFSETVALID(pPeerNbr)    ((pPeerNbr)->peerNbrCellBitmap &= ~LPP_PEER_OTDOA_NBR_CELL_BIT_SLOTNUMBEROFFSETVALID   )
#define LPP_PEER_OTDOA_NBR_CELL_CLEAR_PRSSUBFRAMEOFFSETVALID(pPeerNbr)   ((pPeerNbr)->peerNbrCellBitmap &= ~LPP_PEER_OTDOA_NBR_CELL_BIT_PRSSUBFRAMEOFFSETVALID  )


/*****************************************************************************
 * Enums without tags
 *****************************************************************************/


/*****************************************************************************
 * Type Definitions
 *****************************************************************************/

/* LPP -> LBS */
/* This structure for MSG_ID_LPP_LBS_SESSION_START_IND */
typedef struct
{
    LOCAL_PARA_HDR
} lpp_lbs_session_start_ind_struct;


/* This structure for MSG_ID_LPP_LBS_SESSION_END_IND */
typedef struct
{
    LOCAL_PARA_HDR
} lpp_lbs_session_end_ind_struct;


typedef enum
{
    LPP_POS_METHOD_TYPE_NONE,
    LPP_POS_METHOD_TYPE_AGNSS,
    LPP_POS_METHOD_TYPE_OTDOA,
    LPP_POS_METHOD_TYPE_ECID
} lpp_pos_method_type_enum;


/* This structure for MSG_ID_LPP_LBS_POS_METHOD_IND */
typedef struct
{
    LOCAL_PARA_HDR
    lpp_pos_method_type_enum  posMethod;
} lpp_lbs_pos_method_ind_struct;


/* LBS -> LPP */
/* This structure for MSG_ID_LPP_LBS_SESSION_END_REQ */
typedef struct
{
    LOCAL_PARA_HDR
} lpp_lbs_session_end_req_struct;


/* This structure for MSG_ID_LPP_LBS_CAPABILITY_UPDATE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* TBD: only allow change positioning method support capability */
    kal_bool  agnssSupport;
    kal_bool  otdoaSupport;
    kal_bool  ecidSupport;
} lpp_lbs_capability_update_req_struct;


/* This structure for MSG_ID_LPP_LBS_RESET_UE_STORED_POS_INFO_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool  resetAgnss;
    kal_bool  resetOtdoa;
} lpp_lbs_reset_ue_stored_pos_info_req_struct;


/* LPP (SWIP) -> LPP */
/* This structure for MSG_ID_LPP_PEER_OTDOA_MEAS_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* refer to lpp_el1_otdoa_meas_req_struct, for UP forward only */
    kal_uint16  transactionID;
    kal_uint8   responseTime;     /* [1..128], unit in seconds, for EL1 knowing about how long it will take for OTDOA measurement, but LPP still controls the response timer */
} lpp_peer_otdoa_meas_req_struct;


/* this structure is dedicated for UP peer forward */
typedef struct
{
   kal_uint8   prsBandwidth;  /* map to lpp_otdoa_prs_info_bandwidth_enum */
   kal_uint8   numDLFrames;   /* map to lpp_otdoa_prs_info_num_dl_frame_enum */
   kal_uint8   prsMutingInfoValid; /* map to kal_bool */
   kal_uint8   prsMutingInfoType;  /* map to lpp_otdoa_prs_info_muting_po_enum */
   kal_uint16  prsConfigIndex;     /* [0..4095] */
   kal_uint16  prsMutingInfoBits;  /* Position Occasion: PO-2: 2 bits, PO-4: 4 bits, PO-8: 8 bits, PO-16: 16 bits */
} lpp_peer_otdoa_prs_info;


/* this structure is dedicated for UP peer forward */
typedef struct
{
    kal_uint8                earfcnValid;               /* map to kal_bool, FALSE: indicate this is a intra-freq cell, EL1 should use current serving cell's earfcn; TRUE: indicate this is a inter-freq cell */
    kal_uint8                isFourAntPortConfigValid;  /* map to kal_bool */
    kal_uint8                isFourAntPortConfig;       /* map to kal_bool, TRUE: 4 antenna ports for CRS are used in the assistance data reference cell, FALSE: 1 (or 2) antenna port(s) */
    kal_uint8                isCPLengthExtended;        /* map to kal_bool, TRUE: cyclic prefix length of PRS or CRS is extended, FALSE: cyclic prefix length is normal */
    kal_uint8                prsInfoValid;              /* map to kal_bool */
    kal_uint16               phyCellId;                 /* [0..503] */
    kal_uint32               earfcn;                    /* [0..262143], 65535 is invalid to indicate ARFCN-ValueEUTRA-v9a0 present; LPP assign reference cell if received message IE does not present */
    lpp_peer_otdoa_prs_info  prsInfo;
} lpp_peer_otdoa_ref_cell_info_struct;


/* this structure is dedicated for UP peer forward */
typedef struct
{
    kal_uint8                peerNbrCellBitmap;         /*earfcnValid; isCPLengthExtendedValid; isCPLengthExtended; isFourAntPortConfigValid; isFourAntPortConfig; prsInfoValid; slotNumberOffsetValid; prsSubFrameOffsetValid;*/
    kal_uint8                slotNumberOffset;          /* [0..19] */
    kal_uint16               phyCellId;                 /* [0..503] */
    kal_uint16               prsSubFrameOffset;         /* [0..1279] */
    kal_uint16               expectedRSTD;              /* [0..16383] */
    kal_uint16               expectedRSTDUnc;           /* [0..1023] */
    kal_uint32               earfcn;                    /* [0..262143], 65535 is invalid to indicate ARFCN-ValueEUTRA-v9a0 present; LPP assign reference cell if received message IE does not present */
    lpp_peer_otdoa_prs_info  prsInfo;
    
} lpp_peer_otdoa_nbr_cell_info_struct;


/* this structure is dedicated for UP peer forward */
typedef struct
{
    kal_uint8                            numCellInfo;
    lpp_peer_otdoa_nbr_cell_info_struct  cellInfo[LPP_PEER_OTDOA_MAX_NBR_CELL_LIST_NUM];
} lpp_peer_otdoa_nbr_cell_info_list_struct;


/* this structure is dedicated for UP peer forward */
typedef struct
{
    kal_uint8                                 numFreqInfo;
    lpp_peer_otdoa_nbr_cell_info_list_struct  freqInfo[LPP_PEER_OTDOA_MAX_NBR_CELL_FREQ_LAYER_NUM];
}  lpp_peer_otdoa_nbr_freq_info_list_struct;


/* This structure for MSG_ID_LPP_PEER_OTDOA_ASSIST_DATA_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* refer to lpp_el1_otdoa_assist_data_req_struct, for UP forward only */
    kal_uint16                                transactionID;
    kal_uint8                                 refCellInfoValid;  /* map to kal_bool */
    lpp_peer_otdoa_ref_cell_info_struct       refCellInfo;
    kal_uint8                                 nbrCellInfoValid;  /* map to kal_bool */
    lpp_peer_otdoa_nbr_freq_info_list_struct  nbrCellInfo;
} lpp_peer_otdoa_assist_data_req_struct;


/* This structure for MSG_ID_LPP_PEER_OTDOA_MEAS_ABORT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* refer to lpp_el1_otdoa_meas_abort_req_struct, for UP forward only */
    kal_uint16  transactionID;
} lpp_peer_otdoa_meas_abort_req_struct;


/* This structure for MSG_ID_LPP_PEER_ECID_MEAS_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* refer to lpp_errc_ecid_meas_req_struct, for UP forward only */
    kal_uint16  transactionID;
    kal_uint8   rsrpReq;            /* map to kal_bool */
    kal_uint8   rsrqReq;            /* map to kal_bool */
    kal_uint8   ueRxTxTimeDiffReq;  /* map to kal_bool */
} lpp_peer_ecid_meas_req_struct;


/* This structure for MSG_ID_LPP_PEER_ECID_MEAS_ABORT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* refer to lpp_errc_ecid_abort_req_struct, for UP forward only */
    kal_uint16  transactionID;
} lpp_peer_ecid_meas_abort_req_struct;


/* LPP -> LPP (SWIP) */

/* this structure is dedicated for UP peer forward */
typedef struct
{
    kal_uint8  errResolution;     /* 2 bits, refer description as above */
    kal_uint8  errValue;          /* 5 bits, refer description as above */
    kal_uint8  errSamplesValid;   /* map to kal_bool */
    kal_uint8  errSamples;        /* 3 bits, refer description as above */
} lpp_peer_otdoa_measured_quality_struct;


/* this structure is dedicated for UP peer forward */
typedef struct
{
    kal_uint16                              phyCellId;
    kal_uint32                              earfcn;        /* [0..262143], 65535 is invalid to indicate ARFCN-ValueEUTRA-v9a0 present */
    kal_uint16                              rstd;          /* [0..12711], mapping refer to TS 36.133 table 9.1.10.3-1 */
    lpp_peer_otdoa_measured_quality_struct  rstdQuality;
} lpp_peer_otdoa_measured_nbr_cell_struct;


/* this structure is dedicated for UP peer forward */
typedef struct
{
    kal_uint16                               sysFrameNumber;      /* 10 bits */
    kal_uint16                               refPhyCellId;        /* [0..503] */
    kal_uint32                               refEarfcn;           /* [0..262143], 65535 is invalid to indicate ARFCN-ValueEUTRA-v9a0 present */
    kal_uint8                                refQualityValid;     /* map to kal_bool */
    lpp_peer_otdoa_measured_quality_struct   refQuality;
    kal_uint8                                numMeasuredNbrCell;
    lpp_peer_otdoa_measured_nbr_cell_struct  measuredNbrCell[LPP_PEER_OTDOA_MAX_NBR_CELL_LIST_NUM];
}  lpp_peer_otdoa_measured_info_struct;


/* This structure for MSG_ID_LPP_PEER_OTDOA_MEAS_CNF */
typedef struct
{
    LOCAL_PARA_HDR    
    /* refer to lpp_el1_otdoa_meas_cnf_struct, for UP forward only */
    kal_uint16                           transactionID;
    lpp_peer_otdoa_measured_info_struct  measurementResult;
} lpp_peer_otdoa_meas_cnf_struct;


/* This structure for MSG_ID_LPP_PEER_OTDOA_ASSIST_DATA_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    /* refer to lpp_el1_otdoa_assist_data_cnf_struct, for UP forward only */
    kal_uint16  transactionID;
} lpp_peer_otdoa_assist_data_cnf_struct;


/* This structure for MSG_ID_LPP_PEER_OTDOA_ADDITIONAL_ASSIST_DATA_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16  transactionID;   /* assoicated measurement transaction ID */
    kal_uint16  physCellId;      /* [0..503] */
} lpp_peer_otdoa_additional_assist_data_req_struct;  /* same as lpp_el1_otdoa_additional_assist_data_req_struct */


typedef struct {
    kal_uint8 mcc1;
    kal_uint8 mcc2;
    kal_uint8 mcc3;
    kal_uint8 mnc1;
    kal_uint8 mnc2;
    kal_uint8 mnc3;
} lbs_plmn_id_struct;


/* this structure is dedicated for UP peer forward */
typedef struct
{
    kal_uint16          phyCellId;            /* [0..503] */
    kal_uint8           plmnIdValid;          /* map to kal_bool */
    lbs_plmn_id_struct  plmnId;
    kal_uint8           cellIdValid;          /* map to kal_bool */
    kal_uint32          cellId;               /* eutra 28 bits */
    kal_uint32          earfcn;               /* [0..262143], 65535 is invalid to indicate ARFCN-ValueEUTRA-v9a0 present */
    kal_uint8           sysFrameNumberValid;  /* map to kal_bool */
    kal_uint16          sysFrameNumber;       /* 10 bits */
    /* measured result */
    kal_uint8           rsrpResultValid;      /* map to kal_bool */
    kal_uint8           rsrpResult;           /* [0..97] */
    kal_uint8           rsrqResultValid;      /* map to kal_bool */
    kal_uint8           rsrqResult;           /* [0..34] */
    kal_uint8           ueRxTxTimeDiffValid;  /* map to kal_bool */
    kal_uint16          ueRxTxTimeDiff;       /* [0..4095] */
} lpp_peer_ecid_cell_measured_info_struct;


/* this structure is dedicated for UP peer forward */
typedef struct
{
    /**
     * Please note that the interface here is more straight-forward then ECID-SignalMeasurementInformation IE of LPP Message:
     * when ERRC has measured primary cell, the result will place at primaryCellMeasuredResult;
     * (if serving (primary) cell is not present, the whole measured info should be ignored since result will be error)
     *
     * in addition to primary cell, if ERRC also measured neighbor cells, they will be put into the array of measuredCellResult[],
     * and the number of neighbor will specify in numMeasuredCellResult
     */
    lpp_peer_ecid_cell_measured_info_struct  primaryCellMeasuredResult;
    kal_uint8                                numMeasuredCellResult;
    lpp_peer_ecid_cell_measured_info_struct  measuredCellResult[LPP_PEER_ECID_MAX_MEASURED_CELL_INFO_NUM];
} lpp_peer_ecid_measured_info_struct;


/* This structure for MSG_ID_LPP_PEER_ECID_MEAS_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    /* refer to lpp_errc_ecid_meas_cnf_struct, for UP forward only */
    kal_uint16                          transactionID;
    kal_uint8                           result;  /* map to lpp_loc_ecid_result_enum */
    lpp_peer_ecid_measured_info_struct  measurementResult;
} lpp_peer_ecid_meas_cnf_struct;


/* This structure for MSG_ID_LPP_PEER_EUTRAN_BAND_UPDATE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    /* empty */
} lpp_peer_eutran_band_update_req_struct;


/* This structure for MSG_ID_LPP_PEER_EUTRAN_BAND_UPDATE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   supportEutraBandListNum;
    kal_uint16  supportEutraBandList[LPP_PEER_MAX_BANDS];
} lpp_peer_eutran_band_update_cnf_struct;

#endif  /* #if defined(__LPP_CP_SUPPORT__) || defined(__LPP_UP_SUPPORT__) */

#endif /* _LPP_LBS_MSG_STRUCT_H */
