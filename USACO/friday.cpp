/*
ID: onlyjav1
LANG: C++
TASK: friday
*/
#include<bits/stdc++.h>
using namespace std;


int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    
    int n, x = 0;
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days[7] = {0,0,0,0,0,0,0};

    fin >> n;

    for(int i = 1900; i <= 1900+n-1; i++)
    {
        if(i % 400 == 0 || (i % 4 == 0 && i %100 != 0))
        {
            months[1] = 29;
        }
        else
        {
            months[1] = 28;
        }
        for(int j = 0; j < 12; j++)
        {
            int day = 0;
            for(int k = 1; k <= months[j]; k++)
            {
                day = (k-1+x)%7;
                if(k == 13)
                {
                    days[day]++;
                }
            }
            x = day+1;
        }
        
    }
    fout << days[5] << " " << days[6] << " ";
    for(int i = 0; i < 5; i++)
    {
        fout << days[i];
        if(i < 4)
            fout << " ";
    }
    fout << endl;
    return 0;
}

