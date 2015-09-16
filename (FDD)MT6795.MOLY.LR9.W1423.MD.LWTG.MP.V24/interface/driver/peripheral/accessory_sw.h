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
 *    accessory_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for accessory detector driver and adaption.
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
#ifndef ACCESSSORY_SW_H
#define ACCESSSORY_SW_H

#include "kal_general_types.h"

typedef struct
{
   // This API is for aux task to register HISR handler for earphone
   // PWIC will use det_earphone_present() to determine whether it is in/out
   void (*reg_earphone_hisr)(void (earphone_hisr_callback)(void));

   // This API is for aux task to register HISR handler for tvout
   // PWIC will use det_earphone_present() to determine whether it is in/out
   void (*reg_tvout_hisr)(void (tvout_hisr_callback)(void));

   // This API is for aux task to register HISR handler for earphone key
   // PWIC will use det_earphone_present() to determine whether it is in/out
   void (*reg_key_hisr)(void (key_hisr_callback)(void));

   // This API is to set S/W debounce time for earphone cable
   // The uint of deb_time is in 10ms (GPT tick)
   void (*set_earphone_in_deb_time)(kal_uint32 deb_time);
 
   // This API is to set S/W debounce time for earphone cable
   // The uint of deb_time is in 10ms (GPT tick)
   void (*set_earphone_out_deb_time)(kal_uint32 deb_time);
   
   // This API is to set S/W debounce time for tvout cable
   // The uint of deb_time is in 10ms (GPT tick)
   void (*set_tvout_in_deb_time)(kal_uint32 deb_time);
 
   // This API is to set S/W debounce time for tvout cable
   // The uint of deb_time is in 10ms (GPT tick)
   void (*set_tvout_out_deb_time)(kal_uint32 deb_time);
 
   // This API is to set S/W debounce time for key press
   // The uint of deb_time is in 10ms (GPT tick)
   void (*set_key_press_deb_time)(kal_uint32 deb_time);
 
   // This API is to set S/W debounce time for key release
   // The uint of deb_time is in 10ms (GPT tick)
   void (*set_key_release_deb_time)(kal_uint32 deb_time);
 
   // Init the external accessory detection mechanism
   // The API is called at boot phase
   void (*drv_init)(void);
 
   // The API is called at driver init phase
   void (*enable_intr)(void);
  
}aux_ext_accessory_det;

typedef struct
{
	void (*aux_plug_in)(void);
	void (*aux_plug_out)(void);
	void (*aux_uart_func)(kal_bool enable);
	void (*aux_HSTV_func)(kal_bool enable);
}aux_func_struct;



#if defined(__DRV_EXT_ACCESSORY_DETECTION__ )
extern aux_ext_accessory_det *aux_ext_acc_det;
extern aux_ext_accessory_det *aux_custom_get_ext_accessory_det(void);
#endif // #if defined(__DRV_EXT_ACCESSORY_DETECTION__ )



#endif//#define ACCESSSORY_SW_H
