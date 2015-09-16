#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
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
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   ckFlashInfo.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script will
#*       1. parse PartNumber_cfg.ini to obtain a series of part numbers
#*       2. read MDL to get flash ID of these part numbers
#*       3. compare these flash ID and report error if there are duplicated ones
#*
#* Author:
#* -------
#*   Claudia Lo    (mtk01876)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
use Win32::OLE qw(in with);
use Win32::OLE::Const 'Microsoft Excel';
$Win32::OLE::Warn = 3;                                # die on errors...

#****************************************************************************
# Constants
#****************************************************************************
my $CKFLASHINFO_VERNO  = " v0.00";
                         # v0.00 , by Claudia at 2009/12/11 , initial version
                         #

my $DebugPrint    = 1; # 1 for debug; 0 for non-debug

my $PARTNUMBER_CFG_INI       = $ARGV[0];
my $MEMORY_DEVICE_LIST_XLS   = Win32::GetCwd()."\\".$ARGV[1];
my $MEMORY_DEVICE_LIST_XLS_E = $ARGV[1];
my $CUSTOM_MEMORY_DEVICE_HDR = $ARGV[2];

# to align error message file name format
$MEMORY_DEVICE_LIST_XLS_E =~ s/^.\\|^\\//;

#****************************************************************************
# parse custom_MemoryDevice.h to extract MEMORY_DEVICE_TYPE & PART_NUMBER
#****************************************************************************
open CUSTOM_MEMORY_DEVICE_HDR, "<$CUSTOM_MEMORY_DEVICE_HDR" or &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: file error!", __FILE__, __LINE__);
my $MEMORY_DEVICE_TYPE;
while (<CUSTOM_MEMORY_DEVICE_HDR>)
{
    if (/^#define\s+MEMORY_DEVICE_TYPE\s+(\w*)/)
    {
        $MEMORY_DEVICE_TYPE = $1;
    }
}
close CUSTOM_MEMORY_DEVICE_HDR;

&error_handler("$CUSTOM_MEMORY_DEVICE_HDR: MEMORY_DEVICE_TYPE undefined!", __FILE__, __LINE__) if (!defined $MEMORY_DEVICE_TYPE);

if ($DebugPrint == 1)
{
    print "MEMORY_DEVICE_TYPE: $MEMORY_DEVICE_TYPE\n";
}

#****************************************************************************
# parse EMI database to get flash IDs
#****************************************************************************
my %PN_FlashID;
if ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP')
{
    &fs_parse_mdl_key_content($MEMORY_DEVICE_LIST_XLS, 'NOR_RAM_MCP', 'Part Number', 'Flash ID', \%PN_FlashID);
} # if ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP')
elsif ($MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP')
{
    &fs_parse_mdl_key_content($MEMORY_DEVICE_LIST_XLS, 'NOR_RAM_MCP', 'Part Number', 'Flash ID', \%PN_FlashID);
}# elsif ($MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP')
elsif ($MEMORY_DEVICE_TYPE eq 'LPSDRAM')
{
    &fs_parse_mdl_key_content($MEMORY_DEVICE_LIST_XLS, 'LPSDRAM', 'Part Number', 'Flash ID', \%PN_FlashID);
}# elsif ($MEMORY_DEVICE_TYPE eq 'LPSDRAM')
else
{
    &error_handler("$CUSTOM_MEMORY_DEVICE_HDR: invalid MEMORY_DEVICE_TYPE!", __FILE__, __LINE__);
}

#****************************************************************************
# parse PartNumber_cfg.ini to obtain a series of part numbers,
# retrieve their flash IDs, and check whether the flash IDs are duplicated
#****************************************************************************
open PARTNUMBER_CFG_INI_HANDLE, "<$PARTNUMBER_CFG_INI";
my %PN_FlashID_cfg;
while (<PARTNUMBER_CFG_INI_HANDLE>)
{
    if (/([\w|\-]+)\n*/)
    {
    	   my $part_number = $1;
    	   if ($DebugPrint == 1)
    	   {
    	   	   print "Part Number: $1, flash ID: $PN_FlashID{$part_number}\n";
    	   }
    	   
    	   &error_handler("$PARTNUMBER_CFG_INI: Invalid part number $part_number! Please assign valid part numbers!\n", __FILE__, __LINE__) if (!defined $PN_FlashID{$part_number});
    	   if ((defined $PN_FlashID{$part_number}) and ($PN_FlashID{$part_number} =~ /\s*0x[A-Fa-f0-9]{4}\s*,*/))
    	   {
    	   	   my @id_list = split /\,/, $PN_FlashID{$part_number};
    	   	   foreach (@id_list)
    	   	   {
    	   	   	   if (/\s*0x[A-Fa-f0-9]{4}\s*/)
    	   	   	   {
    	   	   	   }
    	   	   	   else
    	   	   	   {
    	   	   	   	   &error_handler("$PARTNUMBER_CFG_INI: Invalid Flash ID of part number $part_number! Please choose another part number with valid flash ID!\n", __FILE__, __LINE__);
    	   	   	   }
    	   	   }
        	   foreach (keys %PN_FlashID_cfg)
        	   {
    	       	   &error_handler("$PARTNUMBER_CFG_INI: Duplicated Flash ID of part number $_ and $part_number! Please assign part numbers with different flash IDs, otherwise the flash tool cannot determine which load to download!\n", __FILE__, __LINE__) if (uc($PN_FlashID{$part_number}) eq uc($PN_FlashID_cfg{$_}));
        	   }
    	   }
    	   else
    	   {
    	   	   &error_handler("$PARTNUMBER_CFG_INI: Invalid Flash ID of part number $part_number! Please choose another part number with valid flash ID!\n", __FILE__, __LINE__);
    	   }
    	   $PN_FlashID_cfg{$part_number} = $PN_FlashID{$part_number};
    }
}

close PARTNUMBER_CFG_INI_HANDLE;

if ($DebugPrint == 1)
{
    my $idx = 1;
    foreach (keys %PN_FlashID_cfg)
    {
        print "Part Number $idx: $_, flash ID $PN_FlashID_cfg{$_}\n";
        $idx++;
    }
}


exit;


#****************************************************************************
# subroutine:  xls_cell_value
# return:      excel cell value no matter it's in merge area or not
# input:       $sheet:  specified Excel Sheet
#              $row:    specified row number
#              $col:    specified column number
#****************************************************************************
sub xls_cell_value
{
    my ($sheet, $row, $col) = @_;

    if ($sheet->Cells($row, $col)->{'MergeCells'})
    {
        my $ma = $sheet->Cells($row, $col)->{'MergeArea'};
        return ($ma->Cells(1, 1)->{'Value'});
    }
    else
    {
        return ($sheet->Cells($row, $col)->{'Value'})
    }    
}

#****************************************************************************
# subroutine:  fs_parse_mdl_key_content
# return:      hash of matching rows and indexing rows
# input:       $file:        excel file to be read
#              $sheet:       sheet to open
#              $key:         the column in the file to be keys
#              $content:     the column in the file to be contents
#              $target_href: the output hash of all key-content mappings in the file
#****************************************************************************
sub fs_parse_mdl_key_content
{
    my ($file, $sheet, $key, $content, $target_href) = @_;

    ### get already active Excel application or open new
    my $Excel = Win32::OLE->GetActiveObject('Excel.Application') || Win32::OLE->new('Excel.Application', 'Quit');

    ### copy the Excel file to a temp file and open it;
    ### this will prevent error due to simultaneous Excel access
    my $Book = $Excel->Workbooks->Open($file);
    
    ### 
    my $WorkSheet = $Book->Worksheets($sheet);

    ### find the key and content columns
    my ($key_col, $content_col);
    my $col = 1;
    while (defined &xls_cell_value($WorkSheet, 1, $col))
    {
        if (&xls_cell_value($WorkSheet, 1, $col) eq $key)
        {
            $key_col = $col
        }
        if (&xls_cell_value($WorkSheet, 1, $col) eq $content)
        {
            $content_col = $col
        }
        $col++;
    }

    if ($DebugPrint == 1)
    {
    	   print "key_col = $key_col; content_col = $content_col\n";
    }

    ### collect all key contents in the output href
    my $row = 2;
    my $empty_flag = 0;  # exit if two consecutive empty lines are encountered
    while (1)
    {
    	   if (!defined &xls_cell_value($WorkSheet, $row, $key_col))
    	   {
    	   	   if ($empty_flag == 0)
    	   	   {
    	   	   	   $empty_flag = 1;
    	   	   }
    	   	   elsif ($empty_flag == 1)
    	   	   {
    	   	   	   last;
    	   	   }
    	   	   
    	   }
    	   else
    	   {
    	   	   $empty_flag = 0;
    	   }

    	   my $key_val = &xls_cell_value($WorkSheet, $row, $key_col);
    	   my $content_val = &xls_cell_value($WorkSheet, $row, $content_col);
    	   if ($content_val =~ /\w+/)
    	   {
    	       my @key_list = split /\s/, $key_val;
#print "key_val = $key_val, content_val = $content_val\n";
            foreach (@key_list)
            {
            	   if (/\w+/)
        	       {
        	       	   if (!defined $target_href->{$_})
        	       	   {
        	       	   	   $target_href->{$_} = $content_val;
        	       	   }
            	   }
            }
        }
        $row++;
    }

    ### close the temp Excel file
    $Book->Close(1);
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
      my ($error_msg, $file, $line_no) = @_;
      
      my $final_error_msg = "CKFLASHID ERROR: $error_msg at $file line $line_no\n";
      print $final_error_msg;
      die $final_error_msg;
}
