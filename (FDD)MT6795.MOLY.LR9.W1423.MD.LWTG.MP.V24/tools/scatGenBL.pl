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
#*   scatGenBL.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script designed as module to be include by top level perl script
#*
#* Author:
#* -------
#*   Claudia Lo  (mtk01876)
#*
#****************************************************************************/
#use strict;
BEGIN { push @INC, './tools/' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity
use FileInfoParser;

my $feature_query_function_ptr;
my $nfb;
my $scatter_maui;
my $emiinitcode_exist;
my $emiinitcode_base;
my $emiinitcode_size;
my $sysram_base;
my $sysram_size;
my $maui_bootloader_base;
my $maui_bootloader_size;
my $maui_ext_bootloader_base;
my $maui_ext_bootloader_size;
my $g_MAKEFILE_ref;

1;

#****************************************************************************
# MAIN INTERFACE
# input: 
#****************************************************************************
sub scatGenBL_main
{
    my ($func, $bb, $rs, $bb_path, $scatter) = @_;
    
    $feature_query_function_ptr = $func;
    my $nand_flash_booting = &$func('nand_flash_booting');
    my $emmc_booting = &$func('emmc_booting');
    $nfb = "NONE";
    if ((defined $nand_flash_booting) and ($nand_flash_booting ne "NONE"))
    {
    	$nfb = $nand_flash_booting;
    }
    elsif ((defined $emmc_booting) and ($emmc_booting ne "NONE"))
    {
    	$nfb = $emmc_booting;
    }
    $scatter_maui = $scatter;
    $g_MAKEFILE_ref = &FileInfo::GetMakeFileRef(undef);

	### Parse MAUI scatter to get Sys RAM info
    open (SCATTER_H, "<$scatter_maui") or &sysUtil::sysgen_die("$scatter_maui: file error!", __FILE__, __LINE__);
    my $itcm_base;
    while (<SCATTER_H>)
    {
        if (/\s*INTSRAM_CODE\s*(0x\w+)\s*\w*/)
        {
             $itcm_base = $1;
        }
        elsif (/\s*INTSRAM_MULTIMEDIA\s*(0x\w+)\s*\w*\s*(0x\w+)/)
        {
              $sysram_base = $1;
              $sysram_size = $2;
        } 
        elsif (/\s*EXT_BOOTLOADER\s*(0x\w+)\s*\w*\s*(0x\w+)/)
        {
            $maui_ext_bootloader_base = $1;
            $maui_ext_bootloader_size = $2;
        }
        elsif (/\s*EXT_BOOTLOADER\s*(0x\w+)\s*\w*\s*/)
        {
            $maui_ext_bootloader_base = $1;
            $maui_ext_bootloader_size = undef;
        }
        elsif (/^\s*BOOTLOADER\s*(0x\w+)\s*\w*\s*(0x\w+)/)
        {
            $maui_bootloader_base = $1;
            $maui_bootloader_size = $2;
        }
        elsif (/^\s*BOOTLOADER\s*(0x\w+)\s*\w*\s*/)
        {
            $maui_bootloader_base = $1;
            $maui_bootloader_size = undef;
        } 
    }
    $sysram_base = $itcm_base if (!defined $sysram_base);
    close (SCATTER_H) or &sysUtil::sysgen_die("$scatter_maui: file error!", __FILE__, __LINE__);

    ### Generate BL scatter
    my $bl_scat_output;
    if (&sysUtil::is_sv5($bb) == 1)
    {
        $bl_scat_output .= &layout_bl_sv5($bb, $rs, $nfb);
    }
    else
    {
        $bl_scat_output .= &layout_bl_sv3($bb, $rs, $nfb);
    }
    
    ### Generate EXT-BL scatter
    my $ext_bl_scat_output = &layout_ext_bl($bb, $rs, $nfb);
 
    # Finally , return output
    return ($bl_scat_output, $ext_bl_scat_output);
}

#****************************************************************************
# subroutine:  BL SV3 Layout
# return:      the body strings
#****************************************************************************
sub layout_bl_sv3
{
    my ($bb, $rs, $nfb) = @_;
      
    # --- --- ---
    my %BBtbl_READ_ONLY_base =
       (
             'MT6268'  => '0x92002000',
             'MT6235'  => '0x40002000',
             'MT6235B' => '0x40002000',
             'MT6236'  => '0x40002000',
             'MT6252'  => '0x00000000',
             'MT6253'  => '0x00000000',
             'MT6921'  => '0x40002000',
       );
    my $read_only_base = '0x00000000'; # NOR+SV3 always starts from 0x0
    $read_only_base = &config_query_hash_bb(\%BBtbl_READ_ONLY_base, $bb, __LINE__) if ($nfb ne 'NONE');
    my $read_only_size = "";
    $read_only_size = $maui_bootloader_size if($nfb eq 'NONE');
    # --- --- ---
    my $ev_read_only = &layout_read_only_ev($bb, $rs, $nfb, $read_only_base);
    
    # --- --- ---
    my $ev_hidden_bl_secure_mac = &layout_hidden_bl_secure_mac_ev();

    my $mac_overlay;
    if ($nfb ne 'NONE' or 1 == &FileInfo::is_SmartPhone($g_MAKEFILE_ref))
    {
       $mac_overlay = "OVERLAY";
    }
    
    # --- --- --- 
    my $layout = <<"__LAYOUT";
READ_ONLY $read_only_base $read_only_size
{
$ev_read_only
}

;=========================================================================
; This load region must be behind all the protected load region
;=========================================================================
; do NOT modify load region naming and pragma naming!
;=========================================================================

__HIDDEN_BL_SECURE_MAC +0x0 $mac_overlay
{
$ev_hidden_bl_secure_mac
}

__LAYOUT

    return $layout;
}

#****************************************************************************
# subroutine:  BL SV5 Layout
# return:      the body strings
#****************************************************************************
sub layout_bl_sv5
{
    my ($bb, $rs, $nfb) = @_;
      
    # --- --- ---
    my %BBtbl_READ_ONLY_base =
       (
             'MT6276'  => '0x50000000',
             'MT6251'  => '0x40020000',
             'MT6256'  => '0x91004000',
             'MT6255'  => '0x40000900',
             'MT6280'  => '0x7000a000',
             'MT6922'  => '0x40000900',
             'MT6250'  => '0x70008000',             
       );

    my $read_only_base = &config_query_hash_bb(\%BBtbl_READ_ONLY_base, $bb, __LINE__);
    my $read_only_size = "";
    $read_only_size = $maui_bootloader_size if($nfb eq 'NONE');

    # --- --- ---
    my $ev_read_only = &layout_read_only_ev($bb, $rs, $nfb, $read_only_base);

    # --- --- --- 
    my $layout = <<"__LAYOUT";
READ_ONLY $read_only_base $read_only_size
{
$ev_read_only
}

__LAYOUT

    return $layout;
}

#****************************************************************************
# subroutine:  EXT-BL Layout
# return:      the body strings
#****************************************************************************
sub layout_ext_bl
{
    my ($bb, $rs, $nfb) = @_;
      
    # --- --- ---
    my ($ext_bootloader_base, $ext_bootloader_size);
    my $ext_bl_update_support = &$feature_query_function_ptr('ext_bl_update_support');
    if (defined $ext_bl_update_support and $ext_bl_update_support eq 'TRUE')
    {
        ### NAND: ExtMem size - 1M, NOR/N+0: fixed
        ### NAND: 1M, NOR: 512K, N+0:fixed
        if ($bb eq 'MT6251')
        {
            $ext_bootloader_base = "0x40030000";
            $ext_bootloader_size = "0x30000";
        }
        elsif ($nfb ne 'NONE' or 1 == &FileInfo::is_SmartPhone($g_MAKEFILE_ref))
        {
            $ext_bootloader_base = sprintf("0x%x", $rs - (1024*1024));
            $ext_bootloader_size = sprintf("0x%x", (1024*1024));
        }
        else
        {
            $ext_bootloader_base = sprintf("0x%x", &sysUtil::query_cs1_addr($bb ,0, 1) + 72*1024);
            $ext_bootloader_size = sprintf("0x%x", (512*1024));
        }
    }
    else
    {
        if ($nfb ne 'NONE' or 1 == &FileInfo::is_SmartPhone($g_MAKEFILE_ref))
        {
            $ext_bootloader_base = sprintf("0x%x", $rs - (1024*1024));
            $ext_bootloader_size = "";
        }
        else
        {
            $ext_bootloader_base = sprintf("0x%08x", hex($maui_ext_bootloader_base) & (~0xf8000000));
            $ext_bootloader_size = $maui_ext_bootloader_size;
            $ext_bootloader_base = sprintf("0x%08x", hex($maui_ext_bootloader_base)) if($bb eq "MT6255" or $bb eq "MT6280" or $bb eq "MT6922" or $bb eq "MT6250");
        }
    }

    # --- --- ---
    my $ev_ext_bootloader = &layout_ext_bootloader_ev($bb, $rs, $nfb, $read_only_base, $ext_bootloader_base);

    # --- --- --- 
    my $layout = <<"__LAYOUT";
EXT_BOOTLOADER $ext_bootloader_base $ext_bootloader_size
{
$ev_ext_bootloader
}

__LAYOUT

    return $layout;
}

#****************************************************************************
# subroutine:  Layout :: READ_ONLY :: Exec View
# input:       BB chip, ram size [value]
#****************************************************************************
sub layout_read_only_ev
{
    my ($bb, $rs, $nfb, $read_only_base) = @_;

    # --- --- ---
    $READ_WRITE_BASE_6921 = (($bb eq 'MT6921') and ($nfb ne 'NONE')) ? '+0x0' : '0x50000000';   
    my %BBtbl_READ_WRITE_base =
       (
             'MT6276'  => '+0x0',
             'MT6268'  => '+0x0',
             'MT6235'  => '+0x0',
             'MT6235B' => '+0x0',
             'MT6236'  => '+0x0',
             'MT6921'  => $READ_WRITE_BASE_6921,           
             'MT6252'  => '0x40009000',
             'MT6251'  => '+0x0',
             'MT6253'  => '0x40000000',
             'MT6256'  => '+0x0',
             'MT6255'  => '+0x0',
             'MT6922'  => '+0x0',
             'MT6250'  => '+0x0',             
             'MT6280'  => '+0x0',
       );

    my %BBtbl_READ_ONLY_INT_base =
       (
             'MT6276'  => '0x5000C000',
             'MT6268'  => '0x92014000',
             'MT6235'  => '0x50008000',
             'MT6235B' => '0x50008000',
             'MT6236'  => '0x50008000',
             'MT6921'  => '0x50008000',             
             'MT6252'  => '+0x0',
             'MT6251'  => '+0x0',
             'MT6253'  => '+0x0',
             'MT6256'  => '0x50000000', 
             'MT6255'  => '0x50000000',
             'MT6280'  => '0x70018000',
             'MT6922'  => '0x50000000',
             'MT6250'  => '0x70004940',             
       );

    my %BBtbl_READ_WRITE_INT_base =
       (
             'MT6276'  => '0x5004C000',
             'MT6268'  => '0x50048000',
             'MT6235'  => '0x5002E000',
             'MT6235B' => '0x5002E000',
             'MT6236'  => '0x5004E000',
             'MT6921'  => '0x5004E000',              
             'MT6252'  => '+0x0',
             'MT6251'  => '+0x0',
             'MT6253'  => '+0x0',
             'MT6256'  => '0x9100C000',
             'MT6255'  => '0x40006000',
             'MT6280'  => '+0x0',
             'MT6922'  => '0x40006000',
             'MT6250'  => '+0x0',             
       );

    my %BBtbl_EMIINIT_CODE_base =
       (
             'MT6252'  => '0x40008000',
             'MT6251'  => '0x40000080',
             'MT6253'  => '0x40000000',
             'MT6255'  => '0x40000080',
             'MT6922'  => '0x40000080',
             'MT6921'  => '0x50000000',
       );

    my %BBtbl_STACK_AREA_base =
       (
             'MT6276'  => '0x5004F000',
             'MT6268'  => '0x50052800',
             'MT6235'  => '0x50033000',
             'MT6235B' => '0x50033000',
             'MT6236'  => '0x50053000',
             'MT6921'  => '0x50053000',             
             'MT6252'  => '0x4000BC00',
             'MT6251'  => '0x4005E000',
             'MT6253'  => '0x4001F000',
             'MT6256'  => '0x50042000',
             'MT6255'  => '0x50041000',
             'MT6280'  => '0x7001f000',
             'MT6922'  => '0x50041000',
             'MT6250'  => '0x7000c400',             
       );

    my %BBtbl_DUMMY_END_base =
       (
             'MT6276'  => '0xC8014000',
             'MT6268'  => '0x92018000',
             'MT6235'  => '0x40010000',
             'MT6235B' => '0x40010000',
             'MT6236'  => '0x40010000',
             'MT6921'  => '0x40010000',
             'MT6252'  => '0x4000cc00',
             'MT6251'  => '0x40060000',
             'MT6253'  => '0x40020000',
             'MT6256'  => '0x91010000',
             'MT6255'  => '0x40007000',
             'MT6280'  => '0x70038000',
             'MT6922'  => '0x40007000',
             'MT6250'  => '0x7000d400',             
       );

    # --- --- ---
    ### NAND: ExtMem size - 4M, NOR: ExtMem size - 1.5M, N+0: fixed
    my $ext_un_init_base;
    if ($bb eq 'MT6251')
    {
    	$ext_un_init_base = "0x40007000";
    }
    elsif ($nfb ne 'NONE'  or 1 == &FileInfo::is_SmartPhone($g_MAKEFILE_ref))
    {
    	$ext_un_init_base = sprintf("0x%x", $rs - (4*1024*1024));
    }
    else
    {
    	$ext_un_init_base = sprintf("0x%x", &sysUtil::query_cs1_addr($bb, 0, 1) + ($rs - (1.5*1024*1024)));
    }

    # --- --- ---
    ### NAND: 8K, NOR: 8K, N+0: Last 8K of IntRam
    ### N+0:4K, others: 64K
    my ($share_buf_base, $share_buf_size);
    if ($bb eq 'MT6251')
    {
    	$share_buf_base = "0x4005F000";
    	$share_buf_size = "0x1000"
    }
    elsif ($nfb ne 'NONE'  or 1 == &FileInfo::is_SmartPhone($g_MAKEFILE_ref))
    {
    	$share_buf_base = sprintf("0x%x", 8*1024);
    	$share_buf_size = "0x10000";
    }
    else
    {
    	$share_buf_base = sprintf("0x%x", &sysUtil::query_cs1_addr($bb,0, 1)+(8*1024));
    	$share_buf_size = "0x10000";
    }
    
    # --- --- ---
    my @bl_gfh_section_libs = split("\n", &BL_GFH_SECTION_EV());
    map { s/^\s+//; } @bl_gfh_section_libs;

    my @read_only_libs = split("\n", &READ_ONLY_EV());
    map { s/^\s+//; } @read_only_libs;

    my @read_only_head_libs = split("\n", &READ_ONLY_HEAD_EV());
    map { s/^\s+//; } @read_only_head_libs;

    my @read_only_int_libs = split("\n", &READ_ONLY_INT_EV());
    map { s/^\s+//; } @read_only_int_libs;
    
    my @read_write_int_libs = split("\n", &READ_WRITE_INT_EV());
    map { s/^\s+//; } @read_write_int_libs;

    my @stack_area_libs = split("\n", &STACK_AREA_EV());
    map { s/^\s+//; } @stack_area_libs;

    my @ext_un_init_libs = split("\n", &EXT_UN_INIT_EV());
    map { s/^\s+//; } @ext_un_init_libs;

    # --- --- ---
    my $template;
    if (&sysUtil::is_sv5($bb) == 1)  # Only generate on SV5 platform
    {
	    $template .= &format_execution_view('BL_GFH_SECTION',
	                                        '+0x0',
	                                        undef,
	                                        \@bl_gfh_section_libs);
    }
    $template .= &format_execution_view('READ_ONLY',
                                        '+0x0',
                                        undef,
                                        \@read_only_libs);
    $template .= &format_execution_view('READ_ONLY_HEAD',
                                        '+0x0',
                                        undef,
                                        \@read_only_head_libs);
    if (&sysUtil::is_sv5($bb) != 1)  # Only generate on non-SV5 platform
    {
    	my $bl_alg_table_base = sprintf("0x%x FIXED", hex($read_only_base)+0x400);
	    $template .= &format_execution_view('BL_ALG_TABLE',
	                                        $bl_alg_table_base,
	                                        undef,
	                                        ["*.obj (BL_ALG_TABLE)"]);
	    $template .= &format_execution_view('BL_SECINFO',
	                                        '+0x0',
	                                        undef,
	                                        ["*.obj (BL_SECINFO)"]);
    }
    $template .= &format_execution_view('READ_ONLY_TAIL',
                                        '+0x0',
                                        undef,
                                        ["* (+RO)"]);
    $template .= &format_execution_view('READ_WRITE',
                                        &config_query_hash_bb(\%BBtbl_READ_WRITE_base, $bb, __LINE__),
                                        undef,
                                        ["* (+RW, +ZI)"]);
    $template .= &format_execution_view('READ_ONLY_INT',
                                        &config_query_hash_bb(\%BBtbl_READ_ONLY_INT_base, $bb, __LINE__),
                                        undef,
                                        \@read_only_int_libs);
    $template .= &format_execution_view('READ_WRITE_INT',
                                        &config_query_hash_bb(\%BBtbl_READ_WRITE_INT_base, $bb, __LINE__),
                                        undef,
                                        \@read_write_int_libs);
    if ((&sysUtil::is_sv5($bb) == 1) or ($nfb ne 'NONE') or 1 == &FileInfo::is_SmartPhone($g_MAKEFILE_ref) )
    {
	    $template .= &format_execution_view('EMIINIT_CODE',
	                                        '+0x0',
	                                        undef,
	                                        ["*                            (EMIINITZI)"]);
    }
    else
    {
    	my $emiinit_code_base = &config_query_hash_bb(\%BBtbl_EMIINIT_CODE_base, $bb, __LINE__) . " OVERLAY";
	    $template .= &format_execution_view('EMIINIT_CODE',
	                                        $emiinit_code_base,
	                                        undef,
	                                        ["*                            (EMIINITCODE, EMIINITCONST, EMIINITRW, EMIINITZI)"]);
    }
    $template .= &format_execution_view('STACK_AREA_NOINIT',
                                        &config_query_hash_bb(\%BBtbl_STACK_AREA_base, $bb, __LINE__),
                                        '0x1000',
                                        \@stack_area_libs);
    $template .= &format_execution_view('EXT_UN_INIT_NOINIT',
                                        $ext_un_init_base,
                                        undef,
                                        \@ext_un_init_libs);
    $template .= &format_execution_view('SHARE_BUF_NOINIT',
                                        $share_buf_base,
                                        $share_buf_size,
                                        ["*                          (MINI_EXT_DA_SHARE)"]);
    if ($nfb ne 'NONE' or 1 == &FileInfo::is_SmartPhone($g_MAKEFILE_ref))  # Only generate on NFB
    {
        $template .= &format_execution_view('READ_WRITE_SYS_RAM',
                                            $sysram_base,
                                            '0x2000',
                                            ["bl_ImageLoaderCommon.obj (BL_INFO_SHARED_ZI)"]);
    }
    $template .= &format_execution_view('DUMMY_END',
                                        &config_query_hash_bb(\%BBtbl_DUMMY_END_base, $bb, __LINE__),
                                        '0x04',
                                        ["bl_bootarm_rvct.obj (DUMMY_POOL)"]);
	if (&sysUtil::is_sv5($bb) == 1)  # Only generate on SV5 platform
	{
	    $template .= &format_execution_view('BL_SIGNATURE_SECTION',
	                                        '+0x0',
	                                        undef,
	                                        ["*                     (BL_SIGNATURE_SECTION)"]);
	}
    chomp $template;
    return $template;
}

#****************************************************************************
# subroutine:  Layout :: EXT_BOOTLOADER :: Exec View
# input:       BB chip, ram size [value]
#****************************************************************************
sub layout_ext_bootloader_ev
{
    my ($bb, $rs, $nfb, $read_only_base, $ext_bootloader_base) = @_;

    # --- --- ---
    my %BBtbl_EXT_READ_ONLY_INT_base =
       (
             'MT6276'  => '0x5000C000',
             'MT6268'  => '0x92014000',
             'MT6235'  => '0x50008000',
             'MT6235B' => '0x50008000',
             'MT6236'  => '0x50008000',
             'MT6921'  => '0x50008000',
             'MT6252'  => '0x40008080',
             'MT6251'  => '+0x0',
             'MT6253'  => '0x40000080',
             'MT6256'  => '0x50000000',
             'MT6255'  => '0x50000000',
             'MT6280'  => '0x70018000',
             'MT6922'  => '0x50000000',
             'MT6250'  => '0x700040c0',             
       );

    my %BBtbl_EXT_READ_WRITE_INT_base =
       (
             'MT6276'  => '0x5004C000',
             'MT6268'  => '0x50048000',
             'MT6235'  => '0x5002E000',
             'MT6235B' => '0x5002E000',
             'MT6236'  => '0x5004E000',
             'MT6921'  => '0x5004E000',            
             'MT6252'  => '+0x0',
             'MT6251'  => '+0x0',
             'MT6253'  => '+0x0',
             'MT6256'  => '0x9100C000',
             'MT6255'  => '0x40006000',
             'MT6280'  => '+0x0',
             'MT6922'  => '0x40006000',
             'MT6250'  => '+0x0',             
       );

    my %BBtbl_STACK_AREA_base =
       (
             'MT6276'  => '0x5004F000',
             'MT6268'  => '0x50052800',
             'MT6235'  => '0x50033000',
             'MT6235B' => '0x50033000',
             'MT6236'  => '0x50053000',
             'MT6921'  => '0x50053000',
             'MT6252'  => '0x4000BC00',
             'MT6251'  => '0x4005E000',
             'MT6253'  => '0x4001F000',
             'MT6256'  => '0x50042000',
             'MT6255'  => '0x50041000',
             'MT6280'  => '0x7001f000',
             'MT6922'  => '0x50041000',
             'MT6250'  => '0x7000c400',             
       );

    my %BBtbl_BL_INFO_NOR_base =  #Sysram Base
       (
             'MT6252'  => '0x40008000',
             'MT6251'  => '0x40000080',
             'MT6253'  => '0x40000000',
             'MT6921'  => '0x40000000',
             'MT6255'  => '0x40000000',
             'MT6280'  => '0x70000040',
       );

    my %BBtbl_DUMMY_END_base =
       (
             'MT6276'  => '0xC8014000',
             'MT6268'  => '0x92018000',
             'MT6235'  => '0x40010000',
             'MT6235B' => '0x40010000',
             'MT6236'  => '0x40010000',
             'MT6921'  => '0x40010000',            
             'MT6252'  => '0x4000cc00',
             'MT6251'  => '0x40060000',
             'MT6253'  => '0x40020000',
             'MT6256'  => '0x91010000',
             'MT6255'  => '0x40007000',
             'MT6280'  => '0x70038000',
       );

    # --- --- ---
    my $ext_read_write_base;
    my $ext_bl_update_support = &$feature_query_function_ptr('ext_bl_update_support');
    if ($nfb ne 'NONE' or (defined $ext_bl_update_support and $ext_bl_update_support eq 'TRUE')
     or 1 == &FileInfo::is_SmartPhone($g_MAKEFILE_ref))
    {
    	$ext_read_write_base = "+0x0";
    }
    else
    {
        if ($bb eq 'MT6251')
        {
    	    $ext_read_write_base = "0x40030000";
        }
        else
        {
            $ext_read_write_base = sprintf("0x%x", &sysUtil::query_cs1_addr($bb,0, 1) + 72*1024);
        }
    }
    
    # --- --- ---
    ### NAND: ExtMem size - 4M, NOR: ExtMem size - 1.5M, N+0: fixed
    my $ext_un_init_base;
    if ($bb eq 'MT6251')
    {
    	$ext_un_init_base = "0x40007000";
    }
    elsif ($nfb ne 'NONE' or 1 == &FileInfo::is_SmartPhone($g_MAKEFILE_ref))
    {
    	$ext_un_init_base = sprintf("0x%x", $rs - (4*1024*1024));
    }
    else
    {
    	$ext_un_init_base = sprintf("0x%x", &sysUtil::query_cs1_addr($bb,0, 1) + ($rs - (1.5*1024*1024)));
    }

    # --- --- ---
    ### NAND: 8K, NOR: 8K, N+0: Last 8K of IntRam
    ### N+0:4K, others: 64K
    my ($share_buf_base, $share_buf_size);
    if ($bb eq 'MT6251')
    {
    	$share_buf_base = "0x4005F000";
    	$share_buf_size = "0x1000"
    }
    elsif ($nfb ne 'NONE' or 1 == &FileInfo::is_SmartPhone($g_MAKEFILE_ref))
    {
    	$share_buf_base = sprintf("0x%x", 8*1024);
    	$share_buf_size = "0x10000";
    }
    else
    {
    	$share_buf_base = sprintf("0x%x", &sysUtil::query_cs1_addr($bb,0, 1)+(8*1024));
    	$share_buf_size = "0x10000";
    }
    
    # --- --- ---
    my @ext_read_only_head_libs = split("\n", &EXT_READ_ONLY_HEAD_EV());
    map { s/^\s+//; } @ext_read_only_head_libs;

    my @ext_read_only_int_libs = split("\n", &EXT_READ_ONLY_INT_EV($bb));
    map { s/^\s+//; } @ext_read_only_int_libs;
    
    my @ext_read_write_int_libs = split("\n", &EXT_READ_WRITE_INT_EV($bb));
    map { s/^\s+//; } @ext_read_write_int_libs;

    my @da_share_libs = split("\n", &DA_SHARE_EV());
    map { s/^\s+//; } @da_share_libs;

    my @ext_un_init_libs = split("\n", &EXT_UN_INIT_EV());
    map { s/^\s+//; } @ext_un_init_libs;

    # --- --- ---
    my $template;
    if (&sysUtil::is_sv5($bb) == 1)  # Only generate on SV5 platform
    {
	    $template .= &format_execution_view('EXT_BL_GFH_SECTION',
	                                        '+0x0',
	                                        undef,
	                                        ["*    (EXT_BOOTLOADER_GFH, +First)"]);
    }
    $template .= &format_execution_view('EXT_READ_ONLY',
                                        '+0x0',
                                        undef,
                                        ["bl_bootarm_rvct.obj (VECTOR_TBL, +First)"]);
    $template .= &format_execution_view('EXT_READ_ONLY_HEAD',
                                        '+0x0',
                                        undef,
                                        \@ext_read_only_head_libs);
    if (&sysUtil::is_sv5($bb) != 1)  # Only generate on non-SV5 platform
    {
    	my $ext_bl_alg_table_base = sprintf("0x%x FIXED", hex($ext_bootloader_base)+0x400);
	    $template .= &format_execution_view('BL_ALG_TABLE',
	                                        $ext_bl_alg_table_base,
	                                        undef,
	                                        ["*.obj (BL_ALG_TABLE)"]);
	    $template .= &format_execution_view('BL_SECINFO',
	                                        '+0x0',
	                                        undef,
	                                        ["*.obj (BL_SECINFO)"]);
    }                                                
    $template .= &format_execution_view('EXT_READ_ONLY_TAIL',
                                        '+0x0',
                                        undef,
                                        ["* (+RO)"]);
    $template .= &format_execution_view('EXT_READ_WRITE',
                                        $ext_read_write_base,
                                        undef,
                                        ["* (+RW, +ZI)"]);
    $template .= &format_execution_view('EXT_READ_ONLY_INT',
                                        &config_query_hash_bb(\%BBtbl_EXT_READ_ONLY_INT_base, $bb, __LINE__),
                                        undef,
                                        \@ext_read_only_int_libs);
    $template .= &format_execution_view('EXT_READ_WRITE_INT',
                                        &config_query_hash_bb(\%BBtbl_EXT_READ_WRITE_INT_base, $bb, __LINE__),
                                        undef,
                                        \@ext_read_write_int_libs);
    if ($bb eq 'MT6251')
    {
	    $template .= &format_execution_view('DA_SHARE',
	                                        '0x40000A00',
	                                        undef,
	                                        \@da_share_libs);
    }
    $template .= &format_execution_view('STACK_AREA_NOINIT',
                                        &config_query_hash_bb(\%BBtbl_STACK_AREA_base, $bb, __LINE__),
                                        '0x1000',
                                        ["bl_bootarm_rvct.obj               (STACK_POOL_INTSRAM)"]);
    $template .= &format_execution_view('EXT_UN_INIT_NOINIT',
                                        $ext_un_init_base,
                                        undef,
                                        \@ext_un_init_libs);
    $template .= &format_execution_view('SHARE_BUF_NOINIT',
                                        $share_buf_base,
                                        $share_buf_size,
                                        ["*                            (MINI_EXT_DA_SHARE)"]);
    if ($nfb ne 'NONE' or 1 == &FileInfo::is_SmartPhone($g_MAKEFILE_ref))  # Only generate on NFB
    {
        $template .= &format_execution_view('READ_WRITE_SYS_RAM',
                                            $sysram_base,
                                            '0x2000',
                                            ["bl_ImageLoaderCommon.obj     (BL_INFO_SHARED_ZI)"]);
    }
    else  # Only generate on NOR
    {
        $template .= &format_execution_view('BL_INFO_NOR',
                                            &config_query_hash_bb(\%BBtbl_BL_INFO_NOR_base, $bb, __LINE__),
                                            '0x80',
                                            ["*.obj                        (BL_INFO_SHARED_ZI)"]);
    }
    $template .= &format_execution_view('DUMMY_END',
                                        &config_query_hash_bb(\%BBtbl_DUMMY_END_base, $bb, __LINE__),
                                        '0x04',
                                        ["bl_bootarm_rvct.obj (DUMMY_POOL)"]);
	if (&sysUtil::is_sv5($bb) == 1)  # Only generate on SV5 platform
	{
	    $template .= &format_execution_view('EXT_BL_SIGNATURE_SECTION',
	                                        '+0x0',
	                                        undef,
	                                        ["*                            (EXT_BL_SIGNATURE_SECTION)"]);
	}
    chomp $template;
    return $template;
}

#****************************************************************************
# subroutine:  Layout :: __HIDDEN_BL_SECURE_MAC :: Exec View
# input:       BB chip, ram size [value]
#****************************************************************************
sub layout_hidden_bl_secure_mac_nfb_ev
{
    my $template;
    $template .= &format_execution_view('__HIDDEN_BL_SECURE_MAC',
                                        '+0x0 OVERLAY',
                                        undef,
                                        ["*.obj (BL_SECURE_MAC_SIZE)"]);
    $template .= &format_execution_view('__HIDDEN_BL_SECURE_MAC_CONTENT',
                                        '+0x0 OVERLAY',
                                        undef,
                                        ["*.obj (BL_SECURE_MAC_CONTENT)"]);
    $template .= &format_execution_view('__HIDDEN_SECURE_MAC',
                                        '+0x0 OVERLAY',
                                        undef,
                                        ["*.obj (FOTA_SECINFO)"]);
    chomp $template;
    return $template;
}

#****************************************************************************
# subroutine:  Layout :: __HIDDEN_BL_SECURE_MAC :: Exec View
# input:       BB chip, ram size [value]
#****************************************************************************
sub layout_hidden_bl_secure_mac_ev
{
    my $template;
    $template .= &format_execution_view('__HIDDEN_BL_SECURE_MAC',
                                        '+0x0',
                                        undef,
                                        ["*.obj (BL_SECURE_MAC_SIZE)"]);
    $template .= &format_execution_view('__HIDDEN_BL_SECURE_MAC_CONTENT',
                                        '+0x0',
                                        undef,
                                        ["*.obj (BL_SECURE_MAC_CONTENT)"]);
    $template .= &format_execution_view('__HIDDEN_SECURE_MAC',
                                        '+0x0',
                                        undef,
                                        ["*.obj (FOTA_SECINFO)"]);
    chomp $template;
    return $template;
}

#****************************************************************************
# subroutine:  NFB Layout :: EXT_READ_ONLY
# return:      the body strings
#****************************************************************************
sub BL_GFH_SECTION_EV
{
    my $template = <<"__TEMPLATE";
         *                     (BOOTLOADER_GFH, +First)
         *                     (BOOTLOADER_GFH_EXT)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Layout :: READ_ONLY
# return:      the body strings
#****************************************************************************
sub READ_ONLY_EV
{
    my $template .= <<"__TEMPLATE";
         bl_bootarm_rvct.obj (VECTOR_TBL, +First)
         * (BL_RESV_REGION)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Layout :: READ_ONLY_HEAD
# return:      the body strings
#****************************************************************************
sub READ_ONLY_HEAD_EV
{
    my $template .= <<"__TEMPLATE";
         bl_bootarm_rvct.obj (C\$\$code, +First)
         *.obj (HEAD_BL)
         * (INIT_CODE)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Layout :: READ_ONLY_INT
# return:      the body strings
#****************************************************************************
sub READ_ONLY_INT_EV
{
    my $template = <<"__TEMPLATE";
         sha1_engine.obj                  (+RO)
         md5_engine.obj                   (+RO)
         br_crypto_asm.obj                (+RO)
         br_crypto_drv*.obj               (+RO)
         br_sha256_sw.obj                 (+RO)
         br_sha256_hw.obj                 (+RO)
         br_sha1_sw.obj                   (+RO)
         br_sha1_hw.obj                   (+RO)
         br_rsa_sw.obj                    (+RO)
         br_M1_rsa.obj                    (+RO)
         br_crypto_platform.obj           (+RO)
         *                                (INTERNCODE)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Layout :: READ_ONLY_INT
# return:      the body strings
#****************************************************************************
sub READ_WRITE_INT_EV
{
    my $template = <<"__TEMPLATE";
         sha1_engine.obj                  (+RW, +ZI)
         md5_engine.obj                   (+RW, +ZI)
         br_crypto_asm.obj                (+RW, +ZI)
         br_crypto_drv*.obj               (+RW, +ZI)
         br_sha256_sw.obj                 (+RW, +ZI)
         br_sha256_hw.obj                 (+RW, +ZI)
         br_sha1_sw.obj                   (+RW, +ZI)
         br_sha1_hw.obj                   (+RW, +ZI)
         br_rsa_sw.obj                    (+RW, +ZI)
         br_M1_RSA.obj                    (+RW, +ZI)
         br_crypto_platform.obj           (+RW, +ZI)
         *                            (INTERNDATA)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Layout :: STACK_AREA
# return:      the body strings
#****************************************************************************
sub STACK_AREA_EV
{
    my $template = <<"__TEMPLATE";
         bl_bootarm_rvct.obj               (STACK_POOL_INTSRAM)
         br_time_stamp.obj            (UN_INIT_RW, UN_INIT_ZI)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Layout :: EXT_UN_INIT
# return:      the body strings
#****************************************************************************
sub EXT_UN_INIT_EV
{
    my $template = <<"__TEMPLATE";
         *                            (EXT_UN_INIT_RW, EXT_UN_INIT_ZI)
         bl_cache.obj                 (BL_PAGETABLE)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  EXT_READ_ONLY_HEAD
# return:      the body strings
#****************************************************************************
sub EXT_READ_ONLY_HEAD_EV
{
    my $template = <<"__TEMPLATE";
         bl_bootarm_rvct.obj (C\$\$code, +First)
         *.obj (HEAD_BL)
         * (INIT_CODE)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Layout :: EXT_READ_ONLY_INT
# return:      the body strings
#****************************************************************************
sub EXT_READ_ONLY_INT_EV
{
	my ($bb) = @_;
	
	my $template;
	if ($bb eq 'MT6251')
	{
		$template = <<"__TEMPLATE";
         br_crypto_asm.obj            (+RO)
         br_crypto_drv*.obj           (+RO)
         br_sha256_sw.obj             (+RO)
         br_sha256_hw.obj             (+RO)
         br_sha1_sw.obj               (+RO)
         br_sha1_hw.obj               (+RO)
         br_rsa_sw.obj                (+RO)
         br_M1_rsa.obj                (+RO)
         br_crypto_platform.obj       (+RO)
         *                            (INTERNCODE)
__TEMPLATE
	}
	else
	{
		$template = <<"__TEMPLATE";
         sha1_engine.obj              (+RO)
         md5_engine.obj               (+RO)
         br_crypto_asm.obj            (+RO)
         br_crypto_drv*.obj           (+RO)
         br_sha256_sw.obj             (+RO)
         br_sha256_hw.obj             (+RO)
         br_sha1_sw.obj               (+RO)
         br_sha1_hw.obj               (+RO)
         br_rsa_sw.obj                (+RO)
         br_M1_rsa.obj                (+RO)
         br_crypto_platform.obj       (+RO)
         *                            (INTERNCODE)
__TEMPLATE
	}
	my $serial_flash_stt_support = &$feature_query_function_ptr('serial_flash_stt_support');
    if (defined $serial_flash_stt_support and $serial_flash_stt_support eq 'TRUE')
    {
        my $stt_template = << "__TEMPLATE";
         divrt_9e.o                   (+RO)
         bl_STT_SF.obj                (+RO)
         bl_DBGPRINT.obj              (+RO)
         bl_UART.obj                  (+RO)
__TEMPLATE
        $template .= $stt_template;
    }
    return $template;
}

#****************************************************************************
# subroutine:  Layout :: EXT_READ_WRITE_INT
# return:      the body strings
#****************************************************************************
sub EXT_READ_WRITE_INT_EV
{
	my ($bb) = @_;
	
	my $template;
	if ($bb eq 'MT6251')
	{
		$template = <<"__TEMPLATE";
         br_crypto_asm.obj            (+RW, +ZI)
         br_crypto_drv*.obj           (+RW, +ZI)
         br_sha256_sw.obj             (+RW, +ZI)
         br_sha256_hw.obj             (+RW, +ZI)
         br_sha1_sw.obj               (+RW, +ZI)
         br_sha1_hw.obj               (+RW, +ZI)
         br_rsa_sw.obj                (+RW, +ZI)
         br_M1_RSA.obj                (+RW, +ZI)
         br_crypto_platform.obj       (+RW, +ZI)
         *                            (INTERNDATA)
__TEMPLATE
	}
	else
	{
		$template = <<"__TEMPLATE";
         sha1_engine.obj              (+RW, +ZI)
         md5_engine.obj               (+RW, +ZI)
         br_crypto_asm.obj            (+RW, +ZI)
         br_crypto_drv*.obj           (+RW, +ZI)
         br_sha256_sw.obj             (+RW, +ZI)
         br_sha256_hw.obj             (+RW, +ZI)
         br_sha1_sw.obj               (+RW, +ZI)
         br_sha1_hw.obj               (+RW, +ZI)
         br_rsa_sw.obj                (+RW, +ZI)
         br_M1_RSA.obj                (+RW, +ZI)
         br_crypto_platform.obj       (+RW, +ZI)
         *                            (INTERNDATA)
__TEMPLATE
	}

    return $template;
}

#****************************************************************************
# subroutine:  Layout :: DA_SHARE
# return:      the body strings
#****************************************************************************
sub DA_SHARE_EV
{
	my $template = <<"__TEMPLATE";
         *.l                          (+RO, +RW, +ZI)
         bl_bootarm_rvct.obj               (SHARECODE)
         bl_DBGPRINT.obj              (+RO, +RW, +ZI)
         bl_portingfunc.obj           (+RO, +RW, +ZI)
         bl_UART.obj                  (+RO, +RW, +ZI)
         sha1_engine.obj              (+RO, +RW, +ZI)
         md5_engine.obj               (+RO, +RW, +ZI)
         M1_rsa.obj                   (+RO, +RW, +ZI)
         SSS_interface.obj            (+RO, +RW, +ZI)
         SSS_secure_shared.obj        (+RO, +RW, +ZI)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Execution View Generator
# input:       Region name [string], Begin [string], Length [string], Content [Array Reference]
# output:      execution view body string
#****************************************************************************
sub format_execution_view
{
    my ($name, $begin, $length, $ar) = @_;
    my $formated_string = ' ' x 4 . $name . " $begin $length\n";
    $formated_string .= ' ' x 4 . "{\n";
    foreach (@$ar)
    {
        $formated_string .= ' ' x 9 . $_ . "\n";
    }
    $formated_string .= ' ' x 4 . "}\n";
    return $formated_string;
}

#****************************************************************************
# subroutine:  config_query_hash_bb
# return:      address/size defined in the input hash of the input bb
#****************************************************************************
sub config_query_hash_bb
{
    my ($href, $bb, $Line) = @_;
    if (not exists $href->{$bb})
    {
        print "tools/scatGenBL.pl:[Line$Line]Unsupported Bootloader Scatter information on $bb !\n";
        exit 0;
    }

    return $href->{$bb};
}
