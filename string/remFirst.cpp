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
	string str, str1, str2;
	cin>>str>>str1;
	int n = str.length(), m = str1.length(), i, j;
	//remove in str1
	bool cnt[256];
	loop(i, 256)
		cnt[i] = false;
	loop(i, n)
		cnt[str.at(i)] = true;
	char c;
	loop(i, m) {
		c = str1.at(i);
		if(cnt[c] == false)
			str2.append(string(1, c));
	}
	cout<<str2<<endl;
	return 0;
}

