import time
start = time.time()

import math
total=0
for i in str(math.factorial(100)): total+=int(i)

print(total)
print(time.time()-start)
