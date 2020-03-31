#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long int

int main()
{
    int ts;
    cin >> ts;
    while(ts--)
    {
        int n;
        LL sum = 0;
        cin >> n;
        int a[n+1], b[n+1];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        sort(a,a+n);
        sort(b,b+n);
        for(int i = 0; i < n; i++)
        {
            sum += min(a[i],b[i]);
        }
        cout << sum << endl;
    }
    
    return 0;
}