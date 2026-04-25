#11021
n = int(input())
for i in range(n):
  p, q = map(int, input().split())
  print("Case #" + str(i+1) + ":", p+q)