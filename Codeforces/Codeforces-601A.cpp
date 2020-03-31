#include<bits/stdc++.h>

using namespace std;

#define LL long long int
#define MAX 1000000

bool adj_train[400][400];
bool adj_bus[400][400];
int n, m;
int dist[400];

int shortest_path(int root, bool adj[][400])
{
    for(int i = 0; i <= 400; i++)
        dist[i] = MAX;

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push({0,root});
    dist[root] = 0;

    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        for(int i = 1; i <= n; i++)
        {
            if(adj[u][i])
            {
                if(dist[u]+1 < dist[i])
                {
                    dist[i] = dist[u]+1;
                    q.push({dist[i], i});
                }
            }
        }
    }
    return dist[n];
}

int main()
{
    memset(adj_bus, 1, sizeof(adj_bus));


    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj_train[x][y] = 1;
        adj_train[y][x] = 1;
        adj_bus[x][y] = 0;
        adj_bus[y][x] = 0;
    }

    int train =  shortest_path(1, adj_train);
    int bus =  shortest_path(1, adj_bus);
    //cout << train << " " << bus << endl;
    if(train == MAX || bus == MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << max(train, bus) << endl;
    }
    return 0;
}

