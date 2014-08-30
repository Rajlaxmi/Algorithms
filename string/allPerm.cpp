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

using namespace std;
int main()
{
	string str, pat;
	getline(cin, str);
	getline(cin, pat);
	
	int cnt[26], i, len[26];
	loop(i, 26)
		cnt[i] = 0;
	
	//count in pat
	int m = pat.length(), i, j;
	loop(i, m)
		cnt[pat.at(i)-97]++;
	
	//2
	loop(i, n-m) {
		loop(j, i, )
	}
	
	return 0;
}

