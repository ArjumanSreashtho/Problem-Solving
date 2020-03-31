#include<bits/stdc++.h>

using namespace std;


#define MAX 100010
#define LL long long int


int main()
{
    LL a, b;
    vector<int> v;
    cin >> a >> b;
    v.push_back(b);
    while(a < b)
    {
        if(b&1)
        {
            if((b-1)%10 != 0)
            {
                break;
            }
            b -= 1;
            b /= 10;
        }
        else
        {
            b /= 2;
        }
        //cout << a << " " << b << endl;
        v.push_back(b);
    }
    if(a == b)
    {
        cout << "YES\n" << v.size() << endl;
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    return 0;
}

