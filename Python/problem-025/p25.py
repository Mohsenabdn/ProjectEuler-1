import time
start = time.time()

def addme(list1,list2):
    hand = 0
    list3=[]
    list1 = list(reversed(list1))
    list1.append(0)
    list2=list(reversed(list2))
    if len(list1) <= len(list2):
        list2,list1=list1,list2
    # hereon list 2 is always smaller
    #print(len(list1),len(list2))
    while len(list2) != len(list1):
        list2.append(0)
    hand = 0
    for i in range(len(list1)):
        list3.append((list1[i]+list2[i]+hand)%10)
        hand = (list1[i]+list2[i]+hand)//10
    c = list(reversed(list3))
    if c[0] == 0:c=c[1:]
    return c

index =[2]
g =[1]
f =[1]

while len(g) <1000:
    index,f,g = addme(index,[1]),g,addme(f,g)
val = ''
for i in index:
    val = val + str(i)

print(val)
print(time.time()-start)
