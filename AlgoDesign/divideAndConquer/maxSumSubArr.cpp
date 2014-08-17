#include <iostream>
#include <cmath>
using namespace std;

int maxmCross(int* arr, int m, int n)
{
	int maxm = arr[m], x = m-1, maxmr = 0;
	while(x-- > 0)
	{
		if(maxm + arr[x] > maxm)
			maxm = maxm + arr[x];
		else
			break;
	}
	
	x = m+1;
	if(x < n)
		maxmr = arr[x];
	x++;
	while(x < n)
	{
		if(maxmr + arr[x] > maxmr)
			maxmr = maxmr + arr[x];
		else
			break;
		x++;
	}
	
	maxm = max(maxm, maxm+maxmr);
	return maxm;
}

int maxmSubArr(int* arr, int l, int h,int n)
{
	int m = (l+h)/2;
	if(l == h)
		return arr[l];
	else
	{
		int lmaxm = maxmSubArr(arr,l,m,n);
		int rmaxm = maxmSubArr(arr,m+1,h,n);
		int cmaxm = maxmCross(arr,m,n);
		return max(lmaxm,max(rmaxm,cmaxm));
	}
}

int main()
{
	int n,x;
	cin>>n;
	x = n;
	int arr[n];
	while(x--)
		cin>>arr[n-x-1];
	x = maxmSubArr(arr,0,n-1,n);
	cout<<"Maximum sum is "<<x<<endl;
	return 0;
}


