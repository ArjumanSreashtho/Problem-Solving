
#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long int
 
int dp[1111][1111];
int n, m;

bool subsetSum(int arr[], int i, int modulo, bool ck)
{
    modulo %= m; 
    if((!modulo && ck) ||  i >= n)
    {
        if(!modulo && ck)
        {
            return true;
        }
        return false;
    }
    if(dp[i][modulo] != -1)
    {
        return dp[i][modulo];
    }
    int res1 = false, res2 = false;
    res1 = subsetSum(arr, i+1, modulo+arr[i], true);
    res2 = subsetSum(arr, i+1, modulo, ck);
    return dp[i][modulo] = res1|res2;
     
}

int main()
{
    
    
    cin >> n >> m;
    int arr[n+1];
    bool ck = false;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] %= m;
        if(!arr[i])
        {
            ck = true;
        }
    }
    if(ck || n > m)
    {
        cout << "YES" << endl;
    }
    else
    {
        memset(dp, -1, sizeof(dp));

        if(subsetSum(arr,0,0,false))
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