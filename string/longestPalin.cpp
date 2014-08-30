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

string odd(string str, int mid) {
	int i = mid, n = str.length();
	for(i=mid-1; i>=0 && (mid + (mid - i)) < n; i--) {
		if(str.at(i) != str.at(mid + (mid - i)))
			break;
	}
	if(i == mid)
		return string(1, str.at(i));
	else
		return str.substr(i+1, 2*(mid-i) - 1);
}

string even(string str, int mid) {
	int i = mid, n = str.length(), j = mid+1;
	while(i >= 0 && j < n) {
		if(str.at(i) != str.at(j))
			break;
		else {
			i--;
			j++;
		}
	}
	
	if(i == mid)
		return string(1, str.at(i));
	else {
		//cout<<str.substr(i+1, j-i-1)<<endl;
		return str.substr(i+1, j-i-1);
	}
}

int main()
{
	string str, str1, str2, strmx;
	cin>>str;
	int n = str.length(), i, j, mx = 0;
	loop(i, n) {
		str1 = odd(str, i);
		str2 = even(str, i);
		if(str1.length() >= str2.length() && str1.length() > mx) {
			mx = str1.length();
			strmx = str1;
		}
		else if(str2.length() > str1.length() && str2.length() > mx) {
			mx = str2.length();
			strmx = str2;
		}
	}
	cout<<"Max length: "<<mx<<" String: "<<strmx<<endl;
	return 0;
}
