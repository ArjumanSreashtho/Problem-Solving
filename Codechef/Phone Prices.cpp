#include<bits/stdc++.h>

using namespace std;


#define MAX 100010
#define LL long long int

int arr[MAX];
int main()
{
    int ts;
    int n;
    cin >> ts;
    while(ts--)
    {
        for(int i = 0; i < MAX; i++)
        {
            arr[i] = 1000000;
        }
        cin >> n;
        
        int ans = 0;
        
        for(int i = 100; i < 100+n; i++)
        {
            cin >> arr[i];
        }
        for(int i = 100+n-1; i >= 100; i--)
        {
            //cout << arr[i] << endl;
            bool ck = true;
            for(int j = i-1, cnt = 0; cnt < 5 ; cnt++, j--)
            {
               // cout << arr[i] <<"   "<<i<<"    " << arr[j] << endl;
                if(arr[j] <= arr[i])
                {
                    ck = false;
                    break;
                }
                
            }
            if(ck)
            {
                ans++;
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}

