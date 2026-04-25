#2407
def ntom(n, m):
  ans = 1
  for i in range(n, m+1):
    ans = ans * i
  return ans

p, q = map(int, input().split())
if q > p-q:
  q = p-q
a = ntom(p-q+1, p)
b = ntom(1, q)
print(int(a/b))

