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
int * construct_bit(int n,int arr[])
{
  int *bit=new int[n+1];
  for(int i=0;i<=n;i++)
   bit[i]=0;
  for(int i=0;i<n;i++)
   update(bit,i,arr[i],n);
  return bit;

}
int main()
{
 int a[]={2,4,6,12,8,4,9};
 int *bit;
int  n=sizeof(a)/sizeof(a[0]);
 bit=construct_bit(n,a);
 cout<<get_max(bit,1);
 //update(bit,1,2,n);
 //cout<<get_max(bit,3);
 return 0;
}
