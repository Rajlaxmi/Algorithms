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

string revWord(string str, int i, int j) {
	char c;
	while(i < j) {
		c = str.at(i);
		str.at(i) = str.at(j);
		str.at(j) = c;
		i++;
		j--;
	}
	return str;
}

string reverse(string str) {
	string str1;
	int n = str.length(), i = n-1, j;
	for(i=n-1; i>=0; ) {
		while(i >= 0 && str.at(i) == ' ') {
			str1.append(string(1, str.at(i)));
			i--;
		}
		if(i >= 0) {
			j = i;
			while(j >= 0 && str.at(j) != ' ')
				j--;
			j++;
			str1.append(str.substr(j, i-j+1));
			i = j-1;
		}
	}
	return str1;
}
// abcd   cd , aed  
int main()
{
	string str, str1;
	getline(cin, str);
	str1=str;
	int i=0, j, n;
	n = str.length();
	while(i < n) {
		if(str.at(i) == ' ')
			i++;
		else {
			j = i;
			while(j < n && str.at(j) != ' ')
				j++;
			str = revWord(str, i, j-1);
			i = j;
			//cout<<str<<" "<<i<<" "<<n<<endl;
		}
	}
	cout<<"!"<<str1<<"!"<<endl;
	cout<<"!"<<reverse(str)<<"!"<<endl;
	return 0;
}

