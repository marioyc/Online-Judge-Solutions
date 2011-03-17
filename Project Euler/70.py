import psyco

psyco.full()

N = pow(10,7)-1

factor = [-1] * (N+1)

for i in xrange(2,N+1):
    if factor[i] == -1:
        factor[i] = i
        j = 2*i
        
        while j<=N:
            factor[j] = i
            j += i

phi = [0] * (N+1)
phi[1] = 1

for i in xrange(2,N+1):
    aux = i
    aux2 = 1
    
    while aux % factor[i] == 0:
        aux /= factor[i]
        aux2 *= factor[i]
    
    phi[i] = phi[aux] * (aux2-aux2/factor[i])

num, den = -1, -1

for i in xrange(2,N+1):
    cont1 = [0] * 10
    cont2 = [0] * 10
    
    aux1, aux2 = i, phi[i]
    
    while aux1 != 0:
        cont1[aux1 % 10] += 1
        aux1 /= 10
    
    while aux2 != 0:
        cont2[aux2 % 10] += 1
        aux2 /= 10
    
    if cont1 == cont2 and (num == -1 or num * phi[i] > i * den):
            num, den = i, phi[i]

print num
