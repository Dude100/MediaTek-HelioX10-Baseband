#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2008
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
# Copy files listed in make\$module\$module.lis to the $TARGET.

# show usage

use File::Basename;

sub usage
{
	print "USAGE: perl checkObjFilePath.pl <filename of .lis>\n";
	exit(0);
}

my $LIS_FILE;

$ORIGINAL = $ARGV[0];
$TARGET = $ARGV[1];
$LIS_FILE = $ARGV[2];

$BASE = $ARGV[3];
open BASE,"$BASE" or die "0 Cannot open $BASE\n";
while(<BASE>) {
  chomp($_);
  $base_dir=uc($_);
  $${base_dir}=1;
}
close BASE;

my @SRCModList = (defined $ARGV[4])? split(' ',$ARGV[4]) : ();
foreach $src(@SRCModList) {
  $${src} = 1;
}

my @PSRCModList = (defined $ARGV[5])? split(' ',$ARGV[5]) : ();
foreach $psrc(@PSRCModList) {
  $${psrc} = 1;
}

$GLOBAL_USE = 1;

$EXCLUDE_FILE = $ARGV[6];
open EXCLUDE_FILE,"$EXCLUDE_FILE" or die "1 Cannot open $EXCLUDE_FILE\n";
while(<EXCLUDE_FILE>) {
  chomp($_);
  $_ =~ /(.+) (.+)/;
  $ex_file=uc($2);
  $${ex_file}=$1;
}
close EXCLUDE_FILE;

$RELEASE_PACKAGE = $ARGV[7];

if ($RELEASE_PACKAGE =~ /INET_MMI/i) {
  $INET_MMI = 1;
  $MMI = 1;
} elsif ($RELEASE_PACKAGE =~ /MMI/i) {
  $MMI = 1;
} elsif ($RELEASE_PACKAGE =~ /INET_L4/i) {
  $INET_L4 = 1;
  $L4 = 1;
} elsif ($RELEASE_PACKAGE =~ /L4/i) {
  $L4 = 1;
} elsif ($RELEASE_PACKAGE =~ /INET_PROTOCOL/i) {
  $INET_PROTOCOL = 1;
  $PROTOCOL = 1;
} elsif ($RELEASE_PACKAGE =~ /PROTOCOL/i) {
  $PROTOCOL = 1;
  print "RELEASE_PACKAGE=$RELEASE_PACKAGE $PROTOCOL\n";
} else {
  $OBJ = 1;
}

open LIS_FILE,"$LIS_FILE" or die "2 Cannot open $LIS_FILE\n";

$backup = $/; undef $/;
$reading = <LIS_FILE>;
$/ = $backup;
close LIS_FILE;

@FILE = split(" ",$reading);
system("perl tools\\time.pl -n");
foreach (@FILE) {
  $LIS= $_;
  open LIS,"$_" or die "2 Cannot open $_\n";
  while (<LIS>) {
    chomp($_);
    $file = uc($_);
    $file_dir = uc(dirname($file));
#    if (($${file_dir} == 1) && ($$${file} != 1) && ($file =~ /\.(c|cpp|s)$/i)) {
#      system("echo Error: The object-release $file in $LIS is under the must-be-released folder: $file_dir.>>custom_release_err.log");
#      print "Error: The object-release $file in $LIS is under the must-be-released folder: $file_dir.\n";
#      exit 1;
#    }
#    while ($file_dir =~ /\\/) {
#      $file_dir = uc(dirname($file_dir));
#      if (($${file_dir} == 1) && ($$${file} != 1) && ($file =~ /\.(c|cpp|s)$/i)) {
#        system("echo Error: The object-release $file in $LIS is under the must-be-released folder: $file_dir.>>custom_release_err.log");
#        print "Error: The object-release $file in $LIS is under the must-be-released folder: $file_dir.\n";
#        exit 1;
#      }
#    }
    if (-e "$TARGET\\$file") {
      if (($file =~ /\.(c|cpp|s)$/i) && ($$${file} != 1)) {
        system("echo Error: The object-release $file in $LIS is released to $TARGET\\$file.>>custom_release_err.log");
        print "Error: The object-release $file in $LIS is released to $TARGET\\$file.\n";
        exit 1;
      }
    }
  }
  close LIS;
}
system("perl tools\\time.pl -n");


