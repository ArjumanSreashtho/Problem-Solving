#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define LL long long int

int main()
{
    int a, b, draw = 0;
    bool ck = false;
    cin >> a >> b;
    if(a > b)
    {
        ck = true;
        swap(a,b);
    }
    else if(a == b)
    {
        cout << 0 << " " << 6 << " " << 0 << endl;
        return 0;
    }
    int def = abs(a-b);
    if(def%2 == 0)
        draw++;
    a = a+def/2-draw;
    b = 6-b+1+(def/2)-draw;
    if(ck)
    {
        swap(a,b);
    }
    cout << a << " " << draw << " " << b << endl;
    return 0;
}
///1 2 3 4 5 6
/// 1 3
