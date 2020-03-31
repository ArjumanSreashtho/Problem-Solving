#include<bits/stdc++.h>

using namespace std;


#define MAX 100010
#define LL long long int

int main()
{
    int ts;
    cin >> ts;
    while(ts--)
    {
        LL n, c, sum = 0;
        cin >> n >> c;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            sum += x;
        }
        (sum <= c) ? cout << "Yes" << endl : cout << "No" << endl;
    }
    return 0;
}

