import time
start = time.time()

fr = open('8.txt','r')
a = fr.readlines()
b=''
for i in a:
    i = i.strip()
    b = b + i
#print(len(b))

dig = 13

def prod(arr):
    prod = 1
    for i in arr:
        prod = prod*int(i)
    return prod

high = 0
for i in range(0,len(b)-dig+1):
    luck = b[i:i+dig]
    if prod(luck) > high:
        high = prod(luck)
    else:
        continue

print(high)
print(time.time()-start)
