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
#*   FileInfoParser.pm
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
BEGIN{push(@INC,'../', './tools/', './tools/MemoryUtility/')};
use CommonUtility; 

#****************************************************************************
# Constant
#****************************************************************************
package Region;
use constant Size        => 1;
use constant VMA         => 2;
use constant LMA         => 3;
use constant Offsets     => 4;
use constant Align       => 5;
use constant Attr        => 6;

# for %g_SymTable = ();
package SymTable;
use constant Name       => 0;
use constant Addr       => 1;
use constant Group      => 2;
use constant Region     => 3;
use constant Size       => 4;

# for %symbol = ();
package Symbol;
use constant Addr       => 0;
use constant Region     => 3;
use constant Size       => 4;

package LinkerSymPostfix;
use constant Base       => 0;
use constant Limit      => 1;
use constant ZIBase     => 2;
use constant ZILimit    => 3;
use constant Length     => 4;

#****************************************************************************
# Constants
#****************************************************************************
my $SYMINFOPARSER_VERNO     = " m0.14";
                              # m0.14 , 2014/08/04, add GetSymbol() for retrieve symbol table
                              # ...
                              # v0.01 , 2012/07/25,  Initial revision

#****************************************************************************
# Global variable
#****************************************************************************

package SymFileParser;

my $g_SYMPath;
my %symbol;
my $DUMMY_END_size;
my $DUMMY_END_base;
#0001622c l     F ROM	000001b4 ast_hif_mcu_lisr_handler   
#00000001 l       *ABS*	00000000 __SRS_CPS_OPTIMIZE__
my %g_SymTable; # $strAddress.$strSymbolName => [strSymbol, $strAddress, strGroup, strRegion, nSize]
my %g_LinkerSymbol; # $strSymbolName => [$strAddress, strGroup, strRegion, nSize]


# Execution Region
my %g_ExeRegion;
my %g_ExeRegionLookUpTable; # RegionName -> Index
my %Attr;

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# subroutine:  SYM_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub SYM_die
{
    my ($error_msg, $file, $line_no) = (@_);
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'SYM');    
}
#****************************************************************************
# subroutine:  ParseSYM
# input:  SYM Path string     
# output: x     
#****************************************************************************
sub Clean
{
    %symbol = ();
	%g_ExeRegion = ();
	%g_ExeRegionLookUpTable = ();
	%g_SymTable = ();
	%g_LinkerSymbol = ();
	%Attr = ();
	$DUMMY_END_size = 0;
	$DUMMY_END_size = 0;
}
sub ParseSYM
{
    ($g_SYMPath) = (@_);
    Clean();
    if(defined $g_SYMPath and -e $g_SYMPath)
    {
        open (FILE_HANDLE, "<$g_SYMPath") or &SYM_die("$g_SYMPath: file error!", __FILE__, __LINE__);
        my $strPreExeRegionName = undef;
        my $bBegin = 0; # 0= Program Header: begin, 1= Sections begin, 2=SYMBOL TABLE: begin
        while (<FILE_HANDLE>) 
        {
            my $strLine = $_;
            $bBegin = 1 if($strLine =~/^Sections:$/);
            $bBegin = 2 if($strLine =~/^SYMBOL TABLE:$/);
            if ($bBegin == 1 and 
                $strLine =~ /\s*(\d+)\s+(\S+)\s+(\w+)\s+(\w+)\s+(\w+)\s+(\w+)\s+(\S+)/) 
            {   #  0 BL_GFH_SECTION 00000170  7000a000  7000a000  00002000  2**2
				$g_ExeRegion{$1}= [$2, $3, $4, $5, $6, $7];
                $g_ExeRegionLookUpTable{$2} = $1;
                $strPreExeRegionName = $2;
            }           
            &ParseInputSection($strPreExeRegionName, $strLine) if(defined $strPreExeRegionName);
            
            ParseSymbolTable($strLine) if($bBegin == 2);

            if ($bBegin ==2 and $strLine =~ /DUMMY_END/)
            {#f3fc0000 g       *ABS*    00000000 Image$$CACHED_DUMMY_END$$Base
             #3fc0000 g       *ABS*    00000000 Image$$DUMMY_END$$Base
				if(/^(\w+)\s+(\w+)\s+(.*)\s+(\w+)/)
				{
					$DUMMY_END_size = hex($4);
					$DUMMY_END_base = "0x".$1;
				}			
			}
            elsif ($bBegin ==2 and 
                   $strLine =~ /^(\w+)\s+(\w+)\s+(\w+)\s+(\S+)\s+(\w+)\s+(\w+)$/)
            {#7000a000 l    d  BL_GFH_SECTION   00000000 BL_GFH_SECTION
				next if ($2 ne "g");
				next if (($3 ne "F") && ($3 ne "O"));
				my $symbol_name = $6;
				my $base_address = $1;
				my $execution_region = $4;
				my $size = $5;
				$symbol{$symbol_name} = [$1, $2, $3, $4, $5];
			}
			
        }
        close FILE_HANDLE;
    }
    else
    {
        &SYM_die("SYM Path($g_SYMPath) doesn't exist", __FILE__, __LINE__);   
    }    
}


sub ParseSymbolTable
{
    my ($strLine) = @_;
    my $bSearched = 0;
    my ($strSymbolName, $strAddress, $strGroup, $strRegion, $nSize);
    if($strLine =~ /^(\w+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\w+)\s(\S+)/)
    {#0001622c l     F ROM	000001b4 ast_hif_mcu_lisr_handler       
        ($strSymbolName, $strAddress, $strGroup, $strRegion, $nSize) = ($6, "0x".$1, $2.$3, $4, hex($5));
        $bSearched = 1;
    }
    elsif($strLine =~ /^(\w+)\s+(\S+)\s+(\S+)\s+(\w+)\s(\S+)/)
    {#00000001 l       *ABS*	00000000 __SRS_CPS_OPTIMIZE__
     #f06185f1 g       CACHED_EXTSRAM	00000000 BUILD_TIME_RW$$Base
        
        ($strSymbolName, $strAddress, $strGroup, $strRegion, $nSize) = ($5, "0x".$1, $2, $3, hex($4));
        $bSearched = 1;
    }
    if($bSearched)
    {
        if($strGroup ne "l" and $strGroup ne "ldf" and $strGroup ne "ld")
        {#skip 00000000 l       *ABS*	00000000 MT6589
         #skip 00000000 l    df *ABS*	00000000 ft_fnc_fat.c
         #skip 00000000 l    d  ROM	00000000 ROM
            if($strSymbolName =~ /\$\$/ and (($strGroup eq "g") or ($strGroup eq "w")))
            {
                $g_LinkerSymbol{$strSymbolName} = [$strAddress, $strGroup, $strRegion, $nSize];
            }
            else
            {
                print "$strAddress.$strSymbolName appears before\n" if(exists $g_SymTable{$strAddress.".".$strSymbolName});
                $g_SymTable{$strAddress.".".$strSymbolName} = [$strSymbolName, $strAddress, $strGroup, $strRegion, $nSize];
            }
        }
    }
}

sub GetSymbolTable
{
    return \%g_SymTable;    
}
sub GetSymbol
{
    return \%symbol;    
}

sub GrepSymbolBySection
{
    my ($strSection) = @_;
    my @SymKeys = sort { hex($g_SymTable{$a}->[SymTable::Addr]) <=> hex($g_SymTable{$b}->[SymTable::Addr]) } 
                  grep{$g_SymTable{$_}->[SymTable::Region] eq $strSection} keys %g_SymTable;
    #map {print $_."\n"} @SymKeys;
    my @SymInfo = map {$g_SymTable{$_}} @SymKeys;
    return \@SymInfo;
}

sub GrepSymbolByInputSection
{
    my ($strSection) = @_;
    my $strStart = GetLinkerSymbolAddress($strSection, LinkerSymPostfix::Base, 2);
    my $strEnd = GetLinkerSymbolAddress($strSection, LinkerSymPostfix::Limit, 2);
    my @SymInfo;
    if((hex($strEnd) - hex($strStart)) > 0)
    {
        my @SymKeys = sort { hex($g_SymTable{$a}->[SymTable::Addr]) <=> hex($g_SymTable{$b}->[SymTable::Addr]) } 
                      grep{(hex($g_SymTable{$_}->[SymTable::Addr]) >= hex($strStart)) and  
                           (hex($g_SymTable{$_}->[SymTable::Addr]) < hex($strEnd  ))} keys %g_SymTable;
        #map {print $_."\n"} @SymKeys;
        @SymInfo = map {$g_SymTable{$_}} @SymKeys;
    }
    return \@SymInfo;
}

#nRegionType = 0: Execution Region
#nRegionType = 1: Load Region
#nRegionType = 2: Input Section
sub GetLinkerSymbolAddress
{
    my ($strRegionName, $nLocation, $nRegionType) = @_;
    my $strPrefix = 'Image$$';
    if($nRegionType == 1)
    {
        $strPrefix = 'Load$$' ;
        $nLocation = 0;
    }
    elsif($nRegionType == 2)
    {
        $strPrefix = "";    
    }
    my $strPostfix = '$$Base';  #LinkerSymPostfix::Base
    $strPostfix = '$$Limit'     if($nLocation == LinkerSymPostfix::Limit);
    $strPostfix = '$$ZI$$Base'  if($nLocation == LinkerSymPostfix::ZIBase);
    $strPostfix = '$$ZI$$Limit' if($nLocation == LinkerSymPostfix::ZILimit);
    $strPostfix = '$$Length'    if($nLocation == LinkerSymPostfix::Length);
    my $strSymbolName = $strPrefix.uc($strRegionName).$strPostfix;
    my $strAddr = undef;
    $strAddr = $g_LinkerSymbol{$strSymbolName}->[0] if(exists $g_LinkerSymbol{$strSymbolName});
    return $strAddr;
}


#****************************************************************************
# subroutine:  Get_DUMMY_END_Size
# input:       N/A
# output:      size of DUMMY_END region
#****************************************************************************
sub Get_DUMMY_END_Size
{
	return $DUMMY_END_size;
}

#****************************************************************************
# subroutine:  Get_DUMMY_END_Base
# input:       N/A
# output:      base address of DUMMY_END region
#****************************************************************************
sub Get_DUMMY_END_Base
{
	return $DUMMY_END_base;
}

#****************************************************************************
# subroutine:  StoreIntoTempFile
# input:       N/A
# output:      temp files which contain perl data structure
#****************************************************************************
use Storable qw/lock_nstore/;
sub StoreIntoTempFile
{
	my ($strPath) = @_;
	my $file = $strPath."\\SymParser_Temp.dat";
	my %tempfile;

	$tempfile{"execution_region"} = \%g_ExeRegion;
	$tempfile{"symbol_info"} = \%symbol;

	lock_nstore \%tempfile, $file;
}

#****************************************************************************
# subroutine:  ParseInputSection used by ParseSYM
#              to parse Execution Region Attribute
# input:  1. Execution Name, 2. $strLine
# output: x     
#****************************************************************************
sub ParseInputSection
{
    my ($strExeRegionName, $strLine) = @_;
    return if(!defined $strExeRegionName);    ### setting for $strExeRegionName = undef

    my $attr = undef;
    chomp($strLine);
    if($strLine =~ /\s+(.*)/)
    {
    #	 CONTENTS, ALLOC, LOAD, READONLY, DATA
        $Attr{$strExeRegionName} = $1;
    }
}

#****************************************************************************
# subroutine:  ListAllExeRegion
# input:       $bTrimDebugRegion: 1= NeedtoTrimDebugRegion, 0 or undef=NoNeedToTrimDebugRegion
# output:      Execution Region List 
#****************************************************************************
sub ListAllExeRegion
{
    my ($bTrimDebugRegion) = @_;
	my @k = keys %g_ExeRegion;
	my @ExeRegion;
	my $ExeRegion_aref = undef;
    for (my $i = 0; $i < $#k; $i++)
	{
		push(@ExeRegion,$g_ExeRegion{$i}->[0]);
	}
	$ExeRegion_aref = \@ExeRegion;
	if($bTrimDebugRegion)
	{
	    $ExeRegion_aref = TrimDebugRegion(\@ExeRegion);
	}
	return $ExeRegion_aref;
}
#****************************************************************************
# subroutine:  TrimDebugRegion
# input:       All Regions in array reference
# output:      Execution Region List(array reference) after trimming
#****************************************************************************
sub TrimDebugRegion
{
    my ($ERs_aref) = @_;
    my @RealERs;
    foreach my $region (@$ERs_aref)
    {
        if ( $region !~ /^\.debug_/
         and $region !~ /^\.ARM\.attributes/
         and $region !~ /^\.comment/
         and $region !~ /^\.stab/
         and $region ne "")
        {
            push(@RealERs , $region);
        }
    }
    return \@RealERs;
}


#****************************************************************************
# subroutine:  GetExeRegionInfo
# input:       Execution Region Name, $nOption
#              $nOption = Region::VMA or Region::LMA or Region::Size 
#                         or Region::Offsets or Region::Align or Region::Attr
# output:      string of corresponding Execution Region Infomation 
#****************************************************************************
sub GetExeRegionInfo
{	
	# Name          Size      VMA       LMA       File off  Algn
	my ($strExeRegionName, $nOption) = @_;
	my $index = $g_ExeRegionLookUpTable{$strExeRegionName};
	my @ExeRegionInfo;
	my $strInfo;
	my @k = keys %g_ExeRegion;
	my $key_count = $#k + 1;
	for (my $i = 0; $i <= $#k; $i++)
	{
		my $string = $g_ExeRegion{$i}->[0];
		next if ($string ne $strExeRegionName);
	}
	
	if ($nOption == Region::Size)
	{
		$strInfo = "0x".$g_ExeRegion{$index}->[Region::Size];
	}
	elsif ($nOption == Region::VMA)
	{
		$strInfo = "0x".$g_ExeRegion{$index}->[Region::VMA];
	}
	elsif ($nOption == Region::LMA)
	{
		$strInfo = "0x".$g_ExeRegion{$index}->[Region::LMA];
	}
    elsif ($nOption == Region::Offsets)
	{
        $strInfo = "0x".$g_ExeRegion{$index}->[Region::Offsets];
	}
	elsif ($nOption == Region::Align)
	{
		$strInfo = $g_ExeRegion{$index}->[Region::Align];
	}
	elsif ($nOption == Region::Attr)
	{
		$strInfo = $Attr{$strExeRegionName};
	}
	
	return $strInfo;
}

#****************************************************************************
# subroutine:  FootprintAnalyzeBySymbol
# input:       $strSymName: Symbol Name (Case sensitive)
# output:      symbol info array reference
#****************************************************************************
sub FootprintAnalyzeBySymbol
{
	my ($strSymName) = @_;
	my @total_sym_info;
	foreach my $key (keys %symbol)
	{
		next if ($strSymName ne $key);
		my $sym_info = $symbol{$strSymName};
		my $exe_region = $sym_info->[3];
		my $F_0_attr = $sym_info->[2];
		my $attr = $Attr{$exe_region};
		my $sym_attr;
		if ($attr =~ /CODE/)
		{
			$sym_attr = "RO-CODE";
		}
		elsif ($attr =~ /DATA/)
		{
			if ($F_0_attr eq "F")
			{
				$sym_attr = "RW-DATA";
			}
			elsif ($F_0_attr eq "O")
			{
				$sym_attr = "RO-DATA";
			}
		}
		else
		{
			$sym_attr = "ZI";
		}
		
		push(@total_sym_info, $exe_region);
		push(@total_sym_info, $sym_attr);
		push(@total_sym_info, "0x".$sym_info->[0]);
		push(@total_sym_info, hex($sym_info->[4]));
	}
	return \@total_sym_info;
}
