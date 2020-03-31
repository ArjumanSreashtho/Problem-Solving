Copy
#include<bits/stdc++.h>

using namespace std;


#define MAX 100010


int main()
{
    int n;
    cin >> n;
    int arr[2*n+10];
    for(int i = 0; i < 2*n; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+2*n);
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++)
    {
        sum1 += arr[i];
    }
    for(int i = n; i < 2*n; i++)
    {
        sum2 += arr[i];
    }
    if(sum1 == sum2)
    {
        cout << "-1" << endl;
    }
    else
    {
        for(int i = 0; i < 2*n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    
    return 0;
}