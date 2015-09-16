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
#*   gps_config2.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# parsing command arguments
#****************************************************************************

#$file2="custom\\drv\\misc_drv\\EVEN6228_DEMO_BB\\codegen\\gpio_var.c";	# Need Modify: Input from @ mcu\custom\drv\misc_drv\EVEN6228_DEMO_BB\codegen\gpio_var.c
#$gps_ini="build\\EVEN6228_DEMO\\EVEN6228_DEMO_PCB04_gprs_MT6228_S02.MAUI_W07_40.bin\\GPS\\gps.ini";		# Need Modify: Output to  @ mcu\build\$EVEN6228_DEMO_BB\$NFB\GPS\gps.ini

$file2=$ARGV[0];
$gps_ini=$ARGV[1];

@gps_gpio=("gpio_gps_power_pin",
					"gpio_gps_reset_pin",
					"gpio_gps_standby_pin",
					"gpio_gps_32k_pin");

open(GPS_CONFIG, $file2) or die "$file2 cannot be opened!\r\n";

print "Open $file2!\r\n\r\n";

sub GetDefineValue {
		my ($line) = $_[0];
		my ($pattern) = $_[1];
		my ($ret) = 0;
		my ($value) = 0;
		my (@result);
			
		if($line =~ /^*$pattern/i){
#			print $line;
#			print "~~~~~~~~~~~~~>\r\n";
			
			@tokens=split(/\s+/,$line);

			if($tokens[4] =~ /(GPIO|GPO)/){
					($token1,$token2)=split(/;/,$tokens[4]);			#	e.g, $tokens[4]	=GPIO_PORT_1;
					($gpio_type,$port,$pin)=split(/_/,$token1);		#	e.g, $token1		=GPIO_PORT_1
					
					if( $gpio_type =~ /GPIO/i ){
							$ret = 1;
							$value = $pin;
					}
					elsif( $gpio_type =~ /GPO/i ){
							$ret = 1;
							$value = $pin+100;
					}
					else {
						print "Unknow GPIO Type: $gps_type !\r\n";
					}
			}
			else{
				print "Cannot find $pattern !\r\n";
			}
		
#			print "<~~~~~~~~~~~~~\r\n";
		}

		@result = ($ret, $value);
		return @result;
				
}

open(GPS_INI, ">$gps_ini") or die "$gps_ini cannot be opened!";
print GPS_INI "[GPIO]\r\n";
close ($gps_ini);

while($line = <GPS_CONFIG>) {
	
		foreach $pattern (@gps_gpio){	
#				$pattern = $gps_power_pin;
				($g_ret, $g_value) = GetDefineValue($line, $pattern);
				if($g_ret){
						$output="$pattern=$g_value\r\n";
					
						open(GPS_INI, ">>$gps_ini") or die "$gps_ini cannot be opened!";
						print GPS_INI $output;
						close ($gps_ini);

						print $output;
						break;
				}
		}

}


close ($file2);
exit 0;

