import sys

def find_digits(line, n, used):
   if n >= len(line) and used >= 12:
      return 0      # early return 

   if n == len(line):
       return -10**20

   key = (n, used)
   if key in DP:
       return DP[key]

   result = find_digits(line, n + 1, used)
   if used < 12:
       result = max(result, 10**(11 - used)*int(line[n]) + find_digits(line, n + 1, used + 1))

   DP[key] = result
   return DP[key]

D = sys.stdin.read()

sum = 0

for line in D.splitlines():
    DP = {}
    sum += find_digits(line, 0, 0) 

print("The sum is ", sum)
