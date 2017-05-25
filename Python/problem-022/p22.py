import time
start = time.time()

fr = open('22.txt','r')
a = fr.read()
b = list(a.split(' '))
# print(len(b))
b.sort()

compare = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
tot = 0
for i in b:
    word_tot = 0
    for j in i:
        #print(j)
        word_tot = word_tot + compare.index(j)+1
    tot = tot + word_tot*(b.index(i)+1)

print(tot)
print(time.time()-start)
