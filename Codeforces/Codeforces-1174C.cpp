#include<bits/stdc++.h>

using namespace std;


#define MAX 100010

bool ck[MAX];
bool cp = true;
int num = 1;
int arr[MAX];
void solve()
{
    for(int i = 2; i < MAX; i++)
    {
        if(!ck[i])
        {
            cp = true;
            for(int j = i; j <= MAX; j+=i)
            {
                ck[j] = true;
                if(arr[j] == 0)
                {
                    arr[j] = num;
                }
            }
        }
        if(cp)
        {
            num++;
            cp = false;
        }
    }
}

int main()
{
    solve();
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}