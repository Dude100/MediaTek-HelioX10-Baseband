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
#*   zImageConfig.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script parse scatter file and 
#*       1. force generate custom_scatstruct.h if update required
#*       2. force generate custom_scatstruct.c if update required
#*       3. force generate custom_blconfig.c if update required
#*
#* Author:
#* -------
#*   Ken Lin  (mtk02554)
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
BEGIN { push @INC, '.\\tools\\' }  # add additional library path 
use auto_adjust_mem; #pm file name without case sensitivity 
use File::Copy;

#****************************************************************************
# Constants
#****************************************************************************
my $ZIMAGECONFIG_VERNO     = " v0.11";
                       #  v0.11 , show healthy check error on the console
                       #  v0.10 , AAPMC auto check-in support
                       #  v0.09 , deduct the dcm share pool from $max_compressed_size
                       #  v0.08 , detect if ZIMAGE overflows as a healthy check in advance
                       #  v0.07 , take cached dummy end into account in free ram size calculation
                       #  v0.06 , healthy check for RAM leakage
                       #  v0.05 , align interface of DemandPagingConfig.pl
                       #  v0.04 , get zimage config in custom_FeatureConfig.h
                       #  v0.03 , get FS base address in ~flash_cfg_tmp.c
                       #  v0.02 , take DCM into account
                       #  v0.01 , initial draft

#****************************************************************************
# File Names
#****************************************************************************
my $LIS_FILE = $ARGV[0];
my $DUMMY_ZIMAGE = $ARGV[1];
my $CUSTOM_EMI_RELEASE_H = $ARGV[2] . '\\' . "custom_EMI_release.h";
my $CUSTOM_FEATURE_CONFIG_H = $ARGV[2] . '\\' . "custom_FeatureConfig.h";
my $MAKEFILE = $ARGV[3];
my $FLASH_CFG_TMP_C = $ARGV[4];
my $INTERMEDIATE_FILE = $ARGV[5];
my $LOG_PATH = $ARGV[6];

# to align error message file name format
$LIS_FILE =~ s/^.\\|^\\//;
$DUMMY_ZIMAGE =~ s/^.\\|^\\//;
$CUSTOM_EMI_RELEASE_H   =~ s/^.\\|^\\//;
$CUSTOM_FEATURE_CONFIG_H =~ s/^.\\|^\\//;
$MAKEFILE =~ s/^.\\|^\\//;
$FLASH_CFG_TMP_C =~ s/^.\\|^\\//;
$INTERMEDIATE_FILE =~ s/^.\\|^\\//;
$LOG_PATH =~ s/^.\\|^\\//;

my $DebugPrint    = 1; # 1 for debug; 0 for non-debug

#****************************************************************************
# 0 >>>  Print out input parameters for checking
#****************************************************************************
if ($DebugPrint == 1) {
  print "LIS_FILE: $LIS_FILE\n";
  print "DUMMY_ZIMAGE: $DUMMY_ZIMAGE\n";
  print "CUSTOM_EMI_RELEASE_H: $CUSTOM_EMI_RELEASE_H\n";
  print "CUSTOM_FEATURE_CONFIG_H: $CUSTOM_FEATURE_CONFIG_H\n";
  print "MAKEFILE: $MAKEFILE\n";
  print "FLASH_CFG_TMP_C: $FLASH_CFG_TMP_C\n";  
  print "INTERMEDIATE_FILE: $INTERMEDIATE_FILE\n";
  print "LOG_PATH: $LOG_PATH\n";
  print "\n";  
}

#****************************************************************************
# 1 >>>  Parse Makefile
#****************************************************************************
# assumption: same category should be put together
use constant FEATURE_NAME => 0;
use constant CATEGORY => 1;
use constant LOAD_REGION => 2;
use constant SWITCH => 3;
use constant SIZE => 4;

my @feature_option = (
# feature name             category       load region                 switch(OFF)    size
  ['MP4_DECODE',             'video',       'DYNAMIC_COMP_MP4DEC',      0,        0],
  ['H264_DECODE',            'video',       'DYNAMIC_COMP_H264DEC',     0,        0],
  ['MP4_ENCODE',             'video',       'DYNAMIC_COMP_MP4ENC',      0,        0],  
  ['BES_LOUDNESS_SUPPORT',   'audio',       'DYNAMIC_COMP_BESLOUDNESS', 0,        0],
  ['BT_AUDIO_VIA_SCO',       'audio',       'DYNAMIC_COMP_RESAMPLE',    0,        0],
  ['BT_A2DP_PROFILE',        'audio',       'DYNAMIC_COMP_SBC',         0,        0],
);
my $auto_config;

print "Starting stage1 ... \n" if($DebugPrint == 1);

&error_handler("$MAKEFILE: NOT exist!", __FILE__, __LINE__) if (!-e $MAKEFILE);

open (FILE_HANDLE, "<$MAKEFILE") or &error_handler("$MAKEFILE: file error!", __FILE__, __LINE__);
while (<FILE_HANDLE>) {
    if (/^(\S+)\s*=\s*TRUE/) {
        # DCM
        foreach $_ (@feature_option) {
            if ($_->[FEATURE_NAME] eq $1) {
                $_->[SWITCH] = 1; # ON
            }
        }

        # ZIMAGE_AUTO_CONFIG
        if ($1 eq 'ZIMAGE_AUTO_CONFIG') {
            $auto_config = 1;
        }
    }
}

print "\n";

#****************************************************************************
# 2 >>>  Parse LIS File
#****************************************************************************
my $total_rom;
my $basic_rom_size;
my $rw_bound;
my $dsp_tx_reserved;
my $dsp_rx_reserved;
my $orig_zimage_size;
my $static_zimage_size;
my $dcm_rom_size;
my $dcm_ram_size;


print "Starting stage2 ... \n" if($DebugPrint == 1);

&error_handler("$LIS_FILE: NOT exist!", __FILE__, __LINE__) if (!-e $LIS_FILE);

open (FILE_HANDLE, "<$LIS_FILE") or &error_handler("$LIS_FILE: file error!", __FILE__, __LINE__);
while (<FILE_HANDLE>) {
  if (/Total ROM Size \(Code \+ RO Data \+ RW Data\)\s+(\S+)/) {
    $total_rom = $1;
  }
  elsif (/Execution Region ROM1 \(Base: (\S+), Size: (\S+)/) {
    $basic_rom_size = (hex($1) & hex("0x07FFFFFF")) + hex($2);
  }
  elsif (/Execution Region DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI \(Base: (\S+), Size: (\S+)/) {
    $rw_bound = (hex($1) & hex("0x07FFFFFF")) + hex($2);
  }
  elsif (/Execution Region EXTSRAM_DSP_TX \(Base: (\S+), Size: (\S+), Max: (\S+)/) {
    $dsp_tx_reserved = hex($3);
  }
  elsif (/Execution Region EXTSRAM_DSP_RX \(Base: (\S+), Size: (\S+), Max: (\S+)/) {
    $dsp_rx_reserved = hex($3);
  }  
  elsif (/Load Region ZIMAGE \(Base: (\S+), Size: (\S+)/) {
    $orig_zimage_size = hex($2);
  }
  elsif (/Execution Region ZIMAGE \(Base: (\S+), Size: (\S+)/) {
    $static_zimage_size = hex($2);
  }
  
  # DCM RO
  if (/Load Region (\S+) \(Base: (\S+), Size: (\S+)/) {
    foreach $_ (@feature_option) {
      if ($_->[SWITCH] == 1 && $_->[LOAD_REGION] eq $1) {
        $_->[SIZE] = hex($3); # ON
        $dcm_rom_size += hex($3);
      }
    }
  }
}
close (FILE_HANDLE);

# calculate $dcm_ram_size
my $current_category = $feature_option[0][1];
my $category_max_size;
foreach $_ (@feature_option) {
  print "$_->[FEATURE_NAME], $_->[CATEGORY], $_->[LOAD_REGION], $_->[SWITCH], $_->[SIZE]\n" if($DebugPrint == 1);

  # next category
  if ($current_category ne $_->[CATEGORY]) {
    $dcm_ram_size += $category_max_size;
    $category_max_size = $_->[SIZE];
    $current_category = $_->[CATEGORY];
  }
  # same category, then update the max size
  elsif ($category_max_size < $_->[SIZE]) {
    $category_max_size = $_->[SIZE];
  }
}
$dcm_ram_size += $category_max_size; # last category
print "\n" if($DebugPrint == 1);

if ($DebugPrint == 1) {
  print "total_rom: $total_rom\n";
  print "basic_rom_size: $basic_rom_size\n";
  print "rw_bound: $rw_bound\n";
  print "dsp_tx_reserved: $dsp_tx_reserved\n";
  print "dsp_rx_reserved: $dsp_rx_reserved\n";
  print "orig_zimage_size: $orig_zimage_size\n";  
  print "static_zimage_size: $static_zimage_size\n";  
  print "dcm_rom_size: $dcm_rom_size\n";
  print "dcm_ram_size: $dcm_ram_size\n";
  print "\n";
}

#****************************************************************************
# 3 >>>  Parse custom_FeatureConfig.h 
#****************************************************************************
my $orig_decompressed_size;
my $orig_max_compressed_size;

print "Starting stage3 ... \n" if($DebugPrint == 1);

&error_handler("$CUSTOM_FEATURE_CONFIG_H: NOT exist!", __FILE__, __LINE__) if (!-e $CUSTOM_FEATURE_CONFIG_H);

open (FILE_HANDLE, "<$CUSTOM_FEATURE_CONFIG_H") or &error_handler("$CUSTOM_FEATURE_CONFIG_H: file error!", __FILE__, __LINE__);
while (<FILE_HANDLE>) {
  if (/\#define CONFIG_ZIMAGE_DECOMPRESSED_SIZE\s+((\S|\s)+)/) {
    $orig_decompressed_size = hex($1);
  }
  elsif (/\#define CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE\s+((\S|\s)+)/) {
    $orig_max_compressed_size = hex($1);
  }
}
close (FILE_HANDLE);

if ($DebugPrint == 1) {
  print "orig_decompressed_size: $orig_decompressed_size\n";
  print "orig_max_compressed_size: $orig_max_compressed_size\n";
  print "\n";
}

#****************************************************************************
# 4 >>>  Parse custom_EMI_release.h (EMI_EXTSRAM_SIZE)
#****************************************************************************
my $max_ram;
my $ram_bound;

print "Starting stage4 ... \n" if($DebugPrint == 1);

&error_handler("$CUSTOM_EMI_RELEASE_H: NOT exist!", __FILE__, __LINE__) if (!-e $CUSTOM_EMI_RELEASE_H);

open (FILE_HANDLE, "<$CUSTOM_EMI_RELEASE_H") or &error_handler("$CUSTOM_EMI_RELEASE_H: file error!", __FILE__, __LINE__);
while (<FILE_HANDLE>) {
  if (/\#define EMI_EXTSRAM_SIZE ((\S|\s)+)/) {
    $max_ram = eval($1);
    last;
  }
}
close (FILE_HANDLE);

$ram_bound = $max_ram - $dsp_tx_reserved - $dsp_rx_reserved;

if ($DebugPrint == 1) {
  print "max_ram: $max_ram\n";
  print "ram_bound: $ram_bound\n";
  print "\n";
}

#****************************************************************************
# 5 >>>  Parse ~flash_cfg_tmp.c
#****************************************************************************
my $fs_base_addr;

print "Starting stage5 ... \n" if($DebugPrint == 1);

&error_handler("$FLASH_CFG_TMP_C: NOT exist!", __FILE__, __LINE__) if (!-e $FLASH_CFG_TMP_C);

open (FILE_HANDLE, "<$FLASH_CFG_TMP_C") or &error_handler("$FLASH_CFG_TMP_C: file error!", __FILE__, __LINE__);
while (<FILE_HANDLE>) {
  if (/int flash_base_address\s+=\s+((\S|\s)+);/) {
    $fs_base_addr = eval($1);
  }
}
close (FILE_HANDLE);

if ($DebugPrint == 1) {
  print "fs_base_addr: $fs_base_addr\n";  
  print "\n";
}

#****************************************************************************
# 6 >>>  Calculate compression ratio
#****************************************************************************
my $zimage_size;
my $compression_ratio;

print "Starting stage6 ... \n" if($DebugPrint == 1);

$zimage_size = -s $DUMMY_ZIMAGE;
$compression_ratio = $zimage_size / $orig_zimage_size;

if ($DebugPrint == 1) {
  print "zimage_size: $zimage_size\n";
  print "compression_ratio: $compression_ratio\n";  
  print "\n";
}

#****************************************************************************
# 7 >>>  Calculate CONFIG_ZIMAGE_DECOMPRESSED_SIZE 
#                           & CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE
#****************************************************************************
my $decompressed_size;
my $max_compressed_size;
my $free_ram_size;
my $max_decompressed_size;
my $cached_dummy_end_size = 4;

print "Starting stage7 ... \n" if($DebugPrint == 1);

# calculate $free_ram_size & $max_decompressed_size
$free_ram_size = $ram_bound - $rw_bound - $cached_dummy_end_size;
$max_decompressed_size = $total_rom - $basic_rom_size;

# calculate $decompressed_size & $max_compressed_size
$decompressed_size = min($free_ram_size, $max_decompressed_size);
$max_compressed_size = int(($decompressed_size - $dcm_ram_size) * $compression_ratio + 0.99); # ceil

if ($DebugPrint == 1) {
  print "basic_rom_size: $basic_rom_size\n";
  print "free_ram_size: $free_ram_size\n";
  print "max_decompressed_size: $max_decompressed_size\n";
  print "decompressed_size: $decompressed_size\n";
  print "max_compressed_size: $max_compressed_size\n";
  print "\n";
}

#****************************************************************************
# 8 >>>  Healthy check
#****************************************************************************
my $actual_rom_size;
my $total_compressed_size;
my $alignment = 4 * 1024;

print "Starting stage8 ... \n" if($DebugPrint == 1);

# health check (1)
if ($decompressed_size - $dcm_ram_size <= 0) {
    my $exceeded = -($decompressed_size - $dcm_ram_size);
    &write_log($INTERMEDIATE_FILE, "Error: Insufficient RAM space. ($exceeded bytes exceeded)\nRecommend: Please turn off some features. (e.g. DCM_COMPRESSION_SUPPORT)\n");
    exit ERR::CANNOT_ADJUST;    
}

$actual_rom_size = $total_rom - ($decompressed_size - $dcm_ram_size) - $dcm_rom_size;
$total_compressed_size = int(($decompressed_size + $dcm_rom_size) * $compression_ratio + 0.99);  # ceil
if ($DebugPrint == 1) {
  print "actual_rom_size: $actual_rom_size\n";
  print "total_compressed_size: $total_compressed_size\n";  
  print "\n";  
}

# health check (2)
if ($actual_rom_size + $total_compressed_size >= $fs_base_addr) {
    my $exceeded = $actual_rom_size + $total_compressed_size - $fs_base_addr;
    &write_log($INTERMEDIATE_FILE, "Error: Insufficient flash space. ($exceeded bytes exceeded)\nRecommend: Please turn off some features.\n");
    exit ERR::CANNOT_ADJUST;
}

# health check (3)
if ($free_ram_size < 0) {
    my $exceeded = -$free_ram_size;
    &write_log($INTERMEDIATE_FILE, "Error: Insufficient RAM space. ($exceeded bytes exceeded)\nRecommend: Please turn off some features.\n");
    exit ERR::CANNOT_ADJUST;
}

# make alignment (floor)
$decompressed_size = int($decompressed_size / $alignment) * $alignment;
$max_compressed_size = int($max_compressed_size / $alignment) * $alignment;

# health check (4)
if (($decompressed_size - $dcm_ram_size) <= $static_zimage_size) {
    my $exceeded = $static_zimage_size - ($decompressed_size - $dcm_ram_size);
    &write_log($INTERMEDIATE_FILE, "Error: ZIMAGE overflow. ($exceeded bytes exceeded)\nRecommend: Please either\n           (1) remove xxx.lib/xxx.obj from ZIMAGE, or\n           (2) turn off some features\n");
    exit ERR::CANNOT_ADJUST;
}

# health check (5)
if ($decompressed_size == $orig_decompressed_size && $max_compressed_size == $orig_max_compressed_size) {
    &write_log($INTERMEDIATE_FILE, "Error: Invalid configuration.\nRecommend: Please call for help.\n");
    exit ERR::CANNOT_ADJUST;
}

#****************************************************************************
# 9 >>>  Output
#****************************************************************************
my $err;

print "Starting stage9 ... \n" if($DebugPrint == 1);

# convert to hex
$orig_decompressed_size = sprintf("0x%X", $orig_decompressed_size);
$orig_max_compressed_size = sprintf("0x%X", $orig_max_compressed_size);

$decompressed_size = sprintf("0x%X", $decompressed_size);
$max_compressed_size = sprintf("0x%X", $max_compressed_size);

if ($auto_config) {
    if( ERR::AAPMCLOG_SUCCESS == &AAPMCLogParser::Open($LOG_PATH)) {
        my $P4Info_ref = &AUTO_ADJUST::CreateP4InfoTemplate("mtk01892", "", "zImage auto config",
                         "[Before]\n($orig_decompressed_size, $orig_max_compressed_size)\n[After]\n($decompressed_size, $max_compressed_size)\n");
    
    my %ChangeList = (
        'CONFIG_ZIMAGE_DECOMPRESSED_SIZE' => $decompressed_size,
        'CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE' => $max_compressed_size,
    );
        $err = &AAPMCLogParser::AddOneChangeRecord($CUSTOM_FEATURE_CONFIG_H, \%ChangeList, \%$P4Info_ref);
        if($err == ERR::ERR_MODIFYDUPLICATED) {
            print "can't modified more than twice\n";
        }
        elsif ($err == ERR::AAPMCLOG_SUCCESS) {
            print "add successfully!\n";
            &write_log($INTERMEDIATE_FILE, "[Before auto adjustment]\nCONFIG_ZIMAGE_DECOMPRESSED_SIZE=$orig_decompressed_size\nCONFIG_ZIMAGE_MAX_COMPRESSED_SIZE=$orig_max_compressed_size\n[After auto adjustment]\nRECOMMAND: CONFIG_ZIMAGE_DECOMPRESSED_SIZE=$decompressed_size\nRECOMMAND: CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE=$max_compressed_size\n");
        }
        &AAPMCLogParser::Close($LOG_PATH);        
    }
    else {
        print "load AAPMCLog failed";
    }  
}
else {
    print "No modification\n";
    &write_log($INTERMEDIATE_FILE, "[Before auto adjustment]\nCONFIG_ZIMAGE_DECOMPRESSED_SIZE=$orig_decompressed_size\nCONFIG_ZIMAGE_MAX_COMPRESSED_SIZE=$orig_max_compressed_size\n[After auto adjustment]\nRECOMMAND: CONFIG_ZIMAGE_DECOMPRESSED_SIZE=$decompressed_size\nRECOMMAND: CONFIG_ZIMAGE_MAX_COMPRESSED_SIZE=$max_compressed_size\n");
    exit ERR::NO_MODIFY;    
}


#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit $err;


#****************************************************************************
# subroutine:  min
# input:       $m, $n
#****************************************************************************
sub min
{
    my ($m, $n) = @_;
	   
    if ($m < $n) {
        $m
    }
    else {
        $n
    }
}


#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#              $file:          filename
#              $line_no:       line number
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;

    print "ZIMAGE CONFIG ERROR: $error_msg at $file line $line_no\n";	   
    my $final_error_msg = "ZIMAGE CONFIG ERROR: $error_msg at $file line $line_no\n";
    die $final_error_msg;
}


#****************************************************************************
# subroutine:  write_log
# input:     $log_path
#****************************************************************************
sub write_log
{
    my ($log_path, $message) = @_;
    
    print $message;
    
    open (FILE_HANDLE, ">$log_path") or &error_handler("Cannot open log: $log_path\n", __FILE__, __LINE__);
    print FILE_HANDLE $message;
    close FILE_HANDLE;
}
