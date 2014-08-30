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
	int cnt[256], i, j;
	cin>>str;
	int n = str.length();
	loop(i, 256)
		cnt[i] = 0;
	loop(i, n)
		cnt[str.at(i)]++;
	int mx = 0;
	char c;
	loop(i, 256) {
		if(cnt[i] > mx) {
			mx = cnt[i];
			c = (char) i;
		}
	}
	cout<<mx<<" "<<c<<endl;
	return 0;
}

