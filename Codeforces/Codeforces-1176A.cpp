#include<bits/stdc++.h>

using namespace std;


#define MAX 100010
#define LL long long int

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        LL n, ans = 0;
        cin >> n;
        while(n > 1)
        {
            if(n%2 == 0 || n%3 == 0 || n%5 == 0)
            {
                if(n%2 == 0)
                {
                    n /= 2;
                }
                else if(n%3 == 0)
                {
                    n = (2*n)/3;
                }
                else if(n%5 == 0)
                {
                    n = (4*n)/5;
                }
                ans++;
            }
            else
            {
                break;
            }
            
        }
        if(n == 1)
        {
            cout << ans << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        
    }
    return 0;
}