from math import sqrt
import psyco

psyco.full()

def is_prime(n):
    r = sqrt(n)
    i = 2
    
    while i <= r:
        if n % i == 0:
            return False
        i += 1
    
    return True

primes = list()

for n in xrange(2,10001):
    if is_prime(n):
        primes.append(n)

best = -1
N = len(primes)

def check(i1,i2):
    return is_prime(int(str(primes[i2])+str(primes[i1]))) and is_prime(int(str(primes[i1])+str(primes[i2])))

for i1 in xrange(4,N):
    for i2 in xrange(3,i1):
        if check(i2,i1):
            for i3 in xrange(2,i2):
                if check(i3,i2) and check(i3,i1):
                    for i4 in xrange(1,i3):
                        if check(i4,i3) and check(i4,i2) and check(i4,i1):
                            for i5 in xrange(0,i4):
                                if check(i5,i4) and check(i5,i3) and check(i5,i2) and check(i5,i1):
                                    if best == -1 or primes[i1]+primes[i2]+primes[i3]+primes[i4]+primes[i5]:
                                        best = primes[i1]+primes[i2]+primes[i3]+primes[i4]+primes[i5]
                                        print best

print best
