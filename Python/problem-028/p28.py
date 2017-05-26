import time
start = time.time()

def gen(no,addme):
    hello = []
    big = (no)*(no)
    i = 1
    n = 0
    while i <= big:
        hello.append(i)
        i = i + n*8+addme
        n+=1
    return sum(hello)

no = 1001
print(gen(no,2)+gen(no,6)+gen(no,4)+gen(no,8)-3)
print(time.time()-start)
