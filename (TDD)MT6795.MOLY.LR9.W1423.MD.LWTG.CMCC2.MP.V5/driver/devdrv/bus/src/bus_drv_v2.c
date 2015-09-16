/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * -----------
 *   bus_drv.c
 *
 * Project:
 * -----------
 *   MOLY
 *
 * Description:
 * ------------
 *   Bus Related Driver Code
 *   (Refer to WR8's Bus Driver API Interface, But Not Include Prefetch Buffer API)
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 ****************************************************************************/

#include "kal_general_types.h"
#include "reg_base.h"
#include "bus_drv.h"

/*************************************************************************
 * Define HW register
 *************************************************************************/
#define MD_MCU_CON0         (BASE_MADDR_MDCONFIG+0x100)
#define MD_MCU2EMI_CON0     (BASE_MADDR_MDCONFIG+0x200)

#define MD_SMI_DMA_LARB0_CFG		(volatile kal_uint32 *)(BASE_MADDR_MDCONFIG + 0x0700)
#define MD_SMI_DMA_LARB1_CFG		(volatile kal_uint32 *)(BASE_MADDR_MDCONFIG + 0x0704)
#define MD_SMI_DMA_LARB2_CFG		(volatile kal_uint32 *)(BASE_MADDR_MDCONFIG + 0x0708)
#define MD_SMI_DMA_LARB3_CFG		(volatile kal_uint32 *)(BASE_MADDR_MDCONFIG + 0x070C)
#define MD_SMI_DMA_LARB4_CFG		(volatile kal_uint32 *)(BASE_MADDR_MDCONFIG + 0x0710)
#define MD_SMI_DMA_BW_LIMITER_CFG	(volatile kal_uint32 *)(BASE_MADDR_MDCONFIG + 0x0714)
#define MD_SMI_DMA_COMMIT_THROT		(volatile kal_uint32 *)(BASE_MADDR_MDCONFIG + 0x0718)
#define MD_SMI_DMA_AXI_MON_CFG_0	(volatile kal_uint32 *)(BASE_MADDR_MDCONFIG + 0x071C)

#define MD_BUS_CON1					(volatile kal_uint32 *)(BASE_MADDR_MDCONFIG + 0x0424)
#define MDSYS_INTF_FIFO_DEPTH_CON	(volatile kal_uint32 *)(INFRACFG_AO_BASE + 0x070C)




/*******************************************************************************
 * Locally Used Macro Function
 *******************************************************************************/
#define BUS_REG32(addr)     *(volatile kal_uint32 *)(addr)


#ifdef __MTK_TARGET__ /* should NOT be compiled on MODIS */
/*************************************************************************
* FUNCTION
*  enableVirtualMapping
*
* DESCRIPTION
*  Enable cacheable virtual address mapping: bank F remap to bank 0.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void enableVirtualMapping(void)
{
#if defined(MT6595) || defined(MT6752)
    BUS_REG32(MD_MCU_CON0) = BUS_REG32(MD_MCU_CON0) & (~0xC0000000);
#endif
}

/*************************************************************************
* FUNCTION
*  disableVirtualMapping
*
* DESCRIPTION
*  Disable cacheable virtual address mapping: bank F no remap.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void disableVirtualMapping(void)
{
#if defined(MT6595) || defined(MT6752)
    BUS_REG32(MD_MCU_CON0) = BUS_REG32(MD_MCU_CON0) | 0x80000000;
    BUS_REG32(MD_MCU_CON0) = BUS_REG32(MD_MCU_CON0) & (~0x40000000);
#endif
}

/*************************************************************************
* FUNCTION
*  enableMcuOutstanding
*
* DESCRIPTION
*  Enable MCU to EMI AXI bus outstanding.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void enableMcuOutstanding(void)
{
#if defined(MT6595) || defined(MT6752)
    // Actually Can Do Nothing Here, Since Outstanding is Enabled by Default
    // But to Fit the Function's Meaning, Register Setting is Still Set Here
    BUS_REG32(MD_MCU2EMI_CON0) = BUS_REG32(MD_MCU2EMI_CON0) & (~0x00001000);
#endif
}

void Bus_Init(void)
{
#if defined(MT6752) || defined(MT6595) 

	//the following setting is originally from architecture team c model verification by I-Jou.Chen

	//setting1: smi common setting is AO domain register, from DE Chenfeng.Hsiao comment
	*MD_SMI_DMA_LARB0_CFG = 0x03D00C42;
	*MD_SMI_DMA_LARB1_CFG = 0x034AFC21;
	*MD_SMI_DMA_LARB2_CFG = 0x034A0421;
	*MD_SMI_DMA_LARB3_CFG = 0x03540463;
	*MD_SMI_DMA_LARB4_CFG = 0x004A0424;
	*MD_SMI_DMA_BW_LIMITER_CFG = 0x3FFFFFFF;
	*MD_SMI_DMA_COMMIT_THROT = 0x0;
	*MD_SMI_DMA_AXI_MON_CFG_0 = 0x000041C1;

	*MD_BUS_CON1 = 0x03F37006;

	#if defined(MT6752)
		//setting2: MDSYS_INTF_FIFO_DEPTH_CON |= ((0x1<<1) | (0x1<<5) | (0x1<<7)), from DE BS.Wang
		*MDSYS_INTF_FIFO_DEPTH_CON |= 0xA2;
	#endif

#endif

    return;
}

#endif /* should NOT be compiled on MODIS */
