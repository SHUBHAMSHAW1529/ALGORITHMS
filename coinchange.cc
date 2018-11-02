#include<bits/stdc++.h>
using namespace std;
#define lo long long
lo cnt( lo S[], int m, int n )
{
    lo i, j, x, y;


    lo table[n+1][m];


    for (i=0; i<m; i++)
        table[0][i] = 1;


    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {

            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;


            y = (j >= 1)? table[i][j-1]: 0;


            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}
int main()
{
  lo S[100005];
  lo n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
   cin>>S[i];
  lo ans=cnt(S,m,n);
  cout<<ans<<endl;
  return 0;
}
