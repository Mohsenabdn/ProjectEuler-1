import time
import math

start = time.time()

def isprime(a):
    for i in range(2,int(math.sqrt(a))+1):
        if a%i== 0:
            return 'n'
    else:
        return 'y'
count = 0
i = 2
while count < 10001:
    if isprime(i) == 'y':
        count+=1
        #print(count,i)
    i+=1

print(i-1)
print(time.time()-start)
