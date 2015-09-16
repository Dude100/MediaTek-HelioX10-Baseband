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
##*   dir.pl
##*
##* Project:
##* --------
##*   Maui_Software
##*
##* Description:
##* ------------
##*   list directory contents
##*
##* Author:
##* -------
##*   kk Lin-Wang  (mtk04222)
##*
##*============================================================================
use strict;
use warnings;
use File::Basename;

($#ARGV < 0) && &Usage;

my $newline  = 0;
my $basename = 0;
my @target;

# parse parameters
foreach my $arg (@ARGV)
{
	if ($arg =~ /^\-n\b/i)
	{
		$newline = 1;
	}
	elsif ($arg =~/^\-b\b/i)
	{
		$basename = 1;
	}
	else
	{
		push(@target,$arg);
	}
}
($#target > 0) && &Usage;

# glob the parameter, if not found then invoke sub not_found()
my @filelist = <$target[0]>;
&not_found  if(!@filelist);

my $all_not_found = 1;
foreach my $file (@filelist) 
{
	if( -e $file){
		$file = basename($file) if($basename == 1);
		print "$file";

		if ($newline == 0){
			print "\t";
		}
		else
		{
			print "\n";
		}
		$all_not_found = 0;
	}
}

&not_found if($all_not_found == 1);
print "\n" if($newline == 0);

sub not_found
{
	die "[Error:][dir.pl] File Not Found $!";
}
#my $path = $ARGV[0];
#opendir(DIR, $path) || die "[dir.pl][Error:] failed $!";
#my @dirs = grep !/^\./, readdir(DIR);
#foreach my $file (@dirs)
#{
#	print "$file\t";
#}
#print "\n";
#closedir(DIR);


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
	perl dir.pl [Path] 
Description:
	list directory contents	
	-n list by \\n, default is \\t [ex3]
	-b display the file name and extension only [ex4]
Example:
	List_folder:
	  foo.pl
	  sum.pl
	=====================================
	ex1:
	Command:
		perl dir.pl "List_folder/"
	Output:
		List_folder/
	------------------------------------
	ex2:
	Command:
		perl dir.pl "List_folder/*.pl"
	Output:
		List_folder/foo.pl	List_folder/sum.pl
	------------------------------------
	ex3:
	Command:
		perl dir.pl -n "List_folder/*.pl"
	Output:
		List_folder/foo.pl
		List_folder/sum.pl
	------------------------------------
	ex4:
	Command:
		perl dir.pl -b -n "List_folder/*.pl"
	Output:
		foo.pl
		sum.pl
	------------------------------------
	ex5:
	Command:
		perl dir.pl "List_folder/*.c"
	Output:
		[Error:][dir.pl] File Not Found
	------------------------------------

_END_OF_USAGE
	exit 1;
}

