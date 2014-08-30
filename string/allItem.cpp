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

void process(string str, int* cnt) {
	int i, n = str.length();
	loop(i, 256)
		cnt[i] = 0;
	loop(i, n)
		cnt[str.at(i)]++;
}

bool isEqual(int* cnt, int* cnt1) {
	int i;
	loop(i, 256)
		if(cnt[i] > cnt1[i])
			return false;
	return true;
}

void print(int* cnt) {
	int i;
	loop(i, 256) {
		if(cnt[i] != 0)
			cout<<(char) i <<" "<<cnt[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n, i, j;
	cin>>n;
	string lst[n];
	int cnt[n][256];
	loop(i, n) {
		cin>>lst[i];
		//cout<<lst[i]<<endl;
		process(lst[i], cnt[i]);
		//print(cnt[i]);
	}
	int newcnt[256];
	string str;
	cin>>str;
	process(str, newcnt);
	loop(i, n) {
		if(isEqual(newcnt, cnt[i]))
			cout<<lst[i]<<endl;
	}
	return 0;
}

