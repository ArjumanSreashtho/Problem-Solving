/*
ID: onlyjav1
LANG: C++
TASK: dualpal
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

string base_conversion(int num, int base)
{
    string s;
    while(num)
    {
        int mod = num%base;
        if(mod >= 10)
            s+=((char)(mod+7+'0'));
        else
        {
            s+=((char)mod+'0');
        }
        num /= base;
        
    }
    reverse(s.begin(), s.end());
    return s;
}

bool palindrome(string s)
{
    int l = s.size();
    for(int i = 0; i < l/2; i++)
    {
        if(s[i] != s[l-i-1])
            return false;
    }
    return true;
}

int main()
{
    
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int n,s;
    fin >> n >> s;
    for(int num = s+1, cnt = 0; cnt < n; num++)
    {
        int pal = 0;
        for(int base = 2; base < 11; base++)
        {
            string s = base_conversion(num, base);
            //cout << base<< " "<< s << endl;
            if(palindrome(s))
            {
                pal++;
                if(pal == 2)
                {
                    cnt++;
                    fout << num << endl;
                    break;
                }
            }
        }
    }
    return 0;
}