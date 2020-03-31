#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>>& matrix) 
{
    int n = matrix[0].size();
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    } 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n/2; j++)
        {
            swap(matrix[i][j], matrix[i][n-j-1]);
        }
    }   
}

void print(vector<vector<int> > matrix)
{
    int n = matrix[0].size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > v;
    for(int i = 0; i < n; i++)
    {
        vector<int> temp;
        for(int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    rotate(v);
    print(v);
    return 0;
}
