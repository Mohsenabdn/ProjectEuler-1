import copy
import time
start = time.time()

old_possi =[2,0,0,0,0,0,0]
mult = [100,50,20,10,5,2,1]
curr_possi =[]
alllist=[]
#add 1 to answer for the case with 200 one note and rest all zeros
alllist.append(old_possi)

def reduce():
    global curr_possi
    temp = list(reversed(old_possi[:-1]))
    temp2=[]
    cut = -1
    for i in range(len(temp)):
        if temp[i]!=0:
            cut = i
            break
    if cut == -1 :return -1
    addme = old_possi[5-cut] -1
    temp2 = old_possi[:5-cut] + [addme]
    curr_possi=copy.deepcopy(temp2)

def complete():
    global curr_possi
    global old_possi
    global alllist
    addthem = 0
    for i in range(len(curr_possi)):
        addthem = curr_possi[i]*mult[i] + addthem
    curr_dig = len(curr_possi)
    remainder = 200 - addthem
    for i in range(curr_dig,6):
        curr_possi.append(remainder//mult[i])
        remainder = remainder - (remainder//mult[i])*mult[i]
    curr_possi.append(remainder)
    old_possi = copy.deepcopy(curr_possi)
    alllist.append(curr_possi)
    curr_possi=[]

i = 0
while reduce() != -1:
    complete()


print(len(alllist)+1)
print(time.time()-start)
