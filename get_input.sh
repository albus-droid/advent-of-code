#!/usr/bin/env sh

# Prompt for year and day input
echo "Enter the year:"
read year
echo "Enter the day:"
read day

# Construct the URL based on the year and day input
url="https://adventofcode.com/$year/day/$day/input"

#Reading cookie from Lynx.trace
cookie_string=$(grep -i 'session' Lynx.trace | sed -e 's/^Cookie: //' -e 's/;.*$//' -e 's/^.*session=//' | tr -d '\\r' | tail -n 1)

#Checking if folder exists, if not make one
if [ ! -d "${year}/day${day}" ]; then
   mkdir -p "${year}/day${day}" 
   echo "Dont exist"
fi

# Send the curl request with the session cookie and save it to a file
curl -H "Cookie: session=$cookie_string" "$url" -o "${year}/day${day}/input.txt"

# Check if curl succeeded and provide feedback
if [ $? -eq 0 ]; then
  echo "Successfully downloaded the input for Year $year, Day $day."
else
  echo "Failed to download the input. Please check your session cookie and the URL."
fi

