#include <bits/stdc++.h>
using namespace std;
#define LL long long int
LL count(LL *a, LL m, LL n)
{
	LL odd = 0, even = 0;
	LL counter, i, j, p = 1;
	LL pow_set_size = (1 << n);
	for (counter = 1; counter < pow_set_size; counter++)
	{
		p = 1;
		for (j = 0; j < n; j++) 
		{
			if (counter & (1 << j)) 
			{
				p = (p*a[j])/__gcd(p,a[j]);
			}
		}
		if (__builtin_popcount(counter) & 1)
			odd += (m / p);
		else
			even += m / p;
	}

	return odd - even;
}

int main()
{
  LL num, k;
  cin >> num >> k;
	LL a[k+10];
  for(LL i = 0; i < k; i++)
    cin >> a[i];
  cout << num-count(a,num,k) << endl;
	return 0;
}
