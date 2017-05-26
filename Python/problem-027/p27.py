import time
start = time.time()

def isprime(no):
    if no <2: return 'n'
    for i in range(2,int(no**0.5)+1):
        if no%i == 0:return 'n'
    return 'y'

def howmany(a,b):
    n = 0
    val = b
    while isprime(val) == 'y':
        val = n**2+a*n+b
        n+=1
    return(n-1)

count = 0
for i in range(-999,1000):
    #print(i)
    for j in range(-999,1000):
        if howmany(i,j) > count:
            count = howmany(i,j)
            pro,nopro = i,j

print(pro*nopro)
print(time.time()-start)
