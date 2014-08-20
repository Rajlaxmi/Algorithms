#include <iostream>
#include <vector>
#include <stack>
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

void dfs(int n)
{
	bool visited[n];
	for(int i = 0; i < n; i++)
		visited[i] = false;
	stack<pair<int,int> > st;
	pair<int,int> tp;
	int curr, pos, len;
	
	
	for(int i = 0; i < n; i++) 
	{
		if(visited[i] == false)
		{
			st.push(make_pair(i,0));
			cout<<"Discovered "<<i<<endl;
			while(st.size() > 0)
			{
				tp = st.top();
				curr = tp.first;
				pos = tp.second;
				len = adjList[curr].size();
				
				visited[curr] = true;
				if(pos < len)
				{
					if(visited[adjList[curr][pos]] == false)
					{
						cout<<"Discovered "<<adjList[curr][pos]<<endl;
						st.pop();
						st.push(make_pair(curr, pos+1));
						st.push(make_pair(adjList[curr][pos], 0));
					}
					else
					{
						while(pos<len && visited[adjList[curr][pos]] == true)
							pos=pos+1;
					}
				}
				if(pos == len)
					st.pop();
			}
		}
	}
}

int main()
{
	//cin>>n;
	n = 8;
	adjList.resize(n);
	buildGraph();
	dfs(n);
	return 0;
}

