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

use strict;
my $logPath = "$ARGV[0]/bin/log";
my $logPath_modis = "$ARGV[0]/MoDIS/_BUILD_LOG";
my $modisConfig = "false";
my $debugPrint = 0;
my $filename;
my $outStr = "";
my $outFile = "$ARGV[2]/comp_err.txt";

unlink $outFile if(-e $outFile);

if (defined $ARGV[1])
{
  $modisConfig = lc($ARGV[1]);
}
else
{
  $debugPrint = 1;
}
if (defined $ARGV[3] && $ARGV[3] eq "TRUE")
{
  $debugPrint = 1;
}

if ($modisConfig eq "true")
{
  $logPath = "$ARGV[0]/MoDIS/_BUILD_XGEN/bin/log";
  $filename = "${logPath_modis}/codegen.log";
}
else
{
  $filename = "${logPath}/codegen.log";
}

if ((-e $filename) && (!-z $filename)) {
  $outStr .= "Codegen might be failed ==> $filename\n";
  open(F, $filename) || die "I can't open $filename";
  while(<F>) {
    next if (/^\s*$/);
    $outStr .= " $_";
  }
  close (F);
}

if ($modisConfig eq "true")
{
  $filename = "${logPath_modis}/mcddll_update.log";
}
else
{
  $filename = "${logPath}/mcddll_update.log";
}

if ((-e $filename) && (!-z $filename)) {
  $outStr .= "mcddll_update might be failed ==> $filename\n";
  open(F, $filename) || die "I can't open $filename";
  while(<F>) {
    next if (/^\s*$/);
    $outStr .= " $_";
  }
  close (F);
}

if ($modisConfig eq "true")
{
  &Output_Error if ($outStr ne "");
  exit 0;
}

my $errModule = 0;
while(defined($filename= <$logPath/*.log>)) {
  next if ($filename =~ /info/);
  next if ($filename =~ /codegen/);
  open(F, $filename ) || die "I can't open $filename";
  my $errFlag = 0;
  my $showthefile = 1;
  my $thefile;
  while(<F>) {
    if (/\/\*.*error\s*:.*\*\//i) {
      next;
    }
    if (/Compiling (\S+)/) {
      $thefile = $1;
      $showthefile = 0;
    } elsif ((/Serious error:/)||(/Error:/i)||(/Fatal error:/)||(/No rule/)||(/dependency errors/) || ((/\bError(s?)\b/)&&($_ !~ /\b0 Errors\b/)&&($filename =~ "bootloader"))) {
      $errModule++;
      if ($errFlag == 0) {
        $errFlag = 1;
        $outStr .= "$filename\n";
      }
      if($showthefile == 0)
      {
        $outStr .= " $thefile:\n";
      }
      $showthefile = 1;
      $outStr .= " $_";
      last if ($errModule > 300);
    }
  } ## while
  close(F);
  last if ($errModule > 300);
} ## while

if ($errModule == 0) {
  while(defined($filename= <$ARGV[0]/bin/*.log>)) {
    open(F, $filename ) || die "I can't open $filename";
    my $errFlag = 0;
    while(<F>) {
      if ((/Serious error:/) || (/Error:/) || (/No rule/) || (/Fatal error:/)) {
        if ($errFlag == 0) {
          $errFlag = 1;
          $outStr .= "$filename\n";
        }
        $outStr .= " $_";
      }
    } ## while
    close(F);
  } ## while
} elsif ($errModule > 300) {
  $outStr .= "\n   Too many errors. Stop parsing.";
}

&Output_Error if ($outStr ne "");
exit 0;

sub Output_Error
{
  if($debugPrint)
  {
    print "Please check following errors:\n";
    print "$outStr\n";
  }
  open (Fout, ">$outFile") || die "Error: cannot open $outFile\n";
  print Fout "$outStr\n";
  close Fout;
}
