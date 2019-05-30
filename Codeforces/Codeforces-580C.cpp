#include<bits/stdc++.h>
using namespace std;

#define MAX 100000

vector<int> adj[MAX+10];
bool visited[MAX+10];
bool arr[MAX+10];
int n, m,x, y, ans;

void DFS(int src, int sum)
{
    //cout << "SUM   " << sum << endl;
    if(sum > m)
    {
        //cout << "CAT " << src << endl;
        return ;
    }
    if(adj[src].size() == 1 && visited[adj[src][0]])
    {
        ans++;
    }
    visited[src] = true;
    for(auto u : adj[src])
    {
        if(!visited[u])
        {
            //cout << u << " " <<  arr[u] << endl;
            if(arr[u])
                DFS(u,sum+arr[u]);
            else
                DFS(u,arr[u]);
        }
    }
}

int main()
{

    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n-1; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(1,arr[1]+0);
    cout << ans << endl;
    return 0;
}