#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
int a[MAX],c[MAX],an[MAX];
int ans;
int b;
struct query
{
 int l,r,i;
}q[MAX];
struct comp
{
 bool operator()(struct query x,struct query y)
 {
   if(x.l/b!=y.l/b)
   {
     return x.l/b<y.l/b;
   }
   else
     return x.r<y.r;

 }
}myobject;
void add(int pos)
{
 c[a[pos]]++;
 if(c[a[pos]]==1)
  ans++;

}
void rem(int pos)
{
 c[a[pos]]--;
 if(c[a[pos]]==0)
  ans--;

}
int main()
{
  int n,m;

  int currentL=0,currentR=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
   scanf("%d",&a[i]);
  scanf("%d",&m);
  for(int i=0;i<m;i++)
  {
   scanf("%d",&q[i].l);
   scanf("%d",&q[i].r);
   q[i].i=i;
   q[i].l--;
   q[i].r--;
  }
   b=sqrt(n);
  sort(q,q+m,myobject);
  add(0);

  for(int i=0;i<m;i++)
  {


     while(currentL<q[i].l)
     {
       rem(currentL);
       currentL++;

     }

      while(currentL>q[i].l)
      {
       add(currentL-1);
       currentL--;
      }


     while(currentR<q[i].r)
     {
       add(currentR+1);
       currentR++;

     }


      while(currentR>q[i].r)
      {
       rem(currentR);
       currentR--;
      }

    an[q[i].i]=ans;
  }

 for(int i=0;i<m;i++)
  printf("%d\n",an[i]);

}
