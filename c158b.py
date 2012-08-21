n = input()
g = [int(x) for x in raw_input().split()]
three = g.count(3)
two = g.count(2)
one = g.count(1)

r = g.count(4)

r += three
one -= min(one, three)

r += two / 2
if two & 1:
    r += 1
    one -= min(one, 2)

r += one / 4 + (one % 4 > 0)
print r
