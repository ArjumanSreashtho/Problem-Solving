#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long int
 
int main()
{
    int ts;
    cin >> ts;
    while(ts--)
    {
        int s;
        cin >> s;
        LL ans = s;
        while(s > 9)
        {
            int x = s/10;
            ans += x;
            s = s+x-(x*10);
        }
        cout << ans << endl;
        
    }
    return 0;
}