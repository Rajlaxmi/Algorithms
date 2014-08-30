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

bool cmp(pair<string,int> a, pair<string,int> b) {
	int cnt[255], cnt1[255];
	int i,j;
	loop()
}

int main()
{
	vector<pair<string,int> > vec;
	int n, i, j, x;
	cin>>n;
	vec.resize(n);
	loop(i, n) {
		cin>>x;
		vec[i] = make_pair(x, i);
	}
	sort(vec.begin(), vec.end(), cmp);
	return 0;
}
