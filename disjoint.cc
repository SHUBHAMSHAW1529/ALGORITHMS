#include<bits/stdc++.h>
#define MAX 200005
using namespace std;
int p[MAX],memo[MAX],ch[MAX],ra[MAX],f[MAX];
void create_set(int x)
{
 memo[x]=x;
 p[x]=x;
 ra[x]=0;
 ch[x]=x;
}
int find_set(int x)
{

 if(x!=memo[x])
 {
  memo[x]=find_set(p[x]);

 }
 return memo[x];

}
void merge_set(int x,int y)
{

 int px=find_set(x);
 int py=find_set(y);
 if(ra[px]>ra[py])
 {
  p[py]=px;
  memo[py]=px;
  ch[px]=py;
 }
 else if(ra[px]<ra[py])
 {
  memo[px]=py;
  p[px]=py;
  ch[py]=px;
 }
 else
 {
  memo[px]=py;
  p[px]=py;
  ch[py]=px;
  ra[py]++;
 }


}
void rank_fixer(int x)
{
 if(x!=p[x])
 {
  rank_fixer(p[x]);
  if(ra[x]!=0)
  ra[x]--;
 }
 else if(ra[x]!=0)
 ra[x]--;
}
void memo_fixer(int x)
{
 int temp=ch[x];
 int del=x;
 while(ch[x]!=x)
 {
  if(memo[x]==x)
   memo[x]=temp;
  x=ch[x];
 }
}
void diff_set(int x)
{

 rank_fixer(x);
 memo_fixer(x);
 p[ch[x]]=p[x];
 memo[ch[x]]=p[x];
 ch[p[x]]=ch[x];
 p[x]=x;
 memo[x]=x;
 ra[x]=0;
}
int main()
{
 for(int i=1;i<=10;i++)
  create_set(i);
  merge_set(1,2);
  merge_set(1,3);
  merge_set(1,4);
  diff_set(2);
  cout<<ch[2]<<endl;
  return 0;
}
