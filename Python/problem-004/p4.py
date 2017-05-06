import time
start = time.time()

def ispal(num):
    if list(str(num)) == list(reversed(list(str(num)))):
        return 'y'
    else:
        return 'n'

huge = 0
for i in range(100,1000):
    for j in range(100,1000):
        product = i*j
        if ispal(product) == 'y' and product > huge:
            huge = product


print(huge)
print(time.time()-start)
