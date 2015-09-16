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
#*   ldsGenBL.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to generate memory layout
#*
#* Author:
#* -------
#*   Qmei Yang (mtk03726)
#*
#****************************************************************************/
use strict;
#****************************************************************************
# Included Modules
#****************************************************************************
BEGIN { push @INC, './tools/' }  # add additional library path
use ldsInfo;
use sysGenUtility;
use FileInfoParser;
use ldsFrame;
use File::Basename;
use tools::pack_dep_gen;
PrintDependModule();
#****************************************************************************
# 0 >>> exit;
#****************************************************************************
return 1;
#****************************************************************************
# Constants
#****************************************************************************

sub ldsGenBL_verno
{
    return "ldsGenBL m0.10 + ldsFrame.pm ".&ldsFrame::ldsFrame_verno." on MOLY";
                   # m0.10, 20130528 by mei, Support compiler option
                   # m0.09, 20121228 by mei, Refine NOR's meaning in VMAList.csv
                   # m0.08, 20120702 by mei, Support EWS
                   # m0.07, 20120702 by mei, Support GetBootingType()
                   # m0.06, 20120702 by mei, Support not to duplicate too many chips via SwitchToClonedChip()
                   # m0.05, 20120611 by mei, Replace EXT_BL_LOAD_MEM to EXT_BL_LOAD_MEM & fully support BL autogen 
                   # m0.04, 20120604 by mei, Make SetRegionList() more flexible
                   # m0.03, 20120528 by mei, Support path and filename case sensitive on Linux
                   # m0.02, 20120528 by mei, Replace BL_TCM to BL_LOAD_MEM
                   # m0.01, 20120512 by mei, initial version
}

#****************************************************************************
# Global Variables
#****************************************************************************
my $g_bb = undef;
my $g_nRamSize = undef;
my $g_BBFolder = undef;
my $g_MakeFilePath = undef;
my $g_strMainLDS = undef;
my $g_MakeFile_ref = undef;
my $g_nBLType = undef;
#****************************************************************************
# Input Parameters
#****************************************************************************



#****************************************************************************
# subroutines
#****************************************************************************

sub ldsGenBL_main
{
    ($g_bb, $g_nRamSize, $g_BBFolder, $g_MakeFilePath, $g_strMainLDS, my $strBLType) = @_;
    $g_bb = &sysUtil::SwitchToClonedChip($g_bb);
    $g_MakeFile_ref = &FileInfo::GetMakeFileRef($g_MakeFilePath);
    $g_nBLType = ($strBLType=~/EXT/)? ldsFrame::EXT_BL: ldsFrame::BL;
    my $strLayout = &GenLDSProcess($g_nBLType);
    return $strLayout;
}

sub GenLDSProcess
{
    my ($nType) = @_;
    &ldsFrame::CleanCallBackFunc();
    &ldsFrame::SetCallBackFunc("GetChip", \&GetChip);
    &ldsFrame::SetCallBackFunc("GetBootingType", \&GetBootingType);
    &ldsFrame::SetCallBackFunc("CollectMemorySetting", \&CollectMemorySetting);
    &ldsFrame::SetCallBackFunc("SetRegionList", \&SetRegionList);
    return &ldsFrame::GenLDS($nType);
}
sub GetChip  #CallBack func
{
    return $g_bb;
}
sub GetBootingType
{
    my $strBootingType = "NAND";
    $strBootingType = "NOR" if(&FileInfo::is_NonSPNOR() and !sysUtil::is_XIP_Shadowing($g_bb));
    return $strBootingType;
}
sub CollectMemorySetting  #CallBack func
{
    my ($BLMEMORYPath) = @_;
    # for getting main lds's memory information
    my $MAINlds = new ldsInfo;
    $MAINlds->ParseLinkerScript($g_strMainLDS);
    my $MainMemoryInfo_aref = $MAINlds->GetMEMROYInfo();
    my %MainMemory;
    map { $MainMemory{$_->[0]} = $_; } @$MainMemoryInfo_aref;
    
    # for getting bl lds's memory information
    my $BLMemory_aref = &ldsInfo::ParseMEMORY(&CommonUtil::GetFileContent($BLMEMORYPath));
    my ($nEXT_BL_LOAD_MEM_Base, $nEXT_BL_LOAD_MEM_Size) = &GetEXT_BL_LOAD_MEM($BLMemory_aref, \%MainMemory);
    
    my $nRamBase = 0;
    my %Setting = (RAM_BASE =>  &CommonUtil::Dec2Hex($nRamBase) ,
                   RAM_LEN  =>  &CommonUtil::Dec2Hex($g_nRamSize) ,
                   TCM_BASE =>  $MainMemory{TCM}->[1] ,
                   TCM_LEN  =>  $MainMemory{TCM}->[2] ,
                   ITCM_BASE => $MainMemory{ITCM}->[1],
                   ITCM_LEN  => $MainMemory{ITCM}->[2],
                   DTCM_BASE => $MainMemory{DTCM}->[1],
                   DTCM_LEN  => $MainMemory{DTCM}->[2],
                   BL_LOAD_MEM_LEN =>&CommonUtil::Dec2Hex(&GetBL_TCM_Base($BLMemory_aref, \%MainMemory)),
                   EXT_BL_LOAD_MEM_BASE => &CommonUtil::Dec2Hex($nEXT_BL_LOAD_MEM_Base),
                   EXT_BL_LOAD_MEM_LEN =>  &CommonUtil::Dec2Hex($nEXT_BL_LOAD_MEM_Size),
                   );
    return \%Setting;
}

sub GetBL_TCM_Base  #called by CollectMemorySetting()
{
    my ($BLMemory_aref, $MainMemory_href) = @_;
    my $nBL_TCM_Base = 0;;
    foreach (@$BLMemory_aref)
    {
        $nBL_TCM_Base = hex($_->[2]) if($_->[0] eq "BL_LOAD_MEM");
    }
    return hex($MainMemory_href->{TCM}->[1]) + hex($MainMemory_href->{TCM}->[2]) - $nBL_TCM_Base;
}

sub GetEXT_BL_LOAD_MEM  #called by CollectMemorySetting()
{
    my ($BLMemory_aref, $MainMemory_href) = @_;
    #NAND: ExtMem size - 1M
    my ($nEXT_BL_LOAD_MEM_Base, $nEXT_BL_LOAD_MEM_Size) = ($g_nRamSize - 1024*1024 , 1024*1024);
    if(&FileInfo::is_NonSPNOR() and !sysUtil::is_XIP_Shadowing($g_bb))
    {
        if(&FileInfo::is("ext_bl_update_support", "TRUE"))
        {
            $nEXT_BL_LOAD_MEM_Base = &sysUtil::query_cs1_addr($g_bb ,0, 1) + 72*1024;
            $nEXT_BL_LOAD_MEM_Size = 512*1024;
        }
        else
        {
            $nEXT_BL_LOAD_MEM_Base = (~0xf8000000)& hex($MainMemory_href->{EXT_BL_LOAD_MEM}->[1]);
            $nEXT_BL_LOAD_MEM_Size = hex($MainMemory_href->{EXT_BL_LOAD_MEM}->[2]);
        }
    }
    return ($nEXT_BL_LOAD_MEM_Base, $nEXT_BL_LOAD_MEM_Size);
}

sub SetRegionList  #CallBack func
{
    my ($BasicRegionList_ref, $Index_ref, $MEMORYSetting_href) = @_;
    my @RegionList;
    foreach my $item (@$BasicRegionList_ref)
    {
        my $strCondition = $item->[$Index_ref->{Condition}];
        next if($strCondition ne "" and 0 == &FileInfo::EvaluateFeatureOptionCondition($strCondition, $g_MakeFile_ref));
        my $strCompileOption = $item->[$Index_ref->{CompileOption}];
        next if($strCompileOption ne "" and 0 == BuildInfo::EvaluateCompileOption($strCompileOption));
        push @RegionList, $item;
    }
    #Parse VMAList
    my %VMAList;
    my $strVMAListPath = dirname(ldsFrame::GetPath(undef, ldsFrame::RegionList)) . "/VMAList.csv";
    &ParseVMAList($strVMAListPath, \%VMAList);
    
    for(my $i=0; $i<= $#RegionList; $i++)
    {
        my $nColumnCount = scalar(@{$RegionList[$i]});
        for(my $j=0; $j <= $nColumnCount; $j++)
        {
            while($RegionList[$i]->[$j] =~/\[(\w+)\]/)
            {
                my $strToReplace = $1;
                my $template = undef;
                no strict 'refs';
                if($strToReplace =~/^VMAList_(\w+)/)
                {
                    my $strName = $1;
                    $template = $VMAList{$strName} if(exists $VMAList{$strName})
                        or &sysUtil::sysgen_die("$strName doesn't exist in $strVMAListPath!", __FILE__, __LINE__);
                }
                else
                {
                    my $func = "Gen".uc($strToReplace);
                    $template = &{$func}($MEMORYSetting_href, \@RegionList, $Index_ref) if (exists &{$func})
                      or &sysUtil::sysgen_die("$func() doesn't exist!", __FILE__, __LINE__);
                }
                $RegionList[$i]->[$j] =~ s/\[$strToReplace\]/$template/g;
            }  
        }
    }
    return \@RegionList;
}
sub GenBL_LOAD_MEM_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref) = @_;
    return $MEMORYSetting_href->{BL_LOAD_MEM}->[0];
}

sub GenEXT_BL_LOAD_MEM_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref, $VAMList_href) = @_;
    return $MEMORYSetting_href->{EXT_BL_LOAD_MEM}->[0];
}

sub GenRAM_LEN # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref, $VAMList_href) = @_;
    return $MEMORYSetting_href->{RAM}->[1];
}
sub GenCS1_BASE # Fill in RegionList.csv
{
    return &CommonUtil::Dec2Hex(&sysUtil::query_cs1_addr($g_bb, 0, 1));
}

sub GenSYSRAM_BASE # Fill in RegionList.csv
{
    my ($MEMORYSetting_href, $RegionList_aref, $Index_ref, $VAMList_href) = @_;
    return $MEMORYSetting_href->{TCM}->[0];
}

sub ParseVMAList # called by SetRegionList()
{
    my ($strVMAListPath, $VMAList_href) = @_;
    my ($VMAList_aref, $Index_ref) = &CommonUtil::ParseCSV($strVMAListPath, undef);
    foreach my $item (@$VMAList_aref)
    {
        my $strChip = $item->[$Index_ref->{Chip}];
        my $strType = $item->[$Index_ref->{Type}];
        my $strVMA = $item->[$Index_ref->{VMA}];
        my $strCondition = $item->[$Index_ref->{FeatureOption}];
        my $bCondition = ($strCondition eq "" or 1 == &FileInfo::EvaluateFeatureOptionCondition($strCondition, $g_MakeFile_ref));
        my $bType = 1; 
        $bType = 0 if($strType =~ /^NOR$/i and !(&FileInfo::is_NonSPNOR() and !sysUtil::is_XIP_Shadowing($g_bb)));
        $bType = 0 if($strType =~ /NAND/i and &FileInfo::is_NonSPNOR());
        $bType = 0 if($strType =~ /XIP/i and !(&FileInfo::is_NonSPNOR() and sysUtil::is_XIP_Shadowing($g_bb)));
        #$bType = 0 if($strType =~ /^smartphone$/i and !&FileInfo::is_SmartPhone());
        if(($strChip eq "" or $strChip =~ /$g_bb/i) and $bType and $strVMA ne "" and $bCondition)
        {
            my $strRegionName = $item->[$Index_ref->{RegionName}];
            $VMAList_href->{$strRegionName} = $strVMA;
        }
    }
}
