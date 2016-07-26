import hashlib
h = hashlib.new('ripemd160')
h.update(input().encode())
print(h.hexdigest())