#include<bits/stdc++.h>

using namespace std;

#define LL long long int

int main() {
    int ts;
    cin >> ts;
    while(ts--)
    {
        string s;
        cin >> s;
        int l = s.size();
        LL ans = 0;
        bool ck = false;
        stack<char> st;
        int cnt = 0;
        for(int i = 0; i < l; i++)
        {
            if(st.empty() && s[i] == '>')
                break;
            if(s[i] == '<')
            {
                st.push('<');
            }
            else if(s[i] == '>' && !st.empty())
            {
                cnt++;
                st.pop();
            }
            if(st.empty())
            {
                ans += (cnt * 2);
                cnt = 0;
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}

// <<><><>>><><><>>><><><>