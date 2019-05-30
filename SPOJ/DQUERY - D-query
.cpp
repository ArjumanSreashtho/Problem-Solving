#include<bits/stdc++.h>

using namespace std;

struct query
{
    int l,r,id;
};

int cnt[1000010], arr[30010], answer[200010];
int ans;
const int block_sz = 550;

query q[200010];

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
    if(cnt[arr[idx]] == 1)
    {
        ans++;
    }

}

void remove(int idx)
{
    cnt[arr[idx]]--;
    if(cnt[arr[idx]] == 0)
    {
        ans--;
    }
}

int main()
{
    int n,m;
    //cin >> n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        //cin >> arr[i];
        scanf("%d", &arr[i]);
    }
    //cin >> m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        //cin >> q[i].l >> q[i].r;
        scanf("%d %d", &q[i].l,&q[i].r);
        q[i].l--;
        q[i].r--;
        q[i].id = i;
    }
    sort(q,q+m,cmp);
    int L = 0, R = -1;
    //cout << "OK" << endl;
    for(int i = 0; i < m; i++)
    {
        while(R < q[i].r)
        {
            R++;
            add(R);
        }
        while(R > q[i].r)
        {
            remove(R);
            R--;
        }
        while(L > q[i].l)
        {
            L--;
            add(L);
        }
        while(L < q[i].l)
        {
            remove(L);
            L++;
        }
        answer[q[i].id] = ans;
    }
    for(int i = 0; i < m; i++)
    {
        //cout << answer[i] << endl;
        printf("%d\n", answer[i]);
    }
    return 0;
}