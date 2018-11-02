#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define pii pair<int,int>
#define pb(x) push_back(x)
vector<pii> g[MAX];
bool f[MAX];
int d[MAX];
struct comp {
  bool operator() (const pii &a,const pii &b)
  {
      return a.second>b.second;
  }
};
priority_queue<pii,vector<pii>,comp> q;
void dijkstra(int starting)
{
  d[starting]=0;
  q.push(pii(starting,0));
  int u,v,w,sz;

  while(!q.empty())
  {
    u=q.top().first;
    q.pop();
    if(f[u])
    continue;
    sz=g[u].size();
    for(int i=0;i<sz;i++)
    {
       v=g[u][i].first;
       w=g[u][i].second;
      if(!f[v]&&d[u]+w<d[v])
      {
        d[v]=d[u]+w;
        q.push(pii(v,d[v]));
      }
    }
    f[u]=true;
  }

}
int main()
{
 int n,e,u,v,s,w;
 cout<<"enter number of vertices:\n";
 cin>>n;
 for(int i=0;i<n;i++)
 {
  d[i]=INT_MAX;
 }
 cout<<"enter number of edges:\n";
 cin>>e;
 cout<<"enter edges:\n";
 for(int i=0;i<e;i++)
 {
   cin>>u>>v>>w;
   g[u].pb(pii(v,w));
 }
 cout<<"enter source vertex";
 cin>>s;
 dijkstra(s);
 cout<<"Respective shortest distance from the source vertex are:\n";
 for(int i=0;i<n;i++)
 {
  cout<<"for vertex "<<i<<":"<<d[i]<<endl;

 }
 return 0;
}
