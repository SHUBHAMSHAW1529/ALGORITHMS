#include<bits/stdc++.h>
#define M 100005
#define lo long long
using namespace std;
lo a[M];
lo cum[M];
lo part[105][105];
int main()
{
 int k,n;
 cin>>k>>n;
 for(int i=0;i<n;i++)
 cin>>a[i];
 for(int i=1;i<=n;i++)
 cum[i]=cum[i-1]+a[i-1];
 //cout<<cum[n]<<endl;
 for(int i=1;i<=k;i++)
 {
   part[1][i]=a[0];


 }
 for(int i=1;i<=n;i++)
 {
   part[i][1]=cum[i];
   //cout<<part[i][1]<<endl;
 }
 for(int i=2;i<=k;i++)
 {
   for(int j=2;j<=n;j++)
   {
    lo best=LONG_LONG_MAX;
    for(int p=1;p<=j;p++)
    {
     best=min(best,max(part[p][i-1],cum[j]-cum[p]));
     //cout<<best<<endl;
    }
    part[j][i]=best;
    //cout<<part[j][i]<<endl;
   }

 }
 cout<<part[n][k]<<endl;
 return 0;
}
