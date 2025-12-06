import sys

def invalid(x):
    x = str(x)
    xlen = len(x)
    for k in range(1, xlen):
        if xlen % k == 0:
            sz = xlen // k
            if sz >= 2 and x[:k] * sz == x:
                return True
            
    return False

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
