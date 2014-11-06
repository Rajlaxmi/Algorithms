#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#define pii pair<int, int>
#define ll long long int
#define loop(i, n) for(i=0; i<n; i++)
#define loopab(i, a, b) for(i=a; i<b; i++)
#define pb push_back
#define mk make_pair
using namespace std;
int n, m;
#define mx 100
int weights[mx][mx], tmp[mx][mx], minDist[mx][mx];

void compute() {
	int i, j, k, z;
	for(z = 0; z < n-1; z++) {
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				tmp[i][j] = minDist[i][j];
				for(k = 0; k<n; k++) {
					if(minDist[i][k] != INT_MAX && weights[k][j] != INT_MAX)
						tmp[i][j] = min(tmp[i][j], minDist[i][k] + weights[k][j]);
				}
			}
		}
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				minDist[i][j] = tmp[i][j];
	}
}

void print(int mat[mx][mx], int n, int m) {
	int i, j;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++)
			if(mat[i][j] == INT_MAX)
				cout<<-1<<" ";
			else
				cout<<mat[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	int i, j, x, y, w;
	cin>>n>>m;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			weights[i][j] = INT_MAX;
	for(i=0; i<n; i++)
			weights[i][i] = 0;
	for(i=0; i<m; i++) {
		cin>>x>>y>>w;
		weights[x-1][y-1] = w;
	}
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			minDist[i][j] = weights[i][j];
			
	compute();
	print(minDist, n, n);
	return 0;
}

