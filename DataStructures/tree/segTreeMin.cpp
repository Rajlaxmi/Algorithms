#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int fillSegTree(int* segTree, int* arr, int i, int j, int k)
{
	if(i == j)
	{
		segTree[k] = arr[i];
		return segTree[k];
	}
	else
	{
		int m = (i+j)/2;
		segTree[k] = min(fillSegTree(segTree, arr, i, m, 2*(k+1)-1), fillSegTree(segTree, arr, m+1, j, 2*(k+1)));
		return segTree[k];
	}
}

int query(int* segTree, int x, int y, int s, int e, int k)
{
	if(x == s && y == e)
		return segTree[k];
	else
	{
		int m = (s+e)/2;
		if(x <= m && y <= m)
			return query(segTree, x, y, s, m, 2*(k+1)-1);
		else if(x > m && y > m)
			return query(segTree, x, y, m+1, e, 2*(k+1));
		else
			return min(query(segTree, x, m, s, m, 2*(k+1)-1), query(segTree, m+1, y, m+1, e, 2*(k+1)));
	}
}

int main()
{
	int n, i;
	cin>>n;
	int arr[n];
	for(i=0; i<n; i++)
		cin>>arr[i];
	int size = pow(2, 1+(int)ceil(log2(n)));
	int segTree[size];
	for(i=0; i<size; i++)
		segTree[i] = -1;
	fillSegTree(segTree, arr, 0, n-1, 0);
	/*for(i=0; i<size; i++)
		cout<<segTree[i]<<" ";
	cout<<endl;*/
	int x, y;
	cin>>x>>y;
	cout<<query(segTree, x, y, 0, n-1, 0)<<endl;
}

