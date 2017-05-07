import time
start = time.time()

val = 0
vals = 0

for i in range(1,101):
    val = val + i
    vals = vals + i*i
    #print(i,val,vals)
print (val**2-vals)

print(time.time()-start)
