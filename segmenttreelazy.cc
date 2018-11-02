#include<bits/stdc++.h>
using namespace std;
#define M 300005
#define lo long long
#define MOD 1000000007
lo seg_tree[M],arr[M];
void propagate(int node,int a,int b);
struct state
{
 int status;//status;
 lo val;
}s[M];
void operate(int node,int type,int a,int b)
{
 switch(type)
{
   case 1:
         seg_tree[node]=((b-a+1)*s[node].val)%MOD;
         break;
   case 2:
         seg_tree[node]=(seg_tree[node]+(b-a+1)*s[node].val)%MOD;
         break;
   case 3:
         seg_tree[node]=(seg_tree[node]%MOD*s[node].val%MOD)%MOD;
}

}
void propagate_util(int child,int par,int a,int b)
{

  if(s[par].status==1)
  {
   s[child].status=1;
   s[child].val=s[par].val;
  }
  else if(s[par].status==2)
  {
   if(s[child].status==2||s[child].status==0)
   {
    s[child].val=(s[child].val+s[par].val)%MOD;
    s[child].status=2;
   }
   else
   {
    propagate(child,a,b);
    s[child].val=(s[child].val+s[par].val)%MOD;
    s[child].status=2;
   }
  }
  else if(s[par].status==3)
  {
   if(s[child].status==0)
   {
    s[child].val=s[par].val;
    s[child].status=3;
   }
   else if(s[child].status==3)
   {
    s[child].val=(s[child].val*s[par].val)%MOD;
    s[child].status=3;
   }
   else
   {
    propagate(child,a,b);
    s[child].val=s[par].val;
    s[child].status=3;
   }
  }



}
void propagate(int node,int a,int b)
{
 if(s[node].status==0)
 return;
 operate(node,s[node].status,a,b);
 if(a==b)
 {
  s[node].status=0;
  s[node].val=0;
  return;
 }
 int lc=2*node+1;
 int rc=2*node+2;
 int mid=(a+b)/2;
 propagate_util(lc,node,a,mid);
 propagate_util(rc,node,mid+1,b);
 s[node].status=0;
 s[node].val=0;

}
lo build_tree(int a,int b,int node)//a and b are segments of node//
{
 if(a==b)
 {
  seg_tree[node]=arr[a];
  return arr[a];
 }

  int mid=(a+b)/2;
  lo left=build_tree(a,mid,2*node+1);
  lo right=build_tree(mid+1,b,2*node+2);
  seg_tree[node]=(left+right)%MOD;
  return seg_tree[node];

}
void update(int a,int b,int node,int l,int r,int val,int type)
{

 if(s[node].status!=0)//node is not upto date//
 {



   propagate(node,a,b);


 }
 if(a>b||a>r||b<l)
 return ;
 if(a>=l&&b<=r)//if the segment fits in the range we return//
 {



    s[node].status=type;
    s[node].val=val;
    propagate(node,a,b);


   return;
 }
 int mid=(a+b)/2;
 update(a,mid,2*node+1,l,r,val,type);
 update(mid+1,b,2*node+2,l,r,val,type);
 seg_tree[node]=(seg_tree[2*node+1]+seg_tree[2*node+2])%MOD;
}
lo range_query(int a,int b,int node,int l,int r)
{
   if(s[node].status!=0)//node is not upto date//
   {



       propagate(node,a,b);


   }

  if(a>r||b<l)
  return 0;
  if(a>=l&&b<=r)//if the segment fits in the range we return//
  return seg_tree[node];
  int mid=(a+b)/2;
  int left=range_query(a,mid,2*node+1,l,r);
  int right=range_query(mid+1,b,2*node+2,l,r);
  return (left+right)%MOD;

}
int main()
{



  int n,q;
  cin>>n>>q;
  for(int i=0;i<n;i++)
   cin>>arr[i];
  build_tree(0,n-1,0);
  for(int i=0;i<M;i++)
  {
    s[i].status=0;
    s[i].val=0;
  }
  int type,v;
  while(q--)
  {
   int x,y;

    cin>>type>>x>>y;
    x--;
    y--;
    if(type==1)
    {
     cin>>v;
     update( 0,n-1,0,x,y,v,2);
    }
    else if(type==2)
    {
     cin>>v;
     update( 0,n-1,0,x,y,v,3);
    }
    else if(type==3)
    {
     cin>>v;
     update( 0,n-1,0,x,y,v,1);
    }
    else  if(type==4)
    {
     printf("%lld\n",range_query(0,n-1,0,x,y));
    }

  }


 return 0;

}


