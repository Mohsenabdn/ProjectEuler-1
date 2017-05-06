import time
start = time.time()

def lcm(a,b):
    for i in range(b,a*b+1,b):
        #print (i)
        if i%a == 0:
            #print(i)
            return i

hello = list(range(2,21))
no = hello[0]
for i in hello:
    no = lcm(i,no)
print (no)

print(time.time()-start)
