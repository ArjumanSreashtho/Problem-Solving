#include <bits/stdc++.h>

using namespace std;

#define ESP 1e-9

int main()
{
    double num;
    int cnt = 0;
    string ans = "";
    cin >> num;
    while(num > ESP)
    {
        if(cnt > 32)
        {
            ans = "ERROR";
            break;
        }
        num *= 2;
        int temp = (int)num;
        ans += (temp+48);
        cnt++;
        num -= temp;
    }
    cout << ans << endl;
    return 0;
}
