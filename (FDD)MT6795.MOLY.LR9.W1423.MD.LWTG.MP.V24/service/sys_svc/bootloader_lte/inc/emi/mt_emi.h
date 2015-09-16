/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   mt_emi.h
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *  This file is for EMI setting
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * add get dram info function in bootloader
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 ****************************************************************************/

#ifndef __MT_EMI_H__
#define __MT_EMI_H__

#include "dramc_calib.h"

typedef struct drv_dram_info_s {
    unsigned int dual_rank;
    unsigned int row_num;
    unsigned int bank_num;
    unsigned int col_num;
    unsigned int bus_width;
    unsigned int apmcu_ofst;
    unsigned int apperi_ofst;
} drv_ramc_dram_info_t;

/* ===================== */
/*   Function            */
/* ===================== */
/*************************************************************************
* FUNCTION
*  drv_ramc_get_dram_info()
*
* DESCRIPTION
*   This routine aims to get EMI and DRAM information
*
* PARAMETERS
*  struct of drv_ramc_dram_info_t
*
* RETURNS
*  DRAM Size
*
*************************************************************************/
unsigned int drv_ramc_get_dram_info(drv_ramc_dram_info_t * drv_ramc_dram_info);

/*
 * mt_set_emi: Set up EMI/DRAMC.
 * Entry Function for set up EMI/DRAMC
 */
dramc_cal_err_code mt_set_emi(void);

#endif /* end of __MT_EMI_H__ */

