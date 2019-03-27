#include<bits/stdc++.h>
using namespace std;
#define LL long long int
int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		int a[m+10];
		LL sum = 0;
		for(int i = 0; i < m; i++)
		{
			cin >> a[i];
		}
		for(int i = 1; i < (1 << m); i++)
		{
			LL temp = 1, cnt = 0;
			for(int j = 0; j < m; j++)
			{
				if(i&(1<<j))
				{
					cnt++;
					temp = (temp*a[j])/__gcd(temp,(LL)a[j]);
				}
			}
			if(cnt&1)
			{
				sum += n/temp;
			}
			else
			{
				sum -= n/temp;
			}
		}
		cout << n-sum << endl;
	}
	return 0;
}