#include<bits/stdc++.h>
using namespace std;
struct node
{
  struct node *left;
  struct node *right;
  int key;
  int height;
};
int height(struct node *root)
{
  if(root==NULL)
  return 0;
  else
  return root->height;
}
struct node* newNode(int key)
{
    struct node* root = new node;
    root->key   = key;
    root->left   = NULL;
    root->right  = NULL;
    root->height = 1;
    return(root);
}
struct node * right_rotate(struct node *root)
{
  struct node *pivot;
  pivot=root->left;
  root->left=pivot->right;
  pivot->right=root;
  root->height=max(height(root->left),height(root->right))+1;
  pivot->height=max(height(pivot->left),height(pivot->right))+1;
  return pivot;
}
struct node *left_rotate(struct node *root)
{
  struct node*pivot;
  pivot=root->right;
  root->right=pivot->left;
  pivot->left=root;
  root->height=max(height(root->left),height(root->right))+1;
  pivot->height=max(height(pivot->left),height(pivot->right))+1;
  return pivot;
}
int balance(struct node*root)
{
  if(root==NULL)
  return 0;
  return height(root->left)-height(root->right);
}
struct node* ins(struct node *root,int key)
{
  if(root==NULL)
  return newNode(key);
  if(key<root->key)
  root->left=ins(root->left,key);
  if(key>root->key)
  root->right=ins(root->right,key);
  root->height=max(height(root->left),height(root->right))+1;
  int bal=balance(root);
  if(bal>1&&key<(root->left)->key)
    return right_rotate(root);
  if(bal<-1&&key>(root->right)->key)
    return left_rotate(root);
  if(bal>1&&key>(root->left)->key)
  {
     root->left=left_rotate(root->left);
     return right_rotate(root);
  }
  if(bal<-1&&key<(root->right)->key)
  {
     root->right=right_rotate(root->right);
     return left_rotate(root);
  }
  return root;
}
void inorder(struct node *root)
{
  if(root)
  {
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
  }
}
int main()
{
  struct node *root=NULL;
  int ch;
  int elem;
  while(1)
  {
    cout<<"enter your choice \n0(exit)\n1(insert)\n2(inorder)\n"<<endl;
    cin>>ch;
    switch(ch)
    {
      case 0:
      exit(1);
      case 1:
      cout<<"enter element"<<endl;
      cin>>elem;
      root=ins(root,elem);
      break;
      case 2:
      inorder(root);
      break;
    }
  }

  return 0;
}
