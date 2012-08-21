n=input()
x=1
while 5*(2**x)-5 < n:
    x += 1
print ["Sheldon","Leonard","Penny","Rajesh","Howard"][(n-(5*(2**(x-1))-5)-1)/(2**(x-1))]
