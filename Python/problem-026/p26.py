import time
start = time.time()

def recur(no):
    remain = 1%no
    repeat=[]
    digits=[1//no]
    while remain not in repeat:
        if remain == 0:
            return 0
        else:
            digits.append(remain*10//no)
            repeat.append(remain)
            remain = (remain*10)%no

    #print(repeat)
    #print(digits)
    # repeat is the list of remainders
    return len(repeat)

big = 0
for i in range(1,1000):
    if recur(i) > big:
        big = recur(i)
        no = i

print(no)
print(time.time()-start)
