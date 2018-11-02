#include<iostream>
using namespace std;
int max_sub_array(int arr[],int n)
{
	int max_so_far=0,max_ending_here=0;
	for(int i=0;i<n;i++)
	{
		max_ending_here+=arr[i];
		if(max_ending_here<0)
		max_ending_here=0;
		else if(max_so_far<max_ending_here)//max_ending_here helps in updation of max_so_far//
		max_so_far=max_ending_here;
	}
	return max_so_far;
}
int main()
{
	int arr[]={5,-2,-1,-10,6};
	n=sizeof(arr)/sizeof(arr[0]);
	cout<<max_sub_array(arr,n)<<" "<<endl;
	return 0;
}
