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
#define pii pair<int, int>
#define ll long long int
#define loop(i, n) for(i=0; i<n; i++)
#define loopab(i, a, b) for(i=a; i<b; i++)

using namespace std;
int main()
{
	string str;
	cin>>str;
	int n = str.length(), i, j;
	int cnt[256];
	loop(i, 256)
		cnt[i] = 0;
	char c;
	loop(i, n) {
		c = str.at(i);
		if(cnt[c] == 0)
			cnt[c] = 1;
		else if(cnt[c] == 1) {
			cnt[c] = 2;
			cout<<c<<" ";
		}
	}
	cout<<endl;
	return 0;
}

