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
#*   ModemReservedSize_AutoConfig.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script parses sym/linker script 
#*   and give some recommendation or create new MEMORY config file
#* Author:
#* -------
#*   Qmei Yang  (mtk03726)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './tools/', './tools/MemoryUtility/' }  # add additional library path             
use auto_adjust_mem; #pm file name without case sensitivity
use FileInfoParser;
use sysGenUtility;
use CommonUtility;
use BasicMemInfoQuery;
use systemInfo;
use ldsFrame;
use File::Basename;
use File::Copy;
use File::Path;
use LinkerOutputParser;
use POSIX qw(floor ceil);
#****************************************************************************
# AutoCheckin Information
#****************************************************************************
use constant OWNER        => "";
#****************************************************************************
# Constants
#****************************************************************************
my $MODEMSIZE_CONFIG_VERNO    = " v0.11";
                               #  v0.11, 20140630 by carl, Disable AAPMC adjustment and load size checking in TCM ONLY load (use more intuitive function)
                               #  v0.10, 20140610 by carl, Disable AAPMC adjustment and load size checking in TCM ONLY load
                               #  v0.09, 20140307 by mei, Support LV alignment adjusted by chip
                               #  v0.08, 20130625 by mei, Support COPRO auto config
                               #  v0.07, 20130603 by mei, Add infomake.log input
                               #  v0.06, 20130425 by mei, Not to limit SetMemorySegment() in NOR project only 
                               #  v0.05, 20130321 by mei, Support to show basic ram info during checking load view
                               #  v0.04, 20130321 by mei, Set MT6572&6582 to be 2 MB aligned
                               #  v0.03, 20130208 by mei, perl 5.58 can't support: make_path
                               #  v0.02, 20130124 by mei, to replace chip with cloned chip
                               #  v0.01, initial draft

#****************************************************************************
# Inputs
#****************************************************************************
my $MAP_PATH                    = $ARGV[0]; 
my $SYM_PATH                    = $ARGV[1];
my $LDS_PATH                    = $ARGV[2];
my $BUILD_FOLDER                = $ARGV[3];
my $FEATURE_CONFIG_H            = $ARGV[3] . "/custom_FeatureConfig.h";
my $MAKE_FILE                   = $ARGV[4];
my $INTERMEDIATE_FILE           = $ARGV[5];  #build/.../tmp/~ModemReservedSize_AutoConfig.tmp 
my $LOG_PATH                    = $ARGV[6];
my $INFOMAKE_PATH               = $ARGV[7];
my $COPRO_INFO_PATH             = $ARGV[8];
my $PROJECT_NAME                = basename($MAKE_FILE);

print "Input:\n$ARGV[0]\n$ARGV[1]\n$ARGV[2]\n$ARGV[3]\n$ARGV[4]\n$ARGV[5]\n$ARGV[6]\n$ARGV[7]\n$ARGV[8]\n";

#****************************************************************************
# Global Variables
#****************************************************************************
my %MAKEFILE_OPTIONS;
my %CmplOption;
my %RelOption;
my $g_bAutoConfig = 0;
my $ERR_CODE;
my $g_nExpectedROMSize = undef;
my $g_nExpectedRAMSize = undef;
my $g_nExpectedVRAMBase = undef;
my $g_nCOPRO_TOTAL_USAGE = 0;
my $g_strMsg;
#****************************************************************************
# >>>  Check if it's able to adjust
#****************************************************************************
# Combine Copro_info into MakeFile Option, and then it can be queried by FileInfo.
my $strCoproInfo = CommonUtil::GetFileContent($COPRO_INFO_PATH);
CommonUtil::HashStringParser($strCoproInfo, \%MAKEFILE_OPTIONS) if($strCoproInfo ne "");
my $bEnableAutoConfig = 
    IsEnabledAutoConfig($MAKE_FILE, \%MAKEFILE_OPTIONS, $INFOMAKE_PATH, \%CmplOption, \%RelOption);

# necessarily to set g_nCOPRO_TOTAL_USAGE because BasicInfo will reparse make file again
$g_nCOPRO_TOTAL_USAGE = FileInfo::get(FileInfo::COPRO_TOTAL_USAGE) if(FileInfo::is_BuiltWithCopro()); 

my $bHasHistory = sysUtil::HasCheckinHistory($LDS_PATH);
my $g_bb = sysUtil::SwitchToClonedChip(FileInfo::GetChip());
my $g_bSupportedToAdjustLoadView = sysUtil::isSupportedToAdjustLoadView($g_bb);
my $g_bSupportedToAdjustRAMSize = sysUtil::isSupportedToAdjustRAMSize($g_bb);
my $bSupportedCompiler = (FileInfo::GetCompiler() eq "GCC");
my $bTCMOnlyLoad = FileInfo::is("TCM_ONLY_LOAD", "TRUE");
$g_bAutoConfig = ($bEnableAutoConfig 
             and (defined $bHasHistory and $bHasHistory == 0)
             and ($g_bSupportedToAdjustLoadView or $g_bSupportedToAdjustRAMSize) 
             and $bSupportedCompiler
             and !$bTCMOnlyLoad);

print "-----------------------------------------------------------------\n";
print "Check if it's able to adjust($g_bAutoConfig):\n";
print "bEnableAutoConfig      = $bEnableAutoConfig\n";
print "bHasHistory            = $bHasHistory\n";
print "SupportedMDAutoConfig  = (LoadView=$g_bSupportedToAdjustLoadView or RamSize=$g_bSupportedToAdjustRAMSize)\n";
print "bSupportedCompiler     = $bSupportedCompiler\n";
print "bTCMOnlyLoad           = $bTCMOnlyLoad\n";
my $strPrompt = (!$g_bAutoConfig) ? "disabled" : "enabled";
PrintLog("AutoConfig is $strPrompt\n");
#****************************************************************************
# >>>  Main Flow
#****************************************************************************
if($bTCMOnlyLoad)
{
    print " TCM ONLY load, disable AAPMC adjustment and load size checking.\n";
    exit ERR::NO_MODIFY;
}

if(!$g_bAutoConfig) # not able to config
{
    if(!$bSupportedCompiler)
    {
        print "Unsupported Compiler: ".FileInfo::GetCompiler()."\n";
        $ERR_CODE = ERR::CANNOT_ADJUST;
    }
    else
    {
        $ERR_CODE = CheckLoadViewSize($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, $INTERMEDIATE_FILE);
    }
}
else
{
    $ERR_CODE = AutoAdjust($g_bb, $MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH);
}

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
PrintLog("-----------------------------------------------------------------\n");
PrintLog("RESULT = ". ERR::QueryErrMeaning($ERR_CODE)."\n");
CommonUtil::WriteFileContent($INTERMEDIATE_FILE, $g_strMsg);
exit $ERR_CODE;


sub AutoAdjust
{
    my ($bb, $MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH)= @_;
    # 1. ROM(LoadViewSize)
    my $nLoadViewSize = BasicMemInfo::CMD_GetROMSize($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);#\&PrintLog

    my $strCopro;
    $strCopro = "arm7" if(FileInfo::is_BuiltWithCopro());
    $g_nExpectedROMSize = BasicMemInfo::GetMBAlignment($nLoadViewSize, sysUtil::GetCopro_KBAlignment($strCopro)/1024); 
    
    # 1.5 Copro
    $g_nExpectedVRAMBase = $g_nExpectedROMSize;
    $g_nExpectedVRAMBase += $g_nCOPRO_TOTAL_USAGE if(FileInfo::is_BuiltWithCopro());
    $g_nExpectedVRAMBase = BasicMemInfo::GetMBAlignment($g_nExpectedVRAMBase, sysUtil::GetMDLV_AlignmentByChip(FileInfo::GetChip())); 
    
    # 2. RAM Size # reserved margin at least 0.5MB
    my ($nRAMUsage, $nRAMMargin, $nReservedSize) = BasicMemInfo::CMD_GetRAMUsage($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    my $nReservedMargin = 0.5*1024*1024;
    $nReservedMargin = 0 if($bb eq "MT6290_COPRO");
    $g_nExpectedRAMSize = GetExpectedRAMSize($g_nExpectedVRAMBase, $nRAMUsage + $nReservedSize, $nReservedMargin);
    
    # 3. Get LDS ROM Length and RAM Length, and the 1stRegion Base in RAM
    my $nROM_Length = hex(sysInfo::GetMemoryInfo("ROM", 2, $LDS_PATH));
    my $nRAM_Length = hex(sysInfo::GetMemoryInfo("RAM", 2, $LDS_PATH));
    my $ERsInRAM_aref = BasicMemInfo::GetERsInRAM($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    my $n1stERInRAMVMA = hex(&LinkerOutputParser::GetExeRegionInfo($ERsInRAM_aref->[0], Region::VMA));
    my $nMB = ($g_nExpectedVRAMBase+$g_nExpectedRAMSize)/(1024*1024);
    
    PrintLog("----------------------------Auto Adjust--------------------------\n");
    PrintLog("Actual ROM(Load View) Size = ". CommonUtil::Dec2Hex($nLoadViewSize)."\n");
    PrintLog("current ROM Length in LDS= ". CommonUtil::Dec2Hex($nROM_Length)."\n");
    PrintLog("current RAM Origin in LDS = ". sysInfo::GetMemoryInfo("RAM", 1, $LDS_PATH). "\n");
    PrintLog("current RAM Length in LDS= ". CommonUtil::Dec2Hex($nRAM_Length)."\n");
    PrintLog("current 1stER in ram = ".$ERsInRAM_aref->[0].", VMA=". CommonUtil::Dec2Hex($n1stERInRAMVMA)."\n");
    PrintLog("current RAM Usage = ".CommonUtil::Dec2Hex($nRAMUsage)."\n");
    PrintLog("current RAM Reserved Sizes = ".CommonUtil::Dec2Hex($nReservedSize)."\n");
    PrintLog("current RAM Margin = ".CommonUtil::Dec2Hex($nRAMMargin)."\n");
    PrintLog("current at least Margin setting = ".CommonUtil::Dec2Hex($nReservedMargin)."\n");
    PrintLog("current CORPO Reserved Size = ". CommonUtil::Dec2Hex($g_nCOPRO_TOTAL_USAGE) ."\n")
                                                if(FileInfo::is_BuiltWithCopro());
    PrintLog("expected ROM Sizes = ". CommonUtil::Dec2Hex($g_nExpectedROMSize)."\n");
    PrintLog("expected VRAM Base = ". CommonUtil::Dec2Hex($g_nExpectedVRAMBase)."\n");
    PrintLog("expected RAM Sizes = ". CommonUtil::Dec2Hex($g_nExpectedRAMSize)."\n");
    PrintLog("expected MD Sizes to be ". sysUtil::GetMD_AlignmentByChip($g_bb) ."MB aligned:\n");
    PrintLog("expected MD_LV Sizes to be ". sysUtil::GetMDLV_AlignmentByChip($g_bb) ."MB aligned:\n");
    PrintLog("expected MD Sizes(ROM+RAM) = ". CommonUtil::Dec2Hex($g_nExpectedVRAMBase+$g_nExpectedRAMSize)." = $nMB MB \n");
    PrintLog("-----------------------------------------------------------------\n");
    
    my $err;
    if(($g_bSupportedToAdjustLoadView and (($nLoadViewSize > $nROM_Length) or ($n1stERInRAMVMA != $g_nExpectedVRAMBase))) 
    or ($g_bSupportedToAdjustRAMSize  and ($g_nExpectedRAMSize != $nRAM_Length) )) # RAM size is RAM BASE+LEN
    {
        my $strFilePath = PrepareFileToModify();
        ModifyMEMORY($strFilePath);
        $err = ERR::AUTOCONFIG_SELF_MODIFY_SUCCESS;
        RecommendDuringAutoAdjust($err, $nLoadViewSize, $nROM_Length, 
                                 $n1stERInRAMVMA, $ERsInRAM_aref->[0], $nRAM_Length, ($nRAMUsage + $nReservedSize));
    }
    else
    {
        $err = ERR::NO_NEED_TO_UPDATE;
        $err = RecommendDuringAutoAdjust($err, $nLoadViewSize, $nROM_Length, 
                                 $n1stERInRAMVMA, $ERsInRAM_aref->[0], $nRAM_Length, ($nRAMUsage + $nReservedSize));
    }
    return $err;
}

sub RecommendDuringAutoAdjust
{
    my ($err, $nLoadViewSize, $nROM_Length, $n1stERInRAMVMA, $ER1st, $nRAM_Length, $nRAMTotalUsage) = @_;
    if($nLoadViewSize > $nROM_Length)
    {
        if(!$g_bSupportedToAdjustLoadView)
        {
            PrintLog("Actual ROM(Load View) Size > ROM Length in LDS\n");
            PrintLog("[Recommend] Setting ROM Length to " . CommonUtil::Dec2Hex($g_nExpectedROMSize)."\n");
        }
        $err = ERR::CANNOT_ADJUST;
    }
    if($n1stERInRAMVMA != $nLoadViewSize)
    {
        if(!$g_bSupportedToAdjustLoadView)
        {
            PrintLog("[Recommend] Setting the base address of $ER1st to ".CommonUtil::Dec2Hex($g_nExpectedROMSize)."\n");
        }
        $err = ERR::CANNOT_ADJUST if($n1stERInRAMVMA < $nLoadViewSize);
    }
    if($g_nExpectedRAMSize != $nRAM_Length)
    {
        if(!$g_bSupportedToAdjustRAMSize)
        {
            PrintLog("[Recommend] Setting RAM Length to " . CommonUtil::Dec2Hex($g_nExpectedRAMSize)."\n");
        }
        $err = ERR::CANNOT_ADJUST if($nRAM_Length < $nRAMTotalUsage);
    }
    return $err;
}

sub PrepareFileToModify
{
    ldsFrame::CleanCallBackFunc();
    my $strDefaultMEMORYPath = ldsFrame::GetPath($g_bb, ldsFrame::MEMORY);
    my $strFilePath = $strDefaultMEMORYPath;
    if($strDefaultMEMORYPath =~ /custom\/system\/(.+)/i)
    {
        my $strTemp = $1;
        $BUILD_FOLDER .= "/" if($BUILD_FOLDER !~ /\/$/);
        $strFilePath = $BUILD_FOLDER . $strTemp;
        if(!-e $strFilePath)
        {
            my $DIR = dirname($strFilePath);
            mkpath($DIR) if(!-f $DIR);
            print "[PrepareFileToModify]copy $strDefaultMEMORYPath \nto $strFilePath\n";
            copy($strDefaultMEMORYPath, $strFilePath) or config_die("Copy Fail!");
            # chmod for read-only codebase
            chmod(0640, $strFilePath) if($^O eq "MSWin32");
        }
    }
    return $strFilePath;
}
sub ModifyMEMORY
{
    my ($strFilePath) = @_;
    &ldsFrame::CleanCallBackFunc();
    &ldsFrame::SetCallBackFunc("GetChip", \&GetChip);
    &ldsFrame::SetCallBackFunc("SetMemorySegment", \&SetMemorySegment);
    &ldsFrame::SetCallBackFunc("GetCustomFolder", \&GetCustomFolder);
    my $strContent = ldsFrame::GenMEMORY(ldsFrame::MAIN);
    CommonUtil::WriteFileContent($strFilePath, $strContent);
    print "Generate $strFilePath successfully!\n";
}
sub GetCustomFolder  #ldsFrame's callback func
{
    return $BUILD_FOLDER;
}
sub GetChip  # ldsFrame's callback func
{
    return $g_bb;
}

sub GetExpectedRAMSize
{
    my ($nLVMBAlignedSize, $nRAMSize, $nReservedSize) = @_;
    my $nOrgSize = $nLVMBAlignedSize + $nRAMSize;
    my $nExpectedRamSize = BasicMemInfo::GetMBAlignment($nOrgSize, sysUtil::GetMD_AlignmentByChip($g_bb));
    if(($nExpectedRamSize - $nOrgSize) < $nReservedSize)
    {
        $nExpectedRamSize = BasicMemInfo::GetMBAlignment($nOrgSize+$nReservedSize, sysUtil::GetMD_AlignmentByChip($g_bb));
    }
    return $nExpectedRamSize - $nLVMBAlignedSize;
}

sub SetMemorySegment # ldsFrame's callback func
{
    my ($MEMORY_SEGMENT_aref) = @_;
    my $nIndex = 0;
    my $NCPrefix = sysUtil::GetNonCacheablePrefix($g_bb);
    my $CPrefix = sysUtil::GetCacheablePrefix($g_bb);
    foreach my $i (@$MEMORY_SEGMENT_aref)
    {
        my $strName = $i->[0];
        if($strName eq "ROM")
        {
            if($g_bSupportedToAdjustLoadView)
            {
                $MEMORY_SEGMENT_aref->[$nIndex]->[2] = CommonUtil::Dec2Hex($g_nExpectedROMSize);
                PrintLog("Modify ROM Length = ".CommonUtil::Dec2Hex($g_nExpectedROMSize)."\n");
            }
        }
        else
        {
            if($NCPrefix == 0)
            {
                if($strName eq "RAM" and $g_bSupportedToAdjustLoadView)
                {
                    $MEMORY_SEGMENT_aref->[$nIndex]->[1] = CommonUtil::Dec2Hex($g_nExpectedVRAMBase);
                    PrintLog("Modify RAM ORIGIN = ".CommonUtil::Dec2Hex($g_nExpectedVRAMBase)."\n");
                }    
            }
            elsif($CPrefix == 0)
            {#on MOLY
                if($strName eq "VRAM" and $g_bSupportedToAdjustLoadView)
                {
                    $MEMORY_SEGMENT_aref->[$nIndex]->[1] = CommonUtil::Dec2Hex($g_nExpectedVRAMBase);
                    PrintLog("Modify VRAM ORIGIN = ".CommonUtil::Dec2Hex($g_nExpectedVRAMBase)."\n");
                }
            }
            if($strName eq "RAM" and $g_bSupportedToAdjustRAMSize)
            {
                $MEMORY_SEGMENT_aref->[$nIndex]->[2] = CommonUtil::Dec2Hex($g_nExpectedRAMSize);
                PrintLog("Modify RAM Length = ".CommonUtil::Dec2Hex($g_nExpectedRAMSize)."\n");
            }
            if($strName eq "COPRO_SPACE")
            {
                $MEMORY_SEGMENT_aref->[$nIndex]->[2] = CommonUtil::Dec2Hex($g_nCOPRO_TOTAL_USAGE);
                PrintLog("Modify COPRO_RESERVED_LEN= ".CommonUtil::Dec2Hex($g_nCOPRO_TOTAL_USAGE)."\n");
            }
        }
        $nIndex++;
    }
}

sub ShowBasicInfo
{
    my ($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, $INTERMEDIATE_FILE, $nExpectedROMSize)= @_;
    my ($nRAMUsage, $nRAMMargin, $nReservedSize) = BasicMemInfo::CMD_GetRAMUsage($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    my $nExpectedRAMSize = BasicMemInfo::GetMBAlignment($nRAMUsage+$nReservedSize, 1);
    my $nMB = ($nExpectedROMSize + $nExpectedRAMSize)/(1024*1024);
    PrintLog("-----------------Current BasicInfo for reference-----------------\n");
    PrintLog("current RAM Usage = ".CommonUtil::Dec2Hex($nRAMUsage)."\n");
    PrintLog("current RAM Reserved Sizes = ".CommonUtil::Dec2Hex($nReservedSize)."\n");
    PrintLog("current RAM Margin = ".CommonUtil::Dec2Hex($nRAMMargin)."\n");
    PrintLog("After alignment adjusting:\n");
    PrintLog("ROM Sizes = ". CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
    PrintLog("RAM Sizes (RAM Usage + Reserved Sizes) = ". CommonUtil::Dec2Hex($nExpectedRAMSize)."\n");
    PrintLog("Actual MD Usage(ROM+RAM) = ". CommonUtil::Dec2Hex($nExpectedROMSize+$nExpectedRAMSize)." = $nMB MB \n");
    PrintLog("-----------------------------------------------------------------\n");
}

sub CheckLoadViewSize
{
    my ($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, $INTERMEDIATE_FILE)= @_;
    my $err;
    #Check LoadView size with ROM Length and 1st RAM Base
    # 1. ROM(LoadViewSize)
    my $nActualROMSize = BasicMemInfo::CMD_GetROMSize($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    #my $nExpectedROMSize = BasicMemInfo::GetMBAlignment($nActualROMSize, 1);
    
    my $strCopro;
    $strCopro = "arm7" if(FileInfo::is_BuiltWithCopro());
    $nActualROMSize = BasicMemInfo::GetMBAlignment($nActualROMSize, sysUtil::GetCopro_KBAlignment($strCopro)/1024); 
    
    # 1.5 Copro
    my $nExpectedROMSize = $nActualROMSize;
    $nActualROMSize += $g_nCOPRO_TOTAL_USAGE if(FileInfo::is_BuiltWithCopro());
    $nExpectedROMSize = BasicMemInfo::GetMBAlignment($nActualROMSize, sysUtil::GetMDLV_AlignmentByChip(FileInfo::GetChip())); 
    
    # 2. ROM of MEMORY in LDS
    my $nROM_Length = hex(sysInfo::GetMemoryInfo("ROM", 2, $LDS_PATH));
    # 3. VMA of 1st Region in RAM
    my $ERsInRAM_aref = BasicMemInfo::GetERsInRAM($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, undef);
    my $n1stERInRAMVMA = 0x0FFFFFFF & hex(&LinkerOutputParser::GetExeRegionInfo($ERsInRAM_aref->[0], Region::VMA));
    
    PrintLog("-------------------------Check Load View------------------------\n");
    PrintLog("Actual ROM(Load View) Size = ". CommonUtil::Dec2Hex($nActualROMSize)."\n");
    PrintLog("current ROM Length in LDS= ". CommonUtil::Dec2Hex($nROM_Length)."\n");
    PrintLog("current RAM Origin in LDS = ". sysInfo::GetMemoryInfo("RAM", 1, $LDS_PATH). "\n");
    PrintLog("current 1st ER in ram = ".$ERsInRAM_aref->[0].", VMA=". CommonUtil::Dec2Hex($n1stERInRAMVMA)."\n");
    PrintLog("-----------------------------------------------------------------\n");
    ShowBasicInfo($MAKE_FILE, $LDS_PATH, $MAP_PATH, $SYM_PATH, $INTERMEDIATE_FILE, $nExpectedROMSize);
    #-----------------------------------------------------
    if(($nActualROMSize > $nROM_Length) or ($nActualROMSize > $n1stERInRAMVMA))
    {
        if($nActualROMSize > $nROM_Length)
        {
            PrintLog("Actual ROM(Load View) Size > ROM Length in LDS\n");
            PrintLog("[Recommend] Setting ROM Length to " . CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
        }
        if($nActualROMSize > $n1stERInRAMVMA)
        {
            PrintLog("Actual ROM(Load View) Size > 1st VMA in RAM\n");
            PrintLog("[Recommend] Setting the base address of " . $ERsInRAM_aref->[0] . 
                        " to " . CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
        }
        $err = ERR::ERR_LOADVIEWSIZE_INSUFFICIENT;
    }
    else
    {
        if($n1stERInRAMVMA != $nExpectedROMSize)
        {
            PrintLog("[Recommend] Setting the base address of " . $ERsInRAM_aref->[0] . 
                    " to " . CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
        }
        if($nROM_Length < $nExpectedROMSize)
        {
            PrintLog("[Recommend] Setting ROM Length to " . CommonUtil::Dec2Hex($nExpectedROMSize)."\n");
        }
        if(!(($nROM_Length < $nExpectedROMSize) or ($n1stERInRAMVMA != $nExpectedROMSize)))
        {
            PrintLog("[Load View Analysis] PASS \n");
        }
        PrintLog("-----------------------------------------------------------------\n");
        $err = IsPrvLinkedPASS($INTERMEDIATE_FILE) ? ERR::NO_MODIFY : ERR::CANNOT_ADJUST;
        ($err == ERR::NO_MODIFY) ? PrintLog("Previous Linkage: PASS\n") : PrintLog("Previous Linkage: FAIL\n");
    }
    return $err;
}

sub PrintLog
{
    my ($strContent) = @_;
    print $strContent;
    $g_strMsg .= $strContent;
}

sub IsEnabledAutoConfig
{
    my ($MK_PATH, $mk_option_href, $INFOMAKELOG, $CmplOption_href, $RelOption_href) = @_; 
    if(!&FileInfo::PreProcess($MK_PATH, $mk_option_href, $INFOMAKELOG, $CmplOption_href, $RelOption_href))
    {
        print "MakeFile/Infomake.log Parse Error: ERR_UNEXPECTED\n";
        exit ERR::ERR_UNEXPECTED;
    }
    my $bEnable = FileInfo::is("ModemReservedSize_AutoConfig", "TRUE");
    return $bEnable;
}

sub IsPrvLinkedPASS
{
    my ($INTERMEDIATE_FILE) = @_;
    my $strContent = CommonUtil::GetFileContent($INTERMEDIATE_FILE);
    return $strContent eq ""; # equal "" = PASS, having contents = FAIL
}

#****************************************************************************
# subroutine:  config_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub config_die
{
    my ($error_msg) = @_;
    my ($pack_name, $file, $line_no) = caller;
    &AUTO_ADJUST::error_handler($error_msg, $file, $line_no, 'ModemReservedSize_Config');
}
