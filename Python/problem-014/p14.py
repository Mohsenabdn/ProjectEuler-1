import time

# last 5 terms are always 1 2 4 8 16

start = time.time()

def length(num):
    counter = 0
    while num!=16:
        counter = counter + 1
        if num%2 == 0: num = num/2
        else: num = num*3+1

    return(counter+5)

big = 5
specialnum = 16
for i in range(17,1000000):
    m = length(i)
    # print(m)
    if m > big:
        big = m
        specialnum = i

print(specialnum)
print(time.time() - start)
