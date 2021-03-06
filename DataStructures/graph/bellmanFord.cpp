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
int weights[mx][mx], minDist[mx][mx];

bool bellmanFord(int s) {
	int i, j, k;
	//bellman ford
	for(k=1; k<n; k++) {
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				if(minDist[s][j] != INT_MAX && weights[j][i] != INT_MAX &&
				 minDist[s][i] > minDist[s][j] + weights[j][i])
					minDist[s][i] = minDist[s][j] + weights[j][i];
			}
		}
	}
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(weights[j][i] != INT_MAX && minDist[s][j] != INT_MAX &&
			minDist[s][i] > minDist[s][j] + weights[j][i])
				return false;
	return true;
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
	int i, j, k, x, y, w, s;
	cin>>n>>m;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			weights[i][j] = INT_MAX, minDist[i][j] = INT_MAX;
	for(i=0; i<n; i++)
		weights[i][i] = 0, minDist[i][i] = 0;
	for(i=0; i<m; i++) {
		cin>>x>>y>>w;
		weights[x-1][y-1] = w;
	}
	cin>>s;
	if(!bellmanFord(s))
		cout<<"Negative Cycle Present"<<endl;
	else
		print(minDist, n, n);
	return 0;
}
