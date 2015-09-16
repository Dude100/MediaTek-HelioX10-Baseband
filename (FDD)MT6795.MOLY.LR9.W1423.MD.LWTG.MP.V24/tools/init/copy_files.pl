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
##*   copy_files.pl
##*
##* Project:
##* --------
##*   Maui_Software
##*
##* Description:
##* ------------
##*   This script copy the files and directories to another position and 
##*
##* Author:
##* -------
##*   kk Lin-Wang  (mtk04222)
##*
##*============================================================================

use strict;
use warnings;
use File::Copy;
use File::Basename;

($#ARGV < 1) && &Usage;

#opt
my $opt = $ARGV[0];
shift(@ARGV);

# the destination
my $dest = pop(@ARGV);

# source files
my @src = @ARGV;

if ($opt =~ /^\-f\b/i)
{
	@src = glob("@src");
	copy_file($dest,@src);
}
elsif ($opt =~ /^\-r\b/i)
{
	copy_dir(@src,$dest);
}
else
{
  &Usage;
}

#******************************************************************************
## FUNCTION
##  copy_files 
## DESCRIPTION
##  copy files to another position
## PARAMETER
##  @src	[IN]	an array of source files 
##  $des	[IN]	the destination of copying files
##
## EXAMPLE
##  &copy_files($des, @src);
###******************************************************************************
sub copy_file
{
	my ($des, @src) = @_ ;
	my $bname = "";
	foreach my $src_file (@src)
	{
		if (-f $des)
		{
			unlink($des) or die "[copy_files.pl][Error:] remove '$des' failed: $!";
		}
		elsif (-d $des)
		{
			$bname = basename($src_file);
			if (-e "$des/$bname")
			{
				unlink("$des/$bname") or die "[copy_files.pl][Error:] remove '$des/$bname' failed: $!";
			}
		}
		copy($src_file ,$des) or die "[copy_files.pl][Error:] copy '$src_file' to '$des' failed: $!";
	}
}


#******************************************************************************
## FUNCTION
##  copy_dir
## DESCRIPTION
##  Copy a directory including sub directories
## PARAMETER
##  $from_dir	[IN]	source folder
##  $to_dir		[IN]	destination folder
## EXAMPLE
###******************************************************************************
sub copy_dir
{
	my ($from_dir, $to_dir) = @_;
	opendir my($dir), $from_dir or die "[copy_files.pl][Error:] Could not open dir '$from_dir': $!";
	for my $file (readdir $dir)
	{
		next if ($file =~/\.$/ || $file =~/\b\.\.\b/ );
		my $src = "$from_dir/$file";
		my $dest = "$to_dir/$file";
		
		if(!-d $to_dir)
		{
			mkdir($to_dir) or die "[copy_files.pl][Error:] Create folder '$to_dir' failed: $!";
		}
		
		if(-d $src)
		{
			&copy_dir($src, $dest);
		}
		else
		{
			if(-e $dest){
				unlink("$dest") or die "[copy_files.pl][Error:] remove '$dest' failed: $!";			
			}
			copy($src, $dest) or die "[copy_files.pl][Error:] copy '$src' to '$dest' failed: $!";
			chmod(0640,$dest) if ($^O eq "MSWin32");
		}
	}
	closedir($dir);
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
	copy_files.pl [-f|-r] [source[file1, file2,...]] [destination]
Example:
	perl copy_files.pl -f source_file1 source_file2 destination
	perl copy_files.pl -f source_file destination_file
	perl copy_files.pl -r source_DIR destination_DIR
Description:
	-f	Suppresses prompting to confirm you want to overwrite an existing destination file.
	-r	copy directories recursively
	
_END_OF_USAGE
	exit 1;
}

