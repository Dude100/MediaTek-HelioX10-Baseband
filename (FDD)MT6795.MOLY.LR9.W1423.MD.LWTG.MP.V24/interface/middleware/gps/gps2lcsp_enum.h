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

/*******************************************************************************
 * Filename:
 * ---------
 *  gps2lcsp_enum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is the enum of GPS
 *
 * Author:Wang Hai
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#ifndef __GPS_ENUM_H__
#define __GPS_ENUM_H__

typedef enum
{
    GPS_ERR_NO_ERROR = 0,
    GPS_ERR_UNKOWN_ERR,
    GPS_ERR_NOT_ENOUGH_SAT,
    GPS_ERR_LOC_CALC_DATA_MISS,
    GPS_ERR_ASSIST_DATA_MISS,
    GPS_ERR_TOO_MANY_REQ,
    GPS_ERR_LOC_REQ_NOT_PROCESSED,
    GPS_ERR_REQ_TIMEOUT,
    GPS_ERR_REQ_METHOD_NOT_SUPPORT,  /* for RRLP usage */
    GPS_ERR_REQ_REF_BTS_NOT_SERV     /* for RRLP usage */     

    ,GPS_ERR_REQ_REF_TIME_NOT_MEASUREED     /* for UTRAN GPS ref time */     
    ,GPS_ERR_REQ_REF_SFN_NOT_DECODED        /* for ULCS usage */     

} gps_error_code_enum;


typedef enum
{
    GPS_RESULT_OK,
    GPS_RESULT_ERROR,
    GPS_RESULT_END
} gps_result_enum;


typedef enum
{
    GPS_ASSIST_RTI = 0,             /*PMTK717*/
    GPS_ASSIST_ACQUISITION,         /*PMTK718*/
    GPS_ASSIST_ALMANAC,             /*PMTK711*/
    GPS_ASSIST_UTC,                 /*PMTK716*/
    GPS_ASSIST_IONOSPHERE,          /*PMTK715*/
    GPS_ASSIST_NAVIGATION_MODEL,    /*PMTK710*/
    GPS_ASSIST_DGPS_CORRECTION,     /*PMTK720*/
    GPS_ASSIST_REF_LOCATION,        /*PMTK713*/
    GPS_ASSIST_REF_TIME             /*PMTK712*/
} gps_assist_data_type_enum;


typedef enum
{
    GPS_VELOCITY_HOR,
    GPS_VELOCITY_HOR_AND_VER,
    GPS_VELOCITY_HOR_UNCERT,
    GPS_VELOCITY_HOR_AND_VER_UNCERT,
    GPS_VELOCITY_END
} gps_velocity_type_enum;

#define GPS_ASSIST_WRONG_ASSIST_DATA_TYPE       0

#define GPS_ASSIST_MASK_ALMANAC                 (1<<0)
#define GPS_ASSIST_MASK_UTC                     (1<<1)
#define GPS_ASSIST_MASK_IONOSPHERE              (1<<2)
#define GPS_ASSIST_MASK_NAVIGATION_MODEL        (1<<3)
#define GPS_ASSIST_MASK_DGPS_CORRECTION         (1<<4)
#define GPS_ASSIST_MASK_REF_LOCATION            (1<<5)
#define GPS_ASSIST_MASK_REF_TIME                (1<<6)
#define GPS_ASSIST_MASK_ACQUISITION             (1<<7)
#define GPS_ASSIST_MASK_RTI                     (1<<8)

/* Adeline */
#define GPS_ASSIST_MB_MANDATORY_MASK            (GPS_ASSIST_MASK_UTC | \
                                                 GPS_ASSIST_MASK_IONOSPHERE | \
                                                 GPS_ASSIST_MASK_NAVIGATION_MODEL | \
                                                 GPS_ASSIST_MASK_REF_LOCATION | \
                                                 GPS_ASSIST_MASK_REF_TIME | \
                                                 GPS_ASSIST_MASK_RTI)
                                                 
#define  GPS_ASSIST_MA_MANDATORY_MASK           (GPS_ASSIST_MASK_ACQUISITION | \
                                                 GPS_ASSIST_MASK_REF_TIME)
                                                 

#define GPS_ASSIST_TIME_INDEPENDENT_MASK        (GPS_ASSIST_MASK_REF_LOCATION)


#define GPS_DEFAULT_PORT     (0xAA)

typedef enum
{
    GPS_CHIP_WORK_MODE_MA = 0,  
    GPS_CHIP_WORK_MODE_MB,  
    GPS_CHIP_WORK_MODE_NO_LOCK,  
    GPS_CHIP_WORK_MODE_NORMAL,  
    GPS_CHIP_WORK_MODE_CLEAN_AND_CLOSE,  
    GPS_CHIP_WORK_MODE_END  
} gps_chip_work_mode_enum;



// NEW
/* ENUMERATED SFN-TOW-Uncertainty */
typedef enum
{
   UAGPS_CP_SFN_TOW_UNCERTAINTY_NONE,
   UAGPS_CP_SFN_TOW_UNCERTAINTY_10MS_THRESHOLD,
   UAGPS_CP_SFN_TOW_UNCERTAINTY_MICROSECOND

} uagps_cp_sfn_tow_uncertainty_type;

/* ENUMERATED UTRAN-GPS-DriftRate */
typedef enum
{
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_0,
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_1,
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_2,
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_5,
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_10,
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_15,
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_25,
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_50,
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_MINUS_1,
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_MINUS_2,
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_MINUS_5,
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_MINUS_10,
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_MINUS_15,
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_MINUS_25,
   UAGPS_CP_UTRAN_GPS_DRIFTRATE_MINUS_50
   
} uagps_cp_utran_gps_driftrate;

typedef enum
{
    LCS_UP_SIM_SOURCE_NOT_CARE, /* for user plane */
    LCS_CP_FROM_SIM1,           /* for control plane Gemini SIM1 or single SIM */
    LCS_CP_FROM_SIM2,            /* for control plane Gemini SIM2 */
    LCS_CP_FROM_SIM3,            /* for control plane Gemini SIM3 */
    LCS_CP_FROM_SIM4            /* for control plane Gemini SIM4 */
} lcs_sim_source_enum;

#endif /*__GPS_ENUM_H__*/

