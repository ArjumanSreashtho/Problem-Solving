#include<bits/stdc++.h>

using namespace std;

#define LL long long int
vector<string> res;
void func(string s, int i, int l)
{
    if(i == l)
    {
        res.push_back(s);
        return;
    }
    if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
        func(s,i+1,l);
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
        func(s,i+1,l);
    }
    else
    {
        func(s,i+1,l);
    }
    
}

int main() 
{
    string s;
    cin >> s;
    int l = s.size();
    
    func(s,0,l);
    for(auto r:res)
        cout << r << endl;
    return 0;
}

