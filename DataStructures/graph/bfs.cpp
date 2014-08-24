#include <iostream>
#include <vector>
#define addEdge(i, j) adjList[i].push_back(j);
using namespace std;
vector<int> par;
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
#include <queue>
void bfs(int s)
{
	bool visited[n];
	for(int i=0; i<n; i++)
		visited[i] = false;
	queue<int> nds;
	nds.push(s);
	visited[s] = true;
	int tp;
	par[s] = -1;
	while(!nds.empty())
	{
		tp = nds.front();
		nds.pop();
		cout<<tp<<endl;
		for(int j=0;j<adjList[tp].size(); j++)
		{
			if(visited[adjList[tp][j]] == false)
			{
				visited[adjList[tp][j]] = true;
				nds.push(adjList[tp][j]);
				par[adjList[tp][j]] = tp;
			}
		}
	}
}

int main()
{
	//cin>>n;
	int s=0;
	n = 8;
	adjList.resize(n);
	par.resize(n);
	buildGraph();
	bfs(s);
	
	for(int i=0; i<n; i++)
		cout<<par[i]<<" ";
	cout<<endl;
	return 0;
}

