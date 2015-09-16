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
 *   gnss2lcsp_enum.h
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
 *
 *****************************************************************************/

#ifndef _GNSS2LCSP_ENUM_H
#define _GNSS2LCSP_ENUM_H


/* MACROS *******************************************************************/

/**
 * among LPP/RRC/RRLP, the max number of elements for GNSS data is different in some data fields.
 * we take the largest value as element definition for common interface
 */
#define GNSS_MAX_REF_TIME_SAT_ELEMENT                    16  /* 64 for LPP, 16 for RRC, 12 for RRLP. Use 16 to reduce structure size */
#define GNSS_MAX_REF_CELL_FTA_ELEMENT                    16  /* 16 for LPP, 1 for RRC/RRLP */

#define GNSS_MAX_GNSS_GENERIC_ASSIST_DATA_ELEMENT        16  /* 16 for LPP, 8 for RRC/RRLP in provide assistance data;
                                                                16 for LPP/RRLP, 8 for RRC in capability */

/* GNSS Time Model */
#define GNSS_MAX_TIME_MODEL_ELEMENT                       4  /* 15 for LPP, 7 for RRC/RRLP, Use 4 since gnss-TO-ID only 4 (GPS, Galileo, QZSS, GLONASS) */

/* GNSS DGNSS */
#define GNSS_MAX_DGNSS_SGN_TYPE_ELEMENT                   3  /* 3 for LPP/RRLP, 8 for RRC */
#define GNSS_MAX_DGNSS_CORRECTION_INFO_ELEMENT           16  /* 64 for LPP/RRC, 16 for RRLP. Use 16 to reduce structure size */

/* GNSS Navigation Model */
#define GNSS_MAX_NAV_SAT_ELEMENT                         16  /* 64 for LPP/RRC, 32 for RRLP. Use 16 to reduce structure size */
#define GNSS_MAX_NAV_SAT_ELEMENT_BIT_POS                 64  /* 64 for LPP/RRC, 32 for RRLP, dedicated for assist data req */
#define GNSS_MAX_NAV_STD_CLK_MODEL_ELEMENT                4  /* 2 for LPP/RRLP, 4 for RRC */
#define GNSS_MAX_NAV_CLOCK_MODEL_ELEMENT                  5  /* currently there is 5 clock models */
#define GNSS_MAX_NAV_ORBIT_MODEL_ELEMENT                  5  /* currently there is 5 orbit models */

/* GNSS Real Time Integrity */
#define GNSS_MAX_RTI_BAD_SAT_ELEMENT                     16  /* 64 for LPP/RRC, 16 for RRLP. Use 16 to reduce structure size */

/* GNSS Data Bit Assistance */
#define GNSS_MAX_DBA_SGN_TYPE_ELEMENT                     8  /* 8 for LPP/RRC/RRLP */
#define GNSS_MAX_DBA_SAT_ELEMENT                         16  /* 64 for LPP/RRC, 32 for RRLP. Use 16 to reduce structure size */
#define GNSS_MAX_DBA_BIT_LENGTH                          64  /* 1024 bit for LPP/RRC/RRLP, but RRLP use integer intead of bit. Process only max 64 bits to reduce structure size */

/* GNSS Acquisition Assitance */
#define GNSS_MAX_ACQ_ASSIST_SAT_ELEMENT                  16  /* 64 for LPP/RRC, 16 for RRLP. Use 16 to reduce structure size */

/* GNSS Almanac */
#define GNSS_MAX_ALMANAC_SAT_ELEMENT                     32  /* 64 for LPP/RRC, 36 for RRLP. Use 32 to reduce structure size */

/* GNSS Auxiliary Information */
#define GNSS_MAX_AUX_SAT_ELEMENT                         16  /* 64 for LPP/RRC/RRLP. Use 16 to reduce structure size */

/* GNSS Measurement Info */
#define GNSS_MAX_MEASURED_GNSS_ELEMENT                   GNSS_MAX_SUPPORT_NUM  /* 16 for LPP, 8 for RRC/RRLP, Use GNSS_MAX_SUPPORT_NUM (4) to reduce structure size */
#define GNSS_MAX_MEASURED_SGN_PER_GNSS_ELEMENT                              4  /* 8 for LPP/RRC/RRLP, Use 4 to reduce structure size */
#define GNSS_MAX_MEASURED_SAT_PER_SGN_ELEMENT                              16  /* 64 for LPP/RRC, 16 for RRLP. Use 16 to reduce structure size */

/* GNSS Request Additional Generic Assist Data */
#define GNSS_MAX_REQ_ADD_GENERIC_ASSIST_DATA_ELEMENT     GNSS_MAX_SUPPORT_NUM  /* 16 for LPP, 8 for RRC, unspecified for RRLP (up to 40 bytes), Use 9 since number of generic assistance data type is only 9 */


/* GNSS ID Bitmap, use two-byte representation */
#define GNSS_ID_BITMAP_NONE     0x00
#define GNSS_ID_BITMAP_GPS      0x8000  /* gps     (0) */
#define GNSS_ID_BITMAP_SBAS     0x4000  /* sbas    (1) */
#define GNSS_ID_BITMAP_QZSS     0x2000  /* qzss    (2) */
#define GNSS_ID_BITMAP_GALILEO  0x1000  /* galileo (3) */
#define GNSS_ID_BITMAP_GLONASS  0x0800  /* glonass (4) */

#define GNSS_ID_BITMAP_GPS_GLONASS  (GNSS_ID_BITMAP_GPS | GNSS_ID_BITMAP_GLONASS)

/* TBD: check with WCN, MT6630 support GPS+QZSS+GLONASS+Galileo+Beidou */
#define GNSS_MAX_SUPPORT_NUM    0x02 /* A-GPS + A-GLONASS */

/* SBAS ID Bitmap, use one-byte representation */
#define SBAS_ID_BITMAP_NONE   0x00
#define SBAS_ID_BITMAP_WASS   0x80  /* waas  (0) */
#define SBAS_ID_BITMAP_EGNOS  0x40  /* egnos (1) */
#define SBAS_ID_BITMAP_MSAS   0x20  /* msas	 (2) */
#define SBAS_ID_BITMAP_GAGAN  0x10  /* gagan (3) */

/* GNSS Signal IDs Bitmap, use one-byte representation
 * GNSS    | Bit 1  | Bit 2 | Bit 3 | Bit 4 | Bit 5 | Bit 6 | Bit 7 | Bit 8 |
 *         | (MSB)  |       |       |       |       |       |       | (LSB) |
 * --------+--------+-------+-------+-------+-------+-------+-------+-------+
 * GPS     | L1 C/A |  L1C  |  L2C  |   L5  | -- reserved --|-------|-------|
 * SBAS    |   L1   | -- reserved --|-------|-------|-------|-------|-------|
 * QZSS    | QZS-L1 |QZS-L1C|QZS-L2C| QZS-L5| -- reserved --|-------|-------|
 * GLONASS |   G1   |   G2  |  G3   | -- reserved --|-------|-------|-------|
 * Galileo |   E1   |   E5a |  E5b  |   E6  |E5a+E5b| -- reserved --|-------|
*/
/* TBD: need confirmation GNSS signal spectrum from WCN */
#define GNSS_SGN_ID_BITMAP_GPS_L1C_A       0x80  /* bit 1 */
#define GNSS_SGN_ID_BITMAP_GPS_L1C         0x40  /* bit 2 */
#define GNSS_SGN_ID_BITMAP_GPS_L2C         0x20  /* bit 3 */
#define GNSS_SGN_ID_BITMAP_GPS_L5          0x10  /* bit 4 */

#define GNSS_SGN_ID_BITMAP_SBAS_L1         0x80  /* bit 1 */

#define GNSS_SGN_ID_BITMAP_QZSS_L1C_A      0x80  /* bit 1 */
#define GNSS_SGN_ID_BITMAP_QZSS_L1C        0x40  /* bit 2 */
#define GNSS_SGN_ID_BITMAP_QZSS_L2C        0x20  /* bit 3 */
#define GNSS_SGN_ID_BITMAP_QZSS_L5         0x10  /* bit 4 */

#define GNSS_SGN_ID_BITMAP_GLONASS_G1      0x80  /* bit 1 */
#define GNSS_SGN_ID_BITMAP_GLONASS_G2      0x40  /* bit 2 */
#define GNSS_SGN_ID_BITMAP_GLONASS_G3      0x20  /* bit 3 */

#define GNSS_SGN_ID_BITMAP_GALILEO_E1      0x80  /* bit 1 */
#define GNSS_SGN_ID_BITMAP_GALILEO_E5A     0x40  /* bit 2 */
#define GNSS_SGN_ID_BITMAP_GALILEO_E5B     0x20  /* bit 3 */
#define GNSS_SGN_ID_BITMAP_GALILEO_E6      0x10  /* bit 4 */
#define GNSS_SGN_ID_BITMAP_GALILEO_E5_A_B  0x08  /* bit 5 */

/* GNSS Signal ID value */
#define GNSS_SGN_ID_VALUE_GPS_L1C_A       0
#define GNSS_SGN_ID_VALUE_GPS_L1C         1
#define GNSS_SGN_ID_VALUE_GPS_L2C         2
#define GNSS_SGN_ID_VALUE_GPS_L5          3

#define GNSS_SGN_ID_VALUE_SBAS_L1         0

#define GNSS_SGN_ID_VALUE_QZSS_L1C_A      0
#define GNSS_SGN_ID_VALUE_QZSS_L1C        1
#define GNSS_SGN_ID_VALUE_QZSS_L2C        2
#define GNSS_SGN_ID_VALUE_QZSS_L5         3

#define GNSS_SGN_ID_VALUE_GLONASS_G1      0
#define GNSS_SGN_ID_VALUE_GLONASS_G2      1
#define GNSS_SGN_ID_VALUE_GLONASS_G3      2

#define GNSS_SGN_ID_VALUE_GALILEO_E1      0
#define GNSS_SGN_ID_VALUE_GALILEO_E5A     1
#define GNSS_SGN_ID_VALUE_GALILEO_E5B     2
#define GNSS_SGN_ID_VALUE_GALILEO_E6      3
#define GNSS_SGN_ID_VALUE_GALILEO_E5_A_B  4

#define GNSS_SGN_ID_VALUE_MAX             7

/* GNSS Clock and Orbit Model Value (for Navigation Model) */
#define GNSS_NAV_CLOCK_MODEL_1_VALUE_STANDARD  1  /* model-1 */
#define GNSS_NAV_CLOCK_MODEL_2_VALUE_NAV       2  /* model-2 */
#define GNSS_NAV_CLOCK_MODEL_3_VALUE_CNAV      3  /* model-3 */
#define GNSS_NAV_CLOCK_MODEL_4_VALUE_GLONASS   4  /* model-4 */
#define GNSS_NAV_CLOCK_MODEL_5_VALUE_SBAS      5  /* model-5 */

#define GNSS_NAV_ORBIT_MODEL_1_VALUE_KEPLERIAN_SET       1  /* model-1 */
#define GNSS_NAV_ORBIT_MODEL_2_VALUE_NAV_KEPLERIAN_SET   2  /* model-2 */
#define GNSS_NAV_ORBIT_MODEL_3_VALUE_CNAV_KEPLERIAN_SET  3  /* model-3 */
#define GNSS_NAV_ORBIT_MODEL_4_VALUE_GLONASS_ECEF        4  /* model-4 */
#define GNSS_NAV_ORBIT_MODEL_5_VALUE_SBAS_ECEF           5  /* model-5 */

/* Almanac Model Value */
#define GNSS_ALMANAC_MODEL_1_VALUE_KEPLERIAN_SET          1  /* model-1 */
#define GNSS_ALMANAC_MODEL_2_VALUE_NAV_KEPLERIAN_SET      2  /* model-2 */
#define GNSS_ALMANAC_MODEL_3_VALUE_REDUCED_KEPLERIAN_SET  3  /* model-3 */
#define GNSS_ALMANAC_MODEL_4_VALUE_MIDI_KEPLERIAN_SET     4  /* model-4 */
#define GNSS_ALMANAC_MODEL_5_VALUE_GLONASS_SET            5  /* model-5 */
#define GNSS_ALMANAC_MODEL_6_VALUE_ECEF_SBAS_SET          6  /* model-6 */

/* UTC Model Value */
#define GNSS_UTC_MODEL_1_VALUE  1  /* model-1 (0) */
#define GNSS_UTC_MODEL_2_VALUE  2  /* model-2 (1) */
#define GNSS_UTC_MODEL_3_VALUE  3  /* model-3 (2) */
#define GNSS_UTC_MODEL_4_VALUE  4  /* model-4 (3) */

/* Ionospheric Model */
#define GNSS_ION_MODEL_KLOBUCHAR  0x80  /* klobuchar (0) */
#define GNSS_ION_MODEL_NEQUICK    0x40  /* neQuick   (1) */


/* Navigation Model */
#define GNSS_NAV_CLOCK_MODEL_1_STANDARD  0x80  /* model-1 (0) */
#define GNSS_NAV_CLOCK_MODEL_2_NAV       0x40  /* model-2 (1) */
#define GNSS_NAV_CLOCK_MODEL_3_CNAV      0x20  /* model-3 (2) */
#define GNSS_NAV_CLOCK_MODEL_4_GLONASS   0x10  /* model-4 (3) */
#define GNSS_NAV_CLOCK_MODEL_5_SBAS      0x08  /* model-5 (4) */

#define GNSS_NAV_ORBIT_MODEL_1_KEPLERIAN_SET       0x80  /* model-1 (0) */
#define GNSS_NAV_ORBIT_MODEL_2_NAV_KEPLERIAN_SET   0x40  /* model-2 (1) */
#define GNSS_NAV_ORBIT_MODEL_3_CNAV_KEPLERIAN_SET  0x20  /* model-3 (2) */
#define GNSS_NAV_ORBIT_MODEL_4_GLONASS_ECEF        0x10  /* model-4 (3) */
#define GNSS_NAV_ORBIT_MODEL_5_SBAS_ECEF           0x08  /* model-5 (4) */


/* Almanac */
#define GNSS_ALMANAC_MODEL_1_KEPLERIAN_SET          0x80  /* model-1 (0) */
#define GNSS_ALMANAC_MODEL_2_NAV_KEPLERIAN_SET      0x40  /* model-2 (1) */
#define GNSS_ALMANAC_MODEL_3_REDUCED_KEPLERIAN_SET  0x20  /* model-3 (2) */
#define GNSS_ALMANAC_MODEL_4_MIDI_KEPLERIAN_SET     0x10  /* model-4 (3) */
#define GNSS_ALMANAC_MODEL_5_GLONASS_SET            0x08  /* model-5 (4) */
#define GNSS_ALMANAC_MODEL_6_ECEF_SBAS_SET          0x04  /* model-6 (5) */


/* UTC Model*/
#define GNSS_UTC_MODEL_1  0x80  /* model-1 (0) */
#define GNSS_UTC_MODEL_2  0x40  /* model-2 (1) */
#define GNSS_UTC_MODEL_3  0x20  /* model-3 (2) */
#define GNSS_UTC_MODEL_4  0x10  /* model-4 (3) */


/* GNSS measurement fields validity bitmask */
#define GNSS_MEAS_INFO_CARRIER_QUALITY_VALIDITY   0x01
#define GNSS_MEAS_INFO_INT_CODE_PHASE_VALIDITY    0x02
#define GNSS_MEAS_INFO_DOPPLER_VALIDITY           0x04
#define GNSS_MEAS_INFO_ADR_VALIDITY               0x08
#define GNSS_MEAS_INFO_ALL_VALIDITY               0x0F

#define CHECK_GNSS_MEAS_INFO_CARRIER_QUALITY_VALIDITY(validity)      ((validity & GNSS_MEAS_INFO_ALL_VALIDITY) & GNSS_MEAS_INFO_CARRIER_QUALITY_VALIDITY) ? KAL_TRUE : KAL_FALSE
#define SET_GNSS_MEAS_INFO_CARRIER_QUALITY_VALIDITY(validity)        (validity |= GNSS_MEAS_INFO_CARRIER_QUALITY_VALIDITY)

#define CHECK_GNSS_MEAS_INFO_INT_CODE_PHASE_VALIDITY(validity)       ((validity & GNSS_MEAS_INFO_ALL_VALIDITY) & GNSS_MEAS_INFO_INT_CODE_PHASE_VALIDITY) ? KAL_TRUE : KAL_FALSE
#define SET_GNSS_MEAS_INFO_INT_CODE_PHASE_VALIDITY(validity)         (validity |= GNSS_MEAS_INFO_INT_CODE_PHASE_VALIDITY)

#define CHECK_GNSS_MEAS_INFO_DOPPLER_VALIDITY(validity)              ((validity & GNSS_MEAS_INFO_ALL_VALIDITY) & GNSS_MEAS_INFO_DOPPLER_VALIDITY) ? KAL_TRUE : KAL_FALSE
#define SET_GNSS_MEAS_INFO_DOPPLER_VALIDITY(validity)                (validity |= GNSS_MEAS_INFO_DOPPLER_VALIDITY)

#define CHECK_GNSS_MEAS_INFO_ADR_VALIDITY(validity)                  ((validity & GNSS_MEAS_INFO_ALL_VALIDITY) & GNSS_MEAS_INFO_ADR_VALIDITY) ? KAL_TRUE : KAL_FALSE
#define SET_GNSS_MEAS_INFO_ADR_VALIDITY(validity)                    (validity |= GNSS_MEAS_INFO_ADR_VALIDITY)


/* GNSS assist data type bitmask */
#define GNSS_ASSIST_MASK_NONE                        0x0

#define GNSS_COM_ASSIST_MASK_REF_TIME                (1 << 0)  /* 0x0001 */
#define GNSS_COM_ASSIST_MASK_REF_LOCATION            (1 << 1)  /* 0x0002 */
#define GNSS_COM_ASSIST_MASK_IONOSPHERE              (1 << 2)  /* 0x0004 */
#define GNSS_COM_ASSIST_MASK_EARTH_ORIENT_PARAMS     (1 << 3)  /* 0x0008 */

#define GNSS_GEN_ASSIST_MASK_TIME_MODEL              (1 << 4)  /* 0x0010 */
#define GNSS_GEN_ASSIST_MASK_DGNSS_CORRECTION        (1 << 5)  /* 0x0020 */
#define GNSS_GEN_ASSIST_MASK_NAV_MODEL               (1 << 6)  /* 0x0040 */
#define GNSS_GEN_ASSIST_MASK_RTI                     (1 << 7)  /* 0x0080 */
#define GNSS_GEN_ASSIST_MASK_DATA_BIT_ASSIST         (1 << 8)  /* 0x0100 */
#define GNSS_GEN_ASSIST_MASK_ACQUISITION             (1 << 9)  /* 0x0200 */
#define GNSS_GEN_ASSIST_MASK_ALMANAC                 (1 <<10)  /* 0x0400 */
#define GNSS_GEN_ASSIST_MASK_UTC_MODEL               (1 <<11)  /* 0x0800 */
#define GNSS_GEN_ASSIST_MASK_AUX_INFO                (1 <<12)  /* 0x1000 */


#define GNSS_ASSIST_MB_MANDATORY_MASK                (GNSS_COM_ASSIST_MASK_REF_TIME            | \
                                                      GNSS_COM_ASSIST_MASK_REF_LOCATION        | \
                                                      GNSS_COM_ASSIST_MASK_IONOSPHERE          | \
                                                      GNSS_COM_ASSIST_MASK_EARTH_ORIENT_PARAMS | \
                                                      GNSS_GEN_ASSIST_MASK_TIME_MODEL          | \
                                                      GNSS_GEN_ASSIST_MASK_DGNSS_CORRECTION    | \
                                                      GNSS_GEN_ASSIST_MASK_NAV_MODEL           | \
                                                      GNSS_GEN_ASSIST_MASK_RTI                 | \
                                                      GNSS_GEN_ASSIST_MASK_DATA_BIT_ASSIST     | \
                                                      GNSS_GEN_ASSIST_MASK_ALMANAC             | \
                                                      GNSS_GEN_ASSIST_MASK_UTC_MODEL           | \
                                                      GNSS_GEN_ASSIST_MASK_AUX_INFO)     /* 0x1DFF */

                                                 
#define GNSS_ASSIST_MA_MANDATORY_MASK               (GNSS_COM_ASSIST_MASK_REF_TIME             | \
                                                     GNSS_GEN_ASSIST_MASK_ACQUISITION          | \
                                                     GNSS_GEN_ASSIST_MASK_AUX_INFO)      /* 0x1201 */
                                                 

#define GNSS_ASSIST_TIME_INDEPENDENT_MASK           (GNSS_COM_ASSIST_MASK_REF_LOCATION)  /* 0x0002 */



/* NNUM ********************************************************************/

typedef enum
{
    GNSS_NETWORK_CELL_TYPE_NULL,
    GNSS_NETWORK_CELL_TYPE_EUTRA,
    GNSS_NETWORK_CELL_TYPE_UTRA,
    GNSS_NETWORK_CELL_TYPE_GSM
} gnss_network_cell_type_enum;


typedef enum
{
    GNSS_ID_GPS,
    GNSS_ID_SBAS,
    GNSS_ID_QZSS,
    GNSS_ID_GALILEO,
    GNSS_ID_GLONASS
} gnss_id_enum;


typedef enum
{
    GNSS_TO_ID_GPS = 1,
    GNSS_TO_ID_GALILEO,
    GNSS_TO_ID_QZSS,
    GNSS_TO_ID_GLONASS
} gnss_to_id_enum;


typedef enum
{
    SBAS_ID_WAAS,
    SBAS_ID_EGNOS,
    SBAS_ID_MSAS,
    SBAS_ID_GAGAN
} sbas_id_enum;


typedef enum
{
    GNSS_COMMON_ASSIST_DATA_TYPE_REF_TIME,
    GNSS_COMMON_ASSIST_DATA_TYPE_REF_LOCACTION,
    GNSS_COMMON_ASSIST_DATA_TYPE_ION_MODEL,
    GNSS_COMMON_ASSIST_DATA_TYPE_EARTH_ORIENT_PARAMS
} gnss_common_assist_data_type_enum;


typedef enum
{
    GNSS_GENERIC_ASSIST_DATA_TYPE_TIME_MODEL,
    GNSS_GENERIC_ASSIST_DATA_TYPE_DGNSS_CORRECTION,
    GNSS_GENERIC_ASSIST_DATA_TYPE_NAVIGATION_MODEL,
    GNSS_GENERIC_ASSIST_DATA_TYPE_RTI,
    GNSS_GENERIC_ASSIST_DATA_TYPE_DATA_BIT_ASSIST,
    GNSS_GENERIC_ASSIST_DATA_TYPE_ACQUISITION,
    GNSS_GENERIC_ASSIST_DATA_TYPE_ALMANAC,
    GNSS_GENERIC_ASSIST_DATA_TYPE_UTC_MODEL,
    GNSS_GENERIC_ASSIST_DATA_TYPE_AUX_INFO
} gnss_generic_assist_data_type_enum;


typedef enum
{
    GNSS_CLOCK_MODEL_TYPE_STANDARD,
    GNSS_CLOCK_MODEL_TYPE_NAV,
    GNSS_CLOCK_MODEL_TYPE_CNAV,
    GNSS_CLOCK_MODEL_TYPE_GLONASS,
    GNSS_CLOCK_MODEL_TYPE_SBAS
} gnss_clock_model_type_enum;


typedef enum
{
    GNSS_ORBIT_MODEL_TYPE_KEPLERIAN_SET,
    GNSS_ORBIT_MODEL_TYPE_NAV_KEPLERIAN_SET,
    GNSS_ORBIT_MODEL_TYPE_CNAV_KEPLERIAN_SET,
    GNSS_ORBIT_MODEL_TYPE_GLONASS_ECEF,
    GNSS_ORBIT_MODEL_TYPE_SBAS_ECEF
} gnss_orbit_model_type_enum;


typedef enum
{
    GNSS_NAV_MODEL_REQ_TYPE_STORED_NAV_LIST,
    GNSS_NAV_MODEL_REQ_TYPE_REQ_NAV_LIST
} gnss_nav_model_req_type_enum;

typedef enum
{
    GNSS_ACQ_ASSIST_DOPPLER_UNCERTAINTY_EXT_ENUM_D60,
    GNSS_ACQ_ASSIST_DOPPLER_UNCERTAINTY_EXT_ENUM_D80,
    GNSS_ACQ_ASSIST_DOPPLER_UNCERTAINTY_EXT_ENUM_D100,
    GNSS_ACQ_ASSIST_DOPPLER_UNCERTAINTY_EXT_ENUM_D120,
    GNSS_ACQ_ASSIST_DOPPLER_UNCERTAINTY_EXT_ENUM_NO_INFO
} gnss_acq_assist_doppler_uncertainty_ext_enum;


typedef enum
{
    GNSS_ALMANAC_TYPE_KEPLERIAN_SET,
    GNSS_ALMANAC_TYPE_NAV_KEPLERIAN_SET,
    GNSS_ALMANAC_TYPE_REDUCED_KEPLERIAN_SET,
    GNSS_ALMANAC_TYPE_MIDI_KEPLERIAN_SET,
    GNSS_ALMANAC_TYPE_GLONASS_SET,
    GNSS_ALMANAC_TYPE_ECEF_SBAS_SET
} gnss_almanac_type_enum;


typedef enum
{
    GNSS_UTC_MODEL_TYPE_MODEL1,
    GNSS_UTC_MODEL_TYPE_MODEL2,
    GNSS_UTC_MODEL_TYPE_MODEL3,
    GNSS_UTC_MODEL_TYPE_MODEL4
} gnss_utc_model_type_enum;


typedef enum
{
    GNSS_AUX_INFO_GNSS_TYPE_GPS,
    GNSS_AUX_INFO_GNSS_TYPE_GLONASS
} gnss_aux_info_gnss_type_enum;


typedef enum
{
    GNSS_POS_RESULT_TYPE_POS_CNF,
    GNSS_POS_RESULT_TYPE_ASSIST_DATA_REQ
} gnss_pos_result_type_enum;


typedef enum
{
    GNSS_MEAS_RESULT_TYPE_MEAS_CNF,
    GNSS_MEAS_RESULT_TYPE_ASSIST_DATA_REQ
} gnss_meas_result_type_enum;


typedef enum
{
    GNSS_LOC_RESULT_NULL,
    GNSS_LOC_RESULT_NO_ERROR,
    GNSS_LOC_RESULT_UNDEFINED,
    GNSS_LOC_RESULT_REQ_TIMEOUT,
    GNSS_LOC_RESULT_NOT_ENOUGH_SATELLITES,
    GNSS_LOC_RESULT_ASSIST_DATA_MISSING,  /* not used in POS(MEAS)_REQ/CNF primitive */

    /* dedicated for RRLP */
    GNSS_LOC_RESULT_METHOD_NOT_SUPPORTED,
    GNSS_LOC_RESULT_REFERENCE_BTS_NOT_SERVING_BTS,

    /* dedicated for RRC */
    GNSS_LOC_RESULT_NOT_ACCOMPLISHED_TIMING_OF_CELL_FRAMES,  /* similar to FINE_TIME_ASSISTANCE_MEASUREMENTS_NOT_POSSIBLE */
    GNSS_LOC_RESULT_REFERENCE_CELL_NOT_SERVING_CELL,         /* reference cell's SFN cannot be decoded */

    /* dedicated for LPP */    
    GNSS_LOC_RESULT_FINE_TIME_ASSISTANCE_MEASUREMENTS_NOT_POSSIBLE,  /* fineTimeAssistanceMeasurementsNotPossible IE present */
    GNSS_LOC_RESULT_ADR_MEASUREMENTS_NOT_POSSIBLE,                   /* adrMeasurementsNotPossible IE present */
    GNSS_LOC_RESULT_MULTI_FREQUENCY_MEASUREMENTS_NOT_POSSIBLE        /* multiFrequencyMeasurementsNotPossible IE present */

} gnss_loc_result_enum;




#endif /* _GNSS2LCSP_ENUM_H_ */

