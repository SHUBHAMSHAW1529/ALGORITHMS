#include<bits/stdc++.h>
#define M 100005
using namespace std;
int a[M];
void quicksort(int l,int r)
{
  //cout<<l<<" "<<r<<endl;
  if(l<r)
  {
    int i=l,j=r;
    int pivot=a[l];
    while(i<j)
    {
       //cout<<"s"<<endl;
      while(a[i]<=pivot)
      {
        //cout<<i<<endl;
        i++;
      }
      while(a[j]>pivot)
      {
        //cout<<j<<endl;
        j--;
      }
      if(i<j)
      swap(a[i],a[j]);

    }
    swap(a[l],a[j]);

    quicksort(l,j-1);
    quicksort(j+1,r);
  }
}
int main()
{
  int n;
  cout<<"enter number of elements"<<endl;
  cin>>n;
  cout<<"enter elements"<<endl;
  for(int i=0;i<n;i++)
   cin>>a[i];
 a[n]=INT_MAX;
  quicksort(0,n-1);
  cout<<"elements in sorted order"<<endl;
  for(int i=0;i<n;i++)
   cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}
