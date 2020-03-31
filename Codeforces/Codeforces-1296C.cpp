#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long int

int main()
{
    int ts;
    cin >> ts;
    while(ts--)
    {
        string s;
        int n, x = 0, y = 0, i = 0, mn = INT_MAX, start = -1, end = -1;
        bool ck = true;

        cin >> n >> s;
        
        map<pair<int, int>, int> mp;
        mp[{x,y}] = i;

        for(i = 0; i < n; i++)
        {
            if(s[i] == 'L')
                x--;
            else if(s[i] == 'R')
                x++;
            else if(s[i] == 'U')
                y++;
            else if(s[i] == 'D')
                y--;
            if(mp.find({x,y}) == mp.end())
            {
                mp[{x,y}] = i+1;
            }
            else
            {
                if(i-mp[{x,y}] < mn)
                {
                    mn = i-mp[{x,y}];
                    start = mp[{x,y}];
                    end = i;
                }
                mp[{x,y}] = i+1;
                ck = false;
            }            
        }
        if(ck)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << start+1 << " " << end+1 << endl;
        }
        
        
    }
    
    return 0;
}