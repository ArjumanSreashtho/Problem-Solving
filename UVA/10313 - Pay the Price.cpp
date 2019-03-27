#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define MOD 100000007

ofstream fout("test.txt");
int n, m,lim;
int coin[300];
LL dp[310][310];
void DP()
{
    for(int i = 0; i < 300; i++)
        coin[i] = i+1;
    for(int i = 0; i <= 300; i++)
        dp[i][0] = 1,dp[0][i] = 0;
    dp[0][0] = 1;
    for(int i = 1; i <= 300; i++)
    {
        for(int j = 1; j <= 300; j++)
        {
            if(j >= coin[i-1])
            {
                dp[i][j] = dp[i-1][j]+(dp[i][j-coin[i-1]]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}
vector<int> parse(string &s)
{
    s += ' ';
    int n = 0;
    vector<int> ret;
    for(char c : s)
        if(c == ' ') ret.push_back(n), n = 0;
        else n = 10*n + c - '0';
    return ret;
}
LL query(int n, int l, int r)
{
    if(n == 0) return l == 0 ? 1 : 0;
    l = max(l,1), r = min(r,300);
    return dp[r][n] - dp[l-1][n];
}
int main()
{
    DP();
    while(true)
    {
        string line;
        getline(cin, line);
        if(line.size() < 1) return 0;
        vector<int> v = parse(line);
        int SZ = v.size();
        if(SZ == 1) cout << query(v[0], 0, 300) << "\n";
        if(SZ == 2) cout << query(v[0], 0, v[1]) << "\n";
        if(SZ == 3) cout << query(v[0], v[1], v[2]) << "\n";
    }
    return 0;
}


