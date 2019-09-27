N = int(input())
E = ''
for i in range(N*2-1):
    e = input()
    if e == '/':
        e = '//'
    E += e
print(eval(E))
