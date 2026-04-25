#10430
a, b, c = map(int, input().split())
ans = []
ans.append((a + b) % c)
ans.append(((a % c) + (b % c)) % c)
ans.append((a*b) % c)
ans.append(((a % c) * (b % c)) % c)
for i in ans:
  print(i)