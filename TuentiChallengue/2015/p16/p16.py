from scipy.optimize import linprog

E = int(raw_input())

for tc in range(1,E + 1):
	E -= 1

	T,S,P = [int(x) for x in raw_input().split()]
	M = []

	for i in range(0,P):
		M.append([int(x) for x in raw_input().split()])

	A = []
	A2 = []
	b = []
	b2 = []
	c = [1] * (P * T)

	for i in range(0,P):
		row = [0] * (P * T)

		for j in range(0,T):
			row[i * T + j] = 1

		A.append(row)
		b.append(M[i][0])

	for j in range(0,T):
		row = [0] * (P * T)

		for i in range(0,P):
			row[i * T + j] = 1.0 / M[i][j + 1]

		A2.append(row)
		b2.append(1)

	res = linprog(c, A_ub=A, b_ub=b, A_eq=A2, b_eq=b2)

	if res.status == 0:
		ans = 0

		for var in res.x:
			ans += var

		if ans <= S:
			print "Test case #%d: RIGHT" % tc
		else:
			print "Test case #%d: %.2f" % (tc,ans - S)
	else:
		print "Test case #%d: IMPOSSIBLE" % tc