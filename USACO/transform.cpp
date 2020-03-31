/*
ID: onlyjav1
LANG: C++
TASK: transform
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int


int n;
char arr[10+1][10+1], cpy[10][10], out[10][10];
void rotate90()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cpy[j][n-i-1] = arr[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = cpy[i][j];
        }
    }
}

bool check()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(cpy[i][j] != out[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void reflection()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cpy[i][n-1-j] = arr[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = cpy[i][j];
        }
    }
}

void print()
{
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    fin >> n;
    bool ck = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            fin >> arr[i][j];
            cpy[i][j] = arr[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            fin >> out[i][j];
        }
    }
    rotate90();
    if(check())
    {
        fout << "1" << endl;
        return 0;
    }
    rotate90();
    if(check())
    {
        fout << "2" << endl;
        return 0;
    }
    rotate90();
    if(check())
    {
        fout << "3" << endl;
        return 0;
    }
    rotate90();
    if(check())
    {
        fout << "6" << endl;
        return 0;
    }
    reflection();
    if(check())
    {
        fout << "4" << endl;
        return 0;
    }
    rotate90();
    if(check())
    {
        fout << "5" << endl;
        return 0;
    }
    rotate90();
    if(check())
    {
        fout << "5" << endl;
        return 0;
    }
    rotate90();
    if(check())
    {
        fout << "5" << endl;
        return 0;
    }
    
    fout << "7" << endl;
    
    return 0;

}


