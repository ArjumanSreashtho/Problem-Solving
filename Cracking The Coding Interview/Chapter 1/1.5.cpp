#include <bits/stdc++.h>

using namespace std;

bool check(string s1, string s2)
{
    int l1 = s1.size(), l2 = s2.size();
    int cnt = 0, i = 0, j = 0;
    while(i < l1 && j < l2)
    {
        if(cnt > 1)
            return false;
        if(s1[i] != s2[j])
        {
            if(l1 > l2)
            {
                i++;
            }
            else if(l1 < l2)
            {
                j++;
            }
            else
            {
                i++;
                j++;
            }
            cnt++;
        }
        else
        {
            i++;
            j++;
        }
    }
    if(i < l1 || j < l2)
    {
        cnt++;
    }
    return cnt == 1;
}


int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    if(check(s1, s2))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
