#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL nCr(int n, int r)
{
    LL res = 1;
    for(int i = 1; i <= r; i++)
    {
        res = res * (n-r+i)/i;
    }
    return res;
}
int main()
{
    int m,n,t;
    cin >> n >> m >> t;
    LL ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i >= 4 && t-i >= 1)
            ans += (nCr(n,i)*nCr(m,t-i));
    }
    cout << ans << endl;
    return 0;
}

