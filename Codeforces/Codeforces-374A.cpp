#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int n, m;

int cal(int x, int y, int i, int j, int a, int b)
{
    int dx = abs(x-i);
    int dy = abs(y-j);
    if(i == x && j == y)
    {
        return 0;
    }
    if((i+a > n && i-a < 1) || (j+b > m && j-b < 1))
    {
        return INF;
    }
    if(dx%a == 0 && dy%b == 0)
    {
        int aa = dx/a, bb = dy/b;
        if((aa%2 == 0 && bb%2 == 0) || (aa%2 != 0 && bb%2 != 0))
        {
            return max(aa,bb);
        }
        else
        {
            return INF;
        }
    }
    return INF;
}

int main()
{

    int i,j,a,b;
    cin >> n >> m >> i >> j >> a >> b;
    int x1 = cal(1,m,i,j,a,b);
    int x2 = cal(n,1,i,j,a,b);
    int x3 = cal(n,m,i,j,a,b);
    int x4 = cal(1,1,i,j,a,b);
    int ans = min(min(x1,x2),min(x3,x4));
    //cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;
    if(ans == INF)
    {
        cout << "Poor Inna and pony!" << endl;
    }
    else
        cout << ans << endl;
    return 0;
}

