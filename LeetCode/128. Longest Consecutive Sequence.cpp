#include<bits/stdc++.h>

using namespace std;

int root(int nodes[], int node)
{
    while(nodes[node] != node)
    {
        node = nodes[node];
        nodes[node] = nodes[nodes[node]];
    }

    return node;
}

void union_nodes(int nodes[], int sz[], int node1, int node2)
{
    int root1 = root(nodes, node1);
    int root2 = root(nodes, node2);

    if(sz[root1] >= sz[root2])
    {
        nodes[root2] = root1;
        sz[root1] += sz[root2];
    }
    else
    {
        nodes[root1] = root2;
        sz[root2] += sz[root1];
    }
}

int longestConsecutive(vector<int>& nums)
{
    int n = nums.size();

    if(!n)
    {
        return n;
    }

    unordered_map<int, int> mp;
    int nodes[n], sz[n];

    for(int i = 0; i < n; i++)
    {
        nodes[i] = i;
        sz[i] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        if(mp.find(nums[i]) != mp.end())
        {
            continue;
        }

        if(mp.find(nums[i] + 1) != mp.end())
        {
            union_nodes(nodes, sz, i, mp[nums[i]+1]);
        }

        if(mp.find(nums[i] - 1) != mp.end())
        {
            union_nodes(nodes, sz, i, mp[nums[i]-1]);
        }

        mp[nums[i]] = i;
    }

    int ans = 1;
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, sz[i]);
    }

    return ans;
}

int main()
{
    int n;

    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int result = longestConsecutive(nums);

    cout << result << endl;

    return 0;
}