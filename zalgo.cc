#include<bits/stdc++.h>
using namespace std;
int z[100005];
void z_algo(string s)
{
 int l=0,r=0;
 int n=s.size();
  for(int i=1;i<n;i++)
  {
    if(r<i)
    {
     l=r=i;
     while(r<n&&s[r]==s[r-l])
      r++;
     r--;
     z[i]=r-l+1;
    }
    else
    {
     int k=i-l;
     if(z[k]<r-i+1)
      z[i]=z[k];
     else
     {
      l=i;
      while(r<n&&s[r]==s[r-l])
       r++;
      r--;
      z[i]=r-l+1;
     }
    }
  }
}
int main()
{
 string s;
 cin>>s;
 z_algo(s);
 for(int i=1;i<s.size();i++)
  cout<<z[i]<<" ";
return 0;
}
