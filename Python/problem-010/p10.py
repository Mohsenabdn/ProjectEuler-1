import math
import time
start = time.time()


def isprime(no):
    for i in range(3,int(math.sqrt(no))+1,2):
        if no%i == 0:
            return 'n'
    return 'y'


total = 0
ultimate = 2000000

for i in range(3,ultimate,2):
    if isprime(i) == 'y':
        total = total + i

actual_total = total + 2

print(actual_total)
print(time.time() - start)
