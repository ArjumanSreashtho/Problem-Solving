#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define LL long long int

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        LL n, a, b;
        cin >> n >> a >> b;
        LL ans = min(n*a,(n/2)*b+(n%2)*a);
        cout << ans << endl;
    }
}

