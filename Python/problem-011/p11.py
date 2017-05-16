import time
start = time.time()

fr = open('p11.txt','r')
lines = fr.readlines()
fr.close()

b=[]
counter = 0
for i in lines:
    i = i.strip()
    b.append(list(i.split(' ')))

def getprod(i,j):
    try:
        row4 = int(b[i][j])*int(b[i][j+1])*int(b[i][j+2])*int(b[i][j+3])
    except:
        row4 = -1
    try:
        col4 = int(b[i][j])*int(b[i+1][j])*int(b[i+2][j])*int(b[i+3][j])
    except:
        col4 = -1
    try:
        dia4 = int(b[i][j])*int(b[i+1][j+1])*int(b[i+2][j+2])*int(b[i+3][j+3])
    except:
        dia4 = -1
    try:
        dia24 = int(b[i][j])*int(b[i+1][j-1])*int(b[i+2][j-2])*int(b[i+3][j-3])
    except:
        dia24 = -1
    return max(row4,col4,dia4,dia24)

high = 0
for i in range(20):
    for j in range(20):
        prod = getprod(i,j)
        #print(i,j,prod)
        if prod > high and prod!=-1:
            high = prod

print(high)
print(time.time()-start)
