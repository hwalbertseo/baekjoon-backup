import math

p, q = map(int, input().split())
a = math.factorial(p)
b = (math.factorial(p - q)) * (math.factorial(q))
print(a / b)