#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   emiGenSP.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script will
#*       1. generate fxied flash_opt.h for smart phone modem
#*       2. generate fixed custom_EMI.c for smart phone modem
#*       3. generate fixed custom_EMI.h for smart phone modem
#*       4. generate fixed custom_flash.c for smart phone modem
#*
#* Author:
#* -------
#*   Guo-Huei Chang    (mtk04123)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#* 04 21 2014 guo-huei.chang
#* [MOLY00063203] [EMIGEN] Update EMIGEN for Smart Phone Project
#* 	Update emigen to generate EMI size for none EMI support
#*
#* 01 08 2014 guo-huei.chang
#* [MOLY00052841] [EMIGEN] Update EMIGEN for SmartPhone project
#* 	1. update emigen for smart phone to generate custom emi header
#* 	2. update custom_EMI_SP.c for smart phone
#* 
#* 07 27 2012 marvin.lin
#* [MOLY00001243] [MemoryStorage][Auto-Gen][EMI Gen/CFG Gen][Request For Design Change] to fix emi build warning on sp project
#* .
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;

#****************************************************************************
# Constants
#****************************************************************************
1;
#my $DebugPrint    = 0; # 1 for debug; 0 for non-debug

#****************************************************************************
# subroutine:  custom_EMI_h_file_body_for_sp
# return:      custom_EMI.h file content for SP
#****************************************************************************
sub custom_EMI_h_file_body_for_sp
{
    my ($bb) = @_;
    my $template;
	   
    $template = <<"__TEMPLATE";
#ifndef __CUSTOM_EMI__
#define __CUSTOM_EMI__

/****************************************************
 * This part is for auto-gen validity CHECK *
 * Don't modify any content in this comment section *
 ****************************************************/

#endif /* __CUSTOM_EMI__ */

__TEMPLATE
	   
    return $template;
}

#****************************************************************************
# subroutine:  custom_EMI_release_h_file_body_for_sp
# return:      custom_EMI_release.h file content for SP
#****************************************************************************
sub custom_EMI_release_h_file_body_for_sp
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL) = @_;
    my $template;
	   
    $template = <<"__TEMPLATE";
#ifndef __CUSTOM_EMI_RELEASE__
#define __CUSTOM_EMI_RELEASE__

/***********************************
    *
    * Definition
    * 
    *********************************/

/**
  * Define memory's mode.
  */
#define __EMI_DEVICE_NONE__
/**
  * Define RAM size in Bytes.
  */
#define EMI_EXTSRAM_SIZE ((($COMM_MDL_INFO_LOCAL->{1}->{'Size (Mb)'})>>3)<<20)

#endif /* __CUSTOM_EMI_RELEASE__ */

__TEMPLATE
	   
    return $template;
}

