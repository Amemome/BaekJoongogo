import sys



phi = [0] * 100001
for i in range(100001):
    phi[i] = i

prime = []

for i in range(2,100001):
    if phi[i] == i:
        prime.append(i)
        for j in range(i,100001,i):
            phi[j] = phi[j] * (i-1) // i

def getphi(n):
    if n > 100000:
        tmp = n
        for p in prime:
            if tmp < p * p:
                break
            if tmp % p == 0:
                while tmp % p == 0:
                    tmp //= p
                n = n // p * (p - 1)
        if tmp > 1:
            n = n // tmp * (tmp - 1) 
        return n
            
    else:
        return phi[n]





tc = int(sys.stdin.readline())
def solve(n,m):
    if(m==1):
        return 0
    p = getphi(m)
    return pow(n,solve(n,p)+p,m)



for i in range(tc):
    n,m = list(map(int,sys.stdin.readline().split()))
    if m == 1:
        print(0)
    else:
        print(solve(n,m))
    

