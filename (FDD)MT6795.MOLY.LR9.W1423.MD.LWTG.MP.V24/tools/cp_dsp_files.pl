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
#*   cp_dsp_files.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to copy dsp files and append the DSP label info.
##*
#* Author:
#* -------
#*   Ray Lin-Wang (mtk04222)
#*
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
use File::Copy;
use File::Path;
use File::Basename;
use Cwd;

#****************************************************************************
# Input Parameters & Global Variables
#****************************************************************************
(($#ARGV <0) || ($#ARGV > 6)) && &Usage;
my $dsp_dir         = $ARGV[0]; # The DSP folder ex:modem/dsp_bin
my $build_dsp_dir   = $ARGV[1]; # The DSP files will copy to this folder ex: build/$project/$flavor/bin/dsp
my $target_dir      = $ARGV[2]; # The DSP bin will copy to this folder ex: build/$project/$flavor/bin/
my $project_mk      = $ARGV[3]; # The project makefile path. ex: make/XXXX.mak
my $dsp_version     = $ARGV[4]; # The DSP label info.
my $need_cp_sig     = $ARGV[5]; # Copy signature file accodring to PARTIAL_SOURCE 
my $info_out_file   = $ARGV[6]; # output the DSP info to this file for cmmgen
$target_dir = dirname($target_dir) if(!-d $target_dir);

my $OStype = 'WIN';
if($^O ne "MSWin32"){
  $OStype = 'LINUX';
}
my $lte_dsp_project ="";
my $lte_dsp_flavor = "";
my $dsp_file = "";
my $nand_flash_support = "";
my $category ="";
#****************************************************************************
# Read from project makefile
#****************************************************************************
my %feature;
open(FILE_HANDLE, "<$project_mk") or &error_handler("Fail to read $project_mk!", __FILE__, __LINE__); 
while (<FILE_HANDLE>)
{
	if (/^(\w+)\s*=\s*(\S+)/)
	{
		my $keyname = $1;
		defined($feature{$keyname}) && warn "$1 redefined in $project_mk!\n";
		$feature{$keyname} = $2;
	}
}
close FILE_HANDLE;

#****************************************************************************
# Setting DSP files
#****************************************************************************
# read lte_dsp_project
if (defined($feature{'LTE_DSP_PROJECT'}) && $feature{'LTE_DSP_PROJECT'} ne "") {
	$lte_dsp_project = $feature{'LTE_DSP_PROJECT'};
}
else {
	&error_handler("Fail to get the LTE_DSP_PROJECT value from $project_mk!", __FILE__, __LINE__);
}

#read lte_dsp_flavor
if (defined($feature{'LTE_DSP_FLAVOR'}) && $feature{'LTE_DSP_FLAVOR'} ne "") {
	$lte_dsp_flavor = $feature{'LTE_DSP_FLAVOR'};
}
else {
	&error_handler("Fail to get the LTE_DSP_FLAVOR value from $project_mk!", __FILE__, __LINE__);
}

#read nand_support
if (defined($feature{'NAND_SUPPORT'}) && $feature{'NAND_SUPPORT'} ne "") {
	$nand_flash_support = $feature{'NAND_SUPPORT'};
}
else {
	&error_handler("Fail to get the NAND_SUPPORT value from $project_mk!", __FILE__, __LINE__);
}
if ($nand_flash_support eq "TRUE") {
    $category = "NAND";
} else {
    $category = "SPI";
}

#****************************************************************************
# Execute
#****************************************************************************
my $pattern = "DSP";
my @delfiles = glob "$target_dir/*${pattern}*.bin";
unlink(@delfiles) if (@delfiles);

my $dsp_bin_file = "${dsp_dir}/${lte_dsp_project}/${lte_dsp_flavor}/${category}/${lte_dsp_project}_${lte_dsp_flavor}_${category}.bin";
my ($name, $path, $suffix) = fileparse($dsp_bin_file,qr/\.+?.*/);
my $dsp_dst_file = "$target_dir/${name}_${dsp_version}${suffix}";
if ($dsp_version !~ /DSP/) {
	&error_handler("Cannot find the \"DSP\" pattern in the DSP version \"$dsp_version\", it may cause download fail.", __FILE__, __LINE__);
}
copy($dsp_bin_file,"$dsp_dst_file") or &error_handler("copy $dsp_bin_file to $dsp_dst_file $!", __FILE__, __LINE__);

if ($need_cp_sig eq "TRUE" && -e "$dsp_bin_file.sig") {
	copy("$dsp_bin_file.sig","$dsp_dst_file.sig") or &error_handler("copy $dsp_bin_file.sig to $dsp_dst_file.sig $!", __FILE__, __LINE__);
}

# write the DSP file to cp_dsp_info.tmp for cmmgen
open(FH,">$info_out_file") or &error_handler("Cannot open $info_out_file!", __FILE__, __LINE__);
print FH "DSPMOLY_BIN = $dsp_dst_file\n";
close(FH);
#****************************************************************************
# subroutine: Usage
#****************************************************************************
sub Usage
{
	warn <<"_END_OF_USAGE";
Usage:
	perl cp_dsp_files.pl dsp_folder build_dsp_folder bin_folder platform label
Example:
	perl tools/cp_dsp_files.pl ./modem/dsp_bin ./build/project/flavor/bin/dsp ./build/project/flavor/bin MTXXXX XX_XX_W1X_1X
	
_END_OF_USAGE
	exit 1;
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;
    
    my $final_error_msg = "COPY_DSP_FILES ERROR: $error_msg at $file line $line_no\n";
    print $final_error_msg;
    die $final_error_msg;
}
