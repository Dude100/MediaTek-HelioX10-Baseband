use strict;
BEGIN{push(@INC,'../', './tools/', './tools/MemoryUtility/')};
use CommonUtility; 

package MapFileParser;

my $g_MAPPath;

my %parent_of_symbol;
my %parent_obj_of_symbol;
my %parent_lib_of_symbol;
my %contained_obj;
my %related_lib;
my %obj_size;
my %lib_size;
my %region_obj_size;
my %region_lib_size;
my %region_contained_obj;
my %region_obj;
my %region_contained_lib;
my @veneers;
my %obj_pad;
my %obj_lib_lookup;
my $obj_pad_count = 0;
my @pad;
my %g_discard_symbols; #$inputsection."_".$obj => $nSize;

my %obj_debuginfo;
my %lib_debuginfo;
my %OBJ_RO_Size;  #{objname} => nSize
my %LIB_RO_Size;  #{libname} => nSize
my %OBJ_RW_Size;
my %LIB_RW_Size;
my %OBJ_ZI_Size; 
my %LIB_ZI_Size;

my %region_OBJ_RO_Size; #{regionname-objname} => nSize  
my %region_OBJ_RW_Size;
my %region_OBJ_ZI_Size;

my @sections; # input section
my %obj_pad_exeregion;  # {ERName} => strPadSize(e.g. 0x---)
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# subroutine:  MAP_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub MAP_die
{
    my ($error_msg, $file, $line_no) = (@_);
    &CommonUtil::error_handler($error_msg, $file, $line_no, 'MAP');    
}
#****************************************************************************
# subroutine:  ParseMAP
# input:  MAP Path string     
# output: x     
#****************************************************************************
sub initGlobalVariable
{
    %parent_of_symbol = ();
    %parent_obj_of_symbol = ();
    %parent_lib_of_symbol = ();
    %contained_obj = ();
    %related_lib = ();
    %obj_size = ();
    %lib_size = ();
    %region_obj_size = ();
    %region_lib_size = ();
    %region_contained_obj = ();
    %region_obj = ();
    %region_contained_lib = ();
    @veneers = ();
    %obj_pad = ();
    %obj_pad_exeregion = ();
    %obj_lib_lookup = ();
    $obj_pad_count = 0;
    @pad = ();
    %obj_debuginfo = ();
    %lib_debuginfo = ();
    %OBJ_RO_Size = ();
    %LIB_RO_Size = ();
    %OBJ_RW_Size = ();
    %LIB_RW_Size = ();
    %OBJ_ZI_Size = ();
    %LIB_ZI_Size = ();
    %region_OBJ_RO_Size = ();
    %region_OBJ_RW_Size = ();
    %region_OBJ_ZI_Size = ();
    @sections = ();
    %g_discard_symbols = ();
}
sub ParseMAP
{
    ($g_MAPPath) = @_;
    initGlobalVariable();
    if(defined $g_MAPPath and -e $g_MAPPath)
    {
        open (FILE_HANDLE, "<$g_MAPPath") or &MAP_die("$g_MAPPath: file error!", __FILE__, __LINE__);
        my ($strPreSymbolName, $strPreExeRegion, $strPreInputSection) = (undef, undef, undef);
        my ($flag_end_group, $b_enter_reference_table, $b_enter_discard) = (1, 0, 0);
        while (<FILE_HANDLE>)
        {
            my $strLine = $_;
            if(/Discarded input sections/)
            {
                $b_enter_discard = 1; next;
            }
            elsif(/Memory Configuration/)
            {
                $b_enter_discard = 0; next;
            }
            elsif($b_enter_discard == 1)
            {
                $strPreSymbolName = _ParseDiscardInputSection($strLine, $strPreSymbolName);
            }
            elsif (/END GROUP/)
            {
                $flag_end_group = 0;  next;
            }
            elsif ($flag_end_group)
            {
                next;
            }
            elsif (/Symbol\s+File/ or /Cross Reference Table/)   
            { #Symbol                                            File
                $b_enter_reference_table = 1; next;
            } 
            elsif($b_enter_reference_table == 0 )
            {
                if(/^(\S+)/ and $strLine !~/^OUTPUT\(/)
                {#ignore: OUTPUT(./build/MT6589_MD2_TDD128HSPA/SKYPA/bin/MT6589_MD2_TDD128HSPA_PCB01_MT6589_S00.elf elf32-littlearm)
                    $strPreExeRegion = $1; next;
                }
                elsif(/^\s+(\S+)$/)
                {# .debug_aranges
                 #               0x00000000       0x20 ./build/MT6589_MD2_TDD128HSPA/SKYPA/bin/lib/libsys_drv.a(bootarm_gcc.obj)
                    $strPreInputSection = $1; next;
                }
                $strPreInputSection = _ParseContent($strLine, $strPreInputSection, $strPreExeRegion);
            }
            else
            {
                my $tmp_ref;
                ($strPreSymbolName,$tmp_ref) = _ParseSymbol($_, $strPreSymbolName);
                $parent_of_symbol{$strPreSymbolName}=$tmp_ref;
            }
        }
        close FILE_HANDLE;
    }
    else
    {
        &MAP_die("MAP Path($g_MAPPath) doesn't exist", __FILE__, __LINE__);   
    }
}

sub _UpdateSize
{
    my ($href, $strKey, $strSize) = @_;
    if(exists $href->{$strKey})
    {
        $href->{$strKey} += hex($strSize);
    }
    else
    {
        $href->{$strKey} = hex($strSize);
    } 
}
sub _ParseDiscardInputSection
{
    my ($strInput, $strPreLine) = @_;
    chomp($strInput);
    if($strInput =~ /^\s+(\S+)\s*$/)
    {# .debug_aranges
     #               0x00000000       0x20 ./build/MT6589_MD2_TDD128HSPA/SKYPA/bin/lib/libsys_drv.a(bootarm_gcc.obj)
        return $1;
    }
    elsif(/^\s+(0x\w+)/)
    {
        $strInput =  $strPreLine . $strInput;
    }
    if (($strInput =~ /(\S+)\s+(0x\w+)\s+(0x\w+)\s+.*\\(.*)\((.*)\)/) || 
        ($strInput =~ /(\S+)\s+(0x\w+)\s+(0x\w+)\s+.*\/(.*)\((.*)\)/))
    { #  C$$code        0x00000000      0x210 ./build/MT6572_DEMO_TDD128HSPA/DEFAULT/bin/lib/libsys_drv.a(bootarm_gcc.obj)
        my $lib = $4;
        my $obj = $5;
        my $nSize = hex($3);
        my $inputsection = $1;
        _UpdateDiscardSymbol($inputsection, $nSize, $obj, $lib);
    }
    return "";
}

sub _UpdateDiscardSymbol
{
    my ($inputsection, $nSize, $obj, $lib) = @_;
    $g_discard_symbols{$obj.'$$'.$inputsection} = $nSize;
}

sub _ParseContent
{
    my ($strInput, $strPreInputSection, $strPreExeRegion) = @_;
    chomp($strInput);
    
    if (($strInput =~ /(0x\w+)\s+(0x\w+)\s+.*\\(.*)\((.*)\)/) || 
        ($strInput =~ /(0x\w+)\s+(0x\w+)\s+.*\/(.*)\((.*)\)/))
    { #  C$$code        0x00000000      0x210 ./build/MT6572_DEMO_TDD128HSPA/DEFAULT/bin/lib/libsys_drv.a(bootarm_gcc.obj)
        my $lib = $3;
        my $obj = $4;
        my $size = $2;
        my $base = $1;
                
        $obj_pad{++$obj_pad_count} = $1;
        $obj_lib_lookup{$1} = [$4,$3];
        &ParseObjLib($strPreExeRegion, $strInput);
        
        if(($strInput =~ /\s+(\S+)\s+(0x\w+)\s+(0x\w+)\s+.*\\(.*)\((.*)\)/) || 
           ($strInput =~ /\s+(\S+)\s+(0x\w+)\s+(0x\w+)\s+.*\/(.*)\((.*)\)/))
        {#  C$$code        0x00000000      0x210 ./build/MT6572_DEMO_TDD128HSPA/DEFAULT/bin/lib/libsys_drv.a(bootarm_gcc.obj)
            push(@sections, $1);
            _UpdateRORWZISize($strPreExeRegion, $base, $obj, $lib, $size);
        }
        elsif(($strInput =~ /^\s+(0x\w+)\s+(0x\w+)\s+.*\\(.*)\((.*)\)/) || 
              ($strInput =~ /^\s+(0x\w+)\s+(0x\w+)\s+.*\/(.*)\((.*)\)/))
        {# .debug_aranges
         #               0x00000000       0x20 ./build/MT6589_MD2_TDD128HSPA/SKYPA/bin/lib/libsys_drv.a(bootarm_gcc.obj)
            if(defined $strPreInputSection)
            {
                push(@sections, $strPreInputSection);
                _UpdateRORWZISize($strPreExeRegion, $base, $obj, $lib, $size);
                $strPreInputSection = undef;
            }
        }
    }
    elsif ($strInput =~ /(0x\w+)\s+(0x\w+)\s+linker stubs/)
    {
        &ParseObjLib($strPreExeRegion, $strInput);
        _UpdateRORWZISize($strPreExeRegion, $1, "*stub*", undef, $2);
    }
    elsif($strInput =~ /\*fill\*\s+(0x\w+)\s+(0x\w+)/)
    {
        $obj_pad{++$obj_pad_count} = $1;
        push(@pad, $obj_pad_count);
        _UpdateRORWZISize($strPreExeRegion, $1, "*fill*", undef, $2);
    }                     
    return $strPreInputSection;
}

sub _UpdateRORWZISize
{
    my ($strPreExeRegion, $base, $obj, $lib, $size) = @_;
    $lib = $obj if(!defined $lib);
    my $key = $strPreExeRegion."-".$obj;
    my $objkey = $obj."-".$lib;

    if($strPreExeRegion =~ /^\.debug/)
    {
        _UpdateSize(\%obj_debuginfo, $obj, $size);
        _UpdateSize(\%lib_debuginfo, $lib, $size);
    }
    elsif(isZI($strPreExeRegion))
    {
        return if($base eq "0x00000000");
        _UpdateSize(\%OBJ_ZI_Size, $obj, $size);
        _UpdateSize(\%LIB_ZI_Size, $lib, $size);
        _UpdateSize(\%region_OBJ_ZI_Size, $key, $size);
        _UpdateSize(\%obj_size, $objkey, $size);   
    }
    elsif(isRW($strPreExeRegion))
    {
        return if($base eq "0x00000000");
        _UpdateSize(\%OBJ_RW_Size, $obj, $size);
        _UpdateSize(\%LIB_RW_Size, $lib, $size);
        _UpdateSize(\%region_OBJ_RW_Size, $key, $size);
        _UpdateSize(\%obj_size, $objkey, $size);   
    }
    elsif(isRO($strPreExeRegion))
    {
    #neet to skip 
    # .rodata.str1.1
    #            0x00000000        0x3 ./build/MT6589_MD2_TDD128HSPA/SKYPA/bin/lib/libtst.a(tst_spare_ram_logging.obj)
        return if($base eq "0x00000000" and $obj !~ /bootarm/i);
        _UpdateSize(\%OBJ_RO_Size, $obj, $size);
        _UpdateSize(\%LIB_RO_Size, $lib, $size);
        _UpdateSize(\%region_OBJ_RO_Size, $key, $size);
        _UpdateSize(\%obj_size, $objkey, $size);
    }
    ParseInputSection($strPreExeRegion, $obj, $lib, $size);
}

sub isZI
{
    my ($strRegionName) = @_;
    my $bRet = ($strRegionName =~ /ZI|\.bss/);
    return $bRet;
}
sub isRW
{
    my ($strRegionName) = @_;
    my $bRet = 0;
    $bRet = 1 if(!isZI($strRegionName) and $strRegionName =~ /EXTSRAM|PAGE_TABLE|DATA|RW/);
    return $bRet;
}
sub isRO
{
    my ($strRegionName) = @_;
    my $bRet = 0;
    $bRet = 1 if(!isZI($strRegionName) and !isRW($strRegionName) 
                and ($strRegionName !~/\.ARM\.attributes|\.comment|\.debug|\.stab/));
    return $bRet;
}

sub _ParseSymbol
{
    my ($strInput, $strPreSymbolName) = @_;
    if ($strInput =~ /(\S+)\s+.*[\/|\\](.*)\((.*)\)/)
    {
        $strPreSymbolName = $1;
        my @obj_lib = [$2,$3];
        push(@{$parent_of_symbol{$1}}, @obj_lib);
        push(@{$parent_obj_of_symbol{$1}}, $3);
        push(@{$parent_lib_of_symbol{$1}}, $2);
    }
    elsif ($strInput =~ /\s+.*[\/|\\](.*)\((.*)\)/)
    {
        my @obj_lib = [$1,$2];
        push(@{$parent_of_symbol{$strPreSymbolName}}, @obj_lib);
        push(@{$parent_obj_of_symbol{$strPreSymbolName}}, $2);
        push(@{$parent_lib_of_symbol{$strPreSymbolName}}, $1);
    }
    return ($strPreSymbolName, $parent_of_symbol{$1} );
}


sub ListAllSections
{
    my %count;
    my @uni_sections = grep { ++$count{ $_ } < 2; } @sections; 
    return \@uni_sections;
}
#****************************************************************************
# subroutine:  ListAllLoadRegion (not support this function)
# input:       N/A
# output:      N/A
#****************************************************************************
sub ListAllLoadRegion
{
    return undef;
}

#****************************************************************************
# subroutine:  ListPadInfo
# input:       N/A
# output:      array reference
#              for map file, array content:[array1,array2,...]
#                            array1:[strPadBaseAddress,[strPreObjName,strPreLibName],strPreObjAddress,[strPostObjName,strPostLibName],strPostObjAddress]
#****************************************************************************
sub ListPadInfo
{
	my @padstring;
	foreach my $temp(@pad)
	{
		my $pad_address = $obj_pad{$temp};
		my $previous = $obj_pad{$temp - 1};
		my $post = $obj_pad{$temp + 1};
		my @pre_obj = $obj_lib_lookup{$previous};
		my @post_obj = $obj_lib_lookup{$post};
		# next if(!$pad_address);
		my @padinfo = [$pad_address,@pre_obj,$previous,@post_obj,$post];
		push (@padstring, @padinfo);
	}
	return \@padstring;
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
    my $file = $strPath."\\MapParser_Temp.dat";
    my %tempfile;
    $tempfile{"parent_reference"} = \%parent_of_symbol;
    $tempfile{"parent_obj_reference"} = \%parent_obj_of_symbol;
    $tempfile{"parent_lib_reference"} = \%parent_lib_of_symbol;
    $tempfile{"veneer"} = \@veneers;
    $tempfile{"obj_in_exeregion"} = \%region_contained_obj;
    $tempfile{"lib_in_exeregion"} = \%region_contained_lib;
    $tempfile{"obj_by_lib"} = \%contained_obj;
    $tempfile{"lib_by_obj"} = \%related_lib;
    
    lock_nstore \%tempfile, $file;
}

#****************************************************************************
# subroutine:  ParseObjLib
# input:       Execution Region Name, $strLine
# output:      N/A 
#****************************************************************************
sub ParseObjLib
{
    my ($strPreExeRegion, $strLine) = @_;
    if (($strPreExeRegion !~ /\.ARM\.attributes/) and ($strPreExeRegion !~ /\.comment/) 
    and ($strPreExeRegion !~ /^\.debug/) and ($strPreExeRegion !~ /^\.stab/))
    {
        if ((/(0x\w+)\s+(0x\w+)\s+.*\\(.*)\((.*)\)/) || (/(0x\w+)\s+(0x\w+)\s+.*\/(.*)\((.*)\)/))
        {
            my $lib = $3;
            my $obj = $4;
            $contained_obj{$lib}{$obj} = 1;
            $related_lib{$obj}{$lib} = 1;            
        }
        elsif(/(0x\w+)\s+(0x\w+)\s+linker stubs/)
        {## C$$code.stub   0x7000a258        0x8 linker stubs
            push (@veneers, [$strPreExeRegion, $1, hex($2)]);
        }
    }
}

#****************************************************************************
# subroutine:  ParseInputSection
# input:       Execution Region Name, $strLine
# output:      N/A
#****************************************************************************
sub ParseInputSection
{
    my ($strExeRegionName, $obj, $lib, $size) = @_;
    return if(!defined $strExeRegionName);    ### setting for $strExeRegionName = undef
    
    $region_contained_obj{$strExeRegionName}{$obj} = 1;
    $region_contained_lib{$strExeRegionName}{$lib} = 1;
    
    my $obj_key = $strExeRegionName."-".$obj."-".$lib;
    my $lib_key = $strExeRegionName."-".$lib;
    _UpdateSize(\%region_obj_size, $obj_key, $size);
    _UpdateSize(\%region_lib_size, $obj_key, $size);
}
sub GetDiscardSymbol
{
    my ($discard_href) = @_;
    %$discard_href = %g_discard_symbols;
}


#****************************************************************************
# subroutine:  GetParentOfSymbol
# input:       Execution Region Name, flag (all/lib/obj)
# output:      (Object Name, Library Name) which refers to given symbol (flag = all)
#              Object Name which refers to given symbol (flag = obj)
#              Library Name which refers to given symbol (flag = lib)
#****************************************************************************
sub GetParentOfSymbol
{   
    # Name          Size      VMA       LMA       File off  Algn
    my ($strSymName, $flag) = @_;
    
    my $parent_array;
    if($flag eq "all")
    {
        $parent_array = $parent_of_symbol{$strSymName};
    }
    elsif($flag eq "lib")
    {
        $parent_array = $parent_lib_of_symbol{$strSymName};
    }
    elsif($flag eq "obj")
    {
        $parent_array = $parent_obj_of_symbol{$strSymName};
    }
    return $parent_array;
}

#****************************************************************************
# subroutine:  GetChildOfSymbol
# input:       symbol name
# output:      undef(not support this function)
#****************************************************************************
sub GetChildOfSymbol
{
    my ($strSymbolName) = @_;
    return undef;
}

#****************************************************************************
# subroutine:  ListObjByLib
# input:       Library Name
# output:      Objects array reference
#****************************************************************************
sub ListObjByLib
{
    my ($lib_name) = @_;
    my @obj_array = keys %{$contained_obj{$lib_name}};
    return \@obj_array;
}

#****************************************************************************
# subroutine:  ListLibByObj
# input:       Object Name
# output:      Library array reference
#****************************************************************************
sub ListLibByObj
{
    my ($obj_name) = @_;
    my @lib_array = keys %{$related_lib{$obj_name}};
    return \@lib_array;
}

#****************************************************************************
# subroutine:  GetTotalSizeByObj
# input:       Object Name, Library Name
# output:      Total size of given object
#              (excluding size in .comment, .ARM.attribut, 
#               execution region which begins with .debug or .stab)
#****************************************************************************
sub GetTotalSizeByObj
{
    my ($obj_name, $lib_name) = @_;
    my $key = $obj_name."-".$lib_name;
    my $obj_size = $obj_size{$key};
    return $obj_size;
}

#****************************************************************************
# subroutine:  GetTotalSizeByLib
# input:       Library Name
# output:      Total size of given library 
#              (excluding size in .comment, .ARM.attribut, 
#               execution region which begins with .debug or .stab)
#****************************************************************************
sub GetTotalSizeByLib
{
    my ($lib_name) = @_;
    my $obj_array = $contained_obj{$lib_name};
    foreach my $temp (@$obj_array)
    {
        my $strObjSize = CommonUtil::Dec2Hex($obj_size{$temp});
        _UpdateSize(\%lib_size, $lib_name, $strObjSize);
    }
    return $lib_size{$lib_name};
}

#****************************************************************************
# subroutine:  GetObjByExeRegion
# input:       Execution Region Name
# output:      objects which given execution region contains
#****************************************************************************
sub GetObjByExeRegion
{
    my ($strExeRegionName) = @_;
    my @obj_array = keys %{$region_contained_obj{$strExeRegionName}};
    return \@obj_array;
}

#****************************************************************************
# subroutine:  GetLibByExeRegion
# input:       Execution Region Name
# output:      libraries which given execution region contains
#****************************************************************************
sub GetLibByExeRegion
{
    my ($strExeRegionName) = @_;
    my @lib_array = keys %{$region_contained_lib{$strExeRegionName}};
    return \@lib_array;
}

#****************************************************************************
# subroutine:  GetObjSizeByExeRegion
# input:       ExeRegion Name, Object Name, Library Name
# output:      size of object in given execution region
#****************************************************************************
sub GetObjSizeByExeRegion
{
    my ($strExeRegion, $strObj, $strLib) = @_;
    my $string = $strExeRegion."-".$strObj."-".$strLib;
    my $obj_size = $region_obj_size{$string};
    return $obj_size;
}

#****************************************************************************
# subroutine:  GetLibSizeByExeRegion
# input:       ExeRegion Name, Library Name
# output:      size of library in given execution region 
#****************************************************************************
sub GetLibSizeByExeRegion
{
    my ($strExeRegion, $strLib) = @_;
    my $string = $strExeRegion."-".$strLib;
    my $lib_size = $region_lib_size{$string};
    return $lib_size;
}

#****************************************************************************
# subroutine:  GetObjSizeByCatExeRegion
# input:       $strRegionName: Execution Name (Case sensitive)
#              $strCategory: RO/RW/ZI (Case sensitive)
# output:      ObjCateSize Hash Reference
#****************************************************************************
sub GetObjSizeByCatExeRegion
{
    my ($strERName, $strCategory) = @_;
    my %ObjSize; # {strObjName} => Size 
    
    my $included_obj_aref = &GetObjByExeRegion($strERName);
    my $region_OBJ_href = undef;
    $region_OBJ_href = \%region_OBJ_ZI_Size if(isZI($strERName) and $strCategory =~ /ZI/i);
    $region_OBJ_href = \%region_OBJ_RW_Size if(isRW($strERName) and $strCategory =~ /RW/i);
    $region_OBJ_href = \%region_OBJ_RO_Size if(isRO($strERName) and $strCategory =~ /RO/i);
    
    if(defined $region_OBJ_href)
    {
        foreach my $temp(@$included_obj_aref)
        {
            my $key = $strERName."-".$temp;
            if(exists $region_OBJ_href->{$key})
            {
                $ObjSize{$temp} = $region_OBJ_href->{$key};
            }
            else
            {
                $ObjSize{$temp} = 0;
            }
        }
    }
    return \%ObjSize;
}

#****************************************************************************
# subroutine:  GetVeneerInfo
# input:       N/A
# output:      [Execution Region, Base Address, Size] list for veneer
#****************************************************************************
sub GetVeneerInfo
{
    return \@veneers;
}

#****************************************************************************
# subroutine:  ListObjLibBySymbol
# input:       $SymName: Symbol Name (Case sensitive)
# output:      undef(not support this function)
#****************************************************************************
sub ListObjLibBySymbol
{
    my ($SymName) = @_;
    return undef;
}

#****************************************************************************
# subroutine:  GetLoadRegionInfo - Get Load Region information
# input:       N/A
# output:      undef(not support this function)
#****************************************************************************
sub GetLoadRegionInfo
{
    return undef;
}

#****************************************************************************
# subroutine:  GetTotalROSize - Get total RO size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      undef(not support this function)
#****************************************************************************
sub GetTotalROSize
{
    my ($bNeedString) = @_;
    return undef;
}

#****************************************************************************
# subroutine:  GetTotalRWZISize - Get total RWZI size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      undef(not support this function)
#****************************************************************************
sub GetTotalRWZISize
{
    my ($bNeedString) = @_;
    return undef;
}

#****************************************************************************
# subroutine:  GetTotalROMSize - Get total ROM size
# input:       $bNeedString: 1=Return string, 0/default/no input=Return int
# output:      undef(not support this function)
#****************************************************************************
sub GetTotalROMSize
{
    my ($bNeedString) = @_;
    return undef;
}

#****************************************************************************
# subroutine:  GetObjDebugInfoSize
# input:       $strObjName: Obj Name (Case sensitive)
# output:      debug info size for given obj
#****************************************************************************
sub GetObjDebugInfoSize
{
    my ($strObjName) = @_;
    my $DebugInfoSize = $obj_debuginfo{$strObjName};
    return $DebugInfoSize;
}

#****************************************************************************
# subroutine:  ListObjSummaryInfo
# input:       obj name, flag represents which column to show
#                        flag = "RO"
#                             = "RW"
#                             = "ZI"
#                             = "Debug"
# output:      RO/RW/ZI/Debug size for given obj
#****************************************************************************
sub ListObjSummaryInfo
{
    my ($strName, $flag) = @_;
    my $nSize = 0;
    if ($flag =~ /RO/i)
    {
        $nSize =  $OBJ_RO_Size{$strName};
    }
    elsif ($flag =~ /RW/i)
    {
        $nSize =  $OBJ_RW_Size{$strName};
    }
    elsif ($flag =~ /ZI/i)
    {
        $nSize =  $OBJ_ZI_Size{$strName};
    }
    elsif ($flag eq "Debug")
    {
        $nSize = $obj_debuginfo{$strName};
    }
    return $nSize;
}

#****************************************************************************
# subroutine:  ListLibSummaryInfo
# input:       lib name, flag represents which column to show
#                        flag = "RO"
#                             = "RW"
#                             = "ZI"
#                             = "Debug"
# output:      RO/RW/ZI/Debug size for given lib
#****************************************************************************
sub ListLibSummaryInfo
{
    my ($strLibName, $flag) = @_;
    my $nSize = 0;
    if ($flag =~ /RO/i)
    {
        $nSize =  $LIB_RO_Size{$strLibName};
    }
    elsif ($flag =~ /RW/i)
    {
        $nSize =  $LIB_RW_Size{$strLibName};
    }
    elsif ($flag =~ /ZI/i)
    {
        $nSize =  $LIB_ZI_Size{$strLibName};
    }
    elsif ($flag eq "Debug")
    {
        $nSize = $lib_debuginfo{$strLibName};
    }
    return $nSize;
}
