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

int hash(string str, int i, int j) {
	int h = 0, k;
	loopab(k, i, j+1)
		h = (h+str.at(k)) % 73;
	return h;
}

void verify(string str, string str1, int i, int m) {
	int j;
	loopab(j, i, m+i) {
		if(str.at(j) != str1.at(j-i))
			return;
	}
	cout<<"Found at "<<i<<endl;
}

int main()
{
	string str, str1;
	getline(cin, str);
	cin>>str1;
	int n = str.length(), m = str1.length(), i, j;
	int hm = hash(str1, 0, m-1);
	int hn = hash(str, 0, m-1);
	i = 0;
	while(i+m-1 < n) {
		if(hn == hm)
			verify(str, str1, i, m);
		
		hn = (hn - str.at(i)) % 73;
		i++;
		if(i+m-1 < n)
			hn = (hn + str.at(i+m-1)) % 73;
	}
	return 0;
}

