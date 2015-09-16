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
#*   ldsInfo.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to parse LinkerScript
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
use sysGenUtility;
#****************************************************************************
# Constants
#****************************************************************************
package Region;
use constant Base         => 0;
use constant MaxSize      => 1;
use constant Attribute    => 2;
use constant Offset       => 3;

package InfoIndex;
use constant Base         => 1;
use constant MaxSize      => 3;
use constant Attribute    => 4;
use constant Offset       => 2;

package ldsInfo;
#****************************************************************************
# Global Variables
#****************************************************************************
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# ldsInfo Version
#****************************************************************************
sub ldsInfo_verno
{
    return " m0.11";
           # m0.11 , 20130605 by mei, Support to strip comments in MEMORY
           # m0.10 , 20130503 by mei, Add GetMEMORYInfoByName()
           # m0.09 , 20121125 by mei, Support ParseSECTIONS() to skip other kinds of ASSERT
           # m0.08 , 20121029 by mei, Support more flexible MEMORY format
           # m0.07 , 20121002 by mei, Support ORIGIN
           # m0.06 , 20120921 by mei, Support parsing hidden execution regions(the regions aint shown in linker symbol)
           # m0.05 , 20120724 by mei, Support parsing MaxSize by ASSERT in linker script
           # m0.04 , 20120528 by mei, Support path and filename case sensitive on Linux
           # m0.03 , 20120522 by mei, support sysgen2
           # m0.02 , 20120513 by mei, support partially parsing Linker Script
           # m0.01 , 20120504 by mei, initial version
}

sub ParseSECTIONS
{
    my $self = shift;
    my ($strInput) = @_;
    my @lines = split(/\n/, $strInput);
    map {$self->parse_linker_symbol($_)} @lines;
    my ($strPrvRegionName, $strPrvBase, $nOVERLAYLine) = (undef, undef, 0);
    my @OVERLAY;
    foreach my $strLine (@lines) 
    {
        next if($strLine =~ /PROVIDE/);
        if($strLine =~ /ASSERT/ and $strLine =~ /Sizes\s*of\s*(\S+)\s*exceed\s*(\w+)/ )
        {
            my ($strRegionName, $nMaxSize) = ($1, hex($2));
            my $nIndex = $self->{ExeRegionLookUpTable}{$strRegionName};
            $self->{ExeRegion}->{$nIndex}[3] = $nMaxSize;
        }
        elsif($strLine =~ /ASSERT/)
        {
            next;
        }
        elsif(($strLine =~ /(\S+)\s+(\S+)*\s*\(NOLOAD\)\s*\:(.*)/ 
          or $strLine =~ /(\S+)\s+(\S+)*\s*\:(.*)/)
          and $strLine !~ /OVERLAY/)
        {
            my ($strRegionName, $strBase, $strLast) = ($1, $2, $3);
            if($strPrvRegionName eq "OVERLAY")
            {
                $self->parse_overlay(\@OVERLAY);
                $nOVERLAYLine = 0;
                @OVERLAY = ();
            }
            if($strBase =~ /ALIGN|\d+/)
            {
                my $nIndex = $self->{ExeRegionLookUpTable}{$strRegionName};
                $self->{ExeRegion}->{$nIndex}[1] = $strBase;
                $self->{ExeRegion}->{$nIndex}[2] = undef;
            }
            elsif($strBase =~ /ORIGIN\(\s*(\S+)\s*\)/)
            {
                my $nIndex = $self->{ExeRegionLookUpTable}{$strRegionName};
                my $ORIGIN;
                foreach my $aref (@{$self->{MEMORYInfo}})
                {
                    if($1 eq $aref->[0])
                    {
                        $ORIGIN = $aref->[1];
                        last;    
                    }    
                }
                $self->{ExeRegion}->{$nIndex}[1] = $ORIGIN;
                $self->{ExeRegion}->{$nIndex}[2] = undef;
            }
            else
            {   # used in set_hiddenERs()
                $strRegionName =~ s/\///g;
                my $nIndex = $self->{ExeRegionLookUpTable}{$strPrvRegionName};
                $self->{HiddenExeRegion}->{$strRegionName} = [$nIndex, $strPrvRegionName];
            }
            if($strLast =~ /\{/)
            {
                $strLast =~ s/.*\{//;
                $self->parse_input_section($strLast, $strRegionName);
            }
            $strPrvRegionName = $strRegionName;
        }
        elsif($strLine =~ /OVERLAY/ or ($nOVERLAYLine >0 and $strPrvRegionName eq "OVERLAY"))
        {# parse overlay
            $strPrvRegionName = "OVERLAY";
            push(@OVERLAY, $strLine);
            $nOVERLAYLine++ if($strLine =~ /OVERLAY/);
            $nOVERLAYLine++ if($strLine =~/\{/);
            $nOVERLAYLine-- if($strLine =~/\}/);
            next;
        }
        elsif($strLine !~ /\=|\;/)
        {# parse input section
            $self->parse_input_section($strLine, $strPrvRegionName);
        }
        $self->parse_memory_view($strLine, $strPrvRegionName);
    }
    $self->set_hiddenERs();
}
sub parse_overlay  #ParseSECTIONS
{
    my $self = shift;
    my ($lines_aref) = @_;
    my $strCurRegionName = undef;
    my $strOVERLAYBase;
    my @OverlayRegion;
    foreach my $strLine (@$lines_aref)
    {
        if($strLine =~ /OVERLAY\s*(\S*)\s*:/)
        {
            $strOVERLAYBase = $1;
            next;
        }
        elsif($strLine =~ /^\s*(\S+)\s*\{/ or ($strLine =~ /^\s*(\S+)/ and $strLine !~ /\{|\}|\*|\(|\)|\=|\;/))
        {
            my $strRegionName = $1;
            $strRegionName =~ s/\s|\{|\}//g;
            next if($strRegionName eq "");
            $strCurRegionName = $strRegionName;
            if(exists $self->{ExeRegionLookUpTable}{$strRegionName})
            {
                my $nIndex = $self->{ExeRegionLookUpTable}{$strRegionName};
                $self->{ExeRegion}->{$nIndex}[1] = $strOVERLAYBase;
                $self->{ExeRegion}->{$nIndex}[2] = undef;
                $self->{ExeRegion}->{$nIndex}[4] = ["OVERLAY"];
                push (@OverlayRegion, $strRegionName);
            }
        }
        elsif($strLine =~ /\>/)
        {
            map{ $self->parse_memory_view($strLine, $_);}@OverlayRegion;
        }
        elsif($strLine !~ /\=|\;/ and defined $strCurRegionName)
        {
            $self->parse_input_section($strLine, $strCurRegionName);
        }
    }
}
sub parse_input_section #used by ParseSECTIONS and parse_overlay
{
    my $self = shift;
    my ($strLine, $strRegionName)= @_;
    $strLine =~ s/.*\{|\}.*//;
    
    #remove empty string
    my $temp = $strLine;
    $temp =~ s/\s//g; 
    return if($temp eq "");
    
    if($strLine =~ /\{*\s*(\S+)\s*\((.+)\)(\}*)/)
    {
        push(@{$self->{InputSection}{$strRegionName}}, "$1 ($2)");
    }
    elsif( $strLine !~/\;|\=/)
    {
        push(@{$self->{InputSection}{$strRegionName}}, $strLine);
    }
}
sub parse_linker_symbol #used by ParseSECTIONS
{
    my $self = shift;
    my ($strLine) = @_;
    if( $strLine =~ /Image\$\$(\S+)\$\$ZI\$\$(\S+)\s*\=\s*(\S+|\.)\s*\;/ or
        $strLine =~ /Image\$\$(\S+)\$\$(\S+)\s*\=\s*\s*(\S+|\.)\s*\;/)
    {
        my ($strRegionName, $strBase, $strOffset, $nMaxSize, @Attr) = ($1, undef, "+0x0", undef, ());
        my ($strIndexName, $strInput) = ($2, $3);
        if($strIndexName =~ /Base/ and $strInput !~ /\s+|\./)
        {
            $strBase = $strInput;
            $strOffset = undef;
        }
        if($strIndexName =~ /Length/ and $strInput =~ /\d+/)
        {
            $nMaxSize = hex($strInput) ;
        }
        if(!exists $self->{ExeRegionLookUpTable}{$strRegionName})
        {
            $self->{ExeRegion}->{++$self->{ExeRegionCount}} = [$strRegionName, $strBase, $strOffset, $nMaxSize, \@Attr];
            $self->{ExeRegionLookUpTable}{$strRegionName} = $self->{ExeRegionCount};
        }
        else
        {
            if(defined $nMaxSize)
            {
                my $nIndex = $self->{ExeRegionLookUpTable}{$strRegionName};
                $self->{ExeRegion}->{$nIndex}[3] = $nMaxSize;
            }
        }
    }
}
sub parse_memory_view  #used by ParseSECTIONS and parse_overlay
{
    my $self = shift;
    my ($strLine, $strRegionName) = @_;
    if($strLine =~ /\>\s*(\S+)\s*AT\s*\>\s*(\S+)/)
    {
        $self->{MemoryView}{$strRegionName} = [$1, $2];
    }
    elsif($strLine =~ /AT\s*\>\s*(\S+)/)
    {
        $self->{MemoryView}{$strRegionName} = ["", $1];
    }
    elsif($strLine =~ /\>\s*(\S+)/)
    {
        $self->{MemoryView}{$strRegionName} = [$1, ""];
    }
}
sub set_hiddenERs
{
    my $self = shift;
    foreach my $key (keys %{$self->{HiddenExeRegion}})
    {
        if(exists $self->{ExeRegionLookUpTable}->{$key})
        {
            delete $self->{HiddenExeRegion}->{$key};
        }    
    }
}

sub ParseMEMORY
{
    my ($strMEMORY) = @_;
    #strip comments
    $strMEMORY =~s#/\*[^*]*\*+([^/*][^*]*\*+)*/|([^/"']*("[^"\\]*(\\[\d\D][^"\\]*)*"[^/"']*|'[^'\\]*(\\[\d\D][^'\\]*)*'[^/"']*|/+[^*/][^/"']*)*)#$2#g;
    my @MemoryInfo;
    my @lines = split(/\n/, $strMEMORY);
    foreach my $line (@lines) 
    {
        my ($strName, $strBase, $strLength) = &ParseMEMORYLine($line);
        push @MemoryInfo, [$strName, $strBase, $strLength] if(defined $strName);
    }
    return \@MemoryInfo;
}
sub ParseMEMORYLine
{
    my ($strLine) = @_;
    my ($strName, $strBase, $strLength) = (undef, undef, undef);
    my @org = ("ORIGIN", "org", "o");
    my @len = ("LENGTH", "len", "l");
    my $bFind = 0;
    foreach my $o (@org)
    {
        foreach my $l (@len)
        {
            if($strLine =~ /\s*(\S+)\s*:\s*$o\s*\=\s*(.+)\s*,\s*$l\s*\=\s*(.+)/)
            {
                ($strName, $strBase, $strLength) = ($1, $2, $3);
                $bFind = 1; last;
            }
        }
        last if($bFind==1);
    }
    return ($strName, $strBase, $strLength);
}
sub new
{
    my $class = shift;
    my $self = {};
    #default value
    $self->{ldsPath} = undef;
    $self->{MEMORY} = undef;   #=string
    $self->{SECTIONS} = undef; #=string
    $self->{MEMORYInfo} = undef; #aref: [$strName, $strBase, $strLength]
    
    $self->{ExeRegion} = {};            #%g_ExeRegion; (start from 1) 
                                        # nIndex => [$1=Region name, $2=strBaseAddress, $3=strOffset, $4=nMaxSize, $5=\@Attribute]
    $self->{ExeRegionCount} = 0;        #$g_ExeRegionCount = 0;
    $self->{ExeRegionLookUpTable} = {}; #%g_ExeRegionLookUpTable; # RegionName -> Index
    $self->{HiddenExeRegion} = {};        #%HiddenExeRegion = RegionName => [$nPrvERIndex, $strPrvERName];

    $self->{MemoryView} = {};      # %g_MemoryView; (start from 1)
                                   # $RegionName => [$ExecutionView, $LoadView];
    $self->{InputSection} = {}; # $self->{InputSection}{$strRegionName} = @InputSections;
    #$self->{EXCLUDE_FILE} = {}; # $self->{EXCLUDE_FILE}{$strInputSection} = @files;
    bless $self, $class;
    return $self;
}

sub ParseLinkerScript
{
    my $self = shift;
    my ($ldsPath) = @_;
    if(defined $ldsPath and -e $ldsPath)
    {
        open (FILE_HANDLE, "<$ldsPath") or &lds_die("$ldsPath: file error!", __FILE__, __LINE__);
        my $strStart = undef;
        while (<FILE_HANDLE>) 
        {
            if(/^MEMORY/)
            {
                $strStart = "MEMORY";
            }
            elsif(/^SECTIONS/)
            {
                $strStart = "SECTIONS";
            }
            elsif(/^}/)
            {
                undef $strStart;    
            }
            elsif($_ !~ /^{/ and defined $strStart)
            {
                $self->{$strStart} .= $_;
            }
        }
        close FILE_HANDLE;
        #strip comments
        $self->{MEMORY} =~s#/\*[^*]*\*+([^/*][^*]*\*+)*/|([^/"']*("[^"\\]*(\\[\d\D][^"\\]*)*"[^/"']*|'[^'\\]*(\\[\d\D][^'\\]*)*'[^/"']*|/+[^*/][^/"']*)*)#$2#g;
        $self->{SECTIONS} =~s#/\*[^*]*\*+([^/*][^*]*\*+)*/|([^/"']*("[^"\\]*(\\[\d\D][^"\\]*)*"[^/"']*|'[^'\\]*(\\[\d\D][^'\\]*)*'[^/"']*|/+[^*/][^/"']*)*)#$2#g;
        $self->{MEMORYInfo} = &ParseMEMORY($self->{MEMORY});
        &EvalMemory($self->{MEMORYInfo});
        $self->ParseSECTIONS($self->{SECTIONS});
    }
    else
    {
        &lds_die("LinkerScript Path($ldsPath) doesn't exist", __FILE__, __LINE__);   
    }
}

sub EvalMemory
{
    my ($MEMORYInfo_aref) = @_;
    foreach my $item (@$MEMORYInfo_aref)
    {
        my $nBase = eval($item->[1]);
        my $nLen = eval($item->[2]);
        $item->[1] = &CommonUtil::Dec2Hex($nBase);
        $item->[2] = &CommonUtil::Dec2Hex($nLen);
    }
}

sub GetMEMROYInfo
{
    my $self = shift;
    return $self->{MEMORYInfo};
}

sub GetMEMORYInfoByName
{
    my $self = shift;
    my ($strRegionName) = @_;
    my ($strBase, $strLen) = (undef, undef);
    my $MEMORYInfo_aref = $self->{MEMORYInfo};
    foreach my $aref (@$MEMORYInfo_aref)
    {
        if($strRegionName eq $aref->[0])
        {
            $strBase = $aref->[1];
            $strLen = $aref->[2];
            last;
        }    
    }
    return ($strBase, $strLen);
}

sub ListMemoryView
{
    my $self = shift;
    foreach my $item (keys %{$self->{MemoryView}})
    {
        print "[$item]\n";
        map {print "$_  "}@{$self->{MemoryView}{$item}};
        print "\n";
    }
}
sub ListInputSections
{
    my $self = shift;
    foreach my $item (keys %{$self->{InputSection}})
    {
        print "[$item]\n";
        map {print "$_\n"}@{$self->{InputSection}{$item}};
        print "\n\n";
    }
}

#****************************************************************************
# subroutine:  GetAllExeRegion
# input:       x
# output:      an array reference of execution region 
#****************************************************************************
sub GetAllExeRegion
{
    my $self = shift;
    my @ExeRegions;
    foreach my $i (1 .. $self->{ExeRegionCount})
    {
        push(@ExeRegions, $self->{ExeRegion}{$i}->[0]);
    }
    return \@ExeRegions;
}
#****************************************************************************
# subroutine:  GetAllHiddenExeRegion
# purpose:     To get hidden 
# input:       x
# output:      an array reference of execution region 
#****************************************************************************
sub GetAllHiddenExeRegion
{
    my $self = shift;
    my $href = $self->{HiddenExeRegion};
    my @ExeRegions = sort { $href->{$a}->[0] <=> $href->{$b}->[0]} keys %$href;
    #map{print "[$_]".$href->{$_}->[0]."\n";} @ExeRegions;
    return \@ExeRegions;
}
#****************************************************************************
# subroutine:  GetRegionInfo - Get Region information from ExecutionRegions
# input:       $strRegionName: Execution Name (Case sensitive)
#              $nOption= Region::Base, Region::MaxSize, Region::Attribute, Region::Offset
# output:      $strInfo may be base, maxsize, attribute, and offset
#****************************************************************************
sub GetRegionInfo
{
    my $self = shift;
    my ($strRegionName, $nOption) = @_;
    my $strInfo = undef;
    my $Info_ref = $self->GetExeRegionInfo($strRegionName);

    if(defined $Info_ref->[Region::Attribute])
    {
        if($nOption >  Region::Offset || $nOption <  Region::Base)
        { # report error - $nOption must have a value
            &lds_die("GetRegionInfo must have Option value($nOption)");
        }
        else
        {
            $strInfo = $Info_ref->[$nOption];
        }
    }
    return $strInfo;
}
#****************************************************************************
# subroutine:  GetExeRegionInfo - Get Execution Region information
# input:       $strRegionName: Execution Name (Case sensitive)
# output:      an Array contains 
#              [0]$strBase=Region Base address, 
#              [1]$strMaxSize=Region MaxSize, 
#              [2]$strAttribute=Attribute, 
#              [3]$strOffset(undef= no offset , others=start with +0x.. or ALIGN)
#****************************************************************************
sub GetExeRegionInfo
{
    my $self = shift;
    my ($strRegionName) = @_;
    my ($strBase, $nMaxSize, $strAttribute, $strOffset) = (undef, undef, undef, undef);
    my $nIndex = $self->{ExeRegionLookUpTable}{$strRegionName};
    if(defined $nIndex)
    {
        $strOffset = $self->{ExeRegion}{$nIndex}->[2];
        $strBase = $self->{ExeRegion}{$nIndex}->[1]; 
        $nMaxSize = (defined $self->{ExeRegion}{$nIndex}->[3]) ? $self->{ExeRegion}{$nIndex}->[3] : 0xFFFFFFFF;
        $strAttribute = $self->{ExeRegion}{$nIndex}->[4];
    }
    my @Info = ($strBase, &CommonUtil::Dec2Hex($nMaxSize), $strAttribute, $strOffset);
    return \@Info;
}

#****************************************************************************
# subroutine:  lds_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub lds_die
{
    my ($error_msg, $file, $line_no) = (@_);
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'ldsInfo');    
}
