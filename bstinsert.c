#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	struct node *left,*right;
	int data;
}node;
node *create(node *);
node *insert(node *,int);
void inorder(node *);
node *del(node *,int);
node *find_max(node *);

void main()
{
    node *root=NULL;
    int key;
	int ch;
	while(1)
	{
	  printf("enter you choice\n1.insert\n2.delete\n3.inorder traversal\n");
	  scanf("%d",&ch);
	  switch(ch)
     {
	   case 1:
	   printf("enter key\n");
	   scanf("%d",&key);
       root=insert(root,key);
	   break;
	   case 2:
	   printf("enter key\n");
	   scanf("%d",&key);
	   root=del(root,key);
	   break;
	   case 3:
       inorder(root);
       break;

	 }

	}


}
node *create(node *root)
{
	node *temp;
	int cl,cr;
	temp=calloc(1,sizeof(node));
	root=temp;
	printf("enter data in root\n");
	scanf("%d",&temp->data);
	printf("does the root with %d data posses a left child?\n 1.yes\n2.no\n",temp->data);
	scanf("%d",&cl);
	if(cl==1)
	{
		temp->left=create(temp);

	}
	else if(cl==2)
	{
		temp->left=NULL;
	}
	printf("does the root with data %d data posses a right child?\n1.yes\nno\n",temp->data);
	scanf("%d",&cr);
		if(cr==1)
	{
		temp->right=create(temp);

	}
	else if(cr==2)
	{
		temp->right=NULL;
	}
	return root;
}

node *insert(node *root,int key)
{
	node *temp;
	if(root==NULL)
	{
		temp=calloc(1,sizeof(node));
		temp->data=key;
		return temp;
	}
	if(key>root->data)
	root->right=insert(root->right,key);
	else if(key<root->data)
	root->left=insert(root->left,key);
	return root;
}
node *del(node *root,int data)
{
  if(root==NULL)
  printf("key is not in the tree\n");
  if(data>root->data)
  root->right=del(root->right,data);
  else if(data<root->data)
  root->left=del(root->left,data);
  else
  {
    if(root->left&&root->right)
    {
      node *temp=find_max(root->left);
      root->data=temp->data;
      root->left=del(root->left,temp->data);
    }
    else if(!root->left)
    root=root->right;
    else if(!root->right)
    root=root->left;
  }
  return root;
}
node *find_max(node *root)
{
 if(root==NULL)
 return NULL;
 if(root->right==NULL)
 return root;
 else
 return find_max(root->right);

}
void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
