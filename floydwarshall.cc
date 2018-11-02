#include<bits/stdc++.h>
using namespace std;
#define INF 9999
#define V 50
int graph[V][V];
int dist[V][V];
void print_sol(int v)
{
 cout<<"respective distances are"<<endl;
 for(int i=0;i<v;i++)
 {
  for(int j=0;j<v;j++)
  {
   cout<<"for pairs"<<i<<" "<<j<<endl;
   if(dist[i][j]==INF)
   cout<<"INFINITY"<<endl;
   else
   cout<<dist[i][j]<<endl;
  }
 }
}
void floyd_warshall(int v)
{
 for(int i=0;i<v;i++)
 {
  for(int j=0;j<v;j++)
   dist[i][j]=graph[i][j];
 }
 for(int k=0;k<v;k++)
 {
  for(int i=0;i<v;i++)
  {
   for(int j=0;j<v;j++)
   {
     if(dist[i][k]+dist[k][j]<dist[i][j])
      dist[i][j]=dist[i][k]+dist[k][j];
   }
  }
 }
 print_sol(v);
}
int main()
{
 int v,w;
 cout<<"enter number of vertices"<<endl;
 cin>>v;
 cout<<"enter edges"<<endl;
 for(int i=0;i<v;i++)
 {
  cout<<"for vertex"<<" "<<i<<endl;
  for(int j=0;j<v;j++)
  {
    cin>>w;
    if(w==-1)
    graph[i][j]=INF;
    else
    graph[i][j]=w;
  }
 }
 floyd_warshall(v);
 return 0;
}
