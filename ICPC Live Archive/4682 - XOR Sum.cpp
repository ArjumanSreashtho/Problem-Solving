#include<bits/stdc++.h>
using namespace std;

#define fout ofstream("output.txt")

#define INT_SIZE 32 

#define LL long long int

struct node
{
    int num;
    node *val[2];
    node()
    {
        num = 0;
        val[0] = val[1] = NULL;
    }
} *root;

void insert(node *root, int num)
{
    node *temp = root;
    for(int i = INT_SIZE-1; i >= 0; i--)
    {
        bool pos = num & (1 << i);
        if(temp->val[pos] == NULL)
        {
            temp->val[pos] = new node();
        }
        temp = temp->val[pos];
    }
    temp->num = num;
   // cout << "INSERT" << endl;
}

LL query(node *root, int num)
{
    node *temp = root;
    for(int i = INT_SIZE-1; i >= 0; i--)
    {
        bool pos = num & (1 << i);
        if(temp->val[1-pos] != NULL)
            temp = temp->val[1-pos];
        else if(temp->val[pos] != NULL)
            temp = temp->val[pos];
    }
    //cout << "QUERY " << endl;
    return num^(temp->num);
}

int main()
{
    int ts;
    scanf("%d", &ts);
    while(ts--)
    {
        root = new node();
        insert(root,0);
        int n, pre_xor = 0;
        LL ans = INT_MIN;
        scanf("%d", &n);
        int arr[n+10];
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        for(int i = 0; i < n; i++)
        {
            pre_xor = pre_xor^arr[i];
            insert(root,pre_xor);
            ans = max(ans,query(root,pre_xor));
        }
        //cout << ans << endl;
        printf("%lld\n", ans);
        //fout << ans << endl;
    }

    return 0;
}