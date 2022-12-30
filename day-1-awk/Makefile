
part1: input.txt count-calorie.awk
	awk -f count-calorie.awk < input.txt | sort -rn | head -1

part2: input.txt calorie-count.awk
	awk -f count-calorie.awk < input.txt | sort -rn | head -3 | awk -f sum-calorie.awk
