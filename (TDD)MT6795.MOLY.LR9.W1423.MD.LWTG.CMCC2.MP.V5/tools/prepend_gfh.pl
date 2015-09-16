#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2013
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
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   prepend_gfh.pl
#*
#* Project:
#* --------
#*   MOLY
#*
#* Description:
#* ------------
#*   Add GFH header for the binary without GFH
#*
#* Author:
#* -------
#*   Chin-Chieh Hung (mtk03404)
#*
#****************************************************************************
use strict;


#****************************************************************************
# Included Modules
#****************************************************************************
BEGIN { push @INC, './LTE_CDP_FMC/Tools/' }  # add additional library path
use File::Basename;
use File::Copy;
#use CommonUtility;
#use tools::pack_dep_gen;
#PrintDependModule();

#****************************************************************************
# Constants
#****************************************************************************
my $PREPEND_GFH_VERNO = "m0.05";
# v0.05 by Yu-Hung Huang, add DSP platform id support in m_platform_id instead of hard code to "MT6290"
# v0.04 by Yu-Hung Huang, support don't care flash in m_flash_dev with value FLASH_DEV_NONE (0x00)
# v0.03 by Peiwen Qing, add DSP build time support in m_build_time
# v0.02 by Peiwen Qing, add DSP version support in m_project_id
# v0.01 by mtk03404 Chin-Chieh Hung, initial version

#Usage: prepend_gfh.pl SRC_BINFILE_PATH(filename) DST_BINFILE_PATH(filename) file_info.conf 

#****************************************************************************
# Global Variables
#****************************************************************************
my @GFH_Buffer;
my $gfh_fileinfo_type = 1;
my %GFH_FILE_TYPE;
my %GFH_FLASH_DEV;
my %GFH_SIG_TYPE;

#****************************************************************************
# GFH FileInfo Related Enum Definition
#****************************************************************************
$GFH_FILE_TYPE{ "LTE_DSP_ROM" } = chr(0x09).chr(0x01); #Big Endian

$GFH_FLASH_DEV{ "FLASH_DEV_NONE"     } = chr(0x00);
$GFH_FLASH_DEV{ "F_NOR"              } = chr(0x01);
$GFH_FLASH_DEV{ "F_NAND_SEQUENTIAL"  } = chr(0x02);
$GFH_FLASH_DEV{ "F_NAND_TTBL"        } = chr(0x03);
$GFH_FLASH_DEV{ "F_NAND_FDM50"       } = chr(0x04);
$GFH_FLASH_DEV{ "F_EMMC_BOOT_REGION" } = chr(0x05);
$GFH_FLASH_DEV{ "F_EMMC_DATA_REGION" } = chr(0x06);
$GFH_FLASH_DEV{ "F_SF"               } = chr(0x07);
$GFH_FLASH_DEV{ "F_XBOOT"            } = chr(0x08);
$GFH_FLASH_DEV{ "FLASH_DEV_END"      } = chr(0xFF);

$GFH_SIG_TYPE{ "SIG_NONE"             } = chr(0x00);
$GFH_SIG_TYPE{ "SIG_PHASH"            } = chr(0x01);
$GFH_SIG_TYPE{ "SIG_SINGLE"           } = chr(0x02);
$GFH_SIG_TYPE{ "SIG_SINGLE_AND_PHASE" } = chr(0x03);
$GFH_SIG_TYPE{ "SIG_MULTI"            } = chr(0x04);
$GFH_SIG_TYPE{ "SIG_TYPE_NUM"         } = chr(0x05);
$GFH_SIG_TYPE{ "SIG_TYPE_END"         } = chr(0xFF);

#****************************************************************************
# Input Parameters
#****************************************************************************
my ($src_bin_file)   = $ARGV[0];
my ($dst_bin_file)   = $ARGV[1];
my ($file_info_cfg)  = $ARGV[2];

#****************************************************************************
# Parameter Check
#****************************************************************************
die "source binary file $src_bin_file doesn't exist" if not -e $src_bin_file;
die "config file $file_info_cfg doesn't exist" if not -e $file_info_cfg;


#****************************************************************************
# Functions
#****************************************************************************
if (&IsGFH($src_bin_file))
{
    print "The $dst_bin_file has the GFH header, does not prepend the GFH header for $dst_bin_file";
    exit 0;
}
else
{
    my $b;
    my $sum;
    my $src_bin_file_size;
    open (SRC_FILE_HANDLE, "<$src_bin_file")  or &error_handler("$src_bin_file: open file error!");
    binmode(SRC_FILE_HANDLE);
    while (read(SRC_FILE_HANDLE, $b, 1))
    {
        $sum .= $b;
    }
    close SRC_FILE_HANDLE;

    open (FILE_HANDLE, ">$dst_bin_file") or &error_handler("$dst_bin_file: open file error!");
    $src_bin_file_size = (-s $src_bin_file) + 0x38 + 0xE0;
    &GFH_FileInfo_Gen($file_info_cfg, $src_bin_file_size);
    &GFH_DSPInfo_Gen($file_info_cfg, 0x38);
    binmode(FILE_HANDLE);
    print FILE_HANDLE @GFH_Buffer;
    print FILE_HANDLE $sum;
    close FILE_HANDLE;

#copy($src_bin_file, $dst_bin_file) or die "$!";
}

# GFH_FILE_INFO_v1
# [  3:  0] GFH_Header.m_magic_ver
# [  5:  4] GFH_Header.m_size, = size of GFH_FILE_INFO_v1 structure
# [  7:  6] GFH_Header.m_type, = GFH_FILE_INFO_v1
# [ 19:  8] identifier, = GFH_FILE_INFO_ID = "FILE_INFO"
# [ 23: 20] m_file_ver
# [ 25: 24] m_file_type, = PRI_ROM, DSP_ROM, ...
# [   : 26] m_flash_dev
# [   : 27] m_sig_type
# [ 31: 28] m_load_addr
# [ 35: 32] m_file_len
# [ 39: 36] m_max_size
# [ 43: 40] m_content_offset
# [ 47: 44] m_sig_len
# [ 51: 48] m_jump_offset
# [ 55: 52] m_attr
sub GFH_FileInfo_Gen
{
    my ($config_file, $input_file_len) = @_;
    my ($nIndex, $data) = (0, undef);
    my ($CONFIG_FILE_VER, $CONFIG_FILE_TYPE, $FLASH_DEV, $MAX_SIZE) = &GetFileInfoConfig($config_file);

#GFH_Header.m_magic_ver
    $GFH_Buffer[$nIndex++] = 'MMM'; #'M'
    $GFH_Buffer[$nIndex++] = chr(0x01);

#GFH_Header.m_size
    $GFH_Buffer[$nIndex++] = chr(0x38);
    $GFH_Buffer[$nIndex++] = chr(0x00);

#GFH_Header.m_type
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);

#identifier
    $GFH_Buffer[$nIndex++] = 'FILE_INFO';
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);

#m_file_ver
    $GFH_Buffer[$nIndex++] = $CONFIG_FILE_VER;

#m_file_type
    $GFH_Buffer[$nIndex++] = $GFH_FILE_TYPE{ $CONFIG_FILE_TYPE };

#m_flash_dev
    if($FLASH_DEV =~ /_NAND_FLASH_BOOTING_/)
    {
        $GFH_Buffer[$nIndex++] = $GFH_FLASH_DEV{ "F_NAND_FDM50" };
    }
    elsif($FLASH_DEV =~ /__EMMC_BOOTING__/)
    {
        $GFH_Buffer[$nIndex++] = $GFH_FLASH_DEV{ "F_EMMC_DATA_REGION" };
    }
    elsif($FLASH_DEV =~ /__X_BOOTING__/)
    {
        $GFH_Buffer[$nIndex++] = $GFH_FLASH_DEV{ "F_XBOOT" };
    }
    elsif($FLASH_DEV =~ /__SERIAL_FLASH_EN__/)
    {
        $GFH_Buffer[$nIndex++] = $GFH_FLASH_DEV{ "F_SF" };
    }
    elsif($FLASH_DEV =~ /__DONT_CARE_FLASH__/)
    {
        $GFH_Buffer[$nIndex++] = $GFH_FLASH_DEV{ "FLASH_DEV_NONE" };
    }
    else
    {
        $GFH_Buffer[$nIndex++] = $GFH_FLASH_DEV{ "F_NOR" };
    }
	
#m_sig_type
    $GFH_Buffer[$nIndex++] = $GFH_SIG_TYPE{ "SIG_NONE" };

#m_load_addr
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);

#m_file_len
    $GFH_Buffer[$nIndex++] = &Dec2ASCIIString($input_file_len);

#m_max_size
    $GFH_Buffer[$nIndex++] = &Dec2ASCIIString($MAX_SIZE);

#m_content_offset
    $GFH_Buffer[$nIndex++] = chr(0x18);
    $GFH_Buffer[$nIndex++] = chr(0x01);
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);

#m_sig_len
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);

#m_jump_offset
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);

#m_attr, no XIP in MT6290, default value is 0
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);

    print pack("i*", @GFH_Buffer);
}

# GFH_DSP_INFO_v1
# [  3:  0] GFH_Header.m_magic_ver
# [  5:  4] GFH_Header.m_size = size of GFH_FILE_INFO_v1 structure
# [  7:  6] GFH_Header.m_type = GFH_FILE_INFO_v1
# [ 11:  8] m_product_ver = 0x1 // 0x0: invalid, 0x1: debug version (DSP image not encrypted), 0x2: release version
# [ 15: 12] m_image_type // 0x0: invalid, 0x1: normal image, 0x2: RFC flavor image
# [ 31: 16] m_platform_id[16] // ex: "MT6290_S00", "MT6290_S01", "MT6595_S00"
# [ 95: 32] m_project_id[64] // ex: "DSPMOLY.W13.21.LTE.p6"
# [159: 96] m_build_time // ex: "24\10\2013 17:50:29"
# [223: 160] reserved
sub GFH_DSPInfo_Gen
{
    my ($config_file, $nIndex) = @_;
    my ($PLATFORM_ID, $VERSION, $BUILD_TIME) = &GetDSPInfoConfig($config_file);
    my ($counter);

#GFH_Header.m_magic_ver
    $GFH_Buffer[$nIndex++] = 'MMM'; #'M'
    $GFH_Buffer[$nIndex++] = chr(0x01);

#GFH_Header.m_size
    $GFH_Buffer[$nIndex++] = chr(0xE0);
    $GFH_Buffer[$nIndex++] = chr(0x00);

#GFH_Header.m_type
    $GFH_Buffer[$nIndex++] = chr(0x04);
    $GFH_Buffer[$nIndex++] = chr(0x01);

#m_product_ver
    $GFH_Buffer[$nIndex++] = chr(0x01);
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);

#m_image_type
    $GFH_Buffer[$nIndex++] = chr(0x00); #why not 1??
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);
    $GFH_Buffer[$nIndex++] = chr(0x00);

#m_platform_id
    if (length($PLATFORM_ID) > 16)
    {
        print "The platform ID strings exceed the max string size 16!";
        exit 0;
    }
    $GFH_Buffer[$nIndex++] = $PLATFORM_ID;
    for ($counter = length($PLATFORM_ID) + 1; $counter <= 16; $counter++)
    {
        $GFH_Buffer[$nIndex++] = chr(0x00);
    }

#m_project_id
    if (length($VERSION) > 64)
    {
        print "The project ID strings exceed the max string size 64!";
        exit 0;
    }
    $GFH_Buffer[$nIndex++] = $VERSION;
    for ($counter = length($VERSION) + 1; $counter <= 64; $counter++)
    {
        $GFH_Buffer[$nIndex++] = chr(0x00);
    }

#m_build_time
    if (length($BUILD_TIME) > 64)
    {
        print "The build time strings exceed the max string size 64!";
        exit 0;
    }
    $GFH_Buffer[$nIndex++] = $BUILD_TIME;
    for ($counter = length($BUILD_TIME) + 1; $counter <= 64; $counter++)
    {
        $GFH_Buffer[$nIndex++] = chr(0x00);
    }

#reserved
    for (0..63)
    {
        $GFH_Buffer[$nIndex++] = chr(0x00);
    }

    print pack("i*", @GFH_Buffer);
}

#****************************************************************************
# subroutine:  Get file config
# input:       config file
# output:      File Info config setting
#****************************************************************************
sub GetFileInfoConfig
{
    my $fileContent = &GetFileContent(@_);
    my $parse_file_ver;
    my $parse_file_ver_str;
    my $parse_file_type;
    my $parse_flash_dev;
    my $parse_max_size;

    $fileContent =~ s/(.*)#(.*)/$1/g;

    $fileContent =~ /FILE_VER:[ \f\t]*(\w*)[ \f\t]*/;
    $parse_file_ver = hex($1);
    $parse_file_ver_str = &Dec2ASCIIString($parse_file_ver);

    $fileContent =~ /FILE_TYPE:[ \f\t]*(\w*)[ \f\t]*/;
    $parse_file_type = $1;

    $fileContent =~ /FLASH_DEV:[ \f\t]*(\w*)[ \f\t]*/;
    $parse_flash_dev = $1;

    $fileContent =~ /MAX_SIZE:[ \f\t]*(\w*)[ \f\t]*/;
    $parse_max_size = hex($1);

    return ($parse_file_ver_str, $parse_file_type, $parse_flash_dev, $parse_max_size);
}

#****************************************************************************
# subroutine:  Get dsp config
# input:       config file
# output:      DSP Info config setting
#****************************************************************************
sub GetDSPInfoConfig
{
    my $fileContent = &GetFileContent(@_);
    my $platform_id;
    my $parse_version;
    my $build_time;

    $fileContent =~ s/(.*)#(.*)/$1/g;

    $fileContent =~ /PLATFORM_ID:[ \f\t]*(.*)[ \f\t]*/;
    $platform_id = $1;

    $fileContent =~ /VERSION:[ \f\t]*(.*)[ \f\t]*/;
    $parse_version = $1;

    $fileContent =~ /BUILD_TIME:[ \f\t]*(.*)[ \f\t]*/;
    $build_time = $1;

    return ($platform_id, $parse_version, $build_time);
}

#****************************************************************************
# subroutine:  GetFileContent
# input:   strFilePath
# output:  strFileContent after chomp
#****************************************************************************
sub GetFileContent
{
    my ($strFilePath) = @_;
    my $content;
    open FILE, "<$strFilePath" or &error_handler("$strFilePath: open file error!", __FILE__, __LINE__, 'CommonUtil::GetFileContent');
    {
        local $/;
        $content = <FILE>;
    }
    close FILE;
    chomp($content);
    return $content;
}

#****************************************************************************
# subroutine:  Dec2HexASCII, without "0x" for prefix, big endian
# input:       Integer value
# output:      Hex ASCII without "0x"
#****************************************************************************
sub Dec2ASCIIString
{
    my ($dec) = @_;
    my $str = "";
    if ($dec > 0x00FF0000)
    {
        $str .= chr(($dec >> 0) & 0xFF);
        $str .= chr(($dec >> 8) & 0xFF);
        $str .= chr(($dec >> 16) & 0xFF);
        $str .= chr(($dec >> 24) & 0xFF);
    }
    elsif($dec > 0x0000FF00)
    {
        $str .= chr($dec & 0xFF);
        $str .= chr(($dec >> 8) & 0xFF);
        $str .= chr(($dec >> 16) & 0xFF);
        $str .= chr(0x00);
    }
    elsif($dec > 0x000000FF)
    {
        $str .= chr($dec & 0xFF);
        $str .= chr(($dec >> 8) & 0xFF);
        $str .= chr(0x00);
        $str .= chr(0x00);
    }
    else
    {
        $str .= chr($dec & 0xFF);
        $str .= chr(0x00);
        $str .= chr(0x00);
        $str .= chr(0x00);
	}

}

#****************************************************************************
# subroutine:  Check GFH Header, (0-2: 4D 4D 4D, 8-16: FILE_INFO)
# input:       File Name
# output:      True/False
#****************************************************************************
sub IsGFH
{
    my ($strFilePath) = @_;
    my $bIsGFH = 0;

    if (-e $strFilePath)
    {
# Get 17bytes (0-2: 4D 4D 4D, 8-16: FILE_INFO
    open (FILE_HANDLE, "<$strFilePath") or &error_handler("$strFilePath: open file error!");
#binmode(FILE_HANDLE);
        my ($nIndex, $data) = (0, undef);
        my @Buffer;
        while (read(FILE_HANDLE, $data, 1))
        {
            $Buffer[$nIndex++] = $data;
            last if ($nIndex > 16);
        }
        close FILE_HANDLE;
        my ($strFILE_INFO, $nMatchMMM) = (undef, 0);
        for (0..2)
        {
            $nMatchMMM++ if (ord($Buffer[$_]) == 0x4D);
        }
        for (8..16)
        {
            $strFILE_INFO .= $Buffer[$_];
        }
        $bIsGFH =1 if($nMatchMMM == 3 and $strFILE_INFO eq "FILE_INFO");
    }
    
    return $bIsGFH;
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#              $file:          filename
#              $line_no:       line number
#****************************************************************************
sub error_handler
{
    my ($error_msg) = @_;
    my ($pack_name, $file, $line_no) = caller;
    my $final_error_msg = "PREPEND_GFH ERROR: $error_msg at $file line $line_no\n";
    die $final_error_msg;
}
