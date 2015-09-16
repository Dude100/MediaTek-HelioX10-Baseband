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
 ****************************************************************************/

/*****************************************************************************
 * Filename:
 * ---------
 *   pll_mt6752_md2.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   PLL Related Functions
 *
 * Author:
 * -------
 * -------
 *
 * ===========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * Merging from //MOLY/Development_BRANCHES/MT6752E1_BRING_UP_DEV/mcu/driver/devdrv/pll/...
 *
 * removed!
 * removed!
 *
 ****************************************************************************/

#ifndef __PLL_MT6752_MD2_H__
#define __PLL_MT6752_MD2_H__

#define PLL_PLL_CON1           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x044))
#define PLL_PLL_CON2           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x048))
#define PLL_PLL_CON3           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x04C))

#define PLL_LTEMDPLL_TEST      ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x05C))

#define PLL_CLKSW_CKSEL0       ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x060))
#define PLL_CLKSW_CKSEL1       ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x064))
#define PLL_CLKSW_CKSEL2       ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x068))
#define PLL_CLKSW_CKSEL3       ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x06C))

#define PLL_CLKSW_FDIV0        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x070))
#define PLL_CLKSW_FDIV1        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x074))
#define PLL_CLKSW_FDIV2        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x078))
#define PLL_CLKSW_FDIV3        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x07C))
#define PLL_CLKSW_FDIV4        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x080))
#define PLL_CLKSW_FDIV5        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x084))
#define PLL_CLKSW_FDIV6        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x088))
#define PLL_CLKSW_FDIV7        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x08C))

#define PLL_CLKSW_CONN_CON0    ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x090))

#define PLL_DFS_CON7           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0AC))
#define PLL_DFS_CON8           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0B0))
#define PLL_DFS_CON9           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0B4))

#define PLL_MDPLL_CON0         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x100))
#define PLL_MDPLL_CON1         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x104))
#define PLL_MDPLL_CON2         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x108))
#define PLL_MDPLL_CON3         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x10C))
#define PLL_MDPLL_CON4         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x110))

#define PLL_MCUPLL_CON0        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x140))
#define PLL_MCUPLL_CON1        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x144))
#define PLL_MCUPLL_CON2        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x148))
#define PLL_MCUPLL_CON3        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x14C))

#define PLL_WPLL_CON0          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C0))
#define PLL_WPLL_CON1          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C4))
#define PLL_WPLL_CON2          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C8))
#define PLL_WPLL_CON3          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1CC))

#define PLL_WHPLL_CON0         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x200))
//#define PLL_WHPLL_CON1         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x204))
#define PLL_WHPLL_CON2         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x208))
#define PLL_WHPLL_CON3         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x20C))
#define PLL_WHPLL_CON4         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x210))

#define PLL_ABIST_FQMTR_CON0   ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x400))
#define PLL_ABIST_FQMTR_CON1   ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x404))
#define PLL_ABIST_FQMTR_CON2   ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x408))
#define PLL_ABIST_FQMTR_DATA   ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x40C))

#define PLL_FH_CON0            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x500))
#define PLL_FH_CON1            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x504))
#define PLL_FH_CON2            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x508))
#define PLL_FH_CON3            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x50C))
#define PLL_FH_CON4            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x510))
#define PLL_FH_CON5            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x514))
#define PLL_FH_CON6            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x518))
#define PLL_FH_CON7            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x51C))
//#define PLL_FH_CON8            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x520))
#define PLL_FH_CON9            ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x524))
#define PLL_FH_CON10           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x528))
#define PLL_FH_CON11           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x52C))
#define PLL_FH_CON12           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x530))
#define PLL_FH_CON13           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x534))
#define PLL_FH_CON14           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x538))
#define PLL_FH_CON15           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x53C))
#define PLL_FH_CON16           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x540))
#define PLL_FH_CON17           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x544))
#define PLL_FH_CON18           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x548))
#define PLL_FH_CON19           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x54C))
#define PLL_FH_CON20           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x550))
#define PLL_FH_CON21           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x554))
#define PLL_FH_CON22           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x558))
#define PLL_FH_CON23           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x55C))
#define PLL_FH_CON24           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x560))
#define PLL_FH_CON25           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x564))
#define PLL_FH_CON26           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x568))
#define PLL_FH_CON27           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x56C))
#define PLL_FH_CON28           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x570))
#define PLL_FH_CON29           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x574))
#define PLL_FH_CON30           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x578))
#define PLL_FH_CON31           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x57C))
#define PLL_FH_CON32           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x580))

#define PLL_PLLTD_CON0         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x700))
#define PLL_PLLTD_CON1         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x704))
#define PLL_PLLTD_CON2         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x708))
#define PLL_PLLTD_CON3         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x70C))
#define PLL_PLLTD_CON4         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x710))
#define PLL_PLLTD_CON5         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x714))
#define PLL_PLLTD_CON6         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x718))
#define PLL_PLLTD_CON7         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x71C))

#define PLL_MD_GLOBAL_CON1     ((volatile kal_uint32*)(CONFIG_base+0x45C))

#endif  /* !__PLL_MT6752_MD2_H__ */
