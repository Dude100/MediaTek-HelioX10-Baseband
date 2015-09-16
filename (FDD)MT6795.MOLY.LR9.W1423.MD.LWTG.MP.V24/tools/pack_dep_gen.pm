package tools::pack_dep_gen;
use strict;
use Cwd qw(abs_path);
use Exporter;
use vars qw(@ISA @EXPORT @EXPORT_OK);
@ISA = qw(Exporter);
@EXPORT = qw(PrintDependency PrintDependModule);
@EXPORT_OK = qw(PrintDependency PrintDependModule);

return 1;

sub PrintDependency
{
	my $file = shift;
	if (-e $file)
	{
		$file = abs_path($file);
		print STDERR "[Dependency] $file\n";
	}
}

sub PrintDependModule
{
	my $file = shift;
	if ($file eq "")
	{
		PrintDependency($0);
	}
	else
	{
		PrintDependency($file);
	}
	foreach my $value (values %INC)
	{
		if ($value =~ /[\/\\]Perl([\/\\].*)?[\/\\]lib[\/\\]/i)
		{
			# skip system module
		}
		else
		{
			PrintDependency($value);
		}
	}
}
