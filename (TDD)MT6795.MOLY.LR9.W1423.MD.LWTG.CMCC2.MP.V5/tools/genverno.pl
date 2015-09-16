#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2012
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
#*   genverno.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to generate verno.c/verno.h
#*
#* Author:
#* -------
#*   Ray Lin-Wang (mtk04222)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
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
# Input Parameters & Global Variables
#****************************************************************************
my $verno_dir       = $ARGV[0]; # The output path of verno.c and verno.h
my $verno           = $ARGV[1]; # The version number
my $build_date_time = $ARGV[2]; # The date of building
my $branch          = $ARGV[3]; # The branch name
my $hal_verno       = $ARGV[4]; 
my $hw_verno        = $ARGV[5];
my $build           = $ARGV[6];
my $flavor          = $ARGV[7];
my $platform        = $ARGV[8];

my $source_file = "verno.c";
my $header_file = "verno.h";
#****************************************************************************
# subroutines
#****************************************************************************
#****************************************************************************
# Execute
#****************************************************************************
open (SRCFILE, ">$verno_dir/$source_file") or &error_handler("$verno_dir/$source_file : file error!", __FILE__, __LINE__);
print SRCFILE &gen_verno_src_declare;
print SRCFILE &gen_verno_src_rel_verno;
print SRCFILE &gen_verno_src_hal_verno;
print SRCFILE &gen_verno_src_hw_ver;
print SRCFILE &gen_verno_src_build_date;
print SRCFILE &gen_verno_src_rel_build;
print SRCFILE &gen_verno_src_rel_branch;
print SRCFILE &gen_verno_src_rel_flavor;
close SRCFILE;

open (H_FILE, ">$verno_dir/$header_file") or &error_handler("$verno_dir/$header_file : file error!", __FILE__, __LINE__);
print H_FILE &gen_verno_header_file;
close H_FILE;

#****************************************************************************
# subroutine: genverno_verno
#****************************************************************************
sub genverno_verno
{
    return " v0.00 , initial version ";
}

#****************************************************************************
# subroutine:  gen_verno_header_file
#****************************************************************************
sub gen_verno_header_file
{    
	my $template = <<"__TEMPLATE";
#define VERNO_STR "$verno"
#define HW_VER_STR "$hw_verno"
#define BUILD_DATE_TIME_STR "$build_date_time"
#define BUILD_STR "$build"
#define BUILD_BRANCH_STR "$branch"
#define PLATFORM "$platform"

__TEMPLATE
}

#****************************************************************************
# 1. subroutine:  gen_verno_src_declare
#****************************************************************************
sub gen_verno_src_declare
{   
	my $template = <<"__TEMPLATE";
#include "kal_public_api.h"
#if defined(__MTK_TARGET__)
__attribute__ ((section ("RELEASE_VERNO_RW"))) static kal_char verno_str[] = "$verno";
__attribute__ ((section ("BUILD_TIME_RW"))) static kal_char build_date_time_str[] = "$build_date_time";
__attribute__ ((section ("RELEASE_BRANCH_RW"))) static kal_char build_branch_str[] = "$branch";
extern kal_uint32 RELEASE_VERNO_RW\$\$Base;
extern kal_uint32 BUILD_TIME_RW\$\$Base;
extern kal_uint32 RELEASE_BRANCH_RW\$\$Base;
#endif

__TEMPLATE
}

#****************************************************************************
# 2. subroutine:  gen_verno_src_rel_verno
#****************************************************************************
sub gen_verno_src_rel_verno
{    
	my $template = <<"__TEMPLATE";
kal_char* release_verno(void)
{
#if defined(__MTK_TARGET__)
#if defined(__GNUC__)
   return verno_str;
#else
   return (kal_char*)&RELEASE_VERNO_RW\$\$Base;
#endif
#else
   static kal_char verno_str[] = "$verno";
   return verno_str;
#endif
}

__TEMPLATE
}

#****************************************************************************
# 3. subroutine:  gen_verno_src_hal_verno
#****************************************************************************
sub gen_verno_src_hal_verno
{    
	my $template = <<"__TEMPLATE";
kal_char* release_hal_verno(void)
{
   static kal_char hal_verno_str[] = "$hal_verno";
   return hal_verno_str;
}

__TEMPLATE
}

#****************************************************************************
# 4. subroutine:  gen_verno_src_hw_ver
#****************************************************************************
sub gen_verno_src_hw_ver
{    
	my $template = <<"__TEMPLATE";
kal_char* release_hw_ver(void)
{
   static kal_char hw_ver_str[] = "$hw_verno";
   return hw_ver_str;
}

__TEMPLATE
}

#****************************************************************************
# 5. subroutine:  gen_verno_src_build_date
#****************************************************************************
sub gen_verno_src_build_date
{    
	my $template = <<"__TEMPLATE";
kal_char* build_date_time(void)
{
#if defined(__MTK_TARGET__)
#if defined(__GNUC__)
   return build_date_time_str;
#else
   return (kal_char*)&BUILD_TIME_RW\$\$Base;
#endif
#else
   static kal_char build_date_time_str[] = "$build_date_time";
   return build_date_time_str;
#endif
}

__TEMPLATE
}

#****************************************************************************
# 6. subroutine:  gen_verno_src_rel_build
#****************************************************************************
sub gen_verno_src_rel_build
{    
	my $template = <<"__TEMPLATE";
kal_char* release_build(void)
{
   static kal_char build_str[] = "$build";
   return build_str;
}

__TEMPLATE
}

#****************************************************************************
# 7. subroutine:  gen_verno_src_rel_branch
#****************************************************************************
sub gen_verno_src_rel_branch
{    
	my $template = <<"__TEMPLATE";
kal_char* release_branch(void)
{
#if defined(__MTK_TARGET__)
#if defined(__GNUC__)
   return build_branch_str;
#else
   return (kal_char*)&RELEASE_BRANCH_RW\$\$Base;
#endif
#else
   static kal_char build_branch_str[] = "$branch";
   return build_branch_str;
#endif
}

__TEMPLATE
}

#****************************************************************************
# 8. subroutine:  gen_verno_src_rel_flavor
#****************************************************************************
sub gen_verno_src_rel_flavor
{    
	my $template = <<"__TEMPLATE";
kal_char* release_flavor(void)
{
   static kal_char build_flavor_str[] = "$flavor";
   return build_flavor_str;
}

__TEMPLATE
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;
    
    my $final_error_msg = "GENVERNO ERROR: $error_msg at $file line $line_no\n";
    print $final_error_msg;
    die $final_error_msg;
}

