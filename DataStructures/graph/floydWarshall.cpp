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
int weights[mx][mx], tmp[mx][mx], minDist[mx][mx], parent[mx][mx];

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
	int i, j, x, y, w, k;
	cin>>n>>m;
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			weights[i][j] = INT_MAX, parent[i][j] = -1;
			
	for(i=0; i<n; i++)
		weights[i][i] = 0;
		
	for(i=0; i<m; i++) {
		cin>>x>>y>>w;
		weights[x-1][y-1] = w;
		parent[x-1][y-1] = x-1;
	}
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			minDist[i][j] = weights[i][j];
	
	//Floyd Warshall
	for(k=0; k<n; k++) {
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				tmp[i][j] = minDist[i][j];
				if(minDist[i][k] != INT_MAX && minDist[k][j] != INT_MAX && minDist[i][k]+minDist[k][j] < tmp[i][j]) {
					tmp[i][j] = minDist[i][k]+minDist[k][j];
					parent[i][j] = parent[k][j];
				}
			}
		}
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				minDist[i][j] = tmp[i][j];
	}
	print(minDist, n, n);
	
	return 0;
}
