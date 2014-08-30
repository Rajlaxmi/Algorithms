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
#define pii pair<int, int>
#define ll long long int
#define loop(i, n) for(i=0; i<n; i++)
#define loopab(i, a, b) for(i=a; i<b; i++)
using namespace std;

int main()
{
	string str;
	cin>>str;
	int cnt[256], i, j, n=str.length();
	loop(i, 256)
		cnt[i] = 0;
	i = 0;
	j = 0;
	mx = 0;
	while(i<n && j<n) {
		if(valid(cnt)) {
			mx = max(mx, j-i+1);
		}
		
		i++;
	}
	return 0;
}

