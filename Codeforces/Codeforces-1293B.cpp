
#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long int
 
int main()
{
    double ans = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        ans += (1/(double)i);
    }
    printf("%0.12f\n", ans);
    return 0;
}