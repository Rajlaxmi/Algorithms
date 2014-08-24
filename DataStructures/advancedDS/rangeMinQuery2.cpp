#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
//n processing, root(n) query cost
int main()
{
	int n, i, j, mn;
	cin>>n;
	int arr[n];
	for(i = 0; i < n; i++)
		cin>>arr[i];
	
	int rootn = (int) floor(sqrt(n));
	int num = (int) ceil(n/rootn);
	int pre[num];
	for(i = 0; i < num; i++)
	{
		mn = INT_MAX;
		for(j = i*rootn; j < (i+1)*rootn && j < n; j++)
		{
			mn = min(mn, arr[j]);
		}
		pre[i] = mn;
	}
	
	cin>>x>>y; //Range
	int s = x/rootn, e = y/rootn;
	mn = INT_MAX;
	if(s < x)
	{
		for(i = s*rootn; i <= x; i++)
			mn = min(mn, arr[i]);
		for(i = s+1; i <= e; i++)
			mn = min(mn, pre[i]);
		for(i = s+1; i <= e; i++)
	}
	
	return 0;
}


