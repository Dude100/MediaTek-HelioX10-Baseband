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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   usbms_msdc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of memory card host driver
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/


typedef enum {
	MSDC_MEM_TYPE_EXT = 0,
	MSDC_MEM_TYPE_SIMPLUS = 1,
	MSDC_MEM_TYPE_TCARD2 = 2		
}MSDC_EXT_MEM_TYPE;

typedef enum {
	DEV_STATUS_OK = 0,
	DEV_STATUS_MEDIA_CHANGE,
	DEV_STATUS_NOMEDIA,
	DEV_STATUS_WP,
	DEV_STATUS_MAX
} MSDC_DEV_STATUS;

kal_bool usbms_read_all(void *data, kal_uint32 LBA, kal_uint16 sec_len, MSDC_EXT_MEM_TYPE type);
kal_bool usbms_gpd_read_all(qbm_gpd *head,qbm_gpd *tail,kal_uint32 LBA,kal_uint16 sec_len,MSDC_EXT_MEM_TYPE type);
kal_bool usbms_write_all(void *data, kal_uint32 LBA, kal_uint16 sec_len, MSDC_EXT_MEM_TYPE type);
kal_bool usbms_gpd_write_all(qbm_gpd *head,qbm_gpd *tail,kal_uint32 LBA,kal_uint16 sec_len,MSDC_EXT_MEM_TYPE type);
kal_int16 usbms_checkmedia_exist_all(MSDC_EXT_MEM_TYPE type);
kal_bool usbms_format_all(MSDC_EXT_MEM_TYPE type);
kal_bool usbms_prevmedia_removal_all(kal_bool enable);
kal_bool usbms_query_max_bd_num(kal_uint16 * max_bd_num);
kal_bool usbms_read_capacity_all(kal_uint32 *max_lba, kal_uint32 *sec_len, MSDC_EXT_MEM_TYPE type);

	

