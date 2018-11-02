#include<bits/stdc++.h>
using namespace std;
#define pii pair<char,int>
struct node{
 pii data;//first is character and second is its frequency//
 struct node *left;
 struct node *right;
};
struct comp{
 bool operator()(const struct node * a,const struct node * b)
 {
    return (a->data).second > (b->data).second;
 }
};
struct node * make_new_node(pii t)
{

  struct node * temp = new struct node;
  temp->data = t;
  temp->left = NULL;
  temp->right = NULL;
  return temp;

}
struct node* build_tree(pii a[],int n)
{
  struct node* root = NULL;
  pii t;
  priority_queue<struct node *,vector<struct node *>,comp> q;
  for(int i=0;i<n;i++)
  {
    q.push(make_new_node(a[i]));
  }
  struct node* l;
  struct node* r;
  struct node * temp;
  while(q.size() > 1)
  {
     l = q.top();
     q.pop();
     r = q.top();
     q.pop();
     t.first = '$';
     t.second = (l->data).second  +  (r->data).second;
     temp = make_new_node(t);
     temp->left = l;
     temp->right = r;
     q.push(temp);

  }
  root = q.top();
  q.pop();
  return root;
}
void print_array(int arr[],int len)
{
  for(int i=0;i<len;i++)
  cout<<arr[i];
  cout<<endl;
}
void print_codes(struct node *root,int arr[],int len)
{
  if(root==NULL)
   return;
  if(root->left==NULL&&root->right==NULL)
  {
    cout<<(root->data).first<<": ";
    print_array(arr,len);
  }
  if(root->left)
  {
    arr[len] = 0;
    print_codes(root->left,arr,len+1);
  }
  if(root->right)
  {
    arr[len] = 1;
    print_codes(root->right,arr,len+1);
  }

}
int main()
{
  struct node * root = NULL;
  char t1;
  int t2;
  pii a[100];
  int n;
  cout<<"enter number of characters"<<endl;
  cin>>n;
  cout<<"enter character and its frequency"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>t1;
    cin>>t2;
    a[i]=pii(t1,t2);
  }
  root = build_tree(a,n);
  int arr[100];
  cout<<"respective huffman codes are"<<endl;
  print_codes(root,arr,0);
  return 0;
}

