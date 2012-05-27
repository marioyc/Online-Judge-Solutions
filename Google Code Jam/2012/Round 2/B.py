from random import *

def check(x,y,r,ind,pos):
	if(pos == 0):
		return True
	
	k = ind[pos][1]
	
	for j in range(0,pos):
		i = ind[j][1]
		
		if((x[i] - x[k]) * (x[i] - x[k]) + (y[i] - y[k]) * (y[i] - y[k]) < (r[i] + r[k]) * (r[i] + r[k])):
			return False
	
	return True

T = int(input())

for tc in range(1,T + 1):
	N,W,L = [int(x) for x in raw_input().split()]
	r = [int(x) for x in raw_input().split()]
	x = [0] * N
	y = [0] * N
	
	ind = [(r[i],i) for i in range(0,N)]
	ind.sort()
	ind.reverse()
	pos = 0
	
	while pos < N:
		for it in range(0,10):
			x[ ind[pos][1] ] = random() * W
			y[ ind[pos][1] ] = random() * L
			
			if(check(x,y,r,ind,pos)):
				pos += 1
				break
			elif(pos > 0 and it == 9):
				pos -= 1
	
	ans = ""
	
	for i in range(0,N):
		ans += " " + str(x[i]) + " " + str(y[i])
	
	print "Case #%d:%s" % (tc, ans)