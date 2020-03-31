#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int val)
{
    Node *nptr = new Node();
    nptr->data = val;
    nptr->next = NULL;
    return nptr;
}   

Node *insertNode(Node *root, int val)
{
    Node *tptr = root, *nptr = createNode(val);

    if(root == NULL)
    {
        root = nptr;
        return root;
    }
    while(tptr->next != NULL)
    {
        tptr = tptr->next;
    }
    tptr->next = nptr;
    return root;
}

Node *addList(Node *num1, Node *num2, Node *sum)
{
    int add = 0, carry = 0;
    Node *tptr = sum, *nptr = NULL;
    while(num1 != NULL && num2 != NULL)
    {
        add = (num1->data+num2->data+carry)%10;
        carry = (num1->data+num2->data+carry)/10;
        nptr = createNode(add);
        if(sum == NULL)
        {
            sum = nptr;
            tptr = sum;
        }
        else
        {
            tptr->next = nptr;
            tptr = tptr->next;
        }
        num1 = num1->next;
        num2 = num2->next;
    }
    while(num1 != NULL)
    {
        add = (num1->data+carry)%10;
        carry = (num1->data+carry)/10;
        nptr = createNode(add);
        tptr->next = nptr;
        tptr = tptr->next;
        num1 = num1->next;
    }
    while(num2 != NULL)
    {
        add = (num2->data+carry)%10;
        carry = (num2->data+carry)/10;
        nptr = createNode(add);
        tptr->next = nptr;
        tptr = tptr->next;
        num2 = num2->next;
    }
    return sum;
}

void print(Node *root)
{
    while(root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}

void printReverse(Node *root)
{
    if(root == NULL)
    {
        return ;
    }
    printReverse(root->next);
    cout << root->data << " ";
}

int main()
{
    Node *num1 = NULL, *num2 = NULL, *sum = NULL;
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        num1 = insertNode(num1, x);
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        num2 = insertNode(num2, x);
    }
    sum = addList(num1, num2, sum);
    printReverse(sum);
    cout << endl;
    return 0;
}