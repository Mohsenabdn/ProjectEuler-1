import time
start = time.time()

import itertools
a = '0123456789'
count = 0
for i in itertools.permutations(a):
    if count == 1000000-1:
        yele = i
        break
    else:
        count+=1

yele = ''.join(yele)
print(yele)
print(time.time()-start)
