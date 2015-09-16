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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   gpio_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides definition for GPIO mode, direction, pull-up/pull down 
 *   enable, data inversion value.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _GPIO_DEF_H
#define _GPIO_DEF_H

#define MODE_0		0
#define MODE_1		1
#define MODE_2		2
#define MODE_3		3
#define MODE_4		4
#define MODE_5		5
#define MODE_6		6
#define MODE_7		7
#define MODE_NC		0

#define	DIR_NULL		  0
#define	DIR_INPUT		  0
#define	DIR_OUTPUT		1

#define PULL_NULL       1
#define	PULL_DISABLE	0
#define	PULL_ENABLE		1

#define	INV_NULL	    0
#define	INV_DISABLE	  0
#define	INV_ENABLE		1

#define GPIO_CLK0 0
#define GPIO_CLK1 1
#define GPIO_CLK2 2
#define GPIO_CLK3 3
#define GPIO_CLK4 4
#define GPIO_CLK5 5
#define GPIO_CLK6 6
#define GPIO_CLK7 7
#define GPIO_CLK8 8
#define GPIO_CLK9 9
#define GPIO_CLK10 10
#define GPIO_CLK11 11

#define DCT_none_clk 0

#if defined (MT6235) 
#define GPIO_CLKSRC_65mHz 0x0
#define GPIO_CLKSRC_104mHz 0x1
#define GPIO_CLKSRC_52mHz 0x2
#define GPIO_CLKSRC_26mHz 0x3
#define GPIO_CLKSRC_13mHz 0x4
#define GPIO_CLKSRC_32kHz 0x6

#elif defined (MT6256) 
#define GPIO_CLKSRC_52mHz 0xB
#define GPIO_CLKSRC_32kHz 0xC

#elif defined(MT6236)
#define GPIO_CLKSRC_32kHz 0x40

#elif defined(MT6238) || defined(MT6239)
#define GPIO_CLKSRC_32kHz 0x6

#elif defined(MT6268)
#define GPIO_CLKSRC_32kHz 0x40

#elif defined(MT6290)
#define MD_OWNED   0
#define AP_OWNED   1

#endif

#endif /* _GPIO_DEF_H */
