#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long int
#define MOD 1000000009

int main()
{
	int n, ans;
	cin >> n;
	if(n&1)
	{
		cout << 0 << endl;
		return 0;
	}
	ans = n/4;
	if(n%4 == 0)
		ans--;
	cout << ans << endl;
	return 0;
}