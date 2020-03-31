
#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long int
 

int main()
{
    
    int n;
    set<int> list;
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        bool isPrime = true, div = false;
        int cnt = 0;
        for(int j = 2, k = i; j <= k; j++)
        {
            div = false;
            while(k%j == 0)
            {
                isPrime = false;
                k /= j;
                div = true;
            } 
            if(div)
            {
                cnt++;
            }
        }
        if(isPrime || cnt == 1)
        {
            list.insert(i);
        }
    }
    cout << list.size() << endl;
    for(set<int> :: iterator it = list.begin(); it != list.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}