#include <iostream>
#include <vector>
using namespace std;

/*
3 <- 2 <- 0    1
| /  |  / |/  |
4 <- 5 <- 6 <- 7
*/

enum color { WHITE, GRAY, BLACK };

struct vertex
{
	int id;
	color col;
	vertex* par;
	int d;
	int f;
};

vector<vector<vertex* > > adjList;
int t = 0;

void addEdge(int i, int j, vertex* vlist)
{
	adjList[i].push_back(&vlist[j]);
	//adjList[j].push_back(&vlist[i]);
}

void buildGraph(vertex* vlist)
{
	addEdge(0, 2, vlist);
	addEdge(0, 5, vlist);
	addEdge(1, 6, vlist);
	addEdge(1, 7, vlist);
	addEdge(2, 3, vlist);
	addEdge(2, 5, vlist);
	addEdge(3, 4, vlist);
	addEdge(3, 4, vlist);
	addEdge(4, 2, vlist);
	addEdge(5, 4, vlist);
	addEdge(6, 5, vlist);
	addEdge(7, 6, vlist);
	addEdge(7, 1, vlist);
}

int main()
{
	int n = 8;
	//cin>>n;
	vertex vlist[n];
	adjList.resize(n);
	buildGraph(vlist);
	dfs(vlist, n);
}
