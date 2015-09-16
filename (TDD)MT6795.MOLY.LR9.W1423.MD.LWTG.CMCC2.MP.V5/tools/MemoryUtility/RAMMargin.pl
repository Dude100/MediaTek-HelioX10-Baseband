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
#*   RAMmargin.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This perl is used to get RAM margin
#*       
#*
#* Author:
#* -------
#*   Carina Liao (mtk04017)
#*
#****************************************************************************/

BEGIN { push @INC, '../', './tools/', './tools/MemoryUtility/' }  # add additional library path
use systemInfo;
use LinkerOutputParser;
use CommonUtility;
use FileInfoParser;
use BasicMemInfoQuery;
use strict;

#****************************************************************************
# Constants
#****************************************************************************
my $RAMMARGIN_VERNO     = " m0.03";
             # m0.03 , 2013/02/12,  Fix RamMargin
             # m0.02 , 2012/08/03,  Push additional library path
             # m0.01 , 2012/07/21,  Initial revision

#****************************************************************************
# Global variable
#****************************************************************************
my $DebugPrint = 0;

#****************************************************************************
# 1 >>>  Get in put parameters
#****************************************************************************
&Usage() if($#ARGV != 2);
my ($makeFile, $memorymapfile, $linkeroutputfile) = @ARGV;

#****************************************************************************
# 2 >>>  Parse make file
#****************************************************************************
my %MAKEFILE_OPTIONS;
&FileInfo::Parse_MAKEFILE($makeFile, \%MAKEFILE_OPTIONS);

#****************************************************************************
# 3 >>>  Calculate RAM margin
#****************************************************************************
&CalcRAMmargin($makeFile, $memorymapfile, $linkeroutputfile);

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit 0;

#****************************************************************************
# subroutine:  CalcRAMmargin - calculate RAM margin
# Input:       x
# Output:      x
#****************************************************************************
sub CalcRAMmargin
{
    my ($makeFile, $memorymapfile, $linkeroutputfile) = @_;
    my $nRAMmargin = 0;
    if($linkeroutputfile =~ /lis$/)
    {
        &LinkerOutputParser::FileParse($linkeroutputfile);
        my($LastRegionBeforeDUMMYEND, $DUMMY_END) =  &sysInfo::GetRAMBoundaryregion($memorymapfile,\%MAKEFILE_OPTIONS);
        print "regions = $LastRegionBeforeDUMMYEND, $DUMMY_END\n" if($DebugPrint == 1);
        my $DUMMY_END_base = hex(&LinkerOutputParser::GetExeRegionInfo($DUMMY_END, ExecutionRegion::Base));
        my $PreRegion_base = hex(&LinkerOutputParser::GetExeRegionInfo($LastRegionBeforeDUMMYEND, ExecutionRegion::Base));
        my $PreRegion_size = hex(&LinkerOutputParser::GetExeRegionInfo($LastRegionBeforeDUMMYEND, ExecutionRegion::Size));
        print "Dbase = $DUMMY_END_base, Pre_base = $PreRegion_base, Pre_size = $PreRegion_size\n"  if($DebugPrint == 1);
        $nRAMmargin = $DUMMY_END_base - ($PreRegion_base + $PreRegion_size);
    }
    elsif($linkeroutputfile =~ /sym$/)
    {
        my $mapfile = $linkeroutputfile;
        $mapfile =~ s/\.sym/\.map/;
        (my $nRAMUsage, $nRAMmargin, my $nReservedSize) = BasicMemInfo::CMD_GetRAMUsage($makeFile, $memorymapfile, $mapfile, $linkeroutputfile, undef);
    }
    else
    {
        &Usage();
    }
    my $RamMarginInHex = CommonUtil::Dec2Hex($nRAMmargin);
    print "RAM Margin = $RamMarginInHex = $nRAMmargin (Bytes)\n";

}

#****************************************************************************
# subroutine:  Usage - usage template
# Input:       x
# Output:      x
#****************************************************************************
sub Usage
{
  print <<"__EOFUSAGE";

usage: perl RAMMargin.pl makefile_path scatter_file_path/lds_file_path lis_file_path/sym_file_path 

NOTE: scatter file should input with lis file
      lds file should input with sym file

e.g. 
perl RAMMargin.pl "/[path]/MT6280_R7R8_HSPA(FULL_VERSION_RVCT).mak" "/[path]/scatMT6280_R7R8.txt" "/[path]/MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00.lis"

__EOFUSAGE

  exit 1;
}

#****************************************************************************
# Subroutine:  TCMmargin_verno - to query this package's version number
# Parameters:  x
# Returns:     version number string
#****************************************************************************
sub RAMmargin_verno
{
    return $RAMMARGIN_VERNO;
}