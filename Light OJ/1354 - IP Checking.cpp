#include<bits/stdc++.h>
using namespace std;
int convert(int num)
{
    int res = 0, temp = 1;
    while(num)
    {
        res += (temp*(num%10));
        num /= 10;
        temp *= 2;
    }
    return res;
}
int main()
{
    int ts;
    cin >> ts;
    for(int t = 1; t <= ts; t++)
    {
        int dec[4],num,bin[4];
        bool ck = true;
        for(int i = 0; i < 4; i++)
        {
            cin >> dec[i];
            getchar();
        }
        for(int i = 0; i < 4; i++)
        {
            cin >> bin[i];
            getchar();
        }
        cout << "Case "<< t << ": ";
        for(int i = 0; i < 4; i++)
        {
            num = convert(bin[i]);
            if(num != dec[i])
            {
                cout << "No" << endl;
                ck = false;
                break;
            }
        }
        if(ck)
        {
            cout << "Yes" << endl;
        }
    }
    //getchar();
    return 0;
}

