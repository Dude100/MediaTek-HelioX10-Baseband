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
/*
**   Includes
*/
#include "kal_general_types.h"

/* For customer define the refresh rate of pwr_level_report period in idle state, unit second */
#define PWR_LEVEL_REP_PERIOD_IDLE  10

/* For customer define the refresh rate of pwr_level_report period in dedicated state, helf second */
#define PWR_LEVEL_REP_PERIOD_DEDI  5 /* 5: 2.5s */


/* For 3G */
/* For customer define the refresh rate of pwr_level_report period in idle/PCH states, mini second */
#define UAS_PWR_LEVEL_REP_PERIOD_IDLEPCH  5000

/* For customer define the refresh rate of pwr_level_report period in FACH/DCH states, mini second */
#define UAS_PWR_LEVEL_REP_PERIOD_FACHDCH  2500

#ifdef __NBR_CELL_INFO__
/* For customer, define the reporting rate for 3G neighbor cell information, per 10 mini second */
#define UAS_NBR_CELL_INFO_REP_PERIOD  500

/* For customer, define the number of reported cell for 3G neighbor cell information */
#define UAS_NBR_CELL_INFO_REP_NUM  6
#endif

#if defined(__MODEM_EM_MODE__)
/* For customer, define the reporting rate for EM mode 3G neighbor cell information.
 * Unit: milliseconds.
 * Default set to 1 second.
 * Recommand: the period shall larger than 500. (500ms)*/
#define UAS_EM_DCH_UMTS_CELL_INFO_REP_PERIOD  1000
#endif

/*****************************************************************************
* FUNCTION
*  rr_get_power_ind_period_idle
* DESCRIPTION
*   This function is used to define the refresh rate for
*   RR report serv_cell measured RSSI level to MMI in idle state.
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint8 rr_get_power_ind_period_idle (void)
{
   return (PWR_LEVEL_REP_PERIOD_IDLE);
}

/*****************************************************************************
* FUNCTION
*  rr_get_power_ind_period_dedi
* DESCRIPTION
*   This function is used to define the refresh rate for
*   RR report serv_cell measured RSSI level to MMI in dedicated state.
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint8 rr_get_power_ind_period_dedi (void)
{
   return (PWR_LEVEL_REP_PERIOD_DEDI);
}

/*****************************************************************************
* FUNCTION
*  uas_get_power_ind_period_idlepch
* DESCRIPTION
*   This function is used to define the refresh rate for
*   UAS to report the measured RSCP and Ec/No of serving cell to MMI in idle/PCH states.
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 uas_get_power_ind_period_idlepch (void)
{
   return (UAS_PWR_LEVEL_REP_PERIOD_IDLEPCH);
}

/*****************************************************************************
* FUNCTION
*  uas_get_power_ind_period_fachdch
* DESCRIPTION
*   This function is used to define the refresh rate for
*   UAS to report the measured RSCP and Ec/No level of active set cell to MMI in FACH/DCH states.
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 uas_get_power_ind_period_fachdch (void)
{
   return (UAS_PWR_LEVEL_REP_PERIOD_FACHDCH);
}

#ifdef __NBR_CELL_INFO__
/*****************************************************************************
* FUNCTION
*  uas_get_power_ind_period_fachdch
* DESCRIPTION
*   This function is used to define the refresh rate for
*   UAS to report the measured RSCP and Ec/No level of active set cell to MMI in FACH/DCH states.
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 uas_nbr_cell_info_ind_period (void)
{
   return (UAS_NBR_CELL_INFO_REP_PERIOD);
}

/*****************************************************************************
* FUNCTION
*  uas_get_power_ind_period_fachdch
* DESCRIPTION
*   This function is used to define the refresh rate for
*   UAS to report the measured RSCP and Ec/No level of active set cell to MMI in FACH/DCH states.
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint8 uas_nbr_cell_info_rep_cell_num (void)
{
   return (UAS_NBR_CELL_INFO_REP_NUM);
}

#endif

#if defined(__MODEM_EM_MODE__)
/*****************************************************************************
* FUNCTION
*  uas_dch_em_umts_cell_info_ind_period
* DESCRIPTION
*   This function is used to define the reporting rate for
*   UAS to report the cell info in EM mode in DCH states.
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint32 uas_dch_em_umts_cell_info_ind_period (void)
{
   return (UAS_EM_DCH_UMTS_CELL_INFO_REP_PERIOD);
}
#endif


