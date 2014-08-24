#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
int matrix[100];
bool visited[100];
int main()
{
	int t, i, j, x, y, ld, sn;
	cin>>t;
	while(t--)
	{
		for(i=0; i<100; i++)
				matrix[i] = 0;
		for(i=0; i<100; i++)
			visited[i] = false;
			
		scanf("%d,%d", &ld, &sn);
		for(i=0; i<ld; i++) {
			scanf("%d,%d ", &x, &y);
			matrix[x-1] = y-x;
		}
		for(i=0; i<sn; i++) {
			scanf("%d,%d ", &x, &y);
			matrix[x-1] = y-x;
		}
		
		queue<int> states;
		queue<int> states2;
		states.push(-1);
		int steps = 0;
		while(visited[99] == false)
		{
			steps++;
			while(!states.empty())
			{
				x = states.front();
				states.pop();
				for(j=1; j<=6; j++) {
					if(x+j+matrix[x+j]<100 &&x+j+matrix[x+j]>=0 && visited[x+j+matrix[x+j]] == false) {
						states2.push(x+j+matrix[x+j]);
						visited[x+j+matrix[x+j]] = true;
					}
				}
			}
			while(!states2.empty())
			{
				x = states2.front();
				states2.pop();
				states.push(x);
			}
		}
		cout<<steps<<endl;
	}
}
