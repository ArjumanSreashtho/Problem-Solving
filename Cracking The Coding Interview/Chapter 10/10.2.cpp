#include <bits/stdc++.h>

using namespace std;

string merge(string left, string right, string str, int l, int r)
{
    int i = 0, j = 0, k = 0;
    while(i < l && j < r)
    {
        if(left[i] < right[j])
        {
            str[k] = left[i];
            i++;
        }
        else
        {
            str[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < l)
    {
        str[k] = left[i];
        i++;
        k++;
    }
    while(j < r)
    {
        str[k] = right[j];
        j++;
        k++;
    }
    return str;
}

string merge_sort(string str)
{
    int sz = str.size();
    if(sz < 2)
        return str;
    int l = sz/2;
    int r = sz-l;
    string left, right;
    for(int i = 0; i < l; i++)
        left.push_back(str[i]);
    for(int i = l; i < sz; i++)
        right.push_back(str[i]);
    left = merge_sort(left);
    right = merge_sort(right);
    return merge(left, right, str, l, r);
}

long long int computeHash(string &str)
{
    long long int hash = 0;
    int prime = 53;
    int mod = 1e9+9;
    long long int pow = 1;
    for(auto c:str)
    {
        hash += ((c-'A'+1)*pow)%mod;
        pow *= prime;
        pow %= mod;
    }
    return hash;
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    int l = strs.size();
    vector<vector<string> > ans;
    map<long long int, vector<string> > mp;
    for(int i = 0; i < l; i++)
    {
        string temp = strs[i];
        temp = merge_sort(temp);
        //cout << temp << endl;
        long long int hash = computeHash(temp);
        mp[hash].push_back(strs[i]);
    }
    for(map<long long int, vector<string> > :: iterator it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}

int main()
{
    vector<string> strs;
    vector<vector<string> > ans;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        strs.push_back(s);
    }
    ans = groupAnagrams(strs);
    return 0;
}
