#include<bits/stdc++.h>
using namespace std;

vector<int> adj[250];
bool used[250];
int clr[250];
bool bfs()
{
    queue<int> q;
    q.push(0);
    used[0] = 1;
    clr[0] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!used[v])
            {
                q.push(v);
                used[v] = 1;
                if(clr[v] == 0)
                {
                    if(clr[u] == 1)
                        clr[v] = 2;
                    else
                        clr[v] = 1;
                }
            }
            else if(clr[v] == clr[u])
                return false;
        }
    }
    return true;
}

int main()
{
    int n,m,a,b;
    while((cin >> n) && n)
    {
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(bfs())
        {
            cout << "BICOLORABLE." << endl;
        }
        else
        {
            cout << "NOT BICOLORABLE." << endl;
        }
        memset(clr,0,sizeof(clr));
        memset(used,0,sizeof(used));
        for(int i = 0; i < 250; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}

