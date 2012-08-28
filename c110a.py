s = raw_input()
ss = set(str(s.count('4') + s.count('7')))
lucky = True
for c in ss:
    if c not in '47':
        lucky = False
        break
if lucky:
    print 'YES'
else:
    print 'NO'
