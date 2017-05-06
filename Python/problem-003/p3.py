import math
import time

start = time.time()

def findfact(num):
    current_max = 1
    for i in range(int(math.sqrt(num))):
        if i == 0:
            continue
        else:
            if num%i == 0 and isprime(i) == 'y':
                current_max = i
    return current_max


def isprime(num):
    counter = 0
    for i in range(int(math.sqrt(num))):
        if i == 0:
            continue
        else:
            if num%i == 0:
                counter = counter + 1
    if counter == 1:
        return 'y'
    else:
        return 'n'

print(findfact(600851475143))

run_time = time.time()-start
print(run_time)
