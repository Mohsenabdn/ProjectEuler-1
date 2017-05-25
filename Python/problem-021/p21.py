import time

start = time.time()


def factsum(no):
    total = 0
    for i in range(1,no):
        if no%i == 0:total+=i
    return total

tot = 0
for i in range(10000):
    sum1 = factsum(i)
    if i == factsum(sum1) and i!= sum1:
        tot +=i
        #print(i)
    

print(tot)
print(time.time()-start)
