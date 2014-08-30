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
#include <cmath>
#define pii pair<int, int>
#define ll long long int
#define loop(i, n) for(i=0; i<n; i++)
#define loopab(i, a, b) for(i=a; i<b; i++)
int matrix[26][26];
int vertex[26];

void addEdge(string str, string str1) {
	for(int i=0; i<min(str.length(), str1.length()) ; i++)
	{
		if(!(str.at(i) == str1.at(i)))
			add();
	}
}

using namespace std;
int main()
{
	int n,i;
	cin>>n;
	string str[n];
	loop(i, n)
		cin>>str[i];
	loop(i, n-1)
		addEdge(str[i], str[i+1]);
	topSort();
	return 0;
}
