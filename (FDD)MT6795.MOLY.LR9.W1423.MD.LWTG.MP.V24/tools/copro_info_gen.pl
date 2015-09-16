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
#*   copro_info_gen.pl
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
use BasicMemInfoQuery;
use FileInfoParser;

#****************************************************************************
# Constants
#****************************************************************************
my $COPRO_INFO_VERNO     = " v0.01";
                           # v0.01 , 2013/06/25,  Initial revision
#****************************************************************************
# Input
#****************************************************************************
my $FORCE_GEN             = $ARGV[0];
my $COPRO_INFO_OUTPUT     = $ARGV[1];
my $themf                 = $ARGV[2];
my $INFOMAKELOG           = $ARGV[3];
my $COPRO_SYM_FILE        = $ARGV[4];
my $COPRO_IMAGELAYOUT     = $ARGV[5];

print "copro_info_gen input:\n$ARGV[0]\n$ARGV[1]\n$ARGV[2]\n".
      "$ARGV[3]\n$ARGV[4]\n$ARGV[5]\n\n";

#****************************************************************************
# Global Variables
#****************************************************************************
my $g_bFORCE = ($FORCE_GEN eq "TRUE") ? 1 : 0;
my %g_COPRO_INFO;
my %g_MKFILE;
my %g_CmplOpt;
my %g_RelInfo;

#****************************************************************************
# >>>  Main Flow
#****************************************************************************
FileInfo::PreProcess($themf, \%g_MKFILE, $INFOMAKELOG, \%g_CmplOpt, \%g_RelInfo,1);
if(NeedToGen($g_bFORCE, $themf, $COPRO_IMAGELAYOUT, $COPRO_SYM_FILE))
{
    get_COPRO_INFO($themf, $COPRO_IMAGELAYOUT, undef, $COPRO_SYM_FILE, \%g_COPRO_INFO);
}
else
{
    SetDefaultValue(\%g_COPRO_INFO);
}
$g_COPRO_INFO{FileInfo::COPRO_INFO_FORCE} = $g_bFORCE;
map {print "$_ => ".$g_COPRO_INFO{$_}. "(".CommonUtil::Dec2Hex($g_COPRO_INFO{$_}).")"."\n"; } keys %g_COPRO_INFO;
gen_COPRO_INFO_LOG(\%g_COPRO_INFO, $COPRO_INFO_OUTPUT);

exit 0;
#****************************************************************************
# Subroutines
#****************************************************************************
sub NeedToGen
{
    my ($bFORCE, $MAKE_FILE, $IMAGELAYOUT, $SYM_PATH)=@_;
    my $bNeed = 0; # no need to generate
    print "[NeedToGen] FORCE=$bFORCE, BuiltWithCopro=". FileInfo::is_BuiltWithCopro() ."\n";
    if($bFORCE and FileInfo::is_BuiltWithCopro())
    {       
        #die for BasicMemInfo
        coproinfo_die("$MAKE_FILE doesn't exist!\n") if(!-e $MAKE_FILE);
        coproinfo_die("$IMAGELAYOUT doesn't exist!\n") if(!-e $IMAGELAYOUT);
        coproinfo_die("$SYM_PATH doesn't exist!\n") if(!-e $SYM_PATH);
        $bNeed = 1;
    }
    print $bNeed ? "=> Need to generate tmp file contents\n" : "=> No need to generate tmp file contents\n";
    return $bNeed;
}

sub gen_COPRO_INFO_LOG
{
    my ($COPRO_INFO_href, $OUTPUT_PATH) = @_;
    my $strCOPRO_INFO = CommonUtil::HashStringGenerator($COPRO_INFO_href);
    CommonUtil::WriteFileContent($OUTPUT_PATH, $strCOPRO_INFO, 1, 1);
}

sub get_COPRO_INFO
{
    my ($MAKE_FILE, $IMAGELAYOUT, $MAP_PATH, $SYM_PATH, $COPRO_INFO_href) = @_;
    print "Set COPRO INFO:\n";
    print "--------------------------------------------------------------\n";
    my $nLoadViewSize = BasicMemInfo::CMD_GetLoadViewSize($MAKE_FILE, $IMAGELAYOUT, $MAP_PATH, $SYM_PATH, undef);
    $COPRO_INFO_href->{FileInfo::COPRO_LV_SIZE} = $nLoadViewSize;
    my $nTotalRamUsage = BasicMemInfo::CMD_GetPhysicalRAMUsage($MAKE_FILE, $IMAGELAYOUT, $MAP_PATH, $SYM_PATH, undef);
    $COPRO_INFO_href->{FileInfo::COPRO_TOTAL_USAGE} = $nTotalRamUsage;
}

sub SetDefaultValue
{
    my ($COPRO_INFO_href) = @_;
    print "Set Default Value:\n";
    print "--------------------------------------------------------------\n";
    $COPRO_INFO_href->{FileInfo::COPRO_LV_SIZE} = 0x100000;
    $COPRO_INFO_href->{FileInfo::COPRO_TOTAL_USAGE} = 0x400000;
}

sub coproinfo_die
{
    my ($error_msg, $file, $line_no) = @_;
    my $pack_name = undef;
    if(!defined $file or !defined $line_no)
    {
        ($pack_name, $file, $line_no) = caller;    
    }
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'COPRO_INFO_GEN'); 
}