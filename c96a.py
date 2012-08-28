s = raw_input()
zero = 0
one = 0
dangerous = False
for c in s:
    if c == '0':
        zero += 1
        one = 0
    else:
        one += 1
        zero = 0
    if zero >= 7 or one >= 7:
        dangerous = True
        break

if dangerous:
    print 'YES'
else:
    print 'NO'
