/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ccci_sysmsgsvc_conf.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   user enum for ccci system message service
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *
 ****************************************************************************/

//- flag bit mask
//- 7 6 5 4 3 2 1 0 LSB
//- 0 0 0 x x x x x
//- | |
//- | |--> ilm local param neeeded
//- | 	
//- |--> ilm needed
//#if defined(__MODEM_CCCI_EXIST__)
#if defined(__HIF_CCCI_SUPPORT__)
//                    CCCI_MSG_ID                                       flag     ilm_msg_id
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L1_DORMANT,                    0,       0)                           //-0x100 add for L1 dormant mode used
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L1_SLEEPMASKING,               0,       0)                           //-0x101 add for L1 sleep/un-sleep mode used
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_MD_L4_TX_PWR_LEV_REQ,                    0xC0,    MSG_ID_L4C_MEAS_INFO_REQ)    //-0x102 add for L1 TX Power
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L1_QUERY_RF_TEMPERATURE,       0,       0)                           //-0x103 add for query L1 RF temperature
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L1_QUERY_3G_RF_TEMPERATURE,    0,       0)                           //-0x104 add for query L1 3G RF temperature
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L1_QUERY_AP_VOLTAGE,           0,       0)                           //-0x105 add for L1 to query AP volatage. Used for TX and RX.
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_LOCK_AP_26M,                   0,       0)                           //-0x106 add for USB to lock 26M on AP side. Only used in MT6280
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L4_SIM_INFO,                   0xC0,    MSG_ID_L4C_REGIONAL_PHONE_MODE_REQ)    //-0x107 add to send information to AP. Feature: Regional Animation. MD window: Hong
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_ICUSB_AP_NOTIFY,               0,       0)                           //-0x108 add for ICUSB user to do error handling
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L1_CRYSTAL_THERMAL_CHANGE,     0,       0)                           //-0x109 add for L1 thermal issue in 6571. MD window: Rick.Wu
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L4_TX_PWR_REDU_REQ,            0,       0)                           //-0x10A add for L4 for TX power reduction. MD window: Bob.Chiang
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_L1_THERMAL_TX_PWR_REDU_REQ,    0,       0)                           //-0x10B add for L1 Thermal Control. MD window: Chichen.Lee
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_MD_SLEEP_CONTROL,              0,       0)                           //-0x10C add for CPE project for MD Sleep Control. Rounter only 
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_EL1_DISABLE_MD_EMI_REQ,        0,       0)                           //-0x10D add for 6595 DVFS, EL1 DISABLE MD EMI ACCESS. MD window: Lewis Yu
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_MML1_UPDATE_AP_TPO_INFO,       0,       0)                           //-0x10E add for SWTP. MD window: Ryan-HN Chen 
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_MD2_UPDATE_AP_TPO_INFO,        0,       0)                           //-0x10F add for SWTP. MD window: Ryan-HN Chen 
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_MML1_QUERY_AP_TPO_INFO,        0,       0)                           //-0x110 add for SWTP. MD window: Ryan-HN Chen 
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_MD2_QUERY_AP_TPO_INFO,         0,       0)                           //-0x111 add for SWTP. MD window: Ryan-HN Chen 
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_SW_TPUT_THROTTLING,            0,       0)                           //-0x112 add for SW through put throttling. MD window: Peter Hsu

#ifdef ATEST_SYS_CCCI_SYS_MSG
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_UT_ONLY  ,                     0,       0)                           //- add for UT only
#endif
#ifdef __CCCI_IT_CTRL__
X_CCCI_SYSMSGSVC_CONF(CCMSG_ID_SYSMSGSVC_TEST_ONLY=0x1FF,               0,       0)                          //- add for IT only 
#endif
#endif


