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
#*   sysInfoProcessScat.pm
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
package sysInfoProcScat;
use CommonUtility;
use sysGenUtility;
use scatInfo;
use strict;

#****************************************************************************
# Constants
#****************************************************************************
my $SYSINFOPROCSCAT_VERNO     = " m0.03";
                 # m0.03 , 2012/08/03,  Modify GetTCMmargin() to store TCM physical size                 
                 # m0.02 , 2012/08/03,  Modify module name and push additional library path
                 # m0.01 , 2012/07/05,  Initial revision

#****************************************************************************
# Global variable
#****************************************************************************
my $g_MAUIScat;
my $DebugPrint = 1;

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# Subroutine:  GetChipInsideRAMregion - to query all Chip inside RAM regions
# Parameters:  $SCATTERFILE = the path of scatter file
#              $INTSRAMregion_href = a Hash reference to store ChipInsideRAM infomation
#              $INTSRAMregion_href->{regionName} = []
# Returns:     $nINTSRAMnum = the number of ChipInsideRAM regions
#****************************************************************************
sub GetChipInsideRAMregion
{
    my ($SCATTERFILE, $INTSRAMregion_href) = (@_);
    my $nINTSRAMnum = 0;

    &GetScatInfo($SCATTERFILE);
    my $ExeRegion_ref = $g_MAUIScat->GetAllExeRegion();
    foreach (@$ExeRegion_ref)
    {
        if($_ =~ /EMIINIT_CODE|^INTSRAM|^L2TCM/)
        {
            next if ($_ =~ /DUMMY/);
            $nINTSRAMnum++;
            $INTSRAMregion_href -> {$_} = [];
        }
    }
    
    return ($nINTSRAMnum);
}

#****************************************************************************
# Subroutine:  GetChipInsideRAMsize - to query ChipInsideRAM size
# Parameters:  $SCATTERFILE = the path of scatter file
#              $INTSRAMinfo_href = a Hash reference to store ChipInsideRAM infomation
#              ($INTSRAMinfo_href -> {ChipInsideRAM type} = MaxSize)
# Returns:     $nINTSRAMnum = the number of ChipInsideRAM types
#****************************************************************************
sub GetChipInsideRAMsize
{
    my ($SCATTERFILE, $INTSRAMinfo_href) = (@_);
    my $nINTSRAMnum = 0;
    my $strINTSRAMName = undef;

    &GetScatInfo($SCATTERFILE);
    my $ExeRegion_ref = $g_MAUIScat->GetAllExeRegion();
    foreach (@$ExeRegion_ref)
    {
        if($_ =~ /INTSRAM_CODE|INTSRAM_DATA$|L2TCM_CODE|L2TCM_DATA|INTSRAM_MULTIMEDIA/)
        {
            #print "region = $_"."\n";
            $nINTSRAMnum++;
            my $Info = $g_MAUIScat->GetExeRegionInfo($_);
            my $nMaxSize = hex($Info->[Region::MaxSize]);
            my $strOffest = $Info->[Region::Offset];
            if($_ eq 'INTSRAM_CODE')
            {
                $strINTSRAMName = 'ITCM';
            }
            elsif($_ eq 'INTSRAM_DATA')
            {
                $strINTSRAMName = 'DTCM';
                if($strOffest eq '+0x0')
                {   
                    $nINTSRAMnum--;
                    my $TCMsize = $INTSRAMinfo_href->{'ITCM'};
                    $INTSRAMinfo_href->{'TCM'} = $TCMsize;
                    delete $INTSRAMinfo_href->{'ITCM'};
                    next;
                }
            }
            elsif($_ eq 'L2TCM_CODE')
            {
                $strINTSRAMName = 'L2TCM_CODE';
            }
            elsif($_ eq 'L2TCM_DATA')
            {
                $strINTSRAMName = 'L2TCM_DATA';
            }
            elsif($_ eq 'INTSRAM_MULTIMEDIA')
            {
                $strINTSRAMName = 'MM_SYSRAM';
            }            
            $INTSRAMinfo_href->{$strINTSRAMName} = $nMaxSize;
        }
    }
    return ($nINTSRAMnum);
}

#****************************************************************************
# Subroutine:  GetTCMmargin - to query TCM margin
# Parameters:  $SCATTERFILE = the path of scatter file
#              $TCMregion_href = a Hash reference to store TCM infomation
#              $TCMregion_href->{'regionName'} = size
# Returns:     $hTCMmargin = a Hash reference to store TCM information
#              $TCMmargin_href->{ITCM}->[0] = ITCM physical size, $TCMmargin_href->{ITCM}->[1] = ITCM margin
#              $TCMmargin_href->{DTCM}->[0] = DTCM physical size, $TCMmargin_href->{DTCM}->[1] = DTCM margin
#              $TCMmargin_href->{TCM}->[0]  = TCM physical size , $TCMmargin_href->{TCM}->[1]  = TCM margin
#****************************************************************************
sub GetTCMmargin
{
    my ($SCATTERFILE, $TCMregion_href) = (@_);
    my %hTCMmargin;
    my %INTSRAMinfo;
    my ($TCMmargin, $ITCMmargin, $DTCMmargin) = (undef,undef,undef);
    my ($ITCMusedsize, $DTCMusedsize) = (0,0);
    &GetChipInsideRAMsize($SCATTERFILE, \%INTSRAMinfo);
    
    foreach my $strINTSRAM (keys %{$TCMregion_href})
    {
        if( $strINTSRAM =~ /^INTSRAM/)
        {
            $ITCMusedsize += $TCMregion_href->{$strINTSRAM} if($strINTSRAM =~ /CODE/);
            $DTCMusedsize += $TCMregion_href->{$strINTSRAM} if($strINTSRAM =~ /DATA/);
        }
    }

    foreach my $strINTSRAMname (keys %INTSRAMinfo)
    {
        if($strINTSRAMname =~ /^TCM/)
        {
            my $TCMsize = $INTSRAMinfo{$strINTSRAMname};
            $TCMmargin = $TCMsize - $ITCMusedsize - $DTCMusedsize;
            $hTCMmargin{'TCM'} = [$TCMsize, $TCMmargin];
        }
        elsif($strINTSRAMname =~ /^ITCM/)
        {
            my $ITCMsize = $INTSRAMinfo{$strINTSRAMname};
            $ITCMmargin = $ITCMsize - $ITCMusedsize;
            $hTCMmargin{'ITCM'} = [$ITCMsize, $ITCMmargin];
        }
        elsif($strINTSRAMname =~ /^DTCM/)
        {
            my $DTCMsize = $INTSRAMinfo{$strINTSRAMname};
            $DTCMmargin = $DTCMsize - $DTCMusedsize;
            $hTCMmargin{'DTCM'} = [$DTCMsize, $DTCMmargin];
        }
    }
    return (\%hTCMmargin);
}


#****************************************************************************
# Subroutine:  GetphysicalRAMsize - to query physical RAM size
# Parameters:  $BB_PATH = the path of BB folder
# Returns:     $nRAMsize = the physical RAM size
#****************************************************************************
sub GetphysicalRAMsize
{
    my ($BB_PATH) = (@_);
    my $CUSTOM_EMI_RELEASE_H  = $BB_PATH . '/' . "custom_EMI_release.h";
    my $nRAMsize = 0;
    
    open (EMIRELEASEH_HANDLE, "<$CUSTOM_EMI_RELEASE_H") or &sysInfoProcess_die("$CUSTOM_EMI_RELEASE_H: file error!", __FILE__, __LINE__);
    while (<EMIRELEASEH_HANDLE>) {
        if (/^#define EMI_EXTSRAM_SIZE\s+\(\s*\(*\s*\(*\s*(\S+)\)*\s*<<\s*20\s*\)*\s*>>\s*3\s*\)/)
        {
            $nRAMsize = $1 * 1024 * 1024 / 8;
        }
    }
    close (EMIRELEASEH_HANDLE);
    return $nRAMsize;
}


#****************************************************************************
# Subroutine:  GetAvailableRAMsize - to query available RAM size
# Parameters:  $BB_PATH = the path of BB folder
# Returns:     $nRAMsize = the available RAM size
#****************************************************************************
sub GetAvailableRAMsize
{
    my ($BB_PATH) = (@_);
    my $nRAMsize = undef;
    my $CUSTOM_FEATURECONFIG_H   = $BB_PATH . '/' . "custom_FeatureConfig.h";
    my $CUSTOM_EMI_RELEASE_H     = $BB_PATH . '/' . "custom_EMI_release.h";
    my $bsetLimit = 0;
    my $isNOR = (&FileInfo::is_NOR() and !FileInfo::is_SmartPhone()) ? 1 : 0;

    open (FEATURECONFIGH_HANDLE, "<$CUSTOM_FEATURECONFIG_H") or &sysInfoProcSCAT_die("$CUSTOM_FEATURECONFIG_H: file error!", __FILE__, __LINE__);
    while (<FEATURECONFIGH_HANDLE>) {
    if (/^#define PROJECT_EXPECTED_RAM_LIMIT\s*(\w*)/ && $isNOR)
    {
        $nRAMsize = hex($1);
        $bsetLimit = 1;
    }
    elsif (/^#define PROJECT_EXPECTED_RAM_LIMIT_NFB\s*(\w*)/)
    {
        $nRAMsize = hex($1);
        $bsetLimit = 1;
    }
    }
    close (FEATURECONFIGH_HANDLE);
    
    if($bsetLimit == 0)
    {
        open (EMIRELEASEH_HANDLE, "<$CUSTOM_EMI_RELEASE_H") or &sysInfoProcess_die("$CUSTOM_EMI_RELEASE_H: file error!", __FILE__, __LINE__);
        while (<EMIRELEASEH_HANDLE>) {
        if (/^#define EMI_EXTSRAM_SIZE\s+\(\s*\(*\s*\(*\s*(\S+)\)*\s*<<\s*20\s*\)*\s*>>\s*3\s*\)/)
        {
            $nRAMsize = $1 * 1024 * 1024 / 8;
        }
        }
        close (EMIRELEASEH_HANDLE);
    }
    return $nRAMsize;
}

#****************************************************************************
# Subroutine:  GetRAMregion - to query all regions placed in RAM
# Parameters:  $BB_PATH
#              $SCATTERFILE = the path of scatter file
#              $RAMregion_aref = a Array reference to store RAM regions
#              $MAKEFILE_ref = a Hash to contain MAKEFILE information
# Returns:     $nRAMnum = the number of RAM regions
#****************************************************************************
sub GetRAMregion
{
    my ($BB_path, $SCATTERFILE, $RAMregion_aref, $MAKEFILE_ref) = (@_);
    my $CUSTOM_FEATURECONFIG_H = $BB_path . '/' . "custom_FeatureConfig.h";
    my $nRAMnum = 0;
    my $isNOR = (&FileInfo::is_NOR() and !FileInfo::is_SmartPhone());
    
    &GetScatInfo($SCATTERFILE);
    my $ExeRegion_ref = $g_MAUIScat->GetAllExeRegion();
    
    if(!$isNOR)
    {
        foreach (@$ExeRegion_ref)
        {
            #print $_."\n";
            next if($_ =~ /GFH$|SIGNATURE|EMIINIT_CODE|^INTSRAM|^L2TCM|DUMMY|SHOULDBE_EMPTYSECTION/);
            $nRAMnum++;
            push(@$RAMregion_aref, $_);
    }
    }
    else
    {
        foreach (@$ExeRegion_ref)
        {
            if($_ =~ /^EXTSRAM|^CACHED|^DYNAMIC|PAGETABLE/)
            {
                next if($_ =~ /DUMMY|SHOULDBE_EMPTYSECTION/);
                $nRAMnum++;
                push(@$RAMregion_aref, $_);
            }
        }
    }
    return ($nRAMnum);
}

#****************************************************************************
# Subroutine:  GetRAMBoundaryregion - to query the boundary regions in RAM
#              this function can be used to calculate RAM margin
# Parameters:  $SCATTERFILE = the path of scatter file
#              $MAKEFILE_ref = a Hash to contain MAKEFILE information
# Returns:     $LAST_CACHED_REGION  = the last cached region in RAM
#              $DUMMY_END   = the dummy_end region in RAM
#****************************************************************************
sub GetRAMBoundaryregion
{
    my ($SCATTERFILE, $MAKEFILE_ref) = (@_);
    my $bb = $MAKEFILE_ref->{"platform"};
    my $DUMMY_END = undef;
    my $LAST_CACHED_REGION  = undef;

    &GetScatInfo($SCATTERFILE);
    $DUMMY_END= &Gen_RegionName_EV_DUMMY_END_Base($bb);
    $LAST_CACHED_REGION = &Gen_RegionName_EV_LAST_CACHED_REGION($bb);

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
    my ($BB_PATH) = (@_);
    my $nROMsize = undef;
    my $CUSTOM_FLASH_H         = $BB_PATH . '/' . "custom_flash.h";
    my $FLASH_OPT_GEN_H        = $BB_PATH . '/' . "flash_opt_gen.h";
    my $isNOR = (&FileInfo::is_NOR() and !FileInfo::is_SmartPhone()) ? 1 : 0;
    
    if($isNOR)
    {
        open (FLASHH_HANDLE, "<$CUSTOM_FLASH_H") or &sysInfoProcSCAT_die("$CUSTOM_FLASH_H: file error!", __FILE__, __LINE__);
        while (<FLASHH_HANDLE>) {
           if (/^\s*\*\s+NOR_FLASH_SIZE\(Mb\):\s*(\w*)/)
           {
               $nROMsize = $1 * 1024 * 1024 / 8;
           }
    }
        close (FLASHH_HANDLE);
    }
    else
    {
        open (FLASHOPTGENH_HANDLE, "<$FLASH_OPT_GEN_H") or &sysInfoProcSCAT_die("$FLASH_OPT_GEN_H: file error!", __FILE__, __LINE__);
        while (<FLASHOPTGENH_HANDLE>) {
        if (/^#define NAND_TOTAL_SIZE\s*(\w*)/)
        {
              $nROMsize = $1 * 1024 * 1024;
        }
    }
        close (FLASHOPTGENH_HANDLE);
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
    my ($BB_PATH) = (@_);
    my $nROMsize = 0;
    my $CUSTOM_FEATURECONFIG_H         = $BB_PATH . '/' . "custom_FeatureConfig.h";
    my $CUSTOM_MEMORYDEVICE_H        = $BB_PATH . '/' . "custom_MemoryDevice.h";
    my $CUSTOM_FALSH_H        = $BB_PATH . '/' . "custom_flash.h";
    my $isNOR = (&FileInfo::is_NOR() and !FileInfo::is_SmartPhone()) ? 1 : 0;
    
    #code/data can not be executed in NAND flash
    return $nROMsize if(!$isNOR);

    my %FEATURE_CONFIG_Value;
    my %MEM_DEV_H_Value;
    &ParseDefinition($CUSTOM_FEATURECONFIG_H, \%FEATURE_CONFIG_Value);
    &ParseDefinition($CUSTOM_MEMORYDEVICE_H, \%MEM_DEV_H_Value);
    
    if (exists $FEATURE_CONFIG_Value{'PROJECT_EXPECTED_CODE_LIMIT'})
    {
        $nROMsize = hex($FEATURE_CONFIG_Value{'PROJECT_EXPECTED_CODE_LIMIT'});;
    }
    elsif (exists $MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_BASE_ADDRESS'})
    {
        $nROMsize = hex($MEM_DEV_H_Value{'NOR_BOOTING_NOR_FS_BASE_ADDRESS'});
    }
    else
    {
        my $flash_size = 0;
        my $sum_of_regions = 0;
        my $bisNORFDM5 = 0;
        my %FLASH_H_Value;
        my (@FLASH_H_Value_BLK_LIST, @FLASH_H_Value_REGION_LIST, @FLASH_H_Value_BANK_LIST);
        &ParseFlashInfo($CUSTOM_FALSH_H, \%FLASH_H_Value, \@FLASH_H_Value_BLK_LIST,
                                                  \@FLASH_H_Value_REGION_LIST,
                                                  \@FLASH_H_Value_BANK_LIST);
        $flash_size  = hex($FLASH_H_Value{'NOR_FLASH_DENSITY'});
        $bisNORFDM5 = ((defined $MEM_DEV_H_Value{'__NOR_FDM5__'}) && ($MEM_DEV_H_Value{'__NOR_FDM5__'} eq 'TRUE')) ? 1 : 0;
        $sum_of_regions = &Comp_lastBANKsize(\@FLASH_H_Value_REGION_LIST, \@FLASH_H_Value_BLK_LIST, $flash_size, $bisNORFDM5);
        $nROMsize = $flash_size - $sum_of_regions;
    }
    return $nROMsize;
}

#****************************************************************************
# Subroutine:  GetROMregion - to query all regions placed in ROM
# Parameters:  $BB_PATH
#              $SCATTERFILE = the path of scatter file
#              $ROMregion_href = a Hash reference to store ROM regions
#              $ROMregion_href->{regionName} = []
#              $MAKEFILE_ref = a Hash to contain MAKEFILE information
# Returns:     $nROMnum = the number of ROM regions
#****************************************************************************
sub GetROMregion
{
    my ($BB_path, $SCATTERFILE, $ROMregion_href, $MAKEFILE_ref) = (@_);
    my $CUSTOM_FEATURECONFIG_H = $BB_path . '/' . "custom_FeatureConfig.h";
    my $nROMnum = 0;
    my $isNOR = (&FileInfo::is_NOR() and !FileInfo::is_SmartPhone()) ? 1 : 0;

    return $nROMnum if(!$isNOR);

    &GetScatInfo($SCATTERFILE);
    my $ExeRegion_ref = $g_MAUIScat->GetAllExeRegion();
    foreach (@$ExeRegion_ref)
    {
        if($_ =~ /^ROM/)
        {
            $nROMnum++;
            $ROMregion_href -> {$_} = [];
        }
    }
    return ($nROMnum);
}

#****************************************************************************
# Subroutine:  Gen_RegionName_EV_DUMMY_END_Base - to query DUMMY_END region
# Parameters:  $bb = bb chip
# Returns:     $strRegionName = region name
#****************************************************************************
sub Gen_RegionName_EV_DUMMY_END_Base
{
    my ($bb) = (@_);
    my $strRegionName;
    if(1 == &sysUtil::is_mmu($bb))
    {
        $strRegionName = "CACHED_DUMMY_END";
        $strRegionName = $g_MAUIScat->SearchExeRegionName("DUMMY_END") if(! $g_MAUIScat->IsRegionExistent($strRegionName));
    }
    return $strRegionName;
}

#****************************************************************************
# Subroutine:  Gen_RegionName_EV_LAST_CACHED_REGION - to query the last cached region 
#              before dummy end
# Parameters:  $bb = bb chip
# Returns:     $strPreviousRegionName = region name
#****************************************************************************
sub Gen_RegionName_EV_LAST_CACHED_REGION
{
    my ($bb) = (@_);
    my $strPreviousRegionName;
    if(1 == &sysUtil::is_mmu($bb))
    {
        my $strRegionName = &Gen_RegionName_EV_DUMMY_END_Base($bb);
        $strPreviousRegionName = $g_MAUIScat->GetPreviousExeRegionName($strRegionName) if(defined $strRegionName);
        &sysInfoProcSCAT_die("Region Name can't be empty!", __FILE__, __LINE__) if(!defined $strPreviousRegionName);
    }
    return $strPreviousRegionName;
}
#****************************************************************************
# Subroutine: ParseFlashInfo - parse key definition in CUSTOM_FLASH_H
# Parameters: $strFilePath
#             $Hash_refResult Container) = a Hash reference to store the parse result
#             $BLK_LIST_aref = an Array reference to store Block info
#             $REGION_LIST_aref = an Array reference to store Region info
#             $BANK_LIST_aref = an Array reference to store Bank info
#****************************************************************************
sub ParseFlashInfo
{
    my ($strFilePath, $Hash_ref, $BLK_LIST_aref, $REGION_LIST_aref, $BANK_LIST_aref) = @_;
    open (FLASHC_HANDLE, "<$strFilePath") or &sysInfoProcSCAT_die("$strFilePath: file error!", __FILE__, __LINE__);
    while (<FLASHC_HANDLE>) {
       if (/^FLASH_REGIONINFO_VAR_MODIFIER\s+FlashBlockTBL\s+\S+/)
       {
          $Hash_ref->{'BlockTBLFlag'} ++;
       }
       elsif (defined $Hash_ref->{'BlockTBLFlag'})
       {
          $Hash_ref->{'BlockTBLTxt'} .= $_;
          # debug purpose
          # print $_;
          if (/\{\s*(\S+)\s*,\s*(\S+)\s*\}/)
          {
                push @$BLK_LIST_aref, $_;
          }
          delete $Hash_ref->{'BlockTBLFlag'} if (/^\s+EndBlockInfo\s+/);
       }
       elsif (/^FLASH_REGIONINFO_VAR_MODIFIER\s+FlashRegionInfo\s+oriRegionInfo\S+/)
       {
          $Hash_ref->{'RegionInfoFlag'} ++;
       }
       elsif (defined $Hash_ref->{'RegionInfoFlag'})
       {
          $Hash_ref->{'RegionInfoTxt'} .= $_;
          if (/\{\s*(\S+)\s*,\s*(\S+)\s*\}/)
          {
             push @$REGION_LIST_aref, $_;
          }
          delete $Hash_ref->{'RegionInfoFlag'} if (/^\s+EndoriRegionInfo\s+/);
       }
       elsif (/^static\s+NORBankInfo\s+oriBankInfo\S+/)
       {
          $Hash_ref->{'BankInfoFlag'} ++;
       }
       elsif (defined $Hash_ref->{'BankInfoFlag'})
       {
          $Hash_ref->{'BankInfoTxt'} .= $_;
          if (/\{\s*(\S+)\s*,\s*(\S+)\s*\}/)
          {
             push @$BANK_LIST_aref, $_;
          }
          delete $Hash_ref->{'BankInfoFlag'} if (/^\s+EndBankInfo\s+/);
       }
       elsif (/^\s*\*\s+NOR_FLASH_DENSITY:\s*(\w*)/)
       {
       	  $Hash_ref->{'NOR_FLASH_DENSITY'} = $1;
       }
       elsif (/^\s*\*\s+NOR_FLASH_SIZE\(Mb\):\s*(\w*)/)
       {
       	  $Hash_ref->{'NOR_FLASH_SIZE(Mb)'} = $1;
       }
    }
    close (FLASHC_HANDLE);
}

#****************************************************************************
# Subroutine: ParseDefinition - parse key definition in the input file
# Parameters: $strFilePath
#             $Hash_refResult Container) = a Hash reference to store the parse result
#****************************************************************************
sub ParseDefinition
{
    my ($strFilePath, $Hash_ref) = @_;
    open (MEMDEVH_HANDLE, "<$strFilePath") or &sysInfoProcSCAT_die("$strFilePath: file error!", __FILE__, __LINE__);
    while (<MEMDEVH_HANDLE>) {
        if (/^#define\s+(\w+)\s+\((\w*)\)/ || /^#define\s+(\w+)\s+(\w*)/)
        {
            my $option = $1;
            my $value  = $2;
            
            &sysInfoProcSCAT_die("$strFilePath: $option redefined in custom_MemoryDevice.h!", __FILE__, __LINE__) if defined($Hash_ref->{$option});
            if (!defined $value)
            {
                $Hash_ref->{$option} = 'TRUE';
            }
            else
            {
                $Hash_ref->{$option} = $value;
            }
        }
    }
    close (MEMDEVH_HANDLE);
}

#****************************************************************************
# Subroutine: ParseFlashInfo - parse key definition in CUSTOM_FLASH_H
# Parameters: $regions_aref = an Array reference to store Region info
#             $blk_aref = an Array reference to store Block info
#             $flash_size = Total flash size
#             $bisFDM5 = check if __NOR_FDM5__
# Returns   : $fat_space = the size of FAT
#****************************************************************************
sub Comp_lastBANKsize
{
    my ($regions_aref, $blk_aref, $flash_size , $bisFDM5)  = (@_);
    my @regions = @$regions_aref;
    my @blocks              = @$blk_aref;
    my $small_block_start   = $flash_size;
    my $sum_of_regions      = 0;
    my $fat_space           = 0;
    
    for (0..$#regions)
    {
        if ($regions[$_] =~ /\{(0x\w+),\s*(\d+)\}/) # match {0x20000, 7}
        {
            $sum_of_regions += hex($1) * $2;
        }
    }
    
    if (($#regions>=0) && $bisFDM5)
    {
        if ($blocks[$#blocks] =~ /\{(0x\w+),\s*(0x\w+)\}/) # match {0xFF0000,0x2000}
        {
            $small_block_start = hex($1);
        }
        $fat_space = $sum_of_regions - ($flash_size-$small_block_start);
    }
    else
    {
        $fat_space = $sum_of_regions;
    }
    return $fat_space;
}

#****************************************************************************
# Subroutine:  GetLdsInfo - to query Scat info by LdsInfo.pm
# Parameters:  $LDSFILE = lds file
#****************************************************************************
sub GetScatInfo
{
    my ($SCATTERFILE) = (@_);
    $g_MAUIScat = new scatInfo;
    $g_MAUIScat->ParseScatterFile($SCATTERFILE);
}

#****************************************************************************
# subroutine:  sysInfoProcSCAT_die
# sample code: (message, __FILE__, __LINE__)
# parameters:  $error_msg, $file, $line_no
#****************************************************************************
sub sysInfoProcSCAT_die
{
    my ($error_msg, $file, $line_no) = (@_);
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'SYSINFOPROCESSSCAT');
}