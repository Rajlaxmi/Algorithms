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
#include <sstream>
#define pii pair<int, int>
#define ll long long int
#define loop(i, n) for(i=0; i<n; i++)
#define loopab(i, a, b) for(i=a; i<b; i++)
using namespace std;

string toString(int num) {
	stringstream ss;
	ss << num;
	return ss.str();
}

string add(string str1, char c, int cnt) {
	str1.append(string(1, c));
	str1.append(toString(cnt));
	return str1;
}

int main()
{
	string str, str1;
	cin>>str;
	int i = 0, cnt=0, n = str.length(), j;
	char c;
	while(i < n) {
		cnt = 0;
		c = str.at(i);
		j = i;
		while(j < n && str.at(j) == c)
			j++;
		str1 = add(str1, c, j-i);
		i = j;
	}
	cout<<str1<<endl;
	return 0;
}

