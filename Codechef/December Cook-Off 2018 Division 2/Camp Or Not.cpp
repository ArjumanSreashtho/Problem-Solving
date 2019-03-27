#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ts;
    scanf("%d", &ts);
    while(ts--)
    {
        int d, p, n,q,dead,req;
        int arr[50];
        memset(arr,0,sizeof(arr));
        scanf("%d", &d);
        for(int i = 1; i <= d; i++)
        {
            scanf("%d %d", &p, &n);
            arr[p] = n;
        }
        for(int i = 2; i < 50; i++)
            arr[i] += arr[i-1];
        // for(int i = 1; i <= 31; i++)
        //     cout << arr[i] << " ";
        // cout << endl;
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d %d", &dead, &req);
            if(arr[dead] >= req)
            {
                printf("Go Camp\n");
            }
            else
            {
                printf("Go Sleep\n");
            }
        }
    }
    return 0;
}