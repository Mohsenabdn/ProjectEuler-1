import time
import math

start = time.time()

def div(no):
    counter = 0
    for i in range(1,int(math.sqrt(no))):
        if no%i == 0:
            counter = counter + 1
    if int(math.sqrt(no)) == math.sqrt(no):
        return 2*counter + 1
    else:
        return 2*counter

val = 1
total = 1
while div(total) <= 500:
    val = val + 1
    total = total+ val
    #print(val,total)

print(total)
print(time.time()-start)
