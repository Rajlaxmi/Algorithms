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
#include <cstring>
#define pii pair<int, int>
#define ll long long int
#define loop(i, n) for(i=0; i<n; i++)
#define loopab(i, a, b) for(i=a; i<b; i++)
using namespace std;

int main()
{
	string str = "abbcc";
	string reg = "ab*cb*c";
	int n = str.length(), m = reg.length(), i, j, len;
	string regarr[n];
	i = 0, j = 0;
	while(i < n) {
		if(i+1 < n && (reg.at(i+1) == '*' || reg.at(i+1) == '?')) {
			regarr[j] = string(1, reg.at(i)).append(string(1, reg.at(i+1)));
			i++;
		}
		else
			regarr[j] = string(1, reg.at(i));
		j++;
		i++;
	}
	len = j;
	bool match[m][n];
	for(i=0; i<len; ) { //reg
		for(j=0; j<n; ) {
			if(regarr[i].length() == 1) {
				if(i > 0 && j > 0)
					match[i][j] = match[i-1][j-1] * (str[j] == regarr[i][0]);
				else if(i == 0 && j == 0)
					match[i][j] = (str[j] == regarr[i][0]);
				else
					match[i][j] = 0;
			}
			else if(regarr[i][1] == '*') {
				if(str[j] == regarr[i][0]) {
					if(i>0 && j>0)
						match[i][j] = (match[i-1][j-1] || match[i][j-1]) * (str[j] == regarr[i][0]);
					else if(j>0)
						match[i][j] = match[i][j-1] * (str[j] == regarr[i][0]);
					else
						match[i][j] = (str[j] == regarr[i][0]);
				}
				else
					match[i][j] = 0;
			}
			else if(regarr[i][1] == '?') {
			}
		}
	}
	
	return 0;
}

