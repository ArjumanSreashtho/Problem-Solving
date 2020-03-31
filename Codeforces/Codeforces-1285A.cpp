#include<bits/stdc++.h>

using namespace std;

#define LL long long int




int main()
{
    int n;
    string s;
    cin >> n >> s;
    int l = 0, r = 0;
    for(int i = n-1; i >= 0; i-- )
    {
        if(s[i] == 'L')
            l++;
        else
            r++;
        
    }
    cout << l+1+r << endl;
    return 0;
}