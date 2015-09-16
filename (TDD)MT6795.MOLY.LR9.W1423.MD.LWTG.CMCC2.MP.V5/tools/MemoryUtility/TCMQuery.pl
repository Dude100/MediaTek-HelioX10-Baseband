use strict;
BEGIN { push @INC, '../', './tools/', './tools/MemoryUtility/' }
use LinkerOutputParser;
use File::Basename;

&Usage() if (($#ARGV != 2) && ($#ARGV != 3)); 

my ($option, $region, $file1, $file2) = @ARGV;

$file1 =~ s/\\/\\\\/;
$file2 =~ s/\\/\\\\/;

if(($option eq "-Q") || ($option eq "-q"))
{
    &TCMQuery($region, $file1);
}
elsif(($option eq "-C") || ($option eq "-c"))
{
    &TCMCompare($region, $file1, $file2);
}
elsif(($option eq "-S") || ($option eq "-s"))
{
    my @SymbolInfo; #[[SymbolName, address, size], ...] sorted by address
    GetSymbolBySection($file1, $region, \@SymbolInfo);
    ListAllSymbolInfo(\@SymbolInfo);
}
elsif(($option eq "-SC") || ($option eq "-sc"))
{
    my @SymbolInfo1; #[[SymbolName, address, size], ...] sorted by address
    GetSymbolBySection($file1, $region, \@SymbolInfo1);
    my @SymbolInfo2; #[[SymbolName, address, size], ...] sorted by address
    GetSymbolBySection($file2, $region, \@SymbolInfo2);
    my $diff_href = DiffSymbolInfo(\@SymbolInfo1, \@SymbolInfo2);
    ListDiffSymbolInfo($diff_href, 0);
}
elsif(($option eq "-SCE") || ($option eq "-sce")) # section compare only in empty symbol
{
    my @SymbolInfo1; #[[SymbolName, address, size], ...] sorted by address
    GetSymbolBySection($file1, $region, \@SymbolInfo1);
    my @SymbolInfo2; #[[SymbolName, address, size], ...] sorted by address
    GetSymbolBySection($file2, $region, \@SymbolInfo2);
    my $diff_href = DiffSymbolInfo(\@SymbolInfo1, \@SymbolInfo2);
    ListDiffSymbolInfo($diff_href, 1);
}
else
{
    &Usage();
}

sub GetSymbolBySection
{
    my ($symfile, $strSection, $SymbolInfo_aref) = @_;
    LinkerOutputParser::FileParse($symfile);
    my @regions = split(/\,/, $strSection);
    foreach my $section (@regions)
    {
        if($section eq "INTSRAM")
        {
            my $temp1_aref = LinkerOutputParser::GrepSymbolBySection("INTSRAM_CODE");
            my $temp2_aref = LinkerOutputParser::GrepSymbolBySection("INTSRAM_DATA");
            my $temp3_aref = LinkerOutputParser::GrepSymbolBySection("INTSRAM_DATA_ZI");
            my $temp3_aref = LinkerOutputParser::GrepSymbolBySection("INTSRAM_DATA_ZI");
            my $temp4_aref = LinkerOutputParser::GrepSymbolBySection("INTSRAM_DATA_B1");
            my $temp5_aref = LinkerOutputParser::GrepSymbolBySection("INTSRAM_DATA_B1_ZI");
            push(@$SymbolInfo_aref , @$temp1_aref, @$temp2_aref, @$temp3_aref, @$temp4_aref, @$temp5_aref);
        }
        else
        {
            my $temp_aref = LinkerOutputParser::GrepSymbolBySection($section);
            push(@$SymbolInfo_aref , @$temp_aref);
        }    
    }
}

sub DiffSymbolInfo
{
    my ($SymInfo1_aref, $SymInfo2_aref) = @_;
    my %diff;
    foreach my $item (@$SymInfo1_aref)
    {
        if(!exists $diff{$item->[SymTable::Name]})
        {
            $diff{$item->[SymTable::Name]} = [ $item->[SymTable::Size] , -1, $item->[SymTable::Region]];
        }
        else
        {
            $diff{$item->[SymTable::Name]."+"} = [ $item->[SymTable::Size] , -1, $item->[SymTable::Region]];
        }
    }
    foreach my $item (@$SymInfo2_aref)
    {
        if(exists $diff{$item->[SymTable::Name]})
        {
            $diff{$item->[SymTable::Name]}[1] = $item->[SymTable::Size];
        }
        else
        {
            $diff{$item->[SymTable::Name]} = [ -1, $item->[SymTable::Size], $item->[SymTable::Region]];
        }
    }
    return \%diff;
}
sub ListDiffSymbolInfo
{
    my ($diff_href, $bListEmptyOnly) = @_;
    print "   $file1 \nvs. $file2\n";
    print "SymbolName                                                                      Size1             Size2\n";
    print "*********************************************************************************************************************\n";
    my $strRegion;
    my ($nTotalSize1, $nTotalSize2) = (0,0);
    foreach my $key (sort keys %$diff_href)
    {
        my $strSize1 = $diff_href->{$key}[0] eq "-1" ? "" : $diff_href->{$key}[0];
        my $strSize2 = $diff_href->{$key}[1] eq "-1" ? "" : $diff_href->{$key}[1];
        next if(($strSize1 eq $strSize2));
        if($bListEmptyOnly)
        {
            next if(!($diff_href->{$key}[0] eq "-1" or $diff_href->{$key}[1] eq "-1"));
        }
        $nTotalSize1 += $strSize1;
        $nTotalSize2 += $strSize2;
        $~ = "DIFF";
        format DIFF =
@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<@<<<<<<<<<
$key,$strSize1,$strSize2
.
write;
    }
    print "*********************************************************************************************************************\n";
    $~ = "TOTALDIFF";
    format TOTALDIFF = 
@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<@<<<<<<<<<
'Total',$nTotalSize1,$nTotalSize2
.
write;
}

sub ListAllSymbolInfo
{
    my ($SymInfo_aref) = @_;
    print "[Section]\n";
    print "Address       Size    Group            Symbol Name\n";
    print "*********************************************************************************************************************\n";
    my $strSection;
    my $nNextAddress = 0;
    my $nIndex = 0;
    foreach my $item (@$SymInfo_aref)
    {
        if($item->[SymTable::Region] ne $strSection)
        {
            $strSection = $item->[SymTable::Region];
            print "[$strSection]\n";
        }
        
        my $nSize = $item->[SymTable::Size];
        my $strSize = $nSize;
        if($nSize == 0)
        {
            if($nIndex+1 < scalar(@$SymInfo_aref) and $SymInfo_aref->[$nIndex+1][SymTable::Region] eq $strSection)
            {
                $nSize = hex($SymInfo_aref->[$nIndex+1][SymTable::Addr]) - hex($item->[SymTable::Addr]) ;
            }
            else
            {
                $nSize = "--";
            }
            $strSize = "0($nSize)";
        }
        $~ = "SYMBOLS";
        format SYMBOLS =
@<<<<<<<<<<<<<@<<<<<<<<<@<<<<<<@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
$item->[SymTable::Addr],$strSize,$item->[SymTable::Group],$item->[SymTable::Name],
.
write;
        $nIndex++;
    }
}

sub TCMQuery
{
    my ($ExeRegion, $file) = @_;
    
    my ($objs_aref, $RO_href, $RW_href, $ZI_href) = &GetAllOBJ($ExeRegion, $file);
    print "Object_Name                                   RO_Size             RW_Size            ZI_Size\n";
    print "***********************************************************************************************\n";

    my $total_RO;
    my $total_RW;
    my $total_ZI;
    
    foreach my $temp(sort @$objs_aref)
    {
        $~ = "LIS_QUERY";
        format LIS_QUERY = 
@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<
$temp,$$RO_href{$temp},$$RW_href{$temp},$$ZI_href{$temp}
.
        
write;
            $total_RO += $$RO_href{$temp};
            $total_RW += $$RW_href{$temp};
            $total_ZI += $$ZI_href{$temp};          
    }
    $~ = "LIS_QUERY_TOTAL";
    format LIS_QUERY_TOTAL = 
@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<
"Total",$total_RO,$total_RW,$total_ZI
.
        
write;
    
    print "***********************************************************************************************\n";
}

sub TCMCompare
{
    my ($ExeRegion, $file1, $file2) = @_;
    my ($objs1_aref, $RO_1_href, $RW_1_href, $ZI_1_href, $objs2_aref, $RO_2_href, $RW_2_href, $ZI_2_href);
   
    ($objs1_aref, $RO_1_href, $RW_1_href, $ZI_1_href) = &GetAllOBJ($ExeRegion, $file1);
    ($objs2_aref, $RO_2_href, $RW_2_href, $ZI_2_href) = &GetAllOBJ($ExeRegion, $file2);
    
    my @objs1 = @$objs1_aref;
    my @objs2 = @$objs2_aref;

    my %objs1 = map{$_ => 1} @objs1;
    my %objs2 = map{$_ => 1} @objs2;
    my @arr = map{$_ => 1} @objs1; 

    my @inter = grep {$objs1{$_}} @objs2;

    my %merge = map {$_ => 1} @objs1,@objs2; 
    my @merge = sort keys (%merge);

    my @objs1_only = grep {!$objs2{$_}} @merge;
    my @objs2_only = grep {!$objs1{$_}} @merge;

    print "Compare result as below:\n";


        print "**************************************************************************************************************************************\n";
        print "                                               Codebase1                           Codebase2                              Diff\n";
        print "ObjectName                                ROSize;RWSize;ZISize                ROSize;RWSize;ZISize                ROSize;RWSize;ZISize\n";
        print "**************************************************************************************************************************************\n";

        my $total_RO_1 = 0;
        my $total_RW_1 = 0;
        my $total_ZI_1 = 0;
        my $total_RO_2 = 0;
        my $total_RW_2 = 0;
        my $total_ZI_2 = 0;
        my $total_RO_diff = 0;
        my $total_RW_diff = 0;
        my $total_ZI_diff = 0;
        my $total_codebase1;
        my $total_codebase2;
        my $total_diff;
        
        foreach my $obj(@merge)
        {
            $$RO_2_href{$obj} = 0 if(!defined $$RO_2_href{$obj});
            $$RO_1_href{$obj} = 0 if(!defined $$RO_1_href{$obj});
            $$RW_2_href{$obj} = 0 if(!defined $$RW_2_href{$obj});
            $$RW_1_href{$obj} = 0 if(!defined $$RW_1_href{$obj});
            $$ZI_2_href{$obj} = 0 if(!defined $$ZI_2_href{$obj});
            $$ZI_1_href{$obj} = 0 if(!defined $$ZI_1_href{$obj});
            
            my $RO_diff = $$RO_2_href{$obj} - $$RO_1_href{$obj};
            my $RW_diff = $$RW_2_href{$obj} - $$RW_1_href{$obj};
            my $ZI_diff = $$ZI_2_href{$obj} - $$ZI_1_href{$obj};

            my $codebase1 = $$RO_1_href{$obj}.";".$$RW_1_href{$obj}.";".$$ZI_1_href{$obj};
            my $codebase2 = $$RO_2_href{$obj}.";".$$RW_2_href{$obj}.";".$$ZI_2_href{$obj};
            my $diff = $RO_diff.";".$RW_diff.";".$ZI_diff;
            
            $total_RO_1 += $$RO_1_href{$obj};
            $total_RW_1 += $$RW_1_href{$obj};
            $total_ZI_1 += $$ZI_1_href{$obj};
            
            $total_RO_2 += $$RO_2_href{$obj};
            $total_RW_2 += $$RW_2_href{$obj};
            $total_ZI_2 += $$ZI_2_href{$obj};
            
            $total_RO_diff += $RO_diff;
            $total_RW_diff += $RW_diff;
            $total_ZI_diff += $ZI_diff;
            
            $~ = "LIS_COMPARE";
            format LIS_COMPARE = 
@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
$obj,$codebase1,$codebase2,$diff
.
        
write;
        }
        
        $total_codebase1 = $total_RO_1.";".$total_RW_1.";".$total_ZI_1;
        $total_codebase2 = $total_RO_2.";".$total_RW_2.";".$total_ZI_2;
        $total_diff = $total_RO_diff.";".$total_RW_diff.";".$total_ZI_diff;
            
        $~ = "LIS_TOTAL";
        format LIS_TOTAL = 
@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
"Total",$total_codebase1,$total_codebase2,$total_diff
.
        
write;

    print "**************************************************************************************************************************************\n";
}

sub GetAllOBJ
{
    my ($ExeRegion, $file) = @_;
    my $symfile = $file;
    my $exeregion_aref;
    
    if($file =~ /\.map$/)
    {
        $symfile =~ s/map/sym/;
        if(!-f $symfile)
        {
            my $file = basename($symfile);
            my $dirname  = dirname($symfile);
            $symfile = $dirname."\/dummy_$file";
        }        
        &LinkerOutputParser::FileParse($symfile);
    }
    &LinkerOutputParser::FileParse($file);
    $exeregion_aref = &LinkerOutputParser::ListAllExeRegion(1);

    my %objs;
    my @uni_objs;
    my %count; 
    my %RO_Size;
    my %RW_Size;
    my %ZI_Size;
    if (defined $exeregion_aref)
    {
        foreach my $temp(@$exeregion_aref)
        {
            next if ($temp !~ /^$ExeRegion/i);
            my $obj_aref = &LinkerOutputParser::GetObjByExeRegion($temp);
            if (defined $obj_aref)
            {
                map { $objs{$_} = 1} @$obj_aref;
            }
        }
    }
    
    foreach my $obj(keys %objs)
    {
        push (@uni_objs, $obj);
        my ($nRO_Size, $nRW_Size, $nZI_Size);
        if (defined $exeregion_aref)
        {
            foreach my $temp(@$exeregion_aref)
            {
                next if ($temp !~ /^$ExeRegion/i);
                
                if($file =~ /\.lis$/)
                {
                    $nRO_Size = &LinkerOutputParser::GetObjSizeByCatExeRegion($temp, $obj, "RO Data") + &LinkerOutputParser::GetObjSizeByCatExeRegion($temp, $obj, "Code");
                    $nRW_Size = &LinkerOutputParser::GetObjSizeByCatExeRegion($temp, $obj, "RW Data");
                    $nZI_Size = &LinkerOutputParser::GetObjSizeByCatExeRegion($temp, $obj, "ZI Data");

                    _UpdateSize(\%RO_Size, $obj, $nRO_Size);
                    _UpdateSize(\%RW_Size, $obj, $nRW_Size);
                    _UpdateSize(\%ZI_Size, $obj, $nZI_Size);
                }
                elsif($file =~ /\.map$/)
                {
                    if ($obj =~ /\.o|\*fill\*|stub/) #(/\*fill\*\s+(0x\w+)\s+(0x\w+)/)
                    {
                        $nRO_Size = &LinkerOutputParser::GetObjSizeByCatExeRegion($temp, $obj, "RO");
                        $nRW_Size = &LinkerOutputParser::GetObjSizeByCatExeRegion($temp, $obj, "RW");
                        $nZI_Size = &LinkerOutputParser::GetObjSizeByCatExeRegion($temp, $obj, "ZI");
                        _UpdateSize(\%RO_Size, $obj, $nRO_Size);
                        _UpdateSize(\%RW_Size, $obj, $nRW_Size);
                        _UpdateSize(\%ZI_Size, $obj, $nZI_Size);
                    }
                }
            }
        }
        
    }
    
    return (\@uni_objs, \%RO_Size, \%RW_Size, \%ZI_Size);
}


sub _UpdateSize
{
    my ($href, $strKey, $nSize) = @_;
    if(exists $href->{$strKey})
    {
        $href->{$strKey} += $nSize;
    }
    else
    {
        $href->{$strKey} = $nSize;
    } 
}

sub Usage
{
  print <<"__EOFUSAGE";

usage: perl TCMQuery.pl -Q INTSRAM lis/map_file_path
       perl TCMQuery.pl -q INTSRAM lis/map_file_path
       perl TCMQuery.pl -C INTSRAM lis/map_file_path1 lis/map_file_path2
       perl TCMQuery.pl -c INTSRAM lis/map_file_path1 lis/map_file_path2
       perl TCMQuery.pl -S INTSRAM lis/sym_file_path
       perl TCMQuery.pl -s INTSRAM lis/sym_file_path

lis/map_file_path1: lis/map file path for codebase1 you want to compare
lis/map_file_path2: lis/map file path for codebase2 you want to compare

e.g. 
perl TCMQuery.pl -Q INTSRAM "E:\\mtk80506\\MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00\\MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00.map"
perl TCMQuery.pl -C INTSRAM "E:\\mtk80506\MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00\\MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00.map" "E:\\mtk80506\\MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00.map"

__EOFUSAGE
  exit 1;
}