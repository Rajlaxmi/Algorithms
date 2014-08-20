#include <iostream>
#include <vector>
#define addEdge(i, j) adjList[i].push_back(j);
using namespace std;

vector<vector<int> > adjList;
int n;

void buildGraph()
{
	addEdge(0, 2);
	addEdge(0, 5);
	addEdge(1, 6);
	addEdge(1, 7);
	addEdge(2, 3);
	addEdge(2, 5);
	addEdge(3, 4);
	addEdge(3, 4);
	addEdge(4, 2);
	addEdge(5, 4);
	addEdge(6, 5);
	addEdge(7, 6);
	addEdge(7, 1);
}

void dfsvisit(int i, bool* visit, int* par, int* dist, int d)
{
	visit[i] = true;
	int len = adjList[i].size();
	dist[i] = d;
	for(int j=0; j<len; j++)
	{
		int u = adjList[i][j];
		if(visit[u] == false)
		{
			par[u] = i;
			dfsvisit(u, visit, par, dist, d+1);
		}
	}
}

void dfs(int* par, int* dist)
{
	bool visit[n];
	for(int i=0; i<n; i++)
	{
		visit[i] = false;
		par[i] = -1;
	}
	for(int i=0; i<n; i++)
		if(visit[i] == false)
			dfsvisit(i, visit, par, dist, 0);
}

int main()
{
	//cin>>n;
	n = 8;
	adjList.resize(n);
	buildGraph();
	int par[n];
	int dist[n];
	dfs(par, dist);
	for(int i = 0; i < n; i++)
		cout<<par[i]<<" ";
	cout<<endl;
	for(int i = 0; i < n; i++)
		cout<<dist[i]<<" ";
	cout<<endl;
	return 0;
}
