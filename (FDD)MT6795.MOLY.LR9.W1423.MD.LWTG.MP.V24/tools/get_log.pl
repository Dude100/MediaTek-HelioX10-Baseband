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
#*   get_log.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This script will parse compile logs and dump them to a single log file.
#*
#* Author:
#* -------
#*   Frank Wu  (mtk01760)
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
use File::Basename;
my $LOG_FILE = $ARGV[0];
my $LOG_PATH = $ARGV[1];
if (defined $ARGV[2]) {
  $HEADER_REF = $ARGV[2];
  $HEADER_FLD = $ARGV[3];
  $HEADER_FLD =~ s/\\/\//g;
}

my $line = 0;
my %errFile;
open LOG_FILE,"<$LOG_FILE" or die "cannot open $LOG_FILE:$!\n";
while(<LOG_FILE>) {
  $line++;
  next if($line == 1);
  if ($_ =~ /.+\*\*\*.+\[(.+)\.obj\].+/ig) {
  	$errFile{uc($1)}=1;
  }
}
close LOG_FILE;

# Get original header file paths from tools\copy_mmi_inlude_h.bat
if (defined $ARGV[2]) {
  open HEADER_REF,"<$HEADER_REF" or die "Cannot open $HEADER_REF";
  while(<HEADER_REF>) {
  	$_ =~ s/\\/\//g;
    if ($_ =~ /(\S+\.h)/) {
    	$file = $1;
    	$fdir=dirname($file);
    	$fname=basename($file);
      $path{lc("$HEADER_FLD/$fname")} = "$fdir/$fname";
      push @header, $fname;
    }
  }
  close HEADER_REF;
}

our  @LOGFILES;

if (opendir(LOGDIR, $LOG_PATH)) {
  @LOGFILES = sort readdir(LOGDIR);
  closedir(LOGDIR);
}

open LOG_FILE,"<$LOG_FILE" or die "cannot open $LOG_FILE:$!\n";
my $newlog;
my $printlog;
my $file;
my $log;
my $filename;
$line = 0;
while(<LOG_FILE>) {
  $line++;
  if ($line == 1) {
  	$newlog.=$_;
  	$printlog = 1;
  } else {
    if ($printlog == 1) {
      foreach $file (@LOGFILES) {
        next if ($file eq ".");
        next if ($file eq "..");
        $file =~ /(.+)\.log/;
        $filename = $1;
        next if ($errFile{uc($filename)} == 1);
      
        open f,"<$LOG_PATH/$file" or die "cannot open $LOG_PATH/$file:$!\n";
        my $backup= $/;
        undef $/;
        $log .= <f>;
        $/ = $backup;
        close f;
      }
      $log =~ s/\\/\//g;
      if (defined $ARGV[2]) {
        foreach $h(@header){
          $ori_h_file = $path{lc("$HEADER_FLD/$h")};
          $log =~ s/$HEADER_FLD\/$h/$ori_h_file/ig;
        }
      }
      $printlog = 0;
    
      $newlog.=$log;

      $log = "";
    }
    if ($_ =~ /.+\*\*\*.+\[(.+)\.obj\].+/ig) {
      if (-e "$LOG_PATH/$1.log") {
    	  open f,"<$LOG_PATH/$1.log" or die "cannot open $LOG_PATH/$1.log:$!\n";
    	  my $backup= $/;
        undef $/;
        $log = <f>;
        $/ = $backup;
        close f;
        $log =~ s/\\/\//g;
        if (defined $ARGV[2]) {
          foreach $h(@header){
          	$ori_h_file = $path{lc("$HEADER_FLD/$h")};
          	$log =~ s/$HEADER_FLD\/$h/$ori_h_file/ig;
          }
        }
        $newlog.=$log;
      }
    }
    $newlog.=$_;
  }
}

open LOG_FILE,"+<$LOG_FILE" or die "cannot open $LOG_FILE:$!\n";
  # clear all file content
  truncate(LOG_FILE,0);
  # then insert the content of $LOG_FILE
  seek(LOG_FILE,0,0);
  print LOG_FILE $newlog;  
close LOG_FILE;

