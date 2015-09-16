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

/*******************************************************************************
* Filename:
* ---------
*  agps_struct.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  AGPS related structure define in GPS task
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*******************************************************************************/
#ifndef __GPS_AGPS_H__
#define __GPS_AGPS_H__

#include "gps_main.h"
#include "gps2lcsp_struct.h"
#include "gps2lcsp_enum.h"

#include "kal_general_types.h"    

#if defined(__AGPS_SUPPORT__)
#define GPS_AGPS_QOP_POS_ARRAY_MAX   GPS_AGPS_POS_REQ_TIMER_MAX
#define GPS_AGPS_QOP_MEAS_ARRAY_MAX  GPS_AGPS_MEAS_REQ_TIMER_MAX

typedef struct 
{
    kal_uint16    bitmap;    /*see define of GPS_ASSIST_MASK_RTI enum*/
    gps_sat_related_data_struct sat_data;
} gps_assist_bitmap_struct;


typedef struct 
{
    kal_uint16  frame;
    kal_uint16  week;
    kal_uint32  tow;
    kal_uint8   fix;
    double       latitude;         /*latitude */
    double       longtitude;       /* N2, encoded longtitude with 2's complement */
    double       altitude;         /* no encoding, unit in meter */
    kal_uint16   unc_major;        /* K1, encoded r1 */
    kal_uint16   unc_minor;       /* K2, encoded r2 */
    kal_uint16   unc_bear;         /* N3, encoded a = 2N3, Bearing of semi-major axis (degrees)*/
    kal_uint16   unc_vert;     /* K3, encode r3, vertical uncertain */
    kal_uint8   confidence;       /* %, The confidence by which the position of a target 
                                   entity is known to be within the shape description, 
                                   expressed as a percentage. [0 ~ 100] (%)*/
    double       h_speed; /*horizontal speed*/
    kal_uint16   bearing;    /*Direction of the horizontal speed*/
    kal_uint32  ticks;
} gps_agps_pos_struct;

typedef struct 
{
    gps_error_code_enum error_code;
} gps_agps_loc_error_struct;

#ifdef __SMART_PHONE_MODEM__
// MODEM_DEV_TEST move from mnl header file
#if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)  
typedef enum _mtk_gps_frame_sync_type_enum
{
   GPS_FRAME_SYNC_TYPE1 = 0,
   GPS_FRAME_SYNC_TYPE2,
   GPS_FRAME_SYNC_TYPE3,
} mtk_gps_frame_sync_type_enum;
#endif /* (__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__) */
typedef enum
{
  MTK_GPS_FS_RESULT_INIT = 0,           /* FS request initial value  */
  MTK_GPS_FS_RESULT_ERR,                /* FS request error and clear naram's data  */
  MTK_GPS_FS_RESULT_ERR_NOT_CLR,        /* FS request error but don't clear nvram's data */
  MTK_GPS_FS_RESULT_OK                  /* FS request success */  
} mtk_gps_fs_result;

typedef enum
{
  MTK_GPS_FS_WORK_MODE_AIDING = 0,      /* FS request for aiding phase  */
  MTK_GPS_FS_WORK_MODE_MAINTAIN         /* FS request for maintain phase  */
} mtk_gps_fs_work_mode;

/* MTK_PARAM_FRAME_SYNC_RESP : receive a result of a frame sync meas request */
typedef struct
{
  mtk_gps_fs_result eResult;            /* frame sync measurement request result */  
  double            dfFrameTime;        /* frame time of the issued frame pulse */
} mtk_param_frame_sync_resp;

#endif

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
/* under construction !*/
#endif

#endif /*__AGPS_SUPPORT__*/
#endif /*__GPS_AGPS_H__*/


