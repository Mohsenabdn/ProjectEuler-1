import time
start = time.time()

fr = open('13.txt','r')
lines = fr.readlines()
a=[]
for i in lines:
    a.append(i.strip())

def colsum(j):
    total = 0
    for i in range(100):
        total = total + int(a[i][j])
    return total
hand = 0
b=[]
for k in reversed(range(50)):
    this = colsum(k) + hand
    b.append(this%10)
    hand = this//10

b.append(str(hand))

total = list(reversed(b))
val=''
for i in total:
    val = val + str(i)
# print(val)

print(val[0:10])
print(time.time()-start)
