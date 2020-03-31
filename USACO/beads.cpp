/*
ID: onlyjav1
LANG: C++
TASK: beads
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n;
    string in;
    fin >> n >> in;
    int len = in.size();
    int ans = 0;
    in += in;
    for(int i = 0; i < len; i++)
    {
        int j = 0, k = 0, cnt1 = 0, cnt2 = 0;
        bool b = false, r = false;
        for(j = i; j < len+i; j++)
        {
            if(in[j] == 'b')
                b = true;
            else if(in[j] == 'r')
                r = true;
            if(b^r || in[j] == 'w')
                cnt1++;
            else
                break;
        }
        b = false, r = false;
        for(k = len+i-1; k >= j; k--)
        {
            if(in[k] == 'b')
                b = true;
            else if(in[k] == 'r')
                r = true;
            if(b^r || in[k] == 'w')
                cnt2++;
            else
                break;
        }
        ans = max(ans,cnt1+cnt2);

    }
    fout << ans << endl;
    return 0;
}