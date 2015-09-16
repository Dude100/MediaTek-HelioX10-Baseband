use strict;
BEGIN { push @INC, './tools/', './tools/MemoryUtility/', '../' }
use LinkerOutputParser;

&Usage() if ($#ARGV != 1); 

my ($file, $query_name) = @ARGV;
$file =~ s/\\/\\\\/;
&LinkerOutputParser::FileParse($file);

my ($ROSize, $RWSize, $ZISize) = (0,0,0);

if($file =~ /\.lis$/)
{
	if($query_name =~ /\.o/)
	{
		$ROSize = &LinkerOutputParser::ListObjSummaryInfo($query_name, "RO Data") + &LinkerOutputParser::ListObjSummaryInfo($query_name, "Code");
		$RWSize = &LinkerOutputParser::ListObjSummaryInfo($query_name, "RW Data");
		$ZISize = &LinkerOutputParser::ListObjSummaryInfo($query_name, "ZI Data");
	}
	elsif(($query_name =~ /\.l/) || ($query_name =~ /\.a/))
	{
		$ROSize = &LinkerOutputParser::ListLibSummaryInfo($query_name, "RO Data") + &LinkerOutputParser::ListLibSummaryInfo($query_name, "Code");
		$RWSize = &LinkerOutputParser::ListLibSummaryInfo($query_name, "RW Data");
		$ZISize = &LinkerOutputParser::ListLibSummaryInfo($query_name, "ZI Data");
	}
	else
	{
		&Usage();
	}
	print "RO Size: $ROSize\n";
	print "RW Size: $RWSize\n";
	print "ZI Size: $ZISize\n";
}
elsif($file =~ /\.map$/)
{
	if($query_name =~ /\.o/)
	{
		$ROSize = &LinkerOutputParser::ListObjSummaryInfo($query_name, "RO");
		$RWSize = &LinkerOutputParser::ListObjSummaryInfo($query_name, "RW");
		$ZISize = &LinkerOutputParser::ListObjSummaryInfo($query_name, "ZI");
	}
	elsif(($query_name =~ /\.l/) || ($query_name =~ /\.a/))
	{
		$ROSize = &LinkerOutputParser::ListLibSummaryInfo($query_name, "RO");
		$RWSize = &LinkerOutputParser::ListLibSummaryInfo($query_name, "RW");
		$ZISize = &LinkerOutputParser::ListLibSummaryInfo($query_name, "ZI");
	}
	else
	{
		&Usage();
	}
	print "RO Size: $ROSize\n";
	print "RW Size: $RWSize\n";
	print "ZI Size: $ZISize\n";
}
else
{
	&Usage();
}


sub Usage
{
  print <<"__EOFUSAGE";

usage: perl QuerySize.pl lis/map_file_path obj_name
       perl QuerySize.pl lis/map_file_path lib_name

lis/map_file_path: lis/map file path for codebase you want to query
obj_name/lib_name: object/library name with postfix (for example, bootloader.lib, lpwr.obj)

e.g. perl QuerySize.pl "E:\\mtk80506\\APOLLO55N_V2_DEMO_TDD128HSPA(CMCC_FTE_HVGA).W12.08\\mcu\\build\\APOLLO55N_V2_DEMO\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis" bootloader.lib
     perl QuerySize.pl "E:\\mtk80506\\APOLLO55N_V2_DEMO_TDD128HSPA(CMCC_FTE_HVGA).W12.08\\mcu\\build\\APOLLO55N_V2_DEMO\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis" lpwr.obj

__EOFUSAGE
  exit 1;
}