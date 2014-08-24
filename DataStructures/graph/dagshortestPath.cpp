#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>
#define addEdge(i, j, k) adjList[i].push_back(j); weight[i].push_back(k);
using namespace std;

vector<vector<int> > adjList, weight;
vector<pair<int, int> > last;
int n, t;
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

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > a.second;
}

void dagvisit(int curr, int* dagv, bool* visited)
{
	visited[curr] = true;
	for(int i=0; i<adjList[curr].size(); i++)
		if(visited[adjList[curr][i]] == false)
			dagvisit(adjList[curr][i], dagv, visited);
	t++;
	last[curr] = make_pair(t, curr);
	dagv[curr] = t;
}

void dag(int* dagv)
{
	bool visited[n];
	for(int i=0; i<n; i++)
		visited[i] = false;
	t = 0;
	for(int i=0; i<n; i++)
		if(visited[i] == false)
			dagvisit(i, dagv, visited);
			
	sort(last.begin(), last.end(), cmp);
	
	for(int i=0; i<n; i++)
		visited[i] = false;
	t = 0;
	
	for(int i=0; i<n; i++)
		if(visited[last[i].second] == false)
			dagvisit(last[i].second, dagv, visited);
}

int main()
{
	n = 6;
	int s=0, v=4;
	adjList.resize(n);
	weight.resize(n);
	buildGraph();
	int dagv[n];
	dag(dagv);
	for(int i=0; i<n; i++)
		cout<<dagv[i]<<" ";
	cout<<endl;
		
	return 0;
}

