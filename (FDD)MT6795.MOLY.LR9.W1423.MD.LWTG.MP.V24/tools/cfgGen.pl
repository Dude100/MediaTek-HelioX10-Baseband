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
#*   cfgGen.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script generates the CFG file for flash tool for SV5
#*
#* Author:
#* -------
#*   Claudia Lo  (mtk01876)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
#****************************************************************************
# Constants
#****************************************************************************
my $CFGGEN_VERNO     = " m0.14";
                      #  m0.14, add infomake.log
                      #  m0.13, Make bin_list's content be an actual file
                      #  m0.12, Add cmdScript.bin for MT6290
                      #  m0.11, Support to add dsp bin if finding it in both flashtool.txt and bin folder
                      #  m0.10, Remove FOTA input
                      #  m0.09, Support Multibin by flashtool.txt from ldsGen
                      #  m0.08, Support MDSYS binding chip name
                      #  v0.28, Generate FS region by default
                      #  m0.07, Support Guardian on linux
                      #  m0.06, Fix parameters reversed in gen_external_memory_setting()
                      #  m0.05, Support path and filename case sensitive on Linux (bypass sign path)
                      #  m0.04, Support GCC temporarily
                      #  m0.03, Add temp folder for the one
                      #  m0.02 , Skip GCC temporarily
                      #  m0.01 , Support MT6280
                      #  v0.27 , Support VIVA in im_maker.ini
                      #  v0.26 , Add Makefile optiion hash to gen_flash_info()
                      #  v0.25 , Support VIVA - use scatter file of flashtool version to be input
                      #  v0.24 , Support 6250 
                      #  v0.23 , Compare bin string in the same letter
                      #  v0.22 , Add Makefile optiion hash to gen_external_memory_setting()
                      #  v0.21 , Support MT6922
                      #  v0.20 , Fix parsing MakeFile
                      #  v0.19 , Remove $$ to support Perl v5.12
                      #  v0.18 , CFG Gen re-structure to split into cfgGen.pl, cfgGen_EMI.pl, and cfgGen_flash.pl
                      #          Parse pre-compiled custom_EMI.c to support compile options
                      #          Support MT6256
                      #          Support sign feature
                      #          Support case-insensitive .bin/.IM extensions
                      #  v0.17 , To support MT6255
                      #  v0.16 , Rename custom_flash.c into custom_flash.h due to re-structure
                      #  v0.15 , Support custom_FeatureConfig.h
                      #  v0.14 , Generate Load_Address for BL and EXT_BL for IM_Maker.ini
                      #  v0.13 , Add FS regions to cfg file for WISE MMI projects
                      #  v0.12 , Generate EMI settings from CFG file under BB folder for those chips which do not support Auto-Gen
                      #  v0.11 , Modify CardDL ini to generate BOOT_CERT region when BOOT_CERT is enabled, even if BOOT_CERT binary does not exist
                      #  v0.10 , Modify CardDL ini to ensure Bootloader section always exists before Ext-Bootloader section
                      #  v0.09 , Modify CardDL ini to add DSP regions and Serial Flash type, and to remove SECURE_RO_ME and SECURE_RO_S from ini files
                      #  v0.08 , Remove SECURE_RO_S from cfg
                      #  v0.07 , To support SV5 ROOT_CERT
                      #  v0.06 , To support SV5 CFG file generation with EMI configurations
                      #  v0.04 , To support Card DL ini gen
                      #  v0.05 , Fix the issue that when Secure is turned on, binaries should be generated in the bin folder
                      #  v0.03 , To support eMMC Booting
                      #  v0.02 , Remove MT6255
                      #  v0.01 , Remove SV5_DEV option and enable SV5 on all MT6276/MT6251/MT6255/MT6256 platforms
                      #  v0.00 , initial version 

#****************************************************************************
# Input Parameters and Global Variables
#****************************************************************************
my $ACTION        = $ARGV[0];  # 1: cfg file for SV5; 2: ini file for Card DL
my $BUILD_PATH    = $ARGV[1];
my $MAUI_BIN      = $ARGV[2];
my $BL_BIN        = $ARGV[3];
my $MAKEFILE      = $ARGV[4];
my $BB_PATH       = $ARGV[5];
my $SCATTER       = $ARGV[6];
my $CC_CMD        = $ARGV[7];
my $VIA_CMD       = $ARGV[8];
my $OPTION_TMP    = $ARGV[9];
my $NET_PATH      = $ARGV[10];
my $TMP_FOLDER    = $ARGV[11];
my $INFOMAKE_PATH = $ARGV[12];
my $ACT_SIGN      = $ARGV[13];
my $CUSTOM_MEM_DEV_H = $BB_PATH . "/custom_MemoryDevice.h";
my $CUSTOM_FEATURE_CONFIG_H = $BB_PATH . "/custom_FeatureConfig.h";
my $SCATTER_FLASH = $SCATTER;
$SCATTER_FLASH =~ s/\.txt/_flashtool\.txt/;
$SCATTER = $SCATTER_FLASH if(-e $SCATTER_FLASH);

my $DebugPrint = 1;

print "BUILD_PATH: $BUILD_PATH, MAUI_BIN: $MAUI_BIN, BL_BIN: $BL_BIN, MAKEFILE: $MAKEFILE, BB_PATH: $BB_PATH, SCATTER: $SCATTER, CC_CMD=$CC_CMD, VIA_CMD=$VIA_CMD, OPTION_TMP=$OPTION_TMP, Temp folder=$TMP_FOLDER\n" if ($DebugPrint == 1);

# --- --- ---
my %BBtbl_SV5 =
   (
         'MT6280'  => 1,
         'MT6290'  => 1,
   );

#****************************************************************************
# 1 >>> parse Project Make File
#****************************************************************************
my %MAKEFILE_OPTIONS;
my $keyname;

&error_handler("$MAKEFILE: NOT exist!", __FILE__, __LINE__) if (!-e $MAKEFILE);

if ($MAKEFILE =~ /make\/(\w+)_(\w+).mak/i) {
  $MAKEFILE_OPTIONS{'MODE'} = uc($2);
}

open (FILE_HANDLE, "<$MAKEFILE") or &error_handler("$MAKEFILE: file error!", __FILE__, __LINE__);
while (<FILE_HANDLE>) {
  if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/))  
  {
    $MAKEFILE_OPTIONS{lc($1)} = uc($2);
    $MAKEFILE_OPTIONS{uc($1)} = uc($2);
  }
}
close (FILE_HANDLE);
my $PLATFORM = $MAKEFILE_OPTIONS{'platform'};
$PLATFORM .= "_".$MAKEFILE_OPTIONS{'MDSYS'} if(exists $MAKEFILE_OPTIONS{MDSYS} and $MAKEFILE_OPTIONS{MDSYS} !~/none/i);
my $COMPILER = $MAKEFILE_OPTIONS{'compiler'};

#****************************************************************************
# 2 >>> parse Scatter File
#****************************************************************************

my (%LoadView, %ExecView);
&ParseScatterFile($SCATTER, \%LoadView, \%ExecView);

#****************************************************************************
# 3 >>> get custom_FeatureConfig.h configurations
#****************************************************************************
my %FEATURE_CONFIG_H_Value;

open (FEATURE_CONFIG_H_HANDLE, "<$CUSTOM_FEATURE_CONFIG_H") or &error_handler("$CUSTOM_FEATURE_CONFIG_H: file error!", __FILE__, __LINE__);
while (<FEATURE_CONFIG_H_HANDLE>) {
    if (/^#define\s+(\w+)\s+\((\w*)\)/ || /^#define\s+(\w+)\s+(\w*)/)
    {
        my $option = $1;
        my $value  = $2;
        
        &error_handler("$CUSTOM_FEATURE_CONFIG_H: $option redefined in custom_FeatureConfig.h!", __FILE__, __LINE__) if defined($FEATURE_CONFIG_H_Value{$option});
        if ((!defined $value) or ($value eq ''))
        {
            $FEATURE_CONFIG_H_Value{$option} = 'TRUE';
        }
        else
        {
            $FEATURE_CONFIG_H_Value{$option} = $value;
        }
    }
}
close (FEATURE_CONFIG_H_HANDLE);

#****************************************************************************
# 4 >>> get all binary list
#****************************************************************************
my (%bin_list, $bin_file);

### For projects that contains more than 1 binary, the output binaries are under .bin folder
my $tmp_bin_folder = $BUILD_PATH . "/" . $MAUI_BIN;
if (opendir(TMP_DIR, $tmp_bin_folder))
{
    $BUILD_PATH = $BUILD_PATH . "/" . $MAUI_BIN;
}
closedir(TMP_DIR);
print "BIN folder: $BUILD_PATH\n" if ($DebugPrint == 1);

opendir(BIN_DIR, $BUILD_PATH) or die "cannot open build folder $BUILD_PATH!";
while (defined($bin_file = readdir(BIN_DIR)))
{
    next if(!-f "$BUILD_PATH\/$bin_file");
    ### binary files are those without extentions (e.g. .txt, .cfg), or with only .bin extention
    if ($bin_file =~ /\./)
    {
        if ($bin_file =~ /\.bin$/i)
        {
            $bin_list{$bin_file} = 'NONE';
        }
        elsif ($bin_file =~ /\.IM$/i)
        {
            $bin_list{$bin_file} = 'FS';
        }
    }
    else
    {
        $bin_list{$bin_file} = 'NONE';
    }
}
closedir(BIN_DIR);

### handle exception: BOOT_CERT might not contain binary
my $boot_cert_bin_exist = 'FALSE';
foreach (keys %bin_list)
{
    if (/BOOT_CERT/)
    {
        $boot_cert_bin_exist = 'TRUE';
        last;
    }
}
if ($boot_cert_bin_exist eq 'FALSE')
{
    $bin_list{'BOOT_CERT'} = 'NONE';
}

### Sort bin_list according to scatter file sequence
my @sorted_bin_list;

# Handle BOOTLOADER first
foreach (keys %bin_list)  # handle exception: for NFB projects, scatter file may not contain BOOTLOADER and EXT_BOOTLOADER
{
    my $cur_bin = $_;
    if (uc($cur_bin) eq uc($BL_BIN))
    {
        my $bl_in_scat = 'FALSE';
        foreach (keys %LoadView)
        {
            if ($_ eq 'BOOTLOADER')
            {
                $bl_in_scat = 'TRUE';
                last;
            }
        }
        if ($bl_in_scat eq 'FALSE')
        {
            push @sorted_bin_list, $cur_bin;

            ### ROOT_CERT always lies behind BL; does not have binary; depending on custom_MemoryDevice.h option
            if ((&config_query_sv5($PLATFORM) == 1) and (defined $MAKEFILE_OPTIONS{'secure_support'} and $MAKEFILE_OPTIONS{'secure_support'} eq 'TRUE') and (defined $FEATURE_CONFIG_H_Value{ROOT_KEY_MANAGEMENT_ENABLE} and $FEATURE_CONFIG_H_Value{ROOT_KEY_MANAGEMENT_ENABLE} eq 'TRUE'))
            {
                push @sorted_bin_list, "ROOT_CERT";
            }
        }
    }
}

# Handle EXT_BOOTLOADER secondly
foreach (keys %bin_list)  # handle exception: for NFB projects, scatter file may not contain BOOTLOADER and EXT_BOOTLOADER
{
    my $cur_bin = $_;
    if (uc($cur_bin) eq 'EXT_BOOTLOADER')
    {
        my $extbl_in_scat = 'FALSE';
        foreach (keys %LoadView)
        {
            if ($_ eq 'EXT_BOOTLOADER')
            {
                $extbl_in_scat = 'TRUE';
                last;
            }
        }
        if ($extbl_in_scat eq 'FALSE')
        {
            push @sorted_bin_list, $cur_bin;
        }
    }
}

foreach (sort {$LoadView{$a}->{'seq'} <=> $LoadView{$b}->{'seq'}} keys %LoadView)
{
    my $scat_key = $_;
    
    ### Some binaries have different names as the one in scatter file
    if ($scat_key eq 'ROM')
    {
        if ($BUILD_PATH =~ /$MAUI_BIN/)  # multiple binary files under MAUI_BIN folder
        {
        }
        else
        {
            $scat_key = $MAUI_BIN;
        }
    }
    elsif ($scat_key eq 'BOOTLOADER')
    {
        $scat_key = $BL_BIN;
    }
    elsif($scat_key =~ /DSP/)
    {
        map {$scat_key =$_ if($_ =~ /dsp/i)} keys %bin_list;
    }

    foreach my $temp (keys %bin_list)
    {
        if (uc($scat_key) eq uc($temp))
        {
            push @sorted_bin_list, $temp;
            
            if ($scat_key eq $BL_BIN)
            {
                ### ROOT_CERT always lies behind BL; does not have binary; depending on custom_MemoryDevice.h option
                if ((&config_query_sv5($PLATFORM) == 1) and (defined $MAKEFILE_OPTIONS{'secure_support'} and $MAKEFILE_OPTIONS{'secure_support'} eq 'TRUE') and (defined $FEATURE_CONFIG_H_Value{ROOT_KEY_MANAGEMENT_ENABLE} and $FEATURE_CONFIG_H_Value{ROOT_KEY_MANAGEMENT_ENABLE} eq 'TRUE'))
                {
                    push @sorted_bin_list, "ROOT_CERT";
                }
            }
            last;
        }
    }
}

if ($DebugPrint == 1)
{
    foreach (@sorted_bin_list)
    {
        print "bin: $_\n";
    }
}

#****************************************************************************
# 5 >>> generate the output cfg file for SV5
#****************************************************************************
my $BOARD_VER = $MAKEFILE_OPTIONS{'board_ver'};
my $CFG_FILE = $BUILD_PATH . "/" . $BOARD_VER . "\.cfg";
if ($ACTION == 1)
{
    ### Only generate CFG file for SV5
    if ((defined &config_query_sv5($PLATFORM)) and (&config_query_sv5($PLATFORM) == 1))
    {
        require "tools/cfgGen_EMI.pl";
        
        open (CFG_FILE, ">$CFG_FILE") or &error_handler("$CFG_FILE: file error!", __FILE__, __LINE__);
        
        print CFG_FILE &gen_general_setting();
        print CFG_FILE &gen_boot_region_setting($PLATFORM);
        print CFG_FILE &gen_control_block_region_setting();
        print CFG_FILE &gen_main_region_setting();
        print CFG_FILE &gen_fs_region_setting();
        print CFG_FILE &gen_external_memory_setting($BB_PATH, $BOARD_VER, $PLATFORM, $CC_CMD, $VIA_CMD, $OPTION_TMP, $TMP_FOLDER, \%MAKEFILE_OPTIONS);
        print "$CFG_FILE is generated\n";
        
        ### Sign
        if ($ACT_SIGN eq "-sign")
        {
            my $CFG_FILE_NET_PATH = $CFG_FILE;
            $CFG_FILE_NET_PATH =~ s/^\.\///;
            print "CFG_FILE_NET_PATH = $NET_PATH/$CFG_FILE_NET_PATH\n";
            if($^O eq "MSWin32")
            {
                system("\\\\mbjsap101\\Guardian_Programs\\Guardian\\bin\\Debug\\Guardian.exe $NET_PATH\\$CFG_FILE_NET_PATH");
            }
            else
            {
                system("/proj/wcp1sm/Guardian $NET_PATH/$CFG_FILE_NET_PATH");
            }
        }
    }
}

#****************************************************************************
# 6 >>> generate the output ini file for Card DL
#****************************************************************************
my $INI_FILE = $BB_PATH . "/IM_Maker.ini";

if ($ACTION == 2)
{
    &error_handler("Not support generating IM_Maker.ini under GCC!", __FILE__, __LINE__) if($COMPILER eq "GCC");
    ### Only generate ini file for Card DL
    if ((defined $MAKEFILE_OPTIONS{'card_download'}) and ($MAKEFILE_OPTIONS{'card_download'} ne 'NONE'))
    {
        require "tools/cfgGen_flash.pl";
        
        open (INI_FILE, ">$INI_FILE") or &error_handler("$INI_FILE: file error!", __FILE__, __LINE__);
        
        print INI_FILE &gen_flash_info($BB_PATH, $BOARD_VER, $PLATFORM, \%MAKEFILE_OPTIONS);
        print INI_FILE &gen_general_setting_for_ini();
        print INI_FILE &gen_bin_info();
        print "$INI_FILE is generated\n";
    }
}

exit;


#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: SV5 Family
# input:       BB chip
# Output:      whether this chip enables SV5
#****************************************************************************
sub config_query_sv5
{
   my ($bb) = @_;
   return $BBtbl_SV5{$bb};
}

#****************************************************************************
# subroutine:  gen_general_setting
# return:      General Setting
#****************************************************************************
sub gen_general_setting
{
    my $template = <<"__TEMPLATE";
############################################################################################################
#
#  General Setting 
#    
############################################################################################################

general:
    config_version : alpha # config file version ("alpha", "beta" is used before SQC done.)
                           # After SQC done, the version should be "1" for the first release version.
    platform: $PLATFORM       # It is used for tool to identify the right setting for specific target

__TEMPLATE
}

#****************************************************************************
# subroutine:  gen_boot_region_setting
# return:      Boot Region Setting
#****************************************************************************
sub gen_boot_region_setting
{
    my ($bb) = @_;
    my $boot_region_list;
    $boot_region_list .= "    - file: cmdScript.bin\n" if($bb eq "MT6290");
    ### Boot Region includes all binaries with naming with BOOTLOADER or BL
    foreach (@sorted_bin_list)
    {
        if (/BOOTLOADER/ or /DSP_BL/)
        {
            $bin_list{$_} = 'BOOT';
            $boot_region_list .= "    - file: " . $_ . "\n";
        }
        elsif ($_ eq 'ROOT_CERT')
        {
            $bin_list{$_} = 'BOOT';
            $boot_region_list .= "    - file: ROOT_CERT\n";
        }
    }
    chomp $boot_region_list;
    
    my $template = <<"__TEMPLATE";
############################################################################################################
#
#  Boot Region Setting
#
############################################################################################################

boot_region:
  alignment: block         # block[default], page(NAND:2K/512B, NOR: 1KB, eMMC: 512B, SF: 256B)
  rom:
$boot_region_list

__TEMPLATE
}

#****************************************************************************
# subroutine:  gen_control_block_region_setting
# return:      Control Block Region Setting
#****************************************************************************
sub gen_control_block_region_setting
{
    my $cbr_region_list;

    ### Control Block Region includes all binaries with naming with SECURE_RO
    foreach (@sorted_bin_list)
    {
        if (/SECURE_RO/)
        {
            next if ($_ eq 'SECURE_RO_S');
            $bin_list{$_} = 'CBR';
            $cbr_region_list .= "    - file: " . $_ . "\n";
        }
    }
    chomp $cbr_region_list;

    my $template = <<"__TEMPLATE";
############################################################################################################
#
#  Control Block Region Setting
#
############################################################################################################          

control_block_region:
  rom:
$cbr_region_list

__TEMPLATE
}

#****************************************************************************
# subroutine:  gen_main_region_setting
# return:      Main Region Setting
#****************************************************************************
sub gen_main_region_setting
{
    my $main_region_list;

    ### Main Region includes all other binaries
    foreach (@sorted_bin_list)
    {
        next if ($_ eq 'SECURE_RO_S');
        if ($bin_list{$_} eq 'NONE')
        {
            $main_region_list .= "    - file: " . $_ . "\n";
        }
    }
    chomp $main_region_list;

    my $template = <<"__TEMPLATE";
############################################################################################################
#
#  Main Region Setting
#
############################################################################################################

main_region:
  alignment: block         # block[default], page(NAND:2K/512B, NOR: 1KB, eMMC: 512B, SF: 256B)
  rom:
$main_region_list

__TEMPLATE
}

#****************************************************************************
# subroutine:  gen_fs_region_setting
# return:      File System Region Setting
#****************************************************************************
sub gen_fs_region_setting
{
    my $fs_region_list;    
    ### File System Region includes all IM files
    foreach (keys %bin_list)
    {
    	if ($bin_list{$_} eq 'FS')
        {
            $fs_region_list .= "    - file: " . $_ . "\n";
        }
    }
    chomp $fs_region_list;

    my $template = <<"__TEMPLATE";
############################################################################################################
#
#  File System Region Setting
#
############################################################################################################

file_system_region:
  rom:
$fs_region_list

__TEMPLATE
}

#****************************************************************************
# subroutine:  gen_general_setting_for_ini
# return:      General Setting
#****************************************************************************
sub gen_general_setting_for_ini
{
    my $base_dir = $BUILD_PATH;
    $base_dir =~ s/^\.\///;
    
    my $template = <<"__TEMPLATE";
[General Setting]
Base_Directory=$base_dir

__TEMPLATE
}

#****************************************************************************
# subroutine:  gen_bin_info
# return:      Binary information
#****************************************************************************
sub gen_bin_info
{
    my $bin_str;
    my $res_bin = 1;  # Resource Bin such as LANG_PACK_ROM, CUSTPACK_ROM, JUMP_TABLE
    my $cust_bin = 1;  # all other binaries
    
    ### Parse scatter file to find binaries sequentially
    foreach (@sorted_bin_list)
    {
    	next if (/SECURE_RO/);  # SECURE_RO regions cannot be updated, so skip them
        if (uc($_) eq uc($BL_BIN))  # [Bootloader] region represents BL bin
        {
            my $load_address;
            if (defined $LoadView{'BOOTLOADER'}->{'begin'})
            {
                $load_address = "Load_Address=$LoadView{'BOOTLOADER'}->{'begin'}";
            }
            $bin_str .= <<"__TEMPLATE";
[Bootloader]
File=$BL_BIN
$load_address

__TEMPLATE
        }
        elsif (/EXT_BOOTLOADER/)  # [Ext-Bootloader] region represents the region with naming as EXT_BOOTLOADER
        {
            my $load_address;
            if (defined $LoadView{'EXT_BOOTLOADER'}->{'begin'})
            {
                $load_address = "Load_Address=$LoadView{'EXT_BOOTLOADER'}->{'begin'}";
            }
            $bin_str .= <<"__TEMPLATE";
[Ext-Bootloader]
File=$_
$load_address

__TEMPLATE
        }
        elsif (($_ eq $MAUI_BIN) or ($_ eq 'ROM'))  # [Primary MAUI] region represents the ROM region
        {
            my $load_addr = ($LoadView{'ROM'}->{'begin'} =~ /\+/) ? "0x0" : $LoadView{'ROM'}->{'begin'};
            $bin_str .= <<"__TEMPLATE";
[Primary MAUI]
File=$_
Load_Address=$load_addr

__TEMPLATE
        }
        elsif ($_ eq 'SECONDARY_ROM')  # [Secondary MAUI] region represents the SECONDARY_ROM region
        {
            $bin_str .= <<"__TEMPLATE";
[Secondary MAUI]
File=$_
Load_Address=$LoadView{$_}->{'begin'}

__TEMPLATE
        }
        elsif ($_ eq 'THIRD_ROM')  # [Third MAUI] region represents the THIRD_ROM region
        {
            $bin_str .= <<"__TEMPLATE";
[Third MAUI]
File=$_
Load_Address=$LoadView{$_}->{'begin'}

__TEMPLATE
        }
        elsif ($_ eq 'VIVA')  # [VIVA] region represents the VIVA region
        {
            $bin_str .= <<"__TEMPLATE";
[VIVA]
File=$_
Load_Address=$LoadView{$_}->{'begin'}

__TEMPLATE
        }
        elsif ($_ eq 'BOOT_CERT')  # [Boot Cert] region represents the BOOT_CERT region
        {
            $bin_str .= <<"__TEMPLATE";
[Boot Cert]
File=$_
Load_Address=$LoadView{$_}->{'begin'}

__TEMPLATE
        }
        elsif (/DEMAND_PAGING/)  # [Demand Paging] region represents the DEMAND_PAGING_ROMx region
        {
            $bin_str .= <<"__TEMPLATE";
[Demand Paging]
File=$_
Load_Address=$LoadView{$_}->{'begin'}

__TEMPLATE
        }
        elsif (($_ eq 'LANG_PACK_ROM') or ($_ eq 'CUSTPACK_ROM') or ($_ eq 'JUMP_TABLE'))  # [Resource Binx] region represents Resource Bin regions (MBA)
        {
            $bin_str .= <<"__TEMPLATE";
[Resource Bin$res_bin]
File=$_
Load_Address=$LoadView{$_}->{'begin'}

__TEMPLATE
            $res_bin++;
        }
        elsif ($_ eq 'DSP_BL')  # [DSP-Bootloader] region represents DSP Bootloader region
        {
            $bin_str .= <<"__TEMPLATE";
[DSP-Bootloader]
File=$_
Load_Address=$LoadView{$_}->{'begin'}

__TEMPLATE
        }
        elsif ($_ eq 'DSP_ROM')  # [DSP MAUI] region represents DSP main binary
        {
            $bin_str .= <<"__TEMPLATE";
[DSP MAUI]
File=$_
Load_Address=$LoadView{$_}->{'begin'}

__TEMPLATE
        }
        else  # [Customer Binx] region represents all other regions
        {
            $bin_str .= <<"__TEMPLATE";
[Customer Bin$cust_bin]
File=$_
Load_Address=$LoadView{$_}->{'begin'}

__TEMPLATE
            $cust_bin++;
        }
    }

    my $template = <<"__TEMPLATE";
$bin_str
__TEMPLATE
}

#****************************************************************************
# subroutine:  parse_region_string
# input:       reference to %LoadView or %ExecView ; Region Name start address string
# return:      %LoadView ; key = RegionName , value = hash ref , begin , attr , length
#****************************************************************************
my $sequence = 0;
sub parse_region_string
{
    my ($hash_ref, $string) = @_;
    my %tmp;

    if    ($string =~ m/(\S+)\s+(\S+)\s+OVERLAY\s+(\S+)/)
    {
        #print 'PATTERN1', "\t", $1, "\t", $2, "\t", 'OVERLAY', "\t", $3 , "\n";
        $tmp{'seq'}     = ++$sequence;
        $tmp{'attr'}    = "OVERLAY";
        $tmp{'begin'}   = $2;
        $tmp{'length'}  = $3;
        $hash_ref->{$1} = \%tmp;
    }
    elsif ($string =~ m/(\S+)\s+(\S+)\s+FIXED\s+(\S+)/)
    {
        #print 'PATTERN1', "\t", $1, "\t", $2, "\t", 'FIXED', "\t", $3, "\n";
        $tmp{'seq'}     = ++$sequence;
        $tmp{'attr'}    = "FIXED";
        $tmp{'begin'}   = $2;
        $tmp{'length'}  = $3;
        $hash_ref->{$1} = \%tmp;
    }
    elsif ($string =~ m/(\S+)\s+(\S+)\s+(\S+)/)
    {
        #print 'PATTERN3', "\t", $1, "\t", $2, "\t", $3, "\n";
        $tmp{'seq'}     = ++$sequence;
        $tmp{'begin'}   = $2;
        $tmp{'length'}  = $3;
        $hash_ref->{$1} = \%tmp;
    }
    elsif ($string =~ m/(\S+)\s+(\S+)/)
    {
        #print 'PATTERN4', "\t", $1, "\t", $2, "\n";
        $tmp{'seq'}     = ++$sequence;
        $tmp{'begin'}   = $2;
        $hash_ref->{$1} = \%tmp;
    }
    elsif ($string =~ m/(\S+)/)
    {
        print 'PATTERN5-Fake scatter' , "\t", $1 , "\n";
        $tmp{'seq'}     = ++$sequence;
        $tmp{'begin'}   = undef;
        $hash_ref->{$1} = \%tmp; 
    }
    else
    {
        warn "UNKNOWN PATTERN : $string";
    }
}

#****************************************************************************
# subroutine:  parse_scatter_file_structure
# return:      %LoadView , %ExecView
#****************************************************************************
sub parse_scatter_file_structure
{
    my ($Scat_Content, $LoadView_href, $ExeView_href) = @_;
    my $last_line_no;
    my $text_line;
    my $view=0;  #counter , 1 = load view , 2 = exec view
    foreach my $file_line_no (sort {$a <=> $b} keys %$Scat_Content)
    {
        $text_line = $Scat_Content->{$file_line_no};
        if    ($text_line =~ m/{/)
        {
            if ($view > 1)
            {
                &error_handler("$SCATTER: Unrecognizable view at $file_line_no!", __FILE__, __LINE__);
            }
            $view++;
            if (not defined $last_line_no)
            {
                &error_handler("$SCATTER: No region name detected before $file_line_no!", __FILE__, __LINE__);
            }
            &parse_region_string( ($view == 1) ? $LoadView_href : $ExeView_href , $Scat_Content->{$last_line_no} );
        }
        elsif ($text_line =~ m/}/)
        { 
            $view--;
            if ($view < 0)
            {
                &error_handler("$SCATTER: Unrecognizable view at $file_line_no!", __FILE__, __LINE__);
            }
        }
        $last_line_no = $file_line_no;
    }
}

sub ParseScatterFile
{
    my ($SCATTER, $LoadView_href, $ExeView_href) = @_;
    my %Scat_Content;
    open (SCAT_HANDLE, "<$SCATTER") or &error_handler("$SCATTER: file error!", __FILE__, __LINE__);
    while (<SCAT_HANDLE>) {
        if (/ALIGN/) { $Scat_Content{$.} = $_; }
        if (/\(.+\)/) {next;}
        if (/;/) {s/;.*//;}
        if (/{/ or /}/ or /\S+/) { $Scat_Content{$.} = $_; }
    }
    close (SCAT_HANDLE);
    
    &parse_scatter_file_structure(\%Scat_Content, $LoadView_href, $ExeView_href);
    
    if ($DebugPrint == 1)
    {
        foreach (sort {$LoadView{$a}->{'seq'} <=> $LoadView{$b}->{'seq'}} keys %LoadView)
        {
            printf("Load View %d: $_\n", $LoadView{$_}->{'seq'});
        }
    }
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;
    
    my $final_error_msg = "CFGGEN ERROR: $error_msg at $file line $line_no\n";
    print $final_error_msg;
    die $final_error_msg;
}

