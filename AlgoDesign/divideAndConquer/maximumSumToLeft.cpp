#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,maxm;
	cin>>n;
	int arr[n],l[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
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
	
	for(int i=0; i<n; i++)
	{
		cout<<l[i]<<"  ";
	}
	cout<<endl;
	
	return 0;
}

