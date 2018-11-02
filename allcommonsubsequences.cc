#include<bits/stdc++.h>
using namespace std;
int l[105][105];
char str[100],str2[100],temp[100];
int tcs()
{
  int m=strlen(str);
  int n=strlen(str2);
  for(int i=0;i<=m;i++)
  {
    for(int j=0;j<=n;j++)
    {
      if(i==0||j==0)
      l[i][j]=0;
      if(str[i-1]==str2[j-1])
       l[i][j]=2*l[i-1][j-1]+1;
      else
       l[i][j]=(l[i][j-1]+l[i-1][j]-l[i-1][j-1]);
    }
  }
  return l[m][n];
}
int main()
{
  strcpy(str,"aab");
  strcpy(str2,"baa");
  //cout<<str<<" "<<str2<<endl;
  int ans;
  ans=tcs();
  cout<<ans<<endl;
  return 0;
}
