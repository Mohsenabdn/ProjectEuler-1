import math
import time

start = time.time()
a = int(math.factorial(40)/math.factorial(20)/math.factorial(20))
end = time.time()

print(a)
print(end-start)
