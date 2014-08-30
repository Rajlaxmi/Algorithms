#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstdio>
#include <cstdlib>
#define pii pair<int, int>
#define loop(i, n) for(i=0; i<n; i++)
#define loop(i, a, b) for(i=a; i<b; i++)
using namespace std;
#define MAX 100
string str[MAX];
bool mat[MAX][MAX];
	
int dfs(int n)
{
	
}

int main()
{
	int n, i;
	cin>>n;
	loop(i, n)
		cin>>str[i];
	loop(i, n) {
		loop(j, n) {
			if(str[i].at(str[i].length()-1) == str[j].at(0))
				mat[i][j] = true;
			else
				mat[i][j] = false;
		}
	}
	
	cout<<dfs(n)<<endl;
	return 0;
}
