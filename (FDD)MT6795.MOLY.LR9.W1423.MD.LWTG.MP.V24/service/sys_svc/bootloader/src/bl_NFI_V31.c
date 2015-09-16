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
 *
 * Filename:
 * ---------
 *  bl_NFI_V31.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   NAND flash driver for NFI V3.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


/*******************************************************************************
 * Include Header Files
 *******************************************************************************/

#if defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__)

#if defined(__NFI_VERSION3_1__)
#if defined(__NFI_SHARED_DRV__)
#include "NAND_MTD_FDM50_internal.h"
/* Macros for register read/write */
#define DRV_WriteReg(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#define DRV_Reg(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_WriteReg16(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#define DRV_Reg16(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_WriteReg32(addr,data)   ((*(volatile kal_uint32 *)(addr)) = (kal_uint32)(data))
#define DRV_Reg32(addr)             (*(volatile kal_uint32 *)(addr))
#define DRV_WriteReg8(addr,data)    ((*(volatile kal_uint8 *)(addr)) = (kal_uint8)(data))
#define DRV_Reg8(addr)              (*(volatile kal_uint8 *)(addr))
#if defined(MT6276)
#define MCU_CG_CLR1     		((volatile UINT16P)(CONFIG_base+0x324))
#elif (defined(MT6256))
#define MCU_CG_CLR1     		((volatile UINT16P)(CONFIG_base+0x724))
#elif (defined(MT6255))
#define MCU_SFC_CTRL_SET 		((volatile UINT32P)(CONFIG_base+0x61C))
#define MCU_CG_CLR1     		((volatile UINT16P)(CONFIG_base+0x724))
#elif defined(MT6573)
#define APMCU_CG_CLR1           ((volatile UINT32P)(CONFIG_base+0x0318))    
#endif 
/**********************************************************
Description : NFI_ReadID
Remark      : content in
              NFI_PAGEFMT, NFI_CNFG, NFI_ADDRNOB, NFI_CON,
              NFI_COLADDR, and NFI_ROWADDR will be changed 
***********************************************************/
void NFI_ReadID(kal_uint32 id_num, kal_uint8* id_data)
{
    kal_uint32 idx;
    kal_uint32 ID[2];
    kal_uint32 Backup_NFI_PAGEFMT;
    //NFIReconfigure();
	  // Power-on NFI.
	  #if defined(MT6276)
	  	DRV_WriteReg16(MCU_CG_CLR1, 0x1000);
	  #elif (defined(MT6256))
	  	DRV_WriteReg16(MCU_CG_CLR1, 0x1000);
	  #elif (defined(MT6255))
	  	DRV_WriteReg16(MCU_CG_CLR1, 0x1000);	
	    *MCU_SFC_CTRL_SET	&= ~0x20;				// Disable NLD share with SF.
	  #elif defined(MT6573)
	      DRV_WriteReg32(APMCU_CG_CLR1, 0x80);    
	  #endif 	

   	while(0 != DRV_Reg(NFI_MASTERSTA));

    *NFI_CON = CON_FIFO_FLUSH|CON_NFI_RST;
  	while( (*NFI_STA) & (STA_NFI_FSM_MASK|STA_NAND_FSM_MASK) );

    Backup_NFI_PAGEFMT = *NFI_PAGEFMT;    
    *NFI_PAGEFMT = PAGEFMT_512_8BIT;
		*NFI_CNFG = CNFG_OP_SRD | CNFG_READ_EN;
		*NFI_CMD = RD_ID_CMD;
		while ((*NFI_STA) & STA_CMD_STATE);

   	*NFI_COLADDR = 0;
		*NFI_ROWADDR = 0;
		*NFI_ADDRNOB = 1;
		while ((*NFI_STA) & STA_ADDR_STATE);

		*NFI_CON = CON_NFI_SRD;
		while((*NFI_STA) & STA_DATAR_STATE);
		for(idx = 0 ; idx < 2 ; idx++)
		{
			while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) );
			ID[idx] = *NFI_DATAR;
		}
		*NFI_CON = 0x0;
    *NFI_PAGEFMT = Backup_NFI_PAGEFMT;		
    id_data[0] = (kal_uint8)ID[0];
    id_data[1] = (kal_uint8)(ID[0]>>8);
    id_data[2] = (kal_uint8)(ID[0]>>16);
    id_data[3] = (kal_uint8)(ID[0]>>24);
    id_data[4] = (kal_uint8)ID[1];
    id_data[5] = (kal_uint8)(ID[1]>>8);
    id_data[6] = (kal_uint8)(ID[1]>>16);
    id_data[7] = (kal_uint8)(ID[1]>>24);
   
}
#else //__USE_NFI_SHARED_DRV__
//RHR remove#include "kal_release.h"
#include "NAND_MTD_FDM50_internal.h"
#include "ECC_hw.h"
#include "NAND_DAL.h"
#include "NAND_DAL_internal.h"
//RHR remove#include "fat_fs.h"
//RHR remove#include <bl_FOTA.h>
#include <bl_loader.h>

// Add for RHR 
//RHR remove#include "bl_types.h"
#include "reg_base.h"
#include "sw_types.h"
#include "nfb_header.h"
//RHR remove#include "kal_non_specific_general_types.h"
#include "fs_errcode.h"
#include "kal_general_types.h"
#include "kal_internal_api.h"
// Add for RHR 
/*
typedef kal_bool			bool;
typedef unsigned char       U8;
typedef signed char         S8;
typedef unsigned short      U16;
typedef signed short        S16;
typedef unsigned int        U32;
typedef signed int          S32;
typedef unsigned long long  U64;
typedef signed long long    S64;

typedef unsigned char       US8;
typedef unsigned short      US16;
typedef unsigned int        US32;

typedef volatile unsigned char *     P_U8;
typedef volatile signed char *       P_S8;
typedef volatile unsigned short *    P_U16;
typedef volatile signed short *      P_S16;
typedef volatile unsigned int *      P_U32;
typedef volatile signed int *        P_S32;
typedef unsigned long long *         P_U64;
typedef signed long long *           P_S64;
*/

#if defined(MT6276)
#define MCU_CG_CLR1     		((volatile UINT16P)(CONFIG_base+0x324))
#elif (defined(MT6256))
#define MCU_CG_CLR1     		((volatile UINT16P)(CONFIG_base+0x724))
#elif (defined(MT6255))
#define MCU_SFC_CTRL_SET 		((volatile UINT32P)(CONFIG_base+0x61C))
#define MCU_CG_CLR1     		((volatile UINT16P)(CONFIG_base+0x724))
#elif (defined(MT6280))
	#define APMCU_CG_CLR     		  ((volatile UINT32P)(AP_CONFIG_base+0x0008))
#elif defined(MT6573)
#define APMCU_CG_CLR1           ((volatile UINT32P)(CONFIG_base+0x0318))    
#endif 

#if defined(MT6280)
#define BL_ACCON      			(0x30035446)
#else
#define BL_ACCON      			(0x00033333)
#endif
#define BL_WRITE_CNFG 			(CNFG_OP_PRGM)
#define BL_READ_CNFG  			(CNFG_READ_EN|CNFG_OP_READ)
#define BL_SRD_CNFG   			(CNFG_READ_EN|CNFG_BYTE_RW|CNFG_OP_SRD)
#define BL_ERASE_CNFG 			(CNFG_OP_ERASE)
#define MCU_CYCLE_TIME_NS 		(3)

#define NORMAL_BUSY_PERIOD   	(500000/MCU_CYCLE_TIME_NS)
#define DATA_TRANSFER_PERIOD 	(6000000/MCU_CYCLE_TIME_NS)
#define PROG_BUSY_PERIOD     	(700000/MCU_CYCLE_TIME_NS)
#define ERASE_BUSY_PERIOD    	(3000000/MCU_CYCLE_TIME_NS)

#define ECC_PARITY_NUM        (156)

#define ECC_PARITY_BITS       (13)

/* Macros for register read/write */
#define DRV_WriteReg(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#define DRV_Reg(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_WriteReg16(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#define DRV_Reg16(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_WriteReg32(addr,data)   ((*(volatile kal_uint32 *)(addr)) = (kal_uint32)(data))
#define DRV_Reg32(addr)             (*(volatile kal_uint32 *)(addr))
#define DRV_WriteReg8(addr,data)    ((*(volatile kal_uint8 *)(addr)) = (kal_uint8)(data))
#define DRV_Reg8(addr)              (*(volatile kal_uint8 *)(addr))



typedef enum {
   ECC_DEC_DETECT,
   ECC_DEC_LOCATE,
   ECC_DEC_CORRECT,
   ECC_DEC_NONE
} ECC_Decode_Type_t;

typedef enum {
   ECC_4_BITS,
   ECC_6_BITS,
   ECC_8_BITS,
   ECC_10_BITS,
   ECC_12_BITS,
   NUM_OF_ECC
} ECC_Level_t;

typedef enum
{
   NFI_ECC_CORRECTED      = 0xD0,
   NFI_OPERATION_SUCCESS  = 0xE0,
   NFI_BAD_BLOCK          = 0xF0,
   NFI_ECC_UNCORRECT      = 0xF1,
   NFI_ECC_TIMEOUT        = 0xF2,
   NFI_CMD_TIMEOUT        = 0xF3,
   NFI_ADDR_TIMEOUT       = 0xF4,
   NFI_DATA_TIMEOUT       = 0xF5,
   NFI_PROG_TIMEOUT       = 0xF6,
   NFI_BLOCKERASE_TIMEOUT = 0xF7,
   NFI_READ_TIMEOUT       = 0xF8,
   NFI_RESET_TIMEOUT      = 0xF9,
   NFI_PROG_FAILED        = 0xFA,
   NFI_BLOCKERASE_FAILED  = 0xFB
} NFI_Error_Code;

typedef struct {
   bool   nfi_hw_ecc;
   bool   nfi_auto_fmt;
   bool   nfi_ahb_mode;
   U32    nfi_page_size;
   U32    nfi_spare_size;
   U32    nfi_block_size;   /* in pages, 32, 64, 128 */
   U32    nfi_fdm_size;
   U32    nfi_sector_num;
   U32    nfi_data_sectors;
   U32    nfi_col_num;
   U32    nfi_row_num;
   U32    nfi_io_width;
} NFI_Config_st;

typedef struct {
   ECC_Decode_Type_t ecc_dec_op;
   ECC_Level_t       ecc_level;
   U32               ecc_msg_size; /* in bits */
} ECC_conf_st;

#define NAND_MAX_SECOTR_NUM        (8)
#define NAND_MAX_ERROR_LOCATION   (6)

NFI_Config_st 	BL_nfi_cfg;
ECC_conf_st   	BL_ecc_cfg;
U32  			nfi_meta_val[2];
U32  			nfi_ecc_err_location[NAND_MAX_SECOTR_NUM][NAND_MAX_ERROR_LOCATION];

extern BOOTL_HEADER  BLHeader;   
extern void dbg_print(kal_char *fmt, ...);




/**********************************************************
Description : ECC_Config
Input         : TRUE: 512B/page, 1: 2KB/page
Output        : 0
***********************************************************/
void ECC_Config(ECC_conf_st *ecc_conf, bool nfi_mode)
{
    U32 ecc_cfg  = 0;
    U32 ecc_bits = 0;

    if(nfi_mode)
        ecc_cfg |= ECC_CNFG_NFI;
    else
        ecc_cfg &= ~ECC_CNFG_NFI;

    switch(ecc_conf->ecc_level)
    {
#if defined(__ECC_8_BIT_SUPPORT__)			
		case ECC_8_BITS:
			ecc_bits = 8*ECC_PARITY_BITS;
            ecc_cfg |= ECC_CNFG_ECC8;
			break;
#endif			
        case ECC_4_BITS:
        default:
            ecc_bits = 4*ECC_PARITY_BITS;
            ecc_cfg |= ECC_CNFG_ECC4;
            break;
    }
    /* encoder configuration */
    ecc_cfg |= ecc_conf->ecc_msg_size << ENC_CNFG_MSG_SHIFT;
    DRV_WriteReg32(ECC_ENCCNFG, ecc_cfg);

    ecc_cfg &= ~DEC_CNFG_CODE_MASK;
    ecc_cfg |= (ecc_conf->ecc_msg_size+ecc_bits) << DEC_CNFG_CODE_SHIFT;
   /* decoder configuration */
    switch(ecc_conf->ecc_dec_op)
    {
        case ECC_DEC_DETECT:
            ecc_cfg |= DEC_CNFG_FER;
            break;
        case ECC_DEC_LOCATE:
            ecc_cfg |= DEC_CNFG_EL;
            break;
        case ECC_DEC_CORRECT:
        default:
            ecc_cfg |= DEC_CNFG_CORRECT;
            break;
    }
    DRV_WriteReg32(ECC_DECCNFG, ecc_cfg);
}

/**********************************************************
Description : BL_NFI_Reset
Remark      :
***********************************************************/
void BL_NFI_Reset(void)
{
	while(0 != DRV_Reg(NFI_MASTERSTA));

    *NFI_CON = CON_FIFO_FLUSH|CON_NFI_RST;
	while( (*NFI_STA) & (STA_NFI_FSM_MASK|STA_NAND_FSM_MASK) );
}

/**********************************************************
Description : NFI_Config
***********************************************************/
void NFI_Config(const NFI_MENU *input, const NFI_SUBMENU* sub_para)
{
    U16 reg_val = 0;

    switch(input->pageSize)
    {
        case 512:
            BL_nfi_cfg.nfi_col_num = 1;
            BL_nfi_cfg.nfi_row_num = input->addressCycle-1;
            reg_val |= PAGEFMT_512;
            break;
        case 2048:
            BL_nfi_cfg.nfi_col_num = 2;
            BL_nfi_cfg.nfi_row_num = input->addressCycle-2;
            reg_val |= PAGEFMT_2K;
            break;
        case 4096:
            BL_nfi_cfg.nfi_col_num = 2;
            BL_nfi_cfg.nfi_row_num = input->addressCycle-2;
            reg_val |= PAGEFMT_4K;
            break;
    }
    BL_nfi_cfg.nfi_page_size = input->pageSize;
    BL_nfi_cfg.nfi_sector_num = BL_nfi_cfg.nfi_page_size>>NAND_SECTOR_SHIFT;
    switch(sub_para->spareSize)
    {
        case 16:
            BL_nfi_cfg.nfi_fdm_size = 8;
            reg_val |= 8 << PAGEFMT_FDM_SHIFT;
            reg_val |= 8 << PAGEFMT_FDM_ECC_SHIFT;
            BL_ecc_cfg.ecc_level = ECC_4_BITS;
            reg_val |= PAGEFMT_SPARE_16<<PAGEFMT_SPARE_SHIFT;
            BL_nfi_cfg.nfi_spare_size = 16;
            break;
#if defined(__ECC_8_BIT_SUPPORT__)			
		case 26:	
			BL_nfi_cfg.nfi_fdm_size = 8;
            reg_val |= 8 << PAGEFMT_FDM_SHIFT;
            reg_val |= 8 << PAGEFMT_FDM_ECC_SHIFT;
            BL_ecc_cfg.ecc_level = ECC_8_BITS;
            reg_val |= PAGEFMT_SPARE_26<<PAGEFMT_SPARE_SHIFT;
            BL_nfi_cfg.nfi_spare_size = 26;
#endif			
    }
    BL_nfi_cfg.nfi_block_size = sub_para->blockSize;
    BL_ecc_cfg.ecc_msg_size = (NAND_SECTOR_SIZE+BL_nfi_cfg.nfi_fdm_size)<<3;
    BL_nfi_cfg.nfi_io_width = input->IOInterface;
    if(IO_16BITS == input->IOInterface)
    {
        reg_val |= PAGEFMT_DBYTE_EN;
    }
    /* configure NFI_PAGEFMT */
    DRV_WriteReg(NFI_PAGEFMT, reg_val);
    /* configure ECC decoder and encoder */
    BL_ecc_cfg.ecc_dec_op = ECC_DEC_LOCATE/*ECC_DEC_CORRECT*/;
    ECC_Config(&BL_ecc_cfg, KAL_TRUE);

}

/**********************************************************
Description : NFI_MCU_Correct
Remark      : Must be page alignment.
***********************************************************/
NFI_Error_Code NFI_MCU_Correct(U32 sec_no, P_U32 err_array, P_U8 data_buff)
{
    U32             idx         = 0;
    U32             err_num   = 0;
    U32             err_pos     = 0;
    U32             timeout     = DATA_TRANSFER_PERIOD;
    NFI_Error_Code  status      = NFI_OPERATION_SUCCESS;

    for(idx = 0 ; idx < NAND_MAX_ERROR_LOCATION ; idx++)
    {
        err_array[idx] = 0xFFFFFFFF;
    }

    while( !(DRV_Reg(ECC_DECDONE) & (1<<sec_no)) && (--timeout) );
    if(timeout)
    {
        if(DRV_Reg(ECC_DECFER) & (1 << sec_no))
        {
            err_num = (DRV_Reg32(ECC_DECENUM)>>(sec_no<<2))&0xF;
            if(err_num)
            {
	            if(0xF != err_num)
	            {
	                for(idx = 0 ; idx < ((err_num+1)>>1) ; idx++)
	                {
	                    /* get error location */
	                    err_array[idx] = DRV_Reg32(ECC_DECEL0+idx);
	                }
	                for(idx = 0 ; idx < err_num ; idx++)
	                {
	                    /* MCU error correction */
	                    kal_uint32 BytePos; 
	                    err_pos = ((err_array[idx>>1] >> ((idx&0x01)<<4)) & 0x1FFF);
	                    BytePos = (err_pos>>3);
	                    if ( BytePos < (NAND_SECTOR_SIZE+PAGEFMT_FDM_ECC_DEFAULT) )
	                    {
		                    if ((BytePos < 0x200) || (BL_nfi_cfg.nfi_auto_fmt==KAL_FALSE)) {
			                    *(data_buff+BytePos) ^= (1<<(err_pos&0x7));
		                    } else {
		                    	// BytePos is in FDM data and auto-format.
		                    	kal_uint32 temp;

		                    	BytePos -= 0x200;
		                    	if (BytePos < BL_nfi_cfg.nfi_fdm_size) {
			                    	if (BytePos >= 4) {
					                    temp = DRV_Reg32(NFI_FDM0M + (sec_no<<1));
					                    BytePos -= 4;
				                    	temp ^= ( 1<<((err_pos&0x7)+(BytePos<<3)) );
				                        DRV_WriteReg32(NFI_FDM0M + (sec_no<<1), temp);
			                    	} else {
					                    temp = DRV_Reg32(NFI_FDM0L + (sec_no<<1));
				                    	temp ^= ( 1<<((err_pos&0x7)+(BytePos<<3)) );
				                        DRV_WriteReg32(NFI_FDM0L + (sec_no<<1), temp);
			                    	}
		                    	}
		                    }
	                    }
	                }
	                status = NFI_ECC_CORRECTED;
	            }
            	else
            	{
                	status = NFI_ECC_UNCORRECT;
            	}
            }
        }
    }
    else
    {
        status = NFI_ECC_TIMEOUT;
    }

    return status;
}

/**********************************************************
Description : NFI_Read
Remark      : Must be page alignment.
***********************************************************/
NFI_Error_Code NFI_Read(U32 row_addr, U32 col_addr, P_U32 main_buff, P_U32 spare_buff)
{
    U32             reg_val     = 0;
    U32				tmp_val 	= 0;
    U32             idx         = 0;
    U32             inner       = 0;
    U32             timeout     = 0;
    P_U8            spare_ptr   = NULL;
    P_U8            byte_ptr    = NULL;
    NFI_Error_Code  status      = NFI_OPERATION_SUCCESS;
    NFI_Error_Code  ecc_status  = NFI_OPERATION_SUCCESS;

    BL_NFI_Reset();

    if(spare_buff)
        spare_ptr = (P_U8)spare_buff;
    else
        spare_ptr = (P_U8)((U32)main_buff+BL_nfi_cfg.nfi_page_size);

    /* configure data destination address */
    DRV_WriteReg32(NFI_STRADDR, (U32)main_buff);

    if(BL_nfi_cfg.nfi_hw_ecc)
    {
        /* enable ECC decoder */
        tmp_val = DRV_Reg32(ECC_DECCNFG);
        tmp_val |= ECC_CNFG_NFI | DEC_CNFG_EMPTY_EN;
        DRV_WriteReg32(ECC_DECCNFG, tmp_val);

        STOP_ECC_DEC
        START_ECC_DEC
        reg_val = CNFG_HW_ECC_EN;
    }
    /* data size to be transfered and AUTO_FMT setting */
    tmp_val = BL_nfi_cfg.nfi_data_sectors<<NAND_SECTOR_SHIFT;
    if(!BL_nfi_cfg.nfi_auto_fmt)
        tmp_val += BL_nfi_cfg.nfi_spare_size*BL_nfi_cfg.nfi_data_sectors;
    else
        reg_val |= CNFG_AUTO_FMT_EN;

    if(BL_nfi_cfg.nfi_ahb_mode)
    {
        reg_val |= (CNFG_DMA | CNFG_DMA_BURST_EN);
        /* one page in a transaction */
        tmp_val = BL_nfi_cfg.nfi_data_sectors<<NAND_SECTOR_SHIFT;
        if(!BL_nfi_cfg.nfi_auto_fmt)
            tmp_val += BL_nfi_cfg.nfi_spare_size*BL_nfi_cfg.nfi_data_sectors;
        else
            reg_val |= CNFG_AUTO_FMT_EN;
    }
    else
    {
        /* one sector in a transaction */
        tmp_val = NAND_SECTOR_SIZE;
        if(!BL_nfi_cfg.nfi_auto_fmt)
            tmp_val += BL_nfi_cfg.nfi_spare_size;
        else
            reg_val |= CNFG_AUTO_FMT_EN;
    }

    if(tmp_val&0x3)
    {
        reg_val |= CNFG_BYTE_RW;
    }

    reg_val |= BL_READ_CNFG;
    DRV_WriteReg(NFI_CNFG, reg_val);

    /* issue data output command and address cycles */
    DRV_WriteReg(NFI_CMD, RD_1ST_CMD);
    timeout = NORMAL_BUSY_PERIOD;
    while( (DRV_Reg32(NFI_STA) & STA_CMD_STATE) && (--timeout) );
   
    if(timeout)
    {
        DRV_WriteReg32(NFI_COLADDR, col_addr);
        DRV_WriteReg32(NFI_ROWADDR, row_addr);
        reg_val = BL_nfi_cfg.nfi_col_num|(BL_nfi_cfg.nfi_row_num << ADDR_ROW_NOB_SHIFT);
        DRV_WriteReg(NFI_ADDRNOB, reg_val);
        timeout = NORMAL_BUSY_PERIOD;
        while( (DRV_Reg32(NFI_STA) & STA_ADDR_STATE) && (--timeout) );

        /* check whether confirm command is necessary */
        if( (BL_nfi_cfg.nfi_sector_num > 1) && timeout)
        {
            DRV_WriteReg(NFI_CMD, RD_2ND_CYCLE_CMD);
            timeout = NORMAL_BUSY_PERIOD;
            while( (DRV_Reg32(NFI_STA) & STA_CMD_STATE) && (--timeout) );
        }

        if(timeout)
        {
            /* wait for device returning ready */
            timeout = NORMAL_BUSY_PERIOD;
            while( !(DRV_Reg32(NFI_STA) & STA_NAND_BUSY_RETURN) && --timeout );

            if(timeout)
            {
                /* transfer data */
                reg_val = CON_NFI_BRD | (BL_nfi_cfg.nfi_data_sectors << CON_NFI_SEC_SHIFT);
                DRV_WriteReg(NFI_CON, reg_val);

                if(BL_nfi_cfg.nfi_ahb_mode)
                {
                    timeout = DATA_TRANSFER_PERIOD;
                    while( (ADDRCNTR_CNTR(DRV_Reg(NFI_ADDRCNTR)) < BL_nfi_cfg.nfi_sector_num) && (--timeout));
                    while( (ADDRCNTR_CNTR(DRV_Reg(NFI_BYTELEN)) < BL_nfi_cfg.nfi_sector_num) && (--timeout));
                    if(timeout && BL_nfi_cfg.nfi_hw_ecc)
                    {
						while( *ECC_DECDONE != ((1<<BL_nfi_cfg.nfi_data_sectors)-1) );
						if ( (*ECC_DECFER) & ((1<<BL_nfi_cfg.nfi_data_sectors)-1) ) 
						{
							for (idx=0; idx<BL_nfi_cfg.nfi_data_sectors; idx++) 
							{
								kal_uint32 ErrNum = ((*ECC_DECENUM)>>(idx<<2))&0xF;

								if (ErrNum) 
								{ 
									if (ErrNum == 0x0f) 
									{
										status = NFI_ECC_UNCORRECT;
									}
									else
									{
										if (status != NFI_ECC_UNCORRECT) 
										{
											status = NFI_ECC_CORRECTED;
										}
									}	
								} 
							}
						}
                    }
                }
                else
                {
                    if(DRV_Reg(NFI_CNFG) & CNFG_BYTE_RW)
                    {
                        byte_ptr = (P_U8)main_buff;
                        for( idx = 0 ; idx < BL_nfi_cfg.nfi_data_sectors ; idx++)
                        {
                            for(inner = 0 ; inner < tmp_val ; inner++)
                            {
                                timeout = NORMAL_BUSY_PERIOD;
                                while( (!FIFO_PIO_READY(*NFI_PIO_DIRDY)) && (--timeout));
                                if(timeout)
                                {
                                    *(byte_ptr+tmp_val*idx+inner) = DRV_Reg32(NFI_DATAR);
                                }
                                else
                                    break;
                            }
                            if(timeout && BL_nfi_cfg.nfi_hw_ecc)
                            {
                                ecc_status = NFI_MCU_Correct(idx, nfi_ecc_err_location[idx], byte_ptr+tmp_val*idx);
                                if(NFI_OPERATION_SUCCESS == status) {
                                	// Here only status == NFI_OPERATION_SUCCESS.
                                    status = ecc_status; 
                                } else if( (NFI_ECC_CORRECTED == status) && (ecc_status != NFI_OPERATION_SUCCESS) ) {
                                	// Here only status == NFI_ECC_CORRECTED and ecc_status is not NFI_OPERATION_SUCCESS/
                                    status = ecc_status; 
                                }
                                	
                            }
                        }
                    }
                    else
                    {
                        tmp_val >>= 2;
                        for( idx = 0 ; idx < BL_nfi_cfg.nfi_data_sectors ; idx++)
                        {
                            for(inner = 0 ; inner < tmp_val ; inner++)
                            {
                                timeout = NORMAL_BUSY_PERIOD;
                                while( (!FIFO_PIO_READY(*NFI_PIO_DIRDY)) && (--timeout));
                                if(timeout)
                                {
                                    *(main_buff+tmp_val*idx+inner) = DRV_Reg32(NFI_DATAR);
                                }
                                else
                                    break;
                            }
                            if(timeout && BL_nfi_cfg.nfi_hw_ecc)
                            {
                                ecc_status = NFI_MCU_Correct(idx, nfi_ecc_err_location[idx], (P_U8)(main_buff+tmp_val*idx));
                                if(NFI_OPERATION_SUCCESS == status) {
                                	// Here only status == NFI_OPERATION_SUCCESS.
                                    status = ecc_status; 
                                } else if( (NFI_ECC_CORRECTED == status) && (ecc_status != NFI_OPERATION_SUCCESS) ) {
                                	// Here only status == NFI_ECC_CORRECTED and not NFI_OPERATION_SUCCESS/
                                    status = ecc_status; 
                                }                                
                            }
                        }
                    }
                }
                if(timeout)
                {
                    if(BL_nfi_cfg.nfi_auto_fmt)
                    {
                        /* extract FDM meta data */
   	                    timeout = DATA_TRANSFER_PERIOD;
	                    NFI_WAIT_TRANSFER_DONE(BL_nfi_cfg.nfi_data_sectors, timeout);                        
                        byte_ptr  = (P_U8)nfi_meta_val;
                        for(idx = 0 ; idx < BL_nfi_cfg.nfi_data_sectors ; idx++)
                        {
                            nfi_meta_val[0] = DRV_Reg32(NFI_FDM0L+(idx<<1));
                            nfi_meta_val[1] = DRV_Reg32(NFI_FDM0L+(idx<<1)+1);
                            for(tmp_val = 0 ; tmp_val < BL_nfi_cfg.nfi_fdm_size ; tmp_val++)
                            {
                                *(spare_ptr+idx*BL_nfi_cfg.nfi_fdm_size+tmp_val) = *(byte_ptr+tmp_val);
                            }
                        }
                    }
                }
                else
                {
                    if(NFI_OPERATION_SUCCESS == status)
                        status = NFI_DATA_TIMEOUT;
                }
            }
            else
                status = NFI_READ_TIMEOUT;
        }
        else
        {
            if(BL_nfi_cfg.nfi_sector_num > 1)
                status = NFI_CMD_TIMEOUT;
            else
                status = NFI_ADDR_TIMEOUT;
        }
    }
    else
    {
        status = NFI_CMD_TIMEOUT;
    }

    /* stop ECC decoder */
    if(BL_nfi_cfg.nfi_hw_ecc)
    {
			// before stop ECC, must check ECC status kuohong 2010.4.14
			timeout = DATA_TRANSFER_PERIOD;
			while( (!(*ECC_DECIDLE & DEC_IDLE)) && (--timeout) );
			if(timeout==0)
			{
				status = NFI_DATA_TIMEOUT;
		  }
      STOP_ECC_DEC
    }

    return status;
}


NFI_Error_Code  NFI_SectorRead(U32 page_index, U32 offset, U32 sectors, P_U32 sector_buff, P_U32 spare_buff, bool ahb_mode, bool hw_ecc, bool auto_fmt)
{
    NFI_Error_Code  status        = NFI_OPERATION_SUCCESS;
    U32               col_offset  = 0;
    U32               reg_val     = 0;

    BL_nfi_cfg.nfi_data_sectors = sectors;
    BL_nfi_cfg.nfi_hw_ecc = hw_ecc;
    BL_nfi_cfg.nfi_auto_fmt = auto_fmt;
    BL_nfi_cfg.nfi_ahb_mode = ahb_mode;

    if(IO_16BITS == BL_nfi_cfg.nfi_io_width)
        col_offset = offset >> 1;
    else
        col_offset = offset;

    reg_val = DRV_Reg32(ECC_DECCNFG);
    if(ahb_mode)
    {
        /* configure ECC to do correction */
        reg_val &= ~(DEC_CNFG_TYPE_MASK);
        reg_val |= DEC_CNFG_CORRECT;
    }
    else
    {
        /* configure ECC to output error location */
        reg_val &= ~(DEC_CNFG_TYPE_MASK);
        reg_val |= DEC_CNFG_EL;
    }
    DRV_WriteReg32(ECC_DECCNFG, reg_val);

    status = NFI_Read(page_index, col_offset, sector_buff, spare_buff);

    return status;
}

/**********************************************************
Description : NFI_PageRead
Input       : .......
Output      : _RET_CODE
Remark      : Must be page alignment
***********************************************************/
#ifdef __EXT_BOOTLOADER__

_RET_CODE NFI_PageRead(kal_uint32 *destination, kal_uint32 *parity, kal_uint32 length, \
                       kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize, \
                       kal_bool ECC, kal_bool continous)
{
 
    kal_uint32 block;
    kal_uint32 page;
    kal_int32 retVal;

    if ( BLHeader.NFIinfo.addressCycle > 4)
    {
        block = ((addr2<<16)|(addr1>>(BLHeader.pageShift)))/BLHeader.pagesPerBlock;
        page = ((addr2<<16)|(addr1>>(BLHeader.pageShift)))%BLHeader.pagesPerBlock;
    }        
    else
    {
        block = (addr1>>(BLHeader.pageShift))/BLHeader.pagesPerBlock;
        page = (addr1>>(BLHeader.pageShift))%BLHeader.pagesPerBlock;
    }

    if (length == pageSize)
    {
        retVal = NFB_ReadPhysicalPage(block, page, destination);
    }
    else
    {
        dbg_print("[Error] NFI_PageRead with length != pageSize\n\r");
        retVal = -1;
    }

    if (retVal >= 0)
        return NFI_SUCCESS;
    else
        return NFI_GENERAL_ERR;

}

#endif /* __EXT_BOOTLOADER__ */

/**********************************************************
Description : NFI_BitOneCount
Input         : NFI_MENU, baseaddr must be page alignment
Output        : U32 return data
***********************************************************/
U32 NFI_BitOneCount(U32 val, U32 len)
{
    U32  idx = 0;
    U32  num = 0;

    for(idx = 0 ; idx < len ; idx++)
    {
        if( (val>>idx) & 0x1 )
            num++;
    }

    return num;
}

/**********************************************************
Description : NFI_CheckGoodBlock
Input         : NFI_MENU, baseaddr must be page alignment
Output        : U32 return data
                +--------------------+---+----------+
                | Sector (512 bytes) | B | 15 bytes |   
                +--------------------+---+----------+
***********************************************************/
#define MAX_SPARE_SIZE 8
#define NAND_BAD_MARK_SPARE_OFFSET (0)
#define NAND_GOOD_BLOCK_THRESHOLD  (7)

U32 block_check_page_buff[NAND_SECTOR_SIZE>>2];  
NFI_Error_Code NFI_CheckGoodBlock(U32 block_no)
{
    U32            block_check_tmp_spare[MAX_SPARE_SIZE];
    U32            page_idx = 0;
    U32            tmp_val  = 0;
    P_U8           byte_ptr = (P_U8)block_check_tmp_spare;
    NFI_Error_Code status = NFI_OPERATION_SUCCESS;
    /* check 1st and 2nd page */
    for(page_idx = 0 ; page_idx < 2 ; page_idx++)
    {
        for(tmp_val = 0 ; tmp_val < BL_nfi_cfg.nfi_sector_num ; tmp_val++)
        {
            status = 
            NFI_SectorRead(page_idx+block_no*BL_nfi_cfg.nfi_block_size, tmp_val*(NAND_SECTOR_SIZE+BL_nfi_cfg.nfi_spare_size), 1, block_check_page_buff, block_check_tmp_spare, KAL_FALSE, KAL_TRUE, KAL_TRUE);
            if(status > NFI_ECC_TIMEOUT)
                break;
            if(NFI_BitOneCount(byte_ptr[NAND_BAD_MARK_SPARE_OFFSET], 8) < NAND_GOOD_BLOCK_THRESHOLD)
                return NFI_BAD_BLOCK;
        }
    }

    return status;
}


/**********************************************************
Description : NFIReconfigure
Input       : NO
Output      : NO
***********************************************************/
void NFIReconfigure(void)
{
// Power-on NFI.
#if defined(MT6276)
	DRV_WriteReg16(MCU_CG_CLR1, 0x1000);
#elif (defined(MT6256))
	DRV_WriteReg16(MCU_CG_CLR1, 0x1000);
#elif (defined(MT6255))
	DRV_WriteReg16(MCU_CG_CLR1, 0x1000);	
  *MCU_SFC_CTRL_SET	&= ~0x20;				// Disable NLD share with SF.
#elif (defined(MT6280))
	DRV_WriteReg32(APMCU_CG_CLR, 0x20);  
	//read bonding option,  DONGLE_SIP mode
	if(*NFI_MD_CHIP_STATUS&0x0002)
	{	
		*NFI_GPIO_1000 = 0x1111;							//NLD0, 1, 2, 3
		*NFI_GPIO_1100 = 0x1111;							//NLD4, 5, 6, 7
	
		*NFI_GPIO_1400 = (*NFI_GPIO_1400 & 0x00FF);//NLD0,1 reset as GPIO
		*NFI_GPIO_1500 = 0;//NLD2,3,4,5 reset as GPIO
		*NFI_GPIO_1600 = (*NFI_GPIO_1600 & 0xFF00); //NLD6,7 reset as GPIO
	}
	else 
	{		
		*NFI_GPIO_1000 = 0;//NLD0, 1, 2, 3  reset as GPIO
		*NFI_GPIO_1100 = 0;//NLD4, 5, 6, 7 reset as GPIO
	
		*NFI_GPIO_1400 = (*NFI_GPIO_1400 & 0x00FF)|0x4400;	//NLD0,1 
		*NFI_GPIO_1500 = 0x4444;							//NLD2,3,4,5 
		*NFI_GPIO_1600 = (*NFI_GPIO_1600 & 0xFF00)|0x0044; 	//NLD6,7
	}	
	if(BLHeader.NFIinfo.IOInterface==IO_16BITS) 									// 16 bit enable
	{
				*NFI_GPIO_1200 = 0x1111;							 	//NLD8, 9 , 10, 11
				*NFI_GPIO_1300 = 0x1111;							 	//NLD12, 13, 14, 15
	}        
	
	*NFI_GPIO_2500 = 0x1111;							 	//NRNB, NWEB, NREB, NCLE
	*NFI_GPIO_2600 = (*NFI_GPIO_2600 & 0xFF00) | 0x0011; 	//NALE, NCE0B         	  	 
#elif defined(MT6573)
    DRV_WriteReg32(APMCU_CG_CLR1, 0x80);    
#endif 	

	BL_NFI_Reset();

    DRV_WriteReg32(NFI_ACCCON, BL_ACCON);
    DRV_WriteReg32(NFI_CSEL, 0);
}


/**********************************************************
Description : GoodBlockChecking
Input       : NFI_MENU, NFIReadPtr must be page alignment
Output      : TRUE, good block, FALSE, bad block
***********************************************************/
kal_bool GoodBlockChecking(NFI_MENU *input, kal_uint32 addr1, kal_uint16 addr2)
{
	U32 block_no;

    if ( input->addressCycle > 4) {
        block_no = ((addr2<<16)|(addr1>>(BLHeader.pageShift)))/BLHeader.pagesPerBlock;
    } else {
        block_no = (addr1>>(BLHeader.pageShift))/BLHeader.pagesPerBlock;
    }
    
	if (NFI_CheckGoodBlock(block_no) != NFI_BAD_BLOCK) {
		return KAL_TRUE;
	} else {
		return KAL_FALSE;
	}
}

#ifdef __EXT_BOOTLOADER__

void NFIReconfigure2(void)
{
    kal_int32 NFBStatus = -1;
    NFBStatus = DAL_init();
    if ( NFBStatus != FS_NO_ERROR )
    {
        dbg_print("[NFIReconfigure] DAL_init fail\n");
        while (1);
    }
}

#endif /* __EXT_BOOTLOADER__ */

// Return value :
//	 0 - Good block.
//	-1 - Bad block
kal_int32 NFB_CheckGoodBlock_NoTT(kal_uint32 Block)
{
	if (NFI_CheckGoodBlock(Block) != NFI_BAD_BLOCK) {
		return 0;
	} else {
		return -1;
	}
}

/**********************************************************
Description : NFI_PhyPageRead
Input       : .......
Output      : _RET_CODE
Remark      : Must be page alignment
***********************************************************/
_RET_CODE NFI_PhyPageRead(kal_uint32 *destination, kal_uint32 *parity, kal_uint32 length, \
                       kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize, \
                       kal_bool ECC, kal_bool continous)
{
    kal_uint32 row_addr, reg_val;
    NFI_Error_Code  status        = NFI_OPERATION_SUCCESS;

    BL_nfi_cfg.nfi_data_sectors = BL_nfi_cfg.nfi_sector_num;
    BL_nfi_cfg.nfi_hw_ecc = KAL_TRUE;
    BL_nfi_cfg.nfi_auto_fmt = KAL_TRUE;
    BL_nfi_cfg.nfi_ahb_mode = KAL_FALSE;

    reg_val = DRV_Reg32(ECC_DECCNFG);
    if(BL_nfi_cfg.nfi_ahb_mode)
    {
        /* configure ECC to do correction */
        reg_val &= ~(DEC_CNFG_TYPE_MASK);
        reg_val |= DEC_CNFG_CORRECT;
    }
    else
    {
        /* configure ECC to output error location */
        reg_val &= ~(DEC_CNFG_TYPE_MASK);
        reg_val |= DEC_CNFG_EL;
    }
    DRV_WriteReg32(ECC_DECCNFG, reg_val);

    if ( BLHeader.NFIinfo.addressCycle > 4) {
        row_addr = (addr2<<16) | (addr1>>(BLHeader.pageShift));
    } else {
        row_addr = addr1 >> (BLHeader.pageShift);
    }
    
	status = NFI_Read(row_addr, 0, destination, parity);

    if(status>NFI_OPERATION_SUCCESS) 
    {
    	return NFI_GENERAL_ERR;
    }
    else 
    {
        return NFI_SUCCESS;
    }
}

kal_int32 NFB_ReadPhysicalPageWithSpare_NoTT(kal_uint32 PhyBlock, kal_uint32 PhyPage, kal_uint32 *Data, kal_uint32 *Spare)
{
   	kal_uint32 addr1, addr2;

	PhyPage += (PhyBlock << (BLHeader.blockShift - PAGE_SHIFT));
	addr1 = (kal_uint32)(PhyPage << PAGE_SHIFT);
	addr2 = 0;
	if (BLHeader.NFIinfo.addressCycle>4) {
		// Seems only in 2KB page size case.
		addr2 = (kal_uint32)(PhyPage >> PAGE_SHIFT);
   	}	
   		
	return NFI_PhyPageRead(Data, Spare, BLHeader.NFIinfo.pageSize, BLHeader.NFIinfo.addressCycle, addr1, addr2, 
			BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_FALSE);
}
/**********************************************************
Description : NFI_ReadID
Remark      : content in
              NFI_PAGEFMT, NFI_CNFG, NFI_ADDRNOB, NFI_CON,
              NFI_COLADDR, and NFI_ROWADDR will be changed 
***********************************************************/
void NFI_ReadID(kal_uint32 id_num, kal_uint8* id_data)
{
    kal_uint32 idx;
    kal_uint32 ID[2];
    kal_uint32 Backup_NFI_PAGEFMT;
    NFIReconfigure();
    BL_NFI_Reset();
    Backup_NFI_PAGEFMT = *NFI_PAGEFMT;    
    *NFI_PAGEFMT = PAGEFMT_512_8BIT;
		*NFI_CNFG = CNFG_OP_SRD | CNFG_READ_EN;
		*NFI_CMD = RD_ID_CMD;
		while ((*NFI_STA) & STA_CMD_STATE);

   	*NFI_COLADDR = 0;
		*NFI_ROWADDR = 0;
		*NFI_ADDRNOB = 1;
		while ((*NFI_STA) & STA_ADDR_STATE);

		*NFI_CON = CON_NFI_SRD;
		while((*NFI_STA) & STA_DATAR_STATE);
		for(idx = 0 ; idx < 2 ; idx++)
		{
			while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) );
			ID[idx] = *NFI_DATAR;
		}
		*NFI_CON = 0x0;
    *NFI_PAGEFMT = Backup_NFI_PAGEFMT;		
    id_data[0] = (kal_uint8)ID[0];
    id_data[1] = (kal_uint8)(ID[0]>>8);
    id_data[2] = (kal_uint8)(ID[0]>>16);
    id_data[3] = (kal_uint8)(ID[0]>>24);
    id_data[4] = (kal_uint8)ID[1];
    id_data[5] = (kal_uint8)(ID[1]>>8);
    id_data[6] = (kal_uint8)(ID[1]>>16);
    id_data[7] = (kal_uint8)(ID[1]>>24);
   
}
#if defined(BIT_ERROR_TEST) || defined(BL_NFI_TEST)

/**********************************************************
Description : NFI_ReadStatus
Input       : None
Output      : None
***********************************************************/
U8 NFI_ReadStatus(void)
{
    U8     status  = 0xFF;
    U32    timeout = NORMAL_BUSY_PERIOD;

    BL_NFI_Reset();

    DRV_WriteReg(NFI_CNFG, BL_SRD_CNFG);
    
    DRV_WriteReg(NFI_CMD, RD_STATUS_CMD);
    while ( (DRV_Reg32(NFI_STA) & STA_CMD_STATE) && (--timeout));

    if(timeout)
    {
        DRV_WriteReg(NFI_CON, (1 << CON_NFI_NOB_SHIFT)|CON_NFI_SRD);

        while ( !FIFO_PIO_READY(*NFI_PIO_DIRDY) && (--timeout));

        if(timeout)
        {
            status = DRV_Reg32(NFI_DATAR);
        }
        /* clear NOB */
        DRV_WriteReg(NFI_CON, 0);
    }

    return status;
}

/**********************************************************
Description : NFI_PageWrite
Remark      : Must be page alignment.
              Both HW_ECC and AUTO_FMT have to be set to 
              append ECC parity
***********************************************************/
NFI_Error_Code NFI_PageWrite(U32 page_index, U32 col_addr, P_U32 main_buff, P_U32 spare_buff, kal_bool hw_ecc, kal_bool auto_fmt, kal_bool ahb_mode)
{
    NFI_Error_Code  status     = NFI_OPERATION_SUCCESS;
    U32              idx       = 0;
    U32             reg_val   = 0;
    U32             tmp_val   = 0;
    U32             timeout   = 0;
    P_U8            byte_ptr  = NULL;
    P_U8            spare_ptr = NULL;

    BL_nfi_cfg.nfi_data_sectors = BL_nfi_cfg.nfi_sector_num;
    BL_nfi_cfg.nfi_hw_ecc = hw_ecc;
    BL_nfi_cfg.nfi_auto_fmt = auto_fmt;
    BL_nfi_cfg.nfi_ahb_mode = ahb_mode;
    
    BL_NFI_Reset();

    reg_val = BL_WRITE_CNFG;

    /* copy FDM neta data */
    if(spare_buff)
        spare_ptr = (P_U8)spare_buff;
    else
        spare_ptr = (P_U8)((U32)main_buff+BL_nfi_cfg.nfi_page_size);

    if(BL_nfi_cfg.nfi_auto_fmt)
    {
        byte_ptr  = (P_U8)nfi_meta_val;
        for(tmp_val = 0 ; tmp_val < BL_nfi_cfg.nfi_sector_num ; tmp_val++)
        {
            for(idx = 0 ; idx < BL_nfi_cfg.nfi_fdm_size ; idx++)
            {
                *(byte_ptr+idx) = *(spare_ptr+idx+BL_nfi_cfg.nfi_fdm_size*tmp_val);
            }
            for(; idx < (8-BL_nfi_cfg.nfi_fdm_size) ; idx++)
            {
                *(byte_ptr+idx) = 0xFF;
            }
            DRV_WriteReg32(NFI_FDM0L+(tmp_val<<1), nfi_meta_val[0]);
            DRV_WriteReg32(NFI_FDM0L+(tmp_val<<1)+1, nfi_meta_val[1]);
        }
    }

    /* configure data source address */
    DRV_WriteReg32(NFI_STRADDR, (U32)main_buff);

    /* configure ECC */
    /* NOTE: only following setting are supported
     *       spare size    ECC capability
     *          16 bytes      8 bit
     *          26 bytes     12 bit
     */
    if(BL_nfi_cfg.nfi_hw_ecc & BL_nfi_cfg.nfi_auto_fmt)
    {
        timeout = NORMAL_BUSY_PERIOD;
        reg_val |= CNFG_HW_ECC_EN;
        /* enable ECC encoder */
        tmp_val = DRV_Reg32(ECC_ENCCNFG);
        tmp_val |= ECC_CNFG_NFI;
        DRV_WriteReg32(ECC_ENCCNFG, tmp_val);
        //WAIT_ENC_READY
        //START_ECC_ENC
        WAIT_ENC_READY_WITH_TIMEOUT(timeout);
        STOP_ECC_ENC
        START_ECC_ENC
    }

    /* data size to be transfered and AUTO_FMT setting */
    tmp_val = BL_nfi_cfg.nfi_data_sectors<<NAND_SECTOR_SHIFT;
    if(!BL_nfi_cfg.nfi_auto_fmt)
        tmp_val += BL_nfi_cfg.nfi_spare_size*BL_nfi_cfg.nfi_data_sectors;
    else
        reg_val |= CNFG_AUTO_FMT_EN;

    if(BL_nfi_cfg.nfi_ahb_mode)
        reg_val |= CNFG_AHB;

    if(tmp_val&0x3)
    {
        reg_val |= CNFG_BYTE_RW;
    }
    else
    {
        tmp_val >>= 2;
    }

    DRV_WriteReg(NFI_CNFG, reg_val);

    /* issue data input command and address cycles */
    DRV_WriteReg(NFI_CMD, INPUT_DATA_CMD);
    timeout = NORMAL_BUSY_PERIOD;
    while( (DRV_Reg32(NFI_STA) & STA_CMD_STATE) && (--timeout) );

    if(timeout)
    {
        DRV_WriteReg32(NFI_COLADDR, col_addr);
        DRV_WriteReg32(NFI_ROWADDR, page_index);
        reg_val = BL_nfi_cfg.nfi_col_num|(BL_nfi_cfg.nfi_row_num << ADDR_ROW_NOB_SHIFT);
        DRV_WriteReg(NFI_ADDRNOB, reg_val);
        timeout = NORMAL_BUSY_PERIOD;
        while( (DRV_Reg32(NFI_STA) & STA_ADDR_STATE) && (--timeout));

        if(timeout)
        {
            /* transfer data */
            reg_val = CON_NFI_BWR | (BL_nfi_cfg.nfi_data_sectors << CON_NFI_SEC_SHIFT);
            DRV_WriteReg(NFI_CON, reg_val);
            if(BL_nfi_cfg.nfi_ahb_mode)
            {
                timeout = DATA_TRANSFER_PERIOD;
                while( (ADDRCNTR_CNTR(DRV_Reg(NFI_ADDRCNTR)) < BL_nfi_cfg.nfi_data_sectors) && (--timeout));
            }
            else
            {
                if(DRV_Reg(NFI_CNFG) & CNFG_BYTE_RW)
                {
                    byte_ptr = (P_U8)main_buff;
                    for(idx = 0 ; idx < tmp_val ; idx++)
                    {
                        timeout = NORMAL_BUSY_PERIOD;
                        while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) && (--timeout) );
                        if(timeout)
                        {
                            DRV_WriteReg32(NFI_DATAW, *(byte_ptr++));
                        }
                        else
                            break;
                    }
                }
                else
                {
                    for(idx = 0 ; idx < tmp_val ; idx++)
                    {
                        timeout = NORMAL_BUSY_PERIOD;
                        while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) && (--timeout) );
                        if(timeout)
                        {
                            DRV_WriteReg32(NFI_DATAW, *(main_buff++));
                        }
                        else
                            break;
                    }
                }
                if(timeout)
                {
                    timeout = NORMAL_BUSY_PERIOD;
                    NFI_WAIT_TRANSFER_DONE(BL_nfi_cfg.nfi_data_sectors, timeout);
                }
            }

            /* stop ECC encoder */
            if(BL_nfi_cfg.nfi_hw_ecc & BL_nfi_cfg.nfi_auto_fmt)
            {
               if(timeout)
               {
                  timeout = NORMAL_BUSY_PERIOD;
                  WAIT_ENC_READY_WITH_TIMEOUT(timeout);
               }
               //reg_val = CON_FIFO_FLUSH;
               //DRV_WriteReg(NFI_CON, reg_val);
               if(timeout)
               {
                   timeout = NORMAL_BUSY_PERIOD;
                   while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) && (--timeout) );
               }
               STOP_ECC_ENC
            }

            if(timeout)
            {
                /* issue program command */
                DRV_WriteReg(NFI_CMD, PROG_DATA_CMD);
                timeout = NORMAL_BUSY_PERIOD;
                while( (DRV_Reg32(NFI_STA) & STA_CMD_STATE) && (--timeout));

                if(timeout)
                {
                    /* wait for device returning ready */
                    timeout = PROG_BUSY_PERIOD;
                    do
                    {
                        tmp_val = NFI_ReadStatus();
                        if(tmp_val&DEVICE_READY)
                            break;
                        else
                            timeout--;
                    }while(timeout);
                    if(0 == timeout)
                        status = NFI_PROG_TIMEOUT;
                }
                else
                    status = NFI_CMD_TIMEOUT;
            }
            else
            {
                status = NFI_DATA_TIMEOUT;
            }
        }
        else
        {
            status = NFI_ADDR_TIMEOUT;
        }
    }
    else
    {
        status = NFI_CMD_TIMEOUT;
    }

    /* stop ECC encoder */
    if(BL_nfi_cfg.nfi_hw_ecc & BL_nfi_cfg.nfi_auto_fmt)
    {
        if( (NFI_CMD_TIMEOUT == status) || (NFI_ADDR_TIMEOUT == status) )
           STOP_ECC_ENC
    }

    /* check operation status */
    if( (NFI_OPERATION_SUCCESS == status) && (tmp_val&OPERATION_FAIL) )
        status = NFI_PROG_FAILED;

    return status;
}

void EmulateBitError(kal_uint32 *destination, kal_uint32 *parity, kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize)
{
	kal_uint8 BitNo, Sector, Mask;
	kal_uint32 Offset, MagicNum;
	kal_bool EmulatedBitError;
	kal_uint8 *Ptr = (kal_uint8 *)destination;
	U32 page_index;
    NFI_Error_Code  NFIStatus = NFI_OPERATION_SUCCESS;
    kal_uint32 row_addr, reg_val;

    BL_nfi_cfg.nfi_data_sectors = BL_nfi_cfg.nfi_sector_num;
    BL_nfi_cfg.nfi_hw_ecc = KAL_TRUE;
    BL_nfi_cfg.nfi_auto_fmt = KAL_FALSE;
    BL_nfi_cfg.nfi_ahb_mode = KAL_FALSE;

    reg_val = DRV_Reg32(ECC_DECCNFG);
    if(BL_nfi_cfg.nfi_ahb_mode)
    {
        /* configure ECC to do correction */
        reg_val &= ~(DEC_CNFG_TYPE_MASK);
        reg_val |= DEC_CNFG_CORRECT;
    }
    else
    {
        /* configure ECC to output error location */
        reg_val &= ~(DEC_CNFG_TYPE_MASK);
        reg_val |= DEC_CNFG_EL;
    }
    DRV_WriteReg32(ECC_DECCNFG, reg_val);

    if ( BLHeader.NFIinfo.addressCycle > 4) {
        row_addr = (addr2<<16) | (addr1>>(BLHeader.pageShift));
    } else {
        row_addr = addr1 >> (BLHeader.pageShift);
    }
    
	NFIStatus = NFI_Read(row_addr, 0, destination, parity);
	
	if (NFIStatus != NFI_OPERATION_SUCCESS) {
		dbg_print(" Original data has error. No need to emulate bit error. status=%x \n\r", NFIStatus);
		return;
	}

	for(Sector=0; Sector<(pageSize/0x200); Sector++) {
		EmulatedBitError = KAL_FALSE;
		if(pageSize < 1024) {
			MagicNum = (addr1>>16) ^ (addr1>>8);
		} else {
			MagicNum = (addr1>>16) ^ (addr1>>24);
		}
		for(Offset=(MagicNum & 0x1ff); Offset<0x200; Offset++) {
			Mask = 0x01;
			for(BitNo=0; BitNo<8; BitNo++) {
				if(Ptr[Sector*0x200+Offset] & Mask) {
					dbg_print("***[Emulate] Offset = %x, Original data = %x", addr1+(Sector*0x200)+Offset, Ptr[Sector*0x200+Offset]);
					Ptr[Sector*0x200+Offset] = Ptr[Sector*0x200+Offset] & (~Mask);
					dbg_print(" New data  = %x \n\r", Ptr[Sector*0x200+Offset]);
					EmulatedBitError = KAL_TRUE;
					break;
				}
				Mask = Mask << 1;
			}
			if(EmulatedBitError==KAL_TRUE) {
				break;
			}
		}
	}

    if ( BLHeader.NFIinfo.addressCycle > 4) {
        page_index = (addr2<<16) | (addr1>>(BLHeader.pageShift));
    } else {
        page_index = addr1 >> (BLHeader.pageShift);
    }
    
	NFI_PageWrite(page_index, 0, destination, parity, KAL_FALSE, KAL_FALSE, KAL_FALSE);

	return;
} 

#if defined(BL_NFI_TEST)

/**********************************************************
Description : NFI_BlockErase
Remark      : Must be page alignment.
***********************************************************/
NFI_Error_Code NFI_BlockErase(U32 block_index)
{
    U32              tmp_val = 0;
    U32              timeout = 0;
    NFI_Error_Code  status  = NFI_OPERATION_SUCCESS;

    BL_NFI_Reset();

    DRV_WriteReg(NFI_CNFG, BL_ERASE_CNFG);

    /* issue data output command and address cycles */
    DRV_WriteReg(NFI_CMD, BLOCK_ERASE1_CMD);
    timeout = NORMAL_BUSY_PERIOD;
    while( (DRV_Reg32(NFI_STA) & STA_CMD_STATE) && (--timeout) );
    
    if(timeout)
    {
        DRV_WriteReg32(NFI_COLADDR, 0);
        DRV_WriteReg32(NFI_ROWADDR, block_index*BL_nfi_cfg.nfi_block_size);
        tmp_val = BL_nfi_cfg.nfi_row_num << ADDR_ROW_NOB_SHIFT;
        DRV_WriteReg(NFI_ADDRNOB, tmp_val);
        timeout = NORMAL_BUSY_PERIOD;
        while( (DRV_Reg32(NFI_STA) & STA_ADDR_STATE) && (--timeout) );

        if(timeout)
        {
            /* erase confirm command */
            DRV_WriteReg(NFI_CMD, BLOCK_ERASE2_CMD);
            timeout = NORMAL_BUSY_PERIOD;
            while( (DRV_Reg32(NFI_STA) & STA_CMD_STATE) && (--timeout) );

            if(timeout)
            {
                timeout = ERASE_BUSY_PERIOD;
                do
                {
                    tmp_val = NFI_ReadStatus();
                    if(tmp_val&DEVICE_READY)
                        break;
                    else
                        timeout--;
                }while(timeout);
                if(0 == timeout)
                    status = NFI_BLOCKERASE_TIMEOUT;
            }
            else
            {
                status = NFI_CMD_TIMEOUT;
            }
        }
        else
        {
                status = NFI_ADDR_TIMEOUT;
        }
    }
    else
    {
        status = NFI_CMD_TIMEOUT;
    }

    /* check operation status */
    if( (NFI_OPERATION_SUCCESS == status) && (tmp_val&OPERATION_FAIL) )
        status = NFI_BLOCKERASE_FAILED;

    return status;
}




struct NAND_DeviceTable {
    NFI_MENU    info;
    U8          id[8];
};

U8   device_id[8];
U32  device_idx = 8;
struct NAND_DeviceTable  NFI_Test_Device[] =
{   //advance high address cycle test
    { {IO_8BITS,  4096, 5}, { 0x98, 0xD5, 0x94, 0xBA, 0x00, 0x00, 0x00, 0x00 } },
    { {IO_16BITS, 2048, 4}, { 0xAD, 0xC1, 0x80, 0x5D, 0x00, 0x00, 0x00, 0x00 } },
    { {IO_8BITS,  2048, 5}, { 0xEC, 0xDA, 0x10, 0x95, 0x00, 0x00, 0x00, 0x00 } },
    { {IO_8BITS,  2048, 5}, { 0xAD, 0xD3, 0x14, 0xA5, 0x00, 0x00, 0x00, 0x00 } },
    { {IO_16BITS,  512, 3}, { 0xAD, 0x55, 0xA5, 0x00, 0x00, 0x00, 0x00, 0x00 } },
    { {IO_8BITS,   512, 4}, { 0xAD, 0x76, 0xAD, 0x76, 0x00, 0x00, 0x00, 0x00 } }
};     

void BL_NFI_Test(kal_uint32 *Buffer)
{
	kal_uint8 *BufPtr = (kal_uint8 *)Buffer;
	kal_uint8 *RBufPtr = BufPtr+3072;
	kal_uint32 BlockIndex, PageIndex, Offset, Addr[2];
    NFI_SUBMENU sub_menu;
    kal_bool Pass = KAL_TRUE;
    NFI_Error_Code RetCode;

#if defined(MT6276)
	DRV_WriteReg16(MCU_CG_CLR1, 0x1000);
#elif (defined(MT6256))
	DRV_WriteReg16(MCU_CG_CLR1, 0x1000);
#elif (defined(MT6255))
	DRV_WriteReg16(MCU_CG_CLR1, 0x1000);	
#elif (defined(MT6280))
	DRV_WriteReg32(APMCU_CG_CLR, 0x20);    	 	
#elif defined(MT6573)
    DRV_WriteReg32(APMCU_CG_CLR1, 0x80);    	
#endif 	

    // auto detect NAND flash device 
    memset(device_id, 0, sizeof(device_id));
    NFI_ReadID(sizeof(device_id), device_id);
    for(device_idx=0; device_idx<sizeof(NFI_Test_Device)/sizeof(struct NAND_DeviceTable); device_idx++) {
        if(!memcmp(NFI_Test_Device[device_idx].id, device_id, 4)) {
            goto __device_found;
        }
    }

    // device not found! 
	dbg_print("Device not found %x %x %x %x~~\n\r", device_id[0], device_id[1], device_id[2], device_id[3]);
    while(1);

__device_found:

	if (NFI_Test_Device[device_idx].info.pageSize == 512) {
		sub_menu.blockSize = 32;
		BLHeader.pageShift = 8;
		BLHeader.blockShift = 5;
	} else {
		sub_menu.blockSize = 64;
		BLHeader.pageShift = 16;	
		BLHeader.blockShift = 6;
	}	
	sub_menu.spareSize = 16;
	NFI_Config(&NFI_Test_Device[device_idx].info, &sub_menu);
	BLHeader.NFIinfo.addressCycle = NFI_Test_Device[device_idx].info.addressCycle;
	BLHeader.NFIinfo.IOInterface = NFI_Test_Device[device_idx].info.IOInterface;
	BLHeader.NFIinfo.pageSize = NFI_Test_Device[device_idx].info.pageSize;
	BLHeader.spareSize = sub_menu.spareSize;
	BLHeader.pagesPerBlock = sub_menu.blockSize;

	
	for (BlockIndex=0; BlockIndex<0x100; BlockIndex++) {
		Addr[0] = (BlockIndex * BLHeader.pagesPerBlock) << BLHeader.pageShift;
		Addr[1] = (BlockIndex * BLHeader.pagesPerBlock) >> (32 - BLHeader.pageShift);
		if (GoodBlockChecking(&NFI_Test_Device[device_idx].info, Addr[0], Addr[1] )==KAL_FALSE) {
			dbg_print("Block %x is bad..\n\r", BlockIndex);
			continue;
		}
		RetCode = NFI_BlockErase(BlockIndex);
		if (RetCode > NFI_OPERATION_SUCCESS) {

			dbg_print("Block %x erase failed..\n\r", BlockIndex);
			continue;
		}
		for (PageIndex=0; PageIndex<BLHeader.pagesPerBlock; PageIndex++) {
			Addr[0] = (BlockIndex * BLHeader.pagesPerBlock + PageIndex) << BLHeader.pageShift;
			Addr[1] = (BlockIndex * BLHeader.pagesPerBlock + PageIndex) >> (32 - BLHeader.pageShift);

			RetCode = NFI_PhyPageRead((U32 *)RBufPtr, (U32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize]), 1, BLHeader.NFIinfo.addressCycle, 
				Addr[0], Addr[1], BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_TRUE);
			if (RetCode > NFI_OPERATION_SUCCESS) {

				dbg_print("NFI_PhyPageRead failed.. Block %x Page %x RetCode=%x\n\r", BlockIndex, PageIndex, RetCode);
				while(1);
			}			
			
			for (Offset=0; Offset<(NFI_Test_Device[device_idx].info.pageSize+(BL_nfi_cfg.nfi_sector_num*BL_nfi_cfg.nfi_fdm_size)); Offset++) {
				if (RBufPtr[Offset] != 0xff) {
					dbg_print("[Error] Data not empty. BlockIndex %x PageIndex %x Offset %x value %x\n\r", 
						BlockIndex, PageIndex, Offset, RBufPtr[Offset]);
					Pass = KAL_FALSE;
				}
			}
		}
	}

	if(Pass==KAL_FALSE) {
		dbg_print("Test failed..\n\r");
		while(1);
	}

	for (BlockIndex=0; BlockIndex<0x100; BlockIndex++) {
		Addr[0] = (BlockIndex * BLHeader.pagesPerBlock) << BLHeader.pageShift;
		Addr[1] = (BlockIndex * BLHeader.pagesPerBlock) >> (32 - BLHeader.pageShift);
		if (GoodBlockChecking(&NFI_Test_Device[device_idx].info, Addr[0], Addr[1] )==KAL_FALSE) {
			dbg_print("Block %x is bad..\n\r", BlockIndex);
			continue;
		}
		
		for (PageIndex=0; PageIndex<BLHeader.pagesPerBlock; PageIndex++) {
			for (Offset=0; Offset<(NFI_Test_Device[device_idx].info.pageSize+(BL_nfi_cfg.nfi_sector_num*BL_nfi_cfg.nfi_fdm_size)); Offset++) {
				BufPtr[Offset] = (kal_uint8) (BlockIndex+PageIndex+Offset);
			}
			RetCode = NFI_PageWrite(BlockIndex*BLHeader.pagesPerBlock+PageIndex, 0, (U32 *)BufPtr, (U32 *)&(BufPtr[NFI_Test_Device[device_idx].info.pageSize]), KAL_TRUE, KAL_TRUE, KAL_FALSE);
			if (RetCode > NFI_OPERATION_SUCCESS) {

				dbg_print("Block %x program failed..\n\r", BlockIndex);
				continue;
			}

			Addr[0] = (BlockIndex * BLHeader.pagesPerBlock + PageIndex) << BLHeader.pageShift;
			Addr[1] = (BlockIndex * BLHeader.pagesPerBlock + PageIndex) >> (32 - BLHeader.pageShift);

			RetCode = NFI_PhyPageRead((U32 *)RBufPtr, (U32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize]), 1, BLHeader.NFIinfo.addressCycle, 
				Addr[0], Addr[1], BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_TRUE);
			if (RetCode > NFI_OPERATION_SUCCESS) {

				dbg_print("NFI_PhyPageRead failed.. Block %x Page %x RetCode=%x\n\r", BlockIndex, PageIndex, RetCode);
				while(1);
			}			
			for (Offset=0; Offset<(NFI_Test_Device[device_idx].info.pageSize+(BL_nfi_cfg.nfi_sector_num*BL_nfi_cfg.nfi_fdm_size)); Offset++) {
				if(RBufPtr[Offset] != BufPtr[Offset]) {
					dbg_print("[Error] Data mismatch. BlockIndex %x PageIndex %x Offset %x write value=%x read value=%x\n\r", 
						BlockIndex, PageIndex, Offset, BufPtr[Offset], RBufPtr[Offset]);
					Pass = KAL_FALSE;					
				}
			}
			if (Pass==KAL_FALSE) {
				dbg_print("Test failed..\n\r");
				while(1);				
			}
			memset(RBufPtr, 0, 4096);
			NFI_SectorRead(BlockIndex * BLHeader.pagesPerBlock + PageIndex, 0, 1, (U32 *)&(RBufPtr[0]), (U32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize]), KAL_FALSE, KAL_TRUE, KAL_TRUE);
			NFI_SectorRead(BlockIndex * BLHeader.pagesPerBlock + PageIndex, 528, 1, (U32 *)&(RBufPtr[512]), (U32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize+3]), KAL_FALSE, KAL_TRUE, KAL_TRUE);
			NFI_SectorRead(BlockIndex * BLHeader.pagesPerBlock + PageIndex, 1056, 2, (U32 *)&(RBufPtr[1024]), (U32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize+6]), KAL_FALSE, KAL_TRUE, KAL_TRUE);
			for (Offset=0; Offset<(NFI_Test_Device[device_idx].info.pageSize+(BL_nfi_cfg.nfi_sector_num*BL_nfi_cfg.nfi_fdm_size)); Offset++) {
				if(RBufPtr[Offset] != BufPtr[Offset]) {
					dbg_print("[Error] Data mismatch. BlockIndex %x PageIndex %x Offset %x write value=%x read value=%x\n\r", 
						BlockIndex, PageIndex, Offset, BufPtr[Offset], RBufPtr[Offset]);
					Pass = KAL_FALSE;					
				}
			}
			if (Pass==KAL_FALSE) {
				dbg_print("NFI_SectorRead compare failed..\n\r");
				while(1);				
			}			
			EmulateBitError((U32 *)RBufPtr, (U32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize]), BLHeader.NFIinfo.addressCycle, Addr[0], Addr[1], BLHeader.NFIinfo.pageSize);
			memset(RBufPtr, 0, 4096);
			RetCode = NFI_PhyPageRead((U32 *)RBufPtr, (U32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize]), 1, BLHeader.NFIinfo.addressCycle, 
				Addr[0], Addr[1], BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_TRUE);
			if (RetCode > NFI_OPERATION_SUCCESS) {

				dbg_print("NFI_PhyPageRead failed.. Block %x Page %x RetCode=%x\n\r", BlockIndex, PageIndex, RetCode);
				while(1);
			}			
			for (Offset=0; Offset<(NFI_Test_Device[device_idx].info.pageSize+(BL_nfi_cfg.nfi_sector_num*BL_nfi_cfg.nfi_fdm_size)); Offset++) {
				if(RBufPtr[Offset] != BufPtr[Offset]) {
					dbg_print("[Error] Data mismatch. BlockIndex %x PageIndex %x Offset %x write value=%x read value=%x\n\r", 
						BlockIndex, PageIndex, Offset, BufPtr[Offset], RBufPtr[Offset]);
					Pass = KAL_FALSE;					
				}
			}
			if (Pass==KAL_FALSE) {
				dbg_print("EmulateBitError compare failed..\n\r");
				while(1);				
			}			
			
		}
	}	
}

#endif // defined(BL_NFI_TEST)

#endif  // defined(BIT_ERROR_TEST) || defined(BL_NFI_TEST)

#endif // __USE_NFI_SHARED_DRV__
#endif // defined(__NFI_VERSION3_1__)

#endif /* _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ */
