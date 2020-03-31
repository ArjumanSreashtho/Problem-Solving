#include<bits/stdc++.h>

using namespace std;

#define LL long long int

LL nCr(int n, int r)
{
    LL res = 1;
    for(int i = 0; i < r; i++)
    {
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}

int main() 
{
    string s1, s2;
    cin >> s1 >> s2;
    int plus1 = 0, minus1 = 0, plus2 = 0, minus2 = 0, n = 0;
    for(int i = 0; i < s1.length(); i++)
    {
        if(s1[i] == '+')
            plus1++;
        else if(s1[i] == '-')
            minus1++;
    }
    for(int i = 0; i < s2.length(); i++)
    {
        if(s2[i] == '+')
            plus2++;
        else if(s2[i] == '-')
            minus2++;
        else if(s2[i] == '?')
            n++;
    }
    if(abs(plus1-plus2)+abs(minus1-minus2) != n)
    {
        printf("0.000000000000\n");
        return 0;
    }
    int r = abs(minus1-minus2);
    double ans = (double)nCr(n,r)/pow(2,n);
    printf("%0.12f\n", ans);
    return 0;
}

