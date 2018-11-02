#include<bits/stdc++.h>
using namespace std;
int get_max(int bit[],int index)
{
  index++;
  int sum=0;
  while(index>0)
  {
    sum+=bit[index];
    index-=index&(-index);
  }
  return sum;
}
void update(int bit[],int index,int value,int n)
{
  index++;
  while(index<=n)
  {
    bit[index]+=value;
    index+=index&(-index);
  }
}
int * construct_bit(int n)
{
  int *bit=new int[n+1];
  for(int i=0;i<=n;i++)
   bit[i]=0;

  return bit;

}
int main()
{
 int a[]={9,1,0,5,4};
 int inv=0;
 int n=sizeof(a)/sizeof(a[0]);
 int b[n];
 int *bit=construct_bit(n);
 for(int i=0;i<n;i++)
  b[i]=a[i];
 sort(b,b+n);

 for(int i=0;i<n;i++)
 {
  int ind=(int)(lower_bound(b,b+n,a[i])-b);
  a[i]=ind+1;
 }
  for(int i=n-1;i>=0;i--)
  {
    inv+=get_max(bit,a[i]-1);
    cout<<inv<<" ";
    update(bit,a[i],1,n);
  }
  //cout<<"inversions: "<<inv<<endl;
  return 0;
}
