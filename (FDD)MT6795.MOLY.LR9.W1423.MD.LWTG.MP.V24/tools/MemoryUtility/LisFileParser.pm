use strict;
BEGIN{push(@INC,'../', './tools/', './tools/MemoryUtility/')};
use CommonUtility;

#****************************************************************************
# Constants
#****************************************************************************
package LoadRegion;
use constant Base                  => 1;
use constant Size                  => 2;
use constant MaxSize               => 3;
use constant Attr                  => 4;

package ExecutionRegion;
use constant ExeRegionName         => 0;
use constant Base                  => 1;
use constant Size                  => 2;
use constant MaxSize               => 3;
use constant Type                  => 3;
use constant Attr                  => 4;
use constant SectionAttr           => 5;
use constant ObjName               => 6;
use constant LibName               => 7;

package LisFileParser;

my $g_LISPath;
# Load Region
my %g_LoadRegion;
my $g_LoadRegionCount = 0;
my %g_LoadRegionLookUpTable; # RegionName -> Index
# Execution Region
my %g_ExeRegion;
my $g_ExeRegionCount = 0;
my %g_ExeRegionLookUpTable; # RegionName -> Index
my %g_VeneerLookUpTable;

# InputSection:
my %g_InputSectionDetails; # {nIndex} => [0. strExecutionRegionName, 
                           #              1. strBaseAddress, 
                           #              2. strSize, 
                           #              3. strType, 
                           #              4. strAttr, 
                           #              5. strSectionName, 
                           #              6. strObjectName, 
                           #              7. strLibName]
                           # nIndex starts from 0
my %g_InputSections; # {strExecutionRegionName} => [nIndex, ...]
my $g_InputSectionCount = 0;
my %debugInfoSize;
my %ObjSummary;
my %LibSummary;

my %child;
my %parent;

# Total Size
my $g_nTotalROSize = 0;
my $g_nTotalRWZISize = 0;
my $g_nTotalROMSize = 0;

my @LoadRegions;
my @ExeRegions;

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
# return 1;

#****************************************************************************
# subroutine:  LIS_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub LIS_die
{
    my ($error_msg, $file, $line_no) = (@_);
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'LIS');    
}
#****************************************************************************
# subroutine:  ParseLIS
# input:  LIS Path string     
# output: x     
#****************************************************************************
sub ParseLIS
{
    ($g_LISPath) = (@_);
	
	%g_LoadRegion = undef;
	$g_LoadRegionCount = 0;
	%g_LoadRegionLookUpTable = undef;
    %g_ExeRegion = undef;
	$g_ExeRegionCount = 0;
	%g_ExeRegionLookUpTable = undef;
	%g_VeneerLookUpTable = undef;
	%g_InputSectionDetails = undef;
	%g_InputSections = undef;
	$g_InputSectionCount = 0;
	%debugInfoSize = undef;
	%ObjSummary = undef;
	%LibSummary = undef;
	%child = undef;
	%parent = undef;
	$g_nTotalROSize = 0;
	$g_nTotalRWZISize = 0;
	$g_nTotalROMSize = 0;
	@LoadRegions = undef;
    @ExeRegions = undef;
	
    if(defined $g_LISPath and -e $g_LISPath)
    {
        open (FILE_HANDLE, "<$g_LISPath") or &LIS_die("$g_LISPath: file error!", __FILE__, __LINE__);
        my $strPreExeRegionName = undef;
		my $strObjDebug = 0;
		my $strLibDebug = 0;
        while (<FILE_HANDLE>) 
        {
            my $strLine = $_;
			
			if(/\s+(\S+)\..*\((\S+)\)\srefers\s\S*\s*to\s(\S+)\..*\((\S+)\)\sfor\s(\S+)\s*/)
			{ ### arm_unaligned.obj(i.memcpy) refers to rt_memcpy_w.o(.text) for __aeabi_memcpy4
				my $parent = $2;
				my $child = $5;
				$parent =~ s/i\.//;
				push(@{$child{$parent}}, $child);
				push(@{$parent{$child}}, $parent);
			}
			elsif(/Veneer to (\w+)\s+(0x\w+)/)
			{
				$g_VeneerLookUpTable{$2} = $1;
				## Long ARM to Thumb Veneer to ASSERT       0x5000005c   ARM Code       8  anon$$obj.o(Veneer$$Code)
			}
			elsif(/\s+Load Region\s(\w+)\s\(Base:\s(0x\w+)\,\sSize:\s(0x\w+),\sMax:\s(0x\w+),\s(\w+)\)/) 
            {   #   Load Region READ_ONLY (Base: 0x40000900, Size: 0x00004114, Max: 0xffffffff, ABSOLUTE)
                #$1=Region name, $2=nBaseAddress, $3=nActualSize, $4=nMaxSize, $5=strAttribute
                $g_LoadRegion{++$g_LoadRegionCount}= [$1, hex($2), hex($3), hex($4), $5];
                #print "Index=$g_LoadRegionCount, LoadRegionName=$1, BaseAddress=$2, MaxSize=$3, ActualSize=$4, Attribute=$5\n";
                $g_LoadRegionLookUpTable{$1} = $g_LoadRegionCount;   ### use load region name to query load region id
                $strPreExeRegionName = undef;
				push(@LoadRegions, $1);
            }
            elsif (/\s+Execution Region\s(\w+)\s\(Base:\s(0x\w+)\,\sSize:\s(0x\w+),\sMax:\s(0x\w+),\s(\w+)(.*)\)/) 
            {
                #$1=Region name, $2=nBaseAddress, $3=nActualSize, $4=nMaxSize, $5=strAttribute
                $g_ExeRegion{++$g_ExeRegionCount}= [$1, hex($2), hex($3), hex($4), $5];
                #print "Index=$g_ExeRegionCount, ExeRegionName=$1, BaseAddress=$2, Size=$3, ActualSize=$4, Attribute=$5\n";
                $g_ExeRegionLookUpTable{$1} = $g_ExeRegionCount;
                # For parsing Input sections
                $strPreExeRegionName = $1;
                $g_InputSections{$strPreExeRegionName} = [];
				push(@ExeRegions, $1);
            }
            elsif (/=========/)
            {
                $strPreExeRegionName = undef;
            }
			elsif (/\s+Code\s+\(inc\. data\)\s+RO Data\s+RW Data\s+ZI Data\s+Debug\s+Object Name/)
			{  ## Code (inc. data)   RO Data    RW Data    ZI Data      Debug   Object Name
				$strObjDebug = 1;
			}
			elsif (/\s+Code\s+\(inc\. data\)\s+RO Data\s+RW Data\s+ZI Data\s+Debug\s+Library Member Name/)
			{
				$strObjDebug = 1;
			}
			elsif (/\s+Code\s+\(inc\. data\)\s+RO Data\s+RW Data\s+ZI Data\s+Debug\s+Library Name/)
			{  ##  Code (inc. data)   RO Data    RW Data    ZI Data      Debug   Library Name
				$strLibDebug = 1;
			}
			elsif (/Total RO  Size \(Code \+ RO Data\)\s+(\S+)/)
            {
                $g_nTotalROSize = $1;
            }
            elsif (/Total RW  Size \(RW Data \+ ZI Data\)\s+(\S+)/)
            {
                $g_nTotalRWZISize = $1;
            }
            elsif (/Total ROM Size \(Code \+ RO Data \+ RW Data\)\s+(\S+)/)
            {
                $g_nTotalROMSize  = $1;
            }
            &ParseInputSection($strPreExeRegionName, $strLine) if(defined $strPreExeRegionName);
			&ParseDebugInfo($strObjDebug, $strLine) if ($strObjDebug);
			&GetObjSummaryInfo($strObjDebug, $strLine) if ($strObjDebug);
			&GetLibSummaryInfo($strLibDebug, $strLine) if ($strLibDebug);
        }
        close FILE_HANDLE;
    }
    else
    {
        &LIS_die("LIS Path($g_LISPath) doesn't exist", __FILE__, __LINE__);   
    }    
}

#****************************************************************************
# subroutine:  StoreIntoTempFile
# input:       N/A
# output:      temp files which contain perl data structure
#****************************************************************************
use Storable qw/lock_nstore/;
sub StoreIntoTempFile
{
	my ($strPath) = @_;
	my $file = $strPath."\\LisParser_Temp.dat";
	my %tempfile;
	$tempfile{"parent_reference"} = \%parent;
	$tempfile{"child_reference"} = \%child;
	$tempfile{"debug_size"} = \%debugInfoSize;
	$tempfile{"execution_region"} = \%g_ExeRegion;
	$tempfile{"load_region"} = \%g_LoadRegion;
	$tempfile{"symbol_info"} = \%g_InputSectionDetails;
	$tempfile{"obj_summary"} = \%ObjSummary;
	$tempfile{"lib_summary"} = \%LibSummary;
	
	lock_nstore \%tempfile, $file;
}

#****************************************************************************
# subroutine:  GetParentOfSymbol
# input:       symbol name
# output:      parent symbol array reference
#****************************************************************************
sub GetParentOfSymbol
{
	my ($strSymbolName) = @_;
	foreach my $key (keys %parent)
	{
		next if ($strSymbolName ne $key);
		my $parent = $parent{$key};
		
		return $parent;
	}
}

#****************************************************************************
# subroutine:  GetChildOfSymbol
# input:       symbol name
# output:      child symbol array reference
#****************************************************************************
sub GetChildOfSymbol
{
	my ($strSymbolName) = @_;
	foreach my $key (keys %child)
	{
		next if ($strSymbolName ne $key);
		my $child = $child{$key};
		
		return $child;
	}
}

#****************************************************************************
# subroutine:  ListAllExeRegion
# input:       N/A
# output:      execution region array reference 
#****************************************************************************
sub ListAllExeRegion
{
	$#ExeRegions = $#ExeRegions + 1;	
	return \@ExeRegions;
}

#****************************************************************************
# subroutine:  ListAllLoadRegion
# input:       N/A
# output:      load region array reference
#****************************************************************************
sub ListAllLoadRegion
{
	$#LoadRegions = $#LoadRegions + 1;
	return \@LoadRegions;
}
#****************************************************************************
# subroutine:  ParseInputSection used by ParseLIS
#              to parse input sections
# parsing format: 
#     Base Addr    Size         Type   Attr      Idx    E Section Name        Object
# 1.  0x70008230   0x00000020   Code   RO           18  * VECTOR_TBL          bl_BOOTARM.obj(bootloader.lib)   
# 2.  0x1007bb30   0x00000008   Ven    RO       402248    Veneer$$Code        anon$$obj.o
# 3.  0x106f9c72   0x00000002   PAD
# we don't need Idx(Index) and E(Entry)
# input:  1. Execution Name, 2. $strLine
# output: x     
#****************************************************************************
sub ParseInputSection
{
    my ($strExeRegionName, $strLine) = @_;
    return if(!defined $strExeRegionName);    ### setting for $strExeRegionName = undef

    my ($strBaseAddress, $strSize, $strType, $strAttr, $strInputSection, $strObjName, $strLibName)
     = (undef, undef, undef, undef, undef, undef, undef);
    my $bMatchInputSection = 0; 
    chomp($strLine);
    if($strLine =~ /\s+(0x\w+)\s+(0x\w+)\s+(\w+)\s+(\w+)\s+\d+\s+\**\s+(\S+)\s+(\S+)\((\S+)\)/)
    {
    #    Base Addr    Size         Type   Attr      Idx    E Section Name        Object
    #    0x70008230   0x00000020   Code   RO           18  * VECTOR_TBL          bl_BOOTARM.obj(bootloader.lib)    
        $strBaseAddress = $1;
        $strSize = $2;
        $strType = $3;
        $strAttr = $4;
        $strInputSection = $5;
        $strObjName = $6;
        $strLibName = $7;
        #print "[Pattern 1]$strLine:\n[Base]$strBaseAddress, [Size]$strSize, [Type]$strType, [Attr]$strAttr, [InputAttr]$strInputSection, [ObjName]$strObjName, [LibName]$strLibName\n";
        $bMatchInputSection = 1; 
    }
    elsif($strLine =~ /\s+(0x\w+)\s+(0x\w+)\s+(\w+)\s+(\w+)\s+\d+\s+\**\s+(\S+)\s+(\S+)/)
    {
    #    Base Addr    Size         Type   Attr      Idx    E Section Name        Object
    #    0x1007bb30   0x00000008   Ven    RO       402248    Veneer$$Code        anon$$obj.o
        $strBaseAddress = $1;
        $strSize = $2;
        $strType = $3;
        $strAttr = $4;
        $strInputSection = $5;
        $strObjName = $6;
        #print "[Pattern 2]$strLine:\n[Base]$strBaseAddress, [Size]$strSize, [Type]$strType, [Attr]$strAttr, [InputAttr]$strInputSection, [ObjName]$strObjName, [LibName]x\n";
        $bMatchInputSection = 1;
    }
    elsif($strLine =~ /\s+(0x\w+)\s+(0x\w+)\s+(\w+)/)
    {
    #    Base Addr    Size         Type   Attr      Idx    E Section Name        Object
    #    0x106f9c72   0x00000002   PAD
        $strBaseAddress = $1;
        $strSize = $2;
        $strType = $3;
        #print "[Pattern 3]$strLine:\n[Base]$strBaseAddress, [Size]$strSize, [Type]$strType\n";
        $bMatchInputSection = 1;
    }
    if($bMatchInputSection == 1)
    {
        $g_InputSectionDetails{$g_InputSectionCount} = [$strExeRegionName, $strBaseAddress, $strSize, 
                                                        $strType, $strAttr, $strInputSection, 
                                                        $strObjName, $strLibName];
        push (@{$g_InputSections{$strExeRegionName}}, $g_InputSectionCount);
        $g_InputSectionCount++;
    }
}

#****************************************************************************
# subroutine:  ListPadInfo
# input:       N/A
# output:      array reference
#              for lis file, array content:[array1,array2,...]
#                            array1:[strPadBaseAddress,strPreSymName,strPreSymAddress,strPostSymName,strPostSymAddress]
#****************************************************************************
sub ListPadInfo
{
	my @padstring;
	foreach my $key (sort keys %g_InputSectionDetails)
	{
		my $type = $g_InputSectionDetails{$key}->[3];
		next if ($type ne "PAD");
		my $base_address = $g_InputSectionDetails{$key}->[1];
		my $pre_address = $g_InputSectionDetails{$key-1}->[1];
		my $pre_symbol = $g_InputSectionDetails{$key-1}->[5];
		my $post_address = $g_InputSectionDetails{$key+1}->[1];
		my $post_symbol = $g_InputSectionDetails{$key+1}->[5];

		my @padinfo = [$base_address,$pre_symbol,$pre_address,$post_symbol,$post_address];
		push (@padstring, @padinfo);
	}
	return \@padstring;
}

#****************************************************************************
# subroutine:  ParseDebugInfo
# input:       $strObjDebug, $strLine
# output:      N/A
#****************************************************************************
sub ParseDebugInfo
{
	my ($strObjDebug, $strLine) = @_;
	return if(!$strObjDebug);
	###  0          0    7341676          0          0          0   IG_FT_CH_320X480.obj
    chomp($strLine);
	if($strLine =~ /\s+\d+\s+\d+\s+\d+\s+\d+\s+\d+\s+(\d+)\s+(\S+\.obj$|\S+\.o$)/)
	{
		$debugInfoSize{$2} = $1;
	}  
}

#****************************************************************************
# subroutine:  GetObjSummaryInfo
# input:       flag $strObjDebug, $strLine
# output:      N/A
#****************************************************************************
sub GetObjSummaryInfo
{
	my ($strObjDebug, $strLine) = @_;
	return if(!$strObjDebug);
	###  0          0    7341676          0          0          0   IG_FT_CH_320X480.obj
    chomp($strLine);
	if($strLine =~ /\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\S+\.obj$|\S+\.o$)/)
	{
		$ObjSummary{$7} = [$1,$2,$3,$4,$5,$6];
	}
}

#****************************************************************************
# subroutine:  GetLibSummaryInfo
# input:       flag $strLibDebug, $strLine
# output:      N/A
#****************************************************************************
sub GetLibSummaryInfo
{
	my ($strLibDebug, $strLine) = @_;
	return if(!$strLibDebug);
	###  0          0    7341676          0          0          0   IG_FT_CH_320X480.obj
    chomp($strLine);
	if($strLine =~ /\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\S+\.lib$|\S+\.l$|\S+\.a$)/)
	{
		$LibSummary{$7} = [$1,$2,$3,$4,$5,$6];
	}
}

#****************************************************************************
# subroutine:  ListObjSummaryInfo
# input:       obj name, flag represents which column to show
#                        flag = "Code"
#                             = "inc.data"
#                             = "RO Data"
#                             = "RW Data"
#                             = "ZI Data"
#                             = "Debug"
# output:      Code/inc.data/RO Data/RW Data/ZI Data/Debug size for given obj
#****************************************************************************
sub ListObjSummaryInfo
{
	my ($strObjName, $flag) = @_;
	foreach my $key (keys %ObjSummary)
	{
		next if ($strObjName ne $key);
		my $ObjSummaryInfo = $ObjSummary{$key};
		if ($flag eq "Code")
		{
			return @$ObjSummaryInfo[0];
		}
		elsif ($flag eq "inc.data")
		{
			return @$ObjSummaryInfo[1];
		}
		elsif ($flag eq "RO Data")
		{
			return @$ObjSummaryInfo[2];
		}
		elsif ($flag eq "RW Data")
		{
			return @$ObjSummaryInfo[3];
		}
		elsif ($flag eq "ZI Data")
		{
			return @$ObjSummaryInfo[4];
		}
		elsif ($flag eq "Debug")
		{
			return @$ObjSummaryInfo[5];
		}
	}
}

#****************************************************************************
# subroutine:  ListLibSummaryInfo
# input:       lib name, flag represents which column to show
#                        flag = "Code"
#                             = "inc.data"
#                             = "RO Data"
#                             = "RW Data"
#                             = "ZI Data"
#                             = "Debug"
# output:      Code/inc.data/RO Data/RW Data/ZI Data/Debug size for given lib
#****************************************************************************
sub ListLibSummaryInfo
{
	my ($strLibName, $flag) = @_;
	foreach my $key (keys %LibSummary)
	{
		next if ($strLibName ne $key);
		my $LibSummaryInfo = $LibSummary{$key};
		if ($flag eq "Code")
		{
			return @$LibSummaryInfo[0];
		}
		elsif ($flag eq "inc.data")
		{
			return @$LibSummaryInfo[1];
		}
		elsif ($flag eq "RO Data")
		{
			return @$LibSummaryInfo[2];
		}
		elsif ($flag eq "RW Data")
		{
			return @$LibSummaryInfo[3];
		}
		elsif ($flag eq "ZI Data")
		{
			return @$LibSummaryInfo[4];
		}
		elsif ($flag eq "Debug")
		{
			return @$LibSummaryInfo[5];
		}
	}
}

#****************************************************************************
# subroutine:  GetInputSectionsByExeRegion 
# input:       $strExeRegionName: Execution Name (Case sensitive)
# output:      Array_ref : InputSections: [[ExeRegionName, Base...], [ExeRegionName, Base...], ...]
#              [ExeRegionName, Base...]: InputSectionDetails elements
#****************************************************************************
sub GetInputSectionsByExeRegion
{
    my ($strExeRegionName) = @_;
    my @InputSections;
    my $Indexes = $g_InputSections{$strExeRegionName};    ### array
    foreach my $nIndex (@$Indexes)
    {
        push(@InputSections, $g_InputSectionDetails{$nIndex});  ## $g_InputSectionDetails{$g_InputSectionCount} = [$strExeRegionName, $strBaseAddress, $strSize, $strType, $strAttr, $strInputSection, $strObjName, $strLibName];
    }
    return \@InputSections;
}

#****************************************************************************
# subroutine:  GetObjTotalSizesByExeRegion
# input:       $strRegionName: Execution Name (Case sensitive)
# output:      ObjTotalSize Hash Reference: {ObjName::LibName} => nSize
# sample code:
#        my $strExeRegionName = "xxx";
#        my $nObjTotalSize_ref = &LISInfo::GetObjTotalSizesByExeRegion($strExeRegionName);
#        foreach my $Obj_LibName (keys %$nObjTotalSize_ref) {...}
#        => $Obj_LibName: "ObjName::LibName"
#****************************************************************************
sub GetObjTotalSizesByExeRegion
{
    my ($strExeRegionName) = @_;
    my %nObjTotalSize; # {ObjName_LibName} = nSize;
    my $InputSections_ref = &GetInputSectionsByExeRegion($strExeRegionName);
    foreach my $Info ( @$InputSections_ref)
    {
        if(defined $Info->[ExecutionRegion::ObjName])
        {
            my $strKey = $Info->[ExecutionRegion::ObjName]."::".$Info->[ExecutionRegion::LibName];
            if(exists $nObjTotalSize{$strKey})
            {
                $nObjTotalSize{$strKey} += hex($Info->[ExecutionRegion::Size]);
                #print "$strKey = ". $ObjTotalSize{$strKey} ."\n";
            }
            else
            {
                $nObjTotalSize{$strKey} = hex($Info->[ExecutionRegion::Size]);
                #print "$strKey = ". hex($Info->[InputSection::Size])."\n";
            }
        }
        else #PAD
        {
            $nObjTotalSize{"PAD"} += hex($Info->[ExecutionRegion::Size]);
        }
    }
    return \%nObjTotalSize;
}

#****************************************************************************
# subroutine:  GetObjSizeByCatExeRegion
# input:       $strRegionName: Execution Name (Case sensitive)
#              $strCategory: RO Data/RW Data/ZI Data/Code (Case sensitive)
# output:      ObjCateSize Hash Reference
#****************************************************************************
sub GetObjSizeByCatExeRegion
{
	 my ($strExeRegionName, $strCategory) = @_;
	 my %nObjROSize; 
	 my %nObjRWSize;
	 my %nObjZISize;
	 my %nObjCodeSize;
	 
	 my $InputSections_ref = &GetInputSectionsByExeRegion($strExeRegionName);
	 foreach my $Info ( @$InputSections_ref)
	 {
		if(defined $Info->[ExecutionRegion::ObjName])
		{
			my $strKey = $Info->[ExecutionRegion::ObjName];

			if(($strCategory eq "RO Data") && ($Info->[ExecutionRegion::Type] eq "Data") && ($Info->[ExecutionRegion::Attr] eq "RO"))
			{
				if(exists $nObjROSize{$strKey})
				{
					$nObjROSize{$strKey} += hex($Info->[ExecutionRegion::Size]);
				}
				else
				{
					$nObjROSize{$strKey} = hex($Info->[ExecutionRegion::Size]);
				}
			}
			elsif(($strCategory eq "RW Data") && ($Info->[ExecutionRegion::Type] eq "Data") && ($Info->[ExecutionRegion::Attr] eq "RW"))
			{
				if(exists $nObjRWSize{$strKey})
				{
					$nObjRWSize{$strKey} += hex($Info->[ExecutionRegion::Size]);
				}
				else
				{
					$nObjRWSize{$strKey} = hex($Info->[ExecutionRegion::Size]);
				}
			}
			elsif(($strCategory eq "ZI Data") && ($Info->[ExecutionRegion::Type] eq "Zero") && ($Info->[ExecutionRegion::Attr] eq "RW"))
			{
				if(exists $nObjZISize{$strKey})
				{
					$nObjZISize{$strKey} += hex($Info->[ExecutionRegion::Size]);
				}
				else
				{
					$nObjZISize{$strKey} = hex($Info->[ExecutionRegion::Size]);
				}
			}
			elsif(($strCategory eq "Code") && ($Info->[ExecutionRegion::Type] eq "Code") && ($Info->[ExecutionRegion::Attr] eq "RO"))
			{
				if(exists $nObjCodeSize{$strKey})
				{
					$nObjCodeSize{$strKey} += hex($Info->[ExecutionRegion::Size]);
				}
				else
				{
					$nObjCodeSize{$strKey} = hex($Info->[ExecutionRegion::Size]);
				}
			}
		}	
	 }
	 
	 if($strCategory eq "RO Data")
	 {
		return \%nObjROSize;
	 }
	 elsif($strCategory eq "RW Data")
	 {
		return \%nObjRWSize;
	 }
	 elsif($strCategory eq "ZI Data")
	 {	
		return \%nObjZISize;
	 }
	 elsif($strCategory eq "Code")
	 {
		return \%nObjCodeSize;
	 }
}


#****************************************************************************
# subroutine:  GetTotalSizeByExeRegion
# input:       $strRegionName: Execution Region Name (Case sensitive)
# output:      total size for given execution region
#****************************************************************************
sub GetTotalSizeByExeRegion
{
	my ($strExeRegionName) = @_;
    my %nExeRegionTotalSize; # {ObjName_LibName} = nSize;
	my $TotalSize;
    my $InputSections_ref = &GetInputSectionsByExeRegion($strExeRegionName);
    foreach my $Info ( @$InputSections_ref)
    {
        if(defined $Info->[ExecutionRegion::ExeRegionName])
        {
            my $strKey = $Info->[ExecutionRegion::ExeRegionName];
            if(exists $nExeRegionTotalSize{$strKey})
            {
                $nExeRegionTotalSize{$strKey} += hex($Info->[ExecutionRegion::Size]);
                #print "$strKey = ". $ObjTotalSize{$strKey} ."\n";
            }
            else
            {
                $nExeRegionTotalSize{$strKey} = hex($Info->[ExecutionRegion::Size]);
                #print "$strKey = ". hex($Info->[InputSection::Size])."\n";
            }
			$TotalSize = $nExeRegionTotalSize{$strKey};
        }
    }
	return $TotalSize;
}

#****************************************************************************
# subroutine:  GetObjByExeRegion
# input:       Execution Region Name (Case sensitive)
# output:      OBJ array reference which given execution region contains
#****************************************************************************
sub GetObjByExeRegion
{
	my ($strExeRegionName) = @_;
	my $InputSections_ref = &GetInputSectionsByExeRegion($strExeRegionName);
	my @obj;
	my @uni_objs;
	my %count;
	foreach my $Info ( @$InputSections_ref)
    {
        if(defined $Info->[ExecutionRegion::ObjName])
        {
			my $strObj = $Info->[ExecutionRegion::ObjName];
			push(@obj, $strObj);
        }
    }
	@uni_objs = grep { ++$count{ $_ } < 2; } @obj; 
	return \@uni_objs;
}

#****************************************************************************
# subroutine:  GetLibByExeRegion
# input:       Execution Region Name (Case sensitive)
# output:      LIB array reference which given execution region contains
#****************************************************************************
sub GetLibByExeRegion
{
	my ($strExeRegionName) = @_;
	my $InputSections_ref = &GetInputSectionsByExeRegion($strExeRegionName);
	my @lib;
	my @uni_libs;
	my %count;
	foreach my $Info (@$InputSections_ref)
    {
        if(defined $Info->[ExecutionRegion::LibName])
        {
			my $strLib = $Info->[ExecutionRegion::LibName];
			push(@lib, $strLib);
        }
    }
	@uni_libs = grep { ++$count{ $_ } < 2; } @lib; 
	return \@uni_libs;
}

#****************************************************************************
# subroutine:  GetLibSizeByExeRegion
# input:       Execution Region Name, Library Name (Case sensitive)
# output:      size of given library in givin execution region
#****************************************************************************
sub GetLibSizeByExeRegion
{
	my ($strExeRegion, $strLib) = @_;
	my $InputSections_ref = &GetInputSectionsByExeRegion($strExeRegion);
	my $size = 0;
	foreach my $Info ( @$InputSections_ref)
    {
        if($Info->[ExecutionRegion::LibName] eq $strLib)
        {
            $size += hex($Info->[ExecutionRegion::Size]);
        }
    }
	return $size;
}

#****************************************************************************
# subroutine:  GetTotalSizeByLib
# input:       $strLibName: Library Name (Case sensitive)
# output:      total size for given library
#****************************************************************************
sub GetTotalSizeByLib
{
    my ($strLibName) = @_;
	my %nLibTotalSize;
	my $TotalSize;
	foreach my $ExeRegion (@ExeRegions)
	{
		my $InputSections_ref = &GetInputSectionsByExeRegion($ExeRegion);
		foreach my $Info ( @$InputSections_ref)
		{
			if(defined $Info->[ExecutionRegion::LibName])
			{
				my $strKey = $Info->[ExecutionRegion::LibName];
				next if ($strKey ne $strLibName);
				if(exists $nLibTotalSize{$strKey})
				{
					$nLibTotalSize{$strKey} += hex($Info->[ExecutionRegion::Size]);
					#print "$strKey = ". $ObjTotalSize{$strKey} ."\n";
				}
				else
				{
					$nLibTotalSize{$strKey} = hex($Info->[ExecutionRegion::Size]);
					#print "$strKey = ". hex($Info->[InputSection::Size])."\n";
				}
				$TotalSize = $nLibTotalSize{$strKey};
			}
		}
	}
	return $TotalSize;
}

#****************************************************************************
# subroutine:  GetTotalSizeByObj
# input:       $strObjName: Obj Name, $strLibName: Library Name (Case sensitive)
# output:      total size for given (obj, library)
#****************************************************************************
sub GetTotalSizeByObj
{
    my ($strObjName, $strLibName) = @_;
	my %nObjTotalSize;
	my $TotalSize;
	foreach my $ExeRegion(@ExeRegions)
	{
		my $InputSections_ref = &GetInputSectionsByExeRegion($ExeRegion);
		foreach my $Info(@$InputSections_ref)
		{
			if(defined $Info->[ExecutionRegion::ObjName])
			{
				my $strKey = $Info->[ExecutionRegion::ObjName]."::".$Info->[ExecutionRegion::LibName];
				my $Key = $strObjName."::".$strLibName;
				next if ($Key ne $strKey);
				if(exists $nObjTotalSize{$strKey})
				{
					$nObjTotalSize{$strKey} += hex($Info->[ExecutionRegion::Size]);
					#print "$strKey = ". $ObjTotalSize{$strKey} ."\n";
				}
				else
				{
					$nObjTotalSize{$strKey} = hex($Info->[ExecutionRegion::Size]);
					#print "$strKey = ". hex($Info->[InputSection::Size])."\n";
				}
				$TotalSize = $nObjTotalSize{$strKey};
			}
		}
	}
	return $TotalSize;
}

#****************************************************************************
# subroutine:  ListObjLibBySymbol
# input:       $SymName: Symbol Name (Case sensitive)
# output:      [obj, library] list array reference
#****************************************************************************
sub ListObjLibBySymbol
{
	my ($SymName) = @_;
	my @obj_lib;
	foreach my $ExeRegion(@ExeRegions)
	{
		my $InputSections_ref = &GetInputSectionsByExeRegion($ExeRegion);
		foreach my $Info(@$InputSections_ref)
		{
			if(defined $Info->[ExecutionRegion::SectionAttr])
			{
				my $strKey = $Info->[ExecutionRegion::SectionAttr];
				if($strKey eq $SymName)
				{
					my $ObjName = $Info->[ExecutionRegion::ObjName];
					my $LibName = $Info->[ExecutionRegion::LibName];
					push(@obj_lib, [$ObjName, $LibName]);
				}
			}
		}
	}
	return \@obj_lib;
}

#****************************************************************************
# subroutine:  ListObjByLib
# input:       $LibName: Library Name (Case sensitive)
# output:      obj array reference
#****************************************************************************
sub ListObjByLib
{
	my ($LibName) = @_;
	my @obj;
	my @uni_objs;
	my %count;
	foreach my $ExeRegion(@ExeRegions)
	{
		my $InputSections_ref = &GetInputSectionsByExeRegion($ExeRegion);
		foreach my $Info(@$InputSections_ref)
		{
			if(defined $Info->[ExecutionRegion::LibName])
			{
				my $strKey = $Info->[ExecutionRegion::LibName];
				if($strKey eq $LibName)
				{
					my $ObjName = $Info->[ExecutionRegion::ObjName];
					push(@obj, $ObjName);
				}
			}
		}
	}
	@uni_objs = grep { ++$count{ $_ } < 2; } @obj; 
	return \@uni_objs;
}

#****************************************************************************
# subroutine:  ListLibByObj
# input:       $ObjName: Object Name (Case sensitive)
# output:      Library array reference
#****************************************************************************
sub ListLibByObj
{
	my ($ObjName) = @_;
	my @lib;
	my @uni_libs;
	my %count;
	foreach my $ExeRegion(@ExeRegions)
	{
		my $InputSections_ref = &GetInputSectionsByExeRegion($ExeRegion);
		foreach my $Info(@$InputSections_ref)
		{
			if(defined $Info->[ExecutionRegion::ObjName])
			{
				my $strKey = $Info->[ExecutionRegion::ObjName];
				if($strKey eq $ObjName)
				{
					my $LibName = $Info->[ExecutionRegion::LibName];
					push(@lib, $LibName);
				}
			}
		}
	}
	@uni_libs = grep { ++$count{ $_ } < 2; } @lib;		
	return \@uni_libs;
}

#****************************************************************************
# subroutine:  GetObjDebugInfoSize
# input:       $strObjName: Obj Name (Case sensitive)
# output:      debug info size for given obj
#****************************************************************************
sub GetObjDebugInfoSize
{
	my ($strObjName) = @_;
    my $DebugInfoSize = $debugInfoSize{$strObjName};
	return $DebugInfoSize;
}

#****************************************************************************
# subroutine:  FootprintAnalyzeBySymbol
# input:       $strSymName: Symbol Name, $strObjName: Obj Name (Case sensitive)
# output:      symbol info array reference
#****************************************************************************
sub FootprintAnalyzeBySymbol
{
	my ($strSymName, $strObjName) = @_;
	my %SymHash;
	my @SymInfo;
	foreach my $ExeRegion(@ExeRegions)
	{
		my $InputSections_ref = &GetInputSectionsByExeRegion($ExeRegion);
		foreach my $Info(@$InputSections_ref)
		{
			if(defined $Info->[ExecutionRegion::SectionAttr])
			{
				my $strKey = $Info->[ExecutionRegion::SectionAttr]."::".$Info->[ExecutionRegion::ObjName];
				my $Key = $strSymName."::".$strObjName;
				next if ($Key ne $strKey);
				
				my $type = $Info->[ExecutionRegion::Type];
				if (($type ne "Pad") && ($type ne "Ven"))
				{
					my $attr = $Info->[ExecutionRegion::Attr]."-".$type;
					my $base = $Info->[ExecutionRegion::Base];
					my $size = hex($Info->[ExecutionRegion::Size]);
					my $region = $ExeRegion;
					$SymHash{$strKey} = [$region, $attr, $base, $size];		
					
					push(@SymInfo, $region);
					push(@SymInfo, $attr);
					push(@SymInfo, $base);
					push(@SymInfo, $size);
				}
				elsif ($type eq "Ven")
				{
					my $region = $ExeRegion;
					my $base = $Info->[ExecutionRegion::Base];
					my $dest = $g_VeneerLookUpTable{$base};
					my $size = hex($Info->[ExecutionRegion::Size]);
					$SymHash{$strKey} = [$region, $type, $base, $size, $dest];

					push(@SymInfo, $region);
					push(@SymInfo, $type);
					push(@SymInfo, $base);
					push(@SymInfo, $size);
					push(@SymInfo, $dest);
				}
			}
		}
	}	
	return \@SymInfo;
}

#****************************************************************************
# subroutine:  GetVeneerInfo
# input:       N/A
# output:      [Execution Region, Base Address, Size, DestinationSymbolName] array reference for veneer
#****************************************************************************
sub GetVeneerInfo
{
	my @veneers;
	foreach my $ExeRegion(@ExeRegions)
	{
		my $InputSections_ref = &GetInputSectionsByExeRegion($ExeRegion);
		foreach my $Info(@$InputSections_ref)
		{
			if($Info->[ExecutionRegion::Type] eq "Ven")
			{
				my $base = $Info->[ExecutionRegion::Base];
				my $size = hex($Info->[ExecutionRegion::Size]);
				my $dest = $g_VeneerLookUpTable{$base};
				my @veneerinfo = [$ExeRegion, $base, $size, $dest];
				push(@veneers, @veneerinfo);
			}
		}
	}
	return \@veneers;
}

#****************************************************************************
# subroutine:  GetExeRegionInfo - Get Execution Region information
# input:       $strRegionName: Execution Name (Case sensitive)
#              $nOption: ExecutionRegion::Base
#                        ExecutionRegion::Size
#                        ExecutionRegion::MaxSize
#                        ExecutionRegion::Attr
# output:      required Region Base address, Used Size, Region MaxSize, Attribute info
#****************************************************************************
sub GetExeRegionInfo
{
    my ($strRegionName, $nOption) = @_;
    my ($nBase, $nSize, $nMaxSize, $strAttribute) = (0,0,0,'');
    my $nIndex = $g_ExeRegionLookUpTable{$strRegionName};
	my $strInfo;
    if(defined $nIndex)
    {
		if($nOption == ExecutionRegion::Base)
		{
			$strInfo = &CommonUtil::Dec2Hex($g_ExeRegion{$nIndex}->[ExecutionRegion::Base]);
		}
		elsif($nOption == ExecutionRegion::Size)
		{
			$strInfo = $g_ExeRegion{$nIndex}->[ExecutionRegion::Size];
		}
		elsif($nOption == ExecutionRegion::MaxSize)
		{
			$strInfo = $g_ExeRegion{$nIndex}->[ExecutionRegion::MaxSize];
		}
		elsif($nOption == ExecutionRegion::Attr)
		{
			$strInfo = $g_ExeRegion{$nIndex}->[ExecutionRegion::Attr];
		}
    }
    return $strInfo;
}

#****************************************************************************
# subroutine:  GetLoadRegionInfo - Get Load Region information
# input:       $strRegionName: Execution Name (Case sensitive)
#              $nOption: LoadRegion::Base
#                        LoadRegion::Size
#                        LoadRegion::MaxSize
#                        LoadRegion::Attr
# output:      required Region Base address, Used Size, Region MaxSize, Attribute infosub GetLoadRegionInfo
#****************************************************************************
sub GetLoadRegionInfo
{
    my ($strRegionName, $nOption) = (@_);
    my ($nBase, $nSize, $nMaxSize, $strAttribute) = (0,0,0,'');
    my $nIndex = $g_LoadRegionLookUpTable{$strRegionName};
	my $strInfo;
    if(defined $nIndex)
    {
		if($nOption == LoadRegion::Base)
		{
			$strInfo = &CommonUtil::Dec2Hex($g_LoadRegion{$nIndex}->[LoadRegion::Base]);
		}
		elsif($nOption == LoadRegion::Size)
		{
			$strInfo = $g_LoadRegion{$nIndex}->[LoadRegion::Size];
		}
        elsif($nOption == LoadRegion::MaxSize)
		{
			$strInfo = $g_LoadRegion{$nIndex}->[LoadRegion::MaxSize];
		}
		elsif($nOption == LoadRegion::Attr)
		{
			$strInfo = $g_LoadRegion{$nIndex}->[LoadRegion::Attr];
		}
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
    my ($bNeedString) = @_;
    return $bNeedString ? &CommonUtil::Dec2Hex($g_nTotalROSize) : $g_nTotalROSize; 
}

#****************************************************************************
# subroutine:  GetTotalRWZISize - Get total RWZI size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $bNeedString=0:nRWZISize/ $bNeedString=1:strRWZISize
#****************************************************************************
sub GetTotalRWZISize
{
    my ($bNeedString) = @_;
    return $bNeedString ? &CommonUtil::Dec2Hex($g_nTotalRWZISize) : $g_nTotalRWZISize;
}

#****************************************************************************
# subroutine:  GetTotalROMSize - Get total ROM size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      $bNeedString=0:nROMSize/ $bNeedString=1:strROMSize
#****************************************************************************
sub GetTotalROMSize
{
    my ($bNeedString) = @_;
    return $bNeedString ? &CommonUtil::Dec2Hex($g_nTotalROMSize) : $g_nTotalROMSize;
}

1;