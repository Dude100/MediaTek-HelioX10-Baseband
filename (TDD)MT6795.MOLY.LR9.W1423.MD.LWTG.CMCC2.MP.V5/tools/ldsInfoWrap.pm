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
#*   ldsInfoWrap.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to provide functions for parsing linker script and getting information
#*   It helps to cover linker script's insufficient syntax part.
#*   e.g. no Load View, no max size...etc
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
use CommonUtility;
use ldsInfo;
package ldsInfoWrap;
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# ldsInfoWrap Version
#****************************************************************************
sub ldsInfoWrap_verno
{
    return " m0.08";
           # m0.08 , 20140918 by Carl, Merge ATCM and BTCM as a single TCM for K2 and ROME
           # m0.07 , 20131023 by mei, Fix SECURE_RO's bug
           # m0.06 , 20130503 by mei, Export GetMEMROYInfo and GetMEMROYInfoByName from ldsInfo.pm
           # m0.05_From WR8 , 20121219 by mei, Support SECURE_RO
           # m0.05 , 20121002 by mei, Support MT7208 BTCM1
           # m0.04 , 20120911 by mei, Support setting Load Region
           # m0.03 , 20120724 by mei, Use MaxSize directly except getting TCMSize from MEMORY
           # m0.02 , 20120528 by mei, Support path and filename case sensitive on Linux
           # m0.01 , 20120528 by mei, initial version
}


sub new
{
    my $class = shift;
    my $self = {};
    my ($strFakeLoadRegionName) = @_;           
    #default value
    $self->{ldsInfo} = new ldsInfo;
    #default value
    $self->{ldsPath} = undef;
    $self->{MEMORY} = undef;   #=string
    $self->{SECTIONS} = undef; #=string
    
    $self->{FAKE_LRName} = $strFakeLoadRegionName;
    
    $self->{ExeRegion} = {};            #%g_ExeRegion; (start from 1) 
                                        # nIndex => [$1=Region name, $2=strBaseAddress, $3=strOffset, $4=nMaxSize, $5=\@Attribute]
    $self->{ExeRegionCount} = 0;        #$g_ExeRegionCount = 0;
    $self->{ExeRegionLookUpTable} = {}; #%g_ExeRegionLookUpTable; # RegionName -> Index

    $self->{MemoryView} = {};      # %g_MemoryView; (start from 1)
                                   # $RegionName => [$ExecutionView, $LoadView];
    $self->{InputSection} = {}; # $self->{InputSection}{$strRegionName} = @InputSections;
    #$self->{EXCLUDE_FILE} = {}; # $self->{EXCLUDE_FILE}{$strInputSection} = @files;
    $self->{RegionMap} = undef;
    bless $self, $class;
    return $self;
}
sub ParseLinkerScript
{
    my $self = shift;
    my ($strLDSPath) = @_;
    $self->{ldsInfo}->ParseLinkerScript($strLDSPath);
    #default value
    $self->{ldsPath} = $self->{ldsInfo}->{ldsPath};
    $self->{MEMORY} = $self->{ldsInfo}->{MEMORY};   #=string
    $self->{SECTIONS} = $self->{ldsInfo}->{SECTIONS}; #=string
    $self->{MEMORYInfo} = $self->{ldsInfo}->{MEMORYInfo}; #aref: [$strName, $strBase, $strLength]
    $self->{ExeRegion} = $self->{ldsInfo}->{ExeRegion};            #%g_ExeRegion; (start from 1) 
                                        # nIndex => [$1=Region name, $2=strBaseAddress, $3=strOffset, $4=nMaxSize, $5=\@Attribute]
    $self->{ExeRegionCount} = $self->{ldsInfo}->{ExeRegionCount};        #$g_ExeRegionCount = 0;
    $self->{ExeRegionLookUpTable} = $self->{ldsInfo}->{ExeRegionLookUpTable}; #%g_ExeRegionLookUpTable; # RegionName -> Index

    $self->{MemoryView} = $self->{ldsInfo}->{MemoryView};      # %g_MemoryView; (start from 1)
                                   # $RegionName => [$ExecutionView, $LoadView];
    $self->{InputSection} = $self->{ldsInfo}->{InputSection}; # $self->{InputSection}{$strRegionName} = @InputSections;

    $self->SetLoadRegion();
    $self->SetTCMSize(); #Set TCMSize due to linker script using MEMORY to limit TCM not ASSERT
}

sub GetMEMROYInfo
{
    my $self = shift;
    return $self->{ldsInfo}->GetMEMROYInfo();
}

sub GetMEMORYInfoByName
{
    my $self = shift;
    my ($strRegionName) = @_;
    return $self->{ldsInfo}->GetMEMORYInfoByName($strRegionName);
}

sub SetTCMSize
{  
    my $self = shift;
    my ($nITCMIndex, $nDTCMIndex, $nBTCM1Index) = ($self->{ExeRegionLookUpTable}{INTSRAM_CODE}, 
                        $self->{ExeRegionLookUpTable}{INTSRAM_DATA},
                        $self->{ExeRegionLookUpTable}{INTSRAM_DATA_B1});
    my ($nDTCM_Size, $nBTCM1_Size) = (undef, undef);
    my $bIDSeperated = 0;
    foreach (@{$self->{MEMORYInfo}})
    {
        if($_->[0] eq "TCM" or $_->[0] eq "ITCM")
        {
            $self->{ExeRegion}{$nITCMIndex}->[InfoIndex::MaxSize] = hex($_->[2]);
            # please sync this method with GenITCM_BASE() @ ldsGenLib.pl
            # please sync this method with GetDumpExeRegions() @ scatInfo.pm
            $bIDSeperated = 1 if($_->[0] eq "ITCM");
        }
        elsif($_->[0] eq "DTCM")
        {
            $nDTCM_Size = hex($_->[2]);
        }
        elsif($_->[0] eq "BTCM1")
        {
            $nBTCM1_Size = hex($_->[2]);
        }
    }
    $self->{ExeRegion}{$nDTCMIndex}->[InfoIndex::MaxSize] = $nDTCM_Size if($bIDSeperated == 1);
    $self->{ExeRegion}{$nBTCM1Index}->[InfoIndex::MaxSize] = $nBTCM1_Size if(exists $self->{ExeRegionLookUpTable}{INTSRAM_DATA_B1});
}
#****************************************************************************
# subroutine:  SetLoadRegion
#              helps to setting HardCode Load Region in linker script 
#              for prompting cfggen and binfile generation
# input:       N/A
# output:      N/A
#****************************************************************************
sub SetLoadRegion
{
    my $self = shift;
    my $strFakeLRName = $self->{FAKE_LRName};
    foreach (1..$self->{ExeRegionCount})
    {
        my $ER = $self->{ExeRegion}{$_};
        # nIndex => [$1=Region name, $2=strBaseAddress, $3=strOffset, $4=nMaxSize, $5=\@Attribute]
        my $strERName = $ER->[0];
        if($strERName =~ /BOOT_CERT/)
        {
            ++$self->{LoadRegionCount};
            $self->{LoadRegionLookUpTable}{$strERName} = $self->{LoadRegionCount};
            #%g_LoadRegionLookUpTable; # RegionName -> Index          
            $self->{LoadRegion}{$self->{LoadRegionCount}} = [$strERName, $ER->[1], $ER->[2], $ER->[3], $ER->[4], ()];
                                                     #   => [$1=Region name, $2=ImageLimit(Previous region) or strBaseAddress, $3=strOffset, $4=nMaxSize, $5=\@Attribute]
            push( @{$self->{RegionMap}{$strERName}}, $strERName);
        }
        elsif($strERName =~ /SECURE_RO/)
        {
            if(!exists $self->{RegionMap}{SECURE_RO})
            {
                ++$self->{LoadRegionCount};
                $self->{LoadRegionLookUpTable}{SECURE_RO} = $self->{LoadRegionCount};
                #%g_LoadRegionLookUpTable; # RegionName -> Index          
                $self->{LoadRegion}{$self->{LoadRegionCount}} = ["SECURE_RO", $ER->[1], $ER->[2], $ER->[3], $ER->[4], ()];
                                                         #   => [$1=Region name, $2=ImageLimit(Previous region) or strBaseAddress, $3=strOffset, $4=nMaxSize, $5=\@Attribute]
            }
            push( @{$self->{RegionMap}{SECURE_RO}}, $strERName);
        }		
        else
        {
            if(!exists $self->{LoadRegionLookUpTable}{$strFakeLRName})
            {
                ++$self->{LoadRegionCount};
                $self->{LoadRegionLookUpTable}{$strFakeLRName} = $self->{LoadRegionCount};
                $self->{LoadRegion}{$self->{LoadRegionCount}} = [$strFakeLRName, $ER->[1], $ER->[2], $ER->[3], $ER->[4], ()];
            }
            push( @{$self->{RegionMap}{$strFakeLRName}}, $strERName);
        }
    }
    #map{print "$_\n"}keys %{$self->{RegionMap}};
}

#****************************************************************************
# subroutine:  SearchExeRegionName
#              to get the first execution region name by keyword searching
# input:       Keyword
# output:      RegionName: undef means it's not existent
#****************************************************************************
sub SearchExeRegionName
{
    my $self = shift;
    my ($strKey) = @_;
    my $strRegion = undef;
    foreach my $strTemp (keys %{$self->{ExeRegionLookUpTable}})
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
# subroutine:  ldsWrap_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub ldsWrap_die
{
    my ($error_msg, $file, $line_no) = (@_);
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'ldsInfoWrap');    
}
