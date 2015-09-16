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
 *  bl_NFI_V3.c
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

#if defined(__NFI_VERSION3__)

#include "flash_opt.h"
#include <bl_types.h>
#include <bl_MTK_BB_REG.h>
#include <bl_FOTA.h>
#include <bl_loader.h>
#include <bl_INIT.h>
#include <bl_NFI.h>

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
        case ECC_4_BITS:
            ecc_bits = 4*ECC_PARITY_BITS;
            ecc_cfg |= ECC_CNFG_ECC4;
            break;
        case ECC_6_BITS:
            ecc_bits = 6*ECC_PARITY_BITS;
            ecc_cfg |= ECC_CNFG_ECC6;
            break;
        case ECC_8_BITS:
            ecc_bits = 8*ECC_PARITY_BITS;
            ecc_cfg |= ECC_CNFG_ECC8;
            break;
        case ECC_10_BITS:
            ecc_bits = 10*ECC_PARITY_BITS;
            ecc_cfg |= ECC_CNFG_ECC10;
            break;
        case ECC_12_BITS:
            ecc_bits = 12*ECC_PARITY_BITS;
            ecc_cfg |= ECC_CNFG_ECC12;
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
            ecc_cfg |= DEC_CNFG_CORRECT;
            break;
    }
    DRV_WriteReg32(ECC_DECCNFG, ecc_cfg);
}

/**********************************************************
Description : NFI_Reset
Remark      :
***********************************************************/
void NFI_Reset(void)
{
    DRV_WriteReg(NFI_CON, CON_FIFO_FLUSH|CON_NFI_RST);

    while( DRV_Reg32(NFI_STA) & (STA_NFI_FSM_MASK|STA_NAND_FSM_MASK) );

    while( FIFO_RD_REMAIN(DRV_Reg(NFI_FIFOSTA)) || FIFO_WR_REMAIN(DRV_Reg(NFI_FIFOSTA)) );
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
            BL_nfi_cfg.nfi_fdm_size = 3;
            reg_val |= 3 << PAGEFMT_FDM_SHIFT;
            reg_val |= 3 << PAGEFMT_FDM_ECC_SHIFT;
            BL_ecc_cfg.ecc_level = ECC_8_BITS;
            reg_val |= PAGEFMT_SPARE_16<<PAGEFMT_SPARE_SHIFT;
            BL_nfi_cfg.nfi_spare_size = 16;
            break;
        case 26:
        case 27:
        case 28:
            BL_nfi_cfg.nfi_fdm_size = 6;
            reg_val |= 6 << PAGEFMT_FDM_SHIFT;
            reg_val |= 6 << PAGEFMT_FDM_ECC_SHIFT;
            BL_ecc_cfg.ecc_level = ECC_12_BITS;
            reg_val |= PAGEFMT_SPARE_26<<PAGEFMT_SPARE_SHIFT;
            BL_nfi_cfg.nfi_spare_size = 26;
            break;
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
    U32             timeout     = NFI_ECC_TIMEOUT;
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
                status = NFI_ECC_CORRECTED;
            }
            else
                status = NFI_ECC_UNCORRECT;
        }
    }
    else
    {
        status = NFI_ECC_TIMEOUT;
    }

    return status;
}

/**********************************************************
Description : NFI_PageRead
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

    NFI_Reset();

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
        reg_val |= CNFG_AHB;
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
                    timeout = NORMAL_BUSY_PERIOD;
                    while( ( DRV_Reg(NFI_BYTELEN) < tmp_val) && (--timeout));
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
                                while( (FIFO_RD_EMPTY&DRV_Reg(NFI_FIFOSTA)) && (--timeout));
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
                                while( (FIFO_RD_REMAIN(DRV_Reg(NFI_FIFOSTA)) < 4) && (--timeout));
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
        if(NFI_OPERATION_SUCCESS == status)
        {
            timeout = NORMAL_BUSY_PERIOD;
            WAIT_DEC_READY_WITH_TIMEOUT(timeout)
            if(timeout)
            {
                /* check ECC decoder status */
                for(idx = 0 ; idx < BL_nfi_cfg.nfi_data_sectors ; idx++)
                {
                    timeout = NORMAL_BUSY_PERIOD;
                    while( !(DRV_Reg(ECC_DECDONE) & (1<<idx)) && --timeout );
                    if(timeout)
                    {
                        reg_val = (DRV_Reg(ECC_DECENUM)>>(idx<<2)) & 0xF;
                        if(0xF == reg_val)
                            status = NFI_ECC_UNCORRECT;
                        else if(reg_val)
                            status = NFI_ECC_CORRECTED;
                    }
                    else
                    {
                        status = NFI_ECC_TIMEOUT;
                        break;
                    }
                }
            }
            else
            {
                status = NFI_ECC_TIMEOUT;
            }
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
_RET_CODE NFI_PageRead(kal_uint32 *destination, kal_uint32 *parity, kal_uint32 length, \
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
            if(NFI_BitOneCount(byte_ptr[NAND_BAD_MARK_SPARE_OFFSET], 7) < NAND_GOOD_BLOCK_THRESHOLD)
                return NFI_BAD_BLOCK;
        }
    }
    if(BL_nfi_cfg.nfi_page_size >= 2048) /* 2K bytes or above */
    {
        /* last, and (last-2)th page */
        page_idx = BL_nfi_cfg.nfi_block_size-3;
        for(page_idx = BL_nfi_cfg.nfi_block_size-3 ; page_idx < BL_nfi_cfg.nfi_block_size ; page_idx+=2)
        {
            for(tmp_val = 0 ; tmp_val < BL_nfi_cfg.nfi_sector_num ; tmp_val++)
            {
                status = 
                NFI_SectorRead(page_idx+block_no*BL_nfi_cfg.nfi_block_size, tmp_val*(NAND_SECTOR_SIZE+BL_nfi_cfg.nfi_spare_size), 1, block_check_page_buff, block_check_tmp_spare, KAL_FALSE, KAL_TRUE, KAL_TRUE);
                if(status > NFI_ECC_TIMEOUT)
                    break;
                if(NFI_BitOneCount(byte_ptr[NAND_BAD_MARK_SPARE_OFFSET], 7) < NAND_GOOD_BLOCK_THRESHOLD)
                    return NFI_BAD_BLOCK;
            }
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
#if defined(MT6516) && defined (__APPLICATION_PROCESSOR__)
	*APCG_CLR0 |= CG_CON0_NFI;	// Power-on NFI.
#endif 	// defined(MT6516)

	NFI_Reset();

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

void NFIReconfigure2(void)
{
	// Dummy now. It is used for DAL_Init for second phase. But now NFI v3 does not implement DAL/MTD, so use dummy.
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

    NFI_Reset();

    DRV_WriteReg(NFI_CNFG, BL_SRD_CNFG);
    
    DRV_WriteReg(NFI_CMD, RD_STATUS_CMD);
    while ( (DRV_Reg32(NFI_STA) & STA_CMD_STATE) && (--timeout));

    if(timeout)
    {
        DRV_WriteReg(NFI_CON, (1 << CON_NFI_NOB_SHIFT)|CON_NFI_SRD);

        while ( (0 == FIFO_RD_REMAIN(DRV_Reg(NFI_FIFOSTA))) && (--timeout));

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
    
    NFI_Reset();

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
                        while( (FIFO_WR_REMAIN(DRV_Reg(NFI_FIFOSTA))) && (--timeout) );
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
                        while( (FIFO_WR_REMAIN(DRV_Reg(NFI_FIFOSTA)) > 4) && (--timeout) );
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
                   while( FIFO_WR_REMAIN(DRV_Reg(NFI_FIFOSTA)) && (--timeout) );
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

    NFI_Reset();

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

/**********************************************************
Description : NFI_ReadID
Remark      : content in
              NFI_PAGEFMT, NFI_CNFG, NFI_ADDRNOB, NFI_CON,
              NFI_COLADDR, and NFI_ROWADDR will be changed 
***********************************************************/
void NFI_ReadID(U32 id_num, P_U8 id_data)
{
   U32    idx = 0;

   NFI_Reset();

   DRV_WriteReg(NFI_PAGEFMT, 0);
   DRV_WriteReg(NFI_CNFG, CNFG_BYTE_RW|CNFG_OP_SRD);
   
   /* read NAND flash ID */
   DRV_WriteReg(NFI_CMD,RD_ID_CMD);
   while (DRV_Reg32(NFI_STA) & STA_CMD_STATE);

   DRV_WriteReg32(NFI_COLADDR, 0);
   DRV_WriteReg32(NFI_ROWADDR, 0);
   DRV_WriteReg(NFI_ADDRNOB, 1);
   while (DRV_Reg32(NFI_STA) & STA_ADDR_STATE);

   DRV_WriteReg(NFI_CON, CON_NFI_SRD|(id_num<<CON_NFI_NOB_SHIFT));
   while(DRV_Reg32(NFI_STA) & STA_DATAR_STATE);

   for(idx = 0 ; idx < id_num ; idx++)
   {
      while( FIFO_RD_EMPTY & DRV_Reg(NFI_FIFOSTA));
      id_data[idx] = DRV_Reg32(NFI_DATAR);
   }
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

#if defined(MT6516) && defined (__APPLICATION_PROCESSOR__)
	*APCG_CLR0 |= CG_CON0_NFI;	// Power-on NFI.
#endif 	// defined(MT6516)

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

			RetCode = NFI_PageRead((U32 *)RBufPtr, (U32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize]), 1, BLHeader.NFIinfo.addressCycle, 
				Addr[0], Addr[1], BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_TRUE);
			if (RetCode > NFI_OPERATION_SUCCESS) {

				dbg_print("NFI_PageRead failed.. Block %x Page %x RetCode=%x\n\r", BlockIndex, PageIndex, RetCode);
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

			RetCode = NFI_PageRead((U32 *)RBufPtr, (U32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize]), 1, BLHeader.NFIinfo.addressCycle, 
				Addr[0], Addr[1], BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_TRUE);
			if (RetCode > NFI_OPERATION_SUCCESS) {

				dbg_print("NFI_PageRead failed.. Block %x Page %x RetCode=%x\n\r", BlockIndex, PageIndex, RetCode);
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
			RetCode = NFI_PageRead((U32 *)RBufPtr, (U32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize]), 1, BLHeader.NFIinfo.addressCycle, 
				Addr[0], Addr[1], BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_TRUE);
			if (RetCode > NFI_OPERATION_SUCCESS) {

				dbg_print("NFI_PageRead failed.. Block %x Page %x RetCode=%x\n\r", BlockIndex, PageIndex, RetCode);
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

#endif // defined(__NFI_VERSION3__)

#endif /* _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ */
	
