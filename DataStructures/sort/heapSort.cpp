#include<iostream>
using namespace std;

void heapify(int *arr, int i, int n)
{
	while(i <= n/2)
	{
		if(arr[i] >= arr[2*i] && (2*i+1>n || arr[i] >= arr[2*i+1]))
		{}
		else if((arr[i] >= arr[2*i] && arr[i] < arr[2*i+1]) || arr[2*i] >= arr[2*i+1])
		{
			temp = arr[i];
			arr[i] = arr[2*i];
			arr[2*i] = temp;
			heapify(arr, 2*i, n);
		}
		else
		{
			temp = arr[i];
			arr[i] = arr[2*i + 1];
			arr[2*i + 1] = temp;
			heapify(arr, 2*i + 1, n);
		}
	}
}

void buildHeap(int* arr, int n)
{
	int i=0;
	for(i = n/2; i>=1; i--)
		heapify(arr, i, n);
}

int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1; i <= n; i++)
		cin>>arr[i];
	buildHeap(arr, n);
	//insertionSort(arr, n);
	for(int i=1; i <= n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}



