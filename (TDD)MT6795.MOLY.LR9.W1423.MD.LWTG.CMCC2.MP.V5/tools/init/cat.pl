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
##*   cat.pl
##*
##* Project:
##* --------
##*   Maui_Software
##*
##* Description:
##* ------------
##*   This script concatenate files and print on the standard output
##
##* Author:
##* -------
##*   kk Lin-Wang  (mtk04222)
##*
##*============================================================================
use strict;
use warnings;

my @target = "";
my $column = -1;
my $binmode = -1;
# parse parameters
foreach my $arg (@ARGV)
{
	if ($arg =~ /^\-cut=(\d+)\b/i)
	{
		print "$1\n";
		$column = $1;
		($column < 0) && &Usage;
	}
	elsif ($arg =~ /^-binary\b/i)
	{
		$binmode = 1;
	}
	else
	{
		push(@target,$arg);
	}
}
($#target < 0) && &Usage;

# replace backslash with slash
foreach my $arg (@target)
{
		$arg =~ s/\\/\//g;
}

# print each file content
my @fs = glob("@target");
&printAllContent(@fs) if($column == -1);
&printCutContent(@fs) if($column != -1);


#******************************************************************************
## FUNCTION
##  printAllContent
##******************************************************************************
sub printAllContent
{
	foreach my $file (@_) 
	{
		open FH, $file or die "[cat.pl][Error:] Failed to open [$file]";
		if($binmode eq 1)
		{
			binmode FH;
			binmode STDOUT;
		}
		print while(<FH>);
		close FH;
	}
}


#******************************************************************************
## FUNCTION
##  printCutContent
##******************************************************************************
sub printCutContent
{
	my @line = ();
	foreach my $file (@_) 
	{
		open FH, $file or die "[cat.pl][Error:] Failed to open [$file]";
		while(<FH>)
		{
			@line = split(' ',$_);
			next if($#line < $column);
			if($line[$column] ne "")
			{
				print $line[$column];
				print "\n";
			}
		}
		close FH;
	}
}

sub Usage
{
	warn <<"_END_OF_USAGE";
Usage:
	cat.pl [source[file1, files2]] 
Example:
	perl cat.pl file1.c file2.c 
	perl cat.pl *.cpp *.c
	perl cat.pl -cut=1 in.txt
	perl cat.pl -binary foo.bin
Description:
	This script concatenate files and print on the standard output.

	-cut=number only output the [#number] column in each line.
	-binary		read/write as binary mode
	[ex1]:
	in.txt:
		string0 string1 string2
		dog cat frog
	command:
		perl cat.pl -cut=1 in.txt
	output:
		string1
		cat

_END_OF_USAGE
	exit 1;
}
