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
 *    drv_features_vcodec.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for the video codec feature
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_FEATURES_VCODEC_H__
#define __DRV_FEATURES_VCODEC_H__

#include "drv_features_chip_select.h"

#if defined(__MP4_DEC_SW_SUPPORT__)
#define SW_MP4_DEC_SUPPORT
#endif
#if defined(__MP4_ENC_SW_SUPPORT__)
#define SW_MP4_ENC_SUPPORT
#endif
#if defined(__H264_DEC_SW_SUPPORT__)
#define SW_H264_DEC_SUPPORT
#endif

#ifdef SW_MP4_DEC_SUPPORT
#define MP4DEC_SORENSON_OFF 
#define SWMP4DEC 
/* ========= algorithm ========= */
#define MC_Improved
#define OPT_FOR_MTK
#define ACDC_OPT
#define VLD_OPT
#define MP4DEC_IDCT_OPT
#define MP4DEC_MB_OPT
#define MP4DEC_MVD_OPT
#define MP4DEC_PROCESSBLOCK_OPT
#define MP4DEC_REFUV_OPT
#define MP4DEC_INTRA_OPT
#define MP4DEC_MC_OPT
//#define MP4DEC_MCBPC_OPT
#define MP4DEC_DCCOEFF_OPT
#define MP4DEC_SCANDIR_OPT
#if defined(MT6236) || defined(MT6236B) || defined(MT6253) || defined(MT6252H) || defined(MT6252)
    #if !defined(__SW_MP4_LOSSY_SUPPORT__)
#define __SW_MP4_LOSSY_SUPPORT__
    #endif
#endif
#if defined(__SW_MP4_LOSSY_SUPPORT__) && defined(__VIDEO_ARCHI_V2__) && defined(__MTK_TARGET__)
#define MP4_LOSSY_SUPPORT
#endif
#ifdef MP4_LOSSY_SUPPORT
#define MP4DEC_IDCT_16bit
//#define ERICA_MC_ROUND
//#define SUB_INT_USE_MUL
#define SUB_INT_USE_4TAP
#define SUB_INT_USE_2TAP
//#define ERICA_G_MC
#define MP4_LOSSY_KEEP_BOUNDARY
#endif
//#if defined(__MP4_DEC_ASP_PARTIAL_SUPPORT__)
#define MP4_QUANT_SUPPORT
//#endif
#if defined(MT6236) || defined(MT6236B) || defined(MT6276)
    #if defined(__VIDEO_ARCHI_V2__)
#define MP4_VT_SUPPORT
    #endif
#endif
#ifdef MP4_VT_SUPPORT 
//#define MP4_VT_LOG
#define MP4_DEBLOCK_SUPPORT
#define ERROR_DETECTION_1_DQ
#define ERROR_DETECTION_2_IQ
#define ERROR_DETECTION_3_BND
#define ERROR_DETECTION_4_FNL_CEL
//#define ERROR_DETECTION_5_LMT_MV
#define ERROR_DETECTION_8_NCBLK
#define ERROR_DETECTION_9_1VOP
//#define ERROR_DETECTION_10_MV0_CEL
#define ERROR_DETECTION_11_NthIVOP
#define ERROR_DETECTION_12_NCVOP
#define ERROR_DETECTION_13_STALLED_FRAME_REFRESHING_RANGE
//#define ERROR_DETECTION_13_LOW_COMPLEXITY
#define VT_SPECIFIC_PARAMETER_Correction
//#define ERROR_DETECTION_14_JUDGE_EVERY_FRAME_CONCEALMENT_RANGE
//#define ERROR_DETECTION_15_BELIEVE_FORMER_CONCEALED_MV
//#define ERROR_DETECTION_16_SCATTERED_WHOLE_P_FRAME_CONCEALMENT
#endif /* VT */

#define MP4_MTK_DECRYPT

#if defined(__TARGET_FEATURE_DSPMUL) // avoid MODIS error
#define ABS_ASM
#define ADS_ASM
#define MP4DEC_ASM16x16
#define MP4DEC_ASM_CLZ
#endif
//#define NDEBUG
//#define noMetaDecoding
//#define CoeffLess6IDCT
//#define ReplaceClip

/* ========= memory ========= */
#define Critical_RW_Reduced
#if defined(MT6256) || defined(MT6276) || defined(MT6575)
#define SWMP4DEC_ResUpTo1080P
#elif defined(MT6236) || defined(MT6236B) || defined(MT6255)
#define SWMP4DEC_ResUpTo1080P
#elif defined(MT6235) || defined(MT6235B)
//#ifdef __MP4_DEC_SW_CIF_SUPPORT__ 
//#define SWMP4DEC_ResUpToCIF
//#else
//#define SWMP4DEC_ResUpToQVGA 
//#endif
#define SWMP4DEC_ResUpTo1080P
#elif defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
//#ifdef __MP4_DEC_SW_CIF_SUPPORT__ 
//#define SWMP4DEC_ResUpToCIF
//#else
//#define SWMP4DEC_ResUpToQVGA
//#endif
//#define SWMP4DEC_ResUpToWQVGA
    #if defined(__VIDEO_ARCHI_V2__)
#define SWMP4DEC_ResUpToWVGA
    #else
#define SWMP4DEC_ResUpToHVGA
    #endif
#else // 25
#define SWMP4DEC_ResUpToQCIF
#endif

#if defined(MT6236) || defined(MT6236B)
#define PutDecEssentialInIntRam36  // ZI
#define PutDecEssentialInTCM36 // RO
#elif defined(MT6253)
    #if defined(__VIDEO_ARCHI_V2__)
#define PutDecEssentialInIntRam53 // ZI
    #else
#define PutDecEssentialInIntRam  // ZI
    #endif
#define PutDecEssentialInTCM // RO
#define PutDecMotionTextureInIntRam53
#define PutDecMotionTextureUtilsInIntRam53
#define PutDecProcessBlockInIntRam53
#define PutDecUtilsInIntRam53
#define PutDecIdctInIntRam53
#define PutDecVlcInIntRam53
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252) || defined(MT6256) || defined(MT6276) || defined(MT6575) || defined(MT6255)
#elif defined(MT6235) || defined(MT6235B)
    #if !defined(__VIDEO_ARCHI_V2__)
#define PutDecEssentialInIntRam  // ZI
#define PutDecEssentialInTCM // RO
#define PutDecEssentialInIntRam35  // ZI
    #endif
#else
#define PutDecEssentialInIntRam  // ZI
#define PutDecEssentialInTCM // RO
#endif
#endif // SW_MP4_DEC_SUPPORT

/****************************************************************************
 **************************************************************************** 
 ****************************************************************************
 *********                                                          *********
 *********                                                          *********
 *********              software encoder features                   *********
 *********                                                          *********
 *********                                                          *********
 ****************************************************************************
 **************************************************************************** 
 ****************************************************************************/


#ifdef SW_MP4_ENC_SUPPORT

/************************ Resolution **************************************/
#ifdef WIN32_PC_SIM
#define MP4SwEncMaxVidCodRes_720p
#elif defined(MT6236) || defined(MT6236B) || defined(MT6921)
#define MP4SwEncMaxVidCodRes_QVGA
#elif  defined(MT6276)
#ifdef __MPEG4_ENC_SW_SLIM__
  #define MP4SwEncMaxVidCodRes_HVGA
#else
  #define MP4SwEncMaxVidCodRes_WVGA

#endif
#elif defined(MT6256)
  #define MP4SwEncMaxVidCodRes_720p
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
#define MP4SwEncMaxVidCodRes_QCIF
#elif defined(MT6255)
#define MP4SwEncMaxVidCodRes_HVGA
#else // MT6236
#define MP4SwEncMaxVidCodRes_QCIF
#endif

#if defined(MT6276)
#define DUO_VIDEO_SUPPORT
#endif

#if defined(MT6236) || defined(MT6236B) || defined(MT6276)
#define SW_UVT_ENC_SUPPORT
#endif
#endif

/****************************************************************************
 **************************************************************************** 
 ****************************************************************************
 *********                                                          *********
 *********                                                          *********
 *********           end of software encoder features               *********
 *********                                                          *********
 *********                                                          *********
 ****************************************************************************
 **************************************************************************** 
 ****************************************************************************/
 

//#ifdef SW_H264_DEC_SUPPORT
///* ========= algorithm ========= */
//#define SKIP_SEI
//#define MC_OPT
//#define H0V0_OPT
//#define SUPPORT_CLZ
//#define BITSBUF_OPT2
//#define BITSBUF_OPT
//#define DB_BS_OPT
//#define IT_OPT2
//#define MB_OPT
//#if !(defined(MT6253)||defined(MT6253D)||defined(MT6253T)||defined(MT6236)||defined(MT6236B))
//#define CLIP_OPT
//#endif
//#if 0//def __SW_VIDEO_MAX_RESOLUTION__
//#define SUPPORT_LEVEL40 // only used in V1
//#else
//#define SUPPORT_LEVEL20 // only used in V1
//#endif
//#if defined(MT6276)
//#define REDUCE_RES_SIZE
//#if defined(__MTK_TARGET__)
//#define H264DEC_ARM11_ASM
//#endif
//#endif // MT6276
//
//#if defined(MT6236) || defined(MT6236B) || defined(MT6253) || defined(MT6252H) || defined(MT6252) || defined(MT6276)
//    #if !defined(__SW_H264_LOSSY_SUPPORT__)
//#define __SW_H264_LOSSY_SUPPORT__
//    #endif
//#endif
//#ifdef __SW_H264_LOSSY_SUPPORT__
//#define H264_LOSSY_SUPPORT 
//#endif
//
//#ifdef H264_LOSSY_SUPPORT
//#define NO_FULL_SUB_SIWTCH
//#if defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
//#define OUTBUF_ALIGN16
//#endif // defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
//#endif
//
//#if defined(__VIDEO_ARCHI_V2__)
//#define DPB_SET_NULL
//#endif
//
////#define IMAGE_FIXPT_DIV
//#define MBLAYER_MODE_ARRAY
//#define NEIGHBOR_FIND_NEIGHBOR_ARRAY
//#define NEIGHBOR_AVAIL
//#define CAVLC_NO_FLAG
//#define CAVLC_REORDER
//#define CAVLC_RM_DUMMY_BCH
//#define CAVLC_GET_NOCHECK
//#define CAVLC_RM_DUMMY_CHECK
//#define TRANSFORM_1024
//#define TRANSFORM_REDUCE_LDRSTR
//#define INTRA_PARALLEL_STR
//#define INTRA_LOCAL_VAR
//#define INTRA_UNROLL
//#define INTRA_FACTOR
//#define INTER_COMBINE_MV
//#define INTER_COMBINETABLE
//#define MOCOM_HORNER
//#define MOCOM_DOWHILE
////#define DB_ABS_ASM
////#define DB_CLIP3
//#define DB_RM_CHECK
//#define DB_TC_UNROLL
//#define DB_TC_RTN_ONCE
//#define DB_LOCALBETA
//// 20100314
//#define CAVLC_SHARE_VAR
//#define CAVLC_CHANGE_CHECK
//#define CAVLC_SKIP_DUMMY_AND
//#define CAVLC_DELAY_STR
//#define INTRA_NEIGHBOR_STRH
//#define INTRA_DATAPACK_REDUCE_CC
//#define INTRA_UNROLL_GET_PEL
//#define DB_UPDATE_ONLYIF_NONZERO
//#define DB_CHANGE_ALPHA_ORDER
//// 20100512
//#define TRANSFORM_ADVANCED_ADD
//#define TRANSFORM_DEQUANT_OPT
////20100610
//#define MOCOM_FUNCPTR
//#define IMAGE_SKIP_MUL
//#define IMAGE_SHARE_BLK_TBL
//#define REDUCE_MBSTORAGE
//#define MBLAYER_CHANGE_FLOW
//#define VLD_CHANGE_FLOW
//#define MBLAYER_PRECAL_NEIGHBOR_AVAIL
//#define MBLAYER_CHANGE_FLOW
//#define MBLAYER_NCPTR
//#define CAVLC_TRAILINGONE
//#define INLINE_MEMCPY
//#define INLINE_MEMSET
//#define ALIGN_CASE
//#define ALIGN_SET
//#define MC_PADFLOW
////20100617
//#define INLINE_SUBMBMODE
////#define REDUCE_RES_SIZE
//#if defined(REDUCE_RES_SIZE)
//#define TRANSFORM_REDUCE_LOAD
//#endif
////20100620
//#define NEIGHBOR_REDUCE_BCH
//#define FUNC_2_TBL
//#define FUNC_2_TBLa
//#define FUNC_2_TBLc
//#define FUNC_2_TBLd
////20100628
//#define INTRA_WRITE_TO_EXTERNAL
//#define INTRA_OPT
//#define INTRA_CHANGE_FLOW
//#define INTRA_CONTROL_OPT
////#define REDUCE_DIV
//#define SKIP_GETREF
//#if defined(INTRA_WRITE_TO_EXTERNAL) && defined(H264_LOSSY_SUPPORT)
////#define SUBCHROMA
//#endif
////20101123
//#define MOCOM_LOSSLESS_FUNCPTR
//#define RES_EMPTY
//
//// 20101123, for CMMB concealment algorithm
//#define MULTIPLE_SPS
//#define DPB_ERR_HANDLE
//// Please not try to enable/disable the define within CMMB_CONCEAL_ALG
//#define CMMB_CONCEAL_ALG
//#ifdef CMMB_CONCEAL_ALG
//#define CMMB_DPBCTRL
//#define FIX_SCENE_CHANGE
////#define CMMB_DBG // for PC debug
//#define CHECK_BOUNDARY
//#define MV_ROW 
//// Sports_error_04, 280
//#define FIX_SKIPRUN 
//// fun_error_05
//#define FIX_INTRACHROMA_PREDMODE
//// fun_error_05
//#define FIX_MBQPDELTA
//// fun_error_05
//#define FIX_ITSAT
//// fun_error_05
//#define FIX_CAVLC_ZEROLEFT
//// fun_error_05
//// by observations, this should not recover
////#define FIX_MBTYPE
//// fun_error_03
//// observe from N82, may be it rollback only some MBs??
////#define FIX_BACKWARD_MB
//// drama_error_02, under test
////#define FIX_FEW_DECODED_BLK
////#define CHECK_REF_COHERENCE
//#define PATENT_INTRA
////#define EC_1012_TEST
////#define EC_1013_TEST //1118 no need to enable for dpb control
//#define CONCEAL_TRANSFORM_ORIGINAL
////#define CONCEAL_TRANSFORM_4
////#define CONCEAL_TRANSFORM_16
//#endif // CMMB_CONCEAL_ALG
//
//
//#if defined(__MTK_TARGET__)
//#define DB_ABS_ASM
//#define DB_CLIP3
//// 20100314
//#define CAVLC_TBL_LOOKUP
//#define MOCOM_DSPMUL
//#define INTRA_DIRECTADD
//// 20100512
//#define INTRA_DIRECT4X4ADD
//#define TRANSFORM_DSPMUL
////20100617
//#define IMAGE_HARDCODE
//#endif /* #if defined(__MTK_TARGET__) */
//
//#if (defined(MT6253)||defined(MT6253T))
//#define INTRA_WT_WORD53
//#endif
//
///* ========= memory ========= */
//#define REDUCE_SIZE
//#define PutDynamicBufferInCachedExt
//#define PutStrmInIntRam
//
//#if !(defined(MT6253)||defined(MT6253T)||defined(MT6253E)||defined(MT6253L)||defined(MT6252H)||defined(MT6252))
//#define MC_BUF_IN_STACK
//#endif
//
//#if defined(__VIDEO_ARCHI_V2__)
//#if defined(MT6235) || defined(MT6235B)
//#define SUPPORT_1080P
//#endif // #if defined(MT6235) || defined(MT6235B)
//#endif // #if defined(__VIDEO_ARCHI_V2__)
//
//#ifndef __VIDEO_ARCHI_V2__
//#if defined(SW_H264_6235_SERIES) || defined(MT6235) || defined(MT6235B)
//#ifdef __DRV_MTV_SUPPORT__
//    #if !defined(__H264_DEC_SW_QVGA_SUPPORT__) && !defined(__SW_VIDEO_MAX_RESOLUTION__)
//        #error "MobileTV need support QVGA H.264."
//    #endif
//#endif
//#if 1//def __SW_VIDEO_MAX_RESOLUTION__
//#define SUPPORT_1080P
//#elif defined(__H264_DEC_SW_QVGA_SUPPORT__)
//#define SUPPORT_QVGA
//#else // __H264_DEC_SW_QVGA_SUPPORT__
//#define SUPPORT_QCIF
//#define PutmbStorageInIntRam
//#define REDUCE_SIZE2
//#endif // __H264_DEC_SW_QVGA_SUPPORT__
//#endif // SW_H264_6235_SERIES
//
//#if (defined(MT6253)||defined(MT6253T))
//#define SUPPORT_QCIF
//#define PutBsdSliceDataInIntRam53
//#define PutBsdVlcInIntRam53
//#define PutBsdTransformInIntRam53
//#define PutBsdStorageInIntRam53
//#define PutBsdReconstructInIntRam53
//#define PutBsdCavlcInIntRam53
//#define PutBsdImageInIntRam53
//#define PutBsdInterInIntRam53
//#define PutBsdIntraInIntRam53
//#define PutBsdMbLayerInIntRam53
//#define PutBsdVlcInIntRam53
//#define PutSWCodecCommonInIntRam53
//#endif // (defined(MT6253)||defined(MT6253T))
//#endif // __VIDEO_ARCHI_V2__
//
//
//#if defined(MT6256) || defined(MT6276)
//#ifdef __VIDEO_ARCHI_V2__
////#define SUPPORT_nHD
//#define SUPPORT_1080P
//#define SELF_TCM_MANAGE
//#endif // __VIDEO_ARCHI_V2__
//#endif
//
//#if defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
//#ifdef __VIDEO_ARCHI_V2__
//#define SUPPORT_WVGA_848_480
//#endif // __VIDEO_ARCHI_V2__
//#endif
//
//#if defined(MT6253) 
//#ifdef __VIDEO_ARCHI_V2__
////#ifdef __SW_VIDEO_MAX_RESOLUTION__
////#define SUPPORT_WVGA_848_480
////#else /* __SW_VIDEO_MAX_RESOLUTION__ */
////#define SUPPORT_QCIF
////#endif /* __SW_VIDEO_MAX_RESOLUTION__ */
////#define SUPPORT_1080P
//#define SUPPORT_WVGA_848_480
//#define PutBsdSliceDataInIntRam53
//#define PutBsdVlcInIntRam53
//#define PutBsdTransformInIntRam53
//#define PutBsdStorageInIntRam53
//#define PutBsdReconstructInIntRam53
//#define PutBsdCavlcInIntRam53
//#define PutBsdImageInIntRam53
//#define PutBsdInterInIntRam53
//#define PutBsdIntraInIntRam53
//#define PutBsdMbLayerInIntRam53
//#define PutBsdVlcInIntRam53
//#define PutSWCodecCommonInIntRam53
//#endif // __VIDEO_ARCHI_V2__
//#endif
//
//#if defined(MT6236) || defined(MT6236B)
//#ifdef __VIDEO_ARCHI_V2__
////#ifdef __SW_VIDEO_MAX_RESOLUTION__
//#define SUPPORT_1080P
////#else /* __SW_VIDEO_MAX_RESOLUTION__ */
////#define SUPPORT_WVGA
////#endif /* __SW_VIDEO_MAX_RESOLUTION__ */
//#define SELF_TCM_MANAGE
//#else // __VIDEO_ARCHI_V2__
//#error "36 SERIES NOT SUPPORT V1 ARCHITECTURE"
//#define ROW_DB
//#define MT6236_TDDMA_SUPPORT_DB_H264
////#define MMDMA_TEST_ADB_H264
////#define MT6236_TDDMA_SUPPORT_ADB_H264
//#endif // __VIDEO_ARCHI_V2__
//#endif
//
//#if defined(MT6236) || defined(MT6236B)
//#define PutmbLayerStorageInIntRam36
//#else
//#define PutmbLayerStorageInIntRam
//#endif
//#if defined(MT6236) || defined(MT6236B)
//#define PutCriticalROInIntRam36
//#else
//#define PutCriticalROInIntRam
//#endif
//
//#if defined(MT6235) || defined(MT6235B)
//#define USE_35SERIES_DCM
//#endif
//
//#if defined(MT6236) || defined(MT6236B)
//#define USE_36SERIES_DCM
//#endif
//
//#if defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
//#define USE_53SERIES_DCM
//#endif
//
//#if defined(SUPPORT_1080P)              
//#define H264DecMaxWidth   1920
//#define H264DecMaxHeight  1088  
//#elif defined(SUPPORT_4SVGA)              
//#define H264DecMaxWidth   1600
//#define H264DecMaxHeight  1200  
//#elif defined(SUPPORT_16CIF)              
//#define H264DecMaxWidth   1408
//#define H264DecMaxHeight  1152  
//#elif defined(SUPPORT_SXVGA)              
//#define H264DecMaxWidth   1280
//#define H264DecMaxHeight  1024  
//#elif defined(SUPPORT_4VGA)               
//#define H264DecMaxWidth   1280
//#define H264DecMaxHeight  960  
//#elif defined(SUPPORT_720p)               
//#define H264DecMaxWidth   1280
//#define H264DecMaxHeight  720   
//#elif defined(SUPPORT_XVGA)               
//#define H264DecMaxWidth   1024
//#define H264DecMaxHeight  768   
//#elif defined(SUPPORT_SVGA)               
//#define H264DecMaxWidth   800
//#define H264DecMaxHeight  608  
//#elif defined(SUPPORT_D1_720_576)         
//#define H264DecMaxWidth   720
//#define H264DecMaxHeight  576   
//#elif defined(SUPPORT_WVGA_848_480)       
//#define H264DecMaxWidth   848
//#define H264DecMaxHeight  480    
//#elif defined(SUPPORT_WVGA)     
//#define H264DecMaxWidth   800
//#define H264DecMaxHeight  480  
//#elif defined(SUPPORT_D1)   
//#define H264DecMaxWidth   720
//#define H264DecMaxHeight  480   
//#elif defined(SUPPORT_VGA)                
//#define H264DecMaxWidth   640
//#define H264DecMaxHeight  480    
//#elif defined(SUPPORT_nHD)                
//#define H264DecMaxWidth   640
//#define H264DecMaxHeight  368   
//#elif defined(SUPPORT_HVGA)               
//#define H264DecMaxWidth   480
//#define H264DecMaxHeight  320    
//#elif defined(SUPPORT_WQVGA_432_240)              
//#define H264DecMaxWidth   432
//#define H264DecMaxHeight  240    
//#elif defined(SUPPORT_CIF)                
//#define H264DecMaxWidth   352
//#define H264DecMaxHeight  288    
//#elif defined(SUPPORT_WQVGA)              
//#define H264DecMaxWidth   400
//#define H264DecMaxHeight  240    
//#elif defined(SUPPORT_QVGA)               
//#define H264DecMaxWidth   320
//#define H264DecMaxHeight  240    
//#elif defined(SUPPORT_QCIF)               
//#define H264DecMaxWidth   176
//#define H264DecMaxHeight  144    
//#elif defined(SUPPORT_SQCIF)              
//#define H264DecMaxWidth   128
//#define H264DecMaxHeight  96     
//#else
//#error "Unknown resolution."
//#endif
//
///* ========= dma ========= */
//#if defined(MT6236_TDDMA_SUPPORT_ADB_H264) && defined(MT6236_TDDMA_SUPPORT_MC) && !defined(MMDMA_TEST_MC_C)
//#error "we don't support TDDMA ADB and MC Y_only."
//#endif
////#if defined(MT6236_TDDMA_SUPPORT_DB) && !defined(MT6236_TDDMA_SUPPORT_ADB_H264)
////#error "we don't support TDDMA DB w/o ADB. (data incoherence, due to intra prediction"
////#endif
//#if defined(MT6236_TDDMA_SUPPORT_DB) && !defined(ROW_DB)
//#error "we don't support MT6236_TDDMA_SUPPORT_DB w/o ROW_DB."
//#endif
//#if defined(MT6236_TDDMA_SUPPORT_ADB_H264) && !defined(MMDMA_TEST_ADB_H264)
//#error "we don't support MT6236_TDDMA_SUPPORT_ADB w/o ROW_ADB."
//#endif
//#if defined(MT6236_TDDMA_SUPPORT_MC) && !defined(MMDMA_TEST_MC)
//#error "we don't support MT6236_TDDMA_SUPPORT_MC w/o MMDMA_TEST_MC."
//#endif
//
//#endif // SW_H264_DEC_SUPPORT

#endif   /*End __DRV_FEATURES_VCODEC_H__*/
