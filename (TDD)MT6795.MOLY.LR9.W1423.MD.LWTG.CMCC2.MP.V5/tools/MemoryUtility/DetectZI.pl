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
#*   TCMmargin.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This perl is used to get TCM margin
#*       
#*
#* Author:
#* -------
#*   Cark Kao (mtk08237)
#*
#****************************************************************************/

BEGIN { push @INC, '../', './tools/', './tools/MemoryUtility/' }

use strict;
use File::Basename;
use LinkerOutputParser;
use CommonUtility;


use constant EXEC_VIEW => 0;
use constant LOAD_VIEW => 1;


my $nVerion = "v1.02";
             # v1.02 , 20140910 , Carl , Add symbol filter 
             # v1.01 , 20140909 , Carl , Reduce parsing time of map, sym file for speedup
             # v1.00 , 20140827 , Carl , Init version



#################################################################
#############  Configurable variable are list below  ############
#################################################################

# serach sections
my @aSection = (
    "INTSRAM_DATA",
    "INTSRAM_DATA_B1",
    "EXTSRAM",
    "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW",
    "CACHED_EXTSRAM",
    "DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW",
    "EXTSRAM_DSP_TX",
    "EXTSRAM_DSP_RX" );

# filter-out symbol file
my $strSymbolFilterFilePath = "./tools/MemoryUtility/config/detectZI_filter.txt";

#################################################################
#################################################################
#################################################################



# 1. input sym, map, bin file

&Usage() if ($#ARGV < 2); 

my ($sym_file, $map_file, $bin_file, $gnZIpercent, $gnZIthreshold) = @ARGV;

$gnZIpercent = 100 if( !defined $gnZIpercent );
$gnZIthreshold = 0 if( !defined $gnZIthreshold );

$sym_file =~ s/\\/\\\\/;
$map_file =~ s/\\/\\\\/;
$bin_file =~ s/\\/\\\\/;

print "project info: $map_file\n\n";


# 2. main().  lisr all RW sections

my $nTotalZI;
my %var_info;  # var_name => [ var size, obj name, section name ]
my %obj_info;  # obj_name  => [ total ZI var size, var_1, var_2, ... ]
my %filter_out_symbol;

&take_filter_out_symbol();

&process_with_value(100,0) if ( 100==$gnZIpercent );
&process_with_value($gnZIpercent, $gnZIthreshold) if ( 100!=$gnZIpercent );


sub take_filter_out_symbol()
{
    my $strContent = CommonUtil::GetFileContent($strSymbolFilterFilePath);
    my @symbol = split(/\s/, $strContent);

    # note that  we also take the "commont" as filter out symbol
    foreach (@symbol)
    {
        $filter_out_symbol{$_} = 1;
    }
}

sub init_Glob()
{
    $nTotalZI=0;    %var_info={};    %obj_info={};
}

sub process_with_value
{
    &init_Glob();

    my ($nZIpercent, $nZIthreshold) = @_;

    print "==============================================================\n";
    print "=====nZIpercent: $nZIpercent, nZIthreshold: $nZIthreshold=====\n";
    print "==============================================================\n";

    if( 100 == $nZIpercent ) {
        print("Section\tObj file\tSymbol\tSize\n");
    } else {
        print("Section\tObj file\tSymbol\tSymbol size\tZI Size\tRW Size\tZI percent\n");
    }

    my %sectionInfo;
    LinkerOutputParser::FileParse($sym_file);
    foreach my $strSection (@aSection)
    {
        # (1) get base of load/execution address of section
        my $nSectionLoadAddr = hex(SymFileParser::GetLinkerSymbolAddress(
            $strSection, LinkerSymPostfix::Base, LOAD_VIEW));
        my $nSectionExecAddr = hex(SymFileParser::GetLinkerSymbolAddress(
            $strSection, LinkerSymPostfix::Base, EXEC_VIEW));

        # (2) get all symbol in section
        #[[SymbolName, address, size], ...] sorted by address
        my $temp1_aref = LinkerOutputParser::GrepSymbolBySection("$strSection");

        push @{$sectionInfo{$strSection}}, $nSectionLoadAddr, $nSectionExecAddr, $temp1_aref;
    }


    LinkerOutputParser::FileParse($map_file);
    foreach my $strSection (@aSection)
    {
        &detectZI($strSection, $nZIpercent, $nZIthreshold,
            $sectionInfo{$strSection}[0],
            $sectionInfo{$strSection}[1],
            $sectionInfo{$strSection}[2]);
    }
    print "total ZI: $nTotalZI \n";

    &print_result_by_var_size();
    &print_result_by_obj_size();
}


# 3. start process section X

sub detectZI
{  
    my ($strSection, $nZIpercent, $nZIthreshold,
        $nSectionLoadAddr, $nSectionExecAddr, $temp1_aref) = @_;

    # (3) open file

    open (BIN_FILE_HANDLE, "<$bin_file") or & die( "[1.0] no bin file $bin_file @ __FILE__, __LINE__");
    binmode BIN_FILE_HANDLE;

    # (4) for each symbol in section
    foreach my $item (@$temp1_aref)
    {
        my $strVarName = @$item[SymTable::Name];
        my $nFuncAddr = hex(@$item[SymTable::Addr]);
        my $nVarSize = @$item[SymTable::Size];
        my $nFuncAddrInBin = $nFuncAddr - $nSectionExecAddr + $nSectionLoadAddr; # symbol load address
            # my $nOffset = $nFuncAddr - $nSectionExecAddr ; # symbol load address
            # print "\t$strVarName, $nFuncAddr, $nVarSize, $nFuncAddrInBin, $nOffset \n";

        next if (0 == $nVarSize || defined $filter_out_symbol{$strVarName} );

        # <1> read content of symbol: {load address, load address+length}
        # <2> if only zeros in the content, report it shoulbe be a ZI data

        my ($bDetectZI, $nSeekLen, $nVarRWSize, $nVarZISize, $nVarZIpercent) = (1,0,0,0,0);

        seek BIN_FILE_HANDLE, $nFuncAddrInBin, 0;
        for ( ; $nSeekLen < $nVarSize && (1==$bDetectZI||100!=$nZIpercent) ; ++$nSeekLen ) 
        {
            my ($nReadLen, $nData, $strData);
            $nReadLen = read BIN_FILE_HANDLE, $nData, 1;
            $strData = sprintf($nData);
            if( "\c@" ne $strData )
            {
                $bDetectZI = 0; 
                $nVarRWSize++;
            }
        }

        $nVarZISize = $nVarSize - $nVarRWSize;
        $nVarZIpercent = $nVarZISize/$nVarSize*100;
            
        if( $nZIpercent != 100 )
        {
            $bDetectZI = 1 if( 0 == $bDetectZI 
                            && $nVarZIpercent >= $nZIpercent
                            && $nVarSize >= $nZIthreshold );

            # no not show again
            $bDetectZI = 0 if( 100==$nVarZIpercent);
        }

        if ( 1 eq $bDetectZI )
        {
            my $refObj = LinkerOutputParser::GetParentOfSymbol($strVarName, "obj");
            my $strObjName = (defined $refObj?@$refObj[0]:"not_found");

            # warning, we do not process the case: more than one symbol with same name 
            push @{$var_info{$strVarName}}, $nVarSize, $nVarZISize, $strObjName, $strSection;

            if( !defined $obj_info{$strObjName } ){
                push @{$obj_info{$strObjName}}, $nVarSize, $nVarZISize;
            }else{
                $obj_info{$strObjName}[0] += $nVarSize;
                $obj_info{$strObjName}[1] += $nVarZISize;
            }
            push @{$obj_info{$strObjName}}, $strVarName;
 
            print((defined $refObj?$strSection:"not_found_in_map_file"));
            print("\t$strObjName\t$strVarName\t$nVarSize");
            print(($nZIpercent != 100?"\t$nVarZISize\t$nVarRWSize\t$nVarZIpercent\n":"\n"));

            $nTotalZI += $nVarSize;
        }

    }

}


sub print_result_by_var_size()
{
    # sort by ZI size
    my @list = sort { $var_info{$b}[1] <=> $var_info{$a}[1] } keys %var_info;

    print "\n\n-->sort by symbol ZI size<--\n\n";

    if( 100 == $gnZIpercent ) 
    {
        print("Symbol\tSize\tObj file\tSection\n");
        foreach my $strVarName (@list)
        {
            my $nVarSize   = $var_info{$strVarName}[0];
            my $strObjName = $var_info{$strVarName}[2];
            my $strSection = $var_info{$strVarName}[3];

            print "$strVarName\t$nVarSize\t$strObjName\t$strSection\n";
        }
    }
    else
    {
        print("Symbol\tSymbol size\tZI Size\tRW Size\tZI percent\tObj file\tSection\t\n");
        foreach my $strVarName (@list)
        {
            my $nVarSize      = $var_info{$strVarName}[0];
            my $nVarZISize    = $var_info{$strVarName}[1];
            my $strObjName    = $var_info{$strVarName}[2];
            my $strSection    = $var_info{$strVarName}[3];

            next if( !defined $nVarSize );
            my $nVarRWSize    = $nVarSize - $nVarZISize; 
            my $nVarZIpercent = $nVarZISize/$nVarSize*100; 

            print "$strVarName\t$nVarSize\t$nVarZISize\t$nVarRWSize\t$nVarZIpercent\t$strObjName\t$strSection\n";
        }
        
    }
}

sub print_result_by_obj_size()
{
    # sort by ZI size
    my @list = sort { $obj_info{$b}[1] <=> $obj_info{$a}[1] } keys %obj_info;

    print "\n\n-->sort by obj ZI size<--\n\n";

    if( 100 == $gnZIpercent ) 
    {
        print("Obj file\tSymbol\tVar size\tSize of total ZI in obj\n");
        foreach my $strObjName (@list)
        {
            my $nObjZiSize  = $obj_info{$strObjName}[0];
        
            print "$strObjName\t \t \t$nObjZiSize\n";
 
            for( my $i=2; $i<=(scalar @{$obj_info{$strObjName}}-1); ++$i )
            {
                my $strVarName = $obj_info{$strObjName}[$i];
                my $nVarSize = $var_info{$strVarName}[0];
                print "\t$strVarName\t$nVarSize\n";
            }
        }
    }
    else
    {
        print("Obj file\tSymbol\tSymbol size\tZI Size\tRW Size\tZI percent\tSection\t\n");
        foreach my $strObjName (@list)
        {
            my $nObjZiSize  = $obj_info{$strObjName}[0];
        
            print "$strObjName\tsize:$nObjZiSize\n";
 
            for( my $i=2; $i<=(scalar @{$obj_info{$strObjName}}-1); ++$i )
            {
                my $strVarName = $obj_info{$strObjName}[$i];
                my $nVarSize   = $var_info{$strVarName}[0];
                my $nVarZISize = $var_info{$strVarName}[1];
                my $strSection = $var_info{$strVarName}[3];

                next if( !defined $nVarSize );
                my $nVarRWSize    = $nVarSize - $nVarZISize; 
                my $nVarZIpercent = $nVarZISize/$nVarSize*100; 

                print "\t $strVarName\t$nVarSize\t$nVarZISize\t$nVarRWSize\t$nVarZIpercent\t$strSection\n";
            }
        }

    }
}


sub Usage
{
  print "version: $nVerion\n";
  print <<"__EOFUSAGE";
usage: perl $0  sym_file  map_file  bin_file ZI_percent ZI_threshold
e.g. perl  ./tools/MemoryUtility/DetectZI.pl \
        ./build/PROHECT_NAME/FLAVOR/bin/AAA.sym \
        ./build/PROHECT_NAME/FLAVOR/bin/AAA.map \
        ./build/PROHECT_NAME/FLAVOR/bin/AAA.bin
        100 \
        0 \

e.g. perl  ./tools/MemoryUtility/DetectZI.pl \
        ./build/PROHECT_NAME/FLAVOR/bin/AAA.sym \
        ./build/PROHECT_NAME/FLAVOR/bin/AAA.map \
        ./build/PROHECT_NAME/FLAVOR/bin/AAA.bin
        90 \
        1024 \

__EOFUSAGE
  exit 1;
}


