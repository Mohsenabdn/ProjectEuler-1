import time
start = time.time()

def findsum(high):
    total = 0
    new1,new2 = 1,2
    while new2 < high:
        new1,new2 = nextnum(new1,new2)
        if new1%2 == 0:
            total = total + new1
        if new2%2 == 0:
            total = total + new2
    return (total+2)


def nextnum(fib1,fib2):
    return(fib1+fib2, fib1+fib2+fib2)

print(findsum(4e6))

run_time = time.time()-start
print(run_time)
