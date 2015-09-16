/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *   br_header_block.h
 *
 * Project:
 * --------
 *   MBL
 *
 * Description:
 * ------------
 *   Structure definition of each region in Header Block 
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_HEADER_BLOCK_H__
#define __BR_HEADER_BLOCK_H__

#include "br_sw_types.h"
#include "br_GFH.h"

#if defined(__NOR_BOOT__)
#include "nor_header.h"
#endif

#if defined(__NAND_BOOT__)
#include "nfb_header.h"
#endif

#if defined(__EMMC_BOOT__)
#include "emmc_header.h"
#endif

#if defined(__SF_BOOT__)
#include "sf_header.h"
#endif

#define MAX_RECORD_SIZE             512

//==============================================================================
// Header Block Region Index
//==============================================================================
typedef enum {
     REGION_IDX_DEV_HEADER      = 0
    ,REGION_IDX_BRLYT           = 1
    ,REGION_IDX_BRTTBL          = 2
    ,REGION_IDX_HB_EPP_PARAM    = 3
    ,REGION_TOTAL_NUM
    ,REGION_IDX_END             = (U8)255
} REGION_IDX;

//==============================================================================
// Region 0: Device Header
//==============================================================================

// Description:
//      Boot device header 
// Location:
//      Region 0
// Remark:
//      Please refer to nfb_header.h/nor_header.h/emmc_header.h/sf_header.h 

//==============================================================================
// Region 1: BRLYT (Boot Region Layout)
//==============================================================================

// Description:
//      Records all the BL's physical start addr and relevant attributes
// Location:
//      Region 1
// Remark:
//      N/A

#define MAX_BL_NUM  8
#define BRLYT_ID    "BRLYT"
#define BRLYT_VER   1

#define BL_EXIST_MAGIC              0x42424242  // represent "BBBB", it means BL has been downloaded 

typedef struct {
    U32             m_bl_exist_magic;

#if defined(WIN32)
    U8              m_bl_dev;               // 1B
    U16             m_bl_type;              // 2B
#else
    GFH_FLASH_DEV   m_bl_dev;               // 1B
    GFH_FILE_TYPE   m_bl_type;              // 2B
#endif

    U32             m_bl_begin_dev_addr;    // device addr that points to the beginning of BL 
                                            // NAND: page addr 
                                            //      SEQUENTIAL: phy page addr
                                            //      TTBL: TTBL logic page addr 
                                            //      FDM5: FDM5.0 logic page addr
                                            // NOR/eMMC/SFlash: byte addr 

    U32             m_bl_boundary_dev_addr; // device addr that points to the boundary of BL 
                                            // boundary addr = BL addr + BL length 
                                            // NAND: page addr 
                                            //      SEQUENTIAL: phy page addr
                                            //      TTBL: TTBL logic page addr 
                                            //      FDM5: FDM5.0 logic page addr
                                            // NOR/eMMC/SFlash: byte addr 

    U32             m_bl_attribute;         // refer to GFH_BL_INFO 
} BL_Descriptor;

typedef struct {
    char            m_identifier[8];        // including '\0'
    U32             m_ver;                  // this structure will directly export to others, version field is necessary
    U32             m_boot_region_dev_addr; // device addr that points to the beginning of the boot region 
                                            // NAND: page addr 
                                            //      SEQUENTIAL: phy page addr
                                            //      TTBL: TTBL logic page addr 
                                            //      FDM5: FDM5.0 logic page addr
                                            // NOR/eMMC/SFlash: byte addr 

    U32             m_main_region_dev_addr; // device addr that points to the beginning of the main code region 
                                            // NAND: page addr 
                                            //      SEQUENTIAL: phy page addr
                                            //      FDM5: FDM5.0 logic page addr
                                            // NOR/eMMC/SFlash: byte addr 
    BL_Descriptor   m_bl_desc[MAX_BL_NUM];
} BR_Layout_v1;

//==============================================================================
// Region 2: BRTTBL (Boot Region Translation Table) For future FDM5.0
//==============================================================================

// Description:
//      Translate BOOTROM logical block addr to physical block addr for FDM5.0
// Location:
//      Region 2
// Remark:
//      1. Currently it only exists for NAND flash boot project 
//      2. Translation addr is stored in m_log2phy_map.m_entry for every 4B.
//         Total counts of m_log2phy_map.m_entry is described by m_log2phy_map.m_num.
//      3. The max size of BR_TransTable must be 512B, m_log2phy_map.m_entry can only record 124 entry at most.
//         Take 512 page size device as an example:
//         Each block represents 16KB, that means all the BLs must be successfully downloaded in 1.95MB(124x16KB) including
//         bad blocks!

#define BRTTBL_ID           "BRTTBL"
#define BRTTBL_VER          1
#define BRTTBL_MAX_ENTRY    124

typedef struct {
    U32                 m_num;
    U32                 m_entry[BRTTBL_MAX_ENTRY];
} Log2Phy_Table;

typedef struct {
    // WARNING! Ensure structure size is exactly 512B 
    char                m_identifier[8];        // including '\0'
    U32                 m_ver;                  // this structure will directly export to others, version field is necessary
    Log2Phy_Table       m_log2phy_map;
} BR_TransTable_v1;

//==============================================================================
// Region 3: HB_EPP_PARAM
//==============================================================================

// Description:
//      Header Block EPP Param, it will pass to EPP as parameter for FlashTool (such as PLL/DRAM setting)
// Location:
//      Region 3
// Remark:
//      The detailed structure declaration is defined in MAUI and FlashTool.

#include "br_GFH_epp_param.h"

//==============================================================================
// Header Block Information
//==============================================================================

typedef union {

    #if defined(__NOR_BOOT__)
    NOR_HEADER_v1       m_nor_hdr;
    #endif

    #if defined(__NAND_BOOT__)
    NFB_HEADER          m_nand_hdr;
    #endif

    #if defined(__EMMC_BOOT__)
    EMMC_HEADER_v1      m_emmc_hdr;
    #endif

    #if defined(__SF_BOOT__)
    SF_HEADER_v1        m_sf_hdr;
    #endif

    // raw data 
    U32                 m_raw_data[MAX_RECORD_SIZE>>2];

} DEV_HDR_U;

typedef union {
    BR_Layout_v1        m_br_layout;
    // raw data 
    U32                 m_raw_data[MAX_RECORD_SIZE>>2];
} BRLYT_U;

typedef union {
    BR_TransTable_v1    m_br_ttbl;
    // raw data 
    U32                 m_raw_data[MAX_RECORD_SIZE>>2];
} BRTTBL_U;

typedef union {
    EPP_Param_v1        m_hb_epp_param;
    // raw data 
    U32                 m_raw_data[MAX_RECORD_SIZE>>2];
} HB_EPP_PARAM_U;

typedef struct {

    U32                 m_hdr_blk_dev_addr;     // header block device addr 

    // ----- region record begin ----- //
    DEV_HDR_U           m_region0_u;            // region 0: device header 
    BRLYT_U             m_region1_u;            // region 1: boot region layout 
    BRTTBL_U            m_region2_u;            // region 2: boot region translation table 
    HB_EPP_PARAM_U      m_region3_u;            // region 3: epp param 

} HeaderBlock_Info;

#endif
