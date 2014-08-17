#include<iostream>
using namespace std;

void insertionSort(int* arr, int n)
{
	int i,j,minm,pos,temp;
	for(i=0; i<n; i++)
	{
		minm=arr[i];
		pos=i;
		for(j=i+1; j<n; j++)
		{
			if(arr[j] < minm)
			{
				minm=arr[j];
				pos=j;
			}
		}
		if(arr[i] != arr[pos])
		{
			temp = arr[i];
			arr[i] = arr[pos];
			arr[pos] = temp;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	insertionSort(arr, n);
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}

