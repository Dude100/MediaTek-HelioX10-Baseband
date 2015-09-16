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
 *   gnss2lcsp_struct.h
 *
 * Project:
 * --------------------------------------------------------
 *   A-GNSS project
 *
 * Description:
 * --------------------------------------------------------
 *
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
 * TOD issue.
 *
 * removed!
 * removed!
 *
 *
 *****************************************************************************/

#ifndef _GNSS2LCSP_STRUCT_H
#define _GNSS2LCSP_STRUCT_H

#include "gnss2lcsp_enum.h"
#include "mcd_l3_inc_struct.h" /* for PLMN id */
#include "kal_public_api.h"
#include "kal_general_types.h"
        
//#if defined(__AGNSS_SUPPORT__) || defined(__AGPS_SUPPORT__)  /* should add a new compile option __AGNSS_SUPPORT__*/


/*=== GNSS Common Assistance Data ===*/

/* start for gnss reference time */
typedef struct
{
    kal_uint8   svID;         /* satellite PRN [1..64] */
    kal_uint16  tlmWord;      /* telemetry message [0..16383] */
    kal_uint8   antiSpoof;    /* anti spoof flag [0..1] */
    kal_uint8   alert;        /* alert flag [0..1] */
    kal_uint8   tlmRsvdBits;  /* 2 bit reserved bits [0..3] */
} gnss_gps_tow_assist_struct;


typedef struct
{
    gnss_id_enum                gnssTimeID;
    /**
     * This field specifies the sequential number of days from the origin of the GNSS System Time as follows: 
     * GPS, QZSS, SBAS ¡V Days from January 6th 1980 00:00:00 UTC(USNO)
     * Galileo ¡V TBD; 
     * GLONASS ¡V Days from January 1st 1996
     */
    kal_uint16                  gnssDayNumber;           /* [0..32767] */
    kal_uint32                  gnssTimeOfDay;           /* [0..86399] in seconds */
    kal_bool                    gnssTimeOfDayFracMsecValid;
    kal_uint16                  gnssTimeOfDayFracMsec;   /* [0..999] in milli-seconds */
    kal_bool                    notificationLeapSecondValid;
    kal_uint8                   notificationLeapSecond;  /* only present when gnss=GLONASS */
    kal_uint8                   numGpsTowAssist;         /* only present when gnss=GPS */
    gnss_gps_tow_assist_struct  gpsTowAssist[GNSS_MAX_REF_TIME_SAT_ELEMENT];
} gnss_system_time_struct;


typedef struct
{
    kal_uint16      physCellId;  /* [0..503] */
    kal_uint32      earfcn;      /* [0..262143], 65535 is invalid to indicate ARFCN-ValueEUTRA-v9a0 present */    
    /* optional field */
    kal_bool        plmnIdValid;
    plmn_id_struct  plmnId;
    kal_bool        cellIdValid;
    kal_uint32      cellId;      /* eutra 28 bits */
} gnss_eutra_cell_id_struct;


typedef struct
{
    kal_uint16      physCellId;  /* [0..511] */
    kal_uint16      uarfcn;      /* [0..16383] */
    /* optional field */
    kal_bool        plmnIdValid;
    plmn_id_struct  plmnId;
    kal_bool        cellIdValid;
    kal_uint32      cellId;      /* utra 32 bits */ 
} gnss_utra_cell_id_struct;


typedef struct
{
    kal_uint16      bcchCarrier;  /* [0..1023] */
    kal_uint8       bsic;         /* [0..63] */
    /* optional field */
    kal_bool        plmnIdValid;
    plmn_id_struct  plmnId;
    kal_bool        cellIdValid;  /* this validity flag indicate if lac and cellId are present or not */
    kal_uint16      lac;          /* lac 16 bits */
    kal_uint16      cellId;       /* gsm 16 bits */
} gnss_gsm_cell_id_struct;


typedef struct
{
   gnss_network_cell_type_enum     type;

   union
   {
      gnss_eutra_cell_id_struct    eutra;
      gnss_utra_cell_id_struct     utra;
      gnss_gsm_cell_id_struct      gsm;
   }
   data;
} gnss_network_cell_id_struct;


typedef struct
{
   /* The total time since the particular frame structure start is secondsFromFrameStructureStart + fractionalSecondsFromFrameStructureStart  */
   kal_uint16                   secondsFromFrameStructureStart;            /* [0-12533] in seconds, this field specifies the number of seconds from the beginning of the longest frame structure in the corresponding air interface */
   kal_uint32                   fractionalSecondsFromFrameStructureStart;  /* [0-3999999] in 250 nano-seconds, This field specifies the fractional part of the secondsFromFrameStructureStart  in 250 ns resolution */
   kal_bool                     framDriftValid;
   kal_int8                     frameDrift;                                /* [-64~63] in 2^(-30) seconds/second */
   gnss_network_cell_id_struct  cellID;
} gnss_network_time_struct;


typedef struct
{
   gnss_network_time_struct  networkTime;
   kal_bool                  referenceTimeUncValid;
   kal_uint8                 referenceTimeUnc;  /* K = [0..127], uncertainty r (microseconds) = C*(((1+x)^K)-1), C=0.5, x=0.14 */
   kal_bool                  bsAlignValid;
   kal_bool                  bsAlign;           /* indicate all cell with the same carrier freq. and TA/LA/RA are frame aligned */
} gnss_ref_time_one_cell_struct;


typedef struct
{
    gnss_system_time_struct        systemTime;
    kal_bool                       referenceTimeUncValid;
    kal_uint8                      referenceTimeUnc;  /* K = [0..127], uncertainty r (microseconds) = C*(((1+x)^K)-1), C=0.5, x=0.14 */
    kal_uint8                      numGnssReferenceTimeForCells;
    gnss_ref_time_one_cell_struct  gnssReferenceTimeForCells[GNSS_MAX_REF_CELL_FTA_ELEMENT];
} gnss_reference_time_struct;
/* end for gnss reference time */


/* start for gnss reference location */
typedef struct
{
    kal_bool    signOfLatitude;        /* TRUE: SOUTH, FALSE: NORTH */
    kal_uint32  degreesLatitude;       /* [0..8388607] */
    kal_int32   degreesLongitude;      /* [-8388608..8388607] */
    kal_bool    signOfAltitude;        /* TRUE: DEPTH, FALSE: HEIGHT */
    kal_uint16  altitude;              /* [0..32767] */
    kal_uint8   uncertaintySemiMajor;  /* K: [0..127], uncertainty r (meter) = C*((1+x)^K-1), C=10, x=0.1 */
    kal_uint8   uncertaintySemiMinor;  /* K: [0..127], uncertaintyr (meter) = C*((1+x)^K-1), C=10, x=0.1 */
    kal_uint8   orientationMajorAxis;  /* bearing angle degree: [0-179] */
    kal_uint8   uncertaintyAltitude;   /* K: [0..127], uncertainty h (meter) = C*((1+x)^K-1), C=45, x=0.025 */
    kal_uint8   confidence;            /* [0..100] */
} gnss_reference_location_struct;
/* end for gnss reference location */


/* start for gnss ionospheric model */
typedef struct
{
    kal_bool  isQzssData;
    kal_int8  alfa0;  /* alpha0 [-128..127] (* 2^-30 seconds) */
    kal_int8  alfa1;  /* alpha1 [-128..127] (* 2^-27 seconds/semicircle) */
    kal_int8  alfa2;  /* alpha2 [-128..127] (* 2^-24 seconds/semicircle^2) */
    kal_int8  alfa3;  /* alpha3 [-128..127] (* 2^-24 seconds/semicircle^3) */
    kal_int8  beta0;  /* beta0  [-128..127] (* 2^11 seconds) */
    kal_int8  beta1;  /* beta1  [-128..127] (* 2^14 seconds/semicircle) */
    kal_int8  beta2;  /* beta2  [-128..127] (* 2^16 seconds/semicircle^2) */
    kal_int8  beta3;  /* beta3  [-128..127] (* 2^16 seconds/semicircle^3) */
} gnss_klobuchar_model_paras_struct;


typedef struct
{
    kal_uint16  ai0;  /* [0..4095] */
    kal_uint16  ai1;  /* [0..4095] */
    kal_uint16  ai2;  /* [0..4095] */

    /* optional field */
    /**
     * iono storm flag represent five region: [value 0: no disturbance, value 1: disturbance]
     *  region 1: for the northern region (60¢X<MODIP<90¢X)
     *  region 2: for the northern middle region (30¢X<MODIP<60¢X)
     *  region 3: for the equatorial region (-30¢X<MODIP<30¢X)
     *  region 4: for the southern middle region (-60¢X<MODIP<-30¢X)
     *  region 5: for the southern region (-90¢X<MODIP<-60¢X)
     */
    kal_bool    ionoStormFlag1Valid;
    kal_bool    ionoStormFlag1;
    kal_bool    ionoStormFlag2Valid;
    kal_bool    ionoStormFlag2;
    kal_bool    ionoStormFlag3Valid;
    kal_bool    ionoStormFlag3;
    kal_bool    ionoStormFlag4Valid;
    kal_bool    ionoStormFlag4;
    kal_bool    ionoStormFlag5Valid;
    kal_bool    ionoStormFlag5;
} gnss_nequick_model_paras_struct;


typedef struct
{
    kal_bool                           klobucharModelValid;  /* for GPS, GLONASS, etc... */
    gnss_klobuchar_model_paras_struct  klobucharModel;
    kal_bool                           neQuickModelValid;    /* for Galileo */
    gnss_nequick_model_paras_struct    neQuickModel;
} gnss_ionospheric_model_struct;
/* end for gnss ionospheric model */


/* start for gnss earth orientation parameters */
typedef struct
{
    kal_uint16  teop;         /* [0..65535], EOP data reference time in seconds, scale factor 2^4 seconds */
    kal_int32   pmX;          /* [-1048576..1048575], X-axis polar motion value at reference time in arc-seconds, scale factor 2^(-20) arc-seconds */
    kal_int16   pmXdot;       /* [-16384..16383], X-axis polar motion drift at reference time in arc-seconds/day, scale factor 2^(-21) arc-seconds/day */
    kal_int32   pmY;          /* [-1048576..1048575], Y-axis polar motion value at reference time in arc-seconds, scale factor 2^(-20) arc-seconds */
    kal_int16   pmYdot;       /* [-16384..16383] Y-axis polar motion drift at reference time in arc-seconds/day, scale factor 2^(-21) arc-seconds/day */
    kal_int32   deltaUT1;     /* [-1073741824..1073741823], UT1-UTC diff at reference time in seconds, scale factor 2^(-24) seconds */
    kal_int32   deltaUT1dot;  /* [-262144..262143], the rate of UT1-UTC diff at reference time in seconds/day, scale factor 2^(-25) seconds/day */
} gnss_earth_orient_params_struct;
/* end for gnss earth orientation parameters */


/*=== GNSS Generic Assistance Data ===*/

/* start for gnss time model */
/**
 * in LPP, location server could provide up to 15 GNSS-GNSS system time offset
 * in RRC/RRLP, location server could provide up to 7 GNSS-GNSS system time offset
 * i.e. generic assist data is for GPS, time model could provide GPS-GLONASS time offset
 */
typedef struct
{
    /* note that RRC/RRLP tA0, tA1 range is larger than LPP, although scale factor is the same */
    kal_uint16        gnssTimeModelRefTime;  /* [0..65535], the reference time of week, scale factor 2^4 seconds */
    kal_int32         tA0;                   /* [-67108864..67108863] for LPP, [-2147483648 .. 2147483647] for RRC/RRLP, the bias coefficient, scale factor 2^(-35) seconds */
    kal_bool          tA1Valid;
    kal_int32         tA1;                   /* [-4096..4095] for LPP, [-8388608 .. 8388607] for RRC/RRLP, the drift coefficient, scale factor 2^(-51) seconds/second */
    kal_bool          tA2Valid;
    kal_int8          tA2;                   /* [-64..63], the drift rate correction coefficient, scale factor 2^(-68) seconds/second^2 */
    gnss_to_id_enum   gnssToId;              /* GPS, Galileo, QZSS, GLOANSS */
    /* optional field */
    kal_bool          weekNumberValid;
    kal_uint16        weekNumber;            /* [0..8191], the reference week */
    kal_bool          deltaTValid;
    kal_int8          deltaT;                /* [-128..127], the integer number of seconds of GNSS-GNSS time offset */
} gnss_time_model_element_struct;


typedef struct
{
    kal_uint8                       numTimeModels;
    gnss_time_model_element_struct  gnssTimeModels[GNSS_MAX_TIME_MODEL_ELEMENT];  /* 5-15 is reserved */
} gnss_time_model_list_struct;

/* end for gnss time model */


/* start for gnss dgnss correction */
typedef struct
{
   kal_uint8   svID;                   /* [0..63] */
   kal_uint16  iod;                    /* [11 bits], for issue of data field */
   kal_uint8   udre;                   /* [0-3] */
   kal_int16   pseudoRangeCor;         /* [-2047..2047], the correction to the pseudorange for the particular satellite at dgnssRefTime, scale factor 0.32 meters */
   kal_int8    rangeRateCor;           /* [-127..127], the rate-of-change of the pseudorange correction for the particular satellite, scale factor 0.032 meters/sec */
   /* optional field */
   kal_bool    udreGrowthRateValid;
   kal_uint8   udreGrowthRate;         /* [0-7], an estimate of the growth rate of uncertainty (1-£m) in the corrections for the particular satellite */
   kal_bool    udreValidityTimeValid;
   kal_uint8   udreValidityTime;       /* [0-7], the time when the udreGrowthRate field applies and is included if udreGrowthRate is included */
} gnss_dgnss_corrections_element_struct;


typedef struct
{
    kal_uint8                              gnssSignalId;  /* map to GNSS_SGN_ID_VALUE_* */
    kal_uint8                              gnssStatusHealth;  /* [0-7], for UDRE scale factor */
    kal_uint8                              numCorrectionElements;
    gnss_dgnss_corrections_element_struct  correctionElements[GNSS_MAX_DGNSS_CORRECTION_INFO_ELEMENT];
} gnss_dgnss_signal_type_element_struct;


typedef struct
{
    kal_uint16                             dgnssRefTime;  /* [0..3599], the time for which the DGNSS corrections are valid, modulo 1 hour, scale factor 1 seconds */
    kal_uint8                              numSgnTypes;
    gnss_dgnss_signal_type_element_struct  sgnTypes[GNSS_MAX_DGNSS_SGN_TYPE_ELEMENT];
} gnss_diff_correction_struct;
/* end for gnss dgnss correction */


/* start for gnss navigation model */
typedef struct
{
    kal_uint16  stanClockToc;      /* [0..16383], scale factor 60 seconds */
    kal_int16   stanClockAF2;      /* [-2048..2047], scale factor 2^(-65) seconds/seconds^2 */
    kal_int32   stanClockAF1;      /* [-131072..131071], scale factor 2^(-45) seconds/second */
    kal_int32   stanClockAF0;      /* [-134217728..134217727], scale factor 2^(-33) seconds */
    /* optional field */
    kal_bool    stanClockTgdValid;
    kal_int16   stanClockTgd;      /* [-512..511], scale factor 2^(-32) seconds */
    kal_bool    stanModelIdValid;
    kal_uint8   stanModelID;       /* [0..1], 0 for I/Nav, 1 for F/Nav Galileo clock clock */
} gnss_std_clock_model_element_struct;


typedef struct
{
    kal_uint8                            numStdClkElement;
    gnss_std_clock_model_element_struct  stdClkElement[GNSS_MAX_NAV_STD_CLK_MODEL_ELEMENT];
} gnss_standard_clock_model_struct;


typedef struct
{
    kal_uint16  navToc;  /* [0..37799], time of clock, scale factor 2^4 seconds */
    kal_int8    navaf2;  /* [-128..127], clock correction polynomial coefficient, scale factor 2^(-55) seconds/second^2 */
    kal_int16   navaf1;  /* [-32768..32767], clock correction polynomial coefficient, scale factor 2^(-43) seconds/second */
    kal_int32   navaf0;  /* [-2097152..2097151], clock correction polynomial coefficient, scale factor 2^(-31) seconds */
    kal_int8    navTgd;  /* [-128..127], group delay, scale factor 2^(-31) seconds */
} gnss_nav_clock_model_struct;


typedef struct
{
    kal_uint16  cnavToc;           /* [0..2015], clock data reference time of week, scale factor 300 seconds */
    kal_uint16  cnavTop;           /* [0..2015], clock data predict time of week, scale factor 300 seconds */
    kal_int8    cnavURA0;          /* [-16..15], SV clock accuracy index */
    kal_uint8   cnavURA1;          /* [0..7], SV clock accuracy change index */
    kal_uint8   cnavURA2;          /* [0..7], SV clock accuracy change rate index */
    kal_int16   cnavAf2;           /* [-512..511], SV clock drift rate correction coefficient, scale factor 2^(-60) seconds/second^2 */
    kal_int32   cnavAf1;           /* [-524288..524287], SV clock drift correction coefficient, scale factor 2^(-48) seconds/second */
    kal_int32   cnavAf0;           /* [-33554432..33554431], SV clock bias correction coefficient, scale 2^(-35) seconds */
    kal_int16   cnavTgd;           /* [-4096..4095], group delay, scale factor 2^(-35) seconds */
    kal_bool    cnavISCl1cpValid;
    kal_int16   cnavISCl1cp;       /* [-4096..4095], inter signal group delay correction, scale factor 2^(-35) seconds */
    kal_bool    cnavISCl1cdValid;
    kal_int16   cnavISCl1cd;       /* [-4096..4095], inter signal group delay correction, scale factor 2^(-35) seconds */
    kal_bool    cnavISCl1caValid;
    kal_int16   cnavISCl1ca;       /* [-4096..4095], inter signal group delay correction, scale factor 2^(-35) seconds */
    kal_bool    cnavISCl2cValid;
    kal_int16   cnavISCl2c;        /* [-4096..4095], inter signal group delay correction, scale factor 2^(-35) seconds */
    kal_bool    cnavISCl5i5Valid;
    kal_int16   cnavISCl5i5;       /* [-4096..4095], inter signal group delay correction, scale factor 2^(-35) seconds */
    kal_bool    cnavISCl5q5Valid;
    kal_int16   cnavISCl5q5;       /* [-4096..4095], inter signal group delay correction, scale factor 2^(-35) seconds */
} gnss_cnav_clock_model_struct;


typedef struct
{
    kal_int32  gloTau;            /* [-2097152..2097151], satellite clock offset, scale factor 2^(-30) seconds */
    kal_int16  gloGamma;          /* [-1024..1023], relative frequency offset from nominal value, scale factor 2^(-40) */
    kal_bool   gloDeltaTauValid;
    kal_int8   gloDeltaTau;       /* [-16..15], time difference between transmission in G2 and G1, scale factor 2^(-30) seconds */
} gnss_glonass_clock_model_struct;


typedef struct
{
    kal_uint16  sbasTo;    /* [0..5399], scale factor 16 seconds */
    kal_int16   sbasAgfo;  /* [-2048..2047], scale factor 2^(-31) seconds */
    kal_int8    sbasAgf1;  /* [-128..127], scale factor 2^(-40) seconds/second */
} gnss_sbas_clock_model_struct;


typedef struct
{
    gnss_clock_model_type_enum            type;

    union
    {
        gnss_standard_clock_model_struct  standardClockModelList;  /* Model-1: usually used for Galileo */
        gnss_nav_clock_model_struct       navClockModel;           /* Model-2: for GPS */
        gnss_cnav_clock_model_struct      cnavClockModel;          /* Model-3: for modernized GPS */
        gnss_glonass_clock_model_struct   glonassClockModel;       /* Model-4: for GLONASS */
        gnss_sbas_clock_model_struct      sbasClockModel;          /* Model-5: for SBAS */
   } data;
} gnss_clock_model_struct;


typedef struct
{
    kal_uint16  keplerToe;         /* [0 .. 16383], time-of-ephemeris, scale factor 60 seconds */
    kal_int32   keplerW;           /* [-2147483648..2147483647], argument of perigee, scale factor 2^(-31) semi-circles */
    kal_int16   keplerDeltaN;      /* [-32768..32767], mean motion difference from computed value, scale factor 2^(-43) semi-circles/second */
    kal_int32   keplerM0;          /* [-2147483648..2147483647], mean anomaly at reference time, scale factor 2^(-31) semi-circles */
    kal_int32   keplerOmegaDot;    /* [-8388608.. 8388607], longitude of ascending node of orbit plane at weekly epoch, scale factor 2^(-43) semi-circles/second */
    kal_uint32  keplerE;           /* [0..4294967295], eccentricity, scale factor 2^(-33) */
    kal_int16   keplerIDot;        /* [-8192..8191], rate of inclination angle, scale factor 2^(-43) semi-circles/second */
    kal_uint32  keplerAPowerHalf;  /* [0.. 4294967295], semi-major Axis, scale factor 2^(-19) meters^(0.5)*/
    kal_int32   keplerI0;          /* [-2147483648..2147483647], inclination angle at reference time, scale factor 2^(-31) semi-circles */
    kal_int32   keplerOmega0;      /* [-2147483648..2147483647], longitude of ascending node of orbit plane at weekly epoch, scale factor 2^(-31) semi-circles */
    kal_int16   keplerCrs;         /* [-32768..32767], amplitude of the sine harmonic correction term to the orbit radius, scale factor 2^(-5) meters */
    kal_int16   keplerCis;         /* [-32768..32767], amplitude of the sine harmonic correction term to the angle of inclination, scale factor 2^(-29) radians */
    kal_int16   keplerCus;         /* [-32768..32767], amplitude of the sine harmonic correction term to the argument of latitude, scale factor 2^(-29) radians */
    kal_int16   keplerCrc;         /* [-32768..32767], amplitude of the cosine harmonic correction term to the orbit radius, scale factor 2^(-5) meters */
    kal_int16   keplerCic;         /* [-32768..32767], amplitude of the cosine harmonic correction term to the angle of inclination, scale factor 2^(-29) radians */
    kal_int16   keplerCuc;         /* [-32768..32767], amplitude of the cosine harmonic correction term to the argument of latitude, scale factor 2^(-29) radians */
} gnss_nav_model_keplerian_set_struct;


typedef struct
{
    kal_uint32  reserved1;  /* [0..8388607], 23 bit field */
    kal_uint32  reserved2;  /* [0..16777215], 24 bit field */
    kal_uint32  reserved3;  /* [0..16777215], 24 bit field */
    kal_uint16  reserved4;  /* [0..65535], 16 bit field */
} gnss_nav_model_nav_keplerian_set_struct_add_nav_param_ephemSF1Rsvd_struct;


typedef struct
{
    kal_uint8  ephemCodeOnL2; /* [0..3] */
    kal_uint8  ephemL2Pflag;  /* [0..1] */
    gnss_nav_model_nav_keplerian_set_struct_add_nav_param_ephemSF1Rsvd_struct ephemSF1Rsvd;
    kal_uint8  ephemAODA;     /* [0..31] */
} gnss_nav_model_nav_keplerian_set_struct_add_nav_param_struct;


typedef struct
{
    kal_uint8   navURA;         /* [0..15], SV accuracy */
    kal_uint8   navFitFlag;     /* [0..1], fit interval indication */
    kal_uint16  navToe;         /* [0..37799], time of ephemeris, scale factor 2^4 seconds */
    kal_int32   navOmega;       /* [-2147483648..2147483647], argument of perigee, scale factor 2^(-31) semi-circles */
    kal_int16   navDeltaN;      /* [-32768..32767], mean motion difference from computed value, scale factor 2^(-43) semi-circles/second */
    kal_int32   navM0;          /* [-2147483648..2147483647], mean anonmaly at reference time, scale factor 2^(-31) semi-circles */
    kal_int32   navOmegaADot;   /* [-8388608..8388607], rate of right ascension, scale factor 2^(-43) semi-circles/second */
    kal_uint32  navE;           /* [0..4294967295], eccentricity, scale factor 2^(-33) */
    kal_int16   navIDot;        /* [-8192..8191], rate of inclination angle, scale factor 2^(-43) semi-circles/second */
    kal_uint32  navAPowerHalf;  /* [0..4294967295], square root of semi-major axis, scale factor 2^(-19) meters^(0.5) */
    kal_int32   navI0;          /* [-2147483648..2147483647], inclination angle at reference time, scale factor 2^(-31) semi-circles */
    kal_int32   navOmegaA0;     /* [-2147483648..2147483647], longitude of ascending node of orbit plane at weekly epoch, scale factor 2^(-31) semi-circles*/
    kal_int16   navCrs;         /* [-32768..32767], amplitude of sine harmonic correction term to the orbit radius, scale factor 2^(-5) meters */
    kal_int16   navCis;         /* [-32768..32767], amplitude of the sine harmonic correction term to the angle of inclination, scale factor 2^(-29) radians */
    kal_int16   navCus;         /* [-32768..32767], amplitude of the sine harmonic correction term to the argument of latitude, scale factor 2^(-29) radians */
    kal_int16   navCrc;         /* [-32768..32767], amplitude of the cosine harmonic correction term to the orbit radius, scale factor 2^(-5) meters */
    kal_int16   navCic;         /* [-32768..32767], amplitude of the cosine harmonic correction term to the angle of inclination, scale factor 2^(-29) radians */
    kal_int16   navCuc;         /* [-32768..32767], amplitude of the cosine harmonic correction term to the argument of latitude, scale factor 2^(-29) radians */
    /* optional field */
    kal_bool    addNavParamValid;
    gnss_nav_model_nav_keplerian_set_struct_add_nav_param_struct addNAVparam; /* data and reserved bits in GPS NAV message */
} gnss_nav_model_nav_keplerian_set_struct;


typedef struct
{
    kal_uint16  cnavTop;            /* [0..2015], data predict time of week, scale factor 300 seconds */
    kal_int8    cnavURAindex;       /* [-16..15], SV accuracy */
    kal_int32   cnavDeltaA;         /* [-33554432..33554431], semi-major axis difference at reference time, scale factor 2^(-9) meters */
    kal_int32   cnavAdot;           /* [-16777216..16777215], change rate in semi-major axis, scale factor 2^(-21) meters/sec */
    kal_int32   cnavDeltaNo;        /* [-65536..65535], mean motion difference from computed value at reference time, scale factor 2^(-44) semi-circles/second */
    kal_int32   cnavDeltaNoDot;     /* [-4194304..419430], rate of mean motion difference from computed value, scale factor 2^(-57) semi-circles/seconds */
    kal_int64   cnavMo;             /* [-4294967296..4294967295], mean anomaly at reference time, scale factor 2^(-32) semi-circles */
    kal_uint64  cnavE;              /* [0..8589934591], eccentricity, scale factor 2^(-34) */
    kal_int64   cnavOmega;          /* [-4294967296..4294967295], argument of perigee, scale factor 2^(-32) semi-circles */
    kal_int64   cnavOMEGA0;         /* [-4294967296..4294967295], reference right ascension angle, scale factor 2^(-32) semi-circles */
    kal_int32   cnavDeltaOmegaDot;  /* [-65536..65535], rate of right ascension difference, scale factor 2^(-44) semi-circles/second */
    kal_int64   cnavIo;             /* [-4294967296..4294967295], inclination angle at reference time, scale factor 2^(-32) semi-circles */
    kal_int16   cnavIoDot;          /* [-16384..16383], rate of inclination angle, scale factor 2^(-44) semi-circles/second */
    kal_int16   cnavCis;            /* [-32768..32767], amplitude of the sine harmonic correction term to the angle of inclination, scale factor 2^(-30) radians */
    kal_int16   cnavCic;            /* [-32768..32767], amplitude of the cosine harmonic correction term to the angle of inclination, scale factor 2^(-30) radians  */
    kal_int32   cnavCrs;            /* [-8388608..8388607], amplitude of sine harmonic correction term to the orbit radius, scale factor 2^(-8) meters */
    kal_int32   cnavCrc;            /* [-8388608..8388607], amplitude of the cosine harmonic correction term to the orbit radius, scale factor 2^(-8) meters */
    kal_int32   cnavCus;            /* [-1048576..1048575], amplitude of the sine harmonic correction term to the argument of latitude, scale factor 2^(-30) radians */
    kal_int32   cnavCuc;            /* [-1048576..1048575], amplitude of the cosine harmonic correction term to the argument of latitude, scale factor 2^(-30) radians */
} gnss_nav_model_cnav_keplerian_set_struct;


typedef struct
{
    kal_uint8  gloEn;       /* [0..31] */
    kal_uint8  gloP1;       /* 2 bit field, time interval between two adjacent values of tb */
    kal_bool   gloP2;       /* change of tb flag */
    kal_uint8  gloM;        /* [0..3], type of satellite */
    kal_int32  gloX;        /* [-67108864..67108863], x-coordinate of satellite at time tb, scale factor 2^(-11) kilometers */
    kal_int32  gloXdot;     /* [-8388608..8388607], x-coordinate of satellite velocity at time tb, scale factor 2^(-20) kilometers/second */
    kal_int8   gloXdotdot;  /* [-16..15], x-coordinate of satellite acceleration at time tb, scale factor 2^(-30) kilometers/second^2 */
    kal_int32  gloY;        /* [-67108864..67108863], y-coordinate of satellite at time tb, scale factor 2^(-11) kilometers */
    kal_int32  gloYdot;     /* [-8388608..8388607], y-coordinate of satellite velocity at time tb, scale factor 2^(-20) kilometers/second */
    kal_int8   gloYdotdot;  /* [-16..15], y-coordinate of satellite acceleration at time tb, scale factor 2^(-30) kilometers/second^2 */
    kal_int32  gloZ;        /* [-67108864..67108863], z-coordinate of satellite at time tb, scale factor 2^(-11) kilometers */
    kal_int32  gloZdot;     /* [-8388608..8388607)], z-coordinate of satellite velocity at time tb, scale factor 2^(-20) kilometers/second */
    kal_int8   gloZdotdot;  /* [-16..15], z-coordinate of satellite acceleration at time tb, scale factor 2^(-30) kilometers/second^2 */
} gnss_nav_model_glonass_ecef_struct;


typedef struct
{
    kal_bool    sbasToValid;
    kal_uint16  sbasTo;        /* [0..5399], time applicability, scale factor 16 seconds */
    kal_uint8   sbasAccuracy;  /* 4 bits field, accuracy */
    kal_int32   sbasXg;        /* [-536870912..536870911], scale factor 0.08 meters */
    kal_int32   sbasYg;        /* [-536870912..536870911], scale factor 0.08 meters */
    kal_int32   sbasZg;        /* [-16777216..16777215], 0.4 meters */
    kal_int32   sbasXgDot;     /* [-65536..65535], rate of change, scale factor 0.000625 meters/second */
    kal_int32   sbasYgDot;     /* [-65536..65535], rate of change, scale factor 0.000625 meters/second */
    kal_int32   sbasZgDot;     /* [-131072..131071], rate of change, scale factor 0.004 meters/second */
    kal_int16   sbasXgDotDot;  /* [-512..511], acceleration, scale factor 0.0000125 meters/second^2 */
    kal_int16   sbagYgDotDot;  /* [-512..511], acceleration, scale factor 0.0000125 meters/second^2 */
    kal_int16   sbasZgDotDot;  /* [-512..511], acceleration, scale factor 0.0000625 meters/second^2 */
} gnss_nav_model_sbas_ecef_struct;


typedef struct
{
    gnss_orbit_model_type_enum                  type;

    union
    {
      gnss_nav_model_keplerian_set_struct       keplerianSet;      /* Model-1: usually used for Galileo */
      gnss_nav_model_nav_keplerian_set_struct   navKeplerianSet;   /* Model-2: for GPS series */
      gnss_nav_model_cnav_keplerian_set_struct  cnavKeplerianSet;  /* Model-3: for modernized GPS series */
      gnss_nav_model_glonass_ecef_struct        glonassECEF;       /* Model-4: for GLONASS */
      gnss_nav_model_sbas_ecef_struct           sbasECEF;          /* Model-5: for SBAS */
    } data;
} gnss_orbit_model_struct;


typedef struct
{
   kal_uint8                svID;      /* [0..63] */
   kal_uint8                svHealth;  /* 8 bits */
   kal_uint16               iod;       /* 11 bits */
   gnss_clock_model_struct  clockModel;
   gnss_orbit_model_struct  orbitModel;
} gnss_nav_model_satellite_element;


typedef struct
{
   kal_bool                          nonBroadcastIndFlag; /* [0..1] value 0: navigation model data correspond to satellite broadcasted data;
                                                                    value 1: navigation model data is not derived from satellite broadcasted data */
   kal_uint8                         numSatElement;
   gnss_nav_model_satellite_element  satElement[GNSS_MAX_NAV_SAT_ELEMENT];
} gnss_navigation_model_struct;
/* end for gnss navigation model */


/* start for gnss real time integrity */
typedef struct
{
   kal_uint8  badSVID;  /* [0..63] */
   kal_bool   badSignalIDValid;
   kal_uint8  badSignalID;  /* identidy the bad signal or signals of a satellite, bit string representation, map to GNSS_SGN_ID_BITMAP_* */
} gnss_bad_signal_element_struct;


typedef struct
{
    kal_uint8                       numBadSignalElement;
    gnss_bad_signal_element_struct  badSignalElement[GNSS_MAX_RTI_BAD_SAT_ELEMENT];
} gnss_real_time_integrity_struct;
/* end for gnss real time integrity */


/* start for gnss data bit assistance */
typedef struct
{
   kal_uint8   gnssSignalType;                           /* identify GNSS signal type, map to GNSS_SGN_ID_VALUE_* */
   kal_uint8   numGnssDataBits;
   kal_uint8   gnssDataBits[GNSS_MAX_DBA_BIT_LENGTH/8];  /* data bit original max is 1024 bits */
} gnss_data_bit_signal_element_struct;


typedef struct
{
    kal_uint8                            svID;  /* [0..63] */
    kal_uint8                            numGnssDataBitsSgnElement;
    gnss_data_bit_signal_element_struct  gnssDataBitsSgnElement[GNSS_MAX_DBA_SGN_TYPE_ELEMENT];
} gnss_data_bit_satellite_element_struct;


typedef struct
{
    kal_uint16                              gnssTOD;     /* [0..3599], reference time of the first bit of the data modulo 1 hour, scale factor 1 second */
    kal_bool                                gnssTODfracValid;
    kal_uint16                              gnssTODfrac; /* [0..999], fractional part of gnssTD, scale factor 1 milli-second */
    kal_uint8                               numGnssDataBitsSatElement;
    gnss_data_bit_satellite_element_struct  gnssDataBitsSatElement[GNSS_MAX_DBA_SAT_ELEMENT];
} gnss_data_bit_assistance_struct;
/* end for gnss data bit assistance */


/* start for gnss acquisition assistance */
typedef struct
{
    kal_uint8   svID;                   /* [0..63] */
    kal_int16   doppler0;               /* [-2048..2047], Doppler (0th order term) value for velocity, scale factor 0.5 m/s in th range from -1024 m/s to +1023.5 m/s */
    kal_uint8   doppler1;               /* [0..63], Doppler (1th order term) value for acceleration, scale factor 1/210 m/s^2 in the range from -0.2 m/s^2 to +0.1 m/s^2 */
    kal_uint8   dopplerUncertainty;     /* [0..4], defined values: 2.5 m/s, 5 m/s, 10 m/s, 20 m/s, 40 m/s encoded as integer range 0-4 by 2^(-n)*40 m/s, n=0-4 */
    kal_uint16  codePhase;              /* [0..1022], scale factor 2^(-10) ms in the range from 0 to (1-2^(-10)) ms */
    kal_uint8   intCodePhase;           /* [0..127], integer codephase, scale factor 1ms */
    kal_uint8   codePhaseSearchWindow;  /* [0..31], map to value-to-searchwindow table (ms) */
    kal_uint16  azimuth;                /* [0..511], azimuth angle a, x-degrees of satellite x<=a<x+0.703125, scale factor 0.703125 degrees */
    kal_uint8   elevation;              /* [0..127], elevation angle e, y-degrees of satellite y>=e<y+0.703125, scale factr 0.703125 degrees */
    /* optional field */
    kal_bool    codePhase1023Valid;
    kal_bool    codePhase1023;          /* only use if codePhase is 1022, codePhase value is 1023*2^(-10) = (1-2^(-10)) ms */
    /* if support dopplerUncertaintyExtR10, should ignore dopplerUncertainty field */
    kal_bool                                     dopplerUncertaintyExtR10Valid;
    gnss_acq_assist_doppler_uncertainty_ext_enum dopplerUncertaintyExtR10; /* enumerated value map to 60 m/s, 80 m/s, 100 m/s, 120 ms, and No Information */
} gnss_acquisition_assist_element_struct;


/**
 * please note that RRC/RRLP use alternative word to represent GNSS Acquisition Assistance:
 * RRC: GANSS-ReferenceMeasurementInfo
 * RRLP: ganssRefMeasurementAssist
 */
typedef struct
{
    kal_uint8                               gnssSignalID;  /* GNSS type, map to GNSS_SGN_ID_VALUE_* */
    kal_uint8                               numGnssAcqAssistElement;
    gnss_acquisition_assist_element_struct  gnssAcqAssistElement[GNSS_MAX_ACQ_ASSIST_SAT_ELEMENT];
    kal_bool                                confidenceR10Valid;
    kal_uint8                               confidenceR10;  /* only for LPP */
} gnss_acquisition_assistance_struct;
/* end for gnss acquisition assistance */


/* start for gnss almanac */
typedef struct
{
    kal_uint8   svID;                  /* [0..63] */
    kal_uint16  kepAlmanacE;           /* [0..2047], eccentricity, scale factor 2^(-16) */
    kal_int16   kepAlmanacDeltaI;      /* [-1024..1023], scale factor 2^(-14) semi-circles */
    kal_int16   kepAlmanacOmegaDot;    /* [-1024..1023], longitude of ascending node of orbit plane at weekly epoch, scale factor 2^(-33) semi-circles/seconds */
    kal_uint8   kepSVHealth;           /* [0..15], SV health */
    kal_int32   kepAlmanacAPowerHalf;  /* [-65536..65535], semi-major axis delta, scale factor 2^(-9) meters^0.5 */
    kal_int16   kepAlmanacOmega0;      /* [-32768..32767], longitude of ascending node of orbit plane at weekly epoch, scale factor 2^(-15) semi-circles */
    kal_int16   kepAlmanacW;           /* [-32768..32767], argument of perigee, scale factor 2^(-15) semi-circles */
    kal_int16   kepAlmanacM0;          /* [-32768..32767], mean anomaly at reference time, scale factor 2^(-15) semi-circles */
    kal_int16   kepAlmanacAF0;         /* [-8192..8191], scale factor 2^(-19) seconds */
    kal_int16   kepAlmanacAF1;         /* [-1024..1023], scale factor 2^(-38) seconds */
} gnss_almanac_keplerian_set_struct;


typedef struct
{
    kal_uint8   svID;            /* [0..63] */
    kal_uint16  navAlmE;         /* [0..65535], eccentricity, scale factor 2^(-21) */
    kal_int16   navAlmDeltaI;    /* [-32768..32767], correction to inclination, scale factor 2^(-19) semi-circles */
    kal_int16   navAlmOMEGADOT;  /* [-32768..32767], rate of right ascension, scale factor 2^(-38) semi-circles/second */
    kal_uint8   navAlmSVHealth;  /* [0..255] */
    kal_uint32  navAlmSqrtA;     /* [0..16777215], square root of the semi-major axis, scale factor 2^(-11) meters^0.5 */
    kal_int32   navAlmOMEGAo;    /* [-8388608..8388607], longitude of ascending node of orbit plane at weekly epoch, scale factor 2^(-23) semi-circles */
    kal_int32   navAlmOmega;     /* [-8388608..8388607], argument of perigee, , scale factor 2^(-23) semi-circles */
    kal_int32   navAlmMo;        /* [-8388608..8388607], mean anomaly at reference time, scale factor 2^(-23) semi-circles */
    kal_int16   navAlmaf0;       /* [-1024..1023], apparent satellite clock correction, scale factor 2^(-20) seconds */
    kal_int16   navAlmaf1;       /* [-1024..1023], apparent satellite clock correction, scale factor 2^(-38) semi-circles seconds/second */
} gnss_almanac_nav_keplerian_set_struct;


typedef struct
{
    kal_uint8  svID;            /* [0..63] */
    kal_int8   redAlmDeltaA;    /* [-128..127], scale factor 2^9 meters */
    kal_int8   redAlmOmega0;    /* [-64..63], scale factor 2^(-6) semi-circles */
    kal_int8   redAlmPhi0;      /* [-64..63], scale factor 2^(-6) semi-circles */
    kal_bool   redAlmL1Health;  /* L1 health */
    kal_bool   redAlmL2Health;  /* L2 health */
    kal_bool   redAlmL5Health;  /* L5 health */
} gnss_almanac_reduced_keplerian_set_struct;


typedef struct
{
    kal_uint8   svID;             /* [0..63] */
    kal_uint16  midiAlmE;         /* [0..2047], eccentricity, scale factor 2^(-16) */
    kal_int16   midiAlmDeltaI;    /* [-1024..1023], scale factor 2^(-14) semi-circles */
    kal_int16   midiAlmOmegaDot;  /* [-1024..1023], scale factor 2^(-33) semi-circles/second */
    kal_uint32  midiAlmSqrtA;     /* [0..131071], scale factor 2^(-4) meters^0.5 */
    kal_int16   midiAlmOmega0;    /* [-32768..32767], scale factor 2^(-15) semi-circles */
    kal_int16   midiAlmOmega;     /* [-32768..32767], scale factor 2^(-15) semi-circles */
    kal_int16   midiAlmMo;        /* [-32768..32767], scale factor 2^(-15) semi-circles */
    kal_int16   midiAlmaf0;       /* [-1024..1023], scale factor 2^(-20) seconds */
    kal_int16   midiAlmaf1;       /* [-512..511], scale factor 2^(-37) seconds/second */
    kal_bool    midiAlmL1Health;  /* L1 health */
    kal_bool    midiAlmL2Health;  /* L2 health */
    kal_bool    midiAlmL5Health;  /* L5 health */
} gnss_almanac_midi_keplerian_set_struct;


typedef struct
{
    kal_uint16  gloAlmNA;         /* [1..1461], N^A, scale factor 1 days */
    kal_uint8   gloAlmnA;         /* [1..24] */
    kal_uint8   gloAlmHA;         /* [0..31] */
    kal_int32   gloAlmLambdaA;    /* [-1048576..1048575], scale factor 2^(-20) semi-circles */
    kal_uint32  gloAlmtlambdaA;   /* [0..2097151], scale factor 2(^-5) seconds */
    kal_int32   gloAlmDeltaIa;    /* [-131072..131071], scale factor 2^(-20) semi-circles */
    kal_int32   gloAlmDeltaTA;    /* [-2097152..2097151], scale factor 2^(-9) seconds/orbit period */
    kal_int8    gloAlmDeltaTdotA; /* [-64..63], scale factor 2^(-14) seconds/orbit period */
    kal_uint16  gloAlmEpsilonA;   /* [0..32767], scale factor 2^(-20) */
    kal_int16   gloAlmOmegaA;     /* [-32768..32767], scale factor 2^(-15) semi-circles */
    kal_int16   gloAlmTauA;       /* [-512..511], scale factor 2^(-18) seconds */
    kal_uint8   gloAlmCA;         /* [0..1] */
    kal_bool    gloAlmMAValid;
    kal_uint8   gloAlmMA;         /* 2 bit field */
} gnss_almanac_glonass_set_struct;


typedef struct
{
    kal_uint8   sbasAlmDataID;  /* [0..3] */
    kal_uint8   svID;           /* [0..63] */
    kal_uint8   sbasAlmHealth;  /* 8 bit field */
    kal_int16   sbasAlmXg;      /* [-16384..16383], scale factor 2600 meters */
    kal_int16   sbasAlmYg;      /* [-16384..16383], scale factor 2600 meters */
    kal_int16   sbasAlmZg;      /* [-256..255], scale factor 26000 meters */
    kal_int8    sbasAlmXgdot;   /* [-4..3], rate of change, scale factor 10 meters/second */
    kal_int8    sbasAlmYgDot;   /* [-4..3], rate of change, scale factor 10 meters/second */
    kal_int8    sbasAlmZgDot;   /* [-8..7], rate of change, scale factor 40.96 meters/second */
    kal_uint16  sbasAlmTo;      /* [0..2047], scale factor 64 meters/seconds */
} gnss_almanac_ecef_sbas_set_struct;


typedef struct
{
    gnss_almanac_type_enum  type;

    union
    {
        gnss_almanac_keplerian_set_struct          keplerianSet;        /* for Galileo */
        gnss_almanac_nav_keplerian_set_struct      navKeplerianSet;     /* for GPS, QZSS */
        gnss_almanac_reduced_keplerian_set_struct  reducedKeplerianSet; /* for GPS, Modernized GPS, QZSS */
        gnss_almanac_midi_keplerian_set_struct     midiKeplerianSet;    /* for GPS, Modernized GPS, QZSS */
        gnss_almanac_glonass_set_struct            glonassSet;          /* for GLONASS */
        gnss_almanac_ecef_sbas_set_struct          ecefSbasSet;         /* for SBAS */
    } data;
} gnss_almanac_element_struct;


typedef struct
{
    kal_bool                     weekNumberValid;
    kal_uint8                    weekNumber;  /* [0..255], almanac reference week number for non-GLONASS system, modulo 256 weeks */
    kal_bool                     toaValid;
    kal_uint8                    toa;         /* [0.255], almanac reference time for non-GLONASS system, scale factor 2^12 seconds */
    kal_bool                     iodaValid;
    kal_uint8                    ioda;        /* [0..3], issue of data, for Galileo system */
    kal_bool                     completeAlmanacProvided;  /* if almanac list contains complete GNSS constellation */
    kal_uint8                    numGnssAlmanacElement;
    gnss_almanac_element_struct  gnssAlmanacElement[GNSS_MAX_ALMANAC_SAT_ELEMENT];
} gnss_almanac_struct;
/* end for gnss almanac */


/* start for gnss utc model */
typedef struct
{
    kal_int32  gnssUtcA1;         /* [-8388608..8388607], scale factor 2^(-50) seconds/second */
    kal_int32  gnssUtcA0;         /* [-2147483648..2147483647], scale factor 2^(-30) seconds */
    kal_uint8  gnssUtcTot;        /* [0..255], scale factor 2^12 seconds */
    kal_uint8  gnssUtcWNt;        /* [0..255], scale factor 1 week */
    kal_int8   gnssUtcDeltaTls;   /* [-128..127], scale factor 1 second */
    kal_uint8  gnssUtcWNlsf;      /* [0..255], scale factor 1 week */
    kal_int8   gnssUtcDN;         /* [-128..127], scale factor 1 day */
    kal_int8   gnssUtcDeltaTlsf;  /* [-128..127], scale factor 1 second */
} gnss_utc_model_set1_struct;


typedef struct
{
    kal_int16   utcA0;         /* [-32768..32767], bias coefficient of GNSS time scale relative to UTC time scale, scale factor 2^(-35) seconds */
    kal_int16   utcA1;         /* [-4096..4095], drift coefficient of GNSS time scale relative to UTC time scale, scale factor 2^(-51) seconds/second */
    kal_int8    utcA2;         /* [-64..63], drift rate correction coefficient of GNSS time sacel relative to UTC time scale, scale factor 2^(-68) seconds/second^2 */
    kal_int8    utcDeltaTls;   /* [-128..127], current or past leap second count, scale factor 1 second */
    kal_uint16  utcTot;        /* [0..65535], time data reference time of week, scale factor 2^4 seconds */
    kal_uint16  utcWNot;       /* [0..8191], time data reference week number, scale factor 1 week */
    kal_uint8   utcWNlsf;      /* [0..255], leap second reference week number, scale factor 1 week */
    kal_uint8   utcDN;         /* 4 bits field, leap second reference day number, scale factor 1 day */
    kal_int8    utcDeltaTlsf;  /* [-128..127], current or future leap second count, scale factor 1 second */
} gnss_utc_model_set2_struct;


typedef struct
{
    kal_uint16  nA;    /* [1..1461], callendar day number within four-year period beginning since the leap year, scale factor 1 day */
    kal_int32   tauC;  /* [-2147483648..2147483647], GLONASS time scale correction to UTC(SU), scale factor 2^(-31) seconds */
    /* optional field, mandatory present if GLONASS-M satellites are presnet in the current GLONASS constellation */
    kal_bool    b1Valid;
    kal_int16   b1;    /* [-1024..1023], coefficient to determine delta UT1, scale factor 2^(-10) seconds */
    kal_bool    b2Valid;
    kal_int16   b2;    /* [-512..511], coefficient to determind delta UT1, scale factor 2^(-16) seconds/msd */
    kal_bool    kpValid;
    kal_uint8   kp;    /* 2 bits field, notification of expected leap second correction */
} gnss_utc_model_set3_struct;


typedef struct
{
    kal_int32  utcA1wnt;       /* [-8388608..8388607], scale factor 2^(-50) seconds/second */
    kal_int32  utcA0wnt;       /* [-2147483648..2147483647], scale factor 2^(-30) seconds */
    kal_uint8  utcTot;         /* [0..255], scale factor 2^12 seconds */
    kal_uint8  utcWNt;         /* [0..255], scale factor 1 week */
    kal_int8   utcDeltaTls;    /* [-128..127], scale factor 1 second */
    kal_uint8  utcWNlsf;       /* [0..255], scale factor 1 week */
    kal_int8   utcDN;          /* [-128..127], scale factor 1 day */
    kal_int8   utcDeltaTlsf;   /* [-128..127], scale factor 1 second */
    kal_uint8  utcStandardID;  /* [0..7], if GNSS-ID indicates SBAS, this field indicated the UTC stadard used for the SBAS network time indicated by SBAS-ID to UTC relation */
} gnss_utc_model_set4_struct;


typedef struct
{
    gnss_utc_model_type_enum  type;
 
    union
    {
       gnss_utc_model_set1_struct  utcModel1;  /* for GPS, Galileo, QZSS */
       gnss_utc_model_set2_struct  utcModel2;  /* for GPS, Galileo, QZSS */
       gnss_utc_model_set3_struct  utcModel3;  /* for GLONASS */
       gnss_utc_model_set4_struct  utcModel4;  /* for SBAS */
    } data;
} gnss_utc_model_struct;
/* end for gnss utc model */


/* start for gnss aux info */
typedef struct
{
    kal_uint8  svID;              /* [0..63] */
    kal_uint8  signalsAvailable;  /* 8 bits field, indicate the ranging signals supported by the satellite indicated by svID, map to GNSS_SGN_ID_BITMAP_* */
} gnss_aux_gps_sat_element_struct;


typedef struct
{
    kal_uint8                        numGpsElement;
    gnss_aux_gps_sat_element_struct  gpsElement[GNSS_MAX_AUX_SAT_ELEMENT];
} gnss_aux_info_gps_struct;


typedef struct
{
    kal_uint8  svID;              /* [0..63] */
    kal_uint8  signalsAvailable;  /* 8 bits field, indicate the ranging signals supported by the satellite indicated by svID */
    /* optional field */
    kal_bool   channelNumberValid;
    kal_int8   channelNumber;     /* [-7..13] indicate the GLONASS carrier frequency number of the satellite identified by svID */
} gnss_aux_glonass_sat_element_struct;


typedef struct
{
    kal_uint8                            numGlonassElement;
    gnss_aux_glonass_sat_element_struct  glonassElement[GNSS_MAX_AUX_SAT_ELEMENT];
} gnss_aux_info_glonass_struct;


typedef struct
{
    gnss_aux_info_gnss_type_enum type;
 
    union
    {
       gnss_aux_info_gps_struct      gps;
       gnss_aux_info_glonass_struct  glonass;
    } data;
} gnss_aux_info_struct;
/* end for gnss aux info */


/* LCSP -> GNSS Task */
/* This structure for MSG_ID_LCSP_GNSS_OPEN_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    //kal_uint8  gnssIdBitmap;  /* GNSS_ID_BITMAP_* */
    //kal_uint8  preferGnssMode; /* TBD: should not used this kind of design in GNSS */
} lcsp_gnss_open_req_struct;


/* This structure for MSG_ID_LCSP_GNSS_CLOSE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    //kal_uint8  gnssIdBitmap; /* GNSS_ID_BITMAP_* */    
} lcsp_gnss_close_req_struct;


/* This structure for MSG_ID_LCSP_GNSS_COMMON_ASSIST_DATA_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                           transactionID;

    gnss_common_assist_data_type_enum    type;
    union
    {
        gnss_reference_time_struct       refTime;
        gnss_reference_location_struct   refLoc;
        gnss_ionospheric_model_struct    ionModel;
        gnss_earth_orient_params_struct  eop;
    } data;
} lcsp_gnss_common_assist_data_req_struct;


/**
 * in LPP, location server could provide up to 16 GNSSs generic assist data
 * in RRC/RRLP, location server could provide up to 8 GANSSs generic assist data
 */
/* This structure for MSG_ID_LCSP_GNSS_GENERIC_ASSIST_DATA_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                               transactionID;

    gnss_id_enum                             gnssId;
    kal_bool                                 sbasIdValid;  /* only present when gnss is sbas */
    sbas_id_enum                             sbasId;

    gnss_generic_assist_data_type_enum       type;
    union
    {
        gnss_time_model_list_struct          timeModel;
        gnss_diff_correction_struct          dgnss;
        gnss_navigation_model_struct         navModel;
        gnss_real_time_integrity_struct      rti;
        gnss_data_bit_assistance_struct      dataBitAssist;
        gnss_acquisition_assistance_struct   acqAssist;
        gnss_almanac_struct                  almanac;
        gnss_utc_model_struct                utcModel;
        gnss_aux_info_struct                 auxInfo;
    } data;
} lcsp_gnss_generic_assist_data_req_struct;


typedef struct
{
   /* note: for MA, use horizontalAccuracy to represent pseudorange error */
   kal_bool   horizontalAccuracyValid;
   kal_uint8  horizontalAccuracy;            /* range: 0-127, refer TS 23.032, K1 decoding formula */
   kal_uint8  horizontalAccuracyConfidence;  /* range: 0-100, refer TS 23.032, direct map to percentage, zero indicate "no inforamation" */
   kal_bool   verticalAccuracyValid;
   kal_uint8  verticalAccuracy;              /* range: 0-127, refer TS 23.032, K3 decoding formula */
   kal_uint8  verticalAccuracyConfidence;    /* range: 0-100, refer TS 23.032, direct map to percentage, zero indicate "no inforamation" */
   kal_uint8  responseTime;                  /* range: 1-128 seconds */
} gnss_loc_req_qos_struct;


/* This structure for MSG_ID_LCSP_GNSS_POS_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16               transactionID;

    lcs_sim_source_enum      simSource;
    kal_uint16               gnssMethod;                 /* network allowed GNSS type, may be multiple GNSS, map to GNSS_ID_BITMAP_* */
    kal_bool                 fineTimeAssistanceMeasReq;  /* network requested fine time measurement */
                                                         /**
                                                          * note: we assume that when network requests UE to do fine time measurement,
                                                          *       network will always give UE corresponding refercence cell information in Reference Time Assistance Data,
                                                          *       then GNSS task should use this reference cell information within Reference Time Assistance Data to ask current RAT's L1 module to do fine time measurement,
                                                          *       otherwise the measurement would fail.
                                                          */
    kal_bool                 assistanceAvailability;     /* network allow UE request additional GNSS assistance data */
    gnss_loc_req_qos_struct  qos;
    kal_bool                 autoResetTrigger;
} lcsp_gnss_pos_req_struct;


/* This structure for MSG_ID_LCSP_GNSS_MEAS_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16               transactionID;

    lcs_sim_source_enum      simSource;
    kal_uint16               gnssMethod;                 /* network allowed GNSS type, may be multiple GNSS, map to GNSS_ID_BITMAP_* */
    kal_bool                 fineTimeAssistanceMeasReq;  /* network requested fine time measurement */
                                                         /**
                                                          * note: we assume that when network requests UE to do fine time measurement,
                                                          *       network will always give UE corresponding refercence cell information in Reference Time Assistance Data,
                                                          *       then GNSS task should use this reference cell information within Reference Time Assistance Data to ask current RAT's L1 module to do fine time measurement,
                                                          *       otherwise the measurement would fail.
                                                          */
    kal_bool                 adrMeasReq;                 /* network requested ADR(accumulated Doppler range) measurement */
    kal_bool                 multiFreqMeasReq;           /* network requested to report multiple supported GNSS type */
    kal_bool                 assistanceAvailability;     /* network allow UE request additional GNSS assistance data */
    gnss_loc_req_qos_struct  qos;
    kal_bool                 autoResetTrigger;
} lcsp_gnss_meas_req_struct;


/* This structure for MSG_ID_LCSP_GNSS_ABORT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16  transactionID;
} lcsp_gnss_abort_req_struct;


/* This structure for MSG_ID_LCSP_GNSS_RESET_UE_STORED_POS_INFO */
typedef struct
{
    LOCAL_PARA_HDR
    /* empty */
} lcsp_gnss_reset_ue_stored_pos_info_struct;


/* GNSS Task -> LCSP */
/* This structure for MSG_ID_LCSP_GNSS_COMMON_ASSIST_DATA_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                               transactionID;
    gnss_common_assist_data_type_enum        type;
    kal_bool                                 resultOk;
} lcsp_gnss_common_assist_data_cnf_struct;


/* This structure for MSG_ID_LCSP_GNSS_GENERIC_ASSIST_DATA_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                               transactionID;

    gnss_id_enum                             gnssId;
    kal_bool                                 sbasIdValid;  /* only present when gnss is sbas */
    sbas_id_enum                             sbasId;
    gnss_generic_assist_data_type_enum       type;
    kal_bool                                 resultOk;
} lcsp_gnss_generic_assist_data_cnf_struct;


/* No more additional assistance data req primitive, embeded assistance data request in GNSS_POS/MEAS_CNF */
/**
 * For common assistance data,
 * to simplify complexity, LPP would align RRC/RRLP ASN.1 design, request all supported data fields of the assistance data type request
 *  e.g. If network request GPS+GLONASS positioning estimate, LPP will request all supported fields in the GNSS-ReferenceTimeReq if GNSS task response reference time missing
 *       (1) gnssTimeReqPrefList = GPS-ID + GLONASS-ID
 *       (2) gpsTOWAssistReq = true
 *       (3) notOfLeapSecReq = true
 *
 *       If network request GPS only positioning estimate, LPP will request all supported fields in the GNSS-ReferenceTimeReq if GNSS task response reference time missing
 *       (1) gnssTimeReqPrefList = GPS-ID
 *       (2) gpsTOWAssistReq = true
 *       (3) notOfLeapSecReq = false
 *
 *  the same design policy also applies on RRC/RRLP original(extend) GANSS-AdditionalAssistanceDataRequest/GANSSAssistanceData
 */

typedef struct
{
    kal_bool  gnssReferenceTimeReq;     /* fill the request as above example */
    kal_bool  gnssReferenceLocationReq;
    kal_bool  gnssIonosphericModelReq;  /* klobucharModel for GPS, neQuickModel for Galileo, therefore we fill the request according to GNSS method */
    kal_bool  gnssEarthOrientationParametersReq;
} gnss_request_common_assist_data_struct;


/**
 * For generic assistance data, we need to specify GNSS id, and its requested assistance data type.
 * In some assistance data, we also need to include more data in addition to true/false
 *  (1) Time Model => GNSS-ID + deltaTreq
 *  (2) D-Correction => GNSS-Signal-ID + udreValidityTime
 *  (3) Nav Model => stored nav list or request nav list
 *  (4) RTI => only true/false!
 *  (5) Data Bit Assist => GNSS-TOD + interval + speficy which GNSS-Signal-ID, satellite data bit
 *  (6) ACQ => GNSS-Signal-ID
 *  (7) Almanac => Model ID (GNSS-ID map to currect Almanac Model ID)
 *  (8) UTC => Model ID (GNSS-ID map to currect UTC Model ID)
 *  (9) AUX => only true/false!
 */

typedef struct
{
    kal_bool         isRequested;     /* indicate if this type of data is requested */
    kal_uint8        numGnssToIDReq;
    gnss_to_id_enum  GnssToIDReq[GNSS_MAX_TIME_MODEL_ELEMENT];  /* 5-15 is reserved */
} gnss_request_time_model_struct;


typedef struct
{
    kal_bool   isRequested;      /* indicate if this type of data is requested */
    kal_uint8  gnssSignalsReq;   /* requested GNSS Signal(s), map to GNSS_SGN_ID_BITMAP_* */
    kal_bool   validityTimeReq;  /* udreGrowthRate and udreValidityTime are requested or not */
} gnss_request_diff_correction_struct;


typedef struct
{
    kal_uint8   svID;          /* [0..63] */
    kal_uint16  iod;           /* 11 bits field */
    /* GNSS-ID to clock/orbit model ID (map to GNSS_NAV_CLOCK_MODEL_*_VALUE_* and GNSS_NAV_ORBIT_MODEL_*_VALUE_*)
     *  gps    : Model-2
     *  sbas   : Model-5
     *  qzss   : Model-2
     *  galileo: Model-1
     *  glonass: Model-4
     */
    kal_bool    clockModelIDValid;
    kal_uint8   clockModelID;  /* [1..8], optional, specify which clock model used */
    kal_bool    orbitModelIDValid;
    kal_uint8   orbitModelID;  /* [1..8]. optional, specify which orbit model used */
} gnss_sat_data_element_struct;


typedef struct
{
    kal_uint16                    gnssWeekOrDay; /* [0..4095], indicate GNSS week number for non-GLONASS, otherwise indicate calendar number of data within four-year interval starting from 1st of January in a leap year */
    kal_uint8                     gnssToe;       /* [0.255], indicate GNSS time of ephemeris in hours of latest ephemeris for non-GLONASS, otherwise indicate the time of ephemeris in units of 15 minutes of the latest ephemeris */
    kal_uint8                     tToeLimit;     /* [0..15], indicate ephemeris age tolerance in units of hours for non-GLONASS, otherwise indicate ephemeris age tolerance in units of 30 minutes */
    kal_uint8                     numSatDataElement;
    gnss_sat_data_element_struct  satDataElement[GNSS_MAX_NAV_SAT_ELEMENT];  /* optional */
} gnss_stored_nav_list_struct;


typedef struct
{
    kal_uint8  svReqList[GNSS_MAX_NAV_SAT_ELEMENT_BIT_POS/8];  /* bit position represent SV-ID, total 64 bits */
    /* GNSS-ID to clock/orbit model ID (map to GNSS_NAV_CLOCK_MODEL_*_VALUE_* and GNSS_NAV_ORBIT_MODEL_*_VALUE_*)
     *  gps    : Model-2
     *  sbas   : Model-5
     *  qzss   : Model-2
     *  galileo: Model-1
     *  glonass: Model-4
     */
    kal_uint8  numClockModelIDPrefList;
    kal_uint8  clockModelIDPrefList[GNSS_MAX_NAV_CLOCK_MODEL_ELEMENT];  /* optional, list requested clock model in the order of preference */
    kal_uint8  numOrbitModelIDPrefList;
    kal_uint8  orbitModelIDPrefList[GNSS_MAX_NAV_ORBIT_MODEL_ELEMENT];  /* optional, list requested orbit model in the order of preference */
    kal_bool   addNaparamReqValid;
    kal_bool   addNavparamReq;                                          /* dedicated for orbit model - nav-keplerian-set (gps) if need to include addNAVpara IE */
} gnss_requested_nav_list_struct;


typedef struct
{
    kal_bool                            isRequested;          /* indicate if this type of data is requested */
    gnss_nav_model_req_type_enum        type;                 /* storedNavList or reqNavList */
    /* 
     * TBD: NAV request would be too complex for GNSS task/MNL to have this kind of detailed nav data.
     *      evaluate if we could simplify it (always use requestd nav list according to GNSS method?)
     */
    union
    {
        gnss_stored_nav_list_struct     storedNavList;  /* this needs GNSS chip response current searched SAT info (in detailed) */
        gnss_requested_nav_list_struct  reqNavList;     /* this could simply fill corresponding IE according network specified GNSS method, but needs svID list */
    } data;
} gnss_request_nav_model_struct;


typedef struct
{
    kal_bool    isRequested;                           /* indicate if this type of data is requested */
    kal_uint16  gnssTODReq;                            /* [0..3599], specify the reference time for the first data bit requestd in GNSS specific system time, modulo 1 hour, scale factor 1 second */
    kal_bool    gnssTODFracReqValid;
    kal_uint16  gnssTODFracReq;                        /* [0..999], speficty the franctional part of GNSS-TOD-Req, scale factor 1 millisecond */
    kal_uint8   dataBitInterval;                       /* [0..15], value K, the time length for Data Bit Assist requested, r (second) = 0.1*2^K, K=0 means it is not specified */
    kal_uint8   gnssSignalTypes;                       /* requested GNSS Signal(s), map to GNSS_SGN_ID_BITMAP_* */
    kal_uint8   numReqSatList;
    kal_uint8   ReqSatList[GNSS_MAX_DBA_SAT_ELEMENT];  /* optional, list contains SV-IDs for Data Bit Assist requested */
} gnss_request_data_bit_assist_struct;


typedef struct
{
    kal_bool   isRequested;        /* indicate if this type of data is requested */
    kal_uint8  gnssSignalTypeReq;  /* requested signal type, only specify one single signal, map to GNSS_SGN_ID_VALUE_* */
} gnss_request_acq_assist_struct;


typedef struct
{
    kal_bool   isRequested;     /* indicate if this type of data is requested */
    /* this could simply fill corresponding IE according network specified GNSS method */
    /*
     * GNSS-ID to almanac model ID (map to GNSS_ALMANAC_MODEL_*_VALUE_*)
     *  gps    : Model-2 (keplerian NAV almanac set)
     *  sbas   : Model-6 (ecef-SBAS almanac set)
     *  qzss   : Model-2 (keplerian NAV almanac set)
     *  galileo: Model-1 (keplerian almanac set)
     *  glonass: Model-5 (Glonass almanac set)
     */
    kal_bool   modelIDValid;
    kal_uint8  modelID;  /* [1..8], currently 1..6 */
} gnss_request_almanac_struct;


typedef struct
{
    kal_bool   isRequested;     /* indicate if this type of data is requested */
    /* this could simply fill corresponding IE according network specified GNSS method */
    /*
     * GNSS-ID to UTC model ID (map to GNSS_UTC_MODEL_*_VALUE)
     *  gps    : Model-1
     *  sbas   : Model-4
     *  qzss   : Model-1
     *  galileo: Model-1
     *  glonass: Model-3
     */
    kal_bool   modelIDValid;
    kal_uint8  modelID;  /* [1..8], currently 1..4 */
} gnss_request_utc_model_struct;


typedef struct
{
    gnss_id_enum  gnssID;
    kal_bool      sbasIDValid;
    sbas_id_enum  sbasID;
 
    gnss_request_time_model_struct       gnssTimeModelsReq;
    gnss_request_diff_correction_struct  gnssDCorrectionsReq;
    gnss_request_nav_model_struct        gnssNavModelReq;
    kal_bool                             gnssRTIReq;
    gnss_request_data_bit_assist_struct  gnssDataBitAssistReq;
    gnss_request_acq_assist_struct       gnssAcqAssistReq;
    gnss_request_almanac_struct          gnssAlmanacReq;
    gnss_request_utc_model_struct        gnssUTCModelReq;
    kal_bool                             gnssAuxInfoReq;
} gnss_request_generic_assist_data_struct;


typedef struct
{
    gnss_request_common_assist_data_struct   gnssCommonAssistData;
    kal_uint8                                numGnssGenericAssistData;
    gnss_request_generic_assist_data_struct  gnssGenericAssistData[GNSS_MAX_REQ_ADD_GENERIC_ASSIST_DATA_ELEMENT];
} gnss_request_assist_data_struct;


typedef struct
{
    gnss_eutra_cell_id_struct  cellID;
    kal_uint16                 systemFrameNumber;  /* 10 bits field, refer TS 36.331 */
} gnss_measured_ref_network_time_eutra_struct;


typedef struct
{
    gnss_utra_cell_id_struct  cellID;
    kal_uint16                refSystemFrameNumber;  /* [0..4095], refer TS 25.331 */
} gnss_measured_ref_network_time_utra_struct;


typedef struct
{
    gnss_gsm_cell_id_struct  cellID;
    kal_uint16               referenceFN;       /* [0..65535] */
    kal_bool                 referenceFNMSBValid;
    kal_uint8                referenceFNMSB;    /* [0..63], FN (frame number) = referenceFNMSB*42432 + referenceFN */
    kal_bool                 deltaGNSSTODValid;
    kal_uint8                deltaGNSSTOD;      /* [0..127], the difference in millisecond between gnssTODmsec and millisecond part of the SV time of first SV in the list reported from target device */
} gnss_measured_ref_network_time_gsm_struct;


typedef struct
{
    gnss_network_cell_type_enum                      type;
    union
    {
        gnss_measured_ref_network_time_eutra_struct  eutra;
        gnss_measured_ref_network_time_utra_struct   utra;
        gnss_measured_ref_network_time_gsm_struct    gsm;
    } data;
} gnss_measured_ref_network_time_struct;


typedef struct
{
    kal_uint32                             gpsTOW;            /* [0..604799999], scale factor millisecond, only used for legacy GPS! (gnssTimeID == GPS) */
    kal_uint16                             gnssDayNumber;     /* [0..32767] */
    kal_uint32                             gnssTODmsec;       /* [0..3599999], scale factor 1 millisecond in a hour*/
    kal_bool                               gnssTODfracValid;
    kal_uint16                             gnssTODfrac;       /* [0..3999], scale factor 250 nanoseconds */
    kal_bool                               gnssTODuncValid;
    kal_uint8                              gnssTODunc;        /* [0..127], K = [0..127], uncertainty r (microseconds) = C*(((1+x)^K)-1), C=0.5, x=0.14 */
    gnss_id_enum                           gnssTimeID;        /* specify GNSS type of GNSS system time (TOD+frac) provided */

    /* contain networkTime only if fineTimeAssistanceMeasReq is TRUE */
    kal_bool                               networkTimeValid;
    gnss_measured_ref_network_time_struct  networkTime;
} gnss_measured_ref_time;


/* we only support horizontal velocity */
typedef struct
{
    kal_uint16  bearing;          /* [0..359], direction clockwise from North, scale factor 1 degrees */
    kal_uint16  horizontalSpeed;  /* [0..2047], scale factor 1 kilometers/hour */
} gnss_h_velocity_struct;


typedef struct
{
    kal_bool                signOfLatitude;        /* TRUE: SOUTH, FALSE: NORTH */
    kal_uint32              degreesLatitude;       /* [0..8388607], 23 bits field */
    kal_int32               degreesLongitude;      /* [-8388608..8388607], 24 bits field */
    kal_bool                signOfAltitude;        /* TRUE: DEPTH, FALSE: HEIGHT */
    kal_uint16              altitude;              /* [0..32767], 15 bits field */
    kal_uint8               uncertaintySemiMajor;  /* K: [0..127], uncertainty r (meter) = C*((1+x)^K-1), C=10, x=0.1 */
    kal_uint8               uncertaintySemiMinor;  /* K: [0..127], uncertaintyr (meter) = C*((1+x)^K-1), C=10, x=0.1 */
    kal_uint8               orientationMajorAxis;  /* bearing angle degree: [0-179] */
    kal_uint8               uncertaintyAltitude;   /* K: [0..127], uncertainty h (meter) = C*((1+x)^K-1), C=45, x=0.025 */
    kal_uint8               confidence;            /* [0..100] */
    kal_bool                velocityValid;
    gnss_h_velocity_struct  velocityEstimate;
} gnss_gad_pos_estimate_struct;


typedef struct
{
    kal_uint16                    gnssMethod;        /* specify the estimated location is calculated by which GNSS systems, map to GNSS_ID_BITMAP_* */
    gnss_gad_pos_estimate_struct  locationEstimate;
    gnss_measured_ref_time        measuredRefTime;   /* should always present */
} gnss_pos_result_struct;


/* This structure for MSG_ID_LCSP_GNSS_POS_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                           transactionID;

    gnss_loc_result_enum                 resultStatus;

    gnss_pos_result_type_enum            type;
    union
    {
        gnss_pos_result_struct           posResult;      /* only valid when resultStatus = GNSS_LOC_RESULT_NO_ERROR */
        gnss_request_assist_data_struct  assistDataReq;  /* used for ULCS/RRLP, selected when resultStatus = GNSS_LOC_RESULT_ASSIST_DATA_MISSING */
    } data;
} lcsp_gnss_pos_cnf_struct;


typedef struct
{
    kal_uint8   svID;                   /* [0..63] */
    kal_uint8   cNo;                    /* [0..63], carrier-to-noise ratio, scale factor 1dB-Hz */
    kal_uint8   multipath;              /* multipath indicator, real data is two bits field represent multipath enum
                                           '0' = Not measured
                                           '1' = Low, MP error < 5m
                                           '2' = Medium, 5m < MP error < 43m
                                           '3' = High, MP error > 43m
                                         */

    /* use validity flag and rearrange fields to reduce structure size */
    /** 
     *  GNSS_MEAS_INFO_CARRIER_QUALITY_VALIDITY   0x01
     *  GNSS_MEAS_INFO_INT_CODE_PHASE_VALIDITY    0x02
     *  GNSS_MEAS_INFO_DOPPLER_VALIDITY           0x04
     *  GNSS_MEAS_INFO_ADR_VALIDITY               0x08
     */
    kal_uint8   validity;

    kal_uint8   carrierQualityInd;      /* [0..3], two bits field represent carrier phase data inverted/direct, and (not) continuous */
    kal_uint8   intCodePhase;           /* [0..127], integer millisecond part of code phase modulo codePhaseAmbiguity, scale factor 1 milli-seconds in the range from 0 to 127 milliseconds */

    /* to represent codephase RMS error value index, refer floating-point representation mapping table, LPP/RRC/RRLP should combine M & E to index value according to the table */
    kal_uint8   codePhaseRMSErrorM;     /* codePhase(pseudorange) RMS Error Mantissa */
    kal_uint8   codePhaseRMSErrorE;     /* codePhase(Pseudorange) RMS Error Exponent */

    kal_int16   doppler;                /* [-32768..32767], scale factor 0.04 meter/seconds */

    kal_uint32  codePhase;              /* [0..2097151], contain the whole and fractional value of the code phase, scale factor 2^(-21) milliseconds in the range from 0 to (1-2^(-21)) milliseconds */

    kal_uint32  adr;                    /* [0 .. 33554431], accumulated delta range, scale factor 2^(-10) meters in the range for 0 to 32767.5 meters */
} gnss_measure_info_one_sat;


typedef struct
{
    kal_uint8                  signalID;                 /* map to GNSS_SGN_ID_VALUE_* */
    kal_bool                   codePhaseAmbiguityValid;
    kal_uint8                  codePhaseAmbiguity;       /* [0..127], scale factor 1 milli-seconds */
    kal_uint8                  numSatMeasElement;
    gnss_measure_info_one_sat  satMeasElement[GNSS_MAX_MEASURED_SAT_PER_SGN_ELEMENT];
} gnss_measure_info_one_sgn;


typedef struct
{
    gnss_id_enum               gnssID;
    kal_uint8                  numSgnMeasElement;
    gnss_measure_info_one_sgn  sgnMeasElement[GNSS_MAX_MEASURED_SGN_PER_GNSS_ELEMENT];
} gnss_measure_info_one_gnss;


typedef struct
{
    /**
     * Measurement information up to 16 GNSSs can be included.
     * Per GNSS, up to 8 GNSS signal measurements
     * Per GNSS signal measurement (band), up to 64 GNSS satellites
     */
    kal_uint8                   numGnssMeasElements;
    gnss_measure_info_one_gnss  gnssMeasElement[GNSS_MAX_MEASURED_GNSS_ELEMENT];
    gnss_measured_ref_time      measuredRefTime;  /* should always present */
} gnss_measured_result_struct;


/* This structure for MSG_ID_LCSP_GNSS_MEAS_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                           transactionID;

    gnss_loc_result_enum                 resultStatus;

    gnss_meas_result_type_enum           type;
    union
    {
        gnss_measured_result_struct      measuredResult;  /* only valid when resultStatus = GNSS_LOC_RESULT_NO_ERROR */
        gnss_request_assist_data_struct  assistDataReq;   /* used for ULCS/RRLP, selected when resultStatus = GNSS_LOC_RESULT_ASSIST_DATA_MISSING */
    } data;
} lcsp_gnss_meas_cnf_struct;


/* This structure for MSG_ID_LCSP_GNSS_ADDITIONAL_ASSIST_DATA_REQ */
/* This primitive is dedicated for LPP:
 * For LPP, if we request additional assistance data, the network will not resent
 * a new RequestLocationInformation followed by ProvideAssistanceData (two procedures are independent).
 *
 * Therefore, the response time will not reset and LPP will not send a new LCSP_GNSS_POS(MEAS)_REQ,
 * that's why we separate request additional assistance data by another message
 * rather than embeded in LCSP_GNSS_POS(MEAS)_CNF (as RRLP/ULCS design)
 */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                       transactionID;  /* transaction ID should align LCSP_GNSS_POS(MEAS)_REQ if present, for checking assistanceAvailability */

    kal_uint16                       gnssMethod;     /* network allowed GNSS type in LCSP_GNSS_POS(MEAS)_REQ if present (or current GNSS chip operation mode), may be multiple GNSS, map to GNSS_ID_BITMAP_* */
    gnss_request_assist_data_struct  assistDataReq;
} lcsp_gnss_additional_assist_data_req_struct;

/* start for gnss chip support */
typedef struct
{
    gnss_id_enum               gnssID;
    kal_uint8                  sgnIdBitmap;
} gnss_gnss_info_one_gnss;

typedef struct
{
    kal_bool                    adrFlag;
    kal_bool                    ftaFlag;           
    kal_bool                    dgnssFlag;
    kal_uint8                   gnssNumber;
    gnss_id_enum                gnssID;
    gnss_gnss_info_one_gnss     gnssInfo;
    
} gnss_capability_report_struct;



//#endif /* #if defined(__AGNSS_SUPPORT__) || defined(__AGPS_SUPPORT__) */

#endif /* _GNSS2LCSP_STRUCT_H */

