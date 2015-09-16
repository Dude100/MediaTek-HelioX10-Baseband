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
#*   ldsFrame.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to generate the frame of memory layout 
#*   and provides the flow of generation
#*  
#* Author:
#* -------
#*   Qmei Yang (mtk03726)
#*
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './tools/' }  # add additional library path
use ldsInfo;
use CommonUtility;
use sysGenUtility;
package ldsFrame;
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# ldsFrame Version
#****************************************************************************
sub ldsFrame_verno
{
    return " m0.28";
           # m0.28 , 20130913 by mei, Fix symbol bug
           # m0.27 , 20130605 by mei, Make input section file name more flexible in OVERLAY section
           # m0.26 , 20130115 by mei, Change Default csv name to Default.csv
           # m0.25 , 20130114 by mei, Set LDSType to be MAIN by default
           # m0.24 , 20130113 by mei, Support template getting from build folder first
           # m0.23 , 20121030 by mei, Support more flexible ASSERT in Action,
           #                          Support EndAction (to put Action in the end)
           # m0.22 , 20121029 by mei, Support MEMORY without counting reserved region
           # m0.21 , 20121020 by mei, Make addresses in OVERLAY region be 4 bytes aligned
           # m0.20 , 20121002 by mei, Make all lengths are 4 bytes aligned for region-init
           # m0.19 , 20120827 by mei, Support Head input sections
           # m0.18 , 20120817 by mei, Support SetMemorySetting() without calling callback if no need to replace
           # m0.17 , 20120816 by mei, Change symbol assignment in OVERLAY to fix ld's bug
           # m0.16 , 20120816 by mei, Support Input section with Common Block, Chip Block and DefaultChip Block
           # m0.15 , 20120727 by mei, Refine lds output format
           # m0.14 , 20120724 by mei, Support MaxSize ASSERT
           # m0.13 , 20120713 by mei, Support atomic Type(e.g. not accept //SectionFrame) 
           #                          Fix LoadAddress' bug
           #                          Support Default address(top and bottom) align 4 bytes
           # m0.12 , 20120712 by mei, Remove EWS since no need to add dependency in pm file
           # m0.11 , 20120710 by mei, Support input section got from chip.txt as well
           # m0.10 , 20120702 by mei, Support EWS
           # m0.09 , 20120702 by mei, Support Memory Setting with booting type via GetBootingType()
           # m0.08 , 20120625 by mei, Use scalar instead of $#
           # m0.07 , 20120615 by mei, Support using $# on Linux
           # m0.06 , 20120530 by mei, Support RegionList by chip
           # m0.05 , 20120530 by mei, Fix CleanCallBackFunc()'s bug
           # m0.04 , 20120528 by mei, Support path and filename case sensitive on Linux
           # m0.03 , 20120513 by mei, Support BLldsGen
           # m0.02 , 20120507 by mei, Fix ACTION behavior
           # m0.01 , 20120507 by mei, initial version
}
#****************************************************************************
# Constants
#****************************************************************************
#****************************************************************************
# Global Variables
#****************************************************************************
my %Func = ("CollectMemorySetting" => undef,
            "SetMemorySegment"     => undef, # not necessary
            "GetChip"              => undef,
            "SetRegionList"        => undef,
            "GetBootingType"       => undef,
            "GetCustomFolder"      => undef, # to get CustomFolder's template first
           );
my %g_MEMORYSetting;
my $g_nLDSType = 0; #default be MAIN
#****************************************************************************
# Input Parameters
#****************************************************************************
use constant BASIC         => 0;
use constant MEMORY        => 1;
use constant InputSections => 2;
use constant RegionList    => 3;
#LDS Type
use constant MAIN          => 0;
use constant BL            => 1;
use constant EXT_BL        => 2;
use constant FOTA          => 3;
#Input Section File Name
use constant COMMON_InputSection                   =>  "Common";
use constant ChipDependent_Default_InputSection    =>  "DefaultChip";
use constant HEAD_InputSection                     =>  "Head";
#****************************************************************************
# subroutines
#****************************************************************************
sub GetLDSType
{
    my %LDSFolderName = (0      => "lds_config",
                         1      => "BL_lds_config",
                         2      => "EXT_BL_lds_config",
                        );
    &ldsFrame_die("unsupport LDSType: $g_nLDSType \n", __FILE__, __LINE__) if(!exists $LDSFolderName{$g_nLDSType});
    return $LDSFolderName{$g_nLDSType};
}
#ldsFrame::GetPath("MT6280", ldsFrame::MEMORY)
#ldsFrame::GetPath("ROM", ldsFrame::InputSections)
#ldsFrame::GetPath("MT6280", ldsFrame::RegionList)
sub GetPath
{
    my ($strKey, $nType) = @_;
    my $strPath = undef;
    my $LDSFolderName = &GetLDSType();
    my $strDefaultSystemFolder = "./custom/system";
    my $strTemplateFolder = "$strDefaultSystemFolder/Template/$LDSFolderName/";
    my %PathMap = ("ldsMainFrame"      => "ldsTemplate/ldsMainFrame.txt",
                   "RegionList"        => "RegionConfig/",
                   "MEMORY"            => "ldsTemplate/MEMORY/",
                   "InputSections"     => "InputSections/",
                  );
    if($nType == BASIC)
    {
        $strPath = $strTemplateFolder . $PathMap{$strKey};
    }
    elsif($nType == MEMORY)
    {
        $strPath = $strTemplateFolder.$PathMap{MEMORY}.$strKey."_".&{$Func{GetBootingType}}().".txt" if(defined $Func{GetBootingType});
        $strPath = $strTemplateFolder.$PathMap{MEMORY}.$strKey.".txt" if(!-e $strPath);;
    }
    elsif($nType == RegionList)
    {
        $strPath = $strTemplateFolder.$PathMap{RegionList}.$strKey.".csv";
        $strPath = $strTemplateFolder.$PathMap{RegionList}."Default.csv" if(!-e $strPath);
        $strPath = $strTemplateFolder.$PathMap{RegionList}."RegionList.csv" if(!-e $strPath); # for backward compatible
    }
    elsif($nType == InputSections)
    {
        $strPath = $strTemplateFolder . $PathMap{InputSections}.$strKey."/";
    }
    else
    {
        &ldsFrame_die("[GetPath]Unsupport Type", __FILE__, __LINE__);
    }
    if(exists $Func{GetCustomFolder})
    {
        my $strCustomedFolder = &{$Func{GetCustomFolder}}();
        my $strCustomedPath = $strPath;
        $strCustomedPath =~  s/$strDefaultSystemFolder/$strCustomedFolder/;
        $strPath = $strCustomedPath if(-e $strCustomedPath);
    }
    return $strPath;
}



#****************************************************************************
# subroutine:  ProcessTemplate
# Input:       $strFilePath: the file to be processed
#              $strKeyFinding: e.g. ldsGen or AUTOGEN
# Output:      $content: the content after processing
# Description: if there is the pattern as [ldsGen_funcname], 
#              the whole pattern will be replaced by calling funcname().
#              if funcname() doesn't exist, it'll fail and report error.
#****************************************************************************
sub ProcessTemplate
{
    my ($strFilePath, $strKeyFinding) = @_;
    my $content;
    open (FILE_HANDLE, $strFilePath) or &ldsFrame_die("Cannot open $strFilePath\n", __FILE__, __LINE__);
    while(<FILE_HANDLE>)
    {
        my $strLine = $_;
        while ($strLine =~ /\[$strKeyFinding\_(\w+)\]/)
        {
            my $func = $1;
            my $template;
            {
                no strict 'refs';
                $template = &{$func}() if(exists &{$func}) 
                    or &ldsFrame_die("$func() doesn't exist!\n", __FILE__, __LINE__);
            }
            chomp($strLine);
            $strLine =~ s/\[$strKeyFinding\_$func\]/$template/g;
        }
        $content .= $strLine;
    }
    close FILE_HANDLE;
    return $content;
}

sub ProcessSection
{
    my ($strContent, $Info_ref, $Index_ref) = @_;
    my @lines = split(/\n/, $strContent);
    my $strResult;
    foreach my $strLine (@lines)
    {
        while ($strLine =~ /\[ldsGen_(\w+)\]/)
        {
            my $func = "Gen".$1;
            my $template;
            {
                no strict 'refs';
                
                $template = &{$func}($Info_ref, $Index_ref) if(exists &{$func})
                or &ldsFrame_die("[ProcessSection]$func() doesn't exist!\n", __FILE__, __LINE__);
            }
            $strLine =~ s/\[ldsGen_$1\]/$template/g;
        }
        $strResult .= $strLine . "\n";
    }
    return $strResult;
}

#****************************************************************************
sub GenLDS
{
    ($g_nLDSType) = @_;
    #Check CallBack functions
    
    my $strLayout = &ProcessTemplate( &GetPath("ldsMainFrame", BASIC) , "ldsGen");
    return $strLayout;
}

sub CleanCallBackFunc
{
    foreach (keys %Func)
    {
        delete $Func{$_};
    }
    %g_MEMORYSetting = ();
    $g_nLDSType = 0;
}
sub SetCallBackFunc
{
    my ($strKey, $func) = @_;
    $Func{$strKey} = $func;
}

#****************************************************************************
sub GenMEMORY
{
    my $MEMORYPath = &GetPath(&{$Func{GetChip}}(), MEMORY);
    my $MEMORYContent = &CommonUtil::GetFileContent($MEMORYPath);
    my $MEMORY_SEGMENT_aref = &ldsInfo::ParseMEMORY($MEMORYContent);
    my ($RegionList_ref, $Index_ref)= &PreProcessRegionList(undef);
    &SetMemorySetting($MEMORY_SEGMENT_aref, $MEMORYPath, $RegionList_ref, $Index_ref);
    &{$Func{SetMemorySegment}}($MEMORY_SEGMENT_aref) if(exists $Func{SetMemorySegment}); # for extension, not used now
    my $strMEMORY;
    foreach my $i (@$MEMORY_SEGMENT_aref)
    {
        $strMEMORY .= "    $i->[0] : ORIGIN = $i->[1], LENGTH = $i->[2]\n";
        my $nBase = eval($i->[1]);
        my $nLen = eval($i->[2]);
        $g_MEMORYSetting{$i->[0]} = [&CommonUtil::Dec2Hex($nBase), 
                                     &CommonUtil::Dec2Hex($nLen)];
    }
    return $strMEMORY;
}

sub SetMemorySetting
{
    my ($MEMORY_SEGMENT_aref, $MEMORYPath, $RegionList_ref, $Index_ref) = @_;
    if(exists $Func{CollectMemorySetting})
    {
        my $Setting = &{$Func{CollectMemorySetting}}($MEMORYPath, , $RegionList_ref, $Index_ref);
        foreach my $i (@$MEMORY_SEGMENT_aref)
        {
            while($i->[1] =~ /\[(\S+)\]/)
            {
                my $temp = $1;
                &ldsFrame_die("$1 in\n$MEMORYPath\n isn't set in CollectMemorySetting()!\n", __FILE__, __LINE__) if(!exists $Setting->{$1});
                $i->[1] =~ s/\[$temp\]/$Setting->{$temp}/g;
            }
            while($i->[2] =~ /\[(\S+)\]/)
            {
                my $temp = $1;
                &ldsFrame_die("$1 in\n$MEMORYPath\n isn't set in CollectMemorySetting()!\n", __FILE__, __LINE__) if(!exists $Setting->{$1});
                $i->[2] =~ s/\[$temp\]/$Setting->{$temp}/g;
            }
        }
    }
}

sub PreProcessRegionList
{
    my ($MEMORYSetting_href) = @_;
    my $RegionListPath = &GetPath(&{$Func{GetChip}}(), RegionList);
    my ($BasicRegionList_ref, $Index_ref) = &CommonUtil::ParseCSV($RegionListPath, undef);
    my $RegionList_ref = $BasicRegionList_ref; 
    $RegionList_ref = &{$Func{SetRegionList}}($BasicRegionList_ref, $Index_ref, $MEMORYSetting_href) 
                                                                      if(exists $Func{SetRegionList});
    return ($RegionList_ref, $Index_ref);
}

#****************************************************************************
sub GenSECTIONS
{
    my $strLayout;
    my ($RegionList_ref, $Index_ref) = &PreProcessRegionList(\%g_MEMORYSetting);
    &SetHints_Symbols_Nearby_InputSections($RegionList_ref, $Index_ref);
    my $LOADADDR_template;
    my $LengthSymbol_template;
    my $ASSERT_template;
    my $End_template;
    my $strPreviousType;
    my @OVERLAY_items;
    foreach my $item (@$RegionList_ref)
    {
        my $strType = $item->[$Index_ref->{Type}];
        if( $strType =~ /^OVERLAY$/i)
        {
            push @OVERLAY_items, $item;
        }
        elsif( $strType !~ /^OVERLAY$/i and $strPreviousType =~ /^OVERLAY$/i )
        {
            my ($template, $strLOADADDR, $strLengthSymbol)= &FillOVERLAYSectionFrame(\@OVERLAY_items, $Index_ref);
            $strLayout .=$template;
            $LOADADDR_template .= $strLOADADDR;
            $LengthSymbol_template .= $strLengthSymbol;
            @OVERLAY_items = ();
        }
        if( $strType =~ /^SectionFrame$/i)
        {
            $strLayout .= &ProcessSection(&Gen_TEMPLATE_SECTION(), $item, $Index_ref);
            $LOADADDR_template .= &Gen_TEMPLATE_LOADADDR($item, $Index_ref);
            $LengthSymbol_template .= &Gen_TEMPLATE_LengthSymbol($item, $Index_ref);
            $ASSERT_template .= &Gen_TEMPLATE_ASSERT($item, $Index_ref);
        }
        elsif($strType =~ /^ACTION$/i or $strType =~ /^ENDACTION$/i)
        {
            my $CMPLOption = $item->[$Index_ref->{CompileOption}];
            my $FeatureOption = $item->[$Index_ref->{Condition}];
            my @temp = map{ $_ if(($_ ne $strType) and ($_ ne $CMPLOption) and ($_ ne $FeatureOption)) } @$item;
            my $strACTION = &CommonUtil::ConnetString(\@temp, ",", undef);
            if($strACTION =~ /^ASSERT/ or $strACTION =~ /^\"\s*ASSERT/)
            {
                $strACTION =~ s/\"//g;
                $strACTION =~ s/\,\s*/\,\"/;
                $strACTION =~ s/\)/\"\)/;
            }
            $End_template .= "    $strACTION\n" if($strType=~/END/i);
            $strLayout    .= "    $strACTION\n" if($strType!~/END/i);
        }
        elsif($strType =~/^LinkerSymbol$/i)
        {
            $strLayout .= &FillLinkerSymbol($item, $Index_ref);
        }
        $strPreviousType = $strType;
    }
    $strLayout .= $LOADADDR_template . $LengthSymbol_template . $ASSERT_template . $End_template;
    return $strLayout;
}
sub FillLinkerSymbol  #Called by GenSECTIONS()
{
    my ($Info_ref, $Index_ref) = @_;
    my $template;
    my $AttributeIndex = $Index_ref->{Attribute};
    my $NameIndex = $Index_ref->{Name};
    if($Info_ref->[$AttributeIndex] =~ /(\S+)::(\S+)/)
    {
        my $strPostfix = $2;
        my $strPrefix = $1 =~ /EV/ ? "Image" : "Load";
        if($strPostfix =~ /ZIBase/i)
        {
            $template = 'Image$$' . $Info_ref->[$NameIndex] . '$$ZI$$Base';
        }
        elsif($strPostfix =~ /ZILength/i)
        {
            $template = 'Image$$' . $Info_ref->[$NameIndex] . '$$ZI$$Length';
        }
        elsif($strPostfix =~ /ZILimit/i)
        {
            $template = 'Image$$' . $Info_ref->[$NameIndex] . '$$ZI$$Limit';
        }
        elsif($strPostfix =~ /Base/i)
        {
            $template = $strPrefix . '$$' . $Info_ref->[$NameIndex] . '$$Base';
        }
        elsif($strPostfix =~ /Length/i)
        {
            $template = 'Image$$' . $Info_ref->[$NameIndex] . '$$Length';
        }
        elsif($strPostfix =~ /Limit/i)
        {
            $template = 'Image$$' . $Info_ref->[$NameIndex] . '$$Limit';
        }
        my $VMA = $Info_ref->[$Index_ref->{VMA}];
        return ' 'x4 . $template . " = $VMA;" . "\n";
    }
    return "";
}
sub FillOVERLAYSectionFrame  #Called by GenSECTIONS()
{
    my ($Infos_ref, $Index_ref) = @_;
    my ($OVERLAY_template, $strLOADADDR, $strLengthSymbol) = &Gen_TEMPLATE_OVERLAY($Infos_ref, $Index_ref);
    my $template = &ProcessSection($OVERLAY_template, $Infos_ref->[0], $Index_ref);
    return ($template, $strLOADADDR, $strLengthSymbol);
}
#****************************************************************************
sub GenBaseRegionName # Called by ProcessSection()
{
    my ($Info_ref, $Index_ref) = @_;
    my $strName = $Info_ref->[$Index_ref->{BaseRegion}] eq "" ? $Info_ref->[$Index_ref->{Name}]
                                                              : $Info_ref->[$Index_ref->{BaseRegion}];
    $strName =~ s/\#//g; #workaround because .xxx can't be a folder name or a file name
    return $strName;
}
sub GenRegionName  # Called by ProcessSection()
{
    my ($Info_ref, $Index_ref) = @_;
    my $strName = $Info_ref->[$Index_ref->{Name}];
    $strName =~ s/\#//g; #workaround because .xxx can't be a folder name or a file name
    return $strName;
}
sub GenVMA  # Called by ProcessSection()
{
    my ($Info_ref, $Index_ref) = @_;
    return $Info_ref->[$Index_ref->{VMA}];
}
sub GenLMA # Called by ProcessSection()
{
    my ($Info_ref, $Index_ref) = @_;
    my $strLMA = "";
    $strLMA = "AT($Info_ref->[$Index_ref->{LMA}])" if($Info_ref->[$Index_ref->{LMA}] ne "");
    return $strLMA;
}
sub GenRegionAttr  # Called by ProcessSection()
{
    my ($Info_ref, $Index_ref) = @_;
    my $strAttr = "";
    $strAttr =  "(NOLOAD)" if($Info_ref->[$Index_ref->{Attribute}] eq "ZI");
    return $strAttr;
}
sub GenInputSections  # Called by ProcessSection()
{
    my ($Info_ref, $Index_ref) = @_;
    my $RegionName = $Info_ref->[$Index_ref->{Name}];
    my $InputSectionFolder = &GetPath($RegionName, InputSections);
    my $InputSections;
    my $SpecificChipPath = $InputSectionFolder.&{$Func{GetChip}}().".txt";
    my $DefaultChipPath = $InputSectionFolder.ChipDependent_Default_InputSection.".txt";
    my $HeadPath = $InputSectionFolder.HEAD_InputSection.".txt";
    if(-e $HeadPath)
    {
        $InputSections = &CommonUtil::GetFileContent($HeadPath)."\n";
    }
    if(-e $SpecificChipPath)
    {
        $InputSections .= &CommonUtil::GetFileContent($SpecificChipPath)."\n";
    }
    elsif(-e $DefaultChipPath)
    {
        $InputSections .= &CommonUtil::GetFileContent($DefaultChipPath)."\n";
    }
    my $CommonPath = $InputSectionFolder.COMMON_InputSection.".txt";
    $InputSections .= &CommonUtil::GetFileContent($CommonPath);
    return $InputSections;
}
sub GenExecutionRegion  # Called by ProcessSection()
{
    my ($Info_ref, $Index_ref) = @_;
    my $ExecutionView = "";
    $ExecutionView = " > $Info_ref->[$Index_ref->{ExecutionView}]" if($Info_ref->[$Index_ref->{ExecutionView}] ne "");
    return $ExecutionView;
}
sub GenLoadRegion  # Called by ProcessSection()
{
    my ($Info_ref, $Index_ref) = @_;
    my $LoadView = "";
    $LoadView = " AT> $Info_ref->[$Index_ref->{LoadView}]" if($Info_ref->[$Index_ref->{LoadView}] ne "");
    return $LoadView;
}
sub GenALIGN # Called by ProcessSection()
{
    my ($Info_ref, $Index_ref) = @_;
    my $strALIGN = "";
    $strALIGN = "ALIGN(4)" if($Info_ref->[$Index_ref->{Type}] !~ /^OVERLAY$/i);
    $strALIGN = $Info_ref->[$Index_ref->{ALIGN}] if($Info_ref->[$Index_ref->{ALIGN}] ne "");
    return $strALIGN;
}

#****************************************************************************
sub InsertBasicHintSymbols #used by SetHints_Symbols_Nearby_InputSections
{
    my ($RegionList_ref, $Index_ref, $Hints_ref) = @_;
    $Index_ref->{Symbols} = keys %$Index_ref; 
    my $SymbolIndex = $Index_ref->{Symbols};
    for(my $i=0; $i < scalar(@$RegionList_ref); $i++)
    {
        my $item = $RegionList_ref->[$i];
        my $strType = $item->[$Index_ref->{Type}];
        if( $strType =~ /^SectionFrame$/)
        {
            my %Symbols = ("Base"=>0, "Limit" =>1, "ZIBase"=>1, "ZILimit"=>1);
            $item->[$SymbolIndex] = \%Symbols;
            my $BaseRegion = $item->[$Index_ref->{BaseRegion}];
            if($BaseRegion ne "")
            {
                $Hints_ref->{$BaseRegion} = [] if(!exists $Hints_ref->{$BaseRegion});
                push(@{$Hints_ref->{$BaseRegion}}, $item);
            }
        }
    }
}
sub SetHints_Symbols_Nearby_InputSections   #called by GenSECTIONS()
{
    my ($RegionList_ref, $Index_ref) = @_;
    my %Hints;
    # Step1. insert 4 symbols and collect BaseRegion Info. into %Hints
    &InsertBasicHintSymbols($RegionList_ref, $Index_ref, \%Hints);
    # Step2. Remove Symbols
    my $SymbolIndex = $Index_ref->{Symbols};
    my $AttributeIndex = $Index_ref->{Attribute};
    my $NameIndex = $Index_ref->{Name};
    foreach my $items (values %Hints)
    {
        next if(!@$items);
        for(my $i=0; $i< scalar(@$items); $i++)
        {
            my $CurrentItem = $items->[$i]->[$SymbolIndex];
            my $CurrentAttr = $items->[$i]->[$AttributeIndex];
            if($i==0)
            {
                my $NextAttr = $items->[$i+1]->[$AttributeIndex];
                delete $CurrentItem->{ZILimit} if($CurrentAttr ne "ZI");
                delete $CurrentItem->{ZIBase} if($CurrentAttr ne "ZI");
                delete $CurrentItem->{Limit} if($NextAttr ne "ZI");
            }
            elsif($i==(scalar(@$items)-1))            
            {
                my $PrevAttr = $items->[$i-1]->[$AttributeIndex];
                delete $CurrentItem->{Base};
                delete $CurrentItem->{Limit} if($CurrentAttr eq "ZI");
                delete $CurrentItem->{ZIBase} if($PrevAttr eq "ZI");
            }
            else
            {
                my $NextAttr = $items->[$i+1]->[$AttributeIndex];
                my $PrevAttr = $items->[$i-1]->[$AttributeIndex];
                delete $CurrentItem->{Base};
                delete $CurrentItem->{ZILimit};
                delete $CurrentItem->{Limit}  if(($CurrentAttr eq "ZI" and $PrevAttr ne "ZI")
                                              or ($CurrentAttr ne "ZI" and $NextAttr ne "ZI"));
                delete $CurrentItem->{ZIBase} if(($CurrentAttr eq "ZI" and $PrevAttr eq "ZI")
                                              or ($CurrentAttr ne "ZI"));
            }
        }
    }
}
#****************************************************************************
sub GenSymbol_Before_InputSections  # Gen_TEMPLATE_SECTION
{
    my ($Info_ref, $Index_ref) = @_;
    my $template;
    $template = &Gen_TEMPLATE_BaseSymbol($Info_ref, $Index_ref);
    if($Info_ref->[$Index_ref->{Attribute}] eq "ZI")
    {
        my $LimitSymbol = &Gen_TEMPLATE_LimitSymbol($Info_ref, $Index_ref);
        my $ZIBaseSymbol = &Gen_TEMPLATE_ZIBaseSymbol($Info_ref, $Index_ref);
        my $break = "\n" if($template ne "" and $LimitSymbol ne "");
        $template .= $break . $LimitSymbol;
        $break = "\n";
        $break = "" if($LimitSymbol eq "" or $ZIBaseSymbol eq "");
        $template .= $break . $ZIBaseSymbol;
    }
    return $template;
}
sub GenSymbol_After_InputSections   # Gen_TEMPLATE_SECTION
{
    my ($Info_ref, $Index_ref) = @_;
    my $template;
    my $break = "";
    if($Info_ref->[$Index_ref->{Attribute}] ne "ZI")
    {
        $template = &Gen_TEMPLATE_LimitSymbol($Info_ref, $Index_ref);
        my $ZIBaseSymbol = &Gen_TEMPLATE_ZIBaseSymbol($Info_ref, $Index_ref);
        $break= "\n" if($template ne "" and $ZIBaseSymbol ne "");
        $template .= $break. $ZIBaseSymbol;
        $break = "";
    }
    my $ZILimitSymbol = &Gen_TEMPLATE_ZILimitSymbol($Info_ref, $Index_ref);
    $break= "\n" if($template ne "" and $ZILimitSymbol ne "");
    $template .= $break . $ZILimitSymbol;
    return $template;
}
#****************************************************************************
sub GenRORWInputSections  # Gen_TEMPLATE_SECTION_IN_OVERLAY
{
    my ($Info_ref, $Index_ref) = @_;
    return &GenInputSectionsByAttribute($Info_ref, $Index_ref, sub{ my ($file) = @_; 
                                                                    return $file if($file !~/ZI/);} );
}
sub GenZIInputSections   # Gen_TEMPLATE_SECTION_IN_OVERLAY
{
    my ($Info_ref, $Index_ref) = @_;
    return &GenInputSectionsByAttribute($Info_ref, $Index_ref, sub{ my ($file) = @_; 
                                                                    return $file if($file =~/ZI/);} );
}
sub GenInputSectionsByAttribute  # used by GenRORWInputSections and GenZIInputSections 
{
    my ($Info_ref, $Index_ref, $expr) = @_;
    my $RegionName = $Info_ref->[$Index_ref->{Name}];
    my $InputSectionFolder = &GetPath($RegionName, InputSections);
    opendir( my $DIR, $InputSectionFolder) || &ldsFrame_die("Can't open $InputSectionFolder!", __FILE__, __LINE__);
    my @FileList = grep { $expr->($_)=~/\.txt$|.csv$/ && -f "$InputSectionFolder$_" } readdir( $DIR );
    closedir $DIR;
    my $InputSections = undef;
    if(scalar(@FileList)>0)
    {
        my ($strCommonPath, $strDefaultChipPath, $strChipDependentPath, $strHeadPath) = (undef, undef, undef, undef);
        foreach my $file (@FileList)
        {
            my $strChip = &{$Func{GetChip}}();
            my $filename = $file;
            $filename =~ s/\.\S+$//;
            my ($Common, $ChipDefault, $Head) = (COMMON_InputSection, ChipDependent_Default_InputSection, HEAD_InputSection);
            $strChipDependentPath = $InputSectionFolder.$file if($filename =~/($strChip)$/);
            $strCommonPath = $InputSectionFolder.$file if($filename =~/$Common/);
            $strDefaultChipPath = $InputSectionFolder.$file if($filename =~/$ChipDefault/);
            $strHeadPath = $InputSectionFolder.$file if($filename =~/$Head/);
        }
        if(-e $strHeadPath)
        {
            $InputSections = &CommonUtil::GetFileContent($strHeadPath)."\n";
        }
        if(-e $strChipDependentPath)
        {
            $InputSections .= &CommonUtil::GetFileContent($strChipDependentPath)."\n";
        }
        elsif(-e $strDefaultChipPath)
        {
            $InputSections .= &CommonUtil::GetFileContent($strDefaultChipPath)."\n";
        }
        $InputSections .= &CommonUtil::GetFileContent($strCommonPath);
    }
    return $InputSections;
}
#****************************************************************************
sub Gen_TEMPLATE_SECTION  # called by GenSECTIONS() and Gen_TEMPLATE_OVERLAY()
{
    my $template = <<"__TEMPLATE";
    [ldsGen_RegionName] [ldsGen_VMA] [ldsGen_RegionAttr] : [ldsGen_LMA] [ldsGen_ALIGN]
    {
[ldsGen_Symbol_Before_InputSections]
[ldsGen_InputSections]
        . = ALIGN(4);
[ldsGen_Symbol_After_InputSections]
    } [ldsGen_ExecutionRegion] [ldsGen_LoadRegion]
__TEMPLATE
}
sub Gen_TEMPLATE_SECTION_IN_OVERLAY  # called by Gen_TEMPLATE_OVERLAY()
{
    my $template = <<"__TEMPLATE";
        [ldsGen_RegionName]
        {
            Image\$\$[ldsGen_RegionName]\$\$Base = ADDR([ldsGen_RegionName]);
[ldsGen_RORWInputSections]
            . = ALIGN(4);
            Image\$\$[ldsGen_RegionName]\$\$Limit = .;
            Image\$\$[ldsGen_RegionName]\$\$ZI\$\$Base = .;
[ldsGen_ZIInputSections]
            . = ALIGN(4);
            Image\$\$[ldsGen_RegionName]\$\$ZI\$\$Limit = .;
        }
__TEMPLATE
}
sub Gen_TEMPLATE_OVERLAY  # called by FillOVERLAYSectionFrame()
{
    my ($Infos_ref, $Index_ref) = @_;
    my $LOADADDR_template;
    map { $LOADADDR_template .=  &Gen_TEMPLATE_LOADADDR($_, $Index_ref)} @$Infos_ref;
    my $strOVERLAY_SECTIONS;
    map {$strOVERLAY_SECTIONS .= &ProcessSection(&Gen_TEMPLATE_SECTION_IN_OVERLAY(), $_, $Index_ref)}(@$Infos_ref);
    my $LengthSymbol_template;
    map { $LengthSymbol_template .= &Gen_TEMPLATE_LengthSymbol($_, $Index_ref)} @$Infos_ref;

    my $template = <<"__TEMPLATE";
    OVERLAY [ldsGen_VMA] [ldsGen_RegionAttr] : [ldsGen_LMA] [ldsGen_ALIGN]
    {
$strOVERLAY_SECTIONS
    } [ldsGen_ExecutionRegion] [ldsGen_LoadRegion]
__TEMPLATE
    return ($template, $LOADADDR_template, $LengthSymbol_template);
}
sub Gen_TEMPLATE_LOADADDR  # Called by GenSECTIONS and Gen_TEMPLATE_OVERLAY()
{
    my ($Info_ref, $Index_ref) = @_;
    my $strBaseRegion =  $Info_ref->[$Index_ref->{BaseRegion}];
    my $strOrgRegion = $Info_ref->[$Index_ref->{Name}];
    return "" if($strBaseRegion ne "" and $strBaseRegion ne $strOrgRegion);
    
    my $strRegionName = &GenBaseRegionName($Info_ref, $Index_ref);
    my $template = <<"__TEMPLATE";
    Load\$\$$strRegionName\$\$Base = LOADADDR($strRegionName);
__TEMPLATE
    return $template; 
}
sub Gen_TEMPLATE_LengthSymbol  # Called by GenSECTIONS() and Gen_TEMPLATE_OVERLAY()
{
    my ($Info_ref, $Index_ref) = @_;
    my $strBaseRegion =  $Info_ref->[$Index_ref->{BaseRegion}];
    my $strOrgRegion = $Info_ref->[$Index_ref->{Name}];
    return "" if($strBaseRegion ne "" and $strBaseRegion ne $strOrgRegion);
    
    my $strRegionName = &GenBaseRegionName($Info_ref, $Index_ref);
    my $template = <<"__TEMPLATE";
    Image\$\$$strRegionName\$\$Length = Image\$\$$strRegionName\$\$Limit - Image\$\$$strRegionName\$\$Base;
    Image\$\$$strRegionName\$\$ZI\$\$Length = Image\$\$$strRegionName\$\$ZI\$\$Limit - Image\$\$$strRegionName\$\$ZI\$\$Base;
__TEMPLATE
    return $template;
}
sub Gen_TEMPLATE_ASSERT
{
    my ($Info_ref, $Index_ref) = @_;
    my $strBaseRegion =  $Info_ref->[$Index_ref->{BaseRegion}];
    my $strOrgRegion = $Info_ref->[$Index_ref->{Name}];
    my $strMaxSize = $Info_ref->[$Index_ref->{MaxSize}];
    return "" if(($strBaseRegion ne "" and $strBaseRegion ne $strOrgRegion) or $strMaxSize eq "");
    
    my $strRegionName = &GenBaseRegionName($Info_ref, $Index_ref);
    my $ERRTitle = genERR::SYSERR_1_2;
    my $template = <<"__TEMPLATE";
    ASSERT( (Image\$\$$strRegionName\$\$Length + Image\$\$$strRegionName\$\$ZI\$\$Length ) <= $strMaxSize , \"$ERRTitle\Sizes of $strRegionName exceed $strMaxSize\")
__TEMPLATE
    return $template;
}
sub Gen_TEMPLATE_BaseSymbol  # Called by GenSymbol_Before_InputSections()
{
    my ($Info_ref, $Index_ref) = @_;
    return "" if(!exists $Info_ref->[$Index_ref->{Symbols}]->{Base});
    my $strRegionName = &GenBaseRegionName($Info_ref, $Index_ref);
    return ' ' x 8 . "Image\$\$$strRegionName\$\$Base = . ;";
}
sub Gen_TEMPLATE_LimitSymbol  # Called by GenSymbol_(Before/After)_InputSections()
{
    my ($Info_ref, $Index_ref) = @_;
    return "" if(!exists $Info_ref->[$Index_ref->{Symbols}]->{Limit});
    my $strRegionName = &GenBaseRegionName($Info_ref, $Index_ref);
    return ' ' x 8 . "Image\$\$$strRegionName\$\$Limit = . ;";
}
sub Gen_TEMPLATE_ZIBaseSymbol   # Called by GenSymbol_(Before/After)_InputSections()
{
    my ($Info_ref, $Index_ref) = @_;
    return "" if(!exists $Info_ref->[$Index_ref->{Symbols}]->{ZIBase});
    my $strRegionName = &GenBaseRegionName($Info_ref, $Index_ref);
    return ' ' x 8 . "Image\$\$$strRegionName\$\$ZI\$\$Base = . ;";
}
sub Gen_TEMPLATE_ZILimitSymbol  # Called by GenSymbol_After_InputSections()
{
    my ($Info_ref, $Index_ref) = @_;
    return "" if(!exists $Info_ref->[$Index_ref->{Symbols}]->{ZILimit});
    my $strRegionName = &GenBaseRegionName($Info_ref, $Index_ref);
    return ' ' x 8 . "Image\$\$$strRegionName\$\$ZI\$\$Limit = . ;";
}

#****************************************************************************
# subroutine:  ldsFrame_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub ldsFrame_die
{
    my ($error_msg, $file, $line_no) = (@_);
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'ldsFrame');    
}
