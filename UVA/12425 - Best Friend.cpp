#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define MAX 1000010
ofstream fout("practice.txt");
vector<int> prime;
bool ck[MAX];


void sieve()
{
    for(int i = 3; i*i <= MAX; i+=2)
    {
        if(!ck[i])
        {
            for(int j = i+i; j <= MAX; j+= i+i)
            {
                ck[j] = true;
            }
        }
    }
    prime.push_back(2);
    for(int i = 3; i <= MAX; i+=2)
    {
        if(!ck[i])
        {
            prime.push_back(i);
        }
    }
}


LL phi(LL n)
{
    LL res = n, sz = prime.size();
    for(LL i = 0; i < sz && prime[i]*(LL)prime[i] <= n; i++)
    {
        if(n%prime[i] == 0)
        {
            res /= prime[i];
            res *= (prime[i]-1);
            while(n%prime[i] == 0)
                n /= prime[i];
        }
    }
    if(n > 1)
    {
        res /= n;
        res *= (n-1);
    }
    return res;
}

int search(vector<pair<LL,LL> > v, LL x)
{
    int low = 0, high = v.size()-1, mid, res = -1;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(v[mid].first <= x)
        {
            res = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return res;
}

int main()
{
    sieve();
    int ts,idx, t = 1;    
    for(scanf("%d", &ts); ts--;)
    {
        LL n,x;
        int q;
        scanf("%lld %d", &n, &q);
        vector<pair<LL,LL> > v;
        for(LL i = 1; i*i <= n; i++)
        {
            if(n%i == 0)
            {
                v.push_back(make_pair(i,phi(n/i)));
            }
            if(n%(n/i) == 0 && i*i != n)
            {
                v.push_back(make_pair(n/i,phi(i)));
            }
        }
        sort(v.begin(),v.end());
        
        for(LL i = 1; i < v.size(); i++)
            v[i].second += v[i-1].second;

        printf("Case %d\n",t);
        t++;
        while(q--)
        {
            scanf("%lld", &x);        
            idx = search(v,x);
            if(idx == -1)
            {
                printf("0\n");
            }
            else
            {
                printf("%lld\n", v[idx].second);
            }
        
        }
    }
    return 0;
}