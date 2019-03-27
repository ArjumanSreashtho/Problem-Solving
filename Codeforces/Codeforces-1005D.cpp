#include<bits/stdc++.h>
using namespace std;
#define LL long long int
int main()
{
    string s;
    cin >> s;
    LL ans = 0, num = 0, cnt = 0;
    ///cout << s.length() << endl;
    for(int i = 0; s[i]; i++)
    {
        num *= 10;
        num += (s[i]-'0');
        cnt++;
        if(num%3 == 0 || (s[i]-'0')%3 == 0 || cnt == 3) /// 101 er khetre jode if(num%3 == 0 || (s[i]-'0')%3 == 0) use kore thn kaj korbe na..
        {
            ///cout << num << endl;                     /// por por 3 ta number er moddhe ekono ekta / ekono duitar sum / 3 tar sum 3 diye divisible hobe
            ans++;
            num = 0;
            cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
}

