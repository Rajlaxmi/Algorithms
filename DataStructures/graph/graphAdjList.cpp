#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct vertex
{
	int data;
	vertex* next;
};

class Graph
{
	int sz;
	vertex* adjList;
public:
	Graph(int n)
	{
		adjList = (vertex*) malloc(n*sizeof(vertex*));
		sz = n;
		for(int i = 0; i < sz; i++)
			adjList[i].data = i, adjList[i].next = NULL;
	}
	void print()
	{
		cout<<sz<<endl;
		for(int i = 0; i < sz; i++)
			cout<<adjList[i].data<<" ";
		
		cout<<endl;
	}
};

int main()
{
	Graph gph(5);
	gph.print();
	cout<<"here"<<endl;
	return 0;
}
