#include <bits/stdc++.h>

using namespace std;

#define ESP 1e-9

int main()
{
    int a, b;
    int ans = 0;
    cin >> a >> b;
    for(int i = 0; i < 32; i++)
    {
        if((a & (1 << i)) != (b & (1 << i)))
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
