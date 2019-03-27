#include<bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)
#define LL long long int

bool visited[50];
int pos[50];
bool prime[50];
int ts = 1;
void permutation(int arr[], int i, int n)
{
    if(i == n+1)
    {
        if(!prime[arr[n]+1])
        {
            return ;
        }
        for(int j = 1; j <= n; j++)
        {
            cout << arr[j];
            if(j < n)
            {
                cout << " ";
            }
        }
        cout << endl;
        return ;
    }
    for(int j = 2; j <= n; j++)
    {
        if(!visited[j])
        {
            if(!prime[arr[i-1]+j])
            {
                continue;
            }
            visited[j] = true;
            arr[i] = j;
            permutation(arr,i+1,n);
            visited[j] = false;
        }
    }
}

int main()
{
    prime[2] = prime[3] = prime[5] = prime[7] = prime[11] = prime[13] = prime[17] = prime[19] = prime[23] = prime[29] = prime[31] = 1;
    int n;
    
    //cout.open("test.txt");
    while(cin >> n)
    {
        if(ts > 1)
        {
            cout << endl;
        }
        cout << "Case " << ts << ":" << endl;
        ts++;
        int arr[n+10];
        for(int i = 1; i <= n; i++)
        {
            arr[i] = i;
        }
        permutation(arr,2,n);
    }
    //cout.close();
    return 0;
}