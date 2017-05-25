import time
start = time.time()

def isabun(no):
    tot = 1
    for i in range(2,int(no**0.5)+1):
        if tot > no:
            return 'y'
        if no%i == 0:
            if i*i != no:
                tot = tot + i + int(no/i)
            else:
                tot = tot + i
    if tot > no:
        return 'y'
    else:
        return 'n'

c=[]
for i in range(2,28124):
    if isabun(i) == 'y': c.append(i)

d= list(range(0,28124))

for i in c:
    for j in c:
        if i + j > 28123:
            break
        else:
            d[i+j] = 0

print(sum(d))
print(time.time()-start)
