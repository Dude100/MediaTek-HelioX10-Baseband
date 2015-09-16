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
#*
#* Filename:
#* ---------
#*   Append2.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This script can append some information to a file
#*   1. its file name
#*   2. input strings
#*   3. flash configuration information
#*   This script also can query flash configuration stored in FlashConf.c
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/
BEGIN { push @INC, './tools/MemoryUtility/' }  # add additional library path
BEGIN { push @INC, './tools/DSP/'  }

use File::stat;
use Math::BigInt;
use BasicMemInfoQuery;
use Parsing_DSP_array;

my ($FLASH_CFG,$file,$bin_name,$verno,$themf,$build_time_str,$tmpfolder,$scat,$sym_filename,$infomakeLog) = @ARGV;
print "All INPUT: @ARGV\n";
&error_handler("BIN_NAME: $bin_name should NOT exceed 127 bytes", __FILE__, __LINE__) if(length($bin_name) > 127);
&error_handler("VERNO: $verno should NOT exceed 63 bytes", __FILE__, __LINE__) if(length($verno) > 63);

$targetDir = $file;

if($file =~ /\.bin$/ && -d "$file")
{
 $file = $file."/ROM";
}
&error_handler("$file does not exist!", __FILE__, __LINE__) if(!-e "$file");


$targetDir =~ s/\\/\//g;
if($targetDir =~ /(.+)\/(.+)/)
{
  $targetDir = $1;
}

$sym_file = $targetDir."/".$sym_filename;
$map_file = $sym_file;

#****************************************************************************
# parsing makefile
#****************************************************************************
open (FILE_HANDLE, "<$themf") or &error_handler("cannot open $themf!", __FILE__, __LINE__);
while (<FILE_HANDLE>)
{
	if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/))
	{
    $keyname = lc($1);
    $${keyname} = uc($2);
  }
}

if ($compiler eq "RVCT")
{
  $map_file =~ s/\.sym/\.lis/;
}
else
{
  $map_file =~ s/\.sym/\.map/;
}

&error_handler("$map_file does not exist!", __FILE__, __LINE__) if(!-e "$map_file");
&error_handler("$sym_file does not exist!", __FILE__, __LINE__) if(!-e "$sym_file");
#****************************************************************************
# parsing infomake.log
#****************************************************************************
my %COMPOPTIONS=();
open (FILE_HANDLE, "<$infomakeLog") or &error_handler("cannot open $infomakeLog!", __FILE__, __LINE__);
while (<FILE_HANDLE>)
{
	if(/^(\S+)\s*\=\s*(.*)/)
  {
    my $key = $1;
    my $value = $2;
    if($key =~ /COM_DEFS/)
    {
      my @CompOptions = split(/\s/,$value);
      foreach my $CompOption(@CompOptions)
      {
        $CompOption =~ s/\s\n\r//;
        next if($CompOption eq "");
        my $strkey = $CompOption;
        my $strvalue = "";
        if($CompOption =~ /(.*)=(.*)/)
        {
            $strkey = $1;
            $strvalue = $2;
        }
        $COMPOPTIONS{"$strkey"} = $strvalue;
      }
    }
  }
}
close FILE_HANDLE;
#****************************************************************************
# parsing flash configuration from a file or a string
#****************************************************************************
my $full_hex_str = '';
my $full_emi_str;

open (FLASH_CFG, "<$FLASH_CFG") or &error_handler("cannot open $FLASH_CFG!", __FILE__, __LINE__);
$backup = $/;
undef $/;
$reading = <FLASH_CFG>;
$/ = $backup;
close FLASH_CFG;

my $flash_name  = '';              # part number
my @NORFlashID  = (0, 0, 0, 0);    # flash ID (manufacture ID, device ID, ext. device ID1, ext. device ID2)
my @NANDFlashID = (0, 0, 0, 0);    # flash ID (manufacture ID, device ID, ext. device ID1, ext. device ID2)
my @EMMCFlashID = (0, 0, 0, 0);    # flash ID (manufacture ID, device ID, ext. device ID1, ext. device ID2)

my $fs_nor_addr = 0;
my $fs_nor_len = 0;
my $fs_nand_addr = 0;
my $fs_nand_len = 0;
my $fs_emmc_addr = 0;
my $fs_emmc_len = 0;
my $hex_str = '';

# get flash name(part number)
if ($reading =~ /const\s+kal_char\s+PART_NUMBER\w+\[\d*\]\s*=\s*\"(.*)\"\s*;/)
{
	$flash_name = $1;
	if ($bin_name !~ /\_FLN/)
	{ # there will be one more part number(NOR Flash with two and NAND with ONLY one)
		# specified in custom memory device configuration file
		$bin_name .= "_FLN" . $flash_name;
		&error_handler("PLATFORM ID: \"$bin_name\" should NOT exceed 127 bytes!", __FILE__, __LINE__) if(length($bin_name) > 127);
	}
}

# get flash ID
my @flashID = (0, 0, 0, 0);
if ($reading =~ /const\s+kal_char\s+FLASH_ID\[\d*\]\s*=\s*\"\s*(?:\{\s*)?(\w+)\s*\,\s*(\w+)\s*(\,\s*(\w+))?\s*(\,\s*(\w+))?\s*(\,\s*(\w+))*\s*(?:\}\s*)?\"\s*;/)
{ # Flash ID has four fields, manufacture ID, device ID, ext. device ID1 & ext. device ID2
	$flashID[0] = `perl -e "print ($1)" 2>&1` if ($1 ne "");
	$flashID[1] = `perl -e "print ($2)" 2>&1` if ($2 ne "");
	$flashID[2] = `perl -e "print ($4)" 2>&1` if ($4 ne "");
	$flashID[3] = `perl -e "print ($6)" 2>&1` if ($6 ne "");
}

if ($nand_flash_booting !~ /^NONE|FALSE$/)
{
	@NANDFlashID = @flashID;
}
elsif ($emmc_booting !~ /^NONE|FALSE$/)
{
	@EMMCFlashID = @flashID;	
}
else 
{
	@NORFlashID = @flashID;
}

# get nor flash base address if device exists
if ($reading =~ /int\s+fs_nor_base_address\s*=\s*(.*);/)
{
	 $fs_nor_addr = `perl -e "print ($1)" 2>&1`;
}

# get nor flash FAT space if device exists
if ($reading =~ /int\s+fs_nor_length\s*=\s*(.*);/)
{
	 $fs_nor_len = `perl -e "print ($1)" 2>&1`;
}

# get nand flash base address if device exists
if ($reading =~ /int\s+fs_nand_base_address\s*=\s*(.*);/)
{
	 $fs_nand_addr = `perl -e "print ($1)" 2>&1`;
}

# get nand flash FAT space if device exists
if ($reading =~ /int\s+fs_nand_length\s*=\s*(.*);/)
{
	 $fs_nand_len = `perl -e "print ($1)" 2>&1`;
}

# get emmc flash base address if device exists
if ($reading =~ /int\s+fs_emmc_base_address\s*=\s*(.*);/)
{
	 $fs_emmc_addr = `perl -e "print ($1)" 2>&1`;
}

# get emmc flash FAT space if device exists
if ($reading =~ /int\s+fs_emmc_length\s*=\s*(.*);/)
{
	 $fs_emmc_len = `perl -e "print ($1)" 2>&1`;
}

$hex_str = sprintf("%02X", 3); # flash device num.
$full_hex_str .= $hex_str;

# 1st flash device info. --- NOR flash
$hex_str = sprintf("%04X%04X%04X%04X%08X%08X", $NORFlashID[0], $NORFlashID[1], $NORFlashID[2], $NORFlashID[3], $fs_nor_addr, $fs_nor_len);
$full_hex_str .= $hex_str;

# 2nd flash device info. --- NAND flash
$hex_str = sprintf("%04X%04X%04X%04X%08X%08X", $NANDFlashID[0], $NANDFlashID[1], $NANDFlashID[2], $NANDFlashID[3], $fs_nand_addr, $fs_nand_len);
$full_hex_str .= $hex_str;

# 3rd flash device info. --- eMMC flash
$hex_str = sprintf("%04X%04X%04X%04X%08X%08X", $EMMCFlashID[0], $EMMCFlashID[1], $EMMCFlashID[2], $EMMCFlashID[3], $fs_emmc_addr, $fs_emmc_len);			
$full_hex_str .= $hex_str;


$flash_len = length($full_hex_str);
if ( ($flash_len == 2) || ((($flash_len-34)%32) !=0) || ($flash_len > 34+5*32) )
{
  &error_handler("The length of $full_hex_str ($flash_len) should be 34+32n. (5>=n>=0)", __FILE__, __LINE__);
}
$flash_device_count = hex(substr($full_hex_str, 0, 2));

if ((($flash_len-2)/32) != $flash_device_count)
{
  &error_handler("$flash_len-2)/32 should be $flash_device_count", __FILE__, __LINE__);
}

open (CFG,">$tmpfolder/~gfh_cfg_flash.tmp") or &error_handler("cannot open $tmpfolder/~gfh_cfg_flash.tmp", __FILE__, __LINE__);
print CFG "FLASH_DEV_CNT=$flash_device_count\n";

for ($i=0; $i<$flash_device_count; $i++)
{
  $menuID = hex(substr($full_hex_str, 2+32*$i, 4));
  $devID = hex(substr($full_hex_str, 6+32*$i, 4));
  $extID1 = hex(substr($full_hex_str, 10+32*$i, 4));
  $extID2 = hex(substr($full_hex_str, 14+32*$i, 4));
  $fatAddr = hex(substr($full_hex_str, 18+32*$i, 8));
  $fatLen = hex(substr($full_hex_str, 26+32*$i, 8));
  
  $regbase2 .= sprintf("0x%04X", $devID);
  $regbase2 .= sprintf("%04X"  , $menuID).",";
  $regbase2 .= sprintf("0x%04X", $extID2);
  $regbase2 .= sprintf("%04X"  , $extID1).",";
  $regbase2 .= sprintf("0x%08X", $fatAddr).",";
  $regbase2 .= sprintf("0x%08X", $fatLen).",";   
}
print CFG "FLASH_CFG_STR =".$regbase2."\n";
close CFG;

#************************************************************
#Get original binary size(before appending info in tail)
#************************************************************
my $img_rom_size = stat("$file")->size;

#************************************************************
#Fill in PROJECT_NAME and PROJECT_FLAVOR to bin file
#************************************************************
open (FILE, "+<$file") or &error_handler("cannot open $file!", __FILE__, __LINE__);
binmode(FILE);
seek(FILE, 0, 2);

print FILE "$original_project_name";
print FILE "\0" x (128 -length($original_project_name));
print FILE "$original_flavor";
print FILE "\0" x (36 -length($original_flavor));

if(defined $original_verno)
{
  print "original_verno = $original_verno\n";
  print FILE "$original_verno";
  print FILE "\0" x (64 -length($original_verno));
}
else
{
  print "verno = $verno\n";
  print FILE "$verno";
  print FILE "\0" x (64 -length($verno));
}

close FILE;
#************************************************************
#Start to write infomation to BIN file for MODEM
#************************************************************
print "Input for GetTotalRAMUsageFromLDS: $themf $scat $map_file $sym_file\n";
my $nSize = BasicMemInfo::GetTotalRAMUsageFromLDS($themf, $scat, $map_file, $sym_file, undef);
print "Memory size = $nSize\n\n";

my $dspSymbol = "g_dsp_log_buff";
my $dspFlagSymbol = "g_dsp_img_on_emi";

print "Get DSP load address: $sym_file $dspFlagSymbol $dspSymbol\n";
my ($dspSymAddress, $dspSymSize) = Parsing_DSP_array::getDSPsymbol($sym_file,$dspFlagSymbol,$dspSymbol);
print "DSP Symbol address:$dspSymAddress\nDSP Symbol size:$dspSymSize\n\n";

#MODEM mechanism
my $check_header_str = "CHECK_HEADER";

my $structure_size;
my $header_version;

if($platform eq "MT6290" || $platform eq "MT6595")
{
	$structure_size = 188;
	$header_version = "02";
}
else
{
	$structure_size = 284;
	$header_version = "03";
}

open (FILE, "+<$file") or &error_handler("cannot open $file!", __FILE__, __LINE__);
binmode(FILE);
seek(FILE, 0, 2);
print FILE "$check_header_str";
print FILE "\0" x (12 -length($bin_name));

print FILE pack("V1",$header_version);

#Debug/Release mode check
#0x1: debug mode
#0x2: release mode
if($production_release eq "TRUE") {
	print FILE pack("V1",2);
} elsif($production_release eq "FALSE") {
	print FILE pack("V1",1);
} else {
	print FILE pack("V1",0);
}

#modem CHECK
#0x1: 2G
#0x2: 3G
#0x3: WG
#0x4: TG
#0x5: LWG
#0x6: LTG
#0x7: SGLTE
if(defined $sglte_support && $sglte_support ne "NONE") {
	$MODEM_SPEC = 7;
} elsif($eutran_mode_support eq "EUTRAN_MODE" && $utran_mode_support eq "UTRAN_TDD128_MODE" && $geran_mode_support eq "GERAN_EGPRS_MODE") {
	$MODEM_SPEC = 6;
} elsif($eutran_mode_support eq "EUTRAN_MODE" && $utran_mode_support eq "UTRAN_FDD_MODE" && $geran_mode_support eq "GERAN_EGPRS_MODE") {
	$MODEM_SPEC = 5;
} elsif($utran_mode_support eq "UTRAN_TDD128_MODE" && $eutran_mode_support eq "NONE") {
	$MODEM_SPEC = 4;
} elsif($utran_mode_support eq "UTRAN_FDD_MODE" && $eutran_mode_support eq "NONE") {
	$MODEM_SPEC = 3;
} elsif($geran_mode_support eq "GERAN_GSM_MODE" || ($geran_mode_support eq "GERAN_EGPRS_MODE" && $utran_mode_support eq "NONE")) {
	$MODEM_SPEC = 1;
} else {
	$MODEM_SPEC = 0;
}

#exception rule
if(defined $COMPOPTIONS{"__MM_DISABLE_L__"})
{ 
  if($MODEM_SPEC == 6)
  {
    $MODEM_SPEC = 4;
  }
  if($MODEM_SPEC == 5)
  {
    $MODEM_SPEC = 3;
  }
}


print "MODEM SPEC is $MODEM_SPEC\n";
print FILE pack("V1",$MODEM_SPEC);

my $plat_chip_info = $platform."_".$chip_ver;
print FILE "$plat_chip_info";
print FILE "\0" x (16 -length($plat_chip_info));
print FILE "$build_time_str";
print FILE "\0" x (64 -length($build_time_str));

if($verno =~ /(.+W\d\d\.\d\d).*/) {
	 $build_verno = $1;
}
print FILE "$build_verno";
print FILE "\0" x (64 -length($build_verno));


#MD1/MD2 check
#0x1: default value
#0x2: MD2
#0x3~0x4: reserved
#0x5: MD5
if(defined $mdsys && $mdsys eq "MD5") {
  print FILE pack("V1",5);
}elsif(defined $mdsys && $mdsys eq "MD2") {
  print FILE pack("V1",2);
}else {
  print FILE pack("V1",1);
}
print FILE pack("V1",$nSize);
print FILE pack("V1",$img_rom_size);
seek(FILE, 4, 1);

if($header_version eq "03")
{
	print FILE pack("V1",$dspSymAddress);
	print FILE pack("V1",$dspSymSize);
	seek(FILE, 88, 1);
}

print FILE pack("V1",$structure_size);
close (FILE);

print "Done\n";
exit 0;

#*************************************************************************************************
# Error Handling Message
#*************************************************************************************************
sub error_handler
{
	   my ($error_msg, $file, $line_no) = @_;
	   my $final_error_msg = "Error: $error_msg at $file line $line_no\n";
	   print "$final_error_msg";
	   die $final_error_msg;
}
