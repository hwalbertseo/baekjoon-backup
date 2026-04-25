inputp = input()
listp = []
for i in range(len(inputp)):
    listp.append(inputp[i])
cnt1 = 0
cnt2 = 0
for p in range(len(listp)):
    if listp[p - 1] == "(":
        cnt1 += 1
    elif listp[p-1] == ")":
        cnt2 += 1
if cnt1 == cnt2:
    print("YES")
elif cnt1 != cnt2:
    print("NO")
