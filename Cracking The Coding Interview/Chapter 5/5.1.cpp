#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, i, j;
    cin >> n >> m >> j >> i;
    for(int pos = 0;i <= j;i++, pos++)
    {
        bool val = m & (1 << pos);
        n = n | (val << i); 
    }
    cout << n << endl;
    return 0;
}
