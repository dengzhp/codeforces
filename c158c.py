import os
def resolve(p):
    while True:
        d = p.find('/..')
        if d == -1:
            break
        s = p.rfind('/', 0, d-1)
        p = p[0:s] + p[d+3:]
    return p

n = input()

pwd = '/'
for i in range(n):
    c = raw_input()
    if c == 'pwd':
        print '/' if pwd == '/' else resolve(pwd) + '/'
    else:
        path = c.split()[1]
        if path[0] == '/':
            pwd = path
        else:
            if pwd == '/':
                pwd = pwd + path
            else:
                pwd = pwd + '/' + path
