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
 *   m12196.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Turn on/off RF components
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *  HISTORY
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
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
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "l1d_cid.h"
#include "l1d_loc_def.h"
#include "l1d_reg.h"
#include "l1d_custom_rf.h"
#include "l1d_rf.h"
#include "m12190.h"

int filter_cal_fail = 0;

/*---------------------------------------------------------------------------*/

#if IS_RF_BRIGHT2
/*BRIGHT2*/ #if IS_FPGA_TARGET
/*BRIGHT2*/ #define DEV_CS    0
/*BRIGHT2*/ #else
/*BRIGHT2*/ #define DEV_CS    1
/*BRIGHT2*/ #endif
/*BRIGHT2*/
/*BRIGHT2*/ void  L1D_RF_PowerOn( void )
/*BRIGHT2*/ {
/*BRIGHT2*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*BRIGHT2*/    IMM_SEND_BPI( 0x0000 );
/*BRIGHT2*/    IMM_SEND_BSI( SCTRL_IMOD(DEV_CS,22), (0x0000L<<4)|0 );
/*BRIGHT2*/    IMM_SEND_BSI( SCTRL_IMOD(DEV_CS,22), (0x0000L<<4)|2 );
/*BRIGHT2*/    IMM_SEND_BSI( SCTRL_IMOD(DEV_CS,22), (  2700L<<4)|5 );
/*BRIGHT2*/    IMM_MODE_END( );
/*BRIGHT2*/ }
/*BRIGHT2*/
/*BRIGHT2*/ void  L1D_RF_PowerOff( void )
/*BRIGHT2*/ {  }
/*BRIGHT2*/
/*BRIGHT2*/ void  L1D_RF_WindowOn( void )
/*BRIGHT2*/ {  }
/*BRIGHT2*/
/*BRIGHT2*/ void  L1D_RF_WindowOff( void )
/*BRIGHT2*/ {  }
#endif

#if IS_RF_BRIGHT4
/*BRIGHT4*/ void  L1D_RF_PowerOn( void )
/*BRIGHT4*/ {
/*BRIGHT4*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*BRIGHT4*/    IMM_SEND_BPI( 0x0000 );
/*BRIGHT4*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000001 );
/*BRIGHT4*/    IMM_SEND_BSI( SCTRL_IMOD(0,20), 0x006764 );
/*BRIGHT4*/    IMM_SEND_BSI( SCTRL_IMOD(0,20), 0x016515 );
/*BRIGHT4*/    IMM_SEND_BSI( SCTRL_IMOD(0,20), 0x014006 );
/*BRIGHT4*/    IMM_SEND_BSI( SCTRL_IMOD(0,20), 0x01440E );
/*BRIGHT4*/    IMM_MODE_END(  );
/*BRIGHT4*/ }
/*BRIGHT4*/
/*BRIGHT4*/ void  L1D_RF_PowerOff( void )
/*BRIGHT4*/ { }
/*BRIGHT4*/
/*BRIGHT4*/ void  L1D_RF_WindowOn( void )
/*BRIGHT4*/ {
/*BRIGHT4*/ #ifndef  L1D_SIM
/*BRIGHT4*/    void L1D_GPO_WriteIO(char, char);
/*BRIGHT4*/    #ifdef __CUST_NEW__
/*BRIGHT4*/    extern const char gpio_rf_control1_pin;
/*BRIGHT4*/    L1D_GPO_WriteIO( 1, gpio_rf_control1_pin);
/*BRIGHT4*/    #else
/*BRIGHT4*/    L1D_GPO_WriteIO( 1, 1 );
/*BRIGHT4*/    #endif
/*BRIGHT4*/ #endif
/*BRIGHT4*/ }
/*BRIGHT4*/
/*BRIGHT4*/ void  L1D_RF_WindowOff( void )
/*BRIGHT4*/ {
/*BRIGHT4*/ #ifndef  L1D_SIM
/*BRIGHT4*/    void L1D_GPO_WriteIO(char, char);
/*BRIGHT4*/    #ifdef __CUST_NEW__
/*BRIGHT4*/    extern const char gpio_rf_control1_pin;
/*BRIGHT4*/    L1D_GPO_WriteIO( 0, gpio_rf_control1_pin);
/*BRIGHT4*/    #else
/*BRIGHT4*/    L1D_GPO_WriteIO( 0, 1 );
/*BRIGHT4*/    #endif
/*BRIGHT4*/ #endif
/*BRIGHT4*/ }
/*BRIGHT4*/
#endif

#if IS_RF_BRIGHT5P
/*BRIGHT5P*/ void  L1D_RF_PowerOn( void )
/*BRIGHT5P*/ {
/*BRIGHT5P*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*BRIGHT5P*/    IMM_SEND_BPI( 0x0000 );
/*BRIGHT5P*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x00000C );
/*BRIGHT5P*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x006545 );
/*BRIGHT5P*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x158306 );
/*BRIGHT5P*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x00BA8E );
/*BRIGHT5P*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), (0x05F696|(BVMODE<<17)) );
/*BRIGHT5P*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), RFSpecialCoef.tx.b5ptx.data.word6_4_0);
/*BRIGHT5P*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), RFSpecialCoef.tx.b5ptx.data.word6_5_0);
/*BRIGHT5P*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), RFSpecialCoef.tx.b5ptx.data.word6_6_0);
/*BRIGHT5P*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), RFSpecialCoef.tx.b5ptx.data.word6_7_0);
/*BRIGHT5P*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000007 );
/*BRIGHT5P*/    IMM_MODE_END(  );
/*BRIGHT5P*/ }
/*BRIGHT5P*/
/*BRIGHT5P*/ void  L1D_RF_PowerOff( void )
/*BRIGHT5P*/ { }
/*BRIGHT5P*/
/*BRIGHT5P*/ void  L1D_RF_WindowOn( void )
/*BRIGHT5P*/ {
/*BRIGHT5P*/ }
/*BRIGHT5P*/
/*BRIGHT5P*/ void  L1D_RF_WindowOff( void )
/*BRIGHT5P*/ {
/*BRIGHT5P*/ }
/*BRIGHT5P*/
#endif

#if IS_RF_AERO
/*AERO*/ void  L1D_RF_PowerOn( void )
/*AERO*/ {
/*AERO*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*AERO*/    IMM_SEND_BPI( 0x0000 );
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000032 );  /* REG 32h, Data 0000h */
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x00043F );  /* REG 3Fh, Data 0010h */
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x0003FE );  /* REG 3Eh, Data 000Fh */
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x00027A );  /* REG 3Ah, Data 0009h */
/*AERO*/
/*AERO*/ #ifdef  EXT_26M
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x020271 );  /* REG 31h, Data 0801h */
/*AERO*/ #else
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x020071 );  /* REG 31h, Data 0801h */
/*AERO*/ #endif
/*AERO*/
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000041 );  /* REG 01h, Data 0001h */
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000001 );  /* REG 01h, Data 0000h */
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000001 );  /* REG 01h, Data 0000h */
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x020083 );  /* REG 03h, Data 0802h */
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x011D04 );  /* REG 04h, Data 0470h */
/*AERO*/
/*AERO*/ #ifdef  EXT_26M
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x06D411 );  /* REG 11h, Data 1A50h */
/*AERO*/ #else
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x069411 );  /* REG 11h, Data 1A50h */
/*AERO*/ #endif
/*AERO*/
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x018152 );  /* REG 12h, Data 0605h */
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000019 );  /* REG 19h, Data 0000h */
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000082 );  /* REG 02h, Data 0002h */
/*AERO*/ #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*AERO*/ /*MT6218B~*/ IMM_SEND_BPI( 0x0200 );
/*AERO*/ #else
/*AERO*/ /*OTHERS*/   IMM_SEND_BPI( 0x80 );
/*AERO*/ #endif
/*AERO*/    WAIT_TIME_QB( 170 );
/*AERO*/    IMM_SEND_BPI( 0x0000 );
/*AERO*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000102 );  /* REG 02h, Data 0004h */
/*AERO*/    IMM_MODE_END(  );
/*AERO*/ }
/*AERO*/
/*AERO*/ void  L1D_RF_PowerOff( void )
/*AERO*/ {
/*AERO*/    unsigned short d16;
/*AERO*/    d16 = HW_READ( BSI_CON );
/*AERO*/    d16 &= (unsigned short)( ~(BSI_DEVICE_0_CS_POLARITY<<4) );
/*AERO*/    HW_WRITE( BSI_CON , d16 );
/*AERO*/ }
/*AERO*/
/*AERO*/ void  L1D_RF_WindowOn( void )
/*AERO*/ {  }
/*AERO*/
/*AERO*/ void  L1D_RF_WindowOff( void )
/*AERO*/ {  }
/*AERO*/
#endif

#if IS_RF_AERO1PLUS
/*AERO1+*/ void  L1D_RF_PowerOn( void )
/*AERO1+*/ {
/*AERO1+*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*AERO1+*/    IMM_SEND_BPI( 0x0000 );
/*AERO1+*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000041 );
/*AERO1+*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000001 );
/*AERO1+*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000001 );
/*AERO1+*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x020083 );
/*AERO1+*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x010004 );
/*AERO1+*/ #ifdef  EXT_26M
/*AERO1+*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x06D411 );
/*AERO1+*/ #else
/*AERO1+*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x069411 );
/*AERO1+*/ #endif
/*AERO1+*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x018152 );
/*AERO1+*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000019 );
/*AERO1+*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000028|((XO_CapID&0x3F)<<6) );
/*AERO1+*/ #ifdef  EXT_26M
/*AERO1+*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000231 );
/*AERO1+*/ #else
/*AERO1+*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000031 );
/*AERO1+*/ #endif
/*AERO1+*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000082 );
/*AERO1+*/ #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*AERO1+*/ /*MT6218B~*/ IMM_SEND_BPI( 0x0200 );
/*AERO1+*/ #else
/*AERO1+*/ /*OTHERS*/   IMM_SEND_BPI( 0x80 );
/*AERO1+*/ #endif
/*AERO1+*/    WAIT_TIME_QB( 170 );
/*AERO1+*/    IMM_SEND_BPI( 0x0000 );
/*AERO1+*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000102 );  /* REG 02h, Data 0004h */
/*AERO1+*/    IMM_MODE_END(  );
/*AERO1+*/ }
/*AERO1+*/
/*AERO1+*/ void  L1D_RF_PowerOff( void )
/*AERO1+*/ {
/*AERO1+*/    unsigned short d16;
/*AERO1+*/    d16 = HW_READ( BSI_CON );
/*AERO1+*/    d16 &= (unsigned short)( ~(BSI_DEVICE_0_CS_POLARITY<<4) );
/*AERO1+*/    HW_WRITE( BSI_CON , d16 );
/*AERO1+*/ }
/*AERO1+*/
/*AERO1+*/ void  L1D_RF_WindowOn( void )
/*AERO1+*/ {  }
/*AERO1+*/
/*AERO1+*/ void  L1D_RF_WindowOff( void )
/*AERO1+*/ {  }
/*AERO1+*/
#endif

#if IS_RF_POLARIS1
/*RFMD*/ void  L1D_RF_PowerOn( void )
/*RFMD*/ {
/*RFMD*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*RFMD*/    IMM_SEND_BPI( 0x0000 );
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,18), 0x01f000 );  /*RESET */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000000 );  /* CFG1 */
/*RFMD*/  //IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x063f19 );  /* CFG2 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x057f19 );  /* CFG2-->ok!! */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x088008 );  /* CFG3 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x17640c );  /*PLL00 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x18e837 );  /*PLL01 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x1e0372 );  /*PLL02 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x088408 );  /* CFG3:0x0aa503 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x1677a0 );  /*PLL10:0x1677a1 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x1ba83b );  /*PLL11:0x1b6c3c */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x1c0368 );  /*PLL12:0x1c435e */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x088808 );  /* CFG3 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x1677b0 );  /*PLL20 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x1ae871 );  /*PLL21 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x1e03a8 );  /*PLL22 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x088c08 );  /* CFG3 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x1677b0 );  /*PLL30 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x1b6876 );  /*PLL31 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x1e03a8 );  /*PLL32 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x204d44 );  /*TXMOD */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x263b83 );  /*PARMP1*/
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x2b230d );  /*PARMP2*/
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x5ba380 );  /*  CAL:0x5ba38a */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x5d4073 );  /* TRSW */
/*RFMD*/  //IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x5d408d );  /* TRSW */
/*RFMD*/  //IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x61ddf0 );  /* TXDT */
/*RFMD*/  //IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x780200 );  /* TEST */
/*RFMD*/  //IMM_SEND_BSI( SCTRL_IMOD(0,18), 0xd12500 );  /* DELAY */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,18), 0x020044 );  /* CRX1 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,18), 0x021600 );  /* CRX2 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,18), 0x022084 );  /* CRX3 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,18), 0x0230e4 );  /* CRX4:0x0234e4 */
/*RFMD*/  //IMM_SEND_BSI( SCTRL_IMOD(0,18), 0x023116 );  /* CRX4 */
/*RFMD*/    IMM_SEND_BSI( SCTRL_IMOD(0,18), 0x024610 );  /* CRX5 */
/*RFMD*/    IMM_MODE_END(  );
/*RFMD*/
/*RFMD*/ #ifndef  L1D_SIM
/*RFMD*/    #ifndef RFVCO_SW_CONTROL /* HW control */
/*RFMD*/       #if IS_CHIP_MT6205
/*RFMD*/       /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*RFMD*/       /*MT6205*/       #ifdef __CUST_NEW__
/*RFMD*/       /*MT6205*/       extern const char gpio_rf_control1_pin;
/*RFMD*/       /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*RFMD*/       /*MT6205*/       #else
/*RFMD*/       /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*RFMD*/       /*MT6205*/       #endif
/*RFMD*/       /*MT6205*/    }
/*RFMD*/       #endif
/*RFMD*/       #if IS_CHIP_MT6218A
/*RFMD*/       /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*RFMD*/       /*MT6218A*/      #ifdef __CUST_NEW__
/*RFMD*/       /*MT6218A*/      extern  const char gpio_rf_control1_pin;
/*RFMD*/       /*MT6218A*/      L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*RFMD*/       /*MT6218A*/      #else
/*RFMD*/       /*MT6218A*/      L1D_GPIO_WriteIO(1,10);
/*RFMD*/       /*MT6218A*/      #endif
/*RFMD*/       /*MT6218A*/   }
/*RFMD*/       #endif
/*RFMD*/       #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*RFMD*/       /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*RFMD*/       /*MT6218B~*/     #ifdef __CUST_NEW__
/*RFMD*/       /*MT6218B~*/     extern  const char gpio_rf_control1_pin;
/*RFMD*/       /*MT6218B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*RFMD*/       /*MT6218B~*/     #else
/*RFMD*/       /*MT6218B~*/     L1D_GPIO_WriteIO(1,13);
/*RFMD*/       /*MT6218B~*/     #endif
/*RFMD*/       /*MT6218B~*/  }
/*RFMD*/       #endif
/*RFMD*/    #endif
/*RFMD*/ #endif
/*RFMD*/ }
/*RFMD*/
/*RFMD*/ void  L1D_RF_PowerOff( void )
/*RFMD*/ {
/*RFMD*/ #ifndef  L1D_SIM
/*RFMD*/    #ifndef RFVCO_SW_CONTROL /* HW control */
/*RFMD*/       #if IS_CHIP_MT6205
/*RFMD*/       /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*RFMD*/       /*MT6205*/       #ifdef __CUST_NEW__
/*RFMD*/       /*MT6205*/       extern const char gpio_rf_control1_pin;
/*RFMD*/       /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*RFMD*/       /*MT6205*/       #else
/*RFMD*/       /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*RFMD*/       /*MT6205*/       #endif
/*RFMD*/       /*MT6205*/    }
/*RFMD*/       #endif
/*RFMD*/       #if IS_CHIP_MT6218A
/*RFMD*/       /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*RFMD*/       /*MT6218A*/      #ifdef __CUST_NEW__
/*RFMD*/       /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*RFMD*/       /*MT6218A*/      L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*RFMD*/       /*MT6218A*/      #else
/*RFMD*/       /*MT6218A*/      L1D_GPIO_WriteIO(0,10);
/*RFMD*/       /*MT6218A*/      #endif
/*RFMD*/       /*MT6218A*/   }
/*RFMD*/       #endif
/*RFMD*/       #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*RFMD*/       /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*RFMD*/       /*MT6218B~*/     #ifdef __CUST_NEW__
/*RFMD*/       /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*RFMD*/       /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*RFMD*/       /*MT6218B~*/     #else
/*RFMD*/       /*MT6218B~*/     L1D_GPIO_WriteIO(0,13);
/*RFMD*/       /*MT6218B~*/     #endif
/*RFMD*/       /*MT6218B~*/  }
/*RFMD*/       #endif
/*RFMD*/    #endif
/*RFMD*/ #endif
/*RFMD*/
/*RFMD*/    IMM_MODE_BEGIN( IMMMASK_BPI );
/*RFMD*/  //IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x?? ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*RFMD*/    IMM_SEND_BPI( 0x0000 );   /*turn off RF by setting the TXEN & RXEN = 0 */
/*RFMD*/    IMM_MODE_END(  );
/*RFMD*/ }
/*RFMD*/
/*RFMD*/ void  L1D_RF_WindowOn( void )
/*RFMD*/ {  }
/*RFMD*/
/*RFMD*/ void  L1D_RF_WindowOff( void )
/*RFMD*/ {  }
/*RFMD*/
#endif

#if IS_RF_SKY74117
extern long dbg_x;
/*SKY74117*/ void  L1D_RF_PowerOn( void )
/*SKY74117*/ {
/*SKY74117*/ #if IS_CHIP_MT6218B_AND_LATTER_VERSION
/*SKY74117*/ /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*SKY74117*/ /*MT6218B~*/     #ifdef __CUST_NEW__
/*SKY74117*/ /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*SKY74117*/ /*MT6218B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*SKY74117*/ /*MT6218B~*/     #else
/*SKY74117*/ /*MT6218B~*/     L1D_GPIO_WriteIO(1,12);
/*SKY74117*/ /*MT6218B~*/     #endif
/*SKY74117*/ /*MT6218B~*/  }
/*SKY74117*/ #endif
/*SKY74117*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*SKY74117*/    IMM_SEND_BPI( 0x0200 );       //enable SXENA
/*SKY74117*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0xC40E02 );   // # SX3
/*SKY74117*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x160028 );   // * TX Control
/*SKY74117*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x00B412 );   // * TX VCO Test
/*SKY74117*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x0A17D6 );   // # TX Loop Test
/*SKY74117*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x837CCA );   // # Mixer Bias Test Register
/*SKY74117*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0xFD2C38 );   /*110KHz BW*/ // # B/W & DC offset control
/*SKY74117*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x595001 );   // * DCOC Timing
/*SKY74117*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x00A91E );   // * UHF VCO Regsiter
/*SKY74117*/
/*SKY74117*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), (0x000022 | (RFSpecialCoef.rx.sky117ip2.data[1].icorrection<<18) | (RFSpecialCoef.rx.sky117ip2.data[1].qcorrection<<12)) );
/*SKY74117*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), (0x000026 | (RFSpecialCoef.rx.sky117ip2.data[2].icorrection<<18) | (RFSpecialCoef.rx.sky117ip2.data[2].qcorrection<<12)) );
/*SKY74117*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), (0x00002A | (RFSpecialCoef.rx.sky117ip2.data[3].icorrection<<18) | (RFSpecialCoef.rx.sky117ip2.data[3].qcorrection<<12)) );
/*SKY74117*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), (0x00002E | (RFSpecialCoef.rx.sky117ip2.data[4].icorrection<<18) | (RFSpecialCoef.rx.sky117ip2.data[4].qcorrection<<12)) );
/*SKY74117*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), (0x00063E | (RFSpecialCoef.rx.sky117ip2.pol[1].qpol<<11) |
/*SKY74117*/                                                (RFSpecialCoef.rx.sky117ip2.pol[2].qpol<<12) |
/*SKY74117*/                                                (RFSpecialCoef.rx.sky117ip2.pol[3].qpol<<13) |
/*SKY74117*/                                                (RFSpecialCoef.rx.sky117ip2.pol[4].qpol<<14) |
/*SKY74117*/                                                (RFSpecialCoef.rx.sky117ip2.pol[1].ipol<<15) |
/*SKY74117*/                                                (RFSpecialCoef.rx.sky117ip2.pol[2].ipol<<16) |
/*SKY74117*/                                                (RFSpecialCoef.rx.sky117ip2.pol[3].ipol<<17) |
/*SKY74117*/                                                (RFSpecialCoef.rx.sky117ip2.pol[4].ipol<<18))
/*SKY74117*/                );
/*SKY74117*/
/*SKY74117*/    IMM_SEND_BPI( 0x0000 );       //disable SXENA
/*SKY74117*/    IMM_MODE_END(  );
/*SKY74117*/ }
/*SKY74117*/
/*SKY74117*/ void  L1D_RF_PowerOff( void )
/*SKY74117*/ {
/*SKY74117*/ #if IS_CHIP_MT6218B_AND_LATTER_VERSION
/*SKY74117*/ /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*SKY74117*/ /*MT6218B~*/     #ifdef __CUST_NEW__
/*SKY74117*/ /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*SKY74117*/ /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*SKY74117*/ /*MT6218B~*/     #else
/*SKY74117*/ /*MT6218B~*/     L1D_GPIO_WriteIO(0,12);
/*SKY74117*/ /*MT6218B~*/     #endif
/*SKY74117*/ /*MT6218B~*/  }
/*SKY74117*/ #endif
/*SKY74117*/ }
/*SKY74117*/
/*SKY74117*/ void  L1D_RF_WindowOn( void )
/*SKY74117*/ {  }
/*SKY74117*/
/*SKY74117*/ void  L1D_RF_WindowOff( void )
/*SKY74117*/ {  }
#endif

#if IS_RF_SKY74400
/*SKY74400*/ unsigned long IP2_COEF[5] =
/*SKY74400*/ {
/*SKY74400*/    0x000000,
/*SKY74400*/    0x000022,
/*SKY74400*/    0x000026,
/*SKY74400*/    0x00002A,
/*SKY74400*/    0x00002E,
/*SKY74400*/ };
/*SKY74400*/ unsigned long IP2_POL = 0x00063E;
/*SKY74400*/ extern long dbg_x;
/*SKY74400*/ void  L1D_RF_PowerOn( void )
/*SKY74400*/ {
/*SKY74400*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*SKY74400*/    IMM_SEND_BPI( 0x0200 );       //enable SXENA
/*SKY74400*/    IMM_SEND_BSI( SCTRL_IMOD(0,24),0x440E02  );
/*SKY74400*/    IMM_SEND_BSI( SCTRL_IMOD(0,24),0x160028  );
/*SKY74400*/    IMM_SEND_BSI( SCTRL_IMOD(0,24),0x00B412  );
/*SKY74400*/    IMM_SEND_BSI( SCTRL_IMOD(0,24),0x0A10D6  );
/*SKY74400*/    IMM_SEND_BSI( SCTRL_IMOD(0,24),0x837CCA  );
/*SKY74400*/    IMM_SEND_BSI( SCTRL_IMOD(0,24),0xFD2C38  );
/*SKY74400*/    IMM_SEND_BSI( SCTRL_IMOD(0,24),0x595001  );
/*SKY74400*/    IMM_SEND_BSI( SCTRL_IMOD(0,24),0x00A51E  );
/*SKY74400*/
/*SKY74400*/    IP2_COEF[1] |= ( (RFSpecialCoef.rx.sky117ip2.data[1].icorrection<<18) | (RFSpecialCoef.rx.sky117ip2.data[1].qcorrection<<12) );
/*SKY74400*/    IP2_COEF[2] |= ( (RFSpecialCoef.rx.sky117ip2.data[2].icorrection<<18) | (RFSpecialCoef.rx.sky117ip2.data[2].qcorrection<<12) );
/*SKY74400*/    IP2_COEF[3] |= ( (RFSpecialCoef.rx.sky117ip2.data[3].icorrection<<18) | (RFSpecialCoef.rx.sky117ip2.data[3].qcorrection<<12) );
/*SKY74400*/    IP2_COEF[4] |= ( (RFSpecialCoef.rx.sky117ip2.data[4].icorrection<<18) | (RFSpecialCoef.rx.sky117ip2.data[4].qcorrection<<12) );
/*SKY74400*/    IP2_POL |= (RFSpecialCoef.rx.sky117ip2.pol[1].qpol<<11) |
/*SKY74400*/               (RFSpecialCoef.rx.sky117ip2.pol[2].qpol<<12) |
/*SKY74400*/               (RFSpecialCoef.rx.sky117ip2.pol[3].qpol<<13) |
/*SKY74400*/               (RFSpecialCoef.rx.sky117ip2.pol[4].qpol<<14) |
/*SKY74400*/               (RFSpecialCoef.rx.sky117ip2.pol[1].ipol<<15) |
/*SKY74400*/               (RFSpecialCoef.rx.sky117ip2.pol[2].ipol<<16) |
/*SKY74400*/               (RFSpecialCoef.rx.sky117ip2.pol[3].ipol<<17) |
/*SKY74400*/               (RFSpecialCoef.rx.sky117ip2.pol[4].ipol<<18);
/*SKY74400*/    IMM_SEND_BSI( SCTRL_IMOD(0,24),IP2_COEF[1]  );
/*SKY74400*/    IMM_SEND_BSI( SCTRL_IMOD(0,24),IP2_COEF[2]  );
/*SKY74400*/    IMM_SEND_BSI( SCTRL_IMOD(0,24),IP2_COEF[3]  );
/*SKY74400*/    IMM_SEND_BSI( SCTRL_IMOD(0,24),IP2_COEF[4]  );
/*SKY74400*/    IMM_SEND_BSI( SCTRL_IMOD(0,24),IP2_POL  );
/*SKY74400*/
/*SKY74400*/    IMM_SEND_BPI( 0x0000 );       //disable SXENA
/*SKY74400*/    IMM_MODE_END(  );
/*SKY74400*/ }
/*SKY74400*/
/*SKY74400*/ void  L1D_RF_PowerOff( void )
/*SKY74400*/ {
/*SKY74400*/ }
/*SKY74400*/
/*SKY74400*/ void  L1D_RF_WindowOn( void )
/*SKY74400*/ {  }
/*SKY74400*/
/*SKY74400*/ void  L1D_RF_WindowOff( void )
/*SKY74400*/ {  }
#endif

#if IS_RF_MT6119
/*MT6119*/ void  L1D_RF_PowerOn( void )
/*MT6119*/ {
/*MT6119*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6119*/    IMM_SEND_BPI( 0x0000 );
/*MT6119*/    IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x020000 );
/*MT6119*/    IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x0000A8|((XO_CapID&0x1F)<<10) );
/*MT6119*/    IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x430185 );  /*CW5 PGAT=00*/
/*MT6119*/    IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x002366 );  /*CW6 IFFST=01 & POLYBW=011*/
/*MT6119*/    IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x004992 );
/*MT6119*/    if(l1d_rf.is_init)
/*MT6119*/    {  /* for power on tx calibration, we program mt6119 to TX mode */
/*MT6119*/       IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x08802L );
/*MT6119*/    }
/*MT6119*/    IMM_MODE_END(  );
/*MT6119*/ }
/*MT6119*/
/*MT6119*/ void  L1D_RF_PowerOff( void )
/*MT6119*/ {
/*MT6119*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6119*/    IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x000002 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*MT6119*/    IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x000006 ); /* VCO SET =0, remove the current leakage */
/*MT6119*/    IMM_MODE_END(  );
/*MT6119*/ }
/*MT6119*/
/*MT6119*/ void  L1D_RF_WindowOn( void )
/*MT6119*/ {  }
/*MT6119*/
/*MT6119*/ void  L1D_RF_WindowOff( void )
/*MT6119*/ {  }
/*MT6119*/
#endif

#if IS_RF_MT6119C
/*MT6119C*/ void  L1D_RF_PowerOn( void )
/*MT6119C*/ {
/*MT6119C*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6119C*/    IMM_SEND_BPI( 0x0000 );
/*MT6119C*/    IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x040000 );
/*MT6119C*/ #ifdef RFVCO_SW_CONTROL
/*MT6119C*/    IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x0280A8|((XO_CapID&0x1F)<<9) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6119C*/ #else
/*MT6119C*/    IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x0080A8|((XO_CapID&0x1F)<<9) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6119C*/ #endif
/*MT6119C*/    IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x630185 );  /*by C.K's request to set TXICMP=1 to improve PCS modulation spectrum performance*/
/*MT6119C*/    IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x002366 );
/*MT6119C*/    IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x124992 );
/*MT6119C*/    #ifndef L1D_SIM
/*MT6119C*/    if(l1d_rf.is_init)
/*MT6119C*/    {  /* for power on tx calibration, we program mt6119 to TX mode */
/*MT6119C*/       IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x128992L );
/*MT6119C*/    }
/*MT6119C*/    #endif
/*MT6119C*/    IMM_MODE_END(  );
/*MT6119C*/
/*MT6119C*/ #ifndef  L1D_SIM
/*MT6119C*/    #ifndef RFVCO_SW_CONTROL /* HW control */
/*MT6119C*/       #if IS_CHIP_MT6205
/*MT6119C*/       /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6119C*/       /*MT6205*/       #ifdef __CUST_NEW__
/*MT6119C*/       /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6119C*/       /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6119C*/       /*MT6205*/       #else
/*MT6119C*/       /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6119C*/       /*MT6205*/       #endif
/*MT6119C*/       /*MT6205*/    }
/*MT6119C*/       #endif
/*MT6119C*/       #if IS_CHIP_MT6218A
/*MT6119C*/       /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6119C*/       /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6119C*/       /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6119C*/       /*MT6218A*/      L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6119C*/       /*MT6218A*/      #else
/*MT6119C*/       /*MT6218A*/      L1D_GPIO_WriteIO(1,10);
/*MT6119C*/       /*MT6218A*/      #endif
/*MT6119C*/       /*MT6218A*/   }
/*MT6119C*/       #endif
/*MT6119C*/       #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6119C*/       /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6119C*/       /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6119C*/       /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6119C*/       /*MT6218B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6119C*/       /*MT6218B~*/     #else
/*MT6119C*/       /*MT6218B~*/     L1D_GPIO_WriteIO(1,13);
/*MT6119C*/       /*MT6218B~*/     #endif
/*MT6119C*/       /*MT6218B~*/  }
/*MT6119C*/       #endif
/*MT6119C*/    #endif
/*MT6119C*/ #endif
/*MT6119C*/ }
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_PowerOff( void )
/*MT6119C*/ {
/*MT6119C*/ #ifndef  L1D_SIM
/*MT6119C*/    #ifndef RFVCO_SW_CONTROL /* HW control */
/*MT6119C*/       #if IS_CHIP_MT6205
/*MT6119C*/       /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6119C*/       /*MT6205*/       #ifdef __CUST_NEW__
/*MT6119C*/       /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6119C*/       /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6119C*/       /*MT6205*/       #else
/*MT6119C*/       /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6119C*/       /*MT6205*/       #endif
/*MT6119C*/       /*MT6205*/    }
/*MT6119C*/       #endif
/*MT6119C*/       #if IS_CHIP_MT6218A
/*MT6119C*/       /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6119C*/       /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6119C*/       /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6119C*/       /*MT6218A*/      L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6119C*/       /*MT6218A*/      #else
/*MT6119C*/       /*MT6218A*/      L1D_GPIO_WriteIO(0,10);
/*MT6119C*/       /*MT6218A*/      #endif
/*MT6119C*/       /*MT6218A*/   }
/*MT6119C*/       #endif
/*MT6119C*/       #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6119C*/       /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6119C*/       /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6119C*/       /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6119C*/       /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6119C*/       /*MT6218B~*/     #else
/*MT6119C*/       /*MT6218B~*/     L1D_GPIO_WriteIO(0,13);
/*MT6119C*/       /*MT6218B~*/     #endif
/*MT6119C*/       /*MT6218B~*/  }
/*MT6119C*/       #endif
/*MT6119C*/    #endif
/*MT6119C*/ #endif
/*MT6119C*/
/*MT6119C*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6119C*/    IMM_SEND_BSI( SCTRL_IMOD(0,23), 0x120992 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*MT6119C*/    IMM_MODE_END(  );
/*MT6119C*/ }
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_WindowOn( void )
/*MT6119C*/ {  }
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_WindowOff( void )
/*MT6119C*/ {  }
/*MT6119C*/
#endif

#if IS_RF_MT6129A
/*MT6129A*/ void  L1D_RF_PowerOn( void )
/*MT6129A*/ {
/*MT6129A*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6129A*/    IMM_SEND_BPI( 0x0000 );
/*MT6129A*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x100000 );
/*MT6129A*/ #ifdef RFVCO_SW_CONTROL
/*MT6129A*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x0D40A0|((XO_CapID&0x1F)<<9) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6129A*/ #else
/*MT6129A*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x0C40A0|((XO_CapID&0x1F)<<9) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6129A*/ #endif
/*MT6129A*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x0312B6 );
/*MT6129A*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x124982 );
/*MT6129A*/ #ifndef L1D_SIM
/*MT6129A*/    if(l1d_rf.is_init)
/*MT6129A*/    {  /* for power on tx calibration, we program mt6119 to TX mode */
/*MT6129A*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x128982L );
/*MT6129A*/    }
/*MT6129A*/ #endif
/*MT6129A*/    IMM_MODE_END(  );
/*MT6129A*/
/*MT6129A*/ #ifndef  L1D_SIM
/*MT6129A*/  #ifndef RFVCO_SW_CONTROL
/*MT6129A*/    #if IS_CHIP_MT6205
/*MT6129A*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6129A*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6129A*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6129A*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129A*/    /*MT6205*/       #else
/*MT6129A*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6129A*/    /*MT6205*/       #endif
/*MT6129A*/    /*MT6205*/    }
/*MT6129A*/    #endif
/*MT6129A*/    #if IS_CHIP_MT6218A
/*MT6129A*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6129A*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6129A*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6129A*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129A*/    /*MT6218A*/      #else
/*MT6129A*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,10);
/*MT6129A*/    /*MT6218A*/      #endif
/*MT6129A*/    /*MT6218A*/   }
/*MT6129A*/    #endif
/*MT6129A*/    #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6129A*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129A*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6129A*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6129A*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129A*/    /*MT6218B~*/     #else
/*MT6129A*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,13);
/*MT6129A*/    /*MT6218B~*/     #endif
/*MT6129A*/    /*MT6218B~*/  }
/*MT6129A*/    #endif
/*MT6129A*/  #endif
/*MT6129A*/ #endif
/*MT6129A*/ }
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_PowerOff( void )
/*MT6129A*/ {
/*MT6129A*/ #ifndef  L1D_SIM
/*MT6129A*/  #ifndef RFVCO_SW_CONTROL
/*MT6129A*/    #if IS_CHIP_MT6205
/*MT6129A*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6129A*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6129A*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6129A*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129A*/    /*MT6205*/       #else
/*MT6129A*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6129A*/    /*MT6205*/       #endif
/*MT6129A*/    /*MT6205*/    }
/*MT6129A*/    #endif
/*MT6129A*/    #if IS_CHIP_MT6218A
/*MT6129A*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6129A*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6129A*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6129A*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129A*/    /*MT6218A*/      #else
/*MT6129A*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,10);
/*MT6129A*/    /*MT6218A*/      #endif
/*MT6129A*/    /*MT6218A*/   }
/*MT6129A*/    #endif
/*MT6129A*/    #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6129A*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129A*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6129A*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6129A*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129A*/    /*MT6218B~*/     #else
/*MT6129A*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,13);
/*MT6129A*/    /*MT6218B~*/     #endif
/*MT6129A*/    /*MT6218B~*/  }
/*MT6129A*/    #endif
/*MT6129A*/  #endif
/*MT6129A*/ #endif
/*MT6129A*/
/*MT6129A*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6129A*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x120982 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*MT6129A*/    IMM_MODE_END(  );
/*MT6129A*/ }
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_WindowOn( void )
/*MT6129A*/ {  }
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_WindowOff( void )
/*MT6129A*/ {  }
/*MT6129A*/
#endif

#if IS_RF_MT6129B
/*MT6129B*/ void  L1D_RF_PowerOn( void )
/*MT6129B*/ {
/*MT6129B*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6129B*/    IMM_SEND_BPI( 0x0000 );
/*MT6129B*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x200000 );
/*MT6129B*/ #ifdef RFVCO_SW_CONTROL
/*MT6129B*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x1AC0A0|(XO_CapID<<9) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6129B*/ #else
/*MT6129B*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x18C0A0|(XO_CapID<<9) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6129B*/ #endif
/*MT6129B*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x0312B6 );
/*MT6129B*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x124982 );
/*MT6129B*/ #ifndef L1D_SIM
/*MT6129B*/    if(l1d_rf.is_init)
/*MT6129B*/    {  /* for power on tx calibration, we program mt6119 to TX mode */
/*MT6129B*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x128982L );
/*MT6129B*/    }
/*MT6129B*/ #endif
/*MT6129B*/    IMM_MODE_END(  );
/*MT6129B*/
/*MT6129B*/ #ifndef  L1D_SIM
/*MT6129B*/  #ifndef RFVCO_SW_CONTROL
/*MT6129B*/    #if IS_CHIP_MT6205
/*MT6129B*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6129B*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6129B*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6129B*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129B*/    /*MT6205*/       #else
/*MT6129B*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6129B*/    /*MT6205*/       #endif
/*MT6129B*/    /*MT6205*/    }
/*MT6129B*/    #endif
/*MT6129B*/    #if IS_CHIP_MT6218A
/*MT6129B*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6129B*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6129B*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6129B*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129B*/    /*MT6218A*/      #else
/*MT6129B*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,10);
/*MT6129B*/    /*MT6218A*/      #endif
/*MT6129B*/    /*MT6218A*/   }
/*MT6129B*/    #endif
/*MT6129B*/    #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6129B*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6129B*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6129B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129B*/    /*MT6218B~*/     #else
/*MT6129B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,13);
/*MT6129B*/    /*MT6218B~*/     #endif
/*MT6129B*/    /*MT6218B~*/  }
/*MT6129B*/    #endif
/*MT6129B*/  #endif
/*MT6129B*/ #endif
/*MT6129B*/ }
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_PowerOff( void )
/*MT6129B*/ {
/*MT6129B*/ #ifndef  L1D_SIM
/*MT6129B*/  #ifndef RFVCO_SW_CONTROL
/*MT6129B*/    #if IS_CHIP_MT6205
/*MT6129B*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6129B*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6129B*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6129B*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129B*/    /*MT6205*/       #else
/*MT6129B*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6129B*/    /*MT6205*/       #endif
/*MT6129B*/    /*MT6205*/    }
/*MT6129B*/    #endif
/*MT6129B*/    #if IS_CHIP_MT6218A
/*MT6129B*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6129B*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6129B*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6129B*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129B*/    /*MT6218A*/      #else
/*MT6129B*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,10);
/*MT6129B*/    /*MT6218A*/      #endif
/*MT6129B*/    /*MT6218A*/   }
/*MT6129B*/    #endif
/*MT6129B*/    #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6129B*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6129B*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6129B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129B*/    /*MT6218B~*/     #else
/*MT6129B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,13);
/*MT6129B*/    /*MT6218B~*/     #endif
/*MT6129B*/    /*MT6218B~*/  }
/*MT6129B*/    #endif
/*MT6129B*/  #endif
/*MT6129B*/ #endif
/*MT6129B*/
/*MT6129B*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6129B*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x120982 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*MT6129B*/    IMM_MODE_END(  );
/*MT6129B*/ }
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_WindowOn( void )
/*MT6129B*/ {  }
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_WindowOff( void )
/*MT6129B*/ {  }
/*MT6129B*/
#endif

#if IS_RF_MT6129C
/*MT6129C*/ void  L1D_RF_PowerOn( void )
/*MT6129C*/ {
/*MT6129C*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6129C*/    IMM_SEND_BPI( 0x0000 );
/*MT6129C*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x200000 );
/*MT6129C*/ #ifdef RFVCO_SW_CONTROL
/*MT6129C*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x1A8180|(XO_CapID<<9) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6129C*/ #else
/*MT6129C*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x188180|(XO_CapID<<9) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6129C*/ #endif
/*MT6129C*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x05E035 );
/*MT6129C*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x0002C6 );
/*MT6129C*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x124982 );
/*MT6129C*/ #ifndef L1D_SIM
/*MT6129C*/    if(l1d_rf.is_init)
/*MT6129C*/    {  /* for power on tx calibration, we program mt6119 to TX mode */
/*MT6129C*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x128982L );
/*MT6129C*/    }
/*MT6129C*/ #endif
/*MT6129C*/    IMM_MODE_END(  );
/*MT6129C*/
/*MT6129C*/ #ifndef  L1D_SIM
/*MT6129C*/  #ifndef RFVCO_SW_CONTROL
/*MT6129C*/    #if IS_CHIP_MT6205
/*MT6129C*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6129C*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6129C*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6129C*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129C*/    /*MT6205*/       #else
/*MT6129C*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6129C*/    /*MT6205*/       #endif
/*MT6129C*/    /*MT6205*/    }
/*MT6129C*/    #endif
/*MT6129C*/    #if IS_CHIP_MT6218A
/*MT6129C*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6129C*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6129C*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6129C*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129C*/    /*MT6218A*/      #else
/*MT6129C*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,10);
/*MT6129C*/    /*MT6218A*/      #endif
/*MT6129C*/    /*MT6218A*/   }
/*MT6129C*/    #endif
/*MT6129C*/    #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6129C*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6129C*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6129C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129C*/    /*MT6218B~*/     #else
/*MT6129C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,13);
/*MT6129C*/    /*MT6218B~*/     #endif
/*MT6129C*/    /*MT6218B~*/  }
/*MT6129C*/    #endif
/*MT6129C*/  #endif
/*MT6129C*/ #endif
/*MT6129C*/ }
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_PowerOff( void )
/*MT6129C*/ {
/*MT6129C*/ #ifndef  L1D_SIM
/*MT6129C*/  #ifndef RFVCO_SW_CONTROL
/*MT6129C*/    #if IS_CHIP_MT6205
/*MT6129C*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6129C*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6129C*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6129C*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129C*/    /*MT6205*/       #else
/*MT6129C*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6129C*/    /*MT6205*/       #endif
/*MT6129C*/    /*MT6205*/    }
/*MT6129C*/    #endif
/*MT6129C*/    #if IS_CHIP_MT6218A
/*MT6129C*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6129C*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6129C*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6129C*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129C*/    /*MT6218A*/      #else
/*MT6129C*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,10);
/*MT6129C*/    /*MT6218A*/      #endif
/*MT6129C*/    /*MT6218A*/   }
/*MT6129C*/    #endif
/*MT6129C*/    #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6129C*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6129C*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6129C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129C*/    /*MT6218B~*/     #else
/*MT6129C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,13);
/*MT6129C*/    /*MT6218B~*/     #endif
/*MT6129C*/    /*MT6218B~*/  }
/*MT6129C*/    #endif
/*MT6129C*/  #endif
/*MT6129C*/ #endif
/*MT6129C*/
/*MT6129C*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6129C*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x120982 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*MT6129C*/    IMM_MODE_END(  );
/*MT6129C*/ }
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_WindowOn( void )
/*MT6129C*/ {  }
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_WindowOff( void )
/*MT6129C*/ {  }
/*MT6129C*/
#endif

#if IS_RF_MT6129D
/*MT6129D*/ void  L1D_RF_PowerOn( void )
/*MT6129D*/ {
/*MT6129D*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6129D*/    IMM_SEND_BPI( 0x0000 );
/*MT6129D*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x200000 );
/*MT6129D*/ #ifdef RFVCO_SW_CONTROL
/*MT6129D*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x1A8080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6129D*/ #else
/*MT6129D*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x188080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6129D*/ #endif
/*MT6129D*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x0002C6 );
/*MT6129D*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x124982 );
/*MT6129D*/ #ifndef L1D_SIM
/*MT6129D*/    if(l1d_rf.is_init)
/*MT6129D*/    {  /* for power on tx calibration, we program mt6119 to TX mode */
/*MT6129D*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x128982L );
/*MT6129D*/    }
/*MT6129D*/ #endif
/*MT6129D*/    IMM_MODE_END(  );
/*MT6129D*/
/*MT6129D*/ #ifndef  L1D_SIM
/*MT6129D*/  #ifndef RFVCO_SW_CONTROL
/*MT6129D*/    #if IS_CHIP_MT6205
/*MT6129D*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6205*/       #else
/*MT6129D*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6129D*/    /*MT6205*/       #endif
/*MT6129D*/    /*MT6205*/    }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6218A
/*MT6129D*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6218A*/      #else
/*MT6129D*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,10);
/*MT6129D*/    /*MT6218A*/      #endif
/*MT6129D*/    /*MT6218A*/   }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219 || IS_CHIP_MT6227
/*MT6129D*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6218B~*/     #else
/*MT6129D*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,13);
/*MT6129D*/    /*MT6218B~*/     #endif
/*MT6129D*/    /*MT6218B~*/  }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6228 || IS_CHIP_MT6229
/*MT6129D*/    /*MT6228B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6228B~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6228B~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6228B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6228B~*/     #else
/*MT6129D*/    /*MT6228B~*/     L1D_GPIO_WriteIO(1,19);
/*MT6129D*/    /*MT6228B~*/     #endif
/*MT6129D*/    /*MT6228B~*/  }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6225_AND_LATTER_VERSION
/*MT6129D*/    /*MT6225~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6225~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6225~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6225~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6225~*/     #else
/*MT6129D*/    /*MT6225~*/     L1D_GPIO_WriteIO(1,28);
/*MT6129D*/    /*MT6225~*/     #endif
/*MT6129D*/    /*MT6225~*/  }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
/*MT6129D*/    /*MT6223~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6223~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6223~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6223~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6223~*/     #else
/*MT6129D*/    /*MT6223~*/     L1D_GPIO_WriteIO(1,23);
/*MT6129D*/    /*MT6223~*/     #endif
/*MT6129D*/    /*MT6223~*/  }
/*MT6129D*/    #endif
/*MT6129D*/  #endif
/*MT6129D*/ #endif
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_PowerOff( void )
/*MT6129D*/ {
/*MT6129D*/ #ifndef  L1D_SIM
/*MT6129D*/  #ifndef RFVCO_SW_CONTROL
/*MT6129D*/    #if IS_CHIP_MT6205
/*MT6129D*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6205*/    #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6205*/    extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6205*/    #else
/*MT6129D*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6129D*/    /*MT6205*/    #endif
/*MT6129D*/    /*MT6205*/    }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6218A
/*MT6129D*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6218A*/      #else
/*MT6129D*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,10);
/*MT6129D*/    /*MT6218A*/      #endif
/*MT6129D*/    /*MT6218A*/   }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219 || IS_CHIP_MT6227
/*MT6129D*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6218B~*/     #else
/*MT6129D*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,13);
/*MT6129D*/    /*MT6218B~*/     #endif
/*MT6129D*/    /*MT6218B~*/  }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6228 || IS_CHIP_MT6229
/*MT6129D*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6218B~*/     #else
/*MT6129D*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,19);
/*MT6129D*/    /*MT6218B~*/     #endif
/*MT6129D*/    /*MT6218B~*/  }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_CHIP_MT6225_AND_LATTER_VERSION
/*MT6129D*/    /*MT6225~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6225~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6225~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6225~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6225~*/     #else
/*MT6129D*/    /*MT6225~*/     L1D_GPIO_WriteIO(0,28);
/*MT6129D*/    /*MT6225~*/     #endif
/*MT6129D*/    /*MT6225~*/  }
/*MT6129D*/    #endif
/*MT6129D*/    #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
/*MT6129D*/    /*MT6223~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6129D*/    /*MT6223~*/     #ifdef __CUST_NEW__
/*MT6129D*/    /*MT6223~*/     extern const char gpio_rf_control1_pin;
/*MT6129D*/    /*MT6223~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6129D*/    /*MT6223~*/     #else
/*MT6129D*/    /*MT6223~*/     L1D_GPIO_WriteIO(0,23);
/*MT6129D*/    /*MT6223~*/     #endif
/*MT6129D*/    /*MT6223~*/  }
/*MT6129D*/    #endif
/*MT6129D*/  #endif
/*MT6129D*/ #endif
/*MT6129D*/
/*MT6129D*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6129D*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x120982 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*MT6129D*/    IMM_MODE_END(  );
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_WindowOn( void )
/*MT6129D*/ {  }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_WindowOff( void )
/*MT6129D*/ {  }
/*MT6129D*/
#endif

#if IS_RF_MT6139B
/*MT6139B*/ void  L1D_RF_PowerOn( void )
/*MT6139B*/ {
/*MT6139B*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6139B*/    IMM_SEND_BPI( 0x0000 );
/*MT6139B*/    IMM_SEND_BSI( SCTRL_IMOD(0,25), 0x0200000 ); //CW0
/*MT6139B*/ #ifdef RFVCO_SW_CONTROL
/*MT6139B*/    IMM_SEND_BSI( SCTRL_IMOD(0,25), 0x50080|(XO_CapID<<10) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6139B*/ #else
/*MT6139B*/    IMM_SEND_BSI( SCTRL_IMOD(0,25), 0x40080|(XO_CapID<<10) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6139B*/ #endif
/*MT6139B*/    IMM_SEND_BSI( SCTRL_IMOD(0,25), 0x0000802 ); //CW2
/*MT6139B*/    IMM_SEND_BSI( SCTRL_IMOD(0,25), 0x0003957 ); //CW7
/*MT6139B*/ #ifndef L1D_SIM
/*MT6139B*/    if(l1d_rf.is_init)
/*MT6139B*/    {  /* for power on tx calibration, we program mt6119 to TX mode */
/*MT6139B*/       IMM_SEND_BSI( SCTRL_IMOD(0,25), 0x0001002L );
/*MT6139B*/    }
/*MT6139B*/ #endif
/*MT6139B*/    IMM_MODE_END(  );
/*MT6139B*/
/*MT6139B*/ #ifndef  L1D_SIM
/*MT6139B*/  #ifndef RFVCO_SW_CONTROL
/*MT6139B*/    #if IS_CHIP_MT6205
/*MT6139B*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6139B*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6139B*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6139B*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6139B*/    /*MT6205*/       #else
/*MT6139B*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6139B*/    /*MT6205*/       #endif
/*MT6139B*/    /*MT6205*/    }
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6218A
/*MT6139B*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6139B*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6139B*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6139B*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6139B*/    /*MT6218A*/      #else
/*MT6139B*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,10);
/*MT6139B*/    /*MT6218A*/      #endif
/*MT6139B*/    /*MT6218A*/   }
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219 || IS_CHIP_MT6227
/*MT6139B*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6139B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6139B*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6139B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6139B*/    /*MT6218B~*/     #else
/*MT6139B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,13);
/*MT6139B*/    /*MT6218B~*/     #endif
/*MT6139B*/    /*MT6218B~*/  }
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6228 || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6139B*/    /*MT6228B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6139B*/    /*MT6228B~*/     #ifdef __CUST_NEW__
/*MT6139B*/    /*MT6228B~*/     extern const char gpio_rf_control1_pin;
/*MT6139B*/    /*MT6228B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6139B*/    /*MT6228B~*/     #else
/*MT6139B*/    /*MT6228B~*/     L1D_GPIO_WriteIO(1,19);
/*MT6139B*/    /*MT6228B~*/     #endif
/*MT6139B*/    /*MT6228B~*/  }
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6225_AND_LATTER_VERSION
/*MT6139B*/    /*MT6225~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6139B*/    /*MT6225~*/     #ifdef __CUST_NEW__
/*MT6139B*/    /*MT6225~*/     extern const char gpio_rf_control1_pin;
/*MT6139B*/    /*MT6225~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6139B*/    /*MT6225~*/     #else
/*MT6139B*/    /*MT6225~*/     L1D_GPIO_WriteIO(1,28);
/*MT6139B*/    /*MT6225~*/     #endif
/*MT6139B*/    /*MT6225~*/  }
/*MT6139B*/    #endif
/*MT6139B*/  #endif
/*MT6139B*/ #endif
/*MT6139B*/ }
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_PowerOff( void )
/*MT6139B*/ {
/*MT6139B*/ #ifndef  L1D_SIM
/*MT6139B*/  #ifndef RFVCO_SW_CONTROL
/*MT6139B*/    #if IS_CHIP_MT6205
/*MT6139B*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6139B*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6139B*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6139B*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6139B*/    /*MT6205*/       #else
/*MT6139B*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6139B*/    /*MT6205*/       #endif
/*MT6139B*/    /*MT6205*/    }
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6218A
/*MT6139B*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6139B*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6139B*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6139B*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6139B*/    /*MT6218A*/      #else
/*MT6139B*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,10);
/*MT6139B*/    /*MT6218A*/      #endif
/*MT6139B*/    /*MT6218A*/   }
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6291 || IS_CHIP_MT6227
/*MT6139B*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6139B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6139B*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6139B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6139B*/    /*MT6218B~*/     #else
/*MT6139B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,13);
/*MT6139B*/    /*MT6218B~*/     #endif
/*MT6139B*/    /*MT6218B~*/  }
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6228 || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6139B*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6139B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6139B*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6139B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6139B*/    /*MT6218B~*/     #else
/*MT6139B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,19);
/*MT6139B*/    /*MT6218B~*/     #endif
/*MT6139B*/    /*MT6218B~*/  }
/*MT6139B*/    #endif
/*MT6139B*/    #if IS_CHIP_MT6225_AND_LATTER_VERSION
/*MT6139B*/    /*MT6225~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6139B*/    /*MT6225~*/     #ifdef __CUST_NEW__
/*MT6139B*/    /*MT6225~*/     extern const char gpio_rf_control1_pin;
/*MT6139B*/    /*MT6225~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6139B*/    /*MT6225~*/     #else
/*MT6139B*/    /*MT6225~*/     L1D_GPIO_WriteIO(0,28);
/*MT6139B*/    /*MT6225~*/     #endif
/*MT6139B*/    /*MT6225~*/  }
/*MT6139B*/    #endif
/*MT6139B*/  #endif
/*MT6139B*/ #endif
/*MT6139B*/
/*MT6139B*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6139B*/    IMM_SEND_BSI( SCTRL_IMOD(0,25), 0x0000002 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*MT6139B*/    IMM_MODE_END(  );
/*MT6139B*/ }
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_WindowOn( void )
/*MT6139B*/ {  }
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_WindowOff( void )
/*MT6139B*/ {  }
/*MT6139B*/
#endif

#if IS_RF_MT6139C
/*MT6139C*/ void  L1D_RF_PowerOn( void )
/*MT6139C*/ {
/*MT6139C*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6139C*/    IMM_SEND_BPI( 0x0000 );
/*MT6139C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0024080 ); //CW0
/*MT6139C*/ #ifdef RFVCO_SW_CONTROL
/*MT6139C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0008080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6139C*/ #else
/*MT6139C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6139C*/ #endif
/*MT6139C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0002802 ); //CW2
/*MT6139C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x1B4E7FB ); //CW11
/*MT6139C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x01C5957 ); //CW7
/*MT6139C*/ #ifndef L1D_SIM
/*MT6139C*/    if(l1d_rf.is_init)
/*MT6139C*/    {  /* for power on tx calibration, we program mt61xx to TX mode */
/*MT6139C*/       IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0003002L );
/*MT6139C*/    }
/*MT6139C*/ #endif
/*MT6139C*/    IMM_MODE_END(  );
/*MT6139C*/
/*MT6139C*/ #ifndef  L1D_SIM
/*MT6139C*/  #ifndef RFVCO_SW_CONTROL
/*MT6139C*/    #if IS_CHIP_MT6205
/*MT6139C*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6139C*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6139C*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6139C*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6139C*/    /*MT6205*/       #else
/*MT6139C*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6139C*/    /*MT6205*/       #endif
/*MT6139C*/    /*MT6205*/    }
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6218A
/*MT6139C*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6139C*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6139C*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6139C*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6139C*/    /*MT6218A*/      #else
/*MT6139C*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,10);
/*MT6139C*/    /*MT6218A*/      #endif
/*MT6139C*/    /*MT6218A*/   }
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219 || IS_CHIP_MT6227
/*MT6139C*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6139C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6139C*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6139C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6139C*/    /*MT6218B~*/     #else
/*MT6139C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,13);
/*MT6139C*/    /*MT6218B~*/     #endif
/*MT6139C*/    /*MT6218B~*/  }
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6228 || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6139C*/    /*MT6228B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6139C*/    /*MT6228B~*/     L1D_GPIO_WriteIO(1,19);
/*MT6139C*/    /*MT6228B~*/  }
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6225_AND_LATTER_VERSION
/*MT6139C*/    /*MT6225~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6139C*/    /*MT6225~*/     #ifdef __CUST_NEW__
/*MT6139C*/    /*MT6225~*/     extern const char gpio_rf_control1_pin;
/*MT6139C*/    /*MT6225~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6139C*/    /*MT6225~*/     #else
/*MT6139C*/    /*MT6225~*/     L1D_GPIO_WriteIO(1,28);
/*MT6139C*/    /*MT6225~*/     #endif
/*MT6139C*/    /*MT6225~*/  }
/*MT6139C*/    #endif
/*MT6139C*/  #endif
/*MT6139C*/ #endif
/*MT6139C*/ }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_PowerOff( void )
/*MT6139C*/ {
/*MT6139C*/ #ifndef  L1D_SIM
/*MT6139C*/  #ifndef RFVCO_SW_CONTROL
/*MT6139C*/    #if IS_CHIP_MT6205
/*MT6139C*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6139C*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6139C*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6139C*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6139C*/    /*MT6205*/       #else
/*MT6139C*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6139C*/    /*MT6205*/       #endif
/*MT6139C*/    /*MT6205*/    }
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6218A
/*MT6139C*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6139C*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6139C*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6139C*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6139C*/    /*MT6218A*/      #else
/*MT6139C*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,10);
/*MT6139C*/    /*MT6218A*/      #endif
/*MT6139C*/    /*MT6218A*/   }
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219 || IS_CHIP_MT6227
/*MT6139C*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6139C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6139C*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6139C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6139C*/    /*MT6218B~*/     #else
/*MT6139C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,13);
/*MT6139C*/    /*MT6218B~*/     #endif
/*MT6139C*/    /*MT6218B~*/  }
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6228 || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6139C*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6139C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6139C*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6139C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6139C*/    /*MT6218B~*/     #else
/*MT6139C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,19);
/*MT6139C*/    /*MT6218B~*/     #endif
/*MT6139C*/    /*MT6218B~*/  }
/*MT6139C*/    #endif
/*MT6139C*/    #if IS_CHIP_MT6225_AND_LATTER_VERSION
/*MT6139C*/    /*MT6225~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6139C*/    /*MT6225~*/     #ifdef __CUST_NEW__
/*MT6139C*/    /*MT6225~*/     extern const char gpio_rf_control1_pin;
/*MT6139C*/    /*MT6225~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6139C*/    /*MT6225~*/     #else
/*MT6139C*/    /*MT6225~*/     L1D_GPIO_WriteIO(0,28);
/*MT6139C*/    /*MT6225~*/     #endif
/*MT6139C*/    /*MT6225~*/  }
/*MT6139C*/    #endif
/*MT6139C*/  #endif
/*MT6139C*/ #endif
/*MT6139C*/
/*MT6139C*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6139C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000002 ); /* MT61xx enters Sleep mode, turn off RF regulators */
/*MT6139C*/    IMM_MODE_END(  );
/*MT6139C*/ }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_WindowOn( void )
/*MT6139C*/ {  }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_WindowOff( void )
/*MT6139C*/ {  }
/*MT6139C*/
#endif

#if IS_RF_MT6139E
/*MT6139E*/ void  L1D_RF_PowerOn( void )
/*MT6139E*/ {
/*MT6139E*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6139E*/    IMM_SEND_BPI( 0x0000 );
/*MT6139E*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0024080 ); //CW0
/*MT6139E*/ #ifdef RFVCO_SW_CONTROL
/*MT6139E*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0008080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6139E*/ #else
/*MT6139E*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6139E*/ #endif
/*MT6139E*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x00E0809 ); //CW9: Power down AM & A DAC
/*MT6139E*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x000000A ); //CW10: Init AM code
/*MT6139E*/  //IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0002802 ); //CW2: Enter Stand-by mode
/*MT6139E*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0002002 ); //CW2: Enter Sleep mode
/*MT6139E*/ #ifndef L1D_SIM
/*MT6139E*/    if(l1d_rf.is_init)
/*MT6139E*/    {  /* for power on tx calibration, we program mt61xx to TX mode */
/*MT6139E*/       IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0003002L );
/*MT6139E*/    }
/*MT6139E*/ #endif
/*MT6139E*/    IMM_MODE_END(  );
/*MT6139E*/
/*MT6139E*/ #ifndef  L1D_SIM
/*MT6139E*/  #ifndef RFVCO_SW_CONTROL
/*MT6139E*/    #if IS_CHIP_MT6205
/*MT6139E*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6139E*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6139E*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6139E*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6139E*/    /*MT6205*/       #else
/*MT6139E*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6139E*/    /*MT6205*/       #endif
/*MT6139E*/    /*MT6205*/    }
/*MT6139E*/    #endif
/*MT6139E*/  #endif
/*MT6139E*/ #endif
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_PowerOff( void )
/*MT6139E*/ {
/*MT6139E*/ #ifndef  L1D_SIM
/*MT6139E*/  #ifndef RFVCO_SW_CONTROL
/*MT6139E*/    #if IS_CHIP_MT6205
/*MT6139E*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6139E*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6139E*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6139E*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6139E*/    /*MT6205*/       #else
/*MT6139E*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6139E*/    /*MT6205*/       #endif
/*MT6139E*/    /*MT6205*/    }
/*MT6139E*/    #endif
/*MT6139E*/  #endif
/*MT6139E*/ #endif
/*MT6139E*/
/*MT6139E*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6139E*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000002 ); /* MT61xx enters Sleep mode, turn off RF regulators */
/*MT6139E*/    IMM_MODE_END(  );
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_WindowOn( void )
/*MT6139E*/ {  }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_WindowOff( void )
/*MT6139E*/ {  }
/*MT6139E*/
#endif

#if IS_RF_MT6140A
/*MT6140A*/ void  L1D_RF_PowerOn( void )
/*MT6140A*/ {
/*MT6140A*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6140A*/    IMM_SEND_BPI( 0x0000 );
/*MT6140A*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0024080 ); //CW0
/*MT6140A*/ #ifdef RFVCO_SW_CONTROL
/*MT6140A*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0008080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6140A*/ #else
/*MT6140A*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6140A*/ #endif
/*MT6140A*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0002802 ); //CW2
/*MT6140A*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x00101E5 ); //CW5 set EDGE BPI control mode ori:0x00101F5
/*MT6140A*/ #ifndef L1D_SIM
/*MT6140A*/    if(l1d_rf.is_init)
/*MT6140A*/    {  /* for power on tx calibration, we program mt6119 to TX mode */
/*MT6140A*/       IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0003002L );
/*MT6140A*/    }
/*MT6140A*/ #endif
/*MT6140A*/    IMM_SEND_BPI( 0x0200 ); //RFVCOEN always on due to FPGA didn't have RFVCO HW control
/*MT6140A*/    IMM_MODE_END(  );
/*MT6140A*/
/*MT6140A*/ #ifndef  L1D_SIM
/*MT6140A*/  #ifndef RFVCO_SW_CONTROL
/*MT6140A*/    #if IS_CHIP_MT6205
/*MT6140A*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6140A*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6140A*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6140A*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6140A*/    /*MT6205*/       #else
/*MT6140A*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6140A*/    /*MT6205*/      #endif
/*MT6140A*/    /*MT6205*/    }
/*MT6140A*/    #endif
/*MT6140A*/    #if IS_CHIP_MT6218A
/*MT6140A*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6140A*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6140A*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6140A*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6140A*/    /*MT6218A*/      #else
/*MT6140A*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,10);
/*MT6140A*/    /*MT6218A*/      #endif
/*MT6140A*/    /*MT6218A*/   }
/*MT6140A*/    #endif
/*MT6140A*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219
/*MT6140A*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6140A*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6140A*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6140A*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6140A*/    /*MT6218B~*/     #else
/*MT6140A*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,13);
/*MT6140A*/    /*MT6218B~*/     #endif
/*MT6140A*/    /*MT6218B~*/  }
/*MT6140A*/    #endif
/*MT6140A*/    #if IS_CHIP_MT6228_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140A*/    /*MT6228B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6140A*/    /*MT6228B~*/     #ifdef __CUST_NEW__
/*MT6140A*/    /*MT6228B~*/     extern const char gpio_rf_control1_pin;
/*MT6140A*/    /*MT6228B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6140A*/    /*MT6228B~*/     #else
/*MT6140A*/    /*MT6228B~*/     L1D_GPIO_WriteIO(1,19);
/*MT6140A*/    /*MT6228B~*/     #endif
/*MT6140A*/    /*MT6228B~*/  }
/*MT6140A*/    #endif
/*MT6140A*/  #endif
/*MT6140A*/ #endif
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_PowerOff( void )
/*MT6140A*/ {
/*MT6140A*/ #ifndef  L1D_SIM
/*MT6140A*/  #ifndef RFVCO_SW_CONTROL
/*MT6140A*/    #if IS_CHIP_MT6205
/*MT6140A*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6140A*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6140A*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6140A*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6140A*/    /*MT6205*/       #else
/*MT6140A*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6140A*/    /*MT6205*/       #endif
/*MT6140A*/    /*MT6205*/    }
/*MT6140A*/    #endif
/*MT6140A*/    #if IS_CHIP_MT6218A
/*MT6140A*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6140A*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6140A*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6140A*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6140A*/    /*MT6218A*/      #else
/*MT6140A*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,10);
/*MT6140A*/    /*MT6218A*/      #endif
/*MT6140A*/    /*MT6218A*/   }
/*MT6140A*/    #endif
/*MT6140A*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219
/*MT6140A*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6140A*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6140A*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6140A*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6140A*/    /*MT6218B~*/     #else
/*MT6140A*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,13);
/*MT6140A*/    /*MT6218B~*/     #endif
/*MT6140A*/    /*MT6218B~*/  }
/*MT6140A*/    #endif
/*MT6140A*/    #if IS_CHIP_MT6228_AND_LATTER_VERSION  || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140A*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6140A*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6140A*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6140A*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6140A*/    /*MT6218B~*/     #else
/*MT6140A*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,19);
/*MT6140A*/    /*MT6218B~*/     #endif
/*MT6140A*/    /*MT6218B~*/  }
/*MT6140A*/    #endif
/*MT6140A*/  #endif
/*MT6140A*/ #endif
/*MT6140A*/
/*MT6140A*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6140A*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000002 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*MT6140A*/    IMM_MODE_END(  );
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_WindowOn( void )
/*MT6140A*/ {  }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_WindowOff( void )
/*MT6140A*/ {  }
/*MT6140A*/
#endif

#if IS_RF_MT6140B
/*MT6140B*/ //const unsigned long SDATA_TABLE[13]=
/*MT6140B*/ //{
/*MT6140B*/ //  0x0018080,//CW0
/*MT6140B*/ //  0x013F001,//CW1
/*MT6140B*/ //  0x0002802,//CW2
/*MT6140B*/ //  0x0000FF3,//CW3
/*MT6140B*/ //  0x00A8714,//CW4
/*MT6140B*/ //  0x00B81F5,//CW5
/*MT6140B*/ //  0x001D016,//CW6
/*MT6140B*/ //  0x00E1957,//CW7
/*MT6140B*/ //  0x0FA0408,//CW8
/*MT6140B*/ //  0x01E0409,//CW9
/*MT6140B*/ //  0x008080A,//CW10
/*MT6140B*/ //  0x105FFFB,//CW11 by Haley TXMODGC_EN=1,ITC=111 for LB testing
/*MT6140B*/ //  0x000000F //CW15
/*MT6140B*/ //};
/*MT6140B*/ void  L1D_RF_PowerOn( void )
/*MT6140B*/ {
/*MT6140B*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6140B*/    IMM_SEND_BPI( 0x0000 );
/*MT6140B*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0054080 ); //CW0
/*MT6140B*/ #ifdef RFVCO_SW_CONTROL
/*MT6140B*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x001C080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6140B*/ #else
/*MT6140B*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0014080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6140B*/ #endif
/*MT6140B*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x20823E2 ); //CW2 enter Sleep mode
/*MT6140B*/    // IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x1070FFB ); //CW11 set VAPC=2.1V
/*MT6140B*/    // IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[2] ); //CW2 enter Stand-by mode
/*MT6140B*/    // IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[1] ); //CW1
/*MT6140B*/    // IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[3] ); //CW3
/*MT6140B*/    // IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[4] ); //CW4
/*MT6140B*/    // IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[5] ); //CW5
/*MT6140B*/    // IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[6] ); //CW6
/*MT6140B*/    // IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[7] ); //CW7
/*MT6140B*/    // IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[8] ); //CW8
/*MT6140B*/    // IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[9] ); //CW9
/*MT6140B*/    // IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[10] ); //CWA
/*MT6140B*/    // IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[11] ); //CWB
/*MT6140B*/    // IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[12] ); //CWF
/*MT6140B*/ #ifndef L1D_SIM
/*MT6140B*/    if(l1d_rf.is_init)
/*MT6140B*/    {  /* for power on tx calibration, we program mt6119 to TX mode */
/*MT6140B*/       IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0003002L );
/*MT6140B*/    }
/*MT6140B*/ #endif
/*MT6140B*/    IMM_SEND_BPI( 0x0200 ); //RFVCOEN always on due to FPGA didn't have RFVCO HW control
/*MT6140B*/    IMM_MODE_END(  );
/*MT6140B*/
/*MT6140B*/ #ifndef  L1D_SIM
/*MT6140B*/  #ifndef RFVCO_SW_CONTROL
/*MT6140B*/    #if IS_CHIP_MT6205
/*MT6140B*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6140B*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6140B*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6140B*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6140B*/    /*MT6205*/       #else
/*MT6140B*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6140B*/    /*MT6205*/       #endif
/*MT6140B*/    /*MT6205*/    }
/*MT6140B*/    #endif
/*MT6140B*/    #if IS_CHIP_MT6218A
/*MT6140B*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6140B*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6140B*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6140B*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6140B*/    /*MT6218A*/      #else
/*MT6140B*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,10);
/*MT6140B*/    /*MT6218A*/      #endif
/*MT6140B*/    /*MT6218A*/   }
/*MT6140B*/    #endif
/*MT6140B*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219
/*MT6140B*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6140B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6140B*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6140B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6140B*/    /*MT6218B~*/     #else
/*MT6140B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,13);
/*MT6140B*/    /*MT6218B~*/     #endif
/*MT6140B*/    /*MT6218B~*/  }
/*MT6140B*/    #endif
/*MT6140B*/    #if IS_CHIP_MT6228_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140B*/    /*MT6228B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6140B*/    /*MT6228B~*/     #ifdef __CUST_NEW__
/*MT6140B*/    /*MT6228B~*/     extern const char gpio_rf_control1_pin;
/*MT6140B*/    /*MT6228B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6140B*/    /*MT6228B~*/     #else
/*MT6140B*/    /*MT6228B~*/     L1D_GPIO_WriteIO(1,19);
/*MT6140B*/    /*MT6228B~*/     #endif
/*MT6140B*/    /*MT6228B~*/  }
/*MT6140B*/    #endif
/*MT6140B*/  #endif
/*MT6140B*/ #endif
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_PowerOff( void )
/*MT6140B*/ {
/*MT6140B*/ #ifndef  L1D_SIM
/*MT6140B*/  #ifndef RFVCO_SW_CONTROL
/*MT6140B*/    #if IS_CHIP_MT6205
/*MT6140B*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6140B*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6140B*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6140B*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6140B*/    /*MT6205*/       #else
/*MT6140B*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6140B*/    /*MT6205*/       #endif
/*MT6140B*/    /*MT6205*/    }
/*MT6140B*/    #endif
/*MT6140B*/    #if IS_CHIP_MT6218A
/*MT6140B*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6140B*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6140B*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6140B*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6140B*/    /*MT6218A*/      #else
/*MT6140B*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,10);
/*MT6140B*/    /*MT6218A*/      #endif
/*MT6140B*/    /*MT6218A*/   }
/*MT6140B*/    #endif
/*MT6140B*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219
/*MT6140B*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6140B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6140B*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6140B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6140B*/    /*MT6218B~*/     #else
/*MT6140B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,13);
/*MT6140B*/    /*MT6218B~*/     #endif
/*MT6140B*/    /*MT6218B~*/  }
/*MT6140B*/    #endif
/*MT6140B*/    #if IS_CHIP_MT6228_AND_LATTER_VERSION  || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140B*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6140B*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6140B*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6140B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6140B*/    /*MT6218B~*/     #else
/*MT6140B*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,19);
/*MT6140B*/    /*MT6218B~*/     #endif
/*MT6140B*/    /*MT6218B~*/  }
/*MT6140B*/    #endif
/*MT6140B*/  #endif
/*MT6140B*/ #endif
/*MT6140B*/
/*MT6140B*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6140B*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000002 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*MT6140B*/    IMM_MODE_END(  );
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_WindowOn( void )
/*MT6140B*/ {  }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_WindowOff( void )
/*MT6140B*/ {  }
/*MT6140B*/
#endif

#if IS_RF_MT6140C
/*MT6140C*/ unsigned long SDATA_TABLE[14]=
/*MT6140C*/ {
/*MT6140C*/    0x0004080,// 0:CW0
/*MT6140C*/    0x013F001,// 1:CW1
/*MT6140C*/    0x20823E2,// 2:CW2
/*MT6140C*/    0x07F3FF3,// 3:CW3
/*MT6140C*/    0x00A8714,// 4:CW4
/*MT6140C*/    0x00041F5,// 5:CW5
/*MT6140C*/    0x001D016,// 6:CW6
/*MT6140C*/    0x0001957,// 7:CW7
/*MT6140C*/    0x0FA0408,// 8:CW8
/*MT6140C*/    0x00E0409,// 9:CW9 //0x03E0409,// 9:CW9  enable AM A calibration loop
/*MT6140C*/    0x002040A,//10:CW10
/*MT6140C*/    0x200070B,//11:CW11
/*MT6140C*/    0x201370C,//12:CW12
/*MT6140C*/    0x000000F //13:CW15
/*MT6140C*/ };
/*MT6140C*/ void  L1D_RF_PowerOn( void )
/*MT6140C*/ {
/*MT6140C*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6140C*/    IMM_SEND_BPI( 0x0000 );
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0044080 ); //CW0
/*MT6140C*/ #ifdef RFVCO_SW_CONTROL
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0008080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6140C*/ #else
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000080|(XO_CapID<<9) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6140C*/ #endif
/*MT6140C*/    /* POR Start */
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[1] ); // 1:CW1
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[2] ); // 2:CW2,enter Sleep mode
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[3] ); // 3:CW3
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[4] ); // 4:CW4
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[5] ); // 5:CW5
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[6] ); // 6:CW6
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[7] ); // 7:CW7
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[8] ); // 8:CW8
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[9] ); // 9:CW9
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[10] );//10:CW10
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[11] );//11:CW11
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[12] );//12:CW12
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[13] );//13:CW15
/*MT6140C*/    /* POR End */
/*MT6140C*/ #ifndef L1D_SIM
/*MT6140C*/    if(l1d_rf.is_init)
/*MT6140C*/    {  /* for power on tx calibration, we program mt6140 to GSM TX mode */
/*MT6140C*/       IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0003002L );
/*MT6140C*/    }
/*MT6140C*/ #endif
/*MT6140C*/    IMM_MODE_END(  );
/*MT6140C*/
/*MT6140C*/ #ifndef  L1D_SIM
/*MT6140C*/  #ifndef RFVCO_SW_CONTROL
/*MT6140C*/    #if IS_CHIP_MT6205
/*MT6140C*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6140C*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6140C*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6140C*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6140C*/    /*MT6205*/       #else
/*MT6140C*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6140C*/    /*MT6205*/       #endif
/*MT6140C*/    /*MT6205*/    }
/*MT6140C*/    #endif
/*MT6140C*/    #if IS_CHIP_MT6218A
/*MT6140C*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6140C*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6140C*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6140C*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6140C*/    /*MT6218A*/      #else
/*MT6140C*/    /*MT6218A*/      L1D_GPIO_WriteIO(1,10);
/*MT6140C*/    /*MT6218A*/      #endif
/*MT6140C*/    /*MT6218A*/   }
/*MT6140C*/    #endif
/*MT6140C*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219
/*MT6140C*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6140C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6140C*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6140C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6140C*/    /*MT6218B~*/     #else
/*MT6140C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(1,13);
/*MT6140C*/    /*MT6218B~*/     #endif
/*MT6140C*/    /*MT6218B~*/  }
/*MT6140C*/    #endif
/*MT6140C*/    #if IS_CHIP_MT6228_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140C*/    /*MT6228B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6140C*/    /*MT6228B~*/     #ifdef __CUST_NEW__
/*MT6140C*/    /*MT6228B~*/     extern const char gpio_rf_control1_pin;
/*MT6140C*/    /*MT6228B~*/     L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6140C*/    /*MT6228B~*/     #else
/*MT6140C*/    /*MT6228B~*/     L1D_GPIO_WriteIO(1,19);
/*MT6140C*/    /*MT6228B~*/     #endif
/*MT6140C*/    /*MT6228B~*/  }
/*MT6140C*/    #endif
/*MT6140C*/  #endif
/*MT6140C*/ #endif
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_PowerOff( void )
/*MT6140C*/ {
/*MT6140C*/ #ifndef  L1D_SIM
/*MT6140C*/  #ifndef RFVCO_SW_CONTROL
/*MT6140C*/    #if IS_CHIP_MT6205
/*MT6140C*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6140C*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6140C*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6140C*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6140C*/    /*MT6205*/       #else
/*MT6140C*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6140C*/    /*MT6205*/       #endif
/*MT6140C*/    /*MT6205*/    }
/*MT6140C*/    #endif
/*MT6140C*/    #if IS_CHIP_MT6218A
/*MT6140C*/    /*MT6218A*/   {  void L1D_GPIO_WriteIO(char, char);
/*MT6140C*/    /*MT6218A*/      #ifdef __CUST_NEW__
/*MT6140C*/    /*MT6218A*/      extern const char gpio_rf_control1_pin;
/*MT6140C*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6140C*/    /*MT6218A*/      #else
/*MT6140C*/    /*MT6218A*/      L1D_GPIO_WriteIO(0,10);
/*MT6140C*/    /*MT6218A*/      #endif
/*MT6140C*/    /*MT6218A*/   }
/*MT6140C*/    #endif
/*MT6140C*/    #if IS_CHIP_MT6218B || IS_CHIP_MT6219
/*MT6140C*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6140C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6140C*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6140C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6140C*/    /*MT6218B~*/     #else
/*MT6140C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,13);
/*MT6140C*/    /*MT6218B~*/     #endif
/*MT6140C*/    /*MT6218B~*/  }
/*MT6140C*/    #endif
/*MT6140C*/    #if IS_CHIP_MT6228_AND_LATTER_VERSION  || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140C*/    /*MT6218B~*/  {  void L1D_GPIO_WriteIO(char, char);
/*MT6140C*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/*MT6140C*/    /*MT6218B~*/     extern const char gpio_rf_control1_pin;
/*MT6140C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6140C*/    /*MT6218B~*/     #else
/*MT6140C*/    /*MT6218B~*/     L1D_GPIO_WriteIO(0,19);
/*MT6140C*/    /*MT6218B~*/     #endif
/*MT6140C*/    /*MT6218B~*/  }
/*MT6140C*/    #endif
/*MT6140C*/  #endif
/*MT6140C*/ #endif
/*MT6140C*/
/*MT6140C*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6140C*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000002 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*MT6140C*/    IMM_MODE_END(  );
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_WindowOn( void )
/*MT6140C*/ {  }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_WindowOff( void )
/*MT6140C*/ {  }
/*MT6140C*/
#endif

#if IS_RF_MT6140D
/*MT6140D*/ unsigned long SDATA_TABLE[14]=
/*MT6140D*/ {
/*MT6140D*/    0x0004090,// 0:CW0  //BSI controlled mode switching & SYNCP=1
/*MT6140D*/    0x013F001,// 1:CW1
/*MT6140D*/    0x20823E2,// 2:CW2
/*MT6140D*/    0x07F3FF3,// 3:CW3
/*MT6140D*/    0x00A8714,// 4:CW4
/*MT6140D*/    0x00041F5,// 5:CW5
/*MT6140D*/    0x001D016,// 6:CW6
/*MT6140D*/    0x0001957,// 7:CW7
/*MT6140D*/    0x0FA0408,// 8:CW8
/*MT6140D*/    0x00E0409,// 9:CW9  //Disable AM&A DCOC //0x03E0409 :enable AM A DCOC
/*MT6140D*/    0x002040A,//10:CW10
/*MT6140D*/    0x200070B,//11:CW11
/*MT6140D*/    0x201370C,//12:CW12
/*MT6140D*/    0x000000F //13:CW15
/*MT6140D*/ };
/*MT6140D*/ void  L1D_RF_PowerOn( void )
/*MT6140D*/ {
/*MT6140D*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6140D*/    IMM_SEND_BPI( 0x0000 );
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0044090 ); //CW0
/*MT6140D*/ #ifdef RFVCO_SW_CONTROL
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0008090|(XO_CapID<<9) );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*MT6140D*/ #else
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000090|(XO_CapID<<9) );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MT6140D*/ #endif
/*MT6140D*/    /* POR Start */
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[1] ); // 1:CW1
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[2] ); // 2:CW2,enter Sleep mode
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[3] ); // 3:CW3
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[4] ); // 4:CW4
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[5] ); // 5:CW5
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[6] ); // 6:CW6
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[7] ); // 7:CW7
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[8] ); // 8:CW8
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[9] ); // 9:CW9
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[10] );//10:CW10
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[11] );//11:CW11
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[12] );//12:CW12
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[13] );//13:CW15
/*MT6140D*/    /* POR End */
/*MT6140D*/ #ifndef L1D_SIM
/*MT6140D*/    if(l1d_rf.is_init)
/*MT6140D*/    {  /* for power on tx calibration, we program mt6140 to GSM TX mode */
/*MT6140D*/       IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0003002L );
/*MT6140D*/    }
/*MT6140D*/ #endif
/*MT6140D*/    IMM_MODE_END(  );
/*MT6140D*/
/*MT6140D*/ #ifndef  L1D_SIM
/*MT6140D*/  #ifndef RFVCO_SW_CONTROL
/*MT6140D*/    #if IS_CHIP_MT6205
/*MT6140D*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6140D*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6140D*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6140D*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*MT6140D*/    /*MT6205*/       #else
/*MT6140D*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*MT6140D*/    /*MT6205*/       #endif
/*MT6140D*/    /*MT6205*/    }
/*MT6140D*/    #endif
/*MT6140D*/    #if  0//IS_CHIP_MT6218A
/* under construction !*/
/*MT6140D*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140D*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6140D*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6140D*/    #endif
/*MT6140D*/    #if  0//IS_CHIP_MT6218B || IS_CHIP_MT6219
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140D*/    #endif
/*MT6140D*/    #if  0//IS_CHIP_MT6228_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6140D*/    /*MT6228B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140D*/    /*MT6228B~*/     #else
/* under construction !*/
/*MT6140D*/    /*MT6228B~*/     #endif
/* under construction !*/
/*MT6140D*/    #endif
/*MT6140D*/  #endif
/*MT6140D*/ #endif
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_PowerOff( void )
/*MT6140D*/ {
/*MT6140D*/ #ifndef  L1D_SIM
/*MT6140D*/  #ifndef RFVCO_SW_CONTROL
/*MT6140D*/    #if IS_CHIP_MT6205
/*MT6140D*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*MT6140D*/    /*MT6205*/       #ifdef __CUST_NEW__
/*MT6140D*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*MT6140D*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*MT6140D*/    /*MT6205*/       #else
/*MT6140D*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*MT6140D*/    /*MT6205*/       #endif
/*MT6140D*/    /*MT6205*/    }
/*MT6140D*/    #endif
/*MT6140D*/    #if  0//IS_CHIP_MT6218A
/* under construction !*/
/*MT6140D*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140D*/    /*MT6218A*/      #else
/* under construction !*/
/*MT6140D*/    /*MT6218A*/      #endif
/* under construction !*/
/*MT6140D*/    #endif
/*MT6140D*/    #if  0//IS_CHIP_MT6218B || IS_CHIP_MT6219
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140D*/    #endif
/*MT6140D*/    #if  0//IS_CHIP_MT6228_AND_LATTER_VERSION  || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #else
/* under construction !*/
/*MT6140D*/    /*MT6218B~*/     #endif
/* under construction !*/
/*MT6140D*/    #endif
/*MT6140D*/  #endif
/*MT6140D*/ #endif
/*MT6140D*/
/*MT6140D*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6140D*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0000002 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*MT6140D*/    IMM_MODE_END(  );
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_WindowOn( void )
/*MT6140D*/ {  }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_WindowOff( void )
/*MT6140D*/ {  }
/*MT6140D*/
#endif

#if IS_RF_CMOSEDGE
/*CMOSEDGE*/ unsigned long SDATA_TABLE[27]=
/*CMOSEDGE*/ {
/*CMOSEDGE*/    0x00404D1,// 0:CW0
/*CMOSEDGE*/    0x0120000,// 1:CW1
/*CMOSEDGE*/    0x0210000,// 2:CW2
/*CMOSEDGE*/    0x0300040,// 3:CW3
/*CMOSEDGE*/    0x040003F,// 4:CW4
/*CMOSEDGE*/    0x055FEAD,// 5:CW5
/*CMOSEDGE*/    0x061CC88,// 6:CW6
/*CMOSEDGE*/    0x07176A1,// 7:CW7
/*CMOSEDGE*/    0x080A004,// 8:CW8
/*CMOSEDGE*/    0x093E706,// 9:CW9
/*CMOSEDGE*/    0x0A0F540,//10:CW10
/*CMOSEDGE*/    0x0B0021F,//11:CW11
/*CMOSEDGE*/    0x0C28BFF,//12:CW12
/*CMOSEDGE*/    0x0D100F1,//13:CW13
/*CMOSEDGE*/    0x0E015FC,//14:CW14
/*CMOSEDGE*/    0x0F12D4A,//15:CW15
/*CMOSEDGE*/    0x102DDB5,//16:CW16
/*CMOSEDGE*/    0x110000F,//17:CW17
/*CMOSEDGE*/    0x121124F,//18:CW18
/*CMOSEDGE*/    0x13D066A,//19:CW19
/*CMOSEDGE*/    0x14001AA,//20:CW20
/*CMOSEDGE*/    0x1587F0A,//21:CW21
/*CMOSEDGE*/    0x1684200,//22:CW22
/*CMOSEDGE*/    0x1784200,//23:CW23
/*CMOSEDGE*/    0x1810820,//24:CW24
/*CMOSEDGE*/    0x1900000,//25:CW25
/*CMOSEDGE*/    0x1F00000,//26:CW31
/*CMOSEDGE*/ };
/*CMOSEDGE*/ void  L1D_RF_PowerOn( void )
/*CMOSEDGE*/ {
/*CMOSEDGE*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*CMOSEDGE*/    IMM_SEND_BPI( 0x0000 );
/*CMOSEDGE*/    /* POR Start */
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[0] ); // 0:CW0
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[1] ); // 1:CW1
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[2] ); // 2:CW2,enter Sleep mode
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), (SDATA_TABLE[3]&~0x000007F)|XO_CapID|(l1d_rf.AFC_data<<7) ); // 3:CW3
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[4] ); // 4:CW4
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), (SDATA_TABLE[5]&~0x0040000)|(RFSpecialCoef.tx.CMOSEDGEtx.isDCXO<<18) ); // 5:CW5
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[6] ); // 6:CW6
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[7] ); // 7:CW7
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[8] ); // 8:CW8
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[9] ); // 9:CW9
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[10] );//10:CW10
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), (SDATA_TABLE[11]&~0x00003FE)|(RFSpecialCoef.tx.CMOSEDGEtx.ref_temp<<5) );//11:CW11
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[12] );//12:CW12
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[13] );//13:CW13
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[14] );//14:CW14
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[15] );//15:CW15
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[16] );//16:CW16
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[17] );//17:CW17
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[18] );//18:CW18
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[19] );//19:CW19
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[20] );//20:CW20
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[21] );//21:CW21
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[22] );//22:CW22
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[23] );//23:CW23
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[24] );//24:CW24
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[25] );//25:CW25
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[26] );//26:CW31
/*CMOSEDGE*/    /* POR End */
/*CMOSEDGE*/ #ifndef L1D_SIM
/*CMOSEDGE*/    if(l1d_rf.is_init)
/*CMOSEDGE*/    {
/*CMOSEDGE*/    #ifdef RFVCO_SW_CONTROL
/*CMOSEDGE*/       IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x00C06D1 );  /*[CW0-VCOSEL]=1: RFVCO_SW_CONTROL*/
/*CMOSEDGE*/    #else
/*CMOSEDGE*/       IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x00C04D1 );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/     /* for power on tx calibration, we program CMOSEDGE to GSM TX mode */
/*CMOSEDGE*/       IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0E01201L );
/*CMOSEDGE*/    }
/*CMOSEDGE*/ #endif
/*CMOSEDGE*/    IMM_MODE_END(  );
/*CMOSEDGE*/
/*CMOSEDGE*/
/*CMOSEDGE*/ #ifndef  L1D_SIM
/*CMOSEDGE*/  #ifndef RFVCO_SW_CONTROL
/*CMOSEDGE*/    #if IS_CHIP_MT6205
/*CMOSEDGE*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*CMOSEDGE*/    /*MT6205*/       #ifdef __CUST_NEW__
/*CMOSEDGE*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*CMOSEDGE*/    /*MT6205*/       L1D_GPIO_WriteIO(1,gpio_rf_control1_pin);
/*CMOSEDGE*/    /*MT6205*/       #else
/*CMOSEDGE*/    /*MT6205*/       L1D_GPIO_WriteIO(1,7);
/*CMOSEDGE*/    /*MT6205*/       #endif
/*CMOSEDGE*/    /*MT6205*/    }
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/    #if  0//IS_CHIP_MT6218A
/* under construction !*/
/*CMOSEDGE*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    /*MT6218A*/      #else
/* under construction !*/
/*CMOSEDGE*/    /*MT6218A*/      #endif
/* under construction !*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/    #if  0//IS_CHIP_MT6218B || IS_CHIP_MT6219
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #else
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #endif
/* under construction !*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/    #if 0//IS_CHIP_MT6228_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*CMOSEDGE*/    /*MT6228B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    /*MT6228B~*/     #else
/* under construction !*/
/*CMOSEDGE*/    /*MT6228B~*/     #endif
/* under construction !*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/  #endif
/*CMOSEDGE*/ #endif
/*CMOSEDGE*/ }
/*CMOSEDGE*/
/*CMOSEDGE*/ void  L1D_RF_PowerOff( void )
/*CMOSEDGE*/ {
/*CMOSEDGE*/ #ifndef  L1D_SIM
/*CMOSEDGE*/  #ifndef RFVCO_SW_CONTROL
/*CMOSEDGE*/    #if IS_CHIP_MT6205
/*CMOSEDGE*/    /*MT6205*/    {  void L1D_GPIO_WriteIO(char, char);
/*CMOSEDGE*/    /*MT6205*/       #ifdef __CUST_NEW__
/*CMOSEDGE*/    /*MT6205*/       extern const char gpio_rf_control1_pin;
/*CMOSEDGE*/    /*MT6205*/       L1D_GPIO_WriteIO(0,gpio_rf_control1_pin);
/*CMOSEDGE*/    /*MT6205*/       #else
/*CMOSEDGE*/    /*MT6205*/       L1D_GPIO_WriteIO(0,7);
/*CMOSEDGE*/    /*MT6205*/       #endif
/*CMOSEDGE*/    /*MT6205*/    }
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/    #if  0//IS_CHIP_MT6218A
/* under construction !*/
/*CMOSEDGE*/    /*MT6218A*/      #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    /*MT6218A*/      #else
/* under construction !*/
/*CMOSEDGE*/    /*MT6218A*/      #endif
/* under construction !*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/    #if  0//IS_CHIP_MT6218B || IS_CHIP_MT6219
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #else
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #endif
/* under construction !*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/    #if  0//IS_CHIP_MT6228_AND_LATTER_VERSION  || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #else
/* under construction !*/
/*CMOSEDGE*/    /*MT6218B~*/     #endif
/* under construction !*/
/*CMOSEDGE*/    #endif
/*CMOSEDGE*/  #endif
/*CMOSEDGE*/ #endif
/*CMOSEDGE*/
/*CMOSEDGE*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*CMOSEDGE*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0200000 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*CMOSEDGE*/    IMM_MODE_END(  );
/*CMOSEDGE*/ }
/*CMOSEDGE*/
/*CMOSEDGE*/ void  L1D_RF_WindowOn( void )
/*CMOSEDGE*/ {  }
/*CMOSEDGE*/
/*CMOSEDGE*/ void  L1D_RF_WindowOff( void )
/*CMOSEDGE*/ {  }
/*CMOSEDGE*/
#endif

#if IS_RF_MTKSOC1T
/*MTKSOC1T*/ #define RF_POR_NUM   (sizeof(SDATA_TABLE)/sizeof(unsigned long))
/*MTKSOC1T*/
/*MTKSOC1T*/ unsigned long SDATA_TABLE[]=
/*MTKSOC1T*/ {
/*MTKSOC1T*/ #if IS_RF_MTKSOC1_A5
/*MTKSOC1T*/    0x00700B0,
/*MTKSOC1T*/ #else
/*MTKSOC1T*/    0x00700A8, /*good TX, bad RX */
/*MTKSOC1T*/ #endif
/*MTKSOC1T*/
/*MTKSOC1T*/ #if IS_RF_MTKSOC1_A2 || IS_RF_MTKSOC1_A3 || IS_RF_MTKSOC1_A4
/*MTKSOC1T*/    0x05C48AD, /*1*/
/*MTKSOC1T*/ #else
/*MTKSOC1T*/    0x05C4CAD,
/*MTKSOC1T*/ #endif
/*MTKSOC1T*/
/*MTKSOC1T*/ #if IS_RF_MTKSOC1_A4
/*MTKSOC1T*/    0x0912141, /*2*/
/*MTKSOC1T*/ #else
/*MTKSOC1T*/    0x0912541,
/*MTKSOC1T*/ #endif
/*MTKSOC1T*/
/*MTKSOC1T*/ #if IS_RF_MTKSOC1_A2 || IS_RF_MTKSOC1_A3 || IS_RF_MTKSOC1_A4
/*MTKSOC1T*/    0x0A36DBF, /*3*/
/*MTKSOC1T*/ #else
/*MTKSOC1T*/    0x0A36EBF,
/*MTKSOC1T*/ #endif
/*MTKSOC1T*/
/*MTKSOC1T*/    0x0CDB8BE,
/*MTKSOC1T*/    0x101B581,
/*MTKSOC1T*/    0x11000CF,
/*MTKSOC1T*/    0x121325C,
/*MTKSOC1T*/    0x15E5F0A, /*8*/
/*MTKSOC1T*/    0x1864820,
/*MTKSOC1T*/    0x1A34006,
/*MTKSOC1T*/
/*MTKSOC1T*/ };
/*MTKSOC1T*/
/*MTKSOC1T*/ void  L1D_RF_PowerOn( void )
/*MTKSOC1T*/ {
/*MTKSOC1T*/    unsigned short i;
/*MTKSOC1T*/    unsigned short BSI_num;
/*MTKSOC1T*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MTKSOC1T*/    IMM_SEND_BPI( 0x0000 );
/*MTKSOC1T*/
/*MTKSOC1T*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x00F0030 );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MTKSOC1T*/    /* POR Start */
/*MTKSOC1T*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), (l1d_rf.AFC_data&0x1FFF)|0x0300000 ); //Set before AFC DAC value
/*MTKSOC1T*/    SDATA_TABLE[0] = ( SDATA_TABLE[0]&~(0x7F<<10) ) | ( (XO_CapID&0x7F)<<10 );
/*MTKSOC1T*/    BSI_num = (l1d_rf.is_init || L1D_GCMachine_Done()) ? RF_POR_NUM : 1;
/*MTKSOC1T*/    for( i=0 ; i<BSI_num; i++)
/*MTKSOC1T*/       IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[i] );
/*MTKSOC1T*/    /* POR End */
/*MTKSOC1T*/    IMM_MODE_END(  );
/*MTKSOC1T*/ }
/*MTKSOC1T*/
/*MTKSOC1T*/ void  L1D_RF_PowerOff( void )
/*MTKSOC1T*/ {
/*MTKSOC1T*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MTKSOC1T*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0200000 ); /* MT6119 enters Sleep mode, turn off RF regulators */
/*MTKSOC1T*/    IMM_MODE_END(  );
/*MTKSOC1T*/ }
/*MTKSOC1T*/
/*MTKSOC1T*/ void  L1D_RF_WindowOn( void )
/*MTKSOC1T*/ {  }
/*MTKSOC1T*/
/*MTKSOC1T*/ void  L1D_RF_WindowOff( void )
/*MTKSOC1T*/ {  }
/*MTKSOC1T*/
#endif

#if IS_RF_MTKSOC1
/*MTKSOC1*/ #define RF_POR_NUM   (sizeof(SDATA_TABLE2)/sizeof(unsigned long)/2)
/*MTKSOC1*/ extern int L1D_Get_MT6253_SDATA_Index( void );
/*MTKSOC1*/ unsigned long SDATA_TABLE2[2][10]=
/*MTKSOC1*/ {
/*MTKSOC1*/    {  0x0070070,
/*MTKSOC1*/       0x05CC8AD,
/*MTKSOC1*/       0x061C0B0,
/*MTKSOC1*/       0x071B1DD,
/*MTKSOC1*/       0x0912541,
/*MTKSOC1*/       0x0AB6DBF,
/*MTKSOC1*/       0x101B581,
/*MTKSOC1*/       0x1595F0A,
/*MTKSOC1*/       0x1864820,
/*MTKSOC1*/       0x1A34006,
/*MTKSOC1*/    },
/*MTKSOC1*/    {  0x007007F,   // increase loopbandwidth to reduce RX frequency offset
/*MTKSOC1*/       0x05CC8AD,
/*MTKSOC1*/       0x061C0B0,
/*MTKSOC1*/       0x071B1DD,
/*MTKSOC1*/       0x0912141,   // turn off loopbandwidth modification scheme to reduce RX frequency offset
/*MTKSOC1*/       0x0AB6DBF,
/*MTKSOC1*/       0x101B581,
/*MTKSOC1*/       0x1595F0A,
/*MTKSOC1*/       0x1864820,
/*MTKSOC1*/       0x1A34006,
/*MTKSOC1*/    },
/*MTKSOC1*/ };
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_PowerOn( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    unsigned short i;
/*MTKSOC1*/    unsigned short BSI_num=0;
/*MTKSOC1*/    unsigned long *SDATA_TABLE = L1D_Get_MT6253_SDATA_Index() ? SDATA_TABLE2[1] : SDATA_TABLE2[0];
/*MTKSOC1*/
/*MTKSOC1*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MTKSOC1*/
/*MTKSOC1*/    /*SOR*/
/*MTKSOC1*/    if( l1d_rf.is_init )
/*MTKSOC1*/    {  IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x00F0030 );  /*[CW0-VCOSEL]=0: RFVCO_HW_CONTROL*/
/*MTKSOC1*/       BSI_num=RF_POR_NUM;
/*MTKSOC1*/    }
/*MTKSOC1*/    else if(!L1D_GCMachine_Done())
/*MTKSOC1*/    {  IMM_MODE_END(  );
/*MTKSOC1*/       return;
/*MTKSOC1*/    }
/*MTKSOC1*/    else
/*MTKSOC1*/    {  BSI_num=1;
/*MTKSOC1*/    }
/*MTKSOC1*/
/*MTKSOC1*/    /* POR Start */
/*MTKSOC1*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), (l1d_rf.AFC_data&0x1FFF)|0x0300000 ); //Set before AFC DAC value
/*MTKSOC1*/    SDATA_TABLE[0] = (SDATA_TABLE[0]&~(0x7F<<10)) | ((XO_CapID&0x7F)<<10);
/*MTKSOC1*/    for( i=0 ; i<BSI_num; i++)
/*MTKSOC1*/       IMM_SEND_BSI( SCTRL_IMOD(0,26), SDATA_TABLE[i] );
/*MTKSOC1*/    /* POR End */
/*MTKSOC1*/    IMM_SEND_BPI( 0x0000 );
/*MTKSOC1*/    IMM_MODE_END(  );
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_PowerOff( void )
/*MTKSOC1*/ {
/*MTKSOC1*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MTKSOC1*/    /* Don't turn off RF regulators because turning on LDO may disturbing 26MHz */
/*MTKSOC1*///  IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x1C0008c );
/*MTKSOC1*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), 0x0200000 );
/*MTKSOC1*/    IMM_MODE_END(  );
/*MTKSOC1*/ }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_WindowOn( void )
/*MTKSOC1*/ {  }
/*MTKSOC1*/
/*MTKSOC1*/ void  L1D_RF_WindowOff( void )
/*MTKSOC1*/ {  }
/*MTKSOC1*/
#endif

#if IS_RF_MT6252RF
/*MT6252RF*/ #define RF_POR_NUM    (sizeof(SDATA_TABLE)/sizeof(unsigned long))
/*MT6252RF*/ #define RF_POR_NUM2   (sizeof(SDATA_TABLE2)/sizeof(unsigned long))
/*MT6252RF*/
/*MT6252RF*/ /* BSI control word in static digital block need to be modified after POR */
/*MT6252RF*/ #if IS_CHIP_MT6252_S00
/*MT6252RF*/ unsigned long SDATA_TABLE[] =
/*MT6252RF*/ {
/*MT6252RF*/     0x0D00000,  // CW13: by setting GLOBAL_CK_EN = 0 to turn off global clock
/*MT6252RF*/     0x04156A8,  // CW4 (change from 0x04154A8 to 0x04156A8)
/*MT6252RF*/     0x05280D4,  // CW5
/*MT6252RF*/     0x409E00F,  // CW64
/*MT6252RF*/     0x419C000,  // CW65
/*MT6252RF*/     0x6516F0A,  // CW101
/*MT6252RF*/     0x68B0820,  // CW104
/*MT6252RF*/     0x80E9400,  // CW128
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ /* BSI control word in dynamic digital block need to be modified after wakeup */
/*MT6252RF*/ unsigned long SDATA_TABLE2[] =
/*MT6252RF*/ {
/*MT6252RF*/     0x1020F18,  // CW16 (change from 0x1020F14 to 0x1020F18)
/*MT6252RF*/     0x1500226,  // CW21
/*MT6252RF*/     0x0C0821D,  // CW12: ISO = 0 control word in staticic digital block
/*MT6252RF*/ };
/*MT6252RF*/ #else
/*MT6252RF*/ unsigned long SDATA_TABLE[] =
/*MT6252RF*/ {
/*MT6252RF*/     0x0D00100,  // CW13: by setting GLOBAL_CK_EN = 0 to turn off global clock
/*MT6252RF*/     0x04156A8,  // CW4
/*MT6252RF*/     0x05000D3,  // CW5
/*MT6252RF*/     0x409E00F,  // CW64
/*MT6252RF*/     0x419C000,  // CW65
/*MT6252RF*/     0x63D006A,  // CW99
/*MT6252RF*/     0x64000AA,  // CW100
/*MT6252RF*/     0x6516F0A,  // CW101
/*MT6252RF*/     0x68B0820,  // CW104
/*MT6252RF*/     0x80E9480,  // CW128
/*MT6252RF*/ };
/*MT6252RF*/
/*MT6252RF*/ /* BSI control word in dynamic digital block need to be modified after wakeup */
/*MT6252RF*/ unsigned long SDATA_TABLE2[] =
/*MT6252RF*/ {
/*MT6252RF*/     0x004A2A4,  // CW0
/*MT6252RF*/     0x0738429,  // CW7
/*MT6252RF*/     0x1010F11,  // CW16
/*MT6252RF*/     0x1104398,  // CW17
/*MT6252RF*/     0x1340000,  // CW19
/*MT6252RF*/     0x15102BC,  // CW21
/*MT6252RF*/     0x1657878,  // CW22
/*MT6252RF*/     0x18374C8,  // CW24
/*MT6252RF*/     0x1AA42BC,  // CW26
/*MT6252RF*/     0x1B57878,  // CW27
/*MT6252RF*/     0x1C374C8,  // CW28
/*MT6252RF*/     #if IS_RF_VCO_PARTIAL_DOO_ON
/*MT6252RF*/     0x1DF035C,  // CW29
/*MT6252RF*/     #else
/*MT6252RF*/     0x1DC0250,  // CW29
/*MT6252RF*/     #endif
/*MT6252RF*/     0x24FFDEA,  // CW36
/*MT6252RF*/     0x2500A6A,  // CW37
/*MT6252RF*/     0x26FF2C9,  // CW38
/*MT6252RF*/     0x27FE717,  // CW39
/*MT6252RF*/     0x28047A9,  // CW40
/*MT6252RF*/     0x2903D20,  // CW41
/*MT6252RF*/     0x2AF8CC1,  // CW42
/*MT6252RF*/     0x2BFA5F7,  // CW43
/*MT6252RF*/     0x2C05803,  // CW44
/*MT6252RF*/     0x2D03909,  // CW45
/*MT6252RF*/     0x2EFD488,  // CW46
/*MT6252RF*/     0x2FFF596,  // CW47
/*MT6252RF*/     0x3000E34,  // CW48
/*MT6252RF*/     0x31FFD37,  // CW49
/*MT6252RF*/     0x32FFFB6,  // CW50
/*MT6252RF*/     0x0C0821D,  // CW12: ISO = 0 control word in staticic digital block
/*MT6252RF*/ };
/*MT6252RF*/ #endif
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_PowerOn( void )
/*MT6252RF*/ {
/*MT6252RF*/    unsigned short i;
/*MT6252RF*/    unsigned short BSI_num = 0, BSI_num2 = 0;
/*MT6252RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6252RF*/
/*MT6252RF*/    if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6252RF*/    {
/*MT6252RF*/       if( l1d_rf.is_init )
/*MT6252RF*/       {
/*MT6252RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x008A220 );   // CW0: set SOR = 1 to reset SD
/*MT6252RF*/          BSI_num = RF_POR_NUM;
/*MT6252RF*/       }
/*MT6252RF*/
/*MT6252RF*/       BSI_num2 = RF_POR_NUM2;
/*MT6252RF*/ #if IS_CHIP_MT6252_S00
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x004A220 );      // CW0: set DYN_EN = 1 to turn on DD
/*MT6252RF*/ #else
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x004A2A4 );      // CW0: set DYN_EN = 1 to turn on DD
/*MT6252RF*/ #endif
/*MT6252RF*/       WAIT_TIME_QB(600);                                // wait at least 553 us
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0E81CB3 );      // CW14: set SOR_DD = 1 to reset DD
/*MT6252RF*/    }
/*MT6252RF*/
/*MT6252RF*/    if( !l1d_rf2.is_wakeup )
/*MT6252RF*/    {
/*MT6252RF*/       /* CW13: Turn on digital clock by setting GLOBAL_CK_EN = 1  */
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0D00300 );
/*MT6252RF*/
/*MT6252RF*/       /* CW57: Set previous AFC DAC value                         */
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), ( l1d_rf.AFC_data & 0x1FFF ) | 0x3900000 );
/*MT6252RF*/
/*MT6252RF*/       /* CW56: Set previous Cap ID value                          */
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), ( XO_CapID & 0x7F) | 0x3800000 );
/*MT6252RF*/
/*MT6252RF*/       /* CW13: Turn off digital clock by setting GLOBAL_CK_EN = 0 */
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0D00100 );
/*MT6252RF*/    }
/*MT6252RF*/
/*MT6252RF*/    for( i = 0 ; i < BSI_num; i++ )
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE[i] );
/*MT6252RF*/
/*MT6252RF*/    for( i = 0 ; i < BSI_num2; i++ )
/*MT6252RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE2[i] );
/*MT6252RF*/
/*MT6252RF*/    IMM_SEND_BPI( 0x0000 );
/*MT6252RF*/    IMM_MODE_END(  );
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_PowerOff( void )
/*MT6252RF*/ {
/*MT6252RF*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6252RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0200000 );  // CW2: set mode = sleep mode
/*MT6252RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0C4821D );  // CW12: set ISO = 1
/*MT6252RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x000A220 );  // CW0: set DYN_EN = 0
/*MT6252RF*/    IMM_MODE_END(  );
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_WindowOn( void )
/*MT6252RF*/ {
/*MT6252RF*/ }
/*MT6252RF*/
/*MT6252RF*/ void  L1D_RF_WindowOff( void )
/*MT6252RF*/ {
/*MT6252RF*/ }
#endif

#if IS_RF_MT6256RF
/*MT6256RF*/ #define RF_POR_NUM    (sizeof(SDATA_TABLE) /sizeof(unsigned long))
/*MT6256RF*/ #define RF_POR_NUM2   (sizeof(SDATA_TABLE2)/sizeof(unsigned long))
/*MT6256RF*/
/*MT6256RF*/ #if IS_CHIP_MT6256_S00
/*MT6256RF*/ /* BSI control word in static digital block need to be modified after POR */
/*MT6256RF*/ unsigned long SDATA_TABLE[]=
/*MT6256RF*/ {
/*MT6256RF*/    0x6800000,  /* CW104: D6=0 ground hign band mixer MUX */
/*MT6256RF*/    0x80FF4D3,  /* CW128: */
/*MT6256RF*/    0x84088DB,  /* CW132: */
/*MT6256RF*/    0x8A01170,  /* CW138: */
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ /* BSI control word in dynamic digital block need to be modified after wakeup */
/*MT6256RF*/ unsigned long SDATA_TABLE2[]=
/*MT6256RF*/ {
/*MT6256RF*/    0x03C44B7,  /* CW3:   */
/*MT6256RF*/    0x0816013,  /* CW8:   */
/*MT6256RF*/    0x0C18230,  /* CW12: ISO=0 control word in staticic digital block */
/*MT6256RF*/    0x0F01462,  /* CW15:  */
/*MT6256RF*/    0x1041150,  /* CW16:  */
/*MT6256RF*/    0x14F7DBA,  /* CW20:  */
/*MT6256RF*/    0x15FFFFF,  /* CW21:  */
/*MT6256RF*/    0x16FBA01,  /* CW22:  */
/*MT6256RF*/    0x17FFF7D,  /* CW23:  */
/*MT6256RF*/    0x18F01FF,  /* CW24:  */
/*MT6256RF*/    0x1977DBA,  /* CW25:  */
/*MT6256RF*/    0x8369A25,  /* CW131: */
/*MT6256RF*/    0x890001F,  /* CW137: */
/*MT6256RF*/ };
/*MT6256RF*/ #else
/*MT6256RF*/ /* BSI control word in static digital block need to be modified after POR */
/*MT6256RF*/ unsigned long SDATA_TABLE[]=
/*MT6256RF*/ {
/*MT6256RF*/    #if IS_CHIP_MT6256_S01
/*MT6256RF*/    0x0454866,  /* CW4:                         */
/*MT6256RF*/    #else
/*MT6256RF*/    0x0454A66,  /* CW4:                         */
/*MT6256RF*/    #endif
/*MT6256RF*/    0x3F8BC86,  /* CW63:                        */
/*MT6256RF*/    0x651D3FA,  /* CW101:                       */
/*MT6256RF*/    0x8B00001,  /* CW139: boost GMSK HBTX power */
/*MT6256RF*/ };
/*MT6256RF*/
/*MT6256RF*/ /* BSI control word in dynamic digital block need to be modified after wakeup */
/*MT6256RF*/ unsigned long SDATA_TABLE2[]=
/*MT6256RF*/ {
/*MT6256RF*/    0x0C18230,  /* CW12: ISO=0 control word in staticic digital block                     */
/*MT6256RF*/    0x1055D5A,  /* CW16: improve PE                                                       */
/*MT6256RF*/    0x1937DBA,  /* CW25: improve PE                                                       */
/*MT6256RF*/    0x2373038,  /* CW35: improve PE                                                       */
/*MT6256RF*/    0x8369825,  /* CW131: improve PE                                                      */
/*MT6256RF*/    0x419E000,  /* CW65: for reading back RF temperature                                  */
/*MT6256RF*/    0x4200001,  /* CW66: for reading back AUXOUT table                                    */
/*MT6256RF*/    0x8AA1170,  /* CW138: for triggering the temperature ADC ONLY at the TX mode, D[17]=1 */
/*MT6256RF*/ };
/*MT6256RF*/ #endif
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_PowerOn( void )
/*MT6256RF*/ {
/*MT6256RF*/    unsigned short i;
/*MT6256RF*/    unsigned short BSI_num=0, BSI_num2=0;
/*MT6256RF*/ #if IS_AST_B2S_SUPPORT
/*MT6256RF*/    int b32=0;
/*MT6256RF*/ #endif
/*MT6256RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6256RF*/
/*MT6256RF*/    if( l1d_rf.is_init )
/*MT6256RF*/    {
/*MT6256RF*/ #if IS_CHIP_MT6256_S00
/*MT6256RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x102A0) );  //CW0: set SOR=1 to reset SD
/*MT6256RF*/ #else
/*MT6256RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x18230) );  //CW0: set SOR=1 to reset SD
/*MT6256RF*/ #endif
/*MT6256RF*/       BSI_num = RF_POR_NUM;
/*MT6256RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), L1D_RF_SetTX_BSI_CW( QB_ST2B, 150 ) );  //CW136: for DCS and PCS overlapped ARFCN to pass PvT */
/*MT6256RF*/    }
/*MT6256RF*/
/*MT6256RF*/    BSI_num2 = RF_POR_NUM2;
/*MT6256RF*/
/*MT6256RF*/ #if IS_CHIP_MT6256_S00
/*MT6256RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x502A0) );  //CW0: set DYN_EN=1 to turn on DD
/*MT6256RF*/ #else
/*MT6256RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x58230) );  //CW0: set DYN_EN=1 to turn on DD
/*MT6256RF*/ #endif
/*MT6256RF*/
/*MT6256RF*/    WAIT_TIME_QB(335);  //wait at least 310us
/*MT6256RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x0E, 0x80000) );  //CW14: set SOR_DD=1 to reset DD
/*MT6256RF*/
/*MT6256RF*/    if( !l1d_rf2.is_wakeup )
/*MT6256RF*/    {
/*MT6256RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x84, 0x188D8)                );  //CW132: Enable to force to set AFC DAC in RX/TX mode
/*MT6256RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x39, l1d_rf.AFC_data&0x1FFF) );  //CW57: Set previous AFC DAC value
/*MT6256RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x38, XO_CapID&0xFF)          );  //CW56: Set previous Cap ID value
/*MT6256RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x84, 0x088D8)                );  //CW132: Disable to force to set AFC DAC in RX/TX mode
/*MT6256RF*/    }
/*MT6256RF*/
/*MT6256RF*/    for( i=0 ; i<BSI_num; i++ )
/*MT6256RF*/    {  IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE[i] );  }
/*MT6256RF*/
/*MT6256RF*/    for( i=0 ; i<BSI_num2; i++ )
/*MT6256RF*/    {  IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE2[i] ); }
/*MT6256RF*/
/*MT6256RF*/ #if IS_AST_B2S_SUPPORT
/*MT6256RF*/
/*MT6256RF*/    if( !l1d_rf2.is_wakeup )
/*MT6256RF*/    {
/*MT6256RF*/       IMM_SEND_BPI( 0x0100 ); //Switch SPI control to 2G
/*MT6256RF*/
/*MT6256RF*/       for(b32=0;b32<4;b32++)
/*MT6256RF*/       {
/*MT6256RF*/          HW_WRITE(AFC_EV(b32),0x2700);
/*MT6256RF*/       }
/*MT6256RF*/       b32=HW_READ(TDMA_EVTENA(0));
/*MT6256RF*/       HW_WRITE(TDMA_EVTENA(0),b32&0xFFFF0FFF);
/*MT6256RF*/
/*MT6256RF*/       HW_WRITE( AFC_VALUE, 0x0E100000 ); // set AFC Value
/*MT6256RF*/       HW_WRITE( AFC_DAT(0), (l1d_rf.AFC_data&0x1FFF) );
/*MT6256RF*/       HW_WRITE( AFC_CON   , 0x0001 ); //immediate mode
/*MT6256RF*/       WAIT_TIME_QB(3);
/*MT6256RF*/       HW_WRITE( AFC_VALUE, 0x0E000000 ); // set AFC Value
/*MT6256RF*/       HW_WRITE( AFC_DAT(0), (XO_CapID&0xFF) );
/*MT6256RF*/       HW_WRITE( AFC_CON   , 0x0001 ); //immediate mode
/*MT6256RF*/       WAIT_TIME_QB(3);
/*MT6256RF*/       HW_WRITE( AFC_CON   , 0x0000);  //event mode
/*MT6256RF*/       HW_WRITE( AFC_VALUE, 0x0E100000 ); // set AFC Value
/*MT6256RF*/    }
/*MT6256RF*/    IMM_SEND_BPI( 0x0000 ); //Switch SPI control to 3G
/*MT6256RF*/
/*MT6256RF*/ #else
/*MT6256RF*/    IMM_SEND_BPI( 0x0000 );
/*MT6256RF*/ #endif
/*MT6256RF*/
/*MT6256RF*/    IMM_MODE_END(  );
/*MT6256RF*/
/*MT6256RF*/    L1D_RF_TXPC_CL_AUXADC_POWERON();
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_PowerOff( void )
/*MT6256RF*/ {
/*MT6256RF*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6256RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x0C, 0x58230) );  //CW12: set ISO=1
/*MT6256RF*/ #if IS_CHIP_MT6256_S00
/*MT6256RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x102A0) );  //CW0: set DYN_EN=0
/*MT6256RF*/ #else
/*MT6256RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x18230) );  //CW0: set DYN_EN=0
/*MT6256RF*/ #endif
/*MT6256RF*/    IMM_MODE_END(  );
/*MT6256RF*/
/*MT6256RF*/    L1D_RF_TXPC_CL_AUXADC_POWEROFF();
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_WindowOn( void )
/*MT6256RF*/ {
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void  L1D_RF_WindowOff( void )
/*MT6256RF*/ {
/*MT6256RF*/ }
/*MT6256RF*/
/*MT6256RF*/ void L1D_RF_Switch_SPI_Control_to_3G( void )
/*MT6256RF*/ {
/*MT6256RF*/ #if IS_AST_B2S_SUPPORT
/*MT6256RF*/    extern void L1D_PowerManager( int );
/*MT6256RF*/
/*MT6256RF*/    L1D_PowerManager( 3 );
/*MT6256RF*/    L1D_RF_Init_BPI( );
/*MT6256RF*/    IMM_SEND_BPI( 0x0000 ); //send immedidate mode to switch SPI to 3G
/*MT6256RF*/ #endif
/*MT6256RF*/ }
#endif

#if IS_RF_MT6255RF
/*MT6255RF*/ #define RF_POR_NUM    (sizeof(SDATA_TABLE) /sizeof(unsigned long))
/*MT6255RF*/ #define RF_POR_NUM2   (sizeof(SDATA_TABLE2)/sizeof(unsigned long))
/*MT6255RF*/
/*MT6255RF*/ /* BSI control word in static digital block need to be modified after POR */
/*MT6255RF*/ const unsigned long SDATA_TABLE[] =
/*MT6255RF*/ {
/*MT6255RF*/    0x0454A66, /* CW4:  DFM Power */
/*MT6255RF*/    0x3F8BC86, /* CW63: VCO TCL */
/*MT6255RF*/    0x6181ABF, /* CW97: RX Power */
/*MT6255RF*/    0x625066A, /* CW98: RX FE */
/*MT6255RF*/    0x6B2C0F0, /* CW107: Blocker detection */
/*MT6255RF*/    0x8400FFA, /* CW132: TX EN */
/*MT6255RF*/ };
/*MT6255RF*/
/*MT6255RF*/ /* BSI control word in dynamic digital block need to be modified after wakeup */
/*MT6255RF*/ const unsigned long SDATA_TABLE2[] =
/*MT6255RF*/ {
/*MT6255RF*/    0x1055D5A, /* CW16: DFM LG */
/*MT6255RF*/    0x1917DBA, /* CW25: DFM LG */
/*MT6255RF*/    0x2373038, /* CW35: DFM LG */
/*MT6255RF*/ };
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_PowerOn( void )
/*MT6255RF*/ {
/*MT6255RF*/    unsigned short i;
/*MT6255RF*/    unsigned short BSI_num=0, BSI_num2=0;
/*MT6255RF*/ #if IS_AST_B2S_SUPPORT
/*MT6255RF*/    int b32=0;
/*MT6255RF*/ #endif
/*MT6255RF*/
/*MT6255RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6255RF*/
/*MT6255RF*/    if( l1d_rf.is_init )
/*MT6255RF*/    {
/*MT6255RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x18230) );   //CW0: set SOR=1 to reset SD
/*MT6255RF*/       BSI_num = RF_POR_NUM;
/*MT6255RF*/    }
/*MT6255RF*/
/*MT6255RF*/    BSI_num2 = RF_POR_NUM2;
/*MT6255RF*/
/*MT6255RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x58230) );      //CW0: set DYN_EN=1 to turn on DD
/*MT6255RF*/
/*MT6255RF*/    WAIT_TIME_QB(335);                                            //wait at least 310us
/*MT6255RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x0E, 0x80000) );      //CW14: set SOR_DD=1 to reset DD
/*MT6255RF*/
/*MT6255RF*/    if( !l1d_rf2.is_wakeup )
/*MT6255RF*/    {
/*MT6255RF*/       unsigned long cw132 = L1D_RF_SetTX_BSI_CW( QB_ST2B, 150 ); // MT6255RF enters TX mode in ST2B
/*MT6255RF*/
/*MT6255RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), cw132|(0x1<<18)                      );  //CW132: Enable to force to set AFC DAC in RX/TX mode
/*MT6255RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x39, l1d_rf.AFC_data&0x1FFF) );  //CW57:  Set previous AFC DAC value
/*MT6255RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x38, XO_CapID&0xFF)          );  //CW56:  Set previous Cap ID value
/*MT6255RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), cw132|(0x0<<18)                      );  //CW132: Disable to force to set AFC DAC in RX/TX mode
/*MT6255RF*/    }
/*MT6255RF*/
/*MT6255RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x0C, 0x18230) ); // CW12: ISO=0 control word in static digital block
/*MT6255RF*/
/*MT6255RF*/    for( i=0 ; i<BSI_num; i++ )
/*MT6255RF*/    {  IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE[i] );  }
/*MT6255RF*/
/*MT6255RF*/    for( i=0 ; i<BSI_num2; i++ )
/*MT6255RF*/    {  IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE2[i] ); }
/*MT6255RF*/
/*MT6255RF*/ #if IS_AST_B2S_SUPPORT
/*MT6255RF*/    if( !l1d_rf2.is_wakeup )
/*MT6255RF*/    {
/*MT6255RF*/       IMM_SEND_BPI( 0x0100 ); //Switch SPI control to 2G
/*MT6255RF*/
/*MT6255RF*/       for(b32=0;b32<4;b32++)
/*MT6255RF*/       {
/*MT6255RF*/          HW_WRITE(AFC_EV(b32),0x2700);
/*MT6255RF*/       }
/*MT6255RF*/       b32=HW_READ(TDMA_EVTENA(0));
/*MT6255RF*/       HW_WRITE(TDMA_EVTENA(0),b32&0xFFFF0FFF);
/*MT6255RF*/
/*MT6255RF*/       HW_WRITE( AFC_VALUE,   0x0E100000 );  // set AFC Value
/*MT6255RF*/       HW_WRITE( AFC_DAT(0),  (l1d_rf.AFC_data&0x1FFF) );
/*MT6255RF*/       HW_WRITE( AFC_CON,     0x0001 );      // immediate mode
/*MT6255RF*/       WAIT_TIME_QB(3);
/*MT6255RF*/       HW_WRITE( AFC_VALUE,   0x0E000000 );  // set AFC Value
/*MT6255RF*/       HW_WRITE( AFC_DAT(0),  (XO_CapID&0xFF) );
/*MT6255RF*/       HW_WRITE( AFC_CON,     0x0001 );      // immediate mode
/*MT6255RF*/       WAIT_TIME_QB(3);
/*MT6255RF*/       HW_WRITE( AFC_CON,     0x0000 );      // event mode
/*MT6255RF*/       HW_WRITE( AFC_VALUE,   0x0E100000 );  // set AFC Value
/*MT6255RF*/    }
/*MT6255RF*/    IMM_SEND_BPI( 0x0000 ); //Switch SPI control to 3G
/*MT6255RF*/
/*MT6255RF*/ #else
/*MT6255RF*/    IMM_SEND_BPI( 0x0000 );
/*MT6255RF*/ #endif
/*MT6255RF*/
/*MT6255RF*/    IMM_MODE_END(  );
/*MT6255RF*/
/*MT6255RF*/    L1D_RF_TXPC_CL_AUXADC_POWERON();
/*MT6255RF*/ }
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_PowerOff( void )
/*MT6255RF*/ {
/*MT6255RF*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6255RF*/
/*MT6255RF*/ #if IS_32K_CRYSTAL_REMOVAL_SUPPORT
/*MT6255RF*/    {  //Set LPM fractional divider before RF power off
/*MT6255RF*/       extern unsigned long L1D_GetDCXOFreqLPM(void);
/*MT6255RF*/       unsigned long dcxo_frac = L1D_GetDCXOFreqLPM();
/*MT6255RF*/
/*MT6255RF*/       if( !L1D_RF_Check_32K_XO_Status() )
/*MT6255RF*/       {  IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x4A, ((dcxo_frac&0xFFF)<<8)|0xFF) );  }
/*MT6255RF*/    }
/*MT6255RF*/ #endif
/*MT6255RF*/
/*MT6255RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x0C, 0x58230) );  //CW12: set ISO=1
/*MT6255RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x18230) );  //CW0: set DYN_EN=0
/*MT6255RF*/    IMM_MODE_END(  );
/*MT6255RF*/
/*MT6255RF*/    L1D_RF_TXPC_CL_AUXADC_POWEROFF();
/*MT6255RF*/ }
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_WindowOn( void )
/*MT6255RF*/ {
/*MT6255RF*/ }
/*MT6255RF*/
/*MT6255RF*/ void  L1D_RF_WindowOff( void )
/*MT6255RF*/ {
/*MT6255RF*/ }
/*MT6255RF*/
/*MT6255RF*/ void L1D_RF_Switch_SPI_Control_to_3G( void )
/*MT6255RF*/ {
/*MT6255RF*/ #if IS_AST_B2S_SUPPORT
/*MT6255RF*/    extern void L1D_PowerManager( int );
/*MT6255RF*/
/*MT6255RF*/    L1D_PowerManager( 3 );
/*MT6255RF*/    L1D_RF_Init_BPI( );
/*MT6255RF*/    IMM_SEND_BPI( 0x0000 ); //send immedidate mode to switch SPI to 3G
/*MT6255RF*/ #endif
/*MT6255RF*/ }
#endif

#if IS_RF_MT6251RF
/*MT6251RF*/ #define RF_POR_NUM    (sizeof(SDATA_TABLE)/sizeof(unsigned long))
/*MT6251RF*/ #define RF_POR_NUM2   (sizeof(SDATA_TABLE2)/sizeof(unsigned long))
/*MT6251RF*/
   #if IS_CHIP_MT6251_S00
/*MT6251RF*/ const unsigned long SDATA_TABLE[]=
/*MT6251RF*/ {
/*MT6251RF*/    0x6800000,  // CW104:for bias of high band mixer is not grounded
/*MT6251RF*/    0x6274662,  /* CW98: */
/*MT6251RF*/    0x03C44B7,  // CW3   for RF final setting
/*MT6251RF*/    0x6191ABF,  // CW97  for RF final setting
/*MT6251RF*/    0x6481280,  // CW100 for RF final setting
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ const unsigned long SDATA_TABLE2[]=
/*MT6251RF*/ {
/*MT6251RF*/    0x0C18230,  /* CW12: ISO=0 control word in static digital block */
/*MT6251RF*/    0x0816013,  /* CW8:  */
/*MT6251RF*/    0x0F01462,  /* CW15: */
/*MT6251RF*/    0x1041150,  /* CW16: */
/*MT6251RF*/    0x14F7DBA,  /* CW20: */
/*MT6251RF*/    0x15FFFFF,  /* CW21: */
/*MT6251RF*/    0x16FBA01,  /* CW22: */
/*MT6251RF*/    0x17FFF7D,  /* CW23: */
/*MT6251RF*/    0x18F01FF,  /* CW24: */
/*MT6251RF*/    0x1977DBA,  /* CW25: */
/*MT6251RF*/    0x8406FFA,  /* CW132:*/
/*MT6251RF*/    0x4200001,  /* CW66: for read auxout*/
/*MT6251RF*/ };
   #else /* For E2 chip */
/*MT6251RF*/ const unsigned long SDATA_TABLE[]=
/*MT6251RF*/ {
/*MT6251RF*/    0x6191ABF,  /* CW97 */
/*MT6251RF*/ };
/*MT6251RF*/
/*MT6251RF*/ const unsigned long SDATA_TABLE2[]=
/*MT6251RF*/ {
/*MT6251RF*/    0x0C18230,  /* CW12 */ // ISO=0 control word in static digital block
/*MT6251RF*/    0x0058230,  /* CW0  */ // DYN_EN should be 1
/*MT6251RF*/    0x0455B66,  /* CW4  */
/*MT6251RF*/    0x1015D5A,  /* CW16 */
/*MT6251RF*/    0x12CFC10,  /* CW18 */
/*MT6251RF*/    0x15FFFFF,  /* CW21 */
/*MT6251RF*/    0x17FFF7D,  /* CW23 */
/*MT6251RF*/    0x1A9FFFF,  /* CW26 */
/*MT6251RF*/    0x1B90001,  /* CW27 */
/*MT6251RF*/    0x1C57ABC,  /* CW28 */
/*MT6251RF*/    0x1D0E064,  /* CW29 */
/*MT6251RF*/    0x1E96038,  /* CW30 */
/*MT6251RF*/    0x1F1912C,  /* CW31 */
/*MT6251RF*/    0x200E038,  /* CW32 */
/*MT6251RF*/    0x214B258,  /* CW33 */
/*MT6251RF*/    0x220E064,  /* CW34 */
/*MT6251RF*/    0x2339838,  /* CW35 */
/*MT6251RF*/    0x24FFD53,  /* CW36 */
/*MT6251RF*/    0x2500D57,  /* CW37 */
/*MT6251RF*/    0x26FEF11,  /* CW38 */
/*MT6251RF*/    0x27FE017,  /* CW39 */
/*MT6251RF*/    0x2805BCF,  /* CW40 */
/*MT6251RF*/    0x2904E49,  /* CW41 */
/*MT6251RF*/    0x2AF6C59,  /* CW42 */
/*MT6251RF*/    0x2BF8CAF,  /* CW43 */
/*MT6251RF*/    0x2C070C8,  /* CW44 */
/*MT6251RF*/    0x2D0490E,  /* CW45 */
/*MT6251RF*/    0x2EFC84C,  /* CW46 */
/*MT6251RF*/    0x2FFF2AA,  /* CW47 */
/*MT6251RF*/    0x3001232,  /* CW48 */
/*MT6251RF*/    0x31FFC6E,  /* CW49 */
/*MT6251RF*/    0x32FFFA2,  /* CW50 */
/*MT6251RF*/    0x3ECD480,  /* CW62 */
/*MT6251RF*/    0x6B6C0E0,  /* CW107 */
/*MT6251RF*/  //0x8406FFE,  /* CW132 */ // Note for not modify common code
/*MT6251RF*/    0x8580000,  /* CW133*/
/*MT6251RF*/    0x4200001,  /* CW66 */ // Read AUXOUT table
/*MT6251RF*/ };
   #endif
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_PowerOn( void )
/*MT6251RF*/ {
/*MT6251RF*/    unsigned short i;
/*MT6251RF*/    unsigned short BSI_num=0, BSI_num2=0;
/*MT6251RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6251RF*/
/*MT6251RF*/    if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6251RF*/    {
/*MT6251RF*/       if( l1d_rf.is_init )
/*MT6251RF*/       {
/*MT6251RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x00902A0 );   // CW0: set SOR=1 to reset SD
/*MT6251RF*/          BSI_num = RF_POR_NUM;
/*MT6251RF*/       }
/*MT6251RF*/    }
/*MT6251RF*/
/*MT6251RF*/    BSI_num2 = RF_POR_NUM2;
/*MT6251RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x00502A0 );      // CW0: set DYN_EN=1 to turn on DD
/*MT6251RF*/    WAIT_TIME_QB(272);                                // wait at least 250us
/*MT6251RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0E80000 );      // CW14: set SOR_DD=1 to reset DD
/*MT6251RF*/
/*MT6251RF*/    if( !l1d_rf2.is_wakeup )
/*MT6251RF*/    {
/*MT6251RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x8426FFA );
/*MT6251RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), (l1d_rf.AFC_data&0x1FFF)|0x3900000 );   // CW57: Set previous AFC DAC value
/*MT6251RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), (XO_CapID&0xFF)|0x3800000 );            // CW56: Set previous Cap ID value
/*MT6251RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x8406FFA );                            // CW132: releative to BFE TX timing
/*MT6251RF*/    }
/*MT6251RF*/
/*MT6251RF*/    for( i=0 ; i<BSI_num; i++ )
/*MT6251RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE[i] );
/*MT6251RF*/
/*MT6251RF*/    for( i=0 ; i<BSI_num2; i++ )
/*MT6251RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE2[i] );
/*MT6251RF*/
/*MT6251RF*/    IMM_SEND_BPI( 0x0000 );
/*MT6251RF*/    IMM_MODE_END(  );
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_PowerOff( void )
/*MT6251RF*/ {
/*MT6251RF*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6251RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0210000 );  // CW2: set mode = sleep mode
/*MT6251RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x0C58230 );  // CW12: set ISO=1
/*MT6251RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), 0x00102A0 );  // CW0: set DYN_EN=0
/*MT6251RF*/    IMM_MODE_END(  );
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_WindowOn( void )
/*MT6251RF*/ {
/*MT6251RF*/ }
/*MT6251RF*/
/*MT6251RF*/ void  L1D_RF_WindowOff( void )
/*MT6251RF*/ {
/*MT6251RF*/ }
#endif

#if IS_RF_SKY74045
/*SKY74045*/
/*SKY74045*/ void  L1D_RF_PowerOn( void )
/*SKY74045*/ {
/*SKY74045*/ #if defined(L1D_SIM)    // SXENA is used in dual mode RF conflict detection
/*SKY74045*/    if( l1d_rf.is_init ) // assume V_RXBB, pin 52, is tight high to hold the register settings
/*SKY74045*/ #endif                  // then we just need to do RF initialization once
/*SKY74045*/    {
/*SKY74045*/       IMM_MODE_BEGIN( IMMMASK_ALL );
/*SKY74045*/       IMM_SEND_BPI( 0x0200 );       //enable SXENA
/*SKY74045*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x844003 );   //RTX_Ctrl, Preset = 1
/*SKY74045*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x804003 );   //RTX_Ctrl, Preset = 0, GSM band
/*SKY74045*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x6B1401 );   //TR0
/*SKY74045*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x54A1C5 );   //TR1
/*SKY74045*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x844429 );   //TR2, DCOC 20us
/*SKY74045*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x80049D );   //  PAC time
/*SKY74045*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x4B807D );   // ?
/*SKY74045*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x004D2D );   // old
/*SKY74045*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x00756D );   // old
/*SKY74045*/       IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x2F42D4 );   // change 046 VPC output offset voltage [8:7] and AM loop DC calibration [5:4]
/*SKY74045*/       IMM_SEND_BPI( 0x0000 );       //disable SXENA
/*SKY74045*/       IMM_MODE_END(  );
/*SKY74045*/    }
/*SKY74045*/ }
/*SKY74045*/
/*SKY74045*/ void  L1D_RF_PowerOff( void )
/*SKY74045*/ {
/*SKY74045*/ }
/*SKY74045*/
/*SKY74045*/ void  L1D_RF_WindowOn( void )
/*SKY74045*/ {  }
/*SKY74045*/
/*SKY74045*/ void  L1D_RF_WindowOff( void )
/*SKY74045*/ {  }
#endif

#if IS_RF_AERO2
/*AERO2*/
/*AERO2*/ #ifndef AFCC
/*AERO2*/ #define AFCC     0
/*AERO2*/ #endif
/*AERO2*/
/*AERO2*/ const unsigned long SDATA_INITIAL_TABLE[4]=
/*AERO2*/ {
/*AERO2*/    ((0x0200|((AFCC&0x1)<<8))<<6) | 0x04, // DCXO, bit8 must be 1, bit9 don't care
/*AERO2*/    ( 0x0180                 <<6) | 0x03, //
/*AERO2*/    ( 0x2E98                 <<6) | 0x05, //
/*AERO2*/    ( 0x0900                 <<6) | 0x08, //
/*AERO2*/ };
/*AERO2*/
/*AERO2*/ const unsigned long SDATA_CALIBRATION_TABLE[12]=
/*AERO2*/ {
/*AERO2*/    ( 0x2E99                 <<6) | 0x05, //  0,
/*AERO2*/    ( 0x02C0                 <<6) | 0x20, //  1,
/*AERO2*/    ( 0x0025                 <<6) | 0x21, //  2,
/*AERO2*/    ( 0x0000                 <<6) | 0x0A, //  3,
/*AERO2*/    ( 0x0000                 <<6) | 0x0B, //  4,
/*AERO2*/    ( 0x0908                 <<6) | 0x08, //  5,
/*AERO2*/    ( 0x02C0                 <<6) | 0x20, //  6,
/*AERO2*/    ( 0x02BA                 <<6) | 0x21, //  7,
/*AERO2*/    ( 0x0000                 <<6) | 0x0A, //  8,
/*AERO2*/    ( 0x0000                 <<6) | 0x0B, //  9,
/*AERO2*/    ( 0x090C                 <<6) | 0x08, // 10,
/*AERO2*/    ( 0x2E98                 <<6) | 0x05, // 11,
/*AERO2*/ };
/*AERO2*/
/*AERO2*/ void  L1D_RF_PowerOn( void )
/*AERO2*/ {
/*AERO2*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*AERO2*/    IMM_SEND_BPI( 0x000 );
/*AERO2*/    IMM_SEND_BSI( SCTRL_IMOD(0,21), SDATA_INITIAL_TABLE[0] );
/*AERO2*/    IMM_SEND_BSI( SCTRL_IMOD(0,21), SDATA_INITIAL_TABLE[1]|((XO_CapID&0x7F)<<6) );
/*AERO2*/    IMM_SEND_BSI( SCTRL_IMOD(0,21), SDATA_INITIAL_TABLE[2] );
/*AERO2*/    IMM_SEND_BSI( SCTRL_IMOD(0,21), SDATA_INITIAL_TABLE[3] );
/*AERO2*/    /* TX/RX calibration begin */
/*AERO2*/    if(l1d_rf.is_init)
/*AERO2*/    {  int i;
/*AERO2*/       // LB calibration
/*AERO2*/       for(i=0; i<6; i++)
/*AERO2*/          IMM_SEND_BSI( SCTRL_IMOD(0,21), SDATA_CALIBRATION_TABLE[i] );
/*AERO2*/
/*AERO2*/ #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*AERO2*/       IMM_SEND_BPI( 0x200 );
/*AERO2*/ #else
/*AERO2*/       IMM_SEND_BPI( 0x080 );
/*AERO2*/ #endif
/*AERO2*/       WAIT_TIME_QB( 3900 );
/*AERO2*/       IMM_SEND_BPI( 0x000 );
/*AERO2*/
/*AERO2*/       // HB calibration
/*AERO2*/       for(i=6; i<11; i++)
/*AERO2*/          IMM_SEND_BSI( SCTRL_IMOD(0,21), SDATA_CALIBRATION_TABLE[i] );
/*AERO2*/
/*AERO2*/ #if IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*AERO2*/       IMM_SEND_BPI( 0x200 );
/*AERO2*/ #else
/*AERO2*/       IMM_SEND_BPI( 0x080 );
/*AERO2*/ #endif
/*AERO2*/
/*AERO2*/       WAIT_TIME_QB( 12700 );
/*AERO2*/       IMM_SEND_BPI( 0x000 );
/*AERO2*/       IMM_SEND_BSI( SCTRL_IMOD(0,21), SDATA_CALIBRATION_TABLE[11] );
/*AERO2*/    }
/*AERO2*/    /* TX/RX calibration end */
/*AERO2*/    IMM_MODE_END(  );
/*AERO2*/ }
/*AERO2*/
/*AERO2*/ void  L1D_RF_PowerOff( void )
/*AERO2*/ {
/*AERO2*/ }
/*AERO2*/
/*AERO2*/ void  L1D_RF_WindowOn( void )
/*AERO2*/ {  }
/*AERO2*/
/*AERO2*/ void  L1D_RF_WindowOff( void )
/*AERO2*/ {  }
/*AERO2*/
#endif

#if IS_RF_SKY74137
/*SKY74137*/
/*SKY74137*/ void  L1D_RF_PowerOn( void )
/*SKY74137*/ {
/*SKY74137*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*SKY74137*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x44DC02 );
/*SKY74137*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x03CA28 );
/*SKY74137*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0xFD7C38 );
/*SKY74137*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x02AE46 );
/*SKY74137*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x03860A );
/*SKY74137*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x007452 );
/*SKY74137*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x2A5DD6 );
/*SKY74137*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x00691E );
/*SKY74137*/    IMM_MODE_END(  );
/*SKY74137*/ }
/*SKY74137*/
/*SKY74137*/ void  L1D_RF_PowerOff( void )
/*SKY74137*/ {
/*SKY74137*/ }
/*SKY74137*/
/*SKY74137*/ void  L1D_RF_WindowOn( void )
/*SKY74137*/ {  }
/*SKY74137*/
/*SKY74137*/ void  L1D_RF_WindowOff( void )
/*SKY74137*/ {  }
/*SKY74137*/
#endif

#if IS_RF_GRF6201
/*GRF6201*/ unsigned long SPI_initialWord[]=
/*GRF6201*/ {
/*GRF6201*/    0x000000, //00h
/*GRF6201*/    0X49FC83, //03h
/*GRF6201*/    0x000001, //01h
/*GRF6201*/    0x000042, //02h
/*GRF6201*/    0xC4DA44, //0x64DA44, //0x3A1A44, //04h
/*GRF6201*/    0x92D4C5, //05h
/*GRF6201*/    0xDB64C6, //06h
/*GRF6201*/    0x65A407, //07h
/*GRF6201*/    0xC22388, //0xC62388, //08h    //TX_CUR_Ratio 01->00
/*GRF6201*/    0x6A1549, //09h
/*GRF6201*/    0x449CCA, //0Ah
/*GRF6201*/    0x71E78B, //0Bh
/*GRF6201*/    0x8A184C, //0Ch
/*GRF6201*/    0xDDEE8D, //0Dh
/*GRF6201*/    0xA7FE0E, //0Eh
/*GRF6201*/    0x8788CF, //0Fh
/*GRF6201*/    0x600010, //10h
/*GRF6201*/    0x000411, //11h
/*GRF6201*/    0x000412, //12h
/*GRF6201*/    0x0146D3, //13h
/*GRF6201*/    0xE67654, //14h
/*GRF6201*/    0x002115, //0x002015, //15h
/*GRF6201*/    0x555556, //16h
/*GRF6201*/    0xBA2897, //17h
/*GRF6201*/    0xB7E258, //18h
/*GRF6201*/    0xD56619, //19h
/*GRF6201*/    0xFE419A, //1Ah
/*GRF6201*/    0x13BE9B, //1Bh
/*GRF6201*/    0x70705C  //1Ch
/*GRF6201*/ };
/*GRF6201*/ void  L1D_RF_PowerOn( void )
/*GRF6201*/ {
/*GRF6201*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*GRF6201*/    IMM_SEND_BPI( 0x0000 );
/*GRF6201*/
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[0] );  //00h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[1] );  //03h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[2] );  //01h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[3] );  //02h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[4] );  //04h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[5] );  //05h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[6] );  //06h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[7] );  //07h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[8] );  //08h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[9] );  //09h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[10] ); //0Ah
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[11] ); //0Bh
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[12] ); //0Ch
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[13] ); //0Dh
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[14] ); //0Eh
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[15] ); //0Fh
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[16] ); //10h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[17] ); //11h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[18] ); //12h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[19] ); //13h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[20] ); //14h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[21] ); //15h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[22] ); //16h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[23] ); //17h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[24] ); //18h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[25] ); //19h
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[26] ); //1Ah
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[27] ); //1Bh
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SPI_initialWord[28] ); //1Ch
/*GRF6201*/
/*GRF6201*/    IMM_MODE_END(  );
/*GRF6201*/ }
/*GRF6201*/
/*GRF6201*/ void  L1D_RF_PowerOff( void )
/*GRF6201*/ {
/*GRF6201*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*GRF6201*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x000000 ); /* MODE=00b */
/*GRF6201*/    IMM_MODE_END(  );
/*GRF6201*/ }
/*GRF6201*/
/*GRF6201*/ void  L1D_RF_WindowOn( void )
/*GRF6201*/ {  }
/*GRF6201*/
/*GRF6201*/ void  L1D_RF_WindowOff( void )
/*GRF6201*/ {  }
/*GRF6201*/
#endif

#if IS_RF_IRFS3001
/*IRFS3001*/ unsigned long SDATA_INITIALIZE[]=
/*IRFS3001*/ {   ( (0x0069L<<6) | 0x0B                ),
/*IRFS3001*/     ( (0x0460L<<6) | 0x0D                ), // PLL calibration setting
/*IRFS3001*/     ( (0x343fL<<6) | 0x09                ),
/*IRFS3001*/     ( (0x2100L<<6) | 0x0E                ),
/*IRFS3001*/     ( (0x0101L<<6) | 0x02 | XOUT13M_MASK ),
/*IRFS3001*/     ( (0x0109L<<6) | 0x02 | XOUT13M_MASK )
/*IRFS3001*/ };
/*IRFS3001*/
/*IRFS3001*/ unsigned long RXDIGOFFSC = 1;
/*IRFS3001*/ unsigned long RXDIGOFFSC_REG7;
/*IRFS3001*/
/*IRFS3001*/ void  L1D_RF_PowerOn( void )
/*IRFS3001*/ {
/*IRFS3001*/    // Turn Immediate Mode on
/*IRFS3001*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*IRFS3001*/
/*IRFS3001*/    // Initialize pin value
/*IRFS3001*/    IMM_SEND_BPI( PDATA_INIT );
/*IRFS3001*/
/*IRFS3001*/    // General common setup
/*IRFS3001*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SDATA_INITIALIZE[0] );
/*IRFS3001*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SDATA_INITIALIZE[1] );
/*IRFS3001*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SDATA_INITIALIZE[2] );
/*IRFS3001*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SDATA_INITIALIZE[3]|((XO_CapID&0x7F)<<6) );
/*IRFS3001*/
/*IRFS3001*/    // DC offset cancellation mode
/*IRFS3001*/    RXDIGOFFSC_REG7 = ( (0x804<<6)|((RXDIGOFFSC&7)<<9)|0x07 );
/*IRFS3001*/    IMM_SEND_BSI( SCTRL_IMOD(0,24),  RXDIGOFFSC_REG7 );
/*IRFS3001*/
/*IRFS3001*/    // Turn synthesizer on
/*IRFS3001*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SDATA_INITIALIZE[4] );
/*IRFS3001*/
/*IRFS3001*/    // Calibrate VCO
/*IRFS3001*/    IMM_SEND_BSI( SCTRL_IMOD(0,24), SDATA_INITIALIZE[5] );
/*IRFS3001*/
/*IRFS3001*/    // Turn Immediate Mode off
/*IRFS3001*/    IMM_MODE_END(  );
/*IRFS3001*/
/*IRFS3001*/ }
/*IRFS3001*/
/*IRFS3001*/ void  L1D_RF_PowerOff( void )
/*IRFS3001*/ {  // Enter Stand-by Mode
/*IRFS3001*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*IRFS3001*///  IMM_SEND_BSI( SCTRL_IMOD(0,24), (0x00130L<<6)|0x02|XOUT13M_MASK );
/*IRFS3001*/    IMM_SEND_BPI( PDATA_SLEEP );
/*IRFS3001*/    IMM_MODE_END(  );
/*IRFS3001*/ }
/*IRFS3001*/
/*IRFS3001*/ void  L1D_RF_WindowOn( void )
/*IRFS3001*/ {  }
/*IRFS3001*/
/*IRFS3001*/ void  L1D_RF_WindowOff( void )
/*IRFS3001*/ {  }
/*IRFS3001*/
#endif

#if IS_RF_AD6548
/*AD6548*/  #define INITIAL_REG0_RESET  0x00000000  /* Performs chip reset */
/*AD6548*/  #define INITIAL_REG0_NORST  0x00000080  /* No Reset performed */
/*AD6548*/  #define INITIAL_REG1        0x00000001|(XO_CapID<<8)
/*AD6548*/  #define INITIAL_REG5        0x00000105
/*AD6548*/  #define INITIAL_REG6        0x00291686
/*AD6548*/  #define INITIAL_REG29       0x0000001D
/*AD6548*/  #define INITIAL_REG31       0x0000001F
/*AD6548*/  #define PROG_POWER_CAL      0x00006384
/*AD6548*/  #define PROG_POWER_ON       0x00000184
/*AD6548*/  #define PROG_POWER_OFF      0x00000004
/*AD6548*/  #define PROG_CAL_BAND       0x00022F80
/*AD6548*/
/*AD6548*/  void  L1D_RF_PowerOn( void )
/*AD6548*/  {
/*AD6548*/     /* Turn Immediate Mode on*/
/*AD6548*/     IMM_MODE_BEGIN( IMMMASK_ALL );
/*AD6548*/
/*AD6548*/     /*Initialize pin value*/
/*AD6548*/     IMM_SEND_BPI( PDATA_INIT );
/*AD6548*/
/*AD6548*/  #if IS_BT_CO_CLOCK_HW_SUPPORT && IS_BT_COCLOCK_SUPPORT
/*AD6548*/     while ((HW_READ(SLEEP_SPI)&0x80)!= 0);
/*AD6548*/  #endif
/*AD6548*/
/*AD6548*/  #ifndef L1D_SIM
/*AD6548*/     if(l1d_rf.is_init)
/*AD6548*/     {
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG0_RESET ); /*Performs chip reset*/
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_ON );      /*Power on LDO1 & LDO2*/
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG5 );       /*BB gain 3dB*/
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG6 );       /*PLL Word*/
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG29 );      /*Test Register, initialize only*/
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG31 );      /*Test Register, initialize only*/
/*AD6548*/
/*AD6548*/        WAIT_TIME_QB(27);/* Wait 25 us after LDO1 and LDO2 on */
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_CAL ); /*Start auto calibration*/
/*AD6548*/
/*AD6548*/        WAIT_TIME_QB(27);/* Wait 25+25 us after LDO1 and LDO2 on */
/*AD6548*/
/*AD6548*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_CAL_BAND );
/*AD6548*/
/*AD6548*/        WAIT_TIME_QB(4660);/* Wait 4.3ms for RF internal calibration done */
/*AD6548*/     }
/*AD6548*/  #endif
/*AD6548*/
/*AD6548*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG1 );  /* AFC_CAP */
/*AD6548*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_ON );
/*AD6548*/     IMM_MODE_END(  );/*Turn Immediate Mode off*/
/*AD6548*/  }
/*AD6548*/
/*AD6548*/  void  L1D_RF_PowerOff( void )
/*AD6548*/  {
/*AD6548*/     IMM_MODE_BEGIN( IMMMASK_BSI );
/*AD6548*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_OFF ); /* Sleep mode, turn off RF LDO1 and LDO2 */
/*AD6548*/     IMM_MODE_END(  );
/*AD6548*/  }
/*AD6548*/
/*AD6548*/  void  L1D_RF_WindowOn( void )
/*AD6548*/  {  }
/*AD6548*/
/*AD6548*/  void  L1D_RF_WindowOff( void )
/*AD6548*/  {  }
/*AD6548*/
/*AD6548*/  void  L1D_RF_CAP_Set( void )
/*AD6548*/  { /* Set calibrated AFC_CAP */
/*AD6548*/     IMM_MODE_BEGIN( IMMMASK_BSI );
/*AD6548*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG1 );
/*AD6548*/     IMM_MODE_END(  );
/*AD6548*/  }
/*AD6548*/
/*AD6548*/  void  L1D_RF_CAP_Clear( void )
/*AD6548*/  { /* Set AFC_CAP to 0 to speed up settling time*/
/*AD6548*/     IMM_MODE_BEGIN( IMMMASK_BSI );
/*AD6548*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x00000001 );
/*AD6548*/     IMM_MODE_END(  );
/*AD6548*/  }
/*AD6548*/
#endif

#if IS_RF_AD6546
/*AD6546*/  #define INITIAL_REG0_RESET  0x00000000  /*Performs chip reset */
/*AD6546*/  #define INITIAL_REG0_NORST  0x00000080  /*No Reset performed */
/*AD6546*/  #define INITIAL_REG1        0x00000001|(XO_CapID<<7)
/*AD6546*/  #define INITIAL_REG5        0x00000105
/*AD6546*/  #define INITIAL_REG6        0x00291686
   #if IS_HW_DISABLE_EPSK_TX_SUPPORT
/*AD6546*/  #define INITIAL_REG30       0x0084001E
   #else
/*AD6546*/  #define INITIAL_REG30       0x00081F9E
   #endif
/*AD6546*/  #define INITIAL_REG31       0x0003901f  /*ICP/2,TX PLL BW +12%,Fast lock enable,-6dB VGA intercept shift*/
/*AD6546*/  #define PROG_POWER_CAL      0x00006384
/*AD6546*/  #define PROG_POWER_ON       0x00000184
/*AD6546*/  #define PROG_POWER_OFF      0x00000004
/*AD6546*/  #define PROG_CAL_BAND       0x00002F80|(HIGH_BAND_PATH<<16)|((1-LOW_BAND_PATH)<<17)
/*AD6546*/
/*AD6546*/  void  L1D_RF_PowerOn( void )
/*AD6546*/  {
/*AD6546*/     /* Turn Immediate Mode on*/
/*AD6546*/     IMM_MODE_BEGIN( IMMMASK_ALL );
/*AD6546*/
/*AD6546*/     /*Initialize pin value*/
/*AD6546*/     IMM_SEND_BPI( PDATA_INIT );
/*AD6546*/
/*AD6546*/  #if IS_BT_CO_CLOCK_HW_SUPPORT && IS_BT_COCLOCK_SUPPORT
/*AD6546*/     while ((HW_READ(SLEEP_SPI)&0x80)!= 0);
/*AD6546*/  #endif
/*AD6546*/
/*AD6546*/  #ifndef L1D_SIM
/*AD6546*/     if(l1d_rf.is_init)
/*AD6546*/     {
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG0_RESET );   /*Performs chip reset */
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_ON );        /*Power on LDO1 & LDO2 */
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG5 );         /*BB gain 3dB */
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG6 );         /*Initial PLL Word ARFCN 62*/
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG30 );        /*Test Register, initialize only */
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG31 );        /*ICP/2,TX PLL BW +12%,Fast lock enable,-6dB VGA intercept shift*/
/*AD6546*/
/*AD6546*/        WAIT_TIME_QB(27);/* Wait 25 us after LDO1 and LDO2 on */
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_CAL ); /*Start auto calibration*/
/*AD6546*/
/*AD6546*/        WAIT_TIME_QB(27);/* Wait 25+25 us after LDO1 and LDO2 on */
/*AD6546*/
/*AD6546*/        IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_CAL_BAND );
/*AD6546*/
/*AD6546*/        WAIT_TIME_QB(4660);/* Wait 4.3ms for RF internal calibration done */
/*AD6546*/
/*AD6546*/     }
/*AD6546*/  #endif
/*AD6546*/
/*AD6546*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG1 );  /*AFC_CAP */
/*AD6546*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_ON );
/*AD6546*/     IMM_MODE_END(  );/*Turn Immediate Mode off*/
/*AD6546*/  }
/*AD6546*/
/*AD6546*/  void  L1D_RF_PowerOff( void )
/*AD6546*/  {
/*AD6546*/     IMM_MODE_BEGIN( IMMMASK_BSI );
/*AD6546*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), PROG_POWER_OFF ); /* Sleep mode, turn off RF LDO1 and LDO2 */
/*AD6546*/     IMM_MODE_END(  );
/*AD6546*/  }
/*AD6546*/
/*AD6546*/  void  L1D_RF_WindowOn( void )
/*AD6546*/  {  }
/*AD6546*/
/*AD6546*/  void  L1D_RF_WindowOff( void )
/*AD6546*/  {  }
/*AD6546*/
/*AD6546*/  void  L1D_RF_CAP_Set( void )
/*AD6546*/  { /* Set calibrated AFC_CAP */
/*AD6546*/     IMM_MODE_BEGIN( IMMMASK_BSI );
/*AD6546*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), INITIAL_REG1 );
/*AD6546*/     IMM_MODE_END(  );
/*AD6546*/  }
/*AD6546*/
/*AD6546*/  void  L1D_RF_CAP_Clear( void )
/*AD6546*/  { /* Set AFC_CAP to 0 to speed up settling time*/
/*AD6546*/     IMM_MODE_BEGIN( IMMMASK_BSI );
/*AD6546*/     IMM_SEND_BSI( SCTRL_IMOD(0,24), 0x00000001 );
/*AD6546*/     IMM_MODE_END(  );
/*AD6546*/  }
/*AD6546*/
#endif

#if IS_RF_MT6162
/*MT6162*/
/*MT6162*/  #include "intrCtrl.h"
/*MT6162*/
/*MT6162*/  /* CW[29]    : data bit; 1=>DFM data, 0=>control word */
/*MT6162*/  /* CW[28]    : read bit; 1=>read,     0=>write        */
/*MT6162*/  /* CW[27:20] : address                                */
/*MT6162*/  /* CW[19: 0] : data                                   */
/*MT6162*/
/*MT6162*/  /* for power up */
/*MT6162*/  #define INIT_DDC_RESET_SWPOR       0x0D000001L
/*MT6162*/  #define INIT_DDC_LDOCTR_DIGEN      0x0D120001L
/*MT6162*/  #define INIT_DDC_RESET_RELEASE     0x0D00003EL
/*MT6162*/  #define INIT_TX_LO_L               0x0B42C89FL /* for E1 and E2 */
/*MT6162*/  #define INIT_TX_LO_H               0x0B532723L /* for E1 and E2 */
/*MT6162*/  #define INIT_PDCADC_CONFIG         0x0B10EAA8L /* for E1 and E2 */
/*MT6162*/  #define INIT_CW10                  0x00A41150L /* for E1 and E2 */
/*MT6162*/  #define INIT_CW44                  0x02CFFFFFL /* for E1 and E2 */
/*MT6162*/  #define INIT_RX_ABB                0x08504100L /* for E1 and E2 */
/*MT6162*/  #define INIT_RX_GAIN_TEST          0x09031000L /* for E1 and E2 */
/*MT6162*/  #define INIT_GMSK_DATA             0x0A704D85L /* for E1 and E2 */
/*MT6162*/  #define INIT_TTG_TEST              0x09707000L /* for E1 and E2, for 3G use, TTG_CP_OW_EN=1 and TTG_CP_I_SEL=3 */
/*MT6162*/  #define INIT_TX_GAINWRITE          0x0A40FFFCL /* for E1 and E2, set the smallest gain */
/*MT6162*/  #define INIT_TX_BB_FILT_2G         0x0AC20948L /* for E1 and E2 */
/*MT6162*/  #define INIT_TX_GAINRF_2G          0x0C04A864L /* for E1 and E2 */
/*MT6162*/  #define INIT_SRX_LF_ADJUST         0x06747028L /* for E1 and E2 */
/*MT6162*/  #define INIT_SRX_CP_ADJUST         0x06800019L /* for E1 and E2 */
/*MT6162*/  #define INIT_GAINRF_LUT0           0x0C175320L /* only for E1 */
/*MT6162*/  #define INIT_GAINRF_LUT1           0x0C2CBA98L /* only for E1 */
/*MT6162*/  #define INIT_GAINRF_LUT2           0x0C30DDDDL /* only for E1 */
/*MT6162*/  #define INIT_CW03                  0x00340365L /* only for E1 */
/*MT6162*/  #define INIT_CW41                  0x02901495L /* only for E1 */
/*MT6162*/  #define INIT_CW42                  0x02A01425L /* only for E1 */
/*MT6162*/  #define INIT_SRX_GEN_TEST          0x06600000L /* only for E1 */
/*MT6162*/  #define INIT_SRX_VCO_CONFIG        0x06900D37L /* only for E1 */
/*MT6162*/  #define INIT_SRX_VCO_TEST          0x06A00770L /* only for E1 */
/*MT6162*/  #define INIT_STX_VCO_CONFIG        0x02731C00L /* only for E1 */
/*MT6162*/  #define INIT_CW14                  0x00EFFD53L /* only for E2 */
/*MT6162*/  #define INIT_CW15                  0x00F00D57L /* only for E2 */
/*MT6162*/  #define INIT_CW16                  0x010FEF11L /* only for E2 */
/*MT6162*/  #define INIT_CW17                  0x011FE017L /* only for E2 */
/*MT6162*/  #define INIT_CW18                  0x01205BCFL /* only for E2 */
/*MT6162*/  #define INIT_CW19                  0x01304E49L /* only for E2 */
/*MT6162*/  #define INIT_CW20                  0x014F6C59L /* only for E2 */
/*MT6162*/  #define INIT_CW21                  0x015F8CAFL /* only for E2 */
/*MT6162*/  #define INIT_CW22                  0x016070C8L /* only for E2 */
/*MT6162*/  #define INIT_CW23                  0x0170490EL /* only for E2 */
/*MT6162*/  #define INIT_CW24                  0x018FC84CL /* only for E2 */
/*MT6162*/  #define INIT_CW25                  0x019FF2AAL /* only for E2 */
/*MT6162*/  #define INIT_CW26                  0x01A01232L /* only for E2 */
/*MT6162*/  #define INIT_CW27                  0x01BFFC6EL /* only for E2 */
/*MT6162*/  #define INIT_CW28                  0x01CFFFA2L /* only for E2 */
/*MT6162*/  #define INIT_CW29                  0x01D00000L /* only for E2 */
/*MT6162*/  #define INIT_CW43                  0x02B9C00CL /* only for E2 */
/*MT6162*/  #define INIT_CW58                  0x03A39878L /* only for E2 */
/*MT6162*/  #define INIT_CW00_E1               0x000402A0L /* for E1 */
/*MT6162*/  #define INIT_CW00_E2               0x000402A8L /* for E2, increase the CP to increase Loop BW for freq error */
/*MT6162*/  #define INIT_SRX_VCOCAL_E1         0x065E0000L /* for E1, AFC enable */
/*MT6162*/  #define INIT_SRX_VCOCAL_E2         0x06560000L /* for E2, AFC enable */
/*MT6162*/  #define INIT_DCXO_CDAC_MASK        0x0E000000L /* for CapID */
/*MT6162*/
/*MT6162*/  #define INIT_REGISTER_NUM_E1       26
/*MT6162*/  #define INIT_REGISTER_NUM_E2       34
/*MT6162*/  unsigned long rfid_readback;
/*MT6162*/  const unsigned long SDATA_INIT_REGISTER_E1[INIT_REGISTER_NUM_E1]=
/*MT6162*/  {
/*MT6162*/     INIT_TX_LO_L,        INIT_TX_LO_H,        INIT_PDCADC_CONFIG,
/*MT6162*/     INIT_CW10,           INIT_CW44,           INIT_RX_ABB,
/*MT6162*/     INIT_RX_GAIN_TEST,   INIT_GMSK_DATA,      INIT_TTG_TEST,
/*MT6162*/     INIT_TX_BB_FILT_2G,  INIT_TX_GAINRF_2G,   INIT_TX_GAINWRITE,
/*MT6162*/     INIT_GAINRF_LUT0,    INIT_GAINRF_LUT1,    INIT_GAINRF_LUT2,
/*MT6162*/     INIT_CW00_E1,        INIT_CW03,           INIT_CW41,
/*MT6162*/     INIT_CW42,           INIT_SRX_GEN_TEST,   INIT_SRX_LF_ADJUST,
/*MT6162*/     INIT_SRX_CP_ADJUST,  INIT_SRX_VCO_CONFIG, INIT_SRX_VCO_TEST,
/*MT6162*/     INIT_STX_VCO_CONFIG, INIT_SRX_VCOCAL_E1,
/*MT6162*/  };
/*MT6162*/
/*MT6162*/  const unsigned long SDATA_INIT_REGISTER_E2[INIT_REGISTER_NUM_E2]=
/*MT6162*/  {
/*MT6162*/     INIT_TX_LO_L,        INIT_TX_LO_H,        INIT_PDCADC_CONFIG,
/*MT6162*/     INIT_CW10,           INIT_CW44,           INIT_RX_ABB,
/*MT6162*/     INIT_SRX_LF_ADJUST,  INIT_SRX_CP_ADJUST,  INIT_TX_BB_FILT_2G,
/*MT6162*/     INIT_TX_GAINRF_2G,   INIT_SRX_VCOCAL_E2,  INIT_RX_GAIN_TEST,
/*MT6162*/     INIT_GMSK_DATA,      INIT_TTG_TEST,       INIT_TX_GAINWRITE,
/*MT6162*/     INIT_CW00_E2,        INIT_CW14,           INIT_CW15,
/*MT6162*/     INIT_CW16,           INIT_CW17,           INIT_CW18,
/*MT6162*/     INIT_CW19,           INIT_CW20,           INIT_CW21,
/*MT6162*/     INIT_CW22,           INIT_CW23,           INIT_CW24,
/*MT6162*/     INIT_CW25,           INIT_CW26,           INIT_CW27,
/*MT6162*/     INIT_CW28,           INIT_CW29,           INIT_CW43,
/*MT6162*/     INIT_CW58,
/*MT6162*/  };
/*MT6162*/
/*MT6162*/  /* for power down */
/*MT6162*/  #define TX_MODE_CTRL_PWRDWN        0x0A100000L
/*MT6162*/  #define RX_MODE_PWRDWN             0x08100000L
/*MT6162*/  #define DDC_LDOCTR_IDLE            0x0D120000L
/*MT6162*/  #define DDC_RESET_RESET            0x0D000000L
/*MT6162*/  #define DDC_LDOCTR_DUPLEX_OFF      0x0D120001L
/*MT6162*/
/*MT6162*/  /* for baseband filter calibration */
/*MT6162*/  #define DDC_LDOCTR_RXFLTCAL        0x0D124101L
/*MT6162*/  #define RX_RCCAL_LPFCAL            0x084000EEL /* 0526 TzeYee updated, original setting=>0x084000E4L */
/*MT6162*/  #define RX_RCCAL_WRITEBACK_MASK    0x084002E4L
/*MT6162*/  #define DDC_LDOCTR_RXFLTCAL_OFF    0x0D120001L
/*MT6162*/
/*MT6162*/  /* for calibration readback */
/*MT6162*/  unsigned long lpfcap_readback;
/*MT6162*/
/*MT6162*/  extern void L1D_DM_Power_Control_Trace( char is_2g, char is_3g );
/*MT6162*/  void  L1D_RF_PowerOn( void )
/*MT6162*/  {  int i;
/*MT6162*/     unsigned long _savedMask;
/*MT6162*/     unsigned long ctrl, data;
/*MT6162*/              long addr;
/*MT6162*/
/*MT6162*/     /* Turn Immediate Mode on */
/*MT6162*/     if( IS_AFC_TRIGGER_BSI() )
/*MT6162*/     {  IMM_MODE_BEGIN( IMMMASK_BSI|IMMMASK_BPI );  }
/*MT6162*/     else
/*MT6162*/     {  IMM_MODE_BEGIN( IMMMASK_ALL );              }
/*MT6162*/
/*MT6162*/     if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6162*/     {
/*MT6162*/        if( l1d_rf.is_init )
/*MT6162*/        {
/*MT6162*/           L1D_PMU_VRF18Setting( 1 );                                   /* Enable VDD_18 (controlled by PMIC) */
/*MT6162*/           l1d_rf2.is_2g_on = 2;                                        /* Record the PMU step                */
/*MT6162*/           L1D_PMU_VRF28Setting( 1 );                                   /* Enable VDD_28 (controlled by PMIC) */
/*MT6162*/           l1d_rf2.is_2g_on = 4;                                        /* Record the PMU step                */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), INIT_DDC_RESET_SWPOR );      /* DDC_RESET_Reset */
/*MT6162*/           WAIT_TIME_QB( 300 );                                         /* wait for SW POR */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), INIT_DDC_LDOCTR_DIGEN );     /* DDC_LDOCTR_DigEn */
/*MT6162*/           WAIT_TIME_QB(55);                                            /* 50us, Wait T_LDO */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), INIT_DDC_RESET_RELEASE );    /* DDC_RESET_Release */
/*MT6162*/
/*MT6162*/           IMM_RECEIVE_BSI( SCTRL_IMOD(0,10), 0xEF, SCTRL_IMOD(0,20), &(rfid_readback) ); /* read back RFID */
/*MT6162*/           l1d_rf2.mt6162_rfid = (char) ( rfid_readback&0xFF );
/*MT6162*/
/*MT6162*/           if( L1D_RF_Get6162Version() == 1 )
/*MT6162*/           {  /* Set values into initialization registers for OH E1 */
/*MT6162*/              for( i=0; i<INIT_REGISTER_NUM_E1; i++ )
/*MT6162*/              {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_INIT_REGISTER_E1[i] );  }
/*MT6162*/           }
/*MT6162*/           else
/*MT6162*/           {  /* Set values into initialization registers for OH E2 */
/*MT6162*/              for( i=0; i<INIT_REGISTER_NUM_E2; i++ )
/*MT6162*/              {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_INIT_REGISTER_E2[i] );  }
/*MT6162*/              IMM_SEND_BSI( SCTRL_IMOD(0,30), L1D_RF_GetClockControl() );
/*MT6162*/           }
/*MT6162*/           l1d_rf2.is_2g_on = 1;                                        /* set 2G flag to notify 2G is ON */
/*MT6162*/           L1D_DM_Power_Control_Trace( 1, 2 );                          /* indicate the init state */
/*MT6162*/        }
/*MT6162*/        else
/*MT6162*/        {
/*MT6162*/ #if defined(__UMTS_RAT__)
/*MT6162*/           extern char UL1D_RF_CheckDMPower( void );                    /* check 3g RF flag */
/*MT6162*/ #endif
/*MT6162*/           _savedMask = SaveAndSetIRQMask();                            /* disable interrupt */
/*MT6162*/
/*MT6162*/ #if defined(__UMTS_RAT__)
/*MT6162*/           if( UL1D_RF_CheckDMPower() )                                 /* 3G is already ON, so 2G does not do the power-on reset */
/*MT6162*/           {
/*MT6162*/              l1d_rf2.is_2g_on = 1;                                     /* set 2G flag to notify 2G is ON */
/*MT6162*/              L1D_DM_Power_Control_Trace( 1, 1 );                       /* indicate 2G is ON and 3G is ON */
/*MT6162*/              RestoreIRQMask(_savedMask);                               /* enable interrupt */
/*MT6162*/           }
/*MT6162*/           else                                                         /* 3G is not ON yet, so 2G does the power-on reset */
/*MT6162*/ #endif
/*MT6162*/           {
/*MT6162*/              l1d_rf2.is_2g_on = 1;                                     /* set 2G flag to notify 2G is ON */
/*MT6162*/              L1D_DM_Power_Control_Trace( 1, 0 );                       /* indicate 2G is ON and 3G is OFF */
/*MT6162*/              RestoreIRQMask(_savedMask);                               /* enable interrupt */
/*MT6162*/              L1D_PMU_VRF18Setting( 1 );                                /* Enable VDD_18 (controlled by PMIC) */
/*MT6162*/              l1d_rf2.is_2g_on = 3;                                     /* Record the PMU step                */
/*MT6162*/              L1D_PMU_VRF28Setting( 1 );                                /* Enable VDD_28 (controlled by PMIC) */
/*MT6162*/              l1d_rf2.is_2g_on = 5;                                     /* Record the PMU step                */
/*MT6162*/              IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_RESET_RESET );        /* DDC_RESET_Reset */
/*MT6162*/              IMM_SEND_BSI( SCTRL_IMOD(0,30), INIT_DDC_LDOCTR_DIGEN );  /* DDC_LDOCTR_DigEn */
/*MT6162*/              WAIT_TIME_QB(55);                                         /* 50us, Wait T_LDO */
/*MT6162*/              IMM_SEND_BSI( SCTRL_IMOD(0,30), INIT_DDC_RESET_RELEASE ); /* DDC_RESET_Release */
/*MT6162*/
/*MT6162*/              if( L1D_RF_Get6162Version()==1 )
/*MT6162*/              {  /* Set values into initialization registers for OH E1 */
/*MT6162*/                 for( i=0; i<INIT_REGISTER_NUM_E1; i++ )
/*MT6162*/                 {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_INIT_REGISTER_E1[i] );  }
/*MT6162*/              }
/*MT6162*/              else
/*MT6162*/              {  /* Set values into initialization registers for OH E2 */
/*MT6162*/                 for( i=0; i<INIT_REGISTER_NUM_E2; i++ )
/*MT6162*/                 {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_INIT_REGISTER_E2[i] );  }
/*MT6162*/                 IMM_SEND_BSI( SCTRL_IMOD(0,30), L1D_RF_GetClockControl() );
/*MT6162*/              }
/*MT6162*/           }
/*MT6162*/        }
/*MT6162*/
/*MT6162*/
/*MT6162*/        if( l1d_rf.is_init )
/*MT6162*/        {
/*MT6162*/           /* Initial Calibration */
/*MT6162*/           L1D_RF_BASEBAND_FILTER_CAL();
/*MT6162*/        }
/*MT6162*/        else
/*MT6162*/        {
/*MT6162*/           /* Write back the LPFCAP[4:0] value to the RX_RCCAL(0x84) register */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), ((l1d_rf2.lpfcap&0x1F)<<10)|RX_RCCAL_WRITEBACK_MASK );
/*MT6162*/        }
/*MT6162*/     }
/*MT6162*/     else
/*MT6162*/     {
/*MT6162*/        ctrl = SCTRL_IMOD(0,30);
/*MT6162*/        data = (XO_CapID&0xFF)|INIT_DCXO_CDAC_MASK;
/*MT6162*/        HW_WRITE( BSI_CON, SCTRL_IMOD_MAIN );
/*MT6162*/        addr = (long)BSI_Dn_CON(103);
/*MT6162*/        HW_WRITE( (APBADDR)addr, ctrl );  addr += 4;
/*MT6162*/        HW_WRITE_BSI_DATA( addr, data );
/*MT6162*/        HW_DUMMY_READ_BSI_DATA( addr );
   #if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H
/*MT6162*/        HW_WRITE( GSM_BSI_ACTUPT, 0x8067 ); /* update BSI_103 to the active buffer */
/*MT6162*/        HW_DUMMY_READ_BSI_DATA( addr );
   #endif
/*MT6162*/        HW_WRITE( BSI_CON, SCTRL_IMOD_SEND);
/*MT6162*/        WAIT_TIME_QB(IMM_BSI_WAIT_TIME_QB);
/*MT6162*/
/*MT6162*/        data = L1D_RF_GetClockControl();
/*MT6162*/        HW_WRITE( BSI_CON, SCTRL_IMOD_MAIN );
/*MT6162*/        addr = (long)BSI_Dn_CON(103);
/*MT6162*/        HW_WRITE( (APBADDR)addr, ctrl );  addr += 4;
/*MT6162*/        HW_WRITE_BSI_DATA( addr, data );
/*MT6162*/        HW_DUMMY_READ_BSI_DATA( addr );
   #if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H
/*MT6162*/        HW_WRITE( GSM_BSI_ACTUPT, 0x8067 ); /* update BSI_103 to the active buffer */
/*MT6162*/        HW_DUMMY_READ_BSI_DATA( addr );
   #endif
/*MT6162*/        HW_WRITE( BSI_CON, SCTRL_IMOD_SEND );
/*MT6162*/        WAIT_TIME_QB( IMM_BSI_WAIT_TIME_QB );
/*MT6162*/
/*MT6162*/        addr = (long)BSI_Dn_CON(103);       /* set BSI_103 back to SCTRL_RESERVED */
/*MT6162*/        HW_WRITE( (APBADDR)addr, SCTRL_RESERVED );  addr += 4;
/*MT6162*/        HW_WRITE_BSI_DATA( addr, 0 );
/*MT6162*/     }
/*MT6162*/     /* Turn Immediate Mode off */
/*MT6162*/     IMM_MODE_END(  );
/*MT6162*/
/*MT6162*/     L1D_RF_TXPC_CL_AUXADC_POWERON();
/*MT6162*/  }
/*MT6162*/
/*MT6162*/  void  L1D_RF_PowerOff( void )
/*MT6162*/  {
/*MT6162*/     unsigned long _savedMask;
/*MT6162*/
/*MT6162*/     IMM_MODE_BEGIN( IMMMASK_BSI );                                 /* Turn Immediate Mode on */
/*MT6162*/
/*MT6162*/     if(1) //if( l1d_rf.is_sleep ) /* in the case of entering the sleep mode */
/*MT6162*/     {
/*MT6162*/ #if defined(__UMTS_RAT__)
/*MT6162*/        extern char UL1D_RF_CheckDMPower( void );                   /* check 3g RF flag */
/*MT6162*/ #endif
/*MT6162*/        _savedMask = SaveAndSetIRQMask();                           /* disable interrupt */
/*MT6162*/
/*MT6162*/ #if defined(__UMTS_RAT__)
/*MT6162*/        if( UL1D_RF_CheckDMPower() )                                /* 3G is still ON, so 2G can not do the power-off sequence */
/*MT6162*/        {
/*MT6162*/           l1d_rf2.is_2g_on = 0;                                    /* clear 2G flag to notify 2G is OFF */
/*MT6162*/           L1D_DM_Power_Control_Trace( 0, 1 );                      /* indicate 2G is OFF and 3G is ON */
/*MT6162*/           RestoreIRQMask(_savedMask);                              /* enable interrupt */
/*MT6162*/        }
/*MT6162*/        else                                                        /* 3G is already OFF, so 2G does the power-off sequence */
/*MT6162*/ #endif
/*MT6162*/        {
/*MT6162*/           l1d_rf2.is_2g_on = 0;                                    /* clear 2G flag to notify 2G is OFF */
/*MT6162*/           L1D_DM_Power_Control_Trace( 0, 0 );                      /* indicate 2G is OFF and 3G is OFF */
/*MT6162*/           RestoreIRQMask(_savedMask);                              /* enable interrupt */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), TX_MODE_CTRL_PWRDWN );   /* TX_MODE_CTRL_PwrDwn */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), RX_MODE_PWRDWN );        /* RXMODE_PwrDwn */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_LDOCTR_IDLE );       /* DDC_LDOCTR, disable LDOs */
/*MT6162*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_RESET_RESET );       /* DDCCtrl_ResetDig */
/*MT6162*/           L1D_PMU_VRF18Setting( 0 );                               /* Disable VDD_18 (controlled by PMIC) */
/*MT6162*/           l1d_rf2.is_2g_on = 6;                                    /* Record the PMU step                 */
/*MT6162*/           L1D_PMU_VRF28Setting( 0 );                               /* Disable VDD_28 (controlled by PMIC) */
/*MT6162*/           l1d_rf2.is_2g_on = 8;                                    /* Record the PMU step                 */
/*MT6162*/        }
/*MT6162*/     }
/*MT6162*/     else
/*MT6162*/     {
/*MT6162*/        IMM_SEND_BSI( SCTRL_IMOD(0,30), TX_MODE_CTRL_PWRDWN );      /* TX_MODE_CTRL_PwrDwn */
/*MT6162*/        IMM_SEND_BSI( SCTRL_IMOD(0,30), RX_MODE_PWRDWN );           /* RXMODE_PwrDwn */
/*MT6162*/        /* In Meta, when 3G RF TOOL is selected, L1D_RF_PowerOff will be called */
/*MT6162*/        /* DDC_LDOCTR_Idle/DDC_RESET_reset turns off OH all function and initialized registers so 3G can't work */
/*MT6162*/        IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_LDOCTR_DUPLEX_OFF );    /* keep LDO in the digital state */
/*MT6162*/     }
/*MT6162*/
/*MT6162*/     IMM_MODE_END(  );                                              /* Turn Immediate Mode off */
/*MT6162*/
/*MT6162*/     L1D_RF_TXPC_CL_AUXADC_POWEROFF();
/*MT6162*/  }
/*MT6162*/
/*MT6162*/  void  L1D_RF_WindowOn( void )
/*MT6162*/  {  }
/*MT6162*/
/*MT6162*/  void  L1D_RF_WindowOff( void )
/*MT6162*/  {  }
/*MT6162*/
/*MT6162*/  void L1D_RF_BASEBAND_FILTER_CAL( void )
/*MT6162*/  {
/*MT6162*/     IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_LDOCTR_RXFLTCAL );         /* enable digital LDO and RX LDO */
/*MT6162*/     WAIT_TIME_QB( 55 );                                            /* 50us, Wait T_LDO */
/*MT6162*/     IMM_SEND_BSI( SCTRL_IMOD(0,30), RX_RCCAL_LPFCAL );             /* start the calibration */
/*MT6162*/     WAIT_TIME_QB( 44 );                                            /* 40us, Wait T_LPFCal*/
/*MT6162*/     IMM_RECEIVE_BSI( SCTRL_IMOD(0,10), 0x84, SCTRL_IMOD(0,20), &(lpfcap_readback) );
/*MT6162*/     l1d_rf2.lpfcap = (char)( (lpfcap_readback>>10) & 0x1F );
/*MT6162*/     IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_LDOCTR_RXFLTCAL_OFF );     /* turn off LDO */
/*MT6162*/  }
/*MT6162*/
#endif

#if IS_RF_MT6163
/*MT6163*/
/*MT6163*/  #include "intrCtrl.h"
/*MT6163*/  #include "us_timer.h"
/*MT6163*/
/*MT6163*/  /* CW[29]    : data bit; 1=>DFM data, 0=>control word */
/*MT6163*/  /* CW[28]    : read bit; 1=>read,     0=>write        */
/*MT6163*/  /* CW[27:20] : address                                */
/*MT6163*/  /* CW[19: 0] : data                                   */
/*MT6163*/
/*MT6163*/  /* For OT POR */
/*MT6163*/  #define INIT_DFM_VCO_SUBBAND_CAL    0x0091FFFCL
/*MT6163*/  #define INIT_DFM_LG_CW15            0x00F5515EL
/*MT6163*/  #define INIT_DFM_LG_CW16            0x0100FD68L
/*MT6163*/  #define INIT_DFM_LG_CW17            0x0118F728L
/*MT6163*/  #define INIT_DFM_LG_CW54            0x0362FD0DL
/*MT6163*/  #define INIT_VCO_DIST               0x08100009L
/*MT6163*/  #define INIT_RX_RCCAL               0x084002EFL
/*MT6163*/  #define INIT_RX_ABB_CON             0x08540500L       /* Swap RX I-path polarity */
/*MT6163*/  #define INIT_RX_GAIN_TEST           0x09010000L
/*MT6163*/  #define INIT_TX_BB_FILT_2G          0x0AC20948L
/*MT6163*/  #define INIT_TX_SPARES              0x0B300019L
/*MT6163*/  #define INIT_PM_PRE_LDO_VS          0x0D436DB4L
/*MT6163*/  #define INIT_DCXO_SCAN_TEST_CTRL    0x0EEC8000L       /* Disable clk safe mode for customized ref clk buffer output */
/*MT6163*/
/*MT6163*/  /* For OT power-up */
/*MT6163*/  #define INIT_DDC_RESET_SWPOR        0x0D000001L
/*MT6163*/  #define DDC_LDOCTR_DIGEN            0x0D100008L       /* PMT = Dig_EN */
/*MT6163*/  #define DDC_RESET_RELEASE           0x0D000036L
/*MT6163*/  #define DCXO_CDAC_MASK              0x0E000000L       /* For CapID */
/*MT6163*/
/*MT6163*/  /* For OT wake-up & power-down */
/*MT6163*/  #define DDC_LDOCTR_DIGOFF           0x0D100000L       /* PMT = Off */
/*MT6163*/  #define DDC_RESET_RESET             0x0D000000L
/*MT6163*/
/*MT6163*/  /* For OT RX&TX baseband filter calibration */
/*MT6163*/  #define DDC_LDOCTR_RXFLTCAL         0x0D100018L       /* PMT = RX on */
/*MT6163*/  #define RX_RCCAL_LPFCAL             (INIT_RX_RCCAL & 0xFFFFFDFF)
/*MT6163*/  #define DDC_LDOCTR_RXFLTCAL_OFF     DDC_LDOCTR_DIGEN  /* PMT = Dig_EN */
/*MT6163*/  #define RX_RCCAL_WRITEBACK_MASK     INIT_RX_RCCAL
/*MT6163*/
/*MT6163*/  /* OT Misc */
/*MT6163*/  #define BSI_DAT_PWR_ON              103
/*MT6163*/
/*MT6163*/  const unsigned long SDATA_INIT_OT_E1[] =
/*MT6163*/  {
/*MT6163*/     INIT_RX_RCCAL,
/*MT6163*/     INIT_VCO_DIST,
/*MT6163*/     INIT_PM_PRE_LDO_VS,
/*MT6163*/     INIT_TX_BB_FILT_2G,
/*MT6163*/     INIT_RX_GAIN_TEST,
/*MT6163*/     INIT_DFM_VCO_SUBBAND_CAL,
/*MT6163*/     INIT_TX_SPARES,
/*MT6163*/     INIT_DFM_LG_CW15,
/*MT6163*/     INIT_DFM_LG_CW16,
/*MT6163*/     INIT_DFM_LG_CW17,
/*MT6163*/     INIT_DFM_LG_CW54,
/*MT6163*/     INIT_RX_ABB_CON,
/*MT6163*/     INIT_DCXO_SCAN_TEST_CTRL
/*MT6163*/  };
/*MT6163*/  #define RF_POR_NUM (sizeof(SDATA_INIT_OT_E1)/sizeof(unsigned long))
/*MT6163*/
/*MT6163*/  #if IS_BSI_TRIG_OFFCHIP_VRF18_SUPPORT
/*MT6163*/  #define L1D_VRF18SETTING( is_on )                           \
/*MT6163*/  {  if( is_on )                                              \
/*MT6163*/     {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_VRF18_ON );  }  \
/*MT6163*/     else                                                     \
/*MT6163*/     {  IMM_OFFCHIP_BSI_CFG( BSI_SWITCH_NO_ACT_ONCE );        \
/*MT6163*/        IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_VRF18_OFF );    \
/*MT6163*/     }                                                        \
/*MT6163*/  }
/*MT6163*/  #define L1D_VRF18_OFFCHIP_STATUS_UPDATE( is_on )                           \
/*MT6163*/  {  unsigned long vrf18 = (is_on) ? SDATA_VRF18_ON_ONLY : SDATA_VRF18_OFF;  \
/*MT6163*/     IMM_OFFCHIP_BSI_CFG( BSI_SWITCH_NO_ACT_ONCE );                          \
/*MT6163*/     IMM_SEND_BSI( SCTRL_IMOD(0,30), vrf18 );                                \
/*MT6163*/  }
/*MT6163*/  #else
/*MT6163*/  #define L1D_VRF18SETTING( is_on )                           \
/*MT6163*/  {                                                           \
/*MT6163*/     if( l1d_rf.is_init)                                      \
/*MT6163*/     {  L1D_PMU_VRF18HWModeSelect();                          \
/*MT6163*/        L1D_PMU_VRF18ModeSetting( is_on );                    \
/*MT6163*/     }                                                        \
/*MT6163*/     L1D_PMU_VRF18Setting( is_on );                           \
/*MT6163*/  }
/*MT6163*/  #define L1D_VRF18_OFFCHIP_STATUS_UPDATE( is_on )   {;}
/*MT6163*/  #endif
/*MT6163*/
/*MT6163*/  #if IS_SRCLKENA_TRIG_VRF28_SUPPORT
/*MT6163*/  #define L1D_VRF28SETTING( is_on )                           \
/*MT6163*/  {                                                           \
/*MT6163*/     if( l1d_rf.is_init)                                      \
/*MT6163*/     {  L1D_PMU_VRF28HWModeSelect();                          \
/*MT6163*/        L1D_PMU_VRF28ModeSetting( is_on );                    \
/*MT6163*/     }                                                        \
/*MT6163*/  }
/*MT6163*/  #else
/*MT6163*/  #define L1D_VRF28SETTING( is_on )                  L1D_PMU_VRF28Setting( is_on )
/*MT6163*/  #endif
/*MT6163*/
/*MT6163*/  extern void L1D_DM_Power_Control_Trace( char is_2g, char is_3g );
/*MT6163*/
/*MT6163*/  void  L1D_RF_PowerOn( void )
/*MT6163*/  {
/*MT6163*/     int i;
/*MT6163*/     unsigned long ctrl, data;
/*MT6163*/              long addr;
/*MT6163*/
/*MT6163*/     /* Turn on Immediate Mode */
/*MT6163*/     IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6163*/
/*MT6163*/     if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6163*/     {
/*MT6163*/        if( l1d_rf.is_init )
/*MT6163*/        {
/*MT6163*/           IMM_OFFCHIP_BSI_CFG( BSI_SWITCH_2G );                       /* Set off-chip BSI switch owner to be 2G */
/*MT6163*/
/*MT6163*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), INIT_DDC_RESET_SWPOR );     /* SOFT_RESET */
/*MT6163*/           WAIT_TIME_QB( 120 );                                        /* Wait at least 80us, for SW POR */
/*MT6163*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_LDOCTR_DIGEN );         /* DDC_LDOCTR_DigEn */
/*MT6163*/           WAIT_TIME_QB( 22 );                                         /* 20us, Wait T_LDO */
/*MT6163*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_RESET_RELEASE );        /* DDC_RESET_Release */
/*MT6163*/
/*MT6163*/           /* Set initial values to registers */
/*MT6163*/           for( i=0; i<RF_POR_NUM; i++ )
/*MT6163*/           {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_INIT_OT_E1[i] );  }
/*MT6163*/
/*MT6163*/           IMM_SEND_BSI( SCTRL_IMOD(0,30), L1D_RF_GetClockControl() );
/*MT6163*/
/*MT6163*/           L1D_VRF18SETTING( 1 );                                      /* Enable AVDD18_HF */
/*MT6163*/           L1D_VRF28SETTING( 1 );                                      /* Enable AVDD28_HF (controlled by PMIC) */
/*MT6163*/ #if IS_CHIP_MT6583_MD2
/*MT6163*/           WAIT_TIME_QB(300);                                          /* Wait 277us for PMIC settling time after swtich to HW mode */
/*MT6163*/ #endif
/*MT6163*/
/*MT6163*/           l1d_rf2.is_2g_on = 1;
/*MT6163*/           L1D_RF_SET_2G_POWER_STATUS( 1 );
/*MT6163*/           L1D_DM_Power_Control_Trace( 1, 2 );                         /* Indicate the init state */
/*MT6163*/
/*MT6163*/           L1D_RF_BASEBAND_FILTER_CAL();                               /* Initial Calibration */
/*MT6163*/
/*MT6163*/           IMM_OFFCHIP_BSI_CFG( BSI_SWITCH_TD );                       /* Set off-chip BSI switch owner to be TD */
/*MT6163*/        }
/*MT6163*/        else /* wake-up */
/*MT6163*/        {
/*MT6163*/           l1d_rf2.is_2g_on = 1;
/*MT6163*/
/*MT6163*/           if( L1D_RF_CHECK_TDD_POWER( 1 ) )
/*MT6163*/           {
/*MT6163*/              L1D_VRF18_OFFCHIP_STATUS_UPDATE( 1 );                    /* Ensure 2G Vrf18 requirement is sync to remote control register */
/*MT6163*/              L1D_DM_Power_Control_Trace( 1, 1 );                      /* Indicate 2G is ON and TD is ON */
/*MT6163*/           }
/*MT6163*/           else
/*MT6163*/           {
/*MT6163*/              L1D_DM_Power_Control_Trace( 1, 0 );                      /* Indicate 2G is ON and TD is OFF */
/*MT6163*/
/*MT6163*/              IMM_OFFCHIP_BSI_CFG( BSI_SWITCH_2G );                    /* Set off-chip BSI switch owner to be 2G */
/*MT6163*/
/*MT6163*/              IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_RESET_RESET );       /* DDC_RESET_Reset */
/*MT6163*/              IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_LDOCTR_DIGEN );      /* DDC_LDOCTR_DigEn */
/*MT6163*/              WAIT_TIME_QB( 22 );                                      /* 20us, Wait T_LDO */
/*MT6163*/              IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_RESET_RELEASE );     /* DDC_RESET_Release */
/*MT6163*/
/*MT6163*/              /* Set initial values to registers */
/*MT6163*/              for( i=0; i<RF_POR_NUM; i++ )
/*MT6163*/              {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_INIT_OT_E1[i] );  }
/*MT6163*/
/*MT6163*/              IMM_SEND_BSI( SCTRL_IMOD(0,30), L1D_RF_GetClockControl() );
/*MT6163*/
/*MT6163*/              L1D_VRF18SETTING( 1 );                                   /* Enable AVDD18_HF */
/*MT6163*/              L1D_VRF28SETTING( 1 );                                   /* Enable AVDD28_HF (controlled by PMIC) */
/*MT6163*/
/*MT6163*/              /* Write back the LPFCAP[4:0] value to the RX_RCCAL(0x84) register */
/*MT6163*/              IMM_SEND_BSI( SCTRL_IMOD(0,30), ((l1d_rf2.lpfcap&0x1F)<<10)|RX_RCCAL_WRITEBACK_MASK );
/*MT6163*/
/*MT6163*/              IMM_OFFCHIP_BSI_CFG( BSI_SWITCH_TD );                    /* Set off-chip BSI switch owner to be TD */
/*MT6163*/           }
/*MT6163*/        }
/*MT6163*/     }
/*MT6163*/     else /* Not init nor wakeup */
/*MT6163*/     {
/*MT6163*/        IMM_OFFCHIP_BSI_CFG( BSI_SWITCH_2G );                          /* Set off-chip BSI switch owner to be 2G */
/*MT6163*/
/*MT6163*/        ctrl = SCTRL_IMOD(0,30);
/*MT6163*/
/*MT6163*/        /* Config Cap ID */
/*MT6163*/        data = (XO_CapID&0xFF)|DCXO_CDAC_MASK;
/*MT6163*/        HW_WRITE( BSI_CON, SCTRL_IMOD_MAIN );
/*MT6163*/        addr = (long)BSI_Dn_CON( BSI_DAT_PWR_ON );
/*MT6163*/        HW_WRITE( (APBADDR)addr, ctrl );  addr += 4;
/*MT6163*/        HW_WRITE_BSI_DATA( addr, data );
/*MT6163*/        HW_DUMMY_READ_BSI_DATA( addr );
/*MT6163*/  #if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H || IS_CHIP_MT6583_MD2
/*MT6163*/        HW_WRITE( GSM_BSI_ACTUPT, 0x8000|BSI_DAT_PWR_ON );
/*MT6163*/        HW_DUMMY_READ_BSI_DATA( addr );
/*MT6163*/  #endif
/*MT6163*/        HW_WRITE( BSI_CON, SCTRL_IMOD_SEND );
/*MT6163*/        WAIT_TIME_QB( IMM_BSI_WAIT_TIME_QB );
/*MT6163*/
/*MT6163*/        /* Config 26M output buffer */
/*MT6163*/        data = L1D_RF_GetClockControl();
/*MT6163*/        HW_WRITE( BSI_CON, SCTRL_IMOD_MAIN );
/*MT6163*/        addr = (long)BSI_Dn_CON( BSI_DAT_PWR_ON );
/*MT6163*/        HW_WRITE( (APBADDR)addr, ctrl );  addr += 4;
/*MT6163*/        HW_WRITE_BSI_DATA( addr, data );
/*MT6163*/        HW_DUMMY_READ_BSI_DATA( addr );
/*MT6163*/  #if IS_EDGE_SAIC_CHIP_MT6270A_AND_LATTER_VERSION || IS_CHIP_MT6268H || IS_CHIP_MT6583_MD2
/*MT6163*/        HW_WRITE( GSM_BSI_ACTUPT, 0x8000|BSI_DAT_PWR_ON );
/*MT6163*/        HW_DUMMY_READ_BSI_DATA( addr );
/*MT6163*/  #endif
/*MT6163*/        HW_WRITE( BSI_CON, SCTRL_IMOD_SEND );
/*MT6163*/        WAIT_TIME_QB( IMM_BSI_WAIT_TIME_QB );
/*MT6163*/
/*MT6163*/        /* Set BSI_DAT_PWR_ON (103) back to SCTRL_RESERVED */
/*MT6163*/        addr = (long)BSI_Dn_CON( BSI_DAT_PWR_ON );
/*MT6163*/        HW_WRITE( (APBADDR)addr, SCTRL_RESERVED );  addr += 4;
/*MT6163*/        HW_WRITE_BSI_DATA( addr, 0 );
/*MT6163*/
/*MT6163*/        IMM_OFFCHIP_BSI_CFG( BSI_SWITCH_TD );                          /* Set off-chip BSI switch owner to be TD */
/*MT6163*/     }
/*MT6163*/     /* Turn Immediate Mode off */
/*MT6163*/     IMM_MODE_END();
/*MT6163*/
/*MT6163*/     L1D_RF_TXPC_CL_AUXADC_POWERON();
/*MT6163*/  }
/*MT6163*/
/*MT6163*/  void  L1D_RF_PowerOff( void )
/*MT6163*/  {
/*MT6163*/     IMM_MODE_BEGIN( IMMMASK_BSI );                              /* Turn Immediate Mode on */
/*MT6163*/
/*MT6163*/     l1d_rf2.is_2g_on = 0;
/*MT6163*/
/*MT6163*/     if( L1D_RF_CHECK_TDD_POWER( 0 ) )
/*MT6163*/     {
/*MT6163*/        L1D_VRF18_OFFCHIP_STATUS_UPDATE( 0 );                    /* Ensure 2G Vrf18 requirement is sync to remote control register */
/*MT6163*/        L1D_DM_Power_Control_Trace( 0, 1 );                      /* Indicate 2G is OFF and TD is ON */
/*MT6163*/     }
/*MT6163*/     else
/*MT6163*/     {
/*MT6163*/        L1D_DM_Power_Control_Trace( 0, 0 );                      /* Indicate 2G is OFF and 3G is OFF */
/*MT6163*/
/*MT6163*/        IMM_OFFCHIP_BSI_CFG( BSI_SWITCH_2G );                    /* Set off-chip BSI switch owner to be 2G */
/*MT6163*/        IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_LDOCTR_DIGOFF );     /* DigEN = false */
/*MT6163*/        IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_RESET_RESET );       /* DDCCtrl_ResetDig */
/*MT6163*/        IMM_OFFCHIP_BSI_CFG( BSI_SWITCH_TD );                    /* Set off-chip BSI switch owner to be TD */
/*MT6163*/
/*MT6163*/        L1D_VRF18SETTING( 0 );                                   /* Disable AVDD18_HF */
/*MT6163*/        L1D_VRF28SETTING( 0 );                                   /* Disable AVDD28_HF (controlled by PMIC) */
/*MT6163*/     }
/*MT6163*/
/*MT6163*/     IMM_MODE_END();                                             /* Turn Immediate Mode off */
/*MT6163*/
/*MT6163*/     L1D_RF_TXPC_CL_AUXADC_POWEROFF();
/*MT6163*/  }
/*MT6163*/
/*MT6163*/  void  L1D_RF_WindowOn( void )
/*MT6163*/  {  }
/*MT6163*/
/*MT6163*/  void  L1D_RF_WindowOff( void )
/*MT6163*/  {  }
/*MT6163*/
/*MT6163*/  void L1D_RF_BASEBAND_FILTER_CAL( void )
/*MT6163*/  {
/*MT6163*/     unsigned long lpfcap_readback = 0;
/*MT6163*/     unsigned long filter_cal_start;
/*MT6163*/     unsigned long filter_cal_current;
/*MT6163*/     unsigned long filter_cal_duration;
/*MT6163*/
/*MT6163*/     IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_LDOCTR_RXFLTCAL );               /* enable digital LDO and RX LDO */
/*MT6163*/     WAIT_TIME_QB( 55 );                                                  /* 50us, Wait T_LDO */
/*MT6163*/     IMM_SEND_BSI( SCTRL_IMOD(0,30), RX_RCCAL_LPFCAL );                   /* start the calibration */
/*MT6163*/     WAIT_TIME_QB( 40 );                                                  /* 40us, (40+5)QB, Wait T_LPFCal*/
/*MT6163*/
/*MT6163*/     filter_cal_start = ust_get_current_time();
/*MT6163*/     while( (lpfcap_readback&(0x1<<9))==0 || lpfcap_readback==0xAAAAA )   /* Wait unitl LPF_CAL_DONE flag is set to 1 */
/*MT6163*/     {
/*MT6163*/        WAIT_TIME_QB( 5 );
/*MT6163*/        IMM_RECEIVE_BSI( SCTRL_IMOD(0,10), 0x84, SCTRL_IMOD(0,20), &lpfcap_readback );
/*MT6163*/        filter_cal_current = ust_get_current_time();
/*MT6163*/        filter_cal_duration = (filter_cal_current>=filter_cal_start) ? (filter_cal_current-filter_cal_start) : (filter_cal_current+USCNT_WRAP-filter_cal_start);
/*MT6163*/        if( filter_cal_duration>120 )
/*MT6163*/        {
/*MT6163*/ #if IS_CHIP_MT6583_MD2
/*MT6163*/           filter_cal_fail = 0; // temp solution for K2 bring up on MT6589 MD2
/*MT6163*/ #else
/*MT6163*/           filter_cal_fail = 1;
/*MT6163*/ #endif
/*MT6163*/           break;
/*MT6163*/        }
/*MT6163*/     }
/*MT6163*/
/*MT6163*/     l1d_rf2.lpfcap = (char)( (lpfcap_readback>>10) & 0x1F );
/*MT6163*/     IMM_SEND_BSI( SCTRL_IMOD(0,30), DDC_LDOCTR_RXFLTCAL_OFF );     /* turn off RX LDO */
/*MT6163*/  }
/*MT6163*/
/*MT6163*/  void L1D_RF_Switch_SPI_Control_to_3G( void )
/*MT6163*/  {  }
/*MT6163*/
#endif

#if IS_RF_MT6280RF
/*MT6280RF*/
/*MT6280RF*/ #include "intrCtrl.h"
/*MT6280RF*/
/*MT6280RF*/ #define CAL_BAND_NUM     4
/*MT6280RF*/ #define RF_POR_NUM       (sizeof(SDATA_TABLE) /sizeof(unsigned long))
/*MT6280RF*/ #define MAX_RETRY_TIMES  5            // for TX gain step cal. unstable issue SW workaround
/*MT6280RF*/
/*MT6280RF*/ #define RXIF_RCK_MASK    0x0000003FL  //  6 bits length
/*MT6280RF*/ #define DCO_DAC_MASK     0x0000003FL  //  6 bits length
/*MT6280RF*/ #define CALR_CONST_MASK  0x0000001FL  //  5 bits length
/*MT6280RF*/ #define GAIN_MEAS_MASK   0x00000FFFL  // 12 bits length
/*MT6280RF*/ #define ADC_COEF_MASK    0x000000FFL  //  8 bits length
/*MT6280RF*/
/*MT6280RF*/ /* CW1 : Mode */
/*MT6280RF*/ #define SLEEP_MODE       (0x0<<16)
/*MT6280RF*/ #define RXCAL_MODE_2G    (0x1<<16)
/*MT6280RF*/ #define RXBURST_MODE_2G  (0x2<<16)
/*MT6280RF*/ #define TXCAL_MODE_2G    (0x3<<16)
/*MT6280RF*/ #define TXBURST_MODE_2G  (0x4<<16)
/*MT6280RF*/ #define RXCAL_MODE_3G    (0x5<<16)
/*MT6280RF*/ #define RXSLEEP_MODE_3G  (0x8<<16)
/*MT6280RF*/ #define RXDUMP_SLEEP_3G  (0xE<<16)
/*MT6280RF*/ #define RXDUMP_3G        (0xF<<16)
/*MT6280RF*/
/*MT6280RF*/ #define POR_CW1          0x00100200L /* only set DYN_EN=1 */
/*MT6280RF*/
/*MT6280RF*/ /* Set CW default power on value include addr */
/*MT6280RF*/ /* POR default value */
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/ #define POR_CW91         0x05B0003FL
/*MT6280RF*/ #define POR_CW58         0x03A003F7L
/*MT6280RF*/ #define POR_CW73         0x04961802L
/*MT6280RF*/ #define POR_CW157        0x09D01802L
/*MT6280RF*/ #define POR_CW186        0x0BA0007BL
/*MT6280RF*/ #define POR_CW215        0x0D739228L
/*MT6280RF*/ #define POR_CW14         0x00E015C0L /* ADC Loop Filter */
/*MT6280RF*/ #define POR_CW226        0x0E202FB0L
/*MT6280RF*/ #define POR_CW133        0x085116D1L
/*MT6280RF*/ #define POR_CW27         0x01B1B8AFL
/*MT6280RF*/ #define POR_CW98         0x06200000L
/*MT6280RF*/ #define POR_CW43         0x02B32070L /* ori:0x02B2D040L */
/*MT6280RF*/ #define POR_CW44         0x02C04010L /* ori:0x02C04010L */
/*MT6280RF*/ #define POR_CW45         0x02D11000L
/*MT6280RF*/ #define POR_CW46         0x02E03232L /* ori:0x02E02D2DL */
/*MT6280RF*/ #define POR_CW47         0x02F00000L
/*MT6280RF*/ #define POR_CW175        0x0AF55540L
/*MT6280RF*/ #define POR_CW177        0x0B110800L
/*MT6280RF*/ #define POR_CW178        0x0B210000L
/*MT6280RF*/ #define POR_CW179        0x0B3137F4L
/*MT6280RF*/ #define POR_CW180        0x0B4098ADL
/*MT6280RF*/ #define POR_CW184        0x0B81316AL
/*MT6280RF*/ #define POR_CW13         0x00D02100L
/*MT6280RF*/ #define POR_CW160        0x0A000000L /* RX RC Value */
/*MT6280RF*/ #define POR_CW145        0x09119005L
/*MT6280RF*/ #define POR_CW52         0x0340009BL
/*MT6280RF*/ #define POR_CW53         0x0350013BL
/*MT6280RF*/ #define POR_CW230        0x0E60117FL
/*MT6280RF*/ #define POR_CW154        0x09A318C0L
/*MT6280RF*/ #define POR_CW60         0x03C00C1FL
/*MT6280RF*/ #define POR_CW17         0x01133310L
/*MT6280RF*/ #define POR_CW171        0x0AB01236L
/*MT6280RF*/ #define POR_CW172        0x0AC00012L
/*MT6280RF*/ #define POR_CW173        0x0AD0B000L /* ADC Loop Filter */
/*MT6280RF*/ #define POR_CW222        0x0DECCDFAL
/*MT6280RF*/ #define POR_CW231        0x0E702D70L
/*MT6280RF*/ #define POR_CW232        0x0E839DCFL
/*MT6280RF*/ #define POR_CW233        0x0E97B98AL
/*MT6280RF*/ #define POR_CW234        0x0EA41C00L
/*MT6280RF*/ #define POR_CW235        0x0EB00000L
/*MT6280RF*/ #define POR_CW236        0x0EC00000L
/*MT6280RF*/ #define POR_CW227        0x0E362E10L
/*MT6280RF*/ #define POR_CW228        0x0E442CC1L
/*MT6280RF*/ #define POR_CW146        0x092F59AFL
/*MT6280RF*/ #define POR_CW223        0x0DF00044L
/*MT6280RF*/ #define POR_CW237        0x0EDA801CL
/*MT6280RF*/ #define POR_CW167        0x0A700061L
/*MT6280RF*/ #define POR_CW183        0x0B700002L
/*MT6280RF*/ #define POR_CW32         0x02000026L
/*MT6280RF*/ #define POR_CW117        0x0750246CL
/*MT6280RF*/ #define POR_CW176        0x0B015440L
/*MT6280RF*/ #define POR_CW54         0x03600145L
/*MT6280RF*/ #define POR_CW55         0x03700465L
/*MT6280RF*/ #define POR_CW56         0x03800460L
/*MT6280RF*/ #define POR_CW24         0x0180F000L
/*MT6280RF*/ #define POR_CW21         0x0152D880L /* ADC Loop Filter */
/*MT6280RF*/ #define POR_CW79         0x04F001FBL
/*MT6280RF*/ #else
/*MT6280RF*/ #define POR_CW157        0x09D01802L
/*MT6280RF*/ #define POR_CW23         0x01700080L
/*MT6280RF*/ #define POR_CW146        0x092F59ABL
/*MT6280RF*/ #define POR_CW222        0x0DEECDF2L
/*MT6280RF*/ #define POR_CW230        0x0E645148L
/*MT6280RF*/ #define POR_CW91         0x05B0003FL
/*MT6280RF*/ #define POR_CW154        0x09A318C0L
/*MT6280RF*/ #define POR_CW43         0x02B32070L
/*MT6280RF*/ #define POR_CW44         0x02C04010L
/*MT6280RF*/ #define POR_CW46         0x02E03232L
/*MT6280RF*/ #define POR_CW56         0x03803C60L
/*MT6280RF*/ #define POR_CW14         0x00E015C0L /* ADC Loop Filter */
/*MT6280RF*/ #define POR_CW160        0x0A000400L /* RX RC Value */
/*MT6280RF*/ #define POR_CW173        0x0AD0B000L /* ADC Loop Filter */
/*MT6280RF*/ #define POR_CW45         0x02D11000L /* TX Gain Step Cal. */
/*MT6280RF*/ #define POR_CW21         0x01535880L /* ADC Loop Filter */
/*MT6280RF*/ #define POR_CW248        0x0F8FFFE3L /* control conflict on RG_DCXO32K_SEL */
/*MT6280RF*/ #define POR_CW166        0x0A600000L
/*MT6280RF*/ #define POR_CW167        0x0A7C0061L
/*MT6280RF*/ #define POR_CW227        0x0E37BC10L
/*MT6280RF*/ #define POR_CW228        0x0E462CC1L
/*MT6280RF*/ #define POR_CW229        0x0E5E2010L
/*MT6280RF*/ #define POR_CW232        0x0E839DCEL
/*MT6280RF*/ #define POR_CW233        0x0E96AD28L
/*MT6280RF*/ #define POR_CW234        0x0EA29400L
/*MT6280RF*/ #define POR_CW235        0x0EB25248L
/*MT6280RF*/ #define POR_CW236        0x0EC49200L
/*MT6280RF*/ #define POR_CW61         0x03DA0006L
/*MT6280RF*/ #define POR_CW85         0x0550087CL
/*MT6280RF*/ #define POR_CW82         0x05241EC5L
/*MT6280RF*/ #define POR_CW32         0x0200002EL
/*MT6280RF*/ #define POR_CW73         0x04961801L
/*MT6280RF*/ #define POR_CW181        0x0B500004L
/*MT6280RF*/ #define POR_CW79         0x04F001FBL
/*MT6280RF*/ #endif
/*MT6280RF*/
/*MT6280RF*/ #if IS_ANALOG_RXIQ_DEBUG_MODE_ON
/*MT6280RF*/ #define RXIQ_DEBUG_CW21  0x0152DA80L
/*MT6280RF*/ #define RXIQ_DEBUG_CW6   0x00600493L
/*MT6280RF*/ #define RXIQ_DEBUG_CW245 0x0F580004L
/*MT6280RF*/    #if IS_INJECT_SIGNAL2ADC_DEBUG_MODE_ON
/*MT6280RF*/ #define RXIQ_DEBUG_CW59  0x03BC0055L
/*MT6280RF*/    #else
/*MT6280RF*/ #define POR_CW59         0x03B00055L
/*MT6280RF*/    #endif
/*MT6280RF*/ #endif
/*MT6280RF*/
/*MT6280RF*/ /* RCAL */
/*MT6280RF*/ #define POR_CW135        0x08742000L
/*MT6280RF*/
/*MT6280RF*/ /* RX RC Value & RX DCOC */
/*MT6280RF*/ #define POR_CW50         0x03200000L
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/ #define POR_CW22         0x01600020L
/*MT6280RF*/ #else
/*MT6280RF*/ #define POR_CW22         0x01620020L
/*MT6280RF*/ #endif
/*MT6280RF*/ #define POR_CW72         0x04800FFFL
/*MT6280RF*/ #define POR_CW112        0x07000000L
/*MT6280RF*/
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/ const unsigned long SDATA_TABLE[]=
/*MT6280RF*/ {
/*MT6280RF*/    POR_CW91,    /* CW91  : Set default TCL range to 'd63 */
/*MT6280RF*/    POR_CW58,    /* CW58  : Disable the RXADC test output which is default  on.  */
/*MT6280RF*/    POR_CW73,    /* CW73  : Bump up TDC LDO voltage */
/*MT6280RF*/    POR_CW157,   /* CW157 : set RXD_POW_STG1/2 required for diversity path use, RXD_TTG_BIAS for better I/Q imbalance correction */
/*MT6280RF*/    POR_CW186,   /* CW186 : keep clk of RX section of GS always on. Required for RX 3G bursts. */
/*MT6280RF*/    POR_CW215,   /* CW215 : this is the buf_close_delay_cnt value and needs to be reduced to support burst reconfigurations */
/*MT6280RF*/    POR_CW14,    /* CW14  : release RX LDO manual mode (wrong default) */
/*MT6280RF*/    POR_CW226,   /* CW226 : Disable PFD during sub band cal (work around) */
/*MT6280RF*/    POR_CW133,   /* CW133 : Change RXIF Default bias currents */
/*MT6280RF*/    POR_CW27,    /* CW27  : Change t27  to 175us & t26 to 110us */
/*MT6280RF*/    POR_CW98,    /* CW98  : Disable NOFFSET compensation as it's not necessary */
/*MT6280RF*/    POR_CW43,    /* CW43  : TX: No information */
/*MT6280RF*/    POR_CW44,    /* CW44  : TX: Configure Power Det. */
/*MT6280RF*/    POR_CW45,    /* CW45  : TX: Configure Power Det. */
/*MT6280RF*/    POR_CW46,    /* CW46  : TX: Configure Power Det. */
/*MT6280RF*/    POR_CW47,    /* CW47  : TX: Configure Power Det. */
/*MT6280RF*/    POR_CW175,   /* CW175 : TX: 3G TXIQ Cal Gain */
/*MT6280RF*/    POR_CW177,   /* CW177 : TX: No information */
/*MT6280RF*/    POR_CW178,   /* CW178 : TX: No information */
/*MT6280RF*/    POR_CW179,   /* CW179 : TX: No information */
/*MT6280RF*/    POR_CW180,   /* CW180 : TX: 3G TXIQ Cal Gain */
/*MT6280RF*/    POR_CW184,   /* CW184 : TX: 3G TXIQ Cal Gain */
/*MT6280RF*/    POR_CW13,    /* CW13  : RX_LNA_GAIN_M = 000 (req¡¦ed for DCOC) */
/*MT6280RF*/    POR_CW160,   /* CW160 : RXD_LNA_GAIN_M = 000 (req¡¦ed for DCOC) */
/*MT6280RF*/    POR_CW145,   /* CW145 : TX timer change for T80 (5us) */
/*MT6280RF*/    POR_CW52,    /* CW52  : TX Timer change for T29 (155us) */
/*MT6280RF*/    POR_CW53,    /* CW53  : TX Timer chnage for T30 (325us) */
/*MT6280RF*/    POR_CW58 ,   /* CW58  : bring up the LDO supply (ADC LDO in test mode by POR) */
/*MT6280RF*/    POR_CW230,   /* CW230 : workaround for 3G SRX lock */
/*MT6280RF*/    POR_CW154,   /* CW154 : RxD LNA bias settings */
/*MT6280RF*/    POR_CW60,    /* CW60  : ADC clock edge */
/*MT6280RF*/    POR_CW17,    /* CW17  : Rx LNA bias settings */
/*MT6280RF*/    POR_CW171,   /* CW171 : ADC filter coefficient target count */
/*MT6280RF*/    POR_CW172,   /* CW172 : ADC filter coefficient target count */
/*MT6280RF*/    POR_CW173,   /* CW173 : ADC filter coefficient target count */
/*MT6280RF*/    POR_CW222,   /* CW222 : SRX: VCO Trimming: VCO_LDO_VS=5 */
/*MT6280RF*/    POR_CW231,   /* CW231 : SRX: VCO Trimming: VCO_Vbias=5 */
/*MT6280RF*/    POR_CW232,   /* CW232 : SRX: VCO Trimming */
/*MT6280RF*/    POR_CW233,   /* CW233 : SRX: VCO Trimming */
/*MT6280RF*/    POR_CW234,   /* CW234 : SRX: VCO Trimming */
/*MT6280RF*/    POR_CW235,   /* CW235 : SRX: VCO Trimming: NegGm LUT, all =0 */
/*MT6280RF*/    POR_CW236,   /* CW236 : SRX: VCO Trimming */
/*MT6280RF*/    POR_CW227,   /* CW227 : SRX: PLL BW & CP optimization */
/*MT6280RF*/    POR_CW228,   /* CW228 : SRX: PLL BW & CP optimization */
/*MT6280RF*/    POR_CW146,   /* CW146 : RC cal update trim */
/*MT6280RF*/    POR_CW223,   /* CW223 : SRX: SBCAL measure time */
/*MT6280RF*/    POR_CW237,   /* CW237 : SRX: freq doubler settings */
/*MT6280RF*/    POR_CW167,   /* CW167 : ADC default settings, enables OVLD detection & sets correct ADC input resistor values */
/*MT6280RF*/    POR_CW183,   /* CW183 : RX_TTG_BIAS for better I/Q imbalance correction */
/*MT6280RF*/    POR_CW34,    /* CW34  : [D15:D14]=111, TXIF LDO voltage, it will be fixed in ES2 */
/*MT6280RF*/    POR_CW32,    /* CW32  : [D2:D0]=110, TX_TXDIVLDO_VS, MOD linearity */
/*MT6280RF*/    POR_CW35,    /* CW35  : Highband = 00400 :  Lowband = 00000 (Mod Swing) */
/*MT6280RF*/    POR_CW117,   /* CW117 : [D7:D5]=011, D[4:1]=0000, It is not finalzed it. Will update it later after H/L/N temperature measurement. */
/*MT6280RF*/    POR_CW176,   /* CW176 : TX: 3G TXIQ Cal Gain, Change the length of TXIQ cal. */
/*MT6280RF*/    POR_CW54,    /* CW54  : TX Timer change for TTG SW workaround */
/*MT6280RF*/    POR_CW55,    /* CW55  : TX Timer change for TTG SW workaround */
/*MT6280RF*/    POR_CW56,    /* CW56  : TX Timer change for TTG SW workaround */
/*MT6280RF*/    POR_CW24,    /* CW24  : Disable RC-cal in 2G RX cal sequence */
/*MT6280RF*/    POR_CW79,    /* CW79  : STX_DEM_Chunk[6:0] to 1111_1110 prevent overflow during settling */
/*MT6280RF*/ }; /* does not change CW251[D19] which is for xmode latch */
/*MT6280RF*/ #else
/*MT6280RF*/ const unsigned long SDATA_TABLE[]=
/*MT6280RF*/ {
/*MT6280RF*/    POR_CW248,   /* CW248 : DCXO_XO_LPM_PREBUF_ISEL[1:0]=CW248[6:5]=2'b11 */
/*MT6280RF*/    POR_CW157,   /* CW157 : "set RXD_POW_STG1/2 required for diversity path use RXD_TTG_BIAS for better I/Q imbalance correction" */
/*MT6280RF*/    POR_CW23,    /* CW23  : set RXDFE_RCK_M to mid-scale. Not strictly required if RCK manual mode not used */
/*MT6280RF*/    POR_CW146,   /* CW146 : optimum ABB filter TF (default changed on ES1 under impact of ADC STF, unfortunately got replicated in HW) */
/*MT6280RF*/    POR_CW222,   /* CW222 : set DIGITAL_CLK_FREEZE to 0, LDO_FB +100mV */
/*MT6280RF*/    POR_CW230,   /* CW230 : TCL defaults (center values) */
/*MT6280RF*/    POR_CW91,    /* CW91  :  Set the TCL_RANGE default  */
/*MT6280RF*/    POR_CW154,   /* CW154 : Set the RXD CUR default */
/*MT6280RF*/    POR_CW32,    /* CW32  : [D2:D0]=110, TX_TXDIVLDO_VS, MOD linearity */
/*MT6280RF*/    POR_CW35,    /* CW35  : Set a constant value for Mod Swing is OK (removed from PG) */
/*MT6280RF*/    POR_CW44,    /* CW44  : b[19:10]=16 (GAINRAMP_T3); b[9:0] =16  (GAINRAMP_T2)  */
/*MT6280RF*/    POR_CW46,    /* CW46  : b[15:8] =50 (DETMEAS_T3) ; b[7:0] =50  (DETMEAS_T2)   */
/*MT6280RF*/    POR_CW56,    /* CW56  : For temperature measurement setting time */
/*MT6280RF*/    POR_CW21,    /* CW21  : Changed RXIF VCM setting to correct value "10" */
/*MT6280RF*/    POR_CW166,   /* CW166 : Disable ADC overload management */
/*MT6280RF*/    POR_CW167,   /* CW167 : cic_ovld_en=0; Disable ADC overlaod management in CIC filter */
/*MT6280RF*/    POR_CW227,   /* CW227 : ICP 3G 111100 / ICPoff=1 */
/*MT6280RF*/    POR_CW228,   /* CW228 : PCP 3G 101100/ PCPoff=1 */
/*MT6280RF*/    POR_CW229,   /* CW229 : SRX LPF configuration (C6 lighter) */
/*MT6280RF*/    POR_CW232,   /* CW232 : Vbdet LUT. From VCO Characaterization 9-21 */
/*MT6280RF*/    POR_CW233,   /* CW233 : Vbdet LUT. From VCO Characaterization 9-21 */
/*MT6280RF*/    POR_CW234,   /* CW234 : Vbdet LUT. From VCO Characaterization 9-21 */
/*MT6280RF*/    POR_CW235,   /* CW235 : NegGm LUT. From VCO Characaterization 9-21 */
/*MT6280RF*/    POR_CW236,   /* CW236 : NegGm LUT. From VCO Characaterization 9-21 */
/*MT6280RF*/    POR_CW61,    /* CW61  : Improve Phase error on outlier parts by increasing bias current */
/*MT6280RF*/    POR_CW85,    /* CW85  : Improve peak phase error in 2G HB */
/*MT6280RF*/    POR_CW82,    /* CW82  : Improve peak phase error in 2G HB */
/*MT6280RF*/    POR_CW73,    /* CW73  : Improve 400KHz spur */
/*MT6280RF*/    POR_CW181,   /* CW181 : set the LDO settle time to 5us for more margin */
/*MT6280RF*/    POR_CW79,    /* CW79  : STX_DEM_Chunk[6:0] to 1111_1110 prevent overflow during settling */
/*MT6280RF*/ }; /* does not change CW251[D19] which is for xmode latch */
/*MT6280RF*/ #endif
/*MT6280RF*/
/*MT6280RF*/ const int MIDBAND_ARFCN[4]=
/*MT6280RF*/ {
/*MT6280RF*/    189, /* approx. mid Band arfcn of GSM850  */
/*MT6280RF*/     37, /* approx. mid Band arfcn of GSM900  */
/*MT6280RF*/    698, /* approx. mid Band arfcn of DCS1800 */
/*MT6280RF*/    661, /* approx. mid Band arfcn of PCS1900 */
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ const unsigned long  RX_LNA_BAND_SEL[4]=
/*MT6280RF*/ {  /* RX LNA & Band Selection */
/*MT6280RF*/    (GSM850_PATH_SEL<<12)|0x0,  /* GSM  850, LNA4 */
/*MT6280RF*/    (   GSM_PATH_SEL<<12)|0x1,  /* GSM  900, LNA2 */
/*MT6280RF*/    (   DCS_PATH_SEL<<12)|0x2,  /* DCS 1800, LNA1 */
/*MT6280RF*/    (   PCS_PATH_SEL<<12)|0x3,  /* PCS 1900, LNA3 */
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/ const unsigned long TXGAINSTEP_CAL_CW41_LB_TABLE[14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6280RF*/ {  /*   1st     2nd   */
/*MT6280RF*/    { 0x1C780, 0x1BF80 },
/*MT6280RF*/    { 0x1BF80, 0x1B780 },
/*MT6280RF*/    { 0x1B780, 0x1AF80 },
/*MT6280RF*/    { 0x1AF80, 0x1A780 },
/*MT6280RF*/    { 0x1A780, 0x22700 },
/*MT6280RF*/    { 0x22700, 0x19F80 },
/*MT6280RF*/    { 0x19F80, 0x19780 },
/*MT6280RF*/    { 0x19780, 0x42180 },
/*MT6280RF*/    { 0x42180, 0x41180 },
/*MT6280RF*/    { 0x41180, 0x49080 },
/*MT6280RF*/    { 0x49080, 0x48880 },
/*MT6280RF*/    { 0x48880, 0xC8004 },
/*MT6280RF*/    { 0xC8004, 0xC8044 },
/*MT6280RF*/    { 0xC8044, 0xC8064 },
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ const unsigned long TXGAINSTEP_CAL_CW36_LB_TABLE[14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6280RF*/ {  /*   1st     2nd   */
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },
/*MT6280RF*/ };
/*MT6280RF*/ #else
/*MT6280RF*/ const unsigned long TXGAINSTEP_CAL_CW41_LB_TABLE[14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6280RF*/ {  /*   1st     2nd   */
/*MT6280RF*/    { 0x04780, 0x23F80 },
/*MT6280RF*/    { 0x23F80, 0x23780 },
/*MT6280RF*/    { 0x23780, 0x22F80 },
/*MT6280RF*/    { 0x22F80, 0x22780 },
/*MT6280RF*/    { 0x22780, 0x2A700 },
/*MT6280RF*/    { 0x2A700, 0x21F80 },
/*MT6280RF*/    { 0x21F80, 0x21780 },
/*MT6280RF*/    { 0x21780, 0x4A180 },
/*MT6280RF*/    { 0x4A180, 0x49180 },
/*MT6280RF*/    { 0x49180, 0x51080 },
/*MT6280RF*/    { 0x51080, 0x50880 },
/*MT6280RF*/    { 0x50880, 0xD0004 },
/*MT6280RF*/    { 0xD0004, 0xD0044 },
/*MT6280RF*/    { 0xD0044, 0xD0064 },
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ const unsigned long TXGAINSTEP_CAL_CW36_LB_TABLE[14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6280RF*/ {  /*   1st     2nd   */
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },
/*MT6280RF*/    { 0x069AF, 0x069AF },
/*MT6280RF*/    { 0x069AF, 0x069AF },
/*MT6280RF*/ };
/*MT6280RF*/ #endif
/*MT6280RF*/
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/ const unsigned long TXGAINSTEP_CAL_CW42_HB_TABLE[14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6280RF*/ {  /*   1st     2nd   */
/*MT6280RF*/    { 0x40520, 0x40520 },
/*MT6280RF*/    { 0x43560, 0x43560 },
/*MT6280RF*/    { 0x465A0, 0x465A0 },
/*MT6280RF*/    { 0x495E0, 0x495E0 },
/*MT6280RF*/    { 0x4C620, 0x4C620 },
/*MT6280RF*/    { 0x43560, 0x43560 },
/*MT6280RF*/    { 0x465A0, 0x465A0 },
/*MT6280RF*/    { 0x495E0, 0x495E0 },
/*MT6280RF*/    { 0x4C620, 0x4C620 },
/*MT6280RF*/    { 0x52500, 0x52500 },
/*MT6280RF*/    { 0x55540, 0x55540 },
/*MT6280RF*/    { 0x58580, 0x5858F },
/*MT6280RF*/    { 0x9E48F, 0x9E488 },
/*MT6280RF*/    { 0x9F4C8, 0x9F4C4 },
/*MT6280RF*/ };
/*MT6280RF*/ #else
/*MT6280RF*/ const unsigned long TXGAINSTEP_CAL_CW42_HB_TABLE[14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6280RF*/ {  /*   1st     2nd   */
/*MT6280RF*/    { 0x40520, 0x40520 },
/*MT6280RF*/    { 0x43560, 0x43560 },
/*MT6280RF*/    { 0x465A0, 0x465A0 },
/*MT6280RF*/    { 0x495E0, 0x495E0 },
/*MT6280RF*/    { 0x4C620, 0x4C620 },
/*MT6280RF*/    { 0x43560, 0x43560 },
/*MT6280RF*/    { 0x465A0, 0x465A0 },
/*MT6280RF*/    { 0x495E0, 0x495E0 },
/*MT6280RF*/    { 0x4C620, 0x4C620 },
/*MT6280RF*/    { 0x52500, 0x52500 },
/*MT6280RF*/    { 0x55540, 0x55540 },
/*MT6280RF*/    { 0x58580, 0x5858F },
/*MT6280RF*/    { 0x9E48F, 0x9E488 },
/*MT6280RF*/    { 0x9F4C8, 0x9F4C4 },
/*MT6280RF*/ };
/*MT6280RF*/ #endif
/*MT6280RF*/
/*MT6280RF*/ const unsigned long TXGAINSTEP_CAL_CW42_LB_TABLE[][14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6280RF*/ {  /*   1st     2nd   */
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/   {{ 0x40520, 0x40520 },
/*MT6280RF*/    { 0x43560, 0x43560 },
/*MT6280RF*/    { 0x465A0, 0x465A0 },
/*MT6280RF*/    { 0x495E0, 0x495E0 },
/*MT6280RF*/    { 0x4C620, 0x4C620 },
/*MT6280RF*/    { 0x43560, 0x43560 },
/*MT6280RF*/    { 0x465A0, 0x465A0 },
/*MT6280RF*/    { 0x495E0, 0x495E0 },
/*MT6280RF*/    { 0x4C620, 0x4C620 },
/*MT6280RF*/    { 0x52500, 0x52500 },
/*MT6280RF*/    { 0x55540, 0x55540 },
/*MT6280RF*/    { 0x58580, 0x5858F },
/*MT6280RF*/    { 0x9E48F, 0x9E488 },
/*MT6280RF*/    { 0x9F4C8, 0x9F4C4 },},
/*MT6280RF*/ #else
/*MT6280RF*/   {{ 0x40520, 0x40520 },
/*MT6280RF*/    { 0x43560, 0x43560 },
/*MT6280RF*/    { 0x465A0, 0x465A0 },
/*MT6280RF*/    { 0x495E0, 0x495E0 },
/*MT6280RF*/    { 0x4C620, 0x4C620 },
/*MT6280RF*/    { 0x43560, 0x43560 },
/*MT6280RF*/    { 0x465A0, 0x465A0 },
/*MT6280RF*/    { 0x495E0, 0x495E0 },
/*MT6280RF*/    { 0x4C620, 0x4C620 },
/*MT6280RF*/    { 0x52500, 0x52500 },
/*MT6280RF*/    { 0x55540, 0x55540 },
/*MT6280RF*/    { 0x58580, 0x5858F },
/*MT6280RF*/    { 0xA450F, 0xA4508 },
/*MT6280RF*/    { 0xA4508, 0xA4504 },},
/*MT6280RF*/   {{ 0x40520, 0x40520 },
/*MT6280RF*/    { 0x43560, 0x43560 },
/*MT6280RF*/    { 0x465A0, 0x465A0 },
/*MT6280RF*/    { 0x495E0, 0x495E0 },
/*MT6280RF*/    { 0x4C620, 0x4C620 },
/*MT6280RF*/    { 0x43560, 0x43560 },
/*MT6280RF*/    { 0x465A0, 0x465A0 },
/*MT6280RF*/    { 0x495E0, 0x495E0 },
/*MT6280RF*/    { 0x4C620, 0x4C620 },
/*MT6280RF*/    { 0x52500, 0x52500 },
/*MT6280RF*/    { 0x55540, 0x55540 },
/*MT6280RF*/    { 0x58580, 0x5858F },
/*MT6280RF*/    { 0x9F50F, 0x9F508 },
/*MT6280RF*/    { 0x9F508, 0x9F504 },},
/*MT6280RF*/ #endif
/*MT6280RF*/ };
/*MT6280RF*/ const unsigned long TXGAINSTEP_CAL_CW41_HB_TABLE[][14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6280RF*/ {  /*   1st     2nd   */
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/   {{ 0x04780, 0x03F80 },
/*MT6280RF*/    { 0x03F80, 0x03780 },
/*MT6280RF*/    { 0x03780, 0x02F80 },
/*MT6280RF*/    { 0x02F80, 0x02780 },
/*MT6280RF*/    { 0x02780, 0x2BB80 },
/*MT6280RF*/    { 0x2BB80, 0x2B380 },
/*MT6280RF*/    { 0x2B380, 0x2A380 },
/*MT6280RF*/    { 0x2A380, 0x32180 },
/*MT6280RF*/    { 0x32180, 0x31180 },
/*MT6280RF*/    { 0x31180, 0x39080 },
/*MT6280RF*/    { 0x39080, 0x38880 },
/*MT6280RF*/    { 0x38880, 0xB8004 },
/*MT6280RF*/    { 0xB8004, 0xB8044 },
/*MT6280RF*/    { 0xB8044, 0xB8064 },},
/*MT6280RF*/ #else
/*MT6280RF*/   {{ 0x0C780, 0x0BF80 },
/*MT6280RF*/    { 0x0BF80, 0x0B780 },
/*MT6280RF*/    { 0x0B780, 0x0AF80 },
/*MT6280RF*/    { 0x0AF80, 0x0A780 },
/*MT6280RF*/    { 0x0A780, 0x33B80 },
/*MT6280RF*/    { 0x33B80, 0x33380 },
/*MT6280RF*/    { 0x33380, 0x32380 },
/*MT6280RF*/    { 0x32380, 0x3A180 },
/*MT6280RF*/    { 0x3A180, 0x39180 },
/*MT6280RF*/    { 0x39180, 0x41080 },
/*MT6280RF*/    { 0x41080, 0x40880 },
/*MT6280RF*/    { 0x40880, 0xC0004 },
/*MT6280RF*/    { 0xC0004, 0xC0044 },
/*MT6280RF*/    { 0xC0044, 0xC0064 },},
/*MT6280RF*/   {{ 0x1C780, 0x33F80 },
/*MT6280RF*/    { 0x33F80, 0x33780 },
/*MT6280RF*/    { 0x33780, 0x32F80 },
/*MT6280RF*/    { 0x32F80, 0x32780 },
/*MT6280RF*/    { 0x32780, 0x4BB80 },
/*MT6280RF*/    { 0x4BB80, 0x4B380 },
/*MT6280RF*/    { 0x4B380, 0x4A380 },
/*MT6280RF*/    { 0x4A380, 0x52180 },
/*MT6280RF*/    { 0x52180, 0x51180 },
/*MT6280RF*/    { 0x51180, 0x59080 },
/*MT6280RF*/    { 0x59080, 0x58880 },
/*MT6280RF*/    { 0x58880, 0xD8004 },
/*MT6280RF*/    { 0xD8004, 0xD8044 },
/*MT6280RF*/    { 0xD8044, 0xD8064 },},
/*MT6280RF*/ #endif
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ const unsigned long TXGAINSTEP_CAL_CW36_HB_TABLE[][14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6280RF*/ {  /*   1st     2nd   */
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/   {{ 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },},
/*MT6280RF*/ #else
/*MT6280RF*/   {{ 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },},
/*MT6280RF*/   {{ 0x1E9AF, 0x1E9AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x169AF, 0x169AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },
/*MT6280RF*/    { 0x0E9AF, 0x0E9AF },
/*MT6280RF*/    { 0x069AF, 0x069AF },
/*MT6280RF*/    { 0x069AF, 0x069AF },
/*MT6280RF*/    { 0x069AF, 0x069AF },},
/*MT6280RF*/ #endif
/*MT6280RF*/ };
/*MT6280RF*/
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/ const signed short GBB1_LB    [14] = {  -58,  -58,  -58,  -58,  -58,  -80,  -58,  -58, -193,  -193,  -230,  -230,  -230,  -230 };
/*MT6280RF*/ #else
/*MT6280RF*/ const signed short GBB1_LB    [14] = {    0,  -80,  -80,  -80,  -80, -105,  -80,  -80, -230,  -230,  -273,  -273,  -273,  -273  };
/*MT6280RF*/ #endif
/*MT6280RF*/ const signed short GBB1_HB  [][14] = {
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/                                       {    0,    0,    0,    0,    0, -105, -105, -105, -131,  -131,  -160,  -160,  -160,  -160 },
/*MT6280RF*/ #else
/*MT6280RF*/                                       {  -18,  -18,  -18,  -18,  -18, -131, -131, -131, -160,  -160,  -193,  -193,  -193,  -193 },
/*MT6280RF*/                                       {  -58, -131, -131, -131, -131, -230, -230, -230, -273,  -273,  -324,  -324,  -324,  -324 },
/*MT6280RF*/ #endif
/*MT6280RF*/                                      };
/*MT6280RF*/ const signed short GVGARF_LB[][14] = {
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/                                       { -388, -422, -462, -511, -572, -615, -650, -761,  -984, -1176, -1374, -1564, -1760, -1945 },
/*MT6280RF*/ #else
/*MT6280RF*/                                       { -330, -443, -483, -532, -592, -636, -671, -782, -1005, -1197, -1395, -1585, -1780, -1966 },
/*MT6280RF*/                                       { -330, -441, -478, -526, -583, -623, -657, -768,  -973, -1174, -1363, -1544, -1722, -1936 },
/*MT6280RF*/ #endif
/*MT6280RF*/                                      };
/*MT6280RF*/ const signed short GVGARF_HB[][14] = {
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/                                       { -202, -235, -273, -320, -379, -406, -447, -556,  -693,  -884, -1053, -1243, -1429, -1616 },
/*MT6280RF*/ #else
/*MT6280RF*/                                       { -220, -253, -291, -338, -397, -424, -465, -574,  -711,  -902, -1071, -1261, -1447, -1634 },
/*MT6280RF*/                                       { -260, -362, -398, -442, -498, -520, -556, -660,  -804,  -995, -1181, -1373, -1549, -1727 },
/*MT6280RF*/ #endif
/*MT6280RF*/                                      };
/*MT6280RF*/
/*MT6280RF*/ signed short chip_ver;
/*MT6280RF*/
/*MT6280RF*/ extern void L1D_DM_Power_Control_Trace( char is_2g, char is_3g );
/*MT6280RF*/ void  L1D_RF_PowerOn( void )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned short i;
/*MT6280RF*/    unsigned short BSI_num=0;
/*MT6280RF*/    unsigned long  cw0;
/*MT6280RF*/    unsigned long  cw135;
/*MT6280RF*/    unsigned long  cw22 , cw160, cw50;
/*MT6280RF*/    unsigned long  cw169, cw170;
/*MT6280RF*/    unsigned long _savedMask;
/*MT6280RF*/
/*MT6280RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6280RF*/
/*MT6280RF*/    if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6280RF*/    {
/*MT6280RF*/       if( l1d_rf.is_init )
/*MT6280RF*/       {
/*MT6280RF*/          L1D_PMU_VRF18ModeSetting(0);    /* 0: enable with SRCLKEN */ /* Configure VDD_18 to be HW mode     */
/*MT6280RF*/          WAIT_TIME_QB(300);                                           /* Wait 277us for PMIC                */
/*MT6280RF*/          L1D_PMU_VRF18Setting( 1 );                                   /* Enable VDD_18 (controlled by PMIC) */
/*MT6280RF*/          l1d_rf2.is_2g_on = 2;                                        /* Record the PMU step                */
/*MT6280RF*/          L1D_PMU_VRF28Setting( 1 );                                   /* Enable VDD_28 (controlled by PMIC) */
/*MT6280RF*/          l1d_rf2.is_2g_on = 4;                                        /* Record the PMU step                */
/*MT6280RF*/
/*MT6280RF*/          /* POR regardless of init or wake up use the same sequence */
/*MT6280RF*/          SPECIAL_IMM_RECEIVE_BSI( SCTRL_IMOD(0,9), 0x00, SCTRL_IMOD(0,20), &(cw0) );
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x00, 0x80000) );     //CW0 : SOR
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x86, 0x526D1) );     //CW134: D[18:17] Enable PTAT and VBGR current bias
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x03, 0x1B428) );     //CW3  : D[13:12] Enable bandgaps
/*MT6280RF*/          WAIT_TIME_QB(22);                                            //wait 20us
/*MT6280RF*/
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, 0x00211) );     //CW1  : Enable DYN_EN=1
/*MT6280RF*/          WAIT_TIME_QB(120);                                           //wait 110us
/*MT6280RF*/
/*MT6280RF*/          BSI_num = RF_POR_NUM;
/*MT6280RF*/
/*MT6280RF*/          for( i=0 ; i<BSI_num; i++ )
/*MT6280RF*/          {  IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE[i] );
/*MT6280RF*/          }
/*MT6280RF*/
/*MT6280RF*/          l1d_rf2.is_2g_on = 1;                                        /* set 2G flag to notify 2G is ON */
/*MT6280RF*/          L1D_DM_Power_Control_Trace( 1, 2 );                          /* indicate the init state */
/*MT6280RF*/       }
/*MT6280RF*/       else
/*MT6280RF*/       {
/*MT6280RF*/ #if defined(__UMTS_RAT__) && defined ( __UMTS_FDD_MODE__ )
/*MT6280RF*/          extern char UL1D_RF_CheckDMPower( void );                    /* check 3g RF flag */
/*MT6280RF*/ #endif
/*MT6280RF*/          _savedMask = SaveAndSetIRQMask();                            /* disable interrupt */
/*MT6280RF*/
/*MT6280RF*/ #if defined(__UMTS_RAT__) && defined ( __UMTS_FDD_MODE__ )
/*MT6280RF*/          if( UL1D_RF_CheckDMPower() )                                 /* 3G is already ON, so 2G does not do the power-on reset */
/*MT6280RF*/          {
/*MT6280RF*/             l1d_rf2.is_2g_on = 1;                                     /* set 2G flag to notify 2G is ON */
/*MT6280RF*/             L1D_DM_Power_Control_Trace( 1, 1 );                       /* indicate 2G is ON and 3G is ON */
/*MT6280RF*/             RestoreIRQMask(_savedMask);                               /* enable interrupt */
/*MT6280RF*/          }
/*MT6280RF*/          else
/*MT6280RF*/ #endif
/*MT6280RF*/          {
/*MT6280RF*/             l1d_rf2.is_2g_on = 1;                                     /* set 2G flag to notify 2G is ON */
/*MT6280RF*/             L1D_DM_Power_Control_Trace( 1, 0 );                       /* indicate 2G is ON and 3G is OFF */
/*MT6280RF*/             RestoreIRQMask(_savedMask);                               /* enable interrupt */
/*MT6280RF*/             L1D_PMU_VRF18Setting( 1 );                                /* Enable VDD_18 (controlled by PMIC) */
/*MT6280RF*/             l1d_rf2.is_2g_on = 3;                                     /* Record the PMU step                */
/*MT6280RF*/             L1D_PMU_VRF28Setting( 1 );                                /* Enable VDD_28 (controlled by PMIC) */
/*MT6280RF*/             l1d_rf2.is_2g_on = 5;                                     /* Record the PMU step                */
/*MT6280RF*/
/*MT6280RF*/             /* POR regardless of init or wake up use the same sequence */
/*MT6280RF*/             IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x86, 0x526D1) );  //CW134: D[18:17] Enable PTAT and VBGR current bias
/*MT6280RF*/             IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x03, 0x1B428) );  //CW3  : D[13:12] Enable bandgaps
/*MT6280RF*/             WAIT_TIME_QB(22);                                         //wait 20us
/*MT6280RF*/
/*MT6280RF*/             IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, 0x00211) );  //CW1  : Enable DYN_EN=1
/*MT6280RF*/             WAIT_TIME_QB(120);                                        //wait 110us
/*MT6280RF*/
/*MT6280RF*/             BSI_num = RF_POR_NUM;
/*MT6280RF*/
/*MT6280RF*/             for( i=0 ; i<BSI_num; i++ )
/*MT6280RF*/             {  IMM_SEND_BSI( SCTRL_IMOD(0,29), SDATA_TABLE[i] );
/*MT6280RF*/             }
/*MT6280RF*/          }
/*MT6280RF*/       }
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    if( !l1d_rf2.is_wakeup )
/*MT6280RF*/    {  /* Set AFC DAC to corresponding (CW247/CW254) according to (DCXO mode/TCVCXO mode) */
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), ((l1d_rf.AFC_data<<AFC_SHIFT_PART)&AFC_MASK_PART)|(AFC_VALUE_PART) );
/*MT6280RF*/ #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G)
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0xF9, ((XO_CapID&0xFF)<<12)|0x008C6) );  //CW249: Set previous Cap ID value
/*MT6280RF*/ #endif
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    if( l1d_rf.is_init )
/*MT6280RF*/    {  /* Power On Calibration */
/*MT6280RF*/       IMM_RECEIVE_BSI( SCTRL_IMOD(0,9), 0x00, SCTRL_IMOD(0,20), &(cw0) );                   //readback cw0 to check chip version
/*MT6280RF*/       chip_ver = cw0 & 0xFF;
/*MT6280RF*/ #if IS_UESIM_DM_RF_INIT_SUPPORT
/*MT6280RF*/       /* bypass the calibration on UESIM */
/*MT6280RF*/       l1d_rf2.is_power_on_cal |= (RCAL_CAL_DONE|RXRC_DCOC_CAL_DONE|ADC_LF_COEF_CAL_DONE|TXGAIN_STEP_CAL_DONE);
/*MT6280RF*/ #else
/*MT6280RF*/       if( l1d_rf2.power_on_cal_flag&RCAL_CAL_ON )
/*MT6280RF*/       {
/*MT6280RF*/          if( chip_ver == 0x11 || chip_ver == 0x21 )                                         //check chip version E1=0x11 and E2=0x21
/*MT6280RF*/          {
/*MT6280RF*/             L1D_RF_RCAL_Cal();
/*MT6280RF*/          }
/*MT6280RF*/          else                                                                               //E3=0x31 and others, Rcal result read from Efuse
/*MT6280RF*/          {
/*MT6280RF*/             l1d_rf2.calr_const = ( HW_READ(RCAL_EFUSE) == 0 ) ? 13 : HW_READ(RCAL_EFUSE);   //if have no Efuse blown, write mean value 13
/*MT6280RF*/          }
/*MT6280RF*/          l1d_rf2.is_power_on_cal |= RCAL_CAL_DONE;
/*MT6280RF*/       }
/*MT6280RF*/       if( l1d_rf2.power_on_cal_flag&RXRC_DCOC_CAL_ON )
/*MT6280RF*/       {
/*MT6280RF*/          L1D_RF_RXRC_DCO_Cal();
/*MT6280RF*/          l1d_rf2.is_power_on_cal |= RXRC_DCOC_CAL_DONE;
/*MT6280RF*/       }
/*MT6280RF*/       if( l1d_rf2.power_on_cal_flag&ADC_LF_COEF_CAL_ON )
/*MT6280RF*/       {
/*MT6280RF*/          L1D_RF_ADC_LoopFilter_Coef_Cal();
/*MT6280RF*/          l1d_rf2.is_power_on_cal |= ADC_LF_COEF_CAL_DONE;
/*MT6280RF*/       }
/*MT6280RF*/       if( l1d_rf2.power_on_cal_flag&TX_GAINSTEP_CAL_ON )
/*MT6280RF*/       {
/*MT6280RF*/          L1D_RF_TX_GainStep_Cal();
/*MT6280RF*/          l1d_rf2.is_power_on_cal |= TXGAIN_STEP_CAL_DONE;
/*MT6280RF*/       }
/*MT6280RF*/ #endif
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    /* Write back the Calibration value to the register */
/*MT6280RF*/    if( (l1d_rf2.is_power_on_cal)&(RCAL_CAL_DONE) )
/*MT6280RF*/    {  /* Re-write RCAL Value */
/*MT6280RF*/       cw135 = ( POR_CW135&(~(CALR_CONST_MASK)) ) | ( (l1d_rf2.calr_const&CALR_CONST_MASK) );
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x87, cw135) );  //CW135 : CALR_MAN d[19]=1, da_calr_const_final_m[4:0] = CALR_CONST
/*MT6280RF*/    }
/*MT6280RF*/    if( (l1d_rf2.is_power_on_cal)&(RXRC_DCOC_CAL_DONE) )
/*MT6280RF*/    {  /* Re-write RXRC Value */
/*MT6280RF*/       cw22  = ( POR_CW22 &(~(RXIF_RCK_MASK<<0)) ) | ( (l1d_rf2.rxif_rck_m&RXIF_RCK_MASK)<<0 );
/*MT6280RF*/       cw160 = ( POR_CW160&(~(RXIF_RCK_MASK<<5)) ) | ( (l1d_rf2.rxif_rck_m&RXIF_RCK_MASK)<<5 );
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x16, cw22 ) );  //CW22  : RXIF_RCK_M[5:0]
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0xA0, cw160) );  //CW160 : RXDIF_RCK_M[5:0]
/*MT6280RF*/       /* Re-write RXRC for TX */
/*MT6280RF*/       cw50  = ( POR_CW50 &(~(RXIF_RCK_MASK<<13)) ) | ( (l1d_rf2.rxif_rck_m&RXIF_RCK_MASK)<<13 ) | ( 1<<19 );
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x32, cw50) );   //CW50 : TXLP_CSEL_MAN = 1, TXLP_CSEL = RXIF_RCK_M
/*MT6280RF*/    }
/*MT6280RF*/    if( (l1d_rf2.is_power_on_cal)&(ADC_LF_COEF_CAL_DONE) )
/*MT6280RF*/    {  /* Re-write ADC Loop Filter Value */
/*MT6280RF*/       cw169 = ( (l1d_rf2.r8dl_stage2_adj&ADC_COEF_MASK)<<8 ) | (l1d_rf2.r8dl_stage1_adj   &ADC_COEF_MASK);
/*MT6280RF*/       cw170 = ( (l1d_rf2.r8dl_stage3_adj&ADC_COEF_MASK)<<8 ) | (l1d_rf2.r8dl_quantizer_adj&ADC_COEF_MASK);
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0xA9, cw169) );  //CW169 : R8DL_STAGE2_ADJ, R8DL_STAGE1_ADJ
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0xAA, cw170) );  //CW170 : R8DL_STAGE3_ADJ, R8DL_QUANTIZER_ADJ
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/ #if IS_ANALOG_RXIQ_DEBUG_MODE_ON
/*MT6280RF*/    #if IS_INJECT_SIGNAL2ADC_DEBUG_MODE_ON
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), POR_CW21        ); /* CW21  : must remain @ default for inject signal to ADC */
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), RXIQ_DEBUG_CW59 ); /* CW59  : set R8DL_CH0_INPUT_SEL[1:0] = 11 (CW59=C0055) */
/*MT6280RF*/    #else
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), RXIQ_DEBUG_CW21 ); /* CW21  : RX IQ signal before ADC ( CW21[8] = 1 ) */
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), POR_CW59        ); /* CW59  : default value */
/*MT6280RF*/    #endif
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), RXIQ_DEBUG_CW6  ); /* CW6   : enable the analog test mux setting GMUX1/2/3/4 to 0x001 (all four), as well as TST34_EN=1 */
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), RXIQ_DEBUG_CW245); /* CW245 : If we would like to use APC output pins as the test pins */
/*MT6280RF*/ #endif
/*MT6280RF*/
/*MT6280RF*/    IMM_SEND_BPI( 0x0000 );
/*MT6280RF*/
/*MT6280RF*/    IMM_MODE_END(  );
/*MT6280RF*/
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_PowerOff( void )
/*MT6280RF*/ {  // Sleep to Phone Standby
/*MT6280RF*/    unsigned long _savedMask;
/*MT6280RF*/
/*MT6280RF*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6280RF*/
/*MT6280RF*/ #if IS_32K_CRYSTAL_REMOVAL_SUPPORT
/*MT6280RF*/    {  //Set LPM fractional divider before RF power off
/*MT6280RF*/       extern unsigned long L1D_GetDCXOFreqLPM(void);
/*MT6280RF*/       unsigned long dcxo_frac = L1D_GetDCXOFreqLPM();
/*MT6280RF*/
/*MT6280RF*/       if( !L1D_RF_Check_32K_XO_Status() )
/*MT6280RF*/       {
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0xF9, ((XO_CapID&0xFF)<<12)|(dcxo_frac&0xFFF)) );  //CW249: Set previous Cap ID value
/*MT6280RF*/       }
/*MT6280RF*/    }
/*MT6280RF*/ #endif
/*MT6280RF*/
/*MT6280RF*/    if(1) //if( l1d_rf.is_sleep ) /* in the case of entering the sleep mode */
/*MT6280RF*/    {
/*MT6280RF*/ #if defined(__UMTS_RAT__) && defined ( __UMTS_FDD_MODE__ )
/*MT6280RF*/       extern char UL1D_RF_CheckDMPower( void );                   /* check 3g RF flag */
/*MT6280RF*/ #endif
/*MT6280RF*/       _savedMask = SaveAndSetIRQMask();                           /* disable interrupt */
/*MT6280RF*/
/*MT6280RF*/ #if defined(__UMTS_RAT__) && defined ( __UMTS_FDD_MODE__ )
/*MT6280RF*/       if( UL1D_RF_CheckDMPower() )                                /* 3G is still ON, so 2G can not do the power-off sequence */
/*MT6280RF*/       {
/*MT6280RF*/          l1d_rf2.is_2g_on = 0;                                    /* clear 2G flag to notify 2G is OFF */
/*MT6280RF*/          L1D_DM_Power_Control_Trace( 0, 1 );                      /* indicate 2G is OFF and 3G is ON */
/*MT6280RF*/          RestoreIRQMask(_savedMask);                              /* enable interrupt */
/*MT6280RF*/       }
/*MT6280RF*/       else                                                        /* 3G is already OFF, so 2G does the power-off sequence */
/*MT6280RF*/ #endif
/*MT6280RF*/       {
/*MT6280RF*/          l1d_rf2.is_2g_on = 0;                                    /* clear 2G flag to notify 2G is OFF */
/*MT6280RF*/          L1D_DM_Power_Control_Trace( 0, 0 );                      /* indicate 2G is OFF and 3G is OFF */
/*MT6280RF*/          RestoreIRQMask(_savedMask);                              /* enable interrupt */
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, 0x00000) ); //CW1  : DYN_EN=0
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x03, 0x01928) ); //CW3  : BG off
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x86, 0x126D1) ); //CW134: PTAT off
/*MT6280RF*/          L1D_PMU_VRF18Setting( 0 );                               /* Disable VDD_18 (controlled by PMIC) */
/*MT6280RF*/          l1d_rf2.is_2g_on = 6;                                    /* Record the PMU step                 */
/*MT6280RF*/          L1D_PMU_VRF28Setting( 0 );                               /* Disable VDD_28 (controlled by PMIC) */
/*MT6280RF*/          l1d_rf2.is_2g_on = 8;                                    /* Record the PMU step                 */
/*MT6280RF*/       }
/*MT6280RF*/    }
/*MT6280RF*/    else
/*MT6280RF*/    {
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, 0x00000) );  //CW1  : DYN_EN=0
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x03, 0x01928) );  //CW3  : BG off
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x86, 0x126D1) );  //CW134: PTAT off
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    IMM_MODE_END(  );
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_WindowOn( void )
/*MT6280RF*/ {
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void  L1D_RF_WindowOff( void )
/*MT6280RF*/ {
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void L1D_RF_RCAL_Cal( void )
/*MT6280RF*/ {  /* For Bench, Not for MP phone */
/*MT6280RF*/    unsigned long  cw135;
/*MT6280RF*/    unsigned long  cw1 = 0;
/*MT6280RF*/
/*MT6280RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6280RF*/
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, 0x52201) ); // CW1  , DYN_EN=1 | Mode=3G RX Cal.
/*MT6280RF*/    WAIT_TIME_QB( 67 );                                      // wait >60us
/*MT6280RF*/
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0xB9, 0x80000) ); // CW185, rcal_start_tr: D[19]=1
/*MT6280RF*/    WAIT_TIME_QB( 11 );                                      // wait 10us
/*MT6280RF*/
/*MT6280RF*/    IMM_RECEIVE_BSI( SCTRL_IMOD(0,9), 0x87, SCTRL_IMOD(0,20), &(cw135) );
/*MT6280RF*/    l1d_rf2.calr_const = ( cw135&(CALR_CONST_MASK<<14) )>>14;
/*MT6280RF*/
/*MT6280RF*/    /* If configure CW1(3G RX Cal. mode) back to (Sleep mode) need to be checked */
/*MT6280RF*/    cw1 = RXDUMP_3G      |RX_LNA_BAND_SEL[0]|POR_CW1; // CW1  , Mode=1111 (3G RX Dump Mode)
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, cw1) );
/*MT6280RF*/
/*MT6280RF*/    cw1 = RXDUMP_SLEEP_3G|RX_LNA_BAND_SEL[0]|POR_CW1; // CW1  , Mode=1110 (3G RX Dump Sleep)
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, cw1) );
/*MT6280RF*/
/*MT6280RF*/    cw1 = RXSLEEP_MODE_3G|RX_LNA_BAND_SEL[0]|POR_CW1; // CW1  , Mode=1000 (3G RX Sleep)
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, cw1) );
/*MT6280RF*/
/*MT6280RF*/    IMM_MODE_END( );
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void L1D_RF_RXRC_DCO_Cal( void )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned short band_idx = 0;
/*MT6280RF*/    unsigned long  cw99, cw100;
/*MT6280RF*/    unsigned long  cw1 = 0;
/*MT6280RF*/    unsigned long  cw187;
/*MT6280RF*/    unsigned long  cw194, cw195, cw196, cw22, cw18, cw26;
/*MT6280RF*/
/*MT6280RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6280RF*/
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x17, 0x00000) ); // CW23 , to make sure CW23 is 0x00000 because default value seems not all zero
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x70, 0x00002) ); // CW112, Set Static AUX out read to RXDynamic
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x48, 0x01FFF) ); // CW72 , Set readback to static AUXOUT page
/*MT6280RF*/
/*MT6280RF*/    for( band_idx=0; band_idx<CAL_BAND_NUM; band_idx++)
/*MT6280RF*/    {
/*MT6280RF*/       L1D_RF_GetRxPLLSetting( (FrequencyBand850+band_idx), MIDBAND_ARFCN[band_idx], (long *)&cw99, (long *)&cw100 );
/*MT6280RF*/
/*MT6280RF*/       cw1 = RXCAL_MODE_3G|RX_LNA_BAND_SEL[band_idx]|POR_CW1;
/*MT6280RF*/
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x63, cw99 ) ); // CW99 , PLL Setting
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x64, cw100) ); // CW100, PLL Setting
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, cw1  ) ); // CW1  , Mode=0101 | LNA=4(Variable) | DYN_EN | Band(Variable)
/*MT6280RF*/       WAIT_TIME_QB( 212 );                                   // wait 195us
/*MT6280RF*/
/*MT6280RF*/       IMM_RECEIVE_BSI( SCTRL_IMOD(0,9), 0xBB, SCTRL_IMOD(0,20), &(cw187) ); // read back RXRC Cal. Value
/*MT6280RF*/
/*MT6280RF*/       IMM_RECEIVE_BSI( SCTRL_IMOD(0,9), 0xC2, SCTRL_IMOD(0,20), &(cw194) ); // read back I/Q DC Offset Value
/*MT6280RF*/       IMM_RECEIVE_BSI( SCTRL_IMOD(0,9), 0xC3, SCTRL_IMOD(0,20), &(cw195) ); // read back I/Q DC Offset Value
/*MT6280RF*/       IMM_RECEIVE_BSI( SCTRL_IMOD(0,9), 0xC4, SCTRL_IMOD(0,20), &(cw196) ); // read back I/Q DC Offset Value
/*MT6280RF*/       IMM_RECEIVE_BSI( SCTRL_IMOD(0,9), 0x16, SCTRL_IMOD(0,20), &(cw22 ) ); // read back I/Q DC Offset Value
/*MT6280RF*/       IMM_RECEIVE_BSI( SCTRL_IMOD(0,9), 0x12, SCTRL_IMOD(0,20), &(cw18 ) ); // read back I/Q DC Offset Value
/*MT6280RF*/       IMM_RECEIVE_BSI( SCTRL_IMOD(0,9), 0x1A, SCTRL_IMOD(0,20), &(cw26 ) ); // read back I/Q DC Offset Value
/*MT6280RF*/
/*MT6280RF*/       l1d_rf2.rxif_rck_m                    = ( cw187&(RXIF_RCK_MASK<<14))>>14;
/*MT6280RF*/
/*MT6280RF*/       l1d_rf2.rxif_dcoc_daci_m[band_idx][9] = ( cw26 &(DCO_DAC_MASK<< 0) )>> 0;
/*MT6280RF*/       l1d_rf2.rxif_dcoc_daci_m[band_idx][8] = ( cw194&(DCO_DAC_MASK<< 0) )>> 0;
/*MT6280RF*/       l1d_rf2.rxif_dcoc_daci_m[band_idx][7] = ( cw194&(DCO_DAC_MASK<<12) )>>12;
/*MT6280RF*/       l1d_rf2.rxif_dcoc_daci_m[band_idx][6] = ( cw195&(DCO_DAC_MASK<< 0) )>> 0;
/*MT6280RF*/       l1d_rf2.rxif_dcoc_daci_m[band_idx][5] = ( cw196&(DCO_DAC_MASK<<12) )>>12;
/*MT6280RF*/       l1d_rf2.rxif_dcoc_daci_m[band_idx][4] = ( cw196&(DCO_DAC_MASK<< 0) )>> 0;
/*MT6280RF*/       l1d_rf2.rxif_dcoc_daci_m[band_idx][3] = ( cw22 &(DCO_DAC_MASK<< 0) )>> 0;
/*MT6280RF*/       l1d_rf2.rxif_dcoc_daci_m[band_idx][2] = ( cw18 &(DCO_DAC_MASK<< 0) )>> 0;
/*MT6280RF*/
/*MT6280RF*/       l1d_rf2.rxif_dcoc_dacq_m[band_idx][9] = ( cw26 &(DCO_DAC_MASK<< 6) )>> 6;
/*MT6280RF*/       l1d_rf2.rxif_dcoc_dacq_m[band_idx][8] = ( cw194&(DCO_DAC_MASK<< 6) )>> 6;
/*MT6280RF*/       l1d_rf2.rxif_dcoc_dacq_m[band_idx][7] = ( cw195&(DCO_DAC_MASK<<12) )>>12;
/*MT6280RF*/       l1d_rf2.rxif_dcoc_dacq_m[band_idx][6] = ( cw195&(DCO_DAC_MASK<< 6) )>> 6;
/*MT6280RF*/       l1d_rf2.rxif_dcoc_dacq_m[band_idx][5] = ( cw22 &(DCO_DAC_MASK<<12) )>>12;
/*MT6280RF*/       l1d_rf2.rxif_dcoc_dacq_m[band_idx][4] = ( cw196&(DCO_DAC_MASK<< 6) )>> 6;
/*MT6280RF*/       l1d_rf2.rxif_dcoc_dacq_m[band_idx][3] = ( cw22 &(DCO_DAC_MASK<< 6) )>> 6;
/*MT6280RF*/       l1d_rf2.rxif_dcoc_dacq_m[band_idx][2] = ( cw18 &(DCO_DAC_MASK<< 6) )>> 6;
/*MT6280RF*/
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x48, POR_CW72 ) );  // CW72 , Set readback page back
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x70, POR_CW112) );  // CW112, Reset readout_sel
/*MT6280RF*/
/*MT6280RF*/    cw1 = RXDUMP_3G      |RX_LNA_BAND_SEL[0]|POR_CW1; // CW1  , Mode=1111 (3G RX Dump Mode)
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, cw1) );
/*MT6280RF*/
/*MT6280RF*/    cw1 = RXDUMP_SLEEP_3G|RX_LNA_BAND_SEL[0]|POR_CW1; // CW1  , Mode=1110 (3G RX Dump Sleep)
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, cw1) );
/*MT6280RF*/
/*MT6280RF*/    cw1 = RXSLEEP_MODE_3G|RX_LNA_BAND_SEL[0]|POR_CW1; // CW1  , Mode=1000 (3G RX Sleep)
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, cw1) );
/*MT6280RF*/
/*MT6280RF*/    IMM_MODE_END( );
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void L1D_RF_TX_GainStep_Cal( void )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned short band_idx         = 0;
/*MT6280RF*/    unsigned short N                = 0;
/*MT6280RF*/    unsigned short k_cnt            = 0;
/*MT6280RF*/    unsigned short sum_cnt          = 0;
/*MT6280RF*/    unsigned short codetype         = 0;
/*MT6280RF*/    unsigned short Nint             = 0;
/*MT6280RF*/    unsigned long  Nfrac            = 0;
/*MT6280RF*/    unsigned long  read_data        = 0;
/*MT6280RF*/    signed short   Pmeas1           = 0;
/*MT6280RF*/    signed short   Pmeas2           = 0;
/*MT6280RF*/    signed short   Pmeas1_post_proc = 0;
/*MT6280RF*/    signed short   Pmeas2_post_proc = 0;
/*MT6280RF*/    signed short   temp_gain_step   = 0;
/*MT6280RF*/    signed short   simu_gain_step   = 0;
/*MT6280RF*/    signed short   gain_step_ub     = 0;
/*MT6280RF*/    signed short   gain_step_lb     = 0;
/*MT6280RF*/    signed short   sum_gain_step    = 0;
/*MT6280RF*/    signed short   avg_gain_step    = 0;
/*MT6280RF*/    long  cw34,cw95,cw96,cw80,cw97,cw98,cw75;
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/    long  cw245,cw33,cw35;
/*MT6280RF*/ #else
/*MT6280RF*/    unsigned short qpath_on         = 0;
/*MT6280RF*/    long  cw117,cw9,cw35;
/*MT6280RF*/ #endif
/*MT6280RF*/    signed char i;
/*MT6280RF*/    i = ( chip_ver == 0x11 || chip_ver == 0x21) ? 0 : 1;
/*MT6280RF*/
/*MT6280RF*/    l1d_rf2.Gvga_rf[0][0] = GVGARF_LB[i][0]-GBB1_LB[0];
/*MT6280RF*/    l1d_rf2.Gvga_rf[1][0] = GVGARF_LB[i][0]-GBB1_LB[0];
/*MT6280RF*/    l1d_rf2.Gvga_rf[2][0] = GVGARF_HB[i][0]-GBB1_HB[i][0];
/*MT6280RF*/    l1d_rf2.Gvga_rf[3][0] = GVGARF_HB[i][0]-GBB1_HB[i][0];
/*MT6280RF*/
/*MT6280RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6280RF*/
/*MT6280RF*/    /* Set Tx to Initialization State */
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x2B, 0x96042) ); // CW43
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x2D, 0x11200) ); // CW45
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x2F, 0x00000) ); // CW47
/*MT6280RF*/
/*MT6280RF*/    for( band_idx=0;band_idx<CAL_BAND_NUM;band_idx++)
/*MT6280RF*/    {
/*MT6280RF*/       L1D_RF_GetTxPLLSetting       ( (FrequencyBand850+band_idx), MIDBAND_ARFCN[band_idx], &cw95, &cw96);
/*MT6280RF*/       L1D_RF_GetTxKDCOCAL2ndSetting( (FrequencyBand850+band_idx), MIDBAND_ARFCN[band_idx], &cw97, &cw98);
/*MT6280RF*/
/*MT6280RF*/       Nint  = (  cw95&(0xFF<<12) )>>12 ;
/*MT6280RF*/       Nfrac = ( (cw95&0xFFF)<<11 ) | ( (cw96&(0x7FF<<9))>>9 ) ;
/*MT6280RF*/
/*MT6280RF*/       codetype     = L1D_RF_GetTxDCOSCACodeTypeSetting( Nint, Nfrac );
/*MT6280RF*/
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/       cw245 = CW245_CURRENT_ON;
/*MT6280RF*/       cw33  = ( (FrequencyBand850+band_idx)<FrequencyBand1800 ) ? (POR_CW33|(1<<2)) : (POR_CW33);
/*MT6280RF*/       cw35  = ( POR_CW35 | (1<<16) | (0xF) );
/*MT6280RF*/ #else
/*MT6280RF*/       qpath_on = ( (FrequencyBand850+band_idx)<FrequencyBand1800 ) ? (IS_Q_PATH_ON<<5) : (0x0<<5);
/*MT6280RF*/       cw117 = qpath_on ? POR_CW117 : POR_CW117;
/*MT6280RF*/       cw9   = (long) ((POR_CW9&0xFFFFFC7) | (0x3<<3));
/*MT6280RF*/       cw35  = ( POR_CW35 | 0x18F );
/*MT6280RF*/ #endif
/*MT6280RF*/       cw34  = POR_CW34;
/*MT6280RF*/       cw80  = POR_CW80 | ( (codetype&0xFFF)<<8 );
/*MT6280RF*/       cw75  = POR_CW75 ;
/*MT6280RF*/
/*MT6280RF*/       /* Set TX Cal. Mode : ST1 */
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0xF5, cw245));    // CW245: Always on current control
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x21, cw33) );    // CW33 : 2G TX qpath on
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x23, cw35) );    // CW35 : ORFS degradation at LT E1 sw workaround
/*MT6280RF*/ #else
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x9 , cw9 ) );    // CW9  : [D5:D3]=001,Changed it for spur improvement
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x75, cw117));    // CW117: CW117: 2G TX qpath
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x23, cw35) );    // CW35 : turn-on IFLDO and CKGOUT before TX burst to get more timing margin for both Q-path on/off option */
/*MT6280RF*/ #endif
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x22, cw34) );    // CW34 : Enable correct TX band output
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x5F, cw95) );    // CW95 : write STX NMMD0
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x60, cw96) );    // CW96 : write STX NMMD0, offset
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x50, cw80) );    // CW80 : write STX DCO SCA typ. code
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x61, cw97) );    // CW97 : write STX NMMD1 for KDCO cal.
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x62, cw98) );    // CW98 : write STX NMMD1 for KDCO cal.
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x4B, cw75) );    // CW75 : write STX_LF_BW[2:0]=3'b000(91kHz) for 2G mode
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, TXCAL_MODE_2G|POR_CW1|band_idx) ); // CW1 : Mode = 0011 | Band(Variable)
/*MT6280RF*/ #else
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, TXCAL_MODE_2G|POR_CW1|qpath_on|band_idx) ); // CW1 : Mode = 0011 | qpath_on | Band(Variable)
/*MT6280RF*/ #endif
/*MT6280RF*/       WAIT_TIME_QB( 250 );                                     // Wait 230us
/*MT6280RF*/
/*MT6280RF*/       /* Set TX Burst Mode : ST2B */
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, TXBURST_MODE_2G|(0x1<<11)|POR_CW1|band_idx) ); // CW1 : Mode = 0100 | G/8 mode change | Band(Variable)
/*MT6280RF*/ #else
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, TXBURST_MODE_2G|(0x1<<11)|POR_CW1|qpath_on|band_idx) ); // CW1 : Mode = 0100 | G/8 mode change | qpath_on | Band(Variable)
/*MT6280RF*/ #endif
/*MT6280RF*/       /* Set DET ADC to Initialization State */
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x25, 0x607B7) ); // CW37
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x26, 0x02916) ); // CW38
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x24, 0x00280) ); // CW36
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x24, 0x00380) ); // CW36
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x24, 0x069AF) ); // CW36
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x26, 0x02917) ); // CW38
/*MT6280RF*/
/*MT6280RF*/       /* trigger test tone start to output */
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x72, 0x04000) ); // CW114 : trigger test tone start to output
/*MT6280RF*/
/*MT6280RF*/       for( N=0;N<13;N++)
/*MT6280RF*/       {
/*MT6280RF*/          sum_gain_step = 0;
/*MT6280RF*/          avg_gain_step = 0;
/*MT6280RF*/          sum_cnt       = 0;
/*MT6280RF*/
/*MT6280RF*/          for( k_cnt=0;k_cnt<MAX_RETRY_TIMES;k_cnt++)
/*MT6280RF*/          {
/*MT6280RF*/             if( band_idx < 2 )
/*MT6280RF*/             {
/*MT6280RF*/                IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x24, TXGAINSTEP_CAL_CW36_LB_TABLE[N][0])    );    // CW36
/*MT6280RF*/                IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x29, TXGAINSTEP_CAL_CW41_LB_TABLE[N][0])    );    // CW41
/*MT6280RF*/                IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x2A, TXGAINSTEP_CAL_CW42_LB_TABLE[i][N][0]) );    // CW42
/*MT6280RF*/             }
/*MT6280RF*/             else
/*MT6280RF*/             {
/*MT6280RF*/                IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x24, TXGAINSTEP_CAL_CW36_HB_TABLE[i][N][0]) );    // CW36
/*MT6280RF*/                IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x29, TXGAINSTEP_CAL_CW41_HB_TABLE[i][N][0]) );    // CW41
/*MT6280RF*/                IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x2A, TXGAINSTEP_CAL_CW42_HB_TABLE[N][0])    );    // CW42
/*MT6280RF*/             }
/*MT6280RF*/             WAIT_TIME_QB( 80 );                                     // Wait 55us avoid FH drop BSI clk rate must larger than 55us
/*MT6280RF*/             IMM_RECEIVE_BSI( SCTRL_IMOD(0,9), 0x7C, SCTRL_IMOD(0,20), &(read_data) );        // read back CW124 : gainmeas
/*MT6280RF*/             Pmeas1 = read_data & GAIN_MEAS_MASK;
/*MT6280RF*/
/*MT6280RF*/             if( band_idx < 2 )
/*MT6280RF*/             {
/*MT6280RF*/                IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x24, TXGAINSTEP_CAL_CW36_LB_TABLE[N][1])    );    // CW36
/*MT6280RF*/                IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x29, TXGAINSTEP_CAL_CW41_LB_TABLE[N][1])    );    // CW41
/*MT6280RF*/                IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x2A, TXGAINSTEP_CAL_CW42_LB_TABLE[i][N][1]) );    // CW42
/*MT6280RF*/             }
/*MT6280RF*/             else
/*MT6280RF*/             {
/*MT6280RF*/                IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x24, TXGAINSTEP_CAL_CW36_HB_TABLE[i][N][1]) );    // CW36
/*MT6280RF*/                IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x29, TXGAINSTEP_CAL_CW41_HB_TABLE[i][N][1]) );    // CW41
/*MT6280RF*/                IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x2A, TXGAINSTEP_CAL_CW42_HB_TABLE[N][1])    );    // CW42
/*MT6280RF*/             }
/*MT6280RF*/             WAIT_TIME_QB( 80 );                                     // Wait 55us avoid FH drop BSI clk rate must larger than 55us
/*MT6280RF*/             IMM_RECEIVE_BSI( SCTRL_IMOD(0,9), 0x7C, SCTRL_IMOD(0,20), &(read_data) );        // read back CW124 : gainmeas
/*MT6280RF*/             Pmeas2 = read_data & GAIN_MEAS_MASK;
/*MT6280RF*/
/*MT6280RF*/             Pmeas1_post_proc = ((Pmeas1&0x800)!=0)?(Pmeas1-(0x1<<12)):(Pmeas1);              // Read Gain Post Processing S6.5
/*MT6280RF*/             Pmeas2_post_proc = ((Pmeas2&0x800)!=0)?(Pmeas2-(0x1<<12)):(Pmeas2);              // Read Gain Post Processing S6.5
/*MT6280RF*/
/*MT6280RF*/             temp_gain_step   = (band_idx<2) ? (Pmeas2_post_proc - Pmeas1_post_proc + GBB1_LB[N+1] - GBB1_LB[N]) : (Pmeas2_post_proc - Pmeas1_post_proc + GBB1_HB[i][N+1] - GBB1_HB[i][N]);
/*MT6280RF*/
/*MT6280RF*/             simu_gain_step   = (band_idx<2) ? (GVGARF_LB[i][N+1]-GVGARF_LB[i][N]) : (GVGARF_HB[i][N+1]-GVGARF_HB[i][N]);
/*MT6280RF*/
/*MT6280RF*/             gain_step_ub     = (N>7) ? (simu_gain_step+50) : (simu_gain_step  /2);
/*MT6280RF*/             gain_step_lb     = (N>7) ? (simu_gain_step-50) : (simu_gain_step*3/2);
/*MT6280RF*/
/*MT6280RF*/             if( (temp_gain_step>=0) || (temp_gain_step>(gain_step_ub)) || (temp_gain_step<(gain_step_lb)) )
/*MT6280RF*/             {  l1d_rf2.tx_gain_step_k_flag += (0x1<<(band_idx*4));
/*MT6280RF*/             }
/*MT6280RF*/             else
/*MT6280RF*/             {
/*MT6280RF*/                sum_gain_step += Pmeas2_post_proc - Pmeas1_post_proc;
/*MT6280RF*/                sum_cnt++;
/*MT6280RF*/             }
/*MT6280RF*/          }
/*MT6280RF*/          if( band_idx < 2 )
/*MT6280RF*/             avg_gain_step = (sum_cnt==0) ? (simu_gain_step-GBB1_LB[N+1]+GBB1_LB[N])       : (sum_gain_step/sum_cnt);
/*MT6280RF*/          else
/*MT6280RF*/             avg_gain_step = (sum_cnt==0) ? (simu_gain_step-GBB1_HB[i][N+1]+GBB1_HB[i][N]) : (sum_gain_step/sum_cnt);
/*MT6280RF*/
/*MT6280RF*/          l1d_rf2.Gvga_rf[band_idx][N+1] = l1d_rf2.Gvga_rf[band_idx][N] + avg_gain_step;
/*MT6280RF*/       }
/*MT6280RF*/
/*MT6280RF*/       for( N=0;N<14;N++)
/*MT6280RF*/       {
/*MT6280RF*/          l1d_rf2.Gvga_rf[band_idx][N] += ( (band_idx<2) ? GBB1_LB[N] : GBB1_HB[i][N] );
/*MT6280RF*/       }
/*MT6280RF*/
/*MT6280RF*/ #if IS_CHIP_MT6280_S00
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x21, POR_CW33         ) );            // CW33  : 2G TX qpath off
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x23, POR_CW35         ) );            // CW35  : POR
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0xF5, CW245_CURRENT_OFF) );            // CW245 : Current Control
/*MT6280RF*/ #else
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x9 , POR_CW9          ) );            // CW9   : POR
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x23, POR_CW35         ) );            // CW35  : POR
/*MT6280RF*/ #endif
/*MT6280RF*/
/*MT6280RF*/       /* stop test tone start to output */
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x72, 0x08000) ); // CW114 : trigger test tone start to output
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x72, 0x00000) );
/*MT6280RF*/
/*MT6280RF*/       if( band_idx == CAL_BAND_NUM-1 )
/*MT6280RF*/       {
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x24, POR_CW36) ); // CW36
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x29, POR_CW41) ); // CW41
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x2A, POR_CW42) ); // CW42
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x2B, POR_CW43) ); // CW43
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x2D, POR_CW45) ); // CW45
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x25, POR_CW37) ); // CW37
/*MT6280RF*/          IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x26, POR_CW38) ); // CW38
/*MT6280RF*/       }
/*MT6280RF*/
/*MT6280RF*/       IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, SLEEP_MODE|POR_CW1|band_idx) );  // CW1   : Sleep mode
/*MT6280RF*/       WAIT_TIME_QB( 10 );
/*MT6280RF*/    }
/*MT6280RF*/
/*MT6280RF*/    IMM_MODE_END( );
/*MT6280RF*/ }
/*MT6280RF*/
/*MT6280RF*/ void L1D_RF_ADC_LoopFilter_Coef_Cal( void )
/*MT6280RF*/ {
/*MT6280RF*/    unsigned long cw239, cw240;
/*MT6280RF*/    unsigned long cw169, cw170;
/*MT6280RF*/
/*MT6280RF*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6280RF*/
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x15, 0x2D8C0) ); /* CW21 , RXIF_POW_MAN=1  */
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x0E, 0x005C0) ); /* CW14 , RXIF_EN_M Disable Baseband */
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0xAD, 0x0B040) ); /* CW173, R8DL_CAL_SEL=1 Enable Calibration */
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x70, 0x00002) ); /* CW112, Set Static AUX out read to RXDynamic */
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, 0x14200) ); /* CW1  , Mode=0001(2G RX Cal.) */
/*MT6280RF*/
/*MT6280RF*/    WAIT_TIME_QB( 1200 );                                    // Wait 1000us
/*MT6280RF*/
/*MT6280RF*/    IMM_RECEIVE_BSI( SCTRL_IMOD(0,9), 0xEF, SCTRL_IMOD(0,20), &(cw239) ); /* read back filter coefs. */
/*MT6280RF*/    IMM_RECEIVE_BSI( SCTRL_IMOD(0,9), 0xF0, SCTRL_IMOD(0,20), &(cw240) ); /* read back filter coefs. */
/*MT6280RF*/
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0xAD, POR_CW173) ); /* CW173, R8DL_CAL_SEL=0 Set back to default */
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x15, POR_CW21 ) ); /* CW21 , Set back to default */
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x0E, POR_CW14 ) ); /* CW14 , Set back to default */
/*MT6280RF*/
/*MT6280RF*/    l1d_rf2.r8dl_stage1_adj    = ( cw239&(ADC_COEF_MASK<<0) )>>0;
/*MT6280RF*/    l1d_rf2.r8dl_stage2_adj    = ( cw239&(ADC_COEF_MASK<<8) )>>8;
/*MT6280RF*/    l1d_rf2.r8dl_stage3_adj    = ( cw240&(ADC_COEF_MASK<<0) )>>0;
/*MT6280RF*/    l1d_rf2.r8dl_quantizer_adj = ( cw240&(ADC_COEF_MASK<<8) )>>8;
/*MT6280RF*/
/*MT6280RF*/    /* write back ADC Loop Filter Value */
/*MT6280RF*/    cw169 = ( (l1d_rf2.r8dl_stage2_adj&ADC_COEF_MASK)<<8 ) | (l1d_rf2.r8dl_stage1_adj   &ADC_COEF_MASK);
/*MT6280RF*/    cw170 = ( (l1d_rf2.r8dl_stage3_adj&ADC_COEF_MASK)<<8 ) | (l1d_rf2.r8dl_quantizer_adj&ADC_COEF_MASK);
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0xA9, cw169) );     /* CW169 : R8DL_STAGE2_ADJ, R8DL_STAGE1_ADJ */
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0xAA, cw170) );     /* CW170 : R8DL_STAGE3_ADJ, R8DL_QUANTIZER_ADJ */
/*MT6280RF*/
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x70, POR_CW112) ); /* CW112, Reset readout_sel */
/*MT6280RF*/
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, 0x24200) );   /* CW1  , Mode=0010(2G RX Burst) */
/*MT6280RF*/    IMM_SEND_BSI( SCTRL_IMOD(0,29), BSI_CW(0x01, 0x04200) );   /* CW1  , Mode=0000(2G RX Sleep) */
/*MT6280RF*/
/*MT6280RF*/    IMM_MODE_END( );
/*MT6280RF*/ }
/*MT6280RF*/
#endif

#if IS_RF_MT6169
/*MT6169*/
/*MT6169*/ #include "intrCtrl.h"
/*MT6169*/
/*MT6169*/ #if IS_RF_CENTRAL_CONTROL_ENABLE
/*MT6169*/ /* Need not send POR by SW */
/*MT6169*/ #else
/*MT6169*/ #define RF_POR_NUM        (sizeof(SDATA_TABLE) /sizeof(unsigned long))
/*MT6169*/ #define RF_POR_NUM_E3     (sizeof(SDATA_TABLE_E3) /sizeof(unsigned long))
/*MT6169*/ #endif
/*MT6169*/
/*MT6169*/ #define CALR_CONST_MASK   0x0000001FL  //  5 bits length
/*MT6169*/ #define CALR_TCL_R_M_MASK 0x0000001FL  //  5 bits length
/*MT6169*/
/*MT6169*/ /* CW1 : Mode */
/*MT6169*/ #define SLEEP_MODE        (0x00<<15)
/*MT6169*/ #define RXCAL_MODE_2G     (0x01<<15)
/*MT6169*/ #define RXBURST_MODE_2G   (0x02<<15)
/*MT6169*/ #define TXCAL_MODE_2G     (0x03<<15)
/*MT6169*/ #define TXBURST_MODE_2G   (0x04<<15)
/*MT6169*/ #define RXCAL_MODE_FDD    (0x05<<15)
/*MT6169*/ #define TXCAL_MODE_FDD    (0x06<<15)
/*MT6169*/ #define RXSLEEP_MODE_FDD  (0x11<<15)
/*MT6169*/ #define TXSLEEP_MODE_FDD  (0x12<<15)
/*MT6169*/ #define MODE_3_4G         (0x01<< 7)
/*MT6169*/ #define RG_CALR_MAN_ON    (0x01<<19)
/*MT6169*/
/*MT6169*/ #define POR_CW1           0x00100240L /* set DYN_EN=1 and Band=Band 1 */
/*MT6169*/ #define POR_CW3           0x00300052L
/*MT6169*/ #define POR_CW141         0x08D0401CL
/*MT6169*/ #define POR_CW143         0x08F80000L
/*MT6169*/ /* Set CW default power on value include addr */
/*MT6169*/ /* POR default value */
/*MT6169*/ #define POR_CW181         0x0B57E0D5L
/*MT6169*/ #define POR_CW182         0x0B6200D1L
/*MT6169*/ #define POR_CW183         0x0B78E300L
/*MT6169*/ #define POR_CW109         0x06D5A808L
/*MT6169*/ #define POR_CW113         0x07180030L
/*MT6169*/ #define POR_CW155         0x09B41803L
/*MT6169*/ #define POR_CW163         0x0A303785L
/*MT6169*/ #define POR_CW164         0x0A4C5040L
/*MT6169*/ /*-------TX DET Timing related------*/
/*MT6169*/ #define POR_CW83          0x053111C6L
/*MT6169*/ #define POR_CW85          0x0550161DL
/*MT6169*/ #define POR_CW86          0x05604010L
/*MT6169*/ #define POR_CW87          0x057043AFL
/*MT6169*/ #define POR_CW88          0x058F202DL
/*MT6169*/ #define POR_CW89          0x05902D2DL
/*MT6169*/ #define POR_CW90          0x05A02D2DL
/*MT6169*/ #define POR_CW236         0x0EC00000L
/*MT6169*/ #define POR_CW237         0x0EDE3C00L
/*MT6169*/ #define POR_CW238         0x0EE513A0L
/*MT6169*/ #define POR_CW239         0x0EF21588L
/*MT6169*/ #define POR_CW240         0x0F0006B4L
/*MT6169*/ #define POR_CW241         0x0F1006B4L
/*MT6169*/ /*----------------------------------*/
/*MT6169*/ #define POR_CW36          0x02400001L
/*MT6169*/ #define POR_CW37          0x02500000L
/*MT6169*/ #define POR_CW38          0x02600000L
/*MT6169*/ #define POR_CW73          0x0491C000L
/*MT6169*/ //#define POR_CW77          0x04D3222AL //Move to m12190.h
/*MT6169*/ #define POR_CW81          0x0519E094L
/*MT6169*/ #define POR_CW115         0x073000C0L
/*MT6169*/ #define POR_CW117         0x075000BEL
/*MT6169*/ //#define POR_CW118         0x076EE311L //Move to m12190.h
/*MT6169*/ #define POR_CW132         0x084800A3L
/*MT6169*/ #define POR_CW157         0x09D00060L
/*MT6169*/ #define POR_CW161         0x0A1001FBL
/*MT6169*/ #define POR_CW165         0x0A5AAAAAL
/*MT6169*/ #define POR_CW248         0x0F8FFFE3L
/*MT6169*/ #define POR_CW213         0x0D5E0900L
/*MT6169*/ #define POR_CW211         0x0D380800L
/*MT6169*/ #define POR_CW188         0x0BC02004L
/*MT6169*/ #define POR_CW168         0x0A8382B9L
/*MT6169*/ #define POR_CW104         0x06801000L
/*MT6169*/ #define POR_CW220         0x0DC48D40L
/*MT6169*/ #define POR_CW221         0x0DD08C40L
/*MT6169*/ #define POR_CW222         0x0DEFFF1EL
/*MT6169*/ #define POR_CW224         0x0E0137F4L
/*MT6169*/ #define POR_CW225         0x0E13C689L
/*MT6169*/ #define POR_CW114         0x07200000L
/*MT6169*/ #define POR_CW21          0x0150000CL
/*MT6169*/ #define POR_CW22          0x0160000CL
/*MT6169*/
/*MT6169*/ #define POR_CW83_E3       0x053111C6L/* CW83  : */
/*MT6169*/ #define POR_CW85_E3       0x0550161DL/* CW85  : */
/*MT6169*/ #define POR_CW238_E3      0x0EE513A0L/* CW238 : */
/*MT6169*/ #define POR_CW239_E3      0x0EF21588L/* CW239 : */
/*MT6169*/ #define POR_CW240_E3      0x0F0006B4L/* CW240 : */
/*MT6169*/ #define POR_CW241_E3      0x0F1006B4L/* CW241 : */
/*MT6169*/ #define POR_CW132_E3      0x084800A3L
/*MT6169*/ #define POR_CW248_E3      0x0F8FFFE3L
/*MT6169*/ #define POR_CW104_E3      0x06800000L
/*MT6169*/ #define POR_CW72_E3       0x04800208L
/*MT6169*/ #define POR_CW82_E3       0x052A1424L
/*MT6169*/ #define POR_CW51_E3       0x03300080L
/*MT6169*/ #define POR_CW165_E3      0x0A5AAA22L
/*MT6169*/ #define POR_CW167_E3      0x0A7A0AA4L
/*MT6169*/ #define POR_CW73_E3       0x04900000L

/*MT6169*/ #if IS_RF_CENTRAL_CONTROL_ENABLE
/*MT6169*/ /* Need not send POR by SW */
/*MT6169*/ #else
/*MT6169*/ const unsigned long SDATA_TABLE[]=
/*MT6169*/ {
/*MT6169*/    POR_CW181,  /* CW181 : */
/*MT6169*/    POR_CW182,  /* CW182 : */
/*MT6169*/    POR_CW183,  /* CW183 : STX */
/*MT6169*/    POR_CW109,  /* CW109 : SRX RG_SRX_LDO_LVL_PFDCP=01|FBDIV=01|SDM=10|VCO=101| R_BYPASS_RETIMER=10 */
/*MT6169*/    POR_CW113,  /* CW113 : SRX SRX_ACAL_OUT_POL_FLIP=1|SRX_ACAL_TARGET_MAN=1 */
/*MT6169*/    POR_CW155,  /* CW155 : TDC */
/*MT6169*/    POR_CW163,  /* CW163 : DCO */
/*MT6169*/    POR_CW164,  /* CW164 : DCO */
/*MT6169*/ /*-------TX DET Timing related------*/
/*MT6169*/    POR_CW83 ,  /* CW83  : */
/*MT6169*/    POR_CW85 ,  /* CW85  : */
/*MT6169*/    POR_CW86 ,  /* CW86  : */
/*MT6169*/    POR_CW87 ,  /* CW87  : */
/*MT6169*/    POR_CW88 ,  /* CW88  : */
/*MT6169*/    POR_CW89 ,  /* CW89  : */
/*MT6169*/    POR_CW90 ,  /* CW90  : */
/*MT6169*/    POR_CW236,  /* CW236 : */
/*MT6169*/    POR_CW237,  /* CW237 : */
/*MT6169*/    POR_CW238,  /* CW238 : */
/*MT6169*/    POR_CW239,  /* CW239 : */
/*MT6169*/    POR_CW240,  /* CW240 : */
/*MT6169*/    POR_CW241,  /* CW241 : */
/*MT6169*/ /*----------------------------------*/
/*MT6169*/    POR_CW36 ,  /* CW36  : RX */
/*MT6169*/    POR_CW37 ,  /* CW37  : RX */
/*MT6169*/    POR_CW38 ,  /* CW38  : RX */
/*MT6169*/    POR_CW73 ,  /* CW73  : TXDYN */
/*MT6169*/    POR_CW77 ,  /* CW77  : TX_BIAS */
/*MT6169*/    POR_CW81 ,  /* CW81  : TXDET */
/*MT6169*/    POR_CW115,  /* CW115 : SRX */
/*MT6169*/    POR_CW117,  /* CW117 : SRX */
/*MT6169*/    POR_CW118,  /* CW118 : SRX RG_SRX_VCOSCA_HALFLSB=1 */
/*MT6169*/    POR_CW132,  /* CW132 : TXDYN data path delay AM_DLY=14, PM_DLY=1 */
/*MT6169*/    POR_CW157,  /* CW157 : Loop Filter */
/*MT6169*/    POR_CW161,  /* CW161 : STX DEM_chunk=126 */
/*MT6169*/    POR_CW165,  /* CW165 : STX */
/*MT6169*/    POR_CW248,  /* CW248 : DCXO */
/*MT6169*/    POR_CW213,  /* CW213 : */
/*MT6169*/    POR_CW211,  /* CW211 : */
/*MT6169*/    POR_CW188,  /* CW188 : */
/*MT6169*/    POR_CW168,  /* CW168 : */
/*MT6169*/    POR_CW104,  /* CW104 : */
/*MT6169*/    POR_CW220,  /* CW211 : */
/*MT6169*/    POR_CW221,  /* CW188 : */
/*MT6169*/    POR_CW222,  /* CW168 : */
/*MT6169*/    POR_CW224,  /* CW104 : */
/*MT6169*/    POR_CW225,  /* CW168 : */
/*MT6169*/    POR_CW114,  /* CW104 : */
/*MT6169*/    POR_CW21,   /* CW168 : */
/*MT6169*/    POR_CW22,   /* CW104 : */
/*MT6169*/ };
/*MT6169*/ const unsigned long SDATA_TABLE_E3[]=
/*MT6169*/ {
/*MT6169*/    POR_CW83_E3 ,  /* CW83  : */
/*MT6169*/    POR_CW85_E3 ,  /* CW85  : */
/*MT6169*/    POR_CW86 ,     /* CW86  : */
/*MT6169*/    POR_CW87 ,     /* CW87  : */
/*MT6169*/    POR_CW88 ,     /* CW88  : */
/*MT6169*/    POR_CW89 ,     /* CW89  : */
/*MT6169*/    POR_CW90 ,     /* CW90  : */
/*MT6169*/    POR_CW236,     /* CW236 : */
/*MT6169*/    POR_CW237,     /* CW237 : */
/*MT6169*/    POR_CW238_E3,  /* CW238 : */
/*MT6169*/    POR_CW239_E3,  /* CW239 : */
/*MT6169*/    POR_CW240_E3,  /* CW240 : */
/*MT6169*/    POR_CW241_E3,  /* CW241 : */
/*MT6169*/    POR_CW132_E3,
/*MT6169*/    POR_CW248_E3,
/*MT6169*/    POR_CW104_E3,
/*MT6169*/    POR_CW72_E3 ,
/*MT6169*/    POR_CW82_E3 ,
/*MT6169*/    POR_CW51_E3 ,
/*MT6169*/    POR_CW165_E3,
/*MT6169*/    POR_CW167_E3,
/*MT6169*/    POR_CW73_E3 ,
/*MT6169*/ };
/*MT6169*/ #endif
/*MT6169*/ unsigned long MT6169_2G_CHIP_VER;
/*MT6169*/ extern void L1D_DM_Power_Control_Trace( char is_2g, char is_3g );
/*MT6169*/ #if IS_RF_CENTRAL_CONTROL_ENABLE
/*MT6169*/ void  L1D_RF_PowerOn( void )
/*MT6169*/ {
/*MT6169*/    if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6169*/    {
/*MT6169*/       /* RF Power On by MML1 RF central control */
/*MT6169*/       MML1_RF_POWER_ON( l1d_rf2.is_wakeup, MML1_RF_2G );
/*MT6169*/       /* Set the 2G force PWM mode */
/*MT6169*/       L1D_PMIC_ADPT2_PWM_ENABLE( 1 );
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    /* RF Power On Calibration by MML1 RF central control    */
/*MT6169*/    /* But 2G power on init is before LTE power on init      */
/*MT6169*/    /* So Provide L1D_MMRF_SetPowerOnCalibrationData for LTE */
/*MT6169*/    /* to notify 2G to update power on calibration data      */
/*MT6169*/    if( l1d_rf.is_init )
/*MT6169*/    {
/*MT6169*/       IMM_RECEIVE_BSI( SCTRL_IMOD(0,12), 0x00, SCTRL_IMOD(0,20), &(MT6169_2G_CHIP_VER) );
/*MT6169*/       MT6169_2G_CHIP_VER = ( (MT6169_2G_CHIP_VER&0x000F0)>>4 ) ;
/*MT6169*/       if( l1d_rf2.power_on_cal_flag&RCAL_CAL_ON )
/*MT6169*/       {
/*MT6169*/          l1d_rf2.is_power_on_cal |= RCAL_CAL_DONE;
/*MT6169*/       }
/*MT6169*/       MML1_RF_NOTIFY_POC_DONE( MML1_RF_2G );
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    if( !l1d_rf2.is_wakeup )
/*MT6169*/    {  /* Do not remove this part when RF central control turn on. RF central control do not deal with calibration related item */
/*MT6169*/       /* Set AFC DAC to corresponding (CW247/CW254) according to (DCXO mode/TCVCXO mode) */
/*MT6169*/       /* In META mode or L1D_Init2, CAPID and AFC DAC is set by here */
/*MT6169*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), ((l1d_rf.AFC_data<<AFC_SHIFT_PART)&AFC_MASK_PART)|(AFC_VALUE_PART) );
/*MT6169*/    #ifdef AFC_VCXO
/*MT6169*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xF9, ((XO_CapID&0xFF)<<12)|0x008C6) );  //CW249: Set previous Cap ID value
/*MT6169*/    #endif
/*MT6169*/    }
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_PowerOff( void )
/*MT6169*/ {  // Sleep to Phone Standby
/*MT6169*/    /* RF Power Off by RF central control, SW need not send any BSI CW */
/*MT6169*/    #if IS_32K_CRYSTAL_REMOVAL_SUPPORT
/*MT6169*/    {  //Set LPM fractional divider before RF power off
/*MT6169*/       extern unsigned long L1D_GetDCXOFreqLPM(void);
/*MT6169*/       unsigned long dcxo_frac = L1D_GetDCXOFreqLPM();
/*MT6169*/
/*MT6169*/       if( !L1D_RF_Check_32K_XO_Status() )
/*MT6169*/       {
/*MT6169*/          IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xF9, ((XO_CapID&0xFF)<<12)|(dcxo_frac&0xFFF)) );  //CW249: Set previous Cap ID value
/*MT6169*/       }
/*MT6169*/    }
/*MT6169*/    #endif
/*MT6169*/    /* Clear the 2G force PWM mode */
/*MT6169*/    L1D_PMIC_ADPT2_PWM_ENABLE( 0 );
/*MT6169*/    MML1_RF_POWER_OFF( MML1_RF_2G );
/*MT6169*/
/*MT6169*/    #if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
/*MT6169*/    L1D_CustomDynamicDebug();
/*MT6169*/    #endif
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_WindowOn( void )
/*MT6169*/ {
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_WindowOff( void )
/*MT6169*/ {
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void L1D_MMRF_SetPowerOnCalibrationData( RFC_DATABASE_T* pRfcDataBase )
/*MT6169*/ {
/*MT6169*/    /* This function called by MMRF central controllor when LTE's power on cal has done. */
/*MT6169*/    /* Read the calibration results from LTE calibration table provided by LTE           */
/*MT6169*/    /* Power On Calibration */
/*MT6169*/    #if IS_LTE_POWERON_CALIBRATION_ENABLE
/*MT6169*/    l1d_rf2.power_on_cal_flag   = RCAL_CAL_ON | TX_GAINSTEP_CAL_ON | TX_DET_DCOC_CAL_ON | TX_RCF_CAL_ON;
/*MT6169*/    l1d_rf2.calr_const          = 0;         /* RCAL Cal. */
/*MT6169*/    l1d_rf2.calr_tcl_r_m        = 0;         /* RCAL Cal. */
/*MT6169*/    l1d_rf2.txrcf_csel[0]       = 0;         /* TXRCF Cal. */
/*MT6169*/    l1d_rf2.txrcf_csel[1]       = 0;         /* TXRCF Cal. */
/*MT6169*/    if( l1d_rf2.power_on_cal_flag&TX_GAINSTEP_CAL_ON )
/*MT6169*/    {
/*MT6169*/       L1D_RF_TX_GainStep_Cal( pRfcDataBase );
/*MT6169*/       l1d_rf2.is_power_on_cal |= TX_GAINSTEP_CAL_DONE;
/*MT6169*/    }
/*MT6169*/    if( l1d_rf2.power_on_cal_flag&TX_DET_DCOC_CAL_ON )
/*MT6169*/    {
/*MT6169*/       L1D_RF_TX_DET_DCOC_Cal( pRfcDataBase );
/*MT6169*/       l1d_rf2.is_power_on_cal |= TX_DET_DCOC_CAL_DONE;
/*MT6169*/    }
/*MT6169*/    if( l1d_rf2.power_on_cal_flag&TX_RCF_CAL_ON )
/*MT6169*/    {
/*MT6169*/       L1D_RF_TX_RCF_Cal( pRfcDataBase );
/*MT6169*/       l1d_rf2.is_power_on_cal |= TX_RCF_CAL_DONE;
/*MT6169*/    }
/*MT6169*/    #endif
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void L1D_RF_RCAL_Cal( RFC_DATABASE_T* pRfcDataBase )
/*MT6169*/ {
/*MT6169*/    /* RF Power On Calibration by RF Central Control            */
/*MT6169*/    /* RF Central Control will record the RCAL result to HW reg */
/*MT6169*/    /* RCAL result will send to RF triggered by HW engine       */
/*MT6169*/    (void)(pRfcDataBase);
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void L1D_RF_TX_GainStep_Cal( RFC_DATABASE_T* pRfcDataBase )
/*MT6169*/ {
/*MT6169*/    /* RF Power On Calibration by HW Engine       */
/*MT6169*/    /* Read the calibration results from HW REG   */
/*MT6169*/    #if IS_LTE_POWERON_CALIBRATION_ENABLE
/*MT6169*/    unsigned short band_idx, gain_idx, mmmb_band_idx;
/*MT6169*/    unsigned short BAND_NUM[4] = { 5, 8, 3, 2 };
/*MT6169*/
/*MT6169*/    //Get RF Power On K Data from MML1 Structure
/*MT6169*/    for( band_idx=0; band_idx<4; band_idx++)
/*MT6169*/    {
/*MT6169*/       for( mmmb_band_idx=0; mmmb_band_idx<LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND; mmmb_band_idx++)
/*MT6169*/       {
/*MT6169*/          if( BAND_NUM[band_idx] == pRfcDataBase->band_idx_to_band_num_table[mmmb_band_idx] )
/*MT6169*/             break;
/*MT6169*/       }
/*MT6169*/       for( gain_idx=0; gain_idx<28; gain_idx++)
/*MT6169*/       {
/*MT6169*/          l1d_rf2.Gvga_rf[band_idx][gain_idx]=(pRfcDataBase->tx_gain_table[mmmb_band_idx][gain_idx])>>3;
/*MT6169*/       }
/*MT6169*/    }
/*MT6169*/    #else
/*MT6169*/    (void)(pRfcDataBase);
/*MT6169*/    #endif
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void L1D_RF_TX_DET_DCOC_Cal( RFC_DATABASE_T* pRfcDataBase )
/*MT6169*/ {
/*MT6169*/    /* RF Power On Calibration by HW Engine       */
/*MT6169*/    /* Read the calibration results from HW REG   */
/*MT6169*/
/*MT6169*/    //Get RF Power On K Data from MML1 Structure
/*MT6169*/    (void)(pRfcDataBase);
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void L1D_RF_TX_RCF_Cal( RFC_DATABASE_T* pRfcDataBase )
/*MT6169*/ {
/*MT6169*/    /* RF Power On Calibration by HW Engine       */
/*MT6169*/    /* Read the calibration results from HW REG   */
/*MT6169*/
/*MT6169*/    //Get RF Power On K Data from MML1 Structure
/*MT6169*/    l1d_rf2.txrcf_csel[0] = pRfcDataBase->tx_rcf_csel[0];
/*MT6169*/    l1d_rf2.txrcf_csel[1] = pRfcDataBase->tx_rcf_csel[1];
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ #else
/*MT6169*/ void  L1D_RF_PowerOn( void )
/*MT6169*/ {
/*MT6169*/    unsigned short i;
/*MT6169*/    unsigned short BSI_num=0;
/*MT6169*/    unsigned long  cw0;
/*MT6169*/    unsigned long  cw141,cw143;
/*MT6169*/    #if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__)
/*MT6169*/    unsigned long _savedMask;
/*MT6169*/    #endif
/*MT6169*/
/*MT6169*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6169*/
/*MT6169*/    if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6169*/    {
/*MT6169*/       if( l1d_rf.is_init )
/*MT6169*/       {
/*MT6169*/          L1D_PMU_VRF18HWModeSelect(  );                               /* Configure VRF18 srclken sel            */
/*MT6169*/          L1D_PMU_VRF18ModeSetting( 1 );                               /* Configure VDD_18 to be HW mode         */
/*MT6169*/          WAIT_TIME_QB(300);                                           /* Wait 277us for PMIC                    */
/*MT6169*/          L1D_PMU_VRF18Setting( 1 );                                   /* Enable VDD_18 (controlled by PMIC)     */
/*MT6169*/          l1d_rf2.is_2g_on = 2;                                        /* Record the PMU step                    */
/*MT6169*/          L1D_PMU_VRF28Setting( 1 );                                   /* Enable VDD_28 (controlled by PMIC)     */
/*MT6169*/          l1d_rf2.is_2g_on = 4;                                        /* Record the PMU step                    */
/*MT6169*/
/*MT6169*/          /* POR regardless of init or wake up use the same sequence */
/*MT6169*/          SPECIAL_IMM_RECEIVE_BSI( SCTRL_IMOD(0,12), 0x00, SCTRL_IMOD(0,20), &(cw0) );
/*MT6169*/          IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x00, 0x80000) );     //CW0  : SOR
/*MT6169*/
/*MT6169*/          IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x01, 0x00240) );     //CW1  : D[6] Enable DYN digital macro (DYN_EN=1)
/*MT6169*/          WAIT_TIME_QB(120);                                           //wait 110us
/*MT6169*/
/*MT6169*/          IMM_RECEIVE_BSI( SCTRL_IMOD(0,12), 0x00, SCTRL_IMOD(0,20), &(MT6169_2G_CHIP_VER) );
/*MT6169*/          MT6169_2G_CHIP_VER = ( (MT6169_2G_CHIP_VER&0x000F0)>>4 ) ;
/*MT6169*/          if( ( MT6169_2G_CHIP_VER == MT6169_E3 ) )
/*MT6169*/          {
/*MT6169*/             BSI_num = RF_POR_NUM_E3;
/*MT6169*/
/*MT6169*/             for( i=0 ; i<BSI_num; i++ )
/*MT6169*/             {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_TABLE_E3[i] );
/*MT6169*/             }
/*MT6169*/          }
/*MT6169*/          else
/*MT6169*/          {
/*MT6169*/             BSI_num = RF_POR_NUM;
/*MT6169*/
/*MT6169*/             for( i=0 ; i<BSI_num; i++ )
/*MT6169*/             {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_TABLE[i] );
/*MT6169*/             }
/*MT6169*/          }
/*MT6169*/          L1D_RF_SetClockControl();
/*MT6169*/
/*MT6169*/          l1d_rf2.is_2g_on = 1;                                        /* set 2G flag to notify 2G is ON */
/*MT6169*/          L1D_DM_Power_Control_Trace( 1, 2 );                          /* indicate the init state */
/*MT6169*/
/*MT6169*/    #if IS_AST3002_SUPPORT
/*MT6169*/          L1D_RF_SET_2G_POWER_STATUS( 1 );
/*MT6169*/    #endif
/*MT6169*/       }
/*MT6169*/       else
/*MT6169*/       {
/*MT6169*/    #if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__)
/*MT6169*/          extern char UL1D_RF_CheckDMPower( void );                    /* check 3g RF flag */
/*MT6169*/          _savedMask = SaveAndSetIRQMask();                            /* disable interrupt */
/*MT6169*/    #endif
/*MT6169*/
/*MT6169*/    #if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__)
/*MT6169*/          if( UL1D_RF_CheckDMPower() )                                 /* 3G is already ON, so 2G does not do the power-on reset */
/*MT6169*/          {
/*MT6169*/             l1d_rf2.is_2g_on = 1;                                     /* set 2G flag to notify 2G is ON */
/*MT6169*/             L1D_DM_Power_Control_Trace( 1, 1 );                       /* indicate 2G is ON and 3G is ON */
/*MT6169*/             RestoreIRQMask(_savedMask);                               /* enable interrupt */
/*MT6169*/          }
/*MT6169*/          else
/*MT6169*/    #endif
/*MT6169*/    #if IS_AST3002_SUPPORT
/*MT6169*/          if( L1D_RF_CHECK_TDD_POWER( 1 ) )                            /* 3G is already ON, so 2G does not do the power-on reset */
/*MT6169*/          {
/*MT6169*/             l1d_rf2.is_2g_on = 1;                                     /* set 2G flag to notify 2G is ON */
/*MT6169*/             L1D_DM_Power_Control_Trace( 1, 1 );                       /* indicate 2G is ON and 3G is ON */
/*MT6169*/          }
/*MT6169*/          else
/*MT6169*/    #endif
/*MT6169*/          {
/*MT6169*/             l1d_rf2.is_2g_on = 1;                                     /* set 2G flag to notify 2G is ON */
/*MT6169*/             L1D_DM_Power_Control_Trace( 1, 0 );                       /* indicate 2G is ON and 3G is OFF */
/*MT6169*/    #if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__)
/*MT6169*/             RestoreIRQMask(_savedMask);                               /* enable interrupt */
/*MT6169*/    #endif
/*MT6169*/             L1D_PMU_VRF18Setting( 1 );                                /* Enable VDD_18 (controlled by PMIC) */
/*MT6169*/             l1d_rf2.is_2g_on = 3;                                     /* Record the PMU step                */
/*MT6169*/             L1D_PMU_VRF28Setting( 1 );                                /* Enable VDD_28 (controlled by PMIC) */
/*MT6169*/             l1d_rf2.is_2g_on = 5;                                     /* Record the PMU step                */
/*MT6169*/
/*MT6169*/             /* POR regardless of init or wake up use the same sequence */
/*MT6169*/             IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x01, 0x00240) );  //CW1  : D[6] Enable DYN digital macro (DYN_EN=1)
/*MT6169*/             WAIT_TIME_QB(120);                                        //wait 110us
/*MT6169*/
/*MT6169*/             if( ( MT6169_2G_CHIP_VER == MT6169_E3 ) )
/*MT6169*/             {
/*MT6169*/                BSI_num = RF_POR_NUM_E3;
/*MT6169*/
/*MT6169*/                for( i=0 ; i<BSI_num; i++ )
/*MT6169*/                {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_TABLE_E3[i] );
/*MT6169*/                }
/*MT6169*/             }
/*MT6169*/             else
/*MT6169*/             {
/*MT6169*/                BSI_num = RF_POR_NUM;
/*MT6169*/
/*MT6169*/                for( i=0 ; i<BSI_num; i++ )
/*MT6169*/                {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_TABLE[i] );
/*MT6169*/                }
/*MT6169*/             }
/*MT6169*/             L1D_RF_SetClockControl();
/*MT6169*/          }
/*MT6169*/       }
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    if( !l1d_rf2.is_wakeup )
/*MT6169*/    {  /* Do not remove this part when RF central control turn on. RF central control do not deal with calibration related item */
/*MT6169*/       /* Set AFC DAC to corresponding (CW247/CW254) according to (DCXO mode/TCVCXO mode) */
/*MT6169*/       /* In META mode or L1D_Init2, CAPID and AFC DAC is set by here */
/*MT6169*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), ((l1d_rf.AFC_data<<AFC_SHIFT_PART)&AFC_MASK_PART)|(AFC_VALUE_PART) );
/*MT6169*/    #ifdef AFC_VCXO
/*MT6169*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xF9, ((XO_CapID&0xFF)<<12)|0x008C6) );  //CW249: Set previous Cap ID value
/*MT6169*/    #endif
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    if( l1d_rf.is_init )
/*MT6169*/    {
/*MT6169*/       /* Power On Calibration */
/*MT6169*/       if( l1d_rf2.power_on_cal_flag&RCAL_CAL_ON )
/*MT6169*/       {
/*MT6169*/          L1D_RF_RCAL_Cal();
/*MT6169*/          l1d_rf2.is_power_on_cal |= RCAL_CAL_DONE;
/*MT6169*/       }
/*MT6169*/       if( l1d_rf2.power_on_cal_flag&TX_GAINSTEP_CAL_ON )
/*MT6169*/       {
/*MT6169*/          L1D_RF_TX_GainStep_Cal();
/*MT6169*/          l1d_rf2.is_power_on_cal |= TX_GAINSTEP_CAL_DONE;
/*MT6169*/       }
/*MT6169*/       if( l1d_rf2.power_on_cal_flag&TX_DET_DCOC_CAL_ON )
/*MT6169*/       {
/*MT6169*/          L1D_RF_TX_DET_DCOC_Cal();
/*MT6169*/          l1d_rf2.is_power_on_cal |= TX_DET_DCOC_CAL_DONE;
/*MT6169*/       }
/*MT6169*/       if( l1d_rf2.power_on_cal_flag&TX_RCF_CAL_ON )
/*MT6169*/       {
/*MT6169*/          L1D_RF_TX_RCF_Cal();
/*MT6169*/          l1d_rf2.is_power_on_cal |= TX_RCF_CAL_DONE;
/*MT6169*/       }
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    /* Write back the Calibration value to the register */
/*MT6169*/    if( (l1d_rf2.is_power_on_cal)&(RCAL_CAL_DONE) )
/*MT6169*/    {
/*MT6169*/       /* Re-write RCAL Value */
/*MT6169*/       cw141 = ( POR_CW141&(~(CALR_CONST_MASK  <<10)) ) | ( (l1d_rf2.calr_const  &CALR_CONST_MASK  )<<10 ) | RG_CALR_MAN_ON;
/*MT6169*/       cw143 = ( POR_CW143&(~(CALR_TCL_R_M_MASK<<15)) ) | ( (l1d_rf2.calr_tcl_r_m&CALR_TCL_R_M_MASK)<<15 );
/*MT6169*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x8D, cw141) );  //CW141 : Set RG_CALR_MAN=1, write back D14-D10: RG_CALR_CONST_M[4:0]
/*MT6169*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x8F, cw143) );  //CW143 : write back CW143 D19-D15: RG_CALR_TCL_R_M[4:0]
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    IMM_MODE_END(  );
/*MT6169*/
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_PowerOff( void )
/*MT6169*/ {  // Sleep to Phone Standby
/*MT6169*/    #if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__)
/*MT6169*/    unsigned long _savedMask;
/*MT6169*/    #endif
/*MT6169*/
/*MT6169*/    IMM_MODE_BEGIN( IMMMASK_BSI );
/*MT6169*/
/*MT6169*/    #if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__)
/*MT6169*/    extern char UL1D_RF_CheckDMPower( void );                   /* check 3g RF flag */
/*MT6169*/    _savedMask = SaveAndSetIRQMask();                           /* disable interrupt */
/*MT6169*/    #endif
/*MT6169*/
/*MT6169*/    #if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__)
/*MT6169*/    if( UL1D_RF_CheckDMPower() )                                /* 3G is still ON, so 2G can not do the power-off sequence */
/*MT6169*/    {
/*MT6169*/       l1d_rf2.is_2g_on = 0;                                    /* clear 2G flag to notify 2G is OFF */
/*MT6169*/       L1D_DM_Power_Control_Trace( 0, 1 );                      /* indicate 2G is OFF and 3G is ON */
/*MT6169*/       RestoreIRQMask(_savedMask);                              /* enable interrupt */
/*MT6169*/    }
/*MT6169*/    else                                                        /* 3G is already OFF, so 2G does the power-off sequence */
/*MT6169*/    #endif
/*MT6169*/    #if IS_AST3002_SUPPORT
/*MT6169*/    if( L1D_RF_CHECK_TDD_POWER( 0 ) )                           /* 3G is already ON, so 2G does not do the power-on reset */
/*MT6169*/    {
/*MT6169*/       l1d_rf2.is_2g_on = 0;                                    /* set 2G flag to notify 2G is ON */
/*MT6169*/       L1D_DM_Power_Control_Trace( 0, 1 );                      /* indicate 2G is ON and 3G is ON */
/*MT6169*/    }
/*MT6169*/    else
/*MT6169*/    #endif
/*MT6169*/    {
/*MT6169*/    #if IS_32K_CRYSTAL_REMOVAL_SUPPORT
/*MT6169*/       {  //Set LPM fractional divider before RF power off
/*MT6169*/          extern unsigned long L1D_GetDCXOFreqLPM(void);
/*MT6169*/          unsigned long dcxo_frac = L1D_GetDCXOFreqLPM();
/*MT6169*/
/*MT6169*/          if( !L1D_RF_Check_32K_XO_Status() )
/*MT6169*/          {
/*MT6169*/             IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xF9, ((XO_CapID&0xFF)<<12)|(dcxo_frac&0xFFF)) );  //CW249: Set previous Cap ID value
/*MT6169*/          }
/*MT6169*/       }
/*MT6169*/    #endif
/*MT6169*/       l1d_rf2.is_2g_on = 0;                                    /* clear 2G flag to notify 2G is OFF */
/*MT6169*/       L1D_DM_Power_Control_Trace( 0, 0 );                      /* indicate 2G is OFF and 3G is OFF */
/*MT6169*/    #if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__)
/*MT6169*/       RestoreIRQMask(_savedMask);                              /* enable interrupt */
/*MT6169*/    #endif
/*MT6169*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x01, 0x00200) ); //CW1  : DYN_EN=0
/*MT6169*/       L1D_PMU_VRF18Setting( 0 );                               /* Disable VDD_18 (controlled by PMIC) */
/*MT6169*/       l1d_rf2.is_2g_on = 6;                                    /* Record the PMU step                 */
/*MT6169*/       L1D_PMU_VRF28Setting( 0 );                               /* Disable VDD_28 (controlled by PMIC) */
/*MT6169*/       l1d_rf2.is_2g_on = 8;                                    /* Record the PMU step                 */
/*MT6169*/    }
/*MT6169*/
/*MT6169*/    IMM_MODE_END(  );
/*MT6169*/
/*MT6169*/    #if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
/*MT6169*/    L1D_CustomDynamicDebug();
/*MT6169*/    #endif
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_WindowOn( void )
/*MT6169*/ {
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void  L1D_RF_WindowOff( void )
/*MT6169*/ {
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void L1D_RF_RCAL_Cal( void )
/*MT6169*/ {
/*MT6169*/    unsigned long  cw142;
/*MT6169*/    unsigned long  cw1 = 0;
/*MT6169*/
/*MT6169*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6169*/
/*MT6169*/    cw1 = RXCAL_MODE_FDD | MODE_3_4G | POR_CW1;                 // CW1  , use WCDMA RX cal mode
/*MT6169*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x01, cw1) );
/*MT6169*/    WAIT_TIME_QB( 55 );                                         // wait 50us
/*MT6169*/
/*MT6169*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x8D, 0x0411C) );    // CW141 D[18], RSEL=0 (for one type R); D[8], RCAL_START_TRG=1 enable R-cal function
/*MT6169*/                                                                // automatically turn-off after finishing the calibration
/*MT6169*/    WAIT_TIME_QB( 11 );                                         // wait 10us ( total calibration time is less than10us)
/*MT6169*/
/*MT6169*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x8D, 0x4411C) );    // CW141 D[18], RSEL=1 (for another type R); D[8], RCAL_START_TRG=1 enable R-cal function
/*MT6169*/                                                                // automatically turn-off after finishing the calibration
/*MT6169*/    WAIT_TIME_QB( 11 );                                         // wait 10us ( total calibration time is less than10us)
/*MT6169*/
/*MT6169*/    IMM_RECEIVE_BSI( SCTRL_IMOD(0,12), 0x8E, SCTRL_IMOD(0,20), &(cw142) );
/*MT6169*/    l1d_rf2.calr_const   = ( cw142&(CALR_CONST_MASK  <<3) )>>3; // RG_CALR_CONST[4:0]
/*MT6169*/    l1d_rf2.calr_tcl_r_m = ( cw142&(CALR_TCL_R_M_MASK<<8) )>>8; // RG_CALR_TCL_R_M[4:0]
/*MT6169*/
/*MT6169*/    cw1 = RXSLEEP_MODE_FDD | MODE_3_4G | POR_CW1;               // CW1  , Set WCDMA RX sleep mode
/*MT6169*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x01, cw1) );
/*MT6169*/
/*MT6169*/    IMM_MODE_END( );
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void L1D_RF_TX_GainStep_Cal( void )
/*MT6169*/ {
/*MT6169*/    /* Can not do TX calibration by 2G mode       */
/*MT6169*/    /* Set default value to bypass this condition */
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void L1D_RF_TX_DET_DCOC_Cal( void )
/*MT6169*/ {
/*MT6169*/    /* Can not do TX calibration by 2G mode       */
/*MT6169*/    /* Set default value to bypass this condition */
/*MT6169*/ }
/*MT6169*/
/*MT6169*/ void L1D_RF_TX_RCF_Cal( void )
/*MT6169*/ {
/*MT6169*/    /* Can not do TX calibration by 2G mode       */
/*MT6169*/    /* Set default value to bypass this condition */
/*MT6169*/    l1d_rf2.txrcf_csel[0] = 0x20;
/*MT6169*/    l1d_rf2.txrcf_csel[1] = 0x20;
/*MT6169*/ }
/*MT6169*/ #endif
/*MT6169*/
#endif

#if IS_RF_MT6166
/*MT6166*/
/*MT6166*/ #include "intrCtrl.h"
/*MT6166*/
/*MT6166*/
/*MT6166*/ #define CAL_BAND_NUM     4
/*MT6166*/ #define RF_POR_NUM       (sizeof(SDATA_TABLE) /sizeof(unsigned long))
/*MT6166*/ #define MAX_RETRY_TIMES  20           // for TX gain step cal. unstable issue SW workaround
/*MT6166*/
/*MT6166*/ #define BAND_MASK        0x0000003FL  //  6 bits length
/*MT6166*/ #define GAIN_MEAS_MASK   0x00000FFFL  // 12 bits length
/*MT6166*/
/*MT6166*//* CW201 : Mode */
/*MT6166*/ #define SLEEP_MODE       (0x0<<15)
/*MT6166*/ #define RXCAL_MODE_2G    (0x1<<15)
/*MT6166*/ #define RXBURST_MODE_2G  (0x2<<15)
/*MT6166*/ #define TXCAL_MODE_2G    (0x3<<15)
/*MT6166*/ #define TXBURST_MODE_2G  (0x4<<15)
/*MT6166*/
/*MT6166*/ #define POR_CW201        0x0C900208L /* set DYN_EN=1 and Band=Band 1 */
/*MT6166*/
/*MT6166*/ /* Set CW default power on value include addr */
/*MT6166*/ /* POR default value */
/*MT6166*/ #define POR_CW13         0x00D00000L
/*MT6166*/ #define POR_CW49         0x03140035L
/*MT6166*/ #define POR_CW62         0x03E0000FL
/*MT6166*/ #define POR_CW63         0x03F00104L//0x03F000ECL
/*MT6166*/ #define POR_CW64         0x0400015EL//0x0400014AL
/*MT6166*/ #define POR_CW65         0x04100172L
/*MT6166*/ #define POR_CW66         0x04200488L
/*MT6166*/ #define POR_CW67         0x0430000FL
/*MT6166*/ #define POR_CW68         0x04400104L
/*MT6166*/ #define POR_CW69         0x0450015EL
/*MT6166*/ #define POR_CW70         0x04600172L
/*MT6166*/ #define POR_CW71         0x0470023AL
/*MT6166*/ #define POR_CW151        0x0971AC00L
/*MT6166*/ #define POR_CW244        0x0F4FFFFEL
/*MT6166*/ #define POR_CW2          0x00271000L
/*MT6166*/ #define POR_CW6          0x00634024L
/*MT6166*/ #define POR_CW135        0x087AB6A2L
/*MT6166*/ #define POR_CW136        0x088A8C90L
/*MT6166*/ #define POR_CW3          0x00300052L
/*MT6166*/ #define POR_CW228        0x0E4B8000L
/*MT6166*/ #define POR_CW232        0x0E8CD01CL
/*MT6166*/ #define POR_CW238        0x0EE8B4A9L
/*MT6166*/ #define POR_CW239        0x0EFCF37AL
/*MT6166*/ #define POR_CW241        0x0F1294A5L
/*MT6166*/ #define POR_CW8          0x00802B95L
/*MT6166*/ #define POR_CW242        0x0F208DFBL
/*MT6166*/ #define POR_CW90         0x05A25050L
/*MT6166*/ #define POR_CW245        0x0F5801D8L
/*MT6166*/ #define POR_CW175        0x0AF53540L
/*MT6166*/ #define POR_CW176        0x0B012440L
/*MT6166*/ #define POR_CW180        0x0B4094ADL
/*MT6166*/ #define POR_CW184        0x0B812D6AL
/*MT6166*/ #define POR_CW82         0x05200460L
/*MT6166*/ #define POR_CW137        0x0898D000L
/*MT6166*/
/*MT6166*/ const unsigned long SDATA_TABLE[]=
/*MT6166*/ {
/*MT6166*/    POR_CW99,   /* solve the sub-band calibration error at Nfrac=0.5 problem , which comes from digital rounding error */
/*MT6166*/    POR_CW244,  /* apply internal buffers all on */
/*MT6166*/    POR_CW13,   /* I/Q CAL will be never performed for 2G */
/*MT6166*/    POR_CW151,  /* I/Q CAL will be never performed for 2G; advance T48 from 155us to 107us */
/*MT6166*/    POR_CW62,   /* set t67=0 */
/*MT6166*/    POR_CW63,   /* set t67=0,change t63 setting */
/*MT6166*/    POR_CW64,   /* set t68=0,change t64 setting */
/*MT6166*/    POR_CW65,   /* set t68=0,change t65 setting */
/*MT6166*/    POR_CW66,   /* change t66 setting */
/*MT6166*/    POR_CW67,   /* set t77=0 */
/*MT6166*/    POR_CW68,   /* set t77=0,change t73 setting */
/*MT6166*/    POR_CW69,   /* set t78=0,change t74 setting */
/*MT6166*/    POR_CW70,   /* set t78=0,change t75 setting */
/*MT6166*/    POR_CW71,   /* set t78=0,change t76 setting */
/*MT6166*/    POR_CW49,   /* solve slice_LSB_EN issue */
/*MT6166*/    POR_CW117,  /* 2G PM path delay setting, 2G AM path delay setting */
/*MT6166*/    POR_CW2,    /* optimize 2G performance */
/*MT6166*/    POR_CW6,    /* optimize 2G performance */
/*MT6166*/    POR_CW135,  /* change cascode bias for OBB margin */
/*MT6166*/    POR_CW136,  /* change cascode bias for OBB margin */
/*MT6166*/    POR_CW3,    /* modify GSLDO output voltage to 1.2V */
/*MT6166*/    POR_CW228,  /* Change VDD of PFDCP, Divider and VCO */
/*MT6166*/    POR_CW232,  /* Change FDD VCO ACAL Target */
/*MT6166*/    POR_CW238,  /* Change FDD loop parameter */
/*MT6166*/    POR_CW239,  /* Change TDD loop parameter */
/*MT6166*/    POR_CW241,  /* Change TDD loop parameter */
/*MT6166*/    POR_CW8,    /* Change TTG charge pump current */
/*MT6166*/    POR_CW242,  /* Change SRX TCL setting to align THAD and VCO coefficient */
/*MT6166*/    POR_CW90,   /* solve the sub-band calibration frequency error induced TDC range is not enough issue*/
/*MT6166*/    POR_CW245,  /* compensate the temp sensor output code offset */
/*MT6166*/    POR_CW175,  /* Tx cal adjustment*/
/*MT6166*/    POR_CW176,  /* Tx cal adjustment*/
/*MT6166*/    POR_CW180,  /* Tx cal adjustment*/
/*MT6166*/    POR_CW184,  /* Tx cal adjustment*/
/*MT6166*/    POR_CW82,   /* STX loop bandwidth setting */
/*MT6166*/    POR_CW137,  /* OBB detection threshold to avoid false alarm */
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ const int MIDBAND_ARFCN[4]=
/*MT6166*/ {
/*MT6166*/    189, /* approx. mid Band arfcn of GSM850  */
/*MT6166*/     37, /* approx. mid Band arfcn of GSM900  */
/*MT6166*/    698, /* approx. mid Band arfcn of DCS1800 */
/*MT6166*/    661, /* approx. mid Band arfcn of PCS1900 */
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ const unsigned long TXGAINSTEP_CAL_CW41_LB_TABLE[14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6166*/ {  /*   1st     2nd   */
/*MT6166*/    { 0x24780, 0x23F80 },
/*MT6166*/    { 0x23F80, 0x23780 },
/*MT6166*/    { 0x23780, 0x22F80 },
/*MT6166*/    { 0x22F80, 0x22780 },
/*MT6166*/    { 0x22780, 0x2A700 },
/*MT6166*/    { 0x2A700, 0x21F80 },
/*MT6166*/    { 0x21F80, 0x21780 },
/*MT6166*/    { 0x21780, 0x4A180 },
/*MT6166*/    { 0x4A180, 0x49180 },
/*MT6166*/    { 0x49180, 0x51080 },
/*MT6166*/    { 0x51080, 0x50880 },
/*MT6166*/    { 0x50880, 0xD0004 },
/*MT6166*/    { 0xD0004, 0xD0044 },
/*MT6166*/    { 0xB8044, 0xB8064 },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ const unsigned long TXGAINSTEP_CAL_CW42_LB_TABLE[14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6166*/ {  /*   1st     2nd   */
/*MT6166*/    { 0x40520, 0x40520 },
/*MT6166*/    { 0x43560, 0x43560 },
/*MT6166*/    { 0x465A0, 0x465A0 },
/*MT6166*/    { 0x495E0, 0x495E0 },
/*MT6166*/    { 0x4C620, 0x4C620 },
/*MT6166*/    { 0x49440, 0x49440 },
/*MT6166*/    { 0x4C480, 0x4C480 },
/*MT6166*/    { 0x52500, 0x52500 },
/*MT6166*/    { 0x58580, 0x58580 },
/*MT6166*/    { 0x58580, 0x58580 },
/*MT6166*/    { 0x5E600, 0x5E600 },
/*MT6166*/    { 0x5E600, 0x5E60F },
/*MT6166*/    { 0x9E48F, 0x9E488 },
/*MT6166*/    { 0x9E488, 0x9E484 },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ const unsigned long TXGAINSTEP_CAL_CW36_LB_TABLE[14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6166*/ {  /*   1st     2nd   */
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x149AC, 0x149AC },
/*MT6166*/    { 0x149AC, 0x149AC },
/*MT6166*/    { 0x0C9AC, 0x0C9AC },
/*MT6166*/    { 0x049AC, 0x049AC },
/*MT6166*/    { 0x049AC, 0x049AC },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ const unsigned long TXGAINSTEP_CAL_CW41_HB_TABLE[14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6166*/ {  /*   1st     2nd   */
/*MT6166*/    { 0x54780, 0x53F80 },
/*MT6166*/    { 0x53F80, 0x53780 },
/*MT6166*/    { 0x53780, 0x52F80 },
/*MT6166*/    { 0x52F80, 0x52780 },
/*MT6166*/    { 0x52780, 0x63B80 },
/*MT6166*/    { 0x63B80, 0x63380 },
/*MT6166*/    { 0x63380, 0x62380 },
/*MT6166*/    { 0x62380, 0x6A180 },
/*MT6166*/    { 0x6A180, 0x69180 },
/*MT6166*/    { 0x69180, 0x71080 },
/*MT6166*/    { 0x71080, 0x70880 },
/*MT6166*/    { 0x70880, 0xF0004 },
/*MT6166*/    { 0xF0004, 0xF0044 },
/*MT6166*/    { 0xD8044, 0xD8064 },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ const unsigned long TXGAINSTEP_CAL_CW42_HB_TABLE[14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6166*/ {  /*   1st     2nd   */
/*MT6166*/    { 0x40520, 0x40520 },
/*MT6166*/    { 0x43560, 0x43560 },
/*MT6166*/    { 0x465A0, 0x465A0 },
/*MT6166*/    { 0x495E0, 0x495E0 },
/*MT6166*/    { 0x4C620, 0x4C620 },
/*MT6166*/    { 0x49440, 0x49440 },
/*MT6166*/    { 0x4C480, 0x4C480 },
/*MT6166*/    { 0x52500, 0x52500 },
/*MT6166*/    { 0x58580, 0x58580 },
/*MT6166*/    { 0x58580, 0x58580 },
/*MT6166*/    { 0x5E600, 0x5E600 },
/*MT6166*/    { 0x5E600, 0x5E60F },
/*MT6166*/    { 0x9E48F, 0x9E488 },
/*MT6166*/    { 0x9E488, 0x9E484 },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ const unsigned long TXGAINSTEP_CAL_CW36_HB_TABLE[14/*Cal. Sequence*/][2/*Gain Index*/]=
/*MT6166*/ {  /*   1st     2nd   */
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x1C9AC, 0x1C9AC },
/*MT6166*/    { 0x149AC, 0x149AC },
/*MT6166*/    { 0x149AC, 0x149AC },
/*MT6166*/    { 0x0C9AC, 0x0C9AC },
/*MT6166*/    { 0x049AC, 0x049AC },
/*MT6166*/    { 0x049AC, 0x049AC },
/*MT6166*/ };
/*MT6166*/
/*MT6166*/ const signed short GBB1_LB   [14] = {  -18,  -80,  -80,  -80,  -80, -105,  -80,  -80, -230,  -230,  -273,  -273,  -273,  -273 };
/*MT6166*/ const signed short GBB1_HB   [14] = { -105, -273, -273, -273, -273, -386, -386, -386, -466,  -466,  -578,  -578,  -578,  -578 };
/*MT6166*/ const signed short GVGARF_LB [14] = { -348, -442, -480, -527, -586, -621, -664, -774, -914, -1103, -1285, -1478, -1653, -1855 };
/*MT6166*/ const signed short GVGARF_HB [14] = { -306, -503, -542, -590, -650, -693, -735, -846,-1042, -1233, -1490, -1682, -1866, -2070 };
/*MT6166*/ extern const unsigned long  SDATA_BAND_SEL[5];
/*MT6166*/
/*MT6166*/ extern void L1D_DM_Power_Control_Trace( char is_2g, char is_3g );
/*MT6166*/ void  L1D_RF_PowerOn( void )
/*MT6166*/ {
/*MT6166*/    unsigned short i;
/*MT6166*/    unsigned short BSI_num=0;
/*MT6166*/    unsigned long  cw0;
/*MT6166*/ #if defined(__UMTS_RAT__)&& defined ( __UMTS_FDD_MODE__ )
/*MT6166*/    unsigned long _savedMask;
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6166*/
/*MT6166*/ #if IS_DUAL_TALK_SUPPORT
/*MT6166*/    /* RF Power On by MML1 RF central control */
/*MT6166*/    MML1_RF_POWER_ON( l1d_rf2.is_wakeup, MML1_RF_2G );
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/    if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6166*/    {
/*MT6166*/       if( l1d_rf.is_init )
/*MT6166*/       {
/*MT6166*/ #if IS_DUAL_TALK_SUPPORT
/*MT6166*/ #else
/*MT6166*/          IMM_SEND_BPI( 0x20000 );        /* Set BSI switch owner to be 2G */
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ #if IS_DUAL_TALK_SUPPORT
/*MT6166*/          L1D_PMU_VRF18HWModeSelect(  );                               /* Configure VRF18 srclken sel for dual talk       */
/*MT6166*/          L1D_PMU_VRF18ModeSetting( 0 );  /* 0: enable  */ /* Configure VDD_18 to be SW mode         */
/*MT6166*/          WAIT_TIME_QB(300);                                           /* Wait 277us for PMIC                    */
/*MT6166*/          L1D_PMU_VRF18Setting( 1 );                                   /* Enable VDD_18 (controlled by PMIC)     */
/*MT6166*/          WAIT_TIME_QB(220);                                           /* Wait 200us for PMIC                    */
/*MT6166*/          L1D_PMIC_ADPT2_PWM_ENABLE( 1 );                              /* FPWM */
/*MT6166*/ #else
/*MT6166*/          L1D_PMU_VRF18HWModeSelect(  );                               /* Configure VRF18 srclken sel for dual talk       */
/*MT6166*/          L1D_PMU_VRF18ModeSetting( 1 );  /* 1: enable with SRCLKEN */ /* Configure VDD_18 to be HW mode         */
/*MT6166*/          WAIT_TIME_QB(300);                                           /* Wait 277us for PMIC                    */
/*MT6166*/          L1D_PMU_VRF18Setting( 1 );                                   /* Enable VDD_18 (controlled by PMIC)     */
/*MT6166*/ #endif
/*MT6166*/          L1D_PMU_LPModeSetting( 1 );                                  /* Configure low power mode to be SW mode */
/*MT6166*/          l1d_rf2.is_2g_on = 2;                                        /* Record the PMU step                    */
/*MT6166*/          L1D_PMU_VRF28Setting( 1 );                                   /* Enable VDD_28 (controlled by PMIC)     */
/*MT6166*/          L1D_PMU_LPSetting( 0 );                                      /* Configure LPM to be normal mode        */
/*MT6166*/          l1d_rf2.is_2g_on = 4;                                        /* Record the PMU step                    */
/*MT6166*/
/*MT6166*/          /* POR regardless of init or wake up use the same sequence */
/*MT6166*/          SPECIAL_IMM_RECEIVE_BSI( SCTRL_IMOD(0,12), 0x00, SCTRL_IMOD(0,20), &(cw0) );
/*MT6166*/          IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x00, 0x81116) );     //CW0  : SOR
/*MT6166*/          WAIT_TIME_QB(324);                                           //wait 300us
/*MT6166*/
/*MT6166*/          L1D_RF_Power_On_Sequence();
/*MT6166*/
/*MT6166*/          BSI_num = RF_POR_NUM;
/*MT6166*/
/*MT6166*/          for( i=0 ; i<BSI_num; i++ )
/*MT6166*/          {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_TABLE[i] );
/*MT6166*/          }
/*MT6166*/
/*MT6166*/          L1D_RF_SetClockControl();
/*MT6166*/
/*MT6166*/          l1d_rf2.is_2g_on = 1;                                        /* set 2G flag to notify 2G is ON */
/*MT6166*/
/*MT6166*/          L1D_DM_Power_Control_Trace( 1, 2 );                          /* indicate the init state */
/*MT6166*/
/*MT6166*/ #if IS_AST3002_SUPPORT
/*MT6166*/    #if IS_DUAL_TALK_SUPPORT
/*MT6166*/    #else
/*MT6166*/          L1D_RF_SET_2G_POWER_STATUS( 1 );
/*MT6166*/          IMM_SEND_BPI( 0x00000 );        /* Set BSI switch owner to be 2G */
/*MT6166*/    #endif
/*MT6166*/ #endif
/*MT6166*/       }
/*MT6166*/       else
/*MT6166*/       {
/*MT6166*/ #if defined(__UMTS_RAT__)&& defined ( __UMTS_FDD_MODE__ )
/*MT6166*/          extern char UL1D_RF_CheckDMPower( void );                    /* check 3g RF flag */
/*MT6166*/          _savedMask = SaveAndSetIRQMask();                            /* disable interrupt */
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ #if defined(__UMTS_RAT__)&& defined ( __UMTS_FDD_MODE__ )
/*MT6166*/          if( UL1D_RF_CheckDMPower() )                                 /* 3G is already ON, so 2G does not do the power-on reset */
/*MT6166*/          {
/*MT6166*/             l1d_rf2.is_2g_on = 1;                                     /* set 2G flag to notify 2G is ON */
/*MT6166*/             L1D_DM_Power_Control_Trace( 1, 1 );                       /* indicate 2G is ON and 3G is ON */
/*MT6166*/             RestoreIRQMask(_savedMask);                               /* enable interrupt */
/*MT6166*/          }
/*MT6166*/          else
/*MT6166*/ #endif
/*MT6166*/ #if IS_AST3002_SUPPORT
/*MT6166*/    #if IS_DUAL_TALK_SUPPORT
/*MT6166*/    #else
/*MT6166*/          if( L1D_RF_CHECK_TDD_POWER( 1 ) )                            /* 3G is already ON, so 2G does not do the power-on reset */
/*MT6166*/          {
/*MT6166*/             l1d_rf2.is_2g_on = 1;                                     /* set 2G flag to notify 2G is ON */
/*MT6166*/             L1D_DM_Power_Control_Trace( 1, 1 );                       /* indicate 2G is ON and 3G is ON */
/*MT6166*/          }
/*MT6166*/          else
/*MT6166*/    #endif
/*MT6166*/ #endif
/*MT6166*/          {
/*MT6166*/ #if IS_DUAL_TALK_SUPPORT
/*MT6166*/ #else
/*MT6166*/			   IMM_SEND_BPI( 0x20000 );		                          /* Set BSI switch owner to be 2G */
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/             l1d_rf2.is_2g_on = 1;                                     /* set 2G flag to notify 2G is ON */
/*MT6166*/             L1D_DM_Power_Control_Trace( 1, 0 );                       /* indicate 2G is ON and 3G is OFF */
/*MT6166*/ #if defined(__UMTS_RAT__)&& defined ( __UMTS_FDD_MODE__ )
/*MT6166*/             RestoreIRQMask(_savedMask);                               /* enable interrupt */
/*MT6166*/ #endif
/*MT6166*/             L1D_PMU_VRF18Setting( 1 );                                /* Enable VDD_18 (controlled by PMIC) */
/*MT6166*/ #if IS_DUAL_TALK_SUPPORT
/*MT6166*/             WAIT_TIME_QB(220);                                        /* Wait 200us for PMIC                    */
/*MT6166*/ #endif
/*MT6166*/             l1d_rf2.is_2g_on = 3;                                     /* Record the PMU step                */
/*MT6166*/             L1D_PMU_VRF28Setting( 1 );                                /* Enable VDD_28 (controlled by PMIC) */
/*MT6166*/             L1D_PMU_LPSetting( 0 );                                   /* Configure LPM to be normal mode    */
/*MT6166*/             l1d_rf2.is_2g_on = 5;                                     /* Record the PMU step                */
/*MT6166*/
/*MT6166*/             /* POR regardless of init or wake up use the same sequence */
/*MT6166*/             L1D_RF_Power_On_Sequence();
/*MT6166*/
/*MT6166*/             BSI_num = RF_POR_NUM;
/*MT6166*/
/*MT6166*/             for( i=0 ; i<BSI_num; i++ )
/*MT6166*/             {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_TABLE[i] );
/*MT6166*/             }
/*MT6166*/
/*MT6166*/             L1D_RF_SetClockControl();
/*MT6166*/
/*MT6166*/ #if defined(__UMTS_RAT__)&& defined ( __UMTS_FDD_MODE__ )
/*MT6166*/             {
/*MT6166*/                unsigned long  cw147  =0;
/*MT6166*/                unsigned long  cw148  =0;
/*MT6166*/                extern unsigned long UL1D_RF_GetRxDCOC_CW(void);
/*MT6166*/                extern unsigned long UL1D_RF_GetRxDCOC_CW2(void);
/*MT6166*/                cw147 = UL1D_RF_GetRxDCOC_CW();
/*MT6166*/                IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x93, cw147) );
/*MT6166*/                cw148 = UL1D_RF_GetRxDCOC_CW2();
/*MT6166*/                IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x94, cw148) );
/*MT6166*/             }
/*MT6166*/ #endif
/*MT6166*/ #if IS_AST3002_SUPPORT
/*MT6166*/    #if IS_DUAL_TALK_SUPPORT
/*MT6166*/    #else
/*MT6166*/             IMM_SEND_BPI( 0x00000 );                                  /* Set BSI switch owner to be TDD */
/*MT6166*/    #endif
/*MT6166*/ #endif
/*MT6166*/          }
/*MT6166*/       }
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    if( !l1d_rf2.is_wakeup )
/*MT6166*/    {
/*MT6166*/ #if IS_DUAL_TALK_SUPPORT
/*MT6166*/ #else
/*MT6166*/       IMM_SEND_BPI( 0x20000 );		/* Set BSI switch owner to be 2G */
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/       if( l1d_rf.is_init )
/*MT6166*/       {  /* Keep AFC DAC & CAP ID as MT6166 default setting, since we currently don't have calibrated AFC data. */ }
/*MT6166*/       else
/*MT6166*/       {
/*MT6166*/          /* Set AFC DAC to corresponding (CW247/CW254) according to (DCXO mode/TCVCXO mode) */
/*MT6166*/          IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xF9, ((XO_CapID&0xFF)<<12)|0x008C6) );  //CW249: Set previous Cap ID value
/*MT6166*/ #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G)
/*MT6166*/          IMM_SEND_BSI( SCTRL_IMOD(0,30), ((l1d_rf.AFC_data<<AFC_SHIFT_PART)&AFC_MASK_PART)|(AFC_VALUE_PART) );
/*MT6166*/ #endif
/*MT6166*/       }
/*MT6166*/       /* Set Co-Clock setting according to NVRAM at L1D_Init2() */
/*MT6166*/       L1D_RF_SetClockControl();
/*MT6166*/       L1D_RF_Set_FixAFC_Status();
/*MT6166*/
/*MT6166*/ #if IS_AST3002_SUPPORT
/*MT6166*/    #if IS_DUAL_TALK_SUPPORT
/*MT6166*/    #else
/*MT6166*/       IMM_SEND_BPI( 0x00000 );                                  /* Set BSI switch owner to be TDD */
/*MT6166*/    #endif
/*MT6166*/ #endif
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    if( l1d_rf.is_init )
/*MT6166*/    {
/*MT6166*/ #if IS_DUAL_TALK_SUPPORT
/*MT6166*/ #else
/*MT6166*/       IMM_SEND_BPI( 0x20000 );    /* Set BSI switch owner to be 2G */
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/       /* Power On Calibration */
/*MT6166*/       if( l1d_rf2.power_on_cal_flag&RXRC_CAL_ON )
/*MT6166*/       {
/*MT6166*/          L1D_RF_RXRC_Cal();
/*MT6166*/          l1d_rf2.is_power_on_cal |= RXRC_CAL_DONE;
/*MT6166*/       }
/*MT6166*/       if( l1d_rf2.power_on_cal_flag&TX_GAINSTEP_CAL_ON )
/*MT6166*/       {
/*MT6166*/          L1D_RF_TX_GainStep_Cal();
/*MT6166*/          l1d_rf2.is_power_on_cal |= TX_GAINSTEP_CAL_DONE;
/*MT6166*/       }
/*MT6166*/ #if IS_AST3002_SUPPORT
/*MT6166*/    #if IS_DUAL_TALK_SUPPORT
/*MT6166*/    #else
/*MT6166*/       IMM_SEND_BPI( 0x00000 );                                  /* Set BSI switch owner to be TDD */
/*MT6166*/    #endif
/*MT6166*/ #endif
/*MT6166*/ #if IS_DUAL_TALK_SUPPORT
/*MT6166*/       MML1_RF_NOTIFY_POC_DONE( MML1_RF_2G );
/*MT6166*/ #endif
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    IMM_MODE_END(  );
/*MT6166*/
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void  L1D_RF_PowerOff( void )
/*MT6166*/ {  // Sleep to Phone Standby
/*MT6166*/ #if defined(__UMTS_RAT__)&& defined ( __UMTS_FDD_MODE__ )
/*MT6166*/    unsigned long _savedMask;
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/    IMM_MODE_BEGIN( IMMMASK_BSI|IMMMASK_BPI );
/*MT6166*/
/*MT6166*/ #if defined(__UMTS_RAT__)&& defined ( __UMTS_FDD_MODE__ )
/*MT6166*/    extern char UL1D_RF_CheckDMPower( void );                   /* check 3g RF flag */
/*MT6166*/    _savedMask = SaveAndSetIRQMask();                           /* disable interrupt */
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ #if defined(__UMTS_RAT__)&& defined ( __UMTS_FDD_MODE__ )
/*MT6166*/    if( UL1D_RF_CheckDMPower() )                                /* 3G is still ON, so 2G can not do the power-off sequence */
/*MT6166*/    {
/*MT6166*/       l1d_rf2.is_2g_on = 0;                                    /* clear 2G flag to notify 2G is OFF */
/*MT6166*/       L1D_DM_Power_Control_Trace( 0, 1 );                      /* indicate 2G is OFF and 3G is ON */
/*MT6166*/       RestoreIRQMask(_savedMask);                              /* enable interrupt */
/*MT6166*/    }
/*MT6166*/    else                                                        /* 3G is already OFF, so 2G does the power-off sequence */
/*MT6166*/ #endif
/*MT6166*/ #if IS_AST3002_SUPPORT
/*MT6166*/    #if IS_DUAL_TALK_SUPPORT
/*MT6166*/    #else
/*MT6166*/    if( L1D_RF_CHECK_TDD_POWER( 0 ) )                           /* 3G is already ON, so 2G does not do the power-on reset */
/*MT6166*/    {
/*MT6166*/       l1d_rf2.is_2g_on = 0;                                    /* set 2G flag to notify 2G is ON */
/*MT6166*/       L1D_DM_Power_Control_Trace( 0, 1 );                      /* indicate 2G is ON and 3G is ON */
/*MT6166*/    }
/*MT6166*/    else
/*MT6166*/    #endif
/*MT6166*/ #endif
/*MT6166*/    {
/*MT6166*/       l1d_rf2.is_2g_on = 0;                                    /* clear 2G flag to notify 2G is OFF */
/*MT6166*/       L1D_DM_Power_Control_Trace( 0, 0 );                      /* indicate 2G is OFF and 3G is OFF */
/*MT6166*/ #if defined(__UMTS_RAT__)&& defined ( __UMTS_FDD_MODE__ )
/*MT6166*/       RestoreIRQMask(_savedMask);                              /* enable interrupt */
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ #if IS_DUAL_TALK_SUPPORT
/*MT6166*/ #else
/*MT6166*/       IMM_SEND_BPI( 0x20000 );    /* Set BSI switch owner to be 2G */
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/ #if IS_32K_CRYSTAL_REMOVAL_SUPPORT
/*MT6166*/       {  //Set LPM fractional divider before RF power off
/*MT6166*/          extern unsigned long L1D_GetDCXOFreqLPM(void);
/*MT6166*/          unsigned long dcxo_frac = L1D_GetDCXOFreqLPM();
/*MT6166*/
/*MT6166*/          if( !L1D_RF_Check_32K_XO_Status() )
/*MT6166*/          {
/*MT6166*/             IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xF9, ((XO_CapID&0xFF)<<12)|(dcxo_frac&0xFFF)) );  //CW249: Set previous Cap ID value
/*MT6166*/          }
/*MT6166*/       }
/*MT6166*/ #endif
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xC9, 0x00000) ); //CW201: set DYN_EN=0
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x12, 0x00000) ); //CW18 : set EN_BG1_VBGR=0,EN_BG2_VBGR=0,EN_BG_IPTAT=0
/*MT6166*/
/*MT6166*/ #if IS_AST3002_SUPPORT
/*MT6166*/    #if IS_DUAL_TALK_SUPPORT
/*MT6166*/    #else
/*MT6166*/       IMM_SEND_BPI( 0x00000 );                                 /* Set BSI switch owner to be TDD */
/*MT6166*/    #endif
/*MT6166*/ #endif
/*MT6166*/
/*MT6166*/       L1D_PMU_VRF18Setting( 0 );                               /* Disable VDD_18 (controlled by PMIC) */
/*MT6166*/       L1D_PMU_LPSetting( 1 );                                  /* Configure to be LP mode             */
/*MT6166*/       l1d_rf2.is_2g_on = 6;                                    /* Record the PMU step                 */
/*MT6166*/       L1D_PMU_VRF28Setting( 0 );                               /* Disable VDD_28 (controlled by PMIC) */
/*MT6166*/       l1d_rf2.is_2g_on = 8;                                    /* Record the PMU step                 */
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    IMM_MODE_END(  );
/*MT6166*/
/*MT6166*/ #if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
/*MT6166*/    L1D_CustomDynamicDebug();
/*MT6166*/ #endif
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void  L1D_RF_WindowOn( void )
/*MT6166*/ {
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void  L1D_RF_WindowOff( void )
/*MT6166*/ {
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void L1D_RF_Power_On_Sequence( void )
/*MT6166*/ {
/*MT6166*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x12, 0xE0000) );     //CW18 : set EN_BG1_VBGR=1, EN_BG2_VBGR=1, EN_BG_IPTAT=1
/*MT6166*/    WAIT_TIME_QB(12);                                            //wait 10us
/*MT6166*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xC9, 0x00200) );     //CW201: Set DYN_EN=1
/*MT6166*/    WAIT_TIME_QB(217);                                           //wait 200us
/*MT6166*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xC9, 0x08202) );     //CW201: choose 2G RX CAL mode,PCS,to Turn-on 26MHz CLK from DCXO for calibration
/*MT6166*/    WAIT_TIME_QB(12);                                            //wait 10us
/*MT6166*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xB9, 0x80000) );     //CW185: set D[19]=1(RCAL_START_TRG) to enable R-cal function
/*MT6166*/    WAIT_TIME_QB(12);                                            //wait 10us
/*MT6166*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xC9, 0x00200) );     //CW201: back to sleep mode
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void L1D_RF_RXRC_Cal( void )
/*MT6166*/ {
/*MT6166*/    unsigned long  cw144;
/*MT6166*/
/*MT6166*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6166*/
/*MT6166*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x81, 0x01450) );                //CW129 : set RXIF mode, LNA mode, DUAL talk mode
/*MT6166*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xC9, 0x08208) );                //CW201 : enter 2G RX CAL mode, choose GSM900
/*MT6166*/    WAIT_TIME_QB(135);                                                      //wait 120us
/*MT6166*/    IMM_RECEIVE_BSI( SCTRL_IMOD(0,12), 0x90, SCTRL_IMOD(0,20), &(cw144) );  //CW144 : read back RXRC Cal. Value
/*MT6166*/
/*MT6166*/    l1d_rf2.rxif_rck_m = ( cw144&(RXIF_RCK_MASK<<14))>>14;
/*MT6166*/
/*MT6166*/    cw144  = ( POR_CW144 &(~(RXIF_RCK_MASK)) ) | ( (l1d_rf2.rxif_rck_m&RXIF_RCK_MASK) );
/*MT6166*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x90,   cw144) );                //CW144 : RXIF_RCK_CAL[5:0]
/*MT6166*/    WAIT_TIME_QB(4);                                                        //wait 3us
/*MT6166*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xC9, 0x00200) );                //CW201 : enter sleep mode
/*MT6166*/
/*MT6166*/    IMM_MODE_END( );
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void L1D_RF_TX_GainStep_Cal( void )
/*MT6166*/ {
/*MT6166*/    unsigned short band_idx         = 0;
/*MT6166*/    unsigned short N                = 0;
/*MT6166*/    unsigned short k_cnt            = 0;
/*MT6166*/    unsigned short sum_cnt          = 0;
/*MT6166*/    unsigned short codetype         = 0;
/*MT6166*/    unsigned short DEM_Chunk_L1     = 0;
/*MT6166*/    unsigned short Nint             = 0;
/*MT6166*/    unsigned long  Nfrac            = 0;
/*MT6166*/    unsigned long  read_data        = 0;
/*MT6166*/    signed short   Pmeas1           = 0;
/*MT6166*/    signed short   Pmeas2           = 0;
/*MT6166*/    signed short   Pmeas1_post_proc = 0;
/*MT6166*/    signed short   Pmeas2_post_proc = 0;
/*MT6166*/    signed short   temp_gain_step   = 0;
/*MT6166*/    signed short   simu_gain_step   = 0;
/*MT6166*/    signed short   gain_step_ub     = 0;
/*MT6166*/    signed short   gain_step_lb     = 0;
/*MT6166*/    signed short   sum_gain_step    = 0;
/*MT6166*/    signed short   avg_gain_step    = 0;
/*MT6166*/    long  cw201,cw96,cw97,cw87,cw98,cw99;
/*MT6166*/
/*MT6166*/    l1d_rf2.Gvga_rf[0][0] = GVGARF_LB[0]-GBB1_LB[0];
/*MT6166*/    l1d_rf2.Gvga_rf[1][0] = GVGARF_LB[0]-GBB1_LB[0];
/*MT6166*/    l1d_rf2.Gvga_rf[2][0] = GVGARF_HB[0]-GBB1_HB[0];
/*MT6166*/    l1d_rf2.Gvga_rf[3][0] = GVGARF_HB[0]-GBB1_HB[0];
/*MT6166*/
/*MT6166*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6166*/
/*MT6166*/    for( band_idx=0;band_idx<CAL_BAND_NUM;band_idx++)
/*MT6166*/    {
/*MT6166*/       cw201 = ( POR_CW201 &(~BAND_MASK) );
/*MT6166*/
/*MT6166*/       L1D_RF_GetTxPLLSetting       ( (FrequencyBand850+band_idx), MIDBAND_ARFCN[band_idx], &cw96, &cw97);
/*MT6166*/       L1D_RF_GetTxKDCOCAL2ndSetting( (FrequencyBand850+band_idx), MIDBAND_ARFCN[band_idx], &cw98, &cw99);
/*MT6166*/
/*MT6166*/       Nint  = (  cw96&(0xFF<<12) )>>12 ;
/*MT6166*/       Nfrac = ( (cw96&0xFFF)<<11 ) | ( (cw97&(0x7FF<<9))>>9 ) ;
/*MT6166*/
/*MT6166*/       codetype     = L1D_RF_GetTxDCOSCACodeTypeSetting( Nint, Nfrac );
/*MT6166*/       DEM_Chunk_L1 = 0x7E;//L1D_RF_GetTxDEMChunkSetting( (FrequencyBand850+band_idx), Nint );
/*MT6166*/
/*MT6166*/       cw87 = (long) (POR_CW87 | (codetype&0xFFF)<<8 | (DEM_Chunk_L1&0x7F)<<1);
/*MT6166*/
/*MT6166*/       /* Set TX Cal. Mode : ST1 */
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x60, cw96 ) );   // CW96 : write STX NMMD0
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x61, cw97 ) );   // CW97 : write STX NMMD0, offset
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x57, cw87 ) );   // CW87 : write STX DCO SCA typ. code and STX_DEM_chunk
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x62, cw98 ) );   // CW98 : write STX NMMD1 for KDCO cal.
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x63, cw99 ) );   // CW99 : write STX NMMD1 for KDCO cal.
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xC9, TXCAL_MODE_2G| cw201 |SDATA_BAND_SEL[(FrequencyBand850+band_idx)]) ); // CW201 : Mode = 00011 | Band(Variable)
/*MT6166*/       WAIT_TIME_QB( 250 );                                     // Wait 230us
/*MT6166*/
/*MT6166*/       /* Set TX Burst Mode : ST2B */
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xC9, TXBURST_MODE_2G|(0x1<<11)| cw201 |SDATA_BAND_SEL[(FrequencyBand850+band_idx)]) ); // CW201 : Mode = 00100 | G/8 mode change | Band(Variable)
/*MT6166*/
/*MT6166*/       /* Set Tx to Initialization State */
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x24, 0x049AC) ); // CW36
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x2B, 0x96042) ); // CW43 old:0x96040
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x2F, 0x00000) ); // CW47
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x2D, 0x11600) ); // CW45
/*MT6166*/
/*MT6166*/       /* trigger test tone start to output */
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x6C, 0x10000) ); // CW108 : trigger sine tone start to output
/*MT6166*/
/*MT6166*/       for( N=0;N<13;N++)
/*MT6166*/       {
/*MT6166*/          sum_gain_step = 0;
/*MT6166*/          avg_gain_step = 0;
/*MT6166*/          sum_cnt       = 0;
/*MT6166*/
/*MT6166*/          for( k_cnt=0;k_cnt<MAX_RETRY_TIMES;k_cnt++)
/*MT6166*/          {
/*MT6166*/             if( band_idx < 2 )
/*MT6166*/             {
/*MT6166*/                IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x24, TXGAINSTEP_CAL_CW36_LB_TABLE[N][0]) ); // CW36
/*MT6166*/                IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x29, TXGAINSTEP_CAL_CW41_LB_TABLE[N][0]) ); // CW41
/*MT6166*/                IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x2A, TXGAINSTEP_CAL_CW42_LB_TABLE[N][0]) ); // CW42
/*MT6166*/             }
/*MT6166*/             else
/*MT6166*/             {
/*MT6166*/                IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x24, TXGAINSTEP_CAL_CW36_HB_TABLE[N][0]) ); // CW36
/*MT6166*/                IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x29, TXGAINSTEP_CAL_CW41_HB_TABLE[N][0]) ); // CW41
/*MT6166*/                IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x2A, TXGAINSTEP_CAL_CW42_HB_TABLE[N][0]) ); // CW42
/*MT6166*/             }
/*MT6166*/             WAIT_TIME_QB( 80 );                                     // Wait 55us avoid FH drop BSI clk rate must larger than 55us
/*MT6166*/             IMM_RECEIVE_BSI( SCTRL_IMOD(0,12), 0x7C, SCTRL_IMOD(0,20), &(read_data) );        // read back CW124 : gainmeas
/*MT6166*/             Pmeas1 = read_data & GAIN_MEAS_MASK;
/*MT6166*/
/*MT6166*/             if( band_idx < 2 )
/*MT6166*/             {
/*MT6166*/                IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x24, TXGAINSTEP_CAL_CW36_LB_TABLE[N][1]) ); // CW36
/*MT6166*/                IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x29, TXGAINSTEP_CAL_CW41_LB_TABLE[N][1]) ); // CW41
/*MT6166*/                IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x2A, TXGAINSTEP_CAL_CW42_LB_TABLE[N][1]) ); // CW42
/*MT6166*/             }
/*MT6166*/             else
/*MT6166*/             {
/*MT6166*/                IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x24, TXGAINSTEP_CAL_CW36_HB_TABLE[N][1]) ); // CW36
/*MT6166*/                IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x29, TXGAINSTEP_CAL_CW41_HB_TABLE[N][1]) ); // CW41
/*MT6166*/                IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x2A, TXGAINSTEP_CAL_CW42_HB_TABLE[N][1]) ); // CW42
/*MT6166*/             }
/*MT6166*/             WAIT_TIME_QB( 80 );                                     // Wait 55us avoid FH drop BSI clk rate must larger than 55us
/*MT6166*/             IMM_RECEIVE_BSI( SCTRL_IMOD(0,12), 0x7C, SCTRL_IMOD(0,20), &(read_data) );        // read back CW124 : gainmeas
/*MT6166*/             Pmeas2 = read_data & GAIN_MEAS_MASK;
/*MT6166*/
/*MT6166*/             Pmeas1_post_proc = ((Pmeas1&0x800)!=0)?(Pmeas1-(0x1<<12)):(Pmeas1);              // Read Gain Post Processing S6.5
/*MT6166*/             Pmeas2_post_proc = ((Pmeas2&0x800)!=0)?(Pmeas2-(0x1<<12)):(Pmeas2);              // Read Gain Post Processing S6.5
/*MT6166*/
/*MT6166*/             temp_gain_step   = (band_idx<2) ? (Pmeas2_post_proc - Pmeas1_post_proc + GBB1_LB[N+1] - GBB1_LB[N]) : (Pmeas2_post_proc - Pmeas1_post_proc + GBB1_HB[N+1] - GBB1_HB[N]);
/*MT6166*/             simu_gain_step   = (band_idx<2) ? (GVGARF_LB[N+1]-GVGARF_LB[N]) : (GVGARF_HB[N+1]-GVGARF_HB[N]);
/*MT6166*/
/*MT6166*/             gain_step_ub     = (N>7) ? (simu_gain_step+50) : ((simu_gain_step  /2)+7);
/*MT6166*/             gain_step_lb     = (N>7) ? (simu_gain_step-50) : ((simu_gain_step*3/2)-7);
/*MT6166*/
/*MT6166*/             if( (temp_gain_step>=0) || (temp_gain_step>(gain_step_ub)) || (temp_gain_step<(gain_step_lb)) )
/*MT6166*/             {  l1d_rf2.tx_gain_step_k_flag += (0x1<<(band_idx*4));
/*MT6166*/             }
/*MT6166*/             else
/*MT6166*/             {
/*MT6166*/                sum_gain_step += Pmeas2_post_proc - Pmeas1_post_proc;
/*MT6166*/                sum_cnt++;
/*MT6166*/             }
/*MT6166*/          }
/*MT6166*/          if( band_idx < 2 )
/*MT6166*/             avg_gain_step = (sum_cnt==0) ? (simu_gain_step-GBB1_LB[N+1]+GBB1_LB[N]) : (sum_gain_step/sum_cnt);
/*MT6166*/          else
/*MT6166*/             avg_gain_step = (sum_cnt==0) ? (simu_gain_step-GBB1_HB[N+1]+GBB1_HB[N]) : (sum_gain_step/sum_cnt);
/*MT6166*/
/*MT6166*/          l1d_rf2.Gvga_rf[band_idx][N+1] = l1d_rf2.Gvga_rf[band_idx][N] + avg_gain_step;
/*MT6166*/       }
/*MT6166*/
/*MT6166*/       for( N=0;N<14;N++)
/*MT6166*/       {
/*MT6166*/          l1d_rf2.Gvga_rf[band_idx][N] += ( (band_idx<2) ? GBB1_LB[N] : GBB1_HB[N] );
/*MT6166*/       }
/*MT6166*/
/*MT6166*/       /* stop sine tone start to output */
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x6C, 0x08000 ) ); // CW108 : stop sine tone
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x6C, 0x00000 ) );
/*MT6166*/
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x22, POR_CW34) ); // CW34
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x24, POR_CW36) ); // CW36
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x2B, POR_CW43) ); // CW43
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x2F, POR_CW47) ); // CW47
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x2D, POR_CW45) ); // CW45
/*MT6166*/
/*MT6166*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xC9, SLEEP_MODE| cw201 |SDATA_BAND_SEL[(FrequencyBand850+band_idx)]) );  // CW201   : Sleep mode
/*MT6166*/       WAIT_TIME_QB( 10 );
/*MT6166*/    }
/*MT6166*/
/*MT6166*/    IMM_MODE_END( );
/*MT6166*/ }
/*MT6166*/
/*MT6166*/ void L1D_MMRF_SetPowerOnCalibrationData( RFC_DATABASE_T* pRfcDataBase )
/*MT6166*/ {
/*MT6166*/    /* This function called by MMRF central controllor when LTE's power on cal has done. */
/*MT6166*/    /* Read the calibration results from LTE calibration table provided by LTE           */
/*MT6166*/    /* Power On Calibration */
/*MT6166*/ }
/*MT6166*/
#endif

#if IS_RF_MT6165
/*MT6165*/
/*MT6165*/ #include "intrCtrl.h"
/*MT6165*/
/*MT6165*/ #define RF_POR_NUM       (sizeof(SDATA_TABLE) /sizeof(unsigned long))
/*MT6165*/
/*MT6165*//* CW1 : Mode */
/*MT6165*/ #define SLEEP_MODE       (0x0<<16)
/*MT6165*/ #define RXCAL_MODE_2G    (0x1<<16)
/*MT6165*/ #define RXBURST_MODE_2G  (0x2<<16)
/*MT6165*/ #define TXCAL_MODE_2G    (0x3<<16)
/*MT6165*/ #define TXBURST_MODE_2G  (0x4<<16)
/*MT6165*/
/*MT6165*/ /* Set CW default power on value include addr */
/*MT6165*/ /* POR default value */
/*MT6165*/ #define POR_CW64         (0x04080000 | RXLNA_NODET_EN)
/*MT6165*/ #define POR_CW128        0x0800002EL
/*MT6165*/ #define POR_CW177        0x0B153368L
/*MT6165*/ #define POR_CW6          0x006FC001L
/*MT6165*/ #define POR_CW180        0x0B4382F9L
/*MT6165*/ #define POR_CW67         0x04392573L
/*MT6165*/ #define POR_CW68         0x044AF40BL
/*MT6165*/ #define POR_CW70         0x0466DF90L
/*MT6165*/ #define POR_CW71         0x0477EFA8L
/*MT6165*/ #define POR_CW72         0x0484F4F4L
/*MT6165*/ #define POR_CW73         0x04900000L
/*MT6165*/ #define POR_CW74         0x04A6A368L
/*MT6165*/
/*MT6165*/ const unsigned long SDATA_TABLE[]=
/*MT6165*/ {
/*MT6165*/    POR_CW64,
/*MT6165*/    POR_CW128,
/*MT6165*/    POR_CW188,
/*MT6165*/    POR_CW177,
/*MT6165*/    POR_CW6,
/*MT6165*/    POR_CW173,
/*MT6165*/    POR_CW180,
/*MT6165*/    POR_CW176,
/*MT6165*/    POR_CW179,
/*MT6165*/    POR_CW67,
/*MT6165*/    POR_CW68,
/*MT6165*/    POR_CW70,
/*MT6165*/    POR_CW71,
/*MT6165*/    POR_CW72,
/*MT6165*/    POR_CW73,
/*MT6165*/    POR_CW74
/*MT6165*/ };
/*MT6165*/
/*MT6165*/ extern const unsigned long  SDATA_BAND_SEL[5];
/*MT6165*/
/*MT6165*/ extern void L1D_DM_Power_Control_Trace( char is_2g, char is_3g );
/*MT6165*/ void  L1D_RF_PowerOn( void )
/*MT6165*/ {
/*MT6165*/
/*MT6165*/    unsigned long  cw0;
/*MT6165*/
/*MT6165*/    IMM_MODE_BEGIN( IMMMASK_ALL );
/*MT6165*/
/*MT6165*/    if( l1d_rf.is_init || l1d_rf2.is_wakeup )
/*MT6165*/    {
/*MT6165*/       if( l1d_rf.is_init )
/*MT6165*/       {
/*MT6165*/
/*MT6165*/ #if IS_DUAL_TALK_SUPPORT
/*MT6165*/          /* RF Power On by MML1 RF central control */
/*MT6165*/          /* For register RFC query event function  */
/*MT6165*/          MML1_RF_POWER_ON( l1d_rf2.is_wakeup, MML1_RF_2G );
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/ #if IS_DUAL_TALK_SUPPORT || IS_2G_ONLY_MODEM_SUPPORT
/*MT6165*/          L1D_PMU_VRF18HWModeSelect(  );                               /* Configure VRF18 srclken sel for dual talk       */
/*MT6165*/          L1D_PMU_VRF18ModeSetting( 0 );  /* 0: enable  */ /* Configure VDD_18 to be SW mode         */
/*MT6165*/          WAIT_TIME_QB(300);                                           /* Wait 277us for PMIC                    */
/*MT6165*/          L1D_PMU_VRF18Setting( 1 );                                   /* Enable VDD_18 (controlled by PMIC)     */
/*MT6165*/          WAIT_TIME_QB(220);                                           /* Wait 200us for PMIC                    */
/*MT6165*/          L1D_PMIC_ADPT2_PWM_ENABLE( 1 );                              /* FPWM */
/*MT6165*/ #else
/*MT6165*/          L1D_PMU_VRF18HWModeSelect(  );                               /* Configure VRF18 srclken sel for dual talk       */
/*MT6165*/          L1D_PMU_VRF18ModeSetting( 1 );  /* 1: enable with SRCLKEN */ /* Configure VDD_18 to be HW mode         */
/*MT6165*/          WAIT_TIME_QB(300);                                           /* Wait 277us for PMIC                    */
/*MT6165*/          L1D_PMU_VRF18Setting( 1 );                                   /* Enable VDD_18 (controlled by PMIC)     */
/*MT6165*/ #endif
/*MT6165*/          L1D_PMU_LPModeSetting( 1 );                                  /* Configure low power mode to be SW mode */
/*MT6165*/          l1d_rf2.is_2g_on = 2;                                        /* Record the PMU step                    */
/*MT6165*/          L1D_PMU_VRF28Setting( 1 );                                   /* Enable VDD_28 (controlled by PMIC)     */
/*MT6165*/          L1D_PMU_LPSetting( 0 );                                      /* Configure LPM to be normal mode        */
/*MT6165*/          l1d_rf2.is_2g_on = 4;                                        /* Record the PMU step                    */
/*MT6165*/
/*MT6165*/          /* POR regardless of init or wake up use the same sequence */
/*MT6165*/          SPECIAL_IMM_RECEIVE_BSI( SCTRL_IMOD(0,12), 0x00, SCTRL_IMOD(0,20), &(cw0) );
/*MT6165*/          IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x00, 0x81123) );     //CW0  : SOR
/*MT6165*/          WAIT_TIME_QB(22);                                            //wait 20us
/*MT6165*/
/*MT6165*/          L1D_RF_Power_On_Sequence();
/*MT6165*/
/*MT6165*/          l1d_rf2.is_2g_on = 1;                                        /* set 2G flag to notify 2G is ON */
/*MT6165*/
/*MT6165*/          L1D_DM_Power_Control_Trace( 1, 2 );                          /* indicate the init state */
/*MT6165*/ #if IS_DUAL_TALK_SUPPORT
/*MT6165*/          MML1_RF_NOTIFY_POC_DONE( MML1_RF_2G );
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/       }
/*MT6165*/       else
/*MT6165*/       {
/*MT6165*/          {
/*MT6165*/
/*MT6165*/             l1d_rf2.is_2g_on = 1;                                     /* set 2G flag to notify 2G is ON */
/*MT6165*/             L1D_DM_Power_Control_Trace( 1, 0 );                       /* indicate 2G is ON and 3G is OFF */
/*MT6165*/
/*MT6165*/             L1D_PMU_VRF18Setting( 1 );                                /* Enable VDD_18 (controlled by PMIC) */
/*MT6165*/ #if IS_DUAL_TALK_SUPPORT || IS_2G_ONLY_MODEM_SUPPORT
/*MT6165*/             WAIT_TIME_QB(220);                                        /* Wait 200us for PMIC                    */
/*MT6165*/ #endif
/*MT6165*/             l1d_rf2.is_2g_on = 3;                                     /* Record the PMU step                */
/*MT6165*/             L1D_PMU_VRF28Setting( 1 );                                /* Enable VDD_28 (controlled by PMIC) */
/*MT6165*/             L1D_PMU_LPSetting( 0 );                                   /* Configure LPM to be normal mode    */
/*MT6165*/             l1d_rf2.is_2g_on = 5;                                     /* Record the PMU step                */
/*MT6165*/
/*MT6165*/             /* POR regardless of init or wake up use the same sequence */
/*MT6165*/             L1D_RF_Power_On_Sequence();
/*MT6165*/          }
/*MT6165*/       }
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    if( !l1d_rf2.is_wakeup )
/*MT6165*/    {
/*MT6165*/
/*MT6165*/       if( l1d_rf.is_init )
/*MT6165*/       {  /* Keep AFC DAC & CAP ID as MT6165 default setting, since we currently don't have calibrated AFC data. */ }
/*MT6165*/       else
/*MT6165*/       {
/*MT6165*/          /* Set AFC DAC to corresponding (CW247) according to (DCXO mode) */
/*MT6165*/ #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G)
/*MT6165*/          IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xF9, ((XO_CapID&0xFF)<<12)|0x008C6) );  //CW249: Set previous Cap ID value
/*MT6165*/ #endif
/*MT6165*/          IMM_SEND_BSI( SCTRL_IMOD(0,30), ((l1d_rf.AFC_data<<AFC_SHIFT_PART)&AFC_MASK_PART)|(AFC_VALUE_PART) );
/*MT6165*/       }
/*MT6165*/       /* Set Co-Clock setting according to NVRAM at L1D_Init2() */
/*MT6165*/       L1D_RF_SetClockControl();
/*MT6165*/       L1D_RF_Set_FixAFC_Status();
/*MT6165*/
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    IMM_MODE_END(  );
/*MT6165*/
/*MT6165*/ }
/*MT6165*/
/*MT6165*/ void  L1D_RF_PowerOff( void )
/*MT6165*/ {  // Sleep to Phone Standby
/*MT6165*/
/*MT6165*/    IMM_MODE_BEGIN( IMMMASK_BSI|IMMMASK_BPI );
/*MT6165*/
/*MT6165*/    {
/*MT6165*/       l1d_rf2.is_2g_on = 0;                                    /* clear 2G flag to notify 2G is OFF */
/*MT6165*/       L1D_DM_Power_Control_Trace( 0, 0 );                      /* indicate 2G is OFF and 3G is OFF */
/*MT6165*/
/*MT6165*/
/*MT6165*/ #if IS_32K_CRYSTAL_REMOVAL_SUPPORT
/*MT6165*/       {  //Set LPM fractional divider before RF power off
/*MT6165*/          extern unsigned long L1D_GetDCXOFreqLPM(void);
/*MT6165*/          unsigned long dcxo_frac = L1D_GetDCXOFreqLPM();
/*MT6165*/
/*MT6165*/          if( !L1D_RF_Check_32K_XO_Status() )
/*MT6165*/          {
/*MT6165*/             IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xF9, ((XO_CapID&0xFF)<<12)|(dcxo_frac&0xFFF)) );  //CW249: Set previous Cap ID value
/*MT6165*/          }
/*MT6165*/       }
/*MT6165*/ #endif
/*MT6165*/       IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x01, 0x00000) ); //CW1: set DYN_EN=0
/*MT6165*/
/*MT6165*/       L1D_PMU_VRF18Setting( 0 );                               /* Disable VDD_18 (controlled by PMIC) */
/*MT6165*/       L1D_PMU_LPSetting( 1 );                                  /* Configure to be LP mode             */
/*MT6165*/       l1d_rf2.is_2g_on = 6;                                    /* Record the PMU step                 */
/*MT6165*/       L1D_PMU_VRF28Setting( 0 );                               /* Disable VDD_28 (controlled by PMIC) */
/*MT6165*/       l1d_rf2.is_2g_on = 8;                                    /* Record the PMU step                 */
/*MT6165*/    }
/*MT6165*/
/*MT6165*/    IMM_MODE_END(  );
/*MT6165*/
/*MT6165*/ #if IS_RF_TOOL_CUSTOMIZATION_SUPPORT_V2
/*MT6165*/    L1D_CustomDynamicDebug();
/*MT6165*/ #endif
/*MT6165*/ }
/*MT6165*/
/*MT6165*/ void  L1D_RF_WindowOn( void )
/*MT6165*/ {
/*MT6165*/ }
/*MT6165*/
/*MT6165*/ void  L1D_RF_WindowOff( void )
/*MT6165*/ {
/*MT6165*/ }
/*MT6165*/
/*MT6165*/ void L1D_RF_Power_On_Sequence( void )
/*MT6165*/ {
/*MT6165*/    unsigned short BSI_num=0, i=0;
/*MT6165*/
/*MT6165*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0x01, 0x04000) );     //CW1  : BIASCORE on, SXD and DYN enable
/*MT6165*/    WAIT_TIME_QB(140);                                           //wait 120us
/*MT6165*/
/*MT6165*/    BSI_num = RF_POR_NUM;
/*MT6165*/    for( i=0 ; i<BSI_num; i++ )
/*MT6165*/    {  IMM_SEND_BSI( SCTRL_IMOD(0,30), SDATA_TABLE[i] );
/*MT6165*/    }
/*MT6165*/ #if  defined(AFC_VCXO) || defined(AFC_VCXO_2G)
/*MT6165*/    IMM_SEND_BSI( SCTRL_IMOD(0,30), BSI_CW(0xF9, ((XO_CapID&0xFF)<<12)|0x008C6) );  //CW249: Set previous Cap ID value
/*MT6165*/ #endif
/*MT6165*/
/*MT6165*/    L1D_RF_SetClockControl();
/*MT6165*/ }
/*MT6165*/ #if IS_RF_CENTRAL_CONTROL_SUPPORT
/*MT6165*/ void L1D_MMRF_SetPowerOnCalibrationData( RFC_DATABASE_T* pRfcDataBase )
/*MT6165*/ {
/*MT6165*/    /* This function called by MMRF central controllor when LTE's power on cal has done. */
/*MT6165*/    /* Read the calibration results from LTE calibration table provided by LTE           */
/*MT6165*/    /* Power On Calibration */
/*MT6165*/ }
/*MT6165*/ #endif
/*MT6165*/
#endif

