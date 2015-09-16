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
#!/usr/bin/perl
# find out required .(hpp|h|dat|c|hex) for the header sources listed in .lis and in .dep
use File::Copy;
use File::Path;
use File::Basename;
# show usage
sub usage
{
	print "USAGE: perl copyLIS.pl <filename of .lis> <release dir> <MMI DIR> <MMI_VERSION>\n";
	exit(0);
}

#
# parsing command arguments
#

my $LIS_FILE;
my $REL_DIR;
my $reading;

$module = uc $ARGV[0];
$REL_DIR = $ARGV[1];
$categorymapping = $ARGV[2];


$path = "NONE";
open FILE, "$categorymapping" or die "can not find $categorymapping\n";
while (<FILE>){
  my $line = $_;
  if ($line =~ /^\s*${module}_MODULE_CATEGORY\s*=\s*(\S+)/){
    $path = $1;
    last;
  }
}
close FILE;

die "Can not find ${module}_MODULE_CATEGORY in ~categorymapping.mak\n" if($path eq "NONE");
my $modulePath = lc "make//$path";
my $moduleFile = lc "$modulePath//$module.mak";
if(!-e "$REL_DIR//$modulePath"){
	mkpath("$REL_DIR//$modulePath");
}
if(-e "$moduleFile"){
  CopyFile("$moduleFile","$REL_DIR//$moduleFile");
}
else{
  print "Can not find $moduleFile\n";
}

sub CopyFile
{
	my $src = shift;
	my $target = shift;
	my $dest = dirname($target);
	mkpath($dest) if (! -e $dest);
	copy($src, $target);# or die "Fail to copy $src";
}