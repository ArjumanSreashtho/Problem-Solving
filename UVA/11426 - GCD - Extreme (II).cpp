#include<bits/stdc++.h>
using namespace std;

#define MAX 4000001
#define LL long long int

int phi[MAX];
LL res[MAX];
void solve()
{
    for(int i = 0; i < MAX; i++)
        phi[i] = i;
    for(int i = 2; i < MAX; i++)
    {
        if(phi[i] == i)
        {
            for(int j = i; j < MAX; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }

    for(int i = 1; i < MAX; i++)
    {
        for(int j = i; j < MAX; j += i)
        {
            res[j] = res[j] + (LL)i*phi[j/i];
        }
    }
    for(int i = 1; i < MAX; i++)
        res[i] -= i;             /// Question e i = 1 r j = i+1 theke gcd(i,j) ber korte bolse, jode j = i hoto than kora lagto na

    for(int i = 1; i < MAX; i++)
    {
        res[i] += res[i-1];
    }
}

int main()
{
    solve();
    int n;
    while(scanf("%d", &n) && n)
    {
        printf("%lld\n", res[n]);
    }
    return 0;
}

