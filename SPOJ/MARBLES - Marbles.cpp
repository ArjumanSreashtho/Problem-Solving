#include<bits/stdc++.h>

using namespace std;

#define ULL unsigned long long int

ULL nCr(int n, int r)
{
    r = min(n,n-r);
    ULL res = 1;
    for(int i = 1; i <= r; i++)
    {
        res *= (n-r+i);
        res /= i;
    }
    return res;
}

int main()
{
    int ts;
    cin >> ts;
    while(ts--)
    {
        int n, k;
        cin >> n >> k;
        n--;
        k--;
        cout << nCr(n,k) << endl;
    }
    return 0;
}

