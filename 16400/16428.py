n, m = map(int, input().split())
if m > 0:
	p = n//m
else:
	m *= -1
	if n%m == 0:
		p = -n//m
	else:
		p = -n//m + 1
	m *= -1
print(p)
print(n-p*m)