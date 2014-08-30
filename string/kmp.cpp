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
using namespace std;

int main()
{
	string pat, text;
	getline(cin, text);
	cin>>pat;
	
	int m = pat.length(), len = 0;
	int lps[m];
	lps[0] = 0;
	int  i = 1;
	while(i < m) {
		if(pat.at(i) == pat.at(len)) {
			len++;
			lps[i] = len;
			i++;
		}
		else if(len != 0) {
			len = lps[len - 1];
		}
		else {
			lps[i] = 0;
			i++;
		}
	}
	
	int n = text.length(), j=0;
	for(i=0; i<n; i++) {
		if(text.at(i) == pat.at(j)) {
			if(j == m-1) {
				j = 0;
				cout<<"Matched at: "<<(i-m)+1<<endl;
			}
			else
				j++;
		}
		else {
			if(j > 0)
				j = lps[j-1];
		}
	}
	
	return 0;
}
