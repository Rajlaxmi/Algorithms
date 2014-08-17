#include<iostream>
using namespace std;

int partition(int* arr, int p, int r)
{
	int i=p-1,x=arr[r],j,temp;
	for(j=p; j<r; j++)
	{
		if(arr[j] <= x)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp;
	return i+1;
}

void quickSort(int* arr, int p, int r)
{
	if(p < r)
	{
		int q = partition(arr, p, r);
		quickSort(arr, p, q-1);
		quickSort(arr, q+1, r);
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	quickSort(arr, 0, n-1);
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}


