use strict;
BEGIN { push @INC, '../', './tools/', './tools/MemoryUtility/' }
use MapFileParser;

my ($option, $file1, $file2) = @ARGV;

if(($option eq "-Q") || ($option eq "-q"))
{
    MapFileParser::ParseMAP($file1);
    my %discard;
    MapFileParser::GetDiscardSymbol(\%discard);
    ListDiscardedSymbols(\%discard);
}
elsif(($option eq "-C") || ($option eq "-c"))
{
    MapFileParser::ParseMAP($file1);
    my %discard1;
    MapFileParser::GetDiscardSymbol(\%discard1);
    
    MapFileParser::ParseMAP($file2);
    my %discard2;
    MapFileParser::GetDiscardSymbol(\%discard2);
    
    DiffDiscardedSymbols(\%discard1, \%discard2);
}




sub ListDiscardedSymbols
{
    my ($DiscardSym_href) = @_;
    print "SymbolName                                                                                  Size            \n";
    print "*********************************************************************************************************************\n";
    foreach my $key (sort keys %$DiscardSym_href)
    {
         $~ = "AAA";
        format AAA =
@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    @<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
$key,$DiscardSym_href->{$key}
.
write;
    }
}


sub DiffDiscardedSymbols
{
    my ($DiscardSym1_href, $DiscardSym2_href) = @_;
    my %CompareDiscard;
    foreach my $key1 (sort keys %$DiscardSym1_href)
    {
        $CompareDiscard{$key1} = [$DiscardSym1_href->{$key1}, ""];
    }
    foreach my $key2 (keys %$DiscardSym2_href)
    {
        if(!exists $CompareDiscard{$key2})
        {
            $CompareDiscard{$key2} = ["", $DiscardSym2_href->{$key2}];
        }
        else
        {
            $CompareDiscard{$key2}->[1] = $DiscardSym2_href->{$key2};
        }
    }
    print "   $file1 \nvs. $file2\n";
    print "Size1          Size2       SymbolName                                                                \n";
    print "*********************************************************************************************************************\n";
    my ($nTotalSize1, $nTotalSize2) = (0,0);
    foreach my $key (sort keys %CompareDiscard)
    {
#        print $key, $CompareDiscard{$key}->[0] ,  $CompareDiscard{$key}->[1] ."\n";
        next if($CompareDiscard{$key}[0] eq $CompareDiscard{$key}[1]);
        $nTotalSize1 += $CompareDiscard{$key}[0];
        $nTotalSize2 += $CompareDiscard{$key}[1];
        $~ = "SYMBOLS";
        format SYMBOLS =
@<<<<<<<<<<<<@<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
$CompareDiscard{$key}[0],$CompareDiscard{$key}[1],$key
.
write;
    }
    print "*********************************************************************************************************************\nTotal\n";
    $~ = "TOTALDIFF";
    format TOTALDIFF = 
@<<<<<<<<<<<<@<<<<<<<<<<<<
$nTotalSize1,$nTotalSize2
.
write;
}