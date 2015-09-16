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
#*   copro_injection.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is used to parse copro information
#* 
#*
#* Author:
#* -------
#*   Qmei Yang  (mtk03726)
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, './tools/', './tools/MemoryUtility/' }  # add additional library path         
use CommonUtility;
use SymFileParser;
use FileInfoParser;
use File::Copy;
use File::Basename;

#****************************************************************************
# Constants
#****************************************************************************

#****************************************************************************
# Input
#****************************************************************************
my $MAIN_ELF              = $ARGV[0];
my $BACKUP_ELF_PATH       = $ARGV[1];
my $themf                 = $ARGV[2];
my $INFOMAKELOG           = $ARGV[3];
my $MAIN_SYM_FILE         = $ARGV[4];
my $COPRO_BIN_FILE        = $ARGV[5];

print "--------------------------------------------------------------\n". 
      "copro_injection input:\n$ARGV[0]\n$ARGV[1]\n$ARGV[2]\n$ARGV[3]\n$ARGV[4]\n$ARGV[5]\n".
      "--------------------------------------------------------------\n";

#****************************************************************************
# Global Variables
#****************************************************************************
my %g_MKFILE;
my %g_CmplOpt;
my %g_RelInfo;

#****************************************************************************
# >>>  Main Flow
#****************************************************************************
FileInfo::PreProcess($themf, \%g_MKFILE, $INFOMAKELOG, \%g_CmplOpt, \%g_RelInfo, 1);
if(FileInfo::is_BuiltWithCopro())
{
    SymFileParser::ParseSYM($MAIN_SYM_FILE);
    
    my $CoproInfo_href = GetCoproInfo($MAIN_SYM_FILE, "Copro");
    my ($nReservedCoproSize, $nOffset) = ($CoproInfo_href->{COPRO}[0], $CoproInfo_href->{COPRO}[1]);
    print "ReservedCoproSize= $nReservedCoproSize(".CommonUtil::Dec2Hex($nReservedCoproSize).
               "), ElfOffset= $nOffset(".CommonUtil::Dec2Hex($nOffset).")\n";
    CheckCopyBytes($COPRO_BIN_FILE, $nReservedCoproSize);
    copy($MAIN_ELF, $BACKUP_ELF_PATH); #Backup
    Inject($MAIN_ELF, $COPRO_BIN_FILE, $nOffset);
}

exit 0;
#****************************************************************************
# Subroutines
#****************************************************************************
sub CheckCopyBytes
{
    my ($strInputFilePath, $nCoproSize) = @_;
    my $nBinSize = -s $strInputFilePath;
    print "BinSize=$nBinSize(".CommonUtil::Dec2Hex($nBinSize).")\n";
    if($nCoproSize < $nBinSize)
    {
        copro_inject_die("ReservedCoproSize($nCoproSize) is smaller than CoproBinarySize($nBinSize)\n");
    }
}

sub GetCoproInfo
{
    my ($strSYM_FILE, $strRegionKeyWord) = @_;
    my ($nReservedCoproSize, $nOffset) = (0,0);
    my %CoproInfo; # ERName=> [$nReservedCoproSize, $nOffset]
    my $AllERs_aref = SymFileParser::ListAllExeRegion(1);
    foreach my $ER (@$AllERs_aref)
    {
        if($ER =~ /$strRegionKeyWord/i)
        {
            my $nReservedCoproSize = hex(SymFileParser::GetExeRegionInfo($ER, Region::Size));
            my $strOffset = SymFileParser::GetExeRegionInfo($ER, Region::Offsets);
            $CoproInfo{$ER} = [$nReservedCoproSize, hex($strOffset)];
        }
    }
    return \%CoproInfo;
}

sub Inject
{
    my ($strTargetFilePath, $strInputFilePath, $nOffsetStart) = @_;
    my $CoproBin = GetCoproBinContent($strInputFilePath);
    my $nBinSize = -s $strInputFilePath;
    my $nElfSize = -s $strTargetFilePath;
    my $TopElf = GetElfContent($strTargetFilePath, 0, $nOffsetStart );
    my $BottomElf = GetElfContent($strTargetFilePath, $nOffsetStart+$nBinSize, $nElfSize-($nOffsetStart+$nBinSize) );
    open OUTFILE, "+>$strTargetFilePath" or copro_inject_die("$strTargetFilePath: open file error!");
    binmode OUTFILE;
    print OUTFILE $TopElf;
    print OUTFILE $CoproBin;
    print OUTFILE $BottomElf;
    close OUTFILE;
    
    print "--------------------------------------------------------------\n";
    print "Inject successfully!\n";
    print "Output File: $strTargetFilePath\n";
}
sub GetElfContent
{
    my ($strTargetFilePath, $nOffsetStart, $nLength) = @_;
    print "[GetElf]OffsetBase=$nOffsetStart(".CommonUtil::Dec2Hex($nOffsetStart)."), Length=$nLength(".CommonUtil::Dec2Hex($nLength).")\n";
    my $LeftELF;
    open FILE, "+<$strTargetFilePath" or copro_inject_die("$strTargetFilePath: open file error!");
    binmode FILE;
    seek FILE, $nOffsetStart, 0 or copro_inject_die("can't reach $nOffsetStart in $strTargetFilePath!");
    read(FILE, $LeftELF, $nLength);
    close FILE;
    return $LeftELF;
}

sub GetCoproBinContent
{
    my ($strInputFilePath) = @_;
    my $CoproBin;
    open FILE, "<$strInputFilePath" or copro_inject_die("$strInputFilePath: open file error!");
    {
        binmode FILE;
        local $/;
        $CoproBin = <FILE>;
    }
    close FILE;
    return $CoproBin;
}

sub copro_inject_die
{
    my ($error_msg, $file, $line_no) = @_;
    my $pack_name = undef;
    if(!defined $file or !defined $line_no)
    {
        ($pack_name, $file, $line_no) = caller;    
    }
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'COPRO_INJECTION'); 
}