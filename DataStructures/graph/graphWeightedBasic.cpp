#include <iostream>
#include <vector>
#include <climits>
#define addEdge(i, j, k) adjList[i].push_back(j); weight[i].push_back(k);
using namespace std;

vector<vector<int> > adjList, weight;
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



int main()
{
	n = 6;
	int s=0, v=4;
	adjList.resize(n);
	weight.resize(n);
	buildGraph();
	return 0;
}

