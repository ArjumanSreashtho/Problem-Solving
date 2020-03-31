/*
ID: onlyjav1
LANG: C++
TASK: milk
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

ofstream fout ("milk.out");
ifstream fin ("milk.in");



int main()
{
    
    int m, n, sum = 0;
    LL ans = 0;
    fin >> m >> n;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        fin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
    {
        if(sum+v[i].second <= m)
        {
            sum += v[i].second;
            ans += v[i].first*v[i].second;
        }
        else
        {
            ans += v[i].first*(m-sum);
            sum += m-sum;
        }
        //cout << v[i].first << " " << sum << " " << ans << endl;
    }
    fout << ans << endl;
    return 0;

}


