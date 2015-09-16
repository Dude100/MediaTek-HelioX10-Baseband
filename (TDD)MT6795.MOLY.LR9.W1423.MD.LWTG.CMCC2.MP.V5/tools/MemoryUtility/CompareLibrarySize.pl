use strict;
BEGIN { push @INC, '../', './tools/', './tools/MemoryUtility/' }
use LinkerOutputParser;
use File::Basename;

&Usage() if ($#ARGV != 1); 

my ($file1, $file2) = @ARGV;
$file1 =~ s/\\/\\\\/;
$file2 =~ s/\\/\\\\/;

my ($libs1_aref, $RO_1_href, $RW_1_href, $ZI_1_href, $libs2_aref, $RO_2_href, $RW_2_href, $ZI_2_href);

if(($file1 =~ /\.lis$/) && ($file2 =~ /\.lis$/) or ($file1 =~ /\.map$/) && ($file2 =~ /\.map$/))
{
	($libs1_aref, $RO_1_href, $RW_1_href, $ZI_1_href) = &GetAllLibs($file1);
	($libs2_aref, $RO_2_href, $RW_2_href, $ZI_2_href) = &GetAllLibs($file2);
}
else
{
	&Usage();
}

my @libs1 = @$libs1_aref;
my @libs2 = @$libs2_aref;

my %libs1 = map{$_ => 1} @libs1;
my %libs2 = map{$_ => 1} @libs2;

my @inter = grep {$libs1{$_}} @libs2;

my %merge = map {$_ => 1} @libs1,@libs2; 
my @merge = sort keys (%merge);

my @libs1_only = grep {!$libs2{$_}} @merge;
my @libs2_only = grep {!$libs1{$_}} @merge;

print "Compare result as below:\n";


	print "**************************************************************************************************************************************\n";
	print "                                               Codebase1                           Codebase2                              Diff\n";
	print "LibraryName                               ROSize;RWSize;ZISize                ROSize;RWSize;ZISize                ROSize;RWSize;ZISize\n";
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
		
	foreach my $lib(@merge)
	{
		$$RO_2_href{$lib} = 0 if(!defined $$RO_2_href{$lib});
		$$RO_1_href{$lib} = 0 if(!defined $$RO_1_href{$lib});
		$$RW_2_href{$lib} = 0 if(!defined $$RW_2_href{$lib});
		$$RW_1_href{$lib} = 0 if(!defined $$RW_1_href{$lib});
		$$ZI_2_href{$lib} = 0 if(!defined $$ZI_2_href{$lib});
		$$ZI_1_href{$lib} = 0 if(!defined $$ZI_1_href{$lib});
		
		my $RO_diff = $$RO_2_href{$lib} - $$RO_1_href{$lib};
		my $RW_diff = $$RW_2_href{$lib} - $$RW_1_href{$lib};
		my $ZI_diff = $$ZI_2_href{$lib} - $$ZI_1_href{$lib};

		my $codebase1 = $$RO_1_href{$lib}.";".$$RW_1_href{$lib}.";".$$ZI_1_href{$lib};
		my $codebase2 = $$RO_2_href{$lib}.";".$$RW_2_href{$lib}.";".$$ZI_2_href{$lib};
		my $diff = $RO_diff.";".$RW_diff.";".$ZI_diff;
		
		$total_RO_1 += $$RO_1_href{$lib};
		$total_RW_1 += $$RW_1_href{$lib};
		$total_ZI_1 += $$ZI_1_href{$lib};
		
		$total_RO_2 += $$RO_2_href{$lib};
		$total_RW_2 += $$RW_2_href{$lib};
		$total_ZI_2 += $$ZI_2_href{$lib};
		
		$total_RO_diff += $RO_diff;
		$total_RW_diff += $RW_diff;
		$total_ZI_diff += $ZI_diff;

		$~ = "LIS_COMPARE";
	    format LIS_COMPARE = 
@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
$lib,$codebase1,$codebase2,$diff
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


sub GetAllLibs
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

	my %libs = ();
	my @uni_libs = ();
	my %RO_Size = ();
	my %RW_Size = ();
	my %ZI_Size = ();
	
	if (defined $exeregion_aref)
	{
		foreach my $temp(@$exeregion_aref)
		{
			my $lib_aref = &LinkerOutputParser::GetLibByExeRegion($temp);
			if (defined $lib_aref)
			{
				foreach (@$lib_aref)
				{
					map { $libs{$_} = 1} @$lib_aref;
				}
			}
		}
	}
	
	foreach my $lib(keys %libs)
	{
	    push (@uni_libs, $lib);
		my ($nRO_Size, $nRW_Size, $nZI_Size) = (0,0,0);
		
		if($file1 =~ /\.lis$/)
		{
			$nRO_Size = &LinkerOutputParser::ListLibSummaryInfo($lib, "RO Data") + &LinkerOutputParser::ListLibSummaryInfo($lib, "Code");
			$nRW_Size = &LinkerOutputParser::ListLibSummaryInfo($lib, "RW Data");
			$nZI_Size = &LinkerOutputParser::ListLibSummaryInfo($lib, "ZI Data");
			$RO_Size{$lib} = $nRO_Size;
			$RW_Size{$lib} = $nRW_Size;
		    $ZI_Size{$lib} = $nZI_Size;
		}
		elsif($file1 =~ /\.map$/)
		{
			$nRO_Size = &LinkerOutputParser::ListLibSummaryInfo($lib, "RO");
			$nRW_Size = &LinkerOutputParser::ListLibSummaryInfo($lib, "RW");
			$nZI_Size = &LinkerOutputParser::ListLibSummaryInfo($lib, "ZI");
			$RO_Size{$lib} = $nRO_Size;
			$RW_Size{$lib} = $nRW_Size;
		    $ZI_Size{$lib} = $nZI_Size;
		}
	}
	
	return (\@uni_libs, \%RO_Size, \%RW_Size, \%ZI_Size);
}


sub Usage
{
  print <<"__EOFUSAGE";

usage: perl CompareLibrarySize.pl lis/map_file_path1 lis/map_file/path2

lis/map_file_path1: lis/map file path for codebase1 you want to compare
lis/map_file_path2: lis/map file path for codebase2 you want to compare

lis/map_file_path1, lis/map_file_path2 should be the same file type (both .lis file or both .map file, comparison between .lis and .map is not supported)

e.g. perl CompareLibrarySize.pl "E:\\mtk80506\\MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00\\MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00.map" "E:\\mtk80506\\MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00.map"

Note: 
For GCC linker output, there should be corresponding .sym file in the same folder of .map file.

__EOFUSAGE
  exit 1;
}
