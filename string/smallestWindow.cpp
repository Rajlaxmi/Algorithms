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

bool isEqual(int* cnt, int* cnt1) {
	int i;
	loop(i, 256) {
		if(cnt1[i] > cnt[i])
			return false;
	}
	return true;
}

int main()
{
	string str, str1;
	int cnt[256], cnt1[256], i, j;
	cin>>str>>str1;
	int n=str.length(), m = str1.length();
	loop(i, 256) {
		cnt[i] = 0;
		cnt1[i] = 0;
	}
	loop(i, m)
		cnt1[str1.at(i)]++;
	
	i = 0;
	j = 0;
	int l = INT_MAX; //
	cnt[str.at(0)]++;
	while(i < n && j < n) {
		while(j<n && !isEqual(cnt, cnt1)) {
			j++;
			if(j < n) {
				cnt[str.at(j)]++;
			}
		}
		if(isEqual(cnt, cnt1)) {
			cout<<i<<" "<<j<<" "<<str.substr(i, j-i+1)<<endl;
			l = min(l, j-i+1);
			cnt[str.at(i)]--;
			i++;
			if(i < n && i > j)
				cnt[str.at(i)]++;
			if(j < i)
				j++;
		}
	}
	if(l == INT_MAX)
		cout<<-1<<endl;
	else
		cout<<l<<endl;
	return 0;
}
