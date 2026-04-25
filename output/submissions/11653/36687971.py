#11653
p = int(input())
q = 2
while(q <= p and p > 1):
  if(p % q == 0):
    p /= q
    print(q)
  else:
    q += 1