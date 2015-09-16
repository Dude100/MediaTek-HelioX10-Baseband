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
#*   CheckBinaryBlockUsage.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This script will check if code ROM size is enough for all binaries.
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Usage
#****************************************************************************
BEGIN { push @INC, '.\\tools\\' }  # add additional library path             
use Getopt::Std;
use POSIX;

sub Usage {
  print "Usage: perl CheckBinaryBlockUsage.pl ~flash_cfg_tmp.c <BIN_FILE_PATH> <PLATFORM> <BUILD_SYS_PATH>\n";
  exit(1);
}

use File::stat;
use File::Basename;
use Math::BigInt;

#****************************************************************************
# parsing command arguments
#****************************************************************************
$DebugPrint = 1;
print "ARGV[0]:$ARGV[0] ARGV[1]:$ARGV[1] ARGV[2]:$ARGV[2] ARGV[3]:$ARGV[3] ARG_NUM $#ARGV\n" if (0 != $DebugPrint);
while ($#ARGV != -1) {
	if ($ARGV[0] =~ /-h/i) {
		&Usage;
	}
	elsif ($#ARGV == 3) {
		$FLASH_CFG = $ARGV[0];
		(!-e $FLASH_CFG) && die "$FLASH_CFG does NOT EXIST!\n";
		$binary_path = $ARGV[1];
		$platform = $ARGV[2];
		last;
	}
	else {
		&Usage;
	}
}

print "Running tools\\CheckBinaryBlockUsage.pl ....\n";
if($platform eq 'MT6280') {
	$d = $bootloader_path;
	print "path: $d\n";
	if ($d =~ /\.(bin|txt)$/i ) {
		push(@binary, $d);
	}
	print "@binary\n";
}
else{

	# Get all cfg files in the target build path
	opendir (DIR, "$binary_path") or die "build folder doesn't exist: $binary_path\n";
	my @cfgfiles = grep {/.+\.cfg$/}  readdir DIR;
	close DIR;
	if (@cfgfiles == 1) {
		$cfg_file = pop @cfgfiles;
	}
	else {
	    die "There are more than one cfg files or no cfg files in $binary_path!\n";
	}
	$cfg_path = $binary_path . "/" . $cfg_file;
	print "CFG File: $cfg_path\n" if (0 != $DebugPrint);

	open(CFG_FILE_HANDLE, "$cfg_path") or die "Cannot open $cfg_path\n";

	while ($line = <CFG_FILE_HANDLE>) {
		if ($line =~ /\s*- file:/) {
			chomp($line);
			$line =~ s/\s*- file: //;
			$file = $binary_path . "/" . $line;
			push(@binary, $file);
		}
	}
	close(CFG_FILE_HANDLE);
}


#****************************************************************************
# parsing block size
# block size is got from flash_opt_gen.h
#****************************************************************************
my $bin_path = $ARGV[3];
my $FLASH_OPT_GEN_H = $bin_path."/flash_opt_gen.h";
print "$bin_path..\n $FLASH_OPT_GEN_H\n"if $DebugPrint == 1;
open (FLASH_OPT_GEN_H, "<$FLASH_OPT_GEN_H") or die "Cannot open $FLASH_OPT_GEN_H\n";

#$blk_size = 128 * 1024; # Assume 128KB per block
while (<FLASH_OPT_GEN_H>)
{
    if (/^#define\s+(\w+)\s+\(([\w|\-]*)\)/ || /^#define\s+(\w+)\s+([\w|\-]*)/)
    {
        if($1 eq 'NAND_BLOCK_SIZE')
        {
            $blk_size = $2*1024;#NAND_BLOCK_SIZE is KB
        }
    }
}
close FLASH_OPT_GEN_H;

print "blk_size is $blk_size\n";


# Get code rom size from ~flash_cfg_tmp.c
open (FLASH_CFG, "<$FLASH_CFG") or die "Cannot open $FLASH_CFG\n";
    
while ($line = <FLASH_CFG>)
{
    $backup = $/; undef $/;
    $reading = <FLASH_CFG>;
    $/ = $backup;
}
close FLASH_CFG;  #End of open (FLASH_CFG, "<$FLASH_CFG")

my ($addr, $len, $total_block, $bad_block);
if ($reading =~ /int\s+flash_base_address\s*=\s*(.*);/)
{
    $addr = `perl -e "print ($1)" 2>&1`;
    $base_block = $addr / ($blk_size);
}
if ($reading =~ /int\s+allocated_fat_space\s*=\s*(.*);/)
{
    $len = `perl -e "print ($1)" 2>&1`;
}

$total_block = 0;
$idx = 0;
my $ImageSize = 0;
foreach $file (@binary) {
	if(&CheckGFHMaxSize($file))
	{
	    if($ImageSize == 0xFFFFFFFF)
	    {
   	        $block = ceil(&get_size($file)/($blk_size));#Max Size is 0xffffffff
   	        print "[1-1]GFH info, image size is $block\n";
	    }
	    else
	    {
	        $block = $ImageSize/$blk_size;#Max Size is not 0xffffffff
   	        print "[1-2]GFH info, image size is $block\n";
	    }
	}
	else
	{
	    $block = ceil(&get_size($file)/($blk_size));#image do not have GFH info
	}
	$total_block+=$block;
	printf("\t[%d]$file size = %dKB, block # = %d\n", $idx, &get_size($file)/1024, $block) if $DebugPrint == 1;
	$idx = $idx + 1;
}

$bad_block = ceil($total_block * (0.02));
printf("\t[%d]Estimated Bad Block # = %d\n", $idx, $bad_block) if $DebugPrint == 1;
$idx = $idx + 1;


# Add 7 blocks for image list
$img_list_blk = 7;
$total_block = $total_block + $img_list_blk;
printf("\t[%d]Image List Block # = %d\n", $idx, $img_list_blk) if $DebugPrint == 1;

$total_block = $total_block + $bad_block;

if ($total_block > $base_block) {
	print "Error: BIN ($total_block blocks) and FAT ($base_block blocks) on NAND Flash overlap risk were detected.\n";
	print "Please decrease ROM sizes by reducing features or adjust custom_MemoryDevice.h configuration.\n";
	exit(1);
}
else {
	print "BIN size = $total_block blocks on NAND Flash\n";
	print "FAT start at $base_block block.\n";
}    
exit;  

#if ($query_mode == 0) {
  open (FILE_HANDLE, "<$themf") or die "cannot open $themf\n";
  while (<FILE_HANDLE>) {
    if (/^(\S+)\s*=\s*(\S+)/) {
      $keyname = lc($1);
      defined($${keyname}) && warn "$1 redefined in $themf!\n";
      $${keyname} = uc($2);
    }
  }

  if ($secure_support eq "TRUE") {
    $sec_support = 1;
    ($secure_version !~ /\d{1,4}/) && die "SECURE_VERSION: $secure_version should be a integer no longer than 4 digits!\n";
    ($secure_jtag_enable !~ /(TRUE|FALSE)/) && die "SECURE_JTAG_ENABLE: $secure_jtag_enable should be TRUE or FALSE!\n";
    $secure_jtag_enable = ($secure_jtag_enable =~ /TRUE/)? 1 : 0;
    (length($secure_custom_name) > 31) && die "SECURE_CUSTOM_NAME: $secure_custom_name should NOT exceed 31 bytes!\n";
  }
    
my %BBtbl_EMI = 
   (
      'MT6225'       => 1,
      'MT6228'       => 1,
      'MT6229'       => 2,
      'MT6230'       => 2,
      'MT6235'       => 3,
      'MT6235B'      => 3,
      'MT6238'       => 3,
      'MT6239'       => 3,
      'MT6268A'      => 3,
   );
  if (($nand_flash_booting ne "NONE") || (exists $BBtbl_EMI{$platform}))
  {
      open (CUSTOM_EMI_H, "<$memory_cfg") or die "cannot open $memory_cfg\n";
      $backup = $/; undef $/;
      $reading = <CUSTOM_EMI_H>;
      $/ = $backup;
      close CUSTOM_EMI_H;  #End of open (FLASH_CFG, "<$FLASH_CFG")
       
      if  ($reading =~ /\n\s*#define\s+DRAM_CS\s+/gs
       and $reading =~ /\n\s*#define\s+DRAM_SIZE\s+/gs)
      {
         $needEMIInfo = 1;
      }
  }
#}
#****************************************************************************
# parsing flash configuration from a file or a string
#****************************************************************************
my $full_hex_str = '';
my $full_emi_str; 

if ($FLASH_CFG =~ /custom_MemoryDevice\.h/i)
{
# parsing flash configuration from custom_MemoryDevice.h (NAND_FLASH_BOOTING)

  open (FLASH_CFG, "<$FLASH_CFG") or die "cannot open $FLASH_CFG\n";
    
  while ($line = <FLASH_CFG>)
  {
      if ($line =~ /^\s*#define\s+NAND_BOOTING_FLASH_BASE_ADDRESS\s+(0x[0-9A-Fa-f]+)/)
      {
         $addr = hex $1;
      }
      if ($line =~ /^\s*#define\s+NAND_BOOTING_ALLOCATED_FAT_SPACE\s+(0x[0-9A-Fa-f]+)/)
      {
         $len = hex $1;
      }
  }
  close FLASH_CFG;  #End of open (FLASH_CFG, "<$FLASH_CFG")
    
  $hex_str = sprintf("%02X%04X%04X%04X%04X%08X%08X", 1 , 0, 0, 0, 0, $addr, $len);
  $full_hex_str .= $hex_str;

  print "[Flash Cfg 0] $hex_str\n" if $DebugPrint == 1;

} 
elsif ($FLASH_CFG =~ /flash_opt\.h/i)
{
# parsing flash configuration from flash_opt.h (NOR-XIP)

  open (FLASH_CFG, "<$FLASH_CFG") or die "cannot open $FLASH_CFG\n";

  $backup = $/; undef $/;
  $reading = <FLASH_CFG>;
  $/ = $backup;

  close FLASH_CFG;  #End of open (FLASH_CFG, "<$FLASH_CFG")

  #// FLASH_BASE_ADDRESS_FOR_SCATTER 0x01C00000
  #// ALLOCATED_FAT_SPACE_FOR_SCATTER 0x00400000
  if ($reading =~ /\/\/\s+FLASH_BASE_ADDRESS_FOR_SCATTER\s+(0x[0-9A-Fa-f]+)/gs)
  {
      $addr = hex $1;
  }
  if ($reading =~ /\/\/\s+ALLOCATED_FAT_SPACE_FOR_SCATTER\s+(0x[0-9A-Fa-f]+)/gs)
  {
      $len = hex $1;
  }

  if (($system_drive_on_nand eq "TRUE") && ($nand_flash_booting eq "NONE"))
  {
      $addr = 0x0;
      $len = 0x0;
  }

  $hex_str = sprintf("%02X%04X%04X%04X%04X%08X%08X", 1, 0, 0, 0, 0, $addr, $len);
  $full_hex_str .= $hex_str;
}
elsif ($FLASH_CFG =~ /flash_cfg_tmp\.c/i)
{
  open (FLASH_CFG, "<$FLASH_CFG") or die "cannot open $FLASH_CFG\n";

  $backup = $/; undef $/;
  $reading = <FLASH_CFG>;
  $/ = $backup;

  close FLASH_CFG;  #End of open (FLASH_CFG, "<$FLASH_CFG")
  
  #int flash_base_address =  0x00E00000 ;
  #int flash_base_address =  ( (0xD00000)  + 0x00100000) ;
  #int allocated_fat_space =  0x00200000 ;
  #int allocated_fat_space =  ( (0x300000)  - 0x00100000) ;
  if ($reading =~ /int\s+flash_base_address\s*=\s*(.*);/)
  {
  	$addr = `perl -e "print ($1)" 2>&1`;
  }
  if ($reading =~ /int\s+allocated_fat_space\s*=\s*(.*);/)
  {
  	$len = `perl -e "print ($1)" 2>&1`;
  }
  $hex_str = sprintf("%02X%04X%04X%04X%04X%08X%08X", 1, 0, 0, 0, 0, $addr, $len);
  $full_hex_str .= $hex_str;
}
elsif ($FLASH_CFG =~ /\.[ch]/i)
{
    die "Not Support $FLASH_CFG parsing Yet";
}
else
{
# parsing flash configuration from a string
    $full_hex_str = $FLASH_CFG;
    $full_emi_str = $EMI_INFO;
    if ((length($full_emi_str) == 0)
     && (($platform eq "MT6228") || ($platform eq "MT6229") || ($platform eq "MT6225") || ($platform eq "MT6230"))
    ) {
        die "Cannot get EMI_INFO.";
    }
    print "full_hex_str=$full_hex_str\n" if $DebugPrint == 1;
    
    print "[Flash Cfg 0] $FLASH_CFG\n" if $DebugPrint == 1;
}

######################################
#Get register values from custom_MEI.h
######################################
## Check DRAM setting in custom_EMI.h 

#if ($needEMIInfo == 1 and not defined $full_emi_str)
#{
#     $full_emi_str = getRegisterAddress($platform, $memory_cfg);
#}
#elsif (not defined $full_emi_str)
#{
#     $full_emi_str = '';
#}

##################################################################################################################
    
######################################
# Binary String 
######################################
$flash_len = length($full_hex_str);
if ( ($flash_len == 2)
  || ((($flash_len-34)%32) !=0)
  || ($flash_len > 34+5*32) )
{
    die "The length of $full_hex_str ($flash_len) should be 34+32n. (5>=n>=0)\n";
}
$flash_device_count = hex(substr($full_hex_str, 0, 2));

if ((($flash_len-2)/32) != $flash_device_count)
{
    die "($flash_len-2)/32 should be $flash_device_count\n";
}


#****************************************************************************
# in query, output @cfg_list with hex string
#****************************************************************************
if ($query_mode == 1) {
  print "FLASH_CFG = $full_hex_str\n";
  print "EMI_INFO = $full_emi_str\n";
  exit(0);
}

#****************************************************************************
# Parse symbol file
#****************************************************************************
(open(LOGF, "<$symFile")) || die "$symFile can NOT been opened\n";
my %SYM_TBL = 
   (
      'INT_Vectors'      => undef,
      'IMG_INFO'         => undef,
      'EMI_INFO'         => undef,
      'g_CustParaCfg'    => undef,
      'g_secinfo'        => undef,
      'g_secinfo_tail'   => undef,
   );

my %SYM_LEN = 
   (
      'g_CustParaCfg'    => undef,
   );

my $prev_symbol;
while(<LOGF>)
{
   # 0x00000000 A INT_Vectors
   if (/^0x(\S+)\s+\w\s+(\S+)$/)
   {
      if (exists $SYM_TBL{$2})
      {
         $SYM_TBL{$2} = hex($1);
      }
      

      if (exists $SYM_LEN{$prev_symbol})
      {
         $SYM_LEN{$prev_symbol} = hex($1) - $SYM_TBL{$prev_symbol};
      }
      $prev_symbol = $2;
   }
}
close(LOGF);

#****************************************************************************
# Validation symbol and feature combination
#****************************************************************************
die "Could not find IMG_INFO in $symFile\n" unless defined $SYM_TBL{'IMG_INFO'};
if ($sec_support)
{
   die "Could not find g_secinfo in $symFile\n" unless defined $SYM_TBL{'g_secinfo'};
}

#****************************************************************************
# Setup BINARY File Offset
#****************************************************************************
my %ROM_POS = 
   (
      'IMG_INFO'         => undef,
      'EMI_INFO'         => undef,
      'g_CustParaCfg'    => undef,
      'g_secinfo'        => undef,
      'g_secinfo_tail'   => undef,
   );
map { $ROM_POS{$_} = $SYM_TBL{$_} - $SYM_TBL{'INT_Vectors'}; } keys %ROM_POS;


#****************************************************************************
# set ROMINFO version
#****************************************************************************
if ((($system_drive_on_nand eq "TRUE") && ($nand_flash_booting eq "NONE")))
{
        $rom_info_ver = "MTK_ROMINFO_v05";
}

#****************************************************************************
# append information to the file
#****************************************************************************
open (FILE, "+<$file") or die "cannot open $file\n";
binmode(FILE);

seek(FILE, $ROM_POS{'IMG_INFO'}, 0);

    seek(FILE, 16, 1);


    print FILE "$bin_name";
    print FILE "\0" x (128 -length($bin_name));
    print FILE "$verno";
    print FILE "\0" x (64 -length($verno));

if ($FLASH_CFG =~ /custom_MemoryDevice\.h/i)
{
    print FILE pack("H4", "ffff");
} else {
    print FILE pack("H4", "0000");
}

    $flash_len = length($full_hex_str);
    print FILE pack("v1", $flash_device_count);

for ($i=0; $i<$flash_device_count; $i++)
{
    $menuID = hex(substr($full_hex_str, 2+32*$i, 4));
    $devID = hex(substr($full_hex_str, 6+32*$i, 4));
    $extID1 = hex(substr($full_hex_str, 10+32*$i, 4));
    $extID2 = hex(substr($full_hex_str, 14+32*$i, 4));
    $fatAddr = hex(substr($full_hex_str, 18+32*$i, 8));
    $fatLen = hex(substr($full_hex_str, 26+32*$i, 8));
    print FILE pack("v1", $menuID);
    print FILE pack("v1", $devID);
    print FILE pack("v1", $extID1);
    print FILE pack("v1", $extID2);
    print FILE pack("V1", $fatAddr);
    print FILE pack("V1", $fatLen);
}

if ($cust_para_support eq "TRUE")
{
    seek(FILE, 12+(6-$flash_device_count)*16, 1);
    print FILE pack("V1", $SYM_TBL{'g_CustParaCfg'});
    print FILE pack("V1", $SYM_LEN{'g_CustParaCfg'});
}

if ($sec_support == 1)
{
  #Parse scatter file to get SECINFO_TAIL address.
  open(scat,"$scat") || die "Cannot open $sact. Error:$!\n";
  my $line = 0;
  my $rom_base = "";
  my $rom_line = 0;
  my $secondary_rom_base = "0";
  my $secondary_rom_line = 0;
  my $third_rom_base = "0";
  my $third_rom_line = 0;
  my $secinfo_tail_line = 0;
  my $secinfo_tail_base = "0";
  my $multiROM = "";
  while(<scat>){
    $line++;

    if(index($_,"ROM") == 0){
      $rom_line = $line;
      if($_ =~ /[\w]+[\s](.+?)[\s]/ && $1 ne "+0x0"){
        $rom_base = $1;
        # Get ROM binary length.
        if ($file =~ /(.+)\\ROM/) {
          $bin_path = $1;
          $rom_length = get_length($file);
        }
      }
    } elsif(index($_,"SECONDARY_ROM") == 0){
      $secondary_rom_line = $line;
      if($_ =~ /[\w]+[\s](.+?)[\s]/){
        $secondary_rom_base = $1;
        if ($secondary_rom_base =~ /\+(.+)/) {
          $secondary_rom_offset = hex $1;
          $secondary_rom_base = $rom_length + $secondary_rom_offset;
          $secondary_rom_length = get_length("$bin_path\\SECONDARY_ROM");
        }
      }
    } elsif(index($_,"THIRD_ROM") == 0){
      $third_rom_line = $line;
      if($_ =~ /[\w]+[\s](.+?)[\s]/){
        $third_rom_base = $1;
        if ($third_rom_base =~ /\+(.+)/) {
          $third_rom_offset = $1;
          $third_rom_base = $secondary_rom_length + $third_rom_offset;
        }
      }
    } elsif ($_ =~ /^[a-zA-Z].+/) {
      $third_rom_line = $line;
      if($_ =~ /[\w]+[\s](.+?)[\s]/){
        $third_rom_base = $1;
        if ($third_rom_base =~ /\+(.+)/) {
          $third_rom_offset = $1;
          $third_rom_base = $secondary_rom_length + $third_rom_offset;
        }
      }
    } elsif(index($_,"SECINFO_TAIL") >= 0){
      $secinfo_tail_line = $line;
    }
  }
  close(scat);
 
  if($secondary_rom_line == 0) {
    $secinfo_tail_base = $rom_base;
  } elsif($secondary_rom_line > $secinfo_tail_line){ #SECINFO_TAIL locates at ROM
    $secinfo_tail_base = $rom_base;
  } elsif(($secinfo_tail_line > $secondary_rom_line) && ($third_rom_line > $secinfo_tail_line)){#SECINFO_TAIL locates at SECONDARY_ROM
    $secinfo_tail_base = $secondary_rom_base;
    $multiROM = "SECONDARY";
  } elsif(($secinfo_tail_line > $third_rom_line) && (third_rom_line != "0")) {#SECINFO_TAIL locates at THIRD_ROM
    $secinfo_tail_base = $third_rom_base;
    $multiROM = "THIRD";
  }

#************************************************************
#Start to write secinfo to ROM
#************************************************************	
    seek(FILE, $ROM_POS{'g_secinfo'} + 20, 0);
    print FILE pack("V1", $secure_jtag_enable);
    print FILE "$secure_custom_name";
    print FILE "\0" x (32 -length($secure_custom_name));
    seek(FILE, $ROM_POS{'g_secinfo'} + 60, 0);
    print FILE pack("V1", $secure_version);
    
    if ($secinfo_tail_base =~ /0x/i) {
      $secinfo_tail_base = hex($secinfo_tail_base);
    }

    # Verify the address of g_secinfo_tail
    seek(FILE, $ROM_POS{'g_secinfo'} + 80, 0);
    my $addr_secinfo_tail;
    die "cannot read $file\n" unless (my $chnum = (read FILE, $addr_secinfo_tail, 4));
    $addr_secinfo_tail = unpack ("V1",$addr_secinfo_tail);
    die "secinfo tail don't match\n" if ($SYM_TBL{'g_secinfo_tail'} != $addr_secinfo_tail);
        
    if(length($multiROM) > 0){
      if($multiROM eq "SECONDARY"){
        $file =~ s/ROM/SECONDARY_ROM/;
        open(multiFILE,"+<$file") || die "Cannot open $file. Error:$!\b";
      } elsif($multiROM eq "THIRD"){
        $file =~ s/ROM/THIRD_ROM/;
        open(multiFILE,"$file") || die "Cannot open $file. Error:$!\b";
      }
#      $addr_secinfo_tail = $ROM_POS{'g_secinfo_tail'} % 0x08000000;
      $addr_secinfo_tail = $ROM_POS{'g_secinfo_tail'};
      $addr_secinfo_tail = $addr_secinfo_tail - $secinfo_tail_base;
      seek(multiFILE, $addr_secinfo_tail+20, 0);
      print multiFILE pack("V1", $secure_jtag_enable);
      print multiFILE "$secure_custom_name";
      print multiFILE "\0" x (32 -length($secure_custom_name));
      seek(multiFILE, $addr_secinfo_tail+60, 0);
      print multiFILE pack("V1", $secure_version);
      close(multiFILE);
    } else {
      $addr_secinfo_tail = unpack ("V1",$addr_secinfo_tail) % 0x08000000;

      seek(FILE, $ROM_POS{'g_secinfo_tail'} + 20, 0);    
      print FILE pack("V1", $secure_jtag_enable);
      print FILE "$secure_custom_name";
      print FILE "\0" x (32 -length($secure_custom_name));
      seek(FILE, $ROM_POS{'g_secinfo_tail'} + 60, 0);
      print FILE pack("V1", $secure_version);
    }
}

if ($rom_info_ver eq "MTK_ROMINFO_v05")
{
    $cust_para_addr = hex(0);
    $cust_para_len = hex(0);
    $bit_ctrl = hex(0);

    #Read the bit_ctrl first then OR needed bit
    seek(FILE, $ROM_POS{'IMG_INFO'} + 328, 0);
    (read FILE, $bit_ctrl, 4);
    $bit_ctrl=unpack("V1",$bit_ctrl);
    
    if (($system_drive_on_nand eq "TRUE") && ($nand_flash_booting eq "NONE"))
    {
            $bit_ctrl = $bit_ctrl | 0x00000002;
    }
    

  
    seek(FILE, $ROM_POS{'IMG_INFO'} + 320, 0);
    print FILE pack("V1", $cust_para_addr);
      
    seek(FILE, $ROM_POS{'IMG_INFO'} + 324, 0);
    print FILE pack("V1", $cust_para_len);
  
    seek(FILE, $ROM_POS{'IMG_INFO'} + 328, 0);
    print FILE pack("V1", $bit_ctrl);
}

close FILE;

#************************************************************
#Start to write IMG_FOTA_INFO to BIN file for FOTA
#************************************************************


#*********************************************************************************
# Calculate checksum of IMG_FOTA_INFO string (Check sum of "MTK_FOTA_ROMINFO_V01")
#*********************************************************************************


#****************************************************************************
# Write Platform ID and Project ID
#****************************************************************************


#****************************************************************************
# Get array numbers
#****************************************************************************


#****************************************************************************
# Write file size of each ROM image
#****************************************************************************


#****************************************************************************
# Write XOR value of whole structure
# For image information: initial key is (0x86)
#****************************************************************************


exit 0;

#******************************************************************************
# FUNCTION
#  get_size
# DESCRIPTION
#  xxx
# PARAMETERS
#  binary path
# RETURNS
#  binary size
#******************************************************************************

sub get_size(){
  ($path) = @_;
  $rom_size = stat("$path")->size;
  return $rom_size;
}

#******************************************************************************
# FUNCTION
#  CheckGFHMaxSize
# DESCRIPTION
#  Check whether image has GFH head info 
# PARAMETERS
#  binary path
# RETURNS
#  Image has GFH head or not
#******************************************************************************
sub CheckGFHMaxSize
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
            last if($nIndex > 64);
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
        if($bIsGFH == 1)
        {
            # GFH_FILE_INFO_v1
            # [  3:  0] GFH_Header.m_magic_ver
            # [  5:  3] GFH_Header.m_size, = size of GFH_FILE_INFO_v1 structure
            # [  7:  6] GFH_Header.m_type, = GFH_FILE_INFO_v1
            # [ 19:  8] identifier, = GFH_FILE_INFO_ID = "FILE_INFO"
            # [ 23: 20] m_file_ver
            # [ 25: 24] m_file_type, = PRI_ROM, DSP_ROM, ...
            # [   : 26] m_flash_dev
            # [   : 27] m_sig_type
            # [ 31: 28] m_load_addr
            # [ 35: 32] m_file_len
            # [ 39: 36] m_max_size
            # [ 43: 40] m_content_offset
            # [ 47: 44] m_sig_len
            # [ 51: 48] m_jump_offset
            # [ 55: 52] m_attr
            $ImageSize = ord($Buffer[36]) + (ord($Buffer[37])<<8) + (ord($Buffer[38])<<16) + (ord($Buffer[39])<<24);
            print "ImageSize is $ImageSize\n";
        }
    }
    return $bIsGFH;
}
