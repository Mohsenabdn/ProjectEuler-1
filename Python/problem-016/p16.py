import time

start = time.time()

a = str(2**1000)
total = 0
for i in a:
    total = total + int(i)


print(total)
print(time.time()-start)
