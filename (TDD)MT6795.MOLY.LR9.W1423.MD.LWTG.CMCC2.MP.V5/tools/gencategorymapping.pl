#!/usr/bin/perl -w
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

use File::Find;
my $OUT_FLIE = $ARGV[0];

if (-e $OUT_FLIE){
  unlink $OUT_FLIE;
}

my @MAKEFILE_FOLDERS  = qw/ module\/driver module\/middleware module\/modem module\/service  /;

my @makefiles;


foreach $category (@MAKEFILE_FOLDERS) {
  &findMakefiles("make/$category");
}


open FILE, ">>$OUT_FLIE" or die "[ERROR] open file fail.";
foreach $path (@makefiles){
  if ($path =~ /make\/(.*)\/(\S*).mak/){
    $module = uc $2;
    print FILE $module."_MODULE_CATEGORY = $1\n";
    #print "$path\n";
  }
  if ($path =~ /make\/module\/([^\/]*)/){
    print FILE $module."_CATEGORY = $1\n";
  }
}
close FILE;

##
sub findMakefiles{
  my ($root) = @_;
  
  # find the 1st-level makefile
  my @mak = glob "$root/*.mak";
  @makefiles = (@makefiles, @mak);
    
  # find the sub-folders
  my @temp = glob "$root/*";
  my @subfolders;
  for (@temp) {
    @subfolders = (@subfolders,$_) if (-d $_);
  }

  for (@subfolders) {
    #print "$_\n";
    &findMakefiles("$_");
  }
}
    
