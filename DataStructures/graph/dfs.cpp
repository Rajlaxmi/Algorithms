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

void dfsVisit(int curr, bool* visited, int* par)
{
	visited[curr] = true;
	for(int i=0; i<adjList[curr].size(); i++) {
		if(visited[adjList[curr][i]] == false) {
			par[adjList[curr][i]] = curr;
			dfsVisit(adjList[curr][i], visited, par);
		}
	}
}

void dfs()
{
	bool visited[n], par[n];
	for(int i=0; i<n; i++)
		visited[i] = false, par[i]=-1;
	
	for(int i=0; i<n; i++)
		if(visited[i] == false)
			dfsVisit(i, visited, par);
	
}


int main()
{
	//cin>>n;
	n = 8;
	adjList.resize(n);
	buildGraph();
	dfs();
	return 0;
}

