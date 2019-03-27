#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

int arr[MAX+10];
int tree[MAX*4];
int merge(int a, int b)
{
	return min(a,b);
}
void build(int node, int l, int r)
{
	if(l == r)
	{
		tree[node] = arr[l];
		return ;
	}
	int mid = (l+r)/2;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	tree[node] = merge(tree[2*node],tree[2*node+1]);
}

int query(int node,int l, int r, int i, int j)
{
	if(i > r || l > j)
		return INT_MAX;
	if(l >= i && r <= j)
		return tree[node];
	int mid = (l+r)/2;
	int p = query(2*node,l,mid,i,j);
	int q = query(2*node+1,mid+1,r,i,j);
	return merge(p,q);
}

int main()
{
	int ts;
	//cin >> ts;
	scanf("%d", &ts);
	for(int t = 1; t <= ts; t++)
	{
		int n,q,a,b;
		//cin >> n >> q;
		scanf("%d %d", &n,&q);
		for(int i = 0; i < n; i++)
		{
			//cin >> arr[i];
			scanf("%d", arr+i);
		}
		//cout << "Case " << t << ":" << endl;
		printf("Case %d:\n",t);
		build(1,0,n-1);
		while(q--)
		{
			//cin >> a >> b;
			scanf("%d %d", &a, &b);
			printf("%d\n",query(1,0,n-1,a-1,b-1));
		}
	}
	return 0;
}