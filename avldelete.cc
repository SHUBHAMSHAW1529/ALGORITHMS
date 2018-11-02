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
struct node* max_node(struct node *root)
{
  if(root==NULL)
  return NULL;
  while(root->right!=NULL)
  root=root->right;
  return root;
}
struct node* del(struct node *root,int key)
{
  if(root==NULL)
  return NULL;
  if(key>root->key)
  root->right=del(root->right,key);
  else if(key<root->key)
  root->left=del(root->left,key);
  else
  {

     struct node *temp;
     if(root->left&&root->right)
     {
       temp=max_node(root->left);
       root->key=temp->key;
       root->left=del(root->left,temp->key);
     }
     else
     {
        temp=root;
        if(root->left)
        root=root->left;
        else if(root->right)
        root=root->right;
        else
        root=NULL;
        free(temp);

     }
  }
  if(root==NULL)
  return root;

  root->height = max(height(root->left), height(root->right)) + 1;
   int bal = balance(root);

    if (bal > 1 && balance(root->left) >= 0)
        return left_rotate(root);

    if (bal > 1 && balance(root->left) < 0)
    {
        root->left =  left_rotate(root->left);
        return right_rotate(root);
    }

    if (bal < -1 && balance(root->right) <= 0)
        return left_rotate(root);

    if (bal < -1 && balance(root->right) > 0)
    {
        root->right = right_rotate(root->right);
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
      cout<<"enter your choice:\n1.insert\n2.delete\n3.print\n4.exit\n"<<endl;
      cin>>ch;
      switch(ch)
      {
        case 1:
        cout<<"enter element"<<endl;
        cin>>elem;
        root=ins(root,elem);
        break;
        case 2:
        cout<<"enter element"<<endl;
        cin>>elem;
        root=del(root,elem);
        break;
        case 3:
        inorder(root);
        break;
        case 4:
        exit(1);
      }
    }
    return 0;
}

