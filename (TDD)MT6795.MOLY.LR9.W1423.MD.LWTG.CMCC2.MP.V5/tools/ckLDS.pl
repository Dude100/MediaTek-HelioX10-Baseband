#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2012
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
#*   ckLDS.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to check memory layout
#*
#* Author:
#* -------
#*   Qmei Yang (mtk03726)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
BEGIN { push @INC, './tools/', './tools/MemoryUtility/' }  # add additional library path
use strict;
use File::Basename;
use FileInfoParser;
use CommonUtility;
use LinkerOutputParser;
use ldsInfo;
#****************************************************************************
# Constants
#****************************************************************************
#LDS Type
use constant MAIN          => 0;
use constant BL            => 1;
use constant EXT_BL        => 2;

# The following constant patterns are used in m notify for finding the corresponding owner.
# If any change, you have to sync with ErrorMsg Handler BM for the modification information.
use constant INVALID_OBJECT_LIST    => "- INVALID OBJECT LIST -";
use constant ERROR_HANDLING_SOP     => "- ERROR HANDLING SOP -";
#****************************************************************************
# VERNO
#****************************************************************************
my $CKLDS_VERNO = " m0.04";
                  # m0.04 by mei, Remove warning messages
                  # m0.03 by mei, Show invalid regions even if it contains no objlist
                  # m0.02 by mei, Parse linker script directly and output formal error message
                  # m0.01 by JI , initial version



#****************************************************************************
# Input Parameters and Global Variables
#****************************************************************************
my $phase            = $ARGV[0];
my $g_stop_build     = $ARGV[1];
my $g_LDSInputPath   = $ARGV[2];
my $map_file         = $ARGV[3];
my $FLASH_CFG_TMP    = $ARGV[4]; # XXX Not Used in current version
my $g_MakeFilePath   = $ARGV[5]; # XXX Not Used in current version
my $BB_FOLDER        = $ARGV[6]; # XXX Not Used in current version
my $DUMMY_LDS_ALLOW  = $ARGV[7]; # XXX Not Used in current version


#****************************************************************************
# 0 >>>  parse input parameters and decide ckscatter phase
#****************************************************************************
if ($phase == 1)
{
    #warn "ckLDS: phase 1 not implemented yet\n";
}
elsif ($phase == 2)
{
    &cklds_phase2($map_file, $g_LDSInputPath);
}
else
{
    &error_handler("Unsupported ckMemLayout command!");
}
    
exit 0;

#****************************************************************************
# 1 >>>  Phase 1
#****************************************************************************


#****************************************************************************
# 2 >>>  Phase 2
#****************************************************************************
sub cklds_phase2
{
    my ($LinkerOutput_MAP, $LDS) = @_;
    
    my $SYM_ERList = &ParseLinkerOutput_SYM($LinkerOutput_MAP);
    my $LDS_ERList = &ParseLinkerInput($LDS);
    my $SYMOddRegions_href = &CompareER($SYM_ERList, $LDS_ERList);
    
    if (keys(%$SYMOddRegions_href) > 0)
    {
        &LinkerOutputParser::FileParse($LinkerOutput_MAP);
        my $InvalidER_href = &GetOddObjList($SYMOddRegions_href);
        my $err_msg .= &Get_Template_Caution();
        $err_msg .= "------------------- INVALID SECTION LIST -------------------\n";
        $err_msg .= &Get_Template_DiffER_In_SYM_but_Not_in_LDS($InvalidER_href) . "\n";
        $err_msg .= "------------------".INVALID_OBJECT_LIST."-------------------\n";
        $err_msg .= &Get_Template_InvalidObjList($InvalidER_href);
        my $nLDSType = &GetLDSType($LDS);
        $err_msg .= &Get_Template_ErrorHandlingSOP($nLDSType);
        
        &error_handler($err_msg, 1);
    }
}


#****************************************************************************
# subroutine:  GetOddObjList
#              used in cklds_phase2()
# input :      Region_href
# return:      \%ObjList: {ER}=> \@ObjList
#****************************************************************************
sub GetOddObjList
{ # Check Linker Output Diff Regions , which object inside 
    my ($SYMOddRegions_href) = @_;
    my %OddObjList; # RegionName => [obj1, obj2...]
    foreach my $ER (sort keys %$SYMOddRegions_href)
    {
        my $Offender_objlist = &LinkerOutputParser::GetObjByExeRegion($ER);
        $OddObjList{$ER} = $Offender_objlist;
    }
    return \%OddObjList;
}

#****************************************************************************
# subroutine:  ParseLinkerInput: Retrieve Execution Regions from linker script
#              used in cklds_phase2()
# input :      strLDSFilePath
# return:      \@ER_List: Execution Region Array
#****************************************************************************
sub ParseLinkerInput
{ 
    my ($strldsFilePath) = @_;
    my $Info = new ldsInfo;
    $Info->ParseLinkerScript($strldsFilePath);
    my $ERList_aref = $Info->GetAllExeRegion();
    my $HiddenERList_aref = $Info->GetAllHiddenExeRegion();
    push (@$ERList_aref , @$HiddenERList_aref);
    &error_handler("Input($strldsFilePath) is not correct!") if (!defined $ERList_aref);
    #print "=================[LDS]=====================\n";
    #map {print "$_\n";} @$ERList_aref;
    #print "======================================\n";
    return $ERList_aref;
}

#****************************************************************************
# subroutine:  ParseLinkerOutput_SYM: Retrieve Execution Regions from  Linker Output Parser
#              used in cklds_phase2()
# input :      strMapFilePath
#              => it'll be transferred to sym file inside the function
# return:      \@ER_List: Execution Region Array
#****************************************************************************
sub ParseLinkerOutput_SYM
{ 
    my ($strMAPPath) = @_;
    my $ERList_aref = undef;
    my $sym_file = $strMAPPath;
    $sym_file =~ s/\.map$/\.sym/; #execution region information is not supported in LinkerOutputParser.pm while the input is .map
    &LinkerOutputParser::FileParse($sym_file);
    my $ERList_aref = &LinkerOutputParser::ListAllExeRegion();
    &error_handler("Input or LinkerOutputParser.pm is not correct!") if (!defined $ERList_aref);
    #print "=================[SYM]=====================\n";
    #map {print "$_\n";} @$ERList_aref;
    #print "======================================\n";
    return $ERList_aref;
}

#****************************************************************************
# subroutine:  CompareER: Compare 2 region list
#              used in cklds_phase2()
# input :      $SYM_ERList: an array reference 
#              $LDS_ERList: an array reference
# return:      \%Region List: a hash contains the regions in sym but not in lds
#****************************************************************************
sub CompareER
{
    my ($SYM_ERList, $LDS_ERList) = @_; # array_ref
    my %Out_left; #used to get SYM Left Strange Regions
    my @Out_Same;
    my %LDSERHash;
    map{$LDSERHash{$_} = 1;}@$LDS_ERList;
    foreach my $ER (@$SYM_ERList)
    {
        next if($ER eq "");
        if (exists $LDSERHash{$ER})
        {
            push @Out_Same, $ER;
            delete $LDSERHash{$ER};
        }
        else
        {
            $Out_left{$ER} = 1;
        }
    }
    &TrimDebugRegions(\%Out_left);
    #&Print_LDS_ERList_Not_In_SYM(\%LDSERHash);
    #&Print_SameER_In_SYM_and_LDS(\@Out_Same);
    return \%Out_left;
}

#****************************************************************************
# subroutine:  TrimDebugRegions: Normal GCC Regions for Debugging
#              used in CompareER()
# input :      $SYM_ERList: a hash reference contains regions in sym
# return:      N/A
#****************************************************************************
sub TrimDebugRegions
{
    my ($ERList_href) = @_;
    foreach my $ER (sort keys %$ERList_href)
    { #------ Normal GCC Regions for Debugging -----
        if ($ER =~ /^\.debug_/
         or $ER =~ /^\.ARM\.attributes/
         or $ER =~ /^\.comment/
         or $ER =~ /^\.stab/)
        {
            #print $ER, "\n";
            delete $ERList_href->{$ER};
        }
    }
}
#****************************************************************************
# subroutine:  GetLDSType
# input:       $strLDSPath : LDS FilePath
# return:      LDSType: MAIN, BL, EXT_BL
#****************************************************************************
sub GetLDSType
{
    my ($strLDSPath) = @_;
    my $strName = basename($strLDSPath);
    if($strName =~/ldsBL.*\_ext\./i)
    {
        return EXT_BL;    
    }
    elsif($strName =~/ldsBL.*\./i)
    {
        return BL;
    }
    else
    {
        return MAIN;
    }
}
#****************************************************************************
# subroutine:  Get_Template_DiffER_In_SYM_but_Not_in_LDS
# input:       $SYMER_href: a hash reference contains regions in sym but not in lds
# return:      Template shown in log file: regions in sym but not in lds
#****************************************************************************
sub Get_Template_DiffER_In_SYM_but_Not_in_LDS
{
    my ($SYMER_href) = @_;
    my $template;
    #------ Linker Output Found Strange Regions --------;
    map{$template .= "$_\n";}sort keys %$SYMER_href;
    return $template;
}

#****************************************************************************
# subroutine:  Get_Template_InvalidObjList
# input:       $OddList_href: a hash reference contains regions in sym but not in lds
# return:      Template shown in log file, e.g.
#             |1. Objects as below are wrapped in invalid section(C$$code):
#             |ex_hdlr_gcc.obj                                               
#             |stack_gcc.obj
#             |
#****************************************************************************
sub Get_Template_InvalidObjList
{
    my ($OddList_href) = @_;
    my $template;
    my $i=1;
    foreach my $ER(sort keys %$OddList_href)
    {
#####################################################################################
# The following pattern($ER) is used in m notify for finding the corresponding owner.
# If any change, you have to sync with ErrorMsg Handler BM for the modification information.
        $template .= "$i. Objects as below are wrapped in invalid section($ER):\n";
#####################################################################################
        map{ $template.= $_."\n";} @{$OddList_href->{$ER}};
        $template.= "\n";
        $i++;
    }
    return $template;
}

#****************************************************************************
# subroutine:  Get_Template_Caution
# return:      Template shown in log file to tell folks the risks
#****************************************************************************
sub Get_Template_Caution
{
    my $template = <<"__TEMPLATE";

=====================================================================
                       [!!Caution!!]
Some functions, variables or assembly codes 
in the following object list are wrapped around invalid sections,
which may cause bring-up failed due to region init not handling invalid regions.
Please fix it with Error Handling SOP as below.

__TEMPLATE
    return $template;
}


sub Print_LDS_ERList_Not_In_SYM
{
    my ($LDSER_href) = @_;
    print "------ LDSRegionList not in SYM -------\n";
    map{print "$_\n";}sort keys %$LDSER_href;
}

sub Print_SameER_In_SYM_and_LDS
{
    my ($ER_aref) = @_;
    print "------ The Same RegionList in SYM and LDS -------\n";
    map{print "$_\n";} @$ER_aref;
}
#****************************************************************************
# subroutine:  error_handler
# input :      $error_msg
#              $bPrintDirectly: undef or 0=using formal format to show error message, 
#                                        1=print error message directly without adding any other message
# return:      none
#****************************************************************************
sub error_handler
{
    my ($error_msg, $bPrintDirectly) = @_;
    my $todie = $g_stop_build;
    my ($pack_name, $file, $line_no) = caller;
    my $final_error_msg = ($bPrintDirectly) ? $error_msg: "CKMEMLAYOUT ERROR: \n$error_msg\nat $file line $line_no\n";
    print $final_error_msg if ($todie ne 'TRUE');
    die $final_error_msg if ($todie eq 'TRUE');
}


sub Get_Template_ErrorHandlingSOP
{
    my ($nType) = @_;
    my $title = ERROR_HANDLING_SOP;
    my $template= "-------------------$title--------------------\n";;
    my $strPath = &GetSOPPath($nType);
    if(-e $strPath)
    {
        $template .= &CommonUtil::GetFileContent($strPath) . "\n";
    }
    else
    {
        $template .= "Please refer to $strPath\n\n";
    }
    $template .= "-------------------------------------------------------------\n";
    return $template;
}

sub GetSOPPath
{
    my ($nType) = @_;
    my $strPath = "./custom/system/Template/XXX/InputSectionRule.txt";
    if($nType == MAIN)
    {
        $strPath =~ s/XXX/lds_config/;
    }
    elsif($nType == BL)
    {
        $strPath =~ s/XXX/BL_lds_config/;
    }
    elsif($nType == EXT_BL)
    {
        $strPath = ~s/XXX/EXT_BL_lds_config/;
    }
    return $strPath;
}