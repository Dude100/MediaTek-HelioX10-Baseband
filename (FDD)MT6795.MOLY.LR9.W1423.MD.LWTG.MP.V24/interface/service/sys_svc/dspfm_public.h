/*****************************************************************************
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
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dspfm_public.h
 *
 * Project:
 * --------
 *   Moly
 *
 * Description:
 * ------------
 *   Exported interface of LTE DSP file management
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _DSPFM_PUBLIC_H
#define _DSPFM_PUBLIC_H

typedef enum{
    DSPFM_OK = 0,
    DSPFM_ERR_DSP_REGION_NOT_FOUND = -1,
    DSPFM_ERR_DSP_FILE_NOT_OPEND = -2,
    DSPFM_ERR_DSP_EXCEED_FILE_SIZE = -3,
    DSPFM_ERR_DSP_READ_DATA_FAIL = -4,
    DSPFM_ERR_DSP_READ_HEAD_DATA_FAIL = -5,
    DSPFM_ERR_DSP_READ_TAIL_DATA_FAIL = -6,
    DSPFM_ERR_DSP_GET_START_PAGE_FAIL = -7,
    DSPFM_ERR_DSP_PTR_NOT_4B_ALIGN = -8, 
    DSPFM_ERR_DSP_OFFSET_NOT_4B_ALIGN = -9, 
    DSPFM_ERR_DSP_FAIL_GET_FILE_SIZE = -10,
    DSPFM_ERR_DSP_FILE_SEEK_FAIL  = -11,
    DSPFM_ERR_DSP_GFH_READ_FAIL  = -12,
    DSPFM_ERR_DSP_WRONG_GFH_TYPE  = -13,
    DSPFM_ERR_DSP_VERSION_CHECK_FAIL = -14,
    DSPFM_ERR_DSP_INVALID_GFH = -15,
    DSPFM_ERR_FILE_SIZE_TOO_LARGE = -16,
    DSPFM_ERR_DSP_FILE_OPEN_FAIL = -17,
}dspfm_errot_t;

/*!
 *  @brief  Open DSP file
 *  @param  none
 *  @return >0 - size of DSP image(not include GFH)
 *              <=0 - error code
 */
extern kal_int32 dspfm_open(void);

/*!
 *  @brief  Read size of data to ptr from offset
 *  @param  ptr - destination addr
 *                offset - data offset 
 *                size - data size
 *  @return 0 - success
 *              <0 - error code
 */
extern kal_int32 dspfm_read(kal_uint32 ptr, kal_uint32 offset, kal_uint32 size);

/*!
 *  @brief  Close DSP file 
 *  @param  none
 *  @return none
 */
extern void dspfm_close(void);

/*!
 *  @brief  Get GFH size in DSP image 
 *  @param  none
 *  @return size of DSP image's GFG
 */
extern kal_uint32 dspfm_get_DSP_GFH_length(void);


#if defined(__MODEM_ONLY__)

#define LTE_DSP_BIN_BASE  0x08000000

#else /*else of __MODEM_ONLY__*/

extern kal_uint32 Image$$EXTSRAM_DSP_DATA_ZI$$Base;
#define LTE_DSP_BIN_BASE  &Image$$EXTSRAM_DSP_DATA_ZI$$Base

#endif



#endif /*_DSPFM_PUBLIC_H*/
