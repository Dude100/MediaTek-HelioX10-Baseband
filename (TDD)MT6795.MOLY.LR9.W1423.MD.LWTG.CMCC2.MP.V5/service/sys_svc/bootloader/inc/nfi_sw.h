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
 *   NFI_sw.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *   NANDFlash software interface.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef _MTK_BOOTROM_NFI_SW_H_
#define _MTK_BOOTROM_NFI_SW_H_

#include "nfb_header.h"

/*******************************************************************************
 * Macro definition
 *******************************************************************************/

//#define ENABLE_AHB_MODE    

#define NAND_SECTOR_SHIFT             (9)
#define NAND_SECTOR_SIZE              (512)
#define NAND_MAX_SECOTR_NUM           (8)
#define NAND_BAD_MARK_OFFSET          (512)
#define NAND_BAD_MARK_SPARE_OFFSET    (0)
#define NAND_GOOD_BLOCK_THRESHOLD     (6)
#define NAND_MAX_FDM_META_SIZE        (8)
#define MAX_SPARE_SIZE                (28)

#define IO_8BITS                      (0x0000)
#define IO_16BITS                     (0x0001)         


/*******************************************************************************
 * NFI_ReadWithECC and NFI_WriteWithECC Macro definition
 *******************************************************************************/

#define NFI_ATTR_STOP_AT_BLK_BOUNDARY           0x00000001
#define NFI_ATTR_DISABLE_ECC                    0x00000002
#define NFI_ATTR_BYPASS_BEGIN_BLK_CHECK         0x00000004

/*******************************************************************************
 * Type definition
 *******************************************************************************/
typedef enum
{
   //--------- NFI successful code -------------------
    NFI_OPERATION_SUCCESS               = 0x00
   ,NFI_ECC_CORRECTED                   = 0x01
   ,NFI_STOP_AT_BLOCK_BOUNDARY          = 0x02
   ,NFI_ECC_PIO_CORRECTED               = 0x03
   //--------- NFI error code ------------------------
   ,NFI_ERROR                           = 0x30
   ,NFI_BAD_BLOCK                       = NFI_ERROR
   ,NFI_ECC_UNCORRECT                   = 0x31
   ,NFI_ECC_TIMEOUT                     = 0x32
   ,NFI_CMD_TIMEOUT                     = 0x33
   ,NFI_ADDR_TIMEOUT                    = 0x34
   ,NFI_DATA_TIMEOUT                    = 0x35
   ,NFI_PROG_TIMEOUT                    = 0x36
   ,NFI_ERASE_TIMEOUT                   = 0x37
   ,NFI_READ_TIMEOUT                    = 0x38
   ,NFI_RESET_TIMEOUT                   = 0x39
   ,NFI_DEVICE_TIMEOUT                  = 0x3A
   ,NFI_ADDRCNTR_TIMEOUT                = 0x3B
   ,NFI_ENC_IDLE_TIMEOUT                = 0x3C
   ,NFI_PROG_FAILED                     = 0x3D
   ,NFI_ERASE_FAILED                    = 0x3E
   ,NFI_BUF_NOT_4B_ALIGNED              = 0x3F
   ,NFI_INVALID_PARAM                   = 0x40
   ,NFI_LOGIC_BLK_ADDR_EXCEED_TTBL      = 0x41   
   //--------- PIO error code ------------------------   
   ,NFI_ECC_PIO_UNCORRECT               = 0x61   
   ,NFI_ECC_PIO_INVALID_PARAMETER       = 0x62   
   ,NFI_ECC_PIO_EXCEED_MAX_ENCODE_SIZE  = 0x63
   ,NFI_ECC_PIO_PARITY_EXCEED_SIZE      = 0x64
   ,NFI_ECC_PIO_BIT_MODE_UN_SUPPORTED   = 0x65
   ,NFI_ECC_PIO_NON_4BYTE_ALIGNMENT     = 0x66
   ,NFI_ECC_PIO_EXCEED_DECODE_BUFF      = 0x67
   ,NFI_ECC_PIO_MODE_UN_SUPPORTED       = 0x68
   ,NFI_ECC_PIO_DECODE_UN_SUPPORTED     = 0x69
   ,NFI_ECC_PIO_EXCEED_CAPABILITY       = 0x6A
   ,NFI_ECC_PIO_PLACE_EXCEED_AREA       = 0x6B
   ,NFI_ECC_PIO_IRQ_MODE_UN_SUPPORTED   = 0x6C
   ,NFI_ECC_PIO_DONE_TIME_OUT           = 0x6D
   ,NFI_ECC_PIO_VALUE_NULL              = 0x6E
   ,NFI_ECC_PIO_DECENUM_TIME_OUT        = 0x6F
   ,NFI_ECC_PIO_READY_TIME_OUT          = 0x70
   //--------- NFB error code ------------------------
   ,NFB_HEADER_ID_NO_FOUND              = 0xA0
   ,NFB_NO_GOOD_BLOCK                   = 0xA1
   ,NFB_BAD_BLOCK0_GOOD_BLOCK_NO_HEADER = 0xA2
   ,NFB_BL_LENGTH_EXCEED_BL_LINKADDR    = 0xA3
   ,NFB_DATA_EXCEED_HEADER_BLOCK        = 0xA4
   ,NFB_INVALID_LINKADDR                = 0xA5
} NFI_Error_Code;


typedef enum
{
   PARTIAL_OPERATION_SPARE=0,
   PARTIAL_OPERATION_FIRST_HALF_PAGE,
   PARTIAL_OPERATION_SECOND_HALF_PAGE, 
   PARTIAL_OPERATION_1ST_SECTOR,
   PARTIAL_OPERATION_2ND_SECTOR,
   PARTIAL_OPERATION_3RD_SECTOR,
   PARTIAL_OPERATION_4TH_SECTOR,
   PARTIAL_OPERATION_5TH_SECTOR,
   PARTIAL_OPERATION_6TH_SECTOR,
   PARTIAL_OPERATION_7TH_SECTOR,
   PARTIAL_OPERATION_8TH_SECTOR,
   PARTIAL_OPERATION_9TH_SECTOR,
   PARTIAL_OPERATION_10TH_SECTOR,
   PARTIAL_OPERATION_11TH_SECTOR,
   PARTIAL_OPERATION_12TH_SECTOR,
   PARTIAL_OPERATION_13TH_SECTOR,
   PARTIAL_OPERATION_14TH_SECTOR,
   PARTIAL_OPERATION_15TH_SECTOR,
   PARTIAL_OPERATION_16TH_SECTOR,
   PARTIAL_NUM_OF_OPERATIION
} NFI_Partial_Op_st;


typedef enum
{
   NFI_DEDICATED_PIN=0,   
   NFI_8BITS_TYPE,
   NFI_16BITS_TYPE
} NFI_PIN_GROUP_MODE;


typedef enum
{
   NFI_GPIO_INIT=0,
   NFI_GPIO_DEINIT
} NFI_GPIO_STATE;


typedef enum
{
   EMU_WORK_ENABLE=0,
   EMU_WORK_DISABLE
} Emulate_Engine_Work;

typedef enum
{
   BAD_ONE_LINEAR=0,
   BAD_TWO_LINEAR, 
   BAD_101_LINEAR,
   BAD_ANY_LINEAR,
   BAD_ONE_RANDOM,
   BAD_LINEAR_RANDOM,
   BAD_ANY_RANDOM,
   BAD_RANDOM_RANDOM,
   BAD_UNEXPECTED,
   BAD_BURNING_UNEXPECTED,
   BAD_MAX_CASE,
   BAD_DISABLE
} Emulate_Bad_Error_Mode;

typedef enum
{
   ERR_ONE_LINEAR=0,
   ERR_ANY_LINEAR,
   ERR_ONE_RANDOM,
   ERR_LINEAR_RANDOM,
   ERR_1234_LINEAR_RANDOM,
   ERR_nfb_header,
   ERR_recoder_header,
   ERR_nfb_header_5bits,
   ERR_ANY_RANDOM,
   ERR_RANDOM_RANDOM,
   ERR_UNEXPECTED,
   ERR_BURNING_UNEXPECTED,
   ERR_MAX_CASE,
   ERR_DISABLE
} Emulate_Bit_Error_Mode;

typedef enum
{
   EMU_STATE_RUN=0,
   EMU_STATE_IDLE
} Emulate_Engine_State;

typedef enum
{
   EMU_SUCCESS=0,   
   EMU_FINISHED,
   EMU_FAIL
} Emulate_Engine_Status;


typedef enum
{
   MD_SITE=0,
   AP_SITE
} NFI_Owner_Type;

typedef struct _NFIInfo
{
   U16  spareSize;       /* 16 */
   U16  pagesPerBlock;   /* in pages */
} NFI_SUBMENU;

typedef struct _NFIAccess
{
   U32  readAddr1;
   U32  readAddr2;
} NFI_ACCESS;

typedef struct {
   bool   nfi_hw_ecc;
   bool   nfi_auto_fmt;
#if defined(ENABLE_AHB_MODE)   
   bool   nfi_ahb_mode;
#endif
   U32    nfi_page_size;
   U32    nfi_spare_size;
   U32    nfi_pages_per_block;   /* in pages, 32, 64 (SLC) */
   U32    nfi_fdm_size;
   U32    nfi_sector_num;
   U32    nfi_data_sectors;
   U32    nfi_col_num;
   U32    nfi_row_num;
   U32    nfi_io_width;
} NFI_Config_st;

typedef struct {
    U32     m_num;
    P_U32   m_p_entry;
} NFI_TTBL;

/*******************************************************************************
 * Function declaration
 *******************************************************************************/
extern void             NFI_Init(bool bSpeedUp, U32 dwAcccon);
extern void             NFI_DeInit(void);
extern void             NFI_Config(const NFI_MENU *input, const NFI_SUBMENU *sub_para);
extern void             NFI_ConfigByHeader(const NFB_HEADER *pNFB_header);
extern bool             NFI_IsBadBlock(U32 block_no);
extern NFI_Error_Code   NFI_PageRead(U32 row_addr, U32 col_addr, P_U32 main_buff, P_U32 spare_buff);
extern NFI_Error_Code   NFI_SectorRead(U32 page_index, U32 offset, U32 sectors, P_U32 sector_buff, P_U32 spare_buff, bool ahb_mode, bool hw_ecc, bool auto_fmt);
extern NFI_Error_Code   NFI_ReadWithECC(U32 statr_page, void * p_buf, U32 buf_len, U32 attr, P_U32 p_last_page, P_U32 p_rest_len);
extern void             NFI_Reset(void);
extern NFI_Error_Code   NFI_Reset_Device(U32 wait_val_us);
extern void             NFI_TTBL_Enable(U32 num, P_U32 p_entry);
extern void             NFI_TTBL_Disable(void);
extern NFI_Error_Code   NFI_TTBL_Query(U32 log_page_addr, P_U32 p_phy_page_addr);
extern NFI_Error_Code   NFB_Detection(P_U32 p_header_block_dev_addr, NFB_HDR_REPLICATION * p_nfb_hdr_rep);
extern NFI_Error_Code   NFI_ECC_PIO_Decode(P_U32 dbuff_p32, U32 dbuff_size, U32 decode_size, U8 *error_bits);
extern void             NFI_GPIO_config(NFI_GPIO_STATE state);
extern bool             NFI_ByPassToNextNandType(U16 IOInterface);
extern bool             NAND_Boot_IsEnabled(void);
extern bool             NFI_PollingReg_us(P_U32 nfi_reg, U32 mask, bool cond, U32 waitTime_us);
extern const char       blID1[12];
extern const char       blID2[8];

#if defined(__NFI_DVT__)
/*******************************************************************************
 * Utility function declaration
 *******************************************************************************/

typedef struct {
    NFI_MENU    info;
    U32         total_blk;
    U8          pages_per_block;
    U8          id[8];
    U32         chip_select;
} NAND_DeviceTable;

extern const NAND_DeviceTable   *p_device;

extern U8               log_enable;
extern U8               get_error_bits_num;
extern U32              device_idx;
extern U8               device_id[8];
extern U32              nfi_read_buff[4320>>2];
extern U32              nfi_read_spare[224>>2];

extern void             ECC_Invert_Bits(P_U8 buff_ptr, U32 bit_pos);
extern void             NFI_ReadID(U32 id_num, P_U8 id_data);
extern U8               NFI_ReadStatus(void);
extern NFI_Error_Code   NFI_BlockErase(U32 block_index);
extern NFI_Error_Code   NFI_MarkBadBlock(U32 block_index, NFB_HDR_REPLICATION * p_nfb_hdr_rep);
extern NFI_Error_Code   NFI_PageWrite(U32 page_index, U32 col_addr, P_U32 main_buff, P_U32 spare_buff);
extern NFI_Error_Code   NFI_SectorWrite(U32 page_index, U32 offset, U32 sectors, P_U32 sector_buff, P_U32 spare_buff, bool ahb_mode, bool hw_ecc, bool auto_fmt);
extern NFI_Error_Code   NFI_RawProgram(U32 start_block, U32 buff_addr, U32 buff_len);
extern NFI_Error_Code   NFI_WriteWithECC(U32 start_page, void * p_buf, U32 buf_len, U32 attr, P_U32 p_last_page, P_U32 p_rest_len);
extern NFI_Error_Code   NFI_Allocate_Block(U32 start_blk, P_U32 p_good_blk);
extern NFI_Error_Code   NFI_Search_Good_Block(U32 start_blk, P_U32 p_good_blk);
extern void             NFI_Compare_Data(U32 sec_num, P_U8 src_buff, P_U8 src_spare, P_U8 dst_buff, P_U8 dst_spare);
extern void             NFI_AutoDetect(void);
extern void             NFB_ComposeHeader(NFB_HDR_REPLICATION * p_nfb_hdr_rep);
extern bool             NFI_IsOneBitError(U32 src_val , U32 cmp_val, U32 bit_len);
extern void             NFI_ECC_PIO_Init(void);
extern Emulate_Engine_Status NFI_Emulate_Bad_Block(Emulate_Engine_Work work_mode, U8 *data_buff, U32 data_size,
                                                   Emulate_Bad_Error_Mode  set_mode, U8 *error_bit_num, U32 max_random_time, U32 start_addr);
extern NFI_Error_Code   NFI_Simple_Mark_block(U32 block_index, U8 IsBad);
extern NFI_Error_Code   NFI_Scan_Bad(U32 start_block, U8 range);
extern NFI_Error_Code   NFI_Allocate_MultiBlock(U32 start_page, P_U32 p_good_page, U32 byte_size);
extern void             NFI_SetErrorBitsMode(bool error_mode);   
extern void             NFI_ALLBlockErase(void);

#if defined(DEBUG_NFI)
extern void dbg_print(char *fmt,...);
#endif

#endif


#endif /* _MTK_BOOTROM_NFI_SW_H_ */

