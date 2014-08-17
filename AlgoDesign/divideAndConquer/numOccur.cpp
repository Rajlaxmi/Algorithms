#include <iostream>
using namespace std;

int findFirst(int* arr,int l,int h,int x)
{
	if(l==h)
		if(arr[l] == x)
			return l;
		else
			return -1;
	else
	{
		int m = (l+h)/2;
		
	}
}

int main()
{
	int n,x;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
		
	cin>>x;
	cout<<findFirst(arr,0,n-1,x)<<endl;
	return 0;
}

