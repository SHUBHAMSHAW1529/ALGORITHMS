#include<bits/stdc++.h>
#define M 100005
#define pb(t) push_back(t)
using namespace std;
vector<int> v[M];
int indegree[M];
void cal_indegree(int n,int e)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<v[i].size();j++)
    {
       indegree[v[i][j]]++;
    }
  }
}
bool check_unique_top_sort(int n,int e)
{
   cal_indegree(n,e);
   queue<int> q;
   bool f=false;
   for(int i=0;i<n;i++)
   {
      //cout<<f<<" "<<i<<" "<<" "<<indegree[i]<<endl;
      if(indegree[i]==0&&!f)
      {
         q.push(i);
         f=true;
      }
      else if(f&&indegree[i]==0)
      {
        return false;
      }
   }

   f=false;
   int temp;
   while(!q.empty())
   {
      temp=q.front();
      cout<<temp<<" ";
      q.pop();
      f=false;
      for(int i=0;i<v[temp].size();i++)
      {
         if(--indegree[v[temp][i]]==0&&!f)
         {
            q.push(v[temp][i]);
            f=true;
         }
         else if(f&&indegree[v[temp][i]]==0)
         {
           return false;
         }


      }
   }
   return true;
}
int main()
{
  int n;
  cin>>n;
  int e;
  cin>>e;
  int s,d;
  for(int i=0;i<e;i++)
  {
    cin>>s>>d;
    v[s].pb(d);
  }
  bool f=check_unique_top_sort(n,e);
  if(f)
    cout<<"unique top sort"<<endl;
  else
    cout<<"no unique top sort"<<endl;
  return 0;
}
