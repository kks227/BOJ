S = input().split()
N = int(S[0])
P = int(S[1])
O = str(N**P)
for i in range(len(O)):
	print(O[i], end='')
	if i % 70 == 69:
		print()