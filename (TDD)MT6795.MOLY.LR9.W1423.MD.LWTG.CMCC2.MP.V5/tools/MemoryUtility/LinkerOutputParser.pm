package LinkerOutputParser;
BEGIN { push @INC, './tools/', './tools/MemoryUtility/', '../' }
use Storable;
use LisFileParser;
use MapFileParser;
use SymFileParser;

my $strFilePath;
my $strFileType;

my $check_parse = undef;

return 1;

#****************************************************************************
# subroutine:  FileParse
#              Must be called first if you want to call other sub functions
# input:  LIS/MAP Path string     
# output: x  
#****************************************************************************
sub FileParse
{
	$check_parse = 1;
	($strFilePath) = @_;
	if ($strFilePath =~ /lis$/)
	{
		&LisFileParser::ParseLIS($strFilePath);
		$strFileType =~ s/lis//ig;
		$strFileType .= "LIS";
	}
	elsif ($strFilePath =~ /map$/)
	{
		&MapFileParser::ParseMAP($strFilePath);
		$strFileType =~ s/map//ig;
		$strFileType .= "MAP";
	}
	elsif ($strFilePath =~ /sym$/)
	{
		&SymFileParser::ParseSYM($strFilePath);
		$strFileType =~ s/sym//ig;
		$strFileType .= "SYM";
	}
}

#****************************************************************************
# subroutine:  StoreIntoTempFile
# input:       N/A
# output:      temp files which contain perl data structure
#              LisParser_Temp.dat
#              MapParser_Temp.dat
#              SymParser_Temp.dat
#              data is stored into hash in xxxParser_Temp.dat
#****************************************************************************
sub StoreIntoTempFile
{
	die "Must run &FileParse subroutine before run &StoreIntoTempFile\n" if (!defined $check_parse);
	my ($strPath) = @_; 
	if($strFileType =~ /LIS/i)
	{
		&LisFileParser::StoreIntoTempFile($strPath);
	}
	elsif ($strFileType =~ /MAP/i)
	{
		&MapFileParser::StoreIntoTempFile($strPath);
	}
	elsif ($strFileType =~ /SYM/i)
	{
		&SymFileParser::StoreIntoTempFile($strPath);
	}
}

#****************************************************************************
# subroutine:  GetParentOfSymbol
# input:       Symbol Name, $strOption (Case sensitive)
#                                     $strOption = "all" or "lib" or "obj"
# output:      For lis file, output is array reference, 
#                  array content:[sym1,sym2,...],symn refers to given symbol
#              For map file, output is array reference,
#                  $strOption = "all", array content:[array1,array2,...]
#                                    array1:[obj1,lib1]
#                  $strOption = "obj", array content:[obj1,obj2,...]
#                  $strOption = "lib", array content:[lib1,lib2,...]
#****************************************************************************
sub GetParentOfSymbol
{
	die "Must run &FileParse subroutine before run &GetParentOfSymbol\n" if (!defined $check_parse);
	my ($strSymbolName, $strOption) = @_;
	my $parent_aref;
	if($strFileType =~ /LIS/i)
	{
		$parent_aref = &LisFileParser::GetParentOfSymbol($strSymbolName);
	}
	elsif($strFileType =~ /MAP/i)
	{
		die "Option should be all/obj/lib\n" if (($strOption ne "all") && ($strOption ne "obj") && ($strOption ne "lib"));
		$parent_aref = &MapFileParser::GetParentOfSymbol($strSymbolName, $strOption);
	}
	return $parent_aref;
}

#****************************************************************************
# subroutine:  GetChildOfSymbol
# input:       Symbol Name (Case sensitive)
# output:      For lis file, output is array reference,
#                  array content:[sym1,sym2,...]
#              For map file, output is undef
#****************************************************************************
sub GetChildOfSymbol
{
	die "Must run &FileParse subroutine before run &GetChildOfSymbol\n" if (!defined $check_parse);
	my ($strSymbolName) = @_;
	my $child_aref;
	if($strFileType =~ /LIS/i)
	{
		$child_aref = &LisFileParser::GetChildOfSymbol($strSymbolName);
	}
	elsif($strFileType =~ /MAP/i)
	{
		$child_aref = &MapFileParser::GetChildOfSymbol($strSymbolName);
	}
	return $child_aref;
}

#****************************************************************************
# subroutine:  ListAllExeRegion
# input:       $bTrimDebugRegion: only useful for GCC. 
#              1= NeedtoTrimDebugRegion, 0 or undef=NoNeedToTrimDebugRegion
# output:      array reference
#              array content:[ExeRegionName1,ExeRegionName2,...] 
#****************************************************************************
sub ListAllExeRegion
{
	die "Must run &FileParse subroutine before run &ListAllExeRegion\n" if (!defined $check_parse);
	my ($bTrimDebugRegion) = @_;
	my $ExeRegion_aref;
	
	if($strFileType =~ /LIS/i)
	{
		$ExeRegion_aref = &LisFileParser::ListAllExeRegion;
	}
	elsif($strFileType =~ /SYM/i)
	{
		$ExeRegion_aref = &SymFileParser::ListAllExeRegion($bTrimDebugRegion);
	}
	return $ExeRegion_aref;
}

#****************************************************************************
# subroutine:  ListAllLoadRegion
# input:       N/A
# output:      for lis file, output array reference
#                  array content: [LoadRegionName1,LoadRegionName2,...]
#              for map file, output undef
#****************************************************************************
sub ListAllLoadRegion
{
	die "Must run &FileParse subroutine before run &ListAllLoadRegion\n" if (!defined $check_parse);
	my $LoadRegion_aref;
	if($strFileType =~ /LIS/i)
	{
		$LoadRegion_aref = &LisFileParser::ListAllLoadRegion;
	}
	elsif($strFileType =~ /MAP/i)
	{
		$LoadRegion_aref = &MapFileParser::ListAllLoadRegion;
	}
	return $LoadRegion_aref;
}

#****************************************************************************
# subroutine:  ListPadInfo
# input:       N/A
# output:      array reference
#              for lis file, array content:[pad_array1,pad_array2,...]
#                            pad_array1:[strPadBaseAddress,strPreSymName,strPreSymAddress,strPostSymName,strPostSymAddress]
#              for map file, array content:[pad_array1,pad_array2,...]
#                            pad_array1:[strPadBaseAddress,[strPreObjName,strPreLibName],strPreObjAddress,[strPostObjName,strPostLibName],strPostObjAddress]
#****************************************************************************
sub ListPadInfo
{
	die "Must run &FileParse subroutine before run &ListPadInfo\n" if (!defined $check_parse);
	my $pad_aref;
	if($strFileType =~ /LIS/i)
	{
		$pad_aref = &LisFileParser::ListPadInfo;
	}
	elsif($strFileType =~ /MAP/i)
	{
		$pad_aref = &MapFileParser::ListPadInfo;
	}
	return $pad_aref;
}

#****************************************************************************
# subroutine:  GetVeneerInfo
# input:       N/A
# output:      array reference, array content:[veneer_array1,veneer_arry2,...]
#              for lis file, 
#              veneer_array1 content:[strExeRegionName,strBaseAddress,strSize,strDestinationSym]
#              for map file, 
#              veneer_array1 content:[strExeRegionName,strBaseAddress,strSize]
#****************************************************************************
sub GetVeneerInfo
{
	die "Must run &FileParse subroutine before run &GetVeneerInfo\n" if (!defined $check_parse);
	my $veneer_aref;
	if($strFileType =~ /LIS/i)
	{
		$veneer_aref = &LisFileParser::GetVeneerInfo;
	}
	elsif($strFileType =~ /MAP/i)
	{
		$veneer_aref = &MapFileParser::GetVeneerInfo;
	}
	return $veneer_aref;
}

#****************************************************************************
# subroutine:  GetObjSizeByExeRegion
# input:       ExeRegion Name, Object Name, Library Name(Case sensitive)
#                              Object Name should contain ".obj"
#                              Library Name should contain ".lib"
# output:      size of object in given execution region
#****************************************************************************
sub GetObjSizeByExeRegion
{
	die "Must run &FileParse subroutine before run &GetObjSizeByExeRegion\n" if (!defined $check_parse);
	my ($strExeRegionName, $strObjName, $strLibName) = @_;
	die "Object name must contain .obj/.o postfix\n" if ($strObjName !~ /\.o|\*fill\*|stub/);
	die "Library name must contain .lib/.a postfix\n" if (($strLibName !~ /\.l|\.a|\*fill\*|\*stub\*/));
	my $n_size;
	if($strFileType =~ /LIS/i)
	{
		my $nObjTotalSize_ref = &LisFileParser::GetObjTotalSizesByExeRegion($strExeRegionName);
		my $string = $strObjName."::".$strLibName;
		$n_size = $$nObjTotalSize_ref{$string};
	}
	elsif($strFileType =~ /MAP/i)
	{
		$n_size = &MapFileParser::GetObjSizeByExeRegion($strExeRegionName, $strObjName, $strLibName);
	}
	return $n_size;
}

#****************************************************************************
# subroutine:  GetObjSizeByCatExeRegion
# input:       ExeRegion Name, Object Name, $strCategory(Case sensitive)
#                              Object Name should contain ".obj"
#                              $strCategory: RO Data/RW Data/ZI Data/Code for lis
#                                            RO/RW/ZI for map
# output:      RO/RW/ZI/RWZI size of object in given execution region
#****************************************************************************
sub GetObjSizeByCatExeRegion
{
	die "Must run &FileParse subroutine before run &GetObjSizeByExeRegion\n" if (!defined $check_parse);
	my ($strExeRegionName, $strObjName, $strCategory) = @_;
	my $n_size = 0;
	die "Object name must contain .obj/.o postfix\n" if ($strObjName !~ /\.o|\*fill\*|stub/);
	if($strFileType =~ /LIS/i)
	{
	    die "Category should be RO Data/RW Data/ZI Data/RWZI Data/Code\n" 
	        if (($strCategory ne "RO Data") && ($strCategory ne "RW Data") && ($strCategory ne "ZI Data") && ($strCategory ne "Code"));
		my $nObjCateSize_ref = &LisFileParser::GetObjSizeByCatExeRegion($strExeRegionName, $strCategory);
		$n_size = $$nObjCateSize_ref{$strObjName};
	}
	elsif($strFileType =~ /MAP/i)
	{
	    die "Category should be RO/RW/ZI\n"
	        if (($strCategory ne "RO") && ($strCategory ne "RW") && ($strCategory ne "ZI"));
		my $nObjCateSize_ref = &MapFileParser::GetObjSizeByCatExeRegion($strExeRegionName, $strCategory);
		$n_size = $$nObjCateSize_ref{$strObjName};
	}
	return $n_size;
}

#****************************************************************************
# subroutine:  GetLibSizeByExeRegion
# input:       Execution Region Name, Library Name (Case sensitive)
#                                     Library Name should contain ".lib"
# output:      size of given library in givin execution region
#****************************************************************************
sub GetLibSizeByExeRegion
{
	die "Must run &FileParse subroutine before run &GetLibSizeByExeRegion\n" if (!defined $check_parse);
	my ($strExeRegionName, $strLibName) = @_;
	die "Library name must contain .lib/.a postfix\n" if (($strLibName !~ /\.l|\.a|\*fill\*|\*stub\*/));
	my $n_size;
	if($strFileType =~ /LIS/i)
	{
		$n_size = &LisFileParser::GetLibSizeByExeRegion($strExeRegionName, $strLibName);
	}
	elsif($strFileType =~ /MAP/i)
	{
		$n_size = &MapFileParser::GetLibSizeByExeRegion($strExeRegionName, $strLibName);
	}
	return $n_size;
}

#****************************************************************************
# subroutine:  GetObjByExeRegion
# input:       Execution Region Name (Case sensitive)
# output:      array reference which given execution region contains
#              array content:[strObjName1,strObjName2,...]
#****************************************************************************
sub GetObjByExeRegion
{
	die "Must run &FileParse subroutine before run &GetObjByExeRegion\n" if (!defined $check_parse);
	my ($strExeRegionName) = @_;
	my $obj_aref;
	if($strFileType =~ /LIS/i)
	{
		$obj_aref = &LisFileParser::GetObjByExeRegion($strExeRegionName);
	}
	elsif($strFileType =~ /MAP/i)
	{
		$obj_aref = &MapFileParser::GetObjByExeRegion($strExeRegionName);
	}
	return $obj_aref;
}

#****************************************************************************
# subroutine:  GetLibByExeRegion
# input:       Execution Region Name (Case sensitive)
# output:      array reference which given execution region contains
#              array content:[strLibName1,strLibName2,...]
#****************************************************************************
sub GetLibByExeRegion
{
	die "Must run &FileParse subroutine before run &GetLibByExeRegion\n" if (!defined $check_parse);
	my ($strExeRegionName) = @_;
	my $lib_aref;
	if($strFileType =~ /LIS/i)
	{
		$lib_aref = &LisFileParser::GetLibByExeRegion($strExeRegionName);
	}
	elsif($strFileType =~ /MAP/i)
	{
		$lib_aref = &MapFileParser::GetLibByExeRegion($strExeRegionName);
	}
	return $lib_aref;
}

#****************************************************************************
# subroutine:  ListObjSummaryInfo
# input:       obj name, strOption represents which column to show(Case sensitive)
#              OBJ name should contain ".obj"
#                        strOption = "Code"
#                                  = "inc.data"
#                                  = "RO Data"
#                                  = "RW Data"
#                                  = "ZI Data"
#                                  = "Debug"
# output:      for lis file, output corresponding Code/inc.data/RO Data/RW Data/ZI Data/Debug size for given obj
#              for map file, output undef
#****************************************************************************
sub ListObjSummaryInfo
{
	die "Must run &FileParse subroutine before run &ListObjSummaryInfo\n" if (!defined $check_parse);
	my ($strObjName, $strOption) = @_;
	die "Object name must contain .obj/.o postfix\n" if ($strObjName !~ /\.o|\*fill\*|stub/);
	my $n_size;
	if($strFileType =~ /LIS/i)
	{
	    die "Input should be Code/inc.data/RO Data/RW Data/ZI Data/Debug\n" if (($strOption ne "Code") && ($strOption ne "inc.data") && ($strOption ne "RO Data") && ($strOption ne "RW Data") && ($strOption ne "ZI Data") && ($strOption ne "Debug"));
		$n_size = &LisFileParser::ListObjSummaryInfo($strObjName, $strOption);
	}
	elsif($strFileType =~ /MAP/i)
	{
	    die "Input should be RO/RW/ZI/Debug\n" if (($strOption ne "RO") && ($strOption ne "RW") && ($strOption ne "ZI") && ($strOption ne "Debug"));
		$n_size = &MapFileParser::ListObjSummaryInfo($strObjName, $strOption);
	}
	$n_size = 0 if(!defined $n_size or $n_size eq "");
	return $n_size;
}

#****************************************************************************
# subroutine:  ListLibSummaryInfo
# input:       lib name, strOption represents which column to show(Case sensitive)
#              Lib name should contain ".lib"
#                        strOption = "Code"
#                                = "inc.data"
#                                = "RO Data"
#                                = "RW Data"
#                                = "ZI Data"
#                                = "Debug"
# output:      for lis file, output corresponding Code/inc.data/RO Data/RW Data/ZI Data/Debug size for given lib
#              for map file, output undef
#****************************************************************************
sub ListLibSummaryInfo
{
	die "Must run &FileParse subroutine before run &ListLibSummaryInfo\n" if (!defined $check_parse);
	my ($strLibName, $strOption) = @_;
	die "Library name must contain .lib/.a postfix\n" if (($strLibName !~ /\.l|\.a|\*fill\*|\*stub\*/));
	my $n_size = 0;
	if($strFileType =~ /LIS/i)
	{
	    die "Input should be Code/inc.data/RO Data/RW Data/ZI Data/Debug\n" if (($strOption ne "Code") && ($strOption ne "inc.data") && ($strOption ne "RO Data") && ($strOption ne "RW Data") && ($strOption ne "ZI Data") && ($strOption ne "RWZI Data") && ($strOption ne "Debug"));
		$n_size = &LisFileParser::ListLibSummaryInfo($strLibName, $strOption);
	}
	elsif($strFileType =~ /MAP/i)
	{
	    die "Input should be RO/RW/ZI/Debug\n" if (($strOption ne "RO") && ($strOption ne "RW") && ($strOption ne "ZI") && ($strOption ne "Debug"));
		$n_size = &MapFileParser::ListLibSummaryInfo($strLibName, $strOption);
	}
	$n_size = 0 if(!defined $n_size or $n_size eq "");
	return $n_size;
}

#****************************************************************************
# subroutine:  GetTotalSizeByExeRegion
# input:       $strRegionName: Execution Region Name (Case sensitive)
# output:      total size for given execution region
#****************************************************************************
sub GetTotalSizeByExeRegion
{
	die "Must run &FileParse subroutine before run &GetTotalSizeByExeRegion\n" if (!defined $check_parse);
	my ($strExeRegionName) = @_;
	my $n_size;
	if($strFileType =~ /LIS/i)
	{
		$n_size = &LisFileParser::GetTotalSizeByExeRegion($strExeRegionName);
	}
	elsif($strFileType =~ /SYM/i)
	{
		$n_size = hex(&SymFileParser::GetExeRegionInfo($strExeRegionName, Region::Size));
	}
	return $n_size;
}

#****************************************************************************
# subroutine:  GetTotalSizeByLib
# input:       $strLibName: Library Name (Case sensitive)
#                           Library Name should contain ".lib"
# output:      total size for given library
#****************************************************************************
sub GetTotalSizeByLib
{
	die "Must run &FileParse subroutine before run &GetTotalSizeByLib\n" if (!defined $check_parse);
	my ($strLibName) = @_;
	die "Library name must contain .lib/.a postfix\n" if (($strLibName !~ /\.l|\.a|\*fill\*|\*stub\*/));
	my $n_size;
	if($strFileType =~ /LIS/i)
	{
		$n_size = &LisFileParser::GetTotalSizeByLib($strLibName);
	}
	elsif($strFileType =~ /MAP/i)
	{
		$n_size = &MapFileParser::GetTotalSizeByLib($strLibName);
	}
	return $n_size;
}

#****************************************************************************
# subroutine:  GetTotalSizeByObj
# input:       $strObjName: Obj Name, $strLibName: Library Name (Case sensitive)
#                           Object Name should contain ".obj"
#                           Library Name should contain ".lib"
# output:      total size for given (obj, library)
#****************************************************************************
sub GetTotalSizeByObj
{
	die "Must run &FileParse subroutine before run &GetTotalSizeByObj\n" if (!defined $check_parse);
	my ($strObjName, $strLibName) = @_;
	die "Object name must contain .obj/.o postfix\n" if ($strObjName !~ /\.o|\*fill\*|stub/);
	die "Library name must contain .lib/.a postfix\n" if (($strLibName !~ /\.l|\.a|\*fill\*|\*stub\*/));
	my $n_size;
	if($strFileType =~ /LIS/i)
	{
		$n_size = &LisFileParser::GetTotalSizeByObj($strObjName, $strLibName);
	}
	elsif($strFileType =~ /MAP/i)
	{
		$n_size = &MapFileParser::GetTotalSizeByObj($strObjName, $strLibName);
	}
	return $n_size;
}

#****************************************************************************
# subroutine:  ListObjLibBySymbol
# input:       $strSymName: Symbol Name (Case sensitive)
# output:      for lis file, output array reference
#                            array content:[[strObjName1,strLibName1],[strObjName2,strLibName2],...]
#              for map file, output undef
#****************************************************************************
sub ListObjLibBySymbol
{
	die "Must run &FileParse subroutine before run &ListObjLibBySymbol\n" if (!defined $check_parse);
	my ($strSymName) = @_;
	my $obj_lib_aref;
	if($strFileType =~ /LIS/i)
	{
		$obj_lib_aref = &LisFileParser::ListObjLibBySymbol($strSymName);
	}
	elsif($strFileType =~ /MAP/i)
	{
		$obj_lib_aref = &MapFileParser::ListObjLibBySymbol($strSymName);
	}
	return $obj_lib_aref;
}

#****************************************************************************
# subroutine:  ListObjByLib
# input:       $strLibName: Library Name (Case sensitive)
#                           Library Name should contain ".lib"
# output:      obj array reference associated with given library
#              array content:[strObjName1,strObjName2,...]
#****************************************************************************
sub ListObjByLib
{
	die "Must run &FileParse subroutine before run &ListObjByLib\n" if (!defined $check_parse);
	my ($strLibName) = @_;
	die "Library name must contain .lib/.a postfix\n" if (($strLibName !~ /\.l|\.a|\*fill\*|\*stub\*/));
	my $obj_aref;
	if($strFileType =~ /LIS/i)
	{
		$obj_aref = &LisFileParser::ListObjByLib($strLibName);
	}
	elsif($strFileType =~ /MAP/i)
	{
		$obj_aref = &MapFileParser::ListObjByLib($strLibName);
	}
	return $obj_aref;
}

#****************************************************************************
# subroutine:  ListLibByObj
# input:       $ObjName: Object Name (Case sensitive)
#                        Object Name should contain ".obj"
# output:      Library array reference associated with given object
#              array content:[strLibName1,strLibName2,...]
#****************************************************************************
sub ListLibByObj
{
	die "Must run &FileParse subroutine before run &ListLibByObj\n" if (!defined $check_parse);
	my ($strObjName) = @_;
	die "Object name must contain .obj/.o postfix\n" if ($strObjName !~ /\.o|\*fill\*|stub/);
	my $lib_aref;
	if($strFileType =~ /LIS/i)
	{
		$lib_aref = &LisFileParser::ListLibByObj($strObjName);
	}
	elsif($strFileType =~ /MAP/i)
	{
		$lib_aref = &MapFileParser::ListLibByObj($strObjName);
	}	
	return $lib_aref;
}

#****************************************************************************
# subroutine:  GetObjDebugInfoSize
# input:       $strObjName: Obj Name (Case sensitive)
#                           Object Name should contain ".obj"
# output:      debug info size for given obj
#****************************************************************************
sub GetObjDebugInfoSize
{
	die "Must run &FileParse subroutine before run &GetObjDebugInfoSize\n" if (!defined $check_parse);
	my ($strObjName) = @_;
	die "Object name must contain .obj/.o postfix\n" if ($strObjName !~ /\.o|\*fill\*|stub/);
	my $n_debugsize;
    if($strFileType =~ /LIS/i)
	{
		$n_debugsize = &LisFileParser::GetObjDebugInfoSize($strObjName);
	}
	elsif($strFileType =~ /MAP/i)
	{
		$n_debugsize = &MapFileParser::GetObjDebugInfoSize($strObjName);
	}
	return $n_debugsize;
}

#****************************************************************************
# subroutine:  FootprintAnalyzeBySymbol
# input:       $strSymName: Symbol Name, $strObjName: Obj Name (Case sensitive)
#                           Object Name should contain ".obj" (Not necessary input for GCC SYM file)
# output:      symbol info array reference
#              for non Ven/Pad symbol in lis file,[strExeRegionName,strAttr,strBaseAddress,strSize]
#              for Ven symbol in lis file,[strExeRegionName,strAttr,strBaseAddress,strSize,strDestinationSymbol]
#              for symbol in sym file,[strExeRegionName,strAttr,strBaseAddress,strSize]
#****************************************************************************
sub FootprintAnalyzeBySymbol
{
	die "Must run &FileParse subroutine before run &FootprintAnalyzeBySymbol\n" if (!defined $check_parse);
	my ($strSymName, $strObjName) = @_;
	my $SymbolInfo_ref;
	if($strFileType =~ /LIS/i)
	{
		die "Object name must contain .obj/.o postfix\n" if ($strObjName !~ /\.o/);
		$SymbolInfo_ref = &LisFileParser::FootprintAnalyzeBySymbol($strSymName, $strObjName);
	}
	elsif($strFileType =~ /SYM/i)
	{
		$SymbolInfo_ref = &SymFileParser::FootprintAnalyzeBySymbol($strSymName);
	}
	return $SymbolInfo_ref;
}
#****************************************************************************
# subroutine:  GetSymbolTable
# input:       N/A
# output:      symbol info hash reference in the following format:
#              $strAddress.$strSymbolName => [strSymbol, $strAddress, strGroup, strRegion, nSize]
#****************************************************************************
sub GetSymbolTable
{
	die "Must run &FileParse subroutine before run &FootprintAnalyzeBySymbol\n" if (!defined $check_parse);
	my $SymbolInfo_href;
	if($strFileType =~ /SYM/i)
	{
		$SymbolInfo_href = &SymFileParser::GetSymbolTable();
	}
	return $SymbolInfo_href;
}

#****************************************************************************
# subroutine:  GrepSymbolBySection
# input:       $strSectionName
# output:      symbol info array reference in order of address in the following format:
#              [[strSymbol, $strAddress, strGroup, strRegion, nSize], ...]
#****************************************************************************
sub GrepSymbolBySection
{
	die "Must run &FileParse subroutine before run &FootprintAnalyzeBySymbol\n" if (!defined $check_parse);
	my ($strSectionName) = @_;
	my $SymbolInfo_aref;
	if($strFileType =~ /SYM/i)
	{
		$SymbolInfo_aref = &SymFileParser::GrepSymbolBySection($strSectionName);
	}
    return $SymbolInfo_aref;
}

#****************************************************************************
# subroutine:  GetLinkerSymbolAddress
# input:       nRegionType = 0: Execution Region
#              nRegionType = 1: Load Region
#              nRegionType = 2: Input Section
#              nLocation: Base       => 0;
#                         Limit      => 1;
#                         ZIBase     => 2;
#                         ZILimit    => 3;
#                         Length     => 4;
# output:      address in string
#****************************************************************************
sub GetLinkerSymbolAddress
{
	die "Must run &FileParse subroutine before run &FootprintAnalyzeBySymbol\n" if (!defined $check_parse);
	my ($strRegionName, $nLocation, $nRegionType) = @_;
	my $strAddr;
	if($strFileType =~ /SYM/i)
	{
		$strAddr = &SymFileParser::GetLinkerSymbolAddress($strRegionName, $nLocation, $nRegionType);
	}
    return $strAddr;
}

#****************************************************************************
# subroutine:  Get_DUMMY_END_Size
# input:       N/A
# output:      size of DUMMY_END region
#****************************************************************************
sub Get_DUMMY_END_Size
{
	my $DUMMY_END_size;
	if($strFileType =~ /LIS/i)
	{
		$DUMMY_END_size = undef;
	}
	elsif($strFileType =~ /SYM/i)
	{
		$DUMMY_END_size = &SymFileParser::Get_DUMMY_END_Size;
	}
	return $DUMMY_END_size;
}

#****************************************************************************
# subroutine:  Get_DUMMY_END_Base
# input:       N/A
# output:      base address of DUMMY_END region
#****************************************************************************
sub Get_DUMMY_END_Base
{
	my $DUMMY_END_base;
	if($strFileType =~ /LIS/i)
	{
		$DUMMY_END_base = undef;
	}
	elsif($strFileType =~ /SYM/i)
	{
		$DUMMY_END_base = &SymFileParser::Get_DUMMY_END_Base;
	}
	return $DUMMY_END_base;
}

#****************************************************************************
# subroutine:  GetExeRegionInfo - Get Execution Region information
# input:       $strRegionName: Execution Name (Case sensitive)
#              $nOption for LIS file: ExecutionRegion::Base
#                                    ExecutionRegion::Size
#                                    ExecutionRegion::MaxSize
#                                    ExecutionRegion::Attr
#              $nOption for MAP file: Region::VMA
#                                    Region::LMA
#                                    Region::Size 
#                                    Region::Offsets
#                                    Region::Align
#                                    Region::Attr
# output:      required ExeRegion Base address, Used Size, Region MaxSize, Attribute info...
#****************************************************************************
sub GetExeRegionInfo
{
	die "Must run &FileParse subroutine before run &GetExeRegionInfo\n" if (!defined $check_parse);
	my ($strRegionName, $nOption) = @_;
	my $strInfo;
	if($strFileType =~ /LIS/i)
	{
		die "Option should be ExecutionRegion::Base/ExecutionRegion::Size/ExecutionRegion::MaxSize/ExecutionRegion::Attr\n" if (($nOption ne ExecutionRegion::Base) && ($nOption ne ExecutionRegion::Size) && ($nOption ne ExecutionRegion::MaxSize) && ($nOption ne ExecutionRegion::Attr));
		$strInfo = &LisFileParser::GetExeRegionInfo($strRegionName, $nOption);
	}
	elsif($strFileType =~ /SYM/i)
	{
		die "Option should be Region::VMA/Region::LMA/Region::Size/Region::Offsets/Region::Align/Region::Attr\n" if (($nOption ne Region::VMA) && ($nOption ne Region::LMA) && ($nOption ne Region::Size) && ($nOption ne Region::Offsets) && ($nOption ne Region::Align) && ($nOption ne Region::Attr));
		$strInfo = &SymFileParser::GetExeRegionInfo($strRegionName, $nOption);
	}
	return $strInfo;
}

#****************************************************************************
# subroutine:  GetLoadRegionInfo - Get Load Region information
#              $nOption for LIS file: LoadRegion::Base
#                                     LoadRegion::Size
#                                     LoadRegion::MaxSize
#                                     LoadRegion::Attr
# output:      required LoadRegion Base address, Used Size, Region MaxSize, Attribute info
#****************************************************************************
sub GetLoadRegionInfo
{
	die "Must run &FileParse subroutine before run &GetLoadRegionInfo\n" if (!defined $check_parse);
	my ($strRegionName, $nOption) = @_;
	my $strInfo;
	if($strFileType =~ /LIS/i)
	{	
		die "Option should be LoadRegion::Base/LoadRegion::Size/LoadRegion::MaxSize/LoadRegion::Attr\n" if (($nOption ne LoadRegion::Base) && ($nOption ne LoadRegion::Size) && ($nOption ne LoadRegion::MaxSize) && ($nOption ne LoadRegion::Attr));
		$strInfo = &LisFileParser::GetLoadRegionInfo($strRegionName, $nOption);
	}
	elsif($strFileType =~ /MAP/i)
	{
		$strInfo = &MapFileParser::GetLoadRegionInfo;
	}
	return $strInfo;
}

#****************************************************************************
# subroutine:  GetTotalROSize - Get total RO size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $bNeedString=0:nROSize/ $bNeedString=1:strROSize
#****************************************************************************
sub GetTotalROSize
{
	die "Must run &FileParse subroutine before run &GetTotalROSize\n" if (!defined $check_parse);
	my ($bNeedString) = @_;
	my $n_size;
	if($strFileType =~ /LIS/i)
	{
		$n_size = &LisFileParser::GetTotalROSize($bNeedString);
	}
	elsif($strFileType =~ /MAP/i)
	{
		$n_size = &MapFileParser::GetTotalROSize($bNeedString);
	}
	return $n_size;
}

#****************************************************************************
# subroutine:  GetTotalRWZISize - Get total RWZI size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $bNeedString=0:nRWZISize/ $bNeedString=1:strRWZISize
#****************************************************************************
sub GetTotalRWZISize
{
	die "Must run &FileParse subroutine before run &GetTotalRWZISize\n" if (!defined $check_parse);
	my ($bNeedString) = @_;
	my $n_size;
	if($strFileType =~ /LIS/i)
	{
		$n_size = &LisFileParser::GetTotalRWZISize($bNeedString);
	}
	elsif($strFileType =~ /MAP/i)
	{
		$n_size = &MapFileParser::GetTotalRWZISize($bNeedString);
	}
	return $n_size;
}

#****************************************************************************
# subroutine:  GetTotalROMSize - Get total ROM size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $bNeedString=0:nROMSize/ $bNeedString=1:strROMSize
#****************************************************************************
sub GetTotalROMSize
{
	die "Must run &FileParse subroutine before run &GetTotalROMSize\n" if (!defined $check_parse);
	my ($bNeedString) = @_;
	my $n_size;
	if($strFileType =~ /LIS/i)
	{
		$n_size = &LisFileParser::GetTotalROMSize($bNeedString);
	}
	elsif($strFileType =~ /MAP/i)
	{
		$n_size = &MapFileParser::GetTotalROMSize($bNeedString);
	}
	return $n_size;
}

#****************************************************************************
# subroutine:  PadFillExeregSize -- search *fill* padding info for RO and RWZI in INTSRAM region
# input:       execution region name, memory type
# output:      memory size
#****************************************************************************
sub PadFillExeregSize
{
	my ($exeregion, $type)= @_;
	my $size;
	$size = &MapFileParser::PadFillExeregSize($exeregion, $type);
	return $size;
}

__END__

=head1 NAME

LinkerOutputParser - Perl module to parse linker output files: .lis/.map/.sym

=head1 SYNOPSIS

    use LinkerOutputParser;

=head2 Table of Contents

LinkerOutputParser consists of a collection of modules whose details 
are too big to fit in one document.  This POD itself explains the 
top-level APIs and general topics at a glance.  For other topics and 
more details, see the PODs below:

  Name			        Description
  --------------------------------------------------------
  LisFileParser         Parser module for .lis file
  MapFileParser         Parser module for .map file
  SymFileParser         Parser module for .sym file
  --------------------------------------------------------

=head1 DESCRIPTION

The module provides the interfaces to parse RVCT/GCC linker output files.

=head1 EXAMPLES

Here are some code samples showing a possible usage of LinkerOutputParser:

1. How do I get all execution region list from .lis/.sym file?	

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $exeregion_aref = &LinkerOutputParser::ListAllExeRegion;
	if (defined $exeregion_aref)
	{
		foreach my $temp(@$exeregion_aref)
		{
			print "$temp\n";
		}
	}

which prints (on my machine):

	BL_GFH_SECTION
	READ_ONLY
	READ_ONLY_HEAD
	READ_ONLY_TAIL
	READ_WRITE
	READ_ONLY_INT
	READ_WRITE_INT
	EMIINIT_CODE
	STACK_AREA
	EXT_UN_INIT
	SHARE_BUF
	READ_WRITE_SYS_RAM
	DUMMY_END
	BL_SIGNATURE_SECTION

2. How do I get al load region list from .lis file?

    use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $loadregion_aref = &LinkerOutputParser::ListAllLoadRegion;
	if (defined $loadregion_aref)
	{
		foreach my $temp(@$loadregion_aref)
		{
			print "$temp\n";
		}
	}

which prints (on my machine):

	READ_ONLY

3. How do I get base address/size/maxsize/attribute of an execution region?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $base_address = &LinkerOutputParser::GetExeRegionInfo('BL_GFH_SECTION', ExecutionRegion::Base);
	print "$base_address\n";

	my $size = &LinkerOutputParser::GetExeRegionInfo('BL_GFH_SECTION', ExecutionRegion::Size);
	print "$size\n";

which prints (on my machine):

	0x40000900
	0x150
	
4. How do I get base address/size/maxsize/attribute of an load region?
	
	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $base_address = &LinkerOutputParser::GetLoadRegionInfo('READ_ONLY', LoadRegion::Base);
	print "$base_address\n";

	my $size = &LinkerOutputParser::GetLoadRegionInfo('READ_ONLY', LoadRegion::Size);
	print "$size\n";

which prints (on my machine):

	0x40000900
	0x4114
	
5. How do I get all objects in an execution region?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $obj_aref = &LinkerOutputParser::GetObjByExeRegion("BL_GFH_SECTION");
	if (defined $obj_aref)
	{
		foreach my $temp(@$obj_aref)
		{
			print "$temp\n";
		}
	}

which prints (on my machine):

	bl_GFH_body.obj
	custom_emi_MT6255.obj
	bl_Secure_v5.obj

6. How do I get all libraries in an execution region?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $lib_aref = &LinkerOutputParser::GetLibByExeRegion("READ_ONLY_TAIL");
	if (defined $lib_aref)
	{
		foreach my $temp(@$lib_aref)
		{
			print "$temp\n";
		}
	}

which prints (on my machine):

	bootloader.lib
	sss_rvct_sv5.lib
	c_5.l
	h_5.l
	f_5s.l
	sst_sec.lib
	
7. How do I get object, library associated with a symbol?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $objlib_aref = &LinkerOutputParser::ListObjLibBySymbol(".text");
	foreach my $temp(@$objlib_aref)
	{
		print "$temp->[0], $temp->[1]\n";
	}

which prints (on my machine):

	strcpy.o, c_5.l
	_fptrap.o, c_5.l
	defsig_fpe_outer.o, c_5.l
	defsig_exit.o, c_5.l
	defsig_fpe_inner.o, c_5.l
	defsig_general.o, c_5.l
	sys_wrch.o, c_5.l
	rt_memcpy_w.o, c_5.l
	rt_memclr_w.o, c_5.l
	llmullu.o, h_5.l
	rt_memmove_w.o, c_5.l
	llmul.o, c_5.l
	rt_fp_status_addr.o, c_5.l
	sys_exit.o, c_5.l
	use_no_semi.o, c_5.l
	
8. How do I get all objects in a library?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $obj_aref = &LinkerOutputParser::ListObjByLib("sst_sec.lib");
	if(defined $obj_aref)
	{
		foreach my $temp(@$obj_aref)
		{
			print "$temp\n";
		}
	}

which prints (on my machine):

	SSS_interface.obj
	br_crypto_platform.obj
	
9. How do I get all libraries associated with an object?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $lib_aref = &LinkerOutputParser::ListLibByObj("lpwr.obj");
	if(defined $lib_aref)
	{
		foreach my $temp(@$lib_aref)
		{
			print "$temp\n";
		}
	}

which prints (on my machine):

	bootloader.lib
	
10. How do I get execution region total size?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $exeregion_size = &LinkerOutputParser::GetTotalSizeByExeRegion("BL_GFH_SECTION");  
	print "$exeregion_size\n";

which prints (on my machine):

	336
	
11. How do I get total size of a library?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $lib_size = &LinkerOutputParser::GetTotalSizeByLib("f_5s.l");  
	print "$lib_size\n";

which prints (on my machine):

	1320
	
12. How do I get total size of an object?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities

	my $obj_size = &LinkerOutputParser::GetTotalSizeByObj("bl_BOOTARM.obj","bootloader.lib");  
	print "$obj_size\n";
	
which prints (on my machine):

	4304
	
13. How do I get size of an object in a certain execution region?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $obj_size = &LinkerOutputParser::GetObjSizeByExeRegion("READ_ONLY_TAIL", "bl_FTL.obj", "bootloader.lib"); 
	print "$obj_size\n";
	
which prints (on my machine):

	256

14. How do I get size of a library in a certain execution region?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $lib_size = &LinkerOutputParser::GetLibSizeByExeRegion("BL_GFH_SECTION", "bootloader.lib");  ##300
	print "$lib_size\n";
	
which prints (on my machine):

	288

15. How do I get total RO size for a .lis file?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $ROSize = &LinkerOutputParser::GetTotalROSize;
	print "Total ROSize is $ROSize\n";
	
which prints (on my machine):

	Total ROSize is 16452
	
16. How do I get total RWZI size for a .lis file?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $RWZISize = &LinkerOutputParser::GetTotalRWZISize;
	print "Total RWZISize is $RWZISize\n";
	
which prints (on my machine):

	Total RWZISize is 52864
	
17. How do I get total ROM size for a .lis file?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $ROMSize = &LinkerOutputParser::GetTotalROMSize;
	print "Total ROMSize is $ROMSize\n";
	
which prints (on my machine):

	Total ROMSize is 16660
	
18. How do I get debug info size for an object?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $debug_size = &LinkerOutputParser::GetObjDebugInfoSize('SSS_Secure_v5.obj');
	print "$debug_size\n";
	
which prints (on my machine):

	4683
	
19. How do I get footprint infomation of a symbol?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $footprint_info_ref = &LinkerOutputParser::FootprintAnalyzeBySymbol("i.CacheInitMini", "bl_Cache.obj");
	foreach my $temp(@$footprint_info_ref)  ### array content: [ExecutionRegionName, Attribute, BaseAddress, Size] for common symbols
	{                                       ### array content: [ExecutionRegionName, Attribute, BaseAddress, Size, DestinationSymbol] for veneers
		print "$temp\n";
	}
	print "\n";
	
which prints (on my machine):

	READ_ONLY_TAIL
	RO-Code
	0x40000b8c
	0x0000000c
	
20. How do I get parent symbols which refer to certain symbol?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $parent_aref = &LinkerOutputParser::GetParentOfSymbol("NFIDriverInit");
	if(defined $parent_aref)
	{
		foreach my $temp(@$parent_aref)
		{
			print "$temp\n";
		}
	}
	
which prints (on my machine):

	Init
	
21. How do I get child symbols which certain symbol refers to?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $child_aref = &LinkerOutputParser::GetChildOfSymbol("itoa");
	if(defined $child_aref)
	{
		foreach my $temp(@$child_aref)
		{
			print "$temp\n";
		}
	}
	
which prints (on my machine):

	__aeabi_idivmod
	.bss
	
22. How do I know pad infomation?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $pad_aref = &LinkerOutputParser::ListPadInfo;
	if (defined $pad_aref)               
	{
		foreach my $temp(@$pad_aref)
		{
			print "$temp->[0], $temp->[1], $temp->[2], $temp->[3], $temp->[4]\n";
			### array content: [pad_address, previous_symbol_name, previous_symbol_address, post_symbol_name, post_symbol_address]
		}
	}

which prints (on my machine):

	0x40004075, x$divrt, 0x40003e80, x$fpl$dcmpinfnan, 0x40004078
	0x40004545, .constdata, 0x40004544, .constdata, 0x40004548
	0x40004652, .constdata, 0x40004548, .constdata, 0x40004654
	0x4000471a, .constdata, 0x40004654, .constdata, 0x4000471c
	0x40004822, .constdata, 0x4000471c, .constdata, 0x40004824
	0x40004b97, .bss, 0x4000496c, .bss, 0x40004b98
	0x40004bed, .bss, 0x40004bec, .bss, 0x40004bf0
	0x50000076, INTERNCODE, 0x50000068, INTERNCODE, 0x50000078
	0x40000e9e, i.TimeStampInit, 0x40000e9c, i.VerifyExtBootloader, 0x40000ea0
	0x40000ef2, EMIINITCODE, 0x40000eea, EMIINITCODE, 0x40000ef4
	0x40001cbe, i.GFH_Find, 0x40001cac, i.GFH_Internal_Parser, 0x40001cc0
	0x40003302, i.dbg_print, 0x400032ec, i.lpwr_default_callback, 0x40003304

23. How do I know veneer infomation?	

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $veneer_aref = &LinkerOutputParser::GetVeneerInfo;
	if(defined $veneer_aref)
	{
		foreach my $temp(@$veneer_aref)
		{
			print "$temp->[0], $temp->[1], $temp->[2], $temp->[3]\n";
			### array content: [ExecutionRegionName, BaseAddress, Size, DestinationSymbolName]
		}
	}

which prints (on my machine):

	READ_ONLY_TAIL, 0x40000c84, 0x00000008, JumpToExtBootloader
	READ_ONLY_TAIL, 0x40002808, 0x00000008, CP_Crypto_Init
	READ_ONLY_TAIL, 0x40002810, 0x00000008, CP_Get_MTK_Cipher_Key_Len
	READ_ONLY_TAIL, 0x40002818, 0x00000008, SaveAndSetIRQMask
	READ_ONLY_TAIL, 0x40002820, 0x00000008, RestoreIRQMask
	READ_ONLY_TAIL, 0x40002828, 0x00000008, JumpCmd
	READ_ONLY_INT, 0x5000004c, 0x00000008, SSS_Crypto_Config_Init
	READ_ONLY_INT, 0x50000054, 0x00000008, SSS_Crypto_Context_Validation
	READ_ONLY_INT, 0x5000005c, 0x00000008, ASSERT

24. What if I want to know Code/RO/RW/ZI/Debug size of an object?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $ZIData_size = &LinkerOutputParser::ListObjSummaryInfo("lpwr.obj", "ZI Data");
	print "$ZIData_size\n";

	my $Debug_size = &LinkerOutputParser::ListObjSummaryInfo("lpwr.obj", "Debug");
	print "$Debug_size\n";

which prints (on my machine):

	1946
	6344
	
25. What if I want to know Code/RO/RW/ZI/Debug size of a library?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);  # Must run this subroutine first for other activities
	
	my $ROData_size = &LinkerOutputParser::ListLibSummaryInfo("bootloader.lib", "RO Data");
	print "$ROData_size\n";

	my $RWData_size = &LinkerOutputParser::ListLibSummaryInfo("bootloader.lib", "RW Data");
	print "$RWData_size\n";

which prints (on my machine):

	917
	208

26. How to retrieve data from temp files which reserved when parsing?

	use LinkerOutputParser;

	my $file = "E:\\APOLLO55N_V2_DEMO_BOOTLOADER_V005_MT6255_MAUI_11B_W12_08.lis";
	
	&LinkerOutputParser::FileParse($file);
	&LinkerOutputParser::StoreIntoTempFile("E:\\mtk80506");   ## You can identify your preferred path to store temp files
	
	my $data_hash = retrieve 'E:\\mtk80506\\LisParser_Temp.dat';    ## temp file names: your_path\LisParser_Temp.dat or your_path\SymParser_Temp.dat or your_path\MapParser_Temp.dat
	foreach my $key (keys %$data_hash)
	{
		print "$key\n";
	}

which prints (on my machine):
	
	debug_size
	parent_reference
	symbol_info
	obj_summary
	execution_region
	child_reference
	load_region
	lib_summary
	
	Then you can retrieve more detailed data, for example, you want to retrieve "child_reference" data (usually are hash/array reference):
	
	my $child_value = $$data_hash{"child_reference"};

	foreach my $key (keys %$child_value)
	{
		my $array_ref = $$child_value{$key};
		foreach my $temp(@$array_ref)
		{
			print "$key->$temp\n";
		}
	}

which prints (on my machine):
	
	lpwr_group_init->.bss
	lpwr_group_init->.constdata
	_3DES_KeyOptionHandler->__aeabi_memcpy
	Init->uart_init
	Init->set_debug_level
	Init->bl_print
	Init->DclF32K_Initialize
	Init->WaitFor32KStable
	Init->lpwr_init
	Init->DRVPDN_ini
	Init->NFIDriverInit
	Init->bl_Is_Brom_Cmd_Mode_Disabled
	Init->DummyReference
	Init->SSS_Init_Share_Crypto_Drv
	Init->SST_SWB_Init
	Init->bootloader_debug_level
	Init->g_randomSeed
	Init->BL_RESV_REGION
	Init->g_bromCmdModeDisabled
	Init->EMI_INFO_2
	Init->__user_initial_stackheap
	kal_assert_fail_specific_ext->dbg_print
	drv_get_duration_ms->drv_get_duration_tick
	...
	
=cut