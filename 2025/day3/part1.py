import sys

D = sys.stdin.read()

sum = 0

for line in D.splitlines():
    max = 0
    for i in range(len(line)):
        for j in range(i + 1, len(line)):
            score = int(line[i] + line[j])
            if max == 0 or score > max:
                max = score
    sum += max

print("The sum is ", sum)
