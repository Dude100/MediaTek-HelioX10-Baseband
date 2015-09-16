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
#*   sys_auto_gen.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is used to generate image layout
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
use sysGenUtility;                 #pm file name without case sensitivity
use FileInfoParser;
use File::Copy;
use tools::pack_dep_gen;
PrintDependModule();

#****************************************************************************
# Constants
#****************************************************************************
my $SYSAUTOGEN_VERNO = " m0.08";
                       # m0.08 , 20130625 by mei, Add copro_info.log input
                       # m0.07 , 20130528 by mei, Replace factory rom with infomake.log
                       # m0.06 , 20121019 by mei, Remove FOTA input
                       # m0.05 , 20120807 by mei, Move sysgen2 to scatGen.pl
                       # m0.04 , 20120712 by mei, Not to precompile linker script due to changing lib name
                       # m0.03 , 20120702 by mei, Support EWS
                       # m0.02 , 20120614 by mei, Support input with ()'s problem for linux
                       # m0.01 , 20120528 by mei, Support path and filename case sensitive on Linux
                       # m0.03 , 20120507 by mei, Remove precompile BL and ext_BL
                       # v0.02 , 20120614 by mei, Fix if system call fails, it'll return errro code:256
                       #                       and make build flow will pass if without shifting.
                       # v0.01 by mei, initial version

#****************************************************************************
# Global Variables
#****************************************************************************
my $g_exit = 0;
my %g_MAKEFILE_OPTIONS;
my $g_strCOMPILER;

#****************************************************************************
# Input Parameters
#****************************************************************************
my $IMAGELAYOUT           = $ARGV[0];
my $BL_IMAGELAYOUT        = $ARGV[1];
my $themf                 = $ARGV[2];
my $BB_PATH               = $ARGV[3];
my $NEED_BUILD_BOOTLOADER = $ARGV[4];
my $DUMMY_IMAGELAYOUT_ALLOW   = $ARGV[5];  # INSIDE_MTK (need to check dummy_scatter_enable)
my $DUMMY_IMAGELAYOUT_FORCE   = $ARGV[6];  # DUMMY_LIS (from gendummylis)
my $INFOMAKELOG               = $ARGV[7];
my $COPRO_INFO_FILE           = $ARGV[8];
my $LIB_PATH                  = $ARGV[9];
my $CC_CMD                    = $ARGV[10];
my $EXT_BL_IMAGELAYOUT = $BL_IMAGELAYOUT;
$EXT_BL_IMAGELAYOUT =~ s/\.txt/_ext\.txt/;

print "NEED BL=$NEED_BUILD_BOOTLOADER\n";

#****************************************************************************
# 1 >>> Run Process
#****************************************************************************
if(1!=&FileInfo::Parse_MAKEFILE($themf, \%g_MAKEFILE_OPTIONS))
{
   &sysUtil::sysgen_die("Parse MakeFile failed");
}
$g_strCOMPILER = &FileInfo::GetCompiler();

#****************************************************************************
# 2 >>> Run Process
#****************************************************************************
$g_exit = &RunProcess("perl tools/sysGen1.pl $BB_PATH", 0);
$g_exit = &RunProcess("perl tools/scatGen.pl $ARGV[0] $ARGV[1] \"$ARGV[2]\" $ARGV[3] $ARGV[4] $ARGV[5] $ARGV[6] $ARGV[7] $ARGV[8]", $g_exit);

#****************************************************************************
# 0 >>> exit - no error: 0, error code: > 0
#****************************************************************************
exit $g_exit>>8;

#****************************************************************************
# subroutines
#****************************************************************************
sub RunProcess
{#exit - no error: 0, error code: > 0
    my ($CMD, $n_exit) = @_;
    if($n_exit == 0)
    {
        print "========COMMAND==========\n$CMD\n==\n";
        $n_exit = system($CMD);
        print "===========$n_exit=============\n"
    }
    return $n_exit;
}

sub RunPreprocess
{
    my ($SrcPath, $nExit) = @_;
    my ($DestPath, $bBackup) = &BackupFile($SrcPath, "txt", "h");
    if($bBackup && $CC_CMD ne "")
    {
        $nExit = &RunProcess("$CC_CMD -C -E -P -D  LIB_PATH=$LIB_PATH $DestPath > $SrcPath", $nExit);        
        &ChompEmptyLine($SrcPath) if($nExit == 0);
    }
    my $pch = $DestPath;
    $pch =~ s/\.h/\.pch/;
    move($DestPath, $pch);
    return $nExit;
}

sub BackupFile
{
    my ($SrcPath, $strNameToBeReplaced, $strNameToReplace)=@_;
    my $nRes = undef;
    my $DestPath = $SrcPath;
    $DestPath =~ s/$strNameToBeReplaced/$strNameToReplace/;
    print "[BackupFile] $SrcPath => $DestPath\n";
    copy($SrcPath, $DestPath);    
    $nRes = 1 if(-e $DestPath);
    return ($DestPath, $nRes);
}

sub ChompEmptyLine
{
    my ($strFilePath) = @_;
    my $content;
    open FILE, "<$strFilePath" or &sysUtil::sysgen_die("$strFilePath: open file error!", __FILE__, __LINE__);
    while(<FILE>)
    {
        chomp;
        $content .= $_. "\n" if ($_ ne "");
    }
    close FILE;
    open FILE, ">$strFilePath" or &sysUtil::sysgen_die("$strFilePath: open file error!", __FILE__, __LINE__);
    print FILE $content;
    close FILE;
}
