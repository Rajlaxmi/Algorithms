#include<iostream>
using namespace std;

void countingSort(int* a, int* b, int* c, int n, int k)
{
	int i=0;
	for(i = 0; i < k; i++)
		c[i] = 0;
	for(i = 0; i < n; i++)
		c[a[i]]++;
	for(i = 1; i < k; i++)
		c[i]+=c[i-1];
	for(i = n-1; i >= 0; i--)
	{
		b[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}
}

int main()
{
	int n, k;
	cin>>n>>k;
	int a[n], b[n], c[k+1];
	for(int i=0; i<n; i++)
		cin>>a[i];
		
	countingSort(a, b, c, n, k+1);
	
	for(int i=0; i<n; i++)
		cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}



