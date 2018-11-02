#include<bits/stdc++.h>
using namespace std;
int L[100][100];
void lcs( char *X, char *Y, int m, int n )
{

   int i, j;

   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }



}
void print_lcs(int i,int j,char *X,char *Y)
{
  if(i==0||j==0)
   return;
  if(X[i-1]==Y[j-1])
  {
    print_lcs(i-1,j-1,X,Y);
    cout<<X[i];
  }
  else if(L[i-1][j]>=L[i][j-1])
  {
    print_lcs(i-1,j,X,Y);
  }
  else if(L[i-1][j]<L[i][j-1])
  {
    print_lcs(i,j-1,X,Y);
  }

}
int main()
{
  char X[] = "ABCBDAB";
  char Y[] = "BDCABA";
  int m,n;
  m=strlen(X);
  n=strlen(Y);
  cout<<L[m][n]<<endl;
  lcs(X,Y,m,n);
  print_lcs(m,n,X,Y);
  return 0;

}

