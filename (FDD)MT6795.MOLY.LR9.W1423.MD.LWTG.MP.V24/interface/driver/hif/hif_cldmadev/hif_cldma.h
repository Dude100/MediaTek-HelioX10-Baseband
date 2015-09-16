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
 *   hif_cldma.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 * driver header of CLDMA device IP
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 03 13 2014 box.wu
 * removed!
 * export CLDMA bootup trace address define
 *
 * removed!
 * removed!
 * [CCCI EXPT] Add boot up trace API for 82lte
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	.
 ****************************************************************************/


#ifndef __HIF_CLDMA_H__
#define __HIF_CLDMA_H__

#define HIFCLDMA_MAX_ULQ_NUM 8
#define HIFCLDMA_MAX_DLQ_NUM 8

#include "reg_base.h"

#if defined(__HIF_CCIF_SUPPORT__)
#define CLDMA_BOOTUP_TRACE_ADDR (BASE_ADDR_MDCCIF + 0x0100 + 512 - 8)	// last 8 bytes of SRAM
#elif defined(__HIF_WCCIF_SUPPORT__)
#define CLDMA_BOOTUP_TRACE_ADDR (MD_CCIF0_BASE + 0x0100 + 512 - 8)	// last 8 bytes of SRAM
#endif


typedef struct _hifcldma_isr_status{
	kal_uint32	L2TISAR0;
	kal_uint32	L2TISAR1;
	kal_uint32	L3TISAR0;
	kal_uint32	L3TISAR1;
	kal_uint32	L2RISAR0;
	kal_uint32	L2RISAR1;
	kal_uint32	L3RISAR0;
	kal_uint32	L3RISAR1;
} hifcldma_isr_status_t;

typedef struct _hifcldma_property {

    /*!
     *  @brief total UL QMU queues requested to configure
     */
    kal_uint8           ulq_num;
    /*!
     *  @brief total DL QMU queues requested to configure
     */
    kal_uint8           dlq_num;
    /*!
     *  @brief reserve for 4 bytes alignment
     */
    kal_uint8           reserve[2];    
    
     /*!
     *  @brief  set the checksum function of QMU is enable or not
     */
    kal_uint8            checksum_ul_ch_en;
    kal_uint8            checksum_dl_ch_en;

    /*!
     *  @brief  set the checksum bytes, KAL_FALSE = use 12bytes checksum
     *             Notice : the CLDMA IP only has 16bytes checksum now, 12bytes ability will be added in future. 
     */
    kal_bool            checksum_ul_16bytes;
    kal_bool            checksum_dl_16bytes;

    /*!
     *  @brief  set whether IOC function of DL queue is diable or not
     *             (if disable, the interrupt will occurs when each GPD is transfered done no matter the IOC bit of GPD)
     */
    kal_bool            dl_ioc_dis[HIFCLDMA_MAX_DLQ_NUM];

   /*!
     *  @brief cldma_isr_cb_func is the call back function for ISR
     */
    void    (*cldma_isr_cb_func)(hifcldma_isr_status_t cldma_int_status);

} hifcldma_property_t;

/*!
 *  @brief  initialize cldma hif driver 
 *  @param
 *  @return KAL_TRUE if initial success , 
 		   KAL_FALSE if initial failure.
 */
kal_bool hifcldma_init();

/*!
 *  @brief  ask cldma hif driver to set this property
 *  @param  property    the property cldmacore will set
 *  @return KAL_TRUE if the property can be satisfied, otherwise KAL_FALSE
 */
kal_bool hifcldma_set_property(hifcldma_property_t* p_cldma_property);

/*!
 *  @brief  to inform host that function is ready, so host can transfer normal data
 *             upper application can call this function after GPDs initial is complete.
 */
void hifcldma_set_func_ready();

/*!
 *  @brief  to check cldma hardware error statue, it will assert when error occurs
 *
 */
void hifcldma_err_check();

#endif
