#include<bits/stdc++.h>

using namespace std;


#define MAX 100010


int main()
{
    int n;
    bool even = false, odd = false;
    cin >> n;
    int arr[n+1];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i]%2 == 0)
        {
            even = true;
        }
        else
        {
            odd = true;
        }
        
    }
    if(odd && even)
    {
        sort(arr,arr+n);
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    
    return 0;
}