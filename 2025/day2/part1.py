import sys

def invalid(x):
    x = str(x)
    return len(x) % 2 == 0 and x[:len(x)//2] == x[len(x)//2:]

D = sys.stdin.read()
sum = 0

ranges = D.split(',')
for r in ranges:
    first,last = r.split('-')
    first = int(first)
    last = int(last)

    for x in range(first, last + 1):
        if invalid(x):
            sum += x

print("The sum is ", sum)
