import math
import time
start = time.time()


for i in range(1000):
    for j in range(1000):
        k = math.sqrt(i**2+j**2)
        if i+j+k == 1000 and i*j*k != 0:
            product = i*j*k;
            break

print(int(product))
print(time.time() - start)
