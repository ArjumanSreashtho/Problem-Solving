#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long int
 
int main()
{
    int ts;
    cin >> ts;
    while(ts--)
    {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int mx = max(a, max(b,c));
        int need = 3*mx-a-b-c;
        if(n-need >= 0 && (n-need)%3 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}