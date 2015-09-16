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
 *   Dmdsp_init.h
 *
 * Project:
 * --------
 *   Device Test
 *
 * Description:
 * ------------
 *   Header file for CCIF.
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
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DMDSP_INIT_H__
#define __DMDSP_INIT_H__

#include "reg_base.h"
#include "kal_general_types.h"

#if defined(__DSP_FCORE4__)

/* Define the platform support secure boot */
#if (defined(MT6276) || defined(MT6573) || defined (MT6575) || defined (MT6577)) && !defined(L1D_TEST_COSIM)  /* (MT6276 || MT6573) & !L1D_TEST_COSIM  */
#define __DSP_BOOT_SEC__

/* For smart phone project, there will no ARM BL to ungate DSP */
#if defined(MT6573) || defined (MT6575) || defined (MT6577)
#define __NO_ARM_BL__
#endif /* MT6573 */

#else /* (MT6276 || MT6573) & !L1D_TEST_COSIM */
#define __DSP_BOOT_ORG__
#endif /* (MT6276 || MT6573) & !L1D_TEST_COSIM */


/* Define the common DSP control register */
#define DMDSP_RESETADDR_L  (MDIF_base + 0x0010)
#define DMDSP_RESETADDR_H  (MDIF_base + 0x0014)
#define DMDSP_SRAMINIT_CLR (MDIF_base + 0x0000)
#define DMDSP_RESETOUT_CLR (RGU_base + 0x0014)


extern kal_bool sync_status;


#ifdef __DSP_BOOT_ORG__  /* __DSP_BOOT_ORG__ =========================================================================  */

typedef struct bootup_struct_t
{
    kal_uint32 dsp_sync_value;
    kal_uint32 dsp_bin_load_addr;
    kal_uint32 dsp_bin_back_addr;
    kal_uint32 dsp_jump_addr;
}bootup_struct;


#if defined(INTELL_HEX_TO_BIN)

typedef struct hexstruct_t
{
	kal_int8 	colm;
	kal_int8	ByteCount[2];
	kal_int8	addr[4];
	kal_int8	record_type[2] ;
	kal_int8  data[1];
}hexstruct;


#else /* INTELL_HEX_TO_BIN */

#define MEMINIT_STREAM_IGNORE_BITS 4
#define MI_MAGIC	0xFFFF

#define MI_MEM_BITS     0x03
#define MI_MEM_POS	    0x00
#define MI_MEM_DM	    0x00
#define MI_MEM_PM	    0x01
#define MI_MEM_US	    0x02
/* other values reserved */

#define MI_WS_BITS	    0x3C
#define MI_WS_POS	    0x02
#define MI_WS_8BITS	    0x00
#define MI_WS_16BITS	0x01
#define MI_WS_24BITS	0x02
#define MI_WS_32BITS	0x03
#define MI_WS_40BITS	0x04
#define MI_WS_48BITS	0x05
#define MI_WS_64BITS	0x06
/* other values reserved */

#define MI_BT_BITS	    0x1C0
#define MI_BT_POS	    0x06
#define MI_BT_RAW	    0x00
#define MI_BT_ZERO	    0x01
#define MI_BT_CALL	    0x02
#define MI_BT_REP	    0x03
/* other values reserved */


/* Global header structure */
typedef struct mi_magic_t {
  kal_uint8 version;
  kal_uint8 reserved;
  kal_uint16 magic;
}mi_magic;

/* Block header */
typedef struct mi_block_header_t {
  kal_int8 *addr;
  kal_uint32 byte_count;
  kal_uint32 flags;
  kal_uint32 pattern_bytes;
}mi_block_header;


typedef struct mi_table_header_t {
  mi_magic magic;
  kal_uint32 num_blocks;
  mi_block_header blocks[1];	/* arbitrary number of blocks */
}mi_table_header;

#endif /* INTELL_HEX_TO_BIN */



#if defined(TK6270) || defined(MT6270A)

#define RESETADDR_H 0x9000
#define RESETADDR_L 0x0000

#elif defined(MT6268T) /* TK6270 || MT6270A */

#define RESETADDR_H 0xC000
#define RESETADDR_L 0x0000

#elif defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(MT6577) /* TK6270 || MT6270A */

#define RESETADDR_H 0xE020
#define RESETADDR_L 0x0000

#else  /* TK6270 || MT6270A */

#error "Please define the dsp init register and sram init register"

#endif /* TK6270 || MT6270A */


extern kal_int32 dmdsp_init(void);

#else  /* __DSP_BOOT_ORG__ =========================================================================  */

#define DSP_BL_CONTENT_OFFSET 292

#if defined(MT6276) 

#define DSP_EXEC_START_ADDR         0x10000
#define DSP_EXEC_LEN                0x400000
#define DSP_RESRV_LEN               0x100000
#define DSP_EXEC_JUMP_ADDR          0xE0200000

#elif defined(MT6573) || defined(MT6575) || defined(MT6577)

#if defined(__SMARTPHONE_GPRS_ONLY__)
#define DSP_EXEC_START_ADDR         0x0800000
#elif defined(__UMTS_TDD128_MODE__)
#define DSP_EXEC_START_ADDR         0x1000000
#else
#define DSP_EXEC_START_ADDR         0x1400000
#endif
#define DSP_EXEC_LEN                0x1C0000
#define DSP_RESRV_LEN               0x200000
#define DSP_EXEC_JUMP_ADDR          0xE0200000

#else /* MT6276 */
#error "please define the execution regino of DSP"
#endif /* MT6276 */



/* DSP BL INDICATOR */
#define BL_SYNC_NOT_START           0x55FFFF55
#define BL_SYNC_MAGIC               0x434E5953  /* CNYS */
#define BL_SYNC_DONE                0x454E4F44  /* ENOD */
#define BL_FRST_MAGIC               0x46525354  /* FRST */

#define BL_SYNC_ADDR                (BFMDIF_base + 0x800)
#define BL_LOAD_ADDR                (BFMDIF_base + 0x804)
#define BL_BACK_ADDR                (BFMDIF_base + 0x808)
#define BL_JUMP_ADDR                (BFMDIF_base + 0x80C)


/* extern function */
extern void dmdsp_ungate_dsp(void);
extern kal_bool dmdsp_sync_done(void);

#if !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)
extern kal_int32 dmdsp_init(void);
#else
extern kal_int32 dmdsp_init(kal_uint32 cnt_base_addr);
#endif 

#endif /* __DSP_BOOT_ORG__ =========================================================================  */


#endif /* __DSP__FCORE4__ */

#endif  /* __DMDSP_INIT_H__ */

