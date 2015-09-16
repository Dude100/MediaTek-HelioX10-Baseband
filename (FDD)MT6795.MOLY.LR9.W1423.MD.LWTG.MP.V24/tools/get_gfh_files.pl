my $folder_path = $ARGV[0];
my $file_postfix = $ARGV[1];

my $strFileList;
if(-d $folder_path)
{
  print "[BIN FOLDER]\n";
  opendir (DIR, $folder_path) or die "Error: cannot open folder: $folder_path";
  @files = grep {/.+_GFH/i}  readdir DIR;
  close DIR;
  
  foreach (@files)
  {
    $ori_name = $_;
    $_ =~ s/_GFH//i;
    rename("$folder_path/$ori_name", "$folder_path/$_") or die "Error: fail to rename $ori_name to $_\n";
    $strFileList .= "$folder_path/$_\n";
  }

}
else
{
  print "[BIN FILE]\n";
  $strFileList .= "$folder_path\n";
}

print $strFileList;
exit 0;
