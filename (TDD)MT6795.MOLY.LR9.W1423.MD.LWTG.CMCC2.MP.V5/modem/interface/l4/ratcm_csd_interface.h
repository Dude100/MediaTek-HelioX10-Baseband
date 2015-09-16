/*******************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2002
 *
 ******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ratcm_csd_interface.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _RATCM_CSD_INTERFACE_H
#define _RATCM_CSD_INTERFACE_H

/* MAUI_02828210, redundant header removal */
/***************************
Include Prefix Header Files
****************************/
#include "kal_general_types.h"

/***************************
Exported Function Prototypes
****************************/

typedef enum
{
   CSD_MODE_NO,
   CSD_MODE_TRA,
   CSD_MODE_NT,
   CSD_MODE_TRA_FAX,
   CSD_MODE_NT_FAX
}  
CSD_MODE_ENUM;

typedef enum
{
   CSD_USER_RATE_2400,
   CSD_USER_RATE_4800,
   CSD_USER_RATE_7200,
   CSD_USER_RATE_9600,
   CSD_USER_RATE_12000,
   CSD_USER_RATE_14400,
   CSD_USER_RATE_19200,
   CSD_USER_RATE_28800,
   CSD_USER_RATE_38400,
   CSD_USER_RATE_48000,
   CSD_USER_RATE_56000,
   CSD_USER_RATE_64000  /* MAUI_02375911 */
} 
CSD_USER_RATE_ENUM;


typedef enum
{
   CSD_ON = 0,
   CSD_OFF
} 
CSD_STATUS_ENUM;

typedef struct
{
    CSD_STATUS_ENUM sa;
    CSD_STATUS_ENUM sb;
    CSD_STATUS_ENUM x;
} 
CSD_V24_STATUS_STRUCT;

typedef enum{
CSD_TICK_RATE_10MS,
CSD_TICK_RATE_20MS,
CSD_TICK_RATE_40MS,
CSD_TICK_RATE_80MS    
} CSD_TICK_RATE_ENUM;


#if defined(__CSD_T__) || defined(__CSD_NT__) || defined(__CSD_FAX__)

/* Provided by DATA to RATCM */
extern void csd_ratcm_downlink_tick_ind(kal_uint8 simInterface);
extern void csd_ratcm_uplink_tick_ind(kal_bool dtx_allow, 
                                      kal_uint8 rat,
                                      CSD_USER_RATE_ENUM csd_user_rate, 
                                      kal_bool isFR,
                                      CSD_TICK_RATE_ENUM tick_rate,
                                      kal_uint16 byte_cnt,
                                      kal_uint8 simInterface );


extern void csd_ratcm_suspend_ind(kal_uint8 simInterface);
extern void csd_ratcm_resume_ind(kal_uint8 simInterface);


/* Provided by RATCM to DATA */
extern kal_bool csd_ratcm_activate_req(CSD_MODE_ENUM csd_mode, CSD_USER_RATE_ENUM csd_user_rate, kal_bool isFR, kal_uint8 simInterface);
extern void csd_ratcm_deactivate_req(kal_uint8 simInterface);
extern void csd_ratcm_put_uplinkdata_req (kal_uint8* data, kal_uint16 size, CSD_V24_STATUS_STRUCT csd_v24_status, kal_uint8 simInterface);
extern kal_uint16 csd_ratcm_get_downlinkdata_req (kal_uint8* data, kal_uint16 size, CSD_V24_STATUS_STRUCT *csd_v24_status, kal_uint8 simInterface);


#ifdef __UMTS_RAT__

/* Provided by RATCM. */
extern void ratcm_csr_csd_uplink_tick(kal_bool dtx_allow, CSD_USER_RATE_ENUM csd_user_rate,
                                      CSD_TICK_RATE_ENUM  tick_rate, kal_uint16 byte_cnt);
extern void ratcm_csr_csd_downlink_tick(void);


/* Provided by CSR. */
extern void ratcm_csr_activate_req(CSD_MODE_ENUM csd_mode,CSD_USER_RATE_ENUM user_rate);
extern void ratcm_csr_deactivate_req(void);
extern void ratcm_csr_csd_put_uplinkdata(kal_uint8* data, kal_uint16 length, 
                                         CSD_V24_STATUS_STRUCT csd_v24status);
extern kal_uint16 ratcm_csr_csd_get_downlinkdata(kal_uint16 sduLength, kal_uint8* data,
                                         CSD_V24_STATUS_STRUCT *csd_v24status);

#endif /* endif __UMTS_RAT__ */


#ifdef __GSM_RAT__

/* Provided by RATCM to L1RA */
void ratcm_ra_uplinktick (kal_bool dtx_allow, CSD_USER_RATE_ENUM csd_user_rate, kal_bool isFR, kal_uint16 byte_cnt, kal_uint8 simInterface);
void ratcm_ra_downlinktick (kal_uint8 simInterface);
void ratcm_ra_loopmode(kal_bool loopmode, kal_uint8 simInterface);

/* Provided by RA to RATCM */
extern void ratcm_ra_activate_req(CSD_MODE_ENUM csd_mode, CSD_USER_RATE_ENUM csd_user_rate, kal_bool isFR,  kal_uint8 sim_mode);
extern void ratcm_ra_deactivate_req(kal_uint8 sim_mode);
extern void ratcm_ra_putuplinkdata ( kal_uint8* data, kal_uint16 size, CSD_V24_STATUS_STRUCT csd_v24_status, kal_uint8 sim_mode);
extern kal_uint16 ratcm_ra_getdownlinkdata ( kal_uint8* data, kal_uint16 size,  
                                             CSD_V24_STATUS_STRUCT *csd_v24_status, kal_uint8 sim_mode);

#endif /* endif __GSM_RAT__ */

#endif /* endif defined(__CSD_T__) || defined(__CSD_NT__) || defined(__CSD_FAX__) */

#endif /* _RATCM_CSD_INTERFACE_H */
