#!/usr/bin/perl 
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
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
#
#*****************************************************************************
#*****************************************************************************
##*
##* Filename:
##* ---------
##*   chk_sysdrv_log.pl
##*
##* Project:
##* --------
##*   MOLY
##*
##* Description:
##* ------------
##*   This script parse the chksysdrv.log and check it's error or not 
##
##* Author:
##* -------
##*   kk Lin-Wang  (mtk04222)
##*
##*============================================================================
use strict;
use warnings;
use File::Path;

my $log_path = $ARGV[0]; # log file path
my $bin_path = $ARGV[1]; # bin file path
($#ARGV < 1) && &Usage;

open (FLOG, "<$log_path") or &error_handler("$log_path : file error!", __FILE__, __LINE__);
my $backup = $/;
undef $/;
my $reading = <FLOG>;
close(FLOG);

if ($reading =~ /Shortage/i) {
	print "Error: cksysdrv has errors. Delete the binary file.\n";
	if (-f $bin_path){
		unlink("$bin_path") or &error_handler("$bin_path : file error!", __FILE__, __LINE__);
	} 
	elsif (-d $bin_path) {
		rmtree($bin_path) or &error_handler("$bin_path : file error!", __FILE__, __LINE__);	
	}
	exit 1;
}



#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;
    
    my $final_error_msg = "ERROR: $error_msg at $file line $line_no\n";
    print $final_error_msg;
    die $final_error_msg;
}

#******************************************************************************
## FUNCTION
##  Usage
## DESCRIPTION
##   Display the manipulation of this script
##******************************************************************************
sub Usage
{
	warn <<"_END_OF_USAGE";
Usage:
	chk_sysdrv_log.pl [Path of ckSysDrv.log] [Path of bin file]
Description:
	check whether if there is existing error in cksysdrv.log or not.
_END_OF_USAGE
	exit 1;
}

