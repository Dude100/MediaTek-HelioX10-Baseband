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
#*   LISInfo.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This module collects the subroutines for common utility. 
#*       
#*
#* Author:
#* -------
#*   Qmei Yang (mtk03726)
#*
#****************************************************************************/


use strict;
#use warnings;
BEGIN { push @INC, './tools/', './tools/MemoryUtility/' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity
use LinkerOutputParser;
use CommonUtility;
use FileInfoParser;
use scatInfo;
#****************************************************************************
# Constants
#****************************************************************************
my $LISINFO_VERNO     = " m0.13";
                        # m0.13 , 2014/01/15,  Correct PA address in GetDumpRegionBase()
                        # m0.12 , 2013/12/01,  Support cmm memory dump
                        # m0.11 , 2013/10/24,  Dump regions in order
                        # m0.10 , 2013/09/05,  Dump nc in CACHED_EXTSRAM on moly only
                        # m0.09 , 2013/05/29,  Fix code region without dumping data regions
                        # m0.08 , 2013/05/27,  Fix cacheable region's prefix
                        # m0.07 , 2012/11/17,  Support GetDumpCodeRegions()
                        # m0.06 , 2012/10/05,  Support SearchExeRegionName()
                        # m0.05 , 2012/08/17,  Support GetChip() from FileInfoParser
                        # m0.04 , 2012/08/07,  Move Dec2Hex from sysGenUtility to CommonUtility
                        # m0.03 , 2012/07/26,  Change LinkerOutputParser.pm's location
                        # v0.12 , 2012/05/29,  Refined GetScatterReservedSize()
                        # v0.10 , 2012/05/29,  Provide GetScatterReservedSize() for vivaConfig.pl
                        # m0.02 , 2012/05/28,  Support path and filename case sensitive on Linux
                        # m0.01 , 2012/05/28,  Support parsing .sym by LinkerOutputParser.pm temporary 
                        # v0.09 , 2012/05/16,  Modify CheckROMSize() to fix the error of checking rule
                        # v0.08 , 2012/04/17,  Support dump ALICE and compressed ALICE
                        # v0.07 , 2012/04/02,  Modify the return type of CheckROMSize()
                        # v0.06 , 2012/04/02,  Remove GetTotalSizesByObjList_and_ExeRegion()
                        # v0.05 , 2012/03/26,  Provide GetTotalROMSize(), GetTotalROSize(), GetTotalRWZISize() instead of GetTotalSizeInfo()
                        #                      Extend parsing obj list for
                        #                      providing GetInputSectionnByExeRegion(), GetObjTotalSizesByExeRegion(), 
                        #                      GetTotalSizesByObjList_and_ExeRegion() instead of GetObjInfo()
                        # v0.04 , 2012/03/12,  Support GetObjInfo() and provide CheckRomSize() to ckImgSize.pl
                        # v0.03 , 2012/02/15,  Support synced with scatInfo.pm 
                        # v0.02 , 2011/12/16,  Fix a bug
                        # v0.01 , 2011/09/18,  Initial revision

#****************************************************************************
# Constants
#****************************************************************************
package InputSection;
use constant ExeRegionName         => 0;
use constant Base                  => 1;
use constant Size                  => 2;
use constant Type                  => 3;
use constant Attr                  => 4;
use constant SectionAttr           => 5;
use constant ObjName               => 6;
use constant LibName               => 7;

package LISInfo;
#****************************************************************************
# global variable
#****************************************************************************
my $g_LISPath;
# Load Region
my %g_LoadRegion;
my $g_LoadRegionCount = 0;
my %g_LoadRegionLookUpTable; # RegionName -> Index
# Execution Region
my %g_ExeRegion;
my $g_ExeRegionCount = 0;
my %g_ExeRegionLookUpTable; # RegionName -> Index

# InputSection:
my %g_InputSectionDetails; # {nIndex} => [0. strExecutionRegionName, 
                           #              1. strBaseAddress, 
                           #              2. strSize, 
                           #              3. strType, 
                           #              4. strAttr, 
                           #              5. strSectionName, 
                           #              6. strObjectName, 
                           #              7. strLibName]
                           # nIndex starts from 0
my %g_InputSections; # {strExecutionRegionName} => [nIndex, ...]
my $g_InputSectionCount = 0;

# Total Size
my $g_nTotalROSize = 0;
my $g_nTotalRWZISize = 0;
my $g_nTotalROMSize = 0;

my %g_RegionGroup;  # {GroupName} => [RegionName, ... sorted by Index]
my %g_RegionMap;
my $g_scatInfo_ref = undef;
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# subroutine:  LIS_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub LIS_die
{
    my ($error_msg, $file, $line_no) = (@_);
    &sysUtil::error_handler($error_msg, $file, $line_no, 'LIS');    
}
#****************************************************************************
# subroutine:  ParseLIS
# input:  LIS Path string     
# output: x     
#****************************************************************************
sub ParseLIS
{
    ($g_LISPath) = (@_);
    if(defined $g_LISPath and -e $g_LISPath)
    {
        open (FILE_HANDLE, "<$g_LISPath") or &LIS_die("$g_LISPath: file error!", __FILE__, __LINE__);
        my $strPreExeRegionName = undef;
        while (<FILE_HANDLE>) 
        {
            my $strLine = $_;
            if(/\s+Load Region\s(\w+)\s\(Base:\s(0x\w+)\,\sSize:\s(0x\w+),\sMax:\s(0x\w+),\s(\w+)\)/) 
            {
                #$1=Region name, $2=nBaseAddress, $3=nActualSize, $4=nMaxSize, $5=strAttribute
                $g_LoadRegion{++$g_LoadRegionCount}= [$1, hex($2), hex($3), hex($4), $5];
                #print "Index=$g_LoadRegionCount, LoadRegionName=$1, BaseAddress=$2, MaxSize=$3, ActualSize=$4, Attribute=$5\n";
                $g_LoadRegionLookUpTable{$1} = $g_LoadRegionCount;
                $strPreExeRegionName = undef;
            }
            elsif (/\s+Execution Region\s(\w+)\s\(Base:\s(0x\w+)\,\sSize:\s(0x\w+),\sMax:\s(0x\w+),\s(\w+)(.*)\)/) 
            {
                #$1=Region name, $2=nBaseAddress, $3=nActualSize, $4=nMaxSize, $5=strAttribute
                $g_ExeRegion{++$g_ExeRegionCount}= [$1, hex($2), hex($3), hex($4), $5];
                #print "Index=$g_ExeRegionCount, ExeRegionName=$1, BaseAddress=$2, Size=$3, ActualSize=$4, Attribute=$5\n";
                $g_ExeRegionLookUpTable{$1} = $g_ExeRegionCount;
                # For parsing Input sections
                $strPreExeRegionName = $1;
                $g_InputSections{$strPreExeRegionName} = [];
            }
            elsif (/=========/)
            {
                $strPreExeRegionName = undef;
            }
            elsif (/Total RO  Size \(Code \+ RO Data\)\s+(\S+)/)
            {
                $g_nTotalROSize = $1;
            }
            elsif (/Total RW  Size \(RW Data \+ ZI Data\)\s+(\S+)/)
            {
                $g_nTotalRWZISize = $1;
            }
            elsif (/Total ROM Size \(Code \+ RO Data \+ RW Data\)\s+(\S+)/)
            {
                $g_nTotalROMSize  = $1;
            }
            &ParseInputSection($strPreExeRegionName, $strLine) if(defined $strPreExeRegionName);
        }
        close FILE_HANDLE;
    }
    else
    {
        &LIS_die("LIS Path($g_LISPath) doesn't exist", __FILE__, __LINE__);   
    }    
}

sub Parse
{
    my ($InputPath) = @_;
    if($InputPath =~ /lis/)
    {
        &ParseLIS($InputPath);
    }
    else
    {
        &LinkerOutputParser::FileParse($InputPath);
        # Execution Region
        my $ExeName_aref = &LinkerOutputParser::ListAllExeRegion();
        foreach my $item (@$ExeName_aref)
        {
            next if($item =~/\./);
            my $strBaseAddress = LinkerOutputParser::GetExeRegionInfo($item, Region::VMA);
            my $strActualSize = LinkerOutputParser::GetExeRegionInfo($item, Region::Size);
            
            #$1=Region name, $2=nBaseAddress, $3=nActualSize, $4=nMaxSize, $5=strAttribute
            $g_ExeRegion{++$g_ExeRegionCount} = [$item, hex($strBaseAddress), hex($strActualSize), 0xffffffff, undef];
            $g_ExeRegionLookUpTable{$item} = $g_ExeRegionCount;  
            #print "[$item][$g_ExeRegionCount]: $strBaseAddress, $strActualSize\n";
        }
        # Load Region
        &Workaround_LoadRegion();
    }
}

sub Workaround_LoadRegion
{
    $g_LoadRegion{1}= ["ROM", $g_ExeRegion{1}->[1], $g_ExeRegion{1}->[2], $g_ExeRegion{1}->[3], $g_ExeRegion{1}->[4]];
    $g_LoadRegionCount = 1;
    $g_LoadRegionLookUpTable{ROM} = 1;
}

#****************************************************************************
# subroutine:  ParseInputSection used by ParseLIS
#              to parse input sections
# parsing format: 
#     Base Addr    Size         Type   Attr      Idx    E Section Name        Object
# 1.  0x70008230   0x00000020   Code   RO           18  * VECTOR_TBL          bl_BOOTARM.obj(bootloader.lib)   
# 2.  0x1007bb30   0x00000008   Ven    RO       402248    Veneer$$Code        anon$$obj.o
# 3.  0x106f9c72   0x00000002   PAD
# we don't need Idx(Index) and E(Entry)
# input:  1. Execution Name, 2. $strLine
# output: x     
#****************************************************************************
sub ParseInputSection
{
    my ($strExeRegionName, $strLine) = @_;
    return if(!defined $strExeRegionName);

    my ($strBaseAddress, $strSize, $strType, $strAttr, $strInputSectionAttr, $strObjName, $strLibName)
     = (undef, undef, undef, undef, undef, undef, undef);
    my $bMatchInputSection = 0; 
    chomp($strLine);
    if($strLine =~ /\s+(0x\w+)\s+(0x\w+)\s+(\w+)\s+(\w+)\s+\d+\s+\**\s+(\S+)\s+(\S+)\((\S+)\)/)
    {
    #    Base Addr    Size         Type   Attr      Idx    E Section Name        Object
    #    0x70008230   0x00000020   Code   RO           18  * VECTOR_TBL          bl_BOOTARM.obj(bootloader.lib)    
        $strBaseAddress = $1;
        $strSize = $2;
        $strType = $3;
        $strAttr = $4;
        $strInputSectionAttr = $5;
        $strObjName = $6;
        $strLibName = $7;
        #print "[Pattern 1]$strLine:\n[Base]$strBaseAddress, [Size]$strSize, [Type]$strType, [Attr]$strAttr, [InputAttr]$strInputSectionAttr, [ObjName]$strObjName, [LibName]$strLibName\n";
        $bMatchInputSection = 1; 
    }
    elsif($strLine =~ /\s+(0x\w+)\s+(0x\w+)\s+(\w+)\s+(\w+)\s+\d+\s+\**\s+(\S+)\s+(\S+)/)
    {
    #    Base Addr    Size         Type   Attr      Idx    E Section Name        Object
    #    0x1007bb30   0x00000008   Ven    RO       402248    Veneer$$Code        anon$$obj.o
        $strBaseAddress = $1;
        $strSize = $2;
        $strType = $3;
        $strAttr = $4;
        $strInputSectionAttr = $5;
        $strObjName = $6;
        #print "[Pattern 2]$strLine:\n[Base]$strBaseAddress, [Size]$strSize, [Type]$strType, [Attr]$strAttr, [InputAttr]$strInputSectionAttr, [ObjName]$strObjName, [LibName]x\n";
        $bMatchInputSection = 1;
    }
    elsif($strLine =~ /\s+(0x\w+)\s+(0x\w+)\s+(\w+)/)
    {
    #    Base Addr    Size         Type   Attr      Idx    E Section Name        Object
    #    0x106f9c72   0x00000002   PAD
        $strBaseAddress = $1;
        $strSize = $2;
        $strType = $3;
        #print "[Pattern 3]$strLine:\n[Base]$strBaseAddress, [Size]$strSize, [Type]$strType\n";
        $bMatchInputSection = 1;
    }
    if($bMatchInputSection == 1)
    {
        $g_InputSectionDetails{$g_InputSectionCount} = [$strExeRegionName, $strBaseAddress, $strSize, 
                                                        $strType, $strAttr, $strInputSectionAttr, 
                                                        $strObjName, $strLibName];
        push (@{$g_InputSections{$strExeRegionName}}, $g_InputSectionCount);
        $g_InputSectionCount++;
    }
}
#****************************************************************************
# subroutine:  GetInputSectionsByExeRegion 
# input:       $strExeRegionName: Execution Name (Case sensitive)
# output:      Array_ref : InputSections: [[ExeRegionName, Base...], [ExeRegionName, Base...], ...]
#              [ExeRegionName, Base...]: InputSectionDetails elements
#****************************************************************************
sub GetInputSectionsByExeRegion
{
    my ($strExeRegionName) = @_;
    my @InputSections;
    my $Indexes = $g_InputSections{$strExeRegionName};
    foreach my $nIndex (@$Indexes)
    {
        push(@InputSections, $g_InputSectionDetails{$nIndex});
    }
    return \@InputSections;
}
#****************************************************************************
# subroutine:  GetObjTotalSizesByExeRegion
# input:       $strRegionName: Execution Name (Case sensitive)
# output:      ObjTotalSize Hash Reference: {ObjName::LibName} => nSize
# sample code:
#        my $strExeRegionName = "xxx";
#        my $nObjTotalSize_ref = &LISInfo::GetObjTotalSizesByExeRegion($strExeRegionName);
#        foreach my $Obj_LibName (keys %$nObjTotalSize_ref) {...}
#        => $Obj_LibName: "ObjName::LibName"
#****************************************************************************
sub GetObjTotalSizesByExeRegion
{
    my ($strExeRegionName) = @_;
    my $nIndex = 0;
    my %nObjTotalSize; # {ObjName_LibName} = nSize;
    my $InputSections_ref = &GetInputSectionsByExeRegion($strExeRegionName);
    foreach my $Info ( @$InputSections_ref)
    {
        if(defined $Info->[InputSection::ObjName])
        {
            my $strKey = $Info->[InputSection::ObjName]."::".$Info->[InputSection::LibName];
            if(exists $nObjTotalSize{$strKey})
            {
                $nObjTotalSize{$strKey} += hex($Info->[InputSection::Size]);
                #print "$strKey = ". $ObjTotalSize{$strKey} ."\n";
            }
            else
            {
                $nObjTotalSize{$strKey} = hex($Info->[InputSection::Size]);
                #print "$strKey = ". hex($Info->[InputSection::Size])."\n";
            }
        }
        else #PAD
        {
            $nObjTotalSize{"PAD"} += hex($Info->[InputSection::Size]);
        }
    }
    return \%nObjTotalSize;
}

#****************************************************************************
# subroutine:  GetExeRegionInfo - Get Execution Region information
# input:       $strRegionName: Execution Name (Case sensitive)
#              $bNeedString(optional): 0= return number(int), 1=return string if it's a size
# output:      1.Region Base address, Used Size, Region MaxSize, Attribute
#****************************************************************************
sub GetExeRegionInfo
{
    my ($strRegionName, $bNeedString) = (@_);
    $bNeedString = 0 if(!defined $bNeedString);
    my ($nBase, $nSize, $nMaxSize, $strAttribute) = (0,0,0,'');
    my $nIndex = $g_ExeRegionLookUpTable{$strRegionName};
    if(defined $nIndex)
    {
        $nBase = $g_ExeRegion{$nIndex}->[1];
        $nSize = $g_ExeRegion{$nIndex}->[2];
        $nMaxSize = $g_ExeRegion{$nIndex}->[3];
        $strAttribute = $g_ExeRegion{$nIndex}->[4];
    }
    return $bNeedString ? (&CommonUtil::Dec2Hex($nBase), &CommonUtil::Dec2Hex($nSize), &CommonUtil::Dec2Hex($nMaxSize), $strAttribute) 
                        : ($nBase, $nSize, $nMaxSize, $strAttribute);
}

#****************************************************************************
# subroutine:  GetLoadRegionInfo - Get Load Region information
# input:       $strRegionName: Load Name (Case sensitive)
#              $bNeedString(optional): 0= return number(int), 1=return string if it's a size
# output:      1.Region Base address, Used Size, Region MaxSize, Attribute    
#****************************************************************************
sub GetLoadRegionInfo
{
    my ($strRegionName, $bNeedString) = (@_);
    $bNeedString = 0 if(!defined $bNeedString);
    my ($nBase, $nSize, $nMaxSize, $strAttribute) = (0,0,0,'');
    my $nIndex = $g_LoadRegionLookUpTable{$strRegionName};
    if(defined $nIndex)
    {
        $nBase = $g_LoadRegion{$nIndex}->[1];
        $nSize = $g_LoadRegion{$nIndex}->[2];
        $nMaxSize = $g_LoadRegion{$nIndex}->[3];
        $strAttribute = $g_LoadRegion{$nIndex}->[4];
    }
    #print "$strRegionName's base=$nBase, ActualSize=$nSize, MaxSize=$nMaxSize, Attribute=$strAttribute\n";
    return $bNeedString ? (&CommonUtil::Dec2Hex($nBase), &CommonUtil::Dec2Hex($nSize), &CommonUtil::Dec2Hex($nMaxSize), $strAttribute) 
                        : ($nBase, $nSize, $nMaxSize, $strAttribute);
}
#****************************************************************************
# should be used with scatInfo.pm
# subroutine:  ClassifyRegionType - For cmmautogen.pl to know Region Type
# input:       Makefile Hash Reference
# output:      x
#****************************************************************************
sub ClassifyRegionType
{
    my ($MAKEFILE_ref) = @_;
    require "scatInfo.pm";
    $g_scatInfo_ref = LIS_new scatInfo(\%g_LoadRegion, $g_LoadRegionCount, \%g_LoadRegionLookUpTable,
                                        \%g_ExeRegion,  $g_ExeRegionCount,  \%g_ExeRegionLookUpTable,
                                        \%g_RegionGroup,\%g_RegionMap);
    $g_scatInfo_ref->ClassifyRegionType($MAKEFILE_ref);
}

#****************************************************************************
# should be used with scatInfo.pm
# subroutine:  GetGroupedRegions - Use keyword to get grouped regions after classified by ClassifyRegionType()
# input:       strKeyword
# output:      return Grouped regions
#****************************************************************************
sub GetGroupedRegions
{    
    my ($strKey) = @_;
    my $array_ref = undef;
    if($g_scatInfo_ref)
    {
        $array_ref = $g_scatInfo_ref->GetGroupedRegions($strKey); 
    }
    return $array_ref;
}

#****************************************************************************
# should be used with scatInfo.pm
# subroutine:  GetDumpExeRegions - Get dump regions for cmmautogen.pl
# input:       Makefile Hash Reference
# output:      Dump regions' reference
#****************************************************************************
sub GetDumpExeRegions
{    
    my ($MAKEFILE_ref) = @_;
    my $hash_ref = undef;
    my $order_aref = undef;
    if($g_scatInfo_ref)
    {
        my $bb = &FileInfo::GetChip($MAKEFILE_ref);
        ($hash_ref, $order_aref) = $g_scatInfo_ref->GetDumpExeRegions($bb);
        # if VECTOR TABLE and 1stROM Region both start from 0x0, 
        # then delete VECTOR TABLE group
        my $ROMInfo = $g_scatInfo_ref->GetExeRegionInfo("ROM");
        if(hex($ROMInfo->[0]) == 0)
        {
            delete $hash_ref->{"VECTOR_TABLE"};
        }
       
        # FLMM
        my $KAL_STACK_LAYOUT = $MAKEFILE_ref->{KAL_STACK_LAYOUT};
        push(@{$hash_ref->{OTHERS}}, ["FLMM_STACKSPACE"]) if(&IsRegionExistent("FLMM_STACKSPACE") and (defined $KAL_STACK_LAYOUT and $KAL_STACK_LAYOUT eq "ISOLATE") );
    }
    return $hash_ref;
}

#****************************************************************************
# should be used with scatInfo.pm
# subroutine:  GetDumpCodeRegions - Get dump code region names for cmmautogen.pl
# input:       Makefile Hash Reference
# output:      an array reference of Dump code region names
#****************************************************************************
sub GetDumpCodeRegions
{    
    my ($MAKEFILE_ref) = @_;
    my @DumpCodeRegions;
    my $DumpRegion_href = &GetDumpExeRegions($MAKEFILE_ref);
    foreach my $strGroupName (keys %$DumpRegion_href)
    {
        next if($strGroupName !~/ROM|INTSRAM/);
        my $array_ref = $DumpRegion_href->{$strGroupName};
        foreach my $RegionItem (@$array_ref)
        {
            my $RegionName = $RegionItem->[0];
            next if($strGroupName =~/INTSRAM/i and $RegionName =~ /data/i);
            push(@DumpCodeRegions, $RegionName);
        }
    }
    return \@DumpCodeRegions;
}

#****************************************************************************
# should be used with scatInfo.pm
# subroutine:  IsFixedLengthDumpGroup - Query if the dump region is fixed
# input:       strDumpRegionName
# output:      undef = not fixed, 1= fixed
#****************************************************************************
sub IsFixedLengthDumpGroup
{    
    my ($strKey) = @_;
    my $bFixed = undef; # undef = not fixed, 1= fixed
    if($g_scatInfo_ref)
    {
        $bFixed = $g_scatInfo_ref->IsFixedLengthDumpGroup($strKey); 
    }
    return $bFixed;
}
#****************************************************************************
# should be used with scatInfo.pm
# subroutine:  GetDumpRegionBase
# input:       1. DumpRegionGroup, 2. strDumpRegionName
#              3. BIN_PATH 4. $platform
# output:      str Base Address
#****************************************************************************
sub GetDumpRegionBase
{    
    my ($strGroupName, $strRegionName, $BIN_PATH, $platform) = @_;
    my $strBase = "0x0000000";
    if($strRegionName eq "DUMP_VECTOR_TABLE")
    {
        if($g_scatInfo_ref)
        { 
            my $Info = $g_scatInfo_ref->GetExeRegionInfo($strRegionName);
            $strBase = $Info->[0];
        }
    }
    else
    {
        my ($strSize, $strMaxSize, $strAttribute);
        ($strBase, $strSize, $strMaxSize, $strAttribute) = &GetExeRegionInfo($strRegionName, 1);
        if($strGroupName =~ /_PA/i)
        {
            if(0 == sysUtil::GetNonCacheablePrefix($platform))
            {
                $strBase = &CommonUtil::Dec2Hex(hex($strBase) & 0x0FFFFFFF);
            }
            else
            {
                $strBase = &CommonUtil::Dec2Hex(hex($strBase) | sysUtil::GetNonCacheablePrefix($platform));
            }
        }
        elsif($strGroupName =~ /_VA/)
        {
            if(0 == sysUtil::GetCacheablePrefix($platform))
            {
                $strBase = &CommonUtil::Dec2Hex(hex($strBase) & 0x0FFFFFFF);
            }
            else
            {
                $strBase = &CommonUtil::Dec2Hex(hex($strBase) | sysUtil::GetCacheablePrefix($platform));
            }
        }
    }
    $strBase = sprintf("0x%08x", hex($strBase));
    #print "[$strGroupName]$strRegionName: $strBase\n";
    return $strBase;
}
#****************************************************************************
# should be used with scatInfo.pm
# subroutine:  GetDumpRegionSize
# input:       x
# output:      an array contains [$strRegion, $strBase, $strSize] in hex ...
#****************************************************************************
sub GetCMMDumpRegionInfo
{
    my ($bb) = @_;
    my @CMMDumpRegions;
    my $region_aref = LinkerOutputParser::ListAllExeRegion(1);
    foreach my $strRegionName (@$region_aref)
    {
        next if($strRegionName =~/EMIINIT|DUMP_VECTOR_TABLE|SIGNATURE/i);
        my $strBase = LinkerOutputParser::GetExeRegionInfo($strRegionName, Region::VMA);
        my $strSize = LinkerOutputParser::GetExeRegionInfo($strRegionName, Region::Size);
        if($strRegionName =~/^CACHED_|DEFAULT_CACHEABLE|bss/i)
        {
            my $strPABase = &CommonUtil::Dec2Hex(hex($strBase) & 0x0FFFFFFF | sysUtil::GetNonCacheablePrefix($bb));
            push(@CMMDumpRegions, [$strRegionName."_PA", $strPABase, $strSize]);
        }
        push(@CMMDumpRegions, [$strRegionName, $strBase, $strSize]); 
    }
    
    return \@CMMDumpRegions;
}

#****************************************************************************
# subroutine:  IsRegionExistent
#              to see if this Region exists in Load Regions or Execution Regions
# input:       RegionName
# output:      $bExistent=undef: not existent, 1= existent
#****************************************************************************
sub IsRegionExistent
{
    my ($strRegionName) = @_;
    my $bExistent = undef;
    if(exists $g_LoadRegionLookUpTable{$strRegionName} or exists $g_ExeRegionLookUpTable{$strRegionName})
    {
        $bExistent = 1;
    }
    return $bExistent;
}

#****************************************************************************
# subroutine:  SearchExeRegionName
#              to get the first execution region name by keyword searching
# input:       Keyword
# output:      RegionName: undef means it's not existent
#****************************************************************************
sub SearchExeRegionName
{
    my ($strKey) = @_;
    my $strRegion = undef;
    foreach my $strTemp (keys %g_ExeRegionLookUpTable)
    {
        if($strTemp =~ /$strKey/)
        {
            $strRegion = $strTemp;
            last;
        }
    }
    return $strRegion;
}

#****************************************************************************
# subroutine:  CheckROMSize
#              to see if the free ROM is sufficient to put viva_bin
# input:       $Makefile_href : the hash reference of Makefile
#              $viva_bin_size : the size of viva binaray(include all compressed regions and viva region)              
# output:      $compRegion_end : the end address of VIVA
#              $check_base : the base address of all bottom to top regions
#                            (if there is no bottom to top regions, it will be the base address of files system)
#****************************************************************************
sub CheckROMSize
{
    my ($Makefile_href, $viva_bin_size) = @_;

    my $bb = &FileInfo::GetChip($Makefile_href);;
    my $compRegion_end  = undef;
    my $compRegion_start  = undef;
    my $check_base = undef;

    my $nIndex_VIVA  = $g_LoadRegionLookUpTable{'VIVA'};
    $compRegion_start =  &sysUtil::query_cs1_addr($bb, $g_LoadRegion{$nIndex_VIVA}->[1], 0);
    $compRegion_end = $compRegion_start + $viva_bin_size;

    if(defined $g_LoadRegionLookUpTable{'__HIDDEN_SECURE_MAC'})
    {
        my $nIndex_HIDDEN_SECURE_MAC = $g_LoadRegionLookUpTable{'__HIDDEN_SECURE_MAC'};
        $check_base = &sysUtil::query_cs1_addr($bb, $g_LoadRegion{$nIndex_HIDDEN_SECURE_MAC}->[1], 0);
    }
    elsif(defined $g_LoadRegionLookUpTable{'BOOT_CERT'})
    {
        my $nIndex_BOOT_CERT = $g_LoadRegionLookUpTable{'BOOT_CERT'};
        $check_base = &sysUtil::query_cs1_addr($bb, $g_LoadRegion{$nIndex_BOOT_CERT}->[1], 0);
    }

    return ($compRegion_end, $check_base);
}

#****************************************************************************
# subroutine:  GetScatterReservedSize 
#              (this subroutine is used for NOR project & VIVA is enabled)
# description: Get the estimated total ROM size with provided VIVA size
# input:       $Makefile_href : the hash reference of Makefile
#              $FS_base : the base address of file system
# output:      $nReservedSize : the reserved size of scatter file
#****************************************************************************
sub GetScatterReservedSize
{
    my ($Makefile_href, $FS_base) = @_;
    my $viva_base;
    my $bottom_to_top_base;
    my $ROM_size = 0;
    my $nReservedSize = undef;
    my $nIndex_VIVA = undef;

    my $bb = &FileInfo::GetChip($Makefile_href);;
    
    my $nIndex_ROM = $g_LoadRegionLookUpTable{'ROM'};
    $ROM_size = $g_LoadRegion{$nIndex_ROM}->[2];
    
    $nIndex_VIVA  = $g_LoadRegionLookUpTable{'VIVA'};
    $viva_base =  &sysUtil::query_cs1_addr($bb, $g_LoadRegion{$nIndex_VIVA}->[1], 0);
    
    if((&sysUtil::is_NOR($Makefile_href) != 1) or !defined $nIndex_VIVA)
    {
        return ($nReservedSize);
    }
    
    if(defined $g_LoadRegionLookUpTable{'__HIDDEN_SECURE_MAC'})
    {
        my $nIndex_HIDDEN_SECURE_MAC = $g_LoadRegionLookUpTable{'__HIDDEN_SECURE_MAC'};
        $bottom_to_top_base = &sysUtil::query_cs1_addr($bb, $g_LoadRegion{$nIndex_HIDDEN_SECURE_MAC}->[1], 0);
    }
    elsif(defined $g_LoadRegionLookUpTable{'BOOT_CERT'})
    {
        my $nIndex_BOOT_CERT = $g_LoadRegionLookUpTable{'BOOT_CERT'};
        $bottom_to_top_base = &sysUtil::query_cs1_addr($bb, $g_LoadRegion{$nIndex_BOOT_CERT}->[1], 0);
    }
    else
    {
        $bottom_to_top_base = $FS_base;
    }

    $nReservedSize = ($viva_base - $ROM_size) + ($FS_base - $bottom_to_top_base);

    return ($nReservedSize);
}

#****************************************************************************
# subroutine:  GetTotalROSize - Get total RO size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $bNeedString=0:nROSize/ $bNeedString=1:strROSize
#****************************************************************************
sub GetTotalROSize
{
    my ($bNeedString) = @_;
    return $bNeedString ? &CommonUtil::Dec2Hex($g_nTotalROSize) : $g_nTotalROSize; 
}
#****************************************************************************
# subroutine:  GetTotalRWZISize - Get total RWZI size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $bNeedString=0:nRWZISize/ $bNeedString=1:strRWZISize
#****************************************************************************
sub GetTotalRWZISize
{
    my ($bNeedString) = @_;
    return $bNeedString ? &CommonUtil::Dec2Hex($g_nTotalRWZISize) : $g_nTotalRWZISize;
}
#****************************************************************************
# subroutine:  GetTotalROMSize - Get total ROM size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $bNeedString=0:nROMSize/ $bNeedString=1:strROMSize
#****************************************************************************
sub GetTotalROMSize
{
    my ($bNeedString) = @_;
    return $bNeedString ? &CommonUtil::Dec2Hex($g_nTotalROMSize) : $g_nTotalROMSize;
}
