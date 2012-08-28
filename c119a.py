def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

win = 0
a, b, n = [int(x) for x in raw_input().split()]
while True:
    win = 0 if win else 1
    if win:
        t = gcd(a, n)
    else:
        t = gcd(b, n)
    n -= t
    if n < 0:
        print win
        break
