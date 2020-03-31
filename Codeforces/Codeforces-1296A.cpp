#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long int
 
int main()
{
    int ts;
    cin >> ts;
    while(ts--)
    {
        int n, sum = 0;
        cin >> n;
        bool odd = false, even = false;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            sum += x;
            (x&1) ? odd = true : even = true;
            
        }
        if((sum&1) || (odd & even))
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