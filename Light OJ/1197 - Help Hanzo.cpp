#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define MAX 100000

bool ck[MAX];
int prime[MAX+10];
int l;
void sieve()
{
    ck[0] = ck[1] = 1;
    for(int i = 2; i*i <= MAX; i++)
    {
        if(!ck[i])
        {
            //prime.push_back(i);
            //cout << i << endl;
            //1getchar();
            for(int j = i+i; j <= MAX; j+=i)
            {
                ck[j] = 1;
            }
        }
    }
    for(int i = 2; i <= MAX; i++)
    {
        if(!ck[i])
        {
            //cout << i << endl;
            prime[l] = i;
            l++;
        }
    }
    //cout << "ok" << endl;
}

LL seg_sieve(LL a, LL b)
{
    int segp[b-a+1];
    memset(segp,0,sizeof(segp));
    if(a == 1)
        a++;
    LL sq = sqrt(b)+1;
    //cout << a << " " << b << " " << l << endl;
    for(LL i = 0; i < l && prime[i] <= sq; i++)
    {
        //cout << "ok" << endl;
        LL p = prime[i];
        LL j = p*p;
        //cout << p << endl;
        if(j < a)
        {
            j = ((a+p-1)/p)*p;
        }
        //cout << j << endl;
        for( ; j <= b; j+=p)
        {
          //  cout << j << endl;
            segp[j-a] = 1;
        }
    }
   // cout << "ok" << endl;
    LL res = 0;
    for(LL i = a; i <= b; i++)
    {
        //cout << res << endl;
        if(i <= MAX && !ck[i])
        {
            res++;
        }
        else if( i > MAX && !segp[i-a])
        {
            res++;
        }
    }
    return res;
}

int main()
{
    sieve();
    int ts;
    cin >> ts;
    for(int t = 1; t <= ts; t++)
    {
        LL a, b;
        cin >> a >> b;
        LL res = seg_sieve(a,b);
        cout << "Case " << t << ": "<< res << endl;
    }
    return 0;
}

