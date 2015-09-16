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
 *   cldmacore_except_if.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   CLDMA core exception mode APIs header file
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 ****************************************************************************/
#ifndef _CLDMACORE_EXCEPT_IF_H
#define _CLDMACORE_EXCEPT_IF_H

/*!
 *  @brief AP_CCCI_ASSERT_CB is used for AP CCCI assert MD through SDIO SW INT
 */
typedef void (*AP_CCCI_ASSERT_CB)(void); 


kal_bool cldmac_except_init(kal_uint32 dhldl_q, kal_uint32 expt_q);
kal_bool cldmac_except_clear_q(kal_uint8 queue_type, kal_uint8 queue_no);
kal_bool cldmac_except_set_gpd(kal_uint8 queue_type, kal_uint8 queue_no, void *p_first_gpd, void *p_last_gpd);
kal_int32 cldmac_except_poll_gpd(kal_uint8 queue_type, kal_uint8 queue_no, void **pp_first_gpd, void **pp_last_gpd);
kal_bool cldmac_except_hif_isr(void);
kal_bool cldmac_except_link_st(kal_uint8 queue_type, kal_uint8 queue_no);

/*trigger CCIF interrupt (ch 6) to AP for seq error assert*/
void hifcldma_seq_err_D2H_int();

/* write seq into the last 4 bytes  of ccif SRAM */
void hifcldma_write_seq(kal_uint32 seq); 

/* CCCI callback when receive CCIF interrupt (ch 6) for seq error assert */
void hifcldma_register_seq_err_assert_callback(AP_CCCI_ASSERT_CB func_cb_ptr);


#endif //#ifndef _CLDMACORE_EXCEPT_IF_H
