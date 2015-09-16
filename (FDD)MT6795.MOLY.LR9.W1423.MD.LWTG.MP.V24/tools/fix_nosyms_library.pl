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
#*   fix_nosyms_library.pl
#*
#* Project:
#* --------
#*   MAUI
#*
#* Description:
#* ------------
#*   This script will add a armlibc_rvct.obj into a library, armlibc_rvct.obj only
#*     has a single useless ____mtk_fix_empty_library_function_should_not_be_used_by_anybody
#* Author:
#* -------
#*   Shuguang Wen (mtk80458)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#* 
#* 08 16 2012 ying.xin
#* [MOLY00002197] [gcc]newlib tailoring and performance optimization check in
#* .
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/
#

use warnings;
use strict;

sub generate_unused_object {
	my $ARMCC = "armcc";
	my $source = <<END;
	
	#pragma arm section code="SHOULDBE_EMPTYSECTION"
	void ____mtk_fix_empty_library_function_should_not_be_used_by_anybody(void)
	{
		return;
	}
	
END
	
	open FH, ">", "armlibc_rvct.c" || die "Can't open armlibc_rvct.c for writing";
	print FH $source;
	close FH;
	
	my $status = system($ARMCC, "-c", "-o", "armlibc_rvct.obj", "armlibc_rvct.c");
	if ($status != 0) {
		die "Can't compile armlibc_rvct.c";
	}
}

sub usage {
	print STDERR "usage: perl $0 {option}* {library path to be fix}+\n";
	print STDERR "supported options:\n";
	print STDERR "    --force		replace armlibc_rvct.obj in library unconditionally\n";
}

# a specicial function to search object file in a library
if ($#ARGV >= 0 && $ARGV[0] eq "--search_object") {
	my @objects = ();

	shift @ARGV;
	for (my $i = 0; $i <= $#ARGV; $i++) {
		push @objects, $ARGV[$i];
	}
	exit 0 if $#objects == -1;
	
	open FH, "<", "make/~sortedLibs.tmp" or die "can't find make/~sortedLibs.tmp";
	my @words = map { chomp; split /\s+/; } <FH>;
	close FH;
	
	foreach my $f (@words) {
		next if $f =~ /^-/;
		next if not ($f =~ /\.lib$/ || $f =~ /\.a$/);
		next if not -f $f;
		
		open FH, "-|", "armar -t $f" or next;
		my @objs_in_lib = map { chomp; split /\s+/; } <FH>;
		close FH;
		#print join("\n", @objs_in_lib);
		
		foreach my $r (@objects) {
			foreach my $o (@objs_in_lib) {
				if (lc $r eq lc $o) {
					print "found $r in $f\n";
					last;
				}
			}
		}
	}
	exit 0;
}

my $force_fix = 0;
my @to_be_fix_libs = ();
foreach (@ARGV) {
	if ($_ eq "--force") {
		$force_fix = 1;
	}
	else {
		push @to_be_fix_libs, $_;
	}
}
if ($#to_be_fix_libs < 0) {
	print STDERR "No library need to be fix\n";
	usage;
	exit 1;
}

generate_unused_object;

for my $lib (@to_be_fix_libs) {
	if (not -f $lib) {
		print "$lib: failed, can't find this library\n";
		next;
	}
	open PIPE, "-|", "armar -t $lib";
	my @lib_objs = map { chomp; split /\s+/; } <PIPE>;
	close PIPE;
	if ($? != 0) {
		print "$lib: failed, can't use armar -t to extract contents\n";
		next;
	}
	if (not $force_fix) {
		my $has_it = grep { lc $_ eq "armlibc_rvct.obj" } @lib_objs;
		if ($has_it) {
			print "$lib: failed, already has armlibc_rvct.obj\n";
			next;
		}
	}
	my $status = system("armar", "-sr", "$lib", "armlibc_rvct.obj");
	if ($status != 0) {
		print "$lib: failed, can't add armlibc_rvct.obj into $lib\n";
		next;
	}
	print "$lib: succeeded\n";
}

unlink "armlibc_rvct.c", "armlibc_rvct.obj";
