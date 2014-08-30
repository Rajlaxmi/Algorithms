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

bool find(string str, string str1) {
	int n=str.length(), m = str1.length(), i, j, len;
	int lps[m];
	lps[0] = 0;
	i = 1;
	len = 0;
	char c;
	while(i < m) {
		c = str1.at(i);
		if(c == str1.at(len)) {
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
	loop(i, n) {
		if(str.at(i) == str1.at(j)) {
			j++;
			if(j == m) {
				return true;
			}
		}
		else if(j > 0)
			j = lps[j-1];
	}
	return false;
}

int main()
{
	string str, str1;
	cin>>str>>str1;
	if(str1.length() != str.length())
		cout<<0<<endl;
	else
		cout<<find(str.append(str), str1)<<endl;
	return 0;
}

