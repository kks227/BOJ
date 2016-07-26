cache = [[-1 for i in range(101)] for j in range(101)]

def combination(n, r):
    global cache
    ret = cache[n][r]
    if ret != -1:
        return ret
    if n == 0:
        ret = cache[n][r] = 1
        return ret
    if r == 0 or r == n:
        ret = cache[n][r] = 1
        return ret
    ret = cache[n][r] = combination(n-1, r-1) + combination(n-1, r)
    return ret

s = input('')
a = s.find(' ')
m = eval(s[:a])
n = eval(s[a+1:])
result = combination(m, n)
print(result)