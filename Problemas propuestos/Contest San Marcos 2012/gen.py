import string
import random

def generate_string(size=15, chars=string.ascii_lowercase):
   return ''.join(random.choice(chars) for x in range(size))

###Problema A###

f = open('A.in', 'w')
T = 50
f.write(str(T) + '\n')

while T > 0:
    T -= 1
    
    L = random.randint(1,1000)
    f.write(generate_string(size=L, chars='()?') + '\n')

f.close()

###Problema B###

f = open('B.in', 'w')
T = 50
f.write(str(T) + '\n')

while T > 0:
    T -= 1
    
    Ltotal = random.randint(1,100000)
    L = random.randint(1,Ltotal)
    
    f.write(str(Ltotal) + '\n')
    f.write(generate_string(size=L,chars='()') + '\n')

f.close()

###Problema C###

f = open('C.in', 'w')
T = 50
f.write(str(T) + '\n')

while T > 0:
    T -= 1
    
    L = random.randint(1,50000)
    f.write(generate_string(size=L) + '\n')

f.close()
