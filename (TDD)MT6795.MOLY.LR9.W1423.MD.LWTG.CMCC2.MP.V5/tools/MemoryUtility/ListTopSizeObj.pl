use strict;
BEGIN { push @INC, '../', './tools/', './tools/MemoryUtility/' }
use LinkerOutputParser;
use File::Basename;
use constant Top_N  => 15;

&Usage() if ($#ARGV != 0); 

my ($file) = @ARGV;
$file =~ s/\\/\\\\/;

my ($objs1_aref, $RO_1_href, $RW_1_href, $ZI_1_href);

if(($file =~ /\.lis$/) or ($file =~ /\.map$/))
{
	($objs1_aref, $RO_1_href, $RW_1_href, $ZI_1_href) = &GetAllOBJs($file);
}
else
{
	&Usage();
}

my @objs1 = @$objs1_aref;

my %objs1 = map{$_ => 1} @objs1;

my $total_RO_1 = 0;
my $total_RW_1 = 0;
my $total_ZI_1 = 0;
my $total_codebase1;

foreach my $obj (@objs1)
{
	$total_RO_1 += $$RO_1_href{$obj};
	$total_RW_1 += $$RW_1_href{$obj};
	$total_ZI_1 += $$ZI_1_href{$obj};
}

my @RW_Top = sort { $$RW_1_href{$b} <=> $$RW_1_href{$a} } @objs1 ;
my @ZI_Top = sort { $$ZI_1_href{$b} <=> $$ZI_1_href{$a} } @objs1 ;


print "Top", Top_N, " result as below:\n";
	print "*"x80 . "\n";
	print "Rank  ObjectName                       RW/ZI_Size ROSize;RWSize;ZISize\n";
	my $sum=0;
	for my $i (0..Top_N)
	{
	printf (" %2d %-30s\t%5dK\t%d;%d;%d\n", $i+1, $RW_Top[$i], int($$RW_1_href{$RW_Top[$i]}/1024),
		$$RO_1_href{$RW_Top[$i]}, $$RW_1_href{$RW_Top[$i]}, $$ZI_1_href{$RW_Top[$i]} );
        $sum += $$RW_1_href{$RW_Top[$i]};
	}
	print "Top", Top_N, " Contribute ", $sum, "\tTotal:", $total_RW_1, "\t=", int(100*$sum/$total_RW_1), "%\n";
	print "*"x80 . "\n";
	my $sum=0;
	for my $i (0..Top_N)
	{
	printf (" %2d %-30s\t%5dK\t%d;%d;%d\n", $i+1, $ZI_Top[$i], int($$ZI_1_href{$ZI_Top[$i]}/1024),
		$$RO_1_href{$ZI_Top[$i]}, $$RW_1_href{$ZI_Top[$i]}, $$ZI_1_href{$ZI_Top[$i]} );
        $sum += $$ZI_1_href{$ZI_Top[$i]};
	}
	print "Top", Top_N, " Contribute ", $sum, "\tTotal:", $total_ZI_1, "\t=", int(100*$sum/$total_ZI_1), "%\n";
	print "*"x80 . "\n";
	
	printf ("Total RO = %d, RO+RW+RW+ZI = %9d\n",$total_RO_1, $total_RO_1+$total_ZI_1+$total_RW_1*2); 
	my $sum1=1+int(($total_RO_1+$total_RW_1)/(1024*1024));
	printf ("Estimate RAM Usage = ROM (RO+RW) %2dMB\n", $sum1);
	my $sum2=1+int(($total_ZI_1+ 64*1024*(1+int($total_RW_1/(64*1024))))/(1024*1024));

	printf ("                   +Data (RW+ZI) %2dMB\n", $sum2);
	printf ("                   =        SUM  %2dMB\n", $sum1+$sum2);
	print "*"x80 . "\n";

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
		
		if($file =~ /\.lis$/)
		{
			$nRO_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "RO Data") + &LinkerOutputParser::ListObjSummaryInfo($obj, "Code");
			$nRW_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "RW Data");
			$nZI_Size = &LinkerOutputParser::ListObjSummaryInfo($obj, "ZI Data");
			$RO_Size{$obj} = $nRO_Size;
			$RW_Size{$obj} = $nRW_Size;
		    $ZI_Size{$obj} = $nZI_Size;
		}
		elsif($file =~ /\.map$/)
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

usage: perl ListTopSizeObj.pl lis/map_file_path

lis/map_file_path: lis/map file path for codebase1 you want to compare

e.g. perl CompareobjrarySize.pl "E:\\mtk80506\\MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00\\MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00.map" "E:\\mtk80506\\MT6280_EVB_R7R8_PCB01_hspa_MT6280_S00.map"

Note: 
For GCC linker output, there should be corresponding .sym file in the same folder of .map file.

__EOFUSAGE
  exit 1;
}
