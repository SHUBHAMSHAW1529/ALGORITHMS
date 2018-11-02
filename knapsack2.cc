#include<bits/stdc++.h>
using namespace std;
bool pick[100][100];
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   bool p = false;
   int temp1,temp2,res;
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 {
                   temp1=val[i-1] + K[i-1][w-wt[i-1]];
                   temp2=K[i-1][w];
                   if(temp1>temp2)
                   {
                     pick[i][w]=true;
                     res=temp1;
                   }
                   else
                    res=temp2;
                   K[i][w] =res;

                 }
           else
                 K[i][w] = K[i-1][w];
       }
   }

  return K[n][W];
}
int main()
{
  int n;
  int val[100];
  int wt[100];
  int w;
  cout<<"enter capacity of knapsack"<<endl;
  cin>>w;
  cout<<"enter number of items"<<endl;
  cin>>n;
  cout<<"enter weight and corresponding value"<<endl;
  for(int i=0;i<n;i++)
  {

    cin>>wt[i];
    cin>>val[i];
  }
  cout<<"maximum attained value is"<<endl;
  cout<<knapSack(w,wt,val,n)<<endl;
  cout<<"proceede like this"<<endl;
  int t=w;
  for(int i = n;i>=0;i--)
  {
     if(pick[i][t]==true)
     {
       cout<<"pick element "<<i<<endl;
       t-=wt[i-1];
     }

  }
  return 0;
}
