#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long int
#define MOD 1000000009
ULL dp[50][50];
int main()
{
	for(int i = 1; i <= 30; i++)
	{
		dp[i][1] = 1;
	}
	for(int i = 1; i <= 30; i++)
	{
		dp[1][i] = 1;
	}
	for(int i = 2;i <= 25; i++)
	{
		for(int j = 2; j <= 25; j++)
		{
			dp[i][j] = dp[i-1][j]+dp[i][j-1];
		}
	}
	int ts;
	cin >> ts;
	while(ts--)
	{
		int r, c;
		cin >> r >> c;
		cout << dp[r][c] << endl;
	}
	return 0;
}