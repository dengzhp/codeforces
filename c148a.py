def gcd(a, b):
    if b==0:
        return a
    return gcd(b, a%b)

def lcm(*a):
    if len(a) > 2:
        return lcm(a[0], lcm(*a[1:]))
    else:
        return a[0]/gcd(a[0], a[1])*a[1]

k,l,m,n,d=[input() for x in (0,)*5]
r =  d/k+d/l+d/m+d/n
r = r - d/lcm(k,l)-d/lcm(l,m)-d/lcm(m,n)-d/lcm(k,m)-d/lcm(k,n)-d/lcm(l,n)
r = r + d/lcm(k,l,m) + d/lcm(k,l,n) + d/lcm(l,m,n) + d/lcm(k,m,n)
r = r - d/lcm(k,l,m,n)
print r
