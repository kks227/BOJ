import hashlib
h = hashlib.new('sha')
h.update(input().encode())
print(h.hexdigest())