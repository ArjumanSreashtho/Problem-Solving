#include <bits/stdc++.h>

using namespace std;

void hashValue(string s, long long int hash[])
{
    
    int sz = s.size();
    long long int power = prime;
    hash[0] = 0;
    hash[1] = s[0]-'a'+1;
    for(int i = 2; i <= sz; i++)
    {
        hash[i] = hash[i-1]+(s[i-1]-'a'+1);
    }
}

bool checkString(string s1, string s2, int start, int end)
{
    int cnt1[30] = {0}, cnt2[30] = {0};
    int l = end-start+1;
    for(int i = 0; i < l; i++)
    {
        cnt1[s1[i]-'a']++;
    }
    for(int i = start-1; i < end; i++)
    {
        cnt2[s2[i]-'a']++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(cnt1[i] != cnt2[i])
            return false;
    }
    return true;
}

bool check(string s1, string s2)
{
    int l1 = s1.size(), l2 = s2.size();
    long long int hash1[l1+1], hash2[l2+1];
    hashValue(s1, hash1);
    hashValue(s2, hash2);
    
    for(int i = 1; i+l1-1 <= l2; i++)
    {
        //cout << hash2[l1+i-1]-hash2[i-1] << " " << hash1[l1] << endl;
        if(hash2[l1+i-1]-hash2[i-1] == hash1[l1] && checkString(s1, s2, i, i+l1-1))
        {
            return true;
        }
    }
    return false;
}


int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    if(check(s1, s2))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    
    return 0;
}
