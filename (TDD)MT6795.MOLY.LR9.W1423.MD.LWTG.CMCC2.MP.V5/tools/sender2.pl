use Net::FTP;
$ftp = Net::FTP->new("10.15.10.34", Debug => 0) or die "Cannot connect to RD3 ftp: $@";
$ftp->login("rd3build",'xu06z8dkrd3') or die "Cannot login ", $ftp->message;
$ftp->binary or die "Can not change to binarry mode\n";
if(!-e $ARGV[0]){
  die "Can not find file:".$ARGV[0]."\n";
}
$ftp->put("$ARGV[0]") or die "Upload failed ", $ftp->message;
$ftp->quit;

exit 0;
