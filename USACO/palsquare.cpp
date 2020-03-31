/*
ID: onlyjav1
LANG: C++
TASK: palsquare
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
    
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int b;
    fin >> b;
    for(int i = 1; i <= 300; i++)
    {
        string s = base_conversion(i*i,b);
        if(palindrome(s))
        {
            fout << base_conversion(i,b) << " " << s << endl;
        }
    }
    return 0;
}