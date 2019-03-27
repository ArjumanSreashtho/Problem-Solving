#include<bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)
#define LL long long int

int main()
{
    int n,k, nn;
    cin >> n >> k;
    nn = n;
    int cnt = 1;
    priority_queue<int> q;
    if(n&1)
    {
        q.push(1);
        n >>= 1;
        cnt *= 2;
    }
    while(n)
    {
        if(n&1)
        {
            q.push(cnt);
        }
        n >>= 1;
        cnt *= 2;
    }
    int l = q.size();
    if(k < l || k > nn)
    {
        cout << "NO" << endl;
        return 0;
    }
    while(true)
    {
        if(l == k)
        {
            cout << "YES" << endl;
            while(!q.empty())
            {
                cout << q.top() << " ";
                q.pop();
            }
            cout << endl;
            break;
        }
        int temp = q.top();
        q.pop();
        q.push(temp/2);
        q.push(temp/2);
        l++;
    }

    return 0;
}