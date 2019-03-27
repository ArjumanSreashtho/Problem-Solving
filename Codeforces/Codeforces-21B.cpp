#include<bits/stdc++.h>
using namespace std;

int calc(double a1, double b1, double c1, double a2, double b2, double c2)
{
    if((a1 == 0 && b1 == 0 && c1 != 0) || (a2 == 0 && b2 == 0 && c2 != 0))
    {
        return 0;
    }
    if(abs(a1*b2-a2*b1) != 0)
    {
        return 1;
    }
    else if((a1*c2-a2*c1 == 0) && (b1*c2-b2*c1 == 0))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    double a1,b1,c1,a2,b2,c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    cout << calc(a1,b1,c1,a2,b2,c2) << endl;
    return 0;
}
