#include<bits/stdc++.h>

using namespace std;

#define MAX 100000
#define LL long long

bool solve(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    double t1, t2;
    t1 = ((y3-y4)*(x1-x3)+(x4-x3)*(y1-y3))/(double)((x4-x3)*(y1-y2)-(x1-x2)*(y4-y3));
    t2 = ((y1-y2)*(x1-x3)+(x2-x1)*(y1-y3))/(double)((x4-x3)*(y1-y2)-(x1-x2)*(y4-y3));
    if(t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {

        int x1, x2, x3, x4, y1, y2, y3, y4, min_x, min_y, max_x, max_y;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        min_x = min(x3,x4);
        max_x = max(x3,x4);
        min_y = min(y3,y4);
        max_y = max(y3,y4);
        if(solve(x1,y1,x2,y2,x3,y3,x4,y3) || solve(x1,y1,x2,y2,x4,y3,x4,y4) || solve(x1,y1,x2,y2,x4,y4,x3,y4) || solve(x1,y1,x2,y2,x3,y4,x3,y3))
        {
            cout << "T" << endl;
        }
        else if((x1 >= min_x && x1 <= max_x && y1 >= min_y && y1 <= max_y) && (x2 >= min_x && x2 <= max_x && y2 >= min_y && y2 <= max_y))
        {
            cout << "T" << endl;
        }
        else
        {
            cout << "F" << endl;
        }
    }
    return 0;
}

