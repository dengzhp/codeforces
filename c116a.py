n=input()
p = []
for i in range(n):
    p.append([int(x) for x in raw_input().split()])
c = 0
m = 0
for i in range(n):
    c = c - p[i][0] + p[i][1]
    m = max(m, c)
print m
