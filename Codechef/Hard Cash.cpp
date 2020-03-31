#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long int

int main()
{
    int ts;
    cin >> ts;
    while(ts--)
    {
        LL n, k;
        LL sum = 0;
        cin >> n >> k;
        LL arr[n+1];
        for(int i = 0; i < n; i++) 
        {
            cin >> arr[i];
            sum += arr[i];
        }
        cout << sum%k << endl;
    }
    
    return 0;
}