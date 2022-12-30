#!/usr/bin/awk -f

# initializing sum
BEGIN {
  current_count = 0 ;
}

# when white space is encountered
NF == 0 {
  print current_count ;
  current_count = 0 ;
  next ;
}

# adding to current_count
{ current_count += $0 }

# ending with final current_count
END {
	print current_count ;	
}