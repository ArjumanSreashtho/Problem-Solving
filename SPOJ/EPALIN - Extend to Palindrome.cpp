#include<bits/stdc++.h>
using namespace std;

int LPS(string s)
{
    int l = s.length(), i = 0, j = 1;
    int lps[l+1];
    lps[0] = 0;
    while(j < l)
    {
        if(s[i] == s[j])
        {
            i++;
            lps[j] = i;
            j++;
        }
        else
        {
            if(i != 0)
            {
                i = lps[i-1];
            }
            else
            {
                lps[j] = 0;
                j++;
            }
        }
    }
    
    return l/2-lps[l-1];
}

int main()
{
    string s, temp,ss;
    int x;
    while(cin >> s)
    {
        ss = temp = s;
        reverse(temp.begin(),temp.end());
        s = temp+"#"+s;
        x = LPS(s);
        cout << ss;
        for(int i = x-1; i >= 0; i--)
        {
            cout << ss[i];
        }
        cout << endl;
    }
    return 0;
}