from sys import stdin
import psyco

psyco.full()

T = int(raw_input())
p = list()

for i in range(3,10):
    p.append(list())
    
    aux = 1
    
    for j in range(0,665):
        p[i-3].append(aux)
        aux *= i

while T > 0:
    T -= 1
    
    K, N = (int(x) for x in raw_input().split())
    ans = 0
    exp = 0
    
    while N > 0:
        if N & 1 == 1:
            ans += p[K-3][exp]
        
        N >>= 1
        exp += 1
    
    print ans
