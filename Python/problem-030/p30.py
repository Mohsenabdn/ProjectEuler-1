import time
start = time.time()

def powsum(no):
    num = str(no)
    tot = 0
    for i in num:
        tot = tot + int(i)**5
    return tot
a=[]
for i in range(2,1000000):
    if i == powsum(i): a.append(i)

print(sum(a))
print(time.time()-start)
