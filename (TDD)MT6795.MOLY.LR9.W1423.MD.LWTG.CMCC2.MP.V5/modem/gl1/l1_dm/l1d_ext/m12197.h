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
 *   m12197.h
 *
 * Project:
 * --------
 *   MT6573
 *
 * Description:
 * ------------
 *   ModemBinUpdate feature
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime:  $
 * $Log:      $
 *
 * removed!
 * removed!
 * .
 * 
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 *******************************************************************************/
#include "m12190.h"

#if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2

#define RFDEF       0xABCD
#define RFDEF_short 0xAB

typedef    unsigned char           uint8;
typedef    unsigned short          uint16;
typedef    unsigned long           uint64;
typedef      signed char           int8;
typedef      signed short          int16;

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

extern void L1D_RF_Custom_Timing_DefaultValue_Handler(void);
extern void L1D_RF_Custom_BPI_DefaultValue_Handler(void);
extern void L1D_RF_Custom_TX_PCL_DefaultValue_Handler(void);
extern void L1D_RF_Custom_APC_Compensate_DefaultValue_Handler(void);
extern void L1D_RF_Custom_TX_Power_Control_DefaultValue_Handler(void);
extern void L1D_RF_Custom_TX_Power_Rollback_DefaultValue_Handler(void);
extern void L1D_RF_Custom_RF_RX_Band_DefaultValue_Handler(void);
extern void L1D_RF_Custom_Others_DefaultValue_Handler(void);
extern void L1D_RF_Custom_AFC_Tracking_DefaultValue_Handler(void);
extern void L1D_RF_Custom_RF_CLK_Buffer_Variable_DefaultValue_Handler(void);
extern void L1D_RF_Custom_RF_TX_Port_DefaultValue_Handler(void);
extern void BPI_Default_Setting(uint16 *dst, uint16 defaultvalue);
extern void Timing_Default_Setting(int16 *dst, int16 defaultvalue);
extern void TX_Default_Setting(int16 *dst, int16 defaultvalue);
extern void Default_Setting_uint8(uint8 *dst, uint8 defaultvalue);
extern void Default_Setting_int8(int8 *dst,int8 defaultvalue);
extern void Default_Setting_int16(int16 *dst, int16 defaultvalue);
extern void L1D_RF_Custom_Others_Update( void );
#endif


