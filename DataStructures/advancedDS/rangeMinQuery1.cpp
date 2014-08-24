#include <iostream>
#include <cmath>
using namespace std;
//Using DP, O(n), O(1), Updation cost n^2
int main()
{
	int n, i, j, mn;
	cin>>n;
	int arr[n];
	for(i = 0; i < n; i++)
		cin>>arr[i];
	
	int minm[n][n];
	for(i = 0; i<n; i++) {
		mn = arr[i];
		for(j = i+1; j < n; j++) {
			mn = min(mn, arr[i]);
			minm[i][j] = mn;
		}
	}
	
	cin>>i>>j;
	cout<<minm[i][j]<<endl;
	
	return 0;
}

