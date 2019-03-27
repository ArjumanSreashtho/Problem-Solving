#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long int
#define MOD 1000000009
#define N 65535

ULL digit[N+10];
ULL sum[N+10];
ofstream fout("text.txt");

int search(int pos)
{
	int low = 0, high = N, res = 0;
	while(low <= high)
	{
		int mid = (low+high)/2;
		///cout << sum[mid] << endl;
		if(sum[mid] < pos)
		{
			res = mid;
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
		
	}
	return res;
}
int main()
{

	for(int i = 1; i <= N; i++)
	{
		digit[i] = digit[i-1] + log10(i) + 1;
		sum[i] = sum[i-1]+digit[i];
		///cout <<i << " "<< digit[i] << " " <<   sum[i] << endl;
	}
	int ts;
	cin >> ts;
	while(ts--)
	{
		bool ck = true;
		int pos;
		cin >> pos;
		int num = search(pos);
		int start = sum[num];
		num++;
		///cout << num << " " << start << endl;
		for(int i = 1, j = start+1; i <= num && ck; i++)
		{
			string s = to_string(i);	
			for(int p = 0; s[p]; p++, j++)
			{
				if(j == pos)
				{
					cout <<s[p] << endl;
					ck = false;
					break;
				}
			}
		}
	}
	return 0;
}