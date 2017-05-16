import time
start = time.time()

def count(a):
    hundred = ['','one','two','three','four','five','six','seven','eight','nine']
    tens = ['', '','twnety','thirty','forty','fifty','sixty','seventy','eighty','ninety']
    specials = ['ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen']
    ones = ['one','two','three','four','five','six','seven','eight','nine']

    b = ''

    if a//100 != 0:
        b = b + hundred[a//100] + 'hundred'
        if a%100 != 0:
            b = b + 'and'
    hello = (a-(a//100)*100)
    if hello//10 >=2:
        b = b + tens[hello//10]
    elif hello//10 == 1:
        b = b + specials[hello%10]
        return b
    if a%10 !=0:
        b = b + ones[a%10-1]


    return b


total = 0
for i in range(1,1000):
    total = total + len(count(i))

print(total+len('onethousand'))
print(time.time() -start)
