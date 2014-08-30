#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#define pii pair<int, int>
#define ll long long int
#define loop(i, n) for(i=0; i<n; i++)
#define loopab(i, a, b) for(i=a; i<b; i++)
using namespace std;

int main()
{
	string str = "a1b2c3d";
	int cnt = 1, curr = 1, n = str.length(), nxt;
	char c;
	while(cnt < n) {
		nxt = getPos(curr);
		c = str.at(nxt);
		str.at(nxt) = 
	}
	return 0;
}

