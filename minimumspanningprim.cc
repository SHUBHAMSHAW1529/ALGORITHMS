
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define pii pair<int,int>
#define pb(x) push_back(x)
vector<pii> g[MAX];//array of vectors//
bool f[MAX];
int d[MAX];
int result=0;
struct comp {
  bool operator() (const pii &a,const pii &b)
  {
      return a.second>b.second;//min priority queue//
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
    //cout<<u<<" "<<d[u]<<endl;

    q.pop();
    if(f[u])
    continue;
    result+=d[u];
    sz=g[u].size();
    for(int i=0;i<sz;i++)
    {
       v=g[u][i].first;
       w=g[u][i].second;
      if(!f[v]&&w<d[v])
      {
        d[v]=w;//distance updated//
        q.push(pii(v,d[v]));//pushed in the priority queue with new priority//
      }
    }
    f[u]=true;//done with u and it is no more liable for updation one vertex is processed exactly once//
  }

}
int main()
{
 int n,e,u,v,s,w;

 cin>>n;
 for(int i=1;i<=n;i++)
 {
  d[i]=INT_MAX;
 }

 cin>>e;

 for(int i=0;i<e;i++)
 {
   cin>>u>>v>>w;
   g[u].pb(pii(v,w));
   g[v].pb(pii(u,w));
 }


 dijkstra(1);
 cout<<result<<endl;

 return 0;
}
