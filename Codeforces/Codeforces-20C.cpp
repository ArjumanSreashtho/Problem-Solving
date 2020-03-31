#include<bits/stdc++.h>

using namespace std;

#define LL long long int
#define MAX 1000000000000

vector<pair<int,int> > adj[100010];
LL dist[100010];
int parent[100010];

void dijkstra(int root)
{
    for(int i = 2; i <= 100000; i++)
    {
        dist[i] = MAX;
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push({0,root});
    dist[root] = 0;

    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if(dist[u]+w < dist[v])
            {
                dist[v] = dist[u]+w;
                q.push({dist[v],v});
                parent[v] = u;
            }
        }
    }
}

int main()
{
    int n, m;

    vector<int> ans;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    dijkstra(1);
    if(parent[n] == 0)
    {
        cout << -1;
        return 0;
    }
    while(n)
    {
        ans.push_back(n);
        n = parent[n];
    }
    for(int i = ans.size()-1; i >= 0; i--)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
