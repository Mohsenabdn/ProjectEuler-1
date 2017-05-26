import time
start = time.time()


def ispan(a,b,c):
    d = str(a)+str(b)+str(c)
    if len(d) != 9: return 'n'
    for i in '123456789':
        if i not in d: return 'n'
    return 'y'
tot = 0
hello = []
for i in range(1,2000):
    for j in range(1,2000):
        if ispan(i,j,i*j)=='y' and i*j not in hello:
            tot+=i*j
            hello.append(i*j)

print(tot)
print(time.time()-start)
