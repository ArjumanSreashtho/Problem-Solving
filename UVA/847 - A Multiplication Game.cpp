#include<bits/stdc++.h>

using namespace std;

#define LL long long int

ofstream fout ("test.txt");

map<LL,bool> dp;
bool win(LL p, LL num)
{
    if(p >= num)
    {
        return dp[p] = 0;
    }
    if(dp.find(p) != dp.end())
        return dp[p];
    bool res = (win(p*2,num) == 0 || win(p*3,num) == 0 || win(p*4,num) == 0 || win(p*5,num) == 0 || win(p*6,num) == 0 || win(p*7,num) == 0 || win(p*8,num) == 0 || win(p*9,num) == 0);
    
    return dp[p] = res;
}
int main()
{
    LL num,res;
    while(cin >> num)
    {
    
        dp.clear();
        res = win(1,num);
        if(res)
            fout << "Stan wins." << endl;
        else
            fout << "Ollie wins." << endl;
    }
    return 0;
}