#!/usr/bin/env sh

# Prompt for year and day input
echo "Enter the year:"
read year
echo "Enter the day:"
read day

# Construct the URL based on the year and day input
url="https://adventofcode.com/$year/day/$day/input"

# Minimal cookie string (just the session cookie)
cookie_string="53616c7465645f5f99050a86adc77b633ff112324662b42087cc371b927c23bc04332400dc56e96fbdec5e37489ae9b5904393ec38df4c1c3e451b09184d060e"

# Send the curl request with the session cookie and save it to a file
curl -H "Cookie: session=$cookie_string" "$url" -o "${year}_${day}_input.txt"

# Check if curl succeeded and provide feedback
if [ $? -eq 0 ]; then
  echo "Successfully downloaded the input for Year $year, Day $day."
else
  echo "Failed to download the input. Please check your session cookie and the URL."
fi

