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
 *    dcl_pmic6329_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMIC 6329
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifndef __DCL_PMU6329_SW_H_STRUCT__
#define __DCL_PMU6329_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#ifdef PMIC_6329_REG_API

/*
// debug 1
// Define to keep chaging when assert
// This flag is only for debug purpose
//#define DRV_MISC_PMIC_ASSERT_KEEP_CHARGING
//#define DEBUG_PMIC6329_NO_CHARGER_WATCHDOG_TIMER


// debug 2
// Define to enable PMIC6329 charger watch dog timer kick
// When enable charger, PMIC6329 will enable a watch dog timer
// We need to kick the timer periodically, to ontify PMIC6329 that BB is alive
// If timeout, PMIC6329 will disable charge automatically
// #### If this is NOT enabled, we will disable the watch dog timer function at boot time
//#define ENABLE_PMIC_DRIVER_KICK_CHARGER_WATCHDOG_TIMER  ==> Move to be activated by BMT charging algorithm, do NOT use this anymore
*/

#define PMIC6329_ECO_1_VERSION		0x01
#define PMIC6329_ECO_2_VERSION		0x02

#ifndef PMIC_OLD_STRUCTURE
#define PMIC_OLD_STRUCTURE

#endif //#define PMIC_OLD_STRUCTURE

typedef enum
{
    AC_CHR_CALLBACK=0,
    USB_CHR_CALLBACK
}chr_callback_type;

typedef struct 
{
	void (*pmic_ac_det)(void);
	void (*pmic_usb_det)(void); 
}pmic6329_chrdect_callbac_struct;

extern void dcl_pmic6329_ChrDet_Registration(chr_callback_type type, void (*Callback)(void));

// Combinational functions
extern void dcl_pmic6329_EM_reg_write(kal_uint8 reg, kal_uint8 val);
extern kal_uint8 dcl_pmic6329_EM_reg_read(kal_uint8 reg);
extern void pmic6329_customization_init(void);
/*
// The following are implemented in custom files
// MoDIS parser skip start
extern void pmic6329_customization_init(void);
extern void pmic6329_cust_vspk_enable(kal_bool enable);
extern void pmic6329_csut_vsim_enable(kal_bool enable);
extern void pmic6329_csut_vsim_sel(pmic_adpt_vsim_volt volt);
extern void pmic6329_csut_vsim2_enable(kal_bool enable);
extern void pmic6329_csut_vsim2_sel(pmic_adpt_vsim_volt sel);
extern void pmic6329_csut_vusb_enable(kal_bool enable);
extern void pmic6329_csut_vcama_enable(kal_bool enable);
extern void pmic6329_csut_vcama_sel(pmic_adpt_vcama_volt vol);
extern void pmic6329_csut_vcamd_enable(kal_bool enable);
extern void pmic6329_csut_vcamd_sel(pmic_adpt_vcamd_volt volt);
// MoDIS parser skip end
*/

#endif // #ifdef PMIC_6329_REG_API
#endif // #ifndef __DCL_PMU6329_SW_H_STRUCT__

