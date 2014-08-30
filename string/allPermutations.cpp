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

void print(string str, int j) {
	if(j == str.length()-1)
		cout<<str<<endl;
	else {
		int n = str.length(), i;
		string str1;
		char c;
		loopab(i, j, n) {
			str1 = str;
			c = str1.at(i);
			str1.at(i) = str1.at(j);
			str1.at(j) = c;
			print(str1, j+1);
		}
	}
}

int main()
{
	string str;
	cin>>str;
	print(str, 0);
	return 0;
}

