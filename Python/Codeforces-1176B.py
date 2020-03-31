t = int(input())
for _ in range(t):
    n = int(input())
    zero = 0
    one = 0
    two = 0
    arr = list(map(int,input().split()))
    for x in arr:
        if x%3 == 0:
            zero = zero+1
        elif x%3 == 1:
            one = one+1
        else:
            two = two+1
    x = min(one,two)
    print(zero+x+(one-x)//3+(two-x)//3)