#include <iostream>
using namespace std;
int main()
{
	int n,maxm;
	cin>>n;
	int arr[n],r[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	maxm = arr[n-1];
	r[n-1] = maxm;
	for(int i=n-2;i>=0;i--)
	{
		if(maxm + arr[i] < arr[i])
		{
			maxm = arr[i];
			r[i] = maxm;
		}
		else
		{
			maxm = maxm + arr[i];
			r[i] = maxm;
		}
	}
	
	for(int i=0; i<n; i++)
	{
		cout<<r[i]<<"  ";
	}
	cout<<endl;
	
	return 0;
}


