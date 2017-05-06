import time
start = time.time()

def findsum(high):
  total = 0
  for i in range(high):
    if i%3 == 0 or i%5 == 0:
      total = total + i
  return(total)

print(findsum(1000))

run_time = time.time()-start

print(run_time)
