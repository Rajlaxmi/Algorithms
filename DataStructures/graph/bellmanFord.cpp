#include <iostream>
#include <vector>
#include <climits>
#define addEdge(i, j, k) adjList[i].push_back(j); weight[i].push_back(k);
using namespace std;

vector<vector<int> > adjList, weight;
vector<int> par, d;
int n;
/*
3 <- 2 <- 0    1
| /  |  / |/  |
4 <- 5 <- 6 <- 7
*/
void buildGraph()
{
	addEdge(0, 1, 1);
	addEdge(0, 2, 2);
	addEdge(1, 3, -1);
	addEdge(2, 1, 3);
	addEdge(2, 4, 1);
	//addEdge(4, 1, -2);
	addEdge(4, 5, 2);
	addEdge(5, 3, 3);
}

void initialize(int s)
{
	int i;
	for(i=0; i<n; i++)
	{
		par[i] = -1;
		d[i] = INT_MAX;
	}
	d[s] = 0;
}

void relax(int u, int v, int w)
{
	if(d[v] > d[u]+w) {
		d[v] = d[u] + w;
		par[v] = u;
	}
}

bool bellMan(int s)
{
	initialize(s);
	int i,j,k;
	for(i=0; i<n-1; i++) //every vertex
		for(k=0; k<n; k++)
			for(j=0; j<adjList[k].size(); j++) //relax each edge
				relax(k, adjList[k][j], weight[k][j]);
			
	for(i=0; i<n; i++)
		for(j=0; j<adjList[i].size(); j++)
			if(d[adjList[i][j]] > d[i] + weight[i][j])
				return false;
				
	return true;
}

int main()
{
	n = 6;
	int s=0, v=4;
	adjList.resize(n);
	weight.resize(n);
	par.resize(n);
	d.resize(n);
	buildGraph();
	bool res = bellMan(s);
	if(res ==  false)
		cout<<"No path"<<endl;
	else {
		int v = 4;
		cout<<v<<endl;
		while(v != s) {
			v = par[v];
			cout<<v<<endl;
		}
	}
	return 0;
}
