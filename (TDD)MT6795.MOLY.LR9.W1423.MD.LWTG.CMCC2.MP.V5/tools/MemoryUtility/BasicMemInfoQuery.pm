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
#*   BasicInfoQuery.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This perl module is used to get system basic information
#*       
#*
#* Author:
#* -------
#*   Qmei Yang (mtk03726)
#*
#****************************************************************************/

BEGIN { push @INC, '../', './tools/', './tools/MemoryUtility/' }  # add additional library path
use systemInfo;
use LinkerOutputParser;
use FileInfoParser;

use strict;

package FILEOPTION;
use constant LIS         => 1;
use constant MAP         => 2;
use constant SYM         => 3;
use constant MAKEFILE    => 4;
use constant INFOMAKE    => 5;

package BasicMemInfo;
use POSIX qw(floor ceil);
#****************************************************************************
# Constants
#****************************************************************************
my $VERNO     = " m0.06";
             # m0.06 , 2014/02/20,  Correct GetTotalRAMUsageFromLDS's base address
             # m0.05 , 2013/12/25,  Fix LoadView which can't count in .bss
             # m0.04 , 2013/10/20,  Support Secure region
             # m0.03 , 2013/06/25,  Support CMD_GetROMSize() for filtering out COPRO section
             # m0.02 , 2013/03/21,  Support GetMBAlignment()
             # m0.01 , 2013/01/08,  Initial revision

#****************************************************************************
# Global variable
#****************************************************************************
my $DebugPrint = 0;
my $g_bParseSYM = 0;
my $g_bParseMAP = 0;
my $g_bParseLIS = 0;
my $g_bParseMAKEFILE = 0;
my %g_MAKEFILE_OPTIONS;

#****************************************************************************
# Subroutine:  BasicInfoQuery_verno - to query this package's version number
# Parameters:  x
# Returns:     version number string
#****************************************************************************
sub BasicInfoQuery_verno
{
    return $VERNO;
}

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

sub DispatchCommand
{
    my ($cmd, $MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my $bRunCommand = 0;
    $cmd = "help" if($cmd eq "-h" or $cmd eq "--help");
    no strict 'refs';
    &{$cmd}($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH, $PrintFunc) if (exists &{$cmd})
        or basicinfo_die("$cmd() doesn't exists!", __FILE__, __LINE__);
}

sub CMD_GetLoadViewSize
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    Parse(FILEOPTION::SYM, $SYM_PATH);
    Parse(FILEOPTION::MAKEFILE, $MAKEFILE_PATH);
    my $ERs_aref = &LinkerOutputParser::ListAllExeRegion(1);
#    $ERs_aref = sysInfo::FilterOutCoproReservedRegion($ERs_aref); #if(FileInfo::is_BuiltWithCopro());
    my $nCount = scalar(@$ERs_aref);
    my $strLastRegion = $ERs_aref->[$nCount-1];
    my $nLoadViewSize = hex(&LinkerOutputParser::GetExeRegionInfo($strLastRegion, Region::LMA));
    PrintLog($PrintFunc, "ROM Information:\n");
    my $strROM_Base = sysInfo::GetMemoryInfo("ROM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    my $strROM_Length = sysInfo::GetMemoryInfo("ROM", 2, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    PrintLog($PrintFunc, "ROM Base Address in LDS = $strROM_Base\n");
    PrintLog($PrintFunc, "ROM Length in LDS = $strROM_Length\n");
    PrintLog($PrintFunc, "Last Region in sym = $strLastRegion\n");
    PrintLog($PrintFunc, "Last Region LMA in sym = ". CommonUtil::Dec2Hex($nLoadViewSize) . " = $nLoadViewSize(Bytes) \n");
    
    if($strLastRegion !~/zi|bss/i)
    {
        my $nLastRegionSize = hex(&LinkerOutputParser::GetExeRegionInfo($strLastRegion, Region::Size));
        PrintLog($PrintFunc, "Last Region Size in sym = ". CommonUtil::Dec2Hex($nLastRegionSize) . " = $nLastRegionSize(Bytes) \n");        
        $nLoadViewSize += $nLastRegionSize;
    }
    PrintLog($PrintFunc, "-------------------------------------------------------------------\n");
    PrintLog($PrintFunc, "Total ROM Size (Code + RO Data + RW Data) = ". CommonUtil::Dec2Hex($nLoadViewSize) . " = $nLoadViewSize(Bytes) \n");
    return $nLoadViewSize;
}

sub CMD_GetROMSize
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH) = @_;
    Parse(FILEOPTION::SYM, $SYM_PATH);
    Parse(FILEOPTION::MAKEFILE, $MAKEFILE_PATH);
    my $ERs_aref = &LinkerOutputParser::ListAllExeRegion(1);
    $ERs_aref = sysInfo::FilterOutCoproReservedRegion($ERs_aref); 
    $ERs_aref = sysInfo::FilterOutSecureRegion($ERs_aref) if(FileInfo::is_BuiltWithCopro());; 
    my $nCount = scalar(@$ERs_aref);
    my $strLastRegion = $ERs_aref->[$nCount-1];
    my $nLoadViewSize = hex(&LinkerOutputParser::GetExeRegionInfo($strLastRegion, Region::LMA));
   
    if($strLastRegion !~/zi|bss/i)
    {
        my $nLastRegionSize = hex(&LinkerOutputParser::GetExeRegionInfo($strLastRegion, Region::Size));
        $nLoadViewSize += $nLastRegionSize;
    }
    return $nLoadViewSize;
}

sub CMD_GetRAMUsage
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    Parse(FILEOPTION::MAKEFILE, $MAKEFILE_PATH);
    my $ERinRAM_aref = GetERsInRAM($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH, $PrintFunc);
    my ($nRAMUsage, $nRAMMargin, $nReservedSize) = (0, 0, 0);
    if(scalar(@$ERinRAM_aref)>0)
    {
        my $nDummyEndBase = hex(&LinkerOutputParser::Get_DUMMY_END_Base());
        my $ER = GetERBeforeDUMMYEND($ERinRAM_aref, $nDummyEndBase, $SYM_PATH);
        my $nEndRegionVMA =  hex(&LinkerOutputParser::GetExeRegionInfo($ER, Region::VMA));
        my $nEndRegionSize = hex(&LinkerOutputParser::GetExeRegionInfo($ER, Region::Size));
        my $nFirstERInRAMVMA = hex(&LinkerOutputParser::GetExeRegionInfo($ERinRAM_aref->[0], Region::VMA));
        $nRAMUsage = (0x0FFFFFFF & $nEndRegionVMA) + $nEndRegionSize - (0x0FFFFFFF & $nFirstERInRAMVMA);
        $nRAMMargin = $nDummyEndBase - ($nEndRegionVMA + $nEndRegionSize);
        
        $nReservedSize = GetReservedSize($IMAGELAYOUT_PATH, $SYM_PATH, $MAKEFILE_PATH);
        PrintLog($PrintFunc, "RAM Information:\n");
        my $strRAM_Base = sysInfo::GetMemoryInfo("RAM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
        my $strVRAM_Base = sysInfo::GetMemoryInfo("VRAM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
        my $strRAM_Length = sysInfo::GetMemoryInfo("RAM", 2, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
        PrintLog($PrintFunc, "RAM Base Address in LDS = $strRAM_Base\n");
        PrintLog($PrintFunc, "VRAM Base Address in LDS = $strVRAM_Base\n");
        PrintLog($PrintFunc, "RAM Length in LDS = $strRAM_Length\n");
        PrintLog($PrintFunc, "1st Region in RAM: ".$ERinRAM_aref->[0].", VMA=".CommonUtil::Dec2Hex($nFirstERInRAMVMA)."\n");
        PrintLog($PrintFunc, "RegionBeforeDummyEnd: $ER, VMA=".CommonUtil::Dec2Hex($nEndRegionVMA).",Size=".CommonUtil::Dec2Hex($nEndRegionSize)."\n");
        PrintLog($PrintFunc, "DummyEndBase = ".CommonUtil::Dec2Hex($nDummyEndBase)."\n");
        PrintLog($PrintFunc, "-------------------------------------------------------------------\n");
        PrintLog($PrintFunc, "RAM Usage = ".CommonUtil::Dec2Hex($nRAMUsage)." = $nRAMUsage(Bytes)\n");
        PrintLog($PrintFunc, "RAM Margin = ".CommonUtil::Dec2Hex($nRAMMargin)." = $nRAMMargin(Bytes)\n");
        PrintLog($PrintFunc, "RAM ReservedSize = ".CommonUtil::Dec2Hex($nReservedSize)." = $nReservedSize(Bytes)\n");
        PrintLog($PrintFunc, "-------------------------------------------------------------------\n");
        PrintLog($PrintFunc, "Total RAM Size (RW + ZI Data + Reserved Size) = ". CommonUtil::Dec2Hex($nRAMUsage+$nReservedSize) 
                                                                                   . " = ". ($nRAMUsage+$nReservedSize)."(Bytes) \n");
    }
    return ($nRAMUsage, $nRAMMargin, $nReservedSize);
}

sub GetERsInRAM
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    Parse(FILEOPTION::SYM, $SYM_PATH);
    my $ERs_aref = &LinkerOutputParser::ListAllExeRegion(1);
    Parse(FILEOPTION::MAKEFILE, $MAKEFILE_PATH);
    my $ERinRAM_aref = &sysInfo::FilterOutRegionInRAM($ERs_aref, \%g_MAKEFILE_OPTIONS);
    return $ERinRAM_aref;
}

sub GetExpectedLoadViewSize
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my $nActualROMSize = CMD_GetLoadViewSize($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH, $PrintFunc);
    PrintLog($PrintFunc, "ActualROMSize = ".CommonUtil::Dec2Hex($nActualROMSize)." = $nActualROMSize(Bytes)\n");
    my $nExpectedROMSize = GetMBAlignment($nActualROMSize, 1);
    PrintLog($PrintFunc, "ExpectedROMSize = ".CommonUtil::Dec2Hex($nExpectedROMSize)." = $nExpectedROMSize(Bytes)\n");
    return $nExpectedROMSize;
}

sub GetExpectedRAMSize
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH, $PrintFunc, $nReservedMarginSize) = @_;
    my ($nRAMUsage, $nRAMMargin, $nReservedSize) = 
                    CMD_GetRAMUsage($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH, $PrintFunc);
    my $nActualRAMSize = $nRAMUsage+$nReservedSize;
    PrintLog($PrintFunc, "ActualRAMSize = ".CommonUtil::Dec2Hex($nActualRAMSize)." = $nActualRAMSize(Bytes)\n");
    my $nExpectedRAMSize = GetMBAlignment($nActualRAMSize, 1);
    if($nReservedMarginSize > 0)
    {
        $nExpectedRAMSize += $nReservedMarginSize if(($nExpectedRAMSize - $nActualRAMSize) < $nReservedMarginSize);
        $nExpectedRAMSize = GetMBAlignment($nExpectedRAMSize, 1);
    }
    PrintLog($PrintFunc, "ExpectedRAMSize = ".CommonUtil::Dec2Hex($nExpectedRAMSize)." = $nExpectedRAMSize(Bytes)\n");
    PrintLog($PrintFunc, "ExpectedMargin = ".CommonUtil::Dec2Hex($nExpectedRAMSize - $nActualRAMSize)." = ".
                                                                ($nExpectedRAMSize - $nActualRAMSize)."(Bytes)\n");
    return $nExpectedRAMSize;
}

sub GetTotalRAMUsageFromLDS
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    Parse(FILEOPTION::MAKEFILE, $MAKEFILE_PATH);
    my $strRAM_Base = sysInfo::GetMemoryInfo("RAM", 1, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    my $strRAM_Length = sysInfo::GetMemoryInfo("RAM", 2, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
    return (hex($strRAM_Base)&0x0FFFFFFF) + hex($strRAM_Length);
}

sub CMD_GetPhysicalRAMUsage
{
    my ($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH, $PrintFunc) = @_;
    my $nExepectedLoadViewSize = GetExpectedLoadViewSize($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH, undef);
    my $nExpectedRAMSize = GetExpectedRAMSize($MAKEFILE_PATH, $IMAGELAYOUT_PATH, $LISorMAP_PATH, $SYM_PATH, undef, 0);
    my $nPRAMUsage = $nExepectedLoadViewSize + $nExpectedRAMSize;
    PrintLog($PrintFunc, "Total Physical RAMUsage(ROM + RAM) = ".CommonUtil::Dec2Hex($nPRAMUsage)." = $nPRAMUsage(Bytes)\n");
    return $nPRAMUsage ;
}

sub GetMBAlignment
{
    my ($nSize, $nMBAligned) = @_;
    return ceil($nSize/($nMBAligned*1024*1024)) *$nMBAligned*1024*1024;
}
sub GetERBeforeDUMMYEND
{
    my ($ERinRAM_aref, $DUMMY_END_Base_withoutBANK, $SYM_PATH) = @_;
    Parse(FILEOPTION::SYM, $SYM_PATH);
    my $ER_Before_DUMMYEND;
    my $FixedER_aref = sysInfo::FilterOutFixedRegion($ERinRAM_aref, \%g_MAKEFILE_OPTIONS);
    my $FirstFixedER = "";
    $FirstFixedER = $FixedER_aref->[0] if(scalar(@$FixedER_aref) != 0);
    foreach my $ER (@$ERinRAM_aref)
    {
        if($ER ne $FirstFixedER)
        {
            $ER_Before_DUMMYEND = $ER;
        }
        else
        {
            last;    
        }
    }
    return $ER_Before_DUMMYEND;
}

sub GetReservedSize
{
    my ($IMAGELAYOUT_PATH, $SYM_PATH, $MAKEFILE_PATH) = @_;
    Parse(FILEOPTION::MAKEFILE, $MAKEFILE_PATH);
    my @ERinRAM;
    use File::Basename;
    my $BB_PATH = dirname($IMAGELAYOUT_PATH);
    sysInfo::GetRAMregion($BB_PATH, $IMAGELAYOUT_PATH, \@ERinRAM, \%g_MAKEFILE_OPTIONS);
    my $FixedER_aref = &sysInfo::FilterOutFixedRegion(\@ERinRAM, \%g_MAKEFILE_OPTIONS);
    my $nReservedSize = 0;
    foreach my $ER (@$FixedER_aref)
    {
        my $strSize = sysInfo::GetRegionInfo($ER, Region::MaxSize, $IMAGELAYOUT_PATH, \%g_MAKEFILE_OPTIONS);
        $nReservedSize += hex($strSize);
    }
    return $nReservedSize;
}


sub Parse
{
    my ($nOption, $PATH) = @_;
    if($nOption == FILEOPTION::LIS and !$g_bParseLIS)
    {
        basicinfo_die("$PATH doesn't exist!") if(!-e $PATH);
        &LinkerOutputParser::FileParse($PATH);
        $g_bParseLIS = 1;
    }
    elsif($nOption == FILEOPTION::MAP and !$g_bParseMAP)
    {
        basicinfo_die("$PATH doesn't exist!") if(!-e $PATH);
        &LinkerOutputParser::FileParse($PATH);
        $g_bParseMAP = 1;
    }
    elsif($nOption == FILEOPTION::SYM and !$g_bParseSYM)
    {
        basicinfo_die("$PATH doesn't exist!") if(!-e $PATH);
        &LinkerOutputParser::FileParse($PATH);
        $g_bParseSYM = 1;
    }
    elsif($nOption == FILEOPTION::MAKEFILE and !$g_bParseMAKEFILE)
    {
        basicinfo_die("$PATH doesn't exist!") if(!-e $PATH);
        &FileInfo::Parse_MAKEFILE($PATH, \%g_MAKEFILE_OPTIONS);
        $g_bParseMAKEFILE = 1;
    }
}

sub PrintLog
{
    my ($LogFunc, $strLog) = @_;
    &{$LogFunc}($strLog) if(exists &{$LogFunc});
}
#****************************************************************************
# Subroutine:  basicinfo_die
# Parameters:  1. string error message, 2. __FILE__ 3. __LINE__
# Returns:     x
#****************************************************************************
sub basicinfo_die
{
    my ($error_msg, $file, $line_no) = @_;
    my $pack_name = undef;
    if(!defined $file or !defined $line_no)
    {
        ($pack_name, $file, $line_no) = caller;    
    }
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'BasicInfoQuery');    
}
