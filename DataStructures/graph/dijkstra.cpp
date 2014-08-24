#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
#define addEdge(i, j, k) adjList[i].push_back(j); weight[i].push_back(k);
using namespace std;
vector<vector<int> > adjList, weight;
int n;

void buildGraph()
{
	addEdge(0, 1, 1);
	addEdge(0, 2, 2);
	addEdge(1, 3, 3);
	addEdge(2, 3, 1);
}

void dijkstra(int s, int* dist, int* par)
{
	for(int i=0; i<n; i++)
		dist[i] = INT_MAX, par[i] = -1;
	dist[s]	= 0;
	set<pii> pq;
	pq.insert(make_pair(0,s));
	pii tp;
	int pops = 0, pos, d;
	while(!pq.empty() && pops<n)
	{
		tp = *pq.begin();
		pq.erase(pq.begin());
		pops++;
		d = tp.first;
		pos = tp.second;
		for(int i=0; i<adjList[pos].size(); i++) {
			if(dist[pos]+weight[pos][i] < dist[adjList[pos][i]]) {
				dist[adjList[pos][i]] = dist[pos]+weight[pos][i];
				par[adjList[pos][i]] = pos;
				pq.push(make_pair(dist[adjList[pos][i]],adjList[pos][i]));
			}
		}
		priority_queue<pii, vector<pii>, greater<pii> > copy(pq);
		
		while(!copy.empty())
		{
			tp = copy.top();
			cout<<tp.first<<":"<<tp.second<<" ";
			copy.pop();
		}
		cout<<endl;
	}
}

int main()
{
	//cin>>n;
	n = 4;
	int dist[n], par[n], s=0;
	adjList.resize(n);
	weight.resize(n);
	buildGraph();
	dijkstra(s, dist, par);
	for(int i=0; i<n; i++)
		cout<<i<<" "<<dist[i]<<" "<<par[i]<<endl;
		
	return 0;
}
