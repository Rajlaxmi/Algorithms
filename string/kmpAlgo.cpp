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

int main()
{
	string text, pat;
	getline(cin, text);
	cin>>pat;
	int n = text.length(), m = pat.length(), i , j, len;
	int lps[m];
	lps[0] = 0;
	i = 1;
	len = 0;
	while(i < m) {
		if(pat.at(i) == pat.at(len)) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if(len == 0) {
				lps[i] = 0;
				i++;
			}
			else
				len = lps[len-1];
		}
	}
	
	j = 0;
	i = 0;
	while(i < n) {
		if(text.at(i) == pat.at(j)) {
			i++;
			j++;
			if(j == m) {
				cout<<"Found at "<<i-m<<endl;
				j = 0;
			}
		}
		else if(j > 0)
			j = lps[j-1];
		else
			i++;
	}
	return 0;
}

