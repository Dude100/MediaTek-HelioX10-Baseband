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
BEGIN { push @INC, './tools/' }  # add additional library path
use File::Basename;
use File::Copy;
#use CommonUtility;
#use tools::pack_dep_gen;
#PrintDependModule();

#****************************************************************************
# Constants
#****************************************************************************
my $PREPEND_GFH_VERNO = " m0.01";
# v0.01 by mtk03404, initial version

#Usage: modify_gfh_file_info.pl SRC_BINFILE_PATH(filename) DST_BINFILE_PATH(filename) file_info.conf

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
$GFH_FILE_TYPE{ "SLT_TEST_LOAD_0" } = chr(0x00).chr(0x80); #Big Endian
$GFH_FILE_TYPE{ "SLT_TEST_LOAD_1" } = chr(0x01).chr(0x80); #Big Endian
$GFH_FILE_TYPE{ "SLT_TEST_LOAD_2" } = chr(0x02).chr(0x80); #Big Endian
$GFH_FILE_TYPE{ "SLT_TEST_LOAD_3" } = chr(0x03).chr(0x80); #Big Endian
$GFH_FILE_TYPE{ "SLT_TEST_LOAD_4" } = chr(0x04).chr(0x80); #Big Endian
$GFH_FILE_TYPE{ "SLT_TEST_LOAD_5" } = chr(0x05).chr(0x80); #Big Endian
$GFH_FILE_TYPE{ "SLT_TEST_LOAD_6" } = chr(0x06).chr(0x80); #Big Endian
$GFH_FILE_TYPE{ "PRIMARY_MAUI" } = chr(0x00).chr(0x01); #Big Endian

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
if (!&IsGFH($src_bin_file))
{
    print "The $dst_bin_file has not GFH header, can not modify the GFH header for $dst_bin_file";
    exit 0;
}


{
    my $b;
    my $sum;
    my $src_bin_file_size;
    my $nIndex = 0;
    open (SRC_FILE_HANDLE, "<$src_bin_file")  or &error_handler("$src_bin_file: open file error!");
    binmode(SRC_FILE_HANDLE);
    for (0..0x37)
    {
        read(SRC_FILE_HANDLE, $b, 1);
        $GFH_Buffer[$nIndex++] = $b;
    }
    while (read(SRC_FILE_HANDLE, $b, 1))
    {
        $sum .= $b;
    }
    close SRC_FILE_HANDLE;

    open (FILE_HANDLE, ">$dst_bin_file") or &error_handler("$dst_bin_file: open file error!");
    $src_bin_file_size = (-s $src_bin_file);
    &GFH_FileInfo_Mod($file_info_cfg, $src_bin_file_size);
    binmode(FILE_HANDLE);
    print FILE_HANDLE @GFH_Buffer;
    print FILE_HANDLE $sum;
    close FILE_HANDLE;



#copy($src_bin_file, $dst_bin_file) or die "$!";
}

# GFH_FILE_INFO_v1
# [  3:  0] GFH_Header.m_magic_ver
# [  5:  3] GFH_Header.m_size, = size of GFH_FILE_INFO_v1 structure
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
sub GFH_FileInfo_Mod
{
    my ($config_file, $input_file_len) = @_;
    my ($CONFIG_FILE_VER, $CONFIG_FILE_TYPE, $FLASH_DEV, $MAX_SIZE, $ATTR) = &GetFileInfoConfig($config_file);
    my $nIndex;
    
#m_file_type
    $nIndex = 0x18;
    ($GFH_Buffer[$nIndex++], $GFH_Buffer[$nIndex++]) = $GFH_FILE_TYPE{ $CONFIG_FILE_TYPE };

#m_max_siz
    $nIndex = 0x24;
    ($GFH_Buffer[$nIndex++], $GFH_Buffer[$nIndex++], $GFH_Buffer[$nIndex++], $GFH_Buffer[$nIndex++]) = &Dec2ASCIIString($MAX_SIZE);

#m_attr, no XIP in MT6290, default value is 0
    $nIndex = 0x34;
    ($GFH_Buffer[$nIndex++], $GFH_Buffer[$nIndex++], $GFH_Buffer[$nIndex++], $GFH_Buffer[$nIndex++]) = &Dec2ASCIIString($ATTR);
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
    my $parse_attr;

    $fileContent =~ s/(.*)#(.*)/$1/g;

    $fileContent =~ /FILE_VER:[\f\t]*(\w*)[\f\t]*/;
    $parse_file_ver = hex($1);
    $parse_file_ver_str = &Dec2ASCIIString($parse_file_ver);

    $fileContent =~ /FILE_TYPE:[\f\t]*(\w*)[\f\t]*/;
    $parse_file_type = $1;

    $fileContent =~ /FLASH_DEV:[\f\t]*(\w*)[\f\t]*/;
    $parse_flash_dev = $1;

    $fileContent =~ /MAX_SIZE:[\f\t]*(\w*)[\f\t]*/;
    $parse_max_size = hex($1);

    $fileContent =~ /ATTRIBUTE:[\f\t]*(\w*)[\f\t]*/;
    $parse_attr = hex($1);
    
    return ($parse_file_ver_str, $parse_file_type, $parse_flash_dev, $parse_max_size, $parse_attr);
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
    open FILE, "<$strFilePath" or &error_handler("$strFilePath: open file error!", __FILE__, __LINE__, 'GetFileContent');
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
    $bIsGFH = 1 if ($nMatchMMM == 3 and $strFILE_INFO eq "FILE_INFO");
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
    my $final_error_msg = "MODIFY_GFH_FILE_INFO ERROR: $error_msg at $file line $line_no\n";
    die $final_error_msg;
}
