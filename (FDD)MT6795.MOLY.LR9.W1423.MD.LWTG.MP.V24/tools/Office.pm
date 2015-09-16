#!/usr/bin/perl
#
# Filename: 
# ---------
#  Office.pm
#
# Description: 
# ------------
#  Microsoft Office access functions.
#
# Auther: 
# -------
#  mtk01542
# 
# Note:
# -----
#  Hints for Win32 Ole: for object, use 'abc->def'; for attribute, use 'abc->{def}'.
#
# Log: 
# -----
#  2006/12/26   Create for Excel part.
#

package Office;                           # declare package library
use strict;

# for use of Excel
use Win32::OLE qw(in with);
use Win32::OLE::Const 'Microsoft Excel';
$Win32::OLE::Warn = 3;

#******************************************************************************
# Global Data
#******************************************************************************
my $g_excel_name = "";
my $g_excel;
my $g_book;
my $g_sheet;

my %g_fontAttr = ('Name' => 'Arial', 'Size' => 11, 'Bold' => 0, 'ColorIndex' => 1);
my %g_fontColorHash = ('black' => 1, 'white' => 2, 'red' => 3, 'blue' => 5);

my $curr_obj;

#******************************************************************************
# Export Function
#******************************************************************************


#******************************************************************************
# FUNCTION
#  excelGetColIndex
# DESCRIPTION
#  get column index by given cell names and desired row
# PARAMETERS
#  para 1 - reference to cell name array
#  para 2 - reference to index hash
#  para 3 - desired row number
# RETURNS
#  none
#******************************************************************************
sub excelGetColIndex()
{
    my $indexStrArray_ref;
    my $indexHash_ref;
    my $row;
    
    ($indexStrArray_ref, $indexHash_ref, $row) = @_;
    
    foreach my $indexStr (@{$indexStrArray_ref})
    {
        ${$indexHash_ref}{$indexStr} = 0;
        my $col = 1;
        my $str = trim(excelRead($row, $col));    
        while ($str ne "")
        {
            if ($str =~ /^$indexStr$/i)
            {
                ${$indexHash_ref}{$indexStr} = $col;
                #print "$indexStr = $col\n";
            }
            $col++;
            $str = trim(excelRead($row, $col));
        }
    }	
}


#******************************************************************************
# FUNCTION
#  excelNew
# DESCRIPTION
#  new an excel file
# PARAMETERS
#  para 1 - filename
# RETURNS
#  none
#******************************************************************************
sub excelNew()
{
    $g_excel_name = $_[0];
        
    $g_excel = Win32::OLE->new('Excel.Application', 'Quit') or die "Oops, cannot start Excel";
    #Win32::OLE->Option(CP => Win32::OLE::CP_UTF8);
    
    $curr_obj = $g_excel;
    
    $g_book = $g_excel->Workbooks->Add;
    $g_sheet = $g_book->Worksheets(1);
}


#******************************************************************************
# FUNCTION
#  excelOpen
# DESCRIPTION
#  open an excel file
# PARAMETERS
#  para 1 - filename
# RETURNS
#  none
#******************************************************************************
sub excelOpen()
{
    my $file = $_[0];
    
    $g_excel = Win32::OLE->new('Excel.Application', 'Quit') or die "Oops, cannot start Excel";
    #Win32::OLE->Option(CP => Win32::OLE::CP_UTF8);
    
    $curr_obj = $g_excel;
    
    die "\n[ERROR] $file doesn't exist!\n" if (!(-e $file));
    $g_book = $g_excel->Workbooks->Open("$file");
    $g_sheet = $g_book->Worksheets(1);
}


#******************************************************************************
# FUNCTION
#  excelSetWorksheet
# DESCRIPTION
#  set worksheet of excel file
# PARAMETERS
#  para 1 - worksheet name
# RETURNS
#  none
#******************************************************************************
sub excelSetWorksheet()
{
	my $worksheet;
	
	($worksheet) = @_;
	
	$g_sheet = $g_book->Worksheets($worksheet);
}


#******************************************************************************
# FUNCTION
#  excelAddWorksheet
# DESCRIPTION
#  add worksheet to excel file
# PARAMETERS
#  para 1 - worksheet name
#  para 2 - how to add? to right/left or rightest
#  para 3 - name of reference worksheet
# RETURNS
#  none
#******************************************************************************
sub excelAddWorksheet()
{
    my $name;
    my $cmd;
    my $arg;
    
    ($name, $cmd, $arg) = @_;
      
    $arg = $g_book->ActiveSheet->{Name} if ($arg eq '');    # set to current if empty
       
    if ($cmd eq 'rightest')
    {
        # add worksheet as rightest one
        $g_book->Worksheets->add(
            {After=>$g_book->Worksheets($g_book->Worksheets->{Count})})->{Name} = $name;      
    }
    elsif ($cmd eq 'right')
    {
        # add worksheet at the right of given worksheet
        $g_book->Worksheets->add(
            {After=>$g_book->Worksheets($arg)})->{Name} = $name;  
    }
    else 
    {
        # add worksheet at the left of given worksheet
        $g_book->Worksheets->add(
            {Before=>$g_book->Worksheets($arg)})->{Name} = $name;        
    }
    $g_sheet = $g_book->Worksheets($name);    
}

#******************************************************************************
# FUNCTION
#  excelOpenText
# DESCRIPTION
#  open a text file to excel
# PARAMETERS
#  para 1 - text filename
#  para 2 - delimiter character
# RETURNS
#  none
#******************************************************************************
sub excelOpenText()
{
    my $file = $_[0];
    my $delimiter = $_[1];
    
    $g_excel = Win32::OLE->new('Excel.Application', 'Quit') or die "Oops, cannot start Excel";
    #Win32::OLE->Option(CP => Win32::OLE::CP_UTF8);

    $curr_obj = \$g_excel;
    
    $g_book = $g_excel->Workbooks->Open($file, 0, 0, 6, 0, 0, 0, 2, $delimiter);
    $g_sheet = $g_book->Worksheets(1);
}


#******************************************************************************
# FUNCTION
#  excelSaveAs
# DESCRIPTION
#  save as another excel file
# PARAMETERS
#  para 1 - filename
# RETURNS
#  none
#******************************************************************************
sub excelSaveAs()
{
    $g_book->SaveAs("$_[0]");
}


#******************************************************************************
# FUNCTION
#  excelClose
# DESCRIPTION
#  close excel file
# PARAMETERS
#  none
# RETURNS
#  none
#******************************************************************************
sub excelClose()
{
    if ($g_excel_name ne "")
    {
        $g_book->SaveAs("$g_excel_name");
    }
    $g_book->Close();
}


#******************************************************************************
# FUNCTION
#  excelWriteRow
# DESCRIPTION
#  write data items to row
# PARAMETERS
#  para 1 - row
#  para 2 - start of col
#  para 3 - reference to data array (e.g. \@abc)
# RETURNS
#  none
#******************************************************************************
sub excelWriteRow()
{
    my $row = $_[0];
    my $col = $_[1];
    my $data_ref = $_[2];
            
    foreach my $item (@$data_ref)
    {
        excelSetFontAttr($g_sheet->Cells($row,$col));
        $g_sheet->Cells($row,$col)->{Value} = "$item";
        $col++;
    }
}


#******************************************************************************
# FUNCTION
#  excelWriteCol
# DESCRIPTION
#  write data items to column
# PARAMETERS
#  para 1 - start of row
#  para 2 - column
#  para 3 - reference to data array (e.g. \@abc)
# RETURNS
#  none
#******************************************************************************
sub excelWriteCol()
{
    my $row = $_[0];
    my $col = $_[1];
    my $data_ref = $_[2];
            
    foreach my $item (@$data_ref)
    {
        excelSetFontAttr($g_sheet->Cells($row,$col));
        $g_sheet->Cells($row,$col)->{Value} = "$item";
        $row++;
    }
}


#******************************************************************************
# FUNCTION
#  excelWrite
# DESCRIPTION
#  write a cell
# PARAMETERS
#  para 1 - row
#  para 2 - col
#  para 3 - data
# RETURNS
#  none
#******************************************************************************
sub excelWrite()
{
    my $row = $_[0];
    my $col = $_[1];
    my $data = $_[2];

    excelSetFontAttr($g_sheet->Cells($row,$col));    
    $g_sheet->Cells($row,$col)->{Value} = "$data";
}


#******************************************************************************
# FUNCTION
#  excelRead
# DESCRIPTION
#  read a cell
# PARAMETERS
#  para 1 - row
#  para 2 - col
# RETURNS
#  data read
#******************************************************************************
sub excelRead()
{
    my $row = $_[0];
    my $col = $_[1];
    
    return $g_sheet->Cells($row,$col)->{Value};
}


#******************************************************************************
# FUNCTION
#  excelDelCol
# DESCRIPTION
#  delete a column
# PARAMETERS
#  para 1 - column to delete
# RETURNS
#  none
#******************************************************************************
sub excelDelCol()
{
    $g_sheet->Columns($_[0])->Delete;
}


#******************************************************************************
# FUNCTION
#  excelDelRow
# DESCRIPTION
#  delete a row
# PARAMETERS
#  para 1 - row to delete
# RETURNS
#  none
#******************************************************************************
sub excelDelRow()
{
    $g_sheet->Rows($_[0])->Delete;
}


#******************************************************************************
# FUNCTION
#  excelColAlignment
# DESCRIPTION
#  set alignment to specified column
# PARAMETERS
#  para 1 - column to set
#  para 2 - alignment type (center, right, left)
# RETURNS
#  none
#******************************************************************************
sub excelColAlignment()
{
    my $col;
    my $align;
    my %alignHash = ('center' => xlCenter, 'right' => xlRight, 'left' => xlLeft);
    
    ($col, $align) = @_;
    
    $g_sheet->Columns($col)->{HorizontalAlignment} = $alignHash{$align};
}


#******************************************************************************
# FUNCTION
#  excelColAlignmentAll
# DESCRIPTION
#  set alignment to all columns
# PARAMETERS
#  para 1 - alignment type (center, right, left)
# RETURNS
#  none
#******************************************************************************
sub excelColAlignmentAll()
{
    my $col;
    my $align;
    my %alignHash = ('center' => xlCenter, 'right' => xlRight, 'left' => xlLeft);
    
    ($align) = @_;
    
    $g_sheet->Cells->EntireColumn->{HorizontalAlignment} = $alignHash{$align};
}


#******************************************************************************
# FUNCTION
#  excelSetTextOrientation
# DESCRIPTION
#  set text orientation to specified cell
# PARAMETERS
#  para 1 - row to set
#  para 2 - column to set
#  para 3 - degree
# RETURNS
#  none
#******************************************************************************
sub excelSetTextOrientation()
{
    my $row;
    my $col;
    my $degree;
    
    ($row, $col, $degree) = @_;
    
    $g_sheet->Cells($row,$col)->{'Orientation'} = $degree;   # background color
}


#******************************************************************************
# FUNCTION
#  excelAutoFilter
# DESCRIPTION
#  enable auto-filter for all data (usually used when all data are ready)
# PARAMETERS
#  none
# RETURNS
#  none
#******************************************************************************
sub excelAutoFilter()
{
    $g_sheet->Cells->AutoFilter();
}


#******************************************************************************
# FUNCTION
#  excelAutoFit
# DESCRIPTION
#  set auto-fit to specified column
# PARAMETERS
#  para 1 - column to set
# RETURNS
#  none
#******************************************************************************
sub excelAutoFit()
{
    $g_sheet->Columns($_[0])->AutoFit;
}


#******************************************************************************
# FUNCTION
#  excelAutoFitAll
# DESCRIPTION
#  set auto-fit to all.
#  note that this only works when there's already data in cells.
# PARAMETERS
#  none
# RETURNS
#  none
#******************************************************************************
sub excelAutoFitAll()
{   
    $g_sheet->Cells->EntireColumn->AutoFit;
}


#******************************************************************************
# FUNCTION
#  excelSetFontName
# DESCRIPTION
#  set cell font name (e.g. Arial)
# PARAMETERS
#  para 1 - font name
# RETURNS
#  none
#******************************************************************************
sub excelSetFontName()
{
    my $fontName;
    
    ($fontName) = @_;
    
    $g_fontAttr{'Name'} = $fontName if ($fontName ne "");
}


#******************************************************************************
# FUNCTION
#  excelSetFontSize
# DESCRIPTION
#  set cell font size
# PARAMETERS
#  para 1 - font size
# RETURNS
#  none
#******************************************************************************
sub excelSetFontSize()
{
    my $fontSize;
    
    ($fontSize) = @_;
    
    $g_fontAttr{'Size'} = $fontSize if ($fontSize > 0);
}


#******************************************************************************
# FUNCTION
#  excelSetFontColor
# DESCRIPTION
#  set cell font color
# PARAMETERS
#  para 1 - font color name
# RETURNS
#  none
#******************************************************************************
sub excelSetFontColor()
{
    my $fontColor;
    
    ($fontColor) = @_;
    
    $g_fontAttr{'ColorIndex'} = $g_fontColorHash{$fontColor} if (defined $g_fontColorHash{$fontColor});
}


#******************************************************************************
# FUNCTION
#  excelSetFontBold
# DESCRIPTION
#  set cell font bold
# PARAMETERS
#  para 1 - font bold
# RETURNS
#  none
#******************************************************************************
sub excelSetFontBold()
{
    my $fontBold;
    
    ($fontBold) = @_;
    
    $g_fontAttr{'Bold'} = $fontBold if ($fontBold =~ /[0-1]/);
}


#******************************************************************************
# FUNCTION
#  setVisible
# DESCRIPTION
#  write excel file
# PARAMETERS
#  para 1 - visible (1) or not (0)
# RETURNS
#  none
#******************************************************************************
sub setVisible()
{
    $$curr_obj->{Visible} = 1;
}


#******************************************************************************
# FUNCTION
#  excelWrapText
# DESCRIPTION
#  set wrap-text to specified column
#  (use this when there's data in specified column)
# PARAMETERS
#  para 1 - column to set
# RETURNS
#  none
#******************************************************************************
sub excelWrapText()
{
    $g_sheet->Columns($_[0])->{WrapText} = 1;
}


#******************************************************************************
# FUNCTION
#  excelWrapTextAll
# DESCRIPTION
#  set wrap-text to all columns
# PARAMETERS
#  none
# RETURNS
#  none
#******************************************************************************
sub excelWrapTextAll()
{
    $g_sheet->Cells->EntireColumn->{WrapText} = 1;
}


#******************************************************************************
# FUNCTION
#  excelSetColumnWidth
# DESCRIPTION
#  set width of specified column
# PARAMETERS
#  para 1 - column to set
#  para 2 - width
# RETURNS
#  none
#******************************************************************************
sub excelSetColumnWidth()
{
    $g_sheet->Columns($_[0])->{ColumnWidth} = $_[1];
}


#******************************************************************************
# FUNCTION
#  excelSetColumnWidthAll
# DESCRIPTION
#  set width of all columns
# PARAMETERS
#  para 1 - width
# RETURNS
#  none
#******************************************************************************
sub excelSetColumnWidthAll()
{
    $g_sheet->Cells->EntireColumn->{ColumnWidth} = $_[0];
}


#******************************************************************************
# FUNCTION
#  excelShrinkToFit
# DESCRIPTION
#  set shrink-to-fit to specified column
# PARAMETERS
#  para 1 - column to set
# RETURNS
#  none
#******************************************************************************
sub excelShrinkToFit()
{   
    $g_sheet->Columns($_[0])->{ShrinkToFit} = 1;
}


#******************************************************************************
# FUNCTION
#  excelShrinkToFitAll
# DESCRIPTION
#  set shrink-to-fit to all columns
# PARAMETERS
#  noneß
# RETURNS
#  none
#******************************************************************************
sub excelShrinkToFitAll()
{   
    $g_sheet->Cells->EntireColumn->{ShrinkToFit} = 1;
}

#******************************************************************************
# Internal Data
#******************************************************************************
    
#******************************************************************************
# Program Start
#******************************************************************************

1;  # return success

#******************************************************************************
# Internal Function
#******************************************************************************

#******************************************************************************
# FUNCTION
#  excelSetFontAttr
# DESCRIPTION
#  set cell font attributes
# PARAMETERS
#  $oleObject_ref - reference to ole object, may be cells, range, rows, columns, etc.
# RETURNS
#  none
#******************************************************************************
sub excelSetFontAttr()
{
    my $oleObject_ref;
    
    ($oleObject_ref) = @_;

    #$g_sheet->Cells($row,$col)->Interior->{'ColorIndex'}   # background color
            
    while (my ($key, $val) = each(%g_fontAttr))
    {
        $oleObject_ref->Font->{$key} = $val if ($val ne "");
    }
}


#******************************************************************************
# FUNCTION
#  trim
# DESCRIPTION
#  trim left and right spaces
# PARAMETERS
#  $str [IN] - string to process
# RETURNS
#  processed string
#******************************************************************************
sub trim()
{
    my $str;
    ($str) = @_;
    
    $str =~ s/(^\s*)|(\s*$)//g;
    return $str;
}
