# File: lucy.pl
# This perl script is to calcualte memory requirement and generate the header file.
# Author: Pibben Tung

use integer; # To make division as C code

my $via_file;
my $dep_file;
my $c_command;

if (scalar(@ARGV) != 2)
{
    my @usage = ();
    push @usage, "\nUsage lucy.pl <via_file> <dep_file>\n";
    die join('', @usage);
}
else
{
    ($via_file, $dep_file) = @ARGV;       
}

# Create lucy.c subject to preprocessing and linking stage
@interface_header = ("./interface/hal/video/video_memory_usage_v2.h", "./interface/hal/video/media_provider_mem_usage.h", "./interface/hal/video/media_session_mem_usage.h");

$declaration = "unsigned int VarVe";

open(VIR_FILE, ">./hal/video/common/src/lucy.c") || die "file open fail!\n";
print VIR_FILE ("// This file is auto generated for memory requirement calculation !!!\n\n");
foreach $headerfile (@interface_header)
{
    my @purefilename;
    @purefilename = split(/\//, $headerfile);
    print VIR_FILE ("#include \"", $purefilename[-1], "\"\n"); # -1 indicates the last element of array
}
print VIR_FILE ("\nvoid main(void) {\n");

foreach $headerfile (@interface_header)
{
    my $matching = 0;
    my $line;
    my $ifdef = "#ifdef";
    my $sdefined = "defined";
    my $endif = "#endif";
    my $define = "#define";
    my $declare;
    
    open(INTERFACE_HEADER_FILE, $headerfile) || die "file open fail!\n";
    while( $line = <INTERFACE_HEADER_FILE> )
    {
        if(($line =~ /^\s*\#if\s+$sdefined/) || ($line =~ /^\s*$ifdef/) || ($line =~ /^\s*\#if\s+\(*$sdefined/))
        {
            print VIR_FILE ($line);
            $matching++;
        }
        
        if($line =~ /^\s*$define\s+\S+\s+\S+/)
        {
            my $assign = " = ";
            
            $declare = $line;
            $declare =~ s/$define\s+/$declaration/;
            
            $declare =~ /$declaration\S*\s+/;
            # $& is the string matched
            $declare =~ s/$&/$&$assign/;
            
            chomp($declare); # chomp is to remove next line character
            print VIR_FILE ($declare, ";\n");
        }
        
        if($line =~ /^\s*$endif/)
        {
            if($matching > 0)
            {
                print VIR_FILE ($line);
                $matching--;                
            }
        }
    }
    
    close(INTERFACE_HEADER_FILE);
}

print VIR_FILE ("}\n");
close(VIR_FILE);

# lucy.c is generated.
# Preprocess lucy.c

$c_command = "armcc --via ".$via_file." -E .\\hal\\video\\common\\src\\lucy.c -o .\\hal\\video\\common\\src\\bunny.c";
system($c_command) && die "Preprocess lucy.c fail !!!\n";

$c_command = "armcc --via ".$via_file." -M .\\hal\\video\\common\\src\\lucy.c > ".$dep_file;
system($c_command) && die "Make dependency of lucy.c fail !!!\n";

# bunny.c is preprocessed lucy.c
open(bunny, "./hal/video/common/src/bunny.c") || die "file bunny.c open fail!\n";

open(VIR_FILE, ">./hal/video/common/src/lucy2.c") || die "file open fail!\n"; # lucy2.c is to put sizeof information

print VIR_FILE ("// This file is auto generated for memory requirement calculation !!!\n\n");
foreach $headerfile (@interface_header)
{
    my @purefilename;
    @purefilename = split(/\//, $headerfile);
    print VIR_FILE ("#include \"", $purefilename[-1], "\"\n"); # -1 indicates the last element of array
}

$filecontent = "\nvoid main(void) {\n";
#print VIR_FILE ("\nvoid main(void) {\n");

%StructToVar;

my $counter = 0;
while( $line = <bunny> )
{
    if($line =~ /\s*$declaration/)
    {
        $filecontent .= $line;
        #print VIR_FILE ($line);

        # find every sizeof(structure)
        while($line =~ /(sizeof\([a-zA-Z0-9_]+\))/g)
        {
            $StructToVar{$&} = "var".$counter;
            $counter++;
        }
    }
}



print VIR_FILE ("\n// Variables to calculate size of structures\n");
foreach $key (keys(%StructToVar))
{
    $key =~ /sizeof\(([a-zA-Z0-9_]+)\)/;
    print VIR_FILE ($1, " ", $StructToVar{$key}, ";\n");
}

print VIR_FILE ($filecontent);

print VIR_FILE ("\n// To make variables appear in symbol file\n");
foreach $key (keys(%StructToVar))
{
    $key =~ /sizeof\(([a-zA-Z0-9_]+)\)/;
    print VIR_FILE ("memset(&", $StructToVar{$key}, ", 1, ", $key, ");\n");
}

print VIR_FILE ("}\n");
close(VIR_FILE);
close(bunny);

# lucy2.c is generated. (including sizeof variables)

$c_command = "armcc --via ".$via_file." .\\hal\\video\\common\\src\\lucy2.c";
system($c_command) && die "Compile lucy2.c fail !!!\n";
system("armlink --symbols .\\lucy2.o > .\\lucy2.sym") && die "Link lucy2.o fail !!!\n";;

open(symbol, "./lucy2.sym") || die "file lucy.sym open fail!\n";
%VarToSize;
while( $line = <symbol> )
{
	my $data = "Data";
	my $lucydoto = "lucy2.o";
	
	if($line =~ /^\s*([a-zA-Z0-9_]+).*$data\s+(\d+)\s+$lucydoto/)
	{
      #print ($1, "\t", $2, "\n");
      $VarToSize{$1} = $2;
	}
}
close(symbol);

open(header, "./hal/video/common/src/lucy2.c") || die "file open fail!\n";
open(AUTO_GEN_HEADER, ">./interface/hal/video/video_mem_gen.h") || die "file open fail!\n";

my $header_file_begin_text = "";
$header_file_begin_text .= "/* This video memory requirements header is Auto Generated.\nAccording to:\n";
foreach $headerfile (@interface_header)
{
    my @purefilename;
    $header_file_begin_text .= $headerfile."\n";
}
$header_file_begin_text .= "*/\n";
print AUTO_GEN_HEADER ($header_file_begin_text);

while( $line = <header> )
{
    if($line =~ /\s*$declaration/)
    {
        my $expression;
        my $null = "";
        my $structsize;
        
        ($define, $expansion) = split(/=/, $line);
        $define =~ s/$declaration/$null/; # s/old-regex/new-string/
        
        # replace sizeof(.) to number in expansion
        $expression = $expansion;
        
        while($expression =~ /sizeof\([a-zA-Z0-9_]+\)/g)
        {
            $structsize = $VarToSize{$StructToVar{$&}};
            $expression =~ s/sizeof\([a-zA-Z0-9_]+\)/$structsize/; # why $& is not working?
        }

        #print("\n", $expression);
        $value = eval($expression);
        print AUTO_GEN_HEADER ("#define ", $define, "  ", $value, " //", $expression);
    }
}
close(AUTO_GEN_HEADER);
close(header);
