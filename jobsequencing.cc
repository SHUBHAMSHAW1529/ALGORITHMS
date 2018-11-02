#include<bits/stdc++.h>
using namespace std;
#define M 100005
struct job{
 char id;
 int dead;
 int profit;
};
struct comp{
  bool operator()(const struct job a,const struct job b )
 {
   return a.profit>b.profit;
 }
}myobject;
void job_sequencing(struct job j[],int n)
{
  int result[n];
  bool slot[n];
  sort(j,j+n,myobject);
  for(int i=0;i<n;i++)
   slot[i]=false;
  for(int i=0;i<n;i++)
  {
     for(int k=min(n,j[i].dead)-1;k>=0;k--)
     {
        if(slot[k]==false)
        {
          slot[k]=true;
          result[k]=i;
          break;
        }
     }
  }
  for(int i=0;i<n;i++)
  {
    if(slot[i])
    cout<<j[result[i]].id<<" ";

  }
  cout<<endl;
}
int main()
{
    job arr[5] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs\n";
    job_sequencing(arr, n);
    return 0;
}
