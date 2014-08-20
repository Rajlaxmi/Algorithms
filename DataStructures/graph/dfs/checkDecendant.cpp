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

int t = 0;

void dfsvisit(int v, bool* visit, int* s, int* e)
{
	visit[v] = true;
	t++;
	s[v] = t;
	int len = adjList[v].size();
	for(int i = 0; i < len; i++)
	{
		if(visit[adjList[v][i]] == false)
			dfsvisit(adjList[v][i], visit, s, e);
	}
	t++;
	e[v] = t;
}

void dfs(int* s, int* e, int n)
{
	int i = 0;
	bool visit[n];
	for(int i = 0; i < n; i++)
	{
		s[i] = -1;
		e[i] = -1;
		visit[i] = false;
	}
	i = 0;
	for(int i = 0; i < n; i++)
	{
		if(visit[i] == false)
			dfsvisit(i, visit, s, e);
	}
}

int main()
{
	//cin>>n;
	n = 8;
	adjList.resize(n);
	buildGraph();
	int s[n], e[n];
	dfs(s, e, n);
	for(int i = 0; i < n; i++)
		cout<<s[i]<<" ";
	cout<<endl;
	for(int i = 0; i < n; i++)
		cout<<e[i]<<" ";
	cout<<endl;
	return 0;
}

