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
 *    dcl_pmic6326.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMIC6326
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "reg_base.h"
#include "drv_comm.h"
#include "init.h"
#include "intrCtrl.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"
#include "i2c_dual_sw.h"
#include "custom_hw_default.h"

#if defined(PMIC_6326_REG_API)

#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)
#define BL_DIMMING_CONTROL_LEVEL            (PWM_MAX_BACKLIGHT_LEVEL) // Use PWM (%) 

#else
#define BL_DIMMING_CONTROL_LEVEL            (PWM_MAX_LEVEL) // Use PWM (%) 
#endif

// Define to check race condition
//#define PMIC6326_RACE_CONDITION_CHECK

// Define to mask IRQ when performing PMIC APIs
#define PMIC6326_MASKIRQ_WHEN_PERFORM




#define PMIC_INTERNAL_SRAM

#if !defined(__FUE__)
#define SAVEANDSETIRQMASK()      SaveAndSetIRQMask()
#define RESTOREIRQMASK(mask)     RestoreIRQMask(mask)
#else /*defined(__FUE__)*/
#define SAVEANDSETIRQMASK()      0
#define RESTOREIRQMASK(mask)     {}
#endif /*defined(__FUE__)*/


// TTTTTTTT
pmic6326_chrdect_callbac_struct PMIC_CHRDET;

#ifdef PMIC_INTERNAL_SRAM
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#endif // #ifdef PMIC_INTERNAL_SRAM
kal_uint8 pmic6326_reg[PMIC_REG_NUM];

#if defined(PMIC6326_RACE_CONDITION_CHECK)
kal_bool gPerformPMIC6326Func = KAL_FALSE;
#endif // #if defined(PMIC6326_RACE_CONDITION_CHECK)


#if defined(PMIC6326_MASKIRQ_WHEN_PERFORM)
static volatile kal_bool gPMIC6326IRQMasked = KAL_FALSE;
static volatile kal_uint32 gsavedMask;
#endif // #if defined(PMIC6326_MASKIRQ_WHEN_PERFORM)


/*
pmic_adpt_chr_curr_table pmic6326_chr_current_table =
{
	8,
	{
		{ 50, 0},
		{ 90, 1},
		{150, 2},
		{225, 3},
		{300, 4},
		{450, 5},
		{650, 6},
		{800, 7},
		{  0, 0},
		{  0, 0},
		{  0, 0},
		{  0, 0},
		{  0, 0},
		{  0, 0},
		{  0, 0},
		{  0, 0}
	}
};

pmic_adpt_chr_curr_table *pmic6326_get_chr_curr_table(void)
{
	return &pmic6326_chr_current_table;
}


pmic_adpt_chr_curr_offset_table pmic6326_chr_curr_offset_table =
{
	5,
	{
		{-2, 6},
		{-1, 7},
		{ 0, 0},
		{ 1, 1},
		{ 2, 2},
		{ 0, 0},
		{ 0, 0},
		{ 0, 0}
	}

};

pmic_adpt_chr_curr_offset_table *pmic6326_get_chr_curr_offset_table(void)
{
	return &pmic6326_chr_curr_offset_table;
}

*/


kal_uint8 pmic6326_eco_version = 0;

// BL, Flash, OTG LDOs need higher voltage output, we also need to enable vboost1 when enabling the 3 LDOs
#define VBOOST1_SET_FLAG_BL   0x01  // Bit00
#define VBOOST1_SET_FLAG_FLASH  0x02  // Bit01
#define VBOOST1_SET_FLAG_OTG   0x04  // Bit02
#define VBOOST1_SET_FLAG_BOOST1  0x08  // Bit03
kal_uint8 pmic6326_vboost1_set_flag = 0;
// Internal usage only, called insided PMIC6326 driver
// Do NOT need protection check, because it is called inside PMIC API
#define dcl_pmic6326_boost1_enable_internal(flag)  {\
 kal_uint8 enable;\
 enable = (flag == 0)?0:1;\
 pmic6326_reg[0x5D] &= ~(BOOST1_EN_MASK << BOOST1_EN_SHIFT);\
 pmic6326_reg[0x5D] |= (enable << BOOST1_EN_SHIFT);\
 pmic6326_reg_write(0x5D, pmic6326_reg[0x5D]);\
}

// FLASH, Keypad LED, Vibrator LDOs need to control DIM, so we need to turn on 0x72 when any of them are turned on
#define DIM_CK_ON_FLAG_CK    0x01  // Bit00
#define DIM_CK_ON_FLAG_FLASH   0x02  // Bit01
#define DIM_CK_ON_FLAG_KEY    0x04  // Bit02
#define DIM_CK_ON_FLAG_VIB    0x08  // Bit03
// Internal usage only, called insided PMIC6326 driver
// Do NOT need protection check, because it is called inside PMIC API
kal_uint8 pmic6326_dim_ck_set_flag = 0;
#define dcl_pmic6326_dim_ck_force_on_internal(flag)  {\
 kal_uint8 enable;\
 enable = (flag == 0)?0:1;\
 pmic6326_reg[0x72] &= ~(DIM_CK_FORCE_ON_MASK << DIM_CK_FORCE_ON_SHIFT);\
 pmic6326_reg[0x72] |= (enable << DIM_CK_FORCE_ON_SHIFT);\
 pmic6326_reg_write(0x72, pmic6326_reg[0x72]);\
}

#ifdef PMIC_INTERNAL_SRAM
#pragma arm section rwdata, rodata , zidata
#endif // #ifdef PMIC_INTERNAL_SRAM

#if defined(ENABLE_PMIC_DRIVER_KICK_CHARGER_WATCHDOG_TIMER)
#define KICK_PMIC6326_WDT_PERIOD    200 // in (10ms) unit, 200 means 2 sec
kal_uint8 pmic6326_wdt_handle;
void pmic6326_kick_charger_wdt(void *parameter);
#endif // #if defined(ENABLE_PMIC_DRIVER_KICK_CHARGER_WATCHDOG_TIMER)


#if defined(PMIC6326_RACE_CONDITION_CHECK)
#define LOCK_PMIC6326_CHECK {\
 kal_uint32 savedMask = 0;\
 if ( (!kal_if_hisr()) && (!kal_if_lisr()) ){\
  savedMask = SaveAndSetIRQMask();\
 }\
 if (gPerformPMIC6326Func == KAL_TRUE){\
  ASSERT(0);\
 }\
 gPerformPMIC6326Func = KAL_TRUE;\
 if ( (!kal_if_hisr()) && (!kal_if_lisr()) ){\
  RestoreIRQMask(savedMask);\
 }\
}

#define RELEASE_PMIC6326_CHECK {\
 kal_uint32 savedMask = 0;\
 if ( (!kal_if_hisr()) && (!kal_if_lisr()) ){\
  savedMask = SaveAndSetIRQMask();\
 }\
 gPerformPMIC6326Func = KAL_FALSE;\
 if ( (!kal_if_hisr()) && (!kal_if_lisr()) ){\
  RestoreIRQMask(savedMask);\
 }\
}
#elif defined(PMIC6326_MASKIRQ_WHEN_PERFORM)// #if defined(PMIC6326_RACE_CONDITION_CHECK)
#define LOCK_PMIC6326_CHECK  {\
 if (CheckIRQLock()){\
  ;\
 }else{\
  if (!kal_query_systemInit()){\
   gsavedMask = SaveAndSetIRQMask();\
   gPMIC6326IRQMasked = KAL_TRUE;\
  }\
 }\
}

#define RELEASE_PMIC6326_CHECK {\
 if (gPMIC6326IRQMasked == KAL_TRUE){\
  gPMIC6326IRQMasked = KAL_FALSE;\
  RestoreIRQMask(gsavedMask);\
 }\
}

#else // #if defined(PMIC6326_RACE_CONDITION_CHECK)
#define LOCK_PMIC6326_CHECK  ;
#define RELEASE_PMIC6326_CHECK ;
#endif // #if defined(PMIC6326_RACE_CONDITION_CHECK)


#if defined(ENABLE_PMIC_DRIVER_KICK_CHARGER_WATCHDOG_TIMER)
void pmic6326_kick_charger_wdt(void *parameter){
    pmic_watchdog_clear();
}
void dcl_pmic6326_kick_wdt(kal_bool enable){
    // current_state is used prevent that first entry is enable = KAL_FALSE, which will cause GPT release a un-init handle
    static kal_bool current_state = KAL_FALSE;
    if (!kal_query_systemInit()){
        if (current_state != enable){
            if (enable){
                GPTI_GetHandle(&pmic6326_wdt_handle);
                GPTI_StartItem(pmic6326_wdt_handle,
                               KICK_PMIC6326_WDT_PERIOD,
                               pmic6326_kick_charger_wdt,
                               NULL);
            }else{
                GPTI_StopItem(pmic6326_wdt_handle);
                GPTI_ReleaseHandle(&pmic6326_wdt_handle);
            }
            current_state = enable;
        }
    }
}
#endif // #if defined(ENABLE_PMIC_DRIVER_KICK_CHARGER_WATCHDOG_TIMER)



void dcl_pmic6326_dim_ck_force_on(kal_bool enable)
{
    kal_uint8 val ;

    val = (kal_uint8)enable;
    ASSERT(val <= 1);

    LOCK_PMIC6326_CHECK;

    if (val == 1){
        pmic6326_dim_ck_set_flag |= DIM_CK_ON_FLAG_CK;
    }else{
        pmic6326_dim_ck_set_flag &= ~DIM_CK_ON_FLAG_CK;
    }
    dcl_pmic6326_dim_ck_force_on_internal(pmic6326_dim_ck_set_flag);

    RELEASE_PMIC6326_CHECK
}



//static kal_bool pmic6236_boot_check_charge_source = KAL_TRUE;
void dcl_pmic6326_HISR(void){
    kal_uint8 stat1, stat2, stat3, stat4;

    stat1 = dcl_pmic6326_int_status_1();
    stat2 = dcl_pmic6326_int_status_2();
    stat3 = dcl_pmic6326_int_status_3();
    stat4 = dcl_pmic6326_int_status_4();

    kal_prompt_trace(MOD_BMT, "PMIC6326 intr: %x, %x, %x, %x", stat1, stat2, stat3, stat4);

    // Just call ac_det(), no matter there is real CHR intr or NOT
    // 1. At boot time (Device is reset while cable is inserted, PMIC 6326 won't assert INTR at next reset)
    //    ==> EINT will be UnMask immediately, has no effect at boot time
    // 2. If current state of chr is same as read back stat, "CHRDet status is same as chr_usb_state" is shown to catcher
    //    ==> EINT will be UnMask immediately
    // 3. If other PMIC events (Ex: OC) occurs, "CHRDet status is same as chr_usb_state" is shown to catcher
    //    ==> EINT will be UnMask immediately
    // 4. If there is CHR events, corresponding Tasks, HISRs will take over the charger detection process
    //    ==> Normal path, the EINT will be UnMask after charger detection process is done

    // ==> We force to call ac_det in order to make EINT to be UnMask again
    PMIC_CHRDET.pmic_ac_det();

// // show intr state via catcher of each int status
// if (stat3 & (kal_uint8)CHRDET_INT_STAT)
// {
//  kal_prompt_trace(MOD_BMT,"CHRDet");
//  PMIC_CHRDET.pmic_ac_det();
//  perform_ac_det = TRUE;
// }
// else
// {
//  // When Device idle -> Insert cable -> USB/Charger in -> Reboot device -> PMIC 6326 won't assert INTR
//  // Need to refer boot check flag to indicate the INTR service is taken in last boot
//  if (pmic6236_boot_check_charge_source == KAL_TRUE)
//  {
//   if (pmic_chrdet_status())
//   {
//    kal_prompt_trace(MOD_BMT,"CHRDet(Boot check)");
//    PMIC_CHRDET.pmic_ac_det();
//   }
//  }
// }
// pmic6236_boot_check_charge_source = KAL_FALSE;
}

void dcl_pmic6326_ChrDet_Registration(chr_callback_type type, void (*Callback)(void))
{
    if (type == AC_CHR_CALLBACK)
    {
        PMIC_CHRDET.pmic_ac_det = Callback;
    }
    else if (type == USB_CHR_CALLBACK)
    {
        PMIC_CHRDET.pmic_usb_det = Callback;
    }
    else{
        ASSERT(0);
    }
}


// (0x09) STATUS 6 (RO)
kal_bool dcl_pmic6326_boost2_oc_status(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x09, &pmic6326_reg[0x09]);//pmic6326_reg[0x09] = pmic6326_reg_read(0x09);
    if (pmic6326_reg[0x09] & (BOOST2_OC_STATUS_MASK << BOOST2_OC_STATUS_SHIFT)){
        RELEASE_PMIC6326_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6326_CHECK;
        return KAL_FALSE;
    }
}

kal_bool dcl_pmic6326_spkr_oc_det_status(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x09, &pmic6326_reg[0x09]);//pmic6326_reg[0x09] = pmic6326_reg_read(0x09);
    if (pmic6326_reg[0x09] & (SPKR_OC_DET_MASK << SPKR_OC_DET_SHIFT)){
        RELEASE_PMIC6326_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6326_CHECK;
        return KAL_FALSE;
    }
}

kal_bool dcl_pmic6326_spkl_oc_det_status(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x09, &pmic6326_reg[0x09]);//pmic6326_reg[0x09] = pmic6326_reg_read(0x09);
    if (pmic6326_reg[0x09] & (SPKL_OC_DET_MASK << SPKL_OC_DET_SHIFT)){
        RELEASE_PMIC6326_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6326_CHECK;
        return KAL_FALSE;
    }
}

kal_bool dcl_pmic6326_pwrkey_deb_status(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x09, &pmic6326_reg[0x09]);//pmic6326_reg[0x09] = pmic6326_reg_read(0x09);
    if (pmic6326_reg[0x09] & (PWRKEY_DEB_MASK << PWRKEY_DEB_SHIFT)){
        RELEASE_PMIC6326_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6326_CHECK;
        return KAL_FALSE;
    }
}

kal_bool dcl_pmic6326_ovp_status(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x09, &pmic6326_reg[0x09]);//pmic6326_reg[0x09] = pmic6326_reg_read(0x09);
    if (pmic6326_reg[0x09] & (OVP_MASK << OVP_SHIFT)){
        RELEASE_PMIC6326_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6326_CHECK;
        return KAL_FALSE;
    }
}

kal_bool dcl_pmic6326_chrdet_status(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x09, &pmic6326_reg[0x09]);//pmic6326_reg[0x09] = pmic6326_reg_read(0x09);
    if (pmic6326_reg[0x09] & (CHRDET_MASK << CHRDET_SHIFT)){
        RELEASE_PMIC6326_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6326_CHECK;
        return KAL_FALSE;
    }
}

kal_bool dcl_pmic6326_bat_on_status(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x09, &pmic6326_reg[0x09]);//pmic6326_reg[0x09] = pmic6326_reg_read(0x09);
    if (pmic6326_reg[0x09] & (BAT_ON_MASK << BAT_ON_SHIFT)){
        RELEASE_PMIC6326_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6326_CHECK;
        return KAL_FALSE;
    }
}

kal_bool dcl_pmic6326_cv_status(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x09, &pmic6326_reg[0x09]);//pmic6326_reg[0x09] = pmic6326_reg_read(0x09);
    if (pmic6326_reg[0x09] & (CV_MASK << CV_SHIFT)){
        RELEASE_PMIC6326_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6326_CHECK;
        return KAL_FALSE;
    }
}

// (0x0B) INT STATUS 1 (RO)
kal_uint8 dcl_pmic6326_int_status_1(){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x0B, &pmic6326_reg[0x0B]);
    RELEASE_PMIC6326_CHECK;
    return pmic6326_reg[0x0B];
}

// (0x0C) INT STATUS 2 (RO)
kal_uint8 dcl_pmic6326_int_status_2(){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x0C, &pmic6326_reg[0x0C]);
    RELEASE_PMIC6326_CHECK;
    return pmic6326_reg[0x0C];
}

// (0x0D) INT STATUS 3 (RO)
kal_uint8 dcl_pmic6326_int_status_3(){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x0D, &pmic6326_reg[0x0D]);//pmic6326_reg[0x0D] = pmic6326_reg_read(0x0D);
    RELEASE_PMIC6326_CHECK;
    return pmic6326_reg[0x0D];
}

kal_bool dcl_pmic6326_vsdio_oc_int_status(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x0D, &pmic6326_reg[0x0D]);//pmic6326_reg[0x0D] = pmic6326_reg_read(0x0D);
    if (pmic6326_reg[0x0D] & (VSDIO_OC_FLAG_STATUS_MASK << VSDIO_OC_FLAG_STATUS_SHIFT)){
        RELEASE_PMIC6326_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6326_CHECK;
        return KAL_FALSE;
    }
}

kal_bool dcl_pmic6326_vgp_oc_int_status(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x0D, &pmic6326_reg[0x0D]);//pmic6326_reg[0x0D] = pmic6326_reg_read(0x0D);
    if (pmic6326_reg[0x0D] & (VGP_OC_FLAG_STATUS_MASK << VGP_OC_FLAG_STATUS_SHIFT)){
        RELEASE_PMIC6326_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6326_CHECK;
        return KAL_FALSE;
    }
}

kal_bool dcl_pmic6326_vusb_oc_int_status(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x0D, &pmic6326_reg[0x0D]);//pmic6326_reg[0x0D] = pmic6326_reg_read(0x0D);
    if (pmic6326_reg[0x0D] & (VUSB_OC_FLAG_STATUS_MASK << VUSB_OC_FLAG_STATUS_SHIFT)){
        RELEASE_PMIC6326_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6326_CHECK;
        return KAL_FALSE;
    }
}

kal_bool dcl_pmic6326_ovp_int_status(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x0D, &pmic6326_reg[0x0D]);//pmic6326_reg[0x0D] = pmic6326_reg_read(0x0D);
    if (pmic6326_reg[0x0D] & (OVP_INT_FLAG_STATUS_MASK << OVP_INT_FLAG_STATUS_SHIFT)){
        RELEASE_PMIC6326_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6326_CHECK;
        return KAL_FALSE;
    }
}

kal_bool dcl_pmic6326_chrdet_int_status(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x0D, &pmic6326_reg[0x0D]);//pmic6326_reg[0x0D] = pmic6326_reg_read(0x0D);
    if (pmic6326_reg[0x0D] & (CHRDET_INT_FLAG_STATUS_MASK << CHRDET_INT_FLAG_STATUS_SHIFT)){
        RELEASE_PMIC6326_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6326_CHECK;
        return KAL_FALSE;
    }
}

// (0x0E) INT STATUS 4 (RO)
kal_uint8 dcl_pmic6326_int_status_4(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x0E, &pmic6326_reg[0x0E]);//pmic6326_reg[0x0E] = pmic6326_reg_read(0x0E);
    RELEASE_PMIC6326_CHECK;
    return pmic6326_reg[0x0E];
}

kal_bool dcl_pmic6326_watchdog_int_status(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(0x0E, &pmic6326_reg[0x0E]);//pmic6326_reg[0x0E] = pmic6326_reg_read(0x0E);
    if (pmic6326_reg[0x0E] & (WATCHDOG_INT_FLAG_STATUS_MASK << WATCHDOG_INT_FLAG_STATUS_SHIFT)){
        RELEASE_PMIC6326_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6326_CHECK;
        return KAL_FALSE;
    }
}

// Write watchdog bit to clear watch dog timer
void dcl_pmic6326_watchdog_clear(void){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_write(0x0E, (WATCHDOG_INT_FLAG_STATUS_MASK << WATCHDOG_INT_FLAG_STATUS_SHIFT));
    RELEASE_PMIC6326_CHECK;
}


// (0x1B) LDO CTRL 2 VRF
void dcl_pmic6326_vrf_ical_en(vrf_ical_en_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1B] &= ~(VRF_ICAL_EN_MASK << VRF_ICAL_EN_SHIFT);
    pmic6326_reg[0x1B] |= ((kal_uint8)sel << VRF_ICAL_EN_SHIFT);

    pmic6326_reg_write(0x1B, pmic6326_reg[0x1B]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vrf_oc_auto_off(kal_bool auto_off){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1B] &= ~(VRF_OC_AUTO_OFF_MASK << VRF_OC_AUTO_OFF_SHIFT);
    pmic6326_reg[0x1B] |= ((kal_uint8)auto_off << VRF_OC_AUTO_OFF_SHIFT);

    pmic6326_reg_write(0x1B, pmic6326_reg[0x1B]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vrf_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1B] &= ~(VRF_EN_MASK << VRF_EN_SHIFT);
    pmic6326_reg[0x1B] |= ((kal_uint8)enable << VRF_EN_SHIFT);

    pmic6326_reg_write(0x1B, pmic6326_reg[0x1B]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vrf_cal(kal_uint8 val){
    ASSERT(val <= 15);  // val is 0000 ~ 1111

    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1B] &= ~(VRF_CAL_MASK << VRF_CAL_SHIFT);
    pmic6326_reg[0x1B] |= (val << VRF_CAL_SHIFT);

    pmic6326_reg_write(0x1B, pmic6326_reg[0x1B]);
    RELEASE_PMIC6326_CHECK;
}

// (0x1C) LDO CTRL 3 VRF
void dcl_pmic6326_vrf_calst(vrf_calst_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1C] &= ~(VRF_CALST_MASK << VRF_CALST_SHIFT);
    pmic6326_reg[0x1C] |= ((kal_uint8)sel << VRF_CALST_SHIFT);

    pmic6326_reg_write(0x1C, pmic6326_reg[0x1C]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vrf_caloc(vrf_caloc_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1C] &= ~(VRF_CALOC_MASK << VRF_CALOC_SHIFT);
    pmic6326_reg[0x1C] |= ((kal_uint8)sel << VRF_CALOC_SHIFT);

    pmic6326_reg_write(0x1C, pmic6326_reg[0x1C]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vrf_on_sel(vrf_on_sel_enum sel){
    kal_uint8 val;

    val = (kal_uint8)sel;
    ASSERT(val <= 1);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x1C] &= ~(VRF_ON_SEL_MASK << VRF_ON_SEL_SHIFT);
    pmic6326_reg[0x1C] |= (val << VRF_ON_SEL_SHIFT);

    pmic6326_reg_write(0x1C, pmic6326_reg[0x1C]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vrf_en_force(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1C] &= ~(VRF_EN_FORCE_MASK << VRF_EN_FORCE_SHIFT);
    pmic6326_reg[0x1C] |= ((kal_uint8)enable << VRF_EN_FORCE_SHIFT);

    pmic6326_reg_write(0x1C, pmic6326_reg[0x1C]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vrf_plnmos_dis(kal_bool disable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1C] &= ~(VRF_PLNMOS_DIS_MASK << VRF_PLNMOS_DIS_SHIFT);
    pmic6326_reg[0x1C] |= ((kal_uint8)disable << VRF_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(0x1C, pmic6326_reg[0x1C]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vrf_cm(vrf_cm_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1C] &= ~(VRF_CM_MASK << VRF_CM_SHIFT);
    pmic6326_reg[0x1C] |= ((kal_uint8)sel << VRF_CM_SHIFT);

    pmic6326_reg_write(0x1C, pmic6326_reg[0x1C]);
    RELEASE_PMIC6326_CHECK;
}

// (0x1E) LDO CTRL 5 VTCXO
void dcl_pmic6326_vtcxo_ical_en(vtcxo_ical_en_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1E] &= ~(VTCXO_ICAL_EN_MASK << VTCXO_ICAL_EN_SHIFT);
    pmic6326_reg[0x1E] |= ((kal_uint8)sel << VTCXO_ICAL_EN_SHIFT);

    pmic6326_reg_write(0x1E, pmic6326_reg[0x1E]);
    RELEASE_PMIC6326_CHECK;
}
void dcl_pmic6326_vtcxo_oc_auto_off(kal_bool auto_off){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1E] &= ~(VTCXO_OC_AUTO_OFF_MASK << VTCXO_OC_AUTO_OFF_SHIFT);
    pmic6326_reg[0x1E] |= ((kal_uint8)auto_off << VTCXO_OC_AUTO_OFF_SHIFT);

    pmic6326_reg_write(0x1E, pmic6326_reg[0x1E]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vtcxo_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1E] &= ~(VTCXO_EN_MASK << VTCXO_EN_SHIFT);
    pmic6326_reg[0x1E] |= (enable << VTCXO_EN_SHIFT);

    pmic6326_reg_write(0x1E, pmic6326_reg[0x1E]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vtcxo_cal(kal_uint8 val){

    ASSERT(val <= 15);  // val is 0000 ~ 1111

    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1E] &= ~(VTCXO_CAL_MASK << VTCXO_CAL_SHIFT);
    pmic6326_reg[0x1E] |= (val << VTCXO_CAL_SHIFT);

    pmic6326_reg_write(0x1E, pmic6326_reg[0x1E]);
    RELEASE_PMIC6326_CHECK;
}

// (0x1F) LDO CTRL 6 VTCXO
void dcl_pmic6326_vtcxo_calst(vtcxo_calst_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1F] &= ~(VTCXO_CALST_MASK << VTCXO_CALST_SHIFT);
    pmic6326_reg[0x1F] |= ((kal_uint8)sel << VTCXO_CALST_SHIFT);

    pmic6326_reg_write(0x1F, pmic6326_reg[0x1F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vtcxo_caloc(vtcxo_caloc_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1F] &= ~(VTCXO_CALOC_MASK << VTCXO_CALOC_SHIFT);
    pmic6326_reg[0x1F] |= ((kal_uint8)sel << VTCXO_CALOC_SHIFT);

    pmic6326_reg_write(0x1F, pmic6326_reg[0x1F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vtcxo_on_sel(vtcxo_on_sel_enum sel){
    kal_uint8 val;

    val = (kal_uint8)sel;
    ASSERT(val <= 1);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x1F] &= ~(VTCXO_ON_SEL_MASK << VTCXO_ON_SEL_SHIFT);
    pmic6326_reg[0x1F] |= (val << VTCXO_ON_SEL_SHIFT);

    pmic6326_reg_write(0x1F, pmic6326_reg[0x1F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vtcxo_en_force(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1F] &= ~(VTCXO_EN_FORCE_MASK << VTCXO_EN_FORCE_SHIFT);
    pmic6326_reg[0x1F] |= ((kal_uint8)enable << VTCXO_EN_FORCE_SHIFT);

    pmic6326_reg_write(0x1F, pmic6326_reg[0x1F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vtcxo_plnmos_dis(kal_bool disable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1F] &= ~(VTCXO_PLNMOS_DIS_MASK << VTCXO_PLNMOS_DIS_SHIFT);
    pmic6326_reg[0x1F] |= ((kal_uint8)disable << VTCXO_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(0x1F, pmic6326_reg[0x1F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vtcxo_cm(vtcxo_cm_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1F] &= ~(VTCXO_CM_MASK << VTCXO_CM_SHIFT);
    pmic6326_reg[0x1F] |= ((kal_uint8)sel << VTCXO_CM_SHIFT);

    pmic6326_reg_write(0x1F, pmic6326_reg[0x1F]);
    RELEASE_PMIC6326_CHECK;
}


// (0x21) LDO CTRL 8 V3GTX
void dcl_pmic6326_v3gtx_sel(v3gtx_vol vol){
    kal_uint8 val;

    val = (kal_uint8) vol;
    ASSERT(val <= 3);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x21] &= ~(V3GTX_SEL_MASK << V3GTX_SEL_SHIFT);
    pmic6326_reg[0x21] |= (val << V3GTX_SEL_SHIFT);

    //pmic6326_reg_write(0x21, pmic6326_reg[0x21]);
    pmic6326_ch2_reg_write(0x21, pmic6326_reg[0x21]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_v3gtx_ical_en(v3gtx_ical_en_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x21] &= ~(V3GTX_ICAL_EN_MASK << V3GTX_ICAL_EN_SHIFT);
    pmic6326_reg[0x21] |= ((kal_uint8)sel << V3GTX_ICAL_EN_SHIFT);

    //pmic6326_reg_write(0x21, pmic6326_reg[0x21]);
    pmic6326_ch2_reg_write(0x21, pmic6326_reg[0x21]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_v3gtx_cal(kal_uint8 val){

    ASSERT(val <= 15);  // val is 0000 ~ 1111

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x21] &= ~(V3GTX_CAL_MASK << V3GTX_CAL_SHIFT);
    pmic6326_reg[0x21] |= (val << V3GTX_CAL_SHIFT);

    //pmic6326_reg_write(0x21, pmic6326_reg[0x21]);
    pmic6326_ch2_reg_write(0x21, pmic6326_reg[0x21]);
    RELEASE_PMIC6326_CHECK;
}

// (0x22) LDO CTRL 9 V3GTX
void dcl_pmic6326_v3gtx_calst(v3gtx_calst_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x22] &= ~(V3GTX_CALST_MASK << V3GTX_CALST_SHIFT);
    pmic6326_reg[0x22] |= ((kal_uint8)sel << V3GTX_CALST_SHIFT);

    //pmic6326_reg_write(0x22, pmic6326_reg[0x22]);
    pmic6326_ch2_reg_write(0x22, pmic6326_reg[0x22]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_v3gtx_caloc(v3gtx_caloc_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x22] &= ~(V3GTX_CALOC_MASK << V3GTX_CALOC_SHIFT);
    pmic6326_reg[0x22] |= ((kal_uint8)sel << V3GTX_CALOC_SHIFT);

    //pmic6326_reg_write(0x22, pmic6326_reg[0x22]);
    pmic6326_ch2_reg_write(0x22, pmic6326_reg[0x22]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_v3gtx_oc_auto_off(kal_bool auto_off){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x22] &= ~(V3GTX_OC_AUTO_OFF_MASK << V3GTX_OC_AUTO_OFF_SHIFT);
    pmic6326_reg[0x22] |= ((kal_uint8)auto_off << V3GTX_OC_AUTO_OFF_SHIFT);

    //pmic6326_reg_write(0x22, pmic6326_reg[0x22]);
    pmic6326_ch2_reg_write(0x22, pmic6326_reg[0x22]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_v3gtx_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x22] &= ~(V3GTX_EN_MASK << V3GTX_EN_SHIFT);
    pmic6326_reg[0x22] |= (enable << V3GTX_EN_SHIFT);

    //pmic6326_reg_write(0x22, pmic6326_reg[0x22]);
    pmic6326_ch2_reg_write(0x22, pmic6326_reg[0x22]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_v3gtx_on_sel(v3gtx_on_sel_enum sel){
    kal_uint8 val;

    val = (kal_uint8)sel;
    ASSERT(val <= 1);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x22] &= ~(V3GTX_ON_SEL_MASK << V3GTX_ON_SEL_SHIFT);
    pmic6326_reg[0x22] |= (val << V3GTX_ON_SEL_SHIFT);

    //pmic6326_reg_write(0x22, pmic6326_reg[0x22]);
    pmic6326_ch2_reg_write(0x22, pmic6326_reg[0x22]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_v3gtx_en_force(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x22] &= ~(V3GTX_EN_FORCE_MASK << V3GTX_EN_FORCE_SHIFT);
    pmic6326_reg[0x22] |= ((kal_uint8)enable << V3GTX_EN_FORCE_SHIFT);

    //pmic6326_reg_write(0x22, pmic6326_reg[0x22]);
    pmic6326_ch2_reg_write(0x22, pmic6326_reg[0x22]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_v3gtx_plnmos_dis(kal_bool disable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x23] &= ~(V3GTX_PLNMOS_DIS_MASK << V3GTX_PLNMOS_DIS_SHIFT);
    pmic6326_reg[0x23] |= ((kal_uint8)disable << V3GTX_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(0x23, pmic6326_reg[0x23]);
    RELEASE_PMIC6326_CHECK;
}




// (0x24) LDO CTRL 11 V3GRX
void dcl_pmic6326_v3grx_sel(v3grx_vol vol){
    kal_uint8 val;

    val = (kal_uint8) vol;
    ASSERT(val <= 3);

    LOCK_PMIC6326_CHECK;

    // TODO, val may OR the read back value (Or backup value) of the register
    pmic6326_reg[0x24] &= ~(V3GRX_SEL_MASK << V3GRX_SEL_SHIFT);
    pmic6326_reg[0x24] |= (val << V3GRX_SEL_SHIFT);

    //pmic6326_reg_write(0x24, pmic6326_reg[0x24]);
    pmic6326_ch2_reg_write(0x24, pmic6326_reg[0x24]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_3grx_ical_en(v3grx_ical_en_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x24] &= ~(V3GRX_ICAL_EN_MASK << V3GRX_ICAL_EN_SHIFT);
    pmic6326_reg[0x24] |= ((kal_uint8)sel << V3GRX_ICAL_EN_SHIFT);

    //pmic6326_reg_write(0x24, pmic6326_reg[0x24]);
    pmic6326_ch2_reg_write(0x24, pmic6326_reg[0x24]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_v3grx_cal(kal_uint8 val){

    ASSERT(val <= 15);  // val is 0000 ~ 1111

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x24] &= ~(V3GRX_CAL_MASK << V3GRX_CAL_SHIFT);
    pmic6326_reg[0x24] |= (val << V3GRX_CAL_SHIFT);

    //pmic6326_reg_write(0x24, pmic6326_reg[0x24]);
    pmic6326_ch2_reg_write(0x24, pmic6326_reg[0x24]);
    RELEASE_PMIC6326_CHECK;
}

// (0x25) LDO CTRL 12 V3GRX
void dcl_pmic6326_v3grx_calst(v3grx_calst_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x25] &= ~(V3GRX_CALST_MASK << V3GRX_CALST_SHIFT);
    pmic6326_reg[0x25] |= ((kal_uint8)sel << V3GRX_CALST_SHIFT);

    //pmic6326_reg_write(0x25, pmic6326_reg[0x25]);
    pmic6326_ch2_reg_write(0x25, pmic6326_reg[0x25]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_v3grx_caloc(v3grx_caloc_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x25] &= ~(V3GRX_CALOC_MASK << V3GRX_CALOC_SHIFT);
    pmic6326_reg[0x25] |= ((kal_uint8)sel << V3GRX_CALOC_SHIFT);

    //pmic6326_reg_write(0x25, pmic6326_reg[0x25]);
    pmic6326_ch2_reg_write(0x25, pmic6326_reg[0x25]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_v3grx_oc_auto_off(kal_bool auto_off){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x25] &= ~(V3GRX_OC_AUTO_OFF_MASK << V3GRX_OC_AUTO_OFF_SHIFT);
    pmic6326_reg[0x25] |= ((kal_uint8)auto_off << V3GRX_OC_AUTO_OFF_SHIFT);

    //pmic6326_reg_write(0x25, pmic6326_reg[0x25]);
    pmic6326_ch2_reg_write(0x25, pmic6326_reg[0x25]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_v3grx_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x25] &= ~(V3GRX_EN_MASK << V3GRX_EN_SHIFT);
    pmic6326_reg[0x25] |= (enable << V3GRX_EN_SHIFT);

    //pmic6326_reg_write(0x25, pmic6326_reg[0x25]);
    pmic6326_ch2_reg_write(0x25, pmic6326_reg[0x25]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_v3grx_on_sel(v3grx_on_sel_enum sel){
    kal_uint8 val;

    val = (kal_uint8)sel;
    ASSERT(val <= 1);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x25] &= ~(V3GRX_ON_SEL_MASK << V3GRX_ON_SEL_SHIFT);
    pmic6326_reg[0x25] |= (val << V3GRX_ON_SEL_SHIFT);

    //pmic6326_reg_write(0x25, pmic6326_reg[0x25]);
    pmic6326_ch2_reg_write(0x25, pmic6326_reg[0x25]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_v3grx_en_force(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x25] &= ~(V3GRX_EN_FORCE_MASK << V3GRX_EN_FORCE_SHIFT);
    pmic6326_reg[0x25] |= ((kal_uint8)enable << V3GRX_EN_FORCE_SHIFT);

    //pmic6326_reg_write(0x25, pmic6326_reg[0x25]);
    pmic6326_ch2_reg_write(0x25, pmic6326_reg[0x25]);
    RELEASE_PMIC6326_CHECK;
}

// (0x26) LDO CTRL 13 V3GRX
void dcl_pmic6326_v3grx_plnmos_dis(kal_bool disable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x26] &= ~(V3GRX_PLNMOS_DIS_MASK << V3GRX_PLNMOS_DIS_SHIFT);
    pmic6326_reg[0x26] |= ((kal_uint8)disable << V3GRX_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(0x26, pmic6326_reg[0x26]);
    RELEASE_PMIC6326_CHECK;
}

// (0x2E) LDO CTRL 21 VCAMA
void dcl_pmic6326_vcama_sel(vcama_sel_enum sel){
    kal_uint8 val;

    val = (kal_uint8)sel;
    ASSERT(val <= 3);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x2E] &= ~(VCAMA_SEL_MASK << VCAMA_SEL_SHIFT);
    pmic6326_reg[0x2E] |= (val << VCAMA_SEL_SHIFT);

    pmic6326_reg_write(0x2E, pmic6326_reg[0x2E]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcama_ical_en(vcama_ical_en_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x2E] &= ~(VCAMA_ICAL_EN_MASK << VCAMA_ICAL_EN_SHIFT);
    pmic6326_reg[0x2E] |= (sel << VCAMA_ICAL_EN_SHIFT);

    pmic6326_reg_write(0x2E, pmic6326_reg[0x2E]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcama_cal(kal_uint8 val){

    ASSERT(val <= 15);  // val is 0000 ~ 1111

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x2E] &= ~(VCAMA_CAL_MASK << VCAMA_CAL_SHIFT);
    pmic6326_reg[0x2E] |= (val << VCAMA_CAL_SHIFT);

    pmic6326_reg_write(0x2E, pmic6326_reg[0x2E]);
    RELEASE_PMIC6326_CHECK;
}

// (0x2F) LDO CTRL 22 VCAMA
void dcl_pmic6326_vcama_calst(vcama_calst_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x2F] &= ~(VCAMA_CALST_MASK << VCAMA_CALST_SHIFT);
    pmic6326_reg[0x2F] |= ((kal_uint8)sel << VCAMA_CALST_SHIFT);

    pmic6326_reg_write(0x2F, pmic6326_reg[0x2F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcama_caloc(vcama_caloc_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x2F] &= ~(VCAMA_CALOC_MASK << VCAMA_CALOC_SHIFT);
    pmic6326_reg[0x2F] |= ((kal_uint8)sel << VCAMA_CALOC_SHIFT);

    pmic6326_reg_write(0x2F, pmic6326_reg[0x2F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcama_oc_auto_off(kal_bool auto_off){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x8C] &= ~(VCAMA_OC_AUTO_OFF_MASK << VCAMA_OC_AUTO_OFF_SHIFT);
    pmic6326_reg[0x8C] |= ((kal_uint8)auto_off << VCAMA_OC_AUTO_OFF_SHIFT);

    pmic6326_ch2_reg_write(0x8C, pmic6326_reg[0x8C]);
    RELEASE_PMIC6326_CHECK;
}


void dcl_pmic6326_vcama_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x2F] &= ~(VCAMA_EN_MASK << VCAMA_EN_SHIFT);
    pmic6326_reg[0x2F] |= ((kal_uint8)enable << VCAMA_EN_SHIFT);

    pmic6326_reg_write(0x2F, pmic6326_reg[0x2F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcama_en_force(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x2F] &= ~(VCAMA_EN_FORCE_MASK << VCAMA_EN_FORCE_SHIFT);
    pmic6326_reg[0x2F] |= ((kal_uint8)enable << VCAMA_EN_FORCE_SHIFT);

    pmic6326_reg_write(0x2F, pmic6326_reg[0x2F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcama_plnmos_dis(kal_bool disable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x2F] &= ~(VCAMA_PLNMOS_DIS_MASK << VCAMA_PLNMOS_DIS_SHIFT);
    pmic6326_reg[0x2F] |= ((kal_uint8)disable << VCAMA_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(0x2F, pmic6326_reg[0x2F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcama_cm(vcama_cm_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x2F] &= ~(VCAMA_CM_MASK << VCAMA_CM_SHIFT);
    pmic6326_reg[0x2F] |= ((kal_uint8)sel << VCAMA_CM_SHIFT);

    pmic6326_reg_write(0x2F, pmic6326_reg[0x2F]);
    RELEASE_PMIC6326_CHECK;
}

// (0x31) LDO CTRL 24 VWIFI3V3
void dcl_pmic6326_vwifi3v3_sel(vwifi3v3_sel_enum sel){
    kal_uint8 val;

    val = (kal_uint8)sel;
    ASSERT(val <= 3);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x31] &= ~(VWIFI3V3_SEL_MASK << VWIFI3V3_SEL_SHIFT);
    pmic6326_reg[0x31] |= (val << VWIFI3V3_SEL_SHIFT);

    pmic6326_reg_write(0x31, pmic6326_reg[0x31]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vwifi3v3_ical_en(vwifi3v3_ical_en_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x31] &= ~(VWIFI3V3_ICAL_EN_MASK << VWIFI3V3_ICAL_EN_SHIFT);
    pmic6326_reg[0x31] |= (sel << VWIFI3V3_ICAL_EN_SHIFT);

    pmic6326_reg_write(0x31, pmic6326_reg[0x31]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vwifi3v3_cal(kal_uint8 val){

    ASSERT(val <= 15);  // val is 0000 ~ 1111

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x31] &= ~(VWIFI3V3_CAL_MASK << VWIFI3V3_CAL_SHIFT);
    pmic6326_reg[0x31] |= (val << VWIFI3V3_CAL_SHIFT);

    pmic6326_reg_write(0x31, pmic6326_reg[0x31]);
    RELEASE_PMIC6326_CHECK;
}

// (0x32) LDO CTRL 25 VWIFI3V3
void dcl_pmic6326_vwifi3v3_calst(vwifi3v3_calst_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x32] &= ~(VWIFI3V3_CALST_MASK << VWIFI3V3_CALST_SHIFT);
    pmic6326_reg[0x32] |= ((kal_uint8)sel << VWIFI3V3_CALST_SHIFT);

    pmic6326_reg_write(0x32, pmic6326_reg[0x32]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vwifi3v3_caloc(vwifi3v3_caloc_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x32] &= ~(VWIFI3V3_CALOC_MASK << VWIFI3V3_CALOC_SHIFT);
    pmic6326_reg[0x32] |= ((kal_uint8)sel << VWIFI3V3_CALOC_SHIFT);

    pmic6326_reg_write(0x32, pmic6326_reg[0x32]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vwifi3v3_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x32] &= ~(VWIFI3V3_EN_MASK << VWIFI3V3_EN_SHIFT);
    pmic6326_reg[0x32] |= ((kal_uint8)enable << VWIFI3V3_EN_SHIFT);

    pmic6326_reg_write(0x32, pmic6326_reg[0x32]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vwifi3v3_en_force(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x32] &= ~(VWIFI3V3_EN_FORCE_MASK << VWIFI3V3_EN_FORCE_SHIFT);
    pmic6326_reg[0x32] |= ((kal_uint8)enable << VWIFI3V3_EN_FORCE_SHIFT);

    pmic6326_reg_write(0x32, pmic6326_reg[0x32]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vwifi3v3_plnmos_dis(kal_bool disable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x32] &= ~(VWIFI3V3_PLNMOS_DIS_MASK << VWIFI3V3_PLNMOS_DIS_SHIFT);
    pmic6326_reg[0x32] |= ((kal_uint8)disable << VWIFI3V3_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(0x32, pmic6326_reg[0x32]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vwifi3v3_cm(vwifi3v3_cm_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x32] &= ~(VWIFI3V3_CM_MASK << VWIFI3V3_CM_SHIFT);
    pmic6326_reg[0x32] |= ((kal_uint8)sel << VWIFI3V3_CM_SHIFT);

    pmic6326_reg_write(0x32, pmic6326_reg[0x32]);
    RELEASE_PMIC6326_CHECK;
}

// (0x34) LDO CTRL 27 VWIFI2V8
void dcl_pmic6326_vwifi2v8_sel(vwifi2v8_sel_enum sel){
    kal_uint8 val;

    val = (kal_uint8)sel;
    ASSERT(val <= 3);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x34] &= ~(VWIFI2V8_SEL_MASK << VWIFI2V8_SEL_SHIFT);
    pmic6326_reg[0x34] |= (val << VWIFI2V8_SEL_SHIFT);

    pmic6326_reg_write(0x34, pmic6326_reg[0x34]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vwifi2v8_ical_en(vwifi2v8_ical_en_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x34] &= ~(VWIFI2V8_ICAL_EN_MASK << VWIFI2V8_ICAL_EN_SHIFT);
    pmic6326_reg[0x34] |= (sel << VWIFI2V8_ICAL_EN_SHIFT);

    pmic6326_reg_write(0x34, pmic6326_reg[0x34]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vwifi2v8_cal(kal_uint8 val){

    ASSERT(val <= 15);  // val is 0000 ~ 1111

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x34] &= ~(VWIFI2V8_CAL_MASK << VWIFI2V8_CAL_SHIFT);
    pmic6326_reg[0x34] |= (val << VWIFI2V8_CAL_SHIFT);

    pmic6326_reg_write(0x34, pmic6326_reg[0x34]);
    RELEASE_PMIC6326_CHECK;
}

// (0x35) LDO CTRL 28 VWIFI2V8
void dcl_pmic6326_vwifi2v8_calst(vwifi2v8_calst_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x35] &= ~(VWIFI2V8_CALST_MASK << VWIFI2V8_CALST_SHIFT);
    pmic6326_reg[0x35] |= ((kal_uint8)sel << VWIFI2V8_CALST_SHIFT);

    pmic6326_reg_write(0x35, pmic6326_reg[0x35]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vwifi2v8_caloc(vwifi2v8_caloc_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x35] &= ~(VWIFI2V8_CALOC_MASK << VWIFI2V8_CALOC_SHIFT);
    pmic6326_reg[0x35] |= ((kal_uint8)sel << VWIFI2V8_CALOC_SHIFT);

    pmic6326_reg_write(0x35, pmic6326_reg[0x35]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vwifi2v8_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x35] &= ~(VWIFI2V8_EN_MASK << VWIFI2V8_EN_SHIFT);
    pmic6326_reg[0x35] |= ((kal_uint8)enable << VWIFI2V8_EN_SHIFT);

    pmic6326_reg_write(0x35, pmic6326_reg[0x35]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vwifi2v8_en_force(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x35] &= ~(VWIFI2V8_EN_FORCE_MASK << VWIFI2V8_EN_FORCE_SHIFT);
    pmic6326_reg[0x35] |= ((kal_uint8)enable << VWIFI2V8_EN_FORCE_SHIFT);

    pmic6326_reg_write(0x35, pmic6326_reg[0x35]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vwifi2v8_plnmos_dis(kal_bool disable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x35] &= ~(VWIFI2V8_PLNMOS_DIS_MASK << VWIFI2V8_PLNMOS_DIS_SHIFT);
    pmic6326_reg[0x35] |= ((kal_uint8)disable << VWIFI2V8_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(0x35, pmic6326_reg[0x35]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vwifi2v8_cm(vwifi2v8_cm_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x35] &= ~(VWIFI2V8_CM_MASK << VWIFI2V8_CM_SHIFT);
    pmic6326_reg[0x35] |= ((kal_uint8)sel << VWIFI2V8_CM_SHIFT);

    pmic6326_reg_write(0x35, pmic6326_reg[0x35]);
    RELEASE_PMIC6326_CHECK;
}


// (0x37) LDO CTRL 30 VSIM
//void dcl_pmic6326_vsim_sel(vsim_sel_enum sel){
void dcl_pmic6326_vsim_sel(vsim_sel_enum sel){
    kal_uint8 val;

    val = (kal_uint8)sel;
    ASSERT(val <= 7);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x37] &= ~(VSIM_SEL_MASK << VSIM_SEL_SHIFT);
    pmic6326_reg[0x37] |= (val << VSIM_SEL_SHIFT);

    pmic6326_reg_write(0x37, pmic6326_reg[0x37]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vsim_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x37] &= ~(VSIM_EN_MASK << VSIM_EN_SHIFT);
    pmic6326_reg[0x37] |= (enable << VSIM_EN_SHIFT);

    pmic6326_reg_write(0x37, pmic6326_reg[0x37]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vsim_ical_en(vsim_ical_en_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x37] &= ~(VSIM_ICAL_EN_MASK << VSIM_ICAL_EN_SHIFT);
    pmic6326_reg[0x37] |= (sel << VSIM_ICAL_EN_SHIFT);

    pmic6326_reg_write(0x37, pmic6326_reg[0x37]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vsim_en_force(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x37] &= ~(VSIM_EN_FORCE_MASK << VSIM_EN_FORCE_SHIFT);
    pmic6326_reg[0x37] |= ((kal_uint8)enable << VSIM_EN_FORCE_SHIFT);

    pmic6326_reg_write(0x37, pmic6326_reg[0x37]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vsim_plnmos_dis(kal_bool disable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x37] &= ~(VSIM_PLNMOS_DIS_MASK << VSIM_PLNMOS_DIS_SHIFT);
    pmic6326_reg[0x37] |= ((kal_uint8)disable << VSIM_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(0x37, pmic6326_reg[0x37]);
    RELEASE_PMIC6326_CHECK;
}

// (0x38) LDO CTRL 31 VSIM
void dcl_pmic6326_vsim_cal(kal_uint8 val){
    ASSERT(val <= 15);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x38] &= ~(VSIM_CAL_MASK << VSIM_CAL_SHIFT);
    pmic6326_reg[0x38] |= ((kal_uint8)val << VSIM_CAL_SHIFT);

    pmic6326_reg_write(0x38, pmic6326_reg[0x38]);
    RELEASE_PMIC6326_CHECK;
}

// (0x3A) LDO CTRL 33 VUSB
// USB voltage is NOT opened for change
//void dcl_pmic6326_vusb_sel(vusb_sel_enum sel){
// kal_uint8 val;
// ASSERT(0);
//}

void dcl_pmic6326_vusb_enable(kal_bool enable){
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3D;
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3A;
    }
    LOCK_PMIC6326_CHECK;
    if (enable){
        pmic6326_vboost1_set_flag |= VBOOST1_SET_FLAG_OTG;
    }else{
        pmic6326_vboost1_set_flag &= ~(VBOOST1_SET_FLAG_OTG);
    }
    dcl_pmic6326_boost1_enable_internal(pmic6326_vboost1_set_flag);

    pmic6326_reg[reg_addr] &= ~(VUSB_EN_MASK << VUSB_EN_SHIFT);
    pmic6326_reg[reg_addr] |= (enable << VUSB_EN_SHIFT);

    pmic6326_reg_write(reg_addr, pmic6326_reg[reg_addr]);
    RELEASE_PMIC6326_CHECK;

}

void dcl_pmic6326_vusb_ical_en(vusb_ical_en_enum sel){
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3D;
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3A;
    }
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[reg_addr] &= ~(VUSB_ICAL_EN_MASK << VUSB_ICAL_EN_SHIFT);
    pmic6326_reg[reg_addr] |= (sel << VUSB_ICAL_EN_SHIFT);

    pmic6326_reg_write(reg_addr, pmic6326_reg[reg_addr]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vusb_en_force(kal_bool enable){
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3D;
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3A;
    }
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[reg_addr] &= ~(VUSB_EN_FORCE_MASK << VUSB_EN_FORCE_SHIFT);
    pmic6326_reg[reg_addr] |= ((kal_uint8)enable << VUSB_EN_FORCE_SHIFT);

    pmic6326_reg_write(reg_addr, pmic6326_reg[reg_addr]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vusb_plnmos_dis(kal_bool disable){
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3D;
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3A;
    }
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[reg_addr] &= ~(VUSB_PLNMOS_DIS_MASK << VUSB_PLNMOS_DIS_SHIFT);
    pmic6326_reg[reg_addr] |= ((kal_uint8)disable << VUSB_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(reg_addr, pmic6326_reg[reg_addr]);
    RELEASE_PMIC6326_CHECK;
}

// (0x3B) LDO CTRL 34 VUSB
void dcl_pmic6326_vusb_cal(kal_uint8 val){
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3E;
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3B;
    }
    ASSERT(val <= 15);  // val is 0000 ~ 1111

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[reg_addr] &= ~(VUSB_CAL_MASK << VUSB_CAL_SHIFT);
    pmic6326_reg[reg_addr] |= (val << VUSB_CAL_SHIFT);

    pmic6326_reg_write(reg_addr, pmic6326_reg[reg_addr]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vusb_calst(vusb_calst_enum sel){
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3E;
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3B;
    }
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[reg_addr] &= ~(VUSB_CALST_MASK << VUSB_CALST_SHIFT);
    pmic6326_reg[reg_addr] |= ((kal_uint8)sel << VUSB_CALST_SHIFT);

    pmic6326_reg_write(reg_addr, pmic6326_reg[reg_addr]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vusb_caloc(vusb_caloc_enum sel){
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3E;
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3B;
    }
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[reg_addr] &= ~(VUSB_CALOC_MASK << VUSB_CALOC_SHIFT);
    pmic6326_reg[reg_addr] |= ((kal_uint8)sel << VUSB_CALOC_SHIFT);

    pmic6326_reg_write(reg_addr, pmic6326_reg[reg_addr]);
    RELEASE_PMIC6326_CHECK;
}

// (0x3D) LDO CTRL 36 VBT
void dcl_pmic6326_vbt_sel(vbt_sel_enum sel){
    kal_uint8 val;
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3A;
        // For E3, the voltage changed, we need to re-map VBT voltage selction value of E1, E2 to E3
        if (sel == VBT_1_3) {
            val = (kal_uint8)VBT_E3_1_3;
        }
        else if (sel == VBT_1_5) {
            val = (kal_uint8)VBT_E3_1_5;
        }
        else if (sel == VBT_1_8) {
            val = (kal_uint8)VBT_E3_1_8;
        }
        else if (sel == VBT_2_5) {
            val = (kal_uint8)VBT_E3_2_5;
        }
        else if (sel == VBT_2_8) {
            val = (kal_uint8)VBT_E3_2_8;
        }
        else if (sel == VBT_3_0) {
            val = (kal_uint8)VBT_E3_3_0;
        }
        else if (sel == VBT_3_3) {
            val = (kal_uint8)VBT_E3_3_3;
        }
        else
        {
            val = VBT_E3_1_5; // avoid warning
            ASSERT(0); // E3 VBT does NOT support 1.2V
        }
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3D;
        val = (kal_uint8)sel;
    }
    ASSERT(val <= 7);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[reg_addr] &= ~(VBT_SEL_MASK << VBT_SEL_SHIFT);
    pmic6326_reg[reg_addr] |= (val << VBT_SEL_SHIFT);

    pmic6326_reg_write(reg_addr, pmic6326_reg[reg_addr]);
    RELEASE_PMIC6326_CHECK;
}


void dcl_pmic6326_vbt_enable(kal_bool enable){
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3A;
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3D;
    }
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[reg_addr] &= ~(VBT_EN_MASK << VBT_EN_SHIFT);
    pmic6326_reg[reg_addr] |= (enable << VBT_EN_SHIFT);

    pmic6326_reg_write(reg_addr, pmic6326_reg[reg_addr]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vbt_ical_en(vbt_ical_en_enum sel){
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3A;
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3D;
    }
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x3D] &= ~(VBT_ICAL_EN_MASK << VBT_ICAL_EN_SHIFT);
    pmic6326_reg[0x3D] |= (sel << VBT_ICAL_EN_SHIFT);

    pmic6326_reg_write(0x3D, pmic6326_reg[0x3D]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vbt_en_force(kal_bool enable){
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3A;
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3D;
    }
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[reg_addr] &= ~(VBT_EN_FORCE_MASK << VBT_EN_FORCE_SHIFT);
    pmic6326_reg[reg_addr] |= ((kal_uint8)enable << VBT_EN_FORCE_SHIFT);

    pmic6326_reg_write(reg_addr, pmic6326_reg[reg_addr]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vbt_plnmos_dis(kal_bool disable){
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3A;
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3D;
    }
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[reg_addr] &= ~(VBT_PLNMOS_DIS_MASK << VBT_PLNMOS_DIS_SHIFT);
    pmic6326_reg[reg_addr] |= ((kal_uint8)disable << VBT_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(reg_addr, pmic6326_reg[reg_addr]);
    RELEASE_PMIC6326_CHECK;
}

// (0x3E) LDO CTRL 37 VBT
void dcl_pmic6326_vbt_cal(kal_uint8 val){
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3B;
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3E;
    }
    ASSERT(val <= 15);  // val is 0000 ~ 1111

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[reg_addr] &= ~(VBT_CAL_MASK << VBT_CAL_SHIFT);
    pmic6326_reg[reg_addr] |= (val << VBT_CAL_SHIFT);

    pmic6326_reg_write(reg_addr, pmic6326_reg[reg_addr]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vbt_calst(vbt_calst_enum sel){
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3B;
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3E;
    }
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[reg_addr] &= ~(VBT_CALST_MASK << VBT_CALST_SHIFT);
    pmic6326_reg[reg_addr] |= ((kal_uint8)sel << VBT_CALST_SHIFT);

    pmic6326_reg_write(reg_addr, pmic6326_reg[reg_addr]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vbt_caloc(vbt_caloc_enum sel){
    kal_uint16 reg_addr;
    if (pmic6326_eco_version >= PMIC6326_ECO_3_VERSION)
    {
        // E3 version
        reg_addr = 0x3B;
    }
    else
    {
        // E1, E2 version
        reg_addr = 0x3E;
    }
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[reg_addr] &= ~(VBT_CALOC_MASK << VBT_CALOC_SHIFT);
    pmic6326_reg[reg_addr] |= ((kal_uint8)sel << VBT_CALOC_SHIFT);

    pmic6326_reg_write(reg_addr, pmic6326_reg[reg_addr]);
    RELEASE_PMIC6326_CHECK;

}

// (0x40) LDO CTRL 39 VCAMD
void dcl_pmic6326_vcamd_sel(vcamd_sel_enum sel){
    kal_uint8 val;

    val = (kal_uint8)sel;
    ASSERT(val <= 7);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x40] &= ~(VCAMD_SEL_MASK << VCAMD_SEL_SHIFT);
    pmic6326_reg[0x40] |= (val << VCAMD_SEL_SHIFT);

    pmic6326_reg_write(0x40, pmic6326_reg[0x40]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcamd_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x40] &= ~(VCAMD_EN_MASK << VCAMD_EN_SHIFT);
    pmic6326_reg[0x40] |= (enable << VCAMD_EN_SHIFT);

    pmic6326_reg_write(0x40, pmic6326_reg[0x40]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcamd_ical_en(vcamd_ical_en_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x40] &= ~(VCAMD_ICAL_EN_MASK << VCAMD_ICAL_EN_SHIFT);
    pmic6326_reg[0x40] |= (sel << VCAMD_ICAL_EN_SHIFT);

    pmic6326_reg_write(0x40, pmic6326_reg[0x40]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcamd_en_force(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x40] &= ~(VCAMD_EN_FORCE_MASK << VCAMD_EN_FORCE_SHIFT);
    pmic6326_reg[0x40] |= ((kal_uint8)enable << VCAMD_EN_FORCE_SHIFT);

    pmic6326_reg_write(0x40, pmic6326_reg[0x40]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcamd_plnmos_dis(kal_bool disable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x40] &= ~(VCAMD_PLNMOS_DIS_MASK << VCAMD_PLNMOS_DIS_SHIFT);
    pmic6326_reg[0x40] |= ((kal_uint8)disable << VCAMD_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(0x40, pmic6326_reg[0x40]);
    RELEASE_PMIC6326_CHECK;
}

// (0x41) LDO CTRL 40 VCAMD
void dcl_pmic6326_vcamd_cal(kal_uint8 val){

    ASSERT(val <= 15);  // val is 0000 ~ 1111

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x41] &= ~(VCAMD_CAL_MASK << VCAMD_CAL_SHIFT);
    pmic6326_reg[0x41] |= (val << VCAMD_CAL_SHIFT);

    pmic6326_reg_write(0x41, pmic6326_reg[0x41]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcamd_calst(vcamd_calst_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x41] &= ~(VCAMD_CALST_MASK << VCAMD_CALST_SHIFT);
    pmic6326_reg[0x41] |= ((kal_uint8)sel << VCAMD_CALST_SHIFT);

    pmic6326_reg_write(0x41, pmic6326_reg[0x41]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcamd_caloc(vcamd_caloc_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x41] &= ~(VCAMD_CALOC_MASK << VCAMD_CALOC_SHIFT);
    pmic6326_reg[0x41] |= ((kal_uint8)sel << VCAMD_CALOC_SHIFT);

    pmic6326_reg_write(0x41, pmic6326_reg[0x41]);
    RELEASE_PMIC6326_CHECK;
}

// (0x43) LDO CTRL 42 VGP
void dcl_pmic6326_vgp_sel(vgp_sel_enum sel){
    kal_uint8 val;

    val = (kal_uint8) sel;
    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x43] &= ~(VGP_SEL_MASK << VGP_SEL_SHIFT);
    pmic6326_reg[0x43] |= (val << VGP_SEL_SHIFT);

    pmic6326_reg_write(0x43, pmic6326_reg[0x43]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vgp_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x43] &= ~(VGP_EN_MASK << VGP_EN_SHIFT);
    pmic6326_reg[0x43] |= (enable << VGP_EN_SHIFT);

    pmic6326_reg_write(0x43, pmic6326_reg[0x43]);
    RELEASE_PMIC6326_CHECK;
}


void dcl_pmic6326_vgp_plnmos_dis(kal_bool disable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x43] &= ~(VGP_PLNMOS_DIS_MASK << VGP_PLNMOS_DIS_SHIFT);
    pmic6326_reg[0x43] |= ((kal_uint8)disable << VGP_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(0x43, pmic6326_reg[0x43]);
    RELEASE_PMIC6326_CHECK;
}




// (0x44) LDO CTRL 43 VGP
void dcl_pmic6326_vgp_cal(kal_uint8 val){

    ASSERT(val <= 15);  // val is 0000 ~ 1111

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x44] &= ~(VGP_CAL_MASK << VGP_CAL_SHIFT);
    pmic6326_reg[0x44] |= (val << VGP_CAL_SHIFT);

    pmic6326_reg_write(0x44, pmic6326_reg[0x44]);
    RELEASE_PMIC6326_CHECK;
}


// (0x46) LDO CTRL 45 VSDIO
void dcl_pmic6326_vsdio_ical_en(vsdio_ical_en_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x46] &= ~(VSDIO_ICAL_EN_MASK << VSDIO_ICAL_EN_SHIFT);
    pmic6326_reg[0x46] |= (sel << VSDIO_ICAL_EN_SHIFT);

    pmic6326_reg_write(0x46, pmic6326_reg[0x46]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vsdio_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x46] &= ~(VSDIO_EN_MASK << VSDIO_EN_SHIFT);
    pmic6326_reg[0x46] |= (enable << VSDIO_EN_SHIFT);

    pmic6326_reg_write(0x46, pmic6326_reg[0x46]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vsdio_en_force(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x46] &= ~(VSDIO_EN_FORCE_MASK << VSDIO_EN_FORCE_SHIFT);
    pmic6326_reg[0x46] |= ((kal_uint8)enable << VSDIO_EN_FORCE_SHIFT);

    pmic6326_reg_write(0x46, pmic6326_reg[0x46]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vsdio_cal(kal_uint8 val){

    ASSERT(val <= 15);  // val is 0000 ~ 1111

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x46] &= ~(VSDIO_CAL_MASK << VSDIO_CAL_SHIFT);
    pmic6326_reg[0x46] |= (val << VSDIO_CAL_SHIFT);

    pmic6326_reg_write(0x46, pmic6326_reg[0x46]);
    RELEASE_PMIC6326_CHECK;
}

// (0x47) LDO CTRL 46 VSDIO
void dcl_pmic6326_vsdio_calst(vsdio_calst_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x47] &= ~(VSDIO_CALST_MASK << VSDIO_CALST_SHIFT);
    pmic6326_reg[0x47] |= ((kal_uint8)sel << VSDIO_CALST_SHIFT);

    pmic6326_reg_write(0x47, pmic6326_reg[0x47]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vsdio_caloc(vsdio_caloc_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x47] &= ~(VSDIO_CALOC_MASK << VSDIO_CALOC_SHIFT);
    pmic6326_reg[0x47] |= ((kal_uint8)sel << VSDIO_CALOC_SHIFT);

    pmic6326_reg_write(0x47, pmic6326_reg[0x47]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vsdio_plnmos_dis(kal_bool disable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x47] &= ~(VSDIO_PLNMOS_DIS_MASK << VSDIO_PLNMOS_DIS_SHIFT);
    pmic6326_reg[0x47] |= ((kal_uint8)disable << VSDIO_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(0x47, pmic6326_reg[0x47]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vsdio_sel(vsdio_sel_enum sel){
    kal_uint8 val;

    val = (kal_uint8) sel;

    LOCK_PMIC6326_CHECK;


    pmic6326_reg[0x47] &= ~(VSDIO_SEL_MASK << VSDIO_SEL_SHIFT);
    pmic6326_reg[0x47] |= (val << VSDIO_SEL_SHIFT);

    pmic6326_reg_write(0x47, pmic6326_reg[0x47]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vsdio_cm(vsdio_cm_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x47] &= ~(VSDIO_CM_MASK << VSDIO_CM_SHIFT);
    pmic6326_reg[0x47] |= ((kal_uint8)sel << VSDIO_CM_SHIFT);

    pmic6326_reg_write(0x47, pmic6326_reg[0x47]);
    RELEASE_PMIC6326_CHECK;
}

// (0x48) LDO CTRL 47 VSDIO
void dcl_pmic6326_vcore1_dvfs_step_inc(kal_uint8 val){
    ASSERT(val <= 0x1F);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x48] &= ~(VCORE1_DVFS_STEP_INC_MASK << VCORE1_DVFS_STEP_INC_SHIFT);
    pmic6326_reg[0x48] |= ((kal_uint8)val << VCORE1_DVFS_STEP_INC_SHIFT);

    pmic6326_reg_write(0x48, pmic6326_reg[0x48]);
    RELEASE_PMIC6326_CHECK;
}

// (0x4E) BUCK CTRL 6 VCORE1
void dcl_pmic6326_vcore1_dvfs_0_eco3(kal_uint8 val){
    ASSERT(val <= 0xF);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x4E] &= ~(VCORE1_DVFS_0_ECO3_MASK << VCORE1_DVFS_0_ECO3_SHIFT);
    pmic6326_reg[0x4E] |= ((kal_uint8)val << VCORE1_DVFS_0_ECO3_SHIFT);

    pmic6326_reg_write(0x4E, pmic6326_reg[0x4E]);
    RELEASE_PMIC6326_CHECK;
}

// (0x4F) BUCK CTRL 7 VCORE1
void dcl_pmic6326_vcore1_sleep_0_eco3(kal_uint8 val){
    ASSERT(val <= 0x1);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x4F] &= ~(VCORE1_SLEEP_0_ECO3_MASK << VCORE1_SLEEP_0_ECO3_SHIFT);
    pmic6326_reg[0x4F] |= ((kal_uint8)val << VCORE1_SLEEP_0_ECO3_SHIFT);

    pmic6326_reg_write(0x4F, pmic6326_reg[0x4F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcore1_dvfs_ramp_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x4F] &= ~(VCORE1_DVFS_RAMP_EN_MASK << VCORE1_DVFS_RAMP_EN_SHIFT);
    pmic6326_reg[0x4F] |= ((kal_uint8)enable << VCORE1_DVFS_RAMP_EN_SHIFT);

    pmic6326_reg_write(0x4F, pmic6326_reg[0x4F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcore1_dvfs_target_update(kal_bool update){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x4F] &= ~(VCORE1_DVFS_TARGET_UPDATE_MASK << VCORE1_DVFS_TARGET_UPDATE_SHIFT);
    pmic6326_reg[0x4F] |= ((kal_uint8)update << VCORE1_DVFS_TARGET_UPDATE_SHIFT);

    pmic6326_reg_write(0x4F, pmic6326_reg[0x4F]);
    RELEASE_PMIC6326_CHECK;
}

// (0x51) BUCK CTRL 9 VCORE2
void dcl_pmic6326_vcore2_dvfs_0_eco3(kal_uint8 val)
{
    ASSERT(val <= 0xF);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x51] &= ~(VCORE2_DVFS_0_ECO3_MASK << VCORE2_DVFS_0_ECO3_SHIFT);
    pmic6326_reg[0x51] |= ((kal_uint8)val << VCORE2_DVFS_0_ECO3_SHIFT);

    pmic6326_reg_write(0x51, pmic6326_reg[0x51]);
    RELEASE_PMIC6326_CHECK;
}

// (0x52) BUCK CTRL 10 VCORE2
void dcl_pmic6326_vcore2_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x52] &= ~(VCORE2_EN_MASK << VCORE2_EN_SHIFT);
    pmic6326_reg[0x52] |= ((kal_uint8)enable << VCORE2_EN_SHIFT);

    pmic6326_reg_write(0x52, pmic6326_reg[0x52]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcore2_sleep_0_eco3(kal_uint8 val)
{
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x52] &= ~(VCORE2_SLEEP_0_ECO3_MASK << VCORE2_SLEEP_0_ECO3_SHIFT);
    pmic6326_reg[0x52] |= ((kal_uint8)val << VCORE2_SLEEP_0_ECO3_SHIFT);

    pmic6326_reg_write(0x52, pmic6326_reg[0x52]);
    RELEASE_PMIC6326_CHECK;
}


// (0x53) BUCK CTRL 11 VCORE2
void dcl_pmic6326_vcore2_on_sel(vcore2_on_sel_enum sel){
    kal_uint8 val;
    val = (kal_uint8)sel;
    ASSERT(val <= 1);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x53] &= ~(VCORE2_ON_SEL_MASK << VCORE2_ON_SEL_SHIFT);
    pmic6326_reg[0x53] |= ((kal_uint8)val << VCORE2_ON_SEL_SHIFT);

    pmic6326_reg_write(0x53, pmic6326_reg[0x53]);
    RELEASE_PMIC6326_CHECK;
}

// (0x54) BUCK CTRL 12 VCORE2
void dcl_pmic6326_vcore2_plnmos_dis(kal_bool disable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x54] &= ~(VCORE2_PLNMOS_DIS_MASK << VCORE2_PLNMOS_DIS_SHIFT);
    pmic6326_reg[0x54] |= ((kal_uint8)disable << VCORE2_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(0x54, pmic6326_reg[0x54]);
    RELEASE_PMIC6326_CHECK;
}



// (0x57) BUCK CTRL 15 VMEM
void dcl_pmic6326_vcore1_sleep_1_eco3(kal_uint8 val){
    ASSERT(val <= 1);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x57] &= ~(VCORE1_SLEEP_1_ECO3_MASK << VCORE1_SLEEP_1_ECO3_SHIFT);
    pmic6326_reg[0x57] |= ((kal_uint8)val << VCORE1_SLEEP_1_ECO3_SHIFT);

    pmic6326_reg_write(0x57, pmic6326_reg[0x57]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vcore1_dvfs_1_eco3(kal_uint8 val){
    ASSERT(val <= 15);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x57] &= ~(VCORE1_DVFS_1_ECO3_MASK << VCORE1_DVFS_1_ECO3_SHIFT);
    pmic6326_reg[0x57] |= ((kal_uint8)val << VCORE1_DVFS_1_ECO3_SHIFT);

    pmic6326_reg_write(0x57, pmic6326_reg[0x57]);
    RELEASE_PMIC6326_CHECK;
}

// (0x58) BUCK CTRL 16 VPA
void dcl_pmic6326_vpa_tuneh(kal_uint8 value){

    ASSERT(value <= 31);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x58] &= ~(VPA_TUNEH_MASK << VPA_TUNEH_SHIFT);
    pmic6326_reg[0x58] |= (value << VPA_TUNEH_SHIFT);

    pmic6326_reg_write(0x58, pmic6326_reg[0x58]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vpa_en_force(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x58] &= ~(VPA_EN_FORCE_MASK << VPA_EN_FORCE_SHIFT);
    pmic6326_reg[0x58] |= ((kal_uint8)enable << VPA_EN_FORCE_SHIFT);

    pmic6326_reg_write(0x58, pmic6326_reg[0x58]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vpa_plnmos_dis(kal_bool disable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x58] &= ~(VPA_PLNMOS_DIS_MASK << VPA_PLNMOS_DIS_SHIFT);
    pmic6326_reg[0x58] |= ((kal_uint8)disable << VPA_PLNMOS_DIS_SHIFT);

    pmic6326_reg_write(0x58, pmic6326_reg[0x58]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vpa_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x58] &= ~(VPA_EN_MASK << VPA_EN_SHIFT);
    pmic6326_reg[0x58] |= ((kal_uint8)enable << VPA_EN_SHIFT);

    pmic6326_reg_write(0x58, pmic6326_reg[0x58]);
    RELEASE_PMIC6326_CHECK;
}

// (0x59) BUCK CTRL 17 VPA
void dcl_pmic6326_vpa_tunel(kal_uint8 value){

    ASSERT(value <= 31);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x59] &= ~(VPA_TUNEL_MASK << VPA_TUNEL_SHIFT);
    pmic6326_reg[0x59] |= (value << VPA_TUNEL_SHIFT);

    pmic6326_reg_write(0x59, pmic6326_reg[0x59]);
    RELEASE_PMIC6326_CHECK;
}

// (0x5A) BUCK CTRL 18 VPA
void dcl_pmic6326_vpa_oc_tune(kal_uint8 val){
    ASSERT(val <= 7);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x5A] &= ~(VPA_OC_TH_MASK << VPA_OC_TH_SHIFT);
    pmic6326_reg[0x5A] |= (val << VPA_OC_TH_SHIFT);

    pmic6326_reg_write(0x5A, pmic6326_reg[0x5A]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vpa_bat_low(kal_bool bat_low){
    ASSERT((kal_uint8)bat_low <= 1);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x5A] &= ~(VPA_BAT_LOW_MASK << VPA_BAT_LOW_SHIFT);
    pmic6326_reg[0x5A] |= ((kal_uint8)bat_low << VPA_BAT_LOW_SHIFT);

    pmic6326_reg_write(0x5A, pmic6326_reg[0x5A]);
    RELEASE_PMIC6326_CHECK;
}



// (0x5C) BOOST CTRL 1 BOOST1
void dcl_pmic6326_vboost1_tune(vboost1_tune_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x5C] &= ~(VBOOST1_TUNE_MASK << VBOOST1_TUNE_SHIFT);
    pmic6326_reg[0x5C] |= ((kal_uint8)sel << VBOOST1_TUNE_SHIFT);

    pmic6326_reg_write(0x5C, pmic6326_reg[0x5C]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vboost1_tatt(kal_uint8 val){
    // TODO, can we make val to enum?

    ASSERT(val <= 15);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x5C] &= ~(VBOOST1_TATT_MASK << VBOOST1_TATT_SHIFT);
    pmic6326_reg[0x5C] |= (val << VBOOST1_TATT_SHIFT);

    pmic6326_reg_write(0x5C, pmic6326_reg[0x5C]);
    RELEASE_PMIC6326_CHECK;
}


// (0x5D) BOOST CTRL 2 BOOST1
void dcl_pmic6326_boost1_oc_th(kal_uint8 val){
    // TODO, can we make val to enum?

    ASSERT(val <= 7);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x5D] &= ~(BOOST1_OC_TH_MASK << BOOST1_OC_TH_SHIFT);
    pmic6326_reg[0x5D] |= (val << BOOST1_OC_TH_SHIFT);

    pmic6326_reg_write(0x5D, pmic6326_reg[0x5D]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_boost1_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;

    if (enable){
        pmic6326_vboost1_set_flag |= VBOOST1_SET_FLAG_BOOST1;
    }else{
        pmic6326_vboost1_set_flag &= ~(VBOOST1_SET_FLAG_BOOST1);
    }
    dcl_pmic6326_boost1_enable_internal(pmic6326_vboost1_set_flag);

    RELEASE_PMIC6326_CHECK;
}

// Internal usage only, called insided PMIC6326 driver
// Do NOT need protection check, because it is called inside PMIC API
// Moved as a macro
//void dcl_pmic6326_boost1_enable_internal(kal_bool enable){
// pmic6326_reg[0x5D] &= ~(BOOST1_EN_MASK << BOOST1_EN_SHIFT);
// pmic6326_reg[0x5D] |= ((kal_uint8)enable << BOOST1_EN_SHIFT);
//
// pmic6326_reg_write(0x5D, pmic6326_reg[0x5D]);
//}

void dcl_pmic6326_boost1_pre_sr_con(kal_uint8 val){
    // TODO, can we make val to enum?

    ASSERT(val <= 7);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x5D] &= ~(BOOST1_PRE_SR_CON_MASK << BOOST1_PRE_SR_CON_SHIFT);
    pmic6326_reg[0x5D] |= (val << BOOST1_PRE_SR_CON_SHIFT);

    pmic6326_reg_write(0x5D, pmic6326_reg[0x5D]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_boost1_soft_st_speed(boost1_soft_st_speed_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x5D] &= ~(BOOST1_SOFT_ST_SPEED_MASK << BOOST1_SOFT_ST_SPEED_SHIFT);
    pmic6326_reg[0x5D] |= ((kal_uint8)sel << BOOST1_SOFT_ST_SPEED_SHIFT);

    pmic6326_reg_write(0x5D, pmic6326_reg[0x5D]);
    RELEASE_PMIC6326_CHECK;
}


// (0x5E) BOOST CTRL 3 BOOST1
void dcl_pmic6326_boost1_dio_sr_con(kal_uint8 val){
    // TODO, can we make val to enum?

    ASSERT(val <= 7);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x5E] &= ~(BOOST1_DIO_SR_CON_MASK << BOOST1_DIO_SR_CON_SHIFT);
    pmic6326_reg[0x5E] |= (val << BOOST1_DIO_SR_CON_SHIFT);

    pmic6326_reg_write(0x5E, pmic6326_reg[0x5E]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_boost1_sync_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x5E] &= ~(BOOST1_SYNC_EN_MASK << BOOST1_SYNC_EN_SHIFT);
    pmic6326_reg[0x5E] |= ((kal_uint8)enable << BOOST1_SYNC_EN_SHIFT);

    pmic6326_reg_write(0x5E, pmic6326_reg[0x5E]);
    RELEASE_PMIC6326_CHECK;
}

// (0x5F) BOOST CTRL 4 BOOST2
void dcl_pmic6326_boost2_tune(vboost2_tune_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x5F] &= ~(BOOST2_TUNE_MASK << BOOST2_TUNE_SHIFT);
    pmic6326_reg[0x5F] |= ((kal_uint8)sel << BOOST2_TUNE_SHIFT);

    pmic6326_reg_write(0x5F, pmic6326_reg[0x5F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_boots2_oc_th(boost2_oc_th_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x5F] &= ~(BOOST2_OC_TH_MASK << BOOST2_OC_TH_SHIFT);
    pmic6326_reg[0x5F] |= ((kal_uint8)sel << BOOST2_OC_TH_SHIFT);

    pmic6326_reg_write(0x5F, pmic6326_reg[0x5F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_boost2_dim_source(boost2_dim_source_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x5F] &= ~(BOOST2_DIM_SOURCE_MASK << BOOST2_DIM_SOURCE_SHIFT);
    pmic6326_reg[0x5F] |= ((kal_uint8)sel << BOOST2_DIM_SOURCE_SHIFT);

    pmic6326_reg_write(0x5F, pmic6326_reg[0x5F]);
    RELEASE_PMIC6326_CHECK;
}

// (0x60) BOOST CTRL 5 BOOST2
void dcl_pmic6326_boost2_pre_sr_con(kal_uint8 val){

    ASSERT(val <= 7);

    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x60] &= ~(BOOST2_PRE_SR_CON_MASK << BOOST2_PRE_SR_CON_SHIFT);
    pmic6326_reg[0x60] |= ((kal_uint8)val << BOOST2_PRE_SR_CON_SHIFT);

    pmic6326_reg_write(0x60, pmic6326_reg[0x60]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_boost2_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x60] &= ~(BOOST2_EN_MASK << BOOST2_EN_SHIFT);
    pmic6326_reg[0x60] |= ((kal_uint8)enable << BOOST2_EN_SHIFT);

    pmic6326_reg_write(0x60, pmic6326_reg[0x60]);
    RELEASE_PMIC6326_CHECK;
}

// (0x61) BOOST CTRL 6 BOOST2 and BOOST
void dcl_pmic6326_boost_mode(boost_mode_sel_enum sel){
    kal_uint8 val;
    val = (kal_uint8)sel;
    ASSERT(val <= 3);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x61] &= ~(BOOST_MODE_MASK << BOOST_MODE_SHIFT);
    pmic6326_reg[0x61] |= ((kal_uint8)val << BOOST_MODE_SHIFT);

    pmic6326_reg_write(0x61, pmic6326_reg[0x61]);
    RELEASE_PMIC6326_CHECK;
}

// (0x64) DRIVER CTRL 3 GEN
void dcl_pmic6326_igen_drv_isel(kal_uint8 sel){

    ASSERT(sel <= 3);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x64] &= ~(IGEN_DRV_ISEL_MASK << IGEN_DRV_ISEL_SHIFT);
    pmic6326_reg[0x64] |= (sel << IGEN_DRV_ISEL_SHIFT);

    pmic6326_reg_write(0x64, pmic6326_reg[0x64]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_igen_drv_force(kal_bool force){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x64] &= ~(IGEN_DRV_FORCE_MASK << IGEN_DRV_FORCE_SHIFT);
    pmic6326_reg[0x64] |= (force << IGEN_DRV_FORCE_SHIFT);

    pmic6326_reg_write(0x64, pmic6326_reg[0x64]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vgen_drv_bgsel(kal_uint8 sel){

    ASSERT(sel <= 7);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x64] &= ~(VGEN_DRV_BGSEL_MASK << VGEN_DRV_BGSEL_SHIFT);
    pmic6326_reg[0x64] |= ((kal_uint8)sel << VGEN_DRV_BGSEL_SHIFT);

    pmic6326_reg_write(0x64, pmic6326_reg[0x64]);
    RELEASE_PMIC6326_CHECK;
}


// (0x65) DRIVER CTRL 4 FLASH
void dcl_pmic6326_flash_i_tune(kal_uint8 val){

    ASSERT((kal_uint8)val <= 15);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x65] &= ~(FLASH_I_TUNE_MASK << FLASH_I_TUNE_SHIFT);
    pmic6326_reg[0x65] |= ((kal_uint8)val << FLASH_I_TUNE_SHIFT);

    pmic6326_reg_write(0x65, pmic6326_reg[0x65]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_flash_dim_div(kal_uint8 val){

    ASSERT(val <= 15);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x65] &= ~(FLASH_DIM_DIV_MASK << FLASH_DIM_DIV_SHIFT);
    pmic6326_reg[0x65] |= ((kal_uint8)val << FLASH_DIM_DIV_SHIFT);
    pmic6326_reg_write(0x65, pmic6326_reg[0x65]);
    RELEASE_PMIC6326_CHECK;
}

// (0x66) DRIVER CTRL 5 FLASH
void dcl_pmic6326_flash_dim_duty(kal_uint8 duty){

    ASSERT(duty <= 31);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x66] &= ~(FLASH_DIM_DUTY_MASK << FLASH_DIM_DUTY_SHIFT);
    pmic6326_reg[0x66] |= (duty << FLASH_DIM_DUTY_SHIFT);

    pmic6326_reg_write(0x66, pmic6326_reg[0x66]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_flash_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;

    if (enable){
        pmic6326_vboost1_set_flag |= VBOOST1_SET_FLAG_FLASH;
        pmic6326_dim_ck_set_flag |= DIM_CK_ON_FLAG_FLASH;
    }else{
        pmic6326_vboost1_set_flag &= ~VBOOST1_SET_FLAG_FLASH;
        pmic6326_dim_ck_set_flag &= ~DIM_CK_ON_FLAG_FLASH;
    }
    dcl_pmic6326_boost1_enable_internal(pmic6326_vboost1_set_flag);
    dcl_pmic6326_dim_ck_force_on_internal(pmic6326_dim_ck_set_flag);


    pmic6326_reg[0x66] &= ~(FLASH_EN_MASK << FLASH_EN_SHIFT);
    pmic6326_reg[0x66] |= (enable << FLASH_EN_SHIFT);
    pmic6326_reg_write(0x66, pmic6326_reg[0x66]);

    RELEASE_PMIC6326_CHECK;
}

// If bypass divisor, the frequency of BL is 50K/(div+1)
// If no bypass divisor, the frequency of BL is 2K/(div+1)
void dcl_pmic6326_flash_bypass(kal_bool bypass){
    LOCK_PMIC6326_CHECK;
    // bypass = TRUE ==> Bypass divisor 25 for FLASH PWM
    // bypass = FALSE ==> No bypass for FLASH PWM
    pmic6326_reg[0x66] &= ~(FLASH_BYPASS_MASK << FLASH_BYPASS_SHIFT);
    pmic6326_reg[0x66] |= (bypass << FLASH_BYPASS_SHIFT);

    pmic6326_reg_write(0x66, pmic6326_reg[0x66]);
    RELEASE_PMIC6326_CHECK;
}

// (0x67) DRIVER CTRL 6 BL
void dcl_pmic6326_bl_dim_duty(kal_uint8 duty){

    ASSERT(duty <= 31);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x67] &= ~(BL_DIM_DUTY_MASK << BL_DIM_DUTY_SHIFT);
    pmic6326_reg[0x67] |= (duty << BL_DIM_DUTY_SHIFT);

    pmic6326_reg_write(0x67, pmic6326_reg[0x67]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_bl_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    if (enable){
        pmic6326_vboost1_set_flag |= VBOOST1_SET_FLAG_BL;
    }else{
        pmic6326_vboost1_set_flag &= ~VBOOST1_SET_FLAG_BL;
    }
    dcl_pmic6326_boost1_enable_internal(pmic6326_vboost1_set_flag);
    pmic6326_reg[0x67] &= ~(BL_EN_MASK << BL_EN_SHIFT);
    pmic6326_reg[0x67] |= (enable << BL_EN_SHIFT);
    pmic6326_reg_write(0x67, pmic6326_reg[0x67]);

    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_bl_i_cal_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x67] &= ~(BL_I_CAL_EN_MASK << BL_I_CAL_EN_SHIFT);
    pmic6326_reg[0x67] |= (enable << BL_I_CAL_EN_SHIFT);

    pmic6326_reg_write(0x67, pmic6326_reg[0x67]);
    RELEASE_PMIC6326_CHECK;
}

// If bypass divisor, the frequency of BL is 50K/(div+1)
// If no bypass divisor, the frequency of BL is 2K/(div+1)
void dcl_pmic6326_bl_bypass(kal_bool bypass){
    LOCK_PMIC6326_CHECK;
    // bypass = TRUE ==> Bypass divisor 25 for BL PWM
    // bypass = FALSE ==> No bypass for BL PWM
    pmic6326_reg[0x67] &= ~(BL_BYPASS_MASK << BL_BYPASS_SHIFT);
    pmic6326_reg[0x67] |= (bypass << BL_BYPASS_SHIFT);

    pmic6326_reg_write(0x67, pmic6326_reg[0x67]);
    RELEASE_PMIC6326_CHECK;
}

// (0x68) DRIVER CTRL 7 BL
void dcl_pmic6326_bl_i_corse_tune(bl_i_corse_tune_enum sel){

    ASSERT((kal_uint8)sel <= 7);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x68] &= ~(BL_I_CORSE_TUNE_MASK << BL_I_CORSE_TUNE_SHIFT);
    pmic6326_reg[0x68] |= ((kal_uint8)sel << BL_I_CORSE_TUNE_SHIFT);

    pmic6326_reg_write(0x68, pmic6326_reg[0x68]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_bl_i_fine_tune(bl_i_fine_tune_enum sel){

    ASSERT((kal_uint8)sel <= 7);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x68] &= ~(BL_I_FINE_TUNE_MASK << BL_I_FINE_TUNE_SHIFT);
    pmic6326_reg[0x68] |= ((kal_uint8)sel << BL_I_FINE_TUNE_SHIFT);

    pmic6326_reg_write(0x68, pmic6326_reg[0x68]);
    RELEASE_PMIC6326_CHECK;
}

// (0x6D) DRIVER CTRL 12 BL
void dcl_pmic6326_bl_dim_div(kal_uint8 val){

    ASSERT(val <= 15);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x6D] &= ~(BL_DIM_DIV_MASK << BL_DIM_DIV_SHIFT);
    pmic6326_reg[0x6D] |= ((kal_uint8)val << BL_DIM_DIV_SHIFT);
    pmic6326_reg_write(0x6D, pmic6326_reg[0x6D]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_bl_number(bl_number_enum num){

    ASSERT((kal_uint8)num <= 7);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x6D] &= ~(BL_NUMBER_MASK << BL_NUMBER_SHIFT);
    pmic6326_reg[0x6D] |= ((kal_uint8)num << BL_NUMBER_SHIFT);
    pmic6326_reg_write(0x6D, pmic6326_reg[0x6D]);
    RELEASE_PMIC6326_CHECK;
}

DCL_UINT32 bl_support_level;
DCL_BOOL bl_use_pwm;
static boost_mode_sel_enum dcl_pmic6326_boost_mode_val;
void dcl_pmic6326_init_bl(boost_mode_sel_enum boost_mode)
{
	dcl_pmic6326_boost_mode_val = boost_mode;
    // boost mode 0
    if (BOOST_MODE_TYPE_I == boost_mode)
    {
        dcl_pmic6326_boost_mode(BOOST_MODE_TYPE_I);
        dcl_pmic6326_igen_drv_force(KAL_TRUE);
        bl_support_level = BL_DIMMING_CONTROL_LEVEL;
        bl_use_pwm = DCL_TRUE;        
    }// boost mode 1
    else if (BOOST_MODE_TYPE_II == boost_mode)
    {
        dcl_pmic6326_boost2_dim_source(BOOST2_ANALOG_DIMING);
        dcl_pmic6326_boost_mode(BOOST_MODE_TYPE_II);
        bl_support_level = BL_DIMMING_CONTROL_LEVEL;
        bl_use_pwm = DCL_FALSE;            
    }
    else
    {
        ASSERT(1);
    }
}

void dcl_pmic6326_enable_bl(kal_bool enable)
{
	if (BOOST_MODE_TYPE_I == dcl_pmic6326_boost_mode_val)
	{
		if (enable)
		{
			dcl_pmic6326_bl_enable(KAL_TRUE);
			dcl_pmic6326_dim_ck_force_on(KAL_TRUE);
		}
		else
		{
			dcl_pmic6326_bl_enable(KAL_FALSE);
			dcl_pmic6326_dim_ck_force_on(KAL_FALSE);
		}
	}
	else if (BOOST_MODE_TYPE_II == dcl_pmic6326_boost_mode_val)
	{
		if (enable)
		{
			dcl_pmic6326_boost2_enable(KAL_TRUE);
			dcl_pmic6326_dim_ck_force_on(KAL_TRUE);
		}
		else
		{
			dcl_pmic6326_boost2_enable(KAL_FALSE);
			dcl_pmic6326_dim_ck_force_on(KAL_FALSE);
		}
	}
}


// (0x6E) DRIVER CTRL 13 KP
void dcl_pmic6326_kp_dim_div(kal_uint8 val){

    ASSERT(val <= 15);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x6E] &= ~(KP_DIM_DIV_MASK << KP_DIM_DIV_SHIFT);
    pmic6326_reg[0x6E] |= ((kal_uint8)val << KP_DIM_DIV_SHIFT);
    pmic6326_reg_write(0x6E, pmic6326_reg[0x6E]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_kp_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;

    if (enable){
        pmic6326_dim_ck_set_flag |= DIM_CK_ON_FLAG_KEY;
    }else{
        pmic6326_dim_ck_set_flag &= ~DIM_CK_ON_FLAG_KEY;
    }
    dcl_pmic6326_dim_ck_force_on_internal(pmic6326_dim_ck_set_flag);


    pmic6326_reg[0x6E] &= ~(KP_EN_MASK << KP_EN_SHIFT);
    pmic6326_reg[0x6E] |= (enable << KP_EN_SHIFT);

    pmic6326_reg_write(0x6E, pmic6326_reg[0x6E]);
    RELEASE_PMIC6326_CHECK;
}

// (0x6F) DRIVER CTRL 14 KP
void dcl_pmic6326_kp_dim_duty(kal_uint8 duty){

    ASSERT(duty <= 31);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x6F] &= ~(KP_DIM_DUTY_MASK << KP_DIM_DUTY_SHIFT);
    pmic6326_reg[0x6F] |= (duty << KP_DIM_DUTY_SHIFT);

    pmic6326_reg_write(0x6F, pmic6326_reg[0x6F]);
    RELEASE_PMIC6326_CHECK;
}

// (0x70) DRIVER CTRL 15 VIBR
void dcl_pmic6326_vibr_dim_div(kal_uint8 val){

    ASSERT(val <= 15);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x70] &= ~(VIBR_DIM_DIV_MASK << VIBR_DIM_DIV_SHIFT);
    pmic6326_reg[0x70] |= ((kal_uint8)val << VIBR_DIM_DIV_SHIFT);
    pmic6326_reg_write(0x70, pmic6326_reg[0x70]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vibr_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;

    if (enable){
        pmic6326_dim_ck_set_flag |= DIM_CK_ON_FLAG_VIB;
    }else{
        pmic6326_dim_ck_set_flag &= ~DIM_CK_ON_FLAG_VIB;
    }
    dcl_pmic6326_dim_ck_force_on_internal(pmic6326_dim_ck_set_flag);


    pmic6326_reg[0x70] &= ~(VIBR_EN_MASK << VIBR_EN_SHIFT);
    pmic6326_reg[0x70] |= (enable << VIBR_EN_SHIFT);

    pmic6326_reg_write(0x70, pmic6326_reg[0x70]);
    RELEASE_PMIC6326_CHECK;
}

// (0x71) DRIVER CTRL 16 VIBR
void dcl_pmic6326_vibr_dim_duty(kal_uint8 duty){

    ASSERT(duty <= 31);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x71] &= ~(VIBR_DIM_DUTY_MASK << VIBR_DIM_DUTY_SHIFT);
    pmic6326_reg[0x71] |= (duty << VIBR_DIM_DUTY_SHIFT);

    pmic6326_reg_write(0x71, pmic6326_reg[0x71]);
    RELEASE_PMIC6326_CHECK;
}

// (0x73) CLASS_D CTRL 3 SPKL
void dcl_pmic6326_spkl_dtin(kal_uint8 val){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x73] &= ~(SPKL_DTIN_MASK << SPKL_DTIN_SHIFT);
    pmic6326_reg[0x73] |= (val << SPKL_DTIN_SHIFT);

    pmic6326_reg_write(0x73, pmic6326_reg[0x73]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_spkl_dtip(kal_uint8 val){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x73] &= ~(SPKL_DTIP_MASK << SPKL_DTIP_SHIFT);
    pmic6326_reg[0x73] |= (val << SPKL_DTIP_SHIFT);

    pmic6326_reg_write(0x73, pmic6326_reg[0x73]);
    RELEASE_PMIC6326_CHECK;
}

// (0x74) CLASS_D CTRL 4 SPKL
void dcl_pmic6326_spkl_dmode_internal(spkl_dmode_enum sel){
    kal_uint8 val;
    val = (kal_uint8)sel;
    ASSERT(val <= 3);
    pmic6326_reg[0x74] &= ~(SPKL_DMODE_MASK << SPKL_DMODE_SHIFT);
    pmic6326_reg[0x74] |= ((kal_uint8)val << SPKL_DMODE_SHIFT);

    pmic6326_reg_write(0x74, pmic6326_reg[0x74]);
}

void dcl_pmic6326_spkl_dmode(spkl_dmode_enum sel){
    kal_uint8 val;
    val = (kal_uint8)sel;
    ASSERT(val <= 3);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x74] &= ~(SPKL_DMODE_MASK << SPKL_DMODE_SHIFT);
    pmic6326_reg[0x74] |= ((kal_uint8)val << SPKL_DMODE_SHIFT);

    pmic6326_reg_write(0x74, pmic6326_reg[0x74]);
    RELEASE_PMIC6326_CHECK;
}

kal_uint8 spkL1stDeadTimeCalbStage = 0;

void dcl_pmic6326_spkl_enable_internal(kal_bool enable)
{
    pmic6326_reg[0x74] &= ~(SPKL_EN_MASK << SPKL_EN_SHIFT);
    pmic6326_reg[0x74] |= ((kal_uint8)enable << SPKL_EN_SHIFT);

    pmic6326_reg_write(0x74, pmic6326_reg[0x74]);
}

extern void dcl_pmic6326_spkl_dtcal_internal(spkl_dtcal_enum sel);
void dcl_pmic6326_spkl_enable(kal_bool enable)
{
    //volatile kal_uint32 count;

    LOCK_PMIC6326_CHECK;
    
   if ((KAL_TRUE == enable))
    {
    	// Enable SPK
        dcl_pmic6326_spkl_enable_internal(KAL_TRUE);
        // Check if first time enable SPK. 
        // If so, then start calibration
    	if (0 == spkL1stDeadTimeCalbStage)
    	{
            dcl_pmic6326_spkl_dmode_internal(SPKL_FB_AUTO_CAL_DTCN_DTCP); // 10
            dcl_pmic6326_spkl_dtcal_internal(SPKL_DTCAL_ENABLE_CLASS_D_R_READ_TIME_CAL);
            spkL1stDeadTimeCalbStage++;
        }
    }
    else if ((KAL_FALSE == enable))
    {
        if (1 == spkL1stDeadTimeCalbStage)
        {
            // Stop cal
            dcl_pmic6326_spkl_dtcal_internal(SPKL_DTCAL_DISABLE_CLASS_D_R_READ_TIME_CAL);
            
            spkL1stDeadTimeCalbStage++;
        }
        // Disable SPK
        dcl_pmic6326_spkl_enable_internal(KAL_FALSE);
    }

    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_spkl_dtcal_internal(spkl_dtcal_enum sel){
    kal_uint8 val;
    val = (kal_uint8)sel;
    ASSERT(val <= 1);
    pmic6326_reg[0x74] &= ~(SPKL_DTCAL_MASK << SPKL_DTCAL_SHIFT);
    pmic6326_reg[0x74] |= ((kal_uint8)val << SPKL_DTCAL_SHIFT);

    pmic6326_reg_write(0x74, pmic6326_reg[0x74]);
}

void dcl_pmic6326_spkl_dtcal(spkl_dtcal_enum sel){
    kal_uint8 val;
    val = (kal_uint8)sel;
    ASSERT(val <= 1);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x74] &= ~(SPKL_DTCAL_MASK << SPKL_DTCAL_SHIFT);
    pmic6326_reg[0x74] |= ((kal_uint8)val << SPKL_DTCAL_SHIFT);

    pmic6326_reg_write(0x74, pmic6326_reg[0x74]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_spkl_slew(spkl_slew_enum val){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0X75] &= ~(SPKL_SLEW_MASK << SPKL_SLEW_SHIFT);
    pmic6326_reg[0X75] |= (val << SPKL_SLEW_SHIFT);

    pmic6326_reg_write(0X75, pmic6326_reg[0X75]);
    RELEASE_PMIC6326_CHECK;
}



void dcl_pmic6326_spkl_volume(spkl_vol_enum  val){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x76] &= ~(SPKL_VOL_MASK << SPKL_VOL_SHIFT);
    pmic6326_reg[0x76] |= (val << SPKL_VOL_SHIFT);

    pmic6326_reg_write(0x76, pmic6326_reg[0x76]);
    RELEASE_PMIC6326_CHECK;
}



// (0x77) CLASS_D CTRL 7 SPKL
void dcl_pmic6326_spkl_oc(spkl_oc_enum sel){
    kal_uint8 val;
    val = (kal_uint8)sel;
    ASSERT(val <= 1);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x77] &= ~(SPKL_OC_MASK << SPKL_OC_SHIFT);
    pmic6326_reg[0x77] |= ((kal_uint8)val << SPKL_OC_SHIFT);

    pmic6326_reg_write(0x77, pmic6326_reg[0x77]);
    RELEASE_PMIC6326_CHECK;
}


// (0x78) CLASS_D CTRL 8 SPKR
void dcl_pmic6326_spkr_dtin(kal_uint8 val){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x78] &= ~(SPKR_DTIN_MASK << SPKR_DTIN_SHIFT);
    pmic6326_reg[0x78] |= (val << SPKR_DTIN_SHIFT);

    pmic6326_reg_write(0x78, pmic6326_reg[0x78]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_spkr_dtip(kal_uint8 val){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x78] &= ~(SPKR_DTIP_MASK << SPKR_DTIP_SHIFT);
    pmic6326_reg[0x78] |= (val << SPKR_DTIP_SHIFT);

    pmic6326_reg_write(0x78, pmic6326_reg[0x78]);
    RELEASE_PMIC6326_CHECK;
}

// (0x79) CLASS_D CTRL 9 SPKR
void dcl_pmic6326_spkr_dmode_internal(spkr_dmode_enum sel){
    kal_uint8 val;
    val = (kal_uint8)sel;
    ASSERT(val <= 3);
    pmic6326_reg[0x79] &= ~(SPKR_DMODE_MASK << SPKR_DMODE_SHIFT);
    pmic6326_reg[0x79] |= ((kal_uint8)val << SPKR_DMODE_SHIFT);

    pmic6326_reg_write(0x79, pmic6326_reg[0x79]);

}

void dcl_pmic6326_spkr_dmode(spkr_dmode_enum sel){
    kal_uint8 val;
    val = (kal_uint8)sel;
    ASSERT(val <= 3);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x79] &= ~(SPKR_DMODE_MASK << SPKR_DMODE_SHIFT);
    pmic6326_reg[0x79] |= ((kal_uint8)val << SPKR_DMODE_SHIFT);

    pmic6326_reg_write(0x79, pmic6326_reg[0x79]);
    RELEASE_PMIC6326_CHECK;
}

kal_uint8 spkR1stDeadTimeCalbStage = 0;

void dcl_pmic6326_spkr_enable_internal(kal_bool enable)
{

    pmic6326_reg[0x79] &= ~(SPKR_EN_MASK << SPKR_EN_SHIFT);
    pmic6326_reg[0x79] |= ((kal_uint8)enable << SPKR_EN_SHIFT);

    pmic6326_reg_write(0x79, pmic6326_reg[0x79]);

}

extern void dcl_pmic6326_spkr_dtcal_internal(spkr_dtcal_enum sel);
void dcl_pmic6326_spkr_enable(kal_bool enable)
{
    //volatile kal_uint32 count;
    
    LOCK_PMIC6326_CHECK;
    
    if ((KAL_TRUE == enable))
    {
        dcl_pmic6326_spkr_enable_internal(KAL_TRUE);
        if (0 == spkR1stDeadTimeCalbStage)
        {
            dcl_pmic6326_spkr_dmode_internal(SPKR_FB_AUTO_CAL_DTCN_DTCP); // 10
            dcl_pmic6326_spkr_dtcal_internal(SPKR_DTCAL_ENABLE_CLASS_D_R_READ_TIME_CAL);
            spkR1stDeadTimeCalbStage++;
        }
    }
    else if ((KAL_FALSE == enable))
    {
    	if (1 == spkR1stDeadTimeCalbStage)
        {
            dcl_pmic6326_spkr_dtcal_internal(SPKR_DTCAL_DISABLE_CLASS_D_R_READ_TIME_CAL);
            spkR1stDeadTimeCalbStage++;
        }
        dcl_pmic6326_spkr_enable_internal(KAL_FALSE);
    }
   
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_spkr_slew(spkr_slew_enum val){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0X7A] &= ~(SPKR_SLEW_MASK << SPKR_SLEW_SHIFT);
    pmic6326_reg[0X7A] |= (val << SPKR_SLEW_SHIFT);

    pmic6326_reg_write(0X7A, pmic6326_reg[0X7A]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_spkr_dtcal_internal(spkr_dtcal_enum sel){
    kal_uint8 val;
    val = (kal_uint8)sel;
    ASSERT(val <= 1);
    pmic6326_reg[0x79] &= ~(SPKR_DTCAL_MASK << SPKR_DTCAL_SHIFT);
    pmic6326_reg[0x79] |= ((kal_uint8)val << SPKR_DTCAL_SHIFT);

    pmic6326_reg_write(0x79, pmic6326_reg[0x79]);

}

void dcl_pmic6326_spkr_dtcal(spkr_dtcal_enum sel){
    kal_uint8 val;
    val = (kal_uint8)sel;
    ASSERT(val <= 1);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x79] &= ~(SPKR_DTCAL_MASK << SPKR_DTCAL_SHIFT);
    pmic6326_reg[0x79] |= ((kal_uint8)val << SPKR_DTCAL_SHIFT);

    pmic6326_reg_write(0x79, pmic6326_reg[0x79]);
    RELEASE_PMIC6326_CHECK;
}

// (0x7B) CLASS_D CTRL 11 SPKR
void dcl_pmic6326_spkr_volume(spkr_vol_enum val){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x7B] &= ~(SPKR_VOL_MASK << SPKR_VOL_SHIFT);
    pmic6326_reg[0x7B] |= (val << SPKR_VOL_SHIFT);

    pmic6326_reg_write(0x7B, pmic6326_reg[0x7B]);
    RELEASE_PMIC6326_CHECK;
}


// (0x7C) CLASS_D CTRL 12 SPKR
void dcl_pmic6326_spkr_oc(spkr_oc_enum sel){
    kal_uint8 val;
    val = (kal_uint8)sel;
    ASSERT(val <= 1);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x7C] &= ~(SPKR_OC_MASK << SPKR_OC_SHIFT);
    pmic6326_reg[0x7C] |= ((kal_uint8)val << SPKR_OC_SHIFT);

    pmic6326_reg_write(0x7C, pmic6326_reg[0x7C]);
    RELEASE_PMIC6326_CHECK;
}


// (0x81) CHARGER CTRL 1
void dcl_pmic6326_chr_offset(cht_chr_offset_enum sel){
    kal_uint8 val;
    val = (kal_uint8)sel;
    ASSERT(val <= 7);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x81] &= ~(CHR_CHOFST_MASK << CHR_CHOFST_SHIFT);
    pmic6326_reg[0x81] |= ((kal_uint8)val << CHR_CHOFST_SHIFT);

    pmic6326_reg_write(0x81, pmic6326_reg[0x81]);
    RELEASE_PMIC6326_CHECK;
}

cht_chr_offset_enum dcl_pmic6326_get_chr_offset(void)
{
	kal_uint8 val;
	val = pmic6326_reg[0x81];
	val &= (CHR_CHOFST_MASK << CHR_CHOFST_SHIFT);
	val = (val >> CHR_CHOFST_SHIFT);
	return (cht_chr_offset_enum) val;
}

void dcl_pmic6326_chr_ov_th_high(void){
    // TODO
    LOCK_PMIC6326_CHECK;
    ASSERT(0);
    RELEASE_PMIC6326_CHECK;
}

chr_chr_current_enum dcl_pmic6326_get_chr_current(void){
    return (pmic6326_reg[0x81] & (CHR_CHR_CURRENT_MASK << CHR_CHR_CURRENT_SHIFT)) >> CHR_CHR_CURRENT_SHIFT;
}

void dcl_pmic6326_chr_current(chr_chr_current_enum current){
    chr_chr_current_enum current_level;
    kal_bool chr_enable_flag = KAL_FALSE;

    ASSERT((kal_uint8)current <= 7);



    // Turn off charging first before set from high current level to lower current level
    current_level = dcl_pmic6326_get_chr_current();
    kal_prompt_trace(MOD_BMT,"PMIC6326: Charge current level #1: %d",current_level);
    if (current_level > current)
    {
		if (pmic6326_reg[0x82] & (CHR_CHR_EN_MASK << CHR_CHR_EN_SHIFT))
		{
			chr_enable_flag = KAL_TRUE;
		}
    // turn off charger, prevent below case 1 happen.
    // level 6  change to level 4:  	6 -> 7 -> 0 -> 1 -> 2 -> 3 -> 4
        dcl_pmic6326_chr_chr_enable(KAL_FALSE);
    // level 6  change to level 4:  	6 -> off -> 0 -> 1 -> 2 -> 3 -> 4
    }
    //Turn off charging first before set from high current level to lower current level


    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x81] &= ~(CHR_CHR_CURRENT_MASK << CHR_CHR_CURRENT_SHIFT);
    pmic6326_reg[0x81] |= ((kal_uint8)current << CHR_CHR_CURRENT_SHIFT);
    pmic6326_reg_write(0x81, pmic6326_reg[0x81]);
    RELEASE_PMIC6326_CHECK;

	if (chr_enable_flag)
	{
		dcl_pmic6326_chr_chr_enable(KAL_TRUE);
	}

}





// (0x82) CHARGER CTRL 2
void dcl_pmic6326_chr_cv_rt(void){
    // TODO
    LOCK_PMIC6326_CHECK;
    ASSERT(0);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_chr_force(kal_bool force){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x82] &= ~(CHR_CHRON_FORCE_MASK << CHR_CHRON_FORCE_SHIFT);
    pmic6326_reg[0x82] |= ((kal_uint8)force << CHR_CHRON_FORCE_SHIFT);

    pmic6326_reg_write(0x82, pmic6326_reg[0x82]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_chr_chr_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x82] &= ~(CHR_CHR_EN_MASK << CHR_CHR_EN_SHIFT);
    pmic6326_reg[0x82] |= ((kal_uint8)enable << CHR_CHR_EN_SHIFT);

    pmic6326_reg_write(0x82, pmic6326_reg[0x82]);
    RELEASE_PMIC6326_CHECK;

#if defined(ENABLE_dcl_pmic6326_DRIVER_KICK_CHARGER_WATCHDOG_TIMER)
    dcl_pmic6326_kick_wdt(enable);
#endif // #if defined(ENABLE_dcl_pmic6326_DRIVER_KICK_CHARGER_WATCHDOG_TIMER)

}

void dcl_pmic6326_chr_cv_tune(void){
    // TODO
    LOCK_PMIC6326_CHECK;
    ASSERT(0);
    RELEASE_PMIC6326_CHECK;
}



// (0x83) TESTMODE CTRL 3 Analog Switch
void dcl_pmic6326_asw_asel(asw_asel_enum sel){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x83] &= ~(ASW_ASEL_MASK << ASW_ASEL_SHIFT);
    pmic6326_reg[0x83] |= ((kal_uint8)sel << ASW_ASEL_SHIFT);

    pmic6326_reg_write(0x83, pmic6326_reg[0x83]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_asw_bsel(asw_bsel_enum sel){

    ASSERT((kal_uint8)sel <= 2);  // 0x3 is reserved

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x83] &= ~(ASW_BSEL_MASK << ASW_BSEL_SHIFT);
    pmic6326_reg[0x83] |= ((kal_uint8)sel << ASW_BSEL_SHIFT);

    pmic6326_reg_write(0x83, pmic6326_reg[0x83]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_asw_a1sel(kal_uint8 sel){

    ASSERT(sel <= 1);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x83] &= ~(ASW_A1_SEL_MASK << ASW_A1_SEL_SHIFT);
    pmic6326_reg[0x83] |= (sel << ASW_A1_SEL_SHIFT);

    pmic6326_reg_write(0x83, pmic6326_reg[0x83]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_asw_a2sel(kal_uint8 sel){

    ASSERT(sel <= 1);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x83] &= ~(ASW_A2_SEL_MASK << ASW_A2_SEL_SHIFT);
    pmic6326_reg[0x83] |= (sel << ASW_A2_SEL_SHIFT);

    pmic6326_reg_write(0x83, pmic6326_reg[0x83]);
    RELEASE_PMIC6326_CHECK;
}

// (0x86) TESTMODE CTRL 6 BB AUXADC Related
void dcl_pmic6326_adc_isense_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x86] &= ~(ADC_ISENSE_OUT_EN_MASK << ADC_ISENSE_OUT_EN_SHIFT);
    pmic6326_reg[0x86] |= ((kal_uint8)enable << ADC_ISENSE_OUT_EN_SHIFT);

    pmic6326_reg_write(0x86, pmic6326_reg[0x86]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_adc_vbat_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x86] &= ~(ADC_VBAT_OUT_EN_MASK << ADC_VBAT_OUT_EN_SHIFT);
    pmic6326_reg[0x86] |= ((kal_uint8)enable << ADC_VBAT_OUT_EN_SHIFT);

    pmic6326_reg_write(0x86, pmic6326_reg[0x86]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_adc_meas_on(kal_bool on){
    LOCK_PMIC6326_CHECK;
    if (on){
        pmic6326_reg[0x86] |= (((kal_uint8)ADC_VBAT_OUT_EN_MASK << ADC_VBAT_OUT_EN_SHIFT) | ((kal_uint8)ADC_ISENSE_OUT_EN_MASK << ADC_ISENSE_OUT_EN_SHIFT));
    }else{
        pmic6326_reg[0x86] &= ~(((kal_uint8)ADC_VBAT_OUT_EN_MASK << ADC_VBAT_OUT_EN_SHIFT) | ((kal_uint8)ADC_ISENSE_OUT_EN_MASK << ADC_ISENSE_OUT_EN_SHIFT));
    }
    pmic6326_reg_write(0x86, pmic6326_reg[0x86]);
    RELEASE_PMIC6326_CHECK;
}

// (0x89) INT CTRL 1
void dcl_pmic6326_int_ctrl_1_enable(int_ctrl_1_enum sel, kal_bool enable){

    ASSERT((kal_uint32)sel <= 0xFF);

    LOCK_PMIC6326_CHECK;

    if (enable){
        pmic6326_reg[0x89] |= (kal_uint8)sel;
    }else{
        pmic6326_reg[0x89] &= ~((kal_uint8)sel);
    }
    pmic6326_reg_write(0x89, pmic6326_reg[0x89]);
    RELEASE_PMIC6326_CHECK;
}

// (0x8A) INT CTRL 2
void dcl_pmic6326_int_ctrl_2_enable(int_ctrl_2_enum sel, kal_bool enable){

    ASSERT((kal_uint32)sel <= 0xFF);

    LOCK_PMIC6326_CHECK;

    if (enable){
        pmic6326_reg[0x8A] |= (kal_uint8)sel;
    }else{
        pmic6326_reg[0x8A] &= ~((kal_uint8)sel);
    }
    pmic6326_reg_write(0x8A, pmic6326_reg[0x8A]);
    RELEASE_PMIC6326_CHECK;
}

// (0x8B) INT CTRL 2
void dcl_pmic6326_int_ctrl_3_enable(int_ctrl_3_enum sel, kal_bool enable){

    ASSERT((kal_uint32)sel <= 0xFF);

    LOCK_PMIC6326_CHECK;

    if (enable){
        pmic6326_reg[0x8B] |= (kal_uint8)sel;
    }else{
        pmic6326_reg[0x8B] &= ~((kal_uint8)sel);
    }
    pmic6326_reg_write(0x8B, pmic6326_reg[0x8B]);
    RELEASE_PMIC6326_CHECK;
}

// (0x8F) ST CTRL 2

void dcl_pmic6326_st_gear_vwifi3v3(st_gear_vwifi3v3 gear){

    ASSERT((kal_uint8)gear <= 3);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x8F] &= ~( ST_GEAR_VWIFI3V3_MASK << ST_GEAR_VWIFI3V3_SHIFT);
    pmic6326_reg[0x8F] |= ((kal_uint8)gear << ST_GEAR_VWIFI3V3_SHIFT);
    pmic6326_reg_write(0x8F, pmic6326_reg[0x8F]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_st_gear_vwifi2v8(st_gear_vwifi2v8 gear){

    ASSERT((kal_uint8)gear <= 3);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x8F] &= ~( ST_GEAR_VWIFI2V8_MASK << ST_GEAR_VWIFI2V8_SHIFT);
    pmic6326_reg[0x8F] |= ((kal_uint8)gear << ST_GEAR_VWIFI2V8_SHIFT);
    pmic6326_reg_write(0x8F, pmic6326_reg[0x8F]);
    RELEASE_PMIC6326_CHECK;
}

// (0x90)
void dcl_pmic6326_st_gear_vsdio(st_gear_vsdio gear){

    ASSERT((kal_uint8)gear <= 3);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x90] &= ~( ST_GEAR_VSDIO_MASK << ST_GEAR_VSDIO_SHIFT);
    pmic6326_reg[0x90] |= ((kal_uint8)gear << ST_GEAR_VSDIO_SHIFT);
    pmic6326_reg_write(0x90, pmic6326_reg[0x90]);
    RELEASE_PMIC6326_CHECK;
}

// (0x92) OC CTRL 2
void dcl_pmic6326_oc_gear_vwifi3v3(oc_gear_vwifi3v3 gear){

    ASSERT((kal_uint8)gear <= 3);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x92] &= ~( OC_GEAR_VWIFI3V3_MASK << OC_GEAR_VWIFI3V3_SHIFT);
    pmic6326_reg[0x92] |= ((kal_uint8)gear << OC_GEAR_VWIFI3V3_SHIFT);
    pmic6326_reg_write(0x92, pmic6326_reg[0x92]);
    RELEASE_PMIC6326_CHECK;
}
// (0x92) OC CTRL 2
void dcl_pmic6326_oc_gear_vwifi2v8(oc_gear_vwifi2v8 gear){

    ASSERT((kal_uint8)gear <= 3);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x92] &= ~( OC_GEAR_VWIFI2V8_MASK << OC_GEAR_VWIFI2V8_SHIFT);
    pmic6326_reg[0x92] |= ((kal_uint8)gear << OC_GEAR_VWIFI2V8_SHIFT);
    pmic6326_reg_write(0x92, pmic6326_reg[0x92]);
    RELEASE_PMIC6326_CHECK;
}

// (0x93) OC CTRL 3
void dcl_pmic6326_oc_gear_vsdio(oc_gear_vsdio gear){

    ASSERT((kal_uint8)gear <= 3);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x93] &= ~( OC_GEAR_VSDIO_MASK << OC_GEAR_VSDIO_SHIFT);
    pmic6326_reg[0x93] |= ((kal_uint8)gear << OC_GEAR_VSDIO_SHIFT);
    pmic6326_reg_write(0x93, pmic6326_reg[0x93]);
    RELEASE_PMIC6326_CHECK;
}



// (0x96) WATCHDOG CTRL and INT CTRL 4
void dcl_pmic6326_wdt_timeout(wdt_timout_enum sel){

    ASSERT((kal_uint8)sel <= 3);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x96] &= ~(WDT_TIMEOUT_MASK << WDT_TIMEOUT_SHIFT);
    pmic6326_reg[0x96] |= ((kal_uint8)sel << WDT_TIMEOUT_SHIFT);
    pmic6326_reg_write(0x96, pmic6326_reg[0x96]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_intr_polarity(kal_bool assert){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x96] &= ~(INTR_POLARITY_MASK << INTR_POLARITY_SHIFT);
    // 1. Flag assert when intr occur
    // 0. Flag de-assert when intr occur
    pmic6326_reg[0x96] |= ((kal_uint8)assert << INTR_POLARITY_SHIFT);
    pmic6326_reg_write(0x96, pmic6326_reg[0x96]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_wdt_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x96] &= ~(WDT_DISABLE_MASK << WDT_DISABLE_SHIFT);
    // 1: Disable WDT
    // 0: Enable WDT
    pmic6326_reg[0x96] |= ((kal_uint8)(~enable) << WDT_DISABLE_SHIFT);
    pmic6326_reg_write(0x96, pmic6326_reg[0x96]);
    RELEASE_PMIC6326_CHECK;
}



void dcl_pmic6326_vbus_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x63] &= ~(VBUS_EN_MASK << VBUS_EN_SHIFT);
    pmic6326_reg[0x63] |= (enable << VBUS_EN_SHIFT);

    pmic6326_reg_write(0x63, pmic6326_reg[0x63]);

    RELEASE_PMIC6326_CHECK;
}

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void dcl_pmic6326_vgp2_enable(kal_bool enable){
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x1A] &= ~(VGP2_EN_MASK << VGP2_EN_SHIFT);
    pmic6326_reg[0x1A] |= (enable << VGP2_EN_SHIFT);

    pmic6326_reg_write(0x1A, pmic6326_reg[0x1A]);

    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vgp2_sel(vgp2_sel_enum sel){
    kal_uint8 val;

    val = (kal_uint8)sel;
    ASSERT(val <= 6);

    LOCK_PMIC6326_CHECK;

    dcl_pmic6326_vgp2_selh(val >> 2); // Extract bit2 to write to selh
    dcl_pmic6326_vgp2_sell(val & 0x3); // Extract bit[1..0] to write to sell
    RELEASE_PMIC6326_CHECK;

}

void dcl_pmic6326_vgp2_on_sel(vgp2_on_sel_enum sel){
    kal_uint8 val;

    val = (kal_uint8)sel;
    ASSERT(val <= 1);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x84] &= ~(VGP2_ON_SEL_MASK << VGP2_ON_SEL_SHIFT);
    pmic6326_reg[0x84] |= (val << VGP2_ON_SEL_SHIFT);

    pmic6326_reg_write(0x84, pmic6326_reg[0x84]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vgp2_sell(kal_uint8 value){

    ASSERT(value <= 3);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x49] &= ~(VGP2_SELL_MASK << VGP2_SELL_SHIFT);
    pmic6326_reg[0x49] |= (value << VGP2_SELL_SHIFT);

    pmic6326_reg_write(0x49, pmic6326_reg[0x49]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vgp2_selh(kal_uint8 value){

    ASSERT(value <= 1);

    LOCK_PMIC6326_CHECK;

    pmic6326_reg[0x5E] &= ~(VGP2_SELH_MASK << VGP2_SELH_SHIFT);
    pmic6326_reg[0x5E] |= (value << VGP2_SELH_SHIFT);

    pmic6326_reg_write(0x5E, pmic6326_reg[0x5E]);
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_vgp2_ocfb_enable(kal_bool enable)
{
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[0x3D] &= ~(VGP2_OCFB_EN_MASK << VGP2_OCFB_EN_SHIFT);
    pmic6326_reg[0x3D] |= (enable << VGP2_OCFB_EN_SHIFT);

    pmic6326_reg_write(0x3D, pmic6326_reg[0x3D]);
    RELEASE_PMIC6326_CHECK;
}


void dcl_pmic6326_vsim2_enable(kal_bool enable){
    dcl_pmic6326_vgp2_enable(enable);
    // Always to VGP2_EN_SEL to VGP2_ENABLE_WITH_VGP2_EN
    dcl_pmic6326_vgp2_on_sel(VGP2_ENABLE_WITH_VGP2_EN);

}

void dcl_pmic6326_vsim2_sel(vsim_sel_enum sel){
    kal_uint8 val;

    val = (kal_uint8)sel;
    ASSERT(val <= 6);

    LOCK_PMIC6326_CHECK;

    dcl_pmic6326_vgp2_selh(val >> 2); // Extract bit2 to write to selh
    dcl_pmic6326_vgp2_sell(val & 0x3); // Extract bit[1..0] to write to sell
    RELEASE_PMIC6326_CHECK;
}

void dcl_pmic6326_spk_enable(kal_bool enable){
    // Empty function, not used anymore
}


// Exported for EM used
void pmic6326_EM_reg_write(kal_uint8 reg, kal_uint8 val){
    ASSERT(reg <= PMIC_MAX_REG_IDX);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg[reg] = val;
    pmic6326_reg_write(reg, pmic6326_reg[reg]);
    RELEASE_PMIC6326_CHECK;
}

kal_uint8 pmic6326_EM_reg_read(kal_uint8 reg){
    ASSERT(reg <= PMIC_MAX_REG_IDX);
    LOCK_PMIC6326_CHECK;
    pmic6326_reg_read(reg, &pmic6326_reg[reg]);
    RELEASE_PMIC6326_CHECK;
    return pmic6326_reg[reg];
}


#if defined(DRV_MISC_PMIC_ASSERT_KEEP_CHARGING)
static kal_uint32 kick_count;
static kal_bool charge_enable;
void pmic6326_assert_chaging_kick(void){
    kick_count++;
    if ( (kick_count % 1000000) == 0 ){
        dcl_pmic6326_chr_current(CHR_CURRENT_650MA);
        dcl_pmic6326_chr_chr_enable(charge_enable);
        if (charge_enable){
            charge_enable = KAL_FALSE;
        }else{
            charge_enable = KAL_TRUE;
        }
    }
}
#endif // #if defined(DRV_MISC_PMIC_ASSERT_KEEP_CHARGING)




DCL_UINT32 vgp2_vosel[]=
{
      PMU_VOLT_01_300000_V, PMU_VOLT_01_500000_V, PMU_VOLT_01_800000_V, PMU_VOLT_02_500000_V,
      PMU_VOLT_02_800000_V, PMU_VOLT_03_000000_V, PMU_VOLT_03_300000_V
};


DCL_UINT32 vbt_vosel[]=
{
      PMU_VOLT_01_300000_V, PMU_VOLT_01_500000_V, PMU_VOLT_01_800000_V, PMU_VOLT_02_500000_V,
      PMU_VOLT_02_800000_V, PMU_VOLT_03_000000_V, PMU_VOLT_03_300000_V, PMU_VOLT_01_200000_V
};


DCL_UINT32 vcama_vosel[]=
{
      PMU_VOLT_02_800000_V, PMU_VOLT_02_500000_V, PMU_VOLT_01_800000_V, PMU_VOLT_01_500000_V
};


DCL_UINT32 vsim_vosel[]=
{
	PMU_VOLT_01_300000_V, PMU_VOLT_01_500000_V, PMU_VOLT_01_800000_V, PMU_VOLT_02_500000_V,
	PMU_VOLT_02_800000_V, PMU_VOLT_03_000000_V, PMU_VOLT_03_300000_V
};

DCL_UINT32 vsdio_vosel[]=
{
      PMU_VOLT_02_800000_V, PMU_VOLT_03_000000_V
};

DCL_UINT32 vwifi3v3_vosel[]=
{
      PMU_VOLT_02_800000_V, PMU_VOLT_03_000000_V ,PMU_VOLT_03_300000_V ,PMU_VOLT_02_500000_V
};

DCL_UINT32 vbus_vosel[]=
{
      PMU_VOLT_03_200000_V, PMU_VOLT_03_350000_V ,PMU_VOLT_03_500000_V ,PMU_VOLT_03_650000_V,
      PMU_VOLT_03_800000_V, PMU_VOLT_03_950000_V ,PMU_VOLT_04_100000_V ,PMU_VOLT_04_250000_V,
      PMU_VOLT_04_400000_V, PMU_VOLT_04_550000_V ,PMU_VOLT_04_700000_V ,PMU_VOLT_04_850000_V,
      PMU_VOLT_05_000000_V, PMU_VOLT_05_150000_V ,PMU_VOLT_05_300000_V       
};

DCL_UINT32 vpa_votune[]=
{
	PMU_VOLT_01_075000_V, PMU_VOLT_01_150000_V, PMU_VOLT_01_225000_V, PMU_VOLT_01_300000_V, 
	PMU_VOLT_01_375000_V, PMU_VOLT_01_450000_V, PMU_VOLT_01_525000_V, PMU_VOLT_01_600000_V, 
	PMU_VOLT_01_675000_V, PMU_VOLT_01_750000_V, PMU_VOLT_01_825000_V, PMU_VOLT_01_900000_V, 
	PMU_VOLT_01_975000_V, PMU_VOLT_02_050000_V, PMU_VOLT_02_125000_V, PMU_VOLT_02_200000_V, 
	PMU_VOLT_02_275000_V, PMU_VOLT_02_350000_V, PMU_VOLT_02_425000_V, PMU_VOLT_02_500000_V, 
	PMU_VOLT_02_575000_V, PMU_VOLT_02_650000_V, PMU_VOLT_02_725000_V, PMU_VOLT_02_800000_V, 
	PMU_VOLT_02_875000_V, PMU_VOLT_02_950000_V, PMU_VOLT_03_025000_V, PMU_VOLT_03_100000_V, 
	PMU_VOLT_03_175000_V, PMU_VOLT_03_250000_V, PMU_VOLT_03_325000_V, PMU_VOLT_03_400000_V         
};

//CHR CURRENT
DCL_UINT32 cs_vth[]=
{
	PMU_CHARGE_CURRENT_62_50_MA,PMU_CHARGE_CURRENT_87_50_MA,
	PMU_CHARGE_CURRENT_150_00_MA,PMU_CHARGE_CURRENT_225_00_MA,
	PMU_CHARGE_CURRENT_300_00_MA,PMU_CHARGE_CURRENT_450_00_MA,
	PMU_CHARGE_CURRENT_650_00_MA,PMU_CHARGE_CURRENT_800_00_MA
};



PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{
	//BUCK group
	{ENC(LDO_BUCK_SET_VOLTAGE,VGP2),		vgp2_vosel,		NULL,				GETARRNUM(vgp2_vosel)		},
	{ENC(LDO_BUCK_SET_VOLTAGE,VBT),		vbt_vosel,		NULL,				GETARRNUM(vbt_vosel)		},
	{ENC(LDO_BUCK_SET_VOLTAGE,VCAMA),		vcama_vosel,	NULL,				GETARRNUM(vcama_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VCAMD),		vbt_vosel,		NULL,				GETARRNUM(vbt_vosel)		},
	{ENC(LDO_BUCK_SET_VOLTAGE,VGP),		vbt_vosel,		NULL,				GETARRNUM(vbt_vosel)		},	
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM2),		vbt_vosel,		NULL,				GETARRNUM(vbt_vosel)		},	
	{ENC(LDO_BUCK_SET_VOLTAGE,VWIFI2V8),	vwifi3v3_vosel,	NULL,				GETARRNUM(vwifi3v3_vosel)	},	
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM),		vgp2_vosel,		NULL,				GETARRNUM(vgp2_vosel)		},
	{ENC(LDO_BUCK_SET_VOLTAGE,VSDIO),		vsdio_vosel,		NULL,				GETARRNUM(vsdio_vosel)		},	
	{ENC(LDO_BUCK_SET_VOLTAGE,VWIFI3V3),	vwifi3v3_vosel,		NULL,			GETARRNUM(vwifi3v3_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,V3GTX),		vwifi3v3_vosel,		NULL,			GETARRNUM(vwifi3v3_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,V3GRX),		vwifi3v3_vosel,		NULL,			GETARRNUM(vwifi3v3_vosel)	},		
	{ENC(LDO_BUCK_SET_VOLTAGE,VBUS),		vbus_vosel,		NULL,			GETARRNUM(vbus_vosel)	},		
	//VPA
	{ENC(VPA_SET_VOLTAGE,VPA1),				vpa_votune,		NULL,				GETARRNUM(vpa_votune)		},
	//CHR
	{ENC(CHR_SET_CHR_CURRENT,ALLMOD),		cs_vth,			NULL,				GETARRNUM(cs_vth)			}	
};




extern PMU_CONTROL_HANDLER pmu_control_handler;
DCL_UINT16 pmu_parameter_size=0;

DCL_STATUS PMIC6326_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
{
	DCL_UINT16	regVal;
	DCL_UINT32	val;

	switch(cmd)
	{
		case LDO_BUCK_SET_EN:
		{
			PMU_CTRL_LDO_BUCK_SET_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetEn);

			switch(pLdoBuckCtrl->mod)
			{
				case VCORE2:
				{
					dcl_pmic6326_vcore2_enable(pLdoBuckCtrl->enable);
				}
				break;
				case VSIM2:
				case VGP:
				{
					dcl_pmic6326_vgp_enable(pLdoBuckCtrl->enable);
				}
				break;		
				case VSDIO:
				{
					dcl_pmic6326_vsdio_enable(pLdoBuckCtrl->enable);
				}
				break;						
				case VBT:
				{
					dcl_pmic6326_vbt_enable(pLdoBuckCtrl->enable);
				}
				break;					
				case VCAMA:
				{
					dcl_pmic6326_vcama_enable(pLdoBuckCtrl->enable);
				}
				break;
				case VCAMD:
				{
					dcl_pmic6326_vcamd_enable(pLdoBuckCtrl->enable);
				}
				break;
				case VWIFI2V8:
				{
					dcl_pmic6326_vwifi2v8_enable(pLdoBuckCtrl->enable);
				}
				break;		
				case VSIM:
				{
					dcl_pmic6326_vsim_enable(pLdoBuckCtrl->enable);
				}
				break;
				case V3GTX:
				{
					dcl_pmic6326_v3gtx_enable(pLdoBuckCtrl->enable);
				}
				break;				
				case V3GRX:
				{
					dcl_pmic6326_v3grx_enable(pLdoBuckCtrl->enable);
				}
				break;
				case VGP2:
				{
					dcl_pmic6326_vgp2_enable(pLdoBuckCtrl->enable);
				}
				break;		
				case VIBR:
				{
					dcl_pmic6326_vibr_enable(pLdoBuckCtrl->enable);
				}
				break;					
				case VBUS:
				{	
                                dcl_pmic6326_boost_mode(BOOST_MODE_TYPE_I);
                                dcl_pmic6326_boost1_enable (KAL_TRUE);
                                dcl_pmic6326_vbus_enable(pLdoBuckCtrl->enable);
				}
				break;				
				default:				
				return STATUS_UNSUPPORTED;
				break;			
			}
		}
		break;
		case LDO_BUCK_SET_ON_SEL:
		{
			PMU_CTRL_LDO_BUCK_SET_ON_SEL *pLdoBuckCtrl=&(data->rPMULdoBuckSetOnSel);
			switch(pLdoBuckCtrl->mod)
			{
				case VGP2:
				{
					dcl_pmic6326_vgp2_on_sel(pLdoBuckCtrl->onSel);
				}
				break;	
				case VRF:
				{
					dcl_pmic6326_vrf_on_sel(pLdoBuckCtrl->onSel);
				}
				break;					
				case VTCXO:
				{
					dcl_pmic6326_vtcxo_on_sel(pLdoBuckCtrl->onSel);
				}
				break;
				case V3GTX:
				{
					dcl_pmic6326_v3gtx_on_sel(pLdoBuckCtrl->onSel);
				}
				break;				
				case V3GRX:
				{
					dcl_pmic6326_v3grx_on_sel(pLdoBuckCtrl->onSel);
				}
				break;						
				default:				
				return STATUS_UNSUPPORTED;
				break;			
			}
		}
		break;		
		case LDO_BUCK_SET_VOLTAGE:
		{
			PMU_CTRL_LDO_BUCK_SET_VOLTAGE *pLdoBuckCtrl=&(data->rPMULdoBuckSetVoltage);			
			regVal=PMU_Parameter_to_Value(ENC(cmd,pLdoBuckCtrl->mod),pLdoBuckCtrl->voltage);
			switch(pLdoBuckCtrl->mod)
			{
				case VSIM2:
				case VGP:
				{
					dcl_pmic6326_vgp_sel(regVal);
				}
				break;
				case VSDIO:
				{
					dcl_pmic6326_vsdio_sel(regVal);
				}
				break;		
				case VWIFI3V3:
				{
					dcl_pmic6326_vwifi3v3_sel(regVal);
				}
				break;	
				case V3GRX:
				{
					dcl_pmic6326_v3grx_sel(regVal);
				}
				break;		
				case V3GTX:
				{
					dcl_pmic6326_v3gtx_sel(regVal);
				}
				break;					
				case VGP2:
				{
					dcl_pmic6326_vgp2_sel(regVal);
				}
				break;	
				case VBT:
				{
					dcl_pmic6326_vbt_sel(regVal);
				}
				break;					
				case VCAMA:
				{
					dcl_pmic6326_vcama_sel(regVal);
				}
				break;		
				case VCAMD:
				{
					dcl_pmic6326_vcamd_sel(regVal);
				}
				break;		
				case VWIFI2V8:
				{
					dcl_pmic6326_vwifi2v8_sel(regVal);
				}
				break;
				case VSIM:
				{	
					dcl_pmic6326_vsim_sel(regVal);
				}
				break;					
				case VBUS:
				{	
					dcl_pmic6326_vboost1_tune(regVal);
				}
				break;				
				default:				
				return STATUS_UNSUPPORTED;
				break;			
			}
		}	
		break;
		case LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE:
		{
			PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE *pLdoBuckCtrl=&(data->rPMULdoBuckSetVoltageCalibrationCode);			
			switch(pLdoBuckCtrl->mod)
			{
				case V3GRX:
				{
					dcl_pmic6326_v3grx_cal(pLdoBuckCtrl->voltageCalibrationCode);
				}
				break;	
				case V3GTX:
				{
					dcl_pmic6326_v3gtx_cal(pLdoBuckCtrl->voltageCalibrationCode);
				}
				break;						
				case VBT:
				{
					dcl_pmic6326_vbt_cal(pLdoBuckCtrl->voltageCalibrationCode);
				}
				break;		
				case VCAMA:
				{
					dcl_pmic6326_vcama_cal(pLdoBuckCtrl->voltageCalibrationCode);
				}
				break;		
				case VCAMD:
				{
					dcl_pmic6326_vcamd_cal(pLdoBuckCtrl->voltageCalibrationCode);
				}
				break;
				case VSIM2:
				case VGP:
				{
					dcl_pmic6326_vgp_cal(pLdoBuckCtrl->voltageCalibrationCode);
				}
				break;		
				case VRF:
				{
					dcl_pmic6326_vrf_cal(pLdoBuckCtrl->voltageCalibrationCode);
				}
				break;
				case VSDIO:
				{
					dcl_pmic6326_vsdio_cal(pLdoBuckCtrl->voltageCalibrationCode);
				}
				break;
				case VSIM:
				{
					dcl_pmic6326_vsim_cal(pLdoBuckCtrl->voltageCalibrationCode);
				}
				break;	
				case VTCXO:
				{
					dcl_pmic6326_vtcxo_cal(pLdoBuckCtrl->voltageCalibrationCode);
				}
				break;	
				case VWIFI2V8:
				{
					dcl_pmic6326_vwifi2v8_cal(pLdoBuckCtrl->voltageCalibrationCode);
				}
				break;	
				case VWIFI3V3:
				{
					dcl_pmic6326_vwifi3v3_cal(pLdoBuckCtrl->voltageCalibrationCode);
				}
				break;						
				default:				
				return STATUS_UNSUPPORTED;
				break;			
			}
		}	
		break;
		//VPA
		case VPA_SET_EN:
		{
			PMU_CTRL_VPA_SET_EN *pVpaCtrl=&(data->rPMUVpaSetEn);
			dcl_pmic6326_vpa_enable(pVpaCtrl->enable);			
		}
		break;
		case VPA_SET_VOLTAGE:
		{		
			PMU_CTRL_VPA_SET_VOLTAGE *pVpaCtrl=&(data->rPMUVpaSetVoltage);
			regVal=PMU_Parameter_to_Value(ENC(cmd,pVpaCtrl->vpa),pVpaCtrl->voltage);
			switch(pVpaCtrl->vpaIdx)
			{
				case PMU_VPA0:
				{
					dcl_pmic6326_vpa_tuneh(regVal);
				}
				break;	
				case PMU_VPA1:
				{
					dcl_pmic6326_vpa_tunel(regVal);
				}
				break;					

				default:				
				return STATUS_UNSUPPORTED;
				break;			
			}			
		}
		break;		
		case VPA_SET_BAT_LOW:
		{
			PMU_CTRL_VPA_SET_BAT_LOW *pVpaCtrl=&(data->rPMUVpaSetBatLow);
			dcl_pmic6326_vpa_bat_low(pVpaCtrl->enable);
		}	
		break;
		//VIBR
		case VIBR_SET_DIMMING_ON_DUTY:
		{
			PMU_CTRL_VIBR_SET_DIMMING_ON_DUTY *pVibrCtrl=&(data->rPMUVibrSetDimmingOnDuty);
			dcl_pmic6326_vibr_enable(pVibrCtrl->duty);
		}
		//CHR
		case CHR_SET_CHR_EN:
		{
			PMU_CTRL_CHR_SET_CHR_EN *pChrCtrl=&(data->rPMUChrSetChrEn);		
			dcl_pmic6326_chr_chr_enable(pChrCtrl->enable);
		}
		break;
		case CHR_GET_IS_BATTERY_ON:
		{	//always return TRUE (why?)
			PMU_CTRL_CHR_GET_IS_BATTERY_ON *pChrCtrl=&(data->rPMUChrGetIsBatteryOn);		
			pChrCtrl->enable=DCL_TRUE;
		}
		break;			
		case CHR_SET_ADC_MEASURE_EN:
		{
			PMU_CTRL_CHR_SET_ADC_MEASURE_EN *pChrCtrl=&(data->rPMUChrSetAdcMeasureEn);
			dcl_pmic6326_adc_meas_on(pChrCtrl->enable);
		}	
		break;			
		case CHR_GET_CHR_DET_STATUS:
		{
			PMU_CTRL_CHR_GET_CHR_DET_STATUS *pChrCtrl=&(data->rPMUChrGetChrDetStatus);
			pChrCtrl->enable=dcl_pmic6326_chrdet_status();
		}	
		break;
		case CHR_GET_CHR_CURRENT:
		{
			PMU_CTRL_CHR_GET_CHR_CURRENT *pChrCtrl=&(data->rPMUChrGetChrCurrent);
			regVal=dcl_pmic6326_get_chr_current();
			pChrCtrl->current=PMU_Value_to_Parameter(ENC(CHR_SET_CHR_CURRENT,CHR),regVal);			
		}
		break;
		case CHR_SET_CHR_CURRENT:
		{
			PMU_CTRL_CHR_SET_CHR_CURRENT	*pChrCtrl=&(data->rPMUChrSetChrCurrent);
			regVal=PMU_Parameter_to_Value(ENC(cmd,CHR),pChrCtrl->current);
			dcl_pmic6326_chr_current(regVal);
		}
		break;		
		case CHR_GET_CHR_CURRENT_LIST:
		{
			PMU_CTRL_CHR_GET_CHR_CURRENT_LIST *pChrCtrl=&(data->rPMUChrGetChrCurrentList);
			pChrCtrl->pCurrentList=cs_vth;
			pChrCtrl->number=GETARRNUM(cs_vth);
		}
		break;	
		case CHR_SET_WDT_CLEAR:
		{
			dcl_pmic6326_watchdog_clear();
		}
		break;					
		//SPK
		case SPK_SET_EN:
		{
extern DCL_BOOL SpkLeftEn;
extern DCL_BOOL SpkRightEn;

			PMU_CTRL_SPK_SET_EN	*pSpkCtrl=&(data->rPMUSpkSetEn);

			if(SpkLeftEn==DCL_TRUE)
				dcl_pmic6326_spkl_enable(pSpkCtrl->enable);

			if(SpkRightEn==DCL_TRUE)
				dcl_pmic6326_spkr_enable(pSpkCtrl->enable);


		}
		break;		
		case ISINK_SET_DIMMING_ON_DUTY:
		{
			PMU_CTRL_ISINK_SET_DIMMING_ON_DUTY	*pIsinkCtrl=&(data->rPMUIsinkSetDimmingOnDuty);
			dcl_pmic6326_bl_dim_duty(pIsinkCtrl->duty);
		}
		break;			
		case ISINK_SET_FREQUENCY_DIVISION:
		{
			PMU_CTRL_ISINK_SET_FREQUENCY_DIVISION	*pIsinkCtrl=&(data->rPMUIsinkSetFrequencyDivision);
			dcl_pmic6326_bl_dim_div(pIsinkCtrl->div);
		}
		break;				
        case BL_GET_SUPPORT_LEVEL:
        {
            PMU_CTRL_BL_GET_SUPPORT_LEVEL *pBlCtrl = &(data->rPMUBlGetSupportLevel);
            pBlCtrl->blSupportLevel = bl_support_level;
        }
        break;
        case BL_GET_USE_PWM_QUERY:
        {
            PMU_CTRL_BL_GET_USE_PWM_QUERY *pBlCtrl = &(data->rPMUBlGetUsePwmQuery);
            pBlCtrl->blUsePwmQuery = bl_use_pwm;            
        }
        break;        
		case BOOST_SET_EN:
		{
			PMU_CTRL_BOOST_SET_EN	*pBoostCtrl=&(data->rPMUBoostSetEn);

			switch(pBoostCtrl->boost)
			{
				case BOOST1:
				{
					dcl_pmic6326_boost1_enable(pBoostCtrl->enable);
				}
				break;	
				case BOOST2:
				{
					dcl_pmic6326_boost2_enable(pBoostCtrl->enable);
				}
				break;					
				default:				
				return STATUS_UNSUPPORTED;
				break;					
			}
		}
		break;
		//KPLED
		case KPLED_SET_EN:
		{
			PMU_CTRL_KPLED_SET_EN	*pKpledCtrl=&(data->rPMUKpledSetEn);
			dcl_pmic6326_kp_enable(pKpledCtrl->enable);
		}
		break;			
		case KPLED_SET_FREQUENCY_DIVISION:
		{
			PMU_CTRL_KPLED_SET_FREQUENCY_DIVISION	*pKpledCtrl=&(data->rPMUKpledSetFrequencyDivision);
			dcl_pmic6326_kp_dim_div(pKpledCtrl->div);
		}
		break;		
		case KPLED_SET_DIMMING_ON_DUTY:
		{
			PMU_CTRL_KPLED_SET_DIMMING_ON_DUTY	*pKpledCtrl=&(data->rPMUKpledSetDimmingOnDuty);
			dcl_pmic6326_kp_dim_duty(pKpledCtrl->duty);
		}
		break;		
		case MISC_SET_REGISTER_VALUE:
		{			
			PMU_CTRL_MISC_SET_REGISTER_VALUE	*pChrCtrl=&(data->rPMUMiscSetRegisterValue);
                        if (pChrCtrl->offset>=PMIC_REG_NUM)
                              return STATUS_UNSUPPORTED;
			pmic6326_EM_reg_write((kal_uint8)pChrCtrl->offset,(kal_uint8)pChrCtrl->value);
		}
		break;	
		case MISC_GET_REGISTER_VALUE:
		{
			PMU_CTRL_MISC_GET_REGISTER_VALUE	*pChrCtrl=&(data->rPMUMiscGetRegisterValue);
                        if (pChrCtrl->offset>=PMIC_REG_NUM)
                              return STATUS_UNSUPPORTED;
			pChrCtrl->value= pmic6326_EM_reg_read((kal_uint8)pChrCtrl->offset);
		}
		break;			
		default:				
		return STATUS_UNSUPPORTED;
		break;
	}

	return STATUS_OK;

}

void dcl_pmic6326_init(void){
    kal_uint32 i;
    kal_bool result;
//    volatile kal_uint32 count;

	pmu_control_handler=PMIC6326_control_handler;
	pmu_parameter_size=GETARRNUM(pmu_parameter_table);

#if defined(PMIC6326_MASKIRQ_WHEN_PERFORM)
    gPMIC6326IRQMasked = KAL_FALSE;
#endif // #if defined(PMIC6326_MASKIRQ_WHEN_PERFORM)

    i2c_dual_init();

    pmic6326_eco_version = PMIC6326_ECO_4_VERSION;


    // Get PMIC6326 ECO version
    {
        kal_uint16 eco_version = 0;
        kal_uint8 tmp8;
        kal_bool result_tmp;
        // Low part of CID
        result_tmp = pmic6326_reg_read(CID_1_REG_INDEX, &tmp8);
        ASSERT(result_tmp);
        eco_version |= tmp8;
        // High part of CID
        result_tmp = pmic6326_reg_read(CID_2_REG_INDEX, &tmp8);
        ASSERT(result_tmp);
        eco_version |= (tmp8 << 8);
        if (eco_version == PMIC6326_E1_CID_CODE)
        {
            pmic6326_eco_version = PMIC6326_ECO_1_VERSION;
        }
        else if (eco_version == PMIC6326_E2_CID_CODE)
        {
            pmic6326_eco_version = PMIC6326_ECO_2_VERSION;
        }
        else if (eco_version == PMIC6326_E3_CID_CODE)
        {
            pmic6326_eco_version = PMIC6326_ECO_3_VERSION;
        }
        else if (eco_version == PMIC6326_E4_CID_CODE)
        {
            pmic6326_eco_version = PMIC6326_ECO_4_VERSION;
        }
        else
        {
            //ASSERT(0);// Assertion
        }

    }


// for (i=0;i<PMIC_REG_NUM;i++){
//  result = pmic6326_reg_read(i, &pmic6326_reg[i]);
// }
// It is OK to read intr status register here (The operation will cause PMIC6326 deassert intr
// We will trigger PMIC HISR if there is intr event
    for (i = 0;i < PMIC_REG_NUM;i++){
        // We skip intr state read back
        // If there is intr asserted, after enable EINT intr, pmic hisr will handle the intr
        if ( (i != 0x0B) && (i != 0x0C) && (i != 0x0D) && (i != 0x0E) ){
            result = pmic6326_reg_read(i, &pmic6326_reg[i]);
        }
    }


#if defined(DEBUG_PMIC6326_NO_CHARGER_WATCHDOG_TIMER)
    // Disable PMIC6326 charger watch dog timer
    dcl_pmic6326_wdt_enable(KAL_FALSE);
#else // #if defined(DEBUG_PMIC6326_NO_CHARGER_WATCHDOG_TIMER)
    // Eable PMIC6326 charger watch dog timer
    dcl_pmic6326_wdt_enable(KAL_TRUE);
    // Set WDT time out
    dcl_pmic6326_wdt_timeout(WDT_TIMEOUT_32_SEC);
#endif // #ifndef DEBUG_PMIC6326_NO_CHARGER_WATCHDOG_TIMER

    dcl_pmic6326_int_ctrl_1_enable(INT1_EN_ALL, KAL_FALSE);
    dcl_pmic6326_int_ctrl_2_enable(INT2_EN_ALL, KAL_TRUE);
    //dcl_pmic6326_int_ctrl_3_enable(INT_EN_CHRDET|INT_EN_OVP, KAL_TRUE);
    dcl_pmic6326_int_ctrl_3_enable(INT3_EN_ALL, KAL_FALSE);
    //dcl_pmic6326_int_ctrl_3_enable(INT_EN_CHRDET, KAL_TRUE);
    dcl_pmic6326_int_ctrl_3_enable(INT_EN_CHRDET | INT_EN_OVP, KAL_TRUE);




    dcl_pmic6326_vcore1_dvfs_0_eco3(12); // The setting will write 0x4E[7..4] with 0xC
	                            // ==> Same as the value in init setting document 0x4E[7..5] = 6
    dcl_pmic6326_vcore1_sleep_0_eco3(1);

    dcl_pmic6326_vcore1_dvfs_1_eco3(4); // The setting will write 0x57[7..4] with 0x4
	                            // ==> Same as the value in init setting document 0x57[7..5]= 2
    dcl_pmic6326_vcore1_sleep_1_eco3(0);


    dcl_pmic6326_vcore1_dvfs_step_inc(1);
    dcl_pmic6326_vcore1_dvfs_ramp_enable(KAL_TRUE);
    dcl_pmic6326_vcore1_dvfs_target_update(KAL_TRUE);

    dcl_pmic6326_vpa_oc_tune(3);

    dcl_pmic6326_vrf_calst(VRF_MAX_SLEW_RATE);
    dcl_pmic6326_vtcxo_calst(VTCXO_MAX_SLEW_RATE);
    dcl_pmic6326_v3gtx_calst(V3GTX_MAX_SLEW_RATE);
    dcl_pmic6326_v3grx_calst(V3GRX_MAX_SLEW_RATE);

    dcl_pmic6326_st_gear_vwifi3v3(ST_VWIFI3V3_800US);
    dcl_pmic6326_st_gear_vwifi2v8(ST_VWIFI2V8_800US);
    dcl_pmic6326_st_gear_vsdio(ST_VSDIO_800US);


	dcl_pmic6326_oc_gear_vwifi2v8(OC_VWIFI2V8_800US);
	dcl_pmic6326_oc_gear_vwifi3v3(OC_VWIFI3V3_800US);
    dcl_pmic6326_oc_gear_vsdio(OC_VSDIO_800US);

    dcl_pmic6326_boost1_sync_enable(KAL_TRUE);

    dcl_pmic6326_flash_i_tune(0xF);

    dcl_pmic6326_vcore2_plnmos_dis(KAL_TRUE);

    pmic6326_customization_init();


#if defined(PMIC_6326_CV_TRIM_CALIBRATION)
	{
		kal_uint8 tmp8, tmp2;
		kal_bool result_tmp;

		result_tmp = pmic6326_reg_read(EFUSE_BUFF_4_REG_INDEX, &tmp8);
		ASSERT(result_tmp);

		if ( (tmp8 & 0x20) != 0) // Bit5, 0x12[5]
		{
			//RG_CV_RT ==> 0x12[4..3]
			//RG_CV_TUNE ==> 0x12[2.0]
			result_tmp = pmic6326_reg_read(0x82, &tmp2);
			ASSERT(result_tmp);
			tmp2 &= ~(CHR_CV_RT_MASK | CHR_CV_TUNE_MASK);
			tmp2 |= (((tmp8 & 0x18) >> 3) << CHR_CV_RT_SHIFT);
			tmp2 |= (((tmp8 & 0x07) >> 0) << CHR_CV_TUNE_SHIFT);
			pmic6326_reg_write(0x82, (tmp2));
		}
	}
#endif // #if defined(PMIC_6326_CV_TRIM_CALIBRATION)

}









#endif //#if (defined(PMIC_6326_REG_API))

