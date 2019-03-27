#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main()
{
    int n;
    scanf("%d", &n);
    LL sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += (LL)pow(2,i);
    }
    printf("%lld\n", sum);
    return 0;
}

