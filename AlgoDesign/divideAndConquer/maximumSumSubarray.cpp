#include <iostream>
using namespace std;
int main()
{
	int n,x;
	cin>>n;
	x = n;
	int arr[n],l[n],r[n];
	while(x-- > 0)
	{
		cin>>arr[n-x];
	}
	
	//maximum sum to the right
	maxm = arr[n-1];
	r[n-1] = maxm;
	for(int i=n-2;i>=0;i--)
	{
		if(maxm + arr[i] < arr[i])
		{
			maxm = max(maxm + arr[i], arr[i]);
			r[i] = maxm;
		}
		else
		{
			maxm = maxm + arr[i];
			r[i] = maxm;
		}
	}
	
	//maximum sum to left
	maxm = arr[0];
	l[0] = maxm;
	for(int i=1;i < n; i++)
	{
		if(maxm + arr[i] < maxm)
		{
			maxm = max(maxm + arr[i], arr[i]);
			l[i] = maxm;
		}
		else
		{
			maxm = maxm + arr[i];
			l[i] = maxm;
		}
	}
	
	//actual divide and conquer
	
}
