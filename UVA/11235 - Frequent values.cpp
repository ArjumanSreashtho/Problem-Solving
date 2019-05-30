#include<bits/stdc++.h>
using namespace std;

const int block_sz = 550;
#define MAX 100010

struct query
{
    int l, r, id;
};
int cnt[2*MAX], freq[2*MAX], ans[MAX], arr[MAX];
int maxAns ; 

bool cmp(query a, query b)
{
    if(a.l/block_sz != b.l/block_sz)
    {
        return a.l < b.l;
    }
    return ((a.l/block_sz) & 1) ? (a.r < b.r) : (a.r > b.r);
}

void add(int idx)
{
    cnt[arr[idx]]++;
    //cout << idx << " " << cnt[idx] << " ";
    freq[cnt[arr[idx]]]++;
    maxAns = max(cnt[arr[idx]],maxAns);
    //cout << maxAns << endl;
}

void remove(int idx)
{
    freq[cnt[arr[idx]]]--;
    if(freq[cnt[arr[idx]]] == 0)
    {
        maxAns--;
    }
    cnt[arr[idx]]--;
}

int main()
{
    int n,m,l,r;
    
    while(cin >> n && n)
    {
        cin >> m;
        query q[m+1];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 0; i < m; i++)
        {
            cin >> q[i].l >> q[i].r;
            q[i].l--;
            q[i].r--;
            q[i].id = i;
        }
        
        sort(q,q+m,cmp);
        int L = 0, R = -1;
        //cout << "K" << endl;
        for(int i = 0; i < m; i++)
        {
            while(R < q[i].r)
            {
                R++;
                //cout << "ADD R " << R << " " << q[i].r << endl; 
                add(R);
            }
            while(L < q[i].l)
            {
                //cout << "Remove L " << L << " " << q[i].l << endl;
                remove(L);
                L++;
            }
            while(R > q[i].r)
            {
                //cout << "Remove R " << R << " " << q[i].r << endl;
                remove(R);
                R--;
            }
            while(L > q[i].l)
            {
                L--;
                //cout << "ADD L " << L << " " << q[i].l << endl; 
                add(L);
            }
            ans[q[i].id] = maxAns;
            //cout << maxAns << endl;
        }
        for(int i = 0; i < m; i++)
        {
            cout << ans[i] << endl;
        }
        for(int i = 0; i < 2*MAX; i++)
        {
            freq[i] = cnt[i] = maxAns = 0;
        }
    }
    return 0;
}