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
# find out required .(hpp|h|dat|c|hex|incl|inc) for the header sources listed in .lis and in .dep
use File::Copy;
use File::Path;
use File::Basename;
# show usage
sub usage
{
	print "USAGE: perl copySrcComp.pl <filename of .lis> <path of .dep> <release dir>\n";
	exit(0);
}

#
# parsing command arguments
#

my $arg_idx=0;
my $LIS_FILE;
my $DEP_FILE;
my $reading;

#
# open .lis & .dep
#

$LIS_FILE = $ARGV[0];
open LIS_FILE,"$LIS_FILE" or die "cannot open $LIS_FILE\n";
@reading    = <LIS_FILE>;
$obj_count  = 0;
$obj_list   = '';
foreach (@reading)
{
   if ((s/([0-9a-zA-Z_.\-]+)\.cp?p?\s*$/$1.obj/i) || (s/([0-9a-zA-Z_.\-]+)\.s\s*$/$1.obj/i))  # extract '*.c/cpp/s'
   {
      $obj_list .= " $_";
#      print "$_\n";
      $obj_count++;
   }
}
close LIS_FILE;


$DEP_FILE = $ARGV[1];
open DEP_FILE,"$DEP_FILE" or die "cannot open $DEP_FILE\n";
@reading = <DEP_FILE>;
$dep_count = 0;
$hdr_count = 0;
$needed_obj = 0;
foreach (@reading)
{
  $reading = $_;
  if ($reading =~ /([0-9a-zA-Z_.\-]+\.obj)/)
  {
    my $objName = $1;
    if (index($obj_list, $objName) > -1){         # if the '.obj' is needed in .lis
      $needed_obj = 1;
    }
    else{
      $needed_obj = 0;
    }
  }
  if($needed_obj){
    my @files = split /\s+/,$reading;
    for my $file(@files){
      if($file =~ /\b\S+\.(hpp|hs|hex|dat|cpp|c|h|incl|inc|tbl|def|msg)\s*$/i)      # find out next .(hpp|h|dat|c|hex) in this line
      {
         if ( !($file =~ /c:/i) )      # exclude the c:\progra~1\...\xxx.(hpp|h|dat|c|hex)
         {
            if ( !($req_hdr{$hdr_name}) ) # find out non-duplicated .(hpp|h|dat|c|hex)
            {
               $req_hdr{$file} = 1;
               $hdr_count ++;
            }
            else
            {
               $req_hdr{$file} ++;    # count duplication times of .(hpp|h|dat|c|hex), just for our info.
            }
         }
      }
      $dep_count++;
    }
  }
}
close DEP_FILE;

#print "\n\n$hdr_count .(hpp|hex|dat|cpp|c|h|incl|inc|tbl|def|msg) will be copied: \n";
#$output = "~"."$module"."rh.tmp";
#print "out = $output\n";

#open(W,">$ARGV[2]\\$output");
while ( ($key, $value) = each %req_hdr)
{
  # Copy header files at the same time.
  $targetfile = "$ARGV[2]"."\\$key";
  my $path = dirname($targetfile);
  if (!-e $targetfile) {
    print $targetfile."\n";
    CopyFile("$key","$targetfile");
  }
}
#close(W);

# dump header file list to make\~srccomprh.tmp
#system("type make\\$output >> make\\~srccomprh.tmp");

#system("echo $DEP_FILE $module >> make\\module.tmp");

sub CopyFile
{
	my $src = shift;
	my $target = shift;
	my $dest = dirname($target);
	mkpath($dest) if (! -e $dest);
	copy($src, $target);# or die "Fail to copy $src";
}
