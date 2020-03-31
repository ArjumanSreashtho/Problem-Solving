#include<bits/stdc++.h>

using namespace std;


#define MAX 100010
#define LL long long int


int main()
{
    int ts;
    cin >> ts;
    for(int t = 0; t < ts; t++)
    {
        LL n, cnt = 0;
        string s;
        cin >> n >> s;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
                cnt++;
        }
        LL ans = (cnt*(cnt+1))/2;
        cout << ans << endl;
    }
    return 0;
}

