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
##*   compare.pl
##*
##* Project:
##* --------
##*   Maui_Software
##*
##* Description:
##* ------------
##*   This script compare the input two files
##*
##* Author:
##* -------
##*   kk Lin-Wang  (mtk04222)
##*
##*============================================================================
use strict;
use warnings;
use File::Compare;

($#ARGV < 1) && &Usage;

my $src_a = shift(@ARGV);
my $src_b = shift(@ARGV);
($#ARGV > -1) && &Usage;

my $value = compare("$src_a","$src_b");
&judge($value);

sub judge
{
	my $i = $_[0];
	if($i == 0){
		print "They are equal\n";
		exit 0;
	}
	elsif ($i == 1){
		print "They are NOT equal\n";
		exit 1;
	}
	else
	{	
		die "[compare.pl][Error:] $!\n";
		exit -1;
	}
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
	perl compare.pl [file1] [files2]
Example:
	perl compare.pl source1.c source2.c
Description:
    compares the contents of two sources
	return 0 if equal
	return 1 if not equal
	return -1 if error
_END_OF_USAGE
	exit 1;
}
