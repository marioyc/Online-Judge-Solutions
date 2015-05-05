import base64

s = raw_input()
aux = bytearray(s.decode("base64"))
bin = []

for x in aux:
	for i in range(0,8):
		bin.append((x >> (7 - i)) % 2)

G = int(raw_input())
pos = 0

while G > 0:
	G -= 1

	line = raw_input()
	reverse = False

	if line[-1] == "R":
		L = int(line[0:-2])
		op = line[-2]
		reverse = True
	else:
		L = int(line[0:-1])
		op = line[-1]

	if op == "L":
		i = 0

		while i < L:
			Lbyte = min(8,L - i)
			j = 0

			while j < Lbyte / 2:
				bin[pos + i + j], bin[pos + i + Lbyte - 1 - j] = bin[pos + i + Lbyte - 1 - j], bin[pos + i + j]
				j += 1

			i += 8

		for i in range(0,L / 2):
			bin[pos + i], bin[pos + L - 1 - i] = bin[pos + L - 1 - i], bin[pos + i]

	if reverse:
		for i in range(0,L / 2):
			bin[pos + i], bin[pos + L - 1 - i] = bin[pos + L - 1 - i], bin[pos + i]

	val = 0

	for i in range(0,L):
		val = val * 2 + bin[pos + i]

	print val
	pos += L