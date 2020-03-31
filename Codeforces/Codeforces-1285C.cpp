#include<bits/stdc++.h>

using namespace std;

#define LL long long int

LL LCM(LL a, LL b)
{
    return (a*b)/(__gcd(a,b));
}

int main()
{
    LL x;
    cin  >> x;
    for(LL i = sqrt(x); i >= 1; i--)
    {
        if(x%i == 0 && LCM(i,x/i) == x)
        {
            cout << i << " " << x/i << endl;
            break;
        }
    }
    return 0;
}