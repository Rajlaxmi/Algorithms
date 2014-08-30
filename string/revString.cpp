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

string reverse(string str) {
	if(str.length() == 1)
		return str;
	else {
		int n = str.length();
		str = string(1, str.at(n-1)).append(reverse(str.substr(0, n-1)));
		return str;
	}
}

int main()
{
	string str;
	cin>>str;
	cout<<reverse(str)<<endl;
	return 0;
}

