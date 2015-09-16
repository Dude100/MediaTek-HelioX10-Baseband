/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 *   bl_apbl_share_param.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Structure of share parameters with AP BL
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 * .
 ****************************************************************************/

#ifndef _BLAPBL_SHARE_PARAM_H
#define _BLAPBL_SHARE_PARAM_H

#define BOOT_ARGUMENT_MDINFO_VERSION 1
#define BOOT_ARGUMENT_MAGIC 0x18921892
#define BOOT_ARGUMENT_LOCATION (0xA00)

typedef enum
{
    SHARE_MEM_ITEM_DSP, 
    SHARE_MEM_ITEM_LTE,
    SHARE_MEM_ITEM_MAX
} SHARE_MEM_ITEM_INDEX;


typedef struct {
    SHARE_MEM_ITEM_INDEX index;
    unsigned int version;
    unsigned int start;
    unsigned int bound;
} MDBIN_INFO;

typedef struct {
    unsigned char     flashLsz;            // in Byte (log2), possible value: <= 33
    unsigned char     blkLsz;               // in Byte (log2), possible value: 15,16,17,18
    unsigned char     pageLsz;           // in Byte (log2) , possible value: 9,11,12
    unsigned char     spareSize;         // in Byte per sector, possible value: 16,26,27,28
    unsigned int    rfu[3];
} NFI_INFO;

typedef struct {
    unsigned int magic_number;
    NFI_INFO nfi_info;
    MDBIN_INFO mdbin_info[4];
} BOOT_ARGUMENT;





#endif /*_BLAPBL_SHARE_PARAM_H*/
