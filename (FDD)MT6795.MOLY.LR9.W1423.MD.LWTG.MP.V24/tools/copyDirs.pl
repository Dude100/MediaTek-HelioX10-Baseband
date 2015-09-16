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
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   copyDirs.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   To avoid "The inout line is too long" issue on Windows2000.
#*
#* Author:
#* -------
#*
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/
$FIXPATH = $ARGV[0];
print "$FIXPATH\n";

$RELEASE_DIR = $ARGV[1];
print "$RELEASE_DIR\n";
$DIRLIST = $ARGV[2];
print "$DIRLIST\n";

@tempDirs = ();
open(LIS_FILE,"<$DIRLIST") or die "Cannot open $file: $!";
while(<LIS_FILE>){
  chomp;
  if(/\\$/){
   chop;
  }
  print "$FIXPATH\\$_\n";
  if(-e "$FIXPATH\\$_"){
   push @tempDirs, $_;
  }
}
close(LIS_FILE);

@Dirs = ();
&RemovalSubdir();

open FILE_HANDLE, ">build\\xcopy_exclude.txt" or die "Fail to write build\\xcopy_exclude.txt";
print FILE_HANDLE "tools\\GCC\\\n";
print FILE_HANDLE "tools\\MinGW\\\n";
print FILE_HANDLE "tools\\MSYS\\\n";
close FILE_HANDLE;

for my $dir(@Dirs) {
  if (-e $dir){
    print "xcopy /e /y /q $FIXPATH\\$dir $RELEASE_DIR\\$dir\\*.* /EXCLUDE:build\\xcopy_exclude.txt\n";
    system("xcopy /e /y /q $FIXPATH\\$dir $RELEASE_DIR\\$dir\\*.* /EXCLUDE:build\\xcopy_exclude.txt");
  }
  else{
    chop($dir);
    print "xcopy /e /y $FIXPATH\\$dir $RELEASE_DIR\\$dir\\*.* /EXCLUDE:build\\xcopy_exclude.txt\n";
    system("xcopy /e /y $FIXPATH\\$dir $RELEASE_DIR\\$dir\\*.* /EXCLUDE:build\\xcopy_exclude.txt");
  }
}

sub RemovalSubdir{
	@tempDirs = sort @tempDirs;
  my $predir = shift @tempDirs;
  push @Dirs, $predir;
  $predir = quotemeta($predir);
  for my $dir(@tempDirs){
    my $tempdir = quotemeta($dir);
    if($tempdir =~ /^$predir/i){
      next;
    }
    else{
      push @Dirs, $dir;
      $predir = $tempdir;
    }
  }
}
