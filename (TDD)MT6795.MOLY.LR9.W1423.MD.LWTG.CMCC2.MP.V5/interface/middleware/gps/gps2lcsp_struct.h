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
 *  gps2lcsp_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for local parameter declaration about GIS sap
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __GPS2LCSP_STRUCT_H__
#define __GPS2LCSP_STRUCT_H__

#include "gps2lcsp_enum.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
        
#define GPS_ASSIST_DATA_SUB_ITEMS_FEILDS    16
#define GPS_ASSIST_DATA_N_SATE              8

#define GPS_ASSIST_DATA_N_SATE_DGPS                 16
#define GPS_ASSIST_DATA_N_SATE_NAVIGATION_MODEL     16
#define GPS_ASSIST_DATA_N_SATE_ALMANAC              32 /* According to Stanley Huang: max almanac sat number = 32, not 64 */
#define GPS_ASSIST_DATA_N_SATE_ACQUISITION          16
#define GPS_ASSIST_DATA_N_SATE_RTI                  16
#define GPS_ASSIST_DATA_N_SATE_MEAS                 16 /* max allowed = 16, but typical = 4 to 12 */
#define GPS_ASSIST_DATA_N_SATE_TOW_ASSIST           16

#define GPS_ASSIST_CMD_TIMER_EXP_INTERVAL           1500
#define GPS_QUERY_TIMER_INTERVAL                    500

#ifdef __AGPS_SUPPORT__

typedef struct 
{
    kal_uint8    semi_maj_uncertain;         /* K1 = 0-127, mandotary, horizontal accuracy, need converted by 23.032 sec 6.2 */
    kal_uint8    semi_min_uncertain;         /* K2 = 0-127, mandotary, horizontal accuracy, need converted by 23.032 sec 6.2 */
    kal_bool     altitude_uncertain_valid;   /* indicate if altitude_uncertain is valid */
    kal_uint8    altitude_uncertain;         /* K3 = 0-127, optional, vertical accuracy, need converted by 23.032 sec 6.4 */
    kal_bool     delay_valid;	             /* indiate if dealy is valid */
    kal_uint32   delay;                      /* optional, response time ms*/
    kal_bool     age_valid;                  /* indicate if age field is valid, */
    kal_uint16   age;                        /* 0 to 65535, optional, max location age, in sec */ 
    kal_bool     is_check_assist_data;       /*set to TRUE will response error if assist data not enough */                        

    kal_bool     is_gsm_gps_ref_time_wanted; /* set to TRUE if GSM GPS ref time was required to be reported */  
    
    kal_bool     is_utran_gps_ref_time_wanted;       /*Set to TRUE if UTRAN GPS ref time was required to be reported */  

    /* uarfcn and phyCellId are valid when is_utran_gps_ref_time_wanted == KAL_TRUE */
    kal_uint16 uarfcn;
    kal_uint16 phyCellId;

} gps_pos_qop_struct;

typedef struct 
{
    kal_bool     accuracy_valid;
    kal_uint8    accuracy;
    kal_uint32   delay;                      /* optional, response time ms*/
    kal_bool     is_check_assist_data;       /*Set to TRUE will response error if assist data not enough */                        

    kal_bool     is_gsm_gps_ref_time_wanted; /* set to TRUE if GSM GPS ref time was required to be reported */ 
    
    kal_bool     is_utran_gps_ref_time_wanted;       /*Set to TRUE if UTRAN GPS ref time was required to be reported */  

    /* uarfcn and phyCellId are valid when is_utran_gps_ref_time_wanted == KAL_TRUE */
    kal_uint16 uarfcn;
    kal_uint16 phyCellId;

} gps_meas_qop_struct;

typedef struct
{
    kal_uint16 hor_speed;   /*0-65536 .4remove and .5 add 1 unit is 1 km*/
} gps_h_velocity_struct;

typedef struct
{
    kal_uint32 hor_speed;   /*unit is 0.1 km*/
    kal_uint32 ver_speed;   /*unit is 0.1 km*/
} gps_hv_velocity_struct;

typedef struct
{
    kal_uint32 hor_speed;       /*unit is 0.1 km*/
    kal_uint32 hor_speed_uncertainty;
} gps_h_velocity_uncert_struct;

typedef struct
{
    kal_uint32 ver_direction;   /*degree*/
    kal_uint32 hor_speed;       /*unit is 0.1 km*/
    kal_uint32 ver_speed;       /*unit is 0.1 km*/
    kal_uint32 hor_speed_uncertainty;
    kal_uint32 ver_speed_uncertainty;
} gps_hv_velocity_uncert_struct;

typedef struct
{
    gps_velocity_type_enum type;
    union
    {
        gps_h_velocity_struct          hor_velocity;
        gps_hv_velocity_struct         hv_velocity;
        gps_h_velocity_uncert_struct   hor_uncertainty;
        gps_hv_velocity_uncert_struct  hv_uncertainty;
    } v;
} gps_velocity_struct;


typedef struct 
{
    kal_uint8   type;             /* only "ellipsoid point with altitude and uncertainty ellipsoid" 
                                     type (1001b) is supported*/
    kal_bool    sign_latitude;    /* true: SOUTH, false: NORTH */
    kal_uint32  latitude;         /* N1, encoded latitude */
    kal_uint32  longtitude;       /* N2, encoded longtitude with 2's complement */
    kal_bool    sign_altitude;    /* true: DEPTH, false: HEIGHT */
    kal_uint16  altitude;         /* no encoding, unit in meter */
    kal_uint8   unc_major;        /* K1, encoded r1 */
    kal_uint8   unc_minor;       /* K2, encoded r2 */
    kal_uint8   unc_bear;         /* N3, encoded a = 2N3, Bearing of semi-major axis (degrees)*/
    kal_uint8   unc_altitude;     /* K3, encode r3, vertical uncertain */
    kal_uint8   confidence;       /* %, The confidence by which the position of a target 
                                   entity is known to be within the shape description, 
                                   expressed as a percentage. [0 ~ 100] (%)*/
    gps_velocity_struct velocity; /*only support horizontal speed*/
    kal_uint16   bearing;    /*0-360 Direction of the horizontal speed*/
} gps_gad_pos_estimate_struct;

/* in position or measurement result */
typedef struct
{
    kal_uint16 ref_time_ms_part;
    kal_uint32 ref_time_ls_part;
   	
    kal_uint16 uarfcn;
    kal_uint16 phyCellId; // Must valid value
    kal_uint16 sfn;

    kal_bool   ref_time_uncertain_valid;
    kal_uint8  ref_time_uncertain;
} utran_gps_ref_time_result_struct;


typedef struct 
{
    kal_uint16  ref_frame; /* If refFrame is within (42432..65535), it shall be ignored by the receiver */
    kal_uint16  week;    /*gps week*/
    kal_uint32  tow;    /*msec*/
                                  /* GPS TOW [0 ~ 14399999] (msec) for which the location 
                                     estimate is valid, rounded down to the nearest 
                                     millisecond unit. RRLP Location Information element 
                                     only contains the 24 LSBs of GPS TOW.    */
    kal_uint8   fix_type;         /* position fix type performed by the GPS receiver: 
                                     '0' = 2D fix '1' = 3D fix*/
    gps_gad_pos_estimate_struct  pos_estimate;
} gps_pos_result_struct;


typedef struct 
{
    kal_uint8   sat_id;           /*The particular satellite for which the measurement data is valid. [1 ~ 32]*/
    kal_uint8   carrier_noise;    /*The estimate of the carrier-to-noise ratio of the received signal from the particular satellite used in the measurement. [0 ~ 63] (dB-Hz)*/
    kal_uint16  doppler;          /*0.2 Hz The Doppler measured by the MS for the particular satellite signal. [-32768 ~ 32767]*/
    kal_uint16  whole_chips;      /*chips The whole value of the code-phase measurement made by the GPS receiver for the particular satellite signal at the time of measurement. [0 ~ 1022] (chips)*/
    kal_uint16  fractional_chips; /*2^-10 chips  The fractional value of the code-phase measurement made by the GPS receiver for the particular satellite signal at the time of measurement. (2^-10 C/A chips) [0 ~ 1023]*/
    kal_uint8   multipath;        /*The multipath Indicator value. Possible values are listed below: 
                                   '0' = Not measured
                                   '1' = Low, MP error < 5m
                                   '2' = Medium, 5m < MP error < 43m
                                   '3' = High, MP error > 43m*/
    kal_uint8   pseudorang_m;      /*Pseudorange RMS Error Mantissa*/
    kal_uint8   pseudorang_e;      /*Pseudorange RMS Error Exponent*/
} gps_meas_para_struct;



typedef struct 
{
    kal_uint16  ref_frame; /* If refFrame is within (42432..65535), it shall be ignored by the receiver */
    kal_uint32  tow;
    /*GPS TOW [0 ~ 14399999] (msec) for which the location estimate is valid, rounded down to the nearest millisecond unit.
    RRLP GPS Measurement Information element only contains the 24 LSBs of GPS TOW.*/
    kal_uint8   sate_num;/*The number of GPS measurements for which measurement satellites are provided at the time of measurement*/
    gps_meas_para_struct    meas_param[GPS_ASSIST_DATA_N_SATE_MEAS];
} gps_meas_result_struct;


typedef struct 
{
    kal_uint8   sv;         /* sat id, 6 bits */
    kal_uint32   wn;         /* 10 bits, set to 0 */
    kal_uint8   c_a;        /*2 bits*/
    kal_uint8   ura;        /*4 bits*/
    kal_uint8   sv_health;  /*6 bits*/
    kal_uint16  iodc;       /*10 bits*/
    kal_uint8    l2p;        /* 1 bits */
    kal_uint32   sf1_23msb;  /* 23/87 bits, MSB */
    kal_uint32   sf1_24mb1;  /* 24/87 bits */
    kal_uint32   sf1_24mb2;  /* 24/87 bits */
    kal_uint16   sf1_16lsb;  /* 16/87 bits, LSB */
    kal_int8     tgd;        /* 8 bits */
    kal_uint16  toc;        /*16 bits*/
    kal_int8     af2;        /* 8 bits */
    kal_int16    af1;        /* 16 bits */
    kal_int32    af0;        /* 22 bits */
    kal_uint8    iode;       /* 8 bits, set to iodc 8bit lsb */
    kal_int16    crs;        /* 16 bits */
    kal_int16    delta_n;    /* 16 bits */
    kal_int32    m0;         /* 32 bits */
    kal_int16    cuc;        /* 16 bits */
    kal_uint32  e;          /*32 bits*/
    kal_int16    cus;        /* 16 bits */
    kal_uint32  sqrt_a;     /*32 bits*/
    kal_uint16  toe;        /*16 bits*/
    kal_uint8    fit;        /* 1 bits */
    kal_uint8   aodo;       /*5 bits*/
    kal_int16    cic;        /* 16 bits */
    kal_int32    omega0;     /* 32 bits */
    kal_int16    cis;        /* 16 bits */
    kal_int32    i0;         /* 32 bits */
    kal_int16    crc;        /* 16 bits */
    kal_int32    w;          /* 32 bits */
    kal_int32    omega_dot;  /* 24 bits */
    kal_int16    idot;       /* 14 bits */
} gps_assist_navigation_model_single_struct;
/*ephemeris in GPS chip  AGPS_P710*/


typedef struct 
{
    kal_uint8   n_sat;
    gps_assist_navigation_model_single_struct 
        navigation_data[GPS_ASSIST_DATA_N_SATE_NAVIGATION_MODEL];
} gps_assist_navigation_model_struct;
/*ephemeris in GPS chip  AGPS_P710*/


typedef struct 
{
    kal_uint8   data_id;    /*2 bits set to 01*/
    kal_uint8   sat_id;     /*6 bits*/
    kal_uint16  e;          /*16 bits*/
    kal_uint8   toa;        /*8 bits*/
    kal_int16   delta_i;    /*16 bits*/
    kal_int16   omega_dot;  /*16 bits*/
    kal_uint8   sv_health;  /*8 bits*/
    kal_uint32  sqrt_a;     /*24 bits*/
    kal_int32   omega0;     /*24 bits*/
    kal_int32   w;          /*24 bits*/
    kal_int32   m0;         /*24 bits*/
    kal_int16   af0;        /*11 bits*/
    kal_int16   af1;        /*11 bits*/
} gps_assist_almanac_single_struct;


typedef struct 
{
    kal_uint8 n_sat;
    kal_uint8  week; /*Almanac reference GPS week number*/
    gps_assist_almanac_single_struct almanac_data[GPS_ASSIST_DATA_N_SATE_ALMANAC];
} gps_assist_almanac_struct;

typedef struct 
{
    kal_uint16 tlm_word;        /*telemetry message[0-16383]*/
    kal_uint8  sat_id;          /*Sate PRN [1-32]*/
    kal_uint8  anti_spoof;      /*anti spoof flag[0,1]*/
    kal_uint8  alert;           /*alert flag*/
    kal_uint8  tlm_rsvd_bits;   /*2 bit reserved bits[0-3]*/
    
} gps_assist_tow_assist_struct;

//In "ref time" or "aquisition assitance"
typedef struct
{
    kal_uint16 ref_time_ms_part;
    kal_uint32 ref_time_ls_part;
   	
    kal_uint16 uarfcn;
    kal_uint16 phyCellId; // Must valid value
    kal_uint16 sfn;
   	
    uagps_cp_sfn_tow_uncertainty_type  sfn_tow_uncentainty_type;
    /* if type is UAGPS_CP_SFN_TOW_UNCERTAINTY_10MS_THRESHOLD, 0 for UAGPS_CP_SFN_TOW_UNCERTAINTY_LESS_THAN_10, 1 for UAGPS_CP_SFN_TOW_UNCERTAINTY_MORE_THAN_10, 
       if type is UAGPS_CP_SFN_TOW_UNCERTAINTY_MICROSECOND, unit is microsecond, 
       else don't care this field */
    kal_uint32 sfn_tow_Uncertainty;
   	
    kal_bool utran_gps_driftrate_valid;
    uagps_cp_utran_gps_driftrate utran_gps_driftrate;
   	
} utran_gps_ref_time_struct;


typedef struct
{
    kal_uint16 bcch_carrier; /* BCCH Carrier of 2G serving cell: 0~1023 */
    kal_uint8 bsic; /* BSIC of 2G serving cell: 0~63 */
    kal_uint32 FNm; /* FNm (frame number with MSB is truncated): 0~(2^21-1) */
    kal_uint8 tn; /* TN (timeslot number): 0~7 */
    kal_uint8 bn; /* BN (bit number): 0~156 */
} gsm_gps_ref_time_struct;


typedef struct 
{
    kal_uint16  week;       /*GPS week number spec not said range*/
    kal_uint32  tow;        /*unit0.08 GPS time of week of the transmission of the $ character at the start of the message [0 ~ 604800]*/
    kal_uint16  tow_rms;    /*set to 3000*/
    kal_uint16  fs_tow;     /*set to 0*/
    kal_uint16  fs_rms;     /*set to 0*/
    kal_uint8   n_sat;      /*number of tow assist sates*/
    gps_assist_tow_assist_struct tow_assist[GPS_ASSIST_DATA_N_SATE_TOW_ASSIST];
    
    /* 2G Timing Sync. Info */
    kal_bool                 gsm_gps_ref_time_valid;
    gsm_gps_ref_time_struct  gsm_gps_ref_time;

    /* 3G Timing Sync. Info */
    kal_bool                   utran_gps_ref_time_valid;
    utran_gps_ref_time_struct  utran_gps_ref_time;
    
} gps_assist_ref_time_struct;


typedef struct 
{
    kal_bool    sign_latitude;    /* true: SOUTH, false: NORTH */
    kal_uint32  latitude;         /* N1, encoded latitude */
    kal_uint32  longitude;       /* N2, encoded longtitude with 2's complement */
    kal_bool    sign_altitude;    /* true: DEPTH, false: HEIGHT */
    kal_uint16  altitude;         /* no encoding, unit in meter */
    kal_uint16  unc_smaj;   /* in m */
    kal_uint16  unc_smin;   /* in m */
    kal_uint16  bearing;    /* in degree */
    kal_uint16  unc_vert;   /* in m, uncertain altitue */
    kal_uint8   confidence; /* 0 to 100, in % */
} gps_assist_ref_location_struct;   


typedef struct 
{
    kal_int8   a0;  /*Alpha0 (x 2^-30 seconds)*/
    kal_int8   a1;  /*Alpha1 (x 2^-27 seconds per semicircle)*/
    kal_int8   a2;  /*Alpha2 (x 2^-24 seconds per semicircle ^2)*/
    kal_int8   a3;  /*Alpha3 (x 2^-24 seconds per semicircle ^3)*/
    kal_int8   b0;  /*Beta0 (x 2 ^ 11 seconds)*/
    kal_int8   b1;  /*Beta1 (x 2 ^ 14 seconds per semicircle)*/
    kal_int8   b2;  /*Beta2 (x 2 ^ 16 seconds per semicircle ^2)*/
    kal_int8   b3;  /*Beta3 (x 2 ^ 16 seconds per semicircle ^3)*/
} gps_assist_ionosphere_struct;


typedef struct 
{
    kal_int32   a1;
    kal_int32   a0;
    kal_uint8   tot;
    kal_uint8   wnt;
    kal_int8    delta_ls;
    kal_uint8   wnlsf;
    kal_int8    dn;
    kal_int8    delta_lsf;
} gps_assist_utc_struct;


typedef struct 
{
    kal_uint8   number_bad;
    kal_uint8   bad_svid[GPS_ASSIST_DATA_N_SATE_RTI];    /* 6 bits for each sat */
} gps_assist_real_time_integrity_struct;


typedef struct 
{
    kal_uint8   sv_id;      /*Satellite PRN number [1~32]*/
    kal_int16   dopp0;      /*unit 2.5Hz, 0th order term of satellite Doppler [-2048 ~ 2047]*/
    kal_int8    dopp1;      /*unit 1/42Hz, 1th order term of satellite Doppler [-42.0 ~ 21]*/
    kal_uint8   dopp_sr;    /*Doppler search range [2^-n * (200) Hz, n = 0 - 4]*/
    kal_uint16  code_p;     /*GPS satellite code chips [0 ~ 1022] (chip)*/
    kal_uint8   int_code;   /*Integer code phase [0 ~ 19]*/
    kal_uint8   bit;        /*GPS bit number [0 ~ 3]*/
    kal_uint8   code_sr;    /*Code phase search window [GPS task will lookup table covert to 1 ~ 512]*/
    kal_uint8   azimuth;    /*unit 11.25 deg,Satellite azimuth angle [0 ~ 31]*/
    kal_uint8   elevation;  /*unit 11.25 deg, Satellite elevation angle [0 ~ 7]*/
} gps_assist_acquisition_single_struct;

typedef struct 
{
    kal_uint8   n_sat;      /* 4 bits */
    kal_uint32  tow;        /*unit 0.08sec, GPS time of week [0 ~ 7559999]  23bits*/
    gps_assist_acquisition_single_struct sate_data[GPS_ASSIST_DATA_N_SATE_ACQUISITION];
    
    /* 2G Timing Sync. Info */
    kal_bool                 gsm_gps_ref_time_valid;
    gsm_gps_ref_time_struct  gsm_gps_ref_time;

    /* 3G Timing Sync. Info */
    kal_bool                   utran_gps_ref_time_valid;
    utran_gps_ref_time_struct  utran_gps_ref_time;
} gps_assist_acquisition_struct;


typedef struct
{
    kal_uint8   sat_id; /*Satellite PRN for which the corrections are applicable [1 ~ 32]*/
    kal_uint8   iode;   /*The sequence number [0 ~ 255] for the sphemeris for the particular satellite.*/
    kal_uint8   udre;   /*Provides an estimate [0 ~ 3] of the uncertainty (1-sigma) in the corrections for the particular satellite.*/
    kal_int16   prc;    /*Unit 0.32m, The correction [+/-2047] to the pseudorange for the particular satellite at the GPS Reference Time.*/
    kal_int8    rrc;    /*Unit 0.032m, The rate of change of the pseudorange correction [+/- 127] for the particular satellite.*/
} gps_assist_dgps_sate_data_struct;

typedef struct 
{
    kal_uint32  tow;    /*Unit sec, GPS TOW [0 ~ 604799] indicates the baseline time for which the corrections are valid*/
    kal_uint8   status; /*This field indicates the status [0 ~ 7] of the differential corrections contained in the broadcast message. The "UDRE Factor" value is applied to the UDRE values contained in the message.*/
    kal_uint8   n_sat;  /*The number of satellites for which differential corrections are available. Corrections for up to 11 satellites.*/
    gps_assist_dgps_sate_data_struct sat_data[GPS_ASSIST_DATA_N_SATE_DGPS];
} gps_assist_dgps_correction_struct;

typedef struct 
{
    kal_uint16  ref_bcch_carrier; /* ARFCN of current serving cell */
    kal_uint8   ref_bsic; /* BSIC of current serving cell */
} gps_gsm_loc_info_struct;

typedef struct 
{
    kal_bool    ref_frame_msb_valid;
    kal_uint8   ref_frame_msb;
    kal_bool    tow_subms_valid;
    kal_uint16  tow_subms;
    kal_bool    delta_tow_valid;
    kal_uint8   delta_tow;
    kal_bool    ref_time_unc_valid;
    kal_uint8   ref_time_unc;
} gsm_gps_ref_time_result_struct;


typedef struct 
{
    kal_uint16    w_n;
    kal_uint16    toe;
    kal_uint8     n_sat;
    kal_uint8     limit;
    kal_uint8     sat_id[GPS_ASSIST_DATA_SUB_ITEMS_FEILDS];
    kal_uint16    iode[GPS_ASSIST_DATA_SUB_ITEMS_FEILDS];
} gps_sat_related_data_struct;
         

typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8           transaction_id;
    kal_bool            req_time_assist_meas;
    kal_bool     environment_valid;
    kal_uint8    environment;
    gps_pos_qop_struct  qop;
    lcs_sim_source_enum sim_source;  /* for Gemini SIM1/SIM2 */ 
    /**
     * Doug 20130326
     * CP Auto Reset refine for OTA TIS 3G:
     * if network does not sent RESET msg, periodicalReporting with reportingAmount is ra1
     * autoResetTrigger is set to TRUE, and inform GPS task within POS(MEAS)_GAD_REQ.
     */
    kal_bool     autoResetTrigger;
} gps_pos_gad_req_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8   transaction_id;
    gps_error_code_enum error_code;
    kal_bool    bitmap_valid;
    kal_uint16  bitmap;
    gps_sat_related_data_struct sat_data;
    gps_pos_result_struct       pos_result;
    
    kal_bool    gsm_loc_info_valid;
    gps_gsm_loc_info_struct gsm_loc_info; /* for 2G ref. time timing sync. to indicate the serving cell */
    
    kal_bool    gsm_gps_ref_time_result_valid;
    gsm_gps_ref_time_result_struct gsm_gps_ref_time_result;
    
    kal_bool    utran_gps_ref_time_result_valid;
    utran_gps_ref_time_result_struct utran_gps_ref_time_result;
} gps_pos_gad_cnf_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8   transaction_id;
    kal_bool    req_time_assist_meas;
    kal_bool     environment_valid;
    kal_uint8    environment;
    gps_meas_qop_struct qop;
    lcs_sim_source_enum sim_source;  /* for Gemini SIM1/SIM2 */ 
    /**
     * Doug 20130326
     * CP Auto Reset refine for OTA TIS 3G:
     * if network does not sent RESET msg, periodicalReporting with reportingAmount is ra1
     * autoResetTrigger is set to TRUE, and inform GPS task within POS(MEAS)_GAD_REQ.
     */
    kal_bool     autoResetTrigger;
} gps_lcsp_meas_gad_req_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8   transaction_id;
    gps_error_code_enum error_code;
    kal_bool    bitmap_valid;
    kal_uint16  bitmap;
    gps_sat_related_data_struct sat_data;
    gps_meas_result_struct      meas_result;

    kal_bool    gsm_loc_info_valid;
    gps_gsm_loc_info_struct gsm_loc_info; /* for 2G ref. time timing sync. to indicate the serving cell */

    kal_bool    gsm_gps_ref_time_result_valid;
    gsm_gps_ref_time_result_struct gsm_gps_ref_time_result;
    
    kal_bool    utran_gps_ref_time_result_valid;
    utran_gps_ref_time_result_struct utran_gps_ref_time_result;
} gps_lcsp_meas_gad_cnf_struct;

typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8   transaction_id;
} gps_lcsp_abort_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
} gps_lcsp_agps_restart_ind_struct;


typedef union {
        gps_assist_navigation_model_struct      navigation_model;
        gps_assist_almanac_struct               almanac;
        gps_assist_ref_time_struct              ref_time;
        gps_assist_ref_location_struct          ref_location;
        gps_assist_ionosphere_struct            ionosphere;
        gps_assist_utc_struct                   utc;
        gps_assist_dgps_correction_struct       dgps;
        gps_assist_acquisition_struct           acquisition;
        gps_assist_real_time_integrity_struct   rti;
} assist_data_union;

typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8   transaction_id;
    kal_bool    req_time_assist_meas;
    gps_assist_data_type_enum type;
    assist_data_union         assist_data;
    kal_bool    ref_time_uncertain_valid;
    kal_uint32  ref_time_uncertain;
    lcs_sim_source_enum sim_source;  /* for Gemini SIM1/SIM2 */  
} gps_lcsp_assist_data_req_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8   transaction_id;
    gps_assist_data_type_enum   type;
    gps_result_enum    result;
} gps_lcsp_assist_data_cnf_struct;
#endif /*__AGPS_SUPPORT__*/
#endif /*__GPS2LCSP_STRUCT_H__*/

