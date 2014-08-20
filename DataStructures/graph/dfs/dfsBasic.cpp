#include <iostream>
#include <vector>
using namespace std;
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

void dfsvisit(vertex* v)
{
	//cout<<v->id<<endl;
	int i;	
	t++;
	v->d = t;
	v->col = GRAY;
	int len = adjList[v->id].size();
	cout<<v->id<<" discovered"<<endl;
	for(i = 0; i < len; i++)
	{
		vertex* u = adjList[v->id][i];
		//cout<<u->id<<" to visit"<<endl;
		if(u->col == WHITE) {
			u->par = v;
			dfsvisit(u);
		}
	}
	t++;
	v->f = t;
	v->col = BLACK;
}

void dfs(vertex* vlist, int n)
{
	int i;
	t = 0;
	for(i = 0; i < n; i++)
	{
		vlist[i].col = WHITE;
		vlist[i].par = NULL;
		vlist[i].id  = i;
		//cout<<vlist[i].id<<endl;
	}
	for(i = 0; i < n; i++)
		if(vlist[i].col == WHITE)
			dfsvisit(&vlist[i]);
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
