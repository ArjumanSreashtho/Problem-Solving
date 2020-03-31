#include<bits/stdc++.h>

using namespace std;

#define LL long long int


LL maxSum(LL arr[],LL b, LL n)
{
    LL max_curr ,max_global;
    max_curr = max_global = arr[b];
    for(LL i = b+1; i < n; i++)
    {
        max_curr = max(arr[i], max_curr+arr[i]);
        if(max_curr > max_global)
        {
            max_global = max_curr;
        }
    }
    return max_global;
}

int main()
{
    LL t;
    cin >> t;
    while(t--)
    {

    
        LL n;
        cin >> n;
        LL arr[n+1];
        LL sum = 0;
        for(LL i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        LL sum1 = maxSum(arr,0,n-1), sum2 = maxSum(arr,1,n);
        if(sum1 >= sum || sum2 >= sum)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
        
        
    }
    return 0;
}