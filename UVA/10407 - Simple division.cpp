#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num1, num2, ans;
    while(scanf("%d", &num1))
    {
        if(num1 == 0)
            break;
        ans = 0;
        while(scanf("%d", &num2))
        {
            if(num2 == 0)
                break;
            ans = __gcd(num2-num1,ans);
            //cout << num1 << " " << num2 << " " << ans << endl;
            num1 = num2;
        }
        ans = abs(ans);
        printf("%d\n", ans);
    }
    return 0;
}

