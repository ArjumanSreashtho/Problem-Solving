#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long int
 
int main()
{
    int ts;
    cin >> ts;
    while(ts--)
    {
        int n, x, y, cnt;
        string ans = "";
        cin >> n;
        vector<pair<int, int> > v;
        for(int i = 0; i < n; i++)
        {
            
            cin >> x >> y;
            v.push_back({x, y});
        }
        sort(v.begin(), v.end());
        x =  y = cnt = 0;
        for(int i = 0; i < n; i++)
        {
            while(x < v[i].first)
            {
                ans += "R";
                x++;
            }
            while(y < v[i].second)
            {
                ans += "U";
                y++;
            }
            if(x == v[i].first && y == v[i].second)
            {
                cnt++;
            }
        }
        if(cnt == n)
        {
            cout << "YES\n" << ans << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}