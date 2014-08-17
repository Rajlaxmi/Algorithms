#include <iostream>
#include <cmath>
using namespace std;

int pthDigit(int n, int p)
{
	return (n/(int) pow(10, p))%10;
}

void countSort(int *a, int* b, int p, int n)
{
	//Sort according to pth digit
	int a1[n], c[10], i, x;
	for(i = 0; i < n; i++)
		a1[i] = pthDigit(a[i], p);
		
	for(i = 0; i < 10; i++)
		c[i] = 0;
	for(i = 0; i < n; i++)
		c[a1[i]]++;
	for(i = 1; i < 10; i++)
		c[i]+=c[i-1];
	for(i = n-1; i >= 0; i--)
	{
		x = c[a1[i]]-1;
		b[x] = a[i];
		c[a1[i]]--;
	}
	for(i = 0; i < n; i++)
		a[i] = b[i];
}

void radixSort(int* arr, int* arr1, int d, int n)
{
	for(int i=0; i<d; i++)
		countSort(arr, arr1, i, n);
}

int main()
{
	int n, d=4;
	cin>>n;
	int arr[n], arr1[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
		
	radixSort(arr, arr1, d, n);
	
	for(int i=0; i<n; i++)
		cout<<arr1[i]<<" ";
	cout<<endl;
	
	return 0;
}



