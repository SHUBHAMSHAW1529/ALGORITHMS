#include<bits/stdc++.h>
#define ma 100005
using namespace std;
int p[ma],ra[ma];
struct Edge
{
 int src;
 int dest;
 int weight;
}edge[ma];
struct comp
{
 bool operator()(const Edge a,const Edge b)
 {
   return a.weight<b.weight;
 }
}myobject;
void create_set(int x)
{
 p[x]=x;
 ra[x]=0;
}
int find_set(int x)
{
 if(p[x]!=x)
 {
  p[x]=find_set(p[x]);
 }
 return p[x];
}
void merge_set(int x,int y)
{
 int px=find_set(x);
 int py=find_set(y);
 if(ra[px]>ra[py])
  p[py]=px;
 else if(ra[px]<ra[py])
  p[px]=py;
 else
 {
  p[px]=py;
  ra[py]++;
 }
}

int main()
{
 int n,m;
 int result=0;
 scanf("%d %d",&n,&m);
 for(int i=0;i<m;i++)
 {
  scanf("%d %d %d",&edge[i].src,&edge[i].dest,&edge[i].weight);
 }
 sort(edge,edge+m,myobject);
 int s,d,w;

 for(int i=1;i<=n;i++)
  create_set(i);
 for(int i=0;i<m;i++)
 {
  s=edge[i].src;
  d=edge[i].dest;
  w=edge[i].weight;

  if(find_set(s)!=find_set(d))
  {
   //cout<<"s";
   merge_set(s,d);
   result+=w;
  }
 }
 printf("%d\n",result);
 return 0;
}
