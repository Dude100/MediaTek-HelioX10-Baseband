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
 *    usbacm_logging.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file intends for USB logging tool API definitions
 *
 * Author:
 * -------
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef USBACM_LOGGING_H
#define USBACM_LOGGING_H

//#include "kal_non_specific_general_types.h"
#include "usblog_drv.h"
#include "drv_features_usb.h"


typedef enum
{
	USBACM_LOGGING_DMA_OWNER_NONE,
	USBACM_LOGGING_DMA_OWNER_DMA,
	USBACM_LOGGING_DMA_OWNER_LOG_SRC,
	USBACM_LOGGING_DMA_OWNER_MAX
}USBACM_LOGGING_DMA_OWNER;



typedef struct
{
	USBACM_LOGGING_DMA_OWNER  dma_owner;
#if  (defined(DRV_USB_LOGGING_V6)||defined(DRV_USB_LOGGING_V5)||defined(DRV_USB_LOGGING_V8))
	kal_uint32 	buff_size[USBACM_LOGGING_TOTAL_SOURCE_NUM];
	/* Debug info */
	kal_uint32 	buffer_transmitted_times[USBACM_LOGGING_TOTAL_SOURCE_NUM];
	kal_uint32 	buffer_transmitted_num[USBACM_LOGGING_TOTAL_SOURCE_NUM];
	kal_uint32 	full_times;
	kal_uint8		buff_num[USBACM_LOGGING_TOTAL_SOURCE_NUM];
	kal_uint8		dma_read_index[USBACM_LOGGING_TOTAL_SOURCE_NUM];

	kal_uint8		transmitting_buf_index;	/* buffer source which transmitting */
	kal_uint8		buffer_full_index[USBACM_LOGGING_TOTAL_SOURCE_NUM];
	kal_uint8		empty_buf_count[USBACM_LOGGING_TOTAL_SOURCE_NUM]; 		/* the empty buffer number */
#endif

	kal_uint8		transmitting_count;
	kal_bool		b_not_first_time;		/* used for IRDBG only */
	kal_bool		b_reset;
	kal_bool		b_enable;
}USBACM_LOGGING_Struct;


extern kal_uint8 L1D_IRDMA_Power_GetHandle(void);
extern void  L1D_IRDMA_Power_On(kal_uint8 handle);
extern void  L1D_IRDMA_Power_Off(kal_uint8 handle);

#if (defined(DRV_USB_LOGGING_V5)||defined(DRV_USB_LOGGING_V5))
extern void USBACM_LOGGING_3G_Reset(void);
extern void USBACM_LOGGING_Reset_Hdlr(void);
#endif
extern void USBACM_LOGGING_Init(void);
extern void USBACM_LOGGING_Start_Hdlr(void);
extern void USBACM_LOGGING_Stop(void);
extern void USBACM_LOGGING_Connect_Hdlr(void);
extern void USBACM_LOGGING_Discon_Hdlr(void);
//extern void USBACM_LOGGING_Flush_Data(void);
extern void USB_DSPIRDBG_Flush_Data(void);

#endif /* USBACM_LOGGING_H */


