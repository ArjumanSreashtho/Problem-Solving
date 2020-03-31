
#include<bits/stdc++.h>

using namespace std;

#define LL long long int

vector<pair<int, int> > points;
vector<int> adj[100];

bool visited[100];

void BFS(int root)
{
    queue<int> q;
    q.push(root);
    visited[root] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

}

int main()
{
    int n, ans = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back({x,y});
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(points[i].first == points[j].first || points[i].second == points[j].second)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            ans++;
            BFS(i);
        }
    }

    cout << ans-1 << endl;
    return 0;
}
