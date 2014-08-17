#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMedian(int* arr,int l,int h,int* arr1,int l1,int h1, int n)
{
	if(h-l < 2 && h1-l1 < 2)
	{
		vector<int> a;
		for(int i=l; i<=h; i++)
			a.push_back(arr[i]);
		
		for(int i=l1; i<=h1; i++)
			a.push_back(arr1[i]);
			
		sort(a.begin(),a.end());
		return a.at(n);
	}
	else
	{
		int m = (l+h)/2;
		int m1 = (l1+h1)/2;
		if(arr[m] > arr[m1])
			return findMedian(arr,l,m,arr1,m1,h1, n-(m1-l1));
		else
			return findMedian(arr,m,h,arr1,l1,m1, n-(m-l));
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
		
	int n1;
	cin>>n1;
	int arr1[n1];
	for(int i=0; i<n1; i++)
		cin>>arr1[i];
		
	cout<<findMedian(arr,0,n-1,arr1,0,n1-1, (n+n1)/2+1)<<endl;
	return 0;
}

