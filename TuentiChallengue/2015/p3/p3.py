p = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97]
np = len(p)

f = open("numbers.txt","r")

sum = [ [0] * np ]
last = sum[0]

for line in f:
	n = int(line)
	aux = []

	for x in p:
		cont = 0

	 	while n % x == 0:
	 		n /= x
	 		cont += 1

 		aux.append(cont)

 	for i in range(0,np):
 		aux[i] += last[i]

	sum.append(aux)
	last = aux

 	assert(n == 1)

f.close()

f = open("submitInput3","r")
T = int(f.readline())

while T > 0:
	T -= 1

	a,b = [int(x) for x in f.readline().split()]
	
	aux = []

	for i in range(0,np):
		aux.append((sum[b][i] - sum[a][i],p[i]))

	aux.sort()
	best = aux[np - 1][0]
	ans = str(best)

	for x in aux:
		if x[0] == best:
			ans = ans + " " + str(x[1])

	print ans