#include <iostream>
using namespace std;

int findMin(arr,int l,int h,int n)
{
	int m = (l+h)/2;
	if((m-1 > 0 && arr[m] < arr[m-1]) && (m+1 < n && arr[m] < arr[m+1]))
	{
	}
	else if(arr[m] < arr[m-1] && arr[m] > arr[m+1])
	{
	}
	else if(arr[m] > arr[m-1] && arr[m] < arr[m+1])
	{
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	int minm = findMin(arr,0,n-1,n);
	
	return 0;
}
