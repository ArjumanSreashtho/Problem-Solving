#include<bits/stdc++.h>

using namespace std;

int root(int nodes[], int node)
{
    while(nodes[node] != node)
    {
        nodes[node] = nodes[nodes[node]];
        node = nodes[node];
    }

    return node;
}

void union_nodes(int nodes[], unsigned int sz[], int source, int destination)
{
    int source_root = root(nodes, source);
    int destination_root = root(nodes, destination);

    if(sz[source_root] >= sz[destination_root])
    {
        nodes[destination_root] = source_root;
        sz[source_root] += sz[destination_root];
    }
    else
    {
        nodes[source_root] = destination_root;
        sz[destination_root] += sz[source_root];
    }
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    int nodes[n+1];
    unsigned int sz[n+1];

    for(int i = 0; i < n; i++){
        nodes[i] = i;
        sz[i] = 1;
    }

    for(int i = 0; i < edges.size(); i++)
    {
        union_nodes(nodes, sz, edges[i][0], edges[i][1]);
    }

    return root(nodes, source) == root(nodes, destination);
}

int main()
{
   return 0;
}