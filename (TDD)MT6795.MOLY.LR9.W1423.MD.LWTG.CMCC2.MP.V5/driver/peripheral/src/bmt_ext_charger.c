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
 *    bmt_ext_charger.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines external charger interface
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include    "drv_features.h"
#include    "bmt_sw.h"



#if defined(__GENERAL_EXTERNAL_CHARGER__)
bmt_ext_charger_custom_config *ext_charger_config;

// Called at drv init phase
void default_drv_init(void)
{
	ext_charger_config = bmt_ext_charger_get_custom_config();
	return;
}

// Called at pmic adpt layer init phase
// The phase what scheduler is running(BMT task is created)
void default_enable_intr(void)
{
	return;
}

// Control charge enable/disable
// Called at any time, any context
kal_bool default_charge_enable(kal_bool enable)
{
	//kal_uint32 savedMask;
	//savedMask = SaveAndSetIRQMask();

	if (ext_charger_config->charge_enable != NULL)
	{
		ext_charger_config->charge_enable(enable);
	}
	//if (enable)
	//{
	//	// Set CTRL pin to LOW to enable charging
	//	GPIO_WriteIO(0, gpio_ext_chr_ctrl_pin);
	//}
	//else
	//{
	//	// Set CTRL pin to HIGH to enable charging
	//	GPIO_WriteIO(1, gpio_ext_chr_ctrl_pin);
	//}
	//RestoreIRQMask(savedMask);

	return KAL_TRUE;
}

// The unit is in mA ==> 1000 means 1A
// Called at any time, any context
// 500mA means can NOT large than 500mA, but most close to 500mA
kal_bool default_set_charge_current(kal_int32 charge_current)
{
	if (ext_charger_config->charge_current != NULL)
	{
		ext_charger_config->charge_current(charge_current);
	}
	//kal_uint32 savedMask;
	//savedMask = SaveAndSetIRQMask();
	//if (charge_current > 500)
	//{
	//	// Set CTRL pin to HIGH for AC
	//	GPIO_WriteIO(1, gpio_ext_chr_iset_ctrl_pin);
	//}
	//else
	//{
	//	// Set CTRL pin to LOW for USB
	//	GPIO_WriteIO(0, gpio_ext_chr_iset_ctrl_pin);
	//}
	//RestoreIRQMask(savedMask);
	return KAL_TRUE;
}

// Whether the external charger can measure the passed-in charging factor
bmt_chr_fac_measure_support_enum default_get_chr_fac_measure_support(bmt_chr_fac_enum chr_fac)
{
	switch (chr_fac)
	{
		case BMT_CHR_FACTOR_VBAT:
		case BMT_CHR_FACTOR_ISENSE:
		case BMT_CHR_FACTOR_BATTMP:
		case BMT_CHR_FACTOR_VCHARGER:
			return CHR_FACTOR_MEASURE_BY_HOST;
		break;

		default:
			ASSERT(0); // Not Support
		break;

	}
	ASSERT(0); // Not support
	return CHR_FACTOR_MEASURE_NONE;
}

// Whether the external charger can check the passed-in charging factor
bmt_chr_fac_check_support_enum default_get_chr_fac_check_support(bmt_chr_fac_enum chr_fac)
{
	switch (chr_fac)
	{
		case BMT_CHR_FACTOR_CHARGE_FULL:
			if (ext_charger_config->charge_full_ind != NULL)
			{
				return BMT_CHR_FACTOR_CHECK_BY_CHARGER_DEV;
			}
			else
			{
				return BMT_CHR_FACTOR_CHECK_BY_HOST;
			}
		break;
		case BMT_CHR_FACTOR_UNDER_EXTREMETMP:
			if (ext_charger_config->charge_under_extremetmp_ind != NULL)
			{
				return BMT_CHR_FACTOR_CHECK_BY_CHARGER_DEV;
			}
			else
			{
				return BMT_CHR_FACTOR_CHECK_BY_HOST;
			}
		break;
		case BMT_CHR_FACTOR_CHARGE_EXTREMETMP_FULL:
			if (ext_charger_config->charge_extremetmp_full_ind != NULL)
			{
				return BMT_CHR_FACTOR_CHECK_BY_CHARGER_DEV;
			}
			else
			{
				return BMT_CHR_FACTOR_CHECK_BY_HOST;
			}
		break;
		case BMT_CHR_FACTOR_CHARGE_EXTREMETMP_RECHARGE:
			if (ext_charger_config->charge_extremetmp_recharge_ind != NULL)
			{
				return BMT_CHR_FACTOR_CHECK_BY_CHARGER_DEV;
			}
			else
			{
				return BMT_CHR_FACTOR_CHECK_BY_HOST;
			}
		break;
		case BMT_CHR_FACTOR_VBAT:
		case BMT_CHR_FACTOR_ISENSE:
		case BMT_CHR_FACTOR_BATTMP:
		case BMT_CHR_FACTOR_VCHARGER:
		case BMT_CHR_FACTOR_CHARGER_OVP:
		case BMT_CHR_FACTOR_HOLD:
		case BMT_CHR_FACTOR_CHR_BATT_STATE:
			return BMT_CHR_FACTOR_CHECK_BY_HOST;
		break;

		default:
			ASSERT(0); // Not Support
		break;

	}
	ASSERT(0); // Not support
	return BMT_CHR_FACTOR_CHECK_NONE;
}

// Pass information to charger device
// Charger device can calculate the charger status through the passed-in info
void default_check_chr_status(BATPHYStruct *pBatPhysStat)
{
	return;
}

// Charger return calculated charger status
// Usually, charger device should keep the chr status before reset_chr_status() is called
// The return kal_uint32 is union of all charging factors status
kal_uint32 default_get_chr_status(void)
{
	// If the charger does NOT support error check, just return BMT_CHR_STATUS_NONE
	return BMT_CHR_STATUS_NONE;
}

// The return unit is uV ==> 1000000 means 1.0V
// The passed-in parameter is the information measured by HOST,
// ext charger driver need this info to calculate
kal_int32 default_get_vbat(BATPHYStruct *pBatPhysStat)
{
	// ASSERT(0);  // Assert?? Since the charger does NOT support, should NOT be called
	return 0;
}

// The return unit is mA ==> 1000 means 1A
// The passed-in parameter is the information measured by HOST,
// ext charger driver need this info to calculate
kal_int32 default_get_isense(BATPHYStruct *pBatPhysStat)
{
	// ASSERT(0);  // Assert?? Since the charger does NOT support, should NOT be called
	return 0;
}

// The return unit is uV ==> 1000000 means 1.0V
// The passed-in parameter is the information measured by HOST,
// ext charger driver need this info to calculate
kal_int32 default_get_vcharger(BATPHYStruct *pBatPhysStat)
{
	// ASSERT(0);  // Assert?? Since the charger does NOT support, should NOT be called
	return 0;
}

// Return the calculated NTC value of battery temperature
// The passed-in parameter is the information measured by HOST,
// ext charger driver need this info to calculate
kal_int32 default_get_bat_temp(BATPHYStruct *pBatPhysStat)
{
	// ASSERT(0);  // Assert?? Since the charger does NOT support, should NOT be called
	return 0;
}

// Return if charge full
// The unit is vbat is uV ==> 1000000 means 1.0V
// Return KAL_TRUE: Charge full
// Return KAL_FALSE: Not charge full
kal_bool default_get_charge_full(kal_int32 vbat)
{
	if (ext_charger_config->charge_full_ind != NULL)
	{
		return ext_charger_config->charge_full_ind(vbat);
	}
	return KAL_FALSE;
}

kal_bool default_get_charge_under_extremetmp(kal_int32 battmp)
{
	if (ext_charger_config->charge_under_extremetmp_ind != NULL)
	{
		return ext_charger_config->charge_under_extremetmp_ind(battmp);
	}
	return KAL_FALSE;
}

// Return if charge full under extreme temperature
// The unit is vbat is uV ==> 1000000 means 1.0V
// Return KAL_TRUE: Charge full
// Return KAL_FALSE: Not charge full
kal_bool default_get_charge_extremetmp_full(kal_int32 vbat)
{
	if (ext_charger_config->charge_extremetmp_full_ind != NULL)
	{
		return ext_charger_config->charge_extremetmp_full_ind(vbat);
	}
	return KAL_FALSE;
}

// Return if charge full under extreme temperature
// The unit is vbat is uV ==> 1000000 means 1.0V
// Return KAL_TRUE: Charge full
// Return KAL_FALSE: Not charge full
kal_bool default_get_charge_extremetmp_recharge(kal_int32 vbat)
{
	if (ext_charger_config->charge_extremetmp_recharge_ind != NULL)
	{
		return ext_charger_config->charge_extremetmp_recharge_ind(vbat);
	}
	return KAL_FALSE;
}

// Return KAL_TRUE: Need to hold charging
// Return KAL_FALSE: Do NOT need to hold charging
// The condition to hold charging: Talking mode ...
kal_bool default_get_charge_hold(BATPHYStruct *pBatPhysStat)
{
	// ASSERT(0);  // Assert?? Since the charger does NOT support, should NOT be called
	return 0;
}


// Whether the external charger check specific charging batt state transition
bmt_chr_fac_check_support_enum default_get_chr_batt_state_transit_support(kal_uint32 curr_chr_batt_state)
{
	switch (curr_chr_batt_state)
	{
		case CHR_PRE:
		case CHR_FAST:
		case CHR_TOPOFF:
		case CHR_BATFULL:
		case CHR_ERROR:
		case CHR_HOLD:
			return BMT_CHR_FACTOR_CHECK_BY_HOST;
		break;
		default:
			ASSERT(0); // NOT supported
		break;
	}
	ASSERT(0);
	return BMT_CHR_FACTOR_CHECK_NONE;
}

// Perform charring batt state state transit
// curr_chr_batt_state: Current state
// chr_on: Current CHR_EN state
void default_chr_batt_state_transit (kal_uint32 curr_chr_batt_state, kal_bool chr_en)
{
	return;
}

// Get charging battery state PRE, FAST(CC), TOPOFF(CV), FULL, ...
kal_uint32 default_get_curr_chr_batt_state(BATPHYStruct *pBatPhysStat)
{
	ASSERT(0); // Not supported
	return CHR_FAST;
}

// Get custom charge current according to specific charger
kal_uint32 default_get_specific_chr_current(bmt_charger_type charger)
{
	if (ext_charger_config->get_custom_charge_current != NULL)
	{
		return ext_charger_config->get_custom_charge_current(charger);
	}
	return 500;
}


bmt_ext_charger default_ext_charger_drv =
{
	default_drv_init,
	default_enable_intr,
	default_charge_enable,
	default_set_charge_current,
	default_get_chr_fac_measure_support,
	default_get_chr_fac_check_support,
	default_check_chr_status,
	default_get_chr_status,
	default_get_vbat,
	default_get_isense,
	default_get_vcharger,
	default_get_bat_temp,
	default_get_charge_full,
	default_get_charge_under_extremetmp,
	default_get_charge_extremetmp_full,
	default_get_charge_extremetmp_recharge,
	default_get_charge_hold,
	default_get_chr_batt_state_transit_support,
	default_chr_batt_state_transit,
	default_get_curr_chr_batt_state,
	default_get_specific_chr_current
};

bmt_ext_charger *bmt_get_ext_charger(void)
{
//	default_ext_charger_drv.drv_init = default_drv_init;
//	default_ext_charger_drv.enable_intr = default_enable_intr;
//	default_ext_charger_drv.charge_enable = default_charge_enable;
//	default_ext_charger_drv.set_charge_current = default_set_charge_current;
//	default_ext_charger_drv.get_chr_fac_measure_support = default_get_chr_fac_measure_support;
//	default_ext_charger_drv.get_chr_fac_check_support = default_get_chr_fac_check_support;
//	default_ext_charger_drv.check_chr_status = default_check_chr_status;
//	default_ext_charger_drv.get_chr_status = default_get_chr_status;
//	default_ext_charger_drv.get_vbat = default_get_vbat;
//	default_ext_charger_drv.get_isense = default_get_isense;
//	default_ext_charger_drv.get_vcharger = default_get_vcharger;
//	default_ext_charger_drv.get_bat_temp = default_get_bat_temp;
//	default_ext_charger_drv.get_charge_hold = default_get_charge_hold;
//	default_ext_charger_drv.get_chr_batt_state_transit_support = default_get_chr_batt_state_transit_support;
//	default_ext_charger_drv.chr_batt_state_transit = default_chr_batt_state_transit;
//	default_ext_charger_drv.get_curr_chr_batt_state = default_get_curr_chr_batt_state;

	return &default_ext_charger_drv;
}





#endif // #if defined(__GENERAL_EXTERNAL_CHARGER__)






