#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define LL long long int
#define MAX 200000

struct point
{
    int x,y;
};

void lineEquation(int x1, int y1, int x2, int y2, int &a, int &b, int &c)
{
    a = y2-y1;
    b = -1*(x2-x1);
    c = (x2-x1)*y1-(y2-y1)*x1;
}

void solve(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int a1,b1,c1,a2,b2,c2;

    lineEquation(x1,y1,x2,y2,a1,b1,c1);
    lineEquation(x3,y3,x4,y4,a2,b2,c2);
    
    if(a1*b2-a2*b1 != 0)
    {
        double px = (b1*c2-b2*c1)/(double)(a1*b2-a2*b1 );
        double py = (a2*c1-a1*c2)/(double)(a1*b2-a2*b1 );
        printf("POINT %0.2f %0.2f\n",px,py);
    }
    else
    {
        if((b1*c2-b2*c1) == 0 && (a2*c1-a1*c2) == 0)
        {
            printf("LINE\n");
        }
        else
        {
            printf("NONE\n");
        }
        
    }
    
}

int main()
{
    int n;
    cin >> n;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while(n--)
    {
        int x1,x2,x3,x4,y1,y2,y3,y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        solve(x1,y1,x2,y2,x3,y3,x4,y4);
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}

