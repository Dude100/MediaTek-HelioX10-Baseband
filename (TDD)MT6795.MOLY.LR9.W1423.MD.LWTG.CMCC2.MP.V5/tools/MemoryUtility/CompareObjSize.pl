use strict;
BEGIN { push @INC, '../', './tools/', './tools/MemoryUtility/' }
use LinkerOutputParser;
use File::Basename;

&Usage() if ($#ARGV != 1); 

my ($file1, $file2) = @ARGV;
$file1 =~ s/\\/\\\\/;
$file2 =~ s/\\/\\\\/;

my ($objs1_aref, $RO_1_href, $RW_1_href, $ZI_1_href, $objs2_aref, $RO_2_href, $RW_2_href, $ZI_2_href);

if(($file1 =~ /\.lis$/) && ($file2 =~ /\.lis$/) or ($file1 =~ /\.map$/) && ($file2 =~ /\.map$/))
{
	($objs1_aref, $RO_1_href, $RW_1_href, $ZI_1_href) = &GetAllOBJs($file1);
	($objs2_aref, $RO_2_href, $RW_2_href, $ZI_2_href) = &GetAllOBJs($file2);
}
else
{
	&Usage();
}

my @objs1 = @$objs1_aref;
my @objs2 = @$objs2_aref;

my %objs1 = map{$_ => 1} @objs1;
my %objs2 = map{$_ => 1} @objs2;

my @inter = grep {$objs1{$_}} @objs2;

my %merge = map {$_ => 1} @objs1,@objs2; 
my @merge = sort keys (%merge);

my @objs1_only = grep {!$objs2{$_}} @merge;
my @objs2_only = grep {!$objs1{$_}} @merge;

print "Compare result as below:\n";


	print "**************************************************************************************************************************************\n";
	print "                                               Codebase1                           Codebase2                              Diff\n";
	print "ObjectName                               ROSize;RWSize;ZISize                ROSize;RWSize;ZISize                ROSize;RWSize;ZISize\n";
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


sub GetAllOBJs
{
	my ($file) = @_;
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
	

	my @objs = ();
	my @uni_objs = ();
	my %RO_Size;
	my %RW_Size;
	my %ZI_Size;
	my %RWZI_Size;
	my %count;
	
	if (defined $exeregion_aref)
	{
		foreach my $temp(@$exeregion_aref)
		{
			my $obj_aref = &LinkerOutputParser::GetObjByExeRegion($temp);
			if (defined $obj_aref)
			{
				foreach (@$obj_aref)
				{
					push(@objs, $_);
				}
			}
		}
	}
	
	@uni_objs = grep { ++$count{ $_ } < 2; } @objs; 
	
	foreach my $obj(@uni_objs)
	{
		my ($nRO_Size, $nRW_Size, $nZI_Size) = (0,0,0);
		
		if($file1 =~ /\.lis$/)
		{
			$nRO_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "RO Data") + &LinkerOutputParser::ListObjSummaryInfo($obj, "Code");
			$nRW_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "RW Data");
			$nZI_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "ZI Data");
			$RO_Size{$obj} = $nRO_Size;
			$RW_Size{$obj} = $nRW_Size;
		    $ZI_Size{$obj} = $nZI_Size;
		}
		elsif($file1 =~ /\.map$/)
		{
			$nRO_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "RO");
			$nRW_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "RW");
			$nZI_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "ZI");
			$RO_Size{$obj} = $nRO_Size;
			$RW_Size{$obj} = $nRW_Size;
		    $ZI_Size{$obj} = $nZI_Size;
		}
	}
	
	return (\@uni_objs, \%RO_Size, \%RW_Size, \%ZI_Size);
}


sub Usage
{
  print <<"__EOFUSAGE";

usage: perl CompareobjrarySize.pl lis/map_file_path1 lis/map_file/path2

lis/map_file_path1: lis/map file path for codebase1 you want to compare
lis/map_file_path2: lis/map file path for codebase2 you want to compare

lis/map_file_path1, lis/map_file_path2 should be the same file type (both .lis file or both .map file, comparison between .lis and .map is not supported)

e.g. perl CompareobjrarySize.pl "E:\\mtk80506\\MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00\\MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00.map" "E:\\mtk80506\\MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00.map"

Note: 
For GCC linker output, there should be corresponding .sym file in the same folder of .map file.

__EOFUSAGE
  exit 1;
}
