l = []

def print_input(a):
  for i in range(1, a):
    if(a%i == 0):
      l.append(i)

while(1):
  p = int(input())
  if p==-1:
    break
  else:
    print_input(p)
    q = 0
    for i in l:
      q += i
    if(q == p):
      print(p, "=", l[0], end = '')
      for i in range(1, len(l)):
        print(" +", l[i], end = '')
      print()
    else:
      print(p, "is NOT perfect")
    l.clear()

