#include <bits/stdc++.h>

using namespace std;

bool checkUniqueOnSquareTime(string s, int sz)
{
    for(int i = 0; i < sz; i++)
    {
        for(int j = i+1; j < sz; j++)
        {
            if(s[i] == s[j])
            {
                return false;
            }
        }
    }
    return true;
}

bool checkUniqueLinearTime(string s, int sz)
{
    long long int part1 = 0, part2 = 0;
    for(int i = 0; i < sz; i++)
    {
        if(s[i] < 65)
        {
            if(part1 & (1 << s[i]))
            {
                return false;
            }
            part1 |= (1 << s[i]);
        }
        else
        {
            if(part2 & (1 << (s[i]-65)))
            {
                return false;
            }
            part2 |= (1 << (s[i]-65));
        }
    }
    return true;
}


int main()
{
    string s;
    getline(cin, s);
    int sz = s.size();
    if(checkUniqueLinearTime(s, sz))
    {
        cout << "Unique" << endl;
    }
    else
    {
        cout << "Not Unique" << endl;
    }
    
    return 0;
}
