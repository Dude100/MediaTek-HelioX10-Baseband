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
 *   nfb_header.h
 *
 * Project:
 * --------
 *   NAND Booting
 *
 * Description:
 * ------------
 *   NFB header structure.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

#ifndef __NFB_HEADER_H__
#define __NFB_HEADER_H__

#include "br_sw_types.h"

/*******************************************************************************
 * Macro definition
 *******************************************************************************/
#define ECC_PARITY_BYTES    (20)
#define NFB_LOOP_STOP       (100)

/*******************************************************************************
 * Type definition
 *******************************************************************************/
typedef struct _NFIType
{
    U16         IOInterface;     /* IO_8BITS or IO_16BITS */
    U16         pageSize;        /* 512, 2048, 4096 bytes */
    U16         addressCycle;
} NFI_MENU;

typedef struct __NFB_HEADER
{
    char        ID1[12];
    char        version[4];
    char        ID2[8];
    NFI_MENU    NFIinfo;
    U16         spareSize;
    U16         pagesPerBlock;
    U16         totalBlocks;
    U16         pageShift;
    U16         blockShift;
    U32         padding[6];
} NFB_HEADER;

typedef struct {
    NFB_HEADER  nfb_header_body;
    U32         dummy_u32; // It forces the buffer pointer of NFB_HDR_SECTOR to be 4-bytes alignment address.
    char        nfb_dummy[128-sizeof(NFB_HEADER)-4-ECC_PARITY_BYTES];
    U8          nfb_ecc_parities[ECC_PARITY_BYTES];
} NFB_HDR_SECTOR;

#define REPLICATION_NUMBER         (512/sizeof(NFB_HDR_SECTOR))

typedef struct {
    NFB_HDR_SECTOR  nfb_hdr_sec[REPLICATION_NUMBER];
} NFB_HDR_REPLICATION;

#endif // __NFB_HEADER_H__

