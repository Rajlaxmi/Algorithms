#include <iostream>
using namespace std;
int fixed(int* arr, int l, int h)
{
	if(l<=h)
	{
		if(l==h)
			if(arr[l] == l)
				return arr[l];
			else
				return -1;
		else
		{
			int m = (l+h)/2;
			if(arr[m] == m)
				return m;
			else if(arr[m] < m)
				return fixed(arr,m+1,h);
			else
				return fixed(arr,l,m-1);
		}
	}
	else
		return -1;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	cout<<fixed(arr,0,n-1)<<endl;
	return 0;
}

