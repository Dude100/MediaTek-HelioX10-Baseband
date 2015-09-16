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
/*******************************************************************************
 * Filename:
 * ---------
 *    usim_dummy_driver.h
 *
 * Project:
 * --------
 *    MONZA
 *
 * Description:
 * ------------
 *    This file defines the data structure, enum and constant for dummy driver
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#ifndef SIM_DUMMY_DRIVER_H
#define SIM_DUMMY_DRIVER_H

#include <stdio.h>
#include <stdlib.h>

/* Driver related*/
#include "drv_comm.h"
#include "dcl.h"

 /* Please enter your SIM_CARD folder */
#define SIM_ROOT_DIR   "E:\\home\\mtkxxxxx\\MoDIS\\"
#ifdef __UCS2_SIM__
#define SIM_CARD_DIR    L"SIM_CARD\\"
#define MAX_FILEPATH_LEN (260 * 2)
#else /* __UCS2_SIM__ */ 
#define SIM_CARD_DIR    "SIM_CARD\\"
#define MAX_FILEPATH_LEN 260
#endif /* __UCS2_SIM__ */ 

#ifndef __UE_SIMULATOR__
  #define SIM_CARD_CONFIG_FILE "Config.bin"
#else
  #define SIM_CARD_CONFIG_FILE "Config_usim_nw.bin"
#endif

#define SIM_CARD_2_CONFIG_FILE "Config_2.bin"
#define SIM_CARD_3_CONFIG_FILE "Config_3.bin"
#define SIM_CARD_4_CONFIG_FILE "Config_4.bin"
#define USIM_AID_LEN 16

/* Define the UICC file path from MF */
#define SIM_DRV_PATH_MF_ID   {0x3F,0x00,0x00,0x00,0x00,0x00}
#define SIM_DRV_PATH_GSM_ID   {0x7F,0x20,0x00,0x00,0x00,0x00}
#define SIM_DRV_PATH_TELECOM_ID   {0x7F,0x10,0x00,0x00,0x00,0x00}
#define SIM_DRV_PATH_IRIDIUM_ID   {0x7F,0x20,0x5F,0x30,0x00,0x00}
#define SIM_DRV_PATH_GLOBST_ID   {0x7F,0x20,0x5F,0x31,0x00,0x00}
#define SIM_DRV_PATH_ICO_ID   {0x7F,0x20,0x5F,0x32,0x00,0x00}
#define SIM_DRV_PATH_ACES_ID   {0x7F,0x20,0x5F,0x33,0x00,0x00}
#define SIM_DRV_PATH_EIA_ID   {0x7F,0x20,0x5F,0x40,0x00,0x00}
#define SIM_DRV_PATH_CTS_ID   {0x7F,0x20,0x5F,0x60,0x00,0x00}
#define SIM_DRV_PATH_SOLSA_ID   {0x7F,0x20,0x5F,0x70,0x00,0x00}
#define SIM_DRV_PATH_MEXE_ID   {0x7F,0x20,0x5F,0x3C,0x00,0x00}
#define SIM_DRV_PATH_GRAPHICS_ID   {0x7F,0x10,0x5F,0x50,0x00,0x00}
#define SIM_DRV_PATH_ICCID_ID   {0x2F,0xE2,0x00,0x00,0x00,0x00}
#define SIM_DRV_PATH_ELP_ID   {0x2F,0x05,0x00,0x00,0x00,0x00}
#define SIM_DRV_PATH_SAI_ID   {0x7F,0x20,0x5F,0x70,0x4F,0x30}
#define SIM_DRV_PATH_SLL_ID   {0x7F,0x20,0x5F,0x70,0x4F,0x31}
#define SIM_DRV_PATH_MEXE_ST_ID   {0x7F,0x20,0x5F,0x3C,0x4F,0x40}
#define SIM_DRV_PATH_ORPK_ID   {0x7F,0x20,0x5F,0x3C,0x4F,0x41}
#define SIM_DRV_PATH_ARPK_ID   {0x7F,0x20,0x5F,0x3C,0x4F,0x42}
#define SIM_DRV_PATH_TPRPK_ID   {0x7F,0x20,0x5F,0x3C,0x4F,0x43}
#define SIM_DRV_PATH_IMG_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x20}
#define SIM_DRV_PATH_LP_ID   {0x7F,0x20,0x6F,0x05,0x00,0x00}
#define SIM_DRV_PATH_IMSI_ID   {0x7F,0x20,0x6F,0x07,0x00,0x00}
#define SIM_DRV_PATH_KC_ID   {0x7F,0x20,0x6F,0x20,0x00,0x00}
#define SIM_DRV_PATH_PLMNSEL_ID   {0x7F,0x20,0x6F,0x30,0x00,0x00}
#define SIM_DRV_PATH_HPLMN_ID   {0x7F,0x20,0x6F,0x31,0x00,0x00}
#define SIM_DRV_PATH_ACMAX_ID   {0x7F,0x20,0x6F,0x37,0x00,0x00}
#define SIM_DRV_PATH_SST_ID   {0x7F,0x20,0x6F,0x38,0x00,0x00}
#define SIM_DRV_PATH_ACM_ID   {0x7F,0x20,0x6F,0x39,0x00,0x00}
#define SIM_DRV_PATH_GID1_ID   {0x7F,0x20,0x6F,0x3E,0x00,0x00}
#define SIM_DRV_PATH_GID2_ID   {0x7F,0x20,0x6F,0x3F,0x00,0x00}
#define SIM_DRV_PATH_SPN_ID   {0x7F,0x20,0x6F,0x46,0x00,0x00}
#define SIM_DRV_PATH_PUCT_ID   {0x7F,0x20,0x6F,0x41,0x00,0x00}
#define SIM_DRV_PATH_CBMI_ID   {0x7F,0x20,0x6F,0x45,0x00,0x00}
#define SIM_DRV_PATH_BCCH_ID   {0x7F,0x20,0x6F,0x74,0x00,0x00}
#define SIM_DRV_PATH_ACC_ID   {0x7F,0x20,0x6F,0x78,0x00,0x00}
#define SIM_DRV_PATH_FPLMN_ID   {0x7F,0x20,0x6F,0x7B,0x00,0x00}
#define SIM_DRV_PATH_LOCI_ID   {0x7F,0x20,0x6F,0x7E,0x00,0x00}
#define SIM_DRV_PATH_AD_ID   {0x7F,0x20,0x6F,0xAD,0x00,0x00}
#define SIM_DRV_PATH_PHASE_ID   {0x7F,0x20,0x6F,0xAE,0x00,0x00}
#define SIM_DRV_PATH_VGCS_ID   {0x7F,0x20,0x6F,0xB1,0x00,0x00}
#define SIM_DRV_PATH_VGCSS_ID   {0x7F,0x20,0x6F,0xB2,0x00,0x00}
#define SIM_DRV_PATH_VBS_ID   {0x7F,0x20,0x6F,0xB3,0x00,0x00}
#define SIM_DRV_PATH_VBSS_ID   {0x7F,0x20,0x6F,0xB4,0x00,0x00}
#define SIM_DRV_PATH_EMLPP_ID   {0x7F,0x20,0x6F,0xB5,0x00,0x00}
#define SIM_DRV_PATH_AAEM_ID   {0x7F,0x20,0x6F,0xB6,0x00,0x00}
#define SIM_DRV_PATH_CBMID_ID   {0x7F,0x20,0x6F,0x48,0x00,0x00}
#define SIM_DRV_PATH_ECC_ID   {0x7F,0x20,0x6F,0xB7,0x00,0x00}
#define SIM_DRV_PATH_CBMIR_ID   {0x7F,0x20,0x6F,0x50,0x00,0x00}
#define SIM_DRV_PATH_DCK_ID   {0x7F,0x20,0x6F,0x2C,0x00,0x00}
#define SIM_DRV_PATH_CNL_ID   {0x7F,0x20,0x6F,0x32,0x00,0x00}
#define SIM_DRV_PATH_NIA_ID   {0x7F,0x20,0x6F,0x51,0x00,0x00}
#define SIM_DRV_PATH_KCGPRS_ID   {0x7F,0x20,0x6F,0x52,0x00,0x00}
#define SIM_DRV_PATH_LOCIGPRS_ID   {0x7F,0x20,0x6F,0x53,0x00,0x00}
#define SIM_DRV_PATH_SUME_ID   {0x7F,0x20,0x6F,0x54,0x00,0x00}
#define SIM_DRV_PATH_PLMNWACT_ID   {0x7F,0x20,0x6F,0x60,0x00,0x00}
#define SIM_DRV_PATH_OPLMNWACT_ID   {0x7F,0x20,0x6F,0x61,0x00,0x00}
#define SIM_DRV_PATH_HPLMNACT_ID   {0x7F,0x20,0x6F,0x62,0x00,0x00}
#define SIM_DRV_PATH_CPBCCH_ID   {0x7F,0x20,0x6F,0x63,0x00,0x00}
#define SIM_DRV_PATH_INVSCAN_ID   {0x7F,0x20,0x6F,0x64,0x00,0x00}
#define SIM_DRV_PATH_VM_WAIT_ID   {0x7F,0x20,0x6F,0x11,0x00,0x00}
#define SIM_DRV_PATH_CPHS_SST_ID   {0x7F,0x20,0x6F,0x12,0x00,0x00}
#define SIM_DRV_PATH_CF_FLAG_ID   {0x7F,0x20,0x6F,0x13,0x00,0x00}
#define SIM_DRV_PATH_OP_STRING_ID   {0x7F,0x20,0x6F,0x14,0x00,0x00}
#define SIM_DRV_PATH_CSP_ID   {0x7F,0x20,0x6F,0x15,0x00,0x00}
#define SIM_DRV_PATH_CPHS_INFO_ID   {0x7F,0x20,0x6F,0x16,0x00,0x00}
#define SIM_DRV_PATH_MAILBOX_NUM_ID   {0x7F,0x20,0x6F,0x17,0x00,0x00}
#define SIM_DRV_PATH_OP_SHORTFORM_ID   {0x7F,0x20,0x6F,0x18,0x00,0x00}
#define SIM_DRV_PATH_INFO_NUM_ID   {0x7F,0x20,0x6F,0x19,0x00,0x00}
#define SIM_DRV_PATH_ADN_ID   {0x7F,0x10,0x6F,0x3A,0x00,0x00}
#define SIM_DRV_PATH_FDN_ID   {0x7F,0x10,0x6F,0x3B,0x00,0x00}
#define SIM_DRV_PATH_SMS_ID   {0x7F,0x10,0x6F,0x3C,0x00,0x00}
#define SIM_DRV_PATH_CCP_ID   {0x7F,0x10,0x6F,0x3D,0x00,0x00}
#define SIM_DRV_PATH_ECCP_ID   {0x7F,0x10,0x6F,0x4F,0x00,0x00}
#define SIM_DRV_PATH_MSISDN_ID   {0x7F,0x10,0x6F,0x40,0x00,0x00}
#define SIM_DRV_PATH_SMSP_ID   {0x7F,0x10,0x6F,0x42,0x00,0x00}
#define SIM_DRV_PATH_SMSS_ID   {0x7F,0x10,0x6F,0x43,0x00,0x00}
#define SIM_DRV_PATH_LND_ID   {0x7F,0x10,0x6F,0x44,0x00,0x00}
#define SIM_DRV_PATH_SDN_ID   {0x7F,0x10,0x6F,0x49,0x00,0x00}
#define SIM_DRV_PATH_EXT1_ID   {0x7F,0x10,0x6F,0x4A,0x00,0x00}
#define SIM_DRV_PATH_EXT2_ID   {0x7F,0x10,0x6F,0x4B,0x00,0x00}
#define SIM_DRV_PATH_EXT3_ID   {0x7F,0x10,0x6F,0x4C,0x00,0x00}
#define SIM_DRV_PATH_BDN_ID   {0x7F,0x10,0x6F,0x4D,0x00,0x00}
#define SIM_DRV_PATH_EXT4_ID   {0x7F,0x10,0x6F,0x4E,0x00,0x00}
#define SIM_DRV_PATH_SMSR_ID   {0x7F,0x10,0x6F,0x47,0x00,0x00}
#define SIM_DRV_PATH_CMI_ID   {0x7F,0x20,0x6F,0x58,0x00,0x00}
#define SIM_DRV_PATH_IMG_1_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x01}
#define SIM_DRV_PATH_IMG_2_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x02}
#define SIM_DRV_PATH_IMG_3_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x03}
#define SIM_DRV_PATH_IMG_4_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x04}
#define SIM_DRV_PATH_IMG_5_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x05}
#define SIM_DRV_PATH_IMG_6_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x06}
#define SIM_DRV_PATH_IMG_7_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x07}
#define SIM_DRV_PATH_IMG_8_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x08}
#define SIM_DRV_PATH_IMG_9_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x09}
#define SIM_DRV_PATH_IMG_A_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x0A}
#define SIM_DRV_PATH_IMG_B_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x0B}
#define SIM_DRV_PATH_IMG_C_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x0C}
#define SIM_DRV_PATH_IMG_D_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x0D}
#define SIM_DRV_PATH_IMG_E_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x0E}
#define SIM_DRV_PATH_IMG_F_ID   {0x7F,0x10,0x5F,0x50,0x4F,0x0F}
#define SIM_DRV_PATH_VID_ID   {0x7F,0x43,0x00,0x00,0x00,0x00}
/* HomeZone Support */
#define SIM_DRV_PATH_HZ_ID   {0x7F,0x43,0x6F,0x60,0x00,0x00}
#define SIM_DRV_PATH_HZ_CACHE1_ID   {0x7F,0x43,0x6F,0x61,0x00,0x00}
#define SIM_DRV_PATH_HZ_CACHE2_ID   {0x7F,0x43,0x6F,0x62,0x00,0x00}
#define SIM_DRV_PATH_HZ_CACHE3_ID   {0x7F,0x43,0x6F,0x63,0x00,0x00}
#define SIM_DRV_PATH_HZ_CACHE4_ID   {0x7F,0x43,0x6F,0x64,0x00,0x00}
/* ENS support mtk01488 */
#define SIM_DRV_PATH_ENS_DF_7F66_ID {0x7F,0x66,0x00,0x00,0x00,0x00}
#define SIM_DRV_PATH_ENS_DF_5F40_ID {0x7F,0x66,0x5F,0x30,0x00,0x00}
#define SIM_DRV_PATH_ENS_ACTING_HPLMN {0x7F, 0x66, 0x5F, 0x30, 0x4F, 0x34}
#define SIM_DRV_PATH_ENS_TERMINAL_SUPPORT_TABLE  {0x7F, 0x66, 0x6F, 0xD2, 0x00, 0x00}
#define SIM_DRV_PATH_PNN_ID   {0x7F,0x20,0x6F,0xC5,0x00,0x00}
#define SIM_DRV_PATH_OPL_ID   {0x7F,0x20,0x6F,0xC6,0x00,0x00}
#define SIM_DRV_PATH_MBDN_ID   {0x7F,0x20,0x6F,0xC7,0x00,0x00}
#define SIM_DRV_PATH_EXT6_ID   {0x7F,0x20,0x6F,0xC8,0x00,0x00}
#define SIM_DRV_PATH_MBI_ID   {0x7F,0x20,0x6F,0xC9,0x00,0x00}
#define SIM_DRV_PATH_MWIS_ID   {0x7F,0x20,0x6F,0xCA,0x00,0x00}
#define SIM_DRV_PATH_CFIS_ID   {0x7F,0x20,0x6F,0xCB,0x00,0x00}
#define SIM_DRV_PATH_EXT7_ID   {0x7F,0x20,0x6F,0xCC,0x00,0x00}
#define SIM_DRV_PATH_SPDI_ID   {0x7F,0x20,0x6F,0xCD,0x00,0x00}
#define SIM_DRV_PATH_MMSN_ID   {0x7F,0x20,0x6F,0xCE,0x00,0x00}
#define SIM_DRV_PATH_EXT8_ID   {0x7F,0x20,0x6F,0xCF,0x00,0x00}
#define SIM_DRV_PATH_MMSICP_ID   {0x7F,0x20,0x6F,0xD0,0x00,0x00}
#define SIM_DRV_PATH_MMSUP_ID   {0x7F,0x20,0x6F,0xD1,0x00,0x00}
#define SIM_DRV_PATH_MMSUCP_ID   {0x7F,0x20,0x6F,0xD2,0x00,0x00}
#define SIM_DRV_PATH_DIR_ID   {0x2F,0x00,0x00,0x00,0x00,0x00}
#define SIM_DRV_PATH_ARR_ID   {0x2F,0x06,0x00,0x00,0x00,0x00}
#define SIM_DRV_PATH_NONE_ID {0x00,0x00,0x00,0x00,0x00,0x00}

#define MODIS_SIM_HEAD_SPACE 25
#define MODIS_SIM_CHV1_OFFSET (MODIS_SIM_HEAD_SPACE)
#define MODIS_SIM_CHV2_OFFSET (MODIS_SIM_CHV1_OFFSET+16)
#define MODIS_SIM_UBCHV1_OFFSET (MODIS_SIM_CHV2_OFFSET+16)
#define MODIS_SIM_UBCHV2_OFFSET (MODIS_SIM_UBCHV1_OFFSET+16)
#define SIM_CHV1_COUNT_OFFSET 18
#define SIM_UBCHV1_COUNT_OFFSET 19
#define SIM_CHV2_COUNT_OFFSET 20
#define SIM_UBCHV2_COUNT_OFFSET 21
#define SIM_FILE_CHAR_OFFSET 13

typedef struct
{
    kal_uint8 path[6];
} sim_card_path_info_struct;

typedef struct
{
    /* The first 256 bytes */
    kal_char file_name[16];
    kal_uint8 path[6]; //mtk01616_110419 : TODO : to support read long path in Modis
    kal_uint8 fcp_length;
    kal_uint8 fcp_tmp[233];
    /* ------256 bytes ------ */
} uicc_file_meta_struct;

typedef struct
{
    kal_uint8 data[256];
} uicc_file_data_struct;

typedef struct
{
    kal_bool is_uicc_inserted;
    kal_uint8 aid_len;
    kal_uint8 aid[USIM_AID_LEN];
    kal_uint8 current_path[6];
    kal_uint8 temp_path[6];
    kal_uint8 atr_historical[15];
    kal_char cPath[MAX_FILEPATH_LEN];
    kal_char cFile[MAX_FILEPATH_LEN];
    kal_uint8 buf[256];
    FILE *cfPtr;
    uicc_file_meta_struct meta_data;
    kal_uint8 previous_cmd;
    kal_uint8 sim_status[23];   /* Store SIM status of current DF */
    kal_uint8 usim_status_len;
    kal_uint8 usim_status[255];
    kal_bool is_resource_assigned; 
    DCL_SIM_CONFIG_AP_TYPE	driver_config;	
	kal_uint8 sim_test_num;// used in modis only
} usim_test_context_struct;

#ifdef __SIM_UNIT_TEST__
typedef enum
{
    SIM_CTRL_UT_CMD_RST_UICC_STATUS,
    SIM_CTRL_UT_CMD_RST_PIN_CNR,
    SIM_CTRL_UT_CMD_RST_CHV_CNR,	
    SIM_CTRL_UT_CMD_END
} DCL_CTRL_UT_CMD;

typedef struct
{
	kal_bool pin1_enabled;
	kal_bool pin2_enabled;
} SIM_CTRL_RST_PIN_CNR_struct;

typedef struct
{
	kal_bool pin1_enabled;
} SIM_CTRL_RST_CHV_CNR_struct;

typedef union
{
   SIM_CTRL_RST_PIN_CNR_struct		rSIMRstPINCnr; 
   SIM_CTRL_RST_CHV_CNR_struct	rSIMRstCHVCnr;   
} DCL_CTRL_UT_DATA;

#endif

extern kal_uint16 L1sim_Cmd(kal_uint8 *, kal_uint16, kal_uint8 *, kal_uint16 *, kal_uint8 *);
extern usim_test_context_struct *UsimCardPtr;

/*Utility*/
extern FILE *sim_fopen(const char *filename, const char *type);
extern kal_bool is_ef_selected(void);
extern kal_char *UsimSetPath(const char *file_name);
extern kal_bool UsimPath2Name(kal_char *name, kal_uint8 *path, kal_uint8 pathlen);
extern kal_bool UsimLoadMeta(void);
extern kal_bool UsimOpenFile(kal_uint8 *file_id, kal_uint8 len);
extern FILE *UsimSysOpenFile(kal_uint8 *file_id, kal_uint8 len);

/*DCL 1st level API*/
extern DCL_STATUS DclSIM_Initialize(void);
extern DCL_HANDLE DclSIM_Open(DCL_DEV dev, DCL_FLAGS flags);
extern DCL_STATUS DclSIM_Close(DCL_HANDLE handle);
extern DCL_STATUS DclSIM_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
extern DCL_STATUS DclSIM_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
#ifdef __SIM_UNIT_TEST__
extern DCL_STATUS DclSIM_UT_Control(DCL_HANDLE handle, DCL_CTRL_UT_CMD cmd, DCL_CTRL_UT_DATA *data);
#endif

/*DCL 2st level API*/
extern DCL_STATUS DCL_SIM_CTRL_API_RST(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
extern DCL_STATUS DCL_SIM_CTRL_API_SET_CLK_STOP_MODE(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
extern DCL_STATUS DCL_SIM_CTRL_API_GET_CARD_SPEED(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
extern DCL_STATUS DCL_SIM_CTRL_API_CMD(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
extern DCL_STATUS DCL_SIM_CTRL_API_PWOFF(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
extern DCL_STATUS DCL_SIM_CTRL_API_GET_CARD_INFO(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);	
extern DCL_STATUS DCL_SIM_CTRL_API_QUERY_9000(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

#ifdef __SIM_UNIT_TEST__
extern DCL_STATUS DCL_SIM_CTRL_UT_API_RST_UICC_STATUS(DCL_HANDLE handle, DCL_CTRL_UT_CMD cmd, DCL_CTRL_UT_DATA * data);
extern DCL_STATUS DCL_SIM_CTRL_UT_API_RST_PIN_CNR(DCL_HANDLE handle, DCL_CTRL_UT_CMD cmd, DCL_CTRL_UT_DATA * data);
extern DCL_STATUS DCL_SIM_CTRL_UT_API_RST_CHV_CNR(DCL_HANDLE handle, DCL_CTRL_UT_CMD cmd, DCL_CTRL_UT_DATA * data);
#endif

/*DCL 3st level API*/
extern DCL_SIM_STATUS L1sim_Reset(DCL_SIM_POWER ExpectVolt, DCL_SIM_POWER *resultVolt);
extern void L1usim_Get_Card_Info(DCL_SIM_INFO *info);
#ifdef __SIM_UNIT_TEST__
extern void L1sim_reset_uicc_status(void);
extern void L1sim_reset_chv_counter(kal_bool pin1_enabled);
extern void L1sim_config_card(kal_bool is_inserted);
#endif

#endif /* SIM_DUMMY_DRIVER_H */ 

