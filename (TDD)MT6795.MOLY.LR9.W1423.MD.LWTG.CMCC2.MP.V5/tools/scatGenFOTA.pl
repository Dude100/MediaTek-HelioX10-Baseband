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
#*   scatGenFOTA.pl
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
#*
#****************************************************************************/
#use strict;
BEGIN { push @INC, './tools/' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity

my $nfb;
my $scatter_maui;
my $fota_cfg_href;
       
1;

#****************************************************************************
# MAIN INTERFACE
# input: 
#****************************************************************************
sub scatGenFOTA_main
{
    my ($func, $bb, $rs, $fota_cfg, $bb_path, $scatter) = @_;
    
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
    $scatter_maui  = $scatter;
    $fota_cfg_href = $fota_cfg;

    # SW Feature dispatch decision tree
    my $output_result = &layout_fota($bb, $rs, $nfb);

    # Finally , return output
    return $output_result;
}

#****************************************************************************
# subroutine:  FOTA Scatter Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout_fota
{
    my ($bb, $rs, $nfb) = @_;
	   
    # --- --- ---
    my ($emiinitcode_base, $intsram_base, $itcm_base, $dtcm_base, $sysram_base, $sysram_size, $hidden_secure_mac_base);
    open (SCATTER_H, "<$scatter_maui") or &sysUtil::sysgen_die("$scatter_maui: file error!", __FILE__, __LINE__);
    while (<SCATTER_H>)
    {
    	   if (/\s*EMIINIT_CODE\s*(0x\w+)\s*\w*\s*(0x\w+)*/)
    	   {
    	   	   $emiinitcode_base = $1;
    	   }
    	   if (/\s*INTSRAM\s*(0x\w+)\s*\w*\s*(0x\w+)/)
    	   {
    	   	   $intsram_base = $1;
    	   }
    	   if (/\s*INTSRAM_CODE\s*(0x\w+)\s*\w*\s*(0x\w+)/)
    	   {
    	   	   $itcm_base  = $1;
    	   }
    	   if (/\s*INTSRAM_DATA\s*(0x\w+)\s*\w*\s*(0x\w+)/)
    	   {
    	   	   $dtcm_base = $1;
    	   }
    	   if (/\s*INTSRAM_MULTIMEDIA\s*(0x\w+)\s*\w*\s*(0x\w+)/)
    	   {
    	   	   $sysram_base = $1;
               $sysram_size = $2;
    	   }
    	   if (/^__HIDDEN_SECURE_MAC\s*(0x\w+)\s*\w*/ or /^__HIDDEN_SECURE_MAC\s*(\+0x\w+)\s*\w*/)
    	   {
    	   	   $hidden_secure_mac_base = $1;
    	   }
    }
    close (SCATTER_H) or &sysUtil::sysgen_die("$scatter_maui: file error!", __FILE__, __LINE__);

    # --- --- ---
    my $ua_rom_base = $fota_cfg_href->{'FOTA_UE_EXECUTION_BASE'};
    my $ua_rom_size = $fota_cfg_href->{'CONFIG_FOTA_UE_FLASH_SPACE'};
    
    # --- --- ---
    my ($ua_intsram_code_base, $ua_intsram_data_base);
    if (defined $emiinitcode_base)
    {
        $ua_intsram_code_base = $emiinitcode_base;
        if ((defined $sysram_base) and ($nfb eq 'NONE'))
        {
            $ua_intsram_data_base = sprintf("0x%08X", hex($sysram_base));
        }
        elsif (defined $dtcm_base)
        {
            $ua_intsram_data_base = $dtcm_base
        }
    }
    elsif (defined $itcm_base)
    {
        $ua_intsram_code_base = $itcm_base;
        if ((defined $sysram_base) and ($nfb eq 'NONE'))
        {
            $ua_intsram_data_base = sprintf("0x%08X", hex($sysram_base));
        }
        elsif (defined $dtcm_base)
        {
            $ua_intsram_data_base = $dtcm_base
        }
        else
        {
            $ua_intsram_data_base = sprintf("0x%08X", hex($itcm_base) + hex('0x8000'));
        }
    }
    elsif (defined $intsram_base)
    {
        $ua_intsram_code_base = $intsram_base;
        if ((defined $sysram_base) and ($nfb eq 'NONE'))
        {
            $ua_intsram_data_base = sprintf("0x%08X", hex($sysram_base));
        }
        else
        {
            $ua_intsram_data_base = sprintf("0x%08X", hex($intsram_base) + hex('0x8000'));
        }
    }
    elsif (defined $sysram_base)
    {
        $ua_intsram_code_base = sprintf("0x%08X", hex($sysram_base));
        $ua_intsram_data_base = sprintf("0x%08X", hex($sysram_base) + hex('0x8000'));
    }
	   
    # --- --- ---
    my ($bl_ua_shared_sys_ram_base, $ua_maui_shared_sys_ram_base);
    if (defined $sysram_base)
    {
        $bl_ua_shared_sys_ram_base   = $sysram_base;
        $ua_maui_shared_sys_ram_base = sprintf("0x%08X", hex($sysram_base) + hex($sysram_size) - hex('0x1000'));
    }
    else
    {
        &sysUtil::sysgen_die("tools/scatGenFOTA.pl: No SysRAM to put BL_UA_SHARED_SYS_RAM and UA_MAUI_SHARED_SYS_RAM!", __FILE__, __LINE__)
            if ($nfb ne 'NONE');
    }
	   
    # --- --- ---
    my $ev_ua_rom         = &layout_ua_rom_ev($nfb, $bb, $ua_rom_base, $ua_rom_size, $ua_intsram_code_base, $ua_intsram_data_base, $bl_ua_shared_sys_ram_base, $ua_maui_shared_sys_ram_base);
    my $hidden_secure_mac = &layout_hidden_secure_mac($bb, $hidden_secure_mac_base);
    chomp $hidden_secure_mac;

    # --- --- --- 
    my $layout = <<"__LAYOUT";
UA_ROM $ua_rom_base $ua_rom_size
{
$ev_ua_rom
}

$hidden_secure_mac

__LAYOUT

    return $layout;
}

#****************************************************************************
# subroutine:  FOTA Layout :: UA_ROM :: Exec View
# input:       BB chip, ram size [value]
#****************************************************************************
sub layout_ua_rom_ev
{
    my ($nfb, $bb, $ua_rom_base, $ua_rom_size, $ua_intsram_code_base, $ua_intsram_data_base, $bl_ua_shared_sys_ram_base, $ua_maui_shared_sys_ram_base) = @_;

    # --- --- ---
    my $ua_noncached_base;
    if ($nfb ne 'NONE')
    {
        $ua_noncached_base = sprintf("0x%08X", hex($ua_rom_base) - hex('0x200000'));  # The last 2MB of UA_ROM
    }
    else
    {
        $ua_noncached_base = sprintf("0x%08X", hex($ua_rom_base) - hex('0x100000'));  # The last 1MB of UA_ROM
    }

    # --- --- ---
    # In TCM only platform (Arm7), the UA_INTSRAM_CODE and UA_INTSRAM_DATA are from MAUI. FUE may fail to link if the partition for MAUI is not suitable for FUE.
    # So FUE CODE/DATA partition should be independent from MAUI
    my ($ua_intsram_code_base_final, $ua_intsram_code_size_final, $ua_intsram_data_base_final, $ua_intsram_data_size_final);
    if (&sysUtil::is_arm9($bb) == 1 or &sysUtil::is_arm11($bb)==1 )
    {
    	$ua_intsram_code_base_final = $ua_intsram_code_base;
    	$ua_intsram_code_size_final = '0x8000';
    	$ua_intsram_data_base_final = $ua_intsram_data_base;
    	$ua_intsram_data_size_final = '0x2000';
    }
    else
    {
    	$ua_intsram_code_base_final = $ua_intsram_code_base;
    	$ua_intsram_code_size_final = undef;
    	$ua_intsram_data_base_final = '+0x0';
    	$ua_intsram_data_size_final = undef;
    }

    # --- --- ---
    my @ua_init_libs = split("\n", &UA_INIT_EV());
    map { s/^\s+//; } @ua_init_libs;

    my @ua_rom_libs = split("\n", &UA_ROM_EV());
    map { s/^\s+//; } @ua_rom_libs;
    
    my @ua_noncached_libs = split("\n", &UA_NONCACHED_EV());
    map { s/^\s+//; } @ua_noncached_libs;
    
    my @ua_rw_libs = split("\n", &UA_RW_EV());
    map { s/^\s+//; } @ua_rw_libs;
    
    my @ua_intsram_code_libs = split("\n", &UA_INTSRAM_CODE_EV());
    map { s/^\s+//; } @ua_intsram_code_libs;
    
    my @ua_intsram_data_libs = split("\n", &UA_INTSRAM_DATA_EV());
    map { s/^\s+//; } @ua_intsram_data_libs;

    my @bl_ua_shared_sys_ram_libs = split("\n", &BL_UA_SHARED_SYS_RAM_EV());
    map { s/^\s+//; } @bl_ua_shared_sys_ram_libs;

    # --- --- ---
    my $template;
    if (&sysUtil::is_sv5($bb) == 1)
    {
        $template .= &format_execution_view('UA_GFH_SECTION',
                                            '+0x0',
                                            undef,
                                            ["*                     (FUE_GFH, +First)"]);
    }
    $template .= &format_execution_view('UA_INIT',
                                        '+0x0',
                                        '0x400',
                                        \@ua_init_libs);
    $template .= &format_execution_view('UA_ROM',
                                        '+0x0',
                                        undef,
                                        \@ua_rom_libs);
    $template .= &format_execution_view('UA_RW',
                                        '+0x1000',
                                        undef,
                                        \@ua_rw_libs);
    $template .= &format_execution_view('UA_NONCACHED',
                                        $ua_noncached_base,
                                        undef,
                                        \@ua_noncached_libs);
    $template .= &format_execution_view('UA_CUSTOM_ZI',
                                        '0x1000',
                                        undef,
                                        ["*.obj (FOTA_CUSTOM_POOL)"]);
    $template .= &format_execution_view('UA_BL_INFO',
                                        '0x0',
                                        '0x80',
                                        ["*.obj (FOTA_BL_INFO)"]);
    $template .= &format_execution_view('UA_INTSRAM_CODE',
                                        $ua_intsram_code_base_final,
                                        $ua_intsram_code_size_final,
                                        \@ua_intsram_code_libs);
    $template .= &format_execution_view('UA_RESIDENT_PART',
                                        '+0x0',
                                        undef,
                                        ["*.obj (FOTA_RESIDENT_PART)  ;for codes that are used to load Primary ROM image"]);
    $template .= &format_execution_view('UA_INTSRAM_DATA',
                                        $ua_intsram_data_base_final,
                                        $ua_intsram_data_size_final,
                                        \@ua_intsram_data_libs);
    if ($nfb ne 'NONE')
    {
        $template .= &format_execution_view('BL_UA_SHARED_SYS_RAM',
                                            $bl_ua_shared_sys_ram_base,
                                            '0x2000',
                                            \@bl_ua_shared_sys_ram_libs);
        $template .= &format_execution_view('UA_MAUI_SHARED_SYS_RAM',
                                            $ua_maui_shared_sys_ram_base,
                                            '0x1000',
                                            ["fue_partial_fota.obj (FUE_NFB_SHARED_ZI)"]);
    }
    if (&sysUtil::is_sv5($bb) == 1)
    {
        $template .= &format_execution_view('UA_GFH_SIGNATURE_SECTION',
                                            '+0x0',
                                            undef,
                                            ["*                  (FUE_SIGNATURE_SECTION)"]);
    }
    chomp $template;
    return $template;
}

#****************************************************************************
# subroutine:  Layout :: __HIDDEN_SECURE_MAC :: Load View
# input:       BB chip, ram size [value]
#****************************************************************************
sub layout_hidden_secure_mac
{
    my ($bb, $base_str) = @_;
    
    return if (&sysUtil::is_sv5($bb) == 1 or $base_str eq "");
    
    my $layout = <<"__LAYOUT";
;=========================================================================
; This load region must be behind all the protected load region
;=========================================================================
; do NOT modify load region naming and pragma naming!
;=========================================================================

__HIDDEN_SECURE_MAC $base_str
{
    __HIDDEN_SECURE_MAC_CONTENT +0x0 
    {
         *.obj (SECURE_MAC_CONTENT)
    }
    __HIDDEN_SECURE_MAC +0x0 
    {
         *.obj (SECURE_MAC_SIZE)
    }
}
__LAYOUT

    return $layout;
}

#****************************************************************************
# subroutine:  Layout :: UA_INIT
# return:      the body strings
#****************************************************************************
sub UA_INIT_EV
{
	   my $template = <<"__TEMPLATE";
         fue_bootarm.obj (C\$\$code, +First)
         fue_bootarm.obj (+RO)
         *.obj (FOTA_SECINFO)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Layout :: UA_ROM
# return:      the body strings
#****************************************************************************
sub UA_ROM_EV
{
	   my $template = <<"__TEMPLATE";
         *.obj (UA_HEAD, +First)
         * (+RO)
         libmprove610_MTKarm7_tcc.a (+RO)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Layout :: UA_NONCACHED
# return:      the body strings
#****************************************************************************
sub UA_NONCACHED_EV
{
    my $template = <<"__TEMPLATE";
         *.obj (PAGETABLE)
         *.obj (NONCACHEDZI)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Layout :: UA_RW
# return:      the body strings
#****************************************************************************
sub UA_RW_EV
{
    my $template = <<"__TEMPLATE";
         * (+RW, +ZI)
         libmprove610_MTKarm7_tcc.a (+RW, +ZI)
         *.obj (FUE_EXT_SRAM)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Layout :: UA_INTSRAM_CODE
# return:      the body strings
#****************************************************************************
sub UA_INTSRAM_CODE_EV
{
    my $template = <<"__TEMPLATE";
         flash_mtd.obj (+RO)
         flash_mtd.amd.obj (+RO)
         flash_mtd.intel.obj (+RO)
         *.obj (INTERNCODE)  ;for codes that are used to load Primary ROM image
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Layout :: UA_INTSRAM_DATA
# return:      the body strings
#****************************************************************************
sub UA_INTSRAM_DATA_EV
{
	   my $template = <<"__TEMPLATE";
         fue_bootarm.obj (STACK_POOL_INTSRAM)
         *.obj (INTERNZI)
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  NFB Layout :: BL_UA_SHARED_SYS_RAM
# return:      the body strings
#****************************************************************************
sub BL_UA_SHARED_SYS_RAM_EV
{
	   my $template = <<"__TEMPLATE";
         *.obj (BL_FUE_SHARED_ZI, +First)
__TEMPLATE

    return $template;
}
#****************************************************************************
# subroutine: Get TCM information
# input:      BB chip
# return:     ITCM: base address, size DTCM: base address size
#****************************************************************************
sub Get_TCM_info
{
	  my ($bb) = @_;
    my ($strCODEBase, $strCODESize, $strDATABase, $strDATASize);
    my %BB_INTSRAM_tbl =
       (        # $bb => [INTSRAM_CODE_Base, INTSRAM_CODE_Size, INTSRAM_DATA_Base, INTSRAM_DATA_Size] 
                'MT6235'  => ["0x50000000", "0x0000C000", "0x50100000", "0x00014000"],
                'MT6235B' => ["0x50000000", "0x0000C000", "0x50100000", "0x00014000"], #MT6235
                'MT6236'  => ["0x50000000", "0x00010000", "0x50100000", "0x0002B000"],
                'MT6236B' => ["0x50000000", "0x00010000", "0x50100000", "0x0002B000"], #MT6236        
                'MT6268'  => ["0x50000000", "0x00026000", "0x50100000", "0x0001B000"],
                'MT6255'  => ["0x50000000", "0x00010000", "0x50100000", "0x0002B000"],                
       );
    if(exists $BB_INTSRAM_tbl{$bb})
    {
        $strCODEBase = $BB_INTSRAM_tbl{$bb}[0];
        $strCODESize = $BB_INTSRAM_tbl{$bb}[1];
        $strDATABase = $BB_INTSRAM_tbl{$bb}[2];
        $strDATASize = $BB_INTSRAM_tbl{$bb}[3];
    }   
    else
    {
        ($strCODEBase, $strCODESize, $strDATABase, $strDATASize) = &sysUtil::GetIntsramInfo($bb);	
    }
    $strCODEBase = "(kal_uint32)&Image\$\$UA_INTSRAM_CODE\$\$Base" if (&sysUtil::is_CR4($bb));
    $strCODESize = "(kal_uint32)&Image\$\$UA_INTSRAM_CODE\$\$Length" if (&sysUtil::is_CR4($bb));    
    $strDATABase = "(kal_uint32)&Image\$\$UA_INTSRAM_DATA\$\$Base" if (&sysUtil::is_CR4($bb));
    $strDATASize = "(kal_uint32)&Image\$\$UA_INTSRAM_DATA\$\$Length" if (&sysUtil::is_CR4($bb));
                          
    return ($strCODEBase, $strCODESize, $strDATABase, $strDATASize);
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
