#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define LL long long int

int main()
{

    string s;
    cin >> s;
    int pivot;
    LL left = 0, right = 0;
    for(int i = 0; s[i]; i++)
    {
        if(s[i] == '^')
        {
            pivot = i;
        }
    }
    for(int i = 0; s[i]; i++)
    {
        if(i < pivot && s[i] >= '0' && s[i] <= '9')
        {
            left += (pivot-i)*(s[i]-'0');
        }
        else if(pivot < i && s[i] >= '0' && s[i] <= '9')
        {
            right += (i-pivot)*(s[i]-'0');
        }
    }
    //cout << left << " " << right << endl;
    if(left == right)
    {
        cout << "balance" << endl;
    }
    else if(left > right)
    {
        cout << "left" << endl;
    }
    else
    {
        cout << "right" << endl;
    }
    return 0;
}

