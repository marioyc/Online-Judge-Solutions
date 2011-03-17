from sys import stdin
import psyco

psyco.full()

primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,
        61,67,71,73,79,83,89,97,101,103]

while True:#(n = stdin.readline()) != '':
    n = stdin.readline()
    
    if n == '':
        break
    
    n = int(n)
    prod = 1
    
    for p in primes:
        tmp = prod*p
        
        if tmp > n:
            break
        
        prod = tmp
    
    print prod
