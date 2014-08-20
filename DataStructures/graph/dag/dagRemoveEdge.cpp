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

int dagvisit(int i, int* dagv, bool* visited, int k)
{
	visited[i] = true;
	int len = adjList[i].size();
	for(int j = 0; j<len; j++)
	{
		if(visited[adjList[i][j]] == false)
			k = dagvisit(adjList[i][j], dagv, visited, k);
	}
	if(k >= 0)
		dagv[k] = i;
	k--;
	return k;
}

list<int> top;

void dag(int n, int* dagv) 
{
	bool visited[n], indeg[n];
	int k = n-1, i;
	for(i = 0; i<n; i++) {
		visited[i] = false;
		dagv[i] = -1;
	}
	
	for(i=0; i < adjList.size(); i++)
		for(j = 0; j<adjList[i].size(); j++)
			indeg[adjList[i][j]]++;
	for(i = 0; i<n; i++)
		if(indeg[i] == 0)
			top.push_back(i);
	while(top.size() > 0)
	{
		
	}
}

int main()
{
	//cin>>n;
	n = 8;
	adjList.resize(n);
	buildGraph();
	int dagv[n];
	dag(n, dagv);
	for(int i = 0; i<n; i++) 
		cout<<dagv[i]<<" ";
	cout<<endl;
	return 0;
}

