#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l, cnt = 0;
    string s;
    cin >> l >> s;
    for(int i = 1; ; i++)
    {
        cnt = (i*(i+1))/2;
        if(cnt > l)
            break;
        cout << s[cnt-1];
    }
    cout << endl;
    return 0;
}

