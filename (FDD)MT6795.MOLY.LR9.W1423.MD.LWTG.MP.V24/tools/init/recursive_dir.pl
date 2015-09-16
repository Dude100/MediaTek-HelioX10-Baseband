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
##*   find.pl
##*
##* Project:
##* --------
##*   MOLY_Software
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
use File::Find;

my $option = "all";
my $root_dir;
my $regex;
my $re_code;
my @all_list;

# process arguments
if($#ARGV >= 0){
	$option = shift;
	if ($option =~ /^\-f\b/) {
		$option = "file";
	} elsif ($option =~ /^\-d\b/) {
		$option = "folder";
	} else {
		unshift @ARGV, $option;
		$option = "all";
	}
}
$root_dir = shift || '.';
$regex    = shift || '.';
&error_handler("$root_dir can Not be found !", __FILE__, __LINE__) if(! -e $root_dir);

# search recursively
find(\&want ,$root_dir);

# list the search results by option
$re_code = &output_lists(\@all_list, $regex);
&error_handler("execution failed!", __FILE__, __LINE__) if($re_code != 0);

#******************************************************************************
# FUNCTION
#  want
# DESCRIPTION   
#   The function does whatever verifications you want.
#******************************************************************************
sub want
{
	if ($option eq "all") {
		push @all_list,  $File::Find::name if(-e $_);
	} elsif ($option eq "file") {
		push @all_list,  $File::Find::name if(-f $_);
	} elsif ($option eq "folder") {
		push @all_list,  $File::Find::name if(-d $_);
	} else {
		&error_handler("No such option valut: $option !", __FILE__, __LINE__)
	}
}


#******************************************************************************
# FUNCTION
#  output_lists
# DESCRIPTION   
#   output the files/folders according to regular expr
# PARAMETER
#   @list : output list
#   $rule : regular expression
#******************************************************************************
sub output_lists
{
	my $lists = shift;
	my $rule  = shift;
	foreach my $f (@$lists)
	{
	 	next if($f eq ".");
	 	next if($f eq "..");
		print $f."\n" if($f =~ /$rule$/);
	}

	return 0;
}


#****************************************************************************
# FUNCTION
#  error_handler
# PARAMETER
#  $error_msg:  error message
#  $file     :  file
#  $line_no  :  line number
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;
    
    my $final_error_msg = "RECURSIVE_DIR Error: $error_msg at $file line $line_no\n";
    print $final_error_msg;
    die $final_error_msg;
}


#******************************************************************************
# FUNCTION
#  Usage
# DESCRIPTION
#   Display the manipulation of this script
#******************************************************************************
sub Usage
{
	warn <<"_END_OF_USAGE";
Usage:
	perl recursive_dir.pl [-f|-d] [path] [regular expression]
Description:
	List directory/sub-directory contents.
	By default, the path and regular expression is '.'
	-f only list the files.
	-d only list the folders.
Example:
	current path:
	  -foo (folder)
	  --foo.pl (file)
	  -sum.txt (file)
	=====================================
	ex1:
	Command:
		perl recursive_dir.pl 
	Output:
		./sum.txt
		./foo
		./foo/foo.pl
	------------------------------------
	ex2:
	Command:
		perl recursive_dir.pl -f
	Output:
		./sum.txt
		./foo/foo.pl
	------------------------------------
	ex3:
	Command:
		perl recursive_dir.pl foo
	Output:
		foo
		foo/foo.pl
	------------------------------------
	ex4:
	Command:
		perl recursive_dir.pl foo "\\.pl"
	Output:
		foo/foo.pl
	------------------------------------

_END_OF_USAGE
	exit 1;
}

