import psyco

psyco.full()

#u_n = 1 - n + n^2 - n^3 + n^4 - n^5 + n^6 - n^7 + n^8 - n^9 + n^10

def get_term(n):
    ret, aux = 1, 1
    
    for i in xrange(0,10):
        aux *= -n
        ret += aux
    
    return ret

def lagrange(seq, n):
    deg = len(seq)
    ret = 0
    
    for i in xrange(1,deg+1):
        num = seq[i-1]
        den = 1
        
        for j in xrange(1,deg+1):
            if j != i:
                num *= n-j
                den *= i-j
        
        ret += num * 1.0 / den
    
    return ret

U = [get_term(i) for i in xrange(0,12)]
#U = [i*i*i for i in xrange(0,12)]
#print U

ans = 0

for i in xrange(2,12):
    aux = int(lagrange(U[1:i],i))
    
    if aux != U[i]:
        ans += aux

print ans
