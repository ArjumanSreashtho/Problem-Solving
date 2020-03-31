/*
ID: onlyjav1
LANG: C++
TASK: gift1
*/
#include<bits/stdc++.h>
using namespace std;

struct data
{
    int taka, number, sum;
    vector<string> names;
};

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    map<string, data> mp;
    int n, taka, number;
    string name1, name2;
    fin >> n;
    string names[n+1];
    for(int i = 0; i < n; i++)
    {
        fin >> names[i];
    }
    for(int i = 0; i < n; i++)
    {
        data temp;
        temp.sum = 0;
        fin >> name1 >> temp.taka >> temp.number;
        for(int j = 0; j < temp.number; j++)
        {
            fin >> name2;
            temp.names.push_back(name2);
        }
        mp[name1] = temp;
    }
    for(map<string, data> :: iterator it = mp.begin(); it != mp.end(); it++)
    {
        if(it->second.number == 0)
            continue;
        int cash = it->second.taka/it->second.number;
        int remain = it->second.taka-cash*it->second.number;
        it->second.taka = remain;
        it->second.sum += -cash*it->second.number;
        for(int i = 0; i < it->second.number; i++)
        {
            mp[it->second.names[i]].sum += cash;
        }
    }
    for(int i = 0; i < n; i++)
    {
        fout << names[i] << " " << mp[names[i]].sum << endl;
    }
    return 0;
}