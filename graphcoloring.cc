#include<bits/stdc++.h>
using namespace std;
#define M 100005
vector<int> v[M];
bool available[M];
int result[M];
void add_edge(int u,int w)
{
  v[u].push_back(w);
  v[w].push_back(u);
}
void vertex_coloring(int n)
{
  result[0]=0;
  for(int i=1;i<n;i++)
   result[i]=-1;
  for(int i=1;i<n;i++)
   available[i]=false;

  for(int i=1;i<n;i++)
  {
    for(int j=0;j<v[i].size();j++)
      if(result[v[i][j]]!=-1)
        available[result[v[i][j]]]=true;

    for(int j=0;j<n;j++)
    {
       if(available[j]==false)
      {
         result[i]=j;
         break;
      }
    }
    for(int j=0;j<v[i].size();j++)
      if(result[v[i][j]]!=-1)
        available[result[v[i][j]]]=false;
  }
}
int main()
{
   int n,e;
   cout<<"enter number of vertices"<<endl;
   cin>>n;
   cout<<"enter number of edges"<<endl;
   cin>>e;
   cout<<"enter edges"<<endl;
   int u,v;
   while(e--)
   {
     cin>>u>>v;
     add_edge(u,v);
   }
   vertex_coloring(n);
   cout<<"respective colors are"<<endl;
   for(int i=0;i<n;i++)
   {
     cout<<"vertex "<<i<<":"<<result[i]<<endl;
   }
   return 0;
}
