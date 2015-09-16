package Parse::CSV;

=pod

=head1 NAME

Parse::CSV - Highly flexible CVS parser for large files

=head1 SYNOPSIS

  # Simple headerless comma-seperated column parser
  my $simple = Parse::CSV->new(
      file => 'file.csv',
      );
  while ( my $array_ref = $simple->fetch ) {
     # Do something...
  }

... or a more complex example...

  # Parse a colon-seperated variables file  from a handle as a hash
  # based on headers from the first line.
  # Then filter, so we emit objects rather than the plain hash.
  my $objects = Parse::CSV->new(
      handle => $io_handle,
      sep_char   => ';',
      fields     => 'auto',
      filter     => sub { My::Object->new( $_ ) },
      );
  while ( my $object = $objects->fetch ) {
      $object->do_something;
  } 

=head1 DESCRIPTION

Surely the CPAN doesn't need yet another CSV parsing module.

L<Text::CSV_XS> is the standard parser for CSV files. It is fast as hell,
but unfortunately it can be a bit verbose to use.

A number of other modules have attempted to put usability wrappers around
this venerable module, but they have all focussed on parsing the entire
file into memory at once.

This method is fine unless your CSV files start to get large. Once that
happens, the only existing option is to fall back on the relatively slow
and heavyweight L<XML::SAXDriver::CSV> module.

L<Parse::CSV> fills this functionality gap. It provides a flexible
and light-weight streaming parser for large, extremely large, or
arbitrarily large CSV files.

=head2 Main Features

B<Stream-Based Parser> - All parsing a line at a time.

B<Array Mode> - Parsing can be done in simple array mode, returning
a reference to an array if the columns are not named.

B<Hash Mode> - Parsing can be done in hash mode, putting the data into
a hash and return a reference to it.

B<Filter Capability> - All items returned can be passed through a
custom filter. This filter can either modify the data on the fly,
or drop records you don't need.

=head2 Writing Filters

A L<Parse::CSV> filter is a subroutine reference that is passed the raw
record as C<$_>, and should C<return> the alternative or modified record
to return to the user.

The null filter (does not modify or drop any records) looks like the
following.

  sub { $_ };

A filter which reversed the order of the columns (assuming they are
passed as an array) might look like the following.

  sub { return [ reverse @$_ ] };

To drop the record, you should return C<undef> from the filter. The
parser will then keep pulling and parsing new records until one
passes the filter.

  # Only keep records where foo is true
  sub { $_->{foo} ? $_ : undef }

To signal an error, throw an exception

  sub {
      $_->{foo} =~ /bar/ or die "Assumption failed";
      return $_;
  }

=head1 METHODS

=cut

use 5.005;
use strict;
use Carp         ();
use IO::File     ();
use Text::CSV_XS ();
use Params::Util qw{ _STRING _ARRAY _HASH0 _CODELIKE _HANDLE };

use vars qw{$VERSION};
BEGIN {
	$VERSION = '1.00';
}





#####################################################################
# Constructor

=pod

=head2 new

The C<new> constructor creates and initialise a new CSV parser.

It takes a number of params.

To specify the CSV data source, you should provide either the C<file>
param, which should be the name of the file to read, or the C<handle>
param, which should be a file handle to read instead.

The actual parsing is done using L<Text::CSV_XS>. Any of it's
constructor/parsing params can also be provided to this C<new> method,
and they will be passed on.

Alternatively, they can be passed as a single C<HASH> reference as the
C<csv_attr> param. For example:

  $parser = Parse::CSV->new(
      file     => 'file.csv',
      csv_attr => {
          sep_char   => ';',
          quote_char => "'",
      },
  );

An optional C<fields> param can be provided, which should be an array
reference containing the names of the columns in the CSV file.

  $parser = Parse::CSV->new(
      file   => 'file.csv',
      fields => [ 'col1', 'col2', 'col3' ],
  );

If the C<fields> param is provided, the parser will map the columns to a
hash where the keys are the field names provided, and the values are the
values found in the CSV file.

If the C<fields> param is B<not> provided, the parser will return simple
array references of the columns.

If the C<fields> param is the string 'auto', the fields will be
automatically determined by reading the first line of the CSV file and
using those values as the field names.

The optional C<filter> param will be used to filter the records if
provided. It should be a C<CODE> reference or any otherwise callable
scalar, and each value parsed (either array reference or hash reference)
will be passed to the filter to be changed or converted into an object,
or whatever you wish.

Returns a new L<Parse::CSV> object, or throws an exception (dies) on error.

=cut

sub new {
	my $class = shift;
	my $self  = bless { @_,
		row    => 0,
		errstr => '',
		}, $class;

	# Do we have a file name
	if ( exists $self->{file} ) {
		unless ( _STRING($self->{file}) ) {
			Carp::croak("Parse::CSV file param is not a string");
		}
		unless ( -f $self->{file} and -r _ ) {
			Carp::croak("Parse::CSV file '$self->{file}' does not exist");
		}
		$self->{handle} = IO::File->new();
		unless ( $self->{handle}->open($self->{file}) ) {
			Carp::croak("Parse::CSV file '$self->{file}' failed to load: $!");
		}
	}

	# Do we have a file handle
	if ( exists $self->{handle} ) {
		unless ( _HANDLE($self->{handle}) ) {
			Carp::croak("Parse::CSV handle param is not an IO handle");
		}
	} else {
		Carp::croak("Parse::CSV not provided a file or handle param");
	}

	# Seperate the Text::CSV attributes
	unless ( _HASH0($self->{csv_attr}) ) {
		$self->{csv_attr} = {};
		foreach ( qw{quote_char eol escape_char sep_char binary always_quote} ) {
			next unless exists $self->{$_};
			$self->{csv_attr}->{$_} = delete $self->{$_};
		}
	}

	# Create the parser
	$self->{csv_xs} = Text::CSV_XS->new( $self->{csv_attr} );
	unless ( $self->{csv_xs} ) {
		Carp::croak("Failed to create Text::CSV_XS parser");
	}

	# Handle automatic fields
	if ( _STRING($self->{fields}) and lc($self->{fields}) eq 'auto' ) {
		# Grab the first line
		my $line = $self->_getline;
		unless ( defined $line ) {
			Carp::croak("Failed to get header line from CSV");
		}

		# Parse the line into columns
		unless ( $self->{csv_xs}->parse($line) ) {
			Carp::croak(
				"Failed to parse header line from CSV: "
				. $self->{csv_xs}->error_input
			);
		}

		# Turn the array ref into a hash if needed
		my @cols = $self->{csv_xs}->fields;
		$self->{fields} = \@cols;
	}

	# Check fields
	if ( exists $self->{fields} and ! _ARRAY($self->{fields}) ) {
		Carp::croak("Parse::CSV fields param is not an array reference of strings");
	}

	# Check filter
	if ( exists $self->{filter} and ! _CODELIKE($self->{filter}) ) {
		Carp::croak("Parse::CSV filter param is not callable");
	}

	$self;
}





#####################################################################
# Main Methods

=pod

=head2 fetch

Once a L<Parse::CSV> object has been created, the C<fetch> method is
used to parse and return the next value from the CSV file.

Returns an C<ARRAY>, C<HASH> or the output of the filter, based on the
configuration of the object, or C<undef> in a variety of situations.

Returning C<undef> means either some part of the parsing and filtering
process has resulted in an error, B<or> that the end of file has been
reached.

On receiving C<undef>, you should the C<errstr> method. If it is a null
string you have reached the end of file. Otherwise the error message will
be returned. Thus, the basic usage of L<Parse::CSV> will look like the
following.

  my $parser = Parse::CSV->new(
      file => 'file.csv',
      );
  while ( my $value = $parser->fetch ) {
      # Do something...
  }
  if ( $parser->errstr ) {
      # Handle errors...
  }

=cut

sub fetch {
	my $self = shift;

	# The filter can skip rows,
	# iterate till we get something.
	while ( defined(my $line = $self->_getline) ) {
		# Parse the line into columns
		unless ( $self->{csv_xs}->parse($line) ) {
			$self->{errstr} = "Failed to parse row $self->{row}";
			return undef;
		}

		# Turn the array ref into a hash if needed
		my $rv   = undef;
		my $f    = $self->{fields};
		my @cols = $self->{csv_xs}->fields;
		if ( $f ) {
			$rv = {};
			foreach ( 0 .. $#$f ) {
				$rv->{ $f->[$_] } = $cols[$_];
			}
		} else {
			$rv = \@cols;
		}

		# Just return for simple uses
		return $rv unless $self->{filter};

		# Filter if needed
		local $_ = $rv;
		$rv = eval { $self->{filter}->() };
		if ( $@ ) {
			# Handle filter errors
			$self->{errstr} = "Filter error: $@";
			$self->{errstr} =~ s/^(.+)at line.+$/$1/;
			return undef;
		}

		# Filter returns undef to drop a record
		next unless defined $rv;

		# We have a good record, return it
		return $rv;
	}

	return undef;
}

sub _getline {
	my $self = shift;
	$self->{errstr} = '';

	# Fetch the next file line
	my $handle = $self->{handle};
	my $line   = <$handle>;
	unless ( defined $line ) {
		$self->{errstr} = $handle->eof ? '' : $!;
		return undef;
	}

	# Parse the line into columns
	$self->{row}++;
	return $line;
}

=pod

=head2 row

The C<row> method returns the current row of the CSV file.

This is a one-based count, so when you first create the parser,
the value of C<row> will be zero (unless you are using
C<fields => 'auto'> in which case it will be 1).

=cut

sub row {
	$_[0]->{row};
}

=pod

=head2 combine

  $status = $csv->combine(@columns);

The C<combine> method is provided as a convenience, and is passed through
to the underlying L<Text::CSV_XS> object.

=cut

sub combine {
	shift->combine(@_);
}

=pod

=head2 string

  $line = $cvs->string;

The C<string> method is provided as a convenience, and is passed through
to the underlying L<Text::CSV_XS> object.

=cut

sub string {
	shift->string(@_);
}

=pod

=head2 print

  $status = $cvs->print($io, $columns);

The C<print> method is provided as a convenience, and is passed through
to the underlying L<Text::CSV_XS> object.

=cut

sub print {
	shift->print(@_);
}

=pod

=head2 errstr

On error, the C<errstr> method returns the error that occured.

If the last action was NOT an error, returns the null string C<''>.

=cut

sub errstr {
	$_[0]->{errstr};
}

1;

=pod

=head1 SUPPORT

Bugs should be always be reported via the CPAN bug tracker at

L<http://rt.cpan.org/NoAuth/ReportBug.html?Queue=Parse-CSV>

For other issues, or commercial enhancement or support, contact the author.

=head1 AUTHORS

Adam Kennedy E<lt>adamk@cpan.orgE<gt>

=head1 SEE ALSO

L<Text::CSV_XS>, L<http://ali.as/>

=head1 COPYRIGHT

Copyright 2006 Adam Kennedy.

This program is free software; you can redistribute
it and/or modify it under the same terms as Perl itself.

The full text of the license can be found in the
LICENSE file included with this module.

=cut
