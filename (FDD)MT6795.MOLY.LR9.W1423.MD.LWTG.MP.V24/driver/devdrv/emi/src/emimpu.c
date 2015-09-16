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
 *   emimpu.c
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *  This file implements EMIMPU handler
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * Add emimpu_violation_ctl() API to control interrupt mask and bypass assert.
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * check DHL_SUPPORT in emimpu.c
 *
 * removed!
 * removed!
 * Update RMPU implements code.
 * 
 ****************************************************************************/
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "reg_base.h"
#include "init.h"
#include "emi_hw_internal.h"
#include "intrCtrl.h"
#include "drv_hisr.h"
#include "cp15.h"
#include "mpu.h"
#if defined(__DHL_MODULE__)
#include "dhl_trace.h"
#endif

#if defined(MT6290) && defined(EMI_MPU_ENABLE)

#define MAX_EMI_RMPU_REGION_NUM		8
#define MAX_EMI_RMPU_DOMAIN_NUM		8

typedef struct rmpu_info {
	kal_uint8 R_VIO;
	kal_uint8 W_VIO;
	kal_uint8 OOR_VIO;
	kal_uint8 Domain_ID;
	kal_uint8 Region_Abort;
	kal_uint8 Secure;
	kal_uint16 Master_ID;
	kal_uint8 Burst_size;
	kal_uint8 Burst_len;
	kal_uint8 Burst_type;
	kal_uint8 Assert_mask;
	kal_uint32 Error_addr;
} rmpu_info_s;
static rmpu_info_s rmpu_status;

#define RMPU_DOMAIN0_SUB_ID_COUNT	5
const kal_uint16 rmpu_domain0_sub_id[RMPU_DOMAIN0_SUB_ID_COUNT]= {0x008, 0x010, 0x018, 0x020, 0x7FF};
const kal_uint16 rmpu_domain0_sub_mask[RMPU_DOMAIN0_SUB_ID_COUNT]= {0x020, 0x1E0, 0x000, 0x000, 0x000};
const kal_char rmpu_domain0_sub_str[] = {"ALC_Master,Cortex_R4,ARM7,Pre-fetch,NULL"};

#define RMPU_DOMAIN1_SUB_ID_COUNT	25
const kal_uint16 rmpu_domain1_sub_id[RMPU_DOMAIN1_SUB_ID_COUNT]= {0x001, 0x041, 0x021, 0x061, 0x009, 0x029, 0x049, 0x011, 0x031, 0x051, 0x071, 0x171, 0x271, 0x371, 0x091, 0x191, 0x291, 0x0B1, 0x1B1, 0x0D1, 0x039, 0x139, 0x1B9, 0x059, 0x079};
const kal_uint16 rmpu_domain1_sub_mask[RMPU_DOMAIN1_SUB_ID_COUNT]= {0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x080, 0x100, 0x100, 0x100, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x100, 0x000, 0x000, 0x000, 0x080, 0x000};
const kal_char rmpu_domain1_sub_str[] = {"APGDMA/APEHPI,APMCUSYS,MDMCUSYS,MDGDMA/DBGSYS,MDGDMA/DBGSYS,SDIO,ABM_ADOE,SSUSB,CLDMA_AP,CLDMA_MD,MSDC0,MD_NFI,IPSEC,AP_NFI,USB2.0,NIC,MSDC1,APGDMA,APEHPI,PFC,2G_MODEM_DMA,BYC_ACC_DMA,3G_MODEM_DMA,LTEL2_DMA,LTEL1_DMA/TDD_DMA"};

#define RMPU_DOMAIN3_SUB_ID_COUNT	13
const static kal_uint16 rmpu_domain3_sub_id[RMPU_DOMAIN3_SUB_ID_COUNT]= {0x003, 0x00B, 0x013, 0x01B, 0x05B, 0x09B, 0x0DB, 0x023, 0x063, 0x0A3, 0x02B, 0x06B, 0x033};
const static kal_uint16 rmpu_domain3_sub_mask[RMPU_DOMAIN3_SUB_ID_COUNT]= {0x040, 0x040, 0x040, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x040};
const static kal_char rmpu_domain3_sub_str[] = {"SSUSB,CLDMA_AP,CLDMA_MD,MSDC0,MD_NFI,IPSEC,AP_NFI,USB2.0,NIC,MSDC1,APGDMA,APEHPI,PFC"};

#define RMPU_DOMAIN4_SUB_ID_COUNT	5
const kal_uint16 rmpu_domain4_sub_id[RMPU_DOMAIN4_SUB_ID_COUNT]= {0x00C, 0x04C, 0x06C, 0x014, 0x01C};
const kal_uint16 rmpu_domain4_sub_mask[RMPU_DOMAIN4_SUB_ID_COUNT]= {0x000, 0x000, 0x000, 0x020, 0x000};
const kal_char rmpu_domain4_sub_str[] = {"2G_MODEM_DMA ,BYC_ACC_DMA,3G_MODEM_DMA,LTEL2_DMA,LTEL1_DMA/TDD_DMA"};

typedef struct rmpu_master_info {
	kal_uint8 sub_id_cnt;
	const kal_uint16 *sub_id_ptr;
	const kal_uint16 *sub_mask_ptr;
	const kal_char *sub_str_ptr;
} rmpu_master_info_s;
static rmpu_master_info_s rmpu_master_info[] = {
	{RMPU_DOMAIN0_SUB_ID_COUNT, rmpu_domain0_sub_id, rmpu_domain0_sub_mask, rmpu_domain0_sub_str},
	{RMPU_DOMAIN1_SUB_ID_COUNT, rmpu_domain1_sub_id, rmpu_domain1_sub_mask, rmpu_domain1_sub_str},
	{0, NULL, NULL, NULL},
	{RMPU_DOMAIN3_SUB_ID_COUNT, rmpu_domain3_sub_id, rmpu_domain3_sub_mask, rmpu_domain3_sub_str},
	{RMPU_DOMAIN4_SUB_ID_COUNT, rmpu_domain4_sub_id, rmpu_domain4_sub_mask, rmpu_domain4_sub_str},
	{0, NULL, NULL, NULL},
};
const kal_char rmpu_access_type_str[][4] = {"NSW", "NSR", "SW", "SR"};

void drv_emi_rmpu_get_master_name(kal_uint32 master_id, kal_char *str_ptr) {

	kal_uint8 idx, cnt = 0, domain = (master_id & 0x7);
	kal_uint16 offset = 0;
	
    switch(domain) {
        case 0x0:
			kal_mem_cpy(str_ptr, "MDMCU:", 6);
			str_ptr += 6;
            break;
        case 0x1:
			kal_mem_cpy(str_ptr, "MDPERI:", 7);
			str_ptr += 7;
			break;
		case 0x2:
			kal_mem_cpy(str_ptr, "APMCU", 6);
			return;
		case 0x3:
			kal_mem_cpy(str_ptr, "APPERI:", 7);
			str_ptr += 7;
			break;
		case 0x4:
			kal_mem_cpy(str_ptr, "MODEM:", 6);
			str_ptr += 6;
			break;
		case 0x5:
			kal_mem_cpy(str_ptr, "HARQ", 5);
			return;
		default:
			kal_mem_cpy(str_ptr, "Unknown", 8);
			return;
    }	
	for(idx = 0; idx < rmpu_master_info[domain].sub_id_cnt; idx++) {
		if(rmpu_master_info[domain].sub_id_ptr[idx] == (rmpu_status.Master_ID & ~rmpu_master_info[domain].sub_mask_ptr[idx])) {
			break;
		}
	}
	if(idx >= rmpu_master_info[domain].sub_id_cnt) {
		*str_ptr = '\0';
		return;
	}
	while(rmpu_master_info[domain].sub_str_ptr[offset]) {
		if(rmpu_master_info[domain].sub_str_ptr[offset] == ',') {
			cnt++;
			if(cnt > idx) {
				break;
			}
			offset++;
			continue;
		}
		if(cnt == idx) {
			*str_ptr = rmpu_master_info[domain].sub_str_ptr[offset];
			str_ptr++;
		}
		offset++;
	}
	*str_ptr = '\0';
}

kal_bool drv_emi_rmpu_get_status() {
	unsigned int data = 0;
	
	UNLOCK_EMI_REG();
	EMI_PD_REG_ACCESS_EN();
	data = DRV_Reg32(EMI_RMPUS);

	if(data & (EMI_RMPUS_REGION_MASK | EMI_RMPUS_OOR_VIO)) {
		rmpu_status.R_VIO = (data & EMI_RMPUS_W_VIO)?0:1;
		rmpu_status.W_VIO = (data & EMI_RMPUS_W_VIO)?1:0;
		rmpu_status.OOR_VIO = (data & EMI_RMPUS_OOR_VIO)?1:0;
		rmpu_status.Region_Abort = ((data & EMI_RMPUS_REGION_MASK) >> EMI_RMPUS_REGION_OFFSET);
		rmpu_status.Domain_ID = ((data & EMI_RMPUS_DOMAIN_ID_MASK) >> EMI_RMPUS_DOMAIN_ID_OFFSET);
		rmpu_status.Master_ID = ((data & EMI_RMPUS_MASTER_ID_MASK) >> EMI_RMPUS_MASTER_ID_OFFSET);
		
		data = DRV_Reg32(EMI_RMPUS_1);
		rmpu_status.Burst_size = ((data & EMI_RMPUS_1_BS_MASK) >> EMI_RMPUS_1_BS_OFFSET);
		rmpu_status.Burst_len = (((data & EMI_RMPUS_1_BL_MASK) >> EMI_RMPUS_1_BL_OFFSET) + 1);
		rmpu_status.Burst_type = ((data & EMI_RMPUS_1_BT_MASK) >> EMI_RMPUS_1_BT_OFFSET);
		rmpu_status.Secure = (data & EMI_RMPUS_1_SECURE)?0:1;
		rmpu_status.Error_addr = DRV_Reg32(EMI_RMPUT);
	}
	else {
		cp15_data_memory_barrier();
		DRV_WriteReg32(EMI_RMPUS, EMI_RMPUS_CLR);
		cp15_data_memory_barrier();
		LOCK_EMI_REG();
		return KAL_FALSE;
	}
	if(rmpu_status.Assert_mask) {
		cp15_data_memory_barrier();
		DRV_WriteReg32(EMI_RMPUS, EMI_RMPUS_CLR);
		cp15_data_memory_barrier();
	}
	EMI_PD_REG_ACCESS_DIS();
	LOCK_EMI_REG();

	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  EmiMpu_lisr
*
* DESCRIPTION
*  This function processes EMIMPU LISR.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void emimpu_lisr(void) {

    kal_bool RMPU_CODE_PROTECT_ERROR = KAL_FALSE;
    unsigned int ext1, ext2, ext3;
    ASSERT_DUMP_PARAM_T dump_param;
#if defined(__DHL_MODULE__)	
    kal_char string1[0x30], string2[0x20], *str_ptr;
    kal_uint32 idx;
#endif /* __DHL_MODULE__ */

    EMI_PD_REG_ACCESS_EN();
    ext1 = DRV_Reg32(EMI_RMPUS);
    ext2 = DRV_Reg32(EMI_RMPUS_1);
    ext3 = DRV_Reg32(EMI_RMPUT);
    EMI_PD_REG_ACCESS_DIS();

	IRQMask(IRQ_RAMC_CODE);
	if(drv_emi_rmpu_get_status() == KAL_TRUE) {
#if defined(__DHL_MODULE__)		
		drv_emi_rmpu_get_master_name(rmpu_status.Master_ID, string1);
		idx = (((rmpu_status.Secure << 1) | rmpu_status.R_VIO));
		kal_mem_cpy(string2, rmpu_access_type_str[idx], 4);
		dhl_print(TRACE_ERROR, DHL_USER_FLAG_NONE, MOD_SYSTEM, "[RMPU] MasterID:0x%x(%s)  ViolationAddr:0x%x(%s)\n\r", rmpu_status.Master_ID, string1, rmpu_status.Error_addr, string2);

		str_ptr = string1;
		for(idx = 0; idx < MAX_EMI_RMPU_REGION_NUM; idx++) {
			if(rmpu_status.Region_Abort & (1 << idx)) {
				*str_ptr++ = ('0' + idx);
				*str_ptr++ = ' ';
				*str_ptr = '\0';
			}
		}
		dhl_print(TRACE_ERROR, DHL_USER_FLAG_NONE, MOD_SYSTEM, "[RMPU] Region:%s  Domain:%d   Out-of-Range:%d", string1, rmpu_status.Domain_ID, rmpu_status.OOR_VIO);
#endif /* __DHL_MODULE__ */
		if(!rmpu_status.Assert_mask) {
			kal_mem_set(&dump_param, 0, sizeof(ASSERT_DUMP_PARAM_T));
			dump_param.addr[0] = (kal_uint32)(&rmpu_status);
			dump_param.len[0]  = sizeof(rmpu_info_s);
			dump_param.addr[1] = (kal_uint32)(EMI_RMPUA);
			dump_param.len[1]  = 0x80;
			dump_param.addr[2] = (kal_uint32)(EMI_RMPUI);
			dump_param.len[2]  = 0x40;
			dump_param.addr[3] = (kal_uint32)(EMI_RMPUM);
			dump_param.len[3]  = 0x40;
			EXT_ASSERT_DUMP(RMPU_CODE_PROTECT_ERROR, ext1, ext2, ext3, &dump_param);
		}
	}
	
	IRQClearInt(IRQ_RAMC_CODE);
	IRQUnmask(IRQ_RAMC_CODE);
}

/*************************************************************************
* FUNCTION
*  emimpu_init
*
* DESCRIPTION
*  This function initialized EMIMPU.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void emimpu_init(void) {

	UNLOCK_EMI_REG();
	DRV_Reg32(EMI_ARBW) |= 0x1;
	LOCK_EMI_REG();
	memset(&rmpu_status, 0, sizeof(rmpu_status));
	/* register LISR */
	IRQ_Register_LISR(IRQ_RAMC_CODE, emimpu_lisr, "EMIMPU");
	/* register HISR */
	/* set IRQ sensitivity */
	IRQSensitivity(IRQ_RAMC_CODE, LEVEL_SENSITIVE);
	IRQClearInt(IRQ_RAMC_CODE);
	/* unmask EMIMPU */
	IRQUnmask(IRQ_RAMC_CODE);
}

/*************************************************************************
* FUNCTION
*  emimpu_violation_ctl
*
* DESCRIPTION
*  This function to control RMPU violation response.
*
* PARAMETERS
*  int_en - interrupt enable
*  bypass_assert - bypass assert when violation happend
*
* RETURNS
*  none
*
*************************************************************************/
void emimpu_violation_ctl(kal_bool int_en, kal_bool bypass_assert) {

	if(bypass_assert) {
		rmpu_status.Assert_mask = 1;
		//can not bypass assert alone with HISR_PRIORITY_ERROR_RMPU
		int_en = KAL_FALSE;
	}
	else {
		rmpu_status.Assert_mask = 0;
	}
	UNLOCK_EMI_REG();
	if(int_en) {
		DRV_Reg32(EMI_ARBW) |= 0x1;
	}
	else {
		DRV_Reg32(EMI_ARBW) &= 0xFFFFFFFE;
	}
	LOCK_EMI_REG();
}
#else /* MT6290 && EMI_MPU_ENABLE */

void emimpu_lisr(void) {}
void emimpu_init(void) {}

#endif /* MT6290 && EMI_MPU_ENABLE */
