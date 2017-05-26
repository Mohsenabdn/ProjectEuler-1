import time
start = time.time()

d=[]

for i in range(2,101):
    for j in range(2,101):
        hello = i**j
        if hello not in d:
            d.append(hello)
    #print(i)

print(len(d))
print(time.time()-start)
            
