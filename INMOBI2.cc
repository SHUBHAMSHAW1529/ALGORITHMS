#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define pii pair<int,int>
int a[M];
int x[M],y[M],D,n;
bool f[M];
struct comp{
  bool operator()(const pii &a,const pii &b)
  {
     return a.second>b.second;
  }
};
int w(int s,int d)
{
  int res;
  res=abs(x[d]-x[s])+(abs(y[d]-y[s]));
  res*=D;
  if(d!=n)
  res-=a[d-2];
  return res;
}
int dijkstra()
{
  memset(f,0,sizeof(bool)*M);
  int d[106];
  d[1]=0;
  for(int i=2;i<=n;i++)
   d[i]=INT_MAX;
  priority_queue<pii,vector<pii>,comp> q;
  q.push(pii(1,0));
  pii u;
  int v;
  int dis;
  while(!q.empty())
  {
    u=q.top();
    q.pop();
    v=u.first;
    if(f[v])
    continue;
    if(v==n)
    break;
    for(int i=2;i<=n;i++)
    {
      if(i!=v)
      {
        if(!f[i]&&d[v]+w(v,i)<d[i])
        {
           d[i]=d[v]+w(v,i);
           q.push(pii(i,d[i]));
        }
      }

    }
    f[v]=true;
  }
  return d[n];
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    //int n;
    cin>>n>>D;
    for(int i=0;i<n-2;i++)
     cin>>a[i];
    for(int i=1;i<=n;i++)
    {
      cin>>x[i];
      cin>>y[i];
    }
    int spill=dijkstra();
    cout<<spill<<endl;
  }
  return 0;
}

