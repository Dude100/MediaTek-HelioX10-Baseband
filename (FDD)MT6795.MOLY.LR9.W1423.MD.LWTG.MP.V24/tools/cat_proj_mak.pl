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
use strict;
use warnings;
use File::Basename;

my $proj_mak    = $ARGV[0]; # ex: make/MTXXXX.mak
my $output_file = $ARGV[1]; # ex: build/$project/$flavor/tmp/~makefile.mak
if (!-e $proj_mak) {
	&error_handler("$proj_mak is NOT existing !", __FILE__, __LINE__);
}

my $proj_name = basename($proj_mak,".mak");
if (-e $output_file) {
	unlink($output_file) or &error_handler("remove $output_file failed !", __FILE__, __LINE__);
}

my %feature;

#****************************************************************************
# concatenate project makeifle
#****************************************************************************
open (my $FH_OUT, ">>$output_file") or &error_handler("open $output_file failed !", __FILE__, __LINE__);
&recursive_concatenate($proj_mak, $FH_OUT);
close $FH_OUT;

#****************************************************************************
# subroutine:  recursive_concatenate
# input:       $project makefile     output file handle
#****************************************************************************
sub recursive_concatenate
{
	my ($file, $FOUT) = @_;
	my $line = undef;
	&read_feature($file);
	open (my $FIN, "<$file") or &error_handler("open $file failed !", __FILE__, __LINE__);
	while (<$FIN>) {
		$line = $_;
		if (defined($feature{'MODEM_SPEC'}) and ($feature{'MODEM_SPEC'} ne "NONE") and 
				$line =~ /include\s+(make\/modem_spec\/)/ and 
				($line =~ /MODEM_SPEC/ or $line =~ /$feature{'MODEM_SPEC'}/)) {

			my $modem_spec_mak = "make/modem_spec/$feature{'MODEM_SPEC'}.mak";
			print "concatenate $modem_spec_mak\n";
			&recursive_concatenate($modem_spec_mak, $FOUT);
		}
		elsif (defined($feature{'PROJECT_MAKEFILE_EXT'}) and ($feature{'PROJECT_MAKEFILE_EXT'} ne "NONE") and
				$line =~ /include\s+(make\/custom_config\/)/ and 
				($line =~ /PROJECT_MAKEFILE_EXT/ or $line =~ /$feature{'PROJECT_MAKEFILE_EXT'}/)) {
				
			my $proj_mak_ext = "make/custom_config/$feature{'PROJECT_MAKEFILE_EXT'}.mak";
			print "concatenate $proj_mak_ext\n";
			&recursive_concatenate($proj_mak_ext, $FOUT);
		} else{
			print $FOUT $line;
		}
	}
	close $FIN;
}


#****************************************************************************
# Read feature from project makefile
#****************************************************************************
sub read_feature
{
	my $file = $_[0];
	open FILE_HANDLE, "<$file" or &error_handler("open $file failed !", __FILE__, __LINE__);
	while (<FILE_HANDLE>)
	{
		if (/^(\w+)\b\s*=\s*(\S+)/)
		{
			my $keyname = $1;
			defined($feature{$keyname}) && warn "$1 redefined in $file!\n";
			$feature{$keyname} = $2;
		}
	}
	close FILE_HANDLE;
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;
    
    my $final_error_msg = "CONCATENATE Error: $error_msg at $file line $line_no\n";
    print $final_error_msg;
    die $final_error_msg;
}

