#include<bits/stdc++.h>

using namespace std;

#define LL long long

struct Node
{
    LL pre, suf, sum, ans;
};

int n, arr[50000+10], q, l, r;

Node tree[4*50000+10];

Node combine(Node a, Node b)
{
    Node res;
    res.sum = a.sum+b.sum;
    res.pre = max(a.pre,a.sum+b.pre);
    res.suf = max(b.suf,b.sum+a.suf);
    res.ans = max(max(a.ans,b.ans),a.suf+b.pre);
    return res;
}

void build(int i, int j, int node)
{
    if(i == j)
    {
        tree[node].sum = tree[node].pre = tree[node].suf = tree[node].ans = arr[i];
        //cout << node << " " << i  << endl;
        return ;
    }
    int mid = (i+j)/2;
    build(i,mid,2*node);
    build(mid+1,j,2*node+1);
    tree[node] = combine(tree[2*node], tree[2*node+1]);
}

Node query(int i, int j, int l, int r, int node)
{
    //cout << i << " " << j << " "  << l << " " << r << endl;
    if(j < l || i > r)
    {
        Node node;
        node.sum = node.pre = node.suf = node.ans = INT_MIN;
        return node;
    }
    if(i >= l && j <= r)
    {
        return tree[node];
    }
    int mid = (i+j)/2;
    Node node1 = query(i,mid,l,r,2*node);
    Node node2 = query(mid+1,j,l,r,2*node+1);
    Node node3 = combine(node1,node2);
    //cout << node3.ans << endl;
    return node3;

}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }
    
    build(0,n-1,1);
    // for(int i = 1; i < 4*n; i++)
    // {
    //     cout << tree[i].ans << " ";
    // }
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        scanf("%d %d", &l, &r);
        Node res = query(0,n-1,l-1,r-1,1);
        printf("%lld\n", res.ans);
    }
    return 0;
}