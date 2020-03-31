
#include<bits/stdc++.h>

using namespace std;

#define LL long long int

int main()
{
    int n, m;
    cin >> n >> m;
    if(n == m)
    {
        cout << 0 << endl;
    }
    else if(n > m)
    {
        cout << n-m << endl;
    }
    else
    {
        int ans = 0;
        while(m > n)
        {
            if(m%2 != 0)
            {
                m++;
            }
            else
            {
                m /= 2;
            }
            ans++;
        }
        cout << ans+n-m << endl;
    }
    return 0;
}
