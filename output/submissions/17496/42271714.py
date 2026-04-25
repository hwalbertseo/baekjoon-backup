a = list(map(int, input().split()))

ans = (a[0]-1)//a[1]
ans *= a[2]
ans *= a[3]

print(ans)