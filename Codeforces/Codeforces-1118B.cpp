#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define LL long long int
#define MAX 200000


int arr[MAX+10];

int odd[MAX+10], even[MAX+10], oddSum, evenSum,ans;

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if(i&1)
        {
            odd[i] = odd[i-1]+arr[i];
            even[i] = even[i-1];
        }
        else
        {
            even[i] = even[i-1]+arr[i];
            odd[i] = odd[i-1];
        }
        
    }
    for(int i = 1; i <= n; i++)
    {
        if(i&1)
        {
            oddSum = odd[i-2]+even[n]-even[i];
            evenSum = even[i-1]+odd[n]-odd[i];
        }
        else
        {
            oddSum = odd[i-1]+even[n]-even[i];
            evenSum = even[i-2]+odd[n]-odd[i];
        }
        if(oddSum == evenSum)
        {
            ans++;
        }
        
    }
    cout << ans << endl;
}

