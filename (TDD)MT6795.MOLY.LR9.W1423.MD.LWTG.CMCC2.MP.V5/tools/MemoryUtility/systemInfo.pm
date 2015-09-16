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
#*   SystemInfo.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This module collects the subroutines for system information. 
#*       
#*
#* Author:
#* -------
#*   Carina Liao (mtk04017)
#*
#****************************************************************************/

BEGIN { push @INC, '../', './tools/', './tools/MemoryUtility/' }
package sysInfo;
use sysInfoProcessScat; #this module is applied to RVCT compiler
use sysInfoProcessLds;  #this module is applied to GCC compiler
use FileInfoParser;
use strict;

#****************************************************************************
# Constants
#****************************************************************************
my $SYSINFO_VERNO     = " m0.05";
             # m0.05 , 2013/10/20,  Support FilterOutSecureRegion()
             # m0.04 , 2013/06/25,  Support FilterOutCoproReservedRegion()
             # m0.03 , 2012/08/03,  Modify the comment of GetTCMmargin()
             # m0.02 , 2012/08/03,  Modify module name and push additional library path
             # m0.01 , 2012/07/05,  Initial revision

#****************************************************************************
# Global variable
#****************************************************************************
my $DebugPrint = 0;

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# Subroutine:  systemInfo_verno - to query this package's version number
# Parameters:  x
# Returns:     version number string
#****************************************************************************
sub systemInfo_verno
{
    return $SYSINFO_VERNO;
}

#****************************************************************************
# Subroutine:  GetChipInsideRAMregion - to query all Chip inside RAM regions
# Parameters:  $strFilePath = the path of file (scatter file or lds file)
#              $INTSRAMregion_href = a Hash reference to store ChipInsideRAM infomation
#              $INTSRAMregion_href->{regionName} = []
#              $MAKEFILE_ref = a Hash to contain MAKEFILE information
# Returns:     $nINTSRAMnum = the number of ChipInsideRAM regions
#****************************************************************************
sub GetChipInsideRAMregion
{
    my ($strFilePath, $INTSRAMregion_href, $MAKEFILE_ref) = (@_);
    print "file path = $strFilePath\n" if($DebugPrint == 1);
    my $strCompiler = &FileInfo::GetCompiler($MAKEFILE_ref);

    my $nINTSRAMnum = 0;
    if($strCompiler eq "RVCT")
    {
        $nINTSRAMnum = &sysInfoProcScat::GetChipInsideRAMregion($strFilePath, $INTSRAMregion_href);
    }
    elsif($strCompiler eq "GCC")
    {
        $nINTSRAMnum = &sysInfoProcLds::GetChipInsideRAMregion($strFilePath, $INTSRAMregion_href);  
    }
    return ($nINTSRAMnum);
}

#****************************************************************************
# Subroutine:  GetChipInsideRAMsize - to query ChipInsideRAM size
# Parameters:  $strFilePath = the path of file (scatter file or lds file)
#              $INTSRAMinfo_href = a Hash reference to store ChipInsideRAM infomation
#              ($INTSRAMinfo_href -> {ChipInsideRAM type} = MaxSize)
#              $MAKEFILE_ref = a Hash to contain MAKEFILE information
# Returns:     $nINTSRAMnum = the number of ChipInsideRAM types
#****************************************************************************
sub GetChipInsideRAMsize
{
    my ($strFilePath, $INTSRAMinfo_href, $MAKEFILE_ref) = (@_);
    print "file path = $strFilePath\n" if($DebugPrint == 1);
    my $strCompiler = &FileInfo::GetCompiler($MAKEFILE_ref);
    
    my $nINTSRAMnum = 0;
    if($strCompiler eq "RVCT")
    {
        $nINTSRAMnum = &sysInfoProcScat::GetChipInsideRAMsize($strFilePath, $INTSRAMinfo_href);
    }
    elsif($strCompiler eq "GCC")
    {
        $nINTSRAMnum = &sysInfoProcLds::GetChipInsideRAMsize($strFilePath, $INTSRAMinfo_href);
    }
    return ($nINTSRAMnum);
}

#****************************************************************************
# Subroutine:  GetTCMmargin - to query TCM margin
# Parameters:  $strFilePath = the path of file (scatter file or lds file)
#              $TCMregion_href = a Hash reference to store TCM infomation
#              $TCMregion_href->{'regionName'} = size
#              $MAKEFILE_ref = a Hash to contain MAKEFILE information
# Returns:     $TCMmargin_href = a Hash reference to store TCM information
#              $TCMmargin_href->{ITCM}->[0] = ITCM physical size, $TCMmargin_href->{ITCM}->[1] = ITCM margin
#              $TCMmargin_href->{DTCM}->[0] = DTCM physical size, $TCMmargin_href->{DTCM}->[1] = DTCM margin
#              $TCMmargin_href->{TCM}->[0]  = TCM physical size , $TCMmargin_href->{TCM}->[1]  = TCM margin
#****************************************************************************
sub GetTCMmargin
{
    my ($strFilePath, $TCMregion_href, $MAKEFILE_ref) = (@_);
    print "file path = $strFilePath\n" if($DebugPrint == 1);
    my $strCompiler = &FileInfo::GetCompiler($MAKEFILE_ref);

    my $TCMmargin_href = undef;
    if($strCompiler eq "RVCT")
    {
        $TCMmargin_href = &sysInfoProcScat::GetTCMmargin($strFilePath, $TCMregion_href);
    }
    elsif($strCompiler eq "GCC")
    {
        $TCMmargin_href = &sysInfoProcLds::GetTCMmargin($strFilePath, $TCMregion_href);
    }
    return ($TCMmargin_href);
}

#****************************************************************************
# Subroutine:  GetphysicalRAMsize - to query physical RAM size
# Parameters:  $BB_PATH = the path of BB folder
#              $MAKEFILE_ref = a Hash to contain MAKEFILE information
# Returns:     $nRAMsize = the physical RAM size
#****************************************************************************
sub GetphysicalRAMsize
{
    my ($BB_PATH, $MAKEFILE_ref) = (@_);
    my $nRAMsize = undef;
    my $strCompiler = &FileInfo::GetCompiler($MAKEFILE_ref);

    if($strCompiler eq "RVCT")
    {
        $nRAMsize = &sysInfoProcScat::GetphysicalRAMsize($BB_PATH);
    }
    elsif($strCompiler eq "GCC")
    {
        $nRAMsize = &sysInfoProcLds::GetphysicalRAMsize($BB_PATH);
    }
    return $nRAMsize;
}

#****************************************************************************
# Subroutine:  GetAvailableRAMsize - to query available RAM size
# Parameters:  $BB_PATH = the path of BB folder
#              $MAKEFILE_ref = a Hash to contain MAKEFILE information
# Returns:     $nRAMsize = the available RAM size
#****************************************************************************
sub GetAvailableRAMsize
{
    my ($BB_PATH, $MAKEFILE_ref) = (@_);
    my $nRAMsize = undef;
    my $strCompiler = &FileInfo::GetCompiler($MAKEFILE_ref);

    if($strCompiler eq "RVCT")
    {
        $nRAMsize = &sysInfoProcScat::GetAvailableRAMsize($BB_PATH);
    }
    elsif($strCompiler eq "GCC")
    {
        $nRAMsize = &sysInfoProcLds::GetAvailableRAMsize($BB_PATH);
    }
    return $nRAMsize;
}

#****************************************************************************
# Subroutine:  GetRAMregion - to query all regions placed in RAM
# Parameters:  $BB_PATH
#              $strFilePath = the path of file (scatter file or lds file)
#              $RAMregion_aref = a Array reference to store RAM regions 
#              $RAMregion_href->{regionName} = []
#              $MAKEFILE_ref = a Hash to contain MAKEFILE information
# Returns:     $nRAMnum = the number of RAM regions
#****************************************************************************
sub GetRAMregion
{
    my ($BB_PATH, $strFilePath, $RAMregion_aref, $MAKEFILE_ref) = @_;
    print "file path = $strFilePath\n" if($DebugPrint == 1);
    my $strCompiler = &FileInfo::GetCompiler($MAKEFILE_ref);
    
    my $nRAMnum = 0;
    if($strCompiler eq "RVCT")
    {
        $nRAMnum = &sysInfoProcScat::GetRAMregion($BB_PATH, $strFilePath, $RAMregion_aref, $MAKEFILE_ref);
    }
    elsif($strCompiler eq "GCC")
    {
        $nRAMnum = &sysInfoProcLds::GetRAMregion($BB_PATH, $strFilePath, $RAMregion_aref, $MAKEFILE_ref);  
    }
    return ($nRAMnum);
}

#****************************************************************************
# Subroutine:  GetRAMBoundaryregion - to query the boundary regions in RAM
#              this function can be used to calculate RAM margin
# Parameters:  $strFilePath  = the path of file (scatter file or lds file)
#              $MAKEFILE_ref = a Hash to contain MAKEFILE information
# Returns:     $LAST_CACHED_REGION  = the last cached region in RAM
#              $DUMMY_END   = the dummy_end region in RAM
#****************************************************************************
sub GetRAMBoundaryregion
{
    my ($strFilePath, $MAKEFILE_ref) = (@_);
    print "file path = $strFilePath\n" if($DebugPrint == 1);
    my $strCompiler = &FileInfo::GetCompiler($MAKEFILE_ref);

    my ($LAST_CACHED_REGION, $DUMMY_END)= (undef, undef);
    if($strCompiler eq "RVCT")
    {   
        ($LAST_CACHED_REGION, $DUMMY_END) = &sysInfoProcScat::GetRAMBoundaryregion($strFilePath, $MAKEFILE_ref);
    }
    elsif($strCompiler eq "GCC")
    {
        ($LAST_CACHED_REGION, $DUMMY_END) = &sysInfoProcLds::GetRAMBoundaryregion($strFilePath, $MAKEFILE_ref);  
    }
    return ($LAST_CACHED_REGION, $DUMMY_END);
}

#****************************************************************************
# Subroutine:  GetphysicalROMsize - to query physical ROM size
# Parameters:  $BB_PATH = the path of BB folder
#              $MAKEFILE_ref = a Hash to contain MAKEFILE information
# Returns:     $nROMsize = the physical ROM size
#****************************************************************************
sub GetphysicalROMsize
{
    my ($BB_PATH, $MAKEFILE_ref) = (@_);
    my $nROMsize = undef;
    my $strCompiler = &FileInfo::GetCompiler($MAKEFILE_ref);

    if($strCompiler eq "RVCT")
    {
        $nROMsize = &sysInfoProcScat::GetphysicalROMsize($BB_PATH);
    }
    elsif($strCompiler eq "GCC")
    {
        $nROMsize = &sysInfoProcLds::GetphysicalROMsize($BB_PATH);
    }
    return $nROMsize;
}

#****************************************************************************
# Subroutine:  GetAvailableROMsize - to query available ROM size
# Parameters:  $BB_PATH = the path of BB folder
#              $MAKEFILE_ref = a Hash to contain MAKEFILE information
# Returns:     $nROMsize = the available ROM size
#****************************************************************************
sub GetAvailableROMsize
{
    my ($BB_PATH, $MAKEFILE_ref) = (@_);
    my $nROMsize = undef;
    my $strCompiler = &FileInfo::GetCompiler($MAKEFILE_ref);

    if($strCompiler eq "RVCT")
    {
        $nROMsize = &sysInfoProcScat::GetAvailableROMsize($BB_PATH);
    }
    elsif($strCompiler eq "GCC")
    {
        $nROMsize = &sysInfoProcLds::GetAvailableROMsize($BB_PATH);
    }
    return $nROMsize;
}

#****************************************************************************
# Subroutine:  GetROMregion - to query all regions placed in ROM
# Parameters:  $BB_PATH
#              $strFilePath = the path of file (scatter file or lds file)
#              $ROMregion_href = a Hash reference to store ROM regions
#              $ROMregion_href->{regionName} = []
#              $MAKEFILE_ref = a Hash to contain MAKEFILE information
# Returns:     $nROMnum = the number of ROM regions
#****************************************************************************
sub GetROMregion
{
    my ($BB_PATH, $strFilePath, $ROMregion_href, $MAKEFILE_ref) = (@_);
    print "file path = $strFilePath\n" if($DebugPrint == 1);
    my $strCompiler = &FileInfo::GetCompiler($MAKEFILE_ref);

    my $nROMnum = 0;
    if($strCompiler eq "RVCT")
    {
        $nROMnum = &sysInfoProcScat::GetROMregion($BB_PATH, $strFilePath, $ROMregion_href, $MAKEFILE_ref);
    }
    elsif($strCompiler eq "GCC")
    {
        $nROMnum = &sysInfoProcLds::GetROMregion($BB_PATH, $strFilePath, $ROMregion_href, $MAKEFILE_ref);  
    }
    return ($nROMnum);
}

sub FilterOutRegionInRAM
{
    my ($prvER_aref, $MAKEFILE_ref) = @_;
    my @ERInRAM;
    my $strCompiler = &FileInfo::GetCompiler($MAKEFILE_ref);
    if($strCompiler eq "GCC")
    {
        &sysInfoProcLds::FilterOutRegionInRAM($prvER_aref, \@ERInRAM);
    }
    return \@ERInRAM;
}
sub FilterOutFixedRegion
{
    my ($prvER_aref, $MAKEFILE_ref) = @_;
    my @ERInRAM;
    my $strCompiler = &FileInfo::GetCompiler($MAKEFILE_ref);
    if($strCompiler eq "GCC")
    {
        &sysInfoProcLds::FilterOutFixedRegion($prvER_aref, \@ERInRAM);
    }
    return \@ERInRAM;
}

sub FilterOutCoproReservedRegion
{
    my ($prvER_aref) = @_;
    my @ERs;
    my @ReversePrvER = reverse @$prvER_aref;
    my $bTrim = 0;
    foreach my $item (@ReversePrvER)
    {
        if($item !~/copro/i)
        {
           push (@ERs , $item);   
        }
        else
        {
           # print "[FilterOutCoproReservedRegion]Skip $item\n";    
        }
    }
    @ERs = reverse @ERs;
    return \@ERs;
}

sub FilterOutSecureRegion
{
    my ($prvER_aref) = @_;
    my @ERs;
    my @ReversePrvER = reverse @$prvER_aref;
    my $bTrim = 0;
    foreach my $item (@ReversePrvER)
    {
        if($item !~/SECURE_RO|SIGNATURE/i)
        {
           push (@ERs , $item);   
        }
        else
        {
           # print "[FilterOutCoproReservedRegion]Skip $item\n";    
        }
    }
    @ERs = reverse @ERs;
    return \@ERs;
}

sub GetRegionInfo
{
    my ($ER, $nOption, $strFilePath, $MAKEFILE_ref) = @_;
    my $strCompiler = &FileInfo::GetCompiler($MAKEFILE_ref);
    my $Info;
    if($strCompiler eq "GCC")
    {
        $Info = &sysInfoProcLds::GetRegionInfoFromLDS($ER, $nOption, $strFilePath);
    }
    return $Info;
}

sub GetMemoryInfo
{
    my ($strName, $nOption, $strFilePath, $MAKEFILE_ref) = @_;
    my $strCompiler = &FileInfo::GetCompiler($MAKEFILE_ref);
    my $strInfo;
    if($strCompiler eq "GCC")
    {
        $strInfo = &sysInfoProcLds::GetMemoryInfoFromLDS($strName, $nOption, $strFilePath);
    }
    return $strInfo;
}

__END__

=head1 NAME

systemInfo.pm - Perl module to get system Infomation

=head1 SYNOPSIS

    use systemInfo;

=head2 Table of Contents

systemInfo consists of a collection of modules whose details 
are too big to fit in one document.  This POD explains the
top-level APIs and general topics.  For detailed implementation
, please see the PODs below:

  Name			        Description
  --------------------------------------------------------
  sysInfoProcessGCC         Process module for GCC compiler
  sysInfoProcessRVCT        Process module for RVCT compiler
  --------------------------------------------------------

=head1 DESCRIPTION

The module provides the interfaces to get the system information under GCC/RVCT build environment

=head1 EXAMPLES

Here are some code samples showing a possible usage of systemInfo:

1. Get all ChipInside-RAM regions

    use systemInfo;
    use FileInfoParser;

    my $makeFile = "/proj/[usrID]/[path]/MT6280_R7R8_HSPA(FULL_VERSION).mak";
    my $file = "/proj/[usrID]/[path]/ldsMT6280_R7R8.txt";
    my %MAKEFILE_OPTIONS;
    my %ChipInsideRam_region;
    my $nChipInsideRAMnum = 0;
    
    &FileInfo::Parse_MAKEFILE($makeFile, \%MAKEFILE_OPTIONS); #Must run this subroutine first for other activities

    $nChipInsideRAMnum =  &sysInfo::GetChipInsideRAMregion($file, \%ChipInsideRam_region, \%MAKEFILE_OPTIONS);
    
    print "nChipInsideRAMnum = $nChipInsideRAMnum\n";
    foreach my $strRegionName (keys %ChipInsideRam_region)
    {
        print "ChipInsideRAMregion = $strINTSRAMname\n";
    }

    <OUTPUT>
    
    nChipInsideRAMnum = 5
    ChipInsideRAMregion = INTSRAM_PHYSICAL_BOUNDARY
    ChipInsideRAMregion = INTSRAM_DATA
    ChipInsideRAMregion = EMIINIT_CODE
    ChipInsideRAMregion = INTSRAM_DATA_PREINIT_ZI
    ChipInsideRAMregion = INTSRAM_CODE

2. Get the size of all ChipInside RAM

    use systemInfo;
    use FileInfoParser;

    my $makeFile = "/proj/[usrID]/[path]/MT6280_R7R8_HSPA(FULL_VERSION).mak";
    my $file = "/proj/[usrID]/[path]/ldsMT6280_R7R8.txt";
    my %MAKEFILE_OPTIONS;
    my %ChipInsideRAMInfo;
    my $nChipInsideRAMnum = 0;
    
    &FileInfo::Parse_MAKEFILE($makeFile, \%MAKEFILE_OPTIONS); #Must run this subroutine first for other activities
    $nChipInsideRAMnum =  &sysInfo::GetINTSRAMsize($file, \%ChipInsideRAMInfo, \%MAKEFILE_OPTIONS);
    
    print "nChipInsideRAMnum = $nChipInsideRAMnum\n";
    foreach my $strRegionName (keys %ChipInsideRAMInfo)
    {
        print "$strRegionName size = ".%ChipInsideRAMInfo->{$strRegionName}."\n";
    }

    <OUTPUT>
    
    nChipInsideRAMnum = 1
    TCM size = 229376
    
3. Get TCM margin (TCM or DTCM/ITCM)

   to use this API, the following steps are listed:
   
   [step1]
       Get all ChipInside RAM regions - run GetChipInsideRAMregion() subroutine in systemInf.pm
   
   [step2]
       Get the usage of each ChipInside RAM region - run GetTotalSizeByExeRegion() subroutine in LinkerOutputParser.pm
       Store these information in a hash - please refer to the example below
       ([size] need to replace to the real size get from LinkerOutputParser.pm)
       my %ChipInsideRAMinfo= (
            INTSRAM_PHYSICAL_BOUNDARY => [size],
            INTSRAM_DATA => [size],
            EMIINIT_CODE => [size],
            INTSRAM_DATA_PREINIT_ZI => [size],
            INTSRAM_CODE => [size],
            );
   [step3]
       run this script to get TCM margin
       (%ChipInsideRAMinfo is created in step2)
    
        my $makeFile = "/proj/[usrID]/[path]/MT6280_R7R8_HSPA(FULL_VERSION).mak";
        my $file = "/proj/[usrID]/[path]/ldsMT6280_R7R8.txt";
        my %MAKEFILE_OPTIONS;
        my $TCMmargin_href = undef;
    
        &FileInfo::Parse_MAKEFILE($makeFile, \%MAKEFILE_OPTIONS); #Must run this subroutine first for other activities   
        $TCMmargin_href =  &sysInfo::GetTCMmargin($file, \%ChipInsideRAMinfo, \%MAKEFILE_OPTIONS);

        foreach my $strRegionname (keys %$TCMmargin_href)
        {
            print "$strRegionname margin = ". $TCMmargin_href->{$strRegionname}."\n";
        }

    <OUTPUT>

    TCM margin = 228926

4. Get physical RAM size
    
    use systemInfo;
    use FileInfoParser;

    my $makeFile = "/proj/[usrID]/[path]/MT6280_R7R8_HSPA(FULL_VERSION).mak";
    my $BB_PATH  = "/proj/[usrID]/[path]/mcu/build/[project]/[flavor]/custom/system";;
    my %MAKEFILE_OPTIONS;
    
    &FileInfo::Parse_MAKEFILE($makeFile, \%MAKEFILE_OPTIONS); #Must run this subroutine first for other activities    
    my $nPhyRAMsize = 0;
    $nPhyRAMsize = &sysInfo::GetphysicalRAMsize($BB_PATH, \%MAKEFILE_OPTIONS);
    print "nPhyRAMsize = $phyRAMsize\n";
    
    <OUTPUT>

    nPhyRAMsize = 8388608
    
5. Get available RAM size

    use systemInfo;
    use FileInfoParser;

    my $makeFile = "/proj/[usrID]/[path]/MT6280_R7R8_HSPA(FULL_VERSION).mak";
    my $BB_PATH  = "/proj/[usrID]/[path]/mcu/build/[project]/[flavor]/custom/system";;
    my %MAKEFILE_OPTIONS;
    
    &FileInfo::Parse_MAKEFILE($makeFile, \%MAKEFILE_OPTIONS); #Must run this subroutine first for other activities
    my $nPhyRAMsize = 0;
    $nPhyRAMsize = &sysInfo::GetphysicalRAMsize($BB_PATH, \%MAKEFILE_OPTIONS);
    print "nPhyRAMsize = $phyRAMsize\n";
    
    <OUTPUT>

    nPhyRAMsize = 8388608

6. Get RAM regions

    use systemInfo;
    use FileInfoParser;

    my $makeFile = "/proj/[usrID]/[path]/MT6280_R7R8_HSPA(FULL_VERSION).mak";
    my $BB_PATH  = "/proj/[usrID]/[path]/mcu/build/[project]/[flavor]/custom/system";
    my $file = "/proj/[usrID]/[path]/ldsMT6280_R7R8.txt";    
    my %MAKEFILE_OPTIONS;
    my %RAM_region;
    my $nRAMnum = 0;

    &FileInfo::Parse_MAKEFILE($makeFile, \%MAKEFILE_OPTIONS); #Must run this subroutine first for other activities
    $nRAMnum =  &sysInfo::GetRAMregion($BB_PATH, $file, \%RAM_region, \%MAKEFILE_OPTIONS);

    print "nRAMnum = $nRAMnum\n";
    foreach my $strRAMname (keys %RAM_region)
    {
        print "RAMregion = $strRAMname\n";
    }

    <OUTPUT>
    
    nRAMnum = 15
    RAMregion = ROM0
    RAMregion = DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW
    RAMregion = DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL
    RAMregion = ROMHEAD
    RAMregion = DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL
    RAMregion = CACHED_EXTSRAM
    RAMregion = EXTSRAM
    RAMregion = CACHED_EXTSRAM_NVRAM_LTABLE
    RAMregion = ROM
    RAMregion = ROM1
    RAMregion = EXTSRAM_DSP_TX
    RAMregion = DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI
    RAMregion = DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI
    RAMregion = EXTSRAM_DSP_RX
    RAMregion = DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW
    
    NOTE: This function can not be applied to 11B branch

7. Get RAM boundary regions

    my $makeFile = "/proj/[usrID]/[path]/MT6280_R7R8_HSPA(FULL_VERSION).mak";
    my $file = "/proj/[usrID]/[path]/ldsMT6280_R7R8.txt";
    my %MAKEFILE_OPTIONS;

    &FileInfo::Parse_MAKEFILE($makeFile, \%MAKEFILE_OPTIONS); #Must run this subroutine first for other activities
    my($LastRegionBeforeDUMMYEND, $DUMMY_END) =  &sysInfo::GetRAMBoundaryregion($file,\%MAKEFILE_OPTIONS);

    print "Last Region Before DUMMY_END = $LastRegionBeforeDUMMYEND\nDUMMY_END = $DUMMY_END\n";
    
    <OUTPUT>
    
    Last Region Before DUMMY_END = DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI
    DUMMY_END = CACHED_DUMMY_END
    
    Note: This API can be used to get RAM margin
          RAM margin = DUMMY_END_base - (LastRegionBeforeDUMMYEND_base + LastRegionBeforeDUMMYEND_size);
    
8. Get physical ROM size
    
    use systemInfo;
    use FileInfoParser;

    my $makeFile = "/proj/[usrID]/[path]/MT6280_R7R8_HSPA(FULL_VERSION).mak";
    my $BB_PATH  = "/proj/[usrID]/[path]/mcu/build/[project]/[flavor]/custom/system";;
    my %MAKEFILE_OPTIONS;
    
    &FileInfo::Parse_MAKEFILE($makeFile, \%MAKEFILE_OPTIONS); #Must run this subroutine first for other activities    
    my $nPhyROMsize = 0;
    $nPhyROMsize = &sysInfo::GetphysicalROMsize($BB_PATH, \%MAKEFILE_OPTIONS);
    print "nPhyROMsize = $phyROMsize\n";

    <OUTPUT>

    nPhyROMsize = 268435456

9. Get available ROM size

    use systemInfo;
    use FileInfoParser;

    my $makeFile = "/proj/[usrID]/[path]/MT6280_R7R8_HSPA(FULL_VERSION).mak";
    my $BB_PATH  = "/proj/[usrID]/[path]/mcu/build/[project]/[flavor]/custom/system";;
    my %MAKEFILE_OPTIONS;
    
    &FileInfo::Parse_MAKEFILE($makeFile, \%MAKEFILE_OPTIONS); #Must run this subroutine first for other activities
    my $nPhyROMsize = 0;
    $nPhyROMsize = &sysInfo::GetphysicalROMsize($BB_PATH, \%MAKEFILE_OPTIONS);
    print "nPhyRAMsize = $phyRAMsize\n";
    
    <OUTPUT>

    nPhyROMsize = 0

10. Get ROM regions

    use systemInfo;
    use FileInfoParser;

    my $makeFile = "/proj/[usrID]/[path]/MT6280_R7R8_HSPA(FULL_VERSION).mak";
    my $BB_PATH  = "/proj/[usrID]/[path]/mcu/build/[project]/[flavor]/custom/system";
    my $file = "/proj/[usrID]/[path]/ldsMT6280_R7R8.txt";
    my %MAKEFILE_OPTIONS;
    my %ROM_region;
    my $nROMnum = 0;

    &FileInfo::Parse_MAKEFILE($makeFile, \%MAKEFILE_OPTIONS); #Must run this subroutine first for other activities
    $nROMnum =  &sysInfo::GetROMregion($BB_PATH, $file, \%ROM_region, \%MAKEFILE_OPTIONS);

    print "nROMnum = $nROMnum\n";
    foreach my $strROMname (keys %ROM_region)
    {
        print "ROMregion = $strROMname\n";
    }

    <OUTPUT>
    
    nROMnum = 0
    
    NOTE: This function can not be applied to 11B branch.
          for MOLY, all regions will be moved to RAM.

=cut


