#! /usr/bin/awk -f

# calculating sum
{ sum += $0 }

# print sum
END { print sum }