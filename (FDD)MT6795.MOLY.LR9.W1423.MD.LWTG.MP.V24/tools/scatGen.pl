#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2007
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
#*   scatGen.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script aim to generate scatter file base on Makefile and custom_EMI.h
#*       1. generate scatter file if not exists
#*
#* Author:
#* -------
#*   JI Huang  (mtk01077)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './tools/' }  # add additional library path
use sysGenUtility;               # pm file name without case sensitivity
use FileInfoParser;
use CommonUtility;
use scatInfo;
use config_MemSegment;
use tools::pack_dep_gen;
PrintDependModule();

#****************************************************************************
# Global Variables
#****************************************************************************
my $g_strCOMPILER = undef;
my $g_bb = undef;
my $g_bUSE_DUMMY_SCATTER = 0;
my $DebugPrint = 1; # 1 for debug; 0 for non-debug

#****************************************************************************
# File Names
#****************************************************************************
my $SCATTERFILE           = $ARGV[0];
my $BL_SCATTERFILE        = $ARGV[1];
my $themf                 = $ARGV[2];
my $BB_PATH               = $ARGV[3];
my $CUSTOM_EMI_RELEASE_H  = $ARGV[3] . '/' . "custom_EMI_release.h";
my $CUSTOM_MEM_DEV_H      = $ARGV[3] . '/' . "custom_MemoryDevice.h";
my $CUSTOM_FEATURECONFIG_H = $ARGV[3] . '/' . "custom_FeatureConfig.h";
my $CUSTOM_FLASH_H        = $ARGV[3] . '/' . "custom_flash.h";
my $CUSTOM_IMG_CONFIG_H   = $ARGV[3] . '/' . "custom_img_config.h";
my $NEED_BUILD_BOOTLOADER = $ARGV[4];
my $INSIDE_MTK            = $ARGV[5];  # INSIDE_MTK (need to check dummy_scatter_enable)
my $DUMMY_SCATTER_FORCE   = $ARGV[6];  # DUMMY_LIS (from gendummylis)
my $INFOMAKELOG           = $ARGV[7];
my $COPRO_INFO_FILE       = $ARGV[8];

# to align error message file name format
$SCATTERFILE =~ s/^.\/|^\///;
$themf       =~ s/^.\/|^\///;
$BB_PATH     =~ s/^.\/|^\///;

# DL scat: scatter file for flash tool to download images
my $DL_SCATTERFILE = $SCATTERFILE;
$DL_SCATTERFILE =~ s/\.txt//;
$DL_SCATTERFILE .= "_flashtool.txt";
my $DL_Wateramrk = ';AutoGen Copyed from';

# ext_BL scatter file
my $EXT_BL_SCATTERFILE = $BL_SCATTERFILE;
$EXT_BL_SCATTERFILE =~ s/.txt//;
$EXT_BL_SCATTERFILE .= "_ext.txt";
#****************************************************************************
# 1 >>> main judges : scatter file exists or not
#****************************************************************************
&sysUtil::del_noCheckinHistory_file($BL_SCATTERFILE);
&sysUtil::del_noCheckinHistory_file($EXT_BL_SCATTERFILE);
&sysUtil::del_noCheckinHistory_file($SCATTERFILE);
&sysUtil::del_noCheckinHistory_file($DL_SCATTERFILE);
# DL_scatter with watermark($DL_Wateramrk) and Check-in history will be deleted.
# -> Always regen copyed file.
&DelFileWithKeyword($DL_SCATTERFILE, $DL_Wateramrk);
#****************************************************************************
# 2 >>> parse infomake.log and Project MakeFile+corpo_info_gen.log
#****************************************************************************
my %MAKEFILE_OPTIONS;
# Combine Copro_info into MakeFile Option, and then it can be queried by FileInfo.
my $strCoproInfo = CommonUtil::GetFileContent($COPRO_INFO_FILE);
CommonUtil::HashStringParser($strCoproInfo, \%MAKEFILE_OPTIONS) if($strCoproInfo ne "");
my %CmplOption;
my %RelOption;
FileInfo::PreProcess($themf, \%MAKEFILE_OPTIONS, $INFOMAKELOG, \%CmplOption, \%RelOption,1);    
$g_strCOMPILER = &FileInfo::GetCompiler();
$g_bb = &sysUtil::SwitchToClonedChip(&FileInfo::GetChip()); #use infomake.log

#****************************************************************************
# 4 >>> Check user settings validity - DUMMY SCATTER
#****************************************************************************
$g_bUSE_DUMMY_SCATTER = &sysUtil::isDummyScatter($INSIDE_MTK, $DUMMY_SCATTER_FORCE);
&CheckDummyScatter($SCATTERFILE, $g_bUSE_DUMMY_SCATTER);
#****************************************************************************
# 5 >>> Parse Input files
#****************************************************************************
&memConfig::Parse($CUSTOM_MEM_DEV_H, memConfig::MEMORY_DEVICE,        $INSIDE_MTK, $g_bUSE_DUMMY_SCATTER);
&memConfig::Parse($CUSTOM_FEATURECONFIG_H, memConfig::FEATURE_CONFIG, $INSIDE_MTK, $g_bUSE_DUMMY_SCATTER);
&memConfig::Parse($CUSTOM_EMI_RELEASE_H, memConfig::CUSTOM_EMI,       $INSIDE_MTK, $g_bUSE_DUMMY_SCATTER);
&memConfig::Parse($CUSTOM_FLASH_H, memConfig::CUSTOM_FLASH,           $INSIDE_MTK, $g_bUSE_DUMMY_SCATTER);
&memConfig::Parse($CUSTOM_IMG_CONFIG_H, memConfig::CUSTOM_IMG_CONFIG, $INSIDE_MTK, $g_bUSE_DUMMY_SCATTER) if($g_strCOMPILER =~ /RVCT/i);
#****************************************************************************
# 12 >>> Verify parsed value
#****************************************************************************
&PrintDebugInfo();
&memConfig::VerifyRAMInfo($g_bUSE_DUMMY_SCATTER);
&memConfig::VerifyFSInfo($g_bUSE_DUMMY_SCATTER);
#****************************************************************************
# 16 >>> Generate MAUI Scatter File
#****************************************************************************
if (!-e $SCATTERFILE)
{
    &GenMAUIScatter($SCATTERFILE, 0) if($g_strCOMPILER eq "RVCT");
    &GenMAUI_LDS($SCATTERFILE, 0) if($g_strCOMPILER eq "GCC");
}
#****************************************************************************
# 17 >>> Generate DL Scatter File for flash tool
#****************************************************************************
if (!-e $DL_SCATTERFILE)
{
    if(-e $SCATTERFILE)
    {
        &CopyandMarkFile($SCATTERFILE, $DL_SCATTERFILE, $DL_Wateramrk) if($g_strCOMPILER eq "RVCT"); 
        &GenScatSkeleton($SCATTERFILE, $DL_SCATTERFILE) if($g_strCOMPILER eq "GCC");
    }
}
#****************************************************************************
# 18 >>> Generate Bootloader Scatter File
#****************************************************************************
if (!-e $BL_SCATTERFILE and $NEED_BUILD_BOOTLOADER eq "TRUE")
{
    &GenBLScatter() if($g_strCOMPILER eq "RVCT");
    if($g_strCOMPILER eq "GCC")
    {
        &GenBL_LDS($BL_SCATTERFILE, "BL");
        &GenBL_LDS($EXT_BL_SCATTERFILE, "EXT_BL"); 
    }
}
#****************************************************************************
# 19 >>> sysgen2
#****************************************************************************
require "sysGen2.pl";
print "========Run sysGen2.pl==========\n";
&sysgen2_main($BB_PATH, $SCATTERFILE, $BL_SCATTERFILE, $EXT_BL_SCATTERFILE);
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit 0;

#****************************************************************************
# subroutine:  GenScatSkeleton: Generate flashtool.txt from linker script
# input:       1. Linker script path
#              2. flashtool.txt path
# return:      N/A
#****************************************************************************
sub GenScatSkeleton
{
    my ($LDS_FILEPATH, $DL_ScatSkeleton) = @_;
    my $strLayout;
    my $LinkInfo = lds_new scatInfo($LDS_FILEPATH, "ROM");
    my $LR_aref = $LinkInfo->GetAllLoadRegion();
    my $RegionMap_href = $LinkInfo->GetRegionMap();
    push (@$LR_aref, "DSP_ROM") if($g_bb eq "MT6290");
    foreach my $strLRName (@$LR_aref)
    {
        my $LR = $RegionMap_href->{$strLRName};
        $strLayout .= $strLRName . "\n{\n";
        map{ $strLayout .= ' 'x4 ."$_\n";} @$LR;
        $strLayout .= "}\n";
    }
    &Output($DL_ScatSkeleton, "defines the memory map for the validation board", 
         &scatInfo::GetldsInfoWrap_VERNO(), &get_board_parameters(), 1, $strLayout);
}

#****************************************************************************
# subroutine:  GenMAUI_LDS: Generate MAUI main linker script
# input:
# return:      x
# require:    tools/ldsGenLib.pl -> ldsGen_main();
#****************************************************************************
sub GenMAUI_LDS
{
    my ($filepath, $bIs_Flashtool_Layout) = @_;
    require "ldsGenLib.pl";
    my $strLayout = &ldsGen_main( $g_bb, 
                           &memConfig::GetExtRamSize(),
                           $NEED_BUILD_BOOTLOADER,
                           $BB_PATH,
                           $themf);
    &Output($filepath, "defines the memory map for the validation board", 
         &ldsGen_verno(), &get_board_parameters(), 1, $strLayout);
}
#****************************************************************************
# subroutine:  GenMAUIScatter: Generate MAUI main scatter file
# input: 	     $filepath : the file path to save a scatter layout 
#                 $Is_Flashtool_Layout : 0=normal layout, 1=flashtool required layout
# return:      x
# require:    tools/scatGenLib.pl -> scatGen_main();
#****************************************************************************
sub GenMAUIScatter
{
    #$Is_Flashtool_Layout : 0=normal layout, 1=flashtool required layout
    my ($filepath, $Is_Flashtool_Layout) = @_;
    require "scatGenLib.pl";
    my $scat_content = &scatGen_main(sub { my ($key) = @_;
                                           return &FileInfo::get($key);
                                         },
                                     $g_bb,
                                     &memConfig::GetROMSize(),,
                                     &memConfig::GetBlockTable(),
                                     &memConfig::GetExtRamSize(),
                                     (!&FileInfo::is_NOR()) ? "TRUE" : "FALSE",
                                     &memConfig::GetSource(memConfig::CUSTOM_IMG_CONFIG),
                                     $BB_PATH,
                                     $themf,
                                     $NEED_BUILD_BOOTLOADER,
                                     &memConfig::GetSource(memConfig::MEMORY_DEVICE),
                                     $Is_Flashtool_Layout,
                                     $g_bUSE_DUMMY_SCATTER,
                                     &memConfig::GetSource(memConfig::FEATURE_CONFIG),
                                     0
                                    );

    &sysUtil::sysgen_die("Unsupported Feature Combination. Please create $filepath manually!", __FILE__, __LINE__) 
        unless defined $scat_content;
    &OutputScatter($filepath, "defines the memory map for the validation board", 
                                           &get_board_parameters(),$scat_content);
}
#****************************************************************************
# subroutine:  GenBLScatter: Generate BL scatter file
# input: 	     $filepath : the file path to save a scatter layout 
# return:      x
# require:    tools/BLscatGen.pl -> scatGenBL_main()
#****************************************************************************
sub GenBLScatter
{
    require "tools/scatGenBL.pl";
    my ($strBL, $strEXTBL) = &scatGenBL_main(sub { my ($key) = @_;
                                      return &FileInfo::get($key);
                                    },
                               $g_bb,
                               &memConfig::GetExtRamSize(),
                               $BB_PATH,
                               $SCATTERFILE
                              );
    &OutputScatter($BL_SCATTERFILE, "defines the memory map for boot-loader", undef, $strBL);
    &OutputScatter($EXT_BL_SCATTERFILE, "defines the memory map for ext-bootloader", undef, $strEXTBL);
}

sub OutputScatter
{
    my ($strFilePath, $description, $Comments, $strFileContent) = @_;
    open (FILE, ">$strFilePath") or &sysUtil::sysgen_die("$strFilePath: open file error!", __FILE__, __LINE__);
    print FILE &copyright_file_header_for_scatter($g_bb);
    require "tools/scatGenLib.pl";
    print FILE &description_file_header_for_scatter( $strFilePath,
                             $description."\n",
                             "system auto generator ". &scatGen_verno(). 
                             " + scatGen" . &GetSCATGEN_VERNO().
                             " + sysGenUtility" . &sysUtil::sysgenUtility_verno(),
                             , $Comments);
    print FILE $strFileContent;
    close FILE;
    print "$strFilePath is generated\n";
}
sub Output
{
    my ($strFilePath, $description, $verno, $Comments, $bAutoGen, $strFileContent) = @_;
    open (FILE, ">$strFilePath") or &sysUtil::sysgen_die("$strFilePath: open file error!", __FILE__, __LINE__);
    print FILE &sysUtil::copyright_file_header();
    print FILE &sysUtil::description_file_header($strFilePath,
                                                 $description."\n",
                                                 "system auto generator ". $verno . 
                                                 " + scatGen" . &GetSCATGEN_VERNO().
                                                 " + sysGenUtility" . &sysUtil::sysgenUtility_verno(),
                                                 $Comments, $bAutoGen);
    print FILE $strFileContent;
    close FILE;
    print "$strFilePath is generated\n";
}
#****************************************************************************
# subroutine:  GenBL_LDS: Generate bootloader linker script
# input:
# return:      x
# require:    tools/ldsGenBL.pl -> BLldsGen_main();
#****************************************************************************
sub GenBL_LDS
{
    my ($filepath, $strBLType) = @_;
    require "tools/ldsGenBL.pl";
    my $strLDS = &ldsGenBL_main(  $g_bb, 
                                  &memConfig::GetExtRamSize(),
                                  $BB_PATH,
                                  $themf,
                                  $SCATTERFILE,
                                  $strBLType);
   
    &Output($filepath, "defines the memory map for bootloader", 
             &ldsGenBL_verno(), &get_board_parameters(), 1, $strLDS);
}

#****************************************************************************
# subroutine:  CopyandMarkFile: Copy a file from source  to destination
#                    with adding $Watermark in the line containing 'Filename:', 
#                    and replace .txt to _flashtool.txt once.
# input:          $SrcPath : Source file path
#                 $DestPath : Destined file path
#                 $Watermark : the keyword to identify if the destined file is copied or manually added.
# return:      x
#****************************************************************************
sub CopyandMarkFile
{
    my($SrcPath, $DestPath, $Watermark)= @_;
    my $KeyWordtoMark = "$Watermark: $SrcPath";
    my $content;
    open FILE, "<$SrcPath" or &sysUtil::sysgen_die("$SrcPath: open file error!", __FILE__, __LINE__);
    {
        local $/;
        $content = <FILE>;
    }
    close FILE;
    
    #Change File Name
    $content =~ s/\.txt/_flashtool.txt/;
    #Write Copy Mark
    $content =~ s/Filename:/Filename: $KeyWordtoMark/; 
    
    open FILE, ">$DestPath" or &sysUtil::sysgen_die("$DestPath: open file error!", __FILE__, __LINE__);
    print FILE $content;
    close FILE;
}
#****************************************************************************
# subroutine:  DelFileWithKeyword: Delete the existent file which contains $Watermark
# input: 	     $FilePath : the file path you want to delete
#                 $Keyword : the keyword you want to search in the file
# return:      x
#****************************************************************************
sub DelFileWithKeyword
{
    my ($FilePath, $Keyword) = @_;

    if(-e $FilePath)
    {
        my $NeedDelete = 0;
    
        open FILE, "<$FilePath" or &sysUtil::sysgen_die("$FilePath: open file error!", __FILE__, __LINE__);
        {
            local $/;
            my $content = <FILE>;
            $NeedDelete = 1 if($content =~ /$Keyword/);
        }
        close FILE;
        if($NeedDelete eq 1)
        {
            unlink $FilePath;
        }
    }
}
#****************************************************************************
# subroutine:  get the board parameters
# return:      the summary string 
#****************************************************************************
sub get_board_parameters
{
    my ($loadsize, $ramsize) = ( &memConfig::GetROMSize() / (1024 * 1024),
                                 &memConfig::GetExtRamSize() / (1024 * 1024)
                               );
    $loadsize = $loadsize . "MB";
    $ramsize  = $ramsize . "MB";
    my $sw_features = &CollectMemoryTypeForComments();
    my $strDummy = $g_bUSE_DUMMY_SCATTER ? "Yes" : "No";
    my $template1 = <<"__TEMPLATE";
;--------------------
; SCHEME   : external $loadsize flash memory and $ramsize SRAM
; DUMMY SETTING : $strDummy
; PLATFORM : $g_bb
; FEATURES : $sw_features
;--------------------
__TEMPLATE

    my $template2 = <<"__TEMPLATE";
;--------------------
; SCHEME   : external NAND flash and $ramsize LPSDRAM
; DUMMY SETTING : $strDummy
; PLATFORM : $g_bb
; FEATURES : $sw_features
;--------------------
__TEMPLATE

    if($g_strCOMPILER eq "GCC")
    {
        $template1 =~ s/\;/ \*/g;
        $template2 =~ s/\;/ \*/g;
    }
    if (!FileInfo::is_NonSPNOR()) { return $template2; }
    else                          { return $template1; }
}

sub CollectMemoryTypeForComments
{
    my $strSWCFG;
    if(&FileInfo::isnot('nand_flash_booting', 'NONE'))
    {
        $strSWCFG .= "NFB ";
    }
    if(&FileInfo::isnot('emmc_booting', 'NONE'))
    {
        $strSWCFG .= "EMB ";
    }
    if(&FileInfo::is_SmartPhone())
    {
        $strSWCFG .= "[SmartPhone]". &FileInfo::get("SMART_PHONE_CORE"). " ";    
    }
    if(&FileInfo::isnot('usb_download_in_bl', 'NONE'))
    {
        $strSWCFG .= "USBDOWNLOAD ";
    }
    if(&FileInfo::is('multiple_binary_files', 'TRUE'))
    {
        $strSWCFG .= "MULTIBIN ";
    }
    if(&FileInfo::is('secure_support', 'TRUE'))
    {
        $strSWCFG .= "SECURE ";
    }
    if(&FileInfo::is('enhanced_single_bank_nor_flash_support', 'TRUE'))
    {
        $strSWCFG .= "ESBNOR ";
    }
    return $strSWCFG;
}
#****************************************************************************
# subroutine:  description_file_header
# return:      file header -- description 
# input:       $filename:     filename
# input:       $description:  one line description
# input:       $author:       optional
#****************************************************************************
sub description_file_header_for_scatter
{
    my ($filename, $description, $author, $board_description) = @_;
    my @lines = split(/\n/, &sysUtil::description_file_header($filename, $description, $author, $board_description, 1));
    my $template;
    map{ $template .= ";".$_."\n" }@lines;
    return $template;
}
#****************************************************************************
# subroutine:  copyright_file_header
# return:      file header -- copyright
#****************************************************************************
sub copyright_file_header_for_scatter
{
    my ($bb) = @_;
    my $pre_compile_str;
    if(&FileInfo::is("dsp_solution", "DUALMACDSP") or $bb eq "MT6251")
    {
        $pre_compile_str = "#! armcc -E";
    }
    my @lines = split(/\n/, &sysUtil::copyright_file_header());
    my $template;
    map{ $template .= ";".$_."\n" }@lines;
    return $pre_compile_str.$template;
}


#****************************************************************************
# Subroutine: PrintDebugInfo
# Purpose: Print Memory related information for debug usage
#****************************************************************************
sub PrintDebugInfo
{
    if ($DebugPrint == 1)
    {
        print "Chip=$g_bb\n"; 
        
        print "custom_MemoryDevice.h:\n";
        print "NOR_BOOTING_NOR_FS_BASE_ADDRESS = ".&memConfig::GetMemDev('NOR_BOOTING_NOR_FS_BASE_ADDRESS')."\n";
        print "NOR_BOOTING_NOR_FS_SIZE = ".&memConfig::GetMemDev('NOR_BOOTING_NOR_FS_SIZE')."\n";
        print "NAND_BOOTING_NAND_FS_BASE_ADDRESS = ".&memConfig::GetMemDev('NAND_BOOTING_NAND_FS_BASE_ADDRESS')."\n";
        print "NAND_BOOTING_NAND_FS_SIZE = ".&memConfig::GetMemDev('NAND_BOOTING_NAND_FS_SIZE')."\n";
        
        print "PROJECT_EXPECTED_RAM_LIMIT = ".&memConfig::GetFtCfg('PROJECT_EXPECTED_RAM_LIMIT')."\n";
        print "PROJECT_EXPECTED_CODE_LIMIT = ".&memConfig::GetFtCfg('PROJECT_EXPECTED_CODE_LIMIT')."\n"; 
        print "PROJECT_EXPECTED_RAM_LIMIT_NFB = ".&memConfig::GetFtCfg('PROJECT_EXPECTED_RAM_LIMIT_NFB')."\n";      
        print "\n";
        
        if(!&FileInfo::is_SmartPhone())
        {
            print "custom_flash.h:\n";
            print "[original input]\n";
            my ($Blk, $Region, $Bank, $density, $size) = &memConfig::GetFlashInfoLog();
            print "BlockTBLTxt = ". $Blk ."\n";
            print "RegionInfoTxt = ". $Region,."\n";
            print "BankInfoTxt = ". $Bank."\n";
            print "NOR_FLASH_DENSITY = ". $density."\n";
            print "NOR_FLASH_SIZE = ". $size."\n";
            print "\n";
            
            print "custom_emi_release.h:\n";
            print "[original input]\n";
            print "Original RamSize = ". &memConfig::GetPhysicalExtRAMSize(1)."\n";
            print "\n";
        }
        
        print "BOARD_PARAMTERS(Processed information):\n";
        print "Processed RamSize = ". &memConfig::GetExtRamSize().
                                  "(".&CommonUtil::Dec2Hex(&memConfig::GetExtRamSize()).")\n";
        print "Processed ROMSize = ". &memConfig::GetROMSize().
                                  "(".&CommonUtil::Dec2Hex(&memConfig::GetROMSize()).")\n";
        print "\n";
    }
}
sub CheckDummyScatter
{
    my ($strScatterPath, $bIsDummy) = @_;
    if(&sysUtil::HasCheckinHistory($strScatterPath) && $bIsDummy)
    {
        &sysUtil::sysgen_die("Generating DUMMY SCATTER FILE can't work when a manual checked-in scatter file exists.\nRecommand: Please remove your own modifications first, \nrebuild and make sure the load is successfully built, \nthen add your own modifications back.\n", __FILE__, __LINE__);
    }
}

sub GetSCATGEN_VERNO
{
    my $SCATGEN_VERNO = " m0.05";
                        # m0.05 by mei , 20130625, support copro_info.log input
                        # m0.04 by mei , 20130528, support infomake.log input
                        # m0.03 by mei , 20130212, Add DSP into fake scatter for MT6290's cfggen
                        # m0.02 by mei , 20121019, Remove FOTA
                        # m0.01 by mei , 20120920, Support MultiBin on MOLY
  
    return $SCATGEN_VERNO;    
}

