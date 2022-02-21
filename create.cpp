// BST implementation
#include <iostream>
using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
};
node *createnode(int num)
{
    node *temp=new node();
    temp->data=num;
    temp->left=NULL;
    temp->right=NULL;
}
node *addnode(node*root,int num)
{
    if(root==NULL)
    {
        return createnode(num);
    }
    else if(num>root->data)
    {
        root->right=addnode(root->right,num);
    }
    else if(num<root->data)
    {
        root->left=addnode(root->left,num);
    }
    return root;
}
node*display(node *root)
{
    if(root!=NULL)
    {
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }
}
bool searchelement(node*root,int key)
{
    if(root==NULL)
    {
        return false;
    }
    if(key==root->data)
    {
        return true;
    }
     if(key>root->data)
    {
        return searchelement(root->right,key);
    }
    else
    {
        return searchelement(root->left,key);
    }
}
int main()
{
    node*root=NULL;
    root=addnode(root,40);
    root=addnode(root,30);
    root=addnode(root,60);
    root=addnode(root,65);
    root=addnode(root,70);
    display(root);
    cout<<"Enter the element to be searched";
    int key;
    cin>>key;
    if(searchelement(root,key))
    {
        cout<<"Element found";
    }
    else
    {
      cout<<"Element not found";
    }

    return 0;
}
