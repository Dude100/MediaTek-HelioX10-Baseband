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
 *    cs_fac_det.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is header file of customer specific factory mode detection mechanism interface
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CS_FAC_DET_H__
#define __CS_FAC_DET_H__


// The enum lists the boot mode that the customer may request to force boot into
// Customer may request to boot into specific boot mode for specific factory mode
// The factory mode detection mechanism should take responsibility to link factory mode <-> factory boot mode
// and report to PWIC at boot time (If necessary)
typedef enum{
	CS_FAC_BOOT_IDLE = 0,
	CS_FAC_BOOT_CHARGING,
	CS_FAC_BOOT_USB_CHARGING,
	CS_FAC_BOOT_MAX
}cs_fac_boot_mode_enum;

// Currently, take these strctures as common structures
// If there is new customer specific facroty mode SPEC
// then we come back to review if the current definition is enough or NOT

// The enum lists factory modes
// The customer may request to have different activities according to different factory mode
typedef enum{
	CS_FAC_NONE = 0x00000000,    // Factory NONE ==> Means NO factory mode is detected
	CS_FAC_UART = 0x00000001,    // Bit00, Factory UART
	CS_FAC_USB  = 0x00000002,    // Bit01, Factory USB
	CS_FAC_CTRL = 0x00000004,    // Bit02, Factory manual ctrl mode
	CS_FAC_MAX  = 0x10000000     // Bit31, Used for error check purpose
}cs_fac_mode_enum;

#define CS_FAC_MODE_NUM      4   // Total fac modes supported


typedef struct{
	// Drv init
	void (*drv_init)(void);

	// Return expect boot mode according to specific customer spec
	// The spec is implement in the function
	cs_fac_boot_mode_enum (*factory_det_get_boot_mode)(void);

	// Return whether the specific factory mode is detected or NOT
	// KAL_TRUE: The specific fac event is detected
	// KAL_FALSE: The specific fac event is NOT detected
	kal_bool (*factory_det_query_fac_mode)(cs_fac_mode_enum);

	// Set the factory mode by other modules
	void (*factory_det_set_fac_mode)(cs_fac_mode_enum);

	// Clear the factory mode by other modules
	void (*factory_det_clear_fac_mode)(cs_fac_mode_enum);

}cs_factory_detecter;


extern cs_factory_detecter *cs_fac_det;
extern cs_factory_detecter *cs_fac_det_get_interface(void);

#endif // #define __CS_FAC_DET_H__



