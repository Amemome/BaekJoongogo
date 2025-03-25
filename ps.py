
for _ in range(int(input())):
    a,b = input().split()
    realmulti = int(a) * int(b)
    falsemulti = ""
    if len(a) < len(b):
        tmp = a
        a = b
        b = tmp
    dif = len(a) - len(b)
    for i in range(dif):
        falsemulti += a[i]
    a = a[dif:]
    for i in range(len(a)):
        falsemulti += str(int(a[i]) * int(b[i]))
    
    if(falsemulti == str(realmulti)):
        print(1)
    else:
        print(0)