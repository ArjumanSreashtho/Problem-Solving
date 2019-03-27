#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main()
{
    int n, i, j = -1;
    LL ans = 1;
    scanf("%d", &n);
    int x;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if(x == 1 && j == -1)
        {
            j = i;
        }
        else if(x == 1)
        {
            ans *= (i-j);
            j = i;
        }
    }
    if(j == -1)
        ans = 0;
    cout << ans << endl;
    return 0;
}

