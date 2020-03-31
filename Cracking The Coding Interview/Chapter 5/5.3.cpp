#include <bits/stdc++.h>

using namespace std;

#define ESP 1e-9

int main()
{
    int num;
    cin >> num;
    int ans = 0, zero, cnt;
    for(int i = 0; i < 32; i++)
    {
        zero = 0, cnt = 0;
        for(int j = i; j < 32; j++)
        {
            bool val = num & (1 << j);
            if(!val)
            {
                zero++;
                i = j;
                if(zero > 1)
                {
                    break;
                }
            }
            cnt++;
        }
        ans = max(cnt, ans);
    }
    cout << ans << endl;
    return 0;
}
