import sys

n, k = sys.stdin.readline().split()
n = int(n)
k = int(k)
yc = sys.stdin.readline().split()

i = 0
result = ''

while i < 2 * n + 1:
    if i % 2 == 1:
        if k > 0 and int(yc[i]) - 1 > int(yc[i-1]) and int(yc[i])-1 > int(yc[i+1]):
            result = result + str(int(yc[i]) - 1)
            k = k - 1
        else:
            result = result + yc[i]
    else:
        result = result + yc[i]
    if i < 2 * n:
        result += ' '
    i += 1

print result
