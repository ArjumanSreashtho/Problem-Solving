#include<iostream>
#include<fstream>
using namespace std;
#define ULL unsigned long long int
#define MOD 1000000009
#define N 65535

ofstream fout("text.txt");

int main()
{
    ULL n, m;
    while((cin >> n >> m) &&(n || m))
    {
        double res = 1;
        ULL r = min(n,m);
        for(int i = 1; i <= r; i++)
        {
            res = res * (n+m-r+i)/i;
        }
        cout << (ULL)res << endl;
    }
	return 0;
}