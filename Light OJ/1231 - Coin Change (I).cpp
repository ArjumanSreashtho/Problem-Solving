#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define MOD 100000007

int n, m;
int coin[55];
int piece[55];
int dp[55][1010];
int DP(int i,int total)
{
    if(i >= n || total == m)
    {
        if(total == m)
        {
            return 1;
        }
        return 0;
    }
    if(dp[i][total] != -1)
        return dp[i][total];
    int r1 = 0, r2 = 0;
    for(int c = 0; c <= piece[i]; c++)
    {
        if(total+coin[i]*c <= m )
        {
            r1 += DP(i+1,total+coin[i]*c)%MOD;
        }
        else
            break;
    }
    return dp[i][total] = (r1%MOD+r2%MOD)%MOD;
}
int main()
{
    int ts;
    ///cin >> ts;
    scanf("%d",&ts);
    for(int t = 1; t <= ts; t++)
    {
        ///cin >> n >> m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            ///cin >> coin[i];
            scanf("%d", coin+i);
        }
        for(int i = 0; i < n; i++)
        {
            ///cin >> piece[i];
            scanf("%d", piece+i);
        }
        memset(dp,-1,sizeof(dp));
        ///cout << "Case " << t << ": " << DP(0,0) << endl;
        printf("Case %d: %d\n",t,DP(0,0));
    }
    return 0;
}
