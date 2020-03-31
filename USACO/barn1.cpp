/*
ID: onlyjav1
LANG: C++
TASK: barn1
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

ofstream fout ("barn1.out");
ifstream fin ("barn1.in");

void func(vector<pair<int, int> > v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << " {" << v[i].first << "," << v[i].second << "} ";
    }
}

int main()
{
    
    int m, s, c, n;
    map<int, vector<pair<int, int> > > dis;
    map<int, vector<pair<int, int> > > :: reverse_iterator it;
    vector<pair<int, int> > v;
    fin >> m >> s >> c;
    if(m > c)
    {
        m = c;
    }
    n = m;
    int arr[c+1];
    for(int i = 0; i < c; i++)
    {
        fin >> arr[i];
    }
    sort(arr,arr+c);
    for(int i = 0; i < c-1; i++)
    {
        dis[arr[i+1]-arr[i]].push_back({i,i+1});
    }
    for(it = dis.rbegin(); it != dis.rend(), m > 1; it++)
    {
        for(int i = 0; i < it->second.size() && m > 1; i++, m--)
        {
            v.push_back(it->second[i]);
        }
    }
    m = n;
    if(m == 1)
    {
        fout << arr[c-1]-arr[0]+1 << endl;
    }
    else
    {
        int ans = 0;
        sort(v.begin(), v.end());
        ans += arr[v[0].first]-arr[0]+1;
        //cout << arr[0] << " " << arr[v[0].first] << endl;
        for(int i = 0; i < v.size()-1; i++)
        {
            ans += arr[v[i+1].first]-arr[v[i].second]+1;
            //cout << arr[v[i].second] << " " << arr[v[i+1].first] << endl;
        }
        ans += arr[c-1]-arr[v[v.size()-1].second]+1;
        //cout << arr[v[v.size()-1].second] << " " << arr[c-1] << endl;
        fout << ans << endl;
    }
    
    return 0;

}


