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
package dcmcomp_process;
#****************************************************************************
# Included Modules
#****************************************************************************
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use vivaHelper;
use File::stat;
use Math::BigInt;

#****************************************************************************
# Constants
#****************************************************************************
my $dcmcmpBinaryName = "DYNAMIC_COMP_CODE";
my $lzma_exe = "tools\\7lzma.exe";
my %info = ("name" => "DCM with Compression",
            "binary_name" => $dcmcmpBinaryName,
            "struct_name" => "dcmcmp",
            "entry_function" => \&Process);


#****************************************************************************
# subroutine:  Process
# description: Perform the ZIMAGE post build process.
# input:       Binary folder, available start address,
#              original start address ref, original size ref
# output:      Actual start address, new binary size
#****************************************************************************
sub Process
{
   my $binaryFolder = shift;
   my $availableStartAddress = shift;
   my $startAddressRef = shift;
   my $sizeRef = shift;

   my $dcmcmpEnabled = &vivaHelper::GetMakefileOption("DCM_COMPRESSION_SUPPORT");
   if (defined $dcmcmpEnabled and $dcmcmpEnabled eq "TRUE")
   {
      my $binary = "$binaryFolder\\$dcmcmpBinaryName";
      processBody($binaryFolder);

      # Update start address and binary size
      # Need 4 byte align
      $$startAddressRef = &vivaHelper::RoundUpToAlignment($availableStartAddress, 4);
      $$sizeRef = -s $binary;

      return 1;
   }
   else
   {
      return 0;
   }
}

#****************************************************************************
# subroutine:  GetInfo
# description: Get the basic information of processing
# input:       None
# output:      Info ref
#****************************************************************************
sub GetInfo
{
   return \%info;
}

#****************************************************************************
# subroutine:  processBody
# description: Perform the ZIMAGE post build process.
# input:       Binary folder
# output:      None
#****************************************************************************
sub processBody
{
   my ($processed_folder) = @_;
   my @Binary_Files = ();
   my @Compress_List = ();

   my $lzma_exe = "tools\\7lzma.exe";

   die "compression tool $lzma_exe do NOT exist!\n" if (!-e $lzma_exe);

   if(-d "$processed_folder"){
     opendir DIRHANDLE, "$processed_folder";
     @Binary_Files =  grep { !/^\.{1,2}$/ and -f "$processed_folder\\$_"} readdir (DIRHANDLE);
     close DIRHANDLE;
   } else {
     die "$processed_folder bin file folder do NOT exist!!!\n";
   }

   my $base_identifier = "DCM_COMPRESS_CANDIDATE_HDR_V01";
   $base_identifier = unpack('V1', "$base_identifier");

   my $output_identifier = "DCMGBODY";

   foreach (@Binary_Files){
     my $B_file = $_;
     open (FILE, "<$processed_folder\\$B_file") or die "cannot open $processed_folder\\$B_file\n";
     binmode(FILE);
     (read FILE, $identifier, 32);
     my $tmp_id = $identifier;
     $identifier = unpack('V1', $identifier);
     (read FILE, $checksum, 4);
     $checksum = unpack('V1', $checksum);
     push(@Compress_List,$B_file) && next if (($identifier eq $base_identifier) && (&checksum($tmp_id,$checksum)));

     $identifier = "";
     seek(FILE, 0, 0);
     (read FILE, $identifier, 8);
     unpack('C', $identifier);

     $output_file = "$B_file" if ($identifier eq $output_identifier);
     close FILE;
   }

   my $comp_files_cnt = $#Compress_List + 1;
   print "Total $comp_files_cnt files need to be compressed to $output_file\n";

   if($output_file eq "") {
   	print "Error: DCM output file is not existed!\n";
   	exit 1 ;
   }

   system("rd $processed_folder\\DYNAMIC_COMP_BIN") if (-d "$processed_folder\\DYNAMIC_COMP_BIN");
   system("md $processed_folder\\DYNAMIC_COMP_BIN");

   system("copy $processed_folder\\$output_file $processed_folder\\DYNAMIC_COMP_BIN\\$output_file.bin");

   open (OUTFILE, "+<$processed_folder\\$output_file") or die "cannot open $processed_folder\\$output_file\n";
   binmode(OUTFILE);
   seek(OUTFILE, 104, 0);
   print OUTFILE pack("V1",$comp_files_cnt);

   my $processed_cnt = 0;
   foreach (@Compress_List) {

   	my $current_file = $_;

     system("$lzma_exe e $processed_folder\\$current_file $processed_folder\\$current_file.gz");
     system("rename $processed_folder\\$current_file $current_file.bin");
     system("rename $processed_folder\\$current_file.gz $current_file");

   	open (FILE, "<$processed_folder\\$current_file.bin") or die "cannot open $processed_folder\\$current_file.bin\n";
     binmode(FILE);
     seek(FILE, 36, 0);
     (read FILE, $img_id, 4);
     $img_id = unpack('V1', $img_id);
     (read FILE, $img_exec_base, 4);
     $img_exec_base = unpack('V1', $img_exec_base);
     (read FILE, $img_zi_base, 4);
     $img_zi_base = unpack('V1', $img_zi_base);
     (read FILE, $img_zi_size, 4);
     $img_zi_size = unpack('V1', $img_zi_size);

     $comp_size = stat("$processed_folder\\$current_file")->size;
     $original_size = stat("$processed_folder\\$current_file.bin")->size;

     my $header_pos = 108 + 28*$processed_cnt;

     seek(OUTFILE, 0, 2);
     my $last_position = tell(OUTFILE);

     seek(OUTFILE, $header_pos, 0);
     print OUTFILE pack("V1",$img_id);
     print OUTFILE pack("V1",$img_exec_base);
     print OUTFILE pack("V1",$img_zi_base);
     print OUTFILE pack("V1",$img_zi_size);
     print OUTFILE pack("V1",$original_size);
     print OUTFILE pack("V1",$comp_size);
     print OUTFILE pack("V1",$last_position);
     seek(OUTFILE, $last_position, 0);
     open (GZFILE, "<$processed_folder\\$current_file") or die "cannot open $processed_folder\\$current_file\n";
     binmode GZFILE;
     while (read(GZFILE, $buf, 4)) {
       print OUTFILE $buf;
     }
     close GZFILE;
     close FILE;

     system("move /y  $processed_folder\\$current_file $processed_folder\\DYNAMIC_COMP_BIN\\$current_file");
     system("move /y  $processed_folder\\$current_file.bin $processed_folder\\DYNAMIC_COMP_BIN\\$current_file.bin");

     $processed_cnt ++;

   }

   close OUTFILE;
}

sub checksum {
	my ($identifier,$id_checksum) = @_;
  my $count = 0;
  my $checksum1="";
  my $checksum2="";
  my $checksum="";
  my @buffer = split(//,$identifier);
  my @buffer2 = reverse @buffer;
  foreach (@buffer2) {
    if ($count % 4 < 3) {
      $checksum1 = $checksum1.unpack("H*",$_);
    }
    if ($count % 4 == 3) {
      $checksum2 = $checksum1.unpack("H*",$_);
      $checksum = eval($checksum+hex($checksum2));
      $checksum1=undef;
      $checksum2=undef;
    }
    $count++;
  }
  $checksum=$checksum%(Math::BigInt->new('0x100000000'));
  my $result = ($checksum eq $id_checksum) ? 1 : 0;
  return $result;
}

sub Usage {
  print "perl dcmcomp_process.pl <bin file folder>\n";
  exit 1;
}