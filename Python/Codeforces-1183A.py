def check(n):
    res = 0
    while n != 0:
        res = res+n%10;
        n = n//10;
    if res%4 == 0:
        return 1
    else:
        return 0


n = int(input())
while not check(n):
    n = n+1
print(n)