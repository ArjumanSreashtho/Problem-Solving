#include<bits/stdc++.h>

using namespace std;


#define MAX 100010
#define LL long long int

vector<int> adj[50005+10];
int weights[50005+1];
int ans, pos;

void DFS(int u, int sum)
{
    if(adj[u].size() == 0)
    {
        if(sum > ans)
        {
            ans = sum;
            pos = u;
        }
        return;
    }
    int vertix = 0, mx = -1;
    for(int v : adj[u])
    {
        if(weights[v] > mx)
        {
            mx = weights[v];
            vertix = v;
        }
    }
    DFS(vertix,sum+weights[vertix]);
}

int main()
{
    int ts;
    cin >> ts;
    
    for(int t = 1; t <= ts; t++)
    {
        ans = -1;
        pos = 0;
        int n, m;
        cin >> n >> m;
        
        for(int i = 0; i < n; i++)
        {
            cin >> weights[i];
        }
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        DFS(0,0);
        cout << "Case "<< t << ": "<< ans << " " << pos << endl;
        for(auto& v : adj)
            v.clear();
        memset(weights,0,sizeof(weights));
    }
    return 0;
}

/***
6 6
0 8 9 2 7 5
5 4
5 3
1 5
0 1
0 2
2 1

**/