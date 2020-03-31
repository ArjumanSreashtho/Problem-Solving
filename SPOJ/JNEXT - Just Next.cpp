#include<bits/stdc++.h>
 
using namespace std;
 
 
#define MAX 100010
#define LL long long int
 
 
int main()
{
    int ts;
    cin >> ts;
    for(int t = 0; t < ts; t++)
    {
        int n, pos = 0;
        bool ck = false;
        cin >> n;
        int arr[n+1];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for(int i = n-1; i >= 0; i--)
        {
            if(arr[i] > arr[i-1])
            {
                //swap(arr[i],arr[i-1]);
                ck = true;
                pos = i-1;
                break;
            }
        }
        if(!ck)
        {
            cout << -1 << endl;
        }
        else
        {
            int idx = pos+1;
            for(int i = pos+1; i < n; i++)
            {
                if(arr[idx] > arr[i] && arr[pos] < arr[i])
                {
                    idx = i;
                }
            }
            swap(arr[pos], arr[idx]);
            sort(arr+pos+1, arr+n);
            for(int i = 0; i < n; i++)
            {
                cout << arr[i];
            }
            cout << endl;
        }
        
    }
    return 0;
}