#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2011
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
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#* 
#* 09 21 2012 yen-tsung.cheng
#* [MOLY00003906] [SystemService][Auto-Gen][Internal Refinement] Support BOOT_CERT & multibin on MOLY
#* <saved by Perforce>
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************
use File::Basename;
use File::Copy;
use strict;

my($debug) = 1;

#Usage: gfh_process.pl BINFILE_PATH(folder or file) IntermediateFile MakeFile

my ($bin_file)    = $ARGV[0];
my ($intermediate) = $ARGV[1];
my ($makefile)     = $ARGV[2];
my ($log_file)    = $ARGV[3];

my($pbp_win32)= 'tools/pbp.exe';
my($pbp_linux)= 'tools/pbp';
my($key)      = 'tools/key_info.ini';
my($key_pubk) = 'tools/key_info_pubk.ini';
my($setting)  = 'tools/brom_setting.ini';

my($pbp) = $^O=~/linux/i ? $pbp_linux : $pbp_win32;
  
die "Intermediate file $intermediate doesn't exist" if not -e $intermediate;

if(-d $bin_file)
{#process inside bin
    opendir(BIN_DIR, $bin_file) or die "cannot open build folder $bin_file!";
    while (defined(my $strBinFileName = readdir(BIN_DIR)))
    {
        my $strBinFilePath = "$bin_file/$strBinFileName";
        if ($strBinFileName !~ /\.txt$|\.cfg$/ and !-d $strBinFilePath)
        {
            &ExecutePBPByName($strBinFilePath);
        }
    }
    closedir(BIN_DIR);
}
elsif(-e $bin_file)
{
    &ExecutePBPByName($bin_file);
}

exit 0;


sub ExecutePBPByName
{
    my ($strBinFilePath) = @_;
    my $result = 0;
    if(&IsGFH($strBinFilePath))
    {
        my $strBinFileName = basename($strBinFilePath);
        if($strBinFileName =~ /BOOT_CERT/i)
        {#skip BOOT_CERT due to causing Error: Something wrong in GFH parsing, 8001
            print "==> skip BOOT_CERT processing\n";
            return;    
        }
        elsif($strBinFileName =~ /SECURE/i)
        {
            $result = &call_pbp("-secro",$strBinFilePath);
        }
        elsif ($strBinFileName =~ /BOOTLOADER/i) 
        {
            $result = &call_pbp("-bootloader",$strBinFilePath);
        }
        else
        {
            $result = &call_pbp("-maui",$strBinFilePath);
        }
        
        if($result !=0)
        {
        #    my $Error = &IsPBPWrong($log_file);
        #    if($Error != 8001)
        #    {
                print("Error[$result]: Failed in gfh_process.pl\n");
                exit $result;
        #    }
        }
    }
}

sub call_pbp
{
   my($status) = 0;
   my($arg, $file) = @_;

   backupOrigBin($file) if $debug;
   print("==> Proecssing $file\n");
   my $cmd = "$pbp -m $intermediate -m \"$makefile\" -i $key -i $key_pubk -i $setting $file";
   print("cmd=$cmd\n");
   print "====================================================\n";
   #$status = system("$pbp", "-m", $intermediate, "-m", $makefile, "-i", $key, "-i", $key_pubk, "-i", "$setting", $file);
   $status = system($cmd);
   print "====================================================\n";
   print("[call_pbp]status=", $status, "\n\n");
   return($status>>8) if $status != 0;
   return 0;
}


sub backupOrigBin
{
   my($strBinFilePath) = @_;
   my($path, $file) = (dirname($strBinFilePath), basename($strBinFilePath));
   my($backup_path) = "$path/backup";
   print "Backup $file to $backup_path\n";
   mkdir($backup_path) if(! -d $backup_path);

   copy($strBinFilePath, "$backup_path/$file.orig") or die "$!";
}

sub IsGFH
{
    my ($strFilePath) = @_;
    my $bIsGFH = 0;
    
    if(-e $strFilePath)
    {
        # Get 17bytes (0-2: 4D 4D 4D, 8-16: FILE_INFO 
        open (FILE_HANDLE, "<$strFilePath") or &error_handler("$strFilePath: open file error!");
        #binmode(FILE_HANDLE);
        my ($nIndex, $data) = (0, undef);
        my @Buffer;
        while(read(FILE_HANDLE, $data, 1))
        {
            $Buffer[$nIndex++] = $data;
            last if($nIndex > 16);
        }
        close FILE_HANDLE;
        my ($strFILE_INFO, $nMatchMMM) = (undef, 0);
        for(0..2)
        {
            $nMatchMMM++ if(ord($Buffer[$_]) == 0x4D);
        }
        for(8..16)
        {
            $strFILE_INFO .= $Buffer[$_];
        }
        $bIsGFH =1 if($nMatchMMM == 3 and $strFILE_INFO eq "FILE_INFO");
    }
    return $bIsGFH;
}

sub IsPBPWrong
{
    my ($strLogPath) = @_;
    my $Error = 0;
    open FILE, "<$strLogPath" or &error_handler("$strLogPath: open file error!");
    while(<FILE>)
    {
        my $line = $_;
        $Error= 1 if($line =~ /Error/);
        if($line =~ /Error:(.*)(\d{4,})/)
        {
            $Error = $2;
            print "\n[Parsing Log File]Error Message: $1$Error\n";
            last;
        }
    }
    close FILE;
    return $Error;
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#              $file:          filename
#              $line_no:       line number
#****************************************************************************
sub error_handler
{
    my ($error_msg) = @_;
    my ($pack_name, $file, $line_no) = caller;
    my $final_error_msg = "GFH_PROCESS ERROR: $error_msg at $file line $line_no\n";
    die $final_error_msg;
}
