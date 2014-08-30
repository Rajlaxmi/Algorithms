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
	string str, str1;
	char c;
	cin>>str;
	int n = str.length(), i, j;
	bool cnt[256];
	loop(i, 256)
		cnt[i] = false;
	loop(i, n) {
		c = str.at(i);
		if(cnt[c] == false) {
			cnt[c] = true;
			str1.append(string(1, c));
		}
	}
	cout<<str<<" "<<str1<<endl;
	return 0;
}
