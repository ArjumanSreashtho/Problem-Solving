#include<bits/stdc++.h>

using namespace std;


#define MAX 100010
#define LL long long int

bool check(int n)
{
    int res = 0;
    while(n)
    {
        res = res + n%10;
        n /= 10;
    }
    return res%4 == 0? 1 : 0;
}

int main()
{
    int n;
    cin >> n;
    while(!check(n))
    {
        n++;
    }
    cout << n << endl;
    return 0;
}