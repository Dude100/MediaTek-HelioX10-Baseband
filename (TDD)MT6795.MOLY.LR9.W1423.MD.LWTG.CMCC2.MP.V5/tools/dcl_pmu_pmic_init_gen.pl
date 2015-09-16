my $PMU_INITSETTING_VERNO     = " V1.00";
$time =localtime(time);

my @desc_list = ("pmu_init.c", 
                       "This file provide for pmu initial setting",
                                 "Oscar Liu", $PMU_INITSETTING_VERNO, $time);
#information by pmu chip                                 
$pmu = 1;   # pmu = 0 if using PMIC                                 
$pmu_name;                                 

print "Input file :";
#my $data_file = <STDIN>;
chomp($data_file=<STDIN>);
#pmu initial parameter
@address;
@mask;
@value;

#pmic initial parameter
@APshift;
@APmask;
@APvalue;
@APbank;

#ECO Version
@ECO;	#c code string
@ECO_version;

$data_number = 0;	#number of initial data
$ECO_number = 0;
$latest_ECOversion = 0;
$parsing = 0;
$linenumber = 0;

open(IN_FILE_INDEX,$data_file) || die("Could not open file!");
@raw_data = <IN_FILE_INDEX>;	#put the input data to raw_data(array)

foreach $data_handle (@raw_data)	#parsing total ECO number;
{
	if($data_handle =~/^\/\// )	#check //開頭的string	
	{
	}
	else
	{
		$data_handle =~ s/\s+//g;	#remove all white space
	}	
		
		
	if($data_handle =~/^ECO_E(\d+)/)
	{
		$ECO_version[$1]=1;	#save the ECO_Ex to variable $1
		#print $maxECOnumber;
		$ECO_number ++;
		#print $ECO_number;
	}	
}

if($ECO_number != 1)		#only 1 ECO version, no need ECO version judgement
{
	$ECO_String = $ECO_String."\t"."ECO_VERSION ChipVersion = INT_ecoVersion();"."\n";
}

for($i=20;$i!=0;$i--)
{
		$parsing = 0;
		$linenumber = 0;
		if($ECO_version[$i] == 1)
		{
			
			if($latest_ECOversion == 0)
			{	
				if($ECO_number != 1)	#only 1 ECO version, no need ECO version judgement
				{
					$ECO[$i] = $ECO[$i]."\t"."if(ChipVersion >= ECO_E"."$i".")\n";	
				}	
				$ECO[$i] = $ECO[$i]."\t{\n";
				$latest_ECOversion = 1;		#set latest ECO version on the top of C code
			}
			else
			{
				$ECO[$i] = $ECO[$i]."\t"."else if(ChipVersion >= ECO_E"."$i".")\n";	
				$ECO[$i] = $ECO[$i]."\t{\n";
			}
				
			foreach $data_handle (@raw_data)
			{
				$error = 0;	#check input data error
				chomp($data_handle);	#remove CR/LF(換行)
				
								
				#$data_handle =~ s/\s+//g;	#remove all white space
				$linenumber++;
				
				if($data_handle =~/^PMIC/ )	#check 是否為ECO開頭, check ECO version
				{
					$pmu = 0;
					#print $pmu;	
				}
				
				if($data_handle =~/^pmu(\d+)/)
				{
					$pmu_name = "pmu"."$1";
					#print $pmu_name;
				}
				elsif($data_handle =~/^pmic(\d+)/ )
				{
					$pmu_name = "pmic"."$1";
					#print $pmu_name;
				}
								
				if($data_handle =~/^ECO_E(\d+)/ )	#check 是否為ECO開頭, check ECO version
				{
					if($1 == $i)
					{
						$parsing = 1;	
						#print "$i yes\n"
					}
					else
					{
						$parsing = 0;
						#print "$i no\n"	
					}
				}
				else
				{
					#print "$i $parsing\n"	
				}
				if($parsing == 1)
				{
							
					if($data_handle =~s/^$// )	#delete 空白行
					{
						
					}
					elsif($data_handle =~/^ECO_E/ )	#check 是否為ECO開頭, check ECO version	
					{
						
					}
					elsif($data_handle =~/^\/\// )	#check //開頭的string
					{
						$ECO[$i] = $ECO[$i]."\t".$data_handle."\n";	
						#print $data_handle."\n";	
					}
					elsif($data_handle =~/^\// )	#check /開頭的string
					{
						print "$data_handle"." is not acceptable, missing / ,line $linenumber \n";	
					}
					elsif($data_handle !~/\,\w+\,/ )	#check 是否不為,[a-zA-Z0-9],
					{
						print "$data_handle"." is not acceptable, line $linenumber  \n";	
					}
					else
					{
							
						($address[$data_number],$mask[$data_number],$value[$data_number], $APshift[$data_number], $APmask[$data_number], $APvalue[$data_number],$APbank[$data_number]) = split(/,/,$data_handle);	
						
						if($address[$data_number] =~/[g-wyzG-Z]/)	#check 是否為正確的16進位))	
						{
							print "$address[$data_number]"." is not acceptable, line $linenumber  \n";
							$error = 1;
						}
						if($mask[$data_number] =~/[g-wyzG-Z]/)	#check 是否為正確的16進位))	
						{
							print "$mask[$data_number]"." is not acceptable, line $linenumber  \n";
							$error = 1;
						}	
						if($value[$data_number] =~/[g-wyzG-Z]/)	#check 是否為正確的16進位))	
						{
							print "$value[$data_number]"." is not acceptable, line $linenumber  \n";
							$error = 1;
						}	
						if($APshift[$data_number] =~/[g-wyzG-Z]/)	#check 是否為正確的16進位))	
						{
							print "$APshift[$data_number]"." is not acceptable, line $linenumber  \n";
							$error = 1;
						}
						if($APmask[$data_number] =~/[g-wyzG-Z]/)	#check 是否為正確的16進位))	
						{
							print "$APmask[$data_number]"." is not acceptable, line $linenumber  \n";
							$error = 1;
						}	
						if($APvalue[$data_number] =~/[g-wyzG-Z]/)	#check 是否為正確的16進位))	
						{
							print "$APvalue[$data_number]"." is not acceptable, line $linenumber  \n";
							$error = 1;
						}	
						if($APbank[$data_number] =~/[g-wyzG-Z]/)	#check 是否為正確的16進位))	
						{
							print "$APbank[$data_number]"." is not acceptable, line $linenumber  \n";
							$error = 1;
						}	
						
						if($address[$data_number] !~/^0x/ )	#check 是否為0x開頭))	
						{
							print "$address[$data_number]"." is not acceptable, line $linenumber \n";
							$error = 1;
						}	
						if($mask[$data_number] !~/^0x/ )	#check 是否為0x開頭))	
						{
							print "$mask[$data_number]"." is not acceptable, line $linenumber \n";
							$error = 1;
						}
						if($value[$data_number] !~/^0x/ )	#check 是否為0x開頭))	
						{
							print "$value[$data_number]"." is not acceptable, line $linenumber \n";
							$error = 1;
						}
						
						if($APshift[$data_number] !~/^0x/ )	#check 是否為0x開頭))	
						{
							print "$APshift[$data_number]"." is not acceptable, line $linenumber \n";
							$error = 1;
						}	
						if($APmask[$data_number] !~/^0x/ )	#check 是否為0x開頭))	
						{
							print "$APmask[$data_number]"." is not acceptable, line $linenumber \n";
							$error = 1;
						}
						if($APvalue[$data_number] !~/^0x/ )	#check 是否為0x開頭))	
						{
							print "$APvalue[$data_number]"." is not acceptable, line $linenumber \n";
							$error = 1;
						}
						if($APbank[$data_number] !~/^0x/ )	#check 是否為0x開頭))	
						{
							print "$APbank[$data_number]"." is not acceptable, line $linenumber \n";
							$error = 1;
						}
								
						#print "PMU_DRV_SetData16(".$address[$data_number].",".$mask[$data_number].",".$startbit[$data_number].");\n";
						if($error == 0)
						{
							if($pmu ==1)
							{	
								$ECO[$i] = $ECO[$i]."\t"."\t"."PMU_DRV_SetData16(".$address[$data_number].",".$mask[$data_number].",".$value[$data_number].");\n";
							}
							else
							{
								$ECO[$i] = $ECO[$i]."\t"."\t"."PMIC_DRV_SetData(".$address[$data_number].",".$mask[$data_number].",".$value[$data_number].",".$APbank[$data_number].");\n";	
							}	
						}	
					}
					
					
					#print "$address[$data_number] $mask[$data_number] $startbit[$data_number] $value[$data_number] $data_number";
					
					$data_number++;
					
				}
				
			}
			
			$ECO[$i] = $ECO[$i]."\t}\n";
			$ECO_String = $ECO_String.$ECO[$i];
		}
	
}
close(IN_FILE_INDEX);

if($error == 0)
{
	print "code generation OK"; 	
}
# //translate the number to string
#$address_string = join ',' , @address;
#$mask_string = join ',' , @mask;
#$startbit_string = join ',' , @startbit;
#$value_string = join ',' , @value;
#print "$address_string $mask_string $startbit_string $value_string";
	
	
if($pmu ==1)
{
	$file_body_func_name = "config_PMUc_file_body";
}
else
{
	$file_body_func_name = "config_PMICc_file_body";
}	

$output_file = "..\\hal\\peripheral\\src\\dcl_"."$pmu_name"."_init.c";
$pmu_fuunction_name = "dcl_"."$pmu_name"."_internal_init"; 
open(OUT_FILE_INDEX,">$output_file") || die("Cannot Open File"); 
print OUT_FILE_INDEX &copyright_file_header();
print OUT_FILE_INDEX &description_file_header(@desc_list);
print OUT_FILE_INDEX &{$file_body_func_name}($pmu_fuunction_name,$ECO_String);
close(OUT_FILE_INDEX);
	

#****************************************************************************
# subroutine:  generate pmu_init.c content body
# return:      the body strings
#****************************************************************************
sub config_PMUc_file_body
{
	my($pmu_fuunction_name,$ECO_String) = @_;
	my $template = <<"__TEMPLATE";
#include "drv_comm.h"
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"

//$data_file	
void $pmu_fuunction_name(void)
{
$ECO_String}
	
__TEMPLATE

   return $template;
}


#****************************************************************************
# subroutine:  generate pmu_init.c content body
# return:      the body strings
#****************************************************************************
sub config_PMICc_file_body
{
	my($pmu_fuunction_name,$ECO_String) = @_;
	my $template = <<"__TEMPLATE";
#include "init.h"
#include "dcl.h"

extern DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr);
extern void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value);

void PMIC_DRV_SetData(DCL_UINT32 addr, DCL_UINT32 bitmask, DCL_UINT16 value, DCL_UINT32 bank)
{
   DCL_UINT32 temp;
   addr |= (bank << 31);
   temp = (~(bitmask)) & DRV_Read_PMIC_Data(addr);
   temp |= ((value) & (bitmask));
   DRV_Write_PMIC_Data(addr,temp);
}

//$data_file
void $pmu_fuunction_name(void)
{
$ECO_String}
	
__TEMPLATE

   return $template;
}
#****************************************************************************
# subroutine:  copyright_file_header
# return:      file header -- copyright
#****************************************************************************
sub copyright_file_header
{
    my $template = <<"__TEMPLATE";
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

__TEMPLATE

   return $template;
}


#****************************************************************************
# subroutine:  description_file_header
# return:      file header -- description 
# input:       $filename:     filename
# input:       $description:  one line description
# input:       $author:       optional
#****************************************************************************
sub description_file_header
{
    my ($filename, $description, $author, $PMU_INITSETTING_VERNO, $time) = @_;
    my $template = <<"__TEMPLATE";
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   $filename
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   $description
 *
 * Author:
 * -------
 *   $author
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * \$Revision\$   $PMU_INITSETTING_VERNO
 * \$Modtime\$     $time 
 * \$Log\$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
__TEMPLATE

   return $template;
}