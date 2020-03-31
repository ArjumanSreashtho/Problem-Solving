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
        bool ck = true, cp = true;
        string s;
        cin >> s;
        int l = s.length();
        int firstHalf[30], secondHalf[30];
        memset(firstHalf, 0, sizeof(firstHalf));
        memset(secondHalf, 0, sizeof(secondHalf));
        for(int i = 0; i < l; i++)
        {
            if(i < l/2)
            {
                firstHalf[s[i]-'a']++;
            }
            else if(i > l/2)
            {
                secondHalf[s[i]-'a']++;
            }
            if(l%2 == 0 && cp)
            {
                secondHalf[s[l/2]-'a']++;
                cp = false;
            }
        }
        for(int i = 0; i < 26; i++)
        {
            //cout << firstHalf[i] << "  " << secondHalf[i] << endl;
            if(firstHalf[i] != secondHalf[i])
            {
                ck = false;
                //break;
            }
        }
        if(ck)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
    }
    return 0;
}

