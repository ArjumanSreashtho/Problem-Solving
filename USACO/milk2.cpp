/*
ID: onlyjav1
LANG: C++
TASK: milk2
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int


int main()
{
    
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n;
    fin >> n;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        fin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end());
    int mn = 0;
    int cur = 0;
    int mx = v[cur].second-v[cur].first;
    for(int i = 1; i < n; i++)
    {
        if(v[i].first > v[cur].second)
        {
            mx = max(mx, v[cur].second-v[cur].first);
            mn = max(mn,v[i].first-v[cur].second);
            cur = i;
        }
        else
        {
            v[cur].second = max(v[i].second, v[cur].second);
        }
    }
    fout << mx << " " << mn << endl;

    return 0;

}


