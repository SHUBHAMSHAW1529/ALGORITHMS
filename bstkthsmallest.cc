#include<bits/stdc++.h>
using namespace std;
struct node{
 struct node *left;
 struct node *right;
 int data;
 int sz;
};
struct node *ins(struct node *root,int key)
{
  if(root==NULL)
  {
   struct node *new_node=new struct node;
   new_node->left=NULL;
   new_node->right=NULL;
   new_node->sz=0;
   new_node->data=key;
   root=new_node;
  }
  else if(key<root->data)
  {
    root->left=ins(root->left,key);

  }
  else if(key>root->data)
  {
    root->right=ins(root->right,key);
  }
  root->sz++;
  return root;
}
int find_rank(struct node *root,int key)
{
  if(root->data==key)
  {
    if(root->left==NULL)
     return 1;
    else
     return (root->left)->sz+1;
  }
  else if(root->data<key)
  {
    if(root->left!=NULL)
    return (find_rank(root->right,key)+(root->left)->sz+1);
    else
    return 1+find_rank(root->right,key);
  }
  else if(root->data>key)
  {
    return find_rank(root->left,key);
  }
}
int main()
{
  struct node *root=NULL;
  root=ins(root,30);
  root=ins(root,13);
  root=ins(root,10);
  root=ins(root,15);
  root=ins(root,50);
  root=ins(root,40);
  root=ins(root,70);
  //cout<<root->data<<endl;
  cout<<find_rank(root,10);
  return 0;
}
