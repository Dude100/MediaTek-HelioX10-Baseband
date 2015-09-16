use strict;
BEGIN { push @INC, './tools/', './tools/MemoryUtility/' }  # add additional library path         
use SymFileParser;

package Parsing_DSP_array;


return 1;

sub getDSPsymbol{

my $MAIN_SYM_FILE = shift;
my $FLAG_SYM_NAME = shift;
my $SYM_NAME = shift;

        SymFileParser::ParseSYM($MAIN_SYM_FILE);


        my  $symbol_ref = SymFileParser::GetSymbol();

        if( defined $symbol_ref->{$FLAG_SYM_NAME} && 
            defined $symbol_ref->{$SYM_NAME} )
        {
            #print   map {$_." "} @{$symbol_ref->{$SYM_NAME}};
            #print "\n";

            my $addr = @{$symbol_ref->{$SYM_NAME}}[Symbol::Addr];
            my $size = @{$symbol_ref->{$SYM_NAME}}[Symbol::Size];

            return (hex($addr), hex($size));

        }
        else
        {
            #print "NO~~\n";
            return (0xCDCDCDAA, 0x0);
        }

}
