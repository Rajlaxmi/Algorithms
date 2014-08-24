#include<iostream>
using namespace std;
int gp[102][102];
int cnt[102];

int computeChild(int i)
{
	if(cnt[i] != -1)
		return cnt[i];
	else
	{
		int j;
		
		for(j = 0; )
	}
}

int main()
{
	int n, m, i, j, x, y;
	cin>>n>>m;
	for(i = 0; i < m; i++)
		for(j = 0; j < m; j++)
			gp[i][j] = 0;
	for(i = 0; i < m; i++)
		cnt[i] = -1;
	for(i = 0; i < m; i++)
	{
		cin>>x>>y;
		gp[x][y] = 1;
	}
	
	computeChild(i);
	
	
	return 0;
}

//x - > y = 1
