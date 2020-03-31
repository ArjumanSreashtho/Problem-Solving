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

void removeDuplicate(Node *root)
{
    Node *tptr = NULL;
    while(root != NULL && root->next != NULL)
    {
        tptr = root;
        while(tptr->next != NULL)
        {
            if(root->data == tptr->next->data)
            {
                tptr->next = tptr->next->next;
            }
            else
            {
                tptr = tptr->next;
            }
            
        }
        root = root->next;
    }
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

int main()
{
    Node *root = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insertNode(root, x);
        //cout << root << endl;
    }
    print(root);
    //cout << root << endl;
    removeDuplicate(root);
    print(root);
    return 0;
}