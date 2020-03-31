ans = 0
q = int(input())
while q > 0:
    ans = 0
    n = int(input())
    while n > 1:
        if n%2 == 0 or n%3 == 0 or n%5 == 0:
            if n%2 == 0:
                ans = ans+1
                n = n//2
            elif n%3 == 0:
                ans = ans+1
                n = (2*n)//3
            elif n%5 == 0:
                ans = ans+1
                n = (4*n)//5
        else:
            break
    if n == 1:
        print(ans)
    else:
        print(-1)
    q = q-1