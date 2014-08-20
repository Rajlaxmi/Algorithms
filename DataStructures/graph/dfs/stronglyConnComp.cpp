#include <iostream>
#include <vector>
#define addEdge(i, j) adjList[i].push_back(j);
using namespace std;

vector<vector<int> > adjList;
int n;
/*
3 <- 2 <- 0    1
| /  |  / |/  |
4 <- 5 <- 6 <- 7
*/
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
int t = 0;
void dfsvisit(int i, int n, bool* visited, int* f)
{
	visited[i] = true;
	t++;
	int len = adjList[i].size(), j;
	for(j=0; j<len; j++)
	{
		if(visited[adjList[i][j]] == false)
			dfsvisit(adjList[i][j], n, visited, f);
	}
}

void dfs(int n)
{
	bool visited[n];
	int f[n], i;
	for(i=0; i<n; i++)
		visited[i] = false;
	for(i=0; i<n; i++)
		if(visited[i] == false)
			dfsvisit(i, n, visited, f);
}

int main()
{
	//cin>>n;
	n = 8;
	adjList.resize(n);
	buildGraph();
	dfs(n);
	return 0;
}
